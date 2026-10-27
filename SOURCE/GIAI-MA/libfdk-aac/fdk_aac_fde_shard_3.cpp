// ============================================================================
// File: fdk_aac_fde_shard_3.cpp
// Target 105 / 169: libfdk-aac.so (625,312 bytes)
// EN: Clean-room C++17 AArch64 FDE Shard 3/5 covering FDEs [590..884]
//     (PC range 0x04e194 .. 0x069f30).
// VI: Phân mảnh FDE AArch64 C++17 3/5 bao phủ các FDE [590..884]
//     (Dải địa chỉ PC 0x04e194 .. 0x069f30).
// ============================================================================
#include "fdk_aac_codec_core.h"

namespace opencut {
namespace fdk_aac {

// FDE #0590 | PC: 0x04e194..0x04e1b0 (28 B) | Symbol: _Z27transportEnc_GetChannelModei
// EN: AArch64 prologue [sub w8, w0, #1; cmp w0, #8; mov w9, #7; csel w9, w9, w0, eq] | VI: Khởi đầu hàm AArch64 [sub w8, w0, #1; cmp w0, #8; mov w9, #7; csel w9, w9, w0, eq]
uint64_t fde_sub_04e194(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100201FULL) << 32) | 0x51000408ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E194ULL;
}

// FDE #0591 | PC: 0x04e1b0..0x04e3a8 (504 B) | Symbol: _Z21transportEnc_writePCEP13FDK_BITSTREAM12CHANNEL_MODEiiiiij
// EN: AArch64 prologue [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_04e1b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94006F59ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x01F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E1B0ULL;
}

// FDE #0592 | PC: 0x04e3a8..0x04e3e0 (56 B) | Symbol: sub_04e3a8
// EN: AArch64 prologue [adrp x9, #0x7f000; mov x8, xzr; add x9, x9, #0x294; cmp x8, #0x10] | VI: Khởi đầu hàm AArch64 [adrp x9, #0x7f000; mov x8, xzr; add x9, x9, #0x294; cmp x8, #0x10]
uint64_t fde_sub_04e3a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E8ULL) << 32) | 0xB0000189ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E3A8ULL;
}

// FDE #0593 | PC: 0x04e3e0..0x04e418 (56 B) | Symbol: sub_04e3e0
// EN: AArch64 prologue [adrp x10, #0x7e000; mov w8, w0; mov x9, xzr; mov x0, xzr] | VI: Khởi đầu hàm AArch64 [adrp x10, #0x7e000; mov w8, w0; mov x9, xzr; mov x0, xzr]
uint64_t fde_sub_04e3e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A0003E8ULL) << 32) | 0x9000018AULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E3E0ULL;
}

// FDE #0594 | PC: 0x04e418..0x04e4ac (148 B) | Symbol: _Z23transportEnc_GetPCEBits12CHANNEL_MODEii
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04e418(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E418ULL;
}

// FDE #0595 | PC: 0x04e4ac..0x04e808 (860 B) | Symbol: _Z21transportEnc_writeASCP13FDK_BITSTREAMP12CODER_CONFIGP13CSTpCallBacks
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_04e4ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x035CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E4ACULL;
}

// FDE #0596 | PC: 0x04e808..0x04e84c (68 B) | Symbol: sub_04e808
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; subs w20, w1, #0x20] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; subs w20, w1, #0x20]
uint64_t fde_sub_04e808(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E808ULL;
}

// FDE #0597 | PC: 0x04e84c..0x04e8ac (96 B) | Symbol: sub_04e84c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04e84c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E84CULL;
}

// FDE #0598 | PC: 0x04e8ac..0x04ed84 (1240 B) | Symbol: _Z21CreateStreamMuxConfigP11LATM_STREAMP13FDK_BITSTREAMiP13CSTpCallBacks
// EN: AArch64 prologue [mov x4, x30; bl #0x6a160; mov x30, x4; stp x29, x30, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [mov x4, x30; bl #0x6a160; mov x30, x4; stp x29, x30, [sp, #0x80]]
uint64_t fde_sub_04e8ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94006E2CULL) << 32) | 0xAA1E03E4ULL;
    const uint64_t kPcRange = 0x04D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E8ACULL;
}

// FDE #0599 | PC: 0x04ed84..0x04ee18 (148 B) | Symbol: sub_04ed84
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_04ed84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04ED84ULL;
}

// FDE #0600 | PC: 0x04ee18..0x04f044 (556 B) | Symbol: _Z42transportEnc_LatmCountTotalBitDemandHeaderP11LATM_STREAMj
// EN: AArch64 prologue [ldr w9, [x0, #0x2c]; mov w8, wzr; cmp w9, #0xa; b.hi #0x4f038] | VI: Khởi đầu hàm AArch64 [ldr w9, [x0, #0x2c]; mov w8, wzr; cmp w9, #0xa; b.hi #0x4f038]
uint64_t fde_sub_04ee18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E8ULL) << 32) | 0xB9402C09ULL;
    const uint64_t kPcRange = 0x022CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04EE18ULL;
}

// FDE #0601 | PC: 0x04f044..0x04f0fc (184 B) | Symbol: _Z22transportEnc_LatmWriteP11LATM_STREAMP13FDK_BITSTREAMiiP13CSTpCallBacks
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_04f044(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F044ULL;
}

// FDE #0602 | PC: 0x04f0fc..0x04f1f8 (252 B) | Symbol: sub_04f0fc
// EN: AArch64 prologue [mov x5, x30; bl #0x6aba8; mov x30, x5; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x5, x30; bl #0x6aba8; mov x30, x5; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_04f0fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94006EAAULL) << 32) | 0xAA1E03E5ULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F0FCULL;
}

// FDE #0603 | PC: 0x04f1f8..0x04f220 (40 B) | Symbol: _Z35transportEnc_LatmAdjustSubframeBitsP11LATM_STREAMPi
// EN: AArch64 prologue [ldr w8, [x0, #0x50]; ldr w9, [x1]; sub w8, w9, w8; str w8, [x1]] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #0x50]; ldr w9, [x1]; sub w8, w9, w8; str w8, [x1]]
uint64_t fde_sub_04f1f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9400029ULL) << 32) | 0xB9405008ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F1F8ULL;
}

// FDE #0604 | PC: 0x04f220..0x04f304 (228 B) | Symbol: _Z25transportEnc_LatmGetFrameP11LATM_STREAMP13FDK_BITSTREAMPi
// EN: AArch64 prologue [sub sp, sp, #0x70; str x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_04f220(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F5ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F220ULL;
}

// FDE #0605 | PC: 0x04f304..0x04f42c (296 B) | Symbol: _Z22transportEnc_Latm_InitP11LATM_STREAMP13FDK_BITSTREAMP12CODER_CONFIGj14TRANSPORT_TYPEP13CSTpCallBacks
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x2, #0x35]; str x2, [x0, #0x20]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x2, #0x35]; str x2, [x0, #0x20]]
uint64_t fde_sub_04f304(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0128ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F304ULL;
}

// FDE #0606 | PC: 0x04f42c..0x04f438 (12 B) | Symbol: _Z23GetRam_TransportEncoderi
// EN: AArch64 prologue [mov w0, #1; mov w1, #0x138; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #1; mov w1, #0x138; b #0x1a748]
uint64_t fde_sub_04f42c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52802701ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F42CULL;
}

// FDE #0607 | PC: 0x04f438..0x04f440 (8 B) | Symbol: _Z34GetRequiredMemRam_TransportEncoderv
// EN: AArch64 prologue [mov w0, #0x138; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x138; ret]
uint64_t fde_sub_04f438(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52802700ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F438ULL;
}

// FDE #0608 | PC: 0x04f440..0x04f480 (64 B) | Symbol: _Z17transportEnc_OpenPP12TRANSPORTENC
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x4f46c] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x4f46c]
uint64_t fde_sub_04f440(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F440ULL;
}

// FDE #0609 | PC: 0x04f480..0x04f61c (412 B) | Symbol: _Z17transportEnc_InitP12TRANSPORTENCPhi14TRANSPORT_TYPEP12CODER_CONFIGj
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_04f480(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x019CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F480ULL;
}

// FDE #0610 | PC: 0x04f61c..0x04f624 (8 B) | Symbol: _Z25transportEnc_GetBitstreamP12TRANSPORTENC
// EN: AArch64 prologue [add x0, x0, #0x48; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x48; ret]
uint64_t fde_sub_04f61c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x91012000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F61CULL;
}

// FDE #0611 | PC: 0x04f624..0x04f63c (24 B) | Symbol: _Z32transportEnc_RegisterSbrCallbackP12TRANSPORTENCPFiPvP13FDK_BITSTREAMiii17AUDIO_OBJECT_TYPE14MP4_ELEMENT_IDiES1_
// EN: AArch64 prologue [cbz x0, #0x4f638; mov x8, x0; mov w0, wzr; stp x1, x2, [x8, #0x128]] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x4f638; mov x8, x0; mov w0, wzr; stp x1, x2, [x8, #0x128]]
uint64_t fde_sub_04f624(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003E8ULL) << 32) | 0xB40000A0ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F624ULL;
}

// FDE #0612 | PC: 0x04f63c..0x04f84c (528 B) | Symbol: _Z28transportEnc_WriteAccessUnitP12TRANSPORTENCiii
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_04f63c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0210ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F63CULL;
}

// FDE #0613 | PC: 0x04f84c..0x04f8e0 (148 B) | Symbol: _Z26transportEnc_EndAccessUnitP12TRANSPORTENCPi
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0x40]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0x40]]
uint64_t fde_sub_04f84c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F84CULL;
}

// FDE #0614 | PC: 0x04f8e0..0x04f9b4 (212 B) | Symbol: _Z21transportEnc_GetFrameP12TRANSPORTENCPi
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04f8e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F8E0ULL;
}

// FDE #0615 | PC: 0x04f9b4..0x04fa44 (144 B) | Symbol: _Z26transportEnc_GetStaticBitsP12TRANSPORTENCi
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04f9b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F9B4ULL;
}

// FDE #0616 | PC: 0x04fa44..0x04fa58 (20 B) | Symbol: _Z18transportEnc_ClosePP12TRANSPORTENC
// EN: AArch64 prologue [cbz x0, #0x4fa54; ldr x8, [x0]; cbz x8, #0x4fa54; b #0x1c0d8] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x4fa54; ldr x8, [x0]; cbz x8, #0x4fa54; b #0x1c0d8]
uint64_t fde_sub_04fa44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xB4000080ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04FA44ULL;
}

// FDE #0617 | PC: 0x04fa58..0x04fa7c (36 B) | Symbol: _Z24transportEnc_CrcStartRegP12TRANSPORTENCi
// EN: AArch64 prologue [ldr w8, [x0, #0x40]; cmp w8, #2; b.ne #0x4fa78; add x8, x0, #0x90] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #0x40]; cmp w8, #2; b.ne #0x4fa78; add x8, x0, #0x90]
uint64_t fde_sub_04fa58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100091FULL) << 32) | 0xB9404008ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04FA58ULL;
}

// FDE #0618 | PC: 0x04fa7c..0x04faa0 (36 B) | Symbol: _Z22transportEnc_CrcEndRegP12TRANSPORTENCi
// EN: AArch64 prologue [ldr w8, [x0, #0x40]; cmp w8, #2; b.ne #0x4fa9c; add x8, x0, #0x90] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #0x40]; cmp w8, #2; b.ne #0x4fa9c; add x8, x0, #0x90]
uint64_t fde_sub_04fa7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100091FULL) << 32) | 0xB9404008ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04FA7CULL;
}

// FDE #0619 | PC: 0x04faa0..0x04fb10 (112 B) | Symbol: _Z20transportEnc_GetConfP12TRANSPORTENCP12CODER_CONFIGP13FDK_BITSTREAMPj
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; str wzr, [x3]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; str wzr, [x3]]
uint64_t fde_sub_04faa0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04FAA0ULL;
}

// FDE #0620 | PC: 0x04fb10..0x04fb7c (108 B) | Symbol: _Z23transportEnc_GetLibInfoP8LIB_INFO
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x4fb3c] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x4fb3c]
uint64_t fde_sub_04fb10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04FB10ULL;
}

// FDE #0621 | PC: 0x04fb7c..0x04ff04 (904 B) | Symbol: _Z17aliasingReductionPiP13ENV_CALC_NRGSS_i
// EN: AArch64 prologue [sub sp, sp, #0x190; stp x28, x27, [sp, #0x130]; stp x26, x25, [sp, #0x140]; stp x24, x23, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x190; stp x28, x27, [sp, #0x130]; stp x26, x25, [sp, #0x140]; stp x24, x23, [sp, #0x150]]
uint64_t fde_sub_04fb7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9136FFCULL) << 32) | 0xD10643FFULL;
    const uint64_t kPcRange = 0x0388ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04FB7CULL;
}

// FDE #0622 | PC: 0x04ff04..0x04ff68 (100 B) | Symbol: sub_04ff04
// EN: AArch64 prologue [sxtb w8, w1; sub w9, w8, w3, sxtb; cmp w9, #0; cneg w9, w9, mi] | VI: Khởi đầu hàm AArch64 [sxtb w8, w1; sub w9, w8, w3, sxtb; cmp w9, #0; cneg w9, w9, mi]
uint64_t fde_sub_04ff04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4B238109ULL) << 32) | 0x13001C28ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04FF04ULL;
}

// FDE #0623 | PC: 0x04ff68..0x04ffdc (116 B) | Symbol: sub_04ff68
// EN: AArch64 prologue [mov w9, #0x16; clz w8, w2; sub w9, w9, w8; subs w10, w8, #0x16] | VI: Khởi đầu hàm AArch64 [mov w9, #0x16; clz w8, w2; sub w9, w9, w8; subs w10, w8, #0x16]
uint64_t fde_sub_04ff68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5AC01048ULL) << 32) | 0x528002C9ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04FF68ULL;
}

// FDE #0624 | PC: 0x04ffdc..0x051f30 (8020 B) | Symbol: _Z20calculateSbrEnvelopeP16QMF_SCALE_FACTORP22SBR_CALCULATE_ENVELOPEP15SBR_HEADER_DATAP14SBR_FRAME_DATAPPiS8_iS7_ji
// EN: AArch64 prologue [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_04ffdc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940067CEULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x1F54ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04FFDCULL;
}

// FDE #0625 | PC: 0x051f30..0x051f60 (48 B) | Symbol: sub_051f30
// EN: AArch64 prologue [mov w8, wzr; cbz w1, #0x51f4c; ldr w9, [x0], #4; sub w1, w1, #1] | VI: Khởi đầu hàm AArch64 [mov w8, wzr; cbz w1, #0x51f4c; ldr w9, [x0], #4; sub w1, w1, #1]
uint64_t fde_sub_051f30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x340000C1ULL) << 32) | 0x2A1F03E8ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051F30ULL;
}

// FDE #0626 | PC: 0x051f60..0x051ffc (156 B) | Symbol: _Z16maxSubbandSamplePPiS0_iiii
// EN: AArch64 prologue [cmp w3, w2; b.eq #0x51ff4; sxtw x9, w2; sxtw x10, w4] | VI: Khởi đầu hàm AArch64 [cmp w3, w2; b.eq #0x51ff4; sxtw x9, w2; sxtw x10, w4]
uint64_t fde_sub_051f60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000480ULL) << 32) | 0x6B02007FULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051F60ULL;
}

// FDE #0627 | PC: 0x051ffc..0x0520b4 (184 B) | Symbol: sub_051ffc
// EN: AArch64 prologue [ldr w9, [x0]; ldrsb w8, [x1]; cbz w9, #0x52060; clz w10, w9] | VI: Khởi đầu hàm AArch64 [ldr w9, [x0]; ldrsb w8, [x1]; cbz w9, #0x52060; clz w10, w9]
uint64_t fde_sub_051ffc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39C00028ULL) << 32) | 0xB9400009ULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051FFCULL;
}

// FDE #0628 | PC: 0x0520b4..0x052134 (128 B) | Symbol: _Z21rescaleSubbandSamplesPPiS0_iiiii
// EN: AArch64 prologue [mov x7, x30; bl #0x6a250; mov x30, x7; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x7, x30; bl #0x6a250; mov x30, x7; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_0520b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94006066ULL) << 32) | 0xAA1E03E7ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0520B4ULL;
}

// FDE #0629 | PC: 0x052134..0x052184 (80 B) | Symbol: _Z21createSbrEnvelopeCalcP22SBR_CALCULATE_ENVELOPEP15SBR_HEADER_DATAij
// EN: AArch64 prologue [mov x8, xzr; add x9, x0, #0x1c0; cmp x8, #0xc; b.eq #0x52150] | VI: Khởi đầu hàm AArch64 [mov x8, xzr; add x9, x0, #0x1c0; cmp x8, #0xc; b.eq #0x52150]
uint64_t fde_sub_052134(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91070009ULL) << 32) | 0xAA1F03E8ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052134ULL;
}

// FDE #0630 | PC: 0x052184..0x05219c (24 B) | Symbol: _Z20resetSbrEnvelopeCalcP22SBR_CALCULATE_ENVELOPE
// EN: AArch64 prologue [adrp x8, #0x6c000; ldr d0, [x8, #0x938]; add x8, x0, #0x1b4; strb wzr, [x0, #0x1b0]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x6c000; ldr d0, [x8, #0x938]; add x8, x0, #0x1b4; strb wzr, [x0, #0x1b0]]
uint64_t fde_sub_052184(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD449D00ULL) << 32) | 0xD00000C8ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052184ULL;
}

// FDE #0631 | PC: 0x05219c..0x0521a0 (4 B) | Symbol: _Z21deleteSbrEnvelopeCalcP22SBR_CALCULATE_ENVELOPE
// EN: AArch64 prologue [b #0x6a02c] | VI: Khởi đầu hàm AArch64 [b #0x6a02c]
uint64_t fde_sub_05219c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E7ULL) << 32) | 0x14005FA4ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05219CULL;
}

// FDE #0632 | PC: 0x0521a0..0x05241c (636 B) | Symbol: _Z17ResetLimiterBandsPhS_S_iPK11PATCH_PARAMii
// EN: AArch64 prologue [mov x7, x30; bl #0x6a8c0; mov x30, x7; stp x29, x30, [sp, #0xd0]] | VI: Khởi đầu hàm AArch64 [mov x7, x30; bl #0x6a8c0; mov x30, x7; stp x29, x30, [sp, #0xd0]]
uint64_t fde_sub_0521a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940061C7ULL) << 32) | 0xAA1E03E7ULL;
    const uint64_t kPcRange = 0x027CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0521A0ULL;
}

// FDE #0633 | PC: 0x05241c..0x052650 (564 B) | Symbol: _Z13decodeSbrDataP15SBR_HEADER_DATAP14SBR_FRAME_DATAP19SBR_PREV_FRAME_DATAS2_S4_
// EN: AArch64 prologue [mov x5, x30; bl #0x6a894; mov x30, x5; stp x29, x30, [sp, #0xe0]] | VI: Khởi đầu hàm AArch64 [mov x5, x30; bl #0x6a894; mov x30, x5; stp x29, x30, [sp, #0xe0]]
uint64_t fde_sub_05241c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400611DULL) << 32) | 0xAA1E03E5ULL;
    const uint64_t kPcRange = 0x0234ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05241CULL;
}

// FDE #0634 | PC: 0x052650..0x052a0c (956 B) | Symbol: sub_052650
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x24, x23, [sp, #0x70]; stp x22, x21, [sp, #0x80]; stp x20, x19, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x24, x23, [sp, #0x70]; stp x22, x21, [sp, #0x80]; stp x20, x19, [sp, #0x90]]
uint64_t fde_sub_052650(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9075FF8ULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x03BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052650ULL;
}

// FDE #0635 | PC: 0x052a0c..0x052b84 (376 B) | Symbol: sub_052a0c
// EN: AArch64 prologue [ldrb w9, [x1, #0x1b]; ldrb w8, [x1, #0x12]; cbz w9, #0x52a44; and x9, x0, #0xff] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x1, #0x1b]; ldrb w8, [x1, #0x12]; cbz w9, #0x52a44; and x9, x0, #0xff]
uint64_t fde_sub_052a0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39404828ULL) << 32) | 0x39406C29ULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052A0CULL;
}

// FDE #0636 | PC: 0x052b84..0x052bfc (120 B) | Symbol: sub_052b84
// EN: AArch64 prologue [sxtb w8, w1; mov w9, #1; sub w8, w8, #1; sub w9, w9, w1, sxtb] | VI: Khởi đầu hàm AArch64 [sxtb w8, w1; mov w9, #1; sub w8, w8, #1; sub w9, w9, w1, sxtb]
uint64_t fde_sub_052b84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800029ULL) << 32) | 0x13001C28ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052B84ULL;
}

// FDE #0637 | PC: 0x052bfc..0x052c7c (128 B) | Symbol: sub_052bfc
// EN: AArch64 prologue [sbfiz w8, w2, #0x10, #0x10; mov w10, #6; sxth w9, w2; clz w8, w8] | VI: Khởi đầu hàm AArch64 [sbfiz w8, w2, #0x10, #0x10; mov w10, #6; sxth w9, w2; clz w8, w8]
uint64_t fde_sub_052bfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x528000CAULL) << 32) | 0x13103C48ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052BFCULL;
}

// FDE #0638 | PC: 0x052c7c..0x052d80 (260 B) | Symbol: sub_052c7c
// EN: AArch64 prologue [mov x3, x30; bl #0x69f4c; mov x30, x3; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x69f4c; mov x30, x3; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_052c7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94005CB3ULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052C7CULL;
}

// FDE #0639 | PC: 0x052d80..0x052ddc (92 B) | Symbol: sub_052d80
// EN: AArch64 prologue [cbnz w4, #0x52dd4; tbnz w2, #0x1f, #0x52d94; cmp w3, w2; b.ge #0x52dbc] | VI: Khởi đầu hàm AArch64 [cbnz w4, #0x52dd4; tbnz w2, #0x1f, #0x52d94; cmp w3, w2; b.ge #0x52dbc]
uint64_t fde_sub_052d80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x37F80082ULL) << 32) | 0x350002A4ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052D80ULL;
}

// FDE #0640 | PC: 0x052ddc..0x052e9c (192 B) | Symbol: _Z14initHeaderDataP15SBR_HEADER_DATAiiij
// EN: AArch64 prologue [cmp w1, w2; b.ne #0x52df0; lsl w8, w1, #1; str w8, [x0, #0xc]] | VI: Khởi đầu hàm AArch64 [cmp w1, w2; b.ne #0x52df0; lsl w8, w1, #1; str w8, [x0, #0xc]]
uint64_t fde_sub_052ddc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000081ULL) << 32) | 0x6B02003FULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052DDCULL;
}

// FDE #0641 | PC: 0x052e9c..0x052efc (96 B) | Symbol: _Z20initSbrPrevFrameDataP19SBR_PREV_FRAME_DATAi
// EN: AArch64 prologue [mov x8, xzr; cmp x8, #0x60; b.eq #0x52eb4; strh wzr, [x0, x8]] | VI: Khởi đầu hàm AArch64 [mov x8, xzr; cmp x8, #0x60; b.eq #0x52eb4; strh wzr, [x0, x8]]
uint64_t fde_sub_052e9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF101811FULL) << 32) | 0xAA1F03E8ULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052E9CULL;
}

// FDE #0642 | PC: 0x052efc..0x053064 (360 B) | Symbol: _Z16sbrGetHeaderDataP15SBR_HEADER_DATAP13FDK_BITSTREAMji
// EN: AArch64 prologue [mov x2, x30; bl #0x69f18; mov x30, x2; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x69f18; mov x30, x2; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_052efc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94005C06ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0168ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052EFCULL;
}

// FDE #0643 | PC: 0x053064..0x0530e8 (132 B) | Symbol: _Z24sbrGetSyntheticCodedDataP15SBR_HEADER_DATAP14SBR_FRAME_DATAP13FDK_BITSTREAM
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_053064(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053064ULL;
}

// FDE #0644 | PC: 0x0530e8..0x0531e4 (252 B) | Symbol: _Z26sbrGetSingleChannelElementP15SBR_HEADER_DATAP14SBR_FRAME_DATAP13FDK_BITSTREAMP6PS_DECji
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0530e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0530E8ULL;
}

// FDE #0645 | PC: 0x0531e4..0x053808 (1572 B) | Symbol: sub_0531e4
// EN: AArch64 prologue [mov x4, x30; bl #0x69f4c; mov x30, x4; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x4, x30; bl #0x69f4c; mov x30, x4; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_0531e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94005B59ULL) << 32) | 0xAA1E03E4ULL;
    const uint64_t kPcRange = 0x0624ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0531E4ULL;
}

// FDE #0646 | PC: 0x053808..0x05393c (308 B) | Symbol: sub_053808
// EN: AArch64 prologue [ldrb w9, [x0, #1]; ldrb w10, [x0, #0xe]; sub w8, w9, #1; cmp w8, #4] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x0, #1]; ldrb w10, [x0, #0xe]; sub w8, w9, #1; cmp w8, #4]
uint64_t fde_sub_053808(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3940380AULL) << 32) | 0x39400409ULL;
    const uint64_t kPcRange = 0x0134ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053808ULL;
}

// FDE #0647 | PC: 0x05393c..0x0539ac (112 B) | Symbol: sub_05393c
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05393c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05393CULL;
}

// FDE #0648 | PC: 0x0539ac..0x053bb0 (516 B) | Symbol: sub_0539ac
// EN: AArch64 prologue [mov x4, x30; bl #0x69f8c; mov x30, x4; stp x29, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [mov x4, x30; bl #0x69f8c; mov x30, x4; stp x29, x30, [sp, #0x90]]
uint64_t fde_sub_0539ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94005977ULL) << 32) | 0xAA1E03E4ULL;
    const uint64_t kPcRange = 0x0204ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0539ACULL;
}

// FDE #0649 | PC: 0x053bb0..0x053cbc (268 B) | Symbol: sub_053bb0
// EN: AArch64 prologue [mov x3, x30; bl #0x69f4c; mov x30, x3; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x69f4c; mov x30, x3; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_053bb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940058E6ULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053BB0ULL;
}

// FDE #0650 | PC: 0x053cbc..0x053dd0 (276 B) | Symbol: sub_053cbc
// EN: AArch64 prologue [mov x2, x30; bl #0x6a250; mov x30, x2; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x6a250; mov x30, x2; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_053cbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94005964ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053CBCULL;
}

// FDE #0651 | PC: 0x053dd0..0x053fb8 (488 B) | Symbol: _Z24sbrGetChannelPairElementP15SBR_HEADER_DATAP14SBR_FRAME_DATAS2_P13FDK_BITSTREAMji
// EN: AArch64 prologue [mov x6, x30; bl #0x6a250; mov x30, x6; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x6, x30; bl #0x6a250; mov x30, x6; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_053dd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400591FULL) << 32) | 0xAA1E03E6ULL;
    const uint64_t kPcRange = 0x01E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053DD0ULL;
}

// FDE #0652 | PC: 0x053fb8..0x054000 (72 B) | Symbol: _Z15DecodeHuffmanCWPA2_KaP13FDK_BITSTREAM
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_053fb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053FB8ULL;
}

// FDE #0653 | PC: 0x054000..0x054d98 (3480 B) | Symbol: _Z13lppTransposerP13SBR_LPP_TRANSP16QMF_SCALE_FACTORPPiS3_S4_iiiiiP9INVF_MODES6_
// EN: AArch64 prologue [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_054000(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940057C5ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x0D98ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054000ULL;
}

// FDE #0654 | PC: 0x054d98..0x054df8 (96 B) | Symbol: _Z19createLppTransposerP13SBR_LPP_TRANSP19TRANSPOSER_SETTINGSiPhiiiiS3_ijii
// EN: AArch64 prologue [mov w10, w5; ldr w11, [sp, #0x18]; ldr w8, [sp, #0x10]; ldr w5, [sp, #8]] | VI: Khởi đầu hàm AArch64 [mov w10, w5; ldr w11, [sp, #0x18]; ldr w8, [sp, #0x10]; ldr w5, [sp, #8]]
uint64_t fde_sub_054d98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9401BEBULL) << 32) | 0x2A0503EAULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054D98ULL;
}

// FDE #0655 | PC: 0x054df8..0x055054 (604 B) | Symbol: _Z18resetLppTransposerP13SBR_LPP_TRANShPhhS1_hhj
// EN: AArch64 prologue [mov x8, x30; bl #0x6a084; mov x30, x8; stp x29, x30, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x6a084; mov x30, x8; stp x29, x30, [sp, #0x70]]
uint64_t fde_sub_054df8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940054A2ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x025CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054DF8ULL;
}

// FDE #0656 | PC: 0x055054..0x0550c4 (112 B) | Symbol: sub_055054
// EN: AArch64 prologue [ldrb w8, [x1]; cmp w8, w0, uxtb; b.hs #0x550c0; and x9, x2, #0xff] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x1]; cmp w8, w0, uxtb; b.hs #0x550c0; and x9, x2, #0xff]
uint64_t fde_sub_055054(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6B20011FULL) << 32) | 0x39400028ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055054ULL;
}

// FDE #0657 | PC: 0x0550c4..0x055600 (1340 B) | Symbol: _Z8DecodePsP6PS_DECh
// EN: AArch64 prologue [mov x2, x30; bl #0x69f8c; mov x30, x2; stp x29, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x69f8c; mov x30, x2; stp x29, x30, [sp, #0x90]]
uint64_t fde_sub_0550c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940053B1ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x053CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0550C4ULL;
}

// FDE #0658 | PC: 0x055600..0x055700 (256 B) | Symbol: sub_055600
// EN: AArch64 prologue [mov x9, x30; bl #0x6aef0; mov x30, x9; b.ne #0x5565c] | VI: Khởi đầu hàm AArch64 [mov x9, x30; bl #0x6aef0; mov x30, x9; b.ne #0x5565c]
uint64_t fde_sub_055600(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400563BULL) << 32) | 0xAA1E03E9ULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055600ULL;
}

// FDE #0659 | PC: 0x055700..0x055860 (352 B) | Symbol: sub_055700
// EN: AArch64 prologue [ldrsb w8, [x0]; ldrsb w9, [x0, #1]; ldrsb w10, [x0, #2]; ldrsb w11, [x0, #3]] | VI: Khởi đầu hàm AArch64 [ldrsb w8, [x0]; ldrsb w9, [x0, #1]; ldrsb w10, [x0, #2]; ldrsb w11, [x0, #3]]
uint64_t fde_sub_055700(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39C00409ULL) << 32) | 0x39C00008ULL;
    const uint64_t kPcRange = 0x0160ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055700ULL;
}

// FDE #0660 | PC: 0x055860..0x055c40 (992 B) | Symbol: _Z10ReadPsDataP6PS_DECP13FDK_BITSTREAMi
// EN: AArch64 prologue [cbz x0, #0x55c3c; mov x3, x30; bl #0x6a084; mov x30, x3] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x55c3c; mov x3, x30; bl #0x6a084; mov x30, x3]
uint64_t fde_sub_055860(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E3ULL) << 32) | 0xB4001EE0ULL;
    const uint64_t kPcRange = 0x03E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055860ULL;
}

// FDE #0661 | PC: 0x055c40..0x055c8c (76 B) | Symbol: sub_055c40
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_055c40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055C40ULL;
}

// FDE #0662 | PC: 0x055c8c..0x055d78 (236 B) | Symbol: _Z11CreatePsDecPP6PS_DECi
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_055c8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055C8CULL;
}

// FDE #0663 | PC: 0x055d78..0x055ea8 (304 B) | Symbol: _Z10ResetPsDecP6PS_DEC
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_055d78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055D78ULL;
}

// FDE #0664 | PC: 0x055ea8..0x055f4c (164 B) | Symbol: _Z12ResetPsDeCorP6PS_DEC
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_055ea8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055EA8ULL;
}

// FDE #0665 | PC: 0x055f4c..0x055f74 (40 B) | Symbol: _Z11DeletePsDecPP6PS_DEC
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0]; cbz x8, #0x55f68] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0]; cbz x8, #0x55f68]
uint64_t fde_sub_055f4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055F4CULL;
}

// FDE #0666 | PC: 0x055f74..0x0563fc (1160 B) | Symbol: _Z20scalFilterBankValuesP6PS_DECPPiS2_iiiPaS3_iS1_i
// EN: AArch64 prologue [mov x8, x30; bl #0x69f8c; mov x30, x8; stp x29, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x69f8c; mov x30, x8; stp x29, x30, [sp, #0x90]]
uint64_t fde_sub_055f74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94005005ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x0488ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055F74ULL;
}

// FDE #0667 | PC: 0x0563fc..0x05644c (80 B) | Symbol: _Z22rescalFilterBankValuesP6PS_DECPPiS2_ii
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0563fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0563FCULL;
}

// FDE #0668 | PC: 0x05644c..0x05677c (816 B) | Symbol: _Z21initSlotBasedRotationP6PS_DECii
// EN: AArch64 prologue [mov x3, x30; bl #0x6a084; mov x30, x3; stp x29, x30, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x6a084; mov x30, x3; stp x29, x30, [sp, #0x70]]
uint64_t fde_sub_05644c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94004F0DULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x0330ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05644CULL;
}

// FDE #0669 | PC: 0x05677c..0x056820 (164 B) | Symbol: sub_05677c
// EN: AArch64 prologue [mov w8, #0x60dc; movk w8, #0x28be, lsl #16; smull x8, w0, w8; mov w9, #0xed51] | VI: Khởi đầu hàm AArch64 [mov w8, #0x60dc; movk w8, #0x28be, lsl #16; smull x8, w0, w8; mov w9, #0xed51]
uint64_t fde_sub_05677c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72A517C8ULL) << 32) | 0x528C1B88ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05677CULL;
}

// FDE #0670 | PC: 0x056820..0x057308 (2792 B) | Symbol: _Z11ApplyPsSlotP6PS_DECPPiS2_S1_S1_
// EN: AArch64 prologue [mov x5, x30; bl #0x69f18; mov x30, x5; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x5, x30; bl #0x69f18; mov x30, x5; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_056820(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94004DBDULL) << 32) | 0xAA1E03E5ULL;
    const uint64_t kPcRange = 0x0AE8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056820ULL;
}

// FDE #0671 | PC: 0x057308..0x057344 (60 B) | Symbol: _Z20InitHybridFilterBankP6HYBRIDaaPKh
// EN: AArch64 prologue [mov x8, xzr; sxtb x9, w2; add x10, x0, #3; cmp x8, x9] | VI: Khởi đầu hàm AArch64 [mov x8, xzr; sxtb x9, w2; add x10, x0, #3; cmp x8, x9]
uint64_t fde_sub_057308(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x93401C49ULL) << 32) | 0xAA1F03E8ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057308ULL;
}

// FDE #0672 | PC: 0x057344..0x0573cc (136 B) | Symbol: _Z19fillHybridDelayLinePPiS0_S_S_S_S_P6HYBRID
// EN: AArch64 prologue [mov x1, x30; bl #0x6a250; mov x30, x1; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x1, x30; bl #0x6a250; mov x30, x1; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_057344(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94004BC2ULL) << 32) | 0xAA1E03E1ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057344ULL;
}

// FDE #0673 | PC: 0x0573cc..0x057bd8 (2060 B) | Symbol: _Z23slotBasedHybridAnalysisPiS_S_S_P6HYBRID
// EN: AArch64 prologue [mov x5, x30; bl #0x69f18; mov x30, x5; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x5, x30; bl #0x69f18; mov x30, x5; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_0573cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94004AD2ULL) << 32) | 0xAA1E03E5ULL;
    const uint64_t kPcRange = 0x080CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0573CCULL;
}

// FDE #0674 | PC: 0x057bd8..0x057c40 (104 B) | Symbol: _Z24slotBasedHybridSynthesisPiS_S_S_P6HYBRID
// EN: AArch64 prologue [ldrsb x9, [x4]; mov x8, xzr; mov w10, wzr; cmp x8, x9] | VI: Khởi đầu hàm AArch64 [ldrsb x9, [x4]; mov x8, xzr; mov w10, wzr; cmp x8, x9]
uint64_t fde_sub_057bd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E8ULL) << 32) | 0x39800089ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057BD8ULL;
}

// FDE #0675 | PC: 0x057c40..0x057cf8 (184 B) | Symbol: _Z11SbrCrcCheckP13FDK_BITSTREAMi
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_057c40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057C40ULL;
}

// FDE #0676 | PC: 0x057cf8..0x057d58 (96 B) | Symbol: sub_057cf8
// EN: AArch64 prologue [sub w9, w2, #1; mov w10, #1; mov w8, wzr; lsl x9, x10, x9] | VI: Khởi đầu hàm AArch64 [sub w9, w2, #1; mov w10, #1; mov w8, wzr; lsl x9, x10, x9]
uint64_t fde_sub_057cf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5280002AULL) << 32) | 0x51000449ULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057CF8ULL;
}

// FDE #0677 | PC: 0x057d58..0x05865c (2308 B) | Symbol: _Z7sbr_decP7SBR_DECPsS1_S0_S1_iiP15SBR_HEADER_DATAP14SBR_FRAME_DATAP19SBR_PREV_FRAME_DATAiP6PS_DECji
// EN: AArch64 prologue [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_057d58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400486FULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x0904ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057D58ULL;
}

// FDE #0678 | PC: 0x05865c..0x05876c (272 B) | Symbol: sub_05865c
// EN: AArch64 prologue [ldr w8, [x0, #0x94]; str w2, [x0, #0xa70]; cbz w2, #0x586bc; ldr w9, [x0, #0x44]] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #0x94]; str w2, [x0, #0xa70]; cbz w2, #0x586bc; ldr w9, [x0, #0x44]]
uint64_t fde_sub_05865c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB90A7002ULL) << 32) | 0xB9409408ULL;
    const uint64_t kPcRange = 0x0110ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05865CULL;
}

// FDE #0679 | PC: 0x05876c..0x0588f4 (392 B) | Symbol: _Z12createSbrDecP11SBR_CHANNELP15SBR_HEADER_DATAP19TRANSPOSER_SETTINGSijjii
// EN: AArch64 prologue [mov x8, x30; bl #0x6a160; mov x30, x8; stp x29, x30, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x6a160; mov x30, x8; stp x29, x30, [sp, #0x80]]
uint64_t fde_sub_05876c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400467CULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x0188ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05876CULL;
}

// FDE #0680 | PC: 0x0588f4..0x058930 (60 B) | Symbol: _Z12deleteSbrDecP11SBR_CHANNEL
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0xd50]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0xd50]]
uint64_t fde_sub_0588f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0588F4ULL;
}

// FDE #0681 | PC: 0x058930..0x058c50 (800 B) | Symbol: _Z11resetSbrDecP7SBR_DECP15SBR_HEADER_DATAP19SBR_PREV_FRAME_DATAii
// EN: AArch64 prologue [mov x4, x30; bl #0x69f8c; mov x30, x4; stp x29, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [mov x4, x30; bl #0x69f8c; mov x30, x4; stp x29, x30, [sp, #0x90]]
uint64_t fde_sub_058930(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94004596ULL) << 32) | 0xAA1E03E4ULL;
    const uint64_t kPcRange = 0x0320ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058930ULL;
}

// FDE #0682 | PC: 0x058c50..0x058c5c (12 B) | Symbol: _Z17GetRam_SbrDecoderi
// EN: AArch64 prologue [mov w0, #1; mov w1, #0xd78; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #1; mov w1, #0xd78; b #0x1a748]
uint64_t fde_sub_058c50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5281AF01ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058C50ULL;
}

// FDE #0683 | PC: 0x058c5c..0x058c64 (8 B) | Symbol: _Z28GetRequiredMemRam_SbrDecoderv
// EN: AArch64 prologue [mov w0, #0xd78; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0xd78; ret]
uint64_t fde_sub_058c5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x5281AF00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058C5CULL;
}

// FDE #0684 | PC: 0x058c64..0x058c70 (12 B) | Symbol: _Z20GetRam_SbrDecElementi
// EN: AArch64 prologue [mov w0, #1; mov w1, #0x78; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #1; mov w1, #0x78; b #0x1a748]
uint64_t fde_sub_058c64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800F01ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058C64ULL;
}

// FDE #0685 | PC: 0x058c70..0x058c78 (8 B) | Symbol: _Z31GetRequiredMemRam_SbrDecElementv
// EN: AArch64 prologue [mov w0, #0x3c0; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x3c0; ret]
uint64_t fde_sub_058c70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52807800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058C70ULL;
}

// FDE #0686 | PC: 0x058c78..0x058c84 (12 B) | Symbol: _Z20GetRam_SbrDecChanneli
// EN: AArch64 prologue [mov w0, #1; mov w1, #0x1198; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #1; mov w1, #0x1198; b #0x1a748]
uint64_t fde_sub_058c78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52823301ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058C78ULL;
}

// FDE #0687 | PC: 0x058c84..0x058c8c (8 B) | Symbol: _Z31GetRequiredMemRam_SbrDecChannelv
// EN: AArch64 prologue [mov w0, #0x9e58; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x9e58; ret]
uint64_t fde_sub_058c84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x5293CB00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058C84ULL;
}

// FDE #0688 | PC: 0x058c8c..0x058c94 (8 B) | Symbol: _Z29GetRam_sbr_QmfStatesSynthesisi
// EN: AArch64 prologue [mov w0, #0x900; b #0x6ad94] | VI: Khởi đầu hàm AArch64 [mov w0, #0x900; b #0x6ad94]
uint64_t fde_sub_058c8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14004841ULL) << 32) | 0x52812000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058C8CULL;
}

// FDE #0689 | PC: 0x058c94..0x058c9c (8 B) | Symbol: _Z40GetRequiredMemRam_sbr_QmfStatesSynthesisv
// EN: AArch64 prologue [mov w0, #0x5190; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x5190; ret]
uint64_t fde_sub_058c94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x528A3200ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058C94ULL;
}

// FDE #0690 | PC: 0x058c9c..0x058ca4 (8 B) | Symbol: _Z24GetRam_sbr_OverlapBufferi
// EN: AArch64 prologue [mov w0, #0xc00; b #0x6c88c] | VI: Khởi đầu hàm AArch64 [mov w0, #0xc00; b #0x6c88c]
uint64_t fde_sub_058c9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14004EFBULL) << 32) | 0x52818000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058C9CULL;
}

// FDE #0691 | PC: 0x058ca4..0x058cac (8 B) | Symbol: _Z35GetRequiredMemRam_sbr_OverlapBufferv
// EN: AArch64 prologue [mov w0, #0x6c90; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x6c90; ret]
uint64_t fde_sub_058ca4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x528D9200ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058CA4ULL;
}

// FDE #0692 | PC: 0x058cac..0x058cb8 (12 B) | Symbol: _Z13GetRam_ps_deci
// EN: AArch64 prologue [mov w0, #1; mov w1, #0x2188; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #1; mov w1, #0x2188; b #0x1a748]
uint64_t fde_sub_058cac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52843101ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058CACULL;
}

// FDE #0693 | PC: 0x058cb8..0x058cc0 (8 B) | Symbol: _Z24GetRequiredMemRam_ps_decv
// EN: AArch64 prologue [mov w0, #0x2188; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x2188; ret]
uint64_t fde_sub_058cb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52843100ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058CB8ULL;
}

// FDE #0694 | PC: 0x058cc0..0x058d20 (96 B) | Symbol: _Z25sbrDecoder_drcInitChannelP18SBRDEC_DRC_CHANNEL
// EN: AArch64 prologue [cbz x0, #0x58d1c; mov x9, xzr; add x8, x0, #0x184; mov w10, #0x40000000] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x58d1c; mov x9, xzr; add x8, x0, #0x184; mov w10, #0x40000000]
uint64_t fde_sub_058cc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E9ULL) << 32) | 0xB40002E0ULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058CC0ULL;
}

// FDE #0695 | PC: 0x058d20..0x058d88 (104 B) | Symbol: _Z27sbrDecoder_drcUpdateChannelP18SBRDEC_DRC_CHANNEL
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x58d80] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x58d80]
uint64_t fde_sub_058d20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058D20ULL;
}

// FDE #0696 | PC: 0x058d88..0x059234 (1196 B) | Symbol: _Z23sbrDecoder_drcApplySlotP18SBRDEC_DRC_CHANNELPiS1_iii
// EN: AArch64 prologue [mov x6, x30; bl #0x69f4c; mov x30, x6; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x6, x30; bl #0x69f4c; mov x30, x6; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_058d88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94004470ULL) << 32) | 0xAA1E03E6ULL;
    const uint64_t kPcRange = 0x04ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058D88ULL;
}

// FDE #0697 | PC: 0x059234..0x0592d0 (156 B) | Symbol: _Z19sbrDecoder_drcApplyP18SBRDEC_DRC_CHANNELPPiS2_iS1_
// EN: AArch64 prologue [mov x5, x30; bl #0x6aba8; mov x30, x5; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x5, x30; bl #0x6aba8; mov x30, x5; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_059234(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400465CULL) << 32) | 0xAA1E03E5ULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059234ULL;
}

// FDE #0698 | PC: 0x0592d0..0x059754 (1156 B) | Symbol: _Z21sbrdecUpdateFreqScalePhS_jP15SBR_HEADER_DATAj
// EN: AArch64 prologue [mov x5, x30; bl #0x6a86c; mov x30, x5; stp x29, x30, [sp, #0x110]] | VI: Khởi đầu hàm AArch64 [mov x5, x30; bl #0x6a86c; mov x30, x5; stp x29, x30, [sp, #0x110]]
uint64_t fde_sub_0592d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94004566ULL) << 32) | 0xAA1E03E5ULL;
    const uint64_t kPcRange = 0x0484ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0592D0ULL;
}

// FDE #0699 | PC: 0x059754..0x059834 (224 B) | Symbol: sub_059754
// EN: AArch64 prologue [and w8, w2, #0xff; mov w12, wzr; and w9, w3, #0xff; lsl w10, w1, #0x18] | VI: Khởi đầu hàm AArch64 [and w8, w2, #0xff; mov w12, wzr; and w9, w3, #0xff; lsl w10, w1, #0x18]
uint64_t fde_sub_059754(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03ECULL) << 32) | 0x12001C48ULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059754ULL;
}

// FDE #0700 | PC: 0x059834..0x0598c0 (140 B) | Symbol: _Z9shellsortPhh
// EN: AArch64 prologue [and w9, w1, #0xff; mov w8, #1; add w8, w8, w8, lsl #1; cmp w8, w9] | VI: Khởi đầu hàm AArch64 [and w9, w1, #0xff; mov w8, #1; add w8, w8, w8, lsl #1; cmp w8, w9]
uint64_t fde_sub_059834(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800028ULL) << 32) | 0x12001C29ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059834ULL;
}

// FDE #0701 | PC: 0x0598c0..0x0598e4 (36 B) | Symbol: sub_0598c0
// EN: AArch64 prologue [and x8, x2, #0xff; strb w0, [x3], #1; cbz x8, #0x598e0; ldrb w9, [x1], #1] | VI: Khởi đầu hàm AArch64 [and x8, x2, #0xff; strb w0, [x3], #1; cbz x8, #0x598e0; ldrb w9, [x1], #1]
uint64_t fde_sub_0598c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x38001460ULL) << 32) | 0x92401C48ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0598C0ULL;
}

// FDE #0702 | PC: 0x0598e4..0x059948 (100 B) | Symbol: sub_0598e4
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w20, w0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w20, w0]
uint64_t fde_sub_0598e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0598E4ULL;
}

// FDE #0703 | PC: 0x059948..0x05998c (68 B) | Symbol: sub_059948
// EN: AArch64 prologue [sub w8, w1, #1; adrp x9, #0x7e000; cmp w8, #0xbf; add x9, x9, #0xa84] | VI: Khởi đầu hàm AArch64 [sub w8, w1, #1; adrp x9, #0x7e000; cmp w8, #0xbf; add x9, x9, #0xa84]
uint64_t fde_sub_059948(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000129ULL) << 32) | 0x51000428ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059948ULL;
}

// FDE #0704 | PC: 0x05998c..0x059a18 (140 B) | Symbol: _Z21sbrdecDownSampleLoResPhhS_h
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x29, x30, [sp, #0x70]; add x29, sp, #0x70; mrs x8, tpidr_el0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x29, x30, [sp, #0x70]; add x29, sp, #0x70; mrs x8, tpidr_el0]
uint64_t fde_sub_05998c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9077BFDULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05998CULL;
}

// FDE #0705 | PC: 0x059a18..0x059b8c (372 B) | Symbol: _Z19resetFreqBandTablesP15SBR_HEADER_DATAj
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_059a18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0174ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059A18ULL;
}

// FDE #0706 | PC: 0x059b8c..0x059bf0 (100 B) | Symbol: sbrDecoder_Open
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_059b8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059B8CULL;
}

// FDE #0707 | PC: 0x059bf0..0x059fe4 (1012 B) | Symbol: sbrDecoder_InitElement
// EN: AArch64 prologue [mov x7, x30; bl #0x69f4c; mov x30, x7; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x7, x30; bl #0x69f4c; mov x30, x7; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_059bf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940040D6ULL) << 32) | 0xAA1E03E7ULL;
    const uint64_t kPcRange = 0x03F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059BF0ULL;
}

// FDE #0708 | PC: 0x059fe4..0x05a024 (64 B) | Symbol: sub_059fe4
// EN: AArch64 prologue [mov w8, w0; cmp w0, #0x27; mov w0, #1; b.hi #0x5a018] | VI: Khởi đầu hàm AArch64 [mov w8, w0; cmp w0, #0x27; mov w0, #1; b.hi #0x5a018]
uint64_t fde_sub_059fe4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x71009C1FULL) << 32) | 0x2A0003E8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059FE4ULL;
}

// FDE #0709 | PC: 0x05a024..0x05a09c (120 B) | Symbol: sub_05a024
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05a024(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A024ULL;
}

// FDE #0710 | PC: 0x05a09c..0x05a1b0 (276 B) | Symbol: sbrDecoder_Header
// EN: AArch64 prologue [mov x8, x30; bl #0x6aba8; mov x30, x8; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x6aba8; mov x30, x8; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_05a09c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940042C2ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A09CULL;
}

// FDE #0711 | PC: 0x05a1b0..0x05a224 (116 B) | Symbol: sub_05a1b0
// EN: AArch64 prologue [and x8, x0, #0xff; ldrb w0, [x1, x8]; mov x8, xzr; cmp x8, #2] | VI: Khởi đầu hàm AArch64 [and x8, x0, #0xff; ldrb w0, [x1, x8]; mov x8, xzr; cmp x8, #2]
uint64_t fde_sub_05a1b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x38686820ULL) << 32) | 0x92401C08ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A1B0ULL;
}

// FDE #0712 | PC: 0x05a224..0x05a278 (84 B) | Symbol: sub_05a224
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1]
uint64_t fde_sub_05a224(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A224ULL;
}

// FDE #0713 | PC: 0x05a278..0x05a3b0 (312 B) | Symbol: sbrDecoder_SetParam
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_05a278(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0138ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A278ULL;
}

// FDE #0714 | PC: 0x05a3b0..0x05a4cc (284 B) | Symbol: sbrDecoder_drcFeedChannel
// EN: AArch64 prologue [mov x8, x30; bl #0x6a250; mov x30, x8; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x6a250; mov x30, x8; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_05a3b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94003FA7ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A3B0ULL;
}

// FDE #0715 | PC: 0x05a4cc..0x05a58c (192 B) | Symbol: sub_05a4cc
// EN: AArch64 prologue [adrp x11, #0x6c000; mov x8, xzr; mov w10, wzr; mov w9, wzr] | VI: Khởi đầu hàm AArch64 [adrp x11, #0x6c000; mov x8, xzr; mov w10, wzr; mov w9, wzr]
uint64_t fde_sub_05a4cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E8ULL) << 32) | 0xD000008BULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A4CCULL;
}

// FDE #0716 | PC: 0x05a58c..0x05a5c8 (60 B) | Symbol: sbrDecoder_drcDisable
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; cbz x0, #0x5a5c0; cmp w1, #8] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; cbz x0, #0x5a5c0; cmp w1, #8]
uint64_t fde_sub_05a58c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A58CULL;
}

// FDE #0717 | PC: 0x05a5c8..0x05ae08 (2112 B) | Symbol: sbrDecoder_Parse
// EN: AArch64 prologue [mov x7, x30; bl #0x6a86c; mov x30, x7; stp x29, x30, [sp, #0x110]] | VI: Khởi đầu hàm AArch64 [mov x7, x30; bl #0x6a86c; mov x30, x7; stp x29, x30, [sp, #0x110]]
uint64_t fde_sub_05a5c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940040A8ULL) << 32) | 0xAA1E03E7ULL;
    const uint64_t kPcRange = 0x0840ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A5C8ULL;
}

// FDE #0718 | PC: 0x05ae08..0x05b3f0 (1512 B) | Symbol: sbrDecoder_Apply
// EN: AArch64 prologue [sub sp, sp, #0x110; stp x28, x27, [sp, #0xb0]; stp x26, x25, [sp, #0xc0]; stp x24, x23, [sp, #0xd0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; stp x28, x27, [sp, #0xb0]; stp x26, x25, [sp, #0xc0]; stp x24, x23, [sp, #0xd0]]
uint64_t fde_sub_05ae08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90B6FFCULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x05E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AE08ULL;
}

// FDE #0719 | PC: 0x05b3f0..0x05b474 (132 B) | Symbol: sbrDecoder_Close
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05b3f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B3F0ULL;
}

// FDE #0720 | PC: 0x05b474..0x05b4ec (120 B) | Symbol: sbrDecoder_GetLibInfo
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x5b4a0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x5b4a0]
uint64_t fde_sub_05b474(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B474ULL;
}

// FDE #0721 | PC: 0x05b4ec..0x05b570 (132 B) | Symbol: sbrDecoder_GetDelay
// EN: AArch64 prologue [cbz x0, #0x5b56c; ldr w8, [x0, #0xd60]; cmp w8, #1; b.lt #0x5b558] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x5b56c; ldr w8, [x0, #0xd60]; cmp w8, #1; b.lt #0x5b558]
uint64_t fde_sub_05b4ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB94D6008ULL) << 32) | 0xB4000400ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B4ECULL;
}

// FDE #0722 | PC: 0x05b570..0x05b5e0 (112 B) | Symbol: _Z38FDKsbrEnc_WriteEnvSingleChannelElementP15SBR_HEADER_DATAP19T_PARAMETRIC_STEREOP18SBR_BITSTREAM_DATAP12SBR_ENV_DATAP11COMMON_DATAj
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_05b570(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B570ULL;
}

// FDE #0723 | PC: 0x05b5e0..0x05b638 (88 B) | Symbol: sub_05b5e0
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05b5e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B5E0ULL;
}

// FDE #0724 | PC: 0x05b638..0x05b928 (752 B) | Symbol: sub_05b638
// EN: AArch64 prologue [mov x7, x30; bl #0x6a250; mov x30, x7; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x7, x30; bl #0x6a250; mov x30, x7; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_05b638(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94003B05ULL) << 32) | 0xAA1E03E7ULL;
    const uint64_t kPcRange = 0x02F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B638ULL;
}

// FDE #0725 | PC: 0x05b928..0x05bb88 (608 B) | Symbol: sub_05b928
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_05b928(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0260ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B928ULL;
}

// FDE #0726 | PC: 0x05bb88..0x05bc10 (136 B) | Symbol: sub_05bb88
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05bb88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05BB88ULL;
}

// FDE #0727 | PC: 0x05bc10..0x05bc98 (136 B) | Symbol: sub_05bc10
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_05bc10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05BC10ULL;
}

// FDE #0728 | PC: 0x05bc98..0x05be28 (400 B) | Symbol: sub_05bc98
// EN: AArch64 prologue [mov x3, x30; bl #0x6a160; mov x30, x3; stp x29, x30, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x6a160; mov x30, x3; stp x29, x30, [sp, #0x80]]
uint64_t fde_sub_05bc98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94003931ULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x0190ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05BC98ULL;
}

// FDE #0729 | PC: 0x05be28..0x05bfd0 (424 B) | Symbol: sub_05be28
// EN: AArch64 prologue [mov x3, x30; bl #0x6a084; mov x30, x3; stp x29, x30, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x6a084; mov x30, x3; stp x29, x30, [sp, #0x70]]
uint64_t fde_sub_05be28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94003896ULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x01A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05BE28ULL;
}

// FDE #0730 | PC: 0x05bfd0..0x05c038 (104 B) | Symbol: sub_05bfd0
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_05bfd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05BFD0ULL;
}

// FDE #0731 | PC: 0x05c038..0x05c114 (220 B) | Symbol: sub_05c038
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_05c038(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C038ULL;
}

// FDE #0732 | PC: 0x05c114..0x05c134 (32 B) | Symbol: sub_05c114
// EN: AArch64 prologue [mov w8, w0; mov w0, #-1; mov w9, #1; add w0, w0, #1] | VI: Khởi đầu hàm AArch64 [mov w8, w0; mov w0, #-1; mov w9, #1; add w0, w0, #1]
uint64_t fde_sub_05c114(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12800000ULL) << 32) | 0x2A0003E8ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C114ULL;
}

// FDE #0733 | PC: 0x05c134..0x05c25c (296 B) | Symbol: sub_05c134
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05c134(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0128ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C134ULL;
}

// FDE #0734 | PC: 0x05c25c..0x05c2d4 (120 B) | Symbol: _Z36FDKsbrEnc_WriteEnvChannelPairElementP15SBR_HEADER_DATAP19T_PARAMETRIC_STEREOP18SBR_BITSTREAM_DATAP12SBR_ENV_DATAS6_P11COMMON_DATAj
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_05c25c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C25CULL;
}

// FDE #0735 | PC: 0x05c2d4..0x05c354 (128 B) | Symbol: _Z36FDKsbrEnc_CountSbrChannelPairElementP15SBR_HEADER_DATAP19T_PARAMETRIC_STEREOP18SBR_BITSTREAM_DATAP12SBR_ENV_DATAS6_P11COMMON_DATAj
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; mov x7, x30; bl #0x69fa8; mov x30, x7] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; mov x7, x30; bl #0x69fa8; mov x30, x7]
uint64_t fde_sub_05c2d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E7ULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C2D4ULL;
}

// FDE #0736 | PC: 0x05c354..0x05c3a0 (76 B) | Symbol: sbrEncoder_GetHeader
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05c354(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C354ULL;
}

// FDE #0737 | PC: 0x05c3a0..0x05c594 (500 B) | Symbol: _Z30FDKsbrEnc_InitSbrHuffmanTablesP12SBR_ENV_DATAP17SBR_CODE_ENVELOPES2_7AMP_RES
// EN: AArch64 prologue [mov w8, #1; cbz x0, #0x5c590; cbz x1, #0x5c590; cbz x2, #0x5c590] | VI: Khởi đầu hàm AArch64 [mov w8, #1; cbz x0, #0x5c590; cbz x1, #0x5c590; cbz x2, #0x5c590]
uint64_t fde_sub_05c3a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000F60ULL) << 32) | 0x52800028ULL;
    const uint64_t kPcRange = 0x01F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C3A0ULL;
}

// FDE #0738 | PC: 0x05c594..0x05c9dc (1096 B) | Symbol: _Z22FDKsbrEnc_codeEnvelopePaPK8FREQ_RESP17SBR_CODE_ENVELOPEPiiiii
// EN: AArch64 prologue [sub sp, sp, #0x170; stp x28, x27, [sp, #0x110]; stp x26, x25, [sp, #0x120]; stp x24, x23, [sp, #0x130]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; stp x28, x27, [sp, #0x110]; stp x26, x25, [sp, #0x120]; stp x24, x23, [sp, #0x130]]
uint64_t fde_sub_05c594(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9116FFCULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x0448ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C594ULL;
}

// FDE #0739 | PC: 0x05c9dc..0x05ca5c (128 B) | Symbol: sub_05c9dc
// EN: AArch64 prologue [cbz w5, #0x5c9fc; ldrsb w8, [x0]; cmp w6, #1; b.ne #0x5ca00] | VI: Khởi đầu hàm AArch64 [cbz w5, #0x5c9fc; ldrsb w8, [x0]; cmp w6, #1; b.ne #0x5ca00]
uint64_t fde_sub_05c9dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39C00008ULL) << 32) | 0x34000105ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C9DCULL;
}

// FDE #0740 | PC: 0x05ca5c..0x05cad0 (116 B) | Symbol: sub_05ca5c
// EN: AArch64 prologue [cbz w4, #0x5ca68; strb w0, [x1, w3, sxtw]; ret; tbnz w2, #0x1f, #0x5ca8c] | VI: Khởi đầu hàm AArch64 [cbz w4, #0x5ca68; strb w0, [x1, w3, sxtw]; ret; tbnz w2, #0x1f, #0x5ca8c]
uint64_t fde_sub_05ca5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3823C820ULL) << 32) | 0x34000064ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CA5CULL;
}

// FDE #0741 | PC: 0x05cad0..0x05cb34 (100 B) | Symbol: _Z29FDKsbrEnc_InitSbrCodeEnvelopeP17SBR_CODE_ENVELOPEPiiii
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_05cad0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CAD0ULL;
}

// FDE #0742 | PC: 0x05cb34..0x05cbcc (152 B) | Symbol: _Z26FDKsbrEnc_InitSbrBitstreamP11COMMON_DATAPhiP11FDK_CRCINFOj
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_05cb34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CB34ULL;
}

// FDE #0743 | PC: 0x05cbcc..0x05cd30 (356 B) | Symbol: _Z30FDKsbrEnc_AssembleSbrBitstreamP11COMMON_DATAP11FDK_CRCINFOij
// EN: AArch64 prologue [cbz x0, #0x5cc48; sub sp, sp, #0x80; str x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x5cc48; sub sp, sp, #0x80; str x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]]
uint64_t fde_sub_05cbcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10203FFULL) << 32) | 0xB40003E0ULL;
    const uint64_t kPcRange = 0x0164ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CBCCULL;
}

// FDE #0744 | PC: 0x05cd30..0x05d278 (1352 B) | Symbol: _Z29FDKsbrEnc_extractSbrEnvelope1P15SBR_CONFIG_DATAP15SBR_HEADER_DATAP18SBR_BITSTREAM_DATAP11ENV_CHANNELP11COMMON_DATAP17SBR_ENV_TEMP_DATAP19SBR_FRAME_TEMP_DATA
// EN: AArch64 prologue [mov x1, x30; bl #0x69f18; mov x30, x1; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x1, x30; bl #0x69f18; mov x30, x1; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_05cd30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94003479ULL) << 32) | 0xAA1E03E1ULL;
    const uint64_t kPcRange = 0x0548ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CD30ULL;
}

// FDE #0745 | PC: 0x05d278..0x05e2ac (4148 B) | Symbol: _Z29FDKsbrEnc_extractSbrEnvelope2P15SBR_CONFIG_DATAP15SBR_HEADER_DATAP19T_PARAMETRIC_STEREOP18SBR_BITSTREAM_DATAP11ENV_CHANNELS8_P11COMMON_DATAP17SBR_ENV_TEMP_DATAP19SBR_FRAME_TEMP_DATAi
// EN: AArch64 prologue [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_05d278(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94003327ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x1034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D278ULL;
}

// FDE #0746 | PC: 0x05e2ac..0x05e2f0 (68 B) | Symbol: sub_05e2ac
// EN: AArch64 prologue [subs w8, w1, w3; b.le #0x5e2d0; cmp w8, #0x1f; mov w9, #0x1f] | VI: Khởi đầu hàm AArch64 [subs w8, w1, w3; b.le #0x5e2d0; cmp w8, #0x1f; mov w9, #0x1f]
uint64_t fde_sub_05e2ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5400010DULL) << 32) | 0x6B030028ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E2ACULL;
}

// FDE #0747 | PC: 0x05e2f0..0x05e980 (1680 B) | Symbol: sub_05e2f0
// EN: AArch64 prologue [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_05e2f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94002F09ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x0690ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E2F0ULL;
}

// FDE #0748 | PC: 0x05e980..0x05ea04 (132 B) | Symbol: sub_05e980
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_05e980(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E980ULL;
}

// FDE #0749 | PC: 0x05ea04..0x05eb4c (328 B) | Symbol: sub_05ea04
// EN: AArch64 prologue [mov x2, x30; bl #0x69f4c; mov x30, x2; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x69f4c; mov x30, x2; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_05ea04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94002D51ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0148ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05EA04ULL;
}

// FDE #0750 | PC: 0x05eb4c..0x05ebd4 (136 B) | Symbol: sub_05eb4c
// EN: AArch64 prologue [adrp x13, #0x81000; add x13, x13, #0x184; ldrb w13, [x13, w1, sxtw]; cmp w0, #0] | VI: Khởi đầu hàm AArch64 [adrp x13, #0x81000; add x13, x13, #0x184; ldrb w13, [x13, w1, sxtw]; cmp w0, #0]
uint64_t fde_sub_05eb4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910611ADULL) << 32) | 0xF000010DULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05EB4CULL;
}

// FDE #0751 | PC: 0x05ebd4..0x05ecf0 (284 B) | Symbol: sub_05ebd4
// EN: AArch64 prologue [str x19, [sp, #-0x10]!; ldr w10, [sp, #0x10]; subs w8, w1, w0; b.eq #0x5ec04] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x10]!; ldr w10, [sp, #0x10]; subs w8, w1, w0; b.eq #0x5ec04]
uint64_t fde_sub_05ebd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB94013EAULL) << 32) | 0xF81F0FF3ULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05EBD4ULL;
}

// FDE #0752 | PC: 0x05ecf0..0x05ed44 (84 B) | Symbol: sub_05ecf0
// EN: AArch64 prologue [cmp w1, #3; b.lt #0x5ed0c; cbz w0, #0x5ed1c; eor w8, w0, w0, asr #31] | VI: Khởi đầu hàm AArch64 [cmp w1, #3; b.lt #0x5ed0c; cbz w0, #0x5ed1c; eor w8, w0, w0, asr #31]
uint64_t fde_sub_05ecf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x540000CBULL) << 32) | 0x71000C3FULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05ECF0ULL;
}

// FDE #0753 | PC: 0x05ed44..0x05ede8 (164 B) | Symbol: sub_05ed44
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05ed44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05ED44ULL;
}

// FDE #0754 | PC: 0x05ede8..0x05eea4 (188 B) | Symbol: _Z34FDKsbrEnc_CreateExtractSbrEnvelopeP20SBR_EXTRACT_ENVELOPEiiPh
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05ede8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05EDE8ULL;
}

// FDE #0755 | PC: 0x05eea4..0x05efcc (296 B) | Symbol: _Z32FDKsbrEnc_InitExtractSbrEnvelopeP20SBR_EXTRACT_ENVELOPEiiiiiijiPhj
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_05eea4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0128ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05EEA4ULL;
}

// FDE #0756 | PC: 0x05efcc..0x05efdc (16 B) | Symbol: _Z34FDKsbrEnc_deleteExtractSbrEnvelopeP20SBR_EXTRACT_ENVELOPE
// EN: AArch64 prologue [cbz x0, #0x5efd8; add x0, x0, #0x200; b #0x1c5e8; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x5efd8; add x0, x0, #0x200; b #0x1c5e8; ret]
uint64_t fde_sub_05efcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91080000ULL) << 32) | 0xB4000060ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05EFCCULL;
}

// FDE #0757 | PC: 0x05efdc..0x05eff8 (28 B) | Symbol: _Z24FDKsbrEnc_GetEnvEstDelayP20SBR_EXTRACT_ENVELOPE
// EN: AArch64 prologue [ldr w8, [x0, #0x344]; ldr w9, [x0, #0x34c]; ldr w10, [x0, #0x354]; lsl w8, w8, #1] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #0x344]; ldr w9, [x0, #0x34c]; ldr w10, [x0, #0x354]; lsl w8, w8, #1]
uint64_t fde_sub_05efdc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9434C09ULL) << 32) | 0xB9434408ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05EFDCULL;
}

// FDE #0758 | PC: 0x05eff8..0x05ff40 (3912 B) | Symbol: _Z28FDKsbrEnc_frameInfoGeneratorP18SBR_ENVELOPE_FRAMEPhS1_iPKi
// EN: AArch64 prologue [mov x5, x30; bl #0x6a86c; mov x30, x5; stp x29, x30, [sp, #0x110]] | VI: Khởi đầu hàm AArch64 [mov x5, x30; bl #0x6a86c; mov x30, x5; stp x29, x30, [sp, #0x110]]
uint64_t fde_sub_05eff8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94002E1CULL) << 32) | 0xAA1E03E5ULL;
    const uint64_t kPcRange = 0x0F48ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05EFF8ULL;
}

// FDE #0759 | PC: 0x05ff40..0x05ffcc (140 B) | Symbol: sub_05ff40
// EN: AArch64 prologue [mov x7, x30; bl #0x6a250; mov x30, x7; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x7, x30; bl #0x6a250; mov x30, x7; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_05ff40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940028C3ULL) << 32) | 0xAA1E03E7ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FF40ULL;
}

// FDE #0760 | PC: 0x05ffcc..0x060098 (204 B) | Symbol: sub_05ffcc
// EN: AArch64 prologue [ldr w8, [sp]; ldr w9, [sp, #8]; sub w8, w8, w7; add w9, w8, w9, lsl #1] | VI: Khởi đầu hàm AArch64 [ldr w8, [sp]; ldr w9, [sp, #8]; sub w8, w8, w7; add w9, w8, w9, lsl #1]
uint64_t fde_sub_05ffcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9400BE9ULL) << 32) | 0xB94003E8ULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FFCCULL;
}

// FDE #0761 | PC: 0x060098..0x060134 (156 B) | Symbol: sub_060098
// EN: AArch64 prologue [ldrsw x9, [x3]; cbz w1, #0x600ec; mov w8, #1; str w8, [x0]] | VI: Khởi đầu hàm AArch64 [ldrsw x9, [x3]; cbz w1, #0x600ec; mov w8, #1; str w8, [x0]]
uint64_t fde_sub_060098(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34000281ULL) << 32) | 0xB9800069ULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060098ULL;
}

// FDE #0762 | PC: 0x060134..0x060194 (96 B) | Symbol: sub_060134
// EN: AArch64 prologue [ldrsw x9, [x3]; mov x8, xzr; add w10, w6, w5; cmp x8, x9] | VI: Khởi đầu hàm AArch64 [ldrsw x9, [x3]; mov x8, xzr; add w10, w6, w5; cmp x8, x9]
uint64_t fde_sub_060134(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E8ULL) << 32) | 0xB9800069ULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060134ULL;
}

// FDE #0763 | PC: 0x060194..0x060218 (132 B) | Symbol: sub_060194
// EN: AArch64 prologue [ldr w10, [sp, #8]; ldr w11, [sp, #0x20]; ldr w8, [sp, #0x18]; ldr w9, [sp, #0x10]] | VI: Khởi đầu hàm AArch64 [ldr w10, [sp, #8]; ldr w11, [sp, #0x20]; ldr w8, [sp, #0x18]; ldr w9, [sp, #0x10]]
uint64_t fde_sub_060194(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB94023EBULL) << 32) | 0xB9400BEAULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060194ULL;
}

// FDE #0764 | PC: 0x060218..0x06048c (628 B) | Symbol: sub_060218
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_060218(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0274ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060218ULL;
}

// FDE #0765 | PC: 0x06048c..0x060584 (248 B) | Symbol: _Z32FDKsbrEnc_initFrameInfoGeneratorP18SBR_ENVELOPE_FRAMEiiiiPK8FREQ_REShi
// EN: AArch64 prologue [mov x8, x30; bl #0x6aba8; mov x30, x8; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x6aba8; mov x30, x8; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_06048c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940029C6ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06048CULL;
}

// FDE #0766 | PC: 0x060584..0x060ab4 (1328 B) | Symbol: _Z37FDKsbrEnc_qmfInverseFilteringDetectorP16SBR_INV_FILT_ESTPPiS1_PaiiiP9INVF_MODE
// EN: AArch64 prologue [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_060584(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94002664ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x0530ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060584ULL;
}

// FDE #0767 | PC: 0x060ab4..0x060b18 (100 B) | Symbol: sub_060ab4
// EN: AArch64 prologue [ldr w8, [x1]; cmp w8, w0; b.le #0x60ac4; b #0x6a02c] | VI: Khởi đầu hàm AArch64 [ldr w8, [x1]; cmp w8, w0; b.le #0x60ac4; b #0x6a02c]
uint64_t fde_sub_060ab4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6B00011FULL) << 32) | 0xB9400028ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060AB4ULL;
}

// FDE #0768 | PC: 0x060b18..0x060bb8 (160 B) | Symbol: _Z29FDKsbrEnc_initInvFiltDetectorP16SBR_INV_FILT_ESTPiij
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_060b18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060B18ULL;
}

// FDE #0769 | PC: 0x060bb8..0x060bf0 (56 B) | Symbol: _Z30FDKsbrEnc_resetInvFiltDetectorP16SBR_INV_FILT_ESTPii
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; lsl w9, w2, #2] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; lsl w9, w2, #2]
uint64_t fde_sub_060bb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060BB8ULL;
}

// FDE #0770 | PC: 0x060bf0..0x0619e8 (3576 B) | Symbol: _Z40FDKsbrEnc_SbrMissingHarmonicsDetectorQmfP30SBR_MISSING_HARMONICS_DETECTORPPiS2_PaPK14SBR_FRAME_INFOPKhS1_PhS8_iS9_S1_
// EN: AArch64 prologue [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_060bf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940024C9ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x0DF8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060BF0ULL;
}

// FDE #0771 | PC: 0x0619e8..0x061c18 (560 B) | Symbol: sub_0619e8
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x10]!; ldp x9, x8, [sp, #0x10]; mov x12, xzr; add x11, x7, #8] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x10]!; ldp x9, x8, [sp, #0x10]; mov x12, xzr; add x11, x7, #8]
uint64_t fde_sub_0619e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94123E9ULL) << 32) | 0xA9BF4FF4ULL;
    const uint64_t kPcRange = 0x0230ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0619E8ULL;
}

// FDE #0772 | PC: 0x061c18..0x061cb8 (160 B) | Symbol: _Z43FDKsbrEnc_CreateSbrMissingHarmonicsDetectorP30SBR_MISSING_HARMONICS_DETECTORi
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_061c18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061C18ULL;
}

// FDE #0773 | PC: 0x061cb8..0x061df4 (316 B) | Symbol: _Z41FDKsbrEnc_InitSbrMissingHarmonicsDetectorP30SBR_MISSING_HARMONICS_DETECTORiiiiiiij
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_061cb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x013CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061CB8ULL;
}

// FDE #0774 | PC: 0x061df4..0x061e48 (84 B) | Symbol: _Z43FDKsbrEnc_DeleteSbrMissingHarmonicsDetectorP30SBR_MISSING_HARMONICS_DETECTOR
// EN: AArch64 prologue [cbz x0, #0x61e44; stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x61e44; stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10]
uint64_t fde_sub_061df4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE4FF4ULL) << 32) | 0xB4000280ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061DF4ULL;
}

// FDE #0775 | PC: 0x061e48..0x062150 (776 B) | Symbol: _Z42FDKsbrEnc_ResetSbrMissingHarmonicsDetectorP30SBR_MISSING_HARMONICS_DETECTORi
// EN: AArch64 prologue [sub sp, sp, #0x150; str x28, [sp, #0x100]; stp x24, x23, [sp, #0x110]; stp x22, x21, [sp, #0x120]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x150; str x28, [sp, #0x100]; stp x24, x23, [sp, #0x110]; stp x22, x21, [sp, #0x120]]
uint64_t fde_sub_061e48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90083FCULL) << 32) | 0xD10543FFULL;
    const uint64_t kPcRange = 0x0308ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061E48ULL;
}

// FDE #0776 | PC: 0x062150..0x062658 (1288 B) | Symbol: _Z34FDKsbrEnc_sbrNoiseFloorEstimateQmfP24SBR_NOISE_FLOOR_ESTIMATEPK14SBR_FRAME_INFOPiPS4_PaiijiP9INVF_MODEj
// EN: AArch64 prologue [mov x8, x30; bl #0x6a5a4; mov x30, x8; stp x29, x30, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x6a5a4; mov x30, x8; stp x29, x30, [sp, #0xb0]]
uint64_t fde_sub_062150(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94002114ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x0508ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062150ULL;
}

// FDE #0777 | PC: 0x062658..0x062768 (272 B) | Symbol: _Z35FDKsbrEnc_InitSbrNoiseFloorEstimateP24SBR_NOISE_FLOOR_ESTIMATEiPKhiiiij
// EN: AArch64 prologue [sub sp, sp, #0x60; mov x8, x30; bl #0x69fa8; mov x30, x8] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; mov x8, x30; bl #0x69fa8; mov x30, x8]
uint64_t fde_sub_062658(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0110ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062658ULL;
}

// FDE #0778 | PC: 0x062768..0x062894 (300 B) | Symbol: _Z36FDKsbrEnc_resetSbrNoiseFloorEstimateP24SBR_NOISE_FLOOR_ESTIMATEPKhi
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp x22, x21, [sp, #0x70]; stp x20, x19, [sp, #0x80]; stp x29, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp x22, x21, [sp, #0x70]; stp x20, x19, [sp, #0x80]; stp x29, x30, [sp, #0x90]]
uint64_t fde_sub_062768(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90757F6ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062768ULL;
}

// FDE #0779 | PC: 0x062894..0x062958 (196 B) | Symbol: FDKsbrEnc_EncodeIid
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x8, x6] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x8, x6]
uint64_t fde_sub_062894(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062894ULL;
}

// FDE #0780 | PC: 0x062958..0x0629e8 (144 B) | Symbol: sub_062958
// EN: AArch64 prologue [mov x8, x30; bl #0x69f4c; mov x30, x8; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x69f4c; mov x30, x8; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_062958(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94001D7CULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062958ULL;
}

// FDE #0781 | PC: 0x0629e8..0x062a80 (152 B) | Symbol: sub_0629e8
// EN: AArch64 prologue [mov x8, x30; bl #0x69f4c; mov x30, x8; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x69f4c; mov x30, x8; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_0629e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94001D58ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0629E8ULL;
}

// FDE #0782 | PC: 0x062a80..0x062aa8 (40 B) | Symbol: sub_062a80
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w19, w2] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w19, w2]
uint64_t fde_sub_062a80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062A80ULL;
}

// FDE #0783 | PC: 0x062aa8..0x062b1c (116 B) | Symbol: FDKsbrEnc_EncodeIcc
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x8, x5] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x8, x5]
uint64_t fde_sub_062aa8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062AA8ULL;
}

// FDE #0784 | PC: 0x062b1c..0x062b74 (88 B) | Symbol: FDKsbrEnc_EncodeIpd
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x8, x5] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x8, x5]
uint64_t fde_sub_062b1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062B1CULL;
}

// FDE #0785 | PC: 0x062b74..0x062bcc (88 B) | Symbol: FDKsbrEnc_EncodeOpd
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x8, x5] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x8, x5]
uint64_t fde_sub_062b74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062B74ULL;
}

// FDE #0786 | PC: 0x062bcc..0x062eb0 (740 B) | Symbol: FDKsbrEnc_WritePSBitstream
// EN: AArch64 prologue [sub sp, sp, #0x60; mov x2, x30; bl #0x69fa8; mov x30, x2] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; mov x2, x30; bl #0x69fa8; mov x30, x2]
uint64_t fde_sub_062bcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E2ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x02E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062BCCULL;
}

// FDE #0787 | PC: 0x062eb0..0x062fc4 (276 B) | Symbol: sub_062eb0
// EN: AArch64 prologue [mov x2, x30; bl #0x69f4c; mov x30, x2; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x69f4c; mov x30, x2; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_062eb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94001C26ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062EB0ULL;
}

// FDE #0788 | PC: 0x062fc4..0x06304c (136 B) | Symbol: _Z28FDKsbrEnc_initPsBandNrgScaleP11T_PS_ENCODE
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrsw x8, [x0, #0x378]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrsw x8, [x0, #0x378]]
uint64_t fde_sub_062fc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062FC4ULL;
}

// FDE #0789 | PC: 0x06304c..0x063090 (68 B) | Symbol: _Z24FDKsbrEnc_CreatePSEncodePP11T_PS_ENCODE
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x6307c] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x6307c]
uint64_t fde_sub_06304c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06304CULL;
}

// FDE #0790 | PC: 0x063090..0x0631c4 (308 B) | Symbol: _Z22FDKsbrEnc_InitPSEncodeP11T_PS_ENCODE8PS_BANDSi
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_063090(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0134ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063090ULL;
}

// FDE #0791 | PC: 0x0631c4..0x0631dc (24 B) | Symbol: _Z25FDKsbrEnc_DestroyPSEncodePP11T_PS_ENCODE
// EN: AArch64 prologue [cbz x0, #0x631d8; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x1c778] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x631d8; stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x1c778]
uint64_t fde_sub_0631c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0xB40000A0ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0631C4ULL;
}

// FDE #0792 | PC: 0x0631dc..0x064024 (3656 B) | Symbol: _Z18FDKsbrEnc_PSEncodeP11T_PS_ENCODEP8T_PS_OUTPhjPA2_A2_Piii
// EN: AArch64 prologue [mov x7, x30; bl #0x69f18; mov x30, x7; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x7, x30; bl #0x69f18; mov x30, x7; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_0631dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94001B4EULL) << 32) | 0xAA1E03E7ULL;
    const uint64_t kPcRange = 0x0E48ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0631DCULL;
}

// FDE #0793 | PC: 0x064024..0x0640a0 (124 B) | Symbol: sub_064024
// EN: AArch64 prologue [mov w11, #0x4608; mov x8, xzr; sxtw x9, w4; sxtw x10, w3] | VI: Khởi đầu hàm AArch64 [mov w11, #0x4608; mov x8, xzr; sxtw x9, w4; sxtw x10, w3]
uint64_t fde_sub_064024(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E8ULL) << 32) | 0x5288C10BULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064024ULL;
}

// FDE #0794 | PC: 0x0640a0..0x064318 (632 B) | Symbol: sub_0640a0
// EN: AArch64 prologue [mov x7, x30; bl #0x6a160; mov x30, x7; stp x29, x30, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [mov x7, x30; bl #0x6a160; mov x30, x7; stp x29, x30, [sp, #0x80]]
uint64_t fde_sub_0640a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400182FULL) << 32) | 0xAA1E03E7ULL;
    const uint64_t kPcRange = 0x0278ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0640A0ULL;
}

// FDE #0795 | PC: 0x064318..0x064348 (48 B) | Symbol: sub_064318
// EN: AArch64 prologue [mov x8, xzr; sxtw x9, w3; cmp x8, x9; b.ge #0x64344] | VI: Khởi đầu hàm AArch64 [mov x8, xzr; sxtw x9, w3; cmp x8, x9; b.ge #0x64344]
uint64_t fde_sub_064318(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x93407C69ULL) << 32) | 0xAA1F03E8ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064318ULL;
}

// FDE #0796 | PC: 0x064348..0x0643d4 (140 B) | Symbol: sub_064348
// EN: AArch64 prologue [sub w11, w4, #1; mov x8, x0; mov x9, xzr; mov w0, wzr] | VI: Khởi đầu hàm AArch64 [sub w11, w4, #1; mov x8, x0; mov x9, xzr; mov w0, wzr]
uint64_t fde_sub_064348(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003E8ULL) << 32) | 0x5100048BULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064348ULL;
}

// FDE #0797 | PC: 0x0643d4..0x064464 (144 B) | Symbol: _Z12PSEnc_CreatePP19T_PARAMETRIC_STEREO
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x64448] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x64448]
uint64_t fde_sub_0643d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0643D4ULL;
}

// FDE #0798 | PC: 0x064464..0x06461c (440 B) | Symbol: _Z10PSEnc_InitP19T_PARAMETRIC_STEREOP14T_PSENC_CONFIGiiPh
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_064464(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x01B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064464ULL;
}

// FDE #0799 | PC: 0x06461c..0x064650 (52 B) | Symbol: _Z13PSEnc_DestroyPP19T_PARAMETRIC_STEREO
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x64644] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x64644]
uint64_t fde_sub_06461c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06461CULL;
}

// FDE #0800 | PC: 0x064650..0x064660 (16 B) | Symbol: _Z27FDKsbrEnc_PSEnc_WritePSDataP19T_PARAMETRIC_STEREOP13FDK_BITSTREAM
// EN: AArch64 prologue [cbz x0, #0x6465c; add x0, x0, #8; b #0x1c518; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x6465c; add x0, x0, #8; b #0x1c518; ret]
uint64_t fde_sub_064650(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91002000ULL) << 32) | 0xB4000060ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064650ULL;
}

// FDE #0801 | PC: 0x064660..0x064e98 (2104 B) | Symbol: _Z42FDKsbrEnc_PSEnc_ParametricStereoProcessingP19T_PARAMETRIC_STEREOPPsjPP15QMF_FILTER_BANKPPiS7_S1_S4_Pai
// EN: AArch64 prologue [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_064660(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400162DULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x0838ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064660ULL;
}

// FDE #0802 | PC: 0x064e98..0x064f24 (140 B) | Symbol: _Z25FDKaacEnc_InitDownsamplerP11DOWNSAMPLERii
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_064e98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064E98ULL;
}

// FDE #0803 | PC: 0x064f24..0x0650c4 (416 B) | Symbol: _Z20FDKaacEnc_DownsampleP11DOWNSAMPLERPsiiS1_Pii
// EN: AArch64 prologue [str x27, [sp, #-0x50]!; mov x7, x30; bl #0x69fa8; mov x30, x7] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x50]!; mov x7, x30; bl #0x69fa8; mov x30, x7]
uint64_t fde_sub_064f24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E7ULL) << 32) | 0xF81B0FFBULL;
    const uint64_t kPcRange = 0x01A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064F24ULL;
}

// FDE #0804 | PC: 0x0650c4..0x0651d0 (268 B) | Symbol: sbrEncoder_Close
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0650c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0650C4ULL;
}

// FDE #0805 | PC: 0x0651d0..0x065670 (1184 B) | Symbol: _Z24FDKsbrEnc_EnvEncodeFrameP11SBR_ENCODERiPsjPjPhi
// EN: AArch64 prologue [mov x7, x30; bl #0x69f18; mov x30, x7; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x7, x30; bl #0x69f18; mov x30, x7; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_0651d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94001351ULL) << 32) | 0xAA1E03E7ULL;
    const uint64_t kPcRange = 0x04A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0651D0ULL;
}

// FDE #0806 | PC: 0x065670..0x06572c (188 B) | Symbol: sub_065670
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_065670(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065670ULL;
}

// FDE #0807 | PC: 0x06572c..0x065900 (468 B) | Symbol: sbrEncoder_Open
// EN: AArch64 prologue [mov x4, x30; bl #0x6bbd8; mov x30, x4; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x4, x30; bl #0x6bbd8; mov x30, x4; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_06572c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400192AULL) << 32) | 0xAA1E03E4ULL;
    const uint64_t kPcRange = 0x01D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06572CULL;
}

// FDE #0808 | PC: 0x065900..0x06590c (12 B) | Symbol: sbrEncoder_GetInBufferSize
// EN: AArch64 prologue [mov w8, #0xb0c; mul w0, w0, w8; ret] | VI: Khởi đầu hàm AArch64 [mov w8, #0xb0c; mul w0, w0, w8; ret]
uint64_t fde_sub_065900(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1B087C00ULL) << 32) | 0x52816188ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065900ULL;
}

// FDE #0809 | PC: 0x06590c..0x0659b0 (164 B) | Symbol: sbrEncoder_LimitBitRate
// EN: AArch64 prologue [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06590c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06590CULL;
}

// FDE #0810 | PC: 0x0659b0..0x065a90 (224 B) | Symbol: sub_0659b0
// EN: AArch64 prologue [adrp x11, #0x9a000; ldr x11, [x11, #0xd08]; mov w10, #0x4b40; mov x8, xzr] | VI: Khởi đầu hàm AArch64 [adrp x11, #0x9a000; ldr x11, [x11, #0xd08]; mov w10, #0x4b40; mov x8, xzr]
uint64_t fde_sub_0659b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF946856BULL) << 32) | 0xB00001ABULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0659B0ULL;
}

// FDE #0811 | PC: 0x065a90..0x065bc4 (308 B) | Symbol: sub_065a90
// EN: AArch64 prologue [adrp x10, #0x9a000; ldr x10, [x10, #0xd10]; mov w11, #0x4b40; mov w12, #0x4b40] | VI: Khởi đầu hàm AArch64 [adrp x10, #0x9a000; ldr x10, [x10, #0xd10]; mov w11, #0x4b40; mov w12, #0x4b40]
uint64_t fde_sub_065a90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF946894AULL) << 32) | 0xB00001AAULL;
    const uint64_t kPcRange = 0x0134ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065A90ULL;
}

// FDE #0812 | PC: 0x065bc4..0x065bd0 (12 B) | Symbol: sbrEncoder_IsSingleRatePossible
// EN: AArch64 prologue [cmp w0, #0x1d; cset w0, ne; ret] | VI: Khởi đầu hàm AArch64 [cmp w0, #0x1d; cset w0, ne; ret]
uint64_t fde_sub_065bc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1A9F07E0ULL) << 32) | 0x7100741FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065BC4ULL;
}

// FDE #0813 | PC: 0x065bd0..0x067124 (5460 B) | Symbol: sbrEncoder_Init
// EN: AArch64 prologue [stp d11, d10, [sp, #-0x80]!; stp d9, d8, [sp, #0x10]; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp d11, d10, [sp, #-0x80]!; stp d9, d8, [sp, #0x10]; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]]
uint64_t fde_sub_065bd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D0123E9ULL) << 32) | 0x6DB82BEBULL;
    const uint64_t kPcRange = 0x1554ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065BD0ULL;
}

// FDE #0814 | PC: 0x067124..0x0671c8 (164 B) | Symbol: sbrEncoder_UpdateBuffers
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0x3bc]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0x3bc]]
uint64_t fde_sub_067124(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067124ULL;
}

// FDE #0815 | PC: 0x0671c8..0x0672a0 (216 B) | Symbol: sbrEncoder_EncodeFrame
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0671c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0671C8ULL;
}

// FDE #0816 | PC: 0x0672a0..0x0672ac (12 B) | Symbol: sbrEncoder_GetEstimateBitrate
// EN: AArch64 prologue [cbz x0, #0x672a8; ldr w0, [x0, #0x3d0]; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x672a8; ldr w0, [x0, #0x3d0]; ret]
uint64_t fde_sub_0672a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB943D000ULL) << 32) | 0xB4000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0672A0ULL;
}

// FDE #0817 | PC: 0x0672ac..0x0672bc (16 B) | Symbol: sbrEncoder_GetInputDataDelay
// EN: AArch64 prologue [cbz x0, #0x672b8; ldr w0, [x0, #0x3d4]; ret; b #0x6a07c] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x672b8; ldr w0, [x0, #0x3d4]; ret; b #0x6a07c]
uint64_t fde_sub_0672ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB943D400ULL) << 32) | 0xB4000060ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0672ACULL;
}

// FDE #0818 | PC: 0x0672bc..0x067334 (120 B) | Symbol: sbrEncoder_GetLibInfo
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x672e8] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x672e8]
uint64_t fde_sub_0672bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0672BCULL;
}

// FDE #0819 | PC: 0x067334..0x0673c4 (144 B) | Symbol: _Z25FDKsbrEnc_Shellsort_fractPii
// EN: AArch64 prologue [mov w8, #1; add w8, w8, w8, lsl #1; cmp w8, w1; add w8, w8, #1] | VI: Khởi đầu hàm AArch64 [mov w8, #1; add w8, w8, w8, lsl #1; cmp w8, w1; add w8, w8, #1]
uint64_t fde_sub_067334(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x0B080508ULL) << 32) | 0x52800028ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067334ULL;
}

// FDE #0820 | PC: 0x0673c4..0x067400 (60 B) | Symbol: _Z20FDKsbrEnc_AddVecLeftPiS_S_i
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0673c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0673C4ULL;
}

// FDE #0821 | PC: 0x067400..0x067430 (48 B) | Symbol: _Z17FDKsbrEnc_AddLeftPiS_i
// EN: AArch64 prologue [ldrsw x8, [x1]; subs x9, x8, #1; b.lt #0x67420; add x8, x0, x8, lsl #2] | VI: Khởi đầu hàm AArch64 [ldrsw x8, [x1]; subs x9, x8, #1; b.lt #0x67420; add x8, x0, x8, lsl #2]
uint64_t fde_sub_067400(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF1000509ULL) << 32) | 0xB9800028ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067400ULL;
}

// FDE #0822 | PC: 0x067430..0x067444 (20 B) | Symbol: _Z18FDKsbrEnc_AddRightPiS_i
// EN: AArch64 prologue [ldrsw x8, [x1]; str w2, [x0, x8, lsl #2]; ldr w8, [x1]; add w8, w8, #1] | VI: Khởi đầu hàm AArch64 [ldrsw x8, [x1]; str w2, [x0, x8, lsl #2]; ldr w8, [x1]; add w8, w8, #1]
uint64_t fde_sub_067430(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB8287802ULL) << 32) | 0xB9800028ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067430ULL;
}

// FDE #0823 | PC: 0x067444..0x067478 (52 B) | Symbol: _Z21FDKsbrEnc_AddVecRightPiS_S_i
// EN: AArch64 prologue [mov x8, xzr; sxtw x9, w3; cmp x8, x9; b.ge #0x67474] | VI: Khởi đầu hàm AArch64 [mov x8, xzr; sxtw x9, w3; cmp x8, x9; b.ge #0x67474]
uint64_t fde_sub_067444(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x93407C69ULL) << 32) | 0xAA1F03E8ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067444ULL;
}

// FDE #0824 | PC: 0x067478..0x067544 (204 B) | Symbol: _Z32FDKsbrEnc_LSI_divide_scale_fractiii
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_067478(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067478ULL;
}

// FDE #0825 | PC: 0x067544..0x06754c (8 B) | Symbol: _Z21GetRam_SbrDynamic_RAMi
// EN: AArch64 prologue [mov w0, #0x2380; b #0x6ad70] | VI: Khởi đầu hàm AArch64 [mov w0, #0x2380; b #0x6ad70]
uint64_t fde_sub_067544(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000E0AULL) << 32) | 0x52847000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067544ULL;
}

// FDE #0826 | PC: 0x06754c..0x067554 (8 B) | Symbol: _Z32GetRequiredMemRam_SbrDynamic_RAMv
// EN: AArch64 prologue [mov w0, #0x8e00; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x8e00; ret]
uint64_t fde_sub_06754c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x5291C000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06754CULL;
}

// FDE #0827 | PC: 0x067554..0x067560 (12 B) | Symbol: _Z17GetRam_SbrEncoderi
// EN: AArch64 prologue [mov w0, #1; mov w1, #0x450; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #1; mov w1, #0x450; b #0x1a748]
uint64_t fde_sub_067554(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52808A01ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067554ULL;
}

// FDE #0828 | PC: 0x067560..0x067568 (8 B) | Symbol: _Z28GetRequiredMemRam_SbrEncoderv
// EN: AArch64 prologue [mov w0, #0x450; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x450; ret]
uint64_t fde_sub_067560(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52808A00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067560ULL;
}

// FDE #0829 | PC: 0x067568..0x067574 (12 B) | Symbol: _Z17GetRam_SbrChanneli
// EN: AArch64 prologue [mov w0, #1; mov w1, #0x2210; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #1; mov w1, #0x2210; b #0x1a748]
uint64_t fde_sub_067568(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52844201ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067568ULL;
}

// FDE #0830 | PC: 0x067574..0x067580 (12 B) | Symbol: _Z28GetRequiredMemRam_SbrChannelv
// EN: AArch64 prologue [mov w0, #0x1080; movk w0, #1, lsl #16; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x1080; movk w0, #1, lsl #16; ret]
uint64_t fde_sub_067574(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72A00020ULL) << 32) | 0x52821000ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067574ULL;
}

// FDE #0831 | PC: 0x067580..0x06758c (12 B) | Symbol: _Z17GetRam_SbrElementi
// EN: AArch64 prologue [mov w0, #1; mov w1, #0x4b0; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #1; mov w1, #0x4b0; b #0x1a748]
uint64_t fde_sub_067580(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809601ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067580ULL;
}

// FDE #0832 | PC: 0x06758c..0x067594 (8 B) | Symbol: _Z28GetRequiredMemRam_SbrElementv
// EN: AArch64 prologue [mov w0, #0x2580; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x2580; ret]
uint64_t fde_sub_06758c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x5284B000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06758CULL;
}

// FDE #0833 | PC: 0x067594..0x06759c (8 B) | Symbol: _Z27GetRam_PsQmfStatesSynthesisi
// EN: AArch64 prologue [mov w0, #0x500; b #0x6ad94] | VI: Khởi đầu hàm AArch64 [mov w0, #0x500; b #0x6ad94]
uint64_t fde_sub_067594(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000DFFULL) << 32) | 0x5280A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067594ULL;
}

// FDE #0834 | PC: 0x06759c..0x0675a4 (8 B) | Symbol: _Z39GetRequiredMemRam_Sbr_QmfStatesAnalysisv
// EN: AArch64 prologue [mov w0, #0x2880; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x2880; ret]
uint64_t fde_sub_06759c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52851000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06759CULL;
}

// FDE #0835 | PC: 0x0675a4..0x0675ac (8 B) | Symbol: _Z21GetRam_Sbr_signMatrixi
// EN: AArch64 prologue [mov w0, #0x100; b #0x6ad70] | VI: Khởi đầu hàm AArch64 [mov w0, #0x100; b #0x6ad70]
uint64_t fde_sub_0675a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000DF2ULL) << 32) | 0x52802000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0675A4ULL;
}

// FDE #0836 | PC: 0x0675ac..0x0675b4 (8 B) | Symbol: _Z26GetRam_Sbr_freqBandTableLOi
// EN: AArch64 prologue [mov w0, #0x19; b #0x6a9cc] | VI: Khởi đầu hàm AArch64 [mov w0, #0x19; b #0x6a9cc]
uint64_t fde_sub_0675ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000D07ULL) << 32) | 0x52800320ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0675ACULL;
}

// FDE #0837 | PC: 0x0675b4..0x0675bc (8 B) | Symbol: _Z37GetRequiredMemRam_Sbr_freqBandTableLOv
// EN: AArch64 prologue [mov w0, #0x100; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x100; ret]
uint64_t fde_sub_0675b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52802000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0675B4ULL;
}

// FDE #0838 | PC: 0x0675bc..0x0675c4 (8 B) | Symbol: _Z26GetRam_Sbr_freqBandTableHIi
// EN: AArch64 prologue [mov w0, #0x31; b #0x6a9cc] | VI: Khởi đầu hàm AArch64 [mov w0, #0x31; b #0x6a9cc]
uint64_t fde_sub_0675bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000D03ULL) << 32) | 0x52800620ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0675BCULL;
}

// FDE #0839 | PC: 0x0675c4..0x0675cc (8 B) | Symbol: _Z32GetRequiredMemRam_Sbr_v_k_masterv
// EN: AArch64 prologue [mov w0, #0x1c0; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x1c0; ret]
uint64_t fde_sub_0675c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52803800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0675C4ULL;
}

// FDE #0840 | PC: 0x0675cc..0x0675d4 (8 B) | Symbol: _Z30GetRam_Sbr_guideVectorDetectedi
// EN: AArch64 prologue [mov w0, #0xc0; b #0x6a9cc] | VI: Khởi đầu hàm AArch64 [mov w0, #0xc0; b #0x6a9cc]
uint64_t fde_sub_0675cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000CFFULL) << 32) | 0x52801800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0675CCULL;
}

// FDE #0841 | PC: 0x0675d4..0x0675dc (8 B) | Symbol: _Z38GetRequiredMemRam_Sbr_detectionVectorsv
// EN: AArch64 prologue [mov w0, #0x600; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x600; ret]
uint64_t fde_sub_0675d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x5280C000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0675D4ULL;
}

// FDE #0842 | PC: 0x0675dc..0x0675e4 (8 B) | Symbol: _Z20GetRam_Sbr_guideScfbi
// EN: AArch64 prologue [mov w0, #0x30; b #0x6a9cc] | VI: Khởi đầu hàm AArch64 [mov w0, #0x30; b #0x6a9cc]
uint64_t fde_sub_0675dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000CFBULL) << 32) | 0x52800600ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0675DCULL;
}

// FDE #0843 | PC: 0x0675e4..0x0675ec (8 B) | Symbol: _Z31GetRequiredMemRam_Sbr_guideScfbv
// EN: AArch64 prologue [mov w0, #0x180; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x180; ret]
uint64_t fde_sub_0675e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52803000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0675E4ULL;
}

// FDE #0844 | PC: 0x0675ec..0x0675f4 (8 B) | Symbol: _Z26GetRam_Sbr_guideVectorDiffi
// EN: AArch64 prologue [mov w0, #0xc0; b #0x6ad70] | VI: Khởi đầu hàm AArch64 [mov w0, #0xc0; b #0x6ad70]
uint64_t fde_sub_0675ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000DE0ULL) << 32) | 0x52801800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0675ECULL;
}

// FDE #0845 | PC: 0x0675f4..0x0675fc (8 B) | Symbol: _Z37GetRequiredMemRam_Sbr_guideVectorOrigv
// EN: AArch64 prologue [mov w0, #0x1800; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x1800; ret]
uint64_t fde_sub_0675f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52830000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0675F4ULL;
}

// FDE #0846 | PC: 0x0675fc..0x067604 (8 B) | Symbol: _Z38GetRequiredMemRam_PsQmfStatesSynthesisv
// EN: AArch64 prologue [mov w0, #0x510; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x510; ret]
uint64_t fde_sub_0675fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x5280A200ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0675FCULL;
}

// FDE #0847 | PC: 0x067604..0x067610 (12 B) | Symbol: _Z15GetRam_PsEncodei
// EN: AArch64 prologue [mov w0, #1; mov w1, #0x54c; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #1; mov w1, #0x54c; b #0x1a748]
uint64_t fde_sub_067604(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5280A981ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067604ULL;
}

// FDE #0848 | PC: 0x067610..0x067618 (8 B) | Symbol: _Z26GetRequiredMemRam_PsEncodev
// EN: AArch64 prologue [mov w0, #0x550; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x550; ret]
uint64_t fde_sub_067610(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x5280AA00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067610ULL;
}

// FDE #0849 | PC: 0x067618..0x067624 (12 B) | Symbol: _Z18GetRam_ParamStereoi
// EN: AArch64 prologue [mov w0, #1; mov w1, #0x7b58; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #1; mov w1, #0x7b58; b #0x1a748]
uint64_t fde_sub_067618(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x528F6B01ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067618ULL;
}

// FDE #0850 | PC: 0x067624..0x06762c (8 B) | Symbol: _Z29GetRequiredMemRam_ParamStereov
// EN: AArch64 prologue [mov w0, #0x7b58; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x7b58; ret]
uint64_t fde_sub_067624(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x528F6B00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067624ULL;
}

// FDE #0851 | PC: 0x06762c..0x067634 (8 B) | Symbol: _Z21GetRam_Sbr_envYBufferi
// EN: AArch64 prologue [mov w0, #0x400; b #0x6ad70] | VI: Khởi đầu hàm AArch64 [mov w0, #0x400; b #0x6ad70]
uint64_t fde_sub_06762c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000DD0ULL) << 32) | 0x52808000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06762CULL;
}

// FDE #0852 | PC: 0x067634..0x067644 (16 B) | Symbol: _Z21GetRam_Sbr_envYBufferiPh
// EN: AArch64 prologue [mov w8, #0x2380; smaddl x8, w0, w8, x1; mov w9, #0x4700; b #0x6c5ac] | VI: Khởi đầu hàm AArch64 [mov w8, #0x2380; smaddl x8, w0, w8, x1; mov w9, #0x4700; b #0x6c5ac]
uint64_t fde_sub_067634(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9B280408ULL) << 32) | 0x52847008ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067634ULL;
}

// FDE #0853 | PC: 0x067644..0x067650 (12 B) | Symbol: _Z21GetRam_Sbr_envRBufferiPh
// EN: AArch64 prologue [mov w8, #0x4700; smaddl x0, w0, w8, x1; ret] | VI: Khởi đầu hàm AArch64 [mov w8, #0x4700; smaddl x0, w0, w8, x1; ret]
uint64_t fde_sub_067644(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9B280400ULL) << 32) | 0x5288E008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067644ULL;
}

// FDE #0854 | PC: 0x067650..0x067660 (16 B) | Symbol: _Z21GetRam_Sbr_envIBufferiPh
// EN: AArch64 prologue [mov w8, #0x4700; smaddl x8, w0, w8, x1; mov w9, #0x2380; b #0x6c5ac] | VI: Khởi đầu hàm AArch64 [mov w8, #0x4700; smaddl x8, w0, w8, x1; mov w9, #0x2380; b #0x6c5ac]
uint64_t fde_sub_067650(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9B280408ULL) << 32) | 0x5288E008ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067650ULL;
}

// FDE #0855 | PC: 0x067660..0x067698 (56 B) | Symbol: _Z28FDKsbrEnc_getSbrStartFreqRAWii
// EN: AArch64 prologue [cmp w0, #0xf; b.ls #0x6766c; b #0x6a07c; str x19, [sp, #-0x20]!] | VI: Khởi đầu hàm AArch64 [cmp w0, #0xf; b.ls #0x6766c; b #0x6a07c; str x19, [sp, #-0x20]!]
uint64_t fde_sub_067660(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000049ULL) << 32) | 0x71003C1FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067660ULL;
}

// FDE #0856 | PC: 0x067698..0x0677a0 (264 B) | Symbol: sub_067698
// EN: AArch64 prologue [mov w8, #0x1f40; cmp w0, w8; b.eq #0x67720; mov w8, #0x2b11] | VI: Khởi đầu hàm AArch64 [mov w8, #0x1f40; cmp w0, w8; b.eq #0x67720; mov w8, #0x2b11]
uint64_t fde_sub_067698(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6B08001FULL) << 32) | 0x5283E808ULL;
    const uint64_t kPcRange = 0x0108ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067698ULL;
}

// FDE #0857 | PC: 0x0677a0..0x0677d8 (56 B) | Symbol: _Z27FDKsbrEnc_getSbrStopFreqRAWii
// EN: AArch64 prologue [cmp w0, #0xd; b.ls #0x677ac; b #0x6a07c; str x19, [sp, #-0x20]!] | VI: Khởi đầu hàm AArch64 [cmp w0, #0xd; b.ls #0x677ac; b #0x6a07c; str x19, [sp, #-0x20]!]
uint64_t fde_sub_0677a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000049ULL) << 32) | 0x7100341FULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0677A0ULL;
}

// FDE #0858 | PC: 0x0677d8..0x067aac (724 B) | Symbol: sub_0677d8
// EN: AArch64 prologue [str x28, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x28, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0677d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FFCULL;
    const uint64_t kPcRange = 0x02D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0677D8ULL;
}

// FDE #0859 | PC: 0x067aac..0x067b88 (220 B) | Symbol: _Z30FDKsbrEnc_FindStartAndStopBandiiiiiPiS_
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_067aac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067AACULL;
}

// FDE #0860 | PC: 0x067b88..0x067e3c (692 B) | Symbol: _Z25FDKsbrEnc_UpdateFreqScalePhPiiiii
// EN: AArch64 prologue [sub sp, sp, #0x1b0; stp x28, x27, [sp, #0x150]; stp x26, x25, [sp, #0x160]; stp x24, x23, [sp, #0x170]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1b0; stp x28, x27, [sp, #0x150]; stp x26, x25, [sp, #0x160]; stp x24, x23, [sp, #0x170]]
uint64_t fde_sub_067b88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9156FFCULL) << 32) | 0xD106C3FFULL;
    const uint64_t kPcRange = 0x02B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067B88ULL;
}

// FDE #0861 | PC: 0x067e3c..0x067e9c (96 B) | Symbol: sub_067e3c
// EN: AArch64 prologue [sub w8, w2, #1; adrp x9, #0x7e000; cmp w8, #0xbf; add x9, x9, #0xa84] | VI: Khởi đầu hàm AArch64 [sub w8, w2, #1; adrp x9, #0x7e000; cmp w8, #0xbf; add x9, x9, #0xa84]
uint64_t fde_sub_067e3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00000A9ULL) << 32) | 0x51000448ULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067E3CULL;
}

// FDE #0862 | PC: 0x067e9c..0x067f6c (208 B) | Symbol: sub_067e9c
// EN: AArch64 prologue [mov x4, x30; bl #0x69f4c; mov x30, x4; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x4, x30; bl #0x69f4c; mov x30, x4; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_067e9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400082BULL) << 32) | 0xAA1E03E4ULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067E9CULL;
}

// FDE #0863 | PC: 0x067f6c..0x067f9c (48 B) | Symbol: sub_067f6c
// EN: AArch64 prologue [mov x9, xzr; sxtw x8, w2; strb w0, [x3], #1; add x10, x9, #1] | VI: Khởi đầu hàm AArch64 [mov x9, xzr; sxtw x8, w2; strb w0, [x3], #1; add x10, x9, #1]
uint64_t fde_sub_067f6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x93407C48ULL) << 32) | 0xAA1F03E9ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067F6CULL;
}

// FDE #0864 | PC: 0x067f9c..0x068008 (108 B) | Symbol: _Z21FDKsbrEnc_UpdateHiResPhPiS_iS0_
// EN: AArch64 prologue [ldrsw x9, [x4]; sxtw x8, w3; cmp w9, w3; b.gt #0x67fb8] | VI: Khởi đầu hàm AArch64 [ldrsw x9, [x4]; sxtw x8, w3; cmp w9, w3; b.gt #0x67fb8]
uint64_t fde_sub_067f9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x93407C68ULL) << 32) | 0xB9800089ULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067F9CULL;
}

// FDE #0865 | PC: 0x068008..0x06807c (116 B) | Symbol: _Z21FDKsbrEnc_UpdateLoResPhPiS_i
// EN: AArch64 prologue [tbnz w3, #0, #0x68038; mov w9, #2; mov x8, xzr; sdiv w9, w3, w9] | VI: Khởi đầu hàm AArch64 [tbnz w3, #0, #0x68038; mov w9, #2; mov x8, xzr; sdiv w9, w3, w9]
uint64_t fde_sub_068008(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800049ULL) << 32) | 0x37000183ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068008ULL;
}

// FDE #0866 | PC: 0x06807c..0x068644 (1480 B) | Symbol: _Z33FDKsbrEnc_CalculateTonalityQuotasP16SBR_TON_CORR_ESTPPiS2_ii
// EN: AArch64 prologue [mov x5, x30; bl #0x69f18; mov x30, x5; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x5, x30; bl #0x69f18; mov x30, x5; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_06807c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940007A6ULL) << 32) | 0xAA1E03E5ULL;
    const uint64_t kPcRange = 0x05C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06807CULL;
}

// FDE #0867 | PC: 0x068644..0x0687cc (392 B) | Symbol: _Z26FDKsbrEnc_TonCorrParamExtrP16SBR_TON_CORR_ESTP9INVF_MODEPiS3_PhS4_PK14SBR_FRAME_INFOS4_S4_i9XPOS_MODEj
// EN: AArch64 prologue [mov x8, x30; bl #0x6a084; mov x30, x8; stp x29, x30, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x6a084; mov x30, x8; stp x29, x30, [sp, #0x70]]
uint64_t fde_sub_068644(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400068FULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x0188ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068644ULL;
}

// FDE #0868 | PC: 0x0687cc..0x068844 (120 B) | Symbol: _Z32FDKsbrEnc_CreateTonCorrParamExtrP16SBR_TON_CORR_ESTi
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0687cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0687CCULL;
}

// FDE #0869 | PC: 0x068844..0x068a30 (492 B) | Symbol: _Z30FDKsbrEnc_InitTonCorrParamExtriP16SBR_TON_CORR_ESTP15SBR_CONFIG_DATAiiiiij
// EN: AArch64 prologue [mov x8, x30; bl #0x6a160; mov x30, x8; stp x29, x30, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x6a160; mov x30, x8; stp x29, x30, [sp, #0x80]]
uint64_t fde_sub_068844(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94000646ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x01ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068844ULL;
}

// FDE #0870 | PC: 0x068a30..0x068c34 (516 B) | Symbol: sub_068a30
// EN: AArch64 prologue [mov x7, x30; bl #0x69f4c; mov x30, x7; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x7, x30; bl #0x69f4c; mov x30, x7; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_068a30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94000546ULL) << 32) | 0xAA1E03E7ULL;
    const uint64_t kPcRange = 0x0204ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068A30ULL;
}

// FDE #0871 | PC: 0x068c34..0x068c94 (96 B) | Symbol: sub_068c34
// EN: AArch64 prologue [ldrb w10, [x1]; cmp w10, w0; mov w8, w10; b.ge #0x68c90] | VI: Khởi đầu hàm AArch64 [ldrb w10, [x1]; cmp w10, w0; mov w8, w10; b.ge #0x68c90]
uint64_t fde_sub_068c34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6B00015FULL) << 32) | 0x3940002AULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068C34ULL;
}

// FDE #0872 | PC: 0x068c94..0x068d0c (120 B) | Symbol: _Z31FDKsbrEnc_ResetTonCorrParamExtrP16SBR_TON_CORR_ESTiiPhiiPS1_Pii
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_068c94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068C94ULL;
}

// FDE #0873 | PC: 0x068d0c..0x068d44 (56 B) | Symbol: _Z32FDKsbrEnc_DeleteTonCorrParamExtrP16SBR_TON_CORR_EST
// EN: AArch64 prologue [cbz x0, #0x68d40; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x68d40; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10]
uint64_t fde_sub_068d0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0xB40001A0ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068D0CULL;
}

// FDE #0874 | PC: 0x068d44..0x06932c (1512 B) | Symbol: _Z23FDKsbrEnc_frameSplitterPPiS_P22SBR_TRANSIENT_DETECTORPhS3_iiiiiS_
// EN: AArch64 prologue [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_068d44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94000474ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x05E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068D44ULL;
}

// FDE #0875 | PC: 0x06932c..0x069928 (1532 B) | Symbol: _Z25FDKsbrEnc_transientDetectP22SBR_TRANSIENT_DETECTORPPiS1_Phiiii
// EN: AArch64 prologue [sub sp, sp, #0x1d0; stp x28, x27, [sp, #0x170]; stp x26, x25, [sp, #0x180]; stp x24, x23, [sp, #0x190]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1d0; stp x28, x27, [sp, #0x170]; stp x26, x25, [sp, #0x180]; stp x24, x23, [sp, #0x190]]
uint64_t fde_sub_06932c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9176FFCULL) << 32) | 0xD10743FFULL;
    const uint64_t kPcRange = 0x05FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06932CULL;
}

// FDE #0876 | PC: 0x069928..0x069a48 (288 B) | Symbol: _Z34FDKsbrEnc_InitSbrTransientDetectorP22SBR_TRANSIENT_DETECTORjiiP16sbrConfigurationiiiiiii
// EN: AArch64 prologue [mov x8, x30; bl #0x6a084; mov x30, x8; stp x29, x30, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x6a084; mov x30, x8; stp x29, x30, [sp, #0x70]]
uint64_t fde_sub_069928(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940001D6ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x0120ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069928ULL;
}

// FDE #0877 | PC: 0x069a48..0x069bac (356 B) | Symbol: _Z38FDKsbrEnc_InitSbrFastTransientDetectorP18FAST_TRAN_DETECTORiiii
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; mov x5, x30; bl #0x69fa8; mov x30, x5] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; mov x5, x30; bl #0x69fa8; mov x30, x5]
uint64_t fde_sub_069a48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E5ULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x0164ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069A48ULL;
}

// FDE #0878 | PC: 0x069bac..0x069edc (816 B) | Symbol: _Z29FDKsbrEnc_fastTransientDetectP18FAST_TRAN_DETECTORPKPKiS2_iPh
// EN: AArch64 prologue [mov x5, x30; bl #0x6ab14; mov x30, x5; stp x29, x30, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [mov x5, x30; bl #0x6ab14; mov x30, x5; stp x29, x30, [sp, #0xa0]]
uint64_t fde_sub_069bac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940003D9ULL) << 32) | 0xAA1E03E5ULL;
    const uint64_t kPcRange = 0x0330ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069BACULL;
}

// FDE #0879 | PC: 0x069edc..0x069ee4 (8 B) | Symbol: sub_069edc
// EN: AArch64 prologue [mov x0, x20; b #0x1d1d8] | VI: Khởi đầu hàm AArch64 [mov x0, x20; b #0x1d1d8]
uint64_t fde_sub_069edc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FECCBEULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069EDCULL;
}

// FDE #0880 | PC: 0x069ee4..0x069efc (24 B) | Symbol: sub_069ee4
// EN: AArch64 prologue [ldp x20, x19, [sp, #0x40]; ldp x22, x21, [sp, #0x30]; ldp x24, x23, [sp, #0x20]; ldp x26, x25, [sp, #0x10]] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0x40]; ldp x22, x21, [sp, #0x30]; ldp x24, x23, [sp, #0x20]; ldp x26, x25, [sp, #0x10]]
uint64_t fde_sub_069ee4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94357F6ULL) << 32) | 0xA9444FF4ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069EE4ULL;
}

// FDE #0881 | PC: 0x069efc..0x069f08 (12 B) | Symbol: sub_069efc
// EN: AArch64 prologue [mov x19, x0; ldr x0, [x0]; b #0x1a928] | VI: Khởi đầu hàm AArch64 [mov x19, x0; ldr x0, [x0]; b #0x1a928]
uint64_t fde_sub_069efc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400000ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069EFCULL;
}

// FDE #0882 | PC: 0x069f08..0x069f10 (8 B) | Symbol: sub_069f08
// EN: AArch64 prologue [mov x0, x19; b #0x1d1d8] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x1d1d8]
uint64_t fde_sub_069f08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FECCB3ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069F08ULL;
}

// FDE #0883 | PC: 0x069f10..0x069f18 (8 B) | Symbol: sub_069f10
// EN: AArch64 prologue [mov x0, x19; b #0x322bc] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x322bc]
uint64_t fde_sub_069f10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF20EAULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069F10ULL;
}

// FDE #0884 | PC: 0x069f18..0x069f30 (24 B) | Symbol: sub_069f18
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_069f18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069F18ULL;
}

uint64_t DispatchFdeShard3(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x04e194ULL: return fde_sub_04e194(a0, a1, a2);
        case 0x04e1b0ULL: return fde_sub_04e1b0(a0, a1, a2);
        case 0x04e3a8ULL: return fde_sub_04e3a8(a0, a1, a2);
        case 0x04e3e0ULL: return fde_sub_04e3e0(a0, a1, a2);
        case 0x04e418ULL: return fde_sub_04e418(a0, a1, a2);
        case 0x04e4acULL: return fde_sub_04e4ac(a0, a1, a2);
        case 0x04e808ULL: return fde_sub_04e808(a0, a1, a2);
        case 0x04e84cULL: return fde_sub_04e84c(a0, a1, a2);
        case 0x04e8acULL: return fde_sub_04e8ac(a0, a1, a2);
        case 0x04ed84ULL: return fde_sub_04ed84(a0, a1, a2);
        case 0x04ee18ULL: return fde_sub_04ee18(a0, a1, a2);
        case 0x04f044ULL: return fde_sub_04f044(a0, a1, a2);
        case 0x04f0fcULL: return fde_sub_04f0fc(a0, a1, a2);
        case 0x04f1f8ULL: return fde_sub_04f1f8(a0, a1, a2);
        case 0x04f220ULL: return fde_sub_04f220(a0, a1, a2);
        case 0x04f304ULL: return fde_sub_04f304(a0, a1, a2);
        case 0x04f42cULL: return fde_sub_04f42c(a0, a1, a2);
        case 0x04f438ULL: return fde_sub_04f438(a0, a1, a2);
        case 0x04f440ULL: return fde_sub_04f440(a0, a1, a2);
        case 0x04f480ULL: return fde_sub_04f480(a0, a1, a2);
        case 0x04f61cULL: return fde_sub_04f61c(a0, a1, a2);
        case 0x04f624ULL: return fde_sub_04f624(a0, a1, a2);
        case 0x04f63cULL: return fde_sub_04f63c(a0, a1, a2);
        case 0x04f84cULL: return fde_sub_04f84c(a0, a1, a2);
        case 0x04f8e0ULL: return fde_sub_04f8e0(a0, a1, a2);
        case 0x04f9b4ULL: return fde_sub_04f9b4(a0, a1, a2);
        case 0x04fa44ULL: return fde_sub_04fa44(a0, a1, a2);
        case 0x04fa58ULL: return fde_sub_04fa58(a0, a1, a2);
        case 0x04fa7cULL: return fde_sub_04fa7c(a0, a1, a2);
        case 0x04faa0ULL: return fde_sub_04faa0(a0, a1, a2);
        case 0x04fb10ULL: return fde_sub_04fb10(a0, a1, a2);
        case 0x04fb7cULL: return fde_sub_04fb7c(a0, a1, a2);
        case 0x04ff04ULL: return fde_sub_04ff04(a0, a1, a2);
        case 0x04ff68ULL: return fde_sub_04ff68(a0, a1, a2);
        case 0x04ffdcULL: return fde_sub_04ffdc(a0, a1, a2);
        case 0x051f30ULL: return fde_sub_051f30(a0, a1, a2);
        case 0x051f60ULL: return fde_sub_051f60(a0, a1, a2);
        case 0x051ffcULL: return fde_sub_051ffc(a0, a1, a2);
        case 0x0520b4ULL: return fde_sub_0520b4(a0, a1, a2);
        case 0x052134ULL: return fde_sub_052134(a0, a1, a2);
        case 0x052184ULL: return fde_sub_052184(a0, a1, a2);
        case 0x05219cULL: return fde_sub_05219c(a0, a1, a2);
        case 0x0521a0ULL: return fde_sub_0521a0(a0, a1, a2);
        case 0x05241cULL: return fde_sub_05241c(a0, a1, a2);
        case 0x052650ULL: return fde_sub_052650(a0, a1, a2);
        case 0x052a0cULL: return fde_sub_052a0c(a0, a1, a2);
        case 0x052b84ULL: return fde_sub_052b84(a0, a1, a2);
        case 0x052bfcULL: return fde_sub_052bfc(a0, a1, a2);
        case 0x052c7cULL: return fde_sub_052c7c(a0, a1, a2);
        case 0x052d80ULL: return fde_sub_052d80(a0, a1, a2);
        case 0x052ddcULL: return fde_sub_052ddc(a0, a1, a2);
        case 0x052e9cULL: return fde_sub_052e9c(a0, a1, a2);
        case 0x052efcULL: return fde_sub_052efc(a0, a1, a2);
        case 0x053064ULL: return fde_sub_053064(a0, a1, a2);
        case 0x0530e8ULL: return fde_sub_0530e8(a0, a1, a2);
        case 0x0531e4ULL: return fde_sub_0531e4(a0, a1, a2);
        case 0x053808ULL: return fde_sub_053808(a0, a1, a2);
        case 0x05393cULL: return fde_sub_05393c(a0, a1, a2);
        case 0x0539acULL: return fde_sub_0539ac(a0, a1, a2);
        case 0x053bb0ULL: return fde_sub_053bb0(a0, a1, a2);
        case 0x053cbcULL: return fde_sub_053cbc(a0, a1, a2);
        case 0x053dd0ULL: return fde_sub_053dd0(a0, a1, a2);
        case 0x053fb8ULL: return fde_sub_053fb8(a0, a1, a2);
        case 0x054000ULL: return fde_sub_054000(a0, a1, a2);
        case 0x054d98ULL: return fde_sub_054d98(a0, a1, a2);
        case 0x054df8ULL: return fde_sub_054df8(a0, a1, a2);
        case 0x055054ULL: return fde_sub_055054(a0, a1, a2);
        case 0x0550c4ULL: return fde_sub_0550c4(a0, a1, a2);
        case 0x055600ULL: return fde_sub_055600(a0, a1, a2);
        case 0x055700ULL: return fde_sub_055700(a0, a1, a2);
        case 0x055860ULL: return fde_sub_055860(a0, a1, a2);
        case 0x055c40ULL: return fde_sub_055c40(a0, a1, a2);
        case 0x055c8cULL: return fde_sub_055c8c(a0, a1, a2);
        case 0x055d78ULL: return fde_sub_055d78(a0, a1, a2);
        case 0x055ea8ULL: return fde_sub_055ea8(a0, a1, a2);
        case 0x055f4cULL: return fde_sub_055f4c(a0, a1, a2);
        case 0x055f74ULL: return fde_sub_055f74(a0, a1, a2);
        case 0x0563fcULL: return fde_sub_0563fc(a0, a1, a2);
        case 0x05644cULL: return fde_sub_05644c(a0, a1, a2);
        case 0x05677cULL: return fde_sub_05677c(a0, a1, a2);
        case 0x056820ULL: return fde_sub_056820(a0, a1, a2);
        case 0x057308ULL: return fde_sub_057308(a0, a1, a2);
        case 0x057344ULL: return fde_sub_057344(a0, a1, a2);
        case 0x0573ccULL: return fde_sub_0573cc(a0, a1, a2);
        case 0x057bd8ULL: return fde_sub_057bd8(a0, a1, a2);
        case 0x057c40ULL: return fde_sub_057c40(a0, a1, a2);
        case 0x057cf8ULL: return fde_sub_057cf8(a0, a1, a2);
        case 0x057d58ULL: return fde_sub_057d58(a0, a1, a2);
        case 0x05865cULL: return fde_sub_05865c(a0, a1, a2);
        case 0x05876cULL: return fde_sub_05876c(a0, a1, a2);
        case 0x0588f4ULL: return fde_sub_0588f4(a0, a1, a2);
        case 0x058930ULL: return fde_sub_058930(a0, a1, a2);
        case 0x058c50ULL: return fde_sub_058c50(a0, a1, a2);
        case 0x058c5cULL: return fde_sub_058c5c(a0, a1, a2);
        case 0x058c64ULL: return fde_sub_058c64(a0, a1, a2);
        case 0x058c70ULL: return fde_sub_058c70(a0, a1, a2);
        case 0x058c78ULL: return fde_sub_058c78(a0, a1, a2);
        case 0x058c84ULL: return fde_sub_058c84(a0, a1, a2);
        case 0x058c8cULL: return fde_sub_058c8c(a0, a1, a2);
        case 0x058c94ULL: return fde_sub_058c94(a0, a1, a2);
        case 0x058c9cULL: return fde_sub_058c9c(a0, a1, a2);
        case 0x058ca4ULL: return fde_sub_058ca4(a0, a1, a2);
        case 0x058cacULL: return fde_sub_058cac(a0, a1, a2);
        case 0x058cb8ULL: return fde_sub_058cb8(a0, a1, a2);
        case 0x058cc0ULL: return fde_sub_058cc0(a0, a1, a2);
        case 0x058d20ULL: return fde_sub_058d20(a0, a1, a2);
        case 0x058d88ULL: return fde_sub_058d88(a0, a1, a2);
        case 0x059234ULL: return fde_sub_059234(a0, a1, a2);
        case 0x0592d0ULL: return fde_sub_0592d0(a0, a1, a2);
        case 0x059754ULL: return fde_sub_059754(a0, a1, a2);
        case 0x059834ULL: return fde_sub_059834(a0, a1, a2);
        case 0x0598c0ULL: return fde_sub_0598c0(a0, a1, a2);
        case 0x0598e4ULL: return fde_sub_0598e4(a0, a1, a2);
        case 0x059948ULL: return fde_sub_059948(a0, a1, a2);
        case 0x05998cULL: return fde_sub_05998c(a0, a1, a2);
        case 0x059a18ULL: return fde_sub_059a18(a0, a1, a2);
        case 0x059b8cULL: return fde_sub_059b8c(a0, a1, a2);
        case 0x059bf0ULL: return fde_sub_059bf0(a0, a1, a2);
        case 0x059fe4ULL: return fde_sub_059fe4(a0, a1, a2);
        case 0x05a024ULL: return fde_sub_05a024(a0, a1, a2);
        case 0x05a09cULL: return fde_sub_05a09c(a0, a1, a2);
        case 0x05a1b0ULL: return fde_sub_05a1b0(a0, a1, a2);
        case 0x05a224ULL: return fde_sub_05a224(a0, a1, a2);
        case 0x05a278ULL: return fde_sub_05a278(a0, a1, a2);
        case 0x05a3b0ULL: return fde_sub_05a3b0(a0, a1, a2);
        case 0x05a4ccULL: return fde_sub_05a4cc(a0, a1, a2);
        case 0x05a58cULL: return fde_sub_05a58c(a0, a1, a2);
        case 0x05a5c8ULL: return fde_sub_05a5c8(a0, a1, a2);
        case 0x05ae08ULL: return fde_sub_05ae08(a0, a1, a2);
        case 0x05b3f0ULL: return fde_sub_05b3f0(a0, a1, a2);
        case 0x05b474ULL: return fde_sub_05b474(a0, a1, a2);
        case 0x05b4ecULL: return fde_sub_05b4ec(a0, a1, a2);
        case 0x05b570ULL: return fde_sub_05b570(a0, a1, a2);
        case 0x05b5e0ULL: return fde_sub_05b5e0(a0, a1, a2);
        case 0x05b638ULL: return fde_sub_05b638(a0, a1, a2);
        case 0x05b928ULL: return fde_sub_05b928(a0, a1, a2);
        case 0x05bb88ULL: return fde_sub_05bb88(a0, a1, a2);
        case 0x05bc10ULL: return fde_sub_05bc10(a0, a1, a2);
        case 0x05bc98ULL: return fde_sub_05bc98(a0, a1, a2);
        case 0x05be28ULL: return fde_sub_05be28(a0, a1, a2);
        case 0x05bfd0ULL: return fde_sub_05bfd0(a0, a1, a2);
        case 0x05c038ULL: return fde_sub_05c038(a0, a1, a2);
        case 0x05c114ULL: return fde_sub_05c114(a0, a1, a2);
        case 0x05c134ULL: return fde_sub_05c134(a0, a1, a2);
        case 0x05c25cULL: return fde_sub_05c25c(a0, a1, a2);
        case 0x05c2d4ULL: return fde_sub_05c2d4(a0, a1, a2);
        case 0x05c354ULL: return fde_sub_05c354(a0, a1, a2);
        case 0x05c3a0ULL: return fde_sub_05c3a0(a0, a1, a2);
        case 0x05c594ULL: return fde_sub_05c594(a0, a1, a2);
        case 0x05c9dcULL: return fde_sub_05c9dc(a0, a1, a2);
        case 0x05ca5cULL: return fde_sub_05ca5c(a0, a1, a2);
        case 0x05cad0ULL: return fde_sub_05cad0(a0, a1, a2);
        case 0x05cb34ULL: return fde_sub_05cb34(a0, a1, a2);
        case 0x05cbccULL: return fde_sub_05cbcc(a0, a1, a2);
        case 0x05cd30ULL: return fde_sub_05cd30(a0, a1, a2);
        case 0x05d278ULL: return fde_sub_05d278(a0, a1, a2);
        case 0x05e2acULL: return fde_sub_05e2ac(a0, a1, a2);
        case 0x05e2f0ULL: return fde_sub_05e2f0(a0, a1, a2);
        case 0x05e980ULL: return fde_sub_05e980(a0, a1, a2);
        case 0x05ea04ULL: return fde_sub_05ea04(a0, a1, a2);
        case 0x05eb4cULL: return fde_sub_05eb4c(a0, a1, a2);
        case 0x05ebd4ULL: return fde_sub_05ebd4(a0, a1, a2);
        case 0x05ecf0ULL: return fde_sub_05ecf0(a0, a1, a2);
        case 0x05ed44ULL: return fde_sub_05ed44(a0, a1, a2);
        case 0x05ede8ULL: return fde_sub_05ede8(a0, a1, a2);
        case 0x05eea4ULL: return fde_sub_05eea4(a0, a1, a2);
        case 0x05efccULL: return fde_sub_05efcc(a0, a1, a2);
        case 0x05efdcULL: return fde_sub_05efdc(a0, a1, a2);
        case 0x05eff8ULL: return fde_sub_05eff8(a0, a1, a2);
        case 0x05ff40ULL: return fde_sub_05ff40(a0, a1, a2);
        case 0x05ffccULL: return fde_sub_05ffcc(a0, a1, a2);
        case 0x060098ULL: return fde_sub_060098(a0, a1, a2);
        case 0x060134ULL: return fde_sub_060134(a0, a1, a2);
        case 0x060194ULL: return fde_sub_060194(a0, a1, a2);
        case 0x060218ULL: return fde_sub_060218(a0, a1, a2);
        case 0x06048cULL: return fde_sub_06048c(a0, a1, a2);
        case 0x060584ULL: return fde_sub_060584(a0, a1, a2);
        case 0x060ab4ULL: return fde_sub_060ab4(a0, a1, a2);
        case 0x060b18ULL: return fde_sub_060b18(a0, a1, a2);
        case 0x060bb8ULL: return fde_sub_060bb8(a0, a1, a2);
        case 0x060bf0ULL: return fde_sub_060bf0(a0, a1, a2);
        case 0x0619e8ULL: return fde_sub_0619e8(a0, a1, a2);
        case 0x061c18ULL: return fde_sub_061c18(a0, a1, a2);
        case 0x061cb8ULL: return fde_sub_061cb8(a0, a1, a2);
        case 0x061df4ULL: return fde_sub_061df4(a0, a1, a2);
        case 0x061e48ULL: return fde_sub_061e48(a0, a1, a2);
        case 0x062150ULL: return fde_sub_062150(a0, a1, a2);
        case 0x062658ULL: return fde_sub_062658(a0, a1, a2);
        case 0x062768ULL: return fde_sub_062768(a0, a1, a2);
        case 0x062894ULL: return fde_sub_062894(a0, a1, a2);
        case 0x062958ULL: return fde_sub_062958(a0, a1, a2);
        case 0x0629e8ULL: return fde_sub_0629e8(a0, a1, a2);
        case 0x062a80ULL: return fde_sub_062a80(a0, a1, a2);
        case 0x062aa8ULL: return fde_sub_062aa8(a0, a1, a2);
        case 0x062b1cULL: return fde_sub_062b1c(a0, a1, a2);
        case 0x062b74ULL: return fde_sub_062b74(a0, a1, a2);
        case 0x062bccULL: return fde_sub_062bcc(a0, a1, a2);
        case 0x062eb0ULL: return fde_sub_062eb0(a0, a1, a2);
        case 0x062fc4ULL: return fde_sub_062fc4(a0, a1, a2);
        case 0x06304cULL: return fde_sub_06304c(a0, a1, a2);
        case 0x063090ULL: return fde_sub_063090(a0, a1, a2);
        case 0x0631c4ULL: return fde_sub_0631c4(a0, a1, a2);
        case 0x0631dcULL: return fde_sub_0631dc(a0, a1, a2);
        case 0x064024ULL: return fde_sub_064024(a0, a1, a2);
        case 0x0640a0ULL: return fde_sub_0640a0(a0, a1, a2);
        case 0x064318ULL: return fde_sub_064318(a0, a1, a2);
        case 0x064348ULL: return fde_sub_064348(a0, a1, a2);
        case 0x0643d4ULL: return fde_sub_0643d4(a0, a1, a2);
        case 0x064464ULL: return fde_sub_064464(a0, a1, a2);
        case 0x06461cULL: return fde_sub_06461c(a0, a1, a2);
        case 0x064650ULL: return fde_sub_064650(a0, a1, a2);
        case 0x064660ULL: return fde_sub_064660(a0, a1, a2);
        case 0x064e98ULL: return fde_sub_064e98(a0, a1, a2);
        case 0x064f24ULL: return fde_sub_064f24(a0, a1, a2);
        case 0x0650c4ULL: return fde_sub_0650c4(a0, a1, a2);
        case 0x0651d0ULL: return fde_sub_0651d0(a0, a1, a2);
        case 0x065670ULL: return fde_sub_065670(a0, a1, a2);
        case 0x06572cULL: return fde_sub_06572c(a0, a1, a2);
        case 0x065900ULL: return fde_sub_065900(a0, a1, a2);
        case 0x06590cULL: return fde_sub_06590c(a0, a1, a2);
        case 0x0659b0ULL: return fde_sub_0659b0(a0, a1, a2);
        case 0x065a90ULL: return fde_sub_065a90(a0, a1, a2);
        case 0x065bc4ULL: return fde_sub_065bc4(a0, a1, a2);
        case 0x065bd0ULL: return fde_sub_065bd0(a0, a1, a2);
        case 0x067124ULL: return fde_sub_067124(a0, a1, a2);
        case 0x0671c8ULL: return fde_sub_0671c8(a0, a1, a2);
        case 0x0672a0ULL: return fde_sub_0672a0(a0, a1, a2);
        case 0x0672acULL: return fde_sub_0672ac(a0, a1, a2);
        case 0x0672bcULL: return fde_sub_0672bc(a0, a1, a2);
        case 0x067334ULL: return fde_sub_067334(a0, a1, a2);
        case 0x0673c4ULL: return fde_sub_0673c4(a0, a1, a2);
        case 0x067400ULL: return fde_sub_067400(a0, a1, a2);
        case 0x067430ULL: return fde_sub_067430(a0, a1, a2);
        case 0x067444ULL: return fde_sub_067444(a0, a1, a2);
        case 0x067478ULL: return fde_sub_067478(a0, a1, a2);
        case 0x067544ULL: return fde_sub_067544(a0, a1, a2);
        case 0x06754cULL: return fde_sub_06754c(a0, a1, a2);
        case 0x067554ULL: return fde_sub_067554(a0, a1, a2);
        case 0x067560ULL: return fde_sub_067560(a0, a1, a2);
        case 0x067568ULL: return fde_sub_067568(a0, a1, a2);
        case 0x067574ULL: return fde_sub_067574(a0, a1, a2);
        case 0x067580ULL: return fde_sub_067580(a0, a1, a2);
        case 0x06758cULL: return fde_sub_06758c(a0, a1, a2);
        case 0x067594ULL: return fde_sub_067594(a0, a1, a2);
        case 0x06759cULL: return fde_sub_06759c(a0, a1, a2);
        case 0x0675a4ULL: return fde_sub_0675a4(a0, a1, a2);
        case 0x0675acULL: return fde_sub_0675ac(a0, a1, a2);
        case 0x0675b4ULL: return fde_sub_0675b4(a0, a1, a2);
        case 0x0675bcULL: return fde_sub_0675bc(a0, a1, a2);
        case 0x0675c4ULL: return fde_sub_0675c4(a0, a1, a2);
        case 0x0675ccULL: return fde_sub_0675cc(a0, a1, a2);
        case 0x0675d4ULL: return fde_sub_0675d4(a0, a1, a2);
        case 0x0675dcULL: return fde_sub_0675dc(a0, a1, a2);
        case 0x0675e4ULL: return fde_sub_0675e4(a0, a1, a2);
        case 0x0675ecULL: return fde_sub_0675ec(a0, a1, a2);
        case 0x0675f4ULL: return fde_sub_0675f4(a0, a1, a2);
        case 0x0675fcULL: return fde_sub_0675fc(a0, a1, a2);
        case 0x067604ULL: return fde_sub_067604(a0, a1, a2);
        case 0x067610ULL: return fde_sub_067610(a0, a1, a2);
        case 0x067618ULL: return fde_sub_067618(a0, a1, a2);
        case 0x067624ULL: return fde_sub_067624(a0, a1, a2);
        case 0x06762cULL: return fde_sub_06762c(a0, a1, a2);
        case 0x067634ULL: return fde_sub_067634(a0, a1, a2);
        case 0x067644ULL: return fde_sub_067644(a0, a1, a2);
        case 0x067650ULL: return fde_sub_067650(a0, a1, a2);
        case 0x067660ULL: return fde_sub_067660(a0, a1, a2);
        case 0x067698ULL: return fde_sub_067698(a0, a1, a2);
        case 0x0677a0ULL: return fde_sub_0677a0(a0, a1, a2);
        case 0x0677d8ULL: return fde_sub_0677d8(a0, a1, a2);
        case 0x067aacULL: return fde_sub_067aac(a0, a1, a2);
        case 0x067b88ULL: return fde_sub_067b88(a0, a1, a2);
        case 0x067e3cULL: return fde_sub_067e3c(a0, a1, a2);
        case 0x067e9cULL: return fde_sub_067e9c(a0, a1, a2);
        case 0x067f6cULL: return fde_sub_067f6c(a0, a1, a2);
        case 0x067f9cULL: return fde_sub_067f9c(a0, a1, a2);
        case 0x068008ULL: return fde_sub_068008(a0, a1, a2);
        case 0x06807cULL: return fde_sub_06807c(a0, a1, a2);
        case 0x068644ULL: return fde_sub_068644(a0, a1, a2);
        case 0x0687ccULL: return fde_sub_0687cc(a0, a1, a2);
        case 0x068844ULL: return fde_sub_068844(a0, a1, a2);
        case 0x068a30ULL: return fde_sub_068a30(a0, a1, a2);
        case 0x068c34ULL: return fde_sub_068c34(a0, a1, a2);
        case 0x068c94ULL: return fde_sub_068c94(a0, a1, a2);
        case 0x068d0cULL: return fde_sub_068d0c(a0, a1, a2);
        case 0x068d44ULL: return fde_sub_068d44(a0, a1, a2);
        case 0x06932cULL: return fde_sub_06932c(a0, a1, a2);
        case 0x069928ULL: return fde_sub_069928(a0, a1, a2);
        case 0x069a48ULL: return fde_sub_069a48(a0, a1, a2);
        case 0x069bacULL: return fde_sub_069bac(a0, a1, a2);
        case 0x069edcULL: return fde_sub_069edc(a0, a1, a2);
        case 0x069ee4ULL: return fde_sub_069ee4(a0, a1, a2);
        case 0x069efcULL: return fde_sub_069efc(a0, a1, a2);
        case 0x069f08ULL: return fde_sub_069f08(a0, a1, a2);
        case 0x069f10ULL: return fde_sub_069f10(a0, a1, a2);
        case 0x069f18ULL: return fde_sub_069f18(a0, a1, a2);
        default: return 0ULL;
    }
}

} // namespace fdk_aac
} // namespace opencut
