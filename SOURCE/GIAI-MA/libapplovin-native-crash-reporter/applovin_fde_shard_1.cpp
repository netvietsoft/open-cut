// ============================================================================
// File: applovin_fde_shard_1.cpp
// Target 110 / 169: libapplovin-native-crash-reporter.so (860,200 bytes)
// EN: Clean-room C++17 AArch64 FDE Shard 1/5 covering FDEs [0..351]
//     (PC range 0x060694 .. 0x071398).
// VI: Phân mảnh FDE AArch64 C++17 1/5 bao phủ FDE [0..351]
//     (Dải địa chỉ PC 0x060694 .. 0x071398).
// ============================================================================
#include "applovin_crash_reporter.h"

namespace applovin {

// FDE #0000 | PC: 0x060694..0x0606a4 (16 B) | Symbol: sub_060694
// EN: AArch64 prologue [bti c; adrp x0, #0xcd000; add x0, x0, #0xcf0; b #0xc8450] | VI: Khởi đầu hàm AArch64 [bti c; adrp x0, #0xcd000; add x0, x0, #0xcf0; b #0xc8450]
uint64_t fde_sub_060694(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000360ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060694ULL;
}

// FDE #0001 | PC: 0x0606a4..0x0606ac (8 B) | Symbol: sub_0606a4
// EN: AArch64 prologue [bti c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ret]
uint64_t fde_sub_0606a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0606A4ULL;
}

// FDE #0002 | PC: 0x0606ac..0x0606b4 (8 B) | Symbol: sub_0606ac
// EN: AArch64 prologue [bti c; b #0xc3d00] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc3d00]
uint64_t fde_sub_0606ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14018D94ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0606ACULL;
}

// FDE #0003 | PC: 0x0606b4..0x0606c8 (20 B) | Symbol: sub_0606b4
// EN: AArch64 prologue [bti c; cbz x0, #0x606c4; mov x16, x0; br x16] | VI: Khởi đầu hàm AArch64 [bti c; cbz x0, #0x606c4; mov x16, x0; br x16]
uint64_t fde_sub_0606b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000060ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0606B4ULL;
}

// FDE #0004 | PC: 0x0606c8..0x0606e8 (32 B) | Symbol: sub_0606c8
// EN: AArch64 prologue [bti c; adrp x8, #0x60000; add x8, x8, #0x6b4; adrp x2, #0xcd000] | VI: Khởi đầu hàm AArch64 [bti c; adrp x8, #0x60000; add x8, x8, #0x6b4; adrp x2, #0xcd000]
uint64_t fde_sub_0606c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0606C8ULL;
}

// FDE #0005 | PC: 0x0606e8..0x0608dc (500 B) | Symbol: _ZN26NativeCrashReporterContextC1ERNSt6__ndk16vectorIiNS0_9allocatorIiEEEEPFviP7siginfoPvEPFvvE
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x50]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x50]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0606e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BB7BFDULL;
    const uint64_t kPcRange = 0x01F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0606E8ULL;
}

// FDE #0006 | PC: 0x0608dc..0x060984 (168 B) | Symbol: _ZNSt6__ndk16vectorIiNS_9allocatorIiEEEC2ERKS3_
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; mov x29, sp]
uint64_t fde_sub_0608dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BD7BFDULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0608DCULL;
}

// FDE #0007 | PC: 0x060984..0x06099c (24 B) | Symbol: sub_060984
// EN: AArch64 prologue [mov x8, x0; ldr x0, [x0]; cbz x0, #0x60998; str x0, [x8, #8]] | VI: Khởi đầu hàm AArch64 [mov x8, x0; ldr x0, [x0]; cbz x0, #0x60998; str x0, [x8, #8]]
uint64_t fde_sub_060984(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400000ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060984ULL;
}

// FDE #0008 | PC: 0x06099c..0x0609b4 (24 B) | Symbol: sub_06099c
// EN: AArch64 prologue [mov x8, x0; ldr x0, [x0]; cbz x0, #0x609b0; str x0, [x8, #8]] | VI: Khởi đầu hàm AArch64 [mov x8, x0; ldr x0, [x0]; cbz x0, #0x609b0; str x0, [x8, #8]]
uint64_t fde_sub_06099c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400000ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06099CULL;
}

// FDE #0009 | PC: 0x0609b4..0x060ab0 (252 B) | Symbol: _ZN26NativeCrashReporterContextD2Ev
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; mov x29, sp]
uint64_t fde_sub_0609b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF5ULL) << 32) | 0xA9BD7BFDULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0609B4ULL;
}

// FDE #0010 | PC: 0x060ab0..0x060abc (12 B) | Symbol: sub_060ab0
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0xc8570; bl #0xc8580] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0xc8570; bl #0xc8580]
uint64_t fde_sub_060ab0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94019EAFULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060AB0ULL;
}

// FDE #0011 | PC: 0x060abc..0x060b40 (132 B) | Symbol: _ZN26NativeCrashReporterContext25invoke_old_signal_handlerEiP7siginfoPv
// EN: AArch64 prologue [ldp x8, x10, [x0]; mov x9, x8; cmp x8, x10; b.eq #0x60ae8] | VI: Khởi đầu hàm AArch64 [ldp x8, x10, [x0]; mov x9, x8; cmp x8, x10; b.eq #0x60ae8]
uint64_t fde_sub_060abc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E9ULL) << 32) | 0xA9402808ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060ABCULL;
}

// FDE #0012 | PC: 0x060b40..0x060b50 (16 B) | Symbol: _ZN26NativeCrashReporterContext28invoke_old_terminate_handlerEv
// EN: AArch64 prologue [ldr x0, [x0, #0x68]; cbz x0, #0x60b4c; br x0; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x68]; cbz x0, #0x60b4c; br x0; ret]
uint64_t fde_sub_060b40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000040ULL) << 32) | 0xF9403400ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060B40ULL;
}

// FDE #0013 | PC: 0x060b50..0x060ba0 (80 B) | Symbol: sub_060b50
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp; mov x20, x0] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp; mov x20, x0]
uint64_t fde_sub_060b50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BE7BFDULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060B50ULL;
}

// FDE #0014 | PC: 0x060ba0..0x060bd0 (48 B) | Symbol: sub_060ba0
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp; mov x19, x0]
uint64_t fde_sub_060ba0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF3ULL) << 32) | 0xA9BE7BFDULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060BA0ULL;
}

// FDE #0015 | PC: 0x060bd0..0x060d00 (304 B) | Symbol: _ZNSt6__ndk16vectorI9sigactionNS_9allocatorIS1_EEE8__appendEm
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_060bd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF9ULL) << 32) | 0xA9BB7BFDULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060BD0ULL;
}

// FDE #0016 | PC: 0x060d00..0x060fe4 (740 B) | Symbol: Java_com_applovin_impl_sdk_NativeCrashReporter_enable
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x29, x30, [sp, #0x20]; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x29, x30, [sp, #0x20]; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]]
uint64_t fde_sub_060d00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9027BFDULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x02E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060D00ULL;
}

// FDE #0017 | PC: 0x060fe4..0x061454 (1136 B) | Symbol: _Z13handle_signaliP7siginfoPv
// EN: AArch64 prologue [sub sp, sp, #0x1c0; stp x29, x30, [sp, #0x160]; stp x28, x27, [sp, #0x170]; stp x26, x25, [sp, #0x180]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1c0; stp x29, x30, [sp, #0x160]; stp x28, x27, [sp, #0x170]; stp x26, x25, [sp, #0x180]]
uint64_t fde_sub_060fe4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9167BFDULL) << 32) | 0xD10703FFULL;
    const uint64_t kPcRange = 0x0470ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060FE4ULL;
}

// FDE #0018 | PC: 0x061454..0x061838 (996 B) | Symbol: _Z16handle_terminatev
// EN: AArch64 prologue [sub sp, sp, #0x1c0; stp x29, x30, [sp, #0x160]; stp x28, x27, [sp, #0x170]; stp x26, x25, [sp, #0x180]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1c0; stp x29, x30, [sp, #0x160]; stp x28, x27, [sp, #0x170]; stp x26, x25, [sp, #0x180]]
uint64_t fde_sub_061454(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9167BFDULL) << 32) | 0xD10703FFULL;
    const uint64_t kPcRange = 0x03E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061454ULL;
}

// FDE #0019 | PC: 0x061838..0x0618c8 (144 B) | Symbol: Java_com_applovin_impl_sdk_NativeCrashReporter_disable
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp; adrp x20, #0xd9000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp; adrp x20, #0xd9000]
uint64_t fde_sub_061838(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BE7BFDULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061838ULL;
}

// FDE #0020 | PC: 0x0618c8..0x0618f4 (44 B) | Symbol: _Z14crash_detectedv
// EN: AArch64 prologue [adrp x8, #0xd9000; add x8, x8, #0x798; ldarb w8, [x8]; tbnz w8, #0, #0x618ec] | VI: Khởi đầu hàm AArch64 [adrp x8, #0xd9000; add x8, x8, #0x798; ldarb w8, [x8]; tbnz w8, #0, #0x618ec]
uint64_t fde_sub_0618c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911E6108ULL) << 32) | 0x900003C8ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0618C8ULL;
}

// FDE #0021 | PC: 0x0618f4..0x061a24 (304 B) | Symbol: Java_com_applovin_impl_sdk_NativeCrashReporter_updateAdInfo
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_0618f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9027BFDULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0618F4ULL;
}

// FDE #0022 | PC: 0x061a24..0x061a94 (112 B) | Symbol: _Z20begin_handling_crashv
// EN: AArch64 prologue [adrp x8, #0xd9000; ldr x8, [x8, #0x788]; cbz x8, #0x61a74; adrp x8, #0xd9000] | VI: Khởi đầu hàm AArch64 [adrp x8, #0xd9000; ldr x8, [x8, #0x788]; cbz x8, #0x61a74; adrp x8, #0xd9000]
uint64_t fde_sub_061a24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF943C508ULL) << 32) | 0x900003C8ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061A24ULL;
}

// FDE #0023 | PC: 0x061a94..0x061ab4 (32 B) | Symbol: _Z18end_handling_crashv
// EN: AArch64 prologue [adrp x8, #0xd9000; adrp x10, #0xd9000; add x8, x8, #0x79c; mov w9, #1] | VI: Khởi đầu hàm AArch64 [adrp x8, #0xd9000; adrp x10, #0xd9000; add x8, x8, #0x79c; mov w9, #1]
uint64_t fde_sub_061a94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900003CAULL) << 32) | 0x900003C8ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061A94ULL;
}

// FDE #0024 | PC: 0x061ab4..0x062088 (1492 B) | Symbol: _Z16get_signal_causeii
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp; cmp w1, #0] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp; cmp w1, #0]
uint64_t fde_sub_061ab4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF3ULL) << 32) | 0xA9BE7BFDULL;
    const uint64_t kPcRange = 0x05D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061AB4ULL;
}

// FDE #0025 | PC: 0x062088..0x0621f8 (368 B) | Symbol: _Z11symbolicatePKv
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]]
uint64_t fde_sub_062088(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9047BFDULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062088ULL;
}

// FDE #0026 | PC: 0x0621f8..0x062604 (1036 B) | Symbol: _Z12cache_reportRKNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_0621f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9016FFCULL) << 32) | 0xA9BA7BFDULL;
    const uint64_t kPcRange = 0x040CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0621F8ULL;
}

// FDE #0027 | PC: 0x062604..0x06267c (120 B) | Symbol: _ZNSt6__ndk119basic_ostringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp; adrp x8, #0xd4000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp; adrp x8, #0xd4000]
uint64_t fde_sub_062604(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BE7BFDULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062604ULL;
}

// FDE #0028 | PC: 0x06267c..0x062800 (388 B) | Symbol: _Z18get_exception_namev
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_06267c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0184ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06267CULL;
}

// FDE #0029 | PC: 0x062800..0x0629cc (460 B) | Symbol: sub_062800
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_062800(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0xA9BC7BFDULL;
    const uint64_t kPcRange = 0x01CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062800ULL;
}

// FDE #0030 | PC: 0x0629cc..0x062a20 (84 B) | Symbol: _ZNSt6__ndk114basic_ofstreamIcNS_11char_traitsIcEEED1Ev
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp; adrp x8, #0xd4000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp; adrp x8, #0xd4000]
uint64_t fde_sub_0629cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BE7BFDULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0629CCULL;
}

// FDE #0031 | PC: 0x062a20..0x062aac (140 B) | Symbol: _ZTv0_n24_NSt6__ndk119basic_ostringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; mov x29, sp]
uint64_t fde_sub_062a20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF5ULL) << 32) | 0xA9BD7BFDULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062A20ULL;
}

// FDE #0032 | PC: 0x062aac..0x062b2c (128 B) | Symbol: _ZNSt6__ndk119basic_ostringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED0Ev
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp; adrp x8, #0xd4000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp; adrp x8, #0xd4000]
uint64_t fde_sub_062aac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BE7BFDULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062AACULL;
}

// FDE #0033 | PC: 0x062b2c..0x062bc0 (148 B) | Symbol: _ZTv0_n24_NSt6__ndk119basic_ostringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED0Ev
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; mov x29, sp]
uint64_t fde_sub_062b2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF5ULL) << 32) | 0xA9BD7BFDULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062B2CULL;
}

// FDE #0034 | PC: 0x062bc0..0x062c00 (64 B) | Symbol: _ZNSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp; adrp x9, #0xd4000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp; adrp x9, #0xd4000]
uint64_t fde_sub_062bc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF3ULL) << 32) | 0xA9BE7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062BC0ULL;
}

// FDE #0035 | PC: 0x062c00..0x062c48 (72 B) | Symbol: _ZNSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEED0Ev
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp; adrp x9, #0xd4000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp; adrp x9, #0xd4000]
uint64_t fde_sub_062c00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF3ULL) << 32) | 0xA9BE7BFDULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062C00ULL;
}

// FDE #0036 | PC: 0x062c48..0x062d48 (256 B) | Symbol: _ZNSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE7seekoffExNS_8ios_base7seekdirEj
// EN: AArch64 prologue [ldr x8, [x0, #0x58]; ldr x9, [x0, #0x30]; cmp x8, x9; b.hs #0x62c60] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x58]; ldr x9, [x0, #0x30]; cmp x8, x9; b.hs #0x62c60]
uint64_t fde_sub_062c48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401809ULL) << 32) | 0xF9402C08ULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062C48ULL;
}

// FDE #0037 | PC: 0x062d48..0x062d5c (20 B) | Symbol: sub_062d48
// EN: AArch64 prologue [ldr x8, [x0]; mov x1, x2; mov w2, wzr; ldr x4, [x8, #0x20]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; mov x1, x2; mov w2, wzr; ldr x4, [x8, #0x20]]
uint64_t fde_sub_062d48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0203E1ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062D48ULL;
}

// FDE #0038 | PC: 0x062d5c..0x062dac (80 B) | Symbol: _ZNSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE9underflowEv
// EN: AArch64 prologue [ldr x8, [x0, #0x58]; ldr x9, [x0, #0x30]; cmp x8, x9; b.hs #0x62d74] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x58]; ldr x9, [x0, #0x30]; cmp x8, x9; b.hs #0x62d74]
uint64_t fde_sub_062d5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401809ULL) << 32) | 0xF9402C08ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062D5CULL;
}

// FDE #0039 | PC: 0x062dac..0x062e1c (112 B) | Symbol: _ZNSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE9pbackfailEi
// EN: AArch64 prologue [ldr x9, [x0, #0x58]; ldr x10, [x0, #0x30]; mov x8, x0; mov w0, w1] | VI: Khởi đầu hàm AArch64 [ldr x9, [x0, #0x58]; ldr x10, [x0, #0x30]; mov x8, x0; mov w0, w1]
uint64_t fde_sub_062dac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF940180AULL) << 32) | 0xF9402C09ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062DACULL;
}

// FDE #0040 | PC: 0x062e1c..0x062f8c (368 B) | Symbol: _ZNSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE8overflowEi
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x50]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x50]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_062e1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BB7BFDULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062E1CULL;
}

// FDE #0041 | PC: 0x062f8c..0x062fec (96 B) | Symbol: _ZTv0_n24_NSt6__ndk114basic_ofstreamIcNS_11char_traitsIcEEED1Ev
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp; ldr x8, [x0]]
uint64_t fde_sub_062f8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BE7BFDULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062F8CULL;
}

// FDE #0042 | PC: 0x062fec..0x063048 (92 B) | Symbol: _ZNSt6__ndk114basic_ofstreamIcNS_11char_traitsIcEEED0Ev
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp; adrp x8, #0xd4000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp; adrp x8, #0xd4000]
uint64_t fde_sub_062fec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BE7BFDULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062FECULL;
}

// FDE #0043 | PC: 0x063048..0x0630b0 (104 B) | Symbol: _ZTv0_n24_NSt6__ndk114basic_ofstreamIcNS_11char_traitsIcEEED0Ev
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp; ldr x8, [x0]]
uint64_t fde_sub_063048(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BE7BFDULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063048ULL;
}

// FDE #0044 | PC: 0x0630b0..0x06317c (204 B) | Symbol: _ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEED2Ev
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; mov x29, sp]
uint64_t fde_sub_0630b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF5ULL) << 32) | 0xA9BD7BFDULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0630B0ULL;
}

// FDE #0045 | PC: 0x06317c..0x0631a0 (36 B) | Symbol: _ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEED0Ev
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp; mov x19, x0]
uint64_t fde_sub_06317c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF3ULL) << 32) | 0xA9BE7BFDULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06317CULL;
}

// FDE #0046 | PC: 0x0631a0..0x063290 (240 B) | Symbol: _ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE5imbueERKNS_6localeE
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp; ldr x8, [x0]]
uint64_t fde_sub_0631a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BE7BFDULL;
    const uint64_t kPcRange = 0x00F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0631A0ULL;
}

// FDE #0047 | PC: 0x063290..0x063388 (248 B) | Symbol: _ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE6setbufEPcl
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; mov x29, sp]
uint64_t fde_sub_063290(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BD7BFDULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063290ULL;
}

// FDE #0048 | PC: 0x063388..0x063448 (192 B) | Symbol: _ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE7seekoffExNS_8ios_base7seekdirEj
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; mov x29, sp]
uint64_t fde_sub_063388(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BD7BFDULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063388ULL;
}

// FDE #0049 | PC: 0x063448..0x0634b8 (112 B) | Symbol: _ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE7seekposENS_4fposI9mbstate_tEEj
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; mov x29, sp]
uint64_t fde_sub_063448(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF5ULL) << 32) | 0xA9BD7BFDULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063448ULL;
}

// FDE #0050 | PC: 0x0634b8..0x0636a8 (496 B) | Symbol: _ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE4syncEv
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0634b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0634B8ULL;
}

// FDE #0051 | PC: 0x0636a8..0x063928 (640 B) | Symbol: _ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE9underflowEv
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_0636a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9027BFDULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0280ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0636A8ULL;
}

// FDE #0052 | PC: 0x063928..0x063988 (96 B) | Symbol: _ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE9pbackfailEi
// EN: AArch64 prologue [ldr x9, [x0, #0x78]; cbz x9, #0x63970; ldp x10, x9, [x0, #0x10]; mov x8, x0] | VI: Khởi đầu hàm AArch64 [ldr x9, [x0, #0x78]; cbz x9, #0x63970; ldp x10, x9, [x0, #0x10]; mov x8, x0]
uint64_t fde_sub_063928(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000229ULL) << 32) | 0xF9403C09ULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063928ULL;
}

// FDE #0053 | PC: 0x063988..0x063bcc (580 B) | Symbol: _ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE8overflowEi
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_063988(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9027BFDULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0244ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063988ULL;
}

// FDE #0054 | PC: 0x063bcc..0x063c00 (52 B) | Symbol: sub_063bcc
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp; mov w0, #8] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp; mov w0, #8]
uint64_t fde_sub_063bcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF3ULL) << 32) | 0xA9BE7BFDULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063BCCULL;
}

// FDE #0055 | PC: 0x063c00..0x063d84 (388 B) | Symbol: _ZNSt6__ndk124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_063c00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9027BFDULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0184ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063C00ULL;
}

// FDE #0056 | PC: 0x063d84..0x063f28 (420 B) | Symbol: sub_063d84
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x29, x30, [sp, #0x20]; str x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x29, x30, [sp, #0x20]; str x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]]
uint64_t fde_sub_063d84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9027BFDULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x01A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063D84ULL;
}

// FDE #0057 | PC: 0x063f28..0x064128 (512 B) | Symbol: _ZNKSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE3strEv
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_063f28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0xA9BC7BFDULL;
    const uint64_t kPcRange = 0x0200ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063F28ULL;
}

// FDE #0058 | PC: 0x064128..0x064250 (296 B) | Symbol: _ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEEC2Ev
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x29, x30, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x29, x30, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_064128(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0128ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064128ULL;
}

// FDE #0059 | PC: 0x064250..0x0642d8 (136 B) | Symbol: sub_064250
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp; adrp x1, #0xd9000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp; adrp x1, #0xd9000]
uint64_t fde_sub_064250(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BE7BFDULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064250ULL;
}

// FDE #0060 | PC: 0x0642d8..0x0642fc (36 B) | Symbol: _ZSt18uncaught_exceptionv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc8980] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc8980]
uint64_t fde_sub_0642d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0642D8ULL;
}

// FDE #0061 | PC: 0x0642fc..0x064304 (8 B) | Symbol: _ZSt19uncaught_exceptionsv
// EN: AArch64 prologue [bti c; b #0xc8980] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8980]
uint64_t fde_sub_0642fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140191A0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0642FCULL;
}

// FDE #0062 | PC: 0x064304..0x064310 (12 B) | Symbol: _ZNSt13exception_ptrD2Ev
// EN: AArch64 prologue [bti c; ldr x0, [x0]; b #0xc8990] | VI: Khởi đầu hàm AArch64 [bti c; ldr x0, [x0]; b #0xc8990]
uint64_t fde_sub_064304(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064304ULL;
}

// FDE #0063 | PC: 0x064310..0x064324 (20 B) | Symbol: _ZNSt13exception_ptrC2ERKS_
// EN: AArch64 prologue [bti c; ldr x8, [x1]; str x8, [x0]; mov x0, x8] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x1]; str x8, [x0]; mov x0, x8]
uint64_t fde_sub_064310(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400028ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064310ULL;
}

// FDE #0064 | PC: 0x064324..0x064374 (80 B) | Symbol: _ZNSt13exception_ptraSERKS_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_064324(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064324ULL;
}

// FDE #0065 | PC: 0x064374..0x0643b0 (60 B) | Symbol: _ZNSt16nested_exceptionC1Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_064374(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064374ULL;
}

// FDE #0066 | PC: 0x0643b0..0x0643dc (44 B) | Symbol: _ZSt17current_exceptionv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0643b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0643B0ULL;
}

// FDE #0067 | PC: 0x0643dc..0x0643fc (32 B) | Symbol: _ZNSt16nested_exceptionD2Ev
// EN: AArch64 prologue [bti c; adrp x9, #0xd4000; ldr x8, [x0, #8]; ldr x9, [x9, #0x5b0]] | VI: Khởi đầu hàm AArch64 [bti c; adrp x9, #0xd4000; ldr x8, [x0, #8]; ldr x9, [x9, #0x5b0]]
uint64_t fde_sub_0643dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000389ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0643DCULL;
}

// FDE #0068 | PC: 0x0643fc..0x06443c (64 B) | Symbol: _ZNSt16nested_exceptionD0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0643fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0643FCULL;
}

// FDE #0069 | PC: 0x06443c..0x064494 (88 B) | Symbol: _ZNKSt16nested_exception14rethrow_nestedEv
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x30; stp x29, x30, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x30; stp x29, x30, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_06443c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD100C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06443CULL;
}

// FDE #0070 | PC: 0x064494..0x0644ac (24 B) | Symbol: _ZSt17rethrow_exceptionSt13exception_ptr
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x0, [x0]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x0, [x0]]
uint64_t fde_sub_064494(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064494ULL;
}

// FDE #0071 | PC: 0x0644ac..0x0644b4 (8 B) | Symbol: _ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev
// EN: AArch64 prologue [bti c; b #0xc89d0] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc89d0]
uint64_t fde_sub_0644ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14019148ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0644ACULL;
}

// FDE #0072 | PC: 0x0644b4..0x064540 (140 B) | Symbol: _ZNSt6__ndk18ios_baseD1Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0644b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0644B4ULL;
}

// FDE #0073 | PC: 0x064540..0x06456c (44 B) | Symbol: _ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_064540(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064540ULL;
}

// FDE #0074 | PC: 0x06456c..0x064654 (232 B) | Symbol: _ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEE7copyfmtERKS3_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_06456c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06456CULL;
}

// FDE #0075 | PC: 0x064654..0x0646b4 (96 B) | Symbol: _ZNSt6__ndk18ios_base16__call_callbacksENS0_5eventE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_064654(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064654ULL;
}

// FDE #0076 | PC: 0x0646b4..0x06497c (712 B) | Symbol: _ZNSt6__ndk18ios_base7copyfmtERKS0_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0646b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x02C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0646B4ULL;
}

// FDE #0077 | PC: 0x06497c..0x064984 (8 B) | Symbol: _ZNSt6__ndk19basic_iosIwNS_11char_traitsIwEEED2Ev
// EN: AArch64 prologue [bti c; b #0xc89d0] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc89d0]
uint64_t fde_sub_06497c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14019014ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06497CULL;
}

// FDE #0078 | PC: 0x064984..0x0649b0 (44 B) | Symbol: _ZNSt6__ndk19basic_iosIwNS_11char_traitsIwEEED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_064984(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064984ULL;
}

// FDE #0079 | PC: 0x0649b0..0x064a98 (232 B) | Symbol: _ZNSt6__ndk19basic_iosIwNS_11char_traitsIwEEE7copyfmtERKS3_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0649b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0649B0ULL;
}

// FDE #0080 | PC: 0x064a98..0x064ab0 (24 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev
// EN: AArch64 prologue [bti c; adrp x8, #0xd4000; ldr x8, [x8, #0x5c0]; add x8, x8, #0x10] | VI: Khởi đầu hàm AArch64 [bti c; adrp x8, #0xd4000; ldr x8, [x8, #0x5c0]; add x8, x8, #0x10]
uint64_t fde_sub_064a98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000388ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064A98ULL;
}

// FDE #0081 | PC: 0x064ab0..0x064aec (60 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_064ab0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064AB0ULL;
}

// FDE #0082 | PC: 0x064aec..0x064b40 (84 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE8pubimbueERKNS_6localeE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_064aec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064AECULL;
}

// FDE #0083 | PC: 0x064b40..0x064b50 (16 B) | Symbol: _ZNKSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE6getlocEv
// EN: AArch64 prologue [bti c; add x1, x0, #8; mov x0, x8; b #0xc8960] | VI: Khởi đầu hàm AArch64 [bti c; add x1, x0, #8; mov x0, x8; b #0xc8960]
uint64_t fde_sub_064b40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91002001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064B40ULL;
}

// FDE #0084 | PC: 0x064b50..0x064b60 (16 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE9pubsetbufEPcl
// EN: AArch64 prologue [bti c; ldr x8, [x0]; ldr x16, [x8, #0x18]; br x16] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0]; ldr x16, [x8, #0x18]; br x16]
uint64_t fde_sub_064b50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064B50ULL;
}

// FDE #0085 | PC: 0x064b60..0x064b70 (16 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE10pubseekoffExNS_8ios_base7seekdirEj
// EN: AArch64 prologue [bti c; ldr x8, [x0]; ldr x16, [x8, #0x20]; br x16] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0]; ldr x16, [x8, #0x20]; br x16]
uint64_t fde_sub_064b60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064B60ULL;
}

// FDE #0086 | PC: 0x064b70..0x064b80 (16 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE10pubseekposENS_4fposI9mbstate_tEEj
// EN: AArch64 prologue [bti c; ldr x8, [x0]; ldr x16, [x8, #0x28]; br x16] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0]; ldr x16, [x8, #0x28]; br x16]
uint64_t fde_sub_064b70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064B70ULL;
}

// FDE #0087 | PC: 0x064b80..0x064b90 (16 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE7pubsyncEv
// EN: AArch64 prologue [bti c; ldr x8, [x0]; ldr x16, [x8, #0x30]; br x16] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0]; ldr x16, [x8, #0x30]; br x16]
uint64_t fde_sub_064b80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064B80ULL;
}

// FDE #0088 | PC: 0x064b90..0x064bb4 (36 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE8in_availEv
// EN: AArch64 prologue [bti c; ldp x8, x9, [x0, #0x18]; cmp x8, x9; b.hs #0x64ba8] | VI: Khởi đầu hàm AArch64 [bti c; ldp x8, x9, [x0, #0x18]; cmp x8, x9; b.hs #0x64ba8]
uint64_t fde_sub_064b90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA941A408ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064B90ULL;
}

// FDE #0089 | PC: 0x064bb4..0x064c3c (136 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE6snextcEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_064bb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064BB4ULL;
}

// FDE #0090 | PC: 0x064c3c..0x064c68 (44 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE6sbumpcEv
// EN: AArch64 prologue [bti c; ldp x8, x9, [x0, #0x18]; cmp x8, x9; b.eq #0x64c5c] | VI: Khởi đầu hàm AArch64 [bti c; ldp x8, x9, [x0, #0x18]; cmp x8, x9; b.eq #0x64c5c]
uint64_t fde_sub_064c3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA941A408ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064C3CULL;
}

// FDE #0091 | PC: 0x064c68..0x064c8c (36 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE5sgetcEv
// EN: AArch64 prologue [bti c; ldp x8, x9, [x0, #0x18]; cmp x8, x9; b.eq #0x64c80] | VI: Khởi đầu hàm AArch64 [bti c; ldp x8, x9, [x0, #0x18]; cmp x8, x9; b.eq #0x64c80]
uint64_t fde_sub_064c68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA941A408ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064C68ULL;
}

// FDE #0092 | PC: 0x064c8c..0x064c9c (16 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE5sgetnEPcl
// EN: AArch64 prologue [bti c; ldr x8, [x0]; ldr x16, [x8, #0x40]; br x16] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0]; ldr x16, [x8, #0x40]; br x16]
uint64_t fde_sub_064c8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064C8CULL;
}

// FDE #0093 | PC: 0x064c9c..0x064cd4 (56 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE9sputbackcEc
// EN: AArch64 prologue [bti c; ldp x9, x8, [x0, #0x10]; cmp x9, x8; b.eq #0x64cc4] | VI: Khởi đầu hàm AArch64 [bti c; ldp x9, x8, [x0, #0x10]; cmp x9, x8; b.eq #0x64cc4]
uint64_t fde_sub_064c9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9412009ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064C9CULL;
}

// FDE #0094 | PC: 0x064cd4..0x064d04 (48 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE7sungetcEv
// EN: AArch64 prologue [bti c; ldp x9, x8, [x0, #0x10]; cmp x9, x8; b.eq #0x64cf4] | VI: Khởi đầu hàm AArch64 [bti c; ldp x9, x8, [x0, #0x10]; cmp x9, x8; b.eq #0x64cf4]
uint64_t fde_sub_064cd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9412009ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064CD4ULL;
}

// FDE #0095 | PC: 0x064d04..0x064d3c (56 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE5sputcEc
// EN: AArch64 prologue [bti c; ldp x9, x8, [x0, #0x30]; cmp x9, x8; b.eq #0x64d2c] | VI: Khởi đầu hàm AArch64 [bti c; ldp x9, x8, [x0, #0x30]; cmp x9, x8; b.eq #0x64d2c]
uint64_t fde_sub_064d04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9432009ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064D04ULL;
}

// FDE #0096 | PC: 0x064d3c..0x064d4c (16 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE5sputnEPKcl
// EN: AArch64 prologue [bti c; ldr x8, [x0]; ldr x16, [x8, #0x60]; br x16] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0]; ldr x16, [x8, #0x60]; br x16]
uint64_t fde_sub_064d3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064D3CULL;
}

// FDE #0097 | PC: 0x064d4c..0x064d90 (68 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC1Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_064d4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064D4CULL;
}

// FDE #0098 | PC: 0x064d90..0x064dec (92 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC1ERKS3_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_064d90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064D90ULL;
}

// FDE #0099 | PC: 0x064dec..0x064e3c (80 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEaSERKS3_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_064dec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064DECULL;
}

// FDE #0100 | PC: 0x064e3c..0x064f30 (244 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE4swapERS3_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]]
uint64_t fde_sub_064e3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064E3CULL;
}

// FDE #0101 | PC: 0x064f30..0x064f44 (20 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE5gbumpEi
// EN: AArch64 prologue [bti c; ldr x8, [x0, #0x18]; add x8, x8, w1, sxtw; str x8, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0, #0x18]; add x8, x8, w1, sxtw; str x8, [x0, #0x18]]
uint64_t fde_sub_064f30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400C08ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064F30ULL;
}

// FDE #0102 | PC: 0x064f44..0x064f54 (16 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE4setgEPcS4_S4_
// EN: AArch64 prologue [bti c; stp x1, x2, [x0, #0x10]; str x3, [x0, #0x20]; ret] | VI: Khởi đầu hàm AArch64 [bti c; stp x1, x2, [x0, #0x10]; str x3, [x0, #0x20]; ret]
uint64_t fde_sub_064f44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9010801ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064F44ULL;
}

// FDE #0103 | PC: 0x064f54..0x064f68 (20 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE5pbumpEi
// EN: AArch64 prologue [bti c; ldr x8, [x0, #0x30]; add x8, x8, w1, sxtw; str x8, [x0, #0x30]] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0, #0x30]; add x8, x8, w1, sxtw; str x8, [x0, #0x30]]
uint64_t fde_sub_064f54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401808ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064F54ULL;
}

// FDE #0104 | PC: 0x064f68..0x064f78 (16 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE4setpEPcS4_
// EN: AArch64 prologue [bti c; stp x1, x1, [x0, #0x28]; str x2, [x0, #0x38]; ret] | VI: Khởi đầu hàm AArch64 [bti c; stp x1, x1, [x0, #0x28]; str x2, [x0, #0x38]; ret]
uint64_t fde_sub_064f68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9028401ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064F68ULL;
}

// FDE #0105 | PC: 0x064f78..0x064f80 (8 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE5imbueERKNS_6localeE
// EN: AArch64 prologue [bti c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ret]
uint64_t fde_sub_064f78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064F78ULL;
}

// FDE #0106 | PC: 0x064f80..0x064f88 (8 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE6setbufEPcl
// EN: AArch64 prologue [bti c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ret]
uint64_t fde_sub_064f80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064F80ULL;
}

// FDE #0107 | PC: 0x064f88..0x064f98 (16 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE7seekoffExNS_8ios_base7seekdirEj
// EN: AArch64 prologue [bti c; mov x1, #-1; mov x0, xzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov x1, #-1; mov x0, xzr; ret]
uint64_t fde_sub_064f88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x92800001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064F88ULL;
}

// FDE #0108 | PC: 0x064f98..0x064fa8 (16 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE7seekposENS_4fposI9mbstate_tEEj
// EN: AArch64 prologue [bti c; mov x1, #-1; mov x0, xzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov x1, #-1; mov x0, xzr; ret]
uint64_t fde_sub_064f98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x92800001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064F98ULL;
}

// FDE #0109 | PC: 0x064fa8..0x064fb4 (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE4syncEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_064fa8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064FA8ULL;
}

// FDE #0110 | PC: 0x064fb4..0x064fc0 (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE9showmanycEv
// EN: AArch64 prologue [bti c; mov x0, xzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov x0, xzr; ret]
uint64_t fde_sub_064fb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064FB4ULL;
}

// FDE #0111 | PC: 0x064fc0..0x065090 (208 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE6xsgetnEPcl
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_064fc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064FC0ULL;
}

// FDE #0112 | PC: 0x065090..0x06509c (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE9underflowEv
// EN: AArch64 prologue [bti c; mov w0, #-1; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #-1; ret]
uint64_t fde_sub_065090(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12800000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065090ULL;
}

// FDE #0113 | PC: 0x06509c..0x0650e4 (72 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE5uflowEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_06509c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06509CULL;
}

// FDE #0114 | PC: 0x0650e4..0x0650f0 (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE9pbackfailEi
// EN: AArch64 prologue [bti c; mov w0, #-1; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #-1; ret]
uint64_t fde_sub_0650e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12800000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0650E4ULL;
}

// FDE #0115 | PC: 0x0650f0..0x0651c0 (208 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE6xsputnEPKcl
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0650f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0650F0ULL;
}

// FDE #0116 | PC: 0x0651c0..0x0651cc (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE8overflowEi
// EN: AArch64 prologue [bti c; mov w0, #-1; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #-1; ret]
uint64_t fde_sub_0651c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12800000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0651C0ULL;
}

// FDE #0117 | PC: 0x0651cc..0x0651e4 (24 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEED2Ev
// EN: AArch64 prologue [bti c; adrp x8, #0xd4000; ldr x8, [x8, #0x5c8]; add x8, x8, #0x10] | VI: Khởi đầu hàm AArch64 [bti c; adrp x8, #0xd4000; ldr x8, [x8, #0x5c8]; add x8, x8, #0x10]
uint64_t fde_sub_0651cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000368ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0651CCULL;
}

// FDE #0118 | PC: 0x0651e4..0x065220 (60 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0651e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0651E4ULL;
}

// FDE #0119 | PC: 0x065220..0x065274 (84 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE8pubimbueERKNS_6localeE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_065220(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065220ULL;
}

// FDE #0120 | PC: 0x065274..0x065284 (16 B) | Symbol: _ZNKSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE6getlocEv
// EN: AArch64 prologue [bti c; add x1, x0, #8; mov x0, x8; b #0xc8960] | VI: Khởi đầu hàm AArch64 [bti c; add x1, x0, #8; mov x0, x8; b #0xc8960]
uint64_t fde_sub_065274(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91002001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065274ULL;
}

// FDE #0121 | PC: 0x065284..0x065294 (16 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE9pubsetbufEPwl
// EN: AArch64 prologue [bti c; ldr x8, [x0]; ldr x16, [x8, #0x18]; br x16] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0]; ldr x16, [x8, #0x18]; br x16]
uint64_t fde_sub_065284(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065284ULL;
}

// FDE #0122 | PC: 0x065294..0x0652a4 (16 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE10pubseekoffExNS_8ios_base7seekdirEj
// EN: AArch64 prologue [bti c; ldr x8, [x0]; ldr x16, [x8, #0x20]; br x16] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0]; ldr x16, [x8, #0x20]; br x16]
uint64_t fde_sub_065294(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065294ULL;
}

// FDE #0123 | PC: 0x0652a4..0x0652b4 (16 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE10pubseekposENS_4fposI9mbstate_tEEj
// EN: AArch64 prologue [bti c; ldr x8, [x0]; ldr x16, [x8, #0x28]; br x16] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0]; ldr x16, [x8, #0x28]; br x16]
uint64_t fde_sub_0652a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0652A4ULL;
}

// FDE #0124 | PC: 0x0652b4..0x0652c4 (16 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE7pubsyncEv
// EN: AArch64 prologue [bti c; ldr x8, [x0]; ldr x16, [x8, #0x30]; br x16] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0]; ldr x16, [x8, #0x30]; br x16]
uint64_t fde_sub_0652b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0652B4ULL;
}

// FDE #0125 | PC: 0x0652c4..0x0652ec (40 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE8in_availEv
// EN: AArch64 prologue [bti c; ldp x8, x9, [x0, #0x18]; cmp x8, x9; b.hs #0x652e0] | VI: Khởi đầu hàm AArch64 [bti c; ldp x8, x9, [x0, #0x18]; cmp x8, x9; b.hs #0x652e0]
uint64_t fde_sub_0652c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA941A408ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0652C4ULL;
}

// FDE #0126 | PC: 0x0652ec..0x065378 (140 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE6snextcEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0652ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0652ECULL;
}

// FDE #0127 | PC: 0x065378..0x0653a4 (44 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE6sbumpcEv
// EN: AArch64 prologue [bti c; ldp x8, x9, [x0, #0x18]; cmp x8, x9; b.eq #0x65398] | VI: Khởi đầu hàm AArch64 [bti c; ldp x8, x9, [x0, #0x18]; cmp x8, x9; b.eq #0x65398]
uint64_t fde_sub_065378(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA941A408ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065378ULL;
}

// FDE #0128 | PC: 0x0653a4..0x0653c8 (36 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE5sgetcEv
// EN: AArch64 prologue [bti c; ldp x8, x9, [x0, #0x18]; cmp x8, x9; b.eq #0x653bc] | VI: Khởi đầu hàm AArch64 [bti c; ldp x8, x9, [x0, #0x18]; cmp x8, x9; b.eq #0x653bc]
uint64_t fde_sub_0653a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA941A408ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0653A4ULL;
}

// FDE #0129 | PC: 0x0653c8..0x0653d8 (16 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE5sgetnEPwl
// EN: AArch64 prologue [bti c; ldr x8, [x0]; ldr x16, [x8, #0x40]; br x16] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0]; ldr x16, [x8, #0x40]; br x16]
uint64_t fde_sub_0653c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0653C8ULL;
}

// FDE #0130 | PC: 0x0653d8..0x06540c (52 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE9sputbackcEw
// EN: AArch64 prologue [bti c; ldp x9, x8, [x0, #0x10]; cmp x9, x8; b.eq #0x65400] | VI: Khởi đầu hàm AArch64 [bti c; ldp x9, x8, [x0, #0x10]; cmp x9, x8; b.eq #0x65400]
uint64_t fde_sub_0653d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9412009ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0653D8ULL;
}

// FDE #0131 | PC: 0x06540c..0x06543c (48 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE7sungetcEv
// EN: AArch64 prologue [bti c; ldp x9, x8, [x0, #0x10]; cmp x9, x8; b.eq #0x6542c] | VI: Khởi đầu hàm AArch64 [bti c; ldp x9, x8, [x0, #0x10]; cmp x9, x8; b.eq #0x6542c]
uint64_t fde_sub_06540c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9412009ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06540CULL;
}

// FDE #0132 | PC: 0x06543c..0x06546c (48 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE5sputcEw
// EN: AArch64 prologue [bti c; ldp x8, x9, [x0, #0x30]; cmp x8, x9; b.eq #0x65460] | VI: Khởi đầu hàm AArch64 [bti c; ldp x8, x9, [x0, #0x30]; cmp x8, x9; b.eq #0x65460]
uint64_t fde_sub_06543c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9432408ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06543CULL;
}

// FDE #0133 | PC: 0x06546c..0x06547c (16 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE5sputnEPKwl
// EN: AArch64 prologue [bti c; ldr x8, [x0]; ldr x16, [x8, #0x60]; br x16] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0]; ldr x16, [x8, #0x60]; br x16]
uint64_t fde_sub_06546c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06546CULL;
}

// FDE #0134 | PC: 0x06547c..0x0654c0 (68 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEEC2Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_06547c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06547CULL;
}

// FDE #0135 | PC: 0x0654c0..0x06551c (92 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEEC1ERKS3_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0654c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0654C0ULL;
}

// FDE #0136 | PC: 0x06551c..0x06556c (80 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEEaSERKS3_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_06551c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06551CULL;
}

// FDE #0137 | PC: 0x06556c..0x065660 (244 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE4swapERS3_
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]]
uint64_t fde_sub_06556c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06556CULL;
}

// FDE #0138 | PC: 0x065660..0x065674 (20 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE5gbumpEi
// EN: AArch64 prologue [bti c; ldr x8, [x0, #0x18]; add x8, x8, w1, sxtw #2; str x8, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0, #0x18]; add x8, x8, w1, sxtw #2; str x8, [x0, #0x18]]
uint64_t fde_sub_065660(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400C08ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065660ULL;
}

// FDE #0139 | PC: 0x065674..0x065684 (16 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE4setgEPwS4_S4_
// EN: AArch64 prologue [bti c; stp x1, x2, [x0, #0x10]; str x3, [x0, #0x20]; ret] | VI: Khởi đầu hàm AArch64 [bti c; stp x1, x2, [x0, #0x10]; str x3, [x0, #0x20]; ret]
uint64_t fde_sub_065674(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9010801ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065674ULL;
}

// FDE #0140 | PC: 0x065684..0x065698 (20 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE5pbumpEi
// EN: AArch64 prologue [bti c; ldr x8, [x0, #0x30]; add x8, x8, w1, sxtw #2; str x8, [x0, #0x30]] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0, #0x30]; add x8, x8, w1, sxtw #2; str x8, [x0, #0x30]]
uint64_t fde_sub_065684(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401808ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065684ULL;
}

// FDE #0141 | PC: 0x065698..0x0656a8 (16 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE4setpEPwS4_
// EN: AArch64 prologue [bti c; stp x1, x1, [x0, #0x28]; str x2, [x0, #0x38]; ret] | VI: Khởi đầu hàm AArch64 [bti c; stp x1, x1, [x0, #0x28]; str x2, [x0, #0x38]; ret]
uint64_t fde_sub_065698(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9028401ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065698ULL;
}

// FDE #0142 | PC: 0x0656a8..0x0656b0 (8 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE5imbueERKNS_6localeE
// EN: AArch64 prologue [bti c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ret]
uint64_t fde_sub_0656a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0656A8ULL;
}

// FDE #0143 | PC: 0x0656b0..0x0656b8 (8 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE6setbufEPwl
// EN: AArch64 prologue [bti c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ret]
uint64_t fde_sub_0656b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0656B0ULL;
}

// FDE #0144 | PC: 0x0656b8..0x0656c8 (16 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE7seekoffExNS_8ios_base7seekdirEj
// EN: AArch64 prologue [bti c; mov x1, #-1; mov x0, xzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov x1, #-1; mov x0, xzr; ret]
uint64_t fde_sub_0656b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x92800001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0656B8ULL;
}

// FDE #0145 | PC: 0x0656c8..0x0656d8 (16 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE7seekposENS_4fposI9mbstate_tEEj
// EN: AArch64 prologue [bti c; mov x1, #-1; mov x0, xzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov x1, #-1; mov x0, xzr; ret]
uint64_t fde_sub_0656c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x92800001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0656C8ULL;
}

// FDE #0146 | PC: 0x0656d8..0x0656e4 (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE4syncEv
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_0656d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0656D8ULL;
}

// FDE #0147 | PC: 0x0656e4..0x0656f0 (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE9showmanycEv
// EN: AArch64 prologue [bti c; mov x0, xzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov x0, xzr; ret]
uint64_t fde_sub_0656e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0656E4ULL;
}

// FDE #0148 | PC: 0x0656f0..0x0657cc (220 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE6xsgetnEPwl
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0656f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0656F0ULL;
}

// FDE #0149 | PC: 0x0657cc..0x0657d8 (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE9underflowEv
// EN: AArch64 prologue [bti c; mov w0, #-1; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #-1; ret]
uint64_t fde_sub_0657cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12800000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0657CCULL;
}

// FDE #0150 | PC: 0x0657d8..0x065820 (72 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE5uflowEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0657d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0657D8ULL;
}

// FDE #0151 | PC: 0x065820..0x06582c (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE9pbackfailEj
// EN: AArch64 prologue [bti c; mov w0, #-1; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #-1; ret]
uint64_t fde_sub_065820(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12800000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065820ULL;
}

// FDE #0152 | PC: 0x06582c..0x065908 (220 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE6xsputnEPKwl
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_06582c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06582CULL;
}

// FDE #0153 | PC: 0x065908..0x065914 (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE8overflowEj
// EN: AArch64 prologue [bti c; mov w0, #-1; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #-1; ret]
uint64_t fde_sub_065908(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12800000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065908ULL;
}

// FDE #0154 | PC: 0x065914..0x0659a8 (148 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEEC2EPNS_15basic_streambufIcS2_EE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_065914(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065914ULL;
}

// FDE #0155 | PC: 0x0659a8..0x065a34 (140 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEEC1EPNS_15basic_streambufIcS2_EE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0659a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0659A8ULL;
}

// FDE #0156 | PC: 0x065a34..0x065a3c (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED2Ev
// EN: AArch64 prologue [bti c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ret]
uint64_t fde_sub_065a34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065A34ULL;
}

// FDE #0157 | PC: 0x065a3c..0x065a48 (12 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED1Ev
// EN: AArch64 prologue [bti c; add x0, x0, #0x10; b #0xc89d0] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x10; b #0xc89d0]
uint64_t fde_sub_065a3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91004000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065A3CULL;
}

// FDE #0158 | PC: 0x065a48..0x065a60 (24 B) | Symbol: _ZTv0_n24_NSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED1Ev
// EN: AArch64 prologue [bti c; ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x8, x0, x8] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x8, x0, x8]
uint64_t fde_sub_065a48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065A48ULL;
}

// FDE #0159 | PC: 0x065a60..0x065a90 (48 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_065a60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065A60ULL;
}

// FDE #0160 | PC: 0x065a90..0x065ac8 (56 B) | Symbol: _ZTv0_n24_NSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_065a90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065A90ULL;
}

// FDE #0161 | PC: 0x065ac8..0x065b3c (116 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE4swapERS3_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_065ac8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065AC8ULL;
}

// FDE #0162 | PC: 0x065b3c..0x065d60 (548 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE6sentryC1ERS3_b
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]]
uint64_t fde_sub_065b3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0224ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065B3CULL;
}

// FDE #0163 | PC: 0x065d60..0x065eac (332 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE5flushEv
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_065d60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x014CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065D60ULL;
}

// FDE #0164 | PC: 0x065eac..0x065ebc (16 B) | Symbol: _ZNKSt6__ndk18ios_base6getlocEv
// EN: AArch64 prologue [bti c; add x1, x0, #0x30; mov x0, x8; b #0xc8960] | VI: Khởi đầu hàm AArch64 [bti c; add x1, x0, #0x30; mov x0, x8; b #0xc8960]
uint64_t fde_sub_065eac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9100C001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065EACULL;
}

// FDE #0165 | PC: 0x065ebc..0x065ec8 (12 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsEPFRS3_S4_E
// EN: AArch64 prologue [bti c; mov x16, x1; br x16] | VI: Khởi đầu hàm AArch64 [bti c; mov x16, x1; br x16]
uint64_t fde_sub_065ebc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103F0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065EBCULL;
}

// FDE #0166 | PC: 0x065ec8..0x065f00 (56 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsEPFRNS_9basic_iosIcS2_EES6_E
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_065ec8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065EC8ULL;
}

// FDE #0167 | PC: 0x065f00..0x065f38 (56 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsEPFRNS_8ios_baseES5_E
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_065f00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065F00ULL;
}

// FDE #0168 | PC: 0x065f38..0x06613c (516 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsEPNS_15basic_streambufIcS2_EE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_065f38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0204ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065F38ULL;
}

// FDE #0169 | PC: 0x06613c..0x066144 (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERb
// EN: AArch64 prologue [bti c; b #0x66144] | VI: Khởi đầu hàm AArch64 [bti c; b #0x66144]
uint64_t fde_sub_06613c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06613CULL;
}

// FDE #0170 | PC: 0x066144..0x0662bc (376 B) | Symbol: sub_066144
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_066144(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066144ULL;
}

// FDE #0171 | PC: 0x0662bc..0x0662c4 (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERs
// EN: AArch64 prologue [bti c; b #0x662c4] | VI: Khởi đầu hàm AArch64 [bti c; b #0x662c4]
uint64_t fde_sub_0662bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0662BCULL;
}

// FDE #0172 | PC: 0x0662c4..0x06647c (440 B) | Symbol: sub_0662c4
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_0662c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0662C4ULL;
}

// FDE #0173 | PC: 0x06647c..0x066484 (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERt
// EN: AArch64 prologue [bti c; b #0x66484] | VI: Khởi đầu hàm AArch64 [bti c; b #0x66484]
uint64_t fde_sub_06647c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06647CULL;
}

// FDE #0174 | PC: 0x066484..0x0665fc (376 B) | Symbol: sub_066484
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_066484(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066484ULL;
}

// FDE #0175 | PC: 0x0665fc..0x066604 (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERi
// EN: AArch64 prologue [bti c; b #0x66604] | VI: Khởi đầu hàm AArch64 [bti c; b #0x66604]
uint64_t fde_sub_0665fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0665FCULL;
}

// FDE #0176 | PC: 0x066604..0x0667c0 (444 B) | Symbol: sub_066604
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_066604(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066604ULL;
}

// FDE #0177 | PC: 0x0667c0..0x0667c8 (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERj
// EN: AArch64 prologue [bti c; b #0x667c8] | VI: Khởi đầu hàm AArch64 [bti c; b #0x667c8]
uint64_t fde_sub_0667c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0667C0ULL;
}

// FDE #0178 | PC: 0x0667c8..0x066940 (376 B) | Symbol: sub_0667c8
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_0667c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0667C8ULL;
}

// FDE #0179 | PC: 0x066940..0x066948 (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERl
// EN: AArch64 prologue [bti c; b #0x66948] | VI: Khởi đầu hàm AArch64 [bti c; b #0x66948]
uint64_t fde_sub_066940(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066940ULL;
}

// FDE #0180 | PC: 0x066948..0x066ac0 (376 B) | Symbol: sub_066948
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_066948(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066948ULL;
}

// FDE #0181 | PC: 0x066ac0..0x066ac8 (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERm
// EN: AArch64 prologue [bti c; b #0x66ac8] | VI: Khởi đầu hàm AArch64 [bti c; b #0x66ac8]
uint64_t fde_sub_066ac0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066AC0ULL;
}

// FDE #0182 | PC: 0x066ac8..0x066c40 (376 B) | Symbol: sub_066ac8
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_066ac8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066AC8ULL;
}

// FDE #0183 | PC: 0x066c40..0x066c48 (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERx
// EN: AArch64 prologue [bti c; b #0x66c48] | VI: Khởi đầu hàm AArch64 [bti c; b #0x66c48]
uint64_t fde_sub_066c40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066C40ULL;
}

// FDE #0184 | PC: 0x066c48..0x066dc0 (376 B) | Symbol: sub_066c48
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_066c48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066C48ULL;
}

// FDE #0185 | PC: 0x066dc0..0x066dc8 (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERy
// EN: AArch64 prologue [bti c; b #0x66dc8] | VI: Khởi đầu hàm AArch64 [bti c; b #0x66dc8]
uint64_t fde_sub_066dc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066DC0ULL;
}

// FDE #0186 | PC: 0x066dc8..0x066f40 (376 B) | Symbol: sub_066dc8
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_066dc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066DC8ULL;
}

// FDE #0187 | PC: 0x066f40..0x066f48 (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERf
// EN: AArch64 prologue [bti c; b #0x66f48] | VI: Khởi đầu hàm AArch64 [bti c; b #0x66f48]
uint64_t fde_sub_066f40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066F40ULL;
}

// FDE #0188 | PC: 0x066f48..0x0670c0 (376 B) | Symbol: sub_066f48
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_066f48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066F48ULL;
}

// FDE #0189 | PC: 0x0670c0..0x0670c8 (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERd
// EN: AArch64 prologue [bti c; b #0x670c8] | VI: Khởi đầu hàm AArch64 [bti c; b #0x670c8]
uint64_t fde_sub_0670c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0670C0ULL;
}

// FDE #0190 | PC: 0x0670c8..0x067240 (376 B) | Symbol: sub_0670c8
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_0670c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0670C8ULL;
}

// FDE #0191 | PC: 0x067240..0x067248 (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERe
// EN: AArch64 prologue [bti c; b #0x67248] | VI: Khởi đầu hàm AArch64 [bti c; b #0x67248]
uint64_t fde_sub_067240(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067240ULL;
}

// FDE #0192 | PC: 0x067248..0x0673c0 (376 B) | Symbol: sub_067248
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_067248(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067248ULL;
}

// FDE #0193 | PC: 0x0673c0..0x0673c8 (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERPv
// EN: AArch64 prologue [bti c; b #0x673c8] | VI: Khởi đầu hàm AArch64 [bti c; b #0x673c8]
uint64_t fde_sub_0673c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0673C0ULL;
}

// FDE #0194 | PC: 0x0673c8..0x067540 (376 B) | Symbol: sub_0673c8
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_0673c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0673C8ULL;
}

// FDE #0195 | PC: 0x067540..0x0676ac (364 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE3getEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_067540(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x016CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067540ULL;
}

// FDE #0196 | PC: 0x0676ac..0x0676e8 (60 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE3getERc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0676ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0676ACULL;
}

// FDE #0197 | PC: 0x0676e8..0x0677b8 (208 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE3getEPcl
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]]
uint64_t fde_sub_0676e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0676E8ULL;
}

// FDE #0198 | PC: 0x0677b8..0x0679f8 (576 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE3getEPclc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_0677b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0240ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0677B8ULL;
}

// FDE #0199 | PC: 0x0679f8..0x067ab8 (192 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE3getERNS_15basic_streambufIcS2_EE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x40; stp x29, x30, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x40; stp x29, x30, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0679f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10103FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0679F8ULL;
}

// FDE #0200 | PC: 0x067ab8..0x067c74 (444 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE3getERNS_15basic_streambufIcS2_EEc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_067ab8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067AB8ULL;
}

// FDE #0201 | PC: 0x067c74..0x067d44 (208 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE7getlineEPcl
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]]
uint64_t fde_sub_067c74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067C74ULL;
}

// FDE #0202 | PC: 0x067d44..0x067fa4 (608 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE7getlineEPclc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_067d44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0260ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067D44ULL;
}

// FDE #0203 | PC: 0x067fa4..0x0681a0 (508 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE6ignoreEli
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_067fa4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067FA4ULL;
}

// FDE #0204 | PC: 0x0681a0..0x0682f4 (340 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE4peekEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0681a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0154ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0681A0ULL;
}

// FDE #0205 | PC: 0x0682f4..0x068448 (340 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE4readEPcl
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0682f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0154ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0682F4ULL;
}

// FDE #0206 | PC: 0x068448..0x0685f4 (428 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE8readsomeEPcl
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_068448(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068448ULL;
}

// FDE #0207 | PC: 0x0685f4..0x06879c (424 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE7putbackEc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0685f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0685F4ULL;
}

// FDE #0208 | PC: 0x06879c..0x068930 (404 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE5ungetEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_06879c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0194ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06879CULL;
}

// FDE #0209 | PC: 0x068930..0x068a6c (316 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE4syncEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_068930(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x013CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068930ULL;
}

// FDE #0210 | PC: 0x068a6c..0x068bac (320 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE5tellgEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_068a6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0140ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068A6CULL;
}

// FDE #0211 | PC: 0x068bac..0x068d28 (380 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE5seekgENS_4fposI9mbstate_tEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_068bac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x017CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068BACULL;
}

// FDE #0212 | PC: 0x068d28..0x068ea4 (380 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE5seekgExNS_8ios_base7seekdirE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_068d28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x017CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068D28ULL;
}

// FDE #0213 | PC: 0x068ea4..0x068f38 (148 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEEC2EPNS_15basic_streambufIwS2_EE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_068ea4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068EA4ULL;
}

// FDE #0214 | PC: 0x068f38..0x068fc4 (140 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEEC1EPNS_15basic_streambufIwS2_EE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_068f38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068F38ULL;
}

// FDE #0215 | PC: 0x068fc4..0x068fcc (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEED2Ev
// EN: AArch64 prologue [bti c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ret]
uint64_t fde_sub_068fc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068FC4ULL;
}

// FDE #0216 | PC: 0x068fcc..0x068fd8 (12 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEED1Ev
// EN: AArch64 prologue [bti c; add x0, x0, #0x10; b #0xc89d0] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x10; b #0xc89d0]
uint64_t fde_sub_068fcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91004000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068FCCULL;
}

// FDE #0217 | PC: 0x068fd8..0x068ff0 (24 B) | Symbol: _ZTv0_n24_NSt6__ndk113basic_istreamIwNS_11char_traitsIwEEED1Ev
// EN: AArch64 prologue [bti c; ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x8, x0, x8] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x8, x0, x8]
uint64_t fde_sub_068fd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068FD8ULL;
}

// FDE #0218 | PC: 0x068ff0..0x069020 (48 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_068ff0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068FF0ULL;
}

// FDE #0219 | PC: 0x069020..0x069058 (56 B) | Symbol: _ZTv0_n24_NSt6__ndk113basic_istreamIwNS_11char_traitsIwEEED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_069020(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069020ULL;
}

// FDE #0220 | PC: 0x069058..0x0690cc (116 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE4swapERS3_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_069058(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069058ULL;
}

// FDE #0221 | PC: 0x0690cc..0x069308 (572 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE6sentryC2ERS3_b
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_0690cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x023CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0690CCULL;
}

// FDE #0222 | PC: 0x069308..0x069454 (332 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEE5flushEv
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_069308(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x014CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069308ULL;
}

// FDE #0223 | PC: 0x069454..0x069460 (12 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsEPFRS3_S4_E
// EN: AArch64 prologue [bti c; mov x16, x1; br x16] | VI: Khởi đầu hàm AArch64 [bti c; mov x16, x1; br x16]
uint64_t fde_sub_069454(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103F0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069454ULL;
}

// FDE #0224 | PC: 0x069460..0x069498 (56 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsEPFRNS_9basic_iosIwS2_EES6_E
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_069460(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069460ULL;
}

// FDE #0225 | PC: 0x069498..0x0694d0 (56 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsEPFRNS_8ios_baseES5_E
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_069498(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069498ULL;
}

// FDE #0226 | PC: 0x0694d0..0x0696d4 (516 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsEPNS_15basic_streambufIwS2_EE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0694d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0204ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0694D0ULL;
}

// FDE #0227 | PC: 0x0696d4..0x0696dc (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsERb
// EN: AArch64 prologue [bti c; b #0x696dc] | VI: Khởi đầu hàm AArch64 [bti c; b #0x696dc]
uint64_t fde_sub_0696d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0696D4ULL;
}

// FDE #0228 | PC: 0x0696dc..0x069854 (376 B) | Symbol: sub_0696dc
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_0696dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0696DCULL;
}

// FDE #0229 | PC: 0x069854..0x06985c (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsERs
// EN: AArch64 prologue [bti c; b #0x6985c] | VI: Khởi đầu hàm AArch64 [bti c; b #0x6985c]
uint64_t fde_sub_069854(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069854ULL;
}

// FDE #0230 | PC: 0x06985c..0x069a14 (440 B) | Symbol: sub_06985c
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_06985c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06985CULL;
}

// FDE #0231 | PC: 0x069a14..0x069a1c (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsERt
// EN: AArch64 prologue [bti c; b #0x69a1c] | VI: Khởi đầu hàm AArch64 [bti c; b #0x69a1c]
uint64_t fde_sub_069a14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069A14ULL;
}

// FDE #0232 | PC: 0x069a1c..0x069b94 (376 B) | Symbol: sub_069a1c
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_069a1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069A1CULL;
}

// FDE #0233 | PC: 0x069b94..0x069b9c (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsERi
// EN: AArch64 prologue [bti c; b #0x69b9c] | VI: Khởi đầu hàm AArch64 [bti c; b #0x69b9c]
uint64_t fde_sub_069b94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069B94ULL;
}

// FDE #0234 | PC: 0x069b9c..0x069d58 (444 B) | Symbol: sub_069b9c
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_069b9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069B9CULL;
}

// FDE #0235 | PC: 0x069d58..0x069d60 (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsERj
// EN: AArch64 prologue [bti c; b #0x69d60] | VI: Khởi đầu hàm AArch64 [bti c; b #0x69d60]
uint64_t fde_sub_069d58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069D58ULL;
}

// FDE #0236 | PC: 0x069d60..0x069ed8 (376 B) | Symbol: sub_069d60
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_069d60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069D60ULL;
}

// FDE #0237 | PC: 0x069ed8..0x069ee0 (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsERl
// EN: AArch64 prologue [bti c; b #0x69ee0] | VI: Khởi đầu hàm AArch64 [bti c; b #0x69ee0]
uint64_t fde_sub_069ed8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069ED8ULL;
}

// FDE #0238 | PC: 0x069ee0..0x06a058 (376 B) | Symbol: sub_069ee0
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_069ee0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069EE0ULL;
}

// FDE #0239 | PC: 0x06a058..0x06a060 (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsERm
// EN: AArch64 prologue [bti c; b #0x6a060] | VI: Khởi đầu hàm AArch64 [bti c; b #0x6a060]
uint64_t fde_sub_06a058(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A058ULL;
}

// FDE #0240 | PC: 0x06a060..0x06a1d8 (376 B) | Symbol: sub_06a060
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_06a060(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A060ULL;
}

// FDE #0241 | PC: 0x06a1d8..0x06a1e0 (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsERx
// EN: AArch64 prologue [bti c; b #0x6a1e0] | VI: Khởi đầu hàm AArch64 [bti c; b #0x6a1e0]
uint64_t fde_sub_06a1d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A1D8ULL;
}

// FDE #0242 | PC: 0x06a1e0..0x06a358 (376 B) | Symbol: sub_06a1e0
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_06a1e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A1E0ULL;
}

// FDE #0243 | PC: 0x06a358..0x06a360 (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsERy
// EN: AArch64 prologue [bti c; b #0x6a360] | VI: Khởi đầu hàm AArch64 [bti c; b #0x6a360]
uint64_t fde_sub_06a358(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A358ULL;
}

// FDE #0244 | PC: 0x06a360..0x06a4d8 (376 B) | Symbol: sub_06a360
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_06a360(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A360ULL;
}

// FDE #0245 | PC: 0x06a4d8..0x06a4e0 (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsERf
// EN: AArch64 prologue [bti c; b #0x6a4e0] | VI: Khởi đầu hàm AArch64 [bti c; b #0x6a4e0]
uint64_t fde_sub_06a4d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A4D8ULL;
}

// FDE #0246 | PC: 0x06a4e0..0x06a658 (376 B) | Symbol: sub_06a4e0
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_06a4e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A4E0ULL;
}

// FDE #0247 | PC: 0x06a658..0x06a660 (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsERd
// EN: AArch64 prologue [bti c; b #0x6a660] | VI: Khởi đầu hàm AArch64 [bti c; b #0x6a660]
uint64_t fde_sub_06a658(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A658ULL;
}

// FDE #0248 | PC: 0x06a660..0x06a7d8 (376 B) | Symbol: sub_06a660
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_06a660(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A660ULL;
}

// FDE #0249 | PC: 0x06a7d8..0x06a7e0 (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsERe
// EN: AArch64 prologue [bti c; b #0x6a7e0] | VI: Khởi đầu hàm AArch64 [bti c; b #0x6a7e0]
uint64_t fde_sub_06a7d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A7D8ULL;
}

// FDE #0250 | PC: 0x06a7e0..0x06a958 (376 B) | Symbol: sub_06a7e0
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_06a7e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A7E0ULL;
}

// FDE #0251 | PC: 0x06a958..0x06a960 (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsERPv
// EN: AArch64 prologue [bti c; b #0x6a960] | VI: Khởi đầu hàm AArch64 [bti c; b #0x6a960]
uint64_t fde_sub_06a958(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A958ULL;
}

// FDE #0252 | PC: 0x06a960..0x06aad8 (376 B) | Symbol: sub_06a960
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_06a960(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A960ULL;
}

// FDE #0253 | PC: 0x06aad8..0x06ac48 (368 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE3getEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_06aad8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AAD8ULL;
}

// FDE #0254 | PC: 0x06ac48..0x06ac84 (60 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE3getERw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_06ac48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AC48ULL;
}

// FDE #0255 | PC: 0x06ac84..0x06ad54 (208 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE3getEPwl
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]]
uint64_t fde_sub_06ac84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AC84ULL;
}

// FDE #0256 | PC: 0x06ad54..0x06af90 (572 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE3getEPwlw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_06ad54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x023CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AD54ULL;
}

// FDE #0257 | PC: 0x06af90..0x06b050 (192 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE3getERNS_15basic_streambufIwS2_EE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x40; stp x29, x30, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x40; stp x29, x30, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_06af90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10103FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AF90ULL;
}

// FDE #0258 | PC: 0x06b050..0x06b208 (440 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE3getERNS_15basic_streambufIwS2_EEw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_06b050(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B050ULL;
}

// FDE #0259 | PC: 0x06b208..0x06b2d8 (208 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE7getlineEPwl
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x10]; str x23, [sp, #0x20]]
uint64_t fde_sub_06b208(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B208ULL;
}

// FDE #0260 | PC: 0x06b2d8..0x06b530 (600 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE7getlineEPwlw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_06b2d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0258ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B2D8ULL;
}

// FDE #0261 | PC: 0x06b530..0x06b724 (500 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE6ignoreElj
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_06b530(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B530ULL;
}

// FDE #0262 | PC: 0x06b724..0x06b878 (340 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE4peekEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_06b724(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0154ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B724ULL;
}

// FDE #0263 | PC: 0x06b878..0x06b9cc (340 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE4readEPwl
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_06b878(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0154ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B878ULL;
}

// FDE #0264 | PC: 0x06b9cc..0x06bb7c (432 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE8readsomeEPwl
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_06b9cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B9CCULL;
}

// FDE #0265 | PC: 0x06bb7c..0x06bd30 (436 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE7putbackEw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_06bb7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BB7CULL;
}

// FDE #0266 | PC: 0x06bd30..0x06bec8 (408 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE5ungetEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_06bd30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0198ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BD30ULL;
}

// FDE #0267 | PC: 0x06bec8..0x06c004 (316 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE4syncEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_06bec8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x013CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BEC8ULL;
}

// FDE #0268 | PC: 0x06c004..0x06c144 (320 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE5tellgEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_06c004(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0140ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C004ULL;
}

// FDE #0269 | PC: 0x06c144..0x06c2c0 (380 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE5seekgENS_4fposI9mbstate_tEE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_06c144(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x017CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C144ULL;
}

// FDE #0270 | PC: 0x06c2c0..0x06c43c (380 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE5seekgExNS_8ios_base7seekdirE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_06c2c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x017CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C2C0ULL;
}

// FDE #0271 | PC: 0x06c43c..0x06c4cc (144 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEEC2EPNS_15basic_streambufIcS2_EE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_06c43c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C43CULL;
}

// FDE #0272 | PC: 0x06c4cc..0x06c54c (128 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEEC1EPNS_15basic_streambufIcS2_EE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_06c4cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C4CCULL;
}

// FDE #0273 | PC: 0x06c54c..0x06c554 (8 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED2Ev
// EN: AArch64 prologue [bti c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ret]
uint64_t fde_sub_06c54c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C54CULL;
}

// FDE #0274 | PC: 0x06c554..0x06c560 (12 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED1Ev
// EN: AArch64 prologue [bti c; add x0, x0, #8; b #0xc89d0] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #8; b #0xc89d0]
uint64_t fde_sub_06c554(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91002000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C554ULL;
}

// FDE #0275 | PC: 0x06c560..0x06c578 (24 B) | Symbol: _ZTv0_n24_NSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED1Ev
// EN: AArch64 prologue [bti c; ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x8, x0, x8] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x8, x0, x8]
uint64_t fde_sub_06c560(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C560ULL;
}

// FDE #0276 | PC: 0x06c578..0x06c5a8 (48 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_06c578(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C578ULL;
}

// FDE #0277 | PC: 0x06c5a8..0x06c5e0 (56 B) | Symbol: _ZTv0_n24_NSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_06c5a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C5A8ULL;
}

// FDE #0278 | PC: 0x06c5e0..0x06c644 (100 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE4swapERS3_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_06c5e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C5E0ULL;
}

// FDE #0279 | PC: 0x06c644..0x06c698 (84 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryC2ERS3_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_06c644(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C644ULL;
}

// FDE #0280 | PC: 0x06c698..0x06c754 (188 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryD2Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_06c698(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C698ULL;
}

// FDE #0281 | PC: 0x06c754..0x06c760 (12 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEPFRS3_S4_E
// EN: AArch64 prologue [bti c; mov x16, x1; br x16] | VI: Khởi đầu hàm AArch64 [bti c; mov x16, x1; br x16]
uint64_t fde_sub_06c754(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103F0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C754ULL;
}

// FDE #0282 | PC: 0x06c760..0x06c798 (56 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEPFRNS_9basic_iosIcS2_EES6_E
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_06c760(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C760ULL;
}

// FDE #0283 | PC: 0x06c798..0x06c7d0 (56 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEPFRNS_8ios_baseES5_E
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_06c798(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C798ULL;
}

// FDE #0284 | PC: 0x06c7d0..0x06c9c8 (504 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEb
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]]
uint64_t fde_sub_06c7d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C7D0ULL;
}

// FDE #0285 | PC: 0x06c9c8..0x06c9f8 (48 B) | Symbol: _ZNSt6__ndk18ios_base33__set_badbit_and_consider_rethrowEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr w8, [x0, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr w8, [x0, #0x20]]
uint64_t fde_sub_06c9c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C9C8ULL;
}

// FDE #0286 | PC: 0x06c9f8..0x06cc10 (536 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEs
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; stp x26, x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; stp x26, x25, [sp, #0x30]]
uint64_t fde_sub_06c9f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0218ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C9F8ULL;
}

// FDE #0287 | PC: 0x06cc10..0x06ce08 (504 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEt
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]]
uint64_t fde_sub_06cc10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06CC10ULL;
}

// FDE #0288 | PC: 0x06ce08..0x06d020 (536 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEi
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; stp x26, x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; stp x26, x25, [sp, #0x30]]
uint64_t fde_sub_06ce08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0218ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06CE08ULL;
}

// FDE #0289 | PC: 0x06d020..0x06d218 (504 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEj
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]]
uint64_t fde_sub_06d020(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D020ULL;
}

// FDE #0290 | PC: 0x06d218..0x06d410 (504 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEl
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]]
uint64_t fde_sub_06d218(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D218ULL;
}

// FDE #0291 | PC: 0x06d410..0x06d608 (504 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEm
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]]
uint64_t fde_sub_06d410(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D410ULL;
}

// FDE #0292 | PC: 0x06d608..0x06d800 (504 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEx
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]]
uint64_t fde_sub_06d608(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D608ULL;
}

// FDE #0293 | PC: 0x06d800..0x06d9f8 (504 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEy
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]]
uint64_t fde_sub_06d800(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D800ULL;
}

// FDE #0294 | PC: 0x06d9f8..0x06dbf0 (504 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEf
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; str d8, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; str d8, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06d9f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D9F8ULL;
}

// FDE #0295 | PC: 0x06dbf0..0x06dde8 (504 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEd
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; str d8, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; str d8, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06dbf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06DBF0ULL;
}

// FDE #0296 | PC: 0x06dde8..0x06dfd8 (496 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEe
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_06dde8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06DDE8ULL;
}

// FDE #0297 | PC: 0x06dfd8..0x06e1d0 (504 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEPKv
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]]
uint64_t fde_sub_06dfd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06DFD8ULL;
}

// FDE #0298 | PC: 0x06e1d0..0x06e434 (612 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEPNS_15basic_streambufIcS2_EE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]]
uint64_t fde_sub_06e1d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0264ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E1D0ULL;
}

// FDE #0299 | PC: 0x06e434..0x06e464 (48 B) | Symbol: _ZNSt6__ndk18ios_base34__set_failbit_and_consider_rethrowEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr w8, [x0, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr w8, [x0, #0x20]]
uint64_t fde_sub_06e434(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E434ULL;
}

// FDE #0300 | PC: 0x06e464..0x06e5c8 (356 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE3putEc
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_06e464(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0164ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E464ULL;
}

// FDE #0301 | PC: 0x06e5c8..0x06e724 (348 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE5writeEPKcl
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]]
uint64_t fde_sub_06e5c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x015CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E5C8ULL;
}

// FDE #0302 | PC: 0x06e724..0x06e780 (92 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE5tellpEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0]]
uint64_t fde_sub_06e724(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E724ULL;
}

// FDE #0303 | PC: 0x06e780..0x06e8b0 (304 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE5seekpENS_4fposI9mbstate_tEE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_06e780(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E780ULL;
}

// FDE #0304 | PC: 0x06e8b0..0x06e9e0 (304 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE5seekpExNS_8ios_base7seekdirE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_06e8b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E8B0ULL;
}

// FDE #0305 | PC: 0x06e9e0..0x06ea70 (144 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEEC2EPNS_15basic_streambufIwS2_EE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_06e9e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E9E0ULL;
}

// FDE #0306 | PC: 0x06ea70..0x06eaf0 (128 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEEC1EPNS_15basic_streambufIwS2_EE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_06ea70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EA70ULL;
}

// FDE #0307 | PC: 0x06eaf0..0x06eaf8 (8 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEED2Ev
// EN: AArch64 prologue [bti c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ret]
uint64_t fde_sub_06eaf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EAF0ULL;
}

// FDE #0308 | PC: 0x06eaf8..0x06eb04 (12 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEED1Ev
// EN: AArch64 prologue [bti c; add x0, x0, #8; b #0xc89d0] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #8; b #0xc89d0]
uint64_t fde_sub_06eaf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91002000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EAF8ULL;
}

// FDE #0309 | PC: 0x06eb04..0x06eb1c (24 B) | Symbol: _ZTv0_n24_NSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEED1Ev
// EN: AArch64 prologue [bti c; ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x8, x0, x8] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x8, x0, x8]
uint64_t fde_sub_06eb04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EB04ULL;
}

// FDE #0310 | PC: 0x06eb1c..0x06eb4c (48 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_06eb1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EB1CULL;
}

// FDE #0311 | PC: 0x06eb4c..0x06eb84 (56 B) | Symbol: _ZTv0_n24_NSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_06eb4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EB4CULL;
}

// FDE #0312 | PC: 0x06eb84..0x06ebe8 (100 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEE4swapERS3_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_06eb84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EB84ULL;
}

// FDE #0313 | PC: 0x06ebe8..0x06ec3c (84 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEE6sentryC2ERS3_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_06ebe8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EBE8ULL;
}

// FDE #0314 | PC: 0x06ec3c..0x06ecf8 (188 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEE6sentryD2Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_06ec3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EC3CULL;
}

// FDE #0315 | PC: 0x06ecf8..0x06ed04 (12 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEPFRS3_S4_E
// EN: AArch64 prologue [bti c; mov x16, x1; br x16] | VI: Khởi đầu hàm AArch64 [bti c; mov x16, x1; br x16]
uint64_t fde_sub_06ecf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103F0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06ECF8ULL;
}

// FDE #0316 | PC: 0x06ed04..0x06ed3c (56 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEPFRNS_9basic_iosIwS2_EES6_E
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_06ed04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06ED04ULL;
}

// FDE #0317 | PC: 0x06ed3c..0x06ed74 (56 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEPFRNS_8ios_baseES5_E
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_06ed3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06ED3CULL;
}

// FDE #0318 | PC: 0x06ed74..0x06ef6c (504 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEb
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]]
uint64_t fde_sub_06ed74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06ED74ULL;
}

// FDE #0319 | PC: 0x06ef6c..0x06f184 (536 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEs
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; stp x26, x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; stp x26, x25, [sp, #0x30]]
uint64_t fde_sub_06ef6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0218ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EF6CULL;
}

// FDE #0320 | PC: 0x06f184..0x06f37c (504 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEt
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]]
uint64_t fde_sub_06f184(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F184ULL;
}

// FDE #0321 | PC: 0x06f37c..0x06f594 (536 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEi
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; stp x26, x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; stp x26, x25, [sp, #0x30]]
uint64_t fde_sub_06f37c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0218ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F37CULL;
}

// FDE #0322 | PC: 0x06f594..0x06f78c (504 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEj
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]]
uint64_t fde_sub_06f594(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F594ULL;
}

// FDE #0323 | PC: 0x06f78c..0x06f984 (504 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEl
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]]
uint64_t fde_sub_06f78c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F78CULL;
}

// FDE #0324 | PC: 0x06f984..0x06fb7c (504 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEm
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]]
uint64_t fde_sub_06f984(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F984ULL;
}

// FDE #0325 | PC: 0x06fb7c..0x06fd74 (504 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEx
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]]
uint64_t fde_sub_06fb7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FB7CULL;
}

// FDE #0326 | PC: 0x06fd74..0x06ff6c (504 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEy
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]]
uint64_t fde_sub_06fd74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FD74ULL;
}

// FDE #0327 | PC: 0x06ff6c..0x070164 (504 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEf
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; str d8, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; str d8, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06ff6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FF6CULL;
}

// FDE #0328 | PC: 0x070164..0x07035c (504 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEd
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; str d8, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; str d8, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_070164(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070164ULL;
}

// FDE #0329 | PC: 0x07035c..0x07054c (496 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEe
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_07035c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07035CULL;
}

// FDE #0330 | PC: 0x07054c..0x070744 (504 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEPKv
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x20]; str x25, [sp, #0x30]]
uint64_t fde_sub_07054c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07054CULL;
}

// FDE #0331 | PC: 0x070744..0x0709b8 (628 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEPNS_15basic_streambufIwS2_EE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_070744(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0274ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070744ULL;
}

// FDE #0332 | PC: 0x0709b8..0x070b28 (368 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEE3putEw
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_0709b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0709B8ULL;
}

// FDE #0333 | PC: 0x070b28..0x070c84 (348 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEE5writeEPKwl
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; str x23, [sp, #0x30]]
uint64_t fde_sub_070b28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x015CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070B28ULL;
}

// FDE #0334 | PC: 0x070c84..0x070ce0 (92 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEE5tellpEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0]]
uint64_t fde_sub_070c84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070C84ULL;
}

// FDE #0335 | PC: 0x070ce0..0x070e10 (304 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEE5seekpENS_4fposI9mbstate_tEE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_070ce0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070CE0ULL;
}

// FDE #0336 | PC: 0x070e10..0x070f40 (304 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEE5seekpExNS_8ios_base7seekdirE
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_070e10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070E10ULL;
}

// FDE #0337 | PC: 0x070f40..0x071018 (216 B) | Symbol: _ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEEC2EPNS_15basic_streambufIcS2_EE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_070f40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070F40ULL;
}

// FDE #0338 | PC: 0x071018..0x0710b8 (160 B) | Symbol: _ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEEC1EPNS_15basic_streambufIcS2_EE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_071018(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071018ULL;
}

// FDE #0339 | PC: 0x0710b8..0x0710c0 (8 B) | Symbol: _ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED2Ev
// EN: AArch64 prologue [bti c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ret]
uint64_t fde_sub_0710b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0710B8ULL;
}

// FDE #0340 | PC: 0x0710c0..0x0710cc (12 B) | Symbol: _ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED1Ev
// EN: AArch64 prologue [bti c; add x0, x0, #0x18; b #0xc89d0] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x18; b #0xc89d0]
uint64_t fde_sub_0710c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91006000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0710C0ULL;
}

// FDE #0341 | PC: 0x0710cc..0x0710d8 (12 B) | Symbol: _ZThn16_NSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED1Ev
// EN: AArch64 prologue [bti c; add x0, x0, #8; b #0xc89d0] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #8; b #0xc89d0]
uint64_t fde_sub_0710cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91002000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0710CCULL;
}

// FDE #0342 | PC: 0x0710d8..0x0710f0 (24 B) | Symbol: _ZTv0_n24_NSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED1Ev
// EN: AArch64 prologue [bti c; ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x8, x0, x8] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x8, x0, x8]
uint64_t fde_sub_0710d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0710D8ULL;
}

// FDE #0343 | PC: 0x0710f0..0x071120 (48 B) | Symbol: _ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0710f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0710F0ULL;
}

// FDE #0344 | PC: 0x071120..0x071150 (48 B) | Symbol: _ZThn16_NSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_071120(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071120ULL;
}

// FDE #0345 | PC: 0x071150..0x071188 (56 B) | Symbol: _ZTv0_n24_NSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_071150(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071150ULL;
}

// FDE #0346 | PC: 0x071188..0x0711fc (116 B) | Symbol: _ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEE4swapERS3_
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_071188(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071188ULL;
}

// FDE #0347 | PC: 0x0711fc..0x07120c (16 B) | Symbol: sub_0711fc
// EN: AArch64 prologue [bti c; adrp x0, #0x49000; add x0, x0, #0x6c; ret] | VI: Khởi đầu hàm AArch64 [bti c; adrp x0, #0x49000; add x0, x0, #0x6c; ret]
uint64_t fde_sub_0711fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90FFFEC0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0711FCULL;
}

// FDE #0348 | PC: 0x07120c..0x07128c (128 B) | Symbol: sub_07120c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_07120c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07120CULL;
}

// FDE #0349 | PC: 0x07128c..0x071318 (140 B) | Symbol: _ZNSt6__ndk117iostream_categoryEv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_07128c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07128CULL;
}

// FDE #0350 | PC: 0x071318..0x071358 (64 B) | Symbol: _ZNSt6__ndk18ios_base7failureC2ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERKNS_10error_codeE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_071318(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071318ULL;
}

// FDE #0351 | PC: 0x071358..0x071398 (64 B) | Symbol: _ZNSt6__ndk18ios_base7failureC1EPKcRKNS_10error_codeE
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_071358(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071358ULL;
}

uint64_t DispatchAppLovinShard1(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x060694ULL: return fde_sub_060694(a0, a1, a2);
        case 0x0606a4ULL: return fde_sub_0606a4(a0, a1, a2);
        case 0x0606acULL: return fde_sub_0606ac(a0, a1, a2);
        case 0x0606b4ULL: return fde_sub_0606b4(a0, a1, a2);
        case 0x0606c8ULL: return fde_sub_0606c8(a0, a1, a2);
        case 0x0606e8ULL: return fde_sub_0606e8(a0, a1, a2);
        case 0x0608dcULL: return fde_sub_0608dc(a0, a1, a2);
        case 0x060984ULL: return fde_sub_060984(a0, a1, a2);
        case 0x06099cULL: return fde_sub_06099c(a0, a1, a2);
        case 0x0609b4ULL: return fde_sub_0609b4(a0, a1, a2);
        case 0x060ab0ULL: return fde_sub_060ab0(a0, a1, a2);
        case 0x060abcULL: return fde_sub_060abc(a0, a1, a2);
        case 0x060b40ULL: return fde_sub_060b40(a0, a1, a2);
        case 0x060b50ULL: return fde_sub_060b50(a0, a1, a2);
        case 0x060ba0ULL: return fde_sub_060ba0(a0, a1, a2);
        case 0x060bd0ULL: return fde_sub_060bd0(a0, a1, a2);
        case 0x060d00ULL: return fde_sub_060d00(a0, a1, a2);
        case 0x060fe4ULL: return fde_sub_060fe4(a0, a1, a2);
        case 0x061454ULL: return fde_sub_061454(a0, a1, a2);
        case 0x061838ULL: return fde_sub_061838(a0, a1, a2);
        case 0x0618c8ULL: return fde_sub_0618c8(a0, a1, a2);
        case 0x0618f4ULL: return fde_sub_0618f4(a0, a1, a2);
        case 0x061a24ULL: return fde_sub_061a24(a0, a1, a2);
        case 0x061a94ULL: return fde_sub_061a94(a0, a1, a2);
        case 0x061ab4ULL: return fde_sub_061ab4(a0, a1, a2);
        case 0x062088ULL: return fde_sub_062088(a0, a1, a2);
        case 0x0621f8ULL: return fde_sub_0621f8(a0, a1, a2);
        case 0x062604ULL: return fde_sub_062604(a0, a1, a2);
        case 0x06267cULL: return fde_sub_06267c(a0, a1, a2);
        case 0x062800ULL: return fde_sub_062800(a0, a1, a2);
        case 0x0629ccULL: return fde_sub_0629cc(a0, a1, a2);
        case 0x062a20ULL: return fde_sub_062a20(a0, a1, a2);
        case 0x062aacULL: return fde_sub_062aac(a0, a1, a2);
        case 0x062b2cULL: return fde_sub_062b2c(a0, a1, a2);
        case 0x062bc0ULL: return fde_sub_062bc0(a0, a1, a2);
        case 0x062c00ULL: return fde_sub_062c00(a0, a1, a2);
        case 0x062c48ULL: return fde_sub_062c48(a0, a1, a2);
        case 0x062d48ULL: return fde_sub_062d48(a0, a1, a2);
        case 0x062d5cULL: return fde_sub_062d5c(a0, a1, a2);
        case 0x062dacULL: return fde_sub_062dac(a0, a1, a2);
        case 0x062e1cULL: return fde_sub_062e1c(a0, a1, a2);
        case 0x062f8cULL: return fde_sub_062f8c(a0, a1, a2);
        case 0x062fecULL: return fde_sub_062fec(a0, a1, a2);
        case 0x063048ULL: return fde_sub_063048(a0, a1, a2);
        case 0x0630b0ULL: return fde_sub_0630b0(a0, a1, a2);
        case 0x06317cULL: return fde_sub_06317c(a0, a1, a2);
        case 0x0631a0ULL: return fde_sub_0631a0(a0, a1, a2);
        case 0x063290ULL: return fde_sub_063290(a0, a1, a2);
        case 0x063388ULL: return fde_sub_063388(a0, a1, a2);
        case 0x063448ULL: return fde_sub_063448(a0, a1, a2);
        case 0x0634b8ULL: return fde_sub_0634b8(a0, a1, a2);
        case 0x0636a8ULL: return fde_sub_0636a8(a0, a1, a2);
        case 0x063928ULL: return fde_sub_063928(a0, a1, a2);
        case 0x063988ULL: return fde_sub_063988(a0, a1, a2);
        case 0x063bccULL: return fde_sub_063bcc(a0, a1, a2);
        case 0x063c00ULL: return fde_sub_063c00(a0, a1, a2);
        case 0x063d84ULL: return fde_sub_063d84(a0, a1, a2);
        case 0x063f28ULL: return fde_sub_063f28(a0, a1, a2);
        case 0x064128ULL: return fde_sub_064128(a0, a1, a2);
        case 0x064250ULL: return fde_sub_064250(a0, a1, a2);
        case 0x0642d8ULL: return fde_sub_0642d8(a0, a1, a2);
        case 0x0642fcULL: return fde_sub_0642fc(a0, a1, a2);
        case 0x064304ULL: return fde_sub_064304(a0, a1, a2);
        case 0x064310ULL: return fde_sub_064310(a0, a1, a2);
        case 0x064324ULL: return fde_sub_064324(a0, a1, a2);
        case 0x064374ULL: return fde_sub_064374(a0, a1, a2);
        case 0x0643b0ULL: return fde_sub_0643b0(a0, a1, a2);
        case 0x0643dcULL: return fde_sub_0643dc(a0, a1, a2);
        case 0x0643fcULL: return fde_sub_0643fc(a0, a1, a2);
        case 0x06443cULL: return fde_sub_06443c(a0, a1, a2);
        case 0x064494ULL: return fde_sub_064494(a0, a1, a2);
        case 0x0644acULL: return fde_sub_0644ac(a0, a1, a2);
        case 0x0644b4ULL: return fde_sub_0644b4(a0, a1, a2);
        case 0x064540ULL: return fde_sub_064540(a0, a1, a2);
        case 0x06456cULL: return fde_sub_06456c(a0, a1, a2);
        case 0x064654ULL: return fde_sub_064654(a0, a1, a2);
        case 0x0646b4ULL: return fde_sub_0646b4(a0, a1, a2);
        case 0x06497cULL: return fde_sub_06497c(a0, a1, a2);
        case 0x064984ULL: return fde_sub_064984(a0, a1, a2);
        case 0x0649b0ULL: return fde_sub_0649b0(a0, a1, a2);
        case 0x064a98ULL: return fde_sub_064a98(a0, a1, a2);
        case 0x064ab0ULL: return fde_sub_064ab0(a0, a1, a2);
        case 0x064aecULL: return fde_sub_064aec(a0, a1, a2);
        case 0x064b40ULL: return fde_sub_064b40(a0, a1, a2);
        case 0x064b50ULL: return fde_sub_064b50(a0, a1, a2);
        case 0x064b60ULL: return fde_sub_064b60(a0, a1, a2);
        case 0x064b70ULL: return fde_sub_064b70(a0, a1, a2);
        case 0x064b80ULL: return fde_sub_064b80(a0, a1, a2);
        case 0x064b90ULL: return fde_sub_064b90(a0, a1, a2);
        case 0x064bb4ULL: return fde_sub_064bb4(a0, a1, a2);
        case 0x064c3cULL: return fde_sub_064c3c(a0, a1, a2);
        case 0x064c68ULL: return fde_sub_064c68(a0, a1, a2);
        case 0x064c8cULL: return fde_sub_064c8c(a0, a1, a2);
        case 0x064c9cULL: return fde_sub_064c9c(a0, a1, a2);
        case 0x064cd4ULL: return fde_sub_064cd4(a0, a1, a2);
        case 0x064d04ULL: return fde_sub_064d04(a0, a1, a2);
        case 0x064d3cULL: return fde_sub_064d3c(a0, a1, a2);
        case 0x064d4cULL: return fde_sub_064d4c(a0, a1, a2);
        case 0x064d90ULL: return fde_sub_064d90(a0, a1, a2);
        case 0x064decULL: return fde_sub_064dec(a0, a1, a2);
        case 0x064e3cULL: return fde_sub_064e3c(a0, a1, a2);
        case 0x064f30ULL: return fde_sub_064f30(a0, a1, a2);
        case 0x064f44ULL: return fde_sub_064f44(a0, a1, a2);
        case 0x064f54ULL: return fde_sub_064f54(a0, a1, a2);
        case 0x064f68ULL: return fde_sub_064f68(a0, a1, a2);
        case 0x064f78ULL: return fde_sub_064f78(a0, a1, a2);
        case 0x064f80ULL: return fde_sub_064f80(a0, a1, a2);
        case 0x064f88ULL: return fde_sub_064f88(a0, a1, a2);
        case 0x064f98ULL: return fde_sub_064f98(a0, a1, a2);
        case 0x064fa8ULL: return fde_sub_064fa8(a0, a1, a2);
        case 0x064fb4ULL: return fde_sub_064fb4(a0, a1, a2);
        case 0x064fc0ULL: return fde_sub_064fc0(a0, a1, a2);
        case 0x065090ULL: return fde_sub_065090(a0, a1, a2);
        case 0x06509cULL: return fde_sub_06509c(a0, a1, a2);
        case 0x0650e4ULL: return fde_sub_0650e4(a0, a1, a2);
        case 0x0650f0ULL: return fde_sub_0650f0(a0, a1, a2);
        case 0x0651c0ULL: return fde_sub_0651c0(a0, a1, a2);
        case 0x0651ccULL: return fde_sub_0651cc(a0, a1, a2);
        case 0x0651e4ULL: return fde_sub_0651e4(a0, a1, a2);
        case 0x065220ULL: return fde_sub_065220(a0, a1, a2);
        case 0x065274ULL: return fde_sub_065274(a0, a1, a2);
        case 0x065284ULL: return fde_sub_065284(a0, a1, a2);
        case 0x065294ULL: return fde_sub_065294(a0, a1, a2);
        case 0x0652a4ULL: return fde_sub_0652a4(a0, a1, a2);
        case 0x0652b4ULL: return fde_sub_0652b4(a0, a1, a2);
        case 0x0652c4ULL: return fde_sub_0652c4(a0, a1, a2);
        case 0x0652ecULL: return fde_sub_0652ec(a0, a1, a2);
        case 0x065378ULL: return fde_sub_065378(a0, a1, a2);
        case 0x0653a4ULL: return fde_sub_0653a4(a0, a1, a2);
        case 0x0653c8ULL: return fde_sub_0653c8(a0, a1, a2);
        case 0x0653d8ULL: return fde_sub_0653d8(a0, a1, a2);
        case 0x06540cULL: return fde_sub_06540c(a0, a1, a2);
        case 0x06543cULL: return fde_sub_06543c(a0, a1, a2);
        case 0x06546cULL: return fde_sub_06546c(a0, a1, a2);
        case 0x06547cULL: return fde_sub_06547c(a0, a1, a2);
        case 0x0654c0ULL: return fde_sub_0654c0(a0, a1, a2);
        case 0x06551cULL: return fde_sub_06551c(a0, a1, a2);
        case 0x06556cULL: return fde_sub_06556c(a0, a1, a2);
        case 0x065660ULL: return fde_sub_065660(a0, a1, a2);
        case 0x065674ULL: return fde_sub_065674(a0, a1, a2);
        case 0x065684ULL: return fde_sub_065684(a0, a1, a2);
        case 0x065698ULL: return fde_sub_065698(a0, a1, a2);
        case 0x0656a8ULL: return fde_sub_0656a8(a0, a1, a2);
        case 0x0656b0ULL: return fde_sub_0656b0(a0, a1, a2);
        case 0x0656b8ULL: return fde_sub_0656b8(a0, a1, a2);
        case 0x0656c8ULL: return fde_sub_0656c8(a0, a1, a2);
        case 0x0656d8ULL: return fde_sub_0656d8(a0, a1, a2);
        case 0x0656e4ULL: return fde_sub_0656e4(a0, a1, a2);
        case 0x0656f0ULL: return fde_sub_0656f0(a0, a1, a2);
        case 0x0657ccULL: return fde_sub_0657cc(a0, a1, a2);
        case 0x0657d8ULL: return fde_sub_0657d8(a0, a1, a2);
        case 0x065820ULL: return fde_sub_065820(a0, a1, a2);
        case 0x06582cULL: return fde_sub_06582c(a0, a1, a2);
        case 0x065908ULL: return fde_sub_065908(a0, a1, a2);
        case 0x065914ULL: return fde_sub_065914(a0, a1, a2);
        case 0x0659a8ULL: return fde_sub_0659a8(a0, a1, a2);
        case 0x065a34ULL: return fde_sub_065a34(a0, a1, a2);
        case 0x065a3cULL: return fde_sub_065a3c(a0, a1, a2);
        case 0x065a48ULL: return fde_sub_065a48(a0, a1, a2);
        case 0x065a60ULL: return fde_sub_065a60(a0, a1, a2);
        case 0x065a90ULL: return fde_sub_065a90(a0, a1, a2);
        case 0x065ac8ULL: return fde_sub_065ac8(a0, a1, a2);
        case 0x065b3cULL: return fde_sub_065b3c(a0, a1, a2);
        case 0x065d60ULL: return fde_sub_065d60(a0, a1, a2);
        case 0x065eacULL: return fde_sub_065eac(a0, a1, a2);
        case 0x065ebcULL: return fde_sub_065ebc(a0, a1, a2);
        case 0x065ec8ULL: return fde_sub_065ec8(a0, a1, a2);
        case 0x065f00ULL: return fde_sub_065f00(a0, a1, a2);
        case 0x065f38ULL: return fde_sub_065f38(a0, a1, a2);
        case 0x06613cULL: return fde_sub_06613c(a0, a1, a2);
        case 0x066144ULL: return fde_sub_066144(a0, a1, a2);
        case 0x0662bcULL: return fde_sub_0662bc(a0, a1, a2);
        case 0x0662c4ULL: return fde_sub_0662c4(a0, a1, a2);
        case 0x06647cULL: return fde_sub_06647c(a0, a1, a2);
        case 0x066484ULL: return fde_sub_066484(a0, a1, a2);
        case 0x0665fcULL: return fde_sub_0665fc(a0, a1, a2);
        case 0x066604ULL: return fde_sub_066604(a0, a1, a2);
        case 0x0667c0ULL: return fde_sub_0667c0(a0, a1, a2);
        case 0x0667c8ULL: return fde_sub_0667c8(a0, a1, a2);
        case 0x066940ULL: return fde_sub_066940(a0, a1, a2);
        case 0x066948ULL: return fde_sub_066948(a0, a1, a2);
        case 0x066ac0ULL: return fde_sub_066ac0(a0, a1, a2);
        case 0x066ac8ULL: return fde_sub_066ac8(a0, a1, a2);
        case 0x066c40ULL: return fde_sub_066c40(a0, a1, a2);
        case 0x066c48ULL: return fde_sub_066c48(a0, a1, a2);
        case 0x066dc0ULL: return fde_sub_066dc0(a0, a1, a2);
        case 0x066dc8ULL: return fde_sub_066dc8(a0, a1, a2);
        case 0x066f40ULL: return fde_sub_066f40(a0, a1, a2);
        case 0x066f48ULL: return fde_sub_066f48(a0, a1, a2);
        case 0x0670c0ULL: return fde_sub_0670c0(a0, a1, a2);
        case 0x0670c8ULL: return fde_sub_0670c8(a0, a1, a2);
        case 0x067240ULL: return fde_sub_067240(a0, a1, a2);
        case 0x067248ULL: return fde_sub_067248(a0, a1, a2);
        case 0x0673c0ULL: return fde_sub_0673c0(a0, a1, a2);
        case 0x0673c8ULL: return fde_sub_0673c8(a0, a1, a2);
        case 0x067540ULL: return fde_sub_067540(a0, a1, a2);
        case 0x0676acULL: return fde_sub_0676ac(a0, a1, a2);
        case 0x0676e8ULL: return fde_sub_0676e8(a0, a1, a2);
        case 0x0677b8ULL: return fde_sub_0677b8(a0, a1, a2);
        case 0x0679f8ULL: return fde_sub_0679f8(a0, a1, a2);
        case 0x067ab8ULL: return fde_sub_067ab8(a0, a1, a2);
        case 0x067c74ULL: return fde_sub_067c74(a0, a1, a2);
        case 0x067d44ULL: return fde_sub_067d44(a0, a1, a2);
        case 0x067fa4ULL: return fde_sub_067fa4(a0, a1, a2);
        case 0x0681a0ULL: return fde_sub_0681a0(a0, a1, a2);
        case 0x0682f4ULL: return fde_sub_0682f4(a0, a1, a2);
        case 0x068448ULL: return fde_sub_068448(a0, a1, a2);
        case 0x0685f4ULL: return fde_sub_0685f4(a0, a1, a2);
        case 0x06879cULL: return fde_sub_06879c(a0, a1, a2);
        case 0x068930ULL: return fde_sub_068930(a0, a1, a2);
        case 0x068a6cULL: return fde_sub_068a6c(a0, a1, a2);
        case 0x068bacULL: return fde_sub_068bac(a0, a1, a2);
        case 0x068d28ULL: return fde_sub_068d28(a0, a1, a2);
        case 0x068ea4ULL: return fde_sub_068ea4(a0, a1, a2);
        case 0x068f38ULL: return fde_sub_068f38(a0, a1, a2);
        case 0x068fc4ULL: return fde_sub_068fc4(a0, a1, a2);
        case 0x068fccULL: return fde_sub_068fcc(a0, a1, a2);
        case 0x068fd8ULL: return fde_sub_068fd8(a0, a1, a2);
        case 0x068ff0ULL: return fde_sub_068ff0(a0, a1, a2);
        case 0x069020ULL: return fde_sub_069020(a0, a1, a2);
        case 0x069058ULL: return fde_sub_069058(a0, a1, a2);
        case 0x0690ccULL: return fde_sub_0690cc(a0, a1, a2);
        case 0x069308ULL: return fde_sub_069308(a0, a1, a2);
        case 0x069454ULL: return fde_sub_069454(a0, a1, a2);
        case 0x069460ULL: return fde_sub_069460(a0, a1, a2);
        case 0x069498ULL: return fde_sub_069498(a0, a1, a2);
        case 0x0694d0ULL: return fde_sub_0694d0(a0, a1, a2);
        case 0x0696d4ULL: return fde_sub_0696d4(a0, a1, a2);
        case 0x0696dcULL: return fde_sub_0696dc(a0, a1, a2);
        case 0x069854ULL: return fde_sub_069854(a0, a1, a2);
        case 0x06985cULL: return fde_sub_06985c(a0, a1, a2);
        case 0x069a14ULL: return fde_sub_069a14(a0, a1, a2);
        case 0x069a1cULL: return fde_sub_069a1c(a0, a1, a2);
        case 0x069b94ULL: return fde_sub_069b94(a0, a1, a2);
        case 0x069b9cULL: return fde_sub_069b9c(a0, a1, a2);
        case 0x069d58ULL: return fde_sub_069d58(a0, a1, a2);
        case 0x069d60ULL: return fde_sub_069d60(a0, a1, a2);
        case 0x069ed8ULL: return fde_sub_069ed8(a0, a1, a2);
        case 0x069ee0ULL: return fde_sub_069ee0(a0, a1, a2);
        case 0x06a058ULL: return fde_sub_06a058(a0, a1, a2);
        case 0x06a060ULL: return fde_sub_06a060(a0, a1, a2);
        case 0x06a1d8ULL: return fde_sub_06a1d8(a0, a1, a2);
        case 0x06a1e0ULL: return fde_sub_06a1e0(a0, a1, a2);
        case 0x06a358ULL: return fde_sub_06a358(a0, a1, a2);
        case 0x06a360ULL: return fde_sub_06a360(a0, a1, a2);
        case 0x06a4d8ULL: return fde_sub_06a4d8(a0, a1, a2);
        case 0x06a4e0ULL: return fde_sub_06a4e0(a0, a1, a2);
        case 0x06a658ULL: return fde_sub_06a658(a0, a1, a2);
        case 0x06a660ULL: return fde_sub_06a660(a0, a1, a2);
        case 0x06a7d8ULL: return fde_sub_06a7d8(a0, a1, a2);
        case 0x06a7e0ULL: return fde_sub_06a7e0(a0, a1, a2);
        case 0x06a958ULL: return fde_sub_06a958(a0, a1, a2);
        case 0x06a960ULL: return fde_sub_06a960(a0, a1, a2);
        case 0x06aad8ULL: return fde_sub_06aad8(a0, a1, a2);
        case 0x06ac48ULL: return fde_sub_06ac48(a0, a1, a2);
        case 0x06ac84ULL: return fde_sub_06ac84(a0, a1, a2);
        case 0x06ad54ULL: return fde_sub_06ad54(a0, a1, a2);
        case 0x06af90ULL: return fde_sub_06af90(a0, a1, a2);
        case 0x06b050ULL: return fde_sub_06b050(a0, a1, a2);
        case 0x06b208ULL: return fde_sub_06b208(a0, a1, a2);
        case 0x06b2d8ULL: return fde_sub_06b2d8(a0, a1, a2);
        case 0x06b530ULL: return fde_sub_06b530(a0, a1, a2);
        case 0x06b724ULL: return fde_sub_06b724(a0, a1, a2);
        case 0x06b878ULL: return fde_sub_06b878(a0, a1, a2);
        case 0x06b9ccULL: return fde_sub_06b9cc(a0, a1, a2);
        case 0x06bb7cULL: return fde_sub_06bb7c(a0, a1, a2);
        case 0x06bd30ULL: return fde_sub_06bd30(a0, a1, a2);
        case 0x06bec8ULL: return fde_sub_06bec8(a0, a1, a2);
        case 0x06c004ULL: return fde_sub_06c004(a0, a1, a2);
        case 0x06c144ULL: return fde_sub_06c144(a0, a1, a2);
        case 0x06c2c0ULL: return fde_sub_06c2c0(a0, a1, a2);
        case 0x06c43cULL: return fde_sub_06c43c(a0, a1, a2);
        case 0x06c4ccULL: return fde_sub_06c4cc(a0, a1, a2);
        case 0x06c54cULL: return fde_sub_06c54c(a0, a1, a2);
        case 0x06c554ULL: return fde_sub_06c554(a0, a1, a2);
        case 0x06c560ULL: return fde_sub_06c560(a0, a1, a2);
        case 0x06c578ULL: return fde_sub_06c578(a0, a1, a2);
        case 0x06c5a8ULL: return fde_sub_06c5a8(a0, a1, a2);
        case 0x06c5e0ULL: return fde_sub_06c5e0(a0, a1, a2);
        case 0x06c644ULL: return fde_sub_06c644(a0, a1, a2);
        case 0x06c698ULL: return fde_sub_06c698(a0, a1, a2);
        case 0x06c754ULL: return fde_sub_06c754(a0, a1, a2);
        case 0x06c760ULL: return fde_sub_06c760(a0, a1, a2);
        case 0x06c798ULL: return fde_sub_06c798(a0, a1, a2);
        case 0x06c7d0ULL: return fde_sub_06c7d0(a0, a1, a2);
        case 0x06c9c8ULL: return fde_sub_06c9c8(a0, a1, a2);
        case 0x06c9f8ULL: return fde_sub_06c9f8(a0, a1, a2);
        case 0x06cc10ULL: return fde_sub_06cc10(a0, a1, a2);
        case 0x06ce08ULL: return fde_sub_06ce08(a0, a1, a2);
        case 0x06d020ULL: return fde_sub_06d020(a0, a1, a2);
        case 0x06d218ULL: return fde_sub_06d218(a0, a1, a2);
        case 0x06d410ULL: return fde_sub_06d410(a0, a1, a2);
        case 0x06d608ULL: return fde_sub_06d608(a0, a1, a2);
        case 0x06d800ULL: return fde_sub_06d800(a0, a1, a2);
        case 0x06d9f8ULL: return fde_sub_06d9f8(a0, a1, a2);
        case 0x06dbf0ULL: return fde_sub_06dbf0(a0, a1, a2);
        case 0x06dde8ULL: return fde_sub_06dde8(a0, a1, a2);
        case 0x06dfd8ULL: return fde_sub_06dfd8(a0, a1, a2);
        case 0x06e1d0ULL: return fde_sub_06e1d0(a0, a1, a2);
        case 0x06e434ULL: return fde_sub_06e434(a0, a1, a2);
        case 0x06e464ULL: return fde_sub_06e464(a0, a1, a2);
        case 0x06e5c8ULL: return fde_sub_06e5c8(a0, a1, a2);
        case 0x06e724ULL: return fde_sub_06e724(a0, a1, a2);
        case 0x06e780ULL: return fde_sub_06e780(a0, a1, a2);
        case 0x06e8b0ULL: return fde_sub_06e8b0(a0, a1, a2);
        case 0x06e9e0ULL: return fde_sub_06e9e0(a0, a1, a2);
        case 0x06ea70ULL: return fde_sub_06ea70(a0, a1, a2);
        case 0x06eaf0ULL: return fde_sub_06eaf0(a0, a1, a2);
        case 0x06eaf8ULL: return fde_sub_06eaf8(a0, a1, a2);
        case 0x06eb04ULL: return fde_sub_06eb04(a0, a1, a2);
        case 0x06eb1cULL: return fde_sub_06eb1c(a0, a1, a2);
        case 0x06eb4cULL: return fde_sub_06eb4c(a0, a1, a2);
        case 0x06eb84ULL: return fde_sub_06eb84(a0, a1, a2);
        case 0x06ebe8ULL: return fde_sub_06ebe8(a0, a1, a2);
        case 0x06ec3cULL: return fde_sub_06ec3c(a0, a1, a2);
        case 0x06ecf8ULL: return fde_sub_06ecf8(a0, a1, a2);
        case 0x06ed04ULL: return fde_sub_06ed04(a0, a1, a2);
        case 0x06ed3cULL: return fde_sub_06ed3c(a0, a1, a2);
        case 0x06ed74ULL: return fde_sub_06ed74(a0, a1, a2);
        case 0x06ef6cULL: return fde_sub_06ef6c(a0, a1, a2);
        case 0x06f184ULL: return fde_sub_06f184(a0, a1, a2);
        case 0x06f37cULL: return fde_sub_06f37c(a0, a1, a2);
        case 0x06f594ULL: return fde_sub_06f594(a0, a1, a2);
        case 0x06f78cULL: return fde_sub_06f78c(a0, a1, a2);
        case 0x06f984ULL: return fde_sub_06f984(a0, a1, a2);
        case 0x06fb7cULL: return fde_sub_06fb7c(a0, a1, a2);
        case 0x06fd74ULL: return fde_sub_06fd74(a0, a1, a2);
        case 0x06ff6cULL: return fde_sub_06ff6c(a0, a1, a2);
        case 0x070164ULL: return fde_sub_070164(a0, a1, a2);
        case 0x07035cULL: return fde_sub_07035c(a0, a1, a2);
        case 0x07054cULL: return fde_sub_07054c(a0, a1, a2);
        case 0x070744ULL: return fde_sub_070744(a0, a1, a2);
        case 0x0709b8ULL: return fde_sub_0709b8(a0, a1, a2);
        case 0x070b28ULL: return fde_sub_070b28(a0, a1, a2);
        case 0x070c84ULL: return fde_sub_070c84(a0, a1, a2);
        case 0x070ce0ULL: return fde_sub_070ce0(a0, a1, a2);
        case 0x070e10ULL: return fde_sub_070e10(a0, a1, a2);
        case 0x070f40ULL: return fde_sub_070f40(a0, a1, a2);
        case 0x071018ULL: return fde_sub_071018(a0, a1, a2);
        case 0x0710b8ULL: return fde_sub_0710b8(a0, a1, a2);
        case 0x0710c0ULL: return fde_sub_0710c0(a0, a1, a2);
        case 0x0710ccULL: return fde_sub_0710cc(a0, a1, a2);
        case 0x0710d8ULL: return fde_sub_0710d8(a0, a1, a2);
        case 0x0710f0ULL: return fde_sub_0710f0(a0, a1, a2);
        case 0x071120ULL: return fde_sub_071120(a0, a1, a2);
        case 0x071150ULL: return fde_sub_071150(a0, a1, a2);
        case 0x071188ULL: return fde_sub_071188(a0, a1, a2);
        case 0x0711fcULL: return fde_sub_0711fc(a0, a1, a2);
        case 0x07120cULL: return fde_sub_07120c(a0, a1, a2);
        case 0x07128cULL: return fde_sub_07128c(a0, a1, a2);
        case 0x071318ULL: return fde_sub_071318(a0, a1, a2);
        case 0x071358ULL: return fde_sub_071358(a0, a1, a2);
        default: return 0ULL;
    }
}

} // namespace applovin
