// ============================================================================
// File: applovin_fde_shard_4.cpp
// Target 110 / 169: libapplovin-native-crash-reporter.so (860,200 bytes)
// EN: Clean-room C++17 AArch64 FDE Shard 4/5 covering FDEs [1056..1407]
//     (PC range 0x0a00d0 .. 0x0b6fc4).
// VI: Phân mảnh FDE AArch64 C++17 4/5 bao phủ FDE [1056..1407]
//     (Dải địa chỉ PC 0x0a00d0 .. 0x0b6fc4).
// ============================================================================
#include "applovin_crash_reporter.h"

namespace applovin {

// FDE #1056 | PC: 0x0a00d0..0x0a00dc (12 B) | Symbol: _ZNSt6__ndk118get_pointer_safetyEv
// EN: AArch64 prologue [bti c; mov x0, xzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov x0, xzr; ret]
uint64_t fde_sub_0a00d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A00D0ULL;
}

// FDE #1057 | PC: 0x0a00dc..0x0a00e4 (8 B) | Symbol: _ZNSt6__ndk121__undeclare_reachableEPv
// EN: AArch64 prologue [bti c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ret]
uint64_t fde_sub_0a00dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A00DCULL;
}

// FDE #1058 | PC: 0x0a00e4..0x0a0134 (80 B) | Symbol: _ZNSt6__ndk15alignEmmRPvRm
// EN: AArch64 prologue [bti c; ldr x8, [x3]; subs x10, x8, x1; b.hs #0xa00fc] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x3]; subs x10, x8, x1; b.hs #0xa00fc]
uint64_t fde_sub_0a00e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400068ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A00E4ULL;
}

// FDE #1059 | PC: 0x0a0134..0x0a0160 (44 B) | Symbol: _ZNSt6__ndk15mutex4lockEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc95d0] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc95d0]
uint64_t fde_sub_0a0134(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0134ULL;
}

// FDE #1060 | PC: 0x0a0160..0x0a0188 (40 B) | Symbol: _ZNSt6__ndk15mutex8try_lockEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc95b0] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc95b0]
uint64_t fde_sub_0a0160(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0160ULL;
}

// FDE #1061 | PC: 0x0a0188..0x0a01a8 (32 B) | Symbol: _ZNSt6__ndk15mutex6unlockEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc95e0] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc95e0]
uint64_t fde_sub_0a0188(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0188ULL;
}

// FDE #1062 | PC: 0x0a01a8..0x0a0274 (204 B) | Symbol: _ZNSt6__ndk115recursive_mutexC2Ev
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_0a01a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A01A8ULL;
}

// FDE #1063 | PC: 0x0a0274..0x0a0294 (32 B) | Symbol: _ZNSt6__ndk115recursive_mutexD2Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc9640] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc9640]
uint64_t fde_sub_0a0274(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0274ULL;
}

// FDE #1064 | PC: 0x0a0294..0x0a02c0 (44 B) | Symbol: _ZNSt6__ndk115recursive_mutex4lockEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc95d0] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc95d0]
uint64_t fde_sub_0a0294(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0294ULL;
}

// FDE #1065 | PC: 0x0a02c0..0x0a02e0 (32 B) | Symbol: _ZNSt6__ndk115recursive_mutex6unlockEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc95e0] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc95e0]
uint64_t fde_sub_0a02c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A02C0ULL;
}

// FDE #1066 | PC: 0x0a02e0..0x0a0308 (40 B) | Symbol: _ZNSt6__ndk115recursive_mutex8try_lockEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc95b0] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc95b0]
uint64_t fde_sub_0a02e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A02E0ULL;
}

// FDE #1067 | PC: 0x0a0308..0x0a0324 (28 B) | Symbol: _ZNSt6__ndk111timed_mutexC2Ev
// EN: AArch64 prologue [bti c; movi v0.2d, #0000000000000000; stur q0, [x0, #0x49]; stp q0, q0, [x0, #0x30]] | VI: Khởi đầu hàm AArch64 [bti c; movi v0.2d, #0000000000000000; stur q0, [x0, #0x49]; stp q0, q0, [x0, #0x30]]
uint64_t fde_sub_0a0308(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6F00E400ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0308ULL;
}

// FDE #1068 | PC: 0x0a0324..0x0a0390 (108 B) | Symbol: _ZNSt6__ndk111timed_mutexD2Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0a0324(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0324ULL;
}

// FDE #1069 | PC: 0x0a0390..0x0a044c (188 B) | Symbol: _ZNSt6__ndk111timed_mutex4lockEv
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_0a0390(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0390ULL;
}

// FDE #1070 | PC: 0x0a044c..0x0a04ac (96 B) | Symbol: _ZNSt6__ndk111timed_mutex8try_lockEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0a044c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A044CULL;
}

// FDE #1071 | PC: 0x0a04ac..0x0a0500 (84 B) | Symbol: _ZNSt6__ndk111timed_mutex6unlockEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0a04ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A04ACULL;
}

// FDE #1072 | PC: 0x0a0500..0x0a051c (28 B) | Symbol: _ZNSt6__ndk121recursive_timed_mutexC2Ev
// EN: AArch64 prologue [bti c; movi v0.2d, #0000000000000000; str xzr, [x0, #0x60]; stp q0, q0, [x0, #0x40]] | VI: Khởi đầu hàm AArch64 [bti c; movi v0.2d, #0000000000000000; str xzr, [x0, #0x60]; stp q0, q0, [x0, #0x40]]
uint64_t fde_sub_0a0500(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6F00E400ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0500ULL;
}

// FDE #1073 | PC: 0x0a051c..0x0a0588 (108 B) | Symbol: _ZNSt6__ndk121recursive_timed_mutexD2Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0a051c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A051CULL;
}

// FDE #1074 | PC: 0x0a0588..0x0a06b4 (300 B) | Symbol: _ZNSt6__ndk121recursive_timed_mutex4lockEv
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0a0588(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0588ULL;
}

// FDE #1075 | PC: 0x0a06b4..0x0a0754 (160 B) | Symbol: _ZNSt6__ndk121recursive_timed_mutex8try_lockEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0a06b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A06B4ULL;
}

// FDE #1076 | PC: 0x0a0754..0x0a07d0 (124 B) | Symbol: _ZNSt6__ndk121recursive_timed_mutex6unlockEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0a0754(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0754ULL;
}

// FDE #1077 | PC: 0x0a07d0..0x0a0900 (304 B) | Symbol: _ZNSt6__ndk111__call_onceERVmPvPFvS2_E
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0a07d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A07D0ULL;
}

// FDE #1078 | PC: 0x0a0900..0x0a0920 (32 B) | Symbol: _ZNSt6__ndk118condition_variable10notify_oneEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc96d0] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc96d0]
uint64_t fde_sub_0a0900(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0900ULL;
}

// FDE #1079 | PC: 0x0a0920..0x0a0940 (32 B) | Symbol: _ZNSt6__ndk118condition_variable10notify_allEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc96c0] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc96c0]
uint64_t fde_sub_0a0920(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0920ULL;
}

// FDE #1080 | PC: 0x0a0940..0x0a0990 (80 B) | Symbol: _ZNSt6__ndk118condition_variable4waitERNS_11unique_lockINS_5mutexEEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x1, #8]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x1, #8]]
uint64_t fde_sub_0a0940(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0940ULL;
}

// FDE #1081 | PC: 0x0a0990..0x0a0a5c (204 B) | Symbol: _ZNSt6__ndk118condition_variable15__do_timed_waitERNS_11unique_lockINS_5mutexEEENS_6chrono10time_pointINS5_12system_clockENS5_8durationIxNS_5ratioILl1ELl1000000000EEEEEEE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x40; stp x29, x30, [sp, #0x20]; str x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x40; stp x29, x30, [sp, #0x20]; str x19, [sp, #0x30]]
uint64_t fde_sub_0a0990(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10103FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0990ULL;
}

// FDE #1082 | PC: 0x0a0a5c..0x0a0aec (144 B) | Symbol: _ZNSt6__ndk125notify_all_at_thread_exitERNS_18condition_variableENS_11unique_lockINS_5mutexEEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a0a5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0A5CULL;
}

// FDE #1083 | PC: 0x0a0aec..0x0a0b0c (32 B) | Symbol: _ZNSt6__ndk118condition_variableD2Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc9740] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc9740]
uint64_t fde_sub_0a0aec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0AECULL;
}

// FDE #1084 | PC: 0x0a0b0c..0x0a0b2c (32 B) | Symbol: _ZNSt6__ndk15mutexD2Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc9640] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc9640]
uint64_t fde_sub_0a0b0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0B0CULL;
}

// FDE #1085 | PC: 0x0a0b2c..0x0a0b64 (56 B) | Symbol: _ZSt17__throw_bad_allocv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0a0b2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0B2CULL;
}

// FDE #1086 | PC: 0x0a0b64..0x0a0bd0 (108 B) | Symbol: _Znwm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0a0b64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0B64ULL;
}

// FDE #1087 | PC: 0x0a0bd0..0x0a0c00 (48 B) | Symbol: _ZnwmRKSt9nothrow_t
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc8540] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc8540]
uint64_t fde_sub_0a0bd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0BD0ULL;
}

// FDE #1088 | PC: 0x0a0c00..0x0a0c08 (8 B) | Symbol: _Znam
// EN: AArch64 prologue [bti c; b #0xc8540] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8540]
uint64_t fde_sub_0a0c00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14009E4FULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0C00ULL;
}

// FDE #1089 | PC: 0x0a0c08..0x0a0c38 (48 B) | Symbol: _ZnamRKSt9nothrow_t
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc8890] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc8890]
uint64_t fde_sub_0a0c08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0C08ULL;
}

// FDE #1090 | PC: 0x0a0c38..0x0a0c40 (8 B) | Symbol: _ZdlPv
// EN: AArch64 prologue [bti c; b #0xc8510] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8510]
uint64_t fde_sub_0a0c38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14009E35ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0C38ULL;
}

// FDE #1091 | PC: 0x0a0c40..0x0a0c48 (8 B) | Symbol: _ZdlPvRKSt9nothrow_t
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0a0c40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14009E3BULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0C40ULL;
}

// FDE #1092 | PC: 0x0a0c48..0x0a0c50 (8 B) | Symbol: _ZdlPvm
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0a0c48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14009E39ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0C48ULL;
}

// FDE #1093 | PC: 0x0a0c50..0x0a0c58 (8 B) | Symbol: _ZdaPv
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0a0c50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14009E37ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0C50ULL;
}

// FDE #1094 | PC: 0x0a0c58..0x0a0c60 (8 B) | Symbol: _ZdaPvRKSt9nothrow_t
// EN: AArch64 prologue [bti c; b #0xc8870] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8870]
uint64_t fde_sub_0a0c58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14009F05ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0C58ULL;
}

// FDE #1095 | PC: 0x0a0c60..0x0a0c68 (8 B) | Symbol: _ZdaPvm
// EN: AArch64 prologue [bti c; b #0xc8870] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8870]
uint64_t fde_sub_0a0c60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14009F03ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0C60ULL;
}

// FDE #1096 | PC: 0x0a0c68..0x0a0d1c (180 B) | Symbol: _ZnwmSt11align_val_t
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x40; stp x29, x30, [sp, #0x10]; str x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x40; stp x29, x30, [sp, #0x10]; str x21, [sp, #0x20]]
uint64_t fde_sub_0a0c68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10103FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0C68ULL;
}

// FDE #1097 | PC: 0x0a0d1c..0x0a0d4c (48 B) | Symbol: _ZnwmSt11align_val_tRKSt9nothrow_t
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc9780] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc9780]
uint64_t fde_sub_0a0d1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0D1CULL;
}

// FDE #1098 | PC: 0x0a0d4c..0x0a0d54 (8 B) | Symbol: _ZnamSt11align_val_t
// EN: AArch64 prologue [bti c; b #0xc9780] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc9780]
uint64_t fde_sub_0a0d4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400A28CULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0D4CULL;
}

// FDE #1099 | PC: 0x0a0d54..0x0a0d84 (48 B) | Symbol: _ZnamSt11align_val_tRKSt9nothrow_t
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc9790] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc9790]
uint64_t fde_sub_0a0d54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0D54ULL;
}

// FDE #1100 | PC: 0x0a0d84..0x0a0d8c (8 B) | Symbol: _ZdlPvSt11align_val_t
// EN: AArch64 prologue [bti c; b #0xc8510] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8510]
uint64_t fde_sub_0a0d84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14009DE2ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0D84ULL;
}

// FDE #1101 | PC: 0x0a0d8c..0x0a0d94 (8 B) | Symbol: _ZdlPvSt11align_val_tRKSt9nothrow_t
// EN: AArch64 prologue [bti c; b #0xc97a0] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc97a0]
uint64_t fde_sub_0a0d8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400A284ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0D8CULL;
}

// FDE #1102 | PC: 0x0a0d94..0x0a0da0 (12 B) | Symbol: _ZdlPvmSt11align_val_t
// EN: AArch64 prologue [bti c; mov x1, x2; b #0xc97a0] | VI: Khởi đầu hàm AArch64 [bti c; mov x1, x2; b #0xc97a0]
uint64_t fde_sub_0a0d94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0203E1ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0D94ULL;
}

// FDE #1103 | PC: 0x0a0da0..0x0a0da8 (8 B) | Symbol: _ZdaPvSt11align_val_t
// EN: AArch64 prologue [bti c; b #0xc97a0] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc97a0]
uint64_t fde_sub_0a0da0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400A27FULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0DA0ULL;
}

// FDE #1104 | PC: 0x0a0da8..0x0a0db0 (8 B) | Symbol: _ZdaPvSt11align_val_tRKSt9nothrow_t
// EN: AArch64 prologue [bti c; b #0xc97b0] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc97b0]
uint64_t fde_sub_0a0da8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400A281ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0DA8ULL;
}

// FDE #1105 | PC: 0x0a0db0..0x0a0dbc (12 B) | Symbol: _ZdaPvmSt11align_val_t
// EN: AArch64 prologue [bti c; mov x1, x2; b #0xc97b0] | VI: Khởi đầu hàm AArch64 [bti c; mov x1, x2; b #0xc97b0]
uint64_t fde_sub_0a0db0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0203E1ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0DB0ULL;
}

// FDE #1106 | PC: 0x0a0dbc..0x0a0e54 (152 B) | Symbol: _ZNSt11logic_errorC1ERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a0dbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0DBCULL;
}

// FDE #1107 | PC: 0x0a0e54..0x0a0ee0 (140 B) | Symbol: _ZNSt11logic_errorC1EPKc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a0e54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0E54ULL;
}

// FDE #1108 | PC: 0x0a0ee0..0x0a0f14 (52 B) | Symbol: _ZNSt11logic_errorC2ERKS_
// EN: AArch64 prologue [bti c; adrp x8, #0xd4000; ldr x8, [x8, #0x8c0]; add x8, x8, #0x10] | VI: Khởi đầu hàm AArch64 [bti c; adrp x8, #0xd4000; ldr x8, [x8, #0x8c0]; add x8, x8, #0x10]
uint64_t fde_sub_0a0ee0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900001A8ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0EE0ULL;
}

// FDE #1109 | PC: 0x0a0f14..0x0a0f7c (104 B) | Symbol: _ZNSt11logic_erroraSERKS_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0a0f14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0F14ULL;
}

// FDE #1110 | PC: 0x0a0f7c..0x0a1014 (152 B) | Symbol: _ZNSt13runtime_errorC1ERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a0f7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A0F7CULL;
}

// FDE #1111 | PC: 0x0a1014..0x0a10a0 (140 B) | Symbol: _ZNSt13runtime_errorC1EPKc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a1014(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A1014ULL;
}

// FDE #1112 | PC: 0x0a10a0..0x0a10d4 (52 B) | Symbol: _ZNSt13runtime_errorC2ERKS_
// EN: AArch64 prologue [bti c; adrp x8, #0xd4000; ldr x8, [x8, #0x8c8]; add x8, x8, #0x10] | VI: Khởi đầu hàm AArch64 [bti c; adrp x8, #0xd4000; ldr x8, [x8, #0x8c8]; add x8, x8, #0x10]
uint64_t fde_sub_0a10a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000188ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A10A0ULL;
}

// FDE #1113 | PC: 0x0a10d4..0x0a113c (104 B) | Symbol: _ZNSt13runtime_erroraSERKS_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0a10d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A10D4ULL;
}

// FDE #1114 | PC: 0x0a113c..0x0a1154 (24 B) | Symbol: _ZNKSt6__ndk121__basic_string_commonILb1EE20__throw_length_errorEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0x49000] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0x49000]
uint64_t fde_sub_0a113c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A113CULL;
}

// FDE #1115 | PC: 0x0a1154..0x0a116c (24 B) | Symbol: _ZNKSt6__ndk121__basic_string_commonILb1EE20__throw_out_of_rangeEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0x49000] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0x49000]
uint64_t fde_sub_0a1154(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A1154ULL;
}

// FDE #1116 | PC: 0x0a116c..0x0a11c0 (84 B) | Symbol: sub_0a116c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0a116c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A116CULL;
}

// FDE #1117 | PC: 0x0a11c0..0x0a13a4 (484 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7replaceEmmPKcm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_0a11c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A11C0ULL;
}

// FDE #1118 | PC: 0x0a13a4..0x0a14e0 (316 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE21__grow_by_and_replaceEmmmmmmPKc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_0a13a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x013CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A13A4ULL;
}

// FDE #1119 | PC: 0x0a14e0..0x0a15a4 (196 B) | Symbol: _ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5rfindEPKcmm
// EN: AArch64 prologue [bti c; ldrb w9, [x0]; tbnz w9, #0, #0xa14f8; add x8, x0, #1] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w9, [x0]; tbnz w9, #0, #0xa14f8; add x8, x0, #1]
uint64_t fde_sub_0a14e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39400009ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A14E0ULL;
}

// FDE #1120 | PC: 0x0a15a4..0x0a1638 (148 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6__initEPKcmm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a15a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A15A4ULL;
}

// FDE #1121 | PC: 0x0a1638..0x0a16d8 (160 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a1638(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A1638ULL;
}

// FDE #1122 | PC: 0x0a16d8..0x0a172c (84 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7replaceEmmPKc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a16d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A16D8ULL;
}

// FDE #1123 | PC: 0x0a172c..0x0a17cc (160 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC1ERKS5_RKS4_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a172c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A172CULL;
}

// FDE #1124 | PC: 0x0a17cc..0x0a184c (128 B) | Symbol: _ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE16find_last_not_ofEPKcmm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a17cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A17CCULL;
}

// FDE #1125 | PC: 0x0a184c..0x0a1864 (24 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev
// EN: AArch64 prologue [bti c; ldrb w8, [x0]; tbnz w8, #0, #0xa185c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w8, [x0]; tbnz w8, #0, #0xa185c; ret]
uint64_t fde_sub_0a184c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39400008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A184CULL;
}

// FDE #1126 | PC: 0x0a1864..0x0a1900 (156 B) | Symbol: _ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE17find_first_not_ofEPKcmm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0a1864(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A1864ULL;
}

// FDE #1127 | PC: 0x0a1900..0x0a1a18 (280 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmmc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0a1900(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0118ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A1900ULL;
}

// FDE #1128 | PC: 0x0a1a18..0x0a1b34 (284 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9__grow_byEmmmmmm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_0a1a18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A1A18ULL;
}

// FDE #1129 | PC: 0x0a1b34..0x0a1b68 (52 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSEc
// EN: AArch64 prologue [bti c; ldrb w8, [x0]; tbnz w8, #0, #0xa1b50; mov w9, #2] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w8, [x0]; tbnz w8, #0, #0xa1b50; mov w9, #2]
uint64_t fde_sub_0a1b34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39400008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A1B34ULL;
}

// FDE #1130 | PC: 0x0a1b68..0x0a1bf8 (144 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6__initEPKcm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a1b68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A1B68ULL;
}

// FDE #1131 | PC: 0x0a1bf8..0x0a1c40 (72 B) | Symbol: _ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE2atEm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x0]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x0]]
uint64_t fde_sub_0a1bf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A1BF8ULL;
}

// FDE #1132 | PC: 0x0a1c40..0x0a1d68 (296 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKcm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0a1c40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0128ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A1C40ULL;
}

// FDE #1133 | PC: 0x0a1d68..0x0a1de4 (124 B) | Symbol: _ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE13find_first_ofEPKcmm
// EN: AArch64 prologue [bti c; ldrb w9, [x0]; tbnz w9, #0, #0xa1d88; add x8, x0, #1] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w9, [x0]; tbnz w9, #0, #0xa1d88; add x8, x0, #1]
uint64_t fde_sub_0a1d68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39400009ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A1D68ULL;
}

// FDE #1134 | PC: 0x0a1de4..0x0a1f34 (336 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7replaceEmmmc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_0a1de4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0150ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A1DE4ULL;
}

// FDE #1135 | PC: 0x0a1f34..0x0a1ffc (200 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKcm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a1f34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A1F34ULL;
}

// FDE #1136 | PC: 0x0a1ffc..0x0a2158 (348 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7reserveEm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_0a1ffc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x015CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A1FFCULL;
}

// FDE #1137 | PC: 0x0a2158..0x0a2224 (204 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a2158(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A2158ULL;
}

// FDE #1138 | PC: 0x0a2224..0x0a2328 (260 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignERKS5_mm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a2224(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A2224ULL;
}

// FDE #1139 | PC: 0x0a2328..0x0a23a8 (128 B) | Symbol: _ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE4copyEPcmm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0a2328(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A2328ULL;
}

// FDE #1140 | PC: 0x0a23a8..0x0a247c (212 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_mmRKS4_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0a23a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A23A8ULL;
}

// FDE #1141 | PC: 0x0a247c..0x0a24f0 (116 B) | Symbol: _ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE4findEcm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0a247c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A247CULL;
}

// FDE #1142 | PC: 0x0a24f0..0x0a2580 (144 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6__initEmc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a24f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A24F0ULL;
}

// FDE #1143 | PC: 0x0a2580..0x0a25cc (76 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a2580(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A2580ULL;
}

// FDE #1144 | PC: 0x0a25cc..0x0a2650 (132 B) | Symbol: _ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE12find_last_ofEPKcmm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a25cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A25CCULL;
}

// FDE #1145 | PC: 0x0a2650..0x0a2704 (180 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a2650(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A2650ULL;
}

// FDE #1146 | PC: 0x0a2704..0x0a27d8 (212 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEmc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0a2704(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A2704ULL;
}

// FDE #1147 | PC: 0x0a27d8..0x0a2828 (80 B) | Symbol: _ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5rfindEcm
// EN: AArch64 prologue [bti c; ldrb w9, [x0]; tbnz w9, #0, #0xa27f4; add x8, x0, #1] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w9, [x0]; tbnz w9, #0, #0xa27f4; add x8, x0, #1]
uint64_t fde_sub_0a27d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39400009ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A27D8ULL;
}

// FDE #1148 | PC: 0x0a2828..0x0a2970 (328 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEmc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0a2828(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0148ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A2828ULL;
}

// FDE #1149 | PC: 0x0a2970..0x0a2a4c (220 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5eraseEmm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a2970(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A2970ULL;
}

// FDE #1150 | PC: 0x0a2a4c..0x0a2b54 (264 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendERKS5_mm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a2a4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0108ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A2A4CULL;
}

// FDE #1151 | PC: 0x0a2b54..0x0a2be4 (144 B) | Symbol: _ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7compareEPKc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a2b54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A2B54ULL;
}

// FDE #1152 | PC: 0x0a2be4..0x0a2c80 (156 B) | Symbol: _ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7compareEmmPKcm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0a2be4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A2BE4ULL;
}

// FDE #1153 | PC: 0x0a2c80..0x0a2d44 (196 B) | Symbol: _ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7compareEmmPKc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0a2c80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A2C80ULL;
}

// FDE #1154 | PC: 0x0a2d44..0x0a2d8c (72 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE2atEm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x0]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x0]]
uint64_t fde_sub_0a2d44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A2D44ULL;
}

// FDE #1155 | PC: 0x0a2d8c..0x0a2e60 (212 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a2d8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A2D8CULL;
}

// FDE #1156 | PC: 0x0a2e60..0x0a2f34 (212 B) | Symbol: _ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE4findEPKcmm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0a2e60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A2E60ULL;
}

// FDE #1157 | PC: 0x0a2f34..0x0a2fe4 (176 B) | Symbol: _ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7compareEmmRKS5_mm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0a2f34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A2F34ULL;
}

// FDE #1158 | PC: 0x0a2fe4..0x0a30ec (264 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a2fe4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0108ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A2FE4ULL;
}

// FDE #1159 | PC: 0x0a30ec..0x0a31cc (224 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0a30ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A30ECULL;
}

// FDE #1160 | PC: 0x0a31cc..0x0a3224 (88 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7replaceEmmRKS5_mm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x3]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x3]]
uint64_t fde_sub_0a31cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A31CCULL;
}

// FDE #1161 | PC: 0x0a3224..0x0a3310 (236 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertENS_11__wrap_iterIPKcEEc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0a3224(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A3224ULL;
}

// FDE #1162 | PC: 0x0a3310..0x0a3374 (100 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6resizeEmc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x0]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x0]]
uint64_t fde_sub_0a3310(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A3310ULL;
}

// FDE #1163 | PC: 0x0a3374..0x0a33cc (88 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmRKS5_mm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x2]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x2]]
uint64_t fde_sub_0a3374(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A3374ULL;
}

// FDE #1164 | PC: 0x0a33cc..0x0a35c4 (504 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE7replaceEmmPKwm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_0a33cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A33CCULL;
}

// FDE #1165 | PC: 0x0a35c4..0x0a3724 (352 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE21__grow_by_and_replaceEmmmmmmPKw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_0a35c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0160ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A35C4ULL;
}

// FDE #1166 | PC: 0x0a3724..0x0a37f4 (208 B) | Symbol: _ZNKSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE5rfindEPKwmm
// EN: AArch64 prologue [bti c; ldrb w9, [x0]; tbnz w9, #0, #0xa373c; add x8, x0, #4] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w9, [x0]; tbnz w9, #0, #0xa373c; add x8, x0, #4]
uint64_t fde_sub_0a3724(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39400009ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A3724ULL;
}

// FDE #1167 | PC: 0x0a37f4..0x0a3890 (156 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6__initEPKwmm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a37f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A37F4ULL;
}

// FDE #1168 | PC: 0x0a3890..0x0a3938 (168 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEEC1ERKS5_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a3890(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A3890ULL;
}

// FDE #1169 | PC: 0x0a3938..0x0a398c (84 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE7replaceEmmPKw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a3938(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A3938ULL;
}

// FDE #1170 | PC: 0x0a398c..0x0a3a34 (168 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEEC1ERKS5_RKS4_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a398c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A398CULL;
}

// FDE #1171 | PC: 0x0a3a34..0x0a3ac0 (140 B) | Symbol: _ZNKSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE16find_last_not_ofEPKwmm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a3a34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A3A34ULL;
}

// FDE #1172 | PC: 0x0a3ac0..0x0a3ad8 (24 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEED1Ev
// EN: AArch64 prologue [bti c; ldrb w8, [x0]; tbnz w8, #0, #0xa3ad0; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w8, [x0]; tbnz w8, #0, #0xa3ad0; ret]
uint64_t fde_sub_0a3ac0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39400008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A3AC0ULL;
}

// FDE #1173 | PC: 0x0a3ad8..0x0a3b84 (172 B) | Symbol: _ZNKSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE17find_first_not_ofEPKwmm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0a3ad8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A3AD8ULL;
}

// FDE #1174 | PC: 0x0a3b84..0x0a3ca4 (288 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6insertEmmw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0a3b84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0120ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A3B84ULL;
}

// FDE #1175 | PC: 0x0a3ca4..0x0a3ddc (312 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE9__grow_byEmmmmmm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_0a3ca4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0138ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A3CA4ULL;
}

// FDE #1176 | PC: 0x0a3ddc..0x0a3e10 (52 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEEaSEw
// EN: AArch64 prologue [bti c; ldrb w8, [x0]; tbnz w8, #0, #0xa3dfc; mov w9, #2] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w8, [x0]; tbnz w8, #0, #0xa3dfc; mov w9, #2]
uint64_t fde_sub_0a3ddc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39400008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A3DDCULL;
}

// FDE #1177 | PC: 0x0a3e10..0x0a3ea8 (152 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6__initEPKwm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a3e10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A3E10ULL;
}

// FDE #1178 | PC: 0x0a3ea8..0x0a3ef0 (72 B) | Symbol: _ZNKSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE2atEm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x0]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x0]]
uint64_t fde_sub_0a3ea8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A3EA8ULL;
}

// FDE #1179 | PC: 0x0a3ef0..0x0a4024 (308 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6insertEmPKwm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0a3ef0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0134ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A3EF0ULL;
}

// FDE #1180 | PC: 0x0a4024..0x0a40a8 (132 B) | Symbol: _ZNKSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE13find_first_ofEPKwmm
// EN: AArch64 prologue [bti c; ldrb w9, [x0]; tbnz w9, #0, #0xa4044; add x8, x0, #4] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w9, [x0]; tbnz w9, #0, #0xa4044; add x8, x0, #4]
uint64_t fde_sub_0a4024(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39400009ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A4024ULL;
}

// FDE #1181 | PC: 0x0a40a8..0x0a4200 (344 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE7replaceEmmmw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_0a40a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0158ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A40A8ULL;
}

// FDE #1182 | PC: 0x0a4200..0x0a42cc (204 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6assignEPKwm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a4200(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A4200ULL;
}

// FDE #1183 | PC: 0x0a42cc..0x0a4454 (392 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE7reserveEm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_0a42cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0188ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A42CCULL;
}

// FDE #1184 | PC: 0x0a4454..0x0a4524 (208 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6appendEPKwm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a4454(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A4454ULL;
}

// FDE #1185 | PC: 0x0a4524..0x0a457c (88 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6assignERKS5_mm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x1]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x1]]
uint64_t fde_sub_0a4524(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A4524ULL;
}

// FDE #1186 | PC: 0x0a457c..0x0a4600 (132 B) | Symbol: _ZNKSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE4copyEPwmm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0a457c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A457CULL;
}

// FDE #1187 | PC: 0x0a4600..0x0a46dc (220 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEEC2ERKS5_mmRKS4_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0a4600(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A4600ULL;
}

// FDE #1188 | PC: 0x0a46dc..0x0a4750 (116 B) | Symbol: _ZNKSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE4findEwm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0a46dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A46DCULL;
}

// FDE #1189 | PC: 0x0a4750..0x0a47e8 (152 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6__initEmw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a4750(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A4750ULL;
}

// FDE #1190 | PC: 0x0a47e8..0x0a4834 (76 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6insertEmPKw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a47e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A47E8ULL;
}

// FDE #1191 | PC: 0x0a4834..0x0a48bc (136 B) | Symbol: _ZNKSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE12find_last_ofEPKwmm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a4834(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A4834ULL;
}

// FDE #1192 | PC: 0x0a48bc..0x0a496c (176 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE9push_backEw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a48bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A48BCULL;
}

// FDE #1193 | PC: 0x0a496c..0x0a4a44 (216 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6appendEmw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0a496c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A496CULL;
}

// FDE #1194 | PC: 0x0a4a44..0x0a4a9c (88 B) | Symbol: _ZNKSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE5rfindEwm
// EN: AArch64 prologue [bti c; ldrb w9, [x0]; tbnz w9, #0, #0xa4a60; add x8, x0, #4] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w9, [x0]; tbnz w9, #0, #0xa4a60; add x8, x0, #4]
uint64_t fde_sub_0a4a44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39400009ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A4A44ULL;
}

// FDE #1195 | PC: 0x0a4a9c..0x0a4b6c (208 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6assignEmw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a4a9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A4A9CULL;
}

// FDE #1196 | PC: 0x0a4b6c..0x0a4c4c (224 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE5eraseEmm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a4b6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A4B6CULL;
}

// FDE #1197 | PC: 0x0a4c4c..0x0a4ca4 (88 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6appendERKS5_mm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x1]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x1]]
uint64_t fde_sub_0a4c4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A4C4CULL;
}

// FDE #1198 | PC: 0x0a4ca4..0x0a4d34 (144 B) | Symbol: _ZNKSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE7compareEPKw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a4ca4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A4CA4ULL;
}

// FDE #1199 | PC: 0x0a4d34..0x0a4dd0 (156 B) | Symbol: _ZNKSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE7compareEmmPKwm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0a4d34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A4D34ULL;
}

// FDE #1200 | PC: 0x0a4dd0..0x0a4e94 (196 B) | Symbol: _ZNKSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE7compareEmmPKw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0a4dd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A4DD0ULL;
}

// FDE #1201 | PC: 0x0a4e94..0x0a4edc (72 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE2atEm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x0]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x0]]
uint64_t fde_sub_0a4e94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A4E94ULL;
}

// FDE #1202 | PC: 0x0a4edc..0x0a4f18 (60 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6assignEPKw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0a4edc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A4EDCULL;
}

// FDE #1203 | PC: 0x0a4f18..0x0a4ff8 (224 B) | Symbol: _ZNKSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE4findEPKwmm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0a4f18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A4F18ULL;
}

// FDE #1204 | PC: 0x0a4ff8..0x0a50ac (180 B) | Symbol: _ZNKSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE7compareEmmRKS5_mm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0a4ff8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A4FF8ULL;
}

// FDE #1205 | PC: 0x0a50ac..0x0a51c0 (276 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEEaSERKS5_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a50ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A50ACULL;
}

// FDE #1206 | PC: 0x0a51c0..0x0a51fc (60 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6appendEPKw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0a51c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A51C0ULL;
}

// FDE #1207 | PC: 0x0a51fc..0x0a5254 (88 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE7replaceEmmRKS5_mm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x3]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x3]]
uint64_t fde_sub_0a51fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A51FCULL;
}

// FDE #1208 | PC: 0x0a5254..0x0a534c (248 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6insertENS_11__wrap_iterIPKwEEw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0a5254(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A5254ULL;
}

// FDE #1209 | PC: 0x0a534c..0x0a53b0 (100 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6resizeEmw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x0]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x0]]
uint64_t fde_sub_0a534c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A534CULL;
}

// FDE #1210 | PC: 0x0a53b0..0x0a5408 (88 B) | Symbol: _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6insertEmRKS5_mm
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x2]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x2]]
uint64_t fde_sub_0a53b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A53B0ULL;
}

// FDE #1211 | PC: 0x0a5408..0x0a5598 (400 B) | Symbol: _ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EEPKS6_RKS9_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x50]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x50]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_0a5408(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0190ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A5408ULL;
}

// FDE #1212 | PC: 0x0a5598..0x0a57e4 (588 B) | Symbol: _ZNSt6__ndk14stoiERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPmi
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; stp x24, x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; stp x24, x23, [sp, #0x50]]
uint64_t fde_sub_0a5598(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x024CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A5598ULL;
}

// FDE #1213 | PC: 0x0a57e4..0x0a5a38 (596 B) | Symbol: _ZNSt6__ndk14stoiERKNS_12basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEEEPmi
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; stp x24, x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; stp x24, x23, [sp, #0x50]]
uint64_t fde_sub_0a57e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0254ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A57E4ULL;
}

// FDE #1214 | PC: 0x0a5a38..0x0a5c24 (492 B) | Symbol: _ZNSt6__ndk14stolERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPmi
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; stp x24, x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; stp x24, x23, [sp, #0x50]]
uint64_t fde_sub_0a5a38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A5A38ULL;
}

// FDE #1215 | PC: 0x0a5c24..0x0a5e18 (500 B) | Symbol: _ZNSt6__ndk14stolERKNS_12basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEEEPmi
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; stp x24, x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; stp x24, x23, [sp, #0x50]]
uint64_t fde_sub_0a5c24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A5C24ULL;
}

// FDE #1216 | PC: 0x0a5e18..0x0a6008 (496 B) | Symbol: _ZNSt6__ndk15stoulERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPmi
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; stp x24, x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; stp x24, x23, [sp, #0x50]]
uint64_t fde_sub_0a5e18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A5E18ULL;
}

// FDE #1217 | PC: 0x0a6008..0x0a6200 (504 B) | Symbol: _ZNSt6__ndk15stoulERKNS_12basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEEEPmi
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; stp x24, x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; stp x24, x23, [sp, #0x50]]
uint64_t fde_sub_0a6008(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A6008ULL;
}

// FDE #1218 | PC: 0x0a6200..0x0a63f0 (496 B) | Symbol: _ZNSt6__ndk15stollERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPmi
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; stp x24, x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; stp x24, x23, [sp, #0x50]]
uint64_t fde_sub_0a6200(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A6200ULL;
}

// FDE #1219 | PC: 0x0a63f0..0x0a65e8 (504 B) | Symbol: _ZNSt6__ndk15stollERKNS_12basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEEEPmi
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; stp x24, x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; stp x24, x23, [sp, #0x50]]
uint64_t fde_sub_0a63f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A63F0ULL;
}

// FDE #1220 | PC: 0x0a65e8..0x0a67dc (500 B) | Symbol: _ZNSt6__ndk16stoullERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPmi
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; stp x24, x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; stp x24, x23, [sp, #0x50]]
uint64_t fde_sub_0a65e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A65E8ULL;
}

// FDE #1221 | PC: 0x0a67dc..0x0a69d8 (508 B) | Symbol: _ZNSt6__ndk16stoullERKNS_12basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEEEPmi
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; stp x24, x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; stp x24, x23, [sp, #0x50]]
uint64_t fde_sub_0a67dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A67DCULL;
}

// FDE #1222 | PC: 0x0a69d8..0x0a6bc4 (492 B) | Symbol: _ZNSt6__ndk14stofERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPm
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; str d8, [sp, #0x40]; stp x29, x30, [sp, #0x48]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; str d8, [sp, #0x40]; stp x29, x30, [sp, #0x48]]
uint64_t fde_sub_0a69d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A69D8ULL;
}

// FDE #1223 | PC: 0x0a6bc4..0x0a6db8 (500 B) | Symbol: _ZNSt6__ndk14stofERKNS_12basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEEEPm
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; str d8, [sp, #0x40]; stp x29, x30, [sp, #0x48]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; str d8, [sp, #0x40]; stp x29, x30, [sp, #0x48]]
uint64_t fde_sub_0a6bc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A6BC4ULL;
}

// FDE #1224 | PC: 0x0a6db8..0x0a6fa4 (492 B) | Symbol: _ZNSt6__ndk14stodERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPm
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; str d8, [sp, #0x40]; stp x29, x30, [sp, #0x48]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; str d8, [sp, #0x40]; stp x29, x30, [sp, #0x48]]
uint64_t fde_sub_0a6db8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A6DB8ULL;
}

// FDE #1225 | PC: 0x0a6fa4..0x0a7198 (500 B) | Symbol: _ZNSt6__ndk14stodERKNS_12basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEEEPm
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; str d8, [sp, #0x40]; stp x29, x30, [sp, #0x48]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; str d8, [sp, #0x40]; stp x29, x30, [sp, #0x48]]
uint64_t fde_sub_0a6fa4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A6FA4ULL;
}

// FDE #1226 | PC: 0x0a7198..0x0a7380 (488 B) | Symbol: _ZNSt6__ndk15stoldERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPm
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x50]; str x23, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x50]; str x23, [sp, #0x60]]
uint64_t fde_sub_0a7198(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10243FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A7198ULL;
}

// FDE #1227 | PC: 0x0a7380..0x0a7570 (496 B) | Symbol: _ZNSt6__ndk15stoldERKNS_12basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEEEPm
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x50]; str x23, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x50]; str x23, [sp, #0x60]]
uint64_t fde_sub_0a7380(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10243FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A7380ULL;
}

// FDE #1228 | PC: 0x0a7570..0x0a76ac (316 B) | Symbol: _ZNSt6__ndk19to_stringEi
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]]
uint64_t fde_sub_0a7570(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x013CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A7570ULL;
}

// FDE #1229 | PC: 0x0a76ac..0x0a77e8 (316 B) | Symbol: _ZNSt6__ndk19to_stringEl
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]]
uint64_t fde_sub_0a76ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x013CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A76ACULL;
}

// FDE #1230 | PC: 0x0a77e8..0x0a7924 (316 B) | Symbol: _ZNSt6__ndk19to_stringEx
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]]
uint64_t fde_sub_0a77e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x013CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A77E8ULL;
}

// FDE #1231 | PC: 0x0a7924..0x0a7a38 (276 B) | Symbol: _ZNSt6__ndk19to_stringEj
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]]
uint64_t fde_sub_0a7924(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A7924ULL;
}

// FDE #1232 | PC: 0x0a7a38..0x0a7b4c (276 B) | Symbol: _ZNSt6__ndk19to_stringEm
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]]
uint64_t fde_sub_0a7a38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A7A38ULL;
}

// FDE #1233 | PC: 0x0a7b4c..0x0a7c60 (276 B) | Symbol: _ZNSt6__ndk19to_stringEy
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]]
uint64_t fde_sub_0a7b4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A7B4CULL;
}

// FDE #1234 | PC: 0x0a7c60..0x0a7de4 (388 B) | Symbol: _ZNSt6__ndk110to_wstringEi
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]]
uint64_t fde_sub_0a7c60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0184ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A7C60ULL;
}

// FDE #1235 | PC: 0x0a7de4..0x0a7f68 (388 B) | Symbol: _ZNSt6__ndk110to_wstringEl
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]]
uint64_t fde_sub_0a7de4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0184ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A7DE4ULL;
}

// FDE #1236 | PC: 0x0a7f68..0x0a80ec (388 B) | Symbol: _ZNSt6__ndk110to_wstringEx
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]]
uint64_t fde_sub_0a7f68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0184ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A7F68ULL;
}

// FDE #1237 | PC: 0x0a80ec..0x0a820c (288 B) | Symbol: _ZNSt6__ndk110to_wstringEj
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]]
uint64_t fde_sub_0a80ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0120ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A80ECULL;
}

// FDE #1238 | PC: 0x0a820c..0x0a832c (288 B) | Symbol: _ZNSt6__ndk110to_wstringEm
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]]
uint64_t fde_sub_0a820c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0120ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A820CULL;
}

// FDE #1239 | PC: 0x0a832c..0x0a844c (288 B) | Symbol: _ZNSt6__ndk110to_wstringEy
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]]
uint64_t fde_sub_0a832c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0120ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A832CULL;
}

// FDE #1240 | PC: 0x0a844c..0x0a8580 (308 B) | Symbol: _ZNSt6__ndk19to_stringEf
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; str d8, [sp, #0x20]; stp x29, x30, [sp, #0x28]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; str d8, [sp, #0x20]; stp x29, x30, [sp, #0x28]]
uint64_t fde_sub_0a844c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0134ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A844CULL;
}

// FDE #1241 | PC: 0x0a8580..0x0a86b0 (304 B) | Symbol: _ZNSt6__ndk19to_stringEd
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; str d8, [sp, #0x20]; stp x29, x30, [sp, #0x28]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; str d8, [sp, #0x20]; stp x29, x30, [sp, #0x28]]
uint64_t fde_sub_0a8580(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A8580ULL;
}

// FDE #1242 | PC: 0x0a86b0..0x0a87d8 (296 B) | Symbol: _ZNSt6__ndk19to_stringEe
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; str x23, [sp, #0x40]]
uint64_t fde_sub_0a86b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0128ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A86B0ULL;
}

// FDE #1243 | PC: 0x0a87d8..0x0a89d8 (512 B) | Symbol: _ZNSt6__ndk110to_wstringEf
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; str d8, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; str d8, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0a87d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0200ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A87D8ULL;
}

// FDE #1244 | PC: 0x0a89d8..0x0a8bd4 (508 B) | Symbol: _ZNSt6__ndk110to_wstringEd
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; str d8, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; str d8, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0a89d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A89D8ULL;
}

// FDE #1245 | PC: 0x0a8bd4..0x0a8dc8 (500 B) | Symbol: _ZNSt6__ndk110to_wstringEe
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_0a8bd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A8BD4ULL;
}

// FDE #1246 | PC: 0x0a8dc8..0x0a8e00 (56 B) | Symbol: sub_0a8dc8
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0a8dc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A8DC8ULL;
}

// FDE #1247 | PC: 0x0a8e00..0x0a8f98 (408 B) | Symbol: sub_0a8e00
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_0a8e00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0198ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A8E00ULL;
}

// FDE #1248 | PC: 0x0a8f98..0x0a909c (260 B) | Symbol: sub_0a8f98
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0a8f98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A8F98ULL;
}

// FDE #1249 | PC: 0x0a909c..0x0a9174 (216 B) | Symbol: _ZNSt6__ndk16__itoa8__u32toaEjPc
// EN: AArch64 prologue [bti c; mov w9, #0xe100; movk w9, #0x5f5, lsl #16; mov w8, w0] | VI: Khởi đầu hàm AArch64 [bti c; mov w9, #0xe100; movk w9, #0x5f5, lsl #16; mov w8, w0]
uint64_t fde_sub_0a909c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x529C2009ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A909CULL;
}

// FDE #1250 | PC: 0x0a9174..0x0a9334 (448 B) | Symbol: sub_0a9174
// EN: AArch64 prologue [bti c; lsr w8, w1, #4; cmp w8, #0x270; b.hi #0xa91a0] | VI: Khởi đầu hàm AArch64 [bti c; lsr w8, w1, #4; cmp w8, #0x270; b.hi #0xa91a0]
uint64_t fde_sub_0a9174(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x53047C28ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x01C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9174ULL;
}

// FDE #1251 | PC: 0x0a9334..0x0a9590 (604 B) | Symbol: _ZNSt6__ndk16__itoa8__u64toaEmPc
// EN: AArch64 prologue [bti c; mov w10, #0xe100; movk w10, #0x5f5, lsl #16; mov x8, x0] | VI: Khởi đầu hàm AArch64 [bti c; mov w10, #0xe100; movk w10, #0x5f5, lsl #16; mov x8, x0]
uint64_t fde_sub_0a9334(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x529C200AULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x025CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9334ULL;
}

// FDE #1252 | PC: 0x0a9590..0x0a95a8 (24 B) | Symbol: _ZNSt6__ndk114error_categoryC2Ev
// EN: AArch64 prologue [bti c; adrp x8, #0xd4000; ldr x8, [x8, #0x900]; add x8, x8, #0x10] | VI: Khởi đầu hàm AArch64 [bti c; adrp x8, #0xd4000; ldr x8, [x8, #0x900]; add x8, x8, #0x10]
uint64_t fde_sub_0a9590(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000148ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9590ULL;
}

// FDE #1253 | PC: 0x0a95a8..0x0a95b0 (8 B) | Symbol: _ZNSt6__ndk114error_categoryD0Ev
// EN: AArch64 prologue [bti c; brk #1] | VI: Khởi đầu hàm AArch64 [bti c; brk #1]
uint64_t fde_sub_0a95a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD4200020ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A95A8ULL;
}

// FDE #1254 | PC: 0x0a95b0..0x0a95c4 (20 B) | Symbol: _ZNKSt6__ndk114error_category23default_error_conditionEi
// EN: AArch64 prologue [bti c; mov w8, w1; mov x1, x0; mov x0, x8] | VI: Khởi đầu hàm AArch64 [bti c; mov w8, w1; mov x1, x0; mov x0, x8]
uint64_t fde_sub_0a95b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A0103E8ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A95B0ULL;
}

// FDE #1255 | PC: 0x0a95c4..0x0a9610 (76 B) | Symbol: _ZNKSt6__ndk114error_category10equivalentEiRKNS_15error_conditionE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0a95c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A95C4ULL;
}

// FDE #1256 | PC: 0x0a9610..0x0a9634 (36 B) | Symbol: _ZNKSt6__ndk114error_category10equivalentERKNS_10error_codeEi
// EN: AArch64 prologue [bti c; ldr x8, [x1, #8]; ldr w9, [x1]; cmp x8, x0] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x1, #8]; ldr w9, [x1]; cmp x8, x0]
uint64_t fde_sub_0a9610(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400428ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9610ULL;
}

// FDE #1257 | PC: 0x0a9634..0x0a9764 (304 B) | Symbol: sub_0a9634
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x50]!; str x28, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x50]!; str x28, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_0a9634(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9634ULL;
}

// FDE #1258 | PC: 0x0a9764..0x0a9774 (16 B) | Symbol: sub_0a9764
// EN: AArch64 prologue [bti c; adrp x0, #0x48000; add x0, x0, #0xd32; ret] | VI: Khởi đầu hàm AArch64 [bti c; adrp x0, #0x48000; add x0, x0, #0xd32; ret]
uint64_t fde_sub_0a9764(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0FFFCE0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9764ULL;
}

// FDE #1259 | PC: 0x0a9774..0x0a97e8 (116 B) | Symbol: sub_0a9774
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0a9774(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9774ULL;
}

// FDE #1260 | PC: 0x0a97e8..0x0a9848 (96 B) | Symbol: _ZNSt6__ndk116generic_categoryEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xda000] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xda000]
uint64_t fde_sub_0a97e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A97E8ULL;
}

// FDE #1261 | PC: 0x0a9848..0x0a9858 (16 B) | Symbol: sub_0a9848
// EN: AArch64 prologue [bti c; adrp x0, #0x49000; add x0, x0, #0x1c8; ret] | VI: Khởi đầu hàm AArch64 [bti c; adrp x0, #0x49000; add x0, x0, #0x1c8; ret]
uint64_t fde_sub_0a9848(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90FFFD00ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9848ULL;
}

// FDE #1262 | PC: 0x0a9858..0x0a98cc (116 B) | Symbol: sub_0a9858
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0a9858(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9858ULL;
}

// FDE #1263 | PC: 0x0a98cc..0x0a99ac (224 B) | Symbol: sub_0a98cc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0a98cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A98CCULL;
}

// FDE #1264 | PC: 0x0a99ac..0x0a9a0c (96 B) | Symbol: _ZNSt6__ndk115system_categoryEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xda000] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xda000]
uint64_t fde_sub_0a99ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A99ACULL;
}

// FDE #1265 | PC: 0x0a9a0c..0x0a9a28 (28 B) | Symbol: _ZNKSt6__ndk115error_condition7messageEv
// EN: AArch64 prologue [bti c; ldr x9, [x0, #8]; ldr w1, [x0]; ldr x10, [x9]] | VI: Khởi đầu hàm AArch64 [bti c; ldr x9, [x0, #8]; ldr w1, [x0]; ldr x10, [x9]]
uint64_t fde_sub_0a9a0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400409ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9A0CULL;
}

// FDE #1266 | PC: 0x0a9a28..0x0a9a44 (28 B) | Symbol: _ZNKSt6__ndk110error_code7messageEv
// EN: AArch64 prologue [bti c; ldr x9, [x0, #8]; ldr w1, [x0]; ldr x10, [x9]] | VI: Khởi đầu hàm AArch64 [bti c; ldr x9, [x0, #8]; ldr w1, [x0]; ldr x10, [x9]]
uint64_t fde_sub_0a9a28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400409ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9A28ULL;
}

// FDE #1267 | PC: 0x0a9a44..0x0a9b58 (276 B) | Symbol: _ZNSt6__ndk112system_error6__initERKNS_10error_codeENS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0a9a44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9A44ULL;
}

// FDE #1268 | PC: 0x0a9b58..0x0a9c54 (252 B) | Symbol: _ZNSt6__ndk112system_errorC1ENS_10error_codeERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x50]; stp x20, x19, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x50]; stp x20, x19, [sp, #0x60]]
uint64_t fde_sub_0a9b58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9B58ULL;
}

// FDE #1269 | PC: 0x0a9c54..0x0a9dc8 (372 B) | Symbol: _ZNSt6__ndk112system_errorC1ENS_10error_codeEPKc
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x50]; stp x24, x23, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x50]; stp x24, x23, [sp, #0x60]]
uint64_t fde_sub_0a9c54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10243FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0174ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9C54ULL;
}

// FDE #1270 | PC: 0x0a9dc8..0x0a9ebc (244 B) | Symbol: _ZNSt6__ndk112system_errorC2ENS_10error_codeE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x50]; stp x20, x19, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x50]; stp x20, x19, [sp, #0x60]]
uint64_t fde_sub_0a9dc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9DC8ULL;
}

// FDE #1271 | PC: 0x0a9ebc..0x0a9fcc (272 B) | Symbol: _ZNSt6__ndk112system_errorC1EiRKNS_14error_categoryERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x50]; stp x22, x21, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x50]; stp x22, x21, [sp, #0x60]]
uint64_t fde_sub_0a9ebc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0110ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9EBCULL;
}

// FDE #1272 | PC: 0x0a9fcc..0x0aa154 (392 B) | Symbol: _ZNSt6__ndk112system_errorC2EiRKNS_14error_categoryEPKc
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xa0; stp x29, x30, [sp, #0x50]; stp x26, x25, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xa0; stp x29, x30, [sp, #0x50]; stp x26, x25, [sp, #0x60]]
uint64_t fde_sub_0a9fcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10283FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0188ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9FCCULL;
}

// FDE #1273 | PC: 0x0aa154..0x0aa25c (264 B) | Symbol: _ZNSt6__ndk112system_errorC2EiRKNS_14error_categoryE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x50]; stp x22, x21, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x50]; stp x22, x21, [sp, #0x60]]
uint64_t fde_sub_0aa154(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0108ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA154ULL;
}

// FDE #1274 | PC: 0x0aa25c..0x0aa264 (8 B) | Symbol: _ZNSt6__ndk112system_errorD2Ev
// EN: AArch64 prologue [bti c; b #0xc9a00] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc9a00]
uint64_t fde_sub_0aa25c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14007DE8ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA25CULL;
}

// FDE #1275 | PC: 0x0aa264..0x0aa290 (44 B) | Symbol: _ZNSt6__ndk112system_errorD0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0aa264(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA264ULL;
}

// FDE #1276 | PC: 0x0aa290..0x0aa33c (172 B) | Symbol: _ZNSt6__ndk120__throw_system_errorEiPKc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0aa290(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA290ULL;
}

// FDE #1277 | PC: 0x0aa33c..0x0aa344 (8 B) | Symbol: _ZNSt6__ndk114error_categoryD1Ev
// EN: AArch64 prologue [bti c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ret]
uint64_t fde_sub_0aa33c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA33CULL;
}

// FDE #1278 | PC: 0x0aa344..0x0aa34c (8 B) | Symbol: sub_0aa344
// EN: AArch64 prologue [bti c; brk #1] | VI: Khởi đầu hàm AArch64 [bti c; brk #1]
uint64_t fde_sub_0aa344(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD4200020ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA344ULL;
}

// FDE #1279 | PC: 0x0aa34c..0x0aa354 (8 B) | Symbol: sub_0aa34c
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0aa34c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14007878ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA34CULL;
}

// FDE #1280 | PC: 0x0aa354..0x0aa35c (8 B) | Symbol: sub_0aa354
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0aa354(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14007876ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA354ULL;
}

// FDE #1281 | PC: 0x0aa35c..0x0aa400 (164 B) | Symbol: sub_0aa35c
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x110; stp x29, x30, [sp, #0xf0]; stp x28, x19, [sp, #0x100]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x110; stp x29, x30, [sp, #0xf0]; stp x28, x19, [sp, #0x100]]
uint64_t fde_sub_0aa35c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10443FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA35CULL;
}

// FDE #1282 | PC: 0x0aa400..0x0aa424 (36 B) | Symbol: _ZNSt6__ndk16threadD1Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0]]
uint64_t fde_sub_0aa400(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA400ULL;
}

// FDE #1283 | PC: 0x0aa424..0x0aa470 (76 B) | Symbol: _ZNSt6__ndk16thread4joinEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0aa424(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA424ULL;
}

// FDE #1284 | PC: 0x0aa470..0x0aa4b8 (72 B) | Symbol: _ZNSt6__ndk16thread6detachEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0aa470(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA470ULL;
}

// FDE #1285 | PC: 0x0aa4b8..0x0aa4e4 (44 B) | Symbol: _ZNSt6__ndk16thread20hardware_concurrencyEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w0, #0x61] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w0, #0x61]
uint64_t fde_sub_0aa4b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA4B8ULL;
}

// FDE #1286 | PC: 0x0aa4e4..0x0aa588 (164 B) | Symbol: _ZNSt6__ndk111this_thread9sleep_forERKNS_6chrono8durationIxNS_5ratioILl1ELl1000000000EEEEE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x40; stp x29, x30, [sp, #0x20]; str x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x40; stp x29, x30, [sp, #0x20]; str x19, [sp, #0x30]]
uint64_t fde_sub_0aa4e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10103FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA4E4ULL;
}

// FDE #1287 | PC: 0x0aa588..0x0aa61c (148 B) | Symbol: _ZNSt6__ndk119__thread_local_dataEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0aa588(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA588ULL;
}

// FDE #1288 | PC: 0x0aa61c..0x0aa6e4 (200 B) | Symbol: sub_0aa61c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0aa61c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA61CULL;
}

// FDE #1289 | PC: 0x0aa6e4..0x0aa700 (28 B) | Symbol: sub_0aa6e4
// EN: AArch64 prologue [bti c; mov x8, x0; ldr x0, [x0]; cbz x0, #0xaa6fc] | VI: Khởi đầu hàm AArch64 [bti c; mov x8, x0; ldr x0, [x0]; cbz x0, #0xaa6fc]
uint64_t fde_sub_0aa6e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003E8ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA6E4ULL;
}

// FDE #1290 | PC: 0x0aa700..0x0aa71c (28 B) | Symbol: sub_0aa700
// EN: AArch64 prologue [bti c; mov x8, x0; ldr x0, [x0]; cbz x0, #0xaa718] | VI: Khởi đầu hàm AArch64 [bti c; mov x8, x0; ldr x0, [x0]; cbz x0, #0xaa718]
uint64_t fde_sub_0aa700(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003E8ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA700ULL;
}

// FDE #1291 | PC: 0x0aa71c..0x0aa82c (272 B) | Symbol: sub_0aa71c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0aa71c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0110ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA71CULL;
}

// FDE #1292 | PC: 0x0aa82c..0x0aa918 (236 B) | Symbol: sub_0aa82c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0aa82c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA82CULL;
}

// FDE #1293 | PC: 0x0aa918..0x0aa954 (60 B) | Symbol: _ZNSt6__ndk115__thread_structC2Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0aa918(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA918ULL;
}

// FDE #1294 | PC: 0x0aa954..0x0aa998 (68 B) | Symbol: _ZNSt6__ndk115__thread_structD2Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0aa954(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA954ULL;
}

// FDE #1295 | PC: 0x0aa998..0x0aa9a4 (12 B) | Symbol: _ZNSt6__ndk115__thread_struct25notify_all_at_thread_exitEPNS_18condition_variableEPNS_5mutexE
// EN: AArch64 prologue [bti c; ldr x0, [x0]; b #0xaa71c] | VI: Khởi đầu hàm AArch64 [bti c; ldr x0, [x0]; b #0xaa71c]
uint64_t fde_sub_0aa998(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA998ULL;
}

// FDE #1296 | PC: 0x0aa9a4..0x0aa9b0 (12 B) | Symbol: _ZNSt6__ndk115__thread_struct27__make_ready_at_thread_exitEPNS_17__assoc_sub_stateE
// EN: AArch64 prologue [bti c; ldr x0, [x0]; b #0xaa82c] | VI: Khởi đầu hàm AArch64 [bti c; ldr x0, [x0]; b #0xaa82c]
uint64_t fde_sub_0aa9a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA9A4ULL;
}

// FDE #1297 | PC: 0x0aa9b0..0x0aa9fc (76 B) | Symbol: sub_0aa9b0
// EN: AArch64 prologue [bti c; cbz x0, #0xaa9f8; paciasp; stp x29, x30, [sp, #-0x20]!] | VI: Khởi đầu hàm AArch64 [bti c; cbz x0, #0xaa9f8; paciasp; stp x29, x30, [sp, #-0x20]!]
uint64_t fde_sub_0aa9b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000220ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA9B0ULL;
}

// FDE #1298 | PC: 0x0aa9fc..0x0aaa0c (16 B) | Symbol: sub_0aa9fc
// EN: AArch64 prologue [bti c; adrp x0, #0x49000; add x0, x0, #0xc49; ret] | VI: Khởi đầu hàm AArch64 [bti c; adrp x0, #0x49000; add x0, x0, #0xc49; ret]
uint64_t fde_sub_0aa9fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0FFFCE0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA9FCULL;
}

// FDE #1299 | PC: 0x0aaa0c..0x0aab9c (400 B) | Symbol: sub_0aaa0c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0aaa0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0190ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AAA0CULL;
}

// FDE #1300 | PC: 0x0aab9c..0x0aac28 (140 B) | Symbol: _ZNSt6__ndk115future_categoryEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0aab9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AAB9CULL;
}

// FDE #1301 | PC: 0x0aac28..0x0aacd4 (172 B) | Symbol: _ZNSt6__ndk112future_errorC1ENS_10error_codeE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_0aac28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AAC28ULL;
}

// FDE #1302 | PC: 0x0aacd4..0x0aacdc (8 B) | Symbol: _ZNSt6__ndk112future_errorD2Ev
// EN: AArch64 prologue [bti c; b #0xc9ab0] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc9ab0]
uint64_t fde_sub_0aacd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14007B76ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AACD4ULL;
}

// FDE #1303 | PC: 0x0aacdc..0x0aad08 (44 B) | Symbol: _ZNSt6__ndk112future_errorD0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0aacdc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AACDCULL;
}

// FDE #1304 | PC: 0x0aad08..0x0aad18 (16 B) | Symbol: _ZNSt6__ndk117__assoc_sub_state16__on_zero_sharedEv
// EN: AArch64 prologue [bti c; ldr x8, [x0]; ldr x16, [x8, #8]; br x16] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0]; ldr x16, [x8, #8]; br x16]
uint64_t fde_sub_0aad08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AAD08ULL;
}

// FDE #1305 | PC: 0x0aad18..0x0aadd0 (184 B) | Symbol: _ZNSt6__ndk117__assoc_sub_state9set_valueEv
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x40; stp x29, x30, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x40; stp x29, x30, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0aad18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10103FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AAD18ULL;
}

// FDE #1306 | PC: 0x0aadd0..0x0aae98 (200 B) | Symbol: sub_0aadd0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0aadd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AADD0ULL;
}

// FDE #1307 | PC: 0x0aae98..0x0aaf58 (192 B) | Symbol: _ZNSt6__ndk117__assoc_sub_state24set_value_at_thread_exitEv
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x40; stp x29, x30, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x40; stp x29, x30, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0aae98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10103FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AAE98ULL;
}

// FDE #1308 | PC: 0x0aaf58..0x0ab024 (204 B) | Symbol: _ZNSt6__ndk117__assoc_sub_state13set_exceptionESt13exception_ptr
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]]
uint64_t fde_sub_0aaf58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AAF58ULL;
}

// FDE #1309 | PC: 0x0ab024..0x0ab0f0 (204 B) | Symbol: _ZNSt6__ndk117__assoc_sub_state28set_exception_at_thread_exitESt13exception_ptr
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]]
uint64_t fde_sub_0ab024(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB024ULL;
}

// FDE #1310 | PC: 0x0ab0f0..0x0ab138 (72 B) | Symbol: _ZNSt6__ndk117__assoc_sub_state12__make_readyEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0ab0f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB0F0ULL;
}

// FDE #1311 | PC: 0x0ab138..0x0ab254 (284 B) | Symbol: _ZNSt6__ndk117__assoc_sub_state4copyEv
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x30]; str x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x30]; str x21, [sp, #0x40]]
uint64_t fde_sub_0ab138(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB138ULL;
}

// FDE #1312 | PC: 0x0ab254..0x0ab2f4 (160 B) | Symbol: _ZNSt6__ndk117__assoc_sub_state10__sub_waitERNS_11unique_lockINS_5mutexEEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0ab254(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB254ULL;
}

// FDE #1313 | PC: 0x0ab2f4..0x0ab3d8 (228 B) | Symbol: _ZNSt6__ndk117__assoc_sub_state4waitEv
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_0ab2f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB2F4ULL;
}

// FDE #1314 | PC: 0x0ab3d8..0x0ab3ec (20 B) | Symbol: _ZNSt6__ndk117__assoc_sub_state9__executeEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w0, #3] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w0, #3]
uint64_t fde_sub_0ab3d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB3D8ULL;
}

// FDE #1315 | PC: 0x0ab3ec..0x0ab45c (112 B) | Symbol: _ZNSt6__ndk16futureIvEC2EPNS_17__assoc_sub_stateE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0ab3ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB3ECULL;
}

// FDE #1316 | PC: 0x0ab45c..0x0ab470 (20 B) | Symbol: _ZNSt6__ndk16futureIvED2Ev
// EN: AArch64 prologue [bti c; ldr x0, [x0]; cbz x0, #0xab46c; b #0xc8bf0] | VI: Khởi đầu hàm AArch64 [bti c; ldr x0, [x0]; cbz x0, #0xab46c; b #0xc8bf0]
uint64_t fde_sub_0ab45c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB45CULL;
}

// FDE #1317 | PC: 0x0ab470..0x0ab4d0 (96 B) | Symbol: _ZNSt6__ndk16futureIvE3getEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0ab470(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB470ULL;
}

// FDE #1318 | PC: 0x0ab4d0..0x0ab524 (84 B) | Symbol: _ZNSt6__ndk17promiseIvEC2Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0ab4d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB4D0ULL;
}

// FDE #1319 | PC: 0x0ab524..0x0ab6ec (456 B) | Symbol: _ZNSt6__ndk17promiseIvED2Ev
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x60]; str x21, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x60]; str x21, [sp, #0x70]]
uint64_t fde_sub_0ab524(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10243FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB524ULL;
}

// FDE #1320 | PC: 0x0ab6ec..0x0ab774 (136 B) | Symbol: sub_0ab6ec
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0ab6ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB6ECULL;
}

// FDE #1321 | PC: 0x0ab774..0x0ab7f0 (124 B) | Symbol: _ZNSt6__ndk17promiseIvE10get_futureEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0ab774(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB774ULL;
}

// FDE #1322 | PC: 0x0ab7f0..0x0ab818 (40 B) | Symbol: _ZNSt6__ndk17promiseIvE9set_valueEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x0, [x0]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x0, [x0]]
uint64_t fde_sub_0ab7f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB7F0ULL;
}

// FDE #1323 | PC: 0x0ab818..0x0ab8a0 (136 B) | Symbol: _ZNSt6__ndk17promiseIvE13set_exceptionESt13exception_ptr
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x30; stp x29, x30, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x30; stp x29, x30, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0ab818(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD100C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB818ULL;
}

// FDE #1324 | PC: 0x0ab8a0..0x0ab8c8 (40 B) | Symbol: _ZNSt6__ndk17promiseIvE24set_value_at_thread_exitEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x0, [x0]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x0, [x0]]
uint64_t fde_sub_0ab8a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB8A0ULL;
}

// FDE #1325 | PC: 0x0ab8c8..0x0ab950 (136 B) | Symbol: _ZNSt6__ndk17promiseIvE28set_exception_at_thread_exitESt13exception_ptr
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x30; stp x29, x30, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x30; stp x29, x30, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0ab8c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD100C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB8C8ULL;
}

// FDE #1326 | PC: 0x0ab950..0x0ab964 (20 B) | Symbol: _ZNSt6__ndk113shared_futureIvED2Ev
// EN: AArch64 prologue [bti c; ldr x0, [x0]; cbz x0, #0xab960; b #0xc8bf0] | VI: Khởi đầu hàm AArch64 [bti c; ldr x0, [x0]; cbz x0, #0xab960; b #0xc8bf0]
uint64_t fde_sub_0ab950(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB950ULL;
}

// FDE #1327 | PC: 0x0ab964..0x0ab9b4 (80 B) | Symbol: _ZNSt6__ndk113shared_futureIvEaSERKS1_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0ab964(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB964ULL;
}

// FDE #1328 | PC: 0x0ab9b4..0x0aba08 (84 B) | Symbol: _ZNSt6__ndk117__assoc_sub_stateD2Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0ab9b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB9B4ULL;
}

// FDE #1329 | PC: 0x0aba08..0x0aba64 (92 B) | Symbol: _ZNSt6__ndk117__assoc_sub_stateD0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0aba08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ABA08ULL;
}

// FDE #1330 | PC: 0x0aba64..0x0aba90 (44 B) | Symbol: sub_0aba64
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0aba64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ABA64ULL;
}

// FDE #1331 | PC: 0x0aba90..0x0abaa8 (24 B) | Symbol: _ZNKSt6__ndk120__vector_base_commonILb1EE20__throw_length_errorEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0x49000] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0x49000]
uint64_t fde_sub_0aba90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ABA90ULL;
}

// FDE #1332 | PC: 0x0abaa8..0x0abac0 (24 B) | Symbol: _ZNKSt6__ndk120__vector_base_commonILb1EE20__throw_out_of_rangeEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0x49000] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0x49000]
uint64_t fde_sub_0abaa8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ABAA8ULL;
}

// FDE #1333 | PC: 0x0abac0..0x0abbe4 (292 B) | Symbol: sub_0abac0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x28, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x28, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0abac0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0124ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ABAC0ULL;
}

// FDE #1334 | PC: 0x0abbe4..0x0abc04 (32 B) | Symbol: sub_0abbe4
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x9, #0x48000] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x9, #0x48000]
uint64_t fde_sub_0abbe4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ABBE4ULL;
}

// FDE #1335 | PC: 0x0abc04..0x0abc30 (44 B) | Symbol: _ZSt14set_unexpectedPFvvE
// EN: AArch64 prologue [bti c; adrp x9, #0xd4000; ldr x9, [x9, #0x948]; adrp x8, #0xab000] | VI: Khởi đầu hàm AArch64 [bti c; adrp x9, #0xd4000; ldr x9, [x9, #0x948]; adrp x8, #0xab000]
uint64_t fde_sub_0abc04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000149ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ABC04ULL;
}

// FDE #1336 | PC: 0x0abc30..0x0abc5c (44 B) | Symbol: _ZSt13set_terminatePFvvE
// EN: AArch64 prologue [bti c; adrp x9, #0xd4000; ldr x9, [x9, #0x950]; adrp x8, #0xab000] | VI: Khởi đầu hàm AArch64 [bti c; adrp x9, #0xd4000; ldr x9, [x9, #0x950]; adrp x8, #0xab000]
uint64_t fde_sub_0abc30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000149ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ABC30ULL;
}

// FDE #1337 | PC: 0x0abc5c..0x0abd50 (244 B) | Symbol: sub_0abc5c
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x1a0; stp x29, x30, [sp, #0x150]; stp x28, x25, [sp, #0x160]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x1a0; stp x29, x30, [sp, #0x150]; stp x28, x25, [sp, #0x160]]
uint64_t fde_sub_0abc5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10683FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ABC5CULL;
}

// FDE #1338 | PC: 0x0abd50..0x0ac4a8 (1880 B) | Symbol: __cxa_demangle
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_0abd50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0758ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ABD50ULL;
}

// FDE #1339 | PC: 0x0ac4a8..0x0ad15c (3252 B) | Symbol: sub_0ac4a8
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x30]; str x27, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x30]; str x27, [sp, #0x40]]
uint64_t fde_sub_0ac4a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10243FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0CB4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AC4A8ULL;
}

// FDE #1340 | PC: 0x0ad15c..0x0ae960 (6148 B) | Symbol: sub_0ad15c
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_0ad15c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x1804ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD15CULL;
}

// FDE #1341 | PC: 0x0ae960..0x0af4a8 (2888 B) | Symbol: sub_0ae960
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x20]; stp x28, x27, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x20]; stp x28, x27, [sp, #0x30]]
uint64_t fde_sub_0ae960(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0B48ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AE960ULL;
}

// FDE #1342 | PC: 0x0af4a8..0x0af698 (496 B) | Symbol: sub_0af4a8
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]]
uint64_t fde_sub_0af4a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AF4A8ULL;
}

// FDE #1343 | PC: 0x0af698..0x0af75c (196 B) | Symbol: sub_0af698
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0af698(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AF698ULL;
}

// FDE #1344 | PC: 0x0af75c..0x0af96c (528 B) | Symbol: sub_0af75c
// EN: AArch64 prologue [bti c; ldp x10, x9, [x0]; cmp x10, x9; b.eq #0xaf8f8] | VI: Khởi đầu hàm AArch64 [bti c; ldp x10, x9, [x0]; cmp x10, x9; b.eq #0xaf8f8]
uint64_t fde_sub_0af75c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA940240AULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0210ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AF75CULL;
}

// FDE #1345 | PC: 0x0af96c..0x0af978 (12 B) | Symbol: sub_0af96c
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_0af96c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AF96CULL;
}

// FDE #1346 | PC: 0x0af978..0x0af984 (12 B) | Symbol: sub_0af978
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_0af978(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AF978ULL;
}

// FDE #1347 | PC: 0x0af984..0x0af990 (12 B) | Symbol: sub_0af984
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_0af984(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AF984ULL;
}

// FDE #1348 | PC: 0x0af990..0x0af998 (8 B) | Symbol: sub_0af990
// EN: AArch64 prologue [bti c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ret]
uint64_t fde_sub_0af990(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AF990ULL;
}

// FDE #1349 | PC: 0x0af998..0x0afa78 (224 B) | Symbol: sub_0af998
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0af998(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AF998ULL;
}

// FDE #1350 | PC: 0x0afa78..0x0afa80 (8 B) | Symbol: sub_0afa78
// EN: AArch64 prologue [bti c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ret]
uint64_t fde_sub_0afa78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AFA78ULL;
}

// FDE #1351 | PC: 0x0afa80..0x0afa90 (16 B) | Symbol: sub_0afa80
// EN: AArch64 prologue [bti c; mov x0, xzr; mov x1, xzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov x0, xzr; mov x1, xzr; ret]
uint64_t fde_sub_0afa80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AFA80ULL;
}

// FDE #1352 | PC: 0x0afa90..0x0afa98 (8 B) | Symbol: sub_0afa90
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0afa90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140062A7ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AFA90ULL;
}

// FDE #1353 | PC: 0x0afa98..0x0afc04 (364 B) | Symbol: sub_0afa98
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0afa98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x016CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AFA98ULL;
}

// FDE #1354 | PC: 0x0afc04..0x0afc0c (8 B) | Symbol: sub_0afc04
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0afc04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400624AULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AFC04ULL;
}

// FDE #1355 | PC: 0x0afc0c..0x0affa8 (924 B) | Symbol: sub_0afc0c
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x40; stp x29, x30, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x40; stp x29, x30, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0afc0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10103FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x039CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AFC0CULL;
}

// FDE #1356 | PC: 0x0affa8..0x0b0418 (1136 B) | Symbol: sub_0affa8
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xd0; stp x29, x30, [sp, #0x70]; stp x28, x27, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xd0; stp x29, x30, [sp, #0x70]; stp x28, x27, [sp, #0x80]]
uint64_t fde_sub_0affa8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10343FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0470ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AFFA8ULL;
}

// FDE #1357 | PC: 0x0b0418..0x0b07c0 (936 B) | Symbol: sub_0b0418
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_0b0418(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x03A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0418ULL;
}

// FDE #1358 | PC: 0x0b07c0..0x0b08e8 (296 B) | Symbol: sub_0b07c0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0b07c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0128ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B07C0ULL;
}

// FDE #1359 | PC: 0x0b08e8..0x0b0b50 (616 B) | Symbol: sub_0b08e8
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0b08e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0268ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B08E8ULL;
}

// FDE #1360 | PC: 0x0b0b50..0x0b0cc8 (376 B) | Symbol: sub_0b0b50
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x50]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x50]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_0b0b50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0B50ULL;
}

// FDE #1361 | PC: 0x0b0cc8..0x0b0ea4 (476 B) | Symbol: sub_0b0cc8
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]]
uint64_t fde_sub_0b0cc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0CC8ULL;
}

// FDE #1362 | PC: 0x0b0ea4..0x0b0f38 (148 B) | Symbol: sub_0b0ea4
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0b0ea4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0EA4ULL;
}

// FDE #1363 | PC: 0x0b0f38..0x0b0f48 (16 B) | Symbol: sub_0b0f38
// EN: AArch64 prologue [bti c; ldp x8, x1, [x0, #0x10]; mov x0, x8; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldp x8, x1, [x0, #0x10]; mov x0, x8; ret]
uint64_t fde_sub_0b0f38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9410408ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0F38ULL;
}

// FDE #1364 | PC: 0x0b0f48..0x0b0f50 (8 B) | Symbol: sub_0b0f48
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0b0f48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14005D79ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0F48ULL;
}

// FDE #1365 | PC: 0x0b0f50..0x0b1050 (256 B) | Symbol: sub_0b0f50
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0b0f50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0F50ULL;
}

// FDE #1366 | PC: 0x0b1050..0x0b1064 (20 B) | Symbol: sub_0b1050
// EN: AArch64 prologue [bti c; ldr x0, [x0, #0x18]; ldr x8, [x0]; ldr x16, [x8, #0x30]] | VI: Khởi đầu hàm AArch64 [bti c; ldr x0, [x0, #0x18]; ldr x8, [x0]; ldr x16, [x8, #0x30]]
uint64_t fde_sub_0b1050(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400C00ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B1050ULL;
}

// FDE #1367 | PC: 0x0b1064..0x0b106c (8 B) | Symbol: sub_0b1064
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0b1064(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14005D32ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B1064ULL;
}

// FDE #1368 | PC: 0x0b106c..0x0b1130 (196 B) | Symbol: sub_0b106c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0b106c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B106CULL;
}

// FDE #1369 | PC: 0x0b1130..0x0b11a8 (120 B) | Symbol: sub_0b1130
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0b1130(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B1130ULL;
}

// FDE #1370 | PC: 0x0b11a8..0x0b1220 (120 B) | Symbol: sub_0b11a8
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0b11a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B11A8ULL;
}

// FDE #1371 | PC: 0x0b1220..0x0b1298 (120 B) | Symbol: sub_0b1220
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0b1220(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B1220ULL;
}

// FDE #1372 | PC: 0x0b1298..0x0b12f0 (88 B) | Symbol: sub_0b1298
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0b1298(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B1298ULL;
}

// FDE #1373 | PC: 0x0b12f0..0x0b1340 (80 B) | Symbol: sub_0b12f0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0b12f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B12F0ULL;
}

// FDE #1374 | PC: 0x0b1340..0x0b1390 (80 B) | Symbol: sub_0b1340
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0b1340(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B1340ULL;
}

// FDE #1375 | PC: 0x0b1390..0x0b1398 (8 B) | Symbol: sub_0b1390
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0b1390(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14005C67ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B1390ULL;
}

// FDE #1376 | PC: 0x0b1398..0x0b3368 (8144 B) | Symbol: sub_0b1398
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; stp x26, x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; stp x26, x25, [sp, #0x30]]
uint64_t fde_sub_0b1398(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x1FD0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B1398ULL;
}

// FDE #1377 | PC: 0x0b3368..0x0b3e48 (2784 B) | Symbol: sub_0b3368
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0b3368(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0AE0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B3368ULL;
}

// FDE #1378 | PC: 0x0b3e48..0x0b4108 (704 B) | Symbol: sub_0b3e48
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0b3e48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x02C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B3E48ULL;
}

// FDE #1379 | PC: 0x0b4108..0x0b4710 (1544 B) | Symbol: sub_0b4108
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_0b4108(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0608ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B4108ULL;
}

// FDE #1380 | PC: 0x0b4710..0x0b47c8 (184 B) | Symbol: sub_0b4710
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0b4710(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B4710ULL;
}

// FDE #1381 | PC: 0x0b47c8..0x0b4e04 (1596 B) | Symbol: sub_0b47c8
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_0b47c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x063CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B47C8ULL;
}

// FDE #1382 | PC: 0x0b4e04..0x0b503c (568 B) | Symbol: sub_0b4e04
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0b4e04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0238ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B4E04ULL;
}

// FDE #1383 | PC: 0x0b503c..0x0b51a4 (360 B) | Symbol: sub_0b503c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0b503c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0168ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B503CULL;
}

// FDE #1384 | PC: 0x0b51a4..0x0b5780 (1500 B) | Symbol: sub_0b51a4
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xe0; stp x29, x30, [sp, #0x80]; stp x28, x27, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xe0; stp x29, x30, [sp, #0x80]; stp x28, x27, [sp, #0x90]]
uint64_t fde_sub_0b51a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10383FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x05DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B51A4ULL;
}

// FDE #1385 | PC: 0x0b5780..0x0b5a64 (740 B) | Symbol: sub_0b5780
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0b5780(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x02E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B5780ULL;
}

// FDE #1386 | PC: 0x0b5a64..0x0b5a6c (8 B) | Symbol: sub_0b5a64
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0b5a64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14004AB2ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B5A64ULL;
}

// FDE #1387 | PC: 0x0b5a6c..0x0b5b24 (184 B) | Symbol: sub_0b5a6c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0b5a6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B5A6CULL;
}

// FDE #1388 | PC: 0x0b5b24..0x0b5b2c (8 B) | Symbol: sub_0b5b24
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0b5b24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14004A82ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B5B24ULL;
}

// FDE #1389 | PC: 0x0b5b2c..0x0b5d18 (492 B) | Symbol: sub_0b5b2c
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x30]; str x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x30]; str x21, [sp, #0x40]]
uint64_t fde_sub_0b5b2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B5B2CULL;
}

// FDE #1390 | PC: 0x0b5d18..0x0b5d20 (8 B) | Symbol: sub_0b5d18
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0b5d18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14004A05ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B5D18ULL;
}

// FDE #1391 | PC: 0x0b5d20..0x0b5dcc (172 B) | Symbol: sub_0b5d20
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x110; stp x29, x30, [sp, #0xf0]; stp x28, x19, [sp, #0x100]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x110; stp x29, x30, [sp, #0xf0]; stp x28, x19, [sp, #0x100]]
uint64_t fde_sub_0b5d20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10443FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B5D20ULL;
}

// FDE #1392 | PC: 0x0b5dcc..0x0b607c (688 B) | Symbol: sub_0b5dcc
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x40]; str x21, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x40]; str x21, [sp, #0x50]]
uint64_t fde_sub_0b5dcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x02B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B5DCCULL;
}

// FDE #1393 | PC: 0x0b607c..0x0b6084 (8 B) | Symbol: sub_0b607c
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0b607c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400492CULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B607CULL;
}

// FDE #1394 | PC: 0x0b6084..0x0b6314 (656 B) | Symbol: sub_0b6084
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x40]; str x21, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x40]; str x21, [sp, #0x50]]
uint64_t fde_sub_0b6084(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0290ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B6084ULL;
}

// FDE #1395 | PC: 0x0b6314..0x0b631c (8 B) | Symbol: sub_0b6314
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0b6314(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14004886ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B6314ULL;
}

// FDE #1396 | PC: 0x0b631c..0x0b6420 (260 B) | Symbol: sub_0b631c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0b631c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B631CULL;
}

// FDE #1397 | PC: 0x0b6420..0x0b6428 (8 B) | Symbol: sub_0b6420
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0b6420(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14004843ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B6420ULL;
}

// FDE #1398 | PC: 0x0b6428..0x0b697c (1364 B) | Symbol: sub_0b6428
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xd0; stp x29, x30, [sp, #0x80]; str x25, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xd0; stp x29, x30, [sp, #0x80]; str x25, [sp, #0x90]]
uint64_t fde_sub_0b6428(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10343FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0554ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B6428ULL;
}

// FDE #1399 | PC: 0x0b697c..0x0b6ac0 (324 B) | Symbol: sub_0b697c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0b697c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0144ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B697CULL;
}

// FDE #1400 | PC: 0x0b6ac0..0x0b6ac8 (8 B) | Symbol: sub_0b6ac0
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0b6ac0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400469BULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B6AC0ULL;
}

// FDE #1401 | PC: 0x0b6ac8..0x0b6b8c (196 B) | Symbol: sub_0b6ac8
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0b6ac8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B6AC8ULL;
}

// FDE #1402 | PC: 0x0b6b8c..0x0b6e10 (644 B) | Symbol: sub_0b6b8c
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0b6b8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0284ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B6B8CULL;
}

// FDE #1403 | PC: 0x0b6e10..0x0b6e18 (8 B) | Symbol: sub_0b6e10
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0b6e10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140045C7ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B6E10ULL;
}

// FDE #1404 | PC: 0x0b6e18..0x0b6ea4 (140 B) | Symbol: sub_0b6e18
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0b6e18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B6E18ULL;
}

// FDE #1405 | PC: 0x0b6ea4..0x0b6f08 (100 B) | Symbol: sub_0b6ea4
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0b6ea4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B6EA4ULL;
}

// FDE #1406 | PC: 0x0b6f08..0x0b6f10 (8 B) | Symbol: sub_0b6f08
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0b6f08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14004589ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B6F08ULL;
}

// FDE #1407 | PC: 0x0b6f10..0x0b6fc4 (180 B) | Symbol: sub_0b6f10
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0b6f10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B6F10ULL;
}

uint64_t DispatchAppLovinShard4(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x0a00d0ULL: return fde_sub_0a00d0(a0, a1, a2);
        case 0x0a00dcULL: return fde_sub_0a00dc(a0, a1, a2);
        case 0x0a00e4ULL: return fde_sub_0a00e4(a0, a1, a2);
        case 0x0a0134ULL: return fde_sub_0a0134(a0, a1, a2);
        case 0x0a0160ULL: return fde_sub_0a0160(a0, a1, a2);
        case 0x0a0188ULL: return fde_sub_0a0188(a0, a1, a2);
        case 0x0a01a8ULL: return fde_sub_0a01a8(a0, a1, a2);
        case 0x0a0274ULL: return fde_sub_0a0274(a0, a1, a2);
        case 0x0a0294ULL: return fde_sub_0a0294(a0, a1, a2);
        case 0x0a02c0ULL: return fde_sub_0a02c0(a0, a1, a2);
        case 0x0a02e0ULL: return fde_sub_0a02e0(a0, a1, a2);
        case 0x0a0308ULL: return fde_sub_0a0308(a0, a1, a2);
        case 0x0a0324ULL: return fde_sub_0a0324(a0, a1, a2);
        case 0x0a0390ULL: return fde_sub_0a0390(a0, a1, a2);
        case 0x0a044cULL: return fde_sub_0a044c(a0, a1, a2);
        case 0x0a04acULL: return fde_sub_0a04ac(a0, a1, a2);
        case 0x0a0500ULL: return fde_sub_0a0500(a0, a1, a2);
        case 0x0a051cULL: return fde_sub_0a051c(a0, a1, a2);
        case 0x0a0588ULL: return fde_sub_0a0588(a0, a1, a2);
        case 0x0a06b4ULL: return fde_sub_0a06b4(a0, a1, a2);
        case 0x0a0754ULL: return fde_sub_0a0754(a0, a1, a2);
        case 0x0a07d0ULL: return fde_sub_0a07d0(a0, a1, a2);
        case 0x0a0900ULL: return fde_sub_0a0900(a0, a1, a2);
        case 0x0a0920ULL: return fde_sub_0a0920(a0, a1, a2);
        case 0x0a0940ULL: return fde_sub_0a0940(a0, a1, a2);
        case 0x0a0990ULL: return fde_sub_0a0990(a0, a1, a2);
        case 0x0a0a5cULL: return fde_sub_0a0a5c(a0, a1, a2);
        case 0x0a0aecULL: return fde_sub_0a0aec(a0, a1, a2);
        case 0x0a0b0cULL: return fde_sub_0a0b0c(a0, a1, a2);
        case 0x0a0b2cULL: return fde_sub_0a0b2c(a0, a1, a2);
        case 0x0a0b64ULL: return fde_sub_0a0b64(a0, a1, a2);
        case 0x0a0bd0ULL: return fde_sub_0a0bd0(a0, a1, a2);
        case 0x0a0c00ULL: return fde_sub_0a0c00(a0, a1, a2);
        case 0x0a0c08ULL: return fde_sub_0a0c08(a0, a1, a2);
        case 0x0a0c38ULL: return fde_sub_0a0c38(a0, a1, a2);
        case 0x0a0c40ULL: return fde_sub_0a0c40(a0, a1, a2);
        case 0x0a0c48ULL: return fde_sub_0a0c48(a0, a1, a2);
        case 0x0a0c50ULL: return fde_sub_0a0c50(a0, a1, a2);
        case 0x0a0c58ULL: return fde_sub_0a0c58(a0, a1, a2);
        case 0x0a0c60ULL: return fde_sub_0a0c60(a0, a1, a2);
        case 0x0a0c68ULL: return fde_sub_0a0c68(a0, a1, a2);
        case 0x0a0d1cULL: return fde_sub_0a0d1c(a0, a1, a2);
        case 0x0a0d4cULL: return fde_sub_0a0d4c(a0, a1, a2);
        case 0x0a0d54ULL: return fde_sub_0a0d54(a0, a1, a2);
        case 0x0a0d84ULL: return fde_sub_0a0d84(a0, a1, a2);
        case 0x0a0d8cULL: return fde_sub_0a0d8c(a0, a1, a2);
        case 0x0a0d94ULL: return fde_sub_0a0d94(a0, a1, a2);
        case 0x0a0da0ULL: return fde_sub_0a0da0(a0, a1, a2);
        case 0x0a0da8ULL: return fde_sub_0a0da8(a0, a1, a2);
        case 0x0a0db0ULL: return fde_sub_0a0db0(a0, a1, a2);
        case 0x0a0dbcULL: return fde_sub_0a0dbc(a0, a1, a2);
        case 0x0a0e54ULL: return fde_sub_0a0e54(a0, a1, a2);
        case 0x0a0ee0ULL: return fde_sub_0a0ee0(a0, a1, a2);
        case 0x0a0f14ULL: return fde_sub_0a0f14(a0, a1, a2);
        case 0x0a0f7cULL: return fde_sub_0a0f7c(a0, a1, a2);
        case 0x0a1014ULL: return fde_sub_0a1014(a0, a1, a2);
        case 0x0a10a0ULL: return fde_sub_0a10a0(a0, a1, a2);
        case 0x0a10d4ULL: return fde_sub_0a10d4(a0, a1, a2);
        case 0x0a113cULL: return fde_sub_0a113c(a0, a1, a2);
        case 0x0a1154ULL: return fde_sub_0a1154(a0, a1, a2);
        case 0x0a116cULL: return fde_sub_0a116c(a0, a1, a2);
        case 0x0a11c0ULL: return fde_sub_0a11c0(a0, a1, a2);
        case 0x0a13a4ULL: return fde_sub_0a13a4(a0, a1, a2);
        case 0x0a14e0ULL: return fde_sub_0a14e0(a0, a1, a2);
        case 0x0a15a4ULL: return fde_sub_0a15a4(a0, a1, a2);
        case 0x0a1638ULL: return fde_sub_0a1638(a0, a1, a2);
        case 0x0a16d8ULL: return fde_sub_0a16d8(a0, a1, a2);
        case 0x0a172cULL: return fde_sub_0a172c(a0, a1, a2);
        case 0x0a17ccULL: return fde_sub_0a17cc(a0, a1, a2);
        case 0x0a184cULL: return fde_sub_0a184c(a0, a1, a2);
        case 0x0a1864ULL: return fde_sub_0a1864(a0, a1, a2);
        case 0x0a1900ULL: return fde_sub_0a1900(a0, a1, a2);
        case 0x0a1a18ULL: return fde_sub_0a1a18(a0, a1, a2);
        case 0x0a1b34ULL: return fde_sub_0a1b34(a0, a1, a2);
        case 0x0a1b68ULL: return fde_sub_0a1b68(a0, a1, a2);
        case 0x0a1bf8ULL: return fde_sub_0a1bf8(a0, a1, a2);
        case 0x0a1c40ULL: return fde_sub_0a1c40(a0, a1, a2);
        case 0x0a1d68ULL: return fde_sub_0a1d68(a0, a1, a2);
        case 0x0a1de4ULL: return fde_sub_0a1de4(a0, a1, a2);
        case 0x0a1f34ULL: return fde_sub_0a1f34(a0, a1, a2);
        case 0x0a1ffcULL: return fde_sub_0a1ffc(a0, a1, a2);
        case 0x0a2158ULL: return fde_sub_0a2158(a0, a1, a2);
        case 0x0a2224ULL: return fde_sub_0a2224(a0, a1, a2);
        case 0x0a2328ULL: return fde_sub_0a2328(a0, a1, a2);
        case 0x0a23a8ULL: return fde_sub_0a23a8(a0, a1, a2);
        case 0x0a247cULL: return fde_sub_0a247c(a0, a1, a2);
        case 0x0a24f0ULL: return fde_sub_0a24f0(a0, a1, a2);
        case 0x0a2580ULL: return fde_sub_0a2580(a0, a1, a2);
        case 0x0a25ccULL: return fde_sub_0a25cc(a0, a1, a2);
        case 0x0a2650ULL: return fde_sub_0a2650(a0, a1, a2);
        case 0x0a2704ULL: return fde_sub_0a2704(a0, a1, a2);
        case 0x0a27d8ULL: return fde_sub_0a27d8(a0, a1, a2);
        case 0x0a2828ULL: return fde_sub_0a2828(a0, a1, a2);
        case 0x0a2970ULL: return fde_sub_0a2970(a0, a1, a2);
        case 0x0a2a4cULL: return fde_sub_0a2a4c(a0, a1, a2);
        case 0x0a2b54ULL: return fde_sub_0a2b54(a0, a1, a2);
        case 0x0a2be4ULL: return fde_sub_0a2be4(a0, a1, a2);
        case 0x0a2c80ULL: return fde_sub_0a2c80(a0, a1, a2);
        case 0x0a2d44ULL: return fde_sub_0a2d44(a0, a1, a2);
        case 0x0a2d8cULL: return fde_sub_0a2d8c(a0, a1, a2);
        case 0x0a2e60ULL: return fde_sub_0a2e60(a0, a1, a2);
        case 0x0a2f34ULL: return fde_sub_0a2f34(a0, a1, a2);
        case 0x0a2fe4ULL: return fde_sub_0a2fe4(a0, a1, a2);
        case 0x0a30ecULL: return fde_sub_0a30ec(a0, a1, a2);
        case 0x0a31ccULL: return fde_sub_0a31cc(a0, a1, a2);
        case 0x0a3224ULL: return fde_sub_0a3224(a0, a1, a2);
        case 0x0a3310ULL: return fde_sub_0a3310(a0, a1, a2);
        case 0x0a3374ULL: return fde_sub_0a3374(a0, a1, a2);
        case 0x0a33ccULL: return fde_sub_0a33cc(a0, a1, a2);
        case 0x0a35c4ULL: return fde_sub_0a35c4(a0, a1, a2);
        case 0x0a3724ULL: return fde_sub_0a3724(a0, a1, a2);
        case 0x0a37f4ULL: return fde_sub_0a37f4(a0, a1, a2);
        case 0x0a3890ULL: return fde_sub_0a3890(a0, a1, a2);
        case 0x0a3938ULL: return fde_sub_0a3938(a0, a1, a2);
        case 0x0a398cULL: return fde_sub_0a398c(a0, a1, a2);
        case 0x0a3a34ULL: return fde_sub_0a3a34(a0, a1, a2);
        case 0x0a3ac0ULL: return fde_sub_0a3ac0(a0, a1, a2);
        case 0x0a3ad8ULL: return fde_sub_0a3ad8(a0, a1, a2);
        case 0x0a3b84ULL: return fde_sub_0a3b84(a0, a1, a2);
        case 0x0a3ca4ULL: return fde_sub_0a3ca4(a0, a1, a2);
        case 0x0a3ddcULL: return fde_sub_0a3ddc(a0, a1, a2);
        case 0x0a3e10ULL: return fde_sub_0a3e10(a0, a1, a2);
        case 0x0a3ea8ULL: return fde_sub_0a3ea8(a0, a1, a2);
        case 0x0a3ef0ULL: return fde_sub_0a3ef0(a0, a1, a2);
        case 0x0a4024ULL: return fde_sub_0a4024(a0, a1, a2);
        case 0x0a40a8ULL: return fde_sub_0a40a8(a0, a1, a2);
        case 0x0a4200ULL: return fde_sub_0a4200(a0, a1, a2);
        case 0x0a42ccULL: return fde_sub_0a42cc(a0, a1, a2);
        case 0x0a4454ULL: return fde_sub_0a4454(a0, a1, a2);
        case 0x0a4524ULL: return fde_sub_0a4524(a0, a1, a2);
        case 0x0a457cULL: return fde_sub_0a457c(a0, a1, a2);
        case 0x0a4600ULL: return fde_sub_0a4600(a0, a1, a2);
        case 0x0a46dcULL: return fde_sub_0a46dc(a0, a1, a2);
        case 0x0a4750ULL: return fde_sub_0a4750(a0, a1, a2);
        case 0x0a47e8ULL: return fde_sub_0a47e8(a0, a1, a2);
        case 0x0a4834ULL: return fde_sub_0a4834(a0, a1, a2);
        case 0x0a48bcULL: return fde_sub_0a48bc(a0, a1, a2);
        case 0x0a496cULL: return fde_sub_0a496c(a0, a1, a2);
        case 0x0a4a44ULL: return fde_sub_0a4a44(a0, a1, a2);
        case 0x0a4a9cULL: return fde_sub_0a4a9c(a0, a1, a2);
        case 0x0a4b6cULL: return fde_sub_0a4b6c(a0, a1, a2);
        case 0x0a4c4cULL: return fde_sub_0a4c4c(a0, a1, a2);
        case 0x0a4ca4ULL: return fde_sub_0a4ca4(a0, a1, a2);
        case 0x0a4d34ULL: return fde_sub_0a4d34(a0, a1, a2);
        case 0x0a4dd0ULL: return fde_sub_0a4dd0(a0, a1, a2);
        case 0x0a4e94ULL: return fde_sub_0a4e94(a0, a1, a2);
        case 0x0a4edcULL: return fde_sub_0a4edc(a0, a1, a2);
        case 0x0a4f18ULL: return fde_sub_0a4f18(a0, a1, a2);
        case 0x0a4ff8ULL: return fde_sub_0a4ff8(a0, a1, a2);
        case 0x0a50acULL: return fde_sub_0a50ac(a0, a1, a2);
        case 0x0a51c0ULL: return fde_sub_0a51c0(a0, a1, a2);
        case 0x0a51fcULL: return fde_sub_0a51fc(a0, a1, a2);
        case 0x0a5254ULL: return fde_sub_0a5254(a0, a1, a2);
        case 0x0a534cULL: return fde_sub_0a534c(a0, a1, a2);
        case 0x0a53b0ULL: return fde_sub_0a53b0(a0, a1, a2);
        case 0x0a5408ULL: return fde_sub_0a5408(a0, a1, a2);
        case 0x0a5598ULL: return fde_sub_0a5598(a0, a1, a2);
        case 0x0a57e4ULL: return fde_sub_0a57e4(a0, a1, a2);
        case 0x0a5a38ULL: return fde_sub_0a5a38(a0, a1, a2);
        case 0x0a5c24ULL: return fde_sub_0a5c24(a0, a1, a2);
        case 0x0a5e18ULL: return fde_sub_0a5e18(a0, a1, a2);
        case 0x0a6008ULL: return fde_sub_0a6008(a0, a1, a2);
        case 0x0a6200ULL: return fde_sub_0a6200(a0, a1, a2);
        case 0x0a63f0ULL: return fde_sub_0a63f0(a0, a1, a2);
        case 0x0a65e8ULL: return fde_sub_0a65e8(a0, a1, a2);
        case 0x0a67dcULL: return fde_sub_0a67dc(a0, a1, a2);
        case 0x0a69d8ULL: return fde_sub_0a69d8(a0, a1, a2);
        case 0x0a6bc4ULL: return fde_sub_0a6bc4(a0, a1, a2);
        case 0x0a6db8ULL: return fde_sub_0a6db8(a0, a1, a2);
        case 0x0a6fa4ULL: return fde_sub_0a6fa4(a0, a1, a2);
        case 0x0a7198ULL: return fde_sub_0a7198(a0, a1, a2);
        case 0x0a7380ULL: return fde_sub_0a7380(a0, a1, a2);
        case 0x0a7570ULL: return fde_sub_0a7570(a0, a1, a2);
        case 0x0a76acULL: return fde_sub_0a76ac(a0, a1, a2);
        case 0x0a77e8ULL: return fde_sub_0a77e8(a0, a1, a2);
        case 0x0a7924ULL: return fde_sub_0a7924(a0, a1, a2);
        case 0x0a7a38ULL: return fde_sub_0a7a38(a0, a1, a2);
        case 0x0a7b4cULL: return fde_sub_0a7b4c(a0, a1, a2);
        case 0x0a7c60ULL: return fde_sub_0a7c60(a0, a1, a2);
        case 0x0a7de4ULL: return fde_sub_0a7de4(a0, a1, a2);
        case 0x0a7f68ULL: return fde_sub_0a7f68(a0, a1, a2);
        case 0x0a80ecULL: return fde_sub_0a80ec(a0, a1, a2);
        case 0x0a820cULL: return fde_sub_0a820c(a0, a1, a2);
        case 0x0a832cULL: return fde_sub_0a832c(a0, a1, a2);
        case 0x0a844cULL: return fde_sub_0a844c(a0, a1, a2);
        case 0x0a8580ULL: return fde_sub_0a8580(a0, a1, a2);
        case 0x0a86b0ULL: return fde_sub_0a86b0(a0, a1, a2);
        case 0x0a87d8ULL: return fde_sub_0a87d8(a0, a1, a2);
        case 0x0a89d8ULL: return fde_sub_0a89d8(a0, a1, a2);
        case 0x0a8bd4ULL: return fde_sub_0a8bd4(a0, a1, a2);
        case 0x0a8dc8ULL: return fde_sub_0a8dc8(a0, a1, a2);
        case 0x0a8e00ULL: return fde_sub_0a8e00(a0, a1, a2);
        case 0x0a8f98ULL: return fde_sub_0a8f98(a0, a1, a2);
        case 0x0a909cULL: return fde_sub_0a909c(a0, a1, a2);
        case 0x0a9174ULL: return fde_sub_0a9174(a0, a1, a2);
        case 0x0a9334ULL: return fde_sub_0a9334(a0, a1, a2);
        case 0x0a9590ULL: return fde_sub_0a9590(a0, a1, a2);
        case 0x0a95a8ULL: return fde_sub_0a95a8(a0, a1, a2);
        case 0x0a95b0ULL: return fde_sub_0a95b0(a0, a1, a2);
        case 0x0a95c4ULL: return fde_sub_0a95c4(a0, a1, a2);
        case 0x0a9610ULL: return fde_sub_0a9610(a0, a1, a2);
        case 0x0a9634ULL: return fde_sub_0a9634(a0, a1, a2);
        case 0x0a9764ULL: return fde_sub_0a9764(a0, a1, a2);
        case 0x0a9774ULL: return fde_sub_0a9774(a0, a1, a2);
        case 0x0a97e8ULL: return fde_sub_0a97e8(a0, a1, a2);
        case 0x0a9848ULL: return fde_sub_0a9848(a0, a1, a2);
        case 0x0a9858ULL: return fde_sub_0a9858(a0, a1, a2);
        case 0x0a98ccULL: return fde_sub_0a98cc(a0, a1, a2);
        case 0x0a99acULL: return fde_sub_0a99ac(a0, a1, a2);
        case 0x0a9a0cULL: return fde_sub_0a9a0c(a0, a1, a2);
        case 0x0a9a28ULL: return fde_sub_0a9a28(a0, a1, a2);
        case 0x0a9a44ULL: return fde_sub_0a9a44(a0, a1, a2);
        case 0x0a9b58ULL: return fde_sub_0a9b58(a0, a1, a2);
        case 0x0a9c54ULL: return fde_sub_0a9c54(a0, a1, a2);
        case 0x0a9dc8ULL: return fde_sub_0a9dc8(a0, a1, a2);
        case 0x0a9ebcULL: return fde_sub_0a9ebc(a0, a1, a2);
        case 0x0a9fccULL: return fde_sub_0a9fcc(a0, a1, a2);
        case 0x0aa154ULL: return fde_sub_0aa154(a0, a1, a2);
        case 0x0aa25cULL: return fde_sub_0aa25c(a0, a1, a2);
        case 0x0aa264ULL: return fde_sub_0aa264(a0, a1, a2);
        case 0x0aa290ULL: return fde_sub_0aa290(a0, a1, a2);
        case 0x0aa33cULL: return fde_sub_0aa33c(a0, a1, a2);
        case 0x0aa344ULL: return fde_sub_0aa344(a0, a1, a2);
        case 0x0aa34cULL: return fde_sub_0aa34c(a0, a1, a2);
        case 0x0aa354ULL: return fde_sub_0aa354(a0, a1, a2);
        case 0x0aa35cULL: return fde_sub_0aa35c(a0, a1, a2);
        case 0x0aa400ULL: return fde_sub_0aa400(a0, a1, a2);
        case 0x0aa424ULL: return fde_sub_0aa424(a0, a1, a2);
        case 0x0aa470ULL: return fde_sub_0aa470(a0, a1, a2);
        case 0x0aa4b8ULL: return fde_sub_0aa4b8(a0, a1, a2);
        case 0x0aa4e4ULL: return fde_sub_0aa4e4(a0, a1, a2);
        case 0x0aa588ULL: return fde_sub_0aa588(a0, a1, a2);
        case 0x0aa61cULL: return fde_sub_0aa61c(a0, a1, a2);
        case 0x0aa6e4ULL: return fde_sub_0aa6e4(a0, a1, a2);
        case 0x0aa700ULL: return fde_sub_0aa700(a0, a1, a2);
        case 0x0aa71cULL: return fde_sub_0aa71c(a0, a1, a2);
        case 0x0aa82cULL: return fde_sub_0aa82c(a0, a1, a2);
        case 0x0aa918ULL: return fde_sub_0aa918(a0, a1, a2);
        case 0x0aa954ULL: return fde_sub_0aa954(a0, a1, a2);
        case 0x0aa998ULL: return fde_sub_0aa998(a0, a1, a2);
        case 0x0aa9a4ULL: return fde_sub_0aa9a4(a0, a1, a2);
        case 0x0aa9b0ULL: return fde_sub_0aa9b0(a0, a1, a2);
        case 0x0aa9fcULL: return fde_sub_0aa9fc(a0, a1, a2);
        case 0x0aaa0cULL: return fde_sub_0aaa0c(a0, a1, a2);
        case 0x0aab9cULL: return fde_sub_0aab9c(a0, a1, a2);
        case 0x0aac28ULL: return fde_sub_0aac28(a0, a1, a2);
        case 0x0aacd4ULL: return fde_sub_0aacd4(a0, a1, a2);
        case 0x0aacdcULL: return fde_sub_0aacdc(a0, a1, a2);
        case 0x0aad08ULL: return fde_sub_0aad08(a0, a1, a2);
        case 0x0aad18ULL: return fde_sub_0aad18(a0, a1, a2);
        case 0x0aadd0ULL: return fde_sub_0aadd0(a0, a1, a2);
        case 0x0aae98ULL: return fde_sub_0aae98(a0, a1, a2);
        case 0x0aaf58ULL: return fde_sub_0aaf58(a0, a1, a2);
        case 0x0ab024ULL: return fde_sub_0ab024(a0, a1, a2);
        case 0x0ab0f0ULL: return fde_sub_0ab0f0(a0, a1, a2);
        case 0x0ab138ULL: return fde_sub_0ab138(a0, a1, a2);
        case 0x0ab254ULL: return fde_sub_0ab254(a0, a1, a2);
        case 0x0ab2f4ULL: return fde_sub_0ab2f4(a0, a1, a2);
        case 0x0ab3d8ULL: return fde_sub_0ab3d8(a0, a1, a2);
        case 0x0ab3ecULL: return fde_sub_0ab3ec(a0, a1, a2);
        case 0x0ab45cULL: return fde_sub_0ab45c(a0, a1, a2);
        case 0x0ab470ULL: return fde_sub_0ab470(a0, a1, a2);
        case 0x0ab4d0ULL: return fde_sub_0ab4d0(a0, a1, a2);
        case 0x0ab524ULL: return fde_sub_0ab524(a0, a1, a2);
        case 0x0ab6ecULL: return fde_sub_0ab6ec(a0, a1, a2);
        case 0x0ab774ULL: return fde_sub_0ab774(a0, a1, a2);
        case 0x0ab7f0ULL: return fde_sub_0ab7f0(a0, a1, a2);
        case 0x0ab818ULL: return fde_sub_0ab818(a0, a1, a2);
        case 0x0ab8a0ULL: return fde_sub_0ab8a0(a0, a1, a2);
        case 0x0ab8c8ULL: return fde_sub_0ab8c8(a0, a1, a2);
        case 0x0ab950ULL: return fde_sub_0ab950(a0, a1, a2);
        case 0x0ab964ULL: return fde_sub_0ab964(a0, a1, a2);
        case 0x0ab9b4ULL: return fde_sub_0ab9b4(a0, a1, a2);
        case 0x0aba08ULL: return fde_sub_0aba08(a0, a1, a2);
        case 0x0aba64ULL: return fde_sub_0aba64(a0, a1, a2);
        case 0x0aba90ULL: return fde_sub_0aba90(a0, a1, a2);
        case 0x0abaa8ULL: return fde_sub_0abaa8(a0, a1, a2);
        case 0x0abac0ULL: return fde_sub_0abac0(a0, a1, a2);
        case 0x0abbe4ULL: return fde_sub_0abbe4(a0, a1, a2);
        case 0x0abc04ULL: return fde_sub_0abc04(a0, a1, a2);
        case 0x0abc30ULL: return fde_sub_0abc30(a0, a1, a2);
        case 0x0abc5cULL: return fde_sub_0abc5c(a0, a1, a2);
        case 0x0abd50ULL: return fde_sub_0abd50(a0, a1, a2);
        case 0x0ac4a8ULL: return fde_sub_0ac4a8(a0, a1, a2);
        case 0x0ad15cULL: return fde_sub_0ad15c(a0, a1, a2);
        case 0x0ae960ULL: return fde_sub_0ae960(a0, a1, a2);
        case 0x0af4a8ULL: return fde_sub_0af4a8(a0, a1, a2);
        case 0x0af698ULL: return fde_sub_0af698(a0, a1, a2);
        case 0x0af75cULL: return fde_sub_0af75c(a0, a1, a2);
        case 0x0af96cULL: return fde_sub_0af96c(a0, a1, a2);
        case 0x0af978ULL: return fde_sub_0af978(a0, a1, a2);
        case 0x0af984ULL: return fde_sub_0af984(a0, a1, a2);
        case 0x0af990ULL: return fde_sub_0af990(a0, a1, a2);
        case 0x0af998ULL: return fde_sub_0af998(a0, a1, a2);
        case 0x0afa78ULL: return fde_sub_0afa78(a0, a1, a2);
        case 0x0afa80ULL: return fde_sub_0afa80(a0, a1, a2);
        case 0x0afa90ULL: return fde_sub_0afa90(a0, a1, a2);
        case 0x0afa98ULL: return fde_sub_0afa98(a0, a1, a2);
        case 0x0afc04ULL: return fde_sub_0afc04(a0, a1, a2);
        case 0x0afc0cULL: return fde_sub_0afc0c(a0, a1, a2);
        case 0x0affa8ULL: return fde_sub_0affa8(a0, a1, a2);
        case 0x0b0418ULL: return fde_sub_0b0418(a0, a1, a2);
        case 0x0b07c0ULL: return fde_sub_0b07c0(a0, a1, a2);
        case 0x0b08e8ULL: return fde_sub_0b08e8(a0, a1, a2);
        case 0x0b0b50ULL: return fde_sub_0b0b50(a0, a1, a2);
        case 0x0b0cc8ULL: return fde_sub_0b0cc8(a0, a1, a2);
        case 0x0b0ea4ULL: return fde_sub_0b0ea4(a0, a1, a2);
        case 0x0b0f38ULL: return fde_sub_0b0f38(a0, a1, a2);
        case 0x0b0f48ULL: return fde_sub_0b0f48(a0, a1, a2);
        case 0x0b0f50ULL: return fde_sub_0b0f50(a0, a1, a2);
        case 0x0b1050ULL: return fde_sub_0b1050(a0, a1, a2);
        case 0x0b1064ULL: return fde_sub_0b1064(a0, a1, a2);
        case 0x0b106cULL: return fde_sub_0b106c(a0, a1, a2);
        case 0x0b1130ULL: return fde_sub_0b1130(a0, a1, a2);
        case 0x0b11a8ULL: return fde_sub_0b11a8(a0, a1, a2);
        case 0x0b1220ULL: return fde_sub_0b1220(a0, a1, a2);
        case 0x0b1298ULL: return fde_sub_0b1298(a0, a1, a2);
        case 0x0b12f0ULL: return fde_sub_0b12f0(a0, a1, a2);
        case 0x0b1340ULL: return fde_sub_0b1340(a0, a1, a2);
        case 0x0b1390ULL: return fde_sub_0b1390(a0, a1, a2);
        case 0x0b1398ULL: return fde_sub_0b1398(a0, a1, a2);
        case 0x0b3368ULL: return fde_sub_0b3368(a0, a1, a2);
        case 0x0b3e48ULL: return fde_sub_0b3e48(a0, a1, a2);
        case 0x0b4108ULL: return fde_sub_0b4108(a0, a1, a2);
        case 0x0b4710ULL: return fde_sub_0b4710(a0, a1, a2);
        case 0x0b47c8ULL: return fde_sub_0b47c8(a0, a1, a2);
        case 0x0b4e04ULL: return fde_sub_0b4e04(a0, a1, a2);
        case 0x0b503cULL: return fde_sub_0b503c(a0, a1, a2);
        case 0x0b51a4ULL: return fde_sub_0b51a4(a0, a1, a2);
        case 0x0b5780ULL: return fde_sub_0b5780(a0, a1, a2);
        case 0x0b5a64ULL: return fde_sub_0b5a64(a0, a1, a2);
        case 0x0b5a6cULL: return fde_sub_0b5a6c(a0, a1, a2);
        case 0x0b5b24ULL: return fde_sub_0b5b24(a0, a1, a2);
        case 0x0b5b2cULL: return fde_sub_0b5b2c(a0, a1, a2);
        case 0x0b5d18ULL: return fde_sub_0b5d18(a0, a1, a2);
        case 0x0b5d20ULL: return fde_sub_0b5d20(a0, a1, a2);
        case 0x0b5dccULL: return fde_sub_0b5dcc(a0, a1, a2);
        case 0x0b607cULL: return fde_sub_0b607c(a0, a1, a2);
        case 0x0b6084ULL: return fde_sub_0b6084(a0, a1, a2);
        case 0x0b6314ULL: return fde_sub_0b6314(a0, a1, a2);
        case 0x0b631cULL: return fde_sub_0b631c(a0, a1, a2);
        case 0x0b6420ULL: return fde_sub_0b6420(a0, a1, a2);
        case 0x0b6428ULL: return fde_sub_0b6428(a0, a1, a2);
        case 0x0b697cULL: return fde_sub_0b697c(a0, a1, a2);
        case 0x0b6ac0ULL: return fde_sub_0b6ac0(a0, a1, a2);
        case 0x0b6ac8ULL: return fde_sub_0b6ac8(a0, a1, a2);
        case 0x0b6b8cULL: return fde_sub_0b6b8c(a0, a1, a2);
        case 0x0b6e10ULL: return fde_sub_0b6e10(a0, a1, a2);
        case 0x0b6e18ULL: return fde_sub_0b6e18(a0, a1, a2);
        case 0x0b6ea4ULL: return fde_sub_0b6ea4(a0, a1, a2);
        case 0x0b6f08ULL: return fde_sub_0b6f08(a0, a1, a2);
        case 0x0b6f10ULL: return fde_sub_0b6f10(a0, a1, a2);
        default: return 0ULL;
    }
}

} // namespace applovin
