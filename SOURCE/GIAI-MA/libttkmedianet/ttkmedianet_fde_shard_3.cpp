// ============================================================================
// File: ttkmedianet_fde_shard_3.cpp
// Target 106 / 169: libttkmedianet.so (632,064 bytes)
// EN: Clean-room C++17 AArch64 FDE Shard 3/5 covering FDEs [658..986]
//     (PC range 0x041adc .. 0x056b00).
// VI: Phân mảnh FDE AArch64 C++17 3/5 bao phủ các FDE [658..986]
//     (Dải địa chỉ PC 0x041adc .. 0x056b00).
// ============================================================================
#include "ttkmedianet_core.h"

namespace TTKMediaNet {

// FDE #0658 | PC: 0x041adc..0x041b18 (60 B) | Symbol: sub_041adc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldp x8, x9, [x1]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldp x8, x9, [x1]]
uint64_t fde_sub_041adc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041ADCULL;
}

// FDE #0659 | PC: 0x041b18..0x041b88 (112 B) | Symbol: sub_041b18
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_041b18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041B18ULL;
}

// FDE #0660 | PC: 0x041b88..0x041d2c (420 B) | Symbol: sub_041b88
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_041b88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x01A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041B88ULL;
}

// FDE #0661 | PC: 0x041d2c..0x041db8 (140 B) | Symbol: sub_041d2c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_041d2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041D2CULL;
}

// FDE #0662 | PC: 0x041db8..0x041dd0 (24 B) | Symbol: sub_041db8
// EN: AArch64 prologue [ldr x3, [x2, #0x30]; cbz x3, #0x41dcc; ldr x1, [x2, #0x10]; mov x0, x2] | VI: Khởi đầu hàm AArch64 [ldr x3, [x2, #0x30]; cbz x3, #0x41dcc; ldr x1, [x2, #0x10]; mov x0, x2]
uint64_t fde_sub_041db8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000083ULL) << 32) | 0xF9401843ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041DB8ULL;
}

// FDE #0663 | PC: 0x041dd0..0x041df0 (32 B) | Symbol: sub_041dd0
// EN: AArch64 prologue [ldr x5, [x4, #0x38]; cbz x5, #0x41dec; ldr x8, [x4]; ldr x3, [x4, #0x10]] | VI: Khởi đầu hàm AArch64 [ldr x5, [x4, #0x38]; cbz x5, #0x41dec; ldr x8, [x4]; ldr x3, [x4, #0x10]]
uint64_t fde_sub_041dd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB40000C5ULL) << 32) | 0xF9401C85ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041DD0ULL;
}

// FDE #0664 | PC: 0x041df0..0x041eb8 (200 B) | Symbol: sub_041df0
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_041df0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041DF0ULL;
}

// FDE #0665 | PC: 0x041eb8..0x041f00 (72 B) | Symbol: sub_041eb8
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0, #0x40]; orr x9, x8, #0x1000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0, #0x40]; orr x9, x8, #0x1000]
uint64_t fde_sub_041eb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041EB8ULL;
}

// FDE #0666 | PC: 0x041f00..0x041f84 (132 B) | Symbol: sub_041f00
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x1, [x0, #0x100]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x1, [x0, #0x100]]
uint64_t fde_sub_041f00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041F00ULL;
}

// FDE #0667 | PC: 0x041f84..0x042074 (240 B) | Symbol: sub_041f84
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_041f84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041F84ULL;
}

// FDE #0668 | PC: 0x042074..0x04213c (200 B) | Symbol: sub_042074
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_042074(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042074ULL;
}

// FDE #0669 | PC: 0x04213c..0x042220 (228 B) | Symbol: sub_04213c
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04213c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04213CULL;
}

// FDE #0670 | PC: 0x042220..0x0424dc (700 B) | Symbol: sub_042220
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_042220(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x02BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042220ULL;
}

// FDE #0671 | PC: 0x0424dc..0x042544 (104 B) | Symbol: sub_0424dc
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0424dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0424DCULL;
}

// FDE #0672 | PC: 0x042544..0x0425ec (168 B) | Symbol: sub_042544
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_042544(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042544ULL;
}

// FDE #0673 | PC: 0x0425ec..0x0426a8 (188 B) | Symbol: sub_0425ec
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0425ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0425ECULL;
}

// FDE #0674 | PC: 0x0426a8..0x0426f8 (80 B) | Symbol: sub_0426a8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0426a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0426A8ULL;
}

// FDE #0675 | PC: 0x0426f8..0x042788 (144 B) | Symbol: sub_0426f8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x1, #0x42720] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x1, #0x42720]
uint64_t fde_sub_0426f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0426F8ULL;
}

// FDE #0676 | PC: 0x042788..0x0428f0 (360 B) | Symbol: sub_042788
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_042788(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x0168ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042788ULL;
}

// FDE #0677 | PC: 0x0428f0..0x042cd4 (996 B) | Symbol: sub_0428f0
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_0428f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9026FFCULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x03E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0428F0ULL;
}

// FDE #0678 | PC: 0x042cd4..0x042e60 (396 B) | Symbol: sub_042cd4
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_042cd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x018CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042CD4ULL;
}

// FDE #0679 | PC: 0x042e60..0x042f94 (308 B) | Symbol: sub_042e60
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_042e60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0134ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042E60ULL;
}

// FDE #0680 | PC: 0x042f94..0x0430e0 (332 B) | Symbol: sub_042f94
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_042f94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x014CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042F94ULL;
}

// FDE #0681 | PC: 0x0430e0..0x043264 (388 B) | Symbol: sub_0430e0
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0430e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0184ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0430E0ULL;
}

// FDE #0682 | PC: 0x043264..0x043374 (272 B) | Symbol: sub_043264
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_043264(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0110ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043264ULL;
}

// FDE #0683 | PC: 0x043374..0x0434e0 (364 B) | Symbol: sub_043374
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_043374(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x016CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043374ULL;
}

// FDE #0684 | PC: 0x0434e0..0x0435f4 (276 B) | Symbol: sub_0434e0
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0434e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0434E0ULL;
}

// FDE #0685 | PC: 0x0435f4..0x0437d8 (484 B) | Symbol: sub_0435f4
// EN: AArch64 prologue [str x28, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x28, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0435f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FFCULL;
    const uint64_t kPcRange = 0x01E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0435F4ULL;
}

// FDE #0686 | PC: 0x0437d8..0x0438dc (260 B) | Symbol: sub_0437d8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_0437d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0437D8ULL;
}

// FDE #0687 | PC: 0x0438dc..0x0439dc (256 B) | Symbol: sub_0438dc
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0438dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0438DCULL;
}

// FDE #0688 | PC: 0x0439dc..0x043a04 (40 B) | Symbol: sub_0439dc
// EN: AArch64 prologue [ldr x8, [x0]; ldr w8, [x8, #0xac8]; cbnz w8, #0x439fc; ldr w8, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr w8, [x8, #0xac8]; cbnz w8, #0x439fc; ldr w8, [x0, #0x10]]
uint64_t fde_sub_0439dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB94AC908ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0439DCULL;
}

// FDE #0689 | PC: 0x043a04..0x043c24 (544 B) | Symbol: sub_043a04
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_043a04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0220ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043A04ULL;
}

// FDE #0690 | PC: 0x043c24..0x043d28 (260 B) | Symbol: sub_043c24
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0xb8]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0xb8]]
uint64_t fde_sub_043c24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043C24ULL;
}

// FDE #0691 | PC: 0x043d28..0x043d48 (32 B) | Symbol: sub_043d28
// EN: AArch64 prologue [ldr x9, [x0]; mov x8, x0; cbz x9, #0x43d40; ldr x0, [x9, #0x110]] | VI: Khởi đầu hàm AArch64 [ldr x9, [x0]; mov x8, x0; cbz x9, #0x43d40; ldr x0, [x9, #0x110]]
uint64_t fde_sub_043d28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003E8ULL) << 32) | 0xF9400009ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043D28ULL;
}

// FDE #0692 | PC: 0x043d48..0x043e9c (340 B) | Symbol: sub_043d48
// EN: AArch64 prologue [ldr x10, [x0]; cbz x10, #0x43e98; add x8, x10, #0x1c8; ldr q0, [x8]] | VI: Khởi đầu hàm AArch64 [ldr x10, [x0]; cbz x10, #0x43e98; add x8, x10, #0x1c8; ldr q0, [x8]]
uint64_t fde_sub_043d48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000A6AULL) << 32) | 0xF940000AULL;
    const uint64_t kPcRange = 0x0154ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043D48ULL;
}

// FDE #0693 | PC: 0x043e9c..0x043ebc (32 B) | Symbol: sub_043e9c
// EN: AArch64 prologue [cbz x2, #0x43eb8; ldr x8, [x2, #0x30]; cmp x8, #0x10; b.ne #0x43eb8] | VI: Khởi đầu hàm AArch64 [cbz x2, #0x43eb8; ldr x8, [x2, #0x30]; cmp x8, #0x10; b.ne #0x43eb8]
uint64_t fde_sub_043e9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401848ULL) << 32) | 0xB40000E2ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043E9CULL;
}

// FDE #0694 | PC: 0x043ebc..0x043f3c (128 B) | Symbol: sub_043ebc
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0xb0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0xb0]]
uint64_t fde_sub_043ebc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043EBCULL;
}

// FDE #0695 | PC: 0x043f3c..0x04400c (208 B) | Symbol: sub_043f3c
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_043f3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043F3CULL;
}

// FDE #0696 | PC: 0x04400c..0x0440ac (160 B) | Symbol: sub_04400c
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04400c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04400CULL;
}

// FDE #0697 | PC: 0x0440ac..0x044138 (140 B) | Symbol: sub_0440ac
// EN: AArch64 prologue [sub sp, sp, #0x1b0; str x28, [sp, #0x180]; stp x20, x19, [sp, #0x190]; stp x29, x30, [sp, #0x1a0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1b0; str x28, [sp, #0x180]; stp x20, x19, [sp, #0x190]; stp x29, x30, [sp, #0x1a0]]
uint64_t fde_sub_0440ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900C3FCULL) << 32) | 0xD106C3FFULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0440ACULL;
}

// FDE #0698 | PC: 0x044138..0x04429c (356 B) | Symbol: sub_044138
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; movi v0.2d, #0000000000000000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; movi v0.2d, #0000000000000000]
uint64_t fde_sub_044138(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0164ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044138ULL;
}

// FDE #0699 | PC: 0x04429c..0x0442a4 (8 B) | Symbol: sub_04429c
// EN: AArch64 prologue [ldr x0, [x0]; b #0x41eb8] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0]; b #0x41eb8]
uint64_t fde_sub_04429c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFF706ULL) << 32) | 0xF9400000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04429CULL;
}

// FDE #0700 | PC: 0x0442a4..0x044348 (164 B) | Symbol: sub_0442a4
// EN: AArch64 prologue [sub sp, sp, #0x110; stp x28, x19, [sp, #0xf0]; stp x29, x30, [sp, #0x100]; add x29, sp, #0x100] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; stp x28, x19, [sp, #0xf0]; stp x29, x30, [sp, #0x100]; add x29, sp, #0x100]
uint64_t fde_sub_0442a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90F4FFCULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0442A4ULL;
}

// FDE #0701 | PC: 0x044348..0x044710 (968 B) | Symbol: sub_044348
// EN: AArch64 prologue [sub sp, sp, #0x80; str x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]; stp x20, x19, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]; stp x20, x19, [sp, #0x60]]
uint64_t fde_sub_044348(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F7ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x03C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044348ULL;
}

// FDE #0702 | PC: 0x044710..0x044c30 (1312 B) | Symbol: sub_044710
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_044710(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9035FF8ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0520ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044710ULL;
}

// FDE #0703 | PC: 0x044c30..0x044cc4 (148 B) | Symbol: sub_044c30
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_044c30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044C30ULL;
}

// FDE #0704 | PC: 0x044cc4..0x044ce0 (28 B) | Symbol: sub_044cc4
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x0, [x0]; bl #0x42544] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x0, [x0]; bl #0x42544]
uint64_t fde_sub_044cc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044CC4ULL;
}

// FDE #0705 | PC: 0x044ce0..0x044da4 (196 B) | Symbol: sub_044ce0
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0x1c]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0x1c]]
uint64_t fde_sub_044ce0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044CE0ULL;
}

// FDE #0706 | PC: 0x044da4..0x044f1c (376 B) | Symbol: sub_044da4
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_044da4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044DA4ULL;
}

// FDE #0707 | PC: 0x044f1c..0x045038 (284 B) | Symbol: sub_044f1c
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0x70]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0x70]]
uint64_t fde_sub_044f1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044F1CULL;
}

// FDE #0708 | PC: 0x045038..0x045080 (72 B) | Symbol: sub_045038
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0, #0x80]; add x9, x0, #0x78] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0, #0x80]; add x9, x0, #0x78]
uint64_t fde_sub_045038(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045038ULL;
}

// FDE #0709 | PC: 0x045080..0x045108 (136 B) | Symbol: sub_045080
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x18]]
uint64_t fde_sub_045080(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045080ULL;
}

// FDE #0710 | PC: 0x045108..0x04516c (100 B) | Symbol: sub_045108
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0x70]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0x70]]
uint64_t fde_sub_045108(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045108ULL;
}

// FDE #0711 | PC: 0x04516c..0x0451b0 (68 B) | Symbol: sub_04516c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0xc0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0xc0]]
uint64_t fde_sub_04516c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04516CULL;
}

// FDE #0712 | PC: 0x0451b0..0x0451f4 (68 B) | Symbol: sub_0451b0
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0xc8]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0xc8]]
uint64_t fde_sub_0451b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0451B0ULL;
}

// FDE #0713 | PC: 0x0451f4..0x045238 (68 B) | Symbol: sub_0451f4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0xf8]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0xf8]]
uint64_t fde_sub_0451f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0451F4ULL;
}

// FDE #0714 | PC: 0x045238..0x04527c (68 B) | Symbol: sub_045238
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0xd0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0xd0]]
uint64_t fde_sub_045238(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045238ULL;
}

// FDE #0715 | PC: 0x04527c..0x045294 (24 B) | Symbol: sub_04527c
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; ldr x3, [x8, #0x20]; cbz x3, #0x45290; ldr x2, [x0, #8]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; ldr x3, [x8, #0x20]; cbz x3, #0x45290; ldr x2, [x0, #8]]
uint64_t fde_sub_04527c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401103ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04527CULL;
}

// FDE #0716 | PC: 0x045294..0x0452f4 (96 B) | Symbol: sub_045294
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #8]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #8]]
uint64_t fde_sub_045294(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045294ULL;
}

// FDE #0717 | PC: 0x0452f4..0x0454fc (520 B) | Symbol: sub_0452f4
// EN: AArch64 prologue [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0452f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF9ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0208ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0452F4ULL;
}

// FDE #0718 | PC: 0x0454fc..0x0457bc (704 B) | Symbol: sub_0454fc
// EN: AArch64 prologue [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0454fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF9ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x02C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0454FCULL;
}

// FDE #0719 | PC: 0x0457bc..0x045898 (220 B) | Symbol: sub_0457bc
// EN: AArch64 prologue [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_0457bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF5ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0457BCULL;
}

// FDE #0720 | PC: 0x045898..0x04595c (196 B) | Symbol: sub_045898
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_045898(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045898ULL;
}

// FDE #0721 | PC: 0x04595c..0x045a90 (308 B) | Symbol: sub_04595c
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_04595c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x0134ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04595CULL;
}

// FDE #0722 | PC: 0x045a90..0x045ad8 (72 B) | Symbol: sub_045a90
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; add x8, x1, x1, lsl #2] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; add x8, x1, x1, lsl #2]
uint64_t fde_sub_045a90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045A90ULL;
}

// FDE #0723 | PC: 0x045ad8..0x045b6c (148 B) | Symbol: sub_045ad8
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_045ad8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045AD8ULL;
}

// FDE #0724 | PC: 0x045b6c..0x045c0c (160 B) | Symbol: sub_045b6c
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_045b6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045B6CULL;
}

// FDE #0725 | PC: 0x045c0c..0x045c18 (12 B) | Symbol: sub_045c0c
// EN: AArch64 prologue [stp xzr, xzr, [x0]; str xzr, [x0, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x0]; str xzr, [x0, #0x10]; ret]
uint64_t fde_sub_045c0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900081FULL) << 32) | 0xA9007C1FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045C0CULL;
}

// FDE #0726 | PC: 0x045c18..0x046728 (2832 B) | Symbol: sub_045c18
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub x8, x1, #3] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub x8, x1, #3]
uint64_t fde_sub_045c18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0B10ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045C18ULL;
}

// FDE #0727 | PC: 0x046728..0x0469c4 (668 B) | Symbol: sub_046728
// EN: AArch64 prologue [sub sp, sp, #0xe0; stp x24, x23, [sp, #0xa0]; stp x22, x21, [sp, #0xb0]; stp x20, x19, [sp, #0xc0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xe0; stp x24, x23, [sp, #0xa0]; stp x22, x21, [sp, #0xb0]; stp x20, x19, [sp, #0xc0]]
uint64_t fde_sub_046728(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90A5FF8ULL) << 32) | 0xD10383FFULL;
    const uint64_t kPcRange = 0x029CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046728ULL;
}

// FDE #0728 | PC: 0x0469c4..0x046ad4 (272 B) | Symbol: sub_0469c4
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x20, #0x7d000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x20, #0x7d000]
uint64_t fde_sub_0469c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0110ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0469C4ULL;
}

// FDE #0729 | PC: 0x046ad4..0x046b14 (64 B) | Symbol: sub_046ad4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x3] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x3]
uint64_t fde_sub_046ad4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046AD4ULL;
}

// FDE #0730 | PC: 0x046b14..0x046b58 (68 B) | Symbol: sub_046b14
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x3] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x3]
uint64_t fde_sub_046b14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046B14ULL;
}

// FDE #0731 | PC: 0x046b58..0x046c58 (256 B) | Symbol: sub_046b58
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_046b58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046B58ULL;
}

// FDE #0732 | PC: 0x046c58..0x046cb0 (88 B) | Symbol: sub_046c58
// EN: AArch64 prologue [cbz x0, #0x46cac; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x46cac; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10]
uint64_t fde_sub_046c58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0xB40002A0ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046C58ULL;
}

// FDE #0733 | PC: 0x046cb0..0x046cb8 (8 B) | Symbol: sub_046cb0
// EN: AArch64 prologue [ldr x0, [x0]; b #0x48694] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0]; b #0x48694]
uint64_t fde_sub_046cb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000678ULL) << 32) | 0xF9400000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046CB0ULL;
}

// FDE #0734 | PC: 0x046cb8..0x046d50 (152 B) | Symbol: sub_046cb8
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_046cb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046CB8ULL;
}

// FDE #0735 | PC: 0x046d50..0x046d58 (8 B) | Symbol: sub_046d50
// EN: AArch64 prologue [ldr x0, [x0]; b #0x486b8] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0]; b #0x486b8]
uint64_t fde_sub_046d50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000659ULL) << 32) | 0xF9400000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046D50ULL;
}

// FDE #0736 | PC: 0x046d58..0x046d60 (8 B) | Symbol: sub_046d58
// EN: AArch64 prologue [ldr x0, [x0, #8]; b #0x477f0] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #8]; b #0x477f0]
uint64_t fde_sub_046d58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140002A5ULL) << 32) | 0xF9400400ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046D58ULL;
}

// FDE #0737 | PC: 0x046d60..0x046f28 (456 B) | Symbol: sub_046d60
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_046d60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x01C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046D60ULL;
}

// FDE #0738 | PC: 0x046f28..0x04701c (244 B) | Symbol: sub_046f28
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_046f28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046F28ULL;
}

// FDE #0739 | PC: 0x04701c..0x047020 (4 B) | Symbol: sub_04701c
// EN: AArch64 prologue [b #0x486c4] | VI: Khởi đầu hàm AArch64 [b #0x486c4]
uint64_t fde_sub_04701c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140005C5ULL) << 32) | 0x140005AAULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04701CULL;
}

// FDE #0740 | PC: 0x047020..0x047024 (4 B) | Symbol: sub_047020
// EN: AArch64 prologue [b #0x48734] | VI: Khởi đầu hàm AArch64 [b #0x48734]
uint64_t fde_sub_047020(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140005E9ULL) << 32) | 0x140005C5ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047020ULL;
}

// FDE #0741 | PC: 0x047024..0x047028 (4 B) | Symbol: sub_047024
// EN: AArch64 prologue [b #0x487c8] | VI: Khởi đầu hàm AArch64 [b #0x487c8]
uint64_t fde_sub_047024(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140005F6ULL) << 32) | 0x140005E9ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047024ULL;
}

// FDE #0742 | PC: 0x047028..0x04702c (4 B) | Symbol: sub_047028
// EN: AArch64 prologue [b #0x48800] | VI: Khởi đầu hàm AArch64 [b #0x48800]
uint64_t fde_sub_047028(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81C0FF7ULL) << 32) | 0x140005F6ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047028ULL;
}

// FDE #0743 | PC: 0x04702c..0x0470bc (144 B) | Symbol: sub_04702c
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_04702c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04702CULL;
}

// FDE #0744 | PC: 0x0470bc..0x0472ac (496 B) | Symbol: sub_0470bc
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_0470bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9016FFCULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0470BCULL;
}

// FDE #0745 | PC: 0x0472ac..0x047318 (108 B) | Symbol: sub_0472ac
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0472ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0472ACULL;
}

// FDE #0746 | PC: 0x047318..0x04734c (52 B) | Symbol: sub_047318
// EN: AArch64 prologue [cbz x0, #0x47348; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x47348; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10]
uint64_t fde_sub_047318(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0xB4000180ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047318ULL;
}

// FDE #0747 | PC: 0x04734c..0x0474d4 (392 B) | Symbol: sub_04734c
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_04734c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x0188ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04734CULL;
}

// FDE #0748 | PC: 0x0474d4..0x0475d4 (256 B) | Symbol: sub_0474d4
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0474d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0474D4ULL;
}

// FDE #0749 | PC: 0x0475d4..0x0475dc (8 B) | Symbol: sub_0475d4
// EN: AArch64 prologue [ldr x0, [x0]; b #0x4a9a8] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0]; b #0x4a9a8]
uint64_t fde_sub_0475d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000CF4ULL) << 32) | 0xF9400000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0475D4ULL;
}

// FDE #0750 | PC: 0x0475dc..0x04765c (128 B) | Symbol: sub_0475dc
// EN: AArch64 prologue [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0475dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0475DCULL;
}

// FDE #0751 | PC: 0x04765c..0x0476bc (96 B) | Symbol: sub_04765c
// EN: AArch64 prologue [sub sp, sp, #0x30; str x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; str x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04765c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF3ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04765CULL;
}

// FDE #0752 | PC: 0x0476bc..0x0477f0 (308 B) | Symbol: sub_0476bc
// EN: AArch64 prologue [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0476bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF9ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0134ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0476BCULL;
}

// FDE #0753 | PC: 0x0477f0..0x0477f8 (8 B) | Symbol: sub_0477f0
// EN: AArch64 prologue [ldr x0, [x0]; b #0x4ab08] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0]; b #0x4ab08]
uint64_t fde_sub_0477f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000CC5ULL) << 32) | 0xF9400000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0477F0ULL;
}

// FDE #0754 | PC: 0x0477f8..0x0478bc (196 B) | Symbol: sub_0477f8
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0]
uint64_t fde_sub_0477f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0477F8ULL;
}

// FDE #0755 | PC: 0x0478bc..0x047950 (148 B) | Symbol: sub_0478bc
// EN: AArch64 prologue [cbz x0, #0x4794c; str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x4794c; str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]]
uint64_t fde_sub_0478bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0xB4000480ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0478BCULL;
}

// FDE #0756 | PC: 0x047950..0x047a98 (328 B) | Symbol: sub_047950
// EN: AArch64 prologue [sub sp, sp, #0x80; str x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_047950(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013FBULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0148ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047950ULL;
}

// FDE #0757 | PC: 0x047a98..0x047b9c (260 B) | Symbol: sub_047a98
// EN: AArch64 prologue [ldr x8, [x1]; str wzr, [x1, #0x2c]; ldrb w9, [x8, #0x20]; tbnz w9, #1, #0x47ac8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1]; str wzr, [x1, #0x2c]; ldrb w9, [x8, #0x20]; tbnz w9, #1, #0x47ac8]
uint64_t fde_sub_047a98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9002C3FULL) << 32) | 0xF9400028ULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047A98ULL;
}

// FDE #0758 | PC: 0x047b9c..0x047d34 (408 B) | Symbol: sub_047b9c
// EN: AArch64 prologue [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_047b9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0198ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047B9CULL;
}

// FDE #0759 | PC: 0x047d34..0x047fac (632 B) | Symbol: sub_047d34
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]]
uint64_t fde_sub_047d34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9036FFCULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0278ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047D34ULL;
}

// FDE #0760 | PC: 0x047fac..0x04813c (400 B) | Symbol: sub_047fac
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_047fac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0190ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047FACULL;
}

// FDE #0761 | PC: 0x04813c..0x0482fc (448 B) | Symbol: sub_04813c
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_04813c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x01C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04813CULL;
}

// FDE #0762 | PC: 0x0482fc..0x048468 (364 B) | Symbol: sub_0482fc
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0482fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x016CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0482FCULL;
}

// FDE #0763 | PC: 0x048468..0x048584 (284 B) | Symbol: sub_048468
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_048468(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048468ULL;
}

// FDE #0764 | PC: 0x048584..0x048634 (176 B) | Symbol: sub_048584
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_048584(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048584ULL;
}

// FDE #0765 | PC: 0x048634..0x048694 (96 B) | Symbol: sub_048634
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_048634(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048634ULL;
}

// FDE #0766 | PC: 0x048694..0x0486b8 (36 B) | Symbol: sub_048694
// EN: AArch64 prologue [ldr x9, [x0, #0x10]; cbz x9, #0x486a4; mov w0, #-0x390; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [x0, #0x10]; cbz x9, #0x486a4; mov w0, #-0x390; ret]
uint64_t fde_sub_048694(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000069ULL) << 32) | 0xF9400809ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048694ULL;
}

// FDE #0767 | PC: 0x0486b8..0x0486c4 (12 B) | Symbol: sub_0486b8
// EN: AArch64 prologue [str x1, [x0, #0x38]; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [str x1, [x0, #0x38]; mov w0, wzr; ret]
uint64_t fde_sub_0486b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xF9001C01ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0486B8ULL;
}

// FDE #0768 | PC: 0x0486c4..0x048734 (112 B) | Symbol: sub_0486c4
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0]
uint64_t fde_sub_0486c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0486C4ULL;
}

// FDE #0769 | PC: 0x048734..0x048788 (84 B) | Symbol: sub_048734
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_048734(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048734ULL;
}

// FDE #0770 | PC: 0x048788..0x0487c8 (64 B) | Symbol: sub_048788
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w8, #3] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w8, #3]
uint64_t fde_sub_048788(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048788ULL;
}

// FDE #0771 | PC: 0x0487c8..0x048800 (56 B) | Symbol: sub_0487c8
// EN: AArch64 prologue [cbz x0, #0x487fc; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x487fc; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10]
uint64_t fde_sub_0487c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0xB40001A0ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0487C8ULL;
}

// FDE #0772 | PC: 0x048800..0x048808 (8 B) | Symbol: sub_048800
// EN: AArch64 prologue [ldr x0, [x0, #0x20]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x20]; ret]
uint64_t fde_sub_048800(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF9401000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048800ULL;
}

// FDE #0773 | PC: 0x048808..0x0489c8 (448 B) | Symbol: sub_048808
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_048808(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x01C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048808ULL;
}

// FDE #0774 | PC: 0x0489c8..0x048b2c (356 B) | Symbol: sub_0489c8
// EN: AArch64 prologue [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0489c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF9ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0164ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0489C8ULL;
}

// FDE #0775 | PC: 0x048b2c..0x048c88 (348 B) | Symbol: sub_048b2c
// EN: AArch64 prologue [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_048b2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF9ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x015CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048B2CULL;
}

// FDE #0776 | PC: 0x048c88..0x048dd8 (336 B) | Symbol: sub_048c88
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_048c88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0150ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048C88ULL;
}

// FDE #0777 | PC: 0x048dd8..0x04907c (676 B) | Symbol: sub_048dd8
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_048dd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x02A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048DD8ULL;
}

// FDE #0778 | PC: 0x04907c..0x04915c (224 B) | Symbol: sub_04907c
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_04907c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04907CULL;
}

// FDE #0779 | PC: 0x04915c..0x0491dc (128 B) | Symbol: sub_04915c
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04915c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04915CULL;
}

// FDE #0780 | PC: 0x0491dc..0x049254 (120 B) | Symbol: sub_0491dc
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0491dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0491DCULL;
}

// FDE #0781 | PC: 0x049254..0x04932c (216 B) | Symbol: sub_049254
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_049254(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049254ULL;
}

// FDE #0782 | PC: 0x04932c..0x0493ec (192 B) | Symbol: sub_04932c
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_04932c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04932CULL;
}

// FDE #0783 | PC: 0x0493ec..0x0494c8 (220 B) | Symbol: sub_0493ec
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0493ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0493ECULL;
}

// FDE #0784 | PC: 0x0494c8..0x049518 (80 B) | Symbol: sub_0494c8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w0, #0x50] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w0, #0x50]
uint64_t fde_sub_0494c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0494C8ULL;
}

// FDE #0785 | PC: 0x049518..0x049550 (56 B) | Symbol: sub_049518
// EN: AArch64 prologue [cbz x0, #0x4954c; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x4954c; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10]
uint64_t fde_sub_049518(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0xB40001A0ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049518ULL;
}

// FDE #0786 | PC: 0x049550..0x04957c (44 B) | Symbol: sub_049550
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w0, #0x38; bl #0xee60] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w0, #0x38; bl #0xee60]
uint64_t fde_sub_049550(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049550ULL;
}

// FDE #0787 | PC: 0x04957c..0x049580 (4 B) | Symbol: sub_04957c
// EN: AArch64 prologue [b #0xedd0] | VI: Khởi đầu hàm AArch64 [b #0xedd0]
uint64_t fde_sub_04957c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0x17FF1615ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04957CULL;
}

// FDE #0788 | PC: 0x049580..0x0496b8 (312 B) | Symbol: sub_049580
// EN: AArch64 prologue [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_049580(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF9ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0138ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049580ULL;
}

// FDE #0789 | PC: 0x0496b8..0x0497e0 (296 B) | Symbol: sub_0496b8
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0496b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0128ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0496B8ULL;
}

// FDE #0790 | PC: 0x0497e0..0x0499cc (492 B) | Symbol: sub_0497e0
// EN: AArch64 prologue [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0497e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x01ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0497E0ULL;
}

// FDE #0791 | PC: 0x0499cc..0x049b5c (400 B) | Symbol: sub_0499cc
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_0499cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9016FFCULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0190ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0499CCULL;
}

// FDE #0792 | PC: 0x049b5c..0x049bd4 (120 B) | Symbol: sub_049b5c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_049b5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049B5CULL;
}

// FDE #0793 | PC: 0x049bd4..0x049c98 (196 B) | Symbol: sub_049bd4
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_049bd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049BD4ULL;
}

// FDE #0794 | PC: 0x049c98..0x049d60 (200 B) | Symbol: sub_049c98
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_049c98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049C98ULL;
}

// FDE #0795 | PC: 0x049d60..0x049dd4 (116 B) | Symbol: sub_049d60
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_049d60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049D60ULL;
}

// FDE #0796 | PC: 0x049dd4..0x049e4c (120 B) | Symbol: sub_049dd4
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_049dd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049DD4ULL;
}

// FDE #0797 | PC: 0x049e4c..0x049ec0 (116 B) | Symbol: sub_049e4c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_049e4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049E4CULL;
}

// FDE #0798 | PC: 0x049ec0..0x049fa8 (232 B) | Symbol: sub_049ec0
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_049ec0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049EC0ULL;
}

// FDE #0799 | PC: 0x049fa8..0x04a0d8 (304 B) | Symbol: sub_049fa8
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_049fa8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049FA8ULL;
}

// FDE #0800 | PC: 0x04a0d8..0x04a0f4 (28 B) | Symbol: sub_04a0d8
// EN: AArch64 prologue [ldr x8, [x0, #0x20]; ldr x9, [x1, #0x20]; cmp x8, x9; mov w8, #1] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x20]; ldr x9, [x1, #0x20]; cmp x8, x9; mov w8, #1]
uint64_t fde_sub_04a0d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401029ULL) << 32) | 0xF9401008ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A0D8ULL;
}

// FDE #0801 | PC: 0x04a0f4..0x04a198 (164 B) | Symbol: sub_04a0f4
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_04a0f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A0F4ULL;
}

// FDE #0802 | PC: 0x04a198..0x04a284 (236 B) | Symbol: sub_04a198
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04a198(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A198ULL;
}

// FDE #0803 | PC: 0x04a284..0x04a2d0 (76 B) | Symbol: sub_04a284
// EN: AArch64 prologue [cbz x0, #0x4a2cc; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x4a2cc; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10]
uint64_t fde_sub_04a284(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0xB4000240ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A284ULL;
}

// FDE #0804 | PC: 0x04a2d0..0x04a3ac (220 B) | Symbol: sub_04a2d0
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_04a2d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A2D0ULL;
}

// FDE #0805 | PC: 0x04a3ac..0x04a494 (232 B) | Symbol: sub_04a3ac
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04a3ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A3ACULL;
}

// FDE #0806 | PC: 0x04a494..0x04a678 (484 B) | Symbol: sub_04a494
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_04a494(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x01E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A494ULL;
}

// FDE #0807 | PC: 0x04a678..0x04a794 (284 B) | Symbol: sub_04a678
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04a678(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A678ULL;
}

// FDE #0808 | PC: 0x04a794..0x04a908 (372 B) | Symbol: sub_04a794
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04a794(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0174ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A794ULL;
}

// FDE #0809 | PC: 0x04a908..0x04a9a8 (160 B) | Symbol: sub_04a908
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04a908(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A908ULL;
}

// FDE #0810 | PC: 0x04a9a8..0x04aa10 (104 B) | Symbol: sub_04a9a8
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0x28]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0x28]]
uint64_t fde_sub_04a9a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A9A8ULL;
}

// FDE #0811 | PC: 0x04aa10..0x04ab08 (248 B) | Symbol: sub_04aa10
// EN: AArch64 prologue [sub sp, sp, #0xa0; str x21, [sp, #0x70]; stp x20, x19, [sp, #0x80]; stp x29, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; str x21, [sp, #0x70]; stp x20, x19, [sp, #0x80]; stp x29, x30, [sp, #0x90]]
uint64_t fde_sub_04aa10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9003BF5ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AA10ULL;
}

// FDE #0812 | PC: 0x04ab08..0x04ab10 (8 B) | Symbol: sub_04ab08
// EN: AArch64 prologue [ldr x0, [x0, #0x18]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x18]; ret]
uint64_t fde_sub_04ab08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF9400C00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AB08ULL;
}

// FDE #0813 | PC: 0x04ab10..0x04aba8 (152 B) | Symbol: sub_04ab10
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; strb wzr, [x2]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; strb wzr, [x2]]
uint64_t fde_sub_04ab10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AB10ULL;
}

// FDE #0814 | PC: 0x04aba8..0x04abd4 (44 B) | Symbol: sub_04aba8
// EN: AArch64 prologue [ldr x0, [x0, #0xbf0]; ldr x5, [x0, #0x88]; cbz x5, #0x4abbc; ldrb w9, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0xbf0]; ldr x5, [x0, #0x88]; cbz x5, #0x4abbc; ldrb w9, [x0, #0x18]]
uint64_t fde_sub_04aba8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404405ULL) << 32) | 0xF945F800ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04ABA8ULL;
}

// FDE #0815 | PC: 0x04abd4..0x04abf0 (28 B) | Symbol: sub_04abd4
// EN: AArch64 prologue [ldr x0, [x0, #0xbf0]; ldr x2, [x0, #0x90]; cbz x2, #0x4abe8; ldrb w8, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0xbf0]; ldr x2, [x0, #0x90]; cbz x2, #0x4abe8; ldrb w8, [x0, #0x18]]
uint64_t fde_sub_04abd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404802ULL) << 32) | 0xF945F800ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04ABD4ULL;
}

// FDE #0816 | PC: 0x04abf0..0x04ac10 (32 B) | Symbol: sub_04abf0
// EN: AArch64 prologue [ldr x0, [x0, #0xbf0]; ldr x3, [x0, #0xa0]; cbz x3, #0x4ac04; ldrb w8, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0xbf0]; ldr x3, [x0, #0xa0]; cbz x3, #0x4ac04; ldrb w8, [x0, #0x18]]
uint64_t fde_sub_04abf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9405003ULL) << 32) | 0xF945F800ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04ABF0ULL;
}

// FDE #0817 | PC: 0x04ac10..0x04ac2c (28 B) | Symbol: sub_04ac10
// EN: AArch64 prologue [ldr x0, [x0, #0xbf0]; ldr x3, [x0, #0x98]; cbz x3, #0x4ac24; ldrb w8, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0xbf0]; ldr x3, [x0, #0x98]; cbz x3, #0x4ac24; ldrb w8, [x0, #0x18]]
uint64_t fde_sub_04ac10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404C03ULL) << 32) | 0xF945F800ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AC10ULL;
}

// FDE #0818 | PC: 0x04ac2c..0x04ac48 (28 B) | Symbol: sub_04ac2c
// EN: AArch64 prologue [ldr x0, [x0, #0xbf0]; ldr x3, [x0, #0xa8]; cbz x3, #0x4ac40; ldrb w8, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0xbf0]; ldr x3, [x0, #0xa8]; cbz x3, #0x4ac40; ldrb w8, [x0, #0x18]]
uint64_t fde_sub_04ac2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9405403ULL) << 32) | 0xF945F800ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AC2CULL;
}

// FDE #0819 | PC: 0x04ac48..0x04acdc (148 B) | Symbol: sub_04ac48
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04ac48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AC48ULL;
}

// FDE #0820 | PC: 0x04acdc..0x04ad98 (188 B) | Symbol: sub_04acdc
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04acdc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04ACDCULL;
}

// FDE #0821 | PC: 0x04ad98..0x04ae38 (160 B) | Symbol: sub_04ad98
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04ad98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AD98ULL;
}

// FDE #0822 | PC: 0x04ae38..0x04aee4 (172 B) | Symbol: sub_04ae38
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04ae38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AE38ULL;
}

// FDE #0823 | PC: 0x04aee4..0x04aef8 (20 B) | Symbol: sub_04aee4
// EN: AArch64 prologue [ldr x8, [x1, #0x160]; str x8, [x0, #0x78]; ldr x8, [x1, #0x118]; str x8, [x0, #0x50]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1, #0x160]; str x8, [x0, #0x78]; ldr x8, [x1, #0x118]; str x8, [x0, #0x50]]
uint64_t fde_sub_04aee4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9003C08ULL) << 32) | 0xF940B028ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AEE4ULL;
}

// FDE #0824 | PC: 0x04aef8..0x04af3c (68 B) | Symbol: sub_04aef8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0x88]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0x88]]
uint64_t fde_sub_04aef8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AEF8ULL;
}

// FDE #0825 | PC: 0x04af3c..0x04af80 (68 B) | Symbol: sub_04af3c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0x60]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0x60]]
uint64_t fde_sub_04af3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AF3CULL;
}

// FDE #0826 | PC: 0x04af80..0x04b084 (260 B) | Symbol: sub_04af80
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0x38]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0x38]]
uint64_t fde_sub_04af80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AF80ULL;
}

// FDE #0827 | PC: 0x04b084..0x04b094 (16 B) | Symbol: sub_04b084
// EN: AArch64 prologue [ldr w8, [x0, #0x18]; orr w8, w8, #1; str w8, [x0, #0x18]; ret] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #0x18]; orr w8, w8, #1; str w8, [x0, #0x18]; ret]
uint64_t fde_sub_04b084(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x32000108ULL) << 32) | 0xB9401808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B084ULL;
}

// FDE #0828 | PC: 0x04b094..0x04b0c4 (48 B) | Symbol: sub_04b094
// EN: AArch64 prologue [ldr x8, [x0, #0x28]; add x9, x0, #0x20; cmp x8, x9; b.eq #0x4b0ac] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x28]; add x9, x0, #0x20; cmp x8, x9; b.eq #0x4b0ac]
uint64_t fde_sub_04b094(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91008009ULL) << 32) | 0xF9401408ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B094ULL;
}

// FDE #0829 | PC: 0x04b0c4..0x04b330 (620 B) | Symbol: sub_04b0c4
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_04b0c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x026CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B0C4ULL;
}

// FDE #0830 | PC: 0x04b330..0x04b474 (324 B) | Symbol: sub_04b330
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x1, #0x28]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x1, #0x28]]
uint64_t fde_sub_04b330(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0144ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B330ULL;
}

// FDE #0831 | PC: 0x04b474..0x04b490 (28 B) | Symbol: sub_04b474
// EN: AArch64 prologue [adrp x8, #0x9b000; adrp x9, #0x9b000; ldr x8, [x8, #0xf60]; ldr x9, [x9, #0xed8]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9b000; adrp x9, #0x9b000; ldr x8, [x8, #0xf60]; ldr x9, [x9, #0xed8]]
uint64_t fde_sub_04b474(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000289ULL) << 32) | 0x90000288ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B474ULL;
}

// FDE #0832 | PC: 0x04b490..0x04b49c (12 B) | Symbol: sub_04b490
// EN: AArch64 prologue [cmp x1, x0; cset w0, lo; ret] | VI: Khởi đầu hàm AArch64 [cmp x1, x0; cset w0, lo; ret]
uint64_t fde_sub_04b490(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1A9F27E0ULL) << 32) | 0xEB00003FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B490ULL;
}

// FDE #0833 | PC: 0x04b49c..0x04b4a8 (12 B) | Symbol: sub_04b49c
// EN: AArch64 prologue [cmp x1, x0; cset w0, lo; ret] | VI: Khởi đầu hàm AArch64 [cmp x1, x0; cset w0, lo; ret]
uint64_t fde_sub_04b49c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1A9F27E0ULL) << 32) | 0xEB00003FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B49CULL;
}

// FDE #0834 | PC: 0x04b4a8..0x04b5c4 (284 B) | Symbol: sub_04b4a8
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04b4a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B4A8ULL;
}

// FDE #0835 | PC: 0x04b5c4..0x04b5dc (24 B) | Symbol: sub_04b5c4
// EN: AArch64 prologue [ldr x2, [x0, #8]; cbz x2, #0x4b5d8; ldr x1, [x0, #0x40a8]; mov w0, #1] | VI: Khởi đầu hàm AArch64 [ldr x2, [x0, #8]; cbz x2, #0x4b5d8; ldr x1, [x0, #0x40a8]; mov w0, #1]
uint64_t fde_sub_04b5c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000082ULL) << 32) | 0xF9400402ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B5C4ULL;
}

// FDE #0836 | PC: 0x04b5dc..0x04b6fc (288 B) | Symbol: sub_04b5dc
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04b5dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0120ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B5DCULL;
}

// FDE #0837 | PC: 0x04b6fc..0x04bacc (976 B) | Symbol: sub_04b6fc
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_04b6fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x03D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B6FCULL;
}

// FDE #0838 | PC: 0x04bacc..0x04be0c (832 B) | Symbol: sub_04bacc
// EN: AArch64 prologue [cbz x0, #0x4be08; stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x4be08; stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]]
uint64_t fde_sub_04bacc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD57F6ULL) << 32) | 0xB40019E0ULL;
    const uint64_t kPcRange = 0x0340ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04BACCULL;
}

// FDE #0839 | PC: 0x04be0c..0x04bf84 (376 B) | Symbol: sub_04be0c
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_04be0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04BE0CULL;
}

// FDE #0840 | PC: 0x04bf84..0x04c084 (256 B) | Symbol: sub_04bf84
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04bf84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04BF84ULL;
}

// FDE #0841 | PC: 0x04c084..0x04c534 (1200 B) | Symbol: sub_04c084
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04c084(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x04B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C084ULL;
}

// FDE #0842 | PC: 0x04c534..0x04c570 (60 B) | Symbol: sub_04c534
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0x48]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0x48]]
uint64_t fde_sub_04c534(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C534ULL;
}

// FDE #0843 | PC: 0x04c570..0x04c5ac (60 B) | Symbol: sub_04c570
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0x48]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0x48]]
uint64_t fde_sub_04c570(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C570ULL;
}

// FDE #0844 | PC: 0x04c5ac..0x04c878 (716 B) | Symbol: sub_04c5ac
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04c5ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x02CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C5ACULL;
}

// FDE #0845 | PC: 0x04c878..0x04c98c (276 B) | Symbol: sub_04c878
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_04c878(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C878ULL;
}

// FDE #0846 | PC: 0x04c98c..0x04cb94 (520 B) | Symbol: sub_04c98c
// EN: AArch64 prologue [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_04c98c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0208ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C98CULL;
}

// FDE #0847 | PC: 0x04cb94..0x04cc98 (260 B) | Symbol: sub_04cb94
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_04cb94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04CB94ULL;
}

// FDE #0848 | PC: 0x04cc98..0x04d2cc (1588 B) | Symbol: sub_04cc98
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_04cc98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0634ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04CC98ULL;
}

// FDE #0849 | PC: 0x04d2cc..0x04d3b8 (236 B) | Symbol: sub_04d2cc
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_04d2cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D2CCULL;
}

// FDE #0850 | PC: 0x04d3b8..0x04d4a8 (240 B) | Symbol: sub_04d3b8
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_04d3b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x00F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D3B8ULL;
}

// FDE #0851 | PC: 0x04d4a8..0x04d534 (140 B) | Symbol: sub_04d4a8
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_04d4a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D4A8ULL;
}

// FDE #0852 | PC: 0x04d534..0x04d61c (232 B) | Symbol: sub_04d534
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_04d534(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D534ULL;
}

// FDE #0853 | PC: 0x04d61c..0x04d6dc (192 B) | Symbol: sub_04d61c
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_04d61c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D61CULL;
}

// FDE #0854 | PC: 0x04d6dc..0x04d6e4 (8 B) | Symbol: sub_04d6dc
// EN: AArch64 prologue [mov x0, x1; b #0xee60] | VI: Khởi đầu hàm AArch64 [mov x0, x1; b #0xee60]
uint64_t fde_sub_04d6dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF05E0ULL) << 32) | 0xAA0103E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D6DCULL;
}

// FDE #0855 | PC: 0x04d6e4..0x04d6ec (8 B) | Symbol: sub_04d6e4
// EN: AArch64 prologue [mov x0, x1; b #0xedd0] | VI: Khởi đầu hàm AArch64 [mov x0, x1; b #0xedd0]
uint64_t fde_sub_04d6e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF05BAULL) << 32) | 0xAA0103E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D6E4ULL;
}

// FDE #0856 | PC: 0x04d6ec..0x04d7b4 (200 B) | Symbol: sub_04d6ec
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_04d6ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D6ECULL;
}

// FDE #0857 | PC: 0x04d7b4..0x04d858 (164 B) | Symbol: sub_04d7b4
// EN: AArch64 prologue [sub sp, sp, #0x110; stp x28, x19, [sp, #0xf0]; stp x29, x30, [sp, #0x100]; add x29, sp, #0x100] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; stp x28, x19, [sp, #0xf0]; stp x29, x30, [sp, #0x100]; add x29, sp, #0x100]
uint64_t fde_sub_04d7b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90F4FFCULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D7B4ULL;
}

// FDE #0858 | PC: 0x04d858..0x04e50c (3252 B) | Symbol: sub_04d858
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_04d858(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9026FFCULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0CB4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D858ULL;
}

// FDE #0859 | PC: 0x04e50c..0x04e63c (304 B) | Symbol: sub_04e50c
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04e50c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E50CULL;
}

// FDE #0860 | PC: 0x04e63c..0x04e668 (44 B) | Symbol: sub_04e63c
// EN: AArch64 prologue [ldr x9, [x2, #0x1068]; cbz x9, #0x4e664; ldr x8, [x9, #0x10]; cbz x8, #0x4e664] | VI: Khởi đầu hàm AArch64 [ldr x9, [x2, #0x1068]; cbz x9, #0x4e664; ldr x8, [x9, #0x10]; cbz x8, #0x4e664]
uint64_t fde_sub_04e63c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000129ULL) << 32) | 0xF9483449ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E63CULL;
}

// FDE #0861 | PC: 0x04e668..0x04ec7c (1556 B) | Symbol: sub_04e668
// EN: AArch64 prologue [stp x28, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_04e668(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FCULL;
    const uint64_t kPcRange = 0x0614ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E668ULL;
}

// FDE #0862 | PC: 0x04ec7c..0x04ed20 (164 B) | Symbol: sub_04ec7c
// EN: AArch64 prologue [str x28, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x28, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_04ec7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FFCULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04EC7CULL;
}

// FDE #0863 | PC: 0x04ed20..0x04ee94 (372 B) | Symbol: sub_04ed20
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_04ed20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0174ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04ED20ULL;
}

// FDE #0864 | PC: 0x04ee94..0x04f184 (752 B) | Symbol: sub_04ee94
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_04ee94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x02F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04EE94ULL;
}

// FDE #0865 | PC: 0x04f184..0x04f194 (16 B) | Symbol: sub_04f184
// EN: AArch64 prologue [ldr x8, [x0, #0xac0]; orr x8, x8, #0x80000000; str x8, [x0, #0xac0]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0xac0]; orr x8, x8, #0x80000000; str x8, [x0, #0xac0]; ret]
uint64_t fde_sub_04f184(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB2610108ULL) << 32) | 0xF9456008ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F184ULL;
}

// FDE #0866 | PC: 0x04f194..0x04f21c (136 B) | Symbol: sub_04f194
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04f194(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F194ULL;
}

// FDE #0867 | PC: 0x04f21c..0x04f44c (560 B) | Symbol: sub_04f21c
// EN: AArch64 prologue [stp x28, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_04f21c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FFCULL;
    const uint64_t kPcRange = 0x0230ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F21CULL;
}

// FDE #0868 | PC: 0x04f44c..0x04f65c (528 B) | Symbol: sub_04f44c
// EN: AArch64 prologue [sub sp, sp, #0x60; str x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_04f44c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0210ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F44CULL;
}

// FDE #0869 | PC: 0x04f65c..0x04f7d4 (376 B) | Symbol: sub_04f65c
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_04f65c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F65CULL;
}

// FDE #0870 | PC: 0x04f7d4..0x04f7dc (8 B) | Symbol: sub_04f7d4
// EN: AArch64 prologue [str x1, [x0, #0xbf0]; ret] | VI: Khởi đầu hàm AArch64 [str x1, [x0, #0xbf0]; ret]
uint64_t fde_sub_04f7d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF905F801ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F7D4ULL;
}

// FDE #0871 | PC: 0x04f7dc..0x04f930 (340 B) | Symbol: sub_04f7dc
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]]
uint64_t fde_sub_04f7dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9036FFCULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0154ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F7DCULL;
}

// FDE #0872 | PC: 0x04f930..0x04fa84 (340 B) | Symbol: sub_04f930
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_04f930(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x0154ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F930ULL;
}

// FDE #0873 | PC: 0x04fa84..0x04fa94 (16 B) | Symbol: sub_04fa84
// EN: AArch64 prologue [ldp x8, x9, [x0]; str x8, [x9]; str x9, [x8, #8]; b #0xedd0] | VI: Khởi đầu hàm AArch64 [ldp x8, x9, [x0]; str x8, [x9]; str x9, [x8, #8]; b #0xedd0]
uint64_t fde_sub_04fa84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000128ULL) << 32) | 0xA9402408ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04FA84ULL;
}

// FDE #0874 | PC: 0x04fa94..0x04fb38 (164 B) | Symbol: sub_04fa94
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04fa94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04FA94ULL;
}

// FDE #0875 | PC: 0x04fb38..0x04fbd8 (160 B) | Symbol: sub_04fb38
// EN: AArch64 prologue [ldr x11, [x0, #0xf58]; add x9, x0, #0xf50; cmp x11, x9; b.eq #0x4fbd4] | VI: Khởi đầu hàm AArch64 [ldr x11, [x0, #0xf58]; add x9, x0, #0xf50; cmp x11, x9; b.eq #0x4fbd4]
uint64_t fde_sub_04fb38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x913D4009ULL) << 32) | 0xF947AC0BULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04FB38ULL;
}

// FDE #0876 | PC: 0x04fbd8..0x04fbe4 (12 B) | Symbol: sub_04fbd8
// EN: AArch64 prologue [cbz x0, #0x4fbe0; ldr x0, [x0, #0xb68]; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x4fbe0; ldr x0, [x0, #0xb68]; ret]
uint64_t fde_sub_04fbd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF945B400ULL) << 32) | 0xB4000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04FBD8ULL;
}

// FDE #0877 | PC: 0x04fbe4..0x04ff34 (848 B) | Symbol: sub_04fbe4
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]]
uint64_t fde_sub_04fbe4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9036FFCULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0350ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04FBE4ULL;
}

// FDE #0878 | PC: 0x04ff34..0x050040 (268 B) | Symbol: sub_04ff34
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_04ff34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04FF34ULL;
}

// FDE #0879 | PC: 0x050040..0x0504cc (1164 B) | Symbol: sub_050040
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_050040(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x048CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x050040ULL;
}

// FDE #0880 | PC: 0x0504cc..0x050644 (376 B) | Symbol: sub_0504cc
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]]
uint64_t fde_sub_0504cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90467FAULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0504CCULL;
}

// FDE #0881 | PC: 0x050644..0x05075c (280 B) | Symbol: sub_050644
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_050644(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0118ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x050644ULL;
}

// FDE #0882 | PC: 0x05075c..0x050a4c (752 B) | Symbol: sub_05075c
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]]
uint64_t fde_sub_05075c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9036FFCULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x02F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05075CULL;
}

// FDE #0883 | PC: 0x050a4c..0x050b90 (324 B) | Symbol: sub_050a4c
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_050a4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0144ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x050A4CULL;
}

// FDE #0884 | PC: 0x050b90..0x050c30 (160 B) | Symbol: sub_050b90
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_050b90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x050B90ULL;
}

// FDE #0885 | PC: 0x050c30..0x050d50 (288 B) | Symbol: sub_050c30
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_050c30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0120ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x050C30ULL;
}

// FDE #0886 | PC: 0x050d50..0x050e94 (324 B) | Symbol: sub_050d50
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_050d50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0144ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x050D50ULL;
}

// FDE #0887 | PC: 0x050e94..0x050ffc (360 B) | Symbol: sub_050e94
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_050e94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90457F6ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0168ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x050E94ULL;
}

// FDE #0888 | PC: 0x050ffc..0x051418 (1052 B) | Symbol: sub_050ffc
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_050ffc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90267FAULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x041CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x050FFCULL;
}

// FDE #0889 | PC: 0x051418..0x05147c (100 B) | Symbol: sub_051418
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_051418(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051418ULL;
}

// FDE #0890 | PC: 0x05147c..0x0514e0 (100 B) | Symbol: sub_05147c
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05147c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05147CULL;
}

// FDE #0891 | PC: 0x0514e0..0x051584 (164 B) | Symbol: sub_0514e0
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0514e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0514E0ULL;
}

// FDE #0892 | PC: 0x051584..0x051628 (164 B) | Symbol: sub_051584
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_051584(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051584ULL;
}

// FDE #0893 | PC: 0x051628..0x0516e0 (184 B) | Symbol: sub_051628
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_051628(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051628ULL;
}

// FDE #0894 | PC: 0x0516e0..0x0517bc (220 B) | Symbol: sub_0516e0
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0516e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0516E0ULL;
}

// FDE #0895 | PC: 0x0517bc..0x051b20 (868 B) | Symbol: sub_0517bc
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_0517bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9016FFCULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0364ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0517BCULL;
}

// FDE #0896 | PC: 0x051b20..0x051b84 (100 B) | Symbol: sub_051b20
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; lsl w8, w1, #1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; lsl w8, w1, #1]
uint64_t fde_sub_051b20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051B20ULL;
}

// FDE #0897 | PC: 0x051b84..0x051b90 (12 B) | Symbol: sub_051b84
// EN: AArch64 prologue [ldr w8, [x0, #0xac0]; ubfx w0, w8, #1, #1; ret] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #0xac0]; ubfx w0, w8, #1, #1; ret]
uint64_t fde_sub_051b84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x53010500ULL) << 32) | 0xB94AC008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051B84ULL;
}

// FDE #0898 | PC: 0x051b90..0x051b9c (12 B) | Symbol: sub_051b90
// EN: AArch64 prologue [ldr w8, [x0, #0xac0]; ubfx w0, w8, #0x16, #1; ret] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #0xac0]; ubfx w0, w8, #0x16, #1; ret]
uint64_t fde_sub_051b90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x53165900ULL) << 32) | 0xB94AC008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051B90ULL;
}

// FDE #0899 | PC: 0x051b9c..0x051d2c (400 B) | Symbol: sub_051b9c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_051b9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0190ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051B9CULL;
}

// FDE #0900 | PC: 0x051d2c..0x051db8 (140 B) | Symbol: sub_051d2c
// EN: AArch64 prologue [ldr x11, [x0, #0xf58]; add x8, x0, #0xf50; cmp x11, x8; b.eq #0x51db0] | VI: Khởi đầu hàm AArch64 [ldr x11, [x0, #0xf58]; add x8, x0, #0xf50; cmp x11, x8; b.eq #0x51db0]
uint64_t fde_sub_051d2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x913D4008ULL) << 32) | 0xF947AC0BULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051D2CULL;
}

// FDE #0901 | PC: 0x051db8..0x051f44 (396 B) | Symbol: sub_051db8
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0x704]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0x704]]
uint64_t fde_sub_051db8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x018CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051DB8ULL;
}

// FDE #0902 | PC: 0x051f44..0x051fe4 (160 B) | Symbol: sub_051f44
// EN: AArch64 prologue [ldr w8, [x0, #0xac8]; cmp w8, #1; b.ne #0x51f58; ldr w8, [x0, #0x378]] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #0xac8]; cmp w8, #1; b.ne #0x51f58; ldr w8, [x0, #0x378]]
uint64_t fde_sub_051f44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100051FULL) << 32) | 0xB94AC808ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051F44ULL;
}

// FDE #0903 | PC: 0x051fe4..0x052138 (340 B) | Symbol: sub_051fe4
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_051fe4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0154ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051FE4ULL;
}

// FDE #0904 | PC: 0x052138..0x05216c (52 B) | Symbol: sub_052138
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w2, #0x73; bl #0x4b4a8] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w2, #0x73; bl #0x4b4a8]
uint64_t fde_sub_052138(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052138ULL;
}

// FDE #0905 | PC: 0x05216c..0x052258 (236 B) | Symbol: sub_05216c
// EN: AArch64 prologue [cmp x2, #0x1e; b.lo #0x52254; str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]] | VI: Khởi đầu hàm AArch64 [cmp x2, #0x1e; b.lo #0x52254; str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]]
uint64_t fde_sub_05216c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000723ULL) << 32) | 0xF100785FULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05216CULL;
}

// FDE #0906 | PC: 0x052258..0x052750 (1272 B) | Symbol: sub_052258
// EN: AArch64 prologue [sub sp, sp, #0x1f0; stp x28, x27, [sp, #0x190]; stp x26, x25, [sp, #0x1a0]; stp x24, x23, [sp, #0x1b0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1f0; stp x28, x27, [sp, #0x190]; stp x26, x25, [sp, #0x1a0]; stp x24, x23, [sp, #0x1b0]]
uint64_t fde_sub_052258(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9196FFCULL) << 32) | 0xD107C3FFULL;
    const uint64_t kPcRange = 0x04F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052258ULL;
}

// FDE #0907 | PC: 0x052750..0x0527d8 (136 B) | Symbol: sub_052750
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_052750(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052750ULL;
}

// FDE #0908 | PC: 0x0527d8..0x0528cc (244 B) | Symbol: sub_0527d8
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub w8, w2, #1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub w8, w2, #1]
uint64_t fde_sub_0527d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0527D8ULL;
}

// FDE #0909 | PC: 0x0528cc..0x052978 (172 B) | Symbol: sub_0528cc
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0528cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0528CCULL;
}

// FDE #0910 | PC: 0x052978..0x052aec (372 B) | Symbol: sub_052978
// EN: AArch64 prologue [str x28, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x28, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_052978(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xF81A0FFCULL;
    const uint64_t kPcRange = 0x0174ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052978ULL;
}

// FDE #0911 | PC: 0x052aec..0x052bf0 (260 B) | Symbol: sub_052aec
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_052aec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052AECULL;
}

// FDE #0912 | PC: 0x052bf0..0x052bf8 (8 B) | Symbol: sub_052bf0
// EN: AArch64 prologue [ldr x0, [x0, #0x710]; b #0x6e5f0] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x710]; b #0x6e5f0]
uint64_t fde_sub_052bf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14006E7FULL) << 32) | 0xF9438800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052BF0ULL;
}

// FDE #0913 | PC: 0x052bf8..0x052e18 (544 B) | Symbol: sub_052bf8
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_052bf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0220ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052BF8ULL;
}

// FDE #0914 | PC: 0x052e18..0x052f60 (328 B) | Symbol: sub_052e18
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_052e18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0148ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052E18ULL;
}

// FDE #0915 | PC: 0x052f60..0x053004 (164 B) | Symbol: sub_052f60
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_052f60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052F60ULL;
}

// FDE #0916 | PC: 0x053004..0x05333c (824 B) | Symbol: sub_053004
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_053004(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0338ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053004ULL;
}

// FDE #0917 | PC: 0x05333c..0x053394 (88 B) | Symbol: sub_05333c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05333c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05333CULL;
}

// FDE #0918 | PC: 0x053394..0x05346c (216 B) | Symbol: sub_053394
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]]
uint64_t fde_sub_053394(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90467FAULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053394ULL;
}

// FDE #0919 | PC: 0x05346c..0x05376c (768 B) | Symbol: sub_05346c
// EN: AArch64 prologue [ldrb w8, [x0, #0xc60]; cbz w8, #0x5375c; ldr x8, [x0, #0xc68]; ldrb w9, [x0, #0xc80]] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0xc60]; cbz w8, #0x5375c; ldr x8, [x0, #0xc68]; ldrb w9, [x0, #0xc80]]
uint64_t fde_sub_05346c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34001768ULL) << 32) | 0x39718008ULL;
    const uint64_t kPcRange = 0x0300ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05346CULL;
}

// FDE #0920 | PC: 0x05376c..0x05389c (304 B) | Symbol: sub_05376c
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_05376c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05376CULL;
}

// FDE #0921 | PC: 0x05389c..0x05399c (256 B) | Symbol: sub_05389c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05389c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05389CULL;
}

// FDE #0922 | PC: 0x05399c..0x053a6c (208 B) | Symbol: sub_05399c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05399c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05399CULL;
}

// FDE #0923 | PC: 0x053a6c..0x053b70 (260 B) | Symbol: sub_053a6c
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_053a6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053A6CULL;
}

// FDE #0924 | PC: 0x053b70..0x053be4 (116 B) | Symbol: sub_053b70
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_053b70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053B70ULL;
}

// FDE #0925 | PC: 0x053be4..0x053c6c (136 B) | Symbol: sub_053be4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0xac0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0xac0]]
uint64_t fde_sub_053be4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053BE4ULL;
}

// FDE #0926 | PC: 0x053c6c..0x053c90 (36 B) | Symbol: sub_053c6c
// EN: AArch64 prologue [ldr x8, [x0, #0x420]; cbz x8, #0x53c88; ldr x8, [x0, #0x4b0]; cmp x8, #0] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x420]; cbz x8, #0x53c88; ldr x8, [x0, #0x4b0]; cmp x8, #0]
uint64_t fde_sub_053c6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB40000C8ULL) << 32) | 0xF9421008ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053C6CULL;
}

// FDE #0927 | PC: 0x053c90..0x053d0c (124 B) | Symbol: sub_053c90
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_053c90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053C90ULL;
}

// FDE #0928 | PC: 0x053d0c..0x053ea4 (408 B) | Symbol: sub_053d0c
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_053d0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0198ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053D0CULL;
}

// FDE #0929 | PC: 0x053ea4..0x053fd4 (304 B) | Symbol: sub_053ea4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x1, [x0, #0xf48]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x1, [x0, #0xf48]]
uint64_t fde_sub_053ea4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053EA4ULL;
}

// FDE #0930 | PC: 0x053fd4..0x05402c (88 B) | Symbol: sub_053fd4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; add x19, x0, #0x4a0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; add x19, x0, #0x4a0]
uint64_t fde_sub_053fd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053FD4ULL;
}

// FDE #0931 | PC: 0x05402c..0x054124 (248 B) | Symbol: sub_05402c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05402c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05402CULL;
}

// FDE #0932 | PC: 0x054124..0x0541e0 (188 B) | Symbol: sub_054124
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_054124(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054124ULL;
}

// FDE #0933 | PC: 0x0541e0..0x054228 (72 B) | Symbol: sub_0541e0
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr w8, [x0, #0xac8]; cmp w8, #1] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr w8, [x0, #0xac8]; cmp w8, #1]
uint64_t fde_sub_0541e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0541E0ULL;
}

// FDE #0934 | PC: 0x054228..0x054284 (92 B) | Symbol: sub_054228
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_054228(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054228ULL;
}

// FDE #0935 | PC: 0x054284..0x054478 (500 B) | Symbol: sub_054284
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_054284(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x01F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054284ULL;
}

// FDE #0936 | PC: 0x054478..0x05455c (228 B) | Symbol: sub_054478
// EN: AArch64 prologue [cmp w2, #1; b.eq #0x544d8; cbnz w2, #0x544e0; ldr w8, [x0, #0xac8]] | VI: Khởi đầu hàm AArch64 [cmp w2, #1; b.eq #0x544d8; cbnz w2, #0x544e0; ldr w8, [x0, #0xac8]]
uint64_t fde_sub_054478(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x540002E0ULL) << 32) | 0x7100045FULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054478ULL;
}

// FDE #0937 | PC: 0x05455c..0x05492c (976 B) | Symbol: sub_05455c
// EN: AArch64 prologue [stp x28, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_05455c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FFCULL;
    const uint64_t kPcRange = 0x03D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05455CULL;
}

// FDE #0938 | PC: 0x05492c..0x054a70 (324 B) | Symbol: sub_05492c
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_05492c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0144ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05492CULL;
}

// FDE #0939 | PC: 0x054a70..0x054b48 (216 B) | Symbol: sub_054a70
// EN: AArch64 prologue [ldr w8, [x0, #0xac8]; cmp w8, #1; b.ne #0x54a88; mov w8, #-0x2c0] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #0xac8]; cmp w8, #1; b.ne #0x54a88; mov w8, #-0x2c0]
uint64_t fde_sub_054a70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100051FULL) << 32) | 0xB94AC808ULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054A70ULL;
}

// FDE #0940 | PC: 0x054b48..0x054b70 (40 B) | Symbol: sub_054b48
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x1; mov x1, x0] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x1; mov x1, x0]
uint64_t fde_sub_054b48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054B48ULL;
}

// FDE #0941 | PC: 0x054b70..0x054b7c (12 B) | Symbol: sub_054b70
// EN: AArch64 prologue [ldr x2, [x1, #0xb28]; ldr x1, [x1, #0xb68]; br x2] | VI: Khởi đầu hàm AArch64 [ldr x2, [x1, #0xb28]; ldr x1, [x1, #0xb68]; br x2]
uint64_t fde_sub_054b70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF945B421ULL) << 32) | 0xF9459422ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054B70ULL;
}

// FDE #0942 | PC: 0x054b7c..0x054b88 (12 B) | Symbol: sub_054b7c
// EN: AArch64 prologue [ldr x3, [x2, #0xb18]; ldr x2, [x2, #0xb68]; br x3] | VI: Khởi đầu hàm AArch64 [ldr x3, [x2, #0xb18]; ldr x2, [x2, #0xb68]; br x3]
uint64_t fde_sub_054b7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF945B442ULL) << 32) | 0xF9458C43ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054B7CULL;
}

// FDE #0943 | PC: 0x054b88..0x054b8c (4 B) | Symbol: sub_054b88
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_054b88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9479828ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054B88ULL;
}

// FDE #0944 | PC: 0x054b8c..0x054bd0 (68 B) | Symbol: sub_054b8c
// EN: AArch64 prologue [ldr x8, [x1, #0xf30]; cbz x8, #0x54b98; ret; ldr x8, [x1, #0xf38]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1, #0xf30]; cbz x8, #0x54b98; ret; ldr x8, [x1, #0xf38]]
uint64_t fde_sub_054b8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000048ULL) << 32) | 0xF9479828ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054B8CULL;
}

// FDE #0945 | PC: 0x054bd0..0x054be8 (24 B) | Symbol: sub_054bd0
// EN: AArch64 prologue [ldr x5, [x4, #0xb60]; cbz x5, #0x54be0; ldr x4, [x4, #0xb68]; br x5] | VI: Khởi đầu hàm AArch64 [ldr x5, [x4, #0xb60]; cbz x5, #0x54be0; ldr x4, [x4, #0xb68]; br x5]
uint64_t fde_sub_054bd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000065ULL) << 32) | 0xF945B085ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054BD0ULL;
}

// FDE #0946 | PC: 0x054be8..0x054c24 (60 B) | Symbol: sub_054be8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0xac0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0xac0]]
uint64_t fde_sub_054be8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054BE8ULL;
}

// FDE #0947 | PC: 0x054c24..0x054c64 (64 B) | Symbol: sub_054c24
// EN: AArch64 prologue [ldr w8, [x0, #0xac8]; cmp w8, #1; b.ne #0x54c4c; ldrb w8, [x0, #0xac0]] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #0xac8]; cmp w8, #1; b.ne #0x54c4c; ldrb w8, [x0, #0xac0]]
uint64_t fde_sub_054c24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100051FULL) << 32) | 0xB94AC808ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054C24ULL;
}

// FDE #0948 | PC: 0x054c64..0x054e18 (436 B) | Symbol: sub_054c64
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_054c64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x01B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054C64ULL;
}

// FDE #0949 | PC: 0x054e18..0x054f78 (352 B) | Symbol: sub_054e18
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_054e18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0160ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054E18ULL;
}

// FDE #0950 | PC: 0x054f78..0x0552e8 (880 B) | Symbol: sub_054f78
// EN: AArch64 prologue [sub sp, sp, #0x60; str x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_054f78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0370ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054F78ULL;
}

// FDE #0951 | PC: 0x0552e8..0x05538c (164 B) | Symbol: sub_0552e8
// EN: AArch64 prologue [ldr x9, [x0, #0xf58]; add x8, x0, #0xf50; cmp x9, x8; b.eq #0x55384] | VI: Khởi đầu hàm AArch64 [ldr x9, [x0, #0xf58]; add x8, x0, #0xf50; cmp x9, x8; b.eq #0x55384]
uint64_t fde_sub_0552e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x913D4008ULL) << 32) | 0xF947AC09ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0552E8ULL;
}

// FDE #0952 | PC: 0x05538c..0x0553f4 (104 B) | Symbol: sub_05538c
// EN: AArch64 prologue [ldr x9, [x0, #0xf58]; add x8, x0, #0xf50; cmp x9, x8; b.eq #0x553ec] | VI: Khởi đầu hàm AArch64 [ldr x9, [x0, #0xf58]; add x8, x0, #0xf50; cmp x9, x8; b.eq #0x553ec]
uint64_t fde_sub_05538c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x913D4008ULL) << 32) | 0xF947AC09ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05538CULL;
}

// FDE #0953 | PC: 0x0553f4..0x05567c (648 B) | Symbol: sub_0553f4
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0553f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x0288ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0553F4ULL;
}

// FDE #0954 | PC: 0x05567c..0x05570c (144 B) | Symbol: sub_05567c
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05567c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05567CULL;
}

// FDE #0955 | PC: 0x05570c..0x055744 (56 B) | Symbol: sub_05570c
// EN: AArch64 prologue [ldr x4, [x0, #0xb48]; cbz x4, #0x55740; ldr x9, [x0, #0xac0]; tbz w9, #0x1f, #0x55740] | VI: Khởi đầu hàm AArch64 [ldr x4, [x0, #0xb48]; cbz x4, #0x55740; ldr x9, [x0, #0xac0]; tbz w9, #0x1f, #0x55740]
uint64_t fde_sub_05570c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000184ULL) << 32) | 0xF945A404ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05570CULL;
}

// FDE #0956 | PC: 0x055744..0x055874 (304 B) | Symbol: sub_055744
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_055744(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055744ULL;
}

// FDE #0957 | PC: 0x055874..0x0558d8 (100 B) | Symbol: sub_055874
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_055874(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055874ULL;
}

// FDE #0958 | PC: 0x0558d8..0x05592c (84 B) | Symbol: sub_0558d8
// EN: AArch64 prologue [ldr w8, [x0, #0xe78]; cmp w8, w1; b.le #0x5591c; add x8, x0, #0xe68] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #0xe78]; cmp w8, w1; b.le #0x5591c; add x8, x0, #0xe68]
uint64_t fde_sub_0558d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6B01011FULL) << 32) | 0xB94E7808ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0558D8ULL;
}

// FDE #0959 | PC: 0x05592c..0x055a78 (332 B) | Symbol: sub_05592c
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9b000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9b000]
uint64_t fde_sub_05592c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x014CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05592CULL;
}

// FDE #0960 | PC: 0x055a78..0x055b04 (140 B) | Symbol: sub_055a78
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_055a78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055A78ULL;
}

// FDE #0961 | PC: 0x055b04..0x055b38 (52 B) | Symbol: sub_055b04
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; cbz x0, #0x55b2c; ldr w8, [x0, #0x704]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; cbz x0, #0x55b2c; ldr w8, [x0, #0x704]]
uint64_t fde_sub_055b04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055B04ULL;
}

// FDE #0962 | PC: 0x055b38..0x055c34 (252 B) | Symbol: sub_055b38
// EN: AArch64 prologue [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_055b38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055B38ULL;
}

// FDE #0963 | PC: 0x055c34..0x055c3c (8 B) | Symbol: sub_055c34
// EN: AArch64 prologue [mov x0, x1; b #0xee60] | VI: Khởi đầu hàm AArch64 [mov x0, x1; b #0xee60]
uint64_t fde_sub_055c34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE48AULL) << 32) | 0xAA0103E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055C34ULL;
}

// FDE #0964 | PC: 0x055c3c..0x055c44 (8 B) | Symbol: sub_055c3c
// EN: AArch64 prologue [mov x0, x1; b #0xedd0] | VI: Khởi đầu hàm AArch64 [mov x0, x1; b #0xedd0]
uint64_t fde_sub_055c3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE464ULL) << 32) | 0xAA0103E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055C3CULL;
}

// FDE #0965 | PC: 0x055c44..0x055d0c (200 B) | Symbol: sub_055c44
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_055c44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055C44ULL;
}

// FDE #0966 | PC: 0x055d0c..0x055f34 (552 B) | Symbol: sub_055d0c
// EN: AArch64 prologue [sub sp, sp, #0x150; stp x28, x27, [sp, #0xf0]; stp x26, x25, [sp, #0x100]; stp x24, x23, [sp, #0x110]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x150; stp x28, x27, [sp, #0xf0]; stp x26, x25, [sp, #0x100]; stp x24, x23, [sp, #0x110]]
uint64_t fde_sub_055d0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90F6FFCULL) << 32) | 0xD10543FFULL;
    const uint64_t kPcRange = 0x0228ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055D0CULL;
}

// FDE #0967 | PC: 0x055f34..0x056078 (324 B) | Symbol: sub_055f34
// EN: AArch64 prologue [stp x28, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_055f34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FCULL;
    const uint64_t kPcRange = 0x0144ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055F34ULL;
}

// FDE #0968 | PC: 0x056078..0x056260 (488 B) | Symbol: sub_056078
// EN: AArch64 prologue [str x28, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x28, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_056078(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FFCULL;
    const uint64_t kPcRange = 0x01E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056078ULL;
}

// FDE #0969 | PC: 0x056260..0x0562f8 (152 B) | Symbol: sub_056260
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_056260(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056260ULL;
}

// FDE #0970 | PC: 0x0562f8..0x056348 (80 B) | Symbol: sub_0562f8
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x0; mov w0, #-1] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x0; mov w0, #-1]
uint64_t fde_sub_0562f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0562F8ULL;
}

// FDE #0971 | PC: 0x056348..0x056388 (64 B) | Symbol: sub_056348
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1]
uint64_t fde_sub_056348(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056348ULL;
}

// FDE #0972 | PC: 0x056388..0x056394 (12 B) | Symbol: sub_056388
// EN: AArch64 prologue [strb wzr, [x0]; str xzr, [x0, #0x18]; ret] | VI: Khởi đầu hàm AArch64 [strb wzr, [x0]; str xzr, [x0, #0x18]; ret]
uint64_t fde_sub_056388(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000C1FULL) << 32) | 0x3900001FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056388ULL;
}

// FDE #0973 | PC: 0x056394..0x0563b0 (28 B) | Symbol: sub_056394
// EN: AArch64 prologue [tst w2, #0xff; strb w2, [x0]; b.eq #0x563ac; add x0, x0, #1] | VI: Khởi đầu hàm AArch64 [tst w2, #0xff; strb w2, [x0]; b.eq #0x563ac; add x0, x0, #1]
uint64_t fde_sub_056394(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39000002ULL) << 32) | 0x72001C5FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056394ULL;
}

// FDE #0974 | PC: 0x0563b0..0x0563f0 (64 B) | Symbol: sub_0563b0
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1]
uint64_t fde_sub_0563b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0563B0ULL;
}

// FDE #0975 | PC: 0x0563f0..0x05640c (28 B) | Symbol: sub_0563f0
// EN: AArch64 prologue [add x8, x0, #0x30; movi v0.2d, #0000000000000000; strb wzr, [x0]; str xzr, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [add x8, x0, #0x30; movi v0.2d, #0000000000000000; strb wzr, [x0]; str xzr, [x0, #0x18]]
uint64_t fde_sub_0563f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6F00E400ULL) << 32) | 0x9100C008ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0563F0ULL;
}

// FDE #0976 | PC: 0x05640c..0x056428 (28 B) | Symbol: sub_05640c
// EN: AArch64 prologue [add x8, x0, #0x30; movi v0.2d, #0000000000000000; strb wzr, [x0]; str xzr, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [add x8, x0, #0x30; movi v0.2d, #0000000000000000; strb wzr, [x0]; str xzr, [x0, #0x18]]
uint64_t fde_sub_05640c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6F00E400ULL) << 32) | 0x9100C008ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05640CULL;
}

// FDE #0977 | PC: 0x056428..0x056488 (96 B) | Symbol: sub_056428
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_056428(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056428ULL;
}

// FDE #0978 | PC: 0x056488..0x0564fc (116 B) | Symbol: sub_056488
// EN: AArch64 prologue [ldp x8, x10, [x0, #0x10]; ldr x9, [x2]; add x8, x8, x10; add x8, x8, #1] | VI: Khởi đầu hàm AArch64 [ldp x8, x10, [x0, #0x10]; ldr x9, [x2]; add x8, x8, x10; add x8, x8, #1]
uint64_t fde_sub_056488(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400049ULL) << 32) | 0xA9412808ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056488ULL;
}

// FDE #0979 | PC: 0x0564fc..0x056618 (284 B) | Symbol: sub_0564fc
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0564fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0564FCULL;
}

// FDE #0980 | PC: 0x056618..0x056710 (248 B) | Symbol: sub_056618
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_056618(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056618ULL;
}

// FDE #0981 | PC: 0x056710..0x0567c4 (180 B) | Symbol: sub_056710
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_056710(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056710ULL;
}

// FDE #0982 | PC: 0x0567c4..0x0568ec (296 B) | Symbol: sub_0567c4
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0567c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0128ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0567C4ULL;
}

// FDE #0983 | PC: 0x0568ec..0x056a1c (304 B) | Symbol: sub_0568ec
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0568ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0568ECULL;
}

// FDE #0984 | PC: 0x056a1c..0x056a4c (48 B) | Symbol: sub_056a1c
// EN: AArch64 prologue [mov x8, x0; add x9, x0, #8; ldr x0, [x9]; cmp x0, x8] | VI: Khởi đầu hàm AArch64 [mov x8, x0; add x9, x0, #8; ldr x0, [x9]; cmp x0, x8]
uint64_t fde_sub_056a1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91002009ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056A1CULL;
}

// FDE #0985 | PC: 0x056a4c..0x056af0 (164 B) | Symbol: sub_056a4c
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_056a4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056A4CULL;
}

// FDE #0986 | PC: 0x056af0..0x056b00 (16 B) | Symbol: sub_056af0
// EN: AArch64 prologue [and w8, w0, #0xff; add w8, w8, w1, uxtb; add w0, w8, #2; ret] | VI: Khởi đầu hàm AArch64 [and w8, w0, #0xff; add w8, w8, w1, uxtb; add w0, w8, #2; ret]
uint64_t fde_sub_056af0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x0B210108ULL) << 32) | 0x12001C08ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056AF0ULL;
}

uint64_t DispatchTtkMediaNetShard3(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x041adcULL: return fde_sub_041adc(a0, a1, a2);
        case 0x041b18ULL: return fde_sub_041b18(a0, a1, a2);
        case 0x041b88ULL: return fde_sub_041b88(a0, a1, a2);
        case 0x041d2cULL: return fde_sub_041d2c(a0, a1, a2);
        case 0x041db8ULL: return fde_sub_041db8(a0, a1, a2);
        case 0x041dd0ULL: return fde_sub_041dd0(a0, a1, a2);
        case 0x041df0ULL: return fde_sub_041df0(a0, a1, a2);
        case 0x041eb8ULL: return fde_sub_041eb8(a0, a1, a2);
        case 0x041f00ULL: return fde_sub_041f00(a0, a1, a2);
        case 0x041f84ULL: return fde_sub_041f84(a0, a1, a2);
        case 0x042074ULL: return fde_sub_042074(a0, a1, a2);
        case 0x04213cULL: return fde_sub_04213c(a0, a1, a2);
        case 0x042220ULL: return fde_sub_042220(a0, a1, a2);
        case 0x0424dcULL: return fde_sub_0424dc(a0, a1, a2);
        case 0x042544ULL: return fde_sub_042544(a0, a1, a2);
        case 0x0425ecULL: return fde_sub_0425ec(a0, a1, a2);
        case 0x0426a8ULL: return fde_sub_0426a8(a0, a1, a2);
        case 0x0426f8ULL: return fde_sub_0426f8(a0, a1, a2);
        case 0x042788ULL: return fde_sub_042788(a0, a1, a2);
        case 0x0428f0ULL: return fde_sub_0428f0(a0, a1, a2);
        case 0x042cd4ULL: return fde_sub_042cd4(a0, a1, a2);
        case 0x042e60ULL: return fde_sub_042e60(a0, a1, a2);
        case 0x042f94ULL: return fde_sub_042f94(a0, a1, a2);
        case 0x0430e0ULL: return fde_sub_0430e0(a0, a1, a2);
        case 0x043264ULL: return fde_sub_043264(a0, a1, a2);
        case 0x043374ULL: return fde_sub_043374(a0, a1, a2);
        case 0x0434e0ULL: return fde_sub_0434e0(a0, a1, a2);
        case 0x0435f4ULL: return fde_sub_0435f4(a0, a1, a2);
        case 0x0437d8ULL: return fde_sub_0437d8(a0, a1, a2);
        case 0x0438dcULL: return fde_sub_0438dc(a0, a1, a2);
        case 0x0439dcULL: return fde_sub_0439dc(a0, a1, a2);
        case 0x043a04ULL: return fde_sub_043a04(a0, a1, a2);
        case 0x043c24ULL: return fde_sub_043c24(a0, a1, a2);
        case 0x043d28ULL: return fde_sub_043d28(a0, a1, a2);
        case 0x043d48ULL: return fde_sub_043d48(a0, a1, a2);
        case 0x043e9cULL: return fde_sub_043e9c(a0, a1, a2);
        case 0x043ebcULL: return fde_sub_043ebc(a0, a1, a2);
        case 0x043f3cULL: return fde_sub_043f3c(a0, a1, a2);
        case 0x04400cULL: return fde_sub_04400c(a0, a1, a2);
        case 0x0440acULL: return fde_sub_0440ac(a0, a1, a2);
        case 0x044138ULL: return fde_sub_044138(a0, a1, a2);
        case 0x04429cULL: return fde_sub_04429c(a0, a1, a2);
        case 0x0442a4ULL: return fde_sub_0442a4(a0, a1, a2);
        case 0x044348ULL: return fde_sub_044348(a0, a1, a2);
        case 0x044710ULL: return fde_sub_044710(a0, a1, a2);
        case 0x044c30ULL: return fde_sub_044c30(a0, a1, a2);
        case 0x044cc4ULL: return fde_sub_044cc4(a0, a1, a2);
        case 0x044ce0ULL: return fde_sub_044ce0(a0, a1, a2);
        case 0x044da4ULL: return fde_sub_044da4(a0, a1, a2);
        case 0x044f1cULL: return fde_sub_044f1c(a0, a1, a2);
        case 0x045038ULL: return fde_sub_045038(a0, a1, a2);
        case 0x045080ULL: return fde_sub_045080(a0, a1, a2);
        case 0x045108ULL: return fde_sub_045108(a0, a1, a2);
        case 0x04516cULL: return fde_sub_04516c(a0, a1, a2);
        case 0x0451b0ULL: return fde_sub_0451b0(a0, a1, a2);
        case 0x0451f4ULL: return fde_sub_0451f4(a0, a1, a2);
        case 0x045238ULL: return fde_sub_045238(a0, a1, a2);
        case 0x04527cULL: return fde_sub_04527c(a0, a1, a2);
        case 0x045294ULL: return fde_sub_045294(a0, a1, a2);
        case 0x0452f4ULL: return fde_sub_0452f4(a0, a1, a2);
        case 0x0454fcULL: return fde_sub_0454fc(a0, a1, a2);
        case 0x0457bcULL: return fde_sub_0457bc(a0, a1, a2);
        case 0x045898ULL: return fde_sub_045898(a0, a1, a2);
        case 0x04595cULL: return fde_sub_04595c(a0, a1, a2);
        case 0x045a90ULL: return fde_sub_045a90(a0, a1, a2);
        case 0x045ad8ULL: return fde_sub_045ad8(a0, a1, a2);
        case 0x045b6cULL: return fde_sub_045b6c(a0, a1, a2);
        case 0x045c0cULL: return fde_sub_045c0c(a0, a1, a2);
        case 0x045c18ULL: return fde_sub_045c18(a0, a1, a2);
        case 0x046728ULL: return fde_sub_046728(a0, a1, a2);
        case 0x0469c4ULL: return fde_sub_0469c4(a0, a1, a2);
        case 0x046ad4ULL: return fde_sub_046ad4(a0, a1, a2);
        case 0x046b14ULL: return fde_sub_046b14(a0, a1, a2);
        case 0x046b58ULL: return fde_sub_046b58(a0, a1, a2);
        case 0x046c58ULL: return fde_sub_046c58(a0, a1, a2);
        case 0x046cb0ULL: return fde_sub_046cb0(a0, a1, a2);
        case 0x046cb8ULL: return fde_sub_046cb8(a0, a1, a2);
        case 0x046d50ULL: return fde_sub_046d50(a0, a1, a2);
        case 0x046d58ULL: return fde_sub_046d58(a0, a1, a2);
        case 0x046d60ULL: return fde_sub_046d60(a0, a1, a2);
        case 0x046f28ULL: return fde_sub_046f28(a0, a1, a2);
        case 0x04701cULL: return fde_sub_04701c(a0, a1, a2);
        case 0x047020ULL: return fde_sub_047020(a0, a1, a2);
        case 0x047024ULL: return fde_sub_047024(a0, a1, a2);
        case 0x047028ULL: return fde_sub_047028(a0, a1, a2);
        case 0x04702cULL: return fde_sub_04702c(a0, a1, a2);
        case 0x0470bcULL: return fde_sub_0470bc(a0, a1, a2);
        case 0x0472acULL: return fde_sub_0472ac(a0, a1, a2);
        case 0x047318ULL: return fde_sub_047318(a0, a1, a2);
        case 0x04734cULL: return fde_sub_04734c(a0, a1, a2);
        case 0x0474d4ULL: return fde_sub_0474d4(a0, a1, a2);
        case 0x0475d4ULL: return fde_sub_0475d4(a0, a1, a2);
        case 0x0475dcULL: return fde_sub_0475dc(a0, a1, a2);
        case 0x04765cULL: return fde_sub_04765c(a0, a1, a2);
        case 0x0476bcULL: return fde_sub_0476bc(a0, a1, a2);
        case 0x0477f0ULL: return fde_sub_0477f0(a0, a1, a2);
        case 0x0477f8ULL: return fde_sub_0477f8(a0, a1, a2);
        case 0x0478bcULL: return fde_sub_0478bc(a0, a1, a2);
        case 0x047950ULL: return fde_sub_047950(a0, a1, a2);
        case 0x047a98ULL: return fde_sub_047a98(a0, a1, a2);
        case 0x047b9cULL: return fde_sub_047b9c(a0, a1, a2);
        case 0x047d34ULL: return fde_sub_047d34(a0, a1, a2);
        case 0x047facULL: return fde_sub_047fac(a0, a1, a2);
        case 0x04813cULL: return fde_sub_04813c(a0, a1, a2);
        case 0x0482fcULL: return fde_sub_0482fc(a0, a1, a2);
        case 0x048468ULL: return fde_sub_048468(a0, a1, a2);
        case 0x048584ULL: return fde_sub_048584(a0, a1, a2);
        case 0x048634ULL: return fde_sub_048634(a0, a1, a2);
        case 0x048694ULL: return fde_sub_048694(a0, a1, a2);
        case 0x0486b8ULL: return fde_sub_0486b8(a0, a1, a2);
        case 0x0486c4ULL: return fde_sub_0486c4(a0, a1, a2);
        case 0x048734ULL: return fde_sub_048734(a0, a1, a2);
        case 0x048788ULL: return fde_sub_048788(a0, a1, a2);
        case 0x0487c8ULL: return fde_sub_0487c8(a0, a1, a2);
        case 0x048800ULL: return fde_sub_048800(a0, a1, a2);
        case 0x048808ULL: return fde_sub_048808(a0, a1, a2);
        case 0x0489c8ULL: return fde_sub_0489c8(a0, a1, a2);
        case 0x048b2cULL: return fde_sub_048b2c(a0, a1, a2);
        case 0x048c88ULL: return fde_sub_048c88(a0, a1, a2);
        case 0x048dd8ULL: return fde_sub_048dd8(a0, a1, a2);
        case 0x04907cULL: return fde_sub_04907c(a0, a1, a2);
        case 0x04915cULL: return fde_sub_04915c(a0, a1, a2);
        case 0x0491dcULL: return fde_sub_0491dc(a0, a1, a2);
        case 0x049254ULL: return fde_sub_049254(a0, a1, a2);
        case 0x04932cULL: return fde_sub_04932c(a0, a1, a2);
        case 0x0493ecULL: return fde_sub_0493ec(a0, a1, a2);
        case 0x0494c8ULL: return fde_sub_0494c8(a0, a1, a2);
        case 0x049518ULL: return fde_sub_049518(a0, a1, a2);
        case 0x049550ULL: return fde_sub_049550(a0, a1, a2);
        case 0x04957cULL: return fde_sub_04957c(a0, a1, a2);
        case 0x049580ULL: return fde_sub_049580(a0, a1, a2);
        case 0x0496b8ULL: return fde_sub_0496b8(a0, a1, a2);
        case 0x0497e0ULL: return fde_sub_0497e0(a0, a1, a2);
        case 0x0499ccULL: return fde_sub_0499cc(a0, a1, a2);
        case 0x049b5cULL: return fde_sub_049b5c(a0, a1, a2);
        case 0x049bd4ULL: return fde_sub_049bd4(a0, a1, a2);
        case 0x049c98ULL: return fde_sub_049c98(a0, a1, a2);
        case 0x049d60ULL: return fde_sub_049d60(a0, a1, a2);
        case 0x049dd4ULL: return fde_sub_049dd4(a0, a1, a2);
        case 0x049e4cULL: return fde_sub_049e4c(a0, a1, a2);
        case 0x049ec0ULL: return fde_sub_049ec0(a0, a1, a2);
        case 0x049fa8ULL: return fde_sub_049fa8(a0, a1, a2);
        case 0x04a0d8ULL: return fde_sub_04a0d8(a0, a1, a2);
        case 0x04a0f4ULL: return fde_sub_04a0f4(a0, a1, a2);
        case 0x04a198ULL: return fde_sub_04a198(a0, a1, a2);
        case 0x04a284ULL: return fde_sub_04a284(a0, a1, a2);
        case 0x04a2d0ULL: return fde_sub_04a2d0(a0, a1, a2);
        case 0x04a3acULL: return fde_sub_04a3ac(a0, a1, a2);
        case 0x04a494ULL: return fde_sub_04a494(a0, a1, a2);
        case 0x04a678ULL: return fde_sub_04a678(a0, a1, a2);
        case 0x04a794ULL: return fde_sub_04a794(a0, a1, a2);
        case 0x04a908ULL: return fde_sub_04a908(a0, a1, a2);
        case 0x04a9a8ULL: return fde_sub_04a9a8(a0, a1, a2);
        case 0x04aa10ULL: return fde_sub_04aa10(a0, a1, a2);
        case 0x04ab08ULL: return fde_sub_04ab08(a0, a1, a2);
        case 0x04ab10ULL: return fde_sub_04ab10(a0, a1, a2);
        case 0x04aba8ULL: return fde_sub_04aba8(a0, a1, a2);
        case 0x04abd4ULL: return fde_sub_04abd4(a0, a1, a2);
        case 0x04abf0ULL: return fde_sub_04abf0(a0, a1, a2);
        case 0x04ac10ULL: return fde_sub_04ac10(a0, a1, a2);
        case 0x04ac2cULL: return fde_sub_04ac2c(a0, a1, a2);
        case 0x04ac48ULL: return fde_sub_04ac48(a0, a1, a2);
        case 0x04acdcULL: return fde_sub_04acdc(a0, a1, a2);
        case 0x04ad98ULL: return fde_sub_04ad98(a0, a1, a2);
        case 0x04ae38ULL: return fde_sub_04ae38(a0, a1, a2);
        case 0x04aee4ULL: return fde_sub_04aee4(a0, a1, a2);
        case 0x04aef8ULL: return fde_sub_04aef8(a0, a1, a2);
        case 0x04af3cULL: return fde_sub_04af3c(a0, a1, a2);
        case 0x04af80ULL: return fde_sub_04af80(a0, a1, a2);
        case 0x04b084ULL: return fde_sub_04b084(a0, a1, a2);
        case 0x04b094ULL: return fde_sub_04b094(a0, a1, a2);
        case 0x04b0c4ULL: return fde_sub_04b0c4(a0, a1, a2);
        case 0x04b330ULL: return fde_sub_04b330(a0, a1, a2);
        case 0x04b474ULL: return fde_sub_04b474(a0, a1, a2);
        case 0x04b490ULL: return fde_sub_04b490(a0, a1, a2);
        case 0x04b49cULL: return fde_sub_04b49c(a0, a1, a2);
        case 0x04b4a8ULL: return fde_sub_04b4a8(a0, a1, a2);
        case 0x04b5c4ULL: return fde_sub_04b5c4(a0, a1, a2);
        case 0x04b5dcULL: return fde_sub_04b5dc(a0, a1, a2);
        case 0x04b6fcULL: return fde_sub_04b6fc(a0, a1, a2);
        case 0x04baccULL: return fde_sub_04bacc(a0, a1, a2);
        case 0x04be0cULL: return fde_sub_04be0c(a0, a1, a2);
        case 0x04bf84ULL: return fde_sub_04bf84(a0, a1, a2);
        case 0x04c084ULL: return fde_sub_04c084(a0, a1, a2);
        case 0x04c534ULL: return fde_sub_04c534(a0, a1, a2);
        case 0x04c570ULL: return fde_sub_04c570(a0, a1, a2);
        case 0x04c5acULL: return fde_sub_04c5ac(a0, a1, a2);
        case 0x04c878ULL: return fde_sub_04c878(a0, a1, a2);
        case 0x04c98cULL: return fde_sub_04c98c(a0, a1, a2);
        case 0x04cb94ULL: return fde_sub_04cb94(a0, a1, a2);
        case 0x04cc98ULL: return fde_sub_04cc98(a0, a1, a2);
        case 0x04d2ccULL: return fde_sub_04d2cc(a0, a1, a2);
        case 0x04d3b8ULL: return fde_sub_04d3b8(a0, a1, a2);
        case 0x04d4a8ULL: return fde_sub_04d4a8(a0, a1, a2);
        case 0x04d534ULL: return fde_sub_04d534(a0, a1, a2);
        case 0x04d61cULL: return fde_sub_04d61c(a0, a1, a2);
        case 0x04d6dcULL: return fde_sub_04d6dc(a0, a1, a2);
        case 0x04d6e4ULL: return fde_sub_04d6e4(a0, a1, a2);
        case 0x04d6ecULL: return fde_sub_04d6ec(a0, a1, a2);
        case 0x04d7b4ULL: return fde_sub_04d7b4(a0, a1, a2);
        case 0x04d858ULL: return fde_sub_04d858(a0, a1, a2);
        case 0x04e50cULL: return fde_sub_04e50c(a0, a1, a2);
        case 0x04e63cULL: return fde_sub_04e63c(a0, a1, a2);
        case 0x04e668ULL: return fde_sub_04e668(a0, a1, a2);
        case 0x04ec7cULL: return fde_sub_04ec7c(a0, a1, a2);
        case 0x04ed20ULL: return fde_sub_04ed20(a0, a1, a2);
        case 0x04ee94ULL: return fde_sub_04ee94(a0, a1, a2);
        case 0x04f184ULL: return fde_sub_04f184(a0, a1, a2);
        case 0x04f194ULL: return fde_sub_04f194(a0, a1, a2);
        case 0x04f21cULL: return fde_sub_04f21c(a0, a1, a2);
        case 0x04f44cULL: return fde_sub_04f44c(a0, a1, a2);
        case 0x04f65cULL: return fde_sub_04f65c(a0, a1, a2);
        case 0x04f7d4ULL: return fde_sub_04f7d4(a0, a1, a2);
        case 0x04f7dcULL: return fde_sub_04f7dc(a0, a1, a2);
        case 0x04f930ULL: return fde_sub_04f930(a0, a1, a2);
        case 0x04fa84ULL: return fde_sub_04fa84(a0, a1, a2);
        case 0x04fa94ULL: return fde_sub_04fa94(a0, a1, a2);
        case 0x04fb38ULL: return fde_sub_04fb38(a0, a1, a2);
        case 0x04fbd8ULL: return fde_sub_04fbd8(a0, a1, a2);
        case 0x04fbe4ULL: return fde_sub_04fbe4(a0, a1, a2);
        case 0x04ff34ULL: return fde_sub_04ff34(a0, a1, a2);
        case 0x050040ULL: return fde_sub_050040(a0, a1, a2);
        case 0x0504ccULL: return fde_sub_0504cc(a0, a1, a2);
        case 0x050644ULL: return fde_sub_050644(a0, a1, a2);
        case 0x05075cULL: return fde_sub_05075c(a0, a1, a2);
        case 0x050a4cULL: return fde_sub_050a4c(a0, a1, a2);
        case 0x050b90ULL: return fde_sub_050b90(a0, a1, a2);
        case 0x050c30ULL: return fde_sub_050c30(a0, a1, a2);
        case 0x050d50ULL: return fde_sub_050d50(a0, a1, a2);
        case 0x050e94ULL: return fde_sub_050e94(a0, a1, a2);
        case 0x050ffcULL: return fde_sub_050ffc(a0, a1, a2);
        case 0x051418ULL: return fde_sub_051418(a0, a1, a2);
        case 0x05147cULL: return fde_sub_05147c(a0, a1, a2);
        case 0x0514e0ULL: return fde_sub_0514e0(a0, a1, a2);
        case 0x051584ULL: return fde_sub_051584(a0, a1, a2);
        case 0x051628ULL: return fde_sub_051628(a0, a1, a2);
        case 0x0516e0ULL: return fde_sub_0516e0(a0, a1, a2);
        case 0x0517bcULL: return fde_sub_0517bc(a0, a1, a2);
        case 0x051b20ULL: return fde_sub_051b20(a0, a1, a2);
        case 0x051b84ULL: return fde_sub_051b84(a0, a1, a2);
        case 0x051b90ULL: return fde_sub_051b90(a0, a1, a2);
        case 0x051b9cULL: return fde_sub_051b9c(a0, a1, a2);
        case 0x051d2cULL: return fde_sub_051d2c(a0, a1, a2);
        case 0x051db8ULL: return fde_sub_051db8(a0, a1, a2);
        case 0x051f44ULL: return fde_sub_051f44(a0, a1, a2);
        case 0x051fe4ULL: return fde_sub_051fe4(a0, a1, a2);
        case 0x052138ULL: return fde_sub_052138(a0, a1, a2);
        case 0x05216cULL: return fde_sub_05216c(a0, a1, a2);
        case 0x052258ULL: return fde_sub_052258(a0, a1, a2);
        case 0x052750ULL: return fde_sub_052750(a0, a1, a2);
        case 0x0527d8ULL: return fde_sub_0527d8(a0, a1, a2);
        case 0x0528ccULL: return fde_sub_0528cc(a0, a1, a2);
        case 0x052978ULL: return fde_sub_052978(a0, a1, a2);
        case 0x052aecULL: return fde_sub_052aec(a0, a1, a2);
        case 0x052bf0ULL: return fde_sub_052bf0(a0, a1, a2);
        case 0x052bf8ULL: return fde_sub_052bf8(a0, a1, a2);
        case 0x052e18ULL: return fde_sub_052e18(a0, a1, a2);
        case 0x052f60ULL: return fde_sub_052f60(a0, a1, a2);
        case 0x053004ULL: return fde_sub_053004(a0, a1, a2);
        case 0x05333cULL: return fde_sub_05333c(a0, a1, a2);
        case 0x053394ULL: return fde_sub_053394(a0, a1, a2);
        case 0x05346cULL: return fde_sub_05346c(a0, a1, a2);
        case 0x05376cULL: return fde_sub_05376c(a0, a1, a2);
        case 0x05389cULL: return fde_sub_05389c(a0, a1, a2);
        case 0x05399cULL: return fde_sub_05399c(a0, a1, a2);
        case 0x053a6cULL: return fde_sub_053a6c(a0, a1, a2);
        case 0x053b70ULL: return fde_sub_053b70(a0, a1, a2);
        case 0x053be4ULL: return fde_sub_053be4(a0, a1, a2);
        case 0x053c6cULL: return fde_sub_053c6c(a0, a1, a2);
        case 0x053c90ULL: return fde_sub_053c90(a0, a1, a2);
        case 0x053d0cULL: return fde_sub_053d0c(a0, a1, a2);
        case 0x053ea4ULL: return fde_sub_053ea4(a0, a1, a2);
        case 0x053fd4ULL: return fde_sub_053fd4(a0, a1, a2);
        case 0x05402cULL: return fde_sub_05402c(a0, a1, a2);
        case 0x054124ULL: return fde_sub_054124(a0, a1, a2);
        case 0x0541e0ULL: return fde_sub_0541e0(a0, a1, a2);
        case 0x054228ULL: return fde_sub_054228(a0, a1, a2);
        case 0x054284ULL: return fde_sub_054284(a0, a1, a2);
        case 0x054478ULL: return fde_sub_054478(a0, a1, a2);
        case 0x05455cULL: return fde_sub_05455c(a0, a1, a2);
        case 0x05492cULL: return fde_sub_05492c(a0, a1, a2);
        case 0x054a70ULL: return fde_sub_054a70(a0, a1, a2);
        case 0x054b48ULL: return fde_sub_054b48(a0, a1, a2);
        case 0x054b70ULL: return fde_sub_054b70(a0, a1, a2);
        case 0x054b7cULL: return fde_sub_054b7c(a0, a1, a2);
        case 0x054b88ULL: return fde_sub_054b88(a0, a1, a2);
        case 0x054b8cULL: return fde_sub_054b8c(a0, a1, a2);
        case 0x054bd0ULL: return fde_sub_054bd0(a0, a1, a2);
        case 0x054be8ULL: return fde_sub_054be8(a0, a1, a2);
        case 0x054c24ULL: return fde_sub_054c24(a0, a1, a2);
        case 0x054c64ULL: return fde_sub_054c64(a0, a1, a2);
        case 0x054e18ULL: return fde_sub_054e18(a0, a1, a2);
        case 0x054f78ULL: return fde_sub_054f78(a0, a1, a2);
        case 0x0552e8ULL: return fde_sub_0552e8(a0, a1, a2);
        case 0x05538cULL: return fde_sub_05538c(a0, a1, a2);
        case 0x0553f4ULL: return fde_sub_0553f4(a0, a1, a2);
        case 0x05567cULL: return fde_sub_05567c(a0, a1, a2);
        case 0x05570cULL: return fde_sub_05570c(a0, a1, a2);
        case 0x055744ULL: return fde_sub_055744(a0, a1, a2);
        case 0x055874ULL: return fde_sub_055874(a0, a1, a2);
        case 0x0558d8ULL: return fde_sub_0558d8(a0, a1, a2);
        case 0x05592cULL: return fde_sub_05592c(a0, a1, a2);
        case 0x055a78ULL: return fde_sub_055a78(a0, a1, a2);
        case 0x055b04ULL: return fde_sub_055b04(a0, a1, a2);
        case 0x055b38ULL: return fde_sub_055b38(a0, a1, a2);
        case 0x055c34ULL: return fde_sub_055c34(a0, a1, a2);
        case 0x055c3cULL: return fde_sub_055c3c(a0, a1, a2);
        case 0x055c44ULL: return fde_sub_055c44(a0, a1, a2);
        case 0x055d0cULL: return fde_sub_055d0c(a0, a1, a2);
        case 0x055f34ULL: return fde_sub_055f34(a0, a1, a2);
        case 0x056078ULL: return fde_sub_056078(a0, a1, a2);
        case 0x056260ULL: return fde_sub_056260(a0, a1, a2);
        case 0x0562f8ULL: return fde_sub_0562f8(a0, a1, a2);
        case 0x056348ULL: return fde_sub_056348(a0, a1, a2);
        case 0x056388ULL: return fde_sub_056388(a0, a1, a2);
        case 0x056394ULL: return fde_sub_056394(a0, a1, a2);
        case 0x0563b0ULL: return fde_sub_0563b0(a0, a1, a2);
        case 0x0563f0ULL: return fde_sub_0563f0(a0, a1, a2);
        case 0x05640cULL: return fde_sub_05640c(a0, a1, a2);
        case 0x056428ULL: return fde_sub_056428(a0, a1, a2);
        case 0x056488ULL: return fde_sub_056488(a0, a1, a2);
        case 0x0564fcULL: return fde_sub_0564fc(a0, a1, a2);
        case 0x056618ULL: return fde_sub_056618(a0, a1, a2);
        case 0x056710ULL: return fde_sub_056710(a0, a1, a2);
        case 0x0567c4ULL: return fde_sub_0567c4(a0, a1, a2);
        case 0x0568ecULL: return fde_sub_0568ec(a0, a1, a2);
        case 0x056a1cULL: return fde_sub_056a1c(a0, a1, a2);
        case 0x056a4cULL: return fde_sub_056a4c(a0, a1, a2);
        case 0x056af0ULL: return fde_sub_056af0(a0, a1, a2);
        default: return 0ULL;
    }
}

} // namespace TTKMediaNet
