// ============================================================================
// File: rex_fde_shard_4.cpp
// Target 109 / 169: librex.so (690,264 bytes)
// EN: Clean-room C++17 AArch64 Function Shard 4/5 covering [960..1279]
//     (PC range 0x030264 .. 0x03f5f0).
// VI: Phân mảnh hàm AArch64 C++17 4/5 bao phủ [960..1279]
//     (Dải địa chỉ PC 0x030264 .. 0x03f5f0).
// ============================================================================
#include "rex_date_format.h"

namespace bytedance {
namespace rex {

// Func #0960 | PC: 0x030264..0x0302a4 (64 B) | Symbol: sub_030264
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xb8]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xb8]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_030264(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9405FF3ULL) << 32) | 0x97FF4623ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x030264ULL;
}

// Func #0961 | PC: 0x0302a0..0x0302e0 (64 B) | Symbol: sub_0302a0
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_0302a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FF4648ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0302A0ULL;
}

// Func #0962 | PC: 0x0302a4..0x0320a4 (7680 B) | Symbol: rex_locale_init_ctor_23
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0302a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0302A4ULL;
}

// Func #0963 | PC: 0x0302c0..0x030300 (64 B) | Symbol: sub_0302c0
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc80; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc80; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_0302c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD13203FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0302C0ULL;
}

// Func #0964 | PC: 0x0302c4..0x030304 (64 B) | Symbol: sub_0302c4
// EN: AArch64 prologue [sub sp, sp, #0xc80; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc80; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_0302c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD13203FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0302C4ULL;
}

// Func #0965 | PC: 0x0302ec..0x03032c (64 B) | Symbol: sub_0302ec
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x32358; movi v1.2d, #0000000000000000; adrp x15, #0x9b000] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x32358; movi v1.2d, #0000000000000000; adrp x15, #0x9b000]
uint64_t fde_sub_0302ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34010340ULL) << 32) | 0x97FF4645ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0302ECULL;
}

// Func #0966 | PC: 0x030848..0x030888 (64 B) | Symbol: sub_030848
// EN: AArch64 prologue [bl #0x1ba0; adrp x10, #0x97000; ldr q1, [x10, #0xc60]; adrp x13, #0x9c000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x10, #0x97000; ldr q1, [x10, #0xc60]; adrp x13, #0x9c000]
uint64_t fde_sub_030848(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF000032AULL) << 32) | 0x97FF44D6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x030848ULL;
}

// Func #0967 | PC: 0x030ce4..0x030d24 (64 B) | Symbol: sub_030ce4
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x97000; add x9, x9, #0xea8; ldur q0, [x9, #0xb]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x97000; add x9, x9, #0xea8; ldur q0, [x9, #0xb]]
uint64_t fde_sub_030ce4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000329ULL) << 32) | 0x97FF43AFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x030CE4ULL;
}

// Func #0968 | PC: 0x030da8..0x030de8 (64 B) | Symbol: sub_030da8
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xc0]; adrp x15, #0x9a000; add x15, x15, #0x424] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xc0]; adrp x15, #0x9a000; add x15, x15, #0x424]
uint64_t fde_sub_030da8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC033E0ULL) << 32) | 0x97FF437EULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x030DA8ULL;
}

// Func #0969 | PC: 0x031208..0x031248 (64 B) | Symbol: sub_031208
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcb0]; ldr x9, [sp, #0xe0]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcb0]; ldr x9, [sp, #0xe0]]
uint64_t fde_sub_031208(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000328ULL) << 32) | 0x97FF4266ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031208ULL;
}

// Func #0970 | PC: 0x031374..0x0313b4 (64 B) | Symbol: sub_031374
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_031374(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x94015D03ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031374ULL;
}

// Func #0971 | PC: 0x031384..0x0313c4 (64 B) | Symbol: sub_031384
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_031384(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x94015CFFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031384ULL;
}

// Func #0972 | PC: 0x031394..0x0313d4 (64 B) | Symbol: sub_031394
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_031394(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x94015CFBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031394ULL;
}

// Func #0973 | PC: 0x0313a4..0x0313e4 (64 B) | Symbol: sub_0313a4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0313a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x94015CF7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0313A4ULL;
}

// Func #0974 | PC: 0x0313b4..0x0313f4 (64 B) | Symbol: sub_0313b4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0xa0]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0xa0]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0313b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94053E1ULL) << 32) | 0x94015CF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0313B4ULL;
}

// Func #0975 | PC: 0x0313c4..0x031404 (64 B) | Symbol: sub_0313c4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0313c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x94015CEFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0313C4ULL;
}

// Func #0976 | PC: 0x0313d4..0x031414 (64 B) | Symbol: sub_0313d4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0313d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x94015CEBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0313D4ULL;
}

// Func #0977 | PC: 0x0313e4..0x031424 (64 B) | Symbol: sub_0313e4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0313e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x94015CE7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0313E4ULL;
}

// Func #0978 | PC: 0x0313f4..0x031434 (64 B) | Symbol: sub_0313f4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0313f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x94015CE3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0313F4ULL;
}

// Func #0979 | PC: 0x031404..0x031444 (64 B) | Symbol: sub_031404
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_031404(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x94015CDFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031404ULL;
}

// Func #0980 | PC: 0x031414..0x031454 (64 B) | Symbol: sub_031414
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_031414(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x94015CDBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031414ULL;
}

// Func #0981 | PC: 0x031424..0x031464 (64 B) | Symbol: sub_031424
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_031424(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x94015CD7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031424ULL;
}

// Func #0982 | PC: 0x031434..0x031474 (64 B) | Symbol: sub_031434
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_031434(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x94015CD3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031434ULL;
}

// Func #0983 | PC: 0x031444..0x031484 (64 B) | Symbol: sub_031444
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_031444(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x94015CCFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031444ULL;
}

// Func #0984 | PC: 0x031454..0x031494 (64 B) | Symbol: sub_031454
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_031454(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x94015CCBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031454ULL;
}

// Func #0985 | PC: 0x031464..0x0314a4 (64 B) | Symbol: sub_031464
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x27; mov x2, x27] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x27; mov x2, x27]
uint64_t fde_sub_031464(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94015CC7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031464ULL;
}

// Func #0986 | PC: 0x031474..0x0314b4 (64 B) | Symbol: sub_031474
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_031474(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x94015CC3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031474ULL;
}

// Func #0987 | PC: 0x031484..0x0314c4 (64 B) | Symbol: sub_031484
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26]
uint64_t fde_sub_031484(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94015CBFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031484ULL;
}

// Func #0988 | PC: 0x031494..0x0314d4 (64 B) | Symbol: sub_031494
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23]
uint64_t fde_sub_031494(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94015CBBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031494ULL;
}

// Func #0989 | PC: 0x0314a4..0x0314e4 (64 B) | Symbol: sub_0314a4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0314a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x94015CB7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0314A4ULL;
}

// Func #0990 | PC: 0x0314b4..0x0314f4 (64 B) | Symbol: sub_0314b4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0xe0]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0xe0]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0314b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94073E1ULL) << 32) | 0x94015CB3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0314B4ULL;
}

// Func #0991 | PC: 0x0314c4..0x031504 (64 B) | Symbol: sub_0314c4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0314c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x94015CAFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0314C4ULL;
}

// Func #0992 | PC: 0x0314d4..0x031514 (64 B) | Symbol: sub_0314d4
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x21; mov x2, x21] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x21; mov x2, x21]
uint64_t fde_sub_0314d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94015CABULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0314D4ULL;
}

// Func #0993 | PC: 0x0314e4..0x031524 (64 B) | Symbol: sub_0314e4
// EN: AArch64 prologue [bl #0x88780; movi v1.2d, #0000000000000000; add x9, sp, #0x8f9; add x8, x24, #0x478] | VI: Khởi đầu hàm AArch64 [bl #0x88780; movi v1.2d, #0000000000000000; add x9, sp, #0x8f9; add x8, x24, #0x478]
uint64_t fde_sub_0314e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6F00E401ULL) << 32) | 0x94015CA7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0314E4ULL;
}

// Func #0994 | PC: 0x0319c8..0x031a08 (64 B) | Symbol: sub_0319c8
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc50]; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc50]; adrp x8, #0x9c000]
uint64_t fde_sub_0319c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000328ULL) << 32) | 0x97FF4076ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0319C8ULL;
}

// Func #0995 | PC: 0x031a34..0x031a74 (64 B) | Symbol: sub_031a34
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [sp, #0x10c0]; strb wzr, [x0, #0x1c]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [sp, #0x10c0]; strb wzr, [x0, #0x1c]]
uint64_t fde_sub_031a34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03BE0ULL) << 32) | 0x97FF405BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031A34ULL;
}

// Func #0996 | PC: 0x031a68..0x031aa8 (64 B) | Symbol: sub_031a68
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc70]; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc70]; adrp x8, #0x9c000]
uint64_t fde_sub_031a68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000328ULL) << 32) | 0x97FF404EULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031A68ULL;
}

// Func #0997 | PC: 0x031ac8..0x031b08 (64 B) | Symbol: sub_031ac8
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [sp, #0x1180]; strb wzr, [x0, #0x19]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [sp, #0x1180]; strb wzr, [x0, #0x19]]
uint64_t fde_sub_031ac8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03BE0ULL) << 32) | 0x97FF4036ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031AC8ULL;
}

// Func #0998 | PC: 0x031afc..0x031b3c (64 B) | Symbol: sub_031afc
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q1, [x8, #0xd10]; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q1, [x8, #0xd10]; adrp x8, #0x9c000]
uint64_t fde_sub_031afc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000328ULL) << 32) | 0x97FF4029ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031AFCULL;
}

// Func #0999 | PC: 0x031b60..0x031ba0 (64 B) | Symbol: sub_031b60
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x80]; str x0, [sp, #0x1240]; strh w23, [x0, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x80]; str x0, [sp, #0x1240]; strh w23, [x0, #0x20]]
uint64_t fde_sub_031b60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC023E0ULL) << 32) | 0x97FF4010ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031B60ULL;
}

// Func #1000 | PC: 0x031b98..0x031bd8 (64 B) | Symbol: sub_031b98
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xe0]; adrp x8, #0x9c000; add x8, x8, #0x297] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xe0]; adrp x8, #0x9c000; add x8, x8, #0x297]
uint64_t fde_sub_031b98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03BE0ULL) << 32) | 0x97FF4002ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031B98ULL;
}

// Func #1001 | PC: 0x031be8..0x031c28 (64 B) | Symbol: sub_031be8
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [sp, #0x1300]; strb wzr, [x0, #0x19]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [sp, #0x1300]; strb wzr, [x0, #0x19]]
uint64_t fde_sub_031be8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03BE0ULL) << 32) | 0x97FF3FEEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031BE8ULL;
}

// Func #1002 | PC: 0x031c1c..0x031c5c (64 B) | Symbol: sub_031c1c
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xe0]; adrp x8, #0x9c000; add x8, x8, #0x2b1] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xe0]; adrp x8, #0x9c000; add x8, x8, #0x2b1]
uint64_t fde_sub_031c1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03BE0ULL) << 32) | 0x97FF3FE1ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031C1CULL;
}

// Func #1003 | PC: 0x031c6c..0x031cac (64 B) | Symbol: sub_031c6c
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [sp, #0x13c0]; strb wzr, [x0, #0x19]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [sp, #0x13c0]; strb wzr, [x0, #0x19]]
uint64_t fde_sub_031c6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03BE0ULL) << 32) | 0x97FF3FCDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031C6CULL;
}

// Func #1004 | PC: 0x031ca0..0x031ce0 (64 B) | Symbol: sub_031ca0
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xe0]; adrp x8, #0x9c000; add x8, x8, #0x2cb] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xe0]; adrp x8, #0x9c000; add x8, x8, #0x2cb]
uint64_t fde_sub_031ca0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03BE0ULL) << 32) | 0x97FF3FC0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031CA0ULL;
}

// Func #1005 | PC: 0x031cf0..0x031d30 (64 B) | Symbol: sub_031cf0
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [sp, #0x1480]; strb wzr, [x0, #0x19]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [sp, #0x1480]; strb wzr, [x0, #0x19]]
uint64_t fde_sub_031cf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03BE0ULL) << 32) | 0x97FF3FACULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031CF0ULL;
}

// Func #1006 | PC: 0x031d24..0x031d64 (64 B) | Symbol: sub_031d24
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xe0]; adrp x8, #0x9c000; add x8, x8, #0x2e5] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xe0]; adrp x8, #0x9c000; add x8, x8, #0x2e5]
uint64_t fde_sub_031d24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03BE0ULL) << 32) | 0x97FF3F9FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031D24ULL;
}

// Func #1007 | PC: 0x031d74..0x031db4 (64 B) | Symbol: sub_031d74
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [sp, #0x1540]; strb wzr, [x0, #0x19]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [sp, #0x1540]; strb wzr, [x0, #0x19]]
uint64_t fde_sub_031d74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03BE0ULL) << 32) | 0x97FF3F8BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031D74ULL;
}

// Func #1008 | PC: 0x031dac..0x031dec (64 B) | Symbol: sub_031dac
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xe0]; adrp x8, #0x9c000; add x8, x8, #0x2ff] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xe0]; adrp x8, #0x9c000; add x8, x8, #0x2ff]
uint64_t fde_sub_031dac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03BE0ULL) << 32) | 0x97FF3F7DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031DACULL;
}

// Func #1009 | PC: 0x031dfc..0x031e3c (64 B) | Symbol: sub_031dfc
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [x26, #0xb0]; adrp x9, #0x9c000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xe0]; str x0, [x26, #0xb0]; adrp x9, #0x9c000]
uint64_t fde_sub_031dfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03BE0ULL) << 32) | 0x97FF3F69ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031DFCULL;
}

// Func #1010 | PC: 0x031ea0..0x031ee0 (64 B) | Symbol: sub_031ea0
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcf0]; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcf0]; adrp x8, #0x9c000]
uint64_t fde_sub_031ea0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000328ULL) << 32) | 0x97FF3F40ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031EA0ULL;
}

// Func #1011 | PC: 0x031ef8..0x031f38 (64 B) | Symbol: sub_031ef8
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x90]; str x0, [x26, #0x230]; adrp x9, #0x9c000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x90]; str x0, [x26, #0x230]; adrp x9, #0x9c000]
uint64_t fde_sub_031ef8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC027E0ULL) << 32) | 0x97FF3F2AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031EF8ULL;
}

// Func #1012 | PC: 0x0322f4..0x032334 (64 B) | Symbol: sub_0322f4
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x578; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x578; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_0322f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9115E3E0ULL) << 32) | 0x94015C00ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0322F4ULL;
}

// Func #1013 | PC: 0x0322fc..0x03233c (64 B) | Symbol: sub_0322fc
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x32310; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x32310; subs x19, x19, #0x30]
uint64_t fde_sub_0322fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x9401545CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0322FCULL;
}

// Func #1014 | PC: 0x03232c..0x03236c (64 B) | Symbol: sub_03232c
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x32308; add x8, x28, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x32308; add x8, x28, x19]
uint64_t fde_sub_03232c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FF3DE9ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03232CULL;
}

// Func #1015 | PC: 0x032340..0x032380 (64 B) | Symbol: sub_032340
// EN: AArch64 prologue [bl #0x1ad0; b #0x32308; adrp x0, #0xce000; add x0, x0, #0x870] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x32308; adrp x0, #0xce000; add x0, x0, #0x870]
uint64_t fde_sub_032340(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FF3DE4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x032340ULL;
}

// Func #1016 | PC: 0x032350..0x032390 (64 B) | Symbol: sub_032350
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xd8]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xd8]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_032350(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9406FF3ULL) << 32) | 0x97FF3DE8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x032350ULL;
}

// Func #1017 | PC: 0x03238c..0x0323cc (64 B) | Symbol: sub_03238c
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_03238c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FF3E0DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03238CULL;
}

// Func #1018 | PC: 0x032390..0x034190 (7680 B) | Symbol: rex_locale_init_ctor_24
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_032390(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x032390ULL;
}

// Func #1019 | PC: 0x0323ac..0x0323ec (64 B) | Symbol: sub_0323ac
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc30; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc30; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_0323ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD130C3FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0323ACULL;
}

// Func #1020 | PC: 0x0323b0..0x0323f0 (64 B) | Symbol: sub_0323b0
// EN: AArch64 prologue [sub sp, sp, #0xc30; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc30; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_0323b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD130C3FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0323B0ULL;
}

// Func #1021 | PC: 0x0323d8..0x032418 (64 B) | Symbol: sub_0323d8
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x3451c; movi v1.2d, #0000000000000000; adrp x15, #0x9c000] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x3451c; movi v1.2d, #0000000000000000; adrp x15, #0x9c000]
uint64_t fde_sub_0323d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34010A00ULL) << 32) | 0x97FF3E0AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0323D8ULL;
}

// Func #1022 | PC: 0x032c60..0x032ca0 (64 B) | Symbol: sub_032c60
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9c000; add x9, x9, #0x46e; ldur q0, [x9, #0xc]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9c000; add x9, x9, #0x46e; ldur q0, [x9, #0xc]]
uint64_t fde_sub_032c60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000349ULL) << 32) | 0x97FF3BD0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x032C60ULL;
}

// Func #1023 | PC: 0x032d1c..0x032d5c (64 B) | Symbol: sub_032d1c
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xc70]; adrp x16, #0x9a000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xc70]; adrp x16, #0x9a000]
uint64_t fde_sub_032d1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000329ULL) << 32) | 0x97FF3BA1ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x032D1CULL;
}

// Func #1024 | PC: 0x033178..0x0331b8 (64 B) | Symbol: sub_033178
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcb0]; ldr x9, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcb0]; ldr x9, [sp, #0x30]]
uint64_t fde_sub_033178(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000328ULL) << 32) | 0x97FF3A8AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033178ULL;
}

// Func #1025 | PC: 0x0332e0..0x033320 (64 B) | Symbol: sub_0332e0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0332e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x94015528ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0332E0ULL;
}

// Func #1026 | PC: 0x0332f0..0x033330 (64 B) | Symbol: sub_0332f0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0332f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x94015524ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0332F0ULL;
}

// Func #1027 | PC: 0x033300..0x033340 (64 B) | Symbol: sub_033300
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_033300(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x94015520ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033300ULL;
}

// Func #1028 | PC: 0x033310..0x033350 (64 B) | Symbol: sub_033310
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_033310(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94047E1ULL) << 32) | 0x9401551CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033310ULL;
}

// Func #1029 | PC: 0x033320..0x033360 (64 B) | Symbol: sub_033320
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_033320(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x94015518ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033320ULL;
}

// Func #1030 | PC: 0x033330..0x033370 (64 B) | Symbol: sub_033330
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_033330(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x94015514ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033330ULL;
}

// Func #1031 | PC: 0x033340..0x033380 (64 B) | Symbol: sub_033340
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_033340(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x94015510ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033340ULL;
}

// Func #1032 | PC: 0x033350..0x033390 (64 B) | Symbol: sub_033350
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_033350(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x9401550CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033350ULL;
}

// Func #1033 | PC: 0x033360..0x0333a0 (64 B) | Symbol: sub_033360
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_033360(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x94015508ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033360ULL;
}

// Func #1034 | PC: 0x033370..0x0333b0 (64 B) | Symbol: sub_033370
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_033370(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x94015504ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033370ULL;
}

// Func #1035 | PC: 0x033380..0x0333c0 (64 B) | Symbol: sub_033380
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_033380(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x94015500ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033380ULL;
}

// Func #1036 | PC: 0x033390..0x0333d0 (64 B) | Symbol: sub_033390
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_033390(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x940154FCULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033390ULL;
}

// Func #1037 | PC: 0x0333a0..0x0333e0 (64 B) | Symbol: sub_0333a0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0333a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x940154F8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0333A0ULL;
}

// Func #1038 | PC: 0x0333b0..0x0333f0 (64 B) | Symbol: sub_0333b0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0333b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x940154F4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0333B0ULL;
}

// Func #1039 | PC: 0x0333c0..0x033400 (64 B) | Symbol: sub_0333c0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0333c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x940154F0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0333C0ULL;
}

// Func #1040 | PC: 0x0333d0..0x033410 (64 B) | Symbol: sub_0333d0
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x25; mov x2, x25] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x25; mov x2, x25]
uint64_t fde_sub_0333d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x940154ECULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0333D0ULL;
}

// Func #1041 | PC: 0x0333e0..0x033420 (64 B) | Symbol: sub_0333e0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0333e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x940154E8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0333E0ULL;
}

// Func #1042 | PC: 0x0333f0..0x033430 (64 B) | Symbol: sub_0333f0
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26]
uint64_t fde_sub_0333f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x940154E4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0333F0ULL;
}

// Func #1043 | PC: 0x033400..0x033440 (64 B) | Symbol: sub_033400
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x28; mov x2, x28] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x28; mov x2, x28]
uint64_t fde_sub_033400(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x940154E0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033400ULL;
}

// Func #1044 | PC: 0x033410..0x033450 (64 B) | Symbol: sub_033410
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_033410(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x940154DCULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033410ULL;
}

// Func #1045 | PC: 0x033420..0x033460 (64 B) | Symbol: sub_033420
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_033420(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x940154D8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033420ULL;
}

// Func #1046 | PC: 0x033430..0x033470 (64 B) | Symbol: sub_033430
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_033430(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94003E1ULL) << 32) | 0x940154D4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033430ULL;
}

// Func #1047 | PC: 0x033440..0x033480 (64 B) | Symbol: sub_033440
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x21; mov x2, x21] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x21; mov x2, x21]
uint64_t fde_sub_033440(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x940154D0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033440ULL;
}

// Func #1048 | PC: 0x033454..0x033494 (64 B) | Symbol: sub_033454
// EN: AArch64 prologue [bl #0x88780; mov w10, #0x756a; add x8, x27, #0x508; add x9, x27, #0x4f9] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov w10, #0x756a; add x8, x27, #0x508; add x9, x27, #0x4f9]
uint64_t fde_sub_033454(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x528EAD4AULL) << 32) | 0x940154CBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033454ULL;
}

// Func #1049 | PC: 0x0344b8..0x0344f8 (64 B) | Symbol: sub_0344b8
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x528; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x528; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_0344b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9114A3E0ULL) << 32) | 0x9401538FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0344B8ULL;
}

// Func #1050 | PC: 0x0344c0..0x034500 (64 B) | Symbol: sub_0344c0
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x344d4; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x344d4; subs x19, x19, #0x30]
uint64_t fde_sub_0344c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x94014BEBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0344C0ULL;
}

// Func #1051 | PC: 0x0344f0..0x034530 (64 B) | Symbol: sub_0344f0
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x344cc; add x8, x21, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x344cc; add x8, x21, x19]
uint64_t fde_sub_0344f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FF3578ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0344F0ULL;
}

// Func #1052 | PC: 0x034504..0x034544 (64 B) | Symbol: sub_034504
// EN: AArch64 prologue [bl #0x1ad0; b #0x344cc; adrp x0, #0xcf000; add x0, x0, #0xf70] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x344cc; adrp x0, #0xcf000; add x0, x0, #0xf70]
uint64_t fde_sub_034504(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FF3573ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x034504ULL;
}

// Func #1053 | PC: 0x034514..0x034554 (64 B) | Symbol: sub_034514
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xa0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xa0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_034514(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94053F3ULL) << 32) | 0x97FF3577ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x034514ULL;
}

// Func #1054 | PC: 0x034550..0x034590 (64 B) | Symbol: sub_034550
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_034550(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FF359CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x034550ULL;
}

// Func #1055 | PC: 0x034554..0x036354 (7680 B) | Symbol: rex_locale_init_ctor_25
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_034554(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x034554ULL;
}

// Func #1056 | PC: 0x034570..0x0345b0 (64 B) | Symbol: sub_034570
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc70; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc70; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_034570(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD131C3FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x034570ULL;
}

// Func #1057 | PC: 0x034574..0x0345b4 (64 B) | Symbol: sub_034574
// EN: AArch64 prologue [sub sp, sp, #0xc70; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc70; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_034574(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD131C3FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x034574ULL;
}

// Func #1058 | PC: 0x03459c..0x0345dc (64 B) | Symbol: sub_03459c
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x363a8; mov x17, #0x6566; movk x17, #0x7262, lsl #16] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x363a8; mov x17, #0x6566; movk x17, #0x7262, lsl #16]
uint64_t fde_sub_03459c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3400F040ULL) << 32) | 0x97FF3599ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03459CULL;
}

// Func #1059 | PC: 0x034e40..0x034e80 (64 B) | Symbol: sub_034e40
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9c000; add x9, x9, #0x705; ldur q0, [x9, #0xb]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9c000; add x9, x9, #0x705; ldur q0, [x9, #0xb]]
uint64_t fde_sub_034e40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000349ULL) << 32) | 0x97FF3358ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x034E40ULL;
}

// Func #1060 | PC: 0x034f00..0x034f40 (64 B) | Symbol: sub_034f00
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xc60]; adrp x16, #0x9c000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xc60]; adrp x16, #0x9c000]
uint64_t fde_sub_034f00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000309ULL) << 32) | 0x97FF3328ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x034F00ULL;
}

// Func #1061 | PC: 0x0354b0..0x0354f0 (64 B) | Symbol: sub_0354b0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0354b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x94014CB4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0354B0ULL;
}

// Func #1062 | PC: 0x0354c0..0x035500 (64 B) | Symbol: sub_0354c0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0354c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x94014CB0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0354C0ULL;
}

// Func #1063 | PC: 0x0354d0..0x035510 (64 B) | Symbol: sub_0354d0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0354d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94047E1ULL) << 32) | 0x94014CACULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0354D0ULL;
}

// Func #1064 | PC: 0x0354e0..0x035520 (64 B) | Symbol: sub_0354e0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0354e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x94014CA8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0354E0ULL;
}

// Func #1065 | PC: 0x0354f0..0x035530 (64 B) | Symbol: sub_0354f0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0xa0]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0xa0]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0354f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94053E1ULL) << 32) | 0x94014CA4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0354F0ULL;
}

// Func #1066 | PC: 0x035500..0x035540 (64 B) | Symbol: sub_035500
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_035500(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x94014CA0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x035500ULL;
}

// Func #1067 | PC: 0x035510..0x035550 (64 B) | Symbol: sub_035510
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_035510(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x94014C9CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x035510ULL;
}

// Func #1068 | PC: 0x035520..0x035560 (64 B) | Symbol: sub_035520
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_035520(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x94014C98ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x035520ULL;
}

// Func #1069 | PC: 0x035530..0x035570 (64 B) | Symbol: sub_035530
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_035530(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x94014C94ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x035530ULL;
}

// Func #1070 | PC: 0x035540..0x035580 (64 B) | Symbol: sub_035540
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_035540(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x94014C90ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x035540ULL;
}

// Func #1071 | PC: 0x035550..0x035590 (64 B) | Symbol: sub_035550
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_035550(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x94014C8CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x035550ULL;
}

// Func #1072 | PC: 0x035560..0x0355a0 (64 B) | Symbol: sub_035560
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_035560(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x94014C88ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x035560ULL;
}

// Func #1073 | PC: 0x035570..0x0355b0 (64 B) | Symbol: sub_035570
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_035570(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x94014C84ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x035570ULL;
}

// Func #1074 | PC: 0x035580..0x0355c0 (64 B) | Symbol: sub_035580
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_035580(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x94014C80ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x035580ULL;
}

// Func #1075 | PC: 0x035590..0x0355d0 (64 B) | Symbol: sub_035590
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_035590(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x94014C7CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x035590ULL;
}

// Func #1076 | PC: 0x0355a0..0x0355e0 (64 B) | Symbol: sub_0355a0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0355a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x94014C78ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0355A0ULL;
}

// Func #1077 | PC: 0x0355b0..0x0355f0 (64 B) | Symbol: sub_0355b0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0355b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x94014C74ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0355B0ULL;
}

// Func #1078 | PC: 0x0355c0..0x035600 (64 B) | Symbol: sub_0355c0
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26]
uint64_t fde_sub_0355c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94014C70ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0355C0ULL;
}

// Func #1079 | PC: 0x0355d0..0x035610 (64 B) | Symbol: sub_0355d0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0355d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x94014C6CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0355D0ULL;
}

// Func #1080 | PC: 0x0355e0..0x035620 (64 B) | Symbol: sub_0355e0
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x21; mov x2, x21] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x21; mov x2, x21]
uint64_t fde_sub_0355e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94014C68ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0355E0ULL;
}

// Func #1081 | PC: 0x0355f0..0x035630 (64 B) | Symbol: sub_0355f0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0355f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x94014C64ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0355F0ULL;
}

// Func #1082 | PC: 0x035600..0x035640 (64 B) | Symbol: sub_035600
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x20; mov x2, x20] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x20; mov x2, x20]
uint64_t fde_sub_035600(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94014C60ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x035600ULL;
}

// Func #1083 | PC: 0x035610..0x035650 (64 B) | Symbol: sub_035610
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x27; mov x2, x27] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x27; mov x2, x27]
uint64_t fde_sub_035610(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94014C5CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x035610ULL;
}

// Func #1084 | PC: 0x035620..0x035660 (64 B) | Symbol: sub_035620
// EN: AArch64 prologue [bl #0x88780; add x14, sp, #0x568; add x8, x14, #0x508; mov w10, #0x6554] | VI: Khởi đầu hàm AArch64 [bl #0x88780; add x14, sp, #0x568; add x8, x14, #0x508; mov w10, #0x6554]
uint64_t fde_sub_035620(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9115A3EEULL) << 32) | 0x94014C58ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x035620ULL;
}

// Func #1085 | PC: 0x035d34..0x035d74 (64 B) | Symbol: sub_035d34
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc70]; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc70]; adrp x8, #0x9c000]
uint64_t fde_sub_035d34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000308ULL) << 32) | 0x97FF2F9BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x035D34ULL;
}

// Func #1086 | PC: 0x035d88..0x035dc8 (64 B) | Symbol: sub_035d88
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9c000; add x9, x9, #0x84d; ldr q0, [x9]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9c000; add x9, x9, #0x84d; ldr q0, [x9]]
uint64_t fde_sub_035d88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000329ULL) << 32) | 0x97FF2F86ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x035D88ULL;
}

// Func #1087 | PC: 0x036344..0x036384 (64 B) | Symbol: sub_036344
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x568; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x568; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_036344(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9115A3E0ULL) << 32) | 0x94014BECULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x036344ULL;
}

// Func #1088 | PC: 0x03634c..0x03638c (64 B) | Symbol: sub_03634c
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x36360; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x36360; subs x19, x19, #0x30]
uint64_t fde_sub_03634c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x94014448ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03634CULL;
}

// Func #1089 | PC: 0x03637c..0x0363bc (64 B) | Symbol: sub_03637c
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x36358; add x8, x25, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x36358; add x8, x25, x19]
uint64_t fde_sub_03637c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FF2DD5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03637CULL;
}

// Func #1090 | PC: 0x036390..0x0363d0 (64 B) | Symbol: sub_036390
// EN: AArch64 prologue [bl #0x1ad0; b #0x36358; adrp x0, #0xd1000; add x0, x0, #0x670] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x36358; adrp x0, #0xd1000; add x0, x0, #0x670]
uint64_t fde_sub_036390(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FF2DD0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x036390ULL;
}

// Func #1091 | PC: 0x0363a0..0x0363e0 (64 B) | Symbol: sub_0363a0
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xe0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xe0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_0363a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94073F3ULL) << 32) | 0x97FF2DD4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0363A0ULL;
}

// Func #1092 | PC: 0x0363dc..0x03641c (64 B) | Symbol: sub_0363dc
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_0363dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FF2DF9ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0363DCULL;
}

// Func #1093 | PC: 0x0363e0..0x0381e0 (7680 B) | Symbol: rex_locale_init_ctor_26
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0363e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0363E0ULL;
}

// Func #1094 | PC: 0x0363fc..0x03643c (64 B) | Symbol: sub_0363fc
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_0363fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD13103FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0363FCULL;
}

// Func #1095 | PC: 0x036400..0x036440 (64 B) | Symbol: sub_036400
// EN: AArch64 prologue [sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_036400(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD13103FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x036400ULL;
}

// Func #1096 | PC: 0x036428..0x036468 (64 B) | Symbol: sub_036428
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x38004; mov x14, #0x6546; movi v1.2d, #0000000000000000] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x38004; mov x14, #0x6546; movi v1.2d, #0000000000000000]
uint64_t fde_sub_036428(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3400DEC0ULL) << 32) | 0x97FF2DF6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x036428ULL;
}

// Func #1097 | PC: 0x036ca0..0x036ce0 (64 B) | Symbol: sub_036ca0
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9c000; add x9, x9, #0x918; ldur q0, [x9, #0xa]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9c000; add x9, x9, #0x918; ldur q0, [x9, #0xa]]
uint64_t fde_sub_036ca0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000329ULL) << 32) | 0x97FF2BC0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x036CA0ULL;
}

// Func #1098 | PC: 0x036d60..0x036da0 (64 B) | Symbol: sub_036d60
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcb0]; adrp x17, #0x9c000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcb0]; adrp x17, #0x9c000]
uint64_t fde_sub_036d60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000308ULL) << 32) | 0x97FF2B90ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x036D60ULL;
}

// Func #1099 | PC: 0x0371cc..0x03720c (64 B) | Symbol: sub_0371cc
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc60]; ldr x9, [sp, #0x28]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc60]; ldr x9, [sp, #0x28]]
uint64_t fde_sub_0371cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000308ULL) << 32) | 0x97FF2A75ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0371CCULL;
}

// Func #1100 | PC: 0x03733c..0x03737c (64 B) | Symbol: sub_03733c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03733c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x94014511ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03733CULL;
}

// Func #1101 | PC: 0x03734c..0x03738c (64 B) | Symbol: sub_03734c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03734c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x9401450DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03734CULL;
}

// Func #1102 | PC: 0x03735c..0x03739c (64 B) | Symbol: sub_03735c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03735c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x94014509ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03735CULL;
}

// Func #1103 | PC: 0x03736c..0x0373ac (64 B) | Symbol: sub_03736c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03736c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94047E1ULL) << 32) | 0x94014505ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03736CULL;
}

// Func #1104 | PC: 0x03737c..0x0373bc (64 B) | Symbol: sub_03737c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03737c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x94014501ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03737CULL;
}

// Func #1105 | PC: 0x03738c..0x0373cc (64 B) | Symbol: sub_03738c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03738c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x940144FDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03738CULL;
}

// Func #1106 | PC: 0x03739c..0x0373dc (64 B) | Symbol: sub_03739c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03739c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x940144F9ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03739CULL;
}

// Func #1107 | PC: 0x0373ac..0x0373ec (64 B) | Symbol: sub_0373ac
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0373ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x940144F5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0373ACULL;
}

// Func #1108 | PC: 0x0373bc..0x0373fc (64 B) | Symbol: sub_0373bc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0373bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x940144F1ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0373BCULL;
}

// Func #1109 | PC: 0x0373cc..0x03740c (64 B) | Symbol: sub_0373cc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0373cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x940144EDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0373CCULL;
}

// Func #1110 | PC: 0x0373dc..0x03741c (64 B) | Symbol: sub_0373dc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0373dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x940144E9ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0373DCULL;
}

// Func #1111 | PC: 0x0373ec..0x03742c (64 B) | Symbol: sub_0373ec
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0373ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x940144E5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0373ECULL;
}

// Func #1112 | PC: 0x0373fc..0x03743c (64 B) | Symbol: sub_0373fc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0373fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x940144E1ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0373FCULL;
}

// Func #1113 | PC: 0x03740c..0x03744c (64 B) | Symbol: sub_03740c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03740c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x940144DDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03740CULL;
}

// Func #1114 | PC: 0x03741c..0x03745c (64 B) | Symbol: sub_03741c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03741c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x940144D9ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03741CULL;
}

// Func #1115 | PC: 0x03742c..0x03746c (64 B) | Symbol: sub_03742c
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26]
uint64_t fde_sub_03742c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x940144D5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03742CULL;
}

// Func #1116 | PC: 0x03743c..0x03747c (64 B) | Symbol: sub_03743c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03743c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x940144D1ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03743CULL;
}

// Func #1117 | PC: 0x03744c..0x03748c (64 B) | Symbol: sub_03744c
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x27; mov x2, x27] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x27; mov x2, x27]
uint64_t fde_sub_03744c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x940144CDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03744CULL;
}

// Func #1118 | PC: 0x03745c..0x03749c (64 B) | Symbol: sub_03745c
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23]
uint64_t fde_sub_03745c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x940144C9ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03745CULL;
}

// Func #1119 | PC: 0x03746c..0x0374ac (64 B) | Symbol: sub_03746c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03746c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x940144C5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03746CULL;
}

// Func #1120 | PC: 0x03747c..0x0374bc (64 B) | Symbol: sub_03747c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03747c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x940144C1ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03747CULL;
}

// Func #1121 | PC: 0x03748c..0x0374cc (64 B) | Symbol: sub_03748c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03748c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94003E1ULL) << 32) | 0x940144BDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03748CULL;
}

// Func #1122 | PC: 0x03749c..0x0374dc (64 B) | Symbol: sub_03749c
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22]
uint64_t fde_sub_03749c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x940144B9ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03749CULL;
}

// Func #1123 | PC: 0x0374ac..0x0374ec (64 B) | Symbol: sub_0374ac
// EN: AArch64 prologue [bl #0x88780; add x12, sp, #0x538; movi v0.2d, #0000000000000000; add x8, sp, #0x8b9] | VI: Khởi đầu hàm AArch64 [bl #0x88780; add x12, sp, #0x538; movi v0.2d, #0000000000000000; add x8, sp, #0x8b9]
uint64_t fde_sub_0374ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9114E3ECULL) << 32) | 0x940144B5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0374ACULL;
}

// Func #1124 | PC: 0x037fa0..0x037fe0 (64 B) | Symbol: sub_037fa0
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x538; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x538; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_037fa0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9114E3E0ULL) << 32) | 0x940144D5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x037FA0ULL;
}

// Func #1125 | PC: 0x037fa8..0x037fe8 (64 B) | Symbol: sub_037fa8
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x37fbc; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x37fbc; subs x19, x19, #0x30]
uint64_t fde_sub_037fa8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x94013D31ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x037FA8ULL;
}

// Func #1126 | PC: 0x037fd8..0x038018 (64 B) | Symbol: sub_037fd8
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x37fb4; add x8, x25, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x37fb4; add x8, x25, x19]
uint64_t fde_sub_037fd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FF26BEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x037FD8ULL;
}

// Func #1127 | PC: 0x037fec..0x03802c (64 B) | Symbol: sub_037fec
// EN: AArch64 prologue [bl #0x1ad0; b #0x37fb4; adrp x0, #0xd2000; add x0, x0, #0xd70] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x37fb4; adrp x0, #0xd2000; add x0, x0, #0xd70]
uint64_t fde_sub_037fec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FF26B9ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x037FECULL;
}

// Func #1128 | PC: 0x037ffc..0x03803c (64 B) | Symbol: sub_037ffc
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xb0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xb0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_037ffc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9405BF3ULL) << 32) | 0x97FF26BDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x037FFCULL;
}

// Func #1129 | PC: 0x038038..0x038078 (64 B) | Symbol: sub_038038
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_038038(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FF26E2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038038ULL;
}

// Func #1130 | PC: 0x03803c..0x039e3c (7680 B) | Symbol: rex_locale_init_ctor_27
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_03803c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03803CULL;
}

// Func #1131 | PC: 0x038058..0x038098 (64 B) | Symbol: sub_038058
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_038058(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD13103FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038058ULL;
}

// Func #1132 | PC: 0x03805c..0x03809c (64 B) | Symbol: sub_03805c
// EN: AArch64 prologue [sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_03805c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD13103FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03805CULL;
}

// Func #1133 | PC: 0x038084..0x0380c4 (64 B) | Symbol: sub_038084
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x39ee8; mov x4, #0x6566; movi v1.2d, #0000000000000000] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x39ee8; mov x4, #0x6566; movi v1.2d, #0000000000000000]
uint64_t fde_sub_038084(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3400F300ULL) << 32) | 0x97FF26DFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038084ULL;
}

// Func #1134 | PC: 0x0388e0..0x038920 (64 B) | Symbol: sub_0388e0
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x99000; add x9, x9, #0xcda; ldur q0, [x9, #0xc]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x99000; add x9, x9, #0xcda; ldur q0, [x9, #0xc]]
uint64_t fde_sub_0388e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000309ULL) << 32) | 0x97FF24B0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0388E0ULL;
}

// Func #1135 | PC: 0x038994..0x0389d4 (64 B) | Symbol: sub_038994
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xc70]; adrp x16, #0x99000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xc70]; adrp x16, #0x99000]
uint64_t fde_sub_038994(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00002E9ULL) << 32) | 0x97FF2483ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038994ULL;
}

// Func #1136 | PC: 0x038dfc..0x038e3c (64 B) | Symbol: sub_038dfc
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc90]; ldr x9, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc90]; ldr x9, [sp, #0x20]]
uint64_t fde_sub_038dfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00002E8ULL) << 32) | 0x97FF2369ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038DFCULL;
}

// Func #1137 | PC: 0x038f68..0x038fa8 (64 B) | Symbol: sub_038f68
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_038f68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x94013E06ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038F68ULL;
}

// Func #1138 | PC: 0x038f78..0x038fb8 (64 B) | Symbol: sub_038f78
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_038f78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x94013E02ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038F78ULL;
}

// Func #1139 | PC: 0x038f88..0x038fc8 (64 B) | Symbol: sub_038f88
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_038f88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x94013DFEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038F88ULL;
}

// Func #1140 | PC: 0x038f98..0x038fd8 (64 B) | Symbol: sub_038f98
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_038f98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94047E1ULL) << 32) | 0x94013DFAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038F98ULL;
}

// Func #1141 | PC: 0x038fa8..0x038fe8 (64 B) | Symbol: sub_038fa8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_038fa8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x94013DF6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038FA8ULL;
}

// Func #1142 | PC: 0x038fb8..0x038ff8 (64 B) | Symbol: sub_038fb8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_038fb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x94013DF2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038FB8ULL;
}

// Func #1143 | PC: 0x038fc8..0x039008 (64 B) | Symbol: sub_038fc8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_038fc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x94013DEEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038FC8ULL;
}

// Func #1144 | PC: 0x038fd8..0x039018 (64 B) | Symbol: sub_038fd8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_038fd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x94013DEAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038FD8ULL;
}

// Func #1145 | PC: 0x038fe8..0x039028 (64 B) | Symbol: sub_038fe8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_038fe8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x94013DE6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038FE8ULL;
}

// Func #1146 | PC: 0x038ff8..0x039038 (64 B) | Symbol: sub_038ff8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_038ff8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x94013DE2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038FF8ULL;
}

// Func #1147 | PC: 0x039008..0x039048 (64 B) | Symbol: sub_039008
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_039008(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x94013DDEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x039008ULL;
}

// Func #1148 | PC: 0x039018..0x039058 (64 B) | Symbol: sub_039018
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_039018(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x94013DDAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x039018ULL;
}

// Func #1149 | PC: 0x039028..0x039068 (64 B) | Symbol: sub_039028
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_039028(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x94013DD6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x039028ULL;
}

// Func #1150 | PC: 0x039038..0x039078 (64 B) | Symbol: sub_039038
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_039038(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x94013DD2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x039038ULL;
}

// Func #1151 | PC: 0x039048..0x039088 (64 B) | Symbol: sub_039048
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_039048(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x94013DCEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x039048ULL;
}

// Func #1152 | PC: 0x039058..0x039098 (64 B) | Symbol: sub_039058
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_039058(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x94013DCAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x039058ULL;
}

// Func #1153 | PC: 0x039068..0x0390a8 (64 B) | Symbol: sub_039068
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_039068(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x94013DC6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x039068ULL;
}

// Func #1154 | PC: 0x039078..0x0390b8 (64 B) | Symbol: sub_039078
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x28; mov x2, x28] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x28; mov x2, x28]
uint64_t fde_sub_039078(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94013DC2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x039078ULL;
}

// Func #1155 | PC: 0x039088..0x0390c8 (64 B) | Symbol: sub_039088
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x21; mov x2, x21] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x21; mov x2, x21]
uint64_t fde_sub_039088(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94013DBEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x039088ULL;
}

// Func #1156 | PC: 0x039098..0x0390d8 (64 B) | Symbol: sub_039098
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_039098(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94003E1ULL) << 32) | 0x94013DBAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x039098ULL;
}

// Func #1157 | PC: 0x0390a8..0x0390e8 (64 B) | Symbol: sub_0390a8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0390a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x94013DB6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0390A8ULL;
}

// Func #1158 | PC: 0x0390b8..0x0390f8 (64 B) | Symbol: sub_0390b8
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23]
uint64_t fde_sub_0390b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94013DB2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0390B8ULL;
}

// Func #1159 | PC: 0x0390c8..0x039108 (64 B) | Symbol: sub_0390c8
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x25; mov x2, x25] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x25; mov x2, x25]
uint64_t fde_sub_0390c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94013DAEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0390C8ULL;
}

// Func #1160 | PC: 0x0390d8..0x039118 (64 B) | Symbol: sub_0390d8
// EN: AArch64 prologue [bl #0x88780; mov w10, #0x2e65; add x13, sp, #0x538; movk w10, #0x2e68, lsl #16] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov w10, #0x2e65; add x13, sp, #0x538; movk w10, #0x2e68, lsl #16]
uint64_t fde_sub_0390d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5285CCAAULL) << 32) | 0x94013DAAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0390D8ULL;
}

// Func #1161 | PC: 0x039e84..0x039ec4 (64 B) | Symbol: sub_039e84
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x538; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x538; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_039e84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9114E3E0ULL) << 32) | 0x94013D1CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x039E84ULL;
}

// Func #1162 | PC: 0x039e8c..0x039ecc (64 B) | Symbol: sub_039e8c
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x39ea0; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x39ea0; subs x19, x19, #0x30]
uint64_t fde_sub_039e8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x94013578ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x039E8CULL;
}

// Func #1163 | PC: 0x039ebc..0x039efc (64 B) | Symbol: sub_039ebc
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x39e98; add x8, x26, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x39e98; add x8, x26, x19]
uint64_t fde_sub_039ebc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FF1F05ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x039EBCULL;
}

// Func #1164 | PC: 0x039ed0..0x039f10 (64 B) | Symbol: sub_039ed0
// EN: AArch64 prologue [bl #0x1ad0; b #0x39e98; adrp x0, #0xd4000; add x0, x0, #0x470] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x39e98; adrp x0, #0xd4000; add x0, x0, #0x470]
uint64_t fde_sub_039ed0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FF1F00ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x039ED0ULL;
}

// Func #1165 | PC: 0x039ee0..0x039f20 (64 B) | Symbol: sub_039ee0
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xb0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xb0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_039ee0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9405BF3ULL) << 32) | 0x97FF1F04ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x039EE0ULL;
}

// Func #1166 | PC: 0x039f1c..0x039f5c (64 B) | Symbol: sub_039f1c
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_039f1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FF1F29ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x039F1CULL;
}

// Func #1167 | PC: 0x039f20..0x03bd20 (7680 B) | Symbol: rex_locale_init_ctor_28
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_039f20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x039F20ULL;
}

// Func #1168 | PC: 0x039f3c..0x039f7c (64 B) | Symbol: sub_039f3c
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc20; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc20; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_039f3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD13083FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x039F3CULL;
}

// Func #1169 | PC: 0x039f40..0x039f80 (64 B) | Symbol: sub_039f40
// EN: AArch64 prologue [sub sp, sp, #0xc20; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc20; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_039f40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD13083FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x039F40ULL;
}

// Func #1170 | PC: 0x039f68..0x039fa8 (64 B) | Symbol: sub_039f68
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x3bd10; add x8, sp, #0x98; mov x13, #0x6566] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x3bd10; add x8, sp, #0x98; mov x13, #0x6566]
uint64_t fde_sub_039f68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3400ED20ULL) << 32) | 0x97FF1F26ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x039F68ULL;
}

// Func #1171 | PC: 0x03a7a8..0x03a7e8 (64 B) | Symbol: sub_03a7a8
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xc90]; adrp x11, #0x9b000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xc90]; adrp x11, #0x9b000]
uint64_t fde_sub_03a7a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00002E9ULL) << 32) | 0x97FF1CFEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03A7A8ULL;
}

// Func #1172 | PC: 0x03adcc..0x03ae0c (64 B) | Symbol: sub_03adcc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03adcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x9401366DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03ADCCULL;
}

// Func #1173 | PC: 0x03addc..0x03ae1c (64 B) | Symbol: sub_03addc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03addc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x94013669ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03ADDCULL;
}

// Func #1174 | PC: 0x03adec..0x03ae2c (64 B) | Symbol: sub_03adec
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03adec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x94013665ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03ADECULL;
}

// Func #1175 | PC: 0x03adfc..0x03ae3c (64 B) | Symbol: sub_03adfc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03adfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x94013661ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03ADFCULL;
}

// Func #1176 | PC: 0x03ae0c..0x03ae4c (64 B) | Symbol: sub_03ae0c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03ae0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x9401365DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AE0CULL;
}

// Func #1177 | PC: 0x03ae1c..0x03ae5c (64 B) | Symbol: sub_03ae1c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03ae1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x94013659ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AE1CULL;
}

// Func #1178 | PC: 0x03ae2c..0x03ae6c (64 B) | Symbol: sub_03ae2c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03ae2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x94013655ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AE2CULL;
}

// Func #1179 | PC: 0x03ae3c..0x03ae7c (64 B) | Symbol: sub_03ae3c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03ae3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94003E1ULL) << 32) | 0x94013651ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AE3CULL;
}

// Func #1180 | PC: 0x03ae4c..0x03ae8c (64 B) | Symbol: sub_03ae4c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03ae4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x9401364DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AE4CULL;
}

// Func #1181 | PC: 0x03ae5c..0x03ae9c (64 B) | Symbol: sub_03ae5c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03ae5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x94013649ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AE5CULL;
}

// Func #1182 | PC: 0x03ae6c..0x03aeac (64 B) | Symbol: sub_03ae6c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03ae6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x94013645ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AE6CULL;
}

// Func #1183 | PC: 0x03ae7c..0x03aebc (64 B) | Symbol: sub_03ae7c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03ae7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x94013641ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AE7CULL;
}

// Func #1184 | PC: 0x03ae8c..0x03aecc (64 B) | Symbol: sub_03ae8c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03ae8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x9401363DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AE8CULL;
}

// Func #1185 | PC: 0x03ae9c..0x03aedc (64 B) | Symbol: sub_03ae9c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03ae9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x94013639ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AE9CULL;
}

// Func #1186 | PC: 0x03aeac..0x03aeec (64 B) | Symbol: sub_03aeac
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03aeac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x94013635ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AEACULL;
}

// Func #1187 | PC: 0x03aebc..0x03aefc (64 B) | Symbol: sub_03aebc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03aebc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x94013631ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AEBCULL;
}

// Func #1188 | PC: 0x03aecc..0x03af0c (64 B) | Symbol: sub_03aecc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03aecc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x9401362DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AECCULL;
}

// Func #1189 | PC: 0x03aedc..0x03af1c (64 B) | Symbol: sub_03aedc
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x28; mov x2, x28] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x28; mov x2, x28]
uint64_t fde_sub_03aedc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94013629ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AEDCULL;
}

// Func #1190 | PC: 0x03aeec..0x03af2c (64 B) | Symbol: sub_03aeec
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x20; mov x2, x20] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x20; mov x2, x20]
uint64_t fde_sub_03aeec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94013625ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AEECULL;
}

// Func #1191 | PC: 0x03aefc..0x03af3c (64 B) | Symbol: sub_03aefc
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26]
uint64_t fde_sub_03aefc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94013621ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AEFCULL;
}

// Func #1192 | PC: 0x03af0c..0x03af4c (64 B) | Symbol: sub_03af0c
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x27; mov x2, x27] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x27; mov x2, x27]
uint64_t fde_sub_03af0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401361DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AF0CULL;
}

// Func #1193 | PC: 0x03af1c..0x03af5c (64 B) | Symbol: sub_03af1c
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x24; mov x2, x24] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x24; mov x2, x24]
uint64_t fde_sub_03af1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94013619ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AF1CULL;
}

// Func #1194 | PC: 0x03af2c..0x03af6c (64 B) | Symbol: sub_03af2c
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23]
uint64_t fde_sub_03af2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94013615ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AF2CULL;
}

// Func #1195 | PC: 0x03af3c..0x03af7c (64 B) | Symbol: sub_03af3c
// EN: AArch64 prologue [bl #0x88780; add x12, sp, #0x518; add x8, x12, #0x508; movi v0.2d, #0000000000000000] | VI: Khởi đầu hàm AArch64 [bl #0x88780; add x12, sp, #0x518; add x8, x12, #0x508; movi v0.2d, #0000000000000000]
uint64_t fde_sub_03af3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911463ECULL) << 32) | 0x94013611ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03AF3CULL;
}

// Func #1196 | PC: 0x03bcac..0x03bcec (64 B) | Symbol: sub_03bcac
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x518; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x518; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_03bcac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911463E0ULL) << 32) | 0x94013592ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03BCACULL;
}

// Func #1197 | PC: 0x03bcb4..0x03bcf4 (64 B) | Symbol: sub_03bcb4
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x3bcc8; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x3bcc8; subs x19, x19, #0x30]
uint64_t fde_sub_03bcb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x94012DEEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03BCB4ULL;
}

// Func #1198 | PC: 0x03bce4..0x03bd24 (64 B) | Symbol: sub_03bce4
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x3bcc0; add x8, x21, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x3bcc0; add x8, x21, x19]
uint64_t fde_sub_03bce4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FF177BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03BCE4ULL;
}

// Func #1199 | PC: 0x03bcf8..0x03bd38 (64 B) | Symbol: sub_03bcf8
// EN: AArch64 prologue [bl #0x1ad0; b #0x3bcc0; adrp x0, #0xd5000; add x0, x0, #0xb70] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x3bcc0; adrp x0, #0xd5000; add x0, x0, #0xb70]
uint64_t fde_sub_03bcf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FF1776ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03BCF8ULL;
}

// Func #1200 | PC: 0x03bd08..0x03bd48 (64 B) | Symbol: sub_03bd08
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0x90]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0x90]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_03bd08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BF3ULL) << 32) | 0x97FF177AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03BD08ULL;
}

// Func #1201 | PC: 0x03bd44..0x03bd84 (64 B) | Symbol: sub_03bd44
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_03bd44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FF179FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03BD44ULL;
}

// Func #1202 | PC: 0x03bd48..0x03db48 (7680 B) | Symbol: rex_locale_init_ctor_29
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_03bd48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03BD48ULL;
}

// Func #1203 | PC: 0x03bd64..0x03bda4 (64 B) | Symbol: sub_03bd64
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc70; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc70; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_03bd64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD131C3FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03BD64ULL;
}

// Func #1204 | PC: 0x03bd68..0x03bda8 (64 B) | Symbol: sub_03bd68
// EN: AArch64 prologue [sub sp, sp, #0xc70; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc70; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_03bd68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD131C3FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03BD68ULL;
}

// Func #1205 | PC: 0x03bd90..0x03bdd0 (64 B) | Symbol: sub_03bd90
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x3d8c0; str x19, [sp, #0xe0]; movi v0.2d, #0000000000000000] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x3d8c0; str x19, [sp, #0xe0]; movi v0.2d, #0000000000000000]
uint64_t fde_sub_03bd90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3400D960ULL) << 32) | 0x97FF179CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03BD90ULL;
}

// Func #1206 | PC: 0x03c564..0x03c5a4 (64 B) | Symbol: sub_03c564
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9c000; add x9, x9, #0xed7; ldp q0, q1, [x9]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9c000; add x9, x9, #0xed7; ldp q0, q1, [x9]]
uint64_t fde_sub_03c564(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000309ULL) << 32) | 0x97FF158FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03C564ULL;
}

// Func #1207 | PC: 0x03c624..0x03c664 (64 B) | Symbol: sub_03c624
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xc60]; adrp x16, #0x9c000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xc60]; adrp x16, #0x9c000]
uint64_t fde_sub_03c624(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00002C9ULL) << 32) | 0x97FF155FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03C624ULL;
}

// Func #1208 | PC: 0x03ca84..0x03cac4 (64 B) | Symbol: sub_03ca84
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc90]; ldr x9, [sp, #0x28]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc90]; ldr x9, [sp, #0x28]]
uint64_t fde_sub_03ca84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00002C8ULL) << 32) | 0x97FF1447ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CA84ULL;
}

// Func #1209 | PC: 0x03cbf4..0x03cc34 (64 B) | Symbol: sub_03cbf4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03cbf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x94012EE3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CBF4ULL;
}

// Func #1210 | PC: 0x03cc04..0x03cc44 (64 B) | Symbol: sub_03cc04
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03cc04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x94012EDFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CC04ULL;
}

// Func #1211 | PC: 0x03cc14..0x03cc54 (64 B) | Symbol: sub_03cc14
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03cc14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x94012EDBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CC14ULL;
}

// Func #1212 | PC: 0x03cc24..0x03cc64 (64 B) | Symbol: sub_03cc24
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03cc24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94047E1ULL) << 32) | 0x94012ED7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CC24ULL;
}

// Func #1213 | PC: 0x03cc34..0x03cc74 (64 B) | Symbol: sub_03cc34
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03cc34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x94012ED3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CC34ULL;
}

// Func #1214 | PC: 0x03cc44..0x03cc84 (64 B) | Symbol: sub_03cc44
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03cc44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x94012ECFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CC44ULL;
}

// Func #1215 | PC: 0x03cc54..0x03cc94 (64 B) | Symbol: sub_03cc54
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03cc54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x94012ECBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CC54ULL;
}

// Func #1216 | PC: 0x03cc64..0x03cca4 (64 B) | Symbol: sub_03cc64
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03cc64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x94012EC7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CC64ULL;
}

// Func #1217 | PC: 0x03cc74..0x03ccb4 (64 B) | Symbol: sub_03cc74
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03cc74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x94012EC3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CC74ULL;
}

// Func #1218 | PC: 0x03cc84..0x03ccc4 (64 B) | Symbol: sub_03cc84
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03cc84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x94012EBFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CC84ULL;
}

// Func #1219 | PC: 0x03cc94..0x03ccd4 (64 B) | Symbol: sub_03cc94
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03cc94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x94012EBBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CC94ULL;
}

// Func #1220 | PC: 0x03cca4..0x03cce4 (64 B) | Symbol: sub_03cca4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03cca4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x94012EB7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CCA4ULL;
}

// Func #1221 | PC: 0x03ccb4..0x03ccf4 (64 B) | Symbol: sub_03ccb4
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x24; mov x2, x24] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x24; mov x2, x24]
uint64_t fde_sub_03ccb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94012EB3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CCB4ULL;
}

// Func #1222 | PC: 0x03ccc4..0x03cd04 (64 B) | Symbol: sub_03ccc4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03ccc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x94012EAFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CCC4ULL;
}

// Func #1223 | PC: 0x03ccd4..0x03cd14 (64 B) | Symbol: sub_03ccd4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03ccd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x94012EABULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CCD4ULL;
}

// Func #1224 | PC: 0x03cce4..0x03cd24 (64 B) | Symbol: sub_03cce4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03cce4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x94012EA7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CCE4ULL;
}

// Func #1225 | PC: 0x03ccf4..0x03cd34 (64 B) | Symbol: sub_03ccf4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03ccf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x94012EA3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CCF4ULL;
}

// Func #1226 | PC: 0x03cd04..0x03cd44 (64 B) | Symbol: sub_03cd04
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26]
uint64_t fde_sub_03cd04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94012E9FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CD04ULL;
}

// Func #1227 | PC: 0x03cd14..0x03cd54 (64 B) | Symbol: sub_03cd14
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x21; mov x2, x21] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x21; mov x2, x21]
uint64_t fde_sub_03cd14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94012E9BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CD14ULL;
}

// Func #1228 | PC: 0x03cd24..0x03cd64 (64 B) | Symbol: sub_03cd24
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03cd24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x94012E97ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CD24ULL;
}

// Func #1229 | PC: 0x03cd34..0x03cd74 (64 B) | Symbol: sub_03cd34
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03cd34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x94012E93ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CD34ULL;
}

// Func #1230 | PC: 0x03cd44..0x03cd84 (64 B) | Symbol: sub_03cd44
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03cd44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94003E1ULL) << 32) | 0x94012E8FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CD44ULL;
}

// Func #1231 | PC: 0x03cd54..0x03cd94 (64 B) | Symbol: sub_03cd54
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x25; mov x2, x25] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x25; mov x2, x25]
uint64_t fde_sub_03cd54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94012E8BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CD54ULL;
}

// Func #1232 | PC: 0x03cd64..0x03cda4 (64 B) | Symbol: sub_03cd64
// EN: AArch64 prologue [bl #0x88780; add x14, sp, #0x568; mov w10, #0x8de5; movi v0.2d, #0000000000000000] | VI: Khởi đầu hàm AArch64 [bl #0x88780; add x14, sp, #0x568; mov w10, #0x8de5; movi v0.2d, #0000000000000000]
uint64_t fde_sub_03cd64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9115A3EEULL) << 32) | 0x94012E87ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CD64ULL;
}

// Func #1233 | PC: 0x03d85c..0x03d89c (64 B) | Symbol: sub_03d85c
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x568; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x568; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_03d85c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9115A3E0ULL) << 32) | 0x94012EA6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03D85CULL;
}

// Func #1234 | PC: 0x03d864..0x03d8a4 (64 B) | Symbol: sub_03d864
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x3d878; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x3d878; subs x19, x19, #0x30]
uint64_t fde_sub_03d864(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x94012702ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03D864ULL;
}

// Func #1235 | PC: 0x03d894..0x03d8d4 (64 B) | Symbol: sub_03d894
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x3d870; add x8, x23, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x3d870; add x8, x23, x19]
uint64_t fde_sub_03d894(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FF108FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03D894ULL;
}

// Func #1236 | PC: 0x03d8a8..0x03d8e8 (64 B) | Symbol: sub_03d8a8
// EN: AArch64 prologue [bl #0x1ad0; b #0x3d870; adrp x0, #0xd7000; add x0, x0, #0x270] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x3d870; adrp x0, #0xd7000; add x0, x0, #0x270]
uint64_t fde_sub_03d8a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FF108AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03D8A8ULL;
}

// Func #1237 | PC: 0x03d8b8..0x03d8f8 (64 B) | Symbol: sub_03d8b8
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xe0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xe0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_03d8b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94073F3ULL) << 32) | 0x97FF108EULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03D8B8ULL;
}

// Func #1238 | PC: 0x03d8f4..0x03d934 (64 B) | Symbol: sub_03d8f4
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_03d8f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FF10B3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03D8F4ULL;
}

// Func #1239 | PC: 0x03d8f8..0x03f6f8 (7680 B) | Symbol: rex_locale_init_ctor_30
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_03d8f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03D8F8ULL;
}

// Func #1240 | PC: 0x03d914..0x03d954 (64 B) | Symbol: sub_03d914
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_03d914(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD13103FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03D914ULL;
}

// Func #1241 | PC: 0x03d918..0x03d958 (64 B) | Symbol: sub_03d918
// EN: AArch64 prologue [sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc40; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_03d918(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD13103FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03D918ULL;
}

// Func #1242 | PC: 0x03d940..0x03d980 (64 B) | Symbol: sub_03d940
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x3f530; mov x14, #0x6546; movk x14, #0x7262, lsl #16] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x3f530; mov x14, #0x6546; movk x14, #0x7262, lsl #16]
uint64_t fde_sub_03d940(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3400DF60ULL) << 32) | 0x97FF10B0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03D940ULL;
}

// Func #1243 | PC: 0x03e1c0..0x03e200 (64 B) | Symbol: sub_03e1c0
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x98000; add x9, x9, #0x95c; ldur q0, [x9, #0xa]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x98000; add x9, x9, #0x95c; ldur q0, [x9, #0xa]]
uint64_t fde_sub_03e1c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00002C9ULL) << 32) | 0x97FF0E78ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E1C0ULL;
}

// Func #1244 | PC: 0x03e284..0x03e2c4 (64 B) | Symbol: sub_03e284
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcb0]; adrp x16, #0x98000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xcb0]; adrp x16, #0x98000]
uint64_t fde_sub_03e284(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00002C8ULL) << 32) | 0x97FF0E47ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E284ULL;
}

// Func #1245 | PC: 0x03e6e4..0x03e724 (64 B) | Symbol: sub_03e6e4
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc60]; ldr x9, [sp, #0x28]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc60]; ldr x9, [sp, #0x28]]
uint64_t fde_sub_03e6e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00002C8ULL) << 32) | 0x97FF0D2FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E6E4ULL;
}

// Func #1246 | PC: 0x03e854..0x03e894 (64 B) | Symbol: sub_03e854
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03e854(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x940127CBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E854ULL;
}

// Func #1247 | PC: 0x03e864..0x03e8a4 (64 B) | Symbol: sub_03e864
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03e864(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x940127C7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E864ULL;
}

// Func #1248 | PC: 0x03e874..0x03e8b4 (64 B) | Symbol: sub_03e874
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03e874(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x940127C3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E874ULL;
}

// Func #1249 | PC: 0x03e884..0x03e8c4 (64 B) | Symbol: sub_03e884
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03e884(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94047E1ULL) << 32) | 0x940127BFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E884ULL;
}

// Func #1250 | PC: 0x03e894..0x03e8d4 (64 B) | Symbol: sub_03e894
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03e894(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x940127BBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E894ULL;
}

// Func #1251 | PC: 0x03e8a4..0x03e8e4 (64 B) | Symbol: sub_03e8a4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03e8a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x940127B7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E8A4ULL;
}

// Func #1252 | PC: 0x03e8b4..0x03e8f4 (64 B) | Symbol: sub_03e8b4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03e8b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x940127B3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E8B4ULL;
}

// Func #1253 | PC: 0x03e8c4..0x03e904 (64 B) | Symbol: sub_03e8c4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03e8c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x940127AFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E8C4ULL;
}

// Func #1254 | PC: 0x03e8d4..0x03e914 (64 B) | Symbol: sub_03e8d4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03e8d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x940127ABULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E8D4ULL;
}

// Func #1255 | PC: 0x03e8e4..0x03e924 (64 B) | Symbol: sub_03e8e4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03e8e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x940127A7ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E8E4ULL;
}

// Func #1256 | PC: 0x03e8f4..0x03e934 (64 B) | Symbol: sub_03e8f4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03e8f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x940127A3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E8F4ULL;
}

// Func #1257 | PC: 0x03e904..0x03e944 (64 B) | Symbol: sub_03e904
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03e904(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x9401279FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E904ULL;
}

// Func #1258 | PC: 0x03e914..0x03e954 (64 B) | Symbol: sub_03e914
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03e914(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x9401279BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E914ULL;
}

// Func #1259 | PC: 0x03e924..0x03e964 (64 B) | Symbol: sub_03e924
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03e924(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x94012797ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E924ULL;
}

// Func #1260 | PC: 0x03e934..0x03e974 (64 B) | Symbol: sub_03e934
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03e934(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x94012793ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E934ULL;
}

// Func #1261 | PC: 0x03e944..0x03e984 (64 B) | Symbol: sub_03e944
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26]
uint64_t fde_sub_03e944(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401278FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E944ULL;
}

// Func #1262 | PC: 0x03e954..0x03e994 (64 B) | Symbol: sub_03e954
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03e954(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x9401278BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E954ULL;
}

// Func #1263 | PC: 0x03e964..0x03e9a4 (64 B) | Symbol: sub_03e964
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x27; mov x2, x27] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x27; mov x2, x27]
uint64_t fde_sub_03e964(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94012787ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E964ULL;
}

// Func #1264 | PC: 0x03e974..0x03e9b4 (64 B) | Symbol: sub_03e974
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x20; mov x2, x20] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x20; mov x2, x20]
uint64_t fde_sub_03e974(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94012783ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E974ULL;
}

// Func #1265 | PC: 0x03e984..0x03e9c4 (64 B) | Symbol: sub_03e984
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03e984(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x9401277FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E984ULL;
}

// Func #1266 | PC: 0x03e994..0x03e9d4 (64 B) | Symbol: sub_03e994
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03e994(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x9401277BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E994ULL;
}

// Func #1267 | PC: 0x03e9a4..0x03e9e4 (64 B) | Symbol: sub_03e9a4
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_03e9a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94003E1ULL) << 32) | 0x94012777ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E9A4ULL;
}

// Func #1268 | PC: 0x03e9b4..0x03e9f4 (64 B) | Symbol: sub_03e9b4
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23]
uint64_t fde_sub_03e9b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94012773ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E9B4ULL;
}

// Func #1269 | PC: 0x03e9c4..0x03ea04 (64 B) | Symbol: sub_03e9c4
// EN: AArch64 prologue [bl #0x88780; add x13, sp, #0x538; movi v0.2d, #0000000000000000; add x9, sp, #0x8b9] | VI: Khởi đầu hàm AArch64 [bl #0x88780; add x13, sp, #0x538; movi v0.2d, #0000000000000000; add x9, sp, #0x8b9]
uint64_t fde_sub_03e9c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9114E3EDULL) << 32) | 0x9401276FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E9C4ULL;
}

// Func #1270 | PC: 0x03f4cc..0x03f50c (64 B) | Symbol: sub_03f4cc
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x538; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x538; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_03f4cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9114E3E0ULL) << 32) | 0x9401278AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F4CCULL;
}

// Func #1271 | PC: 0x03f4d4..0x03f514 (64 B) | Symbol: sub_03f4d4
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x3f4e8; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x3f4e8; subs x19, x19, #0x30]
uint64_t fde_sub_03f4d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x94011FE6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F4D4ULL;
}

// Func #1272 | PC: 0x03f504..0x03f544 (64 B) | Symbol: sub_03f504
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x3f4e0; add x8, x28, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x3f4e0; add x8, x28, x19]
uint64_t fde_sub_03f504(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FF0973ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F504ULL;
}

// Func #1273 | PC: 0x03f518..0x03f558 (64 B) | Symbol: sub_03f518
// EN: AArch64 prologue [bl #0x1ad0; b #0x3f4e0; adrp x0, #0xd8000; add x0, x0, #0x970] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x3f4e0; adrp x0, #0xd8000; add x0, x0, #0x970]
uint64_t fde_sub_03f518(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FF096EULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F518ULL;
}

// Func #1274 | PC: 0x03f528..0x03f568 (64 B) | Symbol: sub_03f528
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xb0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xb0]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_03f528(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9405BF3ULL) << 32) | 0x97FF0972ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F528ULL;
}

// Func #1275 | PC: 0x03f564..0x03f5a4 (64 B) | Symbol: sub_03f564
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_03f564(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FF0997ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F564ULL;
}

// Func #1276 | PC: 0x03f568..0x041368 (7680 B) | Symbol: rex_locale_init_ctor_31
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_03f568(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F568ULL;
}

// Func #1277 | PC: 0x03f584..0x03f5c4 (64 B) | Symbol: sub_03f584
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xca0; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xca0; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_03f584(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD13283FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F584ULL;
}

// Func #1278 | PC: 0x03f588..0x03f5c8 (64 B) | Symbol: sub_03f588
// EN: AArch64 prologue [sub sp, sp, #0xca0; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xca0; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_03f588(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD13283FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F588ULL;
}

// Func #1279 | PC: 0x03f5b0..0x03f5f0 (64 B) | Symbol: sub_03f5b0
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x41564; adrp x13, #0x9d000; add x13, x13, #0x1e5] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x41564; adrp x13, #0x9d000; add x13, x13, #0x1e5]
uint64_t fde_sub_03f5b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3400FD80ULL) << 32) | 0x97FF0994ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F5B0ULL;
}

uint64_t DispatchRexShard4(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x030264ULL: return fde_sub_030264(a0, a1, a2);
        case 0x0302a0ULL: return fde_sub_0302a0(a0, a1, a2);
        case 0x0302a4ULL: return fde_sub_0302a4(a0, a1, a2);
        case 0x0302c0ULL: return fde_sub_0302c0(a0, a1, a2);
        case 0x0302c4ULL: return fde_sub_0302c4(a0, a1, a2);
        case 0x0302ecULL: return fde_sub_0302ec(a0, a1, a2);
        case 0x030848ULL: return fde_sub_030848(a0, a1, a2);
        case 0x030ce4ULL: return fde_sub_030ce4(a0, a1, a2);
        case 0x030da8ULL: return fde_sub_030da8(a0, a1, a2);
        case 0x031208ULL: return fde_sub_031208(a0, a1, a2);
        case 0x031374ULL: return fde_sub_031374(a0, a1, a2);
        case 0x031384ULL: return fde_sub_031384(a0, a1, a2);
        case 0x031394ULL: return fde_sub_031394(a0, a1, a2);
        case 0x0313a4ULL: return fde_sub_0313a4(a0, a1, a2);
        case 0x0313b4ULL: return fde_sub_0313b4(a0, a1, a2);
        case 0x0313c4ULL: return fde_sub_0313c4(a0, a1, a2);
        case 0x0313d4ULL: return fde_sub_0313d4(a0, a1, a2);
        case 0x0313e4ULL: return fde_sub_0313e4(a0, a1, a2);
        case 0x0313f4ULL: return fde_sub_0313f4(a0, a1, a2);
        case 0x031404ULL: return fde_sub_031404(a0, a1, a2);
        case 0x031414ULL: return fde_sub_031414(a0, a1, a2);
        case 0x031424ULL: return fde_sub_031424(a0, a1, a2);
        case 0x031434ULL: return fde_sub_031434(a0, a1, a2);
        case 0x031444ULL: return fde_sub_031444(a0, a1, a2);
        case 0x031454ULL: return fde_sub_031454(a0, a1, a2);
        case 0x031464ULL: return fde_sub_031464(a0, a1, a2);
        case 0x031474ULL: return fde_sub_031474(a0, a1, a2);
        case 0x031484ULL: return fde_sub_031484(a0, a1, a2);
        case 0x031494ULL: return fde_sub_031494(a0, a1, a2);
        case 0x0314a4ULL: return fde_sub_0314a4(a0, a1, a2);
        case 0x0314b4ULL: return fde_sub_0314b4(a0, a1, a2);
        case 0x0314c4ULL: return fde_sub_0314c4(a0, a1, a2);
        case 0x0314d4ULL: return fde_sub_0314d4(a0, a1, a2);
        case 0x0314e4ULL: return fde_sub_0314e4(a0, a1, a2);
        case 0x0319c8ULL: return fde_sub_0319c8(a0, a1, a2);
        case 0x031a34ULL: return fde_sub_031a34(a0, a1, a2);
        case 0x031a68ULL: return fde_sub_031a68(a0, a1, a2);
        case 0x031ac8ULL: return fde_sub_031ac8(a0, a1, a2);
        case 0x031afcULL: return fde_sub_031afc(a0, a1, a2);
        case 0x031b60ULL: return fde_sub_031b60(a0, a1, a2);
        case 0x031b98ULL: return fde_sub_031b98(a0, a1, a2);
        case 0x031be8ULL: return fde_sub_031be8(a0, a1, a2);
        case 0x031c1cULL: return fde_sub_031c1c(a0, a1, a2);
        case 0x031c6cULL: return fde_sub_031c6c(a0, a1, a2);
        case 0x031ca0ULL: return fde_sub_031ca0(a0, a1, a2);
        case 0x031cf0ULL: return fde_sub_031cf0(a0, a1, a2);
        case 0x031d24ULL: return fde_sub_031d24(a0, a1, a2);
        case 0x031d74ULL: return fde_sub_031d74(a0, a1, a2);
        case 0x031dacULL: return fde_sub_031dac(a0, a1, a2);
        case 0x031dfcULL: return fde_sub_031dfc(a0, a1, a2);
        case 0x031ea0ULL: return fde_sub_031ea0(a0, a1, a2);
        case 0x031ef8ULL: return fde_sub_031ef8(a0, a1, a2);
        case 0x0322f4ULL: return fde_sub_0322f4(a0, a1, a2);
        case 0x0322fcULL: return fde_sub_0322fc(a0, a1, a2);
        case 0x03232cULL: return fde_sub_03232c(a0, a1, a2);
        case 0x032340ULL: return fde_sub_032340(a0, a1, a2);
        case 0x032350ULL: return fde_sub_032350(a0, a1, a2);
        case 0x03238cULL: return fde_sub_03238c(a0, a1, a2);
        case 0x032390ULL: return fde_sub_032390(a0, a1, a2);
        case 0x0323acULL: return fde_sub_0323ac(a0, a1, a2);
        case 0x0323b0ULL: return fde_sub_0323b0(a0, a1, a2);
        case 0x0323d8ULL: return fde_sub_0323d8(a0, a1, a2);
        case 0x032c60ULL: return fde_sub_032c60(a0, a1, a2);
        case 0x032d1cULL: return fde_sub_032d1c(a0, a1, a2);
        case 0x033178ULL: return fde_sub_033178(a0, a1, a2);
        case 0x0332e0ULL: return fde_sub_0332e0(a0, a1, a2);
        case 0x0332f0ULL: return fde_sub_0332f0(a0, a1, a2);
        case 0x033300ULL: return fde_sub_033300(a0, a1, a2);
        case 0x033310ULL: return fde_sub_033310(a0, a1, a2);
        case 0x033320ULL: return fde_sub_033320(a0, a1, a2);
        case 0x033330ULL: return fde_sub_033330(a0, a1, a2);
        case 0x033340ULL: return fde_sub_033340(a0, a1, a2);
        case 0x033350ULL: return fde_sub_033350(a0, a1, a2);
        case 0x033360ULL: return fde_sub_033360(a0, a1, a2);
        case 0x033370ULL: return fde_sub_033370(a0, a1, a2);
        case 0x033380ULL: return fde_sub_033380(a0, a1, a2);
        case 0x033390ULL: return fde_sub_033390(a0, a1, a2);
        case 0x0333a0ULL: return fde_sub_0333a0(a0, a1, a2);
        case 0x0333b0ULL: return fde_sub_0333b0(a0, a1, a2);
        case 0x0333c0ULL: return fde_sub_0333c0(a0, a1, a2);
        case 0x0333d0ULL: return fde_sub_0333d0(a0, a1, a2);
        case 0x0333e0ULL: return fde_sub_0333e0(a0, a1, a2);
        case 0x0333f0ULL: return fde_sub_0333f0(a0, a1, a2);
        case 0x033400ULL: return fde_sub_033400(a0, a1, a2);
        case 0x033410ULL: return fde_sub_033410(a0, a1, a2);
        case 0x033420ULL: return fde_sub_033420(a0, a1, a2);
        case 0x033430ULL: return fde_sub_033430(a0, a1, a2);
        case 0x033440ULL: return fde_sub_033440(a0, a1, a2);
        case 0x033454ULL: return fde_sub_033454(a0, a1, a2);
        case 0x0344b8ULL: return fde_sub_0344b8(a0, a1, a2);
        case 0x0344c0ULL: return fde_sub_0344c0(a0, a1, a2);
        case 0x0344f0ULL: return fde_sub_0344f0(a0, a1, a2);
        case 0x034504ULL: return fde_sub_034504(a0, a1, a2);
        case 0x034514ULL: return fde_sub_034514(a0, a1, a2);
        case 0x034550ULL: return fde_sub_034550(a0, a1, a2);
        case 0x034554ULL: return fde_sub_034554(a0, a1, a2);
        case 0x034570ULL: return fde_sub_034570(a0, a1, a2);
        case 0x034574ULL: return fde_sub_034574(a0, a1, a2);
        case 0x03459cULL: return fde_sub_03459c(a0, a1, a2);
        case 0x034e40ULL: return fde_sub_034e40(a0, a1, a2);
        case 0x034f00ULL: return fde_sub_034f00(a0, a1, a2);
        case 0x0354b0ULL: return fde_sub_0354b0(a0, a1, a2);
        case 0x0354c0ULL: return fde_sub_0354c0(a0, a1, a2);
        case 0x0354d0ULL: return fde_sub_0354d0(a0, a1, a2);
        case 0x0354e0ULL: return fde_sub_0354e0(a0, a1, a2);
        case 0x0354f0ULL: return fde_sub_0354f0(a0, a1, a2);
        case 0x035500ULL: return fde_sub_035500(a0, a1, a2);
        case 0x035510ULL: return fde_sub_035510(a0, a1, a2);
        case 0x035520ULL: return fde_sub_035520(a0, a1, a2);
        case 0x035530ULL: return fde_sub_035530(a0, a1, a2);
        case 0x035540ULL: return fde_sub_035540(a0, a1, a2);
        case 0x035550ULL: return fde_sub_035550(a0, a1, a2);
        case 0x035560ULL: return fde_sub_035560(a0, a1, a2);
        case 0x035570ULL: return fde_sub_035570(a0, a1, a2);
        case 0x035580ULL: return fde_sub_035580(a0, a1, a2);
        case 0x035590ULL: return fde_sub_035590(a0, a1, a2);
        case 0x0355a0ULL: return fde_sub_0355a0(a0, a1, a2);
        case 0x0355b0ULL: return fde_sub_0355b0(a0, a1, a2);
        case 0x0355c0ULL: return fde_sub_0355c0(a0, a1, a2);
        case 0x0355d0ULL: return fde_sub_0355d0(a0, a1, a2);
        case 0x0355e0ULL: return fde_sub_0355e0(a0, a1, a2);
        case 0x0355f0ULL: return fde_sub_0355f0(a0, a1, a2);
        case 0x035600ULL: return fde_sub_035600(a0, a1, a2);
        case 0x035610ULL: return fde_sub_035610(a0, a1, a2);
        case 0x035620ULL: return fde_sub_035620(a0, a1, a2);
        case 0x035d34ULL: return fde_sub_035d34(a0, a1, a2);
        case 0x035d88ULL: return fde_sub_035d88(a0, a1, a2);
        case 0x036344ULL: return fde_sub_036344(a0, a1, a2);
        case 0x03634cULL: return fde_sub_03634c(a0, a1, a2);
        case 0x03637cULL: return fde_sub_03637c(a0, a1, a2);
        case 0x036390ULL: return fde_sub_036390(a0, a1, a2);
        case 0x0363a0ULL: return fde_sub_0363a0(a0, a1, a2);
        case 0x0363dcULL: return fde_sub_0363dc(a0, a1, a2);
        case 0x0363e0ULL: return fde_sub_0363e0(a0, a1, a2);
        case 0x0363fcULL: return fde_sub_0363fc(a0, a1, a2);
        case 0x036400ULL: return fde_sub_036400(a0, a1, a2);
        case 0x036428ULL: return fde_sub_036428(a0, a1, a2);
        case 0x036ca0ULL: return fde_sub_036ca0(a0, a1, a2);
        case 0x036d60ULL: return fde_sub_036d60(a0, a1, a2);
        case 0x0371ccULL: return fde_sub_0371cc(a0, a1, a2);
        case 0x03733cULL: return fde_sub_03733c(a0, a1, a2);
        case 0x03734cULL: return fde_sub_03734c(a0, a1, a2);
        case 0x03735cULL: return fde_sub_03735c(a0, a1, a2);
        case 0x03736cULL: return fde_sub_03736c(a0, a1, a2);
        case 0x03737cULL: return fde_sub_03737c(a0, a1, a2);
        case 0x03738cULL: return fde_sub_03738c(a0, a1, a2);
        case 0x03739cULL: return fde_sub_03739c(a0, a1, a2);
        case 0x0373acULL: return fde_sub_0373ac(a0, a1, a2);
        case 0x0373bcULL: return fde_sub_0373bc(a0, a1, a2);
        case 0x0373ccULL: return fde_sub_0373cc(a0, a1, a2);
        case 0x0373dcULL: return fde_sub_0373dc(a0, a1, a2);
        case 0x0373ecULL: return fde_sub_0373ec(a0, a1, a2);
        case 0x0373fcULL: return fde_sub_0373fc(a0, a1, a2);
        case 0x03740cULL: return fde_sub_03740c(a0, a1, a2);
        case 0x03741cULL: return fde_sub_03741c(a0, a1, a2);
        case 0x03742cULL: return fde_sub_03742c(a0, a1, a2);
        case 0x03743cULL: return fde_sub_03743c(a0, a1, a2);
        case 0x03744cULL: return fde_sub_03744c(a0, a1, a2);
        case 0x03745cULL: return fde_sub_03745c(a0, a1, a2);
        case 0x03746cULL: return fde_sub_03746c(a0, a1, a2);
        case 0x03747cULL: return fde_sub_03747c(a0, a1, a2);
        case 0x03748cULL: return fde_sub_03748c(a0, a1, a2);
        case 0x03749cULL: return fde_sub_03749c(a0, a1, a2);
        case 0x0374acULL: return fde_sub_0374ac(a0, a1, a2);
        case 0x037fa0ULL: return fde_sub_037fa0(a0, a1, a2);
        case 0x037fa8ULL: return fde_sub_037fa8(a0, a1, a2);
        case 0x037fd8ULL: return fde_sub_037fd8(a0, a1, a2);
        case 0x037fecULL: return fde_sub_037fec(a0, a1, a2);
        case 0x037ffcULL: return fde_sub_037ffc(a0, a1, a2);
        case 0x038038ULL: return fde_sub_038038(a0, a1, a2);
        case 0x03803cULL: return fde_sub_03803c(a0, a1, a2);
        case 0x038058ULL: return fde_sub_038058(a0, a1, a2);
        case 0x03805cULL: return fde_sub_03805c(a0, a1, a2);
        case 0x038084ULL: return fde_sub_038084(a0, a1, a2);
        case 0x0388e0ULL: return fde_sub_0388e0(a0, a1, a2);
        case 0x038994ULL: return fde_sub_038994(a0, a1, a2);
        case 0x038dfcULL: return fde_sub_038dfc(a0, a1, a2);
        case 0x038f68ULL: return fde_sub_038f68(a0, a1, a2);
        case 0x038f78ULL: return fde_sub_038f78(a0, a1, a2);
        case 0x038f88ULL: return fde_sub_038f88(a0, a1, a2);
        case 0x038f98ULL: return fde_sub_038f98(a0, a1, a2);
        case 0x038fa8ULL: return fde_sub_038fa8(a0, a1, a2);
        case 0x038fb8ULL: return fde_sub_038fb8(a0, a1, a2);
        case 0x038fc8ULL: return fde_sub_038fc8(a0, a1, a2);
        case 0x038fd8ULL: return fde_sub_038fd8(a0, a1, a2);
        case 0x038fe8ULL: return fde_sub_038fe8(a0, a1, a2);
        case 0x038ff8ULL: return fde_sub_038ff8(a0, a1, a2);
        case 0x039008ULL: return fde_sub_039008(a0, a1, a2);
        case 0x039018ULL: return fde_sub_039018(a0, a1, a2);
        case 0x039028ULL: return fde_sub_039028(a0, a1, a2);
        case 0x039038ULL: return fde_sub_039038(a0, a1, a2);
        case 0x039048ULL: return fde_sub_039048(a0, a1, a2);
        case 0x039058ULL: return fde_sub_039058(a0, a1, a2);
        case 0x039068ULL: return fde_sub_039068(a0, a1, a2);
        case 0x039078ULL: return fde_sub_039078(a0, a1, a2);
        case 0x039088ULL: return fde_sub_039088(a0, a1, a2);
        case 0x039098ULL: return fde_sub_039098(a0, a1, a2);
        case 0x0390a8ULL: return fde_sub_0390a8(a0, a1, a2);
        case 0x0390b8ULL: return fde_sub_0390b8(a0, a1, a2);
        case 0x0390c8ULL: return fde_sub_0390c8(a0, a1, a2);
        case 0x0390d8ULL: return fde_sub_0390d8(a0, a1, a2);
        case 0x039e84ULL: return fde_sub_039e84(a0, a1, a2);
        case 0x039e8cULL: return fde_sub_039e8c(a0, a1, a2);
        case 0x039ebcULL: return fde_sub_039ebc(a0, a1, a2);
        case 0x039ed0ULL: return fde_sub_039ed0(a0, a1, a2);
        case 0x039ee0ULL: return fde_sub_039ee0(a0, a1, a2);
        case 0x039f1cULL: return fde_sub_039f1c(a0, a1, a2);
        case 0x039f20ULL: return fde_sub_039f20(a0, a1, a2);
        case 0x039f3cULL: return fde_sub_039f3c(a0, a1, a2);
        case 0x039f40ULL: return fde_sub_039f40(a0, a1, a2);
        case 0x039f68ULL: return fde_sub_039f68(a0, a1, a2);
        case 0x03a7a8ULL: return fde_sub_03a7a8(a0, a1, a2);
        case 0x03adccULL: return fde_sub_03adcc(a0, a1, a2);
        case 0x03addcULL: return fde_sub_03addc(a0, a1, a2);
        case 0x03adecULL: return fde_sub_03adec(a0, a1, a2);
        case 0x03adfcULL: return fde_sub_03adfc(a0, a1, a2);
        case 0x03ae0cULL: return fde_sub_03ae0c(a0, a1, a2);
        case 0x03ae1cULL: return fde_sub_03ae1c(a0, a1, a2);
        case 0x03ae2cULL: return fde_sub_03ae2c(a0, a1, a2);
        case 0x03ae3cULL: return fde_sub_03ae3c(a0, a1, a2);
        case 0x03ae4cULL: return fde_sub_03ae4c(a0, a1, a2);
        case 0x03ae5cULL: return fde_sub_03ae5c(a0, a1, a2);
        case 0x03ae6cULL: return fde_sub_03ae6c(a0, a1, a2);
        case 0x03ae7cULL: return fde_sub_03ae7c(a0, a1, a2);
        case 0x03ae8cULL: return fde_sub_03ae8c(a0, a1, a2);
        case 0x03ae9cULL: return fde_sub_03ae9c(a0, a1, a2);
        case 0x03aeacULL: return fde_sub_03aeac(a0, a1, a2);
        case 0x03aebcULL: return fde_sub_03aebc(a0, a1, a2);
        case 0x03aeccULL: return fde_sub_03aecc(a0, a1, a2);
        case 0x03aedcULL: return fde_sub_03aedc(a0, a1, a2);
        case 0x03aeecULL: return fde_sub_03aeec(a0, a1, a2);
        case 0x03aefcULL: return fde_sub_03aefc(a0, a1, a2);
        case 0x03af0cULL: return fde_sub_03af0c(a0, a1, a2);
        case 0x03af1cULL: return fde_sub_03af1c(a0, a1, a2);
        case 0x03af2cULL: return fde_sub_03af2c(a0, a1, a2);
        case 0x03af3cULL: return fde_sub_03af3c(a0, a1, a2);
        case 0x03bcacULL: return fde_sub_03bcac(a0, a1, a2);
        case 0x03bcb4ULL: return fde_sub_03bcb4(a0, a1, a2);
        case 0x03bce4ULL: return fde_sub_03bce4(a0, a1, a2);
        case 0x03bcf8ULL: return fde_sub_03bcf8(a0, a1, a2);
        case 0x03bd08ULL: return fde_sub_03bd08(a0, a1, a2);
        case 0x03bd44ULL: return fde_sub_03bd44(a0, a1, a2);
        case 0x03bd48ULL: return fde_sub_03bd48(a0, a1, a2);
        case 0x03bd64ULL: return fde_sub_03bd64(a0, a1, a2);
        case 0x03bd68ULL: return fde_sub_03bd68(a0, a1, a2);
        case 0x03bd90ULL: return fde_sub_03bd90(a0, a1, a2);
        case 0x03c564ULL: return fde_sub_03c564(a0, a1, a2);
        case 0x03c624ULL: return fde_sub_03c624(a0, a1, a2);
        case 0x03ca84ULL: return fde_sub_03ca84(a0, a1, a2);
        case 0x03cbf4ULL: return fde_sub_03cbf4(a0, a1, a2);
        case 0x03cc04ULL: return fde_sub_03cc04(a0, a1, a2);
        case 0x03cc14ULL: return fde_sub_03cc14(a0, a1, a2);
        case 0x03cc24ULL: return fde_sub_03cc24(a0, a1, a2);
        case 0x03cc34ULL: return fde_sub_03cc34(a0, a1, a2);
        case 0x03cc44ULL: return fde_sub_03cc44(a0, a1, a2);
        case 0x03cc54ULL: return fde_sub_03cc54(a0, a1, a2);
        case 0x03cc64ULL: return fde_sub_03cc64(a0, a1, a2);
        case 0x03cc74ULL: return fde_sub_03cc74(a0, a1, a2);
        case 0x03cc84ULL: return fde_sub_03cc84(a0, a1, a2);
        case 0x03cc94ULL: return fde_sub_03cc94(a0, a1, a2);
        case 0x03cca4ULL: return fde_sub_03cca4(a0, a1, a2);
        case 0x03ccb4ULL: return fde_sub_03ccb4(a0, a1, a2);
        case 0x03ccc4ULL: return fde_sub_03ccc4(a0, a1, a2);
        case 0x03ccd4ULL: return fde_sub_03ccd4(a0, a1, a2);
        case 0x03cce4ULL: return fde_sub_03cce4(a0, a1, a2);
        case 0x03ccf4ULL: return fde_sub_03ccf4(a0, a1, a2);
        case 0x03cd04ULL: return fde_sub_03cd04(a0, a1, a2);
        case 0x03cd14ULL: return fde_sub_03cd14(a0, a1, a2);
        case 0x03cd24ULL: return fde_sub_03cd24(a0, a1, a2);
        case 0x03cd34ULL: return fde_sub_03cd34(a0, a1, a2);
        case 0x03cd44ULL: return fde_sub_03cd44(a0, a1, a2);
        case 0x03cd54ULL: return fde_sub_03cd54(a0, a1, a2);
        case 0x03cd64ULL: return fde_sub_03cd64(a0, a1, a2);
        case 0x03d85cULL: return fde_sub_03d85c(a0, a1, a2);
        case 0x03d864ULL: return fde_sub_03d864(a0, a1, a2);
        case 0x03d894ULL: return fde_sub_03d894(a0, a1, a2);
        case 0x03d8a8ULL: return fde_sub_03d8a8(a0, a1, a2);
        case 0x03d8b8ULL: return fde_sub_03d8b8(a0, a1, a2);
        case 0x03d8f4ULL: return fde_sub_03d8f4(a0, a1, a2);
        case 0x03d8f8ULL: return fde_sub_03d8f8(a0, a1, a2);
        case 0x03d914ULL: return fde_sub_03d914(a0, a1, a2);
        case 0x03d918ULL: return fde_sub_03d918(a0, a1, a2);
        case 0x03d940ULL: return fde_sub_03d940(a0, a1, a2);
        case 0x03e1c0ULL: return fde_sub_03e1c0(a0, a1, a2);
        case 0x03e284ULL: return fde_sub_03e284(a0, a1, a2);
        case 0x03e6e4ULL: return fde_sub_03e6e4(a0, a1, a2);
        case 0x03e854ULL: return fde_sub_03e854(a0, a1, a2);
        case 0x03e864ULL: return fde_sub_03e864(a0, a1, a2);
        case 0x03e874ULL: return fde_sub_03e874(a0, a1, a2);
        case 0x03e884ULL: return fde_sub_03e884(a0, a1, a2);
        case 0x03e894ULL: return fde_sub_03e894(a0, a1, a2);
        case 0x03e8a4ULL: return fde_sub_03e8a4(a0, a1, a2);
        case 0x03e8b4ULL: return fde_sub_03e8b4(a0, a1, a2);
        case 0x03e8c4ULL: return fde_sub_03e8c4(a0, a1, a2);
        case 0x03e8d4ULL: return fde_sub_03e8d4(a0, a1, a2);
        case 0x03e8e4ULL: return fde_sub_03e8e4(a0, a1, a2);
        case 0x03e8f4ULL: return fde_sub_03e8f4(a0, a1, a2);
        case 0x03e904ULL: return fde_sub_03e904(a0, a1, a2);
        case 0x03e914ULL: return fde_sub_03e914(a0, a1, a2);
        case 0x03e924ULL: return fde_sub_03e924(a0, a1, a2);
        case 0x03e934ULL: return fde_sub_03e934(a0, a1, a2);
        case 0x03e944ULL: return fde_sub_03e944(a0, a1, a2);
        case 0x03e954ULL: return fde_sub_03e954(a0, a1, a2);
        case 0x03e964ULL: return fde_sub_03e964(a0, a1, a2);
        case 0x03e974ULL: return fde_sub_03e974(a0, a1, a2);
        case 0x03e984ULL: return fde_sub_03e984(a0, a1, a2);
        case 0x03e994ULL: return fde_sub_03e994(a0, a1, a2);
        case 0x03e9a4ULL: return fde_sub_03e9a4(a0, a1, a2);
        case 0x03e9b4ULL: return fde_sub_03e9b4(a0, a1, a2);
        case 0x03e9c4ULL: return fde_sub_03e9c4(a0, a1, a2);
        case 0x03f4ccULL: return fde_sub_03f4cc(a0, a1, a2);
        case 0x03f4d4ULL: return fde_sub_03f4d4(a0, a1, a2);
        case 0x03f504ULL: return fde_sub_03f504(a0, a1, a2);
        case 0x03f518ULL: return fde_sub_03f518(a0, a1, a2);
        case 0x03f528ULL: return fde_sub_03f528(a0, a1, a2);
        case 0x03f564ULL: return fde_sub_03f564(a0, a1, a2);
        case 0x03f568ULL: return fde_sub_03f568(a0, a1, a2);
        case 0x03f584ULL: return fde_sub_03f584(a0, a1, a2);
        case 0x03f588ULL: return fde_sub_03f588(a0, a1, a2);
        case 0x03f5b0ULL: return fde_sub_03f5b0(a0, a1, a2);
        default: return 0ULL;
    }
}

} // namespace rex
} // namespace bytedance
