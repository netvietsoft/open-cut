// ============================================================================
// File: fdk_aac_fde_shard_2.cpp
// Target 105 / 169: libfdk-aac.so (625,312 bytes)
// EN: Clean-room C++17 AArch64 FDE Shard 2/5 covering FDEs [295..589]
//     (PC range 0x038004 .. 0x04e194).
// VI: Phân mảnh FDE AArch64 C++17 2/5 bao phủ các FDE [295..589]
//     (Dải địa chỉ PC 0x038004 .. 0x04e194).
// ============================================================================
#include "fdk_aac_codec_core.h"

namespace opencut {
namespace fdk_aac {

// FDE #0295 | PC: 0x038004..0x038304 (768 B) | Symbol: _Z28FDKaacEnc_MsStereoProcessingPP8PSY_DATAPP15PSY_OUT_CHANNELPKiPiS7_iiiS6_
// EN: AArch64 prologue [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_038004(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400C7C4ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x0300ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038004ULL;
}

// FDE #0296 | PC: 0x038304..0x0384d4 (464 B) | Symbol: _Z21FDKaacEnc_noiseDetectPiS_iPKiPsP11NOISEPARAMSS2_
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_038304(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BC67FAULL;
    const uint64_t kPcRange = 0x01D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038304ULL;
}

// FDE #0297 | PC: 0x0384d4..0x0385e4 (272 B) | Symbol: _Z22FDKaacEnc_lookUpPnsUseiiii
// EN: AArch64 prologue [cbz w3, #0x384e8; adrp x8, #0x78000; add x8, x8, #0x788; mov w9, #5] | VI: Khởi đầu hàm AArch64 [cbz w3, #0x384e8; adrp x8, #0x78000; add x8, x8, #0x788; mov w9, #5]
uint64_t fde_sub_0384d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000208ULL) << 32) | 0x340000A3ULL;
    const uint64_t kPcRange = 0x0110ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0384D4ULL;
}

// FDE #0298 | PC: 0x0385e4..0x038754 (368 B) | Symbol: _Z21FDKaacEnc_GetPnsParamP11NOISEPARAMSiiiPKiPiii
// EN: AArch64 prologue [mov x8, x30; bl #0x6a250; mov x30, x8; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x6a250; mov x30, x8; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_0385e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400C71AULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0385E4ULL;
}

// FDE #0299 | PC: 0x038754..0x038788 (52 B) | Symbol: _Z28FDKaacEnc_InitPreEchoControlPiS_iS_S_
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1]
uint64_t fde_sub_038754(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038754ULL;
}

// FDE #0300 | PC: 0x038788..0x03888c (260 B) | Symbol: _Z24FDKaacEnc_PreEchoControlPiiiisS_iS_
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x7] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x7]
uint64_t fde_sub_038788(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038788ULL;
}

// FDE #0301 | PC: 0x03888c..0x038ec8 (1596 B) | Symbol: _Z30FDKaacEnc_InitPsyConfigurationiiiiiiP17PSY_CONFIGURATION7FB_TYPE
// EN: AArch64 prologue [sub sp, sp, #0x180; stp x28, x27, [sp, #0x120]; stp x26, x25, [sp, #0x130]; stp x24, x23, [sp, #0x140]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x180; stp x28, x27, [sp, #0x120]; stp x26, x25, [sp, #0x130]; stp x24, x23, [sp, #0x140]]
uint64_t fde_sub_03888c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9126FFCULL) << 32) | 0xD10603FFULL;
    const uint64_t kPcRange = 0x063CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03888CULL;
}

// FDE #0302 | PC: 0x038ec8..0x038f9c (212 B) | Symbol: sub_038ec8
// EN: AArch64 prologue [cmp w0, #0x80; mul w8, w2, w1; b.eq #0x38ef4; cmp w0, #0x1e0] | VI: Khởi đầu hàm AArch64 [cmp w0, #0x80; mul w8, w2, w1; b.eq #0x38ef4; cmp w0, #0x1e0]
uint64_t fde_sub_038ec8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1B017C48ULL) << 32) | 0x7102001FULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038EC8ULL;
}

// FDE #0303 | PC: 0x038f9c..0x039014 (120 B) | Symbol: sub_038f9c
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; neg w2, w0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; neg w2, w0]
uint64_t fde_sub_038f9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x038F9CULL;
}

// FDE #0304 | PC: 0x039014..0x0390d8 (196 B) | Symbol: _Z16FDKaacEnc_PsyNewPP12PSY_INTERNALiiPh
// EN: AArch64 prologue [mov x4, x30; bl #0x6a250; mov x30, x4; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x4, x30; bl #0x6a250; mov x30, x4; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_039014(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400C48EULL) << 32) | 0xAA1E03E4ULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x039014ULL;
}

// FDE #0305 | PC: 0x0390d8..0x0391e4 (268 B) | Symbol: _Z18FDKaacEnc_PsyClosePP12PSY_INTERNALPP7PSY_OUT
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0390d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0390D8ULL;
}

// FDE #0306 | PC: 0x0391e4..0x039298 (180 B) | Symbol: _Z19FDKaacEnc_PsyOutNewPP7PSY_OUTiiiPh
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0391e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0391E4ULL;
}

// FDE #0307 | PC: 0x039298..0x0392e4 (76 B) | Symbol: _Z23FDKaacEnc_psyInitStatesP12PSY_INTERNALP10PSY_STATIC17AUDIO_OBJECT_TYPE
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x0, [x1]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x0, [x1]]
uint64_t fde_sub_039298(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x039298ULL;
}

// FDE #0308 | PC: 0x0392e4..0x0394a4 (448 B) | Symbol: _Z17FDKaacEnc_psyInitP12PSY_INTERNALPP7PSY_OUTii17AUDIO_OBJECT_TYPEP15CHANNEL_MAPPING
// EN: AArch64 prologue [mov x6, x30; bl #0x6a160; mov x30, x6; stp x29, x30, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [mov x6, x30; bl #0x6a160; mov x30, x6; stp x29, x30, [sp, #0x80]]
uint64_t fde_sub_0392e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400C39EULL) << 32) | 0xAA1E03E6ULL;
    const uint64_t kPcRange = 0x01C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0392E4ULL;
}

// FDE #0309 | PC: 0x0394a4..0x039738 (660 B) | Symbol: _Z21FDKaacEnc_psyMainInitP12PSY_INTERNAL17AUDIO_OBJECT_TYPEP15CHANNEL_MAPPINGiiiiiiijj
// EN: AArch64 prologue [mov x8, x30; bl #0x69f8c; mov x30, x8; stp x29, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x69f8c; mov x30, x8; stp x29, x30, [sp, #0x90]]
uint64_t fde_sub_0394a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400C2B9ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x0294ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0394A4ULL;
}

// FDE #0310 | PC: 0x039738..0x03b034 (6396 B) | Symbol: _Z17FDKaacEnc_psyMainiP11PSY_ELEMENTP11PSY_DYNAMICP17PSY_CONFIGURATIONP15PSY_OUT_ELEMENTPsPii
// EN: AArch64 prologue [str d8, [sp, #-0x70]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str d8, [sp, #-0x70]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_039738(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9016FFCULL) << 32) | 0xFC190FE8ULL;
    const uint64_t kPcRange = 0x18FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x039738ULL;
}

// FDE #0311 | PC: 0x03b034..0x03b060 (44 B) | Symbol: sub_03b034
// EN: AArch64 prologue [mov w8, wzr; mov x9, xzr; sxtw x10, w2; cmp x9, x10] | VI: Khởi đầu hàm AArch64 [mov w8, wzr; mov x9, xzr; sxtw x10, w2; cmp x9, x10]
uint64_t fde_sub_03b034(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E9ULL) << 32) | 0x2A1F03E8ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03B034ULL;
}

// FDE #0312 | PC: 0x03b060..0x03b12c (204 B) | Symbol: _Z18FDKaacEnc_QCOutNewPP6QC_OUTiiiPh
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; mov x5, x30; bl #0x69fa8; mov x30, x5] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; mov x5, x30; bl #0x69fa8; mov x30, x5]
uint64_t fde_sub_03b060(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E5ULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03B060ULL;
}

// FDE #0313 | PC: 0x03b12c..0x03b1a4 (120 B) | Symbol: _Z19FDKaacEnc_QCOutInitPP6QC_OUTiPK15CHANNEL_MAPPING
// EN: AArch64 prologue [mov x8, xzr; sxtw x9, w1; mov w10, #0x18; cmp x8, x9] | VI: Khởi đầu hàm AArch64 [mov x8, xzr; sxtw x9, w1; mov w10, #0x18; cmp x8, x9]
uint64_t fde_sub_03b12c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x93407C29ULL) << 32) | 0xAA1F03E8ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03B12CULL;
}

// FDE #0314 | PC: 0x03b1a4..0x03b234 (144 B) | Symbol: _Z15FDKaacEnc_QCNewPP8QC_STATEiPh
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_03b1a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03B1A4ULL;
}

// FDE #0315 | PC: 0x03b234..0x03b2f8 (196 B) | Symbol: _Z17FDKaacEnc_QCClosePP8QC_STATEPP6QC_OUT
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_03b234(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03B234ULL;
}

// FDE #0316 | PC: 0x03b2f8..0x03b46c (372 B) | Symbol: _Z16FDKaacEnc_QCInitP8QC_STATEP7QC_INIT
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_03b2f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0174ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03B2F8ULL;
}

// FDE #0317 | PC: 0x03b46c..0x03b518 (172 B) | Symbol: _Z23FDKaacEnc_QCMainPrepareP12ELEMENT_INFOP11ATS_ELEMENTP15PSY_OUT_ELEMENTP14QC_OUT_ELEMENT17AUDIO_OBJECT_TYPEja
// EN: AArch64 prologue [mov x7, x30; bl #0x6bbd8; mov x30, x7; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x7, x30; bl #0x6bbd8; mov x30, x7; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_03b46c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400C1DAULL) << 32) | 0xAA1E03E7ULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03B46CULL;
}

// FDE #0318 | PC: 0x03b518..0x03b558 (64 B) | Symbol: _Z23FDKaacEnc_AdjustBitrateP8QC_STATEP15CHANNEL_MAPPINGPiiii
// EN: AArch64 prologue [asr w8, w5, #3; ldr w9, [x0, #0x30]; mul w8, w8, w3; sdiv w10, w8, w4] | VI: Khởi đầu hàm AArch64 [asr w8, w5, #3; ldr w9, [x0, #0x30]; mul w8, w8, w3; sdiv w10, w8, w4]
uint64_t fde_sub_03b518(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9403009ULL) << 32) | 0x13037CA8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03B518ULL;
}

// FDE #0319 | PC: 0x03b558..0x03c2d0 (3448 B) | Symbol: _Z16FDKaacEnc_QCMainP8QC_STATEPP7PSY_OUTPP6QC_OUTiP15CHANNEL_MAPPING17AUDIO_OBJECT_TYPEja
// EN: AArch64 prologue [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_03b558(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400BA6FULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x0D78ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03B558ULL;
}

// FDE #0320 | PC: 0x03c2d0..0x03c36c (156 B) | Symbol: sub_03c2d0
// EN: AArch64 prologue [ldrsw x9, [x2, #0xc]; mov w8, wzr; add x10, x2, #0x10; mov w13, #1] | VI: Khởi đầu hàm AArch64 [ldrsw x9, [x2, #0xc]; mov w8, wzr; add x10, x2, #0x10; mov w13, #1]
uint64_t fde_sub_03c2d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E8ULL) << 32) | 0xB9800C49ULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03C2D0ULL;
}

// FDE #0321 | PC: 0x03c36c..0x03c44c (224 B) | Symbol: _Z24FDKaacEnc_updateFillBitsP15CHANNEL_MAPPINGP8QC_STATEPP12ELEMENT_BITSPP6QC_OUT
// EN: AArch64 prologue [ldr w8, [x1, #0x10]; sub w9, w8, #1; cmp w9, #5; b.hs #0x3c3c8] | VI: Khởi đầu hàm AArch64 [ldr w8, [x1, #0x10]; sub w9, w8, #1; cmp w9, #5; b.hs #0x3c3c8]
uint64_t fde_sub_03c36c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x51000509ULL) << 32) | 0xB9401028ULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03C36CULL;
}

// FDE #0322 | PC: 0x03c44c..0x03c49c (80 B) | Symbol: _Z22FDKaacEnc_updateBitresP15CHANNEL_MAPPINGP8QC_STATEPP6QC_OUT
// EN: AArch64 prologue [ldr w8, [x1, #0x10]; sub w8, w8, #1; cmp w8, #5; b.hi #0x3c474] | VI: Khởi đầu hàm AArch64 [ldr w8, [x1, #0x10]; sub w8, w8, #1; cmp w8, #5; b.hi #0x3c474]
uint64_t fde_sub_03c44c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x51000508ULL) << 32) | 0xB9401028ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03C44CULL;
}

// FDE #0323 | PC: 0x03c49c..0x03c674 (472 B) | Symbol: _Z32FDKaacEnc_FinalizeBitConsumptionP15CHANNEL_MAPPINGP8QC_STATEP6QC_OUTPP14QC_OUT_ELEMENTP12TRANSPORTENC17AUDIO_OBJECT_TYPEja
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_03c49c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9025FF8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x01D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03C49CULL;
}

// FDE #0324 | PC: 0x03c674..0x03c71c (168 B) | Symbol: _Z26FDKaacEnc_QuantizeSpectrumiiiPiS_iS_Psi
// EN: AArch64 prologue [mov x8, x30; bl #0x69f4c; mov x30, x8; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x69f4c; mov x30, x8; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_03c674(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400B635ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03C674ULL;
}

// FDE #0325 | PC: 0x03c71c..0x03c840 (292 B) | Symbol: sub_03c71c
// EN: AArch64 prologue [adrp x11, #0x9a000; ldr x11, [x11, #0x898]; neg w12, w0; adrp x10, #0x9a000] | VI: Khởi đầu hàm AArch64 [adrp x11, #0x9a000; ldr x11, [x11, #0x898]; neg w12, w0; adrp x10, #0x9a000]
uint64_t fde_sub_03c71c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9444D6BULL) << 32) | 0xD00002EBULL;
    const uint64_t kPcRange = 0x0124ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03C71CULL;
}

// FDE #0326 | PC: 0x03c840..0x03c940 (256 B) | Symbol: _Z21FDKaacEnc_calcSfbDistPiPsiii
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; mov x5, x30; bl #0x69fa8; mov x30, x5] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; mov x5, x30; bl #0x69fa8; mov x30, x5]
uint64_t fde_sub_03c840(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E5ULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03C840ULL;
}

// FDE #0327 | PC: 0x03c940..0x03ca38 (248 B) | Symbol: sub_03c940
// EN: AArch64 prologue [mov w8, #1; and w9, w0, #3; sxth w10, w1; sub w8, w8, w0, asr #2] | VI: Khởi đầu hàm AArch64 [mov w8, #1; and w9, w0, #3; sxth w10, w1; sub w8, w8, w0, asr #2]
uint64_t fde_sub_03c940(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12000409ULL) << 32) | 0x52800028ULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03C940ULL;
}

// FDE #0328 | PC: 0x03ca38..0x03cb4c (276 B) | Symbol: _Z35FDKaacEnc_calcSfbQuantEnergyAndDistPiPsiiS_S_
// EN: AArch64 prologue [mov x6, x30; bl #0x69f4c; mov x30, x6; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x6, x30; bl #0x69f4c; mov x30, x6; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_03ca38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400B544ULL) << 32) | 0xAA1E03E6ULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CA38ULL;
}

// FDE #0329 | PC: 0x03cb4c..0x03cc6c (288 B) | Symbol: _Z24FDKaacEnc_CalcFormFactorPP14QC_OUT_CHANNELPP15PSY_OUT_CHANNELi
// EN: AArch64 prologue [mov x3, x30; bl #0x69f8c; mov x30, x3; stp x29, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x69f8c; mov x30, x3; stp x29, x30, [sp, #0x90]]
uint64_t fde_sub_03cb4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400B50FULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x0120ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CB4CULL;
}

// FDE #0330 | PC: 0x03cc6c..0x03e16c (5376 B) | Symbol: _Z30FDKaacEnc_EstimateScaleFactorsPP15PSY_OUT_CHANNELPP14QC_OUT_CHANNELiii
// EN: AArch64 prologue [mov x5, x30; bl #0x69f18; mov x30, x5; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x5, x30; bl #0x69f18; mov x30, x5; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_03cc6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400B4AAULL) << 32) | 0xAA1E03E5ULL;
    const uint64_t kPcRange = 0x1500ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03CC6CULL;
}

// FDE #0331 | PC: 0x03e16c..0x03e1e4 (120 B) | Symbol: sub_03e16c
// EN: AArch64 prologue [lsl w8, w0, #0x18; mov w9, #0x30000000; smull x8, w8, w9; lsr x8, x8, #0x1f] | VI: Khởi đầu hàm AArch64 [lsl w8, w0, #0x18; mov w9, #0x30000000; smull x8, w8, w9; lsr x8, x8, #0x1f]
uint64_t fde_sub_03e16c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52A60009ULL) << 32) | 0x53081C08ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E16CULL;
}

// FDE #0332 | PC: 0x03e1e4..0x03e210 (44 B) | Symbol: sub_03e1e4
// EN: AArch64 prologue [adrp x9, #0x9a000; ldr x9, [x9, #0x970]; sub w8, w1, w0; sub w10, w0, w2] | VI: Khởi đầu hàm AArch64 [adrp x9, #0x9a000; ldr x9, [x9, #0x970]; sub w8, w1, w0; sub w10, w0, w2]
uint64_t fde_sub_03e1e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF944B929ULL) << 32) | 0x900002E9ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E1E4ULL;
}

// FDE #0333 | PC: 0x03e210..0x03e5d0 (960 B) | Symbol: sub_03e210
// EN: AArch64 prologue [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_03e210(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400AF41ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x03C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E210ULL;
}

// FDE #0334 | PC: 0x03e5d0..0x03e724 (340 B) | Symbol: sub_03e5d0
// EN: AArch64 prologue [sxtw x11, w3; sxtw x8, w4; sbfiz x12, x3, #0x20, #0x20; mov w9, #-0xffffffff80000000] | VI: Khởi đầu hàm AArch64 [sxtw x11, w3; sxtw x8, w4; sbfiz x12, x3, #0x20, #0x20; mov w9, #-0xffffffff80000000]
uint64_t fde_sub_03e5d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x93407C88ULL) << 32) | 0x93407C6BULL;
    const uint64_t kPcRange = 0x0154ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E5D0ULL;
}

// FDE #0335 | PC: 0x03e724..0x03e83c (280 B) | Symbol: sub_03e724
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x10]!; mov w9, #0x500; mov w11, #0x69e2; sxtw x12, w6] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x10]!; mov w9, #0x500; mov w11, #0x69e2; sxtw x12, w6]
uint64_t fde_sub_03e724(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5280A009ULL) << 32) | 0xA9BF4FF4ULL;
    const uint64_t kPcRange = 0x0118ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E724ULL;
}

// FDE #0336 | PC: 0x03e83c..0x03e8c4 (136 B) | Symbol: _Z22FDKaacEnc_SpreadingMaxiPKiS0_Pi
// EN: AArch64 prologue [ldr w10, [x3]; sxtw x8, w0; mov w9, #1; cmp x9, x8] | VI: Khởi đầu hàm AArch64 [ldr w10, [x3]; sxtw x8, w0; mov w9, #1; cmp x9, x8]
uint64_t fde_sub_03e83c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x93407C08ULL) << 32) | 0xB940006AULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E83CULL;
}

// FDE #0337 | PC: 0x03e8c4..0x03ea3c (376 B) | Symbol: _Z31FDKaacEnc_CalculateFullTonalityPiS_S_PsiPKii
// EN: AArch64 prologue [mov x7, x30; bl #0x69f18; mov x30, x7; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x7, x30; bl #0x69f18; mov x30, x7; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_03e8c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400AD94ULL) << 32) | 0xAA1E03E7ULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03E8C4ULL;
}

// FDE #0338 | PC: 0x03ea3c..0x03ee50 (1044 B) | Symbol: _Z24FDKaacEnc_Transform_RealPKsPiiiS1_iS1_iS1_
// EN: AArch64 prologue [mov x8, x30; bl #0x69f4c; mov x30, x8; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x69f4c; mov x30, x8; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_03ea3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400AD43ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x0414ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03EA3CULL;
}

// FDE #0339 | PC: 0x03ee50..0x03ef5c (268 B) | Symbol: createLimiter
// EN: AArch64 prologue [mov x5, x30; bl #0x69f4c; mov x30, x5; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x5, x30; bl #0x69f4c; mov x30, x5; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_03ee50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400AC3EULL) << 32) | 0xAA1E03E5ULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03EE50ULL;
}

// FDE #0340 | PC: 0x03ef5c..0x03ef94 (56 B) | Symbol: destroyLimiter
// EN: AArch64 prologue [cbz x0, #0x3ef90; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x3ef90; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10]
uint64_t fde_sub_03ef5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0xB40001A0ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03EF5CULL;
}

// FDE #0341 | PC: 0x03ef94..0x03efd0 (60 B) | Symbol: sub_03ef94
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub x1, x29, #4] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub x1, x29, #4]
uint64_t fde_sub_03ef94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03EF94ULL;
}

// FDE #0342 | PC: 0x03efd0..0x03f050 (128 B) | Symbol: resetLimiter
// EN: AArch64 prologue [cbz x0, #0x3f04c; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x3f04c; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10]
uint64_t fde_sub_03efd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0xB40003E0ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03EFD0ULL;
}

// FDE #0343 | PC: 0x03f050..0x03f3d4 (900 B) | Symbol: applyLimiter
// EN: AArch64 prologue [mov x4, x30; bl #0x6a8c0; mov x30, x4; stp x29, x30, [sp, #0xd0]] | VI: Khởi đầu hàm AArch64 [mov x4, x30; bl #0x6a8c0; mov x30, x4; stp x29, x30, [sp, #0xd0]]
uint64_t fde_sub_03f050(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400AE1BULL) << 32) | 0xAA1E03E4ULL;
    const uint64_t kPcRange = 0x0384ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F050ULL;
}

// FDE #0344 | PC: 0x03f3d4..0x03f3d8 (4 B) | Symbol: FDK_getValidBits
// EN: AArch64 prologue [b #0x6c0f0] | VI: Khởi đầu hàm AArch64 [b #0x6c0f0]
uint64_t fde_sub_03f3d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB40000E0ULL) << 32) | 0x1400B347ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F3D4ULL;
}

// FDE #0345 | PC: 0x03f3d8..0x03f404 (44 B) | Symbol: setLimiterNChannels
// EN: AArch64 prologue [cbz x0, #0x3f3f4; ldr w9, [x0, #0x20]; mov x8, x0; cmp w9, w1] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x3f3f4; ldr w9, [x0, #0x20]; mov x8, x0; cmp w9, w1]
uint64_t fde_sub_03f3d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9402009ULL) << 32) | 0xB40000E0ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F3D8ULL;
}

// FDE #0346 | PC: 0x03f404..0x03f49c (152 B) | Symbol: setLimiterSampleRate
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_03f404(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F404ULL;
}

// FDE #0347 | PC: 0x03f49c..0x03f510 (116 B) | Symbol: setLimiterAttack
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_03f49c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F49CULL;
}

// FDE #0348 | PC: 0x03f510..0x03f580 (112 B) | Symbol: setLimiterRelease
// EN: AArch64 prologue [cbz x0, #0x3f57c; sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x3f57c; sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]]
uint64_t fde_sub_03f510(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD100C3FFULL) << 32) | 0xB4000360ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F510ULL;
}

// FDE #0349 | PC: 0x03f580..0x03f598 (24 B) | Symbol: setLimiterThreshold
// EN: AArch64 prologue [cbz x0, #0x3f594; mov x8, x0; mov w0, wzr; strh w1, [x8, #0x18]] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x3f594; mov x8, x0; mov w0, wzr; strh w1, [x8, #0x18]]
uint64_t fde_sub_03f580(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003E8ULL) << 32) | 0xB40000A0ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F580ULL;
}

// FDE #0350 | PC: 0x03f598..0x03f5e8 (80 B) | Symbol: pcmDmx_Open
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x3f5d4] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x3f5d4]
uint64_t fde_sub_03f598(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F598ULL;
}

// FDE #0351 | PC: 0x03f5e8..0x03f668 (128 B) | Symbol: pcmDmx_Reset
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_03f5e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F5E8ULL;
}

// FDE #0352 | PC: 0x03f668..0x03f7c4 (348 B) | Symbol: pcmDmx_SetParam
// EN: AArch64 prologue [cmp w1, #5; b.hi #0x3f6a4; adrp x10, #0x6c000; mov w9, w1] | VI: Khởi đầu hàm AArch64 [cmp w1, #5; b.hi #0x3f6a4; adrp x10, #0x6c000; mov w9, w1]
uint64_t fde_sub_03f668(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x540001C8ULL) << 32) | 0x7100143FULL;
    const uint64_t kPcRange = 0x015CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F668ULL;
}

// FDE #0353 | PC: 0x03f7c4..0x03f838 (116 B) | Symbol: pcmDmx_GetParam
// EN: AArch64 prologue [mov x8, x0; mov w0, #7; cbz x8, #0x3f834; cbz x2, #0x3f834] | VI: Khởi đầu hàm AArch64 [mov x8, x0; mov w0, #7; cbz x8, #0x3f834; cbz x2, #0x3f834]
uint64_t fde_sub_03f7c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x528000E0ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F7C4ULL;
}

// FDE #0354 | PC: 0x03f838..0x03fa88 (592 B) | Symbol: pcmDmx_Parse
// EN: AArch64 prologue [mov x2, x30; bl #0x6a250; mov x30, x2; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x6a250; mov x30, x2; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_03f838(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400AA85ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0250ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03F838ULL;
}

// FDE #0355 | PC: 0x03fa88..0x03fb14 (140 B) | Symbol: pcmDmx_ReadDvbAncData
// EN: AArch64 prologue [sub sp, sp, #0x60; str x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]; add x29, sp, #0x50] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]; add x29, sp, #0x50]
uint64_t fde_sub_03fa88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F3ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03FA88ULL;
}

// FDE #0356 | PC: 0x03fb14..0x03fb4c (56 B) | Symbol: pcmDmx_SetMatrixMixdownFromPce
// EN: AArch64 prologue [cbz x0, #0x3fb44; cbz w1, #0x3fb48; mov x8, x0; ldr w9, [x8]] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x3fb44; cbz w1, #0x3fb48; mov x8, x0; ldr w9, [x8]]
uint64_t fde_sub_03fb14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34000181ULL) << 32) | 0xB4000180ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03FB14ULL;
}

// FDE #0357 | PC: 0x03fb4c..0x04145c (6416 B) | Symbol: pcmDmx_ApplyFrame
// EN: AArch64 prologue [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_03fb4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400A8F2ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x1910ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03FB4CULL;
}

// FDE #0358 | PC: 0x04145c..0x041680 (548 B) | Symbol: sub_04145c
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_04145c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0224ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04145CULL;
}

// FDE #0359 | PC: 0x041680..0x0416b4 (52 B) | Symbol: sub_041680
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1]
uint64_t fde_sub_041680(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041680ULL;
}

// FDE #0360 | PC: 0x0416b4..0x041708 (84 B) | Symbol: sub_0416b4
// EN: AArch64 prologue [mov w12, w3; mov w13, w2; mov x8, xzr; sbfiz w9, w4, #1, #0x10] | VI: Khởi đầu hàm AArch64 [mov w12, w3; mov w13, w2; mov x8, xzr; sbfiz w9, w4, #1, #0x10]
uint64_t fde_sub_0416b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A0203EDULL) << 32) | 0x2A0303ECULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0416B4ULL;
}

// FDE #0361 | PC: 0x041708..0x041790 (136 B) | Symbol: sub_041708
// EN: AArch64 prologue [mov w12, w3; mov w13, w2; mov x8, xzr; sxth w9, w4] | VI: Khởi đầu hàm AArch64 [mov w12, w3; mov w13, w2; mov x8, xzr; sxth w9, w4]
uint64_t fde_sub_041708(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A0203EDULL) << 32) | 0x2A0303ECULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041708ULL;
}

// FDE #0362 | PC: 0x041790..0x0417b8 (40 B) | Symbol: pcmDmx_Close
// EN: AArch64 prologue [cbz x0, #0x417b4; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x417b4; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10]
uint64_t fde_sub_041790(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0xB4000120ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041790ULL;
}

// FDE #0363 | PC: 0x0417b8..0x041850 (152 B) | Symbol: pcmDmx_GetLibInfo
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x417ec] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x417ec]
uint64_t fde_sub_0417b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0417B8ULL;
}

// FDE #0364 | PC: 0x041850..0x041878 (40 B) | Symbol: FDK_CreateBitBuffer
// EN: AArch64 prologue [ldr x8, [x0]; lsl w9, w2, #3; stp xzr, xzr, [x8]; str wzr, [x8, #0x10]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; lsl w9, w2, #3; stp xzr, xzr, [x8]; str wzr, [x8, #0x10]]
uint64_t fde_sub_041850(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x531D7049ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041850ULL;
}

// FDE #0365 | PC: 0x041878..0x041894 (28 B) | Symbol: FDK_InitBitBuffer
// EN: AArch64 prologue [lsl w8, w2, #3; str w3, [x0]; stur xzr, [x0, #0xc]; stur xzr, [x0, #4]] | VI: Khởi đầu hàm AArch64 [lsl w8, w2, #3; str w3, [x0]; stur xzr, [x0, #0xc]; stur xzr, [x0, #4]]
uint64_t fde_sub_041878(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9000003ULL) << 32) | 0x531D7048ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041878ULL;
}

// FDE #0366 | PC: 0x041894..0x0418a0 (12 B) | Symbol: FDK_ResetBitBuffer
// EN: AArch64 prologue [stp xzr, xzr, [x0]; str wzr, [x0, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [stp xzr, xzr, [x0]; str wzr, [x0, #0x10]; ret]
uint64_t fde_sub_041894(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB900101FULL) << 32) | 0xA9007C1FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041894ULL;
}

// FDE #0367 | PC: 0x0418a0..0x041944 (164 B) | Symbol: FDK_get
// EN: AArch64 prologue [ldp w9, w11, [x0, #0xc]; ldp w12, w10, [x0, #0x20]; ldr w13, [x0]; ldr x8, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [ldp w9, w11, [x0, #0xc]; ldp w12, w10, [x0, #0x20]; ldr w13, [x0]; ldr x8, [x0, #0x18]]
uint64_t fde_sub_0418a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2944280CULL) << 32) | 0x2941AC09ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0418A0ULL;
}

// FDE #0368 | PC: 0x041944..0x041a14 (208 B) | Symbol: FDK_get32
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w9, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w9, [x0, #0x10]]
uint64_t fde_sub_041944(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041944ULL;
}

// FDE #0369 | PC: 0x041a14..0x041b10 (252 B) | Symbol: FDK_getBwd
// EN: AArch64 prologue [ldp w11, w8, [x0, #0xc]; ldp w10, w9, [x0, #0x20]; ldr w12, [x0]; cmp w1, #0x19] | VI: Khởi đầu hàm AArch64 [ldp w11, w8, [x0, #0xc]; ldp w10, w9, [x0, #0x20]; ldr w12, [x0]; cmp w1, #0x19]
uint64_t fde_sub_041a14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2944240AULL) << 32) | 0x2941A00BULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041A14ULL;
}

// FDE #0370 | PC: 0x041b10..0x041c28 (280 B) | Symbol: FDK_put
// EN: AArch64 prologue [ldp w9, w11, [x0, #0xc]; ldp w10, w12, [x0, #0x20]; adrp x8, #0x9a000; ldr w13, [x0]] | VI: Khởi đầu hàm AArch64 [ldp w9, w11, [x0, #0xc]; ldp w10, w12, [x0, #0x20]; adrp x8, #0x9a000; ldr w13, [x0]]
uint64_t fde_sub_041b10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2944300AULL) << 32) | 0x2941AC09ULL;
    const uint64_t kPcRange = 0x0118ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041B10ULL;
}

// FDE #0371 | PC: 0x041c28..0x041d84 (348 B) | Symbol: FDK_putBwd
// EN: AArch64 prologue [ldp w13, w11, [x0, #0xc]; adrp x9, #0x9a000; ldr x9, [x9, #0x798]; ldp w12, w15, [x0, #0x20]] | VI: Khởi đầu hàm AArch64 [ldp w13, w11, [x0, #0xc]; adrp x9, #0x9a000; ldr x9, [x9, #0x798]; ldp w12, w15, [x0, #0x20]]
uint64_t fde_sub_041c28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00002C9ULL) << 32) | 0x2941AC0DULL;
    const uint64_t kPcRange = 0x015CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041C28ULL;
}

// FDE #0372 | PC: 0x041d84..0x041da8 (36 B) | Symbol: FDK_pushBack
// EN: AArch64 prologue [ldr w8, [x0]; tst w2, #0xff; ldp w9, w10, [x0, #0xc]; cneg w11, w1, ne] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0]; tst w2, #0xff; ldp w9, w10, [x0, #0xc]; cneg w11, w1, ne]
uint64_t fde_sub_041d84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72001C5FULL) << 32) | 0xB9400008ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041D84ULL;
}

// FDE #0373 | PC: 0x041da8..0x041dcc (36 B) | Symbol: FDK_pushForward
// EN: AArch64 prologue [ldr w8, [x0]; tst w2, #0xff; ldp w9, w10, [x0, #0xc]; cneg w11, w1, ne] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0]; tst w2, #0xff; ldp w9, w10, [x0, #0xc]; cneg w11, w1, ne]
uint64_t fde_sub_041da8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72001C5FULL) << 32) | 0xB9400008ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041DA8ULL;
}

// FDE #0374 | PC: 0x041dcc..0x041e20 (84 B) | Symbol: FDK_byteAlign
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0xc]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0xc]]
uint64_t fde_sub_041dcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041DCCULL;
}

// FDE #0375 | PC: 0x041e20..0x041e30 (16 B) | Symbol: FDK_getFreeBits
// EN: AArch64 prologue [ldr w8, [x0, #0x24]; ldr w9, [x0]; sub w0, w8, w9; ret] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #0x24]; ldr w9, [x0]; sub w0, w8, w9; ret]
uint64_t fde_sub_041e20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9400009ULL) << 32) | 0xB9402408ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041E20ULL;
}

// FDE #0376 | PC: 0x041e30..0x041e38 (8 B) | Symbol: FDK_setBitCnt
// EN: AArch64 prologue [str w1, [x0, #0xc]; ret] | VI: Khởi đầu hàm AArch64 [str w1, [x0, #0xc]; ret]
uint64_t fde_sub_041e30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9000C01ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041E30ULL;
}

// FDE #0377 | PC: 0x041e38..0x041e40 (8 B) | Symbol: _Z31CLatmDemux_GetFrameLengthInBitsP10CLatmDemux
// EN: AArch64 prologue [ldr w0, [x0, #0xc]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0xc]; ret]
uint64_t fde_sub_041e38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9400C00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041E38ULL;
}

// FDE #0378 | PC: 0x041e40..0x041ef0 (176 B) | Symbol: FDK_Feed
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_041e40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041E40ULL;
}

// FDE #0379 | PC: 0x041ef0..0x041f54 (100 B) | Symbol: _Z16CopyAlignedBlockP10FDK_BITBUFPhj
// EN: AArch64 prologue [ldr w10, [x0, #0x20]; ldr w9, [x0, #0x10]; ldr x8, [x0, #0x18]; sub w11, w10, #1] | VI: Khởi đầu hàm AArch64 [ldr w10, [x0, #0x20]; ldr w9, [x0, #0x10]; ldr x8, [x0, #0x18]; sub w11, w10, #1]
uint64_t fde_sub_041ef0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9401009ULL) << 32) | 0xB940200AULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041EF0ULL;
}

// FDE #0380 | PC: 0x041f54..0x04203c (232 B) | Symbol: FDK_Copy
// EN: AArch64 prologue [mov x3, x30; bl #0x6a250; mov x30, x3; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x6a250; mov x30, x3; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_041f54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400A0BEULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041F54ULL;
}

// FDE #0381 | PC: 0x04203c..0x0420cc (144 B) | Symbol: FDK_Fetch
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_04203c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04203CULL;
}

// FDE #0382 | PC: 0x0420cc..0x04216c (160 B) | Symbol: FDK_toolsGetLibInfo
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x42108] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x42108]
uint64_t fde_sub_0420cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0420CCULL;
}

// FDE #0383 | PC: 0x04216c..0x0421e8 (124 B) | Symbol: _Z10FDKcrcInitP11FDK_CRCINFOjjj
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub w8, w3, #1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub w8, w3, #1]
uint64_t fde_sub_04216c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04216CULL;
}

// FDE #0384 | PC: 0x0421e8..0x042210 (40 B) | Symbol: _Z11FDKcrcResetP11FDK_CRCINFO
// EN: AArch64 prologue [ldrh w9, [x0, #0x3c]; mov x8, xzr; strh w9, [x0, #0x48]; cmp x8, #0x30] | VI: Khởi đầu hàm AArch64 [ldrh w9, [x0, #0x3c]; mov x8, xzr; strh w9, [x0, #0x48]; cmp x8, #0x30]
uint64_t fde_sub_0421e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E8ULL) << 32) | 0x79407809ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0421E8ULL;
}

// FDE #0385 | PC: 0x042210..0x042260 (80 B) | Symbol: _Z14FDKcrcStartRegP11FDK_CRCINFOP13FDK_BITSTREAMi
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_042210(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042210ULL;
}

// FDE #0386 | PC: 0x042260..0x042468 (520 B) | Symbol: _Z12FDKcrcEndRegP11FDK_CRCINFOP13FDK_BITSTREAMi
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]; stp x20, x19, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]; stp x20, x19, [sp, #0x70]]
uint64_t fde_sub_042260(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9055FF8ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0208ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042260ULL;
}

// FDE #0387 | PC: 0x042468..0x0424f8 (144 B) | Symbol: sub_042468
// EN: AArch64 prologue [mov x4, x30; bl #0x6a250; mov x30, x4; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x4, x30; bl #0x6a250; mov x30, x4; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_042468(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94009F79ULL) << 32) | 0xAA1E03E4ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042468ULL;
}

// FDE #0388 | PC: 0x0424f8..0x04258c (148 B) | Symbol: sub_0424f8
// EN: AArch64 prologue [mov x5, x30; bl #0x6a250; mov x30, x5; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x5, x30; bl #0x6a250; mov x30, x5; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_0424f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94009F55ULL) << 32) | 0xAA1E03E5ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0424F8ULL;
}

// FDE #0389 | PC: 0x04258c..0x0425a4 (24 B) | Symbol: _Z12FDKcrcGetCRCP11FDK_CRCINFO
// EN: AArch64 prologue [ldrh w8, [x0, #0x3a]; ldrh w9, [x0, #0x48]; lsl w8, w8, #1; sub w8, w8, #1] | VI: Khởi đầu hàm AArch64 [ldrh w8, [x0, #0x3a]; ldrh w9, [x0, #0x48]; lsl w8, w8, #1; sub w8, w8, #1]
uint64_t fde_sub_04258c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x79409009ULL) << 32) | 0x79407408ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04258CULL;
}

// FDE #0390 | PC: 0x0425a4..0x0425b4 (16 B) | Symbol: _Z21FDKhybridAnalysisOpenP18FDK_ANA_HYB_FILTERPijS1_j
// EN: AArch64 prologue [str w2, [x0, #0x128]; stp x1, x3, [x0, #0x118]; str w4, [x0, #0x12c]; b #0x6a02c] | VI: Khởi đầu hàm AArch64 [str w2, [x0, #0x128]; stp x1, x3, [x0, #0x118]; str w4, [x0, #0x12c]; b #0x6a02c]
uint64_t fde_sub_0425a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9118C01ULL) << 32) | 0xB9012802ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0425A4ULL;
}

// FDE #0391 | PC: 0x0425b4..0x042724 (368 B) | Symbol: _Z21FDKhybridAnalysisInitP18FDK_ANA_HYB_FILTER15FDK_HYBRID_MODEiii
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; mov x5, x30; bl #0x69fa8; mov x30, x5] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; mov x5, x30; bl #0x69fa8; mov x30, x5]
uint64_t fde_sub_0425b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E5ULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0425B4ULL;
}

// FDE #0392 | PC: 0x042724..0x0427d0 (172 B) | Symbol: _Z28FDKhybridAnalysisScaleStatesP18FDK_ANA_HYB_FILTERi
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_042724(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042724ULL;
}

// FDE #0393 | PC: 0x0427d0..0x043304 (2868 B) | Symbol: _Z22FDKhybridAnalysisApplyP18FDK_ANA_HYB_FILTERPKiS2_PiS3_
// EN: AArch64 prologue [sub sp, sp, #0x160; stp x28, x27, [sp, #0x100]; stp x26, x25, [sp, #0x110]; stp x24, x23, [sp, #0x120]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; stp x28, x27, [sp, #0x100]; stp x26, x25, [sp, #0x110]; stp x24, x23, [sp, #0x120]]
uint64_t fde_sub_0427d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9106FFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x0B34ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0427D0ULL;
}

// FDE #0394 | PC: 0x043304..0x04330c (8 B) | Symbol: sub_043304
// EN: AArch64 prologue [ubfx x5, x4, #0x10, #0x10; b #0x4330c] | VI: Khởi đầu hàm AArch64 [ubfx x5, x4, #0x10, #0x10; b #0x4330c]
uint64_t fde_sub_043304(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xD3507C85ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043304ULL;
}

// FDE #0395 | PC: 0x04330c..0x043344 (56 B) | Symbol: sub_04330c
// EN: AArch64 prologue [lsl w8, w4, #0x10; lsl w9, w5, #0x10; smull x10, w8, w2; smull x11, w9, w3] | VI: Khởi đầu hàm AArch64 [lsl w8, w4, #0x10; lsl w9, w5, #0x10; smull x10, w8, w2; smull x11, w9, w3]
uint64_t fde_sub_04330c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x53103CA9ULL) << 32) | 0x53103C88ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04330CULL;
}

// FDE #0396 | PC: 0x043344..0x043354 (16 B) | Symbol: _Z22FDKhybridAnalysisCloseP18FDK_ANA_HYB_FILTER
// EN: AArch64 prologue [cbz x0, #0x43350; stp xzr, xzr, [x0, #0x118]; str xzr, [x0, #0x128]; b #0x6a02c] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x43350; stp xzr, xzr, [x0, #0x118]; str xzr, [x0, #0x128]; b #0x6a02c]
uint64_t fde_sub_043344(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA911FC1FULL) << 32) | 0xB4000060ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043344ULL;
}

// FDE #0397 | PC: 0x043354..0x043380 (44 B) | Symbol: _Z22FDKhybridSynthesisInitP18FDK_SYN_HYB_FILTER15FDK_HYBRID_MODEii
// EN: AArch64 prologue [cmp w1, #2; b.hi #0x4337c; adrp x9, #0x99000; add x9, x9, #0xec8] | VI: Khởi đầu hàm AArch64 [cmp w1, #2; b.hi #0x4337c; adrp x9, #0x99000; add x9, x9, #0xec8]
uint64_t fde_sub_043354(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000128ULL) << 32) | 0x7100083FULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043354ULL;
}

// FDE #0398 | PC: 0x043380..0x04343c (188 B) | Symbol: _Z23FDKhybridSynthesisApplyP18FDK_SYN_HYB_FILTERPKiS2_PiS3_
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_043380(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043380ULL;
}

// FDE #0399 | PC: 0x04343c..0x0434c0 (132 B) | Symbol: _Z17FDKgetWindowSlopeii
// EN: AArch64 prologue [mov w9, #0x1c; clz w10, w0; sub w9, w9, w10; mov w8, #0x1e] | VI: Khởi đầu hàm AArch64 [mov w9, #0x1c; clz w10, w0; sub w9, w9, w10; mov w8, #0x1e]
uint64_t fde_sub_04343c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5AC0100AULL) << 32) | 0x52800389ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04343CULL;
}

// FDE #0400 | PC: 0x0434c0..0x0435ec (300 B) | Symbol: _Z23getBitstreamElementList17AUDIO_OBJECT_TYPEahh
// EN: AArch64 prologue [sub w8, w0, #0x8f; cmp w8, #3; b.lo #0x43518; cmp w0, #2] | VI: Khởi đầu hàm AArch64 [sub w8, w0, #0x8f; cmp w8, #3; b.lo #0x43518; cmp w0, #2]
uint64_t fde_sub_0434c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x71000D1FULL) << 32) | 0x51023C08ULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0434C0ULL;
}

// FDE #0401 | PC: 0x0435ec..0x04376c (384 B) | Symbol: _Z10fixp_atan2ii
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0435ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0180ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0435ECULL;
}

// FDE #0402 | PC: 0x04376c..0x043848 (220 B) | Symbol: _Z9fixp_atani
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cmp w0, #0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cmp w0, #0]
uint64_t fde_sub_04376c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04376CULL;
}

// FDE #0403 | PC: 0x043848..0x043884 (60 B) | Symbol: _Z8fixp_cosii
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub x2, x29, #4] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub x2, x29, #4]
uint64_t fde_sub_043848(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043848ULL;
}

// FDE #0404 | PC: 0x043884..0x043944 (192 B) | Symbol: sub_043884
// EN: AArch64 prologue [mov w9, #0x60dc; movk w9, #0x28be, lsl #16; smull x9, w0, w9; mov w8, #0x15] | VI: Khởi đầu hàm AArch64 [mov w9, #0x60dc; movk w9, #0x28be, lsl #16; smull x9, w0, w9; mov w8, #0x15]
uint64_t fde_sub_043884(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72A517C9ULL) << 32) | 0x528C1B89ULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043884ULL;
}

// FDE #0405 | PC: 0x043944..0x043980 (60 B) | Symbol: _Z8fixp_sinii
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub x2, x29, #4] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub x2, x29, #4]
uint64_t fde_sub_043944(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043944ULL;
}

// FDE #0406 | PC: 0x043980..0x0439e0 (96 B) | Symbol: _Z12fixp_cos_siniiPiS_
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_043980(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043980ULL;
}

// FDE #0407 | PC: 0x0439e0..0x043b50 (368 B) | Symbol: _Z16autoCorr2nd_realP11ACORR_COEFSPKii
// EN: AArch64 prologue [ldpsw x8, x10, [x1, #-8]; ldpsw x15, x9, [x1]; sxtw x11, w2; sub x14, x11, #2] | VI: Khởi đầu hàm AArch64 [ldpsw x8, x10, [x1, #-8]; ldpsw x15, x9, [x1]; sxtw x11, w2; sub x14, x11, #2]
uint64_t fde_sub_0439e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6940242FULL) << 32) | 0x697F2828ULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0439E0ULL;
}

// FDE #0408 | PC: 0x043b50..0x043e7c (812 B) | Symbol: _Z16autoCorr2nd_cplxP11ACORR_COEFSPKiS2_i
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_043b50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BC67FAULL;
    const uint64_t kPcRange = 0x032CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043B50ULL;
}

// FDE #0409 | PC: 0x043e7c..0x0440e8 (620 B) | Symbol: _Z7dct_IIIPiS_iS_
// EN: AArch64 prologue [mov x4, x30; bl #0x6a5a4; mov x30, x4; stp x29, x30, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [mov x4, x30; bl #0x6a5a4; mov x30, x4; stp x29, x30, [sp, #0xb0]]
uint64_t fde_sub_043e7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940099C9ULL) << 32) | 0xAA1E03E4ULL;
    const uint64_t kPcRange = 0x026CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043E7CULL;
}

// FDE #0410 | PC: 0x0440e8..0x0443c0 (728 B) | Symbol: _Z6dct_IIPiS_iS_
// EN: AArch64 prologue [mov x4, x30; bl #0x6a894; mov x30, x4; stp x29, x30, [sp, #0xe0]] | VI: Khởi đầu hàm AArch64 [mov x4, x30; bl #0x6a894; mov x30, x4; stp x29, x30, [sp, #0xe0]]
uint64_t fde_sub_0440e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940099EAULL) << 32) | 0xAA1E03E4ULL;
    const uint64_t kPcRange = 0x02D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0440E8ULL;
}

// FDE #0411 | PC: 0x0443c0..0x044524 (356 B) | Symbol: _Z6dct_IVPiiS_
// EN: AArch64 prologue [mov x3, x30; bl #0x6a5a4; mov x30, x3; stp x29, x30, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x6a5a4; mov x30, x3; stp x29, x30, [sp, #0xb0]]
uint64_t fde_sub_0443c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94009878ULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x0164ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0443C0ULL;
}

// FDE #0412 | PC: 0x044524..0x0445c0 (156 B) | Symbol: sub_044524
// EN: AArch64 prologue [mov w9, #0x1d; clz w8, w3; sub w9, w9, w8; asr w10, w3, w9] | VI: Khởi đầu hàm AArch64 [mov w9, #0x1d; clz w8, w3; sub w9, w9, w8; asr w10, w3, w9]
uint64_t fde_sub_044524(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5AC01068ULL) << 32) | 0x528003A9ULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044524ULL;
}

// FDE #0413 | PC: 0x0445c0..0x04473c (380 B) | Symbol: _Z6dst_IVPiiS_
// EN: AArch64 prologue [mov x3, x30; bl #0x6a5a4; mov x30, x3; stp x29, x30, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x6a5a4; mov x30, x3; stp x29, x30, [sp, #0xb0]]
uint64_t fde_sub_0445c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940097F8ULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x017CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0445C0ULL;
}

// FDE #0414 | PC: 0x04473c..0x044ef8 (1980 B) | Symbol: _Z3fftiPiS_
// EN: AArch64 prologue [str x28, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x28, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_04473c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FFCULL;
    const uint64_t kPcRange = 0x07BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04473CULL;
}

// FDE #0415 | PC: 0x044ef8..0x04599c (2724 B) | Symbol: sub_044ef8
// EN: AArch64 prologue [sub sp, sp, #0x140; stp x28, x21, [sp, #0x110]; stp x20, x19, [sp, #0x120]; stp x29, x30, [sp, #0x130]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x140; stp x28, x21, [sp, #0x110]; stp x20, x19, [sp, #0x120]; stp x29, x30, [sp, #0x130]]
uint64_t fde_sub_044ef8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA91157FCULL) << 32) | 0xD10503FFULL;
    const uint64_t kPcRange = 0x0AA4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044EF8ULL;
}

// FDE #0416 | PC: 0x04599c..0x045ee4 (1352 B) | Symbol: sub_04599c
// EN: AArch64 prologue [mov x1, x30; bl #0x69f8c; mov x30, x1; stp x29, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [mov x1, x30; bl #0x69f8c; mov x30, x1; stp x29, x30, [sp, #0x90]]
uint64_t fde_sub_04599c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400917BULL) << 32) | 0xAA1E03E1ULL;
    const uint64_t kPcRange = 0x0548ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04599CULL;
}

// FDE #0417 | PC: 0x045ee4..0x046204 (800 B) | Symbol: sub_045ee4
// EN: AArch64 prologue [sub sp, sp, #0x140; str x28, [sp, #0x100]; stp x22, x21, [sp, #0x110]; stp x20, x19, [sp, #0x120]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x140; str x28, [sp, #0x100]; stp x22, x21, [sp, #0x110]; stp x20, x19, [sp, #0x120]]
uint64_t fde_sub_045ee4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90083FCULL) << 32) | 0xD10503FFULL;
    const uint64_t kPcRange = 0x0320ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045EE4ULL;
}

// FDE #0418 | PC: 0x046204..0x0462ec (232 B) | Symbol: sub_046204
// EN: AArch64 prologue [mov x5, x30; bl #0x69f4c; mov x30, x5; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x5, x30; bl #0x69f4c; mov x30, x5; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_046204(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94008F51ULL) << 32) | 0xAA1E03E5ULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046204ULL;
}

// FDE #0419 | PC: 0x0462ec..0x046740 (1108 B) | Symbol: _Z7dit_fftPiiPK8FIXP_SPKi
// EN: AArch64 prologue [mov x4, x30; bl #0x6a8c0; mov x30, x4; stp x29, x30, [sp, #0xd0]] | VI: Khởi đầu hàm AArch64 [mov x4, x30; bl #0x6a8c0; mov x30, x4; stp x29, x30, [sp, #0xd0]]
uint64_t fde_sub_0462ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94009174ULL) << 32) | 0xAA1E03E4ULL;
    const uint64_t kPcRange = 0x0454ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0462ECULL;
}

// FDE #0420 | PC: 0x046740..0x0467bc (124 B) | Symbol: sub_046740
// EN: AArch64 prologue [sub w9, w1, #1; mov w8, wzr; sxtw x9, w9; mov w10, #1] | VI: Khởi đầu hàm AArch64 [sub w9, w1, #1; mov w8, wzr; sxtw x9, w9; mov w10, #1]
uint64_t fde_sub_046740(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E8ULL) << 32) | 0x51000429ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046740ULL;
}

// FDE #0421 | PC: 0x0467bc..0x046c24 (1128 B) | Symbol: _Z8dit_ifftPiiPK8FIXP_SPKi
// EN: AArch64 prologue [mov x4, x30; bl #0x6a894; mov x30, x4; stp x29, x30, [sp, #0xe0]] | VI: Khởi đầu hàm AArch64 [mov x4, x30; bl #0x6a894; mov x30, x4; stp x29, x30, [sp, #0xe0]]
uint64_t fde_sub_0467bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94009035ULL) << 32) | 0xAA1E03E4ULL;
    const uint64_t kPcRange = 0x0468ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0467BCULL;
}

// FDE #0422 | PC: 0x046c24..0x046c2c (8 B) | Symbol: _Z10CalcLdDatai
// EN: AArch64 prologue [mov w1, wzr; b #0x1ba78] | VI: Khởi đầu hàm AArch64 [mov w1, wzr; b #0x1ba78]
uint64_t fde_sub_046c24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF5394ULL) << 32) | 0x2A1F03E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046C24ULL;
}

// FDE #0423 | PC: 0x046c2c..0x046c78 (76 B) | Symbol: _Z5fLog2ii
// EN: AArch64 prologue [cmp w0, #1; b.lt #0x46c70; sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]] | VI: Khởi đầu hàm AArch64 [cmp w0, #1; b.lt #0x46c70; sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]]
uint64_t fde_sub_046c2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5400020BULL) << 32) | 0x7100041FULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046C2CULL;
}

// FDE #0424 | PC: 0x046c78..0x046d34 (188 B) | Symbol: _Z5fLog2iiPi
// EN: AArch64 prologue [cmp w0, #1; b.lt #0x46d20; clz w10, w0; sub w10, w10, #1] | VI: Khởi đầu hàm AArch64 [cmp w0, #1; b.lt #0x46d20; clz w10, w0; sub w10, w10, #1]
uint64_t fde_sub_046c78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5400052BULL) << 32) | 0x7100041FULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046C78ULL;
}

// FDE #0425 | PC: 0x046d34..0x046d6c (56 B) | Symbol: _Z12LdDataVectorPiS_i
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_046d34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046D34ULL;
}

// FDE #0426 | PC: 0x046d6c..0x046d90 (36 B) | Symbol: _Z15mul_dbl_sgl_rndis
// EN: AArch64 prologue [sxth w8, w1; and w9, w0, #0xffff; mov w10, #0x4000; asr w11, w0, #0x10] | VI: Khởi đầu hàm AArch64 [sxth w8, w1; and w9, w0, #0xffff; mov w10, #0x4000; asr w11, w0, #0x10]
uint64_t fde_sub_046d6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12003C09ULL) << 32) | 0x13003C28ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046D6CULL;
}

// FDE #0427 | PC: 0x046d90..0x046e30 (160 B) | Symbol: _Z13CalcInvLdDatai
// EN: AArch64 prologue [adrp x10, #0x7e000; ubfx w8, w0, #0x14, #5; add x10, x10, #0x904; cmp w0, #0] | VI: Khởi đầu hàm AArch64 [adrp x10, #0x7e000; ubfx w8, w0, #0x14, #5; add x10, x10, #0x904; cmp w0, #0]
uint64_t fde_sub_046d90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x53146008ULL) << 32) | 0x900001CAULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046D90ULL;
}

// FDE #0428 | PC: 0x046e30..0x046e50 (32 B) | Symbol: _Z9CalcLdInti
// EN: AArch64 prologue [sub w8, w0, #1; cmp w8, #0xbf; b.hi #0x46e4c; adrp x8, #0x7e000] | VI: Khởi đầu hàm AArch64 [sub w8, w0, #1; cmp w8, #0xbf; b.hi #0x46e4c; adrp x8, #0x7e000]
uint64_t fde_sub_046e30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7102FD1FULL) << 32) | 0x51000408ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046E30ULL;
}

// FDE #0429 | PC: 0x046e50..0x046ed8 (136 B) | Symbol: _Z12invSqrtNorm2iPi
// EN: AArch64 prologue [cbz w0, #0x46ec8; clz w8, w0; sub w10, w8, #1; adrp x9, #0x7e000] | VI: Khởi đầu hàm AArch64 [cbz w0, #0x46ec8; clz w8, w0; sub w10, w8, #1; adrp x9, #0x7e000]
uint64_t fde_sub_046e50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5AC01008ULL) << 32) | 0x340003C0ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046E50ULL;
}

// FDE #0430 | PC: 0x046ed8..0x046f14 (60 B) | Symbol: _Z8sqrtFixpi
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub x1, x29, #4] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub x1, x29, #4]
uint64_t fde_sub_046ed8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046ED8ULL;
}

// FDE #0431 | PC: 0x046f14..0x046f5c (72 B) | Symbol: _Z9schur_diviii
// EN: AArch64 prologue [mov w8, wzr; asr w11, w0, #1; cbz w11, #0x46f50; asr w9, w1, #1] | VI: Khởi đầu hàm AArch64 [mov w8, wzr; asr w11, w0, #1; cbz w11, #0x46f50; asr w9, w1, #1]
uint64_t fde_sub_046f14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x13017C0BULL) << 32) | 0x2A1F03E8ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046F14ULL;
}

// FDE #0432 | PC: 0x046f5c..0x046fb0 (84 B) | Symbol: _Z9fMultNormiiPi
// EN: AArch64 prologue [mov w9, wzr; mov w8, wzr; cbz w0, #0x46fa4; cbz w1, #0x46fa4] | VI: Khởi đầu hàm AArch64 [mov w9, wzr; mov w8, wzr; cbz w0, #0x46fa4; cbz w1, #0x46fa4]
uint64_t fde_sub_046f5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E8ULL) << 32) | 0x2A1F03E9ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046F5CULL;
}

// FDE #0433 | PC: 0x046fb0..0x046ff8 (72 B) | Symbol: _Z8fDivNormiiPi
// EN: AArch64 prologue [mov x8, x2; cbz w0, #0x46fd8; mov x2, x30; bl #0x6c0c4] | VI: Khởi đầu hàm AArch64 [mov x8, x2; cbz w0, #0x46fd8; mov x2, x30; bl #0x6c0c4]
uint64_t fde_sub_046fb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34000120ULL) << 32) | 0xAA0203E8ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046FB0ULL;
}

// FDE #0434 | PC: 0x046ff8..0x047038 (64 B) | Symbol: _Z8fDivNormii
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub x2, x29, #4] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub x2, x29, #4]
uint64_t fde_sub_046ff8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x046FF8ULL;
}

// FDE #0435 | PC: 0x047038..0x047080 (72 B) | Symbol: _Z16fDivNormHighPreciiPi
// EN: AArch64 prologue [mov x8, x2; cbz w0, #0x47060; mov x2, x30; bl #0x6c0c4] | VI: Khởi đầu hàm AArch64 [mov x8, x2; cbz w0, #0x47060; mov x2, x30; bl #0x6c0c4]
uint64_t fde_sub_047038(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34000120ULL) << 32) | 0xAA0203E8ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047038ULL;
}

// FDE #0436 | PC: 0x047080..0x047084 (4 B) | Symbol: _Z8CalcLog2iiPi
// EN: AArch64 prologue [b #0x1ba88] | VI: Khởi đầu hàm AArch64 [b #0x1ba88]
uint64_t fde_sub_047080(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100043FULL) << 32) | 0x17FF5282ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047080ULL;
}

// FDE #0437 | PC: 0x047084..0x04713c (184 B) | Symbol: _Z5f2PowiiPi
// EN: AArch64 prologue [cmp w1, #1; b.lt #0x470ac; mov w8, #0x1f; sub w8, w8, w1] | VI: Khởi đầu hàm AArch64 [cmp w1, #1; b.lt #0x470ac; mov w8, #0x1f; sub w8, w8, w1]
uint64_t fde_sub_047084(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5400012BULL) << 32) | 0x7100043FULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047084ULL;
}

// FDE #0438 | PC: 0x04713c..0x047188 (76 B) | Symbol: _Z5f2Powii
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub x2, x29, #4] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub x2, x29, #4]
uint64_t fde_sub_04713c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04713CULL;
}

// FDE #0439 | PC: 0x047188..0x0471f0 (104 B) | Symbol: _Z4fPowiiiiPi
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_047188(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047188ULL;
}

// FDE #0440 | PC: 0x0471f0..0x047224 (52 B) | Symbol: _Z6fLdPowiiiiPi
// EN: AArch64 prologue [cmp w2, #0; cneg w8, w2, mi; cbz w8, #0x47204; clz w8, w8] | VI: Khởi đầu hàm AArch64 [cmp w2, #0; cneg w8, w2, mi; cbz w8, #0x47204; clz w8, w8]
uint64_t fde_sub_0471f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5A825448ULL) << 32) | 0x7100005FULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0471F0ULL;
}

// FDE #0441 | PC: 0x047224..0x047280 (92 B) | Symbol: _Z6fLdPowiiii
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub x4, x29, #4] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub x4, x29, #4]
uint64_t fde_sub_047224(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047224ULL;
}

// FDE #0442 | PC: 0x047280..0x047350 (208 B) | Symbol: _Z7fPowIntiiiPi
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_047280(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047280ULL;
}

// FDE #0443 | PC: 0x047350..0x047364 (20 B) | Symbol: _Z9mdct_initP6mdct_tPii
// EN: AArch64 prologue [str x1, [x0]; str wzr, [x0, #0x18]; str xzr, [x0, #0x10]; str w2, [x0, #0x20]] | VI: Khởi đầu hàm AArch64 [str x1, [x0]; str wzr, [x0, #0x18]; str xzr, [x0, #0x10]; str w2, [x0, #0x20]]
uint64_t fde_sub_047350(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB900181FULL) << 32) | 0xF9000001ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047350ULL;
}

// FDE #0444 | PC: 0x047364..0x0473d8 (116 B) | Symbol: _Z10imdct_gainPiS_i
// EN: AArch64 prologue [ldr w8, [x1]; ldr w9, [x0]; mov w10, #0x1d; clz w12, w2] | VI: Khởi đầu hàm AArch64 [ldr w8, [x1]; ldr w9, [x0]; mov w10, #0x1d; clz w12, w2]
uint64_t fde_sub_047364(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9400009ULL) << 32) | 0xB9400028ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047364ULL;
}

// FDE #0445 | PC: 0x0473d8..0x047428 (80 B) | Symbol: _Z11imdct_drainP6mdct_tPii
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cmp w2, #1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cmp w2, #1]
uint64_t fde_sub_0473d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0473D8ULL;
}

// FDE #0446 | PC: 0x047428..0x0474b0 (136 B) | Symbol: _Z20imdct_copy_ov_and_nrP6mdct_tPii
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_047428(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047428ULL;
}

// FDE #0447 | PC: 0x0474b0..0x047534 (132 B) | Symbol: _Z22imdct_adapt_parametersP6mdct_tPiS1_iPK8FIXP_SPKi
// EN: AArch64 prologue [ldr w8, [x1]; ldr w10, [x0, #0x10]; ldr w9, [x2]; cbz w10, #0x474cc] | VI: Khởi đầu hàm AArch64 [ldr w8, [x1]; ldr w10, [x0, #0x10]; ldr w9, [x2]; cbz w10, #0x474cc]
uint64_t fde_sub_0474b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB940100AULL) << 32) | 0xB9400028ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0474B0ULL;
}

// FDE #0448 | PC: 0x047534..0x04792c (1016 B) | Symbol: _Z11imdct_blockP6mdct_tPiS1_PKsiiiPK8FIXP_SPKiS6_ii
// EN: AArch64 prologue [mov x8, x30; bl #0x6a86c; mov x30, x8; stp x29, x30, [sp, #0x110]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x6a86c; mov x30, x8; stp x29, x30, [sp, #0x110]]
uint64_t fde_sub_047534(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94008CCDULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x03F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047534ULL;
}

// FDE #0449 | PC: 0x04792c..0x047974 (72 B) | Symbol: sub_04792c
// EN: AArch64 prologue [lsl w8, w4, #0x10; lsl w9, w5, #0x10; smull x10, w8, w2; smull x11, w9, w3] | VI: Khởi đầu hàm AArch64 [lsl w8, w4, #0x10; lsl w9, w5, #0x10; smull x10, w8, w2; smull x11, w9, w3]
uint64_t fde_sub_04792c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x53103CA9ULL) << 32) | 0x53103C88ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04792CULL;
}

// FDE #0450 | PC: 0x047974..0x047e0c (1176 B) | Symbol: _Z24qmfAnalysisFilteringSlotP15QMF_FILTER_BANKPiS1_PKsiS1_
// EN: AArch64 prologue [mov x6, x30; bl #0x6a084; mov x30, x6; stp x29, x30, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [mov x6, x30; bl #0x6a084; mov x30, x6; stp x29, x30, [sp, #0x70]]
uint64_t fde_sub_047974(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940089C3ULL) << 32) | 0xAA1E03E6ULL;
    const uint64_t kPcRange = 0x0498ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047974ULL;
}

// FDE #0451 | PC: 0x047e0c..0x047ea0 (148 B) | Symbol: _Z20qmfAnalysisFilteringP15QMF_FILTER_BANKPPiS2_P16QMF_SCALE_FACTORPKsiS1_
// EN: AArch64 prologue [mov x7, x30; bl #0x6aba8; mov x30, x7; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x7, x30; bl #0x6aba8; mov x30, x7; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_047e0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94008B66ULL) << 32) | 0xAA1E03E7ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047E0CULL;
}

// FDE #0452 | PC: 0x047ea0..0x048630 (1936 B) | Symbol: _Z25qmfSynthesisFilteringSlotP15QMF_FILTER_BANKPKiS2_iiPsiPi
// EN: AArch64 prologue [mov x8, x30; bl #0x69f8c; mov x30, x8; stp x29, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x69f8c; mov x30, x8; stp x29, x30, [sp, #0x90]]
uint64_t fde_sub_047ea0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400883AULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x0790ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047EA0ULL;
}

// FDE #0453 | PC: 0x048630..0x048788 (344 B) | Symbol: sub_048630
// EN: AArch64 prologue [cbz w3, #0x486d8; cmp w3, #1; b.lt #0x486e8; cmp w3, #0x1f] | VI: Khởi đầu hàm AArch64 [cbz w3, #0x486d8; cmp w3, #1; b.lt #0x486e8; cmp w3, #0x1f]
uint64_t fde_sub_048630(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100047FULL) << 32) | 0x34000543ULL;
    const uint64_t kPcRange = 0x0158ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048630ULL;
}

// FDE #0454 | PC: 0x048788..0x048840 (184 B) | Symbol: _Z21qmfSynthesisFilteringP15QMF_FILTER_BANKPPiS2_PK16QMF_SCALE_FACTORiPsiS1_
// EN: AArch64 prologue [mov x8, x30; bl #0x6a084; mov x30, x8; stp x29, x30, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x6a084; mov x30, x8; stp x29, x30, [sp, #0x70]]
uint64_t fde_sub_048788(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400863EULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048788ULL;
}

// FDE #0455 | PC: 0x048840..0x048880 (64 B) | Symbol: _Z25qmfInitAnalysisFilterBankP15QMF_FILTER_BANKPsiiiii
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_048840(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048840ULL;
}

// FDE #0456 | PC: 0x048880..0x048a64 (484 B) | Symbol: sub_048880
// EN: AArch64 prologue [mov x7, x30; bl #0x6a250; mov x30, x7; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x7, x30; bl #0x6a250; mov x30, x7; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_048880(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94008673ULL) << 32) | 0xAA1E03E7ULL;
    const uint64_t kPcRange = 0x01E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048880ULL;
}

// FDE #0457 | PC: 0x048a64..0x048ac0 (92 B) | Symbol: _Z26qmfInitSynthesisFilterBankP15QMF_FILTER_BANKPiiiiii
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_048a64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048A64ULL;
}

// FDE #0458 | PC: 0x048ac0..0x048ae4 (36 B) | Symbol: sub_048ac0
// EN: AArch64 prologue [cbz x0, #0x48ae0; ldr x8, [x0, #8]; cbz x8, #0x48ae0; ldr w9, [x0, #0x2c]] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x48ae0; ldr x8, [x0, #8]; cbz x8, #0x48ae0; ldr w9, [x0, #0x2c]]
uint64_t fde_sub_048ac0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400408ULL) << 32) | 0xB4000100ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048AC0ULL;
}

// FDE #0459 | PC: 0x048ae4..0x048b6c (136 B) | Symbol: _Z23qmfChangeOutScalefactorP15QMF_FILTER_BANKi
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x48b64] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x48b64]
uint64_t fde_sub_048ae4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048AE4ULL;
}

// FDE #0460 | PC: 0x048b6c..0x048b74 (8 B) | Symbol: _Z16qmfChangeOutGainP15QMF_FILTER_BANKi
// EN: AArch64 prologue [str w1, [x0, #0x40]; ret] | VI: Khởi đầu hàm AArch64 [str w1, [x0, #0x40]; ret]
uint64_t fde_sub_048b6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9004001ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048B6CULL;
}

// FDE #0461 | PC: 0x048b74..0x049280 (1804 B) | Symbol: IIS_ScanCmdl
// EN: AArch64 prologue [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_048b74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940084E8ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x070CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048B74ULL;
}

// FDE #0462 | PC: 0x049280..0x0493b8 (312 B) | Symbol: _Z19IIS_ProcessCmdlListPKcPFiiPPcE
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; mov x2, x30; bl #0x69fa8; mov x30, x2] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; mov x2, x30; bl #0x69fa8; mov x30, x2]
uint64_t fde_sub_049280(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E2ULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x0138ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049280ULL;
}

// FDE #0463 | PC: 0x0493b8..0x049414 (92 B) | Symbol: charBuf2HexString
// EN: AArch64 prologue [cbz w2, #0x4940c; adrp x11, #0x6c000; mov x8, xzr; sxtw x9, w2] | VI: Khởi đầu hàm AArch64 [cbz w2, #0x4940c; adrp x11, #0x6c000; mov x8, xzr; sxtw x9, w2]
uint64_t fde_sub_0493b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF000010BULL) << 32) | 0x340002A2ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0493B8ULL;
}

// FDE #0464 | PC: 0x049414..0x0494f0 (220 B) | Symbol: hexString2CharBuf
// EN: AArch64 prologue [mov x3, x30; bl #0x6a250; mov x30, x3; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x6a250; mov x30, x3; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_049414(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400838EULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049414ULL;
}

// FDE #0465 | PC: 0x0494f0..0x049534 (68 B) | Symbol: hexChar2Dec
// EN: AArch64 prologue [sub w8, w0, #0x30; and w9, w8, #0xff; cmp w9, #0xa; b.lo #0x49514] | VI: Khởi đầu hàm AArch64 [sub w8, w0, #0x30; and w9, w8, #0xff; cmp w9, #0xa; b.lo #0x49514]
uint64_t fde_sub_0494f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12001D09ULL) << 32) | 0x5100C008ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0494F0ULL;
}

// FDE #0466 | PC: 0x049534..0x049588 (84 B) | Symbol: FDKprintf
// EN: AArch64 prologue [sub sp, sp, #0x130; stp x28, x19, [sp, #0x110]; stp x29, x30, [sp, #0x120]; add x29, sp, #0x120] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x130; stp x28, x19, [sp, #0x110]; stp x29, x30, [sp, #0x120]; add x29, sp, #0x120]
uint64_t fde_sub_049534(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9114FFCULL) << 32) | 0xD104C3FFULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049534ULL;
}

// FDE #0467 | PC: 0x049588..0x049604 (124 B) | Symbol: FDKprintfErr
// EN: AArch64 prologue [sub sp, sp, #0x130; stp x28, x19, [sp, #0x110]; stp x29, x30, [sp, #0x120]; add x29, sp, #0x120] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x130; stp x28, x19, [sp, #0x110]; stp x29, x30, [sp, #0x120]; add x29, sp, #0x120]
uint64_t fde_sub_049588(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9114FFCULL) << 32) | 0xD104C3FFULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049588ULL;
}

// FDE #0468 | PC: 0x049604..0x049608 (4 B) | Symbol: FDKgetchar
// EN: AArch64 prologue [b #0x1bc18] | VI: Khởi đầu hàm AArch64 [b #0x1bc18]
uint64_t fde_sub_049604(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10483FFULL) << 32) | 0x17FF4985ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049604ULL;
}

// FDE #0469 | PC: 0x049608..0x049660 (88 B) | Symbol: FDKfprintf
// EN: AArch64 prologue [sub sp, sp, #0x120; stp x28, x19, [sp, #0x100]; stp x29, x30, [sp, #0x110]; add x29, sp, #0x110] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; stp x28, x19, [sp, #0x100]; stp x29, x30, [sp, #0x110]; add x29, sp, #0x110]
uint64_t fde_sub_049608(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9104FFCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049608ULL;
}

// FDE #0470 | PC: 0x049660..0x0496c8 (104 B) | Symbol: FDKsprintf
// EN: AArch64 prologue [sub sp, sp, #0x120; stp x28, x19, [sp, #0x100]; stp x29, x30, [sp, #0x110]; add x29, sp, #0x110] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; stp x28, x19, [sp, #0x100]; stp x29, x30, [sp, #0x110]; add x29, sp, #0x110]
uint64_t fde_sub_049660(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9104FFCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049660ULL;
}

// FDE #0471 | PC: 0x0496c8..0x0496cc (4 B) | Symbol: FDKstrchr
// EN: AArch64 prologue [b #0x1bc38] | VI: Khởi đầu hàm AArch64 [b #0x1bc38]
uint64_t fde_sub_0496c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF495FULL) << 32) | 0x17FF495CULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0496C8ULL;
}

// FDE #0472 | PC: 0x0496cc..0x0496d0 (4 B) | Symbol: FDKstrstr
// EN: AArch64 prologue [b #0x1bc48] | VI: Khởi đầu hàm AArch64 [b #0x1bc48]
uint64_t fde_sub_0496cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF4962ULL) << 32) | 0x17FF495FULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0496CCULL;
}

// FDE #0473 | PC: 0x0496d0..0x0496d4 (4 B) | Symbol: FDKstrcpy
// EN: AArch64 prologue [b #0x1bc58] | VI: Khởi đầu hàm AArch64 [b #0x1bc58]
uint64_t fde_sub_0496d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0x17FF4962ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0496D0ULL;
}

// FDE #0474 | PC: 0x0496d4..0x0496ec (24 B) | Symbol: FDKstrncpy
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w2, w2; bl #0x1bc68] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w2, w2; bl #0x1bc68]
uint64_t fde_sub_0496d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0496D4ULL;
}

// FDE #0475 | PC: 0x0496ec..0x0496f0 (4 B) | Symbol: FDKcalloc_L
// EN: AArch64 prologue [b #0x6c79c] | VI: Khởi đầu hàm AArch64 [b #0x6c79c]
uint64_t fde_sub_0496ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A0003E0ULL) << 32) | 0x14008C2CULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0496ECULL;
}

// FDE #0476 | PC: 0x0496f0..0x0496f8 (8 B) | Symbol: FDKmalloc
// EN: AArch64 prologue [mov w0, w0; b #0x1bc78] | VI: Khởi đầu hàm AArch64 [mov w0, w0; b #0x1bc78]
uint64_t fde_sub_0496f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF4961ULL) << 32) | 0x2A0003E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0496F0ULL;
}

// FDE #0477 | PC: 0x0496f8..0x0496fc (4 B) | Symbol: FDKfree_L
// EN: AArch64 prologue [b #0x1a928] | VI: Khởi đầu hàm AArch64 [b #0x1a928]
uint64_t fde_sub_0496f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0x17FF448CULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0496F8ULL;
}

// FDE #0478 | PC: 0x0496fc..0x049724 (40 B) | Symbol: FDKaalloc_L
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x6b184; cbz x0, #0x49714] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x6b184; cbz x0, #0x49714]
uint64_t fde_sub_0496fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0496FCULL;
}

// FDE #0479 | PC: 0x049724..0x04972c (8 B) | Symbol: FDKafree
// EN: AArch64 prologue [ldur x0, [x0, #-8]; b #0x1a928] | VI: Khởi đầu hàm AArch64 [ldur x0, [x0, #-8]; b #0x1a928]
uint64_t fde_sub_049724(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF4480ULL) << 32) | 0xF85F8000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049724ULL;
}

// FDE #0480 | PC: 0x04972c..0x049734 (8 B) | Symbol: FDKmemcpy
// EN: AArch64 prologue [mov w2, w2; b #0x1bc88] | VI: Khởi đầu hàm AArch64 [mov w2, w2; b #0x1bc88]
uint64_t fde_sub_04972c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF4956ULL) << 32) | 0x2A0203E2ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04972CULL;
}

// FDE #0481 | PC: 0x049734..0x04973c (8 B) | Symbol: FDKmemmove
// EN: AArch64 prologue [mov w2, w2; b #0x1bc98] | VI: Khởi đầu hàm AArch64 [mov w2, w2; b #0x1bc98]
uint64_t fde_sub_049734(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF4958ULL) << 32) | 0x2A0203E2ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049734ULL;
}

// FDE #0482 | PC: 0x04973c..0x049744 (8 B) | Symbol: FDKmemset
// EN: AArch64 prologue [mov w2, w2; b #0x1bb28] | VI: Khởi đầu hàm AArch64 [mov w2, w2; b #0x1bb28]
uint64_t fde_sub_04973c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF48FAULL) << 32) | 0x2A0203E2ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04973CULL;
}

// FDE #0483 | PC: 0x049744..0x049750 (12 B) | Symbol: FDKmemclear
// EN: AArch64 prologue [mov w2, w1; mov w1, wzr; b #0x1ba18] | VI: Khởi đầu hàm AArch64 [mov w2, w1; mov w1, wzr; b #0x1ba18]
uint64_t fde_sub_049744(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E1ULL) << 32) | 0x2A0103E2ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049744ULL;
}

// FDE #0484 | PC: 0x049750..0x049764 (20 B) | Symbol: FDKstrlen
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x1bca8; ldp x29, x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x1bca8; ldp x29, x30, [sp], #0x10]
uint64_t fde_sub_049750(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049750ULL;
}

// FDE #0485 | PC: 0x049764..0x04976c (8 B) | Symbol: FDKmemcmp
// EN: AArch64 prologue [mov w2, w2; b #0x1bcb8] | VI: Khởi đầu hàm AArch64 [mov w2, w2; b #0x1bcb8]
uint64_t fde_sub_049764(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF4954ULL) << 32) | 0x2A0203E2ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049764ULL;
}

// FDE #0486 | PC: 0x04976c..0x049770 (4 B) | Symbol: FDKstrcmp
// EN: AArch64 prologue [b #0x1bb38] | VI: Khởi đầu hàm AArch64 [b #0x1bb38]
uint64_t fde_sub_04976c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A0203E2ULL) << 32) | 0x17FF48F3ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04976CULL;
}

// FDE #0487 | PC: 0x049770..0x049778 (8 B) | Symbol: FDKstrncmp
// EN: AArch64 prologue [mov w2, w2; b #0x1bcc8] | VI: Khởi đầu hàm AArch64 [mov w2, w2; b #0x1bcc8]
uint64_t fde_sub_049770(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF4955ULL) << 32) | 0x2A0203E2ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049770ULL;
}

// FDE #0488 | PC: 0x049778..0x049784 (12 B) | Symbol: FDKabs
// EN: AArch64 prologue [cmp w0, #0; cneg w0, w0, mi; ret] | VI: Khởi đầu hàm AArch64 [cmp w0, #0; cneg w0, w0, mi; ret]
uint64_t fde_sub_049778(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5A805400ULL) << 32) | 0x7100001FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049778ULL;
}

// FDE #0489 | PC: 0x049784..0x04978c (8 B) | Symbol: FDKfabs
// EN: AArch64 prologue [fabs d0, d0; ret] | VI: Khởi đầu hàm AArch64 [fabs d0, d0; ret]
uint64_t fde_sub_049784(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x1E60C000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049784ULL;
}

// FDE #0490 | PC: 0x04978c..0x049790 (4 B) | Symbol: FDKpow
// EN: AArch64 prologue [b #0x1bcd8] | VI: Khởi đầu hàm AArch64 [b #0x1bcd8]
uint64_t fde_sub_04978c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E61C000ULL) << 32) | 0x17FF4953ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04978CULL;
}

// FDE #0491 | PC: 0x049790..0x049798 (8 B) | Symbol: FDKsqrt
// EN: AArch64 prologue [fsqrt d0, d0; ret] | VI: Khởi đầu hàm AArch64 [fsqrt d0, d0; ret]
uint64_t fde_sub_049790(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x1E61C000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049790ULL;
}

// FDE #0492 | PC: 0x049798..0x04979c (4 B) | Symbol: FDKatan
// EN: AArch64 prologue [b #0x1bce8] | VI: Khởi đầu hàm AArch64 [b #0x1bce8]
uint64_t fde_sub_049798(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF4957ULL) << 32) | 0x17FF4954ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049798ULL;
}

// FDE #0493 | PC: 0x04979c..0x0497a0 (4 B) | Symbol: FDKlog
// EN: AArch64 prologue [b #0x1bcf8] | VI: Khởi đầu hàm AArch64 [b #0x1bcf8]
uint64_t fde_sub_04979c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF495AULL) << 32) | 0x17FF4957ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04979CULL;
}

// FDE #0494 | PC: 0x0497a0..0x0497a4 (4 B) | Symbol: FDKsin
// EN: AArch64 prologue [b #0x1bd08] | VI: Khởi đầu hàm AArch64 [b #0x1bd08]
uint64_t fde_sub_0497a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF495DULL) << 32) | 0x17FF495AULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0497A0ULL;
}

// FDE #0495 | PC: 0x0497a4..0x0497a8 (4 B) | Symbol: FDKcos
// EN: AArch64 prologue [b #0x1bd18] | VI: Khởi đầu hàm AArch64 [b #0x1bd18]
uint64_t fde_sub_0497a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF4960ULL) << 32) | 0x17FF495DULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0497A4ULL;
}

// FDE #0496 | PC: 0x0497a8..0x0497ac (4 B) | Symbol: FDKexp
// EN: AArch64 prologue [b #0x1bd28] | VI: Khởi đầu hàm AArch64 [b #0x1bd28]
uint64_t fde_sub_0497a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF4963ULL) << 32) | 0x17FF4960ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0497A8ULL;
}

// FDE #0497 | PC: 0x0497ac..0x0497b0 (4 B) | Symbol: FDKatan2
// EN: AArch64 prologue [b #0x1bd38] | VI: Khởi đầu hàm AArch64 [b #0x1bd38]
uint64_t fde_sub_0497ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF4966ULL) << 32) | 0x17FF4963ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0497ACULL;
}

// FDE #0498 | PC: 0x0497b0..0x0497b4 (4 B) | Symbol: FDKacos
// EN: AArch64 prologue [b #0x1bd48] | VI: Khởi đầu hàm AArch64 [b #0x1bd48]
uint64_t fde_sub_0497b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF4969ULL) << 32) | 0x17FF4966ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0497B0ULL;
}

// FDE #0499 | PC: 0x0497b4..0x0497b8 (4 B) | Symbol: FDKtan
// EN: AArch64 prologue [b #0x1bd58] | VI: Khởi đầu hàm AArch64 [b #0x1bd58]
uint64_t fde_sub_0497b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E654000ULL) << 32) | 0x17FF4969ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0497B4ULL;
}

// FDE #0500 | PC: 0x0497b8..0x0497c0 (8 B) | Symbol: FDKfloor
// EN: AArch64 prologue [frintm d0, d0; ret] | VI: Khởi đầu hàm AArch64 [frintm d0, d0; ret]
uint64_t fde_sub_0497b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x1E654000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0497B8ULL;
}

// FDE #0501 | PC: 0x0497c0..0x0497c8 (8 B) | Symbol: FDKceil
// EN: AArch64 prologue [frintp d0, d0; ret] | VI: Khởi đầu hàm AArch64 [frintp d0, d0; ret]
uint64_t fde_sub_0497c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x1E64C000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0497C0ULL;
}

// FDE #0502 | PC: 0x0497c8..0x0497cc (4 B) | Symbol: FDKatoi
// EN: AArch64 prologue [b #0x1bb78] | VI: Khởi đầu hàm AArch64 [b #0x1bb78]
uint64_t fde_sub_0497c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF4967ULL) << 32) | 0x17FF48ECULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0497C8ULL;
}

// FDE #0503 | PC: 0x0497cc..0x0497d0 (4 B) | Symbol: FDKatol
// EN: AArch64 prologue [b #0x1bd68] | VI: Khởi đầu hàm AArch64 [b #0x1bd68]
uint64_t fde_sub_0497cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0x17FF4967ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0497CCULL;
}

// FDE #0504 | PC: 0x0497d0..0x0497e8 (24 B) | Symbol: FDKatof
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x1bd78; fcvt s0, d0] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x1bd78; fcvt s0, d0]
uint64_t fde_sub_0497d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0497D0ULL;
}

// FDE #0505 | PC: 0x0497e8..0x0497ec (4 B) | Symbol: FDKfopen
// EN: AArch64 prologue [b #0x1bba8] | VI: Khởi đầu hàm AArch64 [b #0x1bba8]
uint64_t fde_sub_0497e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF48FBULL) << 32) | 0x17FF48F0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0497E8ULL;
}

// FDE #0506 | PC: 0x0497ec..0x0497f0 (4 B) | Symbol: FDKfclose
// EN: AArch64 prologue [b #0x1bbd8] | VI: Khởi đầu hàm AArch64 [b #0x1bbd8]
uint64_t fde_sub_0497ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x93407C21ULL) << 32) | 0x17FF48FBULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0497ECULL;
}

// FDE #0507 | PC: 0x0497f0..0x0497f8 (8 B) | Symbol: FDKfseek
// EN: AArch64 prologue [sxtw x1, w1; b #0x1bd88] | VI: Khởi đầu hàm AArch64 [sxtw x1, w1; b #0x1bd88]
uint64_t fde_sub_0497f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF4965ULL) << 32) | 0x93407C21ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0497F0ULL;
}

// FDE #0508 | PC: 0x0497f8..0x04980c (20 B) | Symbol: FDKftell
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x1bd98; ldp x29, x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x1bd98; ldp x29, x30, [sp], #0x10]
uint64_t fde_sub_0497f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0497F8ULL;
}

// FDE #0509 | PC: 0x04980c..0x049810 (4 B) | Symbol: FDKfflush
// EN: AArch64 prologue [b #0x1bda8] | VI: Khởi đầu hàm AArch64 [b #0x1bda8]
uint64_t fde_sub_04980c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0x17FF4967ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04980CULL;
}

// FDE #0510 | PC: 0x049810..0x04982c (28 B) | Symbol: FDKfwrite
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w2, w2; sxtw x1, w1] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w2, w2; sxtw x1, w1]
uint64_t fde_sub_049810(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049810ULL;
}

// FDE #0511 | PC: 0x04982c..0x049848 (28 B) | Symbol: FDKfread
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w2, w2; sxtw x1, w1] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w2, w2; sxtw x1, w1]
uint64_t fde_sub_04982c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04982CULL;
}

// FDE #0512 | PC: 0x049848..0x04984c (4 B) | Symbol: FDKfgets
// EN: AArch64 prologue [b #0x1bdc8] | VI: Khởi đầu hàm AArch64 [b #0x1bdc8]
uint64_t fde_sub_049848(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E1ULL) << 32) | 0x17FF4960ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049848ULL;
}

// FDE #0513 | PC: 0x04984c..0x049858 (12 B) | Symbol: FDKrewind
// EN: AArch64 prologue [mov x1, xzr; mov w2, wzr; b #0x1bd88] | VI: Khởi đầu hàm AArch64 [mov x1, xzr; mov w2, wzr; b #0x1bd88]
uint64_t fde_sub_04984c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E2ULL) << 32) | 0xAA1F03E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04984CULL;
}

// FDE #0514 | PC: 0x049858..0x049878 (32 B) | Symbol: FDKfwrite_EL
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w19, w2] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w19, w2]
uint64_t fde_sub_049858(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049858ULL;
}

// FDE #0515 | PC: 0x049878..0x04993c (196 B) | Symbol: FDKfread_EL
// EN: AArch64 prologue [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_049878(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049878ULL;
}

// FDE #0516 | PC: 0x04993c..0x049940 (4 B) | Symbol: FDKfeof
// EN: AArch64 prologue [b #0x1bdf8] | VI: Khởi đầu hàm AArch64 [b #0x1bdf8]
uint64_t fde_sub_04993c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000140ULL) << 32) | 0x17FF492FULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04993CULL;
}

// FDE #0517 | PC: 0x049940..0x04994c (12 B) | Symbol: FDKprintDisclaimer
// EN: AArch64 prologue [adrp x0, #0x72000; add x0, x0, #0xb3b; b #0x1baf8] | VI: Khởi đầu hàm AArch64 [adrp x0, #0x72000; add x0, x0, #0xb3b; b #0x1baf8]
uint64_t fde_sub_049940(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x912CEC00ULL) << 32) | 0xB0000140ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049940ULL;
}

// FDE #0518 | PC: 0x04994c..0x049cd0 (900 B) | Symbol: WAV_InputOpen
// EN: AArch64 prologue [sub sp, sp, #0x80; str x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]]
uint64_t fde_sub_04994c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF9ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0384ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04994CULL;
}

// FDE #0519 | PC: 0x049cd0..0x049e50 (384 B) | Symbol: WAV_InputRead
// EN: AArch64 prologue [mov x4, x30; bl #0x6a250; mov x30, x4; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x4, x30; bl #0x6a250; mov x30, x4; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_049cd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400815FULL) << 32) | 0xAA1E03E4ULL;
    const uint64_t kPcRange = 0x0180ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049CD0ULL;
}

// FDE #0520 | PC: 0x049e50..0x049e84 (52 B) | Symbol: WAV_InputClose
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0]]
uint64_t fde_sub_049e50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049E50ULL;
}

// FDE #0521 | PC: 0x049e84..0x04a004 (384 B) | Symbol: WAV_OutputOpen
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_049e84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0180ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049E84ULL;
}

// FDE #0522 | PC: 0x04a004..0x04a0f8 (244 B) | Symbol: WAV_OutputWrite
// EN: AArch64 prologue [mov x5, x30; bl #0x69f4c; mov x30, x5; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x5, x30; bl #0x69f4c; mov x30, x5; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_04a004(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94007FD1ULL) << 32) | 0xAA1E03E5ULL;
    const uint64_t kPcRange = 0x00F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A004ULL;
}

// FDE #0523 | PC: 0x04a0f8..0x04a190 (152 B) | Symbol: WAV_OutputClose
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0]]
uint64_t fde_sub_04a0f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A0F8ULL;
}

// FDE #0524 | PC: 0x04a190..0x04a2cc (316 B) | Symbol: _Z21adifRead_DecodeHeaderP11CAdifHeaderP14CProgramConfigP13FDK_BITSTREAM
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_04a190(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x013CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A190ULL;
}

// FDE #0525 | PC: 0x04a2cc..0x04a2e0 (20 B) | Symbol: _Z16adtsRead_CrcInitP11STRUCT_ADTS
// EN: AArch64 prologue [add x0, x0, #0x18; mov w1, #0x8005; mov w2, #0xffff; mov w3, #0x10] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x18; mov w1, #0x8005; mov w2, #0xffff; mov w3, #0x10]
uint64_t fde_sub_04a2cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x529000A1ULL) << 32) | 0x91006000ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A2CCULL;
}

// FDE #0526 | PC: 0x04a2e0..0x04a2f4 (20 B) | Symbol: _Z20adtsRead_CrcStartRegP11STRUCT_ADTSP13FDK_BITSTREAMi
// EN: AArch64 prologue [ldrb w8, [x0, #2]; cbz w8, #0x4a2ec; b #0x6a02c; add x0, x0, #0x18] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #2]; cbz w8, #0x4a2ec; b #0x6a02c; add x0, x0, #0x18]
uint64_t fde_sub_04a2e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34000048ULL) << 32) | 0x39400808ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A2E0ULL;
}

// FDE #0527 | PC: 0x04a2f4..0x04a308 (20 B) | Symbol: _Z18adtsRead_CrcEndRegP11STRUCT_ADTSP13FDK_BITSTREAMi
// EN: AArch64 prologue [ldrb w8, [x0, #2]; cbz w8, #0x4a300; ret; add x0, x0, #0x18] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #2]; cbz w8, #0x4a300; ret; add x0, x0, #0x18]
uint64_t fde_sub_04a2f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34000048ULL) << 32) | 0x39400808ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A2F4ULL;
}

// FDE #0528 | PC: 0x04a308..0x04a330 (40 B) | Symbol: _Z17adtsRead_CrcCheckP11STRUCT_ADTS
// EN: AArch64 prologue [ldrb w8, [x0, #2]; cbz w8, #0x4a314; b #0x6a02c; ldrh w8, [x0, #0x52]] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #2]; cbz w8, #0x4a314; b #0x6a02c; ldrh w8, [x0, #0x52]]
uint64_t fde_sub_04a308(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34000048ULL) << 32) | 0x39400808ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A308ULL;
}

// FDE #0529 | PC: 0x04a330..0x04a728 (1016 B) | Symbol: _Z21adtsRead_DecodeHeaderP11STRUCT_ADTSP21CSAudioSpecificConfigP13FDK_BITSTREAMi
// EN: AArch64 prologue [mov x4, x30; bl #0x69f18; mov x30, x4; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x4, x30; bl #0x69f18; mov x30, x4; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_04a330(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94007EF9ULL) << 32) | 0xAA1E03E4ULL;
    const uint64_t kPcRange = 0x03F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A330ULL;
}

// FDE #0530 | PC: 0x04a728..0x04a78c (100 B) | Symbol: _Z30adtsRead_GetRawDataBlockLengthP11STRUCT_ADTSi
// EN: AArch64 prologue [ldrb w8, [x0, #0x10]; cbz w8, #0x4a740; ldrb w8, [x0, #2]; cbz w8, #0x4a764] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x10]; cbz w8, #0x4a740; ldrb w8, [x0, #2]; cbz w8, #0x4a764]
uint64_t fde_sub_04a728(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x340000A8ULL) << 32) | 0x39404008ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A728ULL;
}

// FDE #0531 | PC: 0x04a78c..0x04a794 (8 B) | Symbol: _Z20CProgramConfig_ResetP14CProgramConfig
// EN: AArch64 prologue [strb wzr, [x0, #0x1d0]; ret] | VI: Khởi đầu hàm AArch64 [strb wzr, [x0, #0x1d0]; ret]
uint64_t fde_sub_04a78c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x3907401FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A78CULL;
}

// FDE #0532 | PC: 0x04a794..0x04a7b8 (36 B) | Symbol: _Z19CProgramConfig_InitP14CProgramConfig
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w1, #0x1d1] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w1, #0x1d1]
uint64_t fde_sub_04a794(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A794ULL;
}

// FDE #0533 | PC: 0x04a7b8..0x04a7c0 (8 B) | Symbol: _Z22CProgramConfig_IsValidPK14CProgramConfig
// EN: AArch64 prologue [ldrb w8, [x0, #0x1cd]; b #0x6c854] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x1cd]; b #0x6c854]
uint64_t fde_sub_04a7b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14008826ULL) << 32) | 0x39473408ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A7B8ULL;
}

// FDE #0534 | PC: 0x04a7c0..0x04abb8 (1016 B) | Symbol: _Z19CProgramConfig_ReadP14CProgramConfigP13FDK_BITSTREAMj
// EN: AArch64 prologue [sub sp, sp, #0xc0; str x27, [sp, #0x60]; stp x26, x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; str x27, [sp, #0x60]; stp x26, x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]]
uint64_t fde_sub_04a7c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90033FBULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x03F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A7C0ULL;
}

// FDE #0535 | PC: 0x04abb8..0x04ad90 (472 B) | Symbol: _Z22CProgramConfig_ComparePK14CProgramConfigS1_
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w2, #0x1d1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w2, #0x1d1]
uint64_t fde_sub_04abb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x01D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04ABB8ULL;
}

// FDE #0536 | PC: 0x04ad90..0x04afe0 (592 B) | Symbol: _Z25CProgramConfig_GetDefaultP14CProgramConfigj
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x6c7c4] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x6c7c4]
uint64_t fde_sub_04ad90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0250ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AD90ULL;
}

// FDE #0537 | PC: 0x04afe0..0x04b7cc (2028 B) | Symbol: _Z28CProgramConfig_LookupElementP14CProgramConfigjjjPhP18AUDIO_CHANNEL_TYPES1_S1_P14MP4_ELEMENT_IDS4_
// EN: AArch64 prologue [sub sp, sp, #0xa0; str x23, [sp, #0x60]; stp x22, x21, [sp, #0x70]; stp x20, x19, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; str x23, [sp, #0x60]; stp x22, x21, [sp, #0x70]; stp x20, x19, [sp, #0x80]]
uint64_t fde_sub_04afe0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90033F7ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x07ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AFE0ULL;
}

// FDE #0538 | PC: 0x04b7cc..0x04b98c (448 B) | Symbol: _Z30CProgramConfig_GetElementTablePK14CProgramConfigP14MP4_ELEMENT_IDiPh
// EN: AArch64 prologue [mov x4, x30; bl #0x69f18; mov x30, x4; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x4, x30; bl #0x69f18; mov x30, x4; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_04b7cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940079D2ULL) << 32) | 0xAA1E03E4ULL;
    const uint64_t kPcRange = 0x01C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B7CCULL;
}

// FDE #0539 | PC: 0x04b98c..0x04b9cc (64 B) | Symbol: _Z24AudioSpecificConfig_InitP21CSAudioSpecificConfig
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w1, #0x218] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w1, #0x218]
uint64_t fde_sub_04b98c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B98CULL;
}

// FDE #0540 | PC: 0x04b9cc..0x04bf88 (1468 B) | Symbol: _Z25AudioSpecificConfig_ParseP21CSAudioSpecificConfigP13FDK_BITSTREAMiP13CSTpCallBacks
// EN: AArch64 prologue [mov x4, x30; bl #0x6a250; mov x30, x4; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x4, x30; bl #0x6a250; mov x30, x4; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_04b9cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94007A20ULL) << 32) | 0xAA1E03E4ULL;
    const uint64_t kPcRange = 0x05BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B9CCULL;
}

// FDE #0541 | PC: 0x04bf88..0x04bfb8 (48 B) | Symbol: sub_04bf88
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w1, #5] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w1, #5]
uint64_t fde_sub_04bf88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04BF88ULL;
}

// FDE #0542 | PC: 0x04bfb8..0x04c01c (100 B) | Symbol: sub_04bfb8
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04bfb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04BFB8ULL;
}

// FDE #0543 | PC: 0x04c01c..0x04c1cc (432 B) | Symbol: _Z26DrmRawSdcAudioConfig_ParseP21CSAudioSpecificConfigP13FDK_BITSTREAM
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_04c01c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x01B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C01CULL;
}

// FDE #0544 | PC: 0x04c1cc..0x04c1dc (16 B) | Symbol: _Z15drmRead_CrcInitP10STRUCT_DRM
// EN: AArch64 prologue [mov w1, #0x1d; mov w2, #0xffff; mov w3, #8; b #0x1be18] | VI: Khởi đầu hàm AArch64 [mov w1, #0x1d; mov w2, #0xffff; mov w3, #8; b #0x1be18]
uint64_t fde_sub_04c1cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x529FFFE2ULL) << 32) | 0x528003A1ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C1CCULL;
}

// FDE #0545 | PC: 0x04c1dc..0x04c220 (68 B) | Symbol: _Z19drmRead_CrcStartRegP10STRUCT_DRMP13FDK_BITSTREAMi
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04c1dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C1DCULL;
}

// FDE #0546 | PC: 0x04c220..0x04c224 (4 B) | Symbol: _Z17drmRead_CrcEndRegP10STRUCT_DRMP13FDK_BITSTREAMi
// EN: AArch64 prologue [b #0x1be38] | VI: Khởi đầu hàm AArch64 [b #0x1be38]
uint64_t fde_sub_04c220(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x79407408ULL) << 32) | 0x17FF3F06ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C220ULL;
}

// FDE #0547 | PC: 0x04c224..0x04c244 (32 B) | Symbol: _Z16drmRead_CrcCheckP10STRUCT_DRM
// EN: AArch64 prologue [ldrh w8, [x0, #0x3a]; ldrh w9, [x0, #0x48]; ldrh w10, [x0, #0x50]; lsl w8, w8, #1] | VI: Khởi đầu hàm AArch64 [ldrh w8, [x0, #0x3a]; ldrh w9, [x0, #0x48]; ldrh w10, [x0, #0x50]; lsl w8, w8, #1]
uint64_t fde_sub_04c224(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x79409009ULL) << 32) | 0x79407408ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C224ULL;
}

// FDE #0548 | PC: 0x04c244..0x04c340 (252 B) | Symbol: _Z15CLatmDemux_ReadP13FDK_BITSTREAMP10CLatmDemux14TRANSPORT_TYPEP13CSTpCallBacksP21CSAudioSpecificConfigPii
// EN: AArch64 prologue [mov x7, x30; bl #0x6aba8; mov x30, x7; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x7, x30; bl #0x6aba8; mov x30, x7; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_04c244(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94007A58ULL) << 32) | 0xAA1E03E7ULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C244ULL;
}

// FDE #0549 | PC: 0x04c340..0x04c6cc (908 B) | Symbol: _Z30CLatmDemux_ReadStreamMuxConfigP13FDK_BITSTREAMP10CLatmDemuxP13CSTpCallBacksP21CSAudioSpecificConfigPi
// EN: AArch64 prologue [mov x5, x30; bl #0x6a894; mov x30, x5; stp x29, x30, [sp, #0xe0]] | VI: Khởi đầu hàm AArch64 [mov x5, x30; bl #0x6a894; mov x30, x5; stp x29, x30, [sp, #0xe0]]
uint64_t fde_sub_04c340(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94007954ULL) << 32) | 0xAA1E03E5ULL;
    const uint64_t kPcRange = 0x038CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C340ULL;
}

// FDE #0550 | PC: 0x04c6cc..0x04c784 (184 B) | Symbol: _Z32CLatmDemux_ReadPayloadLengthInfoP13FDK_BITSTREAMP10CLatmDemux
// EN: AArch64 prologue [mov x2, x30; bl #0x6aba8; mov x30, x2; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x6aba8; mov x30, x2; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_04c6cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94007936ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C6CCULL;
}

// FDE #0551 | PC: 0x04c784..0x04c7bc (56 B) | Symbol: _Z32CLatmDemux_ReadAuChunkLengthInfoP13FDK_BITSTREAM
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_04c784(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C784ULL;
}

// FDE #0552 | PC: 0x04c7bc..0x04c808 (76 B) | Symbol: sub_04c7bc
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04c7bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C7BCULL;
}

// FDE #0553 | PC: 0x04c808..0x04c810 (8 B) | Symbol: _Z34CLatmDemux_GetOtherDataPresentFlagP10CLatmDemux
// EN: AArch64 prologue [ldrb w8, [x0, #0x34]; b #0x6c854] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x34]; b #0x6c854]
uint64_t fde_sub_04c808(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14008012ULL) << 32) | 0x3940D008ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C808ULL;
}

// FDE #0554 | PC: 0x04c810..0x04c818 (8 B) | Symbol: _Z29CLatmDemux_GetOtherDataLengthP10CLatmDemux
// EN: AArch64 prologue [ldr w0, [x0, #0x24]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0x24]; ret]
uint64_t fde_sub_04c810(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9402400ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C810ULL;
}

// FDE #0555 | PC: 0x04c818..0x04c820 (8 B) | Symbol: _Z27CLatmDemux_GetNrOfSubFramesP10CLatmDemux
// EN: AArch64 prologue [ldrb w0, [x0, #0x30]; ret] | VI: Khởi đầu hàm AArch64 [ldrb w0, [x0, #0x30]; ret]
uint64_t fde_sub_04c818(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x3940C000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C818ULL;
}

// FDE #0556 | PC: 0x04c820..0x04c82c (12 B) | Symbol: _Z23GetRam_TransportDecoderi
// EN: AArch64 prologue [mov w0, #1; mov w1, #0x590; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #1; mov w1, #0x590; b #0x1a748]
uint64_t fde_sub_04c820(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5280B201ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C820ULL;
}

// FDE #0557 | PC: 0x04c82c..0x04c834 (8 B) | Symbol: _Z34GetRequiredMemRam_TransportDecoderv
// EN: AArch64 prologue [mov w0, #0x590; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x590; ret]
uint64_t fde_sub_04c82c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x5280B200ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C82CULL;
}

// FDE #0558 | PC: 0x04c834..0x04c92c (248 B) | Symbol: _Z17transportDec_Open14TRANSPORT_TYPEj
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_04c834(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C834ULL;
}

// FDE #0559 | PC: 0x04c92c..0x04c990 (100 B) | Symbol: _Z18transportDec_ClosePP12TRANSPORTDEC
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x4c988] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x4c988]
uint64_t fde_sub_04c92c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C92CULL;
}

// FDE #0560 | PC: 0x04c990..0x04cac4 (308 B) | Symbol: _Z28transportDec_OutOfBandConfigP12TRANSPORTDECPhjj
// EN: AArch64 prologue [sub sp, sp, #0x80; str x21, [sp, #0x50]; stp x20, x19, [sp, #0x60]; stp x29, x30, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x21, [sp, #0x50]; stp x20, x19, [sp, #0x60]; stp x29, x30, [sp, #0x70]]
uint64_t fde_sub_04c990(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9002BF5ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0134ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C990ULL;
}

// FDE #0561 | PC: 0x04cac4..0x04cadc (24 B) | Symbol: _Z32transportDec_RegisterAscCallbackP12TRANSPORTDECPFiPvPK21CSAudioSpecificConfigES1_
// EN: AArch64 prologue [cbz x0, #0x4cad8; mov x8, x0; mov w0, wzr; stp x1, x2, [x8, #8]] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x4cad8; mov x8, x0; mov w0, wzr; stp x1, x2, [x8, #8]]
uint64_t fde_sub_04cac4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003E8ULL) << 32) | 0xB40000A0ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04CAC4ULL;
}

// FDE #0562 | PC: 0x04cadc..0x04caf4 (24 B) | Symbol: _Z32transportDec_RegisterSscCallbackP12TRANSPORTDECPFiPvP13FDK_BITSTREAM17AUDIO_OBJECT_TYPEiiiES1_
// EN: AArch64 prologue [cbz x0, #0x4caf0; mov x8, x0; mov w0, wzr; stp x1, x2, [x8, #0x18]] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x4caf0; mov x8, x0; mov w0, wzr; stp x1, x2, [x8, #0x18]]
uint64_t fde_sub_04cadc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003E8ULL) << 32) | 0xB40000A0ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04CADCULL;
}

// FDE #0563 | PC: 0x04caf4..0x04cb0c (24 B) | Symbol: _Z32transportDec_RegisterSbrCallbackP12TRANSPORTDECPFiPvP13FDK_BITSTREAMiii17AUDIO_OBJECT_TYPE14MP4_ELEMENT_IDiES1_
// EN: AArch64 prologue [cbz x0, #0x4cb08; mov x8, x0; mov w0, wzr; stp x1, x2, [x8, #0x28]] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x4cb08; mov x8, x0; mov w0, wzr; stp x1, x2, [x8, #0x28]]
uint64_t fde_sub_04caf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003E8ULL) << 32) | 0xB40000A0ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04CAF4ULL;
}

// FDE #0564 | PC: 0x04cb0c..0x04cbf8 (236 B) | Symbol: _Z21transportDec_FillDataP12TRANSPORTDECPhjPji
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_04cb0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04CB0CULL;
}

// FDE #0565 | PC: 0x04cbf8..0x04cc08 (16 B) | Symbol: _Z25transportDec_GetBitstreamP12TRANSPORTDECj
// EN: AArch64 prologue [mov w8, #0x38; umaddl x8, w1, w8, x0; add x0, x8, #0x38; ret] | VI: Khởi đầu hàm AArch64 [mov w8, #0x38; umaddl x8, w1, w8, x0; add x0, x8, #0x38; ret]
uint64_t fde_sub_04cbf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9BA80028ULL) << 32) | 0x52800708ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04CBF8ULL;
}

// FDE #0566 | PC: 0x04cc08..0x04cc68 (96 B) | Symbol: _Z30transportDec_GetBufferFullnessP12TRANSPORTDEC
// EN: AArch64 prologue [ldr w8, [x0]; sub w9, w8, #6; cmp w9, #2; ccmp w8, #0xa, #4, hs] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0]; sub w9, w8, #6; cmp w9, #2; ccmp w8, #0xa, #4, hs]
uint64_t fde_sub_04cc08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x51001909ULL) << 32) | 0xB9400008ULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04CC08ULL;
}

// FDE #0567 | PC: 0x04cc68..0x04cf54 (748 B) | Symbol: _Z27transportDec_ReadAccessUnitP12TRANSPORTDECj
// EN: AArch64 prologue [sub sp, sp, #0x80; str x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_04cc68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013FBULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x02ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04CC68ULL;
}

// FDE #0568 | PC: 0x04cf54..0x04d1fc (680 B) | Symbol: sub_04cf54
// EN: AArch64 prologue [mov x8, x30; bl #0x6a084; mov x30, x8; stp x29, x30, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x6a084; mov x30, x8; stp x29, x30, [sp, #0x70]]
uint64_t fde_sub_04cf54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400744BULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x02A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04CF54ULL;
}

// FDE #0569 | PC: 0x04d1fc..0x04d780 (1412 B) | Symbol: sub_04d1fc
// EN: AArch64 prologue [sub sp, sp, #0x140; stp x28, x27, [sp, #0xe0]; stp x26, x25, [sp, #0xf0]; stp x24, x23, [sp, #0x100]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x140; stp x28, x27, [sp, #0xe0]; stp x26, x25, [sp, #0xf0]; stp x24, x23, [sp, #0x100]]
uint64_t fde_sub_04d1fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90E6FFCULL) << 32) | 0xD10503FFULL;
    const uint64_t kPcRange = 0x0584ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D1FCULL;
}

// FDE #0570 | PC: 0x04d780..0x04d8a4 (292 B) | Symbol: sub_04d780
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_04d780(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0124ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D780ULL;
}

// FDE #0571 | PC: 0x04d8a4..0x04d908 (100 B) | Symbol: _Z31transportDec_GetAuBitsRemainingP12TRANSPORTDECj
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; add x8, x0, w1, uxtw #2] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; add x8, x0, w1, uxtw #2]
uint64_t fde_sub_04d8a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D8A4ULL;
}

// FDE #0572 | PC: 0x04d908..0x04d914 (12 B) | Symbol: _Z27transportDec_GetAuBitsTotalP12TRANSPORTDECj
// EN: AArch64 prologue [add x8, x0, w1, uxtw #2; ldr w0, [x8, #0x564]; ret] | VI: Khởi đầu hàm AArch64 [add x8, x0, w1, uxtw #2; ldr w0, [x8, #0x564]; ret]
uint64_t fde_sub_04d908(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9456500ULL) << 32) | 0x8B214808ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D908ULL;
}

// FDE #0573 | PC: 0x04d914..0x04d920 (12 B) | Symbol: _Z38transportDec_GetMissingAccessUnitCountPiP12TRANSPORTDEC
// EN: AArch64 prologue [ldr w8, [x1, #0x57c]; str w8, [x0]; b #0x6a02c] | VI: Khởi đầu hàm AArch64 [ldr w8, [x1, #0x57c]; str w8, [x0]; b #0x6a02c]
uint64_t fde_sub_04d914(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9000008ULL) << 32) | 0xB9457C28ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D914ULL;
}

// FDE #0574 | PC: 0x04d920..0x04d924 (4 B) | Symbol: _Z26transportDec_EndAccessUnitP12TRANSPORTDEC
// EN: AArch64 prologue [b #0x4d780] | VI: Khởi đầu hàm AArch64 [b #0x4d780]
uint64_t fde_sub_04d920(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x51000428ULL) << 32) | 0x17FFFF98ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D920ULL;
}

// FDE #0575 | PC: 0x04d924..0x04da2c (264 B) | Symbol: _Z21transportDec_SetParamP12TRANSPORTDEC11TPDEC_PARAMi
// EN: AArch64 prologue [sub w8, w1, #1; cmp w8, #5; b.hi #0x4da28; adrp x9, #0x6c000] | VI: Khởi đầu hàm AArch64 [sub w8, w1, #1; cmp w8, #5; b.hi #0x4da28; adrp x9, #0x6c000]
uint64_t fde_sub_04d924(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100151FULL) << 32) | 0x51000428ULL;
    const uint64_t kPcRange = 0x0108ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D924ULL;
}

// FDE #0576 | PC: 0x04da2c..0x04da64 (56 B) | Symbol: _Z29transportDec_GetNrOfSubFramesP12TRANSPORTDEC
// EN: AArch64 prologue [cbz x0, #0x4da5c; ldr w8, [x0]; sub w9, w8, #6; cmp w9, #2] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x4da5c; ldr w8, [x0]; sub w9, w8, #6; cmp w9, #2]
uint64_t fde_sub_04da2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9400008ULL) << 32) | 0xB4000180ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04DA2CULL;
}

// FDE #0577 | PC: 0x04da64..0x04dae4 (128 B) | Symbol: _Z23transportDec_GetLibInfoP8LIB_INFO
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x4da90] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x4da90]
uint64_t fde_sub_04da64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04DA64ULL;
}

// FDE #0578 | PC: 0x04dae4..0x04db20 (60 B) | Symbol: _Z24transportDec_CrcStartRegP12TRANSPORTDECi
// EN: AArch64 prologue [ldr w8, [x0]; mov w2, w1; cmp w8, #0xc; b.eq #0x4db0c] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0]; mov w2, w1; cmp w8, #0xc; b.eq #0x4db0c]
uint64_t fde_sub_04dae4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A0103E2ULL) << 32) | 0xB9400008ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04DAE4ULL;
}

// FDE #0579 | PC: 0x04db20..0x04db5c (60 B) | Symbol: _Z22transportDec_CrcEndRegP12TRANSPORTDECi
// EN: AArch64 prologue [ldr w8, [x0]; mov w2, w1; cmp w8, #0xc; b.eq #0x4db48] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0]; mov w2, w1; cmp w8, #0xc; b.eq #0x4db48]
uint64_t fde_sub_04db20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A0103E2ULL) << 32) | 0xB9400008ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04DB20ULL;
}

// FDE #0580 | PC: 0x04db5c..0x04dbc0 (100 B) | Symbol: _Z21transportDec_CrcCheckP12TRANSPORTDEC
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0]]
uint64_t fde_sub_04db5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04DB5CULL;
}

// FDE #0581 | PC: 0x04dbc0..0x04dcbc (252 B) | Symbol: _Z22adifWrite_EncodeHeaderP9ADIF_INFOP13FDK_BITSTREAMi
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_04dbc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04DBC0ULL;
}

// FDE #0582 | PC: 0x04dcbc..0x04dce8 (44 B) | Symbol: _Z23adifWrite_GetHeaderBitsP9ADIF_INFO
// EN: AArch64 prologue [ldr w8, [x0, #0x18]; cbz w8, #0x4dcc8; b #0x6a02c; ldr w8, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #0x18]; cbz w8, #0x4dcc8; b #0x6a02c; ldr w8, [x0, #0x10]]
uint64_t fde_sub_04dcbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34000048ULL) << 32) | 0xB9401808ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04DCBCULL;
}

// FDE #0583 | PC: 0x04dce8..0x04dcfc (20 B) | Symbol: _Z21adtsWrite_CrcStartRegP11STRUCT_ADTSP13FDK_BITSTREAMi
// EN: AArch64 prologue [ldrb w8, [x0, #0xb]; cbz w8, #0x4dcf4; b #0x6a02c; add x0, x0, #0x28] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0xb]; cbz w8, #0x4dcf4; b #0x6a02c; add x0, x0, #0x28]
uint64_t fde_sub_04dce8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34000048ULL) << 32) | 0x39402C08ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04DCE8ULL;
}

// FDE #0584 | PC: 0x04dcfc..0x04dd10 (20 B) | Symbol: _Z19adtsWrite_CrcEndRegP11STRUCT_ADTSP13FDK_BITSTREAMi
// EN: AArch64 prologue [ldrb w8, [x0, #0xb]; cbz w8, #0x4dd08; ret; add x0, x0, #0x28] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0xb]; cbz w8, #0x4dd08; ret; add x0, x0, #0x28]
uint64_t fde_sub_04dcfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34000048ULL) << 32) | 0x39402C08ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04DCFCULL;
}

// FDE #0585 | PC: 0x04dd10..0x04dd64 (84 B) | Symbol: _Z23adtsWrite_GetHeaderBitsP11STRUCT_ADTS
// EN: AArch64 prologue [ldr w9, [x0, #0x1c]; ldrb w8, [x0, #0xb]; cbz w9, #0x4dd28; cbz w8, #0x4dd34] | VI: Khởi đầu hàm AArch64 [ldr w9, [x0, #0x1c]; ldrb w8, [x0, #0xb]; cbz w9, #0x4dd28; cbz w8, #0x4dd34]
uint64_t fde_sub_04dd10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39402C08ULL) << 32) | 0xB9401C09ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04DD10ULL;
}

// FDE #0586 | PC: 0x04dd64..0x04de34 (208 B) | Symbol: _Z14adtsWrite_InitP11STRUCT_ADTSP12CODER_CONFIG
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x1, #0x24]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x1, #0x24]]
uint64_t fde_sub_04dd64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04DD64ULL;
}

// FDE #0587 | PC: 0x04de34..0x04dfd0 (412 B) | Symbol: _Z22adtsWrite_EncodeHeaderP11STRUCT_ADTSP13FDK_BITSTREAMii
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_04de34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x019CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04DE34ULL;
}

// FDE #0588 | PC: 0x04dfd0..0x04e184 (436 B) | Symbol: _Z25adtsWrite_EndRawDataBlockP11STRUCT_ADTSP13FDK_BITSTREAMPi
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_04dfd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90457F6ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04DFD0ULL;
}

// FDE #0589 | PC: 0x04e184..0x04e194 (16 B) | Symbol: _Z16getChannelConfig12CHANNEL_MODE
// EN: AArch64 prologue [sub w8, w0, #1; cmp w8, #7; csel w0, w0, wzr, lo; ret] | VI: Khởi đầu hàm AArch64 [sub w8, w0, #1; cmp w8, #7; csel w0, w0, wzr, lo; ret]
uint64_t fde_sub_04e184(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x71001D1FULL) << 32) | 0x51000408ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E184ULL;
}

uint64_t DispatchFdeShard2(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x038004ULL: return fde_sub_038004(a0, a1, a2);
        case 0x038304ULL: return fde_sub_038304(a0, a1, a2);
        case 0x0384d4ULL: return fde_sub_0384d4(a0, a1, a2);
        case 0x0385e4ULL: return fde_sub_0385e4(a0, a1, a2);
        case 0x038754ULL: return fde_sub_038754(a0, a1, a2);
        case 0x038788ULL: return fde_sub_038788(a0, a1, a2);
        case 0x03888cULL: return fde_sub_03888c(a0, a1, a2);
        case 0x038ec8ULL: return fde_sub_038ec8(a0, a1, a2);
        case 0x038f9cULL: return fde_sub_038f9c(a0, a1, a2);
        case 0x039014ULL: return fde_sub_039014(a0, a1, a2);
        case 0x0390d8ULL: return fde_sub_0390d8(a0, a1, a2);
        case 0x0391e4ULL: return fde_sub_0391e4(a0, a1, a2);
        case 0x039298ULL: return fde_sub_039298(a0, a1, a2);
        case 0x0392e4ULL: return fde_sub_0392e4(a0, a1, a2);
        case 0x0394a4ULL: return fde_sub_0394a4(a0, a1, a2);
        case 0x039738ULL: return fde_sub_039738(a0, a1, a2);
        case 0x03b034ULL: return fde_sub_03b034(a0, a1, a2);
        case 0x03b060ULL: return fde_sub_03b060(a0, a1, a2);
        case 0x03b12cULL: return fde_sub_03b12c(a0, a1, a2);
        case 0x03b1a4ULL: return fde_sub_03b1a4(a0, a1, a2);
        case 0x03b234ULL: return fde_sub_03b234(a0, a1, a2);
        case 0x03b2f8ULL: return fde_sub_03b2f8(a0, a1, a2);
        case 0x03b46cULL: return fde_sub_03b46c(a0, a1, a2);
        case 0x03b518ULL: return fde_sub_03b518(a0, a1, a2);
        case 0x03b558ULL: return fde_sub_03b558(a0, a1, a2);
        case 0x03c2d0ULL: return fde_sub_03c2d0(a0, a1, a2);
        case 0x03c36cULL: return fde_sub_03c36c(a0, a1, a2);
        case 0x03c44cULL: return fde_sub_03c44c(a0, a1, a2);
        case 0x03c49cULL: return fde_sub_03c49c(a0, a1, a2);
        case 0x03c674ULL: return fde_sub_03c674(a0, a1, a2);
        case 0x03c71cULL: return fde_sub_03c71c(a0, a1, a2);
        case 0x03c840ULL: return fde_sub_03c840(a0, a1, a2);
        case 0x03c940ULL: return fde_sub_03c940(a0, a1, a2);
        case 0x03ca38ULL: return fde_sub_03ca38(a0, a1, a2);
        case 0x03cb4cULL: return fde_sub_03cb4c(a0, a1, a2);
        case 0x03cc6cULL: return fde_sub_03cc6c(a0, a1, a2);
        case 0x03e16cULL: return fde_sub_03e16c(a0, a1, a2);
        case 0x03e1e4ULL: return fde_sub_03e1e4(a0, a1, a2);
        case 0x03e210ULL: return fde_sub_03e210(a0, a1, a2);
        case 0x03e5d0ULL: return fde_sub_03e5d0(a0, a1, a2);
        case 0x03e724ULL: return fde_sub_03e724(a0, a1, a2);
        case 0x03e83cULL: return fde_sub_03e83c(a0, a1, a2);
        case 0x03e8c4ULL: return fde_sub_03e8c4(a0, a1, a2);
        case 0x03ea3cULL: return fde_sub_03ea3c(a0, a1, a2);
        case 0x03ee50ULL: return fde_sub_03ee50(a0, a1, a2);
        case 0x03ef5cULL: return fde_sub_03ef5c(a0, a1, a2);
        case 0x03ef94ULL: return fde_sub_03ef94(a0, a1, a2);
        case 0x03efd0ULL: return fde_sub_03efd0(a0, a1, a2);
        case 0x03f050ULL: return fde_sub_03f050(a0, a1, a2);
        case 0x03f3d4ULL: return fde_sub_03f3d4(a0, a1, a2);
        case 0x03f3d8ULL: return fde_sub_03f3d8(a0, a1, a2);
        case 0x03f404ULL: return fde_sub_03f404(a0, a1, a2);
        case 0x03f49cULL: return fde_sub_03f49c(a0, a1, a2);
        case 0x03f510ULL: return fde_sub_03f510(a0, a1, a2);
        case 0x03f580ULL: return fde_sub_03f580(a0, a1, a2);
        case 0x03f598ULL: return fde_sub_03f598(a0, a1, a2);
        case 0x03f5e8ULL: return fde_sub_03f5e8(a0, a1, a2);
        case 0x03f668ULL: return fde_sub_03f668(a0, a1, a2);
        case 0x03f7c4ULL: return fde_sub_03f7c4(a0, a1, a2);
        case 0x03f838ULL: return fde_sub_03f838(a0, a1, a2);
        case 0x03fa88ULL: return fde_sub_03fa88(a0, a1, a2);
        case 0x03fb14ULL: return fde_sub_03fb14(a0, a1, a2);
        case 0x03fb4cULL: return fde_sub_03fb4c(a0, a1, a2);
        case 0x04145cULL: return fde_sub_04145c(a0, a1, a2);
        case 0x041680ULL: return fde_sub_041680(a0, a1, a2);
        case 0x0416b4ULL: return fde_sub_0416b4(a0, a1, a2);
        case 0x041708ULL: return fde_sub_041708(a0, a1, a2);
        case 0x041790ULL: return fde_sub_041790(a0, a1, a2);
        case 0x0417b8ULL: return fde_sub_0417b8(a0, a1, a2);
        case 0x041850ULL: return fde_sub_041850(a0, a1, a2);
        case 0x041878ULL: return fde_sub_041878(a0, a1, a2);
        case 0x041894ULL: return fde_sub_041894(a0, a1, a2);
        case 0x0418a0ULL: return fde_sub_0418a0(a0, a1, a2);
        case 0x041944ULL: return fde_sub_041944(a0, a1, a2);
        case 0x041a14ULL: return fde_sub_041a14(a0, a1, a2);
        case 0x041b10ULL: return fde_sub_041b10(a0, a1, a2);
        case 0x041c28ULL: return fde_sub_041c28(a0, a1, a2);
        case 0x041d84ULL: return fde_sub_041d84(a0, a1, a2);
        case 0x041da8ULL: return fde_sub_041da8(a0, a1, a2);
        case 0x041dccULL: return fde_sub_041dcc(a0, a1, a2);
        case 0x041e20ULL: return fde_sub_041e20(a0, a1, a2);
        case 0x041e30ULL: return fde_sub_041e30(a0, a1, a2);
        case 0x041e38ULL: return fde_sub_041e38(a0, a1, a2);
        case 0x041e40ULL: return fde_sub_041e40(a0, a1, a2);
        case 0x041ef0ULL: return fde_sub_041ef0(a0, a1, a2);
        case 0x041f54ULL: return fde_sub_041f54(a0, a1, a2);
        case 0x04203cULL: return fde_sub_04203c(a0, a1, a2);
        case 0x0420ccULL: return fde_sub_0420cc(a0, a1, a2);
        case 0x04216cULL: return fde_sub_04216c(a0, a1, a2);
        case 0x0421e8ULL: return fde_sub_0421e8(a0, a1, a2);
        case 0x042210ULL: return fde_sub_042210(a0, a1, a2);
        case 0x042260ULL: return fde_sub_042260(a0, a1, a2);
        case 0x042468ULL: return fde_sub_042468(a0, a1, a2);
        case 0x0424f8ULL: return fde_sub_0424f8(a0, a1, a2);
        case 0x04258cULL: return fde_sub_04258c(a0, a1, a2);
        case 0x0425a4ULL: return fde_sub_0425a4(a0, a1, a2);
        case 0x0425b4ULL: return fde_sub_0425b4(a0, a1, a2);
        case 0x042724ULL: return fde_sub_042724(a0, a1, a2);
        case 0x0427d0ULL: return fde_sub_0427d0(a0, a1, a2);
        case 0x043304ULL: return fde_sub_043304(a0, a1, a2);
        case 0x04330cULL: return fde_sub_04330c(a0, a1, a2);
        case 0x043344ULL: return fde_sub_043344(a0, a1, a2);
        case 0x043354ULL: return fde_sub_043354(a0, a1, a2);
        case 0x043380ULL: return fde_sub_043380(a0, a1, a2);
        case 0x04343cULL: return fde_sub_04343c(a0, a1, a2);
        case 0x0434c0ULL: return fde_sub_0434c0(a0, a1, a2);
        case 0x0435ecULL: return fde_sub_0435ec(a0, a1, a2);
        case 0x04376cULL: return fde_sub_04376c(a0, a1, a2);
        case 0x043848ULL: return fde_sub_043848(a0, a1, a2);
        case 0x043884ULL: return fde_sub_043884(a0, a1, a2);
        case 0x043944ULL: return fde_sub_043944(a0, a1, a2);
        case 0x043980ULL: return fde_sub_043980(a0, a1, a2);
        case 0x0439e0ULL: return fde_sub_0439e0(a0, a1, a2);
        case 0x043b50ULL: return fde_sub_043b50(a0, a1, a2);
        case 0x043e7cULL: return fde_sub_043e7c(a0, a1, a2);
        case 0x0440e8ULL: return fde_sub_0440e8(a0, a1, a2);
        case 0x0443c0ULL: return fde_sub_0443c0(a0, a1, a2);
        case 0x044524ULL: return fde_sub_044524(a0, a1, a2);
        case 0x0445c0ULL: return fde_sub_0445c0(a0, a1, a2);
        case 0x04473cULL: return fde_sub_04473c(a0, a1, a2);
        case 0x044ef8ULL: return fde_sub_044ef8(a0, a1, a2);
        case 0x04599cULL: return fde_sub_04599c(a0, a1, a2);
        case 0x045ee4ULL: return fde_sub_045ee4(a0, a1, a2);
        case 0x046204ULL: return fde_sub_046204(a0, a1, a2);
        case 0x0462ecULL: return fde_sub_0462ec(a0, a1, a2);
        case 0x046740ULL: return fde_sub_046740(a0, a1, a2);
        case 0x0467bcULL: return fde_sub_0467bc(a0, a1, a2);
        case 0x046c24ULL: return fde_sub_046c24(a0, a1, a2);
        case 0x046c2cULL: return fde_sub_046c2c(a0, a1, a2);
        case 0x046c78ULL: return fde_sub_046c78(a0, a1, a2);
        case 0x046d34ULL: return fde_sub_046d34(a0, a1, a2);
        case 0x046d6cULL: return fde_sub_046d6c(a0, a1, a2);
        case 0x046d90ULL: return fde_sub_046d90(a0, a1, a2);
        case 0x046e30ULL: return fde_sub_046e30(a0, a1, a2);
        case 0x046e50ULL: return fde_sub_046e50(a0, a1, a2);
        case 0x046ed8ULL: return fde_sub_046ed8(a0, a1, a2);
        case 0x046f14ULL: return fde_sub_046f14(a0, a1, a2);
        case 0x046f5cULL: return fde_sub_046f5c(a0, a1, a2);
        case 0x046fb0ULL: return fde_sub_046fb0(a0, a1, a2);
        case 0x046ff8ULL: return fde_sub_046ff8(a0, a1, a2);
        case 0x047038ULL: return fde_sub_047038(a0, a1, a2);
        case 0x047080ULL: return fde_sub_047080(a0, a1, a2);
        case 0x047084ULL: return fde_sub_047084(a0, a1, a2);
        case 0x04713cULL: return fde_sub_04713c(a0, a1, a2);
        case 0x047188ULL: return fde_sub_047188(a0, a1, a2);
        case 0x0471f0ULL: return fde_sub_0471f0(a0, a1, a2);
        case 0x047224ULL: return fde_sub_047224(a0, a1, a2);
        case 0x047280ULL: return fde_sub_047280(a0, a1, a2);
        case 0x047350ULL: return fde_sub_047350(a0, a1, a2);
        case 0x047364ULL: return fde_sub_047364(a0, a1, a2);
        case 0x0473d8ULL: return fde_sub_0473d8(a0, a1, a2);
        case 0x047428ULL: return fde_sub_047428(a0, a1, a2);
        case 0x0474b0ULL: return fde_sub_0474b0(a0, a1, a2);
        case 0x047534ULL: return fde_sub_047534(a0, a1, a2);
        case 0x04792cULL: return fde_sub_04792c(a0, a1, a2);
        case 0x047974ULL: return fde_sub_047974(a0, a1, a2);
        case 0x047e0cULL: return fde_sub_047e0c(a0, a1, a2);
        case 0x047ea0ULL: return fde_sub_047ea0(a0, a1, a2);
        case 0x048630ULL: return fde_sub_048630(a0, a1, a2);
        case 0x048788ULL: return fde_sub_048788(a0, a1, a2);
        case 0x048840ULL: return fde_sub_048840(a0, a1, a2);
        case 0x048880ULL: return fde_sub_048880(a0, a1, a2);
        case 0x048a64ULL: return fde_sub_048a64(a0, a1, a2);
        case 0x048ac0ULL: return fde_sub_048ac0(a0, a1, a2);
        case 0x048ae4ULL: return fde_sub_048ae4(a0, a1, a2);
        case 0x048b6cULL: return fde_sub_048b6c(a0, a1, a2);
        case 0x048b74ULL: return fde_sub_048b74(a0, a1, a2);
        case 0x049280ULL: return fde_sub_049280(a0, a1, a2);
        case 0x0493b8ULL: return fde_sub_0493b8(a0, a1, a2);
        case 0x049414ULL: return fde_sub_049414(a0, a1, a2);
        case 0x0494f0ULL: return fde_sub_0494f0(a0, a1, a2);
        case 0x049534ULL: return fde_sub_049534(a0, a1, a2);
        case 0x049588ULL: return fde_sub_049588(a0, a1, a2);
        case 0x049604ULL: return fde_sub_049604(a0, a1, a2);
        case 0x049608ULL: return fde_sub_049608(a0, a1, a2);
        case 0x049660ULL: return fde_sub_049660(a0, a1, a2);
        case 0x0496c8ULL: return fde_sub_0496c8(a0, a1, a2);
        case 0x0496ccULL: return fde_sub_0496cc(a0, a1, a2);
        case 0x0496d0ULL: return fde_sub_0496d0(a0, a1, a2);
        case 0x0496d4ULL: return fde_sub_0496d4(a0, a1, a2);
        case 0x0496ecULL: return fde_sub_0496ec(a0, a1, a2);
        case 0x0496f0ULL: return fde_sub_0496f0(a0, a1, a2);
        case 0x0496f8ULL: return fde_sub_0496f8(a0, a1, a2);
        case 0x0496fcULL: return fde_sub_0496fc(a0, a1, a2);
        case 0x049724ULL: return fde_sub_049724(a0, a1, a2);
        case 0x04972cULL: return fde_sub_04972c(a0, a1, a2);
        case 0x049734ULL: return fde_sub_049734(a0, a1, a2);
        case 0x04973cULL: return fde_sub_04973c(a0, a1, a2);
        case 0x049744ULL: return fde_sub_049744(a0, a1, a2);
        case 0x049750ULL: return fde_sub_049750(a0, a1, a2);
        case 0x049764ULL: return fde_sub_049764(a0, a1, a2);
        case 0x04976cULL: return fde_sub_04976c(a0, a1, a2);
        case 0x049770ULL: return fde_sub_049770(a0, a1, a2);
        case 0x049778ULL: return fde_sub_049778(a0, a1, a2);
        case 0x049784ULL: return fde_sub_049784(a0, a1, a2);
        case 0x04978cULL: return fde_sub_04978c(a0, a1, a2);
        case 0x049790ULL: return fde_sub_049790(a0, a1, a2);
        case 0x049798ULL: return fde_sub_049798(a0, a1, a2);
        case 0x04979cULL: return fde_sub_04979c(a0, a1, a2);
        case 0x0497a0ULL: return fde_sub_0497a0(a0, a1, a2);
        case 0x0497a4ULL: return fde_sub_0497a4(a0, a1, a2);
        case 0x0497a8ULL: return fde_sub_0497a8(a0, a1, a2);
        case 0x0497acULL: return fde_sub_0497ac(a0, a1, a2);
        case 0x0497b0ULL: return fde_sub_0497b0(a0, a1, a2);
        case 0x0497b4ULL: return fde_sub_0497b4(a0, a1, a2);
        case 0x0497b8ULL: return fde_sub_0497b8(a0, a1, a2);
        case 0x0497c0ULL: return fde_sub_0497c0(a0, a1, a2);
        case 0x0497c8ULL: return fde_sub_0497c8(a0, a1, a2);
        case 0x0497ccULL: return fde_sub_0497cc(a0, a1, a2);
        case 0x0497d0ULL: return fde_sub_0497d0(a0, a1, a2);
        case 0x0497e8ULL: return fde_sub_0497e8(a0, a1, a2);
        case 0x0497ecULL: return fde_sub_0497ec(a0, a1, a2);
        case 0x0497f0ULL: return fde_sub_0497f0(a0, a1, a2);
        case 0x0497f8ULL: return fde_sub_0497f8(a0, a1, a2);
        case 0x04980cULL: return fde_sub_04980c(a0, a1, a2);
        case 0x049810ULL: return fde_sub_049810(a0, a1, a2);
        case 0x04982cULL: return fde_sub_04982c(a0, a1, a2);
        case 0x049848ULL: return fde_sub_049848(a0, a1, a2);
        case 0x04984cULL: return fde_sub_04984c(a0, a1, a2);
        case 0x049858ULL: return fde_sub_049858(a0, a1, a2);
        case 0x049878ULL: return fde_sub_049878(a0, a1, a2);
        case 0x04993cULL: return fde_sub_04993c(a0, a1, a2);
        case 0x049940ULL: return fde_sub_049940(a0, a1, a2);
        case 0x04994cULL: return fde_sub_04994c(a0, a1, a2);
        case 0x049cd0ULL: return fde_sub_049cd0(a0, a1, a2);
        case 0x049e50ULL: return fde_sub_049e50(a0, a1, a2);
        case 0x049e84ULL: return fde_sub_049e84(a0, a1, a2);
        case 0x04a004ULL: return fde_sub_04a004(a0, a1, a2);
        case 0x04a0f8ULL: return fde_sub_04a0f8(a0, a1, a2);
        case 0x04a190ULL: return fde_sub_04a190(a0, a1, a2);
        case 0x04a2ccULL: return fde_sub_04a2cc(a0, a1, a2);
        case 0x04a2e0ULL: return fde_sub_04a2e0(a0, a1, a2);
        case 0x04a2f4ULL: return fde_sub_04a2f4(a0, a1, a2);
        case 0x04a308ULL: return fde_sub_04a308(a0, a1, a2);
        case 0x04a330ULL: return fde_sub_04a330(a0, a1, a2);
        case 0x04a728ULL: return fde_sub_04a728(a0, a1, a2);
        case 0x04a78cULL: return fde_sub_04a78c(a0, a1, a2);
        case 0x04a794ULL: return fde_sub_04a794(a0, a1, a2);
        case 0x04a7b8ULL: return fde_sub_04a7b8(a0, a1, a2);
        case 0x04a7c0ULL: return fde_sub_04a7c0(a0, a1, a2);
        case 0x04abb8ULL: return fde_sub_04abb8(a0, a1, a2);
        case 0x04ad90ULL: return fde_sub_04ad90(a0, a1, a2);
        case 0x04afe0ULL: return fde_sub_04afe0(a0, a1, a2);
        case 0x04b7ccULL: return fde_sub_04b7cc(a0, a1, a2);
        case 0x04b98cULL: return fde_sub_04b98c(a0, a1, a2);
        case 0x04b9ccULL: return fde_sub_04b9cc(a0, a1, a2);
        case 0x04bf88ULL: return fde_sub_04bf88(a0, a1, a2);
        case 0x04bfb8ULL: return fde_sub_04bfb8(a0, a1, a2);
        case 0x04c01cULL: return fde_sub_04c01c(a0, a1, a2);
        case 0x04c1ccULL: return fde_sub_04c1cc(a0, a1, a2);
        case 0x04c1dcULL: return fde_sub_04c1dc(a0, a1, a2);
        case 0x04c220ULL: return fde_sub_04c220(a0, a1, a2);
        case 0x04c224ULL: return fde_sub_04c224(a0, a1, a2);
        case 0x04c244ULL: return fde_sub_04c244(a0, a1, a2);
        case 0x04c340ULL: return fde_sub_04c340(a0, a1, a2);
        case 0x04c6ccULL: return fde_sub_04c6cc(a0, a1, a2);
        case 0x04c784ULL: return fde_sub_04c784(a0, a1, a2);
        case 0x04c7bcULL: return fde_sub_04c7bc(a0, a1, a2);
        case 0x04c808ULL: return fde_sub_04c808(a0, a1, a2);
        case 0x04c810ULL: return fde_sub_04c810(a0, a1, a2);
        case 0x04c818ULL: return fde_sub_04c818(a0, a1, a2);
        case 0x04c820ULL: return fde_sub_04c820(a0, a1, a2);
        case 0x04c82cULL: return fde_sub_04c82c(a0, a1, a2);
        case 0x04c834ULL: return fde_sub_04c834(a0, a1, a2);
        case 0x04c92cULL: return fde_sub_04c92c(a0, a1, a2);
        case 0x04c990ULL: return fde_sub_04c990(a0, a1, a2);
        case 0x04cac4ULL: return fde_sub_04cac4(a0, a1, a2);
        case 0x04cadcULL: return fde_sub_04cadc(a0, a1, a2);
        case 0x04caf4ULL: return fde_sub_04caf4(a0, a1, a2);
        case 0x04cb0cULL: return fde_sub_04cb0c(a0, a1, a2);
        case 0x04cbf8ULL: return fde_sub_04cbf8(a0, a1, a2);
        case 0x04cc08ULL: return fde_sub_04cc08(a0, a1, a2);
        case 0x04cc68ULL: return fde_sub_04cc68(a0, a1, a2);
        case 0x04cf54ULL: return fde_sub_04cf54(a0, a1, a2);
        case 0x04d1fcULL: return fde_sub_04d1fc(a0, a1, a2);
        case 0x04d780ULL: return fde_sub_04d780(a0, a1, a2);
        case 0x04d8a4ULL: return fde_sub_04d8a4(a0, a1, a2);
        case 0x04d908ULL: return fde_sub_04d908(a0, a1, a2);
        case 0x04d914ULL: return fde_sub_04d914(a0, a1, a2);
        case 0x04d920ULL: return fde_sub_04d920(a0, a1, a2);
        case 0x04d924ULL: return fde_sub_04d924(a0, a1, a2);
        case 0x04da2cULL: return fde_sub_04da2c(a0, a1, a2);
        case 0x04da64ULL: return fde_sub_04da64(a0, a1, a2);
        case 0x04dae4ULL: return fde_sub_04dae4(a0, a1, a2);
        case 0x04db20ULL: return fde_sub_04db20(a0, a1, a2);
        case 0x04db5cULL: return fde_sub_04db5c(a0, a1, a2);
        case 0x04dbc0ULL: return fde_sub_04dbc0(a0, a1, a2);
        case 0x04dcbcULL: return fde_sub_04dcbc(a0, a1, a2);
        case 0x04dce8ULL: return fde_sub_04dce8(a0, a1, a2);
        case 0x04dcfcULL: return fde_sub_04dcfc(a0, a1, a2);
        case 0x04dd10ULL: return fde_sub_04dd10(a0, a1, a2);
        case 0x04dd64ULL: return fde_sub_04dd64(a0, a1, a2);
        case 0x04de34ULL: return fde_sub_04de34(a0, a1, a2);
        case 0x04dfd0ULL: return fde_sub_04dfd0(a0, a1, a2);
        case 0x04e184ULL: return fde_sub_04e184(a0, a1, a2);
        default: return 0ULL;
    }
}

} // namespace fdk_aac
} // namespace opencut
