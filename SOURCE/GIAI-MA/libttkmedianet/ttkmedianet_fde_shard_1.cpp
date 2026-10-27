// ============================================================================
// File: ttkmedianet_fde_shard_1.cpp
// Target 106 / 169: libttkmedianet.so (632,064 bytes)
// EN: Clean-room C++17 AArch64 FDE Shard 1/5 covering FDEs [0..328]
//     (PC range 0x00fd20 .. 0x02c844).
// VI: Phân mảnh FDE AArch64 C++17 1/5 bao phủ các FDE [0..328]
//     (Dải địa chỉ PC 0x00fd20 .. 0x02c844).
// ============================================================================
#include "ttkmedianet_core.h"

namespace TTKMediaNet {

// FDE #0000 | PC: 0x00fd20..0x00fd40 (32 B) | Symbol: sub_00fd20
// EN: AArch64 prologue [adrp x1, #0x9d000; adrp x0, #0x1d000; adrp x2, #0x99000; add x1, x1, #0xd80] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x9d000; adrp x0, #0x1d000; adrp x2, #0x99000; add x1, x1, #0xd80]
uint64_t fde_sub_00fd20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000060ULL) << 32) | 0xD0000461ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00FD20ULL;
}

// FDE #0001 | PC: 0x00fd7c..0x00fe8c (272 B) | Symbol: sub_00fd7c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_00fd7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0110ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00FD7CULL;
}

// FDE #0002 | PC: 0x00fe8c..0x00ff18 (140 B) | Symbol: sub_00fe8c
// EN: AArch64 prologue [cbz x0, #0xfef0; stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10] | VI: Khởi đầu hàm AArch64 [cbz x0, #0xfef0; stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10]
uint64_t fde_sub_00fe8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE4FF4ULL) << 32) | 0xB4000320ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00FE8CULL;
}

// FDE #0003 | PC: 0x00ff18..0x0101d8 (704 B) | Symbol: sub_00ff18
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]]
uint64_t fde_sub_00ff18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9056FFCULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x02C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x00FF18ULL;
}

// FDE #0004 | PC: 0x0101d8..0x0102cc (244 B) | Symbol: sub_0101d8
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0101d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x00F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0101D8ULL;
}

// FDE #0005 | PC: 0x0102cc..0x010398 (204 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0102cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0102CCULL;
}

// FDE #0006 | PC: 0x010398..0x0104f8 (352 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE21__grow_by_and_replaceEmmmmmmPKc
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_010398(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0160ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x010398ULL;
}

// FDE #0007 | PC: 0x0104f8..0x010a8c (1428 B) | Symbol: sub_0104f8
// EN: AArch64 prologue [sub sp, sp, #0xd0; str x27, [sp, #0x70]; stp x26, x25, [sp, #0x80]; stp x24, x23, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xd0; str x27, [sp, #0x70]; stp x26, x25, [sp, #0x80]; stp x24, x23, [sp, #0x90]]
uint64_t fde_sub_0104f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9003BFBULL) << 32) | 0xD10343FFULL;
    const uint64_t kPcRange = 0x0594ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0104F8ULL;
}

// FDE #0008 | PC: 0x010a8c..0x010d18 (652 B) | Symbol: sub_010a8c
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_010a8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x028CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x010A8CULL;
}

// FDE #0009 | PC: 0x010d18..0x010f6c (596 B) | Symbol: sub_010d18
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_010d18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x0254ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x010D18ULL;
}

// FDE #0010 | PC: 0x010f6c..0x011118 (428 B) | Symbol: sub_010f6c
// EN: AArch64 prologue [cmp x1, x0; cset w8, eq; strb w8, [x1, #0x18]; b.eq #0x11034] | VI: Khởi đầu hàm AArch64 [cmp x1, x0; cset w8, eq; strb w8, [x1, #0x18]; b.eq #0x11034]
uint64_t fde_sub_010f6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1A9F17E8ULL) << 32) | 0xEB00003FULL;
    const uint64_t kPcRange = 0x01ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x010F6CULL;
}

// FDE #0011 | PC: 0x011118..0x011220 (264 B) | Symbol: sub_011118
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_011118(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0108ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x011118ULL;
}

// FDE #0012 | PC: 0x011220..0x011450 (560 B) | Symbol: sub_011220
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_011220(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0230ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x011220ULL;
}

// FDE #0013 | PC: 0x011450..0x011aa0 (1616 B) | Symbol: sub_011450
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]]
uint64_t fde_sub_011450(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9056FFCULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x0650ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x011450ULL;
}

// FDE #0014 | PC: 0x011aa0..0x011e70 (976 B) | Symbol: sub_011aa0
// EN: AArch64 prologue [ldr x9, [x1]; mov x10, x1; cbz x9, #0x11ac0; ldr x8, [x1, #8]] | VI: Khởi đầu hàm AArch64 [ldr x9, [x1]; mov x10, x1; cbz x9, #0x11ac0; ldr x8, [x1, #8]]
uint64_t fde_sub_011aa0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103EAULL) << 32) | 0xF9400029ULL;
    const uint64_t kPcRange = 0x03D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x011AA0ULL;
}

// FDE #0015 | PC: 0x011e70..0x011f60 (240 B) | Symbol: sub_011e70
// EN: AArch64 prologue [sub sp, sp, #0x80; str x21, [sp, #0x50]; stp x20, x19, [sp, #0x60]; stp x29, x30, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x21, [sp, #0x50]; stp x20, x19, [sp, #0x60]; stp x29, x30, [sp, #0x70]]
uint64_t fde_sub_011e70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9002BF5ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x00F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x011E70ULL;
}

// FDE #0016 | PC: 0x011f60..0x0122c8 (872 B) | Symbol: sub_011f60
// EN: AArch64 prologue [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_011f60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F9ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0368ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x011F60ULL;
}

// FDE #0017 | PC: 0x0122c8..0x01236c (164 B) | Symbol: sub_0122c8
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0122c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0122C8ULL;
}

// FDE #0018 | PC: 0x01236c..0x012408 (156 B) | Symbol: sub_01236c
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_01236c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01236CULL;
}

// FDE #0019 | PC: 0x012408..0x01240c (4 B) | Symbol: sub_012408
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_012408(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x012408ULL;
}

// FDE #0020 | PC: 0x01240c..0x012410 (4 B) | Symbol: sub_01240c
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_01240c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01240CULL;
}

// FDE #0021 | PC: 0x012410..0x012414 (4 B) | Symbol: sub_012410
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_012410(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10303FFULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x012410ULL;
}

// FDE #0022 | PC: 0x012414..0x012768 (852 B) | Symbol: sub_012414
// EN: AArch64 prologue [sub sp, sp, #0xc0; str x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; str x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]]
uint64_t fde_sub_012414(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9003BF9ULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x0354ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x012414ULL;
}

// FDE #0023 | PC: 0x012768..0x012c54 (1260 B) | Symbol: sub_012768
// EN: AArch64 prologue [sub sp, sp, #0x80; str x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_012768(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013FBULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x04ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x012768ULL;
}

// FDE #0024 | PC: 0x012c54..0x012d98 (324 B) | Symbol: sub_012c54
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_012c54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x0144ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x012C54ULL;
}

// FDE #0025 | PC: 0x012d98..0x012d9c (4 B) | Symbol: sub_012d98
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_012d98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFEF71ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x012D98ULL;
}

// FDE #0026 | PC: 0x012d9c..0x012da0 (4 B) | Symbol: sub_012d9c
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_012d9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000428ULL) << 32) | 0x17FFEF71ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x012D9CULL;
}

// FDE #0027 | PC: 0x012da0..0x012dc0 (32 B) | Symbol: sub_012da0
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0x558; str x8, [x1]; ldur q0, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0x558; str x8, [x1]; ldur q0, [x0, #0x18]]
uint64_t fde_sub_012da0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91156108ULL) << 32) | 0xF0000428ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x012DA0ULL;
}

// FDE #0028 | PC: 0x012dc0..0x012dc4 (4 B) | Symbol: sub_012dc0
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_012dc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFEF67ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x012DC0ULL;
}

// FDE #0029 | PC: 0x012dc4..0x012dc8 (4 B) | Symbol: sub_012dc4
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_012dc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE4FF4ULL) << 32) | 0x17FFEF67ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x012DC4ULL;
}

// FDE #0030 | PC: 0x012dc8..0x012f8c (452 B) | Symbol: sub_012dc8
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldp x8, x20, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldp x8, x20, [x0, #0x10]]
uint64_t fde_sub_012dc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x01C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x012DC8ULL;
}

// FDE #0031 | PC: 0x012f8c..0x0140b0 (4388 B) | Symbol: sub_012f8c
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_012f8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1124ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x012F8CULL;
}

// FDE #0032 | PC: 0x0140b0..0x01451c (1132 B) | Symbol: sub_0140b0
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_0140b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9016FFCULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x046CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0140B0ULL;
}

// FDE #0033 | PC: 0x01451c..0x01458c (112 B) | Symbol: sub_01451c
// EN: AArch64 prologue [cbz x0, #0x14560; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x14560; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10]
uint64_t fde_sub_01451c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0xB4000220ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01451CULL;
}

// FDE #0034 | PC: 0x01458c..0x0147bc (560 B) | Symbol: sub_01458c
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_01458c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0230ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01458CULL;
}

// FDE #0035 | PC: 0x0147bc..0x0147cc (16 B) | Symbol: sub_0147bc
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0x5d0; str x8, [x0], #8; b #0x149f8] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0x5d0; str x8, [x0], #8; b #0x149f8]
uint64_t fde_sub_0147bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91174108ULL) << 32) | 0xB0000428ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0147BCULL;
}

// FDE #0036 | PC: 0x0147cc..0x0147fc (48 B) | Symbol: sub_0147cc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x99000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x99000]
uint64_t fde_sub_0147cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0147CCULL;
}

// FDE #0037 | PC: 0x0147fc..0x0148e4 (232 B) | Symbol: sub_0147fc
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0x5d0; str x8, [x1]; ldur q0, [x0, #8]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0x5d0; str x8, [x1]; ldur q0, [x0, #8]]
uint64_t fde_sub_0147fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91174108ULL) << 32) | 0xB0000428ULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0147FCULL;
}

// FDE #0038 | PC: 0x0148e4..0x0148ec (8 B) | Symbol: sub_0148e4
// EN: AArch64 prologue [add x0, x0, #8; b #0x149f8] | VI: Khởi đầu hàm AArch64 [add x0, x0, #8; b #0x149f8]
uint64_t fde_sub_0148e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000044ULL) << 32) | 0x91002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0148E4ULL;
}

// FDE #0039 | PC: 0x0148ec..0x014914 (40 B) | Symbol: sub_0148ec
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0148ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0148ECULL;
}

// FDE #0040 | PC: 0x014914..0x0149f8 (228 B) | Symbol: sub_014914
// EN: AArch64 prologue [sub sp, sp, #0xf0; stp x22, x21, [sp, #0xc0]; stp x20, x19, [sp, #0xd0]; stp x29, x30, [sp, #0xe0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xf0; stp x22, x21, [sp, #0xc0]; stp x20, x19, [sp, #0xd0]; stp x29, x30, [sp, #0xe0]]
uint64_t fde_sub_014914(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90C57F6ULL) << 32) | 0xD103C3FFULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x014914ULL;
}

// FDE #0041 | PC: 0x0149f8..0x014ac0 (200 B) | Symbol: sub_0149f8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0149f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0149F8ULL;
}

// FDE #0042 | PC: 0x014ac0..0x014c00 (320 B) | Symbol: sub_014ac0
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_014ac0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0140ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x014AC0ULL;
}

// FDE #0043 | PC: 0x014c00..0x014d20 (288 B) | Symbol: sub_014c00
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_014c00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0120ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x014C00ULL;
}

// FDE #0044 | PC: 0x014d20..0x014d50 (48 B) | Symbol: sub_014d20
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x99000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x99000]
uint64_t fde_sub_014d20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x014D20ULL;
}

// FDE #0045 | PC: 0x014d50..0x014d88 (56 B) | Symbol: sub_014d50
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x99000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x99000]
uint64_t fde_sub_014d50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x014D50ULL;
}

// FDE #0046 | PC: 0x014d88..0x014d94 (12 B) | Symbol: sub_014d88
// EN: AArch64 prologue [ldr x8, [x0, #0x18]!; ldr x1, [x8]; br x1] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x18]!; ldr x1, [x8]; br x1]
uint64_t fde_sub_014d88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400101ULL) << 32) | 0xF8418C08ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x014D88ULL;
}

// FDE #0047 | PC: 0x014d94..0x014d98 (4 B) | Symbol: sub_014d94
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_014d94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC5FF8ULL) << 32) | 0x17FFE773ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x014D94ULL;
}

// FDE #0048 | PC: 0x014d98..0x015078 (736 B) | Symbol: sub_014d98
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_014d98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x02E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x014D98ULL;
}

// FDE #0049 | PC: 0x015078..0x015320 (680 B) | Symbol: sub_015078
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_015078(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9026FFCULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x02A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x015078ULL;
}

// FDE #0050 | PC: 0x015320..0x01552c (524 B) | Symbol: sub_015320
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_015320(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x020CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x015320ULL;
}

// FDE #0051 | PC: 0x01552c..0x0156e0 (436 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEb
// EN: AArch64 prologue [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_01552c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF9ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x01B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01552CULL;
}

// FDE #0052 | PC: 0x0156e0..0x0158b4 (468 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEi
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0156e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x01D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0156E0ULL;
}

// FDE #0053 | PC: 0x0158b4..0x015a68 (436 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEj
// EN: AArch64 prologue [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0158b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF9ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x01B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0158B4ULL;
}

// FDE #0054 | PC: 0x015a68..0x015c1c (436 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEl
// EN: AArch64 prologue [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_015a68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF9ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x01B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x015A68ULL;
}

// FDE #0055 | PC: 0x015c1c..0x015dd0 (436 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEm
// EN: AArch64 prologue [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_015c1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF9ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x01B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x015C1CULL;
}

// FDE #0056 | PC: 0x015dd0..0x015ec0 (240 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE5flushEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_015dd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x00F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x015DD0ULL;
}

// FDE #0057 | PC: 0x015ec0..0x015f10 (80 B) | Symbol: sub_015ec0
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0x9b000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0x9b000]
uint64_t fde_sub_015ec0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x015EC0ULL;
}

// FDE #0058 | PC: 0x015f10..0x015f68 (88 B) | Symbol: sub_015f10
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0x9b000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0x9b000]
uint64_t fde_sub_015f10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x015F10ULL;
}

// FDE #0059 | PC: 0x015f68..0x015f6c (4 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE5imbueERKNS_6localeE
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_015f68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x015F68ULL;
}

// FDE #0060 | PC: 0x015f6c..0x015f70 (4 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE6setbufEPcl
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_015f6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402C08ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x015F6CULL;
}

// FDE #0061 | PC: 0x015f70..0x016098 (296 B) | Symbol: sub_015f70
// EN: AArch64 prologue [ldr x8, [x0, #0x58]; ldr x9, [x0, #0x30]; cmp x8, x9; b.hs #0x15f88] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x58]; ldr x9, [x0, #0x30]; cmp x8, x9; b.hs #0x15f88]
uint64_t fde_sub_015f70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401809ULL) << 32) | 0xF9402C08ULL;
    const uint64_t kPcRange = 0x0128ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x015F70ULL;
}

// FDE #0062 | PC: 0x016098..0x0160ac (20 B) | Symbol: sub_016098
// EN: AArch64 prologue [ldr x8, [x0]; mov x1, x2; mov w2, wzr; ldr x4, [x8, #0x20]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; mov x1, x2; mov w2, wzr; ldr x4, [x8, #0x20]]
uint64_t fde_sub_016098(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0203E1ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016098ULL;
}

// FDE #0063 | PC: 0x0160ac..0x0160b4 (8 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE4syncEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_0160ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0160ACULL;
}

// FDE #0064 | PC: 0x0160b4..0x0160bc (8 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE9showmanycEv
// EN: AArch64 prologue [mov x0, xzr; ret] | VI: Khởi đầu hàm AArch64 [mov x0, xzr; ret]
uint64_t fde_sub_0160b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xAA1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0160B4ULL;
}

// FDE #0065 | PC: 0x0160bc..0x01619c (224 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE6xsgetnEPcl
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0160bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0160BCULL;
}

// FDE #0066 | PC: 0x01619c..0x0161ec (80 B) | Symbol: sub_01619c
// EN: AArch64 prologue [ldr x8, [x0, #0x58]; ldr x9, [x0, #0x30]; cmp x8, x9; b.hs #0x161b4] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x58]; ldr x9, [x0, #0x30]; cmp x8, x9; b.hs #0x161b4]
uint64_t fde_sub_01619c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401809ULL) << 32) | 0xF9402C08ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01619CULL;
}

// FDE #0067 | PC: 0x0161ec..0x01622c (64 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE5uflowEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_0161ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0161ECULL;
}

// FDE #0068 | PC: 0x01622c..0x01629c (112 B) | Symbol: sub_01622c
// EN: AArch64 prologue [ldr x9, [x0, #0x58]; ldr x10, [x0, #0x30]; mov x8, x0; mov w0, w1] | VI: Khởi đầu hàm AArch64 [ldr x9, [x0, #0x58]; ldr x10, [x0, #0x30]; mov x8, x0; mov w0, w1]
uint64_t fde_sub_01622c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF940180AULL) << 32) | 0xF9402C09ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01622CULL;
}

// FDE #0069 | PC: 0x01629c..0x016370 (212 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE6xsputnEPKcl
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_01629c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01629CULL;
}

// FDE #0070 | PC: 0x016370..0x0165b8 (584 B) | Symbol: sub_016370
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_016370(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x0248ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016370ULL;
}

// FDE #0071 | PC: 0x0165b8..0x0166f8 (320 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9__grow_byEmmmmmm
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0165b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x0140ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0165B8ULL;
}

// FDE #0072 | PC: 0x0166f8..0x0167d0 (216 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEmc
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0166f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0166F8ULL;
}

// FDE #0073 | PC: 0x0167d0..0x0167e4 (20 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev
// EN: AArch64 prologue [adrp x8, #0x9b000; ldr x8, [x8, #0xdf0]; add x8, x8, #0x10; str x8, [x0], #8] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9b000; ldr x8, [x8, #0xdf0]; add x8, x8, #0x10; str x8, [x0], #8]
uint64_t fde_sub_0167d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF946F908ULL) << 32) | 0xB0000428ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0167D0ULL;
}

// FDE #0074 | PC: 0x0167e4..0x016818 (52 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9b000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9b000]
uint64_t fde_sub_0167e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0167E4ULL;
}

// FDE #0075 | PC: 0x016818..0x016824 (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE7seekoffExNS_8ios_base7seekdirEj
// EN: AArch64 prologue [mov x1, #-1; mov x0, xzr; ret] | VI: Khởi đầu hàm AArch64 [mov x1, #-1; mov x0, xzr; ret]
uint64_t fde_sub_016818(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E0ULL) << 32) | 0x92800001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016818ULL;
}

// FDE #0076 | PC: 0x016824..0x016830 (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE7seekposENS_4fposI9mbstate_tEEj
// EN: AArch64 prologue [mov x1, #-1; mov x0, xzr; ret] | VI: Khởi đầu hàm AArch64 [mov x1, #-1; mov x0, xzr; ret]
uint64_t fde_sub_016824(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E0ULL) << 32) | 0x92800001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016824ULL;
}

// FDE #0077 | PC: 0x016830..0x016838 (8 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE9underflowEv
// EN: AArch64 prologue [mov w0, #-1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #-1; ret]
uint64_t fde_sub_016830(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x12800000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016830ULL;
}

// FDE #0078 | PC: 0x016838..0x016840 (8 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE9pbackfailEi
// EN: AArch64 prologue [mov w0, #-1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #-1; ret]
uint64_t fde_sub_016838(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x12800000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016838ULL;
}

// FDE #0079 | PC: 0x016840..0x016848 (8 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE8overflowEi
// EN: AArch64 prologue [mov w0, #-1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #-1; ret]
uint64_t fde_sub_016840(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x12800000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016840ULL;
}

// FDE #0080 | PC: 0x016848..0x0168b4 (108 B) | Symbol: sub_016848
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9b000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9b000]
uint64_t fde_sub_016848(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016848ULL;
}

// FDE #0081 | PC: 0x0168b4..0x016928 (116 B) | Symbol: sub_0168b4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9b000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9b000]
uint64_t fde_sub_0168b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0168B4ULL;
}

// FDE #0082 | PC: 0x016928..0x0169a4 (124 B) | Symbol: sub_016928
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_016928(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016928ULL;
}

// FDE #0083 | PC: 0x0169a4..0x016a28 (132 B) | Symbol: sub_0169a4
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_0169a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0169A4ULL;
}

// FDE #0084 | PC: 0x016a28..0x016a30 (8 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED1Ev
// EN: AArch64 prologue [add x0, x0, #8; b #0xec20] | VI: Khởi đầu hàm AArch64 [add x0, x0, #8; b #0xec20]
uint64_t fde_sub_016a28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFE07DULL) << 32) | 0x91002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016A28ULL;
}

// FDE #0085 | PC: 0x016a30..0x016a58 (40 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_016a30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016A30ULL;
}

// FDE #0086 | PC: 0x016a58..0x016a6c (20 B) | Symbol: _ZTv0_n24_NSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED1Ev
// EN: AArch64 prologue [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x8, x0, x8; add x0, x8, #8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x8, x0, x8; add x0, x8, #8]
uint64_t fde_sub_016a58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF85E8108ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016A58ULL;
}

// FDE #0087 | PC: 0x016a6c..0x016a9c (48 B) | Symbol: _ZTv0_n24_NSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_016a6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016A6CULL;
}

// FDE #0088 | PC: 0x016a9c..0x016acc (48 B) | Symbol: sub_016a9c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x99000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x99000]
uint64_t fde_sub_016a9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016A9CULL;
}

// FDE #0089 | PC: 0x016acc..0x016b04 (56 B) | Symbol: sub_016acc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x99000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x99000]
uint64_t fde_sub_016acc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016ACCULL;
}

// FDE #0090 | PC: 0x016b04..0x016b10 (12 B) | Symbol: sub_016b04
// EN: AArch64 prologue [ldr x8, [x0, #0x18]!; ldr x1, [x8]; br x1] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x18]!; ldr x1, [x8]; br x1]
uint64_t fde_sub_016b04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400101ULL) << 32) | 0xF8418C08ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016B04ULL;
}

// FDE #0091 | PC: 0x016b10..0x016b14 (4 B) | Symbol: sub_016b10
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_016b10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD57F6ULL) << 32) | 0x17FFE014ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016B10ULL;
}

// FDE #0092 | PC: 0x016b14..0x016be4 (208 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_016b14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016B14ULL;
}

// FDE #0093 | PC: 0x016be4..0x016ca0 (188 B) | Symbol: sub_016be4
// EN: AArch64 prologue [cbz x0, #0x16c6c; stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x16c6c; stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]]
uint64_t fde_sub_016be4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD57F6ULL) << 32) | 0xB4000440ULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016BE4ULL;
}

// FDE #0094 | PC: 0x016ca0..0x016db4 (276 B) | Symbol: sub_016ca0
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_016ca0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016CA0ULL;
}

// FDE #0095 | PC: 0x016db4..0x017650 (2204 B) | Symbol: sub_016db4
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_016db4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x089CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x016DB4ULL;
}

// FDE #0096 | PC: 0x017650..0x01772c (220 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_017650(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x017650ULL;
}

// FDE #0097 | PC: 0x01772c..0x01787c (336 B) | Symbol: sub_01772c
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_01772c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0150ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01772CULL;
}

// FDE #0098 | PC: 0x01787c..0x017f10 (1684 B) | Symbol: sub_01787c
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_01787c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0694ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01787CULL;
}

// FDE #0099 | PC: 0x017f10..0x017fd0 (192 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_mmRKS4_
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_017f10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x017F10ULL;
}

// FDE #0100 | PC: 0x017fd0..0x01828c (700 B) | Symbol: sub_017fd0
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_017fd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x02BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x017FD0ULL;
}

// FDE #0101 | PC: 0x01828c..0x018400 (372 B) | Symbol: sub_01828c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_01828c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0174ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01828CULL;
}

// FDE #0102 | PC: 0x018400..0x018574 (372 B) | Symbol: sub_018400
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_018400(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0174ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x018400ULL;
}

// FDE #0103 | PC: 0x018574..0x0185e4 (112 B) | Symbol: sub_018574
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9b000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9b000]
uint64_t fde_sub_018574(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x018574ULL;
}

// FDE #0104 | PC: 0x0185e4..0x01865c (120 B) | Symbol: sub_0185e4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9b000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9b000]
uint64_t fde_sub_0185e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0185E4ULL;
}

// FDE #0105 | PC: 0x01865c..0x0186d8 (124 B) | Symbol: sub_01865c
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_01865c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01865CULL;
}

// FDE #0106 | PC: 0x0186d8..0x01875c (132 B) | Symbol: sub_0186d8
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_0186d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0186D8ULL;
}

// FDE #0107 | PC: 0x01875c..0x018764 (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED1Ev
// EN: AArch64 prologue [add x0, x0, #0x10; b #0xec20] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x10; b #0xec20]
uint64_t fde_sub_01875c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFD930ULL) << 32) | 0x91004000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01875CULL;
}

// FDE #0108 | PC: 0x018764..0x01878c (40 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_018764(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x018764ULL;
}

// FDE #0109 | PC: 0x01878c..0x0187a0 (20 B) | Symbol: _ZTv0_n24_NSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED1Ev
// EN: AArch64 prologue [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x8, x0, x8; add x0, x8, #0x10] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x8, x0, x8; add x0, x8, #0x10]
uint64_t fde_sub_01878c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF85E8108ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01878CULL;
}

// FDE #0110 | PC: 0x0187a0..0x0187d0 (48 B) | Symbol: _ZTv0_n24_NSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_0187a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0187A0ULL;
}

// FDE #0111 | PC: 0x0187d0..0x0189bc (492 B) | Symbol: sub_0187d0
// EN: AArch64 prologue [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0187d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x01ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0187D0ULL;
}

// FDE #0112 | PC: 0x0189bc..0x0189e0 (36 B) | Symbol: sub_0189bc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0189bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0189BCULL;
}

// FDE #0113 | PC: 0x0189e0..0x018a5c (124 B) | Symbol: sub_0189e0
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0]
uint64_t fde_sub_0189e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0189E0ULL;
}

// FDE #0114 | PC: 0x018a5c..0x018aec (144 B) | Symbol: sub_018a5c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_018a5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x018A5CULL;
}

// FDE #0115 | PC: 0x018aec..0x018b6c (128 B) | Symbol: sub_018aec
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0]
uint64_t fde_sub_018aec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x018AECULL;
}

// FDE #0116 | PC: 0x018b6c..0x018d54 (488 B) | Symbol: sub_018b6c
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_018b6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x01E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x018B6CULL;
}

// FDE #0117 | PC: 0x018d54..0x019338 (1508 B) | Symbol: sub_018d54
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]; stp x20, x19, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]; stp x20, x19, [sp, #0x60]]
uint64_t fde_sub_018d54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9045FF8ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x05E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x018D54ULL;
}

// FDE #0118 | PC: 0x019338..0x0194bc (388 B) | Symbol: sub_019338
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_019338(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90257F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0184ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x019338ULL;
}

// FDE #0119 | PC: 0x0194bc..0x01c23c (11648 B) | Symbol: sub_0194bc
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0194bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x2D80ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0194BCULL;
}

// FDE #0120 | PC: 0x01c23c..0x01c784 (1352 B) | Symbol: sub_01c23c
// EN: AArch64 prologue [sub sp, sp, #0xe0; str x25, [sp, #0x90]; stp x24, x23, [sp, #0xa0]; stp x22, x21, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xe0; str x25, [sp, #0x90]; stp x24, x23, [sp, #0xa0]; stp x22, x21, [sp, #0xb0]]
uint64_t fde_sub_01c23c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9004BF9ULL) << 32) | 0xD10383FFULL;
    const uint64_t kPcRange = 0x0548ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01C23CULL;
}

// FDE #0121 | PC: 0x01c784..0x01c790 (12 B) | Symbol: sub_01c784
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xf700] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xf700]
uint64_t fde_sub_01c784(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01C784ULL;
}

// FDE #0122 | PC: 0x01c790..0x01caf4 (868 B) | Symbol: sub_01c790
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_01c790(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0364ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01C790ULL;
}

// FDE #0123 | PC: 0x01caf4..0x01cd24 (560 B) | Symbol: sub_01caf4
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_01caf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0230ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CAF4ULL;
}

// FDE #0124 | PC: 0x01cd24..0x01cda0 (124 B) | Symbol: sub_01cd24
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_01cd24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CD24ULL;
}

// FDE #0125 | PC: 0x01cda0..0x01ce24 (132 B) | Symbol: sub_01cda0
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_01cda0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CDA0ULL;
}

// FDE #0126 | PC: 0x01ce24..0x01ce98 (116 B) | Symbol: sub_01ce24
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_01ce24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CE24ULL;
}

// FDE #0127 | PC: 0x01ce98..0x01ce9c (4 B) | Symbol: sub_01ce98
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_01ce98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFC731ULL) << 32) | 0x17FFC732ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CE98ULL;
}

// FDE #0128 | PC: 0x01ce9c..0x01cea0 (4 B) | Symbol: sub_01ce9c
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_01ce9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00003E8ULL) << 32) | 0x17FFC731ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CE9CULL;
}

// FDE #0129 | PC: 0x01cea0..0x01ceb8 (24 B) | Symbol: sub_01cea0
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0x900; str x8, [x1]; ldur q0, [x0, #8]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0x900; str x8, [x1]; ldur q0, [x0, #8]]
uint64_t fde_sub_01cea0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91240108ULL) << 32) | 0xB00003E8ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CEA0ULL;
}

// FDE #0130 | PC: 0x01ceb8..0x01cebc (4 B) | Symbol: sub_01ceb8
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_01ceb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFC729ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CEB8ULL;
}

// FDE #0131 | PC: 0x01cebc..0x01cec0 (4 B) | Symbol: sub_01cebc
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_01cebc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9408001ULL) << 32) | 0x17FFC729ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CEBCULL;
}

// FDE #0132 | PC: 0x01cec0..0x01cec8 (8 B) | Symbol: sub_01cec0
// EN: AArch64 prologue [ldp x1, x0, [x0, #8]; br x1] | VI: Khởi đầu hàm AArch64 [ldp x1, x0, [x0, #8]; br x1]
uint64_t fde_sub_01cec0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD61F0020ULL) << 32) | 0xA9408001ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CEC0ULL;
}

// FDE #0133 | PC: 0x01cec8..0x01cef8 (48 B) | Symbol: sub_01cec8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x99000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x99000]
uint64_t fde_sub_01cec8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CEC8ULL;
}

// FDE #0134 | PC: 0x01cef8..0x01cf30 (56 B) | Symbol: sub_01cef8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x99000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x99000]
uint64_t fde_sub_01cef8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CEF8ULL;
}

// FDE #0135 | PC: 0x01cf30..0x01cf38 (8 B) | Symbol: sub_01cf30
// EN: AArch64 prologue [add x0, x0, #0x18; b #0x1cf3c] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x18; b #0x1cf3c]
uint64_t fde_sub_01cf30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000002ULL) << 32) | 0x91006000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CF30ULL;
}

// FDE #0136 | PC: 0x01cf38..0x01cf3c (4 B) | Symbol: sub_01cf38
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_01cf38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FFC70AULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CF38ULL;
}

// FDE #0137 | PC: 0x01cf3c..0x01d0fc (448 B) | Symbol: sub_01cf3c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_01cf3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x01C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CF3CULL;
}

// FDE #0138 | PC: 0x01d0fc..0x01d2c0 (452 B) | Symbol: sub_01d0fc
// EN: AArch64 prologue [sub sp, sp, #0x60; str x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_01d0fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x01C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01D0FCULL;
}

// FDE #0139 | PC: 0x01d2c0..0x01d624 (868 B) | Symbol: sub_01d2c0
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_01d2c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0364ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01D2C0ULL;
}

// FDE #0140 | PC: 0x01d624..0x01d854 (560 B) | Symbol: sub_01d624
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_01d624(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0230ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01D624ULL;
}

// FDE #0141 | PC: 0x01d854..0x01d8d0 (124 B) | Symbol: sub_01d854
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_01d854(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01D854ULL;
}

// FDE #0142 | PC: 0x01d8d0..0x01d954 (132 B) | Symbol: sub_01d8d0
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_01d8d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01D8D0ULL;
}

// FDE #0143 | PC: 0x01d954..0x01d9c8 (116 B) | Symbol: sub_01d954
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_01d954(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01D954ULL;
}

// FDE #0144 | PC: 0x01d9c8..0x01d9cc (4 B) | Symbol: sub_01d9c8
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_01d9c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0x17FFC466ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01D9C8ULL;
}

// FDE #0145 | PC: 0x01d9cc..0x01da30 (100 B) | Symbol: sub_01d9cc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #0x18]]
uint64_t fde_sub_01d9cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01D9CCULL;
}

// FDE #0146 | PC: 0x01da30..0x01daa4 (116 B) | Symbol: sub_01da30
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0, #0x18]]
uint64_t fde_sub_01da30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01DA30ULL;
}

// FDE #0147 | PC: 0x01daa4..0x01dac8 (36 B) | Symbol: sub_01daa4
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0x978; str x8, [x1]; ldur q0, [x0, #8]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0x978; str x8, [x1]; ldur q0, [x0, #8]]
uint64_t fde_sub_01daa4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9125E108ULL) << 32) | 0x900003E8ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01DAA4ULL;
}

// FDE #0148 | PC: 0x01dac8..0x01db20 (88 B) | Symbol: sub_01dac8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #0x18]]
uint64_t fde_sub_01dac8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01DAC8ULL;
}

// FDE #0149 | PC: 0x01db20..0x01db88 (104 B) | Symbol: sub_01db20
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0, #0x18]]
uint64_t fde_sub_01db20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01DB20ULL;
}

// FDE #0150 | PC: 0x01db88..0x01dc04 (124 B) | Symbol: sub_01db88
// EN: AArch64 prologue [sub sp, sp, #0x40; str x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30]
uint64_t fde_sub_01db88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F3ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01DB88ULL;
}

// FDE #0151 | PC: 0x01dc04..0x01dd18 (276 B) | Symbol: sub_01dc04
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_01dc04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01DC04ULL;
}

// FDE #0152 | PC: 0x01dd18..0x01dd48 (48 B) | Symbol: sub_01dd18
// EN: AArch64 prologue [mov x8, x0; ldr x0, [x0, #0x20]; cmp x8, x0; b.eq #0x1dd38] | VI: Khởi đầu hàm AArch64 [mov x8, x0; ldr x0, [x0, #0x20]; cmp x8, x0; b.eq #0x1dd38]
uint64_t fde_sub_01dd18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401000ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01DD18ULL;
}

// FDE #0153 | PC: 0x01dd48..0x01dd8c (68 B) | Symbol: sub_01dd48
// EN: AArch64 prologue [cbz x0, #0x1dd88; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x1dd88; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10]
uint64_t fde_sub_01dd48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0xB4000200ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01DD48ULL;
}

// FDE #0154 | PC: 0x01dd8c..0x01defc (368 B) | Symbol: sub_01dd8c
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_01dd8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01DD8CULL;
}

// FDE #0155 | PC: 0x01defc..0x01e024 (296 B) | Symbol: sub_01defc
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_01defc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0128ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01DEFCULL;
}

// FDE #0156 | PC: 0x01e024..0x01e12c (264 B) | Symbol: sub_01e024
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_01e024(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0108ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01E024ULL;
}

// FDE #0157 | PC: 0x01e12c..0x01e934 (2056 B) | Symbol: sub_01e12c
// EN: AArch64 prologue [sub sp, sp, #0x120; stp x28, x27, [sp, #0xc0]; stp x26, x25, [sp, #0xd0]; stp x24, x23, [sp, #0xe0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; stp x28, x27, [sp, #0xc0]; stp x26, x25, [sp, #0xd0]; stp x24, x23, [sp, #0xe0]]
uint64_t fde_sub_01e12c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90C6FFCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x0808ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01E12CULL;
}

// FDE #0158 | PC: 0x01e934..0x01eb50 (540 B) | Symbol: sub_01e934
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]]
uint64_t fde_sub_01e934(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90367FAULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x021CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01E934ULL;
}

// FDE #0159 | PC: 0x01eb50..0x01f244 (1780 B) | Symbol: sub_01eb50
// EN: AArch64 prologue [sub sp, sp, #0xe0; stp x26, x25, [sp, #0x90]; stp x24, x23, [sp, #0xa0]; stp x22, x21, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xe0; stp x26, x25, [sp, #0x90]; stp x24, x23, [sp, #0xa0]; stp x22, x21, [sp, #0xb0]]
uint64_t fde_sub_01eb50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90967FAULL) << 32) | 0xD10383FFULL;
    const uint64_t kPcRange = 0x06F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01EB50ULL;
}

// FDE #0160 | PC: 0x01f244..0x01f248 (4 B) | Symbol: sub_01f244
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_01f244(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00003C8ULL) << 32) | 0x17FFBE47ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01F244ULL;
}

// FDE #0161 | PC: 0x01f248..0x01f268 (32 B) | Symbol: sub_01f248
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0x9f0; str x8, [x1]; ldr x8, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0x9f0; str x8, [x1]; ldr x8, [x0, #0x18]]
uint64_t fde_sub_01f248(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9127C108ULL) << 32) | 0xD00003C8ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01F248ULL;
}

// FDE #0162 | PC: 0x01f268..0x01f26c (4 B) | Symbol: sub_01f268
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_01f268(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFBE3DULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01F268ULL;
}

// FDE #0163 | PC: 0x01f26c..0x01f270 (4 B) | Symbol: sub_01f26c
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_01f26c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA940A002ULL) << 32) | 0x17FFBE3DULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01F26CULL;
}

// FDE #0164 | PC: 0x01f270..0x01f280 (16 B) | Symbol: sub_01f270
// EN: AArch64 prologue [ldp x2, x8, [x0, #8]; ldr x1, [x0, #0x18]; mov x0, x8; br x2] | VI: Khởi đầu hàm AArch64 [ldp x2, x8, [x0, #8]; ldr x1, [x0, #0x18]; mov x0, x8; br x2]
uint64_t fde_sub_01f270(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400C01ULL) << 32) | 0xA940A002ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01F270ULL;
}

// FDE #0165 | PC: 0x01f280..0x01f284 (4 B) | Symbol: sub_01f280
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_01f280(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00003C8ULL) << 32) | 0x17FFBE38ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01F280ULL;
}

// FDE #0166 | PC: 0x01f284..0x01f2a4 (32 B) | Symbol: sub_01f284
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0xa30; str x8, [x1]; ldr x8, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0xa30; str x8, [x1]; ldr x8, [x0, #0x18]]
uint64_t fde_sub_01f284(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9128C108ULL) << 32) | 0xD00003C8ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01F284ULL;
}

// FDE #0167 | PC: 0x01f2a4..0x01f2a8 (4 B) | Symbol: sub_01f2a4
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_01f2a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFBE2EULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01F2A4ULL;
}

// FDE #0168 | PC: 0x01f2a8..0x01f2ac (4 B) | Symbol: sub_01f2a8
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_01f2a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA940A002ULL) << 32) | 0x17FFBE2EULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01F2A8ULL;
}

// FDE #0169 | PC: 0x01f2ac..0x01f2bc (16 B) | Symbol: sub_01f2ac
// EN: AArch64 prologue [ldp x2, x8, [x0, #8]; ldr x1, [x0, #0x18]; mov x0, x8; br x2] | VI: Khởi đầu hàm AArch64 [ldp x2, x8, [x0, #8]; ldr x1, [x0, #0x18]; mov x0, x8; br x2]
uint64_t fde_sub_01f2ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400C01ULL) << 32) | 0xA940A002ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01F2ACULL;
}

// FDE #0170 | PC: 0x01f2bc..0x01f618 (860 B) | Symbol: sub_01f2bc
// EN: AArch64 prologue [stp x28, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_01f2bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FCULL;
    const uint64_t kPcRange = 0x035CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01F2BCULL;
}

// FDE #0171 | PC: 0x01f618..0x01f7a8 (400 B) | Symbol: sub_01f618
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_01f618(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0190ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01F618ULL;
}

// FDE #0172 | PC: 0x01f7a8..0x01fcb0 (1288 B) | Symbol: sub_01f7a8
// EN: AArch64 prologue [stp x28, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_01f7a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FCULL;
    const uint64_t kPcRange = 0x0508ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01F7A8ULL;
}

// FDE #0173 | PC: 0x01fcb0..0x01fe58 (424 B) | Symbol: sub_01fcb0
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_01fcb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x01A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01FCB0ULL;
}

// FDE #0174 | PC: 0x01fe58..0x01fe5c (4 B) | Symbol: sub_01fe58
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_01fe58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01FE58ULL;
}

// FDE #0175 | PC: 0x01fe5c..0x01fe60 (4 B) | Symbol: sub_01fe5c
// EN: AArch64 prologue [b #0x1fe60] | VI: Khởi đầu hàm AArch64 [b #0x1fe60]
uint64_t fde_sub_01fe5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x14000001ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01FE5CULL;
}

// FDE #0176 | PC: 0x01fe60..0x0207d4 (2420 B) | Symbol: sub_01fe60
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_01fe60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0974ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01FE60ULL;
}

// FDE #0177 | PC: 0x0207d4..0x0207d8 (4 B) | Symbol: sub_0207d4
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_0207d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00003C8ULL) << 32) | 0x17FFB8E3ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0207D4ULL;
}

// FDE #0178 | PC: 0x0207d8..0x0207f0 (24 B) | Symbol: sub_0207d8
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0xa70; str x8, [x1]; ldur q0, [x0, #8]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0xa70; str x8, [x1]; ldur q0, [x0, #8]]
uint64_t fde_sub_0207d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9129C108ULL) << 32) | 0xB00003C8ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0207D8ULL;
}

// FDE #0179 | PC: 0x0207f0..0x0207f4 (4 B) | Symbol: sub_0207f0
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_0207f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFB8DBULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0207F0ULL;
}

// FDE #0180 | PC: 0x0207f4..0x0207f8 (4 B) | Symbol: sub_0207f4
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_0207f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400400ULL) << 32) | 0x17FFB8DBULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0207F4ULL;
}

// FDE #0181 | PC: 0x0207f8..0x020800 (8 B) | Symbol: sub_0207f8
// EN: AArch64 prologue [ldr x0, [x0, #8]; b #0x1fe60] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #8]; b #0x1fe60]
uint64_t fde_sub_0207f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFD99ULL) << 32) | 0xF9400400ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0207F8ULL;
}

// FDE #0182 | PC: 0x020800..0x020824 (36 B) | Symbol: sub_020800
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_020800(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020800ULL;
}

// FDE #0183 | PC: 0x020824..0x02086c (72 B) | Symbol: sub_020824
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #0x18]]
uint64_t fde_sub_020824(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020824ULL;
}

// FDE #0184 | PC: 0x02086c..0x020870 (4 B) | Symbol: sub_02086c
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_02086c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0x17FFB8BDULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02086CULL;
}

// FDE #0185 | PC: 0x020870..0x020894 (36 B) | Symbol: sub_020870
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_020870(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020870ULL;
}

// FDE #0186 | PC: 0x020894..0x02093c (168 B) | Symbol: sub_020894
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_020894(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020894ULL;
}

// FDE #0187 | PC: 0x02093c..0x020940 (4 B) | Symbol: sub_02093c
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_02093c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0x17FFB889ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02093CULL;
}

// FDE #0188 | PC: 0x020940..0x020964 (36 B) | Symbol: sub_020940
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_020940(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020940ULL;
}

// FDE #0189 | PC: 0x020964..0x0209f4 (144 B) | Symbol: sub_020964
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_020964(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020964ULL;
}

// FDE #0190 | PC: 0x0209f4..0x0209f8 (4 B) | Symbol: sub_0209f4
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_0209f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD103C3FFULL) << 32) | 0x17FFB85BULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0209F4ULL;
}

// FDE #0191 | PC: 0x0209f8..0x020ed8 (1248 B) | Symbol: sub_0209f8
// EN: AArch64 prologue [sub sp, sp, #0xf0; str x25, [sp, #0xa0]; stp x24, x23, [sp, #0xb0]; stp x22, x21, [sp, #0xc0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xf0; str x25, [sp, #0xa0]; stp x24, x23, [sp, #0xb0]; stp x22, x21, [sp, #0xc0]]
uint64_t fde_sub_0209f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90053F9ULL) << 32) | 0xD103C3FFULL;
    const uint64_t kPcRange = 0x04E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0209F8ULL;
}

// FDE #0192 | PC: 0x020ed8..0x020edc (4 B) | Symbol: sub_020ed8
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_020ed8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020ED8ULL;
}

// FDE #0193 | PC: 0x020edc..0x020ee0 (4 B) | Symbol: sub_020edc
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_020edc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000080ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020EDCULL;
}

// FDE #0194 | PC: 0x020ee0..0x020ef4 (20 B) | Symbol: sub_020ee0
// EN: AArch64 prologue [cbz x0, #0x20ef0; ldr x0, [x0]; cbz x0, #0x20ef0; b #0x4c5ac] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x20ef0; ldr x0, [x0]; cbz x0, #0x20ef0; b #0x4c5ac]
uint64_t fde_sub_020ee0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400000ULL) << 32) | 0xB4000080ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020EE0ULL;
}

// FDE #0195 | PC: 0x020ef4..0x020ef8 (4 B) | Symbol: sub_020ef4
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_020ef4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00003C8ULL) << 32) | 0x17FFB71BULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020EF4ULL;
}

// FDE #0196 | PC: 0x020ef8..0x020f10 (24 B) | Symbol: sub_020ef8
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0xc68; str x8, [x1]; ldur q0, [x0, #8]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0xc68; str x8, [x1]; ldur q0, [x0, #8]]
uint64_t fde_sub_020ef8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9131A108ULL) << 32) | 0xB00003C8ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020EF8ULL;
}

// FDE #0197 | PC: 0x020f10..0x020f14 (4 B) | Symbol: sub_020f10
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_020f10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFB713ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020F10ULL;
}

// FDE #0198 | PC: 0x020f14..0x020f18 (4 B) | Symbol: sub_020f14
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_020f14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9408001ULL) << 32) | 0x17FFB713ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020F14ULL;
}

// FDE #0199 | PC: 0x020f18..0x020f20 (8 B) | Symbol: sub_020f18
// EN: AArch64 prologue [ldp x1, x0, [x0, #8]; br x1] | VI: Khởi đầu hàm AArch64 [ldp x1, x0, [x0, #8]; br x1]
uint64_t fde_sub_020f18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD61F0020ULL) << 32) | 0xA9408001ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020F18ULL;
}

// FDE #0200 | PC: 0x020f20..0x020f44 (36 B) | Symbol: sub_020f20
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_020f20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020F20ULL;
}

// FDE #0201 | PC: 0x020f44..0x020fbc (120 B) | Symbol: sub_020f44
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #0x18]]
uint64_t fde_sub_020f44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020F44ULL;
}

// FDE #0202 | PC: 0x020fbc..0x020fc0 (4 B) | Symbol: sub_020fbc
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_020fbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD106C3FFULL) << 32) | 0x17FFB6E9ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020FBCULL;
}

// FDE #0203 | PC: 0x020fc0..0x021a10 (2640 B) | Symbol: sub_020fc0
// EN: AArch64 prologue [sub sp, sp, #0x1b0; stp x28, x27, [sp, #0x150]; stp x26, x25, [sp, #0x160]; stp x24, x23, [sp, #0x170]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1b0; stp x28, x27, [sp, #0x150]; stp x26, x25, [sp, #0x160]; stp x24, x23, [sp, #0x170]]
uint64_t fde_sub_020fc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9156FFCULL) << 32) | 0xD106C3FFULL;
    const uint64_t kPcRange = 0x0A50ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020FC0ULL;
}

// FDE #0204 | PC: 0x021a10..0x021b30 (288 B) | Symbol: sub_021a10
// EN: AArch64 prologue [sub sp, sp, #0x110; stp x28, x21, [sp, #0xe0]; stp x20, x19, [sp, #0xf0]; stp x29, x30, [sp, #0x100]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; stp x28, x21, [sp, #0xe0]; stp x20, x19, [sp, #0xf0]; stp x29, x30, [sp, #0x100]]
uint64_t fde_sub_021a10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90E57FCULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x0120ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x021A10ULL;
}

// FDE #0205 | PC: 0x021b30..0x021b54 (36 B) | Symbol: sub_021b30
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_021b30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x021B30ULL;
}

// FDE #0206 | PC: 0x021b54..0x021bcc (120 B) | Symbol: sub_021b54
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #0x18]]
uint64_t fde_sub_021b54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x021B54ULL;
}

// FDE #0207 | PC: 0x021bcc..0x021bd0 (4 B) | Symbol: sub_021bcc
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_021bcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0x17FFB3E5ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x021BCCULL;
}

// FDE #0208 | PC: 0x021bd0..0x021c00 (48 B) | Symbol: sub_021bd0
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x99000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x99000]
uint64_t fde_sub_021bd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x021BD0ULL;
}

// FDE #0209 | PC: 0x021c00..0x021c38 (56 B) | Symbol: sub_021c00
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x99000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x99000]
uint64_t fde_sub_021c00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x021C00ULL;
}

// FDE #0210 | PC: 0x021c38..0x021c40 (8 B) | Symbol: sub_021c38
// EN: AArch64 prologue [add x0, x0, #0x18; b #0x21c44] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x18; b #0x21c44]
uint64_t fde_sub_021c38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000002ULL) << 32) | 0x91006000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x021C38ULL;
}

// FDE #0211 | PC: 0x021c40..0x021c44 (4 B) | Symbol: sub_021c40
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_021c40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE4FF4ULL) << 32) | 0x17FFB3C8ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x021C40ULL;
}

// FDE #0212 | PC: 0x021c44..0x021ce4 (160 B) | Symbol: sub_021c44
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0, #0x180]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0, #0x180]]
uint64_t fde_sub_021c44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x021C44ULL;
}

// FDE #0213 | PC: 0x021ce4..0x021d14 (48 B) | Symbol: sub_021ce4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x99000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x99000]
uint64_t fde_sub_021ce4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x021CE4ULL;
}

// FDE #0214 | PC: 0x021d14..0x021d4c (56 B) | Symbol: sub_021d14
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x99000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x99000]
uint64_t fde_sub_021d14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x021D14ULL;
}

// FDE #0215 | PC: 0x021d4c..0x021d58 (12 B) | Symbol: sub_021d4c
// EN: AArch64 prologue [ldr x8, [x0, #0x18]!; ldr x1, [x8]; br x1] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x18]!; ldr x1, [x8]; br x1]
uint64_t fde_sub_021d4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400101ULL) << 32) | 0xF8418C08ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x021D4CULL;
}

// FDE #0216 | PC: 0x021d58..0x021d5c (4 B) | Symbol: sub_021d58
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_021d58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x17FFB382ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x021D58ULL;
}

// FDE #0217 | PC: 0x021d5c..0x022178 (1052 B) | Symbol: sub_021d5c
// EN: AArch64 prologue [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_021d5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x041CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x021D5CULL;
}

// FDE #0218 | PC: 0x022178..0x02219c (36 B) | Symbol: sub_022178
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_022178(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022178ULL;
}

// FDE #0219 | PC: 0x02219c..0x023234 (4248 B) | Symbol: sub_02219c
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_02219c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02219CULL;
}

// FDE #0220 | PC: 0x023234..0x0235b8 (900 B) | Symbol: sub_023234
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_023234(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9025FF8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0384ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x023234ULL;
}

// FDE #0221 | PC: 0x0235b8..0x023790 (472 B) | Symbol: sub_0235b8
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_0235b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90257F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x01D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0235B8ULL;
}

// FDE #0222 | PC: 0x023790..0x0238ac (284 B) | Symbol: sub_023790
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x28]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x28]]
uint64_t fde_sub_023790(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x023790ULL;
}

// FDE #0223 | PC: 0x0238ac..0x0238dc (48 B) | Symbol: sub_0238ac
// EN: AArch64 prologue [mov w8, #0x8a89; movk w8, #1, lsl #16; cmp w1, w8; b.ne #0x238d4] | VI: Khởi đầu hàm AArch64 [mov w8, #0x8a89; movk w8, #1, lsl #16; cmp w1, w8; b.ne #0x238d4]
uint64_t fde_sub_0238ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72A00028ULL) << 32) | 0x52915128ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0238ACULL;
}

// FDE #0224 | PC: 0x0238dc..0x0239c4 (232 B) | Symbol: sub_0238dc
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w8, #0x7578; movk w8, #0xfffe, lsl #16] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w8, #0x7578; movk w8, #0xfffe, lsl #16]
uint64_t fde_sub_0238dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0238DCULL;
}

// FDE #0225 | PC: 0x0239c4..0x0239cc (8 B) | Symbol: sub_0239c4
// EN: AArch64 prologue [mov w0, #1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #1; ret]
uint64_t fde_sub_0239c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0239C4ULL;
}

// FDE #0226 | PC: 0x0239cc..0x0239d4 (8 B) | Symbol: sub_0239cc
// EN: AArch64 prologue [mov w0, #1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #1; ret]
uint64_t fde_sub_0239cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0239CCULL;
}

// FDE #0227 | PC: 0x0239d4..0x0239f0 (28 B) | Symbol: sub_0239d4
// EN: AArch64 prologue [add x0, x0, #0x58; cmp x0, x1; b.eq #0x239ec; mov x2, x1] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x58; cmp x0, x1; b.eq #0x239ec; mov x2, x1]
uint64_t fde_sub_0239d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB01001FULL) << 32) | 0x91016000ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0239D4ULL;
}

// FDE #0228 | PC: 0x0239f0..0x023aac (188 B) | Symbol: sub_0239f0
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0239f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0239F0ULL;
}

// FDE #0229 | PC: 0x023aac..0x023bec (320 B) | Symbol: sub_023aac
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_023aac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90257F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0140ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x023AACULL;
}

// FDE #0230 | PC: 0x023bec..0x023c88 (156 B) | Symbol: sub_023bec
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_023bec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x023BECULL;
}

// FDE #0231 | PC: 0x023c88..0x023db8 (304 B) | Symbol: sub_023c88
// EN: AArch64 prologue [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_023c88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x023C88ULL;
}

// FDE #0232 | PC: 0x023db8..0x023dc0 (8 B) | Symbol: sub_023db8
// EN: AArch64 prologue [mov w2, wzr; b #0x25138] | VI: Khởi đầu hàm AArch64 [mov w2, wzr; b #0x25138]
uint64_t fde_sub_023db8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140004DFULL) << 32) | 0x2A1F03E2ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x023DB8ULL;
}

// FDE #0233 | PC: 0x023dc0..0x023f40 (384 B) | Symbol: sub_023dc0
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_023dc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90267FAULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0180ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x023DC0ULL;
}

// FDE #0234 | PC: 0x023f40..0x024000 (192 B) | Symbol: sub_023f40
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_023f40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x023F40ULL;
}

// FDE #0235 | PC: 0x024000..0x024008 (8 B) | Symbol: sub_024000
// EN: AArch64 prologue [mov w2, #1; b #0x25138] | VI: Khởi đầu hàm AArch64 [mov w2, #1; b #0x25138]
uint64_t fde_sub_024000(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400044DULL) << 32) | 0x52800022ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024000ULL;
}

// FDE #0236 | PC: 0x024008..0x024028 (32 B) | Symbol: sub_024008
// EN: AArch64 prologue [ldr x8, [x0, #0xe0]; cbz x8, #0x24020; ldr x8, [x8, #0x178]; cbz x8, #0x24020] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0xe0]; cbz x8, #0x24020; ldr x8, [x8, #0x178]; cbz x8, #0x24020]
uint64_t fde_sub_024008(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB40000A8ULL) << 32) | 0xF9407008ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024008ULL;
}

// FDE #0237 | PC: 0x024028..0x024030 (8 B) | Symbol: sub_024028
// EN: AArch64 prologue [sub x0, x0, #8; b #0x21d5c] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x21d5c]
uint64_t fde_sub_024028(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFF74CULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024028ULL;
}

// FDE #0238 | PC: 0x024030..0x024058 (40 B) | Symbol: sub_024030
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub x19, x0, #8] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub x19, x0, #8]
uint64_t fde_sub_024030(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024030ULL;
}

// FDE #0239 | PC: 0x024058..0x024114 (188 B) | Symbol: sub_024058
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_024058(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024058ULL;
}

// FDE #0240 | PC: 0x024114..0x02411c (8 B) | Symbol: sub_024114
// EN: AArch64 prologue [sub x0, x0, #8; b #0x23aac] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x23aac]
uint64_t fde_sub_024114(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFE65ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024114ULL;
}

// FDE #0241 | PC: 0x02411c..0x0241bc (160 B) | Symbol: sub_02411c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_02411c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02411CULL;
}

// FDE #0242 | PC: 0x0241bc..0x0241c4 (8 B) | Symbol: sub_0241bc
// EN: AArch64 prologue [sub x0, x0, #8; b #0x23c88] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x23c88]
uint64_t fde_sub_0241bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFEB2ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0241BCULL;
}

// FDE #0243 | PC: 0x0241c4..0x0241d0 (12 B) | Symbol: sub_0241c4
// EN: AArch64 prologue [sub x0, x0, #8; mov w2, wzr; b #0x25138] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; mov w2, wzr; b #0x25138]
uint64_t fde_sub_0241c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E2ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0241C4ULL;
}

// FDE #0244 | PC: 0x0241d0..0x0241d8 (8 B) | Symbol: sub_0241d0
// EN: AArch64 prologue [sub x0, x0, #8; b #0x23dc0] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x23dc0]
uint64_t fde_sub_0241d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFEFBULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0241D0ULL;
}

// FDE #0245 | PC: 0x0241d8..0x0241e0 (8 B) | Symbol: sub_0241d8
// EN: AArch64 prologue [sub x0, x0, #0x10; b #0x21d5c] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x10; b #0x21d5c]
uint64_t fde_sub_0241d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFF6E0ULL) << 32) | 0xD1004000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0241D8ULL;
}

// FDE #0246 | PC: 0x0241e0..0x024208 (40 B) | Symbol: sub_0241e0
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub x19, x0, #0x10] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub x19, x0, #0x10]
uint64_t fde_sub_0241e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0241E0ULL;
}

// FDE #0247 | PC: 0x024208..0x0242c8 (192 B) | Symbol: sub_024208
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_024208(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024208ULL;
}

// FDE #0248 | PC: 0x0242c8..0x0242d4 (12 B) | Symbol: sub_0242c8
// EN: AArch64 prologue [sub x0, x0, #0x10; mov w2, #1; b #0x25138] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x10; mov w2, #1; b #0x25138]
uint64_t fde_sub_0242c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800022ULL) << 32) | 0xD1004000ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0242C8ULL;
}

// FDE #0249 | PC: 0x0242d4..0x0242f8 (36 B) | Symbol: sub_0242d4
// EN: AArch64 prologue [ldr x8, [x0, #0xd0]; cbz x8, #0x242ec; ldr x8, [x8, #0x178]; cbz x8, #0x242ec] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0xd0]; cbz x8, #0x242ec; ldr x8, [x8, #0x178]; cbz x8, #0x242ec]
uint64_t fde_sub_0242d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB40000A8ULL) << 32) | 0xF9406808ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0242D4ULL;
}

// FDE #0250 | PC: 0x0242f8..0x024300 (8 B) | Symbol: sub_0242f8
// EN: AArch64 prologue [sub x0, x0, #0x10; b #0x23dc0] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x10; b #0x23dc0]
uint64_t fde_sub_0242f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFEB1ULL) << 32) | 0xD1004000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0242F8ULL;
}

// FDE #0251 | PC: 0x024300..0x02454c (588 B) | Symbol: sub_024300
// EN: AArch64 prologue [sub sp, sp, #0xc0; str x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; str x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]]
uint64_t fde_sub_024300(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9003BF9ULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x024CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024300ULL;
}

// FDE #0252 | PC: 0x02454c..0x024550 (4 B) | Symbol: sub_02454c
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_02454c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00003A8ULL) << 32) | 0x17FFA985ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02454CULL;
}

// FDE #0253 | PC: 0x024550..0x024568 (24 B) | Symbol: sub_024550
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0xe90; str x8, [x1]; ldur q0, [x0, #8]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0xe90; str x8, [x1]; ldur q0, [x0, #8]]
uint64_t fde_sub_024550(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x913A4108ULL) << 32) | 0xB00003A8ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024550ULL;
}

// FDE #0254 | PC: 0x024568..0x02456c (4 B) | Symbol: sub_024568
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_024568(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFA97DULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024568ULL;
}

// FDE #0255 | PC: 0x02456c..0x024570 (4 B) | Symbol: sub_02456c
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_02456c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10103FFULL) << 32) | 0x17FFA97DULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02456CULL;
}

// FDE #0256 | PC: 0x024570..0x024654 (228 B) | Symbol: sub_024570
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30]
uint64_t fde_sub_024570(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9024FF4ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024570ULL;
}

// FDE #0257 | PC: 0x024654..0x024b34 (1248 B) | Symbol: sub_024654
// EN: AArch64 prologue [sub sp, sp, #0x90; str x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]; stp x20, x19, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]; stp x20, x19, [sp, #0x70]]
uint64_t fde_sub_024654(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9002BF7ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x04E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024654ULL;
}

// FDE #0258 | PC: 0x024b34..0x024c68 (308 B) | Symbol: sub_024b34
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_024b34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90257F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0134ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024B34ULL;
}

// FDE #0259 | PC: 0x024c68..0x024f00 (664 B) | Symbol: sub_024c68
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x24, x23, [sp, #0x70]; stp x22, x21, [sp, #0x80]; stp x20, x19, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x24, x23, [sp, #0x70]; stp x22, x21, [sp, #0x80]; stp x20, x19, [sp, #0x90]]
uint64_t fde_sub_024c68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9075FF8ULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x0298ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024C68ULL;
}

// FDE #0260 | PC: 0x024f00..0x024f64 (100 B) | Symbol: sub_024f00
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #0x18]]
uint64_t fde_sub_024f00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024F00ULL;
}

// FDE #0261 | PC: 0x024f64..0x024fd8 (116 B) | Symbol: sub_024f64
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0, #0x18]]
uint64_t fde_sub_024f64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024F64ULL;
}

// FDE #0262 | PC: 0x024fd8..0x024ffc (36 B) | Symbol: sub_024fd8
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0xed0; str x8, [x1]; ldur q0, [x0, #8]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0xed0; str x8, [x1]; ldur q0, [x0, #8]]
uint64_t fde_sub_024fd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x913B4108ULL) << 32) | 0xB00003A8ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024FD8ULL;
}

// FDE #0263 | PC: 0x024ffc..0x025054 (88 B) | Symbol: sub_024ffc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #0x18]]
uint64_t fde_sub_024ffc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024FFCULL;
}

// FDE #0264 | PC: 0x025054..0x0250bc (104 B) | Symbol: sub_025054
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0, #0x18]]
uint64_t fde_sub_025054(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x025054ULL;
}

// FDE #0265 | PC: 0x0250bc..0x025138 (124 B) | Symbol: sub_0250bc
// EN: AArch64 prologue [sub sp, sp, #0x40; str x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30]
uint64_t fde_sub_0250bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F3ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0250BCULL;
}

// FDE #0266 | PC: 0x025138..0x025304 (460 B) | Symbol: sub_025138
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30]
uint64_t fde_sub_025138(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9024FF4ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x01CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x025138ULL;
}

// FDE #0267 | PC: 0x025304..0x025450 (332 B) | Symbol: sub_025304
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_025304(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x014CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x025304ULL;
}

// FDE #0268 | PC: 0x025450..0x02559c (332 B) | Symbol: sub_025450
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_025450(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x014CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x025450ULL;
}

// FDE #0269 | PC: 0x02559c..0x0259e4 (1096 B) | Symbol: sub_02559c
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_02559c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9016FFCULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0448ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02559CULL;
}

// FDE #0270 | PC: 0x0259e4..0x025ec4 (1248 B) | Symbol: sub_0259e4
// EN: AArch64 prologue [sub sp, sp, #0x90; str x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]; stp x20, x19, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]; stp x20, x19, [sp, #0x70]]
uint64_t fde_sub_0259e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9002BF7ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x04E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0259E4ULL;
}

// FDE #0271 | PC: 0x025ec4..0x025fc4 (256 B) | Symbol: sub_025ec4
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_025ec4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x025EC4ULL;
}

// FDE #0272 | PC: 0x025fc4..0x0260d0 (268 B) | Symbol: sub_025fc4
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_025fc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x025FC4ULL;
}

// FDE #0273 | PC: 0x0260d0..0x0260ec (28 B) | Symbol: sub_0260d0
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x0, x2; bl #0x260ec] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x0, x2; bl #0x260ec]
uint64_t fde_sub_0260d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0260D0ULL;
}

// FDE #0274 | PC: 0x0260ec..0x026bb0 (2756 B) | Symbol: sub_0260ec
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0260ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0AC4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0260ECULL;
}

// FDE #0275 | PC: 0x026bb0..0x026f20 (880 B) | Symbol: sub_026bb0
// EN: AArch64 prologue [sub sp, sp, #0xc0; str x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; str x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]]
uint64_t fde_sub_026bb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9003BF9ULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x0370ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x026BB0ULL;
}

// FDE #0276 | PC: 0x026f20..0x026f24 (4 B) | Symbol: sub_026f20
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_026f20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000388ULL) << 32) | 0x17FF9F10ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x026F20ULL;
}

// FDE #0277 | PC: 0x026f24..0x026f3c (24 B) | Symbol: sub_026f24
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0xf10; str x8, [x1]; ldur q0, [x0, #8]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0xf10; str x8, [x1]; ldur q0, [x0, #8]]
uint64_t fde_sub_026f24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x913C4108ULL) << 32) | 0xF0000388ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x026F24ULL;
}

// FDE #0278 | PC: 0x026f3c..0x026f40 (4 B) | Symbol: sub_026f3c
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_026f3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF9F08ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x026F3CULL;
}

// FDE #0279 | PC: 0x026f40..0x026f44 (4 B) | Symbol: sub_026f40
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_026f40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x17FF9F08ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x026F40ULL;
}

// FDE #0280 | PC: 0x026f44..0x027040 (252 B) | Symbol: sub_026f44
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_026f44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x026F44ULL;
}

// FDE #0281 | PC: 0x027040..0x027044 (4 B) | Symbol: sub_027040
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_027040(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000388ULL) << 32) | 0x17FF9EC8ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x027040ULL;
}

// FDE #0282 | PC: 0x027044..0x02705c (24 B) | Symbol: sub_027044
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0xf50; str x8, [x1]; ldur q0, [x0, #8]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0xf50; str x8, [x1]; ldur q0, [x0, #8]]
uint64_t fde_sub_027044(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x913D4108ULL) << 32) | 0xD0000388ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x027044ULL;
}

// FDE #0283 | PC: 0x02705c..0x027060 (4 B) | Symbol: sub_02705c
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_02705c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF9EC0ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02705CULL;
}

// FDE #0284 | PC: 0x027060..0x027064 (4 B) | Symbol: sub_027060
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_027060(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0x17FF9EC0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x027060ULL;
}

// FDE #0285 | PC: 0x027064..0x027368 (772 B) | Symbol: sub_027064
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_027064(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9035FF8ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0304ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x027064ULL;
}

// FDE #0286 | PC: 0x027368..0x0274a4 (316 B) | Symbol: sub_027368
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_027368(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x013CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x027368ULL;
}

// FDE #0287 | PC: 0x0274a4..0x0274c4 (32 B) | Symbol: sub_0274a4
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x0, x1; mov w1, #1] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x0, x1; mov w1, #1]
uint64_t fde_sub_0274a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0274A4ULL;
}

// FDE #0288 | PC: 0x0274c4..0x027c68 (1956 B) | Symbol: sub_0274c4
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0274c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x07A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0274C4ULL;
}

// FDE #0289 | PC: 0x027c68..0x027cfc (148 B) | Symbol: sub_027c68
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x1]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x1]]
uint64_t fde_sub_027c68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x027C68ULL;
}

// FDE #0290 | PC: 0x027cfc..0x028018 (796 B) | Symbol: sub_027cfc
// EN: AArch64 prologue [sub sp, sp, #0x1c0; stp x28, x23, [sp, #0x180]; stp x22, x21, [sp, #0x190]; stp x20, x19, [sp, #0x1a0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1c0; stp x28, x23, [sp, #0x180]; stp x22, x21, [sp, #0x190]; stp x20, x19, [sp, #0x1a0]]
uint64_t fde_sub_027cfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9185FFCULL) << 32) | 0xD10703FFULL;
    const uint64_t kPcRange = 0x031CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x027CFCULL;
}

// FDE #0291 | PC: 0x028018..0x028220 (520 B) | Symbol: sub_028018
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_028018(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90257F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0208ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028018ULL;
}

// FDE #0292 | PC: 0x028220..0x0285e4 (964 B) | Symbol: sub_028220
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]]
uint64_t fde_sub_028220(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9056FFCULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x03C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028220ULL;
}

// FDE #0293 | PC: 0x0285e4..0x028798 (436 B) | Symbol: sub_0285e4
// EN: AArch64 prologue [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0285e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x01B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0285E4ULL;
}

// FDE #0294 | PC: 0x028798..0x0289ec (596 B) | Symbol: sub_028798
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x24, x23, [sp, #0x70]; stp x22, x21, [sp, #0x80]; stp x20, x19, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x24, x23, [sp, #0x70]; stp x22, x21, [sp, #0x80]; stp x20, x19, [sp, #0x90]]
uint64_t fde_sub_028798(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9075FF8ULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x0254ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028798ULL;
}

// FDE #0295 | PC: 0x0289ec..0x0289f0 (4 B) | Symbol: sub_0289ec
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_0289ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000388ULL) << 32) | 0x17FF985DULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0289ECULL;
}

// FDE #0296 | PC: 0x0289f0..0x028a08 (24 B) | Symbol: sub_0289f0
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0xf90; str x8, [x1]; ldur q0, [x0, #8]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0xf90; str x8, [x1]; ldur q0, [x0, #8]]
uint64_t fde_sub_0289f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x913E4108ULL) << 32) | 0xB0000388ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0289F0ULL;
}

// FDE #0297 | PC: 0x028a08..0x028a0c (4 B) | Symbol: sub_028a08
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_028a08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF9855ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028A08ULL;
}

// FDE #0298 | PC: 0x028a0c..0x028a10 (4 B) | Symbol: sub_028a0c
// EN: AArch64 prologue [b #0xeb60] | VI: Khởi đầu hàm AArch64 [b #0xeb60]
uint64_t fde_sub_028a0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9408001ULL) << 32) | 0x17FF9855ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028A0CULL;
}

// FDE #0299 | PC: 0x028a10..0x028a18 (8 B) | Symbol: sub_028a10
// EN: AArch64 prologue [ldp x1, x0, [x0, #8]; br x1] | VI: Khởi đầu hàm AArch64 [ldp x1, x0, [x0, #8]; br x1]
uint64_t fde_sub_028a10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD61F0020ULL) << 32) | 0xA9408001ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028A10ULL;
}

// FDE #0300 | PC: 0x028a18..0x028de4 (972 B) | Symbol: sub_028a18
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp x28, x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp x28, x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]]
uint64_t fde_sub_028a18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9046FFCULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x03CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028A18ULL;
}

// FDE #0301 | PC: 0x028de4..0x0291e4 (1024 B) | Symbol: sub_028de4
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp x28, x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp x28, x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]]
uint64_t fde_sub_028de4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9046FFCULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x0400ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028DE4ULL;
}

// FDE #0302 | PC: 0x0291e4..0x0295e4 (1024 B) | Symbol: sub_0291e4
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp x28, x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp x28, x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]]
uint64_t fde_sub_0291e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9046FFCULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x0400ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0291E4ULL;
}

// FDE #0303 | PC: 0x0295e4..0x029884 (672 B) | Symbol: sub_0295e4
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]]
uint64_t fde_sub_0295e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9056FFCULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x02A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0295E4ULL;
}

// FDE #0304 | PC: 0x029884..0x029918 (148 B) | Symbol: sub_029884
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_029884(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x029884ULL;
}

// FDE #0305 | PC: 0x029918..0x029a34 (284 B) | Symbol: sub_029918
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_029918(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x029918ULL;
}

// FDE #0306 | PC: 0x029a34..0x029c9c (616 B) | Symbol: sub_029a34
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]; stp x22, x21, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]; stp x22, x21, [sp, #0x70]]
uint64_t fde_sub_029a34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90567FAULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x0268ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x029A34ULL;
}

// FDE #0307 | PC: 0x029c9c..0x02a3dc (1856 B) | Symbol: sub_029c9c
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_029c9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0740ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x029C9CULL;
}

// FDE #0308 | PC: 0x02a3dc..0x02ae1c (2624 B) | Symbol: sub_02a3dc
// EN: AArch64 prologue [sub sp, sp, #0xd0; stp x28, x27, [sp, #0x70]; stp x26, x25, [sp, #0x80]; stp x24, x23, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xd0; stp x28, x27, [sp, #0x70]; stp x26, x25, [sp, #0x80]; stp x24, x23, [sp, #0x90]]
uint64_t fde_sub_02a3dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9076FFCULL) << 32) | 0xD10343FFULL;
    const uint64_t kPcRange = 0x0A40ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02A3DCULL;
}

// FDE #0309 | PC: 0x02ae1c..0x02b024 (520 B) | Symbol: sub_02ae1c
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_02ae1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0208ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02AE1CULL;
}

// FDE #0310 | PC: 0x02b024..0x02b164 (320 B) | Symbol: sub_02b024
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_02b024(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0140ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02B024ULL;
}

// FDE #0311 | PC: 0x02b164..0x02b5d0 (1132 B) | Symbol: sub_02b164
// EN: AArch64 prologue [cmp x1, #0x20; b.hi #0x2b1d4; cmp x1, #0x10; b.hi #0x2b2a0] | VI: Khởi đầu hàm AArch64 [cmp x1, #0x20; b.hi #0x2b1d4; cmp x1, #0x10; b.hi #0x2b2a0]
uint64_t fde_sub_02b164(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000368ULL) << 32) | 0xF100803FULL;
    const uint64_t kPcRange = 0x046CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02B164ULL;
}

// FDE #0312 | PC: 0x02b5d0..0x02b8f0 (800 B) | Symbol: sub_02b5d0
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_02b5d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9016FFCULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0320ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02B5D0ULL;
}

// FDE #0313 | PC: 0x02b8f0..0x02ba08 (280 B) | Symbol: sub_02b8f0
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_02b8f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0118ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02B8F0ULL;
}

// FDE #0314 | PC: 0x02ba08..0x02bc34 (556 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEPNS_15basic_streambufIcS2_EE
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_02ba08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x022CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02BA08ULL;
}

// FDE #0315 | PC: 0x02bc34..0x02bccc (152 B) | Symbol: sub_02bc34
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0, #0x78]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0, #0x78]]
uint64_t fde_sub_02bc34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02BC34ULL;
}

// FDE #0316 | PC: 0x02bccc..0x02bec8 (508 B) | Symbol: sub_02bccc
// EN: AArch64 prologue [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_02bccc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x01FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02BCCCULL;
}

// FDE #0317 | PC: 0x02bec8..0x02bed4 (12 B) | Symbol: sub_02bec8
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xf700] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xf700]
uint64_t fde_sub_02bec8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02BEC8ULL;
}

// FDE #0318 | PC: 0x02bed4..0x02bef8 (36 B) | Symbol: sub_02bed4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_02bed4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02BED4ULL;
}

// FDE #0319 | PC: 0x02bef8..0x02bff8 (256 B) | Symbol: sub_02bef8
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_02bef8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02BEF8ULL;
}

// FDE #0320 | PC: 0x02bff8..0x02c0f0 (248 B) | Symbol: sub_02bff8
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_02bff8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02BFF8ULL;
}

// FDE #0321 | PC: 0x02c0f0..0x02c1b0 (192 B) | Symbol: sub_02c0f0
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_02c0f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02C0F0ULL;
}

// FDE #0322 | PC: 0x02c1b0..0x02c220 (112 B) | Symbol: sub_02c1b0
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_02c1b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02C1B0ULL;
}

// FDE #0323 | PC: 0x02c220..0x02c4b8 (664 B) | Symbol: sub_02c220
// EN: AArch64 prologue [sub sp, sp, #0x60; str x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_02c220(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0298ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02C220ULL;
}

// FDE #0324 | PC: 0x02c4b8..0x02c518 (96 B) | Symbol: sub_02c4b8
// EN: AArch64 prologue [ldr x9, [x0, #0x78]; cbz x9, #0x2c500; ldp x10, x9, [x0, #0x10]; mov x8, x0] | VI: Khởi đầu hàm AArch64 [ldr x9, [x0, #0x78]; cbz x9, #0x2c500; ldp x10, x9, [x0, #0x10]; mov x8, x0]
uint64_t fde_sub_02c4b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000229ULL) << 32) | 0xF9403C09ULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02C4B8ULL;
}

// FDE #0325 | PC: 0x02c518..0x02c784 (620 B) | Symbol: sub_02c518
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_02c518(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90267FAULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x026CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02C518ULL;
}

// FDE #0326 | PC: 0x02c784..0x02c7bc (56 B) | Symbol: sub_02c784
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9a000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9a000]
uint64_t fde_sub_02c784(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02C784ULL;
}

// FDE #0327 | PC: 0x02c7bc..0x02c800 (68 B) | Symbol: sub_02c7bc
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9a000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0x9a000]
uint64_t fde_sub_02c7bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02C7BCULL;
}

// FDE #0328 | PC: 0x02c800..0x02c844 (68 B) | Symbol: sub_02c800
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_02c800(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02C800ULL;
}

uint64_t DispatchTtkMediaNetShard1(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x00fd20ULL: return fde_sub_00fd20(a0, a1, a2);
        case 0x00fd7cULL: return fde_sub_00fd7c(a0, a1, a2);
        case 0x00fe8cULL: return fde_sub_00fe8c(a0, a1, a2);
        case 0x00ff18ULL: return fde_sub_00ff18(a0, a1, a2);
        case 0x0101d8ULL: return fde_sub_0101d8(a0, a1, a2);
        case 0x0102ccULL: return fde_sub_0102cc(a0, a1, a2);
        case 0x010398ULL: return fde_sub_010398(a0, a1, a2);
        case 0x0104f8ULL: return fde_sub_0104f8(a0, a1, a2);
        case 0x010a8cULL: return fde_sub_010a8c(a0, a1, a2);
        case 0x010d18ULL: return fde_sub_010d18(a0, a1, a2);
        case 0x010f6cULL: return fde_sub_010f6c(a0, a1, a2);
        case 0x011118ULL: return fde_sub_011118(a0, a1, a2);
        case 0x011220ULL: return fde_sub_011220(a0, a1, a2);
        case 0x011450ULL: return fde_sub_011450(a0, a1, a2);
        case 0x011aa0ULL: return fde_sub_011aa0(a0, a1, a2);
        case 0x011e70ULL: return fde_sub_011e70(a0, a1, a2);
        case 0x011f60ULL: return fde_sub_011f60(a0, a1, a2);
        case 0x0122c8ULL: return fde_sub_0122c8(a0, a1, a2);
        case 0x01236cULL: return fde_sub_01236c(a0, a1, a2);
        case 0x012408ULL: return fde_sub_012408(a0, a1, a2);
        case 0x01240cULL: return fde_sub_01240c(a0, a1, a2);
        case 0x012410ULL: return fde_sub_012410(a0, a1, a2);
        case 0x012414ULL: return fde_sub_012414(a0, a1, a2);
        case 0x012768ULL: return fde_sub_012768(a0, a1, a2);
        case 0x012c54ULL: return fde_sub_012c54(a0, a1, a2);
        case 0x012d98ULL: return fde_sub_012d98(a0, a1, a2);
        case 0x012d9cULL: return fde_sub_012d9c(a0, a1, a2);
        case 0x012da0ULL: return fde_sub_012da0(a0, a1, a2);
        case 0x012dc0ULL: return fde_sub_012dc0(a0, a1, a2);
        case 0x012dc4ULL: return fde_sub_012dc4(a0, a1, a2);
        case 0x012dc8ULL: return fde_sub_012dc8(a0, a1, a2);
        case 0x012f8cULL: return fde_sub_012f8c(a0, a1, a2);
        case 0x0140b0ULL: return fde_sub_0140b0(a0, a1, a2);
        case 0x01451cULL: return fde_sub_01451c(a0, a1, a2);
        case 0x01458cULL: return fde_sub_01458c(a0, a1, a2);
        case 0x0147bcULL: return fde_sub_0147bc(a0, a1, a2);
        case 0x0147ccULL: return fde_sub_0147cc(a0, a1, a2);
        case 0x0147fcULL: return fde_sub_0147fc(a0, a1, a2);
        case 0x0148e4ULL: return fde_sub_0148e4(a0, a1, a2);
        case 0x0148ecULL: return fde_sub_0148ec(a0, a1, a2);
        case 0x014914ULL: return fde_sub_014914(a0, a1, a2);
        case 0x0149f8ULL: return fde_sub_0149f8(a0, a1, a2);
        case 0x014ac0ULL: return fde_sub_014ac0(a0, a1, a2);
        case 0x014c00ULL: return fde_sub_014c00(a0, a1, a2);
        case 0x014d20ULL: return fde_sub_014d20(a0, a1, a2);
        case 0x014d50ULL: return fde_sub_014d50(a0, a1, a2);
        case 0x014d88ULL: return fde_sub_014d88(a0, a1, a2);
        case 0x014d94ULL: return fde_sub_014d94(a0, a1, a2);
        case 0x014d98ULL: return fde_sub_014d98(a0, a1, a2);
        case 0x015078ULL: return fde_sub_015078(a0, a1, a2);
        case 0x015320ULL: return fde_sub_015320(a0, a1, a2);
        case 0x01552cULL: return fde_sub_01552c(a0, a1, a2);
        case 0x0156e0ULL: return fde_sub_0156e0(a0, a1, a2);
        case 0x0158b4ULL: return fde_sub_0158b4(a0, a1, a2);
        case 0x015a68ULL: return fde_sub_015a68(a0, a1, a2);
        case 0x015c1cULL: return fde_sub_015c1c(a0, a1, a2);
        case 0x015dd0ULL: return fde_sub_015dd0(a0, a1, a2);
        case 0x015ec0ULL: return fde_sub_015ec0(a0, a1, a2);
        case 0x015f10ULL: return fde_sub_015f10(a0, a1, a2);
        case 0x015f68ULL: return fde_sub_015f68(a0, a1, a2);
        case 0x015f6cULL: return fde_sub_015f6c(a0, a1, a2);
        case 0x015f70ULL: return fde_sub_015f70(a0, a1, a2);
        case 0x016098ULL: return fde_sub_016098(a0, a1, a2);
        case 0x0160acULL: return fde_sub_0160ac(a0, a1, a2);
        case 0x0160b4ULL: return fde_sub_0160b4(a0, a1, a2);
        case 0x0160bcULL: return fde_sub_0160bc(a0, a1, a2);
        case 0x01619cULL: return fde_sub_01619c(a0, a1, a2);
        case 0x0161ecULL: return fde_sub_0161ec(a0, a1, a2);
        case 0x01622cULL: return fde_sub_01622c(a0, a1, a2);
        case 0x01629cULL: return fde_sub_01629c(a0, a1, a2);
        case 0x016370ULL: return fde_sub_016370(a0, a1, a2);
        case 0x0165b8ULL: return fde_sub_0165b8(a0, a1, a2);
        case 0x0166f8ULL: return fde_sub_0166f8(a0, a1, a2);
        case 0x0167d0ULL: return fde_sub_0167d0(a0, a1, a2);
        case 0x0167e4ULL: return fde_sub_0167e4(a0, a1, a2);
        case 0x016818ULL: return fde_sub_016818(a0, a1, a2);
        case 0x016824ULL: return fde_sub_016824(a0, a1, a2);
        case 0x016830ULL: return fde_sub_016830(a0, a1, a2);
        case 0x016838ULL: return fde_sub_016838(a0, a1, a2);
        case 0x016840ULL: return fde_sub_016840(a0, a1, a2);
        case 0x016848ULL: return fde_sub_016848(a0, a1, a2);
        case 0x0168b4ULL: return fde_sub_0168b4(a0, a1, a2);
        case 0x016928ULL: return fde_sub_016928(a0, a1, a2);
        case 0x0169a4ULL: return fde_sub_0169a4(a0, a1, a2);
        case 0x016a28ULL: return fde_sub_016a28(a0, a1, a2);
        case 0x016a30ULL: return fde_sub_016a30(a0, a1, a2);
        case 0x016a58ULL: return fde_sub_016a58(a0, a1, a2);
        case 0x016a6cULL: return fde_sub_016a6c(a0, a1, a2);
        case 0x016a9cULL: return fde_sub_016a9c(a0, a1, a2);
        case 0x016accULL: return fde_sub_016acc(a0, a1, a2);
        case 0x016b04ULL: return fde_sub_016b04(a0, a1, a2);
        case 0x016b10ULL: return fde_sub_016b10(a0, a1, a2);
        case 0x016b14ULL: return fde_sub_016b14(a0, a1, a2);
        case 0x016be4ULL: return fde_sub_016be4(a0, a1, a2);
        case 0x016ca0ULL: return fde_sub_016ca0(a0, a1, a2);
        case 0x016db4ULL: return fde_sub_016db4(a0, a1, a2);
        case 0x017650ULL: return fde_sub_017650(a0, a1, a2);
        case 0x01772cULL: return fde_sub_01772c(a0, a1, a2);
        case 0x01787cULL: return fde_sub_01787c(a0, a1, a2);
        case 0x017f10ULL: return fde_sub_017f10(a0, a1, a2);
        case 0x017fd0ULL: return fde_sub_017fd0(a0, a1, a2);
        case 0x01828cULL: return fde_sub_01828c(a0, a1, a2);
        case 0x018400ULL: return fde_sub_018400(a0, a1, a2);
        case 0x018574ULL: return fde_sub_018574(a0, a1, a2);
        case 0x0185e4ULL: return fde_sub_0185e4(a0, a1, a2);
        case 0x01865cULL: return fde_sub_01865c(a0, a1, a2);
        case 0x0186d8ULL: return fde_sub_0186d8(a0, a1, a2);
        case 0x01875cULL: return fde_sub_01875c(a0, a1, a2);
        case 0x018764ULL: return fde_sub_018764(a0, a1, a2);
        case 0x01878cULL: return fde_sub_01878c(a0, a1, a2);
        case 0x0187a0ULL: return fde_sub_0187a0(a0, a1, a2);
        case 0x0187d0ULL: return fde_sub_0187d0(a0, a1, a2);
        case 0x0189bcULL: return fde_sub_0189bc(a0, a1, a2);
        case 0x0189e0ULL: return fde_sub_0189e0(a0, a1, a2);
        case 0x018a5cULL: return fde_sub_018a5c(a0, a1, a2);
        case 0x018aecULL: return fde_sub_018aec(a0, a1, a2);
        case 0x018b6cULL: return fde_sub_018b6c(a0, a1, a2);
        case 0x018d54ULL: return fde_sub_018d54(a0, a1, a2);
        case 0x019338ULL: return fde_sub_019338(a0, a1, a2);
        case 0x0194bcULL: return fde_sub_0194bc(a0, a1, a2);
        case 0x01c23cULL: return fde_sub_01c23c(a0, a1, a2);
        case 0x01c784ULL: return fde_sub_01c784(a0, a1, a2);
        case 0x01c790ULL: return fde_sub_01c790(a0, a1, a2);
        case 0x01caf4ULL: return fde_sub_01caf4(a0, a1, a2);
        case 0x01cd24ULL: return fde_sub_01cd24(a0, a1, a2);
        case 0x01cda0ULL: return fde_sub_01cda0(a0, a1, a2);
        case 0x01ce24ULL: return fde_sub_01ce24(a0, a1, a2);
        case 0x01ce98ULL: return fde_sub_01ce98(a0, a1, a2);
        case 0x01ce9cULL: return fde_sub_01ce9c(a0, a1, a2);
        case 0x01cea0ULL: return fde_sub_01cea0(a0, a1, a2);
        case 0x01ceb8ULL: return fde_sub_01ceb8(a0, a1, a2);
        case 0x01cebcULL: return fde_sub_01cebc(a0, a1, a2);
        case 0x01cec0ULL: return fde_sub_01cec0(a0, a1, a2);
        case 0x01cec8ULL: return fde_sub_01cec8(a0, a1, a2);
        case 0x01cef8ULL: return fde_sub_01cef8(a0, a1, a2);
        case 0x01cf30ULL: return fde_sub_01cf30(a0, a1, a2);
        case 0x01cf38ULL: return fde_sub_01cf38(a0, a1, a2);
        case 0x01cf3cULL: return fde_sub_01cf3c(a0, a1, a2);
        case 0x01d0fcULL: return fde_sub_01d0fc(a0, a1, a2);
        case 0x01d2c0ULL: return fde_sub_01d2c0(a0, a1, a2);
        case 0x01d624ULL: return fde_sub_01d624(a0, a1, a2);
        case 0x01d854ULL: return fde_sub_01d854(a0, a1, a2);
        case 0x01d8d0ULL: return fde_sub_01d8d0(a0, a1, a2);
        case 0x01d954ULL: return fde_sub_01d954(a0, a1, a2);
        case 0x01d9c8ULL: return fde_sub_01d9c8(a0, a1, a2);
        case 0x01d9ccULL: return fde_sub_01d9cc(a0, a1, a2);
        case 0x01da30ULL: return fde_sub_01da30(a0, a1, a2);
        case 0x01daa4ULL: return fde_sub_01daa4(a0, a1, a2);
        case 0x01dac8ULL: return fde_sub_01dac8(a0, a1, a2);
        case 0x01db20ULL: return fde_sub_01db20(a0, a1, a2);
        case 0x01db88ULL: return fde_sub_01db88(a0, a1, a2);
        case 0x01dc04ULL: return fde_sub_01dc04(a0, a1, a2);
        case 0x01dd18ULL: return fde_sub_01dd18(a0, a1, a2);
        case 0x01dd48ULL: return fde_sub_01dd48(a0, a1, a2);
        case 0x01dd8cULL: return fde_sub_01dd8c(a0, a1, a2);
        case 0x01defcULL: return fde_sub_01defc(a0, a1, a2);
        case 0x01e024ULL: return fde_sub_01e024(a0, a1, a2);
        case 0x01e12cULL: return fde_sub_01e12c(a0, a1, a2);
        case 0x01e934ULL: return fde_sub_01e934(a0, a1, a2);
        case 0x01eb50ULL: return fde_sub_01eb50(a0, a1, a2);
        case 0x01f244ULL: return fde_sub_01f244(a0, a1, a2);
        case 0x01f248ULL: return fde_sub_01f248(a0, a1, a2);
        case 0x01f268ULL: return fde_sub_01f268(a0, a1, a2);
        case 0x01f26cULL: return fde_sub_01f26c(a0, a1, a2);
        case 0x01f270ULL: return fde_sub_01f270(a0, a1, a2);
        case 0x01f280ULL: return fde_sub_01f280(a0, a1, a2);
        case 0x01f284ULL: return fde_sub_01f284(a0, a1, a2);
        case 0x01f2a4ULL: return fde_sub_01f2a4(a0, a1, a2);
        case 0x01f2a8ULL: return fde_sub_01f2a8(a0, a1, a2);
        case 0x01f2acULL: return fde_sub_01f2ac(a0, a1, a2);
        case 0x01f2bcULL: return fde_sub_01f2bc(a0, a1, a2);
        case 0x01f618ULL: return fde_sub_01f618(a0, a1, a2);
        case 0x01f7a8ULL: return fde_sub_01f7a8(a0, a1, a2);
        case 0x01fcb0ULL: return fde_sub_01fcb0(a0, a1, a2);
        case 0x01fe58ULL: return fde_sub_01fe58(a0, a1, a2);
        case 0x01fe5cULL: return fde_sub_01fe5c(a0, a1, a2);
        case 0x01fe60ULL: return fde_sub_01fe60(a0, a1, a2);
        case 0x0207d4ULL: return fde_sub_0207d4(a0, a1, a2);
        case 0x0207d8ULL: return fde_sub_0207d8(a0, a1, a2);
        case 0x0207f0ULL: return fde_sub_0207f0(a0, a1, a2);
        case 0x0207f4ULL: return fde_sub_0207f4(a0, a1, a2);
        case 0x0207f8ULL: return fde_sub_0207f8(a0, a1, a2);
        case 0x020800ULL: return fde_sub_020800(a0, a1, a2);
        case 0x020824ULL: return fde_sub_020824(a0, a1, a2);
        case 0x02086cULL: return fde_sub_02086c(a0, a1, a2);
        case 0x020870ULL: return fde_sub_020870(a0, a1, a2);
        case 0x020894ULL: return fde_sub_020894(a0, a1, a2);
        case 0x02093cULL: return fde_sub_02093c(a0, a1, a2);
        case 0x020940ULL: return fde_sub_020940(a0, a1, a2);
        case 0x020964ULL: return fde_sub_020964(a0, a1, a2);
        case 0x0209f4ULL: return fde_sub_0209f4(a0, a1, a2);
        case 0x0209f8ULL: return fde_sub_0209f8(a0, a1, a2);
        case 0x020ed8ULL: return fde_sub_020ed8(a0, a1, a2);
        case 0x020edcULL: return fde_sub_020edc(a0, a1, a2);
        case 0x020ee0ULL: return fde_sub_020ee0(a0, a1, a2);
        case 0x020ef4ULL: return fde_sub_020ef4(a0, a1, a2);
        case 0x020ef8ULL: return fde_sub_020ef8(a0, a1, a2);
        case 0x020f10ULL: return fde_sub_020f10(a0, a1, a2);
        case 0x020f14ULL: return fde_sub_020f14(a0, a1, a2);
        case 0x020f18ULL: return fde_sub_020f18(a0, a1, a2);
        case 0x020f20ULL: return fde_sub_020f20(a0, a1, a2);
        case 0x020f44ULL: return fde_sub_020f44(a0, a1, a2);
        case 0x020fbcULL: return fde_sub_020fbc(a0, a1, a2);
        case 0x020fc0ULL: return fde_sub_020fc0(a0, a1, a2);
        case 0x021a10ULL: return fde_sub_021a10(a0, a1, a2);
        case 0x021b30ULL: return fde_sub_021b30(a0, a1, a2);
        case 0x021b54ULL: return fde_sub_021b54(a0, a1, a2);
        case 0x021bccULL: return fde_sub_021bcc(a0, a1, a2);
        case 0x021bd0ULL: return fde_sub_021bd0(a0, a1, a2);
        case 0x021c00ULL: return fde_sub_021c00(a0, a1, a2);
        case 0x021c38ULL: return fde_sub_021c38(a0, a1, a2);
        case 0x021c40ULL: return fde_sub_021c40(a0, a1, a2);
        case 0x021c44ULL: return fde_sub_021c44(a0, a1, a2);
        case 0x021ce4ULL: return fde_sub_021ce4(a0, a1, a2);
        case 0x021d14ULL: return fde_sub_021d14(a0, a1, a2);
        case 0x021d4cULL: return fde_sub_021d4c(a0, a1, a2);
        case 0x021d58ULL: return fde_sub_021d58(a0, a1, a2);
        case 0x021d5cULL: return fde_sub_021d5c(a0, a1, a2);
        case 0x022178ULL: return fde_sub_022178(a0, a1, a2);
        case 0x02219cULL: return fde_sub_02219c(a0, a1, a2);
        case 0x023234ULL: return fde_sub_023234(a0, a1, a2);
        case 0x0235b8ULL: return fde_sub_0235b8(a0, a1, a2);
        case 0x023790ULL: return fde_sub_023790(a0, a1, a2);
        case 0x0238acULL: return fde_sub_0238ac(a0, a1, a2);
        case 0x0238dcULL: return fde_sub_0238dc(a0, a1, a2);
        case 0x0239c4ULL: return fde_sub_0239c4(a0, a1, a2);
        case 0x0239ccULL: return fde_sub_0239cc(a0, a1, a2);
        case 0x0239d4ULL: return fde_sub_0239d4(a0, a1, a2);
        case 0x0239f0ULL: return fde_sub_0239f0(a0, a1, a2);
        case 0x023aacULL: return fde_sub_023aac(a0, a1, a2);
        case 0x023becULL: return fde_sub_023bec(a0, a1, a2);
        case 0x023c88ULL: return fde_sub_023c88(a0, a1, a2);
        case 0x023db8ULL: return fde_sub_023db8(a0, a1, a2);
        case 0x023dc0ULL: return fde_sub_023dc0(a0, a1, a2);
        case 0x023f40ULL: return fde_sub_023f40(a0, a1, a2);
        case 0x024000ULL: return fde_sub_024000(a0, a1, a2);
        case 0x024008ULL: return fde_sub_024008(a0, a1, a2);
        case 0x024028ULL: return fde_sub_024028(a0, a1, a2);
        case 0x024030ULL: return fde_sub_024030(a0, a1, a2);
        case 0x024058ULL: return fde_sub_024058(a0, a1, a2);
        case 0x024114ULL: return fde_sub_024114(a0, a1, a2);
        case 0x02411cULL: return fde_sub_02411c(a0, a1, a2);
        case 0x0241bcULL: return fde_sub_0241bc(a0, a1, a2);
        case 0x0241c4ULL: return fde_sub_0241c4(a0, a1, a2);
        case 0x0241d0ULL: return fde_sub_0241d0(a0, a1, a2);
        case 0x0241d8ULL: return fde_sub_0241d8(a0, a1, a2);
        case 0x0241e0ULL: return fde_sub_0241e0(a0, a1, a2);
        case 0x024208ULL: return fde_sub_024208(a0, a1, a2);
        case 0x0242c8ULL: return fde_sub_0242c8(a0, a1, a2);
        case 0x0242d4ULL: return fde_sub_0242d4(a0, a1, a2);
        case 0x0242f8ULL: return fde_sub_0242f8(a0, a1, a2);
        case 0x024300ULL: return fde_sub_024300(a0, a1, a2);
        case 0x02454cULL: return fde_sub_02454c(a0, a1, a2);
        case 0x024550ULL: return fde_sub_024550(a0, a1, a2);
        case 0x024568ULL: return fde_sub_024568(a0, a1, a2);
        case 0x02456cULL: return fde_sub_02456c(a0, a1, a2);
        case 0x024570ULL: return fde_sub_024570(a0, a1, a2);
        case 0x024654ULL: return fde_sub_024654(a0, a1, a2);
        case 0x024b34ULL: return fde_sub_024b34(a0, a1, a2);
        case 0x024c68ULL: return fde_sub_024c68(a0, a1, a2);
        case 0x024f00ULL: return fde_sub_024f00(a0, a1, a2);
        case 0x024f64ULL: return fde_sub_024f64(a0, a1, a2);
        case 0x024fd8ULL: return fde_sub_024fd8(a0, a1, a2);
        case 0x024ffcULL: return fde_sub_024ffc(a0, a1, a2);
        case 0x025054ULL: return fde_sub_025054(a0, a1, a2);
        case 0x0250bcULL: return fde_sub_0250bc(a0, a1, a2);
        case 0x025138ULL: return fde_sub_025138(a0, a1, a2);
        case 0x025304ULL: return fde_sub_025304(a0, a1, a2);
        case 0x025450ULL: return fde_sub_025450(a0, a1, a2);
        case 0x02559cULL: return fde_sub_02559c(a0, a1, a2);
        case 0x0259e4ULL: return fde_sub_0259e4(a0, a1, a2);
        case 0x025ec4ULL: return fde_sub_025ec4(a0, a1, a2);
        case 0x025fc4ULL: return fde_sub_025fc4(a0, a1, a2);
        case 0x0260d0ULL: return fde_sub_0260d0(a0, a1, a2);
        case 0x0260ecULL: return fde_sub_0260ec(a0, a1, a2);
        case 0x026bb0ULL: return fde_sub_026bb0(a0, a1, a2);
        case 0x026f20ULL: return fde_sub_026f20(a0, a1, a2);
        case 0x026f24ULL: return fde_sub_026f24(a0, a1, a2);
        case 0x026f3cULL: return fde_sub_026f3c(a0, a1, a2);
        case 0x026f40ULL: return fde_sub_026f40(a0, a1, a2);
        case 0x026f44ULL: return fde_sub_026f44(a0, a1, a2);
        case 0x027040ULL: return fde_sub_027040(a0, a1, a2);
        case 0x027044ULL: return fde_sub_027044(a0, a1, a2);
        case 0x02705cULL: return fde_sub_02705c(a0, a1, a2);
        case 0x027060ULL: return fde_sub_027060(a0, a1, a2);
        case 0x027064ULL: return fde_sub_027064(a0, a1, a2);
        case 0x027368ULL: return fde_sub_027368(a0, a1, a2);
        case 0x0274a4ULL: return fde_sub_0274a4(a0, a1, a2);
        case 0x0274c4ULL: return fde_sub_0274c4(a0, a1, a2);
        case 0x027c68ULL: return fde_sub_027c68(a0, a1, a2);
        case 0x027cfcULL: return fde_sub_027cfc(a0, a1, a2);
        case 0x028018ULL: return fde_sub_028018(a0, a1, a2);
        case 0x028220ULL: return fde_sub_028220(a0, a1, a2);
        case 0x0285e4ULL: return fde_sub_0285e4(a0, a1, a2);
        case 0x028798ULL: return fde_sub_028798(a0, a1, a2);
        case 0x0289ecULL: return fde_sub_0289ec(a0, a1, a2);
        case 0x0289f0ULL: return fde_sub_0289f0(a0, a1, a2);
        case 0x028a08ULL: return fde_sub_028a08(a0, a1, a2);
        case 0x028a0cULL: return fde_sub_028a0c(a0, a1, a2);
        case 0x028a10ULL: return fde_sub_028a10(a0, a1, a2);
        case 0x028a18ULL: return fde_sub_028a18(a0, a1, a2);
        case 0x028de4ULL: return fde_sub_028de4(a0, a1, a2);
        case 0x0291e4ULL: return fde_sub_0291e4(a0, a1, a2);
        case 0x0295e4ULL: return fde_sub_0295e4(a0, a1, a2);
        case 0x029884ULL: return fde_sub_029884(a0, a1, a2);
        case 0x029918ULL: return fde_sub_029918(a0, a1, a2);
        case 0x029a34ULL: return fde_sub_029a34(a0, a1, a2);
        case 0x029c9cULL: return fde_sub_029c9c(a0, a1, a2);
        case 0x02a3dcULL: return fde_sub_02a3dc(a0, a1, a2);
        case 0x02ae1cULL: return fde_sub_02ae1c(a0, a1, a2);
        case 0x02b024ULL: return fde_sub_02b024(a0, a1, a2);
        case 0x02b164ULL: return fde_sub_02b164(a0, a1, a2);
        case 0x02b5d0ULL: return fde_sub_02b5d0(a0, a1, a2);
        case 0x02b8f0ULL: return fde_sub_02b8f0(a0, a1, a2);
        case 0x02ba08ULL: return fde_sub_02ba08(a0, a1, a2);
        case 0x02bc34ULL: return fde_sub_02bc34(a0, a1, a2);
        case 0x02bcccULL: return fde_sub_02bccc(a0, a1, a2);
        case 0x02bec8ULL: return fde_sub_02bec8(a0, a1, a2);
        case 0x02bed4ULL: return fde_sub_02bed4(a0, a1, a2);
        case 0x02bef8ULL: return fde_sub_02bef8(a0, a1, a2);
        case 0x02bff8ULL: return fde_sub_02bff8(a0, a1, a2);
        case 0x02c0f0ULL: return fde_sub_02c0f0(a0, a1, a2);
        case 0x02c1b0ULL: return fde_sub_02c1b0(a0, a1, a2);
        case 0x02c220ULL: return fde_sub_02c220(a0, a1, a2);
        case 0x02c4b8ULL: return fde_sub_02c4b8(a0, a1, a2);
        case 0x02c518ULL: return fde_sub_02c518(a0, a1, a2);
        case 0x02c784ULL: return fde_sub_02c784(a0, a1, a2);
        case 0x02c7bcULL: return fde_sub_02c7bc(a0, a1, a2);
        case 0x02c800ULL: return fde_sub_02c800(a0, a1, a2);
        default: return 0ULL;
    }
}

} // namespace TTKMediaNet
