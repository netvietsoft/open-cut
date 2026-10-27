// ============================================================================
// File: fdk_aac_fde_shard_4.cpp
// Target 105 / 169: libfdk-aac.so (625,312 bytes)
// EN: Clean-room C++17 AArch64 FDE Shard 4/5 covering FDEs [885..1179]
//     (PC range 0x069f30 .. 0x06b760).
// VI: Phân mảnh FDE AArch64 C++17 4/5 bao phủ các FDE [885..1179]
//     (Dải địa chỉ PC 0x069f30 .. 0x06b760).
// ============================================================================
#include "fdk_aac_codec_core.h"

namespace opencut {
namespace fdk_aac {

// FDE #0885 | PC: 0x069f30..0x069f4c (28 B) | Symbol: sub_069f30
// EN: AArch64 prologue [ldp x20, x19, [sp, #0x50]; ldp x22, x21, [sp, #0x40]; ldp x24, x23, [sp, #0x30]; ldp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0x50]; ldp x22, x21, [sp, #0x40]; ldp x24, x23, [sp, #0x30]; ldp x26, x25, [sp, #0x20]]
uint64_t fde_sub_069f30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94457F6ULL) << 32) | 0xA9454FF4ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069F30ULL;
}

// FDE #0886 | PC: 0x069f4c..0x069f68 (28 B) | Symbol: sub_069f4c
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_069f4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9016FFCULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069F4CULL;
}

// FDE #0887 | PC: 0x069f68..0x069f7c (20 B) | Symbol: sub_069f68
// EN: AArch64 prologue [ldp x20, x19, [sp, #0x30]; ldp x22, x21, [sp, #0x20]; ldp x24, x23, [sp, #0x10]; ldr x25, [sp], #0x50] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0x30]; ldp x22, x21, [sp, #0x20]; ldp x24, x23, [sp, #0x10]; ldr x25, [sp], #0x50]
uint64_t fde_sub_069f68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94257F6ULL) << 32) | 0xA9434FF4ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069F68ULL;
}

// FDE #0888 | PC: 0x069f7c..0x069f8c (16 B) | Symbol: sub_069f7c
// EN: AArch64 prologue [ldp x20, x19, [sp, #0x20]; ldp x22, x21, [sp, #0x10]; ldr x23, [sp], #0x40; ret] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0x20]; ldp x22, x21, [sp, #0x10]; ldr x23, [sp], #0x40; ret]
uint64_t fde_sub_069f7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94157F6ULL) << 32) | 0xA9424FF4ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069F7CULL;
}

// FDE #0889 | PC: 0x069f8c..0x069fa8 (28 B) | Symbol: sub_069f8c
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp x28, x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp x28, x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]]
uint64_t fde_sub_069f8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9046FFCULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069F8CULL;
}

// FDE #0890 | PC: 0x069fa8..0x069fbc (20 B) | Symbol: sub_069fa8
// EN: AArch64 prologue [stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_069fa8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9025FF8ULL) << 32) | 0xA90167FAULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069FA8ULL;
}

// FDE #0891 | PC: 0x069fbc..0x069fd8 (28 B) | Symbol: sub_069fbc
// EN: AArch64 prologue [ldp x20, x19, [sp, #0x80]; ldp x22, x21, [sp, #0x70]; ldp x24, x23, [sp, #0x60]; ldp x26, x25, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0x80]; ldp x22, x21, [sp, #0x70]; ldp x24, x23, [sp, #0x60]; ldp x26, x25, [sp, #0x50]]
uint64_t fde_sub_069fbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94757F6ULL) << 32) | 0xA9484FF4ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069FBCULL;
}

// FDE #0892 | PC: 0x069fd8..0x069fe8 (16 B) | Symbol: sub_069fd8
// EN: AArch64 prologue [ldr x8, [x8, #0x28]; ldur x9, [x29, #-0x60]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x8, #0x28]; ldur x9, [x29, #-0x60]; cmp x8, x9; ret]
uint64_t fde_sub_069fd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF85A03A9ULL) << 32) | 0xF9401508ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069FD8ULL;
}

// FDE #0893 | PC: 0x069fe8..0x069ff8 (16 B) | Symbol: sub_069fe8
// EN: AArch64 prologue [ldp x20, x19, [sp, #0x20]; ldp x22, x21, [sp, #0x10]; ldp x24, x23, [sp], #0x40; ret] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0x20]; ldp x22, x21, [sp, #0x10]; ldp x24, x23, [sp], #0x40; ret]
uint64_t fde_sub_069fe8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94157F6ULL) << 32) | 0xA9424FF4ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069FE8ULL;
}

// FDE #0894 | PC: 0x069ff8..0x06a004 (12 B) | Symbol: sub_069ff8
// EN: AArch64 prologue [mov x0, x19; mov w1, wzr; b #0x322bc] | VI: Khởi đầu hàm AArch64 [mov x0, x19; mov w1, wzr; b #0x322bc]
uint64_t fde_sub_069ff8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E1ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069FF8ULL;
}

// FDE #0895 | PC: 0x06a004..0x06a020 (28 B) | Symbol: sub_06a004
// EN: AArch64 prologue [ldp x20, x19, [sp, #0x70]; ldp x22, x21, [sp, #0x60]; ldp x24, x23, [sp, #0x50]; ldp x26, x25, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0x70]; ldp x22, x21, [sp, #0x60]; ldp x24, x23, [sp, #0x50]; ldp x26, x25, [sp, #0x40]]
uint64_t fde_sub_06a004(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94657F6ULL) << 32) | 0xA9474FF4ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A004ULL;
}

// FDE #0896 | PC: 0x06a020..0x06a02c (12 B) | Symbol: sub_06a020
// EN: AArch64 prologue [ldur x9, [x29, #-0x60]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldur x9, [x29, #-0x60]; cmp x8, x9; ret]
uint64_t fde_sub_06a020(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xF85A03A9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A020ULL;
}

// FDE #0897 | PC: 0x06a02c..0x06a034 (8 B) | Symbol: sub_06a02c
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06a02c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A02CULL;
}

// FDE #0898 | PC: 0x06a034..0x06a03c (8 B) | Symbol: sub_06a034
// EN: AArch64 prologue [mov w1, wzr; b #0x322bc] | VI: Khởi đầu hàm AArch64 [mov w1, wzr; b #0x322bc]
uint64_t fde_sub_06a034(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF20A1ULL) << 32) | 0x2A1F03E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A034ULL;
}

// FDE #0899 | PC: 0x06a03c..0x06a044 (8 B) | Symbol: sub_06a03c
// EN: AArch64 prologue [mov x0, x24; b #0x1d1d8] | VI: Khởi đầu hàm AArch64 [mov x0, x24; b #0x1d1d8]
uint64_t fde_sub_06a03c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FECC66ULL) << 32) | 0xAA1803E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A03CULL;
}

// FDE #0900 | PC: 0x06a044..0x06a04c (8 B) | Symbol: sub_06a044
// EN: AArch64 prologue [mov x0, x21; b #0x1d1d8] | VI: Khởi đầu hàm AArch64 [mov x0, x21; b #0x1d1d8]
uint64_t fde_sub_06a044(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FECC64ULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A044ULL;
}

// FDE #0901 | PC: 0x06a04c..0x06a068 (28 B) | Symbol: sub_06a04c
// EN: AArch64 prologue [mov w2, w0; mov w0, #0xccd0; add x4, sp, #0xc; movk w0, #0xccc, lsl #16] | VI: Khởi đầu hàm AArch64 [mov w2, w0; mov w0, #0xccd0; add x4, sp, #0xc; movk w0, #0xccc, lsl #16]
uint64_t fde_sub_06a04c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52999A00ULL) << 32) | 0x2A0003E2ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A04CULL;
}

// FDE #0902 | PC: 0x06a068..0x06a074 (12 B) | Symbol: sub_06a068
// EN: AArch64 prologue [ldp x20, x19, [sp, #0x10]; ldr x21, [sp], #0x30; ret] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0x10]; ldr x21, [sp], #0x30; ret]
uint64_t fde_sub_06a068(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF84307F5ULL) << 32) | 0xA9414FF4ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A068ULL;
}

// FDE #0903 | PC: 0x06a074..0x06a07c (8 B) | Symbol: sub_06a074
// EN: AArch64 prologue [ldr x19, [sp], #0x20; ret] | VI: Khởi đầu hàm AArch64 [ldr x19, [sp], #0x20; ret]
uint64_t fde_sub_06a074(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF84207F3ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A074ULL;
}

// FDE #0904 | PC: 0x06a07c..0x06a084 (8 B) | Symbol: sub_06a07c
// EN: AArch64 prologue [mov w0, #-1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #-1; ret]
uint64_t fde_sub_06a07c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x12800000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A07CULL;
}

// FDE #0905 | PC: 0x06a084..0x06a0a0 (28 B) | Symbol: sub_06a084
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_06a084(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9026FFCULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A084ULL;
}

// FDE #0906 | PC: 0x06a0a0..0x06a0a8 (8 B) | Symbol: sub_06a0a0
// EN: AArch64 prologue [ldp x20, x19, [sp], #0x20; ret] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp], #0x20; ret]
uint64_t fde_sub_06a0a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xA8C24FF4ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A0A0ULL;
}

// FDE #0907 | PC: 0x06a0a8..0x06a0c4 (28 B) | Symbol: sub_06a0a8
// EN: AArch64 prologue [ldp x20, x19, [sp, #0xa0]; ldp x22, x21, [sp, #0x90]; ldp x24, x23, [sp, #0x80]; ldp x26, x25, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0xa0]; ldp x22, x21, [sp, #0x90]; ldp x24, x23, [sp, #0x80]; ldp x26, x25, [sp, #0x70]]
uint64_t fde_sub_06a0a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94957F6ULL) << 32) | 0xA94A4FF4ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A0A8ULL;
}

// FDE #0908 | PC: 0x06a0c4..0x06a0d8 (20 B) | Symbol: sub_06a0c4
// EN: AArch64 prologue [add x0, sp, #0x40; mov w2, #1; cmp w8, #0; cset w1, ne] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x40; mov w2, #1; cmp w8, #0; cset w1, ne]
uint64_t fde_sub_06a0c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800022ULL) << 32) | 0x910103E0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A0C4ULL;
}

// FDE #0909 | PC: 0x06a0d8..0x06a0f4 (28 B) | Symbol: sub_06a0d8
// EN: AArch64 prologue [ldp x20, x19, [sp, #0x60]; ldp x22, x21, [sp, #0x50]; ldp x24, x23, [sp, #0x40]; ldp x26, x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0x60]; ldp x22, x21, [sp, #0x50]; ldp x24, x23, [sp, #0x40]; ldp x26, x25, [sp, #0x30]]
uint64_t fde_sub_06a0d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94557F6ULL) << 32) | 0xA9464FF4ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A0D8ULL;
}

// FDE #0910 | PC: 0x06a0f4..0x06a160 (108 B) | Symbol: sub_06a0f4
// EN: AArch64 prologue [sub w11, w9, #1; add w12, w3, w9; sub w13, w12, #1; ldr w14, [x21, w11, sxtw #2]] | VI: Khởi đầu hàm AArch64 [sub w11, w9, #1; add w12, w3, w9; sub w13, w12, #1; ldr w14, [x21, w11, sxtw #2]]
uint64_t fde_sub_06a0f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x0B09006CULL) << 32) | 0x5100052BULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A0F4ULL;
}

// FDE #0911 | PC: 0x06a160..0x06a17c (28 B) | Symbol: sub_06a160
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]]
uint64_t fde_sub_06a160(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9036FFCULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A160ULL;
}

// FDE #0912 | PC: 0x06a17c..0x06a1a4 (40 B) | Symbol: sub_06a17c
// EN: AArch64 prologue [lsr x8, x24, #3; and x8, x8, #0x1ffffffc; mvn w10, w24; ldr w9, [x12, x8]] | VI: Khởi đầu hàm AArch64 [lsr x8, x24, #3; and x8, x8, #0x1ffffffc; mvn w10, w24; ldr w9, [x12, x8]]
uint64_t fde_sub_06a17c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x927E6908ULL) << 32) | 0xD343FF08ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A17CULL;
}

// FDE #0913 | PC: 0x06a1a4..0x06a1dc (56 B) | Symbol: sub_06a1a4
// EN: AArch64 prologue [ldr x11, [sp, #0x38]; cmp w9, #0; mov w12, #-7; ldrh w10, [x11], #2] | VI: Khởi đầu hàm AArch64 [ldr x11, [sp, #0x38]; cmp w9, #0; mov w12, #-7; ldrh w10, [x11], #2]
uint64_t fde_sub_06a1a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100013FULL) << 32) | 0xF9401FEBULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A1A4ULL;
}

// FDE #0914 | PC: 0x06a1dc..0x06a214 (56 B) | Symbol: sub_06a1dc
// EN: AArch64 prologue [ldr x11, [sp, #0x30]; cmp w9, #0; mov w12, #-7; ldrh w10, [x11], #0xfffffffffffffffe] | VI: Khởi đầu hàm AArch64 [ldr x11, [sp, #0x30]; cmp w9, #0; mov w12, #-7; ldrh w10, [x11], #0xfffffffffffffffe]
uint64_t fde_sub_06a1dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100013FULL) << 32) | 0xF9401BEBULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A1DCULL;
}

// FDE #0915 | PC: 0x06a214..0x06a21c (8 B) | Symbol: sub_06a214
// EN: AArch64 prologue [ldr x23, [sp], #0x40; ret] | VI: Khởi đầu hàm AArch64 [ldr x23, [sp], #0x40; ret]
uint64_t fde_sub_06a214(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF84407F7ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A214ULL;
}

// FDE #0916 | PC: 0x06a21c..0x06a250 (52 B) | Symbol: sub_06a21c
// EN: AArch64 prologue [ldrb w14, [x10]; sub x8, x8, #1; ldr w15, [x11, x14, lsl #2]; ldr w16, [x13, x14, lsl #2]] | VI: Khởi đầu hàm AArch64 [ldrb w14, [x10]; sub x8, x8, #1; ldr w15, [x11, x14, lsl #2]; ldr w16, [x13, x14, lsl #2]]
uint64_t fde_sub_06a21c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD1000508ULL) << 32) | 0x3940014EULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A21CULL;
}

// FDE #0917 | PC: 0x06a250..0x06a264 (20 B) | Symbol: sub_06a250
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_06a250(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A250ULL;
}

// FDE #0918 | PC: 0x06a264..0x06a27c (24 B) | Symbol: sub_06a264
// EN: AArch64 prologue [ldp x20, x19, [sp, #0x40]; ldp x22, x21, [sp, #0x30]; ldp x24, x23, [sp, #0x20]; ldp x26, x25, [sp, #0x10]] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0x40]; ldp x22, x21, [sp, #0x30]; ldp x24, x23, [sp, #0x20]; ldp x26, x25, [sp, #0x10]]
uint64_t fde_sub_06a264(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94357F6ULL) << 32) | 0xA9444FF4ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A264ULL;
}

// FDE #0919 | PC: 0x06a27c..0x06a284 (8 B) | Symbol: sub_06a27c
// EN: AArch64 prologue [ldr x21, [sp], #0x30; ret] | VI: Khởi đầu hàm AArch64 [ldr x21, [sp], #0x30; ret]
uint64_t fde_sub_06a27c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF84307F5ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A27CULL;
}

// FDE #0920 | PC: 0x06a284..0x06a28c (8 B) | Symbol: sub_06a284
// EN: AArch64 prologue [ldp x24, x23, [sp], #0x40; ret] | VI: Khởi đầu hàm AArch64 [ldp x24, x23, [sp], #0x40; ret]
uint64_t fde_sub_06a284(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xA8C45FF8ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A284ULL;
}

// FDE #0921 | PC: 0x06a28c..0x06a2a8 (28 B) | Symbol: sub_06a28c
// EN: AArch64 prologue [ldp x20, x19, [sp, #0x100]; ldp x22, x21, [sp, #0xf0]; ldp x24, x23, [sp, #0xe0]; ldp x26, x25, [sp, #0xd0]] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0x100]; ldp x22, x21, [sp, #0xf0]; ldp x24, x23, [sp, #0xe0]; ldp x26, x25, [sp, #0xd0]]
uint64_t fde_sub_06a28c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94F57F6ULL) << 32) | 0xA9504FF4ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A28CULL;
}

// FDE #0922 | PC: 0x06a2a8..0x06a2b8 (16 B) | Symbol: sub_06a2a8
// EN: AArch64 prologue [mov x0, x19; mov w1, w21; mov w2, w22; b #0x322bc] | VI: Khởi đầu hàm AArch64 [mov x0, x19; mov w1, w21; mov w2, w22; b #0x322bc]
uint64_t fde_sub_06a2a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1503E1ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A2A8ULL;
}

// FDE #0923 | PC: 0x06a2b8..0x06a2c4 (12 B) | Symbol: sub_06a2b8
// EN: AArch64 prologue [cmp w8, #0; cset w1, ne; b #0x322bc] | VI: Khởi đầu hàm AArch64 [cmp w8, #0; cset w1, ne; b #0x322bc]
uint64_t fde_sub_06a2b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1A9F07E1ULL) << 32) | 0x7100011FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A2B8ULL;
}

// FDE #0924 | PC: 0x06a2c4..0x06a31c (88 B) | Symbol: sub_06a2c4
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; ldr x8, [sp, #0xb0]; ldr w0, [x8, x25, lsl #2]; bl #0x1b048] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; ldr x8, [sp, #0xb0]; ldr w0, [x8, x25, lsl #2]; bl #0x1b048]
uint64_t fde_sub_06a2c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9405BE8ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A2C4ULL;
}

// FDE #0925 | PC: 0x06a31c..0x06a33c (32 B) | Symbol: sub_06a31c
// EN: AArch64 prologue [ldr w11, [sp]; asr w9, w9, #1; asr w12, w10, #1; sub w8, w9, w8] | VI: Khởi đầu hàm AArch64 [ldr w11, [sp]; asr w9, w9, #1; asr w12, w10, #1; sub w8, w9, w8]
uint64_t fde_sub_06a31c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x13017D29ULL) << 32) | 0xB94003EBULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A31CULL;
}

// FDE #0926 | PC: 0x06a33c..0x06a348 (12 B) | Symbol: sub_06a33c
// EN: AArch64 prologue [ldp x20, x19, [sp, #0x10]; ldp x22, x21, [sp], #0x30; ret] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0x10]; ldp x22, x21, [sp], #0x30; ret]
uint64_t fde_sub_06a33c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA8C357F6ULL) << 32) | 0xA9414FF4ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A33CULL;
}

// FDE #0927 | PC: 0x06a348..0x06a35c (20 B) | Symbol: sub_06a348
// EN: AArch64 prologue [mov x0, x20; mov x1, x22; mov x2, x23; mov w3, w21] | VI: Khởi đầu hàm AArch64 [mov x0, x20; mov x1, x22; mov x2, x23; mov w3, w21]
uint64_t fde_sub_06a348(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E1ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A348ULL;
}

// FDE #0928 | PC: 0x06a35c..0x06a370 (20 B) | Symbol: sub_06a35c
// EN: AArch64 prologue [ldp x20, x19, [sp, #0x30]; ldp x22, x21, [sp, #0x20]; ldp x24, x23, [sp, #0x10]; ldp x26, x25, [sp], #0x50] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0x30]; ldp x22, x21, [sp, #0x20]; ldp x24, x23, [sp, #0x10]; ldp x26, x25, [sp], #0x50]
uint64_t fde_sub_06a35c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94257F6ULL) << 32) | 0xA9434FF4ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A35CULL;
}

// FDE #0929 | PC: 0x06a370..0x06a378 (8 B) | Symbol: sub_06a370
// EN: AArch64 prologue [mov w0, w8; ret] | VI: Khởi đầu hàm AArch64 [mov w0, w8; ret]
uint64_t fde_sub_06a370(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A0803E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A370ULL;
}

// FDE #0930 | PC: 0x06a378..0x06a384 (12 B) | Symbol: sub_06a378
// EN: AArch64 prologue [ldr w8, [x19, #0xa78]; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [ldr w8, [x19, #0xa78]; mov w0, wzr; ret]
uint64_t fde_sub_06a378(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xB94A7A68ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A378ULL;
}

// FDE #0931 | PC: 0x06a384..0x06a38c (8 B) | Symbol: sub_06a384
// EN: AArch64 prologue [mov x0, x20; b #0x1d1b8] | VI: Khởi đầu hàm AArch64 [mov x0, x20; b #0x1d1b8]
uint64_t fde_sub_06a384(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FECB8CULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A384ULL;
}

// FDE #0932 | PC: 0x06a38c..0x06a3a4 (24 B) | Symbol: sub_06a38c
// EN: AArch64 prologue [mov w2, w21; mov w3, w28; mov w4, w27; mov w6, w24] | VI: Khởi đầu hàm AArch64 [mov w2, w21; mov w3, w28; mov w4, w27; mov w6, w24]
uint64_t fde_sub_06a38c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1C03E3ULL) << 32) | 0x2A1503E2ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A38CULL;
}

// FDE #0933 | PC: 0x06a3a4..0x06a3ac (8 B) | Symbol: sub_06a3a4
// EN: AArch64 prologue [mov x0, x19; b #0x1d1b8] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x1d1b8]
uint64_t fde_sub_06a3a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FECB84ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A3A4ULL;
}

// FDE #0934 | PC: 0x06a3ac..0x06a3b4 (8 B) | Symbol: sub_06a3ac
// EN: AArch64 prologue [ldp x22, x21, [sp], #0x30; ret] | VI: Khởi đầu hàm AArch64 [ldp x22, x21, [sp], #0x30; ret]
uint64_t fde_sub_06a3ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xA8C357F6ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A3ACULL;
}

// FDE #0935 | PC: 0x06a3b4..0x06a3d0 (28 B) | Symbol: sub_06a3b4
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0]; bl #0x1cba8] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0]; bl #0x1cba8]
uint64_t fde_sub_06a3b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A3B4ULL;
}

// FDE #0936 | PC: 0x06a3d0..0x06a3f0 (32 B) | Symbol: sub_06a3d0
// EN: AArch64 prologue [mov w2, #1; mov x0, x19; cmp w10, #1; cset w1, eq] | VI: Khởi đầu hàm AArch64 [mov w2, #1; mov x0, x19; cmp w10, #1; cset w1, eq]
uint64_t fde_sub_06a3d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x52800022ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A3D0ULL;
}

// FDE #0937 | PC: 0x06a3f0..0x06a3fc (12 B) | Symbol: sub_06a3f0
// EN: AArch64 prologue [mov w2, #1; mov x0, x19; b #0x62a80] | VI: Khởi đầu hàm AArch64 [mov w2, #1; mov x0, x19; b #0x62a80]
uint64_t fde_sub_06a3f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x52800022ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A3F0ULL;
}

// FDE #0938 | PC: 0x06a3fc..0x06a440 (68 B) | Symbol: sub_06a3fc
// EN: AArch64 prologue [add w10, w19, #3; ldr w12, [x21, w10, sxtw #2]; add w13, w9, w8, asr #1; add w11, w11, w23] | VI: Khởi đầu hàm AArch64 [add w10, w19, #3; ldr w12, [x21, w10, sxtw #2]; add w13, w9, w8, asr #1; add w11, w11, w23]
uint64_t fde_sub_06a3fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB86ADAACULL) << 32) | 0x11000E6AULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A3FCULL;
}

// FDE #0939 | PC: 0x06a440..0x06a44c (12 B) | Symbol: sub_06a440
// EN: AArch64 prologue [mov x19, x1; mov x20, x0; ret] | VI: Khởi đầu hàm AArch64 [mov x19, x1; mov x20, x0; ret]
uint64_t fde_sub_06a440(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F4ULL) << 32) | 0xAA0103F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A440ULL;
}

// FDE #0940 | PC: 0x06a44c..0x06a454 (8 B) | Symbol: sub_06a44c
// EN: AArch64 prologue [add sp, sp, #0x70; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0x70; ret]
uint64_t fde_sub_06a44c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x9101C3FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A44CULL;
}

// FDE #0941 | PC: 0x06a454..0x06a45c (8 B) | Symbol: sub_06a454
// EN: AArch64 prologue [mov x0, x21; b #0x1d1b8] | VI: Khởi đầu hàm AArch64 [mov x0, x21; b #0x1d1b8]
uint64_t fde_sub_06a454(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FECB58ULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A454ULL;
}

// FDE #0942 | PC: 0x06a45c..0x06a494 (56 B) | Symbol: sub_06a45c
// EN: AArch64 prologue [tst w8, #0x40; mov w9, #1; and w8, w8, #0x3f; cneg w9, w9, ne] | VI: Khởi đầu hàm AArch64 [tst w8, #0x40; mov w9, #1; and w8, w8, #0x3f; cneg w9, w9, ne]
uint64_t fde_sub_06a45c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800029ULL) << 32) | 0x721A011FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A45CULL;
}

// FDE #0943 | PC: 0x06a494..0x06a4e4 (80 B) | Symbol: sub_06a494
// EN: AArch64 prologue [ldr q2, [x0, x8, lsl #4]; fmov x11, d0; fmov x12, d0; sshll v3.2d, v2.2s, #0] | VI: Khởi đầu hàm AArch64 [ldr q2, [x0, x8, lsl #4]; fmov x11, d0; fmov x12, d0; sshll v3.2d, v2.2s, #0]
uint64_t fde_sub_06a494(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9E66000BULL) << 32) | 0x3CE87802ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A494ULL;
}

// FDE #0944 | PC: 0x06a4e4..0x06a4ec (8 B) | Symbol: sub_06a4e4
// EN: AArch64 prologue [mov x0, x20; b #0x322bc] | VI: Khởi đầu hàm AArch64 [mov x0, x20; b #0x322bc]
uint64_t fde_sub_06a4e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF1F75ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A4E4ULL;
}

// FDE #0945 | PC: 0x06a4ec..0x06a4f4 (8 B) | Symbol: sub_06a4ec
// EN: AArch64 prologue [mov x0, x19; b #0x62a80] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x62a80]
uint64_t fde_sub_06a4ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFE164ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A4ECULL;
}

// FDE #0946 | PC: 0x06a4f4..0x06a534 (64 B) | Symbol: sub_06a4f4
// EN: AArch64 prologue [ldr x10, [sp, #0x50]; sub w8, w19, #2; sub w9, w21, #1; add x25, x20, w8, sxtw #2] | VI: Khởi đầu hàm AArch64 [ldr x10, [sp, #0x50]; sub w8, w19, #2; sub w9, w21, #1; add x25, x20, w8, sxtw #2]
uint64_t fde_sub_06a4f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x51000A68ULL) << 32) | 0xF9402BEAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A4F4ULL;
}

// FDE #0947 | PC: 0x06a534..0x06a540 (12 B) | Symbol: sub_06a534
// EN: AArch64 prologue [lsr x8, x8, #0x1f; and w8, w8, #0xfffffffe; ret] | VI: Khởi đầu hàm AArch64 [lsr x8, x8, #0x1f; and w8, w8, #0xfffffffe; ret]
uint64_t fde_sub_06a534(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x121F7908ULL) << 32) | 0xD35FFD08ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A534ULL;
}

// FDE #0948 | PC: 0x06a540..0x06a564 (36 B) | Symbol: sub_06a540
// EN: AArch64 prologue [ldr w11, [sp]; asr w9, w9, #1; asr w12, w10, #1; sub w8, w9, w8] | VI: Khởi đầu hàm AArch64 [ldr w11, [sp]; asr w9, w9, #1; asr w12, w10, #1; sub w8, w9, w8]
uint64_t fde_sub_06a540(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x13017D29ULL) << 32) | 0xB94003EBULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A540ULL;
}

// FDE #0949 | PC: 0x06a564..0x06a588 (36 B) | Symbol: sub_06a564
// EN: AArch64 prologue [ldr w11, [sp]; asr w9, w9, #1; asr w12, w10, #1; sub w8, w9, w8] | VI: Khởi đầu hàm AArch64 [ldr w11, [sp]; asr w9, w9, #1; asr w12, w10, #1; sub w8, w9, w8]
uint64_t fde_sub_06a564(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x13017D29ULL) << 32) | 0xB94003EBULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A564ULL;
}

// FDE #0950 | PC: 0x06a588..0x06a5a4 (28 B) | Symbol: sub_06a588
// EN: AArch64 prologue [add x2, sp, #4; add x5, sp, #8; mov w1, #1; movk w6, #0x2147, lsl #16] | VI: Khởi đầu hàm AArch64 [add x2, sp, #4; add x5, sp, #8; mov w1, #1; movk w6, #0x2147, lsl #16]
uint64_t fde_sub_06a588(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910023E5ULL) << 32) | 0x910013E2ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A588ULL;
}

// FDE #0951 | PC: 0x06a5a4..0x06a5c0 (28 B) | Symbol: sub_06a5a4
// EN: AArch64 prologue [sub sp, sp, #0xc0; stp x28, x27, [sp, #0x60]; stp x26, x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; stp x28, x27, [sp, #0x60]; stp x26, x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]]
uint64_t fde_sub_06a5a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9066FFCULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A5A4ULL;
}

// FDE #0952 | PC: 0x06a5c0..0x06a5c8 (8 B) | Symbol: sub_06a5c0
// EN: AArch64 prologue [add sp, sp, #0xa0; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0xa0; ret]
uint64_t fde_sub_06a5c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910283FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A5C0ULL;
}

// FDE #0953 | PC: 0x06a5c8..0x06a5e4 (28 B) | Symbol: sub_06a5c8
// EN: AArch64 prologue [ldp x20, x19, [sp, #0xd0]; ldp x22, x21, [sp, #0xc0]; ldp x24, x23, [sp, #0xb0]; ldp x26, x25, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0xd0]; ldp x22, x21, [sp, #0xc0]; ldp x24, x23, [sp, #0xb0]; ldp x26, x25, [sp, #0xa0]]
uint64_t fde_sub_06a5c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94C57F6ULL) << 32) | 0xA94D4FF4ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A5C8ULL;
}

// FDE #0954 | PC: 0x06a5e4..0x06a5ec (8 B) | Symbol: sub_06a5e4
// EN: AArch64 prologue [mov w2, w24; b #0x2660c] | VI: Khởi đầu hàm AArch64 [mov w2, w24; b #0x2660c]
uint64_t fde_sub_06a5e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEF009ULL) << 32) | 0x2A1803E2ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A5E4ULL;
}

// FDE #0955 | PC: 0x06a5ec..0x06a5f4 (8 B) | Symbol: sub_06a5ec
// EN: AArch64 prologue [mov w4, w19; b #0x342a0] | VI: Khởi đầu hàm AArch64 [mov w4, w19; b #0x342a0]
uint64_t fde_sub_06a5ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF272CULL) << 32) | 0x2A1303E4ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A5ECULL;
}

// FDE #0956 | PC: 0x06a5f4..0x06a610 (28 B) | Symbol: sub_06a5f4
// EN: AArch64 prologue [ldp x20, x19, [sp, #0xc0]; ldp x22, x21, [sp, #0xb0]; ldp x24, x23, [sp, #0xa0]; ldp x26, x25, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0xc0]; ldp x22, x21, [sp, #0xb0]; ldp x24, x23, [sp, #0xa0]; ldp x26, x25, [sp, #0x90]]
uint64_t fde_sub_06a5f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94B57F6ULL) << 32) | 0xA94C4FF4ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A5F4ULL;
}

// FDE #0957 | PC: 0x06a610..0x06a618 (8 B) | Symbol: sub_06a610
// EN: AArch64 prologue [mov w1, #0x30; b #0x1a7e8] | VI: Khởi đầu hàm AArch64 [mov w1, #0x30; b #0x1a7e8]
uint64_t fde_sub_06a610(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC075ULL) << 32) | 0x52800601ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A610ULL;
}

// FDE #0958 | PC: 0x06a618..0x06a638 (32 B) | Symbol: sub_06a618
// EN: AArch64 prologue [ldurb w12, [x11, #-0x10]; sub x10, x10, #1; cmp w12, #0; csel w12, w8, w9, eq] | VI: Khởi đầu hàm AArch64 [ldurb w12, [x11, #-0x10]; sub x10, x10, #1; cmp w12, #0; csel w12, w8, w9, eq]
uint64_t fde_sub_06a618(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD100054AULL) << 32) | 0x385F016CULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A618ULL;
}

// FDE #0959 | PC: 0x06a638..0x06a640 (8 B) | Symbol: sub_06a638
// EN: AArch64 prologue [mov x0, x20; b #0x2678c] | VI: Khởi đầu hàm AArch64 [mov x0, x20; b #0x2678c]
uint64_t fde_sub_06a638(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEF054ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A638ULL;
}

// FDE #0960 | PC: 0x06a640..0x06a678 (56 B) | Symbol: sub_06a640
// EN: AArch64 prologue [ldr w11, [x19, #0x2160]; mov w10, #0xf; cmp w26, #0x1e; mov x9, xzr] | VI: Khởi đầu hàm AArch64 [ldr w11, [x19, #0x2160]; mov w10, #0xf; cmp w26, #0x1e; mov x9, xzr]
uint64_t fde_sub_06a640(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x528001EAULL) << 32) | 0xB961626BULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A640ULL;
}

// FDE #0961 | PC: 0x06a678..0x06a680 (8 B) | Symbol: sub_06a678
// EN: AArch64 prologue [add sp, sp, #0x20; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0x20; ret]
uint64_t fde_sub_06a678(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910083FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A678ULL;
}

// FDE #0962 | PC: 0x06a680..0x06a690 (16 B) | Symbol: sub_06a680
// EN: AArch64 prologue [add w9, w8, #8; cmp w9, #0; str w9, [sp, #0x108]; ret] | VI: Khởi đầu hàm AArch64 [add w9, w8, #8; cmp w9, #0; str w9, [sp, #0x108]; ret]
uint64_t fde_sub_06a680(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100013FULL) << 32) | 0x11002109ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A680ULL;
}

// FDE #0963 | PC: 0x06a690..0x06a6a8 (24 B) | Symbol: sub_06a690
// EN: AArch64 prologue [sub w8, w9, w8; lsl w9, w0, w10; asr w8, w0, w8; cmp w10, #0] | VI: Khởi đầu hàm AArch64 [sub w8, w9, w8; lsl w9, w0, w10; asr w8, w0, w8; cmp w10, #0]
uint64_t fde_sub_06a690(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1ACA2009ULL) << 32) | 0x4B080128ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A690ULL;
}

// FDE #0964 | PC: 0x06a6a8..0x06a6bc (20 B) | Symbol: sub_06a6a8
// EN: AArch64 prologue [add x0, x20, #0x28; add x2, sp, #4; add x5, sp, #8; mov w1, #1] | VI: Khởi đầu hàm AArch64 [add x0, x20, #0x28; add x2, sp, #4; add x5, sp, #8; mov w1, #1]
uint64_t fde_sub_06a6a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910013E2ULL) << 32) | 0x9100A280ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A6A8ULL;
}

// FDE #0965 | PC: 0x06a6bc..0x06a6cc (16 B) | Symbol: sub_06a6bc
// EN: AArch64 prologue [add x0, x20, #0x10; add x2, sp, #4; add x5, sp, #8; ret] | VI: Khởi đầu hàm AArch64 [add x0, x20, #0x10; add x2, sp, #4; add x5, sp, #8; ret]
uint64_t fde_sub_06a6bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910013E2ULL) << 32) | 0x91004280ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A6BCULL;
}

// FDE #0966 | PC: 0x06a6cc..0x06a6dc (16 B) | Symbol: sub_06a6cc
// EN: AArch64 prologue [ldr x8, [sp, #0xf0]; add x9, x8, #8; str x9, [sp, #0xf0]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [sp, #0xf0]; add x9, x8, #8; str x9, [sp, #0xf0]; ret]
uint64_t fde_sub_06a6cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91002109ULL) << 32) | 0xF9407BE8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A6CCULL;
}

// FDE #0967 | PC: 0x06a6dc..0x06a710 (52 B) | Symbol: sub_06a6dc
// EN: AArch64 prologue [asr w12, w8, #1; sub w12, w12, w9; add w10, w10, w23; ldr w11, [x21, w10, sxtw #2]] | VI: Khởi đầu hàm AArch64 [asr w12, w8, #1; sub w12, w12, w9; add w10, w10, w23; ldr w11, [x21, w10, sxtw #2]]
uint64_t fde_sub_06a6dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4B09018CULL) << 32) | 0x13017D0CULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A6DCULL;
}

// FDE #0968 | PC: 0x06a710..0x06a744 (52 B) | Symbol: sub_06a710
// EN: AArch64 prologue [add x8, x20, x21, lsl #1; ldrsh x9, [x8]; ldrsh x10, [x8, #2]; ldrsh x11, [x8, #4]] | VI: Khởi đầu hàm AArch64 [add x8, x20, x21, lsl #1; ldrsh x9, [x8]; ldrsh x10, [x8, #2]; ldrsh x11, [x8, #4]]
uint64_t fde_sub_06a710(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x79800109ULL) << 32) | 0x8B150688ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A710ULL;
}

// FDE #0969 | PC: 0x06a744..0x06a750 (12 B) | Symbol: sub_06a744
// EN: AArch64 prologue [mov w2, #1; mov x0, x19; ret] | VI: Khởi đầu hàm AArch64 [mov w2, #1; mov x0, x19; ret]
uint64_t fde_sub_06a744(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x52800022ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A744ULL;
}

// FDE #0970 | PC: 0x06a750..0x06a75c (12 B) | Symbol: sub_06a750
// EN: AArch64 prologue [ldr w2, [x25, x8, lsl #2]; ldr w3, [x21, x8, lsl #2]; b #0x43304] | VI: Khởi đầu hàm AArch64 [ldr w2, [x25, x8, lsl #2]; ldr w3, [x21, x8, lsl #2]; b #0x43304]
uint64_t fde_sub_06a750(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB8687AA3ULL) << 32) | 0xB8687B22ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A750ULL;
}

// FDE #0971 | PC: 0x06a75c..0x06a7a0 (68 B) | Symbol: sub_06a75c
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; add x25, x23, x22, lsl #3; ldr x0, [x25, #0x8f8]; mov w1, w24] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; add x25, x23, x22, lsl #3; ldr x0, [x25, #0x8f8]; mov w1, w24]
uint64_t fde_sub_06a75c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8B160EF9ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A75CULL;
}

// FDE #0972 | PC: 0x06a7a0..0x06a7ac (12 B) | Symbol: sub_06a7a0
// EN: AArch64 prologue [ldr x9, [sp, #8]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [sp, #8]; cmp x8, x9; ret]
uint64_t fde_sub_06a7a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xF94007E9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A7A0ULL;
}

// FDE #0973 | PC: 0x06a7ac..0x06a7dc (48 B) | Symbol: sub_06a7ac
// EN: AArch64 prologue [ldr w8, [sp, #0x40]; add x28, x28, #2; stur w8, [x21, #-4]; ldr w8, [sp, #0x44]] | VI: Khởi đầu hàm AArch64 [ldr w8, [sp, #0x40]; add x28, x28, #2; stur w8, [x21, #-4]; ldr w8, [sp, #0x44]]
uint64_t fde_sub_06a7ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91000B9CULL) << 32) | 0xB94043E8ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A7ACULL;
}

// FDE #0974 | PC: 0x06a7dc..0x06a7e8 (12 B) | Symbol: sub_06a7dc
// EN: AArch64 prologue [add w22, w22, #1; lsl w21, w21, #1; ret] | VI: Khởi đầu hàm AArch64 [add w22, w22, #1; lsl w21, w21, #1; ret]
uint64_t fde_sub_06a7dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x531F7AB5ULL) << 32) | 0x110006D6ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A7DCULL;
}

// FDE #0975 | PC: 0x06a7e8..0x06a7f0 (8 B) | Symbol: sub_06a7e8
// EN: AArch64 prologue [mov w2, #1; b #0x1be08] | VI: Khởi đầu hàm AArch64 [mov w2, #1; b #0x1be08]
uint64_t fde_sub_06a7e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC587ULL) << 32) | 0x52800022ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A7E8ULL;
}

// FDE #0976 | PC: 0x06a7f0..0x06a818 (40 B) | Symbol: sub_06a7f0
// EN: AArch64 prologue [sxtw x8, w0; sxtw x9, w9; mul x8, x8, x19; mul x9, x9, x19] | VI: Khởi đầu hàm AArch64 [sxtw x8, w0; sxtw x9, w9; mul x8, x8, x19; mul x9, x9, x19]
uint64_t fde_sub_06a7f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x93407D29ULL) << 32) | 0x93407C08ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A7F0ULL;
}

// FDE #0977 | PC: 0x06a818..0x06a834 (28 B) | Symbol: sub_06a818
// EN: AArch64 prologue [ldrsw x10, [x8]; sub w22, w22, #1; mul x10, x10, x9; lsr x10, x10, #0x1f] | VI: Khởi đầu hàm AArch64 [ldrsw x10, [x8]; sub w22, w22, #1; mul x10, x10, x9; lsr x10, x10, #0x1f]
uint64_t fde_sub_06a818(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x510006D6ULL) << 32) | 0xB980010AULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A818ULL;
}

// FDE #0978 | PC: 0x06a834..0x06a864 (48 B) | Symbol: sub_06a834
// EN: AArch64 prologue [add w11, w13, #1; ldr w15, [x21, w13, sxtw #2]; ldr w16, [x21, w11, sxtw #2]; mul x10, x10, x3] | VI: Khởi đầu hàm AArch64 [add w11, w13, #1; ldr w15, [x21, w13, sxtw #2]; ldr w16, [x21, w11, sxtw #2]; mul x10, x10, x3]
uint64_t fde_sub_06a834(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB86DDAAFULL) << 32) | 0x110005ABULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A834ULL;
}

// FDE #0979 | PC: 0x06a864..0x06a86c (8 B) | Symbol: sub_06a864
// EN: AArch64 prologue [mov x0, x22; b #0x1d1d8] | VI: Khởi đầu hàm AArch64 [mov x0, x22; b #0x1d1d8]
uint64_t fde_sub_06a864(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FECA5CULL) << 32) | 0xAA1603E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A864ULL;
}

// FDE #0980 | PC: 0x06a86c..0x06a888 (28 B) | Symbol: sub_06a86c
// EN: AArch64 prologue [sub sp, sp, #0x120; stp x28, x27, [sp, #0xc0]; stp x26, x25, [sp, #0xd0]; stp x24, x23, [sp, #0xe0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; stp x28, x27, [sp, #0xc0]; stp x26, x25, [sp, #0xd0]; stp x24, x23, [sp, #0xe0]]
uint64_t fde_sub_06a86c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90C6FFCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A86CULL;
}

// FDE #0981 | PC: 0x06a888..0x06a894 (12 B) | Symbol: sub_06a888
// EN: AArch64 prologue [mov x0, x20; mov x1, x19; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x20; mov x1, x19; ret]
uint64_t fde_sub_06a888(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E1ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A888ULL;
}

// FDE #0982 | PC: 0x06a894..0x06a8b0 (28 B) | Symbol: sub_06a894
// EN: AArch64 prologue [sub sp, sp, #0xf0; stp x28, x27, [sp, #0x90]; stp x26, x25, [sp, #0xa0]; stp x24, x23, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xf0; stp x28, x27, [sp, #0x90]; stp x26, x25, [sp, #0xa0]; stp x24, x23, [sp, #0xb0]]
uint64_t fde_sub_06a894(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9096FFCULL) << 32) | 0xD103C3FFULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A894ULL;
}

// FDE #0983 | PC: 0x06a8b0..0x06a8c0 (16 B) | Symbol: sub_06a8b0
// EN: AArch64 prologue [mrs x8, tpidr_el0; str x8, [sp, #8]; ldr x8, [x8, #0x28]; ret] | VI: Khởi đầu hàm AArch64 [mrs x8, tpidr_el0; str x8, [sp, #8]; ldr x8, [x8, #0x28]; ret]
uint64_t fde_sub_06a8b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90007E8ULL) << 32) | 0xD53BD048ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A8B0ULL;
}

// FDE #0984 | PC: 0x06a8c0..0x06a8dc (28 B) | Symbol: sub_06a8c0
// EN: AArch64 prologue [sub sp, sp, #0xe0; stp x28, x27, [sp, #0x80]; stp x26, x25, [sp, #0x90]; stp x24, x23, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xe0; stp x28, x27, [sp, #0x80]; stp x26, x25, [sp, #0x90]; stp x24, x23, [sp, #0xa0]]
uint64_t fde_sub_06a8c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9086FFCULL) << 32) | 0xD10383FFULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A8C0ULL;
}

// FDE #0985 | PC: 0x06a8dc..0x06a8ec (16 B) | Symbol: sub_06a8dc
// EN: AArch64 prologue [cmp w8, #1; mov w8, #1; cinc w5, w8, gt; b #0x1c5a8] | VI: Khởi đầu hàm AArch64 [cmp w8, #1; mov w8, #1; cinc w5, w8, gt; b #0x1c5a8]
uint64_t fde_sub_06a8dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800028ULL) << 32) | 0x7100051FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A8DCULL;
}

// FDE #0986 | PC: 0x06a8ec..0x06a918 (44 B) | Symbol: sub_06a8ec
// EN: AArch64 prologue [lsr x8, x24, #3; and x8, x8, #0x1ffffffc; mvn w10, w24; ldr w9, [x12, x8]] | VI: Khởi đầu hàm AArch64 [lsr x8, x24, #3; and x8, x8, #0x1ffffffc; mvn w10, w24; ldr w9, [x12, x8]]
uint64_t fde_sub_06a8ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x927E6908ULL) << 32) | 0xD343FF08ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A8ECULL;
}

// FDE #0987 | PC: 0x06a918..0x06a92c (20 B) | Symbol: sub_06a918
// EN: AArch64 prologue [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #2; mov w3, #2] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #2; mov w3, #2]
uint64_t fde_sub_06a918(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910783E1ULL) << 32) | 0x910243E0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A918ULL;
}

// FDE #0988 | PC: 0x06a92c..0x06a940 (20 B) | Symbol: sub_06a92c
// EN: AArch64 prologue [ldr x10, [x10]; ldr w1, [x9]; mov x0, x20; ldrb w2, [x10, x8]] | VI: Khởi đầu hàm AArch64 [ldr x10, [x10]; ldr w1, [x9]; mov x0, x20; ldrb w2, [x10, x8]]
uint64_t fde_sub_06a92c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9400121ULL) << 32) | 0xF940014AULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A92CULL;
}

// FDE #0989 | PC: 0x06a940..0x06a964 (36 B) | Symbol: sub_06a940
// EN: AArch64 prologue [ldp x8, x0, [x22, #0x20]; ldr w2, [x20, #0x1f8]; ldr w3, [x20, #0x208]; ldr w4, [x20, #0x1fc]] | VI: Khởi đầu hàm AArch64 [ldp x8, x0, [x22, #0x20]; ldr w2, [x20, #0x1f8]; ldr w3, [x20, #0x208]; ldr w4, [x20, #0x1fc]]
uint64_t fde_sub_06a940(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB941FA82ULL) << 32) | 0xA94202C8ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A940ULL;
}

// FDE #0990 | PC: 0x06a964..0x06a988 (36 B) | Symbol: sub_06a964
// EN: AArch64 prologue [ldp x8, x0, [x22, #0x20]; ldr w2, [x20, #0x1f8]; ldr w3, [x20, #0x208]; ldr w4, [x20, #0x1fc]] | VI: Khởi đầu hàm AArch64 [ldp x8, x0, [x22, #0x20]; ldr w2, [x20, #0x1f8]; ldr w3, [x20, #0x208]; ldr w4, [x20, #0x1fc]]
uint64_t fde_sub_06a964(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB941FA82ULL) << 32) | 0xA94202C8ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A964ULL;
}

// FDE #0991 | PC: 0x06a988..0x06a99c (20 B) | Symbol: sub_06a988
// EN: AArch64 prologue [mov w2, #2; mov x0, x19; sub w8, w8, #2; asr w1, w8, #1] | VI: Khởi đầu hàm AArch64 [mov w2, #2; mov x0, x19; sub w8, w8, #2; asr w1, w8, #1]
uint64_t fde_sub_06a988(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x52800042ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A988ULL;
}

// FDE #0992 | PC: 0x06a99c..0x06a9b0 (20 B) | Symbol: sub_06a99c
// EN: AArch64 prologue [ldur x8, [sp, #0x3c]; str x8, [x19, #0xb0]; ldr w8, [sp, #0x24]; str w8, [x19, #0xb8]] | VI: Khởi đầu hàm AArch64 [ldur x8, [sp, #0x3c]; str x8, [x19, #0xb0]; ldr w8, [sp, #0x24]; str w8, [x19, #0xb8]]
uint64_t fde_sub_06a99c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9005A68ULL) << 32) | 0xF843C3E8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A99CULL;
}

// FDE #0993 | PC: 0x06a9b0..0x06a9b8 (8 B) | Symbol: sub_06a9b0
// EN: AArch64 prologue [add sp, sp, #0x80; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0x80; ret]
uint64_t fde_sub_06a9b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910203FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A9B0ULL;
}

// FDE #0994 | PC: 0x06a9b8..0x06a9cc (20 B) | Symbol: sub_06a9b8
// EN: AArch64 prologue [add x0, sp, #0x84; add x1, sp, #0x80; ldr w2, [x25, x8, lsl #2]; ldr w3, [x21, x8, lsl #2]] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x84; add x1, sp, #0x80; ldr w2, [x25, x8, lsl #2]; ldr w3, [x21, x8, lsl #2]]
uint64_t fde_sub_06a9b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910203E1ULL) << 32) | 0x910213E0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A9B8ULL;
}

// FDE #0995 | PC: 0x06a9cc..0x06a9d4 (8 B) | Symbol: sub_06a9cc
// EN: AArch64 prologue [mov w1, #1; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w1, #1; b #0x1a748]
uint64_t fde_sub_06a9cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBF5EULL) << 32) | 0x52800021ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A9CCULL;
}

// FDE #0996 | PC: 0x06a9d4..0x06aa00 (44 B) | Symbol: sub_06a9d4
// EN: AArch64 prologue [ldr x8, [x21, #0x20]; ldr w9, [x21, #0x28]; stp xzr, xzr, [sp, #0x10]; str wzr, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x21, #0x20]; ldr w9, [x21, #0x28]; stp xzr, xzr, [sp, #0x10]; str wzr, [sp, #0x20]]
uint64_t fde_sub_06a9d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9402AA9ULL) << 32) | 0xF94012A8ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A9D4ULL;
}

// FDE #0997 | PC: 0x06aa00..0x06aa08 (8 B) | Symbol: sub_06aa00
// EN: AArch64 prologue [mov x19, x0; b #0x1a7e8] | VI: Khởi đầu hàm AArch64 [mov x19, x0; b #0x1a7e8]
uint64_t fde_sub_06aa00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBF79ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AA00ULL;
}

// FDE #0998 | PC: 0x06aa08..0x06aa10 (8 B) | Symbol: sub_06aa08
// EN: AArch64 prologue [mov w2, #-2; b #0x2660c] | VI: Khởi đầu hàm AArch64 [mov w2, #-2; b #0x2660c]
uint64_t fde_sub_06aa08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEEF00ULL) << 32) | 0x12800022ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AA08ULL;
}

// FDE #0999 | PC: 0x06aa10..0x06aa18 (8 B) | Symbol: sub_06aa10
// EN: AArch64 prologue [lsl w1, w8, #2; b #0x1a7e8] | VI: Khởi đầu hàm AArch64 [lsl w1, w8, #2; b #0x1a7e8]
uint64_t fde_sub_06aa10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBF75ULL) << 32) | 0x531E7501ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AA10ULL;
}

// FDE #1000 | PC: 0x06aa18..0x06aa24 (12 B) | Symbol: sub_06aa18
// EN: AArch64 prologue [mov x0, x23; mov x1, x22; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x23; mov x1, x22; ret]
uint64_t fde_sub_06aa18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E1ULL) << 32) | 0xAA1703E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AA18ULL;
}

// FDE #1001 | PC: 0x06aa24..0x06aa2c (8 B) | Symbol: sub_06aa24
// EN: AArch64 prologue [mov x0, x22; b #0x1d1b8] | VI: Khởi đầu hàm AArch64 [mov x0, x22; b #0x1d1b8]
uint64_t fde_sub_06aa24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC9E4ULL) << 32) | 0xAA1603E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AA24ULL;
}

// FDE #1002 | PC: 0x06aa2c..0x06aa34 (8 B) | Symbol: sub_06aa2c
// EN: AArch64 prologue [mov x0, x20; b #0x1df10] | VI: Khởi đầu hàm AArch64 [mov x0, x20; b #0x1df10]
uint64_t fde_sub_06aa2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FECD38ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AA2CULL;
}

// FDE #1003 | PC: 0x06aa34..0x06aa4c (24 B) | Symbol: sub_06aa34
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x51f30; cmp w20, w0; csel w20, w20, w0, lt] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x51f30; cmp w20, w0; csel w20, w20, w0, lt]
uint64_t fde_sub_06aa34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x97FF9D3EULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AA34ULL;
}

// FDE #1004 | PC: 0x06aa4c..0x06aa5c (16 B) | Symbol: sub_06aa4c
// EN: AArch64 prologue [sub w9, w21, w20; mov x8, xzr; sxtw x9, w9; ret] | VI: Khởi đầu hàm AArch64 [sub w9, w21, w20; mov x8, xzr; sxtw x9, w9; ret]
uint64_t fde_sub_06aa4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E8ULL) << 32) | 0x4B1402A9ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AA4CULL;
}

// FDE #1005 | PC: 0x06aa5c..0x06aa84 (40 B) | Symbol: sub_06aa5c
// EN: AArch64 prologue [add w8, w0, w21; sub w9, w19, w0; cmp w8, #0; csel w8, w9, w8, lt] | VI: Khởi đầu hàm AArch64 [add w8, w0, w21; sub w9, w19, w0; cmp w8, #0; csel w8, w9, w8, lt]
uint64_t fde_sub_06aa5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4B000269ULL) << 32) | 0x0B150008ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AA5CULL;
}

// FDE #1006 | PC: 0x06aa84..0x06aaac (40 B) | Symbol: sub_06aa84
// EN: AArch64 prologue [stp x1, x2, [sp, #0x88]; stp x3, x4, [sp, #0x98]; stp x5, x6, [sp, #0xa8]; str x7, [sp, #0xb8]] | VI: Khởi đầu hàm AArch64 [stp x1, x2, [sp, #0x88]; stp x3, x4, [sp, #0x98]; stp x5, x6, [sp, #0xa8]; str x7, [sp, #0xb8]]
uint64_t fde_sub_06aa84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90993E3ULL) << 32) | 0xA9088BE1ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AA84ULL;
}

// FDE #1007 | PC: 0x06aaac..0x06aac4 (24 B) | Symbol: sub_06aaac
// EN: AArch64 prologue [sub w8, w8, #1; strb w8, [x20]; ldr w8, [x19]; add w8, w8, #1] | VI: Khởi đầu hàm AArch64 [sub w8, w8, #1; strb w8, [x20]; ldr w8, [x19]; add w8, w8, #1]
uint64_t fde_sub_06aaac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39000288ULL) << 32) | 0x51000508ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AAACULL;
}

// FDE #1008 | PC: 0x06aac4..0x06aafc (56 B) | Symbol: sub_06aac4
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x1b3e8; mov w8, #-0x2000000; sub w8, w8, w0] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x1b3e8; mov w8, #-0x2000000; sub w8, w8, w0]
uint64_t fde_sub_06aac4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x97FEC248ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AAC4ULL;
}

// FDE #1009 | PC: 0x06aafc..0x06ab14 (24 B) | Symbol: sub_06aafc
// EN: AArch64 prologue [mov w8, #1; mov w9, #0x24; lsl w8, w8, w27; movk w9, #0x2000, lsl #16] | VI: Khởi đầu hàm AArch64 [mov w8, #1; mov w9, #0x24; lsl w8, w8, w27; movk w9, #0x2000, lsl #16]
uint64_t fde_sub_06aafc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800489ULL) << 32) | 0x52800028ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AAFCULL;
}

// FDE #1010 | PC: 0x06ab14..0x06ab30 (28 B) | Symbol: sub_06ab14
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]]
uint64_t fde_sub_06ab14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9056FFCULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AB14ULL;
}

// FDE #1011 | PC: 0x06ab30..0x06ab54 (36 B) | Symbol: sub_06ab30
// EN: AArch64 prologue [lsr x8, x24, #3; and x8, x8, #0x1ffffffc; mvn w10, w24; ldr w9, [x12, x8]] | VI: Khởi đầu hàm AArch64 [lsr x8, x24, #3; and x8, x8, #0x1ffffffc; mvn w10, w24; ldr w9, [x12, x8]]
uint64_t fde_sub_06ab30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x927E6908ULL) << 32) | 0xD343FF08ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AB30ULL;
}

// FDE #1012 | PC: 0x06ab54..0x06ab70 (28 B) | Symbol: sub_06ab54
// EN: AArch64 prologue [ldp x20, x19, [sp, #0xf0]; ldp x22, x21, [sp, #0xe0]; ldp x24, x23, [sp, #0xd0]; ldp x26, x25, [sp, #0xc0]] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0xf0]; ldp x22, x21, [sp, #0xe0]; ldp x24, x23, [sp, #0xd0]; ldp x26, x25, [sp, #0xc0]]
uint64_t fde_sub_06ab54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94E57F6ULL) << 32) | 0xA94F4FF4ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AB54ULL;
}

// FDE #1013 | PC: 0x06ab70..0x06ab7c (12 B) | Symbol: sub_06ab70
// EN: AArch64 prologue [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; ret] | VI: Khởi đầu hàm AArch64 [mrs x22, tpidr_el0; ldr x8, [x22, #0x28]; ret]
uint64_t fde_sub_06ab70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016C8ULL) << 32) | 0xD53BD056ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AB70ULL;
}

// FDE #1014 | PC: 0x06ab7c..0x06ab84 (8 B) | Symbol: sub_06ab7c
// EN: AArch64 prologue [ldp x1, x0, [sp, #0x40]; b #0x1af58] | VI: Khởi đầu hàm AArch64 [ldp x1, x0, [sp, #0x40]; b #0x1af58]
uint64_t fde_sub_06ab7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC0F6ULL) << 32) | 0xA94403E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AB7CULL;
}

// FDE #1015 | PC: 0x06ab84..0x06ab8c (8 B) | Symbol: sub_06ab84
// EN: AArch64 prologue [mov w2, w23; b #0x1a948] | VI: Khởi đầu hàm AArch64 [mov w2, w23; b #0x1a948]
uint64_t fde_sub_06ab84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBF70ULL) << 32) | 0x2A1703E2ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AB84ULL;
}

// FDE #1016 | PC: 0x06ab8c..0x06aba8 (28 B) | Symbol: sub_06ab8c
// EN: AArch64 prologue [ldp w8, w9, [x19, #0x34]; mov w3, w24; sxtw x8, w8; add x0, x20, x8, lsl #2] | VI: Khởi đầu hàm AArch64 [ldp w8, w9, [x19, #0x34]; mov w3, w24; sxtw x8, w8; add x0, x20, x8, lsl #2]
uint64_t fde_sub_06ab8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1803E3ULL) << 32) | 0x2946A668ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AB8CULL;
}

// FDE #1017 | PC: 0x06aba8..0x06abbc (20 B) | Symbol: sub_06aba8
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_06aba8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06ABA8ULL;
}

// FDE #1018 | PC: 0x06abbc..0x06abc4 (8 B) | Symbol: sub_06abbc
// EN: AArch64 prologue [add sp, sp, #0x120; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0x120; ret]
uint64_t fde_sub_06abbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910483FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06ABBCULL;
}

// FDE #1019 | PC: 0x06abc4..0x06abd0 (12 B) | Symbol: sub_06abc4
// EN: AArch64 prologue [mov w1, w26; mov w2, w27; b #0x2660c] | VI: Khởi đầu hàm AArch64 [mov w1, w26; mov w2, w27; b #0x2660c]
uint64_t fde_sub_06abc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1B03E2ULL) << 32) | 0x2A1A03E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06ABC4ULL;
}

// FDE #1020 | PC: 0x06abd0..0x06abf4 (36 B) | Symbol: sub_06abd0
// EN: AArch64 prologue [add x8, x20, x21, lsl #1; ldrsh x9, [x8]; ldrsh x8, [x8, #2]; mov x0, x19] | VI: Khởi đầu hàm AArch64 [add x8, x20, x21, lsl #1; ldrsh x9, [x8]; ldrsh x8, [x8, #2]; mov x0, x19]
uint64_t fde_sub_06abd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x79800109ULL) << 32) | 0x8B150688ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06ABD0ULL;
}

// FDE #1021 | PC: 0x06abf4..0x06ac04 (16 B) | Symbol: sub_06abf4
// EN: AArch64 prologue [mov x1, x22; mov x2, x22; mov w3, wzr; b #0x1a818] | VI: Khởi đầu hàm AArch64 [mov x1, x22; mov x2, x22; mov w3, wzr; b #0x1a818]
uint64_t fde_sub_06abf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E2ULL) << 32) | 0xAA1603E1ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06ABF4ULL;
}

// FDE #1022 | PC: 0x06ac04..0x06ac10 (12 B) | Symbol: sub_06ac04
// EN: AArch64 prologue [mov w2, #2; mov x0, x22; b #0x322bc] | VI: Khởi đầu hàm AArch64 [mov w2, #2; mov x0, x22; b #0x322bc]
uint64_t fde_sub_06ac04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E0ULL) << 32) | 0x52800042ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AC04ULL;
}

// FDE #1023 | PC: 0x06ac10..0x06ac1c (12 B) | Symbol: sub_06ac10
// EN: AArch64 prologue [mov x2, x19; mov w3, w23; b #0x539ac] | VI: Khởi đầu hàm AArch64 [mov x2, x19; mov w3, w23; b #0x539ac]
uint64_t fde_sub_06ac10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1703E3ULL) << 32) | 0xAA1303E2ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AC10ULL;
}

// FDE #1024 | PC: 0x06ac1c..0x06ac38 (28 B) | Symbol: sub_06ac1c
// EN: AArch64 prologue [mov w6, #7; mov w2, w3; mov x3, x9; mov w5, wzr] | VI: Khởi đầu hàm AArch64 [mov w6, #7; mov w2, w3; mov x3, x9; mov w5, wzr]
uint64_t fde_sub_06ac1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A0303E2ULL) << 32) | 0x528000E6ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AC1CULL;
}

// FDE #1025 | PC: 0x06ac38..0x06ac54 (28 B) | Symbol: sub_06ac38
// EN: AArch64 prologue [ldp x20, x19, [sp, #0x1b0]; ldp x22, x21, [sp, #0x1a0]; ldp x24, x23, [sp, #0x190]; ldp x26, x25, [sp, #0x180]] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0x1b0]; ldp x22, x21, [sp, #0x1a0]; ldp x24, x23, [sp, #0x190]; ldp x26, x25, [sp, #0x180]]
uint64_t fde_sub_06ac38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA95A57F6ULL) << 32) | 0xA95B4FF4ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AC38ULL;
}

// FDE #1026 | PC: 0x06ac54..0x06ac60 (12 B) | Symbol: sub_06ac54
// EN: AArch64 prologue [mov x7, x8; add sp, sp, #0x20; b #0x62958] | VI: Khởi đầu hàm AArch64 [mov x7, x8; add sp, sp, #0x20; b #0x62958]
uint64_t fde_sub_06ac54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910083FFULL) << 32) | 0xAA0803E7ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AC54ULL;
}

// FDE #1027 | PC: 0x06ac60..0x06ac68 (8 B) | Symbol: sub_06ac60
// EN: AArch64 prologue [mov x0, x25; b #0x322bc] | VI: Khởi đầu hàm AArch64 [mov x0, x25; b #0x322bc]
uint64_t fde_sub_06ac60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF1D96ULL) << 32) | 0xAA1903E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AC60ULL;
}

// FDE #1028 | PC: 0x06ac68..0x06ac74 (12 B) | Symbol: sub_06ac68
// EN: AArch64 prologue [mov x0, x19; mov w1, w21; b #0x322bc] | VI: Khởi đầu hàm AArch64 [mov x0, x19; mov w1, w21; b #0x322bc]
uint64_t fde_sub_06ac68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1503E1ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AC68ULL;
}

// FDE #1029 | PC: 0x06ac74..0x06ac90 (28 B) | Symbol: sub_06ac74
// EN: AArch64 prologue [ldp x20, x19, [sp, #0x190]; ldp x22, x21, [sp, #0x180]; ldp x24, x23, [sp, #0x170]; ldp x26, x25, [sp, #0x160]] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0x190]; ldp x22, x21, [sp, #0x180]; ldp x24, x23, [sp, #0x170]; ldp x26, x25, [sp, #0x160]]
uint64_t fde_sub_06ac74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA95857F6ULL) << 32) | 0xA9594FF4ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AC74ULL;
}

// FDE #1030 | PC: 0x06ac90..0x06aca4 (20 B) | Symbol: sub_06ac90
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x43304; ldr w8, [sp, #0x14]; ldr x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x43304; ldr w8, [sp, #0x14]; ldr x30, [sp], #0x10]
uint64_t fde_sub_06ac90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x97FF619CULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AC90ULL;
}

// FDE #1031 | PC: 0x06aca4..0x06acb4 (16 B) | Symbol: sub_06aca4
// EN: AArch64 prologue [mov w1, #1; mov w2, #4; mov x0, x21; b #0x1bdb8] | VI: Khởi đầu hàm AArch64 [mov w1, #1; mov w2, #4; mov x0, x21; b #0x1bdb8]
uint64_t fde_sub_06aca4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800082ULL) << 32) | 0x52800021ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06ACA4ULL;
}

// FDE #1032 | PC: 0x06acb4..0x06acd8 (36 B) | Symbol: sub_06acb4
// EN: AArch64 prologue [stp x2, x3, [sp, #0x80]; stp x4, x5, [sp, #0x90]; stp x6, x7, [sp, #0xa0]; stp q0, q1, [sp]] | VI: Khởi đầu hàm AArch64 [stp x2, x3, [sp, #0x80]; stp x4, x5, [sp, #0x90]; stp x6, x7, [sp, #0xa0]; stp q0, q1, [sp]]
uint64_t fde_sub_06acb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90917E4ULL) << 32) | 0xA9080FE2ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06ACB4ULL;
}

// FDE #1033 | PC: 0x06acd8..0x06ace4 (12 B) | Symbol: sub_06acd8
// EN: AArch64 prologue [mov x8, xzr; mov x9, x24; ret] | VI: Khởi đầu hàm AArch64 [mov x8, xzr; mov x9, x24; ret]
uint64_t fde_sub_06acd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1803E9ULL) << 32) | 0xAA1F03E8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06ACD8ULL;
}

// FDE #1034 | PC: 0x06ace4..0x06ad00 (28 B) | Symbol: sub_06ace4
// EN: AArch64 prologue [ldp x20, x19, [sp, #0x50]; ldp x22, x21, [sp, #0x40]; ldp x24, x23, [sp, #0x30]; ldp x26, x25, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0x50]; ldp x22, x21, [sp, #0x40]; ldp x24, x23, [sp, #0x30]; ldp x26, x25, [sp, #0x20]]
uint64_t fde_sub_06ace4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94457F6ULL) << 32) | 0xA9454FF4ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06ACE4ULL;
}

// FDE #1035 | PC: 0x06ad00..0x06ad24 (36 B) | Symbol: sub_06ad00
// EN: AArch64 prologue [ldr w11, [sp]; asr w9, w9, #1; asr w12, w10, #1; sub w8, w9, w8] | VI: Khởi đầu hàm AArch64 [ldr w11, [sp]; asr w9, w9, #1; asr w12, w10, #1; sub w8, w9, w8]
uint64_t fde_sub_06ad00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x13017D29ULL) << 32) | 0xB94003EBULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AD00ULL;
}

// FDE #1036 | PC: 0x06ad24..0x06ad48 (36 B) | Symbol: sub_06ad24
// EN: AArch64 prologue [ldr w11, [sp]; asr w9, w9, #1; asr w12, w10, #1; sub w8, w9, w8] | VI: Khởi đầu hàm AArch64 [ldr w11, [sp]; asr w9, w9, #1; asr w12, w10, #1; sub w8, w9, w8]
uint64_t fde_sub_06ad24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x13017D29ULL) << 32) | 0xB94003EBULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AD24ULL;
}

// FDE #1037 | PC: 0x06ad48..0x06ad54 (12 B) | Symbol: sub_06ad48
// EN: AArch64 prologue [mov w2, wzr; mov w4, w24; b #0x1b0d8] | VI: Khởi đầu hàm AArch64 [mov w2, wzr; mov w4, w24; b #0x1b0d8]
uint64_t fde_sub_06ad48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1803E4ULL) << 32) | 0x2A1F03E2ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AD48ULL;
}

// FDE #1038 | PC: 0x06ad54..0x06ad64 (16 B) | Symbol: sub_06ad54
// EN: AArch64 prologue [ldp x20, x19, [sp, #0x20]; ldp x22, x21, [sp, #0x10]; add sp, sp, #0x40; ret] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0x20]; ldp x22, x21, [sp, #0x10]; add sp, sp, #0x40; ret]
uint64_t fde_sub_06ad54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94157F6ULL) << 32) | 0xA9424FF4ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AD54ULL;
}

// FDE #1039 | PC: 0x06ad64..0x06ad70 (12 B) | Symbol: sub_06ad64
// EN: AArch64 prologue [sub w13, w14, w9; add w9, w14, w9; ret] | VI: Khởi đầu hàm AArch64 [sub w13, w14, w9; add w9, w14, w9; ret]
uint64_t fde_sub_06ad64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x0B0901C9ULL) << 32) | 0x4B0901CDULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AD64ULL;
}

// FDE #1040 | PC: 0x06ad70..0x06ad78 (8 B) | Symbol: sub_06ad70
// EN: AArch64 prologue [mov w1, #4; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w1, #4; b #0x1a748]
uint64_t fde_sub_06ad70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBE75ULL) << 32) | 0x52800081ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AD70ULL;
}

// FDE #1041 | PC: 0x06ad78..0x06ad94 (28 B) | Symbol: sub_06ad78
// EN: AArch64 prologue [ldp x20, x19, [sp, #0x90]; ldp x22, x21, [sp, #0x80]; ldp x24, x23, [sp, #0x70]; ldp x26, x25, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0x90]; ldp x22, x21, [sp, #0x80]; ldp x24, x23, [sp, #0x70]; ldp x26, x25, [sp, #0x60]]
uint64_t fde_sub_06ad78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94857F6ULL) << 32) | 0xA9494FF4ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AD78ULL;
}

// FDE #1042 | PC: 0x06ad94..0x06ad9c (8 B) | Symbol: sub_06ad94
// EN: AArch64 prologue [mov w1, #8; b #0x1cbb8] | VI: Khởi đầu hàm AArch64 [mov w1, #8; b #0x1cbb8]
uint64_t fde_sub_06ad94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC788ULL) << 32) | 0x52800101ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AD94ULL;
}

// FDE #1043 | PC: 0x06ad9c..0x06adac (16 B) | Symbol: sub_06ad9c
// EN: AArch64 prologue [add w21, w21, w0, uxtb; mov w2, #2; mov x0, x19; ret] | VI: Khởi đầu hàm AArch64 [add w21, w21, w0, uxtb; mov w2, #2; mov x0, x19; ret]
uint64_t fde_sub_06ad9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800042ULL) << 32) | 0x0B2002B5ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AD9CULL;
}

// FDE #1044 | PC: 0x06adac..0x06adc4 (24 B) | Symbol: sub_06adac
// EN: AArch64 prologue [ldr w19, [sp, #0x14]; ldr x26, [sp, #0x28]; mov x1, x20; mov w0, w19] | VI: Khởi đầu hàm AArch64 [ldr w19, [sp, #0x14]; ldr x26, [sp, #0x28]; mov x1, x20; mov w0, w19]
uint64_t fde_sub_06adac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017FAULL) << 32) | 0xB94017F3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06ADACULL;
}

// FDE #1045 | PC: 0x06adc4..0x06add8 (20 B) | Symbol: sub_06adc4
// EN: AArch64 prologue [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #2; mov w3, wzr] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #2; mov w3, wzr]
uint64_t fde_sub_06adc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910783E1ULL) << 32) | 0x910243E0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06ADC4ULL;
}

// FDE #1046 | PC: 0x06add8..0x06adec (20 B) | Symbol: sub_06add8
// EN: AArch64 prologue [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #1; mov w3, #1] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #1; mov w3, #1]
uint64_t fde_sub_06add8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910783E1ULL) << 32) | 0x910243E0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06ADD8ULL;
}

// FDE #1047 | PC: 0x06adec..0x06ae00 (20 B) | Symbol: sub_06adec
// EN: AArch64 prologue [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #1; mov w3, #3] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #1; mov w3, #3]
uint64_t fde_sub_06adec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910783E1ULL) << 32) | 0x910243E0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06ADECULL;
}

// FDE #1048 | PC: 0x06ae00..0x06ae18 (24 B) | Symbol: sub_06ae00
// EN: AArch64 prologue [ldp x20, x19, [sp, #0x40]; ldp x22, x21, [sp, #0x30]; ldp x24, x23, [sp, #0x20]; ldp x26, x25, [sp, #0x10]] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0x40]; ldp x22, x21, [sp, #0x30]; ldp x24, x23, [sp, #0x20]; ldp x26, x25, [sp, #0x10]]
uint64_t fde_sub_06ae00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94357F6ULL) << 32) | 0xA9444FF4ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AE00ULL;
}

// FDE #1049 | PC: 0x06ae18..0x06ae20 (8 B) | Symbol: sub_06ae18
// EN: AArch64 prologue [mov x0, x26; b #0x1d1d8] | VI: Khởi đầu hàm AArch64 [mov x0, x26; b #0x1d1d8]
uint64_t fde_sub_06ae18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC8EFULL) << 32) | 0xAA1A03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AE18ULL;
}

// FDE #1050 | PC: 0x06ae20..0x06ae28 (8 B) | Symbol: sub_06ae20
// EN: AArch64 prologue [str w8, [x1]; ret] | VI: Khởi đầu hàm AArch64 [str w8, [x1]; ret]
uint64_t fde_sub_06ae20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9000028ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AE20ULL;
}

// FDE #1051 | PC: 0x06ae28..0x06ae40 (24 B) | Symbol: sub_06ae28
// EN: AArch64 prologue [str w9, [x0, #0xc]; sub w9, w11, #1; str w8, [x0]; and w8, w9, w10] | VI: Khởi đầu hàm AArch64 [str w9, [x0, #0xc]; sub w9, w11, #1; str w8, [x0]; and w8, w9, w10]
uint64_t fde_sub_06ae28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x51000569ULL) << 32) | 0xB9000C09ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AE28ULL;
}

// FDE #1052 | PC: 0x06ae40..0x06ae60 (32 B) | Symbol: sub_06ae40
// EN: AArch64 prologue [adrp x25, #0x9a000; ldr x25, [x25, #0x8f0]; mov x23, xzr; sxtw x24, w1] | VI: Khởi đầu hàm AArch64 [adrp x25, #0x9a000; ldr x25, [x25, #0x8f0]; mov x23, xzr; sxtw x24, w1]
uint64_t fde_sub_06ae40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9447B39ULL) << 32) | 0x90000199ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AE40ULL;
}

// FDE #1053 | PC: 0x06ae60..0x06ae80 (32 B) | Symbol: sub_06ae60
// EN: AArch64 prologue [ldr x23, [x23, #0x8e0]; mov x21, xzr; sxtw x22, w1; mov w26, #6] | VI: Khởi đầu hàm AArch64 [ldr x23, [x23, #0x8e0]; mov x21, xzr; sxtw x22, w1; mov w26, #6]
uint64_t fde_sub_06ae60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03F5ULL) << 32) | 0xF94472F7ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AE60ULL;
}

// FDE #1054 | PC: 0x06ae80..0x06aeb0 (48 B) | Symbol: sub_06ae80
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; ldr w8, [x24, x21, lsl #2]; add x9, x22, x21, lsl #2; add x0, x22, x20] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; ldr w8, [x24, x21, lsl #2]; add x9, x22, x21, lsl #2; add x0, x22, x20]
uint64_t fde_sub_06ae80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB8757B08ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AE80ULL;
}

// FDE #1055 | PC: 0x06aeb0..0x06aed0 (32 B) | Symbol: sub_06aeb0
// EN: AArch64 prologue [asr w14, w14, #1; str w15, [x20, x9, lsl #2]; str w12, [x23, w10, sxtw #2]; str w13, [x20, w10, sxtw #2]] | VI: Khởi đầu hàm AArch64 [asr w14, w14, #1; str w15, [x20, x9, lsl #2]; str w12, [x23, w10, sxtw #2]; str w13, [x20, w10, sxtw #2]]
uint64_t fde_sub_06aeb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB8297A8FULL) << 32) | 0x13017DCEULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AEB0ULL;
}

// FDE #1056 | PC: 0x06aed0..0x06aedc (12 B) | Symbol: sub_06aed0
// EN: AArch64 prologue [mrs x23, tpidr_el0; ldr x8, [x23, #0x28]; ret] | VI: Khởi đầu hàm AArch64 [mrs x23, tpidr_el0; ldr x8, [x23, #0x28]; ret]
uint64_t fde_sub_06aed0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016E8ULL) << 32) | 0xD53BD057ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AED0ULL;
}

// FDE #1057 | PC: 0x06aedc..0x06aef0 (20 B) | Symbol: sub_06aedc
// EN: AArch64 prologue [add x8, x26, w22, sxtw #2; sub x8, x8, #4; lsl w9, w9, #0x10; sxtw x9, w9] | VI: Khởi đầu hàm AArch64 [add x8, x26, w22, sxtw #2; sub x8, x8, #4; lsl w9, w9, #0x10; sxtw x9, w9]
uint64_t fde_sub_06aedc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD1001108ULL) << 32) | 0x8B36CB48ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AEDCULL;
}

// FDE #1058 | PC: 0x06aef0..0x06aefc (12 B) | Symbol: sub_06aef0
// EN: AArch64 prologue [and w8, w0, #0xff; cmp w8, #1; ret] | VI: Khởi đầu hàm AArch64 [and w8, w0, #0xff; cmp w8, #1; ret]
uint64_t fde_sub_06aef0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100051FULL) << 32) | 0x12001C08ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AEF0ULL;
}

// FDE #1059 | PC: 0x06aefc..0x06af04 (8 B) | Symbol: sub_06aefc
// EN: AArch64 prologue [lsl w2, w8, #2; b #0x1a948] | VI: Khởi đầu hàm AArch64 [lsl w2, w8, #2; b #0x1a948]
uint64_t fde_sub_06aefc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBE92ULL) << 32) | 0x531E7502ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AEFCULL;
}

// FDE #1060 | PC: 0x06af04..0x06af10 (12 B) | Symbol: sub_06af04
// EN: AArch64 prologue [mov w21, wzr; mov w22, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w21, wzr; mov w22, wzr; ret]
uint64_t fde_sub_06af04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03F6ULL) << 32) | 0x2A1F03F5ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AF04ULL;
}

// FDE #1061 | PC: 0x06af10..0x06af1c (12 B) | Symbol: sub_06af10
// EN: AArch64 prologue [lsr x11, x11, #0x1f; and w11, w11, #0xfffffffe; ret] | VI: Khởi đầu hàm AArch64 [lsr x11, x11, #0x1f; and w11, w11, #0xfffffffe; ret]
uint64_t fde_sub_06af10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x121F796BULL) << 32) | 0xD35FFD6BULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AF10ULL;
}

// FDE #1062 | PC: 0x06af1c..0x06af30 (20 B) | Symbol: sub_06af1c
// EN: AArch64 prologue [mov v0.d[1], x8; str x8, [x19, #0x10]; str q0, [x19]; str w10, [x19, #0x20]] | VI: Khởi đầu hàm AArch64 [mov v0.d[1], x8; str x8, [x19, #0x10]; str q0, [x19]; str w10, [x19, #0x20]]
uint64_t fde_sub_06af1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000A68ULL) << 32) | 0x4E181D00ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AF1CULL;
}

// FDE #1063 | PC: 0x06af30..0x06af38 (8 B) | Symbol: sub_06af30
// EN: AArch64 prologue [mov w1, #0xc0; b #0x1a7e8] | VI: Khởi đầu hàm AArch64 [mov w1, #0xc0; b #0x1a7e8]
uint64_t fde_sub_06af30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBE2DULL) << 32) | 0x52801801ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AF30ULL;
}

// FDE #1064 | PC: 0x06af38..0x06af58 (32 B) | Symbol: sub_06af38
// EN: AArch64 prologue [sub x8, x29, #0x80; ldr x5, [x9, x26, lsl #3]; ldp q0, q2, [x19]; ldr q1, [x19, #0x20]] | VI: Khởi đầu hàm AArch64 [sub x8, x29, #0x80; ldr x5, [x9, x26, lsl #3]; ldp q0, q2, [x19]; ldr q1, [x19, #0x20]]
uint64_t fde_sub_06af38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF87A7925ULL) << 32) | 0xD10203A8ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AF38ULL;
}

// FDE #1065 | PC: 0x06af58..0x06af60 (8 B) | Symbol: sub_06af58
// EN: AArch64 prologue [mov w1, w20; b #0x1a7e8] | VI: Khởi đầu hàm AArch64 [mov w1, w20; b #0x1a7e8]
uint64_t fde_sub_06af58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBE23ULL) << 32) | 0x2A1403E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AF58ULL;
}

// FDE #1066 | PC: 0x06af60..0x06af80 (32 B) | Symbol: sub_06af60
// EN: AArch64 prologue [ldursw x14, [x29, #-0xb0]; cmp w8, #1; lsl w15, w12, w10; asr w12, w12, #1] | VI: Khởi đầu hàm AArch64 [ldursw x14, [x29, #-0xb0]; cmp w8, #1; lsl w15, w12, w10; asr w12, w12, #1]
uint64_t fde_sub_06af60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100051FULL) << 32) | 0xB89503AEULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AF60ULL;
}

// FDE #1067 | PC: 0x06af80..0x06afa0 (32 B) | Symbol: sub_06af80
// EN: AArch64 prologue [mov w9, #4; sdiv w9, w1, w9; mov w10, #2; asr w8, w8, w2] | VI: Khởi đầu hàm AArch64 [mov w9, #4; sdiv w9, w1, w9; mov w10, #2; asr w8, w8, w2]
uint64_t fde_sub_06af80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1AC90C29ULL) << 32) | 0x52800089ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AF80ULL;
}

// FDE #1068 | PC: 0x06afa0..0x06afc0 (32 B) | Symbol: sub_06afa0
// EN: AArch64 prologue [ldr w11, [sp, #0x38]; asr w9, w9, #1; asr w12, w10, #1; sub w8, w9, w8] | VI: Khởi đầu hàm AArch64 [ldr w11, [sp, #0x38]; asr w9, w9, #1; asr w12, w10, #1; sub w8, w9, w8]
uint64_t fde_sub_06afa0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x13017D29ULL) << 32) | 0xB9403BEBULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AFA0ULL;
}

// FDE #1069 | PC: 0x06afc0..0x06afd0 (16 B) | Symbol: sub_06afc0
// EN: AArch64 prologue [ldrb w11, [x9, x8]; strb w11, [x10, x8]; add x8, x8, #1; ret] | VI: Khởi đầu hàm AArch64 [ldrb w11, [x9, x8]; strb w11, [x10, x8]; add x8, x8, #1; ret]
uint64_t fde_sub_06afc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3828694BULL) << 32) | 0x3868692BULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AFC0ULL;
}

// FDE #1070 | PC: 0x06afd0..0x06afe4 (20 B) | Symbol: sub_06afd0
// EN: AArch64 prologue [add x0, sp, #0x8c; add x1, sp, #0x88; add w8, w9, w8; add w9, w11, w10] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x8c; add x1, sp, #0x88; add w8, w9, w8; add w9, w11, w10]
uint64_t fde_sub_06afd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910223E1ULL) << 32) | 0x910233E0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AFD0ULL;
}

// FDE #1071 | PC: 0x06afe4..0x06b004 (32 B) | Symbol: sub_06afe4
// EN: AArch64 prologue [ldr w8, [sp, #0xdc]; mov w9, #0x7fffffff; add w8, w27, w8; lsr w9, w9, w8] | VI: Khởi đầu hàm AArch64 [ldr w8, [sp, #0xdc]; mov w9, #0x7fffffff; add w8, w27, w8; lsr w9, w9, w8]
uint64_t fde_sub_06afe4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12B00009ULL) << 32) | 0xB940DFE8ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AFE4ULL;
}

// FDE #1072 | PC: 0x06b004..0x06b024 (32 B) | Symbol: sub_06b004
// EN: AArch64 prologue [mov w8, #4; stp w11, w4, [sp, #0x24]; stp w5, w6, [sp, #0x18]; str d1, [x20, #0x18]] | VI: Khởi đầu hàm AArch64 [mov w8, #4; stp w11, w4, [sp, #0x24]; stp w5, w6, [sp, #0x18]; str d1, [x20, #0x18]]
uint64_t fde_sub_06b004(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x290493EBULL) << 32) | 0x52800088ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B004ULL;
}

// FDE #1073 | PC: 0x06b024..0x06b034 (16 B) | Symbol: sub_06b024
// EN: AArch64 prologue [mrs x8, tpidr_el0; str x8, [sp, #0x10]; ldr x8, [x8, #0x28]; ret] | VI: Khởi đầu hàm AArch64 [mrs x8, tpidr_el0; str x8, [sp, #0x10]; ldr x8, [x8, #0x28]; ret]
uint64_t fde_sub_06b024(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BE8ULL) << 32) | 0xD53BD048ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B024ULL;
}

// FDE #1074 | PC: 0x06b034..0x06b040 (12 B) | Symbol: sub_06b034
// EN: AArch64 prologue [mov w0, wzr; str x20, [x19]; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; str x20, [x19]; ret]
uint64_t fde_sub_06b034(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000274ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B034ULL;
}

// FDE #1075 | PC: 0x06b040..0x06b050 (16 B) | Symbol: sub_06b040
// EN: AArch64 prologue [mov x8, xzr; sub w9, w20, w21; sxtw x10, w21; ret] | VI: Khởi đầu hàm AArch64 [mov x8, xzr; sub w9, w20, w21; sxtw x10, w21; ret]
uint64_t fde_sub_06b040(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4B150289ULL) << 32) | 0xAA1F03E8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B040ULL;
}

// FDE #1076 | PC: 0x06b050..0x06b05c (12 B) | Symbol: sub_06b050
// EN: AArch64 prologue [ldr x9, [sp, #0xf8]; add x8, x9, x8; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [sp, #0xf8]; add x8, x9, x8; ret]
uint64_t fde_sub_06b050(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8B080128ULL) << 32) | 0xF9407FE9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B050ULL;
}

// FDE #1077 | PC: 0x06b05c..0x06b070 (20 B) | Symbol: sub_06b05c
// EN: AArch64 prologue [add x0, x20, #0x40; add x2, sp, #4; add x5, sp, #8; mov w1, #1] | VI: Khởi đầu hàm AArch64 [add x0, x20, #0x40; add x2, sp, #4; add x5, sp, #8; mov w1, #1]
uint64_t fde_sub_06b05c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910013E2ULL) << 32) | 0x91010280ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B05CULL;
}

// FDE #1078 | PC: 0x06b070..0x06b090 (32 B) | Symbol: sub_06b070
// EN: AArch64 prologue [ldr w11, [sp]; asr w9, w9, #1; asr w12, w10, #1; sub w8, w9, w8] | VI: Khởi đầu hàm AArch64 [ldr w11, [sp]; asr w9, w9, #1; asr w12, w10, #1; sub w8, w9, w8]
uint64_t fde_sub_06b070(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x13017D29ULL) << 32) | 0xB94003EBULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B070ULL;
}

// FDE #1079 | PC: 0x06b090..0x06b0a0 (16 B) | Symbol: sub_06b090
// EN: AArch64 prologue [ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x18]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x18]; cmp x8, x9; ret]
uint64_t fde_sub_06b090(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF85E83A9ULL) << 32) | 0xF9401668ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B090ULL;
}

// FDE #1080 | PC: 0x06b0a0..0x06b0b0 (16 B) | Symbol: sub_06b0a0
// EN: AArch64 prologue [add x8, x8, #0xf82; fmov d0, x9; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [add x8, x8, #0xf82; fmov d0, x9; mov w0, wzr; ret]
uint64_t fde_sub_06b0a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9E670120ULL) << 32) | 0x913E0908ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B0A0ULL;
}

// FDE #1081 | PC: 0x06b0b0..0x06b0c0 (16 B) | Symbol: sub_06b0b0
// EN: AArch64 prologue [cmp w9, #0; orr w21, w21, #1; cneg w9, w9, mi; ret] | VI: Khởi đầu hàm AArch64 [cmp w9, #0; orr w21, w21, #1; cneg w9, w9, mi; ret]
uint64_t fde_sub_06b0b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x320002B5ULL) << 32) | 0x7100013FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B0B0ULL;
}

// FDE #1082 | PC: 0x06b0c0..0x06b0cc (12 B) | Symbol: sub_06b0c0
// EN: AArch64 prologue [mov x0, x21; mov x1, x20; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x21; mov x1, x20; ret]
uint64_t fde_sub_06b0c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E1ULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B0C0ULL;
}

// FDE #1083 | PC: 0x06b0cc..0x06b0d4 (8 B) | Symbol: sub_06b0cc
// EN: AArch64 prologue [mov w1, #0x50; b #0x1a7e8] | VI: Khởi đầu hàm AArch64 [mov w1, #0x50; b #0x1a7e8]
uint64_t fde_sub_06b0cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBDC6ULL) << 32) | 0x52800A01ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B0CCULL;
}

// FDE #1084 | PC: 0x06b0d4..0x06b0e4 (16 B) | Symbol: sub_06b0d4
// EN: AArch64 prologue [cmp w8, #0; mov w21, #1; cneg w8, w8, mi; ret] | VI: Khởi đầu hàm AArch64 [cmp w8, #0; mov w21, #1; cneg w8, w8, mi; ret]
uint64_t fde_sub_06b0d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800035ULL) << 32) | 0x7100011FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B0D4ULL;
}

// FDE #1085 | PC: 0x06b0e4..0x06b0f0 (12 B) | Symbol: sub_06b0e4
// EN: AArch64 prologue [cmp w8, #0; cset w8, ne; ret] | VI: Khởi đầu hàm AArch64 [cmp w8, #0; cset w8, ne; ret]
uint64_t fde_sub_06b0e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1A9F07E8ULL) << 32) | 0x7100011FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B0E4ULL;
}

// FDE #1086 | PC: 0x06b0f0..0x06b110 (32 B) | Symbol: sub_06b0f0
// EN: AArch64 prologue [mov w9, #1; lsl w10, w9, w2; asr w1, w10, #1; and w3, w10, #0xfffffffe] | VI: Khởi đầu hàm AArch64 [mov w9, #1; lsl w10, w9, w2; asr w1, w10, #1; and w3, w10, #0xfffffffe]
uint64_t fde_sub_06b0f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1AC2212AULL) << 32) | 0x52800029ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B0F0ULL;
}

// FDE #1087 | PC: 0x06b110..0x06b120 (16 B) | Symbol: sub_06b110
// EN: AArch64 prologue [mov w9, #1; mov w0, wzr; str w9, [x8]; ret] | VI: Khởi đầu hàm AArch64 [mov w9, #1; mov w0, wzr; str w9, [x8]; ret]
uint64_t fde_sub_06b110(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0x52800029ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B110ULL;
}

// FDE #1088 | PC: 0x06b120..0x06b134 (20 B) | Symbol: sub_06b120
// EN: AArch64 prologue [add x9, x24, x22, lsl #1; mov w11, #0x11; strh w10, [x9, x19]; sub w10, w10, w8] | VI: Khởi đầu hàm AArch64 [add x9, x24, x22, lsl #1; mov w11, #0x11; strh w10, [x9, x19]; sub w10, w10, w8]
uint64_t fde_sub_06b120(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5280022BULL) << 32) | 0x8B160709ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B120ULL;
}

// FDE #1089 | PC: 0x06b134..0x06b140 (12 B) | Symbol: sub_06b134
// EN: AArch64 prologue [mov w3, #0x200; mov x0, x19; b #0x1cbc8] | VI: Khởi đầu hàm AArch64 [mov w3, #0x200; mov x0, x19; b #0x1cbc8]
uint64_t fde_sub_06b134(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x52804003ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B134ULL;
}

// FDE #1090 | PC: 0x06b140..0x06b14c (12 B) | Symbol: sub_06b140
// EN: AArch64 prologue [mov x0, sp; add w11, w8, w9, asr #1; ret] | VI: Khởi đầu hàm AArch64 [mov x0, sp; add w11, w8, w9, asr #1; ret]
uint64_t fde_sub_06b140(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x0B89050BULL) << 32) | 0x910003E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B140ULL;
}

// FDE #1091 | PC: 0x06b14c..0x06b158 (12 B) | Symbol: sub_06b14c
// EN: AArch64 prologue [sxtb w8, w8; cmp w8, #1; ret] | VI: Khởi đầu hàm AArch64 [sxtb w8, w8; cmp w8, #1; ret]
uint64_t fde_sub_06b14c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100051FULL) << 32) | 0x13001D08ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B14CULL;
}

// FDE #1092 | PC: 0x06b158..0x06b184 (44 B) | Symbol: sub_06b158
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; mov x1, x19; mov w2, w22; mov w3, w24] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; mov x1, x19; mov w2, w22; mov w3, w24]
uint64_t fde_sub_06b158(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E1ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B158ULL;
}

// FDE #1093 | PC: 0x06b184..0x06b194 (16 B) | Symbol: sub_06b184
// EN: AArch64 prologue [add w8, w0, w1; add w1, w8, #8; mov w0, #1; b #0x1a748] | VI: Khởi đầu hàm AArch64 [add w8, w0, w1; add w1, w8, #8; mov w0, #1; b #0x1a748]
uint64_t fde_sub_06b184(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x11002101ULL) << 32) | 0x0B010008ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B184ULL;
}

// FDE #1094 | PC: 0x06b194..0x06b1b0 (28 B) | Symbol: sub_06b194
// EN: AArch64 prologue [mov w8, #0x5a820000; smull x9, w2, w8; smull x8, w3, w8; lsr x9, x9, #0x20] | VI: Khởi đầu hàm AArch64 [mov w8, #0x5a820000; smull x9, w2, w8; smull x8, w3, w8; lsr x9, x9, #0x20]
uint64_t fde_sub_06b194(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9B287C49ULL) << 32) | 0x52AB5048ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B194ULL;
}

// FDE #1095 | PC: 0x06b1b0..0x06b1cc (28 B) | Symbol: sub_06b1b0
// EN: AArch64 prologue [add x22, x20, #8; asr w8, w8, #1; str w8, [x20]; ldur w23, [x29, #-0x54]] | VI: Khởi đầu hàm AArch64 [add x22, x20, #8; asr w8, w8, #1; str w8, [x20]; ldur w23, [x29, #-0x54]]
uint64_t fde_sub_06b1b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x13017D08ULL) << 32) | 0x91002296ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B1B0ULL;
}

// FDE #1096 | PC: 0x06b1cc..0x06b1e8 (28 B) | Symbol: sub_06b1cc
// EN: AArch64 prologue [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #3; mov w3, #3] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #3; mov w3, #3]
uint64_t fde_sub_06b1cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910783E1ULL) << 32) | 0x910243E0ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B1CCULL;
}

// FDE #1097 | PC: 0x06b1e8..0x06b204 (28 B) | Symbol: sub_06b1e8
// EN: AArch64 prologue [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #1; mov w3, wzr] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #1; mov w3, wzr]
uint64_t fde_sub_06b1e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910783E1ULL) << 32) | 0x910243E0ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B1E8ULL;
}

// FDE #1098 | PC: 0x06b204..0x06b218 (20 B) | Symbol: sub_06b204
// EN: AArch64 prologue [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #4; mov x19, x13] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #4; mov x19, x13]
uint64_t fde_sub_06b204(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910783E1ULL) << 32) | 0x910243E0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B204ULL;
}

// FDE #1099 | PC: 0x06b218..0x06b22c (20 B) | Symbol: sub_06b218
// EN: AArch64 prologue [ldr x8, [x21, x24, lsl #3]; mov w1, w20; mov w2, w19; add x0, x8, x23, lsl #2] | VI: Khởi đầu hàm AArch64 [ldr x8, [x21, x24, lsl #3]; mov w1, w20; mov w2, w19; add x0, x8, x23, lsl #2]
uint64_t fde_sub_06b218(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1403E1ULL) << 32) | 0xF8787AA8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B218ULL;
}

// FDE #1100 | PC: 0x06b22c..0x06b238 (12 B) | Symbol: sub_06b22c
// EN: AArch64 prologue [mov w1, #0xff; mov w2, #8; b #0x1ba18] | VI: Khởi đầu hàm AArch64 [mov w1, #0xff; mov w2, #8; b #0x1ba18]
uint64_t fde_sub_06b22c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800102ULL) << 32) | 0x52801FE1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B22CULL;
}

// FDE #1101 | PC: 0x06b238..0x06b254 (28 B) | Symbol: sub_06b238
// EN: AArch64 prologue [ldr w4, [sp, #0x84]; sub x0, x29, #0x64; sub x1, x29, #0x68; mov x2, x28] | VI: Khởi đầu hàm AArch64 [ldr w4, [sp, #0x84]; sub x0, x29, #0x64; sub x1, x29, #0x68; mov x2, x28]
uint64_t fde_sub_06b238(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10193A0ULL) << 32) | 0xB94087E4ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B238ULL;
}

// FDE #1102 | PC: 0x06b254..0x06b270 (28 B) | Symbol: sub_06b254
// EN: AArch64 prologue [ldr w8, [sp, #0x50]; sub w8, w8, #2; str w8, [sp, #0x50]; ldr w8, [sp, #0x4c]] | VI: Khởi đầu hàm AArch64 [ldr w8, [sp, #0x50]; sub w8, w8, #2; str w8, [sp, #0x50]; ldr w8, [sp, #0x4c]]
uint64_t fde_sub_06b254(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x51000908ULL) << 32) | 0xB94053E8ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B254ULL;
}

// FDE #1103 | PC: 0x06b270..0x06b284 (20 B) | Symbol: sub_06b270
// EN: AArch64 prologue [ldr x6, [sp, #0x80]; add x7, sp, #0xe4; mov w3, wzr; str x8, [sp]] | VI: Khởi đầu hàm AArch64 [ldr x6, [sp, #0x80]; add x7, sp, #0xe4; mov w3, wzr; str x8, [sp]]
uint64_t fde_sub_06b270(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910393E7ULL) << 32) | 0xF94043E6ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B270ULL;
}

// FDE #1104 | PC: 0x06b284..0x06b28c (8 B) | Symbol: sub_06b284
// EN: AArch64 prologue [mov w1, w28; b #0x1a7e8] | VI: Khởi đầu hàm AArch64 [mov w1, w28; b #0x1a7e8]
uint64_t fde_sub_06b284(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBD58ULL) << 32) | 0x2A1C03E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B284ULL;
}

// FDE #1105 | PC: 0x06b28c..0x06b294 (8 B) | Symbol: sub_06b28c
// EN: AArch64 prologue [add sp, sp, #0x30; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0x30; ret]
uint64_t fde_sub_06b28c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x9100C3FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B28CULL;
}

// FDE #1106 | PC: 0x06b294..0x06b2a8 (20 B) | Symbol: sub_06b294
// EN: AArch64 prologue [add w8, w23, #0x10; cmp w0, #0; mov x0, x20; csel w23, w23, w8, eq] | VI: Khởi đầu hàm AArch64 [add w8, w23, #0x10; cmp w0, #0; mov x0, x20; csel w23, w23, w8, eq]
uint64_t fde_sub_06b294(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100001FULL) << 32) | 0x110042E8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B294ULL;
}

// FDE #1107 | PC: 0x06b2a8..0x06b2b4 (12 B) | Symbol: sub_06b2a8
// EN: AArch64 prologue [mov x1, x22; mov w2, wzr; b #0x5bc98] | VI: Khởi đầu hàm AArch64 [mov x1, x22; mov w2, wzr; b #0x5bc98]
uint64_t fde_sub_06b2a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E2ULL) << 32) | 0xAA1603E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B2A8ULL;
}

// FDE #1108 | PC: 0x06b2b4..0x06b2bc (8 B) | Symbol: sub_06b2b4
// EN: AArch64 prologue [mov x1, x22; b #0x5bc10] | VI: Khởi đầu hàm AArch64 [mov x1, x22; b #0x5bc10]
uint64_t fde_sub_06b2b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFC256ULL) << 32) | 0xAA1603E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B2B4ULL;
}

// FDE #1109 | PC: 0x06b2bc..0x06b2c8 (12 B) | Symbol: sub_06b2bc
// EN: AArch64 prologue [add x8, x9, x8; add x9, x10, x8, lsl #2; ret] | VI: Khởi đầu hàm AArch64 [add x8, x9, x8; add x9, x10, x8, lsl #2; ret]
uint64_t fde_sub_06b2bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8B080949ULL) << 32) | 0x8B080128ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B2BCULL;
}

// FDE #1110 | PC: 0x06b2c8..0x06b2e4 (28 B) | Symbol: sub_06b2c8
// EN: AArch64 prologue [add w12, w3, #1; add w11, w11, #1; add x10, x10, #1; strb w12, [x4, x10]] | VI: Khởi đầu hàm AArch64 [add w12, w3, #1; add w11, w11, #1; add x10, x10, #1; strb w12, [x4, x10]]
uint64_t fde_sub_06b2c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1100056BULL) << 32) | 0x1100046CULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B2C8ULL;
}

// FDE #1111 | PC: 0x06b2e4..0x06b2f8 (20 B) | Symbol: sub_06b2e4
// EN: AArch64 prologue [mov w1, w27; mov x3, x25; mov x5, x22; mov x6, x26] | VI: Khởi đầu hàm AArch64 [mov w1, w27; mov x3, x25; mov x5, x22; mov x6, x26]
uint64_t fde_sub_06b2e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1903E3ULL) << 32) | 0x2A1B03E1ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B2E4ULL;
}

// FDE #1112 | PC: 0x06b2f8..0x06b304 (12 B) | Symbol: sub_06b2f8
// EN: AArch64 prologue [mov x1, x20; mov w2, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov x1, x20; mov w2, wzr; ret]
uint64_t fde_sub_06b2f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E2ULL) << 32) | 0xAA1403E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B2F8ULL;
}

// FDE #1113 | PC: 0x06b304..0x06b310 (12 B) | Symbol: sub_06b304
// EN: AArch64 prologue [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; ret] | VI: Khởi đầu hàm AArch64 [mrs x21, tpidr_el0; ldr x8, [x21, #0x28]; ret]
uint64_t fde_sub_06b304(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94016A8ULL) << 32) | 0xD53BD055ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B304ULL;
}

// FDE #1114 | PC: 0x06b310..0x06b31c (12 B) | Symbol: sub_06b310
// EN: AArch64 prologue [mov x4, x26; stur wzr, [x29, #-0x60]; b #0x1f078] | VI: Khởi đầu hàm AArch64 [mov x4, x26; stur wzr, [x29, #-0x60]; b #0x1f078]
uint64_t fde_sub_06b310(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB81A03BFULL) << 32) | 0xAA1A03E4ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B310ULL;
}

// FDE #1115 | PC: 0x06b31c..0x06b330 (20 B) | Symbol: sub_06b31c
// EN: AArch64 prologue [ldr x0, [sp, #0x60]; sub x4, x29, #0x60; mov x2, x22; mov x3, x26] | VI: Khởi đầu hàm AArch64 [ldr x0, [sp, #0x60]; sub x4, x29, #0x60; mov x2, x22; mov x3, x26]
uint64_t fde_sub_06b31c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183A4ULL) << 32) | 0xF94033E0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B31CULL;
}

// FDE #1116 | PC: 0x06b330..0x06b344 (20 B) | Symbol: sub_06b330
// EN: AArch64 prologue [ldr w8, [x20, #0x30]; mov w2, #1; mov x0, x19; ubfx w1, w8, #0x1a, #1] | VI: Khởi đầu hàm AArch64 [ldr w8, [x20, #0x30]; mov w2, #1; mov x0, x19; ubfx w1, w8, #0x1a, #1]
uint64_t fde_sub_06b330(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800022ULL) << 32) | 0xB9403288ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B330ULL;
}

// FDE #1117 | PC: 0x06b344..0x06b358 (20 B) | Symbol: sub_06b344
// EN: AArch64 prologue [ldr w8, [x20, #0x30]; mov w2, #1; mov x0, x19; ubfx w1, w8, #0x18, #1] | VI: Khởi đầu hàm AArch64 [ldr w8, [x20, #0x30]; mov w2, #1; mov x0, x19; ubfx w1, w8, #0x18, #1]
uint64_t fde_sub_06b344(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800022ULL) << 32) | 0xB9403288ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B344ULL;
}

// FDE #1118 | PC: 0x06b358..0x06b360 (8 B) | Symbol: sub_06b358
// EN: AArch64 prologue [mov w0, #-0x63; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #-0x63; ret]
uint64_t fde_sub_06b358(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x12800C40ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B358ULL;
}

// FDE #1119 | PC: 0x06b360..0x06b37c (28 B) | Symbol: sub_06b360
// EN: AArch64 prologue [ldrsw x11, [x23, x8, lsl #2]; ldrsw x12, [x22, x8, lsl #2]; mul x11, x11, x10; mul x12, x12, x10] | VI: Khởi đầu hàm AArch64 [ldrsw x11, [x23, x8, lsl #2]; ldrsw x12, [x22, x8, lsl #2]; mul x11, x11, x10; mul x12, x12, x10]
uint64_t fde_sub_06b360(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB8A87ACCULL) << 32) | 0xB8A87AEBULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B360ULL;
}

// FDE #1120 | PC: 0x06b37c..0x06b398 (28 B) | Symbol: sub_06b37c
// EN: AArch64 prologue [ldrsw x10, [x23, x8, lsl #2]; ldrsw x11, [x22, x8, lsl #2]; mul x10, x10, x9; mul x11, x11, x9] | VI: Khởi đầu hàm AArch64 [ldrsw x10, [x23, x8, lsl #2]; ldrsw x11, [x22, x8, lsl #2]; mul x10, x10, x9; mul x11, x11, x9]
uint64_t fde_sub_06b37c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB8A87ACBULL) << 32) | 0xB8A87AEAULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B37CULL;
}

// FDE #1121 | PC: 0x06b398..0x06b3a0 (8 B) | Symbol: sub_06b398
// EN: AArch64 prologue [str w8, [x2, #0x2c]; ret] | VI: Khởi đầu hàm AArch64 [str w8, [x2, #0x2c]; ret]
uint64_t fde_sub_06b398(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9002C48ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B398ULL;
}

// FDE #1122 | PC: 0x06b3a0..0x06b3bc (28 B) | Symbol: sub_06b3a0
// EN: AArch64 prologue [add w12, w9, w10; sub w8, w8, w11; sub w9, w10, w9; lsl w10, w12, #1] | VI: Khởi đầu hàm AArch64 [add w12, w9, w10; sub w8, w8, w11; sub w9, w10, w9; lsl w10, w12, #1]
uint64_t fde_sub_06b3a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4B0B0108ULL) << 32) | 0x0B0A012CULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B3A0ULL;
}

// FDE #1123 | PC: 0x06b3bc..0x06b3d8 (28 B) | Symbol: sub_06b3bc
// EN: AArch64 prologue [ldrb w9, [x19, #0x1ce]; add x22, x22, #1; cmp w8, #0; cinc w8, w23, ne] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x19, #0x1ce]; add x22, x22, #1; cmp w8, #0; cinc w8, w23, ne]
uint64_t fde_sub_06b3bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910006D6ULL) << 32) | 0x39473A69ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B3BCULL;
}

// FDE #1124 | PC: 0x06b3d8..0x06b3e4 (12 B) | Symbol: sub_06b3d8
// EN: AArch64 prologue [mov w2, #0x12; mov x0, x26; b #0x1a948] | VI: Khởi đầu hàm AArch64 [mov w2, #0x12; mov x0, x26; b #0x1a948]
uint64_t fde_sub_06b3d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1A03E0ULL) << 32) | 0x52800242ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B3D8ULL;
}

// FDE #1125 | PC: 0x06b3e4..0x06b400 (28 B) | Symbol: sub_06b3e4
// EN: AArch64 prologue [add w13, w12, #0xc; sub w12, w12, #0x12; cmp w13, #0x1d; csel w12, w12, w13, gt] | VI: Khởi đầu hàm AArch64 [add w13, w12, #0xc; sub w12, w12, #0x12; cmp w13, #0x1d; csel w12, w12, w13, gt]
uint64_t fde_sub_06b3e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5100498CULL) << 32) | 0x1100318DULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B3E4ULL;
}

// FDE #1126 | PC: 0x06b400..0x06b41c (28 B) | Symbol: sub_06b400
// EN: AArch64 prologue [add w14, w12, #0xc; sub w12, w12, #0x12; cmp w14, #0x1d; csel w12, w12, w14, gt] | VI: Khởi đầu hàm AArch64 [add w14, w12, #0xc; sub w12, w12, #0x12; cmp w14, #0x1d; csel w12, w12, w14, gt]
uint64_t fde_sub_06b400(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5100498CULL) << 32) | 0x1100318EULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B400ULL;
}

// FDE #1127 | PC: 0x06b41c..0x06b428 (12 B) | Symbol: sub_06b41c
// EN: AArch64 prologue [mov x20, x1; mov x19, x0; ret] | VI: Khởi đầu hàm AArch64 [mov x20, x1; mov x19, x0; ret]
uint64_t fde_sub_06b41c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xAA0103F4ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B41CULL;
}

// FDE #1128 | PC: 0x06b428..0x06b434 (12 B) | Symbol: sub_06b428
// EN: AArch64 prologue [mov x20, x1; mov x21, x0; ret] | VI: Khởi đầu hàm AArch64 [mov x20, x1; mov x21, x0; ret]
uint64_t fde_sub_06b428(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F5ULL) << 32) | 0xAA0103F4ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B428ULL;
}

// FDE #1129 | PC: 0x06b434..0x06b450 (28 B) | Symbol: sub_06b434
// EN: AArch64 prologue [smull x14, w14, w14; smull x15, w15, w15; lsr x14, x14, #0x20; lsr x15, x15, #0x20] | VI: Khởi đầu hàm AArch64 [smull x14, w14, w14; smull x15, w15, w15; lsr x14, x14, #0x20; lsr x15, x15, #0x20]
uint64_t fde_sub_06b434(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9B2F7DEFULL) << 32) | 0x9B2E7DCEULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B434ULL;
}

// FDE #1130 | PC: 0x06b450..0x06b46c (28 B) | Symbol: sub_06b450
// EN: AArch64 prologue [sub x8, x29, #0x80; ldr x8, [x8, x24, lsl #3]; cmp w10, #0x1f; mov w11, #0x1f] | VI: Khởi đầu hàm AArch64 [sub x8, x29, #0x80; ldr x8, [x8, x24, lsl #3]; cmp w10, #0x1f; mov w11, #0x1f]
uint64_t fde_sub_06b450(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF8787908ULL) << 32) | 0xD10203A8ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B450ULL;
}

// FDE #1131 | PC: 0x06b46c..0x06b474 (8 B) | Symbol: sub_06b46c
// EN: AArch64 prologue [mov x0, x20; b #0x1a7e8] | VI: Khởi đầu hàm AArch64 [mov x0, x20; b #0x1a7e8]
uint64_t fde_sub_06b46c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBCDEULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B46CULL;
}

// FDE #1132 | PC: 0x06b474..0x06b488 (20 B) | Symbol: sub_06b474
// EN: AArch64 prologue [mov x0, x20; mov x1, x19; mov x2, x23; mov x3, x22] | VI: Khởi đầu hàm AArch64 [mov x0, x20; mov x1, x19; mov x2, x23; mov x3, x22]
uint64_t fde_sub_06b474(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E1ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B474ULL;
}

// FDE #1133 | PC: 0x06b488..0x06b490 (8 B) | Symbol: sub_06b488
// EN: AArch64 prologue [mov x0, x20; b #0x1df60] | VI: Khởi đầu hàm AArch64 [mov x0, x20; b #0x1df60]
uint64_t fde_sub_06b488(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FECAB5ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B488ULL;
}

// FDE #1134 | PC: 0x06b490..0x06b498 (8 B) | Symbol: sub_06b490
// EN: AArch64 prologue [mov x20, x0; b #0x1a7e8] | VI: Khởi đầu hàm AArch64 [mov x20, x0; b #0x1a7e8]
uint64_t fde_sub_06b490(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBCD5ULL) << 32) | 0xAA0003F4ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B490ULL;
}

// FDE #1135 | PC: 0x06b498..0x06b4a4 (12 B) | Symbol: sub_06b498
// EN: AArch64 prologue [mov x20, x0; mov x19, x1; ret] | VI: Khởi đầu hàm AArch64 [mov x20, x0; mov x19, x1; ret]
uint64_t fde_sub_06b498(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103F3ULL) << 32) | 0xAA0003F4ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B498ULL;
}

// FDE #1136 | PC: 0x06b4a4..0x06b4ac (8 B) | Symbol: sub_06b4a4
// EN: AArch64 prologue [mov x0, x25; b #0x1d1b8] | VI: Khởi đầu hàm AArch64 [mov x0, x25; b #0x1d1b8]
uint64_t fde_sub_06b4a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC744ULL) << 32) | 0xAA1903E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B4A4ULL;
}

// FDE #1137 | PC: 0x06b4ac..0x06b4b8 (12 B) | Symbol: sub_06b4ac
// EN: AArch64 prologue [mov x0, x19; mov w1, w23; b #0x322bc] | VI: Khởi đầu hàm AArch64 [mov x0, x19; mov w1, w23; b #0x322bc]
uint64_t fde_sub_06b4ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1703E1ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B4ACULL;
}

// FDE #1138 | PC: 0x06b4b8..0x06b4c4 (12 B) | Symbol: sub_06b4b8
// EN: AArch64 prologue [mov x0, x19; sub w1, w8, #1; b #0x322bc] | VI: Khởi đầu hàm AArch64 [mov x0, x19; sub w1, w8, #1; b #0x322bc]
uint64_t fde_sub_06b4b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x51000501ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B4B8ULL;
}

// FDE #1139 | PC: 0x06b4c4..0x06b4d0 (12 B) | Symbol: sub_06b4c4
// EN: AArch64 prologue [mov x0, x19; mov w1, wzr; b #0x62a80] | VI: Khởi đầu hàm AArch64 [mov x0, x19; mov w1, wzr; b #0x62a80]
uint64_t fde_sub_06b4c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E1ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B4C4ULL;
}

// FDE #1140 | PC: 0x06b4d0..0x06b4dc (12 B) | Symbol: sub_06b4d0
// EN: AArch64 prologue [mov x0, x19; mov w1, w20; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x19; mov w1, w20; ret]
uint64_t fde_sub_06b4d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1403E1ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B4D0ULL;
}

// FDE #1141 | PC: 0x06b4dc..0x06b4e8 (12 B) | Symbol: sub_06b4dc
// EN: AArch64 prologue [mov x21, x0; mov x22, xzr; ret] | VI: Khởi đầu hàm AArch64 [mov x21, x0; mov x22, xzr; ret]
uint64_t fde_sub_06b4dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03F6ULL) << 32) | 0xAA0003F5ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B4DCULL;
}

// FDE #1142 | PC: 0x06b4e8..0x06b504 (28 B) | Symbol: sub_06b4e8
// EN: AArch64 prologue [sub w13, w13, #1; mul w12, w12, w11; lsr w12, w12, #0x10; strh w12, [x14, x9, lsl #1]] | VI: Khởi đầu hàm AArch64 [sub w13, w13, #1; mul w12, w12, w11; lsr w12, w12, #0x10; strh w12, [x14, x9, lsl #1]]
uint64_t fde_sub_06b4e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1B0B7D8CULL) << 32) | 0x510005ADULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B4E8ULL;
}

// FDE #1143 | PC: 0x06b504..0x06b518 (20 B) | Symbol: sub_06b504
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x1a7e8; mov x8, xzr; ldr x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x1a7e8; mov x8, xzr; ldr x30, [sp], #0x10]
uint64_t fde_sub_06b504(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x97FEBCB8ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B504ULL;
}

// FDE #1144 | PC: 0x06b518..0x06b520 (8 B) | Symbol: sub_06b518
// EN: AArch64 prologue [mov w1, w22; b #0x1a7e8] | VI: Khởi đầu hàm AArch64 [mov w1, w22; b #0x1a7e8]
uint64_t fde_sub_06b518(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBCB3ULL) << 32) | 0x2A1603E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B518ULL;
}

// FDE #1145 | PC: 0x06b520..0x06b53c (28 B) | Symbol: sub_06b520
// EN: AArch64 prologue [add x13, x13, #0x80; sub x8, x29, #0x38; stur x12, [x29, #-0x18]; stp x10, x9, [x29, #-0x38]] | VI: Khởi đầu hàm AArch64 [add x13, x13, #0x80; sub x8, x29, #0x38; stur x12, [x29, #-0x18]; stp x10, x9, [x29, #-0x38]]
uint64_t fde_sub_06b520(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD100E3A8ULL) << 32) | 0x910201ADULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B520ULL;
}

// FDE #1146 | PC: 0x06b53c..0x06b544 (8 B) | Symbol: sub_06b53c
// EN: AArch64 prologue [add sp, sp, #0x60; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0x60; ret]
uint64_t fde_sub_06b53c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910183FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B53CULL;
}

// FDE #1147 | PC: 0x06b544..0x06b550 (12 B) | Symbol: sub_06b544
// EN: AArch64 prologue [add x0, sp, #4; add w11, w8, w9, asr #1; ret] | VI: Khởi đầu hàm AArch64 [add x0, sp, #4; add w11, w8, w9, asr #1; ret]
uint64_t fde_sub_06b544(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x0B89050BULL) << 32) | 0x910013E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B544ULL;
}

// FDE #1148 | PC: 0x06b550..0x06b56c (28 B) | Symbol: sub_06b550
// EN: AArch64 prologue [adrp x1, #0x72000; add x0, x19, #0x24; add x1, x1, #0xf79; mov w2, #2] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x72000; add x0, x19, #0x24; add x1, x1, #0xf79; mov w2, #2]
uint64_t fde_sub_06b550(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91009260ULL) << 32) | 0xF0000021ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B550ULL;
}

// FDE #1149 | PC: 0x06b56c..0x06b574 (8 B) | Symbol: sub_06b56c
// EN: AArch64 prologue [mov w1, w21; b #0x1a7e8] | VI: Khởi đầu hàm AArch64 [mov w1, w21; b #0x1a7e8]
uint64_t fde_sub_06b56c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBC9EULL) << 32) | 0x2A1503E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B56CULL;
}

// FDE #1150 | PC: 0x06b574..0x06b580 (12 B) | Symbol: sub_06b574
// EN: AArch64 prologue [mov w1, w21; add x0, x8, x23, lsl #2; b #0x1a7e8] | VI: Khởi đầu hàm AArch64 [mov w1, w21; add x0, x8, x23, lsl #2; b #0x1a7e8]
uint64_t fde_sub_06b574(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8B170900ULL) << 32) | 0x2A1503E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B574ULL;
}

// FDE #1151 | PC: 0x06b580..0x06b58c (12 B) | Symbol: sub_06b580
// EN: AArch64 prologue [ldur x9, [x29, #-0x38]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldur x9, [x29, #-0x38]; cmp x8, x9; ret]
uint64_t fde_sub_06b580(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xF85C83A9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B580ULL;
}

// FDE #1152 | PC: 0x06b58c..0x06b5a0 (20 B) | Symbol: sub_06b58c
// EN: AArch64 prologue [ldp x20, x19, [sp, #0x30]; ldp x22, x21, [sp, #0x20]; ldp x24, x23, [sp, #0x10]; add sp, sp, #0x50] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0x30]; ldp x22, x21, [sp, #0x20]; ldp x24, x23, [sp, #0x10]; add sp, sp, #0x50]
uint64_t fde_sub_06b58c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94257F6ULL) << 32) | 0xA9434FF4ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B58CULL;
}

// FDE #1153 | PC: 0x06b5a0..0x06b5b4 (20 B) | Symbol: sub_06b5a0
// EN: AArch64 prologue [ldp x20, x19, [sp, #0x30]; ldp x22, x21, [sp, #0x20]; ldp x24, x23, [sp, #0x10]; ldp x26, x25, [sp], #0x40] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0x30]; ldp x22, x21, [sp, #0x20]; ldp x24, x23, [sp, #0x10]; ldp x26, x25, [sp], #0x40]
uint64_t fde_sub_06b5a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94257F6ULL) << 32) | 0xA9434FF4ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B5A0ULL;
}

// FDE #1154 | PC: 0x06b5b4..0x06b5c0 (12 B) | Symbol: sub_06b5b4
// EN: AArch64 prologue [mov x0, x21; mov x1, x22; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x21; mov x1, x22; ret]
uint64_t fde_sub_06b5b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E1ULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B5B4ULL;
}

// FDE #1155 | PC: 0x06b5c0..0x06b5cc (12 B) | Symbol: sub_06b5c0
// EN: AArch64 prologue [mov x0, x21; mov x1, x22; b #0x5b928] | VI: Khởi đầu hàm AArch64 [mov x0, x21; mov x1, x22; b #0x5b928]
uint64_t fde_sub_06b5c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E1ULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B5C0ULL;
}

// FDE #1156 | PC: 0x06b5cc..0x06b5d8 (12 B) | Symbol: sub_06b5cc
// EN: AArch64 prologue [mov w1, #1; mov x0, x23; b #0x1d1d8] | VI: Khởi đầu hàm AArch64 [mov w1, #1; mov x0, x23; b #0x1d1d8]
uint64_t fde_sub_06b5cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1703E0ULL) << 32) | 0x52800021ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B5CCULL;
}

// FDE #1157 | PC: 0x06b5d8..0x06b5e4 (12 B) | Symbol: sub_06b5d8
// EN: AArch64 prologue [mov w1, #1; mov x0, x19; ret] | VI: Khởi đầu hàm AArch64 [mov w1, #1; mov x0, x19; ret]
uint64_t fde_sub_06b5d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x52800021ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B5D8ULL;
}

// FDE #1158 | PC: 0x06b5e4..0x06b5f8 (20 B) | Symbol: sub_06b5e4
// EN: AArch64 prologue [mov w1, #1; mov w2, #1; mov x0, x19; lsr w22, w22, #1] | VI: Khởi đầu hàm AArch64 [mov w1, #1; mov w2, #1; mov x0, x19; lsr w22, w22, #1]
uint64_t fde_sub_06b5e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800022ULL) << 32) | 0x52800021ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B5E4ULL;
}

// FDE #1159 | PC: 0x06b5f8..0x06b604 (12 B) | Symbol: sub_06b5f8
// EN: AArch64 prologue [cmp w8, #0; cset w8, eq; ret] | VI: Khởi đầu hàm AArch64 [cmp w8, #0; cset w8, eq; ret]
uint64_t fde_sub_06b5f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1A9F17E8ULL) << 32) | 0x7100011FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B5F8ULL;
}

// FDE #1160 | PC: 0x06b604..0x06b618 (20 B) | Symbol: sub_06b604
// EN: AArch64 prologue [mov w24, w5; mov w23, w4; mov x19, x3; mov x20, x2] | VI: Khởi đầu hàm AArch64 [mov w24, w5; mov w23, w4; mov x19, x3; mov x20, x2]
uint64_t fde_sub_06b604(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A0403F7ULL) << 32) | 0x2A0503F8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B604ULL;
}

// FDE #1161 | PC: 0x06b618..0x06b620 (8 B) | Symbol: sub_06b618
// EN: AArch64 prologue [mov w1, #8; b #0x1a7e8] | VI: Khởi đầu hàm AArch64 [mov w1, #8; b #0x1a7e8]
uint64_t fde_sub_06b618(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBC73ULL) << 32) | 0x52800101ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B618ULL;
}

// FDE #1162 | PC: 0x06b620..0x06b630 (16 B) | Symbol: sub_06b620
// EN: AArch64 prologue [mov w2, #3; mov x0, x19; str w8, [x9]; b #0x322bc] | VI: Khởi đầu hàm AArch64 [mov w2, #3; mov x0, x19; str w8, [x9]; b #0x322bc]
uint64_t fde_sub_06b620(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x52800062ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B620ULL;
}

// FDE #1163 | PC: 0x06b630..0x06b640 (16 B) | Symbol: sub_06b630
// EN: AArch64 prologue [mov x20, x2; mov x21, x1; mov x22, x0; ret] | VI: Khởi đầu hàm AArch64 [mov x20, x2; mov x21, x1; mov x22, x0; ret]
uint64_t fde_sub_06b630(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103F5ULL) << 32) | 0xAA0203F4ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B630ULL;
}

// FDE #1164 | PC: 0x06b640..0x06b650 (16 B) | Symbol: sub_06b640
// EN: AArch64 prologue [mov x8, sp; mov w23, wzr; add x24, x8, #4; ret] | VI: Khởi đầu hàm AArch64 [mov x8, sp; mov w23, wzr; add x24, x8, #4; ret]
uint64_t fde_sub_06b640(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03F7ULL) << 32) | 0x910003E8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B640ULL;
}

// FDE #1165 | PC: 0x06b650..0x06b65c (12 B) | Symbol: sub_06b650
// EN: AArch64 prologue [add w21, w21, w0, uxtb; add x22, x22, #1; ret] | VI: Khởi đầu hàm AArch64 [add w21, w21, w0, uxtb; add x22, x22, #1; ret]
uint64_t fde_sub_06b650(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910006D6ULL) << 32) | 0x0B2002B5ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B650ULL;
}

// FDE #1166 | PC: 0x06b65c..0x06b674 (24 B) | Symbol: sub_06b65c
// EN: AArch64 prologue [ldrb w8, [x21]; mov w9, #8; sub w9, w9, w2; mov x0, x20] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x21]; mov w9, #8; sub w9, w9, w2; mov x0, x20]
uint64_t fde_sub_06b65c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800109ULL) << 32) | 0x394002A8ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B65CULL;
}

// FDE #1167 | PC: 0x06b674..0x06b68c (24 B) | Symbol: sub_06b674
// EN: AArch64 prologue [add x16, x2, x11, lsl #2; ldp w17, w16, [x16]; sub w16, w16, w17; str w16, [x14, x11, lsl #2]] | VI: Khởi đầu hàm AArch64 [add x16, x2, x11, lsl #2; ldp w17, w16, [x16]; sub w16, w16, w17; str w16, [x14, x11, lsl #2]]
uint64_t fde_sub_06b674(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x29404211ULL) << 32) | 0x8B0B0850ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B674ULL;
}

// FDE #1168 | PC: 0x06b68c..0x06b69c (16 B) | Symbol: sub_06b68c
// EN: AArch64 prologue [add x8, x0, #0x280; cmp x0, #0; csel x0, xzr, x8, eq; ret] | VI: Khởi đầu hàm AArch64 [add x8, x0, #0x280; cmp x0, #0; csel x0, xzr, x8, eq; ret]
uint64_t fde_sub_06b68c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF100001FULL) << 32) | 0x910A0008ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B68CULL;
}

// FDE #1169 | PC: 0x06b69c..0x06b6a4 (8 B) | Symbol: sub_06b69c
// EN: AArch64 prologue [mov w2, #0x11c; b #0x1a948] | VI: Khởi đầu hàm AArch64 [mov w2, #0x11c; b #0x1a948]
uint64_t fde_sub_06b69c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBCAAULL) << 32) | 0x52802382ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B69CULL;
}

// FDE #1170 | PC: 0x06b6a4..0x06b6b4 (16 B) | Symbol: sub_06b6a4
// EN: AArch64 prologue [mov w0, w24; add x8, x20, x8, lsl #2; ldr w1, [x8, #0x18]; b #0x1b2c8] | VI: Khởi đầu hàm AArch64 [mov w0, w24; add x8, x20, x8, lsl #2; ldr w1, [x8, #0x18]; b #0x1b2c8]
uint64_t fde_sub_06b6a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8B080A88ULL) << 32) | 0x2A1803E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B6A4ULL;
}

// FDE #1171 | PC: 0x06b6b4..0x06b6cc (24 B) | Symbol: sub_06b6b4
// EN: AArch64 prologue [ldp w2, w3, [x25]; add w9, w19, #1; asr w19, w9, #1; neg w8, w8, asr #1] | VI: Khởi đầu hàm AArch64 [ldp w2, w3, [x25]; add w9, w19, #1; asr w19, w9, #1; neg w8, w8, asr #1]
uint64_t fde_sub_06b6b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x11000669ULL) << 32) | 0x29400F22ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B6B4ULL;
}

// FDE #1172 | PC: 0x06b6cc..0x06b6dc (16 B) | Symbol: sub_06b6cc
// EN: AArch64 prologue [mov w2, #0x6b0; mov x0, x23; mov x1, x22; b #0x1bc88] | VI: Khởi đầu hàm AArch64 [mov w2, #0x6b0; mov x0, x23; mov x1, x22; b #0x1bc88]
uint64_t fde_sub_06b6cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1703E0ULL) << 32) | 0x5280D602ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B6CCULL;
}

// FDE #1173 | PC: 0x06b6dc..0x06b6ec (16 B) | Symbol: sub_06b6dc
// EN: AArch64 prologue [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #2; ret] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #2; ret]
uint64_t fde_sub_06b6dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910783E1ULL) << 32) | 0x910243E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B6DCULL;
}

// FDE #1174 | PC: 0x06b6ec..0x06b704 (24 B) | Symbol: sub_06b6ec
// EN: AArch64 prologue [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #2; mov w4, #0x5a7f] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #2; mov w4, #0x5a7f]
uint64_t fde_sub_06b6ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910783E1ULL) << 32) | 0x910243E0ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B6ECULL;
}

// FDE #1175 | PC: 0x06b704..0x06b71c (24 B) | Symbol: sub_06b704
// EN: AArch64 prologue [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #2; mov w3, #3] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #2; mov w3, #3]
uint64_t fde_sub_06b704(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910783E1ULL) << 32) | 0x910243E0ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B704ULL;
}

// FDE #1176 | PC: 0x06b71c..0x06b734 (24 B) | Symbol: sub_06b71c
// EN: AArch64 prologue [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #1; mov w3, #3] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #1; mov w3, #3]
uint64_t fde_sub_06b71c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910783E1ULL) << 32) | 0x910243E0ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B71CULL;
}

// FDE #1177 | PC: 0x06b734..0x06b744 (16 B) | Symbol: sub_06b734
// EN: AArch64 prologue [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #4; ret] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #4; ret]
uint64_t fde_sub_06b734(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910783E1ULL) << 32) | 0x910243E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B734ULL;
}

// FDE #1178 | PC: 0x06b744..0x06b750 (12 B) | Symbol: sub_06b744
// EN: AArch64 prologue [lsr x8, x8, #0x20; add w8, w8, #4, lsl #12; ret] | VI: Khởi đầu hàm AArch64 [lsr x8, x8, #0x20; add w8, w8, #4, lsl #12; ret]
uint64_t fde_sub_06b744(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x11401108ULL) << 32) | 0xD360FD08ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B744ULL;
}

// FDE #1179 | PC: 0x06b750..0x06b760 (16 B) | Symbol: sub_06b750
// EN: AArch64 prologue [mov w9, #0x20; clz w8, w8; sub w1, w9, w8; ret] | VI: Khởi đầu hàm AArch64 [mov w9, #0x20; clz w8, w8; sub w1, w9, w8; ret]
uint64_t fde_sub_06b750(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5AC01108ULL) << 32) | 0x52800409ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B750ULL;
}

uint64_t DispatchFdeShard4(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x069f30ULL: return fde_sub_069f30(a0, a1, a2);
        case 0x069f4cULL: return fde_sub_069f4c(a0, a1, a2);
        case 0x069f68ULL: return fde_sub_069f68(a0, a1, a2);
        case 0x069f7cULL: return fde_sub_069f7c(a0, a1, a2);
        case 0x069f8cULL: return fde_sub_069f8c(a0, a1, a2);
        case 0x069fa8ULL: return fde_sub_069fa8(a0, a1, a2);
        case 0x069fbcULL: return fde_sub_069fbc(a0, a1, a2);
        case 0x069fd8ULL: return fde_sub_069fd8(a0, a1, a2);
        case 0x069fe8ULL: return fde_sub_069fe8(a0, a1, a2);
        case 0x069ff8ULL: return fde_sub_069ff8(a0, a1, a2);
        case 0x06a004ULL: return fde_sub_06a004(a0, a1, a2);
        case 0x06a020ULL: return fde_sub_06a020(a0, a1, a2);
        case 0x06a02cULL: return fde_sub_06a02c(a0, a1, a2);
        case 0x06a034ULL: return fde_sub_06a034(a0, a1, a2);
        case 0x06a03cULL: return fde_sub_06a03c(a0, a1, a2);
        case 0x06a044ULL: return fde_sub_06a044(a0, a1, a2);
        case 0x06a04cULL: return fde_sub_06a04c(a0, a1, a2);
        case 0x06a068ULL: return fde_sub_06a068(a0, a1, a2);
        case 0x06a074ULL: return fde_sub_06a074(a0, a1, a2);
        case 0x06a07cULL: return fde_sub_06a07c(a0, a1, a2);
        case 0x06a084ULL: return fde_sub_06a084(a0, a1, a2);
        case 0x06a0a0ULL: return fde_sub_06a0a0(a0, a1, a2);
        case 0x06a0a8ULL: return fde_sub_06a0a8(a0, a1, a2);
        case 0x06a0c4ULL: return fde_sub_06a0c4(a0, a1, a2);
        case 0x06a0d8ULL: return fde_sub_06a0d8(a0, a1, a2);
        case 0x06a0f4ULL: return fde_sub_06a0f4(a0, a1, a2);
        case 0x06a160ULL: return fde_sub_06a160(a0, a1, a2);
        case 0x06a17cULL: return fde_sub_06a17c(a0, a1, a2);
        case 0x06a1a4ULL: return fde_sub_06a1a4(a0, a1, a2);
        case 0x06a1dcULL: return fde_sub_06a1dc(a0, a1, a2);
        case 0x06a214ULL: return fde_sub_06a214(a0, a1, a2);
        case 0x06a21cULL: return fde_sub_06a21c(a0, a1, a2);
        case 0x06a250ULL: return fde_sub_06a250(a0, a1, a2);
        case 0x06a264ULL: return fde_sub_06a264(a0, a1, a2);
        case 0x06a27cULL: return fde_sub_06a27c(a0, a1, a2);
        case 0x06a284ULL: return fde_sub_06a284(a0, a1, a2);
        case 0x06a28cULL: return fde_sub_06a28c(a0, a1, a2);
        case 0x06a2a8ULL: return fde_sub_06a2a8(a0, a1, a2);
        case 0x06a2b8ULL: return fde_sub_06a2b8(a0, a1, a2);
        case 0x06a2c4ULL: return fde_sub_06a2c4(a0, a1, a2);
        case 0x06a31cULL: return fde_sub_06a31c(a0, a1, a2);
        case 0x06a33cULL: return fde_sub_06a33c(a0, a1, a2);
        case 0x06a348ULL: return fde_sub_06a348(a0, a1, a2);
        case 0x06a35cULL: return fde_sub_06a35c(a0, a1, a2);
        case 0x06a370ULL: return fde_sub_06a370(a0, a1, a2);
        case 0x06a378ULL: return fde_sub_06a378(a0, a1, a2);
        case 0x06a384ULL: return fde_sub_06a384(a0, a1, a2);
        case 0x06a38cULL: return fde_sub_06a38c(a0, a1, a2);
        case 0x06a3a4ULL: return fde_sub_06a3a4(a0, a1, a2);
        case 0x06a3acULL: return fde_sub_06a3ac(a0, a1, a2);
        case 0x06a3b4ULL: return fde_sub_06a3b4(a0, a1, a2);
        case 0x06a3d0ULL: return fde_sub_06a3d0(a0, a1, a2);
        case 0x06a3f0ULL: return fde_sub_06a3f0(a0, a1, a2);
        case 0x06a3fcULL: return fde_sub_06a3fc(a0, a1, a2);
        case 0x06a440ULL: return fde_sub_06a440(a0, a1, a2);
        case 0x06a44cULL: return fde_sub_06a44c(a0, a1, a2);
        case 0x06a454ULL: return fde_sub_06a454(a0, a1, a2);
        case 0x06a45cULL: return fde_sub_06a45c(a0, a1, a2);
        case 0x06a494ULL: return fde_sub_06a494(a0, a1, a2);
        case 0x06a4e4ULL: return fde_sub_06a4e4(a0, a1, a2);
        case 0x06a4ecULL: return fde_sub_06a4ec(a0, a1, a2);
        case 0x06a4f4ULL: return fde_sub_06a4f4(a0, a1, a2);
        case 0x06a534ULL: return fde_sub_06a534(a0, a1, a2);
        case 0x06a540ULL: return fde_sub_06a540(a0, a1, a2);
        case 0x06a564ULL: return fde_sub_06a564(a0, a1, a2);
        case 0x06a588ULL: return fde_sub_06a588(a0, a1, a2);
        case 0x06a5a4ULL: return fde_sub_06a5a4(a0, a1, a2);
        case 0x06a5c0ULL: return fde_sub_06a5c0(a0, a1, a2);
        case 0x06a5c8ULL: return fde_sub_06a5c8(a0, a1, a2);
        case 0x06a5e4ULL: return fde_sub_06a5e4(a0, a1, a2);
        case 0x06a5ecULL: return fde_sub_06a5ec(a0, a1, a2);
        case 0x06a5f4ULL: return fde_sub_06a5f4(a0, a1, a2);
        case 0x06a610ULL: return fde_sub_06a610(a0, a1, a2);
        case 0x06a618ULL: return fde_sub_06a618(a0, a1, a2);
        case 0x06a638ULL: return fde_sub_06a638(a0, a1, a2);
        case 0x06a640ULL: return fde_sub_06a640(a0, a1, a2);
        case 0x06a678ULL: return fde_sub_06a678(a0, a1, a2);
        case 0x06a680ULL: return fde_sub_06a680(a0, a1, a2);
        case 0x06a690ULL: return fde_sub_06a690(a0, a1, a2);
        case 0x06a6a8ULL: return fde_sub_06a6a8(a0, a1, a2);
        case 0x06a6bcULL: return fde_sub_06a6bc(a0, a1, a2);
        case 0x06a6ccULL: return fde_sub_06a6cc(a0, a1, a2);
        case 0x06a6dcULL: return fde_sub_06a6dc(a0, a1, a2);
        case 0x06a710ULL: return fde_sub_06a710(a0, a1, a2);
        case 0x06a744ULL: return fde_sub_06a744(a0, a1, a2);
        case 0x06a750ULL: return fde_sub_06a750(a0, a1, a2);
        case 0x06a75cULL: return fde_sub_06a75c(a0, a1, a2);
        case 0x06a7a0ULL: return fde_sub_06a7a0(a0, a1, a2);
        case 0x06a7acULL: return fde_sub_06a7ac(a0, a1, a2);
        case 0x06a7dcULL: return fde_sub_06a7dc(a0, a1, a2);
        case 0x06a7e8ULL: return fde_sub_06a7e8(a0, a1, a2);
        case 0x06a7f0ULL: return fde_sub_06a7f0(a0, a1, a2);
        case 0x06a818ULL: return fde_sub_06a818(a0, a1, a2);
        case 0x06a834ULL: return fde_sub_06a834(a0, a1, a2);
        case 0x06a864ULL: return fde_sub_06a864(a0, a1, a2);
        case 0x06a86cULL: return fde_sub_06a86c(a0, a1, a2);
        case 0x06a888ULL: return fde_sub_06a888(a0, a1, a2);
        case 0x06a894ULL: return fde_sub_06a894(a0, a1, a2);
        case 0x06a8b0ULL: return fde_sub_06a8b0(a0, a1, a2);
        case 0x06a8c0ULL: return fde_sub_06a8c0(a0, a1, a2);
        case 0x06a8dcULL: return fde_sub_06a8dc(a0, a1, a2);
        case 0x06a8ecULL: return fde_sub_06a8ec(a0, a1, a2);
        case 0x06a918ULL: return fde_sub_06a918(a0, a1, a2);
        case 0x06a92cULL: return fde_sub_06a92c(a0, a1, a2);
        case 0x06a940ULL: return fde_sub_06a940(a0, a1, a2);
        case 0x06a964ULL: return fde_sub_06a964(a0, a1, a2);
        case 0x06a988ULL: return fde_sub_06a988(a0, a1, a2);
        case 0x06a99cULL: return fde_sub_06a99c(a0, a1, a2);
        case 0x06a9b0ULL: return fde_sub_06a9b0(a0, a1, a2);
        case 0x06a9b8ULL: return fde_sub_06a9b8(a0, a1, a2);
        case 0x06a9ccULL: return fde_sub_06a9cc(a0, a1, a2);
        case 0x06a9d4ULL: return fde_sub_06a9d4(a0, a1, a2);
        case 0x06aa00ULL: return fde_sub_06aa00(a0, a1, a2);
        case 0x06aa08ULL: return fde_sub_06aa08(a0, a1, a2);
        case 0x06aa10ULL: return fde_sub_06aa10(a0, a1, a2);
        case 0x06aa18ULL: return fde_sub_06aa18(a0, a1, a2);
        case 0x06aa24ULL: return fde_sub_06aa24(a0, a1, a2);
        case 0x06aa2cULL: return fde_sub_06aa2c(a0, a1, a2);
        case 0x06aa34ULL: return fde_sub_06aa34(a0, a1, a2);
        case 0x06aa4cULL: return fde_sub_06aa4c(a0, a1, a2);
        case 0x06aa5cULL: return fde_sub_06aa5c(a0, a1, a2);
        case 0x06aa84ULL: return fde_sub_06aa84(a0, a1, a2);
        case 0x06aaacULL: return fde_sub_06aaac(a0, a1, a2);
        case 0x06aac4ULL: return fde_sub_06aac4(a0, a1, a2);
        case 0x06aafcULL: return fde_sub_06aafc(a0, a1, a2);
        case 0x06ab14ULL: return fde_sub_06ab14(a0, a1, a2);
        case 0x06ab30ULL: return fde_sub_06ab30(a0, a1, a2);
        case 0x06ab54ULL: return fde_sub_06ab54(a0, a1, a2);
        case 0x06ab70ULL: return fde_sub_06ab70(a0, a1, a2);
        case 0x06ab7cULL: return fde_sub_06ab7c(a0, a1, a2);
        case 0x06ab84ULL: return fde_sub_06ab84(a0, a1, a2);
        case 0x06ab8cULL: return fde_sub_06ab8c(a0, a1, a2);
        case 0x06aba8ULL: return fde_sub_06aba8(a0, a1, a2);
        case 0x06abbcULL: return fde_sub_06abbc(a0, a1, a2);
        case 0x06abc4ULL: return fde_sub_06abc4(a0, a1, a2);
        case 0x06abd0ULL: return fde_sub_06abd0(a0, a1, a2);
        case 0x06abf4ULL: return fde_sub_06abf4(a0, a1, a2);
        case 0x06ac04ULL: return fde_sub_06ac04(a0, a1, a2);
        case 0x06ac10ULL: return fde_sub_06ac10(a0, a1, a2);
        case 0x06ac1cULL: return fde_sub_06ac1c(a0, a1, a2);
        case 0x06ac38ULL: return fde_sub_06ac38(a0, a1, a2);
        case 0x06ac54ULL: return fde_sub_06ac54(a0, a1, a2);
        case 0x06ac60ULL: return fde_sub_06ac60(a0, a1, a2);
        case 0x06ac68ULL: return fde_sub_06ac68(a0, a1, a2);
        case 0x06ac74ULL: return fde_sub_06ac74(a0, a1, a2);
        case 0x06ac90ULL: return fde_sub_06ac90(a0, a1, a2);
        case 0x06aca4ULL: return fde_sub_06aca4(a0, a1, a2);
        case 0x06acb4ULL: return fde_sub_06acb4(a0, a1, a2);
        case 0x06acd8ULL: return fde_sub_06acd8(a0, a1, a2);
        case 0x06ace4ULL: return fde_sub_06ace4(a0, a1, a2);
        case 0x06ad00ULL: return fde_sub_06ad00(a0, a1, a2);
        case 0x06ad24ULL: return fde_sub_06ad24(a0, a1, a2);
        case 0x06ad48ULL: return fde_sub_06ad48(a0, a1, a2);
        case 0x06ad54ULL: return fde_sub_06ad54(a0, a1, a2);
        case 0x06ad64ULL: return fde_sub_06ad64(a0, a1, a2);
        case 0x06ad70ULL: return fde_sub_06ad70(a0, a1, a2);
        case 0x06ad78ULL: return fde_sub_06ad78(a0, a1, a2);
        case 0x06ad94ULL: return fde_sub_06ad94(a0, a1, a2);
        case 0x06ad9cULL: return fde_sub_06ad9c(a0, a1, a2);
        case 0x06adacULL: return fde_sub_06adac(a0, a1, a2);
        case 0x06adc4ULL: return fde_sub_06adc4(a0, a1, a2);
        case 0x06add8ULL: return fde_sub_06add8(a0, a1, a2);
        case 0x06adecULL: return fde_sub_06adec(a0, a1, a2);
        case 0x06ae00ULL: return fde_sub_06ae00(a0, a1, a2);
        case 0x06ae18ULL: return fde_sub_06ae18(a0, a1, a2);
        case 0x06ae20ULL: return fde_sub_06ae20(a0, a1, a2);
        case 0x06ae28ULL: return fde_sub_06ae28(a0, a1, a2);
        case 0x06ae40ULL: return fde_sub_06ae40(a0, a1, a2);
        case 0x06ae60ULL: return fde_sub_06ae60(a0, a1, a2);
        case 0x06ae80ULL: return fde_sub_06ae80(a0, a1, a2);
        case 0x06aeb0ULL: return fde_sub_06aeb0(a0, a1, a2);
        case 0x06aed0ULL: return fde_sub_06aed0(a0, a1, a2);
        case 0x06aedcULL: return fde_sub_06aedc(a0, a1, a2);
        case 0x06aef0ULL: return fde_sub_06aef0(a0, a1, a2);
        case 0x06aefcULL: return fde_sub_06aefc(a0, a1, a2);
        case 0x06af04ULL: return fde_sub_06af04(a0, a1, a2);
        case 0x06af10ULL: return fde_sub_06af10(a0, a1, a2);
        case 0x06af1cULL: return fde_sub_06af1c(a0, a1, a2);
        case 0x06af30ULL: return fde_sub_06af30(a0, a1, a2);
        case 0x06af38ULL: return fde_sub_06af38(a0, a1, a2);
        case 0x06af58ULL: return fde_sub_06af58(a0, a1, a2);
        case 0x06af60ULL: return fde_sub_06af60(a0, a1, a2);
        case 0x06af80ULL: return fde_sub_06af80(a0, a1, a2);
        case 0x06afa0ULL: return fde_sub_06afa0(a0, a1, a2);
        case 0x06afc0ULL: return fde_sub_06afc0(a0, a1, a2);
        case 0x06afd0ULL: return fde_sub_06afd0(a0, a1, a2);
        case 0x06afe4ULL: return fde_sub_06afe4(a0, a1, a2);
        case 0x06b004ULL: return fde_sub_06b004(a0, a1, a2);
        case 0x06b024ULL: return fde_sub_06b024(a0, a1, a2);
        case 0x06b034ULL: return fde_sub_06b034(a0, a1, a2);
        case 0x06b040ULL: return fde_sub_06b040(a0, a1, a2);
        case 0x06b050ULL: return fde_sub_06b050(a0, a1, a2);
        case 0x06b05cULL: return fde_sub_06b05c(a0, a1, a2);
        case 0x06b070ULL: return fde_sub_06b070(a0, a1, a2);
        case 0x06b090ULL: return fde_sub_06b090(a0, a1, a2);
        case 0x06b0a0ULL: return fde_sub_06b0a0(a0, a1, a2);
        case 0x06b0b0ULL: return fde_sub_06b0b0(a0, a1, a2);
        case 0x06b0c0ULL: return fde_sub_06b0c0(a0, a1, a2);
        case 0x06b0ccULL: return fde_sub_06b0cc(a0, a1, a2);
        case 0x06b0d4ULL: return fde_sub_06b0d4(a0, a1, a2);
        case 0x06b0e4ULL: return fde_sub_06b0e4(a0, a1, a2);
        case 0x06b0f0ULL: return fde_sub_06b0f0(a0, a1, a2);
        case 0x06b110ULL: return fde_sub_06b110(a0, a1, a2);
        case 0x06b120ULL: return fde_sub_06b120(a0, a1, a2);
        case 0x06b134ULL: return fde_sub_06b134(a0, a1, a2);
        case 0x06b140ULL: return fde_sub_06b140(a0, a1, a2);
        case 0x06b14cULL: return fde_sub_06b14c(a0, a1, a2);
        case 0x06b158ULL: return fde_sub_06b158(a0, a1, a2);
        case 0x06b184ULL: return fde_sub_06b184(a0, a1, a2);
        case 0x06b194ULL: return fde_sub_06b194(a0, a1, a2);
        case 0x06b1b0ULL: return fde_sub_06b1b0(a0, a1, a2);
        case 0x06b1ccULL: return fde_sub_06b1cc(a0, a1, a2);
        case 0x06b1e8ULL: return fde_sub_06b1e8(a0, a1, a2);
        case 0x06b204ULL: return fde_sub_06b204(a0, a1, a2);
        case 0x06b218ULL: return fde_sub_06b218(a0, a1, a2);
        case 0x06b22cULL: return fde_sub_06b22c(a0, a1, a2);
        case 0x06b238ULL: return fde_sub_06b238(a0, a1, a2);
        case 0x06b254ULL: return fde_sub_06b254(a0, a1, a2);
        case 0x06b270ULL: return fde_sub_06b270(a0, a1, a2);
        case 0x06b284ULL: return fde_sub_06b284(a0, a1, a2);
        case 0x06b28cULL: return fde_sub_06b28c(a0, a1, a2);
        case 0x06b294ULL: return fde_sub_06b294(a0, a1, a2);
        case 0x06b2a8ULL: return fde_sub_06b2a8(a0, a1, a2);
        case 0x06b2b4ULL: return fde_sub_06b2b4(a0, a1, a2);
        case 0x06b2bcULL: return fde_sub_06b2bc(a0, a1, a2);
        case 0x06b2c8ULL: return fde_sub_06b2c8(a0, a1, a2);
        case 0x06b2e4ULL: return fde_sub_06b2e4(a0, a1, a2);
        case 0x06b2f8ULL: return fde_sub_06b2f8(a0, a1, a2);
        case 0x06b304ULL: return fde_sub_06b304(a0, a1, a2);
        case 0x06b310ULL: return fde_sub_06b310(a0, a1, a2);
        case 0x06b31cULL: return fde_sub_06b31c(a0, a1, a2);
        case 0x06b330ULL: return fde_sub_06b330(a0, a1, a2);
        case 0x06b344ULL: return fde_sub_06b344(a0, a1, a2);
        case 0x06b358ULL: return fde_sub_06b358(a0, a1, a2);
        case 0x06b360ULL: return fde_sub_06b360(a0, a1, a2);
        case 0x06b37cULL: return fde_sub_06b37c(a0, a1, a2);
        case 0x06b398ULL: return fde_sub_06b398(a0, a1, a2);
        case 0x06b3a0ULL: return fde_sub_06b3a0(a0, a1, a2);
        case 0x06b3bcULL: return fde_sub_06b3bc(a0, a1, a2);
        case 0x06b3d8ULL: return fde_sub_06b3d8(a0, a1, a2);
        case 0x06b3e4ULL: return fde_sub_06b3e4(a0, a1, a2);
        case 0x06b400ULL: return fde_sub_06b400(a0, a1, a2);
        case 0x06b41cULL: return fde_sub_06b41c(a0, a1, a2);
        case 0x06b428ULL: return fde_sub_06b428(a0, a1, a2);
        case 0x06b434ULL: return fde_sub_06b434(a0, a1, a2);
        case 0x06b450ULL: return fde_sub_06b450(a0, a1, a2);
        case 0x06b46cULL: return fde_sub_06b46c(a0, a1, a2);
        case 0x06b474ULL: return fde_sub_06b474(a0, a1, a2);
        case 0x06b488ULL: return fde_sub_06b488(a0, a1, a2);
        case 0x06b490ULL: return fde_sub_06b490(a0, a1, a2);
        case 0x06b498ULL: return fde_sub_06b498(a0, a1, a2);
        case 0x06b4a4ULL: return fde_sub_06b4a4(a0, a1, a2);
        case 0x06b4acULL: return fde_sub_06b4ac(a0, a1, a2);
        case 0x06b4b8ULL: return fde_sub_06b4b8(a0, a1, a2);
        case 0x06b4c4ULL: return fde_sub_06b4c4(a0, a1, a2);
        case 0x06b4d0ULL: return fde_sub_06b4d0(a0, a1, a2);
        case 0x06b4dcULL: return fde_sub_06b4dc(a0, a1, a2);
        case 0x06b4e8ULL: return fde_sub_06b4e8(a0, a1, a2);
        case 0x06b504ULL: return fde_sub_06b504(a0, a1, a2);
        case 0x06b518ULL: return fde_sub_06b518(a0, a1, a2);
        case 0x06b520ULL: return fde_sub_06b520(a0, a1, a2);
        case 0x06b53cULL: return fde_sub_06b53c(a0, a1, a2);
        case 0x06b544ULL: return fde_sub_06b544(a0, a1, a2);
        case 0x06b550ULL: return fde_sub_06b550(a0, a1, a2);
        case 0x06b56cULL: return fde_sub_06b56c(a0, a1, a2);
        case 0x06b574ULL: return fde_sub_06b574(a0, a1, a2);
        case 0x06b580ULL: return fde_sub_06b580(a0, a1, a2);
        case 0x06b58cULL: return fde_sub_06b58c(a0, a1, a2);
        case 0x06b5a0ULL: return fde_sub_06b5a0(a0, a1, a2);
        case 0x06b5b4ULL: return fde_sub_06b5b4(a0, a1, a2);
        case 0x06b5c0ULL: return fde_sub_06b5c0(a0, a1, a2);
        case 0x06b5ccULL: return fde_sub_06b5cc(a0, a1, a2);
        case 0x06b5d8ULL: return fde_sub_06b5d8(a0, a1, a2);
        case 0x06b5e4ULL: return fde_sub_06b5e4(a0, a1, a2);
        case 0x06b5f8ULL: return fde_sub_06b5f8(a0, a1, a2);
        case 0x06b604ULL: return fde_sub_06b604(a0, a1, a2);
        case 0x06b618ULL: return fde_sub_06b618(a0, a1, a2);
        case 0x06b620ULL: return fde_sub_06b620(a0, a1, a2);
        case 0x06b630ULL: return fde_sub_06b630(a0, a1, a2);
        case 0x06b640ULL: return fde_sub_06b640(a0, a1, a2);
        case 0x06b650ULL: return fde_sub_06b650(a0, a1, a2);
        case 0x06b65cULL: return fde_sub_06b65c(a0, a1, a2);
        case 0x06b674ULL: return fde_sub_06b674(a0, a1, a2);
        case 0x06b68cULL: return fde_sub_06b68c(a0, a1, a2);
        case 0x06b69cULL: return fde_sub_06b69c(a0, a1, a2);
        case 0x06b6a4ULL: return fde_sub_06b6a4(a0, a1, a2);
        case 0x06b6b4ULL: return fde_sub_06b6b4(a0, a1, a2);
        case 0x06b6ccULL: return fde_sub_06b6cc(a0, a1, a2);
        case 0x06b6dcULL: return fde_sub_06b6dc(a0, a1, a2);
        case 0x06b6ecULL: return fde_sub_06b6ec(a0, a1, a2);
        case 0x06b704ULL: return fde_sub_06b704(a0, a1, a2);
        case 0x06b71cULL: return fde_sub_06b71c(a0, a1, a2);
        case 0x06b734ULL: return fde_sub_06b734(a0, a1, a2);
        case 0x06b744ULL: return fde_sub_06b744(a0, a1, a2);
        case 0x06b750ULL: return fde_sub_06b750(a0, a1, a2);
        default: return 0ULL;
    }
}

} // namespace fdk_aac
} // namespace opencut
