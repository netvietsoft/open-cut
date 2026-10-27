// ============================================================================
// File: cxx_shared_fde_shard_3.cpp
// Target 111 / 169: libc++_shared.so (919,888 bytes)
// EN: Clean-room C++17 AArch64 FDE Shard 3/5 covering FDEs [782..1172]
//     (PC range 0x074f74 .. 0x090b5c).
// VI: Phân mảnh FDE AArch64 C++17 3/5 bao phủ FDE [782..1172]
//     (Dải địa chỉ PC 0x074f74 .. 0x090b5c).
// ============================================================================
#include "cxx_shared_core.h"

namespace ndk_libcxx_recon {

// FDE #0782 | PC: 0x074f74..0x075390 (1052 B) | Symbol: _ZNSt6__ndk117moneypunct_bynameIcLb0EE4initEPKc
// EN: AArch64 prologue [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]]
uint64_t fde_sub_074f74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F9ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x041CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074F74ULL;
}

// FDE #0783 | PC: 0x075390..0x0757a4 (1044 B) | Symbol: sub_075390
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_075390(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0414ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075390ULL;
}

// FDE #0784 | PC: 0x0757a4..0x075bc0 (1052 B) | Symbol: _ZNSt6__ndk117moneypunct_bynameIcLb1EE4initEPKc
// EN: AArch64 prologue [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]]
uint64_t fde_sub_0757a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F9ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x041CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0757A4ULL;
}

// FDE #0785 | PC: 0x075bc0..0x0763b8 (2040 B) | Symbol: _ZNSt6__ndk117moneypunct_bynameIwLb0EE4initEPKc
// EN: AArch64 prologue [str x28, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x28, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_075bc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xF81A0FFCULL;
    const uint64_t kPcRange = 0x07F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075BC0ULL;
}

// FDE #0786 | PC: 0x0763b8..0x0767dc (1060 B) | Symbol: sub_0763b8
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0763b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0424ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0763B8ULL;
}

// FDE #0787 | PC: 0x0767dc..0x076fd4 (2040 B) | Symbol: _ZNSt6__ndk117moneypunct_bynameIwLb1EE4initEPKc
// EN: AArch64 prologue [str x28, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x28, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0767dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xF81A0FFCULL;
    const uint64_t kPcRange = 0x07F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0767DCULL;
}

// FDE #0788 | PC: 0x076fd4..0x077098 (196 B) | Symbol: _ZNSt6__ndk17codecvtIwc9mbstate_tED1Ev
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_076fd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x076FD4ULL;
}

// FDE #0789 | PC: 0x077098..0x07709c (4 B) | Symbol: _ZNSt6__ndk116__narrow_to_utf8ILm32EED1Ev
// EN: AArch64 prologue [b #0x47f80] | VI: Khởi đầu hàm AArch64 [b #0x47f80]
uint64_t fde_sub_077098(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0x17FF43BAULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077098ULL;
}

// FDE #0790 | PC: 0x07709c..0x0770c0 (36 B) | Symbol: sub_07709c
// EN: AArch64 prologue [ldr x8, [x0]; ldr x8, [x8]; ldp x1, x9, [x8, #8]; ldr x10, [x8]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x8, [x8]; ldp x1, x9, [x8, #8]; ldr x10, [x8]]
uint64_t fde_sub_07709c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400108ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07709CULL;
}

// FDE #0791 | PC: 0x0770c0..0x0770c4 (4 B) | Symbol: _ZNSt6__ndk17collateIcED1Ev
// EN: AArch64 prologue [b #0x47f80] | VI: Khởi đầu hàm AArch64 [b #0x47f80]
uint64_t fde_sub_0770c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0x17FF43B0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0770C0ULL;
}

// FDE #0792 | PC: 0x0770c4..0x0770e8 (36 B) | Symbol: _ZNSt6__ndk17collateIcED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0770c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0770C4ULL;
}

// FDE #0793 | PC: 0x0770e8..0x07713c (84 B) | Symbol: _ZNKSt6__ndk17collateIcE10do_compareEPKcS3_S3_S3_
// EN: AArch64 prologue [cmp x3, x4; b.eq #0x77120; cmp x2, x1; b.eq #0x7712c] | VI: Khởi đầu hàm AArch64 [cmp x3, x4; b.eq #0x77120; cmp x2, x1; b.eq #0x7712c]
uint64_t fde_sub_0770e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x540001A0ULL) << 32) | 0xEB04007FULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0770E8ULL;
}

// FDE #0794 | PC: 0x07713c..0x07722c (240 B) | Symbol: _ZNKSt6__ndk17collateIcE12do_transformEPKcS3_
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_07713c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07713CULL;
}

// FDE #0795 | PC: 0x07722c..0x077260 (52 B) | Symbol: _ZNKSt6__ndk17collateIcE7do_hashEPKcS3_
// EN: AArch64 prologue [cmp x1, x2; b.eq #0x77258; mov x0, xzr; ldrb w8, [x1], #1] | VI: Khởi đầu hàm AArch64 [cmp x1, x2; b.eq #0x77258; mov x0, xzr; ldrb w8, [x1], #1]
uint64_t fde_sub_07722c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000140ULL) << 32) | 0xEB02003FULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07722CULL;
}

// FDE #0796 | PC: 0x077260..0x077264 (4 B) | Symbol: _ZNSt6__ndk17collateIwED2Ev
// EN: AArch64 prologue [b #0x47f80] | VI: Khởi đầu hàm AArch64 [b #0x47f80]
uint64_t fde_sub_077260(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0x17FF4348ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077260ULL;
}

// FDE #0797 | PC: 0x077264..0x077288 (36 B) | Symbol: _ZNSt6__ndk17collateIwED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_077264(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077264ULL;
}

// FDE #0798 | PC: 0x077288..0x0772dc (84 B) | Symbol: _ZNKSt6__ndk17collateIwE10do_compareEPKwS3_S3_S3_
// EN: AArch64 prologue [cmp x3, x4; b.eq #0x772c0; cmp x2, x1; b.eq #0x772cc] | VI: Khởi đầu hàm AArch64 [cmp x3, x4; b.eq #0x772c0; cmp x2, x1; b.eq #0x772cc]
uint64_t fde_sub_077288(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x540001A0ULL) << 32) | 0xEB04007FULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077288ULL;
}

// FDE #0799 | PC: 0x0772dc..0x0773f8 (284 B) | Symbol: _ZNKSt6__ndk17collateIwE12do_transformEPKwS3_
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0772dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0772DCULL;
}

// FDE #0800 | PC: 0x0773f8..0x07742c (52 B) | Symbol: _ZNKSt6__ndk17collateIwE7do_hashEPKwS3_
// EN: AArch64 prologue [cmp x1, x2; b.eq #0x77424; mov x0, xzr; ldr w8, [x1], #4] | VI: Khởi đầu hàm AArch64 [cmp x1, x2; b.eq #0x77424; mov x0, xzr; ldr w8, [x1], #4]
uint64_t fde_sub_0773f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000140ULL) << 32) | 0xEB02003FULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0773F8ULL;
}

// FDE #0801 | PC: 0x07742c..0x0776f4 (712 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_getES4_S4_RNS_8ios_baseERjRb
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]; stp x22, x21, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]; stp x22, x21, [sp, #0x80]]
uint64_t fde_sub_07742c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90667FAULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x02C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07742CULL;
}

// FDE #0802 | PC: 0x0776f4..0x077ba0 (1196 B) | Symbol: sub_0776f4
// EN: AArch64 prologue [sub sp, sp, #0x110; stp x28, x27, [sp, #0xb0]; stp x26, x25, [sp, #0xc0]; stp x24, x23, [sp, #0xd0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; stp x28, x27, [sp, #0xb0]; stp x26, x25, [sp, #0xc0]; stp x24, x23, [sp, #0xd0]]
uint64_t fde_sub_0776f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90B6FFCULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x04ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0776F4ULL;
}

// FDE #0803 | PC: 0x077ba0..0x077ba4 (4 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_getES4_S4_RNS_8ios_baseERjRl
// EN: AArch64 prologue [b #0x473b0] | VI: Khởi đầu hàm AArch64 [b #0x473b0]
uint64_t fde_sub_077ba0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10643FFULL) << 32) | 0x17FF3E04ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077BA0ULL;
}

// FDE #0804 | PC: 0x077ba4..0x077f48 (932 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE15__do_get_signedIlEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [sub sp, sp, #0x190; stp x28, x27, [sp, #0x130]; stp x26, x25, [sp, #0x140]; stp x24, x23, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x190; stp x28, x27, [sp, #0x130]; stp x26, x25, [sp, #0x140]; stp x24, x23, [sp, #0x150]]
uint64_t fde_sub_077ba4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9136FFCULL) << 32) | 0xD10643FFULL;
    const uint64_t kPcRange = 0x03A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077BA4ULL;
}

// FDE #0805 | PC: 0x077f48..0x077f4c (4 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_getES4_S4_RNS_8ios_baseERjRx
// EN: AArch64 prologue [b #0x47fe0] | VI: Khởi đầu hàm AArch64 [b #0x47fe0]
uint64_t fde_sub_077f48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10643FFULL) << 32) | 0x17FF4026ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077F48ULL;
}

// FDE #0806 | PC: 0x077f4c..0x0782f0 (932 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE15__do_get_signedIxEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [sub sp, sp, #0x190; stp x28, x27, [sp, #0x130]; stp x26, x25, [sp, #0x140]; stp x24, x23, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x190; stp x28, x27, [sp, #0x130]; stp x26, x25, [sp, #0x140]; stp x24, x23, [sp, #0x150]]
uint64_t fde_sub_077f4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9136FFCULL) << 32) | 0xD10643FFULL;
    const uint64_t kPcRange = 0x03A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077F4CULL;
}

// FDE #0807 | PC: 0x0782f0..0x0782f4 (4 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_getES4_S4_RNS_8ios_baseERjRt
// EN: AArch64 prologue [b #0x47080] | VI: Khởi đầu hàm AArch64 [b #0x47080]
uint64_t fde_sub_0782f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10643FFULL) << 32) | 0x17FF3B64ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0782F0ULL;
}

// FDE #0808 | PC: 0x0782f4..0x078698 (932 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE17__do_get_unsignedItEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [sub sp, sp, #0x190; stp x28, x27, [sp, #0x130]; stp x26, x25, [sp, #0x140]; stp x24, x23, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x190; stp x28, x27, [sp, #0x130]; stp x26, x25, [sp, #0x140]; stp x24, x23, [sp, #0x150]]
uint64_t fde_sub_0782f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9136FFCULL) << 32) | 0xD10643FFULL;
    const uint64_t kPcRange = 0x03A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0782F4ULL;
}

// FDE #0809 | PC: 0x078698..0x07869c (4 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_getES4_S4_RNS_8ios_baseERjS8_
// EN: AArch64 prologue [b #0x47b00] | VI: Khởi đầu hàm AArch64 [b #0x47b00]
uint64_t fde_sub_078698(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10643FFULL) << 32) | 0x17FF3D1AULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078698ULL;
}

// FDE #0810 | PC: 0x07869c..0x078a40 (932 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE17__do_get_unsignedIjEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [sub sp, sp, #0x190; stp x28, x27, [sp, #0x130]; stp x26, x25, [sp, #0x140]; stp x24, x23, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x190; stp x28, x27, [sp, #0x130]; stp x26, x25, [sp, #0x140]; stp x24, x23, [sp, #0x150]]
uint64_t fde_sub_07869c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9136FFCULL) << 32) | 0xD10643FFULL;
    const uint64_t kPcRange = 0x03A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07869CULL;
}

// FDE #0811 | PC: 0x078a40..0x078a44 (4 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_getES4_S4_RNS_8ios_baseERjRm
// EN: AArch64 prologue [b #0x47d50] | VI: Khởi đầu hàm AArch64 [b #0x47d50]
uint64_t fde_sub_078a40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10643FFULL) << 32) | 0x17FF3CC4ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078A40ULL;
}

// FDE #0812 | PC: 0x078a44..0x078de8 (932 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE17__do_get_unsignedImEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [sub sp, sp, #0x190; stp x28, x27, [sp, #0x130]; stp x26, x25, [sp, #0x140]; stp x24, x23, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x190; stp x28, x27, [sp, #0x130]; stp x26, x25, [sp, #0x140]; stp x24, x23, [sp, #0x150]]
uint64_t fde_sub_078a44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9136FFCULL) << 32) | 0xD10643FFULL;
    const uint64_t kPcRange = 0x03A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078A44ULL;
}

// FDE #0813 | PC: 0x078de8..0x078dec (4 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_getES4_S4_RNS_8ios_baseERjRy
// EN: AArch64 prologue [b #0x47b60] | VI: Khởi đầu hàm AArch64 [b #0x47b60]
uint64_t fde_sub_078de8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10643FFULL) << 32) | 0x17FF3B5EULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078DE8ULL;
}

// FDE #0814 | PC: 0x078dec..0x079190 (932 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE17__do_get_unsignedIyEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [sub sp, sp, #0x190; stp x28, x27, [sp, #0x130]; stp x26, x25, [sp, #0x140]; stp x24, x23, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x190; stp x28, x27, [sp, #0x130]; stp x26, x25, [sp, #0x140]; stp x24, x23, [sp, #0x150]]
uint64_t fde_sub_078dec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9136FFCULL) << 32) | 0xD10643FFULL;
    const uint64_t kPcRange = 0x03A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078DECULL;
}

// FDE #0815 | PC: 0x079190..0x079194 (4 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_getES4_S4_RNS_8ios_baseERjRf
// EN: AArch64 prologue [b #0x473d0] | VI: Khởi đầu hàm AArch64 [b #0x473d0]
uint64_t fde_sub_079190(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10703FFULL) << 32) | 0x17FF3890ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079190ULL;
}

// FDE #0816 | PC: 0x079194..0x079520 (908 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE23__do_get_floating_pointIfEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [sub sp, sp, #0x1c0; stp x28, x27, [sp, #0x160]; stp x26, x25, [sp, #0x170]; stp x24, x23, [sp, #0x180]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1c0; stp x28, x27, [sp, #0x160]; stp x26, x25, [sp, #0x170]; stp x24, x23, [sp, #0x180]]
uint64_t fde_sub_079194(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9166FFCULL) << 32) | 0xD10703FFULL;
    const uint64_t kPcRange = 0x038CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079194ULL;
}

// FDE #0817 | PC: 0x079520..0x079524 (4 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_getES4_S4_RNS_8ios_baseERjRd
// EN: AArch64 prologue [b #0x48640] | VI: Khởi đầu hàm AArch64 [b #0x48640]
uint64_t fde_sub_079520(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10703FFULL) << 32) | 0x17FF3C48ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079520ULL;
}

// FDE #0818 | PC: 0x079524..0x0798b0 (908 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE23__do_get_floating_pointIdEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [sub sp, sp, #0x1c0; stp x28, x27, [sp, #0x160]; stp x26, x25, [sp, #0x170]; stp x24, x23, [sp, #0x180]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1c0; stp x28, x27, [sp, #0x160]; stp x26, x25, [sp, #0x170]; stp x24, x23, [sp, #0x180]]
uint64_t fde_sub_079524(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9166FFCULL) << 32) | 0xD10703FFULL;
    const uint64_t kPcRange = 0x038CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079524ULL;
}

// FDE #0819 | PC: 0x0798b0..0x0798b4 (4 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_getES4_S4_RNS_8ios_baseERjRe
// EN: AArch64 prologue [b #0x486e0] | VI: Khởi đầu hàm AArch64 [b #0x486e0]
uint64_t fde_sub_0798b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10703FFULL) << 32) | 0x17FF3B8CULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0798B0ULL;
}

// FDE #0820 | PC: 0x0798b4..0x079c40 (908 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE23__do_get_floating_pointIeEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [sub sp, sp, #0x1c0; stp x28, x27, [sp, #0x160]; stp x26, x25, [sp, #0x170]; stp x24, x23, [sp, #0x180]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1c0; stp x28, x27, [sp, #0x160]; stp x26, x25, [sp, #0x170]; stp x24, x23, [sp, #0x180]]
uint64_t fde_sub_0798b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9166FFCULL) << 32) | 0xD10703FFULL;
    const uint64_t kPcRange = 0x038CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0798B4ULL;
}

// FDE #0821 | PC: 0x079c40..0x07a0b8 (1144 B) | Symbol: _ZNKSt6__ndk17num_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_getES4_S4_RNS_8ios_baseERjRPv
// EN: AArch64 prologue [sub sp, sp, #0x190; stp x28, x27, [sp, #0x130]; stp x26, x25, [sp, #0x140]; stp x24, x23, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x190; stp x28, x27, [sp, #0x130]; stp x26, x25, [sp, #0x140]; stp x24, x23, [sp, #0x150]]
uint64_t fde_sub_079c40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9136FFCULL) << 32) | 0xD10643FFULL;
    const uint64_t kPcRange = 0x0478ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079C40ULL;
}

// FDE #0822 | PC: 0x07a0b8..0x07a424 (876 B) | Symbol: _ZNSt6__ndk19__num_getIcE17__stage2_int_loopEciPcRS2_RjcRKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPjRSD_S2_
// EN: AArch64 prologue [ldr x9, [x3]; ldr x8, [sp, #8]; cmp x9, x2; b.eq #0x7a11c] | VI: Khởi đầu hàm AArch64 [ldr x9, [x3]; ldr x8, [sp, #8]; cmp x9, x2; b.eq #0x7a11c]
uint64_t fde_sub_07a0b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E8ULL) << 32) | 0xF9400069ULL;
    const uint64_t kPcRange = 0x036CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A0B8ULL;
}

// FDE #0823 | PC: 0x07a424..0x07a4fc (216 B) | Symbol: _ZNSt6__ndk117__libcpp_sscanf_lEPKcP10__locale_tS1_z
// EN: AArch64 prologue [sub sp, sp, #0x140; stp x28, x23, [sp, #0x100]; stp x22, x21, [sp, #0x110]; stp x20, x19, [sp, #0x120]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x140; stp x28, x23, [sp, #0x100]; stp x22, x21, [sp, #0x110]; stp x20, x19, [sp, #0x120]]
uint64_t fde_sub_07a424(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9105FFCULL) << 32) | 0xD10503FFULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A424ULL;
}

// FDE #0824 | PC: 0x07a4fc..0x07a7c4 (712 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_getES4_S4_RNS_8ios_baseERjRb
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]; stp x22, x21, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]; stp x22, x21, [sp, #0x80]]
uint64_t fde_sub_07a4fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90667FAULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x02C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A4FCULL;
}

// FDE #0825 | PC: 0x07a7c4..0x07ac84 (1216 B) | Symbol: sub_07a7c4
// EN: AArch64 prologue [sub sp, sp, #0x100; stp x28, x27, [sp, #0xa0]; stp x26, x25, [sp, #0xb0]; stp x24, x23, [sp, #0xc0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x100; stp x28, x27, [sp, #0xa0]; stp x26, x25, [sp, #0xb0]; stp x24, x23, [sp, #0xc0]]
uint64_t fde_sub_07a7c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90A6FFCULL) << 32) | 0xD10403FFULL;
    const uint64_t kPcRange = 0x04C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A7C4ULL;
}

// FDE #0826 | PC: 0x07ac84..0x07ac88 (4 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_getES4_S4_RNS_8ios_baseERjRl
// EN: AArch64 prologue [b #0x48240] | VI: Khởi đầu hàm AArch64 [b #0x48240]
uint64_t fde_sub_07ac84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10783FFULL) << 32) | 0x17FF356FULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07AC84ULL;
}

// FDE #0827 | PC: 0x07ac88..0x07b06c (996 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE15__do_get_signedIlEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [sub sp, sp, #0x1e0; stp x28, x27, [sp, #0x180]; stp x26, x25, [sp, #0x190]; stp x24, x23, [sp, #0x1a0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1e0; stp x28, x27, [sp, #0x180]; stp x26, x25, [sp, #0x190]; stp x24, x23, [sp, #0x1a0]]
uint64_t fde_sub_07ac88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9186FFCULL) << 32) | 0xD10783FFULL;
    const uint64_t kPcRange = 0x03E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07AC88ULL;
}

// FDE #0828 | PC: 0x07b06c..0x07b070 (4 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_getES4_S4_RNS_8ios_baseERjRx
// EN: AArch64 prologue [b #0x47a70] | VI: Khởi đầu hàm AArch64 [b #0x47a70]
uint64_t fde_sub_07b06c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10783FFULL) << 32) | 0x17FF3281ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B06CULL;
}

// FDE #0829 | PC: 0x07b070..0x07b454 (996 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE15__do_get_signedIxEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [sub sp, sp, #0x1e0; stp x28, x27, [sp, #0x180]; stp x26, x25, [sp, #0x190]; stp x24, x23, [sp, #0x1a0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1e0; stp x28, x27, [sp, #0x180]; stp x26, x25, [sp, #0x190]; stp x24, x23, [sp, #0x1a0]]
uint64_t fde_sub_07b070(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9186FFCULL) << 32) | 0xD10783FFULL;
    const uint64_t kPcRange = 0x03E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B070ULL;
}

// FDE #0830 | PC: 0x07b454..0x07b458 (4 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_getES4_S4_RNS_8ios_baseERjRt
// EN: AArch64 prologue [b #0x47c10] | VI: Khởi đầu hàm AArch64 [b #0x47c10]
uint64_t fde_sub_07b454(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10783FFULL) << 32) | 0x17FF31EFULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B454ULL;
}

// FDE #0831 | PC: 0x07b458..0x07b83c (996 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE17__do_get_unsignedItEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [sub sp, sp, #0x1e0; stp x28, x27, [sp, #0x180]; stp x26, x25, [sp, #0x190]; stp x24, x23, [sp, #0x1a0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1e0; stp x28, x27, [sp, #0x180]; stp x26, x25, [sp, #0x190]; stp x24, x23, [sp, #0x1a0]]
uint64_t fde_sub_07b458(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9186FFCULL) << 32) | 0xD10783FFULL;
    const uint64_t kPcRange = 0x03E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B458ULL;
}

// FDE #0832 | PC: 0x07b83c..0x07b840 (4 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_getES4_S4_RNS_8ios_baseERjS8_
// EN: AArch64 prologue [b #0x48420] | VI: Khởi đầu hàm AArch64 [b #0x48420]
uint64_t fde_sub_07b83c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10783FFULL) << 32) | 0x17FF32F9ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B83CULL;
}

// FDE #0833 | PC: 0x07b840..0x07bc24 (996 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE17__do_get_unsignedIjEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [sub sp, sp, #0x1e0; stp x28, x27, [sp, #0x180]; stp x26, x25, [sp, #0x190]; stp x24, x23, [sp, #0x1a0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1e0; stp x28, x27, [sp, #0x180]; stp x26, x25, [sp, #0x190]; stp x24, x23, [sp, #0x1a0]]
uint64_t fde_sub_07b840(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9186FFCULL) << 32) | 0xD10783FFULL;
    const uint64_t kPcRange = 0x03E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B840ULL;
}

// FDE #0834 | PC: 0x07bc24..0x07bc28 (4 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_getES4_S4_RNS_8ios_baseERjRm
// EN: AArch64 prologue [b #0x48280] | VI: Khởi đầu hàm AArch64 [b #0x48280]
uint64_t fde_sub_07bc24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10783FFULL) << 32) | 0x17FF3197ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07BC24ULL;
}

// FDE #0835 | PC: 0x07bc28..0x07c00c (996 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE17__do_get_unsignedImEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [sub sp, sp, #0x1e0; stp x28, x27, [sp, #0x180]; stp x26, x25, [sp, #0x190]; stp x24, x23, [sp, #0x1a0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1e0; stp x28, x27, [sp, #0x180]; stp x26, x25, [sp, #0x190]; stp x24, x23, [sp, #0x1a0]]
uint64_t fde_sub_07bc28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9186FFCULL) << 32) | 0xD10783FFULL;
    const uint64_t kPcRange = 0x03E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07BC28ULL;
}

// FDE #0836 | PC: 0x07c00c..0x07c010 (4 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_getES4_S4_RNS_8ios_baseERjRy
// EN: AArch64 prologue [b #0x483b0] | VI: Khởi đầu hàm AArch64 [b #0x483b0]
uint64_t fde_sub_07c00c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10783FFULL) << 32) | 0x17FF30E9ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C00CULL;
}

// FDE #0837 | PC: 0x07c010..0x07c3f4 (996 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE17__do_get_unsignedIyEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [sub sp, sp, #0x1e0; stp x28, x27, [sp, #0x180]; stp x26, x25, [sp, #0x190]; stp x24, x23, [sp, #0x1a0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1e0; stp x28, x27, [sp, #0x180]; stp x26, x25, [sp, #0x190]; stp x24, x23, [sp, #0x1a0]]
uint64_t fde_sub_07c010(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9186FFCULL) << 32) | 0xD10783FFULL;
    const uint64_t kPcRange = 0x03E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C010ULL;
}

// FDE #0838 | PC: 0x07c3f4..0x07c3f8 (4 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_getES4_S4_RNS_8ios_baseERjRf
// EN: AArch64 prologue [b #0x480c0] | VI: Khởi đầu hàm AArch64 [b #0x480c0]
uint64_t fde_sub_07c3f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x17FF2F33ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C3F4ULL;
}

// FDE #0839 | PC: 0x07c3f8..0x07c7c4 (972 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE23__do_get_floating_pointIfEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_07c3f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x03CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C3F8ULL;
}

// FDE #0840 | PC: 0x07c7c4..0x07c7c8 (4 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_getES4_S4_RNS_8ios_baseERjRd
// EN: AArch64 prologue [b #0x47890] | VI: Khởi đầu hàm AArch64 [b #0x47890]
uint64_t fde_sub_07c7c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x17FF2C33ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C7C4ULL;
}

// FDE #0841 | PC: 0x07c7c8..0x07cb94 (972 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE23__do_get_floating_pointIdEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_07c7c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x03CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C7C8ULL;
}

// FDE #0842 | PC: 0x07cb94..0x07cb98 (4 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_getES4_S4_RNS_8ios_baseERjRe
// EN: AArch64 prologue [b #0x47fa0] | VI: Khởi đầu hàm AArch64 [b #0x47fa0]
uint64_t fde_sub_07cb94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x17FF2D03ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07CB94ULL;
}

// FDE #0843 | PC: 0x07cb98..0x07cf64 (972 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE23__do_get_floating_pointIeEES4_S4_S4_RNS_8ios_baseERjRT_
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_07cb98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x03CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07CB98ULL;
}

// FDE #0844 | PC: 0x07cf64..0x07d41c (1208 B) | Symbol: _ZNKSt6__ndk17num_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_getES4_S4_RNS_8ios_baseERjRPv
// EN: AArch64 prologue [sub sp, sp, #0x1d0; stp x28, x27, [sp, #0x170]; stp x26, x25, [sp, #0x180]; stp x24, x23, [sp, #0x190]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1d0; stp x28, x27, [sp, #0x170]; stp x26, x25, [sp, #0x180]; stp x24, x23, [sp, #0x190]]
uint64_t fde_sub_07cf64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9176FFCULL) << 32) | 0xD10743FFULL;
    const uint64_t kPcRange = 0x04B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07CF64ULL;
}

// FDE #0845 | PC: 0x07d41c..0x07d788 (876 B) | Symbol: _ZNSt6__ndk19__num_getIwE17__stage2_int_loopEwiPcRS2_RjwRKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPjRSD_Pw
// EN: AArch64 prologue [ldr x9, [x3]; ldr x8, [sp, #8]; cmp x9, x2; b.eq #0x7d47c] | VI: Khởi đầu hàm AArch64 [ldr x9, [x3]; ldr x8, [sp, #8]; cmp x9, x2; b.eq #0x7d47c]
uint64_t fde_sub_07d41c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E8ULL) << 32) | 0xF9400069ULL;
    const uint64_t kPcRange = 0x036CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07D41CULL;
}

// FDE #0846 | PC: 0x07d788..0x07d958 (464 B) | Symbol: _ZNSt6__ndk19__num_getIcE19__stage2_float_prepERNS_8ios_baseEPcRcS5_
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]]
uint64_t fde_sub_07d788(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90467FAULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x01D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07D788ULL;
}

// FDE #0847 | PC: 0x07d958..0x07ddc0 (1128 B) | Symbol: _ZNSt6__ndk19__num_getIcE19__stage2_float_loopEcRbRcPcRS4_ccRKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPjRSE_RjS4_
// EN: AArch64 prologue [ldp x9, x8, [sp, #8]; ldr x10, [sp]; and w11, w0, #0xff; cmp w11, w5, uxtb] | VI: Khởi đầu hàm AArch64 [ldp x9, x8, [sp, #8]; ldr x10, [sp]; and w11, w0, #0xff; cmp w11, w5, uxtb]
uint64_t fde_sub_07d958(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94003EAULL) << 32) | 0xA940A3E9ULL;
    const uint64_t kPcRange = 0x0468ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07D958ULL;
}

// FDE #0848 | PC: 0x07ddc0..0x07df78 (440 B) | Symbol: _ZNSt6__ndk19__num_getIcE17__stage2_int_prepERNS_8ios_baseEPcRc
// EN: AArch64 prologue [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]]
uint64_t fde_sub_07ddc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F9ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x01B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07DDC0ULL;
}

// FDE #0849 | PC: 0x07df78..0x07e148 (464 B) | Symbol: _ZNSt6__ndk19__num_getIwE19__stage2_float_prepERNS_8ios_baseEPwRwS5_
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]]
uint64_t fde_sub_07df78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90467FAULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x01D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07DF78ULL;
}

// FDE #0850 | PC: 0x07e148..0x07e5ac (1124 B) | Symbol: _ZNSt6__ndk19__num_getIwE19__stage2_float_loopEwRbRcPcRS4_wwRKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPjRSE_RjPw
// EN: AArch64 prologue [ldp x9, x8, [sp, #8]; ldr x10, [sp]; cmp w0, w5; b.ne #0x7e1b8] | VI: Khởi đầu hàm AArch64 [ldp x9, x8, [sp, #8]; ldr x10, [sp]; cmp w0, w5; b.ne #0x7e1b8]
uint64_t fde_sub_07e148(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94003EAULL) << 32) | 0xA940A3E9ULL;
    const uint64_t kPcRange = 0x0464ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E148ULL;
}

// FDE #0851 | PC: 0x07e5ac..0x07e764 (440 B) | Symbol: _ZNSt6__ndk19__num_getIwE17__stage2_int_prepERNS_8ios_baseEPwRw
// EN: AArch64 prologue [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]]
uint64_t fde_sub_07e5ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F9ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x01B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E5ACULL;
}

// FDE #0852 | PC: 0x07e764..0x07e974 (528 B) | Symbol: _ZNKSt6__ndk17num_putIcNS_19ostreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_putES4_RNS_8ios_baseEcb
// EN: AArch64 prologue [sub sp, sp, #0x80; str x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]; stp x20, x19, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]; stp x20, x19, [sp, #0x60]]
uint64_t fde_sub_07e764(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F7ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0210ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E764ULL;
}

// FDE #0853 | PC: 0x07e974..0x07ebe0 (620 B) | Symbol: _ZNKSt6__ndk17num_putIcNS_19ostreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_putES4_RNS_8ios_baseEcl
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_07e974(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x026CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E974ULL;
}

// FDE #0854 | PC: 0x07ebe0..0x07ecdc (252 B) | Symbol: _ZNSt6__ndk119__libcpp_snprintf_lEPcmP10__locale_tPKcz
// EN: AArch64 prologue [sub sp, sp, #0x130; stp x28, x23, [sp, #0xf0]; stp x22, x21, [sp, #0x100]; stp x20, x19, [sp, #0x110]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x130; stp x28, x23, [sp, #0xf0]; stp x22, x21, [sp, #0x100]; stp x20, x19, [sp, #0x110]]
uint64_t fde_sub_07ebe0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90F5FFCULL) << 32) | 0xD104C3FFULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07EBE0ULL;
}

// FDE #0855 | PC: 0x07ecdc..0x07f0f0 (1044 B) | Symbol: _ZNSt6__ndk19__num_putIcE21__widen_and_group_intEPcS2_S2_S2_RS2_S3_RKNS_6localeE
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]]
uint64_t fde_sub_07ecdc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9056FFCULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x0414ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07ECDCULL;
}

// FDE #0856 | PC: 0x07f0f0..0x07f2a0 (432 B) | Symbol: sub_07f0f0
// EN: AArch64 prologue [sub sp, sp, #0x80; str x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_07f0f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013FBULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x01B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F0F0ULL;
}

// FDE #0857 | PC: 0x07f2a0..0x07f508 (616 B) | Symbol: _ZNKSt6__ndk17num_putIcNS_19ostreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_putES4_RNS_8ios_baseEcx
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_07f2a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x0268ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F2A0ULL;
}

// FDE #0858 | PC: 0x07f508..0x07f78c (644 B) | Symbol: _ZNKSt6__ndk17num_putIcNS_19ostreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_putES4_RNS_8ios_baseEcm
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_07f508(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0284ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F508ULL;
}

// FDE #0859 | PC: 0x07f78c..0x07fa0c (640 B) | Symbol: _ZNKSt6__ndk17num_putIcNS_19ostreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_putES4_RNS_8ios_baseEcy
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_07f78c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0280ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F78CULL;
}

// FDE #0860 | PC: 0x07fa0c..0x07fe30 (1060 B) | Symbol: _ZNKSt6__ndk17num_putIcNS_19ostreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_putES4_RNS_8ios_baseEcd
// EN: AArch64 prologue [sub sp, sp, #0x100; str d8, [sp, #0x90]; stp x28, x27, [sp, #0xa0]; stp x26, x25, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x100; str d8, [sp, #0x90]; stp x28, x27, [sp, #0xa0]; stp x26, x25, [sp, #0xb0]]
uint64_t fde_sub_07fa0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD004BE8ULL) << 32) | 0xD10403FFULL;
    const uint64_t kPcRange = 0x0424ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FA0CULL;
}

// FDE #0861 | PC: 0x07fe30..0x07ff24 (244 B) | Symbol: _ZNSt6__ndk119__libcpp_asprintf_lEPPcP10__locale_tPKcz
// EN: AArch64 prologue [sub sp, sp, #0x140; stp x28, x23, [sp, #0x100]; stp x22, x21, [sp, #0x110]; stp x20, x19, [sp, #0x120]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x140; stp x28, x23, [sp, #0x100]; stp x22, x21, [sp, #0x110]; stp x20, x19, [sp, #0x120]]
uint64_t fde_sub_07fe30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9105FFCULL) << 32) | 0xD10503FFULL;
    const uint64_t kPcRange = 0x00F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FE30ULL;
}

// FDE #0862 | PC: 0x07ff24..0x0804f8 (1492 B) | Symbol: _ZNSt6__ndk19__num_putIcE23__widen_and_group_floatEPcS2_S2_S2_RS2_S3_RKNS_6localeE
// EN: AArch64 prologue [sub sp, sp, #0xc0; stp x28, x27, [sp, #0x60]; stp x26, x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; stp x28, x27, [sp, #0x60]; stp x26, x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]]
uint64_t fde_sub_07ff24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9066FFCULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x05D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FF24ULL;
}

// FDE #0863 | PC: 0x0804f8..0x080924 (1068 B) | Symbol: _ZNKSt6__ndk17num_putIcNS_19ostreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_putES4_RNS_8ios_baseEce
// EN: AArch64 prologue [sub sp, sp, #0x100; stp x28, x27, [sp, #0xa0]; stp x26, x25, [sp, #0xb0]; stp x24, x23, [sp, #0xc0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x100; stp x28, x27, [sp, #0xa0]; stp x26, x25, [sp, #0xb0]; stp x24, x23, [sp, #0xc0]]
uint64_t fde_sub_0804f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90A6FFCULL) << 32) | 0xD10403FFULL;
    const uint64_t kPcRange = 0x042CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0804F8ULL;
}

// FDE #0864 | PC: 0x080924..0x080b88 (612 B) | Symbol: _ZNKSt6__ndk17num_putIcNS_19ostreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_putES4_RNS_8ios_baseEcPKv
// EN: AArch64 prologue [sub sp, sp, #0xe0; stp x28, x27, [sp, #0x80]; stp x26, x25, [sp, #0x90]; stp x24, x23, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xe0; stp x28, x27, [sp, #0x80]; stp x26, x25, [sp, #0x90]; stp x24, x23, [sp, #0xa0]]
uint64_t fde_sub_080924(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9086FFCULL) << 32) | 0xD10383FFULL;
    const uint64_t kPcRange = 0x0264ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080924ULL;
}

// FDE #0865 | PC: 0x080b88..0x080da0 (536 B) | Symbol: _ZNKSt6__ndk17num_putIwNS_19ostreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_putES4_RNS_8ios_baseEwb
// EN: AArch64 prologue [sub sp, sp, #0x80; str x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]; stp x20, x19, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]; stp x20, x19, [sp, #0x60]]
uint64_t fde_sub_080b88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F7ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0218ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080B88ULL;
}

// FDE #0866 | PC: 0x080da0..0x081028 (648 B) | Symbol: _ZNKSt6__ndk17num_putIwNS_19ostreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_putES4_RNS_8ios_baseEwl
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_080da0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0288ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080DA0ULL;
}

// FDE #0867 | PC: 0x081028..0x081430 (1032 B) | Symbol: _ZNSt6__ndk19__num_putIwE21__widen_and_group_intEPcS2_S2_PwRS3_S4_RKNS_6localeE
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]]
uint64_t fde_sub_081028(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9056FFCULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x0408ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081028ULL;
}

// FDE #0868 | PC: 0x081430..0x081618 (488 B) | Symbol: sub_081430
// EN: AArch64 prologue [sub sp, sp, #0x80; str x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_081430(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013FBULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x01E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081430ULL;
}

// FDE #0869 | PC: 0x081618..0x08189c (644 B) | Symbol: _ZNKSt6__ndk17num_putIwNS_19ostreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_putES4_RNS_8ios_baseEwx
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_081618(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0284ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081618ULL;
}

// FDE #0870 | PC: 0x08189c..0x081b24 (648 B) | Symbol: _ZNKSt6__ndk17num_putIwNS_19ostreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_putES4_RNS_8ios_baseEwm
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_08189c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0288ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08189CULL;
}

// FDE #0871 | PC: 0x081b24..0x081da8 (644 B) | Symbol: _ZNKSt6__ndk17num_putIwNS_19ostreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_putES4_RNS_8ios_baseEwy
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_081b24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0284ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081B24ULL;
}

// FDE #0872 | PC: 0x081da8..0x0821dc (1076 B) | Symbol: _ZNKSt6__ndk17num_putIwNS_19ostreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_putES4_RNS_8ios_baseEwd
// EN: AArch64 prologue [sub sp, sp, #0x1c0; str d8, [sp, #0x150]; stp x28, x27, [sp, #0x160]; stp x26, x25, [sp, #0x170]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1c0; str d8, [sp, #0x150]; stp x28, x27, [sp, #0x160]; stp x26, x25, [sp, #0x170]]
uint64_t fde_sub_081da8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD00ABE8ULL) << 32) | 0xD10703FFULL;
    const uint64_t kPcRange = 0x0434ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081DA8ULL;
}

// FDE #0873 | PC: 0x0821dc..0x0827c0 (1508 B) | Symbol: _ZNSt6__ndk19__num_putIwE23__widen_and_group_floatEPcS2_S2_PwRS3_S4_RKNS_6localeE
// EN: AArch64 prologue [sub sp, sp, #0xc0; stp x28, x27, [sp, #0x60]; stp x26, x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; stp x28, x27, [sp, #0x60]; stp x26, x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]]
uint64_t fde_sub_0821dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9066FFCULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x05E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0821DCULL;
}

// FDE #0874 | PC: 0x0827c0..0x082bfc (1084 B) | Symbol: _ZNKSt6__ndk17num_putIwNS_19ostreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_putES4_RNS_8ios_baseEwe
// EN: AArch64 prologue [sub sp, sp, #0x1c0; stp x28, x27, [sp, #0x160]; stp x26, x25, [sp, #0x170]; stp x24, x23, [sp, #0x180]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1c0; stp x28, x27, [sp, #0x160]; stp x26, x25, [sp, #0x170]; stp x24, x23, [sp, #0x180]]
uint64_t fde_sub_0827c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9166FFCULL) << 32) | 0xD10703FFULL;
    const uint64_t kPcRange = 0x043CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0827C0ULL;
}

// FDE #0875 | PC: 0x082bfc..0x082e60 (612 B) | Symbol: _ZNKSt6__ndk17num_putIwNS_19ostreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_putES4_RNS_8ios_baseEwPKv
// EN: AArch64 prologue [sub sp, sp, #0x150; stp x28, x27, [sp, #0xf0]; stp x26, x25, [sp, #0x100]; stp x24, x23, [sp, #0x110]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x150; stp x28, x27, [sp, #0xf0]; stp x26, x25, [sp, #0x100]; stp x24, x23, [sp, #0x110]]
uint64_t fde_sub_082bfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90F6FFCULL) << 32) | 0xD10543FFULL;
    const uint64_t kPcRange = 0x0264ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082BFCULL;
}

// FDE #0876 | PC: 0x082e60..0x082e64 (4 B) | Symbol: sub_082e60
// EN: AArch64 prologue [b #0x48180] | VI: Khởi đầu hàm AArch64 [b #0x48180]
uint64_t fde_sub_082e60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5100C008ULL) << 32) | 0x17FF14C8ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082E60ULL;
}

// FDE #0877 | PC: 0x082e64..0x082e74 (16 B) | Symbol: sub_082e64
// EN: AArch64 prologue [sub w8, w0, #0x30; cmp w8, #0xa; cset w0, lo; ret] | VI: Khởi đầu hàm AArch64 [sub w8, w0, #0x30; cmp w8, #0xa; cset w0, lo; ret]
uint64_t fde_sub_082e64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100291FULL) << 32) | 0x5100C008ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082E64ULL;
}

// FDE #0878 | PC: 0x082e74..0x083358 (1252 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE3getES4_S4_RNS_8ios_baseERjP2tmPKcSC_
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]]
uint64_t fde_sub_082e74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9056FFCULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x04E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082E74ULL;
}

// FDE #0879 | PC: 0x083358..0x083360 (8 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE13do_date_orderEv
// EN: AArch64 prologue [mov w0, #2; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #2; ret]
uint64_t fde_sub_083358(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800040ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x083358ULL;
}

// FDE #0880 | PC: 0x083360..0x0833c4 (100 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE11do_get_timeES4_S4_RNS_8ios_baseERjP2tm
// EN: AArch64 prologue [sub sp, sp, #0x30; str x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; str x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_083360(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF3ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x083360ULL;
}

// FDE #0881 | PC: 0x0833c4..0x083444 (128 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE11do_get_dateES4_S4_RNS_8ios_baseERjP2tm
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0833c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0833C4ULL;
}

// FDE #0882 | PC: 0x083444..0x0835d4 (400 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE14do_get_weekdayES4_S4_RNS_8ios_baseERjP2tm
// EN: AArch64 prologue [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]]
uint64_t fde_sub_083444(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F9ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0190ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x083444ULL;
}

// FDE #0883 | PC: 0x0835d4..0x083688 (180 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE17__get_weekdaynameERiRS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0835d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0835D4ULL;
}

// FDE #0884 | PC: 0x083688..0x083814 (396 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE16do_get_monthnameES4_S4_RNS_8ios_baseERjP2tm
// EN: AArch64 prologue [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]]
uint64_t fde_sub_083688(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F9ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x018CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x083688ULL;
}

// FDE #0885 | PC: 0x083814..0x0838c4 (176 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE15__get_monthnameERiRS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_083814(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x083814ULL;
}

// FDE #0886 | PC: 0x0838c4..0x083a10 (332 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE11do_get_yearES4_S4_RNS_8ios_baseERjP2tm
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]; stp x20, x19, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]; stp x20, x19, [sp, #0x60]]
uint64_t fde_sub_0838c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9045FF8ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x014CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0838C4ULL;
}

// FDE #0887 | PC: 0x083a10..0x083a74 (100 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE10__get_yearERiRS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x4] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x4]
uint64_t fde_sub_083a10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x083A10ULL;
}

// FDE #0888 | PC: 0x083a74..0x0840c8 (1620 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_getES4_S4_RNS_8ios_baseERjP2tmcc
// EN: AArch64 prologue [sub sp, sp, #0xa0; str x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; str x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]]
uint64_t fde_sub_083a74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023FBULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x0654ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x083A74ULL;
}

// FDE #0889 | PC: 0x0840c8..0x084124 (92 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE9__get_dayERiRS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4]
uint64_t fde_sub_0840c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0840C8ULL;
}

// FDE #0890 | PC: 0x084124..0x08417c (88 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE10__get_hourERiRS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4]
uint64_t fde_sub_084124(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x084124ULL;
}

// FDE #0891 | PC: 0x08417c..0x0841d8 (92 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE13__get_12_hourERiRS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4]
uint64_t fde_sub_08417c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08417CULL;
}

// FDE #0892 | PC: 0x0841d8..0x084230 (88 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE18__get_day_year_numERiRS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4]
uint64_t fde_sub_0841d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0841D8ULL;
}

// FDE #0893 | PC: 0x084230..0x08428c (92 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE11__get_monthERiRS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4]
uint64_t fde_sub_084230(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x084230ULL;
}

// FDE #0894 | PC: 0x08428c..0x0842e4 (88 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE12__get_minuteERiRS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4]
uint64_t fde_sub_08428c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08428CULL;
}

// FDE #0895 | PC: 0x0842e4..0x084494 (432 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE17__get_white_spaceERS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0842e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x01B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0842E4ULL;
}

// FDE #0896 | PC: 0x084494..0x08457c (232 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE11__get_am_pmERiRS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_084494(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x084494ULL;
}

// FDE #0897 | PC: 0x08457c..0x0845d4 (88 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE12__get_secondERiRS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4]
uint64_t fde_sub_08457c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08457CULL;
}

// FDE #0898 | PC: 0x0845d4..0x08462c (88 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE13__get_weekdayERiRS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4]
uint64_t fde_sub_0845d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0845D4ULL;
}

// FDE #0899 | PC: 0x08462c..0x084674 (72 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE11__get_year4ERiRS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x4] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x4]
uint64_t fde_sub_08462c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08462CULL;
}

// FDE #0900 | PC: 0x084674..0x084838 (452 B) | Symbol: _ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE13__get_percentERS4_S4_RjRKNS_5ctypeIcEE
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_084674(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x01C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x084674ULL;
}

// FDE #0901 | PC: 0x084838..0x084b84 (844 B) | Symbol: sub_084838
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_084838(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x034CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x084838ULL;
}

// FDE #0902 | PC: 0x084b84..0x0850a0 (1308 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE3getES4_S4_RNS_8ios_baseERjP2tmPKwSC_
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]]
uint64_t fde_sub_084b84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9056FFCULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x051CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x084B84ULL;
}

// FDE #0903 | PC: 0x0850a0..0x0850a8 (8 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE13do_date_orderEv
// EN: AArch64 prologue [mov w0, #2; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #2; ret]
uint64_t fde_sub_0850a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800040ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0850A0ULL;
}

// FDE #0904 | PC: 0x0850a8..0x085108 (96 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE11do_get_timeES4_S4_RNS_8ios_baseERjP2tm
// EN: AArch64 prologue [sub sp, sp, #0x50; str x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]; add x29, sp, #0x40] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]; add x29, sp, #0x40]
uint64_t fde_sub_0850a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF3ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0850A8ULL;
}

// FDE #0905 | PC: 0x085108..0x08518c (132 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE11do_get_dateES4_S4_RNS_8ios_baseERjP2tm
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_085108(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085108ULL;
}

// FDE #0906 | PC: 0x08518c..0x08531c (400 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE14do_get_weekdayES4_S4_RNS_8ios_baseERjP2tm
// EN: AArch64 prologue [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]]
uint64_t fde_sub_08518c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F9ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0190ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08518CULL;
}

// FDE #0907 | PC: 0x08531c..0x0853d0 (180 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE17__get_weekdaynameERiRS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_08531c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08531CULL;
}

// FDE #0908 | PC: 0x0853d0..0x08555c (396 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE16do_get_monthnameES4_S4_RNS_8ios_baseERjP2tm
// EN: AArch64 prologue [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]]
uint64_t fde_sub_0853d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F9ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x018CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0853D0ULL;
}

// FDE #0909 | PC: 0x08555c..0x08560c (176 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE15__get_monthnameERiRS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_08555c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08555CULL;
}

// FDE #0910 | PC: 0x08560c..0x085758 (332 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE11do_get_yearES4_S4_RNS_8ios_baseERjP2tm
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]; stp x20, x19, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]; stp x20, x19, [sp, #0x60]]
uint64_t fde_sub_08560c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9045FF8ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x014CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08560CULL;
}

// FDE #0911 | PC: 0x085758..0x0857bc (100 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE10__get_yearERiRS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x4] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x4]
uint64_t fde_sub_085758(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085758ULL;
}

// FDE #0912 | PC: 0x0857bc..0x085e00 (1604 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_getES4_S4_RNS_8ios_baseERjP2tmcc
// EN: AArch64 prologue [sub sp, sp, #0xc0; str x27, [sp, #0x60]; stp x26, x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; str x27, [sp, #0x60]; stp x26, x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]]
uint64_t fde_sub_0857bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90033FBULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x0644ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0857BCULL;
}

// FDE #0913 | PC: 0x085e00..0x085e5c (92 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE9__get_dayERiRS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4]
uint64_t fde_sub_085e00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085E00ULL;
}

// FDE #0914 | PC: 0x085e5c..0x085eb4 (88 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE10__get_hourERiRS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4]
uint64_t fde_sub_085e5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085E5CULL;
}

// FDE #0915 | PC: 0x085eb4..0x085f10 (92 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE13__get_12_hourERiRS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4]
uint64_t fde_sub_085eb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085EB4ULL;
}

// FDE #0916 | PC: 0x085f10..0x085f68 (88 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE18__get_day_year_numERiRS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4]
uint64_t fde_sub_085f10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085F10ULL;
}

// FDE #0917 | PC: 0x085f68..0x085fc4 (92 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE11__get_monthERiRS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4]
uint64_t fde_sub_085f68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085F68ULL;
}

// FDE #0918 | PC: 0x085fc4..0x08601c (88 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE12__get_minuteERiRS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4]
uint64_t fde_sub_085fc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085FC4ULL;
}

// FDE #0919 | PC: 0x08601c..0x0861fc (480 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE17__get_white_spaceERS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_08601c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x01E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08601CULL;
}

// FDE #0920 | PC: 0x0861fc..0x0862e4 (232 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE11__get_am_pmERiRS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0861fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0861FCULL;
}

// FDE #0921 | PC: 0x0862e4..0x08633c (88 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE12__get_secondERiRS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4]
uint64_t fde_sub_0862e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0862E4ULL;
}

// FDE #0922 | PC: 0x08633c..0x086394 (88 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE13__get_weekdayERiRS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x4]
uint64_t fde_sub_08633c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08633CULL;
}

// FDE #0923 | PC: 0x086394..0x0863dc (72 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE11__get_year4ERiRS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x4] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x4]
uint64_t fde_sub_086394(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x086394ULL;
}

// FDE #0924 | PC: 0x0863dc..0x0865c8 (492 B) | Symbol: _ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE13__get_percentERS4_S4_RjRKNS_5ctypeIwEE
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0863dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x01ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0863DCULL;
}

// FDE #0925 | PC: 0x0865c8..0x086954 (908 B) | Symbol: sub_0865c8
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0865c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x038CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0865C8ULL;
}

// FDE #0926 | PC: 0x086954..0x086c70 (796 B) | Symbol: _ZNKSt6__ndk18time_putIcNS_19ostreambuf_iteratorIcNS_11char_traitsIcEEEEE3putES4_RNS_8ios_baseEcPK2tmPKcSC_
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]]
uint64_t fde_sub_086954(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9056FFCULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x031CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x086954ULL;
}

// FDE #0927 | PC: 0x086c70..0x086d54 (228 B) | Symbol: _ZNKSt6__ndk18time_putIcNS_19ostreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_putES4_RNS_8ios_baseEcPK2tmcc
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp x22, x21, [sp, #0x70]; stp x20, x19, [sp, #0x80]; stp x29, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp x22, x21, [sp, #0x70]; stp x20, x19, [sp, #0x80]; stp x29, x30, [sp, #0x90]]
uint64_t fde_sub_086c70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90757F6ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x086C70ULL;
}

// FDE #0928 | PC: 0x086d54..0x087084 (816 B) | Symbol: _ZNKSt6__ndk18time_putIwNS_19ostreambuf_iteratorIwNS_11char_traitsIwEEEEE3putES4_RNS_8ios_baseEwPK2tmPKwSC_
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]]
uint64_t fde_sub_086d54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9056FFCULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x0330ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x086D54ULL;
}

// FDE #0929 | PC: 0x087084..0x087168 (228 B) | Symbol: _ZNKSt6__ndk18time_putIwNS_19ostreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_putES4_RNS_8ios_baseEwPK2tmcc
// EN: AArch64 prologue [sub sp, sp, #0x1e0; str x28, [sp, #0x1a0]; stp x22, x21, [sp, #0x1b0]; stp x20, x19, [sp, #0x1c0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1e0; str x28, [sp, #0x1a0]; stp x22, x21, [sp, #0x1b0]; stp x20, x19, [sp, #0x1c0]]
uint64_t fde_sub_087084(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900D3FCULL) << 32) | 0xD10783FFULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087084ULL;
}

// FDE #0930 | PC: 0x087168..0x087170 (8 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb0EE16do_decimal_pointEv
// EN: AArch64 prologue [mov w0, #0xff; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0xff; ret]
uint64_t fde_sub_087168(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52801FE0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087168ULL;
}

// FDE #0931 | PC: 0x087170..0x087178 (8 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb0EE16do_thousands_sepEv
// EN: AArch64 prologue [mov w0, #0xff; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0xff; ret]
uint64_t fde_sub_087170(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52801FE0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087170ULL;
}

// FDE #0932 | PC: 0x087178..0x087184 (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb0EE11do_groupingEv
// EN: AArch64 prologue [stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret]
uint64_t fde_sub_087178(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900091FULL) << 32) | 0xA9007D1FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087178ULL;
}

// FDE #0933 | PC: 0x087184..0x087190 (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb0EE14do_curr_symbolEv
// EN: AArch64 prologue [stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret]
uint64_t fde_sub_087184(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900091FULL) << 32) | 0xA9007D1FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087184ULL;
}

// FDE #0934 | PC: 0x087190..0x08719c (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb0EE16do_positive_signEv
// EN: AArch64 prologue [stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret]
uint64_t fde_sub_087190(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900091FULL) << 32) | 0xA9007D1FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087190ULL;
}

// FDE #0935 | PC: 0x08719c..0x0871b4 (24 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb0EE16do_negative_signEv
// EN: AArch64 prologue [mov w9, #0x2d02; stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; strh w9, [x8]] | VI: Khởi đầu hàm AArch64 [mov w9, #0x2d02; stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; strh w9, [x8]]
uint64_t fde_sub_08719c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9007D1FULL) << 32) | 0x5285A049ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08719CULL;
}

// FDE #0936 | PC: 0x0871b4..0x0871bc (8 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb0EE14do_frac_digitsEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_0871b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0871B4ULL;
}

// FDE #0937 | PC: 0x0871bc..0x0871c8 (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb0EE13do_pos_formatEv
// EN: AArch64 prologue [mov w0, #0x302; movk w0, #0x400, lsl #16; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x302; movk w0, #0x400, lsl #16; ret]
uint64_t fde_sub_0871bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72A08000ULL) << 32) | 0x52806040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0871BCULL;
}

// FDE #0938 | PC: 0x0871c8..0x0871d4 (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb0EE13do_neg_formatEv
// EN: AArch64 prologue [mov w0, #0x302; movk w0, #0x400, lsl #16; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x302; movk w0, #0x400, lsl #16; ret]
uint64_t fde_sub_0871c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72A08000ULL) << 32) | 0x52806040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0871C8ULL;
}

// FDE #0939 | PC: 0x0871d4..0x0871dc (8 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb1EE16do_decimal_pointEv
// EN: AArch64 prologue [mov w0, #0xff; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0xff; ret]
uint64_t fde_sub_0871d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52801FE0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0871D4ULL;
}

// FDE #0940 | PC: 0x0871dc..0x0871e4 (8 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb1EE16do_thousands_sepEv
// EN: AArch64 prologue [mov w0, #0xff; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0xff; ret]
uint64_t fde_sub_0871dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52801FE0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0871DCULL;
}

// FDE #0941 | PC: 0x0871e4..0x0871f0 (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb1EE11do_groupingEv
// EN: AArch64 prologue [stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret]
uint64_t fde_sub_0871e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900091FULL) << 32) | 0xA9007D1FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0871E4ULL;
}

// FDE #0942 | PC: 0x0871f0..0x0871fc (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb1EE14do_curr_symbolEv
// EN: AArch64 prologue [stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret]
uint64_t fde_sub_0871f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900091FULL) << 32) | 0xA9007D1FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0871F0ULL;
}

// FDE #0943 | PC: 0x0871fc..0x087208 (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb1EE16do_positive_signEv
// EN: AArch64 prologue [stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret]
uint64_t fde_sub_0871fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900091FULL) << 32) | 0xA9007D1FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0871FCULL;
}

// FDE #0944 | PC: 0x087208..0x087220 (24 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb1EE16do_negative_signEv
// EN: AArch64 prologue [mov w9, #0x2d02; stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; strh w9, [x8]] | VI: Khởi đầu hàm AArch64 [mov w9, #0x2d02; stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; strh w9, [x8]]
uint64_t fde_sub_087208(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9007D1FULL) << 32) | 0x5285A049ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087208ULL;
}

// FDE #0945 | PC: 0x087220..0x087228 (8 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb1EE14do_frac_digitsEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_087220(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087220ULL;
}

// FDE #0946 | PC: 0x087228..0x087234 (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb1EE13do_pos_formatEv
// EN: AArch64 prologue [mov w0, #0x302; movk w0, #0x400, lsl #16; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x302; movk w0, #0x400, lsl #16; ret]
uint64_t fde_sub_087228(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72A08000ULL) << 32) | 0x52806040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087228ULL;
}

// FDE #0947 | PC: 0x087234..0x087240 (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIcLb1EE13do_neg_formatEv
// EN: AArch64 prologue [mov w0, #0x302; movk w0, #0x400, lsl #16; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x302; movk w0, #0x400, lsl #16; ret]
uint64_t fde_sub_087234(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72A08000ULL) << 32) | 0x52806040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087234ULL;
}

// FDE #0948 | PC: 0x087240..0x087248 (8 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb0EE16do_decimal_pointEv
// EN: AArch64 prologue [mov w0, #-1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #-1; ret]
uint64_t fde_sub_087240(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x12800000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087240ULL;
}

// FDE #0949 | PC: 0x087248..0x087250 (8 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb0EE16do_thousands_sepEv
// EN: AArch64 prologue [mov w0, #-1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #-1; ret]
uint64_t fde_sub_087248(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x12800000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087248ULL;
}

// FDE #0950 | PC: 0x087250..0x08725c (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb0EE11do_groupingEv
// EN: AArch64 prologue [stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret]
uint64_t fde_sub_087250(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900091FULL) << 32) | 0xA9007D1FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087250ULL;
}

// FDE #0951 | PC: 0x08725c..0x087268 (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb0EE14do_curr_symbolEv
// EN: AArch64 prologue [stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret]
uint64_t fde_sub_08725c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900091FULL) << 32) | 0xA9007D1FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08725CULL;
}

// FDE #0952 | PC: 0x087268..0x087274 (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb0EE16do_positive_signEv
// EN: AArch64 prologue [stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret]
uint64_t fde_sub_087268(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900091FULL) << 32) | 0xA9007D1FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087268ULL;
}

// FDE #0953 | PC: 0x087274..0x0872b4 (64 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb0EE16do_negative_signEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x8] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x8]
uint64_t fde_sub_087274(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087274ULL;
}

// FDE #0954 | PC: 0x0872b4..0x0872bc (8 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb0EE14do_frac_digitsEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_0872b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0872B4ULL;
}

// FDE #0955 | PC: 0x0872bc..0x0872c8 (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb0EE13do_pos_formatEv
// EN: AArch64 prologue [mov w0, #0x302; movk w0, #0x400, lsl #16; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x302; movk w0, #0x400, lsl #16; ret]
uint64_t fde_sub_0872bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72A08000ULL) << 32) | 0x52806040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0872BCULL;
}

// FDE #0956 | PC: 0x0872c8..0x0872d4 (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb0EE13do_neg_formatEv
// EN: AArch64 prologue [mov w0, #0x302; movk w0, #0x400, lsl #16; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x302; movk w0, #0x400, lsl #16; ret]
uint64_t fde_sub_0872c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72A08000ULL) << 32) | 0x52806040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0872C8ULL;
}

// FDE #0957 | PC: 0x0872d4..0x0872dc (8 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb1EE16do_decimal_pointEv
// EN: AArch64 prologue [mov w0, #-1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #-1; ret]
uint64_t fde_sub_0872d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x12800000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0872D4ULL;
}

// FDE #0958 | PC: 0x0872dc..0x0872e4 (8 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb1EE16do_thousands_sepEv
// EN: AArch64 prologue [mov w0, #-1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #-1; ret]
uint64_t fde_sub_0872dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x12800000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0872DCULL;
}

// FDE #0959 | PC: 0x0872e4..0x0872f0 (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb1EE11do_groupingEv
// EN: AArch64 prologue [stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret]
uint64_t fde_sub_0872e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900091FULL) << 32) | 0xA9007D1FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0872E4ULL;
}

// FDE #0960 | PC: 0x0872f0..0x0872fc (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb1EE14do_curr_symbolEv
// EN: AArch64 prologue [stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret]
uint64_t fde_sub_0872f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900091FULL) << 32) | 0xA9007D1FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0872F0ULL;
}

// FDE #0961 | PC: 0x0872fc..0x087308 (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb1EE16do_positive_signEv
// EN: AArch64 prologue [stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret]
uint64_t fde_sub_0872fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900091FULL) << 32) | 0xA9007D1FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0872FCULL;
}

// FDE #0962 | PC: 0x087308..0x087348 (64 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb1EE16do_negative_signEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x8] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x8]
uint64_t fde_sub_087308(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087308ULL;
}

// FDE #0963 | PC: 0x087348..0x087350 (8 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb1EE14do_frac_digitsEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_087348(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087348ULL;
}

// FDE #0964 | PC: 0x087350..0x08735c (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb1EE13do_pos_formatEv
// EN: AArch64 prologue [mov w0, #0x302; movk w0, #0x400, lsl #16; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x302; movk w0, #0x400, lsl #16; ret]
uint64_t fde_sub_087350(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72A08000ULL) << 32) | 0x52806040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087350ULL;
}

// FDE #0965 | PC: 0x08735c..0x087368 (12 B) | Symbol: _ZNKSt6__ndk110moneypunctIwLb1EE13do_neg_formatEv
// EN: AArch64 prologue [mov w0, #0x302; movk w0, #0x400, lsl #16; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x302; movk w0, #0x400, lsl #16; ret]
uint64_t fde_sub_08735c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72A08000ULL) << 32) | 0x52806040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08735CULL;
}

// FDE #0966 | PC: 0x087368..0x087370 (8 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb0EE16do_decimal_pointEv
// EN: AArch64 prologue [ldrb w0, [x0, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [ldrb w0, [x0, #0x10]; ret]
uint64_t fde_sub_087368(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x39404000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087368ULL;
}

// FDE #0967 | PC: 0x087370..0x087378 (8 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb0EE16do_thousands_sepEv
// EN: AArch64 prologue [ldrb w0, [x0, #0x11]; ret] | VI: Khởi đầu hàm AArch64 [ldrb w0, [x0, #0x11]; ret]
uint64_t fde_sub_087370(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x39404400ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087370ULL;
}

// FDE #0968 | PC: 0x087378..0x087384 (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb0EE11do_groupingEv
// EN: AArch64 prologue [add x1, x0, #0x18; mov x0, x8; b #0x48580] | VI: Khởi đầu hàm AArch64 [add x1, x0, #0x18; mov x0, x8; b #0x48580]
uint64_t fde_sub_087378(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0x91006001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087378ULL;
}

// FDE #0969 | PC: 0x087384..0x087390 (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb0EE14do_curr_symbolEv
// EN: AArch64 prologue [add x1, x0, #0x30; mov x0, x8; b #0x48580] | VI: Khởi đầu hàm AArch64 [add x1, x0, #0x30; mov x0, x8; b #0x48580]
uint64_t fde_sub_087384(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0x9100C001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087384ULL;
}

// FDE #0970 | PC: 0x087390..0x08739c (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb0EE16do_positive_signEv
// EN: AArch64 prologue [add x1, x0, #0x48; mov x0, x8; b #0x48580] | VI: Khởi đầu hàm AArch64 [add x1, x0, #0x48; mov x0, x8; b #0x48580]
uint64_t fde_sub_087390(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0x91012001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087390ULL;
}

// FDE #0971 | PC: 0x08739c..0x0873a8 (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb0EE16do_negative_signEv
// EN: AArch64 prologue [add x1, x0, #0x60; mov x0, x8; b #0x48580] | VI: Khởi đầu hàm AArch64 [add x1, x0, #0x60; mov x0, x8; b #0x48580]
uint64_t fde_sub_08739c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0x91018001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08739CULL;
}

// FDE #0972 | PC: 0x0873a8..0x0873b0 (8 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb0EE14do_frac_digitsEv
// EN: AArch64 prologue [ldr w0, [x0, #0x78]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0x78]; ret]
uint64_t fde_sub_0873a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9407800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0873A8ULL;
}

// FDE #0973 | PC: 0x0873b0..0x0873b8 (8 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb0EE13do_pos_formatEv
// EN: AArch64 prologue [ldr w0, [x0, #0x7c]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0x7c]; ret]
uint64_t fde_sub_0873b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9407C00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0873B0ULL;
}

// FDE #0974 | PC: 0x0873b8..0x0873c0 (8 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb0EE13do_neg_formatEv
// EN: AArch64 prologue [ldr w0, [x0, #0x80]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0x80]; ret]
uint64_t fde_sub_0873b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9408000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0873B8ULL;
}

// FDE #0975 | PC: 0x0873c0..0x0873c8 (8 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb1EE16do_decimal_pointEv
// EN: AArch64 prologue [ldrb w0, [x0, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [ldrb w0, [x0, #0x10]; ret]
uint64_t fde_sub_0873c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x39404000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0873C0ULL;
}

// FDE #0976 | PC: 0x0873c8..0x0873d0 (8 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb1EE16do_thousands_sepEv
// EN: AArch64 prologue [ldrb w0, [x0, #0x11]; ret] | VI: Khởi đầu hàm AArch64 [ldrb w0, [x0, #0x11]; ret]
uint64_t fde_sub_0873c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x39404400ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0873C8ULL;
}

// FDE #0977 | PC: 0x0873d0..0x0873dc (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb1EE11do_groupingEv
// EN: AArch64 prologue [add x1, x0, #0x18; mov x0, x8; b #0x48580] | VI: Khởi đầu hàm AArch64 [add x1, x0, #0x18; mov x0, x8; b #0x48580]
uint64_t fde_sub_0873d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0x91006001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0873D0ULL;
}

// FDE #0978 | PC: 0x0873dc..0x0873e8 (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb1EE14do_curr_symbolEv
// EN: AArch64 prologue [add x1, x0, #0x30; mov x0, x8; b #0x48580] | VI: Khởi đầu hàm AArch64 [add x1, x0, #0x30; mov x0, x8; b #0x48580]
uint64_t fde_sub_0873dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0x9100C001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0873DCULL;
}

// FDE #0979 | PC: 0x0873e8..0x0873f4 (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb1EE16do_positive_signEv
// EN: AArch64 prologue [add x1, x0, #0x48; mov x0, x8; b #0x48580] | VI: Khởi đầu hàm AArch64 [add x1, x0, #0x48; mov x0, x8; b #0x48580]
uint64_t fde_sub_0873e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0x91012001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0873E8ULL;
}

// FDE #0980 | PC: 0x0873f4..0x087400 (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb1EE16do_negative_signEv
// EN: AArch64 prologue [add x1, x0, #0x60; mov x0, x8; b #0x48580] | VI: Khởi đầu hàm AArch64 [add x1, x0, #0x60; mov x0, x8; b #0x48580]
uint64_t fde_sub_0873f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0x91018001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0873F4ULL;
}

// FDE #0981 | PC: 0x087400..0x087408 (8 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb1EE14do_frac_digitsEv
// EN: AArch64 prologue [ldr w0, [x0, #0x78]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0x78]; ret]
uint64_t fde_sub_087400(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9407800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087400ULL;
}

// FDE #0982 | PC: 0x087408..0x087410 (8 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb1EE13do_pos_formatEv
// EN: AArch64 prologue [ldr w0, [x0, #0x7c]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0x7c]; ret]
uint64_t fde_sub_087408(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9407C00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087408ULL;
}

// FDE #0983 | PC: 0x087410..0x087418 (8 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIcLb1EE13do_neg_formatEv
// EN: AArch64 prologue [ldr w0, [x0, #0x80]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0x80]; ret]
uint64_t fde_sub_087410(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9408000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087410ULL;
}

// FDE #0984 | PC: 0x087418..0x087420 (8 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb0EE16do_decimal_pointEv
// EN: AArch64 prologue [ldr w0, [x0, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0x10]; ret]
uint64_t fde_sub_087418(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9401000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087418ULL;
}

// FDE #0985 | PC: 0x087420..0x087428 (8 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb0EE16do_thousands_sepEv
// EN: AArch64 prologue [ldr w0, [x0, #0x14]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0x14]; ret]
uint64_t fde_sub_087420(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9401400ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087420ULL;
}

// FDE #0986 | PC: 0x087428..0x087434 (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb0EE11do_groupingEv
// EN: AArch64 prologue [add x1, x0, #0x18; mov x0, x8; b #0x48580] | VI: Khởi đầu hàm AArch64 [add x1, x0, #0x18; mov x0, x8; b #0x48580]
uint64_t fde_sub_087428(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0x91006001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087428ULL;
}

// FDE #0987 | PC: 0x087434..0x087440 (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb0EE14do_curr_symbolEv
// EN: AArch64 prologue [add x1, x0, #0x30; mov x0, x8; b #0x47e90] | VI: Khởi đầu hàm AArch64 [add x1, x0, #0x30; mov x0, x8; b #0x47e90]
uint64_t fde_sub_087434(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0x9100C001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087434ULL;
}

// FDE #0988 | PC: 0x087440..0x08744c (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb0EE16do_positive_signEv
// EN: AArch64 prologue [add x1, x0, #0x48; mov x0, x8; b #0x47e90] | VI: Khởi đầu hàm AArch64 [add x1, x0, #0x48; mov x0, x8; b #0x47e90]
uint64_t fde_sub_087440(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0x91012001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087440ULL;
}

// FDE #0989 | PC: 0x08744c..0x087458 (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb0EE16do_negative_signEv
// EN: AArch64 prologue [add x1, x0, #0x60; mov x0, x8; b #0x47e90] | VI: Khởi đầu hàm AArch64 [add x1, x0, #0x60; mov x0, x8; b #0x47e90]
uint64_t fde_sub_08744c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0x91018001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08744CULL;
}

// FDE #0990 | PC: 0x087458..0x087460 (8 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb0EE14do_frac_digitsEv
// EN: AArch64 prologue [ldr w0, [x0, #0x78]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0x78]; ret]
uint64_t fde_sub_087458(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9407800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087458ULL;
}

// FDE #0991 | PC: 0x087460..0x087468 (8 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb0EE13do_pos_formatEv
// EN: AArch64 prologue [ldr w0, [x0, #0x7c]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0x7c]; ret]
uint64_t fde_sub_087460(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9407C00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087460ULL;
}

// FDE #0992 | PC: 0x087468..0x087470 (8 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb0EE13do_neg_formatEv
// EN: AArch64 prologue [ldr w0, [x0, #0x80]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0x80]; ret]
uint64_t fde_sub_087468(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9408000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087468ULL;
}

// FDE #0993 | PC: 0x087470..0x087478 (8 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb1EE16do_decimal_pointEv
// EN: AArch64 prologue [ldr w0, [x0, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0x10]; ret]
uint64_t fde_sub_087470(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9401000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087470ULL;
}

// FDE #0994 | PC: 0x087478..0x087480 (8 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb1EE16do_thousands_sepEv
// EN: AArch64 prologue [ldr w0, [x0, #0x14]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0x14]; ret]
uint64_t fde_sub_087478(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9401400ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087478ULL;
}

// FDE #0995 | PC: 0x087480..0x08748c (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb1EE11do_groupingEv
// EN: AArch64 prologue [add x1, x0, #0x18; mov x0, x8; b #0x48580] | VI: Khởi đầu hàm AArch64 [add x1, x0, #0x18; mov x0, x8; b #0x48580]
uint64_t fde_sub_087480(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0x91006001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087480ULL;
}

// FDE #0996 | PC: 0x08748c..0x087498 (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb1EE14do_curr_symbolEv
// EN: AArch64 prologue [add x1, x0, #0x30; mov x0, x8; b #0x47e90] | VI: Khởi đầu hàm AArch64 [add x1, x0, #0x30; mov x0, x8; b #0x47e90]
uint64_t fde_sub_08748c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0x9100C001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08748CULL;
}

// FDE #0997 | PC: 0x087498..0x0874a4 (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb1EE16do_positive_signEv
// EN: AArch64 prologue [add x1, x0, #0x48; mov x0, x8; b #0x47e90] | VI: Khởi đầu hàm AArch64 [add x1, x0, #0x48; mov x0, x8; b #0x47e90]
uint64_t fde_sub_087498(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0x91012001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087498ULL;
}

// FDE #0998 | PC: 0x0874a4..0x0874b0 (12 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb1EE16do_negative_signEv
// EN: AArch64 prologue [add x1, x0, #0x60; mov x0, x8; b #0x47e90] | VI: Khởi đầu hàm AArch64 [add x1, x0, #0x60; mov x0, x8; b #0x47e90]
uint64_t fde_sub_0874a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0x91018001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0874A4ULL;
}

// FDE #0999 | PC: 0x0874b0..0x0874b8 (8 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb1EE14do_frac_digitsEv
// EN: AArch64 prologue [ldr w0, [x0, #0x78]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0x78]; ret]
uint64_t fde_sub_0874b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9407800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0874B0ULL;
}

// FDE #1000 | PC: 0x0874b8..0x0874c0 (8 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb1EE13do_pos_formatEv
// EN: AArch64 prologue [ldr w0, [x0, #0x7c]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0x7c]; ret]
uint64_t fde_sub_0874b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9407C00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0874B8ULL;
}

// FDE #1001 | PC: 0x0874c0..0x0874c8 (8 B) | Symbol: _ZNKSt6__ndk117moneypunct_bynameIwLb1EE13do_neg_formatEv
// EN: AArch64 prologue [ldr w0, [x0, #0x80]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0x80]; ret]
uint64_t fde_sub_0874c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9408000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0874C0ULL;
}

// FDE #1002 | PC: 0x0874c8..0x0878e0 (1048 B) | Symbol: _ZNKSt6__ndk19money_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_getES4_S4_bRNS_8ios_baseERjRe
// EN: AArch64 prologue [sub sp, sp, #0x1a0; stp x28, x27, [sp, #0x140]; stp x26, x25, [sp, #0x150]; stp x24, x23, [sp, #0x160]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1a0; stp x28, x27, [sp, #0x140]; stp x26, x25, [sp, #0x150]; stp x24, x23, [sp, #0x160]]
uint64_t fde_sub_0874c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9146FFCULL) << 32) | 0xD10683FFULL;
    const uint64_t kPcRange = 0x0418ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0874C8ULL;
}

// FDE #1003 | PC: 0x0878e0..0x088ae0 (4608 B) | Symbol: _ZNSt6__ndk19money_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE8__do_getERS4_S4_bRKNS_6localeEjRjRbRKNS_5ctypeIcEERNS_10unique_ptrIcPFvPvEEERPcSM_
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0878e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1200ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0878E0ULL;
}

// FDE #1004 | PC: 0x088ae0..0x088db8 (728 B) | Symbol: _ZNKSt6__ndk19money_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_getES4_S4_bRNS_8ios_baseERjRNS_12basic_stringIcS3_NS_9allocatorIcEEEE
// EN: AArch64 prologue [sub sp, sp, #0x140; stp x28, x27, [sp, #0xe0]; stp x26, x25, [sp, #0xf0]; stp x24, x23, [sp, #0x100]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x140; stp x28, x27, [sp, #0xe0]; stp x26, x25, [sp, #0xf0]; stp x24, x23, [sp, #0x100]]
uint64_t fde_sub_088ae0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90E6FFCULL) << 32) | 0xD10503FFULL;
    const uint64_t kPcRange = 0x02D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088AE0ULL;
}

// FDE #1005 | PC: 0x088db8..0x0890c8 (784 B) | Symbol: _ZNSt6__ndk111__money_getIcE13__gather_infoEbRKNS_6localeERNS_10money_base7patternERcS8_RNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEESF_SF_SF_Ri
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]]
uint64_t fde_sub_088db8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9036FFCULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0310ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088DB8ULL;
}

// FDE #1006 | PC: 0x0890c8..0x0894fc (1076 B) | Symbol: _ZNKSt6__ndk19money_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_getES4_S4_bRNS_8ios_baseERjRe
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0890c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0434ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0890C8ULL;
}

// FDE #1007 | PC: 0x0894fc..0x08a800 (4868 B) | Symbol: _ZNSt6__ndk19money_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE8__do_getERS4_S4_bRKNS_6localeEjRjRbRKNS_5ctypeIwEERNS_10unique_ptrIwPFvPvEEERPwSM_
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0894fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1304ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0894FCULL;
}

// FDE #1008 | PC: 0x08a800..0x08aaf4 (756 B) | Symbol: _ZNKSt6__ndk19money_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_getES4_S4_bRNS_8ios_baseERjRNS_12basic_stringIwS3_NS_9allocatorIwEEEE
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_08a800(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x02F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08A800ULL;
}

// FDE #1009 | PC: 0x08aaf4..0x08ae10 (796 B) | Symbol: _ZNSt6__ndk111__money_getIwE13__gather_infoEbRKNS_6localeERNS_10money_base7patternERwS8_RNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS9_IwNSA_IwEENSC_IwEEEESJ_SJ_Ri
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]]
uint64_t fde_sub_08aaf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9036FFCULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x031CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08AAF4ULL;
}

// FDE #1010 | PC: 0x08ae10..0x08b2c0 (1200 B) | Symbol: _ZNKSt6__ndk19money_putIcNS_19ostreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_putES4_bRNS_8ios_baseEce
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_08ae10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x04B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08AE10ULL;
}

// FDE #1011 | PC: 0x08b2c0..0x08b5a4 (740 B) | Symbol: _ZNSt6__ndk111__money_putIcE13__gather_infoEbbRKNS_6localeERNS_10money_base7patternERcS8_RNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEESF_SF_Ri
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]]
uint64_t fde_sub_08b2c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9036FFCULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x02E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B2C0ULL;
}

// FDE #1012 | PC: 0x08b5a4..0x08babc (1304 B) | Symbol: _ZNSt6__ndk111__money_putIcE8__formatEPcRS2_S3_jPKcS5_RKNS_5ctypeIcEEbRKNS_10money_base7patternEccRKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEESL_SL_i
// EN: AArch64 prologue [sub sp, sp, #0xc0; stp x28, x27, [sp, #0x60]; stp x26, x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; stp x28, x27, [sp, #0x60]; stp x26, x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]]
uint64_t fde_sub_08b5a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9066FFCULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x0518ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B5A4ULL;
}

// FDE #1013 | PC: 0x08babc..0x08be70 (948 B) | Symbol: _ZNKSt6__ndk19money_putIcNS_19ostreambuf_iteratorIcNS_11char_traitsIcEEEEE6do_putES4_bRNS_8ios_baseEcRKNS_12basic_stringIcS3_NS_9allocatorIcEEEE
// EN: AArch64 prologue [sub sp, sp, #0x1a0; stp x28, x27, [sp, #0x140]; stp x26, x25, [sp, #0x150]; stp x24, x23, [sp, #0x160]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1a0; stp x28, x27, [sp, #0x140]; stp x26, x25, [sp, #0x150]; stp x24, x23, [sp, #0x160]]
uint64_t fde_sub_08babc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9146FFCULL) << 32) | 0xD10683FFULL;
    const uint64_t kPcRange = 0x03B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BABCULL;
}

// FDE #1014 | PC: 0x08be70..0x08c324 (1204 B) | Symbol: _ZNKSt6__ndk19money_putIwNS_19ostreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_putES4_bRNS_8ios_baseEwe
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_08be70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x04B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BE70ULL;
}

// FDE #1015 | PC: 0x08c324..0x08c60c (744 B) | Symbol: _ZNSt6__ndk111__money_putIwE13__gather_infoEbbRKNS_6localeERNS_10money_base7patternERwS8_RNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS9_IwNSA_IwEENSC_IwEEEESJ_Ri
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]]
uint64_t fde_sub_08c324(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9036FFCULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x02E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C324ULL;
}

// FDE #1016 | PC: 0x08c60c..0x08cb00 (1268 B) | Symbol: _ZNSt6__ndk111__money_putIwE8__formatEPwRS2_S3_jPKwS5_RKNS_5ctypeIwEEbRKNS_10money_base7patternEwwRKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERKNSE_IwNSF_IwEENSH_IwEEEESQ_i
// EN: AArch64 prologue [sub sp, sp, #0xd0; stp x28, x27, [sp, #0x70]; stp x26, x25, [sp, #0x80]; stp x24, x23, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xd0; stp x28, x27, [sp, #0x70]; stp x26, x25, [sp, #0x80]; stp x24, x23, [sp, #0x90]]
uint64_t fde_sub_08c60c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9076FFCULL) << 32) | 0xD10343FFULL;
    const uint64_t kPcRange = 0x04F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C60CULL;
}

// FDE #1017 | PC: 0x08cb00..0x08cebc (956 B) | Symbol: _ZNKSt6__ndk19money_putIwNS_19ostreambuf_iteratorIwNS_11char_traitsIwEEEEE6do_putES4_bRNS_8ios_baseEwRKNS_12basic_stringIwS3_NS_9allocatorIwEEEE
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_08cb00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x03BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08CB00ULL;
}

// FDE #1018 | PC: 0x08cebc..0x08cec4 (8 B) | Symbol: _ZNKSt6__ndk18messagesIcE7do_openERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERKNS_6localeE
// EN: AArch64 prologue [mov x0, #-1; ret] | VI: Khởi đầu hàm AArch64 [mov x0, #-1; ret]
uint64_t fde_sub_08cebc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x92800000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08CEBCULL;
}

// FDE #1019 | PC: 0x08cec4..0x08ced0 (12 B) | Symbol: _ZNKSt6__ndk18messagesIcE6do_getEliiRKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE
// EN: AArch64 prologue [mov x1, x4; mov x0, x8; b #0x48580] | VI: Khởi đầu hàm AArch64 [mov x1, x4; mov x0, x8; b #0x48580]
uint64_t fde_sub_08cec4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0xAA0403E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08CEC4ULL;
}

// FDE #1020 | PC: 0x08ced0..0x08ced4 (4 B) | Symbol: _ZNKSt6__ndk18messagesIcE8do_closeEl
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_08ced0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x92800000ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08CED0ULL;
}

// FDE #1021 | PC: 0x08ced4..0x08cedc (8 B) | Symbol: _ZNKSt6__ndk18messagesIwE7do_openERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERKNS_6localeE
// EN: AArch64 prologue [mov x0, #-1; ret] | VI: Khởi đầu hàm AArch64 [mov x0, #-1; ret]
uint64_t fde_sub_08ced4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x92800000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08CED4ULL;
}

// FDE #1022 | PC: 0x08cedc..0x08cee8 (12 B) | Symbol: _ZNKSt6__ndk18messagesIwE6do_getEliiRKNS_12basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEEE
// EN: AArch64 prologue [mov x1, x4; mov x0, x8; b #0x47e90] | VI: Khởi đầu hàm AArch64 [mov x1, x4; mov x0, x8; b #0x47e90]
uint64_t fde_sub_08cedc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0xAA0403E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08CEDCULL;
}

// FDE #1023 | PC: 0x08cee8..0x08ceec (4 B) | Symbol: _ZNKSt6__ndk18messagesIwE8do_closeEl
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_08cee8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEEC25ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08CEE8ULL;
}

// FDE #1024 | PC: 0x08ceec..0x08cef0 (4 B) | Symbol: _ZNSt6__ndk114codecvt_bynameIcc9mbstate_tED2Ev
// EN: AArch64 prologue [b #0x47f80] | VI: Khởi đầu hàm AArch64 [b #0x47f80]
uint64_t fde_sub_08ceec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0x17FEEC25ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08CEECULL;
}

// FDE #1025 | PC: 0x08cef0..0x08cf14 (36 B) | Symbol: _ZNSt6__ndk114codecvt_bynameIcc9mbstate_tED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08cef0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08CEF0ULL;
}

// FDE #1026 | PC: 0x08cf14..0x08cf18 (4 B) | Symbol: _ZNSt6__ndk114codecvt_bynameIwc9mbstate_tED1Ev
// EN: AArch64 prologue [b #0x47300] | VI: Khởi đầu hàm AArch64 [b #0x47300]
uint64_t fde_sub_08cf14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0x17FEE8FBULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08CF14ULL;
}

// FDE #1027 | PC: 0x08cf18..0x08cf3c (36 B) | Symbol: _ZNSt6__ndk114codecvt_bynameIwc9mbstate_tED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08cf18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08CF18ULL;
}

// FDE #1028 | PC: 0x08cf3c..0x08cf40 (4 B) | Symbol: _ZNSt6__ndk114codecvt_bynameIDsc9mbstate_tED2Ev
// EN: AArch64 prologue [b #0x47f80] | VI: Khởi đầu hàm AArch64 [b #0x47f80]
uint64_t fde_sub_08cf3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0x17FEEC11ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08CF3CULL;
}

// FDE #1029 | PC: 0x08cf40..0x08cf64 (36 B) | Symbol: _ZNSt6__ndk114codecvt_bynameIDsc9mbstate_tED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08cf40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08CF40ULL;
}

// FDE #1030 | PC: 0x08cf64..0x08cf68 (4 B) | Symbol: _ZNSt6__ndk114codecvt_bynameIDic9mbstate_tED2Ev
// EN: AArch64 prologue [b #0x47f80] | VI: Khởi đầu hàm AArch64 [b #0x47f80]
uint64_t fde_sub_08cf64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0x17FEEC07ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08CF64ULL;
}

// FDE #1031 | PC: 0x08cf68..0x08cf8c (36 B) | Symbol: _ZNSt6__ndk114codecvt_bynameIDic9mbstate_tED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08cf68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08CF68ULL;
}

// FDE #1032 | PC: 0x08cf8c..0x08d0bc (304 B) | Symbol: sub_08cf8c
// EN: AArch64 prologue [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_08cf8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF7ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08CF8CULL;
}

// FDE #1033 | PC: 0x08d0bc..0x08d1ec (304 B) | Symbol: sub_08d0bc
// EN: AArch64 prologue [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_08d0bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF7ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D0BCULL;
}

// FDE #1034 | PC: 0x08d1ec..0x08d31c (304 B) | Symbol: sub_08d1ec
// EN: AArch64 prologue [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_08d1ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF7ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D1ECULL;
}

// FDE #1035 | PC: 0x08d31c..0x08d44c (304 B) | Symbol: sub_08d31c
// EN: AArch64 prologue [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_08d31c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF7ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D31CULL;
}

// FDE #1036 | PC: 0x08d44c..0x08d57c (304 B) | Symbol: sub_08d44c
// EN: AArch64 prologue [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_08d44c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF7ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D44CULL;
}

// FDE #1037 | PC: 0x08d57c..0x08d6ac (304 B) | Symbol: sub_08d57c
// EN: AArch64 prologue [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_08d57c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF7ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D57CULL;
}

// FDE #1038 | PC: 0x08d6ac..0x08d7dc (304 B) | Symbol: sub_08d6ac
// EN: AArch64 prologue [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_08d6ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF7ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D6ACULL;
}

// FDE #1039 | PC: 0x08d7dc..0x08d90c (304 B) | Symbol: sub_08d7dc
// EN: AArch64 prologue [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_08d7dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF7ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D7DCULL;
}

// FDE #1040 | PC: 0x08d90c..0x08da3c (304 B) | Symbol: sub_08d90c
// EN: AArch64 prologue [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_08d90c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF7ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D90CULL;
}

// FDE #1041 | PC: 0x08da3c..0x08db6c (304 B) | Symbol: sub_08da3c
// EN: AArch64 prologue [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_08da3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF7ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DA3CULL;
}

// FDE #1042 | PC: 0x08db6c..0x08dc9c (304 B) | Symbol: sub_08db6c
// EN: AArch64 prologue [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_08db6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF7ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DB6CULL;
}

// FDE #1043 | PC: 0x08dc9c..0x08dd78 (220 B) | Symbol: sub_08dc9c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_08dc9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DC9CULL;
}

// FDE #1044 | PC: 0x08dd78..0x08dea8 (304 B) | Symbol: sub_08dd78
// EN: AArch64 prologue [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_08dd78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF7ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DD78ULL;
}

// FDE #1045 | PC: 0x08dea8..0x08df84 (220 B) | Symbol: sub_08dea8
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_08dea8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DEA8ULL;
}

// FDE #1046 | PC: 0x08df84..0x08e0b4 (304 B) | Symbol: sub_08df84
// EN: AArch64 prologue [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_08df84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF7ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DF84ULL;
}

// FDE #1047 | PC: 0x08e0b4..0x08e190 (220 B) | Symbol: sub_08e0b4
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_08e0b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E0B4ULL;
}

// FDE #1048 | PC: 0x08e190..0x08e2c0 (304 B) | Symbol: sub_08e190
// EN: AArch64 prologue [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_08e190(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF7ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E190ULL;
}

// FDE #1049 | PC: 0x08e2c0..0x08e39c (220 B) | Symbol: sub_08e2c0
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_08e2c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E2C0ULL;
}

// FDE #1050 | PC: 0x08e39c..0x08e4cc (304 B) | Symbol: sub_08e39c
// EN: AArch64 prologue [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_08e39c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF7ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E39CULL;
}

// FDE #1051 | PC: 0x08e4cc..0x08e5fc (304 B) | Symbol: sub_08e4cc
// EN: AArch64 prologue [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_08e4cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF7ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E4CCULL;
}

// FDE #1052 | PC: 0x08e5fc..0x08e72c (304 B) | Symbol: sub_08e5fc
// EN: AArch64 prologue [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_08e5fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF7ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E5FCULL;
}

// FDE #1053 | PC: 0x08e72c..0x08e85c (304 B) | Symbol: sub_08e72c
// EN: AArch64 prologue [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_08e72c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF7ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E72CULL;
}

// FDE #1054 | PC: 0x08e85c..0x08e98c (304 B) | Symbol: sub_08e85c
// EN: AArch64 prologue [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_08e85c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF7ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E85CULL;
}

// FDE #1055 | PC: 0x08e98c..0x08eabc (304 B) | Symbol: sub_08e98c
// EN: AArch64 prologue [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_08e98c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF7ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08E98CULL;
}

// FDE #1056 | PC: 0x08eabc..0x08eaf0 (52 B) | Symbol: sub_08eabc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w0, #8] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w0, #8]
uint64_t fde_sub_08eabc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EABCULL;
}

// FDE #1057 | PC: 0x08eaf0..0x08eaf4 (4 B) | Symbol: sub_08eaf0
// EN: AArch64 prologue [b #0x47740] | VI: Khởi đầu hàm AArch64 [b #0x47740]
uint64_t fde_sub_08eaf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE3AFULL) << 32) | 0x17FEE314ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EAF0ULL;
}

// FDE #1058 | PC: 0x08eaf4..0x08eaf8 (4 B) | Symbol: sub_08eaf4
// EN: AArch64 prologue [b #0x479b0] | VI: Khởi đầu hàm AArch64 [b #0x479b0]
uint64_t fde_sub_08eaf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE252ULL) << 32) | 0x17FEE3AFULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EAF4ULL;
}

// FDE #1059 | PC: 0x08eaf8..0x08eafc (4 B) | Symbol: sub_08eaf8
// EN: AArch64 prologue [b #0x47440] | VI: Khởi đầu hàm AArch64 [b #0x47440]
uint64_t fde_sub_08eaf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE25DULL) << 32) | 0x17FEE252ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EAF8ULL;
}

// FDE #1060 | PC: 0x08eafc..0x08eb00 (4 B) | Symbol: sub_08eafc
// EN: AArch64 prologue [b #0x47470] | VI: Khởi đầu hàm AArch64 [b #0x47470]
uint64_t fde_sub_08eafc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE5E8ULL) << 32) | 0x17FEE25DULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EAFCULL;
}

// FDE #1061 | PC: 0x08eb00..0x08eb04 (4 B) | Symbol: sub_08eb00
// EN: AArch64 prologue [b #0x482a0] | VI: Khởi đầu hàm AArch64 [b #0x482a0]
uint64_t fde_sub_08eb00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE317ULL) << 32) | 0x17FEE5E8ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EB00ULL;
}

// FDE #1062 | PC: 0x08eb04..0x08eb08 (4 B) | Symbol: sub_08eb04
// EN: AArch64 prologue [b #0x47760] | VI: Khởi đầu hàm AArch64 [b #0x47760]
uint64_t fde_sub_08eb04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE31AULL) << 32) | 0x17FEE317ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EB04ULL;
}

// FDE #1063 | PC: 0x08eb08..0x08eb0c (4 B) | Symbol: sub_08eb08
// EN: AArch64 prologue [b #0x47770] | VI: Khởi đầu hàm AArch64 [b #0x47770]
uint64_t fde_sub_08eb08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE321ULL) << 32) | 0x17FEE31AULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EB08ULL;
}

// FDE #1064 | PC: 0x08eb0c..0x08eb10 (4 B) | Symbol: sub_08eb0c
// EN: AArch64 prologue [b #0x47790] | VI: Khởi đầu hàm AArch64 [b #0x47790]
uint64_t fde_sub_08eb0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE4A8ULL) << 32) | 0x17FEE321ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EB0CULL;
}

// FDE #1065 | PC: 0x08eb10..0x08eb14 (4 B) | Symbol: sub_08eb10
// EN: AArch64 prologue [b #0x47db0] | VI: Khởi đầu hàm AArch64 [b #0x47db0]
uint64_t fde_sub_08eb10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE67FULL) << 32) | 0x17FEE4A8ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EB10ULL;
}

// FDE #1066 | PC: 0x08eb14..0x08eb18 (4 B) | Symbol: sub_08eb14
// EN: AArch64 prologue [b #0x48510] | VI: Khởi đầu hàm AArch64 [b #0x48510]
uint64_t fde_sub_08eb14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE5C2ULL) << 32) | 0x17FEE67FULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EB14ULL;
}

// FDE #1067 | PC: 0x08eb18..0x08eb1c (4 B) | Symbol: sub_08eb18
// EN: AArch64 prologue [b #0x48220] | VI: Khởi đầu hàm AArch64 [b #0x48220]
uint64_t fde_sub_08eb18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE1A9ULL) << 32) | 0x17FEE5C2ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EB18ULL;
}

// FDE #1068 | PC: 0x08eb1c..0x08eb20 (4 B) | Symbol: sub_08eb1c
// EN: AArch64 prologue [b #0x471c0] | VI: Khởi đầu hàm AArch64 [b #0x471c0]
uint64_t fde_sub_08eb1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE378ULL) << 32) | 0x17FEE1A9ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EB1CULL;
}

// FDE #1069 | PC: 0x08eb20..0x08eb24 (4 B) | Symbol: sub_08eb20
// EN: AArch64 prologue [b #0x47900] | VI: Khởi đầu hàm AArch64 [b #0x47900]
uint64_t fde_sub_08eb20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE627ULL) << 32) | 0x17FEE378ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EB20ULL;
}

// FDE #1070 | PC: 0x08eb24..0x08eb28 (4 B) | Symbol: sub_08eb24
// EN: AArch64 prologue [b #0x483c0] | VI: Khởi đầu hàm AArch64 [b #0x483c0]
uint64_t fde_sub_08eb24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE26EULL) << 32) | 0x17FEE627ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EB24ULL;
}

// FDE #1071 | PC: 0x08eb28..0x08eb2c (4 B) | Symbol: sub_08eb28
// EN: AArch64 prologue [b #0x474e0] | VI: Khởi đầu hàm AArch64 [b #0x474e0]
uint64_t fde_sub_08eb28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE209ULL) << 32) | 0x17FEE26EULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EB28ULL;
}

// FDE #1072 | PC: 0x08eb2c..0x08eb30 (4 B) | Symbol: sub_08eb2c
// EN: AArch64 prologue [b #0x47350] | VI: Khởi đầu hàm AArch64 [b #0x47350]
uint64_t fde_sub_08eb2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE6E8ULL) << 32) | 0x17FEE209ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EB2CULL;
}

// FDE #1073 | PC: 0x08eb30..0x08eb34 (4 B) | Symbol: sub_08eb30
// EN: AArch64 prologue [b #0x486d0] | VI: Khởi đầu hàm AArch64 [b #0x486d0]
uint64_t fde_sub_08eb30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE497ULL) << 32) | 0x17FEE6E8ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EB30ULL;
}

// FDE #1074 | PC: 0x08eb34..0x08eb38 (4 B) | Symbol: sub_08eb34
// EN: AArch64 prologue [b #0x47d90] | VI: Khởi đầu hàm AArch64 [b #0x47d90]
uint64_t fde_sub_08eb34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE5A2ULL) << 32) | 0x17FEE497ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EB34ULL;
}

// FDE #1075 | PC: 0x08eb38..0x08eb3c (4 B) | Symbol: sub_08eb38
// EN: AArch64 prologue [b #0x481c0] | VI: Khởi đầu hàm AArch64 [b #0x481c0]
uint64_t fde_sub_08eb38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE6C9ULL) << 32) | 0x17FEE5A2ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EB38ULL;
}

// FDE #1076 | PC: 0x08eb3c..0x08eb40 (4 B) | Symbol: sub_08eb3c
// EN: AArch64 prologue [b #0x48660] | VI: Khởi đầu hàm AArch64 [b #0x48660]
uint64_t fde_sub_08eb3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD57F6ULL) << 32) | 0x17FEE6C9ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EB3CULL;
}

// FDE #1077 | PC: 0x08eb40..0x08ebf4 (180 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEEC2IDnEEPKw
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_08eb40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EB40ULL;
}

// FDE #1078 | PC: 0x08ebf4..0x08ebf8 (4 B) | Symbol: sub_08ebf4
// EN: AArch64 prologue [b #0x47b50] | VI: Khởi đầu hàm AArch64 [b #0x47b50]
uint64_t fde_sub_08ebf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10443FFULL) << 32) | 0x17FEE3D7ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EBF4ULL;
}

// FDE #1079 | PC: 0x08ebf8..0x08ef50 (856 B) | Symbol: sub_08ebf8
// EN: AArch64 prologue [sub sp, sp, #0x110; stp x28, x27, [sp, #0xb0]; stp x26, x25, [sp, #0xc0]; stp x24, x23, [sp, #0xd0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; stp x28, x27, [sp, #0xb0]; stp x26, x25, [sp, #0xc0]; stp x24, x23, [sp, #0xd0]]
uint64_t fde_sub_08ebf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90B6FFCULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x0358ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EBF8ULL;
}

// FDE #1080 | PC: 0x08ef50..0x08f2a4 (852 B) | Symbol: sub_08ef50
// EN: AArch64 prologue [sub sp, sp, #0x110; stp x28, x27, [sp, #0xb0]; stp x26, x25, [sp, #0xc0]; stp x24, x23, [sp, #0xd0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; stp x28, x27, [sp, #0xb0]; stp x26, x25, [sp, #0xc0]; stp x24, x23, [sp, #0xd0]]
uint64_t fde_sub_08ef50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90B6FFCULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x0354ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08EF50ULL;
}

// FDE #1081 | PC: 0x08f2a4..0x08f2c8 (36 B) | Symbol: _ZNSt6__ndk114__codecvt_utf8IwED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f2a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F2A4ULL;
}

// FDE #1082 | PC: 0x08f2c8..0x08f2ec (36 B) | Symbol: _ZNSt6__ndk114__codecvt_utf8IDsED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f2c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F2C8ULL;
}

// FDE #1083 | PC: 0x08f2ec..0x08f310 (36 B) | Symbol: _ZNSt6__ndk114__codecvt_utf8IDiED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f2ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F2ECULL;
}

// FDE #1084 | PC: 0x08f310..0x08f334 (36 B) | Symbol: _ZNSt6__ndk115__codecvt_utf16IwLb0EED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f310(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F310ULL;
}

// FDE #1085 | PC: 0x08f334..0x08f358 (36 B) | Symbol: _ZNSt6__ndk115__codecvt_utf16IwLb1EED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f334(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F334ULL;
}

// FDE #1086 | PC: 0x08f358..0x08f37c (36 B) | Symbol: _ZNSt6__ndk115__codecvt_utf16IDsLb0EED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f358(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F358ULL;
}

// FDE #1087 | PC: 0x08f37c..0x08f3a0 (36 B) | Symbol: _ZNSt6__ndk115__codecvt_utf16IDsLb1EED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f37c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F37CULL;
}

// FDE #1088 | PC: 0x08f3a0..0x08f3c4 (36 B) | Symbol: _ZNSt6__ndk115__codecvt_utf16IDiLb0EED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f3a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F3A0ULL;
}

// FDE #1089 | PC: 0x08f3c4..0x08f3e8 (36 B) | Symbol: _ZNSt6__ndk115__codecvt_utf16IDiLb1EED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f3c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F3C4ULL;
}

// FDE #1090 | PC: 0x08f3e8..0x08f40c (36 B) | Symbol: _ZNSt6__ndk120__codecvt_utf8_utf16IwED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f3e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F3E8ULL;
}

// FDE #1091 | PC: 0x08f40c..0x08f430 (36 B) | Symbol: _ZNSt6__ndk120__codecvt_utf8_utf16IDiED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f40c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F40CULL;
}

// FDE #1092 | PC: 0x08f430..0x08f454 (36 B) | Symbol: _ZNSt6__ndk120__codecvt_utf8_utf16IDsED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f430(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F430ULL;
}

// FDE #1093 | PC: 0x08f454..0x08f478 (36 B) | Symbol: sub_08f454
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f454(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F454ULL;
}

// FDE #1094 | PC: 0x08f478..0x08f49c (36 B) | Symbol: sub_08f478
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f478(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F478ULL;
}

// FDE #1095 | PC: 0x08f49c..0x08f4c0 (36 B) | Symbol: sub_08f49c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f49c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F49CULL;
}

// FDE #1096 | PC: 0x08f4c0..0x08f4e4 (36 B) | Symbol: sub_08f4c0
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f4c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F4C0ULL;
}

// FDE #1097 | PC: 0x08f4e4..0x08f4e8 (4 B) | Symbol: sub_08f4e4
// EN: AArch64 prologue [b #0x47f80] | VI: Khởi đầu hàm AArch64 [b #0x47f80]
uint64_t fde_sub_08f4e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0x17FEE2A7ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F4E4ULL;
}

// FDE #1098 | PC: 0x08f4e8..0x08f50c (36 B) | Symbol: sub_08f4e8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f4e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F4E8ULL;
}

// FDE #1099 | PC: 0x08f50c..0x08f510 (4 B) | Symbol: sub_08f50c
// EN: AArch64 prologue [b #0x47f80] | VI: Khởi đầu hàm AArch64 [b #0x47f80]
uint64_t fde_sub_08f50c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0x17FEE29DULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F50CULL;
}

// FDE #1100 | PC: 0x08f510..0x08f534 (36 B) | Symbol: sub_08f510
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f510(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F510ULL;
}

// FDE #1101 | PC: 0x08f534..0x08f55c (40 B) | Symbol: sub_08f534
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f534(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F534ULL;
}

// FDE #1102 | PC: 0x08f55c..0x08f58c (48 B) | Symbol: sub_08f55c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f55c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F55CULL;
}

// FDE #1103 | PC: 0x08f58c..0x08f594 (8 B) | Symbol: sub_08f58c
// EN: AArch64 prologue [add x0, x0, #0x18; b #0x48140] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x18; b #0x48140]
uint64_t fde_sub_08f58c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE2ECULL) << 32) | 0x91006000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F58CULL;
}

// FDE #1104 | PC: 0x08f594..0x08f59c (8 B) | Symbol: sub_08f594
// EN: AArch64 prologue [add x0, x0, #0x20; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x20; ret]
uint64_t fde_sub_08f594(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x91008000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F594ULL;
}

// FDE #1105 | PC: 0x08f59c..0x08f5a4 (8 B) | Symbol: sub_08f59c
// EN: AArch64 prologue [add x0, x0, #0x170; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x170; ret]
uint64_t fde_sub_08f59c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x9105C000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F59CULL;
}

// FDE #1106 | PC: 0x08f5a4..0x08f5ac (8 B) | Symbol: sub_08f5a4
// EN: AArch64 prologue [add x0, x0, #0x3b0; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x3b0; ret]
uint64_t fde_sub_08f5a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910EC000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F5A4ULL;
}

// FDE #1107 | PC: 0x08f5ac..0x08f5b4 (8 B) | Symbol: sub_08f5ac
// EN: AArch64 prologue [add x0, x0, #0x3e0; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x3e0; ret]
uint64_t fde_sub_08f5ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910F8000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F5ACULL;
}

// FDE #1108 | PC: 0x08f5b4..0x08f5bc (8 B) | Symbol: sub_08f5b4
// EN: AArch64 prologue [add x0, x0, #0x3f8; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x3f8; ret]
uint64_t fde_sub_08f5b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910FE000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F5B4ULL;
}

// FDE #1109 | PC: 0x08f5bc..0x08f5c4 (8 B) | Symbol: sub_08f5bc
// EN: AArch64 prologue [add x0, x0, #0x410; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x410; ret]
uint64_t fde_sub_08f5bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x91104000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F5BCULL;
}

// FDE #1110 | PC: 0x08f5c4..0x08f5cc (8 B) | Symbol: sub_08f5c4
// EN: AArch64 prologue [add x0, x0, #0x428; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x428; ret]
uint64_t fde_sub_08f5c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x9110A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F5C4ULL;
}

// FDE #1111 | PC: 0x08f5cc..0x08f5d4 (8 B) | Symbol: sub_08f5cc
// EN: AArch64 prologue [add x0, x0, #0x10; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x10; ret]
uint64_t fde_sub_08f5cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x91004000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F5CCULL;
}

// FDE #1112 | PC: 0x08f5d4..0x08f5dc (8 B) | Symbol: sub_08f5d4
// EN: AArch64 prologue [add x0, x0, #0x160; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x160; ret]
uint64_t fde_sub_08f5d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x91058000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F5D4ULL;
}

// FDE #1113 | PC: 0x08f5dc..0x08f5e4 (8 B) | Symbol: sub_08f5dc
// EN: AArch64 prologue [add x0, x0, #0x3a0; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x3a0; ret]
uint64_t fde_sub_08f5dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910E8000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F5DCULL;
}

// FDE #1114 | PC: 0x08f5e4..0x08f5ec (8 B) | Symbol: sub_08f5e4
// EN: AArch64 prologue [add x0, x0, #0x3d0; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x3d0; ret]
uint64_t fde_sub_08f5e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910F4000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F5E4ULL;
}

// FDE #1115 | PC: 0x08f5ec..0x08f5f4 (8 B) | Symbol: sub_08f5ec
// EN: AArch64 prologue [add x0, x0, #0x3e8; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x3e8; ret]
uint64_t fde_sub_08f5ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910FA000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F5ECULL;
}

// FDE #1116 | PC: 0x08f5f4..0x08f5fc (8 B) | Symbol: sub_08f5f4
// EN: AArch64 prologue [add x0, x0, #0x400; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x400; ret]
uint64_t fde_sub_08f5f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x91100000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F5F4ULL;
}

// FDE #1117 | PC: 0x08f5fc..0x08f604 (8 B) | Symbol: sub_08f5fc
// EN: AArch64 prologue [add x0, x0, #0x418; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x418; ret]
uint64_t fde_sub_08f5fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x91106000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F5FCULL;
}

// FDE #1118 | PC: 0x08f604..0x08f62c (40 B) | Symbol: sub_08f604
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f604(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F604ULL;
}

// FDE #1119 | PC: 0x08f62c..0x08f65c (48 B) | Symbol: sub_08f62c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f62c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F62CULL;
}

// FDE #1120 | PC: 0x08f65c..0x08f664 (8 B) | Symbol: sub_08f65c
// EN: AArch64 prologue [add x0, x0, #0x18; b #0x47c20] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x18; b #0x47c20]
uint64_t fde_sub_08f65c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEE170ULL) << 32) | 0x91006000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F65CULL;
}

// FDE #1121 | PC: 0x08f664..0x08f66c (8 B) | Symbol: sub_08f664
// EN: AArch64 prologue [add x0, x0, #0x20; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x20; ret]
uint64_t fde_sub_08f664(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x91008000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F664ULL;
}

// FDE #1122 | PC: 0x08f66c..0x08f674 (8 B) | Symbol: sub_08f66c
// EN: AArch64 prologue [add x0, x0, #0x170; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x170; ret]
uint64_t fde_sub_08f66c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x9105C000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F66CULL;
}

// FDE #1123 | PC: 0x08f674..0x08f67c (8 B) | Symbol: sub_08f674
// EN: AArch64 prologue [add x0, x0, #0x3b0; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x3b0; ret]
uint64_t fde_sub_08f674(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910EC000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F674ULL;
}

// FDE #1124 | PC: 0x08f67c..0x08f684 (8 B) | Symbol: sub_08f67c
// EN: AArch64 prologue [add x0, x0, #0x3e0; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x3e0; ret]
uint64_t fde_sub_08f67c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910F8000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F67CULL;
}

// FDE #1125 | PC: 0x08f684..0x08f68c (8 B) | Symbol: sub_08f684
// EN: AArch64 prologue [add x0, x0, #0x3f8; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x3f8; ret]
uint64_t fde_sub_08f684(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910FE000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F684ULL;
}

// FDE #1126 | PC: 0x08f68c..0x08f694 (8 B) | Symbol: sub_08f68c
// EN: AArch64 prologue [add x0, x0, #0x410; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x410; ret]
uint64_t fde_sub_08f68c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x91104000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F68CULL;
}

// FDE #1127 | PC: 0x08f694..0x08f69c (8 B) | Symbol: sub_08f694
// EN: AArch64 prologue [add x0, x0, #0x428; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x428; ret]
uint64_t fde_sub_08f694(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x9110A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F694ULL;
}

// FDE #1128 | PC: 0x08f69c..0x08f6a4 (8 B) | Symbol: sub_08f69c
// EN: AArch64 prologue [add x0, x0, #0x10; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x10; ret]
uint64_t fde_sub_08f69c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x91004000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F69CULL;
}

// FDE #1129 | PC: 0x08f6a4..0x08f6ac (8 B) | Symbol: sub_08f6a4
// EN: AArch64 prologue [add x0, x0, #0x160; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x160; ret]
uint64_t fde_sub_08f6a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x91058000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F6A4ULL;
}

// FDE #1130 | PC: 0x08f6ac..0x08f6b4 (8 B) | Symbol: sub_08f6ac
// EN: AArch64 prologue [add x0, x0, #0x3a0; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x3a0; ret]
uint64_t fde_sub_08f6ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910E8000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F6ACULL;
}

// FDE #1131 | PC: 0x08f6b4..0x08f6bc (8 B) | Symbol: sub_08f6b4
// EN: AArch64 prologue [add x0, x0, #0x3d0; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x3d0; ret]
uint64_t fde_sub_08f6b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910F4000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F6B4ULL;
}

// FDE #1132 | PC: 0x08f6bc..0x08f6c4 (8 B) | Symbol: sub_08f6bc
// EN: AArch64 prologue [add x0, x0, #0x3e8; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x3e8; ret]
uint64_t fde_sub_08f6bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910FA000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F6BCULL;
}

// FDE #1133 | PC: 0x08f6c4..0x08f6cc (8 B) | Symbol: sub_08f6c4
// EN: AArch64 prologue [add x0, x0, #0x400; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x400; ret]
uint64_t fde_sub_08f6c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x91100000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F6C4ULL;
}

// FDE #1134 | PC: 0x08f6cc..0x08f6d4 (8 B) | Symbol: sub_08f6cc
// EN: AArch64 prologue [add x0, x0, #0x418; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x418; ret]
uint64_t fde_sub_08f6cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x91106000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F6CCULL;
}

// FDE #1135 | PC: 0x08f6d4..0x08f704 (48 B) | Symbol: sub_08f6d4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f6d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F6D4ULL;
}

// FDE #1136 | PC: 0x08f704..0x08f72c (40 B) | Symbol: sub_08f704
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f704(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F704ULL;
}

// FDE #1137 | PC: 0x08f72c..0x08f75c (48 B) | Symbol: sub_08f72c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f72c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F72CULL;
}

// FDE #1138 | PC: 0x08f75c..0x08f784 (40 B) | Symbol: sub_08f75c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f75c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F75CULL;
}

// FDE #1139 | PC: 0x08f784..0x08f7b4 (48 B) | Symbol: sub_08f784
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f784(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F784ULL;
}

// FDE #1140 | PC: 0x08f7b4..0x08f7e4 (48 B) | Symbol: sub_08f7b4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f7b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F7B4ULL;
}

// FDE #1141 | PC: 0x08f7e4..0x08f808 (36 B) | Symbol: sub_08f7e4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f7e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F7E4ULL;
}

// FDE #1142 | PC: 0x08f808..0x08f82c (36 B) | Symbol: sub_08f808
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f808(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F808ULL;
}

// FDE #1143 | PC: 0x08f82c..0x08f850 (36 B) | Symbol: sub_08f82c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f82c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F82CULL;
}

// FDE #1144 | PC: 0x08f850..0x08f874 (36 B) | Symbol: sub_08f850
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f850(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F850ULL;
}

// FDE #1145 | PC: 0x08f874..0x08f900 (140 B) | Symbol: sub_08f874
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000]
uint64_t fde_sub_08f874(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F874ULL;
}

// FDE #1146 | PC: 0x08f900..0x08f924 (36 B) | Symbol: sub_08f900
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f900(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F900ULL;
}

// FDE #1147 | PC: 0x08f924..0x08f9b0 (140 B) | Symbol: sub_08f924
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000]
uint64_t fde_sub_08f924(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F924ULL;
}

// FDE #1148 | PC: 0x08f9b0..0x08f9d4 (36 B) | Symbol: sub_08f9b0
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08f9b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F9B0ULL;
}

// FDE #1149 | PC: 0x08f9d4..0x08fa60 (140 B) | Symbol: sub_08f9d4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000]
uint64_t fde_sub_08f9d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F9D4ULL;
}

// FDE #1150 | PC: 0x08fa60..0x08fa84 (36 B) | Symbol: sub_08fa60
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08fa60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FA60ULL;
}

// FDE #1151 | PC: 0x08fa84..0x08fb10 (140 B) | Symbol: sub_08fa84
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000]
uint64_t fde_sub_08fa84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FA84ULL;
}

// FDE #1152 | PC: 0x08fb10..0x08fb34 (36 B) | Symbol: sub_08fb10
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08fb10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FB10ULL;
}

// FDE #1153 | PC: 0x08fb34..0x08fb58 (36 B) | Symbol: sub_08fb34
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08fb34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FB34ULL;
}

// FDE #1154 | PC: 0x08fb58..0x08fb7c (36 B) | Symbol: sub_08fb58
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08fb58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FB58ULL;
}

// FDE #1155 | PC: 0x08fb7c..0x08fba0 (36 B) | Symbol: sub_08fb7c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08fb7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FB7CULL;
}

// FDE #1156 | PC: 0x08fba0..0x08fbc4 (36 B) | Symbol: sub_08fba0
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08fba0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FBA0ULL;
}

// FDE #1157 | PC: 0x08fbc4..0x08fbe8 (36 B) | Symbol: sub_08fbc4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08fbc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FBC4ULL;
}

// FDE #1158 | PC: 0x08fbe8..0x08fc0c (36 B) | Symbol: sub_08fbe8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08fbe8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FBE8ULL;
}

// FDE #1159 | PC: 0x08fc0c..0x08fc30 (36 B) | Symbol: sub_08fc0c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08fc0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FC0CULL;
}

// FDE #1160 | PC: 0x08fc30..0x08fc54 (36 B) | Symbol: sub_08fc30
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_08fc30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FC30ULL;
}

// FDE #1161 | PC: 0x08fc54..0x08fde0 (396 B) | Symbol: sub_08fc54
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_08fc54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x018CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FC54ULL;
}

// FDE #1162 | PC: 0x08fde0..0x08ff24 (324 B) | Symbol: sub_08fde0
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_08fde0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0144ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FDE0ULL;
}

// FDE #1163 | PC: 0x08ff24..0x08ff9c (120 B) | Symbol: sub_08ff24
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_08ff24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FF24ULL;
}

// FDE #1164 | PC: 0x08ff9c..0x08fff0 (84 B) | Symbol: sub_08ff9c
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_08ff9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FF9CULL;
}

// FDE #1165 | PC: 0x08fff0..0x090184 (404 B) | Symbol: sub_08fff0
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_08fff0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0194ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08FFF0ULL;
}

// FDE #1166 | PC: 0x090184..0x090354 (464 B) | Symbol: sub_090184
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_090184(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x01D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090184ULL;
}

// FDE #1167 | PC: 0x090354..0x090490 (316 B) | Symbol: sub_090354
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_090354(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x013CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090354ULL;
}

// FDE #1168 | PC: 0x090490..0x0905cc (316 B) | Symbol: sub_090490
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_090490(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x013CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090490ULL;
}

// FDE #1169 | PC: 0x0905cc..0x090734 (360 B) | Symbol: sub_0905cc
// EN: AArch64 prologue [sub sp, sp, #0x70; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_0905cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BFBULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0168ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0905CCULL;
}

// FDE #1170 | PC: 0x090734..0x09089c (360 B) | Symbol: sub_090734
// EN: AArch64 prologue [sub sp, sp, #0x70; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_090734(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BFBULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0168ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090734ULL;
}

// FDE #1171 | PC: 0x09089c..0x0909fc (352 B) | Symbol: sub_09089c
// EN: AArch64 prologue [sub sp, sp, #0x70; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_09089c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BFBULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0160ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09089CULL;
}

// FDE #1172 | PC: 0x0909fc..0x090b5c (352 B) | Symbol: sub_0909fc
// EN: AArch64 prologue [sub sp, sp, #0x70; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_0909fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BFBULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0160ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0909FCULL;
}

uint64_t DispatchCxxSharedShard3(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x074f74ULL: return fde_sub_074f74(a0, a1, a2);
        case 0x075390ULL: return fde_sub_075390(a0, a1, a2);
        case 0x0757a4ULL: return fde_sub_0757a4(a0, a1, a2);
        case 0x075bc0ULL: return fde_sub_075bc0(a0, a1, a2);
        case 0x0763b8ULL: return fde_sub_0763b8(a0, a1, a2);
        case 0x0767dcULL: return fde_sub_0767dc(a0, a1, a2);
        case 0x076fd4ULL: return fde_sub_076fd4(a0, a1, a2);
        case 0x077098ULL: return fde_sub_077098(a0, a1, a2);
        case 0x07709cULL: return fde_sub_07709c(a0, a1, a2);
        case 0x0770c0ULL: return fde_sub_0770c0(a0, a1, a2);
        case 0x0770c4ULL: return fde_sub_0770c4(a0, a1, a2);
        case 0x0770e8ULL: return fde_sub_0770e8(a0, a1, a2);
        case 0x07713cULL: return fde_sub_07713c(a0, a1, a2);
        case 0x07722cULL: return fde_sub_07722c(a0, a1, a2);
        case 0x077260ULL: return fde_sub_077260(a0, a1, a2);
        case 0x077264ULL: return fde_sub_077264(a0, a1, a2);
        case 0x077288ULL: return fde_sub_077288(a0, a1, a2);
        case 0x0772dcULL: return fde_sub_0772dc(a0, a1, a2);
        case 0x0773f8ULL: return fde_sub_0773f8(a0, a1, a2);
        case 0x07742cULL: return fde_sub_07742c(a0, a1, a2);
        case 0x0776f4ULL: return fde_sub_0776f4(a0, a1, a2);
        case 0x077ba0ULL: return fde_sub_077ba0(a0, a1, a2);
        case 0x077ba4ULL: return fde_sub_077ba4(a0, a1, a2);
        case 0x077f48ULL: return fde_sub_077f48(a0, a1, a2);
        case 0x077f4cULL: return fde_sub_077f4c(a0, a1, a2);
        case 0x0782f0ULL: return fde_sub_0782f0(a0, a1, a2);
        case 0x0782f4ULL: return fde_sub_0782f4(a0, a1, a2);
        case 0x078698ULL: return fde_sub_078698(a0, a1, a2);
        case 0x07869cULL: return fde_sub_07869c(a0, a1, a2);
        case 0x078a40ULL: return fde_sub_078a40(a0, a1, a2);
        case 0x078a44ULL: return fde_sub_078a44(a0, a1, a2);
        case 0x078de8ULL: return fde_sub_078de8(a0, a1, a2);
        case 0x078decULL: return fde_sub_078dec(a0, a1, a2);
        case 0x079190ULL: return fde_sub_079190(a0, a1, a2);
        case 0x079194ULL: return fde_sub_079194(a0, a1, a2);
        case 0x079520ULL: return fde_sub_079520(a0, a1, a2);
        case 0x079524ULL: return fde_sub_079524(a0, a1, a2);
        case 0x0798b0ULL: return fde_sub_0798b0(a0, a1, a2);
        case 0x0798b4ULL: return fde_sub_0798b4(a0, a1, a2);
        case 0x079c40ULL: return fde_sub_079c40(a0, a1, a2);
        case 0x07a0b8ULL: return fde_sub_07a0b8(a0, a1, a2);
        case 0x07a424ULL: return fde_sub_07a424(a0, a1, a2);
        case 0x07a4fcULL: return fde_sub_07a4fc(a0, a1, a2);
        case 0x07a7c4ULL: return fde_sub_07a7c4(a0, a1, a2);
        case 0x07ac84ULL: return fde_sub_07ac84(a0, a1, a2);
        case 0x07ac88ULL: return fde_sub_07ac88(a0, a1, a2);
        case 0x07b06cULL: return fde_sub_07b06c(a0, a1, a2);
        case 0x07b070ULL: return fde_sub_07b070(a0, a1, a2);
        case 0x07b454ULL: return fde_sub_07b454(a0, a1, a2);
        case 0x07b458ULL: return fde_sub_07b458(a0, a1, a2);
        case 0x07b83cULL: return fde_sub_07b83c(a0, a1, a2);
        case 0x07b840ULL: return fde_sub_07b840(a0, a1, a2);
        case 0x07bc24ULL: return fde_sub_07bc24(a0, a1, a2);
        case 0x07bc28ULL: return fde_sub_07bc28(a0, a1, a2);
        case 0x07c00cULL: return fde_sub_07c00c(a0, a1, a2);
        case 0x07c010ULL: return fde_sub_07c010(a0, a1, a2);
        case 0x07c3f4ULL: return fde_sub_07c3f4(a0, a1, a2);
        case 0x07c3f8ULL: return fde_sub_07c3f8(a0, a1, a2);
        case 0x07c7c4ULL: return fde_sub_07c7c4(a0, a1, a2);
        case 0x07c7c8ULL: return fde_sub_07c7c8(a0, a1, a2);
        case 0x07cb94ULL: return fde_sub_07cb94(a0, a1, a2);
        case 0x07cb98ULL: return fde_sub_07cb98(a0, a1, a2);
        case 0x07cf64ULL: return fde_sub_07cf64(a0, a1, a2);
        case 0x07d41cULL: return fde_sub_07d41c(a0, a1, a2);
        case 0x07d788ULL: return fde_sub_07d788(a0, a1, a2);
        case 0x07d958ULL: return fde_sub_07d958(a0, a1, a2);
        case 0x07ddc0ULL: return fde_sub_07ddc0(a0, a1, a2);
        case 0x07df78ULL: return fde_sub_07df78(a0, a1, a2);
        case 0x07e148ULL: return fde_sub_07e148(a0, a1, a2);
        case 0x07e5acULL: return fde_sub_07e5ac(a0, a1, a2);
        case 0x07e764ULL: return fde_sub_07e764(a0, a1, a2);
        case 0x07e974ULL: return fde_sub_07e974(a0, a1, a2);
        case 0x07ebe0ULL: return fde_sub_07ebe0(a0, a1, a2);
        case 0x07ecdcULL: return fde_sub_07ecdc(a0, a1, a2);
        case 0x07f0f0ULL: return fde_sub_07f0f0(a0, a1, a2);
        case 0x07f2a0ULL: return fde_sub_07f2a0(a0, a1, a2);
        case 0x07f508ULL: return fde_sub_07f508(a0, a1, a2);
        case 0x07f78cULL: return fde_sub_07f78c(a0, a1, a2);
        case 0x07fa0cULL: return fde_sub_07fa0c(a0, a1, a2);
        case 0x07fe30ULL: return fde_sub_07fe30(a0, a1, a2);
        case 0x07ff24ULL: return fde_sub_07ff24(a0, a1, a2);
        case 0x0804f8ULL: return fde_sub_0804f8(a0, a1, a2);
        case 0x080924ULL: return fde_sub_080924(a0, a1, a2);
        case 0x080b88ULL: return fde_sub_080b88(a0, a1, a2);
        case 0x080da0ULL: return fde_sub_080da0(a0, a1, a2);
        case 0x081028ULL: return fde_sub_081028(a0, a1, a2);
        case 0x081430ULL: return fde_sub_081430(a0, a1, a2);
        case 0x081618ULL: return fde_sub_081618(a0, a1, a2);
        case 0x08189cULL: return fde_sub_08189c(a0, a1, a2);
        case 0x081b24ULL: return fde_sub_081b24(a0, a1, a2);
        case 0x081da8ULL: return fde_sub_081da8(a0, a1, a2);
        case 0x0821dcULL: return fde_sub_0821dc(a0, a1, a2);
        case 0x0827c0ULL: return fde_sub_0827c0(a0, a1, a2);
        case 0x082bfcULL: return fde_sub_082bfc(a0, a1, a2);
        case 0x082e60ULL: return fde_sub_082e60(a0, a1, a2);
        case 0x082e64ULL: return fde_sub_082e64(a0, a1, a2);
        case 0x082e74ULL: return fde_sub_082e74(a0, a1, a2);
        case 0x083358ULL: return fde_sub_083358(a0, a1, a2);
        case 0x083360ULL: return fde_sub_083360(a0, a1, a2);
        case 0x0833c4ULL: return fde_sub_0833c4(a0, a1, a2);
        case 0x083444ULL: return fde_sub_083444(a0, a1, a2);
        case 0x0835d4ULL: return fde_sub_0835d4(a0, a1, a2);
        case 0x083688ULL: return fde_sub_083688(a0, a1, a2);
        case 0x083814ULL: return fde_sub_083814(a0, a1, a2);
        case 0x0838c4ULL: return fde_sub_0838c4(a0, a1, a2);
        case 0x083a10ULL: return fde_sub_083a10(a0, a1, a2);
        case 0x083a74ULL: return fde_sub_083a74(a0, a1, a2);
        case 0x0840c8ULL: return fde_sub_0840c8(a0, a1, a2);
        case 0x084124ULL: return fde_sub_084124(a0, a1, a2);
        case 0x08417cULL: return fde_sub_08417c(a0, a1, a2);
        case 0x0841d8ULL: return fde_sub_0841d8(a0, a1, a2);
        case 0x084230ULL: return fde_sub_084230(a0, a1, a2);
        case 0x08428cULL: return fde_sub_08428c(a0, a1, a2);
        case 0x0842e4ULL: return fde_sub_0842e4(a0, a1, a2);
        case 0x084494ULL: return fde_sub_084494(a0, a1, a2);
        case 0x08457cULL: return fde_sub_08457c(a0, a1, a2);
        case 0x0845d4ULL: return fde_sub_0845d4(a0, a1, a2);
        case 0x08462cULL: return fde_sub_08462c(a0, a1, a2);
        case 0x084674ULL: return fde_sub_084674(a0, a1, a2);
        case 0x084838ULL: return fde_sub_084838(a0, a1, a2);
        case 0x084b84ULL: return fde_sub_084b84(a0, a1, a2);
        case 0x0850a0ULL: return fde_sub_0850a0(a0, a1, a2);
        case 0x0850a8ULL: return fde_sub_0850a8(a0, a1, a2);
        case 0x085108ULL: return fde_sub_085108(a0, a1, a2);
        case 0x08518cULL: return fde_sub_08518c(a0, a1, a2);
        case 0x08531cULL: return fde_sub_08531c(a0, a1, a2);
        case 0x0853d0ULL: return fde_sub_0853d0(a0, a1, a2);
        case 0x08555cULL: return fde_sub_08555c(a0, a1, a2);
        case 0x08560cULL: return fde_sub_08560c(a0, a1, a2);
        case 0x085758ULL: return fde_sub_085758(a0, a1, a2);
        case 0x0857bcULL: return fde_sub_0857bc(a0, a1, a2);
        case 0x085e00ULL: return fde_sub_085e00(a0, a1, a2);
        case 0x085e5cULL: return fde_sub_085e5c(a0, a1, a2);
        case 0x085eb4ULL: return fde_sub_085eb4(a0, a1, a2);
        case 0x085f10ULL: return fde_sub_085f10(a0, a1, a2);
        case 0x085f68ULL: return fde_sub_085f68(a0, a1, a2);
        case 0x085fc4ULL: return fde_sub_085fc4(a0, a1, a2);
        case 0x08601cULL: return fde_sub_08601c(a0, a1, a2);
        case 0x0861fcULL: return fde_sub_0861fc(a0, a1, a2);
        case 0x0862e4ULL: return fde_sub_0862e4(a0, a1, a2);
        case 0x08633cULL: return fde_sub_08633c(a0, a1, a2);
        case 0x086394ULL: return fde_sub_086394(a0, a1, a2);
        case 0x0863dcULL: return fde_sub_0863dc(a0, a1, a2);
        case 0x0865c8ULL: return fde_sub_0865c8(a0, a1, a2);
        case 0x086954ULL: return fde_sub_086954(a0, a1, a2);
        case 0x086c70ULL: return fde_sub_086c70(a0, a1, a2);
        case 0x086d54ULL: return fde_sub_086d54(a0, a1, a2);
        case 0x087084ULL: return fde_sub_087084(a0, a1, a2);
        case 0x087168ULL: return fde_sub_087168(a0, a1, a2);
        case 0x087170ULL: return fde_sub_087170(a0, a1, a2);
        case 0x087178ULL: return fde_sub_087178(a0, a1, a2);
        case 0x087184ULL: return fde_sub_087184(a0, a1, a2);
        case 0x087190ULL: return fde_sub_087190(a0, a1, a2);
        case 0x08719cULL: return fde_sub_08719c(a0, a1, a2);
        case 0x0871b4ULL: return fde_sub_0871b4(a0, a1, a2);
        case 0x0871bcULL: return fde_sub_0871bc(a0, a1, a2);
        case 0x0871c8ULL: return fde_sub_0871c8(a0, a1, a2);
        case 0x0871d4ULL: return fde_sub_0871d4(a0, a1, a2);
        case 0x0871dcULL: return fde_sub_0871dc(a0, a1, a2);
        case 0x0871e4ULL: return fde_sub_0871e4(a0, a1, a2);
        case 0x0871f0ULL: return fde_sub_0871f0(a0, a1, a2);
        case 0x0871fcULL: return fde_sub_0871fc(a0, a1, a2);
        case 0x087208ULL: return fde_sub_087208(a0, a1, a2);
        case 0x087220ULL: return fde_sub_087220(a0, a1, a2);
        case 0x087228ULL: return fde_sub_087228(a0, a1, a2);
        case 0x087234ULL: return fde_sub_087234(a0, a1, a2);
        case 0x087240ULL: return fde_sub_087240(a0, a1, a2);
        case 0x087248ULL: return fde_sub_087248(a0, a1, a2);
        case 0x087250ULL: return fde_sub_087250(a0, a1, a2);
        case 0x08725cULL: return fde_sub_08725c(a0, a1, a2);
        case 0x087268ULL: return fde_sub_087268(a0, a1, a2);
        case 0x087274ULL: return fde_sub_087274(a0, a1, a2);
        case 0x0872b4ULL: return fde_sub_0872b4(a0, a1, a2);
        case 0x0872bcULL: return fde_sub_0872bc(a0, a1, a2);
        case 0x0872c8ULL: return fde_sub_0872c8(a0, a1, a2);
        case 0x0872d4ULL: return fde_sub_0872d4(a0, a1, a2);
        case 0x0872dcULL: return fde_sub_0872dc(a0, a1, a2);
        case 0x0872e4ULL: return fde_sub_0872e4(a0, a1, a2);
        case 0x0872f0ULL: return fde_sub_0872f0(a0, a1, a2);
        case 0x0872fcULL: return fde_sub_0872fc(a0, a1, a2);
        case 0x087308ULL: return fde_sub_087308(a0, a1, a2);
        case 0x087348ULL: return fde_sub_087348(a0, a1, a2);
        case 0x087350ULL: return fde_sub_087350(a0, a1, a2);
        case 0x08735cULL: return fde_sub_08735c(a0, a1, a2);
        case 0x087368ULL: return fde_sub_087368(a0, a1, a2);
        case 0x087370ULL: return fde_sub_087370(a0, a1, a2);
        case 0x087378ULL: return fde_sub_087378(a0, a1, a2);
        case 0x087384ULL: return fde_sub_087384(a0, a1, a2);
        case 0x087390ULL: return fde_sub_087390(a0, a1, a2);
        case 0x08739cULL: return fde_sub_08739c(a0, a1, a2);
        case 0x0873a8ULL: return fde_sub_0873a8(a0, a1, a2);
        case 0x0873b0ULL: return fde_sub_0873b0(a0, a1, a2);
        case 0x0873b8ULL: return fde_sub_0873b8(a0, a1, a2);
        case 0x0873c0ULL: return fde_sub_0873c0(a0, a1, a2);
        case 0x0873c8ULL: return fde_sub_0873c8(a0, a1, a2);
        case 0x0873d0ULL: return fde_sub_0873d0(a0, a1, a2);
        case 0x0873dcULL: return fde_sub_0873dc(a0, a1, a2);
        case 0x0873e8ULL: return fde_sub_0873e8(a0, a1, a2);
        case 0x0873f4ULL: return fde_sub_0873f4(a0, a1, a2);
        case 0x087400ULL: return fde_sub_087400(a0, a1, a2);
        case 0x087408ULL: return fde_sub_087408(a0, a1, a2);
        case 0x087410ULL: return fde_sub_087410(a0, a1, a2);
        case 0x087418ULL: return fde_sub_087418(a0, a1, a2);
        case 0x087420ULL: return fde_sub_087420(a0, a1, a2);
        case 0x087428ULL: return fde_sub_087428(a0, a1, a2);
        case 0x087434ULL: return fde_sub_087434(a0, a1, a2);
        case 0x087440ULL: return fde_sub_087440(a0, a1, a2);
        case 0x08744cULL: return fde_sub_08744c(a0, a1, a2);
        case 0x087458ULL: return fde_sub_087458(a0, a1, a2);
        case 0x087460ULL: return fde_sub_087460(a0, a1, a2);
        case 0x087468ULL: return fde_sub_087468(a0, a1, a2);
        case 0x087470ULL: return fde_sub_087470(a0, a1, a2);
        case 0x087478ULL: return fde_sub_087478(a0, a1, a2);
        case 0x087480ULL: return fde_sub_087480(a0, a1, a2);
        case 0x08748cULL: return fde_sub_08748c(a0, a1, a2);
        case 0x087498ULL: return fde_sub_087498(a0, a1, a2);
        case 0x0874a4ULL: return fde_sub_0874a4(a0, a1, a2);
        case 0x0874b0ULL: return fde_sub_0874b0(a0, a1, a2);
        case 0x0874b8ULL: return fde_sub_0874b8(a0, a1, a2);
        case 0x0874c0ULL: return fde_sub_0874c0(a0, a1, a2);
        case 0x0874c8ULL: return fde_sub_0874c8(a0, a1, a2);
        case 0x0878e0ULL: return fde_sub_0878e0(a0, a1, a2);
        case 0x088ae0ULL: return fde_sub_088ae0(a0, a1, a2);
        case 0x088db8ULL: return fde_sub_088db8(a0, a1, a2);
        case 0x0890c8ULL: return fde_sub_0890c8(a0, a1, a2);
        case 0x0894fcULL: return fde_sub_0894fc(a0, a1, a2);
        case 0x08a800ULL: return fde_sub_08a800(a0, a1, a2);
        case 0x08aaf4ULL: return fde_sub_08aaf4(a0, a1, a2);
        case 0x08ae10ULL: return fde_sub_08ae10(a0, a1, a2);
        case 0x08b2c0ULL: return fde_sub_08b2c0(a0, a1, a2);
        case 0x08b5a4ULL: return fde_sub_08b5a4(a0, a1, a2);
        case 0x08babcULL: return fde_sub_08babc(a0, a1, a2);
        case 0x08be70ULL: return fde_sub_08be70(a0, a1, a2);
        case 0x08c324ULL: return fde_sub_08c324(a0, a1, a2);
        case 0x08c60cULL: return fde_sub_08c60c(a0, a1, a2);
        case 0x08cb00ULL: return fde_sub_08cb00(a0, a1, a2);
        case 0x08cebcULL: return fde_sub_08cebc(a0, a1, a2);
        case 0x08cec4ULL: return fde_sub_08cec4(a0, a1, a2);
        case 0x08ced0ULL: return fde_sub_08ced0(a0, a1, a2);
        case 0x08ced4ULL: return fde_sub_08ced4(a0, a1, a2);
        case 0x08cedcULL: return fde_sub_08cedc(a0, a1, a2);
        case 0x08cee8ULL: return fde_sub_08cee8(a0, a1, a2);
        case 0x08ceecULL: return fde_sub_08ceec(a0, a1, a2);
        case 0x08cef0ULL: return fde_sub_08cef0(a0, a1, a2);
        case 0x08cf14ULL: return fde_sub_08cf14(a0, a1, a2);
        case 0x08cf18ULL: return fde_sub_08cf18(a0, a1, a2);
        case 0x08cf3cULL: return fde_sub_08cf3c(a0, a1, a2);
        case 0x08cf40ULL: return fde_sub_08cf40(a0, a1, a2);
        case 0x08cf64ULL: return fde_sub_08cf64(a0, a1, a2);
        case 0x08cf68ULL: return fde_sub_08cf68(a0, a1, a2);
        case 0x08cf8cULL: return fde_sub_08cf8c(a0, a1, a2);
        case 0x08d0bcULL: return fde_sub_08d0bc(a0, a1, a2);
        case 0x08d1ecULL: return fde_sub_08d1ec(a0, a1, a2);
        case 0x08d31cULL: return fde_sub_08d31c(a0, a1, a2);
        case 0x08d44cULL: return fde_sub_08d44c(a0, a1, a2);
        case 0x08d57cULL: return fde_sub_08d57c(a0, a1, a2);
        case 0x08d6acULL: return fde_sub_08d6ac(a0, a1, a2);
        case 0x08d7dcULL: return fde_sub_08d7dc(a0, a1, a2);
        case 0x08d90cULL: return fde_sub_08d90c(a0, a1, a2);
        case 0x08da3cULL: return fde_sub_08da3c(a0, a1, a2);
        case 0x08db6cULL: return fde_sub_08db6c(a0, a1, a2);
        case 0x08dc9cULL: return fde_sub_08dc9c(a0, a1, a2);
        case 0x08dd78ULL: return fde_sub_08dd78(a0, a1, a2);
        case 0x08dea8ULL: return fde_sub_08dea8(a0, a1, a2);
        case 0x08df84ULL: return fde_sub_08df84(a0, a1, a2);
        case 0x08e0b4ULL: return fde_sub_08e0b4(a0, a1, a2);
        case 0x08e190ULL: return fde_sub_08e190(a0, a1, a2);
        case 0x08e2c0ULL: return fde_sub_08e2c0(a0, a1, a2);
        case 0x08e39cULL: return fde_sub_08e39c(a0, a1, a2);
        case 0x08e4ccULL: return fde_sub_08e4cc(a0, a1, a2);
        case 0x08e5fcULL: return fde_sub_08e5fc(a0, a1, a2);
        case 0x08e72cULL: return fde_sub_08e72c(a0, a1, a2);
        case 0x08e85cULL: return fde_sub_08e85c(a0, a1, a2);
        case 0x08e98cULL: return fde_sub_08e98c(a0, a1, a2);
        case 0x08eabcULL: return fde_sub_08eabc(a0, a1, a2);
        case 0x08eaf0ULL: return fde_sub_08eaf0(a0, a1, a2);
        case 0x08eaf4ULL: return fde_sub_08eaf4(a0, a1, a2);
        case 0x08eaf8ULL: return fde_sub_08eaf8(a0, a1, a2);
        case 0x08eafcULL: return fde_sub_08eafc(a0, a1, a2);
        case 0x08eb00ULL: return fde_sub_08eb00(a0, a1, a2);
        case 0x08eb04ULL: return fde_sub_08eb04(a0, a1, a2);
        case 0x08eb08ULL: return fde_sub_08eb08(a0, a1, a2);
        case 0x08eb0cULL: return fde_sub_08eb0c(a0, a1, a2);
        case 0x08eb10ULL: return fde_sub_08eb10(a0, a1, a2);
        case 0x08eb14ULL: return fde_sub_08eb14(a0, a1, a2);
        case 0x08eb18ULL: return fde_sub_08eb18(a0, a1, a2);
        case 0x08eb1cULL: return fde_sub_08eb1c(a0, a1, a2);
        case 0x08eb20ULL: return fde_sub_08eb20(a0, a1, a2);
        case 0x08eb24ULL: return fde_sub_08eb24(a0, a1, a2);
        case 0x08eb28ULL: return fde_sub_08eb28(a0, a1, a2);
        case 0x08eb2cULL: return fde_sub_08eb2c(a0, a1, a2);
        case 0x08eb30ULL: return fde_sub_08eb30(a0, a1, a2);
        case 0x08eb34ULL: return fde_sub_08eb34(a0, a1, a2);
        case 0x08eb38ULL: return fde_sub_08eb38(a0, a1, a2);
        case 0x08eb3cULL: return fde_sub_08eb3c(a0, a1, a2);
        case 0x08eb40ULL: return fde_sub_08eb40(a0, a1, a2);
        case 0x08ebf4ULL: return fde_sub_08ebf4(a0, a1, a2);
        case 0x08ebf8ULL: return fde_sub_08ebf8(a0, a1, a2);
        case 0x08ef50ULL: return fde_sub_08ef50(a0, a1, a2);
        case 0x08f2a4ULL: return fde_sub_08f2a4(a0, a1, a2);
        case 0x08f2c8ULL: return fde_sub_08f2c8(a0, a1, a2);
        case 0x08f2ecULL: return fde_sub_08f2ec(a0, a1, a2);
        case 0x08f310ULL: return fde_sub_08f310(a0, a1, a2);
        case 0x08f334ULL: return fde_sub_08f334(a0, a1, a2);
        case 0x08f358ULL: return fde_sub_08f358(a0, a1, a2);
        case 0x08f37cULL: return fde_sub_08f37c(a0, a1, a2);
        case 0x08f3a0ULL: return fde_sub_08f3a0(a0, a1, a2);
        case 0x08f3c4ULL: return fde_sub_08f3c4(a0, a1, a2);
        case 0x08f3e8ULL: return fde_sub_08f3e8(a0, a1, a2);
        case 0x08f40cULL: return fde_sub_08f40c(a0, a1, a2);
        case 0x08f430ULL: return fde_sub_08f430(a0, a1, a2);
        case 0x08f454ULL: return fde_sub_08f454(a0, a1, a2);
        case 0x08f478ULL: return fde_sub_08f478(a0, a1, a2);
        case 0x08f49cULL: return fde_sub_08f49c(a0, a1, a2);
        case 0x08f4c0ULL: return fde_sub_08f4c0(a0, a1, a2);
        case 0x08f4e4ULL: return fde_sub_08f4e4(a0, a1, a2);
        case 0x08f4e8ULL: return fde_sub_08f4e8(a0, a1, a2);
        case 0x08f50cULL: return fde_sub_08f50c(a0, a1, a2);
        case 0x08f510ULL: return fde_sub_08f510(a0, a1, a2);
        case 0x08f534ULL: return fde_sub_08f534(a0, a1, a2);
        case 0x08f55cULL: return fde_sub_08f55c(a0, a1, a2);
        case 0x08f58cULL: return fde_sub_08f58c(a0, a1, a2);
        case 0x08f594ULL: return fde_sub_08f594(a0, a1, a2);
        case 0x08f59cULL: return fde_sub_08f59c(a0, a1, a2);
        case 0x08f5a4ULL: return fde_sub_08f5a4(a0, a1, a2);
        case 0x08f5acULL: return fde_sub_08f5ac(a0, a1, a2);
        case 0x08f5b4ULL: return fde_sub_08f5b4(a0, a1, a2);
        case 0x08f5bcULL: return fde_sub_08f5bc(a0, a1, a2);
        case 0x08f5c4ULL: return fde_sub_08f5c4(a0, a1, a2);
        case 0x08f5ccULL: return fde_sub_08f5cc(a0, a1, a2);
        case 0x08f5d4ULL: return fde_sub_08f5d4(a0, a1, a2);
        case 0x08f5dcULL: return fde_sub_08f5dc(a0, a1, a2);
        case 0x08f5e4ULL: return fde_sub_08f5e4(a0, a1, a2);
        case 0x08f5ecULL: return fde_sub_08f5ec(a0, a1, a2);
        case 0x08f5f4ULL: return fde_sub_08f5f4(a0, a1, a2);
        case 0x08f5fcULL: return fde_sub_08f5fc(a0, a1, a2);
        case 0x08f604ULL: return fde_sub_08f604(a0, a1, a2);
        case 0x08f62cULL: return fde_sub_08f62c(a0, a1, a2);
        case 0x08f65cULL: return fde_sub_08f65c(a0, a1, a2);
        case 0x08f664ULL: return fde_sub_08f664(a0, a1, a2);
        case 0x08f66cULL: return fde_sub_08f66c(a0, a1, a2);
        case 0x08f674ULL: return fde_sub_08f674(a0, a1, a2);
        case 0x08f67cULL: return fde_sub_08f67c(a0, a1, a2);
        case 0x08f684ULL: return fde_sub_08f684(a0, a1, a2);
        case 0x08f68cULL: return fde_sub_08f68c(a0, a1, a2);
        case 0x08f694ULL: return fde_sub_08f694(a0, a1, a2);
        case 0x08f69cULL: return fde_sub_08f69c(a0, a1, a2);
        case 0x08f6a4ULL: return fde_sub_08f6a4(a0, a1, a2);
        case 0x08f6acULL: return fde_sub_08f6ac(a0, a1, a2);
        case 0x08f6b4ULL: return fde_sub_08f6b4(a0, a1, a2);
        case 0x08f6bcULL: return fde_sub_08f6bc(a0, a1, a2);
        case 0x08f6c4ULL: return fde_sub_08f6c4(a0, a1, a2);
        case 0x08f6ccULL: return fde_sub_08f6cc(a0, a1, a2);
        case 0x08f6d4ULL: return fde_sub_08f6d4(a0, a1, a2);
        case 0x08f704ULL: return fde_sub_08f704(a0, a1, a2);
        case 0x08f72cULL: return fde_sub_08f72c(a0, a1, a2);
        case 0x08f75cULL: return fde_sub_08f75c(a0, a1, a2);
        case 0x08f784ULL: return fde_sub_08f784(a0, a1, a2);
        case 0x08f7b4ULL: return fde_sub_08f7b4(a0, a1, a2);
        case 0x08f7e4ULL: return fde_sub_08f7e4(a0, a1, a2);
        case 0x08f808ULL: return fde_sub_08f808(a0, a1, a2);
        case 0x08f82cULL: return fde_sub_08f82c(a0, a1, a2);
        case 0x08f850ULL: return fde_sub_08f850(a0, a1, a2);
        case 0x08f874ULL: return fde_sub_08f874(a0, a1, a2);
        case 0x08f900ULL: return fde_sub_08f900(a0, a1, a2);
        case 0x08f924ULL: return fde_sub_08f924(a0, a1, a2);
        case 0x08f9b0ULL: return fde_sub_08f9b0(a0, a1, a2);
        case 0x08f9d4ULL: return fde_sub_08f9d4(a0, a1, a2);
        case 0x08fa60ULL: return fde_sub_08fa60(a0, a1, a2);
        case 0x08fa84ULL: return fde_sub_08fa84(a0, a1, a2);
        case 0x08fb10ULL: return fde_sub_08fb10(a0, a1, a2);
        case 0x08fb34ULL: return fde_sub_08fb34(a0, a1, a2);
        case 0x08fb58ULL: return fde_sub_08fb58(a0, a1, a2);
        case 0x08fb7cULL: return fde_sub_08fb7c(a0, a1, a2);
        case 0x08fba0ULL: return fde_sub_08fba0(a0, a1, a2);
        case 0x08fbc4ULL: return fde_sub_08fbc4(a0, a1, a2);
        case 0x08fbe8ULL: return fde_sub_08fbe8(a0, a1, a2);
        case 0x08fc0cULL: return fde_sub_08fc0c(a0, a1, a2);
        case 0x08fc30ULL: return fde_sub_08fc30(a0, a1, a2);
        case 0x08fc54ULL: return fde_sub_08fc54(a0, a1, a2);
        case 0x08fde0ULL: return fde_sub_08fde0(a0, a1, a2);
        case 0x08ff24ULL: return fde_sub_08ff24(a0, a1, a2);
        case 0x08ff9cULL: return fde_sub_08ff9c(a0, a1, a2);
        case 0x08fff0ULL: return fde_sub_08fff0(a0, a1, a2);
        case 0x090184ULL: return fde_sub_090184(a0, a1, a2);
        case 0x090354ULL: return fde_sub_090354(a0, a1, a2);
        case 0x090490ULL: return fde_sub_090490(a0, a1, a2);
        case 0x0905ccULL: return fde_sub_0905cc(a0, a1, a2);
        case 0x090734ULL: return fde_sub_090734(a0, a1, a2);
        case 0x09089cULL: return fde_sub_09089c(a0, a1, a2);
        case 0x0909fcULL: return fde_sub_0909fc(a0, a1, a2);
        default: return 0ULL;
    }
}

} // namespace ndk_libcxx_recon
