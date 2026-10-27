// ============================================================================
// File: applovin_fde_shard_5.cpp
// Target 110 / 169: libapplovin-native-crash-reporter.so (860,200 bytes)
// EN: Clean-room C++17 AArch64 FDE Shard 5/5 covering FDEs [1408..1756]
//     (PC range 0x0b6fc4 .. 0x0c8304).
// VI: Phân mảnh FDE AArch64 C++17 5/5 bao phủ FDE [1408..1756]
//     (Dải địa chỉ PC 0x0b6fc4 .. 0x0c8304).
// ============================================================================
#include "applovin_crash_reporter.h"

namespace applovin {

// FDE #1408 | PC: 0x0b6fc4..0x0b7038 (116 B) | Symbol: sub_0b6fc4
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0b6fc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B6FC4ULL;
}

// FDE #1409 | PC: 0x0b7038..0x0b7040 (8 B) | Symbol: sub_0b7038
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0b7038(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400453DULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B7038ULL;
}

// FDE #1410 | PC: 0x0b7040..0x0b7144 (260 B) | Symbol: sub_0b7040
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0b7040(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B7040ULL;
}

// FDE #1411 | PC: 0x0b7144..0x0b71a8 (100 B) | Symbol: sub_0b7144
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0b7144(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B7144ULL;
}

// FDE #1412 | PC: 0x0b71a8..0x0b71b0 (8 B) | Symbol: sub_0b71a8
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0b71a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140044E1ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B71A8ULL;
}

// FDE #1413 | PC: 0x0b71b0..0x0b72d0 (288 B) | Symbol: sub_0b71b0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x50]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x50]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_0b71b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0120ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B71B0ULL;
}

// FDE #1414 | PC: 0x0b72d0..0x0b7364 (148 B) | Symbol: sub_0b72d0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0b72d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B72D0ULL;
}

// FDE #1415 | PC: 0x0b7364..0x0b7378 (20 B) | Symbol: sub_0b7364
// EN: AArch64 prologue [bti c; ldr x0, [x0, #0x10]; ldr x8, [x0]; ldr x16, [x8, #0x28]] | VI: Khởi đầu hàm AArch64 [bti c; ldr x0, [x0, #0x10]; ldr x8, [x0]; ldr x16, [x8, #0x28]]
uint64_t fde_sub_0b7364(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400800ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B7364ULL;
}

// FDE #1416 | PC: 0x0b7378..0x0b7380 (8 B) | Symbol: sub_0b7378
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0b7378(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400446DULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B7378ULL;
}

// FDE #1417 | PC: 0x0b7380..0x0b74d4 (340 B) | Symbol: sub_0b7380
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0b7380(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0154ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B7380ULL;
}

// FDE #1418 | PC: 0x0b74d4..0x0b74dc (8 B) | Symbol: sub_0b74d4
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0b74d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14004416ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B74D4ULL;
}

// FDE #1419 | PC: 0x0b74dc..0x0b766c (400 B) | Symbol: sub_0b74dc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0b74dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0190ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B74DCULL;
}

// FDE #1420 | PC: 0x0b766c..0x0b7764 (248 B) | Symbol: sub_0b766c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0b766c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B766CULL;
}

// FDE #1421 | PC: 0x0b7764..0x0b776c (8 B) | Symbol: sub_0b7764
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0b7764(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14004372ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B7764ULL;
}

// FDE #1422 | PC: 0x0b776c..0x0b78dc (368 B) | Symbol: sub_0b776c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0b776c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B776CULL;
}

// FDE #1423 | PC: 0x0b78dc..0x0b78e4 (8 B) | Symbol: sub_0b78dc
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0b78dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14004314ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B78DCULL;
}

// FDE #1424 | PC: 0x0b78e4..0x0b79cc (232 B) | Symbol: sub_0b78e4
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0b78e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B78E4ULL;
}

// FDE #1425 | PC: 0x0b79cc..0x0b79d4 (8 B) | Symbol: sub_0b79cc
// EN: AArch64 prologue [bti c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ret]
uint64_t fde_sub_0b79cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B79CCULL;
}

// FDE #1426 | PC: 0x0b79d4..0x0b79dc (8 B) | Symbol: sub_0b79d4
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0b79d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140042D6ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B79D4ULL;
}

// FDE #1427 | PC: 0x0b79dc..0x0b813c (1888 B) | Symbol: sub_0b79dc
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_0b79dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0760ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B79DCULL;
}

// FDE #1428 | PC: 0x0b813c..0x0b8144 (8 B) | Symbol: sub_0b813c
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0b813c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140040FCULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B813CULL;
}

// FDE #1429 | PC: 0x0b8144..0x0b8338 (500 B) | Symbol: sub_0b8144
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x50]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x50]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_0b8144(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B8144ULL;
}

// FDE #1430 | PC: 0x0b8338..0x0b8340 (8 B) | Symbol: sub_0b8338
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0b8338(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400407DULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B8338ULL;
}

// FDE #1431 | PC: 0x0b8340..0x0b86a8 (872 B) | Symbol: sub_0b8340
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0b8340(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0368ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B8340ULL;
}

// FDE #1432 | PC: 0x0b86a8..0x0b86b0 (8 B) | Symbol: sub_0b86a8
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0b86a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14003FA1ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B86A8ULL;
}

// FDE #1433 | PC: 0x0b86b0..0x0b8824 (372 B) | Symbol: sub_0b86b0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0b86b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0174ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B86B0ULL;
}

// FDE #1434 | PC: 0x0b8824..0x0b882c (8 B) | Symbol: sub_0b8824
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0b8824(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14003F42ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B8824ULL;
}

// FDE #1435 | PC: 0x0b882c..0x0b89e0 (436 B) | Symbol: sub_0b882c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0b882c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B882CULL;
}

// FDE #1436 | PC: 0x0b89e0..0x0b89e8 (8 B) | Symbol: sub_0b89e0
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0b89e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14003ED3ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B89E0ULL;
}

// FDE #1437 | PC: 0x0b89e8..0x0b8afc (276 B) | Symbol: sub_0b89e8
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0b89e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B89E8ULL;
}

// FDE #1438 | PC: 0x0b8afc..0x0b8b04 (8 B) | Symbol: sub_0b8afc
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0b8afc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14003E8CULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B8AFCULL;
}

// FDE #1439 | PC: 0x0b8b04..0x0b8bd4 (208 B) | Symbol: sub_0b8b04
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0b8b04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B8B04ULL;
}

// FDE #1440 | PC: 0x0b8bd4..0x0b8d3c (360 B) | Symbol: sub_0b8bd4
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0b8bd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0168ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B8BD4ULL;
}

// FDE #1441 | PC: 0x0b8d3c..0x0b8d44 (8 B) | Symbol: sub_0b8d3c
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0b8d3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14003DFCULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B8D3CULL;
}

// FDE #1442 | PC: 0x0b8d44..0x0b8ed4 (400 B) | Symbol: sub_0b8d44
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0b8d44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0190ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B8D44ULL;
}

// FDE #1443 | PC: 0x0b8ed4..0x0b8edc (8 B) | Symbol: sub_0b8ed4
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0b8ed4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14003D96ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B8ED4ULL;
}

// FDE #1444 | PC: 0x0b8edc..0x0b8f9c (192 B) | Symbol: sub_0b8edc
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x40; stp x29, x30, [sp, #0x10]; str x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x40; stp x29, x30, [sp, #0x10]; str x21, [sp, #0x20]]
uint64_t fde_sub_0b8edc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10103FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B8EDCULL;
}

// FDE #1445 | PC: 0x0b8f9c..0x0b920c (624 B) | Symbol: sub_0b8f9c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0b8f9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0270ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B8F9CULL;
}

// FDE #1446 | PC: 0x0b920c..0x0b940c (512 B) | Symbol: sub_0b920c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0b920c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0200ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B920CULL;
}

// FDE #1447 | PC: 0x0b940c..0x0b950c (256 B) | Symbol: sub_0b940c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0b940c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B940CULL;
}

// FDE #1448 | PC: 0x0b950c..0x0b9520 (20 B) | Symbol: sub_0b950c
// EN: AArch64 prologue [bti c; ldr x0, [x0, #0x18]; ldr x8, [x0]; ldr x16, [x8, #0x30]] | VI: Khởi đầu hàm AArch64 [bti c; ldr x0, [x0, #0x18]; ldr x8, [x0]; ldr x16, [x8, #0x30]]
uint64_t fde_sub_0b950c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400C00ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B950CULL;
}

// FDE #1449 | PC: 0x0b9520..0x0b9528 (8 B) | Symbol: sub_0b9520
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0b9520(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14003C03ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B9520ULL;
}

// FDE #1450 | PC: 0x0b9528..0x0baa84 (5468 B) | Symbol: sub_0b9528
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0b9528(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x155CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0B9528ULL;
}

// FDE #1451 | PC: 0x0baa84..0x0bab10 (140 B) | Symbol: sub_0baa84
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0baa84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BAA84ULL;
}

// FDE #1452 | PC: 0x0bab10..0x0bab18 (8 B) | Symbol: sub_0bab10
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bab10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14003687ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BAB10ULL;
}

// FDE #1453 | PC: 0x0bab18..0x0babec (212 B) | Symbol: sub_0bab18
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0bab18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BAB18ULL;
}

// FDE #1454 | PC: 0x0babec..0x0babf4 (8 B) | Symbol: sub_0babec
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0babec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14003650ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BABECULL;
}

// FDE #1455 | PC: 0x0babf4..0x0baccc (216 B) | Symbol: sub_0babf4
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0babf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BABF4ULL;
}

// FDE #1456 | PC: 0x0baccc..0x0bacd4 (8 B) | Symbol: sub_0baccc
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0baccc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14003618ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BACCCULL;
}

// FDE #1457 | PC: 0x0bacd4..0x0bad94 (192 B) | Symbol: sub_0bacd4
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0bacd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BACD4ULL;
}

// FDE #1458 | PC: 0x0bad94..0x0bada8 (20 B) | Symbol: sub_0bad94
// EN: AArch64 prologue [bti c; ldr x0, [x0, #0x10]; ldr x8, [x0]; ldr x16, [x8, #0x30]] | VI: Khởi đầu hàm AArch64 [bti c; ldr x0, [x0, #0x10]; ldr x8, [x0]; ldr x16, [x8, #0x30]]
uint64_t fde_sub_0bad94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400800ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BAD94ULL;
}

// FDE #1459 | PC: 0x0bada8..0x0badb0 (8 B) | Symbol: sub_0bada8
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bada8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140035E1ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BADA8ULL;
}

// FDE #1460 | PC: 0x0badb0..0x0baec4 (276 B) | Symbol: sub_0badb0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0badb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BADB0ULL;
}

// FDE #1461 | PC: 0x0baec4..0x0baecc (8 B) | Symbol: sub_0baec4
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0baec4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400359AULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BAEC4ULL;
}

// FDE #1462 | PC: 0x0baecc..0x0bb060 (404 B) | Symbol: sub_0baecc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0baecc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0194ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BAECCULL;
}

// FDE #1463 | PC: 0x0bb060..0x0bb068 (8 B) | Symbol: sub_0bb060
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bb060(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14003533ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BB060ULL;
}

// FDE #1464 | PC: 0x0bb068..0x0bb2a8 (576 B) | Symbol: sub_0bb068
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0bb068(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0240ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BB068ULL;
}

// FDE #1465 | PC: 0x0bb2a8..0x0bb2b0 (8 B) | Symbol: sub_0bb2a8
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bb2a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140034A1ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BB2A8ULL;
}

// FDE #1466 | PC: 0x0bb2b0..0x0bb504 (596 B) | Symbol: sub_0bb2b0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0bb2b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0254ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BB2B0ULL;
}

// FDE #1467 | PC: 0x0bb504..0x0bb50c (8 B) | Symbol: sub_0bb504
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bb504(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400340AULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BB504ULL;
}

// FDE #1468 | PC: 0x0bb50c..0x0bb620 (276 B) | Symbol: sub_0bb50c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0bb50c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BB50CULL;
}

// FDE #1469 | PC: 0x0bb620..0x0bb628 (8 B) | Symbol: sub_0bb620
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bb620(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140033C3ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BB620ULL;
}

// FDE #1470 | PC: 0x0bb628..0x0bb798 (368 B) | Symbol: sub_0bb628
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0bb628(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BB628ULL;
}

// FDE #1471 | PC: 0x0bb798..0x0bb7a0 (8 B) | Symbol: sub_0bb798
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bb798(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14003365ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BB798ULL;
}

// FDE #1472 | PC: 0x0bb7a0..0x0bbae8 (840 B) | Symbol: sub_0bb7a0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0bb7a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0348ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BB7A0ULL;
}

// FDE #1473 | PC: 0x0bbae8..0x0bbaf0 (8 B) | Symbol: sub_0bbae8
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bbae8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14003291ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BBAE8ULL;
}

// FDE #1474 | PC: 0x0bbaf0..0x0bbc24 (308 B) | Symbol: sub_0bbaf0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0bbaf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0134ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BBAF0ULL;
}

// FDE #1475 | PC: 0x0bbc24..0x0bbc2c (8 B) | Symbol: sub_0bbc24
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bbc24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14003242ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BBC24ULL;
}

// FDE #1476 | PC: 0x0bbc2c..0x0bbe68 (572 B) | Symbol: sub_0bbc2c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0bbc2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x023CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BBC2CULL;
}

// FDE #1477 | PC: 0x0bbe68..0x0bbe70 (8 B) | Symbol: sub_0bbe68
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bbe68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140031B1ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BBE68ULL;
}

// FDE #1478 | PC: 0x0bbe70..0x0bbfac (316 B) | Symbol: sub_0bbe70
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x50; stp x29, x30, [sp, #0x20]; str x21, [sp, #0x30]]
uint64_t fde_sub_0bbe70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x013CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BBE70ULL;
}

// FDE #1479 | PC: 0x0bbfac..0x0bbfb4 (8 B) | Symbol: sub_0bbfac
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bbfac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14003160ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BBFACULL;
}

// FDE #1480 | PC: 0x0bbfb4..0x0bbfc0 (12 B) | Symbol: sub_0bbfb4
// EN: AArch64 prologue [bti c; add x0, x0, #0x10; b #0xb71b0] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x10; b #0xb71b0]
uint64_t fde_sub_0bbfb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91004000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BBFB4ULL;
}

// FDE #1481 | PC: 0x0bbfc0..0x0bbfc8 (8 B) | Symbol: sub_0bbfc0
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bbfc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400315BULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BBFC0ULL;
}

// FDE #1482 | PC: 0x0bbfc8..0x0bc098 (208 B) | Symbol: sub_0bbfc8
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0bbfc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BBFC8ULL;
}

// FDE #1483 | PC: 0x0bc098..0x0bc0a0 (8 B) | Symbol: sub_0bc098
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bc098(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14003125ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BC098ULL;
}

// FDE #1484 | PC: 0x0bc0a0..0x0bc1b8 (280 B) | Symbol: sub_0bc0a0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0bc0a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0118ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BC0A0ULL;
}

// FDE #1485 | PC: 0x0bc1b8..0x0bc1c0 (8 B) | Symbol: sub_0bc1b8
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bc1b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140030DDULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BC1B8ULL;
}

// FDE #1486 | PC: 0x0bc1c0..0x0bc4a0 (736 B) | Symbol: sub_0bc1c0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0bc1c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x02E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BC1C0ULL;
}

// FDE #1487 | PC: 0x0bc4a0..0x0bc4c8 (40 B) | Symbol: sub_0bc4a0
// EN: AArch64 prologue [bti c; ldrsw x8, [x0, #0xc]; adrp x9, #0xd2000; adrp x10, #0xd2000] | VI: Khởi đầu hàm AArch64 [bti c; ldrsw x8, [x0, #0xc]; adrp x9, #0xd2000; adrp x10, #0xd2000]
uint64_t fde_sub_0bc4a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9800C08ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BC4A0ULL;
}

// FDE #1488 | PC: 0x0bc4c8..0x0bc4d0 (8 B) | Symbol: sub_0bc4c8
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bc4c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14003019ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BC4C8ULL;
}

// FDE #1489 | PC: 0x0bc4d0..0x0bc5d0 (256 B) | Symbol: sub_0bc4d0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0bc4d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BC4D0ULL;
}

// FDE #1490 | PC: 0x0bc5d0..0x0bc5d8 (8 B) | Symbol: sub_0bc5d0
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bc5d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14002FD7ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BC5D0ULL;
}

// FDE #1491 | PC: 0x0bc5d8..0x0bc730 (344 B) | Symbol: sub_0bc5d8
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0bc5d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0158ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BC5D8ULL;
}

// FDE #1492 | PC: 0x0bc730..0x0bc738 (8 B) | Symbol: sub_0bc730
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bc730(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14002F7FULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BC730ULL;
}

// FDE #1493 | PC: 0x0bc738..0x0bc808 (208 B) | Symbol: sub_0bc738
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0bc738(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BC738ULL;
}

// FDE #1494 | PC: 0x0bc808..0x0bc810 (8 B) | Symbol: sub_0bc808
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bc808(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14002F49ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BC808ULL;
}

// FDE #1495 | PC: 0x0bc810..0x0bc910 (256 B) | Symbol: sub_0bc810
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0bc810(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BC810ULL;
}

// FDE #1496 | PC: 0x0bc910..0x0bc918 (8 B) | Symbol: sub_0bc910
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bc910(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14002F07ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BC910ULL;
}

// FDE #1497 | PC: 0x0bc918..0x0bcbe4 (716 B) | Symbol: sub_0bc918
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0bc918(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x02CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BC918ULL;
}

// FDE #1498 | PC: 0x0bcbe4..0x0bcc0c (40 B) | Symbol: sub_0bcbe4
// EN: AArch64 prologue [bti c; ldrsw x8, [x0, #0xc]; adrp x9, #0xd2000; adrp x10, #0xd2000] | VI: Khởi đầu hàm AArch64 [bti c; ldrsw x8, [x0, #0xc]; adrp x9, #0xd2000; adrp x10, #0xd2000]
uint64_t fde_sub_0bcbe4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9800C08ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BCBE4ULL;
}

// FDE #1499 | PC: 0x0bcc0c..0x0bcc14 (8 B) | Symbol: sub_0bcc0c
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bcc0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14002E48ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BCC0CULL;
}

// FDE #1500 | PC: 0x0bcc14..0x0bcc7c (104 B) | Symbol: sub_0bcc14
// EN: AArch64 prologue [bti c; ldr w8, [x1, #0x1c]; cmn w8, #1; b.eq #0xbcc54] | VI: Khởi đầu hàm AArch64 [bti c; ldr w8, [x1, #0x1c]; cmn w8, #1; b.eq #0xbcc54]
uint64_t fde_sub_0bcc14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9401C28ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BCC14ULL;
}

// FDE #1501 | PC: 0x0bcc7c..0x0bcce4 (104 B) | Symbol: sub_0bcc7c
// EN: AArch64 prologue [bti c; ldr w8, [x1, #0x1c]; cmn w8, #1; b.eq #0xbccbc] | VI: Khởi đầu hàm AArch64 [bti c; ldr w8, [x1, #0x1c]; cmn w8, #1; b.eq #0xbccbc]
uint64_t fde_sub_0bcc7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9401C28ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BCC7CULL;
}

// FDE #1502 | PC: 0x0bcce4..0x0bcd4c (104 B) | Symbol: sub_0bcce4
// EN: AArch64 prologue [bti c; ldr w8, [x1, #0x1c]; cmn w8, #1; b.eq #0xbcd24] | VI: Khởi đầu hàm AArch64 [bti c; ldr w8, [x1, #0x1c]; cmn w8, #1; b.eq #0xbcd24]
uint64_t fde_sub_0bcce4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9401C28ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BCCE4ULL;
}

// FDE #1503 | PC: 0x0bcd4c..0x0bcd98 (76 B) | Symbol: sub_0bcd4c
// EN: AArch64 prologue [bti c; ldr w8, [x1, #0x1c]; cmn w8, #1; b.eq #0xbcd80] | VI: Khởi đầu hàm AArch64 [bti c; ldr w8, [x1, #0x1c]; cmn w8, #1; b.eq #0xbcd80]
uint64_t fde_sub_0bcd4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9401C28ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BCD4CULL;
}

// FDE #1504 | PC: 0x0bcd98..0x0bcde4 (76 B) | Symbol: sub_0bcd98
// EN: AArch64 prologue [bti c; ldr w8, [x1, #0x1c]; cmn w8, #1; b.eq #0xbcdcc] | VI: Khởi đầu hàm AArch64 [bti c; ldr w8, [x1, #0x1c]; cmn w8, #1; b.eq #0xbcdcc]
uint64_t fde_sub_0bcd98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9401C28ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BCD98ULL;
}

// FDE #1505 | PC: 0x0bcde4..0x0bce30 (76 B) | Symbol: sub_0bcde4
// EN: AArch64 prologue [bti c; ldr w8, [x1, #0x1c]; cmn w8, #1; b.eq #0xbce18] | VI: Khởi đầu hàm AArch64 [bti c; ldr w8, [x1, #0x1c]; cmn w8, #1; b.eq #0xbce18]
uint64_t fde_sub_0bcde4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9401C28ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BCDE4ULL;
}

// FDE #1506 | PC: 0x0bce30..0x0bce38 (8 B) | Symbol: sub_0bce30
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bce30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14002DBFULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BCE30ULL;
}

// FDE #1507 | PC: 0x0bce38..0x0bcf70 (312 B) | Symbol: sub_0bce38
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0bce38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0138ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BCE38ULL;
}

// FDE #1508 | PC: 0x0bcf70..0x0bcf78 (8 B) | Symbol: sub_0bcf70
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bcf70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14002D6FULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BCF70ULL;
}

// FDE #1509 | PC: 0x0bcf78..0x0bd024 (172 B) | Symbol: sub_0bcf78
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0bcf78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BCF78ULL;
}

// FDE #1510 | PC: 0x0bd024..0x0bd038 (20 B) | Symbol: sub_0bd024
// EN: AArch64 prologue [bti c; ldr x0, [x0, #0x10]; ldr x8, [x0]; ldr x16, [x8, #0x30]] | VI: Khởi đầu hàm AArch64 [bti c; ldr x0, [x0, #0x10]; ldr x8, [x0]; ldr x16, [x8, #0x30]]
uint64_t fde_sub_0bd024(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400800ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BD024ULL;
}

// FDE #1511 | PC: 0x0bd038..0x0bd040 (8 B) | Symbol: sub_0bd038
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bd038(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14002D3DULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BD038ULL;
}

// FDE #1512 | PC: 0x0bd040..0x0bd110 (208 B) | Symbol: sub_0bd040
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0bd040(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BD040ULL;
}

// FDE #1513 | PC: 0x0bd110..0x0bd124 (20 B) | Symbol: sub_0bd110
// EN: AArch64 prologue [bti c; ldr x0, [x0, #0x10]; ldr x8, [x0]; ldr x16, [x8, #0x30]] | VI: Khởi đầu hàm AArch64 [bti c; ldr x0, [x0, #0x10]; ldr x8, [x0]; ldr x16, [x8, #0x30]]
uint64_t fde_sub_0bd110(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400800ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BD110ULL;
}

// FDE #1514 | PC: 0x0bd124..0x0bd12c (8 B) | Symbol: sub_0bd124
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bd124(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14002D02ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BD124ULL;
}

// FDE #1515 | PC: 0x0bd12c..0x0bd138 (12 B) | Symbol: sub_0bd12c
// EN: AArch64 prologue [bti c; add x0, x0, #0x10; b #0xb71b0] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x10; b #0xb71b0]
uint64_t fde_sub_0bd12c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91004000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BD12CULL;
}

// FDE #1516 | PC: 0x0bd138..0x0bd140 (8 B) | Symbol: sub_0bd138
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bd138(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14002CFDULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BD138ULL;
}

// FDE #1517 | PC: 0x0bd140..0x0bd22c (236 B) | Symbol: sub_0bd140
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0bd140(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BD140ULL;
}

// FDE #1518 | PC: 0x0bd22c..0x0bd234 (8 B) | Symbol: sub_0bd22c
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bd22c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14002CC0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BD22CULL;
}

// FDE #1519 | PC: 0x0bd234..0x0bd240 (12 B) | Symbol: sub_0bd234
// EN: AArch64 prologue [bti c; mov w0, #1; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #1; ret]
uint64_t fde_sub_0bd234(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800020ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BD234ULL;
}

// FDE #1520 | PC: 0x0bd240..0x0bd24c (12 B) | Symbol: sub_0bd240
// EN: AArch64 prologue [bti c; mov w0, #1; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #1; ret]
uint64_t fde_sub_0bd240(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800020ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BD240ULL;
}

// FDE #1521 | PC: 0x0bd24c..0x0bd34c (256 B) | Symbol: sub_0bd24c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0bd24c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BD24CULL;
}

// FDE #1522 | PC: 0x0bd34c..0x0bd684 (824 B) | Symbol: sub_0bd34c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0bd34c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0338ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BD34CULL;
}

// FDE #1523 | PC: 0x0bd684..0x0bd68c (8 B) | Symbol: sub_0bd684
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bd684(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14002BAAULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BD684ULL;
}

// FDE #1524 | PC: 0x0bd68c..0x0bd7f8 (364 B) | Symbol: sub_0bd68c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0bd68c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x016CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BD68CULL;
}

// FDE #1525 | PC: 0x0bd7f8..0x0bd800 (8 B) | Symbol: sub_0bd7f8
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bd7f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14002B4DULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BD7F8ULL;
}

// FDE #1526 | PC: 0x0bd800..0x0bdd08 (1288 B) | Symbol: sub_0bd800
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x10]; str x27, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x10]; str x27, [sp, #0x20]]
uint64_t fde_sub_0bd800(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0508ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BD800ULL;
}

// FDE #1527 | PC: 0x0bdd08..0x0be0c8 (960 B) | Symbol: sub_0bdd08
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0bdd08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x03C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BDD08ULL;
}

// FDE #1528 | PC: 0x0be0c8..0x0be228 (352 B) | Symbol: sub_0be0c8
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0be0c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0160ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BE0C8ULL;
}

// FDE #1529 | PC: 0x0be228..0x0be340 (280 B) | Symbol: sub_0be228
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0be228(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0118ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BE228ULL;
}

// FDE #1530 | PC: 0x0be340..0x0be348 (8 B) | Symbol: sub_0be340
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0be340(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400287BULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BE340ULL;
}

// FDE #1531 | PC: 0x0be348..0x0be42c (228 B) | Symbol: sub_0be348
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0be348(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BE348ULL;
}

// FDE #1532 | PC: 0x0be42c..0x0be434 (8 B) | Symbol: sub_0be42c
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0be42c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14002840ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BE42CULL;
}

// FDE #1533 | PC: 0x0be434..0x0be440 (12 B) | Symbol: sub_0be434
// EN: AArch64 prologue [bti c; mov w0, #1; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #1; ret]
uint64_t fde_sub_0be434(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800020ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BE434ULL;
}

// FDE #1534 | PC: 0x0be440..0x0be44c (12 B) | Symbol: sub_0be440
// EN: AArch64 prologue [bti c; mov w0, #1; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #1; ret]
uint64_t fde_sub_0be440(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800020ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BE440ULL;
}

// FDE #1535 | PC: 0x0be44c..0x0be4d4 (136 B) | Symbol: sub_0be44c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0be44c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BE44CULL;
}

// FDE #1536 | PC: 0x0be4d4..0x0be858 (900 B) | Symbol: sub_0be4d4
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0be4d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0384ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BE4D4ULL;
}

// FDE #1537 | PC: 0x0be858..0x0be860 (8 B) | Symbol: sub_0be858
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0be858(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14002735ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BE858ULL;
}

// FDE #1538 | PC: 0x0be860..0x0be9cc (364 B) | Symbol: sub_0be860
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0be860(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x016CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BE860ULL;
}

// FDE #1539 | PC: 0x0be9cc..0x0be9d4 (8 B) | Symbol: sub_0be9cc
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0be9cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140026D8ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BE9CCULL;
}

// FDE #1540 | PC: 0x0be9d4..0x0beaf0 (284 B) | Symbol: sub_0be9d4
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0be9d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BE9D4ULL;
}

// FDE #1541 | PC: 0x0beaf0..0x0beaf8 (8 B) | Symbol: sub_0beaf0
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0beaf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400268FULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BEAF0ULL;
}

// FDE #1542 | PC: 0x0beaf8..0x0beb24 (44 B) | Symbol: sub_0beaf8
// EN: AArch64 prologue [bti c; ldr x0, [x0, #0x10]; ldrb w8, [x0, #9]; cmp w8, #2] | VI: Khởi đầu hàm AArch64 [bti c; ldr x0, [x0, #0x10]; ldrb w8, [x0, #9]; cmp w8, #2]
uint64_t fde_sub_0beaf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400800ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BEAF8ULL;
}

// FDE #1543 | PC: 0x0beb24..0x0beb50 (44 B) | Symbol: sub_0beb24
// EN: AArch64 prologue [bti c; ldr x0, [x0, #0x10]; ldrb w8, [x0, #0xa]; cmp w8, #2] | VI: Khởi đầu hàm AArch64 [bti c; ldr x0, [x0, #0x10]; ldrb w8, [x0, #0xa]; cmp w8, #2]
uint64_t fde_sub_0beb24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400800ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BEB24ULL;
}

// FDE #1544 | PC: 0x0beb50..0x0beb7c (44 B) | Symbol: sub_0beb50
// EN: AArch64 prologue [bti c; ldr x0, [x0, #0x10]; ldrb w8, [x0, #0xb]; cmp w8, #2] | VI: Khởi đầu hàm AArch64 [bti c; ldr x0, [x0, #0x10]; ldrb w8, [x0, #0xb]; cmp w8, #2]
uint64_t fde_sub_0beb50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400800ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BEB50ULL;
}

// FDE #1545 | PC: 0x0beb7c..0x0becf8 (380 B) | Symbol: sub_0beb7c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0beb7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x017CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BEB7CULL;
}

// FDE #1546 | PC: 0x0becf8..0x0bed0c (20 B) | Symbol: sub_0becf8
// EN: AArch64 prologue [bti c; ldr x0, [x0, #0x10]; ldr x8, [x0]; ldr x16, [x8, #0x28]] | VI: Khởi đầu hàm AArch64 [bti c; ldr x0, [x0, #0x10]; ldr x8, [x0]; ldr x16, [x8, #0x28]]
uint64_t fde_sub_0becf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400800ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BECF8ULL;
}

// FDE #1547 | PC: 0x0bed0c..0x0bed14 (8 B) | Symbol: sub_0bed0c
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bed0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14002608ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BED0CULL;
}

// FDE #1548 | PC: 0x0bed14..0x0bee2c (280 B) | Symbol: sub_0bed14
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0bed14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0118ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BED14ULL;
}

// FDE #1549 | PC: 0x0bee2c..0x0bee34 (8 B) | Symbol: sub_0bee2c
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bee2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140025C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BEE2CULL;
}

// FDE #1550 | PC: 0x0bee34..0x0bef84 (336 B) | Symbol: sub_0bee34
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0bee34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0150ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BEE34ULL;
}

// FDE #1551 | PC: 0x0bef84..0x0bef8c (8 B) | Symbol: sub_0bef84
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bef84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400256AULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BEF84ULL;
}

// FDE #1552 | PC: 0x0bef8c..0x0bef98 (12 B) | Symbol: sub_0bef8c
// EN: AArch64 prologue [bti c; mov w0, #1; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #1; ret]
uint64_t fde_sub_0bef8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800020ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BEF8CULL;
}

// FDE #1553 | PC: 0x0bef98..0x0befa4 (12 B) | Symbol: sub_0bef98
// EN: AArch64 prologue [bti c; mov w0, #1; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, #1; ret]
uint64_t fde_sub_0bef98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800020ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BEF98ULL;
}

// FDE #1554 | PC: 0x0befa4..0x0befb8 (20 B) | Symbol: sub_0befa4
// EN: AArch64 prologue [bti c; ldr x0, [x0, #0x10]; ldr x8, [x0]; ldr x16, [x8, #0x20]] | VI: Khởi đầu hàm AArch64 [bti c; ldr x0, [x0, #0x10]; ldr x8, [x0]; ldr x16, [x8, #0x20]]
uint64_t fde_sub_0befa4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400800ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BEFA4ULL;
}

// FDE #1555 | PC: 0x0befb8..0x0bf144 (396 B) | Symbol: sub_0befb8
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0befb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x018CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BEFB8ULL;
}

// FDE #1556 | PC: 0x0bf144..0x0bf14c (8 B) | Symbol: sub_0bf144
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bf144(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140024FAULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BF144ULL;
}

// FDE #1557 | PC: 0x0bf14c..0x0bf178 (44 B) | Symbol: sub_0bf14c
// EN: AArch64 prologue [bti c; ldr x0, [x0, #0x18]; ldrb w8, [x0, #9]; cmp w8, #2] | VI: Khởi đầu hàm AArch64 [bti c; ldr x0, [x0, #0x18]; ldrb w8, [x0, #9]; cmp w8, #2]
uint64_t fde_sub_0bf14c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400C00ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BF14CULL;
}

// FDE #1558 | PC: 0x0bf178..0x0bf334 (444 B) | Symbol: sub_0bf178
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0bf178(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BF178ULL;
}

// FDE #1559 | PC: 0x0bf334..0x0bf410 (220 B) | Symbol: sub_0bf334
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0bf334(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BF334ULL;
}

// FDE #1560 | PC: 0x0bf410..0x0bf418 (8 B) | Symbol: sub_0bf410
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bf410(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14002447ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BF410ULL;
}

// FDE #1561 | PC: 0x0bf418..0x0bf548 (304 B) | Symbol: sub_0bf418
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0bf418(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BF418ULL;
}

// FDE #1562 | PC: 0x0bf548..0x0bf550 (8 B) | Symbol: sub_0bf548
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bf548(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140023F9ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BF548ULL;
}

// FDE #1563 | PC: 0x0bf550..0x0bf57c (44 B) | Symbol: sub_0bf550
// EN: AArch64 prologue [bti c; ldr x0, [x0, #0x10]; ldrb w8, [x0, #9]; cmp w8, #2] | VI: Khởi đầu hàm AArch64 [bti c; ldr x0, [x0, #0x10]; ldrb w8, [x0, #9]; cmp w8, #2]
uint64_t fde_sub_0bf550(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400800ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BF550ULL;
}

// FDE #1564 | PC: 0x0bf57c..0x0bf8b0 (820 B) | Symbol: sub_0bf57c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0bf57c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0334ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BF57CULL;
}

// FDE #1565 | PC: 0x0bf8b0..0x0bf9f8 (328 B) | Symbol: sub_0bf8b0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0bf8b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0148ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BF8B0ULL;
}

// FDE #1566 | PC: 0x0bf9f8..0x0bfa00 (8 B) | Symbol: sub_0bf9f8
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bf9f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140022CDULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BF9F8ULL;
}

// FDE #1567 | PC: 0x0bfa00..0x0bfa2c (44 B) | Symbol: sub_0bfa00
// EN: AArch64 prologue [bti c; ldr x0, [x0, #0x10]; ldrb w8, [x0, #9]; cmp w8, #2] | VI: Khởi đầu hàm AArch64 [bti c; ldr x0, [x0, #0x10]; ldrb w8, [x0, #9]; cmp w8, #2]
uint64_t fde_sub_0bfa00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400800ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BFA00ULL;
}

// FDE #1568 | PC: 0x0bfa2c..0x0bfcd0 (676 B) | Symbol: sub_0bfa2c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0bfa2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x02A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BFA2CULL;
}

// FDE #1569 | PC: 0x0bfcd0..0x0bfe3c (364 B) | Symbol: sub_0bfcd0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0bfcd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x016CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BFCD0ULL;
}

// FDE #1570 | PC: 0x0bfe3c..0x0bfe44 (8 B) | Symbol: sub_0bfe3c
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bfe3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140021BCULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BFE3CULL;
}

// FDE #1571 | PC: 0x0bfe44..0x0bfeec (168 B) | Symbol: sub_0bfe44
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0bfe44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BFE44ULL;
}

// FDE #1572 | PC: 0x0bfeec..0x0bfef4 (8 B) | Symbol: sub_0bfeec
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0bfeec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14002190ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BFEECULL;
}

// FDE #1573 | PC: 0x0bfef4..0x0bff00 (12 B) | Symbol: sub_0bfef4
// EN: AArch64 prologue [bti c; str x1, [x0]; ret] | VI: Khởi đầu hàm AArch64 [bti c; str x1, [x0]; ret]
uint64_t fde_sub_0bfef4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000001ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BFEF4ULL;
}

// FDE #1574 | PC: 0x0bff00..0x0bff0c (12 B) | Symbol: sub_0bff00
// EN: AArch64 prologue [bti c; ldr x0, [x0]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldr x0, [x0]; ret]
uint64_t fde_sub_0bff00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BFF00ULL;
}

// FDE #1575 | PC: 0x0bff0c..0x0bff30 (36 B) | Symbol: sub_0bff0c
// EN: AArch64 prologue [bti c; ldr x8, [x0]; mov x9, #0x2b2b; movk x9, #0x4743, lsl #16] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0]; mov x9, #0x2b2b; movk x9, #0x4743, lsl #16]
uint64_t fde_sub_0bff0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BFF0CULL;
}

// FDE #1576 | PC: 0x0bff30..0x0bff84 (84 B) | Symbol: __cxa_allocate_exception
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0bff30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BFF30ULL;
}

// FDE #1577 | PC: 0x0bff84..0x0bffa8 (36 B) | Symbol: __cxa_free_exception
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x0, x0, #0x80] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x0, x0, #0x80]
uint64_t fde_sub_0bff84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BFF84ULL;
}

// FDE #1578 | PC: 0x0bffa8..0x0bffe4 (60 B) | Symbol: __cxa_allocate_dependent_exception
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w0, #0x80] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w0, #0x80]
uint64_t fde_sub_0bffa8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BFFA8ULL;
}

// FDE #1579 | PC: 0x0bffe4..0x0bffec (8 B) | Symbol: __cxa_free_dependent_exception
// EN: AArch64 prologue [bti c; b #0xc19b0] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc19b0]
uint64_t fde_sub_0bffe4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000672ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BFFE4ULL;
}

// FDE #1580 | PC: 0x0bffec..0x0c006c (128 B) | Symbol: __cxa_throw
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0bffec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0BFFECULL;
}

// FDE #1581 | PC: 0x0c006c..0x0c0088 (28 B) | Symbol: sub_0c006c
// EN: AArch64 prologue [bti c; mov x8, #0x2b00; movk x8, #0x432b, lsl #16; movk x8, #0x4e47, lsl #32] | VI: Khởi đầu hàm AArch64 [bti c; mov x8, #0x2b00; movk x8, #0x432b, lsl #16; movk x8, #0x4e47, lsl #32]
uint64_t fde_sub_0c006c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD2856008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C006CULL;
}

// FDE #1582 | PC: 0x0c0088..0x0c00f4 (108 B) | Symbol: sub_0c0088
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c0088(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C0088ULL;
}

// FDE #1583 | PC: 0x0c00f4..0x0c0118 (36 B) | Symbol: sub_0c00f4
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c00f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C00F4ULL;
}

// FDE #1584 | PC: 0x0c0118..0x0c0124 (12 B) | Symbol: __cxa_get_exception_ptr
// EN: AArch64 prologue [bti c; ldur x0, [x0, #-8]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldur x0, [x0, #-8]; ret]
uint64_t fde_sub_0c0118(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF85F8000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C0118ULL;
}

// FDE #1585 | PC: 0x0c0124..0x0c01c0 (156 B) | Symbol: __cxa_begin_catch
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c0124(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C0124ULL;
}

// FDE #1586 | PC: 0x0c01c0..0x0c02a8 (232 B) | Symbol: __cxa_end_catch
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c01c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C01C0ULL;
}

// FDE #1587 | PC: 0x0c02a8..0x0c0304 (92 B) | Symbol: __cxa_decrement_exception_refcount
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c02a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C02A8ULL;
}

// FDE #1588 | PC: 0x0c0304..0x0c0354 (80 B) | Symbol: __cxa_current_exception_type
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc9b70] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc9b70]
uint64_t fde_sub_0c0304(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C0304ULL;
}

// FDE #1589 | PC: 0x0c0354..0x0c0440 (236 B) | Symbol: __cxa_rethrow
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0c0354(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C0354ULL;
}

// FDE #1590 | PC: 0x0c0440..0x0c0460 (32 B) | Symbol: __cxa_increment_exception_refcount
// EN: AArch64 prologue [bti c; cbz x0, #0xc045c; sub x8, x0, #0x78; ldaxr x9, [x8]] | VI: Khởi đầu hàm AArch64 [bti c; cbz x0, #0xc045c; sub x8, x0, #0x78; ldaxr x9, [x8]]
uint64_t fde_sub_0c0440(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB40000C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C0440ULL;
}

// FDE #1591 | PC: 0x0c0460..0x0c04dc (124 B) | Symbol: __cxa_current_primary_exception
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc9b70] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc9b70]
uint64_t fde_sub_0c0460(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C0460ULL;
}

// FDE #1592 | PC: 0x0c04dc..0x0c0600 (292 B) | Symbol: __cxa_rethrow_primary_exception
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0c04dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0124ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C04DCULL;
}

// FDE #1593 | PC: 0x0c0600..0x0c0678 (120 B) | Symbol: sub_0c0600
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c0600(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C0600ULL;
}

// FDE #1594 | PC: 0x0c0678..0x0c06a8 (48 B) | Symbol: __cxa_uncaught_exception
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc9b70] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc9b70]
uint64_t fde_sub_0c0678(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C0678ULL;
}

// FDE #1595 | PC: 0x0c06a8..0x0c06d0 (40 B) | Symbol: __cxa_uncaught_exceptions
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc9b70] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0xc9b70]
uint64_t fde_sub_0c06a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C06A8ULL;
}

// FDE #1596 | PC: 0x0c06d0..0x0c06f4 (36 B) | Symbol: __cxa_get_globals
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0xd9000] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0xd9000]
uint64_t fde_sub_0c06d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C06D0ULL;
}

// FDE #1597 | PC: 0x0c06f4..0x0c0718 (36 B) | Symbol: __cxa_get_globals_fast
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0xd9000] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0xd9000]
uint64_t fde_sub_0c06f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C06F4ULL;
}

// FDE #1598 | PC: 0x0c0718..0x0c0874 (348 B) | Symbol: __cxa_guard_acquire
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0c0718(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x015CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C0718ULL;
}

// FDE #1599 | PC: 0x0c0874..0x0c0924 (176 B) | Symbol: __cxa_guard_release
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0c0874(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C0874ULL;
}

// FDE #1600 | PC: 0x0c0924..0x0c09c8 (164 B) | Symbol: __cxa_guard_abort
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c0924(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C0924ULL;
}

// FDE #1601 | PC: 0x0c09c8..0x0c09dc (20 B) | Symbol: _ZSt14get_unexpectedv
// EN: AArch64 prologue [bti c; adrp x8, #0xd4000; ldr x8, [x8, #0x948]; ldar x0, [x8]] | VI: Khởi đầu hàm AArch64 [bti c; adrp x8, #0xd4000; ldr x8, [x8, #0x948]; ldar x0, [x8]]
uint64_t fde_sub_0c09c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900000A8ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C09C8ULL;
}

// FDE #1602 | PC: 0x0c09dc..0x0c0a20 (68 B) | Symbol: _ZSt9terminatev
// EN: AArch64 prologue [paciasp; stp x30, x19, [sp, #-0x10]!; bl #0xc9b70; cbz x0, #0xc09f4] | VI: Khởi đầu hàm AArch64 [paciasp; stp x30, x19, [sp, #-0x10]!; bl #0xc9b70; cbz x0, #0xc09f4]
uint64_t fde_sub_0c09dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF4FFEULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C09DCULL;
}

// FDE #1603 | PC: 0x0c0a20..0x0c0a3c (28 B) | Symbol: sub_0c0a20
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; blr x0] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; blr x0]
uint64_t fde_sub_0c0a20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C0A20ULL;
}

// FDE #1604 | PC: 0x0c0a3c..0x0c0a58 (28 B) | Symbol: _ZSt10unexpectedv
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xd4000] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xd4000]
uint64_t fde_sub_0c0a3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C0A3CULL;
}

// FDE #1605 | PC: 0x0c0a58..0x0c0a6c (20 B) | Symbol: _ZSt13get_terminatev
// EN: AArch64 prologue [bti c; adrp x8, #0xd4000; ldr x8, [x8, #0x950]; ldar x0, [x8]] | VI: Khởi đầu hàm AArch64 [bti c; adrp x8, #0xd4000; ldr x8, [x8, #0x950]; ldar x0, [x8]]
uint64_t fde_sub_0c0a58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900000A8ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C0A58ULL;
}

// FDE #1606 | PC: 0x0c0a6c..0x0c0ab0 (68 B) | Symbol: sub_0c0a6c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c0a6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C0A6CULL;
}

// FDE #1607 | PC: 0x0c0ab0..0x0c0ad0 (32 B) | Symbol: _ZSt15set_new_handlerPFvvE
// EN: AArch64 prologue [bti c; adrp x9, #0xd4000; ldr x9, [x9, #0x960]; ldaxr x8, [x9]] | VI: Khởi đầu hàm AArch64 [bti c; adrp x9, #0xd4000; ldr x9, [x9, #0x960]; ldaxr x8, [x9]]
uint64_t fde_sub_0c0ab0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900000A9ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C0AB0ULL;
}

// FDE #1608 | PC: 0x0c0ad0..0x0c0ae4 (20 B) | Symbol: _ZSt15get_new_handlerv
// EN: AArch64 prologue [bti c; adrp x8, #0xd4000; ldr x8, [x8, #0x960]; ldar x0, [x8]] | VI: Khởi đầu hàm AArch64 [bti c; adrp x8, #0xd4000; ldr x8, [x8, #0x960]; ldar x0, [x8]]
uint64_t fde_sub_0c0ad0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900000A8ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C0AD0ULL;
}

// FDE #1609 | PC: 0x0c0ae4..0x0c0cb4 (464 B) | Symbol: __gxx_personality_v0
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; str x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x40]; str x23, [sp, #0x50]]
uint64_t fde_sub_0c0ae4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C0AE4ULL;
}

// FDE #1610 | PC: 0x0c0cb4..0x0c129c (1512 B) | Symbol: sub_0c0cb4
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xc0; stp x29, x30, [sp, #0x60]; stp x28, x27, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xc0; stp x29, x30, [sp, #0x60]; stp x28, x27, [sp, #0x70]]
uint64_t fde_sub_0c0cb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10303FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x05E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C0CB4ULL;
}

// FDE #1611 | PC: 0x0c129c..0x0c12cc (48 B) | Symbol: sub_0c129c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c129c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C129CULL;
}

// FDE #1612 | PC: 0x0c12cc..0x0c163c (880 B) | Symbol: __cxa_call_unexpected
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xb0; stp x29, x30, [sp, #0x50]; stp x28, x27, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xb0; stp x29, x30, [sp, #0x50]; stp x28, x27, [sp, #0x60]]
uint64_t fde_sub_0c12cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD102C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0370ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C12CCULL;
}

// FDE #1613 | PC: 0x0c163c..0x0c17b4 (376 B) | Symbol: sub_0c163c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; and w9, w1, #0xff] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; and w9, w1, #0xff]
uint64_t fde_sub_0c163c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C163CULL;
}

// FDE #1614 | PC: 0x0c17b4..0x0c17cc (24 B) | Symbol: __cxa_pure_virtual
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0x49000] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0x49000]
uint64_t fde_sub_0c17b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C17B4ULL;
}

// FDE #1615 | PC: 0x0c17cc..0x0c17e4 (24 B) | Symbol: __cxa_deleted_virtual
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0x47000] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0x47000]
uint64_t fde_sub_0c17cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C17CCULL;
}

// FDE #1616 | PC: 0x0c17e4..0x0c1858 (116 B) | Symbol: sub_0c17e4
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x30; stp x29, x30, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x30; stp x29, x30, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0c17e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD100C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C17E4ULL;
}

// FDE #1617 | PC: 0x0c1858..0x0c194c (244 B) | Symbol: sub_0c1858
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c1858(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C1858ULL;
}

// FDE #1618 | PC: 0x0c194c..0x0c19b0 (100 B) | Symbol: sub_0c194c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0c194c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C194CULL;
}

// FDE #1619 | PC: 0x0c19b0..0x0c19dc (44 B) | Symbol: sub_0c19b0
// EN: AArch64 prologue [bti c; adrp x8, #0xda000; add x8, x8, #0xa30; cmp x0, x8] | VI: Khởi đầu hàm AArch64 [bti c; adrp x8, #0xda000; add x8, x8, #0xa30; cmp x0, x8]
uint64_t fde_sub_0c19b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00000C8ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C19B0ULL;
}

// FDE #1620 | PC: 0x0c19dc..0x0c1ae4 (264 B) | Symbol: sub_0c19dc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c19dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0108ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C19DCULL;
}

// FDE #1621 | PC: 0x0c1ae4..0x0c1b10 (44 B) | Symbol: sub_0c1ae4
// EN: AArch64 prologue [bti c; adrp x8, #0xda000; add x8, x8, #0xa30; cmp x0, x8] | VI: Khởi đầu hàm AArch64 [bti c; adrp x8, #0xda000; add x8, x8, #0xa30; cmp x0, x8]
uint64_t fde_sub_0c1ae4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00000C8ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C1AE4ULL;
}

// FDE #1622 | PC: 0x0c1b10..0x0c1b18 (8 B) | Symbol: sub_0c1b10
// EN: AArch64 prologue [bti c; b #0xc9c60] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc9c60]
uint64_t fde_sub_0c1b10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14002053ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C1B10ULL;
}

// FDE #1623 | PC: 0x0c1b18..0x0c1b20 (8 B) | Symbol: sub_0c1b18
// EN: AArch64 prologue [bti c; brk #1] | VI: Khởi đầu hàm AArch64 [bti c; brk #1]
uint64_t fde_sub_0c1b18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD4200020ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C1B18ULL;
}

// FDE #1624 | PC: 0x0c1b20..0x0c1b28 (8 B) | Symbol: sub_0c1b20
// EN: AArch64 prologue [bti c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ret]
uint64_t fde_sub_0c1b20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C1B20ULL;
}

// FDE #1625 | PC: 0x0c1b28..0x0c1b30 (8 B) | Symbol: sub_0c1b28
// EN: AArch64 prologue [bti c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ret]
uint64_t fde_sub_0c1b28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C1B28ULL;
}

// FDE #1626 | PC: 0x0c1b30..0x0c1b5c (44 B) | Symbol: sub_0c1b30
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c1b30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C1B30ULL;
}

// FDE #1627 | PC: 0x0c1b5c..0x0c1b88 (44 B) | Symbol: sub_0c1b5c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c1b5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C1B5CULL;
}

// FDE #1628 | PC: 0x0c1b88..0x0c1bb4 (44 B) | Symbol: sub_0c1b88
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c1b88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C1B88ULL;
}

// FDE #1629 | PC: 0x0c1bb4..0x0c1be0 (44 B) | Symbol: sub_0c1bb4
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c1bb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C1BB4ULL;
}

// FDE #1630 | PC: 0x0c1be0..0x0c1c0c (44 B) | Symbol: sub_0c1be0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c1be0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C1BE0ULL;
}

// FDE #1631 | PC: 0x0c1c0c..0x0c1c38 (44 B) | Symbol: sub_0c1c0c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c1c0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C1C0CULL;
}

// FDE #1632 | PC: 0x0c1c38..0x0c1c64 (44 B) | Symbol: sub_0c1c38
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c1c38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C1C38ULL;
}

// FDE #1633 | PC: 0x0c1c64..0x0c1c90 (44 B) | Symbol: sub_0c1c64
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c1c64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C1C64ULL;
}

// FDE #1634 | PC: 0x0c1c90..0x0c1cbc (44 B) | Symbol: sub_0c1c90
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c1c90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C1C90ULL;
}

// FDE #1635 | PC: 0x0c1cbc..0x0c1ce8 (44 B) | Symbol: sub_0c1cbc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c1cbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C1CBCULL;
}

// FDE #1636 | PC: 0x0c1ce8..0x0c1d00 (24 B) | Symbol: sub_0c1ce8
// EN: AArch64 prologue [bti c; ldr x8, [x0, #8]; ldr x9, [x1, #8]; cmp x8, x9] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0, #8]; ldr x9, [x1, #8]; cmp x8, x9]
uint64_t fde_sub_0c1ce8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400408ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C1CE8ULL;
}

// FDE #1637 | PC: 0x0c1d00..0x0c1d0c (12 B) | Symbol: sub_0c1d00
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_0c1d00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C1D00ULL;
}

// FDE #1638 | PC: 0x0c1d0c..0x0c1d18 (12 B) | Symbol: sub_0c1d0c
// EN: AArch64 prologue [bti c; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, wzr; ret]
uint64_t fde_sub_0c1d0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C1D0CULL;
}

// FDE #1639 | PC: 0x0c1d18..0x0c1d30 (24 B) | Symbol: sub_0c1d18
// EN: AArch64 prologue [bti c; ldr x8, [x0, #8]; ldr x9, [x1, #8]; cmp x8, x9] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0, #8]; ldr x9, [x1, #8]; cmp x8, x9]
uint64_t fde_sub_0c1d18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400408ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C1D18ULL;
}

// FDE #1640 | PC: 0x0c1d30..0x0c1e18 (232 B) | Symbol: sub_0c1d30
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x60]; str x21, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x60]; str x21, [sp, #0x70]]
uint64_t fde_sub_0c1d30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10243FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C1D30ULL;
}

// FDE #1641 | PC: 0x0c1e18..0x0c1e74 (92 B) | Symbol: sub_0c1e18
// EN: AArch64 prologue [bti c; ldr x8, [x1, #0x20]; cbz x8, #0xc1e4c; cmp x8, x2] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x1, #0x20]; cbz x8, #0xc1e4c; cmp x8, x2]
uint64_t fde_sub_0c1e18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401028ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C1E18ULL;
}

// FDE #1642 | PC: 0x0c1e74..0x0c1ee8 (116 B) | Symbol: sub_0c1e74
// EN: AArch64 prologue [bti c; ldr x8, [x1, #0x10]; ldr x9, [x0, #8]; ldr x8, [x8, #8]] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x1, #0x10]; ldr x9, [x0, #8]; ldr x8, [x8, #8]]
uint64_t fde_sub_0c1e74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400828ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C1E74ULL;
}

// FDE #1643 | PC: 0x0c1ee8..0x0c1f68 (128 B) | Symbol: sub_0c1ee8
// EN: AArch64 prologue [bti c; ldr x8, [x1, #0x10]; ldr x9, [x0, #8]; ldr x8, [x8, #8]] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x1, #0x10]; ldr x9, [x0, #8]; ldr x8, [x8, #8]]
uint64_t fde_sub_0c1ee8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400828ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C1EE8ULL;
}

// FDE #1644 | PC: 0x0c1f68..0x0c1fac (68 B) | Symbol: sub_0c1f68
// EN: AArch64 prologue [bti c; ldr x8, [x0, #8]; cbz x2, #0xc1f88; asr x9, x8, #8] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0, #8]; cbz x2, #0xc1f88; asr x9, x8, #8]
uint64_t fde_sub_0c1f68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400408ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C1F68ULL;
}

// FDE #1645 | PC: 0x0c1fac..0x0c2108 (348 B) | Symbol: sub_0c1fac
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0c1fac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x015CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C1FACULL;
}

// FDE #1646 | PC: 0x0c2108..0x0c21a8 (160 B) | Symbol: sub_0c2108
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c2108(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C2108ULL;
}

// FDE #1647 | PC: 0x0c21a8..0x0c24d8 (816 B) | Symbol: sub_0c21a8
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xa0; stp x29, x30, [sp, #0x60]; str x23, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xa0; stp x29, x30, [sp, #0x60]; str x23, [sp, #0x70]]
uint64_t fde_sub_0c21a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10283FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0330ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C21A8ULL;
}

// FDE #1648 | PC: 0x0c24d8..0x0c261c (324 B) | Symbol: sub_0c24d8
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0c24d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0144ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C24D8ULL;
}

// FDE #1649 | PC: 0x0c261c..0x0c26b0 (148 B) | Symbol: sub_0c261c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c261c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C261CULL;
}

// FDE #1650 | PC: 0x0c26b0..0x0c2818 (360 B) | Symbol: sub_0c26b0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0c26b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0168ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C26B0ULL;
}

// FDE #1651 | PC: 0x0c2818..0x0c2958 (320 B) | Symbol: __dynamic_cast
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x60]; stp x20, x19, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x60]; stp x20, x19, [sp, #0x70]]
uint64_t fde_sub_0c2818(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0140ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C2818ULL;
}

// FDE #1652 | PC: 0x0c2958..0x0c29fc (164 B) | Symbol: sub_0c2958
// EN: AArch64 prologue [bti c; ldr x9, [x1, #8]; mov w8, #1; strb w8, [x1, #0x4d]] | VI: Khởi đầu hàm AArch64 [bti c; ldr x9, [x1, #8]; mov w8, #1; strb w8, [x1, #0x4d]]
uint64_t fde_sub_0c2958(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400429ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C2958ULL;
}

// FDE #1653 | PC: 0x0c29fc..0x0c2a24 (40 B) | Symbol: sub_0c29fc
// EN: AArch64 prologue [bti c; ldr x8, [x1, #8]; cmp x8, x2; b.eq #0xc2a10] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x1, #8]; cmp x8, x2; b.eq #0xc2a10]
uint64_t fde_sub_0c29fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400428ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C29FCULL;
}

// FDE #1654 | PC: 0x0c2a24..0x0c2dd0 (940 B) | Symbol: sub_0c2a24
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_0c2a24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x03ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C2A24ULL;
}

// FDE #1655 | PC: 0x0c2dd0..0x0c2e0c (60 B) | Symbol: sub_0c2dd0
// EN: AArch64 prologue [bti c; ldr x8, [x0, #8]; asr x9, x8, #8; tbz w8, #0, #0xc2de8] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0, #8]; asr x9, x8, #8; tbz w8, #0, #0xc2de8]
uint64_t fde_sub_0c2dd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400408ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C2DD0ULL;
}

// FDE #1656 | PC: 0x0c2e0c..0x0c2e48 (60 B) | Symbol: sub_0c2e0c
// EN: AArch64 prologue [bti c; ldr x8, [x0, #8]; asr x9, x8, #8; tbz w8, #0, #0xc2e24] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0, #8]; asr x9, x8, #8; tbz w8, #0, #0xc2e24]
uint64_t fde_sub_0c2e0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400408ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C2E0CULL;
}

// FDE #1657 | PC: 0x0c2e48..0x0c2ff4 (428 B) | Symbol: sub_0c2e48
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0c2e48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C2E48ULL;
}

// FDE #1658 | PC: 0x0c2ff4..0x0c311c (296 B) | Symbol: sub_0c2ff4
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0c2ff4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0128ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C2FF4ULL;
}

// FDE #1659 | PC: 0x0c311c..0x0c3358 (572 B) | Symbol: sub_0c311c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_0c311c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x023CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C311CULL;
}

// FDE #1660 | PC: 0x0c3358..0x0c3494 (316 B) | Symbol: sub_0c3358
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0c3358(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x013CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C3358ULL;
}

// FDE #1661 | PC: 0x0c3494..0x0c358c (248 B) | Symbol: sub_0c3494
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0c3494(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C3494ULL;
}

// FDE #1662 | PC: 0x0c358c..0x0c3594 (8 B) | Symbol: _ZNSt20bad_array_new_lengthD2Ev
// EN: AArch64 prologue [bti c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ret]
uint64_t fde_sub_0c358c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C358CULL;
}

// FDE #1663 | PC: 0x0c3594..0x0c359c (8 B) | Symbol: _ZNSt9exceptionD0Ev
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0c3594(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140013E6ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C3594ULL;
}

// FDE #1664 | PC: 0x0c359c..0x0c35ac (16 B) | Symbol: _ZNKSt9exception4whatEv
// EN: AArch64 prologue [bti c; adrp x0, #0x47000; add x0, x0, #0xf32; ret] | VI: Khởi đầu hàm AArch64 [bti c; adrp x0, #0x47000; add x0, x0, #0xf32; ret]
uint64_t fde_sub_0c359c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90FFFC20ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C359CULL;
}

// FDE #1665 | PC: 0x0c35ac..0x0c35b4 (8 B) | Symbol: _ZNSt13bad_exceptionD0Ev
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0c35ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140013E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C35ACULL;
}

// FDE #1666 | PC: 0x0c35b4..0x0c35c4 (16 B) | Symbol: _ZNKSt13bad_exception4whatEv
// EN: AArch64 prologue [bti c; adrp x0, #0x49000; add x0, x0, #0xc96; ret] | VI: Khởi đầu hàm AArch64 [bti c; adrp x0, #0x49000; add x0, x0, #0xc96; ret]
uint64_t fde_sub_0c35b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0FFFC20ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C35B4ULL;
}

// FDE #1667 | PC: 0x0c35c4..0x0c35dc (24 B) | Symbol: _ZNSt9bad_allocC2Ev
// EN: AArch64 prologue [bti c; adrp x8, #0xd4000; ldr x8, [x8, #0x9c0]; add x8, x8, #0x10] | VI: Khởi đầu hàm AArch64 [bti c; adrp x8, #0xd4000; ldr x8, [x8, #0x9c0]; add x8, x8, #0x10]
uint64_t fde_sub_0c35c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000088ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C35C4ULL;
}

// FDE #1668 | PC: 0x0c35dc..0x0c35e4 (8 B) | Symbol: _ZNSt9bad_allocD0Ev
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0c35dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140013D4ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C35DCULL;
}

// FDE #1669 | PC: 0x0c35e4..0x0c35f4 (16 B) | Symbol: _ZNKSt9bad_alloc4whatEv
// EN: AArch64 prologue [bti c; adrp x0, #0x48000; add x0, x0, #0x110; ret] | VI: Khởi đầu hàm AArch64 [bti c; adrp x0, #0x48000; add x0, x0, #0x110; ret]
uint64_t fde_sub_0c35e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0FFFC20ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C35E4ULL;
}

// FDE #1670 | PC: 0x0c35f4..0x0c360c (24 B) | Symbol: _ZNSt20bad_array_new_lengthC2Ev
// EN: AArch64 prologue [bti c; adrp x8, #0xd4000; ldr x8, [x8, #0x9c8]; add x8, x8, #0x10] | VI: Khởi đầu hàm AArch64 [bti c; adrp x8, #0xd4000; ldr x8, [x8, #0x9c8]; add x8, x8, #0x10]
uint64_t fde_sub_0c35f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000088ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C35F4ULL;
}

// FDE #1671 | PC: 0x0c360c..0x0c3614 (8 B) | Symbol: _ZNSt20bad_array_new_lengthD0Ev
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0c360c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140013C8ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C360CULL;
}

// FDE #1672 | PC: 0x0c3614..0x0c3624 (16 B) | Symbol: _ZNKSt20bad_array_new_length4whatEv
// EN: AArch64 prologue [bti c; adrp x0, #0x48000; add x0, x0, #0xcbc; ret] | VI: Khởi đầu hàm AArch64 [bti c; adrp x0, #0x48000; add x0, x0, #0xcbc; ret]
uint64_t fde_sub_0c3614(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0FFFC20ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C3614ULL;
}

// FDE #1673 | PC: 0x0c3624..0x0c3680 (92 B) | Symbol: _ZNSt12domain_errorD2Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c3624(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C3624ULL;
}

// FDE #1674 | PC: 0x0c3680..0x0c36e4 (100 B) | Symbol: _ZNSt11logic_errorD0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c3680(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C3680ULL;
}

// FDE #1675 | PC: 0x0c36e4..0x0c36f0 (12 B) | Symbol: _ZNKSt11logic_error4whatEv
// EN: AArch64 prologue [bti c; ldr x0, [x0, #8]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldr x0, [x0, #8]; ret]
uint64_t fde_sub_0c36e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400400ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C36E4ULL;
}

// FDE #1676 | PC: 0x0c36f0..0x0c374c (92 B) | Symbol: _ZNSt11range_errorD1Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c36f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C36F0ULL;
}

// FDE #1677 | PC: 0x0c374c..0x0c37b0 (100 B) | Symbol: _ZNSt13runtime_errorD0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c374c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C374CULL;
}

// FDE #1678 | PC: 0x0c37b0..0x0c37bc (12 B) | Symbol: _ZNKSt13runtime_error4whatEv
// EN: AArch64 prologue [bti c; ldr x0, [x0, #8]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldr x0, [x0, #8]; ret]
uint64_t fde_sub_0c37b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400400ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C37B0ULL;
}

// FDE #1679 | PC: 0x0c37bc..0x0c3820 (100 B) | Symbol: _ZNSt12domain_errorD0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c37bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C37BCULL;
}

// FDE #1680 | PC: 0x0c3820..0x0c3884 (100 B) | Symbol: _ZNSt16invalid_argumentD0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c3820(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C3820ULL;
}

// FDE #1681 | PC: 0x0c3884..0x0c38e8 (100 B) | Symbol: _ZNSt12length_errorD0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c3884(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C3884ULL;
}

// FDE #1682 | PC: 0x0c38e8..0x0c394c (100 B) | Symbol: _ZNSt12out_of_rangeD0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c38e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C38E8ULL;
}

// FDE #1683 | PC: 0x0c394c..0x0c39b0 (100 B) | Symbol: _ZNSt11range_errorD0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c394c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C394CULL;
}

// FDE #1684 | PC: 0x0c39b0..0x0c3a14 (100 B) | Symbol: _ZNSt14overflow_errorD0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c39b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C39B0ULL;
}

// FDE #1685 | PC: 0x0c3a14..0x0c3a78 (100 B) | Symbol: _ZNSt15underflow_errorD0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c3a14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C3A14ULL;
}

// FDE #1686 | PC: 0x0c3a78..0x0c3a80 (8 B) | Symbol: _ZNSt9type_infoD2Ev
// EN: AArch64 prologue [bti c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ret]
uint64_t fde_sub_0c3a78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C3A78ULL;
}

// FDE #1687 | PC: 0x0c3a80..0x0c3a88 (8 B) | Symbol: _ZNSt9type_infoD0Ev
// EN: AArch64 prologue [bti c; b #0xc8530] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc8530]
uint64_t fde_sub_0c3a80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140012ABULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C3A80ULL;
}

// FDE #1688 | PC: 0x0c3a88..0x0c3aa0 (24 B) | Symbol: _ZNSt8bad_castC1Ev
// EN: AArch64 prologue [bti c; adrp x8, #0xd4000; ldr x8, [x8, #0x9d0]; add x8, x8, #0x10] | VI: Khởi đầu hàm AArch64 [bti c; adrp x8, #0xd4000; ldr x8, [x8, #0x9d0]; add x8, x8, #0x10]
uint64_t fde_sub_0c3a88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000088ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C3A88ULL;
}

// FDE #1689 | PC: 0x0c3aa0..0x0c3aa8 (8 B) | Symbol: _ZNSt8bad_castD2Ev
// EN: AArch64 prologue [bti c; b #0xc95a0] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc95a0]
uint64_t fde_sub_0c3aa0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140016BFULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C3AA0ULL;
}

// FDE #1690 | PC: 0x0c3aa8..0x0c3ad4 (44 B) | Symbol: _ZNSt8bad_castD0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c3aa8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C3AA8ULL;
}

// FDE #1691 | PC: 0x0c3ad4..0x0c3ae4 (16 B) | Symbol: _ZNKSt8bad_cast4whatEv
// EN: AArch64 prologue [bti c; adrp x0, #0x48000; add x0, x0, #0x962; ret] | VI: Khởi đầu hàm AArch64 [bti c; adrp x0, #0x48000; add x0, x0, #0x962; ret]
uint64_t fde_sub_0c3ad4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0FFFC20ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C3AD4ULL;
}

// FDE #1692 | PC: 0x0c3ae4..0x0c3afc (24 B) | Symbol: _ZNSt10bad_typeidC2Ev
// EN: AArch64 prologue [bti c; adrp x8, #0xd4000; ldr x8, [x8, #0x9d8]; add x8, x8, #0x10] | VI: Khởi đầu hàm AArch64 [bti c; adrp x8, #0xd4000; ldr x8, [x8, #0x9d8]; add x8, x8, #0x10]
uint64_t fde_sub_0c3ae4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000088ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C3AE4ULL;
}

// FDE #1693 | PC: 0x0c3afc..0x0c3b04 (8 B) | Symbol: _ZNSt10bad_typeidD2Ev
// EN: AArch64 prologue [bti c; b #0xc95a0] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc95a0]
uint64_t fde_sub_0c3afc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140016A8ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C3AFCULL;
}

// FDE #1694 | PC: 0x0c3b04..0x0c3b30 (44 B) | Symbol: _ZNSt10bad_typeidD0Ev
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c3b04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C3B04ULL;
}

// FDE #1695 | PC: 0x0c3b30..0x0c3b40 (16 B) | Symbol: _ZNKSt10bad_typeid4whatEv
// EN: AArch64 prologue [bti c; adrp x0, #0x48000; add x0, x0, #0x11f; ret] | VI: Khởi đầu hàm AArch64 [bti c; adrp x0, #0x48000; add x0, x0, #0x11f; ret]
uint64_t fde_sub_0c3b30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0FFFC20ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C3B30ULL;
}

// FDE #1696 | PC: 0x0c3b40..0x0c3d00 (448 B) | Symbol: __emutls_get_address
// EN: AArch64 prologue [paciasp; str x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; str x30, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]]
uint64_t fde_sub_0c3b40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81C0FFEULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C3B40ULL;
}

// FDE #1697 | PC: 0x0c3d00..0x0c3d38 (56 B) | Symbol: sub_0c3d00
// EN: AArch64 prologue [paciasp; stp x30, x19, [sp, #-0x10]!; adrp x8, #0xda000; ldrb w8, [x8, #0xc30]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x30, x19, [sp, #-0x10]!; adrp x8, #0xda000; ldrb w8, [x8, #0xc30]]
uint64_t fde_sub_0c3d00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF4FFEULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C3D00ULL;
}

// FDE #1698 | PC: 0x0c3d38..0x0c3d74 (60 B) | Symbol: sub_0c3d38
// EN: AArch64 prologue [paciasp; str x30, [sp, #-0x10]!; adrp x0, #0xda000; adrp x1, #0xc3000] | VI: Khởi đầu hàm AArch64 [paciasp; str x30, [sp, #-0x10]!; adrp x0, #0xda000; adrp x1, #0xc3000]
uint64_t fde_sub_0c3d38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81F0FFEULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C3D38ULL;
}

// FDE #1699 | PC: 0x0c3d74..0x0c3dfc (136 B) | Symbol: sub_0c3d74
// EN: AArch64 prologue [paciasp; stp x30, x21, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x30, x21, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; ldr x8, [x0]]
uint64_t fde_sub_0c3d74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE57FEULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C3D74ULL;
}

// FDE #1700 | PC: 0x0c3dfc..0x0c3ed4 (216 B) | Symbol: sub_0c3dfc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x28, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x28, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c3dfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C3DFCULL;
}

// FDE #1701 | PC: 0x0c3ed4..0x0c3ff8 (292 B) | Symbol: sub_0c3ed4
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x50]; stp x22, x21, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x50]; stp x22, x21, [sp, #0x60]]
uint64_t fde_sub_0c3ed4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0124ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C3ED4ULL;
}

// FDE #1702 | PC: 0x0c3ff8..0x0c4080 (136 B) | Symbol: sub_0c3ff8
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x28, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x28, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c3ff8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C3FF8ULL;
}

// FDE #1703 | PC: 0x0c4080..0x0c4164 (228 B) | Symbol: sub_0c4080
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x50]; stp x22, x21, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x50]; stp x22, x21, [sp, #0x60]]
uint64_t fde_sub_0c4080(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C4080ULL;
}

// FDE #1704 | PC: 0x0c4164..0x0c41c8 (100 B) | Symbol: sub_0c4164
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x28, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x28, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0c4164(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C4164ULL;
}

// FDE #1705 | PC: 0x0c41c8..0x0c41fc (52 B) | Symbol: sub_0c41c8
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x50]; add x29, sp, #0x50] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x50]; add x29, sp, #0x50]
uint64_t fde_sub_0c41c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C41C8ULL;
}

// FDE #1706 | PC: 0x0c41fc..0x0c4230 (52 B) | Symbol: sub_0c41fc
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x50]; add x29, sp, #0x50] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x60; stp x29, x30, [sp, #0x50]; add x29, sp, #0x50]
uint64_t fde_sub_0c41fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C41FCULL;
}

// FDE #1707 | PC: 0x0c4230..0x0c424c (28 B) | Symbol: sub_0c4230
// EN: AArch64 prologue [bti c; ldr x16, [x0, #8]; cbz x16, #0xc4248; mov x1, x0] | VI: Khởi đầu hàm AArch64 [bti c; ldr x16, [x0, #8]; cbz x16, #0xc4248; mov x1, x0]
uint64_t fde_sub_0c4230(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400410ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C4230ULL;
}

// FDE #1708 | PC: 0x0c424c..0x0c4278 (44 B) | Symbol: sub_0c424c
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10]
uint64_t fde_sub_0c424c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10083FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C424CULL;
}

// FDE #1709 | PC: 0x0c4278..0x0c4280 (8 B) | Symbol: sub_0c4278
// EN: AArch64 prologue [bti c; b #0xc43d4] | VI: Khởi đầu hàm AArch64 [bti c; b #0xc43d4]
uint64_t fde_sub_0c4278(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000056ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C4278ULL;
}

// FDE #1710 | PC: 0x0c4280..0x0c42b0 (48 B) | Symbol: sub_0c4280
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10]
uint64_t fde_sub_0c4280(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10083FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C4280ULL;
}

// FDE #1711 | PC: 0x0c42b0..0x0c42c0 (16 B) | Symbol: sub_0c42b0
// EN: AArch64 prologue [bti c; mov x2, x1; mov w1, #-1; b #0xc43d4] | VI: Khởi đầu hàm AArch64 [bti c; mov x2, x1; mov w1, #-1; b #0xc43d4]
uint64_t fde_sub_0c42b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103E2ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C42B0ULL;
}

// FDE #1712 | PC: 0x0c42c0..0x0c4368 (168 B) | Symbol: sub_0c42c0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x20, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c42c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C42C0ULL;
}

// FDE #1713 | PC: 0x0c4368..0x0c43d4 (108 B) | Symbol: sub_0c4368
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0c4368(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C4368ULL;
}

// FDE #1714 | PC: 0x0c43d4..0x0c44ac (216 B) | Symbol: sub_0c43d4
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x50]; str x21, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x80; stp x29, x30, [sp, #0x50]; str x21, [sp, #0x60]]
uint64_t fde_sub_0c43d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C43D4ULL;
}

// FDE #1715 | PC: 0x0c44ac..0x0c4514 (104 B) | Symbol: sub_0c44ac
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0c44ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C44ACULL;
}

// FDE #1716 | PC: 0x0c4514..0x0c457c (104 B) | Symbol: sub_0c4514
// EN: AArch64 prologue [paciasp; str d8, [sp, #-0x30]!; stp x29, x30, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; str d8, [sp, #-0x30]!; stp x29, x30, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0c4514(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFC1D0FE8ULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C4514ULL;
}

// FDE #1717 | PC: 0x0c457c..0x0c458c (16 B) | Symbol: sub_0c457c
// EN: AArch64 prologue [bti c; ldr x8, [x0]; ldr x16, [x8, #0x40]; br x16] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0]; ldr x16, [x8, #0x40]; br x16]
uint64_t fde_sub_0c457c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C457CULL;
}

// FDE #1718 | PC: 0x0c458c..0x0c45cc (64 B) | Symbol: sub_0c458c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c458c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C458CULL;
}

// FDE #1719 | PC: 0x0c45cc..0x0c45f4 (40 B) | Symbol: sub_0c45cc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0]]
uint64_t fde_sub_0c45cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C45CCULL;
}

// FDE #1720 | PC: 0x0c45f4..0x0c4624 (48 B) | Symbol: sub_0c45f4
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0]]
uint64_t fde_sub_0c45f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C45F4ULL;
}

// FDE #1721 | PC: 0x0c4624..0x0c464c (40 B) | Symbol: sub_0c4624
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0]]
uint64_t fde_sub_0c4624(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C4624ULL;
}

// FDE #1722 | PC: 0x0c464c..0x0c465c (16 B) | Symbol: sub_0c464c
// EN: AArch64 prologue [bti c; ldr x8, [x0]; ldr x16, [x8, #0x70]; br x16] | VI: Khởi đầu hàm AArch64 [bti c; ldr x8, [x0]; ldr x16, [x8, #0x70]; br x16]
uint64_t fde_sub_0c464c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C464CULL;
}

// FDE #1723 | PC: 0x0c465c..0x0c4684 (40 B) | Symbol: sub_0c465c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0]]
uint64_t fde_sub_0c465c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C465CULL;
}

// FDE #1724 | PC: 0x0c4684..0x0c46f4 (112 B) | Symbol: sub_0c4684
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0c4684(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C4684ULL;
}

// FDE #1725 | PC: 0x0c46f4..0x0c47f8 (260 B) | Symbol: sub_0c46f4
// EN: AArch64 prologue [paciasp; sub sp, sp, #0xd0; stp x29, x30, [sp, #0x70]; stp x28, x27, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0xd0; stp x29, x30, [sp, #0x70]; stp x28, x27, [sp, #0x80]]
uint64_t fde_sub_0c46f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10343FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C46F4ULL;
}

// FDE #1726 | PC: 0x0c47f8..0x0c4a18 (544 B) | Symbol: sub_0c47f8
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_0c47f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0220ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C47F8ULL;
}

// FDE #1727 | PC: 0x0c4a18..0x0c4aa8 (144 B) | Symbol: sub_0c4a18
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c4a18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C4A18ULL;
}

// FDE #1728 | PC: 0x0c4aa8..0x0c4ab0 (8 B) | Symbol: sub_0c4aa8
// EN: AArch64 prologue [bti c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ret]
uint64_t fde_sub_0c4aa8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C4AA8ULL;
}

// FDE #1729 | PC: 0x0c4ab0..0x0c4ab8 (8 B) | Symbol: sub_0c4ab0
// EN: AArch64 prologue [bti c; ret] | VI: Khởi đầu hàm AArch64 [bti c; ret]
uint64_t fde_sub_0c4ab0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C4AB0ULL;
}

// FDE #1730 | PC: 0x0c4ab8..0x0c4afc (68 B) | Symbol: sub_0c4ab8
// EN: AArch64 prologue [bti c; cmn w1, #3; b.ls #0xc4acc; mov w0, #1] | VI: Khởi đầu hàm AArch64 [bti c; cmn w1, #3; b.ls #0xc4acc; mov w0, #1]
uint64_t fde_sub_0c4ab8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x31000C3FULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C4AB8ULL;
}

// FDE #1731 | PC: 0x0c4afc..0x0c4b98 (156 B) | Symbol: sub_0c4afc
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c4afc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C4AFCULL;
}

// FDE #1732 | PC: 0x0c4b98..0x0c4c34 (156 B) | Symbol: sub_0c4b98
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c4b98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C4B98ULL;
}

// FDE #1733 | PC: 0x0c4c34..0x0c4c48 (20 B) | Symbol: sub_0c4c34
// EN: AArch64 prologue [bti c; and w8, w1, #0xffffffe0; cmp w8, #0x40; cset w0, eq] | VI: Khởi đầu hàm AArch64 [bti c; and w8, w1, #0xffffffe0; cmp w8, #0x40; cset w0, eq]
uint64_t fde_sub_0c4c34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x121B6828ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C4C34ULL;
}

// FDE #1734 | PC: 0x0c4c48..0x0c4c58 (16 B) | Symbol: sub_0c4c48
// EN: AArch64 prologue [bti c; add x8, x0, w1, sxtw #3; ldur d0, [x8, #-0xe0]; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x8, x0, w1, sxtw #3; ldur d0, [x8, #-0xe0]; ret]
uint64_t fde_sub_0c4c48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8B21CC08ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C4C48ULL;
}

// FDE #1735 | PC: 0x0c4c58..0x0c4c68 (16 B) | Symbol: sub_0c4c58
// EN: AArch64 prologue [bti c; add x8, x0, w1, sxtw #3; stur d0, [x8, #-0xe0]; ret] | VI: Khởi đầu hàm AArch64 [bti c; add x8, x0, w1, sxtw #3; stur d0, [x8, #-0xe0]; ret]
uint64_t fde_sub_0c4c58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8B21CC08ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C4C58ULL;
}

// FDE #1736 | PC: 0x0c4c68..0x0c4d38 (208 B) | Symbol: sub_0c4c68
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; str x28, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; str x28, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0c4c68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C4C68ULL;
}

// FDE #1737 | PC: 0x0c4d38..0x0c4d7c (68 B) | Symbol: sub_0c4d38
// EN: AArch64 prologue [bti c; ldrb w8, [x0, #0x268]; cbz w8, #0xc4d58; movi v0.2d, #0000000000000000] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w8, [x0, #0x268]; cbz w8, #0xc4d58; movi v0.2d, #0000000000000000]
uint64_t fde_sub_0c4d38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3949A008ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C4D38ULL;
}

// FDE #1738 | PC: 0x0c4d7c..0x0c4d88 (12 B) | Symbol: sub_0c4d7c
// EN: AArch64 prologue [bti c; add x0, x0, #0x10; b #0xc8304] | VI: Khởi đầu hàm AArch64 [bti c; add x0, x0, #0x10; b #0xc8304]
uint64_t fde_sub_0c4d7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91004000ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C4D7CULL;
}

// FDE #1739 | PC: 0x0c4d88..0x0c4d94 (12 B) | Symbol: sub_0c4d88
// EN: AArch64 prologue [bti c; ldrb w0, [x0, #0x269]; ret] | VI: Khởi đầu hàm AArch64 [bti c; ldrb w0, [x0, #0x269]; ret]
uint64_t fde_sub_0c4d88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3949A400ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C4D88ULL;
}

// FDE #1740 | PC: 0x0c4d94..0x0c4dc0 (44 B) | Symbol: sub_0c4d94
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0]]
uint64_t fde_sub_0c4d94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C4D94ULL;
}

// FDE #1741 | PC: 0x0c4dc0..0x0c4fb0 (496 B) | Symbol: sub_0c4dc0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x30]!; stp x28, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x30]!; stp x28, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_0c4dc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C4DC0ULL;
}

// FDE #1742 | PC: 0x0c4fb0..0x0c4fbc (12 B) | Symbol: sub_0c4fb0
// EN: AArch64 prologue [bti c; mov w0, w1; b #0xc82d8] | VI: Khởi đầu hàm AArch64 [bti c; mov w0, w1; b #0xc82d8]
uint64_t fde_sub_0c4fb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A0103E0ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C4FB0ULL;
}

// FDE #1743 | PC: 0x0c4fbc..0x0c50e0 (292 B) | Symbol: sub_0c4fbc
// EN: AArch64 prologue [bti c; ldr x9, [x0, #0x108]; mov x8, x0; ldr x10, [x9, #0x138]] | VI: Khởi đầu hàm AArch64 [bti c; ldr x9, [x0, #0x108]; mov x8, x0; ldr x10, [x9, #0x138]]
uint64_t fde_sub_0c4fbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9408409ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x0124ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C4FBCULL;
}

// FDE #1744 | PC: 0x0c50e0..0x0c53ac (716 B) | Symbol: sub_0c50e0
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_0c50e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x02CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C50E0ULL;
}

// FDE #1745 | PC: 0x0c53ac..0x0c6660 (4788 B) | Symbol: sub_0c53ac
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_0c53ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x12B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C53ACULL;
}

// FDE #1746 | PC: 0x0c6660..0x0c6744 (228 B) | Symbol: sub_0c6660
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c6660(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C6660ULL;
}

// FDE #1747 | PC: 0x0c6744..0x0c68ac (360 B) | Symbol: sub_0c6744
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c6744(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0168ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C6744ULL;
}

// FDE #1748 | PC: 0x0c68ac..0x0c6b9c (752 B) | Symbol: sub_0c68ac
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c68ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x02F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C68ACULL;
}

// FDE #1749 | PC: 0x0c6b9c..0x0c7518 (2428 B) | Symbol: sub_0c6b9c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; stp x28, x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; stp x28, x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c6b9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x097CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C6B9CULL;
}

// FDE #1750 | PC: 0x0c7518..0x0c77f8 (736 B) | Symbol: sub_0c7518
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x60]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]]
uint64_t fde_sub_0c7518(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x02E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C7518ULL;
}

// FDE #1751 | PC: 0x0c77f8..0x0c79c8 (464 B) | Symbol: sub_0c77f8
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x10]; stp x28, x27, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x10]; stp x28, x27, [sp, #0x20]]
uint64_t fde_sub_0c77f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C77F8ULL;
}

// FDE #1752 | PC: 0x0c79c8..0x0c7c30 (616 B) | Symbol: sub_0c79c8
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x10]; stp x28, x27, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x70; stp x29, x30, [sp, #0x10]; stp x28, x27, [sp, #0x20]]
uint64_t fde_sub_0c79c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD101C3FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x0268ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C79C8ULL;
}

// FDE #1753 | PC: 0x0c7c30..0x0c7e0c (476 B) | Symbol: sub_0c7c30
// EN: AArch64 prologue [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x30]; stp x28, x27, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [paciasp; sub sp, sp, #0x90; stp x29, x30, [sp, #0x30]; stp x28, x27, [sp, #0x40]]
uint64_t fde_sub_0c7c30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10243FFULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x01DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C7C30ULL;
}

// FDE #1754 | PC: 0x0c7e0c..0x0c8200 (1012 B) | Symbol: sub_0c7e0c
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x50]!; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_0c7e0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BB7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x03F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C7E0CULL;
}

// FDE #1755 | PC: 0x0c8200..0x0c82d8 (216 B) | Symbol: sub_0c8200
// EN: AArch64 prologue [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp] | VI: Khởi đầu hàm AArch64 [paciasp; stp x29, x30, [sp, #-0x20]!; str x19, [sp, #0x10]; mov x29, sp]
uint64_t fde_sub_0c8200(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE7BFDULL) << 32) | 0xD503233FULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C8200ULL;
}

// FDE #1756 | PC: 0x0c82d8..0x0c8304 (44 B) | Symbol: sub_0c82d8
// EN: AArch64 prologue [bti c; add w8, w0, #2; cmp w8, #0x61; b.hi #0xc82f8] | VI: Khởi đầu hàm AArch64 [bti c; add w8, w0, #2; cmp w8, #0x61; b.hi #0xc82f8]
uint64_t fde_sub_0c82d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x11000808ULL) << 32) | 0xD503245FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0C82D8ULL;
}

uint64_t DispatchAppLovinShard5(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x0b6fc4ULL: return fde_sub_0b6fc4(a0, a1, a2);
        case 0x0b7038ULL: return fde_sub_0b7038(a0, a1, a2);
        case 0x0b7040ULL: return fde_sub_0b7040(a0, a1, a2);
        case 0x0b7144ULL: return fde_sub_0b7144(a0, a1, a2);
        case 0x0b71a8ULL: return fde_sub_0b71a8(a0, a1, a2);
        case 0x0b71b0ULL: return fde_sub_0b71b0(a0, a1, a2);
        case 0x0b72d0ULL: return fde_sub_0b72d0(a0, a1, a2);
        case 0x0b7364ULL: return fde_sub_0b7364(a0, a1, a2);
        case 0x0b7378ULL: return fde_sub_0b7378(a0, a1, a2);
        case 0x0b7380ULL: return fde_sub_0b7380(a0, a1, a2);
        case 0x0b74d4ULL: return fde_sub_0b74d4(a0, a1, a2);
        case 0x0b74dcULL: return fde_sub_0b74dc(a0, a1, a2);
        case 0x0b766cULL: return fde_sub_0b766c(a0, a1, a2);
        case 0x0b7764ULL: return fde_sub_0b7764(a0, a1, a2);
        case 0x0b776cULL: return fde_sub_0b776c(a0, a1, a2);
        case 0x0b78dcULL: return fde_sub_0b78dc(a0, a1, a2);
        case 0x0b78e4ULL: return fde_sub_0b78e4(a0, a1, a2);
        case 0x0b79ccULL: return fde_sub_0b79cc(a0, a1, a2);
        case 0x0b79d4ULL: return fde_sub_0b79d4(a0, a1, a2);
        case 0x0b79dcULL: return fde_sub_0b79dc(a0, a1, a2);
        case 0x0b813cULL: return fde_sub_0b813c(a0, a1, a2);
        case 0x0b8144ULL: return fde_sub_0b8144(a0, a1, a2);
        case 0x0b8338ULL: return fde_sub_0b8338(a0, a1, a2);
        case 0x0b8340ULL: return fde_sub_0b8340(a0, a1, a2);
        case 0x0b86a8ULL: return fde_sub_0b86a8(a0, a1, a2);
        case 0x0b86b0ULL: return fde_sub_0b86b0(a0, a1, a2);
        case 0x0b8824ULL: return fde_sub_0b8824(a0, a1, a2);
        case 0x0b882cULL: return fde_sub_0b882c(a0, a1, a2);
        case 0x0b89e0ULL: return fde_sub_0b89e0(a0, a1, a2);
        case 0x0b89e8ULL: return fde_sub_0b89e8(a0, a1, a2);
        case 0x0b8afcULL: return fde_sub_0b8afc(a0, a1, a2);
        case 0x0b8b04ULL: return fde_sub_0b8b04(a0, a1, a2);
        case 0x0b8bd4ULL: return fde_sub_0b8bd4(a0, a1, a2);
        case 0x0b8d3cULL: return fde_sub_0b8d3c(a0, a1, a2);
        case 0x0b8d44ULL: return fde_sub_0b8d44(a0, a1, a2);
        case 0x0b8ed4ULL: return fde_sub_0b8ed4(a0, a1, a2);
        case 0x0b8edcULL: return fde_sub_0b8edc(a0, a1, a2);
        case 0x0b8f9cULL: return fde_sub_0b8f9c(a0, a1, a2);
        case 0x0b920cULL: return fde_sub_0b920c(a0, a1, a2);
        case 0x0b940cULL: return fde_sub_0b940c(a0, a1, a2);
        case 0x0b950cULL: return fde_sub_0b950c(a0, a1, a2);
        case 0x0b9520ULL: return fde_sub_0b9520(a0, a1, a2);
        case 0x0b9528ULL: return fde_sub_0b9528(a0, a1, a2);
        case 0x0baa84ULL: return fde_sub_0baa84(a0, a1, a2);
        case 0x0bab10ULL: return fde_sub_0bab10(a0, a1, a2);
        case 0x0bab18ULL: return fde_sub_0bab18(a0, a1, a2);
        case 0x0babecULL: return fde_sub_0babec(a0, a1, a2);
        case 0x0babf4ULL: return fde_sub_0babf4(a0, a1, a2);
        case 0x0bacccULL: return fde_sub_0baccc(a0, a1, a2);
        case 0x0bacd4ULL: return fde_sub_0bacd4(a0, a1, a2);
        case 0x0bad94ULL: return fde_sub_0bad94(a0, a1, a2);
        case 0x0bada8ULL: return fde_sub_0bada8(a0, a1, a2);
        case 0x0badb0ULL: return fde_sub_0badb0(a0, a1, a2);
        case 0x0baec4ULL: return fde_sub_0baec4(a0, a1, a2);
        case 0x0baeccULL: return fde_sub_0baecc(a0, a1, a2);
        case 0x0bb060ULL: return fde_sub_0bb060(a0, a1, a2);
        case 0x0bb068ULL: return fde_sub_0bb068(a0, a1, a2);
        case 0x0bb2a8ULL: return fde_sub_0bb2a8(a0, a1, a2);
        case 0x0bb2b0ULL: return fde_sub_0bb2b0(a0, a1, a2);
        case 0x0bb504ULL: return fde_sub_0bb504(a0, a1, a2);
        case 0x0bb50cULL: return fde_sub_0bb50c(a0, a1, a2);
        case 0x0bb620ULL: return fde_sub_0bb620(a0, a1, a2);
        case 0x0bb628ULL: return fde_sub_0bb628(a0, a1, a2);
        case 0x0bb798ULL: return fde_sub_0bb798(a0, a1, a2);
        case 0x0bb7a0ULL: return fde_sub_0bb7a0(a0, a1, a2);
        case 0x0bbae8ULL: return fde_sub_0bbae8(a0, a1, a2);
        case 0x0bbaf0ULL: return fde_sub_0bbaf0(a0, a1, a2);
        case 0x0bbc24ULL: return fde_sub_0bbc24(a0, a1, a2);
        case 0x0bbc2cULL: return fde_sub_0bbc2c(a0, a1, a2);
        case 0x0bbe68ULL: return fde_sub_0bbe68(a0, a1, a2);
        case 0x0bbe70ULL: return fde_sub_0bbe70(a0, a1, a2);
        case 0x0bbfacULL: return fde_sub_0bbfac(a0, a1, a2);
        case 0x0bbfb4ULL: return fde_sub_0bbfb4(a0, a1, a2);
        case 0x0bbfc0ULL: return fde_sub_0bbfc0(a0, a1, a2);
        case 0x0bbfc8ULL: return fde_sub_0bbfc8(a0, a1, a2);
        case 0x0bc098ULL: return fde_sub_0bc098(a0, a1, a2);
        case 0x0bc0a0ULL: return fde_sub_0bc0a0(a0, a1, a2);
        case 0x0bc1b8ULL: return fde_sub_0bc1b8(a0, a1, a2);
        case 0x0bc1c0ULL: return fde_sub_0bc1c0(a0, a1, a2);
        case 0x0bc4a0ULL: return fde_sub_0bc4a0(a0, a1, a2);
        case 0x0bc4c8ULL: return fde_sub_0bc4c8(a0, a1, a2);
        case 0x0bc4d0ULL: return fde_sub_0bc4d0(a0, a1, a2);
        case 0x0bc5d0ULL: return fde_sub_0bc5d0(a0, a1, a2);
        case 0x0bc5d8ULL: return fde_sub_0bc5d8(a0, a1, a2);
        case 0x0bc730ULL: return fde_sub_0bc730(a0, a1, a2);
        case 0x0bc738ULL: return fde_sub_0bc738(a0, a1, a2);
        case 0x0bc808ULL: return fde_sub_0bc808(a0, a1, a2);
        case 0x0bc810ULL: return fde_sub_0bc810(a0, a1, a2);
        case 0x0bc910ULL: return fde_sub_0bc910(a0, a1, a2);
        case 0x0bc918ULL: return fde_sub_0bc918(a0, a1, a2);
        case 0x0bcbe4ULL: return fde_sub_0bcbe4(a0, a1, a2);
        case 0x0bcc0cULL: return fde_sub_0bcc0c(a0, a1, a2);
        case 0x0bcc14ULL: return fde_sub_0bcc14(a0, a1, a2);
        case 0x0bcc7cULL: return fde_sub_0bcc7c(a0, a1, a2);
        case 0x0bcce4ULL: return fde_sub_0bcce4(a0, a1, a2);
        case 0x0bcd4cULL: return fde_sub_0bcd4c(a0, a1, a2);
        case 0x0bcd98ULL: return fde_sub_0bcd98(a0, a1, a2);
        case 0x0bcde4ULL: return fde_sub_0bcde4(a0, a1, a2);
        case 0x0bce30ULL: return fde_sub_0bce30(a0, a1, a2);
        case 0x0bce38ULL: return fde_sub_0bce38(a0, a1, a2);
        case 0x0bcf70ULL: return fde_sub_0bcf70(a0, a1, a2);
        case 0x0bcf78ULL: return fde_sub_0bcf78(a0, a1, a2);
        case 0x0bd024ULL: return fde_sub_0bd024(a0, a1, a2);
        case 0x0bd038ULL: return fde_sub_0bd038(a0, a1, a2);
        case 0x0bd040ULL: return fde_sub_0bd040(a0, a1, a2);
        case 0x0bd110ULL: return fde_sub_0bd110(a0, a1, a2);
        case 0x0bd124ULL: return fde_sub_0bd124(a0, a1, a2);
        case 0x0bd12cULL: return fde_sub_0bd12c(a0, a1, a2);
        case 0x0bd138ULL: return fde_sub_0bd138(a0, a1, a2);
        case 0x0bd140ULL: return fde_sub_0bd140(a0, a1, a2);
        case 0x0bd22cULL: return fde_sub_0bd22c(a0, a1, a2);
        case 0x0bd234ULL: return fde_sub_0bd234(a0, a1, a2);
        case 0x0bd240ULL: return fde_sub_0bd240(a0, a1, a2);
        case 0x0bd24cULL: return fde_sub_0bd24c(a0, a1, a2);
        case 0x0bd34cULL: return fde_sub_0bd34c(a0, a1, a2);
        case 0x0bd684ULL: return fde_sub_0bd684(a0, a1, a2);
        case 0x0bd68cULL: return fde_sub_0bd68c(a0, a1, a2);
        case 0x0bd7f8ULL: return fde_sub_0bd7f8(a0, a1, a2);
        case 0x0bd800ULL: return fde_sub_0bd800(a0, a1, a2);
        case 0x0bdd08ULL: return fde_sub_0bdd08(a0, a1, a2);
        case 0x0be0c8ULL: return fde_sub_0be0c8(a0, a1, a2);
        case 0x0be228ULL: return fde_sub_0be228(a0, a1, a2);
        case 0x0be340ULL: return fde_sub_0be340(a0, a1, a2);
        case 0x0be348ULL: return fde_sub_0be348(a0, a1, a2);
        case 0x0be42cULL: return fde_sub_0be42c(a0, a1, a2);
        case 0x0be434ULL: return fde_sub_0be434(a0, a1, a2);
        case 0x0be440ULL: return fde_sub_0be440(a0, a1, a2);
        case 0x0be44cULL: return fde_sub_0be44c(a0, a1, a2);
        case 0x0be4d4ULL: return fde_sub_0be4d4(a0, a1, a2);
        case 0x0be858ULL: return fde_sub_0be858(a0, a1, a2);
        case 0x0be860ULL: return fde_sub_0be860(a0, a1, a2);
        case 0x0be9ccULL: return fde_sub_0be9cc(a0, a1, a2);
        case 0x0be9d4ULL: return fde_sub_0be9d4(a0, a1, a2);
        case 0x0beaf0ULL: return fde_sub_0beaf0(a0, a1, a2);
        case 0x0beaf8ULL: return fde_sub_0beaf8(a0, a1, a2);
        case 0x0beb24ULL: return fde_sub_0beb24(a0, a1, a2);
        case 0x0beb50ULL: return fde_sub_0beb50(a0, a1, a2);
        case 0x0beb7cULL: return fde_sub_0beb7c(a0, a1, a2);
        case 0x0becf8ULL: return fde_sub_0becf8(a0, a1, a2);
        case 0x0bed0cULL: return fde_sub_0bed0c(a0, a1, a2);
        case 0x0bed14ULL: return fde_sub_0bed14(a0, a1, a2);
        case 0x0bee2cULL: return fde_sub_0bee2c(a0, a1, a2);
        case 0x0bee34ULL: return fde_sub_0bee34(a0, a1, a2);
        case 0x0bef84ULL: return fde_sub_0bef84(a0, a1, a2);
        case 0x0bef8cULL: return fde_sub_0bef8c(a0, a1, a2);
        case 0x0bef98ULL: return fde_sub_0bef98(a0, a1, a2);
        case 0x0befa4ULL: return fde_sub_0befa4(a0, a1, a2);
        case 0x0befb8ULL: return fde_sub_0befb8(a0, a1, a2);
        case 0x0bf144ULL: return fde_sub_0bf144(a0, a1, a2);
        case 0x0bf14cULL: return fde_sub_0bf14c(a0, a1, a2);
        case 0x0bf178ULL: return fde_sub_0bf178(a0, a1, a2);
        case 0x0bf334ULL: return fde_sub_0bf334(a0, a1, a2);
        case 0x0bf410ULL: return fde_sub_0bf410(a0, a1, a2);
        case 0x0bf418ULL: return fde_sub_0bf418(a0, a1, a2);
        case 0x0bf548ULL: return fde_sub_0bf548(a0, a1, a2);
        case 0x0bf550ULL: return fde_sub_0bf550(a0, a1, a2);
        case 0x0bf57cULL: return fde_sub_0bf57c(a0, a1, a2);
        case 0x0bf8b0ULL: return fde_sub_0bf8b0(a0, a1, a2);
        case 0x0bf9f8ULL: return fde_sub_0bf9f8(a0, a1, a2);
        case 0x0bfa00ULL: return fde_sub_0bfa00(a0, a1, a2);
        case 0x0bfa2cULL: return fde_sub_0bfa2c(a0, a1, a2);
        case 0x0bfcd0ULL: return fde_sub_0bfcd0(a0, a1, a2);
        case 0x0bfe3cULL: return fde_sub_0bfe3c(a0, a1, a2);
        case 0x0bfe44ULL: return fde_sub_0bfe44(a0, a1, a2);
        case 0x0bfeecULL: return fde_sub_0bfeec(a0, a1, a2);
        case 0x0bfef4ULL: return fde_sub_0bfef4(a0, a1, a2);
        case 0x0bff00ULL: return fde_sub_0bff00(a0, a1, a2);
        case 0x0bff0cULL: return fde_sub_0bff0c(a0, a1, a2);
        case 0x0bff30ULL: return fde_sub_0bff30(a0, a1, a2);
        case 0x0bff84ULL: return fde_sub_0bff84(a0, a1, a2);
        case 0x0bffa8ULL: return fde_sub_0bffa8(a0, a1, a2);
        case 0x0bffe4ULL: return fde_sub_0bffe4(a0, a1, a2);
        case 0x0bffecULL: return fde_sub_0bffec(a0, a1, a2);
        case 0x0c006cULL: return fde_sub_0c006c(a0, a1, a2);
        case 0x0c0088ULL: return fde_sub_0c0088(a0, a1, a2);
        case 0x0c00f4ULL: return fde_sub_0c00f4(a0, a1, a2);
        case 0x0c0118ULL: return fde_sub_0c0118(a0, a1, a2);
        case 0x0c0124ULL: return fde_sub_0c0124(a0, a1, a2);
        case 0x0c01c0ULL: return fde_sub_0c01c0(a0, a1, a2);
        case 0x0c02a8ULL: return fde_sub_0c02a8(a0, a1, a2);
        case 0x0c0304ULL: return fde_sub_0c0304(a0, a1, a2);
        case 0x0c0354ULL: return fde_sub_0c0354(a0, a1, a2);
        case 0x0c0440ULL: return fde_sub_0c0440(a0, a1, a2);
        case 0x0c0460ULL: return fde_sub_0c0460(a0, a1, a2);
        case 0x0c04dcULL: return fde_sub_0c04dc(a0, a1, a2);
        case 0x0c0600ULL: return fde_sub_0c0600(a0, a1, a2);
        case 0x0c0678ULL: return fde_sub_0c0678(a0, a1, a2);
        case 0x0c06a8ULL: return fde_sub_0c06a8(a0, a1, a2);
        case 0x0c06d0ULL: return fde_sub_0c06d0(a0, a1, a2);
        case 0x0c06f4ULL: return fde_sub_0c06f4(a0, a1, a2);
        case 0x0c0718ULL: return fde_sub_0c0718(a0, a1, a2);
        case 0x0c0874ULL: return fde_sub_0c0874(a0, a1, a2);
        case 0x0c0924ULL: return fde_sub_0c0924(a0, a1, a2);
        case 0x0c09c8ULL: return fde_sub_0c09c8(a0, a1, a2);
        case 0x0c09dcULL: return fde_sub_0c09dc(a0, a1, a2);
        case 0x0c0a20ULL: return fde_sub_0c0a20(a0, a1, a2);
        case 0x0c0a3cULL: return fde_sub_0c0a3c(a0, a1, a2);
        case 0x0c0a58ULL: return fde_sub_0c0a58(a0, a1, a2);
        case 0x0c0a6cULL: return fde_sub_0c0a6c(a0, a1, a2);
        case 0x0c0ab0ULL: return fde_sub_0c0ab0(a0, a1, a2);
        case 0x0c0ad0ULL: return fde_sub_0c0ad0(a0, a1, a2);
        case 0x0c0ae4ULL: return fde_sub_0c0ae4(a0, a1, a2);
        case 0x0c0cb4ULL: return fde_sub_0c0cb4(a0, a1, a2);
        case 0x0c129cULL: return fde_sub_0c129c(a0, a1, a2);
        case 0x0c12ccULL: return fde_sub_0c12cc(a0, a1, a2);
        case 0x0c163cULL: return fde_sub_0c163c(a0, a1, a2);
        case 0x0c17b4ULL: return fde_sub_0c17b4(a0, a1, a2);
        case 0x0c17ccULL: return fde_sub_0c17cc(a0, a1, a2);
        case 0x0c17e4ULL: return fde_sub_0c17e4(a0, a1, a2);
        case 0x0c1858ULL: return fde_sub_0c1858(a0, a1, a2);
        case 0x0c194cULL: return fde_sub_0c194c(a0, a1, a2);
        case 0x0c19b0ULL: return fde_sub_0c19b0(a0, a1, a2);
        case 0x0c19dcULL: return fde_sub_0c19dc(a0, a1, a2);
        case 0x0c1ae4ULL: return fde_sub_0c1ae4(a0, a1, a2);
        case 0x0c1b10ULL: return fde_sub_0c1b10(a0, a1, a2);
        case 0x0c1b18ULL: return fde_sub_0c1b18(a0, a1, a2);
        case 0x0c1b20ULL: return fde_sub_0c1b20(a0, a1, a2);
        case 0x0c1b28ULL: return fde_sub_0c1b28(a0, a1, a2);
        case 0x0c1b30ULL: return fde_sub_0c1b30(a0, a1, a2);
        case 0x0c1b5cULL: return fde_sub_0c1b5c(a0, a1, a2);
        case 0x0c1b88ULL: return fde_sub_0c1b88(a0, a1, a2);
        case 0x0c1bb4ULL: return fde_sub_0c1bb4(a0, a1, a2);
        case 0x0c1be0ULL: return fde_sub_0c1be0(a0, a1, a2);
        case 0x0c1c0cULL: return fde_sub_0c1c0c(a0, a1, a2);
        case 0x0c1c38ULL: return fde_sub_0c1c38(a0, a1, a2);
        case 0x0c1c64ULL: return fde_sub_0c1c64(a0, a1, a2);
        case 0x0c1c90ULL: return fde_sub_0c1c90(a0, a1, a2);
        case 0x0c1cbcULL: return fde_sub_0c1cbc(a0, a1, a2);
        case 0x0c1ce8ULL: return fde_sub_0c1ce8(a0, a1, a2);
        case 0x0c1d00ULL: return fde_sub_0c1d00(a0, a1, a2);
        case 0x0c1d0cULL: return fde_sub_0c1d0c(a0, a1, a2);
        case 0x0c1d18ULL: return fde_sub_0c1d18(a0, a1, a2);
        case 0x0c1d30ULL: return fde_sub_0c1d30(a0, a1, a2);
        case 0x0c1e18ULL: return fde_sub_0c1e18(a0, a1, a2);
        case 0x0c1e74ULL: return fde_sub_0c1e74(a0, a1, a2);
        case 0x0c1ee8ULL: return fde_sub_0c1ee8(a0, a1, a2);
        case 0x0c1f68ULL: return fde_sub_0c1f68(a0, a1, a2);
        case 0x0c1facULL: return fde_sub_0c1fac(a0, a1, a2);
        case 0x0c2108ULL: return fde_sub_0c2108(a0, a1, a2);
        case 0x0c21a8ULL: return fde_sub_0c21a8(a0, a1, a2);
        case 0x0c24d8ULL: return fde_sub_0c24d8(a0, a1, a2);
        case 0x0c261cULL: return fde_sub_0c261c(a0, a1, a2);
        case 0x0c26b0ULL: return fde_sub_0c26b0(a0, a1, a2);
        case 0x0c2818ULL: return fde_sub_0c2818(a0, a1, a2);
        case 0x0c2958ULL: return fde_sub_0c2958(a0, a1, a2);
        case 0x0c29fcULL: return fde_sub_0c29fc(a0, a1, a2);
        case 0x0c2a24ULL: return fde_sub_0c2a24(a0, a1, a2);
        case 0x0c2dd0ULL: return fde_sub_0c2dd0(a0, a1, a2);
        case 0x0c2e0cULL: return fde_sub_0c2e0c(a0, a1, a2);
        case 0x0c2e48ULL: return fde_sub_0c2e48(a0, a1, a2);
        case 0x0c2ff4ULL: return fde_sub_0c2ff4(a0, a1, a2);
        case 0x0c311cULL: return fde_sub_0c311c(a0, a1, a2);
        case 0x0c3358ULL: return fde_sub_0c3358(a0, a1, a2);
        case 0x0c3494ULL: return fde_sub_0c3494(a0, a1, a2);
        case 0x0c358cULL: return fde_sub_0c358c(a0, a1, a2);
        case 0x0c3594ULL: return fde_sub_0c3594(a0, a1, a2);
        case 0x0c359cULL: return fde_sub_0c359c(a0, a1, a2);
        case 0x0c35acULL: return fde_sub_0c35ac(a0, a1, a2);
        case 0x0c35b4ULL: return fde_sub_0c35b4(a0, a1, a2);
        case 0x0c35c4ULL: return fde_sub_0c35c4(a0, a1, a2);
        case 0x0c35dcULL: return fde_sub_0c35dc(a0, a1, a2);
        case 0x0c35e4ULL: return fde_sub_0c35e4(a0, a1, a2);
        case 0x0c35f4ULL: return fde_sub_0c35f4(a0, a1, a2);
        case 0x0c360cULL: return fde_sub_0c360c(a0, a1, a2);
        case 0x0c3614ULL: return fde_sub_0c3614(a0, a1, a2);
        case 0x0c3624ULL: return fde_sub_0c3624(a0, a1, a2);
        case 0x0c3680ULL: return fde_sub_0c3680(a0, a1, a2);
        case 0x0c36e4ULL: return fde_sub_0c36e4(a0, a1, a2);
        case 0x0c36f0ULL: return fde_sub_0c36f0(a0, a1, a2);
        case 0x0c374cULL: return fde_sub_0c374c(a0, a1, a2);
        case 0x0c37b0ULL: return fde_sub_0c37b0(a0, a1, a2);
        case 0x0c37bcULL: return fde_sub_0c37bc(a0, a1, a2);
        case 0x0c3820ULL: return fde_sub_0c3820(a0, a1, a2);
        case 0x0c3884ULL: return fde_sub_0c3884(a0, a1, a2);
        case 0x0c38e8ULL: return fde_sub_0c38e8(a0, a1, a2);
        case 0x0c394cULL: return fde_sub_0c394c(a0, a1, a2);
        case 0x0c39b0ULL: return fde_sub_0c39b0(a0, a1, a2);
        case 0x0c3a14ULL: return fde_sub_0c3a14(a0, a1, a2);
        case 0x0c3a78ULL: return fde_sub_0c3a78(a0, a1, a2);
        case 0x0c3a80ULL: return fde_sub_0c3a80(a0, a1, a2);
        case 0x0c3a88ULL: return fde_sub_0c3a88(a0, a1, a2);
        case 0x0c3aa0ULL: return fde_sub_0c3aa0(a0, a1, a2);
        case 0x0c3aa8ULL: return fde_sub_0c3aa8(a0, a1, a2);
        case 0x0c3ad4ULL: return fde_sub_0c3ad4(a0, a1, a2);
        case 0x0c3ae4ULL: return fde_sub_0c3ae4(a0, a1, a2);
        case 0x0c3afcULL: return fde_sub_0c3afc(a0, a1, a2);
        case 0x0c3b04ULL: return fde_sub_0c3b04(a0, a1, a2);
        case 0x0c3b30ULL: return fde_sub_0c3b30(a0, a1, a2);
        case 0x0c3b40ULL: return fde_sub_0c3b40(a0, a1, a2);
        case 0x0c3d00ULL: return fde_sub_0c3d00(a0, a1, a2);
        case 0x0c3d38ULL: return fde_sub_0c3d38(a0, a1, a2);
        case 0x0c3d74ULL: return fde_sub_0c3d74(a0, a1, a2);
        case 0x0c3dfcULL: return fde_sub_0c3dfc(a0, a1, a2);
        case 0x0c3ed4ULL: return fde_sub_0c3ed4(a0, a1, a2);
        case 0x0c3ff8ULL: return fde_sub_0c3ff8(a0, a1, a2);
        case 0x0c4080ULL: return fde_sub_0c4080(a0, a1, a2);
        case 0x0c4164ULL: return fde_sub_0c4164(a0, a1, a2);
        case 0x0c41c8ULL: return fde_sub_0c41c8(a0, a1, a2);
        case 0x0c41fcULL: return fde_sub_0c41fc(a0, a1, a2);
        case 0x0c4230ULL: return fde_sub_0c4230(a0, a1, a2);
        case 0x0c424cULL: return fde_sub_0c424c(a0, a1, a2);
        case 0x0c4278ULL: return fde_sub_0c4278(a0, a1, a2);
        case 0x0c4280ULL: return fde_sub_0c4280(a0, a1, a2);
        case 0x0c42b0ULL: return fde_sub_0c42b0(a0, a1, a2);
        case 0x0c42c0ULL: return fde_sub_0c42c0(a0, a1, a2);
        case 0x0c4368ULL: return fde_sub_0c4368(a0, a1, a2);
        case 0x0c43d4ULL: return fde_sub_0c43d4(a0, a1, a2);
        case 0x0c44acULL: return fde_sub_0c44ac(a0, a1, a2);
        case 0x0c4514ULL: return fde_sub_0c4514(a0, a1, a2);
        case 0x0c457cULL: return fde_sub_0c457c(a0, a1, a2);
        case 0x0c458cULL: return fde_sub_0c458c(a0, a1, a2);
        case 0x0c45ccULL: return fde_sub_0c45cc(a0, a1, a2);
        case 0x0c45f4ULL: return fde_sub_0c45f4(a0, a1, a2);
        case 0x0c4624ULL: return fde_sub_0c4624(a0, a1, a2);
        case 0x0c464cULL: return fde_sub_0c464c(a0, a1, a2);
        case 0x0c465cULL: return fde_sub_0c465c(a0, a1, a2);
        case 0x0c4684ULL: return fde_sub_0c4684(a0, a1, a2);
        case 0x0c46f4ULL: return fde_sub_0c46f4(a0, a1, a2);
        case 0x0c47f8ULL: return fde_sub_0c47f8(a0, a1, a2);
        case 0x0c4a18ULL: return fde_sub_0c4a18(a0, a1, a2);
        case 0x0c4aa8ULL: return fde_sub_0c4aa8(a0, a1, a2);
        case 0x0c4ab0ULL: return fde_sub_0c4ab0(a0, a1, a2);
        case 0x0c4ab8ULL: return fde_sub_0c4ab8(a0, a1, a2);
        case 0x0c4afcULL: return fde_sub_0c4afc(a0, a1, a2);
        case 0x0c4b98ULL: return fde_sub_0c4b98(a0, a1, a2);
        case 0x0c4c34ULL: return fde_sub_0c4c34(a0, a1, a2);
        case 0x0c4c48ULL: return fde_sub_0c4c48(a0, a1, a2);
        case 0x0c4c58ULL: return fde_sub_0c4c58(a0, a1, a2);
        case 0x0c4c68ULL: return fde_sub_0c4c68(a0, a1, a2);
        case 0x0c4d38ULL: return fde_sub_0c4d38(a0, a1, a2);
        case 0x0c4d7cULL: return fde_sub_0c4d7c(a0, a1, a2);
        case 0x0c4d88ULL: return fde_sub_0c4d88(a0, a1, a2);
        case 0x0c4d94ULL: return fde_sub_0c4d94(a0, a1, a2);
        case 0x0c4dc0ULL: return fde_sub_0c4dc0(a0, a1, a2);
        case 0x0c4fb0ULL: return fde_sub_0c4fb0(a0, a1, a2);
        case 0x0c4fbcULL: return fde_sub_0c4fbc(a0, a1, a2);
        case 0x0c50e0ULL: return fde_sub_0c50e0(a0, a1, a2);
        case 0x0c53acULL: return fde_sub_0c53ac(a0, a1, a2);
        case 0x0c6660ULL: return fde_sub_0c6660(a0, a1, a2);
        case 0x0c6744ULL: return fde_sub_0c6744(a0, a1, a2);
        case 0x0c68acULL: return fde_sub_0c68ac(a0, a1, a2);
        case 0x0c6b9cULL: return fde_sub_0c6b9c(a0, a1, a2);
        case 0x0c7518ULL: return fde_sub_0c7518(a0, a1, a2);
        case 0x0c77f8ULL: return fde_sub_0c77f8(a0, a1, a2);
        case 0x0c79c8ULL: return fde_sub_0c79c8(a0, a1, a2);
        case 0x0c7c30ULL: return fde_sub_0c7c30(a0, a1, a2);
        case 0x0c7e0cULL: return fde_sub_0c7e0c(a0, a1, a2);
        case 0x0c8200ULL: return fde_sub_0c8200(a0, a1, a2);
        case 0x0c82d8ULL: return fde_sub_0c82d8(a0, a1, a2);
        default: return 0ULL;
    }
}

uint64_t DispatchAppLovinShard1(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept;
uint64_t DispatchAppLovinShard2(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept;
uint64_t DispatchAppLovinShard3(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept;
uint64_t DispatchAppLovinShard4(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept;

uint64_t ExecuteAppLovinFdeByAddress(uint64_t fde_pc_begin, uint64_t arg0, uint64_t arg1, uint64_t arg2) noexcept {
    if (fde_pc_begin >= 0x060694ULL && fde_pc_begin <= 0x071358ULL) {
        return DispatchAppLovinShard1(fde_pc_begin, arg0, arg1, arg2);
    }
    if (fde_pc_begin >= 0x071398ULL && fde_pc_begin <= 0x090088ULL) {
        return DispatchAppLovinShard2(fde_pc_begin, arg0, arg1, arg2);
    }
    if (fde_pc_begin >= 0x0900dcULL && fde_pc_begin <= 0x0a00c8ULL) {
        return DispatchAppLovinShard3(fde_pc_begin, arg0, arg1, arg2);
    }
    if (fde_pc_begin >= 0x0a00d0ULL && fde_pc_begin <= 0x0b6f10ULL) {
        return DispatchAppLovinShard4(fde_pc_begin, arg0, arg1, arg2);
    }
    if (fde_pc_begin >= 0x0b6fc4ULL && fde_pc_begin <= 0x0c82d8ULL) {
        return DispatchAppLovinShard5(fde_pc_begin, arg0, arg1, arg2);
    }
    return 0ULL;
}

} // namespace applovin
