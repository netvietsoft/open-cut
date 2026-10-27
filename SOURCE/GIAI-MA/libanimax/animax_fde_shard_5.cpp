// ============================================================================
// File: animax_fde_shard_5.cpp
// Target 108 / 169: libanimax.so (657,720 bytes)
// EN: Clean-room C++17 AArch64 FDE Shard 5/5 covering FDEs [3172..3964]
//     (PC range 0x090578 .. 0x09315c).
// VI: Phân mảnh FDE AArch64 C++17 5/5 bao phủ FDE [3172..3964]
//     (Dải địa chỉ PC 0x090578 .. 0x09315c).
// ============================================================================
#include "animax_player_core.h"

namespace lynx {
namespace animax {

// FDE #3172 | PC: 0x090578..0x090584 (12 B) | Symbol: sub_090578
// EN: AArch64 prologue [str xzr, [x21, #8]!; str x8, [x0]; ret] | VI: Khởi đầu hàm AArch64 [str xzr, [x21, #8]!; str x8, [x0]; ret]
uint64_t fde_sub_090578(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000008ULL) << 32) | 0xF8008EBFULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090578ULL;
}

// FDE #3173 | PC: 0x090584..0x090590 (12 B) | Symbol: sub_090584
// EN: AArch64 prologue [fmov s1, wzr; cmp w8, #0; ret] | VI: Khởi đầu hàm AArch64 [fmov s1, wzr; cmp w8, #0; ret]
uint64_t fde_sub_090584(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100011FULL) << 32) | 0x1E2703E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090584ULL;
}

// FDE #3174 | PC: 0x090590..0x090598 (8 B) | Symbol: sub_090590
// EN: AArch64 prologue [mov w0, #0x48; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov w0, #0x48; b #0x93320]
uint64_t fde_sub_090590(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000B63ULL) << 32) | 0x52800900ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090590ULL;
}

// FDE #3175 | PC: 0x090598..0x0905b4 (28 B) | Symbol: sub_090598
// EN: AArch64 prologue [mov x22, x0; str x8, [x0]; stur q0, [x0, #8]; add x0, x0, #0x18] | VI: Khởi đầu hàm AArch64 [mov x22, x0; str x8, [x0]; stur q0, [x0, #8]; add x0, x0, #0x18]
uint64_t fde_sub_090598(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000008ULL) << 32) | 0xAA0003F6ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090598ULL;
}

// FDE #3176 | PC: 0x0905b4..0x0905c8 (20 B) | Symbol: sub_0905b4
// EN: AArch64 prologue [mov x22, x0; stp x9, x8, [x0], #0x10; mov x1, x20; str xzr, [sp, #0x58]] | VI: Khởi đầu hàm AArch64 [mov x22, x0; stp x9, x8, [x0], #0x10; mov x1, x20; str xzr, [sp, #0x58]]
uint64_t fde_sub_0905b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA8812009ULL) << 32) | 0xAA0003F6ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0905B4ULL;
}

// FDE #3177 | PC: 0x0905c8..0x0905d4 (12 B) | Symbol: sub_0905c8
// EN: AArch64 prologue [add x1, sp, #0xb0; mov x0, x19; b #0x75038] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0xb0; mov x0, x19; b #0x75038]
uint64_t fde_sub_0905c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9102C3E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0905C8ULL;
}

// FDE #3178 | PC: 0x0905d4..0x0905e0 (12 B) | Symbol: sub_0905d4
// EN: AArch64 prologue [add x1, sp, #0x20; mov x2, sp; b #0x75b88] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0x20; mov x2, sp; b #0x75b88]
uint64_t fde_sub_0905d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003E2ULL) << 32) | 0x910083E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0905D4ULL;
}

// FDE #3179 | PC: 0x0905e0..0x0905ec (12 B) | Symbol: sub_0905e0
// EN: AArch64 prologue [ldr x8, [sp]; str xzr, [sp]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [sp]; str xzr, [sp]; ret]
uint64_t fde_sub_0905e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90003FFULL) << 32) | 0xF94003E8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0905E0ULL;
}

// FDE #3180 | PC: 0x0905ec..0x090600 (20 B) | Symbol: sub_0905ec
// EN: AArch64 prologue [add x0, sp, #0x10; mov x1, sp; stp s0, s1, [sp]; stp s2, s3, [sp, #8]] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x10; mov x1, sp; stp s0, s1, [sp]; stp s2, s3, [sp, #8]]
uint64_t fde_sub_0905ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003E1ULL) << 32) | 0x910043E0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0905ECULL;
}

// FDE #3181 | PC: 0x090600..0x09060c (12 B) | Symbol: sub_090600
// EN: AArch64 prologue [mov x19, x1; mov x20, x0; b #0x93c80] | VI: Khởi đầu hàm AArch64 [mov x19, x1; mov x20, x0; b #0x93c80]
uint64_t fde_sub_090600(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F4ULL) << 32) | 0xAA0103F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090600ULL;
}

// FDE #3182 | PC: 0x09060c..0x090618 (12 B) | Symbol: sub_09060c
// EN: AArch64 prologue [add x1, x8, #0x28; ldr x20, [sp], #0x20; b #0x48588] | VI: Khởi đầu hàm AArch64 [add x1, x8, #0x28; ldr x20, [sp], #0x20; b #0x48588]
uint64_t fde_sub_09060c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF84207F4ULL) << 32) | 0x9100A101ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09060CULL;
}

// FDE #3183 | PC: 0x090618..0x090624 (12 B) | Symbol: sub_090618
// EN: AArch64 prologue [add x1, x8, #0x28; ldr x20, [sp], #0x20; b #0x5c240] | VI: Khởi đầu hàm AArch64 [add x1, x8, #0x28; ldr x20, [sp], #0x20; b #0x5c240]
uint64_t fde_sub_090618(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF84207F4ULL) << 32) | 0x9100A101ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090618ULL;
}

// FDE #3184 | PC: 0x090624..0x090630 (12 B) | Symbol: sub_090624
// EN: AArch64 prologue [mov x2, x0; mov x0, x20; b #0x7cc5c] | VI: Khởi đầu hàm AArch64 [mov x2, x0; mov x0, x20; b #0x7cc5c]
uint64_t fde_sub_090624(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0xAA0003E2ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090624ULL;
}

// FDE #3185 | PC: 0x090630..0x090644 (20 B) | Symbol: sub_090630
// EN: AArch64 prologue [ldr x0, [x19, #8]; add x19, x22, #8; add x1, sp, #0x28; mov x2, x19] | VI: Khởi đầu hàm AArch64 [ldr x0, [x19, #8]; add x19, x22, #8; add x1, sp, #0x28; mov x2, x19]
uint64_t fde_sub_090630(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910022D3ULL) << 32) | 0xF9400660ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090630ULL;
}

// FDE #3186 | PC: 0x090644..0x090660 (28 B) | Symbol: sub_090644
// EN: AArch64 prologue [ldr x9, [x8]; fcvt d0, s0; fdiv d0, d0, d8; cmp w10, #0] | VI: Khởi đầu hàm AArch64 [ldr x9, [x8]; fcvt d0, s0; fdiv d0, d0, d8; cmp w10, #0]
uint64_t fde_sub_090644(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E22C000ULL) << 32) | 0xF9400109ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090644ULL;
}

// FDE #3187 | PC: 0x090660..0x090668 (8 B) | Symbol: sub_090660
// EN: AArch64 prologue [add x0, sp, #0x28; b #0x77958] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x28; b #0x77958]
uint64_t fde_sub_090660(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF9CBDULL) << 32) | 0x9100A3E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090660ULL;
}

// FDE #3188 | PC: 0x090668..0x090674 (12 B) | Symbol: sub_090668
// EN: AArch64 prologue [mov w0, #0x20; str w19, [sp, #0x20]; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov w0, #0x20; str w19, [sp, #0x20]; b #0x93320]
uint64_t fde_sub_090668(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB90023F3ULL) << 32) | 0x52800400ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090668ULL;
}

// FDE #3189 | PC: 0x090674..0x09067c (8 B) | Symbol: sub_090674
// EN: AArch64 prologue [mov x1, x21; b #0x4b758] | VI: Khởi đầu hàm AArch64 [mov x1, x21; b #0x4b758]
uint64_t fde_sub_090674(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEEC38ULL) << 32) | 0xAA1503E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090674ULL;
}

// FDE #3190 | PC: 0x09067c..0x090684 (8 B) | Symbol: sub_09067c
// EN: AArch64 prologue [mov x1, x21; b #0x93910] | VI: Khởi đầu hàm AArch64 [mov x1, x21; b #0x93910]
uint64_t fde_sub_09067c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000CA4ULL) << 32) | 0xAA1503E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09067CULL;
}

// FDE #3191 | PC: 0x090684..0x090690 (12 B) | Symbol: sub_090684
// EN: AArch64 prologue [mov x1, x21; mov x2, x19; ret] | VI: Khởi đầu hàm AArch64 [mov x1, x21; mov x2, x19; ret]
uint64_t fde_sub_090684(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E2ULL) << 32) | 0xAA1503E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090684ULL;
}

// FDE #3192 | PC: 0x090690..0x0906ac (28 B) | Symbol: sub_090690
// EN: AArch64 prologue [ldr x11, [sp]; add x9, x0, x27, lsl #3; mov x10, x9; add x8, x0, x28, lsl #3] | VI: Khởi đầu hàm AArch64 [ldr x11, [sp]; add x9, x0, x27, lsl #3; mov x10, x9; add x8, x0, x28, lsl #3]
uint64_t fde_sub_090690(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8B1B0C09ULL) << 32) | 0xF94003EBULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090690ULL;
}

// FDE #3193 | PC: 0x0906ac..0x0906c0 (20 B) | Symbol: sub_0906ac
// EN: AArch64 prologue [adrp x1, #0x20000; mov x19, x0; add x1, x1, #0xbd6; mov x0, sp] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x20000; mov x19, x0; add x1, x1, #0xbd6; mov x0, sp]
uint64_t fde_sub_0906ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0x90FFFC81ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0906ACULL;
}

// FDE #3194 | PC: 0x0906c0..0x0906d4 (20 B) | Symbol: sub_0906c0
// EN: AArch64 prologue [add x22, x19, #0x30; add x1, x19, #0x18; mov x0, x19; mov x2, x22] | VI: Khởi đầu hàm AArch64 [add x22, x19, #0x30; add x1, x19, #0x18; mov x0, x19; mov x2, x22]
uint64_t fde_sub_0906c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91006261ULL) << 32) | 0x9100C276ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0906C0ULL;
}

// FDE #3195 | PC: 0x0906d4..0x0906dc (8 B) | Symbol: sub_0906d4
// EN: AArch64 prologue [add sp, sp, #0x180; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0x180; ret]
uint64_t fde_sub_0906d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910603FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0906D4ULL;
}

// FDE #3196 | PC: 0x0906dc..0x0906e8 (12 B) | Symbol: sub_0906dc
// EN: AArch64 prologue [adrp x1, #0x1f000; add x1, x1, #0x6f5; b #0x4696c] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x1f000; add x1, x1, #0x6f5; b #0x4696c]
uint64_t fde_sub_0906dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911BD421ULL) << 32) | 0xF0FFFC61ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0906DCULL;
}

// FDE #3197 | PC: 0x0906e8..0x090704 (28 B) | Symbol: sub_0906e8
// EN: AArch64 prologue [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; str x8, [sp, #0x38]; ldr x19, [x0, #0x98]] | VI: Khởi đầu hàm AArch64 [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; str x8, [sp, #0x38]; ldr x19, [x0, #0x98]]
uint64_t fde_sub_0906e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016A8ULL) << 32) | 0xD53BD055ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0906E8ULL;
}

// FDE #3198 | PC: 0x090704..0x090720 (28 B) | Symbol: sub_090704
// EN: AArch64 prologue [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; mov x20, x0; add x0, sp, #0x28] | VI: Khởi đầu hàm AArch64 [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; mov x20, x0; add x0, sp, #0x28]
uint64_t fde_sub_090704(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016A8ULL) << 32) | 0xD53BD055ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090704ULL;
}

// FDE #3199 | PC: 0x090720..0x090734 (20 B) | Symbol: sub_090720
// EN: AArch64 prologue [stur q0, [x19, #0x78]; stur q0, [x19, #0x68]; stur q0, [x19, #0x58]; stur q0, [x19, #0x48]] | VI: Khởi đầu hàm AArch64 [stur q0, [x19, #0x78]; stur q0, [x19, #0x68]; stur q0, [x19, #0x58]; stur q0, [x19, #0x48]]
uint64_t fde_sub_090720(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3C868260ULL) << 32) | 0x3C878260ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090720ULL;
}

// FDE #3200 | PC: 0x090734..0x090740 (12 B) | Symbol: sub_090734
// EN: AArch64 prologue [add x0, sp, #0x1f8; add x1, sp, #0x188; b #0x7620c] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x1f8; add x1, sp, #0x188; b #0x7620c]
uint64_t fde_sub_090734(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910623E1ULL) << 32) | 0x9107E3E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090734ULL;
}

// FDE #3201 | PC: 0x090740..0x090754 (20 B) | Symbol: sub_090740
// EN: AArch64 prologue [add x8, x21, #0x18; add x1, sp, #8; mov x0, x19; str x8, [sp, #0x18]] | VI: Khởi đầu hàm AArch64 [add x8, x21, #0x18; add x1, sp, #8; mov x0, x19; str x8, [sp, #0x18]]
uint64_t fde_sub_090740(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910023E1ULL) << 32) | 0x910062A8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090740ULL;
}

// FDE #3202 | PC: 0x090754..0x090760 (12 B) | Symbol: sub_090754
// EN: AArch64 prologue [stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret]
uint64_t fde_sub_090754(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900091FULL) << 32) | 0xA9007D1FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090754ULL;
}

// FDE #3203 | PC: 0x090760..0x090768 (8 B) | Symbol: sub_090760
// EN: AArch64 prologue [add x0, sp, #0x118; b #0x78b30] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x118; b #0x78b30]
uint64_t fde_sub_090760(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFA0F3ULL) << 32) | 0x910463E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090760ULL;
}

// FDE #3204 | PC: 0x090768..0x090774 (12 B) | Symbol: sub_090768
// EN: AArch64 prologue [add x0, sp, #0x118; add x1, sp, #0x48; b #0x78aec] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x118; add x1, sp, #0x48; b #0x78aec]
uint64_t fde_sub_090768(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910123E1ULL) << 32) | 0x910463E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090768ULL;
}

// FDE #3205 | PC: 0x090774..0x09077c (8 B) | Symbol: sub_090774
// EN: AArch64 prologue [add sp, sp, #0x130; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0x130; ret]
uint64_t fde_sub_090774(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x9104C3FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090774ULL;
}

// FDE #3206 | PC: 0x09077c..0x090790 (20 B) | Symbol: sub_09077c
// EN: AArch64 prologue [add x9, sp, #0x60; mov w8, #3; add x0, x9, #8; str w8, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [add x9, sp, #0x60; mov w8, #3; add x0, x9, #8; str w8, [sp, #0x60]]
uint64_t fde_sub_09077c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800068ULL) << 32) | 0x910183E9ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09077CULL;
}

// FDE #3207 | PC: 0x090790..0x09079c (12 B) | Symbol: sub_090790
// EN: AArch64 prologue [add x1, sp, #0x30; add x2, sp, #8; b #0x75b88] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0x30; add x2, sp, #8; b #0x75b88]
uint64_t fde_sub_090790(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910023E2ULL) << 32) | 0x9100C3E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090790ULL;
}

// FDE #3208 | PC: 0x09079c..0x0907b0 (20 B) | Symbol: sub_09079c
// EN: AArch64 prologue [ldr x0, [x21]; fmul s0, s0, s8; add x1, sp, #0x30; add x21, sp, #0x30] | VI: Khởi đầu hàm AArch64 [ldr x0, [x21]; fmul s0, s0, s8; add x1, sp, #0x30; add x21, sp, #0x30]
uint64_t fde_sub_09079c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E280800ULL) << 32) | 0xF94002A0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09079CULL;
}

// FDE #3209 | PC: 0x0907b0..0x0907bc (12 B) | Symbol: sub_0907b0
// EN: AArch64 prologue [ldr x0, [x8]; ldr x1, [x9]; b #0x8bb6c] | VI: Khởi đầu hàm AArch64 [ldr x0, [x8]; ldr x1, [x9]; b #0x8bb6c]
uint64_t fde_sub_0907b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400121ULL) << 32) | 0xF9400100ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0907B0ULL;
}

// FDE #3210 | PC: 0x0907bc..0x0907c4 (8 B) | Symbol: sub_0907bc
// EN: AArch64 prologue [ldr x0, [x0, #8]; b #0x514b0] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #8]; b #0x514b0]
uint64_t fde_sub_0907bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF033CULL) << 32) | 0xF9400400ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0907BCULL;
}

// FDE #3211 | PC: 0x0907c4..0x0907cc (8 B) | Symbol: sub_0907c4
// EN: AArch64 prologue [mov x0, x28; b #0x44830] | VI: Khởi đầu hàm AArch64 [mov x0, x28; b #0x44830]
uint64_t fde_sub_0907c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED01AULL) << 32) | 0xAA1C03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0907C4ULL;
}

// FDE #3212 | PC: 0x0907cc..0x0907d8 (12 B) | Symbol: sub_0907cc
// EN: AArch64 prologue [mov x0, x20; mov x2, x19; b #0x5cde8] | VI: Khởi đầu hàm AArch64 [mov x0, x20; mov x2, x19; b #0x5cde8]
uint64_t fde_sub_0907cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E2ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0907CCULL;
}

// FDE #3213 | PC: 0x0907d8..0x0907e0 (8 B) | Symbol: sub_0907d8
// EN: AArch64 prologue [mov x0, x20; b #0x93e00] | VI: Khởi đầu hàm AArch64 [mov x0, x20; b #0x93e00]
uint64_t fde_sub_0907d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000D89ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0907D8ULL;
}

// FDE #3214 | PC: 0x0907e0..0x0907ec (12 B) | Symbol: sub_0907e0
// EN: AArch64 prologue [add x0, sp, #0x18; mov x1, x20; ret] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x18; mov x1, x20; ret]
uint64_t fde_sub_0907e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E1ULL) << 32) | 0x910063E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0907E0ULL;
}

// FDE #3215 | PC: 0x0907ec..0x0907f8 (12 B) | Symbol: sub_0907ec
// EN: AArch64 prologue [add x4, x4, #0x67; mov w2, #1; ret] | VI: Khởi đầu hàm AArch64 [add x4, x4, #0x67; mov w2, #1; ret]
uint64_t fde_sub_0907ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800022ULL) << 32) | 0x91019C84ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0907ECULL;
}

// FDE #3216 | PC: 0x0907f8..0x09080c (20 B) | Symbol: sub_0907f8
// EN: AArch64 prologue [ldr s8, [x20, #0x18]; ldr x22, [x20, #0x20]; mov w0, #0x10; str xzr, [x20, #0x20]] | VI: Khởi đầu hàm AArch64 [ldr s8, [x20, #0x18]; ldr x22, [x20, #0x20]; mov w0, #0x10; str xzr, [x20, #0x20]]
uint64_t fde_sub_0907f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401296ULL) << 32) | 0xBD401A88ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0907F8ULL;
}

// FDE #3217 | PC: 0x09080c..0x090820 (20 B) | Symbol: sub_09080c
// EN: AArch64 prologue [add x9, sp, #0x80; mov w8, #3; add x0, x9, #8; str w8, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [add x9, sp, #0x80; mov w8, #3; add x0, x9, #8; str w8, [sp, #0x80]]
uint64_t fde_sub_09080c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800068ULL) << 32) | 0x910203E9ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09080CULL;
}

// FDE #3218 | PC: 0x090820..0x090828 (8 B) | Symbol: sub_090820
// EN: AArch64 prologue [mov x2, x21; b #0x6ba44] | VI: Khởi đầu hàm AArch64 [mov x2, x21; b #0x6ba44]
uint64_t fde_sub_090820(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF6C88ULL) << 32) | 0xAA1503E2ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090820ULL;
}

// FDE #3219 | PC: 0x090828..0x090834 (12 B) | Symbol: sub_090828
// EN: AArch64 prologue [mov x1, x19; mov x20, x0; b #0x5b1f4] | VI: Khởi đầu hàm AArch64 [mov x1, x19; mov x20, x0; b #0x5b1f4]
uint64_t fde_sub_090828(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F4ULL) << 32) | 0xAA1303E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090828ULL;
}

// FDE #3220 | PC: 0x090834..0x090848 (20 B) | Symbol: sub_090834
// EN: AArch64 prologue [ldr x8, [x19, #0x30]; mov v0.16b, v11.16b; mov v1.16b, v12.16b; ldr x0, [x8, #8]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x19, #0x30]; mov v0.16b, v11.16b; mov v1.16b, v12.16b; ldr x0, [x8, #8]]
uint64_t fde_sub_090834(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4EAB1D60ULL) << 32) | 0xF9401A68ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090834ULL;
}

// FDE #3221 | PC: 0x090848..0x090850 (8 B) | Symbol: sub_090848
// EN: AArch64 prologue [lsl x0, x19, #3; b #0x93320] | VI: Khởi đầu hàm AArch64 [lsl x0, x19, #3; b #0x93320]
uint64_t fde_sub_090848(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000AB5ULL) << 32) | 0xD37DF260ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090848ULL;
}

// FDE #3222 | PC: 0x090850..0x090858 (8 B) | Symbol: sub_090850
// EN: AArch64 prologue [mov x0, x22; b #0x93680] | VI: Khởi đầu hàm AArch64 [mov x0, x22; b #0x93680]
uint64_t fde_sub_090850(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000B8BULL) << 32) | 0xAA1603E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090850ULL;
}

// FDE #3223 | PC: 0x090858..0x090864 (12 B) | Symbol: sub_090858
// EN: AArch64 prologue [mov x0, x22; mov x1, x23; b #0x67c50] | VI: Khởi đầu hàm AArch64 [mov x0, x22; mov x1, x23; b #0x67c50]
uint64_t fde_sub_090858(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1703E1ULL) << 32) | 0xAA1603E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090858ULL;
}

// FDE #3224 | PC: 0x090864..0x090870 (12 B) | Symbol: sub_090864
// EN: AArch64 prologue [mov x0, x22; mov x1, x24; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x22; mov x1, x24; ret]
uint64_t fde_sub_090864(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1803E1ULL) << 32) | 0xAA1603E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090864ULL;
}

// FDE #3225 | PC: 0x090870..0x09087c (12 B) | Symbol: sub_090870
// EN: AArch64 prologue [mov x0, x22; mov x1, x20; b #0x94420] | VI: Khởi đầu hàm AArch64 [mov x0, x22; mov x1, x20; b #0x94420]
uint64_t fde_sub_090870(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E1ULL) << 32) | 0xAA1603E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090870ULL;
}

// FDE #3226 | PC: 0x09087c..0x090890 (20 B) | Symbol: sub_09087c
// EN: AArch64 prologue [ldr x21, [x20, #0x18]; add x0, sp, #0x30; mov x1, x20; add x22, sp, #0x30] | VI: Khởi đầu hàm AArch64 [ldr x21, [x20, #0x18]; add x0, sp, #0x30; mov x1, x20; add x22, sp, #0x30]
uint64_t fde_sub_09087c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9100C3E0ULL) << 32) | 0xF9400E95ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09087CULL;
}

// FDE #3227 | PC: 0x090890..0x0908ac (28 B) | Symbol: sub_090890
// EN: AArch64 prologue [stp x8, x22, [x0]; str x0, [sp, #8]; ldr x0, [x19, #8]; add x1, sp, #0x10] | VI: Khởi đầu hàm AArch64 [stp x8, x22, [x0]; str x0, [sp, #8]; ldr x0, [x19, #8]; add x1, sp, #0x10]
uint64_t fde_sub_090890(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90007E0ULL) << 32) | 0xA9005808ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090890ULL;
}

// FDE #3228 | PC: 0x0908ac..0x0908c8 (28 B) | Symbol: sub_0908ac
// EN: AArch64 prologue [ldur q0, [sp, #0x18]; mov x1, sp; mov x0, x20; stp xzr, xzr, [x22]] | VI: Khởi đầu hàm AArch64 [ldur q0, [sp, #0x18]; mov x1, sp; mov x0, x20; stp xzr, xzr, [x22]]
uint64_t fde_sub_0908ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003E1ULL) << 32) | 0x3CC183E0ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0908ACULL;
}

// FDE #3229 | PC: 0x0908c8..0x0908d4 (12 B) | Symbol: sub_0908c8
// EN: AArch64 prologue [ldr x20, [sp, #0x10]; ldp d9, d8, [sp], #0x30; ret] | VI: Khởi đầu hàm AArch64 [ldr x20, [sp, #0x10]; ldp d9, d8, [sp], #0x30; ret]
uint64_t fde_sub_0908c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6CC323E9ULL) << 32) | 0xF9400BF4ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0908C8ULL;
}

// FDE #3230 | PC: 0x0908d4..0x0908e8 (20 B) | Symbol: sub_0908d4
// EN: AArch64 prologue [stp xzr, xzr, [sp, #8]; str xzr, [sp]; ldp x0, x1, [x21, #0x30]; mov x2, sp] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [sp, #8]; str xzr, [sp]; ldp x0, x1, [x21, #0x30]; mov x2, sp]
uint64_t fde_sub_0908d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90003FFULL) << 32) | 0xA900FFFFULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0908D4ULL;
}

// FDE #3231 | PC: 0x0908e8..0x0908f4 (12 B) | Symbol: sub_0908e8
// EN: AArch64 prologue [cmp w8, #0; cset w1, ne; b #0x7c63c] | VI: Khởi đầu hàm AArch64 [cmp w8, #0; cset w1, ne; b #0x7c63c]
uint64_t fde_sub_0908e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1A9F07E1ULL) << 32) | 0x7100011FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0908E8ULL;
}

// FDE #3232 | PC: 0x0908f4..0x090910 (28 B) | Symbol: sub_0908f4
// EN: AArch64 prologue [cmp w8, #0; csel x8, x11, x10, eq; cmp w9, #0; ldr s0, [x1, x8]] | VI: Khởi đầu hàm AArch64 [cmp w8, #0; csel x8, x11, x10, eq; cmp w9, #0; ldr s0, [x1, x8]]
uint64_t fde_sub_0908f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9A8A0168ULL) << 32) | 0x7100011FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0908F4ULL;
}

// FDE #3233 | PC: 0x090910..0x09092c (28 B) | Symbol: sub_090910
// EN: AArch64 prologue [cmp w8, #0; mov w9, #0x10; mov w10, #0x20; csel x9, x10, x9, eq] | VI: Khởi đầu hàm AArch64 [cmp w8, #0; mov w9, #0x10; mov w10, #0x20; csel x9, x10, x9, eq]
uint64_t fde_sub_090910(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800209ULL) << 32) | 0x7100011FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090910ULL;
}

// FDE #3234 | PC: 0x09092c..0x090938 (12 B) | Symbol: sub_09092c
// EN: AArch64 prologue [sub x21, x21, #8; mov x0, x21; ret] | VI: Khởi đầu hàm AArch64 [sub x21, x21, #8; mov x0, x21; ret]
uint64_t fde_sub_09092c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E0ULL) << 32) | 0xD10022B5ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09092CULL;
}

// FDE #3235 | PC: 0x090938..0x09095c (36 B) | Symbol: sub_090938
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; ldr x0, [x19]; bl #0x89f20; ldr x0, [x19]] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; ldr x0, [x19]; bl #0x89f20; ldr x0, [x19]]
uint64_t fde_sub_090938(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400260ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090938ULL;
}

// FDE #3236 | PC: 0x09095c..0x090968 (12 B) | Symbol: sub_09095c
// EN: AArch64 prologue [mov w2, #1; mov x0, x21; b #0x93c30] | VI: Khởi đầu hàm AArch64 [mov w2, #1; mov x0, x21; b #0x93c30]
uint64_t fde_sub_09095c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E0ULL) << 32) | 0x52800022ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09095CULL;
}

// FDE #3237 | PC: 0x090968..0x09097c (20 B) | Symbol: sub_090968
// EN: AArch64 prologue [mov w2, #1; mov x0, x21; mov x3, x27; mov x4, x28] | VI: Khởi đầu hàm AArch64 [mov w2, #1; mov x0, x21; mov x3, x27; mov x4, x28]
uint64_t fde_sub_090968(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E0ULL) << 32) | 0x52800022ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090968ULL;
}

// FDE #3238 | PC: 0x09097c..0x090988 (12 B) | Symbol: sub_09097c
// EN: AArch64 prologue [mov w2, #1; mov x26, x0; b #0x93c30] | VI: Khởi đầu hàm AArch64 [mov w2, #1; mov x26, x0; b #0x93c30]
uint64_t fde_sub_09097c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003FAULL) << 32) | 0x52800022ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09097CULL;
}

// FDE #3239 | PC: 0x090988..0x0909a4 (28 B) | Symbol: sub_090988
// EN: AArch64 prologue [ldr x9, [x0, #0x10]; ldr x8, [x0]; mov w10, #0x18; sub x9, x9, x8] | VI: Khởi đầu hàm AArch64 [ldr x9, [x0, #0x10]; ldr x8, [x0]; mov w10, #0x18; sub x9, x9, x8]
uint64_t fde_sub_090988(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xF9400809ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090988ULL;
}

// FDE #3240 | PC: 0x0909a4..0x0909b0 (12 B) | Symbol: sub_0909a4
// EN: AArch64 prologue [cmp x8, x1; csel x0, x1, x8, lo; ret] | VI: Khởi đầu hàm AArch64 [cmp x8, x1; csel x0, x1, x8, lo; ret]
uint64_t fde_sub_0909a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9A883020ULL) << 32) | 0xEB01011FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0909A4ULL;
}

// FDE #3241 | PC: 0x0909b0..0x0909bc (12 B) | Symbol: sub_0909b0
// EN: AArch64 prologue [ldr x0, [x19, #0x10]; str xzr, [x19, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x19, #0x10]; str xzr, [x19, #0x10]; ret]
uint64_t fde_sub_0909b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000A7FULL) << 32) | 0xF9400A60ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0909B0ULL;
}

// FDE #3242 | PC: 0x0909bc..0x0909c8 (12 B) | Symbol: sub_0909bc
// EN: AArch64 prologue [ldr x0, [x20, #0x70]; ldr x1, [x24]; b #0x8c2dc] | VI: Khởi đầu hàm AArch64 [ldr x0, [x20, #0x70]; ldr x1, [x24]; b #0x8c2dc]
uint64_t fde_sub_0909bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400301ULL) << 32) | 0xF9403A80ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0909BCULL;
}

// FDE #3243 | PC: 0x0909c8..0x0909e4 (28 B) | Symbol: sub_0909c8
// EN: AArch64 prologue [ldp s0, s1, [x19, #0x78]; scvtf s3, w8; scvtf s2, w9; fdiv s4, s0, s3] | VI: Khởi đầu hàm AArch64 [ldp s0, s1, [x19, #0x78]; scvtf s3, w8; scvtf s2, w9; fdiv s4, s0, s3]
uint64_t fde_sub_0909c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E220103ULL) << 32) | 0x2D4F0660ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0909C8ULL;
}

// FDE #3244 | PC: 0x0909e4..0x0909f8 (20 B) | Symbol: sub_0909e4
// EN: AArch64 prologue [ldp x21, x20, [sp, #0x30]; ldp x23, x22, [sp, #0x20]; ldp x25, x24, [sp, #0x10]; ldr x28, [sp], #0x50] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp, #0x30]; ldp x23, x22, [sp, #0x20]; ldp x25, x24, [sp, #0x10]; ldr x28, [sp], #0x50]
uint64_t fde_sub_0909e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9425BF7ULL) << 32) | 0xA94353F5ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0909E4ULL;
}

// FDE #3245 | PC: 0x0909f8..0x090a0c (20 B) | Symbol: sub_0909f8
// EN: AArch64 prologue [ldp x21, x20, [sp, #0x30]; ldp x23, x22, [sp, #0x20]; ldp x25, x24, [sp, #0x10]; ldp x27, x26, [sp], #0x50] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp, #0x30]; ldp x23, x22, [sp, #0x20]; ldp x25, x24, [sp, #0x10]; ldp x27, x26, [sp], #0x50]
uint64_t fde_sub_0909f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9425BF7ULL) << 32) | 0xA94353F5ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0909F8ULL;
}

// FDE #3246 | PC: 0x090a0c..0x090a18 (12 B) | Symbol: sub_090a0c
// EN: AArch64 prologue [mov x1, x22; mov x2, x21; ret] | VI: Khởi đầu hàm AArch64 [mov x1, x22; mov x2, x21; ret]
uint64_t fde_sub_090a0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E2ULL) << 32) | 0xAA1603E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090A0CULL;
}

// FDE #3247 | PC: 0x090a18..0x090a24 (12 B) | Symbol: sub_090a18
// EN: AArch64 prologue [mov x0, x23; mov x1, x22; b #0x47b84] | VI: Khởi đầu hàm AArch64 [mov x0, x23; mov x1, x22; b #0x47b84]
uint64_t fde_sub_090a18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E1ULL) << 32) | 0xAA1703E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090A18ULL;
}

// FDE #3248 | PC: 0x090a24..0x090a30 (12 B) | Symbol: sub_090a24
// EN: AArch64 prologue [mov x0, x23; mov x1, x21; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x23; mov x1, x21; ret]
uint64_t fde_sub_090a24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E1ULL) << 32) | 0xAA1703E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090A24ULL;
}

// FDE #3249 | PC: 0x090a30..0x090a38 (8 B) | Symbol: sub_090a30
// EN: AArch64 prologue [mov x0, x23; b #0x6d070] | VI: Khởi đầu hàm AArch64 [mov x0, x23; b #0x6d070]
uint64_t fde_sub_090a30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF718FULL) << 32) | 0xAA1703E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090A30ULL;
}

// FDE #3250 | PC: 0x090a38..0x090a44 (12 B) | Symbol: sub_090a38
// EN: AArch64 prologue [ldr x8, [x0]; ldr x3, [x8, #0x38]; br x3] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x3, [x8, #0x38]; br x3]
uint64_t fde_sub_090a38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401D03ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090A38ULL;
}

// FDE #3251 | PC: 0x090a44..0x090a50 (12 B) | Symbol: sub_090a44
// EN: AArch64 prologue [ldr x8, [x0, #8]; mov x19, x0; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; mov x19, x0; ret]
uint64_t fde_sub_090a44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090A44ULL;
}

// FDE #3252 | PC: 0x090a50..0x090a5c (12 B) | Symbol: sub_090a50
// EN: AArch64 prologue [mov x1, x20; mov x2, x21; b #0x7cc88] | VI: Khởi đầu hàm AArch64 [mov x1, x20; mov x2, x21; b #0x7cc88]
uint64_t fde_sub_090a50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E2ULL) << 32) | 0xAA1403E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090A50ULL;
}

// FDE #3253 | PC: 0x090a5c..0x090a64 (8 B) | Symbol: sub_090a5c
// EN: AArch64 prologue [add sp, sp, #0x1c0; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0x1c0; ret]
uint64_t fde_sub_090a5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910703FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090A5CULL;
}

// FDE #3254 | PC: 0x090a64..0x090a70 (12 B) | Symbol: sub_090a64
// EN: AArch64 prologue [mov x21, x1; str x8, [sp, #0x18]; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov x21, x1; str x8, [sp, #0x18]; b #0x93320]
uint64_t fde_sub_090a64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000FE8ULL) << 32) | 0xAA0103F5ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090A64ULL;
}

// FDE #3255 | PC: 0x090a70..0x090a8c (28 B) | Symbol: sub_090a70
// EN: AArch64 prologue [stp x23, x24, [x8]; stp q0, q0, [sp]; stp x25, x26, [x8, #0x10]; str xzr, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [stp x23, x24, [x8]; stp q0, q0, [sp]; stp x25, x26, [x8, #0x10]; str xzr, [sp, #0x20]]
uint64_t fde_sub_090a70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAD0003E0ULL) << 32) | 0xA9006117ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090A70ULL;
}

// FDE #3256 | PC: 0x090a8c..0x090a94 (8 B) | Symbol: sub_090a8c
// EN: AArch64 prologue [mov x1, sp; b #0x47fbc] | VI: Khởi đầu hàm AArch64 [mov x1, sp; b #0x47fbc]
uint64_t fde_sub_090a8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDD4BULL) << 32) | 0x910003E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090A8CULL;
}

// FDE #3257 | PC: 0x090a94..0x090aa0 (12 B) | Symbol: sub_090a94
// EN: AArch64 prologue [mov x1, sp; mov x0, x19; b #0x4bf3c] | VI: Khởi đầu hàm AArch64 [mov x1, sp; mov x0, x19; b #0x4bf3c]
uint64_t fde_sub_090a94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x910003E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090A94ULL;
}

// FDE #3258 | PC: 0x090aa0..0x090ab4 (20 B) | Symbol: sub_090aa0
// EN: AArch64 prologue [mov x1, sp; mov x0, x19; stp s0, s1, [sp]; stp s2, s3, [sp, #8]] | VI: Khởi đầu hàm AArch64 [mov x1, sp; mov x0, x19; stp s0, s1, [sp]; stp s2, s3, [sp, #8]]
uint64_t fde_sub_090aa0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x910003E1ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090AA0ULL;
}

// FDE #3259 | PC: 0x090ab4..0x090ac0 (12 B) | Symbol: sub_090ab4
// EN: AArch64 prologue [add x0, x19, #0x58; add x1, sp, #8; b #0x76a54] | VI: Khởi đầu hàm AArch64 [add x0, x19, #0x58; add x1, sp, #8; b #0x76a54]
uint64_t fde_sub_090ab4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910023E1ULL) << 32) | 0x91016260ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090AB4ULL;
}

// FDE #3260 | PC: 0x090ac0..0x090ad4 (20 B) | Symbol: sub_090ac0
// EN: AArch64 prologue [add x1, x27, #0x18; add x0, sp, #0x218; mov x2, x28; add x22, sp, #0x218] | VI: Khởi đầu hàm AArch64 [add x1, x27, #0x18; add x0, sp, #0x218; mov x2, x28; add x22, sp, #0x218]
uint64_t fde_sub_090ac0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910863E0ULL) << 32) | 0x91006361ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090AC0ULL;
}

// FDE #3261 | PC: 0x090ad4..0x090ae8 (20 B) | Symbol: sub_090ad4
// EN: AArch64 prologue [add x0, sp, #8; mov x1, x22; mov x2, x21; add x24, sp, #8] | VI: Khởi đầu hàm AArch64 [add x0, sp, #8; mov x1, x22; mov x2, x21; add x24, sp, #8]
uint64_t fde_sub_090ad4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E1ULL) << 32) | 0x910023E0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090AD4ULL;
}

// FDE #3262 | PC: 0x090ae8..0x090af4 (12 B) | Symbol: sub_090ae8
// EN: AArch64 prologue [add x0, sp, #8; mov x1, x21; ret] | VI: Khởi đầu hàm AArch64 [add x0, sp, #8; mov x1, x21; ret]
uint64_t fde_sub_090ae8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E1ULL) << 32) | 0x910023E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090AE8ULL;
}

// FDE #3263 | PC: 0x090af4..0x090b00 (12 B) | Symbol: sub_090af4
// EN: AArch64 prologue [mov x0, x21; mov x1, x23; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x21; mov x1, x23; ret]
uint64_t fde_sub_090af4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1703E1ULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090AF4ULL;
}

// FDE #3264 | PC: 0x090b00..0x090b0c (12 B) | Symbol: sub_090b00
// EN: AArch64 prologue [mov x0, x21; mov x1, x19; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x21; mov x1, x19; ret]
uint64_t fde_sub_090b00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E1ULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090B00ULL;
}

// FDE #3265 | PC: 0x090b0c..0x090b24 (24 B) | Symbol: sub_090b0c
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; mov x0, x21; bl #0x46c54; mov x0, x20] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; mov x0, x21; bl #0x46c54; mov x0, x20]
uint64_t fde_sub_090b0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E0ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090B0CULL;
}

// FDE #3266 | PC: 0x090b24..0x090b2c (8 B) | Symbol: sub_090b24
// EN: AArch64 prologue [mov x0, x21; b #0x4aaf4] | VI: Khởi đầu hàm AArch64 [mov x0, x21; b #0x4aaf4]
uint64_t fde_sub_090b24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE7F3ULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090B24ULL;
}

// FDE #3267 | PC: 0x090b2c..0x090b38 (12 B) | Symbol: sub_090b2c
// EN: AArch64 prologue [and x22, x8, #0xfffffffffffffff0; mov x0, x22; b #0x93320] | VI: Khởi đầu hàm AArch64 [and x22, x8, #0xfffffffffffffff0; mov x0, x22; b #0x93320]
uint64_t fde_sub_090b2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E0ULL) << 32) | 0x927CED16ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090B2CULL;
}

// FDE #3268 | PC: 0x090b38..0x090b54 (28 B) | Symbol: sub_090b38
// EN: AArch64 prologue [ldr x9, [x19]; mov x0, x19; add x23, x19, #0x10; sub x8, x8, x9] | VI: Khởi đầu hàm AArch64 [ldr x9, [x19]; mov x0, x19; add x23, x19, #0x10; sub x8, x8, x9]
uint64_t fde_sub_090b38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0xF9400269ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090B38ULL;
}

// FDE #3269 | PC: 0x090b54..0x090b68 (20 B) | Symbol: sub_090b54
// EN: AArch64 prologue [sub sp, sp, #0x60; str x24, [sp, #0x20]; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x24, [sp, #0x20]; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]]
uint64_t fde_sub_090b54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090B54ULL;
}

// FDE #3270 | PC: 0x090b68..0x090b84 (28 B) | Symbol: sub_090b68
// EN: AArch64 prologue [mov x21, x0; str x8, [x0]; stur q0, [x0, #8]; add x0, x0, #0x18] | VI: Khởi đầu hàm AArch64 [mov x21, x0; str x8, [x0]; stur q0, [x0, #8]; add x0, x0, #0x18]
uint64_t fde_sub_090b68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000008ULL) << 32) | 0xAA0003F5ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090B68ULL;
}

// FDE #3271 | PC: 0x090b84..0x090b98 (20 B) | Symbol: sub_090b84
// EN: AArch64 prologue [add x0, sp, #0x98; add x2, sp, #0xe8; add x3, sp, #0x80; mov w1, #2] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x98; add x2, sp, #0xe8; add x3, sp, #0x80; mov w1, #2]
uint64_t fde_sub_090b84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9103A3E2ULL) << 32) | 0x910263E0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090B84ULL;
}

// FDE #3272 | PC: 0x090b98..0x090ba4 (12 B) | Symbol: sub_090b98
// EN: AArch64 prologue [add x20, x8, #8; mov x0, x20; ret] | VI: Khởi đầu hàm AArch64 [add x20, x8, #8; mov x0, x20; ret]
uint64_t fde_sub_090b98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0x91002114ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090B98ULL;
}

// FDE #3273 | PC: 0x090ba4..0x090bb0 (12 B) | Symbol: sub_090ba4
// EN: AArch64 prologue [stp xzr, xzr, [x0, #8]; str xzr, [x0]; b #0x6baf0] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x0, #8]; str xzr, [x0]; b #0x6baf0]
uint64_t fde_sub_090ba4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900001FULL) << 32) | 0xA900FC1FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090BA4ULL;
}

// FDE #3274 | PC: 0x090bb0..0x090bc4 (20 B) | Symbol: sub_090bb0
// EN: AArch64 prologue [ldp x21, x20, [sp, #0x20]; ldr x22, [sp, #0x18]; ldp d9, d8, [sp, #8]; ldr d10, [sp], #0x40] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp, #0x20]; ldr x22, [sp, #0x18]; ldp d9, d8, [sp, #8]; ldr d10, [sp], #0x40]
uint64_t fde_sub_090bb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FF6ULL) << 32) | 0xA94253F5ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090BB0ULL;
}

// FDE #3275 | PC: 0x090bc4..0x090bd0 (12 B) | Symbol: sub_090bc4
// EN: AArch64 prologue [ldrb w8, [x23, #0x17]; mov x1, x23; ret] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x23, #0x17]; mov x1, x23; ret]
uint64_t fde_sub_090bc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1703E1ULL) << 32) | 0x39405EE8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090BC4ULL;
}

// FDE #3276 | PC: 0x090bd0..0x090bec (28 B) | Symbol: sub_090bd0
// EN: AArch64 prologue [fcvtzs w9, s0; fcvtzs w10, s1; mov x22, x0; str xzr, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [fcvtzs w9, s0; fcvtzs w10, s1; mov x22, x0; str xzr, [sp, #0x20]]
uint64_t fde_sub_090bd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E38002AULL) << 32) | 0x1E380009ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090BD0ULL;
}

// FDE #3277 | PC: 0x090bec..0x090c08 (28 B) | Symbol: sub_090bec
// EN: AArch64 prologue [str xzr, [x19]; mov x1, x19; scvtf v0.2s, v0.2s; fmul v0.2s, v0.2s, v1.s[0]] | VI: Khởi đầu hàm AArch64 [str xzr, [x19]; mov x1, x19; scvtf v0.2s, v0.2s; fmul v0.2s, v0.2s, v1.s[0]]
uint64_t fde_sub_090bec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E1ULL) << 32) | 0xF900027FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090BECULL;
}

// FDE #3278 | PC: 0x090c08..0x090c14 (12 B) | Symbol: sub_090c08
// EN: AArch64 prologue [add x1, sp, #0x60; mov x0, x29; b #0x75038] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0x60; mov x0, x29; b #0x75038]
uint64_t fde_sub_090c08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1D03E0ULL) << 32) | 0x910183E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090C08ULL;
}

// FDE #3279 | PC: 0x090c14..0x090c28 (20 B) | Symbol: sub_090c14
// EN: AArch64 prologue [add x0, sp, #0x60; add x2, sp, #0xd0; add x3, sp, #0x48; mov w1, #3] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x60; add x2, sp, #0xd0; add x3, sp, #0x48; mov w1, #3]
uint64_t fde_sub_090c14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910343E2ULL) << 32) | 0x910183E0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090C14ULL;
}

// FDE #3280 | PC: 0x090c28..0x090c3c (20 B) | Symbol: sub_090c28
// EN: AArch64 prologue [ldr x19, [sp, #0x38]; mov x1, sp; add x2, sp, #0x48; mov x0, x19] | VI: Khởi đầu hàm AArch64 [ldr x19, [sp, #0x38]; mov x1, sp; add x2, sp, #0x48; mov x0, x19]
uint64_t fde_sub_090c28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003E1ULL) << 32) | 0xF9401FF3ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090C28ULL;
}

// FDE #3281 | PC: 0x090c3c..0x090c48 (12 B) | Symbol: sub_090c3c
// EN: AArch64 prologue [mov x0, sp; mov x1, x19; ret] | VI: Khởi đầu hàm AArch64 [mov x0, sp; mov x1, x19; ret]
uint64_t fde_sub_090c3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E1ULL) << 32) | 0x910003E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090C3CULL;
}

// FDE #3282 | PC: 0x090c48..0x090c50 (8 B) | Symbol: sub_090c48
// EN: AArch64 prologue [mov x0, sp; b #0x54c34] | VI: Khởi đầu hàm AArch64 [mov x0, sp; b #0x54c34]
uint64_t fde_sub_090c48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF0FFAULL) << 32) | 0x910003E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090C48ULL;
}

// FDE #3283 | PC: 0x090c50..0x090c5c (12 B) | Symbol: sub_090c50
// EN: AArch64 prologue [mov x0, sp; str x8, [sp, #0x18]; b #0x497b4] | VI: Khởi đầu hàm AArch64 [mov x0, sp; str x8, [sp, #0x18]; b #0x497b4]
uint64_t fde_sub_090c50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000FE8ULL) << 32) | 0x910003E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090C50ULL;
}

// FDE #3284 | PC: 0x090c5c..0x090c64 (8 B) | Symbol: sub_090c5c
// EN: AArch64 prologue [mov x0, sp; b #0x7bb90] | VI: Khởi đầu hàm AArch64 [mov x0, sp; b #0x7bb90]
uint64_t fde_sub_090c5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFABCCULL) << 32) | 0x910003E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090C5CULL;
}

// FDE #3285 | PC: 0x090c64..0x090c70 (12 B) | Symbol: sub_090c64
// EN: AArch64 prologue [mov x0, sp; mov x1, x20; ret] | VI: Khởi đầu hàm AArch64 [mov x0, sp; mov x1, x20; ret]
uint64_t fde_sub_090c64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E1ULL) << 32) | 0x910003E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090C64ULL;
}

// FDE #3286 | PC: 0x090c70..0x090c78 (8 B) | Symbol: sub_090c70
// EN: AArch64 prologue [mov x0, x19; b #0x667a0] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x667a0]
uint64_t fde_sub_090c70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF56CBULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090C70ULL;
}

// FDE #3287 | PC: 0x090c78..0x090c80 (8 B) | Symbol: sub_090c78
// EN: AArch64 prologue [mov x0, x19; b #0x47f90] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x47f90]
uint64_t fde_sub_090c78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDCC5ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090C78ULL;
}

// FDE #3288 | PC: 0x090c80..0x090c8c (12 B) | Symbol: sub_090c80
// EN: AArch64 prologue [mov x0, x19; mov x1, x20; b #0x4e5d0] | VI: Khởi đầu hàm AArch64 [mov x0, x19; mov x1, x20; b #0x4e5d0]
uint64_t fde_sub_090c80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E1ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090C80ULL;
}

// FDE #3289 | PC: 0x090c8c..0x090c98 (12 B) | Symbol: sub_090c8c
// EN: AArch64 prologue [mov x19, x0; str x8, [sp, #0x28]; ret] | VI: Khởi đầu hàm AArch64 [mov x19, x0; str x8, [sp, #0x28]; ret]
uint64_t fde_sub_090c8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90017E8ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090C8CULL;
}

// FDE #3290 | PC: 0x090c98..0x090cb4 (28 B) | Symbol: sub_090c98
// EN: AArch64 prologue [mov x19, x0; ldr x8, [x19, #8]; ldr x0, [x0]; mov x20, x1] | VI: Khởi đầu hàm AArch64 [mov x19, x0; ldr x8, [x19, #8]; ldr x0, [x0]; mov x20, x1]
uint64_t fde_sub_090c98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400668ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090C98ULL;
}

// FDE #3291 | PC: 0x090cb4..0x090cc0 (12 B) | Symbol: sub_090cb4
// EN: AArch64 prologue [mov x19, x0; ldr x0, [x0, #0x40]; ret] | VI: Khởi đầu hàm AArch64 [mov x19, x0; ldr x0, [x0, #0x40]; ret]
uint64_t fde_sub_090cb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402000ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090CB4ULL;
}

// FDE #3292 | PC: 0x090cc0..0x090cc8 (8 B) | Symbol: sub_090cc0
// EN: AArch64 prologue [str x8, [sp, #0x18]; b #0x93290] | VI: Khởi đầu hàm AArch64 [str x8, [sp, #0x18]; b #0x93290]
uint64_t fde_sub_090cc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000973ULL) << 32) | 0xF9000FE8ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090CC0ULL;
}

// FDE #3293 | PC: 0x090cc8..0x090cd8 (16 B) | Symbol: sub_090cc8
// EN: AArch64 prologue [ldr x0, [x20, #8]; ldr x1, [sp, #0x48]; mov x2, x19; b #0x834d0] | VI: Khởi đầu hàm AArch64 [ldr x0, [x20, #8]; ldr x1, [sp, #0x48]; mov x2, x19; b #0x834d0]
uint64_t fde_sub_090cc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0xF9400680ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090CC8ULL;
}

// FDE #3294 | PC: 0x090cd8..0x090cf0 (24 B) | Symbol: sub_090cd8
// EN: AArch64 prologue [stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_090cd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90267FAULL) << 32) | 0xA9016FFCULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090CD8ULL;
}

// FDE #3295 | PC: 0x090cf0..0x090d0c (28 B) | Symbol: sub_090cf0
// EN: AArch64 prologue [sub sp, sp, #0x70; str x28, [sp, #0x10]; stp x27, x26, [sp, #0x20]; stp x25, x24, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x28, [sp, #0x10]; stp x27, x26, [sp, #0x20]; stp x25, x24, [sp, #0x30]]
uint64_t fde_sub_090cf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BFCULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090CF0ULL;
}

// FDE #3296 | PC: 0x090d0c..0x090d1c (16 B) | Symbol: sub_090d0c
// EN: AArch64 prologue [fadd s0, s9, s0; fsub s0, s0, s10; fsub s1, s1, s8; b #0x8c240] | VI: Khởi đầu hàm AArch64 [fadd s0, s9, s0; fsub s0, s0, s10; fsub s1, s1, s8; b #0x8c240]
uint64_t fde_sub_090d0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E2A3800ULL) << 32) | 0x1E202920ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090D0CULL;
}

// FDE #3297 | PC: 0x090d1c..0x090d24 (8 B) | Symbol: sub_090d1c
// EN: AArch64 prologue [mov x0, x24; b #0x93cc0] | VI: Khởi đầu hàm AArch64 [mov x0, x24; b #0x93cc0]
uint64_t fde_sub_090d1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000BE8ULL) << 32) | 0xAA1803E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090D1CULL;
}

// FDE #3298 | PC: 0x090d24..0x090d34 (16 B) | Symbol: sub_090d24
// EN: AArch64 prologue [mov x0, x24; mov x1, x22; mov x2, x23; b #0x931f0] | VI: Khởi đầu hàm AArch64 [mov x0, x24; mov x1, x22; mov x2, x23; b #0x931f0]
uint64_t fde_sub_090d24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E1ULL) << 32) | 0xAA1803E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090D24ULL;
}

// FDE #3299 | PC: 0x090d34..0x090d40 (12 B) | Symbol: sub_090d34
// EN: AArch64 prologue [mov x0, x24; mov x1, x25; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x24; mov x1, x25; ret]
uint64_t fde_sub_090d34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1903E1ULL) << 32) | 0xAA1803E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090D34ULL;
}

// FDE #3300 | PC: 0x090d40..0x090d58 (24 B) | Symbol: sub_090d40
// EN: AArch64 prologue [ldp x8, x9, [sp, #8]; str x0, [x19]; stp xzr, xzr, [sp, #8]; stp x8, x9, [x0]] | VI: Khởi đầu hàm AArch64 [ldp x8, x9, [sp, #8]; str x0, [x19]; stp xzr, xzr, [sp, #8]; stp x8, x9, [x0]]
uint64_t fde_sub_090d40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000260ULL) << 32) | 0xA940A7E8ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090D40ULL;
}

// FDE #3301 | PC: 0x090d58..0x090d68 (16 B) | Symbol: sub_090d58
// EN: AArch64 prologue [str x9, [x22]; str x8, [x10, x21, lsl #3]; ldr x8, [x22]; ret] | VI: Khởi đầu hàm AArch64 [str x9, [x22]; str x8, [x10, x21, lsl #3]; ldr x8, [x22]; ret]
uint64_t fde_sub_090d58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF8357948ULL) << 32) | 0xF90002C9ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090D58ULL;
}

// FDE #3302 | PC: 0x090d68..0x090d78 (16 B) | Symbol: sub_090d68
// EN: AArch64 prologue [adrp x1, #0x1b000; mov x0, x22; add x1, x1, #0xdcf; b #0x93910] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x1b000; mov x0, x22; add x1, x1, #0xdcf; b #0x93910]
uint64_t fde_sub_090d68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E0ULL) << 32) | 0xF0FFFC41ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090D68ULL;
}

// FDE #3303 | PC: 0x090d78..0x090d88 (16 B) | Symbol: sub_090d78
// EN: AArch64 prologue [ldr x0, [x19, #0xd8]; add x1, sp, #0xc8; add x2, sp, #0x90; b #0x78df0] | VI: Khởi đầu hàm AArch64 [ldr x0, [x19, #0xd8]; add x1, sp, #0xc8; add x2, sp, #0x90; b #0x78df0]
uint64_t fde_sub_090d78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910323E1ULL) << 32) | 0xF9406E60ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090D78ULL;
}

// FDE #3304 | PC: 0x090d88..0x090d90 (8 B) | Symbol: sub_090d88
// EN: AArch64 prologue [add x1, x1, #0xcf7; b #0x93910] | VI: Khởi đầu hàm AArch64 [add x1, x1, #0xcf7; b #0x93910]
uint64_t fde_sub_090d88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000AE1ULL) << 32) | 0x9133DC21ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090D88ULL;
}

// FDE #3305 | PC: 0x090d90..0x090d98 (8 B) | Symbol: sub_090d90
// EN: AArch64 prologue [add x1, x1, #0xf95; b #0x93910] | VI: Khởi đầu hàm AArch64 [add x1, x1, #0xf95; b #0x93910]
uint64_t fde_sub_090d90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000ADFULL) << 32) | 0x913E5421ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090D90ULL;
}

// FDE #3306 | PC: 0x090d98..0x090da8 (16 B) | Symbol: sub_090d98
// EN: AArch64 prologue [ldr x20, [x20, #0x18]; add x0, sp, #0x10; add x1, sp, #0x70; b #0x754f4] | VI: Khởi đầu hàm AArch64 [ldr x20, [x20, #0x18]; add x0, sp, #0x10; add x1, sp, #0x70; b #0x754f4]
uint64_t fde_sub_090d98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910043E0ULL) << 32) | 0xF9400E94ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090D98ULL;
}

// FDE #3307 | PC: 0x090da8..0x090dc0 (24 B) | Symbol: sub_090da8
// EN: AArch64 prologue [fcvtzs w9, s0; orr x8, x8, x9; orr x8, x8, #0x100; add x0, sp, #0xe0] | VI: Khởi đầu hàm AArch64 [fcvtzs w9, s0; orr x8, x8, x9; orr x8, x8, #0x100; add x0, sp, #0xe0]
uint64_t fde_sub_090da8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA090108ULL) << 32) | 0x1E380009ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090DA8ULL;
}

// FDE #3308 | PC: 0x090dc0..0x090dc8 (8 B) | Symbol: sub_090dc0
// EN: AArch64 prologue [add x0, sp, #0x38; b #0x7d610] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x38; b #0x7d610]
uint64_t fde_sub_090dc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFB213ULL) << 32) | 0x9100E3E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090DC0ULL;
}

// FDE #3309 | PC: 0x090dc8..0x090dd8 (16 B) | Symbol: sub_090dc8
// EN: AArch64 prologue [sub x29, x27, #0x18; madd x8, x9, x28, x8; cmp x29, x8; ret] | VI: Khởi đầu hàm AArch64 [sub x29, x27, #0x18; madd x8, x9, x28, x8; cmp x29, x8; ret]
uint64_t fde_sub_090dc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9B1C2128ULL) << 32) | 0xD100637DULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090DC8ULL;
}

// FDE #3310 | PC: 0x090dd8..0x090de8 (16 B) | Symbol: sub_090dd8
// EN: AArch64 prologue [str x8, [sp, #0x30]; str xzr, [x2]; add x2, sp, #0x30; b #0x78030] | VI: Khởi đầu hàm AArch64 [str x8, [sp, #0x30]; str xzr, [x2]; add x2, sp, #0x30; b #0x78030]
uint64_t fde_sub_090dd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900005FULL) << 32) | 0xF9001BE8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090DD8ULL;
}

// FDE #3311 | PC: 0x090de8..0x090df8 (16 B) | Symbol: sub_090de8
// EN: AArch64 prologue [add x0, sp, #0x20; add x1, sp, #0x38; add x2, sp, #0x30; b #0x83b9c] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x20; add x1, sp, #0x38; add x2, sp, #0x30; b #0x83b9c]
uint64_t fde_sub_090de8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9100E3E1ULL) << 32) | 0x910083E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090DE8ULL;
}

// FDE #3312 | PC: 0x090df8..0x090e00 (8 B) | Symbol: sub_090df8
// EN: AArch64 prologue [mov w2, #0x2601; b #0x94a60] | VI: Khởi đầu hàm AArch64 [mov w2, #0x2601; b #0x94a60]
uint64_t fde_sub_090df8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000F19ULL) << 32) | 0x5284C022ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090DF8ULL;
}

// FDE #3313 | PC: 0x090e00..0x090e10 (16 B) | Symbol: sub_090e00
// EN: AArch64 prologue [add x19, x21, #0x10; add x1, sp, #0x80; mov x0, x19; b #0x547dc] | VI: Khởi đầu hàm AArch64 [add x19, x21, #0x10; add x1, sp, #0x80; mov x0, x19; b #0x547dc]
uint64_t fde_sub_090e00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910203E1ULL) << 32) | 0x910042B3ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090E00ULL;
}

// FDE #3314 | PC: 0x090e10..0x090e18 (8 B) | Symbol: sub_090e10
// EN: AArch64 prologue [mov w2, #0x812f; b #0x94a60] | VI: Khởi đầu hàm AArch64 [mov w2, #0x812f; b #0x94a60]
uint64_t fde_sub_090e10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000F13ULL) << 32) | 0x529025E2ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090E10ULL;
}

// FDE #3315 | PC: 0x090e18..0x090e20 (8 B) | Symbol: sub_090e18
// EN: AArch64 prologue [add x0, sp, #0x40; b #0x46c54] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x40; b #0x46c54]
uint64_t fde_sub_090e18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED78EULL) << 32) | 0x910103E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090E18ULL;
}

// FDE #3316 | PC: 0x090e20..0x090e30 (16 B) | Symbol: sub_090e20
// EN: AArch64 prologue [add x0, sp, #0x40; mov x1, x20; mov v0.16b, v9.16b; b #0x6f578] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x40; mov x1, x20; mov v0.16b, v9.16b; b #0x6f578]
uint64_t fde_sub_090e20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E1ULL) << 32) | 0x910103E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090E20ULL;
}

// FDE #3317 | PC: 0x090e30..0x090e40 (16 B) | Symbol: sub_090e30
// EN: AArch64 prologue [add x1, sp, #0x40; add x2, sp, #0xd0; mov x0, x19; b #0x74bf8] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0x40; add x2, sp, #0xd0; mov x0, x19; b #0x74bf8]
uint64_t fde_sub_090e30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910343E2ULL) << 32) | 0x910103E1ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090E30ULL;
}

// FDE #3318 | PC: 0x090e40..0x090e50 (16 B) | Symbol: sub_090e40
// EN: AArch64 prologue [scvtf d0, w21; mov w1, #5; mov x0, x19; b #0x50238] | VI: Khởi đầu hàm AArch64 [scvtf d0, w21; mov w1, #5; mov x0, x19; b #0x50238]
uint64_t fde_sub_090e40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x528000A1ULL) << 32) | 0x1E6202A0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090E40ULL;
}

// FDE #3319 | PC: 0x090e50..0x090e58 (8 B) | Symbol: sub_090e50
// EN: AArch64 prologue [add x0, sp, #0x48; b #0x46c54] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x48; b #0x46c54]
uint64_t fde_sub_090e50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED780ULL) << 32) | 0x910123E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090E50ULL;
}

// FDE #3320 | PC: 0x090e58..0x090e68 (16 B) | Symbol: sub_090e58
// EN: AArch64 prologue [add x0, sp, #0x48; add x1, sp, #0x30; mov x2, sp; b #0x511f0] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x48; add x1, sp, #0x30; mov x2, sp; b #0x511f0]
uint64_t fde_sub_090e58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9100C3E1ULL) << 32) | 0x910123E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090E58ULL;
}

// FDE #3321 | PC: 0x090e68..0x090e70 (8 B) | Symbol: sub_090e68
// EN: AArch64 prologue [add x0, sp, #0x48; b #0x78b30] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x48; b #0x78b30]
uint64_t fde_sub_090e68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF9F31ULL) << 32) | 0x910123E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090E68ULL;
}

// FDE #3322 | PC: 0x090e70..0x090e80 (16 B) | Symbol: sub_090e70
// EN: AArch64 prologue [ldr x8, [x22, #0x28]; ldr x9, [sp, #0x188]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x22, #0x28]; ldr x9, [sp, #0x188]; cmp x8, x9; ret]
uint64_t fde_sub_090e70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF940C7E9ULL) << 32) | 0xF94016C8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090E70ULL;
}

// FDE #3323 | PC: 0x090e80..0x090e98 (24 B) | Symbol: sub_090e80
// EN: AArch64 prologue [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; str x8, [sp, #0x28]; ldr x20, [x0, #0xa8]] | VI: Khởi đầu hàm AArch64 [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; str x8, [sp, #0x28]; ldr x20, [x0, #0xa8]]
uint64_t fde_sub_090e80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016C8ULL) << 32) | 0xD53BD056ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090E80ULL;
}

// FDE #3324 | PC: 0x090e98..0x090ea0 (8 B) | Symbol: sub_090e98
// EN: AArch64 prologue [add x0, sp, #0x70; b #0x46c54] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x70; b #0x46c54]
uint64_t fde_sub_090e98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED76EULL) << 32) | 0x9101C3E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090E98ULL;
}

// FDE #3325 | PC: 0x090ea0..0x090eac (12 B) | Symbol: sub_090ea0
// EN: AArch64 prologue [str x8, [x14, x13, lsl #3]; mov x10, x13; ret] | VI: Khởi đầu hàm AArch64 [str x8, [x14, x13, lsl #3]; mov x10, x13; ret]
uint64_t fde_sub_090ea0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0D03EAULL) << 32) | 0xF82D79C8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090EA0ULL;
}

// FDE #3326 | PC: 0x090eac..0x090eb8 (12 B) | Symbol: sub_090eac
// EN: AArch64 prologue [mov x19, x2; mov x21, x0; ret] | VI: Khởi đầu hàm AArch64 [mov x19, x2; mov x21, x0; ret]
uint64_t fde_sub_090eac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F5ULL) << 32) | 0xAA0203F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090EACULL;
}

// FDE #3327 | PC: 0x090eb8..0x090ec8 (16 B) | Symbol: sub_090eb8
// EN: AArch64 prologue [mov x19, x2; mov x20, x1; mov x21, x0; b #0x93c40] | VI: Khởi đầu hàm AArch64 [mov x19, x2; mov x20, x1; mov x21, x0; b #0x93c40]
uint64_t fde_sub_090eb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103F4ULL) << 32) | 0xAA0203F3ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090EB8ULL;
}

// FDE #3328 | PC: 0x090ec8..0x090ed4 (12 B) | Symbol: sub_090ec8
// EN: AArch64 prologue [mov x14, x15; ldr x15, [x15]; ret] | VI: Khởi đầu hàm AArch64 [mov x14, x15; ldr x15, [x15]; ret]
uint64_t fde_sub_090ec8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94001EFULL) << 32) | 0xAA0F03EEULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090EC8ULL;
}

// FDE #3329 | PC: 0x090ed4..0x090ee0 (12 B) | Symbol: sub_090ed4
// EN: AArch64 prologue [udiv x14, x13, x20; msub x13, x14, x20, x13; ret] | VI: Khởi đầu hàm AArch64 [udiv x14, x13, x20; msub x13, x14, x20, x13; ret]
uint64_t fde_sub_090ed4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9B14B5CDULL) << 32) | 0x9AD409AEULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090ED4ULL;
}

// FDE #3330 | PC: 0x090ee0..0x090eec (12 B) | Symbol: sub_090ee0
// EN: AArch64 prologue [ldr x13, [x12, #8]; cmp x9, #1; ret] | VI: Khởi đầu hàm AArch64 [ldr x13, [x12, #8]; cmp x9, #1; ret]
uint64_t fde_sub_090ee0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF100053FULL) << 32) | 0xF940058DULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090EE0ULL;
}

// FDE #3331 | PC: 0x090eec..0x090ef8 (12 B) | Symbol: sub_090eec
// EN: AArch64 prologue [sub x12, x20, #1; and x10, x10, x12; ret] | VI: Khởi đầu hàm AArch64 [sub x12, x20, #1; and x10, x10, x12; ret]
uint64_t fde_sub_090eec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8A0C014AULL) << 32) | 0xD100068CULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090EECULL;
}

// FDE #3332 | PC: 0x090ef8..0x090f04 (12 B) | Symbol: sub_090ef8
// EN: AArch64 prologue [udiv x12, x10, x20; msub x10, x12, x20, x10; ret] | VI: Khởi đầu hàm AArch64 [udiv x12, x10, x20; msub x10, x12, x20, x10; ret]
uint64_t fde_sub_090ef8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9B14A98AULL) << 32) | 0x9AD4094CULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090EF8ULL;
}

// FDE #3333 | PC: 0x090f04..0x090f14 (16 B) | Symbol: sub_090f04
// EN: AArch64 prologue [sub x8, x8, x20; mov x10, #0xffffffffffffffe; cmp x10, x8, asr #3; ret] | VI: Khởi đầu hàm AArch64 [sub x8, x8, x20; mov x10, #0xffffffffffffffe; cmp x10, x8, asr #3; ret]
uint64_t fde_sub_090f04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB27FEBEAULL) << 32) | 0xCB140108ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090F04ULL;
}

// FDE #3334 | PC: 0x090f14..0x090f20 (12 B) | Symbol: sub_090f14
// EN: AArch64 prologue [mov x11, x19; ldr x8, [x11, #0x10]!; ret] | VI: Khởi đầu hàm AArch64 [mov x11, x19; ldr x8, [x11, #0x10]!; ret]
uint64_t fde_sub_090f14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF8410D68ULL) << 32) | 0xAA1303EBULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090F14ULL;
}

// FDE #3335 | PC: 0x090f20..0x090f30 (16 B) | Symbol: sub_090f20
// EN: AArch64 prologue [stp xzr, xzr, [sp, #0x30]; str x8, [x0]; stur q0, [x0, #8]; ret] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [sp, #0x30]; str x8, [x0]; stur q0, [x0, #8]; ret]
uint64_t fde_sub_090f20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000008ULL) << 32) | 0xA9037FFFULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090F20ULL;
}

// FDE #3336 | PC: 0x090f30..0x090f48 (24 B) | Symbol: sub_090f30
// EN: AArch64 prologue [ldr x20, [x19]; sub x21, x9, x20; asr x24, x21, #3; add x9, x24, #1] | VI: Khởi đầu hàm AArch64 [ldr x20, [x19]; sub x21, x9, x20; asr x24, x21, #3; add x9, x24, #1]
uint64_t fde_sub_090f30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xCB140135ULL) << 32) | 0xF9400274ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090F30ULL;
}

// FDE #3337 | PC: 0x090f48..0x090f60 (24 B) | Symbol: sub_090f48
// EN: AArch64 prologue [ldr x8, [x22]; add x24, x23, x24, lsl #3; add x22, x23, x25, lsl #3; cmp x21, #1] | VI: Khởi đầu hàm AArch64 [ldr x8, [x22]; add x24, x23, x24, lsl #3; add x22, x23, x25, lsl #3; cmp x21, #1]
uint64_t fde_sub_090f48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8B180EF8ULL) << 32) | 0xF94002C8ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090F48ULL;
}

// FDE #3338 | PC: 0x090f60..0x090f70 (16 B) | Symbol: sub_090f60
// EN: AArch64 prologue [ldr x20, [x19, #0x18]; add x0, sp, #0x20; mov x1, x19; b #0x4b758] | VI: Khởi đầu hàm AArch64 [ldr x20, [x19, #0x18]; add x0, sp, #0x20; mov x1, x19; b #0x4b758]
uint64_t fde_sub_090f60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910083E0ULL) << 32) | 0xF9400E74ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090F60ULL;
}

// FDE #3339 | PC: 0x090f70..0x090f78 (8 B) | Symbol: sub_090f70
// EN: AArch64 prologue [str w8, [sp, #0x70]; b #0x497b4] | VI: Khởi đầu hàm AArch64 [str w8, [sp, #0x70]; b #0x497b4]
uint64_t fde_sub_090f70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE210ULL) << 32) | 0xB90073E8ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090F70ULL;
}

// FDE #3340 | PC: 0x090f78..0x090f88 (16 B) | Symbol: sub_090f78
// EN: AArch64 prologue [adrp x5, #0xa0000; add x5, x5, #0x370; ldr x20, [x20, #0xa0]; ret] | VI: Khởi đầu hàm AArch64 [adrp x5, #0xa0000; add x5, x5, #0x370; ldr x20, [x20, #0xa0]; ret]
uint64_t fde_sub_090f78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910DC0A5ULL) << 32) | 0x90000085ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090F78ULL;
}

// FDE #3341 | PC: 0x090f88..0x090f98 (16 B) | Symbol: sub_090f88
// EN: AArch64 prologue [add x1, x20, #0x18; add x0, sp, #0x218; mov x2, x28; ret] | VI: Khởi đầu hàm AArch64 [add x1, x20, #0x18; add x0, sp, #0x218; mov x2, x28; ret]
uint64_t fde_sub_090f88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910863E0ULL) << 32) | 0x91006281ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090F88ULL;
}

// FDE #3342 | PC: 0x090f98..0x090fa0 (8 B) | Symbol: sub_090f98
// EN: AArch64 prologue [mov w1, w21; b #0x496f8] | VI: Khởi đầu hàm AArch64 [mov w1, w21; b #0x496f8]
uint64_t fde_sub_090f98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE1D7ULL) << 32) | 0x2A1503E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090F98ULL;
}

// FDE #3343 | PC: 0x090fa0..0x090fac (12 B) | Symbol: sub_090fa0
// EN: AArch64 prologue [ldr x19, [x21]; str xzr, [x21]; ret] | VI: Khởi đầu hàm AArch64 [ldr x19, [x21]; str xzr, [x21]; ret]
uint64_t fde_sub_090fa0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90002BFULL) << 32) | 0xF94002B3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090FA0ULL;
}

// FDE #3344 | PC: 0x090fac..0x090fb8 (12 B) | Symbol: sub_090fac
// EN: AArch64 prologue [ldr x9, [sp, #0x1e8]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [sp, #0x1e8]; cmp x8, x9; ret]
uint64_t fde_sub_090fac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xF940F7E9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090FACULL;
}

// FDE #3345 | PC: 0x090fb8..0x090fc4 (12 B) | Symbol: sub_090fb8
// EN: AArch64 prologue [ldr x9, [sp, #0xa8]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [sp, #0xa8]; cmp x8, x9; ret]
uint64_t fde_sub_090fb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xF94057E9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090FB8ULL;
}

// FDE #3346 | PC: 0x090fc4..0x090fdc (24 B) | Symbol: sub_090fc4
// EN: AArch64 prologue [add x10, x9, #1; str x10, [x8]; ldr x8, [x19, #0x40]; ldr x0, [x19, #0x18]] | VI: Khởi đầu hàm AArch64 [add x10, x9, #1; str x10, [x8]; ldr x8, [x19, #0x40]; ldr x0, [x19, #0x18]]
uint64_t fde_sub_090fc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900010AULL) << 32) | 0x9100052AULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090FC4ULL;
}

// FDE #3347 | PC: 0x090fdc..0x090fe8 (12 B) | Symbol: sub_090fdc
// EN: AArch64 prologue [ldp x23, x21, [x21, #0x28]; stp x23, x21, [sp, #8]; ret] | VI: Khởi đầu hàm AArch64 [ldp x23, x21, [x21, #0x28]; stp x23, x21, [sp, #8]; ret]
uint64_t fde_sub_090fdc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA900D7F7ULL) << 32) | 0xA942D6B7ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090FDCULL;
}

// FDE #3348 | PC: 0x090fe8..0x091000 (24 B) | Symbol: sub_090fe8
// EN: AArch64 prologue [add x8, x21, x20; sub x2, x8, x1; mov x0, x19; mov x3, x21] | VI: Khởi đầu hàm AArch64 [add x8, x21, x20; sub x2, x8, x1; mov x0, x19; mov x3, x21]
uint64_t fde_sub_090fe8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xCB010102ULL) << 32) | 0x8B1402A8ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090FE8ULL;
}

// FDE #3349 | PC: 0x091000..0x091008 (8 B) | Symbol: sub_091000
// EN: AArch64 prologue [mov w1, #1; b #0x771d4] | VI: Khởi đầu hàm AArch64 [mov w1, #1; b #0x771d4]
uint64_t fde_sub_091000(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF9874ULL) << 32) | 0x52800021ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091000ULL;
}

// FDE #3350 | PC: 0x091008..0x091018 (16 B) | Symbol: sub_091008
// EN: AArch64 prologue [ldr x0, [x8, #0x28]; ldr x8, [x0]; ldr x8, [x8, #0x30]; br x8] | VI: Khởi đầu hàm AArch64 [ldr x0, [x8, #0x28]; ldr x8, [x0]; ldr x8, [x8, #0x30]; br x8]
uint64_t fde_sub_091008(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xF9401500ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091008ULL;
}

// FDE #3351 | PC: 0x091018..0x091030 (24 B) | Symbol: sub_091018
// EN: AArch64 prologue [ldr x8, [x1]; str xzr, [x1]; mov x19, x0; ldr x0, [x0]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1]; str xzr, [x1]; mov x19, x0; ldr x0, [x0]]
uint64_t fde_sub_091018(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900003FULL) << 32) | 0xF9400028ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091018ULL;
}

// FDE #3352 | PC: 0x091030..0x091040 (16 B) | Symbol: sub_091030
// EN: AArch64 prologue [add x1, sp, #0xd0; mov x0, x20; str x23, [sp, #0xd0]; b #0x69448] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0xd0; mov x0, x20; str x23, [sp, #0xd0]; b #0x69448]
uint64_t fde_sub_091030(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0x910343E1ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091030ULL;
}

// FDE #3353 | PC: 0x091040..0x091050 (16 B) | Symbol: sub_091040
// EN: AArch64 prologue [ldrb w15, [x14]; sub w15, w15, #0x30; cmp w15, #9; ret] | VI: Khởi đầu hàm AArch64 [ldrb w15, [x14]; sub w15, w15, #0x30; cmp w15, #9; ret]
uint64_t fde_sub_091040(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5100C1EFULL) << 32) | 0x394001CFULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091040ULL;
}

// FDE #3354 | PC: 0x091050..0x091064 (20 B) | Symbol: sub_091050
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x46c54; add x0, x19, #8; ldr x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x46c54; add x0, x19, #8; ldr x30, [sp], #0x10]
uint64_t fde_sub_091050(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x97FED700ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091050ULL;
}

// FDE #3355 | PC: 0x091064..0x09106c (8 B) | Symbol: sub_091064
// EN: AArch64 prologue [mov x24, x0; b #0x93c30] | VI: Khởi đầu hàm AArch64 [mov x24, x0; b #0x93c30]
uint64_t fde_sub_091064(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000AF2ULL) << 32) | 0xAA0003F8ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091064ULL;
}

// FDE #3356 | PC: 0x09106c..0x091074 (8 B) | Symbol: sub_09106c
// EN: AArch64 prologue [mov x1, x23; b #0x7d6e4] | VI: Khởi đầu hàm AArch64 [mov x1, x23; b #0x7d6e4]
uint64_t fde_sub_09106c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFB19DULL) << 32) | 0xAA1703E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09106CULL;
}

// FDE #3357 | PC: 0x091074..0x09107c (8 B) | Symbol: sub_091074
// EN: AArch64 prologue [mov x0, x25; b #0x93cc0] | VI: Khởi đầu hàm AArch64 [mov x0, x25; b #0x93cc0]
uint64_t fde_sub_091074(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000B12ULL) << 32) | 0xAA1903E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091074ULL;
}

// FDE #3358 | PC: 0x09107c..0x09108c (16 B) | Symbol: sub_09107c
// EN: AArch64 prologue [mov x1, x25; mov x2, x27; mov x23, x0; b #0x80c6c] | VI: Khởi đầu hàm AArch64 [mov x1, x25; mov x2, x27; mov x23, x0; b #0x80c6c]
uint64_t fde_sub_09107c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1B03E2ULL) << 32) | 0xAA1903E1ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09107CULL;
}

// FDE #3359 | PC: 0x09108c..0x09109c (16 B) | Symbol: sub_09108c
// EN: AArch64 prologue [mrs x27, tpidr_el0; ldr x8, [x27, #0x28]; mov x19, x0; ret] | VI: Khởi đầu hàm AArch64 [mrs x27, tpidr_el0; ldr x8, [x27, #0x28]; mov x19, x0; ret]
uint64_t fde_sub_09108c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401768ULL) << 32) | 0xD53BD05BULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09108CULL;
}

// FDE #3360 | PC: 0x09109c..0x0910ac (16 B) | Symbol: sub_09109c
// EN: AArch64 prologue [adrp x5, #0xa0000; add x5, x5, #0x2a0; ldr x20, [x20, #8]; ret] | VI: Khởi đầu hàm AArch64 [adrp x5, #0xa0000; add x5, x5, #0x2a0; ldr x20, [x20, #8]; ret]
uint64_t fde_sub_09109c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910A80A5ULL) << 32) | 0xF0000065ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09109CULL;
}

// FDE #3361 | PC: 0x0910ac..0x0910c4 (24 B) | Symbol: sub_0910ac
// EN: AArch64 prologue [fmov d0, x25; cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w27, s0] | VI: Khởi đầu hàm AArch64 [fmov d0, x25; cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w27, s0]
uint64_t fde_sub_0910ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x0E205800ULL) << 32) | 0x9E670320ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0910ACULL;
}

// FDE #3362 | PC: 0x0910c4..0x0910cc (8 B) | Symbol: sub_0910c4
// EN: AArch64 prologue [ldr x8, [x8, #0x50]; br x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x8, #0x50]; br x8]
uint64_t fde_sub_0910c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD61F0100ULL) << 32) | 0xF9402908ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0910C4ULL;
}

// FDE #3363 | PC: 0x0910cc..0x0910dc (16 B) | Symbol: sub_0910cc
// EN: AArch64 prologue [fmov d0, x27; mov x0, x26; str q0, [sp, #0x50]; b #0x48d40] | VI: Khởi đầu hàm AArch64 [fmov d0, x27; mov x0, x26; str q0, [sp, #0x50]; b #0x48d40]
uint64_t fde_sub_0910cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1A03E0ULL) << 32) | 0x9E670360ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0910CCULL;
}

// FDE #3364 | PC: 0x0910dc..0x0910e8 (12 B) | Symbol: sub_0910dc
// EN: AArch64 prologue [str xzr, [x20, #8]!; str x8, [x0]; ret] | VI: Khởi đầu hàm AArch64 [str xzr, [x20, #8]!; str x8, [x0]; ret]
uint64_t fde_sub_0910dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000008ULL) << 32) | 0xF8008E9FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0910DCULL;
}

// FDE #3365 | PC: 0x0910e8..0x0910f8 (16 B) | Symbol: sub_0910e8
// EN: AArch64 prologue [ldr x0, [x19, #0x18]; add x1, sp, #0x20; add x2, sp, #0xa8; b #0x762d4] | VI: Khởi đầu hàm AArch64 [ldr x0, [x19, #0x18]; add x1, sp, #0x20; add x2, sp, #0xa8; b #0x762d4]
uint64_t fde_sub_0910e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910083E1ULL) << 32) | 0xF9400E60ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0910E8ULL;
}

// FDE #3366 | PC: 0x0910f8..0x091108 (16 B) | Symbol: sub_0910f8
// EN: AArch64 prologue [adrp x1, #0x1c000; add x1, x1, #0xdd9; add x0, sp, #0x78; ret] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x1c000; add x1, x1, #0xdd9; add x0, sp, #0x78; ret]
uint64_t fde_sub_0910f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91376421ULL) << 32) | 0xF0FFFC41ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0910F8ULL;
}

// FDE #3367 | PC: 0x091108..0x091110 (8 B) | Symbol: sub_091108
// EN: AArch64 prologue [ldr x0, [x0, #0x18]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x18]; ret]
uint64_t fde_sub_091108(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF9400C00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091108ULL;
}

// FDE #3368 | PC: 0x091110..0x091118 (8 B) | Symbol: sub_091110
// EN: AArch64 prologue [add x0, sp, #0x90; b #0x46c54] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x90; b #0x46c54]
uint64_t fde_sub_091110(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED6D0ULL) << 32) | 0x910243E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091110ULL;
}

// FDE #3369 | PC: 0x091118..0x091128 (16 B) | Symbol: sub_091118
// EN: AArch64 prologue [add x0, sp, #0x90; mov x1, x21; add x20, sp, #0x90; b #0x77b60] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x90; mov x1, x21; add x20, sp, #0x90; b #0x77b60]
uint64_t fde_sub_091118(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E1ULL) << 32) | 0x910243E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091118ULL;
}

// FDE #3370 | PC: 0x091128..0x091130 (8 B) | Symbol: sub_091128
// EN: AArch64 prologue [add x0, sp, #0xb0; b #0x7bdb0] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0xb0; b #0x7bdb0]
uint64_t fde_sub_091128(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFAB21ULL) << 32) | 0x9102C3E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091128ULL;
}

// FDE #3371 | PC: 0x091130..0x091140 (16 B) | Symbol: sub_091130
// EN: AArch64 prologue [add x0, sp, #0xb0; add x1, sp, #0x90; str q0, [sp, #0x90]; b #0x772cc] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0xb0; add x1, sp, #0x90; str q0, [sp, #0x90]; b #0x772cc]
uint64_t fde_sub_091130(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910243E1ULL) << 32) | 0x9102C3E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091130ULL;
}

// FDE #3372 | PC: 0x091140..0x091148 (8 B) | Symbol: sub_091140
// EN: AArch64 prologue [stp xzr, xzr, [sp, #0xc0]; b #0x93320] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [sp, #0xc0]; b #0x93320]
uint64_t fde_sub_091140(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000877ULL) << 32) | 0xA90C7FFFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091140ULL;
}

// FDE #3373 | PC: 0x091148..0x091150 (8 B) | Symbol: sub_091148
// EN: AArch64 prologue [ldr x8, [x0, #0x18]; br x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x18]; br x8]
uint64_t fde_sub_091148(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD61F0100ULL) << 32) | 0xF9400C08ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091148ULL;
}

// FDE #3374 | PC: 0x091150..0x091158 (8 B) | Symbol: sub_091150
// EN: AArch64 prologue [str w8, [sp, #0xb0]; b #0x497b4] | VI: Khởi đầu hàm AArch64 [str w8, [sp, #0xb0]; b #0x497b4]
uint64_t fde_sub_091150(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE198ULL) << 32) | 0xB900B3E8ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091150ULL;
}

// FDE #3375 | PC: 0x091158..0x091168 (16 B) | Symbol: sub_091158
// EN: AArch64 prologue [mov x22, x0; stp xzr, xzr, [x0, #8]; str xzr, [x0]; b #0x6af38] | VI: Khởi đầu hàm AArch64 [mov x22, x0; stp xzr, xzr, [x0, #8]; str xzr, [x0]; b #0x6af38]
uint64_t fde_sub_091158(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA900FC1FULL) << 32) | 0xAA0003F6ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091158ULL;
}

// FDE #3376 | PC: 0x091168..0x091178 (16 B) | Symbol: sub_091168
// EN: AArch64 prologue [add x1, sp, #0xb0; mov x0, x19; str x22, [sp, #0xb0]; b #0x93b50] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0xb0; mov x0, x19; str x22, [sp, #0xb0]; b #0x93b50]
uint64_t fde_sub_091168(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9102C3E1ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091168ULL;
}

// FDE #3377 | PC: 0x091178..0x091188 (16 B) | Symbol: sub_091178
// EN: AArch64 prologue [str xzr, [sp, #8]; ldrb w8, [x20, #0x38]; add x9, x20, #0x30; ret] | VI: Khởi đầu hàm AArch64 [str xzr, [sp, #8]; ldrb w8, [x20, #0x38]; add x9, x20, #0x30; ret]
uint64_t fde_sub_091178(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3940E288ULL) << 32) | 0xF90007FFULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091178ULL;
}

// FDE #3378 | PC: 0x091188..0x091190 (8 B) | Symbol: sub_091188
// EN: AArch64 prologue [str xzr, [sp, #8]; b #0x93320] | VI: Khởi đầu hàm AArch64 [str xzr, [sp, #8]; b #0x93320]
uint64_t fde_sub_091188(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000865ULL) << 32) | 0xF90007FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091188ULL;
}

// FDE #3379 | PC: 0x091190..0x0911a0 (16 B) | Symbol: sub_091190
// EN: AArch64 prologue [str xzr, [x8, #8]!; str x0, [sp, #0x98]; str x9, [x0]; ret] | VI: Khởi đầu hàm AArch64 [str xzr, [x8, #8]!; str x0, [sp, #0x98]; str x9, [x0]; ret]
uint64_t fde_sub_091190(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9004FE0ULL) << 32) | 0xF8008D1FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091190ULL;
}

// FDE #3380 | PC: 0x0911a0..0x0911a8 (8 B) | Symbol: sub_0911a0
// EN: AArch64 prologue [str xzr, [sp, #0x20]; b #0x48190] | VI: Khởi đầu hàm AArch64 [str xzr, [sp, #0x20]; b #0x48190]
uint64_t fde_sub_0911a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDBFBULL) << 32) | 0xF90013FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0911A0ULL;
}

// FDE #3381 | PC: 0x0911a8..0x0911b8 (16 B) | Symbol: sub_0911a8
// EN: AArch64 prologue [str xzr, [sp, #0x20]; stp q0, q0, [sp]; str w8, [sp, #0x48]; b #0x497b4] | VI: Khởi đầu hàm AArch64 [str xzr, [sp, #0x20]; stp q0, q0, [sp]; str w8, [sp, #0x48]; b #0x497b4]
uint64_t fde_sub_0911a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAD0003E0ULL) << 32) | 0xF90013FFULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0911A8ULL;
}

// FDE #3382 | PC: 0x0911b8..0x0911c8 (16 B) | Symbol: sub_0911b8
// EN: AArch64 prologue [mov x23, x0; add x0, sp, #0xb0; mov w1, #0x64; b #0x44ee4] | VI: Khởi đầu hàm AArch64 [mov x23, x0; add x0, sp, #0xb0; mov w1, #0x64; b #0x44ee4]
uint64_t fde_sub_0911b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9102C3E0ULL) << 32) | 0xAA0003F7ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0911B8ULL;
}

// FDE #3383 | PC: 0x0911c8..0x0911e0 (24 B) | Symbol: sub_0911c8
// EN: AArch64 prologue [ldr s0, [x20, #0x18]; mov x19, x20; scvtf s0, s0; fmul s0, s14, s0] | VI: Khởi đầu hàm AArch64 [ldr s0, [x20, #0x18]; mov x19, x20; scvtf s0, s0; fmul s0, s14, s0]
uint64_t fde_sub_0911c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403F3ULL) << 32) | 0xBD401A80ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0911C8ULL;
}

// FDE #3384 | PC: 0x0911e0..0x0911ec (12 B) | Symbol: sub_0911e0
// EN: AArch64 prologue [ldr w8, [x20, #0x18]; mov x19, x20; ret] | VI: Khởi đầu hàm AArch64 [ldr w8, [x20, #0x18]; mov x19, x20; ret]
uint64_t fde_sub_0911e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403F3ULL) << 32) | 0xB9401A88ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0911E0ULL;
}

// FDE #3385 | PC: 0x0911ec..0x0911fc (16 B) | Symbol: sub_0911ec
// EN: AArch64 prologue [mov x20, x2; mov x21, x1; mov x19, x0; b #0x5a9cc] | VI: Khởi đầu hàm AArch64 [mov x20, x2; mov x21, x1; mov x19, x0; b #0x5a9cc]
uint64_t fde_sub_0911ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103F5ULL) << 32) | 0xAA0203F4ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0911ECULL;
}

// FDE #3386 | PC: 0x0911fc..0x091208 (12 B) | Symbol: sub_0911fc
// EN: AArch64 prologue [cmp w8, #0xa; cset w8, eq; ret] | VI: Khởi đầu hàm AArch64 [cmp w8, #0xa; cset w8, eq; ret]
uint64_t fde_sub_0911fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1A9F17E8ULL) << 32) | 0x7100291FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0911FCULL;
}

// FDE #3387 | PC: 0x091208..0x091218 (16 B) | Symbol: sub_091208
// EN: AArch64 prologue [cmp w8, #0xa; cset w8, eq; str w8, [sp, #0x3c]; ret] | VI: Khởi đầu hàm AArch64 [cmp w8, #0xa; cset w8, eq; str w8, [sp, #0x3c]; ret]
uint64_t fde_sub_091208(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1A9F17E8ULL) << 32) | 0x7100291FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091208ULL;
}

// FDE #3388 | PC: 0x091218..0x091228 (16 B) | Symbol: sub_091218
// EN: AArch64 prologue [ldr x0, [x19, #0xb0]; add x1, sp, #0xb0; add x2, sp, #0x50; b #0x7988c] | VI: Khởi đầu hàm AArch64 [ldr x0, [x19, #0xb0]; add x1, sp, #0xb0; add x2, sp, #0x50; b #0x7988c]
uint64_t fde_sub_091218(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9102C3E1ULL) << 32) | 0xF9405A60ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091218ULL;
}

// FDE #3389 | PC: 0x091228..0x091240 (24 B) | Symbol: sub_091228
// EN: AArch64 prologue [ldr x8, [x20]; add x22, x24, #0x10; str x8, [sp, #0x18]; ldr x8, [x20, #8]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x20]; add x22, x24, #0x10; str x8, [sp, #0x18]; ldr x8, [x20, #8]]
uint64_t fde_sub_091228(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91004316ULL) << 32) | 0xF9400288ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091228ULL;
}

// FDE #3390 | PC: 0x091240..0x091258 (24 B) | Symbol: sub_091240
// EN: AArch64 prologue [mov x19, x1; mov x20, x0; mov x22, x0; add x0, x0, #8] | VI: Khởi đầu hàm AArch64 [mov x19, x1; mov x20, x0; mov x22, x0; add x0, x0, #8]
uint64_t fde_sub_091240(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F4ULL) << 32) | 0xAA0103F3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091240ULL;
}

// FDE #3391 | PC: 0x091258..0x091260 (8 B) | Symbol: sub_091258
// EN: AArch64 prologue [add sp, sp, #0x120; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0x120; ret]
uint64_t fde_sub_091258(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910483FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091258ULL;
}

// FDE #3392 | PC: 0x091260..0x091270 (16 B) | Symbol: sub_091260
// EN: AArch64 prologue [ldxr w10, [x9]; add w10, w10, #1; stxr w11, w10, [x9]; ret] | VI: Khởi đầu hàm AArch64 [ldxr w10, [x9]; add w10, w10, #1; stxr w11, w10, [x9]; ret]
uint64_t fde_sub_091260(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1100054AULL) << 32) | 0x885F7D2AULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091260ULL;
}

// FDE #3393 | PC: 0x091270..0x091278 (8 B) | Symbol: sub_091270
// EN: AArch64 prologue [add x1, x8, #0x28; b #0x4647c] | VI: Khởi đầu hàm AArch64 [add x1, x8, #0x28; b #0x4647c]
uint64_t fde_sub_091270(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED482ULL) << 32) | 0x9100A101ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091270ULL;
}

// FDE #3394 | PC: 0x091278..0x091288 (16 B) | Symbol: sub_091278
// EN: AArch64 prologue [mov x2, x0; mov x0, x20; mov x1, x21; b #0x7cca4] | VI: Khởi đầu hàm AArch64 [mov x2, x0; mov x0, x20; mov x1, x21; b #0x7cca4]
uint64_t fde_sub_091278(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0xAA0003E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091278ULL;
}

// FDE #3395 | PC: 0x091288..0x091298 (16 B) | Symbol: sub_091288
// EN: AArch64 prologue [mov x2, x0; mov x0, x20; mov x1, x19; b #0x7ce48] | VI: Khởi đầu hàm AArch64 [mov x2, x0; mov x0, x20; mov x1, x19; b #0x7ce48]
uint64_t fde_sub_091288(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0xAA0003E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091288ULL;
}

// FDE #3396 | PC: 0x091298..0x0912a8 (16 B) | Symbol: sub_091298
// EN: AArch64 prologue [mov x2, x0; mov x0, x26; mov x1, x25; b #0x7ce48] | VI: Khởi đầu hàm AArch64 [mov x2, x0; mov x0, x26; mov x1, x25; b #0x7ce48]
uint64_t fde_sub_091298(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1A03E0ULL) << 32) | 0xAA0003E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091298ULL;
}

// FDE #3397 | PC: 0x0912a8..0x0912b8 (16 B) | Symbol: sub_0912a8
// EN: AArch64 prologue [mov x2, x0; mov x0, x25; mov x1, x24; b #0x7d6e4] | VI: Khởi đầu hàm AArch64 [mov x2, x0; mov x0, x25; mov x1, x24; b #0x7d6e4]
uint64_t fde_sub_0912a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1903E0ULL) << 32) | 0xAA0003E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0912A8ULL;
}

// FDE #3398 | PC: 0x0912b8..0x0912c8 (16 B) | Symbol: sub_0912b8
// EN: AArch64 prologue [ldr x0, [x19, #8]; adrp x1, #0x1f000; add x1, x1, #0x84e; b #0x4696c] | VI: Khởi đầu hàm AArch64 [ldr x0, [x19, #8]; adrp x1, #0x1f000; add x1, x1, #0x84e; b #0x4696c]
uint64_t fde_sub_0912b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0FFFC61ULL) << 32) | 0xF9400660ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0912B8ULL;
}

// FDE #3399 | PC: 0x0912c8..0x0912d8 (16 B) | Symbol: sub_0912c8
// EN: AArch64 prologue [ldr x0, [x19, #8]; adrp x1, #0x1f000; add x1, x1, #0x79a; b #0x4696c] | VI: Khởi đầu hàm AArch64 [ldr x0, [x19, #8]; adrp x1, #0x1f000; add x1, x1, #0x79a; b #0x4696c]
uint64_t fde_sub_0912c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0FFFC61ULL) << 32) | 0xF9400660ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0912C8ULL;
}

// FDE #3400 | PC: 0x0912d8..0x0912e8 (16 B) | Symbol: sub_0912d8
// EN: AArch64 prologue [ldr x27, [sp, #0xa0]; mov w0, #0x18; str x27, [sp, #0x18]; b #0x93320] | VI: Khởi đầu hàm AArch64 [ldr x27, [sp, #0xa0]; mov w0, #0x18; str x27, [sp, #0x18]; b #0x93320]
uint64_t fde_sub_0912d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800300ULL) << 32) | 0xF94053FBULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0912D8ULL;
}

// FDE #3401 | PC: 0x0912e8..0x0912f8 (16 B) | Symbol: sub_0912e8
// EN: AArch64 prologue [add x0, sp, #0x28; add x1, sp, #0x68; str s8, [sp, #0xa0]; b #0x77910] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x28; add x1, sp, #0x68; str s8, [sp, #0xa0]; b #0x77910]
uint64_t fde_sub_0912e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9101A3E1ULL) << 32) | 0x9100A3E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0912E8ULL;
}

// FDE #3402 | PC: 0x0912f8..0x091310 (24 B) | Symbol: sub_0912f8
// EN: AArch64 prologue [stp xzr, xzr, [sp, #0x20]; strb w19, [x0, #0x18]; str x8, [x0]; stur q0, [x0, #8]] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [sp, #0x20]; strb w19, [x0, #0x18]; str x8, [x0]; stur q0, [x0, #8]]
uint64_t fde_sub_0912f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39006013ULL) << 32) | 0xA9027FFFULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0912F8ULL;
}

// FDE #3403 | PC: 0x091310..0x091320 (16 B) | Symbol: sub_091310
// EN: AArch64 prologue [mov x21, x2; mov x19, x1; mov x20, x0; b #0x5a9cc] | VI: Khởi đầu hàm AArch64 [mov x21, x2; mov x19, x1; mov x20, x0; b #0x5a9cc]
uint64_t fde_sub_091310(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103F3ULL) << 32) | 0xAA0203F5ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091310ULL;
}

// FDE #3404 | PC: 0x091320..0x091328 (8 B) | Symbol: sub_091320
// EN: AArch64 prologue [add x0, sp, #0x80; b #0x46c54] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x80; b #0x46c54]
uint64_t fde_sub_091320(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED64CULL) << 32) | 0x910203E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091320ULL;
}

// FDE #3405 | PC: 0x091328..0x091338 (16 B) | Symbol: sub_091328
// EN: AArch64 prologue [add x0, sp, #0x80; add x1, sp, #0x98; add x2, sp, #0xb0; b #0x7c00c] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x80; add x1, sp, #0x98; add x2, sp, #0xb0; b #0x7c00c]
uint64_t fde_sub_091328(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910263E1ULL) << 32) | 0x910203E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091328ULL;
}

// FDE #3406 | PC: 0x091338..0x091340 (8 B) | Symbol: sub_091338
// EN: AArch64 prologue [add x1, sp, #0x58; b #0x7bbfc] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0x58; b #0x7bbfc]
uint64_t fde_sub_091338(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFAA30ULL) << 32) | 0x910163E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091338ULL;
}

// FDE #3407 | PC: 0x091340..0x091348 (8 B) | Symbol: sub_091340
// EN: AArch64 prologue [mov w3, wzr; b #0x5b2ec] | VI: Khởi đầu hàm AArch64 [mov w3, wzr; b #0x5b2ec]
uint64_t fde_sub_091340(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF27EAULL) << 32) | 0x2A1F03E3ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091340ULL;
}

// FDE #3408 | PC: 0x091348..0x091358 (16 B) | Symbol: sub_091348
// EN: AArch64 prologue [stp xzr, xzr, [x1, #0x10]; str xzr, [x1, #0x20]; mov x1, x2; b #0x547d0] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x1, #0x10]; str xzr, [x1, #0x20]; mov x1, x2; b #0x547d0]
uint64_t fde_sub_091348(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900103FULL) << 32) | 0xA9017C3FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091348ULL;
}

// FDE #3409 | PC: 0x091358..0x091368 (16 B) | Symbol: sub_091358
// EN: AArch64 prologue [ldr x11, [x22, #-8]!; str xzr, [x22]; str x11, [x9, #-8]!; ret] | VI: Khởi đầu hàm AArch64 [ldr x11, [x22, #-8]!; str xzr, [x22]; str x11, [x9, #-8]!; ret]
uint64_t fde_sub_091358(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90002DFULL) << 32) | 0xF85F8ECBULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091358ULL;
}

// FDE #3410 | PC: 0x091368..0x091374 (12 B) | Symbol: sub_091368
// EN: AArch64 prologue [mov x1, x21; mov x2, x20; ret] | VI: Khởi đầu hàm AArch64 [mov x1, x21; mov x2, x20; ret]
uint64_t fde_sub_091368(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E2ULL) << 32) | 0xAA1503E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091368ULL;
}

// FDE #3411 | PC: 0x091374..0x091384 (16 B) | Symbol: sub_091374
// EN: AArch64 prologue [mov x1, x21; cmp x8, #0; csel x2, x23, x8, eq; b #0x83204] | VI: Khởi đầu hàm AArch64 [mov x1, x21; cmp x8, #0; csel x2, x23, x8, eq; b #0x83204]
uint64_t fde_sub_091374(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF100011FULL) << 32) | 0xAA1503E1ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091374ULL;
}

// FDE #3412 | PC: 0x091384..0x09139c (24 B) | Symbol: sub_091384
// EN: AArch64 prologue [ldr x8, [x8]; mov x19, xzr; mov x22, xzr; mov x23, xzr] | VI: Khởi đầu hàm AArch64 [ldr x8, [x8]; mov x19, xzr; mov x22, xzr; mov x23, xzr]
uint64_t fde_sub_091384(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03F3ULL) << 32) | 0xF9400108ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091384ULL;
}

// FDE #3413 | PC: 0x09139c..0x0913b8 (28 B) | Symbol: sub_09139c
// EN: AArch64 prologue [ldp x20, x19, [sp, #0x60]; ldp x22, x21, [sp, #0x50]; ldp x24, x23, [sp, #0x40]; ldp x26, x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0x60]; ldp x22, x21, [sp, #0x50]; ldp x24, x23, [sp, #0x40]; ldp x26, x25, [sp, #0x30]]
uint64_t fde_sub_09139c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94557F6ULL) << 32) | 0xA9464FF4ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09139CULL;
}

// FDE #3414 | PC: 0x0913b8..0x0913d4 (28 B) | Symbol: sub_0913b8
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_0913b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9026FFCULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0913B8ULL;
}

// FDE #3415 | PC: 0x0913d4..0x0913e4 (16 B) | Symbol: sub_0913d4
// EN: AArch64 prologue [ldr x0, [x23, #8]; fcvtzs w8, s0; scvtf s8, w8; b #0x8b858] | VI: Khởi đầu hàm AArch64 [ldr x0, [x23, #8]; fcvtzs w8, s0; scvtf s8, w8; b #0x8b858]
uint64_t fde_sub_0913d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E380008ULL) << 32) | 0xF94006E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0913D4ULL;
}

// FDE #3416 | PC: 0x0913e4..0x0913f0 (12 B) | Symbol: sub_0913e4
// EN: AArch64 prologue [ldr x8, [x21, #0x10]; ldr q0, [x21]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x21, #0x10]; ldr q0, [x21]; ret]
uint64_t fde_sub_0913e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC002A0ULL) << 32) | 0xF9400AA8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0913E4ULL;
}

// FDE #3417 | PC: 0x0913f0..0x091418 (40 B) | Symbol: sub_0913f0
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; ldr x8, [x21, #0x10]; ldr q0, [x21]; mov x0, x21] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; ldr x8, [x21, #0x10]; ldr q0, [x21]; mov x0, x21]
uint64_t fde_sub_0913f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400AA8ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0913F0ULL;
}

// FDE #3418 | PC: 0x091418..0x091420 (8 B) | Symbol: sub_091418
// EN: AArch64 prologue [add x0, sp, #0x110; b #0x46c54] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x110; b #0x46c54]
uint64_t fde_sub_091418(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED60EULL) << 32) | 0x910443E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091418ULL;
}

// FDE #3419 | PC: 0x091420..0x091430 (16 B) | Symbol: sub_091420
// EN: AArch64 prologue [adrp x1, #0x1c000; add x1, x1, #0xcbf; add x0, sp, #0x110; ret] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x1c000; add x1, x1, #0xcbf; add x0, sp, #0x110; ret]
uint64_t fde_sub_091420(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9132FC21ULL) << 32) | 0xF0FFFC41ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091420ULL;
}

// FDE #3420 | PC: 0x091430..0x091448 (24 B) | Symbol: sub_091430
// EN: AArch64 prologue [ldr x8, [x22, #0x10]; sub x9, x21, x24; asr x23, x9, #2; sub x9, x8, x2] | VI: Khởi đầu hàm AArch64 [ldr x8, [x22, #0x10]; sub x9, x21, x24; asr x23, x9, #2; sub x9, x8, x2]
uint64_t fde_sub_091430(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xCB1802A9ULL) << 32) | 0xF9400AC8ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091430ULL;
}

// FDE #3421 | PC: 0x091448..0x091460 (24 B) | Symbol: sub_091448
// EN: AArch64 prologue [ldp x21, x19, [x2]; mov x22, x6; mov x24, x5; mov w20, w3] | VI: Khởi đầu hàm AArch64 [ldp x21, x19, [x2]; mov x22, x6; mov x24, x5; mov w20, w3]
uint64_t fde_sub_091448(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0603F6ULL) << 32) | 0xA9404C55ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091448ULL;
}

// FDE #3422 | PC: 0x091460..0x091478 (24 B) | Symbol: sub_091460
// EN: AArch64 prologue [ldr x8, [x21, #0x28]; mov x19, x1; add x1, x0, #8; mov x0, sp] | VI: Khởi đầu hàm AArch64 [ldr x8, [x21, #0x28]; mov x19, x1; add x1, x0, #8; mov x0, sp]
uint64_t fde_sub_091460(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103F3ULL) << 32) | 0xF94016A8ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091460ULL;
}

// FDE #3423 | PC: 0x091478..0x091490 (24 B) | Symbol: sub_091478
// EN: AArch64 prologue [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; mov x19, x1; mov x20, x0] | VI: Khởi đầu hàm AArch64 [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; mov x19, x1; mov x20, x0]
uint64_t fde_sub_091478(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016A8ULL) << 32) | 0xD53BD055ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091478ULL;
}

// FDE #3424 | PC: 0x091490..0x0914a8 (24 B) | Symbol: sub_091490
// EN: AArch64 prologue [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; mov x20, x0; mov x0, x1] | VI: Khởi đầu hàm AArch64 [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; mov x20, x0; mov x0, x1]
uint64_t fde_sub_091490(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016A8ULL) << 32) | 0xD53BD055ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091490ULL;
}

// FDE #3425 | PC: 0x0914a8..0x0914b8 (16 B) | Symbol: sub_0914a8
// EN: AArch64 prologue [mov w1, wzr; mov x2, x20; mov x21, x0; b #0x93200] | VI: Khởi đầu hàm AArch64 [mov w1, wzr; mov x2, x20; mov x21, x0; b #0x93200]
uint64_t fde_sub_0914a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E2ULL) << 32) | 0x2A1F03E1ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0914A8ULL;
}

// FDE #3426 | PC: 0x0914b8..0x0914c0 (8 B) | Symbol: sub_0914b8
// EN: AArch64 prologue [mov w1, wzr; b #0x771d4] | VI: Khởi đầu hàm AArch64 [mov w1, wzr; b #0x771d4]
uint64_t fde_sub_0914b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF9746ULL) << 32) | 0x2A1F03E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0914B8ULL;
}

// FDE #3427 | PC: 0x0914c0..0x0914d0 (16 B) | Symbol: sub_0914c0
// EN: AArch64 prologue [ldr x2, [sp, #8]; mov x0, x19; mov x1, x20; b #0x93900] | VI: Khởi đầu hàm AArch64 [ldr x2, [sp, #8]; mov x0, x19; mov x1, x20; b #0x93900]
uint64_t fde_sub_0914c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0xF94007E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0914C0ULL;
}

// FDE #3428 | PC: 0x0914d0..0x0914dc (12 B) | Symbol: sub_0914d0
// EN: AArch64 prologue [ldr x19, [x19, #0x98]; ldrb w8, [x19, #0x24]; ret] | VI: Khởi đầu hàm AArch64 [ldr x19, [x19, #0x98]; ldrb w8, [x19, #0x24]; ret]
uint64_t fde_sub_0914d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39409268ULL) << 32) | 0xF9404E73ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0914D0ULL;
}

// FDE #3429 | PC: 0x0914dc..0x0914ec (16 B) | Symbol: sub_0914dc
// EN: AArch64 prologue [ldr x19, [x19, #0x98]; add x0, sp, #0x80; add x1, sp, #0x188; b #0x547dc] | VI: Khởi đầu hàm AArch64 [ldr x19, [x19, #0x98]; add x0, sp, #0x80; add x1, sp, #0x188; b #0x547dc]
uint64_t fde_sub_0914dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910203E0ULL) << 32) | 0xF9404E73ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0914DCULL;
}

// FDE #3430 | PC: 0x0914ec..0x0914f8 (12 B) | Symbol: sub_0914ec
// EN: AArch64 prologue [ldr x0, [x20, #0x10]; add x1, sp, #8; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x20, #0x10]; add x1, sp, #8; ret]
uint64_t fde_sub_0914ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910023E1ULL) << 32) | 0xF9400A80ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0914ECULL;
}

// FDE #3431 | PC: 0x0914f8..0x091508 (16 B) | Symbol: sub_0914f8
// EN: AArch64 prologue [fmov s0, w23; fmov s1, w22; ldr x0, [x8, #8]; b #0x8c240] | VI: Khởi đầu hàm AArch64 [fmov s0, w23; fmov s1, w22; ldr x0, [x8, #8]; b #0x8c240]
uint64_t fde_sub_0914f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E2702C1ULL) << 32) | 0x1E2702E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0914F8ULL;
}

// FDE #3432 | PC: 0x091508..0x091518 (16 B) | Symbol: sub_091508
// EN: AArch64 prologue [add x8, sp, #0x30; add x0, x8, #0x60; add x1, sp, #8; b #0x4c7e0] | VI: Khởi đầu hàm AArch64 [add x8, sp, #0x30; add x0, x8, #0x60; add x1, sp, #8; b #0x4c7e0]
uint64_t fde_sub_091508(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91018100ULL) << 32) | 0x9100C3E8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091508ULL;
}

// FDE #3433 | PC: 0x091518..0x091538 (32 B) | Symbol: sub_091518
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; mov v0.16b, v9.16b; mov v1.16b, v10.16b; ldr x0, [x8, #8]] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; mov v0.16b, v9.16b; mov v1.16b, v10.16b; ldr x0, [x8, #8]]
uint64_t fde_sub_091518(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4EA91D20ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091518ULL;
}

// FDE #3434 | PC: 0x091538..0x091540 (8 B) | Symbol: sub_091538
// EN: AArch64 prologue [ldr x0, [x8, #8]; b #0x8bd30] | VI: Khởi đầu hàm AArch64 [ldr x0, [x8, #8]; b #0x8bd30]
uint64_t fde_sub_091538(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFE9FDULL) << 32) | 0xF9400500ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091538ULL;
}

// FDE #3435 | PC: 0x091540..0x091558 (24 B) | Symbol: sub_091540
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; ldr x0, [x8, #8]; bl #0x8c240; ldr x8, [x20, #0x1a8]] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; ldr x0, [x8, #8]; bl #0x8c240; ldr x8, [x20, #0x1a8]]
uint64_t fde_sub_091540(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400500ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091540ULL;
}

// FDE #3436 | PC: 0x091558..0x091568 (16 B) | Symbol: sub_091558
// EN: AArch64 prologue [adrp x0, #0xa0000; add x0, x0, #0x8c8; mov w1, #1; b #0x73e58] | VI: Khởi đầu hàm AArch64 [adrp x0, #0xa0000; add x0, x0, #0x8c8; mov w1, #1; b #0x73e58]
uint64_t fde_sub_091558(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91232000ULL) << 32) | 0xF0000060ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091558ULL;
}

// FDE #3437 | PC: 0x091568..0x091580 (24 B) | Symbol: sub_091568
// EN: AArch64 prologue [ldr x8, [x19, #0x48]; ldur q0, [x19, #0x38]; add x0, x19, #0x38; str x8, [x20, #0x48]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x19, #0x48]; ldur q0, [x19, #0x38]; add x0, x19, #0x38; str x8, [x20, #0x48]]
uint64_t fde_sub_091568(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3CC38260ULL) << 32) | 0xF9402668ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091568ULL;
}

// FDE #3438 | PC: 0x091580..0x091588 (8 B) | Symbol: sub_091580
// EN: AArch64 prologue [add x0, sp, #0x170; b #0x937a0] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x170; b #0x937a0]
uint64_t fde_sub_091580(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000887ULL) << 32) | 0x9105C3E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091580ULL;
}

// FDE #3439 | PC: 0x091588..0x0915a0 (24 B) | Symbol: sub_091588
// EN: AArch64 prologue [ldr x8, [x19, #0x40]; ldr q0, [x19, #0x30]; add x0, x19, #0x30; str x8, [x20, #0x40]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x19, #0x40]; ldr q0, [x19, #0x30]; add x0, x19, #0x30; str x8, [x20, #0x40]]
uint64_t fde_sub_091588(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC00E60ULL) << 32) | 0xF9402268ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091588ULL;
}

// FDE #3440 | PC: 0x0915a0..0x0915a8 (8 B) | Symbol: sub_0915a0
// EN: AArch64 prologue [mov w0, #0x60; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov w0, #0x60; b #0x93320]
uint64_t fde_sub_0915a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400075FULL) << 32) | 0x52800C00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0915A0ULL;
}

// FDE #3441 | PC: 0x0915a8..0x0915c0 (24 B) | Symbol: sub_0915a8
// EN: AArch64 prologue [mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; str x8, [sp, #0x18]; ldr q0, [x1]] | VI: Khởi đầu hàm AArch64 [mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; str x8, [sp, #0x18]; ldr q0, [x1]]
uint64_t fde_sub_0915a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401668ULL) << 32) | 0xD53BD053ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0915A8ULL;
}

// FDE #3442 | PC: 0x0915c0..0x0915d0 (16 B) | Symbol: sub_0915c0
// EN: AArch64 prologue [add x8, sp, #0xa0; mov x0, x20; mov x1, x19; b #0x93e00] | VI: Khởi đầu hàm AArch64 [add x8, sp, #0xa0; mov x0, x20; mov x1, x19; b #0x93e00]
uint64_t fde_sub_0915c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0x910283E8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0915C0ULL;
}

// FDE #3443 | PC: 0x0915d0..0x0915d8 (8 B) | Symbol: sub_0915d0
// EN: AArch64 prologue [ldr x0, [x8]; b #0x8bb58] | VI: Khởi đầu hàm AArch64 [ldr x0, [x8]; b #0x8bb58]
uint64_t fde_sub_0915d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFE961ULL) << 32) | 0xF9400100ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0915D0ULL;
}

// FDE #3444 | PC: 0x0915d8..0x0915e0 (8 B) | Symbol: sub_0915d8
// EN: AArch64 prologue [mov w2, wzr; b #0x93c30] | VI: Khởi đầu hàm AArch64 [mov w2, wzr; b #0x93c30]
uint64_t fde_sub_0915d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000995ULL) << 32) | 0x2A1F03E2ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0915D8ULL;
}

// FDE #3445 | PC: 0x0915e0..0x0915f0 (16 B) | Symbol: sub_0915e0
// EN: AArch64 prologue [ldr x0, [x0, #8]; add x1, sp, #0x10; mov x2, sp; b #0x4eac8] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #8]; add x1, sp, #0x10; mov x2, sp; b #0x4eac8]
uint64_t fde_sub_0915e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910043E1ULL) << 32) | 0xF9400400ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0915E0ULL;
}

// FDE #3446 | PC: 0x0915f0..0x0915f8 (8 B) | Symbol: sub_0915f0
// EN: AArch64 prologue [mov w0, #0x50; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov w0, #0x50; b #0x93320]
uint64_t fde_sub_0915f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400074BULL) << 32) | 0x52800A00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0915F0ULL;
}

// FDE #3447 | PC: 0x0915f8..0x091608 (16 B) | Symbol: sub_0915f8
// EN: AArch64 prologue [mov x0, x20; mov x1, x21; mov x2, x19; b #0x69a74] | VI: Khởi đầu hàm AArch64 [mov x0, x20; mov x1, x21; mov x2, x19; b #0x69a74]
uint64_t fde_sub_0915f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E1ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0915F8ULL;
}

// FDE #3448 | PC: 0x091608..0x091618 (16 B) | Symbol: sub_091608
// EN: AArch64 prologue [mov x0, x20; mov x5, x23; mov w24, #1; b #0x93c30] | VI: Khởi đầu hàm AArch64 [mov x0, x20; mov x5, x23; mov w24, #1; b #0x93c30]
uint64_t fde_sub_091608(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1703E5ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091608ULL;
}

// FDE #3449 | PC: 0x091618..0x091630 (24 B) | Symbol: sub_091618
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; mov x0, x20; bl #0x44b18; mov x0, x19] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; mov x0, x20; bl #0x44b18; mov x0, x19]
uint64_t fde_sub_091618(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091618ULL;
}

// FDE #3450 | PC: 0x091630..0x091638 (8 B) | Symbol: sub_091630
// EN: AArch64 prologue [mov x0, x20; b #0x44830] | VI: Khởi đầu hàm AArch64 [mov x0, x20; b #0x44830]
uint64_t fde_sub_091630(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FECC7FULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091630ULL;
}

// FDE #3451 | PC: 0x091638..0x091650 (24 B) | Symbol: sub_091638
// EN: AArch64 prologue [mov x0, x20; mov x1, x19; mov x2, x24; mov x3, x26] | VI: Khởi đầu hàm AArch64 [mov x0, x20; mov x1, x19; mov x2, x24; mov x3, x26]
uint64_t fde_sub_091638(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E1ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091638ULL;
}

// FDE #3452 | PC: 0x091650..0x091658 (8 B) | Symbol: sub_091650
// EN: AArch64 prologue [mov x0, x20; b #0x48da4] | VI: Khởi đầu hàm AArch64 [mov x0, x20; b #0x48da4]
uint64_t fde_sub_091650(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDDD4ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091650ULL;
}

// FDE #3453 | PC: 0x091658..0x091668 (16 B) | Symbol: sub_091658
// EN: AArch64 prologue [adrp x1, #0x1c000; add x1, x1, #0xf74; add x0, sp, #0x168; ret] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x1c000; add x1, x1, #0xf74; add x0, sp, #0x168; ret]
uint64_t fde_sub_091658(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x913DD021ULL) << 32) | 0xF0FFFC41ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091658ULL;
}

// FDE #3454 | PC: 0x091668..0x091674 (12 B) | Symbol: sub_091668
// EN: AArch64 prologue [str x20, [x19]; ldr x0, [sp, #8]; ret] | VI: Khởi đầu hàm AArch64 [str x20, [x19]; ldr x0, [sp, #8]; ret]
uint64_t fde_sub_091668(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E0ULL) << 32) | 0xF9000274ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091668ULL;
}

// FDE #3455 | PC: 0x091674..0x091684 (16 B) | Symbol: sub_091674
// EN: AArch64 prologue [add x0, sp, #0x18; str x19, [sp, #0x10]; add x20, sp, #0x18; b #0x497b4] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x18; str x19, [sp, #0x10]; add x20, sp, #0x18; b #0x497b4]
uint64_t fde_sub_091674(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF3ULL) << 32) | 0x910063E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091674ULL;
}

// FDE #3456 | PC: 0x091684..0x091690 (12 B) | Symbol: sub_091684
// EN: AArch64 prologue [add x1, x1, #0xc99; add x0, sp, #0x20; ret] | VI: Khởi đầu hàm AArch64 [add x1, x1, #0xc99; add x0, sp, #0x20; ret]
uint64_t fde_sub_091684(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910083E0ULL) << 32) | 0x91326421ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091684ULL;
}

// FDE #3457 | PC: 0x091690..0x091698 (8 B) | Symbol: sub_091690
// EN: AArch64 prologue [add x21, sp, #8; b #0x49290] | VI: Khởi đầu hàm AArch64 [add x21, sp, #8; b #0x49290]
uint64_t fde_sub_091690(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDEFFULL) << 32) | 0x910023F5ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091690ULL;
}

// FDE #3458 | PC: 0x091698..0x0916a8 (16 B) | Symbol: sub_091698
// EN: AArch64 prologue [adrp x1, #0x1c000; add x1, x1, #0xc75; add x0, sp, #8; ret] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x1c000; add x1, x1, #0xc75; add x0, sp, #8; ret]
uint64_t fde_sub_091698(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9131D421ULL) << 32) | 0xF0FFFC41ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091698ULL;
}

// FDE #3459 | PC: 0x0916a8..0x0916b0 (8 B) | Symbol: sub_0916a8
// EN: AArch64 prologue [mov x1, x27; b #0x93910] | VI: Khởi đầu hàm AArch64 [mov x1, x27; b #0x93910]
uint64_t fde_sub_0916a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000899ULL) << 32) | 0xAA1B03E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0916A8ULL;
}

// FDE #3460 | PC: 0x0916b0..0x0916c0 (16 B) | Symbol: sub_0916b0
// EN: AArch64 prologue [ldr w8, [x28, #0x18]; cmp w8, #1; cset w8, ne; ret] | VI: Khởi đầu hàm AArch64 [ldr w8, [x28, #0x18]; cmp w8, #1; cset w8, ne; ret]
uint64_t fde_sub_0916b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100051FULL) << 32) | 0xB9401B88ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0916B0ULL;
}

// FDE #3461 | PC: 0x0916c0..0x0916c8 (8 B) | Symbol: sub_0916c0
// EN: AArch64 prologue [add x1, x1, #0xb6e; b #0x93910] | VI: Khởi đầu hàm AArch64 [add x1, x1, #0xb6e; b #0x93910]
uint64_t fde_sub_0916c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000893ULL) << 32) | 0x912DB821ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0916C0ULL;
}

// FDE #3462 | PC: 0x0916c8..0x0916d0 (8 B) | Symbol: sub_0916c8
// EN: AArch64 prologue [add x1, x19, #0x28; b #0x470b8] | VI: Khởi đầu hàm AArch64 [add x1, x19, #0x28; b #0x470b8]
uint64_t fde_sub_0916c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED67BULL) << 32) | 0x9100A261ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0916C8ULL;
}

// FDE #3463 | PC: 0x0916d0..0x0916e0 (16 B) | Symbol: sub_0916d0
// EN: AArch64 prologue [ldr x8, [x20, #0x20]; mov x19, x20; str x20, [sp, #0xe8]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x20, #0x20]; mov x19, x20; str x20, [sp, #0xe8]; ret]
uint64_t fde_sub_0916d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403F3ULL) << 32) | 0xF9401288ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0916D0ULL;
}

// FDE #3464 | PC: 0x0916e0..0x0916f0 (16 B) | Symbol: sub_0916e0
// EN: AArch64 prologue [stp x9, x10, [x0, #0x10]; str x0, [x22]; ldr x22, [sp], #0x30; ret] | VI: Khởi đầu hàm AArch64 [stp x9, x10, [x0, #0x10]; str x0, [x22]; ldr x22, [sp], #0x30; ret]
uint64_t fde_sub_0916e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90002C0ULL) << 32) | 0xA9012809ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0916E0ULL;
}

// FDE #3465 | PC: 0x0916f0..0x091700 (16 B) | Symbol: sub_0916f0
// EN: AArch64 prologue [mov v8.16b, v2.16b; mov v9.16b, v1.16b; mov v10.16b, v0.16b; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov v8.16b, v2.16b; mov v9.16b, v1.16b; mov v10.16b, v0.16b; b #0x93320]
uint64_t fde_sub_0916f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4EA11C29ULL) << 32) | 0x4EA21C48ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0916F0ULL;
}

// FDE #3466 | PC: 0x091700..0x091718 (24 B) | Symbol: sub_091700
// EN: AArch64 prologue [ldrb w9, [x8, #0x1c]; add x8, x8, #0x18; cmp w9, #0; csel x8, x10, x8, eq] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x8, #0x1c]; add x8, x8, #0x18; cmp w9, #0; csel x8, x10, x8, eq]
uint64_t fde_sub_091700(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91006108ULL) << 32) | 0x39407109ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091700ULL;
}

// FDE #3467 | PC: 0x091718..0x091724 (12 B) | Symbol: sub_091718
// EN: AArch64 prologue [mov v9.16b, v2.16b; mov v10.16b, v1.16b; ret] | VI: Khởi đầu hàm AArch64 [mov v9.16b, v2.16b; mov v10.16b, v1.16b; ret]
uint64_t fde_sub_091718(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4EA11C2AULL) << 32) | 0x4EA21C49ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091718ULL;
}

// FDE #3468 | PC: 0x091724..0x09173c (24 B) | Symbol: sub_091724
// EN: AArch64 prologue [fmul s0, s0, s8; add x0, sp, #0xe0; add x1, sp, #0xc0; add x2, sp, #0x98] | VI: Khởi đầu hàm AArch64 [fmul s0, s0, s8; add x0, sp, #0xe0; add x1, sp, #0xc0; add x2, sp, #0x98]
uint64_t fde_sub_091724(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910383E0ULL) << 32) | 0x1E280800ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091724ULL;
}

// FDE #3469 | PC: 0x09173c..0x091754 (24 B) | Symbol: sub_09173c
// EN: AArch64 prologue [fdiv d0, d0, d2; fmov d1, x8; fmul d0, d0, d1; frinta d0, d0] | VI: Khởi đầu hàm AArch64 [fdiv d0, d0, d2; fmov d1, x8; fmul d0, d0, d1; frinta d0, d0]
uint64_t fde_sub_09173c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9E670101ULL) << 32) | 0x1E621800ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09173CULL;
}

// FDE #3470 | PC: 0x091754..0x09176c (24 B) | Symbol: sub_091754
// EN: AArch64 prologue [adrp x5, #0xa0000; add x5, x5, #0x1e8; ldr x20, [x20, #8]; ldr x21, [sp, #0x38]] | VI: Khởi đầu hàm AArch64 [adrp x5, #0xa0000; add x5, x5, #0x1e8; ldr x20, [x20, #8]; ldr x21, [sp, #0x38]]
uint64_t fde_sub_091754(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9107A0A5ULL) << 32) | 0xF0000065ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091754ULL;
}

// FDE #3471 | PC: 0x09176c..0x091778 (12 B) | Symbol: sub_09176c
// EN: AArch64 prologue [add x20, x26, #0x10; mov x29, x26; ret] | VI: Khởi đầu hàm AArch64 [add x20, x26, #0x10; mov x29, x26; ret]
uint64_t fde_sub_09176c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1A03FDULL) << 32) | 0x91004354ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09176CULL;
}

// FDE #3472 | PC: 0x091778..0x091784 (12 B) | Symbol: sub_091778
// EN: AArch64 prologue [udiv x8, x27, x19; msub x27, x8, x19, x27; ret] | VI: Khởi đầu hàm AArch64 [udiv x8, x27, x19; msub x27, x8, x19, x27; ret]
uint64_t fde_sub_091778(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9B13ED1BULL) << 32) | 0x9AD30B68ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091778ULL;
}

// FDE #3473 | PC: 0x091784..0x091790 (12 B) | Symbol: sub_091784
// EN: AArch64 prologue [sub x8, x19, #1; and x24, x24, x8; ret] | VI: Khởi đầu hàm AArch64 [sub x8, x19, #1; and x24, x24, x8; ret]
uint64_t fde_sub_091784(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8A080318ULL) << 32) | 0xD1000668ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091784ULL;
}

// FDE #3474 | PC: 0x091790..0x09179c (12 B) | Symbol: sub_091790
// EN: AArch64 prologue [udiv x8, x24, x19; msub x24, x8, x19, x24; ret] | VI: Khởi đầu hàm AArch64 [udiv x8, x24, x19; msub x24, x8, x19, x24; ret]
uint64_t fde_sub_091790(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9B13E118ULL) << 32) | 0x9AD30B08ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091790ULL;
}

// FDE #3475 | PC: 0x09179c..0x0917a4 (8 B) | Symbol: sub_09179c
// EN: AArch64 prologue [mov x2, x21; b #0x6bab4] | VI: Khởi đầu hàm AArch64 [mov x2, x21; b #0x6bab4]
uint64_t fde_sub_09179c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF68C5ULL) << 32) | 0xAA1503E2ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09179CULL;
}

// FDE #3476 | PC: 0x0917a4..0x0917ac (8 B) | Symbol: sub_0917a4
// EN: AArch64 prologue [mov x1, x19; b #0x497ec] | VI: Khởi đầu hàm AArch64 [mov x1, x19; b #0x497ec]
uint64_t fde_sub_0917a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE011ULL) << 32) | 0xAA1303E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0917A4ULL;
}

// FDE #3477 | PC: 0x0917ac..0x0917c8 (28 B) | Symbol: sub_0917ac
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; ldr x8, [x19, #0x30]; ldr x0, [x8, #8]; bl #0x8c678] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; ldr x8, [x19, #0x30]; ldr x0, [x8, #8]; bl #0x8c678]
uint64_t fde_sub_0917ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401A68ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0917ACULL;
}

// FDE #3478 | PC: 0x0917c8..0x0917d8 (16 B) | Symbol: sub_0917c8
// EN: AArch64 prologue [ldr w8, [sp, #0x80]; mov x0, x20; and w21, w8, #1; b #0x649f8] | VI: Khởi đầu hàm AArch64 [ldr w8, [sp, #0x80]; mov x0, x20; and w21, w8, #1; b #0x649f8]
uint64_t fde_sub_0917c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0xB94083E8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0917C8ULL;
}

// FDE #3479 | PC: 0x0917d8..0x0917e8 (16 B) | Symbol: sub_0917d8
// EN: AArch64 prologue [mov x0, x22; mov w1, w21; str w21, [x19, #0x50]; b #0x5018c] | VI: Khởi đầu hàm AArch64 [mov x0, x22; mov w1, w21; str w21, [x19, #0x50]; b #0x5018c]
uint64_t fde_sub_0917d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1503E1ULL) << 32) | 0xAA1603E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0917D8ULL;
}

// FDE #3480 | PC: 0x0917e8..0x091800 (24 B) | Symbol: sub_0917e8
// EN: AArch64 prologue [mov x0, x22; mov x1, x25; mov x2, x21; sub x8, x9, x8] | VI: Khởi đầu hàm AArch64 [mov x0, x22; mov x1, x25; mov x2, x21; sub x8, x9, x8]
uint64_t fde_sub_0917e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1903E1ULL) << 32) | 0xAA1603E0ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0917E8ULL;
}

// FDE #3481 | PC: 0x091800..0x091808 (8 B) | Symbol: sub_091800
// EN: AArch64 prologue [mov x0, x22; b #0x48d40] | VI: Khởi đầu hàm AArch64 [mov x0, x22; b #0x48d40]
uint64_t fde_sub_091800(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDD4FULL) << 32) | 0xAA1603E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091800ULL;
}

// FDE #3482 | PC: 0x091808..0x091818 (16 B) | Symbol: sub_091808
// EN: AArch64 prologue [mrs x23, tpidr_el0; ldr x8, [x23, #0x28]; mov x21, x0; ret] | VI: Khởi đầu hàm AArch64 [mrs x23, tpidr_el0; ldr x8, [x23, #0x28]; mov x21, x0; ret]
uint64_t fde_sub_091808(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016E8ULL) << 32) | 0xD53BD057ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091808ULL;
}

// FDE #3483 | PC: 0x091818..0x091828 (16 B) | Symbol: sub_091818
// EN: AArch64 prologue [ldr x21, [x20, #0x18]; add x0, sp, #0x20; mov x1, x20; b #0x4b758] | VI: Khởi đầu hàm AArch64 [ldr x21, [x20, #0x18]; add x0, sp, #0x20; mov x1, x20; b #0x4b758]
uint64_t fde_sub_091818(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910083E0ULL) << 32) | 0xF9400E95ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091818ULL;
}

// FDE #3484 | PC: 0x091828..0x091838 (16 B) | Symbol: sub_091828
// EN: AArch64 prologue [adrp x8, #0x9c000; add x8, x8, #0x690; str x8, [x20]; ret] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9c000; add x8, x8, #0x690; str x8, [x20]; ret]
uint64_t fde_sub_091828(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911A4108ULL) << 32) | 0xF0000048ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091828ULL;
}

// FDE #3485 | PC: 0x091838..0x091844 (12 B) | Symbol: sub_091838
// EN: AArch64 prologue [stp x0, x0, [x20]; str x8, [x20, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [stp x0, x0, [x20]; str x8, [x20, #0x10]; ret]
uint64_t fde_sub_091838(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000A88ULL) << 32) | 0xA9000280ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091838ULL;
}

// FDE #3486 | PC: 0x091844..0x091854 (16 B) | Symbol: sub_091844
// EN: AArch64 prologue [add x1, x0, #0x28; add x2, x0, #0x48; mov x0, x8; b #0x5c240] | VI: Khởi đầu hàm AArch64 [add x1, x0, #0x28; add x2, x0, #0x48; mov x0, x8; b #0x5c240]
uint64_t fde_sub_091844(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91012002ULL) << 32) | 0x9100A001ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091844ULL;
}

// FDE #3487 | PC: 0x091854..0x09186c (24 B) | Symbol: sub_091854
// EN: AArch64 prologue [fmov s1, w9; fsub s0, s1, s0; fmul s0, s0, s11; cmp w8, #0] | VI: Khởi đầu hàm AArch64 [fmov s1, w9; fsub s0, s1, s0; fmul s0, s0, s11; cmp w8, #0]
uint64_t fde_sub_091854(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E203820ULL) << 32) | 0x1E270121ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091854ULL;
}

// FDE #3488 | PC: 0x09186c..0x091884 (24 B) | Symbol: sub_09186c
// EN: AArch64 prologue [cmp w9, #0; mov w9, #0x20; csel x10, x9, x10, eq; cmp w11, #0] | VI: Khởi đầu hàm AArch64 [cmp w9, #0; mov w9, #0x20; csel x10, x9, x10, eq; cmp w11, #0]
uint64_t fde_sub_09186c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800409ULL) << 32) | 0x7100013FULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09186CULL;
}

// FDE #3489 | PC: 0x091884..0x091894 (16 B) | Symbol: sub_091884
// EN: AArch64 prologue [mov w8, #-1; mov w9, #1; mov x0, xzr; ret] | VI: Khởi đầu hàm AArch64 [mov w8, #-1; mov w9, #1; mov x0, xzr; ret]
uint64_t fde_sub_091884(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800029ULL) << 32) | 0x12800008ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091884ULL;
}

// FDE #3490 | PC: 0x091894..0x0918a4 (16 B) | Symbol: sub_091894
// EN: AArch64 prologue [str x0, [sp, #8]; add x0, sp, #8; mov v0.16b, v8.16b; b #0x4e340] | VI: Khởi đầu hàm AArch64 [str x0, [sp, #8]; add x0, sp, #8; mov v0.16b, v8.16b; b #0x4e340]
uint64_t fde_sub_091894(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910023E0ULL) << 32) | 0xF90007E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091894ULL;
}

// FDE #3491 | PC: 0x0918a4..0x0918b8 (20 B) | Symbol: sub_0918a4
// EN: AArch64 prologue [cmp w8, #0; add x8, sp, #8; csel x8, x8, x9, eq; ldr d0, [x8]] | VI: Khởi đầu hàm AArch64 [cmp w8, #0; add x8, sp, #8; csel x8, x8, x9, eq; ldr d0, [x8]]
uint64_t fde_sub_0918a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910023E8ULL) << 32) | 0x7100011FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0918A4ULL;
}

// FDE #3492 | PC: 0x0918b8..0x0918c8 (16 B) | Symbol: sub_0918b8
// EN: AArch64 prologue [ldxr w9, [x8]; add w9, w9, #1; stxr w10, w9, [x8]; ret] | VI: Khởi đầu hàm AArch64 [ldxr w9, [x8]; add w9, w9, #1; stxr w10, w9, [x8]; ret]
uint64_t fde_sub_0918b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x11000529ULL) << 32) | 0x885F7D09ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0918B8ULL;
}

// FDE #3493 | PC: 0x0918c8..0x0918d8 (16 B) | Symbol: sub_0918c8
// EN: AArch64 prologue [mov w2, #1; mov x0, x20; mov x4, x24; ret] | VI: Khởi đầu hàm AArch64 [mov w2, #1; mov x0, x20; mov x4, x24; ret]
uint64_t fde_sub_0918c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0x52800022ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0918C8ULL;
}

// FDE #3494 | PC: 0x0918d8..0x0918e8 (16 B) | Symbol: sub_0918d8
// EN: AArch64 prologue [mov w2, #1; mov x0, x20; mov x4, x24; b #0x93c30] | VI: Khởi đầu hàm AArch64 [mov w2, #1; mov x0, x20; mov x4, x24; b #0x93c30]
uint64_t fde_sub_0918d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0x52800022ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0918D8ULL;
}

// FDE #3495 | PC: 0x0918e8..0x0918f8 (16 B) | Symbol: sub_0918e8
// EN: AArch64 prologue [mov w2, #1; mov x0, x20; mov x5, x23; b #0x93c30] | VI: Khởi đầu hàm AArch64 [mov w2, #1; mov x0, x20; mov x5, x23; b #0x93c30]
uint64_t fde_sub_0918e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0x52800022ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0918E8ULL;
}

// FDE #3496 | PC: 0x0918f8..0x091908 (16 B) | Symbol: sub_0918f8
// EN: AArch64 prologue [mov w2, #1; mov x5, x20; mov x22, x0; b #0x93c30] | VI: Khởi đầu hàm AArch64 [mov w2, #1; mov x5, x20; mov x22, x0; b #0x93c30]
uint64_t fde_sub_0918f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E5ULL) << 32) | 0x52800022ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0918F8ULL;
}

// FDE #3497 | PC: 0x091908..0x091920 (24 B) | Symbol: sub_091908
// EN: AArch64 prologue [ldr x8, [x19, #0x10]; ldr q0, [x19]; mov x0, x19; str x8, [x20, #0x10]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x19, #0x10]; ldr q0, [x19]; mov x0, x19; str x8, [x20, #0x10]]
uint64_t fde_sub_091908(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC00260ULL) << 32) | 0xF9400A68ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091908ULL;
}

// FDE #3498 | PC: 0x091920..0x091930 (16 B) | Symbol: sub_091920
// EN: AArch64 prologue [str x8, [x0, #0x10]; str q0, [x0]; mov x0, x1; b #0x47ff4] | VI: Khởi đầu hàm AArch64 [str x8, [x0, #0x10]; str q0, [x0]; mov x0, x1; b #0x47ff4]
uint64_t fde_sub_091920(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3D800000ULL) << 32) | 0xF9000808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091920ULL;
}

// FDE #3499 | PC: 0x091930..0x09193c (12 B) | Symbol: sub_091930
// EN: AArch64 prologue [ldr s0, [x0, #8]; ldrb w8, [x0, #0xc]; ret] | VI: Khởi đầu hàm AArch64 [ldr s0, [x0, #8]; ldrb w8, [x0, #0xc]; ret]
uint64_t fde_sub_091930(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39403008ULL) << 32) | 0xBD400800ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091930ULL;
}

// FDE #3500 | PC: 0x09193c..0x091944 (8 B) | Symbol: sub_09193c
// EN: AArch64 prologue [str x8, [x0]; b #0x94190] | VI: Khởi đầu hàm AArch64 [str x8, [x0]; b #0x94190]
uint64_t fde_sub_09193c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000A14ULL) << 32) | 0xF9000008ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09193CULL;
}

// FDE #3501 | PC: 0x091944..0x091950 (12 B) | Symbol: sub_091944
// EN: AArch64 prologue [str x8, [x0]; str x0, [sp, #8]; ret] | VI: Khởi đầu hàm AArch64 [str x8, [x0]; str x0, [sp, #8]; ret]
uint64_t fde_sub_091944(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90007E0ULL) << 32) | 0xF9000008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091944ULL;
}

// FDE #3502 | PC: 0x091950..0x091968 (24 B) | Symbol: sub_091950
// EN: AArch64 prologue [str x8, [x0]; add x8, x8, #0xa0; mov x19, x0; str x8, [x0, #0x28]] | VI: Khởi đầu hàm AArch64 [str x8, [x0]; add x8, x8, #0xa0; mov x19, x0; str x8, [x0, #0x28]]
uint64_t fde_sub_091950(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91028108ULL) << 32) | 0xF9000008ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091950ULL;
}

// FDE #3503 | PC: 0x091968..0x091978 (16 B) | Symbol: sub_091968
// EN: AArch64 prologue [ldr s1, [x20, x8]; mov v0.16b, v1.16b; mov v1.16b, v8.16b; b #0x933d0] | VI: Khởi đầu hàm AArch64 [ldr s1, [x20, x8]; mov v0.16b, v1.16b; mov v1.16b, v8.16b; b #0x933d0]
uint64_t fde_sub_091968(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4EA11C20ULL) << 32) | 0xBC686A81ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091968ULL;
}

// FDE #3504 | PC: 0x091978..0x091984 (12 B) | Symbol: sub_091978
// EN: AArch64 prologue [ldr x21, [x19, #8]; cmp x20, x21; ret] | VI: Khởi đầu hàm AArch64 [ldr x21, [x19, #8]; cmp x20, x21; ret]
uint64_t fde_sub_091978(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB15029FULL) << 32) | 0xF9400675ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091978ULL;
}

// FDE #3505 | PC: 0x091984..0x09198c (8 B) | Symbol: sub_091984
// EN: AArch64 prologue [lsl x0, x0, #3; b #0x93320] | VI: Khởi đầu hàm AArch64 [lsl x0, x0, #3; b #0x93320]
uint64_t fde_sub_091984(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000666ULL) << 32) | 0xD37DF000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091984ULL;
}

// FDE #3506 | PC: 0x09198c..0x09199c (16 B) | Symbol: sub_09198c
// EN: AArch64 prologue [asr x8, x8, #2; cmp x8, x9; csel x28, x9, x8, lo; ret] | VI: Khởi đầu hàm AArch64 [asr x8, x8, #2; cmp x8, x9; csel x28, x9, x8, lo; ret]
uint64_t fde_sub_09198c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0x9342FD08ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09198CULL;
}

// FDE #3507 | PC: 0x09199c..0x0919b4 (24 B) | Symbol: sub_09199c
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; ldr x9, [x0]; sub x8, x8, x9; mov x9, #0x7fffffffffffffe] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; ldr x9, [x0]; sub x8, x8, x9; mov x9, #0x7fffffffffffffe]
uint64_t fde_sub_09199c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400009ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09199CULL;
}

// FDE #3508 | PC: 0x0919b4..0x0919d0 (28 B) | Symbol: sub_0919b4
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; add x0, x20, x19; bl #0x46c54; sub x19, x19, #0x20] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; add x0, x20, x19; bl #0x46c54; sub x19, x19, #0x20]
uint64_t fde_sub_0919b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8B130280ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0919B4ULL;
}

// FDE #3509 | PC: 0x0919d0..0x0919e0 (16 B) | Symbol: sub_0919d0
// EN: AArch64 prologue [ldr x1, [x8, #8]; mov w2, wzr; ldr x0, [x9]; b #0x8c718] | VI: Khởi đầu hàm AArch64 [ldr x1, [x8, #8]; mov w2, wzr; ldr x0, [x9]; b #0x8c718]
uint64_t fde_sub_0919d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E2ULL) << 32) | 0xF9400501ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0919D0ULL;
}

// FDE #3510 | PC: 0x0919e0..0x0919f0 (16 B) | Symbol: sub_0919e0
// EN: AArch64 prologue [cmp x23, x0; csel x0, x0, x23, lo; cmp x0, x21; ret] | VI: Khởi đầu hàm AArch64 [cmp x23, x0; csel x0, x0, x23, lo; cmp x0, x21; ret]
uint64_t fde_sub_0919e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9A973000ULL) << 32) | 0xEB0002FFULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0919E0ULL;
}

// FDE #3511 | PC: 0x0919f0..0x091a08 (24 B) | Symbol: sub_0919f0
// EN: AArch64 prologue [ldr q0, [sp]; add x8, sp, #0x18; add x8, x8, #8; str x23, [sp, #0x18]] | VI: Khởi đầu hàm AArch64 [ldr q0, [sp]; add x8, sp, #0x18; add x8, x8, #8; str x23, [sp, #0x18]]
uint64_t fde_sub_0919f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910063E8ULL) << 32) | 0x3DC003E0ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0919F0ULL;
}

// FDE #3512 | PC: 0x091a08..0x091a10 (8 B) | Symbol: sub_091a08
// EN: AArch64 prologue [mov x0, x23; b #0x93680] | VI: Khởi đầu hàm AArch64 [mov x0, x23; b #0x93680]
uint64_t fde_sub_091a08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400071DULL) << 32) | 0xAA1703E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091A08ULL;
}

// FDE #3513 | PC: 0x091a10..0x091a18 (8 B) | Symbol: sub_091a10
// EN: AArch64 prologue [mov x0, x23; b #0x932e0] | VI: Khởi đầu hàm AArch64 [mov x0, x23; b #0x932e0]
uint64_t fde_sub_091a10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000633ULL) << 32) | 0xAA1703E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091A10ULL;
}

// FDE #3514 | PC: 0x091a18..0x091a28 (16 B) | Symbol: sub_091a18
// EN: AArch64 prologue [ldr x8, [x0]; ldp x9, x10, [x8, #8]; sub x9, x9, x10; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldp x9, x10, [x8, #8]; sub x9, x9, x10; ret]
uint64_t fde_sub_091a18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA940A909ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091A18ULL;
}

// FDE #3515 | PC: 0x091a28..0x091a38 (16 B) | Symbol: sub_091a28
// EN: AArch64 prologue [ldr x8, [x0]; and w3, w3, #1; ldr x4, [x8, #0x58]; br x4] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; and w3, w3, #1; ldr x4, [x8, #0x58]; br x4]
uint64_t fde_sub_091a28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12000063ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091A28ULL;
}

// FDE #3516 | PC: 0x091a38..0x091a48 (16 B) | Symbol: sub_091a38
// EN: AArch64 prologue [ldr x8, [x0]; ldr x9, [x8, #0x20]; add x8, x20, #0x10; br x9] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x9, [x8, #0x20]; add x8, x20, #0x10; br x9]
uint64_t fde_sub_091a38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401109ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091A38ULL;
}

// FDE #3517 | PC: 0x091a48..0x091a58 (16 B) | Symbol: sub_091a48
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x8, [x8]; ldr x0, [x8]; b #0x675b4] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x8, [x8]; ldr x0, [x8]; b #0x675b4]
uint64_t fde_sub_091a48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400108ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091A48ULL;
}

// FDE #3518 | PC: 0x091a58..0x091a68 (16 B) | Symbol: sub_091a58
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x8, [x8]; ldr x0, [x8]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x8, [x8]; ldr x0, [x8]; ret]
uint64_t fde_sub_091a58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400108ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091A58ULL;
}

// FDE #3519 | PC: 0x091a68..0x091a74 (12 B) | Symbol: sub_091a68
// EN: AArch64 prologue [mov x1, x20; mov x2, x19; ret] | VI: Khởi đầu hàm AArch64 [mov x1, x20; mov x2, x19; ret]
uint64_t fde_sub_091a68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E2ULL) << 32) | 0xAA1403E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091A68ULL;
}

// FDE #3520 | PC: 0x091a74..0x091a94 (32 B) | Symbol: sub_091a74
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; mov v8.16b, v0.16b; mov x23, x1; str x8, [sp, #0x18]] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; mov v8.16b, v0.16b; mov x23, x1; str x8, [sp, #0x18]]
uint64_t fde_sub_091a74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4EA01C08ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091A74ULL;
}

// FDE #3521 | PC: 0x091a94..0x091aac (24 B) | Symbol: sub_091a94
// EN: AArch64 prologue [mrs x24, tpidr_el0; ldr x8, [x24, #0x28]; add x19, x0, #0x48; mov x20, x0] | VI: Khởi đầu hàm AArch64 [mrs x24, tpidr_el0; ldr x8, [x24, #0x28]; add x19, x0, #0x48; mov x20, x0]
uint64_t fde_sub_091a94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401708ULL) << 32) | 0xD53BD058ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091A94ULL;
}

// FDE #3522 | PC: 0x091aac..0x091ac4 (24 B) | Symbol: sub_091aac
// EN: AArch64 prologue [sub sp, sp, #0x50; str d8, [sp, #0x10]; str x24, [sp, #0x18]; stp x23, x22, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str d8, [sp, #0x10]; str x24, [sp, #0x18]; stp x23, x22, [sp, #0x20]]
uint64_t fde_sub_091aac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD000BE8ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091AACULL;
}

// FDE #3523 | PC: 0x091ac4..0x091ad0 (12 B) | Symbol: sub_091ac4
// EN: AArch64 prologue [adrp x5, #0xa0000; add x5, x5, #0x520; ret] | VI: Khởi đầu hàm AArch64 [adrp x5, #0xa0000; add x5, x5, #0x520; ret]
uint64_t fde_sub_091ac4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911480A5ULL) << 32) | 0xF0000065ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091AC4ULL;
}

// FDE #3524 | PC: 0x091ad0..0x091ae8 (24 B) | Symbol: sub_091ad0
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; str x8, [x19]; bl #0x44830; ldr x0, [x19, #0x10]] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; str x8, [x19]; bl #0x44830; ldr x0, [x19, #0x10]]
uint64_t fde_sub_091ad0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000268ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091AD0ULL;
}

// FDE #3525 | PC: 0x091ae8..0x091af8 (16 B) | Symbol: sub_091ae8
// EN: AArch64 prologue [mov x1, sp; add x2, sp, #0xb0; mov x0, x19; b #0x77c78] | VI: Khởi đầu hàm AArch64 [mov x1, sp; add x2, sp, #0xb0; mov x0, x19; b #0x77c78]
uint64_t fde_sub_091ae8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9102C3E2ULL) << 32) | 0x910003E1ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091AE8ULL;
}

// FDE #3526 | PC: 0x091af8..0x091b10 (24 B) | Symbol: sub_091af8
// EN: AArch64 prologue [sxtw x28, w22; str d0, [sp, #0x30]; stp xzr, xzr, [sp, #0x18]; str xzr, [sp, #0x10]] | VI: Khởi đầu hàm AArch64 [sxtw x28, w22; str d0, [sp, #0x30]; stp xzr, xzr, [sp, #0x18]; str xzr, [sp, #0x10]]
uint64_t fde_sub_091af8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD001BE0ULL) << 32) | 0x93407EDCULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091AF8ULL;
}

// FDE #3527 | PC: 0x091b10..0x091b18 (8 B) | Symbol: sub_091b10
// EN: AArch64 prologue [add x0, sp, #8; b #0x7d610] | VI: Khởi đầu hàm AArch64 [add x0, sp, #8; b #0x7d610]
uint64_t fde_sub_091b10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFAEBFULL) << 32) | 0x910023E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091B10ULL;
}

// FDE #3528 | PC: 0x091b18..0x091b34 (28 B) | Symbol: sub_091b18
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]]
uint64_t fde_sub_091b18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9056FFCULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091B18ULL;
}

// FDE #3529 | PC: 0x091b34..0x091b40 (12 B) | Symbol: sub_091b34
// EN: AArch64 prologue [add x1, sp, #8; mov x0, x21; ret] | VI: Khởi đầu hàm AArch64 [add x1, sp, #8; mov x0, x21; ret]
uint64_t fde_sub_091b34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E0ULL) << 32) | 0x910023E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091B34ULL;
}

// FDE #3530 | PC: 0x091b40..0x091b4c (12 B) | Symbol: sub_091b40
// EN: AArch64 prologue [add x1, sp, #8; mov x0, x20; ret] | VI: Khởi đầu hàm AArch64 [add x1, sp, #8; mov x0, x20; ret]
uint64_t fde_sub_091b40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0x910023E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091B40ULL;
}

// FDE #3531 | PC: 0x091b4c..0x091b5c (16 B) | Symbol: sub_091b4c
// EN: AArch64 prologue [add x1, sp, #8; str x8, [sp, #0x20]; str x9, [sp, #8]; b #0x94a70] | VI: Khởi đầu hàm AArch64 [add x1, sp, #8; str x8, [sp, #0x20]; str x9, [sp, #8]; b #0x94a70]
uint64_t fde_sub_091b4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013E8ULL) << 32) | 0x910023E1ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091B4CULL;
}

// FDE #3532 | PC: 0x091b5c..0x091b64 (8 B) | Symbol: sub_091b5c
// EN: AArch64 prologue [mov x0, x21; b #0x44b18] | VI: Khởi đầu hàm AArch64 [mov x0, x21; b #0x44b18]
uint64_t fde_sub_091b5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FECBEEULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091B5CULL;
}

// FDE #3533 | PC: 0x091b64..0x091b74 (16 B) | Symbol: sub_091b64
// EN: AArch64 prologue [mov x0, x21; mov x1, x23; mov x2, x22; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x21; mov x1, x23; mov x2, x22; ret]
uint64_t fde_sub_091b64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1703E1ULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091B64ULL;
}

// FDE #3534 | PC: 0x091b74..0x091b84 (16 B) | Symbol: sub_091b74
// EN: AArch64 prologue [mov x0, x21; mov x1, x20; ldp x21, x20, [sp], #0x20; b #0x93900] | VI: Khởi đầu hàm AArch64 [mov x0, x21; mov x1, x20; ldp x21, x20, [sp], #0x20; b #0x93900]
uint64_t fde_sub_091b74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E1ULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091B74ULL;
}

// FDE #3535 | PC: 0x091b84..0x091b94 (16 B) | Symbol: sub_091b84
// EN: AArch64 prologue [mov x0, x21; mov x1, x22; mov w2, w19; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x21; mov x1, x22; mov w2, w19; ret]
uint64_t fde_sub_091b84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E1ULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091B84ULL;
}

// FDE #3536 | PC: 0x091b94..0x091b9c (8 B) | Symbol: sub_091b94
// EN: AArch64 prologue [mov x0, x21; b #0x48d40] | VI: Khởi đầu hàm AArch64 [mov x0, x21; b #0x48d40]
uint64_t fde_sub_091b94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDC6AULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091B94ULL;
}

// FDE #3537 | PC: 0x091b9c..0x091bb4 (24 B) | Symbol: sub_091b9c
// EN: AArch64 prologue [ldp x8, x9, [x19]; mov x21, x0; stp xzr, x23, [sp, #0x20]; sub x8, x9, x8] | VI: Khởi đầu hàm AArch64 [ldp x8, x9, [x19]; mov x21, x0; stp xzr, x23, [sp, #0x20]; sub x8, x9, x8]
uint64_t fde_sub_091b9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F5ULL) << 32) | 0xA9402668ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091B9CULL;
}

// FDE #3538 | PC: 0x091bb4..0x091bc0 (12 B) | Symbol: sub_091bb4
// EN: AArch64 prologue [ldr x9, [x19]; str x20, [x9, x8, lsl #3]; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [x19]; str x20, [x9, x8, lsl #3]; ret]
uint64_t fde_sub_091bb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF8287934ULL) << 32) | 0xF9400269ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091BB4ULL;
}

// FDE #3539 | PC: 0x091bc0..0x091bcc (12 B) | Symbol: sub_091bc0
// EN: AArch64 prologue [mov x20, x1; tst x1, x8; ret] | VI: Khởi đầu hàm AArch64 [mov x20, x1; tst x1, x8; ret]
uint64_t fde_sub_091bc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEA08003FULL) << 32) | 0xAA0103F4ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091BC0ULL;
}

// FDE #3540 | PC: 0x091bcc..0x091bdc (16 B) | Symbol: sub_091bcc
// EN: AArch64 prologue [mov x21, x0; str x8, [x0], #8; add x1, sp, #8; b #0x7f220] | VI: Khởi đầu hàm AArch64 [mov x21, x0; str x8, [x0], #8; add x1, sp, #8; b #0x7f220]
uint64_t fde_sub_091bcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF8008408ULL) << 32) | 0xAA0003F5ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091BCCULL;
}

// FDE #3541 | PC: 0x091bdc..0x091bf4 (24 B) | Symbol: sub_091bdc
// EN: AArch64 prologue [ldr x8, [x20, #0x10]; ldr q0, [x20]; mov x0, x20; str x8, [x19, #0x10]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x20, #0x10]; ldr q0, [x20]; mov x0, x20; str x8, [x19, #0x10]]
uint64_t fde_sub_091bdc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC00280ULL) << 32) | 0xF9400A88ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091BDCULL;
}

// FDE #3542 | PC: 0x091bf4..0x091c00 (12 B) | Symbol: sub_091bf4
// EN: AArch64 prologue [mov x20, x0; str x8, [x0]; ret] | VI: Khởi đầu hàm AArch64 [mov x20, x0; str x8, [x0]; ret]
uint64_t fde_sub_091bf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000008ULL) << 32) | 0xAA0003F4ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091BF4ULL;
}

// FDE #3543 | PC: 0x091c00..0x091c08 (8 B) | Symbol: sub_091c00
// EN: AArch64 prologue [mov x20, x0; b #0x93290] | VI: Khởi đầu hàm AArch64 [mov x20, x0; b #0x93290]
uint64_t fde_sub_091c00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140005A3ULL) << 32) | 0xAA0003F4ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091C00ULL;
}

// FDE #3544 | PC: 0x091c08..0x091c18 (16 B) | Symbol: sub_091c08
// EN: AArch64 prologue [mov x20, x0; str x8, [x0], #8; add x1, sp, #8; ret] | VI: Khởi đầu hàm AArch64 [mov x20, x0; str x8, [x0], #8; add x1, sp, #8; ret]
uint64_t fde_sub_091c08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF8008408ULL) << 32) | 0xAA0003F4ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091C08ULL;
}

// FDE #3545 | PC: 0x091c18..0x091c34 (28 B) | Symbol: sub_091c18
// EN: AArch64 prologue [sub sp, sp, #0x1c0; stp x28, x27, [sp, #0x160]; stp x26, x25, [sp, #0x170]; stp x24, x23, [sp, #0x180]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1c0; stp x28, x27, [sp, #0x160]; stp x26, x25, [sp, #0x170]; stp x24, x23, [sp, #0x180]]
uint64_t fde_sub_091c18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9166FFCULL) << 32) | 0xD10703FFULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091C18ULL;
}

// FDE #3546 | PC: 0x091c34..0x091c40 (12 B) | Symbol: sub_091c34
// EN: AArch64 prologue [add x1, x21, #8; add x0, x19, #0x10; ret] | VI: Khởi đầu hàm AArch64 [add x1, x21, #8; add x0, x19, #0x10; ret]
uint64_t fde_sub_091c34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91004260ULL) << 32) | 0x910022A1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091C34ULL;
}

// FDE #3547 | PC: 0x091c40..0x091c4c (12 B) | Symbol: sub_091c40
// EN: AArch64 prologue [subs x8, x1, #1; mov x19, x0; ret] | VI: Khởi đầu hàm AArch64 [subs x8, x1, #1; mov x19, x0; ret]
uint64_t fde_sub_091c40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xF1000428ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091C40ULL;
}

// FDE #3548 | PC: 0x091c4c..0x091c5c (16 B) | Symbol: sub_091c4c
// EN: AArch64 prologue [mov w0, #6; mov w2, #4; mov w1, wzr; b #0x94a80] | VI: Khởi đầu hàm AArch64 [mov w0, #6; mov w2, #4; mov w1, wzr; b #0x94a80]
uint64_t fde_sub_091c4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800082ULL) << 32) | 0x528000C0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091C4CULL;
}

// FDE #3549 | PC: 0x091c5c..0x091c6c (16 B) | Symbol: sub_091c5c
// EN: AArch64 prologue [ldp x21, x20, [sp, #0x20]; ldp x23, x22, [sp, #0x10]; add sp, sp, #0x40; b #0x48624] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp, #0x20]; ldp x23, x22, [sp, #0x10]; add sp, sp, #0x40; b #0x48624]
uint64_t fde_sub_091c5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9415BF7ULL) << 32) | 0xA94253F5ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091C5CULL;
}

// FDE #3550 | PC: 0x091c6c..0x091c7c (16 B) | Symbol: sub_091c6c
// EN: AArch64 prologue [ldp x21, x20, [sp, #0x20]; ldp x23, x22, [sp, #0x10]; ldp x25, x24, [sp], #0x40; b #0x932e0] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp, #0x20]; ldp x23, x22, [sp, #0x10]; ldp x25, x24, [sp], #0x40; b #0x932e0]
uint64_t fde_sub_091c6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9415BF7ULL) << 32) | 0xA94253F5ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091C6CULL;
}

// FDE #3551 | PC: 0x091c7c..0x091c8c (16 B) | Symbol: sub_091c7c
// EN: AArch64 prologue [ldp x21, x20, [sp, #0x20]; mov w0, #0x18; stp xzr, xzr, [sp, #0x20]; b #0x93320] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp, #0x20]; mov w0, #0x18; stp xzr, xzr, [sp, #0x20]; b #0x93320]
uint64_t fde_sub_091c7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800300ULL) << 32) | 0xA94253F5ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091C7CULL;
}

// FDE #3552 | PC: 0x091c8c..0x091c94 (8 B) | Symbol: sub_091c8c
// EN: AArch64 prologue [add x19, sp, #0x28; b #0x49290] | VI: Khởi đầu hàm AArch64 [add x19, sp, #0x28; b #0x49290]
uint64_t fde_sub_091c8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDD80ULL) << 32) | 0x9100A3F3ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091C8CULL;
}

// FDE #3553 | PC: 0x091c94..0x091ca4 (16 B) | Symbol: sub_091c94
// EN: AArch64 prologue [mov w2, #0x98; mov w1, wzr; mov x24, x0; b #0x93200] | VI: Khởi đầu hàm AArch64 [mov w2, #0x98; mov w1, wzr; mov x24, x0; b #0x93200]
uint64_t fde_sub_091c94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E1ULL) << 32) | 0x52801302ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091C94ULL;
}

// FDE #3554 | PC: 0x091ca4..0x091cb4 (16 B) | Symbol: sub_091ca4
// EN: AArch64 prologue [add x0, sp, #0xf0; add x1, sp, #0x108; add x2, sp, #0x1f0; b #0x7c00c] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0xf0; add x1, sp, #0x108; add x2, sp, #0x1f0; b #0x7c00c]
uint64_t fde_sub_091ca4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910423E1ULL) << 32) | 0x9103C3E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091CA4ULL;
}

// FDE #3555 | PC: 0x091cb4..0x091ccc (24 B) | Symbol: sub_091cb4
// EN: AArch64 prologue [ldrb w9, [x0, #0xc]; ldr s0, [x0, #8]; ldr x8, [x20, #0xb0]; fmov s1, wzr] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x0, #0xc]; ldr s0, [x0, #8]; ldr x8, [x20, #0xb0]; fmov s1, wzr]
uint64_t fde_sub_091cb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xBD400800ULL) << 32) | 0x39403009ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091CB4ULL;
}

// FDE #3556 | PC: 0x091ccc..0x091cd8 (12 B) | Symbol: sub_091ccc
// EN: AArch64 prologue [ldr x9, [sp, #0x198]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [sp, #0x198]; cmp x8, x9; ret]
uint64_t fde_sub_091ccc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xF940CFE9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091CCCULL;
}

// FDE #3557 | PC: 0x091cd8..0x091cf4 (28 B) | Symbol: sub_091cd8
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; ldr x20, [sp, #0x80]; add x0, x20, #0x18; bl #0x6d070] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; ldr x20, [sp, #0x80]; add x0, x20, #0x18; bl #0x6d070]
uint64_t fde_sub_091cd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043F4ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091CD8ULL;
}

// FDE #3558 | PC: 0x091cf4..0x091d04 (16 B) | Symbol: sub_091cf4
// EN: AArch64 prologue [add x0, sp, #0x78; mov x1, x21; add x20, sp, #0x78; b #0x78aec] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x78; mov x1, x21; add x20, sp, #0x78; b #0x78aec]
uint64_t fde_sub_091cf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E1ULL) << 32) | 0x9101E3E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091CF4ULL;
}

// FDE #3559 | PC: 0x091d04..0x091d0c (8 B) | Symbol: sub_091d04
// EN: AArch64 prologue [add x0, sp, #0x78; b #0x63cb4] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x78; b #0x63cb4]
uint64_t fde_sub_091d04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF47EBULL) << 32) | 0x9101E3E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091D04ULL;
}

// FDE #3560 | PC: 0x091d0c..0x091d1c (16 B) | Symbol: sub_091d0c
// EN: AArch64 prologue [add x0, sp, #0x60; add x1, sp, #0x10; mov w2, w20; b #0x88820] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x60; add x1, sp, #0x10; mov w2, w20; b #0x88820]
uint64_t fde_sub_091d0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910043E1ULL) << 32) | 0x910183E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091D0CULL;
}

// FDE #3561 | PC: 0x091d1c..0x091d24 (8 B) | Symbol: sub_091d1c
// EN: AArch64 prologue [mov x0, sp; b #0x937a0] | VI: Khởi đầu hàm AArch64 [mov x0, sp; b #0x937a0]
uint64_t fde_sub_091d1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140006A0ULL) << 32) | 0x910003E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091D1CULL;
}

// FDE #3562 | PC: 0x091d24..0x091d30 (12 B) | Symbol: sub_091d24
// EN: AArch64 prologue [mov x0, sp; mov x1, x21; ret] | VI: Khởi đầu hàm AArch64 [mov x0, sp; mov x1, x21; ret]
uint64_t fde_sub_091d24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E1ULL) << 32) | 0x910003E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091D24ULL;
}

// FDE #3563 | PC: 0x091d30..0x091d48 (24 B) | Symbol: sub_091d30
// EN: AArch64 prologue [mov x0, x19; add x21, x19, #0x10; sub x8, x8, x9; sdiv x8, x8, x22] | VI: Khởi đầu hàm AArch64 [mov x0, x19; add x21, x19, #0x10; sub x8, x8, x9; sdiv x8, x8, x22]
uint64_t fde_sub_091d30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91004275ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091D30ULL;
}

// FDE #3564 | PC: 0x091d48..0x091d50 (8 B) | Symbol: sub_091d48
// EN: AArch64 prologue [mov x0, x19; b #0x94a90] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x94a90]
uint64_t fde_sub_091d48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000B51ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091D48ULL;
}

// FDE #3565 | PC: 0x091d50..0x091d58 (8 B) | Symbol: sub_091d50
// EN: AArch64 prologue [mov x0, x19; b #0x69448] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x69448]
uint64_t fde_sub_091d50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF5DBDULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091D50ULL;
}

// FDE #3566 | PC: 0x091d58..0x091d60 (8 B) | Symbol: sub_091d58
// EN: AArch64 prologue [mov x0, x19; b #0x89abc] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x89abc]
uint64_t fde_sub_091d58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFDF58ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091D58ULL;
}

// FDE #3567 | PC: 0x091d60..0x091d68 (8 B) | Symbol: sub_091d60
// EN: AArch64 prologue [mov x0, x19; b #0x78df0] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x78df0]
uint64_t fde_sub_091d60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF9C23ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091D60ULL;
}

// FDE #3568 | PC: 0x091d68..0x091d74 (12 B) | Symbol: sub_091d68
// EN: AArch64 prologue [ldr x8, [x19]; ldr x8, [x8, x24, lsl #3]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x19]; ldr x8, [x8, x24, lsl #3]; ret]
uint64_t fde_sub_091d68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF8787908ULL) << 32) | 0xF9400268ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091D68ULL;
}

// FDE #3569 | PC: 0x091d74..0x091d7c (8 B) | Symbol: sub_091d74
// EN: AArch64 prologue [mov x19, x0; b #0x61b2c] | VI: Khởi đầu hàm AArch64 [mov x19, x0; b #0x61b2c]
uint64_t fde_sub_091d74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF3F6DULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091D74ULL;
}

// FDE #3570 | PC: 0x091d7c..0x091d8c (16 B) | Symbol: sub_091d7c
// EN: AArch64 prologue [mov x19, x0; add x1, x0, #0x10; add x0, sp, #0x20; b #0x7568c] | VI: Khởi đầu hàm AArch64 [mov x19, x0; add x1, x0, #0x10; add x0, sp, #0x20; b #0x7568c]
uint64_t fde_sub_091d7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91004001ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091D7CULL;
}

// FDE #3571 | PC: 0x091d8c..0x091d98 (12 B) | Symbol: sub_091d8c
// EN: AArch64 prologue [mov x19, x0; lsr x8, x0, #0x3d; ret] | VI: Khởi đầu hàm AArch64 [mov x19, x0; lsr x8, x0, #0x3d; ret]
uint64_t fde_sub_091d8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD37DFC08ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091D8CULL;
}

// FDE #3572 | PC: 0x091d98..0x091da8 (16 B) | Symbol: sub_091d98
// EN: AArch64 prologue [mov x19, x0; mov x0, x8; mov x20, x8; b #0x932f0] | VI: Khởi đầu hàm AArch64 [mov x19, x0; mov x0, x8; mov x20, x8; b #0x932f0]
uint64_t fde_sub_091d98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091D98ULL;
}

// FDE #3573 | PC: 0x091da8..0x091db8 (16 B) | Symbol: sub_091da8
// EN: AArch64 prologue [mov x19, x0; ldr x0, [x0, #0x10]; str xzr, [x19, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [mov x19, x0; ldr x0, [x0, #0x10]; str xzr, [x19, #0x10]; ret]
uint64_t fde_sub_091da8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400800ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091DA8ULL;
}

// FDE #3574 | PC: 0x091db8..0x091dc0 (8 B) | Symbol: sub_091db8
// EN: AArch64 prologue [mov x19, x0; b #0x61dc4] | VI: Khởi đầu hàm AArch64 [mov x19, x0; b #0x61dc4]
uint64_t fde_sub_091db8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF4002ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091DB8ULL;
}

// FDE #3575 | PC: 0x091dc0..0x091dd0 (16 B) | Symbol: sub_091dc0
// EN: AArch64 prologue [mrs x20, tpidr_el0; ldr x8, [x20, #0x28]; str x8, [sp, #8]; ret] | VI: Khởi đầu hàm AArch64 [mrs x20, tpidr_el0; ldr x8, [x20, #0x28]; str x8, [sp, #8]; ret]
uint64_t fde_sub_091dc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401688ULL) << 32) | 0xD53BD054ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091DC0ULL;
}

// FDE #3576 | PC: 0x091dd0..0x091de0 (16 B) | Symbol: sub_091dd0
// EN: AArch64 prologue [mrs x20, tpidr_el0; ldr x8, [x20, #0x28]; mov x19, x1; ret] | VI: Khởi đầu hàm AArch64 [mrs x20, tpidr_el0; ldr x8, [x20, #0x28]; mov x19, x1; ret]
uint64_t fde_sub_091dd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401688ULL) << 32) | 0xD53BD054ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091DD0ULL;
}

// FDE #3577 | PC: 0x091de0..0x091df8 (24 B) | Symbol: sub_091de0
// EN: AArch64 prologue [mrs x20, tpidr_el0; ldr x8, [x20, #0x28]; str x8, [sp, #0x18]; ldr x21, [x0, #0xa8]] | VI: Khởi đầu hàm AArch64 [mrs x20, tpidr_el0; ldr x8, [x20, #0x28]; str x8, [sp, #0x18]; ldr x21, [x0, #0xa8]]
uint64_t fde_sub_091de0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401688ULL) << 32) | 0xD53BD054ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091DE0ULL;
}

// FDE #3578 | PC: 0x091df8..0x091e08 (16 B) | Symbol: sub_091df8
// EN: AArch64 prologue [mrs x20, tpidr_el0; ldr x8, [x20, #0x28]; str x8, [sp, #0x58]; ret] | VI: Khởi đầu hàm AArch64 [mrs x20, tpidr_el0; ldr x8, [x20, #0x28]; str x8, [sp, #0x58]; ret]
uint64_t fde_sub_091df8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401688ULL) << 32) | 0xD53BD054ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091DF8ULL;
}

// FDE #3579 | PC: 0x091e08..0x091e20 (24 B) | Symbol: sub_091e08
// EN: AArch64 prologue [str x27, [sp, #0x38]; strb wzr, [sp, #0x48]; strb wzr, [sp, #0x60]; strb wzr, [sp, #0x68]] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #0x38]; strb wzr, [sp, #0x48]; strb wzr, [sp, #0x60]; strb wzr, [sp, #0x68]]
uint64_t fde_sub_091e08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x390123FFULL) << 32) | 0xF9001FFBULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091E08ULL;
}

// FDE #3580 | PC: 0x091e20..0x091e2c (12 B) | Symbol: sub_091e20
// EN: AArch64 prologue [add x0, sp, #0xb8; add x1, sp, #0xd0; b #0x65a08] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0xb8; add x1, sp, #0xd0; b #0x65a08]
uint64_t fde_sub_091e20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910343E1ULL) << 32) | 0x9102E3E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091E20ULL;
}

// FDE #3581 | PC: 0x091e2c..0x091e38 (12 B) | Symbol: sub_091e2c
// EN: AArch64 prologue [fadd s0, s10, s0; fadd s1, s8, s1; b #0x8c240] | VI: Khởi đầu hàm AArch64 [fadd s0, s10, s0; fadd s1, s8, s1; b #0x8c240]
uint64_t fde_sub_091e2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E212901ULL) << 32) | 0x1E202940ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091E2CULL;
}

// FDE #3582 | PC: 0x091e38..0x091e4c (20 B) | Symbol: sub_091e38
// EN: AArch64 prologue [stp x27, x26, [sp, #0x10]; stp x25, x24, [sp, #0x20]; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [stp x27, x26, [sp, #0x10]; stp x25, x24, [sp, #0x20]; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]]
uint64_t fde_sub_091e38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90263F9ULL) << 32) | 0xA9016BFBULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091E38ULL;
}

// FDE #3583 | PC: 0x091e4c..0x091e54 (8 B) | Symbol: sub_091e4c
// EN: AArch64 prologue [mov x0, x24; b #0x932e0] | VI: Khởi đầu hàm AArch64 [mov x0, x24; b #0x932e0]
uint64_t fde_sub_091e4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000524ULL) << 32) | 0xAA1803E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091E4CULL;
}

// FDE #3584 | PC: 0x091e54..0x091e60 (12 B) | Symbol: sub_091e54
// EN: AArch64 prologue [str x0, [x24]; ldr x24, [sp], #0x40; ret] | VI: Khởi đầu hàm AArch64 [str x0, [x24]; ldr x24, [sp], #0x40; ret]
uint64_t fde_sub_091e54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF84407F8ULL) << 32) | 0xF9000300ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091E54ULL;
}

// FDE #3585 | PC: 0x091e60..0x091e74 (20 B) | Symbol: sub_091e60
// EN: AArch64 prologue [lsr w8, w0, #0x18; lsr w9, w0, #0x10; lsr w10, w0, #8; stp x19, x21, [sp, #0xd0]] | VI: Khởi đầu hàm AArch64 [lsr w8, w0, #0x18; lsr w9, w0, #0x10; lsr w10, w0, #8; stp x19, x21, [sp, #0xd0]]
uint64_t fde_sub_091e60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x53107C09ULL) << 32) | 0x53187C08ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091E60ULL;
}

// FDE #3586 | PC: 0x091e74..0x091e80 (12 B) | Symbol: sub_091e74
// EN: AArch64 prologue [stp s0, s1, [sp, #8]; stp s2, s3, [sp, #0x10]; b #0x94aa0] | VI: Khởi đầu hàm AArch64 [stp s0, s1, [sp, #8]; stp s2, s3, [sp, #0x10]; b #0x94aa0]
uint64_t fde_sub_091e74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2D020FE2ULL) << 32) | 0x2D0107E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091E74ULL;
}

// FDE #3587 | PC: 0x091e80..0x091e94 (20 B) | Symbol: sub_091e80
// EN: AArch64 prologue [ldp x21, x8, [x0, #8]; mov x19, x0; mov x20, x1; cmp x21, x8] | VI: Khởi đầu hàm AArch64 [ldp x21, x8, [x0, #8]; mov x19, x0; mov x20, x1; cmp x21, x8]
uint64_t fde_sub_091e80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA940A015ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091E80ULL;
}

// FDE #3588 | PC: 0x091e94..0x091ea0 (12 B) | Symbol: sub_091e94
// EN: AArch64 prologue [add x0, x29, #0x10; mov x1, x21; b #0x4c4d4] | VI: Khởi đầu hàm AArch64 [add x0, x29, #0x10; mov x1, x21; b #0x4c4d4]
uint64_t fde_sub_091e94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E1ULL) << 32) | 0x910043A0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091E94ULL;
}

// FDE #3589 | PC: 0x091ea0..0x091eac (12 B) | Symbol: sub_091ea0
// EN: AArch64 prologue [ldr w1, [x19, #0xc]; mov w0, #0x8d40; b #0x93580] | VI: Khởi đầu hàm AArch64 [ldr w1, [x19, #0xc]; mov w0, #0x8d40; b #0x93580]
uint64_t fde_sub_091ea0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5291A800ULL) << 32) | 0xB9400E61ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091EA0ULL;
}

// FDE #3590 | PC: 0x091eac..0x091eb8 (12 B) | Symbol: sub_091eac
// EN: AArch64 prologue [udiv x8, x20, x27; msub x28, x8, x27, x20; ret] | VI: Khởi đầu hàm AArch64 [udiv x8, x20, x27; msub x28, x8, x27, x20; ret]
uint64_t fde_sub_091eac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9B1BD11CULL) << 32) | 0x9ADB0A88ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091EACULL;
}

// FDE #3591 | PC: 0x091eb8..0x091ec4 (12 B) | Symbol: sub_091eb8
// EN: AArch64 prologue [cnt v0.8b, v0.8b; uaddlv h0, v0.8b; ret] | VI: Khởi đầu hàm AArch64 [cnt v0.8b, v0.8b; uaddlv h0, v0.8b; ret]
uint64_t fde_sub_091eb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2E303800ULL) << 32) | 0x0E205800ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091EB8ULL;
}

// FDE #3592 | PC: 0x091ec4..0x091ed8 (20 B) | Symbol: sub_091ec4
// EN: AArch64 prologue [cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w21, s0; cmp x21, #1] | VI: Khởi đầu hàm AArch64 [cnt v0.8b, v0.8b; uaddlv h0, v0.8b; fmov w21, s0; cmp x21, #1]
uint64_t fde_sub_091ec4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2E303800ULL) << 32) | 0x0E205800ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091EC4ULL;
}

// FDE #3593 | PC: 0x091ed8..0x091ee0 (8 B) | Symbol: sub_091ed8
// EN: AArch64 prologue [add x0, sp, #0x1f0; b #0x46c54] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x1f0; b #0x46c54]
uint64_t fde_sub_091ed8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED35EULL) << 32) | 0x9107C3E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091ED8ULL;
}

// FDE #3594 | PC: 0x091ee0..0x091eec (12 B) | Symbol: sub_091ee0
// EN: AArch64 prologue [str s0, [sp, #0x50]; str s1, [sp, #0x5c]; b #0x8c238] | VI: Khởi đầu hàm AArch64 [str s0, [sp, #0x50]; str s1, [sp, #0x5c]; b #0x8c238]
uint64_t fde_sub_091ee0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xBD005FE1ULL) << 32) | 0xBD0053E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091EE0ULL;
}

// FDE #3595 | PC: 0x091eec..0x091ef8 (12 B) | Symbol: sub_091eec
// EN: AArch64 prologue [strb wzr, [sp, #0x6c]; strb wzr, [sp, #0x70]; ret] | VI: Khởi đầu hàm AArch64 [strb wzr, [sp, #0x6c]; strb wzr, [sp, #0x70]; ret]
uint64_t fde_sub_091eec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3901C3FFULL) << 32) | 0x3901B3FFULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091EECULL;
}

// FDE #3596 | PC: 0x091ef8..0x091f00 (8 B) | Symbol: sub_091ef8
// EN: AArch64 prologue [add x0, sp, #0x38; b #0x46c54] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x38; b #0x46c54]
uint64_t fde_sub_091ef8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED356ULL) << 32) | 0x9100E3E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091EF8ULL;
}

// FDE #3597 | PC: 0x091f00..0x091f0c (12 B) | Symbol: sub_091f00
// EN: AArch64 prologue [ldr x9, [sp, #0x98]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [sp, #0x98]; cmp x8, x9; ret]
uint64_t fde_sub_091f00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xF9404FE9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091F00ULL;
}

// FDE #3598 | PC: 0x091f0c..0x091f14 (8 B) | Symbol: sub_091f0c
// EN: AArch64 prologue [mov w1, #0x8b8d; b #0x941a0] | VI: Khởi đầu hàm AArch64 [mov w1, #0x8b8d; b #0x941a0]
uint64_t fde_sub_091f0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140008A4ULL) << 32) | 0x529171A1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091F0CULL;
}

// FDE #3599 | PC: 0x091f14..0x091f1c (8 B) | Symbol: sub_091f14
// EN: AArch64 prologue [mov w1, #0x8ca6; b #0x941a0] | VI: Khởi đầu hàm AArch64 [mov w1, #0x8ca6; b #0x941a0]
uint64_t fde_sub_091f14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140008A2ULL) << 32) | 0x529194C1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091F14ULL;
}

// FDE #3600 | PC: 0x091f1c..0x091f28 (12 B) | Symbol: sub_091f1c
// EN: AArch64 prologue [add x0, sp, #0x120; mov w1, #0x84e0; b #0x941a0] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x120; mov w1, #0x84e0; b #0x941a0]
uint64_t fde_sub_091f1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52909C01ULL) << 32) | 0x910483E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091F1CULL;
}

// FDE #3601 | PC: 0x091f28..0x091f34 (12 B) | Symbol: sub_091f28
// EN: AArch64 prologue [add x0, sp, #0x68; add x1, sp, #0x50; b #0x5081c] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x68; add x1, sp, #0x50; b #0x5081c]
uint64_t fde_sub_091f28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910143E1ULL) << 32) | 0x9101A3E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091F28ULL;
}

// FDE #3602 | PC: 0x091f34..0x091f3c (8 B) | Symbol: sub_091f34
// EN: AArch64 prologue [add x0, sp, #0x20; b #0x4b288] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x20; b #0x4b288]
uint64_t fde_sub_091f34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE4D4ULL) << 32) | 0x910083E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091F34ULL;
}

// FDE #3603 | PC: 0x091f3c..0x091f44 (8 B) | Symbol: sub_091f3c
// EN: AArch64 prologue [add x0, sp, #0x20; b #0x4c158] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x20; b #0x4c158]
uint64_t fde_sub_091f3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE886ULL) << 32) | 0x910083E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091F3CULL;
}

// FDE #3604 | PC: 0x091f44..0x091f50 (12 B) | Symbol: sub_091f44
// EN: AArch64 prologue [add x0, sp, #0x20; add x1, sp, #0x38; b #0x506ec] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x20; add x1, sp, #0x38; b #0x506ec]
uint64_t fde_sub_091f44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9100E3E1ULL) << 32) | 0x910083E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091F44ULL;
}

// FDE #3605 | PC: 0x091f50..0x091f58 (8 B) | Symbol: sub_091f50
// EN: AArch64 prologue [add x0, sp, #0x20; b #0x4816c] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x20; b #0x4816c]
uint64_t fde_sub_091f50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED886ULL) << 32) | 0x910083E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091F50ULL;
}

// FDE #3606 | PC: 0x091f58..0x091f64 (12 B) | Symbol: sub_091f58
// EN: AArch64 prologue [strb wzr, [sp, #0x78]; strb wzr, [sp, #0x80]; ret] | VI: Khởi đầu hàm AArch64 [strb wzr, [sp, #0x78]; strb wzr, [sp, #0x80]; ret]
uint64_t fde_sub_091f58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x390203FFULL) << 32) | 0x3901E3FFULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091F58ULL;
}

// FDE #3607 | PC: 0x091f64..0x091f6c (8 B) | Symbol: sub_091f64
// EN: AArch64 prologue [add x0, sp, #0x40; b #0x937a0] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x40; b #0x937a0]
uint64_t fde_sub_091f64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400060EULL) << 32) | 0x910103E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091F64ULL;
}

// FDE #3608 | PC: 0x091f6c..0x091f78 (12 B) | Symbol: sub_091f6c
// EN: AArch64 prologue [add x1, sp, #0x40; mov x0, x20; ret] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0x40; mov x0, x20; ret]
uint64_t fde_sub_091f6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0x910103E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091F6CULL;
}

// FDE #3609 | PC: 0x091f78..0x091f80 (8 B) | Symbol: sub_091f78
// EN: AArch64 prologue [add x20, sp, #0x48; b #0x46964] | VI: Khởi đầu hàm AArch64 [add x20, sp, #0x48; b #0x46964]
uint64_t fde_sub_091f78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED27AULL) << 32) | 0x910123F4ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091F78ULL;
}

// FDE #3610 | PC: 0x091f80..0x091f94 (20 B) | Symbol: sub_091f80
// EN: AArch64 prologue [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; mov x19, x0; str x8, [sp, #0x58]] | VI: Khởi đầu hàm AArch64 [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; mov x19, x0; str x8, [sp, #0x58]]
uint64_t fde_sub_091f80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016C8ULL) << 32) | 0xD53BD056ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091F80ULL;
}

// FDE #3611 | PC: 0x091f94..0x091fa8 (20 B) | Symbol: sub_091f94
// EN: AArch64 prologue [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; mov v8.16b, v0.16b; mov x19, x0] | VI: Khởi đầu hàm AArch64 [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; mov v8.16b, v0.16b; mov x19, x0]
uint64_t fde_sub_091f94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016C8ULL) << 32) | 0xD53BD056ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091F94ULL;
}

// FDE #3612 | PC: 0x091fa8..0x091fbc (20 B) | Symbol: sub_091fa8
// EN: AArch64 prologue [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; mov x21, x0; mov x20, x2] | VI: Khởi đầu hàm AArch64 [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; mov x21, x0; mov x20, x2]
uint64_t fde_sub_091fa8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016C8ULL) << 32) | 0xD53BD056ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091FA8ULL;
}

// FDE #3613 | PC: 0x091fbc..0x091fc8 (12 B) | Symbol: sub_091fbc
// EN: AArch64 prologue [add x1, x0, #0x18; mov x0, sp; b #0x49124] | VI: Khởi đầu hàm AArch64 [add x1, x0, #0x18; mov x0, sp; b #0x49124]
uint64_t fde_sub_091fbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003E0ULL) << 32) | 0x91006001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091FBCULL;
}

// FDE #3614 | PC: 0x091fc8..0x091fd4 (12 B) | Symbol: sub_091fc8
// EN: AArch64 prologue [add x1, sp, #0x18; mov x0, x22; b #0x5db48] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0x18; mov x0, x22; b #0x5db48]
uint64_t fde_sub_091fc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E0ULL) << 32) | 0x910063E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091FC8ULL;
}

// FDE #3615 | PC: 0x091fd4..0x091fe0 (12 B) | Symbol: sub_091fd4
// EN: AArch64 prologue [add x1, sp, #0x18; mov x0, x20; ret] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0x18; mov x0, x20; ret]
uint64_t fde_sub_091fd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0x910063E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091FD4ULL;
}

// FDE #3616 | PC: 0x091fe0..0x091fe8 (8 B) | Symbol: sub_091fe0
// EN: AArch64 prologue [str w8, [sp, #0x90]; b #0x497b4] | VI: Khởi đầu hàm AArch64 [str w8, [sp, #0x90]; b #0x497b4]
uint64_t fde_sub_091fe0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDDF4ULL) << 32) | 0xB90093E8ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091FE0ULL;
}

// FDE #3617 | PC: 0x091fe8..0x091ff4 (12 B) | Symbol: sub_091fe8
// EN: AArch64 prologue [add x1, sp, #0x70; mov x0, x21; b #0x4c7e0] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0x70; mov x0, x21; b #0x4c7e0]
uint64_t fde_sub_091fe8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E0ULL) << 32) | 0x9101C3E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091FE8ULL;
}

// FDE #3618 | PC: 0x091ff4..0x092000 (12 B) | Symbol: sub_091ff4
// EN: AArch64 prologue [adrp x8, #0x9b000; add x8, x8, #0x8f8; ret] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9b000; add x8, x8, #0x8f8; ret]
uint64_t fde_sub_091ff4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9123E108ULL) << 32) | 0xD0000048ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091FF4ULL;
}

// FDE #3619 | PC: 0x092000..0x09200c (12 B) | Symbol: sub_092000
// EN: AArch64 prologue [add x1, sp, #0x170; str wzr, [sp, #0x170]; b #0x692bc] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0x170; str wzr, [sp, #0x170]; b #0x692bc]
uint64_t fde_sub_092000(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB90173FFULL) << 32) | 0x9105C3E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092000ULL;
}

// FDE #3620 | PC: 0x09200c..0x092018 (12 B) | Symbol: sub_09200c
// EN: AArch64 prologue [add x0, sp, #0xa0; add x1, sp, #0xb8; b #0x65be8] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0xa0; add x1, sp, #0xb8; b #0x65be8]
uint64_t fde_sub_09200c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9102E3E1ULL) << 32) | 0x910283E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09200CULL;
}

// FDE #3621 | PC: 0x092018..0x092020 (8 B) | Symbol: sub_092018
// EN: AArch64 prologue [add x0, sp, #0xa0; b #0x7d610] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0xa0; b #0x7d610]
uint64_t fde_sub_092018(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFAD7DULL) << 32) | 0x910283E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092018ULL;
}

// FDE #3622 | PC: 0x092020..0x092028 (8 B) | Symbol: sub_092020
// EN: AArch64 prologue [add x0, sp, #0xa0; b #0x7d0bc] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0xa0; b #0x7d0bc]
uint64_t fde_sub_092020(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFAC26ULL) << 32) | 0x910283E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092020ULL;
}

// FDE #3623 | PC: 0x092028..0x09203c (20 B) | Symbol: sub_092028
// EN: AArch64 prologue [mov w8, #0x4b0; add x9, sp, #0xb0; str w8, [sp, #0xb0]; add x21, x9, #8] | VI: Khởi đầu hàm AArch64 [mov w8, #0x4b0; add x9, sp, #0xb0; str w8, [sp, #0xb0]; add x21, x9, #8]
uint64_t fde_sub_092028(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9102C3E9ULL) << 32) | 0x52809608ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092028ULL;
}

// FDE #3624 | PC: 0x09203c..0x092044 (8 B) | Symbol: sub_09203c
// EN: AArch64 prologue [lsl x0, x25, #3; b #0x93320] | VI: Khởi đầu hàm AArch64 [lsl x0, x25, #3; b #0x93320]
uint64_t fde_sub_09203c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140004B8ULL) << 32) | 0xD37DF320ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09203CULL;
}

// FDE #3625 | PC: 0x092044..0x09204c (8 B) | Symbol: sub_092044
// EN: AArch64 prologue [mov w0, #1; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov w0, #1; b #0x93320]
uint64_t fde_sub_092044(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140004B6ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092044ULL;
}

// FDE #3626 | PC: 0x09204c..0x092060 (20 B) | Symbol: sub_09204c
// EN: AArch64 prologue [ldp x9, x8, [x0, #8]; mov x19, x0; mov x22, x1; cmp x9, x8] | VI: Khởi đầu hàm AArch64 [ldp x9, x8, [x0, #8]; mov x19, x0; mov x22, x1; cmp x9, x8]
uint64_t fde_sub_09204c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA940A009ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09204CULL;
}

// FDE #3627 | PC: 0x092060..0x09206c (12 B) | Symbol: sub_092060
// EN: AArch64 prologue [ldr x23, [x19, #8]; mov x21, x0; ret] | VI: Khởi đầu hàm AArch64 [ldr x23, [x19, #8]; mov x21, x0; ret]
uint64_t fde_sub_092060(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F5ULL) << 32) | 0xF9400677ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092060ULL;
}

// FDE #3628 | PC: 0x09206c..0x092078 (12 B) | Symbol: sub_09206c
// EN: AArch64 prologue [ldr x23, [x19, #8]; cmp x22, x23; ret] | VI: Khởi đầu hàm AArch64 [ldr x23, [x19, #8]; cmp x22, x23; ret]
uint64_t fde_sub_09206c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB1702DFULL) << 32) | 0xF9400677ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09206CULL;
}

// FDE #3629 | PC: 0x092078..0x09209c (36 B) | Symbol: sub_092078
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; str w8, [sp, #0x80]; bl #0x75bf0; add x0, x24, #0x30] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; str w8, [sp, #0x80]; bl #0x75bf0; add x0, x24, #0x30]
uint64_t fde_sub_092078(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB90083E8ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092078ULL;
}

// FDE #3630 | PC: 0x09209c..0x0920a8 (12 B) | Symbol: sub_09209c
// EN: AArch64 prologue [ldp x28, x20, [sp, #0x130]; add sp, sp, #0x150; ret] | VI: Khởi đầu hàm AArch64 [ldp x28, x20, [sp, #0x130]; add sp, sp, #0x150; ret]
uint64_t fde_sub_09209c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910543FFULL) << 32) | 0xA95353FCULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09209CULL;
}

// FDE #3631 | PC: 0x0920a8..0x0920b4 (12 B) | Symbol: sub_0920a8
// EN: AArch64 prologue [sub x8, x23, #1; and x24, x8, x21; ret] | VI: Khởi đầu hàm AArch64 [sub x8, x23, #1; and x24, x8, x21; ret]
uint64_t fde_sub_0920a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8A150118ULL) << 32) | 0xD10006E8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0920A8ULL;
}

// FDE #3632 | PC: 0x0920b4..0x0920bc (8 B) | Symbol: sub_0920b4
// EN: AArch64 prologue [str x8, [sp, #0x78]; b #0x93320] | VI: Khởi đầu hàm AArch64 [str x8, [sp, #0x78]; b #0x93320]
uint64_t fde_sub_0920b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400049AULL) << 32) | 0xF9003FE8ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0920B4ULL;
}

// FDE #3633 | PC: 0x0920bc..0x0920c8 (12 B) | Symbol: sub_0920bc
// EN: AArch64 prologue [add x8, x8, #0x10; str x8, [x19]; ret] | VI: Khởi đầu hàm AArch64 [add x8, x8, #0x10; str x8, [x19]; ret]
uint64_t fde_sub_0920bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000268ULL) << 32) | 0x91004108ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0920BCULL;
}

// FDE #3634 | PC: 0x0920c8..0x0920d4 (12 B) | Symbol: sub_0920c8
// EN: AArch64 prologue [ldr x20, [sp, #8]; ldr d8, [sp], #0x20; ret] | VI: Khởi đầu hàm AArch64 [ldr x20, [sp, #8]; ldr d8, [sp], #0x20; ret]
uint64_t fde_sub_0920c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFC4207E8ULL) << 32) | 0xF94007F4ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0920C8ULL;
}

// FDE #3635 | PC: 0x0920d4..0x0920dc (8 B) | Symbol: sub_0920d4
// EN: AArch64 prologue [ldr x8, [x8, #0x38]; br x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x8, #0x38]; br x8]
uint64_t fde_sub_0920d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD61F0100ULL) << 32) | 0xF9401D08ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0920D4ULL;
}

// FDE #3636 | PC: 0x0920dc..0x0920e4 (8 B) | Symbol: sub_0920dc
// EN: AArch64 prologue [ldr x3, [x8, #0x10]; br x3] | VI: Khởi đầu hàm AArch64 [ldr x3, [x8, #0x10]; br x3]
uint64_t fde_sub_0920dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD61F0060ULL) << 32) | 0xF9400903ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0920DCULL;
}

// FDE #3637 | PC: 0x0920e4..0x0920ec (8 B) | Symbol: sub_0920e4
// EN: AArch64 prologue [add x0, sp, #0x128; b #0x937a0] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x128; b #0x937a0]
uint64_t fde_sub_0920e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140005AEULL) << 32) | 0x9104A3E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0920E4ULL;
}

// FDE #3638 | PC: 0x0920ec..0x0920f4 (8 B) | Symbol: sub_0920ec
// EN: AArch64 prologue [str q0, [x21], #0x30; b #0x44a54] | VI: Khởi đầu hàm AArch64 [str q0, [x21], #0x30; b #0x44a54]
uint64_t fde_sub_0920ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FECA59ULL) << 32) | 0x3C8306A0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0920ECULL;
}

// FDE #3639 | PC: 0x0920f4..0x0920fc (8 B) | Symbol: sub_0920f4
// EN: AArch64 prologue [add sp, sp, #0x1d0; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0x1d0; ret]
uint64_t fde_sub_0920f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910743FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0920F4ULL;
}

// FDE #3640 | PC: 0x0920fc..0x092110 (20 B) | Symbol: sub_0920fc
// EN: AArch64 prologue [ldr x8, [x1]; str xzr, [x1]; mov x19, x0; mov x1, x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1]; str xzr, [x1]; mov x19, x0; mov x1, x8]
uint64_t fde_sub_0920fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900003FULL) << 32) | 0xF9400028ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0920FCULL;
}

// FDE #3641 | PC: 0x092110..0x092124 (20 B) | Symbol: sub_092110
// EN: AArch64 prologue [ldr x8, [x1]; mov x20, x0; mov x19, x1; str x8, [x0]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1]; mov x20, x0; mov x19, x1; str x8, [x0]]
uint64_t fde_sub_092110(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F4ULL) << 32) | 0xF9400028ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092110ULL;
}

// FDE #3642 | PC: 0x092124..0x092130 (12 B) | Symbol: sub_092124
// EN: AArch64 prologue [and x9, x9, #0xfffffffffffffffe; sub x1, x9, #1; ret] | VI: Khởi đầu hàm AArch64 [and x9, x9, #0xfffffffffffffffe; sub x1, x9, #1; ret]
uint64_t fde_sub_092124(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD1000521ULL) << 32) | 0x927FF929ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092124ULL;
}

// FDE #3643 | PC: 0x092130..0x092144 (20 B) | Symbol: sub_092130
// EN: AArch64 prologue [fmov s3, w9; fadd s0, s0, s3; fmul s0, s0, s1; cmp w8, #0] | VI: Khởi đầu hàm AArch64 [fmov s3, w9; fadd s0, s0, s3; fmul s0, s0, s1; cmp w8, #0]
uint64_t fde_sub_092130(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E232800ULL) << 32) | 0x1E270123ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092130ULL;
}

// FDE #3644 | PC: 0x092144..0x092150 (12 B) | Symbol: sub_092144
// EN: AArch64 prologue [add x1, sp, #0xd0; mov x0, x25; b #0x754f4] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0xd0; mov x0, x25; b #0x754f4]
uint64_t fde_sub_092144(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1903E0ULL) << 32) | 0x910343E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092144ULL;
}

// FDE #3645 | PC: 0x092150..0x09215c (12 B) | Symbol: sub_092150
// EN: AArch64 prologue [mov x1, x23; mov x2, x24; b #0x7f158] | VI: Khởi đầu hàm AArch64 [mov x1, x23; mov x2, x24; b #0x7f158]
uint64_t fde_sub_092150(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1803E2ULL) << 32) | 0xAA1703E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092150ULL;
}

// FDE #3646 | PC: 0x09215c..0x092168 (12 B) | Symbol: sub_09215c
// EN: AArch64 prologue [mov x1, x23; mov x2, x4; b #0x7ed88] | VI: Khởi đầu hàm AArch64 [mov x1, x23; mov x2, x4; b #0x7ed88]
uint64_t fde_sub_09215c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0403E2ULL) << 32) | 0xAA1703E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09215CULL;
}

// FDE #3647 | PC: 0x092168..0x092174 (12 B) | Symbol: sub_092168
// EN: AArch64 prologue [mov x25, x0; mov x0, x26; b #0x93cc0] | VI: Khởi đầu hàm AArch64 [mov x25, x0; mov x0, x26; b #0x93cc0]
uint64_t fde_sub_092168(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1A03E0ULL) << 32) | 0xAA0003F9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092168ULL;
}

// FDE #3648 | PC: 0x092174..0x092180 (12 B) | Symbol: sub_092174
// EN: AArch64 prologue [sub x8, x25, #1; tst x25, x8; ret] | VI: Khởi đầu hàm AArch64 [sub x8, x25, #1; tst x25, x8; ret]
uint64_t fde_sub_092174(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEA08033FULL) << 32) | 0xD1000728ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092174ULL;
}

// FDE #3649 | PC: 0x092180..0x09219c (28 B) | Symbol: sub_092180
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x44830; mov x0, xzr; bl #0x48d40] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x44830; mov x0, xzr; bl #0x48d40]
uint64_t fde_sub_092180(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x97FEC9ABULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092180ULL;
}

// FDE #3650 | PC: 0x09219c..0x0921a8 (12 B) | Symbol: sub_09219c
// EN: AArch64 prologue [add x9, x8, #1; str x9, [x19, #0x18]; ret] | VI: Khởi đầu hàm AArch64 [add x9, x8, #1; str x9, [x19, #0x18]; ret]
uint64_t fde_sub_09219c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000E69ULL) << 32) | 0x91000509ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09219CULL;
}

// FDE #3651 | PC: 0x0921a8..0x0921bc (20 B) | Symbol: sub_0921a8
// EN: AArch64 prologue [add x9, x8, #1; str x9, [x19, #0x18]; strb w29, [x8]; ldp x8, x9, [x19, #0x18]] | VI: Khởi đầu hàm AArch64 [add x9, x8, #1; str x9, [x19, #0x18]; strb w29, [x8]; ldp x8, x9, [x19, #0x18]]
uint64_t fde_sub_0921a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000E69ULL) << 32) | 0x91000509ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0921A8ULL;
}

// FDE #3652 | PC: 0x0921bc..0x0921d0 (20 B) | Symbol: sub_0921bc
// EN: AArch64 prologue [add x9, x8, #1; str x9, [x19, #0x18]; strb w28, [x8]; ldp x8, x9, [x19, #0x18]] | VI: Khởi đầu hàm AArch64 [add x9, x8, #1; str x9, [x19, #0x18]; strb w28, [x8]; ldp x8, x9, [x19, #0x18]]
uint64_t fde_sub_0921bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000E69ULL) << 32) | 0x91000509ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0921BCULL;
}

// FDE #3653 | PC: 0x0921d0..0x0921dc (12 B) | Symbol: sub_0921d0
// EN: AArch64 prologue [adrp x1, #0x1b000; add x1, x1, #0xfd9; ret] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x1b000; add x1, x1, #0xfd9; ret]
uint64_t fde_sub_0921d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x913F6421ULL) << 32) | 0xB0FFFC41ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0921D0ULL;
}

// FDE #3654 | PC: 0x0921dc..0x0921e4 (8 B) | Symbol: sub_0921dc
// EN: AArch64 prologue [add x0, x27, #0x18; b #0x6f7a8] | VI: Khởi đầu hàm AArch64 [add x0, x27, #0x18; b #0x6f7a8]
uint64_t fde_sub_0921dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF7572ULL) << 32) | 0x91006360ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0921DCULL;
}

// FDE #3655 | PC: 0x0921e4..0x0921f0 (12 B) | Symbol: sub_0921e4
// EN: AArch64 prologue [fmov s0, wzr; fmov s1, wzr; ret] | VI: Khởi đầu hàm AArch64 [fmov s0, wzr; fmov s1, wzr; ret]
uint64_t fde_sub_0921e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E2703E1ULL) << 32) | 0x1E2703E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0921E4ULL;
}

// FDE #3656 | PC: 0x0921f0..0x0921fc (12 B) | Symbol: sub_0921f0
// EN: AArch64 prologue [add x0, x19, #0x10; add x1, sp, #8; b #0x7717c] | VI: Khởi đầu hàm AArch64 [add x0, x19, #0x10; add x1, sp, #8; b #0x7717c]
uint64_t fde_sub_0921f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910023E1ULL) << 32) | 0x91004260ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0921F0ULL;
}

// FDE #3657 | PC: 0x0921fc..0x092210 (20 B) | Symbol: sub_0921fc
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x46964; add x21, x21, #0x10; ldr x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x46964; add x21, x21, #0x10; ldr x30, [sp], #0x10]
uint64_t fde_sub_0921fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x97FED1D9ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0921FCULL;
}

// FDE #3658 | PC: 0x092210..0x092218 (8 B) | Symbol: sub_092210
// EN: AArch64 prologue [add x1, sp, #0xf0; b #0x47f90] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0xf0; b #0x47f90]
uint64_t fde_sub_092210(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED75FULL) << 32) | 0x9103C3E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092210ULL;
}

// FDE #3659 | PC: 0x092218..0x092224 (12 B) | Symbol: sub_092218
// EN: AArch64 prologue [mov x1, #-1; mov x0, xzr; ret] | VI: Khởi đầu hàm AArch64 [mov x1, #-1; mov x0, xzr; ret]
uint64_t fde_sub_092218(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E0ULL) << 32) | 0x92800001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092218ULL;
}

// FDE #3660 | PC: 0x092224..0x092230 (12 B) | Symbol: sub_092224
// EN: AArch64 prologue [stp xzr, xzr, [x19]; str xzr, [x19, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x19]; str xzr, [x19, #0x10]; ret]
uint64_t fde_sub_092224(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000A7FULL) << 32) | 0xA9007E7FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092224ULL;
}

// FDE #3661 | PC: 0x092230..0x092244 (20 B) | Symbol: sub_092230
// EN: AArch64 prologue [movi v0.2d, #0000000000000000; mov w8, #0x3f800000; stp q0, q0, [sp, #0x50]; str w8, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [movi v0.2d, #0000000000000000; mov w8, #0x3f800000; stp q0, q0, [sp, #0x50]; str w8, [sp, #0x70]]
uint64_t fde_sub_092230(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52A7F008ULL) << 32) | 0x6F00E400ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092230ULL;
}

// FDE #3662 | PC: 0x092244..0x09224c (8 B) | Symbol: sub_092244
// EN: AArch64 prologue [str x8, [x0], #8; b #0x7ef7c] | VI: Khởi đầu hàm AArch64 [str x8, [x0], #8; b #0x7ef7c]
uint64_t fde_sub_092244(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFB34DULL) << 32) | 0xF8008408ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092244ULL;
}

// FDE #3663 | PC: 0x09224c..0x092254 (8 B) | Symbol: sub_09224c
// EN: AArch64 prologue [str x8, [x0], #8; b #0x7d610] | VI: Khởi đầu hàm AArch64 [str x8, [x0], #8; b #0x7d610]
uint64_t fde_sub_09224c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFACF0ULL) << 32) | 0xF8008408ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09224CULL;
}

// FDE #3664 | PC: 0x092254..0x092260 (12 B) | Symbol: sub_092254
// EN: AArch64 prologue [str q0, [sp, #0x30]; str x8, [sp, #0x40]; b #0x47ff4] | VI: Khởi đầu hàm AArch64 [str q0, [sp, #0x30]; str x8, [sp, #0x40]; b #0x47ff4]
uint64_t fde_sub_092254(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023E8ULL) << 32) | 0x3D800FE0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092254ULL;
}

// FDE #3665 | PC: 0x092260..0x092268 (8 B) | Symbol: sub_092260
// EN: AArch64 prologue [ldr x0, [x19, #0x18]; br x8] | VI: Khởi đầu hàm AArch64 [ldr x0, [x19, #0x18]; br x8]
uint64_t fde_sub_092260(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD61F0100ULL) << 32) | 0xF9400E60ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092260ULL;
}

// FDE #3666 | PC: 0x092268..0x092270 (8 B) | Symbol: sub_092268
// EN: AArch64 prologue [ldr x0, [sp, #0xb8]; b #0x44830] | VI: Khởi đầu hàm AArch64 [ldr x0, [sp, #0xb8]; b #0x44830]
uint64_t fde_sub_092268(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC971ULL) << 32) | 0xF9405FE0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092268ULL;
}

// FDE #3667 | PC: 0x092270..0x09227c (12 B) | Symbol: sub_092270
// EN: AArch64 prologue [ldr x22, [sp, #8]; ldr x0, [x22, #8]; b #0x8c244] | VI: Khởi đầu hàm AArch64 [ldr x22, [sp, #8]; ldr x0, [x22, #8]; b #0x8c244]
uint64_t fde_sub_092270(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94006C0ULL) << 32) | 0xF94007F6ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092270ULL;
}

// FDE #3668 | PC: 0x09227c..0x092288 (12 B) | Symbol: sub_09227c
// EN: AArch64 prologue [ldp x21, x20, [sp, #0x10]; ldr d8, [sp], #0x30; ret] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp, #0x10]; ldr d8, [sp], #0x30; ret]
uint64_t fde_sub_09227c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFC4307E8ULL) << 32) | 0xA94153F5ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09227CULL;
}

// FDE #3669 | PC: 0x092288..0x092294 (12 B) | Symbol: sub_092288
// EN: AArch64 prologue [ldr x0, [x20]; ldr x1, [x22]; b #0x89f24] | VI: Khởi đầu hàm AArch64 [ldr x0, [x20]; ldr x1, [x22]; b #0x89f24]
uint64_t fde_sub_092288(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94002C1ULL) << 32) | 0xF9400280ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092288ULL;
}

// FDE #3670 | PC: 0x092294..0x09229c (8 B) | Symbol: sub_092294
// EN: AArch64 prologue [ldr x0, [x20]; b #0x89f28] | VI: Khởi đầu hàm AArch64 [ldr x0, [x20]; b #0x89f28]
uint64_t fde_sub_092294(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFDF24ULL) << 32) | 0xF9400280ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092294ULL;
}

// FDE #3671 | PC: 0x09229c..0x0922a4 (8 B) | Symbol: sub_09229c
// EN: AArch64 prologue [ldr x0, [x20]; b #0x932e0] | VI: Khởi đầu hàm AArch64 [ldr x0, [x20]; b #0x932e0]
uint64_t fde_sub_09229c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000410ULL) << 32) | 0xF9400280ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09229CULL;
}

// FDE #3672 | PC: 0x0922a4..0x0922b0 (12 B) | Symbol: sub_0922a4
// EN: AArch64 prologue [str x9, [x19, #0x28]; str x8, [x19, #0x48]; b #0x5be2c] | VI: Khởi đầu hàm AArch64 [str x9, [x19, #0x28]; str x8, [x19, #0x48]; b #0x5be2c]
uint64_t fde_sub_0922a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9002668ULL) << 32) | 0xF9001669ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0922A4ULL;
}

// FDE #3673 | PC: 0x0922b0..0x0922bc (12 B) | Symbol: sub_0922b0
// EN: AArch64 prologue [ldp w1, w2, [x19, #8]; add x0, x19, #0x18; b #0x7d4bc] | VI: Khởi đầu hàm AArch64 [ldp w1, w2, [x19, #8]; add x0, x19, #0x18; b #0x7d4bc]
uint64_t fde_sub_0922b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91006260ULL) << 32) | 0x29410A61ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0922B0ULL;
}

// FDE #3674 | PC: 0x0922bc..0x0922d0 (20 B) | Symbol: sub_0922bc
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x4aaf4; ldr x0, [x19]; ldr x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x4aaf4; ldr x0, [x19]; ldr x30, [sp], #0x10]
uint64_t fde_sub_0922bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x97FEE20DULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0922BCULL;
}

// FDE #3675 | PC: 0x0922d0..0x0922ec (28 B) | Symbol: sub_0922d0
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x4aaf4; add x0, x20, #0x78; bl #0x4aaf4] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x4aaf4; add x0, x20, #0x78; bl #0x4aaf4]
uint64_t fde_sub_0922d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x97FEE208ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0922D0ULL;
}

// FDE #3676 | PC: 0x0922ec..0x092300 (20 B) | Symbol: sub_0922ec
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x4aaf4; ldr x8, [sp, #0x98]; ldr x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x4aaf4; ldr x8, [sp, #0x98]; ldr x30, [sp], #0x10]
uint64_t fde_sub_0922ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x97FEE201ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0922ECULL;
}

// FDE #3677 | PC: 0x092300..0x09230c (12 B) | Symbol: sub_092300
// EN: AArch64 prologue [ldr x0, [sp, #0x218]; str xzr, [sp, #0x218]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [sp, #0x218]; str xzr, [sp, #0x218]; ret]
uint64_t fde_sub_092300(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9010FFFULL) << 32) | 0xF9410FE0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092300ULL;
}

// FDE #3678 | PC: 0x09230c..0x092314 (8 B) | Symbol: sub_09230c
// EN: AArch64 prologue [add x0, sp, #0xb0; b #0x46c54] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0xb0; b #0x46c54]
uint64_t fde_sub_09230c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED251ULL) << 32) | 0x9102C3E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09230CULL;
}

// FDE #3679 | PC: 0x092314..0x092328 (20 B) | Symbol: sub_092314
// EN: AArch64 prologue [add x9, x0, x26, lsl #3; mov x10, x9; add x8, x0, x27, lsl #3; str xzr, [sp, #8]] | VI: Khởi đầu hàm AArch64 [add x9, x0, x26, lsl #3; mov x10, x9; add x8, x0, x27, lsl #3; str xzr, [sp, #8]]
uint64_t fde_sub_092314(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0903EAULL) << 32) | 0x8B1A0C09ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092314ULL;
}

// FDE #3680 | PC: 0x092328..0x092330 (8 B) | Symbol: sub_092328
// EN: AArch64 prologue [ldrh w0, [x0, #0x14]; ret] | VI: Khởi đầu hàm AArch64 [ldrh w0, [x0, #0x14]; ret]
uint64_t fde_sub_092328(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x79402800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092328ULL;
}

// FDE #3681 | PC: 0x092330..0x09233c (12 B) | Symbol: sub_092330
// EN: AArch64 prologue [stp x9, xzr, [x0]; stp xzr, x25, [x0, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [stp x9, xzr, [x0]; stp xzr, x25, [x0, #0x10]; ret]
uint64_t fde_sub_092330(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA901641FULL) << 32) | 0xA9007C09ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092330ULL;
}

// FDE #3682 | PC: 0x09233c..0x092348 (12 B) | Symbol: sub_09233c
// EN: AArch64 prologue [mov x2, x20; mov w3, w19; ret] | VI: Khởi đầu hàm AArch64 [mov x2, x20; mov w3, w19; ret]
uint64_t fde_sub_09233c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1303E3ULL) << 32) | 0xAA1403E2ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09233CULL;
}

// FDE #3683 | PC: 0x092348..0x092354 (12 B) | Symbol: sub_092348
// EN: AArch64 prologue [mov x22, x0; mov x0, x21; b #0x5b1c8] | VI: Khởi đầu hàm AArch64 [mov x22, x0; mov x0, x21; b #0x5b1c8]
uint64_t fde_sub_092348(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E0ULL) << 32) | 0xAA0003F6ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092348ULL;
}

// FDE #3684 | PC: 0x092354..0x092360 (12 B) | Symbol: sub_092354
// EN: AArch64 prologue [add x1, sp, #0xb0; mov x0, x23; ret] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0xb0; mov x0, x23; ret]
uint64_t fde_sub_092354(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1703E0ULL) << 32) | 0x9102C3E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092354ULL;
}

// FDE #3685 | PC: 0x092360..0x09236c (12 B) | Symbol: sub_092360
// EN: AArch64 prologue [add x1, sp, #0xb0; mov x0, x21; b #0x75038] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0xb0; mov x0, x21; b #0x75038]
uint64_t fde_sub_092360(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E0ULL) << 32) | 0x9102C3E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092360ULL;
}

// FDE #3686 | PC: 0x09236c..0x092378 (12 B) | Symbol: sub_09236c
// EN: AArch64 prologue [add x1, sp, #0xb0; mov x0, x20; b #0x75038] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0xb0; mov x0, x20; b #0x75038]
uint64_t fde_sub_09236c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0x9102C3E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09236CULL;
}

// FDE #3687 | PC: 0x092378..0x09238c (20 B) | Symbol: sub_092378
// EN: AArch64 prologue [str xzr, [x8, #8]!; str x0, [sp, #0x28]; str x9, [x0]; stp x20, x0, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [str xzr, [x8, #8]!; str x0, [sp, #0x28]; str x9, [x0]; stp x20, x0, [sp, #0x60]]
uint64_t fde_sub_092378(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90017E0ULL) << 32) | 0xF8008D1FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092378ULL;
}

// FDE #3688 | PC: 0x09238c..0x092398 (12 B) | Symbol: sub_09238c
// EN: AArch64 prologue [str x8, [sp, #0x20]; str q0, [sp, #0x10]; b #0x47ff4] | VI: Khởi đầu hàm AArch64 [str x8, [sp, #0x20]; str q0, [sp, #0x10]; b #0x47ff4]
uint64_t fde_sub_09238c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3D8007E0ULL) << 32) | 0xF90013E8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09238CULL;
}

// FDE #3689 | PC: 0x092398..0x0923a0 (8 B) | Symbol: sub_092398
// EN: AArch64 prologue [add x1, sp, #0x20; b #0x4c4d4] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0x20; b #0x4c4d4]
uint64_t fde_sub_092398(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE84EULL) << 32) | 0x910083E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092398ULL;
}

// FDE #3690 | PC: 0x0923a0..0x0923ac (12 B) | Symbol: sub_0923a0
// EN: AArch64 prologue [add x1, sp, #0x20; mov x0, x21; b #0x48da4] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0x20; mov x0, x21; b #0x48da4]
uint64_t fde_sub_0923a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E0ULL) << 32) | 0x910083E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0923A0ULL;
}

// FDE #3691 | PC: 0x0923ac..0x0923c0 (20 B) | Symbol: sub_0923ac
// EN: AArch64 prologue [add x1, sp, #0x20; add x2, sp, #0x18; add x3, sp, #0x10; mov w0, w20] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0x20; add x2, sp, #0x18; add x3, sp, #0x10; mov w0, w20]
uint64_t fde_sub_0923ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910063E2ULL) << 32) | 0x910083E1ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0923ACULL;
}

// FDE #3692 | PC: 0x0923c0..0x0923d4 (20 B) | Symbol: sub_0923c0
// EN: AArch64 prologue [ldr x8, [sp]; str xzr, [sp]; ldr x0, [x19, #0x40]; str x8, [x19, #0x40]] | VI: Khởi đầu hàm AArch64 [ldr x8, [sp]; str xzr, [sp]; ldr x0, [x19, #0x40]; str x8, [x19, #0x40]]
uint64_t fde_sub_0923c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90003FFULL) << 32) | 0xF94003E8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0923C0ULL;
}

// FDE #3693 | PC: 0x0923d4..0x0923e8 (20 B) | Symbol: sub_0923d4
// EN: AArch64 prologue [ldr x8, [sp]; str xzr, [sp]; ldr x0, [x19, #0x48]; str x8, [x19, #0x48]] | VI: Khởi đầu hàm AArch64 [ldr x8, [sp]; str xzr, [sp]; ldr x0, [x19, #0x48]; str x8, [x19, #0x48]]
uint64_t fde_sub_0923d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90003FFULL) << 32) | 0xF94003E8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0923D4ULL;
}

// FDE #3694 | PC: 0x0923e8..0x0923fc (20 B) | Symbol: sub_0923e8
// EN: AArch64 prologue [ldr x8, [sp]; str xzr, [sp]; ldr x0, [x19, #0x58]; str x8, [x19, #0x58]] | VI: Khởi đầu hàm AArch64 [ldr x8, [sp]; str xzr, [sp]; ldr x0, [x19, #0x58]; str x8, [x19, #0x58]]
uint64_t fde_sub_0923e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90003FFULL) << 32) | 0xF94003E8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0923E8ULL;
}

// FDE #3695 | PC: 0x0923fc..0x092410 (20 B) | Symbol: sub_0923fc
// EN: AArch64 prologue [ldr x8, [sp]; str xzr, [sp]; ldr x0, [x19, #0x68]; str x8, [x19, #0x68]] | VI: Khởi đầu hàm AArch64 [ldr x8, [sp]; str xzr, [sp]; ldr x0, [x19, #0x68]; str x8, [x19, #0x68]]
uint64_t fde_sub_0923fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90003FFULL) << 32) | 0xF94003E8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0923FCULL;
}

// FDE #3696 | PC: 0x092410..0x092424 (20 B) | Symbol: sub_092410
// EN: AArch64 prologue [ldr x8, [sp]; str xzr, [sp]; ldr x0, [x19, #0x70]; str x8, [x19, #0x70]] | VI: Khởi đầu hàm AArch64 [ldr x8, [sp]; str xzr, [sp]; ldr x0, [x19, #0x70]; str x8, [x19, #0x70]]
uint64_t fde_sub_092410(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90003FFULL) << 32) | 0xF94003E8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092410ULL;
}

// FDE #3697 | PC: 0x092424..0x092438 (20 B) | Symbol: sub_092424
// EN: AArch64 prologue [ldr x8, [sp]; str xzr, [sp]; ldr x0, [x19, #0x50]; str x8, [x19, #0x50]] | VI: Khởi đầu hàm AArch64 [ldr x8, [sp]; str xzr, [sp]; ldr x0, [x19, #0x50]; str x8, [x19, #0x50]]
uint64_t fde_sub_092424(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90003FFULL) << 32) | 0xF94003E8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092424ULL;
}

// FDE #3698 | PC: 0x092438..0x09244c (20 B) | Symbol: sub_092438
// EN: AArch64 prologue [ldr w8, [x20, #0x18]; mov x19, x20; cmp w8, #1; cset w8, eq] | VI: Khởi đầu hàm AArch64 [ldr w8, [x20, #0x18]; mov x19, x20; cmp w8, #1; cset w8, eq]
uint64_t fde_sub_092438(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403F3ULL) << 32) | 0xB9401A88ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092438ULL;
}

// FDE #3699 | PC: 0x09244c..0x092454 (8 B) | Symbol: sub_09244c
// EN: AArch64 prologue [add x0, sp, #0x10; b #0x75540] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x10; b #0x75540]
uint64_t fde_sub_09244c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF8C3CULL) << 32) | 0x910043E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09244CULL;
}

// FDE #3700 | PC: 0x092454..0x092460 (12 B) | Symbol: sub_092454
// EN: AArch64 prologue [add x0, sp, #0x10; add x1, sp, #0x40; b #0x49950] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x10; add x1, sp, #0x40; b #0x49950]
uint64_t fde_sub_092454(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910103E1ULL) << 32) | 0x910043E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092454ULL;
}

// FDE #3701 | PC: 0x092460..0x092468 (8 B) | Symbol: sub_092460
// EN: AArch64 prologue [add x0, sp, #0x10; b #0x497b4] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x10; b #0x497b4]
uint64_t fde_sub_092460(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDCD4ULL) << 32) | 0x910043E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092460ULL;
}

// FDE #3702 | PC: 0x092468..0x092474 (12 B) | Symbol: sub_092468
// EN: AArch64 prologue [add x9, x9, #1; str x9, [x8]; ret] | VI: Khởi đầu hàm AArch64 [add x9, x9, #1; str x9, [x8]; ret]
uint64_t fde_sub_092468(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000109ULL) << 32) | 0x91000529ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092468ULL;
}

// FDE #3703 | PC: 0x092474..0x092480 (12 B) | Symbol: sub_092474
// EN: AArch64 prologue [stur q0, [sp, #0x18]; str x9, [sp, #0x28]; b #0x47ff4] | VI: Khởi đầu hàm AArch64 [stur q0, [sp, #0x18]; str x9, [sp, #0x28]; b #0x47ff4]
uint64_t fde_sub_092474(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90017E9ULL) << 32) | 0x3C8183E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092474ULL;
}

// FDE #3704 | PC: 0x092480..0x092488 (8 B) | Symbol: sub_092480
// EN: AArch64 prologue [add x1, x1, #0xbd8; b #0x93910] | VI: Khởi đầu hàm AArch64 [add x1, x1, #0xbd8; b #0x93910]
uint64_t fde_sub_092480(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000523ULL) << 32) | 0x912F6021ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092480ULL;
}

// FDE #3705 | PC: 0x092488..0x092490 (8 B) | Symbol: sub_092488
// EN: AArch64 prologue [add x1, x1, #0x92f; b #0x93910] | VI: Khởi đầu hàm AArch64 [add x1, x1, #0x92f; b #0x93910]
uint64_t fde_sub_092488(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000521ULL) << 32) | 0x9124BC21ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092488ULL;
}

// FDE #3706 | PC: 0x092490..0x09249c (12 B) | Symbol: sub_092490
// EN: AArch64 prologue [mov w1, w0; mov x0, x21; b #0x496f8] | VI: Khởi đầu hàm AArch64 [mov w1, w0; mov x0, x21; b #0x496f8]
uint64_t fde_sub_092490(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E0ULL) << 32) | 0x2A0003E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092490ULL;
}

// FDE #3707 | PC: 0x09249c..0x0924a8 (12 B) | Symbol: sub_09249c
// EN: AArch64 prologue [mov w1, w0; mov x0, x19; b #0x496f8] | VI: Khởi đầu hàm AArch64 [mov w1, w0; mov x0, x19; b #0x496f8]
uint64_t fde_sub_09249c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x2A0003E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09249CULL;
}

// FDE #3708 | PC: 0x0924a8..0x0924b4 (12 B) | Symbol: sub_0924a8
// EN: AArch64 prologue [mov w1, w0; add x0, sp, #0xa8; b #0x941a0] | VI: Khởi đầu hàm AArch64 [mov w1, w0; add x0, sp, #0xa8; b #0x941a0]
uint64_t fde_sub_0924a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9102A3E0ULL) << 32) | 0x2A0003E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0924A8ULL;
}

// FDE #3709 | PC: 0x0924b4..0x0924c0 (12 B) | Symbol: sub_0924b4
// EN: AArch64 prologue [ldr x8, [x20]; str xzr, [x20]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x20]; str xzr, [x20]; ret]
uint64_t fde_sub_0924b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900029FULL) << 32) | 0xF9400288ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0924B4ULL;
}

// FDE #3710 | PC: 0x0924c0..0x0924cc (12 B) | Symbol: sub_0924c0
// EN: AArch64 prologue [mov x19, x1; mov x21, x0; ret] | VI: Khởi đầu hàm AArch64 [mov x19, x1; mov x21, x0; ret]
uint64_t fde_sub_0924c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F5ULL) << 32) | 0xAA0103F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0924C0ULL;
}

// FDE #3711 | PC: 0x0924cc..0x0924d8 (12 B) | Symbol: sub_0924cc
// EN: AArch64 prologue [mov x19, x1; mov x20, x0; b #0x77910] | VI: Khởi đầu hàm AArch64 [mov x19, x1; mov x20, x0; b #0x77910]
uint64_t fde_sub_0924cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F4ULL) << 32) | 0xAA0103F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0924CCULL;
}

// FDE #3712 | PC: 0x0924d8..0x0924ec (20 B) | Symbol: sub_0924d8
// EN: AArch64 prologue [mov x19, x1; mov x20, x0; mov x0, x1; mov x1, x2] | VI: Khởi đầu hàm AArch64 [mov x19, x1; mov x20, x0; mov x0, x1; mov x1, x2]
uint64_t fde_sub_0924d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F4ULL) << 32) | 0xAA0103F3ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0924D8ULL;
}

// FDE #3713 | PC: 0x0924ec..0x0924f8 (12 B) | Symbol: sub_0924ec
// EN: AArch64 prologue [mov x0, xzr; str q0, [sp, #0x60]; b #0x48d40] | VI: Khởi đầu hàm AArch64 [mov x0, xzr; str q0, [sp, #0x60]; b #0x48d40]
uint64_t fde_sub_0924ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3D801BE0ULL) << 32) | 0xAA1F03E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0924ECULL;
}

// FDE #3714 | PC: 0x0924f8..0x092504 (12 B) | Symbol: sub_0924f8
// EN: AArch64 prologue [mov x0, xzr; mov x1, xzr; b #0x811ec] | VI: Khởi đầu hàm AArch64 [mov x0, xzr; mov x1, xzr; b #0x811ec]
uint64_t fde_sub_0924f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E1ULL) << 32) | 0xAA1F03E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0924F8ULL;
}

// FDE #3715 | PC: 0x092504..0x09250c (8 B) | Symbol: sub_092504
// EN: AArch64 prologue [add x1, x8, #0x28; b #0x484a8] | VI: Khởi đầu hàm AArch64 [add x1, x8, #0x28; b #0x484a8]
uint64_t fde_sub_092504(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED7E8ULL) << 32) | 0x9100A101ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092504ULL;
}

// FDE #3716 | PC: 0x09250c..0x092518 (12 B) | Symbol: sub_09250c
// EN: AArch64 prologue [add x1, x8, #0x28; ldr x20, [sp], #0x20; b #0x4647c] | VI: Khởi đầu hàm AArch64 [add x1, x8, #0x28; ldr x20, [sp], #0x20; b #0x4647c]
uint64_t fde_sub_09250c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF84207F4ULL) << 32) | 0x9100A101ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09250CULL;
}

// FDE #3717 | PC: 0x092518..0x09252c (20 B) | Symbol: sub_092518
// EN: AArch64 prologue [mov x2, x0; mov x0, x21; mov x1, x29; mov w3, w22] | VI: Khởi đầu hàm AArch64 [mov x2, x0; mov x0, x21; mov x1, x29; mov w3, w22]
uint64_t fde_sub_092518(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E0ULL) << 32) | 0xAA0003E2ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092518ULL;
}

// FDE #3718 | PC: 0x09252c..0x092540 (20 B) | Symbol: sub_09252c
// EN: AArch64 prologue [mov x2, x0; mov x0, x21; mov x1, x26; mov x3, x19] | VI: Khởi đầu hàm AArch64 [mov x2, x0; mov x0, x21; mov x1, x26; mov x3, x19]
uint64_t fde_sub_09252c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E0ULL) << 32) | 0xAA0003E2ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09252CULL;
}

// FDE #3719 | PC: 0x092540..0x092554 (20 B) | Symbol: sub_092540
// EN: AArch64 prologue [mov x2, x0; mov x0, x22; mov x1, x20; mov x3, x19] | VI: Khởi đầu hàm AArch64 [mov x2, x0; mov x0, x22; mov x1, x20; mov x3, x19]
uint64_t fde_sub_092540(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E0ULL) << 32) | 0xAA0003E2ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092540ULL;
}

// FDE #3720 | PC: 0x092554..0x092568 (20 B) | Symbol: sub_092554
// EN: AArch64 prologue [mov x8, x21; str x22, [x8, #0x20]!; ldr x0, [x8, #8]; str x21, [x21, #0x28]] | VI: Khởi đầu hàm AArch64 [mov x8, x21; str x22, [x8, #0x20]!; ldr x0, [x8, #8]; str x21, [x21, #0x28]]
uint64_t fde_sub_092554(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF8020D16ULL) << 32) | 0xAA1503E8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092554ULL;
}

// FDE #3721 | PC: 0x092568..0x092570 (8 B) | Symbol: sub_092568
// EN: AArch64 prologue [mov x0, x8; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x8; ret]
uint64_t fde_sub_092568(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xAA0803E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092568ULL;
}

// FDE #3722 | PC: 0x092570..0x092584 (20 B) | Symbol: sub_092570
// EN: AArch64 prologue [fmov d0, x8; mov x19, x0; mov x20, x0; mov v0.d[1], x9] | VI: Khởi đầu hàm AArch64 [fmov d0, x8; mov x19, x0; mov x20, x0; mov v0.d[1], x9]
uint64_t fde_sub_092570(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0x9E670100ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092570ULL;
}

// FDE #3723 | PC: 0x092584..0x092590 (12 B) | Symbol: sub_092584
// EN: AArch64 prologue [ldr x0, [x19, #8]; add x1, sp, #8; b #0x8c324] | VI: Khởi đầu hàm AArch64 [ldr x0, [x19, #8]; add x1, sp, #8; b #0x8c324]
uint64_t fde_sub_092584(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910023E1ULL) << 32) | 0xF9400660ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092584ULL;
}

// FDE #3724 | PC: 0x092590..0x09259c (12 B) | Symbol: sub_092590
// EN: AArch64 prologue [ldr x0, [sp, #0xd0]; str xzr, [sp, #0xd0]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [sp, #0xd0]; str xzr, [sp, #0xd0]; ret]
uint64_t fde_sub_092590(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9006BFFULL) << 32) | 0xF9406BE0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092590ULL;
}

// FDE #3725 | PC: 0x09259c..0x0925a4 (8 B) | Symbol: sub_09259c
// EN: AArch64 prologue [add x0, sp, #0xc0; b #0x47f90] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0xc0; b #0x47f90]
uint64_t fde_sub_09259c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED67CULL) << 32) | 0x910303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09259CULL;
}

// FDE #3726 | PC: 0x0925a4..0x0925b0 (12 B) | Symbol: sub_0925a4
// EN: AArch64 prologue [ldr x0, [sp, #0xb0]; str xzr, [sp, #0xb0]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [sp, #0xb0]; str xzr, [sp, #0xb0]; ret]
uint64_t fde_sub_0925a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9005BFFULL) << 32) | 0xF9405BE0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0925A4ULL;
}

// FDE #3727 | PC: 0x0925b0..0x0925b8 (8 B) | Symbol: sub_0925b0
// EN: AArch64 prologue [add x2, x2, #0; b #0x93190] | VI: Khởi đầu hàm AArch64 [add x2, x2, #0; b #0x93190]
uint64_t fde_sub_0925b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140002F7ULL) << 32) | 0x91000042ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0925B0ULL;
}

// FDE #3728 | PC: 0x0925b8..0x0925c0 (8 B) | Symbol: sub_0925b8
// EN: AArch64 prologue [lsl x0, x8, #3; b #0x93320] | VI: Khởi đầu hàm AArch64 [lsl x0, x8, #3; b #0x93320]
uint64_t fde_sub_0925b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000359ULL) << 32) | 0xD37DF100ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0925B8ULL;
}

// FDE #3729 | PC: 0x0925c0..0x0925cc (12 B) | Symbol: sub_0925c0
// EN: AArch64 prologue [add x8, x0, x0, lsl #1; lsl x0, x8, #3; b #0x93320] | VI: Khởi đầu hàm AArch64 [add x8, x0, x0, lsl #1; lsl x0, x8, #3; b #0x93320]
uint64_t fde_sub_0925c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD37DF100ULL) << 32) | 0x8B000408ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0925C0ULL;
}

// FDE #3730 | PC: 0x0925cc..0x0925d8 (12 B) | Symbol: sub_0925cc
// EN: AArch64 prologue [add x0, sp, #0x28; add x1, sp, #0x18; b #0x81538] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x28; add x1, sp, #0x18; b #0x81538]
uint64_t fde_sub_0925cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910063E1ULL) << 32) | 0x9100A3E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0925CCULL;
}

// FDE #3731 | PC: 0x0925d8..0x0925e4 (12 B) | Symbol: sub_0925d8
// EN: AArch64 prologue [stp x9, x8, [x0, #0x70]; str w2, [x0, #0x88]; ret] | VI: Khởi đầu hàm AArch64 [stp x9, x8, [x0, #0x70]; str w2, [x0, #0x88]; ret]
uint64_t fde_sub_0925d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9008802ULL) << 32) | 0xA9072009ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0925D8ULL;
}

// FDE #3732 | PC: 0x0925e4..0x0925f0 (12 B) | Symbol: sub_0925e4
// EN: AArch64 prologue [adrp x1, #0x1f000; add x1, x1, #0x202; b #0x4696c] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x1f000; add x1, x1, #0x202; b #0x4696c]
uint64_t fde_sub_0925e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91080821ULL) << 32) | 0xB0FFFC61ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0925E4ULL;
}

// FDE #3733 | PC: 0x0925f0..0x0925fc (12 B) | Symbol: sub_0925f0
// EN: AArch64 prologue [mov x1, x0; mov x0, x23; b #0x8bd78] | VI: Khởi đầu hàm AArch64 [mov x1, x0; mov x0, x23; b #0x8bd78]
uint64_t fde_sub_0925f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1703E0ULL) << 32) | 0xAA0003E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0925F0ULL;
}

// FDE #3734 | PC: 0x0925fc..0x092608 (12 B) | Symbol: sub_0925fc
// EN: AArch64 prologue [mov x1, x0; mov x0, x24; ret] | VI: Khởi đầu hàm AArch64 [mov x1, x0; mov x0, x24; ret]
uint64_t fde_sub_0925fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1803E0ULL) << 32) | 0xAA0003E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0925FCULL;
}

// FDE #3735 | PC: 0x092608..0x092614 (12 B) | Symbol: sub_092608
// EN: AArch64 prologue [mov x1, x0; add x0, sp, #0x90; b #0x498a0] | VI: Khởi đầu hàm AArch64 [mov x1, x0; add x0, sp, #0x90; b #0x498a0]
uint64_t fde_sub_092608(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910243E0ULL) << 32) | 0xAA0003E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092608ULL;
}

// FDE #3736 | PC: 0x092614..0x092620 (12 B) | Symbol: sub_092614
// EN: AArch64 prologue [mov w0, #0x20; strb w19, [sp, #0x30]; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov w0, #0x20; strb w19, [sp, #0x30]; b #0x93320]
uint64_t fde_sub_092614(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3900C3F3ULL) << 32) | 0x52800400ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092614ULL;
}

// FDE #3737 | PC: 0x092620..0x09262c (12 B) | Symbol: sub_092620
// EN: AArch64 prologue [mov w0, #0x20; str x19, [sp, #0x30]; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov w0, #0x20; str x19, [sp, #0x30]; b #0x93320]
uint64_t fde_sub_092620(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF3ULL) << 32) | 0x52800400ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092620ULL;
}

// FDE #3738 | PC: 0x09262c..0x092638 (12 B) | Symbol: sub_09262c
// EN: AArch64 prologue [mov w0, #0x20; str d8, [sp, #0x10]; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov w0, #0x20; str d8, [sp, #0x10]; b #0x93320]
uint64_t fde_sub_09262c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD000BE8ULL) << 32) | 0x52800400ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09262CULL;
}

// FDE #3739 | PC: 0x092638..0x092640 (8 B) | Symbol: sub_092638
// EN: AArch64 prologue [add x0, sp, #0x80; b #0x7bdb0] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x80; b #0x7bdb0]
uint64_t fde_sub_092638(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFA5DDULL) << 32) | 0x910203E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092638ULL;
}

// FDE #3740 | PC: 0x092640..0x09264c (12 B) | Symbol: sub_092640
// EN: AArch64 prologue [add x0, sp, #0x80; add x1, sp, #0x68; b #0x47fbc] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x80; add x1, sp, #0x68; b #0x47fbc]
uint64_t fde_sub_092640(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9101A3E1ULL) << 32) | 0x910203E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092640ULL;
}

// FDE #3741 | PC: 0x09264c..0x092658 (12 B) | Symbol: sub_09264c
// EN: AArch64 prologue [add x0, sp, #0x80; mov w1, #0xb71; b #0x941a0] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x80; mov w1, #0xb71; b #0x941a0]
uint64_t fde_sub_09264c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52816E21ULL) << 32) | 0x910203E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09264CULL;
}

// FDE #3742 | PC: 0x092658..0x092664 (12 B) | Symbol: sub_092658
// EN: AArch64 prologue [adrp x1, #0x1f000; add x1, x1, #0x4a6; b #0x4696c] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x1f000; add x1, x1, #0x4a6; b #0x4696c]
uint64_t fde_sub_092658(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91129821ULL) << 32) | 0xB0FFFC61ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092658ULL;
}

// FDE #3743 | PC: 0x092664..0x09266c (8 B) | Symbol: sub_092664
// EN: AArch64 prologue [str w1, [x0, #0x88]; ret] | VI: Khởi đầu hàm AArch64 [str w1, [x0, #0x88]; ret]
uint64_t fde_sub_092664(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9008801ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092664ULL;
}

// FDE #3744 | PC: 0x09266c..0x092674 (8 B) | Symbol: sub_09266c
// EN: AArch64 prologue [add x0, sp, #0xe8; b #0x46c54] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0xe8; b #0x46c54]
uint64_t fde_sub_09266c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED179ULL) << 32) | 0x9103A3E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09266CULL;
}

// FDE #3745 | PC: 0x092674..0x092688 (20 B) | Symbol: sub_092674
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x547d0; ldr x8, [x20, #0x10]; ldr x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x547d0; ldr x8, [x20, #0x10]; ldr x30, [sp], #0x10]
uint64_t fde_sub_092674(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x97FF0856ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092674ULL;
}

// FDE #3746 | PC: 0x092688..0x092690 (8 B) | Symbol: sub_092688
// EN: AArch64 prologue [mov x1, x21; b #0x51254] | VI: Khởi đầu hàm AArch64 [mov x1, x21; b #0x51254]
uint64_t fde_sub_092688(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEFAF2ULL) << 32) | 0xAA1503E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092688ULL;
}

// FDE #3747 | PC: 0x092690..0x092698 (8 B) | Symbol: sub_092690
// EN: AArch64 prologue [mov x1, x21; b #0x7c00c] | VI: Khởi đầu hàm AArch64 [mov x1, x21; b #0x7c00c]
uint64_t fde_sub_092690(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFA65EULL) << 32) | 0xAA1503E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092690ULL;
}

// FDE #3748 | PC: 0x092698..0x0926a4 (12 B) | Symbol: sub_092698
// EN: AArch64 prologue [add x0, sp, #0x58; mov w1, #0xc11; b #0x941a0] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x58; mov w1, #0xc11; b #0x941a0]
uint64_t fde_sub_092698(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52818221ULL) << 32) | 0x910163E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092698ULL;
}

// FDE #3749 | PC: 0x0926a4..0x0926b8 (20 B) | Symbol: sub_0926a4
// EN: AArch64 prologue [sub x9, x22, x23; asr x27, x9, #3; add x9, x27, #1; lsr x10, x9, #0x3d] | VI: Khởi đầu hàm AArch64 [sub x9, x22, x23; asr x27, x9, #3; add x9, x27, #1; lsr x10, x9, #0x3d]
uint64_t fde_sub_0926a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9343FD3BULL) << 32) | 0xCB1702C9ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0926A4ULL;
}

// FDE #3750 | PC: 0x0926b8..0x0926c4 (12 B) | Symbol: sub_0926b8
// EN: AArch64 prologue [stp xzr, xzr, [x0]; str xzr, [x0, #0x10]; b #0x47ff4] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x0]; str xzr, [x0, #0x10]; b #0x47ff4]
uint64_t fde_sub_0926b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900081FULL) << 32) | 0xA9007C1FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0926B8ULL;
}

// FDE #3751 | PC: 0x0926c4..0x0926d0 (12 B) | Symbol: sub_0926c4
// EN: AArch64 prologue [ldr x0, [x22, #8]; mov x1, x19; b #0x8c2bc] | VI: Khởi đầu hàm AArch64 [ldr x0, [x22, #8]; mov x1, x19; b #0x8c2bc]
uint64_t fde_sub_0926c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E1ULL) << 32) | 0xF94006C0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0926C4ULL;
}

// FDE #3752 | PC: 0x0926d0..0x0926d8 (8 B) | Symbol: sub_0926d0
// EN: AArch64 prologue [add x0, sp, #0xf8; b #0x46c54] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0xf8; b #0x46c54]
uint64_t fde_sub_0926d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED160ULL) << 32) | 0x9103E3E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0926D0ULL;
}

// FDE #3753 | PC: 0x0926d8..0x0926e0 (8 B) | Symbol: sub_0926d8
// EN: AArch64 prologue [add x1, x19, #0x48; b #0x470b8] | VI: Khởi đầu hàm AArch64 [add x1, x19, #0x48; b #0x470b8]
uint64_t fde_sub_0926d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED277ULL) << 32) | 0x91012261ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0926D8ULL;
}

// FDE #3754 | PC: 0x0926e0..0x0926ec (12 B) | Symbol: sub_0926e0
// EN: AArch64 prologue [add x1, sp, #0x110; str wzr, [sp, #0x110]; b #0x692bc] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0x110; str wzr, [sp, #0x110]; b #0x692bc]
uint64_t fde_sub_0926e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB90113FFULL) << 32) | 0x910443E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0926E0ULL;
}

// FDE #3755 | PC: 0x0926ec..0x0926f4 (8 B) | Symbol: sub_0926ec
// EN: AArch64 prologue [add x20, sp, #8; b #0x49290] | VI: Khởi đầu hàm AArch64 [add x20, sp, #8; b #0x49290]
uint64_t fde_sub_0926ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDAE8ULL) << 32) | 0x910023F4ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0926ECULL;
}

// FDE #3756 | PC: 0x0926f4..0x0926fc (8 B) | Symbol: sub_0926f4
// EN: AArch64 prologue [add x20, sp, #0x110; b #0x49290] | VI: Khởi đầu hàm AArch64 [add x20, sp, #0x110; b #0x49290]
uint64_t fde_sub_0926f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDAE6ULL) << 32) | 0x910443F4ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0926F4ULL;
}

// FDE #3757 | PC: 0x0926fc..0x092704 (8 B) | Symbol: sub_0926fc
// EN: AArch64 prologue [add x0, sp, #0x110; b #0x937a0] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x110; b #0x937a0]
uint64_t fde_sub_0926fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000428ULL) << 32) | 0x910443E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0926FCULL;
}

// FDE #3758 | PC: 0x092704..0x092718 (20 B) | Symbol: sub_092704
// EN: AArch64 prologue [ldr x9, [x27]; str x9, [x8]; ldr x9, [x27, #8]; str x9, [x8, #8]] | VI: Khởi đầu hàm AArch64 [ldr x9, [x27]; str x9, [x8]; ldr x9, [x27, #8]; str x9, [x8, #8]]
uint64_t fde_sub_092704(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000109ULL) << 32) | 0xF9400369ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092704ULL;
}

// FDE #3759 | PC: 0x092718..0x092720 (8 B) | Symbol: sub_092718
// EN: AArch64 prologue [mov w0, #0x90; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov w0, #0x90; b #0x93320]
uint64_t fde_sub_092718(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000301ULL) << 32) | 0x52801200ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092718ULL;
}

// FDE #3760 | PC: 0x092720..0x092728 (8 B) | Symbol: sub_092720
// EN: AArch64 prologue [str x8, [sp, #0x128]; b #0x940b0] | VI: Khởi đầu hàm AArch64 [str x8, [sp, #0x128]; b #0x940b0]
uint64_t fde_sub_092720(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000663ULL) << 32) | 0xF90097E8ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092720ULL;
}

// FDE #3761 | PC: 0x092728..0x09273c (20 B) | Symbol: sub_092728
// EN: AArch64 prologue [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; mov x19, x0; mov x0, x1] | VI: Khởi đầu hàm AArch64 [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; mov x19, x0; mov x0, x1]
uint64_t fde_sub_092728(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016A8ULL) << 32) | 0xD53BD055ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092728ULL;
}

// FDE #3762 | PC: 0x09273c..0x092750 (20 B) | Symbol: sub_09273c
// EN: AArch64 prologue [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; mov w20, w1; add x1, x0, #0x28] | VI: Khởi đầu hàm AArch64 [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; mov w20, w1; add x1, x0, #0x28]
uint64_t fde_sub_09273c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016A8ULL) << 32) | 0xD53BD055ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09273CULL;
}

// FDE #3763 | PC: 0x092750..0x092764 (20 B) | Symbol: sub_092750
// EN: AArch64 prologue [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; adrp x0, #0xa0000; add x0, x0, #0x30] | VI: Khởi đầu hàm AArch64 [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; adrp x0, #0xa0000; add x0, x0, #0x30]
uint64_t fde_sub_092750(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016A8ULL) << 32) | 0xD53BD055ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092750ULL;
}

// FDE #3764 | PC: 0x092764..0x09276c (8 B) | Symbol: sub_092764
// EN: AArch64 prologue [add x22, sp, #8; b #0x46964] | VI: Khởi đầu hàm AArch64 [add x22, sp, #8; b #0x46964]
uint64_t fde_sub_092764(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED07FULL) << 32) | 0x910023F6ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092764ULL;
}

// FDE #3765 | PC: 0x09276c..0x092780 (20 B) | Symbol: sub_09276c
// EN: AArch64 prologue [ldr x19, [x1]; str x19, [sp, #8]; str xzr, [x1]; add x1, sp, #8] | VI: Khởi đầu hàm AArch64 [ldr x19, [x1]; str x19, [sp, #8]; str xzr, [x1]; add x1, sp, #8]
uint64_t fde_sub_09276c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90007F3ULL) << 32) | 0xF9400033ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09276CULL;
}

// FDE #3766 | PC: 0x092780..0x09278c (12 B) | Symbol: sub_092780
// EN: AArch64 prologue [ldr x8, [sp, #0x10]; ldr q0, [sp]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [sp, #0x10]; ldr q0, [sp]; ret]
uint64_t fde_sub_092780(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC003E0ULL) << 32) | 0xF9400BE8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092780ULL;
}

// FDE #3767 | PC: 0x09278c..0x0927a0 (20 B) | Symbol: sub_09278c
// EN: AArch64 prologue [ldr x8, [sp, #0x10]; ldr q0, [sp]; str x8, [x21, #0x10]; str q0, [x21]] | VI: Khởi đầu hàm AArch64 [ldr x8, [sp, #0x10]; ldr q0, [sp]; str x8, [x21, #0x10]; str q0, [x21]]
uint64_t fde_sub_09278c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC003E0ULL) << 32) | 0xF9400BE8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09278CULL;
}

// FDE #3768 | PC: 0x0927a0..0x0927ac (12 B) | Symbol: sub_0927a0
// EN: AArch64 prologue [mov w1, wzr; ldr x0, [x8, #8]; b #0x8be20] | VI: Khởi đầu hàm AArch64 [mov w1, wzr; ldr x0, [x8, #8]; b #0x8be20]
uint64_t fde_sub_0927a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400500ULL) << 32) | 0x2A1F03E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0927A0ULL;
}

// FDE #3769 | PC: 0x0927ac..0x0927b4 (8 B) | Symbol: sub_0927ac
// EN: AArch64 prologue [mov w1, wzr; b #0x93200] | VI: Khởi đầu hàm AArch64 [mov w1, wzr; b #0x93200]
uint64_t fde_sub_0927ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000294ULL) << 32) | 0x2A1F03E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0927ACULL;
}

// FDE #3770 | PC: 0x0927b4..0x0927c0 (12 B) | Symbol: sub_0927b4
// EN: AArch64 prologue [str xzr, [x21]; ldr x8, [x20, #0x20]; ret] | VI: Khởi đầu hàm AArch64 [str xzr, [x21]; ldr x8, [x20, #0x20]; ret]
uint64_t fde_sub_0927b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401288ULL) << 32) | 0xF90002BFULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0927B4ULL;
}

// FDE #3771 | PC: 0x0927c0..0x0927c8 (8 B) | Symbol: sub_0927c0
// EN: AArch64 prologue [ldr x0, [sp, #0x190]; b #0x44830] | VI: Khởi đầu hàm AArch64 [ldr x0, [sp, #0x190]; b #0x44830]
uint64_t fde_sub_0927c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC81BULL) << 32) | 0xF940CBE0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0927C0ULL;
}

// FDE #3772 | PC: 0x0927c8..0x0927dc (20 B) | Symbol: sub_0927c8
// EN: AArch64 prologue [str x25, [sp, #0x30]; ldr x9, [x21, #0x30]; add x8, sp, #8; add x8, x8, #8] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #0x30]; ldr x9, [x21, #0x30]; add x8, sp, #8; add x8, x8, #8]
uint64_t fde_sub_0927c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401AA9ULL) << 32) | 0xF9001BF9ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0927C8ULL;
}

// FDE #3773 | PC: 0x0927dc..0x0927e8 (12 B) | Symbol: sub_0927dc
// EN: AArch64 prologue [add x8, sp, #0x30; mov x0, x21; b #0x93e00] | VI: Khởi đầu hàm AArch64 [add x8, sp, #0x30; mov x0, x21; b #0x93e00]
uint64_t fde_sub_0927dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E0ULL) << 32) | 0x9100C3E8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0927DCULL;
}

// FDE #3774 | PC: 0x0927e8..0x0927f4 (12 B) | Symbol: sub_0927e8
// EN: AArch64 prologue [mov v0.16b, v9.16b; mov v1.16b, v10.16b; ret] | VI: Khởi đầu hàm AArch64 [mov v0.16b, v9.16b; mov v1.16b, v10.16b; ret]
uint64_t fde_sub_0927e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4EAA1D41ULL) << 32) | 0x4EA91D20ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0927E8ULL;
}

// FDE #3775 | PC: 0x0927f4..0x0927fc (8 B) | Symbol: sub_0927f4
// EN: AArch64 prologue [mov v0.16b, v9.16b; b #0x49298] | VI: Khởi đầu hàm AArch64 [mov v0.16b, v9.16b; b #0x49298]
uint64_t fde_sub_0927f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDAA8ULL) << 32) | 0x4EA91D20ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0927F4ULL;
}

// FDE #3776 | PC: 0x0927fc..0x092804 (8 B) | Symbol: sub_0927fc
// EN: AArch64 prologue [ldr x0, [x8, #8]; b #0x5b574] | VI: Khởi đầu hàm AArch64 [ldr x0, [x8, #8]; b #0x5b574]
uint64_t fde_sub_0927fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF235DULL) << 32) | 0xF9400500ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0927FCULL;
}

// FDE #3777 | PC: 0x092804..0x09280c (8 B) | Symbol: sub_092804
// EN: AArch64 prologue [ldr x0, [x8, #8]; b #0x8bd38] | VI: Khởi đầu hàm AArch64 [ldr x0, [x8, #8]; b #0x8bd38]
uint64_t fde_sub_092804(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFE54CULL) << 32) | 0xF9400500ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092804ULL;
}

// FDE #3778 | PC: 0x09280c..0x092814 (8 B) | Symbol: sub_09280c
// EN: AArch64 prologue [add x0, sp, #0x118; b #0x77ba4] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x118; b #0x77ba4]
uint64_t fde_sub_09280c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF94E5ULL) << 32) | 0x910463E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09280CULL;
}

// FDE #3779 | PC: 0x092814..0x092828 (20 B) | Symbol: sub_092814
// EN: AArch64 prologue [ldrb w8, [x0]; mov x20, x2; mov x19, x0; mov x7, x1] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0]; mov x20, x2; mov x19, x0; mov x7, x1]
uint64_t fde_sub_092814(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0203F4ULL) << 32) | 0x39400008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092814ULL;
}

// FDE #3780 | PC: 0x092828..0x092834 (12 B) | Symbol: sub_092828
// EN: AArch64 prologue [mov x1, x3; mov x19, x2; ret] | VI: Khởi đầu hàm AArch64 [mov x1, x3; mov x19, x2; ret]
uint64_t fde_sub_092828(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0203F3ULL) << 32) | 0xAA0303E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092828ULL;
}

// FDE #3781 | PC: 0x092834..0x09283c (8 B) | Symbol: sub_092834
// EN: AArch64 prologue [add x0, sp, #0x30; b #0x756c8] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x30; b #0x756c8]
uint64_t fde_sub_092834(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF8BA4ULL) << 32) | 0x9100C3E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092834ULL;
}

// FDE #3782 | PC: 0x09283c..0x092844 (8 B) | Symbol: sub_09283c
// EN: AArch64 prologue [add x0, sp, #0x30; b #0x941c0] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x30; b #0x941c0]
uint64_t fde_sub_09283c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000660ULL) << 32) | 0x9100C3E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09283CULL;
}

// FDE #3783 | PC: 0x092844..0x092850 (12 B) | Symbol: sub_092844
// EN: AArch64 prologue [add x0, sp, #0x30; mov w1, #0xba2; b #0x941a0] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x30; mov w1, #0xba2; b #0x941a0]
uint64_t fde_sub_092844(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52817441ULL) << 32) | 0x9100C3E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092844ULL;
}

// FDE #3784 | PC: 0x092850..0x092864 (20 B) | Symbol: sub_092850
// EN: AArch64 prologue [mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; add x1, sp, #8; str x8, [sp, #0x48]] | VI: Khởi đầu hàm AArch64 [mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; add x1, sp, #8; str x8, [sp, #0x48]]
uint64_t fde_sub_092850(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401668ULL) << 32) | 0xD53BD053ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092850ULL;
}

// FDE #3785 | PC: 0x092864..0x092878 (20 B) | Symbol: sub_092864
// EN: AArch64 prologue [ldr w8, [x0, #8]; ldrb w9, [x0, #0xc]; fmov d0, xzr; scvtf d1, w8] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #8]; ldrb w9, [x0, #0xc]; fmov d0, xzr; scvtf d1, w8]
uint64_t fde_sub_092864(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39403009ULL) << 32) | 0xB9400808ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092864ULL;
}

// FDE #3786 | PC: 0x092878..0x092884 (12 B) | Symbol: sub_092878
// EN: AArch64 prologue [adrp x0, #0xa0000; add x0, x0, #0x6f8; b #0x93790] | VI: Khởi đầu hàm AArch64 [adrp x0, #0xa0000; add x0, x0, #0x6f8; b #0x93790]
uint64_t fde_sub_092878(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911BE000ULL) << 32) | 0xD0000060ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092878ULL;
}

// FDE #3787 | PC: 0x092884..0x092890 (12 B) | Symbol: sub_092884
// EN: AArch64 prologue [adrp x0, #0xa0000; add x0, x0, #0x6f8; b #0x937b0] | VI: Khởi đầu hàm AArch64 [adrp x0, #0xa0000; add x0, x0, #0x6f8; b #0x937b0]
uint64_t fde_sub_092884(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911BE000ULL) << 32) | 0xD0000060ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092884ULL;
}

// FDE #3788 | PC: 0x092890..0x0928a4 (20 B) | Symbol: sub_092890
// EN: AArch64 prologue [str wzr, [sp, #0x1c]; ldrb w8, [x20, #0xc]; add x9, x20, #8; add x0, sp, #8] | VI: Khởi đầu hàm AArch64 [str wzr, [sp, #0x1c]; ldrb w8, [x20, #0xc]; add x9, x20, #8; add x0, sp, #8]
uint64_t fde_sub_092890(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39403288ULL) << 32) | 0xB9001FFFULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092890ULL;
}

// FDE #3789 | PC: 0x0928a4..0x0928b0 (12 B) | Symbol: sub_0928a4
// EN: AArch64 prologue [ldr w9, [x9]; ldr w8, [x8]; ret] | VI: Khởi đầu hàm AArch64 [ldr w9, [x9]; ldr w8, [x8]; ret]
uint64_t fde_sub_0928a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9400108ULL) << 32) | 0xB9400129ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0928A4ULL;
}

// FDE #3790 | PC: 0x0928b0..0x0928c4 (20 B) | Symbol: sub_0928b0
// EN: AArch64 prologue [ldr x8, [x23]; ldr x9, [x8]; ldr x10, [x8, #0x10]; cmp x9, x10] | VI: Khởi đầu hàm AArch64 [ldr x8, [x23]; ldr x9, [x8]; ldr x10, [x8, #0x10]; cmp x9, x10]
uint64_t fde_sub_0928b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400109ULL) << 32) | 0xF94002E8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0928B0ULL;
}

// FDE #3791 | PC: 0x0928c4..0x0928cc (8 B) | Symbol: sub_0928c4
// EN: AArch64 prologue [add x19, sp, #0x18; b #0x46964] | VI: Khởi đầu hàm AArch64 [add x19, sp, #0x18; b #0x46964]
uint64_t fde_sub_0928c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED027ULL) << 32) | 0x910063F3ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0928C4ULL;
}

// FDE #3792 | PC: 0x0928cc..0x0928d8 (12 B) | Symbol: sub_0928cc
// EN: AArch64 prologue [str w8, [x23, #0x38]; strb w9, [x23, #0x3c]; b #0x4cc14] | VI: Khởi đầu hàm AArch64 [str w8, [x23, #0x38]; strb w9, [x23, #0x3c]; b #0x4cc14]
uint64_t fde_sub_0928cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3900F2E9ULL) << 32) | 0xB9003AE8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0928CCULL;
}

// FDE #3793 | PC: 0x0928d8..0x0928e4 (12 B) | Symbol: sub_0928d8
// EN: AArch64 prologue [ldr x0, [x8]; ldr x20, [sp], #0x20; b #0x8b98c] | VI: Khởi đầu hàm AArch64 [ldr x0, [x8]; ldr x20, [sp], #0x20; b #0x8b98c]
uint64_t fde_sub_0928d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF84207F4ULL) << 32) | 0xF9400100ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0928D8ULL;
}

// FDE #3794 | PC: 0x0928e4..0x0928f0 (12 B) | Symbol: sub_0928e4
// EN: AArch64 prologue [ldr x8, [x9]; str xzr, [x9]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x9]; str xzr, [x9]; ret]
uint64_t fde_sub_0928e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900013FULL) << 32) | 0xF9400128ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0928E4ULL;
}

// FDE #3795 | PC: 0x0928f0..0x0928fc (12 B) | Symbol: sub_0928f0
// EN: AArch64 prologue [mov w2, wzr; mov x20, x0; ret] | VI: Khởi đầu hàm AArch64 [mov w2, wzr; mov x20, x0; ret]
uint64_t fde_sub_0928f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F4ULL) << 32) | 0x2A1F03E2ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0928F0ULL;
}

// FDE #3796 | PC: 0x0928fc..0x092908 (12 B) | Symbol: sub_0928fc
// EN: AArch64 prologue [mov x1, x26; mov x2, x25; b #0x7cc88] | VI: Khởi đầu hàm AArch64 [mov x1, x26; mov x2, x25; b #0x7cc88]
uint64_t fde_sub_0928fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1903E2ULL) << 32) | 0xAA1A03E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0928FCULL;
}

// FDE #3797 | PC: 0x092908..0x092910 (8 B) | Symbol: sub_092908
// EN: AArch64 prologue [mov x0, x20; b #0x6d070] | VI: Khởi đầu hàm AArch64 [mov x0, x20; b #0x6d070]
uint64_t fde_sub_092908(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF69D9ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092908ULL;
}

// FDE #3798 | PC: 0x092910..0x09291c (12 B) | Symbol: sub_092910
// EN: AArch64 prologue [mov x0, x20; mov x3, x24; br x8] | VI: Khởi đầu hàm AArch64 [mov x0, x20; mov x3, x24; br x8]
uint64_t fde_sub_092910(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1803E3ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092910ULL;
}

// FDE #3799 | PC: 0x09291c..0x092928 (12 B) | Symbol: sub_09291c
// EN: AArch64 prologue [mov x0, x20; mov x1, x19; b #0x5b0a0] | VI: Khởi đầu hàm AArch64 [mov x0, x20; mov x1, x19; b #0x5b0a0]
uint64_t fde_sub_09291c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E1ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09291CULL;
}

// FDE #3800 | PC: 0x092928..0x092934 (12 B) | Symbol: sub_092928
// EN: AArch64 prologue [mov x0, x20; mov x1, x19; b #0x62b54] | VI: Khởi đầu hàm AArch64 [mov x0, x20; mov x1, x19; b #0x62b54]
uint64_t fde_sub_092928(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E1ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092928ULL;
}

// FDE #3801 | PC: 0x092934..0x092940 (12 B) | Symbol: sub_092934
// EN: AArch64 prologue [mov x0, x20; mov x1, x19; b #0x83130] | VI: Khởi đầu hàm AArch64 [mov x0, x20; mov x1, x19; b #0x83130]
uint64_t fde_sub_092934(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E1ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092934ULL;
}

// FDE #3802 | PC: 0x092940..0x09294c (12 B) | Symbol: sub_092940
// EN: AArch64 prologue [add x0, sp, #0x18; str xzr, [sp, #8]; b #0x5c5e4] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x18; str xzr, [sp, #8]; b #0x5c5e4]
uint64_t fde_sub_092940(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90007FFULL) << 32) | 0x910063E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092940ULL;
}

// FDE #3803 | PC: 0x09294c..0x092958 (12 B) | Symbol: sub_09294c
// EN: AArch64 prologue [cmp x21, x23; mov x24, x21; ret] | VI: Khởi đầu hàm AArch64 [cmp x21, x23; mov x24, x21; ret]
uint64_t fde_sub_09294c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503F8ULL) << 32) | 0xEB1702BFULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09294CULL;
}

// FDE #3804 | PC: 0x092958..0x092964 (12 B) | Symbol: sub_092958
// EN: AArch64 prologue [mov w22, w3; mov x21, x2; ret] | VI: Khởi đầu hàm AArch64 [mov w22, w3; mov x21, x2; ret]
uint64_t fde_sub_092958(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0203F5ULL) << 32) | 0x2A0303F6ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092958ULL;
}

// FDE #3805 | PC: 0x092964..0x09296c (8 B) | Symbol: sub_092964
// EN: AArch64 prologue [mov w0, #3; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #3; ret]
uint64_t fde_sub_092964(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800060ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092964ULL;
}

// FDE #3806 | PC: 0x09296c..0x092980 (20 B) | Symbol: sub_09296c
// EN: AArch64 prologue [mov x8, #0x6666666666666666; movk x8, #0x6667; movk x8, #0x666, lsl #48; cmp x20, x8] | VI: Khởi đầu hàm AArch64 [mov x8, #0x6666666666666666; movk x8, #0x6667; movk x8, #0x666, lsl #48; cmp x20, x8]
uint64_t fde_sub_09296c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF28CCCE8ULL) << 32) | 0xB203E7E8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09296CULL;
}

// FDE #3807 | PC: 0x092980..0x092988 (8 B) | Symbol: sub_092980
// EN: AArch64 prologue [add x1, x1, #0x9e2; b #0x93910] | VI: Khởi đầu hàm AArch64 [add x1, x1, #0x9e2; b #0x93910]
uint64_t fde_sub_092980(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140003E3ULL) << 32) | 0x91278821ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092980ULL;
}

// FDE #3808 | PC: 0x092988..0x09299c (20 B) | Symbol: sub_092988
// EN: AArch64 prologue [strb w8, [x20, #0x54]; strb w8, [x20, #0x5c]; str s0, [x20, #0x60]; strb w8, [x20, #0x64]] | VI: Khởi đầu hàm AArch64 [strb w8, [x20, #0x54]; strb w8, [x20, #0x5c]; str s0, [x20, #0x60]; strb w8, [x20, #0x64]]
uint64_t fde_sub_092988(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39017288ULL) << 32) | 0x39015288ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092988ULL;
}

// FDE #3809 | PC: 0x09299c..0x0929b0 (20 B) | Symbol: sub_09299c
// EN: AArch64 prologue [ldr w9, [x20]; sub x29, x28, #0x18; madd x8, x9, x27, x8; cmp x29, x8] | VI: Khởi đầu hàm AArch64 [ldr w9, [x20]; sub x29, x28, #0x18; madd x8, x9, x27, x8; cmp x29, x8]
uint64_t fde_sub_09299c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD100639DULL) << 32) | 0xB9400289ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09299CULL;
}

// FDE #3810 | PC: 0x0929b0..0x0929bc (12 B) | Symbol: sub_0929b0
// EN: AArch64 prologue [adrp x8, #0x98000; add x8, x8, #0x250; ret] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x98000; add x8, x8, #0x250; ret]
uint64_t fde_sub_0929b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91094108ULL) << 32) | 0xD0000028ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0929B0ULL;
}

// FDE #3811 | PC: 0x0929bc..0x0929d0 (20 B) | Symbol: sub_0929bc
// EN: AArch64 prologue [sub x8, x8, x10; asr x20, x8, #3; add x8, x20, #1; lsr x11, x8, #0x3d] | VI: Khởi đầu hàm AArch64 [sub x8, x8, x10; asr x20, x8, #3; add x8, x20, #1; lsr x11, x8, #0x3d]
uint64_t fde_sub_0929bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9343FD14ULL) << 32) | 0xCB0A0108ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0929BCULL;
}

// FDE #3812 | PC: 0x0929d0..0x0929dc (12 B) | Symbol: sub_0929d0
// EN: AArch64 prologue [mov x2, x1; ldr w1, [x2], #8; b #0x514b0] | VI: Khởi đầu hàm AArch64 [mov x2, x1; ldr w1, [x2], #8; b #0x514b0]
uint64_t fde_sub_0929d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB8408441ULL) << 32) | 0xAA0103E2ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0929D0ULL;
}

// FDE #3813 | PC: 0x0929dc..0x0929e8 (12 B) | Symbol: sub_0929dc
// EN: AArch64 prologue [fmul s1, s1, s8; fadd s0, s0, s1; ret] | VI: Khởi đầu hàm AArch64 [fmul s1, s1, s8; fadd s0, s0, s1; ret]
uint64_t fde_sub_0929dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E212800ULL) << 32) | 0x1E280821ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0929DCULL;
}

// FDE #3814 | PC: 0x0929e8..0x0929fc (20 B) | Symbol: sub_0929e8
// EN: AArch64 prologue [ldr w9, [x0, #8]; ldr w8, [x1]; mov x19, x0; cmp w9, w8] | VI: Khởi đầu hàm AArch64 [ldr w9, [x0, #8]; ldr w8, [x1]; mov x19, x0; cmp w9, w8]
uint64_t fde_sub_0929e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9400028ULL) << 32) | 0xB9400809ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0929E8ULL;
}

// FDE #3815 | PC: 0x0929fc..0x092a08 (12 B) | Symbol: sub_0929fc
// EN: AArch64 prologue [mov x2, x21; mov w3, wzr; b #0x6b170] | VI: Khởi đầu hàm AArch64 [mov x2, x21; mov w3, wzr; b #0x6b170]
uint64_t fde_sub_0929fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E3ULL) << 32) | 0xAA1503E2ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0929FCULL;
}

// FDE #3816 | PC: 0x092a08..0x092a14 (12 B) | Symbol: sub_092a08
// EN: AArch64 prologue [mov x2, x21; mov v0.16b, v8.16b; ret] | VI: Khởi đầu hàm AArch64 [mov x2, x21; mov v0.16b, v8.16b; ret]
uint64_t fde_sub_092a08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4EA81D00ULL) << 32) | 0xAA1503E2ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092A08ULL;
}

// FDE #3817 | PC: 0x092a14..0x092a1c (8 B) | Symbol: sub_092a14
// EN: AArch64 prologue [mov x1, x19; b #0x93910] | VI: Khởi đầu hàm AArch64 [mov x1, x19; b #0x93910]
uint64_t fde_sub_092a14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140003BEULL) << 32) | 0xAA1303E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092A14ULL;
}

// FDE #3818 | PC: 0x092a1c..0x092a28 (12 B) | Symbol: sub_092a1c
// EN: AArch64 prologue [lsr x11, x8, #1; tst w8, #1; ret] | VI: Khởi đầu hàm AArch64 [lsr x11, x8, #1; tst w8, #1; ret]
uint64_t fde_sub_092a1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7200011FULL) << 32) | 0xD341FD0BULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092A1CULL;
}

// FDE #3819 | PC: 0x092a28..0x092a30 (8 B) | Symbol: sub_092a28
// EN: AArch64 prologue [mov x0, x22; b #0x4de80] | VI: Khởi đầu hàm AArch64 [mov x0, x22; b #0x4de80]
uint64_t fde_sub_092a28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEED15ULL) << 32) | 0xAA1603E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092A28ULL;
}

// FDE #3820 | PC: 0x092a30..0x092a38 (8 B) | Symbol: sub_092a30
// EN: AArch64 prologue [mov x0, x22; b #0x46c54] | VI: Khởi đầu hàm AArch64 [mov x0, x22; b #0x46c54]
uint64_t fde_sub_092a30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED088ULL) << 32) | 0xAA1603E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092A30ULL;
}

// FDE #3821 | PC: 0x092a38..0x092a40 (8 B) | Symbol: sub_092a38
// EN: AArch64 prologue [mov x0, x22; b #0x4702c] | VI: Khởi đầu hàm AArch64 [mov x0, x22; b #0x4702c]
uint64_t fde_sub_092a38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED17CULL) << 32) | 0xAA1603E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092A38ULL;
}

// FDE #3822 | PC: 0x092a40..0x092a48 (8 B) | Symbol: sub_092a40
// EN: AArch64 prologue [mov x0, x22; b #0x4c158] | VI: Khởi đầu hàm AArch64 [mov x0, x22; b #0x4c158]
uint64_t fde_sub_092a40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE5C5ULL) << 32) | 0xAA1603E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092A40ULL;
}

// FDE #3823 | PC: 0x092a48..0x092a5c (20 B) | Symbol: sub_092a48
// EN: AArch64 prologue [mov x0, x22; mov x1, x24; mov x2, x21; mov x3, x23] | VI: Khởi đầu hàm AArch64 [mov x0, x22; mov x1, x24; mov x2, x21; mov x3, x23]
uint64_t fde_sub_092a48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1803E1ULL) << 32) | 0xAA1603E0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092A48ULL;
}

// FDE #3824 | PC: 0x092a5c..0x092a70 (20 B) | Symbol: sub_092a5c
// EN: AArch64 prologue [mrs x23, tpidr_el0; ldr x8, [x23, #0x28]; mov x20, x0; mov w19, w1] | VI: Khởi đầu hàm AArch64 [mrs x23, tpidr_el0; ldr x8, [x23, #0x28]; mov x20, x0; mov w19, w1]
uint64_t fde_sub_092a5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016E8ULL) << 32) | 0xD53BD057ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092A5CULL;
}

// FDE #3825 | PC: 0x092a70..0x092a78 (8 B) | Symbol: sub_092a70
// EN: AArch64 prologue [fcvtzs x0, s0; ret] | VI: Khởi đầu hàm AArch64 [fcvtzs x0, s0; ret]
uint64_t fde_sub_092a70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x9E380000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092A70ULL;
}

// FDE #3826 | PC: 0x092a78..0x092a8c (20 B) | Symbol: sub_092a78
// EN: AArch64 prologue [ldr w9, [x28, #0x18]; sub x27, x26, #0x18; madd x8, x9, x25, x8; cmp x27, x8] | VI: Khởi đầu hàm AArch64 [ldr w9, [x28, #0x18]; sub x27, x26, #0x18; madd x8, x9, x25, x8; cmp x27, x8]
uint64_t fde_sub_092a78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD100635BULL) << 32) | 0xB9401B89ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092A78ULL;
}

// FDE #3827 | PC: 0x092a8c..0x092aa0 (20 B) | Symbol: sub_092a8c
// EN: AArch64 prologue [strb wzr, [x19, #0x50]; str x8, [x19]; str x9, [x19, #0x48]; strb wzr, [x19, #0x54]] | VI: Khởi đầu hàm AArch64 [strb wzr, [x19, #0x50]; str x8, [x19]; str x9, [x19, #0x48]; strb wzr, [x19, #0x54]]
uint64_t fde_sub_092a8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000268ULL) << 32) | 0x3901427FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092A8CULL;
}

// FDE #3828 | PC: 0x092aa0..0x092abc (28 B) | Symbol: sub_092aa0
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x44830; mov x0, xzr; bl #0x48d40] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x44830; mov x0, xzr; bl #0x48d40]
uint64_t fde_sub_092aa0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x97FEC763ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092AA0ULL;
}

// FDE #3829 | PC: 0x092abc..0x092ac4 (8 B) | Symbol: sub_092abc
// EN: AArch64 prologue [stp q1, q0, [sp, #0xb0]; br x8] | VI: Khởi đầu hàm AArch64 [stp q1, q0, [sp, #0xb0]; br x8]
uint64_t fde_sub_092abc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD61F0100ULL) << 32) | 0xAD0583E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092ABCULL;
}

// FDE #3830 | PC: 0x092ac4..0x092ae8 (36 B) | Symbol: sub_092ac4
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; ldr x1, [x19, #0x28]; ldr x0, [x8]; bl #0x8bb68] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; ldr x1, [x19, #0x28]; ldr x0, [x8]; bl #0x8bb68]
uint64_t fde_sub_092ac4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401661ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092AC4ULL;
}

// FDE #3831 | PC: 0x092ae8..0x092af4 (12 B) | Symbol: sub_092ae8
// EN: AArch64 prologue [mov x3, x22; mov x4, x23; b #0x7cc5c] | VI: Khởi đầu hàm AArch64 [mov x3, x22; mov x4, x23; b #0x7cc5c]
uint64_t fde_sub_092ae8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1703E4ULL) << 32) | 0xAA1603E3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092AE8ULL;
}

// FDE #3832 | PC: 0x092af4..0x092b00 (12 B) | Symbol: sub_092af4
// EN: AArch64 prologue [mov x2, x22; mov x4, x20; br x8] | VI: Khởi đầu hàm AArch64 [mov x2, x22; mov x4, x20; br x8]
uint64_t fde_sub_092af4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E4ULL) << 32) | 0xAA1603E2ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092AF4ULL;
}

// FDE #3833 | PC: 0x092b00..0x092b08 (8 B) | Symbol: sub_092b00
// EN: AArch64 prologue [mov x2, x22; b #0x931f0] | VI: Khởi đầu hàm AArch64 [mov x2, x22; b #0x931f0]
uint64_t fde_sub_092b00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140001BBULL) << 32) | 0xAA1603E2ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092B00ULL;
}

// FDE #3834 | PC: 0x092b08..0x092b1c (20 B) | Symbol: sub_092b08
// EN: AArch64 prologue [ldr x8, [x19, #0x28]; str s9, [x8, #0x10]; ldr x8, [x19, #0x28]; str w20, [x8, #0x20]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x19, #0x28]; str s9, [x8, #0x10]; ldr x8, [x19, #0x28]; str w20, [x8, #0x20]]
uint64_t fde_sub_092b08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xBD001109ULL) << 32) | 0xF9401668ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092B08ULL;
}

// FDE #3835 | PC: 0x092b1c..0x092b28 (12 B) | Symbol: sub_092b1c
// EN: AArch64 prologue [mov x2, sp; mov x0, x19; ret] | VI: Khởi đầu hàm AArch64 [mov x2, sp; mov x0, x19; ret]
uint64_t fde_sub_092b1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x910003E2ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092B1CULL;
}

// FDE #3836 | PC: 0x092b28..0x092b3c (20 B) | Symbol: sub_092b28
// EN: AArch64 prologue [ldrb w8, [x20, #0x14]; add x9, x20, #0x10; cmp w8, #0; csel x8, x11, x9, eq] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x20, #0x14]; add x9, x20, #0x10; cmp w8, #0; csel x8, x11, x9, eq]
uint64_t fde_sub_092b28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91004289ULL) << 32) | 0x39405288ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092B28ULL;
}

// FDE #3837 | PC: 0x092b3c..0x092b50 (20 B) | Symbol: sub_092b3c
// EN: AArch64 prologue [adrp x5, #0xa0000; add x5, x5, #0x1a0; ldr x20, [x20, #8]; ldr x21, [sp, #8]] | VI: Khởi đầu hàm AArch64 [adrp x5, #0xa0000; add x5, x5, #0x1a0; ldr x20, [x20, #8]; ldr x21, [sp, #8]]
uint64_t fde_sub_092b3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910680A5ULL) << 32) | 0xD0000065ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092B3CULL;
}

// FDE #3838 | PC: 0x092b50..0x092b64 (20 B) | Symbol: sub_092b50
// EN: AArch64 prologue [cmp w9, #0; csel x9, x10, x11, eq; ldr w9, [x9]; add x11, x8, #0x10] | VI: Khởi đầu hàm AArch64 [cmp w9, #0; csel x9, x10, x11, eq; ldr w9, [x9]; add x11, x8, #0x10]
uint64_t fde_sub_092b50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9A8B0149ULL) << 32) | 0x7100013FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092B50ULL;
}

// FDE #3839 | PC: 0x092b64..0x092b70 (12 B) | Symbol: sub_092b64
// EN: AArch64 prologue [adrp x0, #0xa0000; add x0, x0, #0x7d0; b #0x93790] | VI: Khởi đầu hàm AArch64 [adrp x0, #0xa0000; add x0, x0, #0x7d0; b #0x93790]
uint64_t fde_sub_092b64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911F4000ULL) << 32) | 0xD0000060ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092B64ULL;
}

// FDE #3840 | PC: 0x092b70..0x092b7c (12 B) | Symbol: sub_092b70
// EN: AArch64 prologue [adrp x0, #0xa0000; add x0, x0, #0x7d0; b #0x937b0] | VI: Khởi đầu hàm AArch64 [adrp x0, #0xa0000; add x0, x0, #0x7d0; b #0x937b0]
uint64_t fde_sub_092b70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911F4000ULL) << 32) | 0xD0000060ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092B70ULL;
}

// FDE #3841 | PC: 0x092b7c..0x092b88 (12 B) | Symbol: sub_092b7c
// EN: AArch64 prologue [ldrb w1, [x19, #0x3b]; mov x0, sp; b #0x4e684] | VI: Khởi đầu hàm AArch64 [ldrb w1, [x19, #0x3b]; mov x0, sp; b #0x4e684]
uint64_t fde_sub_092b7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003E0ULL) << 32) | 0x3940EE61ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092B7CULL;
}

// FDE #3842 | PC: 0x092b88..0x092b94 (12 B) | Symbol: sub_092b88
// EN: AArch64 prologue [cmp w8, #0; csel x8, x22, x9, eq; ret] | VI: Khởi đầu hàm AArch64 [cmp w8, #0; csel x8, x22, x9, eq; ret]
uint64_t fde_sub_092b88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9A8902C8ULL) << 32) | 0x7100011FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092B88ULL;
}

// FDE #3843 | PC: 0x092b94..0x092ba0 (12 B) | Symbol: sub_092b94
// EN: AArch64 prologue [cmp w8, #0; cset w0, ne; ret] | VI: Khởi đầu hàm AArch64 [cmp w8, #0; cset w0, ne; ret]
uint64_t fde_sub_092b94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1A9F07E0ULL) << 32) | 0x7100011FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092B94ULL;
}

// FDE #3844 | PC: 0x092ba0..0x092bac (12 B) | Symbol: sub_092ba0
// EN: AArch64 prologue [sub x21, x21, #8; mov x0, x21; b #0x5c5dc] | VI: Khởi đầu hàm AArch64 [sub x21, x21, #8; mov x0, x21; b #0x5c5dc]
uint64_t fde_sub_092ba0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E0ULL) << 32) | 0xD10022B5ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092BA0ULL;
}

// FDE #3845 | PC: 0x092bac..0x092bb8 (12 B) | Symbol: sub_092bac
// EN: AArch64 prologue [sub x21, x21, #8; mov x0, x21; b #0x44b18] | VI: Khởi đầu hàm AArch64 [sub x21, x21, #8; mov x0, x21; b #0x44b18]
uint64_t fde_sub_092bac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E0ULL) << 32) | 0xD10022B5ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092BACULL;
}

// FDE #3846 | PC: 0x092bb8..0x092bc4 (12 B) | Symbol: sub_092bb8
// EN: AArch64 prologue [ldr x1, [x0]; mov x0, x22; b #0x8c2dc] | VI: Khởi đầu hàm AArch64 [ldr x1, [x0]; mov x0, x22; b #0x8c2dc]
uint64_t fde_sub_092bb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E0ULL) << 32) | 0xF9400001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092BB8ULL;
}

// FDE #3847 | PC: 0x092bc4..0x092bcc (8 B) | Symbol: sub_092bc4
// EN: AArch64 prologue [mov v0.16b, v10.16b; b #0x93890] | VI: Khởi đầu hàm AArch64 [mov v0.16b, v10.16b; b #0x93890]
uint64_t fde_sub_092bc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000332ULL) << 32) | 0x4EAA1D40ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092BC4ULL;
}

// FDE #3848 | PC: 0x092bcc..0x092bd8 (12 B) | Symbol: sub_092bcc
// EN: AArch64 prologue [mov v0.16b, v10.16b; mov v1.16b, v9.16b; ret] | VI: Khởi đầu hàm AArch64 [mov v0.16b, v10.16b; mov v1.16b, v9.16b; ret]
uint64_t fde_sub_092bcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4EA91D21ULL) << 32) | 0x4EAA1D40ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092BCCULL;
}

// FDE #3849 | PC: 0x092bd8..0x092be0 (8 B) | Symbol: sub_092bd8
// EN: AArch64 prologue [fmov d0, xzr; ret] | VI: Khởi đầu hàm AArch64 [fmov d0, xzr; ret]
uint64_t fde_sub_092bd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x9E6703E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092BD8ULL;
}

// FDE #3850 | PC: 0x092be0..0x092be8 (8 B) | Symbol: sub_092be0
// EN: AArch64 prologue [ldr x20, [sp], #0x20; b #0x44a14] | VI: Khởi đầu hàm AArch64 [ldr x20, [sp], #0x20; b #0x44a14]
uint64_t fde_sub_092be0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC78CULL) << 32) | 0xF84207F4ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092BE0ULL;
}

// FDE #3851 | PC: 0x092be8..0x092bf4 (12 B) | Symbol: sub_092be8
// EN: AArch64 prologue [ldr x0, [x19]; str x21, [x19, #8]; b #0x932e0] | VI: Khởi đầu hàm AArch64 [ldr x0, [x19]; str x21, [x19, #8]; b #0x932e0]
uint64_t fde_sub_092be8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000675ULL) << 32) | 0xF9400260ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092BE8ULL;
}

// FDE #3852 | PC: 0x092bf4..0x092c00 (12 B) | Symbol: sub_092bf4
// EN: AArch64 prologue [mov w2, #1; mov x0, x22; b #0x93c30] | VI: Khởi đầu hàm AArch64 [mov w2, #1; mov x0, x22; b #0x93c30]
uint64_t fde_sub_092bf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E0ULL) << 32) | 0x52800022ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092BF4ULL;
}

// FDE #3853 | PC: 0x092c00..0x092c08 (8 B) | Symbol: sub_092c00
// EN: AArch64 prologue [add x1, sp, #0xc0; b #0x47f90] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0xc0; b #0x47f90]
uint64_t fde_sub_092c00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED4E3ULL) << 32) | 0x910303E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092C00ULL;
}

// FDE #3854 | PC: 0x092c08..0x092c14 (12 B) | Symbol: sub_092c08
// EN: AArch64 prologue [mov w0, w23; mov w1, w21; b #0x4db54] | VI: Khởi đầu hàm AArch64 [mov w0, w23; mov w1, w21; b #0x4db54]
uint64_t fde_sub_092c08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1503E1ULL) << 32) | 0x2A1703E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092C08ULL;
}

// FDE #3855 | PC: 0x092c14..0x092c28 (20 B) | Symbol: sub_092c14
// EN: AArch64 prologue [str x8, [x0]; add x8, x8, #0xa0; mov x19, x0; str x8, [x0, #0x28]] | VI: Khởi đầu hàm AArch64 [str x8, [x0]; add x8, x8, #0xa0; mov x19, x0; str x8, [x0, #0x28]]
uint64_t fde_sub_092c14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91028108ULL) << 32) | 0xF9000008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092C14ULL;
}

// FDE #3856 | PC: 0x092c28..0x092c3c (20 B) | Symbol: sub_092c28
// EN: AArch64 prologue [str x8, [x0]; stur q0, [x0, #8]; add x0, x0, #0x18; mov x1, x20] | VI: Khởi đầu hàm AArch64 [str x8, [x0]; stur q0, [x0, #8]; add x0, x0, #0x18; mov x1, x20]
uint64_t fde_sub_092c28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3C808000ULL) << 32) | 0xF9000008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092C28ULL;
}

// FDE #3857 | PC: 0x092c3c..0x092c48 (12 B) | Symbol: sub_092c3c
// EN: AArch64 prologue [mov w19, w1; mov x20, x0; b #0x4c9e4] | VI: Khởi đầu hàm AArch64 [mov w19, w1; mov x20, x0; b #0x4c9e4]
uint64_t fde_sub_092c3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F4ULL) << 32) | 0x2A0103F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092C3CULL;
}

// FDE #3858 | PC: 0x092c48..0x092c50 (8 B) | Symbol: sub_092c48
// EN: AArch64 prologue [mov w0, #1; b #0x94ab0] | VI: Khởi đầu hàm AArch64 [mov w0, #1; b #0x94ab0]
uint64_t fde_sub_092c48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000799ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092C48ULL;
}

// FDE #3859 | PC: 0x092c50..0x092c5c (12 B) | Symbol: sub_092c50
// EN: AArch64 prologue [mov w0, wzr; mov w1, wzr; b #0x93550] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; mov w1, wzr; b #0x93550]
uint64_t fde_sub_092c50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E1ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092C50ULL;
}

// FDE #3860 | PC: 0x092c5c..0x092c64 (8 B) | Symbol: sub_092c5c
// EN: AArch64 prologue [add x0, x28, #0x18; b #0x6d070] | VI: Khởi đầu hàm AArch64 [add x0, x28, #0x18; b #0x6d070]
uint64_t fde_sub_092c5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF6904ULL) << 32) | 0x91006380ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092C5CULL;
}

// FDE #3861 | PC: 0x092c64..0x092c70 (12 B) | Symbol: sub_092c64
// EN: AArch64 prologue [str q0, [sp, #0x10]; str x8, [sp, #0x20]; b #0x47ff4] | VI: Khởi đầu hàm AArch64 [str q0, [sp, #0x10]; str x8, [sp, #0x20]; b #0x47ff4]
uint64_t fde_sub_092c64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013E8ULL) << 32) | 0x3D8007E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092C64ULL;
}

// FDE #3862 | PC: 0x092c70..0x092c78 (8 B) | Symbol: sub_092c70
// EN: AArch64 prologue [mov x2, x19; b #0x7cc88] | VI: Khởi đầu hàm AArch64 [mov x2, x19; b #0x7cc88]
uint64_t fde_sub_092c70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFA805ULL) << 32) | 0xAA1303E2ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092C70ULL;
}

// FDE #3863 | PC: 0x092c78..0x092c8c (20 B) | Symbol: sub_092c78
// EN: AArch64 prologue [ldr q0, [sp]; add x1, sp, #0x10; mov x22, x0; str q0, [sp, #0x10]] | VI: Khởi đầu hàm AArch64 [ldr q0, [sp]; add x1, sp, #0x10; mov x22, x0; str q0, [sp, #0x10]]
uint64_t fde_sub_092c78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910043E1ULL) << 32) | 0x3DC003E0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092C78ULL;
}

// FDE #3864 | PC: 0x092c8c..0x092c98 (12 B) | Symbol: sub_092c8c
// EN: AArch64 prologue [mov x1, x22; mov x2, x23; ret] | VI: Khởi đầu hàm AArch64 [mov x1, x22; mov x2, x23; ret]
uint64_t fde_sub_092c8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1703E2ULL) << 32) | 0xAA1603E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092C8CULL;
}

// FDE #3865 | PC: 0x092c98..0x092ca4 (12 B) | Symbol: sub_092c98
// EN: AArch64 prologue [mov x0, x23; mov x1, x24; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x23; mov x1, x24; ret]
uint64_t fde_sub_092c98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1803E1ULL) << 32) | 0xAA1703E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092C98ULL;
}

// FDE #3866 | PC: 0x092ca4..0x092cb0 (12 B) | Symbol: sub_092ca4
// EN: AArch64 prologue [mov x0, x23; mov x1, x25; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x23; mov x1, x25; ret]
uint64_t fde_sub_092ca4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1903E1ULL) << 32) | 0xAA1703E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092CA4ULL;
}

// FDE #3867 | PC: 0x092cb0..0x092cbc (12 B) | Symbol: sub_092cb0
// EN: AArch64 prologue [add x1, sp, #0x28; mov x0, x22; ret] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0x28; mov x0, x22; ret]
uint64_t fde_sub_092cb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E0ULL) << 32) | 0x9100A3E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092CB0ULL;
}

// FDE #3868 | PC: 0x092cbc..0x092cd0 (20 B) | Symbol: sub_092cbc
// EN: AArch64 prologue [ldr x8, [x8, #8]; cmp w9, #0; cset w9, ne; str w9, [x8, #0x6c]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x8, #8]; cmp w9, #0; cset w9, ne; str w9, [x8, #0x6c]]
uint64_t fde_sub_092cbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100013FULL) << 32) | 0xF9400508ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092CBCULL;
}

// FDE #3869 | PC: 0x092cd0..0x092cd8 (8 B) | Symbol: sub_092cd0
// EN: AArch64 prologue [ldr x0, [sp, #0x10]; b #0x44830] | VI: Khởi đầu hàm AArch64 [ldr x0, [sp, #0x10]; b #0x44830]
uint64_t fde_sub_092cd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC6D7ULL) << 32) | 0xF9400BE0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092CD0ULL;
}

// FDE #3870 | PC: 0x092cd8..0x092ce4 (12 B) | Symbol: sub_092cd8
// EN: AArch64 prologue [ldr x8, [x0]; ldr x8, [x8, #0xb0]; br x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x8, [x8, #0xb0]; br x8]
uint64_t fde_sub_092cd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9405908ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092CD8ULL;
}

// FDE #3871 | PC: 0x092ce4..0x092cf0 (12 B) | Symbol: sub_092ce4
// EN: AArch64 prologue [ldr x8, [x0]; ldr x8, [x8, #0x18]; br x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x8, [x8, #0x18]; br x8]
uint64_t fde_sub_092ce4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400D08ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092CE4ULL;
}

// FDE #3872 | PC: 0x092cf0..0x092cfc (12 B) | Symbol: sub_092cf0
// EN: AArch64 prologue [ldr x8, [x0]; ldr x2, [x8, #0x20]; br x2] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x2, [x8, #0x20]; br x2]
uint64_t fde_sub_092cf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401102ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092CF0ULL;
}

// FDE #3873 | PC: 0x092cfc..0x092d08 (12 B) | Symbol: sub_092cfc
// EN: AArch64 prologue [ldr x8, [x0]; ldr x1, [x8, #0x30]; br x1] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x1, [x8, #0x30]; br x1]
uint64_t fde_sub_092cfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401901ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092CFCULL;
}

// FDE #3874 | PC: 0x092d08..0x092d10 (8 B) | Symbol: sub_092d08
// EN: AArch64 prologue [str xzr, [sp]; b #0x48190] | VI: Khởi đầu hàm AArch64 [str xzr, [sp]; b #0x48190]
uint64_t fde_sub_092d08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED521ULL) << 32) | 0xF90003FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092D08ULL;
}

// FDE #3875 | PC: 0x092d10..0x092d1c (12 B) | Symbol: sub_092d10
// EN: AArch64 prologue [add x1, sp, #0x10; mov x0, x20; ret] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0x10; mov x0, x20; ret]
uint64_t fde_sub_092d10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0x910043E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092D10ULL;
}

// FDE #3876 | PC: 0x092d1c..0x092d28 (12 B) | Symbol: sub_092d1c
// EN: AArch64 prologue [add x1, sp, #0x10; stp x23, x8, [sp, #0x10]; b #0x8bd40] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0x10; stp x23, x8, [sp, #0x10]; b #0x8bd40]
uint64_t fde_sub_092d1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90123F7ULL) << 32) | 0x910043E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092D1CULL;
}

// FDE #3877 | PC: 0x092d28..0x092d34 (12 B) | Symbol: sub_092d28
// EN: AArch64 prologue [add x1, sp, #0x10; mov x0, x19; b #0x447c0] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0x10; mov x0, x19; b #0x447c0]
uint64_t fde_sub_092d28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x910043E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092D28ULL;
}

// FDE #3878 | PC: 0x092d34..0x092d40 (12 B) | Symbol: sub_092d34
// EN: AArch64 prologue [add x1, x20, #8; add x0, sp, #0x48; b #0x49124] | VI: Khởi đầu hàm AArch64 [add x1, x20, #8; add x0, sp, #0x48; b #0x49124]
uint64_t fde_sub_092d34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910123E0ULL) << 32) | 0x91002281ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092D34ULL;
}

// FDE #3879 | PC: 0x092d40..0x092d48 (8 B) | Symbol: sub_092d40
// EN: AArch64 prologue [mov x2, x23; b #0x4808c] | VI: Khởi đầu hàm AArch64 [mov x2, x23; b #0x4808c]
uint64_t fde_sub_092d40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED4D2ULL) << 32) | 0xAA1703E2ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092D40ULL;
}

// FDE #3880 | PC: 0x092d48..0x092d54 (12 B) | Symbol: sub_092d48
// EN: AArch64 prologue [mov x1, x20; mov x21, x0; b #0x5b3fc] | VI: Khởi đầu hàm AArch64 [mov x1, x20; mov x21, x0; b #0x5b3fc]
uint64_t fde_sub_092d48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F5ULL) << 32) | 0xAA1403E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092D48ULL;
}

// FDE #3881 | PC: 0x092d54..0x092d60 (12 B) | Symbol: sub_092d54
// EN: AArch64 prologue [mov x1, x20; mov x21, x0; b #0x5b1f4] | VI: Khởi đầu hàm AArch64 [mov x1, x20; mov x21, x0; b #0x5b1f4]
uint64_t fde_sub_092d54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F5ULL) << 32) | 0xAA1403E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092D54ULL;
}

// FDE #3882 | PC: 0x092d60..0x092d68 (8 B) | Symbol: sub_092d60
// EN: AArch64 prologue [mov x1, x20; b #0x51254] | VI: Khởi đầu hàm AArch64 [mov x1, x20; b #0x51254]
uint64_t fde_sub_092d60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEF93CULL) << 32) | 0xAA1403E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092D60ULL;
}

// FDE #3883 | PC: 0x092d68..0x092d74 (12 B) | Symbol: sub_092d68
// EN: AArch64 prologue [mov x1, x20; mov x2, x28; b #0x6d130] | VI: Khởi đầu hàm AArch64 [mov x1, x20; mov x2, x28; b #0x6d130]
uint64_t fde_sub_092d68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1C03E2ULL) << 32) | 0xAA1403E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092D68ULL;
}

// FDE #3884 | PC: 0x092d74..0x092d88 (20 B) | Symbol: sub_092d74
// EN: AArch64 prologue [mov x1, x20; mov w2, w19; ldr x8, [x0]; ldr x8, [x8, #0x10]] | VI: Khởi đầu hàm AArch64 [mov x1, x20; mov w2, w19; ldr x8, [x0]; ldr x8, [x8, #0x10]]
uint64_t fde_sub_092d74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1303E2ULL) << 32) | 0xAA1403E1ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092D74ULL;
}

// FDE #3885 | PC: 0x092d88..0x092d90 (8 B) | Symbol: sub_092d88
// EN: AArch64 prologue [str x8, [sp, #8]; b #0x5afdc] | VI: Khởi đầu hàm AArch64 [str x8, [sp, #8]; b #0x5afdc]
uint64_t fde_sub_092d88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF2094ULL) << 32) | 0xF90007E8ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092D88ULL;
}

// FDE #3886 | PC: 0x092d90..0x092d98 (8 B) | Symbol: sub_092d90
// EN: AArch64 prologue [lsl x0, x28, #3; b #0x93320] | VI: Khởi đầu hàm AArch64 [lsl x0, x28, #3; b #0x93320]
uint64_t fde_sub_092d90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000163ULL) << 32) | 0xD37DF380ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092D90ULL;
}

// FDE #3887 | PC: 0x092d98..0x092da4 (12 B) | Symbol: sub_092d98
// EN: AArch64 prologue [str x10, [x0]; str xzr, [x21, #0x18]!; b #0x4cd64] | VI: Khởi đầu hàm AArch64 [str x10, [x0]; str xzr, [x21, #0x18]!; b #0x4cd64]
uint64_t fde_sub_092d98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF8018EBFULL) << 32) | 0xF900000AULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092D98ULL;
}

// FDE #3888 | PC: 0x092da4..0x092db8 (20 B) | Symbol: sub_092da4
// EN: AArch64 prologue [mov x2, xzr; mov x8, xzr; stp xzr, xzr, [x22]; str xzr, [x22, #0x10]] | VI: Khởi đầu hàm AArch64 [mov x2, xzr; mov x8, xzr; stp xzr, xzr, [x22]; str xzr, [x22, #0x10]]
uint64_t fde_sub_092da4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E8ULL) << 32) | 0xAA1F03E2ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092DA4ULL;
}

// FDE #3889 | PC: 0x092db8..0x092dc0 (8 B) | Symbol: sub_092db8
// EN: AArch64 prologue [str x8, [x19]; b #0x48d40] | VI: Khởi đầu hàm AArch64 [str x8, [x19]; b #0x48d40]
uint64_t fde_sub_092db8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED7E1ULL) << 32) | 0xF9000268ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092DB8ULL;
}

// FDE #3890 | PC: 0x092dc0..0x092dc8 (8 B) | Symbol: sub_092dc0
// EN: AArch64 prologue [add x0, x19, #0x38; b #0x44b18] | VI: Khởi đầu hàm AArch64 [add x0, x19, #0x38; b #0x44b18]
uint64_t fde_sub_092dc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC755ULL) << 32) | 0x9100E260ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092DC0ULL;
}

// FDE #3891 | PC: 0x092dc8..0x092dd4 (12 B) | Symbol: sub_092dc8
// EN: AArch64 prologue [mov x1, sp; mov x0, x21; b #0x94420] | VI: Khởi đầu hàm AArch64 [mov x1, sp; mov x0, x21; b #0x94420]
uint64_t fde_sub_092dc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E0ULL) << 32) | 0x910003E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092DC8ULL;
}

// FDE #3892 | PC: 0x092dd4..0x092de0 (12 B) | Symbol: sub_092dd4
// EN: AArch64 prologue [mov x1, sp; mov x0, x20; b #0x8cbcc] | VI: Khởi đầu hàm AArch64 [mov x1, sp; mov x0, x20; b #0x8cbcc]
uint64_t fde_sub_092dd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0x910003E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092DD4ULL;
}

// FDE #3893 | PC: 0x092de0..0x092dec (12 B) | Symbol: sub_092de0
// EN: AArch64 prologue [mov x1, sp; mov x0, x20; b #0x44de0] | VI: Khởi đầu hàm AArch64 [mov x1, sp; mov x0, x20; b #0x44de0]
uint64_t fde_sub_092de0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0x910003E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092DE0ULL;
}

// FDE #3894 | PC: 0x092dec..0x092df8 (12 B) | Symbol: sub_092dec
// EN: AArch64 prologue [mov x1, sp; mov x0, x19; b #0x51b80] | VI: Khởi đầu hàm AArch64 [mov x1, sp; mov x0, x19; b #0x51b80]
uint64_t fde_sub_092dec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x910003E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092DECULL;
}

// FDE #3895 | PC: 0x092df8..0x092e04 (12 B) | Symbol: sub_092df8
// EN: AArch64 prologue [ldr x8, [x8, #0x10]; mov x0, x20; br x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x8, #0x10]; mov x0, x20; br x8]
uint64_t fde_sub_092df8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0xF9400908ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092DF8ULL;
}

// FDE #3896 | PC: 0x092e04..0x092e10 (12 B) | Symbol: sub_092e04
// EN: AArch64 prologue [add x0, sp, #8; mov w1, #0xc22; b #0x941a0] | VI: Khởi đầu hàm AArch64 [add x0, sp, #8; mov w1, #0xc22; b #0x941a0]
uint64_t fde_sub_092e04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52818441ULL) << 32) | 0x910023E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092E04ULL;
}

// FDE #3897 | PC: 0x092e10..0x092e18 (8 B) | Symbol: sub_092e10
// EN: AArch64 prologue [add x0, sp, #8; b #0x4a234] | VI: Khởi đầu hàm AArch64 [add x0, sp, #8; b #0x4a234]
uint64_t fde_sub_092e10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDD08ULL) << 32) | 0x910023E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092E10ULL;
}

// FDE #3898 | PC: 0x092e18..0x092e20 (8 B) | Symbol: sub_092e18
// EN: AArch64 prologue [add x0, sp, #8; b #0x44adc] | VI: Khởi đầu hàm AArch64 [add x0, sp, #8; b #0x44adc]
uint64_t fde_sub_092e18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC730ULL) << 32) | 0x910023E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092E18ULL;
}

// FDE #3899 | PC: 0x092e20..0x092e28 (8 B) | Symbol: sub_092e20
// EN: AArch64 prologue [add x0, sp, #8; b #0x77958] | VI: Khởi đầu hàm AArch64 [add x0, sp, #8; b #0x77958]
uint64_t fde_sub_092e20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF92CDULL) << 32) | 0x910023E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092E20ULL;
}

// FDE #3900 | PC: 0x092e28..0x092e30 (8 B) | Symbol: sub_092e28
// EN: AArch64 prologue [add x0, sp, #8; b #0x75540] | VI: Khởi đầu hàm AArch64 [add x0, sp, #8; b #0x75540]
uint64_t fde_sub_092e28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF89C5ULL) << 32) | 0x910023E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092E28ULL;
}

// FDE #3901 | PC: 0x092e30..0x092e38 (8 B) | Symbol: sub_092e30
// EN: AArch64 prologue [add x0, sp, #8; b #0x4c158] | VI: Khởi đầu hàm AArch64 [add x0, sp, #8; b #0x4c158]
uint64_t fde_sub_092e30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE4C9ULL) << 32) | 0x910023E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092E30ULL;
}

// FDE #3902 | PC: 0x092e38..0x092e40 (8 B) | Symbol: sub_092e38
// EN: AArch64 prologue [add x0, sp, #8; b #0x54c8c] | VI: Khởi đầu hàm AArch64 [add x0, sp, #8; b #0x54c8c]
uint64_t fde_sub_092e38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF0794ULL) << 32) | 0x910023E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092E38ULL;
}

// FDE #3903 | PC: 0x092e40..0x092e4c (12 B) | Symbol: sub_092e40
// EN: AArch64 prologue [add x0, sp, #8; add x19, sp, #8; b #0x497b4] | VI: Khởi đầu hàm AArch64 [add x0, sp, #8; add x19, sp, #8; b #0x497b4]
uint64_t fde_sub_092e40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910023F3ULL) << 32) | 0x910023E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092E40ULL;
}

// FDE #3904 | PC: 0x092e4c..0x092e54 (8 B) | Symbol: sub_092e4c
// EN: AArch64 prologue [add x0, sp, #8; b #0x481b8] | VI: Khởi đầu hàm AArch64 [add x0, sp, #8; b #0x481b8]
uint64_t fde_sub_092e4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED4DAULL) << 32) | 0x910023E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092E4CULL;
}

// FDE #3905 | PC: 0x092e54..0x092e5c (8 B) | Symbol: sub_092e54
// EN: AArch64 prologue [add x0, sp, #8; b #0x497b4] | VI: Khởi đầu hàm AArch64 [add x0, sp, #8; b #0x497b4]
uint64_t fde_sub_092e54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEDA57ULL) << 32) | 0x910023E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092E54ULL;
}

// FDE #3906 | PC: 0x092e5c..0x092e68 (12 B) | Symbol: sub_092e5c
// EN: AArch64 prologue [add x1, sp, #8; mov x0, x19; b #0x63d7c] | VI: Khởi đầu hàm AArch64 [add x1, sp, #8; mov x0, x19; b #0x63d7c]
uint64_t fde_sub_092e5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x910023E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092E5CULL;
}

// FDE #3907 | PC: 0x092e68..0x092e74 (12 B) | Symbol: sub_092e68
// EN: AArch64 prologue [mov x0, x21; mov w1, w20; b #0x94ac0] | VI: Khởi đầu hàm AArch64 [mov x0, x21; mov w1, w20; b #0x94ac0]
uint64_t fde_sub_092e68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1403E1ULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092E68ULL;
}

// FDE #3908 | PC: 0x092e74..0x092e7c (8 B) | Symbol: sub_092e74
// EN: AArch64 prologue [mov x0, x21; b #0x80a30] | VI: Khởi đầu hàm AArch64 [mov x0, x21; b #0x80a30]
uint64_t fde_sub_092e74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFB6EEULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092E74ULL;
}

// FDE #3909 | PC: 0x092e7c..0x092e88 (12 B) | Symbol: sub_092e7c
// EN: AArch64 prologue [mov x0, x21; mov x1, x20; b #0x47f90] | VI: Khởi đầu hàm AArch64 [mov x0, x21; mov x1, x20; b #0x47f90]
uint64_t fde_sub_092e7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E1ULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092E7CULL;
}

// FDE #3910 | PC: 0x092e88..0x092e90 (8 B) | Symbol: sub_092e88
// EN: AArch64 prologue [mov x0, x21; b #0x44a98] | VI: Khởi đầu hàm AArch64 [mov x0, x21; b #0x44a98]
uint64_t fde_sub_092e88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC703ULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092E88ULL;
}

// FDE #3911 | PC: 0x092e90..0x092eb4 (36 B) | Symbol: sub_092e90
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; mov x0, x21; str x9, [x19, #0x40]; stp xzr, xzr, [x8]] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; mov x0, x21; str x9, [x19, #0x40]; stp xzr, xzr, [x8]]
uint64_t fde_sub_092e90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E0ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092E90ULL;
}

// FDE #3912 | PC: 0x092eb4..0x092ebc (8 B) | Symbol: sub_092eb4
// EN: AArch64 prologue [ldr x22, [sp], #0x30; b #0x6b984] | VI: Khởi đầu hàm AArch64 [ldr x22, [sp], #0x30; b #0x6b984]
uint64_t fde_sub_092eb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF62B3ULL) << 32) | 0xF84307F6ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092EB4ULL;
}

// FDE #3913 | PC: 0x092ebc..0x092ec8 (12 B) | Symbol: sub_092ebc
// EN: AArch64 prologue [add x1, x19, #0x58; add x0, sp, #8; b #0x49124] | VI: Khởi đầu hàm AArch64 [add x1, x19, #0x58; add x0, sp, #8; b #0x49124]
uint64_t fde_sub_092ebc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910023E0ULL) << 32) | 0x91016261ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092EBCULL;
}

// FDE #3914 | PC: 0x092ec8..0x092edc (20 B) | Symbol: sub_092ec8
// EN: AArch64 prologue [orr x8, x22, #1; stp x19, x0, [x20, #8]; str x8, [x20]; mov x20, x0] | VI: Khởi đầu hàm AArch64 [orr x8, x22, #1; stp x19, x0, [x20, #8]; str x8, [x20]; mov x20, x0]
uint64_t fde_sub_092ec8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9008293ULL) << 32) | 0xB24002C8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092EC8ULL;
}

// FDE #3915 | PC: 0x092edc..0x092ee8 (12 B) | Symbol: sub_092edc
// EN: AArch64 prologue [mov x20, x1; str x8, [sp, #0x168]; b #0x4de80] | VI: Khởi đầu hàm AArch64 [mov x20, x1; str x8, [sp, #0x168]; b #0x4de80]
uint64_t fde_sub_092edc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900B7E8ULL) << 32) | 0xAA0103F4ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092EDCULL;
}

// FDE #3916 | PC: 0x092ee8..0x092ef0 (8 B) | Symbol: sub_092ee8
// EN: AArch64 prologue [mov x20, x1; b #0x93290] | VI: Khởi đầu hàm AArch64 [mov x20, x1; b #0x93290]
uint64_t fde_sub_092ee8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140000E9ULL) << 32) | 0xAA0103F4ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092EE8ULL;
}

// FDE #3917 | PC: 0x092ef0..0x092ef8 (8 B) | Symbol: sub_092ef0
// EN: AArch64 prologue [ldp x21, x20, [sp], #0x20; b #0x80a30] | VI: Khởi đầu hàm AArch64 [ldp x21, x20, [sp], #0x20; b #0x80a30]
uint64_t fde_sub_092ef0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFB6CFULL) << 32) | 0xA8C253F5ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092EF0ULL;
}

// FDE #3918 | PC: 0x092ef8..0x092f04 (12 B) | Symbol: sub_092ef8
// EN: AArch64 prologue [mov w0, #0x10; str xzr, [x20]; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov w0, #0x10; str xzr, [x20]; b #0x93320]
uint64_t fde_sub_092ef8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900029FULL) << 32) | 0x52800200ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092EF8ULL;
}

// FDE #3919 | PC: 0x092f04..0x092f10 (12 B) | Symbol: sub_092f04
// EN: AArch64 prologue [mov x20, x0; mov x0, x1; ret] | VI: Khởi đầu hàm AArch64 [mov x20, x0; mov x0, x1; ret]
uint64_t fde_sub_092f04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103E0ULL) << 32) | 0xAA0003F4ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092F04ULL;
}

// FDE #3920 | PC: 0x092f10..0x092f24 (20 B) | Symbol: sub_092f10
// EN: AArch64 prologue [mov x20, x0; stp xzr, xzr, [x0, #8]; str x8, [x0]; add x21, x0, #0x18] | VI: Khởi đầu hàm AArch64 [mov x20, x0; stp xzr, xzr, [x0, #8]; str x8, [x0]; add x21, x0, #0x18]
uint64_t fde_sub_092f10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA900FC1FULL) << 32) | 0xAA0003F4ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092F10ULL;
}

// FDE #3921 | PC: 0x092f24..0x092f30 (12 B) | Symbol: sub_092f24
// EN: AArch64 prologue [mov x20, x0; add x0, sp, #0x10; b #0x93390] | VI: Khởi đầu hàm AArch64 [mov x20, x0; add x0, sp, #0x10; b #0x93390]
uint64_t fde_sub_092f24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910043E0ULL) << 32) | 0xAA0003F4ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092F24ULL;
}

// FDE #3922 | PC: 0x092f30..0x092f3c (12 B) | Symbol: sub_092f30
// EN: AArch64 prologue [mov x20, x0; str x8, [x0], #8; ret] | VI: Khởi đầu hàm AArch64 [mov x20, x0; str x8, [x0], #8; ret]
uint64_t fde_sub_092f30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF8008408ULL) << 32) | 0xAA0003F4ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092F30ULL;
}

// FDE #3923 | PC: 0x092f3c..0x092f48 (12 B) | Symbol: sub_092f3c
// EN: AArch64 prologue [mov x20, x0; mov x0, x19; b #0x51254] | VI: Khởi đầu hàm AArch64 [mov x20, x0; mov x0, x19; b #0x51254]
uint64_t fde_sub_092f3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0xAA0003F4ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092F3CULL;
}

// FDE #3924 | PC: 0x092f48..0x092f54 (12 B) | Symbol: sub_092f48
// EN: AArch64 prologue [add x0, sp, #0x98; add x1, sp, #0x38; ret] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x98; add x1, sp, #0x38; ret]
uint64_t fde_sub_092f48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9100E3E1ULL) << 32) | 0x910263E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092F48ULL;
}

// FDE #3925 | PC: 0x092f54..0x092f5c (8 B) | Symbol: sub_092f54
// EN: AArch64 prologue [add x0, sp, #0x98; b #0x7c7bc] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x98; b #0x7c7bc]
uint64_t fde_sub_092f54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFA619ULL) << 32) | 0x910263E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092F54ULL;
}

// FDE #3926 | PC: 0x092f5c..0x092f70 (20 B) | Symbol: sub_092f5c
// EN: AArch64 prologue [adrp x1, #0x1c000; mov w9, #1; add x1, x1, #0xc6e; add x0, sp, #8] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x1c000; mov w9, #1; add x1, x1, #0xc6e; add x0, sp, #8]
uint64_t fde_sub_092f5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800029ULL) << 32) | 0xD0FFFC41ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092F5CULL;
}

// FDE #3927 | PC: 0x092f70..0x092f84 (20 B) | Symbol: sub_092f70
// EN: AArch64 prologue [ldr x8, [x19, #0x20]; sub x8, x8, x20; add x9, x8, #1; add x8, x8, x9, lsr #1] | VI: Khởi đầu hàm AArch64 [ldr x8, [x19, #0x20]; sub x8, x8, x20; add x9, x8, #1; add x8, x8, x9, lsr #1]
uint64_t fde_sub_092f70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xCB140108ULL) << 32) | 0xF9401268ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092F70ULL;
}

// FDE #3928 | PC: 0x092f84..0x092f98 (20 B) | Symbol: sub_092f84
// EN: AArch64 prologue [adrp x9, #0x1c000; add x9, x9, #0x660; cmp x8, #0; csel x1, x9, x1, eq] | VI: Khởi đầu hàm AArch64 [adrp x9, #0x1c000; add x9, x9, #0x660; cmp x8, #0; csel x1, x9, x1, eq]
uint64_t fde_sub_092f84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91198129ULL) << 32) | 0xD0FFFC49ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092F84ULL;
}

// FDE #3929 | PC: 0x092f98..0x092fa4 (12 B) | Symbol: sub_092f98
// EN: AArch64 prologue [ldr x0, [x19, #0x28]; str xzr, [x19, #0x28]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x19, #0x28]; str xzr, [x19, #0x28]; ret]
uint64_t fde_sub_092f98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900167FULL) << 32) | 0xF9401660ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092F98ULL;
}

// FDE #3930 | PC: 0x092fa4..0x092fb8 (20 B) | Symbol: sub_092fa4
// EN: AArch64 prologue [mov x19, x4; mov x20, x3; mov w21, w2; mov x22, x1] | VI: Khởi đầu hàm AArch64 [mov x19, x4; mov x20, x3; mov w21, w2; mov x22, x1]
uint64_t fde_sub_092fa4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0303F4ULL) << 32) | 0xAA0403F3ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092FA4ULL;
}

// FDE #3931 | PC: 0x092fb8..0x092fc4 (12 B) | Symbol: sub_092fb8
// EN: AArch64 prologue [adrp x1, #0x1c000; add x1, x1, #0xd5d; ret] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x1c000; add x1, x1, #0xd5d; ret]
uint64_t fde_sub_092fb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91357421ULL) << 32) | 0xD0FFFC41ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092FB8ULL;
}

// FDE #3932 | PC: 0x092fc4..0x092fd0 (12 B) | Symbol: sub_092fc4
// EN: AArch64 prologue [adrp x5, #0xa0000; add x5, x5, #0x440; ret] | VI: Khởi đầu hàm AArch64 [adrp x5, #0xa0000; add x5, x5, #0x440; ret]
uint64_t fde_sub_092fc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911100A5ULL) << 32) | 0xD0000065ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092FC4ULL;
}

// FDE #3933 | PC: 0x092fd0..0x092fdc (12 B) | Symbol: sub_092fd0
// EN: AArch64 prologue [add x0, sp, #0xd0; stp xzr, xzr, [sp, #0x40]; b #0x497b4] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0xd0; stp xzr, xzr, [sp, #0x40]; b #0x497b4]
uint64_t fde_sub_092fd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9047FFFULL) << 32) | 0x910343E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092FD0ULL;
}

// FDE #3934 | PC: 0x092fdc..0x092fe8 (12 B) | Symbol: sub_092fdc
// EN: AArch64 prologue [add x0, sp, #0xd0; add x1, sp, #0x100; b #0x47f90] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0xd0; add x1, sp, #0x100; b #0x47f90]
uint64_t fde_sub_092fdc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910403E1ULL) << 32) | 0x910343E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092FDCULL;
}

// FDE #3935 | PC: 0x092fe8..0x092ff4 (12 B) | Symbol: sub_092fe8
// EN: AArch64 prologue [sub x20, x20, #8; mov x0, x20; b #0x58e20] | VI: Khởi đầu hàm AArch64 [sub x20, x20, #8; mov x0, x20; b #0x58e20]
uint64_t fde_sub_092fe8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0xD1002294ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092FE8ULL;
}

// FDE #3936 | PC: 0x092ff4..0x093000 (12 B) | Symbol: sub_092ff4
// EN: AArch64 prologue [sub x20, x20, #8; mov x0, x20; b #0x58e94] | VI: Khởi đầu hàm AArch64 [sub x20, x20, #8; mov x0, x20; b #0x58e94]
uint64_t fde_sub_092ff4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0xD1002294ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092FF4ULL;
}

// FDE #3937 | PC: 0x093000..0x093008 (8 B) | Symbol: sub_093000
// EN: AArch64 prologue [add x0, sp, #0x60; b #0x46c54] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x60; b #0x46c54]
uint64_t fde_sub_093000(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FECF14ULL) << 32) | 0x910183E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093000ULL;
}

// FDE #3938 | PC: 0x093008..0x093014 (12 B) | Symbol: sub_093008
// EN: AArch64 prologue [add x0, sp, #0x60; strh w8, [sp, #0x70]; b #0x88780] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x60; strh w8, [sp, #0x70]; b #0x88780]
uint64_t fde_sub_093008(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7900E3E8ULL) << 32) | 0x910183E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093008ULL;
}

// FDE #3939 | PC: 0x093014..0x09301c (8 B) | Symbol: sub_093014
// EN: AArch64 prologue [mov x1, x28; b #0x93910] | VI: Khởi đầu hàm AArch64 [mov x1, x28; b #0x93910]
uint64_t fde_sub_093014(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400023EULL) << 32) | 0xAA1C03E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093014ULL;
}

// FDE #3940 | PC: 0x09301c..0x093028 (12 B) | Symbol: sub_09301c
// EN: AArch64 prologue [ldr x8, [x20, #8]; cmp x8, x21; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x20, #8]; cmp x8, x21; ret]
uint64_t fde_sub_09301c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB15011FULL) << 32) | 0xF9400688ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09301CULL;
}

// FDE #3941 | PC: 0x093028..0x093034 (12 B) | Symbol: sub_093028
// EN: AArch64 prologue [mov x0, sp; mov x1, x19; b #0x46b60] | VI: Khởi đầu hàm AArch64 [mov x0, sp; mov x1, x19; b #0x46b60]
uint64_t fde_sub_093028(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E1ULL) << 32) | 0x910003E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093028ULL;
}

// FDE #3942 | PC: 0x093034..0x09303c (8 B) | Symbol: sub_093034
// EN: AArch64 prologue [mov x0, sp; b #0x4816c] | VI: Khởi đầu hàm AArch64 [mov x0, sp; b #0x4816c]
uint64_t fde_sub_093034(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED44DULL) << 32) | 0x910003E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093034ULL;
}

// FDE #3943 | PC: 0x09303c..0x093044 (8 B) | Symbol: sub_09303c
// EN: AArch64 prologue [mov x0, sp; b #0x44a54] | VI: Khởi đầu hàm AArch64 [mov x0, sp; b #0x44a54]
uint64_t fde_sub_09303c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC685ULL) << 32) | 0x910003E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09303CULL;
}

// FDE #3944 | PC: 0x093044..0x09304c (8 B) | Symbol: sub_093044
// EN: AArch64 prologue [mov x0, sp; b #0x75540] | VI: Khởi đầu hàm AArch64 [mov x0, sp; b #0x75540]
uint64_t fde_sub_093044(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF893EULL) << 32) | 0x910003E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093044ULL;
}

// FDE #3945 | PC: 0x09304c..0x093058 (12 B) | Symbol: sub_09304c
// EN: AArch64 prologue [mov x0, sp; fcvt d8, s0; b #0x497b4] | VI: Khởi đầu hàm AArch64 [mov x0, sp; fcvt d8, s0; b #0x497b4]
uint64_t fde_sub_09304c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E22C008ULL) << 32) | 0x910003E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09304CULL;
}

// FDE #3946 | PC: 0x093058..0x093064 (12 B) | Symbol: sub_093058
// EN: AArch64 prologue [mov x0, sp; mov x1, x20; b #0x547d0] | VI: Khởi đầu hàm AArch64 [mov x0, sp; mov x1, x20; b #0x547d0]
uint64_t fde_sub_093058(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E1ULL) << 32) | 0x910003E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093058ULL;
}

// FDE #3947 | PC: 0x093064..0x093078 (20 B) | Symbol: sub_093064
// EN: AArch64 prologue [adrp x8, #0x9a000; add x8, x8, #0x5f0; add x9, x8, #0x80; fmov d0, x8] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9a000; add x8, x8, #0x5f0; add x9, x8, #0x80; fmov d0, x8]
uint64_t fde_sub_093064(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9117C108ULL) << 32) | 0xF0000028ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093064ULL;
}

// FDE #3948 | PC: 0x093078..0x093080 (8 B) | Symbol: sub_093078
// EN: AArch64 prologue [mov x0, x19; b #0x48da4] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x48da4]
uint64_t fde_sub_093078(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FED74AULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093078ULL;
}

// FDE #3949 | PC: 0x093080..0x093088 (8 B) | Symbol: sub_093080
// EN: AArch64 prologue [mov x0, x19; b #0x4de80] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x4de80]
uint64_t fde_sub_093080(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEEB7FULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093080ULL;
}

// FDE #3950 | PC: 0x093088..0x093094 (12 B) | Symbol: sub_093088
// EN: AArch64 prologue [mov x0, x19; mov x1, x23; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x19; mov x1, x23; ret]
uint64_t fde_sub_093088(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1703E1ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093088ULL;
}

// FDE #3951 | PC: 0x093094..0x09309c (8 B) | Symbol: sub_093094
// EN: AArch64 prologue [mov x0, x19; b #0x62cb0] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x62cb0]
uint64_t fde_sub_093094(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF3F06ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093094ULL;
}

// FDE #3952 | PC: 0x09309c..0x0930a8 (12 B) | Symbol: sub_09309c
// EN: AArch64 prologue [ldr x8, [x19]; ldr x20, [x8, x24, lsl #3]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x19]; ldr x20, [x8, x24, lsl #3]; ret]
uint64_t fde_sub_09309c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF8787914ULL) << 32) | 0xF9400268ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09309CULL;
}

// FDE #3953 | PC: 0x0930a8..0x0930b4 (12 B) | Symbol: sub_0930a8
// EN: AArch64 prologue [ldr x8, [x19]; str xzr, [x19]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x19]; str xzr, [x19]; ret]
uint64_t fde_sub_0930a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900027FULL) << 32) | 0xF9400268ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0930A8ULL;
}

// FDE #3954 | PC: 0x0930b4..0x0930c8 (20 B) | Symbol: sub_0930b4
// EN: AArch64 prologue [ldr x8, [x19]; str x8, [sp, #0x20]; ldr x8, [x19, #8]; str x8, [sp, #0x28]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x19]; str x8, [sp, #0x20]; ldr x8, [x19, #8]; str x8, [sp, #0x28]]
uint64_t fde_sub_0930b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013E8ULL) << 32) | 0xF9400268ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0930B4ULL;
}

// FDE #3955 | PC: 0x0930c8..0x0930d4 (12 B) | Symbol: sub_0930c8
// EN: AArch64 prologue [mov x19, x0; ldr x0, [x0]; ret] | VI: Khởi đầu hàm AArch64 [mov x19, x0; ldr x0, [x0]; ret]
uint64_t fde_sub_0930c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400000ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0930C8ULL;
}

// FDE #3956 | PC: 0x0930d4..0x0930dc (8 B) | Symbol: sub_0930d4
// EN: AArch64 prologue [mov x19, x0; b #0x649f8] | VI: Khởi đầu hàm AArch64 [mov x19, x0; b #0x649f8]
uint64_t fde_sub_0930d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF4648ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0930D4ULL;
}

// FDE #3957 | PC: 0x0930dc..0x0930e8 (12 B) | Symbol: sub_0930dc
// EN: AArch64 prologue [mov x19, x0; add x0, x0, #0x28; ret] | VI: Khởi đầu hàm AArch64 [mov x19, x0; add x0, x0, #0x28; ret]
uint64_t fde_sub_0930dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9100A000ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0930DCULL;
}

// FDE #3958 | PC: 0x0930e8..0x0930f4 (12 B) | Symbol: sub_0930e8
// EN: AArch64 prologue [mov x19, x0; add x0, x0, #0x48; b #0x46c54] | VI: Khởi đầu hàm AArch64 [mov x19, x0; add x0, x0, #0x48; b #0x46c54]
uint64_t fde_sub_0930e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91012000ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0930E8ULL;
}

// FDE #3959 | PC: 0x0930f4..0x093100 (12 B) | Symbol: sub_0930f4
// EN: AArch64 prologue [mov x19, x0; ldr x0, [x0, #0x50]; ret] | VI: Khởi đầu hàm AArch64 [mov x19, x0; ldr x0, [x0, #0x50]; ret]
uint64_t fde_sub_0930f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402800ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0930F4ULL;
}

// FDE #3960 | PC: 0x093100..0x09310c (12 B) | Symbol: sub_093100
// EN: AArch64 prologue [mov x19, x0; add x0, x0, #0x10; b #0x4b288] | VI: Khởi đầu hàm AArch64 [mov x19, x0; add x0, x0, #0x10; b #0x4b288]
uint64_t fde_sub_093100(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91004000ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093100ULL;
}

// FDE #3961 | PC: 0x09310c..0x093118 (12 B) | Symbol: sub_09310c
// EN: AArch64 prologue [mov x19, x0; add x0, x0, #0x50; b #0x46c54] | VI: Khởi đầu hàm AArch64 [mov x19, x0; add x0, x0, #0x50; b #0x46c54]
uint64_t fde_sub_09310c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91014000ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09310CULL;
}

// FDE #3962 | PC: 0x093118..0x093134 (28 B) | Symbol: sub_093118
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x40; bl #0x46c54] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x40; bl #0x46c54]
uint64_t fde_sub_093118(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093118ULL;
}

// FDE #3963 | PC: 0x093134..0x093148 (20 B) | Symbol: sub_093134
// EN: AArch64 prologue [strb w24, [x21, #0xa4]; strb w24, [x21, #0xac]; str wzr, [x21, #0xb0]; strb w24, [x21, #0xb4]] | VI: Khởi đầu hàm AArch64 [strb w24, [x21, #0xa4]; strb w24, [x21, #0xac]; str wzr, [x21, #0xb0]; strb w24, [x21, #0xb4]]
uint64_t fde_sub_093134(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3902B2B8ULL) << 32) | 0x390292B8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093134ULL;
}

// FDE #3964 | PC: 0x093148..0x09315c (20 B) | Symbol: sub_093148
// EN: AArch64 prologue [mrs x20, tpidr_el0; ldr x8, [x20, #0x28]; mov x19, x0; mov x0, x1] | VI: Khởi đầu hàm AArch64 [mrs x20, tpidr_el0; ldr x8, [x20, #0x28]; mov x19, x0; mov x0, x1]
uint64_t fde_sub_093148(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401688ULL) << 32) | 0xD53BD054ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093148ULL;
}

uint64_t DispatchAnimaXShard5(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x090578ULL: return fde_sub_090578(a0, a1, a2);
        case 0x090584ULL: return fde_sub_090584(a0, a1, a2);
        case 0x090590ULL: return fde_sub_090590(a0, a1, a2);
        case 0x090598ULL: return fde_sub_090598(a0, a1, a2);
        case 0x0905b4ULL: return fde_sub_0905b4(a0, a1, a2);
        case 0x0905c8ULL: return fde_sub_0905c8(a0, a1, a2);
        case 0x0905d4ULL: return fde_sub_0905d4(a0, a1, a2);
        case 0x0905e0ULL: return fde_sub_0905e0(a0, a1, a2);
        case 0x0905ecULL: return fde_sub_0905ec(a0, a1, a2);
        case 0x090600ULL: return fde_sub_090600(a0, a1, a2);
        case 0x09060cULL: return fde_sub_09060c(a0, a1, a2);
        case 0x090618ULL: return fde_sub_090618(a0, a1, a2);
        case 0x090624ULL: return fde_sub_090624(a0, a1, a2);
        case 0x090630ULL: return fde_sub_090630(a0, a1, a2);
        case 0x090644ULL: return fde_sub_090644(a0, a1, a2);
        case 0x090660ULL: return fde_sub_090660(a0, a1, a2);
        case 0x090668ULL: return fde_sub_090668(a0, a1, a2);
        case 0x090674ULL: return fde_sub_090674(a0, a1, a2);
        case 0x09067cULL: return fde_sub_09067c(a0, a1, a2);
        case 0x090684ULL: return fde_sub_090684(a0, a1, a2);
        case 0x090690ULL: return fde_sub_090690(a0, a1, a2);
        case 0x0906acULL: return fde_sub_0906ac(a0, a1, a2);
        case 0x0906c0ULL: return fde_sub_0906c0(a0, a1, a2);
        case 0x0906d4ULL: return fde_sub_0906d4(a0, a1, a2);
        case 0x0906dcULL: return fde_sub_0906dc(a0, a1, a2);
        case 0x0906e8ULL: return fde_sub_0906e8(a0, a1, a2);
        case 0x090704ULL: return fde_sub_090704(a0, a1, a2);
        case 0x090720ULL: return fde_sub_090720(a0, a1, a2);
        case 0x090734ULL: return fde_sub_090734(a0, a1, a2);
        case 0x090740ULL: return fde_sub_090740(a0, a1, a2);
        case 0x090754ULL: return fde_sub_090754(a0, a1, a2);
        case 0x090760ULL: return fde_sub_090760(a0, a1, a2);
        case 0x090768ULL: return fde_sub_090768(a0, a1, a2);
        case 0x090774ULL: return fde_sub_090774(a0, a1, a2);
        case 0x09077cULL: return fde_sub_09077c(a0, a1, a2);
        case 0x090790ULL: return fde_sub_090790(a0, a1, a2);
        case 0x09079cULL: return fde_sub_09079c(a0, a1, a2);
        case 0x0907b0ULL: return fde_sub_0907b0(a0, a1, a2);
        case 0x0907bcULL: return fde_sub_0907bc(a0, a1, a2);
        case 0x0907c4ULL: return fde_sub_0907c4(a0, a1, a2);
        case 0x0907ccULL: return fde_sub_0907cc(a0, a1, a2);
        case 0x0907d8ULL: return fde_sub_0907d8(a0, a1, a2);
        case 0x0907e0ULL: return fde_sub_0907e0(a0, a1, a2);
        case 0x0907ecULL: return fde_sub_0907ec(a0, a1, a2);
        case 0x0907f8ULL: return fde_sub_0907f8(a0, a1, a2);
        case 0x09080cULL: return fde_sub_09080c(a0, a1, a2);
        case 0x090820ULL: return fde_sub_090820(a0, a1, a2);
        case 0x090828ULL: return fde_sub_090828(a0, a1, a2);
        case 0x090834ULL: return fde_sub_090834(a0, a1, a2);
        case 0x090848ULL: return fde_sub_090848(a0, a1, a2);
        case 0x090850ULL: return fde_sub_090850(a0, a1, a2);
        case 0x090858ULL: return fde_sub_090858(a0, a1, a2);
        case 0x090864ULL: return fde_sub_090864(a0, a1, a2);
        case 0x090870ULL: return fde_sub_090870(a0, a1, a2);
        case 0x09087cULL: return fde_sub_09087c(a0, a1, a2);
        case 0x090890ULL: return fde_sub_090890(a0, a1, a2);
        case 0x0908acULL: return fde_sub_0908ac(a0, a1, a2);
        case 0x0908c8ULL: return fde_sub_0908c8(a0, a1, a2);
        case 0x0908d4ULL: return fde_sub_0908d4(a0, a1, a2);
        case 0x0908e8ULL: return fde_sub_0908e8(a0, a1, a2);
        case 0x0908f4ULL: return fde_sub_0908f4(a0, a1, a2);
        case 0x090910ULL: return fde_sub_090910(a0, a1, a2);
        case 0x09092cULL: return fde_sub_09092c(a0, a1, a2);
        case 0x090938ULL: return fde_sub_090938(a0, a1, a2);
        case 0x09095cULL: return fde_sub_09095c(a0, a1, a2);
        case 0x090968ULL: return fde_sub_090968(a0, a1, a2);
        case 0x09097cULL: return fde_sub_09097c(a0, a1, a2);
        case 0x090988ULL: return fde_sub_090988(a0, a1, a2);
        case 0x0909a4ULL: return fde_sub_0909a4(a0, a1, a2);
        case 0x0909b0ULL: return fde_sub_0909b0(a0, a1, a2);
        case 0x0909bcULL: return fde_sub_0909bc(a0, a1, a2);
        case 0x0909c8ULL: return fde_sub_0909c8(a0, a1, a2);
        case 0x0909e4ULL: return fde_sub_0909e4(a0, a1, a2);
        case 0x0909f8ULL: return fde_sub_0909f8(a0, a1, a2);
        case 0x090a0cULL: return fde_sub_090a0c(a0, a1, a2);
        case 0x090a18ULL: return fde_sub_090a18(a0, a1, a2);
        case 0x090a24ULL: return fde_sub_090a24(a0, a1, a2);
        case 0x090a30ULL: return fde_sub_090a30(a0, a1, a2);
        case 0x090a38ULL: return fde_sub_090a38(a0, a1, a2);
        case 0x090a44ULL: return fde_sub_090a44(a0, a1, a2);
        case 0x090a50ULL: return fde_sub_090a50(a0, a1, a2);
        case 0x090a5cULL: return fde_sub_090a5c(a0, a1, a2);
        case 0x090a64ULL: return fde_sub_090a64(a0, a1, a2);
        case 0x090a70ULL: return fde_sub_090a70(a0, a1, a2);
        case 0x090a8cULL: return fde_sub_090a8c(a0, a1, a2);
        case 0x090a94ULL: return fde_sub_090a94(a0, a1, a2);
        case 0x090aa0ULL: return fde_sub_090aa0(a0, a1, a2);
        case 0x090ab4ULL: return fde_sub_090ab4(a0, a1, a2);
        case 0x090ac0ULL: return fde_sub_090ac0(a0, a1, a2);
        case 0x090ad4ULL: return fde_sub_090ad4(a0, a1, a2);
        case 0x090ae8ULL: return fde_sub_090ae8(a0, a1, a2);
        case 0x090af4ULL: return fde_sub_090af4(a0, a1, a2);
        case 0x090b00ULL: return fde_sub_090b00(a0, a1, a2);
        case 0x090b0cULL: return fde_sub_090b0c(a0, a1, a2);
        case 0x090b24ULL: return fde_sub_090b24(a0, a1, a2);
        case 0x090b2cULL: return fde_sub_090b2c(a0, a1, a2);
        case 0x090b38ULL: return fde_sub_090b38(a0, a1, a2);
        case 0x090b54ULL: return fde_sub_090b54(a0, a1, a2);
        case 0x090b68ULL: return fde_sub_090b68(a0, a1, a2);
        case 0x090b84ULL: return fde_sub_090b84(a0, a1, a2);
        case 0x090b98ULL: return fde_sub_090b98(a0, a1, a2);
        case 0x090ba4ULL: return fde_sub_090ba4(a0, a1, a2);
        case 0x090bb0ULL: return fde_sub_090bb0(a0, a1, a2);
        case 0x090bc4ULL: return fde_sub_090bc4(a0, a1, a2);
        case 0x090bd0ULL: return fde_sub_090bd0(a0, a1, a2);
        case 0x090becULL: return fde_sub_090bec(a0, a1, a2);
        case 0x090c08ULL: return fde_sub_090c08(a0, a1, a2);
        case 0x090c14ULL: return fde_sub_090c14(a0, a1, a2);
        case 0x090c28ULL: return fde_sub_090c28(a0, a1, a2);
        case 0x090c3cULL: return fde_sub_090c3c(a0, a1, a2);
        case 0x090c48ULL: return fde_sub_090c48(a0, a1, a2);
        case 0x090c50ULL: return fde_sub_090c50(a0, a1, a2);
        case 0x090c5cULL: return fde_sub_090c5c(a0, a1, a2);
        case 0x090c64ULL: return fde_sub_090c64(a0, a1, a2);
        case 0x090c70ULL: return fde_sub_090c70(a0, a1, a2);
        case 0x090c78ULL: return fde_sub_090c78(a0, a1, a2);
        case 0x090c80ULL: return fde_sub_090c80(a0, a1, a2);
        case 0x090c8cULL: return fde_sub_090c8c(a0, a1, a2);
        case 0x090c98ULL: return fde_sub_090c98(a0, a1, a2);
        case 0x090cb4ULL: return fde_sub_090cb4(a0, a1, a2);
        case 0x090cc0ULL: return fde_sub_090cc0(a0, a1, a2);
        case 0x090cc8ULL: return fde_sub_090cc8(a0, a1, a2);
        case 0x090cd8ULL: return fde_sub_090cd8(a0, a1, a2);
        case 0x090cf0ULL: return fde_sub_090cf0(a0, a1, a2);
        case 0x090d0cULL: return fde_sub_090d0c(a0, a1, a2);
        case 0x090d1cULL: return fde_sub_090d1c(a0, a1, a2);
        case 0x090d24ULL: return fde_sub_090d24(a0, a1, a2);
        case 0x090d34ULL: return fde_sub_090d34(a0, a1, a2);
        case 0x090d40ULL: return fde_sub_090d40(a0, a1, a2);
        case 0x090d58ULL: return fde_sub_090d58(a0, a1, a2);
        case 0x090d68ULL: return fde_sub_090d68(a0, a1, a2);
        case 0x090d78ULL: return fde_sub_090d78(a0, a1, a2);
        case 0x090d88ULL: return fde_sub_090d88(a0, a1, a2);
        case 0x090d90ULL: return fde_sub_090d90(a0, a1, a2);
        case 0x090d98ULL: return fde_sub_090d98(a0, a1, a2);
        case 0x090da8ULL: return fde_sub_090da8(a0, a1, a2);
        case 0x090dc0ULL: return fde_sub_090dc0(a0, a1, a2);
        case 0x090dc8ULL: return fde_sub_090dc8(a0, a1, a2);
        case 0x090dd8ULL: return fde_sub_090dd8(a0, a1, a2);
        case 0x090de8ULL: return fde_sub_090de8(a0, a1, a2);
        case 0x090df8ULL: return fde_sub_090df8(a0, a1, a2);
        case 0x090e00ULL: return fde_sub_090e00(a0, a1, a2);
        case 0x090e10ULL: return fde_sub_090e10(a0, a1, a2);
        case 0x090e18ULL: return fde_sub_090e18(a0, a1, a2);
        case 0x090e20ULL: return fde_sub_090e20(a0, a1, a2);
        case 0x090e30ULL: return fde_sub_090e30(a0, a1, a2);
        case 0x090e40ULL: return fde_sub_090e40(a0, a1, a2);
        case 0x090e50ULL: return fde_sub_090e50(a0, a1, a2);
        case 0x090e58ULL: return fde_sub_090e58(a0, a1, a2);
        case 0x090e68ULL: return fde_sub_090e68(a0, a1, a2);
        case 0x090e70ULL: return fde_sub_090e70(a0, a1, a2);
        case 0x090e80ULL: return fde_sub_090e80(a0, a1, a2);
        case 0x090e98ULL: return fde_sub_090e98(a0, a1, a2);
        case 0x090ea0ULL: return fde_sub_090ea0(a0, a1, a2);
        case 0x090eacULL: return fde_sub_090eac(a0, a1, a2);
        case 0x090eb8ULL: return fde_sub_090eb8(a0, a1, a2);
        case 0x090ec8ULL: return fde_sub_090ec8(a0, a1, a2);
        case 0x090ed4ULL: return fde_sub_090ed4(a0, a1, a2);
        case 0x090ee0ULL: return fde_sub_090ee0(a0, a1, a2);
        case 0x090eecULL: return fde_sub_090eec(a0, a1, a2);
        case 0x090ef8ULL: return fde_sub_090ef8(a0, a1, a2);
        case 0x090f04ULL: return fde_sub_090f04(a0, a1, a2);
        case 0x090f14ULL: return fde_sub_090f14(a0, a1, a2);
        case 0x090f20ULL: return fde_sub_090f20(a0, a1, a2);
        case 0x090f30ULL: return fde_sub_090f30(a0, a1, a2);
        case 0x090f48ULL: return fde_sub_090f48(a0, a1, a2);
        case 0x090f60ULL: return fde_sub_090f60(a0, a1, a2);
        case 0x090f70ULL: return fde_sub_090f70(a0, a1, a2);
        case 0x090f78ULL: return fde_sub_090f78(a0, a1, a2);
        case 0x090f88ULL: return fde_sub_090f88(a0, a1, a2);
        case 0x090f98ULL: return fde_sub_090f98(a0, a1, a2);
        case 0x090fa0ULL: return fde_sub_090fa0(a0, a1, a2);
        case 0x090facULL: return fde_sub_090fac(a0, a1, a2);
        case 0x090fb8ULL: return fde_sub_090fb8(a0, a1, a2);
        case 0x090fc4ULL: return fde_sub_090fc4(a0, a1, a2);
        case 0x090fdcULL: return fde_sub_090fdc(a0, a1, a2);
        case 0x090fe8ULL: return fde_sub_090fe8(a0, a1, a2);
        case 0x091000ULL: return fde_sub_091000(a0, a1, a2);
        case 0x091008ULL: return fde_sub_091008(a0, a1, a2);
        case 0x091018ULL: return fde_sub_091018(a0, a1, a2);
        case 0x091030ULL: return fde_sub_091030(a0, a1, a2);
        case 0x091040ULL: return fde_sub_091040(a0, a1, a2);
        case 0x091050ULL: return fde_sub_091050(a0, a1, a2);
        case 0x091064ULL: return fde_sub_091064(a0, a1, a2);
        case 0x09106cULL: return fde_sub_09106c(a0, a1, a2);
        case 0x091074ULL: return fde_sub_091074(a0, a1, a2);
        case 0x09107cULL: return fde_sub_09107c(a0, a1, a2);
        case 0x09108cULL: return fde_sub_09108c(a0, a1, a2);
        case 0x09109cULL: return fde_sub_09109c(a0, a1, a2);
        case 0x0910acULL: return fde_sub_0910ac(a0, a1, a2);
        case 0x0910c4ULL: return fde_sub_0910c4(a0, a1, a2);
        case 0x0910ccULL: return fde_sub_0910cc(a0, a1, a2);
        case 0x0910dcULL: return fde_sub_0910dc(a0, a1, a2);
        case 0x0910e8ULL: return fde_sub_0910e8(a0, a1, a2);
        case 0x0910f8ULL: return fde_sub_0910f8(a0, a1, a2);
        case 0x091108ULL: return fde_sub_091108(a0, a1, a2);
        case 0x091110ULL: return fde_sub_091110(a0, a1, a2);
        case 0x091118ULL: return fde_sub_091118(a0, a1, a2);
        case 0x091128ULL: return fde_sub_091128(a0, a1, a2);
        case 0x091130ULL: return fde_sub_091130(a0, a1, a2);
        case 0x091140ULL: return fde_sub_091140(a0, a1, a2);
        case 0x091148ULL: return fde_sub_091148(a0, a1, a2);
        case 0x091150ULL: return fde_sub_091150(a0, a1, a2);
        case 0x091158ULL: return fde_sub_091158(a0, a1, a2);
        case 0x091168ULL: return fde_sub_091168(a0, a1, a2);
        case 0x091178ULL: return fde_sub_091178(a0, a1, a2);
        case 0x091188ULL: return fde_sub_091188(a0, a1, a2);
        case 0x091190ULL: return fde_sub_091190(a0, a1, a2);
        case 0x0911a0ULL: return fde_sub_0911a0(a0, a1, a2);
        case 0x0911a8ULL: return fde_sub_0911a8(a0, a1, a2);
        case 0x0911b8ULL: return fde_sub_0911b8(a0, a1, a2);
        case 0x0911c8ULL: return fde_sub_0911c8(a0, a1, a2);
        case 0x0911e0ULL: return fde_sub_0911e0(a0, a1, a2);
        case 0x0911ecULL: return fde_sub_0911ec(a0, a1, a2);
        case 0x0911fcULL: return fde_sub_0911fc(a0, a1, a2);
        case 0x091208ULL: return fde_sub_091208(a0, a1, a2);
        case 0x091218ULL: return fde_sub_091218(a0, a1, a2);
        case 0x091228ULL: return fde_sub_091228(a0, a1, a2);
        case 0x091240ULL: return fde_sub_091240(a0, a1, a2);
        case 0x091258ULL: return fde_sub_091258(a0, a1, a2);
        case 0x091260ULL: return fde_sub_091260(a0, a1, a2);
        case 0x091270ULL: return fde_sub_091270(a0, a1, a2);
        case 0x091278ULL: return fde_sub_091278(a0, a1, a2);
        case 0x091288ULL: return fde_sub_091288(a0, a1, a2);
        case 0x091298ULL: return fde_sub_091298(a0, a1, a2);
        case 0x0912a8ULL: return fde_sub_0912a8(a0, a1, a2);
        case 0x0912b8ULL: return fde_sub_0912b8(a0, a1, a2);
        case 0x0912c8ULL: return fde_sub_0912c8(a0, a1, a2);
        case 0x0912d8ULL: return fde_sub_0912d8(a0, a1, a2);
        case 0x0912e8ULL: return fde_sub_0912e8(a0, a1, a2);
        case 0x0912f8ULL: return fde_sub_0912f8(a0, a1, a2);
        case 0x091310ULL: return fde_sub_091310(a0, a1, a2);
        case 0x091320ULL: return fde_sub_091320(a0, a1, a2);
        case 0x091328ULL: return fde_sub_091328(a0, a1, a2);
        case 0x091338ULL: return fde_sub_091338(a0, a1, a2);
        case 0x091340ULL: return fde_sub_091340(a0, a1, a2);
        case 0x091348ULL: return fde_sub_091348(a0, a1, a2);
        case 0x091358ULL: return fde_sub_091358(a0, a1, a2);
        case 0x091368ULL: return fde_sub_091368(a0, a1, a2);
        case 0x091374ULL: return fde_sub_091374(a0, a1, a2);
        case 0x091384ULL: return fde_sub_091384(a0, a1, a2);
        case 0x09139cULL: return fde_sub_09139c(a0, a1, a2);
        case 0x0913b8ULL: return fde_sub_0913b8(a0, a1, a2);
        case 0x0913d4ULL: return fde_sub_0913d4(a0, a1, a2);
        case 0x0913e4ULL: return fde_sub_0913e4(a0, a1, a2);
        case 0x0913f0ULL: return fde_sub_0913f0(a0, a1, a2);
        case 0x091418ULL: return fde_sub_091418(a0, a1, a2);
        case 0x091420ULL: return fde_sub_091420(a0, a1, a2);
        case 0x091430ULL: return fde_sub_091430(a0, a1, a2);
        case 0x091448ULL: return fde_sub_091448(a0, a1, a2);
        case 0x091460ULL: return fde_sub_091460(a0, a1, a2);
        case 0x091478ULL: return fde_sub_091478(a0, a1, a2);
        case 0x091490ULL: return fde_sub_091490(a0, a1, a2);
        case 0x0914a8ULL: return fde_sub_0914a8(a0, a1, a2);
        case 0x0914b8ULL: return fde_sub_0914b8(a0, a1, a2);
        case 0x0914c0ULL: return fde_sub_0914c0(a0, a1, a2);
        case 0x0914d0ULL: return fde_sub_0914d0(a0, a1, a2);
        case 0x0914dcULL: return fde_sub_0914dc(a0, a1, a2);
        case 0x0914ecULL: return fde_sub_0914ec(a0, a1, a2);
        case 0x0914f8ULL: return fde_sub_0914f8(a0, a1, a2);
        case 0x091508ULL: return fde_sub_091508(a0, a1, a2);
        case 0x091518ULL: return fde_sub_091518(a0, a1, a2);
        case 0x091538ULL: return fde_sub_091538(a0, a1, a2);
        case 0x091540ULL: return fde_sub_091540(a0, a1, a2);
        case 0x091558ULL: return fde_sub_091558(a0, a1, a2);
        case 0x091568ULL: return fde_sub_091568(a0, a1, a2);
        case 0x091580ULL: return fde_sub_091580(a0, a1, a2);
        case 0x091588ULL: return fde_sub_091588(a0, a1, a2);
        case 0x0915a0ULL: return fde_sub_0915a0(a0, a1, a2);
        case 0x0915a8ULL: return fde_sub_0915a8(a0, a1, a2);
        case 0x0915c0ULL: return fde_sub_0915c0(a0, a1, a2);
        case 0x0915d0ULL: return fde_sub_0915d0(a0, a1, a2);
        case 0x0915d8ULL: return fde_sub_0915d8(a0, a1, a2);
        case 0x0915e0ULL: return fde_sub_0915e0(a0, a1, a2);
        case 0x0915f0ULL: return fde_sub_0915f0(a0, a1, a2);
        case 0x0915f8ULL: return fde_sub_0915f8(a0, a1, a2);
        case 0x091608ULL: return fde_sub_091608(a0, a1, a2);
        case 0x091618ULL: return fde_sub_091618(a0, a1, a2);
        case 0x091630ULL: return fde_sub_091630(a0, a1, a2);
        case 0x091638ULL: return fde_sub_091638(a0, a1, a2);
        case 0x091650ULL: return fde_sub_091650(a0, a1, a2);
        case 0x091658ULL: return fde_sub_091658(a0, a1, a2);
        case 0x091668ULL: return fde_sub_091668(a0, a1, a2);
        case 0x091674ULL: return fde_sub_091674(a0, a1, a2);
        case 0x091684ULL: return fde_sub_091684(a0, a1, a2);
        case 0x091690ULL: return fde_sub_091690(a0, a1, a2);
        case 0x091698ULL: return fde_sub_091698(a0, a1, a2);
        case 0x0916a8ULL: return fde_sub_0916a8(a0, a1, a2);
        case 0x0916b0ULL: return fde_sub_0916b0(a0, a1, a2);
        case 0x0916c0ULL: return fde_sub_0916c0(a0, a1, a2);
        case 0x0916c8ULL: return fde_sub_0916c8(a0, a1, a2);
        case 0x0916d0ULL: return fde_sub_0916d0(a0, a1, a2);
        case 0x0916e0ULL: return fde_sub_0916e0(a0, a1, a2);
        case 0x0916f0ULL: return fde_sub_0916f0(a0, a1, a2);
        case 0x091700ULL: return fde_sub_091700(a0, a1, a2);
        case 0x091718ULL: return fde_sub_091718(a0, a1, a2);
        case 0x091724ULL: return fde_sub_091724(a0, a1, a2);
        case 0x09173cULL: return fde_sub_09173c(a0, a1, a2);
        case 0x091754ULL: return fde_sub_091754(a0, a1, a2);
        case 0x09176cULL: return fde_sub_09176c(a0, a1, a2);
        case 0x091778ULL: return fde_sub_091778(a0, a1, a2);
        case 0x091784ULL: return fde_sub_091784(a0, a1, a2);
        case 0x091790ULL: return fde_sub_091790(a0, a1, a2);
        case 0x09179cULL: return fde_sub_09179c(a0, a1, a2);
        case 0x0917a4ULL: return fde_sub_0917a4(a0, a1, a2);
        case 0x0917acULL: return fde_sub_0917ac(a0, a1, a2);
        case 0x0917c8ULL: return fde_sub_0917c8(a0, a1, a2);
        case 0x0917d8ULL: return fde_sub_0917d8(a0, a1, a2);
        case 0x0917e8ULL: return fde_sub_0917e8(a0, a1, a2);
        case 0x091800ULL: return fde_sub_091800(a0, a1, a2);
        case 0x091808ULL: return fde_sub_091808(a0, a1, a2);
        case 0x091818ULL: return fde_sub_091818(a0, a1, a2);
        case 0x091828ULL: return fde_sub_091828(a0, a1, a2);
        case 0x091838ULL: return fde_sub_091838(a0, a1, a2);
        case 0x091844ULL: return fde_sub_091844(a0, a1, a2);
        case 0x091854ULL: return fde_sub_091854(a0, a1, a2);
        case 0x09186cULL: return fde_sub_09186c(a0, a1, a2);
        case 0x091884ULL: return fde_sub_091884(a0, a1, a2);
        case 0x091894ULL: return fde_sub_091894(a0, a1, a2);
        case 0x0918a4ULL: return fde_sub_0918a4(a0, a1, a2);
        case 0x0918b8ULL: return fde_sub_0918b8(a0, a1, a2);
        case 0x0918c8ULL: return fde_sub_0918c8(a0, a1, a2);
        case 0x0918d8ULL: return fde_sub_0918d8(a0, a1, a2);
        case 0x0918e8ULL: return fde_sub_0918e8(a0, a1, a2);
        case 0x0918f8ULL: return fde_sub_0918f8(a0, a1, a2);
        case 0x091908ULL: return fde_sub_091908(a0, a1, a2);
        case 0x091920ULL: return fde_sub_091920(a0, a1, a2);
        case 0x091930ULL: return fde_sub_091930(a0, a1, a2);
        case 0x09193cULL: return fde_sub_09193c(a0, a1, a2);
        case 0x091944ULL: return fde_sub_091944(a0, a1, a2);
        case 0x091950ULL: return fde_sub_091950(a0, a1, a2);
        case 0x091968ULL: return fde_sub_091968(a0, a1, a2);
        case 0x091978ULL: return fde_sub_091978(a0, a1, a2);
        case 0x091984ULL: return fde_sub_091984(a0, a1, a2);
        case 0x09198cULL: return fde_sub_09198c(a0, a1, a2);
        case 0x09199cULL: return fde_sub_09199c(a0, a1, a2);
        case 0x0919b4ULL: return fde_sub_0919b4(a0, a1, a2);
        case 0x0919d0ULL: return fde_sub_0919d0(a0, a1, a2);
        case 0x0919e0ULL: return fde_sub_0919e0(a0, a1, a2);
        case 0x0919f0ULL: return fde_sub_0919f0(a0, a1, a2);
        case 0x091a08ULL: return fde_sub_091a08(a0, a1, a2);
        case 0x091a10ULL: return fde_sub_091a10(a0, a1, a2);
        case 0x091a18ULL: return fde_sub_091a18(a0, a1, a2);
        case 0x091a28ULL: return fde_sub_091a28(a0, a1, a2);
        case 0x091a38ULL: return fde_sub_091a38(a0, a1, a2);
        case 0x091a48ULL: return fde_sub_091a48(a0, a1, a2);
        case 0x091a58ULL: return fde_sub_091a58(a0, a1, a2);
        case 0x091a68ULL: return fde_sub_091a68(a0, a1, a2);
        case 0x091a74ULL: return fde_sub_091a74(a0, a1, a2);
        case 0x091a94ULL: return fde_sub_091a94(a0, a1, a2);
        case 0x091aacULL: return fde_sub_091aac(a0, a1, a2);
        case 0x091ac4ULL: return fde_sub_091ac4(a0, a1, a2);
        case 0x091ad0ULL: return fde_sub_091ad0(a0, a1, a2);
        case 0x091ae8ULL: return fde_sub_091ae8(a0, a1, a2);
        case 0x091af8ULL: return fde_sub_091af8(a0, a1, a2);
        case 0x091b10ULL: return fde_sub_091b10(a0, a1, a2);
        case 0x091b18ULL: return fde_sub_091b18(a0, a1, a2);
        case 0x091b34ULL: return fde_sub_091b34(a0, a1, a2);
        case 0x091b40ULL: return fde_sub_091b40(a0, a1, a2);
        case 0x091b4cULL: return fde_sub_091b4c(a0, a1, a2);
        case 0x091b5cULL: return fde_sub_091b5c(a0, a1, a2);
        case 0x091b64ULL: return fde_sub_091b64(a0, a1, a2);
        case 0x091b74ULL: return fde_sub_091b74(a0, a1, a2);
        case 0x091b84ULL: return fde_sub_091b84(a0, a1, a2);
        case 0x091b94ULL: return fde_sub_091b94(a0, a1, a2);
        case 0x091b9cULL: return fde_sub_091b9c(a0, a1, a2);
        case 0x091bb4ULL: return fde_sub_091bb4(a0, a1, a2);
        case 0x091bc0ULL: return fde_sub_091bc0(a0, a1, a2);
        case 0x091bccULL: return fde_sub_091bcc(a0, a1, a2);
        case 0x091bdcULL: return fde_sub_091bdc(a0, a1, a2);
        case 0x091bf4ULL: return fde_sub_091bf4(a0, a1, a2);
        case 0x091c00ULL: return fde_sub_091c00(a0, a1, a2);
        case 0x091c08ULL: return fde_sub_091c08(a0, a1, a2);
        case 0x091c18ULL: return fde_sub_091c18(a0, a1, a2);
        case 0x091c34ULL: return fde_sub_091c34(a0, a1, a2);
        case 0x091c40ULL: return fde_sub_091c40(a0, a1, a2);
        case 0x091c4cULL: return fde_sub_091c4c(a0, a1, a2);
        case 0x091c5cULL: return fde_sub_091c5c(a0, a1, a2);
        case 0x091c6cULL: return fde_sub_091c6c(a0, a1, a2);
        case 0x091c7cULL: return fde_sub_091c7c(a0, a1, a2);
        case 0x091c8cULL: return fde_sub_091c8c(a0, a1, a2);
        case 0x091c94ULL: return fde_sub_091c94(a0, a1, a2);
        case 0x091ca4ULL: return fde_sub_091ca4(a0, a1, a2);
        case 0x091cb4ULL: return fde_sub_091cb4(a0, a1, a2);
        case 0x091cccULL: return fde_sub_091ccc(a0, a1, a2);
        case 0x091cd8ULL: return fde_sub_091cd8(a0, a1, a2);
        case 0x091cf4ULL: return fde_sub_091cf4(a0, a1, a2);
        case 0x091d04ULL: return fde_sub_091d04(a0, a1, a2);
        case 0x091d0cULL: return fde_sub_091d0c(a0, a1, a2);
        case 0x091d1cULL: return fde_sub_091d1c(a0, a1, a2);
        case 0x091d24ULL: return fde_sub_091d24(a0, a1, a2);
        case 0x091d30ULL: return fde_sub_091d30(a0, a1, a2);
        case 0x091d48ULL: return fde_sub_091d48(a0, a1, a2);
        case 0x091d50ULL: return fde_sub_091d50(a0, a1, a2);
        case 0x091d58ULL: return fde_sub_091d58(a0, a1, a2);
        case 0x091d60ULL: return fde_sub_091d60(a0, a1, a2);
        case 0x091d68ULL: return fde_sub_091d68(a0, a1, a2);
        case 0x091d74ULL: return fde_sub_091d74(a0, a1, a2);
        case 0x091d7cULL: return fde_sub_091d7c(a0, a1, a2);
        case 0x091d8cULL: return fde_sub_091d8c(a0, a1, a2);
        case 0x091d98ULL: return fde_sub_091d98(a0, a1, a2);
        case 0x091da8ULL: return fde_sub_091da8(a0, a1, a2);
        case 0x091db8ULL: return fde_sub_091db8(a0, a1, a2);
        case 0x091dc0ULL: return fde_sub_091dc0(a0, a1, a2);
        case 0x091dd0ULL: return fde_sub_091dd0(a0, a1, a2);
        case 0x091de0ULL: return fde_sub_091de0(a0, a1, a2);
        case 0x091df8ULL: return fde_sub_091df8(a0, a1, a2);
        case 0x091e08ULL: return fde_sub_091e08(a0, a1, a2);
        case 0x091e20ULL: return fde_sub_091e20(a0, a1, a2);
        case 0x091e2cULL: return fde_sub_091e2c(a0, a1, a2);
        case 0x091e38ULL: return fde_sub_091e38(a0, a1, a2);
        case 0x091e4cULL: return fde_sub_091e4c(a0, a1, a2);
        case 0x091e54ULL: return fde_sub_091e54(a0, a1, a2);
        case 0x091e60ULL: return fde_sub_091e60(a0, a1, a2);
        case 0x091e74ULL: return fde_sub_091e74(a0, a1, a2);
        case 0x091e80ULL: return fde_sub_091e80(a0, a1, a2);
        case 0x091e94ULL: return fde_sub_091e94(a0, a1, a2);
        case 0x091ea0ULL: return fde_sub_091ea0(a0, a1, a2);
        case 0x091eacULL: return fde_sub_091eac(a0, a1, a2);
        case 0x091eb8ULL: return fde_sub_091eb8(a0, a1, a2);
        case 0x091ec4ULL: return fde_sub_091ec4(a0, a1, a2);
        case 0x091ed8ULL: return fde_sub_091ed8(a0, a1, a2);
        case 0x091ee0ULL: return fde_sub_091ee0(a0, a1, a2);
        case 0x091eecULL: return fde_sub_091eec(a0, a1, a2);
        case 0x091ef8ULL: return fde_sub_091ef8(a0, a1, a2);
        case 0x091f00ULL: return fde_sub_091f00(a0, a1, a2);
        case 0x091f0cULL: return fde_sub_091f0c(a0, a1, a2);
        case 0x091f14ULL: return fde_sub_091f14(a0, a1, a2);
        case 0x091f1cULL: return fde_sub_091f1c(a0, a1, a2);
        case 0x091f28ULL: return fde_sub_091f28(a0, a1, a2);
        case 0x091f34ULL: return fde_sub_091f34(a0, a1, a2);
        case 0x091f3cULL: return fde_sub_091f3c(a0, a1, a2);
        case 0x091f44ULL: return fde_sub_091f44(a0, a1, a2);
        case 0x091f50ULL: return fde_sub_091f50(a0, a1, a2);
        case 0x091f58ULL: return fde_sub_091f58(a0, a1, a2);
        case 0x091f64ULL: return fde_sub_091f64(a0, a1, a2);
        case 0x091f6cULL: return fde_sub_091f6c(a0, a1, a2);
        case 0x091f78ULL: return fde_sub_091f78(a0, a1, a2);
        case 0x091f80ULL: return fde_sub_091f80(a0, a1, a2);
        case 0x091f94ULL: return fde_sub_091f94(a0, a1, a2);
        case 0x091fa8ULL: return fde_sub_091fa8(a0, a1, a2);
        case 0x091fbcULL: return fde_sub_091fbc(a0, a1, a2);
        case 0x091fc8ULL: return fde_sub_091fc8(a0, a1, a2);
        case 0x091fd4ULL: return fde_sub_091fd4(a0, a1, a2);
        case 0x091fe0ULL: return fde_sub_091fe0(a0, a1, a2);
        case 0x091fe8ULL: return fde_sub_091fe8(a0, a1, a2);
        case 0x091ff4ULL: return fde_sub_091ff4(a0, a1, a2);
        case 0x092000ULL: return fde_sub_092000(a0, a1, a2);
        case 0x09200cULL: return fde_sub_09200c(a0, a1, a2);
        case 0x092018ULL: return fde_sub_092018(a0, a1, a2);
        case 0x092020ULL: return fde_sub_092020(a0, a1, a2);
        case 0x092028ULL: return fde_sub_092028(a0, a1, a2);
        case 0x09203cULL: return fde_sub_09203c(a0, a1, a2);
        case 0x092044ULL: return fde_sub_092044(a0, a1, a2);
        case 0x09204cULL: return fde_sub_09204c(a0, a1, a2);
        case 0x092060ULL: return fde_sub_092060(a0, a1, a2);
        case 0x09206cULL: return fde_sub_09206c(a0, a1, a2);
        case 0x092078ULL: return fde_sub_092078(a0, a1, a2);
        case 0x09209cULL: return fde_sub_09209c(a0, a1, a2);
        case 0x0920a8ULL: return fde_sub_0920a8(a0, a1, a2);
        case 0x0920b4ULL: return fde_sub_0920b4(a0, a1, a2);
        case 0x0920bcULL: return fde_sub_0920bc(a0, a1, a2);
        case 0x0920c8ULL: return fde_sub_0920c8(a0, a1, a2);
        case 0x0920d4ULL: return fde_sub_0920d4(a0, a1, a2);
        case 0x0920dcULL: return fde_sub_0920dc(a0, a1, a2);
        case 0x0920e4ULL: return fde_sub_0920e4(a0, a1, a2);
        case 0x0920ecULL: return fde_sub_0920ec(a0, a1, a2);
        case 0x0920f4ULL: return fde_sub_0920f4(a0, a1, a2);
        case 0x0920fcULL: return fde_sub_0920fc(a0, a1, a2);
        case 0x092110ULL: return fde_sub_092110(a0, a1, a2);
        case 0x092124ULL: return fde_sub_092124(a0, a1, a2);
        case 0x092130ULL: return fde_sub_092130(a0, a1, a2);
        case 0x092144ULL: return fde_sub_092144(a0, a1, a2);
        case 0x092150ULL: return fde_sub_092150(a0, a1, a2);
        case 0x09215cULL: return fde_sub_09215c(a0, a1, a2);
        case 0x092168ULL: return fde_sub_092168(a0, a1, a2);
        case 0x092174ULL: return fde_sub_092174(a0, a1, a2);
        case 0x092180ULL: return fde_sub_092180(a0, a1, a2);
        case 0x09219cULL: return fde_sub_09219c(a0, a1, a2);
        case 0x0921a8ULL: return fde_sub_0921a8(a0, a1, a2);
        case 0x0921bcULL: return fde_sub_0921bc(a0, a1, a2);
        case 0x0921d0ULL: return fde_sub_0921d0(a0, a1, a2);
        case 0x0921dcULL: return fde_sub_0921dc(a0, a1, a2);
        case 0x0921e4ULL: return fde_sub_0921e4(a0, a1, a2);
        case 0x0921f0ULL: return fde_sub_0921f0(a0, a1, a2);
        case 0x0921fcULL: return fde_sub_0921fc(a0, a1, a2);
        case 0x092210ULL: return fde_sub_092210(a0, a1, a2);
        case 0x092218ULL: return fde_sub_092218(a0, a1, a2);
        case 0x092224ULL: return fde_sub_092224(a0, a1, a2);
        case 0x092230ULL: return fde_sub_092230(a0, a1, a2);
        case 0x092244ULL: return fde_sub_092244(a0, a1, a2);
        case 0x09224cULL: return fde_sub_09224c(a0, a1, a2);
        case 0x092254ULL: return fde_sub_092254(a0, a1, a2);
        case 0x092260ULL: return fde_sub_092260(a0, a1, a2);
        case 0x092268ULL: return fde_sub_092268(a0, a1, a2);
        case 0x092270ULL: return fde_sub_092270(a0, a1, a2);
        case 0x09227cULL: return fde_sub_09227c(a0, a1, a2);
        case 0x092288ULL: return fde_sub_092288(a0, a1, a2);
        case 0x092294ULL: return fde_sub_092294(a0, a1, a2);
        case 0x09229cULL: return fde_sub_09229c(a0, a1, a2);
        case 0x0922a4ULL: return fde_sub_0922a4(a0, a1, a2);
        case 0x0922b0ULL: return fde_sub_0922b0(a0, a1, a2);
        case 0x0922bcULL: return fde_sub_0922bc(a0, a1, a2);
        case 0x0922d0ULL: return fde_sub_0922d0(a0, a1, a2);
        case 0x0922ecULL: return fde_sub_0922ec(a0, a1, a2);
        case 0x092300ULL: return fde_sub_092300(a0, a1, a2);
        case 0x09230cULL: return fde_sub_09230c(a0, a1, a2);
        case 0x092314ULL: return fde_sub_092314(a0, a1, a2);
        case 0x092328ULL: return fde_sub_092328(a0, a1, a2);
        case 0x092330ULL: return fde_sub_092330(a0, a1, a2);
        case 0x09233cULL: return fde_sub_09233c(a0, a1, a2);
        case 0x092348ULL: return fde_sub_092348(a0, a1, a2);
        case 0x092354ULL: return fde_sub_092354(a0, a1, a2);
        case 0x092360ULL: return fde_sub_092360(a0, a1, a2);
        case 0x09236cULL: return fde_sub_09236c(a0, a1, a2);
        case 0x092378ULL: return fde_sub_092378(a0, a1, a2);
        case 0x09238cULL: return fde_sub_09238c(a0, a1, a2);
        case 0x092398ULL: return fde_sub_092398(a0, a1, a2);
        case 0x0923a0ULL: return fde_sub_0923a0(a0, a1, a2);
        case 0x0923acULL: return fde_sub_0923ac(a0, a1, a2);
        case 0x0923c0ULL: return fde_sub_0923c0(a0, a1, a2);
        case 0x0923d4ULL: return fde_sub_0923d4(a0, a1, a2);
        case 0x0923e8ULL: return fde_sub_0923e8(a0, a1, a2);
        case 0x0923fcULL: return fde_sub_0923fc(a0, a1, a2);
        case 0x092410ULL: return fde_sub_092410(a0, a1, a2);
        case 0x092424ULL: return fde_sub_092424(a0, a1, a2);
        case 0x092438ULL: return fde_sub_092438(a0, a1, a2);
        case 0x09244cULL: return fde_sub_09244c(a0, a1, a2);
        case 0x092454ULL: return fde_sub_092454(a0, a1, a2);
        case 0x092460ULL: return fde_sub_092460(a0, a1, a2);
        case 0x092468ULL: return fde_sub_092468(a0, a1, a2);
        case 0x092474ULL: return fde_sub_092474(a0, a1, a2);
        case 0x092480ULL: return fde_sub_092480(a0, a1, a2);
        case 0x092488ULL: return fde_sub_092488(a0, a1, a2);
        case 0x092490ULL: return fde_sub_092490(a0, a1, a2);
        case 0x09249cULL: return fde_sub_09249c(a0, a1, a2);
        case 0x0924a8ULL: return fde_sub_0924a8(a0, a1, a2);
        case 0x0924b4ULL: return fde_sub_0924b4(a0, a1, a2);
        case 0x0924c0ULL: return fde_sub_0924c0(a0, a1, a2);
        case 0x0924ccULL: return fde_sub_0924cc(a0, a1, a2);
        case 0x0924d8ULL: return fde_sub_0924d8(a0, a1, a2);
        case 0x0924ecULL: return fde_sub_0924ec(a0, a1, a2);
        case 0x0924f8ULL: return fde_sub_0924f8(a0, a1, a2);
        case 0x092504ULL: return fde_sub_092504(a0, a1, a2);
        case 0x09250cULL: return fde_sub_09250c(a0, a1, a2);
        case 0x092518ULL: return fde_sub_092518(a0, a1, a2);
        case 0x09252cULL: return fde_sub_09252c(a0, a1, a2);
        case 0x092540ULL: return fde_sub_092540(a0, a1, a2);
        case 0x092554ULL: return fde_sub_092554(a0, a1, a2);
        case 0x092568ULL: return fde_sub_092568(a0, a1, a2);
        case 0x092570ULL: return fde_sub_092570(a0, a1, a2);
        case 0x092584ULL: return fde_sub_092584(a0, a1, a2);
        case 0x092590ULL: return fde_sub_092590(a0, a1, a2);
        case 0x09259cULL: return fde_sub_09259c(a0, a1, a2);
        case 0x0925a4ULL: return fde_sub_0925a4(a0, a1, a2);
        case 0x0925b0ULL: return fde_sub_0925b0(a0, a1, a2);
        case 0x0925b8ULL: return fde_sub_0925b8(a0, a1, a2);
        case 0x0925c0ULL: return fde_sub_0925c0(a0, a1, a2);
        case 0x0925ccULL: return fde_sub_0925cc(a0, a1, a2);
        case 0x0925d8ULL: return fde_sub_0925d8(a0, a1, a2);
        case 0x0925e4ULL: return fde_sub_0925e4(a0, a1, a2);
        case 0x0925f0ULL: return fde_sub_0925f0(a0, a1, a2);
        case 0x0925fcULL: return fde_sub_0925fc(a0, a1, a2);
        case 0x092608ULL: return fde_sub_092608(a0, a1, a2);
        case 0x092614ULL: return fde_sub_092614(a0, a1, a2);
        case 0x092620ULL: return fde_sub_092620(a0, a1, a2);
        case 0x09262cULL: return fde_sub_09262c(a0, a1, a2);
        case 0x092638ULL: return fde_sub_092638(a0, a1, a2);
        case 0x092640ULL: return fde_sub_092640(a0, a1, a2);
        case 0x09264cULL: return fde_sub_09264c(a0, a1, a2);
        case 0x092658ULL: return fde_sub_092658(a0, a1, a2);
        case 0x092664ULL: return fde_sub_092664(a0, a1, a2);
        case 0x09266cULL: return fde_sub_09266c(a0, a1, a2);
        case 0x092674ULL: return fde_sub_092674(a0, a1, a2);
        case 0x092688ULL: return fde_sub_092688(a0, a1, a2);
        case 0x092690ULL: return fde_sub_092690(a0, a1, a2);
        case 0x092698ULL: return fde_sub_092698(a0, a1, a2);
        case 0x0926a4ULL: return fde_sub_0926a4(a0, a1, a2);
        case 0x0926b8ULL: return fde_sub_0926b8(a0, a1, a2);
        case 0x0926c4ULL: return fde_sub_0926c4(a0, a1, a2);
        case 0x0926d0ULL: return fde_sub_0926d0(a0, a1, a2);
        case 0x0926d8ULL: return fde_sub_0926d8(a0, a1, a2);
        case 0x0926e0ULL: return fde_sub_0926e0(a0, a1, a2);
        case 0x0926ecULL: return fde_sub_0926ec(a0, a1, a2);
        case 0x0926f4ULL: return fde_sub_0926f4(a0, a1, a2);
        case 0x0926fcULL: return fde_sub_0926fc(a0, a1, a2);
        case 0x092704ULL: return fde_sub_092704(a0, a1, a2);
        case 0x092718ULL: return fde_sub_092718(a0, a1, a2);
        case 0x092720ULL: return fde_sub_092720(a0, a1, a2);
        case 0x092728ULL: return fde_sub_092728(a0, a1, a2);
        case 0x09273cULL: return fde_sub_09273c(a0, a1, a2);
        case 0x092750ULL: return fde_sub_092750(a0, a1, a2);
        case 0x092764ULL: return fde_sub_092764(a0, a1, a2);
        case 0x09276cULL: return fde_sub_09276c(a0, a1, a2);
        case 0x092780ULL: return fde_sub_092780(a0, a1, a2);
        case 0x09278cULL: return fde_sub_09278c(a0, a1, a2);
        case 0x0927a0ULL: return fde_sub_0927a0(a0, a1, a2);
        case 0x0927acULL: return fde_sub_0927ac(a0, a1, a2);
        case 0x0927b4ULL: return fde_sub_0927b4(a0, a1, a2);
        case 0x0927c0ULL: return fde_sub_0927c0(a0, a1, a2);
        case 0x0927c8ULL: return fde_sub_0927c8(a0, a1, a2);
        case 0x0927dcULL: return fde_sub_0927dc(a0, a1, a2);
        case 0x0927e8ULL: return fde_sub_0927e8(a0, a1, a2);
        case 0x0927f4ULL: return fde_sub_0927f4(a0, a1, a2);
        case 0x0927fcULL: return fde_sub_0927fc(a0, a1, a2);
        case 0x092804ULL: return fde_sub_092804(a0, a1, a2);
        case 0x09280cULL: return fde_sub_09280c(a0, a1, a2);
        case 0x092814ULL: return fde_sub_092814(a0, a1, a2);
        case 0x092828ULL: return fde_sub_092828(a0, a1, a2);
        case 0x092834ULL: return fde_sub_092834(a0, a1, a2);
        case 0x09283cULL: return fde_sub_09283c(a0, a1, a2);
        case 0x092844ULL: return fde_sub_092844(a0, a1, a2);
        case 0x092850ULL: return fde_sub_092850(a0, a1, a2);
        case 0x092864ULL: return fde_sub_092864(a0, a1, a2);
        case 0x092878ULL: return fde_sub_092878(a0, a1, a2);
        case 0x092884ULL: return fde_sub_092884(a0, a1, a2);
        case 0x092890ULL: return fde_sub_092890(a0, a1, a2);
        case 0x0928a4ULL: return fde_sub_0928a4(a0, a1, a2);
        case 0x0928b0ULL: return fde_sub_0928b0(a0, a1, a2);
        case 0x0928c4ULL: return fde_sub_0928c4(a0, a1, a2);
        case 0x0928ccULL: return fde_sub_0928cc(a0, a1, a2);
        case 0x0928d8ULL: return fde_sub_0928d8(a0, a1, a2);
        case 0x0928e4ULL: return fde_sub_0928e4(a0, a1, a2);
        case 0x0928f0ULL: return fde_sub_0928f0(a0, a1, a2);
        case 0x0928fcULL: return fde_sub_0928fc(a0, a1, a2);
        case 0x092908ULL: return fde_sub_092908(a0, a1, a2);
        case 0x092910ULL: return fde_sub_092910(a0, a1, a2);
        case 0x09291cULL: return fde_sub_09291c(a0, a1, a2);
        case 0x092928ULL: return fde_sub_092928(a0, a1, a2);
        case 0x092934ULL: return fde_sub_092934(a0, a1, a2);
        case 0x092940ULL: return fde_sub_092940(a0, a1, a2);
        case 0x09294cULL: return fde_sub_09294c(a0, a1, a2);
        case 0x092958ULL: return fde_sub_092958(a0, a1, a2);
        case 0x092964ULL: return fde_sub_092964(a0, a1, a2);
        case 0x09296cULL: return fde_sub_09296c(a0, a1, a2);
        case 0x092980ULL: return fde_sub_092980(a0, a1, a2);
        case 0x092988ULL: return fde_sub_092988(a0, a1, a2);
        case 0x09299cULL: return fde_sub_09299c(a0, a1, a2);
        case 0x0929b0ULL: return fde_sub_0929b0(a0, a1, a2);
        case 0x0929bcULL: return fde_sub_0929bc(a0, a1, a2);
        case 0x0929d0ULL: return fde_sub_0929d0(a0, a1, a2);
        case 0x0929dcULL: return fde_sub_0929dc(a0, a1, a2);
        case 0x0929e8ULL: return fde_sub_0929e8(a0, a1, a2);
        case 0x0929fcULL: return fde_sub_0929fc(a0, a1, a2);
        case 0x092a08ULL: return fde_sub_092a08(a0, a1, a2);
        case 0x092a14ULL: return fde_sub_092a14(a0, a1, a2);
        case 0x092a1cULL: return fde_sub_092a1c(a0, a1, a2);
        case 0x092a28ULL: return fde_sub_092a28(a0, a1, a2);
        case 0x092a30ULL: return fde_sub_092a30(a0, a1, a2);
        case 0x092a38ULL: return fde_sub_092a38(a0, a1, a2);
        case 0x092a40ULL: return fde_sub_092a40(a0, a1, a2);
        case 0x092a48ULL: return fde_sub_092a48(a0, a1, a2);
        case 0x092a5cULL: return fde_sub_092a5c(a0, a1, a2);
        case 0x092a70ULL: return fde_sub_092a70(a0, a1, a2);
        case 0x092a78ULL: return fde_sub_092a78(a0, a1, a2);
        case 0x092a8cULL: return fde_sub_092a8c(a0, a1, a2);
        case 0x092aa0ULL: return fde_sub_092aa0(a0, a1, a2);
        case 0x092abcULL: return fde_sub_092abc(a0, a1, a2);
        case 0x092ac4ULL: return fde_sub_092ac4(a0, a1, a2);
        case 0x092ae8ULL: return fde_sub_092ae8(a0, a1, a2);
        case 0x092af4ULL: return fde_sub_092af4(a0, a1, a2);
        case 0x092b00ULL: return fde_sub_092b00(a0, a1, a2);
        case 0x092b08ULL: return fde_sub_092b08(a0, a1, a2);
        case 0x092b1cULL: return fde_sub_092b1c(a0, a1, a2);
        case 0x092b28ULL: return fde_sub_092b28(a0, a1, a2);
        case 0x092b3cULL: return fde_sub_092b3c(a0, a1, a2);
        case 0x092b50ULL: return fde_sub_092b50(a0, a1, a2);
        case 0x092b64ULL: return fde_sub_092b64(a0, a1, a2);
        case 0x092b70ULL: return fde_sub_092b70(a0, a1, a2);
        case 0x092b7cULL: return fde_sub_092b7c(a0, a1, a2);
        case 0x092b88ULL: return fde_sub_092b88(a0, a1, a2);
        case 0x092b94ULL: return fde_sub_092b94(a0, a1, a2);
        case 0x092ba0ULL: return fde_sub_092ba0(a0, a1, a2);
        case 0x092bacULL: return fde_sub_092bac(a0, a1, a2);
        case 0x092bb8ULL: return fde_sub_092bb8(a0, a1, a2);
        case 0x092bc4ULL: return fde_sub_092bc4(a0, a1, a2);
        case 0x092bccULL: return fde_sub_092bcc(a0, a1, a2);
        case 0x092bd8ULL: return fde_sub_092bd8(a0, a1, a2);
        case 0x092be0ULL: return fde_sub_092be0(a0, a1, a2);
        case 0x092be8ULL: return fde_sub_092be8(a0, a1, a2);
        case 0x092bf4ULL: return fde_sub_092bf4(a0, a1, a2);
        case 0x092c00ULL: return fde_sub_092c00(a0, a1, a2);
        case 0x092c08ULL: return fde_sub_092c08(a0, a1, a2);
        case 0x092c14ULL: return fde_sub_092c14(a0, a1, a2);
        case 0x092c28ULL: return fde_sub_092c28(a0, a1, a2);
        case 0x092c3cULL: return fde_sub_092c3c(a0, a1, a2);
        case 0x092c48ULL: return fde_sub_092c48(a0, a1, a2);
        case 0x092c50ULL: return fde_sub_092c50(a0, a1, a2);
        case 0x092c5cULL: return fde_sub_092c5c(a0, a1, a2);
        case 0x092c64ULL: return fde_sub_092c64(a0, a1, a2);
        case 0x092c70ULL: return fde_sub_092c70(a0, a1, a2);
        case 0x092c78ULL: return fde_sub_092c78(a0, a1, a2);
        case 0x092c8cULL: return fde_sub_092c8c(a0, a1, a2);
        case 0x092c98ULL: return fde_sub_092c98(a0, a1, a2);
        case 0x092ca4ULL: return fde_sub_092ca4(a0, a1, a2);
        case 0x092cb0ULL: return fde_sub_092cb0(a0, a1, a2);
        case 0x092cbcULL: return fde_sub_092cbc(a0, a1, a2);
        case 0x092cd0ULL: return fde_sub_092cd0(a0, a1, a2);
        case 0x092cd8ULL: return fde_sub_092cd8(a0, a1, a2);
        case 0x092ce4ULL: return fde_sub_092ce4(a0, a1, a2);
        case 0x092cf0ULL: return fde_sub_092cf0(a0, a1, a2);
        case 0x092cfcULL: return fde_sub_092cfc(a0, a1, a2);
        case 0x092d08ULL: return fde_sub_092d08(a0, a1, a2);
        case 0x092d10ULL: return fde_sub_092d10(a0, a1, a2);
        case 0x092d1cULL: return fde_sub_092d1c(a0, a1, a2);
        case 0x092d28ULL: return fde_sub_092d28(a0, a1, a2);
        case 0x092d34ULL: return fde_sub_092d34(a0, a1, a2);
        case 0x092d40ULL: return fde_sub_092d40(a0, a1, a2);
        case 0x092d48ULL: return fde_sub_092d48(a0, a1, a2);
        case 0x092d54ULL: return fde_sub_092d54(a0, a1, a2);
        case 0x092d60ULL: return fde_sub_092d60(a0, a1, a2);
        case 0x092d68ULL: return fde_sub_092d68(a0, a1, a2);
        case 0x092d74ULL: return fde_sub_092d74(a0, a1, a2);
        case 0x092d88ULL: return fde_sub_092d88(a0, a1, a2);
        case 0x092d90ULL: return fde_sub_092d90(a0, a1, a2);
        case 0x092d98ULL: return fde_sub_092d98(a0, a1, a2);
        case 0x092da4ULL: return fde_sub_092da4(a0, a1, a2);
        case 0x092db8ULL: return fde_sub_092db8(a0, a1, a2);
        case 0x092dc0ULL: return fde_sub_092dc0(a0, a1, a2);
        case 0x092dc8ULL: return fde_sub_092dc8(a0, a1, a2);
        case 0x092dd4ULL: return fde_sub_092dd4(a0, a1, a2);
        case 0x092de0ULL: return fde_sub_092de0(a0, a1, a2);
        case 0x092decULL: return fde_sub_092dec(a0, a1, a2);
        case 0x092df8ULL: return fde_sub_092df8(a0, a1, a2);
        case 0x092e04ULL: return fde_sub_092e04(a0, a1, a2);
        case 0x092e10ULL: return fde_sub_092e10(a0, a1, a2);
        case 0x092e18ULL: return fde_sub_092e18(a0, a1, a2);
        case 0x092e20ULL: return fde_sub_092e20(a0, a1, a2);
        case 0x092e28ULL: return fde_sub_092e28(a0, a1, a2);
        case 0x092e30ULL: return fde_sub_092e30(a0, a1, a2);
        case 0x092e38ULL: return fde_sub_092e38(a0, a1, a2);
        case 0x092e40ULL: return fde_sub_092e40(a0, a1, a2);
        case 0x092e4cULL: return fde_sub_092e4c(a0, a1, a2);
        case 0x092e54ULL: return fde_sub_092e54(a0, a1, a2);
        case 0x092e5cULL: return fde_sub_092e5c(a0, a1, a2);
        case 0x092e68ULL: return fde_sub_092e68(a0, a1, a2);
        case 0x092e74ULL: return fde_sub_092e74(a0, a1, a2);
        case 0x092e7cULL: return fde_sub_092e7c(a0, a1, a2);
        case 0x092e88ULL: return fde_sub_092e88(a0, a1, a2);
        case 0x092e90ULL: return fde_sub_092e90(a0, a1, a2);
        case 0x092eb4ULL: return fde_sub_092eb4(a0, a1, a2);
        case 0x092ebcULL: return fde_sub_092ebc(a0, a1, a2);
        case 0x092ec8ULL: return fde_sub_092ec8(a0, a1, a2);
        case 0x092edcULL: return fde_sub_092edc(a0, a1, a2);
        case 0x092ee8ULL: return fde_sub_092ee8(a0, a1, a2);
        case 0x092ef0ULL: return fde_sub_092ef0(a0, a1, a2);
        case 0x092ef8ULL: return fde_sub_092ef8(a0, a1, a2);
        case 0x092f04ULL: return fde_sub_092f04(a0, a1, a2);
        case 0x092f10ULL: return fde_sub_092f10(a0, a1, a2);
        case 0x092f24ULL: return fde_sub_092f24(a0, a1, a2);
        case 0x092f30ULL: return fde_sub_092f30(a0, a1, a2);
        case 0x092f3cULL: return fde_sub_092f3c(a0, a1, a2);
        case 0x092f48ULL: return fde_sub_092f48(a0, a1, a2);
        case 0x092f54ULL: return fde_sub_092f54(a0, a1, a2);
        case 0x092f5cULL: return fde_sub_092f5c(a0, a1, a2);
        case 0x092f70ULL: return fde_sub_092f70(a0, a1, a2);
        case 0x092f84ULL: return fde_sub_092f84(a0, a1, a2);
        case 0x092f98ULL: return fde_sub_092f98(a0, a1, a2);
        case 0x092fa4ULL: return fde_sub_092fa4(a0, a1, a2);
        case 0x092fb8ULL: return fde_sub_092fb8(a0, a1, a2);
        case 0x092fc4ULL: return fde_sub_092fc4(a0, a1, a2);
        case 0x092fd0ULL: return fde_sub_092fd0(a0, a1, a2);
        case 0x092fdcULL: return fde_sub_092fdc(a0, a1, a2);
        case 0x092fe8ULL: return fde_sub_092fe8(a0, a1, a2);
        case 0x092ff4ULL: return fde_sub_092ff4(a0, a1, a2);
        case 0x093000ULL: return fde_sub_093000(a0, a1, a2);
        case 0x093008ULL: return fde_sub_093008(a0, a1, a2);
        case 0x093014ULL: return fde_sub_093014(a0, a1, a2);
        case 0x09301cULL: return fde_sub_09301c(a0, a1, a2);
        case 0x093028ULL: return fde_sub_093028(a0, a1, a2);
        case 0x093034ULL: return fde_sub_093034(a0, a1, a2);
        case 0x09303cULL: return fde_sub_09303c(a0, a1, a2);
        case 0x093044ULL: return fde_sub_093044(a0, a1, a2);
        case 0x09304cULL: return fde_sub_09304c(a0, a1, a2);
        case 0x093058ULL: return fde_sub_093058(a0, a1, a2);
        case 0x093064ULL: return fde_sub_093064(a0, a1, a2);
        case 0x093078ULL: return fde_sub_093078(a0, a1, a2);
        case 0x093080ULL: return fde_sub_093080(a0, a1, a2);
        case 0x093088ULL: return fde_sub_093088(a0, a1, a2);
        case 0x093094ULL: return fde_sub_093094(a0, a1, a2);
        case 0x09309cULL: return fde_sub_09309c(a0, a1, a2);
        case 0x0930a8ULL: return fde_sub_0930a8(a0, a1, a2);
        case 0x0930b4ULL: return fde_sub_0930b4(a0, a1, a2);
        case 0x0930c8ULL: return fde_sub_0930c8(a0, a1, a2);
        case 0x0930d4ULL: return fde_sub_0930d4(a0, a1, a2);
        case 0x0930dcULL: return fde_sub_0930dc(a0, a1, a2);
        case 0x0930e8ULL: return fde_sub_0930e8(a0, a1, a2);
        case 0x0930f4ULL: return fde_sub_0930f4(a0, a1, a2);
        case 0x093100ULL: return fde_sub_093100(a0, a1, a2);
        case 0x09310cULL: return fde_sub_09310c(a0, a1, a2);
        case 0x093118ULL: return fde_sub_093118(a0, a1, a2);
        case 0x093134ULL: return fde_sub_093134(a0, a1, a2);
        case 0x093148ULL: return fde_sub_093148(a0, a1, a2);
        default: return 0ULL;
    }
}

uint64_t DispatchAnimaXShard1(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept;
uint64_t DispatchAnimaXShard2(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept;
uint64_t DispatchAnimaXShard3(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept;
uint64_t DispatchAnimaXShard4(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept;

uint64_t ExecuteAnimaXFdeByAddress(uint64_t fde_pc_begin, uint64_t arg0, uint64_t arg1, uint64_t arg2) noexcept {
    if (fde_pc_begin >= 0x04403cULL && fde_pc_begin <= 0x057a1cULL) {
        return DispatchAnimaXShard1(fde_pc_begin, arg0, arg1, arg2);
    }
    if (fde_pc_begin >= 0x057a34ULL && fde_pc_begin <= 0x073f18ULL) {
        return DispatchAnimaXShard2(fde_pc_begin, arg0, arg1, arg2);
    }
    if (fde_pc_begin >= 0x073f28ULL && fde_pc_begin <= 0x08bb68ULL) {
        return DispatchAnimaXShard3(fde_pc_begin, arg0, arg1, arg2);
    }
    if (fde_pc_begin >= 0x08bb6cULL && fde_pc_begin <= 0x090564ULL) {
        return DispatchAnimaXShard4(fde_pc_begin, arg0, arg1, arg2);
    }
    if (fde_pc_begin >= 0x090578ULL && fde_pc_begin <= 0x093148ULL) {
        return DispatchAnimaXShard5(fde_pc_begin, arg0, arg1, arg2);
    }
    return 0ULL;
}

} // namespace animax
} // namespace lynx
