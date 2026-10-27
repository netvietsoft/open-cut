// ============================================================================
// File: animax_fde_shard_3.cpp
// Target 108 / 169: libanimax.so (657,720 bytes)
// EN: Clean-room C++17 AArch64 FDE Shard 3/5 covering FDEs [1586..2378]
//     (PC range 0x073f28 .. 0x08bb6c).
// VI: Phân mảnh FDE AArch64 C++17 3/5 bao phủ FDE [1586..2378]
//     (Dải địa chỉ PC 0x073f28 .. 0x08bb6c).
// ============================================================================
#include "animax_player_core.h"

namespace lynx {
namespace animax {

// FDE #1586 | PC: 0x073f28..0x073f3c (20 B) | Symbol: _ZN4lynx6animax12YUVFrameInfo12SetLineWidthEjj
// EN: AArch64 prologue [cmp w1, #2; b.hi #0x73f38; add x8, x0, w1, uxtw #2; str w2, [x8, #0x10]] | VI: Khởi đầu hàm AArch64 [cmp w1, #2; b.hi #0x73f38; add x8, x0, w1, uxtw #2; str w2, [x8, #0x10]]
uint64_t fde_sub_073f28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000068ULL) << 32) | 0x7100083FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073F28ULL;
}

// FDE #1587 | PC: 0x073f3c..0x073f44 (8 B) | Symbol: _ZN4lynx6animax12YUVFrameInfo8SetWidthEj
// EN: AArch64 prologue [str w1, [x0, #0x20]; ret] | VI: Khởi đầu hàm AArch64 [str w1, [x0, #0x20]; ret]
uint64_t fde_sub_073f3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9002001ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073F3CULL;
}

// FDE #1588 | PC: 0x073f44..0x073f4c (8 B) | Symbol: _ZN4lynx6animax12YUVFrameInfo9SetHeightEj
// EN: AArch64 prologue [str w1, [x0, #0x24]; ret] | VI: Khởi đầu hàm AArch64 [str w1, [x0, #0x24]; ret]
uint64_t fde_sub_073f44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9002401ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073F44ULL;
}

// FDE #1589 | PC: 0x073f4c..0x073f54 (8 B) | Symbol: _ZN4lynx6animax12YUVFrameInfo11SetBitDepthEj
// EN: AArch64 prologue [str w1, [x0, #0x28]; ret] | VI: Khởi đầu hàm AArch64 [str w1, [x0, #0x28]; ret]
uint64_t fde_sub_073f4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9002801ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073F4CULL;
}

// FDE #1590 | PC: 0x073f54..0x073f5c (8 B) | Symbol: _ZN4lynx6animax12YUVFrameInfo12SetYUVPixFmtENS0_9YUVPixFmtE
// EN: AArch64 prologue [str x1, [x0, #0x30]; ret] | VI: Khởi đầu hàm AArch64 [str x1, [x0, #0x30]; ret]
uint64_t fde_sub_073f54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF9001801ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073F54ULL;
}

// FDE #1591 | PC: 0x073f5c..0x073f78 (28 B) | Symbol: _ZNK4lynx6animax12YUVFrameInfo14GetChannelDataEj
// EN: AArch64 prologue [cmp w1, #2; b.ls #0x73f68; b #0x8e158; ldr x8, [x0, #0x38]] | VI: Khởi đầu hàm AArch64 [cmp w1, #2; b.ls #0x73f68; b #0x8e158; ldr x8, [x0, #0x38]]
uint64_t fde_sub_073f5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000049ULL) << 32) | 0x7100083FULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073F5CULL;
}

// FDE #1592 | PC: 0x073f78..0x073f90 (24 B) | Symbol: _ZNK4lynx6animax12YUVFrameInfo19GetChannelDataWidthEj
// EN: AArch64 prologue [cmp w1, #2; b.ls #0x73f84; b #0x8d6a0; add x8, x0, w1, uxtw #2] | VI: Khởi đầu hàm AArch64 [cmp w1, #2; b.ls #0x73f84; b #0x8d6a0; add x8, x0, w1, uxtw #2]
uint64_t fde_sub_073f78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000049ULL) << 32) | 0x7100083FULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073F78ULL;
}

// FDE #1593 | PC: 0x073f90..0x073fd0 (64 B) | Symbol: _ZNK4lynx6animax12YUVFrameInfo20GetChannelDataHeightEj
// EN: AArch64 prologue [cmp w1, #2; b.ls #0x73f9c; b #0x8d6a0; ldr s0, [x0, #0x24]] | VI: Khởi đầu hàm AArch64 [cmp w1, #2; b.ls #0x73f9c; b #0x8d6a0; ldr s0, [x0, #0x24]]
uint64_t fde_sub_073f90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000049ULL) << 32) | 0x7100083FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073F90ULL;
}

// FDE #1594 | PC: 0x073fd0..0x074000 (48 B) | Symbol: _ZNK4lynx6animax12YUVFrameInfo28GetVerticalSubsamplingFactorEj
// EN: AArch64 prologue [cmp w1, #2; fmov s0, wzr; b.hi #0x73ff4; cbz w1, #0x73ff8] | VI: Khởi đầu hàm AArch64 [cmp w1, #2; fmov s0, wzr; b.hi #0x73ff4; cbz w1, #0x73ff8]
uint64_t fde_sub_073fd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E2703E0ULL) << 32) | 0x7100083FULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073FD0ULL;
}

// FDE #1595 | PC: 0x074000..0x074230 (560 B) | Symbol: _ZN4lynx6animax12YUVFrameInfo17UpdateChannelDataEjPKh
// EN: AArch64 prologue [mov x3, x30; bl #0x8e8e8; mov x30, x3; stp x29, x30, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x8e8e8; mov x30, x3; stp x29, x30, [sp, #0x80]]
uint64_t fde_sub_074000(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94006A39ULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x0230ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074000ULL;
}

// FDE #1596 | PC: 0x074230..0x07426c (60 B) | Symbol: sub_074230
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; tbnz x1, #0x3f, #0x74268; ldr x8, [x0, #0x10]; ldr x9, [x0]] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; tbnz x1, #0x3f, #0x74268; ldr x8, [x0, #0x10]; ldr x9, [x0]]
uint64_t fde_sub_074230(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB7F801A1ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074230ULL;
}

// FDE #1597 | PC: 0x07426c..0x074294 (40 B) | Symbol: sub_07426c
// EN: AArch64 prologue [ldp x8, x9, [x0, #8]; cmp x8, x9; b.eq #0x74284; sub x9, x9, #1] | VI: Khởi đầu hàm AArch64 [ldp x8, x9, [x0, #8]; cmp x8, x9; b.eq #0x74284; sub x9, x9, #1]
uint64_t fde_sub_07426c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xA940A408ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07426CULL;
}

// FDE #1598 | PC: 0x074294..0x0746b8 (1060 B) | Symbol: _ZN4lynx6animax27RegisterVideoPlayerProviderEPKcNSt6__ndk110shared_ptrINS0_19VideoPlayerProviderEEE
// EN: AArch64 prologue [mov x2, x30; bl #0x91c18; mov x30, x2; stp x29, x30, [sp, #0x1b0]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x91c18; mov x30, x2; stp x29, x30, [sp, #0x1b0]]
uint64_t fde_sub_074294(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94007660ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0424ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074294ULL;
}

// FDE #1599 | PC: 0x0746b8..0x0747c4 (268 B) | Symbol: sub_0746b8
// EN: AArch64 prologue [mov x1, x30; bl #0x8d63c; mov x30, x1; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x1, x30; bl #0x8d63c; mov x30, x1; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_0746b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940063E0ULL) << 32) | 0xAA1E03E1ULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0746B8ULL;
}

// FDE #1600 | PC: 0x0747c4..0x0747dc (24 B) | Symbol: sub_0747c4
// EN: AArch64 prologue [adrp x9, #0xa0000; ldr x8, [x9, #0x958]; str x0, [x9, #0x958]; cbz x8, #0x747d8] | VI: Khởi đầu hàm AArch64 [adrp x9, #0xa0000; ldr x8, [x9, #0x958]; str x0, [x9, #0x958]; cbz x8, #0x747d8]
uint64_t fde_sub_0747c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF944AD28ULL) << 32) | 0x90000169ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0747C4ULL;
}

// FDE #1601 | PC: 0x0747dc..0x0747f4 (24 B) | Symbol: sub_0747dc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x920fc; bl #0x71874; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x920fc; bl #0x71874; mov x0, x19]
uint64_t fde_sub_0747dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94007647ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0747DCULL;
}

// FDE #1602 | PC: 0x0747f4..0x074864 (112 B) | Symbol: _ZN4lynx6animax9FontAsset7GetFontEv
// EN: AArch64 prologue [sub sp, sp, #0x30; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x0]
uint64_t fde_sub_0747f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0747F4ULL;
}

// FDE #1603 | PC: 0x074864..0x0748a0 (60 B) | Symbol: sub_074864
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; mov x19, x0]
uint64_t fde_sub_074864(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074864ULL;
}

// FDE #1604 | PC: 0x0748a0..0x0748b8 (24 B) | Symbol: sub_0748a0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x74864; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x74864; mov x0, x19]
uint64_t fde_sub_0748a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0748A0ULL;
}

// FDE #1605 | PC: 0x0748b8..0x0748c4 (12 B) | Symbol: sub_0748b8
// EN: AArch64 prologue [ldr x8, [x1]; ldr x2, [x8, #0x18]; b #0x8fa58] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1]; ldr x2, [x8, #0x18]; b #0x8fa58]
uint64_t fde_sub_0748b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400D02ULL) << 32) | 0xF9400028ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0748B8ULL;
}

// FDE #1606 | PC: 0x0748c4..0x074940 (124 B) | Symbol: sub_0748c4
// EN: AArch64 prologue [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]]
uint64_t fde_sub_0748c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9009BFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0748C4ULL;
}

// FDE #1607 | PC: 0x074940..0x07494c (12 B) | Symbol: sub_074940
// EN: AArch64 prologue [ldr x8, [x1]; ldr x2, [x8, #0x20]; b #0x8fa58] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1]; ldr x2, [x8, #0x20]; b #0x8fa58]
uint64_t fde_sub_074940(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401102ULL) << 32) | 0xF9400028ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074940ULL;
}

// FDE #1608 | PC: 0x07494c..0x074950 (4 B) | Symbol: sub_07494c
// EN: AArch64 prologue [b #0x90754] | VI: Khởi đầu hàm AArch64 [b #0x90754]
uint64_t fde_sub_07494c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB00003FULL) << 32) | 0x14006F82ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07494CULL;
}

// FDE #1609 | PC: 0x074950..0x074968 (24 B) | Symbol: sub_074950
// EN: AArch64 prologue [cmp x1, x0; b.eq #0x74964; ldr w8, [x0], #4; cbz w8, #0x74950] | VI: Khởi đầu hàm AArch64 [cmp x1, x0; b.eq #0x74964; ldr w8, [x0], #4; cbz w8, #0x74950]
uint64_t fde_sub_074950(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000080ULL) << 32) | 0xEB00003FULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074950ULL;
}

// FDE #1610 | PC: 0x074968..0x07497c (20 B) | Symbol: _ZN4lynx6animax6BitmapC2EjjPKvPFvS3_ES3_NS0_12BitmapFormatENS0_15BitmapAlphaTypeE
// EN: AArch64 prologue [stp w1, w2, [x0]; stp x3, x4, [x0, #8]; str x5, [x0, #0x18]; stp w6, w7, [x0, #0x20]] | VI: Khởi đầu hàm AArch64 [stp w1, w2, [x0]; stp x3, x4, [x0, #8]; str x5, [x0, #0x18]; stp w6, w7, [x0, #0x20]]
uint64_t fde_sub_074968(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9009003ULL) << 32) | 0x29000801ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074968ULL;
}

// FDE #1611 | PC: 0x07497c..0x074990 (20 B) | Symbol: _ZN4lynx6animax7RawDataD1Ev
// EN: AArch64 prologue [ldr x1, [x0, #0x10]; cbz x1, #0x7498c; ldr x0, [x0, #0x18]; br x1] | VI: Khởi đầu hàm AArch64 [ldr x1, [x0, #0x10]; cbz x1, #0x7498c; ldr x0, [x0, #0x18]; br x1]
uint64_t fde_sub_07497c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000061ULL) << 32) | 0xF9400801ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07497CULL;
}

// FDE #1612 | PC: 0x074990..0x0749e4 (84 B) | Symbol: _ZN4lynx6animax6Bitmap8MakeRGBAEjjPKvPFvS3_ES3_
// EN: AArch64 prologue [str x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_074990(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xF81C0FF8ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074990ULL;
}

// FDE #1613 | PC: 0x0749e4..0x074a48 (100 B) | Symbol: _ZN4lynx6animax6Bitmap4MakeEjjPKvPFvS3_ES3_NS0_12BitmapFormatENS0_15BitmapAlphaTypeE
// EN: AArch64 prologue [mov x7, x30; bl #0x8fc50; mov x30, x7; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x7, x30; bl #0x8fc50; mov x30, x7; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_0749e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94006C9AULL) << 32) | 0xAA1E03E7ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0749E4ULL;
}

// FDE #1614 | PC: 0x074a48..0x074a50 (8 B) | Symbol: _ZNK4lynx6animax6Bitmap5WidthEv
// EN: AArch64 prologue [ldr w0, [x0]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0]; ret]
uint64_t fde_sub_074a48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9400000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074A48ULL;
}

// FDE #1615 | PC: 0x074a50..0x074a58 (8 B) | Symbol: _ZNK4lynx6animax6Bitmap6HeightEv
// EN: AArch64 prologue [ldr w0, [x0, #4]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #4]; ret]
uint64_t fde_sub_074a50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9400400ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074A50ULL;
}

// FDE #1616 | PC: 0x074a58..0x074a60 (8 B) | Symbol: _ZNK4lynx6animax6Bitmap6PixelsEv
// EN: AArch64 prologue [ldr x0, [x0, #8]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #8]; ret]
uint64_t fde_sub_074a58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF9400400ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074A58ULL;
}

// FDE #1617 | PC: 0x074a60..0x074a80 (32 B) | Symbol: _ZNK4lynx6animax6Bitmap12PixelsLengthEv
// EN: AArch64 prologue [ldp w8, w9, [x0]; ldr w10, [x0, #0x20]; mul w8, w9, w8; cmp w10, #2] | VI: Khởi đầu hàm AArch64 [ldp w8, w9, [x0]; ldr w10, [x0, #0x20]; mul w8, w9, w8; cmp w10, #2]
uint64_t fde_sub_074a60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB940200AULL) << 32) | 0x29402408ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074A60ULL;
}

// FDE #1618 | PC: 0x074a80..0x074a94 (20 B) | Symbol: _ZNK4lynx6animax6Bitmap13BytesPerPixelEv
// EN: AArch64 prologue [ldr w8, [x0, #0x20]; mov w9, #4; cmp w8, #2; csel w0, w8, w9, eq] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #0x20]; mov w9, #4; cmp w8, #2; csel w0, w8, w9, eq]
uint64_t fde_sub_074a80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800089ULL) << 32) | 0xB9402008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074A80ULL;
}

// FDE #1619 | PC: 0x074a94..0x074ab0 (28 B) | Symbol: _ZNK4lynx6animax6Bitmap11BytesPerRowEv
// EN: AArch64 prologue [ldr w8, [x0, #0x20]; ldr w9, [x0]; mov w10, #4; cmp w8, #2] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #0x20]; ldr w9, [x0]; mov w10, #4; cmp w8, #2]
uint64_t fde_sub_074a94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9400009ULL) << 32) | 0xB9402008ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074A94ULL;
}

// FDE #1620 | PC: 0x074ab0..0x074b04 (84 B) | Symbol: sub_074ab0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0xa0000; add x8, x8, #0x160; ldarb w8, [x8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0xa0000; add x8, x8, #0x160; ldarb w8, [x8]]
uint64_t fde_sub_074ab0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000168ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074AB0ULL;
}

// FDE #1621 | PC: 0x074b04..0x074b1c (24 B) | Symbol: sub_074b04
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x9b000; add x9, x9, #0xd10; str x9, [x0]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x9b000; add x9, x9, #0xd10; str x9, [x0]]
uint64_t fde_sub_074b04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000129ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074B04ULL;
}

// FDE #1622 | PC: 0x074b1c..0x074b34 (24 B) | Symbol: sub_074b1c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x74b04; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x74b04; mov x0, x19]
uint64_t fde_sub_074b1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074B1CULL;
}

// FDE #1623 | PC: 0x074b34..0x074b64 (48 B) | Symbol: sub_074b34
// EN: AArch64 prologue [cbz x0, #0x74b60; stp x19, x30, [sp, #-0x10]!; bl #0x930c8; bl #0x74b34] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x74b60; stp x19, x30, [sp, #-0x10]!; bl #0x930c8; bl #0x74b34]
uint64_t fde_sub_074b34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BF3ULL) << 32) | 0xB4000160ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074B34ULL;
}

// FDE #1624 | PC: 0x074b64..0x074bf8 (148 B) | Symbol: sub_074b64
// EN: AArch64 prologue [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; adrp x22, #0xa0000] | VI: Khởi đầu hàm AArch64 [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; adrp x22, #0xa0000]
uint64_t fde_sub_074b64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xA9BD5BF7ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074B64ULL;
}

// FDE #1625 | PC: 0x074bf8..0x074c30 (56 B) | Symbol: sub_074bf8
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x19, x30, [sp, #0x20]; bl #0x915a8; stp xzr, xzr, [x1]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x19, x30, [sp, #0x20]; bl #0x915a8; stp xzr, xzr, [x1]]
uint64_t fde_sub_074bf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9027BF3ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074BF8ULL;
}

// FDE #1626 | PC: 0x074c30..0x074ca4 (116 B) | Symbol: sub_074c30
// EN: AArch64 prologue [sub sp, sp, #0x60; str d8, [sp, #0x30]; str x22, [sp, #0x38]; stp x21, x20, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str d8, [sp, #0x30]; str x22, [sp, #0x38]; stp x21, x20, [sp, #0x40]]
uint64_t fde_sub_074c30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD001BE8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074C30ULL;
}

// FDE #1627 | PC: 0x074ca4..0x074cb8 (20 B) | Symbol: sub_074ca4
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8ea58; ldp x19, x30, [sp, #0x10]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8ea58; ldp x19, x30, [sp, #0x10]]
uint64_t fde_sub_074ca4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074CA4ULL;
}

// FDE #1628 | PC: 0x074cb8..0x074cd0 (24 B) | Symbol: sub_074cb8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x74cd0; ldr x0, [x19, #8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x74cd0; ldr x0, [x19, #8]]
uint64_t fde_sub_074cb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94006398ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074CB8ULL;
}

// FDE #1629 | PC: 0x074cd0..0x074cec (28 B) | Symbol: sub_074cd0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8ddf8; cbz x0, #0x74ce0; bl #0x8d3c4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8ddf8; cbz x0, #0x74ce0; bl #0x8d3c4]
uint64_t fde_sub_074cd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94006449ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074CD0ULL;
}

// FDE #1630 | PC: 0x074cec..0x074cfc (16 B) | Symbol: sub_074cec
// EN: AArch64 prologue [adrp x8, #0x9b000; add x8, x8, #0xd30; str x8, [x0], #8; b #0x74cb8] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9b000; add x8, x8, #0xd30; str x8, [x0], #8; b #0x74cb8]
uint64_t fde_sub_074cec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9134C108ULL) << 32) | 0xF0000128ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074CECULL;
}

// FDE #1631 | PC: 0x074cfc..0x074d14 (24 B) | Symbol: sub_074cfc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x74cec; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x74cec; mov x0, x19]
uint64_t fde_sub_074cfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074CFCULL;
}

// FDE #1632 | PC: 0x074d14..0x074d24 (16 B) | Symbol: sub_074d14
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x74c30] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x74c30]
uint64_t fde_sub_074d14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400624FULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074D14ULL;
}

// FDE #1633 | PC: 0x074d24..0x074d44 (32 B) | Symbol: sub_074d24
// EN: AArch64 prologue [mov x8, x0; ldr x0, [x0, #8]; adrp x9, #0x9b000; add x9, x9, #0xd58] | VI: Khởi đầu hàm AArch64 [mov x8, x0; ldr x0, [x0, #8]; adrp x9, #0x9b000; add x9, x9, #0xd58]
uint64_t fde_sub_074d24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400400ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074D24ULL;
}

// FDE #1634 | PC: 0x074d44..0x074d5c (24 B) | Symbol: sub_074d44
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x74d24; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x74d24; mov x0, x19]
uint64_t fde_sub_074d44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074D44ULL;
}

// FDE #1635 | PC: 0x074d5c..0x074dfc (160 B) | Symbol: sub_074d5c
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x23, x22, [sp, #0x60]; stp x21, x20, [sp, #0x70]; stp x19, x30, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x23, x22, [sp, #0x60]; stp x21, x20, [sp, #0x70]; stp x19, x30, [sp, #0x80]]
uint64_t fde_sub_074d5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9065BF7ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074D5CULL;
}

// FDE #1636 | PC: 0x074dfc..0x074e70 (116 B) | Symbol: sub_074dfc
// EN: AArch64 prologue [sub sp, sp, #0x60; str d8, [sp, #0x30]; str x22, [sp, #0x38]; stp x21, x20, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str d8, [sp, #0x30]; str x22, [sp, #0x38]; stp x21, x20, [sp, #0x40]]
uint64_t fde_sub_074dfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD001BE8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074DFCULL;
}

// FDE #1637 | PC: 0x074e70..0x074e80 (16 B) | Symbol: sub_074e70
// EN: AArch64 prologue [adrp x8, #0x9b000; add x8, x8, #0xd80; str x8, [x0], #8; b #0x74cb8] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9b000; add x8, x8, #0xd80; str x8, [x0], #8; b #0x74cb8]
uint64_t fde_sub_074e70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91360108ULL) << 32) | 0xF0000128ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074E70ULL;
}

// FDE #1638 | PC: 0x074e80..0x074e98 (24 B) | Symbol: sub_074e80
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x74e70; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x74e70; mov x0, x19]
uint64_t fde_sub_074e80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074E80ULL;
}

// FDE #1639 | PC: 0x074e98..0x074ea8 (16 B) | Symbol: sub_074e98
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x74dfc] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x74dfc]
uint64_t fde_sub_074e98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940061EEULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074E98ULL;
}

// FDE #1640 | PC: 0x074ea8..0x075038 (400 B) | Symbol: sub_074ea8
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x25, x24, [sp, #0x50]; stp x23, x22, [sp, #0x60]; stp x21, x20, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x25, x24, [sp, #0x50]; stp x23, x22, [sp, #0x60]; stp x21, x20, [sp, #0x70]]
uint64_t fde_sub_074ea8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90563F9ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0190ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074EA8ULL;
}

// FDE #1641 | PC: 0x075038..0x075064 (44 B) | Symbol: sub_075038
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8f7e0; cbz x8, #0x75050; add x10, x8, #0x10] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8f7e0; cbz x8, #0x75050; add x10, x8, #0x10]
uint64_t fde_sub_075038(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940069E9ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075038ULL;
}

// FDE #1642 | PC: 0x075064..0x07507c (24 B) | Symbol: sub_075064
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8ee48; bl #0x48d40; ldr x0, [x19, #8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8ee48; bl #0x48d40; ldr x0, [x19, #8]]
uint64_t fde_sub_075064(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94006778ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075064ULL;
}

// FDE #1643 | PC: 0x07507c..0x075098 (28 B) | Symbol: sub_07507c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8ddf8; adrp x8, #0x9b000; add x8, x8, #0xdf8] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8ddf8; adrp x8, #0x9b000; add x8, x8, #0xdf8]
uint64_t fde_sub_07507c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400635EULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07507CULL;
}

// FDE #1644 | PC: 0x075098..0x0750b0 (24 B) | Symbol: sub_075098
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7507c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7507c; mov x0, x19]
uint64_t fde_sub_075098(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075098ULL;
}

// FDE #1645 | PC: 0x0750b0..0x075440 (912 B) | Symbol: sub_0750b0
// EN: AArch64 prologue [sub sp, sp, #0x190; stp x28, x27, [sp, #0x130]; stp x26, x25, [sp, #0x140]; stp x24, x23, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x190; stp x28, x27, [sp, #0x130]; stp x26, x25, [sp, #0x140]; stp x24, x23, [sp, #0x150]]
uint64_t fde_sub_0750b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9136FFCULL) << 32) | 0xD10643FFULL;
    const uint64_t kPcRange = 0x0390ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0750B0ULL;
}

// FDE #1646 | PC: 0x075440..0x0754ac (108 B) | Symbol: sub_075440
// EN: AArch64 prologue [sub sp, sp, #0x90; str x22, [sp, #0x60]; stp x21, x20, [sp, #0x70]; stp x19, x30, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x22, [sp, #0x60]; stp x21, x20, [sp, #0x70]; stp x19, x30, [sp, #0x80]]
uint64_t fde_sub_075440(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90033F6ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075440ULL;
}

// FDE #1647 | PC: 0x0754ac..0x0754f4 (72 B) | Symbol: sub_0754ac
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; ldr x1, [x20, #0x18]!] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; ldr x1, [x20, #0x18]!]
uint64_t fde_sub_0754ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0754ACULL;
}

// FDE #1648 | PC: 0x0754f4..0x075540 (76 B) | Symbol: sub_0754f4
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8efd8; bl #0x7579c] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8efd8; bl #0x7579c]
uint64_t fde_sub_0754f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0754F4ULL;
}

// FDE #1649 | PC: 0x075540..0x07555c (28 B) | Symbol: sub_075540
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x930e8; add x0, x19, #0x30; bl #0x46c54] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x930e8; add x0, x19, #0x30; bl #0x46c54]
uint64_t fde_sub_075540(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940076E9ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075540ULL;
}

// FDE #1650 | PC: 0x07555c..0x075574 (24 B) | Symbol: sub_07555c
// EN: AArch64 prologue [ldr x8, [x0, #0x18]; adrp x9, #0x9b000; add x9, x9, #0xe20; str x9, [x0]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x18]; adrp x9, #0x9b000; add x9, x9, #0xe20; str x9, [x0]]
uint64_t fde_sub_07555c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000129ULL) << 32) | 0xF9400C08ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07555CULL;
}

// FDE #1651 | PC: 0x075574..0x07558c (24 B) | Symbol: sub_075574
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7555c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7555c; mov x0, x19]
uint64_t fde_sub_075574(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075574ULL;
}

// FDE #1652 | PC: 0x07558c..0x07568c (256 B) | Symbol: sub_07558c
// EN: AArch64 prologue [sub sp, sp, #0x130; str x28, [sp, #0xf0]; stp x23, x22, [sp, #0x100]; stp x21, x20, [sp, #0x110]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x130; str x28, [sp, #0xf0]; stp x23, x22, [sp, #0x100]; stp x21, x20, [sp, #0x110]]
uint64_t fde_sub_07558c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9007BFCULL) << 32) | 0xD104C3FFULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07558CULL;
}

// FDE #1653 | PC: 0x07568c..0x0756c8 (60 B) | Symbol: sub_07568c
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr w8, [x1]; mov x20, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr w8, [x1]; mov x20, x0]
uint64_t fde_sub_07568c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07568CULL;
}

// FDE #1654 | PC: 0x0756c8..0x0756e8 (32 B) | Symbol: sub_0756c8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x930dc; bl #0x7186c; add x0, x19, #0x20] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x930dc; bl #0x7186c; add x0, x19, #0x20]
uint64_t fde_sub_0756c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94007684ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0756C8ULL;
}

// FDE #1655 | PC: 0x0756e8..0x075708 (32 B) | Symbol: sub_0756e8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; ldr w8, [x1], #8; mov x19, x0; str w8, [x0], #8] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; ldr w8, [x1], #8; mov x19, x0; str w8, [x0], #8]
uint64_t fde_sub_0756e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB8408428ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0756E8ULL;
}

// FDE #1656 | PC: 0x075708..0x075748 (64 B) | Symbol: sub_075708
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x1] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x1]
uint64_t fde_sub_075708(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075708ULL;
}

// FDE #1657 | PC: 0x075748..0x07579c (84 B) | Symbol: sub_075748
// EN: AArch64 prologue [stp xzr, xzr, [x0]; str xzr, [x0, #0x10]; ldr x8, [x1]; str x8, [x0]] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x0]; str xzr, [x0, #0x10]; ldr x8, [x1]; str x8, [x0]]
uint64_t fde_sub_075748(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900081FULL) << 32) | 0xA9007C1FULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075748ULL;
}

// FDE #1658 | PC: 0x07579c..0x0757a8 (12 B) | Symbol: sub_07579c
// EN: AArch64 prologue [ldr x8, [x1]; str x8, [x0]; b #0x8f620] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1]; str x8, [x0]; b #0x8f620]
uint64_t fde_sub_07579c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000008ULL) << 32) | 0xF9400028ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07579CULL;
}

// FDE #1659 | PC: 0x0757a8..0x0757d4 (44 B) | Symbol: sub_0757a8
// EN: AArch64 prologue [cbz x0, #0x757d0; stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x754ac] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x757d0; stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x754ac]
uint64_t fde_sub_0757a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BF3ULL) << 32) | 0xB4000140ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0757A8ULL;
}

// FDE #1660 | PC: 0x0757d4..0x0757dc (8 B) | Symbol: sub_0757d4
// EN: AArch64 prologue [ldr x0, [x0, #0x18]; b #0x757a8] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x18]; b #0x757a8]
uint64_t fde_sub_0757d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF4ULL) << 32) | 0xF9400C00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0757D4ULL;
}

// FDE #1661 | PC: 0x0757dc..0x075810 (52 B) | Symbol: sub_0757dc
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x21, [x0, #8]; bl #0x8e454] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x21, [x0, #8]; bl #0x8e454]
uint64_t fde_sub_0757dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0757DCULL;
}

// FDE #1662 | PC: 0x075810..0x075844 (52 B) | Symbol: sub_075810
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x21, [x0, #8]; bl #0x8e454] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x21, [x0, #8]; bl #0x8e454]
uint64_t fde_sub_075810(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075810ULL;
}

// FDE #1663 | PC: 0x075844..0x075864 (32 B) | Symbol: sub_075844
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov w8, #3; mov x19, x0; str w8, [x0], #8] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov w8, #3; mov x19, x0; str w8, [x0], #8]
uint64_t fde_sub_075844(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800068ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075844ULL;
}

// FDE #1664 | PC: 0x075864..0x075884 (32 B) | Symbol: sub_075864
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9b000; add x8, x8, #0xdd0; bl #0x8daa4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9b000; add x8, x8, #0xdd0; bl #0x8daa4]
uint64_t fde_sub_075864(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000128ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075864ULL;
}

// FDE #1665 | PC: 0x075884..0x07589c (24 B) | Symbol: sub_075884
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x75864; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x75864; mov x0, x19]
uint64_t fde_sub_075884(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075884ULL;
}

// FDE #1666 | PC: 0x07589c..0x075a54 (440 B) | Symbol: sub_07589c
// EN: AArch64 prologue [sub sp, sp, #0x1a0; str x28, [sp, #0x150]; stp x25, x24, [sp, #0x160]; stp x23, x22, [sp, #0x170]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1a0; str x28, [sp, #0x150]; stp x25, x24, [sp, #0x160]; stp x23, x22, [sp, #0x170]]
uint64_t fde_sub_07589c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900ABFCULL) << 32) | 0xD10683FFULL;
    const uint64_t kPcRange = 0x01B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07589CULL;
}

// FDE #1667 | PC: 0x075a54..0x075a7c (40 B) | Symbol: sub_075a54
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x90cb4; cbz x0, #0x75a64; bl #0x8d3c4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x90cb4; cbz x0, #0x75a64; bl #0x8d3c4]
uint64_t fde_sub_075a54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94006C97ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075A54ULL;
}

// FDE #1668 | PC: 0x075a7c..0x075a8c (16 B) | Symbol: sub_075a7c
// EN: AArch64 prologue [adrp x8, #0x9b000; add x8, x8, #0xe80; str x8, [x0], #8; b #0x75a54] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9b000; add x8, x8, #0xe80; str x8, [x0], #8; b #0x75a54]
uint64_t fde_sub_075a7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x913A0108ULL) << 32) | 0xD0000128ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075A7CULL;
}

// FDE #1669 | PC: 0x075a8c..0x075aa4 (24 B) | Symbol: sub_075a8c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x75a7c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x75a7c; mov x0, x19]
uint64_t fde_sub_075a8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075A8CULL;
}

// FDE #1670 | PC: 0x075aa4..0x075b88 (228 B) | Symbol: sub_075aa4
// EN: AArch64 prologue [sub sp, sp, #0x110; stp x28, x22, [sp, #0xe0]; stp x21, x20, [sp, #0xf0]; stp x19, x30, [sp, #0x100]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; stp x28, x22, [sp, #0xe0]; stp x21, x20, [sp, #0xf0]; stp x19, x30, [sp, #0x100]]
uint64_t fde_sub_075aa4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90E5BFCULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075AA4ULL;
}

// FDE #1671 | PC: 0x075b88..0x075bf0 (104 B) | Symbol: sub_075b88
// EN: AArch64 prologue [sub sp, sp, #0x90; str x22, [sp, #0x60]; stp x21, x20, [sp, #0x70]; stp x19, x30, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x22, [sp, #0x60]; stp x21, x20, [sp, #0x70]; stp x19, x30, [sp, #0x80]]
uint64_t fde_sub_075b88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90033F6ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075B88ULL;
}

// FDE #1672 | PC: 0x075bf0..0x075bfc (12 B) | Symbol: sub_075bf0
// EN: AArch64 prologue [ldr x8, [x1], #8; str x8, [x0], #8; b #0x47f90] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1], #8; str x8, [x0], #8; b #0x47f90]
uint64_t fde_sub_075bf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF8008408ULL) << 32) | 0xF8408428ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075BF0ULL;
}

// FDE #1673 | PC: 0x075bfc..0x075c24 (40 B) | Symbol: sub_075bfc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8eb7c; adrp x8, #0x9b000; add x8, x8, #0xda8] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8eb7c; adrp x8, #0x9b000; add x8, x8, #0xda8]
uint64_t fde_sub_075bfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940063DFULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075BFCULL;
}

// FDE #1674 | PC: 0x075c24..0x075c3c (24 B) | Symbol: sub_075c24
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x75bfc; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x75bfc; mov x0, x19]
uint64_t fde_sub_075c24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075C24ULL;
}

// FDE #1675 | PC: 0x075c3c..0x07620c (1488 B) | Symbol: sub_075c3c
// EN: AArch64 prologue [mov x3, x30; bl #0x8d63c; mov x30, x3; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x8d63c; mov x30, x3; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_075c3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94005E7FULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x05D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x075C3CULL;
}

// FDE #1676 | PC: 0x07620c..0x076298 (140 B) | Symbol: sub_07620c
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_07620c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9035BF7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07620CULL;
}

// FDE #1677 | PC: 0x076298..0x0762d4 (60 B) | Symbol: sub_076298
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; ldr w8, [x0]; cmp w8, #4; b.eq #0x762b4] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; ldr w8, [x0]; cmp w8, #4; b.eq #0x762b4]
uint64_t fde_sub_076298(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9400008ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x076298ULL;
}

// FDE #1678 | PC: 0x0762d4..0x076344 (112 B) | Symbol: sub_0762d4
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]; bl #0x902ec] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]; bl #0x902ec]
uint64_t fde_sub_0762d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90553F5ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0762D4ULL;
}

// FDE #1679 | PC: 0x076344..0x076374 (48 B) | Symbol: sub_076344
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x930e8; ldr x0, [x19, #0x40]; bl #0x48d40] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x930e8; ldr x0, [x19, #0x40]; bl #0x48d40]
uint64_t fde_sub_076344(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94007368ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x076344ULL;
}

// FDE #1680 | PC: 0x076374..0x0763b4 (64 B) | Symbol: sub_076374
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x21, [x0]; cbz x21, #0x763ac] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x21, [x0]; cbz x21, #0x763ac]
uint64_t fde_sub_076374(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x076374ULL;
}

// FDE #1681 | PC: 0x0763b4..0x0763c4 (16 B) | Symbol: sub_0763b4
// EN: AArch64 prologue [adrp x8, #0x9b000; add x8, x8, #0xea8; str x8, [x0], #0x10; b #0x75540] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9b000; add x8, x8, #0xea8; str x8, [x0], #0x10; b #0x75540]
uint64_t fde_sub_0763b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x913AA108ULL) << 32) | 0xB0000128ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0763B4ULL;
}

// FDE #1682 | PC: 0x0763c4..0x0763d4 (16 B) | Symbol: sub_0763c4
// EN: AArch64 prologue [adrp x8, #0x9b000; add x8, x8, #0xee0; str x8, [x0], #8; b #0x76344] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9b000; add x8, x8, #0xee0; str x8, [x0], #8; b #0x76344]
uint64_t fde_sub_0763c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x913B8108ULL) << 32) | 0xB0000128ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0763C4ULL;
}

// FDE #1683 | PC: 0x0763d4..0x0763ec (24 B) | Symbol: sub_0763d4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x763c4; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x763c4; mov x0, x19]
uint64_t fde_sub_0763d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0763D4ULL;
}

// FDE #1684 | PC: 0x0763ec..0x07673c (848 B) | Symbol: sub_0763ec
// EN: AArch64 prologue [mov x3, x30; bl #0x8d63c; mov x30, x3; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x8d63c; mov x30, x3; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_0763ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94005C93ULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x0350ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0763ECULL;
}

// FDE #1685 | PC: 0x07673c..0x07676c (48 B) | Symbol: sub_07673c
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr w8, [x1]; mov x20, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr w8, [x1]; mov x20, x0]
uint64_t fde_sub_07673c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07673CULL;
}

// FDE #1686 | PC: 0x07676c..0x0767a4 (56 B) | Symbol: sub_07676c
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; mov x19, x0]
uint64_t fde_sub_07676c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07676CULL;
}

// FDE #1687 | PC: 0x0767a4..0x0767bc (24 B) | Symbol: sub_0767a4
// EN: AArch64 prologue [lsr x8, x0, #0x3a; cbnz x8, #0x767b4; lsl x0, x0, #6; b #0x93320] | VI: Khởi đầu hàm AArch64 [lsr x8, x0, #0x3a; cbnz x8, #0x767b4; lsl x0, x0, #6; b #0x93320]
uint64_t fde_sub_0767a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB5000068ULL) << 32) | 0xD37AFC08ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0767A4ULL;
}

// FDE #1688 | PC: 0x0767bc..0x076808 (76 B) | Symbol: sub_0767bc
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldp x22, x21, [x0]] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldp x22, x21, [x0]]
uint64_t fde_sub_0767bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0767BCULL;
}

// FDE #1689 | PC: 0x076808..0x076844 (60 B) | Symbol: sub_076808
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e030; bl #0x900d8] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e030; bl #0x900d8]
uint64_t fde_sub_076808(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x076808ULL;
}

// FDE #1690 | PC: 0x076844..0x07685c (24 B) | Symbol: sub_076844
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7676c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7676c; mov x0, x19]
uint64_t fde_sub_076844(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x076844ULL;
}

// FDE #1691 | PC: 0x07685c..0x076950 (244 B) | Symbol: sub_07685c
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x25, x24, [sp, #0x50]; stp x23, x22, [sp, #0x60]; stp x21, x20, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x25, x24, [sp, #0x50]; stp x23, x22, [sp, #0x60]; stp x21, x20, [sp, #0x70]]
uint64_t fde_sub_07685c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90563F9ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x00F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07685CULL;
}

// FDE #1692 | PC: 0x076950..0x0769d8 (136 B) | Symbol: sub_076950
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x23, x22, [sp, #0x50]; stp x21, x20, [sp, #0x60]; stp x19, x30, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x23, x22, [sp, #0x50]; stp x21, x20, [sp, #0x60]; stp x19, x30, [sp, #0x70]]
uint64_t fde_sub_076950(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9055BF7ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x076950ULL;
}

// FDE #1693 | PC: 0x0769d8..0x076a54 (124 B) | Symbol: sub_0769d8
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x23, x22, [sp, #0x50]; stp x21, x20, [sp, #0x60]; stp x19, x30, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x23, x22, [sp, #0x50]; stp x21, x20, [sp, #0x60]; stp x19, x30, [sp, #0x70]]
uint64_t fde_sub_0769d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9055BF7ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0769D8ULL;
}

// FDE #1694 | PC: 0x076a54..0x076a90 (60 B) | Symbol: sub_076a54
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x1; ldr w8, [x19], #0x20] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x1; ldr w8, [x19], #0x20]
uint64_t fde_sub_076a54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x076A54ULL;
}

// FDE #1695 | PC: 0x076a90..0x076ac0 (48 B) | Symbol: sub_076a90
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; lsr x8, x1, #0x3c; cbnz x8, #0x76abc; bl #0x9199c] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; lsr x8, x1, #0x3c; cbnz x8, #0x76abc; bl #0x9199c]
uint64_t fde_sub_076a90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD37CFC28ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x076A90ULL;
}

// FDE #1696 | PC: 0x076ac0..0x076ad8 (24 B) | Symbol: sub_076ac0
// EN: AArch64 prologue [lsr x8, x0, #0x3c; cbnz x8, #0x76ad0; lsl x0, x0, #4; b #0x93320] | VI: Khởi đầu hàm AArch64 [lsr x8, x0, #0x3c; cbnz x8, #0x76ad0; lsl x0, x0, #4; b #0x93320]
uint64_t fde_sub_076ac0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB5000068ULL) << 32) | 0xD37CFC08ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x076AC0ULL;
}

// FDE #1697 | PC: 0x076ad8..0x076b14 (60 B) | Symbol: sub_076ad8
// EN: AArch64 prologue [ldp x9, x8, [x0]; sub x9, x9, x8; cbz x9, #0x76b10; ldr x10, [x1, #8]] | VI: Khởi đầu hàm AArch64 [ldp x9, x8, [x0]; sub x9, x9, x8; cbz x9, #0x76b10; ldr x10, [x1, #8]]
uint64_t fde_sub_076ad8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xCB080129ULL) << 32) | 0xA9402009ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x076AD8ULL;
}

// FDE #1698 | PC: 0x076b14..0x076b54 (64 B) | Symbol: sub_076b14
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e030; bl #0x900d8] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e030; bl #0x900d8]
uint64_t fde_sub_076b14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x076B14ULL;
}

// FDE #1699 | PC: 0x076b54..0x076ba0 (76 B) | Symbol: sub_076b54
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8df88; cbz x1, #0x76b88] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8df88; cbz x1, #0x76b88]
uint64_t fde_sub_076b54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x076B54ULL;
}

// FDE #1700 | PC: 0x076ba0..0x076bec (76 B) | Symbol: sub_076ba0
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldp x22, x21, [x0]] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldp x22, x21, [x0]]
uint64_t fde_sub_076ba0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x076BA0ULL;
}

// FDE #1701 | PC: 0x076bec..0x076c28 (60 B) | Symbol: sub_076bec
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e030; bl #0x900d8] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e030; bl #0x900d8]
uint64_t fde_sub_076bec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x076BECULL;
}

// FDE #1702 | PC: 0x076c28..0x076c40 (24 B) | Symbol: sub_076c28
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x763b4; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x763b4; mov x0, x19]
uint64_t fde_sub_076c28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x076C28ULL;
}

// FDE #1703 | PC: 0x076c40..0x076dcc (396 B) | Symbol: sub_076c40
// EN: AArch64 prologue [sub sp, sp, #0x120; str x28, [sp, #0xe0]; stp x23, x22, [sp, #0xf0]; stp x21, x20, [sp, #0x100]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; str x28, [sp, #0xe0]; stp x23, x22, [sp, #0xf0]; stp x21, x20, [sp, #0x100]]
uint64_t fde_sub_076c40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90073FCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x018CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x076C40ULL;
}

// FDE #1704 | PC: 0x076dcc..0x077058 (652 B) | Symbol: sub_076dcc
// EN: AArch64 prologue [sub sp, sp, #0x130; stp x28, x27, [sp, #0xd0]; stp x26, x25, [sp, #0xe0]; stp x24, x23, [sp, #0xf0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x130; stp x28, x27, [sp, #0xd0]; stp x26, x25, [sp, #0xe0]; stp x24, x23, [sp, #0xf0]]
uint64_t fde_sub_076dcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90D6FFCULL) << 32) | 0xD104C3FFULL;
    const uint64_t kPcRange = 0x028CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x076DCCULL;
}

// FDE #1705 | PC: 0x077058..0x07717c (292 B) | Symbol: sub_077058
// EN: AArch64 prologue [sub sp, sp, #0xd0; str x22, [sp, #0xa0]; stp x21, x20, [sp, #0xb0]; stp x19, x30, [sp, #0xc0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xd0; str x22, [sp, #0xa0]; stp x21, x20, [sp, #0xb0]; stp x19, x30, [sp, #0xc0]]
uint64_t fde_sub_077058(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90053F6ULL) << 32) | 0xD10343FFULL;
    const uint64_t kPcRange = 0x0124ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077058ULL;
}

// FDE #1706 | PC: 0x07717c..0x0771b8 (60 B) | Symbol: sub_07717c
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8efd8; bl #0x771b8] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8efd8; bl #0x771b8]
uint64_t fde_sub_07717c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07717CULL;
}

// FDE #1707 | PC: 0x0771b8..0x0771d4 (28 B) | Symbol: sub_0771b8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; ldr x8, [x1], #8; bl #0x902b4; bl #0x47fbc] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; ldr x8, [x1], #8; bl #0x902b4; bl #0x47fbc]
uint64_t fde_sub_0771b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF8408428ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0771B8ULL;
}

// FDE #1708 | PC: 0x0771d4..0x0772cc (248 B) | Symbol: sub_0771d4
// EN: AArch64 prologue [sub sp, sp, #0x90; str x24, [sp, #0x50]; stp x23, x22, [sp, #0x60]; stp x21, x20, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x24, [sp, #0x50]; stp x23, x22, [sp, #0x60]; stp x21, x20, [sp, #0x70]]
uint64_t fde_sub_0771d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9002BF8ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0771D4ULL;
}

// FDE #1709 | PC: 0x0772cc..0x077378 (172 B) | Symbol: sub_0772cc
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_0772cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0772CCULL;
}

// FDE #1710 | PC: 0x077378..0x07739c (36 B) | Symbol: sub_077378
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8e7ac; adrp x8, #0x9b000; add x8, x8, #0xf40] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8e7ac; adrp x8, #0x9b000; add x8, x8, #0xf40]
uint64_t fde_sub_077378(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94005D0CULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077378ULL;
}

// FDE #1711 | PC: 0x07739c..0x0773b4 (24 B) | Symbol: sub_07739c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x77378; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x77378; mov x0, x19]
uint64_t fde_sub_07739c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07739CULL;
}

// FDE #1712 | PC: 0x0773b4..0x077484 (208 B) | Symbol: sub_0773b4
// EN: AArch64 prologue [sub sp, sp, #0xf0; str x24, [sp, #0xb0]; stp x23, x22, [sp, #0xc0]; stp x21, x20, [sp, #0xd0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xf0; str x24, [sp, #0xb0]; stp x23, x22, [sp, #0xc0]; stp x21, x20, [sp, #0xd0]]
uint64_t fde_sub_0773b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9005BF8ULL) << 32) | 0xD103C3FFULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0773B4ULL;
}

// FDE #1713 | PC: 0x077484..0x0774d0 (76 B) | Symbol: sub_077484
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e578; add x0, x20, #0x30] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e578; add x0, x20, #0x30]
uint64_t fde_sub_077484(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077484ULL;
}

// FDE #1714 | PC: 0x0774d0..0x0774f8 (40 B) | Symbol: sub_0774d0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x90]; bl #0x44830] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x90]; bl #0x44830]
uint64_t fde_sub_0774d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0774D0ULL;
}

// FDE #1715 | PC: 0x0774f8..0x077514 (28 B) | Symbol: sub_0774f8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x78]; bl #0x44830] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x78]; bl #0x44830]
uint64_t fde_sub_0774f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0774F8ULL;
}

// FDE #1716 | PC: 0x077514..0x077524 (16 B) | Symbol: sub_077514
// EN: AArch64 prologue [adrp x8, #0x9b000; add x8, x8, #0xf68; str x8, [x0], #8; b #0x774d0] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9b000; add x8, x8, #0xf68; str x8, [x0], #8; b #0x774d0]
uint64_t fde_sub_077514(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x913DA108ULL) << 32) | 0x90000128ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077514ULL;
}

// FDE #1717 | PC: 0x077524..0x07753c (24 B) | Symbol: sub_077524
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x77514; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x77514; mov x0, x19]
uint64_t fde_sub_077524(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077524ULL;
}

// FDE #1718 | PC: 0x07753c..0x0775c8 (140 B) | Symbol: sub_07753c
// EN: AArch64 prologue [sub sp, sp, #0xc0; stp x21, x20, [sp, #0xa0]; stp x19, x30, [sp, #0xb0]; bl #0x8ecb8] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; stp x21, x20, [sp, #0xa0]; stp x19, x30, [sp, #0xb0]; bl #0x8ecb8]
uint64_t fde_sub_07753c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90A53F5ULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07753CULL;
}

// FDE #1719 | PC: 0x0775c8..0x0775e8 (32 B) | Symbol: sub_0775c8
// EN: AArch64 prologue [mov x8, x0; ldr x0, [x0, #8]; adrp x9, #0x9b000; add x9, x9, #0xf90] | VI: Khởi đầu hàm AArch64 [mov x8, x0; ldr x0, [x0, #8]; adrp x9, #0x9b000; add x9, x9, #0xf90]
uint64_t fde_sub_0775c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400400ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0775C8ULL;
}

// FDE #1720 | PC: 0x0775e8..0x077600 (24 B) | Symbol: sub_0775e8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x775c8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x775c8; mov x0, x19]
uint64_t fde_sub_0775e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0775E8ULL;
}

// FDE #1721 | PC: 0x077600..0x077738 (312 B) | Symbol: sub_077600
// EN: AArch64 prologue [sub sp, sp, #0x110; str x28, [sp, #0xd0]; stp x23, x22, [sp, #0xe0]; stp x21, x20, [sp, #0xf0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; str x28, [sp, #0xd0]; stp x23, x22, [sp, #0xe0]; stp x21, x20, [sp, #0xf0]]
uint64_t fde_sub_077600(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9006BFCULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x0138ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077600ULL;
}

// FDE #1722 | PC: 0x077738..0x077768 (48 B) | Symbol: sub_077738
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x38; bl #0x91050] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x38; bl #0x91050]
uint64_t fde_sub_077738(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077738ULL;
}

// FDE #1723 | PC: 0x077768..0x077778 (16 B) | Symbol: sub_077768
// EN: AArch64 prologue [adrp x8, #0x9b000; add x8, x8, #0xfb8; str x8, [x0], #8; b #0x77738] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9b000; add x8, x8, #0xfb8; str x8, [x0], #8; b #0x77738]
uint64_t fde_sub_077768(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x913EE108ULL) << 32) | 0x90000128ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077768ULL;
}

// FDE #1724 | PC: 0x077778..0x077790 (24 B) | Symbol: sub_077778
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x77768; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x77768; mov x0, x19]
uint64_t fde_sub_077778(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077778ULL;
}

// FDE #1725 | PC: 0x077790..0x077804 (116 B) | Symbol: sub_077790
// EN: AArch64 prologue [sub sp, sp, #0x70; str x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]; ldr x8, [x0, #8]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]; ldr x8, [x0, #8]]
uint64_t fde_sub_077790(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9002BF4ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077790ULL;
}

// FDE #1726 | PC: 0x077804..0x077828 (36 B) | Symbol: sub_077804
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8e7ac; adrp x8, #0x9b000; add x8, x8, #0xfe0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8e7ac; adrp x8, #0x9b000; add x8, x8, #0xfe0]
uint64_t fde_sub_077804(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94005BE9ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077804ULL;
}

// FDE #1727 | PC: 0x077828..0x077840 (24 B) | Symbol: sub_077828
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x77804; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x77804; mov x0, x19]
uint64_t fde_sub_077828(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077828ULL;
}

// FDE #1728 | PC: 0x077840..0x077910 (208 B) | Symbol: sub_077840
// EN: AArch64 prologue [sub sp, sp, #0xb0; str x24, [sp, #0x70]; stp x23, x22, [sp, #0x80]; stp x21, x20, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; str x24, [sp, #0x70]; stp x23, x22, [sp, #0x80]; stp x21, x20, [sp, #0x90]]
uint64_t fde_sub_077840(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9003BF8ULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077840ULL;
}

// FDE #1729 | PC: 0x077910..0x077934 (36 B) | Symbol: sub_077910
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e128; bl #0x7579c] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e128; bl #0x7579c]
uint64_t fde_sub_077910(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077910ULL;
}

// FDE #1730 | PC: 0x077934..0x077958 (36 B) | Symbol: sub_077934
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x930f4; bl #0x44830; ldr x0, [x19, #0x40]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x930f4; bl #0x44830; ldr x0, [x19, #0x40]]
uint64_t fde_sub_077934(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94006DEFULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077934ULL;
}

// FDE #1731 | PC: 0x077958..0x077970 (24 B) | Symbol: sub_077958
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x20; bl #0x91050] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x20; bl #0x91050]
uint64_t fde_sub_077958(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077958ULL;
}

// FDE #1732 | PC: 0x077970..0x077980 (16 B) | Symbol: sub_077970
// EN: AArch64 prologue [adrp x8, #0x9c000; add x8, x8, #8; str x8, [x0], #8; b #0x77934] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9c000; add x8, x8, #8; str x8, [x0], #8; b #0x77934]
uint64_t fde_sub_077970(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91002108ULL) << 32) | 0xB0000128ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077970ULL;
}

// FDE #1733 | PC: 0x077980..0x077998 (24 B) | Symbol: sub_077980
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x77970; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x77970; mov x0, x19]
uint64_t fde_sub_077980(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077980ULL;
}

// FDE #1734 | PC: 0x077998..0x077a24 (140 B) | Symbol: sub_077998
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x21, x20, [sp, #0x60]; stp x19, x30, [sp, #0x70]; bl #0x8ecb8] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x21, x20, [sp, #0x60]; stp x19, x30, [sp, #0x70]; bl #0x8ecb8]
uint64_t fde_sub_077998(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90653F5ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077998ULL;
}

// FDE #1735 | PC: 0x077a24..0x077a44 (32 B) | Symbol: sub_077a24
// EN: AArch64 prologue [mov x8, x0; ldr x0, [x0, #8]; adrp x9, #0x9c000; add x9, x9, #0x30] | VI: Khởi đầu hàm AArch64 [mov x8, x0; ldr x0, [x0, #8]; adrp x9, #0x9c000; add x9, x9, #0x30]
uint64_t fde_sub_077a24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400400ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077A24ULL;
}

// FDE #1736 | PC: 0x077a44..0x077a5c (24 B) | Symbol: sub_077a44
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x77a24; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x77a24; mov x0, x19]
uint64_t fde_sub_077a44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077A44ULL;
}

// FDE #1737 | PC: 0x077a5c..0x077b60 (260 B) | Symbol: sub_077a5c
// EN: AArch64 prologue [sub sp, sp, #0x130; stp x28, x24, [sp, #0xf0]; stp x23, x22, [sp, #0x100]; stp x21, x20, [sp, #0x110]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x130; stp x28, x24, [sp, #0xf0]; stp x23, x22, [sp, #0x100]; stp x21, x20, [sp, #0x110]]
uint64_t fde_sub_077a5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90F63FCULL) << 32) | 0xD104C3FFULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077A5CULL;
}

// FDE #1738 | PC: 0x077b60..0x077ba4 (68 B) | Symbol: sub_077b60
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x92110; ldr x8, [x1, #8]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x92110; ldr x8, [x1, #8]]
uint64_t fde_sub_077b60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077B60ULL;
}

// FDE #1739 | PC: 0x077ba4..0x077bc4 (32 B) | Symbol: sub_077ba4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x30; bl #0x46c54] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x30; bl #0x46c54]
uint64_t fde_sub_077ba4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077BA4ULL;
}

// FDE #1740 | PC: 0x077bc4..0x077bf4 (48 B) | Symbol: sub_077bc4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x58; bl #0x91050] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x58; bl #0x91050]
uint64_t fde_sub_077bc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077BC4ULL;
}

// FDE #1741 | PC: 0x077bf4..0x077c04 (16 B) | Symbol: sub_077bf4
// EN: AArch64 prologue [adrp x8, #0x9c000; add x8, x8, #0x58; str x8, [x0], #8; b #0x77bc4] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9c000; add x8, x8, #0x58; str x8, [x0], #8; b #0x77bc4]
uint64_t fde_sub_077bf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91016108ULL) << 32) | 0xB0000128ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077BF4ULL;
}

// FDE #1742 | PC: 0x077c04..0x077c1c (24 B) | Symbol: sub_077c04
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x77bf4; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x77bf4; mov x0, x19]
uint64_t fde_sub_077c04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077C04ULL;
}

// FDE #1743 | PC: 0x077c1c..0x077c78 (92 B) | Symbol: sub_077c1c
// EN: AArch64 prologue [sub sp, sp, #0x90; str x20, [sp, #0x70]; stp x19, x30, [sp, #0x80]; ldr x8, [x0, #8]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x20, [sp, #0x70]; stp x19, x30, [sp, #0x80]; ldr x8, [x0, #8]]
uint64_t fde_sub_077c1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9003BF4ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077C1CULL;
}

// FDE #1744 | PC: 0x077c78..0x077ce8 (112 B) | Symbol: sub_077c78
// EN: AArch64 prologue [sub sp, sp, #0xa0; str x22, [sp, #0x70]; stp x21, x20, [sp, #0x80]; stp x19, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; str x22, [sp, #0x70]; stp x21, x20, [sp, #0x80]; stp x19, x30, [sp, #0x90]]
uint64_t fde_sub_077c78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9003BF6ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077C78ULL;
}

// FDE #1745 | PC: 0x077ce8..0x077d04 (28 B) | Symbol: sub_077ce8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8e7ac; adrp x8, #0x9c000; add x8, x8, #0x80] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8e7ac; adrp x8, #0x9c000; add x8, x8, #0x80]
uint64_t fde_sub_077ce8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94005AB0ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077CE8ULL;
}

// FDE #1746 | PC: 0x077d04..0x077d1c (24 B) | Symbol: sub_077d04
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x77ce8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x77ce8; mov x0, x19]
uint64_t fde_sub_077d04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077D04ULL;
}

// FDE #1747 | PC: 0x077d1c..0x077df0 (212 B) | Symbol: sub_077d1c
// EN: AArch64 prologue [sub sp, sp, #0xd0; str x24, [sp, #0x90]; stp x23, x22, [sp, #0xa0]; stp x21, x20, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xd0; str x24, [sp, #0x90]; stp x23, x22, [sp, #0xa0]; stp x21, x20, [sp, #0xb0]]
uint64_t fde_sub_077d1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9004BF8ULL) << 32) | 0xD10343FFULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077D1CULL;
}

// FDE #1748 | PC: 0x077df0..0x077e18 (40 B) | Symbol: sub_077df0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x70]; bl #0x44830] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x70]; bl #0x44830]
uint64_t fde_sub_077df0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077DF0ULL;
}

// FDE #1749 | PC: 0x077e18..0x077e28 (16 B) | Symbol: sub_077e18
// EN: AArch64 prologue [adrp x8, #0x9c000; add x8, x8, #0xa8; str x8, [x0], #8; b #0x77df0] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9c000; add x8, x8, #0xa8; str x8, [x0], #8; b #0x77df0]
uint64_t fde_sub_077e18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9102A108ULL) << 32) | 0xB0000128ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077E18ULL;
}

// FDE #1750 | PC: 0x077e28..0x077e40 (24 B) | Symbol: sub_077e28
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x77e18; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x77e18; mov x0, x19]
uint64_t fde_sub_077e28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077E28ULL;
}

// FDE #1751 | PC: 0x077e40..0x077ecc (140 B) | Symbol: sub_077e40
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp x21, x20, [sp, #0x80]; stp x19, x30, [sp, #0x90]; bl #0x8ecb8] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp x21, x20, [sp, #0x80]; stp x19, x30, [sp, #0x90]; bl #0x8ecb8]
uint64_t fde_sub_077e40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90853F5ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077E40ULL;
}

// FDE #1752 | PC: 0x077ecc..0x077eec (32 B) | Symbol: sub_077ecc
// EN: AArch64 prologue [mov x8, x0; ldr x0, [x0, #8]; adrp x9, #0x9c000; add x9, x9, #0xd0] | VI: Khởi đầu hàm AArch64 [mov x8, x0; ldr x0, [x0, #8]; adrp x9, #0x9c000; add x9, x9, #0xd0]
uint64_t fde_sub_077ecc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400400ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077ECCULL;
}

// FDE #1753 | PC: 0x077eec..0x077f04 (24 B) | Symbol: sub_077eec
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x77ecc; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x77ecc; mov x0, x19]
uint64_t fde_sub_077eec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077EECULL;
}

// FDE #1754 | PC: 0x077f04..0x077f9c (152 B) | Symbol: sub_077f04
// EN: AArch64 prologue [sub sp, sp, #0x100; str x24, [sp, #0xc0]; stp x23, x22, [sp, #0xd0]; stp x21, x20, [sp, #0xe0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x100; str x24, [sp, #0xc0]; stp x23, x22, [sp, #0xd0]; stp x21, x20, [sp, #0xe0]]
uint64_t fde_sub_077f04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90063F8ULL) << 32) | 0xD10403FFULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077F04ULL;
}

// FDE #1755 | PC: 0x077f9c..0x077fc0 (36 B) | Symbol: sub_077f9c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x93118; ldr x0, [x19]; cbz x0, #0x77fb8] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x93118; ldr x0, [x19]; cbz x0, #0x77fb8]
uint64_t fde_sub_077f9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94006C5EULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077F9CULL;
}

// FDE #1756 | PC: 0x077fc0..0x077fd0 (16 B) | Symbol: sub_077fc0
// EN: AArch64 prologue [adrp x8, #0x9c000; add x8, x8, #0xf8; str x8, [x0], #8; b #0x77f9c] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9c000; add x8, x8, #0xf8; str x8, [x0], #8; b #0x77f9c]
uint64_t fde_sub_077fc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9103E108ULL) << 32) | 0xB0000128ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077FC0ULL;
}

// FDE #1757 | PC: 0x077fd0..0x077fe8 (24 B) | Symbol: sub_077fd0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x77fc0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x77fc0; mov x0, x19]
uint64_t fde_sub_077fd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077FD0ULL;
}

// FDE #1758 | PC: 0x077fe8..0x078030 (72 B) | Symbol: sub_077fe8
// EN: AArch64 prologue [sub sp, sp, #0x70; str x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]; ldr x8, [x0, #8]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]; ldr x8, [x0, #8]]
uint64_t fde_sub_077fe8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9002BF4ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x077FE8ULL;
}

// FDE #1759 | PC: 0x078030..0x0780ac (124 B) | Symbol: sub_078030
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_078030(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9025BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078030ULL;
}

// FDE #1760 | PC: 0x0780ac..0x0780d4 (40 B) | Symbol: sub_0780ac
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8db6c; bl #0x48d40; ldr x0, [x19]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8db6c; bl #0x48d40; ldr x0, [x19]]
uint64_t fde_sub_0780ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940056AFULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0780ACULL;
}

// FDE #1761 | PC: 0x0780d4..0x0780e4 (16 B) | Symbol: sub_0780d4
// EN: AArch64 prologue [adrp x8, #0x9c000; add x8, x8, #0x120; str x8, [x0], #8; b #0x780ac] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9c000; add x8, x8, #0x120; str x8, [x0], #8; b #0x780ac]
uint64_t fde_sub_0780d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91048108ULL) << 32) | 0x90000128ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0780D4ULL;
}

// FDE #1762 | PC: 0x0780e4..0x0780fc (24 B) | Symbol: sub_0780e4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x780d4; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x780d4; mov x0, x19]
uint64_t fde_sub_0780e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0780E4ULL;
}

// FDE #1763 | PC: 0x0780fc..0x0781c8 (204 B) | Symbol: sub_0780fc
// EN: AArch64 prologue [sub sp, sp, #0xe0; stp x25, x24, [sp, #0xa0]; stp x23, x22, [sp, #0xb0]; stp x21, x20, [sp, #0xc0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xe0; stp x25, x24, [sp, #0xa0]; stp x23, x22, [sp, #0xb0]; stp x21, x20, [sp, #0xc0]]
uint64_t fde_sub_0780fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90A63F9ULL) << 32) | 0xD10383FFULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0780FCULL;
}

// FDE #1764 | PC: 0x0781c8..0x0783b0 (488 B) | Symbol: sub_0781c8
// EN: AArch64 prologue [sub sp, sp, #0x150; str x28, [sp, #0x100]; stp x25, x24, [sp, #0x110]; stp x23, x22, [sp, #0x120]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x150; str x28, [sp, #0x100]; stp x25, x24, [sp, #0x110]; stp x23, x22, [sp, #0x120]]
uint64_t fde_sub_0781c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90083FCULL) << 32) | 0xD10543FFULL;
    const uint64_t kPcRange = 0x01E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0781C8ULL;
}

// FDE #1765 | PC: 0x0783b0..0x0783c0 (16 B) | Symbol: sub_0783b0
// EN: AArch64 prologue [adrp x8, #0x9c000; add x8, x8, #0x148; str x8, [x0], #8; b #0x4b798] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9c000; add x8, x8, #0x148; str x8, [x0], #8; b #0x4b798]
uint64_t fde_sub_0783b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91052108ULL) << 32) | 0x90000128ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0783B0ULL;
}

// FDE #1766 | PC: 0x0783c0..0x0783d8 (24 B) | Symbol: sub_0783c0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x783b0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x783b0; mov x0, x19]
uint64_t fde_sub_0783c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0783C0ULL;
}

// FDE #1767 | PC: 0x0783d8..0x078554 (380 B) | Symbol: sub_0783d8
// EN: AArch64 prologue [sub sp, sp, #0x110; str x28, [sp, #0xd0]; stp x23, x22, [sp, #0xe0]; stp x21, x20, [sp, #0xf0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; str x28, [sp, #0xd0]; stp x23, x22, [sp, #0xe0]; stp x21, x20, [sp, #0xf0]]
uint64_t fde_sub_0783d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9006BFCULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x017CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0783D8ULL;
}

// FDE #1768 | PC: 0x078554..0x078688 (308 B) | Symbol: sub_078554
// EN: AArch64 prologue [sub sp, sp, #0x1a0; stp x28, x22, [sp, #0x170]; stp x21, x20, [sp, #0x180]; stp x19, x30, [sp, #0x190]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1a0; stp x28, x22, [sp, #0x170]; stp x21, x20, [sp, #0x180]; stp x19, x30, [sp, #0x190]]
uint64_t fde_sub_078554(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9175BFCULL) << 32) | 0xD10683FFULL;
    const uint64_t kPcRange = 0x0134ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078554ULL;
}

// FDE #1769 | PC: 0x078688..0x07868c (4 B) | Symbol: sub_078688
// EN: AArch64 prologue [b #0x92cf0] | VI: Khởi đầu hàm AArch64 [b #0x92cf0]
uint64_t fde_sub_078688(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E0ULL) << 32) | 0x1400699AULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078688ULL;
}

// FDE #1770 | PC: 0x07868c..0x0788ac (544 B) | Symbol: sub_07868c
// EN: AArch64 prologue [mov x0, x30; bl #0x8d63c; mov x30, x0; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x0, x30; bl #0x8d63c; mov x30, x0; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_07868c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940053EBULL) << 32) | 0xAA1E03E0ULL;
    const uint64_t kPcRange = 0x0220ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07868CULL;
}

// FDE #1771 | PC: 0x0788ac..0x0788c8 (28 B) | Symbol: sub_0788ac
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x92c3c; add x8, x20, w19, uxtb #3] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x92c3c; add x8, x20, w19, uxtb #3]
uint64_t fde_sub_0788ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0788ACULL;
}

// FDE #1772 | PC: 0x0788c8..0x0788e0 (24 B) | Symbol: sub_0788c8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; add x19, x0, w1, uxtb #3; bl #0x4c9e4; str x0, [x19, #0xd0]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; add x19, x0, w1, uxtb #3; bl #0x4c9e4; str x0, [x19, #0xd0]]
uint64_t fde_sub_0788c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8B210C13ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0788C8ULL;
}

// FDE #1773 | PC: 0x0788e0..0x0788e8 (8 B) | Symbol: sub_0788e0
// EN: AArch64 prologue [add x1, x0, #0xe8; b #0x903f4] | VI: Khởi đầu hàm AArch64 [add x1, x0, #0xe8; b #0x903f4]
uint64_t fde_sub_0788e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14005EC4ULL) << 32) | 0x9103A001ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0788E0ULL;
}

// FDE #1774 | PC: 0x0788e8..0x0788f0 (8 B) | Symbol: sub_0788e8
// EN: AArch64 prologue [add x1, x0, #0xd0; b #0x903f4] | VI: Khởi đầu hàm AArch64 [add x1, x0, #0xd0; b #0x903f4]
uint64_t fde_sub_0788e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14005EC2ULL) << 32) | 0x91034001ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0788E8ULL;
}

// FDE #1775 | PC: 0x0788f0..0x078908 (24 B) | Symbol: sub_0788f0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4e980; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x4e980; mov x0, x19]
uint64_t fde_sub_0788f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0788F0ULL;
}

// FDE #1776 | PC: 0x078908..0x078910 (8 B) | Symbol: sub_078908
// EN: AArch64 prologue [sub x0, x0, #0x18; b #0x4e980] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x18; b #0x4e980]
uint64_t fde_sub_078908(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF581DULL) << 32) | 0xD1006000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078908ULL;
}

// FDE #1777 | PC: 0x078910..0x078918 (8 B) | Symbol: sub_078910
// EN: AArch64 prologue [sub x0, x0, #0x18; b #0x788f0] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x18; b #0x788f0]
uint64_t fde_sub_078910(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF7ULL) << 32) | 0xD1006000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078910ULL;
}

// FDE #1778 | PC: 0x078918..0x078944 (44 B) | Symbol: sub_078918
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8eb7c; adrp x8, #0x9c000; add x8, x8, #0x210] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8eb7c; adrp x8, #0x9c000; add x8, x8, #0x210]
uint64_t fde_sub_078918(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94005898ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078918ULL;
}

// FDE #1779 | PC: 0x078944..0x07895c (24 B) | Symbol: sub_078944
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x78918; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x78918; mov x0, x19]
uint64_t fde_sub_078944(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078944ULL;
}

// FDE #1780 | PC: 0x07895c..0x0789f4 (152 B) | Symbol: sub_07895c
// EN: AArch64 prologue [sub sp, sp, #0xb0; str x24, [sp, #0x70]; stp x23, x22, [sp, #0x80]; stp x21, x20, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; str x24, [sp, #0x70]; stp x23, x22, [sp, #0x80]; stp x21, x20, [sp, #0x90]]
uint64_t fde_sub_07895c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9003BF8ULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07895CULL;
}

// FDE #1781 | PC: 0x0789f4..0x078a04 (16 B) | Symbol: sub_0789f4
// EN: AArch64 prologue [adrp x8, #0x9c000; add x8, x8, #0x238; str x8, [x0], #8; b #0x54044] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9c000; add x8, x8, #0x238; str x8, [x0], #8; b #0x54044]
uint64_t fde_sub_0789f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9108E108ULL) << 32) | 0x90000128ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0789F4ULL;
}

// FDE #1782 | PC: 0x078a04..0x078a1c (24 B) | Symbol: sub_078a04
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x789f4; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x789f4; mov x0, x19]
uint64_t fde_sub_078a04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078A04ULL;
}

// FDE #1783 | PC: 0x078a1c..0x078aec (208 B) | Symbol: sub_078a1c
// EN: AArch64 prologue [str x28, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; sub sp, sp, #0x1f0] | VI: Khởi đầu hàm AArch64 [str x28, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; sub sp, sp, #0x1f0]
uint64_t fde_sub_078a1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FFCULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078A1CULL;
}

// FDE #1784 | PC: 0x078aec..0x078b30 (68 B) | Symbol: sub_078aec
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x924cc; add x0, x20, #0x40] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x924cc; add x0, x20, #0x40]
uint64_t fde_sub_078aec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078AECULL;
}

// FDE #1785 | PC: 0x078b30..0x078b60 (48 B) | Symbol: sub_078b30
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x88; bl #0x77ba4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x88; bl #0x77ba4]
uint64_t fde_sub_078b30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078B30ULL;
}

// FDE #1786 | PC: 0x078b60..0x078b84 (36 B) | Symbol: sub_078b60
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8ddf8; adrp x8, #0x9c000; add x8, x8, #0x1e8] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8ddf8; adrp x8, #0x9c000; add x8, x8, #0x1e8]
uint64_t fde_sub_078b60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940054A5ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078B60ULL;
}

// FDE #1787 | PC: 0x078b84..0x078b9c (24 B) | Symbol: sub_078b84
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x78b60; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x78b60; mov x0, x19]
uint64_t fde_sub_078b84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078B84ULL;
}

// FDE #1788 | PC: 0x078b9c..0x078df0 (596 B) | Symbol: sub_078b9c
// EN: AArch64 prologue [str d8, [sp, #-0x40]!; str x28, [sp, #8]; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [str d8, [sp, #-0x40]!; str x28, [sp, #8]; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]]
uint64_t fde_sub_078b9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90007FCULL) << 32) | 0xFC1C0FE8ULL;
    const uint64_t kPcRange = 0x0254ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078B9CULL;
}

// FDE #1789 | PC: 0x078df0..0x078e70 (128 B) | Symbol: sub_078df0
// EN: AArch64 prologue [sub sp, sp, #0x130; stp x28, x22, [sp, #0x100]; stp x21, x20, [sp, #0x110]; stp x19, x30, [sp, #0x120]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x130; stp x28, x22, [sp, #0x100]; stp x21, x20, [sp, #0x110]; stp x19, x30, [sp, #0x120]]
uint64_t fde_sub_078df0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9105BFCULL) << 32) | 0xD104C3FFULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078DF0ULL;
}

// FDE #1790 | PC: 0x078e70..0x078e9c (44 B) | Symbol: sub_078e70
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x90cb4; adrp x8, #0x9c000; add x8, x8, #0x288] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x90cb4; adrp x8, #0x9c000; add x8, x8, #0x288]
uint64_t fde_sub_078e70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94005F90ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078E70ULL;
}

// FDE #1791 | PC: 0x078e9c..0x078eb4 (24 B) | Symbol: sub_078e9c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x78e70; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x78e70; mov x0, x19]
uint64_t fde_sub_078e9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078E9CULL;
}

// FDE #1792 | PC: 0x078eb4..0x078f10 (92 B) | Symbol: sub_078eb4
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]; bl #0x8f710] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]; bl #0x8f710]
uint64_t fde_sub_078eb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90553F5ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078EB4ULL;
}

// FDE #1793 | PC: 0x078f10..0x078f30 (32 B) | Symbol: sub_078f10
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8ddf8; adrp x8, #0x9c000; add x8, x8, #0x260] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8ddf8; adrp x8, #0x9c000; add x8, x8, #0x260]
uint64_t fde_sub_078f10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940053B9ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078F10ULL;
}

// FDE #1794 | PC: 0x078f30..0x078f5c (44 B) | Symbol: sub_078f30
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8eb7c; adrp x8, #0x9c000; add x8, x8, #0x300] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8eb7c; adrp x8, #0x9c000; add x8, x8, #0x300]
uint64_t fde_sub_078f30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94005712ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078F30ULL;
}

// FDE #1795 | PC: 0x078f5c..0x078f74 (24 B) | Symbol: sub_078f5c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x78f30; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x78f30; mov x0, x19]
uint64_t fde_sub_078f5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078F5CULL;
}

// FDE #1796 | PC: 0x078f74..0x07900c (152 B) | Symbol: sub_078f74
// EN: AArch64 prologue [sub sp, sp, #0xb0; str x24, [sp, #0x70]; stp x23, x22, [sp, #0x80]; stp x21, x20, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; str x24, [sp, #0x70]; stp x23, x22, [sp, #0x80]; stp x21, x20, [sp, #0x90]]
uint64_t fde_sub_078f74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9003BF8ULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078F74ULL;
}

// FDE #1797 | PC: 0x07900c..0x07901c (16 B) | Symbol: sub_07900c
// EN: AArch64 prologue [adrp x8, #0x9c000; add x8, x8, #0x328; str x8, [x0], #8; b #0x54044] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9c000; add x8, x8, #0x328; str x8, [x0], #8; b #0x54044]
uint64_t fde_sub_07900c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910CA108ULL) << 32) | 0xF0000108ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07900CULL;
}

// FDE #1798 | PC: 0x07901c..0x079034 (24 B) | Symbol: sub_07901c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7900c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7900c; mov x0, x19]
uint64_t fde_sub_07901c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07901CULL;
}

// FDE #1799 | PC: 0x079034..0x079138 (260 B) | Symbol: sub_079034
// EN: AArch64 prologue [sub sp, sp, #0x1d0; str x28, [sp, #0x1a0]; stp x21, x20, [sp, #0x1b0]; stp x19, x30, [sp, #0x1c0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1d0; str x28, [sp, #0x1a0]; stp x21, x20, [sp, #0x1b0]; stp x19, x30, [sp, #0x1c0]]
uint64_t fde_sub_079034(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900D3FCULL) << 32) | 0xD10743FFULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079034ULL;
}

// FDE #1800 | PC: 0x079138..0x079178 (64 B) | Symbol: sub_079138
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x924cc; ldr x8, [x19, #0x40]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x924cc; ldr x8, [x19, #0x40]]
uint64_t fde_sub_079138(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079138ULL;
}

// FDE #1801 | PC: 0x079178..0x0791a4 (44 B) | Symbol: sub_079178
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x90; bl #0x46c54] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x90; bl #0x46c54]
uint64_t fde_sub_079178(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079178ULL;
}

// FDE #1802 | PC: 0x0791a4..0x0791c8 (36 B) | Symbol: sub_0791a4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8ddf8; adrp x8, #0x9c000; add x8, x8, #0x2d8] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8ddf8; adrp x8, #0x9c000; add x8, x8, #0x2d8]
uint64_t fde_sub_0791a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94005314ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0791A4ULL;
}

// FDE #1803 | PC: 0x0791c8..0x0791e0 (24 B) | Symbol: sub_0791c8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x791a4; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x791a4; mov x0, x19]
uint64_t fde_sub_0791c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0791C8ULL;
}

// FDE #1804 | PC: 0x0791e0..0x07937c (412 B) | Symbol: sub_0791e0
// EN: AArch64 prologue [str x28, [sp, #-0x50]!; stp x25, x24, [sp, #0x10]; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x28, [sp, #-0x50]!; stp x25, x24, [sp, #0x10]; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]]
uint64_t fde_sub_0791e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90163F9ULL) << 32) | 0xF81B0FFCULL;
    const uint64_t kPcRange = 0x019CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0791E0ULL;
}

// FDE #1805 | PC: 0x07937c..0x07939c (32 B) | Symbol: sub_07937c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9c000; add x8, x8, #0x2b0; bl #0x8daa4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9c000; add x8, x8, #0x2b0; bl #0x8daa4]
uint64_t fde_sub_07937c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000108ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07937CULL;
}

// FDE #1806 | PC: 0x07939c..0x0793b4 (24 B) | Symbol: sub_07939c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7937c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7937c; mov x0, x19]
uint64_t fde_sub_07939c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07939CULL;
}

// FDE #1807 | PC: 0x0793b4..0x07988c (1240 B) | Symbol: sub_0793b4
// EN: AArch64 prologue [stp x28, x26, [sp, #-0x50]!; stp x25, x24, [sp, #0x10]; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x26, [sp, #-0x50]!; stp x25, x24, [sp, #0x10]; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]]
uint64_t fde_sub_0793b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90163F9ULL) << 32) | 0xA9BB6BFCULL;
    const uint64_t kPcRange = 0x04D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0793B4ULL;
}

// FDE #1808 | PC: 0x07988c..0x079900 (116 B) | Symbol: sub_07988c
// EN: AArch64 prologue [sub sp, sp, #0x100; str x22, [sp, #0xd0]; stp x21, x20, [sp, #0xe0]; stp x19, x30, [sp, #0xf0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x100; str x22, [sp, #0xd0]; stp x21, x20, [sp, #0xe0]; stp x19, x30, [sp, #0xf0]]
uint64_t fde_sub_07988c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9006BF6ULL) << 32) | 0xD10403FFULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07988CULL;
}

// FDE #1809 | PC: 0x079900..0x07991c (28 B) | Symbol: sub_079900
// EN: AArch64 prologue [cbz x0, #0x79918; stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x8ebec] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x79918; stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x8ebec]
uint64_t fde_sub_079900(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BF3ULL) << 32) | 0xB40000C0ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079900ULL;
}

// FDE #1810 | PC: 0x07991c..0x079944 (40 B) | Symbol: sub_07991c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0xb8]; bl #0x48d40] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0xb8]; bl #0x48d40]
uint64_t fde_sub_07991c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07991CULL;
}

// FDE #1811 | PC: 0x079944..0x079954 (16 B) | Symbol: sub_079944
// EN: AArch64 prologue [adrp x8, #0x9c000; add x8, x8, #0x350; str x8, [x0], #8; b #0x7991c] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9c000; add x8, x8, #0x350; str x8, [x0], #8; b #0x7991c]
uint64_t fde_sub_079944(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910D4108ULL) << 32) | 0xF0000108ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079944ULL;
}

// FDE #1812 | PC: 0x079954..0x07996c (24 B) | Symbol: sub_079954
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x79944; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x79944; mov x0, x19]
uint64_t fde_sub_079954(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079954ULL;
}

// FDE #1813 | PC: 0x07996c..0x079ab8 (332 B) | Symbol: sub_07996c
// EN: AArch64 prologue [sub sp, sp, #0x190; stp x28, x22, [sp, #0x160]; stp x21, x20, [sp, #0x170]; stp x19, x30, [sp, #0x180]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x190; stp x28, x22, [sp, #0x160]; stp x21, x20, [sp, #0x170]; stp x19, x30, [sp, #0x180]]
uint64_t fde_sub_07996c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9165BFCULL) << 32) | 0xD10643FFULL;
    const uint64_t kPcRange = 0x014CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07996CULL;
}

// FDE #1814 | PC: 0x079ab8..0x079b88 (208 B) | Symbol: sub_079ab8
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x25, x24, [sp, #0x10]; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x25, x24, [sp, #0x10]; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]]
uint64_t fde_sub_079ab8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90163F9ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079AB8ULL;
}

// FDE #1815 | PC: 0x079b88..0x079bb4 (44 B) | Symbol: sub_079b88
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8eb7c; adrp x8, #0x9c000; add x8, x8, #0x3c8] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8eb7c; adrp x8, #0x9c000; add x8, x8, #0x3c8]
uint64_t fde_sub_079b88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940053FCULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079B88ULL;
}

// FDE #1816 | PC: 0x079bb4..0x079bcc (24 B) | Symbol: sub_079bb4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x79b88; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x79b88; mov x0, x19]
uint64_t fde_sub_079bb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079BB4ULL;
}

// FDE #1817 | PC: 0x079bcc..0x079c7c (176 B) | Symbol: sub_079bcc
// EN: AArch64 prologue [sub sp, sp, #0x140; stp x28, x24, [sp, #0x100]; stp x23, x22, [sp, #0x110]; stp x21, x20, [sp, #0x120]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x140; stp x28, x24, [sp, #0x100]; stp x23, x22, [sp, #0x110]; stp x21, x20, [sp, #0x120]]
uint64_t fde_sub_079bcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA91063FCULL) << 32) | 0xD10503FFULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079BCCULL;
}

// FDE #1818 | PC: 0x079c7c..0x079ca0 (36 B) | Symbol: sub_079c7c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8ddf8; adrp x8, #0x9c000; add x8, x8, #0x3a0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8ddf8; adrp x8, #0x9c000; add x8, x8, #0x3a0]
uint64_t fde_sub_079c7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400505EULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079C7CULL;
}

// FDE #1819 | PC: 0x079ca0..0x079cb8 (24 B) | Symbol: sub_079ca0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x79c7c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x79c7c; mov x0, x19]
uint64_t fde_sub_079ca0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079CA0ULL;
}

// FDE #1820 | PC: 0x079cb8..0x079ed8 (544 B) | Symbol: sub_079cb8
// EN: AArch64 prologue [str x28, [sp, #-0x50]!; stp x25, x24, [sp, #0x10]; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x28, [sp, #-0x50]!; stp x25, x24, [sp, #0x10]; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]]
uint64_t fde_sub_079cb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90163F9ULL) << 32) | 0xF81B0FFCULL;
    const uint64_t kPcRange = 0x0220ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079CB8ULL;
}

// FDE #1821 | PC: 0x079ed8..0x079ef4 (28 B) | Symbol: sub_079ed8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8ddf8; adrp x8, #0x9c000; add x8, x8, #0x378] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8ddf8; adrp x8, #0x9c000; add x8, x8, #0x378]
uint64_t fde_sub_079ed8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94004FC7ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079ED8ULL;
}

// FDE #1822 | PC: 0x079ef4..0x079f0c (24 B) | Symbol: sub_079ef4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x79ed8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x79ed8; mov x0, x19]
uint64_t fde_sub_079ef4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079EF4ULL;
}

// FDE #1823 | PC: 0x079f0c..0x07a050 (324 B) | Symbol: sub_079f0c
// EN: AArch64 prologue [stp x28, x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_079f0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xA9BC63FCULL;
    const uint64_t kPcRange = 0x0144ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079F0CULL;
}

// FDE #1824 | PC: 0x07a050..0x07a070 (32 B) | Symbol: sub_07a050
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0xd0]; cbz x0, #0x7a064] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0xd0]; cbz x0, #0x7a064]
uint64_t fde_sub_07a050(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A050ULL;
}

// FDE #1825 | PC: 0x07a070..0x07a080 (16 B) | Symbol: sub_07a070
// EN: AArch64 prologue [adrp x8, #0x9c000; add x8, x8, #0x3f0; str x8, [x0], #8; b #0x7a050] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9c000; add x8, x8, #0x3f0; str x8, [x0], #8; b #0x7a050]
uint64_t fde_sub_07a070(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910FC108ULL) << 32) | 0xD0000108ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A070ULL;
}

// FDE #1826 | PC: 0x07a080..0x07a098 (24 B) | Symbol: sub_07a080
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7a070; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7a070; mov x0, x19]
uint64_t fde_sub_07a080(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A080ULL;
}

// FDE #1827 | PC: 0x07a098..0x07a1a0 (264 B) | Symbol: sub_07a098
// EN: AArch64 prologue [sub sp, sp, #0x190; str d8, [sp, #0x150]; stp x28, x22, [sp, #0x160]; stp x21, x20, [sp, #0x170]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x190; str d8, [sp, #0x150]; stp x28, x22, [sp, #0x160]; stp x21, x20, [sp, #0x170]]
uint64_t fde_sub_07a098(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD00ABE8ULL) << 32) | 0xD10643FFULL;
    const uint64_t kPcRange = 0x0108ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A098ULL;
}

// FDE #1828 | PC: 0x07a1a0..0x07a3fc (604 B) | Symbol: sub_07a1a0
// EN: AArch64 prologue [sub sp, sp, #0xa0; str x28, [sp, #0x40]; stp x27, x26, [sp, #0x50]; stp x25, x24, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; str x28, [sp, #0x40]; stp x27, x26, [sp, #0x50]; stp x25, x24, [sp, #0x60]]
uint64_t fde_sub_07a1a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023FCULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x025CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A1A0ULL;
}

// FDE #1829 | PC: 0x07a3fc..0x07a428 (44 B) | Symbol: sub_07a3fc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8eb7c; adrp x8, #0x9c000; add x8, x8, #0x418] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8eb7c; adrp x8, #0x9c000; add x8, x8, #0x418]
uint64_t fde_sub_07a3fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940051DFULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A3FCULL;
}

// FDE #1830 | PC: 0x07a428..0x07a440 (24 B) | Symbol: sub_07a428
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7a3fc; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7a3fc; mov x0, x19]
uint64_t fde_sub_07a428(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A428ULL;
}

// FDE #1831 | PC: 0x07a440..0x07a4a8 (104 B) | Symbol: sub_07a440
// EN: AArch64 prologue [sub sp, sp, #0x110; str x28, [sp, #0xe0]; stp x21, x20, [sp, #0xf0]; stp x19, x30, [sp, #0x100]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; str x28, [sp, #0xe0]; stp x21, x20, [sp, #0xf0]; stp x19, x30, [sp, #0x100]]
uint64_t fde_sub_07a440(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90073FCULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A440ULL;
}

// FDE #1832 | PC: 0x07a4a8..0x07a5a0 (248 B) | Symbol: sub_07a4a8
// EN: AArch64 prologue [sub sp, sp, #0xc0; stp x25, x24, [sp, #0x80]; stp x23, x22, [sp, #0x90]; stp x21, x20, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; stp x25, x24, [sp, #0x80]; stp x23, x22, [sp, #0x90]; stp x21, x20, [sp, #0xa0]]
uint64_t fde_sub_07a4a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90863F9ULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A4A8ULL;
}

// FDE #1833 | PC: 0x07a5a0..0x07a5d0 (48 B) | Symbol: sub_07a5a0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8ddf8; bl #0x44830; ldr x0, [x19, #0x10]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8ddf8; bl #0x44830; ldr x0, [x19, #0x10]]
uint64_t fde_sub_07a5a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94004E15ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A5A0ULL;
}

// FDE #1834 | PC: 0x07a5d0..0x07a5e0 (16 B) | Symbol: sub_07a5d0
// EN: AArch64 prologue [adrp x8, #0x9c000; add x8, x8, #0x440; str x8, [x0], #8; b #0x7a5a0] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9c000; add x8, x8, #0x440; str x8, [x0], #8; b #0x7a5a0]
uint64_t fde_sub_07a5d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91110108ULL) << 32) | 0xD0000108ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A5D0ULL;
}

// FDE #1835 | PC: 0x07a5e0..0x07a5f8 (24 B) | Symbol: sub_07a5e0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7a5d0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7a5d0; mov x0, x19]
uint64_t fde_sub_07a5e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A5E0ULL;
}

// FDE #1836 | PC: 0x07a5f8..0x07a6dc (228 B) | Symbol: sub_07a5f8
// EN: AArch64 prologue [str x28, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; sub sp, sp, #0x1f0] | VI: Khởi đầu hàm AArch64 [str x28, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; sub sp, sp, #0x1f0]
uint64_t fde_sub_07a5f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FFCULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A5F8ULL;
}

// FDE #1837 | PC: 0x07a6dc..0x07a718 (60 B) | Symbol: sub_07a6dc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x60]; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x60]; adrp x8, #0x9c000]
uint64_t fde_sub_07a6dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A6DCULL;
}

// FDE #1838 | PC: 0x07a718..0x07a730 (24 B) | Symbol: sub_07a718
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7a6dc; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7a6dc; mov x0, x19]
uint64_t fde_sub_07a718(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A718ULL;
}

// FDE #1839 | PC: 0x07a730..0x07a74c (28 B) | Symbol: sub_07a730
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x18]; bl #0x48d40] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x18]; bl #0x48d40]
uint64_t fde_sub_07a730(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A730ULL;
}

// FDE #1840 | PC: 0x07a74c..0x07a778 (44 B) | Symbol: sub_07a74c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8eb7c; adrp x8, #0x9c000; add x8, x8, #0x4e0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8eb7c; adrp x8, #0x9c000; add x8, x8, #0x4e0]
uint64_t fde_sub_07a74c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400510BULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A74CULL;
}

// FDE #1841 | PC: 0x07a778..0x07a790 (24 B) | Symbol: sub_07a778
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7a74c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7a74c; mov x0, x19]
uint64_t fde_sub_07a778(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A778ULL;
}

// FDE #1842 | PC: 0x07a790..0x07a828 (152 B) | Symbol: sub_07a790
// EN: AArch64 prologue [sub sp, sp, #0xb0; str x24, [sp, #0x70]; stp x23, x22, [sp, #0x80]; stp x21, x20, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; str x24, [sp, #0x70]; stp x23, x22, [sp, #0x80]; stp x21, x20, [sp, #0x90]]
uint64_t fde_sub_07a790(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9003BF8ULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A790ULL;
}

// FDE #1843 | PC: 0x07a828..0x07a838 (16 B) | Symbol: sub_07a828
// EN: AArch64 prologue [adrp x8, #0x9c000; add x8, x8, #0x508; str x8, [x0], #8; b #0x54044] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9c000; add x8, x8, #0x508; str x8, [x0], #8; b #0x54044]
uint64_t fde_sub_07a828(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91142108ULL) << 32) | 0xD0000108ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A828ULL;
}

// FDE #1844 | PC: 0x07a838..0x07a850 (24 B) | Symbol: sub_07a838
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7a828; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7a828; mov x0, x19]
uint64_t fde_sub_07a838(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A838ULL;
}

// FDE #1845 | PC: 0x07a850..0x07a998 (328 B) | Symbol: sub_07a850
// EN: AArch64 prologue [str d8, [sp, #-0x40]!; stp x28, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str d8, [sp, #-0x40]!; stp x28, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_07a850(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BFCULL) << 32) | 0xFC1C0FE8ULL;
    const uint64_t kPcRange = 0x0148ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A850ULL;
}

// FDE #1846 | PC: 0x07a998..0x07a9b8 (32 B) | Symbol: sub_07a998
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9c000; add x8, x8, #0x4b8; bl #0x8daa4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9c000; add x8, x8, #0x4b8; bl #0x8daa4]
uint64_t fde_sub_07a998(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000108ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A998ULL;
}

// FDE #1847 | PC: 0x07a9b8..0x07a9d0 (24 B) | Symbol: sub_07a9b8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7a998; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7a998; mov x0, x19]
uint64_t fde_sub_07a9b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A9B8ULL;
}

// FDE #1848 | PC: 0x07a9d0..0x07ab18 (328 B) | Symbol: sub_07a9d0
// EN: AArch64 prologue [str x28, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x28, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_07a9d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xF81C0FFCULL;
    const uint64_t kPcRange = 0x0148ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07A9D0ULL;
}

// FDE #1849 | PC: 0x07ab18..0x07ab40 (40 B) | Symbol: sub_07ab18
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0xe0]; bl #0x48d40] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0xe0]; bl #0x48d40]
uint64_t fde_sub_07ab18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07AB18ULL;
}

// FDE #1850 | PC: 0x07ab40..0x07ab50 (16 B) | Symbol: sub_07ab40
// EN: AArch64 prologue [adrp x8, #0x9c000; add x8, x8, #0x530; str x8, [x0], #8; b #0x7ab18] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9c000; add x8, x8, #0x530; str x8, [x0], #8; b #0x7ab18]
uint64_t fde_sub_07ab40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9114C108ULL) << 32) | 0xD0000108ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07AB40ULL;
}

// FDE #1851 | PC: 0x07ab50..0x07ab68 (24 B) | Symbol: sub_07ab50
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7ab40; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7ab40; mov x0, x19]
uint64_t fde_sub_07ab50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07AB50ULL;
}

// FDE #1852 | PC: 0x07ab68..0x07ad38 (464 B) | Symbol: sub_07ab68
// EN: AArch64 prologue [sub sp, sp, #0x1e0; str d8, [sp, #0x1a0]; stp x28, x22, [sp, #0x1b0]; stp x21, x20, [sp, #0x1c0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1e0; str d8, [sp, #0x1a0]; stp x28, x22, [sp, #0x1b0]; stp x21, x20, [sp, #0x1c0]]
uint64_t fde_sub_07ab68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD00D3E8ULL) << 32) | 0xD10783FFULL;
    const uint64_t kPcRange = 0x01D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07AB68ULL;
}

// FDE #1853 | PC: 0x07ad38..0x07ad58 (32 B) | Symbol: sub_07ad38
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9c000; add x8, x8, #0x490; bl #0x8daa4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9c000; add x8, x8, #0x490; bl #0x8daa4]
uint64_t fde_sub_07ad38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000108ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07AD38ULL;
}

// FDE #1854 | PC: 0x07ad58..0x07ad70 (24 B) | Symbol: sub_07ad58
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7ad38; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7ad38; mov x0, x19]
uint64_t fde_sub_07ad58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07AD58ULL;
}

// FDE #1855 | PC: 0x07ad70..0x07b040 (720 B) | Symbol: sub_07ad70
// EN: AArch64 prologue [str d8, [sp, #-0x50]!; stp x28, x24, [sp, #0x10]; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str d8, [sp, #-0x50]!; stp x28, x24, [sp, #0x10]; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]]
uint64_t fde_sub_07ad70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90163FCULL) << 32) | 0xFC1B0FE8ULL;
    const uint64_t kPcRange = 0x02D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07AD70ULL;
}

// FDE #1856 | PC: 0x07b040..0x07b070 (48 B) | Symbol: sub_07b040
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0xe8; bl #0x46c54] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0xe8; bl #0x46c54]
uint64_t fde_sub_07b040(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B040ULL;
}

// FDE #1857 | PC: 0x07b070..0x07b080 (16 B) | Symbol: sub_07b070
// EN: AArch64 prologue [adrp x8, #0x9c000; add x8, x8, #0x558; str x8, [x0], #8; b #0x7b040] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9c000; add x8, x8, #0x558; str x8, [x0], #8; b #0x7b040]
uint64_t fde_sub_07b070(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91156108ULL) << 32) | 0xB0000108ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B070ULL;
}

// FDE #1858 | PC: 0x07b080..0x07b098 (24 B) | Symbol: sub_07b080
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7b070; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7b070; mov x0, x19]
uint64_t fde_sub_07b080(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B080ULL;
}

// FDE #1859 | PC: 0x07b098..0x07b234 (412 B) | Symbol: sub_07b098
// EN: AArch64 prologue [sub sp, sp, #0x1d0; str d8, [sp, #0x190]; stp x28, x22, [sp, #0x1a0]; stp x21, x20, [sp, #0x1b0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1d0; str d8, [sp, #0x190]; stp x28, x22, [sp, #0x1a0]; stp x21, x20, [sp, #0x1b0]]
uint64_t fde_sub_07b098(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD00CBE8ULL) << 32) | 0xD10743FFULL;
    const uint64_t kPcRange = 0x019CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B098ULL;
}

// FDE #1860 | PC: 0x07b234..0x07b260 (44 B) | Symbol: sub_07b234
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8eb7c; adrp x8, #0x9c000; add x8, x8, #0x580] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8eb7c; adrp x8, #0x9c000; add x8, x8, #0x580]
uint64_t fde_sub_07b234(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94004E51ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B234ULL;
}

// FDE #1861 | PC: 0x07b260..0x07b278 (24 B) | Symbol: sub_07b260
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7b234; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7b234; mov x0, x19]
uint64_t fde_sub_07b260(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B260ULL;
}

// FDE #1862 | PC: 0x07b278..0x07b2ec (116 B) | Symbol: sub_07b278
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]; mrs x21, tpidr_el0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]; mrs x21, tpidr_el0]
uint64_t fde_sub_07b278(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90553F5ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B278ULL;
}

// FDE #1863 | PC: 0x07b2ec..0x07b310 (36 B) | Symbol: sub_07b2ec
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8ddf8; adrp x8, #0x9c000; add x8, x8, #0x5d0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8ddf8; adrp x8, #0x9c000; add x8, x8, #0x5d0]
uint64_t fde_sub_07b2ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94004AC2ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B2ECULL;
}

// FDE #1864 | PC: 0x07b310..0x07b328 (24 B) | Symbol: sub_07b310
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7b2ec; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7b2ec; mov x0, x19]
uint64_t fde_sub_07b310(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B310ULL;
}

// FDE #1865 | PC: 0x07b328..0x07b4d8 (432 B) | Symbol: sub_07b328
// EN: AArch64 prologue [stp x28, x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_07b328(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xA9BC63FCULL;
    const uint64_t kPcRange = 0x01B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B328ULL;
}

// FDE #1866 | PC: 0x07b4d8..0x07b4f4 (28 B) | Symbol: sub_07b4d8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8ddf8; adrp x8, #0x9c000; add x8, x8, #0x5a8] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8ddf8; adrp x8, #0x9c000; add x8, x8, #0x5a8]
uint64_t fde_sub_07b4d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94004A47ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B4D8ULL;
}

// FDE #1867 | PC: 0x07b4f4..0x07b50c (24 B) | Symbol: sub_07b4f4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7b4d8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7b4d8; mov x0, x19]
uint64_t fde_sub_07b4f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B4F4ULL;
}

// FDE #1868 | PC: 0x07b50c..0x07b778 (620 B) | Symbol: sub_07b50c
// EN: AArch64 prologue [stp x28, x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_07b50c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xA9BC63FCULL;
    const uint64_t kPcRange = 0x026CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B50CULL;
}

// FDE #1869 | PC: 0x07b778..0x07b788 (16 B) | Symbol: sub_07b778
// EN: AArch64 prologue [adrp x8, #0x9c000; add x8, x8, #0x5f8; str x8, [x0], #8; b #0x7a050] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9c000; add x8, x8, #0x5f8; str x8, [x0], #8; b #0x7a050]
uint64_t fde_sub_07b778(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9117E108ULL) << 32) | 0xB0000108ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B778ULL;
}

// FDE #1870 | PC: 0x07b788..0x07b7a0 (24 B) | Symbol: sub_07b788
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7b778; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7b778; mov x0, x19]
uint64_t fde_sub_07b788(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B788ULL;
}

// FDE #1871 | PC: 0x07b7a0..0x07b8a8 (264 B) | Symbol: sub_07b7a0
// EN: AArch64 prologue [sub sp, sp, #0x190; str d8, [sp, #0x150]; stp x28, x22, [sp, #0x160]; stp x21, x20, [sp, #0x170]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x190; str d8, [sp, #0x150]; stp x28, x22, [sp, #0x160]; stp x21, x20, [sp, #0x170]]
uint64_t fde_sub_07b7a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD00ABE8ULL) << 32) | 0xD10643FFULL;
    const uint64_t kPcRange = 0x0108ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B7A0ULL;
}

// FDE #1872 | PC: 0x07b8a8..0x07b9bc (276 B) | Symbol: sub_07b8a8
// EN: AArch64 prologue [sub sp, sp, #0x50; str x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_07b8a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B8A8ULL;
}

// FDE #1873 | PC: 0x07b9bc..0x07bab4 (248 B) | Symbol: sub_07b9bc
// EN: AArch64 prologue [sub sp, sp, #0x50; str x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_07b9bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07B9BCULL;
}

// FDE #1874 | PC: 0x07bab4..0x07bb90 (220 B) | Symbol: sub_07bab4
// EN: AArch64 prologue [sub sp, sp, #0x50; str x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_07bab4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07BAB4ULL;
}

// FDE #1875 | PC: 0x07bb90..0x07bbfc (108 B) | Symbol: sub_07bb90
// EN: AArch64 prologue [sub sp, sp, #0x40; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8ee78] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8ee78]
uint64_t fde_sub_07bb90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F4ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07BB90ULL;
}

// FDE #1876 | PC: 0x07bbfc..0x07bc34 (56 B) | Symbol: sub_07bbfc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x1; adrp x1, #0x1f000; add x1, x1, #0x701] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x1; adrp x1, #0x1f000; add x1, x1, #0x701]
uint64_t fde_sub_07bbfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07BBFCULL;
}

// FDE #1877 | PC: 0x07bc34..0x07bd74 (320 B) | Symbol: sub_07bc34
// EN: AArch64 prologue [mov x2, x30; bl #0x8e8e8; mov x30, x2; stp x29, x30, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8e8e8; mov x30, x2; stp x29, x30, [sp, #0x80]]
uint64_t fde_sub_07bc34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94004B2CULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0140ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07BC34ULL;
}

// FDE #1878 | PC: 0x07bd74..0x07bda4 (48 B) | Symbol: _ZN4lynx6animax7RawData11MakeRawDataEPKvmPFvS3_ES3_
// EN: AArch64 prologue [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x22, x0] | VI: Khởi đầu hàm AArch64 [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x22, x0]
uint64_t fde_sub_07bd74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xA9BD5BF7ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07BD74ULL;
}

// FDE #1879 | PC: 0x07bda4..0x07bdb0 (12 B) | Symbol: _ZN4lynx6animax7RawDataC2EPKvmPFvS3_ES3_
// EN: AArch64 prologue [stp x1, x2, [x0]; stp x3, x4, [x0, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [stp x1, x2, [x0]; stp x3, x4, [x0, #0x10]; ret]
uint64_t fde_sub_07bda4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9011003ULL) << 32) | 0xA9000801ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07BDA4ULL;
}

// FDE #1880 | PC: 0x07bdb0..0x07bef0 (320 B) | Symbol: sub_07bdb0
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x0]
uint64_t fde_sub_07bdb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0140ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07BDB0ULL;
}

// FDE #1881 | PC: 0x07bef0..0x07bfc8 (216 B) | Symbol: sub_07bef0
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldrb w8, [x0]; ldp x9, x10, [x0, #8]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldrb w8, [x0]; ldp x9, x10, [x0, #8]]
uint64_t fde_sub_07bef0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07BEF0ULL;
}

// FDE #1882 | PC: 0x07bfc8..0x07c00c (68 B) | Symbol: sub_07bfc8
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x22, x0] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x22, x0]
uint64_t fde_sub_07bfc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07BFC8ULL;
}

// FDE #1883 | PC: 0x07c00c..0x07c2d4 (712 B) | Symbol: sub_07c00c
// EN: AArch64 prologue [sub sp, sp, #0xf0; str x24, [sp, #0xb0]; stp x23, x22, [sp, #0xc0]; stp x21, x20, [sp, #0xd0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xf0; str x24, [sp, #0xb0]; stp x23, x22, [sp, #0xc0]; stp x21, x20, [sp, #0xd0]]
uint64_t fde_sub_07c00c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9005BF8ULL) << 32) | 0xD103C3FFULL;
    const uint64_t kPcRange = 0x02C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C00CULL;
}

// FDE #1884 | PC: 0x07c2d4..0x07c308 (52 B) | Symbol: sub_07c2d4
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e108; cmp x20, x21] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e108; cmp x20, x21]
uint64_t fde_sub_07c2d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C2D4ULL;
}

// FDE #1885 | PC: 0x07c308..0x07c34c (68 B) | Symbol: sub_07c308
// EN: AArch64 prologue [sub sp, sp, #0x90; str x30, [sp, #0x80]; ldrb w8, [x0]; ldr x9, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x30, [sp, #0x80]; ldrb w8, [x0]; ldr x9, [x0, #0x10]]
uint64_t fde_sub_07c308(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90043FEULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C308ULL;
}

// FDE #1886 | PC: 0x07c34c..0x07c3e4 (152 B) | Symbol: sub_07c34c
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8f2dc] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8f2dc]
uint64_t fde_sub_07c34c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C34CULL;
}

// FDE #1887 | PC: 0x07c3e4..0x07c460 (124 B) | Symbol: sub_07c3e4
// EN: AArch64 prologue [sub sp, sp, #0x150; stp x28, x20, [sp, #0x130]; stp x19, x30, [sp, #0x140]; bl #0x8dab0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x150; stp x28, x20, [sp, #0x130]; stp x19, x30, [sp, #0x140]; bl #0x8dab0]
uint64_t fde_sub_07c3e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA91353FCULL) << 32) | 0xD10543FFULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C3E4ULL;
}

// FDE #1888 | PC: 0x07c460..0x07c63c (476 B) | Symbol: sub_07c460
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x27, x26, [sp, #0x60]; stp x25, x24, [sp, #0x70]; stp x23, x22, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x27, x26, [sp, #0x60]; stp x25, x24, [sp, #0x70]; stp x23, x22, [sp, #0x80]]
uint64_t fde_sub_07c460(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9066BFBULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x01DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C460ULL;
}

// FDE #1889 | PC: 0x07c63c..0x07c6cc (144 B) | Symbol: sub_07c63c
// EN: AArch64 prologue [mov x2, x30; bl #0x90b54; mov x30, x2; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x90b54; mov x30, x2; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_07c63c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94005145ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C63CULL;
}

// FDE #1890 | PC: 0x07c6cc..0x07c76c (160 B) | Symbol: sub_07c6cc
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x19, x30, [sp, #0x60]; bl #0x8f760; str x8, [sp, #0x58]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x19, x30, [sp, #0x60]; bl #0x8f760; str x8, [sp, #0x58]]
uint64_t fde_sub_07c6cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9067BF3ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C6CCULL;
}

// FDE #1891 | PC: 0x07c76c..0x07c7bc (80 B) | Symbol: sub_07c76c
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e4a4; mov w21, w0] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e4a4; mov w21, w0]
uint64_t fde_sub_07c76c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C76CULL;
}

// FDE #1892 | PC: 0x07c7bc..0x07c7cc (16 B) | Symbol: sub_07c7bc
// EN: AArch64 prologue [ldr x1, [x0, #0x10]; adrp x8, #0x9c000; add x8, x8, #0x690; b #0x9193c] | VI: Khởi đầu hàm AArch64 [ldr x1, [x0, #0x10]; adrp x8, #0x9c000; add x8, x8, #0x690; b #0x9193c]
uint64_t fde_sub_07c7bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000108ULL) << 32) | 0xF9400801ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C7BCULL;
}

// FDE #1893 | PC: 0x07c7cc..0x07c8e0 (276 B) | Symbol: sub_07c7cc
// EN: AArch64 prologue [sub sp, sp, #0x90; str x26, [sp, #0x40]; stp x25, x24, [sp, #0x50]; stp x23, x22, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x26, [sp, #0x40]; stp x25, x24, [sp, #0x50]; stp x23, x22, [sp, #0x60]]
uint64_t fde_sub_07c7cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023FAULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C7CCULL;
}

// FDE #1894 | PC: 0x07c8e0..0x07c8fc (28 B) | Symbol: sub_07c8e0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x2; bl #0x4db0c; adrp x8, #0xa0000] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x2; bl #0x4db0c; adrp x8, #0xa0000]
uint64_t fde_sub_07c8e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0203F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C8E0ULL;
}

// FDE #1895 | PC: 0x07c8fc..0x07c9b4 (184 B) | Symbol: sub_07c8fc
// EN: AArch64 prologue [sub sp, sp, #0x90; str x30, [sp, #0x80]; mrs x8, tpidr_el0; ldr x9, [x8, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x30, [sp, #0x80]; mrs x8, tpidr_el0; ldr x9, [x8, #0x28]]
uint64_t fde_sub_07c8fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90043FEULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C8FCULL;
}

// FDE #1896 | PC: 0x07c9b4..0x07cbc0 (524 B) | Symbol: sub_07c9b4
// EN: AArch64 prologue [sub sp, sp, #0x150; stp x28, x20, [sp, #0x130]; stp x19, x30, [sp, #0x140]; mrs x19, tpidr_el0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x150; stp x28, x20, [sp, #0x130]; stp x19, x30, [sp, #0x140]; mrs x19, tpidr_el0]
uint64_t fde_sub_07c9b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA91353FCULL) << 32) | 0xD10543FFULL;
    const uint64_t kPcRange = 0x020CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C9B4ULL;
}

// FDE #1897 | PC: 0x07cbc0..0x07cc3c (124 B) | Symbol: sub_07cbc0
// EN: AArch64 prologue [sub sp, sp, #0x50; str x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_07cbc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07CBC0ULL;
}

// FDE #1898 | PC: 0x07cc3c..0x07cc5c (32 B) | Symbol: sub_07cc3c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x93c40; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x93c40; adrp x8, #0x9c000]
uint64_t fde_sub_07cc3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07CC3CULL;
}

// FDE #1899 | PC: 0x07cc5c..0x07cc88 (44 B) | Symbol: sub_07cc5c
// EN: AArch64 prologue [sub sp, sp, #0x120; str x28, [sp, #0x100]; stp x19, x30, [sp, #0x110]; bl #0x8d3e8] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; str x28, [sp, #0x100]; stp x19, x30, [sp, #0x110]; bl #0x8d3e8]
uint64_t fde_sub_07cc5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90083FCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07CC5CULL;
}

// FDE #1900 | PC: 0x07cc88..0x07cca4 (28 B) | Symbol: sub_07cc88
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x90600; bl #0x91828] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x90600; bl #0x91828]
uint64_t fde_sub_07cc88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07CC88ULL;
}

// FDE #1901 | PC: 0x07cca4..0x07ccd8 (52 B) | Symbol: sub_07cca4
// EN: AArch64 prologue [sub sp, sp, #0x120; str x28, [sp, #0x100]; stp x19, x30, [sp, #0x110]; bl #0x8d3e8] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; str x28, [sp, #0x100]; stp x19, x30, [sp, #0x110]; bl #0x8d3e8]
uint64_t fde_sub_07cca4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90083FCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07CCA4ULL;
}

// FDE #1902 | PC: 0x07ccd8..0x07ce1c (324 B) | Symbol: sub_07ccd8
// EN: AArch64 prologue [sub sp, sp, #0xa0; str x22, [sp, #0x70]; stp x21, x20, [sp, #0x80]; stp x19, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; str x22, [sp, #0x70]; stp x21, x20, [sp, #0x80]; stp x19, x30, [sp, #0x90]]
uint64_t fde_sub_07ccd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9003BF6ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x0144ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07CCD8ULL;
}

// FDE #1903 | PC: 0x07ce1c..0x07ce48 (44 B) | Symbol: sub_07ce1c
// EN: AArch64 prologue [sub sp, sp, #0x120; str x28, [sp, #0x100]; stp x19, x30, [sp, #0x110]; bl #0x8d3e8] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; str x28, [sp, #0x100]; stp x19, x30, [sp, #0x110]; bl #0x8d3e8]
uint64_t fde_sub_07ce1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90083FCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07CE1CULL;
}

// FDE #1904 | PC: 0x07ce48..0x07ce74 (44 B) | Symbol: sub_07ce48
// EN: AArch64 prologue [sub sp, sp, #0x120; str x28, [sp, #0x100]; stp x19, x30, [sp, #0x110]; bl #0x8d3e8] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; str x28, [sp, #0x100]; stp x19, x30, [sp, #0x110]; bl #0x8d3e8]
uint64_t fde_sub_07ce48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90083FCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07CE48ULL;
}

// FDE #1905 | PC: 0x07ce74..0x07ce98 (36 B) | Symbol: sub_07ce74
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x90600; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x90600; adrp x8, #0x9c000]
uint64_t fde_sub_07ce74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07CE74ULL;
}

// FDE #1906 | PC: 0x07ce98..0x07cf14 (124 B) | Symbol: sub_07ce98
// EN: AArch64 prologue [sub sp, sp, #0x50; str x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_07ce98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07CE98ULL;
}

// FDE #1907 | PC: 0x07cf14..0x07d0a8 (404 B) | Symbol: sub_07cf14
// EN: AArch64 prologue [sub sp, sp, #0xd0; stp x23, x22, [sp, #0xa0]; stp x21, x20, [sp, #0xb0]; stp x19, x30, [sp, #0xc0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xd0; stp x23, x22, [sp, #0xa0]; stp x21, x20, [sp, #0xb0]; stp x19, x30, [sp, #0xc0]]
uint64_t fde_sub_07cf14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90A5BF7ULL) << 32) | 0xD10343FFULL;
    const uint64_t kPcRange = 0x0194ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07CF14ULL;
}

// FDE #1908 | PC: 0x07d0a8..0x07d0bc (20 B) | Symbol: sub_07d0a8
// EN: AArch64 prologue [ldrb w8, [x1]; ldr x9, [x1, #0x10]; tst w8, #1; csinc x1, x9, x1, ne] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x1]; ldr x9, [x1, #0x10]; tst w8, #1; csinc x1, x9, x1, ne]
uint64_t fde_sub_07d0a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400829ULL) << 32) | 0x39400028ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07D0A8ULL;
}

// FDE #1909 | PC: 0x07d0bc..0x07d158 (156 B) | Symbol: sub_07d0bc
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_07d0bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9025BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07D0BCULL;
}

// FDE #1910 | PC: 0x07d158..0x07d204 (172 B) | Symbol: sub_07d158
// EN: AArch64 prologue [sub sp, sp, #0x50; str d8, [sp, #0x20]; str x22, [sp, #0x28]; stp x21, x20, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str d8, [sp, #0x20]; str x22, [sp, #0x28]; stp x21, x20, [sp, #0x30]]
uint64_t fde_sub_07d158(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0013E8ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07D158ULL;
}

// FDE #1911 | PC: 0x07d204..0x07d454 (592 B) | Symbol: sub_07d204
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x25, x24, [sp, #0x50]; stp x23, x22, [sp, #0x60]; stp x21, x20, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x25, x24, [sp, #0x50]; stp x23, x22, [sp, #0x60]; stp x21, x20, [sp, #0x70]]
uint64_t fde_sub_07d204(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90563F9ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0250ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07D204ULL;
}

// FDE #1912 | PC: 0x07d454..0x07d488 (52 B) | Symbol: sub_07d454
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; subs x19, x1, x0; mov x20, x2] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; subs x19, x1, x0; mov x20, x2]
uint64_t fde_sub_07d454(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07D454ULL;
}

// FDE #1913 | PC: 0x07d488..0x07d4bc (52 B) | Symbol: sub_07d488
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; tbnz x1, #0x3f, #0x7d4b8; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; tbnz x1, #0x3f, #0x7d4b8; mov x19, x0]
uint64_t fde_sub_07d488(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07D488ULL;
}

// FDE #1914 | PC: 0x07d4bc..0x07d53c (128 B) | Symbol: sub_07d4bc
// EN: AArch64 prologue [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]]
uint64_t fde_sub_07d4bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9009BFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07D4BCULL;
}

// FDE #1915 | PC: 0x07d53c..0x07d5b8 (124 B) | Symbol: sub_07d53c
// EN: AArch64 prologue [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]]
uint64_t fde_sub_07d53c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9009BFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07D53CULL;
}

// FDE #1916 | PC: 0x07d5b8..0x07d5c8 (16 B) | Symbol: _ZN4lynx6animax20AnimaXAbilityAndroidC2EP7_JNIEnvP8_jobject
// EN: AArch64 prologue [adrp x8, #0x9c000; add x8, x8, #0x6f8; str x8, [x0], #8; b #0x7d5c8] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9c000; add x8, x8, #0x6f8; str x8, [x0], #8; b #0x7d5c8]
uint64_t fde_sub_07d5b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911BE108ULL) << 32) | 0xF00000E8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07D5B8ULL;
}

// FDE #1917 | PC: 0x07d5c8..0x07d5ec (36 B) | Symbol: sub_07d5c8
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x90eb8; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x90eb8; adrp x8, #0x9c000]
uint64_t fde_sub_07d5c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07D5C8ULL;
}

// FDE #1918 | PC: 0x07d5ec..0x07d5f8 (12 B) | Symbol: sub_07d5ec
// EN: AArch64 prologue [adrp x8, #0x9c000; add x8, x8, #0x6f8; b #0x9224c] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9c000; add x8, x8, #0x6f8; b #0x9224c]
uint64_t fde_sub_07d5ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911BE108ULL) << 32) | 0xF00000E8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07D5ECULL;
}

// FDE #1919 | PC: 0x07d5f8..0x07d610 (24 B) | Symbol: sub_07d5f8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7d5ec; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7d5ec; mov x0, x19]
uint64_t fde_sub_07d5f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07D5F8ULL;
}

// FDE #1920 | PC: 0x07d610..0x07d624 (20 B) | Symbol: sub_07d610
// EN: AArch64 prologue [adrp x8, #0x9c000; add x8, x8, #0x6d0; mov x1, xzr; str x8, [x0]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9c000; add x8, x8, #0x6d0; mov x1, xzr; str x8, [x0]]
uint64_t fde_sub_07d610(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911B4108ULL) << 32) | 0xF00000E8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07D610ULL;
}

// FDE #1921 | PC: 0x07d624..0x07d698 (116 B) | Symbol: _ZN4lynx6animax20AnimaXAbilityAndroid9SendEventEhP8_jobject
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x2] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x2]
uint64_t fde_sub_07d624(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07D624ULL;
}

// FDE #1922 | PC: 0x07d698..0x07d6e4 (76 B) | Symbol: _ZNK4lynx6animax20AnimaXAbilityAndroid21DisableByteVC1DecoderEv
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8fb64; adrp x5, #0xa0000] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8fb64; adrp x5, #0xa0000]
uint64_t fde_sub_07d698(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07D698ULL;
}

// FDE #1923 | PC: 0x07d6e4..0x07d710 (44 B) | Symbol: sub_07d6e4
// EN: AArch64 prologue [sub sp, sp, #0x120; str x28, [sp, #0x100]; stp x19, x30, [sp, #0x110]; bl #0x8d3e8] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; str x28, [sp, #0x100]; stp x19, x30, [sp, #0x110]; bl #0x8d3e8]
uint64_t fde_sub_07d6e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90083FCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07D6E4ULL;
}

// FDE #1924 | PC: 0x07d710..0x07d778 (104 B) | Symbol: _ZNK4lynx6animax20AnimaXAbilityAndroid17CreateVideoPlayerEl
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8e128] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8e128]
uint64_t fde_sub_07d710(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07D710ULL;
}

// FDE #1925 | PC: 0x07d778..0x07d7b0 (56 B) | Symbol: sub_07d778
// EN: AArch64 prologue [sub sp, sp, #0x120; str x28, [sp, #0x100]; stp x19, x30, [sp, #0x110]; bl #0x8d3e8] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; str x28, [sp, #0x100]; stp x19, x30, [sp, #0x110]; bl #0x8d3e8]
uint64_t fde_sub_07d778(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90083FCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07D778ULL;
}

// FDE #1926 | PC: 0x07d7b0..0x07d86c (188 B) | Symbol: sub_07d7b0
// EN: AArch64 prologue [sub sp, sp, #0x170; str x28, [sp, #0x130]; stp x23, x22, [sp, #0x140]; stp x21, x20, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; str x28, [sp, #0x130]; stp x23, x22, [sp, #0x140]; stp x21, x20, [sp, #0x150]]
uint64_t fde_sub_07d7b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9009BFCULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07D7B0ULL;
}

// FDE #1927 | PC: 0x07d86c..0x07d9e8 (380 B) | Symbol: sub_07d86c
// EN: AArch64 prologue [sub sp, sp, #0x160; stp x28, x22, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; stp x28, x22, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]]
uint64_t fde_sub_07d86c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9135BFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x017CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07D86CULL;
}

// FDE #1928 | PC: 0x07d9e8..0x07dae4 (252 B) | Symbol: sub_07d9e8
// EN: AArch64 prologue [sub sp, sp, #0x80; str x22, [sp, #0x50]; stp x21, x20, [sp, #0x60]; stp x19, x30, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x22, [sp, #0x50]; stp x21, x20, [sp, #0x60]; stp x19, x30, [sp, #0x70]]
uint64_t fde_sub_07d9e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9002BF6ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07D9E8ULL;
}

// FDE #1929 | PC: 0x07dae4..0x07de70 (908 B) | Symbol: sub_07dae4
// EN: AArch64 prologue [sub sp, sp, #0x140; str d8, [sp, #0xe0]; stp x28, x26, [sp, #0xf0]; stp x25, x24, [sp, #0x100]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x140; str d8, [sp, #0xe0]; stp x28, x26, [sp, #0xf0]; stp x25, x24, [sp, #0x100]]
uint64_t fde_sub_07dae4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0073E8ULL) << 32) | 0xD10503FFULL;
    const uint64_t kPcRange = 0x038CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07DAE4ULL;
}

// FDE #1930 | PC: 0x07de70..0x07df40 (208 B) | Symbol: sub_07de70
// EN: AArch64 prologue [sub sp, sp, #0x170; stp x28, x24, [sp, #0x130]; stp x23, x22, [sp, #0x140]; stp x21, x20, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; stp x28, x24, [sp, #0x130]; stp x23, x22, [sp, #0x140]; stp x21, x20, [sp, #0x150]]
uint64_t fde_sub_07de70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA91363FCULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07DE70ULL;
}

// FDE #1931 | PC: 0x07df40..0x07e010 (208 B) | Symbol: sub_07df40
// EN: AArch64 prologue [sub sp, sp, #0x170; stp x28, x24, [sp, #0x130]; stp x23, x22, [sp, #0x140]; stp x21, x20, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; stp x28, x24, [sp, #0x130]; stp x23, x22, [sp, #0x140]; stp x21, x20, [sp, #0x150]]
uint64_t fde_sub_07df40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA91363FCULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07DF40ULL;
}

// FDE #1932 | PC: 0x07e010..0x07e020 (16 B) | Symbol: sub_07e010
// EN: AArch64 prologue [ldr x0, [x2]; tst w3, #0xff; cset w1, ne; b #0x93d70] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2]; tst w3, #0xff; cset w1, ne; b #0x93d70]
uint64_t fde_sub_07e010(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72001C7FULL) << 32) | 0xF9400040ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E010ULL;
}

// FDE #1933 | PC: 0x07e020..0x07e02c (12 B) | Symbol: sub_07e020
// EN: AArch64 prologue [ldr x0, [x2]; fcvt d0, s0; b #0x93d80] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2]; fcvt d0, s0; b #0x93d80]
uint64_t fde_sub_07e020(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E22C000ULL) << 32) | 0xF9400040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E020ULL;
}

// FDE #1934 | PC: 0x07e02c..0x07e038 (12 B) | Symbol: sub_07e02c
// EN: AArch64 prologue [ldr x0, [x2]; fcvt d0, s0; b #0x93d90] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2]; fcvt d0, s0; b #0x93d90]
uint64_t fde_sub_07e02c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E22C000ULL) << 32) | 0xF9400040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E02CULL;
}

// FDE #1935 | PC: 0x07e038..0x07e044 (12 B) | Symbol: sub_07e038
// EN: AArch64 prologue [ldr x0, [x2]; mov w1, w3; b #0x93da0] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2]; mov w1, w3; b #0x93da0]
uint64_t fde_sub_07e038(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A0303E1ULL) << 32) | 0xF9400040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E038ULL;
}

// FDE #1936 | PC: 0x07e044..0x07e050 (12 B) | Symbol: sub_07e044
// EN: AArch64 prologue [ldr x0, [x2]; mov w1, w3; b #0x93db0] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2]; mov w1, w3; b #0x93db0]
uint64_t fde_sub_07e044(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A0303E1ULL) << 32) | 0xF9400040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E044ULL;
}

// FDE #1937 | PC: 0x07e050..0x07e060 (16 B) | Symbol: sub_07e050
// EN: AArch64 prologue [ldr x0, [x2]; tst w3, #0xff; cset w1, ne; b #0x93dc0] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2]; tst w3, #0xff; cset w1, ne; b #0x93dc0]
uint64_t fde_sub_07e050(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72001C7FULL) << 32) | 0xF9400040ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E050ULL;
}

// FDE #1938 | PC: 0x07e060..0x07e0c4 (100 B) | Symbol: sub_07e060
// EN: AArch64 prologue [cbz x3, #0x7e0c0; stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [cbz x3, #0x7e0c0; stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x8, [x0]]
uint64_t fde_sub_07e060(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE53F5ULL) << 32) | 0xB4000303ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E060ULL;
}

// FDE #1939 | PC: 0x07e0c4..0x07e0d4 (16 B) | Symbol: sub_07e0c4
// EN: AArch64 prologue [ldr x0, [x2]; tst w3, #0xff; cset w1, ne; b #0x93de0] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2]; tst w3, #0xff; cset w1, ne; b #0x93de0]
uint64_t fde_sub_07e0c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72001C7FULL) << 32) | 0xF9400040ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E0C4ULL;
}

// FDE #1940 | PC: 0x07e0d4..0x07e0e0 (12 B) | Symbol: sub_07e0d4
// EN: AArch64 prologue [ldr x0, [x2]; mov w1, w3; b #0x93df0] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2]; mov w1, w3; b #0x93df0]
uint64_t fde_sub_07e0d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A0303E1ULL) << 32) | 0xF9400040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E0D4ULL;
}

// FDE #1941 | PC: 0x07e0e0..0x07e134 (84 B) | Symbol: sub_07e0e0
// EN: AArch64 prologue [sub sp, sp, #0x40; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; mrs x20, tpidr_el0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; mrs x20, tpidr_el0]
uint64_t fde_sub_07e0e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F4ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E0E0ULL;
}

// FDE #1942 | PC: 0x07e134..0x07e178 (68 B) | Symbol: sub_07e134
// EN: AArch64 prologue [cbz x3, #0x7e174; sub sp, sp, #0x20; ldr x8, [x3]; ldr x0, [x2]] | VI: Khởi đầu hàm AArch64 [cbz x3, #0x7e174; sub sp, sp, #0x20; ldr x8, [x3]; ldr x0, [x2]]
uint64_t fde_sub_07e134(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10083FFULL) << 32) | 0xB4000203ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E134ULL;
}

// FDE #1943 | PC: 0x07e178..0x07e1ec (116 B) | Symbol: sub_07e178
// EN: AArch64 prologue [sub sp, sp, #0x60; str x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]; mrs x20, tpidr_el0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]; mrs x20, tpidr_el0]
uint64_t fde_sub_07e178(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F4ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E178ULL;
}

// FDE #1944 | PC: 0x07e1ec..0x07e698 (1196 B) | Symbol: sub_07e1ec
// EN: AArch64 prologue [sub sp, sp, #0x170; stp x28, x27, [sp, #0x110]; stp x26, x25, [sp, #0x120]; stp x24, x23, [sp, #0x130]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; stp x28, x27, [sp, #0x110]; stp x26, x25, [sp, #0x120]; stp x24, x23, [sp, #0x130]]
uint64_t fde_sub_07e1ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9116FFCULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x04ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E1ECULL;
}

// FDE #1945 | PC: 0x07e698..0x07e6a4 (12 B) | Symbol: sub_07e698
// EN: AArch64 prologue [ldr x0, [x2]; scvtf d0, w3; b #0x93e50] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2]; scvtf d0, w3; b #0x93e50]
uint64_t fde_sub_07e698(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E620060ULL) << 32) | 0xF9400040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E698ULL;
}

// FDE #1946 | PC: 0x07e6a4..0x07e6b0 (12 B) | Symbol: sub_07e6a4
// EN: AArch64 prologue [ldr x0, [x2]; scvtf d0, w3; b #0x93e60] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2]; scvtf d0, w3; b #0x93e60]
uint64_t fde_sub_07e6a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E620060ULL) << 32) | 0xF9400040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E6A4ULL;
}

// FDE #1947 | PC: 0x07e6b0..0x07e6c0 (16 B) | Symbol: sub_07e6b0
// EN: AArch64 prologue [ldr x0, [x2]; tst w3, #0xff; cset w1, ne; b #0x93e70] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2]; tst w3, #0xff; cset w1, ne; b #0x93e70]
uint64_t fde_sub_07e6b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72001C7FULL) << 32) | 0xF9400040ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E6B0ULL;
}

// FDE #1948 | PC: 0x07e6c0..0x07e6c8 (8 B) | Symbol: sub_07e6c0
// EN: AArch64 prologue [ldr x0, [x2]; b #0x93e80] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2]; b #0x93e80]
uint64_t fde_sub_07e6c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140055EFULL) << 32) | 0xF9400040ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E6C0ULL;
}

// FDE #1949 | PC: 0x07e6c8..0x07e6d0 (8 B) | Symbol: sub_07e6c8
// EN: AArch64 prologue [ldr x0, [x2]; b #0x93e90] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2]; b #0x93e90]
uint64_t fde_sub_07e6c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140055F1ULL) << 32) | 0xF9400040ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E6C8ULL;
}

// FDE #1950 | PC: 0x07e6d0..0x07e6d8 (8 B) | Symbol: sub_07e6d0
// EN: AArch64 prologue [ldr x0, [x2]; b #0x93ea0] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2]; b #0x93ea0]
uint64_t fde_sub_07e6d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140055F3ULL) << 32) | 0xF9400040ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E6D0ULL;
}

// FDE #1951 | PC: 0x07e6d8..0x07e6e0 (8 B) | Symbol: sub_07e6d8
// EN: AArch64 prologue [ldr x0, [x2]; b #0x93eb0] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2]; b #0x93eb0]
uint64_t fde_sub_07e6d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140055F5ULL) << 32) | 0xF9400040ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E6D8ULL;
}

// FDE #1952 | PC: 0x07e6e0..0x07e6e8 (8 B) | Symbol: sub_07e6e0
// EN: AArch64 prologue [ldr x0, [x2]; b #0x93ec0] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2]; b #0x93ec0]
uint64_t fde_sub_07e6e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140055F7ULL) << 32) | 0xF9400040ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E6E0ULL;
}

// FDE #1953 | PC: 0x07e6e8..0x07e700 (24 B) | Symbol: sub_07e6e8
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; ldr x0, [x2]; bl #0x93ed0; and w0, w0, #1] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; ldr x0, [x2]; bl #0x93ed0; and w0, w0, #1]
uint64_t fde_sub_07e6e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400040ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E6E8ULL;
}

// FDE #1954 | PC: 0x07e700..0x07e70c (12 B) | Symbol: sub_07e700
// EN: AArch64 prologue [ldr x0, [x2]; scvtf d0, w3; b #0x93ee0] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2]; scvtf d0, w3; b #0x93ee0]
uint64_t fde_sub_07e700(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E620060ULL) << 32) | 0xF9400040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E700ULL;
}

// FDE #1955 | PC: 0x07e70c..0x07e718 (12 B) | Symbol: sub_07e70c
// EN: AArch64 prologue [ldr x0, [x2]; mov w1, w3; b #0x93ef0] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2]; mov w1, w3; b #0x93ef0]
uint64_t fde_sub_07e70c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A0303E1ULL) << 32) | 0xF9400040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E70CULL;
}

// FDE #1956 | PC: 0x07e718..0x07e724 (12 B) | Symbol: sub_07e718
// EN: AArch64 prologue [ldr x0, [x2]; mov w1, w3; b #0x93f00] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2]; mov w1, w3; b #0x93f00]
uint64_t fde_sub_07e718(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A0303E1ULL) << 32) | 0xF9400040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E718ULL;
}

// FDE #1957 | PC: 0x07e724..0x07e820 (252 B) | Symbol: sub_07e724
// EN: AArch64 prologue [sub sp, sp, #0xb0; str x26, [sp, #0x60]; stp x25, x24, [sp, #0x70]; stp x23, x22, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; str x26, [sp, #0x60]; stp x25, x24, [sp, #0x70]; stp x23, x22, [sp, #0x80]]
uint64_t fde_sub_07e724(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90033FAULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E724ULL;
}

// FDE #1958 | PC: 0x07e820..0x07e828 (8 B) | Symbol: sub_07e820
// EN: AArch64 prologue [ldr x0, [x2]; b #0x93f20] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2]; b #0x93f20]
uint64_t fde_sub_07e820(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140055BFULL) << 32) | 0xF9400040ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E820ULL;
}

// FDE #1959 | PC: 0x07e828..0x07e838 (16 B) | Symbol: sub_07e828
// EN: AArch64 prologue [ldr x0, [x2]; scvtf d0, w3; scvtf d1, w4; b #0x93f30] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2]; scvtf d0, w3; scvtf d1, w4; b #0x93f30]
uint64_t fde_sub_07e828(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E620060ULL) << 32) | 0xF9400040ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E828ULL;
}

// FDE #1960 | PC: 0x07e838..0x07e868 (48 B) | Symbol: sub_07e838
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; ldr x0, [x2]; mov x19, x2; bl #0x93f40] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; ldr x0, [x2]; mov x19, x2; bl #0x93f40]
uint64_t fde_sub_07e838(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400040ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E838ULL;
}

// FDE #1961 | PC: 0x07e868..0x07e870 (8 B) | Symbol: sub_07e868
// EN: AArch64 prologue [ldr x0, [x2]; b #0x93f50] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2]; b #0x93f50]
uint64_t fde_sub_07e868(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140055B9ULL) << 32) | 0xF9400040ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E868ULL;
}

// FDE #1962 | PC: 0x07e870..0x07e8d4 (100 B) | Symbol: sub_07e870
// EN: AArch64 prologue [sub sp, sp, #0x40; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8dab0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8dab0]
uint64_t fde_sub_07e870(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F4ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E870ULL;
}

// FDE #1963 | PC: 0x07e8d4..0x07e8e0 (12 B) | Symbol: sub_07e8d4
// EN: AArch64 prologue [ldr x0, [x2]; mov x1, x3; b #0x93f60] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2]; mov x1, x3; b #0x93f60]
uint64_t fde_sub_07e8d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0303E1ULL) << 32) | 0xF9400040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E8D4ULL;
}

// FDE #1964 | PC: 0x07e8e0..0x07e8e8 (8 B) | Symbol: sub_07e8e0
// EN: AArch64 prologue [ldr x0, [x2]; b #0x93f70] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2]; b #0x93f70]
uint64_t fde_sub_07e8e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140055A3ULL) << 32) | 0xF9400040ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E8E0ULL;
}

// FDE #1965 | PC: 0x07e8e8..0x07e8f4 (12 B) | Symbol: sub_07e8e8
// EN: AArch64 prologue [ldr x0, [x2]; mov x1, x3; b #0x93f80] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2]; mov x1, x3; b #0x93f80]
uint64_t fde_sub_07e8e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0303E1ULL) << 32) | 0xF9400040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E8E8ULL;
}

// FDE #1966 | PC: 0x07e8f4..0x07e900 (12 B) | Symbol: sub_07e8f4
// EN: AArch64 prologue [ldr x0, [x2]; mov x1, x3; b #0x93f90] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2]; mov x1, x3; b #0x93f90]
uint64_t fde_sub_07e8f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0303E1ULL) << 32) | 0xF9400040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E8F4ULL;
}

// FDE #1967 | PC: 0x07e900..0x07e910 (16 B) | Symbol: sub_07e900
// EN: AArch64 prologue [ldr x0, [x2]; tst w3, #0xff; cset w1, ne; b #0x93fa0] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2]; tst w3, #0xff; cset w1, ne; b #0x93fa0]
uint64_t fde_sub_07e900(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72001C7FULL) << 32) | 0xF9400040ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E900ULL;
}

// FDE #1968 | PC: 0x07e910..0x07e918 (8 B) | Symbol: sub_07e910
// EN: AArch64 prologue [ldr x0, [x2]; b #0x93fb0] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2]; b #0x93fb0]
uint64_t fde_sub_07e910(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140055A7ULL) << 32) | 0xF9400040ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E910ULL;
}

// FDE #1969 | PC: 0x07e918..0x07ea20 (264 B) | Symbol: sub_07e918
// EN: AArch64 prologue [sub sp, sp, #0x80; str x24, [sp, #0x40]; stp x23, x22, [sp, #0x50]; stp x21, x20, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x24, [sp, #0x40]; stp x23, x22, [sp, #0x50]; stp x21, x20, [sp, #0x60]]
uint64_t fde_sub_07e918(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F8ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0108ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E918ULL;
}

// FDE #1970 | PC: 0x07ea20..0x07eb4c (300 B) | Symbol: sub_07ea20
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x25, x24, [sp, #0x70]; stp x23, x22, [sp, #0x80]; stp x21, x20, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x25, x24, [sp, #0x70]; stp x23, x22, [sp, #0x80]; stp x21, x20, [sp, #0x90]]
uint64_t fde_sub_07ea20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90763F9ULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07EA20ULL;
}

// FDE #1971 | PC: 0x07eb4c..0x07ecb8 (364 B) | Symbol: sub_07eb4c
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x25, x24, [sp, #0x40]; stp x23, x22, [sp, #0x50]; stp x21, x20, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x25, x24, [sp, #0x40]; stp x23, x22, [sp, #0x50]; stp x21, x20, [sp, #0x60]]
uint64_t fde_sub_07eb4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90463F9ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x016CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07EB4CULL;
}

// FDE #1972 | PC: 0x07ecb8..0x07ed88 (208 B) | Symbol: sub_07ecb8
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_07ecb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9035BF7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07ECB8ULL;
}

// FDE #1973 | PC: 0x07ed88..0x07ef7c (500 B) | Symbol: sub_07ed88
// EN: AArch64 prologue [sub sp, sp, #0xe0; stp x28, x27, [sp, #0x80]; stp x26, x25, [sp, #0x90]; stp x24, x23, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xe0; stp x28, x27, [sp, #0x80]; stp x26, x25, [sp, #0x90]; stp x24, x23, [sp, #0xa0]]
uint64_t fde_sub_07ed88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9086FFCULL) << 32) | 0xD10383FFULL;
    const uint64_t kPcRange = 0x01F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07ED88ULL;
}

// FDE #1974 | PC: 0x07ef7c..0x07efa0 (36 B) | Symbol: sub_07ef7c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8dff0; cbz x19, #0x7ef98; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8dff0; cbz x19, #0x7ef98; mov x0, x19]
uint64_t fde_sub_07ef7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94003C1CULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07EF7CULL;
}

// FDE #1975 | PC: 0x07efa0..0x07efb0 (16 B) | Symbol: sub_07efa0
// EN: AArch64 prologue [adrp x8, #0x9c000; add x8, x8, #0xb68; str x8, [x0], #8; b #0x7ef7c] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9c000; add x8, x8, #0xb68; str x8, [x0], #8; b #0x7ef7c]
uint64_t fde_sub_07efa0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x912DA108ULL) << 32) | 0xD00000E8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07EFA0ULL;
}

// FDE #1976 | PC: 0x07efb0..0x07efc8 (24 B) | Symbol: sub_07efb0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7efa0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7efa0; mov x0, x19]
uint64_t fde_sub_07efb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07EFB0ULL;
}

// FDE #1977 | PC: 0x07efc8..0x07f0f0 (296 B) | Symbol: sub_07efc8
// EN: AArch64 prologue [mov x2, x30; bl #0x8e8e8; mov x30, x2; stp x29, x30, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8e8e8; mov x30, x2; stp x29, x30, [sp, #0x80]]
uint64_t fde_sub_07efc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94003E47ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0128ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07EFC8ULL;
}

// FDE #1978 | PC: 0x07f0f0..0x07f124 (52 B) | Symbol: sub_07f0f0
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x0] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x0]
uint64_t fde_sub_07f0f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F0F0ULL;
}

// FDE #1979 | PC: 0x07f124..0x07f130 (12 B) | Symbol: sub_07f124
// EN: AArch64 prologue [adrp x8, #0x9c000; add x8, x8, #0xb90; b #0x92244] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9c000; add x8, x8, #0xb90; b #0x92244]
uint64_t fde_sub_07f124(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x912E4108ULL) << 32) | 0xB00000E8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F124ULL;
}

// FDE #1980 | PC: 0x07f130..0x07f148 (24 B) | Symbol: sub_07f130
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7f124; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7f124; mov x0, x19]
uint64_t fde_sub_07f130(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F130ULL;
}

// FDE #1981 | PC: 0x07f148..0x07f158 (16 B) | Symbol: sub_07f148
// EN: AArch64 prologue [ldr x0, [x0, #8]; cbz x0, #0x7f154; b #0x82aec; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #8]; cbz x0, #0x7f154; b #0x82aec; ret]
uint64_t fde_sub_07f148(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000040ULL) << 32) | 0xF9400400ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F148ULL;
}

// FDE #1982 | PC: 0x07f158..0x07f18c (52 B) | Symbol: sub_07f158
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x0] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x0]
uint64_t fde_sub_07f158(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F158ULL;
}

// FDE #1983 | PC: 0x07f18c..0x07f1f0 (100 B) | Symbol: sub_07f18c
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr x8, [x1]] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr x8, [x1]]
uint64_t fde_sub_07f18c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F18CULL;
}

// FDE #1984 | PC: 0x07f1f0..0x07f220 (48 B) | Symbol: sub_07f1f0
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x90eb8; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x90eb8; adrp x8, #0x9c000]
uint64_t fde_sub_07f1f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F1F0ULL;
}

// FDE #1985 | PC: 0x07f220..0x07f250 (48 B) | Symbol: sub_07f220
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8ec8c; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8ec8c; adrp x8, #0x9c000]
uint64_t fde_sub_07f220(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F220ULL;
}

// FDE #1986 | PC: 0x07f250..0x07f26c (28 B) | Symbol: sub_07f250
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x18]; bl #0x48d40] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x18]; bl #0x48d40]
uint64_t fde_sub_07f250(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F250ULL;
}

// FDE #1987 | PC: 0x07f26c..0x07f280 (20 B) | Symbol: sub_07f26c
// EN: AArch64 prologue [adrp x8, #0x9c000; add x8, x8, #0xbe0; mov x1, xzr; str x8, [x0]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9c000; add x8, x8, #0xbe0; mov x1, xzr; str x8, [x0]]
uint64_t fde_sub_07f26c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x912F8108ULL) << 32) | 0xB00000E8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F26CULL;
}

// FDE #1988 | PC: 0x07f280..0x07f290 (16 B) | Symbol: sub_07f280
// EN: AArch64 prologue [adrp x8, #0x9c000; add x8, x8, #0xbb8; str x8, [x0], #8; b #0x7f250] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9c000; add x8, x8, #0xbb8; str x8, [x0], #8; b #0x7f250]
uint64_t fde_sub_07f280(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x912EE108ULL) << 32) | 0xB00000E8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F280ULL;
}

// FDE #1989 | PC: 0x07f290..0x07f2a8 (24 B) | Symbol: sub_07f290
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7f280; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7f280; mov x0, x19]
uint64_t fde_sub_07f290(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F290ULL;
}

// FDE #1990 | PC: 0x07f2a8..0x07f3d8 (304 B) | Symbol: sub_07f2a8
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp x23, x22, [sp, #0x70]; stp x21, x20, [sp, #0x80]; stp x19, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp x23, x22, [sp, #0x70]; stp x21, x20, [sp, #0x80]; stp x19, x30, [sp, #0x90]]
uint64_t fde_sub_07f2a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9075BF7ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F2A8ULL;
}

// FDE #1991 | PC: 0x07f3d8..0x07f488 (176 B) | Symbol: sub_07f3d8
// EN: AArch64 prologue [sub sp, sp, #0x170; str x28, [sp, #0x140]; stp x21, x20, [sp, #0x150]; stp x19, x30, [sp, #0x160]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; str x28, [sp, #0x140]; stp x21, x20, [sp, #0x150]; stp x19, x30, [sp, #0x160]]
uint64_t fde_sub_07f3d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900A3FCULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F3D8ULL;
}

// FDE #1992 | PC: 0x07f488..0x07f4a0 (24 B) | Symbol: sub_07f488
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; ldrb w8, [x0, #0x10]; cbz w8, #0x7f49c; ldr x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; ldrb w8, [x0, #0x10]; cbz w8, #0x7f49c; ldr x30, [sp], #0x10]
uint64_t fde_sub_07f488(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39404008ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F488ULL;
}

// FDE #1993 | PC: 0x07f4a0..0x07f4cc (44 B) | Symbol: sub_07f4a0
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8ec8c; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8ec8c; adrp x8, #0x9c000]
uint64_t fde_sub_07f4a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F4A0ULL;
}

// FDE #1994 | PC: 0x07f4cc..0x07f4dc (16 B) | Symbol: sub_07f4cc
// EN: AArch64 prologue [ldrb w8, [x0, #0x10]; cbz w8, #0x7f4d8; b #0x7d610; ret] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x10]; cbz w8, #0x7f4d8; b #0x7d610; ret]
uint64_t fde_sub_07f4cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34000048ULL) << 32) | 0x39404008ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F4CCULL;
}

// FDE #1995 | PC: 0x07f4dc..0x07f508 (44 B) | Symbol: sub_07f4dc
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8ec8c; bl #0x91828] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8ec8c; bl #0x91828]
uint64_t fde_sub_07f4dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F4DCULL;
}

// FDE #1996 | PC: 0x07f508..0x07f518 (16 B) | Symbol: sub_07f508
// EN: AArch64 prologue [adrp x8, #0x9c000; add x8, x8, #0xc08; str x8, [x0], #8; b #0x7f250] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9c000; add x8, x8, #0xc08; str x8, [x0], #8; b #0x7f250]
uint64_t fde_sub_07f508(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91302108ULL) << 32) | 0xB00000E8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F508ULL;
}

// FDE #1997 | PC: 0x07f518..0x07f530 (24 B) | Symbol: sub_07f518
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7f508; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7f508; mov x0, x19]
uint64_t fde_sub_07f518(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F518ULL;
}

// FDE #1998 | PC: 0x07f530..0x07fa9c (1388 B) | Symbol: sub_07f530
// EN: AArch64 prologue [mov x1, x30; bl #0x8d63c; mov x30, x1; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x1, x30; bl #0x8d63c; mov x30, x1; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_07f530(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94003842ULL) << 32) | 0xAA1E03E1ULL;
    const uint64_t kPcRange = 0x056CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07F530ULL;
}

// FDE #1999 | PC: 0x07fa9c..0x07fab4 (24 B) | Symbol: sub_07fa9c
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x9c000; add x9, x9, #0xc30; str x9, [x0]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x9c000; add x9, x9, #0xc30; str x9, [x0]]
uint64_t fde_sub_07fa9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00000E9ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FA9CULL;
}

// FDE #2000 | PC: 0x07fab4..0x07facc (24 B) | Symbol: sub_07fab4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7fa9c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7fa9c; mov x0, x19]
uint64_t fde_sub_07fab4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FAB4ULL;
}

// FDE #2001 | PC: 0x07facc..0x07fce0 (532 B) | Symbol: sub_07facc
// EN: AArch64 prologue [mov x1, x30; bl #0x91b18; mov x30, x1; stp x29, x30, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [mov x1, x30; bl #0x91b18; mov x30, x1; stp x29, x30, [sp, #0xa0]]
uint64_t fde_sub_07facc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94004812ULL) << 32) | 0xAA1E03E1ULL;
    const uint64_t kPcRange = 0x0214ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FACCULL;
}

// FDE #2002 | PC: 0x07fce0..0x07fd00 (32 B) | Symbol: sub_07fce0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9c000; add x8, x8, #0xc58; bl #0x8daa4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9c000; add x8, x8, #0xc58; bl #0x8daa4]
uint64_t fde_sub_07fce0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00000E8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FCE0ULL;
}

// FDE #2003 | PC: 0x07fd00..0x07fd18 (24 B) | Symbol: sub_07fd00
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7fce0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7fce0; mov x0, x19]
uint64_t fde_sub_07fd00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FD00ULL;
}

// FDE #2004 | PC: 0x07fd18..0x07fd20 (8 B) | Symbol: sub_07fd18
// EN: AArch64 prologue [add x0, x0, #0x18; b #0x5a75c] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x18; b #0x5a75c]
uint64_t fde_sub_07fd18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF6A90ULL) << 32) | 0x91006000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FD18ULL;
}

// FDE #2005 | PC: 0x07fd20..0x07fd40 (32 B) | Symbol: sub_07fd20
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9c000; add x8, x8, #0xc90; bl #0x8daa4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9c000; add x8, x8, #0xc90; bl #0x8daa4]
uint64_t fde_sub_07fd20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00000E8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FD20ULL;
}

// FDE #2006 | PC: 0x07fd40..0x07fd58 (24 B) | Symbol: sub_07fd40
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7fd20; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7fd20; mov x0, x19]
uint64_t fde_sub_07fd40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FD40ULL;
}

// FDE #2007 | PC: 0x07fd58..0x07fd70 (24 B) | Symbol: sub_07fd58
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x9c000; add x9, x9, #0xcc8; str x9, [x0]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x9c000; add x9, x9, #0xcc8; str x9, [x0]]
uint64_t fde_sub_07fd58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00000E9ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FD58ULL;
}

// FDE #2008 | PC: 0x07fd70..0x07fd88 (24 B) | Symbol: sub_07fd70
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7fd58; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7fd58; mov x0, x19]
uint64_t fde_sub_07fd70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FD70ULL;
}

// FDE #2009 | PC: 0x07fd88..0x07fe58 (208 B) | Symbol: sub_07fd88
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_07fd88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9025BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FD88ULL;
}

// FDE #2010 | PC: 0x07fe58..0x07fe78 (32 B) | Symbol: sub_07fe58
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9c000; add x8, x8, #0xcf0; bl #0x8daa4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9c000; add x8, x8, #0xcf0; bl #0x8daa4]
uint64_t fde_sub_07fe58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00000E8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FE58ULL;
}

// FDE #2011 | PC: 0x07fe78..0x07fe90 (24 B) | Symbol: sub_07fe78
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7fe58; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x7fe58; mov x0, x19]
uint64_t fde_sub_07fe78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FE78ULL;
}

// FDE #2012 | PC: 0x07fe90..0x07fe98 (8 B) | Symbol: sub_07fe90
// EN: AArch64 prologue [add x0, x0, #0x18; b #0x7fe98] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x18; b #0x7fe98]
uint64_t fde_sub_07fe90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0x91006000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FE90ULL;
}

// FDE #2013 | PC: 0x07fe98..0x07feac (20 B) | Symbol: sub_07fe98
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x8fef8; ldp x19, x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x8fef8; ldp x19, x30, [sp], #0x10]
uint64_t fde_sub_07fe98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94003720ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FE98ULL;
}

// FDE #2014 | PC: 0x07feac..0x07fefc (80 B) | Symbol: sub_07feac
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_07feac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9035BF7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FEACULL;
}

// FDE #2015 | PC: 0x07fefc..0x07ff3c (64 B) | Symbol: sub_07fefc
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8dff0; cbz x19, #0x7ff34] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8dff0; cbz x19, #0x7ff34]
uint64_t fde_sub_07fefc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FEFCULL;
}

// FDE #2016 | PC: 0x07ff3c..0x07ff8c (80 B) | Symbol: sub_07ff3c
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_07ff3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9035BF7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FF3CULL;
}

// FDE #2017 | PC: 0x07ff8c..0x080148 (444 B) | Symbol: sub_07ff8c
// EN: AArch64 prologue [sub sp, sp, #0x1a0; str x28, [sp, #0x150]; stp x25, x24, [sp, #0x160]; stp x23, x22, [sp, #0x170]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1a0; str x28, [sp, #0x150]; stp x25, x24, [sp, #0x160]; stp x23, x22, [sp, #0x170]]
uint64_t fde_sub_07ff8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900ABFCULL) << 32) | 0xD10683FFULL;
    const uint64_t kPcRange = 0x01BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FF8CULL;
}

// FDE #2018 | PC: 0x080148..0x08018c (68 B) | Symbol: sub_080148
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9c000; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9c000; mov x19, x0]
uint64_t fde_sub_080148(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080148ULL;
}

// FDE #2019 | PC: 0x08018c..0x0801a4 (24 B) | Symbol: sub_08018c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x80148; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x80148; mov x0, x19]
uint64_t fde_sub_08018c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08018CULL;
}

// FDE #2020 | PC: 0x0801a4..0x0802a8 (260 B) | Symbol: sub_0801a4
// EN: AArch64 prologue [sub sp, sp, #0x170; str x28, [sp, #0x130]; stp x23, x22, [sp, #0x140]; stp x21, x20, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; str x28, [sp, #0x130]; stp x23, x22, [sp, #0x140]; stp x21, x20, [sp, #0x150]]
uint64_t fde_sub_0801a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9009BFCULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0801A4ULL;
}

// FDE #2021 | PC: 0x0802a8..0x0802b0 (8 B) | Symbol: sub_0802a8
// EN: AArch64 prologue [ldr x0, [x0, #0x38]; b #0x8e770] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x38]; b #0x8e770]
uint64_t fde_sub_0802a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14003931ULL) << 32) | 0xF9401C00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0802A8ULL;
}

// FDE #2022 | PC: 0x0802b0..0x0802d4 (36 B) | Symbol: sub_0802b0
// EN: AArch64 prologue [ldr x8, [x0, #0x18]; cbz x8, #0x802d0; ldr x8, [x0, #0x20]; cbz x8, #0x802d0] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x18]; cbz x8, #0x802d0; ldr x8, [x0, #0x20]; cbz x8, #0x802d0]
uint64_t fde_sub_0802b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB40000E8ULL) << 32) | 0xF9400C08ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0802B0ULL;
}

// FDE #2023 | PC: 0x0802d4..0x080354 (128 B) | Symbol: sub_0802d4
// EN: AArch64 prologue [sub sp, sp, #0x30; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr w8, [x1]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr w8, [x1]]
uint64_t fde_sub_0802d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0802D4ULL;
}

// FDE #2024 | PC: 0x080354..0x080388 (52 B) | Symbol: sub_080354
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8ddf8; adrp x8, #0x9c000; add x8, x8, #0xd70] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8ddf8; adrp x8, #0x9c000; add x8, x8, #0xd70]
uint64_t fde_sub_080354(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940036A8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080354ULL;
}

// FDE #2025 | PC: 0x080388..0x0803a0 (24 B) | Symbol: sub_080388
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x80354; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x80354; mov x0, x19]
uint64_t fde_sub_080388(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080388ULL;
}

// FDE #2026 | PC: 0x0803a0..0x08041c (124 B) | Symbol: sub_0803a0
// EN: AArch64 prologue [sub sp, sp, #0x60; str x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]; bl #0x8eba4] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]; bl #0x8eba4]
uint64_t fde_sub_0803a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F4ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0803A0ULL;
}

// FDE #2027 | PC: 0x08041c..0x080424 (8 B) | Symbol: sub_08041c
// EN: AArch64 prologue [ldr x0, [x0, #0x28]; b #0x8e770] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x28]; b #0x8e770]
uint64_t fde_sub_08041c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140038D4ULL) << 32) | 0xF9401400ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08041CULL;
}

// FDE #2028 | PC: 0x080424..0x080438 (20 B) | Symbol: sub_080424
// EN: AArch64 prologue [ldr x8, [x0, #0x18]; cbz x8, #0x80434; ldr x8, [x0, #0x28]; b #0x8f790] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x18]; cbz x8, #0x80434; ldr x8, [x0, #0x28]; b #0x8f790]
uint64_t fde_sub_080424(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000068ULL) << 32) | 0xF9400C08ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080424ULL;
}

// FDE #2029 | PC: 0x080438..0x080478 (64 B) | Symbol: sub_080438
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x929e8; b.ne #0x8045c; ldr w10, [x19, #0xc]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x929e8; b.ne #0x8045c; ldr w10, [x19, #0xc]]
uint64_t fde_sub_080438(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400496BULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080438ULL;
}

// FDE #2030 | PC: 0x080478..0x0804a4 (44 B) | Symbol: sub_080478
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8ee48; adrp x8, #0x9c000; add x8, x8, #0xd28] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8ee48; adrp x8, #0x9c000; add x8, x8, #0xd28]
uint64_t fde_sub_080478(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94003A73ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080478ULL;
}

// FDE #2031 | PC: 0x0804a4..0x0804bc (24 B) | Symbol: sub_0804a4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x80478; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x80478; mov x0, x19]
uint64_t fde_sub_0804a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0804A4ULL;
}

// FDE #2032 | PC: 0x0804bc..0x08090c (1104 B) | Symbol: sub_0804bc
// EN: AArch64 prologue [mov x1, x30; bl #0x8d63c; mov x30, x1; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x1, x30; bl #0x8d63c; mov x30, x1; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_0804bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400345FULL) << 32) | 0xAA1E03E1ULL;
    const uint64_t kPcRange = 0x0450ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0804BCULL;
}

// FDE #2033 | PC: 0x08090c..0x080914 (8 B) | Symbol: sub_08090c
// EN: AArch64 prologue [ldr x0, [x0, #0x20]; b #0x8e770] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x20]; b #0x8e770]
uint64_t fde_sub_08090c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14003798ULL) << 32) | 0xF9401000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08090CULL;
}

// FDE #2034 | PC: 0x080914..0x080928 (20 B) | Symbol: sub_080914
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; cbz x8, #0x80924; ldr x8, [x0, #0x20]; b #0x8f790] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; cbz x8, #0x80924; ldr x8, [x0, #0x20]; b #0x8f790]
uint64_t fde_sub_080914(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000068ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080914ULL;
}

// FDE #2035 | PC: 0x080928..0x080964 (60 B) | Symbol: sub_080928
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x929e8; b.ne #0x8094c; ldr w10, [x19, #0xc]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x929e8; b.ne #0x8094c; ldr w10, [x19, #0xc]]
uint64_t fde_sub_080928(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400482FULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080928ULL;
}

// FDE #2036 | PC: 0x080964..0x0809ac (72 B) | Symbol: sub_080964
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8fb64; bl #0x8fcb4] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8fb64; bl #0x8fcb4]
uint64_t fde_sub_080964(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080964ULL;
}

// FDE #2037 | PC: 0x0809ac..0x0809d8 (44 B) | Symbol: sub_0809ac
// EN: AArch64 prologue [sub sp, sp, #0x120; str x28, [sp, #0x100]; stp x19, x30, [sp, #0x110]; bl #0x8d3e8] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; str x28, [sp, #0x100]; stp x19, x30, [sp, #0x110]; bl #0x8d3e8]
uint64_t fde_sub_0809ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90083FCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0809ACULL;
}

// FDE #2038 | PC: 0x0809d8..0x080a30 (88 B) | Symbol: sub_0809d8
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x8, [x1, #8]; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x8, [x1, #8]; mov x19, x0]
uint64_t fde_sub_0809d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0809D8ULL;
}

// FDE #2039 | PC: 0x080a30..0x080a54 (36 B) | Symbol: sub_080a30
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x93c40; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x93c40; adrp x8, #0x9c000]
uint64_t fde_sub_080a30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080A30ULL;
}

// FDE #2040 | PC: 0x080a54..0x080aac (88 B) | Symbol: sub_080a54
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x8, [x1, #8]; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x8, [x1, #8]; mov x19, x0]
uint64_t fde_sub_080a54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080A54ULL;
}

// FDE #2041 | PC: 0x080aac..0x080b04 (88 B) | Symbol: sub_080aac
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x8, [x1, #8]; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x8, [x1, #8]; mov x19, x0]
uint64_t fde_sub_080aac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080AACULL;
}

// FDE #2042 | PC: 0x080b04..0x080b44 (64 B) | Symbol: sub_080b04
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8fb64; bl #0x8fcb4] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8fb64; bl #0x8fcb4]
uint64_t fde_sub_080b04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080B04ULL;
}

// FDE #2043 | PC: 0x080b44..0x080b84 (64 B) | Symbol: sub_080b44
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8fb64; bl #0x8fcb4] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8fb64; bl #0x8fcb4]
uint64_t fde_sub_080b44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080B44ULL;
}

// FDE #2044 | PC: 0x080b84..0x080bc8 (68 B) | Symbol: sub_080b84
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8fb64; bl #0x8fcb4] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8fb64; bl #0x8fcb4]
uint64_t fde_sub_080b84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080B84ULL;
}

// FDE #2045 | PC: 0x080bc8..0x080c6c (164 B) | Symbol: sub_080bc8
// EN: AArch64 prologue [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]]
uint64_t fde_sub_080bc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9009BFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080BC8ULL;
}

// FDE #2046 | PC: 0x080c6c..0x080c9c (48 B) | Symbol: sub_080c6c
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9c000; mov x21, x0] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9c000; mov x21, x0]
uint64_t fde_sub_080c6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080C6CULL;
}

// FDE #2047 | PC: 0x080c9c..0x080ca8 (12 B) | Symbol: sub_080c9c
// EN: AArch64 prologue [adrp x8, #0x9c000; add x8, x8, #0xe00; b #0x9224c] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9c000; add x8, x8, #0xe00; b #0x9224c]
uint64_t fde_sub_080c9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91380108ULL) << 32) | 0x900000E8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080C9CULL;
}

// FDE #2048 | PC: 0x080ca8..0x080cc0 (24 B) | Symbol: sub_080ca8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x80c9c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x80c9c; mov x0, x19]
uint64_t fde_sub_080ca8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080CA8ULL;
}

// FDE #2049 | PC: 0x080cc0..0x080d18 (88 B) | Symbol: sub_080cc0
// EN: AArch64 prologue [sub sp, sp, #0x150; stp x28, x20, [sp, #0x130]; stp x19, x30, [sp, #0x140]; bl #0x8f760] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x150; stp x28, x20, [sp, #0x130]; stp x19, x30, [sp, #0x140]; bl #0x8f760]
uint64_t fde_sub_080cc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA91353FCULL) << 32) | 0xD10543FFULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080CC0ULL;
}

// FDE #2050 | PC: 0x080d18..0x080d3c (36 B) | Symbol: sub_080d18
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9c000; add x8, x8, #0xe28; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9c000; add x8, x8, #0xe28; mov x19, x0]
uint64_t fde_sub_080d18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900000E8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080D18ULL;
}

// FDE #2051 | PC: 0x080d3c..0x080d54 (24 B) | Symbol: sub_080d3c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x80d18; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x80d18; mov x0, x19]
uint64_t fde_sub_080d3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080D3CULL;
}

// FDE #2052 | PC: 0x080d54..0x080e2c (216 B) | Symbol: sub_080d54
// EN: AArch64 prologue [sub sp, sp, #0x160; stp x28, x22, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; stp x28, x22, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]]
uint64_t fde_sub_080d54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9135BFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080D54ULL;
}

// FDE #2053 | PC: 0x080e2c..0x080e4c (32 B) | Symbol: sub_080e2c
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x80e4c; bl #0x8d5b8; ldr w8, [x0, #0x24]] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x80e4c; bl #0x8d5b8; ldr w8, [x0, #0x24]]
uint64_t fde_sub_080e2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94000007ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080E2CULL;
}

// FDE #2054 | PC: 0x080e4c..0x080f88 (316 B) | Symbol: sub_080e4c
// EN: AArch64 prologue [sub sp, sp, #0x160; stp x28, x22, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; stp x28, x22, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]]
uint64_t fde_sub_080e4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9135BFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x013CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080E4CULL;
}

// FDE #2055 | PC: 0x080f88..0x081160 (472 B) | Symbol: sub_080f88
// EN: AArch64 prologue [sub sp, sp, #0x180; str x28, [sp, #0x150]; stp x21, x20, [sp, #0x160]; stp x19, x30, [sp, #0x170]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x180; str x28, [sp, #0x150]; stp x21, x20, [sp, #0x160]; stp x19, x30, [sp, #0x170]]
uint64_t fde_sub_080f88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900ABFCULL) << 32) | 0xD10603FFULL;
    const uint64_t kPcRange = 0x01D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x080F88ULL;
}

// FDE #2056 | PC: 0x081160..0x0811ec (140 B) | Symbol: sub_081160
// EN: AArch64 prologue [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]]
uint64_t fde_sub_081160(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9009BFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081160ULL;
}

// FDE #2057 | PC: 0x0811ec..0x081404 (536 B) | Symbol: sub_0811ec
// EN: AArch64 prologue [sub sp, sp, #0x160; stp x28, x22, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; stp x28, x22, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]]
uint64_t fde_sub_0811ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9135BFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x0218ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0811ECULL;
}

// FDE #2058 | PC: 0x081404..0x081478 (116 B) | Symbol: sub_081404
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov w0, #8; bl #0x8e290] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov w0, #8; bl #0x8e290]
uint64_t fde_sub_081404(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081404ULL;
}

// FDE #2059 | PC: 0x081478..0x0814ac (52 B) | Symbol: sub_081478
// EN: AArch64 prologue [sub sp, sp, #0x120; str x28, [sp, #0x100]; stp x19, x30, [sp, #0x110]; bl #0x8d3e8] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; str x28, [sp, #0x100]; stp x19, x30, [sp, #0x110]; bl #0x8d3e8]
uint64_t fde_sub_081478(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90083FCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081478ULL;
}

// FDE #2060 | PC: 0x0814ac..0x0814e4 (56 B) | Symbol: sub_0814ac
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; ldr x0, [x2]; bl #0x92828; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; ldr x0, [x2]; bl #0x92828; ldr x8, [x0]]
uint64_t fde_sub_0814ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400040ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0814ACULL;
}

// FDE #2061 | PC: 0x0814e4..0x0814fc (24 B) | Symbol: sub_0814e4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5a75c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5a75c; mov x0, x19]
uint64_t fde_sub_0814e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0814E4ULL;
}

// FDE #2062 | PC: 0x0814fc..0x081508 (12 B) | Symbol: sub_0814fc
// EN: AArch64 prologue [ldr x8, [x2]; ldr s0, [x8, #0x14]; b #0x92a70] | VI: Khởi đầu hàm AArch64 [ldr x8, [x2]; ldr s0, [x8, #0x14]; b #0x92a70]
uint64_t fde_sub_0814fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xBD401500ULL) << 32) | 0xF9400048ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0814FCULL;
}

// FDE #2063 | PC: 0x081508..0x081514 (12 B) | Symbol: sub_081508
// EN: AArch64 prologue [ldr x8, [x2]; ldr s0, [x8, #0x18]; b #0x92a70] | VI: Khởi đầu hàm AArch64 [ldr x8, [x2]; ldr s0, [x8, #0x18]; b #0x92a70]
uint64_t fde_sub_081508(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xBD401900ULL) << 32) | 0xF9400048ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081508ULL;
}

// FDE #2064 | PC: 0x081514..0x081538 (36 B) | Symbol: sub_081514
// EN: AArch64 prologue [cbz x2, #0x81534; stp x19, x30, [sp, #-0x10]!; ldr x0, [x2, #8]; mov x19, x2] | VI: Khởi đầu hàm AArch64 [cbz x2, #0x81534; stp x19, x30, [sp, #-0x10]!; ldr x0, [x2, #8]; mov x19, x2]
uint64_t fde_sub_081514(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BF3ULL) << 32) | 0xB4000102ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081514ULL;
}

// FDE #2065 | PC: 0x081538..0x0815c4 (140 B) | Symbol: sub_081538
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8e128] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8e128]
uint64_t fde_sub_081538(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081538ULL;
}

// FDE #2066 | PC: 0x0815c4..0x081610 (76 B) | Symbol: sub_0815c4
// EN: AArch64 prologue [sub sp, sp, #0x40; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x90300] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x90300]
uint64_t fde_sub_0815c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F4ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0815C4ULL;
}

// FDE #2067 | PC: 0x081610..0x0816dc (204 B) | Symbol: sub_081610
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x23, x22, [sp, #0x80]; stp x21, x20, [sp, #0x90]; stp x19, x30, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x23, x22, [sp, #0x80]; stp x21, x20, [sp, #0x90]; stp x19, x30, [sp, #0xa0]]
uint64_t fde_sub_081610(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9085BF7ULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081610ULL;
}

// FDE #2068 | PC: 0x0816dc..0x0817fc (288 B) | Symbol: _ZN4lynx6animax17VideoAssetAndroidC1ENS0_15VideoAssetModelE
// EN: AArch64 prologue [sub sp, sp, #0x1c0; stp x28, x22, [sp, #0x190]; stp x21, x20, [sp, #0x1a0]; stp x19, x30, [sp, #0x1b0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1c0; stp x28, x22, [sp, #0x190]; stp x21, x20, [sp, #0x1a0]; stp x19, x30, [sp, #0x1b0]]
uint64_t fde_sub_0816dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9195BFCULL) << 32) | 0xD10703FFULL;
    const uint64_t kPcRange = 0x0120ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0816DCULL;
}

// FDE #2069 | PC: 0x0817fc..0x081820 (36 B) | Symbol: sub_0817fc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; ldr x8, [x8, #0xc28]; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; ldr x8, [x8, #0xc28]; mov x19, x0]
uint64_t fde_sub_0817fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900000E8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0817FCULL;
}

// FDE #2070 | PC: 0x081820..0x081838 (24 B) | Symbol: sub_081820
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x817fc; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x817fc; mov x0, x19]
uint64_t fde_sub_081820(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081820ULL;
}

// FDE #2071 | PC: 0x081838..0x081a88 (592 B) | Symbol: _ZN4lynx6animax17VideoAssetAndroid16PrepareFrameDataERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE
// EN: AArch64 prologue [sub sp, sp, #0x1a0; str d8, [sp, #0x140]; stp x28, x26, [sp, #0x150]; stp x25, x24, [sp, #0x160]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1a0; str d8, [sp, #0x140]; stp x28, x26, [sp, #0x150]; stp x25, x24, [sp, #0x160]]
uint64_t fde_sub_081838(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD00A3E8ULL) << 32) | 0xD10683FFULL;
    const uint64_t kPcRange = 0x0250ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081838ULL;
}

// FDE #2072 | PC: 0x081a88..0x081a90 (8 B) | Symbol: sub_081a88
// EN: AArch64 prologue [ldr w0, [x0, #0xa8]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0xa8]; ret]
uint64_t fde_sub_081a88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB940A800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081A88ULL;
}

// FDE #2073 | PC: 0x081a90..0x081ae0 (80 B) | Symbol: _ZNK4lynx6animax17VideoAssetAndroid15GetPrevKeyFrameEi
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov w19, w1; bl #0x91c00] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov w19, w1; bl #0x91c00]
uint64_t fde_sub_081a90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081A90ULL;
}

// FDE #2074 | PC: 0x081ae0..0x081b70 (144 B) | Symbol: _ZNK4lynx6animax17VideoAssetAndroid21GetVideoParameterSetsEv
// EN: AArch64 prologue [sub sp, sp, #0x50; str x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_081ae0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081AE0ULL;
}

// FDE #2075 | PC: 0x081b70..0x081c08 (152 B) | Symbol: _ZNK4lynx6animax17VideoAssetAndroid15GetFrameRawDataEi
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_081b70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9025BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081B70ULL;
}

// FDE #2076 | PC: 0x081c08..0x081c28 (32 B) | Symbol: sub_081c08
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9c000; add x8, x8, #0xef8; bl #0x8daa4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9c000; add x8, x8, #0xef8; bl #0x8daa4]
uint64_t fde_sub_081c08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00000C8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081C08ULL;
}

// FDE #2077 | PC: 0x081c28..0x081c40 (24 B) | Symbol: sub_081c28
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x81c08; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x81c08; mov x0, x19]
uint64_t fde_sub_081c28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081C28ULL;
}

// FDE #2078 | PC: 0x081c40..0x081c8c (76 B) | Symbol: _ZNK4lynx6animax17VideoAssetAndroid12IsHEVCFormatEv
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8fb64; adrp x5, #0xa0000] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8fb64; adrp x5, #0xa0000]
uint64_t fde_sub_081c40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081C40ULL;
}

// FDE #2079 | PC: 0x081c8c..0x081ce0 (84 B) | Symbol: _ZNK4lynx6animax17VideoAssetAndroid23IsSupportDecodeBySystemEb
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov w19, w1; bl #0x91c00] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov w19, w1; bl #0x91c00]
uint64_t fde_sub_081c8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081C8CULL;
}

// FDE #2080 | PC: 0x081ce0..0x081d68 (136 B) | Symbol: sub_081ce0
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; adrp x8, #0x9c000]
uint64_t fde_sub_081ce0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081CE0ULL;
}

// FDE #2081 | PC: 0x081d68..0x081d80 (24 B) | Symbol: sub_081d68
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x81ce0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x81ce0; mov x0, x19]
uint64_t fde_sub_081d68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081D68ULL;
}

// FDE #2082 | PC: 0x081d80..0x081ef8 (376 B) | Symbol: sub_081d80
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x25, x24, [sp, #0x20]; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x25, x24, [sp, #0x20]; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]]
uint64_t fde_sub_081d80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90263F9ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081D80ULL;
}

// FDE #2083 | PC: 0x081ef8..0x081f00 (8 B) | Symbol: sub_081ef8
// EN: AArch64 prologue [add x0, x0, #0x34; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x34; ret]
uint64_t fde_sub_081ef8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x9100D000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081EF8ULL;
}

// FDE #2084 | PC: 0x081f00..0x082054 (340 B) | Symbol: sub_081f00
// EN: AArch64 prologue [sub sp, sp, #0x70; str x24, [sp, #0x30]; stp x23, x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x24, [sp, #0x30]; stp x23, x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]]
uint64_t fde_sub_081f00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF8ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0154ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081F00ULL;
}

// FDE #2085 | PC: 0x082054..0x08206c (24 B) | Symbol: sub_082054
// EN: AArch64 prologue [cbz x0, #0x82068; ldr x8, [x0]; mov x2, x1; mov w1, #0x64] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x82068; ldr x8, [x0]; mov x2, x1; mov w1, #0x64]
uint64_t fde_sub_082054(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xB40000A0ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082054ULL;
}

// FDE #2086 | PC: 0x08206c..0x08209c (48 B) | Symbol: sub_08206c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9c000; add x8, x8, #0xfb8; str x8, [x0]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9c000; add x8, x8, #0xfb8; str x8, [x0]]
uint64_t fde_sub_08206c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00000C8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08206CULL;
}

// FDE #2087 | PC: 0x08209c..0x0820b4 (24 B) | Symbol: sub_08209c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x8206c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x8206c; mov x0, x19]
uint64_t fde_sub_08209c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08209CULL;
}

// FDE #2088 | PC: 0x0820b4..0x0820c0 (12 B) | Symbol: sub_0820b4
// EN: AArch64 prologue [adrp x0, #0x20000; add x0, x0, #0x3b5; ret] | VI: Khởi đầu hàm AArch64 [adrp x0, #0x20000; add x0, x0, #0x3b5; ret]
uint64_t fde_sub_0820b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910ED400ULL) << 32) | 0xD0FFFCE0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0820B4ULL;
}

// FDE #2089 | PC: 0x0820c0..0x0820cc (12 B) | Symbol: sub_0820c0
// EN: AArch64 prologue [adrp x0, #0x1f000; add x0, x0, #0xf11; ret] | VI: Khởi đầu hàm AArch64 [adrp x0, #0x1f000; add x0, x0, #0xf11; ret]
uint64_t fde_sub_0820c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x913C4400ULL) << 32) | 0xB0FFFCE0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0820C0ULL;
}

// FDE #2090 | PC: 0x0820cc..0x0820fc (48 B) | Symbol: sub_0820cc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr w0, [x0, #0x48]; cmn w0, #1] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr w0, [x0, #0x48]; cmn w0, #1]
uint64_t fde_sub_0820cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0820CCULL;
}

// FDE #2091 | PC: 0x0820fc..0x082104 (8 B) | Symbol: sub_0820fc
// EN: AArch64 prologue [mov w0, #0x8d65; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x8d65; ret]
uint64_t fde_sub_0820fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x5291ACA0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0820FCULL;
}

// FDE #2092 | PC: 0x082104..0x08210c (8 B) | Symbol: sub_082104
// EN: AArch64 prologue [mov w0, #0x8d67; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x8d67; ret]
uint64_t fde_sub_082104(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x5291ACE0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082104ULL;
}

// FDE #2093 | PC: 0x08210c..0x082140 (52 B) | Symbol: _ZN4lynx6animax21VideoShaderYUVAndroidD1Ev
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; ldr x8, [x8, #0xc30]; mov x1, x0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; ldr x8, [x8, #0xc30]; mov x1, x0]
uint64_t fde_sub_08210c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00000C8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08210CULL;
}

// FDE #2094 | PC: 0x082140..0x082158 (24 B) | Symbol: _ZN4lynx6animax21VideoShaderYUVAndroidD0Ev
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x941f0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x941f0; mov x0, x19]
uint64_t fde_sub_082140(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082140ULL;
}

// FDE #2095 | PC: 0x082158..0x082338 (480 B) | Symbol: _ZN4lynx6animax21VideoShaderYUVAndroid4DrawENSt6__ndk110unique_ptrINS0_11TextureInfoENS2_14default_deleteIS4_EEEERKNS2_5arrayIfLm16EEE
// EN: AArch64 prologue [sub sp, sp, #0x1b0; str x28, [sp, #0x150]; stp x27, x26, [sp, #0x160]; stp x25, x24, [sp, #0x170]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1b0; str x28, [sp, #0x150]; stp x27, x26, [sp, #0x160]; stp x25, x24, [sp, #0x170]]
uint64_t fde_sub_082158(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900ABFCULL) << 32) | 0xD106C3FFULL;
    const uint64_t kPcRange = 0x01E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082158ULL;
}

// FDE #2096 | PC: 0x082338..0x082344 (12 B) | Symbol: _ZNK4lynx6animax21VideoShaderYUVAndroid15GetVertexShaderEv
// EN: AArch64 prologue [adrp x0, #0x20000; add x0, x0, #0x249; ret] | VI: Khởi đầu hàm AArch64 [adrp x0, #0x20000; add x0, x0, #0x249; ret]
uint64_t fde_sub_082338(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91092400ULL) << 32) | 0xD0FFFCE0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082338ULL;
}

// FDE #2097 | PC: 0x082344..0x082350 (12 B) | Symbol: _ZNK4lynx6animax21VideoShaderYUVAndroid17GetFragmentShaderEv
// EN: AArch64 prologue [adrp x0, #0x1f000; add x0, x0, #0x9a6; ret] | VI: Khởi đầu hàm AArch64 [adrp x0, #0x1f000; add x0, x0, #0x9a6; ret]
uint64_t fde_sub_082344(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91269800ULL) << 32) | 0xB0FFFCE0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082344ULL;
}

// FDE #2098 | PC: 0x082350..0x082358 (8 B) | Symbol: _ZN4lynx6animax21VideoShaderYUVAndroid21GetVideoTextureTargetEv
// EN: AArch64 prologue [mov w0, #0xde1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0xde1; ret]
uint64_t fde_sub_082350(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x5281BC20ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082350ULL;
}

// FDE #2099 | PC: 0x082358..0x082360 (8 B) | Symbol: _ZN4lynx6animax21VideoShaderYUVAndroid27GetVideoTextureBindingPointEv
// EN: AArch64 prologue [mov w0, #0x8069; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x8069; ret]
uint64_t fde_sub_082358(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52900D20ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082358ULL;
}

// FDE #2100 | PC: 0x082360..0x0823a0 (64 B) | Symbol: _ZN4lynx6animax13VideoShaderGLD1Ev
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; mov x19, x0; ldr w0, [x0, #8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; mov x19, x0; ldr w0, [x0, #8]]
uint64_t fde_sub_082360(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00000C8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082360ULL;
}

// FDE #2101 | PC: 0x0823a0..0x0823bc (28 B) | Symbol: _ZN4lynx6animax13VideoShaderGL5ValidEv
// EN: AArch64 prologue [ldr w8, [x0, #8]; cbz w8, #0x823b8; ldr w8, [x0, #0xc]; cbz w8, #0x823b8] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #8]; cbz w8, #0x823b8; ldr w8, [x0, #0xc]; cbz w8, #0x823b8]
uint64_t fde_sub_0823a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x340000A8ULL) << 32) | 0xB9400808ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0823A0ULL;
}

// FDE #2102 | PC: 0x0823bc..0x082488 (204 B) | Symbol: _ZN4lynx6animax13VideoShaderGL4InitEiiRKNSt6__ndk15arrayIfLm4EEES6_
// EN: AArch64 prologue [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]]
uint64_t fde_sub_0823bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9009BFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0823BCULL;
}

// FDE #2103 | PC: 0x082488..0x0825d4 (332 B) | Symbol: _ZN4lynx6animax13VideoShaderGL4DrawENSt6__ndk110unique_ptrINS0_11TextureInfoENS2_14default_deleteIS4_EEEERKNS2_5arrayIfLm16EEE
// EN: AArch64 prologue [sub sp, sp, #0x190; str x28, [sp, #0x150]; stp x23, x22, [sp, #0x160]; stp x21, x20, [sp, #0x170]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x190; str x28, [sp, #0x150]; stp x23, x22, [sp, #0x160]; stp x21, x20, [sp, #0x170]]
uint64_t fde_sub_082488(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900ABFCULL) << 32) | 0xD10643FFULL;
    const uint64_t kPcRange = 0x014CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082488ULL;
}

// FDE #2104 | PC: 0x0825d4..0x0826fc (296 B) | Symbol: _ZN4lynx6animax13VideoShaderGL14GetOutputImageEPNS0_11RealContextE
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp x25, x24, [sp, #0x60]; stp x23, x22, [sp, #0x70]; stp x21, x20, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp x25, x24, [sp, #0x60]; stp x23, x22, [sp, #0x70]; stp x21, x20, [sp, #0x80]]
uint64_t fde_sub_0825d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90663F9ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x0128ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0825D4ULL;
}

// FDE #2105 | PC: 0x0826fc..0x08272c (48 B) | Symbol: _ZN4lynx6animax13VideoShaderGL23GetVideoTextureLocationEv
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr w0, [x0, #0x14]; cmn w0, #1] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr w0, [x0, #0x14]; cmn w0, #1]
uint64_t fde_sub_0826fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0826FCULL;
}

// FDE #2106 | PC: 0x08272c..0x0828cc (416 B) | Symbol: _ZN4lynx6animax13VideoShaderGL11InitProgramEv
// EN: AArch64 prologue [stp x28, x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_08272c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xA9BC63FCULL;
    const uint64_t kPcRange = 0x01A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08272CULL;
}

// FDE #2107 | PC: 0x0828cc..0x082940 (116 B) | Symbol: _ZN4lynx6animax13VideoShaderGL15InitFramebufferEv
// EN: AArch64 prologue [sub sp, sp, #0x50; str x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]; mrs x20, tpidr_el0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]; mrs x20, tpidr_el0]
uint64_t fde_sub_0828cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF4ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0828CCULL;
}

// FDE #2108 | PC: 0x082940..0x082a54 (276 B) | Symbol: _ZN4lynx6animax13VideoShaderGL13OnInitTextureEv
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x21, x20, [sp, #0x60]; stp x19, x30, [sp, #0x70]; bl #0x8e168] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x21, x20, [sp, #0x60]; stp x19, x30, [sp, #0x70]; bl #0x8e168]
uint64_t fde_sub_082940(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90653F5ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082940ULL;
}

// FDE #2109 | PC: 0x082a54..0x082a84 (48 B) | Symbol: _ZN4lynx6animax13VideoShaderGL19GetRGBFrameLocationEv
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr w0, [x0, #0x18]; cmn w0, #1] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr w0, [x0, #0x18]; cmn w0, #1]
uint64_t fde_sub_082a54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082A54ULL;
}

// FDE #2110 | PC: 0x082a84..0x082ab4 (48 B) | Symbol: _ZN4lynx6animax13VideoShaderGL17GetAFrameLocationEv
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr w0, [x0, #0x1c]; cmn w0, #1] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr w0, [x0, #0x1c]; cmn w0, #1]
uint64_t fde_sub_082a84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082A84ULL;
}

// FDE #2111 | PC: 0x082ab4..0x082ad4 (32 B) | Symbol: sub_082ab4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; add x8, x8, #0x108; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; add x8, x8, #0x108; mov x19, x0]
uint64_t fde_sub_082ab4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00000C8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082AB4ULL;
}

// FDE #2112 | PC: 0x082ad4..0x082aec (24 B) | Symbol: sub_082ad4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x82ab4; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x82ab4; mov x0, x19]
uint64_t fde_sub_082ad4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082AD4ULL;
}

// FDE #2113 | PC: 0x082aec..0x082bb0 (196 B) | Symbol: sub_082aec
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x23, x22, [sp, #0x50]; stp x21, x20, [sp, #0x60]; stp x19, x30, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x23, x22, [sp, #0x50]; stp x21, x20, [sp, #0x60]; stp x19, x30, [sp, #0x70]]
uint64_t fde_sub_082aec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9055BF7ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082AECULL;
}

// FDE #2114 | PC: 0x082bb0..0x082bbc (12 B) | Symbol: sub_082bb0
// EN: AArch64 prologue [adrp x8, #0x9d000; add x8, x8, #0x128; b #0x9224c] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9d000; add x8, x8, #0x128; b #0x9224c]
uint64_t fde_sub_082bb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9104A108ULL) << 32) | 0xF00000C8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082BB0ULL;
}

// FDE #2115 | PC: 0x082bbc..0x082bd4 (24 B) | Symbol: sub_082bbc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x82bb0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x82bb0; mov x0, x19]
uint64_t fde_sub_082bbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082BBCULL;
}

// FDE #2116 | PC: 0x082bd4..0x082d28 (340 B) | Symbol: sub_082bd4
// EN: AArch64 prologue [sub sp, sp, #0x170; str d12, [sp, #0xf0]; stp d11, d10, [sp, #0x100]; stp d9, d8, [sp, #0x110]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; str d12, [sp, #0xf0]; stp d11, d10, [sp, #0x100]; stp d9, d8, [sp, #0x110]]
uint64_t fde_sub_082bd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD007BECULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x0154ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082BD4ULL;
}

// FDE #2117 | PC: 0x082d28..0x0830f8 (976 B) | Symbol: sub_082d28
// EN: AArch64 prologue [sub sp, sp, #0x150; str d10, [sp, #0xd0]; stp d9, d8, [sp, #0xe0]; stp x28, x27, [sp, #0xf0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x150; str d10, [sp, #0xd0]; stp d9, d8, [sp, #0xe0]; stp x28, x27, [sp, #0xf0]]
uint64_t fde_sub_082d28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD006BEAULL) << 32) | 0xD10543FFULL;
    const uint64_t kPcRange = 0x03D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x082D28ULL;
}

// FDE #2118 | PC: 0x0830f8..0x083130 (56 B) | Symbol: sub_0830f8
// EN: AArch64 prologue [sub sp, sp, #0x120; str x28, [sp, #0x100]; stp x19, x30, [sp, #0x110]; bl #0x8d3e8] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; str x28, [sp, #0x100]; stp x19, x30, [sp, #0x110]; bl #0x8d3e8]
uint64_t fde_sub_0830f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90083FCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0830F8ULL;
}

// FDE #2119 | PC: 0x083130..0x083170 (64 B) | Symbol: sub_083130
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x92fc4; mov x19, x1] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x92fc4; mov x19, x1]
uint64_t fde_sub_083130(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x083130ULL;
}

// FDE #2120 | PC: 0x083170..0x083190 (32 B) | Symbol: sub_083170
// EN: AArch64 prologue [ldrb w8, [x0, #0x28]; adrp x9, #0x9d000; add x9, x9, #0x170; str x9, [x0]] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x28]; adrp x9, #0x9d000; add x9, x9, #0x170; str x9, [x0]]
uint64_t fde_sub_083170(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00000C9ULL) << 32) | 0x3940A008ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x083170ULL;
}

// FDE #2121 | PC: 0x083190..0x0831b0 (32 B) | Symbol: sub_083190
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; add x8, x8, #0x150; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; add x8, x8, #0x150; mov x19, x0]
uint64_t fde_sub_083190(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00000C8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x083190ULL;
}

// FDE #2122 | PC: 0x0831b0..0x0831c8 (24 B) | Symbol: sub_0831b0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x83190; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x83190; mov x0, x19]
uint64_t fde_sub_0831b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0831B0ULL;
}

// FDE #2123 | PC: 0x0831c8..0x0831e0 (24 B) | Symbol: sub_0831c8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x83170; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x83170; mov x0, x19]
uint64_t fde_sub_0831c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0831C8ULL;
}

// FDE #2124 | PC: 0x0831e0..0x083204 (36 B) | Symbol: sub_0831e0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; ldr x8, [x1, #0x10]; ldr q0, [x1]; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; ldr x8, [x1, #0x10]; ldr q0, [x1]; mov x19, x0]
uint64_t fde_sub_0831e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400828ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0831E0ULL;
}

// FDE #2125 | PC: 0x083204..0x0834d0 (716 B) | Symbol: sub_083204
// EN: AArch64 prologue [sub sp, sp, #0x90; str d10, [sp, #0x30]; stp d9, d8, [sp, #0x40]; stp x25, x24, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str d10, [sp, #0x30]; stp d9, d8, [sp, #0x40]; stp x25, x24, [sp, #0x50]]
uint64_t fde_sub_083204(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD001BEAULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x02CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x083204ULL;
}

// FDE #2126 | PC: 0x0834d0..0x08356c (156 B) | Symbol: sub_0834d0
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_0834d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9025BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0834D0ULL;
}

// FDE #2127 | PC: 0x08356c..0x0837f8 (652 B) | Symbol: sub_08356c
// EN: AArch64 prologue [sub sp, sp, #0x110; str x28, [sp, #0xc0]; stp x25, x24, [sp, #0xd0]; stp x23, x22, [sp, #0xe0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; str x28, [sp, #0xc0]; stp x25, x24, [sp, #0xd0]; stp x23, x22, [sp, #0xe0]]
uint64_t fde_sub_08356c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90063FCULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x028CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08356CULL;
}

// FDE #2128 | PC: 0x0837f8..0x08382c (52 B) | Symbol: sub_0837f8
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x74ab0; adrp x19, #0xa0000] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x74ab0; adrp x19, #0xa0000]
uint64_t fde_sub_0837f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0837F8ULL;
}

// FDE #2129 | PC: 0x08382c..0x0839e4 (440 B) | Symbol: sub_08382c
// EN: AArch64 prologue [sub sp, sp, #0x160; str d8, [sp, #0x120]; stp x28, x22, [sp, #0x130]; stp x21, x20, [sp, #0x140]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; str d8, [sp, #0x120]; stp x28, x22, [sp, #0x130]; stp x21, x20, [sp, #0x140]]
uint64_t fde_sub_08382c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0093E8ULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x01B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08382CULL;
}

// FDE #2130 | PC: 0x0839e4..0x083b9c (440 B) | Symbol: sub_0839e4
// EN: AArch64 prologue [sub sp, sp, #0x160; str d8, [sp, #0x120]; stp x28, x22, [sp, #0x130]; stp x21, x20, [sp, #0x140]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; str d8, [sp, #0x120]; stp x28, x22, [sp, #0x130]; stp x21, x20, [sp, #0x140]]
uint64_t fde_sub_0839e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0093E8ULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x01B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0839E4ULL;
}

// FDE #2131 | PC: 0x083b9c..0x083be4 (72 B) | Symbol: sub_083b9c
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x0] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x0]
uint64_t fde_sub_083b9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x083B9CULL;
}

// FDE #2132 | PC: 0x083be4..0x083bf4 (16 B) | Symbol: sub_083be4
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x9d000; add x9, x9, #0x1f0; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x9d000; add x9, x9, #0x1f0; b #0x8d518]
uint64_t fde_sub_083be4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00000C9ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x083BE4ULL;
}

// FDE #2133 | PC: 0x083bf4..0x083c0c (24 B) | Symbol: sub_083bf4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x83be4; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x83be4; mov x0, x19]
uint64_t fde_sub_083bf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x083BF4ULL;
}

// FDE #2134 | PC: 0x083c0c..0x083ca0 (148 B) | Symbol: sub_083c0c
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x23, x22, [sp, #0x60]; stp x21, x20, [sp, #0x70]; stp x19, x30, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x23, x22, [sp, #0x60]; stp x21, x20, [sp, #0x70]; stp x19, x30, [sp, #0x80]]
uint64_t fde_sub_083c0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9065BF7ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x083C0CULL;
}

// FDE #2135 | PC: 0x083ca0..0x083cb4 (20 B) | Symbol: sub_083ca0
// EN: AArch64 prologue [ldr x8, [x1, #0x10]; str x8, [x0, #0x10]; ldr x2, [x1, #8]; mov x1, x8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1, #0x10]; str x8, [x0, #0x10]; ldr x2, [x1, #8]; mov x1, x8]
uint64_t fde_sub_083ca0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000808ULL) << 32) | 0xF9400828ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x083CA0ULL;
}

// FDE #2136 | PC: 0x083cb4..0x083cd0 (28 B) | Symbol: sub_083cb4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; add x8, x8, #0x218; bl #0x8daa4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; add x8, x8, #0x218; bl #0x8daa4]
uint64_t fde_sub_083cb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00000C8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x083CB4ULL;
}

// FDE #2137 | PC: 0x083cd0..0x083ce8 (24 B) | Symbol: sub_083cd0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x83cb4; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x83cb4; mov x0, x19]
uint64_t fde_sub_083cd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x083CD0ULL;
}

// FDE #2138 | PC: 0x083ce8..0x083cf0 (8 B) | Symbol: sub_083ce8
// EN: AArch64 prologue [add x0, x0, #0x18; b #0x7d610] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x18; b #0x7d610]
uint64_t fde_sub_083ce8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFE649ULL) << 32) | 0x91006000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x083CE8ULL;
}

// FDE #2139 | PC: 0x083cf0..0x083d1c (44 B) | Symbol: sub_083cf0
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8ec8c; bl #0x91828] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8ec8c; bl #0x91828]
uint64_t fde_sub_083cf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x083CF0ULL;
}

// FDE #2140 | PC: 0x083d1c..0x083d70 (84 B) | Symbol: sub_083d1c
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x5, #0xa0000; add x5, x5, #0x4e0] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x5, #0xa0000; add x5, x5, #0x4e0]
uint64_t fde_sub_083d1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x083D1CULL;
}

// FDE #2141 | PC: 0x083d70..0x083da0 (48 B) | Symbol: sub_083d70
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8ec8c; adrp x8, #0x9c000] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8ec8c; adrp x8, #0x9c000]
uint64_t fde_sub_083d70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x083D70ULL;
}

// FDE #2142 | PC: 0x083da0..0x0840f8 (856 B) | Symbol: sub_083da0
// EN: AArch64 prologue [stp x28, x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_083da0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xA9BC63FCULL;
    const uint64_t kPcRange = 0x0358ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x083DA0ULL;
}

// FDE #2143 | PC: 0x0840f8..0x084168 (112 B) | Symbol: sub_0840f8
// EN: AArch64 prologue [sub sp, sp, #0x70; str x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]]
uint64_t fde_sub_0840f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F6ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0840F8ULL;
}

// FDE #2144 | PC: 0x084168..0x084188 (32 B) | Symbol: sub_084168
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e128; bl #0x7f4a0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e128; bl #0x7f4a0]
uint64_t fde_sub_084168(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x084168ULL;
}

// FDE #2145 | PC: 0x084188..0x0841c8 (64 B) | Symbol: sub_084188
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x91ac4; mov x19, x1] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x91ac4; mov x19, x1]
uint64_t fde_sub_084188(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x084188ULL;
}

// FDE #2146 | PC: 0x0841c8..0x0841d4 (12 B) | Symbol: sub_0841c8
// EN: AArch64 prologue [mov x2, x1; mov x1, xzr; b #0x93900] | VI: Khởi đầu hàm AArch64 [mov x2, x1; mov x1, xzr; b #0x93900]
uint64_t fde_sub_0841c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E1ULL) << 32) | 0xAA0103E2ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0841C8ULL;
}

// FDE #2147 | PC: 0x0841d4..0x084778 (1444 B) | Symbol: sub_0841d4
// EN: AArch64 prologue [sub sp, sp, #0xd0; stp x28, x27, [sp, #0x70]; stp x26, x25, [sp, #0x80]; stp x24, x23, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xd0; stp x28, x27, [sp, #0x70]; stp x26, x25, [sp, #0x80]; stp x24, x23, [sp, #0x90]]
uint64_t fde_sub_0841d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9076FFCULL) << 32) | 0xD10343FFULL;
    const uint64_t kPcRange = 0x05A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0841D4ULL;
}

// FDE #2148 | PC: 0x084778..0x0847a4 (44 B) | Symbol: sub_084778
// EN: AArch64 prologue [cbz x2, #0x847a0; stp x19, x30, [sp, #-0x10]!; ldr x0, [x2, #0x18]; mov x19, x2] | VI: Khởi đầu hàm AArch64 [cbz x2, #0x847a0; stp x19, x30, [sp, #-0x10]!; ldr x0, [x2, #0x18]; mov x19, x2]
uint64_t fde_sub_084778(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BF3ULL) << 32) | 0xB4000142ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x084778ULL;
}

// FDE #2149 | PC: 0x0847a4..0x084954 (432 B) | Symbol: sub_0847a4
// EN: AArch64 prologue [sub sp, sp, #0xc0; stp x25, x24, [sp, #0x80]; stp x23, x22, [sp, #0x90]; stp x21, x20, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; stp x25, x24, [sp, #0x80]; stp x23, x22, [sp, #0x90]; stp x21, x20, [sp, #0xa0]]
uint64_t fde_sub_0847a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90863F9ULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x01B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0847A4ULL;
}

// FDE #2150 | PC: 0x084954..0x084974 (32 B) | Symbol: sub_084954
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; add x8, x8, #0x2b0; bl #0x8daa4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; add x8, x8, #0x2b0; bl #0x8daa4]
uint64_t fde_sub_084954(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00000C8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x084954ULL;
}

// FDE #2151 | PC: 0x084974..0x08498c (24 B) | Symbol: sub_084974
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x84954; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x84954; mov x0, x19]
uint64_t fde_sub_084974(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x084974ULL;
}

// FDE #2152 | PC: 0x08498c..0x0849b8 (44 B) | Symbol: sub_08498c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8eb7c; adrp x8, #0x9d000; add x8, x8, #0x338] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8eb7c; adrp x8, #0x9d000; add x8, x8, #0x338]
uint64_t fde_sub_08498c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400287BULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08498CULL;
}

// FDE #2153 | PC: 0x0849b8..0x084c7c (708 B) | Symbol: sub_0849b8
// EN: AArch64 prologue [sub sp, sp, #0x160; str x28, [sp, #0x110]; stp x25, x24, [sp, #0x120]; stp x23, x22, [sp, #0x130]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; str x28, [sp, #0x110]; stp x25, x24, [sp, #0x120]; stp x23, x22, [sp, #0x130]]
uint64_t fde_sub_0849b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9008BFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x02C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0849B8ULL;
}

// FDE #2154 | PC: 0x084c7c..0x084cfc (128 B) | Symbol: sub_084c7c
// EN: AArch64 prologue [sub sp, sp, #0x70; str x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]]
uint64_t fde_sub_084c7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F6ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x084C7CULL;
}

// FDE #2155 | PC: 0x084cfc..0x084d04 (8 B) | Symbol: sub_084cfc
// EN: AArch64 prologue [ldr x0, [x0, #0x10]; b #0x48d40] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x10]; b #0x48d40]
uint64_t fde_sub_084cfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF1010ULL) << 32) | 0xF9400800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x084CFCULL;
}

// FDE #2156 | PC: 0x084d04..0x084d1c (24 B) | Symbol: sub_084d04
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8db6c; bl #0x48d40; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8db6c; bl #0x48d40; mov x0, x19]
uint64_t fde_sub_084d04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94002399ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x084D04ULL;
}

// FDE #2157 | PC: 0x084d1c..0x084fac (656 B) | Symbol: sub_084d1c
// EN: AArch64 prologue [sub sp, sp, #0x120; str x28, [sp, #0xd0]; stp x25, x24, [sp, #0xe0]; stp x23, x22, [sp, #0xf0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; str x28, [sp, #0xd0]; stp x25, x24, [sp, #0xe0]; stp x23, x22, [sp, #0xf0]]
uint64_t fde_sub_084d1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9006BFCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x0290ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x084D1CULL;
}

// FDE #2158 | PC: 0x084fac..0x084fcc (32 B) | Symbol: sub_084fac
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; add x8, x8, #0x310; bl #0x8daa4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; add x8, x8, #0x310; bl #0x8daa4]
uint64_t fde_sub_084fac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00000C8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x084FACULL;
}

// FDE #2159 | PC: 0x084fcc..0x084fe4 (24 B) | Symbol: sub_084fcc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x84fac; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x84fac; mov x0, x19]
uint64_t fde_sub_084fcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x084FCCULL;
}

// FDE #2160 | PC: 0x084fe4..0x085070 (140 B) | Symbol: sub_084fe4
// EN: AArch64 prologue [sub sp, sp, #0x50; str x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_084fe4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x084FE4ULL;
}

// FDE #2161 | PC: 0x085070..0x085074 (4 B) | Symbol: sub_085070
// EN: AArch64 prologue [b #0x931d0] | VI: Khởi đầu hàm AArch64 [b #0x931d0]
uint64_t fde_sub_085070(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10483FFULL) << 32) | 0x14003858ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085070ULL;
}

// FDE #2162 | PC: 0x085074..0x0850a0 (44 B) | Symbol: sub_085074
// EN: AArch64 prologue [sub sp, sp, #0x120; str x28, [sp, #0x100]; stp x19, x30, [sp, #0x110]; bl #0x8d3e8] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; str x28, [sp, #0x100]; stp x19, x30, [sp, #0x110]; bl #0x8d3e8]
uint64_t fde_sub_085074(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90083FCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085074ULL;
}

// FDE #2163 | PC: 0x0850a0..0x0850cc (44 B) | Symbol: sub_0850a0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8eb7c; adrp x8, #0x9d000; add x8, x8, #0x388] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8eb7c; adrp x8, #0x9d000; add x8, x8, #0x388]
uint64_t fde_sub_0850a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940026B6ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0850A0ULL;
}

// FDE #2164 | PC: 0x0850cc..0x0850e4 (24 B) | Symbol: sub_0850cc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x850a0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x850a0; mov x0, x19]
uint64_t fde_sub_0850cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0850CCULL;
}

// FDE #2165 | PC: 0x0850e4..0x085184 (160 B) | Symbol: sub_0850e4
// EN: AArch64 prologue [sub sp, sp, #0xd0; str x24, [sp, #0x90]; stp x23, x22, [sp, #0xa0]; stp x21, x20, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xd0; str x24, [sp, #0x90]; stp x23, x22, [sp, #0xa0]; stp x21, x20, [sp, #0xb0]]
uint64_t fde_sub_0850e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9004BF8ULL) << 32) | 0xD10343FFULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0850E4ULL;
}

// FDE #2166 | PC: 0x085184..0x085194 (16 B) | Symbol: sub_085184
// EN: AArch64 prologue [adrp x8, #0x9d000; add x8, x8, #0x3b0; str x8, [x0], #8; b #0x54044] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9d000; add x8, x8, #0x3b0; str x8, [x0], #8; b #0x54044]
uint64_t fde_sub_085184(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910EC108ULL) << 32) | 0x900000C8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085184ULL;
}

// FDE #2167 | PC: 0x085194..0x0851ac (24 B) | Symbol: sub_085194
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x85184; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x85184; mov x0, x19]
uint64_t fde_sub_085194(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085194ULL;
}

// FDE #2168 | PC: 0x0851ac..0x08529c (240 B) | Symbol: sub_0851ac
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x21, x20, [sp, #0x90]; stp x19, x30, [sp, #0xa0]; bl #0x8e168] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x21, x20, [sp, #0x90]; stp x19, x30, [sp, #0xa0]; bl #0x8e168]
uint64_t fde_sub_0851ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90953F5ULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x00F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0851ACULL;
}

// FDE #2169 | PC: 0x08529c..0x0852dc (64 B) | Symbol: sub_08529c
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9d000; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9d000; mov x19, x0]
uint64_t fde_sub_08529c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08529CULL;
}

// FDE #2170 | PC: 0x0852dc..0x0852f4 (24 B) | Symbol: sub_0852dc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x8529c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x8529c; mov x0, x19]
uint64_t fde_sub_0852dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0852DCULL;
}

// FDE #2171 | PC: 0x0852f4..0x085404 (272 B) | Symbol: sub_0852f4
// EN: AArch64 prologue [sub sp, sp, #0xf0; stp x23, x22, [sp, #0xc0]; stp x21, x20, [sp, #0xd0]; stp x19, x30, [sp, #0xe0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xf0; stp x23, x22, [sp, #0xc0]; stp x21, x20, [sp, #0xd0]; stp x19, x30, [sp, #0xe0]]
uint64_t fde_sub_0852f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90C5BF7ULL) << 32) | 0xD103C3FFULL;
    const uint64_t kPcRange = 0x0110ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0852F4ULL;
}

// FDE #2172 | PC: 0x085404..0x08541c (24 B) | Symbol: sub_085404
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x8498c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x8498c; mov x0, x19]
uint64_t fde_sub_085404(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085404ULL;
}

// FDE #2173 | PC: 0x08541c..0x085490 (116 B) | Symbol: sub_08541c
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x21, x20, [sp, #0x70]; stp x19, x30, [sp, #0x80]; mrs x21, tpidr_el0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x21, x20, [sp, #0x70]; stp x19, x30, [sp, #0x80]; mrs x21, tpidr_el0]
uint64_t fde_sub_08541c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90753F5ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08541CULL;
}

// FDE #2174 | PC: 0x085490..0x08553c (172 B) | Symbol: sub_085490
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_085490(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085490ULL;
}

// FDE #2175 | PC: 0x08553c..0x08554c (16 B) | Symbol: sub_08553c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8eb88; ldp x19, x30, [sp], #0x10; b #0x932e0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8eb88; ldp x19, x30, [sp], #0x10; b #0x932e0]
uint64_t fde_sub_08553c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94002592ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08553CULL;
}

// FDE #2176 | PC: 0x08554c..0x085694 (328 B) | Symbol: sub_08554c
// EN: AArch64 prologue [sub sp, sp, #0x110; stp x28, x24, [sp, #0xd0]; stp x23, x22, [sp, #0xe0]; stp x21, x20, [sp, #0xf0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; stp x28, x24, [sp, #0xd0]; stp x23, x22, [sp, #0xe0]; stp x21, x20, [sp, #0xf0]]
uint64_t fde_sub_08554c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90D63FCULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x0148ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08554CULL;
}

// FDE #2177 | PC: 0x085694..0x0856bc (40 B) | Symbol: sub_085694
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; str wzr, [x0], #8] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; str wzr, [x0], #8]
uint64_t fde_sub_085694(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085694ULL;
}

// FDE #2178 | PC: 0x0856bc..0x085734 (120 B) | Symbol: sub_0856bc
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x21, x20, [sp, #0x70]; stp x19, x30, [sp, #0x80]; mrs x21, tpidr_el0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x21, x20, [sp, #0x70]; stp x19, x30, [sp, #0x80]; mrs x21, tpidr_el0]
uint64_t fde_sub_0856bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90753F5ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0856BCULL;
}

// FDE #2179 | PC: 0x085734..0x085768 (52 B) | Symbol: sub_085734
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov w8, #2; str w8, [x0]; ldr x8, [x1, #0x10]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov w8, #2; str w8, [x0]; ldr x8, [x1, #0x10]]
uint64_t fde_sub_085734(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800048ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085734ULL;
}

// FDE #2180 | PC: 0x085768..0x085978 (528 B) | Symbol: sub_085768
// EN: AArch64 prologue [sub sp, sp, #0x1b0; stp x28, x24, [sp, #0x170]; stp x23, x22, [sp, #0x180]; stp x21, x20, [sp, #0x190]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1b0; stp x28, x24, [sp, #0x170]; stp x23, x22, [sp, #0x180]; stp x21, x20, [sp, #0x190]]
uint64_t fde_sub_085768(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA91763FCULL) << 32) | 0xD106C3FFULL;
    const uint64_t kPcRange = 0x0210ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085768ULL;
}

// FDE #2181 | PC: 0x085978..0x085a64 (236 B) | Symbol: sub_085978
// EN: AArch64 prologue [sub sp, sp, #0xe0; stp x21, x20, [sp, #0xc0]; stp x19, x30, [sp, #0xd0]; mrs x21, tpidr_el0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xe0; stp x21, x20, [sp, #0xc0]; stp x19, x30, [sp, #0xd0]; mrs x21, tpidr_el0]
uint64_t fde_sub_085978(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90C53F5ULL) << 32) | 0xD10383FFULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085978ULL;
}

// FDE #2182 | PC: 0x085a64..0x085a88 (36 B) | Symbol: sub_085a64
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8e7ac; adrp x8, #0x9d000; add x8, x8, #0x4a0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8e7ac; adrp x8, #0x9d000; add x8, x8, #0x4a0]
uint64_t fde_sub_085a64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94002351ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085A64ULL;
}

// FDE #2183 | PC: 0x085a88..0x085aa0 (24 B) | Symbol: sub_085a88
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x85a64; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x85a64; mov x0, x19]
uint64_t fde_sub_085a88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085A88ULL;
}

// FDE #2184 | PC: 0x085aa0..0x085b74 (212 B) | Symbol: sub_085aa0
// EN: AArch64 prologue [sub sp, sp, #0x90; str x24, [sp, #0x50]; stp x23, x22, [sp, #0x60]; stp x21, x20, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x24, [sp, #0x50]; stp x23, x22, [sp, #0x60]; stp x21, x20, [sp, #0x70]]
uint64_t fde_sub_085aa0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9002BF8ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085AA0ULL;
}

// FDE #2185 | PC: 0x085b74..0x085b98 (36 B) | Symbol: sub_085b74
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8e7ac; bl #0x44830; ldr x0, [x19, #0x18]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8e7ac; bl #0x44830; ldr x0, [x19, #0x18]]
uint64_t fde_sub_085b74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400230DULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085B74ULL;
}

// FDE #2186 | PC: 0x085b98..0x085ba8 (16 B) | Symbol: sub_085b98
// EN: AArch64 prologue [adrp x8, #0x9d000; add x8, x8, #0x4c8; str x8, [x0], #8; b #0x85b74] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9d000; add x8, x8, #0x4c8; str x8, [x0], #8; b #0x85b74]
uint64_t fde_sub_085b98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91132108ULL) << 32) | 0x900000C8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085B98ULL;
}

// FDE #2187 | PC: 0x085ba8..0x085bc0 (24 B) | Symbol: sub_085ba8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x85b98; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x85b98; mov x0, x19]
uint64_t fde_sub_085ba8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085BA8ULL;
}

// FDE #2188 | PC: 0x085bc0..0x085c4c (140 B) | Symbol: sub_085bc0
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]; bl #0x8ecb8] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]; bl #0x8ecb8]
uint64_t fde_sub_085bc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90453F5ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085BC0ULL;
}

// FDE #2189 | PC: 0x085c4c..0x086024 (984 B) | Symbol: sub_085c4c
// EN: AArch64 prologue [mov x0, x30; bl #0x8d63c; mov x30, x0; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x0, x30; bl #0x8d63c; mov x30, x0; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_085c4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94001E7BULL) << 32) | 0xAA1E03E0ULL;
    const uint64_t kPcRange = 0x03D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085C4CULL;
}

// FDE #2190 | PC: 0x086024..0x086088 (100 B) | Symbol: sub_086024
// EN: AArch64 prologue [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; adrp x8, #0x9d000] | VI: Khởi đầu hàm AArch64 [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; adrp x8, #0x9d000]
uint64_t fde_sub_086024(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xA9BD5BF7ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x086024ULL;
}

// FDE #2191 | PC: 0x086088..0x0860a0 (24 B) | Symbol: sub_086088
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x86024; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x86024; mov x0, x19]
uint64_t fde_sub_086088(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x086088ULL;
}

// FDE #2192 | PC: 0x0860a0..0x0861ac (268 B) | Symbol: sub_0860a0
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x23, x22, [sp, #0x80]; stp x21, x20, [sp, #0x90]; stp x19, x30, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x23, x22, [sp, #0x80]; stp x21, x20, [sp, #0x90]; stp x19, x30, [sp, #0xa0]]
uint64_t fde_sub_0860a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9085BF7ULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0860A0ULL;
}

// FDE #2193 | PC: 0x0861ac..0x0861cc (32 B) | Symbol: sub_0861ac
// EN: AArch64 prologue [mov x8, x0; ldr x0, [x0, #8]; adrp x9, #0x9d000; add x9, x9, #0x518] | VI: Khởi đầu hàm AArch64 [mov x8, x0; ldr x0, [x0, #8]; adrp x9, #0x9d000; add x9, x9, #0x518]
uint64_t fde_sub_0861ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400400ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0861ACULL;
}

// FDE #2194 | PC: 0x0861cc..0x0861e4 (24 B) | Symbol: sub_0861cc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x861ac; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x861ac; mov x0, x19]
uint64_t fde_sub_0861cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0861CCULL;
}

// FDE #2195 | PC: 0x0861e4..0x086260 (124 B) | Symbol: sub_0861e4
// EN: AArch64 prologue [sub sp, sp, #0xc0; stp x21, x20, [sp, #0xa0]; stp x19, x30, [sp, #0xb0]; mov x20, x0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; stp x21, x20, [sp, #0xa0]; stp x19, x30, [sp, #0xb0]; mov x20, x0]
uint64_t fde_sub_0861e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90A53F5ULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0861E4ULL;
}

// FDE #2196 | PC: 0x086260..0x0862e8 (136 B) | Symbol: sub_086260
// EN: AArch64 prologue [sub sp, sp, #0x40; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8ee78] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8ee78]
uint64_t fde_sub_086260(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F4ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x086260ULL;
}

// FDE #2197 | PC: 0x0862e8..0x086308 (32 B) | Symbol: sub_0862e8
// EN: AArch64 prologue [cbz x0, #0x86304; stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x44a54] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x86304; stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x44a54]
uint64_t fde_sub_0862e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BF3ULL) << 32) | 0xB40000E0ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0862E8ULL;
}

// FDE #2198 | PC: 0x086308..0x08631c (20 B) | Symbol: _ZN4lynx6animax13AnimaXKeyPathC1Ev
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0xca8; stp x8, xzr, [x0]; stp xzr, xzr, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0xca8; stp x8, xzr, [x0]; stp xzr, xzr, [x0, #0x10]]
uint64_t fde_sub_086308(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9132A108ULL) << 32) | 0xF0000088ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x086308ULL;
}

// FDE #2199 | PC: 0x08631c..0x08632c (16 B) | Symbol: _ZN4lynx6animax13AnimaXKeyPathC1ERKNSt6__ndk16vectorINS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEENS7_IS9_EEEE
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0xca8; str x8, [x0], #8; b #0x8632c] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0xca8; str x8, [x0], #8; b #0x8632c]
uint64_t fde_sub_08631c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9132A108ULL) << 32) | 0xF0000088ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08631CULL;
}

// FDE #2200 | PC: 0x08632c..0x086380 (84 B) | Symbol: sub_08632c
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; stp xzr, xzr, [x0]; str xzr, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; stp xzr, xzr, [x0]; str xzr, [x0, #0x10]]
uint64_t fde_sub_08632c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08632CULL;
}

// FDE #2201 | PC: 0x086380..0x0863bc (60 B) | Symbol: sub_086380
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x8, #-0x5555555555555556; movk x8, #0xaaab] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x8, #-0x5555555555555556; movk x8, #0xaaab]
uint64_t fde_sub_086380(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x086380ULL;
}

// FDE #2202 | PC: 0x0863bc..0x086400 (68 B) | Symbol: sub_0863bc
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr x21, [x0, #8]] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr x21, [x0, #8]]
uint64_t fde_sub_0863bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0863BCULL;
}

// FDE #2203 | PC: 0x086400..0x086414 (20 B) | Symbol: _ZN4lynx6animax13AnimaXKeyPathC2ERKS1_
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0xca8; str x8, [x0], #8; add x1, x1, #8] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0xca8; str x8, [x0], #8; add x1, x1, #8]
uint64_t fde_sub_086400(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9132A108ULL) << 32) | 0xF0000088ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x086400ULL;
}

// FDE #2204 | PC: 0x086414..0x086464 (80 B) | Symbol: _ZNK4lynx6animax13AnimaXKeyPath6AddKeyERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; mrs x21, tpidr_el0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; mrs x21, tpidr_el0]
uint64_t fde_sub_086414(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90253F5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x086414ULL;
}

// FDE #2205 | PC: 0x086464..0x086500 (156 B) | Symbol: _ZNK4lynx6animax13AnimaXKeyPath7MatchesERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEi
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x1; adrp x1, #0x1b000] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x1; adrp x1, #0x1b000]
uint64_t fde_sub_086464(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x086464ULL;
}

// FDE #2206 | PC: 0x086500..0x086514 (20 B) | Symbol: _ZNK4lynx6animax13AnimaXKeyPath11IsContainerERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE
// EN: AArch64 prologue [adrp x8, #0x1b000; add x8, x8, #0xe34; mov x0, x1; mov x1, x8] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x1b000; add x8, x8, #0xe34; mov x0, x1; mov x1, x8]
uint64_t fde_sub_086500(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9138D108ULL) << 32) | 0xB0FFFCA8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x086500ULL;
}

// FDE #2207 | PC: 0x086514..0x0865c8 (180 B) | Symbol: _ZNK4lynx6animax13AnimaXKeyPath16IncrementDepthByERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEi
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x1] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x1]
uint64_t fde_sub_086514(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x00B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x086514ULL;
}

// FDE #2208 | PC: 0x0865c8..0x08671c (340 B) | Symbol: _ZNK4lynx6animax13AnimaXKeyPath15FullyResolvesToERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEi
// EN: AArch64 prologue [stp x25, x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x25, x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_0865c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xA9BC63F9ULL;
    const uint64_t kPcRange = 0x0154ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0865C8ULL;
}

// FDE #2209 | PC: 0x08671c..0x08674c (48 B) | Symbol: _ZNK4lynx6animax13AnimaXKeyPath16EndsWithGlobstarEv
// EN: AArch64 prologue [ldp x8, x9, [x0, #8]; cmp x8, x9; b.eq #0x86748; sub x9, x9, x8] | VI: Khởi đầu hàm AArch64 [ldp x8, x9, [x0, #8]; cmp x8, x9; b.eq #0x86748; sub x9, x9, x8]
uint64_t fde_sub_08671c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xA940A408ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08671CULL;
}

// FDE #2210 | PC: 0x08674c..0x0867cc (128 B) | Symbol: _ZNK4lynx6animax13AnimaXKeyPath19PropagateToChildrenERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEi
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; tbnz w2, #0x1f, #0x86798; adrp x8, #0x1b000] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; tbnz w2, #0x1f, #0x86798; adrp x8, #0x1b000]
uint64_t fde_sub_08674c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08674CULL;
}

// FDE #2211 | PC: 0x0867cc..0x0867dc (16 B) | Symbol: _ZNK4lynx6animax13AnimaXKeyPath14GetDescriptionEv
// EN: AArch64 prologue [adrp x1, #0x1e000; add x0, x0, #8; add x1, x1, #0xcce; b #0x93b90] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x1e000; add x0, x0, #8; add x1, x1, #0xcce; b #0x93b90]
uint64_t fde_sub_0867cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91002000ULL) << 32) | 0x90FFFCC1ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0867CCULL;
}

// FDE #2212 | PC: 0x0867dc..0x08683c (96 B) | Symbol: _ZN4lynx6animax18AnimaXPlayerGlobal4FindERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; mov x19, x8] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; mov x19, x8]
uint64_t fde_sub_0867dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0867DCULL;
}

// FDE #2213 | PC: 0x08683c..0x086884 (72 B) | Symbol: sub_08683c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0xa0000; add x8, x8, #0x5b0; ldarb w8, [x8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0xa0000; add x8, x8, #0x5b0; ldarb w8, [x8]]
uint64_t fde_sub_08683c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00000C8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08683CULL;
}

// FDE #2214 | PC: 0x086884..0x0868d8 (84 B) | Symbol: sub_086884
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0xa0000; add x8, x8, #0x5a8; ldarb w8, [x8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0xa0000; add x8, x8, #0x5a8; ldarb w8, [x8]]
uint64_t fde_sub_086884(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00000C8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x086884ULL;
}

// FDE #2215 | PC: 0x0868d8..0x0869ac (212 B) | Symbol: sub_0868d8
// EN: AArch64 prologue [stp x25, x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x25, x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_0868d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xA9BC63F9ULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0868D8ULL;
}

// FDE #2216 | PC: 0x0869ac..0x086c6c (704 B) | Symbol: _ZN4lynx6animax18AnimaXPlayerGlobal8RegisterERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEENS2_8weak_ptrINS0_12AnimaXPlayerEEE
// EN: AArch64 prologue [sub sp, sp, #0x80; str x28, [sp, #0x20]; stp x27, x26, [sp, #0x30]; stp x25, x24, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x28, [sp, #0x20]; stp x27, x26, [sp, #0x30]; stp x25, x24, [sp, #0x40]]
uint64_t fde_sub_0869ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013FCULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x02C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0869ACULL;
}

// FDE #2217 | PC: 0x086c6c..0x086ca8 (60 B) | Symbol: sub_086c6c
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8dff0; cbz x19, #0x86ca0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8dff0; cbz x19, #0x86ca0]
uint64_t fde_sub_086c6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x086C6CULL;
}

// FDE #2218 | PC: 0x086ca8..0x086db4 (268 B) | Symbol: sub_086ca8
// EN: AArch64 prologue [mov x1, x30; bl #0x8d63c; mov x30, x1; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x1, x30; bl #0x8d63c; mov x30, x1; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_086ca8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94001A64ULL) << 32) | 0xAA1E03E1ULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x086CA8ULL;
}

// FDE #2219 | PC: 0x086db4..0x086dcc (24 B) | Symbol: sub_086db4
// EN: AArch64 prologue [adrp x9, #0xa0000; ldr x8, [x9, #0x6d0]; str x0, [x9, #0x6d0]; cbz x8, #0x86dc8] | VI: Khởi đầu hàm AArch64 [adrp x9, #0xa0000; ldr x8, [x9, #0x6d0]; str x0, [x9, #0x6d0]; cbz x8, #0x86dc8]
uint64_t fde_sub_086db4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9436928ULL) << 32) | 0xD00000C9ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x086DB4ULL;
}

// FDE #2220 | PC: 0x086dcc..0x086f54 (392 B) | Symbol: _ZN4lynx6animax18AnimaXPlayerGlobal10UnregisterERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE
// EN: AArch64 prologue [sub sp, sp, #0x40; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8ee78] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8ee78]
uint64_t fde_sub_086dcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F4ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0188ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x086DCCULL;
}

// FDE #2221 | PC: 0x086f54..0x0871c4 (624 B) | Symbol: sub_086f54
// EN: AArch64 prologue [sub sp, sp, #0xf0; str x28, [sp, #0x90]; stp x27, x26, [sp, #0xa0]; stp x25, x24, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xf0; str x28, [sp, #0x90]; stp x27, x26, [sp, #0xa0]; stp x25, x24, [sp, #0xb0]]
uint64_t fde_sub_086f54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9004BFCULL) << 32) | 0xD103C3FFULL;
    const uint64_t kPcRange = 0x0270ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x086F54ULL;
}

// FDE #2222 | PC: 0x0871c4..0x0872f4 (304 B) | Symbol: sub_0871c4
// EN: AArch64 prologue [sub sp, sp, #0xf0; str x22, [sp, #0xc0]; stp x21, x20, [sp, #0xd0]; stp x19, x30, [sp, #0xe0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xf0; str x22, [sp, #0xc0]; stp x21, x20, [sp, #0xd0]; stp x19, x30, [sp, #0xe0]]
uint64_t fde_sub_0871c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90063F6ULL) << 32) | 0xD103C3FFULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0871C4ULL;
}

// FDE #2223 | PC: 0x0872f4..0x08763c (840 B) | Symbol: sub_0872f4
// EN: AArch64 prologue [sub sp, sp, #0xe0; str x28, [sp, #0x80]; stp x27, x26, [sp, #0x90]; stp x25, x24, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xe0; str x28, [sp, #0x80]; stp x27, x26, [sp, #0x90]; stp x25, x24, [sp, #0xa0]]
uint64_t fde_sub_0872f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90043FCULL) << 32) | 0xD10383FFULL;
    const uint64_t kPcRange = 0x0348ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0872F4ULL;
}

// FDE #2224 | PC: 0x08763c..0x087778 (316 B) | Symbol: sub_08763c
// EN: AArch64 prologue [sub sp, sp, #0xf0; str x22, [sp, #0xc0]; stp x21, x20, [sp, #0xd0]; stp x19, x30, [sp, #0xe0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xf0; str x22, [sp, #0xc0]; stp x21, x20, [sp, #0xd0]; stp x19, x30, [sp, #0xe0]]
uint64_t fde_sub_08763c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90063F6ULL) << 32) | 0xD103C3FFULL;
    const uint64_t kPcRange = 0x013CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08763CULL;
}

// FDE #2225 | PC: 0x087778..0x0877b8 (64 B) | Symbol: sub_087778
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x21, [x0]; cbz x21, #0x877b0] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x21, [x0]; cbz x21, #0x877b0]
uint64_t fde_sub_087778(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087778ULL;
}

// FDE #2226 | PC: 0x0877b8..0x0877e8 (48 B) | Symbol: sub_0877b8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x40; bl #0x91050] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x40; bl #0x91050]
uint64_t fde_sub_0877b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0877B8ULL;
}

// FDE #2227 | PC: 0x0877e8..0x08782c (68 B) | Symbol: sub_0877e8
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x20, [x0, #0x20]; adrp x8, #0x9d000] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x20, [x0, #0x20]; adrp x8, #0x9d000]
uint64_t fde_sub_0877e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0877E8ULL;
}

// FDE #2228 | PC: 0x08782c..0x087844 (24 B) | Symbol: sub_08782c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x877e8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x877e8; mov x0, x19]
uint64_t fde_sub_08782c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08782CULL;
}

// FDE #2229 | PC: 0x087844..0x08788c (72 B) | Symbol: sub_087844
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x19, x30, [sp, #0x20]; bl #0x915a8; ldr x8, [x1, #0x10]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x19, x30, [sp, #0x20]; bl #0x915a8; ldr x8, [x1, #0x10]]
uint64_t fde_sub_087844(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9027BF3ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087844ULL;
}

// FDE #2230 | PC: 0x08788c..0x0878d0 (68 B) | Symbol: sub_08788c
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x21, [x0]; cbz x21, #0x878c8] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x21, [x0]; cbz x21, #0x878c8]
uint64_t fde_sub_08788c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08788CULL;
}

// FDE #2231 | PC: 0x0878d0..0x0878e8 (24 B) | Symbol: sub_0878d0
// EN: AArch64 prologue [lsr x8, x0, #0x3b; cbnz x8, #0x878e0; lsl x0, x0, #5; b #0x93320] | VI: Khởi đầu hàm AArch64 [lsr x8, x0, #0x3b; cbnz x8, #0x878e0; lsl x0, x0, #5; b #0x93320]
uint64_t fde_sub_0878d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB5000068ULL) << 32) | 0xD37BFC08ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0878D0ULL;
}

// FDE #2232 | PC: 0x0878e8..0x087938 (80 B) | Symbol: _ZN4lynx6animax16AnimaXValueParamC2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEi
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9d000; add x8, x8, #0x170] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9d000; add x8, x8, #0x170]
uint64_t fde_sub_0878e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0878E8ULL;
}

// FDE #2233 | PC: 0x087938..0x087970 (56 B) | Symbol: _ZN4lynx6animax16AnimaXValueParamC2Edi
// EN: AArch64 prologue [adrp x8, #0x9d000; add x8, x8, #0x170; str x8, [x0]; mov w8, #1] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9d000; add x8, x8, #0x170; str x8, [x0]; mov w8, #1]
uint64_t fde_sub_087938(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9105C108ULL) << 32) | 0xD00000A8ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087938ULL;
}

// FDE #2234 | PC: 0x087970..0x0879bc (76 B) | Symbol: _ZN4lynx6animax16AnimaXValueParamC2Ebi
// EN: AArch64 prologue [adrp x8, #0x9d000; add x8, x8, #0x170; tst w1, #1; mov w9, #2] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9d000; add x8, x8, #0x170; tst w1, #1; mov w9, #2]
uint64_t fde_sub_087970(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9105C108ULL) << 32) | 0xD00000A8ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087970ULL;
}

// FDE #2235 | PC: 0x0879bc..0x087a28 (108 B) | Symbol: _ZN4lynx6animax16AnimaXValueParamC1Eddi
// EN: AArch64 prologue [adrp x8, #0x9d000; add x8, x8, #0x170; mov w9, #3; fcvt s0, d0] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9d000; add x8, x8, #0x170; mov w9, #3; fcvt s0, d0]
uint64_t fde_sub_0879bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9105C108ULL) << 32) | 0xD00000A8ULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0879BCULL;
}

// FDE #2236 | PC: 0x087a28..0x087a98 (112 B) | Symbol: _ZN4lynx6animax16AnimaXValueParamC2Edddi
// EN: AArch64 prologue [adrp x8, #0x9d000; add x8, x8, #0x170; mov w9, #3; fcvt s0, d0] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9d000; add x8, x8, #0x170; mov w9, #3; fcvt s0, d0]
uint64_t fde_sub_087a28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9105C108ULL) << 32) | 0xD00000A8ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087A28ULL;
}

// FDE #2237 | PC: 0x087a98..0x087af4 (92 B) | Symbol: _ZN4lynx6animax16AnimaXValueParamC2Eii
// EN: AArch64 prologue [adrp x8, #0x9d000; add x8, x8, #0x170; mov w9, #4; str x8, [x0]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9d000; add x8, x8, #0x170; mov w9, #4; str x8, [x0]]
uint64_t fde_sub_087a98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9105C108ULL) << 32) | 0xD00000A8ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087A98ULL;
}

// FDE #2238 | PC: 0x087af4..0x087b5c (104 B) | Symbol: _ZN4lynx6animax16AnimaXValueParamC1ERKNS1_16ColorFilterParamEi
// EN: AArch64 prologue [adrp x8, #0x9d000; add x8, x8, #0x170; mov w9, #5; strb wzr, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9d000; add x8, x8, #0x170; mov w9, #5; strb wzr, [x0, #0x10]]
uint64_t fde_sub_087af4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9105C108ULL) << 32) | 0xD00000A8ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087AF4ULL;
}

// FDE #2239 | PC: 0x087b5c..0x087b9c (64 B) | Symbol: _ZN4lynx6animax16AnimaXValueParamC2Ev
// EN: AArch64 prologue [adrp x8, #0x9d000; add x8, x8, #0x170; mov w9, #6; mov w10, #-1] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9d000; add x8, x8, #0x170; mov w9, #6; mov w10, #-1]
uint64_t fde_sub_087b5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9105C108ULL) << 32) | 0xD00000A8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087B5CULL;
}

// FDE #2240 | PC: 0x087b9c..0x087cbc (288 B) | Symbol: _ZN4lynx6animax16AnimaXValueParamaSEOS1_
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; cmp x0, x1] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; cmp x0, x1]
uint64_t fde_sub_087b9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0120ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087B9CULL;
}

// FDE #2241 | PC: 0x087cbc..0x087d3c (128 B) | Symbol: _ZNK4lynx6animax16AnimaXValueParam14GetStringValueEv
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldrb w8, [x0, #0x28]; cbz w8, #0x87cd4] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldrb w8, [x0, #0x28]; cbz w8, #0x87cd4]
uint64_t fde_sub_087cbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087CBCULL;
}

// FDE #2242 | PC: 0x087d3c..0x087d60 (36 B) | Symbol: _ZNK4lynx6animax16AnimaXValueParam14GetNumberValueEv
// EN: AArch64 prologue [sub sp, sp, #0x10; str xzr, [sp, #8]; ldrb w8, [x0, #0x38]; add x9, x0, #0x30] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x10; str xzr, [sp, #8]; ldrb w8, [x0, #0x38]; add x9, x0, #0x30]
uint64_t fde_sub_087d3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90007FFULL) << 32) | 0xD10043FFULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087D3CULL;
}

// FDE #2243 | PC: 0x087d60..0x087d94 (52 B) | Symbol: _ZNK4lynx6animax16AnimaXValueParam15GetBooleanValueEv
// EN: AArch64 prologue [sub sp, sp, #0x10; str xzr, [sp, #8]; ldrb w8, [x0, #0x38]; add x9, x0, #0x30] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x10; str xzr, [sp, #8]; ldrb w8, [x0, #0x38]; add x9, x0, #0x30]
uint64_t fde_sub_087d60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90007FFULL) << 32) | 0xD10043FFULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087D60ULL;
}

// FDE #2244 | PC: 0x087d94..0x087dac (24 B) | Symbol: _ZNK4lynx6animax16AnimaXValueParam4GetXEv
// EN: AArch64 prologue [ldrb w8, [x0, #0x68]; cbz w8, #0x87da8; ldrb w8, [x0, #0x4c]; mov w9, #0x48] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x68]; cbz w8, #0x87da8; ldrb w8, [x0, #0x4c]; mov w9, #0x48]
uint64_t fde_sub_087d94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34000088ULL) << 32) | 0x3941A008ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087D94ULL;
}

// FDE #2245 | PC: 0x087dac..0x087dc4 (24 B) | Symbol: _ZNK4lynx6animax16AnimaXValueParam4GetYEv
// EN: AArch64 prologue [ldrb w8, [x0, #0x68]; cbz w8, #0x87dc0; ldrb w8, [x0, #0x54]; mov w9, #0x50] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x68]; cbz w8, #0x87dc0; ldrb w8, [x0, #0x54]; mov w9, #0x50]
uint64_t fde_sub_087dac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34000088ULL) << 32) | 0x3941A008ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087DACULL;
}

// FDE #2246 | PC: 0x087dc4..0x087ddc (24 B) | Symbol: _ZNK4lynx6animax16AnimaXValueParam4GetZEv
// EN: AArch64 prologue [ldrb w8, [x0, #0x68]; cbz w8, #0x87dd8; ldrb w8, [x0, #0x5c]; mov w9, #0x58] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x68]; cbz w8, #0x87dd8; ldrb w8, [x0, #0x5c]; mov w9, #0x58]
uint64_t fde_sub_087dc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34000088ULL) << 32) | 0x3941A008ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087DC4ULL;
}

// FDE #2247 | PC: 0x087ddc..0x087e00 (36 B) | Symbol: _ZNK4lynx6animax16AnimaXValueParam13GetColorValueEv
// EN: AArch64 prologue [ldr w8, [x0, #8]; and w8, w8, #0xfffffffe; cmp w8, #4; b.ne #0x87dfc] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #8]; and w8, w8, #0xfffffffe; cmp w8, #4; b.ne #0x87dfc]
uint64_t fde_sub_087ddc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x121F7908ULL) << 32) | 0xB9400808ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087DDCULL;
}

// FDE #2248 | PC: 0x087e00..0x087e68 (104 B) | Symbol: _ZNK4lynx6animax16AnimaXValueParam11GetValuePtrEv
// EN: AArch64 prologue [ldr w8, [x0, #8]; cmp w8, #4; b.hi #0x87e64; adrp x9, #0x1b000] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #8]; cmp w8, #4; b.hi #0x87e64; adrp x9, #0x1b000]
uint64_t fde_sub_087e00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100111FULL) << 32) | 0xB9400808ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087E00ULL;
}

// FDE #2249 | PC: 0x087e68..0x08800c (420 B) | Symbol: _ZN4lynx6animax16AnimaXValueParam9FromValueEPKNS0_5ValueE
// EN: AArch64 prologue [sub sp, sp, #0x40; str d8, [sp, #0x10]; str x22, [sp, #0x18]; stp x21, x20, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str d8, [sp, #0x10]; str x22, [sp, #0x18]; stp x21, x20, [sp, #0x20]]
uint64_t fde_sub_087e68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD000BE8ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x01A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x087E68ULL;
}

// FDE #2250 | PC: 0x08800c..0x088030 (36 B) | Symbol: sub_08800c
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; bl #0x92718] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; bl #0x92718]
uint64_t fde_sub_08800c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08800CULL;
}

// FDE #2251 | PC: 0x088030..0x08807c (76 B) | Symbol: sub_088030
// EN: AArch64 prologue [str d10, [sp, #-0x30]!; stp d9, d8, [sp, #8]; str x20, [sp, #0x18]; stp x19, x30, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [str d10, [sp, #-0x30]!; stp d9, d8, [sp, #8]; str x20, [sp, #0x18]; stp x19, x30, [sp, #0x20]]
uint64_t fde_sub_088030(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D00A3E9ULL) << 32) | 0xFC1D0FEAULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088030ULL;
}

// FDE #2252 | PC: 0x08807c..0x0882cc (592 B) | Symbol: _ZNK4lynx6animax16AnimaXValueParam7ToValueENS0_17LayerPropertyTypeE
// EN: AArch64 prologue [sub sp, sp, #0x60; str d8, [sp, #0x30]; str x22, [sp, #0x38]; stp x21, x20, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str d8, [sp, #0x30]; str x22, [sp, #0x38]; stp x21, x20, [sp, #0x40]]
uint64_t fde_sub_08807c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD001BE8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0250ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08807CULL;
}

// FDE #2253 | PC: 0x0882cc..0x0882d4 (8 B) | Symbol: _ZNK4lynx6animax16AnimaXValueParam7GetTypeEv
// EN: AArch64 prologue [ldr w0, [x0, #8]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #8]; ret]
uint64_t fde_sub_0882cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9400800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0882CCULL;
}

// FDE #2254 | PC: 0x0882d4..0x088310 (60 B) | Symbol: _ZNK4lynx6animax16AnimaXValueParam6CopyToEPNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; cbz x1, #0x882e4; ldr w8, [x0, #8]; cbz w8, #0x882f0] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; cbz x1, #0x882e4; ldr w8, [x0, #8]; cbz w8, #0x882f0]
uint64_t fde_sub_0882d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000061ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0882D4ULL;
}

// FDE #2255 | PC: 0x088310..0x088340 (48 B) | Symbol: _ZNK4lynx6animax16AnimaXValueParam6CopyToEPf
// EN: AArch64 prologue [cbz x1, #0x8833c; ldr w8, [x0, #8]; cmp w8, #1; b.ne #0x8833c] | VI: Khởi đầu hàm AArch64 [cbz x1, #0x8833c; ldr w8, [x0, #8]; cmp w8, #1; b.ne #0x8833c]
uint64_t fde_sub_088310(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9400808ULL) << 32) | 0xB4000161ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088310ULL;
}

// FDE #2256 | PC: 0x088340..0x088370 (48 B) | Symbol: _ZNK4lynx6animax16AnimaXValueParam6CopyToEPi
// EN: AArch64 prologue [cbz x1, #0x8836c; ldr w8, [x0, #8]; cmp w8, #1; b.ne #0x8836c] | VI: Khởi đầu hàm AArch64 [cbz x1, #0x8836c; ldr w8, [x0, #8]; cmp w8, #1; b.ne #0x8836c]
uint64_t fde_sub_088340(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9400808ULL) << 32) | 0xB4000161ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088340ULL;
}

// FDE #2257 | PC: 0x088370..0x08839c (44 B) | Symbol: _ZNK4lynx6animax16AnimaXValueParam6CopyToEPd
// EN: AArch64 prologue [cbz x1, #0x88398; ldr w8, [x0, #8]; cmp w8, #1; b.ne #0x88398] | VI: Khởi đầu hàm AArch64 [cbz x1, #0x88398; ldr w8, [x0, #8]; cmp w8, #1; b.ne #0x88398]
uint64_t fde_sub_088370(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9400808ULL) << 32) | 0xB4000141ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088370ULL;
}

// FDE #2258 | PC: 0x08839c..0x0883d4 (56 B) | Symbol: _ZNK4lynx6animax16AnimaXValueParam6CopyToEPb
// EN: AArch64 prologue [cbz x1, #0x883d0; ldr w8, [x0, #8]; cmp w8, #2; b.ne #0x883d0] | VI: Khởi đầu hàm AArch64 [cbz x1, #0x883d0; ldr w8, [x0, #8]; cmp w8, #2; b.ne #0x883d0]
uint64_t fde_sub_08839c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9400808ULL) << 32) | 0xB40001A1ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08839CULL;
}

// FDE #2259 | PC: 0x0883d4..0x0885a4 (464 B) | Symbol: sub_0883d4
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x27, x26, [sp, #0x40]; stp x25, x24, [sp, #0x50]; stp x23, x22, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x27, x26, [sp, #0x40]; stp x25, x24, [sp, #0x50]; stp x23, x22, [sp, #0x60]]
uint64_t fde_sub_0883d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9046BFBULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x01D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0883D4ULL;
}

// FDE #2260 | PC: 0x0885a4..0x088714 (368 B) | Symbol: sub_0885a4
// EN: AArch64 prologue [sub sp, sp, #0x70; str x26, [sp, #0x20]; stp x25, x24, [sp, #0x30]; stp x23, x22, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x26, [sp, #0x20]; stp x25, x24, [sp, #0x30]; stp x23, x22, [sp, #0x40]]
uint64_t fde_sub_0885a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013FAULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0885A4ULL;
}

// FDE #2261 | PC: 0x088714..0x088748 (52 B) | Symbol: sub_088714
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e108; cmp x20, x21] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e108; cmp x20, x21]
uint64_t fde_sub_088714(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088714ULL;
}

// FDE #2262 | PC: 0x088748..0x088780 (56 B) | Symbol: sub_088748
// EN: AArch64 prologue [ldr x9, [x1]; adrp x10, #0x9d000; add x10, x10, #0x580; movi v0.2d, #0000000000000000] | VI: Khởi đầu hàm AArch64 [ldr x9, [x1]; adrp x10, #0x9d000; add x10, x10, #0x580; movi v0.2d, #0000000000000000]
uint64_t fde_sub_088748(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00000AAULL) << 32) | 0xF9400029ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088748ULL;
}

// FDE #2263 | PC: 0x088780..0x0887a4 (36 B) | Symbol: sub_088780
// EN: AArch64 prologue [ldr x8, [x0]; ldr x8, [x8, #8]; cbz x8, #0x887a0; ldr x9, [x8]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x8, [x8, #8]; cbz x8, #0x887a0; ldr x9, [x8]]
uint64_t fde_sub_088780(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400508ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088780ULL;
}

// FDE #2264 | PC: 0x0887a4..0x088820 (124 B) | Symbol: sub_0887a4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; ldr x8, [x0]; ldr w9, [x8, #0x10]; cmp w9, #2] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; ldr x8, [x0]; ldr w9, [x8, #0x10]; cmp w9, #2]
uint64_t fde_sub_0887a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0887A4ULL;
}

// FDE #2265 | PC: 0x088820..0x08887c (92 B) | Symbol: sub_088820
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8e990] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8e990]
uint64_t fde_sub_088820(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90253F5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088820ULL;
}

// FDE #2266 | PC: 0x08887c..0x088888 (12 B) | Symbol: sub_08887c
// EN: AArch64 prologue [ldr x8, [x0]; ldrh w0, [x8, #0x14]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldrh w0, [x8, #0x14]; ret]
uint64_t fde_sub_08887c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x79402900ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08887CULL;
}

// FDE #2267 | PC: 0x088888..0x0888a8 (32 B) | Symbol: sub_088888
// EN: AArch64 prologue [ldr x8, [x0]; mov w10, #0x30; ldr w9, [x8, #0x10]; cmp w9, #0] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; mov w10, #0x30; ldr w9, [x8, #0x10]; cmp w9, #0]
uint64_t fde_sub_088888(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5280060AULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088888ULL;
}

// FDE #2268 | PC: 0x0888a8..0x0888c8 (32 B) | Symbol: _ZN4lynx6animax21PropertyUpdateRequestC1ENS1_4TypeENS_4base15MoveOnlyClosureIvJRKNS0_22PropertyUpdateResponseEEEE
// EN: AArch64 prologue [adrp x8, #0x9d000; add x8, x8, #0x5a0; str x8, [x0]; ldr x8, [x2]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9d000; add x8, x8, #0x5a0; str x8, [x0]; ldr x8, [x2]]
uint64_t fde_sub_0888a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91168108ULL) << 32) | 0xB00000A8ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0888A8ULL;
}

// FDE #2269 | PC: 0x0888c8..0x0888e8 (32 B) | Symbol: sub_0888c8
// EN: AArch64 prologue [mov x8, x0; ldr x0, [x0, #8]; adrp x9, #0x9d000; add x9, x9, #0x5a0] | VI: Khởi đầu hàm AArch64 [mov x8, x0; ldr x0, [x0, #8]; adrp x9, #0x9d000; add x9, x9, #0x5a0]
uint64_t fde_sub_0888c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400400ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0888C8ULL;
}

// FDE #2270 | PC: 0x0888e8..0x088900 (24 B) | Symbol: sub_0888e8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x888c8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x888c8; mov x0, x19]
uint64_t fde_sub_0888e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0888E8ULL;
}

// FDE #2271 | PC: 0x088900..0x088918 (24 B) | Symbol: _ZNK4lynx6animax21PropertyUpdateRequest14InvokeCallbackERKNS0_22PropertyUpdateResponseE
// EN: AArch64 prologue [ldr x0, [x0, #8]; cbz x0, #0x88914; ldr x8, [x0]; ldr x2, [x8, #0x10]] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #8]; cbz x0, #0x88914; ldr x8, [x0]; ldr x2, [x8, #0x10]]
uint64_t fde_sub_088900(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000080ULL) << 32) | 0xF9400400ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088900ULL;
}

// FDE #2272 | PC: 0x088918..0x088920 (8 B) | Symbol: _ZNK4lynx6animax21PropertyUpdateRequest14GetRequestTypeEv
// EN: AArch64 prologue [ldr w0, [x0, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0x10]; ret]
uint64_t fde_sub_088918(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9401000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088918ULL;
}

// FDE #2273 | PC: 0x088920..0x088978 (88 B) | Symbol: _ZN4lynx6animax18LayerStaticRequest4MakeENS0_17LayerPropertyTypeENSt6__ndk110unique_ptrINS0_13AnimaXKeyPathENS3_14default_deleteIS5_EEEENS4_INS0_16AnimaXValueParamENS6_IS9_EEEENS_4base15MoveOnlyClosureIvJRKNS0_22PropertyUpdateResponseEEEE
// EN: AArch64 prologue [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov w22, w0] | VI: Khởi đầu hàm AArch64 [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov w22, w0]
uint64_t fde_sub_088920(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xA9BD5BF7ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088920ULL;
}

// FDE #2274 | PC: 0x088978..0x0889b4 (60 B) | Symbol: sub_088978
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9d000; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9d000; mov x19, x0]
uint64_t fde_sub_088978(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088978ULL;
}

// FDE #2275 | PC: 0x0889b4..0x0889cc (24 B) | Symbol: sub_0889b4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x88978; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x88978; mov x0, x19]
uint64_t fde_sub_0889b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0889B4ULL;
}

// FDE #2276 | PC: 0x0889cc..0x088a04 (56 B) | Symbol: _ZN4lynx6animax18LayerStaticRequestC1ENS0_17LayerPropertyTypeENSt6__ndk110unique_ptrINS0_13AnimaXKeyPathENS3_14default_deleteIS5_EEEENS4_INS0_16AnimaXValueParamENS6_IS9_EEEENS_4base15MoveOnlyClosureIvJRKNS0_22PropertyUpdateResponseEEEE
// EN: AArch64 prologue [ldr x8, [x4]; adrp x9, #0x9d000; add x9, x9, #0x5c0; str xzr, [x4]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x4]; adrp x9, #0x9d000; add x9, x9, #0x5c0; str xzr, [x4]]
uint64_t fde_sub_0889cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00000A9ULL) << 32) | 0xF9400088ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0889CCULL;
}

// FDE #2277 | PC: 0x088a04..0x088a08 (4 B) | Symbol: _ZNK4lynx6animax21ResourceUpdateRequest15GetResourceTypeEv
// EN: AArch64 prologue [b #0x92328] | VI: Khởi đầu hàm AArch64 [b #0x92328]
uint64_t fde_sub_088a04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401000ULL) << 32) | 0x14002649ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088A04ULL;
}

// FDE #2278 | PC: 0x088a08..0x088a10 (8 B) | Symbol: _ZNK4lynx6animax18LayerStaticRequest8GetValueEv
// EN: AArch64 prologue [ldr x0, [x0, #0x20]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x20]; ret]
uint64_t fde_sub_088a08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF9401000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088A08ULL;
}

// FDE #2279 | PC: 0x088a10..0x088a78 (104 B) | Symbol: _ZN4lynx6animax20LayerCallbackRequest4MakeENS0_17LayerPropertyTypeENSt6__ndk110unique_ptrINS0_13AnimaXKeyPathENS3_14default_deleteIS5_EEEENS3_10shared_ptrINS0_19AnimaXValueCallbackEEENS_4base15MoveOnlyClosureIvJRKNS0_22PropertyUpdateResponseEEEE
// EN: AArch64 prologue [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov w22, w0] | VI: Khởi đầu hàm AArch64 [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov w22, w0]
uint64_t fde_sub_088a10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xA9BD5BF7ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088A10ULL;
}

// FDE #2280 | PC: 0x088a78..0x088aa4 (44 B) | Symbol: sub_088a78
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8e7ac; adrp x8, #0x9d000; add x8, x8, #0x5e0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8e7ac; adrp x8, #0x9d000; add x8, x8, #0x5e0]
uint64_t fde_sub_088a78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400174CULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088A78ULL;
}

// FDE #2281 | PC: 0x088aa4..0x088abc (24 B) | Symbol: sub_088aa4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x88a78; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x88a78; mov x0, x19]
uint64_t fde_sub_088aa4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088AA4ULL;
}

// FDE #2282 | PC: 0x088abc..0x088b00 (68 B) | Symbol: _ZN4lynx6animax20LayerCallbackRequestC1ENS0_17LayerPropertyTypeENSt6__ndk110unique_ptrINS0_13AnimaXKeyPathENS3_14default_deleteIS5_EEEENS3_10shared_ptrINS0_19AnimaXValueCallbackEEENS_4base15MoveOnlyClosureIvJRKNS0_22PropertyUpdateResponseEEEE
// EN: AArch64 prologue [ldr x8, [x4]; adrp x10, #0x9d000; mov w9, #1; add x10, x10, #0x5e0] | VI: Khởi đầu hàm AArch64 [ldr x8, [x4]; adrp x10, #0x9d000; mov w9, #1; add x10, x10, #0x5e0]
uint64_t fde_sub_088abc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00000AAULL) << 32) | 0xF9400088ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088ABCULL;
}

// FDE #2283 | PC: 0x088b00..0x088b2c (44 B) | Symbol: _ZNK4lynx6animax20LayerCallbackRequest16GetValueCallbackEv
// EN: AArch64 prologue [ldr x9, [x0, #0x20]; str x9, [x8]; ldr x9, [x0, #0x28]; str x9, [x8, #8]] | VI: Khởi đầu hàm AArch64 [ldr x9, [x0, #0x20]; str x9, [x8]; ldr x9, [x0, #0x28]; str x9, [x8, #8]]
uint64_t fde_sub_088b00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000109ULL) << 32) | 0xF9401009ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088B00ULL;
}

// FDE #2284 | PC: 0x088b2c..0x088bc0 (148 B) | Symbol: _ZN4lynx6animax21ResourceUpdateRequest4MakeENS0_20ResourcePropertyTypeENSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEENS3_10unique_ptrINS0_16AnimaXValueParamENS3_14default_deleteISB_EEEENS_4base15MoveOnlyClosureIvJRKNS0_22PropertyUpdateResponseEEEE
// EN: AArch64 prologue [sub sp, sp, #0x70; str x24, [sp, #0x30]; stp x23, x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x24, [sp, #0x30]; stp x23, x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]]
uint64_t fde_sub_088b2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF8ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088B2CULL;
}

// FDE #2285 | PC: 0x088bc0..0x088c18 (88 B) | Symbol: _ZN4lynx6animax21ResourceUpdateRequestC2ENS0_20ResourcePropertyTypeENSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEENS3_10unique_ptrINS0_16AnimaXValueParamENS3_14default_deleteISB_EEEENS_4base15MoveOnlyClosureIvJRKNS0_22PropertyUpdateResponseEEEE
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x8, [x4]; adrp x10, #0x9d000] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x8, [x4]; adrp x10, #0x9d000]
uint64_t fde_sub_088bc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088BC0ULL;
}

// FDE #2286 | PC: 0x088c18..0x088c50 (56 B) | Symbol: sub_088c18
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9d000; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9d000; mov x19, x0]
uint64_t fde_sub_088c18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088C18ULL;
}

// FDE #2287 | PC: 0x088c50..0x088c68 (24 B) | Symbol: sub_088c50
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x88c18; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x88c18; mov x0, x19]
uint64_t fde_sub_088c50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088C50ULL;
}

// FDE #2288 | PC: 0x088c68..0x088c70 (8 B) | Symbol: _ZNK4lynx6animax21ResourceUpdateRequest13GetResourceIdEv
// EN: AArch64 prologue [add x0, x0, #0x18; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x18; ret]
uint64_t fde_sub_088c68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x91006000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088C68ULL;
}

// FDE #2289 | PC: 0x088c70..0x088c78 (8 B) | Symbol: _ZNK4lynx6animax21ResourceUpdateRequest8GetValueEv
// EN: AArch64 prologue [ldr x0, [x0, #0x30]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x30]; ret]
uint64_t fde_sub_088c70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF9401800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088C70ULL;
}

// FDE #2290 | PC: 0x088c78..0x088c9c (36 B) | Symbol: _ZN4lynx6animax22PropertyUpdateResponseC1ENS0_20PropertyUpdateResultE
// EN: AArch64 prologue [adrp x8, #0x9d000; add x8, x8, #0x580; movi v0.2d, #0000000000000000; mov w9, #0x3f800000] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9d000; add x8, x8, #0x580; movi v0.2d, #0000000000000000; mov w9, #0x3f800000]
uint64_t fde_sub_088c78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91160108ULL) << 32) | 0xB00000A8ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088C78ULL;
}

// FDE #2291 | PC: 0x088c9c..0x088cb0 (20 B) | Symbol: _ZNK4lynx6animax22PropertyUpdateResponse9IsSuccessEv
// EN: AArch64 prologue [ldrh w8, [x0, #8]; cbz w8, #0x88ca8; b #0x8d6a0; ldr x8, [x0, #0x28]] | VI: Khởi đầu hàm AArch64 [ldrh w8, [x0, #8]; cbz w8, #0x88ca8; b #0x8d6a0; ldr x8, [x0, #0x28]]
uint64_t fde_sub_088c9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34000048ULL) << 32) | 0x79401008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088C9CULL;
}

// FDE #2292 | PC: 0x088cb0..0x088f0c (604 B) | Symbol: _ZN4lynx6animax22PropertyUpdateResponse12AddErrorTypeENSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEENS0_20PropertyUpdateResultE
// EN: AArch64 prologue [str x28, [sp, #-0x60]!; mov x3, x30; bl #0x91e38; mov x30, x3] | VI: Khởi đầu hàm AArch64 [str x28, [sp, #-0x60]!; mov x3, x30; bl #0x91e38; mov x30, x3]
uint64_t fde_sub_088cb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E3ULL) << 32) | 0xF81A0FFCULL;
    const uint64_t kPcRange = 0x025CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088CB0ULL;
}

// FDE #2293 | PC: 0x088f0c..0x08906c (352 B) | Symbol: _ZNK4lynx6animax22PropertyUpdateResponse17GetUpdateMessagesEv
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x23, x22, [sp, #0x80]; stp x21, x20, [sp, #0x90]; stp x19, x30, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x23, x22, [sp, #0x80]; stp x21, x20, [sp, #0x90]; stp x19, x30, [sp, #0xa0]]
uint64_t fde_sub_088f0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9085BF7ULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x0160ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088F0CULL;
}

// FDE #2294 | PC: 0x08906c..0x08907c (16 B) | Symbol: sub_08906c
// EN: AArch64 prologue [sxth w9, w1; mov x8, x0; mov w0, w9; b #0x93740] | VI: Khởi đầu hàm AArch64 [sxth w9, w1; mov x8, x0; mov w0, w9; b #0x93740]
uint64_t fde_sub_08906c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003E8ULL) << 32) | 0x13003C29ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08906CULL;
}

// FDE #2295 | PC: 0x08907c..0x089084 (8 B) | Symbol: _ZN4lynx6animax22PropertyUpdateResponse12SetErrorTypeENS0_20PropertyUpdateResultE
// EN: AArch64 prologue [strh w1, [x0, #8]; ret] | VI: Khởi đầu hàm AArch64 [strh w1, [x0, #8]; ret]
uint64_t fde_sub_08907c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x79001001ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08907CULL;
}

// FDE #2296 | PC: 0x089084..0x0890ac (40 B) | Symbol: _ZNK4lynx6animax22PropertyUpdateResponse12GetErrorTypeEv
// EN: AArch64 prologue [mov x8, x0; ldrh w0, [x0, #8]; cbz w0, #0x89094; ret] | VI: Khởi đầu hàm AArch64 [mov x8, x0; ldrh w0, [x0, #8]; cbz w0, #0x89094; ret]
uint64_t fde_sub_089084(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x79401000ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x089084ULL;
}

// FDE #2297 | PC: 0x0890ac..0x0892d8 (556 B) | Symbol: sub_0890ac
// EN: AArch64 prologue [stp x25, x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x25, x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_0890ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xA9BC63F9ULL;
    const uint64_t kPcRange = 0x022CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0890ACULL;
}

// FDE #2298 | PC: 0x0892d8..0x0892f8 (32 B) | Symbol: sub_0892d8
// EN: AArch64 prologue [mov x8, x0; ldr x0, [x0, #8]; adrp x9, #0x9d000; add x9, x9, #0x6e8] | VI: Khởi đầu hàm AArch64 [mov x8, x0; ldr x0, [x0, #8]; adrp x9, #0x9d000; add x9, x9, #0x6e8]
uint64_t fde_sub_0892d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400400ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0892D8ULL;
}

// FDE #2299 | PC: 0x0892f8..0x089310 (24 B) | Symbol: sub_0892f8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x892d8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x892d8; mov x0, x19]
uint64_t fde_sub_0892f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0892F8ULL;
}

// FDE #2300 | PC: 0x089310..0x089348 (56 B) | Symbol: sub_089310
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x903e8; tbz w3, #0, #0x89328; ldr x1, [x19, #0x10]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x903e8; tbz w3, #0, #0x89328; ldr x1, [x19, #0x10]]
uint64_t fde_sub_089310(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94001C35ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x089310ULL;
}

// FDE #2301 | PC: 0x089348..0x089394 (76 B) | Symbol: sub_089348
// EN: AArch64 prologue [sub sp, sp, #0x40; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x91dd0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x91dd0]
uint64_t fde_sub_089348(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F4ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x089348ULL;
}

// FDE #2302 | PC: 0x089394..0x0893b4 (32 B) | Symbol: sub_089394
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x0, x2; mov x19, x1; bl #0x64e30] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x0, x2; mov x19, x1; bl #0x64e30]
uint64_t fde_sub_089394(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0203E0ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x089394ULL;
}

// FDE #2303 | PC: 0x0893b4..0x0893b8 (4 B) | Symbol: sub_0893b4
// EN: AArch64 prologue [b #0x8d93c] | VI: Khởi đầu hàm AArch64 [b #0x8d93c]
uint64_t fde_sub_0893b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD400040ULL) << 32) | 0x14001162ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0893B4ULL;
}

// FDE #2304 | PC: 0x0893b8..0x0893d0 (24 B) | Symbol: sub_0893b8
// EN: AArch64 prologue [ldr d0, [x2]; mov w8, #1; strb w8, [x1, #0xc]; fcvt s0, d0] | VI: Khởi đầu hàm AArch64 [ldr d0, [x2]; mov w8, #1; strb w8, [x1, #0xc]; fcvt s0, d0]
uint64_t fde_sub_0893b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800028ULL) << 32) | 0xFD400040ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0893B8ULL;
}

// FDE #2305 | PC: 0x0893d0..0x0893e8 (24 B) | Symbol: sub_0893d0
// EN: AArch64 prologue [ldr d0, [x2]; mov w8, #1; strb w8, [x1, #0xc]; fcvtzs w9, d0] | VI: Khởi đầu hàm AArch64 [ldr d0, [x2]; mov w8, #1; strb w8, [x1, #0xc]; fcvtzs w9, d0]
uint64_t fde_sub_0893d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800028ULL) << 32) | 0xFD400040ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0893D0ULL;
}

// FDE #2306 | PC: 0x0893e8..0x08954c (356 B) | Symbol: sub_0893e8
// EN: AArch64 prologue [sub sp, sp, #0x130; str x28, [sp, #0x100]; stp x21, x20, [sp, #0x110]; stp x19, x30, [sp, #0x120]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x130; str x28, [sp, #0x100]; stp x21, x20, [sp, #0x110]; stp x19, x30, [sp, #0x120]]
uint64_t fde_sub_0893e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90083FCULL) << 32) | 0xD104C3FFULL;
    const uint64_t kPcRange = 0x0164ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0893E8ULL;
}

// FDE #2307 | PC: 0x08954c..0x089598 (76 B) | Symbol: sub_08954c
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e128; bl #0x47f90] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e128; bl #0x47f90]
uint64_t fde_sub_08954c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08954CULL;
}

// FDE #2308 | PC: 0x089598..0x0896f4 (348 B) | Symbol: sub_089598
// EN: AArch64 prologue [sub sp, sp, #0xd0; stp x21, x20, [sp, #0xb0]; stp x19, x30, [sp, #0xc0]; bl #0x91478] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xd0; stp x21, x20, [sp, #0xb0]; stp x19, x30, [sp, #0xc0]; bl #0x91478]
uint64_t fde_sub_089598(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90B53F5ULL) << 32) | 0xD10343FFULL;
    const uint64_t kPcRange = 0x015CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x089598ULL;
}

// FDE #2309 | PC: 0x0896f4..0x089738 (68 B) | Symbol: sub_0896f4
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x1] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x1]
uint64_t fde_sub_0896f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0896F4ULL;
}

// FDE #2310 | PC: 0x089738..0x089844 (268 B) | Symbol: sub_089738
// EN: AArch64 prologue [sub sp, sp, #0x110; stp x28, x22, [sp, #0xe0]; stp x21, x20, [sp, #0xf0]; stp x19, x30, [sp, #0x100]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; stp x28, x22, [sp, #0xe0]; stp x21, x20, [sp, #0xf0]; stp x19, x30, [sp, #0x100]]
uint64_t fde_sub_089738(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90E5BFCULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x089738ULL;
}

// FDE #2311 | PC: 0x089844..0x089884 (64 B) | Symbol: sub_089844
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x1; ldp q0, q1, [x1], #0x20] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x1; ldp q0, q1, [x1], #0x20]
uint64_t fde_sub_089844(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x089844ULL;
}

// FDE #2312 | PC: 0x089884..0x08990c (136 B) | Symbol: sub_089884
// EN: AArch64 prologue [stp d9, d8, [sp, #-0x40]!; str x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp d9, d8, [sp, #-0x40]!; str x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_089884(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF6ULL) << 32) | 0x6DBC23E9ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x089884ULL;
}

// FDE #2313 | PC: 0x08990c..0x089934 (40 B) | Symbol: sub_08990c
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x19, x30, [sp, #0x20]; bl #0x8f76c; bl #0x94520] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x19, x30, [sp, #0x20]; bl #0x8f76c; bl #0x94520]
uint64_t fde_sub_08990c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9027BF3ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08990CULL;
}

// FDE #2314 | PC: 0x089934..0x08995c (40 B) | Symbol: sub_089934
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x19, x30, [sp, #0x20]; bl #0x8f76c; bl #0x94530] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x19, x30, [sp, #0x20]; bl #0x8f76c; bl #0x94530]
uint64_t fde_sub_089934(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9027BF3ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x089934ULL;
}

// FDE #2315 | PC: 0x08995c..0x089960 (4 B) | Symbol: sub_08995c
// EN: AArch64 prologue [b #0x94510] | VI: Khởi đầu hàm AArch64 [b #0x94510]
uint64_t fde_sub_08995c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000081ULL) << 32) | 0x14002AEDULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08995CULL;
}

// FDE #2316 | PC: 0x089960..0x089974 (20 B) | Symbol: sub_089960
// EN: AArch64 prologue [cbz x1, #0x89970; ldr x0, [x0]; ldr x1, [x1]; b #0x94540] | VI: Khởi đầu hàm AArch64 [cbz x1, #0x89970; ldr x0, [x0]; ldr x1, [x1]; b #0x94540]
uint64_t fde_sub_089960(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400000ULL) << 32) | 0xB4000081ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x089960ULL;
}

// FDE #2317 | PC: 0x089974..0x0899d8 (100 B) | Symbol: sub_089974
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]; bl #0x8e168] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]; bl #0x8e168]
uint64_t fde_sub_089974(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90553F5ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x089974ULL;
}

// FDE #2318 | PC: 0x0899d8..0x089a04 (44 B) | Symbol: sub_0899d8
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; mov w0, #8] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; mov w0, #8]
uint64_t fde_sub_0899d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0899D8ULL;
}

// FDE #2319 | PC: 0x089a04..0x089a50 (76 B) | Symbol: sub_089a04
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; str x1, [x0]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; str x1, [x0]]
uint64_t fde_sub_089a04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x089A04ULL;
}

// FDE #2320 | PC: 0x089a50..0x089abc (108 B) | Symbol: sub_089a50
// EN: AArch64 prologue [sub sp, sp, #0x50; str x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_089a50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x089A50ULL;
}

// FDE #2321 | PC: 0x089abc..0x089ba8 (236 B) | Symbol: sub_089abc
// EN: AArch64 prologue [sub sp, sp, #0x110; stp x28, x24, [sp, #0xd0]; stp x23, x22, [sp, #0xe0]; stp x21, x20, [sp, #0xf0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; stp x28, x24, [sp, #0xd0]; stp x23, x22, [sp, #0xe0]; stp x21, x20, [sp, #0xf0]]
uint64_t fde_sub_089abc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90D63FCULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x089ABCULL;
}

// FDE #2322 | PC: 0x089ba8..0x089cb4 (268 B) | Symbol: sub_089ba8
// EN: AArch64 prologue [ldp q0, q1, [x1, #0x20]; ldp q2, q3, [x1]; stp q0, q1, [x0, #0x20]; stp q2, q3, [x0]] | VI: Khởi đầu hàm AArch64 [ldp q0, q1, [x1, #0x20]; ldp q2, q3, [x1]; stp q0, q1, [x0, #0x20]; stp q2, q3, [x0]]
uint64_t fde_sub_089ba8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAD400C22ULL) << 32) | 0xAD410420ULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x089BA8ULL;
}

// FDE #2323 | PC: 0x089cb4..0x089d24 (112 B) | Symbol: sub_089cb4
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_089cb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9025BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x089CB4ULL;
}

// FDE #2324 | PC: 0x089d24..0x089dfc (216 B) | Symbol: sub_089d24
// EN: AArch64 prologue [sub sp, sp, #0x110; str x28, [sp, #0xd0]; stp x23, x22, [sp, #0xe0]; stp x21, x20, [sp, #0xf0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; str x28, [sp, #0xd0]; stp x23, x22, [sp, #0xe0]; stp x21, x20, [sp, #0xf0]]
uint64_t fde_sub_089d24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9006BFCULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x089D24ULL;
}

// FDE #2325 | PC: 0x089dfc..0x089f20 (292 B) | Symbol: sub_089dfc
// EN: AArch64 prologue [sub sp, sp, #0x140; str d10, [sp, #0xe0]; stp d9, d8, [sp, #0xf0]; stp x28, x24, [sp, #0x100]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x140; str d10, [sp, #0xe0]; stp d9, d8, [sp, #0xf0]; stp x28, x24, [sp, #0x100]]
uint64_t fde_sub_089dfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0073EAULL) << 32) | 0xD10503FFULL;
    const uint64_t kPcRange = 0x0124ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x089DFCULL;
}

// FDE #2326 | PC: 0x089f20..0x089f24 (4 B) | Symbol: sub_089f20
// EN: AArch64 prologue [b #0x945a0] | VI: Khởi đầu hàm AArch64 [b #0x945a0]
uint64_t fde_sub_089f20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140029C3ULL) << 32) | 0x140029A0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x089F20ULL;
}

// FDE #2327 | PC: 0x089f24..0x089f28 (4 B) | Symbol: sub_089f24
// EN: AArch64 prologue [b #0x94630] | VI: Khởi đầu hàm AArch64 [b #0x94630]
uint64_t fde_sub_089f24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140029AAULL) << 32) | 0x140029C3ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x089F24ULL;
}

// FDE #2328 | PC: 0x089f28..0x089f2c (4 B) | Symbol: sub_089f28
// EN: AArch64 prologue [b #0x945d0] | VI: Khởi đầu hàm AArch64 [b #0x945d0]
uint64_t fde_sub_089f28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140029A1ULL) << 32) | 0x140029AAULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x089F28ULL;
}

// FDE #2329 | PC: 0x089f2c..0x089f30 (4 B) | Symbol: sub_089f2c
// EN: AArch64 prologue [b #0x945b0] | VI: Khởi đầu hàm AArch64 [b #0x945b0]
uint64_t fde_sub_089f2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0x140029A1ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x089F2CULL;
}

// FDE #2330 | PC: 0x089f30..0x089f90 (96 B) | Symbol: sub_089f30
// EN: AArch64 prologue [sub sp, sp, #0x80; str x22, [sp, #0x50]; stp x21, x20, [sp, #0x60]; stp x19, x30, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x22, [sp, #0x50]; stp x21, x20, [sp, #0x60]; stp x19, x30, [sp, #0x70]]
uint64_t fde_sub_089f30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9002BF6ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x089F30ULL;
}

// FDE #2331 | PC: 0x089f90..0x089ff0 (96 B) | Symbol: sub_089f90
// EN: AArch64 prologue [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]]
uint64_t fde_sub_089f90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9009BFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x089F90ULL;
}

// FDE #2332 | PC: 0x089ff0..0x08a068 (120 B) | Symbol: sub_089ff0
// EN: AArch64 prologue [sub sp, sp, #0x50; str x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_089ff0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x089FF0ULL;
}

// FDE #2333 | PC: 0x08a068..0x08a138 (208 B) | Symbol: sub_08a068
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]; bl #0x8e990] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]; bl #0x8e990]
uint64_t fde_sub_08a068(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90453F5ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08A068ULL;
}

// FDE #2334 | PC: 0x08a138..0x08a730 (1528 B) | Symbol: sub_08a138
// EN: AArch64 prologue [mov x1, x30; bl #0x91c18; mov x30, x1; stp x29, x30, [sp, #0x1b0]] | VI: Khởi đầu hàm AArch64 [mov x1, x30; bl #0x91c18; mov x30, x1; stp x29, x30, [sp, #0x1b0]]
uint64_t fde_sub_08a138(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94001EB7ULL) << 32) | 0xAA1E03E1ULL;
    const uint64_t kPcRange = 0x05F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08A138ULL;
}

// FDE #2335 | PC: 0x08a730..0x08a79c (108 B) | Symbol: sub_08a730
// EN: AArch64 prologue [sub sp, sp, #0x50; str x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_08a730(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08A730ULL;
}

// FDE #2336 | PC: 0x08a79c..0x08a808 (108 B) | Symbol: sub_08a79c
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x0]
uint64_t fde_sub_08a79c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08A79CULL;
}

// FDE #2337 | PC: 0x08a808..0x08a830 (40 B) | Symbol: sub_08a808
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8dff0; cbz x19, #0x8a828; ldr x0, [x19, #8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8dff0; cbz x19, #0x8a828; ldr x0, [x19, #8]]
uint64_t fde_sub_08a808(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94000DF9ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08A808ULL;
}

// FDE #2338 | PC: 0x08a830..0x08a850 (32 B) | Symbol: sub_08a830
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; add x8, x8, #0x778; bl #0x8daa4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; add x8, x8, #0x778; bl #0x8daa4]
uint64_t fde_sub_08a830(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000088ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08A830ULL;
}

// FDE #2339 | PC: 0x08a850..0x08a868 (24 B) | Symbol: sub_08a850
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x8a830; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x8a830; mov x0, x19]
uint64_t fde_sub_08a850(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08A850ULL;
}

// FDE #2340 | PC: 0x08a868..0x08a870 (8 B) | Symbol: sub_08a868
// EN: AArch64 prologue [add x0, x0, #0x18; b #0x8a870] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x18; b #0x8a870]
uint64_t fde_sub_08a868(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0x91006000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08A868ULL;
}

// FDE #2341 | PC: 0x08a870..0x08a894 (36 B) | Symbol: sub_08a870
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #8]; str xzr, [x19, #8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #8]; str xzr, [x19, #8]]
uint64_t fde_sub_08a870(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08A870ULL;
}

// FDE #2342 | PC: 0x08a894..0x08ac3c (936 B) | Symbol: sub_08a894
// EN: AArch64 prologue [mov x0, x30; bl #0x8d63c; mov x30, x0; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x0, x30; bl #0x8d63c; mov x30, x0; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_08a894(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94000B69ULL) << 32) | 0xAA1E03E0ULL;
    const uint64_t kPcRange = 0x03A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08A894ULL;
}

// FDE #2343 | PC: 0x08ac3c..0x08af84 (840 B) | Symbol: sub_08ac3c
// EN: AArch64 prologue [sub sp, sp, #0x180; stp x28, x27, [sp, #0x120]; stp x26, x25, [sp, #0x130]; stp x24, x23, [sp, #0x140]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x180; stp x28, x27, [sp, #0x120]; stp x26, x25, [sp, #0x130]; stp x24, x23, [sp, #0x140]]
uint64_t fde_sub_08ac3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9126FFCULL) << 32) | 0xD10603FFULL;
    const uint64_t kPcRange = 0x0348ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08AC3CULL;
}

// FDE #2344 | PC: 0x08af84..0x08b244 (704 B) | Symbol: sub_08af84
// EN: AArch64 prologue [mov x0, x30; bl #0x91b18; mov x30, x0; stp x29, x30, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [mov x0, x30; bl #0x91b18; mov x30, x0; stp x29, x30, [sp, #0xa0]]
uint64_t fde_sub_08af84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94001AE4ULL) << 32) | 0xAA1E03E0ULL;
    const uint64_t kPcRange = 0x02C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08AF84ULL;
}

// FDE #2345 | PC: 0x08b244..0x08b270 (44 B) | Symbol: sub_08b244
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; add x8, x8, #0x7b8; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; add x8, x8, #0x7b8; mov x19, x0]
uint64_t fde_sub_08b244(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000088ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B244ULL;
}

// FDE #2346 | PC: 0x08b270..0x08b278 (8 B) | Symbol: sub_08b270
// EN: AArch64 prologue [add x0, x0, #0x10; b #0x93670] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x10; b #0x93670]
uint64_t fde_sub_08b270(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140020FFULL) << 32) | 0x91004000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B270ULL;
}

// FDE #2347 | PC: 0x08b278..0x08b290 (24 B) | Symbol: sub_08b278
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x93670; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x93670; mov x0, x19]
uint64_t fde_sub_08b278(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94000A28ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B278ULL;
}

// FDE #2348 | PC: 0x08b290..0x08b2a4 (20 B) | Symbol: sub_08b290
// EN: AArch64 prologue [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x8, x0, x8; add x0, x8, #0x10] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x8, x0, x8; add x0, x8, #0x10]
uint64_t fde_sub_08b290(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF85E8108ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B290ULL;
}

// FDE #2349 | PC: 0x08b2a4..0x08b2b4 (16 B) | Symbol: sub_08b2a4
// EN: AArch64 prologue [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x0, x0, x8; b #0x8b278] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x0, x0, x8; b #0x8b278]
uint64_t fde_sub_08b2a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF85E8108ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B2A4ULL;
}

// FDE #2350 | PC: 0x08b2b4..0x08b2cc (24 B) | Symbol: sub_08b2b4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x8b244; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x8b244; mov x0, x19]
uint64_t fde_sub_08b2b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B2B4ULL;
}

// FDE #2351 | PC: 0x08b2cc..0x08b2dc (16 B) | Symbol: sub_08b2cc
// EN: AArch64 prologue [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x0, x0, x8; b #0x8b244] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x0, x0, x8; b #0x8b244]
uint64_t fde_sub_08b2cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF85E8108ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B2CCULL;
}

// FDE #2352 | PC: 0x08b2dc..0x08b2ec (16 B) | Symbol: sub_08b2dc
// EN: AArch64 prologue [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x0, x0, x8; b #0x8b2b4] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x0, x0, x8; b #0x8b2b4]
uint64_t fde_sub_08b2dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF85E8108ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B2DCULL;
}

// FDE #2353 | PC: 0x08b2ec..0x08b3f8 (268 B) | Symbol: sub_08b2ec
// EN: AArch64 prologue [mov x1, x30; bl #0x8d63c; mov x30, x1; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x1, x30; bl #0x8d63c; mov x30, x1; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_08b2ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940008D3ULL) << 32) | 0xAA1E03E1ULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B2ECULL;
}

// FDE #2354 | PC: 0x08b3f8..0x08b410 (24 B) | Symbol: sub_08b3f8
// EN: AArch64 prologue [adrp x9, #0xa0000; ldr x8, [x9, #0x770]; str x0, [x9, #0x770]; cbz x8, #0x8b40c] | VI: Khởi đầu hàm AArch64 [adrp x9, #0xa0000; ldr x8, [x9, #0x770]; str x0, [x9, #0x770]; cbz x8, #0x8b40c]
uint64_t fde_sub_08b3f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF943B928ULL) << 32) | 0xB00000A9ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B3F8ULL;
}

// FDE #2355 | PC: 0x08b410..0x08b51c (268 B) | Symbol: sub_08b410
// EN: AArch64 prologue [mov x1, x30; bl #0x8d63c; mov x30, x1; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x1, x30; bl #0x8d63c; mov x30, x1; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_08b410(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400088AULL) << 32) | 0xAA1E03E1ULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B410ULL;
}

// FDE #2356 | PC: 0x08b51c..0x08b534 (24 B) | Symbol: sub_08b51c
// EN: AArch64 prologue [adrp x9, #0xa0000; ldr x8, [x9, #0x748]; str x0, [x9, #0x748]; cbz x8, #0x8b530] | VI: Khởi đầu hàm AArch64 [adrp x9, #0xa0000; ldr x8, [x9, #0x748]; str x0, [x9, #0x748]; cbz x8, #0x8b530]
uint64_t fde_sub_08b51c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF943A528ULL) << 32) | 0xB00000A9ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B51CULL;
}

// FDE #2357 | PC: 0x08b534..0x08b640 (268 B) | Symbol: sub_08b534
// EN: AArch64 prologue [mov x1, x30; bl #0x8d63c; mov x30, x1; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x1, x30; bl #0x8d63c; mov x30, x1; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_08b534(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94000841ULL) << 32) | 0xAA1E03E1ULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B534ULL;
}

// FDE #2358 | PC: 0x08b640..0x08b658 (24 B) | Symbol: sub_08b640
// EN: AArch64 prologue [adrp x9, #0xa0000; ldr x8, [x9, #0x720]; str x0, [x9, #0x720]; cbz x8, #0x8b654] | VI: Khởi đầu hàm AArch64 [adrp x9, #0xa0000; ldr x8, [x9, #0x720]; str x0, [x9, #0x720]; cbz x8, #0x8b654]
uint64_t fde_sub_08b640(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9439128ULL) << 32) | 0xB00000A9ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B640ULL;
}

// FDE #2359 | PC: 0x08b658..0x08b730 (216 B) | Symbol: sub_08b658
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]; bl #0x8e168] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]; bl #0x8e168]
uint64_t fde_sub_08b658(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90353F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B658ULL;
}

// FDE #2360 | PC: 0x08b730..0x08b734 (4 B) | Symbol: sub_08b730
// EN: AArch64 prologue [b #0x946e0] | VI: Khởi đầu hàm AArch64 [b #0x946e0]
uint64_t fde_sub_08b730(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10443FFULL) << 32) | 0x140023ECULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B730ULL;
}

// FDE #2361 | PC: 0x08b734..0x08b808 (212 B) | Symbol: sub_08b734
// EN: AArch64 prologue [sub sp, sp, #0x110; str d8, [sp, #0xe0]; str x28, [sp, #0xe8]; stp x21, x20, [sp, #0xf0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; str d8, [sp, #0xe0]; str x28, [sp, #0xe8]; stp x21, x20, [sp, #0xf0]]
uint64_t fde_sub_08b734(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0073E8ULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B734ULL;
}

// FDE #2362 | PC: 0x08b808..0x08b820 (24 B) | Symbol: sub_08b808
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x9d000; add x9, x9, #0x850; str x9, [x0]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x9d000; add x9, x9, #0x850; str x9, [x0]]
uint64_t fde_sub_08b808(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000089ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B808ULL;
}

// FDE #2363 | PC: 0x08b820..0x08b838 (24 B) | Symbol: sub_08b820
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x8b808; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x8b808; mov x0, x19]
uint64_t fde_sub_08b820(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B820ULL;
}

// FDE #2364 | PC: 0x08b838..0x08b858 (32 B) | Symbol: sub_08b838
// EN: AArch64 prologue [cbz x0, #0x8b850; str x30, [sp, #-0x10]!; bl #0x8d460; ucvtf s0, x0] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x8b850; str x30, [sp, #-0x10]!; bl #0x8d460; ucvtf s0, x0]
uint64_t fde_sub_08b838(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81F0FFEULL) << 32) | 0xB40000C0ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B838ULL;
}

// FDE #2365 | PC: 0x08b858..0x08b880 (40 B) | Symbol: sub_08b858
// EN: AArch64 prologue [cbz x0, #0x8b878; str x30, [sp, #-0x10]!; ldr x8, [x0]; ldr x8, [x8, #0x38]] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x8b878; str x30, [sp, #-0x10]!; ldr x8, [x0]; ldr x8, [x8, #0x38]]
uint64_t fde_sub_08b858(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81F0FFEULL) << 32) | 0xB4000100ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B858ULL;
}

// FDE #2366 | PC: 0x08b880..0x08b8a8 (40 B) | Symbol: sub_08b880
// EN: AArch64 prologue [cbz x1, #0x8b8a4; stp x19, x30, [sp, #-0x10]!; ldr x8, [x1, #0x10]; mov x19, x1] | VI: Khởi đầu hàm AArch64 [cbz x1, #0x8b8a4; stp x19, x30, [sp, #-0x10]!; ldr x8, [x1, #0x10]; mov x19, x1]
uint64_t fde_sub_08b880(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BF3ULL) << 32) | 0xB4000121ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B880ULL;
}

// FDE #2367 | PC: 0x08b8a8..0x08b8c8 (32 B) | Symbol: sub_08b8a8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; add x8, x8, #0x870; bl #0x8daa4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; add x8, x8, #0x870; bl #0x8daa4]
uint64_t fde_sub_08b8a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000088ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B8A8ULL;
}

// FDE #2368 | PC: 0x08b8c8..0x08b8e0 (24 B) | Symbol: sub_08b8c8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x8b8a8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x8b8a8; mov x0, x19]
uint64_t fde_sub_08b8c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B8C8ULL;
}

// FDE #2369 | PC: 0x08b8e0..0x08b8e8 (8 B) | Symbol: sub_08b8e0
// EN: AArch64 prologue [add x0, x0, #0x18; b #0x94710] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x18; b #0x94710]
uint64_t fde_sub_08b8e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400238BULL) << 32) | 0x91006000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B8E0ULL;
}

// FDE #2370 | PC: 0x08b8e8..0x08b938 (80 B) | Symbol: sub_08b8e8
// EN: AArch64 prologue [sub sp, sp, #0x40; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8eba4] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8eba4]
uint64_t fde_sub_08b8e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F4ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B8E8ULL;
}

// FDE #2371 | PC: 0x08b938..0x08b954 (28 B) | Symbol: sub_08b938
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x55ba4; bl #0x8f4bc] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x55ba4; bl #0x8f4bc]
uint64_t fde_sub_08b938(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B938ULL;
}

// FDE #2372 | PC: 0x08b954..0x08b984 (48 B) | Symbol: sub_08b954
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; mov w0, #0x40] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; mov w0, #0x40]
uint64_t fde_sub_08b954(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B954ULL;
}

// FDE #2373 | PC: 0x08b984..0x08b988 (4 B) | Symbol: sub_08b984
// EN: AArch64 prologue [b #0x94720] | VI: Khởi đầu hàm AArch64 [b #0x94720]
uint64_t fde_sub_08b984(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400236AULL) << 32) | 0x14002367ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B984ULL;
}

// FDE #2374 | PC: 0x08b988..0x08b98c (4 B) | Symbol: sub_08b988
// EN: AArch64 prologue [b #0x94730] | VI: Khởi đầu hàm AArch64 [b #0x94730]
uint64_t fde_sub_08b988(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x1400236AULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B988ULL;
}

// FDE #2375 | PC: 0x08b98c..0x08b9ec (96 B) | Symbol: sub_08b98c
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]; mrs x21, tpidr_el0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]; mrs x21, tpidr_el0]
uint64_t fde_sub_08b98c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90353F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B98CULL;
}

// FDE #2376 | PC: 0x08b9ec..0x08bb58 (364 B) | Symbol: sub_08b9ec
// EN: AArch64 prologue [sub sp, sp, #0xa0; mov x3, x30; bl #0x8feb4; mov x30, x3] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; mov x3, x30; bl #0x8feb4; mov x30, x3]
uint64_t fde_sub_08b9ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E3ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x016CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B9ECULL;
}

// FDE #2377 | PC: 0x08bb58..0x08bb68 (16 B) | Symbol: sub_08bb58
// EN: AArch64 prologue [mov x1, x30; bl #0x8f4bc; mov x30, x1; ret] | VI: Khởi đầu hàm AArch64 [mov x1, x30; bl #0x8f4bc; mov x30, x1; ret]
uint64_t fde_sub_08bb58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94000E58ULL) << 32) | 0xAA1E03E1ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BB58ULL;
}

// FDE #2378 | PC: 0x08bb68..0x08bb6c (4 B) | Symbol: sub_08bb68
// EN: AArch64 prologue [b #0x94760] | VI: Khởi đầu hàm AArch64 [b #0x94760]
uint64_t fde_sub_08bb68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14002301ULL) << 32) | 0x140022FEULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BB68ULL;
}

uint64_t DispatchAnimaXShard3(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x073f28ULL: return fde_sub_073f28(a0, a1, a2);
        case 0x073f3cULL: return fde_sub_073f3c(a0, a1, a2);
        case 0x073f44ULL: return fde_sub_073f44(a0, a1, a2);
        case 0x073f4cULL: return fde_sub_073f4c(a0, a1, a2);
        case 0x073f54ULL: return fde_sub_073f54(a0, a1, a2);
        case 0x073f5cULL: return fde_sub_073f5c(a0, a1, a2);
        case 0x073f78ULL: return fde_sub_073f78(a0, a1, a2);
        case 0x073f90ULL: return fde_sub_073f90(a0, a1, a2);
        case 0x073fd0ULL: return fde_sub_073fd0(a0, a1, a2);
        case 0x074000ULL: return fde_sub_074000(a0, a1, a2);
        case 0x074230ULL: return fde_sub_074230(a0, a1, a2);
        case 0x07426cULL: return fde_sub_07426c(a0, a1, a2);
        case 0x074294ULL: return fde_sub_074294(a0, a1, a2);
        case 0x0746b8ULL: return fde_sub_0746b8(a0, a1, a2);
        case 0x0747c4ULL: return fde_sub_0747c4(a0, a1, a2);
        case 0x0747dcULL: return fde_sub_0747dc(a0, a1, a2);
        case 0x0747f4ULL: return fde_sub_0747f4(a0, a1, a2);
        case 0x074864ULL: return fde_sub_074864(a0, a1, a2);
        case 0x0748a0ULL: return fde_sub_0748a0(a0, a1, a2);
        case 0x0748b8ULL: return fde_sub_0748b8(a0, a1, a2);
        case 0x0748c4ULL: return fde_sub_0748c4(a0, a1, a2);
        case 0x074940ULL: return fde_sub_074940(a0, a1, a2);
        case 0x07494cULL: return fde_sub_07494c(a0, a1, a2);
        case 0x074950ULL: return fde_sub_074950(a0, a1, a2);
        case 0x074968ULL: return fde_sub_074968(a0, a1, a2);
        case 0x07497cULL: return fde_sub_07497c(a0, a1, a2);
        case 0x074990ULL: return fde_sub_074990(a0, a1, a2);
        case 0x0749e4ULL: return fde_sub_0749e4(a0, a1, a2);
        case 0x074a48ULL: return fde_sub_074a48(a0, a1, a2);
        case 0x074a50ULL: return fde_sub_074a50(a0, a1, a2);
        case 0x074a58ULL: return fde_sub_074a58(a0, a1, a2);
        case 0x074a60ULL: return fde_sub_074a60(a0, a1, a2);
        case 0x074a80ULL: return fde_sub_074a80(a0, a1, a2);
        case 0x074a94ULL: return fde_sub_074a94(a0, a1, a2);
        case 0x074ab0ULL: return fde_sub_074ab0(a0, a1, a2);
        case 0x074b04ULL: return fde_sub_074b04(a0, a1, a2);
        case 0x074b1cULL: return fde_sub_074b1c(a0, a1, a2);
        case 0x074b34ULL: return fde_sub_074b34(a0, a1, a2);
        case 0x074b64ULL: return fde_sub_074b64(a0, a1, a2);
        case 0x074bf8ULL: return fde_sub_074bf8(a0, a1, a2);
        case 0x074c30ULL: return fde_sub_074c30(a0, a1, a2);
        case 0x074ca4ULL: return fde_sub_074ca4(a0, a1, a2);
        case 0x074cb8ULL: return fde_sub_074cb8(a0, a1, a2);
        case 0x074cd0ULL: return fde_sub_074cd0(a0, a1, a2);
        case 0x074cecULL: return fde_sub_074cec(a0, a1, a2);
        case 0x074cfcULL: return fde_sub_074cfc(a0, a1, a2);
        case 0x074d14ULL: return fde_sub_074d14(a0, a1, a2);
        case 0x074d24ULL: return fde_sub_074d24(a0, a1, a2);
        case 0x074d44ULL: return fde_sub_074d44(a0, a1, a2);
        case 0x074d5cULL: return fde_sub_074d5c(a0, a1, a2);
        case 0x074dfcULL: return fde_sub_074dfc(a0, a1, a2);
        case 0x074e70ULL: return fde_sub_074e70(a0, a1, a2);
        case 0x074e80ULL: return fde_sub_074e80(a0, a1, a2);
        case 0x074e98ULL: return fde_sub_074e98(a0, a1, a2);
        case 0x074ea8ULL: return fde_sub_074ea8(a0, a1, a2);
        case 0x075038ULL: return fde_sub_075038(a0, a1, a2);
        case 0x075064ULL: return fde_sub_075064(a0, a1, a2);
        case 0x07507cULL: return fde_sub_07507c(a0, a1, a2);
        case 0x075098ULL: return fde_sub_075098(a0, a1, a2);
        case 0x0750b0ULL: return fde_sub_0750b0(a0, a1, a2);
        case 0x075440ULL: return fde_sub_075440(a0, a1, a2);
        case 0x0754acULL: return fde_sub_0754ac(a0, a1, a2);
        case 0x0754f4ULL: return fde_sub_0754f4(a0, a1, a2);
        case 0x075540ULL: return fde_sub_075540(a0, a1, a2);
        case 0x07555cULL: return fde_sub_07555c(a0, a1, a2);
        case 0x075574ULL: return fde_sub_075574(a0, a1, a2);
        case 0x07558cULL: return fde_sub_07558c(a0, a1, a2);
        case 0x07568cULL: return fde_sub_07568c(a0, a1, a2);
        case 0x0756c8ULL: return fde_sub_0756c8(a0, a1, a2);
        case 0x0756e8ULL: return fde_sub_0756e8(a0, a1, a2);
        case 0x075708ULL: return fde_sub_075708(a0, a1, a2);
        case 0x075748ULL: return fde_sub_075748(a0, a1, a2);
        case 0x07579cULL: return fde_sub_07579c(a0, a1, a2);
        case 0x0757a8ULL: return fde_sub_0757a8(a0, a1, a2);
        case 0x0757d4ULL: return fde_sub_0757d4(a0, a1, a2);
        case 0x0757dcULL: return fde_sub_0757dc(a0, a1, a2);
        case 0x075810ULL: return fde_sub_075810(a0, a1, a2);
        case 0x075844ULL: return fde_sub_075844(a0, a1, a2);
        case 0x075864ULL: return fde_sub_075864(a0, a1, a2);
        case 0x075884ULL: return fde_sub_075884(a0, a1, a2);
        case 0x07589cULL: return fde_sub_07589c(a0, a1, a2);
        case 0x075a54ULL: return fde_sub_075a54(a0, a1, a2);
        case 0x075a7cULL: return fde_sub_075a7c(a0, a1, a2);
        case 0x075a8cULL: return fde_sub_075a8c(a0, a1, a2);
        case 0x075aa4ULL: return fde_sub_075aa4(a0, a1, a2);
        case 0x075b88ULL: return fde_sub_075b88(a0, a1, a2);
        case 0x075bf0ULL: return fde_sub_075bf0(a0, a1, a2);
        case 0x075bfcULL: return fde_sub_075bfc(a0, a1, a2);
        case 0x075c24ULL: return fde_sub_075c24(a0, a1, a2);
        case 0x075c3cULL: return fde_sub_075c3c(a0, a1, a2);
        case 0x07620cULL: return fde_sub_07620c(a0, a1, a2);
        case 0x076298ULL: return fde_sub_076298(a0, a1, a2);
        case 0x0762d4ULL: return fde_sub_0762d4(a0, a1, a2);
        case 0x076344ULL: return fde_sub_076344(a0, a1, a2);
        case 0x076374ULL: return fde_sub_076374(a0, a1, a2);
        case 0x0763b4ULL: return fde_sub_0763b4(a0, a1, a2);
        case 0x0763c4ULL: return fde_sub_0763c4(a0, a1, a2);
        case 0x0763d4ULL: return fde_sub_0763d4(a0, a1, a2);
        case 0x0763ecULL: return fde_sub_0763ec(a0, a1, a2);
        case 0x07673cULL: return fde_sub_07673c(a0, a1, a2);
        case 0x07676cULL: return fde_sub_07676c(a0, a1, a2);
        case 0x0767a4ULL: return fde_sub_0767a4(a0, a1, a2);
        case 0x0767bcULL: return fde_sub_0767bc(a0, a1, a2);
        case 0x076808ULL: return fde_sub_076808(a0, a1, a2);
        case 0x076844ULL: return fde_sub_076844(a0, a1, a2);
        case 0x07685cULL: return fde_sub_07685c(a0, a1, a2);
        case 0x076950ULL: return fde_sub_076950(a0, a1, a2);
        case 0x0769d8ULL: return fde_sub_0769d8(a0, a1, a2);
        case 0x076a54ULL: return fde_sub_076a54(a0, a1, a2);
        case 0x076a90ULL: return fde_sub_076a90(a0, a1, a2);
        case 0x076ac0ULL: return fde_sub_076ac0(a0, a1, a2);
        case 0x076ad8ULL: return fde_sub_076ad8(a0, a1, a2);
        case 0x076b14ULL: return fde_sub_076b14(a0, a1, a2);
        case 0x076b54ULL: return fde_sub_076b54(a0, a1, a2);
        case 0x076ba0ULL: return fde_sub_076ba0(a0, a1, a2);
        case 0x076becULL: return fde_sub_076bec(a0, a1, a2);
        case 0x076c28ULL: return fde_sub_076c28(a0, a1, a2);
        case 0x076c40ULL: return fde_sub_076c40(a0, a1, a2);
        case 0x076dccULL: return fde_sub_076dcc(a0, a1, a2);
        case 0x077058ULL: return fde_sub_077058(a0, a1, a2);
        case 0x07717cULL: return fde_sub_07717c(a0, a1, a2);
        case 0x0771b8ULL: return fde_sub_0771b8(a0, a1, a2);
        case 0x0771d4ULL: return fde_sub_0771d4(a0, a1, a2);
        case 0x0772ccULL: return fde_sub_0772cc(a0, a1, a2);
        case 0x077378ULL: return fde_sub_077378(a0, a1, a2);
        case 0x07739cULL: return fde_sub_07739c(a0, a1, a2);
        case 0x0773b4ULL: return fde_sub_0773b4(a0, a1, a2);
        case 0x077484ULL: return fde_sub_077484(a0, a1, a2);
        case 0x0774d0ULL: return fde_sub_0774d0(a0, a1, a2);
        case 0x0774f8ULL: return fde_sub_0774f8(a0, a1, a2);
        case 0x077514ULL: return fde_sub_077514(a0, a1, a2);
        case 0x077524ULL: return fde_sub_077524(a0, a1, a2);
        case 0x07753cULL: return fde_sub_07753c(a0, a1, a2);
        case 0x0775c8ULL: return fde_sub_0775c8(a0, a1, a2);
        case 0x0775e8ULL: return fde_sub_0775e8(a0, a1, a2);
        case 0x077600ULL: return fde_sub_077600(a0, a1, a2);
        case 0x077738ULL: return fde_sub_077738(a0, a1, a2);
        case 0x077768ULL: return fde_sub_077768(a0, a1, a2);
        case 0x077778ULL: return fde_sub_077778(a0, a1, a2);
        case 0x077790ULL: return fde_sub_077790(a0, a1, a2);
        case 0x077804ULL: return fde_sub_077804(a0, a1, a2);
        case 0x077828ULL: return fde_sub_077828(a0, a1, a2);
        case 0x077840ULL: return fde_sub_077840(a0, a1, a2);
        case 0x077910ULL: return fde_sub_077910(a0, a1, a2);
        case 0x077934ULL: return fde_sub_077934(a0, a1, a2);
        case 0x077958ULL: return fde_sub_077958(a0, a1, a2);
        case 0x077970ULL: return fde_sub_077970(a0, a1, a2);
        case 0x077980ULL: return fde_sub_077980(a0, a1, a2);
        case 0x077998ULL: return fde_sub_077998(a0, a1, a2);
        case 0x077a24ULL: return fde_sub_077a24(a0, a1, a2);
        case 0x077a44ULL: return fde_sub_077a44(a0, a1, a2);
        case 0x077a5cULL: return fde_sub_077a5c(a0, a1, a2);
        case 0x077b60ULL: return fde_sub_077b60(a0, a1, a2);
        case 0x077ba4ULL: return fde_sub_077ba4(a0, a1, a2);
        case 0x077bc4ULL: return fde_sub_077bc4(a0, a1, a2);
        case 0x077bf4ULL: return fde_sub_077bf4(a0, a1, a2);
        case 0x077c04ULL: return fde_sub_077c04(a0, a1, a2);
        case 0x077c1cULL: return fde_sub_077c1c(a0, a1, a2);
        case 0x077c78ULL: return fde_sub_077c78(a0, a1, a2);
        case 0x077ce8ULL: return fde_sub_077ce8(a0, a1, a2);
        case 0x077d04ULL: return fde_sub_077d04(a0, a1, a2);
        case 0x077d1cULL: return fde_sub_077d1c(a0, a1, a2);
        case 0x077df0ULL: return fde_sub_077df0(a0, a1, a2);
        case 0x077e18ULL: return fde_sub_077e18(a0, a1, a2);
        case 0x077e28ULL: return fde_sub_077e28(a0, a1, a2);
        case 0x077e40ULL: return fde_sub_077e40(a0, a1, a2);
        case 0x077eccULL: return fde_sub_077ecc(a0, a1, a2);
        case 0x077eecULL: return fde_sub_077eec(a0, a1, a2);
        case 0x077f04ULL: return fde_sub_077f04(a0, a1, a2);
        case 0x077f9cULL: return fde_sub_077f9c(a0, a1, a2);
        case 0x077fc0ULL: return fde_sub_077fc0(a0, a1, a2);
        case 0x077fd0ULL: return fde_sub_077fd0(a0, a1, a2);
        case 0x077fe8ULL: return fde_sub_077fe8(a0, a1, a2);
        case 0x078030ULL: return fde_sub_078030(a0, a1, a2);
        case 0x0780acULL: return fde_sub_0780ac(a0, a1, a2);
        case 0x0780d4ULL: return fde_sub_0780d4(a0, a1, a2);
        case 0x0780e4ULL: return fde_sub_0780e4(a0, a1, a2);
        case 0x0780fcULL: return fde_sub_0780fc(a0, a1, a2);
        case 0x0781c8ULL: return fde_sub_0781c8(a0, a1, a2);
        case 0x0783b0ULL: return fde_sub_0783b0(a0, a1, a2);
        case 0x0783c0ULL: return fde_sub_0783c0(a0, a1, a2);
        case 0x0783d8ULL: return fde_sub_0783d8(a0, a1, a2);
        case 0x078554ULL: return fde_sub_078554(a0, a1, a2);
        case 0x078688ULL: return fde_sub_078688(a0, a1, a2);
        case 0x07868cULL: return fde_sub_07868c(a0, a1, a2);
        case 0x0788acULL: return fde_sub_0788ac(a0, a1, a2);
        case 0x0788c8ULL: return fde_sub_0788c8(a0, a1, a2);
        case 0x0788e0ULL: return fde_sub_0788e0(a0, a1, a2);
        case 0x0788e8ULL: return fde_sub_0788e8(a0, a1, a2);
        case 0x0788f0ULL: return fde_sub_0788f0(a0, a1, a2);
        case 0x078908ULL: return fde_sub_078908(a0, a1, a2);
        case 0x078910ULL: return fde_sub_078910(a0, a1, a2);
        case 0x078918ULL: return fde_sub_078918(a0, a1, a2);
        case 0x078944ULL: return fde_sub_078944(a0, a1, a2);
        case 0x07895cULL: return fde_sub_07895c(a0, a1, a2);
        case 0x0789f4ULL: return fde_sub_0789f4(a0, a1, a2);
        case 0x078a04ULL: return fde_sub_078a04(a0, a1, a2);
        case 0x078a1cULL: return fde_sub_078a1c(a0, a1, a2);
        case 0x078aecULL: return fde_sub_078aec(a0, a1, a2);
        case 0x078b30ULL: return fde_sub_078b30(a0, a1, a2);
        case 0x078b60ULL: return fde_sub_078b60(a0, a1, a2);
        case 0x078b84ULL: return fde_sub_078b84(a0, a1, a2);
        case 0x078b9cULL: return fde_sub_078b9c(a0, a1, a2);
        case 0x078df0ULL: return fde_sub_078df0(a0, a1, a2);
        case 0x078e70ULL: return fde_sub_078e70(a0, a1, a2);
        case 0x078e9cULL: return fde_sub_078e9c(a0, a1, a2);
        case 0x078eb4ULL: return fde_sub_078eb4(a0, a1, a2);
        case 0x078f10ULL: return fde_sub_078f10(a0, a1, a2);
        case 0x078f30ULL: return fde_sub_078f30(a0, a1, a2);
        case 0x078f5cULL: return fde_sub_078f5c(a0, a1, a2);
        case 0x078f74ULL: return fde_sub_078f74(a0, a1, a2);
        case 0x07900cULL: return fde_sub_07900c(a0, a1, a2);
        case 0x07901cULL: return fde_sub_07901c(a0, a1, a2);
        case 0x079034ULL: return fde_sub_079034(a0, a1, a2);
        case 0x079138ULL: return fde_sub_079138(a0, a1, a2);
        case 0x079178ULL: return fde_sub_079178(a0, a1, a2);
        case 0x0791a4ULL: return fde_sub_0791a4(a0, a1, a2);
        case 0x0791c8ULL: return fde_sub_0791c8(a0, a1, a2);
        case 0x0791e0ULL: return fde_sub_0791e0(a0, a1, a2);
        case 0x07937cULL: return fde_sub_07937c(a0, a1, a2);
        case 0x07939cULL: return fde_sub_07939c(a0, a1, a2);
        case 0x0793b4ULL: return fde_sub_0793b4(a0, a1, a2);
        case 0x07988cULL: return fde_sub_07988c(a0, a1, a2);
        case 0x079900ULL: return fde_sub_079900(a0, a1, a2);
        case 0x07991cULL: return fde_sub_07991c(a0, a1, a2);
        case 0x079944ULL: return fde_sub_079944(a0, a1, a2);
        case 0x079954ULL: return fde_sub_079954(a0, a1, a2);
        case 0x07996cULL: return fde_sub_07996c(a0, a1, a2);
        case 0x079ab8ULL: return fde_sub_079ab8(a0, a1, a2);
        case 0x079b88ULL: return fde_sub_079b88(a0, a1, a2);
        case 0x079bb4ULL: return fde_sub_079bb4(a0, a1, a2);
        case 0x079bccULL: return fde_sub_079bcc(a0, a1, a2);
        case 0x079c7cULL: return fde_sub_079c7c(a0, a1, a2);
        case 0x079ca0ULL: return fde_sub_079ca0(a0, a1, a2);
        case 0x079cb8ULL: return fde_sub_079cb8(a0, a1, a2);
        case 0x079ed8ULL: return fde_sub_079ed8(a0, a1, a2);
        case 0x079ef4ULL: return fde_sub_079ef4(a0, a1, a2);
        case 0x079f0cULL: return fde_sub_079f0c(a0, a1, a2);
        case 0x07a050ULL: return fde_sub_07a050(a0, a1, a2);
        case 0x07a070ULL: return fde_sub_07a070(a0, a1, a2);
        case 0x07a080ULL: return fde_sub_07a080(a0, a1, a2);
        case 0x07a098ULL: return fde_sub_07a098(a0, a1, a2);
        case 0x07a1a0ULL: return fde_sub_07a1a0(a0, a1, a2);
        case 0x07a3fcULL: return fde_sub_07a3fc(a0, a1, a2);
        case 0x07a428ULL: return fde_sub_07a428(a0, a1, a2);
        case 0x07a440ULL: return fde_sub_07a440(a0, a1, a2);
        case 0x07a4a8ULL: return fde_sub_07a4a8(a0, a1, a2);
        case 0x07a5a0ULL: return fde_sub_07a5a0(a0, a1, a2);
        case 0x07a5d0ULL: return fde_sub_07a5d0(a0, a1, a2);
        case 0x07a5e0ULL: return fde_sub_07a5e0(a0, a1, a2);
        case 0x07a5f8ULL: return fde_sub_07a5f8(a0, a1, a2);
        case 0x07a6dcULL: return fde_sub_07a6dc(a0, a1, a2);
        case 0x07a718ULL: return fde_sub_07a718(a0, a1, a2);
        case 0x07a730ULL: return fde_sub_07a730(a0, a1, a2);
        case 0x07a74cULL: return fde_sub_07a74c(a0, a1, a2);
        case 0x07a778ULL: return fde_sub_07a778(a0, a1, a2);
        case 0x07a790ULL: return fde_sub_07a790(a0, a1, a2);
        case 0x07a828ULL: return fde_sub_07a828(a0, a1, a2);
        case 0x07a838ULL: return fde_sub_07a838(a0, a1, a2);
        case 0x07a850ULL: return fde_sub_07a850(a0, a1, a2);
        case 0x07a998ULL: return fde_sub_07a998(a0, a1, a2);
        case 0x07a9b8ULL: return fde_sub_07a9b8(a0, a1, a2);
        case 0x07a9d0ULL: return fde_sub_07a9d0(a0, a1, a2);
        case 0x07ab18ULL: return fde_sub_07ab18(a0, a1, a2);
        case 0x07ab40ULL: return fde_sub_07ab40(a0, a1, a2);
        case 0x07ab50ULL: return fde_sub_07ab50(a0, a1, a2);
        case 0x07ab68ULL: return fde_sub_07ab68(a0, a1, a2);
        case 0x07ad38ULL: return fde_sub_07ad38(a0, a1, a2);
        case 0x07ad58ULL: return fde_sub_07ad58(a0, a1, a2);
        case 0x07ad70ULL: return fde_sub_07ad70(a0, a1, a2);
        case 0x07b040ULL: return fde_sub_07b040(a0, a1, a2);
        case 0x07b070ULL: return fde_sub_07b070(a0, a1, a2);
        case 0x07b080ULL: return fde_sub_07b080(a0, a1, a2);
        case 0x07b098ULL: return fde_sub_07b098(a0, a1, a2);
        case 0x07b234ULL: return fde_sub_07b234(a0, a1, a2);
        case 0x07b260ULL: return fde_sub_07b260(a0, a1, a2);
        case 0x07b278ULL: return fde_sub_07b278(a0, a1, a2);
        case 0x07b2ecULL: return fde_sub_07b2ec(a0, a1, a2);
        case 0x07b310ULL: return fde_sub_07b310(a0, a1, a2);
        case 0x07b328ULL: return fde_sub_07b328(a0, a1, a2);
        case 0x07b4d8ULL: return fde_sub_07b4d8(a0, a1, a2);
        case 0x07b4f4ULL: return fde_sub_07b4f4(a0, a1, a2);
        case 0x07b50cULL: return fde_sub_07b50c(a0, a1, a2);
        case 0x07b778ULL: return fde_sub_07b778(a0, a1, a2);
        case 0x07b788ULL: return fde_sub_07b788(a0, a1, a2);
        case 0x07b7a0ULL: return fde_sub_07b7a0(a0, a1, a2);
        case 0x07b8a8ULL: return fde_sub_07b8a8(a0, a1, a2);
        case 0x07b9bcULL: return fde_sub_07b9bc(a0, a1, a2);
        case 0x07bab4ULL: return fde_sub_07bab4(a0, a1, a2);
        case 0x07bb90ULL: return fde_sub_07bb90(a0, a1, a2);
        case 0x07bbfcULL: return fde_sub_07bbfc(a0, a1, a2);
        case 0x07bc34ULL: return fde_sub_07bc34(a0, a1, a2);
        case 0x07bd74ULL: return fde_sub_07bd74(a0, a1, a2);
        case 0x07bda4ULL: return fde_sub_07bda4(a0, a1, a2);
        case 0x07bdb0ULL: return fde_sub_07bdb0(a0, a1, a2);
        case 0x07bef0ULL: return fde_sub_07bef0(a0, a1, a2);
        case 0x07bfc8ULL: return fde_sub_07bfc8(a0, a1, a2);
        case 0x07c00cULL: return fde_sub_07c00c(a0, a1, a2);
        case 0x07c2d4ULL: return fde_sub_07c2d4(a0, a1, a2);
        case 0x07c308ULL: return fde_sub_07c308(a0, a1, a2);
        case 0x07c34cULL: return fde_sub_07c34c(a0, a1, a2);
        case 0x07c3e4ULL: return fde_sub_07c3e4(a0, a1, a2);
        case 0x07c460ULL: return fde_sub_07c460(a0, a1, a2);
        case 0x07c63cULL: return fde_sub_07c63c(a0, a1, a2);
        case 0x07c6ccULL: return fde_sub_07c6cc(a0, a1, a2);
        case 0x07c76cULL: return fde_sub_07c76c(a0, a1, a2);
        case 0x07c7bcULL: return fde_sub_07c7bc(a0, a1, a2);
        case 0x07c7ccULL: return fde_sub_07c7cc(a0, a1, a2);
        case 0x07c8e0ULL: return fde_sub_07c8e0(a0, a1, a2);
        case 0x07c8fcULL: return fde_sub_07c8fc(a0, a1, a2);
        case 0x07c9b4ULL: return fde_sub_07c9b4(a0, a1, a2);
        case 0x07cbc0ULL: return fde_sub_07cbc0(a0, a1, a2);
        case 0x07cc3cULL: return fde_sub_07cc3c(a0, a1, a2);
        case 0x07cc5cULL: return fde_sub_07cc5c(a0, a1, a2);
        case 0x07cc88ULL: return fde_sub_07cc88(a0, a1, a2);
        case 0x07cca4ULL: return fde_sub_07cca4(a0, a1, a2);
        case 0x07ccd8ULL: return fde_sub_07ccd8(a0, a1, a2);
        case 0x07ce1cULL: return fde_sub_07ce1c(a0, a1, a2);
        case 0x07ce48ULL: return fde_sub_07ce48(a0, a1, a2);
        case 0x07ce74ULL: return fde_sub_07ce74(a0, a1, a2);
        case 0x07ce98ULL: return fde_sub_07ce98(a0, a1, a2);
        case 0x07cf14ULL: return fde_sub_07cf14(a0, a1, a2);
        case 0x07d0a8ULL: return fde_sub_07d0a8(a0, a1, a2);
        case 0x07d0bcULL: return fde_sub_07d0bc(a0, a1, a2);
        case 0x07d158ULL: return fde_sub_07d158(a0, a1, a2);
        case 0x07d204ULL: return fde_sub_07d204(a0, a1, a2);
        case 0x07d454ULL: return fde_sub_07d454(a0, a1, a2);
        case 0x07d488ULL: return fde_sub_07d488(a0, a1, a2);
        case 0x07d4bcULL: return fde_sub_07d4bc(a0, a1, a2);
        case 0x07d53cULL: return fde_sub_07d53c(a0, a1, a2);
        case 0x07d5b8ULL: return fde_sub_07d5b8(a0, a1, a2);
        case 0x07d5c8ULL: return fde_sub_07d5c8(a0, a1, a2);
        case 0x07d5ecULL: return fde_sub_07d5ec(a0, a1, a2);
        case 0x07d5f8ULL: return fde_sub_07d5f8(a0, a1, a2);
        case 0x07d610ULL: return fde_sub_07d610(a0, a1, a2);
        case 0x07d624ULL: return fde_sub_07d624(a0, a1, a2);
        case 0x07d698ULL: return fde_sub_07d698(a0, a1, a2);
        case 0x07d6e4ULL: return fde_sub_07d6e4(a0, a1, a2);
        case 0x07d710ULL: return fde_sub_07d710(a0, a1, a2);
        case 0x07d778ULL: return fde_sub_07d778(a0, a1, a2);
        case 0x07d7b0ULL: return fde_sub_07d7b0(a0, a1, a2);
        case 0x07d86cULL: return fde_sub_07d86c(a0, a1, a2);
        case 0x07d9e8ULL: return fde_sub_07d9e8(a0, a1, a2);
        case 0x07dae4ULL: return fde_sub_07dae4(a0, a1, a2);
        case 0x07de70ULL: return fde_sub_07de70(a0, a1, a2);
        case 0x07df40ULL: return fde_sub_07df40(a0, a1, a2);
        case 0x07e010ULL: return fde_sub_07e010(a0, a1, a2);
        case 0x07e020ULL: return fde_sub_07e020(a0, a1, a2);
        case 0x07e02cULL: return fde_sub_07e02c(a0, a1, a2);
        case 0x07e038ULL: return fde_sub_07e038(a0, a1, a2);
        case 0x07e044ULL: return fde_sub_07e044(a0, a1, a2);
        case 0x07e050ULL: return fde_sub_07e050(a0, a1, a2);
        case 0x07e060ULL: return fde_sub_07e060(a0, a1, a2);
        case 0x07e0c4ULL: return fde_sub_07e0c4(a0, a1, a2);
        case 0x07e0d4ULL: return fde_sub_07e0d4(a0, a1, a2);
        case 0x07e0e0ULL: return fde_sub_07e0e0(a0, a1, a2);
        case 0x07e134ULL: return fde_sub_07e134(a0, a1, a2);
        case 0x07e178ULL: return fde_sub_07e178(a0, a1, a2);
        case 0x07e1ecULL: return fde_sub_07e1ec(a0, a1, a2);
        case 0x07e698ULL: return fde_sub_07e698(a0, a1, a2);
        case 0x07e6a4ULL: return fde_sub_07e6a4(a0, a1, a2);
        case 0x07e6b0ULL: return fde_sub_07e6b0(a0, a1, a2);
        case 0x07e6c0ULL: return fde_sub_07e6c0(a0, a1, a2);
        case 0x07e6c8ULL: return fde_sub_07e6c8(a0, a1, a2);
        case 0x07e6d0ULL: return fde_sub_07e6d0(a0, a1, a2);
        case 0x07e6d8ULL: return fde_sub_07e6d8(a0, a1, a2);
        case 0x07e6e0ULL: return fde_sub_07e6e0(a0, a1, a2);
        case 0x07e6e8ULL: return fde_sub_07e6e8(a0, a1, a2);
        case 0x07e700ULL: return fde_sub_07e700(a0, a1, a2);
        case 0x07e70cULL: return fde_sub_07e70c(a0, a1, a2);
        case 0x07e718ULL: return fde_sub_07e718(a0, a1, a2);
        case 0x07e724ULL: return fde_sub_07e724(a0, a1, a2);
        case 0x07e820ULL: return fde_sub_07e820(a0, a1, a2);
        case 0x07e828ULL: return fde_sub_07e828(a0, a1, a2);
        case 0x07e838ULL: return fde_sub_07e838(a0, a1, a2);
        case 0x07e868ULL: return fde_sub_07e868(a0, a1, a2);
        case 0x07e870ULL: return fde_sub_07e870(a0, a1, a2);
        case 0x07e8d4ULL: return fde_sub_07e8d4(a0, a1, a2);
        case 0x07e8e0ULL: return fde_sub_07e8e0(a0, a1, a2);
        case 0x07e8e8ULL: return fde_sub_07e8e8(a0, a1, a2);
        case 0x07e8f4ULL: return fde_sub_07e8f4(a0, a1, a2);
        case 0x07e900ULL: return fde_sub_07e900(a0, a1, a2);
        case 0x07e910ULL: return fde_sub_07e910(a0, a1, a2);
        case 0x07e918ULL: return fde_sub_07e918(a0, a1, a2);
        case 0x07ea20ULL: return fde_sub_07ea20(a0, a1, a2);
        case 0x07eb4cULL: return fde_sub_07eb4c(a0, a1, a2);
        case 0x07ecb8ULL: return fde_sub_07ecb8(a0, a1, a2);
        case 0x07ed88ULL: return fde_sub_07ed88(a0, a1, a2);
        case 0x07ef7cULL: return fde_sub_07ef7c(a0, a1, a2);
        case 0x07efa0ULL: return fde_sub_07efa0(a0, a1, a2);
        case 0x07efb0ULL: return fde_sub_07efb0(a0, a1, a2);
        case 0x07efc8ULL: return fde_sub_07efc8(a0, a1, a2);
        case 0x07f0f0ULL: return fde_sub_07f0f0(a0, a1, a2);
        case 0x07f124ULL: return fde_sub_07f124(a0, a1, a2);
        case 0x07f130ULL: return fde_sub_07f130(a0, a1, a2);
        case 0x07f148ULL: return fde_sub_07f148(a0, a1, a2);
        case 0x07f158ULL: return fde_sub_07f158(a0, a1, a2);
        case 0x07f18cULL: return fde_sub_07f18c(a0, a1, a2);
        case 0x07f1f0ULL: return fde_sub_07f1f0(a0, a1, a2);
        case 0x07f220ULL: return fde_sub_07f220(a0, a1, a2);
        case 0x07f250ULL: return fde_sub_07f250(a0, a1, a2);
        case 0x07f26cULL: return fde_sub_07f26c(a0, a1, a2);
        case 0x07f280ULL: return fde_sub_07f280(a0, a1, a2);
        case 0x07f290ULL: return fde_sub_07f290(a0, a1, a2);
        case 0x07f2a8ULL: return fde_sub_07f2a8(a0, a1, a2);
        case 0x07f3d8ULL: return fde_sub_07f3d8(a0, a1, a2);
        case 0x07f488ULL: return fde_sub_07f488(a0, a1, a2);
        case 0x07f4a0ULL: return fde_sub_07f4a0(a0, a1, a2);
        case 0x07f4ccULL: return fde_sub_07f4cc(a0, a1, a2);
        case 0x07f4dcULL: return fde_sub_07f4dc(a0, a1, a2);
        case 0x07f508ULL: return fde_sub_07f508(a0, a1, a2);
        case 0x07f518ULL: return fde_sub_07f518(a0, a1, a2);
        case 0x07f530ULL: return fde_sub_07f530(a0, a1, a2);
        case 0x07fa9cULL: return fde_sub_07fa9c(a0, a1, a2);
        case 0x07fab4ULL: return fde_sub_07fab4(a0, a1, a2);
        case 0x07faccULL: return fde_sub_07facc(a0, a1, a2);
        case 0x07fce0ULL: return fde_sub_07fce0(a0, a1, a2);
        case 0x07fd00ULL: return fde_sub_07fd00(a0, a1, a2);
        case 0x07fd18ULL: return fde_sub_07fd18(a0, a1, a2);
        case 0x07fd20ULL: return fde_sub_07fd20(a0, a1, a2);
        case 0x07fd40ULL: return fde_sub_07fd40(a0, a1, a2);
        case 0x07fd58ULL: return fde_sub_07fd58(a0, a1, a2);
        case 0x07fd70ULL: return fde_sub_07fd70(a0, a1, a2);
        case 0x07fd88ULL: return fde_sub_07fd88(a0, a1, a2);
        case 0x07fe58ULL: return fde_sub_07fe58(a0, a1, a2);
        case 0x07fe78ULL: return fde_sub_07fe78(a0, a1, a2);
        case 0x07fe90ULL: return fde_sub_07fe90(a0, a1, a2);
        case 0x07fe98ULL: return fde_sub_07fe98(a0, a1, a2);
        case 0x07feacULL: return fde_sub_07feac(a0, a1, a2);
        case 0x07fefcULL: return fde_sub_07fefc(a0, a1, a2);
        case 0x07ff3cULL: return fde_sub_07ff3c(a0, a1, a2);
        case 0x07ff8cULL: return fde_sub_07ff8c(a0, a1, a2);
        case 0x080148ULL: return fde_sub_080148(a0, a1, a2);
        case 0x08018cULL: return fde_sub_08018c(a0, a1, a2);
        case 0x0801a4ULL: return fde_sub_0801a4(a0, a1, a2);
        case 0x0802a8ULL: return fde_sub_0802a8(a0, a1, a2);
        case 0x0802b0ULL: return fde_sub_0802b0(a0, a1, a2);
        case 0x0802d4ULL: return fde_sub_0802d4(a0, a1, a2);
        case 0x080354ULL: return fde_sub_080354(a0, a1, a2);
        case 0x080388ULL: return fde_sub_080388(a0, a1, a2);
        case 0x0803a0ULL: return fde_sub_0803a0(a0, a1, a2);
        case 0x08041cULL: return fde_sub_08041c(a0, a1, a2);
        case 0x080424ULL: return fde_sub_080424(a0, a1, a2);
        case 0x080438ULL: return fde_sub_080438(a0, a1, a2);
        case 0x080478ULL: return fde_sub_080478(a0, a1, a2);
        case 0x0804a4ULL: return fde_sub_0804a4(a0, a1, a2);
        case 0x0804bcULL: return fde_sub_0804bc(a0, a1, a2);
        case 0x08090cULL: return fde_sub_08090c(a0, a1, a2);
        case 0x080914ULL: return fde_sub_080914(a0, a1, a2);
        case 0x080928ULL: return fde_sub_080928(a0, a1, a2);
        case 0x080964ULL: return fde_sub_080964(a0, a1, a2);
        case 0x0809acULL: return fde_sub_0809ac(a0, a1, a2);
        case 0x0809d8ULL: return fde_sub_0809d8(a0, a1, a2);
        case 0x080a30ULL: return fde_sub_080a30(a0, a1, a2);
        case 0x080a54ULL: return fde_sub_080a54(a0, a1, a2);
        case 0x080aacULL: return fde_sub_080aac(a0, a1, a2);
        case 0x080b04ULL: return fde_sub_080b04(a0, a1, a2);
        case 0x080b44ULL: return fde_sub_080b44(a0, a1, a2);
        case 0x080b84ULL: return fde_sub_080b84(a0, a1, a2);
        case 0x080bc8ULL: return fde_sub_080bc8(a0, a1, a2);
        case 0x080c6cULL: return fde_sub_080c6c(a0, a1, a2);
        case 0x080c9cULL: return fde_sub_080c9c(a0, a1, a2);
        case 0x080ca8ULL: return fde_sub_080ca8(a0, a1, a2);
        case 0x080cc0ULL: return fde_sub_080cc0(a0, a1, a2);
        case 0x080d18ULL: return fde_sub_080d18(a0, a1, a2);
        case 0x080d3cULL: return fde_sub_080d3c(a0, a1, a2);
        case 0x080d54ULL: return fde_sub_080d54(a0, a1, a2);
        case 0x080e2cULL: return fde_sub_080e2c(a0, a1, a2);
        case 0x080e4cULL: return fde_sub_080e4c(a0, a1, a2);
        case 0x080f88ULL: return fde_sub_080f88(a0, a1, a2);
        case 0x081160ULL: return fde_sub_081160(a0, a1, a2);
        case 0x0811ecULL: return fde_sub_0811ec(a0, a1, a2);
        case 0x081404ULL: return fde_sub_081404(a0, a1, a2);
        case 0x081478ULL: return fde_sub_081478(a0, a1, a2);
        case 0x0814acULL: return fde_sub_0814ac(a0, a1, a2);
        case 0x0814e4ULL: return fde_sub_0814e4(a0, a1, a2);
        case 0x0814fcULL: return fde_sub_0814fc(a0, a1, a2);
        case 0x081508ULL: return fde_sub_081508(a0, a1, a2);
        case 0x081514ULL: return fde_sub_081514(a0, a1, a2);
        case 0x081538ULL: return fde_sub_081538(a0, a1, a2);
        case 0x0815c4ULL: return fde_sub_0815c4(a0, a1, a2);
        case 0x081610ULL: return fde_sub_081610(a0, a1, a2);
        case 0x0816dcULL: return fde_sub_0816dc(a0, a1, a2);
        case 0x0817fcULL: return fde_sub_0817fc(a0, a1, a2);
        case 0x081820ULL: return fde_sub_081820(a0, a1, a2);
        case 0x081838ULL: return fde_sub_081838(a0, a1, a2);
        case 0x081a88ULL: return fde_sub_081a88(a0, a1, a2);
        case 0x081a90ULL: return fde_sub_081a90(a0, a1, a2);
        case 0x081ae0ULL: return fde_sub_081ae0(a0, a1, a2);
        case 0x081b70ULL: return fde_sub_081b70(a0, a1, a2);
        case 0x081c08ULL: return fde_sub_081c08(a0, a1, a2);
        case 0x081c28ULL: return fde_sub_081c28(a0, a1, a2);
        case 0x081c40ULL: return fde_sub_081c40(a0, a1, a2);
        case 0x081c8cULL: return fde_sub_081c8c(a0, a1, a2);
        case 0x081ce0ULL: return fde_sub_081ce0(a0, a1, a2);
        case 0x081d68ULL: return fde_sub_081d68(a0, a1, a2);
        case 0x081d80ULL: return fde_sub_081d80(a0, a1, a2);
        case 0x081ef8ULL: return fde_sub_081ef8(a0, a1, a2);
        case 0x081f00ULL: return fde_sub_081f00(a0, a1, a2);
        case 0x082054ULL: return fde_sub_082054(a0, a1, a2);
        case 0x08206cULL: return fde_sub_08206c(a0, a1, a2);
        case 0x08209cULL: return fde_sub_08209c(a0, a1, a2);
        case 0x0820b4ULL: return fde_sub_0820b4(a0, a1, a2);
        case 0x0820c0ULL: return fde_sub_0820c0(a0, a1, a2);
        case 0x0820ccULL: return fde_sub_0820cc(a0, a1, a2);
        case 0x0820fcULL: return fde_sub_0820fc(a0, a1, a2);
        case 0x082104ULL: return fde_sub_082104(a0, a1, a2);
        case 0x08210cULL: return fde_sub_08210c(a0, a1, a2);
        case 0x082140ULL: return fde_sub_082140(a0, a1, a2);
        case 0x082158ULL: return fde_sub_082158(a0, a1, a2);
        case 0x082338ULL: return fde_sub_082338(a0, a1, a2);
        case 0x082344ULL: return fde_sub_082344(a0, a1, a2);
        case 0x082350ULL: return fde_sub_082350(a0, a1, a2);
        case 0x082358ULL: return fde_sub_082358(a0, a1, a2);
        case 0x082360ULL: return fde_sub_082360(a0, a1, a2);
        case 0x0823a0ULL: return fde_sub_0823a0(a0, a1, a2);
        case 0x0823bcULL: return fde_sub_0823bc(a0, a1, a2);
        case 0x082488ULL: return fde_sub_082488(a0, a1, a2);
        case 0x0825d4ULL: return fde_sub_0825d4(a0, a1, a2);
        case 0x0826fcULL: return fde_sub_0826fc(a0, a1, a2);
        case 0x08272cULL: return fde_sub_08272c(a0, a1, a2);
        case 0x0828ccULL: return fde_sub_0828cc(a0, a1, a2);
        case 0x082940ULL: return fde_sub_082940(a0, a1, a2);
        case 0x082a54ULL: return fde_sub_082a54(a0, a1, a2);
        case 0x082a84ULL: return fde_sub_082a84(a0, a1, a2);
        case 0x082ab4ULL: return fde_sub_082ab4(a0, a1, a2);
        case 0x082ad4ULL: return fde_sub_082ad4(a0, a1, a2);
        case 0x082aecULL: return fde_sub_082aec(a0, a1, a2);
        case 0x082bb0ULL: return fde_sub_082bb0(a0, a1, a2);
        case 0x082bbcULL: return fde_sub_082bbc(a0, a1, a2);
        case 0x082bd4ULL: return fde_sub_082bd4(a0, a1, a2);
        case 0x082d28ULL: return fde_sub_082d28(a0, a1, a2);
        case 0x0830f8ULL: return fde_sub_0830f8(a0, a1, a2);
        case 0x083130ULL: return fde_sub_083130(a0, a1, a2);
        case 0x083170ULL: return fde_sub_083170(a0, a1, a2);
        case 0x083190ULL: return fde_sub_083190(a0, a1, a2);
        case 0x0831b0ULL: return fde_sub_0831b0(a0, a1, a2);
        case 0x0831c8ULL: return fde_sub_0831c8(a0, a1, a2);
        case 0x0831e0ULL: return fde_sub_0831e0(a0, a1, a2);
        case 0x083204ULL: return fde_sub_083204(a0, a1, a2);
        case 0x0834d0ULL: return fde_sub_0834d0(a0, a1, a2);
        case 0x08356cULL: return fde_sub_08356c(a0, a1, a2);
        case 0x0837f8ULL: return fde_sub_0837f8(a0, a1, a2);
        case 0x08382cULL: return fde_sub_08382c(a0, a1, a2);
        case 0x0839e4ULL: return fde_sub_0839e4(a0, a1, a2);
        case 0x083b9cULL: return fde_sub_083b9c(a0, a1, a2);
        case 0x083be4ULL: return fde_sub_083be4(a0, a1, a2);
        case 0x083bf4ULL: return fde_sub_083bf4(a0, a1, a2);
        case 0x083c0cULL: return fde_sub_083c0c(a0, a1, a2);
        case 0x083ca0ULL: return fde_sub_083ca0(a0, a1, a2);
        case 0x083cb4ULL: return fde_sub_083cb4(a0, a1, a2);
        case 0x083cd0ULL: return fde_sub_083cd0(a0, a1, a2);
        case 0x083ce8ULL: return fde_sub_083ce8(a0, a1, a2);
        case 0x083cf0ULL: return fde_sub_083cf0(a0, a1, a2);
        case 0x083d1cULL: return fde_sub_083d1c(a0, a1, a2);
        case 0x083d70ULL: return fde_sub_083d70(a0, a1, a2);
        case 0x083da0ULL: return fde_sub_083da0(a0, a1, a2);
        case 0x0840f8ULL: return fde_sub_0840f8(a0, a1, a2);
        case 0x084168ULL: return fde_sub_084168(a0, a1, a2);
        case 0x084188ULL: return fde_sub_084188(a0, a1, a2);
        case 0x0841c8ULL: return fde_sub_0841c8(a0, a1, a2);
        case 0x0841d4ULL: return fde_sub_0841d4(a0, a1, a2);
        case 0x084778ULL: return fde_sub_084778(a0, a1, a2);
        case 0x0847a4ULL: return fde_sub_0847a4(a0, a1, a2);
        case 0x084954ULL: return fde_sub_084954(a0, a1, a2);
        case 0x084974ULL: return fde_sub_084974(a0, a1, a2);
        case 0x08498cULL: return fde_sub_08498c(a0, a1, a2);
        case 0x0849b8ULL: return fde_sub_0849b8(a0, a1, a2);
        case 0x084c7cULL: return fde_sub_084c7c(a0, a1, a2);
        case 0x084cfcULL: return fde_sub_084cfc(a0, a1, a2);
        case 0x084d04ULL: return fde_sub_084d04(a0, a1, a2);
        case 0x084d1cULL: return fde_sub_084d1c(a0, a1, a2);
        case 0x084facULL: return fde_sub_084fac(a0, a1, a2);
        case 0x084fccULL: return fde_sub_084fcc(a0, a1, a2);
        case 0x084fe4ULL: return fde_sub_084fe4(a0, a1, a2);
        case 0x085070ULL: return fde_sub_085070(a0, a1, a2);
        case 0x085074ULL: return fde_sub_085074(a0, a1, a2);
        case 0x0850a0ULL: return fde_sub_0850a0(a0, a1, a2);
        case 0x0850ccULL: return fde_sub_0850cc(a0, a1, a2);
        case 0x0850e4ULL: return fde_sub_0850e4(a0, a1, a2);
        case 0x085184ULL: return fde_sub_085184(a0, a1, a2);
        case 0x085194ULL: return fde_sub_085194(a0, a1, a2);
        case 0x0851acULL: return fde_sub_0851ac(a0, a1, a2);
        case 0x08529cULL: return fde_sub_08529c(a0, a1, a2);
        case 0x0852dcULL: return fde_sub_0852dc(a0, a1, a2);
        case 0x0852f4ULL: return fde_sub_0852f4(a0, a1, a2);
        case 0x085404ULL: return fde_sub_085404(a0, a1, a2);
        case 0x08541cULL: return fde_sub_08541c(a0, a1, a2);
        case 0x085490ULL: return fde_sub_085490(a0, a1, a2);
        case 0x08553cULL: return fde_sub_08553c(a0, a1, a2);
        case 0x08554cULL: return fde_sub_08554c(a0, a1, a2);
        case 0x085694ULL: return fde_sub_085694(a0, a1, a2);
        case 0x0856bcULL: return fde_sub_0856bc(a0, a1, a2);
        case 0x085734ULL: return fde_sub_085734(a0, a1, a2);
        case 0x085768ULL: return fde_sub_085768(a0, a1, a2);
        case 0x085978ULL: return fde_sub_085978(a0, a1, a2);
        case 0x085a64ULL: return fde_sub_085a64(a0, a1, a2);
        case 0x085a88ULL: return fde_sub_085a88(a0, a1, a2);
        case 0x085aa0ULL: return fde_sub_085aa0(a0, a1, a2);
        case 0x085b74ULL: return fde_sub_085b74(a0, a1, a2);
        case 0x085b98ULL: return fde_sub_085b98(a0, a1, a2);
        case 0x085ba8ULL: return fde_sub_085ba8(a0, a1, a2);
        case 0x085bc0ULL: return fde_sub_085bc0(a0, a1, a2);
        case 0x085c4cULL: return fde_sub_085c4c(a0, a1, a2);
        case 0x086024ULL: return fde_sub_086024(a0, a1, a2);
        case 0x086088ULL: return fde_sub_086088(a0, a1, a2);
        case 0x0860a0ULL: return fde_sub_0860a0(a0, a1, a2);
        case 0x0861acULL: return fde_sub_0861ac(a0, a1, a2);
        case 0x0861ccULL: return fde_sub_0861cc(a0, a1, a2);
        case 0x0861e4ULL: return fde_sub_0861e4(a0, a1, a2);
        case 0x086260ULL: return fde_sub_086260(a0, a1, a2);
        case 0x0862e8ULL: return fde_sub_0862e8(a0, a1, a2);
        case 0x086308ULL: return fde_sub_086308(a0, a1, a2);
        case 0x08631cULL: return fde_sub_08631c(a0, a1, a2);
        case 0x08632cULL: return fde_sub_08632c(a0, a1, a2);
        case 0x086380ULL: return fde_sub_086380(a0, a1, a2);
        case 0x0863bcULL: return fde_sub_0863bc(a0, a1, a2);
        case 0x086400ULL: return fde_sub_086400(a0, a1, a2);
        case 0x086414ULL: return fde_sub_086414(a0, a1, a2);
        case 0x086464ULL: return fde_sub_086464(a0, a1, a2);
        case 0x086500ULL: return fde_sub_086500(a0, a1, a2);
        case 0x086514ULL: return fde_sub_086514(a0, a1, a2);
        case 0x0865c8ULL: return fde_sub_0865c8(a0, a1, a2);
        case 0x08671cULL: return fde_sub_08671c(a0, a1, a2);
        case 0x08674cULL: return fde_sub_08674c(a0, a1, a2);
        case 0x0867ccULL: return fde_sub_0867cc(a0, a1, a2);
        case 0x0867dcULL: return fde_sub_0867dc(a0, a1, a2);
        case 0x08683cULL: return fde_sub_08683c(a0, a1, a2);
        case 0x086884ULL: return fde_sub_086884(a0, a1, a2);
        case 0x0868d8ULL: return fde_sub_0868d8(a0, a1, a2);
        case 0x0869acULL: return fde_sub_0869ac(a0, a1, a2);
        case 0x086c6cULL: return fde_sub_086c6c(a0, a1, a2);
        case 0x086ca8ULL: return fde_sub_086ca8(a0, a1, a2);
        case 0x086db4ULL: return fde_sub_086db4(a0, a1, a2);
        case 0x086dccULL: return fde_sub_086dcc(a0, a1, a2);
        case 0x086f54ULL: return fde_sub_086f54(a0, a1, a2);
        case 0x0871c4ULL: return fde_sub_0871c4(a0, a1, a2);
        case 0x0872f4ULL: return fde_sub_0872f4(a0, a1, a2);
        case 0x08763cULL: return fde_sub_08763c(a0, a1, a2);
        case 0x087778ULL: return fde_sub_087778(a0, a1, a2);
        case 0x0877b8ULL: return fde_sub_0877b8(a0, a1, a2);
        case 0x0877e8ULL: return fde_sub_0877e8(a0, a1, a2);
        case 0x08782cULL: return fde_sub_08782c(a0, a1, a2);
        case 0x087844ULL: return fde_sub_087844(a0, a1, a2);
        case 0x08788cULL: return fde_sub_08788c(a0, a1, a2);
        case 0x0878d0ULL: return fde_sub_0878d0(a0, a1, a2);
        case 0x0878e8ULL: return fde_sub_0878e8(a0, a1, a2);
        case 0x087938ULL: return fde_sub_087938(a0, a1, a2);
        case 0x087970ULL: return fde_sub_087970(a0, a1, a2);
        case 0x0879bcULL: return fde_sub_0879bc(a0, a1, a2);
        case 0x087a28ULL: return fde_sub_087a28(a0, a1, a2);
        case 0x087a98ULL: return fde_sub_087a98(a0, a1, a2);
        case 0x087af4ULL: return fde_sub_087af4(a0, a1, a2);
        case 0x087b5cULL: return fde_sub_087b5c(a0, a1, a2);
        case 0x087b9cULL: return fde_sub_087b9c(a0, a1, a2);
        case 0x087cbcULL: return fde_sub_087cbc(a0, a1, a2);
        case 0x087d3cULL: return fde_sub_087d3c(a0, a1, a2);
        case 0x087d60ULL: return fde_sub_087d60(a0, a1, a2);
        case 0x087d94ULL: return fde_sub_087d94(a0, a1, a2);
        case 0x087dacULL: return fde_sub_087dac(a0, a1, a2);
        case 0x087dc4ULL: return fde_sub_087dc4(a0, a1, a2);
        case 0x087ddcULL: return fde_sub_087ddc(a0, a1, a2);
        case 0x087e00ULL: return fde_sub_087e00(a0, a1, a2);
        case 0x087e68ULL: return fde_sub_087e68(a0, a1, a2);
        case 0x08800cULL: return fde_sub_08800c(a0, a1, a2);
        case 0x088030ULL: return fde_sub_088030(a0, a1, a2);
        case 0x08807cULL: return fde_sub_08807c(a0, a1, a2);
        case 0x0882ccULL: return fde_sub_0882cc(a0, a1, a2);
        case 0x0882d4ULL: return fde_sub_0882d4(a0, a1, a2);
        case 0x088310ULL: return fde_sub_088310(a0, a1, a2);
        case 0x088340ULL: return fde_sub_088340(a0, a1, a2);
        case 0x088370ULL: return fde_sub_088370(a0, a1, a2);
        case 0x08839cULL: return fde_sub_08839c(a0, a1, a2);
        case 0x0883d4ULL: return fde_sub_0883d4(a0, a1, a2);
        case 0x0885a4ULL: return fde_sub_0885a4(a0, a1, a2);
        case 0x088714ULL: return fde_sub_088714(a0, a1, a2);
        case 0x088748ULL: return fde_sub_088748(a0, a1, a2);
        case 0x088780ULL: return fde_sub_088780(a0, a1, a2);
        case 0x0887a4ULL: return fde_sub_0887a4(a0, a1, a2);
        case 0x088820ULL: return fde_sub_088820(a0, a1, a2);
        case 0x08887cULL: return fde_sub_08887c(a0, a1, a2);
        case 0x088888ULL: return fde_sub_088888(a0, a1, a2);
        case 0x0888a8ULL: return fde_sub_0888a8(a0, a1, a2);
        case 0x0888c8ULL: return fde_sub_0888c8(a0, a1, a2);
        case 0x0888e8ULL: return fde_sub_0888e8(a0, a1, a2);
        case 0x088900ULL: return fde_sub_088900(a0, a1, a2);
        case 0x088918ULL: return fde_sub_088918(a0, a1, a2);
        case 0x088920ULL: return fde_sub_088920(a0, a1, a2);
        case 0x088978ULL: return fde_sub_088978(a0, a1, a2);
        case 0x0889b4ULL: return fde_sub_0889b4(a0, a1, a2);
        case 0x0889ccULL: return fde_sub_0889cc(a0, a1, a2);
        case 0x088a04ULL: return fde_sub_088a04(a0, a1, a2);
        case 0x088a08ULL: return fde_sub_088a08(a0, a1, a2);
        case 0x088a10ULL: return fde_sub_088a10(a0, a1, a2);
        case 0x088a78ULL: return fde_sub_088a78(a0, a1, a2);
        case 0x088aa4ULL: return fde_sub_088aa4(a0, a1, a2);
        case 0x088abcULL: return fde_sub_088abc(a0, a1, a2);
        case 0x088b00ULL: return fde_sub_088b00(a0, a1, a2);
        case 0x088b2cULL: return fde_sub_088b2c(a0, a1, a2);
        case 0x088bc0ULL: return fde_sub_088bc0(a0, a1, a2);
        case 0x088c18ULL: return fde_sub_088c18(a0, a1, a2);
        case 0x088c50ULL: return fde_sub_088c50(a0, a1, a2);
        case 0x088c68ULL: return fde_sub_088c68(a0, a1, a2);
        case 0x088c70ULL: return fde_sub_088c70(a0, a1, a2);
        case 0x088c78ULL: return fde_sub_088c78(a0, a1, a2);
        case 0x088c9cULL: return fde_sub_088c9c(a0, a1, a2);
        case 0x088cb0ULL: return fde_sub_088cb0(a0, a1, a2);
        case 0x088f0cULL: return fde_sub_088f0c(a0, a1, a2);
        case 0x08906cULL: return fde_sub_08906c(a0, a1, a2);
        case 0x08907cULL: return fde_sub_08907c(a0, a1, a2);
        case 0x089084ULL: return fde_sub_089084(a0, a1, a2);
        case 0x0890acULL: return fde_sub_0890ac(a0, a1, a2);
        case 0x0892d8ULL: return fde_sub_0892d8(a0, a1, a2);
        case 0x0892f8ULL: return fde_sub_0892f8(a0, a1, a2);
        case 0x089310ULL: return fde_sub_089310(a0, a1, a2);
        case 0x089348ULL: return fde_sub_089348(a0, a1, a2);
        case 0x089394ULL: return fde_sub_089394(a0, a1, a2);
        case 0x0893b4ULL: return fde_sub_0893b4(a0, a1, a2);
        case 0x0893b8ULL: return fde_sub_0893b8(a0, a1, a2);
        case 0x0893d0ULL: return fde_sub_0893d0(a0, a1, a2);
        case 0x0893e8ULL: return fde_sub_0893e8(a0, a1, a2);
        case 0x08954cULL: return fde_sub_08954c(a0, a1, a2);
        case 0x089598ULL: return fde_sub_089598(a0, a1, a2);
        case 0x0896f4ULL: return fde_sub_0896f4(a0, a1, a2);
        case 0x089738ULL: return fde_sub_089738(a0, a1, a2);
        case 0x089844ULL: return fde_sub_089844(a0, a1, a2);
        case 0x089884ULL: return fde_sub_089884(a0, a1, a2);
        case 0x08990cULL: return fde_sub_08990c(a0, a1, a2);
        case 0x089934ULL: return fde_sub_089934(a0, a1, a2);
        case 0x08995cULL: return fde_sub_08995c(a0, a1, a2);
        case 0x089960ULL: return fde_sub_089960(a0, a1, a2);
        case 0x089974ULL: return fde_sub_089974(a0, a1, a2);
        case 0x0899d8ULL: return fde_sub_0899d8(a0, a1, a2);
        case 0x089a04ULL: return fde_sub_089a04(a0, a1, a2);
        case 0x089a50ULL: return fde_sub_089a50(a0, a1, a2);
        case 0x089abcULL: return fde_sub_089abc(a0, a1, a2);
        case 0x089ba8ULL: return fde_sub_089ba8(a0, a1, a2);
        case 0x089cb4ULL: return fde_sub_089cb4(a0, a1, a2);
        case 0x089d24ULL: return fde_sub_089d24(a0, a1, a2);
        case 0x089dfcULL: return fde_sub_089dfc(a0, a1, a2);
        case 0x089f20ULL: return fde_sub_089f20(a0, a1, a2);
        case 0x089f24ULL: return fde_sub_089f24(a0, a1, a2);
        case 0x089f28ULL: return fde_sub_089f28(a0, a1, a2);
        case 0x089f2cULL: return fde_sub_089f2c(a0, a1, a2);
        case 0x089f30ULL: return fde_sub_089f30(a0, a1, a2);
        case 0x089f90ULL: return fde_sub_089f90(a0, a1, a2);
        case 0x089ff0ULL: return fde_sub_089ff0(a0, a1, a2);
        case 0x08a068ULL: return fde_sub_08a068(a0, a1, a2);
        case 0x08a138ULL: return fde_sub_08a138(a0, a1, a2);
        case 0x08a730ULL: return fde_sub_08a730(a0, a1, a2);
        case 0x08a79cULL: return fde_sub_08a79c(a0, a1, a2);
        case 0x08a808ULL: return fde_sub_08a808(a0, a1, a2);
        case 0x08a830ULL: return fde_sub_08a830(a0, a1, a2);
        case 0x08a850ULL: return fde_sub_08a850(a0, a1, a2);
        case 0x08a868ULL: return fde_sub_08a868(a0, a1, a2);
        case 0x08a870ULL: return fde_sub_08a870(a0, a1, a2);
        case 0x08a894ULL: return fde_sub_08a894(a0, a1, a2);
        case 0x08ac3cULL: return fde_sub_08ac3c(a0, a1, a2);
        case 0x08af84ULL: return fde_sub_08af84(a0, a1, a2);
        case 0x08b244ULL: return fde_sub_08b244(a0, a1, a2);
        case 0x08b270ULL: return fde_sub_08b270(a0, a1, a2);
        case 0x08b278ULL: return fde_sub_08b278(a0, a1, a2);
        case 0x08b290ULL: return fde_sub_08b290(a0, a1, a2);
        case 0x08b2a4ULL: return fde_sub_08b2a4(a0, a1, a2);
        case 0x08b2b4ULL: return fde_sub_08b2b4(a0, a1, a2);
        case 0x08b2ccULL: return fde_sub_08b2cc(a0, a1, a2);
        case 0x08b2dcULL: return fde_sub_08b2dc(a0, a1, a2);
        case 0x08b2ecULL: return fde_sub_08b2ec(a0, a1, a2);
        case 0x08b3f8ULL: return fde_sub_08b3f8(a0, a1, a2);
        case 0x08b410ULL: return fde_sub_08b410(a0, a1, a2);
        case 0x08b51cULL: return fde_sub_08b51c(a0, a1, a2);
        case 0x08b534ULL: return fde_sub_08b534(a0, a1, a2);
        case 0x08b640ULL: return fde_sub_08b640(a0, a1, a2);
        case 0x08b658ULL: return fde_sub_08b658(a0, a1, a2);
        case 0x08b730ULL: return fde_sub_08b730(a0, a1, a2);
        case 0x08b734ULL: return fde_sub_08b734(a0, a1, a2);
        case 0x08b808ULL: return fde_sub_08b808(a0, a1, a2);
        case 0x08b820ULL: return fde_sub_08b820(a0, a1, a2);
        case 0x08b838ULL: return fde_sub_08b838(a0, a1, a2);
        case 0x08b858ULL: return fde_sub_08b858(a0, a1, a2);
        case 0x08b880ULL: return fde_sub_08b880(a0, a1, a2);
        case 0x08b8a8ULL: return fde_sub_08b8a8(a0, a1, a2);
        case 0x08b8c8ULL: return fde_sub_08b8c8(a0, a1, a2);
        case 0x08b8e0ULL: return fde_sub_08b8e0(a0, a1, a2);
        case 0x08b8e8ULL: return fde_sub_08b8e8(a0, a1, a2);
        case 0x08b938ULL: return fde_sub_08b938(a0, a1, a2);
        case 0x08b954ULL: return fde_sub_08b954(a0, a1, a2);
        case 0x08b984ULL: return fde_sub_08b984(a0, a1, a2);
        case 0x08b988ULL: return fde_sub_08b988(a0, a1, a2);
        case 0x08b98cULL: return fde_sub_08b98c(a0, a1, a2);
        case 0x08b9ecULL: return fde_sub_08b9ec(a0, a1, a2);
        case 0x08bb58ULL: return fde_sub_08bb58(a0, a1, a2);
        case 0x08bb68ULL: return fde_sub_08bb68(a0, a1, a2);
        default: return 0ULL;
    }
}

} // namespace animax
} // namespace lynx
