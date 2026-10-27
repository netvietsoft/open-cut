// ============================================================================
// File: cxx_shared_fde_shard_5.cpp
// Target 111 / 169: libc++_shared.so (919,888 bytes)
// EN: Clean-room C++17 AArch64 FDE Shard 5/5 covering FDEs [1564..1952]
//     (PC range 0x0a6bf4 .. 0x0b6294).
// VI: Phân mảnh FDE AArch64 C++17 5/5 bao phủ FDE [1564..1952]
//     (Dải địa chỉ PC 0x0a6bf4 .. 0x0b6294).
// ============================================================================
#include "cxx_shared_core.h"

namespace ndk_libcxx_recon {

// FDE #1564 | PC: 0x0a6bf4..0x0a6c98 (164 B) | Symbol: sub_0a6bf4
// EN: AArch64 prologue [sub sp, sp, #0x110; stp x28, x19, [sp, #0xf0]; stp x29, x30, [sp, #0x100]; add x29, sp, #0x100] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; stp x28, x19, [sp, #0xf0]; stp x29, x30, [sp, #0x100]; add x29, sp, #0x100]
uint64_t fde_sub_0a6bf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90F4FFCULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A6BF4ULL;
}

// FDE #1565 | PC: 0x0a6c98..0x0a6ef0 (600 B) | Symbol: sub_0a6c98
// EN: AArch64 prologue [sub sp, sp, #0x70; str x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_0a6c98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F5ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0258ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A6C98ULL;
}

// FDE #1566 | PC: 0x0a6ef0..0x0a6ef4 (4 B) | Symbol: sub_0a6ef0
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0a6ef0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0x17FE8458ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A6EF0ULL;
}

// FDE #1567 | PC: 0x0a6ef4..0x0a712c (568 B) | Symbol: sub_0a6ef4
// EN: AArch64 prologue [sub sp, sp, #0x70; str x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_0a6ef4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F5ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0238ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A6EF4ULL;
}

// FDE #1568 | PC: 0x0a712c..0x0a7130 (4 B) | Symbol: sub_0a712c
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0a712c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE83C9ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A712CULL;
}

// FDE #1569 | PC: 0x0a7130..0x0a71e0 (176 B) | Symbol: sub_0a7130
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0a7130(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A7130ULL;
}

// FDE #1570 | PC: 0x0a71e0..0x0a71e4 (4 B) | Symbol: sub_0a71e0
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0a71e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE839CULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A71E0ULL;
}

// FDE #1571 | PC: 0x0a71e4..0x0a7238 (84 B) | Symbol: sub_0a71e4
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0a71e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A71E4ULL;
}

// FDE #1572 | PC: 0x0a7238..0x0a723c (4 B) | Symbol: sub_0a7238
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_0a7238(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FE8385ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A7238ULL;
}

// FDE #1573 | PC: 0x0a723c..0x0a7240 (4 B) | Symbol: sub_0a723c
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0a723c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0x17FE8385ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A723CULL;
}

// FDE #1574 | PC: 0x0a7240..0x0a77c4 (1412 B) | Symbol: sub_0a7240
// EN: AArch64 prologue [sub sp, sp, #0x60; str x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_0a7240(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0584ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A7240ULL;
}

// FDE #1575 | PC: 0x0a77c4..0x0a77c8 (4 B) | Symbol: sub_0a77c4
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0a77c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB67FAULL) << 32) | 0x17FE8223ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A77C4ULL;
}

// FDE #1576 | PC: 0x0a77c8..0x0a7918 (336 B) | Symbol: sub_0a77c8
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0a77c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x0150ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A77C8ULL;
}

// FDE #1577 | PC: 0x0a7918..0x0a791c (4 B) | Symbol: sub_0a7918
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0a7918(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE81CEULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A7918ULL;
}

// FDE #1578 | PC: 0x0a791c..0x0a7b34 (536 B) | Symbol: sub_0a791c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0a791c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0218ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A791CULL;
}

// FDE #1579 | PC: 0x0a7b34..0x0a7b38 (4 B) | Symbol: sub_0a7b34
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0a7b34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE8147ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A7B34ULL;
}

// FDE #1580 | PC: 0x0a7b38..0x0a7bec (180 B) | Symbol: sub_0a7b38
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0a7b38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A7B38ULL;
}

// FDE #1581 | PC: 0x0a7bec..0x0a7bf0 (4 B) | Symbol: sub_0a7bec
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0a7bec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE8119ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A7BECULL;
}

// FDE #1582 | PC: 0x0a7bf0..0x0a7cb8 (200 B) | Symbol: sub_0a7bf0
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0a7bf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A7BF0ULL;
}

// FDE #1583 | PC: 0x0a7cb8..0x0a7cbc (4 B) | Symbol: sub_0a7cb8
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0a7cb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB67FAULL) << 32) | 0x17FE80E6ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A7CB8ULL;
}

// FDE #1584 | PC: 0x0a7cbc..0x0a7e24 (360 B) | Symbol: sub_0a7cbc
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0a7cbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x0168ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A7CBCULL;
}

// FDE #1585 | PC: 0x0a7e24..0x0a7e28 (4 B) | Symbol: sub_0a7e24
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0a7e24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81C0FF7ULL) << 32) | 0x17FE808BULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A7E24ULL;
}

// FDE #1586 | PC: 0x0a7e28..0x0a7ef8 (208 B) | Symbol: sub_0a7e28
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0a7e28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A7E28ULL;
}

// FDE #1587 | PC: 0x0a7ef8..0x0a8088 (400 B) | Symbol: sub_0a7ef8
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0a7ef8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x0190ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A7EF8ULL;
}

// FDE #1588 | PC: 0x0a8088..0x0a808c (4 B) | Symbol: sub_0a8088
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0a8088(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE7FF2ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A8088ULL;
}

// FDE #1589 | PC: 0x0a808c..0x0a8174 (232 B) | Symbol: sub_0a808c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0a808c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A808CULL;
}

// FDE #1590 | PC: 0x0a8174..0x0a8178 (4 B) | Symbol: sub_0a8174
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0a8174(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD100C3FFULL) << 32) | 0x17FE7FB7ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A8174ULL;
}

// FDE #1591 | PC: 0x0a8178..0x0a8200 (136 B) | Symbol: sub_0a8178
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0a8178(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A8178ULL;
}

// FDE #1592 | PC: 0x0a8200..0x0a84d8 (728 B) | Symbol: sub_0a8200
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0a8200(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x02D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A8200ULL;
}

// FDE #1593 | PC: 0x0a84d8..0x0a86b8 (480 B) | Symbol: sub_0a84d8
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0a84d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x01E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A84D8ULL;
}

// FDE #1594 | PC: 0x0a86b8..0x0a877c (196 B) | Symbol: sub_0a86b8
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0a86b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A86B8ULL;
}

// FDE #1595 | PC: 0x0a877c..0x0a878c (16 B) | Symbol: sub_0a877c
// EN: AArch64 prologue [ldr x0, [x0, #0x18]; ldr x8, [x0]; ldr x1, [x8, #0x30]; br x1] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x18]; ldr x8, [x0]; ldr x1, [x8, #0x30]; br x1]
uint64_t fde_sub_0a877c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xF9400C00ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A877CULL;
}

// FDE #1596 | PC: 0x0a878c..0x0a8790 (4 B) | Symbol: sub_0a878c
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0a878c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC5FF8ULL) << 32) | 0x17FE7E31ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A878CULL;
}

// FDE #1597 | PC: 0x0a8790..0x0a9a38 (4776 B) | Symbol: sub_0a8790
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0a8790(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x12A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A8790ULL;
}

// FDE #1598 | PC: 0x0a9a38..0x0a9a94 (92 B) | Symbol: sub_0a9a38
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0a9a38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9A38ULL;
}

// FDE #1599 | PC: 0x0a9a94..0x0a9a98 (4 B) | Symbol: sub_0a9a94
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0a9a94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE796FULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9A94ULL;
}

// FDE #1600 | PC: 0x0a9a98..0x0a9b28 (144 B) | Symbol: sub_0a9a98
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0a9a98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9A98ULL;
}

// FDE #1601 | PC: 0x0a9b28..0x0a9b2c (4 B) | Symbol: sub_0a9b28
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0a9b28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE794AULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9B28ULL;
}

// FDE #1602 | PC: 0x0a9b2c..0x0a9bbc (144 B) | Symbol: sub_0a9b2c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0a9b2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9B2CULL;
}

// FDE #1603 | PC: 0x0a9bbc..0x0a9bc0 (4 B) | Symbol: sub_0a9bbc
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0a9bbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE7925ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9BBCULL;
}

// FDE #1604 | PC: 0x0a9bc0..0x0a9c50 (144 B) | Symbol: sub_0a9bc0
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0a9bc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9BC0ULL;
}

// FDE #1605 | PC: 0x0a9c50..0x0a9c60 (16 B) | Symbol: sub_0a9c50
// EN: AArch64 prologue [ldr x0, [x0, #0x10]; ldr x8, [x0]; ldr x1, [x8, #0x30]; br x1] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x10]; ldr x8, [x0]; ldr x1, [x8, #0x30]; br x1]
uint64_t fde_sub_0a9c50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xF9400800ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9C50ULL;
}

// FDE #1606 | PC: 0x0a9c60..0x0a9c64 (4 B) | Symbol: sub_0a9c60
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0a9c60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE78FCULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9C60ULL;
}

// FDE #1607 | PC: 0x0a9c64..0x0a9d10 (172 B) | Symbol: sub_0a9c64
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0a9c64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9C64ULL;
}

// FDE #1608 | PC: 0x0a9d10..0x0a9d14 (4 B) | Symbol: sub_0a9d10
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0a9d10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE78D0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9D10ULL;
}

// FDE #1609 | PC: 0x0a9d14..0x0a9e14 (256 B) | Symbol: sub_0a9d14
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0a9d14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9D14ULL;
}

// FDE #1610 | PC: 0x0a9e14..0x0a9e18 (4 B) | Symbol: sub_0a9e14
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0a9e14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE788FULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9E14ULL;
}

// FDE #1611 | PC: 0x0a9e18..0x0aa014 (508 B) | Symbol: sub_0a9e18
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0a9e18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x01FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0A9E18ULL;
}

// FDE #1612 | PC: 0x0aa014..0x0aa018 (4 B) | Symbol: sub_0aa014
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0aa014(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE780FULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA014ULL;
}

// FDE #1613 | PC: 0x0aa018..0x0aa1ec (468 B) | Symbol: sub_0aa018
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0aa018(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x01D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA018ULL;
}

// FDE #1614 | PC: 0x0aa1ec..0x0aa1f0 (4 B) | Symbol: sub_0aa1ec
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0aa1ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB67FAULL) << 32) | 0x17FE7799ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA1ECULL;
}

// FDE #1615 | PC: 0x0aa1f0..0x0aa3bc (460 B) | Symbol: sub_0aa1f0
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0aa1f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x01CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA1F0ULL;
}

// FDE #1616 | PC: 0x0aa3bc..0x0aa3c0 (4 B) | Symbol: sub_0aa3bc
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0aa3bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE7725ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA3BCULL;
}

// FDE #1617 | PC: 0x0aa3c0..0x0aa470 (176 B) | Symbol: sub_0aa3c0
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0aa3c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA3C0ULL;
}

// FDE #1618 | PC: 0x0aa470..0x0aa474 (4 B) | Symbol: sub_0aa470
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0aa470(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x17FE76F8ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA470ULL;
}

// FDE #1619 | PC: 0x0aa474..0x0aa7c8 (852 B) | Symbol: sub_0aa474
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0aa474(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0354ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA474ULL;
}

// FDE #1620 | PC: 0x0aa7c8..0x0aa7cc (4 B) | Symbol: sub_0aa7c8
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0aa7c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE7622ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA7C8ULL;
}

// FDE #1621 | PC: 0x0aa7cc..0x0aa844 (120 B) | Symbol: sub_0aa7cc
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0aa7cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA7CCULL;
}

// FDE #1622 | PC: 0x0aa844..0x0aa848 (4 B) | Symbol: sub_0aa844
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0aa844(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE7603ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA844ULL;
}

// FDE #1623 | PC: 0x0aa848..0x0aa9a4 (348 B) | Symbol: sub_0aa848
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0aa848(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x015CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA848ULL;
}

// FDE #1624 | PC: 0x0aa9a4..0x0aa9a8 (4 B) | Symbol: sub_0aa9a4
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0aa9a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x17FE75ABULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA9A4ULL;
}

// FDE #1625 | PC: 0x0aa9a8..0x0aaa4c (164 B) | Symbol: sub_0aa9a8
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_0aa9a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AA9A8ULL;
}

// FDE #1626 | PC: 0x0aaa4c..0x0aaa50 (4 B) | Symbol: sub_0aaa4c
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0aaa4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB67FAULL) << 32) | 0x17FE7581ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AAA4CULL;
}

// FDE #1627 | PC: 0x0aaa50..0x0aab40 (240 B) | Symbol: sub_0aaa50
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0aaa50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x00F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AAA50ULL;
}

// FDE #1628 | PC: 0x0aab40..0x0aab44 (4 B) | Symbol: sub_0aab40
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0aab40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE7544ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AAB40ULL;
}

// FDE #1629 | PC: 0x0aab44..0x0aabd4 (144 B) | Symbol: sub_0aab44
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0aab44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AAB44ULL;
}

// FDE #1630 | PC: 0x0aabd4..0x0aabd8 (4 B) | Symbol: sub_0aabd4
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0aabd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE751FULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AABD4ULL;
}

// FDE #1631 | PC: 0x0aabd8..0x0aac7c (164 B) | Symbol: sub_0aabd8
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0aabd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AABD8ULL;
}

// FDE #1632 | PC: 0x0aac7c..0x0aac80 (4 B) | Symbol: sub_0aac7c
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0aac7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE4FF4ULL) << 32) | 0x17FE74F5ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AAC7CULL;
}

// FDE #1633 | PC: 0x0aac80..0x0aad3c (188 B) | Symbol: sub_0aac80
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0xc]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0xc]]
uint64_t fde_sub_0aac80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AAC80ULL;
}

// FDE #1634 | PC: 0x0aad3c..0x0aadcc (144 B) | Symbol: sub_0aad3c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0xc]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0xc]]
uint64_t fde_sub_0aad3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AAD3CULL;
}

// FDE #1635 | PC: 0x0aadcc..0x0aadd0 (4 B) | Symbol: sub_0aadcc
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0aadcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE74A1ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AADCCULL;
}

// FDE #1636 | PC: 0x0aadd0..0x0aae48 (120 B) | Symbol: sub_0aadd0
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0aadd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AADD0ULL;
}

// FDE #1637 | PC: 0x0aae48..0x0aae4c (4 B) | Symbol: sub_0aae48
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0aae48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE7482ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AAE48ULL;
}

// FDE #1638 | PC: 0x0aae4c..0x0aaed4 (136 B) | Symbol: sub_0aae4c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0aae4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AAE4CULL;
}

// FDE #1639 | PC: 0x0aaed4..0x0aaed8 (4 B) | Symbol: sub_0aaed4
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0aaed4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE745FULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AAED4ULL;
}

// FDE #1640 | PC: 0x0aaed8..0x0aaf50 (120 B) | Symbol: sub_0aaed8
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0aaed8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AAED8ULL;
}

// FDE #1641 | PC: 0x0aaf50..0x0aaf54 (4 B) | Symbol: sub_0aaf50
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0aaf50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB67FAULL) << 32) | 0x17FE7440ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AAF50ULL;
}

// FDE #1642 | PC: 0x0aaf54..0x0ab0b8 (356 B) | Symbol: sub_0aaf54
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0aaf54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x0164ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AAF54ULL;
}

// FDE #1643 | PC: 0x0ab0b8..0x0ab0bc (4 B) | Symbol: sub_0ab0b8
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0ab0b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB67FAULL) << 32) | 0x17FE73E6ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB0B8ULL;
}

// FDE #1644 | PC: 0x0ab0bc..0x0ab24c (400 B) | Symbol: sub_0ab0bc
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0ab0bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x0190ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB0BCULL;
}

// FDE #1645 | PC: 0x0ab24c..0x0ab250 (4 B) | Symbol: sub_0ab24c
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0ab24c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE7381ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB24CULL;
}

// FDE #1646 | PC: 0x0ab250..0x0ab314 (196 B) | Symbol: sub_0ab250
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0ab250(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB250ULL;
}

// FDE #1647 | PC: 0x0ab314..0x0ab318 (4 B) | Symbol: sub_0ab314
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0ab314(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE4FF4ULL) << 32) | 0x17FE734FULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB314ULL;
}

// FDE #1648 | PC: 0x0ab318..0x0ab3d4 (188 B) | Symbol: sub_0ab318
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0xc]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0xc]]
uint64_t fde_sub_0ab318(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB318ULL;
}

// FDE #1649 | PC: 0x0ab3d4..0x0ab474 (160 B) | Symbol: sub_0ab3d4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0xc]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0xc]]
uint64_t fde_sub_0ab3d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB3D4ULL;
}

// FDE #1650 | PC: 0x0ab474..0x0ab478 (4 B) | Symbol: sub_0ab474
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0ab474(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9401C28ULL) << 32) | 0x17FE72F7ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB474ULL;
}

// FDE #1651 | PC: 0x0ab478..0x0ab4dc (100 B) | Symbol: sub_0ab478
// EN: AArch64 prologue [ldr w8, [x1, #0x1c]; cmn w8, #1; b.eq #0xab4b4; ldr w8, [x1, #0x18]] | VI: Khởi đầu hàm AArch64 [ldr w8, [x1, #0x1c]; cmn w8, #1; b.eq #0xab4b4; ldr w8, [x1, #0x18]]
uint64_t fde_sub_0ab478(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3100051FULL) << 32) | 0xB9401C28ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB478ULL;
}

// FDE #1652 | PC: 0x0ab4dc..0x0ab540 (100 B) | Symbol: sub_0ab4dc
// EN: AArch64 prologue [ldr w8, [x1, #0x1c]; cmn w8, #1; b.eq #0xab518; ldr w8, [x1, #0x18]] | VI: Khởi đầu hàm AArch64 [ldr w8, [x1, #0x1c]; cmn w8, #1; b.eq #0xab518; ldr w8, [x1, #0x18]]
uint64_t fde_sub_0ab4dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3100051FULL) << 32) | 0xB9401C28ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB4DCULL;
}

// FDE #1653 | PC: 0x0ab540..0x0ab5a4 (100 B) | Symbol: sub_0ab540
// EN: AArch64 prologue [ldr w8, [x1, #0x1c]; cmn w8, #1; b.eq #0xab57c; ldr w8, [x1, #0x18]] | VI: Khởi đầu hàm AArch64 [ldr w8, [x1, #0x1c]; cmn w8, #1; b.eq #0xab57c; ldr w8, [x1, #0x18]]
uint64_t fde_sub_0ab540(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3100051FULL) << 32) | 0xB9401C28ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB540ULL;
}

// FDE #1654 | PC: 0x0ab5a4..0x0ab5ec (72 B) | Symbol: sub_0ab5a4
// EN: AArch64 prologue [ldr w8, [x1, #0x1c]; cmn w8, #1; b.eq #0xab5d4; ldr w8, [x1, #0x18]] | VI: Khởi đầu hàm AArch64 [ldr w8, [x1, #0x1c]; cmn w8, #1; b.eq #0xab5d4; ldr w8, [x1, #0x18]]
uint64_t fde_sub_0ab5a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3100051FULL) << 32) | 0xB9401C28ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB5A4ULL;
}

// FDE #1655 | PC: 0x0ab5ec..0x0ab634 (72 B) | Symbol: sub_0ab5ec
// EN: AArch64 prologue [ldr w8, [x1, #0x1c]; cmn w8, #1; b.eq #0xab61c; ldr w8, [x1, #0x18]] | VI: Khởi đầu hàm AArch64 [ldr w8, [x1, #0x1c]; cmn w8, #1; b.eq #0xab61c; ldr w8, [x1, #0x18]]
uint64_t fde_sub_0ab5ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3100051FULL) << 32) | 0xB9401C28ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB5ECULL;
}

// FDE #1656 | PC: 0x0ab634..0x0ab67c (72 B) | Symbol: sub_0ab634
// EN: AArch64 prologue [ldr w8, [x1, #0x1c]; cmn w8, #1; b.eq #0xab664; ldr w8, [x1, #0x18]] | VI: Khởi đầu hàm AArch64 [ldr w8, [x1, #0x1c]; cmn w8, #1; b.eq #0xab664; ldr w8, [x1, #0x18]]
uint64_t fde_sub_0ab634(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3100051FULL) << 32) | 0xB9401C28ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB634ULL;
}

// FDE #1657 | PC: 0x0ab67c..0x0ab680 (4 B) | Symbol: sub_0ab67c
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0ab67c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB67FAULL) << 32) | 0x17FE7275ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB67CULL;
}

// FDE #1658 | PC: 0x0ab680..0x0ab7f4 (372 B) | Symbol: sub_0ab680
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0ab680(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x0174ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB680ULL;
}

// FDE #1659 | PC: 0x0ab7f4..0x0ab7f8 (4 B) | Symbol: sub_0ab7f4
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0ab7f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE7217ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB7F4ULL;
}

// FDE #1660 | PC: 0x0ab7f8..0x0ab898 (160 B) | Symbol: sub_0ab7f8
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0ab7f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB7F8ULL;
}

// FDE #1661 | PC: 0x0ab898..0x0ab8a8 (16 B) | Symbol: sub_0ab898
// EN: AArch64 prologue [ldr x0, [x0, #0x10]; ldr x8, [x0]; ldr x1, [x8, #0x30]; br x1] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x10]; ldr x8, [x0]; ldr x1, [x8, #0x30]; br x1]
uint64_t fde_sub_0ab898(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xF9400800ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB898ULL;
}

// FDE #1662 | PC: 0x0ab8a8..0x0ab8ac (4 B) | Symbol: sub_0ab8a8
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0ab8a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE71EAULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB8A8ULL;
}

// FDE #1663 | PC: 0x0ab8ac..0x0ab93c (144 B) | Symbol: sub_0ab8ac
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0ab8ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB8ACULL;
}

// FDE #1664 | PC: 0x0ab93c..0x0ab94c (16 B) | Symbol: sub_0ab93c
// EN: AArch64 prologue [ldr x0, [x0, #0x10]; ldr x8, [x0]; ldr x1, [x8, #0x30]; br x1] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x10]; ldr x8, [x0]; ldr x1, [x8, #0x30]; br x1]
uint64_t fde_sub_0ab93c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xF9400800ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB93CULL;
}

// FDE #1665 | PC: 0x0ab94c..0x0ab950 (4 B) | Symbol: sub_0ab94c
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0ab94c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB67FAULL) << 32) | 0x17FE71C1ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB94CULL;
}

// FDE #1666 | PC: 0x0ab950..0x0aba40 (240 B) | Symbol: sub_0ab950
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0ab950(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x00F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AB950ULL;
}

// FDE #1667 | PC: 0x0aba40..0x0aba44 (4 B) | Symbol: sub_0aba40
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0aba40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB67FAULL) << 32) | 0x17FE7184ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ABA40ULL;
}

// FDE #1668 | PC: 0x0aba44..0x0abbac (360 B) | Symbol: sub_0aba44
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0aba44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x0168ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ABA44ULL;
}

// FDE #1669 | PC: 0x0abbac..0x0abbb0 (4 B) | Symbol: sub_0abbac
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0abbac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800020ULL) << 32) | 0x17FE7129ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ABBACULL;
}

// FDE #1670 | PC: 0x0abbb0..0x0abbb8 (8 B) | Symbol: sub_0abbb0
// EN: AArch64 prologue [mov w0, #1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #1; ret]
uint64_t fde_sub_0abbb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ABBB0ULL;
}

// FDE #1671 | PC: 0x0abbb8..0x0abbc0 (8 B) | Symbol: sub_0abbb8
// EN: AArch64 prologue [mov w0, #1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #1; ret]
uint64_t fde_sub_0abbb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ABBB8ULL;
}

// FDE #1672 | PC: 0x0abbc0..0x0abc90 (208 B) | Symbol: sub_0abbc0
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0abbc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ABBC0ULL;
}

// FDE #1673 | PC: 0x0abc90..0x0abf08 (632 B) | Symbol: sub_0abc90
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0abc90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x0278ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ABC90ULL;
}

// FDE #1674 | PC: 0x0abf08..0x0abf0c (4 B) | Symbol: sub_0abf08
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0abf08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE7052ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ABF08ULL;
}

// FDE #1675 | PC: 0x0abf0c..0x0abfb8 (172 B) | Symbol: sub_0abf0c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0abf0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ABF0CULL;
}

// FDE #1676 | PC: 0x0abfb8..0x0abfbc (4 B) | Symbol: sub_0abfb8
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0abfb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0x17FE7026ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ABFB8ULL;
}

// FDE #1677 | PC: 0x0abfbc..0x0ac5d0 (1556 B) | Symbol: sub_0abfbc
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0abfbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0614ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ABFBCULL;
}

// FDE #1678 | PC: 0x0ac5d0..0x0ac990 (960 B) | Symbol: sub_0ac5d0
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0ac5d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x03C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AC5D0ULL;
}

// FDE #1679 | PC: 0x0ac990..0x0acb98 (520 B) | Symbol: sub_0ac990
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0ac990(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0208ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AC990ULL;
}

// FDE #1680 | PC: 0x0acb98..0x0acc3c (164 B) | Symbol: sub_0acb98
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0acb98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ACB98ULL;
}

// FDE #1681 | PC: 0x0acc3c..0x0acc40 (4 B) | Symbol: sub_0acc3c
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0acc3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB67FAULL) << 32) | 0x17FE6D05ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ACC3CULL;
}

// FDE #1682 | PC: 0x0acc40..0x0acda8 (360 B) | Symbol: sub_0acc40
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0acc40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x0168ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ACC40ULL;
}

// FDE #1683 | PC: 0x0acda8..0x0acdac (4 B) | Symbol: sub_0acda8
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0acda8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800020ULL) << 32) | 0x17FE6CAAULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ACDA8ULL;
}

// FDE #1684 | PC: 0x0acdac..0x0acdb4 (8 B) | Symbol: sub_0acdac
// EN: AArch64 prologue [mov w0, #1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #1; ret]
uint64_t fde_sub_0acdac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ACDACULL;
}

// FDE #1685 | PC: 0x0acdb4..0x0acdbc (8 B) | Symbol: sub_0acdb4
// EN: AArch64 prologue [mov w0, #1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #1; ret]
uint64_t fde_sub_0acdb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ACDB4ULL;
}

// FDE #1686 | PC: 0x0acdbc..0x0ace08 (76 B) | Symbol: sub_0acdbc
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x0, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x0, [x0, #0x10]]
uint64_t fde_sub_0acdbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ACDBCULL;
}

// FDE #1687 | PC: 0x0ace08..0x0ad0d0 (712 B) | Symbol: sub_0ace08
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0ace08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x02C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ACE08ULL;
}

// FDE #1688 | PC: 0x0ad0d0..0x0ad0d4 (4 B) | Symbol: sub_0ad0d0
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0ad0d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE6BE0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD0D0ULL;
}

// FDE #1689 | PC: 0x0ad0d4..0x0ad180 (172 B) | Symbol: sub_0ad0d4
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0ad0d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD0D4ULL;
}

// FDE #1690 | PC: 0x0ad180..0x0ad184 (4 B) | Symbol: sub_0ad180
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0ad180(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE6BB4ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD180ULL;
}

// FDE #1691 | PC: 0x0ad184..0x0ad20c (136 B) | Symbol: sub_0ad184
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0ad184(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD184ULL;
}

// FDE #1692 | PC: 0x0ad20c..0x0ad210 (4 B) | Symbol: sub_0ad20c
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0ad20c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400800ULL) << 32) | 0x17FE6B91ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD20CULL;
}

// FDE #1693 | PC: 0x0ad210..0x0ad238 (40 B) | Symbol: sub_0ad210
// EN: AArch64 prologue [ldr x0, [x0, #0x10]; ldrb w8, [x0, #9]; cmp w8, #2; b.ne #0xad22c] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x10]; ldrb w8, [x0, #9]; cmp w8, #2; b.ne #0xad22c]
uint64_t fde_sub_0ad210(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39402408ULL) << 32) | 0xF9400800ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD210ULL;
}

// FDE #1694 | PC: 0x0ad238..0x0ad260 (40 B) | Symbol: sub_0ad238
// EN: AArch64 prologue [ldr x0, [x0, #0x10]; ldrb w8, [x0, #0xa]; cmp w8, #2; b.ne #0xad254] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x10]; ldrb w8, [x0, #0xa]; cmp w8, #2; b.ne #0xad254]
uint64_t fde_sub_0ad238(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39402808ULL) << 32) | 0xF9400800ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD238ULL;
}

// FDE #1695 | PC: 0x0ad260..0x0ad288 (40 B) | Symbol: sub_0ad260
// EN: AArch64 prologue [ldr x0, [x0, #0x10]; ldrb w8, [x0, #0xb]; cmp w8, #2; b.ne #0xad27c] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x10]; ldrb w8, [x0, #0xb]; cmp w8, #2; b.ne #0xad27c]
uint64_t fde_sub_0ad260(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39402C08ULL) << 32) | 0xF9400800ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD260ULL;
}

// FDE #1696 | PC: 0x0ad288..0x0ad358 (208 B) | Symbol: sub_0ad288
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0ad288(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD288ULL;
}

// FDE #1697 | PC: 0x0ad358..0x0ad368 (16 B) | Symbol: sub_0ad358
// EN: AArch64 prologue [ldr x0, [x0, #0x10]; ldr x8, [x0]; ldr x2, [x8, #0x28]; br x2] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x10]; ldr x8, [x0]; ldr x2, [x8, #0x28]; br x2]
uint64_t fde_sub_0ad358(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xF9400800ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD358ULL;
}

// FDE #1698 | PC: 0x0ad368..0x0ad36c (4 B) | Symbol: sub_0ad368
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0ad368(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE6B3AULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD368ULL;
}

// FDE #1699 | PC: 0x0ad36c..0x0ad3e4 (120 B) | Symbol: sub_0ad36c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0ad36c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD36CULL;
}

// FDE #1700 | PC: 0x0ad3e4..0x0ad3e8 (4 B) | Symbol: sub_0ad3e4
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0ad3e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81D0FF5ULL) << 32) | 0x17FE6B1BULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD3E4ULL;
}

// FDE #1701 | PC: 0x0ad3e8..0x0ad4dc (244 B) | Symbol: sub_0ad3e8
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0ad3e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD3E8ULL;
}

// FDE #1702 | PC: 0x0ad4dc..0x0ad4e0 (4 B) | Symbol: sub_0ad4dc
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0ad4dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800020ULL) << 32) | 0x17FE6ADDULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD4DCULL;
}

// FDE #1703 | PC: 0x0ad4e0..0x0ad4e8 (8 B) | Symbol: sub_0ad4e0
// EN: AArch64 prologue [mov w0, #1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #1; ret]
uint64_t fde_sub_0ad4e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD4E0ULL;
}

// FDE #1704 | PC: 0x0ad4e8..0x0ad4f0 (8 B) | Symbol: sub_0ad4e8
// EN: AArch64 prologue [mov w0, #1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #1; ret]
uint64_t fde_sub_0ad4e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD4E8ULL;
}

// FDE #1705 | PC: 0x0ad4f0..0x0ad500 (16 B) | Symbol: sub_0ad4f0
// EN: AArch64 prologue [ldr x0, [x0, #0x10]; ldr x8, [x0]; ldr x2, [x8, #0x20]; br x2] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x10]; ldr x8, [x0]; ldr x2, [x8, #0x20]; br x2]
uint64_t fde_sub_0ad4f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xF9400800ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD4F0ULL;
}

// FDE #1706 | PC: 0x0ad500..0x0ad618 (280 B) | Symbol: sub_0ad500
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0ad500(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0118ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD500ULL;
}

// FDE #1707 | PC: 0x0ad618..0x0ad61c (4 B) | Symbol: sub_0ad618
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0ad618(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400C00ULL) << 32) | 0x17FE6A8EULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD618ULL;
}

// FDE #1708 | PC: 0x0ad61c..0x0ad644 (40 B) | Symbol: sub_0ad61c
// EN: AArch64 prologue [ldr x0, [x0, #0x18]; ldrb w8, [x0, #9]; cmp w8, #2; b.ne #0xad638] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x18]; ldrb w8, [x0, #9]; cmp w8, #2; b.ne #0xad638]
uint64_t fde_sub_0ad61c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39402408ULL) << 32) | 0xF9400C00ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD61CULL;
}

// FDE #1709 | PC: 0x0ad644..0x0ad754 (272 B) | Symbol: sub_0ad644
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0ad644(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0110ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD644ULL;
}

// FDE #1710 | PC: 0x0ad754..0x0ad800 (172 B) | Symbol: sub_0ad754
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0ad754(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD754ULL;
}

// FDE #1711 | PC: 0x0ad800..0x0ad804 (4 B) | Symbol: sub_0ad800
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0ad800(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE4FF4ULL) << 32) | 0x17FE6A14ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD800ULL;
}

// FDE #1712 | PC: 0x0ad804..0x0ad8c4 (192 B) | Symbol: sub_0ad804
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldp x8, x2, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldp x8, x2, [x0, #0x10]]
uint64_t fde_sub_0ad804(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD804ULL;
}

// FDE #1713 | PC: 0x0ad8c4..0x0ad8c8 (4 B) | Symbol: sub_0ad8c4
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0ad8c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400800ULL) << 32) | 0x17FE69E3ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD8C4ULL;
}

// FDE #1714 | PC: 0x0ad8c8..0x0ad8f0 (40 B) | Symbol: sub_0ad8c8
// EN: AArch64 prologue [ldr x0, [x0, #0x10]; ldrb w8, [x0, #9]; cmp w8, #2; b.ne #0xad8e4] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x10]; ldrb w8, [x0, #9]; cmp w8, #2; b.ne #0xad8e4]
uint64_t fde_sub_0ad8c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39402408ULL) << 32) | 0xF9400800ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD8C8ULL;
}

// FDE #1715 | PC: 0x0ad8f0..0x0adabc (460 B) | Symbol: sub_0ad8f0
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0ad8f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x01CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AD8F0ULL;
}

// FDE #1716 | PC: 0x0adabc..0x0adbe8 (300 B) | Symbol: sub_0adabc
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0adabc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ADABCULL;
}

// FDE #1717 | PC: 0x0adbe8..0x0adbec (4 B) | Symbol: sub_0adbe8
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0adbe8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400800ULL) << 32) | 0x17FE691AULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ADBE8ULL;
}

// FDE #1718 | PC: 0x0adbec..0x0adc14 (40 B) | Symbol: sub_0adbec
// EN: AArch64 prologue [ldr x0, [x0, #0x10]; ldrb w8, [x0, #9]; cmp w8, #2; b.ne #0xadc08] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x10]; ldrb w8, [x0, #9]; cmp w8, #2; b.ne #0xadc08]
uint64_t fde_sub_0adbec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39402408ULL) << 32) | 0xF9400800ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ADBECULL;
}

// FDE #1719 | PC: 0x0adc14..0x0addbc (424 B) | Symbol: sub_0adc14
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0adc14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x01A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ADC14ULL;
}

// FDE #1720 | PC: 0x0addbc..0x0adecc (272 B) | Symbol: sub_0addbc
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0addbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0110ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ADDBCULL;
}

// FDE #1721 | PC: 0x0adecc..0x0aded0 (4 B) | Symbol: sub_0adecc
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0adecc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE4FF4ULL) << 32) | 0x17FE6861ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ADECCULL;
}

// FDE #1722 | PC: 0x0aded0..0x0adf08 (56 B) | Symbol: sub_0aded0
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0aded0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ADED0ULL;
}

// FDE #1723 | PC: 0x0adf08..0x0adf0c (4 B) | Symbol: sub_0adf08
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0adf08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10043FFULL) << 32) | 0x17FE6852ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ADF08ULL;
}

// FDE #1724 | PC: 0x0adf0c..0x0adf20 (20 B) | Symbol: _ZN10__cxxabiv119__setExceptionClassEP17_Unwind_Exceptionm
// EN: AArch64 prologue [sub sp, sp, #0x10; str x1, [sp, #8]; str x1, [x0]; add sp, sp, #0x10] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x10; str x1, [sp, #8]; str x1, [x0]; add sp, sp, #0x10]
uint64_t fde_sub_0adf0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90007E1ULL) << 32) | 0xD10043FFULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ADF0CULL;
}

// FDE #1725 | PC: 0x0adf20..0x0adf28 (8 B) | Symbol: _ZN10__cxxabiv119__getExceptionClassEPK17_Unwind_Exception
// EN: AArch64 prologue [ldr x0, [x0]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0]; ret]
uint64_t fde_sub_0adf20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF9400000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ADF20ULL;
}

// FDE #1726 | PC: 0x0adf28..0x0adf48 (32 B) | Symbol: _ZN10__cxxabiv121__isOurExceptionClassEPK17_Unwind_Exception
// EN: AArch64 prologue [ldr x8, [x0]; mov x9, #0x2b2b; movk x9, #0x4743, lsl #16; movk x9, #0x4c4e, lsl #32] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; mov x9, #0x2b2b; movk x9, #0x4743, lsl #16; movk x9, #0x4c4e, lsl #32]
uint64_t fde_sub_0adf28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD2856569ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ADF28ULL;
}

// FDE #1727 | PC: 0x0adf48..0x0adf94 (76 B) | Symbol: __cxa_allocate_exception
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; add x8, x0, #0x8f] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; add x8, x0, #0x8f]
uint64_t fde_sub_0adf48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ADF48ULL;
}

// FDE #1728 | PC: 0x0adf94..0x0adfb0 (28 B) | Symbol: __cxa_free_exception
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x0, x0, #0x80; bl #0xb0460] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x0, x0, #0x80; bl #0xb0460]
uint64_t fde_sub_0adf94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ADF94ULL;
}

// FDE #1729 | PC: 0x0adfb0..0x0adfe4 (52 B) | Symbol: __cxa_allocate_dependent_exception
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w0, #0x80; bl #0xb02a4] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w0, #0x80; bl #0xb02a4]
uint64_t fde_sub_0adfb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ADFB0ULL;
}

// FDE #1730 | PC: 0x0adfe4..0x0adfe8 (4 B) | Symbol: __cxa_free_dependent_exception
// EN: AArch64 prologue [b #0xb0460] | VI: Khởi đầu hàm AArch64 [b #0xb0460]
uint64_t fde_sub_0adfe4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD57F6ULL) << 32) | 0x1400091FULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ADFE4ULL;
}

// FDE #1731 | PC: 0x0adfe8..0x0ae05c (116 B) | Symbol: __cxa_throw
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0adfe8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0ADFE8ULL;
}

// FDE #1732 | PC: 0x0ae05c..0x0ae080 (36 B) | Symbol: sub_0ae05c
// EN: AArch64 prologue [sub sp, sp, #0x10; mov x8, #0x2b00; movk x8, #0x432b, lsl #16; movk x8, #0x4e47, lsl #32] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x10; mov x8, #0x2b00; movk x8, #0x432b, lsl #16; movk x8, #0x4e47, lsl #32]
uint64_t fde_sub_0ae05c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD2856008ULL) << 32) | 0xD10043FFULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AE05CULL;
}

// FDE #1733 | PC: 0x0ae080..0x0ae0e0 (96 B) | Symbol: sub_0ae080
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cmp w0, #1] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cmp w0, #1]
uint64_t fde_sub_0ae080(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AE080ULL;
}

// FDE #1734 | PC: 0x0ae0e0..0x0ae100 (32 B) | Symbol: sub_0ae0e0
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0ae0e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AE0E0ULL;
}

// FDE #1735 | PC: 0x0ae100..0x0ae108 (8 B) | Symbol: __cxa_get_exception_ptr
// EN: AArch64 prologue [ldur x0, [x0, #-0x10]; ret] | VI: Khởi đầu hàm AArch64 [ldur x0, [x0, #-0x10]; ret]
uint64_t fde_sub_0ae100(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF85F0000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AE100ULL;
}

// FDE #1736 | PC: 0x0ae108..0x0ae19c (148 B) | Symbol: __cxa_begin_catch
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0]]
uint64_t fde_sub_0ae108(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AE108ULL;
}

// FDE #1737 | PC: 0x0ae19c..0x0ae278 (220 B) | Symbol: __cxa_end_catch
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x470d0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x470d0]
uint64_t fde_sub_0ae19c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AE19CULL;
}

// FDE #1738 | PC: 0x0ae278..0x0ae2c8 (80 B) | Symbol: __cxa_decrement_exception_refcount
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0xae2b4] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0xae2b4]
uint64_t fde_sub_0ae278(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AE278ULL;
}

// FDE #1739 | PC: 0x0ae2c8..0x0ae314 (76 B) | Symbol: __cxa_current_exception_type
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x470d0; cbz x0, #0xae300] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x470d0; cbz x0, #0xae300]
uint64_t fde_sub_0ae2c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AE2C8ULL;
}

// FDE #1740 | PC: 0x0ae314..0x0ae3f8 (228 B) | Symbol: __cxa_rethrow
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0ae314(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AE314ULL;
}

// FDE #1741 | PC: 0x0ae3f8..0x0ae414 (28 B) | Symbol: __cxa_increment_exception_refcount
// EN: AArch64 prologue [cbz x0, #0xae410; sub x8, x0, #0x80; ldaxr x9, [x8]; add x9, x9, #1] | VI: Khởi đầu hàm AArch64 [cbz x0, #0xae410; sub x8, x0, #0x80; ldaxr x9, [x8]; add x9, x9, #1]
uint64_t fde_sub_0ae3f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD1020008ULL) << 32) | 0xB40000C0ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AE3F8ULL;
}

// FDE #1742 | PC: 0x0ae414..0x0ae488 (116 B) | Symbol: __cxa_current_primary_exception
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x470d0; cbz x0, #0xae470] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x470d0; cbz x0, #0xae470]
uint64_t fde_sub_0ae414(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AE414ULL;
}

// FDE #1743 | PC: 0x0ae488..0x0ae5a8 (288 B) | Symbol: __cxa_rethrow_primary_exception
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0ae488(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0120ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AE488ULL;
}

// FDE #1744 | PC: 0x0ae5a8..0x0ae614 (108 B) | Symbol: sub_0ae5a8
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cmp w0, #1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cmp w0, #1]
uint64_t fde_sub_0ae5a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AE5A8ULL;
}

// FDE #1745 | PC: 0x0ae614..0x0ae63c (40 B) | Symbol: __cxa_uncaught_exception
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x470d0; cbz x0, #0xae630] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x470d0; cbz x0, #0xae630]
uint64_t fde_sub_0ae614(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AE614ULL;
}

// FDE #1746 | PC: 0x0ae63c..0x0ae65c (32 B) | Symbol: __cxa_uncaught_exceptions
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x470d0; cbz x0, #0xae650] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x470d0; cbz x0, #0xae650]
uint64_t fde_sub_0ae63c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AE63CULL;
}

// FDE #1747 | PC: 0x0ae65c..0x0ae6ec (144 B) | Symbol: __cxa_get_globals
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x0, #0xe6000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x0, #0xe6000]
uint64_t fde_sub_0ae65c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AE65CULL;
}

// FDE #1748 | PC: 0x0ae6ec..0x0ae728 (60 B) | Symbol: __cxa_get_globals_fast
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0xe6000; adrp x1, #0xae000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0xe6000; adrp x1, #0xae000]
uint64_t fde_sub_0ae6ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AE6ECULL;
}

// FDE #1749 | PC: 0x0ae728..0x0ae75c (52 B) | Symbol: sub_0ae728
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0xe6000; adrp x1, #0xae000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0xe6000; adrp x1, #0xae000]
uint64_t fde_sub_0ae728(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AE728ULL;
}

// FDE #1750 | PC: 0x0ae75c..0x0ae790 (52 B) | Symbol: sub_0ae75c
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xb0584; adrp x8, #0xe6000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xb0584; adrp x8, #0xe6000]
uint64_t fde_sub_0ae75c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AE75CULL;
}

// FDE #1751 | PC: 0x0ae790..0x0ae8f0 (352 B) | Symbol: __cxa_guard_acquire
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0ae790(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0160ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AE790ULL;
}

// FDE #1752 | PC: 0x0ae8f0..0x0ae998 (168 B) | Symbol: __cxa_guard_release
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0ae8f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AE8F0ULL;
}

// FDE #1753 | PC: 0x0ae998..0x0aea34 (156 B) | Symbol: __cxa_guard_abort
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0ae998(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AE998ULL;
}

// FDE #1754 | PC: 0x0aea34..0x0aea44 (16 B) | Symbol: _ZSt14get_unexpectedv
// EN: AArch64 prologue [adrp x8, #0xe3000; ldr x8, [x8, #0xf40]; ldar x0, [x8]; ret] | VI: Khởi đầu hàm AArch64 [adrp x8, #0xe3000; ldr x8, [x8, #0xf40]; ldar x0, [x8]; ret]
uint64_t fde_sub_0aea34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF947A108ULL) << 32) | 0xB00001A8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AEA34ULL;
}

// FDE #1755 | PC: 0x0aea44..0x0aea84 (64 B) | Symbol: _ZSt9terminatev
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x470d0; cbz x0, #0xaea6c; ldr x19, [x0]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x470d0; cbz x0, #0xaea6c; ldr x19, [x0]]
uint64_t fde_sub_0aea44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x97FE61A2ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AEA44ULL;
}

// FDE #1756 | PC: 0x0aea84..0x0aea9c (24 B) | Symbol: sub_0aea84
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; blr x0; adrp x0, #0xbb000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; blr x0; adrp x0, #0xbb000]
uint64_t fde_sub_0aea84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AEA84ULL;
}

// FDE #1757 | PC: 0x0aea9c..0x0aeab4 (24 B) | Symbol: _ZSt10unexpectedv
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xe3000; ldr x8, [x8, #0xf40]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xe3000; ldr x8, [x8, #0xf40]]
uint64_t fde_sub_0aea9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AEA9CULL;
}

// FDE #1758 | PC: 0x0aeab4..0x0aeac4 (16 B) | Symbol: _ZSt13get_terminatev
// EN: AArch64 prologue [adrp x8, #0xe3000; ldr x8, [x8, #0xab0]; ldar x0, [x8]; ret] | VI: Khởi đầu hàm AArch64 [adrp x8, #0xe3000; ldr x8, [x8, #0xab0]; ldar x0, [x8]; ret]
uint64_t fde_sub_0aeab4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9455908ULL) << 32) | 0xB00001A8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AEAB4ULL;
}

// FDE #1759 | PC: 0x0aeac4..0x0aeb04 (64 B) | Symbol: sub_0aeac4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; blr x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; blr x0]
uint64_t fde_sub_0aeac4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AEAC4ULL;
}

// FDE #1760 | PC: 0x0aeb04..0x0aeb20 (28 B) | Symbol: _ZSt15set_new_handlerPFvvE
// EN: AArch64 prologue [adrp x9, #0xe3000; ldr x9, [x9, #0xe30]; ldaxr x8, [x9]; stlxr w10, x0, [x9]] | VI: Khởi đầu hàm AArch64 [adrp x9, #0xe3000; ldr x9, [x9, #0xe30]; ldaxr x8, [x9]; stlxr w10, x0, [x9]]
uint64_t fde_sub_0aeb04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9471929ULL) << 32) | 0xB00001A9ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AEB04ULL;
}

// FDE #1761 | PC: 0x0aeb20..0x0aeb30 (16 B) | Symbol: _ZSt15get_new_handlerv
// EN: AArch64 prologue [adrp x8, #0xe3000; ldr x8, [x8, #0xe30]; ldar x0, [x8]; ret] | VI: Khởi đầu hàm AArch64 [adrp x8, #0xe3000; ldr x8, [x8, #0xe30]; ldar x0, [x8]; ret]
uint64_t fde_sub_0aeb20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9471908ULL) << 32) | 0xB00001A8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AEB20ULL;
}

// FDE #1762 | PC: 0x0aeb30..0x0aecd0 (416 B) | Symbol: __gxx_personality_v0
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_0aeb30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90357F6ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x01A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AEB30ULL;
}

// FDE #1763 | PC: 0x0aecd0..0x0af2ec (1564 B) | Symbol: sub_0aecd0
// EN: AArch64 prologue [sub sp, sp, #0xc0; stp x28, x27, [sp, #0x60]; stp x26, x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; stp x28, x27, [sp, #0x60]; stp x26, x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]]
uint64_t fde_sub_0aecd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9066FFCULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x061CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AECD0ULL;
}

// FDE #1764 | PC: 0x0af2ec..0x0af318 (44 B) | Symbol: sub_0af2ec
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w20, w0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w20, w0]
uint64_t fde_sub_0af2ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AF2ECULL;
}

// FDE #1765 | PC: 0x0af318..0x0af694 (892 B) | Symbol: __cxa_call_unexpected
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp x28, x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp x28, x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]]
uint64_t fde_sub_0af318(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9046FFCULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x037CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AF318ULL;
}

// FDE #1766 | PC: 0x0af694..0x0af7e8 (340 B) | Symbol: sub_0af694
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; and w9, w1, #0xff; cmp w9, #0xff] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; and w9, w1, #0xff; cmp w9, #0xff]
uint64_t fde_sub_0af694(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0154ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AF694ULL;
}

// FDE #1767 | PC: 0x0af7e8..0x0af930 (328 B) | Symbol: __cxa_thread_atexit
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0af7e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0148ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AF7E8ULL;
}

// FDE #1768 | PC: 0x0af930..0x0af9b0 (128 B) | Symbol: sub_0af930
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0af930(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AF930ULL;
}

// FDE #1769 | PC: 0x0af9b0..0x0afa28 (120 B) | Symbol: sub_0af9b0
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0af9b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AF9B0ULL;
}

// FDE #1770 | PC: 0x0afa28..0x0afb18 (240 B) | Symbol: __cxa_vec_new
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0afa28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x00F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AFA28ULL;
}

// FDE #1771 | PC: 0x0afb18..0x0afc1c (260 B) | Symbol: __cxa_vec_new2
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0afb18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AFB18ULL;
}

// FDE #1772 | PC: 0x0afc1c..0x0afcc0 (164 B) | Symbol: __cxa_vec_ctor
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0afc1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AFC1CULL;
}

// FDE #1773 | PC: 0x0afcc0..0x0afddc (284 B) | Symbol: __cxa_vec_new3
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_0afcc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9016FFCULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AFCC0ULL;
}

// FDE #1774 | PC: 0x0afddc..0x0afe94 (184 B) | Symbol: __cxa_vec_cctor
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0afddc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AFDDCULL;
}

// FDE #1775 | PC: 0x0afe94..0x0aff44 (176 B) | Symbol: __cxa_vec_dtor
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0afe94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AFE94ULL;
}

// FDE #1776 | PC: 0x0aff44..0x0aff98 (84 B) | Symbol: __cxa_vec_cleanup
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0aff44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AFF44ULL;
}

// FDE #1777 | PC: 0x0aff98..0x0b0078 (224 B) | Symbol: __cxa_vec_delete
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0aff98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0AFF98ULL;
}

// FDE #1778 | PC: 0x0b0078..0x0b0158 (224 B) | Symbol: __cxa_vec_delete2
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0b0078(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0078ULL;
}

// FDE #1779 | PC: 0x0b0158..0x0b0248 (240 B) | Symbol: __cxa_vec_delete3
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0b0158(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x00F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0158ULL;
}

// FDE #1780 | PC: 0x0b0248..0x0b027c (52 B) | Symbol: sub_0b0248
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w0, #8] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w0, #8]
uint64_t fde_sub_0b0248(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0248ULL;
}

// FDE #1781 | PC: 0x0b027c..0x0b0290 (20 B) | Symbol: __cxa_pure_virtual
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0xbb000; add x0, x0, #0xaf8] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0xbb000; add x0, x0, #0xaf8]
uint64_t fde_sub_0b027c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B027CULL;
}

// FDE #1782 | PC: 0x0b0290..0x0b02a4 (20 B) | Symbol: __cxa_deleted_virtual
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0xbb000; add x0, x0, #0xb16] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0xbb000; add x0, x0, #0xb16]
uint64_t fde_sub_0b0290(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0290ULL;
}

// FDE #1783 | PC: 0x0b02a4..0x0b0310 (108 B) | Symbol: sub_0b02a4
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0b02a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B02A4ULL;
}

// FDE #1784 | PC: 0x0b0310..0x0b0404 (244 B) | Symbol: sub_0b0310
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0]
uint64_t fde_sub_0b0310(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0310ULL;
}

// FDE #1785 | PC: 0x0b0404..0x0b0460 (92 B) | Symbol: sub_0b0404
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0b0404(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0404ULL;
}

// FDE #1786 | PC: 0x0b0460..0x0b0488 (40 B) | Symbol: sub_0b0460
// EN: AArch64 prologue [adrp x8, #0xe7000; add x8, x8, #0x180; cmp x0, x8; b.hs #0xb0484] | VI: Khởi đầu hàm AArch64 [adrp x8, #0xe7000; add x8, x8, #0x180; cmp x0, x8; b.hs #0xb0484]
uint64_t fde_sub_0b0460(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91060108ULL) << 32) | 0xF00001A8ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0460ULL;
}

// FDE #1787 | PC: 0x0b0488..0x0b0584 (252 B) | Symbol: sub_0b0488
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0b0488(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0488ULL;
}

// FDE #1788 | PC: 0x0b0584..0x0b05ac (40 B) | Symbol: sub_0b0584
// EN: AArch64 prologue [adrp x8, #0xe7000; add x8, x8, #0x180; cmp x0, x8; b.hs #0xb05a8] | VI: Khởi đầu hàm AArch64 [adrp x8, #0xe7000; add x8, x8, #0x180; cmp x0, x8; b.hs #0xb05a8]
uint64_t fde_sub_0b0584(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91060108ULL) << 32) | 0xF00001A8ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0584ULL;
}

// FDE #1789 | PC: 0x0b05ac..0x0b05b0 (4 B) | Symbol: sub_0b05ac
// EN: AArch64 prologue [b #0x479e0] | VI: Khởi đầu hàm AArch64 [b #0x479e0]
uint64_t fde_sub_0b05ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD4200020ULL) << 32) | 0x17FE5D0DULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B05ACULL;
}

// FDE #1790 | PC: 0x0b05b0..0x0b05b4 (4 B) | Symbol: sub_0b05b0
// EN: AArch64 prologue [brk #1] | VI: Khởi đầu hàm AArch64 [brk #1]
uint64_t fde_sub_0b05b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD4200020ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B05B0ULL;
}

// FDE #1791 | PC: 0x0b05b4..0x0b05b8 (4 B) | Symbol: sub_0b05b4
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_0b05b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B05B4ULL;
}

// FDE #1792 | PC: 0x0b05b8..0x0b05bc (4 B) | Symbol: sub_0b05b8
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_0b05b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B05B8ULL;
}

// FDE #1793 | PC: 0x0b05bc..0x0b05e0 (36 B) | Symbol: sub_0b05bc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0b05bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B05BCULL;
}

// FDE #1794 | PC: 0x0b05e0..0x0b0604 (36 B) | Symbol: sub_0b05e0
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0b05e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B05E0ULL;
}

// FDE #1795 | PC: 0x0b0604..0x0b0628 (36 B) | Symbol: sub_0b0604
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0b0604(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0604ULL;
}

// FDE #1796 | PC: 0x0b0628..0x0b064c (36 B) | Symbol: sub_0b0628
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0b0628(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0628ULL;
}

// FDE #1797 | PC: 0x0b064c..0x0b0670 (36 B) | Symbol: sub_0b064c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0b064c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B064CULL;
}

// FDE #1798 | PC: 0x0b0670..0x0b0694 (36 B) | Symbol: sub_0b0670
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0b0670(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0670ULL;
}

// FDE #1799 | PC: 0x0b0694..0x0b06b8 (36 B) | Symbol: sub_0b0694
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0b0694(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0694ULL;
}

// FDE #1800 | PC: 0x0b06b8..0x0b06dc (36 B) | Symbol: sub_0b06b8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0b06b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B06B8ULL;
}

// FDE #1801 | PC: 0x0b06dc..0x0b0700 (36 B) | Symbol: sub_0b06dc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0b06dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B06DCULL;
}

// FDE #1802 | PC: 0x0b0700..0x0b0724 (36 B) | Symbol: sub_0b0700
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0b0700(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0700ULL;
}

// FDE #1803 | PC: 0x0b0724..0x0b0738 (20 B) | Symbol: sub_0b0724
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x9, [x1, #8]; cmp x8, x9; cset w0, eq] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x9, [x1, #8]; cmp x8, x9; cset w0, eq]
uint64_t fde_sub_0b0724(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400429ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0724ULL;
}

// FDE #1804 | PC: 0x0b0738..0x0b0740 (8 B) | Symbol: sub_0b0738
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_0b0738(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0738ULL;
}

// FDE #1805 | PC: 0x0b0740..0x0b0748 (8 B) | Symbol: sub_0b0740
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_0b0740(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0740ULL;
}

// FDE #1806 | PC: 0x0b0748..0x0b075c (20 B) | Symbol: sub_0b0748
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x9, [x1, #8]; cmp x8, x9; cset w0, eq] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x9, [x1, #8]; cmp x8, x9; cset w0, eq]
uint64_t fde_sub_0b0748(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400429ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0748ULL;
}

// FDE #1807 | PC: 0x0b075c..0x0b083c (224 B) | Symbol: sub_0b075c
// EN: AArch64 prologue [sub sp, sp, #0x90; str x21, [sp, #0x60]; stp x20, x19, [sp, #0x70]; stp x29, x30, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x21, [sp, #0x60]; stp x20, x19, [sp, #0x70]; stp x29, x30, [sp, #0x80]]
uint64_t fde_sub_0b075c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90033F5ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B075CULL;
}

// FDE #1808 | PC: 0x0b083c..0x0b0894 (88 B) | Symbol: sub_0b083c
// EN: AArch64 prologue [ldr x8, [x1, #0x20]; cbz x8, #0xb086c; cmp x8, x2; b.eq #0xb0880] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1, #0x20]; cbz x8, #0xb086c; cmp x8, x2; b.eq #0xb0880]
uint64_t fde_sub_0b083c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000168ULL) << 32) | 0xF9401028ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B083CULL;
}

// FDE #1809 | PC: 0x0b0894..0x0b0904 (112 B) | Symbol: sub_0b0894
// EN: AArch64 prologue [ldr x8, [x1, #0x10]; ldr x9, [x0, #8]; ldr x8, [x8, #8]; cmp x9, x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1, #0x10]; ldr x9, [x0, #8]; ldr x8, [x8, #8]; cmp x9, x8]
uint64_t fde_sub_0b0894(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400409ULL) << 32) | 0xF9400828ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0894ULL;
}

// FDE #1810 | PC: 0x0b0904..0x0b0980 (124 B) | Symbol: sub_0b0904
// EN: AArch64 prologue [ldr x8, [x1, #0x10]; ldr x9, [x0, #8]; ldr x8, [x8, #8]; cmp x9, x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1, #0x10]; ldr x9, [x0, #8]; ldr x8, [x8, #8]; cmp x9, x8]
uint64_t fde_sub_0b0904(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400409ULL) << 32) | 0xF9400828ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0904ULL;
}

// FDE #1811 | PC: 0x0b0980..0x0b09c0 (64 B) | Symbol: sub_0b0980
// EN: AArch64 prologue [ldr x8, [x0, #8]; cbz x2, #0xb099c; asr x9, x8, #8; tbz w8, #0, #0xb09a0] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; cbz x2, #0xb099c; asr x9, x8, #8; tbz w8, #0, #0xb09a0]
uint64_t fde_sub_0b0980(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB40000C2ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0980ULL;
}

// FDE #1812 | PC: 0x0b09c0..0x0b0b14 (340 B) | Symbol: sub_0b09c0
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0b09c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0154ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B09C0ULL;
}

// FDE #1813 | PC: 0x0b0b14..0x0b0bac (152 B) | Symbol: sub_0b0b14
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x10]]
uint64_t fde_sub_0b0b14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0B14ULL;
}

// FDE #1814 | PC: 0x0b0bac..0x0b0ecc (800 B) | Symbol: sub_0b0bac
// EN: AArch64 prologue [sub sp, sp, #0xa0; str x23, [sp, #0x60]; stp x22, x21, [sp, #0x70]; stp x20, x19, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; str x23, [sp, #0x60]; stp x22, x21, [sp, #0x70]; stp x20, x19, [sp, #0x80]]
uint64_t fde_sub_0b0bac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90033F7ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x0320ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0BACULL;
}

// FDE #1815 | PC: 0x0b0ecc..0x0b1014 (328 B) | Symbol: sub_0b0ecc
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0b0ecc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0148ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B0ECCULL;
}

// FDE #1816 | PC: 0x0b1014..0x0b10a0 (140 B) | Symbol: sub_0b1014
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x1, #0xb1074] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x1, #0xb1074]
uint64_t fde_sub_0b1014(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B1014ULL;
}

// FDE #1817 | PC: 0x0b10a0..0x0b1200 (352 B) | Symbol: sub_0b10a0
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0b10a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0160ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B10A0ULL;
}

// FDE #1818 | PC: 0x0b1200..0x0b1338 (312 B) | Symbol: __dynamic_cast
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x20, x19, [sp, #0x60]; stp x29, x30, [sp, #0x70]; add x29, sp, #0x70] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x20, x19, [sp, #0x60]; stp x29, x30, [sp, #0x70]; add x29, sp, #0x70]
uint64_t fde_sub_0b1200(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9064FF4ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0138ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B1200ULL;
}

// FDE #1819 | PC: 0x0b1338..0x0b13d8 (160 B) | Symbol: sub_0b1338
// EN: AArch64 prologue [ldr x9, [x1, #8]; mov w8, #1; strb w8, [x1, #0x4d]; cmp x9, x3] | VI: Khởi đầu hàm AArch64 [ldr x9, [x1, #8]; mov w8, #1; strb w8, [x1, #0x4d]; cmp x9, x3]
uint64_t fde_sub_0b1338(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800028ULL) << 32) | 0xF9400429ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B1338ULL;
}

// FDE #1820 | PC: 0x0b13d8..0x0b13f8 (32 B) | Symbol: sub_0b13d8
// EN: AArch64 prologue [ldr x8, [x1, #8]; cmp x8, x2; b.ne #0xb13f4; ldr w8, [x1, #0x34]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1, #8]; cmp x8, x2; b.ne #0xb13f4; ldr w8, [x1, #0x34]]
uint64_t fde_sub_0b13d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB02011FULL) << 32) | 0xF9400428ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B13D8ULL;
}

// FDE #1821 | PC: 0x0b13f8..0x0b17ac (948 B) | Symbol: sub_0b13f8
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0b13f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x03B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B13F8ULL;
}

// FDE #1822 | PC: 0x0b17ac..0x0b17e4 (56 B) | Symbol: sub_0b17ac
// EN: AArch64 prologue [ldr x8, [x0, #8]; asr x9, x8, #8; tbz w8, #0, #0xb17c0; ldr x10, [x3]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; asr x9, x8, #8; tbz w8, #0, #0xb17c0; ldr x10, [x3]]
uint64_t fde_sub_0b17ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9348FD09ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B17ACULL;
}

// FDE #1823 | PC: 0x0b17e4..0x0b181c (56 B) | Symbol: sub_0b17e4
// EN: AArch64 prologue [ldr x8, [x0, #8]; asr x9, x8, #8; tbz w8, #0, #0xb17f8; ldr x10, [x2]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; asr x9, x8, #8; tbz w8, #0, #0xb17f8; ldr x10, [x2]]
uint64_t fde_sub_0b17e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9348FD09ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B17E4ULL;
}

// FDE #1824 | PC: 0x0b181c..0x0b19bc (416 B) | Symbol: sub_0b181c
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0b181c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x01A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B181CULL;
}

// FDE #1825 | PC: 0x0b19bc..0x0b1adc (288 B) | Symbol: sub_0b19bc
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0b19bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0120ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B19BCULL;
}

// FDE #1826 | PC: 0x0b1adc..0x0b1d18 (572 B) | Symbol: sub_0b1adc
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0b1adc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x023CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B1ADCULL;
}

// FDE #1827 | PC: 0x0b1d18..0x0b1e48 (304 B) | Symbol: sub_0b1d18
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0b1d18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B1D18ULL;
}

// FDE #1828 | PC: 0x0b1e48..0x0b1f38 (240 B) | Symbol: sub_0b1e48
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0b1e48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B1E48ULL;
}

// FDE #1829 | PC: 0x0b1f38..0x0b1f3c (4 B) | Symbol: _ZNSt9exceptionD1Ev
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_0b1f38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FE5845ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B1F38ULL;
}

// FDE #1830 | PC: 0x0b1f3c..0x0b1f40 (4 B) | Symbol: _ZNSt9exceptionD0Ev
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0b1f3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000040ULL) << 32) | 0x17FE5845ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B1F3CULL;
}

// FDE #1831 | PC: 0x0b1f40..0x0b1f4c (12 B) | Symbol: _ZNKSt9exception4whatEv
// EN: AArch64 prologue [adrp x0, #0xbb000; add x0, x0, #0xdd6; ret] | VI: Khởi đầu hàm AArch64 [adrp x0, #0xbb000; add x0, x0, #0xdd6; ret]
uint64_t fde_sub_0b1f40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91375800ULL) << 32) | 0xD0000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B1F40ULL;
}

// FDE #1832 | PC: 0x0b1f4c..0x0b1f50 (4 B) | Symbol: _ZNSt13bad_exceptionD0Ev
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0b1f4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000040ULL) << 32) | 0x17FE5841ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B1F4CULL;
}

// FDE #1833 | PC: 0x0b1f50..0x0b1f5c (12 B) | Symbol: _ZNKSt13bad_exception4whatEv
// EN: AArch64 prologue [adrp x0, #0xbb000; add x0, x0, #0xde5; ret] | VI: Khởi đầu hàm AArch64 [adrp x0, #0xbb000; add x0, x0, #0xde5; ret]
uint64_t fde_sub_0b1f50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91379400ULL) << 32) | 0xD0000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B1F50ULL;
}

// FDE #1834 | PC: 0x0b1f5c..0x0b1f70 (20 B) | Symbol: _ZNSt9bad_allocC1Ev
// EN: AArch64 prologue [adrp x8, #0xe3000; ldr x8, [x8, #0xe70]; add x8, x8, #0x10; str x8, [x0]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0xe3000; ldr x8, [x8, #0xe70]; add x8, x8, #0x10; str x8, [x0]]
uint64_t fde_sub_0b1f5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9473908ULL) << 32) | 0xD0000188ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B1F5CULL;
}

// FDE #1835 | PC: 0x0b1f70..0x0b1f74 (4 B) | Symbol: _ZNSt9bad_allocD0Ev
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0b1f70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000040ULL) << 32) | 0x17FE5838ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B1F70ULL;
}

// FDE #1836 | PC: 0x0b1f74..0x0b1f80 (12 B) | Symbol: _ZNKSt9bad_alloc4whatEv
// EN: AArch64 prologue [adrp x0, #0xbb000; add x0, x0, #0xdf8; ret] | VI: Khởi đầu hàm AArch64 [adrp x0, #0xbb000; add x0, x0, #0xdf8; ret]
uint64_t fde_sub_0b1f74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9137E000ULL) << 32) | 0xD0000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B1F74ULL;
}

// FDE #1837 | PC: 0x0b1f80..0x0b1f94 (20 B) | Symbol: _ZNSt20bad_array_new_lengthC2Ev
// EN: AArch64 prologue [adrp x8, #0xe3000; ldr x8, [x8, #0xe90]; add x8, x8, #0x10; str x8, [x0]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0xe3000; ldr x8, [x8, #0xe90]; add x8, x8, #0x10; str x8, [x0]]
uint64_t fde_sub_0b1f80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9474908ULL) << 32) | 0xD0000188ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B1F80ULL;
}

// FDE #1838 | PC: 0x0b1f94..0x0b1f98 (4 B) | Symbol: _ZNSt20bad_array_new_lengthD0Ev
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0b1f94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000040ULL) << 32) | 0x17FE582FULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B1F94ULL;
}

// FDE #1839 | PC: 0x0b1f98..0x0b1fa4 (12 B) | Symbol: _ZNKSt20bad_array_new_length4whatEv
// EN: AArch64 prologue [adrp x0, #0xbb000; add x0, x0, #0xe07; ret] | VI: Khởi đầu hàm AArch64 [adrp x0, #0xbb000; add x0, x0, #0xe07; ret]
uint64_t fde_sub_0b1f98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91381C00ULL) << 32) | 0xD0000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B1F98ULL;
}

// FDE #1840 | PC: 0x0b1fa4..0x0b2008 (100 B) | Symbol: sub_0b1fa4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cmp x0, #0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cmp x0, #0]
uint64_t fde_sub_0b1fa4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B1FA4ULL;
}

// FDE #1841 | PC: 0x0b2008..0x0b2034 (44 B) | Symbol: sub_0b2008
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x473c0; ldp x29, x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x473c0; ldp x29, x30, [sp], #0x10]
uint64_t fde_sub_0b2008(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2008ULL;
}

// FDE #1842 | PC: 0x0b2034..0x0b2038 (4 B) | Symbol: sub_0b2034
// EN: AArch64 prologue [b #0x473c0] | VI: Khởi đầu hàm AArch64 [b #0x473c0]
uint64_t fde_sub_0b2034(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0x17FE54E3ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2034ULL;
}

// FDE #1843 | PC: 0x0b2038..0x0b2064 (44 B) | Symbol: sub_0b2038
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x480b0; ldp x29, x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x480b0; ldp x29, x30, [sp], #0x10]
uint64_t fde_sub_0b2038(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2038ULL;
}

// FDE #1844 | PC: 0x0b2064..0x0b2070 (12 B) | Symbol: sub_0b2064
// EN: AArch64 prologue [cbz x0, #0xb206c; b #0x48610; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0xb206c; b #0x48610; ret]
uint64_t fde_sub_0b2064(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FE596AULL) << 32) | 0xB4000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2064ULL;
}

// FDE #1845 | PC: 0x0b2070..0x0b2074 (4 B) | Symbol: sub_0b2070
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0b2070(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FE57F7ULL) << 32) | 0x17FE57F8ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2070ULL;
}

// FDE #1846 | PC: 0x0b2074..0x0b2078 (4 B) | Symbol: sub_0b2074
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0b2074(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FE57F6ULL) << 32) | 0x17FE57F7ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2074ULL;
}

// FDE #1847 | PC: 0x0b2078..0x0b207c (4 B) | Symbol: sub_0b2078
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0b2078(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FE578DULL) << 32) | 0x17FE57F6ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2078ULL;
}

// FDE #1848 | PC: 0x0b207c..0x0b2080 (4 B) | Symbol: sub_0b207c
// EN: AArch64 prologue [b #0x47eb0] | VI: Khởi đầu hàm AArch64 [b #0x47eb0]
uint64_t fde_sub_0b207c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FE578CULL) << 32) | 0x17FE578DULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B207CULL;
}

// FDE #1849 | PC: 0x0b2080..0x0b2084 (4 B) | Symbol: sub_0b2080
// EN: AArch64 prologue [b #0x47eb0] | VI: Khởi đầu hàm AArch64 [b #0x47eb0]
uint64_t fde_sub_0b2080(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10103FFULL) << 32) | 0x17FE578CULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2080ULL;
}

// FDE #1850 | PC: 0x0b2084..0x0b2130 (172 B) | Symbol: sub_0b2084
// EN: AArch64 prologue [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0b2084(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2084ULL;
}

// FDE #1851 | PC: 0x0b2130..0x0b215c (44 B) | Symbol: sub_0b2130
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x477b0; ldp x29, x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x477b0; ldp x29, x30, [sp], #0x10]
uint64_t fde_sub_0b2130(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2130ULL;
}

// FDE #1852 | PC: 0x0b215c..0x0b2160 (4 B) | Symbol: sub_0b215c
// EN: AArch64 prologue [b #0x477b0] | VI: Khởi đầu hàm AArch64 [b #0x477b0]
uint64_t fde_sub_0b215c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0x17FE5595ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B215CULL;
}

// FDE #1853 | PC: 0x0b2160..0x0b218c (44 B) | Symbol: sub_0b2160
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x471a0; ldp x29, x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x471a0; ldp x29, x30, [sp], #0x10]
uint64_t fde_sub_0b2160(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2160ULL;
}

// FDE #1854 | PC: 0x0b218c..0x0b2198 (12 B) | Symbol: sub_0b218c
// EN: AArch64 prologue [cbz x0, #0xb2194; b #0x48610; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0xb2194; b #0x48610; ret]
uint64_t fde_sub_0b218c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FE5920ULL) << 32) | 0xB4000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B218CULL;
}

// FDE #1855 | PC: 0x0b2198..0x0b219c (4 B) | Symbol: sub_0b2198
// EN: AArch64 prologue [b #0x47d30] | VI: Khởi đầu hàm AArch64 [b #0x47d30]
uint64_t fde_sub_0b2198(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0203E1ULL) << 32) | 0x17FE56E6ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2198ULL;
}

// FDE #1856 | PC: 0x0b219c..0x0b21a4 (8 B) | Symbol: sub_0b219c
// EN: AArch64 prologue [mov x1, x2; b #0x47d30] | VI: Khởi đầu hàm AArch64 [mov x1, x2; b #0x47d30]
uint64_t fde_sub_0b219c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FE56E4ULL) << 32) | 0xAA0203E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B219CULL;
}

// FDE #1857 | PC: 0x0b21a4..0x0b21a8 (4 B) | Symbol: sub_0b21a4
// EN: AArch64 prologue [b #0x47d30] | VI: Khởi đầu hàm AArch64 [b #0x47d30]
uint64_t fde_sub_0b21a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FE54AAULL) << 32) | 0x17FE56E3ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B21A4ULL;
}

// FDE #1858 | PC: 0x0b21a8..0x0b21ac (4 B) | Symbol: sub_0b21a8
// EN: AArch64 prologue [b #0x47450] | VI: Khởi đầu hàm AArch64 [b #0x47450]
uint64_t fde_sub_0b21a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0203E1ULL) << 32) | 0x17FE54AAULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B21A8ULL;
}

// FDE #1859 | PC: 0x0b21ac..0x0b21b4 (8 B) | Symbol: sub_0b21ac
// EN: AArch64 prologue [mov x1, x2; b #0x47450] | VI: Khởi đầu hàm AArch64 [mov x1, x2; b #0x47450]
uint64_t fde_sub_0b21ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FE54A8ULL) << 32) | 0xAA0203E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B21ACULL;
}

// FDE #1860 | PC: 0x0b21b4..0x0b2208 (84 B) | Symbol: _ZNSt11logic_errorD1Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000]
uint64_t fde_sub_0b21b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B21B4ULL;
}

// FDE #1861 | PC: 0x0b2208..0x0b2264 (92 B) | Symbol: _ZNSt11logic_errorD0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000]
uint64_t fde_sub_0b2208(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2208ULL;
}

// FDE #1862 | PC: 0x0b2264..0x0b226c (8 B) | Symbol: _ZNKSt11logic_error4whatEv
// EN: AArch64 prologue [ldr x0, [x0, #8]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #8]; ret]
uint64_t fde_sub_0b2264(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF9400400ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2264ULL;
}

// FDE #1863 | PC: 0x0b226c..0x0b22c0 (84 B) | Symbol: _ZNSt13runtime_errorD2Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000]
uint64_t fde_sub_0b226c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B226CULL;
}

// FDE #1864 | PC: 0x0b22c0..0x0b231c (92 B) | Symbol: _ZNSt13runtime_errorD0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000]
uint64_t fde_sub_0b22c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B22C0ULL;
}

// FDE #1865 | PC: 0x0b231c..0x0b2324 (8 B) | Symbol: _ZNKSt13runtime_error4whatEv
// EN: AArch64 prologue [ldr x0, [x0, #8]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #8]; ret]
uint64_t fde_sub_0b231c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF9400400ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B231CULL;
}

// FDE #1866 | PC: 0x0b2324..0x0b2380 (92 B) | Symbol: _ZNSt12domain_errorD0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000]
uint64_t fde_sub_0b2324(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2324ULL;
}

// FDE #1867 | PC: 0x0b2380..0x0b23dc (92 B) | Symbol: _ZNSt16invalid_argumentD0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000]
uint64_t fde_sub_0b2380(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2380ULL;
}

// FDE #1868 | PC: 0x0b23dc..0x0b2438 (92 B) | Symbol: _ZNSt12length_errorD0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000]
uint64_t fde_sub_0b23dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B23DCULL;
}

// FDE #1869 | PC: 0x0b2438..0x0b2494 (92 B) | Symbol: _ZNSt12out_of_rangeD0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000]
uint64_t fde_sub_0b2438(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2438ULL;
}

// FDE #1870 | PC: 0x0b2494..0x0b24f0 (92 B) | Symbol: _ZNSt11range_errorD0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000]
uint64_t fde_sub_0b2494(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2494ULL;
}

// FDE #1871 | PC: 0x0b24f0..0x0b254c (92 B) | Symbol: _ZNSt14overflow_errorD0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000]
uint64_t fde_sub_0b24f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B24F0ULL;
}

// FDE #1872 | PC: 0x0b254c..0x0b25a8 (92 B) | Symbol: _ZNSt15underflow_errorD0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000]
uint64_t fde_sub_0b254c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B254CULL;
}

// FDE #1873 | PC: 0x0b25a8..0x0b25ac (4 B) | Symbol: _ZNSt9type_infoD2Ev
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_0b25a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FE56A9ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B25A8ULL;
}

// FDE #1874 | PC: 0x0b25ac..0x0b25b0 (4 B) | Symbol: _ZNSt9type_infoD0Ev
// EN: AArch64 prologue [b #0x48050] | VI: Khởi đầu hàm AArch64 [b #0x48050]
uint64_t fde_sub_0b25ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000188ULL) << 32) | 0x17FE56A9ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B25ACULL;
}

// FDE #1875 | PC: 0x0b25b0..0x0b25c4 (20 B) | Symbol: _ZNSt8bad_castC2Ev
// EN: AArch64 prologue [adrp x8, #0xe3000; ldr x8, [x8, #0xca8]; add x8, x8, #0x10; str x8, [x0]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0xe3000; ldr x8, [x8, #0xca8]; add x8, x8, #0x10; str x8, [x0]]
uint64_t fde_sub_0b25b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9465508ULL) << 32) | 0xB0000188ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B25B0ULL;
}

// FDE #1876 | PC: 0x0b25c4..0x0b25c8 (4 B) | Symbol: _ZNSt8bad_castD1Ev
// EN: AArch64 prologue [b #0x483a0] | VI: Khởi đầu hàm AArch64 [b #0x483a0]
uint64_t fde_sub_0b25c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0x17FE5777ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B25C4ULL;
}

// FDE #1877 | PC: 0x0b25c8..0x0b25ec (36 B) | Symbol: _ZNSt8bad_castD0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0b25c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B25C8ULL;
}

// FDE #1878 | PC: 0x0b25ec..0x0b25f8 (12 B) | Symbol: _ZNKSt8bad_cast4whatEv
// EN: AArch64 prologue [adrp x0, #0xbb000; add x0, x0, #0xf02; ret] | VI: Khởi đầu hàm AArch64 [adrp x0, #0xbb000; add x0, x0, #0xf02; ret]
uint64_t fde_sub_0b25ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x913C0800ULL) << 32) | 0xB0000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B25ECULL;
}

// FDE #1879 | PC: 0x0b25f8..0x0b260c (20 B) | Symbol: _ZNSt10bad_typeidC2Ev
// EN: AArch64 prologue [adrp x8, #0xe3000; ldr x8, [x8, #0xd98]; add x8, x8, #0x10; str x8, [x0]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0xe3000; ldr x8, [x8, #0xd98]; add x8, x8, #0x10; str x8, [x0]]
uint64_t fde_sub_0b25f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF946CD08ULL) << 32) | 0xB0000188ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B25F8ULL;
}

// FDE #1880 | PC: 0x0b260c..0x0b2610 (4 B) | Symbol: _ZNSt10bad_typeidD1Ev
// EN: AArch64 prologue [b #0x483a0] | VI: Khởi đầu hàm AArch64 [b #0x483a0]
uint64_t fde_sub_0b260c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0x17FE5765ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B260CULL;
}

// FDE #1881 | PC: 0x0b2610..0x0b2634 (36 B) | Symbol: _ZNSt10bad_typeidD0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0b2610(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2610ULL;
}

// FDE #1882 | PC: 0x0b2634..0x0b2640 (12 B) | Symbol: _ZNKSt10bad_typeid4whatEv
// EN: AArch64 prologue [adrp x0, #0xbb000; add x0, x0, #0xf10; ret] | VI: Khởi đầu hàm AArch64 [adrp x0, #0xbb000; add x0, x0, #0xf10; ret]
uint64_t fde_sub_0b2634(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x913C4000ULL) << 32) | 0xB0000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2634ULL;
}

// FDE #1883 | PC: 0x0b2640..0x0b277c (316 B) | Symbol: sub_0b2640
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; fmov x0, d0; fmov x1, v0.d[1]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; fmov x0, d0; fmov x1, v0.d[1]; mov x29, sp]
uint64_t fde_sub_0b2640(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9E660000ULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x013CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2640ULL;
}

// FDE #1884 | PC: 0x0b277c..0x0b27a4 (40 B) | Symbol: sub_0b277c
// EN: AArch64 prologue [mov x2, #0; mov w3, #0; ldrb w5, [x0], #1; and x4, x5, #0x7f] | VI: Khởi đầu hàm AArch64 [mov x2, #0; mov w3, #0; ldrb w5, [x0], #1; and x4, x5, #0x7f]
uint64_t fde_sub_0b277c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800003ULL) << 32) | 0xD2800002ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B277CULL;
}

// FDE #1885 | PC: 0x0b27a4..0x0b27e4 (64 B) | Symbol: sub_0b27a4
// EN: AArch64 prologue [mov x2, #0; mov w3, #0; ldrb w4, [x0], #1; and x5, x4, #0x7f] | VI: Khởi đầu hàm AArch64 [mov x2, #0; mov w3, #0; ldrb w4, [x0], #1; and x5, x4, #0x7f]
uint64_t fde_sub_0b27a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800003ULL) << 32) | 0xD2800002ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B27A4ULL;
}

// FDE #1886 | PC: 0x0b27e4..0x0b28d4 (240 B) | Symbol: sub_0b27e4
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x40]!; mov x29, sp; stp x19, x20, [sp, #0x10]; uxtb w20, w0] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x40]!; mov x29, sp; stp x19, x20, [sp, #0x10]; uxtb w20, w0]
uint64_t fde_sub_0b27e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BC7BFDULL;
    const uint64_t kPcRange = 0x00F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B27E4ULL;
}

// FDE #1887 | PC: 0x0b28d4..0x0b29e8 (276 B) | Symbol: sub_0b28d4
// EN: AArch64 prologue [adrp x2, #0xe7000; mov w0, #8; add x1, x2, #0x180; strb w0, [x2, #0x180]] | VI: Khởi đầu hàm AArch64 [adrp x2, #0xe7000; mov w0, #8; add x1, x2, #0x180; strb w0, [x2, #0x180]]
uint64_t fde_sub_0b28d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800100ULL) << 32) | 0xB00001A2ULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B28D4ULL;
}

// FDE #1888 | PC: 0x0b29e8..0x0b2a24 (60 B) | Symbol: sub_0b29e8
// EN: AArch64 prologue [adrp x3, #0xe7000; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w3, [x3, #0x19f]] | VI: Khởi đầu hàm AArch64 [adrp x3, #0xe7000; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w3, [x3, #0x19f]]
uint64_t fde_sub_0b29e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xB00001A3ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B29E8ULL;
}

// FDE #1889 | PC: 0x0b2a24..0x0b2a7c (88 B) | Symbol: sub_0b2a24
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; cmp w1, #0x61; mov x29, sp; b.le #0xb2a38] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; cmp w1, #0x61; mov x29, sp; b.le #0xb2a38]
uint64_t fde_sub_0b2a24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7101843FULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2A24ULL;
}

// FDE #1890 | PC: 0x0b2a7c..0x0b2b88 (268 B) | Symbol: sub_0b2a7c
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x40]!; mov x29, sp; stp x21, x22, [sp, #0x20]; mov x21, x0] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x40]!; mov x29, sp; stp x21, x22, [sp, #0x20]; mov x21, x0]
uint64_t fde_sub_0b2a7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BC7BFDULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2A7CULL;
}

// FDE #1891 | PC: 0x0b2b88..0x0b2b90 (8 B) | Symbol: sub_0b2b88
// EN: AArch64 prologue [ldr x0, [x0, #0x310]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x310]; ret]
uint64_t fde_sub_0b2b88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF9418800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2B88ULL;
}

// FDE #1892 | PC: 0x0b2b90..0x0b2be8 (88 B) | Symbol: sub_0b2b90
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; cmp w1, #0x61; mov x29, sp; b.le #0xb2ba4] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; cmp w1, #0x61; mov x29, sp; b.le #0xb2ba4]
uint64_t fde_sub_0b2b90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7101843FULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2B90ULL;
}

// FDE #1893 | PC: 0x0b2be8..0x0b2bf0 (8 B) | Symbol: sub_0b2be8
// EN: AArch64 prologue [ldr x0, [x0, #0x318]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x318]; ret]
uint64_t fde_sub_0b2be8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF9418C00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2BE8ULL;
}

// FDE #1894 | PC: 0x0b2bf0..0x0b2c04 (20 B) | Symbol: sub_0b2bf0
// EN: AArch64 prologue [ldr x2, [x0, #0x340]; ldr x0, [x0, #0x318]; lsr x2, x2, #0x3f; str w2, [x1]] | VI: Khởi đầu hàm AArch64 [ldr x2, [x0, #0x340]; ldr x0, [x0, #0x318]; lsr x2, x2, #0x3f; str w2, [x1]]
uint64_t fde_sub_0b2bf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9418C00ULL) << 32) | 0xF941A002ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2BF0ULL;
}

// FDE #1895 | PC: 0x0b2c04..0x0b2c0c (8 B) | Symbol: sub_0b2c04
// EN: AArch64 prologue [str x1, [x0, #0x318]; ret] | VI: Khởi đầu hàm AArch64 [str x1, [x0, #0x318]; ret]
uint64_t fde_sub_0b2c04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF9018C01ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2C04ULL;
}

// FDE #1896 | PC: 0x0b2c0c..0x0b2c14 (8 B) | Symbol: sub_0b2c0c
// EN: AArch64 prologue [ldr x0, [x0, #0x320]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x320]; ret]
uint64_t fde_sub_0b2c0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF9419000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2C0CULL;
}

// FDE #1897 | PC: 0x0b2c14..0x0b2c1c (8 B) | Symbol: sub_0b2c14
// EN: AArch64 prologue [ldr x0, [x0, #0x338]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x338]; ret]
uint64_t fde_sub_0b2c14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF9419C00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2C14ULL;
}

// FDE #1898 | PC: 0x0b2c1c..0x0b2c44 (40 B) | Symbol: sub_0b2c1c
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x30]!; sub x0, x0, #1; mov x29, sp; add x1, x29, #0x18] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x30]!; sub x0, x0, #1; mov x29, sp; add x1, x29, #0x18]
uint64_t fde_sub_0b2c1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD1000400ULL) << 32) | 0xA9BD7BFDULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2C1CULL;
}

// FDE #1899 | PC: 0x0b2c44..0x0b2c4c (8 B) | Symbol: sub_0b2c44
// EN: AArch64 prologue [ldr x0, [x0, #0x330]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x330]; ret]
uint64_t fde_sub_0b2c44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF9419800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2C44ULL;
}

// FDE #1900 | PC: 0x0b2c4c..0x0b2c54 (8 B) | Symbol: sub_0b2c4c
// EN: AArch64 prologue [ldr x0, [x0, #0x328]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x328]; ret]
uint64_t fde_sub_0b2c4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF9419400ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2C4CULL;
}

// FDE #1901 | PC: 0x0b2c54..0x0b2ccc (120 B) | Symbol: sub_0b2c54
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; uxtb w2, w0; mov x0, x1; cmp w2, #0xff] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; uxtb w2, w0; mov x0, x1; cmp w2, #0xff]
uint64_t fde_sub_0b2c54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x53001C02ULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2C54ULL;
}

// FDE #1902 | PC: 0x0b2ccc..0x0b31c4 (1272 B) | Symbol: sub_0b2ccc
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x90]!; mov x29, sp; stp x21, x22, [sp, #0x20]; stp x23, x24, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x90]!; mov x29, sp; stp x21, x22, [sp, #0x20]; stp x23, x24, [sp, #0x30]]
uint64_t fde_sub_0b2ccc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9B77BFDULL;
    const uint64_t kPcRange = 0x04F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B2CCCULL;
}

// FDE #1903 | PC: 0x0b31c4..0x0b35e8 (1060 B) | Symbol: sub_0b31c4
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x90]!; mov x2, #0x680; mov x29, sp; stp x19, x20, [sp, #0x10]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x90]!; mov x2, #0x680; mov x29, sp; stp x19, x20, [sp, #0x10]]
uint64_t fde_sub_0b31c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD280D002ULL) << 32) | 0xA9B77BFDULL;
    const uint64_t kPcRange = 0x0424ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B31C4ULL;
}

// FDE #1904 | PC: 0x0b35e8..0x0b3b9c (1460 B) | Symbol: sub_0b35e8
// EN: AArch64 prologue [sub sp, sp, #0x230; mov x4, x0; stp x29, x30, [sp, #-0x60]!; mov x29, sp] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x230; mov x4, x0; stp x29, x30, [sp, #-0x60]!; mov x29, sp]
uint64_t fde_sub_0b35e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003E4ULL) << 32) | 0xD108C3FFULL;
    const uint64_t kPcRange = 0x05B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B35E8ULL;
}

// FDE #1905 | PC: 0x0b3b9c..0x0b3da8 (524 B) | Symbol: sub_0b3b9c
// EN: AArch64 prologue [sub sp, sp, #0x3e0; mov x2, #0x3c0; stp x29, x30, [sp, #-0x60]!; mov x29, sp] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x3e0; mov x2, #0x3c0; stp x29, x30, [sp, #-0x60]!; mov x29, sp]
uint64_t fde_sub_0b3b9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD2807802ULL) << 32) | 0xD10F83FFULL;
    const uint64_t kPcRange = 0x020CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B3B9CULL;
}

// FDE #1906 | PC: 0x0b3da8..0x0b3e84 (220 B) | Symbol: sub_0b3da8
// EN: AArch64 prologue [sub sp, sp, #0x690; stp x29, x30, [sp, #-0x40]!; mov x29, sp; stp x19, x20, [sp, #0x10]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x690; stp x29, x30, [sp, #-0x40]!; mov x29, sp; stp x19, x20, [sp, #0x10]]
uint64_t fde_sub_0b3da8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD11A43FFULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B3DA8ULL;
}

// FDE #1907 | PC: 0x0b3e84..0x0b3ed0 (76 B) | Symbol: sub_0b3e84
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x20]!; mov x29, sp; stp x19, x20, [sp, #0x10]; mov x19, x1] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x20]!; mov x29, sp; stp x19, x20, [sp, #0x10]; mov x19, x1]
uint64_t fde_sub_0b3e84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BE7BFDULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B3E84ULL;
}

// FDE #1908 | PC: 0x0b3ed0..0x0b3f90 (192 B) | Symbol: sub_0b3ed0
// EN: AArch64 prologue [sub sp, sp, #0x680; stp x29, x30, [sp, #-0x40]!; mov x29, sp; stp x19, x20, [sp, #0x10]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x680; stp x29, x30, [sp, #-0x40]!; mov x29, sp; stp x19, x20, [sp, #0x10]]
uint64_t fde_sub_0b3ed0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD11A03FFULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B3ED0ULL;
}

// FDE #1909 | PC: 0x0b3f90..0x0b407c (236 B) | Symbol: sub_0b3f90
// EN: AArch64 prologue [sub sp, sp, #0x680; stp x29, x30, [sp, #-0x50]!; mov x29, sp; stp x23, x24, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x680; stp x29, x30, [sp, #-0x50]!; mov x29, sp; stp x23, x24, [sp, #0x30]]
uint64_t fde_sub_0b3f90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB7BFDULL) << 32) | 0xD11A03FFULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B3F90ULL;
}

// FDE #1910 | PC: 0x0b407c..0x0b4170 (244 B) | Symbol: sub_0b407c
// EN: AArch64 prologue [sub sp, sp, #0xa40; mov x2, #0x3c0; stp x29, x30, [sp, #-0x30]!; mov x29, sp] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa40; mov x2, #0x3c0; stp x29, x30, [sp, #-0x30]!; mov x29, sp]
uint64_t fde_sub_0b407c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD2807802ULL) << 32) | 0xD12903FFULL;
    const uint64_t kPcRange = 0x00F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B407CULL;
}

// FDE #1911 | PC: 0x0b4170..0x0b4174 (4 B) | Symbol: sub_0b4170
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_0b4170(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD13843FFULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B4170ULL;
}

// FDE #1912 | PC: 0x0b4174..0x0b42ec (376 B) | Symbol: sub_0b4174
// EN: AArch64 prologue [sub sp, sp, #0xe10; stp x29, x30, [sp, #-0xc0]!; mov x29, sp; stp x21, x22, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xe10; stp x29, x30, [sp, #-0xc0]!; mov x29, sp; stp x21, x22, [sp, #0x40]]
uint64_t fde_sub_0b4174(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9B47BFDULL) << 32) | 0xD13843FFULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B4174ULL;
}

// FDE #1913 | PC: 0x0b42ec..0x0b43e0 (244 B) | Symbol: sub_0b42ec
// EN: AArch64 prologue [sub sp, sp, #0x790; stp x29, x30, [sp, #-0xc0]!; mov x29, sp; stp x19, x20, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x790; stp x29, x30, [sp, #-0xc0]!; mov x29, sp; stp x19, x20, [sp, #0x30]]
uint64_t fde_sub_0b42ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9B47BFDULL) << 32) | 0xD11E43FFULL;
    const uint64_t kPcRange = 0x00F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B42ECULL;
}

// FDE #1914 | PC: 0x0b43e0..0x0b44dc (252 B) | Symbol: sub_0b43e0
// EN: AArch64 prologue [sub sp, sp, #0x790; stp x29, x30, [sp, #-0xc0]!; mov x29, sp; stp x19, x20, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x790; stp x29, x30, [sp, #-0xc0]!; mov x29, sp; stp x19, x20, [sp, #0x30]]
uint64_t fde_sub_0b43e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9B47BFDULL) << 32) | 0xD11E43FFULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B43E0ULL;
}

// FDE #1915 | PC: 0x0b44dc..0x0b45d4 (248 B) | Symbol: sub_0b44dc
// EN: AArch64 prologue [sub sp, sp, #0x790; stp x29, x30, [sp, #-0xc0]!; mov x29, sp; stp d8, d9, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x790; stp x29, x30, [sp, #-0xc0]!; mov x29, sp; stp d8, d9, [sp, #0x80]]
uint64_t fde_sub_0b44dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9B47BFDULL) << 32) | 0xD11E43FFULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B44DCULL;
}

// FDE #1916 | PC: 0x0b45d4..0x0b45f8 (36 B) | Symbol: sub_0b45d4
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x2, [x0, #8]; cbz x2, #0xb45f0] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x2, [x0, #8]; cbz x2, #0xb45f0]
uint64_t fde_sub_0b45d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B45D4ULL;
}

// FDE #1917 | PC: 0x0b45f8..0x0b46c8 (208 B) | Symbol: sub_0b45f8
// EN: AArch64 prologue [sub sp, sp, #0xa40; mov x2, x30; stp x29, x30, [sp, #-0xa0]!; mov x29, sp] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa40; mov x2, x30; stp x29, x30, [sp, #-0xa0]!; mov x29, sp]
uint64_t fde_sub_0b45f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E2ULL) << 32) | 0xD12903FFULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B45F8ULL;
}

// FDE #1918 | PC: 0x0b46c8..0x0b46f0 (40 B) | Symbol: sub_0b46c8
// EN: AArch64 prologue [mov x2, #0; mov w3, #0; ldrb w5, [x0], #1; and x4, x5, #0x7f] | VI: Khởi đầu hàm AArch64 [mov x2, #0; mov w3, #0; ldrb w5, [x0], #1; and x4, x5, #0x7f]
uint64_t fde_sub_0b46c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800003ULL) << 32) | 0xD2800002ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B46C8ULL;
}

// FDE #1919 | PC: 0x0b46f0..0x0b4730 (64 B) | Symbol: sub_0b46f0
// EN: AArch64 prologue [mov x2, #0; mov w3, #0; ldrb w4, [x0], #1; and x5, x4, #0x7f] | VI: Khởi đầu hàm AArch64 [mov x2, #0; mov w3, #0; ldrb w4, [x0], #1; and x5, x4, #0x7f]
uint64_t fde_sub_0b46f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800003ULL) << 32) | 0xD2800002ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B46F0ULL;
}

// FDE #1920 | PC: 0x0b4730..0x0b474c (28 B) | Symbol: sub_0b4730
// EN: AArch64 prologue [ldr x3, [x1, #8]; ldr x1, [x2, #8]; cmp x3, x1; csetm w0, lo] | VI: Khởi đầu hàm AArch64 [ldr x3, [x1, #8]; ldr x1, [x2, #8]; cmp x3, x1; csetm w0, lo]
uint64_t fde_sub_0b4730(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400441ULL) << 32) | 0xF9400423ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B4730ULL;
}

// FDE #1921 | PC: 0x0b474c..0x0b480c (192 B) | Symbol: sub_0b474c
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x60]!; mov x29, sp; stp x19, x20, [sp, #0x10]; lsl w19, w3, #1] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x60]!; mov x29, sp; stp x19, x20, [sp, #0x10]; lsl w19, w3, #1]
uint64_t fde_sub_0b474c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BA7BFDULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B474CULL;
}

// FDE #1922 | PC: 0x0b480c..0x0b48c0 (180 B) | Symbol: sub_0b480c
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x50]!; mov x29, sp; stp x19, x20, [sp, #0x10]; ldr x19, [x2, #8]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x50]!; mov x29, sp; stp x19, x20, [sp, #0x10]; ldr x19, [x2, #8]]
uint64_t fde_sub_0b480c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BB7BFDULL;
    const uint64_t kPcRange = 0x00B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B480CULL;
}

// FDE #1923 | PC: 0x0b48c0..0x0b4920 (96 B) | Symbol: sub_0b48c0
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; uxtb w0, w0; cmp w0, #0xff; mov x29, sp] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; uxtb w0, w0; cmp w0, #0xff; mov x29, sp]
uint64_t fde_sub_0b48c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x53001C00ULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B48C0ULL;
}

// FDE #1924 | PC: 0x0b4920..0x0b4980 (96 B) | Symbol: sub_0b4920
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; uxtb w0, w0; cmp w0, #0xff; mov x29, sp] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; uxtb w0, w0; cmp w0, #0xff; mov x29, sp]
uint64_t fde_sub_0b4920(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x53001C00ULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B4920ULL;
}

// FDE #1925 | PC: 0x0b4980..0x0b49e0 (96 B) | Symbol: sub_0b4980
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; uxtb w0, w0; cmp w0, #0xff; mov x29, sp] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; uxtb w0, w0; cmp w0, #0xff; mov x29, sp]
uint64_t fde_sub_0b4980(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x53001C00ULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B4980ULL;
}

// FDE #1926 | PC: 0x0b49e0..0x0b4ad0 (240 B) | Symbol: sub_0b49e0
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x40]!; mov x29, sp; stp x19, x20, [sp, #0x10]; uxtb w20, w0] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x40]!; mov x29, sp; stp x19, x20, [sp, #0x10]; uxtb w20, w0]
uint64_t fde_sub_0b49e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BC7BFDULL;
    const uint64_t kPcRange = 0x00F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B49E0ULL;
}

// FDE #1927 | PC: 0x0b4ad0..0x0b4b60 (144 B) | Symbol: sub_0b4ad0
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x50]!; mov x29, sp; stp x19, x20, [sp, #0x10]; ldrh w19, [x0, #0x20]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x50]!; mov x29, sp; stp x19, x20, [sp, #0x10]; ldrh w19, [x0, #0x20]]
uint64_t fde_sub_0b4ad0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BB7BFDULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B4AD0ULL;
}

// FDE #1928 | PC: 0x0b4b60..0x0b4c5c (252 B) | Symbol: sub_0b4b60
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x40]!; mov x29, sp; stp x19, x20, [sp, #0x10]; add x20, x0, #9] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x40]!; mov x29, sp; stp x19, x20, [sp, #0x10]; add x20, x0, #9]
uint64_t fde_sub_0b4b60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BC7BFDULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B4B60ULL;
}

// FDE #1929 | PC: 0x0b4c5c..0x0b4dbc (352 B) | Symbol: sub_0b4c5c
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x70]!; mov x29, sp; stp x21, x22, [sp, #0x20]; mov x22, x0] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x70]!; mov x29, sp; stp x21, x22, [sp, #0x20]; mov x22, x0]
uint64_t fde_sub_0b4c5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9B97BFDULL;
    const uint64_t kPcRange = 0x0160ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B4C5CULL;
}

// FDE #1930 | PC: 0x0b4dbc..0x0b4dcc (16 B) | Symbol: sub_0b4dbc
// EN: AArch64 prologue [add x1, x0, #4; ldrsw x0, [x0, #4]; sub x0, x1, x0; b #0xb4b60] | VI: Khởi đầu hàm AArch64 [add x1, x0, #4; ldrsw x0, [x0, #4]; sub x0, x1, x0; b #0xb4b60]
uint64_t fde_sub_0b4dbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9800400ULL) << 32) | 0x91001001ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B4DBCULL;
}

// FDE #1931 | PC: 0x0b4dcc..0x0b51e8 (1052 B) | Symbol: sub_0b4dcc
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x90]!; cmp x1, #0x2f; mov x29, sp; stp x19, x20, [sp, #0x10]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x90]!; cmp x1, #0x2f; mov x29, sp; stp x19, x20, [sp, #0x10]]
uint64_t fde_sub_0b4dcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF100BC3FULL) << 32) | 0xA9B77BFDULL;
    const uint64_t kPcRange = 0x041CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B4DCCULL;
}

// FDE #1932 | PC: 0x0b51e8..0x0b5284 (156 B) | Symbol: sub_0b51e8
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x40]!; mov x29, sp; stp x21, x22, [sp, #0x20]; mov x21, x0] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x40]!; mov x29, sp; stp x21, x22, [sp, #0x20]; mov x21, x0]
uint64_t fde_sub_0b51e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BC7BFDULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B51E8ULL;
}

// FDE #1933 | PC: 0x0b5284..0x0b53e4 (352 B) | Symbol: sub_0b5284
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x70]!; mov x29, sp; stp x19, x20, [sp, #0x10]; stp x23, x24, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x70]!; mov x29, sp; stp x19, x20, [sp, #0x10]; stp x23, x24, [sp, #0x30]]
uint64_t fde_sub_0b5284(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9B97BFDULL;
    const uint64_t kPcRange = 0x0160ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B5284ULL;
}

// FDE #1934 | PC: 0x0b53e4..0x0b5518 (308 B) | Symbol: sub_0b53e4
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x70]!; mov x29, sp; stp x21, x22, [sp, #0x20]; mov x22, x0] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x70]!; mov x29, sp; stp x21, x22, [sp, #0x20]; mov x22, x0]
uint64_t fde_sub_0b53e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9B97BFDULL;
    const uint64_t kPcRange = 0x0134ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B53E4ULL;
}

// FDE #1935 | PC: 0x0b5518..0x0b5a88 (1392 B) | Symbol: sub_0b5518
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x90]!; mov x29, sp; stp x21, x22, [sp, #0x20]; mov x22, x1] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x90]!; mov x29, sp; stp x21, x22, [sp, #0x20]; mov x22, x1]
uint64_t fde_sub_0b5518(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9B77BFDULL;
    const uint64_t kPcRange = 0x0570ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B5518ULL;
}

// FDE #1936 | PC: 0x0b5a88..0x0b5b24 (156 B) | Symbol: sub_0b5a88
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x30]!; mov x29, sp; stp x19, x20, [sp, #0x10]; str x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x30]!; mov x29, sp; stp x19, x20, [sp, #0x10]; str x21, [sp, #0x20]]
uint64_t fde_sub_0b5a88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BD7BFDULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B5A88ULL;
}

// FDE #1937 | PC: 0x0b5b24..0x0b5b30 (12 B) | Symbol: sub_0b5b24
// EN: AArch64 prologue [mov x2, #0; mov x3, #0; b #0xb5a88] | VI: Khởi đầu hàm AArch64 [mov x2, #0; mov x3, #0; b #0xb5a88]
uint64_t fde_sub_0b5b24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD2800003ULL) << 32) | 0xD2800002ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B5B24ULL;
}

// FDE #1938 | PC: 0x0b5b30..0x0b5b70 (64 B) | Symbol: sub_0b5b30
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x20]!; mov x29, sp; ldr w1, [x0]; str x19, [sp, #0x10]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x20]!; mov x29, sp; ldr w1, [x0]; str x19, [sp, #0x10]]
uint64_t fde_sub_0b5b30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BE7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B5B30ULL;
}

// FDE #1939 | PC: 0x0b5b70..0x0b5c04 (148 B) | Symbol: sub_0b5b70
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x30]!; mov x4, #-1; mov x29, sp; stp x19, x20, [sp, #0x10]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x30]!; mov x4, #-1; mov x29, sp; stp x19, x20, [sp, #0x10]]
uint64_t fde_sub_0b5b70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x92800004ULL) << 32) | 0xA9BD7BFDULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B5B70ULL;
}

// FDE #1940 | PC: 0x0b5c04..0x0b5c10 (12 B) | Symbol: sub_0b5c04
// EN: AArch64 prologue [mov x2, #0; mov x3, #0; b #0xb5b70] | VI: Khởi đầu hàm AArch64 [mov x2, #0; mov x3, #0; b #0xb5b70]
uint64_t fde_sub_0b5c04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD2800003ULL) << 32) | 0xD2800002ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B5C04ULL;
}

// FDE #1941 | PC: 0x0b5c10..0x0b5c3c (44 B) | Symbol: sub_0b5c10
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x20]!; mov x29, sp; str x19, [sp, #0x10]; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x20]!; mov x29, sp; str x19, [sp, #0x10]; mov x19, x0]
uint64_t fde_sub_0b5c10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BE7BFDULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B5C10ULL;
}

// FDE #1942 | PC: 0x0b5c3c..0x0b5d3c (256 B) | Symbol: sub_0b5c3c
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x30]!; mov x29, sp; stp x19, x20, [sp, #0x10]; stp x21, x22, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x30]!; mov x29, sp; stp x19, x20, [sp, #0x10]; stp x21, x22, [sp, #0x20]]
uint64_t fde_sub_0b5c3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BD7BFDULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B5C3CULL;
}

// FDE #1943 | PC: 0x0b5d3c..0x0b5d40 (4 B) | Symbol: sub_0b5d3c
// EN: AArch64 prologue [b #0xb5c3c] | VI: Khởi đầu hàm AArch64 [b #0xb5c3c]
uint64_t fde_sub_0b5d3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0x17FFFFC0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B5D3CULL;
}

// FDE #1944 | PC: 0x0b5d40..0x0b5d64 (36 B) | Symbol: sub_0b5d40
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr w1, [x0]; cbz w1, #0xb5d5c] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr w1, [x0]; cbz w1, #0xb5d5c]
uint64_t fde_sub_0b5d40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B5D40ULL;
}

// FDE #1945 | PC: 0x0b5d64..0x0b5f28 (452 B) | Symbol: sub_0b5d64
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x80]!; mov x29, sp; stp x21, x22, [sp, #0x20]; adrp x21, #0xe3000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x80]!; mov x29, sp; stp x21, x22, [sp, #0x20]; adrp x21, #0xe3000]
uint64_t fde_sub_0b5d64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9B87BFDULL;
    const uint64_t kPcRange = 0x01C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B5D64ULL;
}

// FDE #1946 | PC: 0x0b5f28..0x0b5f68 (64 B) | Symbol: sub_0b5f28
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x20]!; adrp x1, #0xb5000; mov x29, sp; str x19, [sp, #0x10]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x20]!; adrp x1, #0xb5000; mov x29, sp; str x19, [sp, #0x10]]
uint64_t fde_sub_0b5f28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000001ULL) << 32) | 0xA9BE7BFDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B5F28ULL;
}

// FDE #1947 | PC: 0x0b5f68..0x0b5fe8 (128 B) | Symbol: sub_0b5f68
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x30]!; mov x1, x0; mov x29, sp; ldr x0, [x0]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x30]!; mov x1, x0; mov x29, sp; ldr x0, [x0]]
uint64_t fde_sub_0b5f68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003E1ULL) << 32) | 0xA9BD7BFDULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B5F68ULL;
}

// FDE #1948 | PC: 0x0b5fe8..0x0b6080 (152 B) | Symbol: sub_0b5fe8
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x30]!; mov x29, sp; stp x19, x20, [sp, #0x10]; ldr x20, [x0, #8]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x30]!; mov x29, sp; stp x19, x20, [sp, #0x10]; ldr x20, [x0, #8]]
uint64_t fde_sub_0b5fe8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BD7BFDULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B5FE8ULL;
}

// FDE #1949 | PC: 0x0b6080..0x0b60a0 (32 B) | Symbol: sub_0b6080
// EN: AArch64 prologue [adrp x0, #0xe7000; add x1, x0, #0x3c0; ldr w2, [x1, #4]; cbz w2, #0xb609c] | VI: Khởi đầu hàm AArch64 [adrp x0, #0xe7000; add x1, x0, #0x3c0; ldr w2, [x1, #4]; cbz w2, #0xb609c]
uint64_t fde_sub_0b6080(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910F0001ULL) << 32) | 0xB0000180ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B6080ULL;
}

// FDE #1950 | PC: 0x0b60a0..0x0b61f8 (344 B) | Symbol: sub_0b60a0
// EN: AArch64 prologue [adrp x1, #0xe3000; stp x29, x30, [sp, #-0x40]!; mov x29, sp; ldr x1, [x1, #0xae8]] | VI: Khởi đầu hàm AArch64 [adrp x1, #0xe3000; stp x29, x30, [sp, #-0x40]!; mov x29, sp; ldr x1, [x1, #0xae8]]
uint64_t fde_sub_0b60a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xB0000161ULL;
    const uint64_t kPcRange = 0x0158ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B60A0ULL;
}

// FDE #1951 | PC: 0x0b61f8..0x0b6234 (60 B) | Symbol: sub_0b61f8
// EN: AArch64 prologue [ldr x4, [x0]; cmp x4, x1; b.hs #0xb620c; str x1, [x0]] | VI: Khởi đầu hàm AArch64 [ldr x4, [x0]; cmp x4, x1; b.hs #0xb620c; str x1, [x0]]
uint64_t fde_sub_0b61f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB01009FULL) << 32) | 0xF9400004ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B61F8ULL;
}

// FDE #1952 | PC: 0x0b6234..0x0b6294 (96 B) | Symbol: sub_0b6234
// EN: AArch64 prologue [tbz w0, #0, #0xb6244; fmov s1, wzr; fdiv s0, s1, s1; mrs x1, fpsr] | VI: Khởi đầu hàm AArch64 [tbz w0, #0, #0xb6244; fmov s1, wzr; fdiv s0, s1, s1; mrs x1, fpsr]
uint64_t fde_sub_0b6234(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E2703E1ULL) << 32) | 0x36000080ULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B6234ULL;
}

uint64_t DispatchCxxSharedShard5(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x0a6bf4ULL: return fde_sub_0a6bf4(a0, a1, a2);
        case 0x0a6c98ULL: return fde_sub_0a6c98(a0, a1, a2);
        case 0x0a6ef0ULL: return fde_sub_0a6ef0(a0, a1, a2);
        case 0x0a6ef4ULL: return fde_sub_0a6ef4(a0, a1, a2);
        case 0x0a712cULL: return fde_sub_0a712c(a0, a1, a2);
        case 0x0a7130ULL: return fde_sub_0a7130(a0, a1, a2);
        case 0x0a71e0ULL: return fde_sub_0a71e0(a0, a1, a2);
        case 0x0a71e4ULL: return fde_sub_0a71e4(a0, a1, a2);
        case 0x0a7238ULL: return fde_sub_0a7238(a0, a1, a2);
        case 0x0a723cULL: return fde_sub_0a723c(a0, a1, a2);
        case 0x0a7240ULL: return fde_sub_0a7240(a0, a1, a2);
        case 0x0a77c4ULL: return fde_sub_0a77c4(a0, a1, a2);
        case 0x0a77c8ULL: return fde_sub_0a77c8(a0, a1, a2);
        case 0x0a7918ULL: return fde_sub_0a7918(a0, a1, a2);
        case 0x0a791cULL: return fde_sub_0a791c(a0, a1, a2);
        case 0x0a7b34ULL: return fde_sub_0a7b34(a0, a1, a2);
        case 0x0a7b38ULL: return fde_sub_0a7b38(a0, a1, a2);
        case 0x0a7becULL: return fde_sub_0a7bec(a0, a1, a2);
        case 0x0a7bf0ULL: return fde_sub_0a7bf0(a0, a1, a2);
        case 0x0a7cb8ULL: return fde_sub_0a7cb8(a0, a1, a2);
        case 0x0a7cbcULL: return fde_sub_0a7cbc(a0, a1, a2);
        case 0x0a7e24ULL: return fde_sub_0a7e24(a0, a1, a2);
        case 0x0a7e28ULL: return fde_sub_0a7e28(a0, a1, a2);
        case 0x0a7ef8ULL: return fde_sub_0a7ef8(a0, a1, a2);
        case 0x0a8088ULL: return fde_sub_0a8088(a0, a1, a2);
        case 0x0a808cULL: return fde_sub_0a808c(a0, a1, a2);
        case 0x0a8174ULL: return fde_sub_0a8174(a0, a1, a2);
        case 0x0a8178ULL: return fde_sub_0a8178(a0, a1, a2);
        case 0x0a8200ULL: return fde_sub_0a8200(a0, a1, a2);
        case 0x0a84d8ULL: return fde_sub_0a84d8(a0, a1, a2);
        case 0x0a86b8ULL: return fde_sub_0a86b8(a0, a1, a2);
        case 0x0a877cULL: return fde_sub_0a877c(a0, a1, a2);
        case 0x0a878cULL: return fde_sub_0a878c(a0, a1, a2);
        case 0x0a8790ULL: return fde_sub_0a8790(a0, a1, a2);
        case 0x0a9a38ULL: return fde_sub_0a9a38(a0, a1, a2);
        case 0x0a9a94ULL: return fde_sub_0a9a94(a0, a1, a2);
        case 0x0a9a98ULL: return fde_sub_0a9a98(a0, a1, a2);
        case 0x0a9b28ULL: return fde_sub_0a9b28(a0, a1, a2);
        case 0x0a9b2cULL: return fde_sub_0a9b2c(a0, a1, a2);
        case 0x0a9bbcULL: return fde_sub_0a9bbc(a0, a1, a2);
        case 0x0a9bc0ULL: return fde_sub_0a9bc0(a0, a1, a2);
        case 0x0a9c50ULL: return fde_sub_0a9c50(a0, a1, a2);
        case 0x0a9c60ULL: return fde_sub_0a9c60(a0, a1, a2);
        case 0x0a9c64ULL: return fde_sub_0a9c64(a0, a1, a2);
        case 0x0a9d10ULL: return fde_sub_0a9d10(a0, a1, a2);
        case 0x0a9d14ULL: return fde_sub_0a9d14(a0, a1, a2);
        case 0x0a9e14ULL: return fde_sub_0a9e14(a0, a1, a2);
        case 0x0a9e18ULL: return fde_sub_0a9e18(a0, a1, a2);
        case 0x0aa014ULL: return fde_sub_0aa014(a0, a1, a2);
        case 0x0aa018ULL: return fde_sub_0aa018(a0, a1, a2);
        case 0x0aa1ecULL: return fde_sub_0aa1ec(a0, a1, a2);
        case 0x0aa1f0ULL: return fde_sub_0aa1f0(a0, a1, a2);
        case 0x0aa3bcULL: return fde_sub_0aa3bc(a0, a1, a2);
        case 0x0aa3c0ULL: return fde_sub_0aa3c0(a0, a1, a2);
        case 0x0aa470ULL: return fde_sub_0aa470(a0, a1, a2);
        case 0x0aa474ULL: return fde_sub_0aa474(a0, a1, a2);
        case 0x0aa7c8ULL: return fde_sub_0aa7c8(a0, a1, a2);
        case 0x0aa7ccULL: return fde_sub_0aa7cc(a0, a1, a2);
        case 0x0aa844ULL: return fde_sub_0aa844(a0, a1, a2);
        case 0x0aa848ULL: return fde_sub_0aa848(a0, a1, a2);
        case 0x0aa9a4ULL: return fde_sub_0aa9a4(a0, a1, a2);
        case 0x0aa9a8ULL: return fde_sub_0aa9a8(a0, a1, a2);
        case 0x0aaa4cULL: return fde_sub_0aaa4c(a0, a1, a2);
        case 0x0aaa50ULL: return fde_sub_0aaa50(a0, a1, a2);
        case 0x0aab40ULL: return fde_sub_0aab40(a0, a1, a2);
        case 0x0aab44ULL: return fde_sub_0aab44(a0, a1, a2);
        case 0x0aabd4ULL: return fde_sub_0aabd4(a0, a1, a2);
        case 0x0aabd8ULL: return fde_sub_0aabd8(a0, a1, a2);
        case 0x0aac7cULL: return fde_sub_0aac7c(a0, a1, a2);
        case 0x0aac80ULL: return fde_sub_0aac80(a0, a1, a2);
        case 0x0aad3cULL: return fde_sub_0aad3c(a0, a1, a2);
        case 0x0aadccULL: return fde_sub_0aadcc(a0, a1, a2);
        case 0x0aadd0ULL: return fde_sub_0aadd0(a0, a1, a2);
        case 0x0aae48ULL: return fde_sub_0aae48(a0, a1, a2);
        case 0x0aae4cULL: return fde_sub_0aae4c(a0, a1, a2);
        case 0x0aaed4ULL: return fde_sub_0aaed4(a0, a1, a2);
        case 0x0aaed8ULL: return fde_sub_0aaed8(a0, a1, a2);
        case 0x0aaf50ULL: return fde_sub_0aaf50(a0, a1, a2);
        case 0x0aaf54ULL: return fde_sub_0aaf54(a0, a1, a2);
        case 0x0ab0b8ULL: return fde_sub_0ab0b8(a0, a1, a2);
        case 0x0ab0bcULL: return fde_sub_0ab0bc(a0, a1, a2);
        case 0x0ab24cULL: return fde_sub_0ab24c(a0, a1, a2);
        case 0x0ab250ULL: return fde_sub_0ab250(a0, a1, a2);
        case 0x0ab314ULL: return fde_sub_0ab314(a0, a1, a2);
        case 0x0ab318ULL: return fde_sub_0ab318(a0, a1, a2);
        case 0x0ab3d4ULL: return fde_sub_0ab3d4(a0, a1, a2);
        case 0x0ab474ULL: return fde_sub_0ab474(a0, a1, a2);
        case 0x0ab478ULL: return fde_sub_0ab478(a0, a1, a2);
        case 0x0ab4dcULL: return fde_sub_0ab4dc(a0, a1, a2);
        case 0x0ab540ULL: return fde_sub_0ab540(a0, a1, a2);
        case 0x0ab5a4ULL: return fde_sub_0ab5a4(a0, a1, a2);
        case 0x0ab5ecULL: return fde_sub_0ab5ec(a0, a1, a2);
        case 0x0ab634ULL: return fde_sub_0ab634(a0, a1, a2);
        case 0x0ab67cULL: return fde_sub_0ab67c(a0, a1, a2);
        case 0x0ab680ULL: return fde_sub_0ab680(a0, a1, a2);
        case 0x0ab7f4ULL: return fde_sub_0ab7f4(a0, a1, a2);
        case 0x0ab7f8ULL: return fde_sub_0ab7f8(a0, a1, a2);
        case 0x0ab898ULL: return fde_sub_0ab898(a0, a1, a2);
        case 0x0ab8a8ULL: return fde_sub_0ab8a8(a0, a1, a2);
        case 0x0ab8acULL: return fde_sub_0ab8ac(a0, a1, a2);
        case 0x0ab93cULL: return fde_sub_0ab93c(a0, a1, a2);
        case 0x0ab94cULL: return fde_sub_0ab94c(a0, a1, a2);
        case 0x0ab950ULL: return fde_sub_0ab950(a0, a1, a2);
        case 0x0aba40ULL: return fde_sub_0aba40(a0, a1, a2);
        case 0x0aba44ULL: return fde_sub_0aba44(a0, a1, a2);
        case 0x0abbacULL: return fde_sub_0abbac(a0, a1, a2);
        case 0x0abbb0ULL: return fde_sub_0abbb0(a0, a1, a2);
        case 0x0abbb8ULL: return fde_sub_0abbb8(a0, a1, a2);
        case 0x0abbc0ULL: return fde_sub_0abbc0(a0, a1, a2);
        case 0x0abc90ULL: return fde_sub_0abc90(a0, a1, a2);
        case 0x0abf08ULL: return fde_sub_0abf08(a0, a1, a2);
        case 0x0abf0cULL: return fde_sub_0abf0c(a0, a1, a2);
        case 0x0abfb8ULL: return fde_sub_0abfb8(a0, a1, a2);
        case 0x0abfbcULL: return fde_sub_0abfbc(a0, a1, a2);
        case 0x0ac5d0ULL: return fde_sub_0ac5d0(a0, a1, a2);
        case 0x0ac990ULL: return fde_sub_0ac990(a0, a1, a2);
        case 0x0acb98ULL: return fde_sub_0acb98(a0, a1, a2);
        case 0x0acc3cULL: return fde_sub_0acc3c(a0, a1, a2);
        case 0x0acc40ULL: return fde_sub_0acc40(a0, a1, a2);
        case 0x0acda8ULL: return fde_sub_0acda8(a0, a1, a2);
        case 0x0acdacULL: return fde_sub_0acdac(a0, a1, a2);
        case 0x0acdb4ULL: return fde_sub_0acdb4(a0, a1, a2);
        case 0x0acdbcULL: return fde_sub_0acdbc(a0, a1, a2);
        case 0x0ace08ULL: return fde_sub_0ace08(a0, a1, a2);
        case 0x0ad0d0ULL: return fde_sub_0ad0d0(a0, a1, a2);
        case 0x0ad0d4ULL: return fde_sub_0ad0d4(a0, a1, a2);
        case 0x0ad180ULL: return fde_sub_0ad180(a0, a1, a2);
        case 0x0ad184ULL: return fde_sub_0ad184(a0, a1, a2);
        case 0x0ad20cULL: return fde_sub_0ad20c(a0, a1, a2);
        case 0x0ad210ULL: return fde_sub_0ad210(a0, a1, a2);
        case 0x0ad238ULL: return fde_sub_0ad238(a0, a1, a2);
        case 0x0ad260ULL: return fde_sub_0ad260(a0, a1, a2);
        case 0x0ad288ULL: return fde_sub_0ad288(a0, a1, a2);
        case 0x0ad358ULL: return fde_sub_0ad358(a0, a1, a2);
        case 0x0ad368ULL: return fde_sub_0ad368(a0, a1, a2);
        case 0x0ad36cULL: return fde_sub_0ad36c(a0, a1, a2);
        case 0x0ad3e4ULL: return fde_sub_0ad3e4(a0, a1, a2);
        case 0x0ad3e8ULL: return fde_sub_0ad3e8(a0, a1, a2);
        case 0x0ad4dcULL: return fde_sub_0ad4dc(a0, a1, a2);
        case 0x0ad4e0ULL: return fde_sub_0ad4e0(a0, a1, a2);
        case 0x0ad4e8ULL: return fde_sub_0ad4e8(a0, a1, a2);
        case 0x0ad4f0ULL: return fde_sub_0ad4f0(a0, a1, a2);
        case 0x0ad500ULL: return fde_sub_0ad500(a0, a1, a2);
        case 0x0ad618ULL: return fde_sub_0ad618(a0, a1, a2);
        case 0x0ad61cULL: return fde_sub_0ad61c(a0, a1, a2);
        case 0x0ad644ULL: return fde_sub_0ad644(a0, a1, a2);
        case 0x0ad754ULL: return fde_sub_0ad754(a0, a1, a2);
        case 0x0ad800ULL: return fde_sub_0ad800(a0, a1, a2);
        case 0x0ad804ULL: return fde_sub_0ad804(a0, a1, a2);
        case 0x0ad8c4ULL: return fde_sub_0ad8c4(a0, a1, a2);
        case 0x0ad8c8ULL: return fde_sub_0ad8c8(a0, a1, a2);
        case 0x0ad8f0ULL: return fde_sub_0ad8f0(a0, a1, a2);
        case 0x0adabcULL: return fde_sub_0adabc(a0, a1, a2);
        case 0x0adbe8ULL: return fde_sub_0adbe8(a0, a1, a2);
        case 0x0adbecULL: return fde_sub_0adbec(a0, a1, a2);
        case 0x0adc14ULL: return fde_sub_0adc14(a0, a1, a2);
        case 0x0addbcULL: return fde_sub_0addbc(a0, a1, a2);
        case 0x0adeccULL: return fde_sub_0adecc(a0, a1, a2);
        case 0x0aded0ULL: return fde_sub_0aded0(a0, a1, a2);
        case 0x0adf08ULL: return fde_sub_0adf08(a0, a1, a2);
        case 0x0adf0cULL: return fde_sub_0adf0c(a0, a1, a2);
        case 0x0adf20ULL: return fde_sub_0adf20(a0, a1, a2);
        case 0x0adf28ULL: return fde_sub_0adf28(a0, a1, a2);
        case 0x0adf48ULL: return fde_sub_0adf48(a0, a1, a2);
        case 0x0adf94ULL: return fde_sub_0adf94(a0, a1, a2);
        case 0x0adfb0ULL: return fde_sub_0adfb0(a0, a1, a2);
        case 0x0adfe4ULL: return fde_sub_0adfe4(a0, a1, a2);
        case 0x0adfe8ULL: return fde_sub_0adfe8(a0, a1, a2);
        case 0x0ae05cULL: return fde_sub_0ae05c(a0, a1, a2);
        case 0x0ae080ULL: return fde_sub_0ae080(a0, a1, a2);
        case 0x0ae0e0ULL: return fde_sub_0ae0e0(a0, a1, a2);
        case 0x0ae100ULL: return fde_sub_0ae100(a0, a1, a2);
        case 0x0ae108ULL: return fde_sub_0ae108(a0, a1, a2);
        case 0x0ae19cULL: return fde_sub_0ae19c(a0, a1, a2);
        case 0x0ae278ULL: return fde_sub_0ae278(a0, a1, a2);
        case 0x0ae2c8ULL: return fde_sub_0ae2c8(a0, a1, a2);
        case 0x0ae314ULL: return fde_sub_0ae314(a0, a1, a2);
        case 0x0ae3f8ULL: return fde_sub_0ae3f8(a0, a1, a2);
        case 0x0ae414ULL: return fde_sub_0ae414(a0, a1, a2);
        case 0x0ae488ULL: return fde_sub_0ae488(a0, a1, a2);
        case 0x0ae5a8ULL: return fde_sub_0ae5a8(a0, a1, a2);
        case 0x0ae614ULL: return fde_sub_0ae614(a0, a1, a2);
        case 0x0ae63cULL: return fde_sub_0ae63c(a0, a1, a2);
        case 0x0ae65cULL: return fde_sub_0ae65c(a0, a1, a2);
        case 0x0ae6ecULL: return fde_sub_0ae6ec(a0, a1, a2);
        case 0x0ae728ULL: return fde_sub_0ae728(a0, a1, a2);
        case 0x0ae75cULL: return fde_sub_0ae75c(a0, a1, a2);
        case 0x0ae790ULL: return fde_sub_0ae790(a0, a1, a2);
        case 0x0ae8f0ULL: return fde_sub_0ae8f0(a0, a1, a2);
        case 0x0ae998ULL: return fde_sub_0ae998(a0, a1, a2);
        case 0x0aea34ULL: return fde_sub_0aea34(a0, a1, a2);
        case 0x0aea44ULL: return fde_sub_0aea44(a0, a1, a2);
        case 0x0aea84ULL: return fde_sub_0aea84(a0, a1, a2);
        case 0x0aea9cULL: return fde_sub_0aea9c(a0, a1, a2);
        case 0x0aeab4ULL: return fde_sub_0aeab4(a0, a1, a2);
        case 0x0aeac4ULL: return fde_sub_0aeac4(a0, a1, a2);
        case 0x0aeb04ULL: return fde_sub_0aeb04(a0, a1, a2);
        case 0x0aeb20ULL: return fde_sub_0aeb20(a0, a1, a2);
        case 0x0aeb30ULL: return fde_sub_0aeb30(a0, a1, a2);
        case 0x0aecd0ULL: return fde_sub_0aecd0(a0, a1, a2);
        case 0x0af2ecULL: return fde_sub_0af2ec(a0, a1, a2);
        case 0x0af318ULL: return fde_sub_0af318(a0, a1, a2);
        case 0x0af694ULL: return fde_sub_0af694(a0, a1, a2);
        case 0x0af7e8ULL: return fde_sub_0af7e8(a0, a1, a2);
        case 0x0af930ULL: return fde_sub_0af930(a0, a1, a2);
        case 0x0af9b0ULL: return fde_sub_0af9b0(a0, a1, a2);
        case 0x0afa28ULL: return fde_sub_0afa28(a0, a1, a2);
        case 0x0afb18ULL: return fde_sub_0afb18(a0, a1, a2);
        case 0x0afc1cULL: return fde_sub_0afc1c(a0, a1, a2);
        case 0x0afcc0ULL: return fde_sub_0afcc0(a0, a1, a2);
        case 0x0afddcULL: return fde_sub_0afddc(a0, a1, a2);
        case 0x0afe94ULL: return fde_sub_0afe94(a0, a1, a2);
        case 0x0aff44ULL: return fde_sub_0aff44(a0, a1, a2);
        case 0x0aff98ULL: return fde_sub_0aff98(a0, a1, a2);
        case 0x0b0078ULL: return fde_sub_0b0078(a0, a1, a2);
        case 0x0b0158ULL: return fde_sub_0b0158(a0, a1, a2);
        case 0x0b0248ULL: return fde_sub_0b0248(a0, a1, a2);
        case 0x0b027cULL: return fde_sub_0b027c(a0, a1, a2);
        case 0x0b0290ULL: return fde_sub_0b0290(a0, a1, a2);
        case 0x0b02a4ULL: return fde_sub_0b02a4(a0, a1, a2);
        case 0x0b0310ULL: return fde_sub_0b0310(a0, a1, a2);
        case 0x0b0404ULL: return fde_sub_0b0404(a0, a1, a2);
        case 0x0b0460ULL: return fde_sub_0b0460(a0, a1, a2);
        case 0x0b0488ULL: return fde_sub_0b0488(a0, a1, a2);
        case 0x0b0584ULL: return fde_sub_0b0584(a0, a1, a2);
        case 0x0b05acULL: return fde_sub_0b05ac(a0, a1, a2);
        case 0x0b05b0ULL: return fde_sub_0b05b0(a0, a1, a2);
        case 0x0b05b4ULL: return fde_sub_0b05b4(a0, a1, a2);
        case 0x0b05b8ULL: return fde_sub_0b05b8(a0, a1, a2);
        case 0x0b05bcULL: return fde_sub_0b05bc(a0, a1, a2);
        case 0x0b05e0ULL: return fde_sub_0b05e0(a0, a1, a2);
        case 0x0b0604ULL: return fde_sub_0b0604(a0, a1, a2);
        case 0x0b0628ULL: return fde_sub_0b0628(a0, a1, a2);
        case 0x0b064cULL: return fde_sub_0b064c(a0, a1, a2);
        case 0x0b0670ULL: return fde_sub_0b0670(a0, a1, a2);
        case 0x0b0694ULL: return fde_sub_0b0694(a0, a1, a2);
        case 0x0b06b8ULL: return fde_sub_0b06b8(a0, a1, a2);
        case 0x0b06dcULL: return fde_sub_0b06dc(a0, a1, a2);
        case 0x0b0700ULL: return fde_sub_0b0700(a0, a1, a2);
        case 0x0b0724ULL: return fde_sub_0b0724(a0, a1, a2);
        case 0x0b0738ULL: return fde_sub_0b0738(a0, a1, a2);
        case 0x0b0740ULL: return fde_sub_0b0740(a0, a1, a2);
        case 0x0b0748ULL: return fde_sub_0b0748(a0, a1, a2);
        case 0x0b075cULL: return fde_sub_0b075c(a0, a1, a2);
        case 0x0b083cULL: return fde_sub_0b083c(a0, a1, a2);
        case 0x0b0894ULL: return fde_sub_0b0894(a0, a1, a2);
        case 0x0b0904ULL: return fde_sub_0b0904(a0, a1, a2);
        case 0x0b0980ULL: return fde_sub_0b0980(a0, a1, a2);
        case 0x0b09c0ULL: return fde_sub_0b09c0(a0, a1, a2);
        case 0x0b0b14ULL: return fde_sub_0b0b14(a0, a1, a2);
        case 0x0b0bacULL: return fde_sub_0b0bac(a0, a1, a2);
        case 0x0b0eccULL: return fde_sub_0b0ecc(a0, a1, a2);
        case 0x0b1014ULL: return fde_sub_0b1014(a0, a1, a2);
        case 0x0b10a0ULL: return fde_sub_0b10a0(a0, a1, a2);
        case 0x0b1200ULL: return fde_sub_0b1200(a0, a1, a2);
        case 0x0b1338ULL: return fde_sub_0b1338(a0, a1, a2);
        case 0x0b13d8ULL: return fde_sub_0b13d8(a0, a1, a2);
        case 0x0b13f8ULL: return fde_sub_0b13f8(a0, a1, a2);
        case 0x0b17acULL: return fde_sub_0b17ac(a0, a1, a2);
        case 0x0b17e4ULL: return fde_sub_0b17e4(a0, a1, a2);
        case 0x0b181cULL: return fde_sub_0b181c(a0, a1, a2);
        case 0x0b19bcULL: return fde_sub_0b19bc(a0, a1, a2);
        case 0x0b1adcULL: return fde_sub_0b1adc(a0, a1, a2);
        case 0x0b1d18ULL: return fde_sub_0b1d18(a0, a1, a2);
        case 0x0b1e48ULL: return fde_sub_0b1e48(a0, a1, a2);
        case 0x0b1f38ULL: return fde_sub_0b1f38(a0, a1, a2);
        case 0x0b1f3cULL: return fde_sub_0b1f3c(a0, a1, a2);
        case 0x0b1f40ULL: return fde_sub_0b1f40(a0, a1, a2);
        case 0x0b1f4cULL: return fde_sub_0b1f4c(a0, a1, a2);
        case 0x0b1f50ULL: return fde_sub_0b1f50(a0, a1, a2);
        case 0x0b1f5cULL: return fde_sub_0b1f5c(a0, a1, a2);
        case 0x0b1f70ULL: return fde_sub_0b1f70(a0, a1, a2);
        case 0x0b1f74ULL: return fde_sub_0b1f74(a0, a1, a2);
        case 0x0b1f80ULL: return fde_sub_0b1f80(a0, a1, a2);
        case 0x0b1f94ULL: return fde_sub_0b1f94(a0, a1, a2);
        case 0x0b1f98ULL: return fde_sub_0b1f98(a0, a1, a2);
        case 0x0b1fa4ULL: return fde_sub_0b1fa4(a0, a1, a2);
        case 0x0b2008ULL: return fde_sub_0b2008(a0, a1, a2);
        case 0x0b2034ULL: return fde_sub_0b2034(a0, a1, a2);
        case 0x0b2038ULL: return fde_sub_0b2038(a0, a1, a2);
        case 0x0b2064ULL: return fde_sub_0b2064(a0, a1, a2);
        case 0x0b2070ULL: return fde_sub_0b2070(a0, a1, a2);
        case 0x0b2074ULL: return fde_sub_0b2074(a0, a1, a2);
        case 0x0b2078ULL: return fde_sub_0b2078(a0, a1, a2);
        case 0x0b207cULL: return fde_sub_0b207c(a0, a1, a2);
        case 0x0b2080ULL: return fde_sub_0b2080(a0, a1, a2);
        case 0x0b2084ULL: return fde_sub_0b2084(a0, a1, a2);
        case 0x0b2130ULL: return fde_sub_0b2130(a0, a1, a2);
        case 0x0b215cULL: return fde_sub_0b215c(a0, a1, a2);
        case 0x0b2160ULL: return fde_sub_0b2160(a0, a1, a2);
        case 0x0b218cULL: return fde_sub_0b218c(a0, a1, a2);
        case 0x0b2198ULL: return fde_sub_0b2198(a0, a1, a2);
        case 0x0b219cULL: return fde_sub_0b219c(a0, a1, a2);
        case 0x0b21a4ULL: return fde_sub_0b21a4(a0, a1, a2);
        case 0x0b21a8ULL: return fde_sub_0b21a8(a0, a1, a2);
        case 0x0b21acULL: return fde_sub_0b21ac(a0, a1, a2);
        case 0x0b21b4ULL: return fde_sub_0b21b4(a0, a1, a2);
        case 0x0b2208ULL: return fde_sub_0b2208(a0, a1, a2);
        case 0x0b2264ULL: return fde_sub_0b2264(a0, a1, a2);
        case 0x0b226cULL: return fde_sub_0b226c(a0, a1, a2);
        case 0x0b22c0ULL: return fde_sub_0b22c0(a0, a1, a2);
        case 0x0b231cULL: return fde_sub_0b231c(a0, a1, a2);
        case 0x0b2324ULL: return fde_sub_0b2324(a0, a1, a2);
        case 0x0b2380ULL: return fde_sub_0b2380(a0, a1, a2);
        case 0x0b23dcULL: return fde_sub_0b23dc(a0, a1, a2);
        case 0x0b2438ULL: return fde_sub_0b2438(a0, a1, a2);
        case 0x0b2494ULL: return fde_sub_0b2494(a0, a1, a2);
        case 0x0b24f0ULL: return fde_sub_0b24f0(a0, a1, a2);
        case 0x0b254cULL: return fde_sub_0b254c(a0, a1, a2);
        case 0x0b25a8ULL: return fde_sub_0b25a8(a0, a1, a2);
        case 0x0b25acULL: return fde_sub_0b25ac(a0, a1, a2);
        case 0x0b25b0ULL: return fde_sub_0b25b0(a0, a1, a2);
        case 0x0b25c4ULL: return fde_sub_0b25c4(a0, a1, a2);
        case 0x0b25c8ULL: return fde_sub_0b25c8(a0, a1, a2);
        case 0x0b25ecULL: return fde_sub_0b25ec(a0, a1, a2);
        case 0x0b25f8ULL: return fde_sub_0b25f8(a0, a1, a2);
        case 0x0b260cULL: return fde_sub_0b260c(a0, a1, a2);
        case 0x0b2610ULL: return fde_sub_0b2610(a0, a1, a2);
        case 0x0b2634ULL: return fde_sub_0b2634(a0, a1, a2);
        case 0x0b2640ULL: return fde_sub_0b2640(a0, a1, a2);
        case 0x0b277cULL: return fde_sub_0b277c(a0, a1, a2);
        case 0x0b27a4ULL: return fde_sub_0b27a4(a0, a1, a2);
        case 0x0b27e4ULL: return fde_sub_0b27e4(a0, a1, a2);
        case 0x0b28d4ULL: return fde_sub_0b28d4(a0, a1, a2);
        case 0x0b29e8ULL: return fde_sub_0b29e8(a0, a1, a2);
        case 0x0b2a24ULL: return fde_sub_0b2a24(a0, a1, a2);
        case 0x0b2a7cULL: return fde_sub_0b2a7c(a0, a1, a2);
        case 0x0b2b88ULL: return fde_sub_0b2b88(a0, a1, a2);
        case 0x0b2b90ULL: return fde_sub_0b2b90(a0, a1, a2);
        case 0x0b2be8ULL: return fde_sub_0b2be8(a0, a1, a2);
        case 0x0b2bf0ULL: return fde_sub_0b2bf0(a0, a1, a2);
        case 0x0b2c04ULL: return fde_sub_0b2c04(a0, a1, a2);
        case 0x0b2c0cULL: return fde_sub_0b2c0c(a0, a1, a2);
        case 0x0b2c14ULL: return fde_sub_0b2c14(a0, a1, a2);
        case 0x0b2c1cULL: return fde_sub_0b2c1c(a0, a1, a2);
        case 0x0b2c44ULL: return fde_sub_0b2c44(a0, a1, a2);
        case 0x0b2c4cULL: return fde_sub_0b2c4c(a0, a1, a2);
        case 0x0b2c54ULL: return fde_sub_0b2c54(a0, a1, a2);
        case 0x0b2cccULL: return fde_sub_0b2ccc(a0, a1, a2);
        case 0x0b31c4ULL: return fde_sub_0b31c4(a0, a1, a2);
        case 0x0b35e8ULL: return fde_sub_0b35e8(a0, a1, a2);
        case 0x0b3b9cULL: return fde_sub_0b3b9c(a0, a1, a2);
        case 0x0b3da8ULL: return fde_sub_0b3da8(a0, a1, a2);
        case 0x0b3e84ULL: return fde_sub_0b3e84(a0, a1, a2);
        case 0x0b3ed0ULL: return fde_sub_0b3ed0(a0, a1, a2);
        case 0x0b3f90ULL: return fde_sub_0b3f90(a0, a1, a2);
        case 0x0b407cULL: return fde_sub_0b407c(a0, a1, a2);
        case 0x0b4170ULL: return fde_sub_0b4170(a0, a1, a2);
        case 0x0b4174ULL: return fde_sub_0b4174(a0, a1, a2);
        case 0x0b42ecULL: return fde_sub_0b42ec(a0, a1, a2);
        case 0x0b43e0ULL: return fde_sub_0b43e0(a0, a1, a2);
        case 0x0b44dcULL: return fde_sub_0b44dc(a0, a1, a2);
        case 0x0b45d4ULL: return fde_sub_0b45d4(a0, a1, a2);
        case 0x0b45f8ULL: return fde_sub_0b45f8(a0, a1, a2);
        case 0x0b46c8ULL: return fde_sub_0b46c8(a0, a1, a2);
        case 0x0b46f0ULL: return fde_sub_0b46f0(a0, a1, a2);
        case 0x0b4730ULL: return fde_sub_0b4730(a0, a1, a2);
        case 0x0b474cULL: return fde_sub_0b474c(a0, a1, a2);
        case 0x0b480cULL: return fde_sub_0b480c(a0, a1, a2);
        case 0x0b48c0ULL: return fde_sub_0b48c0(a0, a1, a2);
        case 0x0b4920ULL: return fde_sub_0b4920(a0, a1, a2);
        case 0x0b4980ULL: return fde_sub_0b4980(a0, a1, a2);
        case 0x0b49e0ULL: return fde_sub_0b49e0(a0, a1, a2);
        case 0x0b4ad0ULL: return fde_sub_0b4ad0(a0, a1, a2);
        case 0x0b4b60ULL: return fde_sub_0b4b60(a0, a1, a2);
        case 0x0b4c5cULL: return fde_sub_0b4c5c(a0, a1, a2);
        case 0x0b4dbcULL: return fde_sub_0b4dbc(a0, a1, a2);
        case 0x0b4dccULL: return fde_sub_0b4dcc(a0, a1, a2);
        case 0x0b51e8ULL: return fde_sub_0b51e8(a0, a1, a2);
        case 0x0b5284ULL: return fde_sub_0b5284(a0, a1, a2);
        case 0x0b53e4ULL: return fde_sub_0b53e4(a0, a1, a2);
        case 0x0b5518ULL: return fde_sub_0b5518(a0, a1, a2);
        case 0x0b5a88ULL: return fde_sub_0b5a88(a0, a1, a2);
        case 0x0b5b24ULL: return fde_sub_0b5b24(a0, a1, a2);
        case 0x0b5b30ULL: return fde_sub_0b5b30(a0, a1, a2);
        case 0x0b5b70ULL: return fde_sub_0b5b70(a0, a1, a2);
        case 0x0b5c04ULL: return fde_sub_0b5c04(a0, a1, a2);
        case 0x0b5c10ULL: return fde_sub_0b5c10(a0, a1, a2);
        case 0x0b5c3cULL: return fde_sub_0b5c3c(a0, a1, a2);
        case 0x0b5d3cULL: return fde_sub_0b5d3c(a0, a1, a2);
        case 0x0b5d40ULL: return fde_sub_0b5d40(a0, a1, a2);
        case 0x0b5d64ULL: return fde_sub_0b5d64(a0, a1, a2);
        case 0x0b5f28ULL: return fde_sub_0b5f28(a0, a1, a2);
        case 0x0b5f68ULL: return fde_sub_0b5f68(a0, a1, a2);
        case 0x0b5fe8ULL: return fde_sub_0b5fe8(a0, a1, a2);
        case 0x0b6080ULL: return fde_sub_0b6080(a0, a1, a2);
        case 0x0b60a0ULL: return fde_sub_0b60a0(a0, a1, a2);
        case 0x0b61f8ULL: return fde_sub_0b61f8(a0, a1, a2);
        case 0x0b6234ULL: return fde_sub_0b6234(a0, a1, a2);
        default: return 0ULL;
    }
}

uint64_t DispatchCxxSharedShard1(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept;
uint64_t DispatchCxxSharedShard2(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept;
uint64_t DispatchCxxSharedShard3(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept;
uint64_t DispatchCxxSharedShard4(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept;

uint64_t ExecuteCxxSharedFdeByAddress(uint64_t fde_pc_begin, uint64_t arg0, uint64_t arg1, uint64_t arg2) noexcept {
    if (fde_pc_begin >= 0x0487b0ULL && fde_pc_begin <= 0x05df68ULL) {
        return DispatchCxxSharedShard1(fde_pc_begin, arg0, arg1, arg2);
    }
    if (fde_pc_begin >= 0x05df98ULL && fde_pc_begin <= 0x074ed0ULL) {
        return DispatchCxxSharedShard2(fde_pc_begin, arg0, arg1, arg2);
    }
    if (fde_pc_begin >= 0x074f74ULL && fde_pc_begin <= 0x0909fcULL) {
        return DispatchCxxSharedShard3(fde_pc_begin, arg0, arg1, arg2);
    }
    if (fde_pc_begin >= 0x090b5cULL && fde_pc_begin <= 0x0a6bf0ULL) {
        return DispatchCxxSharedShard4(fde_pc_begin, arg0, arg1, arg2);
    }
    if (fde_pc_begin >= 0x0a6bf4ULL && fde_pc_begin <= 0x0b6234ULL) {
        return DispatchCxxSharedShard5(fde_pc_begin, arg0, arg1, arg2);
    }
    return 0ULL;
}

} // namespace ndk_libcxx_recon
