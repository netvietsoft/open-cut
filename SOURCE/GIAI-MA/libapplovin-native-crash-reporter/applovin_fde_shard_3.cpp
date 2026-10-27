// ============================================================================
// File: applovin_fde_shard_3.cpp
// Target 110 / 169: libapplovin-native-crash-reporter.so (860,200 bytes)
// EN: Clean-room C++17 AArch64 FDE Shard 3/5 covering FDEs [704..1055]
//     (PC range 0x0900dc .. 0x0a00d0).
// VI: Phân mảnh FDE AArch64 C++17 3/5 bao phủ FDE [704..1055]
//     (Dải địa chỉ PC 0x0900dc .. 0x0a00d0).
// ============================================================================
#include "applovin_crash_reporter.h"

namespace applovin {

// FDE #0704 | PC: 0x0900dc..0x090188 (172 B) | Symbol: _ZNKSt6__ndk15ctypeIcE10do_toupperEc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0900dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0900DCULL;
}

// FDE #0705 | PC: 0x090188..0x090264 (220 B) | Symbol: _ZNKSt6__ndk15ctypeIcE10do_toupperEPcPKc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_090188(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090188ULL;
}

// FDE #0706 | PC: 0x090264..0x090310 (172 B) | Symbol: _ZNKSt6__ndk15ctypeIcE10do_tolowerEc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_090264(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090264ULL;
}

// FDE #0707 | PC: 0x090310..0x0903ec (220 B) | Symbol: _ZNKSt6__ndk15ctypeIcE10do_tolowerEPcPKc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_090310(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090310ULL;
}

// FDE #0708 | PC: 0x0903ec..0x0903f8 (12 B) | Symbol: _ZNKSt6__ndk15ctypeIcE8do_widenEc
// EN: AArch64 prologue [bti c; mov w0, w1; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, w1; ret]
uint64_t fde_sub_0903ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A0103E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0903ECULL;
}

// FDE #0709 | PC: 0x0903f8..0x0904c4 (204 B) | Symbol: _ZNKSt6__ndk15ctypeIcE8do_widenEPKcS3_Pc
// EN: AArch64 prologue [bti c; mov x0, x1; cmp x1, x2; b.eq #0x904c0] | VI: Khởi đầu hàm AArch64 [bti c; mov x0, x1; cmp x1, x2; b.eq #0x904c0]
uint64_t fde_sub_0903f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0903F8ULL;
}

// FDE #0710 | PC: 0x0904c4..0x0904d8 (20 B) | Symbol: _ZNKSt6__ndk15ctypeIcE9do_narrowEcc
// EN: AArch64 prologue [bti c; sxtb w8, w1; cmp w8, #0; csel w0, w2, w1, lt] | VI: Khởi đầu hàm AArch64 [bti c; sxtb w8, w1; cmp w8, #0; csel w0, w2, w1, lt]
uint64_t fde_sub_0904c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x13001C28ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0904C4ULL;
}

// FDE #0711 | PC: 0x0904d8..0x0905b8 (224 B) | Symbol: _ZNKSt6__ndk15ctypeIcE9do_narrowEPKcS3_cPc
// EN: AArch64 prologue [bti c; mov x0, x1; cmp x1, x2; b.eq #0x905b4] | VI: Khởi đầu hàm AArch64 [bti c; mov x0, x1; cmp x1, x2; b.eq #0x905b4]
uint64_t fde_sub_0904d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0904D8ULL;
}

// FDE #0712 | PC: 0x0905b8..0x090760 (424 B) | Symbol: _ZNSt6__ndk112ctype_bynameIcEC1EPKcm
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; str x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; str x23, [sp, #0x50]]
uint64_t fde_sub_0905b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0905B8ULL;
}

// FDE #0713 | PC: 0x090760..0x090870 (272 B) | Symbol: _ZNSt6__ndk112ctype_bynameIcEC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEm
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_090760(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0110ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090760ULL;
}

// FDE #0714 | PC: 0x090870..0x0908f0 (128 B) | Symbol: _ZNSt6__ndk112ctype_bynameIcED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_090870(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090870ULL;
}

// FDE #0715 | PC: 0x0908f0..0x090918 (40 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIcE10do_toupperEc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0, #0x20]]
uint64_t fde_sub_0908f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0908F0ULL;
}

// FDE #0716 | PC: 0x090918..0x090974 (92 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIcE10do_toupperEPcPKc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_090918(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090918ULL;
}

// FDE #0717 | PC: 0x090974..0x09099c (40 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIcE10do_tolowerEc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0, #0x20]]
uint64_t fde_sub_090974(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090974ULL;
}

// FDE #0718 | PC: 0x09099c..0x0909f8 (92 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIcE10do_tolowerEPcPKc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_09099c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09099CULL;
}

// FDE #0719 | PC: 0x0909f8..0x090b6c (372 B) | Symbol: _ZNSt6__ndk112ctype_bynameIwEC2EPKcm
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; str x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; str x23, [sp, #0x50]]
uint64_t fde_sub_0909f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0174ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0909F8ULL;
}

// FDE #0720 | PC: 0x090b6c..0x090c48 (220 B) | Symbol: _ZNSt6__ndk112ctype_bynameIwEC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEm
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_090b6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090B6CULL;
}

// FDE #0721 | PC: 0x090c48..0x090ca4 (92 B) | Symbol: _ZNSt6__ndk112ctype_bynameIwED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_090c48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090C48ULL;
}

// FDE #0722 | PC: 0x090ca4..0x090e1c (376 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIwE5do_isEmw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_090ca4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090CA4ULL;
}

// FDE #0723 | PC: 0x090e1c..0x090fb8 (412 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIwE5do_isEPKwS3_Pm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_090e1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x019CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090E1CULL;
}

// FDE #0724 | PC: 0x090fb8..0x0910e8 (304 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIwE10do_scan_isEmPKwS3_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_090fb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090FB8ULL;
}

// FDE #0725 | PC: 0x0910e8..0x091218 (304 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIwE11do_scan_notEmPKwS3_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0910e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0910E8ULL;
}

// FDE #0726 | PC: 0x091218..0x09122c (20 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIwE10do_toupperEw
// EN: AArch64 prologue [bti c; ldr x8, [x0, #0x10]; mov w0, w1; mov x1, x8] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0, #0x10]; mov w0, w1; mov x1, x8]
uint64_t fde_sub_091218(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400808ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091218ULL;
}

// FDE #0727 | PC: 0x09122c..0x091288 (92 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIwE10do_toupperEPwPKw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_09122c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09122CULL;
}

// FDE #0728 | PC: 0x091288..0x09129c (20 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIwE10do_tolowerEw
// EN: AArch64 prologue [bti c; ldr x8, [x0, #0x10]; mov w0, w1; mov x1, x8] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0, #0x10]; mov w0, w1; mov x1, x8]
uint64_t fde_sub_091288(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400808ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091288ULL;
}

// FDE #0729 | PC: 0x09129c..0x0912f8 (92 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIwE10do_tolowerEPwPKw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_09129c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09129CULL;
}

// FDE #0730 | PC: 0x0912f8..0x091364 (108 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIwE8do_widenEc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0912f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0912F8ULL;
}

// FDE #0731 | PC: 0x091364..0x091414 (176 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIwE8do_widenEPKcS3_Pw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_091364(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091364ULL;
}

// FDE #0732 | PC: 0x091414..0x091490 (124 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIwE9do_narrowEwc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_091414(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091414ULL;
}

// FDE #0733 | PC: 0x091490..0x091554 (196 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIwE9do_narrowEPKwS3_cPc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_091490(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091490ULL;
}

// FDE #0734 | PC: 0x091554..0x091580 (44 B) | Symbol: _ZNSt6__ndk17codecvtIcc9mbstate_tED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_091554(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091554ULL;
}

// FDE #0735 | PC: 0x091580..0x091594 (20 B) | Symbol: _ZNKSt6__ndk17codecvtIcc9mbstate_tE6do_outERS1_PKcS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [bti c; mov w0, #3; str x2, [x4]; str x5, [x7]] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #3; str x2, [x4]; str x5, [x7]]
uint64_t fde_sub_091580(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800060ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091580ULL;
}

// FDE #0736 | PC: 0x091594..0x0915a8 (20 B) | Symbol: _ZNKSt6__ndk17codecvtIcc9mbstate_tE5do_inERS1_PKcS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [bti c; mov w0, #3; str x2, [x4]; str x5, [x7]] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #3; str x2, [x4]; str x5, [x7]]
uint64_t fde_sub_091594(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800060ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091594ULL;
}

// FDE #0737 | PC: 0x0915a8..0x0915b8 (16 B) | Symbol: _ZNKSt6__ndk17codecvtIcc9mbstate_tE10do_unshiftERS1_PcS4_RS4_
// EN: AArch64 prologue [bti c; mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_0915a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800060ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0915A8ULL;
}

// FDE #0738 | PC: 0x0915b8..0x0915c4 (12 B) | Symbol: _ZNKSt6__ndk17codecvtIcc9mbstate_tE11do_encodingEv
// EN: AArch64 prologue [bti c; mov w0, #1; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #1; ret]
uint64_t fde_sub_0915b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800020ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0915B8ULL;
}

// FDE #0739 | PC: 0x0915c4..0x0915d0 (12 B) | Symbol: _ZNKSt6__ndk17codecvtIcc9mbstate_tE16do_always_noconvEv
// EN: AArch64 prologue [bti c; mov w0, #1; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #1; ret]
uint64_t fde_sub_0915c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800020ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0915C4ULL;
}

// FDE #0740 | PC: 0x0915d0..0x0915e4 (20 B) | Symbol: _ZNKSt6__ndk17codecvtIcc9mbstate_tE9do_lengthERS1_PKcS5_m
// EN: AArch64 prologue [bti c; sub x8, x3, x2; cmp x8, x4; csel w0, w8, w4, lo] | VI: Khởi đầu hàm AArch64 [bti c; sub x8, x3, x2; cmp x8, x4; csel w0, w8, w4, lo]
uint64_t fde_sub_0915d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xCB020068ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0915D0ULL;
}

// FDE #0741 | PC: 0x0915e4..0x0915f0 (12 B) | Symbol: _ZNKSt6__ndk17codecvtIcc9mbstate_tE13do_max_lengthEv
// EN: AArch64 prologue [bti c; mov w0, #1; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #1; ret]
uint64_t fde_sub_0915e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800020ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0915E4ULL;
}

// FDE #0742 | PC: 0x0915f0..0x09169c (172 B) | Symbol: _ZNSt6__ndk17codecvtIwc9mbstate_tEC2Em
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0915f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0915F0ULL;
}

// FDE #0743 | PC: 0x09169c..0x091810 (372 B) | Symbol: _ZNSt6__ndk17codecvtIwc9mbstate_tEC2EPKcm
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; str x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; str x23, [sp, #0x50]]
uint64_t fde_sub_09169c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0174ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09169CULL;
}

// FDE #0744 | PC: 0x091810..0x09183c (44 B) | Symbol: _ZNSt6__ndk17codecvtIwc9mbstate_tED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_091810(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091810ULL;
}

// FDE #0745 | PC: 0x09183c..0x091b84 (840 B) | Symbol: _ZNKSt6__ndk17codecvtIwc9mbstate_tE6do_outERS1_PKwS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xa0; stp x29, x30, [sp, #0x40]; stp x28, x27, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xa0; stp x29, x30, [sp, #0x40]; stp x28, x27, [sp, #0x50]]
uint64_t fde_sub_09183c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10283FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0348ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09183CULL;
}

// FDE #0746 | PC: 0x091b84..0x091ea4 (800 B) | Symbol: _ZNKSt6__ndk17codecvtIwc9mbstate_tE5do_inERS1_PKcS5_RS5_PwS7_RS7_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x30]; stp x28, x27, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x30]; stp x28, x27, [sp, #0x40]]
uint64_t fde_sub_091b84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10243FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0320ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091B84ULL;
}

// FDE #0747 | PC: 0x091ea4..0x091fcc (296 B) | Symbol: _ZNKSt6__ndk17codecvtIwc9mbstate_tE10do_unshiftERS1_PcS4_RS4_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]]
uint64_t fde_sub_091ea4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0128ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091EA4ULL;
}

// FDE #0748 | PC: 0x091fcc..0x0920a8 (220 B) | Symbol: _ZNKSt6__ndk17codecvtIwc9mbstate_tE11do_encodingEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_091fcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091FCCULL;
}

// FDE #0749 | PC: 0x0920a8..0x0920b4 (12 B) | Symbol: _ZNKSt6__ndk17codecvtIwc9mbstate_tE16do_always_noconvEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_0920a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0920A8ULL;
}

// FDE #0750 | PC: 0x0920b4..0x0921b0 (252 B) | Symbol: _ZNKSt6__ndk17codecvtIwc9mbstate_tE9do_lengthERS1_PKcS5_m
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_0920b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0920B4ULL;
}

// FDE #0751 | PC: 0x0921b0..0x092228 (120 B) | Symbol: _ZNKSt6__ndk17codecvtIwc9mbstate_tE13do_max_lengthEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0921b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0921B0ULL;
}

// FDE #0752 | PC: 0x092228..0x092254 (44 B) | Symbol: _ZNSt6__ndk17codecvtIDsc9mbstate_tED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_092228(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092228ULL;
}

// FDE #0753 | PC: 0x092254..0x0922ec (152 B) | Symbol: _ZNKSt6__ndk17codecvtIDsc9mbstate_tE6do_outERS1_PKDsS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_092254(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092254ULL;
}

// FDE #0754 | PC: 0x0922ec..0x09250c (544 B) | Symbol: sub_0922ec
// EN: AArch64 prologue [bti c; str x0, [x2]; str x3, [x5]; tbz w7, #1, #0x92348] | VI: Khởi đầu hàm AArch64 [bti c; str x0, [x2]; str x3, [x5]; tbz w7, #1, #0x92348]
uint64_t fde_sub_0922ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000040ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0220ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0922ECULL;
}

// FDE #0755 | PC: 0x09250c..0x0925a4 (152 B) | Symbol: _ZNKSt6__ndk17codecvtIDsc9mbstate_tE5do_inERS1_PKcS5_RS5_PDsS7_RS7_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_09250c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09250CULL;
}

// FDE #0756 | PC: 0x0925a4..0x092820 (636 B) | Symbol: sub_0925a4
// EN: AArch64 prologue [bti c; str x0, [x2]; str x3, [x5]; ldr x12, [x2]] | VI: Khởi đầu hàm AArch64 [bti c; str x0, [x2]; str x3, [x5]; ldr x12, [x2]]
uint64_t fde_sub_0925a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000040ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x027CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0925A4ULL;
}

// FDE #0757 | PC: 0x092820..0x092830 (16 B) | Symbol: _ZNKSt6__ndk17codecvtIDsc9mbstate_tE10do_unshiftERS1_PcS4_RS4_
// EN: AArch64 prologue [bti c; mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_092820(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800060ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092820ULL;
}

// FDE #0758 | PC: 0x092830..0x09283c (12 B) | Symbol: _ZNKSt6__ndk17codecvtIDsc9mbstate_tE11do_encodingEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_092830(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092830ULL;
}

// FDE #0759 | PC: 0x09283c..0x092848 (12 B) | Symbol: _ZNKSt6__ndk17codecvtIDsc9mbstate_tE16do_always_noconvEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_09283c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09283CULL;
}

// FDE #0760 | PC: 0x092848..0x092864 (28 B) | Symbol: _ZNKSt6__ndk17codecvtIDsc9mbstate_tE9do_lengthERS1_PKcS5_m
// EN: AArch64 prologue [bti c; mov x1, x3; mov w3, #0x10ffff; mov x0, x2] | VI: Khởi đầu hàm AArch64 [bti c; mov x1, x3; mov w3, #0x10ffff; mov x0, x2]
uint64_t fde_sub_092848(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0303E1ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092848ULL;
}

// FDE #0761 | PC: 0x092864..0x092a64 (512 B) | Symbol: sub_092864
// EN: AArch64 prologue [bti c; mov x8, x0; tbz w4, #2, #0x928b0; sub x8, x1, x0] | VI: Khởi đầu hàm AArch64 [bti c; mov x8, x0; tbz w4, #2, #0x928b0; sub x8, x1, x0]
uint64_t fde_sub_092864(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003E8ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0200ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092864ULL;
}

// FDE #0762 | PC: 0x092a64..0x092a70 (12 B) | Symbol: _ZNKSt6__ndk17codecvtIDsc9mbstate_tE13do_max_lengthEv
// EN: AArch64 prologue [bti c; mov w0, #4; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #4; ret]
uint64_t fde_sub_092a64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800080ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092A64ULL;
}

// FDE #0763 | PC: 0x092a70..0x092a9c (44 B) | Symbol: _ZNSt6__ndk17codecvtIDic9mbstate_tED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_092a70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092A70ULL;
}

// FDE #0764 | PC: 0x092a9c..0x092b34 (152 B) | Symbol: _ZNKSt6__ndk17codecvtIDic9mbstate_tE6do_outERS1_PKDiS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_092a9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092A9CULL;
}

// FDE #0765 | PC: 0x092b34..0x092cb8 (388 B) | Symbol: sub_092b34
// EN: AArch64 prologue [bti c; str x0, [x2]; str x3, [x5]; tbz w7, #1, #0x92b90] | VI: Khởi đầu hàm AArch64 [bti c; str x0, [x2]; str x3, [x5]; tbz w7, #1, #0x92b90]
uint64_t fde_sub_092b34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000040ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0184ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092B34ULL;
}

// FDE #0766 | PC: 0x092cb8..0x092d50 (152 B) | Symbol: _ZNKSt6__ndk17codecvtIDic9mbstate_tE5do_inERS1_PKcS5_RS5_PDiS7_RS7_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_092cb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092CB8ULL;
}

// FDE #0767 | PC: 0x092d50..0x092f88 (568 B) | Symbol: sub_092d50
// EN: AArch64 prologue [bti c; str x0, [x2]; str x3, [x5]; ldr x8, [x2]] | VI: Khởi đầu hàm AArch64 [bti c; str x0, [x2]; str x3, [x5]; ldr x8, [x2]]
uint64_t fde_sub_092d50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000040ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0238ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092D50ULL;
}

// FDE #0768 | PC: 0x092f88..0x092f98 (16 B) | Symbol: _ZNKSt6__ndk17codecvtIDic9mbstate_tE10do_unshiftERS1_PcS4_RS4_
// EN: AArch64 prologue [bti c; mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_092f88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800060ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092F88ULL;
}

// FDE #0769 | PC: 0x092f98..0x092fa4 (12 B) | Symbol: _ZNKSt6__ndk17codecvtIDic9mbstate_tE11do_encodingEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_092f98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092F98ULL;
}

// FDE #0770 | PC: 0x092fa4..0x092fb0 (12 B) | Symbol: _ZNKSt6__ndk17codecvtIDic9mbstate_tE16do_always_noconvEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_092fa4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092FA4ULL;
}

// FDE #0771 | PC: 0x092fb0..0x092fcc (28 B) | Symbol: _ZNKSt6__ndk17codecvtIDic9mbstate_tE9do_lengthERS1_PKcS5_m
// EN: AArch64 prologue [bti c; mov x1, x3; mov w3, #0x10ffff; mov x0, x2] | VI: Khởi đầu hàm AArch64 [bti c; mov x1, x3; mov w3, #0x10ffff; mov x0, x2]
uint64_t fde_sub_092fb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0303E1ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092FB0ULL;
}

// FDE #0772 | PC: 0x092fcc..0x0931c8 (508 B) | Symbol: sub_092fcc
// EN: AArch64 prologue [bti c; mov x8, x0; tbz w4, #2, #0x93018; sub x8, x1, x0] | VI: Khởi đầu hàm AArch64 [bti c; mov x8, x0; tbz w4, #2, #0x93018; sub x8, x1, x0]
uint64_t fde_sub_092fcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003E8ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x01FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092FCCULL;
}

// FDE #0773 | PC: 0x0931c8..0x0931d4 (12 B) | Symbol: _ZNKSt6__ndk17codecvtIDic9mbstate_tE13do_max_lengthEv
// EN: AArch64 prologue [bti c; mov w0, #4; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #4; ret]
uint64_t fde_sub_0931c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800080ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0931C8ULL;
}

// FDE #0774 | PC: 0x0931d4..0x093270 (156 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IwE6do_outER9mbstate_tPKwS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_0931d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0931D4ULL;
}

// FDE #0775 | PC: 0x093270..0x09330c (156 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IwE5do_inER9mbstate_tPKcS5_RS5_PwS7_RS7_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_093270(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093270ULL;
}

// FDE #0776 | PC: 0x09330c..0x09331c (16 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IwE10do_unshiftER9mbstate_tPcS4_RS4_
// EN: AArch64 prologue [bti c; mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_09330c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800060ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09330CULL;
}

// FDE #0777 | PC: 0x09331c..0x093328 (12 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IwE11do_encodingEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_09331c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09331CULL;
}

// FDE #0778 | PC: 0x093328..0x093334 (12 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IwE16do_always_noconvEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_093328(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093328ULL;
}

// FDE #0779 | PC: 0x093334..0x093354 (32 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IwE9do_lengthER9mbstate_tPKcS5_m
// EN: AArch64 prologue [bti c; mov x8, x4; mov x1, x3; ldr x3, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [bti c; mov x8, x4; mov x1, x3; ldr x3, [x0, #0x18]]
uint64_t fde_sub_093334(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0403E8ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093334ULL;
}

// FDE #0780 | PC: 0x093354..0x093370 (28 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IwE13do_max_lengthEv
// EN: AArch64 prologue [bti c; ldrb w8, [x0, #0x20]; mov w9, #7; tst w8, #4] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w8, [x0, #0x20]; mov w9, #7; tst w8, #4]
uint64_t fde_sub_093354(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39408008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093354ULL;
}

// FDE #0781 | PC: 0x093370..0x093478 (264 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IDsE6do_outER9mbstate_tPKDsS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [bti c; ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #1, #0x933ac] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #1, #0x933ac]
uint64_t fde_sub_093370(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39406009ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0108ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093370ULL;
}

// FDE #0782 | PC: 0x093478..0x09360c (404 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IDsE5do_inER9mbstate_tPKcS5_RS5_PDsS7_RS7_
// EN: AArch64 prologue [bti c; ldrb w8, [x0, #0x18]; tbz w8, #2, #0x934b8; sub x8, x3, x2] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w8, [x0, #0x18]; tbz w8, #2, #0x934b8; sub x8, x3, x2]
uint64_t fde_sub_093478(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39406008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0194ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093478ULL;
}

// FDE #0783 | PC: 0x09360c..0x09361c (16 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IDsE10do_unshiftER9mbstate_tPcS4_RS4_
// EN: AArch64 prologue [bti c; mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_09360c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800060ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09360CULL;
}

// FDE #0784 | PC: 0x09361c..0x093628 (12 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IDsE11do_encodingEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_09361c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09361CULL;
}

// FDE #0785 | PC: 0x093628..0x093634 (12 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IDsE16do_always_noconvEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_093628(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093628ULL;
}

// FDE #0786 | PC: 0x093634..0x09379c (360 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IDsE9do_lengthER9mbstate_tPKcS5_m
// EN: AArch64 prologue [bti c; ldrb w9, [x0, #0x18]; mov x8, x2; tbz w9, #2, #0x93684] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w9, [x0, #0x18]; mov x8, x2; tbz w9, #2, #0x93684]
uint64_t fde_sub_093634(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39406009ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0168ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093634ULL;
}

// FDE #0787 | PC: 0x09379c..0x0937b8 (28 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IDsE13do_max_lengthEv
// EN: AArch64 prologue [bti c; ldrb w8, [x0, #0x18]; mov w9, #6; tst w8, #4] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w8, [x0, #0x18]; mov w9, #6; tst w8, #4]
uint64_t fde_sub_09379c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39406008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09379CULL;
}

// FDE #0788 | PC: 0x0937b8..0x093854 (156 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IDiE6do_outER9mbstate_tPKDiS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_0937b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0937B8ULL;
}

// FDE #0789 | PC: 0x093854..0x0938f0 (156 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IDiE5do_inER9mbstate_tPKcS5_RS5_PDiS7_RS7_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_093854(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093854ULL;
}

// FDE #0790 | PC: 0x0938f0..0x093900 (16 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IDiE10do_unshiftER9mbstate_tPcS4_RS4_
// EN: AArch64 prologue [bti c; mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_0938f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800060ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0938F0ULL;
}

// FDE #0791 | PC: 0x093900..0x09390c (12 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IDiE11do_encodingEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_093900(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093900ULL;
}

// FDE #0792 | PC: 0x09390c..0x093918 (12 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IDiE16do_always_noconvEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_09390c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09390CULL;
}

// FDE #0793 | PC: 0x093918..0x093938 (32 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IDiE9do_lengthER9mbstate_tPKcS5_m
// EN: AArch64 prologue [bti c; mov x8, x4; mov x1, x3; ldr x3, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [bti c; mov x8, x4; mov x1, x3; ldr x3, [x0, #0x10]]
uint64_t fde_sub_093918(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0403E8ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093918ULL;
}

// FDE #0794 | PC: 0x093938..0x093954 (28 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IDiE13do_max_lengthEv
// EN: AArch64 prologue [bti c; ldrb w8, [x0, #0x18]; mov w9, #7; tst w8, #4] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w8, [x0, #0x18]; mov w9, #7; tst w8, #4]
uint64_t fde_sub_093938(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39406008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093938ULL;
}

// FDE #0795 | PC: 0x093954..0x093a38 (228 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IwLb0EE6do_outER9mbstate_tPKwS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [bti c; ldrb w9, [x0, #0x20]; ldr x8, [x0, #0x18]; tbz w9, #1, #0x93980] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w9, [x0, #0x20]; ldr x8, [x0, #0x18]; tbz w9, #1, #0x93980]
uint64_t fde_sub_093954(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39408009ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093954ULL;
}

// FDE #0796 | PC: 0x093a38..0x093b44 (268 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IwLb0EE5do_inER9mbstate_tPKcS5_RS5_PwS7_RS7_
// EN: AArch64 prologue [bti c; ldrb w8, [x0, #0x20]; tbz w8, #2, #0x93a6c; sub x8, x3, x2] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w8, [x0, #0x20]; tbz w8, #2, #0x93a6c; sub x8, x3, x2]
uint64_t fde_sub_093a38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39408008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093A38ULL;
}

// FDE #0797 | PC: 0x093b44..0x093b54 (16 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IwLb0EE10do_unshiftER9mbstate_tPcS4_RS4_
// EN: AArch64 prologue [bti c; mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_093b44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800060ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093B44ULL;
}

// FDE #0798 | PC: 0x093b54..0x093b60 (12 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IwLb0EE11do_encodingEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_093b54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093B54ULL;
}

// FDE #0799 | PC: 0x093b60..0x093b6c (12 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IwLb0EE16do_always_noconvEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_093b60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093B60ULL;
}

// FDE #0800 | PC: 0x093b6c..0x093c6c (256 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IwLb0EE9do_lengthER9mbstate_tPKcS5_m
// EN: AArch64 prologue [bti c; ldrb w9, [x0, #0x20]; mov x8, x2; tbz w9, #2, #0x93bac] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w9, [x0, #0x20]; mov x8, x2; tbz w9, #2, #0x93bac]
uint64_t fde_sub_093b6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39408009ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093B6CULL;
}

// FDE #0801 | PC: 0x093c6c..0x093c88 (28 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IwLb0EE13do_max_lengthEv
// EN: AArch64 prologue [bti c; ldrb w8, [x0, #0x20]; mov w9, #6; tst w8, #4] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w8, [x0, #0x20]; mov w9, #6; tst w8, #4]
uint64_t fde_sub_093c6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39408008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093C6CULL;
}

// FDE #0802 | PC: 0x093c88..0x093d5c (212 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IwLb1EE6do_outER9mbstate_tPKwS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [bti c; ldrb w9, [x0, #0x20]; ldr x8, [x0, #0x18]; tbz w9, #1, #0x93cb4] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w9, [x0, #0x20]; ldr x8, [x0, #0x18]; tbz w9, #1, #0x93cb4]
uint64_t fde_sub_093c88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39408009ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093C88ULL;
}

// FDE #0803 | PC: 0x093d5c..0x093e68 (268 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IwLb1EE5do_inER9mbstate_tPKcS5_RS5_PwS7_RS7_
// EN: AArch64 prologue [bti c; ldrb w8, [x0, #0x20]; tbz w8, #2, #0x93d90; sub x8, x3, x2] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w8, [x0, #0x20]; tbz w8, #2, #0x93d90; sub x8, x3, x2]
uint64_t fde_sub_093d5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39408008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093D5CULL;
}

// FDE #0804 | PC: 0x093e68..0x093e78 (16 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IwLb1EE10do_unshiftER9mbstate_tPcS4_RS4_
// EN: AArch64 prologue [bti c; mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_093e68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800060ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093E68ULL;
}

// FDE #0805 | PC: 0x093e78..0x093e84 (12 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IwLb1EE11do_encodingEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_093e78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093E78ULL;
}

// FDE #0806 | PC: 0x093e84..0x093e90 (12 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IwLb1EE16do_always_noconvEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_093e84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093E84ULL;
}

// FDE #0807 | PC: 0x093e90..0x093f90 (256 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IwLb1EE9do_lengthER9mbstate_tPKcS5_m
// EN: AArch64 prologue [bti c; ldrb w9, [x0, #0x20]; mov x8, x2; tbz w9, #2, #0x93ed0] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w9, [x0, #0x20]; mov x8, x2; tbz w9, #2, #0x93ed0]
uint64_t fde_sub_093e90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39408009ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093E90ULL;
}

// FDE #0808 | PC: 0x093f90..0x093fac (28 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IwLb1EE13do_max_lengthEv
// EN: AArch64 prologue [bti c; ldrb w8, [x0, #0x20]; mov w9, #6; tst w8, #4] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w8, [x0, #0x20]; mov w9, #6; tst w8, #4]
uint64_t fde_sub_093f90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39408008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093F90ULL;
}

// FDE #0809 | PC: 0x093fac..0x09402c (128 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDsLb0EE6do_outER9mbstate_tPKDsS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [bti c; ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #1, #0x93fd8] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #1, #0x93fd8]
uint64_t fde_sub_093fac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39406009ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093FACULL;
}

// FDE #0810 | PC: 0x09402c..0x0940c0 (148 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDsLb0EE5do_inER9mbstate_tPKcS5_RS5_PDsS7_RS7_
// EN: AArch64 prologue [bti c; ldrb w8, [x0, #0x18]; tbz w8, #2, #0x94060; sub x8, x3, x2] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w8, [x0, #0x18]; tbz w8, #2, #0x94060; sub x8, x3, x2]
uint64_t fde_sub_09402c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39406008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09402CULL;
}

// FDE #0811 | PC: 0x0940c0..0x0940d0 (16 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDsLb0EE10do_unshiftER9mbstate_tPcS4_RS4_
// EN: AArch64 prologue [bti c; mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_0940c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800060ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0940C0ULL;
}

// FDE #0812 | PC: 0x0940d0..0x0940dc (12 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDsLb0EE11do_encodingEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_0940d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0940D0ULL;
}

// FDE #0813 | PC: 0x0940dc..0x0940e8 (12 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDsLb0EE16do_always_noconvEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_0940dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0940DCULL;
}

// FDE #0814 | PC: 0x0940e8..0x094180 (152 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDsLb0EE9do_lengthER9mbstate_tPKcS5_m
// EN: AArch64 prologue [bti c; ldrb w9, [x0, #0x18]; mov x8, x2; tbz w9, #2, #0x94128] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w9, [x0, #0x18]; mov x8, x2; tbz w9, #2, #0x94128]
uint64_t fde_sub_0940e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39406009ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0940E8ULL;
}

// FDE #0815 | PC: 0x094180..0x09419c (28 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDsLb0EE13do_max_lengthEv
// EN: AArch64 prologue [bti c; ldrb w8, [x0, #0x18]; mov w9, #4; tst w8, #4] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w8, [x0, #0x18]; mov w9, #4; tst w8, #4]
uint64_t fde_sub_094180(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39406008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x094180ULL;
}

// FDE #0816 | PC: 0x09419c..0x094218 (124 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDsLb1EE6do_outER9mbstate_tPKDsS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [bti c; ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #1, #0x941c8] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #1, #0x941c8]
uint64_t fde_sub_09419c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39406009ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09419CULL;
}

// FDE #0817 | PC: 0x094218..0x0942ac (148 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDsLb1EE5do_inER9mbstate_tPKcS5_RS5_PDsS7_RS7_
// EN: AArch64 prologue [bti c; ldrb w8, [x0, #0x18]; tbz w8, #2, #0x9424c; sub x8, x3, x2] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w8, [x0, #0x18]; tbz w8, #2, #0x9424c; sub x8, x3, x2]
uint64_t fde_sub_094218(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39406008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x094218ULL;
}

// FDE #0818 | PC: 0x0942ac..0x0942bc (16 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDsLb1EE10do_unshiftER9mbstate_tPcS4_RS4_
// EN: AArch64 prologue [bti c; mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_0942ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800060ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0942ACULL;
}

// FDE #0819 | PC: 0x0942bc..0x0942c8 (12 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDsLb1EE11do_encodingEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_0942bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0942BCULL;
}

// FDE #0820 | PC: 0x0942c8..0x0942d4 (12 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDsLb1EE16do_always_noconvEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_0942c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0942C8ULL;
}

// FDE #0821 | PC: 0x0942d4..0x094384 (176 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDsLb1EE9do_lengthER9mbstate_tPKcS5_m
// EN: AArch64 prologue [bti c; ldrb w9, [x0, #0x18]; mov x8, x2; tbz w9, #2, #0x94304] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w9, [x0, #0x18]; mov x8, x2; tbz w9, #2, #0x94304]
uint64_t fde_sub_0942d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39406009ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0942D4ULL;
}

// FDE #0822 | PC: 0x094384..0x0943a0 (28 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDsLb1EE13do_max_lengthEv
// EN: AArch64 prologue [bti c; ldrb w8, [x0, #0x18]; mov w9, #4; tst w8, #4] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w8, [x0, #0x18]; mov w9, #4; tst w8, #4]
uint64_t fde_sub_094384(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39406008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x094384ULL;
}

// FDE #0823 | PC: 0x0943a0..0x094484 (228 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDiLb0EE6do_outER9mbstate_tPKDiS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [bti c; ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #1, #0x943cc] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #1, #0x943cc]
uint64_t fde_sub_0943a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39406009ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0943A0ULL;
}

// FDE #0824 | PC: 0x094484..0x094590 (268 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDiLb0EE5do_inER9mbstate_tPKcS5_RS5_PDiS7_RS7_
// EN: AArch64 prologue [bti c; ldrb w8, [x0, #0x18]; tbz w8, #2, #0x944b8; sub x8, x3, x2] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w8, [x0, #0x18]; tbz w8, #2, #0x944b8; sub x8, x3, x2]
uint64_t fde_sub_094484(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39406008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x094484ULL;
}

// FDE #0825 | PC: 0x094590..0x0945a0 (16 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDiLb0EE10do_unshiftER9mbstate_tPcS4_RS4_
// EN: AArch64 prologue [bti c; mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_094590(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800060ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x094590ULL;
}

// FDE #0826 | PC: 0x0945a0..0x0945ac (12 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDiLb0EE11do_encodingEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_0945a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0945A0ULL;
}

// FDE #0827 | PC: 0x0945ac..0x0945b8 (12 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDiLb0EE16do_always_noconvEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_0945ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0945ACULL;
}

// FDE #0828 | PC: 0x0945b8..0x0946b8 (256 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDiLb0EE9do_lengthER9mbstate_tPKcS5_m
// EN: AArch64 prologue [bti c; ldrb w9, [x0, #0x18]; mov x8, x2; tbz w9, #2, #0x945f8] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w9, [x0, #0x18]; mov x8, x2; tbz w9, #2, #0x945f8]
uint64_t fde_sub_0945b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39406009ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0945B8ULL;
}

// FDE #0829 | PC: 0x0946b8..0x0946d4 (28 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDiLb0EE13do_max_lengthEv
// EN: AArch64 prologue [bti c; ldrb w8, [x0, #0x18]; mov w9, #6; tst w8, #4] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w8, [x0, #0x18]; mov w9, #6; tst w8, #4]
uint64_t fde_sub_0946b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39406008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0946B8ULL;
}

// FDE #0830 | PC: 0x0946d4..0x0947a8 (212 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDiLb1EE6do_outER9mbstate_tPKDiS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [bti c; ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #1, #0x94700] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #1, #0x94700]
uint64_t fde_sub_0946d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39406009ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0946D4ULL;
}

// FDE #0831 | PC: 0x0947a8..0x0948b4 (268 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDiLb1EE5do_inER9mbstate_tPKcS5_RS5_PDiS7_RS7_
// EN: AArch64 prologue [bti c; ldrb w8, [x0, #0x18]; tbz w8, #2, #0x947dc; sub x8, x3, x2] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w8, [x0, #0x18]; tbz w8, #2, #0x947dc; sub x8, x3, x2]
uint64_t fde_sub_0947a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39406008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0947A8ULL;
}

// FDE #0832 | PC: 0x0948b4..0x0948c4 (16 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDiLb1EE10do_unshiftER9mbstate_tPcS4_RS4_
// EN: AArch64 prologue [bti c; mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_0948b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800060ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0948B4ULL;
}

// FDE #0833 | PC: 0x0948c4..0x0948d0 (12 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDiLb1EE11do_encodingEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_0948c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0948C4ULL;
}

// FDE #0834 | PC: 0x0948d0..0x0948dc (12 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDiLb1EE16do_always_noconvEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_0948d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0948D0ULL;
}

// FDE #0835 | PC: 0x0948dc..0x0949dc (256 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDiLb1EE9do_lengthER9mbstate_tPKcS5_m
// EN: AArch64 prologue [bti c; ldrb w9, [x0, #0x18]; mov x8, x2; tbz w9, #2, #0x9491c] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w9, [x0, #0x18]; mov x8, x2; tbz w9, #2, #0x9491c]
uint64_t fde_sub_0948dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39406009ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0948DCULL;
}

// FDE #0836 | PC: 0x0949dc..0x0949f8 (28 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDiLb1EE13do_max_lengthEv
// EN: AArch64 prologue [bti c; ldrb w8, [x0, #0x18]; mov w9, #6; tst w8, #4] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w8, [x0, #0x18]; mov w9, #6; tst w8, #4]
uint64_t fde_sub_0949dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39406008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0949DCULL;
}

// FDE #0837 | PC: 0x0949f8..0x094a94 (156 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IwE6do_outER9mbstate_tPKwS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_0949f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0949F8ULL;
}

// FDE #0838 | PC: 0x094a94..0x094cb8 (548 B) | Symbol: sub_094a94
// EN: AArch64 prologue [bti c; str x0, [x2]; str x3, [x5]; tbz w7, #1, #0x94af0] | VI: Khởi đầu hàm AArch64 [bti c; str x0, [x2]; str x3, [x5]; tbz w7, #1, #0x94af0]
uint64_t fde_sub_094a94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000040ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0224ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x094A94ULL;
}

// FDE #0839 | PC: 0x094cb8..0x094d54 (156 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IwE5do_inER9mbstate_tPKcS5_RS5_PwS7_RS7_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_094cb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x094CB8ULL;
}

// FDE #0840 | PC: 0x094d54..0x094fd0 (636 B) | Symbol: sub_094d54
// EN: AArch64 prologue [bti c; str x0, [x2]; str x3, [x5]; ldr x11, [x2]] | VI: Khởi đầu hàm AArch64 [bti c; str x0, [x2]; str x3, [x5]; ldr x11, [x2]]
uint64_t fde_sub_094d54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000040ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x027CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x094D54ULL;
}

// FDE #0841 | PC: 0x094fd0..0x094fe0 (16 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IwE10do_unshiftER9mbstate_tPcS4_RS4_
// EN: AArch64 prologue [bti c; mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_094fd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800060ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x094FD0ULL;
}

// FDE #0842 | PC: 0x094fe0..0x094fec (12 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IwE11do_encodingEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_094fe0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x094FE0ULL;
}

// FDE #0843 | PC: 0x094fec..0x094ff8 (12 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IwE16do_always_noconvEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_094fec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x094FECULL;
}

// FDE #0844 | PC: 0x094ff8..0x095018 (32 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IwE9do_lengthER9mbstate_tPKcS5_m
// EN: AArch64 prologue [bti c; mov x8, x4; mov x1, x3; ldr x3, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [bti c; mov x8, x4; mov x1, x3; ldr x3, [x0, #0x18]]
uint64_t fde_sub_094ff8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0403E8ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x094FF8ULL;
}

// FDE #0845 | PC: 0x095018..0x095034 (28 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IwE13do_max_lengthEv
// EN: AArch64 prologue [bti c; ldrb w8, [x0, #0x20]; mov w9, #7; tst w8, #4] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w8, [x0, #0x20]; mov w9, #7; tst w8, #4]
uint64_t fde_sub_095018(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39408008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x095018ULL;
}

// FDE #0846 | PC: 0x095034..0x0950d0 (156 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IDsE6do_outER9mbstate_tPKDsS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_095034(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x095034ULL;
}

// FDE #0847 | PC: 0x0950d0..0x09516c (156 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IDsE5do_inER9mbstate_tPKcS5_RS5_PDsS7_RS7_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_0950d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0950D0ULL;
}

// FDE #0848 | PC: 0x09516c..0x09517c (16 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IDsE10do_unshiftER9mbstate_tPcS4_RS4_
// EN: AArch64 prologue [bti c; mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_09516c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800060ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09516CULL;
}

// FDE #0849 | PC: 0x09517c..0x095188 (12 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IDsE11do_encodingEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_09517c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09517CULL;
}

// FDE #0850 | PC: 0x095188..0x095194 (12 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IDsE16do_always_noconvEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_095188(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x095188ULL;
}

// FDE #0851 | PC: 0x095194..0x0951b4 (32 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IDsE9do_lengthER9mbstate_tPKcS5_m
// EN: AArch64 prologue [bti c; mov x8, x4; mov x1, x3; ldr x3, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [bti c; mov x8, x4; mov x1, x3; ldr x3, [x0, #0x10]]
uint64_t fde_sub_095194(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0403E8ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x095194ULL;
}

// FDE #0852 | PC: 0x0951b4..0x0951d0 (28 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IDsE13do_max_lengthEv
// EN: AArch64 prologue [bti c; ldrb w8, [x0, #0x18]; mov w9, #7; tst w8, #4] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w8, [x0, #0x18]; mov w9, #7; tst w8, #4]
uint64_t fde_sub_0951b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39406008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0951B4ULL;
}

// FDE #0853 | PC: 0x0951d0..0x09526c (156 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IDiE6do_outER9mbstate_tPKDiS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_0951d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0951D0ULL;
}

// FDE #0854 | PC: 0x09526c..0x095308 (156 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IDiE5do_inER9mbstate_tPKcS5_RS5_PDiS7_RS7_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_09526c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09526CULL;
}

// FDE #0855 | PC: 0x095308..0x095318 (16 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IDiE10do_unshiftER9mbstate_tPcS4_RS4_
// EN: AArch64 prologue [bti c; mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_095308(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800060ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x095308ULL;
}

// FDE #0856 | PC: 0x095318..0x095324 (12 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IDiE11do_encodingEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_095318(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x095318ULL;
}

// FDE #0857 | PC: 0x095324..0x095330 (12 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IDiE16do_always_noconvEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_095324(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x095324ULL;
}

// FDE #0858 | PC: 0x095330..0x095350 (32 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IDiE9do_lengthER9mbstate_tPKcS5_m
// EN: AArch64 prologue [bti c; mov x8, x4; mov x1, x3; ldr x3, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [bti c; mov x8, x4; mov x1, x3; ldr x3, [x0, #0x10]]
uint64_t fde_sub_095330(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0403E8ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x095330ULL;
}

// FDE #0859 | PC: 0x095350..0x09536c (28 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IDiE13do_max_lengthEv
// EN: AArch64 prologue [bti c; ldrb w8, [x0, #0x18]; mov w9, #7; tst w8, #4] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w8, [x0, #0x18]; mov w9, #7; tst w8, #4]
uint64_t fde_sub_095350(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39406008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x095350ULL;
}

// FDE #0860 | PC: 0x09536c..0x095398 (44 B) | Symbol: _ZNSt6__ndk116__narrow_to_utf8ILm16EED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09536c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09536CULL;
}

// FDE #0861 | PC: 0x095398..0x0953c4 (44 B) | Symbol: _ZNSt6__ndk116__narrow_to_utf8ILm32EED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_095398(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x095398ULL;
}

// FDE #0862 | PC: 0x0953c4..0x0953f0 (44 B) | Symbol: _ZNSt6__ndk117__widen_from_utf8ILm16EED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0953c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0953C4ULL;
}

// FDE #0863 | PC: 0x0953f0..0x09541c (44 B) | Symbol: _ZNSt6__ndk117__widen_from_utf8ILm32EED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0953f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0953F0ULL;
}

// FDE #0864 | PC: 0x09541c..0x095448 (44 B) | Symbol: _ZNSt6__ndk18numpunctIcEC2Em
// EN: AArch64 prologue [bti c; adrp x9, #0xd4000; ldr x9, [x9, #0x708]; sub x8, x1, #1] | VI: Khởi đầu hàm AArch64 [bti c; adrp x9, #0xd4000; ldr x9, [x9, #0x708]; sub x8, x1, #1]
uint64_t fde_sub_09541c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00001E9ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09541CULL;
}

// FDE #0865 | PC: 0x095448..0x095478 (48 B) | Symbol: _ZNSt6__ndk18numpunctIwEC2Em
// EN: AArch64 prologue [bti c; adrp x9, #0xd4000; ldr x9, [x9, #0x710]; adrp x10, #0x4a000] | VI: Khởi đầu hàm AArch64 [bti c; adrp x9, #0xd4000; ldr x9, [x9, #0x710]; adrp x10, #0x4a000]
uint64_t fde_sub_095448(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00001E9ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x095448ULL;
}

// FDE #0866 | PC: 0x095478..0x0954c0 (72 B) | Symbol: _ZNSt6__ndk18numpunctIcED2Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_095478(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x095478ULL;
}

// FDE #0867 | PC: 0x0954c0..0x095510 (80 B) | Symbol: _ZNSt6__ndk18numpunctIcED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0954c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0954C0ULL;
}

// FDE #0868 | PC: 0x095510..0x095558 (72 B) | Symbol: _ZNSt6__ndk18numpunctIwED1Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_095510(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x095510ULL;
}

// FDE #0869 | PC: 0x095558..0x0955a8 (80 B) | Symbol: _ZNSt6__ndk18numpunctIwED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_095558(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x095558ULL;
}

// FDE #0870 | PC: 0x0955a8..0x0955b4 (12 B) | Symbol: _ZNKSt6__ndk18numpunctIcE16do_decimal_pointEv
// EN: AArch64 prologue [bti c; ldrb w0, [x0, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w0, [x0, #0x10]; ret]
uint64_t fde_sub_0955a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39404000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0955A8ULL;
}

// FDE #0871 | PC: 0x0955b4..0x0955c0 (12 B) | Symbol: _ZNKSt6__ndk18numpunctIwE16do_decimal_pointEv
// EN: AArch64 prologue [bti c; ldr w0, [x0, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldr w0, [x0, #0x10]; ret]
uint64_t fde_sub_0955b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9401000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0955B4ULL;
}

// FDE #0872 | PC: 0x0955c0..0x0955cc (12 B) | Symbol: _ZNKSt6__ndk18numpunctIcE16do_thousands_sepEv
// EN: AArch64 prologue [bti c; ldrb w0, [x0, #0x11]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w0, [x0, #0x11]; ret]
uint64_t fde_sub_0955c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39404400ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0955C0ULL;
}

// FDE #0873 | PC: 0x0955cc..0x0955d8 (12 B) | Symbol: _ZNKSt6__ndk18numpunctIwE16do_thousands_sepEv
// EN: AArch64 prologue [bti c; ldr w0, [x0, #0x14]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldr w0, [x0, #0x14]; ret]
uint64_t fde_sub_0955cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9401400ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0955CCULL;
}

// FDE #0874 | PC: 0x0955d8..0x0955e8 (16 B) | Symbol: _ZNKSt6__ndk18numpunctIcE11do_groupingEv
// EN: AArch64 prologue [bti c; add x1, x0, #0x18; mov x0, x8; b #0xc8f50] | VI: Khởi đầu hàm AArch64 [bti c; add x1, x0, #0x18; mov x0, x8; b #0xc8f50]
uint64_t fde_sub_0955d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91006001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0955D8ULL;
}

// FDE #0875 | PC: 0x0955e8..0x0955f8 (16 B) | Symbol: _ZNKSt6__ndk18numpunctIwE11do_groupingEv
// EN: AArch64 prologue [bti c; add x1, x0, #0x18; mov x0, x8; b #0xc8f50] | VI: Khởi đầu hàm AArch64 [bti c; add x1, x0, #0x18; mov x0, x8; b #0xc8f50]
uint64_t fde_sub_0955e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91006001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0955E8ULL;
}

// FDE #0876 | PC: 0x0955f8..0x095618 (32 B) | Symbol: _ZNKSt6__ndk18numpunctIcE11do_truenameEv
// EN: AArch64 prologue [bti c; mov w10, #0x7274; mov w9, #8; movk w10, #0x6575, lsl #16] | VI: Khởi đầu hàm AArch64 [bti c; mov w10, #0x7274; mov w9, #8; movk w10, #0x6575, lsl #16]
uint64_t fde_sub_0955f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x528E4E8AULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0955F8ULL;
}

// FDE #0877 | PC: 0x095618..0x09562c (20 B) | Symbol: _ZNKSt6__ndk18numpunctIwE11do_truenameEv
// EN: AArch64 prologue [bti c; adrp x1, #0x4a000; add x1, x1, #0xe18; mov x0, x8] | VI: Khởi đầu hàm AArch64 [bti c; adrp x1, #0x4a000; add x1, x1, #0xe18; mov x0, x8]
uint64_t fde_sub_095618(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0FFFDA1ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x095618ULL;
}

// FDE #0878 | PC: 0x09562c..0x0956cc (160 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEEC2IDnEEPKw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_09562c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09562CULL;
}

// FDE #0879 | PC: 0x0956cc..0x0956f0 (36 B) | Symbol: _ZNKSt6__ndk18numpunctIcE12do_falsenameEv
// EN: AArch64 prologue [bti c; mov w10, #0x6166; mov w9, #0xa; movk w10, #0x736c, lsl #16] | VI: Khởi đầu hàm AArch64 [bti c; mov w10, #0x6166; mov w9, #0xa; movk w10, #0x736c, lsl #16]
uint64_t fde_sub_0956cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x528C2CCAULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0956CCULL;
}

// FDE #0880 | PC: 0x0956f0..0x095704 (20 B) | Symbol: _ZNKSt6__ndk18numpunctIwE12do_falsenameEv
// EN: AArch64 prologue [bti c; adrp x1, #0x4b000; add x1, x1, #0x24; mov x0, x8] | VI: Khởi đầu hàm AArch64 [bti c; adrp x1, #0x4b000; add x1, x1, #0x24; mov x0, x8]
uint64_t fde_sub_0956f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0FFFDA1ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0956F0ULL;
}

// FDE #0881 | PC: 0x095704..0x095784 (128 B) | Symbol: _ZNSt6__ndk115numpunct_bynameIcEC2EPKcm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_095704(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x095704ULL;
}

// FDE #0882 | PC: 0x095784..0x095b34 (944 B) | Symbol: _ZNSt6__ndk115numpunct_bynameIcE6__initEPKc
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x40]; str x25, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x40]; str x25, [sp, #0x50]]
uint64_t fde_sub_095784(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10243FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x03B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x095784ULL;
}

// FDE #0883 | PC: 0x095b34..0x095bc4 (144 B) | Symbol: _ZNSt6__ndk115numpunct_bynameIcEC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_095b34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x095B34ULL;
}

// FDE #0884 | PC: 0x095bc4..0x095c14 (80 B) | Symbol: _ZNSt6__ndk115numpunct_bynameIcED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_095bc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x095BC4ULL;
}

// FDE #0885 | PC: 0x095c14..0x095c98 (132 B) | Symbol: _ZNSt6__ndk115numpunct_bynameIwEC2EPKcm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_095c14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x095C14ULL;
}

// FDE #0886 | PC: 0x095c98..0x095f68 (720 B) | Symbol: _ZNSt6__ndk115numpunct_bynameIwE6__initEPKc
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x40]; str x25, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x40]; str x25, [sp, #0x50]]
uint64_t fde_sub_095c98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10243FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x02D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x095C98ULL;
}

// FDE #0887 | PC: 0x095f68..0x095ffc (148 B) | Symbol: _ZNSt6__ndk115numpunct_bynameIwEC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_095f68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x095F68ULL;
}

// FDE #0888 | PC: 0x095ffc..0x09604c (80 B) | Symbol: _ZNSt6__ndk115numpunct_bynameIwED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_095ffc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x095FFCULL;
}

// FDE #0889 | PC: 0x09604c..0x096090 (68 B) | Symbol: _ZNSt6__ndk114__num_get_base10__get_baseERNS_8ios_baseE
// EN: AArch64 prologue [bti c; ldr w8, [x0, #8]; mov w9, #0x4a; ands w8, w8, w9] | VI: Khởi đầu hàm AArch64 [bti c; ldr w8, [x0, #8]; mov w9, #0x4a; ands w8, w8, w9]
uint64_t fde_sub_09604c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9400808ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09604CULL;
}

// FDE #0890 | PC: 0x096090..0x0962a8 (536 B) | Symbol: _ZNKSt6__ndk120__time_get_c_storageIcE7__weeksEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_096090(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0218ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x096090ULL;
}

// FDE #0891 | PC: 0x0962a8..0x0964c0 (536 B) | Symbol: _ZNKSt6__ndk120__time_get_c_storageIwE7__weeksEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0962a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0218ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0962A8ULL;
}

// FDE #0892 | PC: 0x0964c0..0x09677c (700 B) | Symbol: _ZNKSt6__ndk120__time_get_c_storageIcE8__monthsEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0964c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x02BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0964C0ULL;
}

// FDE #0893 | PC: 0x09677c..0x096a38 (700 B) | Symbol: _ZNKSt6__ndk120__time_get_c_storageIwE8__monthsEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09677c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x02BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09677CULL;
}

// FDE #0894 | PC: 0x096a38..0x096b3c (260 B) | Symbol: _ZNKSt6__ndk120__time_get_c_storageIcE7__am_pmEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_096a38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x096A38ULL;
}

// FDE #0895 | PC: 0x096b3c..0x096c40 (260 B) | Symbol: _ZNKSt6__ndk120__time_get_c_storageIwE7__am_pmEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_096b3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x096B3CULL;
}

// FDE #0896 | PC: 0x096c40..0x096ccc (140 B) | Symbol: _ZNKSt6__ndk120__time_get_c_storageIcE3__xEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xd9000] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xd9000]
uint64_t fde_sub_096c40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x096C40ULL;
}

// FDE #0897 | PC: 0x096ccc..0x096d6c (160 B) | Symbol: _ZNKSt6__ndk120__time_get_c_storageIwE3__xEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_096ccc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x096CCCULL;
}

// FDE #0898 | PC: 0x096d6c..0x096df8 (140 B) | Symbol: _ZNKSt6__ndk120__time_get_c_storageIcE3__XEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xd9000] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xd9000]
uint64_t fde_sub_096d6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x096D6CULL;
}

// FDE #0899 | PC: 0x096df8..0x096e98 (160 B) | Symbol: _ZNKSt6__ndk120__time_get_c_storageIwE3__XEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_096df8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x096DF8ULL;
}

// FDE #0900 | PC: 0x096e98..0x096f2c (148 B) | Symbol: _ZNKSt6__ndk120__time_get_c_storageIcE3__cEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xd9000] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xd9000]
uint64_t fde_sub_096e98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x096E98ULL;
}

// FDE #0901 | PC: 0x096f2c..0x096fcc (160 B) | Symbol: _ZNKSt6__ndk120__time_get_c_storageIwE3__cEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_096f2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x096F2CULL;
}

// FDE #0902 | PC: 0x096fcc..0x097060 (148 B) | Symbol: _ZNKSt6__ndk120__time_get_c_storageIcE3__rEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xd9000] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xd9000]
uint64_t fde_sub_096fcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x096FCCULL;
}

// FDE #0903 | PC: 0x097060..0x097100 (160 B) | Symbol: _ZNKSt6__ndk120__time_get_c_storageIwE3__rEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_097060(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x097060ULL;
}

// FDE #0904 | PC: 0x097100..0x09725c (348 B) | Symbol: _ZNSt6__ndk110__time_getC2EPKc
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x40]; stp x22, x21, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x40]; stp x22, x21, [sp, #0x50]]
uint64_t fde_sub_097100(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x015CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x097100ULL;
}

// FDE #0905 | PC: 0x09725c..0x097310 (180 B) | Symbol: _ZNSt6__ndk110__time_getC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_09725c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09725CULL;
}

// FDE #0906 | PC: 0x097310..0x097334 (36 B) | Symbol: _ZNSt6__ndk110__time_getD2Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x0, [x0]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x0, [x0]]
uint64_t fde_sub_097310(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x097310ULL;
}

// FDE #0907 | PC: 0x097334..0x097970 (1596 B) | Symbol: _ZNSt6__ndk118__time_get_storageIcE9__analyzeEcRKNS_5ctypeIcEE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x150; stp x29, x30, [sp, #0xf0]; stp x28, x27, [sp, #0x100]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x150; stp x29, x30, [sp, #0xf0]; stp x28, x27, [sp, #0x100]]
uint64_t fde_sub_097334(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10543FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x063CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x097334ULL;
}

// FDE #0908 | PC: 0x097970..0x097cc4 (852 B) | Symbol: sub_097970
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x110; stp x29, x30, [sp, #0xb0]; stp x28, x27, [sp, #0xc0]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x110; stp x29, x30, [sp, #0xb0]; stp x28, x27, [sp, #0xc0]]
uint64_t fde_sub_097970(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10443FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0354ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x097970ULL;
}

// FDE #0909 | PC: 0x097cc4..0x0983e0 (1820 B) | Symbol: _ZNSt6__ndk118__time_get_storageIwE9__analyzeEcRKNS_5ctypeIwEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_097cc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x071CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x097CC4ULL;
}

// FDE #0910 | PC: 0x0983e0..0x098730 (848 B) | Symbol: sub_0983e0
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x110; stp x29, x30, [sp, #0xb0]; stp x28, x27, [sp, #0xc0]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x110; stp x29, x30, [sp, #0xb0]; stp x28, x27, [sp, #0xc0]]
uint64_t fde_sub_0983e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10443FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0350ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0983E0ULL;
}

// FDE #0911 | PC: 0x098730..0x0989d0 (672 B) | Symbol: _ZNSt6__ndk118__time_get_storageIcE4initERKNS_5ctypeIcEE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x120; stp x29, x30, [sp, #0xd0]; stp x28, x25, [sp, #0xe0]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x120; stp x29, x30, [sp, #0xd0]; stp x28, x25, [sp, #0xe0]]
uint64_t fde_sub_098730(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10483FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x02A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x098730ULL;
}

// FDE #0912 | PC: 0x0989d0..0x099598 (3016 B) | Symbol: _ZNSt6__ndk118__time_get_storageIwE4initERKNS_5ctypeIwEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_0989d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0BC8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0989D0ULL;
}

// FDE #0913 | PC: 0x099598..0x0998ec (852 B) | Symbol: _ZNSt6__ndk118__time_get_storageIcEC2EPKc
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x30]; str x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x30]; str x21, [sp, #0x40]]
uint64_t fde_sub_099598(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0354ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x099598ULL;
}

// FDE #0914 | PC: 0x0998ec..0x099964 (120 B) | Symbol: _ZNSt6__ndk112ctype_bynameIcED2Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0998ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0998ECULL;
}

// FDE #0915 | PC: 0x099964..0x099d0c (936 B) | Symbol: _ZNSt6__ndk118__time_get_storageIcEC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x30]; str x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x30]; str x21, [sp, #0x40]]
uint64_t fde_sub_099964(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x03A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x099964ULL;
}

// FDE #0916 | PC: 0x099d0c..0x09a018 (780 B) | Symbol: _ZNSt6__ndk118__time_get_storageIwEC1EPKc
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_099d0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x030CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x099D0CULL;
}

// FDE #0917 | PC: 0x09a018..0x09a06c (84 B) | Symbol: _ZNSt6__ndk112ctype_bynameIwED2Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09a018(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09A018ULL;
}

// FDE #0918 | PC: 0x09a06c..0x09a3cc (864 B) | Symbol: _ZNSt6__ndk118__time_get_storageIwEC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_09a06c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0360ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09A06CULL;
}

// FDE #0919 | PC: 0x09a3cc..0x09a82c (1120 B) | Symbol: _ZNKSt6__ndk118__time_get_storageIcE15__do_date_orderEv
// EN: AArch64 prologue [bti c; ldrb w10, [x0, #0x3f8]; add x8, x0, #0x3f8; add x11, x0, #0x3f9] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w10, [x0, #0x3f8]; add x8, x0, #0x3f8; add x11, x0, #0x3f9]
uint64_t fde_sub_09a3cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x394FE00AULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0460ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09A3CCULL;
}

// FDE #0920 | PC: 0x09a82c..0x09ac8c (1120 B) | Symbol: _ZNKSt6__ndk118__time_get_storageIwE15__do_date_orderEv
// EN: AArch64 prologue [bti c; ldrb w10, [x0, #0x3f8]; add x8, x0, #0x3f8; add x11, x0, #0x3fc] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w10, [x0, #0x3f8]; add x8, x0, #0x3f8; add x11, x0, #0x3fc]
uint64_t fde_sub_09a82c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x394FE00AULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0460ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09A82CULL;
}

// FDE #0921 | PC: 0x09ac8c..0x09ade8 (348 B) | Symbol: _ZNSt6__ndk110__time_putC1EPKc
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x40]; stp x22, x21, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x40]; stp x22, x21, [sp, #0x50]]
uint64_t fde_sub_09ac8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x015CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09AC8CULL;
}

// FDE #0922 | PC: 0x09ade8..0x09ae9c (180 B) | Symbol: _ZNSt6__ndk110__time_putC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_09ade8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09ADE8ULL;
}

// FDE #0923 | PC: 0x09ae9c..0x09af48 (172 B) | Symbol: _ZNSt6__ndk110__time_putD2Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_09ae9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09AE9CULL;
}

// FDE #0924 | PC: 0x09af48..0x09b3c8 (1152 B) | Symbol: _ZNSt6__ndk117moneypunct_bynameIcLb0EE4initEPKc
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x40]; str x25, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x40]; str x25, [sp, #0x50]]
uint64_t fde_sub_09af48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10243FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0480ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09AF48ULL;
}

// FDE #0925 | PC: 0x09b3c8..0x09b95c (1428 B) | Symbol: sub_09b3c8
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x50]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x50]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_09b3c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0594ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09B3C8ULL;
}

// FDE #0926 | PC: 0x09b95c..0x09bddc (1152 B) | Symbol: _ZNSt6__ndk117moneypunct_bynameIcLb1EE4initEPKc
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x40]; str x25, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x40]; str x25, [sp, #0x50]]
uint64_t fde_sub_09b95c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10243FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0480ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09B95CULL;
}

// FDE #0927 | PC: 0x09bddc..0x09c614 (2104 B) | Symbol: _ZNSt6__ndk117moneypunct_bynameIwLb0EE4initEPKc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x50]!; stp x28, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x50]!; stp x28, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_09bddc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0838ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09BDDCULL;
}

// FDE #0928 | PC: 0x09c614..0x09cba0 (1420 B) | Symbol: sub_09c614
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x50]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x50]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_09c614(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x058CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09C614ULL;
}

// FDE #0929 | PC: 0x09cba0..0x09d3d8 (2104 B) | Symbol: _ZNSt6__ndk117moneypunct_bynameIwLb1EE4initEPKc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x50]!; stp x28, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x50]!; stp x28, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_09cba0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0838ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09CBA0ULL;
}

// FDE #0930 | PC: 0x09d3d8..0x09d404 (44 B) | Symbol: _ZNSt6__ndk114__codecvt_utf8IwED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09d3d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D3D8ULL;
}

// FDE #0931 | PC: 0x09d404..0x09d430 (44 B) | Symbol: _ZNSt6__ndk114__codecvt_utf8IDsED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09d404(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D404ULL;
}

// FDE #0932 | PC: 0x09d430..0x09d45c (44 B) | Symbol: _ZNSt6__ndk114__codecvt_utf8IDiED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09d430(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D430ULL;
}

// FDE #0933 | PC: 0x09d45c..0x09d488 (44 B) | Symbol: _ZNSt6__ndk115__codecvt_utf16IwLb0EED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09d45c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D45CULL;
}

// FDE #0934 | PC: 0x09d488..0x09d4b4 (44 B) | Symbol: _ZNSt6__ndk115__codecvt_utf16IwLb1EED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09d488(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D488ULL;
}

// FDE #0935 | PC: 0x09d4b4..0x09d4e0 (44 B) | Symbol: _ZNSt6__ndk115__codecvt_utf16IDsLb0EED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09d4b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D4B4ULL;
}

// FDE #0936 | PC: 0x09d4e0..0x09d50c (44 B) | Symbol: _ZNSt6__ndk115__codecvt_utf16IDsLb1EED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09d4e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D4E0ULL;
}

// FDE #0937 | PC: 0x09d50c..0x09d538 (44 B) | Symbol: _ZNSt6__ndk115__codecvt_utf16IDiLb0EED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09d50c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D50CULL;
}

// FDE #0938 | PC: 0x09d538..0x09d564 (44 B) | Symbol: _ZNSt6__ndk115__codecvt_utf16IDiLb1EED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09d538(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D538ULL;
}

// FDE #0939 | PC: 0x09d564..0x09d630 (204 B) | Symbol: _ZNSt6__ndk17codecvtIwc9mbstate_tED2Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_09d564(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D564ULL;
}

// FDE #0940 | PC: 0x09d630..0x09d65c (44 B) | Symbol: _ZNSt6__ndk120__codecvt_utf8_utf16IwED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09d630(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D630ULL;
}

// FDE #0941 | PC: 0x09d65c..0x09d688 (44 B) | Symbol: _ZNSt6__ndk120__codecvt_utf8_utf16IDiED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09d65c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D65CULL;
}

// FDE #0942 | PC: 0x09d688..0x09d6b4 (44 B) | Symbol: _ZNSt6__ndk120__codecvt_utf8_utf16IDsED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09d688(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D688ULL;
}

// FDE #0943 | PC: 0x09d6b4..0x09d6e0 (44 B) | Symbol: sub_09d6b4
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09d6b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D6B4ULL;
}

// FDE #0944 | PC: 0x09d6e0..0x09d70c (44 B) | Symbol: sub_09d6e0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09d6e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D6E0ULL;
}

// FDE #0945 | PC: 0x09d70c..0x09d738 (44 B) | Symbol: sub_09d70c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09d70c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D70CULL;
}

// FDE #0946 | PC: 0x09d738..0x09d764 (44 B) | Symbol: sub_09d738
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09d738(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D738ULL;
}

// FDE #0947 | PC: 0x09d764..0x09d76c (8 B) | Symbol: sub_09d764
// EN: AArch64 prologue [bti c; b #0xc8bd0] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8bd0]
uint64_t fde_sub_09d764(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400AD1AULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D764ULL;
}

// FDE #0948 | PC: 0x09d76c..0x09d798 (44 B) | Symbol: sub_09d76c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09d76c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D76CULL;
}

// FDE #0949 | PC: 0x09d798..0x09d7a0 (8 B) | Symbol: sub_09d798
// EN: AArch64 prologue [bti c; b #0xc8bd0] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8bd0]
uint64_t fde_sub_09d798(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400AD0DULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D798ULL;
}

// FDE #0950 | PC: 0x09d7a0..0x09d7cc (44 B) | Symbol: sub_09d7a0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09d7a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D7A0ULL;
}

// FDE #0951 | PC: 0x09d7cc..0x09d7fc (48 B) | Symbol: sub_09d7cc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09d7cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D7CCULL;
}

// FDE #0952 | PC: 0x09d7fc..0x09d834 (56 B) | Symbol: sub_09d7fc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09d7fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D7FCULL;
}

// FDE #0953 | PC: 0x09d834..0x09d840 (12 B) | Symbol: sub_09d834
// EN: AArch64 prologue [bti c; add x0, x0, #0x18; b #0xc94e0] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x18; b #0xc94e0]
uint64_t fde_sub_09d834(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91006000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D834ULL;
}

// FDE #0954 | PC: 0x09d840..0x09d84c (12 B) | Symbol: sub_09d840
// EN: AArch64 prologue [bti c; add x0, x0, #0x20; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x20; ret]
uint64_t fde_sub_09d840(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91008000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D840ULL;
}

// FDE #0955 | PC: 0x09d84c..0x09d858 (12 B) | Symbol: sub_09d84c
// EN: AArch64 prologue [bti c; add x0, x0, #0x170; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x170; ret]
uint64_t fde_sub_09d84c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9105C000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D84CULL;
}

// FDE #0956 | PC: 0x09d858..0x09d864 (12 B) | Symbol: sub_09d858
// EN: AArch64 prologue [bti c; add x0, x0, #0x3b0; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x3b0; ret]
uint64_t fde_sub_09d858(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910EC000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D858ULL;
}

// FDE #0957 | PC: 0x09d864..0x09d870 (12 B) | Symbol: sub_09d864
// EN: AArch64 prologue [bti c; add x0, x0, #0x3e0; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x3e0; ret]
uint64_t fde_sub_09d864(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910F8000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D864ULL;
}

// FDE #0958 | PC: 0x09d870..0x09d87c (12 B) | Symbol: sub_09d870
// EN: AArch64 prologue [bti c; add x0, x0, #0x3f8; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x3f8; ret]
uint64_t fde_sub_09d870(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910FE000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D870ULL;
}

// FDE #0959 | PC: 0x09d87c..0x09d888 (12 B) | Symbol: sub_09d87c
// EN: AArch64 prologue [bti c; add x0, x0, #0x410; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x410; ret]
uint64_t fde_sub_09d87c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91104000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D87CULL;
}

// FDE #0960 | PC: 0x09d888..0x09d894 (12 B) | Symbol: sub_09d888
// EN: AArch64 prologue [bti c; add x0, x0, #0x428; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x428; ret]
uint64_t fde_sub_09d888(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9110A000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D888ULL;
}

// FDE #0961 | PC: 0x09d894..0x09d8a0 (12 B) | Symbol: sub_09d894
// EN: AArch64 prologue [bti c; add x0, x0, #0x10; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x10; ret]
uint64_t fde_sub_09d894(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91004000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D894ULL;
}

// FDE #0962 | PC: 0x09d8a0..0x09d8ac (12 B) | Symbol: sub_09d8a0
// EN: AArch64 prologue [bti c; add x0, x0, #0x160; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x160; ret]
uint64_t fde_sub_09d8a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91058000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D8A0ULL;
}

// FDE #0963 | PC: 0x09d8ac..0x09d8b8 (12 B) | Symbol: sub_09d8ac
// EN: AArch64 prologue [bti c; add x0, x0, #0x3a0; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x3a0; ret]
uint64_t fde_sub_09d8ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910E8000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D8ACULL;
}

// FDE #0964 | PC: 0x09d8b8..0x09d8c4 (12 B) | Symbol: sub_09d8b8
// EN: AArch64 prologue [bti c; add x0, x0, #0x3d0; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x3d0; ret]
uint64_t fde_sub_09d8b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910F4000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D8B8ULL;
}

// FDE #0965 | PC: 0x09d8c4..0x09d8d0 (12 B) | Symbol: sub_09d8c4
// EN: AArch64 prologue [bti c; add x0, x0, #0x3e8; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x3e8; ret]
uint64_t fde_sub_09d8c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910FA000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D8C4ULL;
}

// FDE #0966 | PC: 0x09d8d0..0x09d8dc (12 B) | Symbol: sub_09d8d0
// EN: AArch64 prologue [bti c; add x0, x0, #0x400; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x400; ret]
uint64_t fde_sub_09d8d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91100000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D8D0ULL;
}

// FDE #0967 | PC: 0x09d8dc..0x09d8e8 (12 B) | Symbol: sub_09d8dc
// EN: AArch64 prologue [bti c; add x0, x0, #0x418; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x418; ret]
uint64_t fde_sub_09d8dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91106000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D8DCULL;
}

// FDE #0968 | PC: 0x09d8e8..0x09d918 (48 B) | Symbol: sub_09d8e8
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09d8e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D8E8ULL;
}

// FDE #0969 | PC: 0x09d918..0x09d950 (56 B) | Symbol: sub_09d918
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09d918(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D918ULL;
}

// FDE #0970 | PC: 0x09d950..0x09d95c (12 B) | Symbol: sub_09d950
// EN: AArch64 prologue [bti c; add x0, x0, #0x18; b #0xc94f0] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x18; b #0xc94f0]
uint64_t fde_sub_09d950(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91006000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D950ULL;
}

// FDE #0971 | PC: 0x09d95c..0x09d968 (12 B) | Symbol: sub_09d95c
// EN: AArch64 prologue [bti c; add x0, x0, #0x20; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x20; ret]
uint64_t fde_sub_09d95c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91008000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D95CULL;
}

// FDE #0972 | PC: 0x09d968..0x09d974 (12 B) | Symbol: sub_09d968
// EN: AArch64 prologue [bti c; add x0, x0, #0x170; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x170; ret]
uint64_t fde_sub_09d968(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9105C000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D968ULL;
}

// FDE #0973 | PC: 0x09d974..0x09d980 (12 B) | Symbol: sub_09d974
// EN: AArch64 prologue [bti c; add x0, x0, #0x3b0; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x3b0; ret]
uint64_t fde_sub_09d974(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910EC000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D974ULL;
}

// FDE #0974 | PC: 0x09d980..0x09d98c (12 B) | Symbol: sub_09d980
// EN: AArch64 prologue [bti c; add x0, x0, #0x3e0; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x3e0; ret]
uint64_t fde_sub_09d980(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910F8000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D980ULL;
}

// FDE #0975 | PC: 0x09d98c..0x09d998 (12 B) | Symbol: sub_09d98c
// EN: AArch64 prologue [bti c; add x0, x0, #0x3f8; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x3f8; ret]
uint64_t fde_sub_09d98c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910FE000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D98CULL;
}

// FDE #0976 | PC: 0x09d998..0x09d9a4 (12 B) | Symbol: sub_09d998
// EN: AArch64 prologue [bti c; add x0, x0, #0x410; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x410; ret]
uint64_t fde_sub_09d998(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91104000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D998ULL;
}

// FDE #0977 | PC: 0x09d9a4..0x09d9b0 (12 B) | Symbol: sub_09d9a4
// EN: AArch64 prologue [bti c; add x0, x0, #0x428; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x428; ret]
uint64_t fde_sub_09d9a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9110A000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D9A4ULL;
}

// FDE #0978 | PC: 0x09d9b0..0x09d9bc (12 B) | Symbol: sub_09d9b0
// EN: AArch64 prologue [bti c; add x0, x0, #0x10; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x10; ret]
uint64_t fde_sub_09d9b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91004000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D9B0ULL;
}

// FDE #0979 | PC: 0x09d9bc..0x09d9c8 (12 B) | Symbol: sub_09d9bc
// EN: AArch64 prologue [bti c; add x0, x0, #0x160; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x160; ret]
uint64_t fde_sub_09d9bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91058000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D9BCULL;
}

// FDE #0980 | PC: 0x09d9c8..0x09d9d4 (12 B) | Symbol: sub_09d9c8
// EN: AArch64 prologue [bti c; add x0, x0, #0x3a0; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x3a0; ret]
uint64_t fde_sub_09d9c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910E8000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D9C8ULL;
}

// FDE #0981 | PC: 0x09d9d4..0x09d9e0 (12 B) | Symbol: sub_09d9d4
// EN: AArch64 prologue [bti c; add x0, x0, #0x3d0; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x3d0; ret]
uint64_t fde_sub_09d9d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910F4000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D9D4ULL;
}

// FDE #0982 | PC: 0x09d9e0..0x09d9ec (12 B) | Symbol: sub_09d9e0
// EN: AArch64 prologue [bti c; add x0, x0, #0x3e8; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x3e8; ret]
uint64_t fde_sub_09d9e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910FA000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D9E0ULL;
}

// FDE #0983 | PC: 0x09d9ec..0x09d9f8 (12 B) | Symbol: sub_09d9ec
// EN: AArch64 prologue [bti c; add x0, x0, #0x400; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x400; ret]
uint64_t fde_sub_09d9ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91100000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D9ECULL;
}

// FDE #0984 | PC: 0x09d9f8..0x09da04 (12 B) | Symbol: sub_09d9f8
// EN: AArch64 prologue [bti c; add x0, x0, #0x418; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x418; ret]
uint64_t fde_sub_09d9f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91106000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09D9F8ULL;
}

// FDE #0985 | PC: 0x09da04..0x09da3c (56 B) | Symbol: sub_09da04
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09da04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09DA04ULL;
}

// FDE #0986 | PC: 0x09da3c..0x09da6c (48 B) | Symbol: sub_09da3c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09da3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09DA3CULL;
}

// FDE #0987 | PC: 0x09da6c..0x09daa4 (56 B) | Symbol: sub_09da6c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09da6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09DA6CULL;
}

// FDE #0988 | PC: 0x09daa4..0x09dad4 (48 B) | Symbol: sub_09daa4
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09daa4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09DAA4ULL;
}

// FDE #0989 | PC: 0x09dad4..0x09db0c (56 B) | Symbol: sub_09dad4
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09dad4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09DAD4ULL;
}

// FDE #0990 | PC: 0x09db0c..0x09db44 (56 B) | Symbol: sub_09db0c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09db0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09DB0CULL;
}

// FDE #0991 | PC: 0x09db44..0x09db70 (44 B) | Symbol: sub_09db44
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09db44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09DB44ULL;
}

// FDE #0992 | PC: 0x09db70..0x09db9c (44 B) | Symbol: sub_09db70
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09db70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09DB70ULL;
}

// FDE #0993 | PC: 0x09db9c..0x09dbc8 (44 B) | Symbol: sub_09db9c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09db9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09DB9CULL;
}

// FDE #0994 | PC: 0x09dbc8..0x09dbd0 (8 B) | Symbol: _ZNSt6__ndk17codecvtIDic9mbstate_tED1Ev
// EN: AArch64 prologue [bti c; b #0xc8bd0] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8bd0]
uint64_t fde_sub_09dbc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400AC01ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09DBC8ULL;
}

// FDE #0995 | PC: 0x09dbd0..0x09dbfc (44 B) | Symbol: sub_09dbd0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09dbd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09DBD0ULL;
}

// FDE #0996 | PC: 0x09dbfc..0x09dc90 (148 B) | Symbol: sub_09dbfc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09dbfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09DBFCULL;
}

// FDE #0997 | PC: 0x09dc90..0x09dcbc (44 B) | Symbol: sub_09dc90
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09dc90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09DC90ULL;
}

// FDE #0998 | PC: 0x09dcbc..0x09dd50 (148 B) | Symbol: sub_09dcbc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09dcbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09DCBCULL;
}

// FDE #0999 | PC: 0x09dd50..0x09dd7c (44 B) | Symbol: sub_09dd50
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09dd50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09DD50ULL;
}

// FDE #1000 | PC: 0x09dd7c..0x09de10 (148 B) | Symbol: sub_09dd7c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09dd7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09DD7CULL;
}

// FDE #1001 | PC: 0x09de10..0x09de3c (44 B) | Symbol: sub_09de10
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09de10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09DE10ULL;
}

// FDE #1002 | PC: 0x09de3c..0x09ded0 (148 B) | Symbol: sub_09de3c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09de3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09DE3CULL;
}

// FDE #1003 | PC: 0x09ded0..0x09defc (44 B) | Symbol: sub_09ded0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09ded0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09DED0ULL;
}

// FDE #1004 | PC: 0x09defc..0x09df28 (44 B) | Symbol: sub_09defc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09defc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09DEFCULL;
}

// FDE #1005 | PC: 0x09df28..0x09df54 (44 B) | Symbol: sub_09df28
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09df28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09DF28ULL;
}

// FDE #1006 | PC: 0x09df54..0x09df80 (44 B) | Symbol: sub_09df54
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09df54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09DF54ULL;
}

// FDE #1007 | PC: 0x09df80..0x09dfac (44 B) | Symbol: sub_09df80
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09df80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09DF80ULL;
}

// FDE #1008 | PC: 0x09dfac..0x09dfd8 (44 B) | Symbol: sub_09dfac
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09dfac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09DFACULL;
}

// FDE #1009 | PC: 0x09dfd8..0x09e004 (44 B) | Symbol: sub_09dfd8
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09dfd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09DFD8ULL;
}

// FDE #1010 | PC: 0x09e004..0x09e030 (44 B) | Symbol: sub_09e004
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09e004(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09E004ULL;
}

// FDE #1011 | PC: 0x09e030..0x09e05c (44 B) | Symbol: sub_09e030
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09e030(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09E030ULL;
}

// FDE #1012 | PC: 0x09e05c..0x09e1cc (368 B) | Symbol: sub_09e05c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xd9000] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xd9000]
uint64_t fde_sub_09e05c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09E05CULL;
}

// FDE #1013 | PC: 0x09e1cc..0x09e33c (368 B) | Symbol: sub_09e1cc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xd9000] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xd9000]
uint64_t fde_sub_09e1cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09E1CCULL;
}

// FDE #1014 | PC: 0x09e33c..0x09e38c (80 B) | Symbol: sub_09e33c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09e33c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09E33CULL;
}

// FDE #1015 | PC: 0x09e38c..0x09e3dc (80 B) | Symbol: sub_09e38c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09e38c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09E38CULL;
}

// FDE #1016 | PC: 0x09e3dc..0x09e42c (80 B) | Symbol: sub_09e3dc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xda000] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xda000]
uint64_t fde_sub_09e3dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09E3DCULL;
}

// FDE #1017 | PC: 0x09e42c..0x09e47c (80 B) | Symbol: sub_09e42c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xda000] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xda000]
uint64_t fde_sub_09e42c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09E42CULL;
}

// FDE #1018 | PC: 0x09e47c..0x09e604 (392 B) | Symbol: sub_09e47c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x50]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x50]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_09e47c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0188ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09E47CULL;
}

// FDE #1019 | PC: 0x09e604..0x09e754 (336 B) | Symbol: sub_09e604
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_09e604(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0150ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09E604ULL;
}

// FDE #1020 | PC: 0x09e754..0x09e77c (40 B) | Symbol: sub_09e754
// EN: AArch64 prologue [bti c; ldr x8, [x0]; ldr x8, [x8]; ldp x16, x9, [x8, #8]] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0]; ldr x8, [x8]; ldp x16, x9, [x8, #8]]
uint64_t fde_sub_09e754(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09E754ULL;
}

// FDE #1021 | PC: 0x09e77c..0x09e7fc (128 B) | Symbol: sub_09e77c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09e77c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09E77CULL;
}

// FDE #1022 | PC: 0x09e7fc..0x09e858 (92 B) | Symbol: sub_09e7fc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09e7fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09E7FCULL;
}

// FDE #1023 | PC: 0x09e858..0x09e9a8 (336 B) | Symbol: sub_09e858
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_09e858(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0150ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09E858ULL;
}

// FDE #1024 | PC: 0x09e9a8..0x09eaf8 (336 B) | Symbol: sub_09e9a8
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_09e9a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0150ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09E9A8ULL;
}

// FDE #1025 | PC: 0x09eaf8..0x09ec7c (388 B) | Symbol: sub_09eaf8
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x10]; str x27, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x10]; str x27, [sp, #0x20]]
uint64_t fde_sub_09eaf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0184ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09EAF8ULL;
}

// FDE #1026 | PC: 0x09ec7c..0x09ee00 (388 B) | Symbol: sub_09ec7c
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x10]; str x27, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x10]; str x27, [sp, #0x20]]
uint64_t fde_sub_09ec7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0184ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09EC7CULL;
}

// FDE #1027 | PC: 0x09ee00..0x09ef74 (372 B) | Symbol: sub_09ee00
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x10]; str x27, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x10]; str x27, [sp, #0x20]]
uint64_t fde_sub_09ee00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0174ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09EE00ULL;
}

// FDE #1028 | PC: 0x09ef74..0x09f0e8 (372 B) | Symbol: sub_09ef74
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x10]; str x27, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x10]; str x27, [sp, #0x20]]
uint64_t fde_sub_09ef74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0174ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09EF74ULL;
}

// FDE #1029 | PC: 0x09f0e8..0x09f214 (300 B) | Symbol: sub_09f0e8
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_09f0e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09F0E8ULL;
}

// FDE #1030 | PC: 0x09f214..0x09f340 (300 B) | Symbol: sub_09f214
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_09f214(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09F214ULL;
}

// FDE #1031 | PC: 0x09f340..0x09f478 (312 B) | Symbol: sub_09f340
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x10]; str x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x10]; str x25, [sp, #0x20]]
uint64_t fde_sub_09f340(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0138ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09F340ULL;
}

// FDE #1032 | PC: 0x09f478..0x09f6e0 (616 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE23__append_forward_unsafeIPcEERS5_T_S9_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]]
uint64_t fde_sub_09f478(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0268ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09F478ULL;
}

// FDE #1033 | PC: 0x09f6e0..0x09f968 (648 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE23__append_forward_unsafeIPwEERS5_T_S9_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; stp x26, x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; stp x26, x25, [sp, #0x30]]
uint64_t fde_sub_09f6e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0288ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09F6E0ULL;
}

// FDE #1034 | PC: 0x09f968..0x09fb98 (560 B) | Symbol: sub_09f968
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09f968(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0230ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09F968ULL;
}

// FDE #1035 | PC: 0x09fb98..0x09fdc8 (560 B) | Symbol: sub_09fb98
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09fb98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0230ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09FB98ULL;
}

// FDE #1036 | PC: 0x09fdc8..0x09fdd0 (8 B) | Symbol: _ZNSt6__ndk112bad_weak_ptrD1Ev
// EN: AArch64 prologue [bti c; b #0xc95a0] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc95a0]
uint64_t fde_sub_09fdc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400A5F5ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09FDC8ULL;
}

// FDE #1037 | PC: 0x09fdd0..0x09fdfc (44 B) | Symbol: _ZNSt6__ndk112bad_weak_ptrD0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09fdd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09FDD0ULL;
}

// FDE #1038 | PC: 0x09fdfc..0x09fe0c (16 B) | Symbol: _ZNKSt6__ndk112bad_weak_ptr4whatEv
// EN: AArch64 prologue [bti c; adrp x0, #0x48000; add x0, x0, #0xfed; ret] | VI: Khởi đầu hàm AArch64 [bti c; adrp x0, #0x48000; add x0, x0, #0xfed; ret]
uint64_t fde_sub_09fdfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0FFFD40ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09FDFCULL;
}

// FDE #1039 | PC: 0x09fe0c..0x09fe14 (8 B) | Symbol: _ZNSt6__ndk114__shared_countD2Ev
// EN: AArch64 prologue [bti c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ret]
uint64_t fde_sub_09fe0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09FE0CULL;
}

// FDE #1040 | PC: 0x09fe14..0x09fe1c (8 B) | Symbol: _ZNSt6__ndk114__shared_countD0Ev
// EN: AArch64 prologue [bti c; brk #1] | VI: Khởi đầu hàm AArch64 [bti c; brk #1]
uint64_t fde_sub_09fe14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD4200020ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09FE14ULL;
}

// FDE #1041 | PC: 0x09fe1c..0x09fe24 (8 B) | Symbol: _ZNSt6__ndk119__shared_weak_countD0Ev
// EN: AArch64 prologue [bti c; brk #1] | VI: Khởi đầu hàm AArch64 [bti c; brk #1]
uint64_t fde_sub_09fe1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD4200020ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09FE1CULL;
}

// FDE #1042 | PC: 0x09fe24..0x09fe40 (28 B) | Symbol: _ZNSt6__ndk114__shared_count12__add_sharedEv
// EN: AArch64 prologue [bti c; add x8, x0, #8; ldxr x9, [x8]; add x9, x9, #1] | VI: Khởi đầu hàm AArch64 [bti c; add x8, x0, #8; ldxr x9, [x8]; add x9, x9, #1]
uint64_t fde_sub_09fe24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91002008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09FE24ULL;
}

// FDE #1043 | PC: 0x09fe40..0x09fe8c (76 B) | Symbol: _ZNSt6__ndk114__shared_count16__release_sharedEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09fe40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09FE40ULL;
}

// FDE #1044 | PC: 0x09fe8c..0x09fea8 (28 B) | Symbol: _ZNSt6__ndk119__shared_weak_count12__add_sharedEv
// EN: AArch64 prologue [bti c; add x8, x0, #8; ldxr x9, [x8]; add x9, x9, #1] | VI: Khởi đầu hàm AArch64 [bti c; add x8, x0, #8; ldxr x9, [x8]; add x9, x9, #1]
uint64_t fde_sub_09fe8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91002008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09FE8CULL;
}

// FDE #1045 | PC: 0x09fea8..0x09fec4 (28 B) | Symbol: _ZNSt6__ndk119__shared_weak_count10__add_weakEv
// EN: AArch64 prologue [bti c; add x8, x0, #0x10; ldxr x9, [x8]; add x9, x9, #1] | VI: Khởi đầu hàm AArch64 [bti c; add x8, x0, #0x10; ldxr x9, [x8]; add x9, x9, #1]
uint64_t fde_sub_09fea8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91004008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09FEA8ULL;
}

// FDE #1046 | PC: 0x09fec4..0x09ff4c (136 B) | Symbol: _ZNSt6__ndk119__shared_weak_count16__release_sharedEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09fec4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09FEC4ULL;
}

// FDE #1047 | PC: 0x09ff4c..0x09ff80 (52 B) | Symbol: _ZNSt6__ndk119__shared_weak_count14__release_weakEv
// EN: AArch64 prologue [bti c; add x8, x0, #0x10; ldar x9, [x8]; cbz x9, #0x9ff74] | VI: Khởi đầu hàm AArch64 [bti c; add x8, x0, #0x10; ldar x9, [x8]; cbz x9, #0x9ff74]
uint64_t fde_sub_09ff4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91004008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09FF4CULL;
}

// FDE #1048 | PC: 0x09ff80..0x09ffd4 (84 B) | Symbol: _ZNSt6__ndk119__shared_weak_count4lockEv
// EN: AArch64 prologue [bti c; add x8, x0, #8; ldar x10, [x8]; cmn x10, #1] | VI: Khởi đầu hàm AArch64 [bti c; add x8, x0, #8; ldar x10, [x8]; cmn x10, #1]
uint64_t fde_sub_09ff80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91002008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09FF80ULL;
}

// FDE #1049 | PC: 0x09ffd4..0x09ffe0 (12 B) | Symbol: _ZNKSt6__ndk119__shared_weak_count13__get_deleterERKSt9type_info
// EN: AArch64 prologue [bti c; mov x0, xzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov x0, xzr; ret]
uint64_t fde_sub_09ffd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09FFD4ULL;
}

// FDE #1050 | PC: 0x09ffe0..0x0a0038 (88 B) | Symbol: _ZNSt6__ndk18__sp_mut4lockEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09ffe0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09FFE0ULL;
}

// FDE #1051 | PC: 0x0a0038..0x0a005c (36 B) | Symbol: _ZNSt6__ndk18__sp_mut6unlockEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x0, [x0]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x0, [x0]]
uint64_t fde_sub_0a0038(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0038ULL;
}

// FDE #1052 | PC: 0x0a005c..0x0a00b8 (92 B) | Symbol: _ZNSt6__ndk112__get_sp_mutEPKv
// EN: AArch64 prologue [bti c; mov x10, #0x2d69; lsl w9, w0, #3; movk x10, #0xeb38, lsl #16] | VI: Khởi đầu hàm AArch64 [bti c; mov x10, #0x2d69; lsl w9, w0, #3; movk x10, #0xeb38, lsl #16]
uint64_t fde_sub_0a005c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD285AD2AULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A005CULL;
}

// FDE #1053 | PC: 0x0a00b8..0x0a00c0 (8 B) | Symbol: _ZNSt6__ndk117declare_reachableEPv
// EN: AArch64 prologue [bti c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ret]
uint64_t fde_sub_0a00b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A00B8ULL;
}

// FDE #1054 | PC: 0x0a00c0..0x0a00c8 (8 B) | Symbol: _ZNSt6__ndk119declare_no_pointersEPcm
// EN: AArch64 prologue [bti c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ret]
uint64_t fde_sub_0a00c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A00C0ULL;
}

// FDE #1055 | PC: 0x0a00c8..0x0a00d0 (8 B) | Symbol: _ZNSt6__ndk121undeclare_no_pointersEPcm
// EN: AArch64 prologue [bti c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ret]
uint64_t fde_sub_0a00c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A00C8ULL;
}

uint64_t DispatchAppLovinShard3(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x0900dcULL: return fde_sub_0900dc(a0, a1, a2);
        case 0x090188ULL: return fde_sub_090188(a0, a1, a2);
        case 0x090264ULL: return fde_sub_090264(a0, a1, a2);
        case 0x090310ULL: return fde_sub_090310(a0, a1, a2);
        case 0x0903ecULL: return fde_sub_0903ec(a0, a1, a2);
        case 0x0903f8ULL: return fde_sub_0903f8(a0, a1, a2);
        case 0x0904c4ULL: return fde_sub_0904c4(a0, a1, a2);
        case 0x0904d8ULL: return fde_sub_0904d8(a0, a1, a2);
        case 0x0905b8ULL: return fde_sub_0905b8(a0, a1, a2);
        case 0x090760ULL: return fde_sub_090760(a0, a1, a2);
        case 0x090870ULL: return fde_sub_090870(a0, a1, a2);
        case 0x0908f0ULL: return fde_sub_0908f0(a0, a1, a2);
        case 0x090918ULL: return fde_sub_090918(a0, a1, a2);
        case 0x090974ULL: return fde_sub_090974(a0, a1, a2);
        case 0x09099cULL: return fde_sub_09099c(a0, a1, a2);
        case 0x0909f8ULL: return fde_sub_0909f8(a0, a1, a2);
        case 0x090b6cULL: return fde_sub_090b6c(a0, a1, a2);
        case 0x090c48ULL: return fde_sub_090c48(a0, a1, a2);
        case 0x090ca4ULL: return fde_sub_090ca4(a0, a1, a2);
        case 0x090e1cULL: return fde_sub_090e1c(a0, a1, a2);
        case 0x090fb8ULL: return fde_sub_090fb8(a0, a1, a2);
        case 0x0910e8ULL: return fde_sub_0910e8(a0, a1, a2);
        case 0x091218ULL: return fde_sub_091218(a0, a1, a2);
        case 0x09122cULL: return fde_sub_09122c(a0, a1, a2);
        case 0x091288ULL: return fde_sub_091288(a0, a1, a2);
        case 0x09129cULL: return fde_sub_09129c(a0, a1, a2);
        case 0x0912f8ULL: return fde_sub_0912f8(a0, a1, a2);
        case 0x091364ULL: return fde_sub_091364(a0, a1, a2);
        case 0x091414ULL: return fde_sub_091414(a0, a1, a2);
        case 0x091490ULL: return fde_sub_091490(a0, a1, a2);
        case 0x091554ULL: return fde_sub_091554(a0, a1, a2);
        case 0x091580ULL: return fde_sub_091580(a0, a1, a2);
        case 0x091594ULL: return fde_sub_091594(a0, a1, a2);
        case 0x0915a8ULL: return fde_sub_0915a8(a0, a1, a2);
        case 0x0915b8ULL: return fde_sub_0915b8(a0, a1, a2);
        case 0x0915c4ULL: return fde_sub_0915c4(a0, a1, a2);
        case 0x0915d0ULL: return fde_sub_0915d0(a0, a1, a2);
        case 0x0915e4ULL: return fde_sub_0915e4(a0, a1, a2);
        case 0x0915f0ULL: return fde_sub_0915f0(a0, a1, a2);
        case 0x09169cULL: return fde_sub_09169c(a0, a1, a2);
        case 0x091810ULL: return fde_sub_091810(a0, a1, a2);
        case 0x09183cULL: return fde_sub_09183c(a0, a1, a2);
        case 0x091b84ULL: return fde_sub_091b84(a0, a1, a2);
        case 0x091ea4ULL: return fde_sub_091ea4(a0, a1, a2);
        case 0x091fccULL: return fde_sub_091fcc(a0, a1, a2);
        case 0x0920a8ULL: return fde_sub_0920a8(a0, a1, a2);
        case 0x0920b4ULL: return fde_sub_0920b4(a0, a1, a2);
        case 0x0921b0ULL: return fde_sub_0921b0(a0, a1, a2);
        case 0x092228ULL: return fde_sub_092228(a0, a1, a2);
        case 0x092254ULL: return fde_sub_092254(a0, a1, a2);
        case 0x0922ecULL: return fde_sub_0922ec(a0, a1, a2);
        case 0x09250cULL: return fde_sub_09250c(a0, a1, a2);
        case 0x0925a4ULL: return fde_sub_0925a4(a0, a1, a2);
        case 0x092820ULL: return fde_sub_092820(a0, a1, a2);
        case 0x092830ULL: return fde_sub_092830(a0, a1, a2);
        case 0x09283cULL: return fde_sub_09283c(a0, a1, a2);
        case 0x092848ULL: return fde_sub_092848(a0, a1, a2);
        case 0x092864ULL: return fde_sub_092864(a0, a1, a2);
        case 0x092a64ULL: return fde_sub_092a64(a0, a1, a2);
        case 0x092a70ULL: return fde_sub_092a70(a0, a1, a2);
        case 0x092a9cULL: return fde_sub_092a9c(a0, a1, a2);
        case 0x092b34ULL: return fde_sub_092b34(a0, a1, a2);
        case 0x092cb8ULL: return fde_sub_092cb8(a0, a1, a2);
        case 0x092d50ULL: return fde_sub_092d50(a0, a1, a2);
        case 0x092f88ULL: return fde_sub_092f88(a0, a1, a2);
        case 0x092f98ULL: return fde_sub_092f98(a0, a1, a2);
        case 0x092fa4ULL: return fde_sub_092fa4(a0, a1, a2);
        case 0x092fb0ULL: return fde_sub_092fb0(a0, a1, a2);
        case 0x092fccULL: return fde_sub_092fcc(a0, a1, a2);
        case 0x0931c8ULL: return fde_sub_0931c8(a0, a1, a2);
        case 0x0931d4ULL: return fde_sub_0931d4(a0, a1, a2);
        case 0x093270ULL: return fde_sub_093270(a0, a1, a2);
        case 0x09330cULL: return fde_sub_09330c(a0, a1, a2);
        case 0x09331cULL: return fde_sub_09331c(a0, a1, a2);
        case 0x093328ULL: return fde_sub_093328(a0, a1, a2);
        case 0x093334ULL: return fde_sub_093334(a0, a1, a2);
        case 0x093354ULL: return fde_sub_093354(a0, a1, a2);
        case 0x093370ULL: return fde_sub_093370(a0, a1, a2);
        case 0x093478ULL: return fde_sub_093478(a0, a1, a2);
        case 0x09360cULL: return fde_sub_09360c(a0, a1, a2);
        case 0x09361cULL: return fde_sub_09361c(a0, a1, a2);
        case 0x093628ULL: return fde_sub_093628(a0, a1, a2);
        case 0x093634ULL: return fde_sub_093634(a0, a1, a2);
        case 0x09379cULL: return fde_sub_09379c(a0, a1, a2);
        case 0x0937b8ULL: return fde_sub_0937b8(a0, a1, a2);
        case 0x093854ULL: return fde_sub_093854(a0, a1, a2);
        case 0x0938f0ULL: return fde_sub_0938f0(a0, a1, a2);
        case 0x093900ULL: return fde_sub_093900(a0, a1, a2);
        case 0x09390cULL: return fde_sub_09390c(a0, a1, a2);
        case 0x093918ULL: return fde_sub_093918(a0, a1, a2);
        case 0x093938ULL: return fde_sub_093938(a0, a1, a2);
        case 0x093954ULL: return fde_sub_093954(a0, a1, a2);
        case 0x093a38ULL: return fde_sub_093a38(a0, a1, a2);
        case 0x093b44ULL: return fde_sub_093b44(a0, a1, a2);
        case 0x093b54ULL: return fde_sub_093b54(a0, a1, a2);
        case 0x093b60ULL: return fde_sub_093b60(a0, a1, a2);
        case 0x093b6cULL: return fde_sub_093b6c(a0, a1, a2);
        case 0x093c6cULL: return fde_sub_093c6c(a0, a1, a2);
        case 0x093c88ULL: return fde_sub_093c88(a0, a1, a2);
        case 0x093d5cULL: return fde_sub_093d5c(a0, a1, a2);
        case 0x093e68ULL: return fde_sub_093e68(a0, a1, a2);
        case 0x093e78ULL: return fde_sub_093e78(a0, a1, a2);
        case 0x093e84ULL: return fde_sub_093e84(a0, a1, a2);
        case 0x093e90ULL: return fde_sub_093e90(a0, a1, a2);
        case 0x093f90ULL: return fde_sub_093f90(a0, a1, a2);
        case 0x093facULL: return fde_sub_093fac(a0, a1, a2);
        case 0x09402cULL: return fde_sub_09402c(a0, a1, a2);
        case 0x0940c0ULL: return fde_sub_0940c0(a0, a1, a2);
        case 0x0940d0ULL: return fde_sub_0940d0(a0, a1, a2);
        case 0x0940dcULL: return fde_sub_0940dc(a0, a1, a2);
        case 0x0940e8ULL: return fde_sub_0940e8(a0, a1, a2);
        case 0x094180ULL: return fde_sub_094180(a0, a1, a2);
        case 0x09419cULL: return fde_sub_09419c(a0, a1, a2);
        case 0x094218ULL: return fde_sub_094218(a0, a1, a2);
        case 0x0942acULL: return fde_sub_0942ac(a0, a1, a2);
        case 0x0942bcULL: return fde_sub_0942bc(a0, a1, a2);
        case 0x0942c8ULL: return fde_sub_0942c8(a0, a1, a2);
        case 0x0942d4ULL: return fde_sub_0942d4(a0, a1, a2);
        case 0x094384ULL: return fde_sub_094384(a0, a1, a2);
        case 0x0943a0ULL: return fde_sub_0943a0(a0, a1, a2);
        case 0x094484ULL: return fde_sub_094484(a0, a1, a2);
        case 0x094590ULL: return fde_sub_094590(a0, a1, a2);
        case 0x0945a0ULL: return fde_sub_0945a0(a0, a1, a2);
        case 0x0945acULL: return fde_sub_0945ac(a0, a1, a2);
        case 0x0945b8ULL: return fde_sub_0945b8(a0, a1, a2);
        case 0x0946b8ULL: return fde_sub_0946b8(a0, a1, a2);
        case 0x0946d4ULL: return fde_sub_0946d4(a0, a1, a2);
        case 0x0947a8ULL: return fde_sub_0947a8(a0, a1, a2);
        case 0x0948b4ULL: return fde_sub_0948b4(a0, a1, a2);
        case 0x0948c4ULL: return fde_sub_0948c4(a0, a1, a2);
        case 0x0948d0ULL: return fde_sub_0948d0(a0, a1, a2);
        case 0x0948dcULL: return fde_sub_0948dc(a0, a1, a2);
        case 0x0949dcULL: return fde_sub_0949dc(a0, a1, a2);
        case 0x0949f8ULL: return fde_sub_0949f8(a0, a1, a2);
        case 0x094a94ULL: return fde_sub_094a94(a0, a1, a2);
        case 0x094cb8ULL: return fde_sub_094cb8(a0, a1, a2);
        case 0x094d54ULL: return fde_sub_094d54(a0, a1, a2);
        case 0x094fd0ULL: return fde_sub_094fd0(a0, a1, a2);
        case 0x094fe0ULL: return fde_sub_094fe0(a0, a1, a2);
        case 0x094fecULL: return fde_sub_094fec(a0, a1, a2);
        case 0x094ff8ULL: return fde_sub_094ff8(a0, a1, a2);
        case 0x095018ULL: return fde_sub_095018(a0, a1, a2);
        case 0x095034ULL: return fde_sub_095034(a0, a1, a2);
        case 0x0950d0ULL: return fde_sub_0950d0(a0, a1, a2);
        case 0x09516cULL: return fde_sub_09516c(a0, a1, a2);
        case 0x09517cULL: return fde_sub_09517c(a0, a1, a2);
        case 0x095188ULL: return fde_sub_095188(a0, a1, a2);
        case 0x095194ULL: return fde_sub_095194(a0, a1, a2);
        case 0x0951b4ULL: return fde_sub_0951b4(a0, a1, a2);
        case 0x0951d0ULL: return fde_sub_0951d0(a0, a1, a2);
        case 0x09526cULL: return fde_sub_09526c(a0, a1, a2);
        case 0x095308ULL: return fde_sub_095308(a0, a1, a2);
        case 0x095318ULL: return fde_sub_095318(a0, a1, a2);
        case 0x095324ULL: return fde_sub_095324(a0, a1, a2);
        case 0x095330ULL: return fde_sub_095330(a0, a1, a2);
        case 0x095350ULL: return fde_sub_095350(a0, a1, a2);
        case 0x09536cULL: return fde_sub_09536c(a0, a1, a2);
        case 0x095398ULL: return fde_sub_095398(a0, a1, a2);
        case 0x0953c4ULL: return fde_sub_0953c4(a0, a1, a2);
        case 0x0953f0ULL: return fde_sub_0953f0(a0, a1, a2);
        case 0x09541cULL: return fde_sub_09541c(a0, a1, a2);
        case 0x095448ULL: return fde_sub_095448(a0, a1, a2);
        case 0x095478ULL: return fde_sub_095478(a0, a1, a2);
        case 0x0954c0ULL: return fde_sub_0954c0(a0, a1, a2);
        case 0x095510ULL: return fde_sub_095510(a0, a1, a2);
        case 0x095558ULL: return fde_sub_095558(a0, a1, a2);
        case 0x0955a8ULL: return fde_sub_0955a8(a0, a1, a2);
        case 0x0955b4ULL: return fde_sub_0955b4(a0, a1, a2);
        case 0x0955c0ULL: return fde_sub_0955c0(a0, a1, a2);
        case 0x0955ccULL: return fde_sub_0955cc(a0, a1, a2);
        case 0x0955d8ULL: return fde_sub_0955d8(a0, a1, a2);
        case 0x0955e8ULL: return fde_sub_0955e8(a0, a1, a2);
        case 0x0955f8ULL: return fde_sub_0955f8(a0, a1, a2);
        case 0x095618ULL: return fde_sub_095618(a0, a1, a2);
        case 0x09562cULL: return fde_sub_09562c(a0, a1, a2);
        case 0x0956ccULL: return fde_sub_0956cc(a0, a1, a2);
        case 0x0956f0ULL: return fde_sub_0956f0(a0, a1, a2);
        case 0x095704ULL: return fde_sub_095704(a0, a1, a2);
        case 0x095784ULL: return fde_sub_095784(a0, a1, a2);
        case 0x095b34ULL: return fde_sub_095b34(a0, a1, a2);
        case 0x095bc4ULL: return fde_sub_095bc4(a0, a1, a2);
        case 0x095c14ULL: return fde_sub_095c14(a0, a1, a2);
        case 0x095c98ULL: return fde_sub_095c98(a0, a1, a2);
        case 0x095f68ULL: return fde_sub_095f68(a0, a1, a2);
        case 0x095ffcULL: return fde_sub_095ffc(a0, a1, a2);
        case 0x09604cULL: return fde_sub_09604c(a0, a1, a2);
        case 0x096090ULL: return fde_sub_096090(a0, a1, a2);
        case 0x0962a8ULL: return fde_sub_0962a8(a0, a1, a2);
        case 0x0964c0ULL: return fde_sub_0964c0(a0, a1, a2);
        case 0x09677cULL: return fde_sub_09677c(a0, a1, a2);
        case 0x096a38ULL: return fde_sub_096a38(a0, a1, a2);
        case 0x096b3cULL: return fde_sub_096b3c(a0, a1, a2);
        case 0x096c40ULL: return fde_sub_096c40(a0, a1, a2);
        case 0x096cccULL: return fde_sub_096ccc(a0, a1, a2);
        case 0x096d6cULL: return fde_sub_096d6c(a0, a1, a2);
        case 0x096df8ULL: return fde_sub_096df8(a0, a1, a2);
        case 0x096e98ULL: return fde_sub_096e98(a0, a1, a2);
        case 0x096f2cULL: return fde_sub_096f2c(a0, a1, a2);
        case 0x096fccULL: return fde_sub_096fcc(a0, a1, a2);
        case 0x097060ULL: return fde_sub_097060(a0, a1, a2);
        case 0x097100ULL: return fde_sub_097100(a0, a1, a2);
        case 0x09725cULL: return fde_sub_09725c(a0, a1, a2);
        case 0x097310ULL: return fde_sub_097310(a0, a1, a2);
        case 0x097334ULL: return fde_sub_097334(a0, a1, a2);
        case 0x097970ULL: return fde_sub_097970(a0, a1, a2);
        case 0x097cc4ULL: return fde_sub_097cc4(a0, a1, a2);
        case 0x0983e0ULL: return fde_sub_0983e0(a0, a1, a2);
        case 0x098730ULL: return fde_sub_098730(a0, a1, a2);
        case 0x0989d0ULL: return fde_sub_0989d0(a0, a1, a2);
        case 0x099598ULL: return fde_sub_099598(a0, a1, a2);
        case 0x0998ecULL: return fde_sub_0998ec(a0, a1, a2);
        case 0x099964ULL: return fde_sub_099964(a0, a1, a2);
        case 0x099d0cULL: return fde_sub_099d0c(a0, a1, a2);
        case 0x09a018ULL: return fde_sub_09a018(a0, a1, a2);
        case 0x09a06cULL: return fde_sub_09a06c(a0, a1, a2);
        case 0x09a3ccULL: return fde_sub_09a3cc(a0, a1, a2);
        case 0x09a82cULL: return fde_sub_09a82c(a0, a1, a2);
        case 0x09ac8cULL: return fde_sub_09ac8c(a0, a1, a2);
        case 0x09ade8ULL: return fde_sub_09ade8(a0, a1, a2);
        case 0x09ae9cULL: return fde_sub_09ae9c(a0, a1, a2);
        case 0x09af48ULL: return fde_sub_09af48(a0, a1, a2);
        case 0x09b3c8ULL: return fde_sub_09b3c8(a0, a1, a2);
        case 0x09b95cULL: return fde_sub_09b95c(a0, a1, a2);
        case 0x09bddcULL: return fde_sub_09bddc(a0, a1, a2);
        case 0x09c614ULL: return fde_sub_09c614(a0, a1, a2);
        case 0x09cba0ULL: return fde_sub_09cba0(a0, a1, a2);
        case 0x09d3d8ULL: return fde_sub_09d3d8(a0, a1, a2);
        case 0x09d404ULL: return fde_sub_09d404(a0, a1, a2);
        case 0x09d430ULL: return fde_sub_09d430(a0, a1, a2);
        case 0x09d45cULL: return fde_sub_09d45c(a0, a1, a2);
        case 0x09d488ULL: return fde_sub_09d488(a0, a1, a2);
        case 0x09d4b4ULL: return fde_sub_09d4b4(a0, a1, a2);
        case 0x09d4e0ULL: return fde_sub_09d4e0(a0, a1, a2);
        case 0x09d50cULL: return fde_sub_09d50c(a0, a1, a2);
        case 0x09d538ULL: return fde_sub_09d538(a0, a1, a2);
        case 0x09d564ULL: return fde_sub_09d564(a0, a1, a2);
        case 0x09d630ULL: return fde_sub_09d630(a0, a1, a2);
        case 0x09d65cULL: return fde_sub_09d65c(a0, a1, a2);
        case 0x09d688ULL: return fde_sub_09d688(a0, a1, a2);
        case 0x09d6b4ULL: return fde_sub_09d6b4(a0, a1, a2);
        case 0x09d6e0ULL: return fde_sub_09d6e0(a0, a1, a2);
        case 0x09d70cULL: return fde_sub_09d70c(a0, a1, a2);
        case 0x09d738ULL: return fde_sub_09d738(a0, a1, a2);
        case 0x09d764ULL: return fde_sub_09d764(a0, a1, a2);
        case 0x09d76cULL: return fde_sub_09d76c(a0, a1, a2);
        case 0x09d798ULL: return fde_sub_09d798(a0, a1, a2);
        case 0x09d7a0ULL: return fde_sub_09d7a0(a0, a1, a2);
        case 0x09d7ccULL: return fde_sub_09d7cc(a0, a1, a2);
        case 0x09d7fcULL: return fde_sub_09d7fc(a0, a1, a2);
        case 0x09d834ULL: return fde_sub_09d834(a0, a1, a2);
        case 0x09d840ULL: return fde_sub_09d840(a0, a1, a2);
        case 0x09d84cULL: return fde_sub_09d84c(a0, a1, a2);
        case 0x09d858ULL: return fde_sub_09d858(a0, a1, a2);
        case 0x09d864ULL: return fde_sub_09d864(a0, a1, a2);
        case 0x09d870ULL: return fde_sub_09d870(a0, a1, a2);
        case 0x09d87cULL: return fde_sub_09d87c(a0, a1, a2);
        case 0x09d888ULL: return fde_sub_09d888(a0, a1, a2);
        case 0x09d894ULL: return fde_sub_09d894(a0, a1, a2);
        case 0x09d8a0ULL: return fde_sub_09d8a0(a0, a1, a2);
        case 0x09d8acULL: return fde_sub_09d8ac(a0, a1, a2);
        case 0x09d8b8ULL: return fde_sub_09d8b8(a0, a1, a2);
        case 0x09d8c4ULL: return fde_sub_09d8c4(a0, a1, a2);
        case 0x09d8d0ULL: return fde_sub_09d8d0(a0, a1, a2);
        case 0x09d8dcULL: return fde_sub_09d8dc(a0, a1, a2);
        case 0x09d8e8ULL: return fde_sub_09d8e8(a0, a1, a2);
        case 0x09d918ULL: return fde_sub_09d918(a0, a1, a2);
        case 0x09d950ULL: return fde_sub_09d950(a0, a1, a2);
        case 0x09d95cULL: return fde_sub_09d95c(a0, a1, a2);
        case 0x09d968ULL: return fde_sub_09d968(a0, a1, a2);
        case 0x09d974ULL: return fde_sub_09d974(a0, a1, a2);
        case 0x09d980ULL: return fde_sub_09d980(a0, a1, a2);
        case 0x09d98cULL: return fde_sub_09d98c(a0, a1, a2);
        case 0x09d998ULL: return fde_sub_09d998(a0, a1, a2);
        case 0x09d9a4ULL: return fde_sub_09d9a4(a0, a1, a2);
        case 0x09d9b0ULL: return fde_sub_09d9b0(a0, a1, a2);
        case 0x09d9bcULL: return fde_sub_09d9bc(a0, a1, a2);
        case 0x09d9c8ULL: return fde_sub_09d9c8(a0, a1, a2);
        case 0x09d9d4ULL: return fde_sub_09d9d4(a0, a1, a2);
        case 0x09d9e0ULL: return fde_sub_09d9e0(a0, a1, a2);
        case 0x09d9ecULL: return fde_sub_09d9ec(a0, a1, a2);
        case 0x09d9f8ULL: return fde_sub_09d9f8(a0, a1, a2);
        case 0x09da04ULL: return fde_sub_09da04(a0, a1, a2);
        case 0x09da3cULL: return fde_sub_09da3c(a0, a1, a2);
        case 0x09da6cULL: return fde_sub_09da6c(a0, a1, a2);
        case 0x09daa4ULL: return fde_sub_09daa4(a0, a1, a2);
        case 0x09dad4ULL: return fde_sub_09dad4(a0, a1, a2);
        case 0x09db0cULL: return fde_sub_09db0c(a0, a1, a2);
        case 0x09db44ULL: return fde_sub_09db44(a0, a1, a2);
        case 0x09db70ULL: return fde_sub_09db70(a0, a1, a2);
        case 0x09db9cULL: return fde_sub_09db9c(a0, a1, a2);
        case 0x09dbc8ULL: return fde_sub_09dbc8(a0, a1, a2);
        case 0x09dbd0ULL: return fde_sub_09dbd0(a0, a1, a2);
        case 0x09dbfcULL: return fde_sub_09dbfc(a0, a1, a2);
        case 0x09dc90ULL: return fde_sub_09dc90(a0, a1, a2);
        case 0x09dcbcULL: return fde_sub_09dcbc(a0, a1, a2);
        case 0x09dd50ULL: return fde_sub_09dd50(a0, a1, a2);
        case 0x09dd7cULL: return fde_sub_09dd7c(a0, a1, a2);
        case 0x09de10ULL: return fde_sub_09de10(a0, a1, a2);
        case 0x09de3cULL: return fde_sub_09de3c(a0, a1, a2);
        case 0x09ded0ULL: return fde_sub_09ded0(a0, a1, a2);
        case 0x09defcULL: return fde_sub_09defc(a0, a1, a2);
        case 0x09df28ULL: return fde_sub_09df28(a0, a1, a2);
        case 0x09df54ULL: return fde_sub_09df54(a0, a1, a2);
        case 0x09df80ULL: return fde_sub_09df80(a0, a1, a2);
        case 0x09dfacULL: return fde_sub_09dfac(a0, a1, a2);
        case 0x09dfd8ULL: return fde_sub_09dfd8(a0, a1, a2);
        case 0x09e004ULL: return fde_sub_09e004(a0, a1, a2);
        case 0x09e030ULL: return fde_sub_09e030(a0, a1, a2);
        case 0x09e05cULL: return fde_sub_09e05c(a0, a1, a2);
        case 0x09e1ccULL: return fde_sub_09e1cc(a0, a1, a2);
        case 0x09e33cULL: return fde_sub_09e33c(a0, a1, a2);
        case 0x09e38cULL: return fde_sub_09e38c(a0, a1, a2);
        case 0x09e3dcULL: return fde_sub_09e3dc(a0, a1, a2);
        case 0x09e42cULL: return fde_sub_09e42c(a0, a1, a2);
        case 0x09e47cULL: return fde_sub_09e47c(a0, a1, a2);
        case 0x09e604ULL: return fde_sub_09e604(a0, a1, a2);
        case 0x09e754ULL: return fde_sub_09e754(a0, a1, a2);
        case 0x09e77cULL: return fde_sub_09e77c(a0, a1, a2);
        case 0x09e7fcULL: return fde_sub_09e7fc(a0, a1, a2);
        case 0x09e858ULL: return fde_sub_09e858(a0, a1, a2);
        case 0x09e9a8ULL: return fde_sub_09e9a8(a0, a1, a2);
        case 0x09eaf8ULL: return fde_sub_09eaf8(a0, a1, a2);
        case 0x09ec7cULL: return fde_sub_09ec7c(a0, a1, a2);
        case 0x09ee00ULL: return fde_sub_09ee00(a0, a1, a2);
        case 0x09ef74ULL: return fde_sub_09ef74(a0, a1, a2);
        case 0x09f0e8ULL: return fde_sub_09f0e8(a0, a1, a2);
        case 0x09f214ULL: return fde_sub_09f214(a0, a1, a2);
        case 0x09f340ULL: return fde_sub_09f340(a0, a1, a2);
        case 0x09f478ULL: return fde_sub_09f478(a0, a1, a2);
        case 0x09f6e0ULL: return fde_sub_09f6e0(a0, a1, a2);
        case 0x09f968ULL: return fde_sub_09f968(a0, a1, a2);
        case 0x09fb98ULL: return fde_sub_09fb98(a0, a1, a2);
        case 0x09fdc8ULL: return fde_sub_09fdc8(a0, a1, a2);
        case 0x09fdd0ULL: return fde_sub_09fdd0(a0, a1, a2);
        case 0x09fdfcULL: return fde_sub_09fdfc(a0, a1, a2);
        case 0x09fe0cULL: return fde_sub_09fe0c(a0, a1, a2);
        case 0x09fe14ULL: return fde_sub_09fe14(a0, a1, a2);
        case 0x09fe1cULL: return fde_sub_09fe1c(a0, a1, a2);
        case 0x09fe24ULL: return fde_sub_09fe24(a0, a1, a2);
        case 0x09fe40ULL: return fde_sub_09fe40(a0, a1, a2);
        case 0x09fe8cULL: return fde_sub_09fe8c(a0, a1, a2);
        case 0x09fea8ULL: return fde_sub_09fea8(a0, a1, a2);
        case 0x09fec4ULL: return fde_sub_09fec4(a0, a1, a2);
        case 0x09ff4cULL: return fde_sub_09ff4c(a0, a1, a2);
        case 0x09ff80ULL: return fde_sub_09ff80(a0, a1, a2);
        case 0x09ffd4ULL: return fde_sub_09ffd4(a0, a1, a2);
        case 0x09ffe0ULL: return fde_sub_09ffe0(a0, a1, a2);
        case 0x0a0038ULL: return fde_sub_0a0038(a0, a1, a2);
        case 0x0a005cULL: return fde_sub_0a005c(a0, a1, a2);
        case 0x0a00b8ULL: return fde_sub_0a00b8(a0, a1, a2);
        case 0x0a00c0ULL: return fde_sub_0a00c0(a0, a1, a2);
        case 0x0a00c8ULL: return fde_sub_0a00c8(a0, a1, a2);
        default: return 0ULL;
    }
}

} // namespace applovin
