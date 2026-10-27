// ============================================================================
// File: applovin_fde_shard_2.cpp
// Target 110 / 169: libapplovin-native-crash-reporter.so (860,200 bytes)
// EN: Clean-room C++17 AArch64 FDE Shard 2/5 covering FDEs [352..703]
//     (PC range 0x071398 .. 0x0900dc).
// VI: Phân mảnh FDE AArch64 C++17 2/5 bao phủ FDE [352..703]
//     (Dải địa chỉ PC 0x071398 .. 0x0900dc).
// ============================================================================
#include "applovin_crash_reporter.h"

namespace applovin {

// FDE #0352 | PC: 0x071398..0x0713a0 (8 B) | Symbol: _ZNSt6__ndk18ios_base7failureD1Ev
// EN: AArch64 prologue [bti c; b #0xc8ba0] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8ba0]
uint64_t fde_sub_071398(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14015E01ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071398ULL;
}

// FDE #0353 | PC: 0x0713a0..0x0713cc (44 B) | Symbol: _ZNSt6__ndk18ios_base7failureD0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0713a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0713A0ULL;
}

// FDE #0354 | PC: 0x0713cc..0x071460 (148 B) | Symbol: _ZNSt6__ndk18ios_base5imbueERKNS_6localeE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0713cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0713CCULL;
}

// FDE #0355 | PC: 0x071460..0x071480 (32 B) | Symbol: _ZNSt6__ndk18ios_base6xallocEv
// EN: AArch64 prologue [bti c; adrp x8, #0xd4000; ldr x8, [x8, #0x638]; ldaxr w0, [x8]] | VI: Khởi đầu hàm AArch64 [bti c; adrp x8, #0xd4000; ldr x8, [x8, #0x638]; ldaxr w0, [x8]]
uint64_t fde_sub_071460(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000308ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071460ULL;
}

// FDE #0356 | PC: 0x071480..0x071588 (264 B) | Symbol: _ZNSt6__ndk18ios_base5iwordEi
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_071480(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0108ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071480ULL;
}

// FDE #0357 | PC: 0x071588..0x071690 (264 B) | Symbol: _ZNSt6__ndk18ios_base5pwordEi
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_071588(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0108ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071588ULL;
}

// FDE #0358 | PC: 0x071690..0x071770 (224 B) | Symbol: _ZNSt6__ndk18ios_base17register_callbackEPFvNS0_5eventERS0_iEi
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_071690(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071690ULL;
}

// FDE #0359 | PC: 0x071770..0x07179c (44 B) | Symbol: _ZNSt6__ndk18ios_baseD0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_071770(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071770ULL;
}

// FDE #0360 | PC: 0x07179c..0x0717e0 (68 B) | Symbol: _ZNSt6__ndk18ios_base5clearEj
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0, #0x28]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0, #0x28]]
uint64_t fde_sub_07179c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07179CULL;
}

// FDE #0361 | PC: 0x0717e0..0x0718bc (220 B) | Symbol: sub_0717e0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0717e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0717E0ULL;
}

// FDE #0362 | PC: 0x0718bc..0x071908 (76 B) | Symbol: _ZNSt6__ndk18ios_base4initEPv
// EN: AArch64 prologue [bti c; adrp x8, #0x49000; ldr q0, [x8, #0xdf0]; cmp x1, #0] | VI: Khởi đầu hàm AArch64 [bti c; adrp x8, #0x49000; ldr q0, [x8, #0xdf0]; cmp x1, #0]
uint64_t fde_sub_0718bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90FFFEC8ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0718BCULL;
}

// FDE #0363 | PC: 0x071908..0x0719b0 (168 B) | Symbol: _ZNSt6__ndk18ios_base4moveERS0_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_071908(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071908ULL;
}

// FDE #0364 | PC: 0x0719b0..0x071b34 (388 B) | Symbol: _ZNSt6__ndk18ios_base4swapERS0_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]]
uint64_t fde_sub_0719b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0184ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0719B0ULL;
}

// FDE #0365 | PC: 0x071b34..0x071b50 (28 B) | Symbol: _ZNSt6__ndk18ios_base15sync_with_stdioEb
// EN: AArch64 prologue [bti c; adrp x9, #0xd9000; ldrb w8, [x9, #0x658]; and w10, w0, #1] | VI: Khởi đầu hàm AArch64 [bti c; adrp x9, #0xd9000; ldrb w8, [x9, #0x658]; and w10, w0, #1]
uint64_t fde_sub_071b34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000349ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071B34ULL;
}

// FDE #0366 | PC: 0x071b50..0x071b7c (44 B) | Symbol: sub_071b50
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_071b50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071B50ULL;
}

// FDE #0367 | PC: 0x071b7c..0x071b84 (8 B) | Symbol: _ZNSt6__ndk17collateIcED1Ev
// EN: AArch64 prologue [bti c; b #0xc8bd0] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8bd0]
uint64_t fde_sub_071b7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14015C14ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071B7CULL;
}

// FDE #0368 | PC: 0x071b84..0x071bb0 (44 B) | Symbol: _ZNSt6__ndk17collateIcED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_071b84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071B84ULL;
}

// FDE #0369 | PC: 0x071bb0..0x071c08 (88 B) | Symbol: _ZNKSt6__ndk17collateIcE10do_compareEPKcS3_S3_S3_
// EN: AArch64 prologue [bti c; cmp x3, x4; b.eq #0x71bec; cmp x2, x1] | VI: Khởi đầu hàm AArch64 [bti c; cmp x3, x4; b.eq #0x71bec; cmp x2, x1]
uint64_t fde_sub_071bb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB04007FULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071BB0ULL;
}

// FDE #0370 | PC: 0x071c08..0x071cb4 (172 B) | Symbol: _ZNKSt6__ndk17collateIcE12do_transformEPKcS3_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_071c08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071C08ULL;
}

// FDE #0371 | PC: 0x071cb4..0x071cec (56 B) | Symbol: _ZNKSt6__ndk17collateIcE7do_hashEPKcS3_
// EN: AArch64 prologue [bti c; cmp x1, x2; b.eq #0x71ce4; mov x0, xzr] | VI: Khởi đầu hàm AArch64 [bti c; cmp x1, x2; b.eq #0x71ce4; mov x0, xzr]
uint64_t fde_sub_071cb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB02003FULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071CB4ULL;
}

// FDE #0372 | PC: 0x071cec..0x071cf4 (8 B) | Symbol: _ZNSt6__ndk17collateIwED2Ev
// EN: AArch64 prologue [bti c; b #0xc8bd0] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8bd0]
uint64_t fde_sub_071cec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14015BB8ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071CECULL;
}

// FDE #0373 | PC: 0x071cf4..0x071d20 (44 B) | Symbol: _ZNSt6__ndk17collateIwED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_071cf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071CF4ULL;
}

// FDE #0374 | PC: 0x071d20..0x071d78 (88 B) | Symbol: _ZNKSt6__ndk17collateIwE10do_compareEPKwS3_S3_S3_
// EN: AArch64 prologue [bti c; cmp x3, x4; b.eq #0x71d5c; cmp x2, x1] | VI: Khởi đầu hàm AArch64 [bti c; cmp x3, x4; b.eq #0x71d5c; cmp x2, x1]
uint64_t fde_sub_071d20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB04007FULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071D20ULL;
}

// FDE #0375 | PC: 0x071d78..0x071e34 (188 B) | Symbol: _ZNKSt6__ndk17collateIwE12do_transformEPKwS3_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_071d78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071D78ULL;
}

// FDE #0376 | PC: 0x071e34..0x071e6c (56 B) | Symbol: _ZNKSt6__ndk17collateIwE7do_hashEPKwS3_
// EN: AArch64 prologue [bti c; cmp x1, x2; b.eq #0x71e64; mov x0, xzr] | VI: Khởi đầu hàm AArch64 [bti c; cmp x1, x2; b.eq #0x71e64; mov x0, xzr]
uint64_t fde_sub_071e34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB02003FULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071E34ULL;
}

// FDE #0377 | PC: 0x071e6c..0x07212c (704 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_getES4_S4_RNS_8ios_baseERjRb
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xb0; stp x29, x30, [sp, #0x60]; stp x26, x25, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xb0; stp x29, x30, [sp, #0x60]; stp x26, x25, [sp, #0x70]]
uint64_t fde_sub_071e6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD102C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x02C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071E6CULL;
}

// FDE #0378 | PC: 0x07212c..0x0725b0 (1156 B) | Symbol: sub_07212c
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x100; stp x29, x30, [sp, #0xa0]; stp x28, x27, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x100; stp x29, x30, [sp, #0xa0]; stp x28, x27, [sp, #0xb0]]
uint64_t fde_sub_07212c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10403FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0484ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07212CULL;
}

// FDE #0379 | PC: 0x0725b0..0x0725b8 (8 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_getES4_S4_RNS_8ios_baseERjRl
// EN: AArch64 prologue [bti c; b #0xc8c00] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8c00]
uint64_t fde_sub_0725b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14015993ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0725B0ULL;
}

// FDE #0380 | PC: 0x0725b8..0x072960 (936 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE15__do_get_signedIlEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x1a0; stp x29, x30, [sp, #0x140]; stp x28, x27, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x1a0; stp x29, x30, [sp, #0x140]; stp x28, x27, [sp, #0x150]]
uint64_t fde_sub_0725b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10683FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x03A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0725B8ULL;
}

// FDE #0381 | PC: 0x072960..0x072968 (8 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_getES4_S4_RNS_8ios_baseERjRx
// EN: AArch64 prologue [bti c; b #0xc8c40] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8c40]
uint64_t fde_sub_072960(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140158B7ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x072960ULL;
}

// FDE #0382 | PC: 0x072968..0x072d10 (936 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE15__do_get_signedIxEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x1a0; stp x29, x30, [sp, #0x140]; stp x28, x27, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x1a0; stp x29, x30, [sp, #0x140]; stp x28, x27, [sp, #0x150]]
uint64_t fde_sub_072968(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10683FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x03A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x072968ULL;
}

// FDE #0383 | PC: 0x072d10..0x072d18 (8 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_getES4_S4_RNS_8ios_baseERjRt
// EN: AArch64 prologue [bti c; b #0xc8c50] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8c50]
uint64_t fde_sub_072d10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140157CFULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x072D10ULL;
}

// FDE #0384 | PC: 0x072d18..0x0730c0 (936 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE17__do_get_unsignedItEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x1a0; stp x29, x30, [sp, #0x140]; stp x28, x27, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x1a0; stp x29, x30, [sp, #0x140]; stp x28, x27, [sp, #0x150]]
uint64_t fde_sub_072d18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10683FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x03A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x072D18ULL;
}

// FDE #0385 | PC: 0x0730c0..0x0730c8 (8 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_getES4_S4_RNS_8ios_baseERjS8_
// EN: AArch64 prologue [bti c; b #0xc8c60] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8c60]
uint64_t fde_sub_0730c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140156E7ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0730C0ULL;
}

// FDE #0386 | PC: 0x0730c8..0x073470 (936 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE17__do_get_unsignedIjEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x1a0; stp x29, x30, [sp, #0x140]; stp x28, x27, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x1a0; stp x29, x30, [sp, #0x140]; stp x28, x27, [sp, #0x150]]
uint64_t fde_sub_0730c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10683FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x03A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0730C8ULL;
}

// FDE #0387 | PC: 0x073470..0x073478 (8 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_getES4_S4_RNS_8ios_baseERjRm
// EN: AArch64 prologue [bti c; b #0xc8c70] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8c70]
uint64_t fde_sub_073470(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140155FFULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073470ULL;
}

// FDE #0388 | PC: 0x073478..0x073820 (936 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE17__do_get_unsignedImEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x1a0; stp x29, x30, [sp, #0x140]; stp x28, x27, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x1a0; stp x29, x30, [sp, #0x140]; stp x28, x27, [sp, #0x150]]
uint64_t fde_sub_073478(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10683FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x03A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073478ULL;
}

// FDE #0389 | PC: 0x073820..0x073828 (8 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_getES4_S4_RNS_8ios_baseERjRy
// EN: AArch64 prologue [bti c; b #0xc8c80] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8c80]
uint64_t fde_sub_073820(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14015517ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073820ULL;
}

// FDE #0390 | PC: 0x073828..0x073bd0 (936 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE17__do_get_unsignedIyEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x1a0; stp x29, x30, [sp, #0x140]; stp x28, x27, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x1a0; stp x29, x30, [sp, #0x140]; stp x28, x27, [sp, #0x150]]
uint64_t fde_sub_073828(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10683FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x03A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073828ULL;
}

// FDE #0391 | PC: 0x073bd0..0x073bd8 (8 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_getES4_S4_RNS_8ios_baseERjRf
// EN: AArch64 prologue [bti c; b #0xc8c90] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8c90]
uint64_t fde_sub_073bd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1401542FULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073BD0ULL;
}

// FDE #0392 | PC: 0x073bd8..0x073f64 (908 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE23__do_get_floating_pointIfEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x1c0; stp x29, x30, [sp, #0x160]; stp x28, x27, [sp, #0x170]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x1c0; stp x29, x30, [sp, #0x160]; stp x28, x27, [sp, #0x170]]
uint64_t fde_sub_073bd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10703FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x038CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073BD8ULL;
}

// FDE #0393 | PC: 0x073f64..0x073f6c (8 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_getES4_S4_RNS_8ios_baseERjRd
// EN: AArch64 prologue [bti c; b #0xc8cc0] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8cc0]
uint64_t fde_sub_073f64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14015356ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073F64ULL;
}

// FDE #0394 | PC: 0x073f6c..0x0742f8 (908 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE23__do_get_floating_pointIdEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x1c0; stp x29, x30, [sp, #0x160]; stp x28, x27, [sp, #0x170]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x1c0; stp x29, x30, [sp, #0x160]; stp x28, x27, [sp, #0x170]]
uint64_t fde_sub_073f6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10703FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x038CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073F6CULL;
}

// FDE #0395 | PC: 0x0742f8..0x074300 (8 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_getES4_S4_RNS_8ios_baseERjRe
// EN: AArch64 prologue [bti c; b #0xc8cd0] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8cd0]
uint64_t fde_sub_0742f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14015275ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0742F8ULL;
}

// FDE #0396 | PC: 0x074300..0x07468c (908 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE23__do_get_floating_pointIeEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x1c0; stp x29, x30, [sp, #0x160]; stp x28, x27, [sp, #0x170]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x1c0; stp x29, x30, [sp, #0x160]; stp x28, x27, [sp, #0x170]]
uint64_t fde_sub_074300(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10703FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x038CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074300ULL;
}

// FDE #0397 | PC: 0x07468c..0x074b0c (1152 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_getES4_S4_RNS_8ios_baseERjRPv
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x190; stp x29, x30, [sp, #0x130]; stp x28, x27, [sp, #0x140]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x190; stp x29, x30, [sp, #0x130]; stp x28, x27, [sp, #0x140]]
uint64_t fde_sub_07468c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10643FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0480ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07468CULL;
}

// FDE #0398 | PC: 0x074b0c..0x074e70 (868 B) | Symbol: _ZNSt6__ndk19__num_getIcE17__stage2_int_loopEciPcRS2_RjcRKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPjRSD_S2_
// EN: AArch64 prologue [bti c; ldr x8, [x3]; ldr x9, [sp, #8]; cmp x8, x2] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x3]; ldr x9, [sp, #8]; cmp x8, x2]
uint64_t fde_sub_074b0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400068ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0364ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074B0CULL;
}

// FDE #0399 | PC: 0x074e70..0x074f50 (224 B) | Symbol: _ZNSt6__ndk117__libcpp_sscanf_lEPKcP10__locale_tS1_z
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x140; stp x29, x30, [sp, #0x100]; stp x28, x23, [sp, #0x110]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x140; stp x29, x30, [sp, #0x100]; stp x28, x23, [sp, #0x110]]
uint64_t fde_sub_074e70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10503FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074E70ULL;
}

// FDE #0400 | PC: 0x074f50..0x074fd8 (136 B) | Symbol: _ZNSt6__ndk16__clocEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_074f50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074F50ULL;
}

// FDE #0401 | PC: 0x074fd8..0x075298 (704 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_getES4_S4_RNS_8ios_baseERjRb
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xb0; stp x29, x30, [sp, #0x60]; stp x26, x25, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xb0; stp x29, x30, [sp, #0x60]; stp x26, x25, [sp, #0x70]]
uint64_t fde_sub_074fd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD102C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x02C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074FD8ULL;
}

// FDE #0402 | PC: 0x075298..0x075750 (1208 B) | Symbol: sub_075298
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x100; stp x29, x30, [sp, #0xa0]; stp x28, x27, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x100; stp x29, x30, [sp, #0xa0]; stp x28, x27, [sp, #0xb0]]
uint64_t fde_sub_075298(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10403FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x04B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075298ULL;
}

// FDE #0403 | PC: 0x075750..0x075758 (8 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_getES4_S4_RNS_8ios_baseERjRl
// EN: AArch64 prologue [bti c; b #0xc8d30] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8d30]
uint64_t fde_sub_075750(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14014D77ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075750ULL;
}

// FDE #0404 | PC: 0x075758..0x075b34 (988 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE15__do_get_signedIlEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x1f0; stp x29, x30, [sp, #0x190]; stp x28, x27, [sp, #0x1a0]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x1f0; stp x29, x30, [sp, #0x190]; stp x28, x27, [sp, #0x1a0]]
uint64_t fde_sub_075758(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD107C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x03DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075758ULL;
}

// FDE #0405 | PC: 0x075b34..0x075b3c (8 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_getES4_S4_RNS_8ios_baseERjRx
// EN: AArch64 prologue [bti c; b #0xc8d60] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8d60]
uint64_t fde_sub_075b34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14014C8AULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075B34ULL;
}

// FDE #0406 | PC: 0x075b3c..0x075f18 (988 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE15__do_get_signedIxEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x1f0; stp x29, x30, [sp, #0x190]; stp x28, x27, [sp, #0x1a0]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x1f0; stp x29, x30, [sp, #0x190]; stp x28, x27, [sp, #0x1a0]]
uint64_t fde_sub_075b3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD107C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x03DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075B3CULL;
}

// FDE #0407 | PC: 0x075f18..0x075f20 (8 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_getES4_S4_RNS_8ios_baseERjRt
// EN: AArch64 prologue [bti c; b #0xc8d70] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8d70]
uint64_t fde_sub_075f18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14014B95ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075F18ULL;
}

// FDE #0408 | PC: 0x075f20..0x0762fc (988 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE17__do_get_unsignedItEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x1f0; stp x29, x30, [sp, #0x190]; stp x28, x27, [sp, #0x1a0]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x1f0; stp x29, x30, [sp, #0x190]; stp x28, x27, [sp, #0x1a0]]
uint64_t fde_sub_075f20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD107C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x03DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075F20ULL;
}

// FDE #0409 | PC: 0x0762fc..0x076304 (8 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_getES4_S4_RNS_8ios_baseERjS8_
// EN: AArch64 prologue [bti c; b #0xc8d80] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8d80]
uint64_t fde_sub_0762fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14014AA0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0762FCULL;
}

// FDE #0410 | PC: 0x076304..0x0766e0 (988 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE17__do_get_unsignedIjEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x1f0; stp x29, x30, [sp, #0x190]; stp x28, x27, [sp, #0x1a0]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x1f0; stp x29, x30, [sp, #0x190]; stp x28, x27, [sp, #0x1a0]]
uint64_t fde_sub_076304(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD107C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x03DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x076304ULL;
}

// FDE #0411 | PC: 0x0766e0..0x0766e8 (8 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_getES4_S4_RNS_8ios_baseERjRm
// EN: AArch64 prologue [bti c; b #0xc8d90] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8d90]
uint64_t fde_sub_0766e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140149ABULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0766E0ULL;
}

// FDE #0412 | PC: 0x0766e8..0x076ac4 (988 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE17__do_get_unsignedImEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x1f0; stp x29, x30, [sp, #0x190]; stp x28, x27, [sp, #0x1a0]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x1f0; stp x29, x30, [sp, #0x190]; stp x28, x27, [sp, #0x1a0]]
uint64_t fde_sub_0766e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD107C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x03DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0766E8ULL;
}

// FDE #0413 | PC: 0x076ac4..0x076acc (8 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_getES4_S4_RNS_8ios_baseERjRy
// EN: AArch64 prologue [bti c; b #0xc8da0] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8da0]
uint64_t fde_sub_076ac4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140148B6ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x076AC4ULL;
}

// FDE #0414 | PC: 0x076acc..0x076ea8 (988 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE17__do_get_unsignedIyEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x1f0; stp x29, x30, [sp, #0x190]; stp x28, x27, [sp, #0x1a0]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x1f0; stp x29, x30, [sp, #0x190]; stp x28, x27, [sp, #0x1a0]]
uint64_t fde_sub_076acc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD107C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x03DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x076ACCULL;
}

// FDE #0415 | PC: 0x076ea8..0x076eb0 (8 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_getES4_S4_RNS_8ios_baseERjRf
// EN: AArch64 prologue [bti c; b #0xc8db0] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8db0]
uint64_t fde_sub_076ea8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140147C1ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x076EA8ULL;
}

// FDE #0416 | PC: 0x076eb0..0x077274 (964 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE23__do_get_floating_pointIfEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_076eb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x03C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x076EB0ULL;
}

// FDE #0417 | PC: 0x077274..0x07727c (8 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_getES4_S4_RNS_8ios_baseERjRd
// EN: AArch64 prologue [bti c; b #0xc8de0] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8de0]
uint64_t fde_sub_077274(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140146DAULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077274ULL;
}

// FDE #0418 | PC: 0x07727c..0x077640 (964 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE23__do_get_floating_pointIdEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_07727c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x03C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07727CULL;
}

// FDE #0419 | PC: 0x077640..0x077648 (8 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_getES4_S4_RNS_8ios_baseERjRe
// EN: AArch64 prologue [bti c; b #0xc8df0] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8df0]
uint64_t fde_sub_077640(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140145EBULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077640ULL;
}

// FDE #0420 | PC: 0x077648..0x077a0c (964 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE23__do_get_floating_pointIeEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_077648(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x03C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077648ULL;
}

// FDE #0421 | PC: 0x077a0c..0x077ec4 (1208 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_getES4_S4_RNS_8ios_baseERjRPv
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x1e0; stp x29, x30, [sp, #0x180]; stp x28, x27, [sp, #0x190]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x1e0; stp x29, x30, [sp, #0x180]; stp x28, x27, [sp, #0x190]]
uint64_t fde_sub_077a0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10783FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x04B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077A0CULL;
}

// FDE #0422 | PC: 0x077ec4..0x078228 (868 B) | Symbol: _ZNSt6__ndk19__num_getIwE17__stage2_int_loopEwiPcRS2_RjwRKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPjRSD_Pw
// EN: AArch64 prologue [bti c; ldr x8, [x3]; ldr x9, [sp, #8]; cmp x8, x2] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x3]; ldr x9, [sp, #8]; cmp x8, x2]
uint64_t fde_sub_077ec4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400068ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0364ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077EC4ULL;
}

// FDE #0423 | PC: 0x078228..0x0783f0 (456 B) | Symbol: _ZNSt6__ndk19__num_getIcE19__stage2_float_prepERNS_8ios_baseEPcRcS5_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x40]; stp x26, x25, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x40]; stp x26, x25, [sp, #0x50]]
uint64_t fde_sub_078228(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10243FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078228ULL;
}

// FDE #0424 | PC: 0x0783f0..0x07885c (1132 B) | Symbol: _ZNSt6__ndk19__num_getIcE19__stage2_float_loopEcRbRcPcRS4_ccRKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPjRSE_RjS4_
// EN: AArch64 prologue [bti c; ldp x9, x8, [sp, #8]; ldr x10, [sp]; and w11, w0, #0xff] | VI: Khởi đầu hàm AArch64 [bti c; ldp x9, x8, [sp, #8]; ldr x10, [sp]; and w11, w0, #0xff]
uint64_t fde_sub_0783f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA940A3E9ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x046CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0783F0ULL;
}

// FDE #0425 | PC: 0x07885c..0x078a0c (432 B) | Symbol: _ZNSt6__ndk19__num_getIcE17__stage2_int_prepERNS_8ios_baseEPcRc
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x40]; str x25, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x40]; str x25, [sp, #0x50]]
uint64_t fde_sub_07885c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10243FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07885CULL;
}

// FDE #0426 | PC: 0x078a0c..0x078bd4 (456 B) | Symbol: _ZNSt6__ndk19__num_getIwE19__stage2_float_prepERNS_8ios_baseEPwRwS5_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x40]; stp x26, x25, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x40]; stp x26, x25, [sp, #0x50]]
uint64_t fde_sub_078a0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10243FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078A0CULL;
}

// FDE #0427 | PC: 0x078bd4..0x07903c (1128 B) | Symbol: _ZNSt6__ndk19__num_getIwE19__stage2_float_loopEwRbRcPcRS4_wwRKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPjRSE_RjPw
// EN: AArch64 prologue [bti c; ldp x9, x8, [sp, #8]; ldr x10, [sp]; cmp w0, w5] | VI: Khởi đầu hàm AArch64 [bti c; ldp x9, x8, [sp, #8]; ldr x10, [sp]; cmp w0, w5]
uint64_t fde_sub_078bd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA940A3E9ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0468ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078BD4ULL;
}

// FDE #0428 | PC: 0x07903c..0x0791ec (432 B) | Symbol: _ZNSt6__ndk19__num_getIwE17__stage2_int_prepERNS_8ios_baseEPwRw
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x40]; str x25, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x40]; str x25, [sp, #0x50]]
uint64_t fde_sub_07903c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10243FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07903CULL;
}

// FDE #0429 | PC: 0x0791ec..0x0793dc (496 B) | Symbol: _ZNKSt6__ndk17num_putIcNS_19ostreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_putES4_RNS_8ios_baseEcb
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; str x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; str x23, [sp, #0x50]]
uint64_t fde_sub_0791ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0791ECULL;
}

// FDE #0430 | PC: 0x0793dc..0x079650 (628 B) | Symbol: _ZNKSt6__ndk17num_putIcNS_19ostreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_putES4_RNS_8ios_baseEcl
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_0793dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0274ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0793DCULL;
}

// FDE #0431 | PC: 0x079650..0x0796e8 (152 B) | Symbol: _ZNSt6__ndk114__num_put_base12__format_intEPcPKcbj
// EN: AArch64 prologue [bti c; tbnz w3, #0xb, #0x79668; tbnz w3, #9, #0x79674; ldrb w8, [x1]] | VI: Khởi đầu hàm AArch64 [bti c; tbnz w3, #0xb, #0x79668; tbnz w3, #9, #0x79674; ldrb w8, [x1]]
uint64_t fde_sub_079650(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x375800A3ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079650ULL;
}

// FDE #0432 | PC: 0x0796e8..0x0797ec (260 B) | Symbol: _ZNSt6__ndk119__libcpp_snprintf_lEPcmP10__locale_tPKcz
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x130; stp x29, x30, [sp, #0xf0]; stp x28, x23, [sp, #0x100]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x130; stp x29, x30, [sp, #0xf0]; stp x28, x23, [sp, #0x100]]
uint64_t fde_sub_0796e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD104C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0796E8ULL;
}

// FDE #0433 | PC: 0x0797ec..0x07985c (112 B) | Symbol: _ZNSt6__ndk114__num_put_base18__identify_paddingEPcS1_RKNS_8ios_baseE
// EN: AArch64 prologue [bti c; ldr w8, [x2, #8]; mov w9, #0xb0; and w8, w8, w9] | VI: Khởi đầu hàm AArch64 [bti c; ldr w8, [x2, #8]; mov w9, #0xb0; and w8, w8, w9]
uint64_t fde_sub_0797ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9400848ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0797ECULL;
}

// FDE #0434 | PC: 0x07985c..0x079c64 (1032 B) | Symbol: _ZNSt6__ndk19__num_putIcE21__widen_and_group_intEPcS2_S2_S2_RS2_S3_RKNS_6localeE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xb0; stp x29, x30, [sp, #0x50]; stp x28, x27, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xb0; stp x29, x30, [sp, #0x50]; stp x28, x27, [sp, #0x60]]
uint64_t fde_sub_07985c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD102C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0408ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07985CULL;
}

// FDE #0435 | PC: 0x079c64..0x079ed4 (624 B) | Symbol: _ZNKSt6__ndk17num_putIcNS_19ostreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_putES4_RNS_8ios_baseEcx
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_079c64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0270ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079C64ULL;
}

// FDE #0436 | PC: 0x079ed4..0x07a164 (656 B) | Symbol: _ZNKSt6__ndk17num_putIcNS_19ostreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_putES4_RNS_8ios_baseEcm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_079ed4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0290ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079ED4ULL;
}

// FDE #0437 | PC: 0x07a164..0x07a3f0 (652 B) | Symbol: _ZNKSt6__ndk17num_putIcNS_19ostreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_putES4_RNS_8ios_baseEcy
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_07a164(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x028CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A164ULL;
}

// FDE #0438 | PC: 0x07a3f0..0x07a850 (1120 B) | Symbol: _ZNKSt6__ndk17num_putIcNS_19ostreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_putES4_RNS_8ios_baseEcd
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x100; str d8, [sp, #0x90]; stp x29, x30, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x100; str d8, [sp, #0x90]; stp x29, x30, [sp, #0xa0]]
uint64_t fde_sub_07a3f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10403FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0460ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A3F0ULL;
}

// FDE #0439 | PC: 0x07a850..0x07a908 (184 B) | Symbol: _ZNSt6__ndk114__num_put_base14__format_floatEPcPKcj
// EN: AArch64 prologue [bti c; tbz w2, #0xb, #0x7a860; mov w8, #0x2b; strb w8, [x0], #1] | VI: Khởi đầu hàm AArch64 [bti c; tbz w2, #0xb, #0x7a860; mov w8, #0x2b; strb w8, [x0], #1]
uint64_t fde_sub_07a850(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x36580062ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A850ULL;
}

// FDE #0440 | PC: 0x07a908..0x07aa04 (252 B) | Symbol: _ZNSt6__ndk119__libcpp_asprintf_lEPPcP10__locale_tPKcz
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x140; stp x29, x30, [sp, #0x100]; stp x28, x23, [sp, #0x110]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x140; stp x29, x30, [sp, #0x100]; stp x28, x23, [sp, #0x110]]
uint64_t fde_sub_07a908(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10503FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A908ULL;
}

// FDE #0441 | PC: 0x07aa04..0x07afe8 (1508 B) | Symbol: _ZNSt6__ndk19__num_putIcE23__widen_and_group_floatEPcS2_S2_S2_RS2_S3_RKNS_6localeE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xc0; stp x29, x30, [sp, #0x60]; stp x28, x27, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xc0; stp x29, x30, [sp, #0x60]; stp x28, x27, [sp, #0x70]]
uint64_t fde_sub_07aa04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10303FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x05E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07AA04ULL;
}

// FDE #0442 | PC: 0x07afe8..0x07b450 (1128 B) | Symbol: _ZNKSt6__ndk17num_putIcNS_19ostreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_putES4_RNS_8ios_baseEce
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x100; stp x29, x30, [sp, #0xa0]; stp x28, x27, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x100; stp x29, x30, [sp, #0xa0]; stp x28, x27, [sp, #0xb0]]
uint64_t fde_sub_07afe8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10403FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0468ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07AFE8ULL;
}

// FDE #0443 | PC: 0x07b450..0x07b6b4 (612 B) | Symbol: _ZNKSt6__ndk17num_putIcNS_19ostreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_putES4_RNS_8ios_baseEcPKv
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xe0; stp x29, x30, [sp, #0x80]; stp x28, x27, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xe0; stp x29, x30, [sp, #0x80]; stp x28, x27, [sp, #0x90]]
uint64_t fde_sub_07b450(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10383FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0264ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B450ULL;
}

// FDE #0444 | PC: 0x07b6b4..0x07b8a8 (500 B) | Symbol: _ZNKSt6__ndk17num_putIwNS_19ostreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_putES4_RNS_8ios_baseEwb
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; str x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; str x23, [sp, #0x50]]
uint64_t fde_sub_07b6b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B6B4ULL;
}

// FDE #0445 | PC: 0x07b8a8..0x07bb2c (644 B) | Symbol: _ZNKSt6__ndk17num_putIwNS_19ostreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_putES4_RNS_8ios_baseEwl
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_07b8a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0284ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B8A8ULL;
}

// FDE #0446 | PC: 0x07bb2c..0x07bf30 (1028 B) | Symbol: _ZNSt6__ndk19__num_putIwE21__widen_and_group_intEPcS2_S2_PwRS3_S4_RKNS_6localeE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xb0; stp x29, x30, [sp, #0x50]; stp x28, x27, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xb0; stp x29, x30, [sp, #0x50]; stp x28, x27, [sp, #0x60]]
uint64_t fde_sub_07bb2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD102C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0404ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07BB2CULL;
}

// FDE #0447 | PC: 0x07bf30..0x07c104 (468 B) | Symbol: sub_07bf30
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x20]; str x27, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x20]; str x27, [sp, #0x30]]
uint64_t fde_sub_07bf30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07BF30ULL;
}

// FDE #0448 | PC: 0x07c104..0x07c384 (640 B) | Symbol: _ZNKSt6__ndk17num_putIwNS_19ostreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_putES4_RNS_8ios_baseEwx
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_07c104(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0280ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C104ULL;
}

// FDE #0449 | PC: 0x07c384..0x07c618 (660 B) | Symbol: _ZNKSt6__ndk17num_putIwNS_19ostreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_putES4_RNS_8ios_baseEwm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_07c384(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0294ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C384ULL;
}

// FDE #0450 | PC: 0x07c618..0x07c8a8 (656 B) | Symbol: _ZNKSt6__ndk17num_putIwNS_19ostreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_putES4_RNS_8ios_baseEwy
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_07c618(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0290ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C618ULL;
}

// FDE #0451 | PC: 0x07c8a8..0x07cd08 (1120 B) | Symbol: _ZNKSt6__ndk17num_putIwNS_19ostreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_putES4_RNS_8ios_baseEwd
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x1b0; str d8, [sp, #0x140]; stp x29, x30, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x1b0; str d8, [sp, #0x140]; stp x29, x30, [sp, #0x150]]
uint64_t fde_sub_07c8a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD106C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0460ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C8A8ULL;
}

// FDE #0452 | PC: 0x07cd08..0x07d2f4 (1516 B) | Symbol: _ZNSt6__ndk19__num_putIwE23__widen_and_group_floatEPcS2_S2_PwRS3_S4_RKNS_6localeE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xc0; stp x29, x30, [sp, #0x60]; stp x28, x27, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xc0; stp x29, x30, [sp, #0x60]; stp x28, x27, [sp, #0x70]]
uint64_t fde_sub_07cd08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10303FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x05ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07CD08ULL;
}

// FDE #0453 | PC: 0x07d2f4..0x07d75c (1128 B) | Symbol: _ZNKSt6__ndk17num_putIwNS_19ostreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_putES4_RNS_8ios_baseEwe
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x1b0; stp x29, x30, [sp, #0x150]; stp x28, x27, [sp, #0x160]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x1b0; stp x29, x30, [sp, #0x150]; stp x28, x27, [sp, #0x160]]
uint64_t fde_sub_07d2f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD106C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0468ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07D2F4ULL;
}

// FDE #0454 | PC: 0x07d75c..0x07d9c0 (612 B) | Symbol: _ZNKSt6__ndk17num_putIwNS_19ostreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_putES4_RNS_8ios_baseEwPKv
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x150; stp x29, x30, [sp, #0xf0]; stp x28, x27, [sp, #0x100]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x150; stp x29, x30, [sp, #0xf0]; stp x28, x27, [sp, #0x100]]
uint64_t fde_sub_07d75c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10543FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0264ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07D75CULL;
}

// FDE #0455 | PC: 0x07d9c0..0x07de7c (1212 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE3getES4_S4_RNS_8ios_baseERjP2tmPKcSC_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xb0; stp x29, x30, [sp, #0x50]; stp x28, x27, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xb0; stp x29, x30, [sp, #0x50]; stp x28, x27, [sp, #0x60]]
uint64_t fde_sub_07d9c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD102C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x04BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07D9C0ULL;
}

// FDE #0456 | PC: 0x07de7c..0x07de88 (12 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE13do_date_orderEv
// EN: AArch64 prologue [bti c; mov w0, #2; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #2; ret]
uint64_t fde_sub_07de7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800040ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07DE7CULL;
}

// FDE #0457 | PC: 0x07de88..0x07def4 (108 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE11do_get_timeES4_S4_RNS_8ios_baseERjP2tm
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x30; stp x29, x30, [sp, #0x10]; str x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x30; stp x29, x30, [sp, #0x10]; str x19, [sp, #0x20]]
uint64_t fde_sub_07de88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD100C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07DE88ULL;
}

// FDE #0458 | PC: 0x07def4..0x07df7c (136 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE11do_get_dateES4_S4_RNS_8ios_baseERjP2tm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_07def4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07DEF4ULL;
}

// FDE #0459 | PC: 0x07df7c..0x07e10c (400 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE14do_get_weekdayES4_S4_RNS_8ios_baseERjP2tm
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x40]; str x25, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x40]; str x25, [sp, #0x50]]
uint64_t fde_sub_07df7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10243FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0190ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07DF7CULL;
}

// FDE #0460 | PC: 0x07e10c..0x07e1c8 (188 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE17__get_weekdaynameERiRS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_07e10c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E10CULL;
}

// FDE #0461 | PC: 0x07e1c8..0x07e354 (396 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE16do_get_monthnameES4_S4_RNS_8ios_baseERjP2tm
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x40]; str x25, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x40]; str x25, [sp, #0x50]]
uint64_t fde_sub_07e1c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10243FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x018CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E1C8ULL;
}

// FDE #0462 | PC: 0x07e354..0x07e40c (184 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE15__get_monthnameERiRS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_07e354(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E354ULL;
}

// FDE #0463 | PC: 0x07e40c..0x07e554 (328 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE11do_get_yearES4_S4_RNS_8ios_baseERjP2tm
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; stp x24, x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; stp x24, x23, [sp, #0x50]]
uint64_t fde_sub_07e40c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0148ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E40CULL;
}

// FDE #0464 | PC: 0x07e554..0x07e5bc (104 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE10__get_yearERiRS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_07e554(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E554ULL;
}

// FDE #0465 | PC: 0x07e5bc..0x07ec64 (1704 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_getES4_S4_RNS_8ios_baseERjP2tmcc
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xa0; stp x29, x30, [sp, #0x40]; str x27, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xa0; stp x29, x30, [sp, #0x40]; str x27, [sp, #0x50]]
uint64_t fde_sub_07e5bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10283FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x06A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E5BCULL;
}

// FDE #0466 | PC: 0x07ec64..0x07ecc8 (100 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE9__get_dayERiRS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_07ec64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07EC64ULL;
}

// FDE #0467 | PC: 0x07ecc8..0x07ed28 (96 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE10__get_hourERiRS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_07ecc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07ECC8ULL;
}

// FDE #0468 | PC: 0x07ed28..0x07ed8c (100 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE13__get_12_hourERiRS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_07ed28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07ED28ULL;
}

// FDE #0469 | PC: 0x07ed8c..0x07edec (96 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE18__get_day_year_numERiRS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_07ed8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07ED8CULL;
}

// FDE #0470 | PC: 0x07edec..0x07ee50 (100 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE11__get_monthERiRS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_07edec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07EDECULL;
}

// FDE #0471 | PC: 0x07ee50..0x07eeb0 (96 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE12__get_minuteERiRS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_07ee50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07EE50ULL;
}

// FDE #0472 | PC: 0x07eeb0..0x07f058 (424 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE17__get_white_spaceERS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_07eeb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07EEB0ULL;
}

// FDE #0473 | PC: 0x07f058..0x07f148 (240 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE11__get_am_pmERiRS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_07f058(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F058ULL;
}

// FDE #0474 | PC: 0x07f148..0x07f1a8 (96 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE12__get_secondERiRS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_07f148(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F148ULL;
}

// FDE #0475 | PC: 0x07f1a8..0x07f208 (96 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE13__get_weekdayERiRS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_07f1a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F1A8ULL;
}

// FDE #0476 | PC: 0x07f208..0x07f258 (80 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE11__get_year4ERiRS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_07f208(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F208ULL;
}

// FDE #0477 | PC: 0x07f258..0x07f414 (444 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE13__get_percentERS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_07f258(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F258ULL;
}

// FDE #0478 | PC: 0x07f414..0x07f724 (784 B) | Symbol: sub_07f414
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x50]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x50]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_07f414(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0310ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F414ULL;
}

// FDE #0479 | PC: 0x07f724..0x07fc40 (1308 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE3getES4_S4_RNS_8ios_baseERjP2tmPKwSC_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xb0; stp x29, x30, [sp, #0x50]; stp x28, x27, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xb0; stp x29, x30, [sp, #0x50]; stp x28, x27, [sp, #0x60]]
uint64_t fde_sub_07f724(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD102C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x051CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F724ULL;
}

// FDE #0480 | PC: 0x07fc40..0x07fc4c (12 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE13do_date_orderEv
// EN: AArch64 prologue [bti c; mov w0, #2; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #2; ret]
uint64_t fde_sub_07fc40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800040ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FC40ULL;
}

// FDE #0481 | PC: 0x07fc4c..0x07fcb4 (104 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE11do_get_timeES4_S4_RNS_8ios_baseERjP2tm
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x30]; str x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x30]; str x19, [sp, #0x40]]
uint64_t fde_sub_07fc4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FC4CULL;
}

// FDE #0482 | PC: 0x07fcb4..0x07fd40 (140 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE11do_get_dateES4_S4_RNS_8ios_baseERjP2tm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_07fcb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FCB4ULL;
}

// FDE #0483 | PC: 0x07fd40..0x07fed0 (400 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE14do_get_weekdayES4_S4_RNS_8ios_baseERjP2tm
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x40]; str x25, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x40]; str x25, [sp, #0x50]]
uint64_t fde_sub_07fd40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10243FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0190ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FD40ULL;
}

// FDE #0484 | PC: 0x07fed0..0x07ff8c (188 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE17__get_weekdaynameERiRS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_07fed0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FED0ULL;
}

// FDE #0485 | PC: 0x07ff8c..0x080118 (396 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE16do_get_monthnameES4_S4_RNS_8ios_baseERjP2tm
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x40]; str x25, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x40]; str x25, [sp, #0x50]]
uint64_t fde_sub_07ff8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10243FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x018CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FF8CULL;
}

// FDE #0486 | PC: 0x080118..0x0801d0 (184 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE15__get_monthnameERiRS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_080118(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080118ULL;
}

// FDE #0487 | PC: 0x0801d0..0x080318 (328 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE11do_get_yearES4_S4_RNS_8ios_baseERjP2tm
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; stp x24, x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; stp x24, x23, [sp, #0x50]]
uint64_t fde_sub_0801d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0148ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0801D0ULL;
}

// FDE #0488 | PC: 0x080318..0x080380 (104 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE10__get_yearERiRS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_080318(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080318ULL;
}

// FDE #0489 | PC: 0x080380..0x080a18 (1688 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_getES4_S4_RNS_8ios_baseERjP2tmcc
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xc0; stp x29, x30, [sp, #0x60]; str x27, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xc0; stp x29, x30, [sp, #0x60]; str x27, [sp, #0x70]]
uint64_t fde_sub_080380(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10303FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0698ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080380ULL;
}

// FDE #0490 | PC: 0x080a18..0x080a7c (100 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE9__get_dayERiRS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_080a18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080A18ULL;
}

// FDE #0491 | PC: 0x080a7c..0x080adc (96 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE10__get_hourERiRS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_080a7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080A7CULL;
}

// FDE #0492 | PC: 0x080adc..0x080b40 (100 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE13__get_12_hourERiRS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_080adc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080ADCULL;
}

// FDE #0493 | PC: 0x080b40..0x080ba0 (96 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE18__get_day_year_numERiRS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_080b40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080B40ULL;
}

// FDE #0494 | PC: 0x080ba0..0x080c04 (100 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE11__get_monthERiRS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_080ba0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080BA0ULL;
}

// FDE #0495 | PC: 0x080c04..0x080c64 (96 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE12__get_minuteERiRS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_080c04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080C04ULL;
}

// FDE #0496 | PC: 0x080c64..0x080e4c (488 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE17__get_white_spaceERS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_080c64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080C64ULL;
}

// FDE #0497 | PC: 0x080e4c..0x080f3c (240 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE11__get_am_pmERiRS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_080e4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080E4CULL;
}

// FDE #0498 | PC: 0x080f3c..0x080f9c (96 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE12__get_secondERiRS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_080f3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080F3CULL;
}

// FDE #0499 | PC: 0x080f9c..0x080ffc (96 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE13__get_weekdayERiRS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_080f9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080F9CULL;
}

// FDE #0500 | PC: 0x080ffc..0x08104c (80 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE11__get_year4ERiRS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_080ffc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080FFCULL;
}

// FDE #0501 | PC: 0x08104c..0x081240 (500 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE13__get_percentERS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_08104c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08104CULL;
}

// FDE #0502 | PC: 0x081240..0x0815b0 (880 B) | Symbol: sub_081240
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x50]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x50]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_081240(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0370ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081240ULL;
}

// FDE #0503 | PC: 0x0815b0..0x081884 (724 B) | Symbol: _ZNKSt6__ndk18time_putIcNS_19ostreambuf_iteratorIcNS_11char_traitsIcEEEEE3putES4_RNS_8ios_baseEcPK2tmPKcSC_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xb0; stp x29, x30, [sp, #0x50]; stp x28, x27, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xb0; stp x29, x30, [sp, #0x50]; stp x28, x27, [sp, #0x60]]
uint64_t fde_sub_0815b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD102C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x02D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0815B0ULL;
}

// FDE #0504 | PC: 0x081884..0x081970 (236 B) | Symbol: _ZNKSt6__ndk18time_putIcNS_19ostreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_putES4_RNS_8ios_baseEcPK2tmcc
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xa0; stp x29, x30, [sp, #0x70]; stp x22, x21, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xa0; stp x29, x30, [sp, #0x70]; stp x22, x21, [sp, #0x80]]
uint64_t fde_sub_081884(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10283FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081884ULL;
}

// FDE #0505 | PC: 0x081970..0x081a0c (156 B) | Symbol: _ZNKSt6__ndk110__time_put8__do_putEPcRS1_PK2tmcc
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x40; stp x29, x30, [sp, #0x10]; str x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x40; stp x29, x30, [sp, #0x10]; str x21, [sp, #0x20]]
uint64_t fde_sub_081970(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10103FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081970ULL;
}

// FDE #0506 | PC: 0x081a0c..0x081cfc (752 B) | Symbol: _ZNKSt6__ndk18time_putIwNS_19ostreambuf_iteratorIwNS_11char_traitsIwEEEEE3putES4_RNS_8ios_baseEwPK2tmPKwSC_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xb0; stp x29, x30, [sp, #0x50]; stp x28, x27, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xb0; stp x29, x30, [sp, #0x50]; stp x28, x27, [sp, #0x60]]
uint64_t fde_sub_081a0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD102C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x02F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081A0CULL;
}

// FDE #0507 | PC: 0x081cfc..0x081de4 (232 B) | Symbol: _ZNKSt6__ndk18time_putIwNS_19ostreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_putES4_RNS_8ios_baseEwPK2tmcc
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x1e0; stp x29, x30, [sp, #0x1a0]; str x28, [sp, #0x1b0]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x1e0; stp x29, x30, [sp, #0x1a0]; str x28, [sp, #0x1b0]]
uint64_t fde_sub_081cfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10783FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081CFCULL;
}

// FDE #0508 | PC: 0x081de4..0x081f00 (284 B) | Symbol: _ZNKSt6__ndk110__time_put8__do_putEPwRS1_PK2tmcc
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xc0; stp x29, x30, [sp, #0x80]; str x23, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xc0; stp x29, x30, [sp, #0x80]; str x23, [sp, #0x90]]
uint64_t fde_sub_081de4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10303FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081DE4ULL;
}

// FDE #0509 | PC: 0x081f00..0x081f0c (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb0EE16do_decimal_pointEv
// EN: AArch64 prologue [bti c; mov w0, #0xff; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #0xff; ret]
uint64_t fde_sub_081f00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52801FE0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081F00ULL;
}

// FDE #0510 | PC: 0x081f0c..0x081f18 (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb0EE16do_thousands_sepEv
// EN: AArch64 prologue [bti c; mov w0, #0xff; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #0xff; ret]
uint64_t fde_sub_081f0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52801FE0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081F0CULL;
}

// FDE #0511 | PC: 0x081f18..0x081f28 (16 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb0EE11do_groupingEv
// EN: AArch64 prologue [bti c; stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [bti c; stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret]
uint64_t fde_sub_081f18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9007D1FULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081F18ULL;
}

// FDE #0512 | PC: 0x081f28..0x081f38 (16 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb0EE14do_curr_symbolEv
// EN: AArch64 prologue [bti c; stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [bti c; stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret]
uint64_t fde_sub_081f28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9007D1FULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081F28ULL;
}

// FDE #0513 | PC: 0x081f38..0x081f48 (16 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb0EE16do_positive_signEv
// EN: AArch64 prologue [bti c; stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [bti c; stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret]
uint64_t fde_sub_081f38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9007D1FULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081F38ULL;
}

// FDE #0514 | PC: 0x081f48..0x081f5c (20 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb0EE16do_negative_signEv
// EN: AArch64 prologue [bti c; mov w9, #0x2d02; strh w9, [x8]; strb wzr, [x8, #2]] | VI: Khởi đầu hàm AArch64 [bti c; mov w9, #0x2d02; strh w9, [x8]; strb wzr, [x8, #2]]
uint64_t fde_sub_081f48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5285A049ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081F48ULL;
}

// FDE #0515 | PC: 0x081f5c..0x081f68 (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb0EE14do_frac_digitsEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_081f5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081F5CULL;
}

// FDE #0516 | PC: 0x081f68..0x081f78 (16 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb0EE13do_pos_formatEv
// EN: AArch64 prologue [bti c; mov w0, #0x302; movk w0, #0x400, lsl #16; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #0x302; movk w0, #0x400, lsl #16; ret]
uint64_t fde_sub_081f68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52806040ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081F68ULL;
}

// FDE #0517 | PC: 0x081f78..0x081f88 (16 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb0EE13do_neg_formatEv
// EN: AArch64 prologue [bti c; mov w0, #0x302; movk w0, #0x400, lsl #16; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #0x302; movk w0, #0x400, lsl #16; ret]
uint64_t fde_sub_081f78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52806040ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081F78ULL;
}

// FDE #0518 | PC: 0x081f88..0x081f94 (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb1EE16do_decimal_pointEv
// EN: AArch64 prologue [bti c; mov w0, #0xff; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #0xff; ret]
uint64_t fde_sub_081f88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52801FE0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081F88ULL;
}

// FDE #0519 | PC: 0x081f94..0x081fa0 (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb1EE16do_thousands_sepEv
// EN: AArch64 prologue [bti c; mov w0, #0xff; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #0xff; ret]
uint64_t fde_sub_081f94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52801FE0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081F94ULL;
}

// FDE #0520 | PC: 0x081fa0..0x081fb0 (16 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb1EE11do_groupingEv
// EN: AArch64 prologue [bti c; stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [bti c; stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret]
uint64_t fde_sub_081fa0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9007D1FULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081FA0ULL;
}

// FDE #0521 | PC: 0x081fb0..0x081fc0 (16 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb1EE14do_curr_symbolEv
// EN: AArch64 prologue [bti c; stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [bti c; stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret]
uint64_t fde_sub_081fb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9007D1FULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081FB0ULL;
}

// FDE #0522 | PC: 0x081fc0..0x081fd0 (16 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb1EE16do_positive_signEv
// EN: AArch64 prologue [bti c; stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [bti c; stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret]
uint64_t fde_sub_081fc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9007D1FULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081FC0ULL;
}

// FDE #0523 | PC: 0x081fd0..0x081fe4 (20 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb1EE16do_negative_signEv
// EN: AArch64 prologue [bti c; mov w9, #0x2d02; strh w9, [x8]; strb wzr, [x8, #2]] | VI: Khởi đầu hàm AArch64 [bti c; mov w9, #0x2d02; strh w9, [x8]; strb wzr, [x8, #2]]
uint64_t fde_sub_081fd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5285A049ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081FD0ULL;
}

// FDE #0524 | PC: 0x081fe4..0x081ff0 (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb1EE14do_frac_digitsEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_081fe4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081FE4ULL;
}

// FDE #0525 | PC: 0x081ff0..0x082000 (16 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb1EE13do_pos_formatEv
// EN: AArch64 prologue [bti c; mov w0, #0x302; movk w0, #0x400, lsl #16; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #0x302; movk w0, #0x400, lsl #16; ret]
uint64_t fde_sub_081ff0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52806040ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081FF0ULL;
}

// FDE #0526 | PC: 0x082000..0x082010 (16 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb1EE13do_neg_formatEv
// EN: AArch64 prologue [bti c; mov w0, #0x302; movk w0, #0x400, lsl #16; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #0x302; movk w0, #0x400, lsl #16; ret]
uint64_t fde_sub_082000(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52806040ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082000ULL;
}

// FDE #0527 | PC: 0x082010..0x08201c (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb0EE16do_decimal_pointEv
// EN: AArch64 prologue [bti c; mov w0, #-1; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #-1; ret]
uint64_t fde_sub_082010(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12800000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082010ULL;
}

// FDE #0528 | PC: 0x08201c..0x082028 (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb0EE16do_thousands_sepEv
// EN: AArch64 prologue [bti c; mov w0, #-1; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #-1; ret]
uint64_t fde_sub_08201c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12800000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08201CULL;
}

// FDE #0529 | PC: 0x082028..0x082038 (16 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb0EE11do_groupingEv
// EN: AArch64 prologue [bti c; stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [bti c; stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret]
uint64_t fde_sub_082028(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9007D1FULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082028ULL;
}

// FDE #0530 | PC: 0x082038..0x082048 (16 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb0EE14do_curr_symbolEv
// EN: AArch64 prologue [bti c; stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [bti c; stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret]
uint64_t fde_sub_082038(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9007D1FULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082038ULL;
}

// FDE #0531 | PC: 0x082048..0x082058 (16 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb0EE16do_positive_signEv
// EN: AArch64 prologue [bti c; stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [bti c; stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret]
uint64_t fde_sub_082048(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9007D1FULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082048ULL;
}

// FDE #0532 | PC: 0x082058..0x08209c (68 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb0EE16do_negative_signEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_082058(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082058ULL;
}

// FDE #0533 | PC: 0x08209c..0x0820a8 (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb0EE14do_frac_digitsEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_08209c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08209CULL;
}

// FDE #0534 | PC: 0x0820a8..0x0820b8 (16 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb0EE13do_pos_formatEv
// EN: AArch64 prologue [bti c; mov w0, #0x302; movk w0, #0x400, lsl #16; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #0x302; movk w0, #0x400, lsl #16; ret]
uint64_t fde_sub_0820a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52806040ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0820A8ULL;
}

// FDE #0535 | PC: 0x0820b8..0x0820c8 (16 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb0EE13do_neg_formatEv
// EN: AArch64 prologue [bti c; mov w0, #0x302; movk w0, #0x400, lsl #16; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #0x302; movk w0, #0x400, lsl #16; ret]
uint64_t fde_sub_0820b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52806040ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0820B8ULL;
}

// FDE #0536 | PC: 0x0820c8..0x0820d4 (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb1EE16do_decimal_pointEv
// EN: AArch64 prologue [bti c; mov w0, #-1; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #-1; ret]
uint64_t fde_sub_0820c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12800000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0820C8ULL;
}

// FDE #0537 | PC: 0x0820d4..0x0820e0 (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb1EE16do_thousands_sepEv
// EN: AArch64 prologue [bti c; mov w0, #-1; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #-1; ret]
uint64_t fde_sub_0820d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12800000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0820D4ULL;
}

// FDE #0538 | PC: 0x0820e0..0x0820f0 (16 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb1EE11do_groupingEv
// EN: AArch64 prologue [bti c; stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [bti c; stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret]
uint64_t fde_sub_0820e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9007D1FULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0820E0ULL;
}

// FDE #0539 | PC: 0x0820f0..0x082100 (16 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb1EE14do_curr_symbolEv
// EN: AArch64 prologue [bti c; stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [bti c; stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret]
uint64_t fde_sub_0820f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9007D1FULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0820F0ULL;
}

// FDE #0540 | PC: 0x082100..0x082110 (16 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb1EE16do_positive_signEv
// EN: AArch64 prologue [bti c; stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [bti c; stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret]
uint64_t fde_sub_082100(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9007D1FULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082100ULL;
}

// FDE #0541 | PC: 0x082110..0x082154 (68 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb1EE16do_negative_signEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_082110(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082110ULL;
}

// FDE #0542 | PC: 0x082154..0x082160 (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb1EE14do_frac_digitsEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_082154(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082154ULL;
}

// FDE #0543 | PC: 0x082160..0x082170 (16 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb1EE13do_pos_formatEv
// EN: AArch64 prologue [bti c; mov w0, #0x302; movk w0, #0x400, lsl #16; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #0x302; movk w0, #0x400, lsl #16; ret]
uint64_t fde_sub_082160(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52806040ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082160ULL;
}

// FDE #0544 | PC: 0x082170..0x082180 (16 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb1EE13do_neg_formatEv
// EN: AArch64 prologue [bti c; mov w0, #0x302; movk w0, #0x400, lsl #16; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #0x302; movk w0, #0x400, lsl #16; ret]
uint64_t fde_sub_082170(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52806040ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082170ULL;
}

// FDE #0545 | PC: 0x082180..0x08218c (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb0EE16do_decimal_pointEv
// EN: AArch64 prologue [bti c; ldrb w0, [x0, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w0, [x0, #0x10]; ret]
uint64_t fde_sub_082180(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39404000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082180ULL;
}

// FDE #0546 | PC: 0x08218c..0x082198 (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb0EE16do_thousands_sepEv
// EN: AArch64 prologue [bti c; ldrb w0, [x0, #0x11]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w0, [x0, #0x11]; ret]
uint64_t fde_sub_08218c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39404400ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08218CULL;
}

// FDE #0547 | PC: 0x082198..0x0821a8 (16 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb0EE11do_groupingEv
// EN: AArch64 prologue [bti c; add x1, x0, #0x18; mov x0, x8; b #0xc8f50] | VI: Khởi đầu hàm AArch64 [bti c; add x1, x0, #0x18; mov x0, x8; b #0xc8f50]
uint64_t fde_sub_082198(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91006001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082198ULL;
}

// FDE #0548 | PC: 0x0821a8..0x0821b8 (16 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb0EE14do_curr_symbolEv
// EN: AArch64 prologue [bti c; add x1, x0, #0x30; mov x0, x8; b #0xc8f50] | VI: Khởi đầu hàm AArch64 [bti c; add x1, x0, #0x30; mov x0, x8; b #0xc8f50]
uint64_t fde_sub_0821a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9100C001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0821A8ULL;
}

// FDE #0549 | PC: 0x0821b8..0x0821c8 (16 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb0EE16do_positive_signEv
// EN: AArch64 prologue [bti c; add x1, x0, #0x48; mov x0, x8; b #0xc8f50] | VI: Khởi đầu hàm AArch64 [bti c; add x1, x0, #0x48; mov x0, x8; b #0xc8f50]
uint64_t fde_sub_0821b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91012001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0821B8ULL;
}

// FDE #0550 | PC: 0x0821c8..0x0821d8 (16 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb0EE16do_negative_signEv
// EN: AArch64 prologue [bti c; add x1, x0, #0x60; mov x0, x8; b #0xc8f50] | VI: Khởi đầu hàm AArch64 [bti c; add x1, x0, #0x60; mov x0, x8; b #0xc8f50]
uint64_t fde_sub_0821c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91018001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0821C8ULL;
}

// FDE #0551 | PC: 0x0821d8..0x0821e4 (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb0EE14do_frac_digitsEv
// EN: AArch64 prologue [bti c; ldr w0, [x0, #0x78]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldr w0, [x0, #0x78]; ret]
uint64_t fde_sub_0821d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9407800ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0821D8ULL;
}

// FDE #0552 | PC: 0x0821e4..0x0821f0 (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb0EE13do_pos_formatEv
// EN: AArch64 prologue [bti c; ldr w0, [x0, #0x7c]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldr w0, [x0, #0x7c]; ret]
uint64_t fde_sub_0821e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9407C00ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0821E4ULL;
}

// FDE #0553 | PC: 0x0821f0..0x0821fc (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb0EE13do_neg_formatEv
// EN: AArch64 prologue [bti c; ldr w0, [x0, #0x80]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldr w0, [x0, #0x80]; ret]
uint64_t fde_sub_0821f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9408000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0821F0ULL;
}

// FDE #0554 | PC: 0x0821fc..0x082208 (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb1EE16do_decimal_pointEv
// EN: AArch64 prologue [bti c; ldrb w0, [x0, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w0, [x0, #0x10]; ret]
uint64_t fde_sub_0821fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39404000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0821FCULL;
}

// FDE #0555 | PC: 0x082208..0x082214 (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb1EE16do_thousands_sepEv
// EN: AArch64 prologue [bti c; ldrb w0, [x0, #0x11]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w0, [x0, #0x11]; ret]
uint64_t fde_sub_082208(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39404400ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082208ULL;
}

// FDE #0556 | PC: 0x082214..0x082224 (16 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb1EE11do_groupingEv
// EN: AArch64 prologue [bti c; add x1, x0, #0x18; mov x0, x8; b #0xc8f50] | VI: Khởi đầu hàm AArch64 [bti c; add x1, x0, #0x18; mov x0, x8; b #0xc8f50]
uint64_t fde_sub_082214(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91006001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082214ULL;
}

// FDE #0557 | PC: 0x082224..0x082234 (16 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb1EE14do_curr_symbolEv
// EN: AArch64 prologue [bti c; add x1, x0, #0x30; mov x0, x8; b #0xc8f50] | VI: Khởi đầu hàm AArch64 [bti c; add x1, x0, #0x30; mov x0, x8; b #0xc8f50]
uint64_t fde_sub_082224(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9100C001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082224ULL;
}

// FDE #0558 | PC: 0x082234..0x082244 (16 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb1EE16do_positive_signEv
// EN: AArch64 prologue [bti c; add x1, x0, #0x48; mov x0, x8; b #0xc8f50] | VI: Khởi đầu hàm AArch64 [bti c; add x1, x0, #0x48; mov x0, x8; b #0xc8f50]
uint64_t fde_sub_082234(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91012001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082234ULL;
}

// FDE #0559 | PC: 0x082244..0x082254 (16 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb1EE16do_negative_signEv
// EN: AArch64 prologue [bti c; add x1, x0, #0x60; mov x0, x8; b #0xc8f50] | VI: Khởi đầu hàm AArch64 [bti c; add x1, x0, #0x60; mov x0, x8; b #0xc8f50]
uint64_t fde_sub_082244(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91018001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082244ULL;
}

// FDE #0560 | PC: 0x082254..0x082260 (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb1EE14do_frac_digitsEv
// EN: AArch64 prologue [bti c; ldr w0, [x0, #0x78]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldr w0, [x0, #0x78]; ret]
uint64_t fde_sub_082254(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9407800ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082254ULL;
}

// FDE #0561 | PC: 0x082260..0x08226c (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb1EE13do_pos_formatEv
// EN: AArch64 prologue [bti c; ldr w0, [x0, #0x7c]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldr w0, [x0, #0x7c]; ret]
uint64_t fde_sub_082260(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9407C00ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082260ULL;
}

// FDE #0562 | PC: 0x08226c..0x082278 (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb1EE13do_neg_formatEv
// EN: AArch64 prologue [bti c; ldr w0, [x0, #0x80]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldr w0, [x0, #0x80]; ret]
uint64_t fde_sub_08226c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9408000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08226CULL;
}

// FDE #0563 | PC: 0x082278..0x082284 (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb0EE16do_decimal_pointEv
// EN: AArch64 prologue [bti c; ldr w0, [x0, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldr w0, [x0, #0x10]; ret]
uint64_t fde_sub_082278(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9401000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082278ULL;
}

// FDE #0564 | PC: 0x082284..0x082290 (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb0EE16do_thousands_sepEv
// EN: AArch64 prologue [bti c; ldr w0, [x0, #0x14]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldr w0, [x0, #0x14]; ret]
uint64_t fde_sub_082284(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9401400ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082284ULL;
}

// FDE #0565 | PC: 0x082290..0x0822a0 (16 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb0EE11do_groupingEv
// EN: AArch64 prologue [bti c; add x1, x0, #0x18; mov x0, x8; b #0xc8f50] | VI: Khởi đầu hàm AArch64 [bti c; add x1, x0, #0x18; mov x0, x8; b #0xc8f50]
uint64_t fde_sub_082290(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91006001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082290ULL;
}

// FDE #0566 | PC: 0x0822a0..0x0822b0 (16 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb0EE14do_curr_symbolEv
// EN: AArch64 prologue [bti c; add x1, x0, #0x30; mov x0, x8; b #0xc8f60] | VI: Khởi đầu hàm AArch64 [bti c; add x1, x0, #0x30; mov x0, x8; b #0xc8f60]
uint64_t fde_sub_0822a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9100C001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0822A0ULL;
}

// FDE #0567 | PC: 0x0822b0..0x0822c0 (16 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb0EE16do_positive_signEv
// EN: AArch64 prologue [bti c; add x1, x0, #0x48; mov x0, x8; b #0xc8f60] | VI: Khởi đầu hàm AArch64 [bti c; add x1, x0, #0x48; mov x0, x8; b #0xc8f60]
uint64_t fde_sub_0822b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91012001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0822B0ULL;
}

// FDE #0568 | PC: 0x0822c0..0x0822d0 (16 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb0EE16do_negative_signEv
// EN: AArch64 prologue [bti c; add x1, x0, #0x60; mov x0, x8; b #0xc8f60] | VI: Khởi đầu hàm AArch64 [bti c; add x1, x0, #0x60; mov x0, x8; b #0xc8f60]
uint64_t fde_sub_0822c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91018001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0822C0ULL;
}

// FDE #0569 | PC: 0x0822d0..0x0822dc (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb0EE14do_frac_digitsEv
// EN: AArch64 prologue [bti c; ldr w0, [x0, #0x78]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldr w0, [x0, #0x78]; ret]
uint64_t fde_sub_0822d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9407800ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0822D0ULL;
}

// FDE #0570 | PC: 0x0822dc..0x0822e8 (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb0EE13do_pos_formatEv
// EN: AArch64 prologue [bti c; ldr w0, [x0, #0x7c]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldr w0, [x0, #0x7c]; ret]
uint64_t fde_sub_0822dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9407C00ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0822DCULL;
}

// FDE #0571 | PC: 0x0822e8..0x0822f4 (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb0EE13do_neg_formatEv
// EN: AArch64 prologue [bti c; ldr w0, [x0, #0x80]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldr w0, [x0, #0x80]; ret]
uint64_t fde_sub_0822e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9408000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0822E8ULL;
}

// FDE #0572 | PC: 0x0822f4..0x082300 (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb1EE16do_decimal_pointEv
// EN: AArch64 prologue [bti c; ldr w0, [x0, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldr w0, [x0, #0x10]; ret]
uint64_t fde_sub_0822f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9401000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0822F4ULL;
}

// FDE #0573 | PC: 0x082300..0x08230c (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb1EE16do_thousands_sepEv
// EN: AArch64 prologue [bti c; ldr w0, [x0, #0x14]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldr w0, [x0, #0x14]; ret]
uint64_t fde_sub_082300(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9401400ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082300ULL;
}

// FDE #0574 | PC: 0x08230c..0x08231c (16 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb1EE11do_groupingEv
// EN: AArch64 prologue [bti c; add x1, x0, #0x18; mov x0, x8; b #0xc8f50] | VI: Khởi đầu hàm AArch64 [bti c; add x1, x0, #0x18; mov x0, x8; b #0xc8f50]
uint64_t fde_sub_08230c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91006001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08230CULL;
}

// FDE #0575 | PC: 0x08231c..0x08232c (16 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb1EE14do_curr_symbolEv
// EN: AArch64 prologue [bti c; add x1, x0, #0x30; mov x0, x8; b #0xc8f60] | VI: Khởi đầu hàm AArch64 [bti c; add x1, x0, #0x30; mov x0, x8; b #0xc8f60]
uint64_t fde_sub_08231c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9100C001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08231CULL;
}

// FDE #0576 | PC: 0x08232c..0x08233c (16 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb1EE16do_positive_signEv
// EN: AArch64 prologue [bti c; add x1, x0, #0x48; mov x0, x8; b #0xc8f60] | VI: Khởi đầu hàm AArch64 [bti c; add x1, x0, #0x48; mov x0, x8; b #0xc8f60]
uint64_t fde_sub_08232c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91012001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08232CULL;
}

// FDE #0577 | PC: 0x08233c..0x08234c (16 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb1EE16do_negative_signEv
// EN: AArch64 prologue [bti c; add x1, x0, #0x60; mov x0, x8; b #0xc8f60] | VI: Khởi đầu hàm AArch64 [bti c; add x1, x0, #0x60; mov x0, x8; b #0xc8f60]
uint64_t fde_sub_08233c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91018001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08233CULL;
}

// FDE #0578 | PC: 0x08234c..0x082358 (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb1EE14do_frac_digitsEv
// EN: AArch64 prologue [bti c; ldr w0, [x0, #0x78]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldr w0, [x0, #0x78]; ret]
uint64_t fde_sub_08234c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9407800ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08234CULL;
}

// FDE #0579 | PC: 0x082358..0x082364 (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb1EE13do_pos_formatEv
// EN: AArch64 prologue [bti c; ldr w0, [x0, #0x7c]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldr w0, [x0, #0x7c]; ret]
uint64_t fde_sub_082358(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9407C00ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082358ULL;
}

// FDE #0580 | PC: 0x082364..0x082370 (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb1EE13do_neg_formatEv
// EN: AArch64 prologue [bti c; ldr w0, [x0, #0x80]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldr w0, [x0, #0x80]; ret]
uint64_t fde_sub_082364(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9408000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082364ULL;
}

// FDE #0581 | PC: 0x082370..0x082788 (1048 B) | Symbol: _ZNKSt6__ndk19money_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_getES4_S4_bRNS_8ios_baseERjRe
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x1a0; stp x29, x30, [sp, #0x140]; stp x28, x27, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x1a0; stp x29, x30, [sp, #0x140]; stp x28, x27, [sp, #0x150]]
uint64_t fde_sub_082370(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10683FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0418ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082370ULL;
}

// FDE #0582 | PC: 0x082788..0x082790 (8 B) | Symbol: _ZNSt6__ndk112__do_nothingEPv
// EN: AArch64 prologue [bti c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ret]
uint64_t fde_sub_082788(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082788ULL;
}

// FDE #0583 | PC: 0x082790..0x0839dc (4684 B) | Symbol: _ZNSt6__ndk19money_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE8__do_getERS4_S4_bRKNS_6localeEjRjRbRKNS_5ctypeIcEERNS_10unique_ptrIcPFvPvEEERPcSM_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_082790(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x124CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082790ULL;
}

// FDE #0584 | PC: 0x0839dc..0x083a30 (84 B) | Symbol: _ZNSt6__ndk121__throw_runtime_errorEPKc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0839dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0839DCULL;
}

// FDE #0585 | PC: 0x083a30..0x083d0c (732 B) | Symbol: _ZNKSt6__ndk19money_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_getES4_S4_bRNS_8ios_baseERjRNS_12basic_stringIcS3_NS_9allocatorIcEEEE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x140; stp x29, x30, [sp, #0xe0]; stp x28, x27, [sp, #0xf0]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x140; stp x29, x30, [sp, #0xe0]; stp x28, x27, [sp, #0xf0]]
uint64_t fde_sub_083a30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10503FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x02DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x083A30ULL;
}

// FDE #0586 | PC: 0x083d0c..0x083f6c (608 B) | Symbol: _ZNSt6__ndk111__money_getIcE13__gather_infoEbRKNS_6localeERNS_10money_base7patternERcS8_RNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEESF_SF_SF_Ri
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x30]; stp x28, x27, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x30]; stp x28, x27, [sp, #0x40]]
uint64_t fde_sub_083d0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10243FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0260ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x083D0CULL;
}

// FDE #0587 | PC: 0x083f6c..0x084064 (248 B) | Symbol: _ZNSt6__ndk116__check_groupingERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPjS8_Rj
// EN: AArch64 prologue [bti c; ldrb w9, [x0]; ldr x8, [x0, #8]; ands w11, w9, #1] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w9, [x0]; ldr x8, [x0, #8]; ands w11, w9, #1]
uint64_t fde_sub_083f6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39400009ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x083F6CULL;
}

// FDE #0588 | PC: 0x084064..0x084498 (1076 B) | Symbol: _ZNKSt6__ndk19money_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_getES4_S4_bRNS_8ios_baseERjRe
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_084064(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0434ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x084064ULL;
}

// FDE #0589 | PC: 0x084498..0x0857d0 (4920 B) | Symbol: _ZNSt6__ndk19money_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE8__do_getERS4_S4_bRKNS_6localeEjRjRbRKNS_5ctypeIwEERNS_10unique_ptrIwPFvPvEEERPwSM_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_084498(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x1338ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x084498ULL;
}

// FDE #0590 | PC: 0x0857d0..0x085ab8 (744 B) | Symbol: _ZNKSt6__ndk19money_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_getES4_S4_bRNS_8ios_baseERjRNS_12basic_stringIwS3_NS_9allocatorIwEEEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_0857d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x02E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0857D0ULL;
}

// FDE #0591 | PC: 0x085ab8..0x085d18 (608 B) | Symbol: _ZNSt6__ndk111__money_getIwE13__gather_infoEbRKNS_6localeERNS_10money_base7patternERwS8_RNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS9_IwNSA_IwEENSC_IwEEEESJ_SJ_Ri
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x30]; stp x28, x27, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x30]; stp x28, x27, [sp, #0x40]]
uint64_t fde_sub_085ab8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10243FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0260ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085AB8ULL;
}

// FDE #0592 | PC: 0x085d18..0x0861bc (1188 B) | Symbol: _ZNKSt6__ndk19money_putIcNS_19ostreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_putES4_bRNS_8ios_baseEce
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_085d18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x04A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085D18ULL;
}

// FDE #0593 | PC: 0x0861bc..0x086268 (172 B) | Symbol: sub_0861bc
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x110; stp x29, x30, [sp, #0xf0]; stp x28, x19, [sp, #0x100]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x110; stp x29, x30, [sp, #0xf0]; stp x28, x19, [sp, #0x100]]
uint64_t fde_sub_0861bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10443FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0861BCULL;
}

// FDE #0594 | PC: 0x086268..0x0864b4 (588 B) | Symbol: _ZNSt6__ndk111__money_putIcE13__gather_infoEbbRKNS_6localeERNS_10money_base7patternERcS8_RNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEESF_SF_Ri
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x30]; stp x28, x27, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x30]; stp x28, x27, [sp, #0x40]]
uint64_t fde_sub_086268(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10243FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x024CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x086268ULL;
}

// FDE #0595 | PC: 0x0864b4..0x0869ac (1272 B) | Symbol: _ZNSt6__ndk111__money_putIcE8__formatEPcRS2_S3_jPKcS5_RKNS_5ctypeIcEEbRKNS_10money_base7patternEccRKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEESL_SL_i
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xd0; stp x29, x30, [sp, #0x70]; stp x28, x27, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xd0; stp x29, x30, [sp, #0x70]; stp x28, x27, [sp, #0x80]]
uint64_t fde_sub_0864b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10343FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x04F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0864B4ULL;
}

// FDE #0596 | PC: 0x0869ac..0x086d74 (968 B) | Symbol: _ZNKSt6__ndk19money_putIcNS_19ostreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_putES4_bRNS_8ios_baseEcRKNS_12basic_stringIcS3_NS_9allocatorIcEEEE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x190; stp x29, x30, [sp, #0x130]; stp x28, x27, [sp, #0x140]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x190; stp x29, x30, [sp, #0x130]; stp x28, x27, [sp, #0x140]]
uint64_t fde_sub_0869ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10643FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x03C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0869ACULL;
}

// FDE #0597 | PC: 0x086d74..0x08722c (1208 B) | Symbol: _ZNKSt6__ndk19money_putIwNS_19ostreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_putES4_bRNS_8ios_baseEwe
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_086d74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x04B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x086D74ULL;
}

// FDE #0598 | PC: 0x08722c..0x087478 (588 B) | Symbol: _ZNSt6__ndk111__money_putIwE13__gather_infoEbbRKNS_6localeERNS_10money_base7patternERwS8_RNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS9_IwNSA_IwEENSC_IwEEEESJ_Ri
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x30]; stp x28, x27, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x30]; stp x28, x27, [sp, #0x40]]
uint64_t fde_sub_08722c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10243FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x024CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08722CULL;
}

// FDE #0599 | PC: 0x087478..0x08795c (1252 B) | Symbol: _ZNSt6__ndk111__money_putIwE8__formatEPwRS2_S3_jPKwS5_RKNS_5ctypeIwEEbRKNS_10money_base7patternEwwRKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERKNSE_IwNSF_IwEENSH_IwEEEESQ_i
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xc0; stp x29, x30, [sp, #0x60]; stp x28, x27, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xc0; stp x29, x30, [sp, #0x60]; stp x28, x27, [sp, #0x70]]
uint64_t fde_sub_087478(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10303FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x04E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087478ULL;
}

// FDE #0600 | PC: 0x08795c..0x087d28 (972 B) | Symbol: _ZNKSt6__ndk19money_putIwNS_19ostreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_putES4_bRNS_8ios_baseEwRKNS_12basic_stringIwS3_NS_9allocatorIwEEEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_08795c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x03CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08795CULL;
}

// FDE #0601 | PC: 0x087d28..0x087d34 (12 B) | Symbol: _ZNKSt6__ndk18messagesIcE7do_openERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERKNS_6localeE
// EN: AArch64 prologue [bti c; mov x0, #-1; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov x0, #-1; ret]
uint64_t fde_sub_087d28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x92800000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087D28ULL;
}

// FDE #0602 | PC: 0x087d34..0x087d44 (16 B) | Symbol: _ZNKSt6__ndk18messagesIcE6do_getEliiRKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE
// EN: AArch64 prologue [bti c; mov x1, x4; mov x0, x8; b #0xc8f50] | VI: Khởi đầu hàm AArch64 [bti c; mov x1, x4; mov x0, x8; b #0xc8f50]
uint64_t fde_sub_087d34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0403E1ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087D34ULL;
}

// FDE #0603 | PC: 0x087d44..0x087d4c (8 B) | Symbol: _ZNKSt6__ndk18messagesIcE8do_closeEl
// EN: AArch64 prologue [bti c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ret]
uint64_t fde_sub_087d44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087D44ULL;
}

// FDE #0604 | PC: 0x087d4c..0x087d58 (12 B) | Symbol: _ZNKSt6__ndk18messagesIwE7do_openERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERKNS_6localeE
// EN: AArch64 prologue [bti c; mov x0, #-1; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov x0, #-1; ret]
uint64_t fde_sub_087d4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x92800000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087D4CULL;
}

// FDE #0605 | PC: 0x087d58..0x087d68 (16 B) | Symbol: _ZNKSt6__ndk18messagesIwE6do_getEliiRKNS_12basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEEE
// EN: AArch64 prologue [bti c; mov x1, x4; mov x0, x8; b #0xc8f60] | VI: Khởi đầu hàm AArch64 [bti c; mov x1, x4; mov x0, x8; b #0xc8f60]
uint64_t fde_sub_087d58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0403E1ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087D58ULL;
}

// FDE #0606 | PC: 0x087d68..0x087d70 (8 B) | Symbol: _ZNKSt6__ndk18messagesIwE8do_closeEl
// EN: AArch64 prologue [bti c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ret]
uint64_t fde_sub_087d68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087D68ULL;
}

// FDE #0607 | PC: 0x087d70..0x087d78 (8 B) | Symbol: _ZNSt6__ndk114codecvt_bynameIcc9mbstate_tED2Ev
// EN: AArch64 prologue [bti c; b #0xc8bd0] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8bd0]
uint64_t fde_sub_087d70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14010397ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087D70ULL;
}

// FDE #0608 | PC: 0x087d78..0x087da4 (44 B) | Symbol: _ZNSt6__ndk114codecvt_bynameIcc9mbstate_tED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_087d78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087D78ULL;
}

// FDE #0609 | PC: 0x087da4..0x087dac (8 B) | Symbol: _ZNSt6__ndk114codecvt_bynameIwc9mbstate_tED2Ev
// EN: AArch64 prologue [bti c; b #0xc9030] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc9030]
uint64_t fde_sub_087da4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140104A2ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087DA4ULL;
}

// FDE #0610 | PC: 0x087dac..0x087dd8 (44 B) | Symbol: _ZNSt6__ndk114codecvt_bynameIwc9mbstate_tED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_087dac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087DACULL;
}

// FDE #0611 | PC: 0x087dd8..0x087de0 (8 B) | Symbol: _ZNSt6__ndk114codecvt_bynameIDsc9mbstate_tED2Ev
// EN: AArch64 prologue [bti c; b #0xc8bd0] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8bd0]
uint64_t fde_sub_087dd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1401037DULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087DD8ULL;
}

// FDE #0612 | PC: 0x087de0..0x087e0c (44 B) | Symbol: _ZNSt6__ndk114codecvt_bynameIDsc9mbstate_tED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_087de0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087DE0ULL;
}

// FDE #0613 | PC: 0x087e0c..0x087e14 (8 B) | Symbol: _ZNSt6__ndk114codecvt_bynameIDic9mbstate_tED2Ev
// EN: AArch64 prologue [bti c; b #0xc8bd0] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8bd0]
uint64_t fde_sub_087e0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14010370ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087E0CULL;
}

// FDE #0614 | PC: 0x087e14..0x087e40 (44 B) | Symbol: _ZNSt6__ndk114codecvt_bynameIDic9mbstate_tED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_087e14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087E14ULL;
}

// FDE #0615 | PC: 0x087e40..0x0898c0 (6784 B) | Symbol: sub_087e40
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xa0; stp x29, x30, [sp, #0x40]; stp x28, x27, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xa0; stp x29, x30, [sp, #0x40]; stp x28, x27, [sp, #0x50]]
uint64_t fde_sub_087e40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10283FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x1A80ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087E40ULL;
}

// FDE #0616 | PC: 0x0898c0..0x089f34 (1652 B) | Symbol: sub_0898c0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_0898c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0674ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0898C0ULL;
}

// FDE #0617 | PC: 0x089f34..0x089fcc (152 B) | Symbol: _ZNSt6__ndk16locale7classicEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_089f34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x089F34ULL;
}

// FDE #0618 | PC: 0x089fcc..0x08a0f8 (300 B) | Symbol: sub_089fcc
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]]
uint64_t fde_sub_089fcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x089FCCULL;
}

// FDE #0619 | PC: 0x08a0f8..0x08a224 (300 B) | Symbol: sub_08a0f8
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]]
uint64_t fde_sub_08a0f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08A0F8ULL;
}

// FDE #0620 | PC: 0x08a224..0x08a350 (300 B) | Symbol: sub_08a224
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]]
uint64_t fde_sub_08a224(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08A224ULL;
}

// FDE #0621 | PC: 0x08a350..0x08a47c (300 B) | Symbol: sub_08a350
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]]
uint64_t fde_sub_08a350(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08A350ULL;
}

// FDE #0622 | PC: 0x08a47c..0x08a5a8 (300 B) | Symbol: sub_08a47c
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]]
uint64_t fde_sub_08a47c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08A47CULL;
}

// FDE #0623 | PC: 0x08a5a8..0x08a6d4 (300 B) | Symbol: sub_08a5a8
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]]
uint64_t fde_sub_08a5a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08A5A8ULL;
}

// FDE #0624 | PC: 0x08a6d4..0x08a800 (300 B) | Symbol: sub_08a6d4
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]]
uint64_t fde_sub_08a6d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08A6D4ULL;
}

// FDE #0625 | PC: 0x08a800..0x08a92c (300 B) | Symbol: sub_08a800
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]]
uint64_t fde_sub_08a800(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08A800ULL;
}

// FDE #0626 | PC: 0x08a92c..0x08aa58 (300 B) | Symbol: sub_08a92c
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]]
uint64_t fde_sub_08a92c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08A92CULL;
}

// FDE #0627 | PC: 0x08aa58..0x08ab84 (300 B) | Symbol: sub_08aa58
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]]
uint64_t fde_sub_08aa58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08AA58ULL;
}

// FDE #0628 | PC: 0x08ab84..0x08acb0 (300 B) | Symbol: sub_08ab84
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]]
uint64_t fde_sub_08ab84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08AB84ULL;
}

// FDE #0629 | PC: 0x08acb0..0x08ad94 (228 B) | Symbol: sub_08acb0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_08acb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08ACB0ULL;
}

// FDE #0630 | PC: 0x08ad94..0x08aec0 (300 B) | Symbol: sub_08ad94
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]]
uint64_t fde_sub_08ad94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08AD94ULL;
}

// FDE #0631 | PC: 0x08aec0..0x08afa4 (228 B) | Symbol: sub_08aec0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_08aec0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08AEC0ULL;
}

// FDE #0632 | PC: 0x08afa4..0x08b0d0 (300 B) | Symbol: sub_08afa4
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]]
uint64_t fde_sub_08afa4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08AFA4ULL;
}

// FDE #0633 | PC: 0x08b0d0..0x08b1b4 (228 B) | Symbol: sub_08b0d0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_08b0d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B0D0ULL;
}

// FDE #0634 | PC: 0x08b1b4..0x08b2e0 (300 B) | Symbol: sub_08b1b4
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]]
uint64_t fde_sub_08b1b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B1B4ULL;
}

// FDE #0635 | PC: 0x08b2e0..0x08b3c4 (228 B) | Symbol: sub_08b2e0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_08b2e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B2E0ULL;
}

// FDE #0636 | PC: 0x08b3c4..0x08b4f0 (300 B) | Symbol: sub_08b3c4
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]]
uint64_t fde_sub_08b3c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B3C4ULL;
}

// FDE #0637 | PC: 0x08b4f0..0x08b61c (300 B) | Symbol: sub_08b4f0
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]]
uint64_t fde_sub_08b4f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B4F0ULL;
}

// FDE #0638 | PC: 0x08b61c..0x08b748 (300 B) | Symbol: sub_08b61c
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]]
uint64_t fde_sub_08b61c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B61CULL;
}

// FDE #0639 | PC: 0x08b748..0x08b830 (232 B) | Symbol: sub_08b748
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_08b748(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B748ULL;
}

// FDE #0640 | PC: 0x08b830..0x08b95c (300 B) | Symbol: sub_08b830
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]]
uint64_t fde_sub_08b830(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B830ULL;
}

// FDE #0641 | PC: 0x08b95c..0x08ba44 (232 B) | Symbol: sub_08b95c
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_08b95c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B95CULL;
}

// FDE #0642 | PC: 0x08ba44..0x08bb70 (300 B) | Symbol: sub_08ba44
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]]
uint64_t fde_sub_08ba44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BA44ULL;
}

// FDE #0643 | PC: 0x08bb70..0x08bc9c (300 B) | Symbol: sub_08bb70
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]]
uint64_t fde_sub_08bb70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BB70ULL;
}

// FDE #0644 | PC: 0x08bc9c..0x08be3c (416 B) | Symbol: sub_08bc9c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_08bc9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BC9CULL;
}

// FDE #0645 | PC: 0x08be3c..0x08c440 (1540 B) | Symbol: sub_08be3c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_08be3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0604ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BE3CULL;
}

// FDE #0646 | PC: 0x08c440..0x08dbfc (6076 B) | Symbol: sub_08c440
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xa0; stp x29, x30, [sp, #0x40]; stp x28, x27, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xa0; stp x29, x30, [sp, #0x40]; stp x28, x27, [sp, #0x50]]
uint64_t fde_sub_08c440(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10283FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x17BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C440ULL;
}

// FDE #0647 | PC: 0x08dbfc..0x08de4c (592 B) | Symbol: sub_08dbfc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_08dbfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0250ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DBFCULL;
}

// FDE #0648 | PC: 0x08de4c..0x08def8 (172 B) | Symbol: sub_08de4c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_08de4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DE4CULL;
}

// FDE #0649 | PC: 0x08def8..0x08dfa8 (176 B) | Symbol: sub_08def8
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_08def8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DEF8ULL;
}

// FDE #0650 | PC: 0x08dfa8..0x08dfd4 (44 B) | Symbol: sub_08dfa8
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_08dfa8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DFA8ULL;
}

// FDE #0651 | PC: 0x08dfd4..0x08e008 (52 B) | Symbol: sub_08dfd4
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldp x8, x9, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldp x8, x9, [x0, #0x10]]
uint64_t fde_sub_08dfd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DFD4ULL;
}

// FDE #0652 | PC: 0x08e008..0x08e048 (64 B) | Symbol: sub_08e008
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_08e008(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E008ULL;
}

// FDE #0653 | PC: 0x08e048..0x08e0f4 (172 B) | Symbol: sub_08e048
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_08e048(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E048ULL;
}

// FDE #0654 | PC: 0x08e0f4..0x08e1ec (248 B) | Symbol: _ZNSt6__ndk16locale8__globalEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_08e0f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E0F4ULL;
}

// FDE #0655 | PC: 0x08e1ec..0x08e220 (52 B) | Symbol: _ZNSt6__ndk16localeC2Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_08e1ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E1ECULL;
}

// FDE #0656 | PC: 0x08e220..0x08e234 (20 B) | Symbol: _ZNSt6__ndk16localeC2ERKS0_
// EN: AArch64 prologue [bti c; ldr x8, [x1]; str x8, [x0]; mov x0, x8] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x1]; str x8, [x0]; mov x0, x8]
uint64_t fde_sub_08e220(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400028ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E220ULL;
}

// FDE #0657 | PC: 0x08e234..0x08e240 (12 B) | Symbol: _ZNSt6__ndk16localeD2Ev
// EN: AArch64 prologue [bti c; ldr x0, [x0]; b #0xc8bf0] | VI: Khởi đầu hàm AArch64 [bti c; ldr x0, [x0]; b #0xc8bf0]
uint64_t fde_sub_08e234(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E234ULL;
}

// FDE #0658 | PC: 0x08e240..0x08e288 (72 B) | Symbol: _ZNSt6__ndk16localeaSERKS0_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_08e240(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E240ULL;
}

// FDE #0659 | PC: 0x08e288..0x08e3d4 (332 B) | Symbol: _ZNSt6__ndk16localeC1EPKc
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]]
uint64_t fde_sub_08e288(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x014CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E288ULL;
}

// FDE #0660 | PC: 0x08e3d4..0x08e438 (100 B) | Symbol: _ZNSt6__ndk16localeC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_08e3d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E3D4ULL;
}

// FDE #0661 | PC: 0x08e438..0x08e59c (356 B) | Symbol: _ZNSt6__ndk16localeC1ERKS0_PKci
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x20]; str x27, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x20]; str x27, [sp, #0x30]]
uint64_t fde_sub_08e438(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0164ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E438ULL;
}

// FDE #0662 | PC: 0x08e59c..0x08e60c (112 B) | Symbol: _ZNSt6__ndk16localeC1ERKS0_RKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEi
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_08e59c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E59CULL;
}

// FDE #0663 | PC: 0x08e60c..0x08e67c (112 B) | Symbol: _ZNSt6__ndk16localeC2ERKS0_S2_i
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_08e60c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E60CULL;
}

// FDE #0664 | PC: 0x08e67c..0x08e690 (20 B) | Symbol: _ZNKSt6__ndk16locale4nameEv
// EN: AArch64 prologue [bti c; ldr x9, [x0]; mov x0, x8; add x1, x9, #0x120] | VI: Khởi đầu hàm AArch64 [bti c; ldr x9, [x0]; mov x0, x8; add x1, x9, #0x120]
uint64_t fde_sub_08e67c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400009ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E67CULL;
}

// FDE #0665 | PC: 0x08e690..0x08e70c (124 B) | Symbol: _ZNSt6__ndk16locale14__install_ctorERKS0_PNS0_5facetEl
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_08e690(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E690ULL;
}

// FDE #0666 | PC: 0x08e70c..0x08e888 (380 B) | Symbol: _ZNSt6__ndk16locale6globalERKS0_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]]
uint64_t fde_sub_08e70c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x017CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E70CULL;
}

// FDE #0667 | PC: 0x08e888..0x08e94c (196 B) | Symbol: _ZNKSt6__ndk16locale9has_facetERNS0_2idE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x30]; str x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x30]; str x21, [sp, #0x40]]
uint64_t fde_sub_08e888(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E888ULL;
}

// FDE #0668 | PC: 0x08e94c..0x08e9e0 (148 B) | Symbol: _ZNSt6__ndk16locale2id5__getEv
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_08e94c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E94CULL;
}

// FDE #0669 | PC: 0x08e9e0..0x08ea9c (188 B) | Symbol: _ZNKSt6__ndk16locale9use_facetERNS0_2idE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x30]; str x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x30]; str x21, [sp, #0x40]]
uint64_t fde_sub_08e9e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E9E0ULL;
}

// FDE #0670 | PC: 0x08ea9c..0x08ebbc (288 B) | Symbol: _ZNKSt6__ndk16localeeqERKS0_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_08ea9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0120ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EA9CULL;
}

// FDE #0671 | PC: 0x08ebbc..0x08ebe8 (44 B) | Symbol: _ZNSt6__ndk16locale5facetD0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_08ebbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EBBCULL;
}

// FDE #0672 | PC: 0x08ebe8..0x08ebf8 (16 B) | Symbol: _ZNSt6__ndk16locale5facet16__on_zero_sharedEv
// EN: AArch64 prologue [bti c; ldr x8, [x0]; ldr x16, [x8, #8]; br x16] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0]; ldr x16, [x8, #8]; br x16]
uint64_t fde_sub_08ebe8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EBE8ULL;
}

// FDE #0673 | PC: 0x08ebf8..0x08ec1c (36 B) | Symbol: _ZNSt6__ndk16locale2id6__initEv
// EN: AArch64 prologue [bti c; adrp x8, #0xd4000; ldr x8, [x8, #0x880]; ldaxr w9, [x8]] | VI: Khởi đầu hàm AArch64 [bti c; adrp x8, #0xd4000; ldr x8, [x8, #0x880]; ldaxr w9, [x8]]
uint64_t fde_sub_08ebf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000228ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EBF8ULL;
}

// FDE #0674 | PC: 0x08ec1c..0x08ed90 (372 B) | Symbol: _ZNSt6__ndk114collate_bynameIcEC2EPKcm
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; str x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; str x23, [sp, #0x50]]
uint64_t fde_sub_08ec1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0174ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EC1CULL;
}

// FDE #0675 | PC: 0x08ed90..0x08ede4 (84 B) | Symbol: sub_08ed90
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_08ed90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08ED90ULL;
}

// FDE #0676 | PC: 0x08ede4..0x08eec0 (220 B) | Symbol: _ZNSt6__ndk114collate_bynameIcEC2ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEm
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_08ede4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EDE4ULL;
}

// FDE #0677 | PC: 0x08eec0..0x08ef14 (84 B) | Symbol: _ZNSt6__ndk114collate_bynameIcED2Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_08eec0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EEC0ULL;
}

// FDE #0678 | PC: 0x08ef14..0x08ef70 (92 B) | Symbol: _ZNSt6__ndk114collate_bynameIcED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_08ef14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EF14ULL;
}

// FDE #0679 | PC: 0x08ef70..0x08f158 (488 B) | Symbol: _ZNKSt6__ndk114collate_bynameIcE10do_compareEPKcS3_S3_S3_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xa0; stp x29, x30, [sp, #0x40]; str x27, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xa0; stp x29, x30, [sp, #0x40]; str x27, [sp, #0x50]]
uint64_t fde_sub_08ef70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10283FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EF70ULL;
}

// FDE #0680 | PC: 0x08f158..0x08f35c (516 B) | Symbol: _ZNKSt6__ndk114collate_bynameIcE12do_transformEPKcS3_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; stp x26, x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; stp x26, x25, [sp, #0x30]]
uint64_t fde_sub_08f158(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0204ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F158ULL;
}

// FDE #0681 | PC: 0x08f35c..0x08f4d0 (372 B) | Symbol: _ZNSt6__ndk114collate_bynameIwEC2EPKcm
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; str x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; str x23, [sp, #0x50]]
uint64_t fde_sub_08f35c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0174ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F35CULL;
}

// FDE #0682 | PC: 0x08f4d0..0x08f5ac (220 B) | Symbol: _ZNSt6__ndk114collate_bynameIwEC2ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEm
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_08f4d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F4D0ULL;
}

// FDE #0683 | PC: 0x08f5ac..0x08f600 (84 B) | Symbol: _ZNSt6__ndk114collate_bynameIwED2Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_08f5ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F5ACULL;
}

// FDE #0684 | PC: 0x08f600..0x08f65c (92 B) | Symbol: _ZNSt6__ndk114collate_bynameIwED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_08f600(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F600ULL;
}

// FDE #0685 | PC: 0x08f65c..0x08f864 (520 B) | Symbol: _ZNKSt6__ndk114collate_bynameIwE10do_compareEPKwS3_S3_S3_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xa0; stp x29, x30, [sp, #0x40]; stp x28, x27, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xa0; stp x29, x30, [sp, #0x40]; stp x28, x27, [sp, #0x50]]
uint64_t fde_sub_08f65c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10283FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0208ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F65CULL;
}

// FDE #0686 | PC: 0x08f864..0x08fa8c (552 B) | Symbol: _ZNKSt6__ndk114collate_bynameIwE12do_transformEPKwS3_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x20]; str x27, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x20]; str x27, [sp, #0x30]]
uint64_t fde_sub_08f864(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0228ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F864ULL;
}

// FDE #0687 | PC: 0x08fa8c..0x08fab8 (44 B) | Symbol: _ZNSt6__ndk15ctypeIwED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_08fa8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FA8CULL;
}

// FDE #0688 | PC: 0x08fab8..0x08fae4 (44 B) | Symbol: _ZNKSt6__ndk15ctypeIwE5do_isEmw
// EN: AArch64 prologue [bti c; cmp w2, #0x7f; b.ls #0x8facc; mov w0, wzr] | VI: Khởi đầu hàm AArch64 [bti c; cmp w2, #0x7f; b.ls #0x8facc; mov w0, wzr]
uint64_t fde_sub_08fab8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7101FC5FULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FAB8ULL;
}

// FDE #0689 | PC: 0x08fae4..0x08faf4 (16 B) | Symbol: _ZNSt6__ndk15ctypeIcE13classic_tableEv
// EN: AArch64 prologue [bti c; adrp x0, #0x4a000; add x0, x0, #0x5c8; ret] | VI: Khởi đầu hàm AArch64 [bti c; adrp x0, #0x4a000; add x0, x0, #0x5c8; ret]
uint64_t fde_sub_08fae4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0FFFDC0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FAE4ULL;
}

// FDE #0690 | PC: 0x08faf4..0x08fb40 (76 B) | Symbol: _ZNKSt6__ndk15ctypeIwE5do_isEPKwS3_Pm
// EN: AArch64 prologue [bti c; mov x0, x1; cmp x1, x2; b.eq #0x8fb3c] | VI: Khởi đầu hàm AArch64 [bti c; mov x0, x1; cmp x1, x2; b.eq #0x8fb3c]
uint64_t fde_sub_08faf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FAF4ULL;
}

// FDE #0691 | PC: 0x08fb40..0x08fb8c (76 B) | Symbol: _ZNKSt6__ndk15ctypeIwE10do_scan_isEmPKwS3_
// EN: AArch64 prologue [bti c; mov x0, x2; cmp x2, x3; b.eq #0x8fb80] | VI: Khởi đầu hàm AArch64 [bti c; mov x0, x2; cmp x2, x3; b.eq #0x8fb80]
uint64_t fde_sub_08fb40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0203E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FB40ULL;
}

// FDE #0692 | PC: 0x08fb8c..0x08fbd0 (68 B) | Symbol: _ZNKSt6__ndk15ctypeIwE11do_scan_notEmPKwS3_
// EN: AArch64 prologue [bti c; mov x0, x2; cmp x2, x3; b.eq #0x8fbcc] | VI: Khởi đầu hàm AArch64 [bti c; mov x0, x2; cmp x2, x3; b.eq #0x8fbcc]
uint64_t fde_sub_08fb8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0203E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FB8CULL;
}

// FDE #0693 | PC: 0x08fbd0..0x08fc80 (176 B) | Symbol: _ZNKSt6__ndk15ctypeIwE10do_toupperEw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_08fbd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FBD0ULL;
}

// FDE #0694 | PC: 0x08fc80..0x08fd60 (224 B) | Symbol: _ZNKSt6__ndk15ctypeIwE10do_toupperEPwPKw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_08fc80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FC80ULL;
}

// FDE #0695 | PC: 0x08fd60..0x08fe10 (176 B) | Symbol: _ZNKSt6__ndk15ctypeIwE10do_tolowerEw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_08fd60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FD60ULL;
}

// FDE #0696 | PC: 0x08fe10..0x08fef0 (224 B) | Symbol: _ZNKSt6__ndk15ctypeIwE10do_tolowerEPwPKw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_08fe10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FE10ULL;
}

// FDE #0697 | PC: 0x08fef0..0x08fefc (12 B) | Symbol: _ZNKSt6__ndk15ctypeIwE8do_widenEc
// EN: AArch64 prologue [bti c; and w0, w1, #0xff; ret] | VI: Khởi đầu hàm AArch64 [bti c; and w0, w1, #0xff; ret]
uint64_t fde_sub_08fef0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12001C20ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FEF0ULL;
}

// FDE #0698 | PC: 0x08fefc..0x08ff24 (40 B) | Symbol: _ZNKSt6__ndk15ctypeIwE8do_widenEPKcS3_Pw
// EN: AArch64 prologue [bti c; mov x0, x1; cmp x1, x2; b.eq #0x8ff20] | VI: Khởi đầu hàm AArch64 [bti c; mov x0, x1; cmp x1, x2; b.eq #0x8ff20]
uint64_t fde_sub_08fefc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FEFCULL;
}

// FDE #0699 | PC: 0x08ff24..0x08ff34 (16 B) | Symbol: _ZNKSt6__ndk15ctypeIwE9do_narrowEwc
// EN: AArch64 prologue [bti c; cmp w1, #0x7f; csel w0, w2, w1, hi; ret] | VI: Khởi đầu hàm AArch64 [bti c; cmp w1, #0x7f; csel w0, w2, w1, hi; ret]
uint64_t fde_sub_08ff24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7101FC3FULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FF24ULL;
}

// FDE #0700 | PC: 0x08ff34..0x090000 (204 B) | Symbol: _ZNKSt6__ndk15ctypeIwE9do_narrowEPKwS3_cPc
// EN: AArch64 prologue [bti c; mov x0, x1; cmp x1, x2; b.eq #0x8fffc] | VI: Khởi đầu hàm AArch64 [bti c; mov x0, x1; cmp x1, x2; b.eq #0x8fffc]
uint64_t fde_sub_08ff34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FF34ULL;
}

// FDE #0701 | PC: 0x090000..0x09003c (60 B) | Symbol: _ZNSt6__ndk15ctypeIcEC2EPKmbm
// EN: AArch64 prologue [bti c; adrp x10, #0xd4000; ldr x10, [x10, #0x6c0]; and w8, w2, #1] | VI: Khởi đầu hàm AArch64 [bti c; adrp x10, #0xd4000; ldr x10, [x10, #0x6c0]; and w8, w2, #1]
uint64_t fde_sub_090000(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9000022AULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090000ULL;
}

// FDE #0702 | PC: 0x09003c..0x090088 (76 B) | Symbol: _ZNSt6__ndk15ctypeIcED2Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_09003c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09003CULL;
}

// FDE #0703 | PC: 0x090088..0x0900dc (84 B) | Symbol: _ZNSt6__ndk15ctypeIcED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_090088(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090088ULL;
}

uint64_t DispatchAppLovinShard2(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x071398ULL: return fde_sub_071398(a0, a1, a2);
        case 0x0713a0ULL: return fde_sub_0713a0(a0, a1, a2);
        case 0x0713ccULL: return fde_sub_0713cc(a0, a1, a2);
        case 0x071460ULL: return fde_sub_071460(a0, a1, a2);
        case 0x071480ULL: return fde_sub_071480(a0, a1, a2);
        case 0x071588ULL: return fde_sub_071588(a0, a1, a2);
        case 0x071690ULL: return fde_sub_071690(a0, a1, a2);
        case 0x071770ULL: return fde_sub_071770(a0, a1, a2);
        case 0x07179cULL: return fde_sub_07179c(a0, a1, a2);
        case 0x0717e0ULL: return fde_sub_0717e0(a0, a1, a2);
        case 0x0718bcULL: return fde_sub_0718bc(a0, a1, a2);
        case 0x071908ULL: return fde_sub_071908(a0, a1, a2);
        case 0x0719b0ULL: return fde_sub_0719b0(a0, a1, a2);
        case 0x071b34ULL: return fde_sub_071b34(a0, a1, a2);
        case 0x071b50ULL: return fde_sub_071b50(a0, a1, a2);
        case 0x071b7cULL: return fde_sub_071b7c(a0, a1, a2);
        case 0x071b84ULL: return fde_sub_071b84(a0, a1, a2);
        case 0x071bb0ULL: return fde_sub_071bb0(a0, a1, a2);
        case 0x071c08ULL: return fde_sub_071c08(a0, a1, a2);
        case 0x071cb4ULL: return fde_sub_071cb4(a0, a1, a2);
        case 0x071cecULL: return fde_sub_071cec(a0, a1, a2);
        case 0x071cf4ULL: return fde_sub_071cf4(a0, a1, a2);
        case 0x071d20ULL: return fde_sub_071d20(a0, a1, a2);
        case 0x071d78ULL: return fde_sub_071d78(a0, a1, a2);
        case 0x071e34ULL: return fde_sub_071e34(a0, a1, a2);
        case 0x071e6cULL: return fde_sub_071e6c(a0, a1, a2);
        case 0x07212cULL: return fde_sub_07212c(a0, a1, a2);
        case 0x0725b0ULL: return fde_sub_0725b0(a0, a1, a2);
        case 0x0725b8ULL: return fde_sub_0725b8(a0, a1, a2);
        case 0x072960ULL: return fde_sub_072960(a0, a1, a2);
        case 0x072968ULL: return fde_sub_072968(a0, a1, a2);
        case 0x072d10ULL: return fde_sub_072d10(a0, a1, a2);
        case 0x072d18ULL: return fde_sub_072d18(a0, a1, a2);
        case 0x0730c0ULL: return fde_sub_0730c0(a0, a1, a2);
        case 0x0730c8ULL: return fde_sub_0730c8(a0, a1, a2);
        case 0x073470ULL: return fde_sub_073470(a0, a1, a2);
        case 0x073478ULL: return fde_sub_073478(a0, a1, a2);
        case 0x073820ULL: return fde_sub_073820(a0, a1, a2);
        case 0x073828ULL: return fde_sub_073828(a0, a1, a2);
        case 0x073bd0ULL: return fde_sub_073bd0(a0, a1, a2);
        case 0x073bd8ULL: return fde_sub_073bd8(a0, a1, a2);
        case 0x073f64ULL: return fde_sub_073f64(a0, a1, a2);
        case 0x073f6cULL: return fde_sub_073f6c(a0, a1, a2);
        case 0x0742f8ULL: return fde_sub_0742f8(a0, a1, a2);
        case 0x074300ULL: return fde_sub_074300(a0, a1, a2);
        case 0x07468cULL: return fde_sub_07468c(a0, a1, a2);
        case 0x074b0cULL: return fde_sub_074b0c(a0, a1, a2);
        case 0x074e70ULL: return fde_sub_074e70(a0, a1, a2);
        case 0x074f50ULL: return fde_sub_074f50(a0, a1, a2);
        case 0x074fd8ULL: return fde_sub_074fd8(a0, a1, a2);
        case 0x075298ULL: return fde_sub_075298(a0, a1, a2);
        case 0x075750ULL: return fde_sub_075750(a0, a1, a2);
        case 0x075758ULL: return fde_sub_075758(a0, a1, a2);
        case 0x075b34ULL: return fde_sub_075b34(a0, a1, a2);
        case 0x075b3cULL: return fde_sub_075b3c(a0, a1, a2);
        case 0x075f18ULL: return fde_sub_075f18(a0, a1, a2);
        case 0x075f20ULL: return fde_sub_075f20(a0, a1, a2);
        case 0x0762fcULL: return fde_sub_0762fc(a0, a1, a2);
        case 0x076304ULL: return fde_sub_076304(a0, a1, a2);
        case 0x0766e0ULL: return fde_sub_0766e0(a0, a1, a2);
        case 0x0766e8ULL: return fde_sub_0766e8(a0, a1, a2);
        case 0x076ac4ULL: return fde_sub_076ac4(a0, a1, a2);
        case 0x076accULL: return fde_sub_076acc(a0, a1, a2);
        case 0x076ea8ULL: return fde_sub_076ea8(a0, a1, a2);
        case 0x076eb0ULL: return fde_sub_076eb0(a0, a1, a2);
        case 0x077274ULL: return fde_sub_077274(a0, a1, a2);
        case 0x07727cULL: return fde_sub_07727c(a0, a1, a2);
        case 0x077640ULL: return fde_sub_077640(a0, a1, a2);
        case 0x077648ULL: return fde_sub_077648(a0, a1, a2);
        case 0x077a0cULL: return fde_sub_077a0c(a0, a1, a2);
        case 0x077ec4ULL: return fde_sub_077ec4(a0, a1, a2);
        case 0x078228ULL: return fde_sub_078228(a0, a1, a2);
        case 0x0783f0ULL: return fde_sub_0783f0(a0, a1, a2);
        case 0x07885cULL: return fde_sub_07885c(a0, a1, a2);
        case 0x078a0cULL: return fde_sub_078a0c(a0, a1, a2);
        case 0x078bd4ULL: return fde_sub_078bd4(a0, a1, a2);
        case 0x07903cULL: return fde_sub_07903c(a0, a1, a2);
        case 0x0791ecULL: return fde_sub_0791ec(a0, a1, a2);
        case 0x0793dcULL: return fde_sub_0793dc(a0, a1, a2);
        case 0x079650ULL: return fde_sub_079650(a0, a1, a2);
        case 0x0796e8ULL: return fde_sub_0796e8(a0, a1, a2);
        case 0x0797ecULL: return fde_sub_0797ec(a0, a1, a2);
        case 0x07985cULL: return fde_sub_07985c(a0, a1, a2);
        case 0x079c64ULL: return fde_sub_079c64(a0, a1, a2);
        case 0x079ed4ULL: return fde_sub_079ed4(a0, a1, a2);
        case 0x07a164ULL: return fde_sub_07a164(a0, a1, a2);
        case 0x07a3f0ULL: return fde_sub_07a3f0(a0, a1, a2);
        case 0x07a850ULL: return fde_sub_07a850(a0, a1, a2);
        case 0x07a908ULL: return fde_sub_07a908(a0, a1, a2);
        case 0x07aa04ULL: return fde_sub_07aa04(a0, a1, a2);
        case 0x07afe8ULL: return fde_sub_07afe8(a0, a1, a2);
        case 0x07b450ULL: return fde_sub_07b450(a0, a1, a2);
        case 0x07b6b4ULL: return fde_sub_07b6b4(a0, a1, a2);
        case 0x07b8a8ULL: return fde_sub_07b8a8(a0, a1, a2);
        case 0x07bb2cULL: return fde_sub_07bb2c(a0, a1, a2);
        case 0x07bf30ULL: return fde_sub_07bf30(a0, a1, a2);
        case 0x07c104ULL: return fde_sub_07c104(a0, a1, a2);
        case 0x07c384ULL: return fde_sub_07c384(a0, a1, a2);
        case 0x07c618ULL: return fde_sub_07c618(a0, a1, a2);
        case 0x07c8a8ULL: return fde_sub_07c8a8(a0, a1, a2);
        case 0x07cd08ULL: return fde_sub_07cd08(a0, a1, a2);
        case 0x07d2f4ULL: return fde_sub_07d2f4(a0, a1, a2);
        case 0x07d75cULL: return fde_sub_07d75c(a0, a1, a2);
        case 0x07d9c0ULL: return fde_sub_07d9c0(a0, a1, a2);
        case 0x07de7cULL: return fde_sub_07de7c(a0, a1, a2);
        case 0x07de88ULL: return fde_sub_07de88(a0, a1, a2);
        case 0x07def4ULL: return fde_sub_07def4(a0, a1, a2);
        case 0x07df7cULL: return fde_sub_07df7c(a0, a1, a2);
        case 0x07e10cULL: return fde_sub_07e10c(a0, a1, a2);
        case 0x07e1c8ULL: return fde_sub_07e1c8(a0, a1, a2);
        case 0x07e354ULL: return fde_sub_07e354(a0, a1, a2);
        case 0x07e40cULL: return fde_sub_07e40c(a0, a1, a2);
        case 0x07e554ULL: return fde_sub_07e554(a0, a1, a2);
        case 0x07e5bcULL: return fde_sub_07e5bc(a0, a1, a2);
        case 0x07ec64ULL: return fde_sub_07ec64(a0, a1, a2);
        case 0x07ecc8ULL: return fde_sub_07ecc8(a0, a1, a2);
        case 0x07ed28ULL: return fde_sub_07ed28(a0, a1, a2);
        case 0x07ed8cULL: return fde_sub_07ed8c(a0, a1, a2);
        case 0x07edecULL: return fde_sub_07edec(a0, a1, a2);
        case 0x07ee50ULL: return fde_sub_07ee50(a0, a1, a2);
        case 0x07eeb0ULL: return fde_sub_07eeb0(a0, a1, a2);
        case 0x07f058ULL: return fde_sub_07f058(a0, a1, a2);
        case 0x07f148ULL: return fde_sub_07f148(a0, a1, a2);
        case 0x07f1a8ULL: return fde_sub_07f1a8(a0, a1, a2);
        case 0x07f208ULL: return fde_sub_07f208(a0, a1, a2);
        case 0x07f258ULL: return fde_sub_07f258(a0, a1, a2);
        case 0x07f414ULL: return fde_sub_07f414(a0, a1, a2);
        case 0x07f724ULL: return fde_sub_07f724(a0, a1, a2);
        case 0x07fc40ULL: return fde_sub_07fc40(a0, a1, a2);
        case 0x07fc4cULL: return fde_sub_07fc4c(a0, a1, a2);
        case 0x07fcb4ULL: return fde_sub_07fcb4(a0, a1, a2);
        case 0x07fd40ULL: return fde_sub_07fd40(a0, a1, a2);
        case 0x07fed0ULL: return fde_sub_07fed0(a0, a1, a2);
        case 0x07ff8cULL: return fde_sub_07ff8c(a0, a1, a2);
        case 0x080118ULL: return fde_sub_080118(a0, a1, a2);
        case 0x0801d0ULL: return fde_sub_0801d0(a0, a1, a2);
        case 0x080318ULL: return fde_sub_080318(a0, a1, a2);
        case 0x080380ULL: return fde_sub_080380(a0, a1, a2);
        case 0x080a18ULL: return fde_sub_080a18(a0, a1, a2);
        case 0x080a7cULL: return fde_sub_080a7c(a0, a1, a2);
        case 0x080adcULL: return fde_sub_080adc(a0, a1, a2);
        case 0x080b40ULL: return fde_sub_080b40(a0, a1, a2);
        case 0x080ba0ULL: return fde_sub_080ba0(a0, a1, a2);
        case 0x080c04ULL: return fde_sub_080c04(a0, a1, a2);
        case 0x080c64ULL: return fde_sub_080c64(a0, a1, a2);
        case 0x080e4cULL: return fde_sub_080e4c(a0, a1, a2);
        case 0x080f3cULL: return fde_sub_080f3c(a0, a1, a2);
        case 0x080f9cULL: return fde_sub_080f9c(a0, a1, a2);
        case 0x080ffcULL: return fde_sub_080ffc(a0, a1, a2);
        case 0x08104cULL: return fde_sub_08104c(a0, a1, a2);
        case 0x081240ULL: return fde_sub_081240(a0, a1, a2);
        case 0x0815b0ULL: return fde_sub_0815b0(a0, a1, a2);
        case 0x081884ULL: return fde_sub_081884(a0, a1, a2);
        case 0x081970ULL: return fde_sub_081970(a0, a1, a2);
        case 0x081a0cULL: return fde_sub_081a0c(a0, a1, a2);
        case 0x081cfcULL: return fde_sub_081cfc(a0, a1, a2);
        case 0x081de4ULL: return fde_sub_081de4(a0, a1, a2);
        case 0x081f00ULL: return fde_sub_081f00(a0, a1, a2);
        case 0x081f0cULL: return fde_sub_081f0c(a0, a1, a2);
        case 0x081f18ULL: return fde_sub_081f18(a0, a1, a2);
        case 0x081f28ULL: return fde_sub_081f28(a0, a1, a2);
        case 0x081f38ULL: return fde_sub_081f38(a0, a1, a2);
        case 0x081f48ULL: return fde_sub_081f48(a0, a1, a2);
        case 0x081f5cULL: return fde_sub_081f5c(a0, a1, a2);
        case 0x081f68ULL: return fde_sub_081f68(a0, a1, a2);
        case 0x081f78ULL: return fde_sub_081f78(a0, a1, a2);
        case 0x081f88ULL: return fde_sub_081f88(a0, a1, a2);
        case 0x081f94ULL: return fde_sub_081f94(a0, a1, a2);
        case 0x081fa0ULL: return fde_sub_081fa0(a0, a1, a2);
        case 0x081fb0ULL: return fde_sub_081fb0(a0, a1, a2);
        case 0x081fc0ULL: return fde_sub_081fc0(a0, a1, a2);
        case 0x081fd0ULL: return fde_sub_081fd0(a0, a1, a2);
        case 0x081fe4ULL: return fde_sub_081fe4(a0, a1, a2);
        case 0x081ff0ULL: return fde_sub_081ff0(a0, a1, a2);
        case 0x082000ULL: return fde_sub_082000(a0, a1, a2);
        case 0x082010ULL: return fde_sub_082010(a0, a1, a2);
        case 0x08201cULL: return fde_sub_08201c(a0, a1, a2);
        case 0x082028ULL: return fde_sub_082028(a0, a1, a2);
        case 0x082038ULL: return fde_sub_082038(a0, a1, a2);
        case 0x082048ULL: return fde_sub_082048(a0, a1, a2);
        case 0x082058ULL: return fde_sub_082058(a0, a1, a2);
        case 0x08209cULL: return fde_sub_08209c(a0, a1, a2);
        case 0x0820a8ULL: return fde_sub_0820a8(a0, a1, a2);
        case 0x0820b8ULL: return fde_sub_0820b8(a0, a1, a2);
        case 0x0820c8ULL: return fde_sub_0820c8(a0, a1, a2);
        case 0x0820d4ULL: return fde_sub_0820d4(a0, a1, a2);
        case 0x0820e0ULL: return fde_sub_0820e0(a0, a1, a2);
        case 0x0820f0ULL: return fde_sub_0820f0(a0, a1, a2);
        case 0x082100ULL: return fde_sub_082100(a0, a1, a2);
        case 0x082110ULL: return fde_sub_082110(a0, a1, a2);
        case 0x082154ULL: return fde_sub_082154(a0, a1, a2);
        case 0x082160ULL: return fde_sub_082160(a0, a1, a2);
        case 0x082170ULL: return fde_sub_082170(a0, a1, a2);
        case 0x082180ULL: return fde_sub_082180(a0, a1, a2);
        case 0x08218cULL: return fde_sub_08218c(a0, a1, a2);
        case 0x082198ULL: return fde_sub_082198(a0, a1, a2);
        case 0x0821a8ULL: return fde_sub_0821a8(a0, a1, a2);
        case 0x0821b8ULL: return fde_sub_0821b8(a0, a1, a2);
        case 0x0821c8ULL: return fde_sub_0821c8(a0, a1, a2);
        case 0x0821d8ULL: return fde_sub_0821d8(a0, a1, a2);
        case 0x0821e4ULL: return fde_sub_0821e4(a0, a1, a2);
        case 0x0821f0ULL: return fde_sub_0821f0(a0, a1, a2);
        case 0x0821fcULL: return fde_sub_0821fc(a0, a1, a2);
        case 0x082208ULL: return fde_sub_082208(a0, a1, a2);
        case 0x082214ULL: return fde_sub_082214(a0, a1, a2);
        case 0x082224ULL: return fde_sub_082224(a0, a1, a2);
        case 0x082234ULL: return fde_sub_082234(a0, a1, a2);
        case 0x082244ULL: return fde_sub_082244(a0, a1, a2);
        case 0x082254ULL: return fde_sub_082254(a0, a1, a2);
        case 0x082260ULL: return fde_sub_082260(a0, a1, a2);
        case 0x08226cULL: return fde_sub_08226c(a0, a1, a2);
        case 0x082278ULL: return fde_sub_082278(a0, a1, a2);
        case 0x082284ULL: return fde_sub_082284(a0, a1, a2);
        case 0x082290ULL: return fde_sub_082290(a0, a1, a2);
        case 0x0822a0ULL: return fde_sub_0822a0(a0, a1, a2);
        case 0x0822b0ULL: return fde_sub_0822b0(a0, a1, a2);
        case 0x0822c0ULL: return fde_sub_0822c0(a0, a1, a2);
        case 0x0822d0ULL: return fde_sub_0822d0(a0, a1, a2);
        case 0x0822dcULL: return fde_sub_0822dc(a0, a1, a2);
        case 0x0822e8ULL: return fde_sub_0822e8(a0, a1, a2);
        case 0x0822f4ULL: return fde_sub_0822f4(a0, a1, a2);
        case 0x082300ULL: return fde_sub_082300(a0, a1, a2);
        case 0x08230cULL: return fde_sub_08230c(a0, a1, a2);
        case 0x08231cULL: return fde_sub_08231c(a0, a1, a2);
        case 0x08232cULL: return fde_sub_08232c(a0, a1, a2);
        case 0x08233cULL: return fde_sub_08233c(a0, a1, a2);
        case 0x08234cULL: return fde_sub_08234c(a0, a1, a2);
        case 0x082358ULL: return fde_sub_082358(a0, a1, a2);
        case 0x082364ULL: return fde_sub_082364(a0, a1, a2);
        case 0x082370ULL: return fde_sub_082370(a0, a1, a2);
        case 0x082788ULL: return fde_sub_082788(a0, a1, a2);
        case 0x082790ULL: return fde_sub_082790(a0, a1, a2);
        case 0x0839dcULL: return fde_sub_0839dc(a0, a1, a2);
        case 0x083a30ULL: return fde_sub_083a30(a0, a1, a2);
        case 0x083d0cULL: return fde_sub_083d0c(a0, a1, a2);
        case 0x083f6cULL: return fde_sub_083f6c(a0, a1, a2);
        case 0x084064ULL: return fde_sub_084064(a0, a1, a2);
        case 0x084498ULL: return fde_sub_084498(a0, a1, a2);
        case 0x0857d0ULL: return fde_sub_0857d0(a0, a1, a2);
        case 0x085ab8ULL: return fde_sub_085ab8(a0, a1, a2);
        case 0x085d18ULL: return fde_sub_085d18(a0, a1, a2);
        case 0x0861bcULL: return fde_sub_0861bc(a0, a1, a2);
        case 0x086268ULL: return fde_sub_086268(a0, a1, a2);
        case 0x0864b4ULL: return fde_sub_0864b4(a0, a1, a2);
        case 0x0869acULL: return fde_sub_0869ac(a0, a1, a2);
        case 0x086d74ULL: return fde_sub_086d74(a0, a1, a2);
        case 0x08722cULL: return fde_sub_08722c(a0, a1, a2);
        case 0x087478ULL: return fde_sub_087478(a0, a1, a2);
        case 0x08795cULL: return fde_sub_08795c(a0, a1, a2);
        case 0x087d28ULL: return fde_sub_087d28(a0, a1, a2);
        case 0x087d34ULL: return fde_sub_087d34(a0, a1, a2);
        case 0x087d44ULL: return fde_sub_087d44(a0, a1, a2);
        case 0x087d4cULL: return fde_sub_087d4c(a0, a1, a2);
        case 0x087d58ULL: return fde_sub_087d58(a0, a1, a2);
        case 0x087d68ULL: return fde_sub_087d68(a0, a1, a2);
        case 0x087d70ULL: return fde_sub_087d70(a0, a1, a2);
        case 0x087d78ULL: return fde_sub_087d78(a0, a1, a2);
        case 0x087da4ULL: return fde_sub_087da4(a0, a1, a2);
        case 0x087dacULL: return fde_sub_087dac(a0, a1, a2);
        case 0x087dd8ULL: return fde_sub_087dd8(a0, a1, a2);
        case 0x087de0ULL: return fde_sub_087de0(a0, a1, a2);
        case 0x087e0cULL: return fde_sub_087e0c(a0, a1, a2);
        case 0x087e14ULL: return fde_sub_087e14(a0, a1, a2);
        case 0x087e40ULL: return fde_sub_087e40(a0, a1, a2);
        case 0x0898c0ULL: return fde_sub_0898c0(a0, a1, a2);
        case 0x089f34ULL: return fde_sub_089f34(a0, a1, a2);
        case 0x089fccULL: return fde_sub_089fcc(a0, a1, a2);
        case 0x08a0f8ULL: return fde_sub_08a0f8(a0, a1, a2);
        case 0x08a224ULL: return fde_sub_08a224(a0, a1, a2);
        case 0x08a350ULL: return fde_sub_08a350(a0, a1, a2);
        case 0x08a47cULL: return fde_sub_08a47c(a0, a1, a2);
        case 0x08a5a8ULL: return fde_sub_08a5a8(a0, a1, a2);
        case 0x08a6d4ULL: return fde_sub_08a6d4(a0, a1, a2);
        case 0x08a800ULL: return fde_sub_08a800(a0, a1, a2);
        case 0x08a92cULL: return fde_sub_08a92c(a0, a1, a2);
        case 0x08aa58ULL: return fde_sub_08aa58(a0, a1, a2);
        case 0x08ab84ULL: return fde_sub_08ab84(a0, a1, a2);
        case 0x08acb0ULL: return fde_sub_08acb0(a0, a1, a2);
        case 0x08ad94ULL: return fde_sub_08ad94(a0, a1, a2);
        case 0x08aec0ULL: return fde_sub_08aec0(a0, a1, a2);
        case 0x08afa4ULL: return fde_sub_08afa4(a0, a1, a2);
        case 0x08b0d0ULL: return fde_sub_08b0d0(a0, a1, a2);
        case 0x08b1b4ULL: return fde_sub_08b1b4(a0, a1, a2);
        case 0x08b2e0ULL: return fde_sub_08b2e0(a0, a1, a2);
        case 0x08b3c4ULL: return fde_sub_08b3c4(a0, a1, a2);
        case 0x08b4f0ULL: return fde_sub_08b4f0(a0, a1, a2);
        case 0x08b61cULL: return fde_sub_08b61c(a0, a1, a2);
        case 0x08b748ULL: return fde_sub_08b748(a0, a1, a2);
        case 0x08b830ULL: return fde_sub_08b830(a0, a1, a2);
        case 0x08b95cULL: return fde_sub_08b95c(a0, a1, a2);
        case 0x08ba44ULL: return fde_sub_08ba44(a0, a1, a2);
        case 0x08bb70ULL: return fde_sub_08bb70(a0, a1, a2);
        case 0x08bc9cULL: return fde_sub_08bc9c(a0, a1, a2);
        case 0x08be3cULL: return fde_sub_08be3c(a0, a1, a2);
        case 0x08c440ULL: return fde_sub_08c440(a0, a1, a2);
        case 0x08dbfcULL: return fde_sub_08dbfc(a0, a1, a2);
        case 0x08de4cULL: return fde_sub_08de4c(a0, a1, a2);
        case 0x08def8ULL: return fde_sub_08def8(a0, a1, a2);
        case 0x08dfa8ULL: return fde_sub_08dfa8(a0, a1, a2);
        case 0x08dfd4ULL: return fde_sub_08dfd4(a0, a1, a2);
        case 0x08e008ULL: return fde_sub_08e008(a0, a1, a2);
        case 0x08e048ULL: return fde_sub_08e048(a0, a1, a2);
        case 0x08e0f4ULL: return fde_sub_08e0f4(a0, a1, a2);
        case 0x08e1ecULL: return fde_sub_08e1ec(a0, a1, a2);
        case 0x08e220ULL: return fde_sub_08e220(a0, a1, a2);
        case 0x08e234ULL: return fde_sub_08e234(a0, a1, a2);
        case 0x08e240ULL: return fde_sub_08e240(a0, a1, a2);
        case 0x08e288ULL: return fde_sub_08e288(a0, a1, a2);
        case 0x08e3d4ULL: return fde_sub_08e3d4(a0, a1, a2);
        case 0x08e438ULL: return fde_sub_08e438(a0, a1, a2);
        case 0x08e59cULL: return fde_sub_08e59c(a0, a1, a2);
        case 0x08e60cULL: return fde_sub_08e60c(a0, a1, a2);
        case 0x08e67cULL: return fde_sub_08e67c(a0, a1, a2);
        case 0x08e690ULL: return fde_sub_08e690(a0, a1, a2);
        case 0x08e70cULL: return fde_sub_08e70c(a0, a1, a2);
        case 0x08e888ULL: return fde_sub_08e888(a0, a1, a2);
        case 0x08e94cULL: return fde_sub_08e94c(a0, a1, a2);
        case 0x08e9e0ULL: return fde_sub_08e9e0(a0, a1, a2);
        case 0x08ea9cULL: return fde_sub_08ea9c(a0, a1, a2);
        case 0x08ebbcULL: return fde_sub_08ebbc(a0, a1, a2);
        case 0x08ebe8ULL: return fde_sub_08ebe8(a0, a1, a2);
        case 0x08ebf8ULL: return fde_sub_08ebf8(a0, a1, a2);
        case 0x08ec1cULL: return fde_sub_08ec1c(a0, a1, a2);
        case 0x08ed90ULL: return fde_sub_08ed90(a0, a1, a2);
        case 0x08ede4ULL: return fde_sub_08ede4(a0, a1, a2);
        case 0x08eec0ULL: return fde_sub_08eec0(a0, a1, a2);
        case 0x08ef14ULL: return fde_sub_08ef14(a0, a1, a2);
        case 0x08ef70ULL: return fde_sub_08ef70(a0, a1, a2);
        case 0x08f158ULL: return fde_sub_08f158(a0, a1, a2);
        case 0x08f35cULL: return fde_sub_08f35c(a0, a1, a2);
        case 0x08f4d0ULL: return fde_sub_08f4d0(a0, a1, a2);
        case 0x08f5acULL: return fde_sub_08f5ac(a0, a1, a2);
        case 0x08f600ULL: return fde_sub_08f600(a0, a1, a2);
        case 0x08f65cULL: return fde_sub_08f65c(a0, a1, a2);
        case 0x08f864ULL: return fde_sub_08f864(a0, a1, a2);
        case 0x08fa8cULL: return fde_sub_08fa8c(a0, a1, a2);
        case 0x08fab8ULL: return fde_sub_08fab8(a0, a1, a2);
        case 0x08fae4ULL: return fde_sub_08fae4(a0, a1, a2);
        case 0x08faf4ULL: return fde_sub_08faf4(a0, a1, a2);
        case 0x08fb40ULL: return fde_sub_08fb40(a0, a1, a2);
        case 0x08fb8cULL: return fde_sub_08fb8c(a0, a1, a2);
        case 0x08fbd0ULL: return fde_sub_08fbd0(a0, a1, a2);
        case 0x08fc80ULL: return fde_sub_08fc80(a0, a1, a2);
        case 0x08fd60ULL: return fde_sub_08fd60(a0, a1, a2);
        case 0x08fe10ULL: return fde_sub_08fe10(a0, a1, a2);
        case 0x08fef0ULL: return fde_sub_08fef0(a0, a1, a2);
        case 0x08fefcULL: return fde_sub_08fefc(a0, a1, a2);
        case 0x08ff24ULL: return fde_sub_08ff24(a0, a1, a2);
        case 0x08ff34ULL: return fde_sub_08ff34(a0, a1, a2);
        case 0x090000ULL: return fde_sub_090000(a0, a1, a2);
        case 0x09003cULL: return fde_sub_09003c(a0, a1, a2);
        case 0x090088ULL: return fde_sub_090088(a0, a1, a2);
        default: return 0ULL;
    }
}

} // namespace applovin
