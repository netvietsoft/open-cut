// ============================================================================
// File: fdk_aac_fde_shard_1.cpp
// Target 105 / 169: libfdk-aac.so (625,312 bytes)
// EN: Clean-room C++17 AArch64 FDE Shard 1/5 covering FDEs [0..294]
//     (PC range 0x01cd04 .. 0x038004).
// VI: Phân mảnh FDE AArch64 C++17 1/5 bao phủ các FDE [0..294]
//     (Dải địa chỉ PC 0x01cd04 .. 0x038004).
// ============================================================================
#include "fdk_aac_codec_core.h"

namespace opencut {
namespace fdk_aac {

// FDE #0000 | PC: 0x01cd04..0x01cd10 (12 B) | Symbol: _Z13GetAacDecoderi
// EN: AArch64 prologue [mov w0, #1; mov w1, #0xbf40; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #1; mov w1, #0xbf40; b #0x1a748]
uint64_t fde_sub_01cd04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5297E801ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CD04ULL;
}

// FDE #0001 | PC: 0x01cd10..0x01cd34 (36 B) | Symbol: _Z21FreeRam_aacEnc_PsyOutPP7PSY_OUT
// EN: AArch64 prologue [cbz x0, #0x1cd30; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x1cd30; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10]
uint64_t fde_sub_01cd10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0xB4000100ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CD10ULL;
}

// FDE #0002 | PC: 0x01cd34..0x01cd3c (8 B) | Symbol: _Z24GetRequiredMemAacDecoderv
// EN: AArch64 prologue [mov w0, #0xbf40; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0xbf40; ret]
uint64_t fde_sub_01cd34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x5297E800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CD34ULL;
}

// FDE #0003 | PC: 0x01cd3c..0x01cd48 (12 B) | Symbol: _Z30GetAacDecoderStaticChannelInfoi
// EN: AArch64 prologue [mov w0, #1; mov w1, #0x1228; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #1; mov w1, #0x1228; b #0x1a748]
uint64_t fde_sub_01cd3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52824501ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CD3CULL;
}

// FDE #0004 | PC: 0x01cd48..0x01cd50 (8 B) | Symbol: _Z41GetRequiredMemAacDecoderStaticChannelInfov
// EN: AArch64 prologue [mov w0, #0x9140; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x9140; ret]
uint64_t fde_sub_01cd48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52922800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CD48ULL;
}

// FDE #0005 | PC: 0x01cd50..0x01cd58 (8 B) | Symbol: _Z24GetAacDecoderChannelInfoi
// EN: AArch64 prologue [mov w0, #0xe8; b #0x6c88c] | VI: Khởi đầu hàm AArch64 [mov w0, #0xe8; b #0x6c88c]
uint64_t fde_sub_01cd50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14013ECEULL) << 32) | 0x52801D00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CD50ULL;
}

// FDE #0006 | PC: 0x01cd58..0x01cd78 (32 B) | Symbol: _Z25FreeAacDecoderChannelInfoPP22CAacDecoderChannelInfo
// EN: AArch64 prologue [cbz x0, #0x1cd74; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x1cd74; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10]
uint64_t fde_sub_01cd58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0xB40000E0ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CD58ULL;
}

// FDE #0007 | PC: 0x01cd78..0x01cd80 (8 B) | Symbol: _Z35GetRequiredMemAacDecoderChannelInfov
// EN: AArch64 prologue [mov w0, #0x7c0; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x7c0; ret]
uint64_t fde_sub_01cd78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x5280F800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CD78ULL;
}

// FDE #0008 | PC: 0x01cd80..0x01cd88 (8 B) | Symbol: _Z16GetOverlapBufferi
// EN: AArch64 prologue [mov w0, #0x800; b #0x6ad70] | VI: Khởi đầu hàm AArch64 [mov w0, #0x800; b #0x6ad70]
uint64_t fde_sub_01cd80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140137FBULL) << 32) | 0x52810000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CD80ULL;
}

// FDE #0009 | PC: 0x01cd88..0x01cd90 (8 B) | Symbol: _Z27GetRequiredMemOverlapBufferv
// EN: AArch64 prologue [mov w0, #0x10000; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x10000; ret]
uint64_t fde_sub_01cd88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52A00020ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CD88ULL;
}

// FDE #0010 | PC: 0x01cd90..0x01cd9c (12 B) | Symbol: _Z10GetDrcInfoi
// EN: AArch64 prologue [mov w0, #1; mov w1, #0x38; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #1; mov w1, #0x38; b #0x1a748]
uint64_t fde_sub_01cd90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800701ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CD90ULL;
}

// FDE #0011 | PC: 0x01cd9c..0x01cda4 (8 B) | Symbol: _Z21GetRequiredMemDrcInfov
// EN: AArch64 prologue [mov w0, #0x38; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x38; ret]
uint64_t fde_sub_01cd9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800700ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CD9CULL;
}

// FDE #0012 | PC: 0x01cda4..0x01cdac (8 B) | Symbol: _Z18GetWorkBufferCore2i
// EN: AArch64 prologue [mov w0, #0x8000; b #0x6ad94] | VI: Khởi đầu hàm AArch64 [mov w0, #0x8000; b #0x6ad94]
uint64_t fde_sub_01cda4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140137FBULL) << 32) | 0x52900000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CDA4ULL;
}

// FDE #0013 | PC: 0x01cdac..0x01cdcc (32 B) | Symbol: _Z19FreeWorkBufferCore1PP16CWorkBufferCore1
// EN: AArch64 prologue [cbz x0, #0x1cdc8; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x1cdc8; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10]
uint64_t fde_sub_01cdac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0xB40000E0ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CDACULL;
}

// FDE #0014 | PC: 0x01cdcc..0x01cdd4 (8 B) | Symbol: _Z29GetRequiredMemWorkBufferCore2v
// EN: AArch64 prologue [mov w0, #0x8010; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x8010; ret]
uint64_t fde_sub_01cdcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52900200ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CDCCULL;
}

// FDE #0015 | PC: 0x01cdd4..0x01cddc (8 B) | Symbol: _Z24GetRam_SbrDecWorkBuffer2i
// EN: AArch64 prologue [mov w0, #0x2000; b #0x6ad94] | VI: Khởi đầu hàm AArch64 [mov w0, #0x2000; b #0x6ad94]
uint64_t fde_sub_01cdd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140137EFULL) << 32) | 0x52840000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CDD4ULL;
}

// FDE #0016 | PC: 0x01cddc..0x01cde0 (4 B) | Symbol: _Z35GetRequiredMemRam_SbrDecWorkBuffer2v
// EN: AArch64 prologue [b #0x6c884] | VI: Khởi đầu hàm AArch64 [b #0x6c884]
uint64_t fde_sub_01cddc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000140ULL) << 32) | 0x14013EAAULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CDDCULL;
}

// FDE #0017 | PC: 0x01cde0..0x01ce0c (44 B) | Symbol: _Z18aacDecoder_drcInitP8CDrcInfo
// EN: AArch64 prologue [cbz x0, #0x1ce08; mov x9, #0x32; mov w8, #0xff0000; movk x9, #0xff, lsl #32] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x1ce08; mov x9, #0x32; mov w8, #0xff0000; movk x9, #0xff, lsl #32]
uint64_t fde_sub_01cde0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD2800649ULL) << 32) | 0xB4000140ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CDE0ULL;
}

// FDE #0018 | PC: 0x01ce0c..0x01ce34 (40 B) | Symbol: _Z29aacDecoder_drcInitChannelDataP15CDrcChannelData
// EN: AArch64 prologue [cbz x0, #0x1ce30; adrp x8, #0x6c000; ldr d0, [x8, #0x8b0]; mov w9, #0xff] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x1ce30; adrp x8, #0x6c000; ldr d0, [x8, #0x8b0]; mov w9, #0xff]
uint64_t fde_sub_01ce0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000288ULL) << 32) | 0xB4000120ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CE0CULL;
}

// FDE #0019 | PC: 0x01ce34..0x01cfb8 (388 B) | Symbol: _Z22aacDecoder_drcSetParamP8CDrcInfo16AACDEC_DRC_PARAMi
// EN: AArch64 prologue [cmp w1, #6; b.hi #0x1cf20; adrp x9, #0x6c000; mov w8, w1] | VI: Khởi đầu hàm AArch64 [cmp w1, #6; b.hi #0x1cf20; adrp x9, #0x6c000; mov w8, w1]
uint64_t fde_sub_01ce34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000748ULL) << 32) | 0x7100183FULL;
    const uint64_t kPcRange = 0x0184ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CE34ULL;
}

// FDE #0020 | PC: 0x01cfb8..0x01d1b8 (512 B) | Symbol: _Z25aacDecoder_drcMarkPayloadP8CDrcInfoP13FDK_BITSTREAM23AACDEC_DRC_PAYLOAD_TYPE
// EN: AArch64 prologue [mov x3, x30; bl #0x6a250; mov x30, x3; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x6a250; mov x30, x3; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_01cfb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940134A5ULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x0200ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01CFB8ULL;
}

// FDE #0021 | PC: 0x01d1b8..0x01d1d8 (32 B) | Symbol: sub_01d1b8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_01d1b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01D1B8ULL;
}

// FDE #0022 | PC: 0x01d1d8..0x01d254 (124 B) | Symbol: sub_01d1d8
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_01d1d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01D1D8ULL;
}

// FDE #0023 | PC: 0x01d254..0x01d294 (64 B) | Symbol: sub_01d254
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0x30]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0x30]]
uint64_t fde_sub_01d254(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01D254ULL;
}

// FDE #0024 | PC: 0x01d294..0x01d790 (1276 B) | Symbol: _Z19aacDecoder_drcApplyP8CDrcInfoPvP22CAacDecoderChannelInfoP15CDrcChannelDataPiiii
// EN: AArch64 prologue [sub sp, sp, #0x140; stp x28, x27, [sp, #0xe0]; stp x26, x25, [sp, #0xf0]; stp x24, x23, [sp, #0x100]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x140; stp x28, x27, [sp, #0xe0]; stp x26, x25, [sp, #0xf0]; stp x24, x23, [sp, #0x100]]
uint64_t fde_sub_01d294(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90E6FFCULL) << 32) | 0xD10503FFULL;
    const uint64_t kPcRange = 0x04FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01D294ULL;
}

// FDE #0025 | PC: 0x01d790..0x01d7a8 (24 B) | Symbol: _Z20aacDecoder_drcPrologP8CDrcInfoP13FDK_BITSTREAMPP28CAacDecoderStaticChannelInfohPhi
// EN: AArch64 prologue [cbz x0, #0x1d7a0; ldrb w8, [x0, #0x15]; cbz w8, #0x1d7a4; b #0x6a02c] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x1d7a0; ldrb w8, [x0, #0x15]; cbz w8, #0x1d7a4; b #0x6a02c]
uint64_t fde_sub_01d790(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39405408ULL) << 32) | 0xB4000080ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01D790ULL;
}

// FDE #0026 | PC: 0x01d7a8..0x01df00 (1880 B) | Symbol: sub_01d7a8
// EN: AArch64 prologue [sub sp, sp, #0x1b0; stp x28, x27, [sp, #0x150]; stp x26, x25, [sp, #0x160]; stp x24, x23, [sp, #0x170]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1b0; stp x28, x27, [sp, #0x150]; stp x26, x25, [sp, #0x160]; stp x24, x23, [sp, #0x170]]
uint64_t fde_sub_01d7a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9156FFCULL) << 32) | 0xD106C3FFULL;
    const uint64_t kPcRange = 0x0758ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01D7A8ULL;
}

// FDE #0027 | PC: 0x01df00..0x01df10 (16 B) | Symbol: sub_01df00
// EN: AArch64 prologue [tbnz w1, #0x1f, #0x1df08; b #0x1df10; neg w1, w1; b #0x1df60] | VI: Khởi đầu hàm AArch64 [tbnz w1, #0x1f, #0x1df08; b #0x1df10; neg w1, w1; b #0x1df60]
uint64_t fde_sub_01df00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000003ULL) << 32) | 0x37F80041ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01DF00ULL;
}

// FDE #0028 | PC: 0x01df10..0x01df60 (80 B) | Symbol: sub_01df10
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #4]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #4]]
uint64_t fde_sub_01df10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01DF10ULL;
}

// FDE #0029 | PC: 0x01df60..0x01dfbc (92 B) | Symbol: sub_01df60
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #4]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #4]]
uint64_t fde_sub_01df60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01DF60ULL;
}

// FDE #0030 | PC: 0x01dfbc..0x01dfd4 (24 B) | Symbol: _Z20aacDecoder_drcEpilogP8CDrcInfoP13FDK_BITSTREAMPP28CAacDecoderStaticChannelInfohPhi
// EN: AArch64 prologue [cbz x0, #0x1dfcc; ldrb w8, [x0, #0x15]; cbz w8, #0x1dfd0; b #0x1d7a8] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x1dfcc; ldrb w8, [x0, #0x15]; cbz w8, #0x1dfd0; b #0x1d7a8]
uint64_t fde_sub_01dfbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39405408ULL) << 32) | 0xB4000080ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01DFBCULL;
}

// FDE #0031 | PC: 0x01dfd4..0x01e004 (48 B) | Symbol: _Z21aacDecoder_drcGetInfoP8CDrcInfoPaS1_
// EN: AArch64 prologue [cbz x0, #0x1e000; cbz x1, #0x1dfe4; ldrb w8, [x0, #0x24]; strb w8, [x1]] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x1e000; cbz x1, #0x1dfe4; ldrb w8, [x0, #0x24]; strb w8, [x1]]
uint64_t fde_sub_01dfd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000061ULL) << 32) | 0xB4000160ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01DFD4ULL;
}

// FDE #0032 | PC: 0x01e004..0x01e110 (268 B) | Symbol: _Z9CHcr_ReadP13FDK_BITSTREAMP22CAacDecoderChannelInfo
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_01e004(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01E004ULL;
}

// FDE #0033 | PC: 0x01e110..0x01e118 (8 B) | Symbol: _Z10getHcrTypeP10CErHcrInfo
// EN: AArch64 prologue [ldr w0, [x0, #0x3490]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0x3490]; ret]
uint64_t fde_sub_01e110(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9749000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01E110ULL;
}

// FDE #0034 | PC: 0x01e118..0x01e188 (112 B) | Symbol: _Z10HcrInitRomP10CErHcrInfo
// EN: AArch64 prologue [adrp x8, #0x9a000; ldr x8, [x8, #0x7a0]; fmov d0, x8; adrp x8, #0x9a000] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9a000; ldr x8, [x8, #0x7a0]; fmov d0, x8; adrp x8, #0x9a000]
uint64_t fde_sub_01e118(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF943D108ULL) << 32) | 0x900003E8ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01E118ULL;
}

// FDE #0035 | PC: 0x01e188..0x01e460 (728 B) | Symbol: _Z7HcrInitP10CErHcrInfoP22CAacDecoderChannelInfoPK16SamplingRateInfoP13FDK_BITSTREAM
// EN: AArch64 prologue [mov x4, x30; bl #0x69f8c; mov x30, x4; stp x29, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [mov x4, x30; bl #0x69f8c; mov x30, x4; stp x29, x30, [sp, #0x90]]
uint64_t fde_sub_01e188(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94012F80ULL) << 32) | 0xAA1E03E4ULL;
    const uint64_t kPcRange = 0x02D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01E188ULL;
}

// FDE #0036 | PC: 0x01e460..0x01e480 (32 B) | Symbol: sub_01e460
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_01e460(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01E460ULL;
}

// FDE #0037 | PC: 0x01e480..0x01e4b8 (56 B) | Symbol: sub_01e480
// EN: AArch64 prologue [and w8, w0, #0xff; cmp w8, #0x1f; ccmp w8, #0xc, #4, ls; b.ne #0x1e49c] | VI: Khởi đầu hàm AArch64 [and w8, w0, #0xff; cmp w8, #0x1f; ccmp w8, #0xc, #4, ls; b.ne #0x1e49c]
uint64_t fde_sub_01e480(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x71007D1FULL) << 32) | 0x12001C08ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01E480ULL;
}

// FDE #0038 | PC: 0x01e4b8..0x01f078 (3008 B) | Symbol: _Z10HcrDecoderP10CErHcrInfoP22CAacDecoderChannelInfoPK16SamplingRateInfoP13FDK_BITSTREAM
// EN: AArch64 prologue [mov x4, x30; bl #0x6a86c; mov x30, x4; stp x29, x30, [sp, #0x110]] | VI: Khởi đầu hàm AArch64 [mov x4, x30; bl #0x6a86c; mov x30, x4; stp x29, x30, [sp, #0x110]]
uint64_t fde_sub_01e4b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940130ECULL) << 32) | 0xAA1E03E4ULL;
    const uint64_t kPcRange = 0x0BC0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01E4B8ULL;
}

// FDE #0039 | PC: 0x01f078..0x01f0f4 (124 B) | Symbol: sub_01f078
// EN: AArch64 prologue [mov x6, x30; bl #0x6a250; mov x30, x6; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x6, x30; bl #0x6a250; mov x30, x6; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_01f078(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94012C75ULL) << 32) | 0xAA1E03E6ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01F078ULL;
}

// FDE #0040 | PC: 0x01f0f4..0x01f134 (64 B) | Symbol: sub_01f0f4
// EN: AArch64 prologue [sxtb w8, w0; tbnz w8, #0x1f, #0x1f100; b #0x6a02c; adrp x8, #0x72000] | VI: Khởi đầu hàm AArch64 [sxtb w8, w0; tbnz w8, #0x1f, #0x1f100; b #0x6a02c; adrp x8, #0x72000]
uint64_t fde_sub_01f0f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x37F80048ULL) << 32) | 0x13001C08ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01F0F4ULL;
}

// FDE #0041 | PC: 0x01f134..0x01f210 (220 B) | Symbol: sub_01f134
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; mov x8, x30; bl #0x69fa8; mov x30, x8] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; mov x8, x30; bl #0x69fa8; mov x30, x8]
uint64_t fde_sub_01f134(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E8ULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01F134ULL;
}

// FDE #0042 | PC: 0x01f210..0x01f2ac (156 B) | Symbol: sub_01f210
// EN: AArch64 prologue [mov x5, x30; bl #0x6aba8; mov x30, x5; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x5, x30; bl #0x6aba8; mov x30, x5; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_01f210(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94012E65ULL) << 32) | 0xAA1E03E5ULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01F210ULL;
}

// FDE #0043 | PC: 0x01f2ac..0x01f334 (136 B) | Symbol: sub_01f2ac
// EN: AArch64 prologue [cbz w0, #0x1f330; adrp x10, #0x9a000; adrp x11, #0x9a000; ldr x10, [x10, #0x7f0]] | VI: Khởi đầu hàm AArch64 [cbz w0, #0x1f330; adrp x10, #0x9a000; adrp x11, #0x9a000; ldr x10, [x10, #0x7f0]]
uint64_t fde_sub_01f2ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00003CAULL) << 32) | 0x34000420ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01F2ACULL;
}

// FDE #0044 | PC: 0x01f334..0x01f354 (32 B) | Symbol: _Z21CarryBitToBranchValuehjPjS_
// EN: AArch64 prologue [lsr w8, w1, #0xc; tst w0, #0xff; csel w8, w8, w1, eq; and w9, w8, #0xfff] | VI: Khởi đầu hàm AArch64 [lsr w8, w1, #0xc; tst w0, #0xff; csel w8, w8, w1, eq; and w9, w8, #0xfff]
uint64_t fde_sub_01f334(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72001C1FULL) << 32) | 0x530C7C28ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01F334ULL;
}

// FDE #0045 | PC: 0x01f354..0x01f380 (44 B) | Symbol: _Z21HcrMuteErroneousLinesP10CErHcrInfo
// EN: AArch64 prologue [ldr x8, [x0, #8]; mov x9, xzr; cmp x9, #1, lsl #12; b.eq #0x1f37c] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; mov x9, xzr; cmp x9, #1, lsl #12; b.eq #0x1f37c]
uint64_t fde_sub_01f354(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E9ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01F354ULL;
}

// FDE #0046 | PC: 0x01f380..0x01f390 (16 B) | Symbol: _Z10setHcrTypeP10CErHcrInfo14MP4_ELEMENT_ID
// EN: AArch64 prologue [cmp w1, #1; b.hi #0x1f38c; str w1, [x0, #0x3490]; ret] | VI: Khởi đầu hàm AArch64 [cmp w1, #1; b.hi #0x1f38c; str w1, [x0, #0x3490]; ret]
uint64_t fde_sub_01f380(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000048ULL) << 32) | 0x7100043FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01F380ULL;
}

// FDE #0047 | PC: 0x01f390..0x01f39c (12 B) | Symbol: _Z19ToggleReadDirectionh
// EN: AArch64 prologue [tst w0, #0xff; cset w0, eq; ret] | VI: Khởi đầu hàm AArch64 [tst w0, #0xff; cset w0, eq; ret]
uint64_t fde_sub_01f390(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1A9F17E0ULL) << 32) | 0x72001C1FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01F390ULL;
}

// FDE #0048 | PC: 0x01f39c..0x01f438 (156 B) | Symbol: _Z23HcrGetABitFromBitstreamP13FDK_BITSTREAMPtS1_h
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_01f39c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01F39CULL;
}

// FDE #0049 | PC: 0x01f438..0x01f970 (1336 B) | Symbol: _Z13DecodeNonPCWsP13FDK_BITSTREAMP10CErHcrInfo
// EN: AArch64 prologue [mov x2, x30; bl #0x6a5a4; mov x30, x2; stp x29, x30, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x6a5a4; mov x30, x2; stp x29, x30, [sp, #0xb0]]
uint64_t fde_sub_01f438(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94012C5AULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0538ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01F438ULL;
}

// FDE #0050 | PC: 0x01f970..0x01fad4 (356 B) | Symbol: _Z19Hcr_State_BODY_ONLYP13FDK_BITSTREAMPv
// EN: AArch64 prologue [mov x2, x30; bl #0x69f8c; mov x30, x2; stp x29, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x69f8c; mov x30, x2; stp x29, x30, [sp, #0x90]]
uint64_t fde_sub_01f970(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94012986ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0164ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01F970ULL;
}

// FDE #0051 | PC: 0x01fad4..0x01fc84 (432 B) | Symbol: _Z25Hcr_State_BODY_SIGN__BODYP13FDK_BITSTREAMPv
// EN: AArch64 prologue [mov x2, x30; bl #0x6ab14; mov x30, x2; stp x29, x30, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x6ab14; mov x30, x2; stp x29, x30, [sp, #0xa0]]
uint64_t fde_sub_01fad4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94012C0FULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x01B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01FAD4ULL;
}

// FDE #0052 | PC: 0x01fc84..0x01fdf4 (368 B) | Symbol: _Z25Hcr_State_BODY_SIGN__SIGNP13FDK_BITSTREAMPv
// EN: AArch64 prologue [mov x2, x30; bl #0x6a160; mov x30, x2; stp x29, x30, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x6a160; mov x30, x2; stp x29, x30, [sp, #0x80]]
uint64_t fde_sub_01fc84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94012936ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01FC84ULL;
}

// FDE #0053 | PC: 0x01fdf4..0x01ffa0 (428 B) | Symbol: _Z29Hcr_State_BODY_SIGN_ESC__BODYP13FDK_BITSTREAMPv
// EN: AArch64 prologue [mov x2, x30; bl #0x69f8c; mov x30, x2; stp x29, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x69f8c; mov x30, x2; stp x29, x30, [sp, #0x90]]
uint64_t fde_sub_01fdf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94012865ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x01ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01FDF4ULL;
}

// FDE #0054 | PC: 0x01ffa0..0x0201bc (540 B) | Symbol: _Z29Hcr_State_BODY_SIGN_ESC__SIGNP13FDK_BITSTREAMPv
// EN: AArch64 prologue [mov x2, x30; bl #0x69f8c; mov x30, x2; stp x29, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x69f8c; mov x30, x2; stp x29, x30, [sp, #0x90]]
uint64_t fde_sub_01ffa0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940127FAULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x021CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x01FFA0ULL;
}

// FDE #0055 | PC: 0x0201bc..0x0202e0 (292 B) | Symbol: _Z35Hcr_State_BODY_SIGN_ESC__ESC_PREFIXP13FDK_BITSTREAMPv
// EN: AArch64 prologue [mov x2, x30; bl #0x69f4c; mov x30, x2; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x69f4c; mov x30, x2; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_0201bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94012763ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0124ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0201BCULL;
}

// FDE #0056 | PC: 0x0202e0..0x0204b8 (472 B) | Symbol: _Z33Hcr_State_BODY_SIGN_ESC__ESC_WORDP13FDK_BITSTREAMPv
// EN: AArch64 prologue [mov x2, x30; bl #0x6a160; mov x30, x2; stp x29, x30, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x6a160; mov x30, x2; stp x29, x30, [sp, #0x80]]
uint64_t fde_sub_0202e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9401279FULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x01D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0202E0ULL;
}

// FDE #0057 | PC: 0x0204b8..0x0204f4 (60 B) | Symbol: _Z14CPns_ResetDataP8CPnsDataP20CPnsInterChannelData
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1]
uint64_t fde_sub_0204b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0204B8ULL;
}

// FDE #0058 | PC: 0x0204f4..0x020500 (12 B) | Symbol: _Z12CPns_InitPnsP8CPnsDataP20CPnsInterChannelDataPiS3_
// EN: AArch64 prologue [str x1, [x0]; stp x2, x3, [x0, #0x90]; ret] | VI: Khởi đầu hàm AArch64 [str x1, [x0]; stp x2, x3, [x0, #0x90]; ret]
uint64_t fde_sub_0204f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9090C02ULL) << 32) | 0xF9000001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0204F4ULL;
}

// FDE #0059 | PC: 0x020500..0x020514 (20 B) | Symbol: _Z14CPns_IsPnsUsedPK8CPnsDataii
// EN: AArch64 prologue [add w8, w2, w1, lsl #4; add x8, x0, x8; ldrb w8, [x8, #8]; and w0, w8, #1] | VI: Khởi đầu hàm AArch64 [add w8, w2, w1, lsl #4; add x8, x0, x8; ldrb w8, [x8, #8]; and w0, w8, #1]
uint64_t fde_sub_020500(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8B080008ULL) << 32) | 0x0B011048ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020500ULL;
}

// FDE #0060 | PC: 0x020514..0x020530 (28 B) | Symbol: _Z19CPns_SetCorrelationP8CPnsDataiii
// EN: AArch64 prologue [ldr x8, [x0]; cmp w3, #0; mov w10, #3; add w9, w2, w1, lsl #4] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; cmp w3, #0; mov w10, #3; add w9, w2, w1, lsl #4]
uint64_t fde_sub_020514(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100007FULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020514ULL;
}

// FDE #0061 | PC: 0x020530..0x0205b8 (136 B) | Symbol: _Z9CPns_ReadP8CPnsDataP13FDK_BITSTREAMPK19CodeBookDescriptionPshii
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_020530(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020530ULL;
}

// FDE #0062 | PC: 0x0205b8..0x020604 (76 B) | Symbol: sub_0205b8
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0205b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0205B8ULL;
}

// FDE #0063 | PC: 0x020604..0x0208c8 (708 B) | Symbol: _Z10CPns_ApplyPK8CPnsDataPK8CIcsInfoPiPKsS7_PK16SamplingRateInfoii
// EN: AArch64 prologue [mov x8, x30; bl #0x6a8c0; mov x30, x8; stp x29, x30, [sp, #0xd0]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x6a8c0; mov x30, x8; stp x29, x30, [sp, #0xd0]]
uint64_t fde_sub_020604(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940128AEULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x02C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020604ULL;
}

// FDE #0064 | PC: 0x0208c8..0x0208f0 (40 B) | Symbol: _Z10CTns_ResetP8CTnsData
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w1, #0x258] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w1, #0x258]
uint64_t fde_sub_0208c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0208C8ULL;
}

// FDE #0065 | PC: 0x0208f0..0x020914 (36 B) | Symbol: _Z24CTns_ReadDataPresentFlagP13FDK_BITSTREAMP8CTnsData
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1]
uint64_t fde_sub_0208f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0208F0ULL;
}

// FDE #0066 | PC: 0x020914..0x020b48 (564 B) | Symbol: _Z9CTns_ReadP13FDK_BITSTREAMP8CTnsDataPK8CIcsInfoj
// EN: AArch64 prologue [mov x3, x30; bl #0x69f8c; mov x30, x3; stp x29, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x69f8c; mov x30, x3; stp x29, x30, [sp, #0x90]]
uint64_t fde_sub_020914(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9401259DULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x0234ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020914ULL;
}

// FDE #0067 | PC: 0x020b48..0x0211dc (1684 B) | Symbol: _Z10CTns_ApplyP8CTnsDataPK8CIcsInfoPiPK16SamplingRateInfoi
// EN: AArch64 prologue [sub sp, sp, #0x1d0; stp x28, x27, [sp, #0x170]; stp x26, x25, [sp, #0x180]; stp x24, x23, [sp, #0x190]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1d0; stp x28, x27, [sp, #0x170]; stp x26, x25, [sp, #0x180]; stp x24, x23, [sp, #0x190]]
uint64_t fde_sub_020b48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9176FFCULL) << 32) | 0xD10743FFULL;
    const uint64_t kPcRange = 0x0694ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x020B48ULL;
}

// FDE #0068 | PC: 0x0211dc..0x0212f8 (284 B) | Symbol: _Z23CAacDecoder_SyncQmfModeP20AAC_DECODER_INSTANCE
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w9, [x0, #0x3ee4]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w9, [x0, #0x3ee4]]
uint64_t fde_sub_0211dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0211DCULL;
}

// FDE #0069 | PC: 0x0212f8..0x0212fc (4 B) | Symbol: _Z37FDKsbrEnc_deleteSbrNoiseFloorEstimateP24SBR_NOISE_FLOOR_ESTIMATE
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_0212f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x37F80122ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0212F8ULL;
}

// FDE #0070 | PC: 0x0212fc..0x021328 (44 B) | Symbol: _Z23CAacDecoder_AncDataInitP8CAncDataPhi
// EN: AArch64 prologue [tbnz w2, #0x1f, #0x21320; stp x29, x30, [sp, #-0x10]!; mov x29, sp; str x1, [x0]] | VI: Khởi đầu hàm AArch64 [tbnz w2, #0x1f, #0x21320; stp x29, x30, [sp, #-0x10]!; mov x29, sp; str x1, [x0]]
uint64_t fde_sub_0212fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0x37F80122ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0212FCULL;
}

// FDE #0071 | PC: 0x021328..0x02134c (36 B) | Symbol: sub_021328
// EN: AArch64 prologue [mov x8, xzr; add x9, x0, #0xc; cmp x8, #0x20; b.eq #0x21344] | VI: Khởi đầu hàm AArch64 [mov x8, xzr; add x9, x0, #0xc; cmp x8, #0x20; b.eq #0x21344]
uint64_t fde_sub_021328(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91003009ULL) << 32) | 0xAA1F03E8ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x021328ULL;
}

// FDE #0072 | PC: 0x02134c..0x02138c (64 B) | Symbol: _Z22CAacDecoder_AncDataGetP8CAncDataiPPhPi
// EN: AArch64 prologue [cmp w1, #7; str xzr, [x2]; str wzr, [x3]; b.hi #0x21388] | VI: Khởi đầu hàm AArch64 [cmp w1, #7; str xzr, [x2]; str wzr, [x3]; b.hi #0x21388]
uint64_t fde_sub_02134c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900005FULL) << 32) | 0x71001C3FULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02134CULL;
}

// FDE #0073 | PC: 0x02138c..0x021484 (248 B) | Symbol: _Z16CAacDecoder_Open14TRANSPORT_TYPE
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_02138c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02138CULL;
}

// FDE #0074 | PC: 0x021484..0x02153c (184 B) | Symbol: _Z17CAacDecoder_CloseP20AAC_DECODER_INSTANCE
// EN: AArch64 prologue [cbz x0, #0x21538; stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x21538; stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]]
uint64_t fde_sub_021484(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD57F6ULL) << 32) | 0xB40005A0ULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x021484ULL;
}

// FDE #0075 | PC: 0x02153c..0x021b18 (1500 B) | Symbol: _Z16CAacDecoder_InitP20AAC_DECODER_INSTANCEPK21CSAudioSpecificConfig
// EN: AArch64 prologue [sub sp, sp, #0x80; str d8, [sp, #0x10]; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str d8, [sp, #0x10]; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]]
uint64_t fde_sub_02153c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD000BE8ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x05DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02153CULL;
}

// FDE #0076 | PC: 0x021b18..0x0228b4 (3484 B) | Symbol: _Z23CAacDecoder_DecodeFrameP20AAC_DECODER_INSTANCEjPsii
// EN: AArch64 prologue [str d8, [sp, #-0x70]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str d8, [sp, #-0x70]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_021b18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9016FFCULL) << 32) | 0xFC190FE8ULL;
    const uint64_t kPcRange = 0x0D9CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x021B18ULL;
}

// FDE #0077 | PC: 0x0228b4..0x022910 (92 B) | Symbol: sub_0228b4
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x6c7c4] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x6c7c4]
uint64_t fde_sub_0228b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0228B4ULL;
}

// FDE #0078 | PC: 0x022910..0x0229e0 (208 B) | Symbol: sub_022910
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_022910(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022910ULL;
}

// FDE #0079 | PC: 0x0229e0..0x022ce8 (776 B) | Symbol: sub_0229e0
// EN: AArch64 prologue [mov x6, x30; bl #0x6bbd8; mov x30, x6; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x6, x30; bl #0x6bbd8; mov x30, x6; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_0229e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9401247DULL) << 32) | 0xAA1E03E6ULL;
    const uint64_t kPcRange = 0x0308ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0229E0ULL;
}

// FDE #0080 | PC: 0x022ce8..0x022cec (4 B) | Symbol: _Z25CAacDecoder_GetStreamInfoP20AAC_DECODER_INSTANCE
// EN: AArch64 prologue [b #0x6b68c] | VI: Khởi đầu hàm AArch64 [b #0x6b68c]
uint64_t fde_sub_022ce8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB900003FULL) << 32) | 0x14012269ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022CE8ULL;
}

// FDE #0081 | PC: 0x022cec..0x022d20 (52 B) | Symbol: aacDecoder_GetFreeBytes
// EN: AArch64 prologue [str wzr, [x1]; cbz x0, #0x22d18; mov x8, x0; ldr x8, [x8, #0x18]] | VI: Khởi đầu hàm AArch64 [str wzr, [x1]; cbz x0, #0x22d18; mov x8, x0; ldr x8, [x8, #0x18]]
uint64_t fde_sub_022cec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000140ULL) << 32) | 0xB900003FULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022CECULL;
}

// FDE #0082 | PC: 0x022d20..0x022db8 (152 B) | Symbol: aacDecoder_ConfigRaw
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_022d20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022D20ULL;
}

// FDE #0083 | PC: 0x022db8..0x022dc4 (12 B) | Symbol: aacDecoder_AncDataInit
// EN: AArch64 prologue [mov w8, #0x3ef0; add x0, x0, x8; b #0x1ab48] | VI: Khởi đầu hàm AArch64 [mov w8, #0x3ef0; add x0, x0, x8; b #0x1ab48]
uint64_t fde_sub_022db8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8B080000ULL) << 32) | 0x5287DE08ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022DB8ULL;
}

// FDE #0084 | PC: 0x022dc4..0x022de4 (32 B) | Symbol: aacDecoder_AncDataGet
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w8, #0x3ef0; add x0, x0, x8] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w8, #0x3ef0; add x0, x0, x8]
uint64_t fde_sub_022dc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022DC4ULL;
}

// FDE #0085 | PC: 0x022de4..0x023000 (540 B) | Symbol: aacDecoder_SetParam
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0]
uint64_t fde_sub_022de4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x021CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x022DE4ULL;
}

// FDE #0086 | PC: 0x023000..0x023138 (312 B) | Symbol: sub_023000
// EN: AArch64 prologue [mov x2, x30; bl #0x6aba8; mov x30, x2; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x6aba8; mov x30, x2; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_023000(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94011EE9ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0138ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x023000ULL;
}

// FDE #0087 | PC: 0x023138..0x02326c (308 B) | Symbol: aacDecoder_Open
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_023138(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0134ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x023138ULL;
}

// FDE #0088 | PC: 0x02326c..0x0232e4 (120 B) | Symbol: sub_02326c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_02326c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02326CULL;
}

// FDE #0089 | PC: 0x0232e4..0x023350 (108 B) | Symbol: aacDecoder_Close
// EN: AArch64 prologue [cbz x0, #0x2334c; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x2334c; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10]
uint64_t fde_sub_0232e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0xB4000340ULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0232E4ULL;
}

// FDE #0090 | PC: 0x023350..0x0233b4 (100 B) | Symbol: aacDecoder_Fill
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_023350(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x023350ULL;
}

// FDE #0091 | PC: 0x0233b4..0x023900 (1356 B) | Symbol: aacDecoder_DecodeFrame
// EN: AArch64 prologue [mov x4, x30; bl #0x6ab14; mov x30, x4; stp x29, x30, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [mov x4, x30; bl #0x6ab14; mov x30, x4; stp x29, x30, [sp, #0xa0]]
uint64_t fde_sub_0233b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94011DD7ULL) << 32) | 0xAA1E03E4ULL;
    const uint64_t kPcRange = 0x054CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0233B4ULL;
}

// FDE #0092 | PC: 0x023900..0x023914 (20 B) | Symbol: sub_023900
// EN: AArch64 prologue [cbz x0, #0x23910; mov w1, #5; mov w2, wzr; b #0x1a838] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x23910; mov w1, #5; mov w2, wzr; b #0x1a838]
uint64_t fde_sub_023900(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x528000A1ULL) << 32) | 0xB4000080ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x023900ULL;
}

// FDE #0093 | PC: 0x023914..0x0239b0 (156 B) | Symbol: aacDecoder_GetLibInfo
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x23964] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x23964]
uint64_t fde_sub_023914(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x023914ULL;
}

// FDE #0094 | PC: 0x0239b0..0x023a58 (168 B) | Symbol: _Z16CBlock_GetEscapeP13FDK_BITSTREAMi
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0239b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0239B0ULL;
}

// FDE #0095 | PC: 0x023a58..0x023b70 (280 B) | Symbol: _Z26CBlock_ReadScaleFactorDataP22CAacDecoderChannelInfoP13FDK_BITSTREAMj
// EN: AArch64 prologue [mov x3, x30; bl #0x6a084; mov x30, x3; stp x29, x30, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x6a084; mov x30, x3; stp x29, x30, [sp, #0x70]]
uint64_t fde_sub_023a58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9401198AULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x0118ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x023A58ULL;
}

// FDE #0096 | PC: 0x023b70..0x023c9c (300 B) | Symbol: _Z24CBlock_ScaleSpectralDataP22CAacDecoderChannelInfoP16SamplingRateInfo
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_023b70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x023B70ULL;
}

// FDE #0097 | PC: 0x023c9c..0x023e9c (512 B) | Symbol: _Z22CBlock_ReadSectionDataP13FDK_BITSTREAMP22CAacDecoderChannelInfoPK16SamplingRateInfoj
// EN: AArch64 prologue [mov x4, x30; bl #0x6a160; mov x30, x4; stp x29, x30, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [mov x4, x30; bl #0x6a160; mov x30, x4; stp x29, x30, [sp, #0x80]]
uint64_t fde_sub_023c9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94011930ULL) << 32) | 0xAA1E03E4ULL;
    const uint64_t kPcRange = 0x0200ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x023C9CULL;
}

// FDE #0098 | PC: 0x023e9c..0x024134 (664 B) | Symbol: _Z34CBlock_InverseQuantizeSpectralDataP22CAacDecoderChannelInfoP16SamplingRateInfo
// EN: AArch64 prologue [mov x2, x30; bl #0x6a5a4; mov x30, x2; stp x29, x30, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x6a5a4; mov x30, x2; stp x29, x30, [sp, #0xb0]]
uint64_t fde_sub_023e9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940119C1ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0298ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x023E9CULL;
}

// FDE #0099 | PC: 0x024134..0x024478 (836 B) | Symbol: _Z23CBlock_ReadSpectralDataP13FDK_BITSTREAMP22CAacDecoderChannelInfoPK16SamplingRateInfoj
// EN: AArch64 prologue [sub sp, sp, #0x100; stp x28, x27, [sp, #0xa0]; stp x26, x25, [sp, #0xb0]; stp x24, x23, [sp, #0xc0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x100; stp x28, x27, [sp, #0xa0]; stp x26, x25, [sp, #0xb0]; stp x24, x23, [sp, #0xc0]]
uint64_t fde_sub_024134(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90A6FFCULL) << 32) | 0xD10403FFULL;
    const uint64_t kPcRange = 0x0344ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024134ULL;
}

// FDE #0100 | PC: 0x024478..0x0244f4 (124 B) | Symbol: _Z10ApplyToolsPP22CAacDecoderChannelInfoPK16SamplingRateInfoji
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_024478(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024478ULL;
}

// FDE #0101 | PC: 0x0244f4..0x02464c (344 B) | Symbol: _Z22CBlock_FrequencyToTimeP28CAacDecoderStaticChannelInfoP22CAacDecoderChannelInfoPssiiPi
// EN: AArch64 prologue [mov x5, x30; bl #0x69f8c; mov x30, x5; stp x29, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [mov x5, x30; bl #0x69f8c; mov x30, x5; stp x29, x30, [sp, #0x90]]
uint64_t fde_sub_0244f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940116A5ULL) << 32) | 0xAA1E03E5ULL;
    const uint64_t kPcRange = 0x0158ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0244F4ULL;
}

// FDE #0102 | PC: 0x02464c..0x02466c (32 B) | Symbol: _Z30CBlock_FrequencyToTimeLowDelayP28CAacDecoderStaticChannelInfoP22CAacDecoderChannelInfoPssc
// EN: AArch64 prologue [ldr x8, [x1]; ldr x9, [x0]; ldrsh w1, [x1, #8]; and w4, w4, #0xff] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1]; ldr x9, [x0]; ldrsh w1, [x1, #8]; and w4, w4, #0xff]
uint64_t fde_sub_02464c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400009ULL) << 32) | 0xF9400028ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02464CULL;
}

// FDE #0103 | PC: 0x02466c..0x024858 (492 B) | Symbol: _Z22CChannelElement_DecodePP22CAacDecoderChannelInfoPP28CAacDecoderStaticChannelInfoP16SamplingRateInfoji
// EN: AArch64 prologue [mov x5, x30; bl #0x6a250; mov x30, x5; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x5, x30; bl #0x6a250; mov x30, x5; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_02466c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940116F8ULL) << 32) | 0xAA1E03E5ULL;
    const uint64_t kPcRange = 0x01ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02466CULL;
}

// FDE #0104 | PC: 0x024858..0x0248d0 (120 B) | Symbol: _Z26CChannel_CodebookTableInitP22CAacDecoderChannelInfo
// EN: AArch64 prologue [ldrb w11, [x0, #0x23]; ldr x10, [x0, #0xd8]; ldrb w9, [x0, #0x24]; mov w12, #8] | VI: Khởi đầu hàm AArch64 [ldrb w11, [x0, #0x23]; ldr x10, [x0, #0xd8]; ldrb w9, [x0, #0x24]; mov w12, #8]
uint64_t fde_sub_024858(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9406C0AULL) << 32) | 0x39408C0BULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024858ULL;
}

// FDE #0105 | PC: 0x0248d0..0x024c88 (952 B) | Symbol: _Z20CChannelElement_ReadP13FDK_BITSTREAMPP22CAacDecoderChannelInfoPP28CAacDecoderStaticChannelInfo17AUDIO_OBJECT_TYPEPK16SamplingRateInfojjhaP12TRANSPORTDEC
// EN: AArch64 prologue [mov x8, x30; bl #0x6a160; mov x30, x8; stp x29, x30, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x6a160; mov x30, x8; stp x29, x30, [sp, #0x80]]
uint64_t fde_sub_0248d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94011623ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x03B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0248D0ULL;
}

// FDE #0106 | PC: 0x024c88..0x024ce0 (88 B) | Symbol: _Z13IcsReadMaxSfbP13FDK_BITSTREAMP8CIcsInfoPK16SamplingRateInfo
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x1, #0xb]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x1, #0xb]]
uint64_t fde_sub_024c88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024C88ULL;
}

// FDE #0107 | PC: 0x024ce0..0x024e50 (368 B) | Symbol: _Z7IcsReadP13FDK_BITSTREAMP8CIcsInfoPK16SamplingRateInfoj
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_024ce0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024CE0ULL;
}

// FDE #0108 | PC: 0x024e50..0x024ee0 (144 B) | Symbol: _Z19getSamplingRateInfoP16SamplingRateInfojjj
// EN: AArch64 prologue [cmp w1, #0x1e0; stp w2, w3, [x0, #0x14]; b.eq #0x24e7c; cmp w1, #0x200] | VI: Khởi đầu hàm AArch64 [cmp w1, #0x1e0; stp w2, w3, [x0, #0x14]; b.eq #0x24e7c; cmp w1, #0x200]
uint64_t fde_sub_024e50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x29028C02ULL) << 32) | 0x7107803FULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024E50ULL;
}

// FDE #0109 | PC: 0x024ee0..0x024f38 (88 B) | Symbol: _Z27CConcealment_InitCommonDataP14CConcealParams
// EN: AArch64 prologue [cbz x0, #0x24f34; adrp x10, #0x6c000; ldr q0, [x10, #0xa20]; mov x8, xzr] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x24f34; adrp x10, #0x6c000; ldr q0, [x10, #0xa20]; mov x8, xzr]
uint64_t fde_sub_024ee0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9000024AULL) << 32) | 0xB40002A0ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024EE0ULL;
}

// FDE #0110 | PC: 0x024f38..0x024f48 (16 B) | Symbol: _Z22CConcealment_GetMethodP14CConcealParams
// EN: AArch64 prologue [cbz x0, #0x24f44; ldr w0, [x0, #0x40]; ret; b #0x6a07c] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x24f44; ldr w0, [x0, #0x40]; ret; b #0x6a07c]
uint64_t fde_sub_024f38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9404000ULL) << 32) | 0xB4000060ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024F38ULL;
}

// FDE #0111 | PC: 0x024f48..0x024fb0 (104 B) | Symbol: _Z28CConcealment_InitChannelDataP16CConcealmentInfoP14CConcealParamsi
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w8, #0x1018] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w8, #0x1018]
uint64_t fde_sub_024f48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024F48ULL;
}

// FDE #0112 | PC: 0x024fb0..0x02505c (172 B) | Symbol: _Z22CConcealment_SetParamsP14CConcealParamsiiiii
// EN: AArch64 prologue [mov w8, #0xfffe; cmp w1, w8; b.eq #0x24fcc; cmp w1, #2] | VI: Khởi đầu hàm AArch64 [mov w8, #0xfffe; cmp w1, w8; b.eq #0x24fcc; cmp w1, #2]
uint64_t fde_sub_024fb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6B08003FULL) << 32) | 0x529FFFC8ULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x024FB0ULL;
}

// FDE #0113 | PC: 0x02505c..0x025160 (260 B) | Symbol: _Z27CConcealment_SetAttenuationP14CConcealParamsPsS1_
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_02505c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02505CULL;
}

// FDE #0114 | PC: 0x025160..0x02516c (12 B) | Symbol: _Z21CConcealment_GetStateP16CConcealmentInfo
// EN: AArch64 prologue [cbz x0, #0x25168; ldr w0, [x0, #0x11b4]; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x25168; ldr w0, [x0, #0x11b4]; ret]
uint64_t fde_sub_025160(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB951B400ULL) << 32) | 0xB4000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x025160ULL;
}

// FDE #0115 | PC: 0x02516c..0x0252a0 (308 B) | Symbol: _Z18CConcealment_StoreP16CConcealmentInfoP22CAacDecoderChannelInfoP28CAacDecoderStaticChannelInfo
// EN: AArch64 prologue [sub sp, sp, #0x80; str x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_02516c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013FBULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0134ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02516CULL;
}

// FDE #0116 | PC: 0x0252a0..0x0252b8 (24 B) | Symbol: _Z21CConcealment_GetDelayP14CConcealParams
// EN: AArch64 prologue [cbz x0, #0x252b4; ldr w8, [x0, #0x40]; and w8, w8, #0xfffffffe; cmp w8, #2] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x252b4; ldr w8, [x0, #0x40]; and w8, w8, #0xfffffffe; cmp w8, #2]
uint64_t fde_sub_0252a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9404008ULL) << 32) | 0xB40000A0ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0252A0ULL;
}

// FDE #0117 | PC: 0x0252b8..0x025c30 (2424 B) | Symbol: _Z18CConcealment_ApplyP16CConcealmentInfoP22CAacDecoderChannelInfoP28CAacDecoderStaticChannelInfoPK16SamplingRateInfoihij
// EN: AArch64 prologue [mov x2, x30; bl #0x69f18; mov x30, x2; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x69f18; mov x30, x2; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_0252b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94011317ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0978ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0252B8ULL;
}

// FDE #0118 | PC: 0x025c30..0x025ce0 (176 B) | Symbol: sub_025c30
// EN: AArch64 prologue [add x11, x0, #0x20; add x10, x0, w1, sxtw #1; cmp w2, #0; add x13, x11, w1, sxtw #1] | VI: Khởi đầu hàm AArch64 [add x11, x0, #0x20; add x10, x0, w1, sxtw #1; cmp w2, #0; add x13, x11, w1, sxtw #1]
uint64_t fde_sub_025c30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8B21C40AULL) << 32) | 0x9100800BULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x025C30ULL;
}

// FDE #0119 | PC: 0x025ce0..0x025d44 (100 B) | Symbol: sub_025ce0
// EN: AArch64 prologue [adrp x9, #0x9a000; ldr x9, [x9, #0x890]; asr w10, w0, #4; and w11, w0, #0xf] | VI: Khởi đầu hàm AArch64 [adrp x9, #0x9a000; ldr x9, [x9, #0x890]; asr w10, w0, #4; and w11, w0, #0xf]
uint64_t fde_sub_025ce0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9444929ULL) << 32) | 0xB00003A9ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x025CE0ULL;
}

// FDE #0120 | PC: 0x025d44..0x025e2c (232 B) | Symbol: sub_025d44
// EN: AArch64 prologue [ldrb w9, [x1, #0xb]; ldr x8, [x0]; mov w10, #8; mov w11, #0x1f] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x1, #0xb]; ldr x8, [x0]; mov w10, #8; mov w11, #0x1f]
uint64_t fde_sub_025d44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0x39402C29ULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x025D44ULL;
}

// FDE #0121 | PC: 0x025e2c..0x025ff0 (452 B) | Symbol: sub_025e2c
// EN: AArch64 prologue [cmp w2, #2; b.lo #0x25e40; b.eq #0x25f18; cmp w2, #3] | VI: Khởi đầu hàm AArch64 [cmp w2, #2; b.lo #0x25e40; b.eq #0x25f18; cmp w2, #3]
uint64_t fde_sub_025e2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000083ULL) << 32) | 0x7100085FULL;
    const uint64_t kPcRange = 0x01C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x025E2CULL;
}

// FDE #0122 | PC: 0x025ff0..0x0260ac (188 B) | Symbol: sub_025ff0
// EN: AArch64 prologue [adrp x11, #0x9a000; ldr x11, [x11, #0x898]; mov x8, xzr; mov x9, xzr] | VI: Khởi đầu hàm AArch64 [adrp x11, #0x9a000; ldr x11, [x11, #0x898]; mov x8, xzr; mov x9, xzr]
uint64_t fde_sub_025ff0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9444D6BULL) << 32) | 0xB00003ABULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x025FF0ULL;
}

// FDE #0123 | PC: 0x0260ac..0x026138 (140 B) | Symbol: _Z26CConcealment_GetFadeFactorP16CConcealmentInfoi
// EN: AArch64 prologue [ldr x9, [x0]; ldr w10, [x9, #0x40]; cmp w10, #1; b.lt #0x26134] | VI: Khởi đầu hàm AArch64 [ldr x9, [x0]; ldr w10, [x9, #0x40]; cmp w10, #1; b.lt #0x26134]
uint64_t fde_sub_0260ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB940412AULL) << 32) | 0xF9400009ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0260ACULL;
}

// FDE #0124 | PC: 0x026138..0x026150 (24 B) | Symbol: _Z27CConcealment_GetLastFrameOkP16CConcealmentInfoi
// EN: AArch64 prologue [cbz x0, #0x2614c; and w8, w1, #1; add x8, x0, w8, uxtw #2; ldr w0, [x8, #0x101c]] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x2614c; and w8, w1, #1; add x8, x0, w8, uxtw #2; ldr w0, [x8, #0x101c]]
uint64_t fde_sub_026138(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12000028ULL) << 32) | 0xB40000A0ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x026138ULL;
}

// FDE #0125 | PC: 0x026150..0x026520 (976 B) | Symbol: _Z28InvMdctTransformLowDelay_fdkPiiPsS_ii
// EN: AArch64 prologue [mov x6, x30; bl #0x69f8c; mov x30, x6; stp x29, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [mov x6, x30; bl #0x69f8c; mov x30, x6; stp x29, x30, [sp, #0x90]]
uint64_t fde_sub_026150(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94010F8EULL) << 32) | 0xAA1E03E6ULL;
    const uint64_t kPcRange = 0x03D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x026150ULL;
}

// FDE #0126 | PC: 0x026520..0x02660c (236 B) | Symbol: sub_026520
// EN: AArch64 prologue [tbnz w3, #0x1f, #0x26594; cmp w3, #0x1e; mov w9, #0x1e; csel w9, w3, w9, lt] | VI: Khởi đầu hàm AArch64 [tbnz w3, #0x1f, #0x26594; cmp w3, #0x1e; mov w9, #0x1e; csel w9, w3, w9, lt]
uint64_t fde_sub_026520(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100787FULL) << 32) | 0x37F803A3ULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x026520ULL;
}

// FDE #0127 | PC: 0x02660c..0x0266c4 (184 B) | Symbol: sub_02660c
// EN: AArch64 prologue [cbz w2, #0x266c0; cmp w2, #1; b.lt #0x26668; cmp w2, #0x1f] | VI: Khởi đầu hàm AArch64 [cbz w2, #0x266c0; cmp w2, #1; b.lt #0x26668; cmp w2, #0x1f]
uint64_t fde_sub_02660c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100045FULL) << 32) | 0x340005A2ULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02660CULL;
}

// FDE #0128 | PC: 0x0266c4..0x02678c (200 B) | Symbol: _Z15CPulseData_ReadP13FDK_BITSTREAMP10CPulseDataPKsPKvs
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0266c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0266C4ULL;
}

// FDE #0129 | PC: 0x02678c..0x0267d8 (76 B) | Symbol: sub_02678c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #4]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #4]]
uint64_t fde_sub_02678c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02678CULL;
}

// FDE #0130 | PC: 0x0267d8..0x026824 (76 B) | Symbol: _Z16CPulseData_ApplyP10CPulseDataPKsPi
// EN: AArch64 prologue [ldrb w8, [x0]; cbz w8, #0x26820; ldrb w8, [x0, #2]; ldrb w9, [x0, #1]] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0]; cbz w8, #0x26820; ldrb w8, [x0, #2]; ldrb w9, [x0, #1]]
uint64_t fde_sub_0267d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34000228ULL) << 32) | 0x39400008ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0267D8ULL;
}

// FDE #0131 | PC: 0x026824..0x0268ec (200 B) | Symbol: _Z17decodeRVLCodewordP13FDK_BITSTREAMP11CErRvlcInfo
// EN: AArch64 prologue [mov x2, x30; bl #0x6a250; mov x30, x2; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x6a250; mov x30, x2; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_026824(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94010E8AULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x026824ULL;
}

// FDE #0132 | PC: 0x0268ec..0x026a20 (308 B) | Symbol: _Z10CRvlc_ReadP22CAacDecoderChannelInfoP13FDK_BITSTREAM
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0268ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0134ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0268ECULL;
}

// FDE #0133 | PC: 0x026a20..0x0277a0 (3456 B) | Symbol: _Z12CRvlc_DecodeP22CAacDecoderChannelInfoP28CAacDecoderStaticChannelInfoP13FDK_BITSTREAM
// EN: AArch64 prologue [mov x3, x30; bl #0x6ab14; mov x30, x3; stp x29, x30, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x6ab14; mov x30, x3; stp x29, x30, [sp, #0xa0]]
uint64_t fde_sub_026a20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9401103CULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x0D80ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x026A20ULL;
}

// FDE #0134 | PC: 0x0277a0..0x027878 (216 B) | Symbol: _Z18CRvlc_ElementCheckPP22CAacDecoderChannelInfoPP28CAacDecoderStaticChannelInfoji
// EN: AArch64 prologue [cbz x1, #0x27874; tbz w2, #1, #0x27820; cmp w3, #2; b.ne #0x27820] | VI: Khởi đầu hàm AArch64 [cbz x1, #0x27874; tbz w2, #1, #0x27820; cmp w3, #2; b.ne #0x27820]
uint64_t fde_sub_0277a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x360803E2ULL) << 32) | 0xB40006A1ULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0277A0ULL;
}

// FDE #0135 | PC: 0x027878..0x0278e4 (108 B) | Symbol: _Z24rvlcReadBitFromBitstreamP13FDK_BITSTREAMPth
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_027878(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x027878ULL;
}

// FDE #0136 | PC: 0x0278e4..0x027d00 (1052 B) | Symbol: _Z49BidirectionalEstimation_UseLowerScfOfCurrentFrameP22CAacDecoderChannelInfo
// EN: AArch64 prologue [mov x1, x30; bl #0x69f18; mov x30, x1; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x1, x30; bl #0x69f18; mov x30, x1; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_0278e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9401098CULL) << 32) | 0xAA1E03E1ULL;
    const uint64_t kPcRange = 0x041CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0278E4ULL;
}

// FDE #0137 | PC: 0x027d00..0x027fd4 (724 B) | Symbol: _Z52BidirectionalEstimation_UseScfOfPrevFrameAsReferenceP22CAacDecoderChannelInfoP28CAacDecoderStaticChannelInfo
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; ldr x9, [x0, #0xe0]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; ldr x9, [x0, #0xe0]]
uint64_t fde_sub_027d00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BD5FF8ULL;
    const uint64_t kPcRange = 0x02D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x027D00ULL;
}

// FDE #0138 | PC: 0x027fd4..0x028168 (404 B) | Symbol: _Z21StatisticalEstimationP22CAacDecoderChannelInfo
// EN: AArch64 prologue [str x23, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; ldr x14, [x0, #0xe0]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; ldr x14, [x0, #0xe0]]
uint64_t fde_sub_027fd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81D0FF7ULL;
    const uint64_t kPcRange = 0x0194ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x027FD4ULL;
}

// FDE #0139 | PC: 0x028168..0x02826c (260 B) | Symbol: _Z23PredictiveInterpolationP22CAacDecoderChannelInfoP28CAacDecoderStaticChannelInfo
// EN: AArch64 prologue [ldr x13, [x0, #0xe0]; mov w11, #0x37a8; mov w10, #0x109c; mov w14, #0x38e8] | VI: Khởi đầu hàm AArch64 [ldr x13, [x0, #0xe0]; mov w11, #0x37a8; mov w10, #0x109c; mov w14, #0x38e8]
uint64_t fde_sub_028168(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5286F50BULL) << 32) | 0xF940700DULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028168ULL;
}

// FDE #0140 | PC: 0x02826c..0x028338 (204 B) | Symbol: _Z17CJointStereo_ReadP13FDK_BITSTREAMP16CJointStereoDataiij
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_02826c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02826CULL;
}

// FDE #0141 | PC: 0x028338..0x02849c (356 B) | Symbol: _Z20CJointStereo_ApplyMSPP22CAacDecoderChannelInfoPKsPKhiii
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x40]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_028338(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BC67FAULL;
    const uint64_t kPcRange = 0x0164ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028338ULL;
}

// FDE #0142 | PC: 0x02849c..0x02860c (368 B) | Symbol: _Z20CJointStereo_ApplyISPP22CAacDecoderChannelInfoPKsPKhiij
// EN: AArch64 prologue [mov x6, x30; bl #0x69f18; mov x30, x6; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x6, x30; bl #0x69f18; mov x30, x6; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_02849c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9401069EULL) << 32) | 0xAA1E03E6ULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02849CULL;
}

// FDE #0143 | PC: 0x02860c..0x028618 (12 B) | Symbol: _Z17GetAACdynamic_RAMi
// EN: AArch64 prologue [mov w0, #0x4e78; movk w0, #1, lsl #16; b #0x6c88c] | VI: Khởi đầu hàm AArch64 [mov w0, #0x4e78; movk w0, #1, lsl #16; b #0x6c88c]
uint64_t fde_sub_02860c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72A00020ULL) << 32) | 0x5289CF00ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02860CULL;
}

// FDE #0144 | PC: 0x028618..0x028624 (12 B) | Symbol: _Z28GetRequiredMemAACdynamic_RAMv
// EN: AArch64 prologue [mov w0, #0x4e88; movk w0, #1, lsl #16; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x4e88; movk w0, #1, lsl #16; ret]
uint64_t fde_sub_028618(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72A00020ULL) << 32) | 0x5289D100ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028618ULL;
}

// FDE #0145 | PC: 0x028624..0x028630 (12 B) | Symbol: _Z24GetRam_aacEnc_AacEncoderi
// EN: AArch64 prologue [mov w0, #1; mov w1, #0x128; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #1; mov w1, #0x128; b #0x1a748]
uint64_t fde_sub_028624(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52802501ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028624ULL;
}

// FDE #0146 | PC: 0x028630..0x028638 (8 B) | Symbol: _Z35GetRequiredMemRam_aacEnc_AacEncoderv
// EN: AArch64 prologue [mov w0, #0x128; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x128; ret]
uint64_t fde_sub_028630(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52802500ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028630ULL;
}

// FDE #0147 | PC: 0x028638..0x02863c (4 B) | Symbol: _Z24GetRam_aacEnc_PsyElementi
// EN: AArch64 prologue [b #0x6c89c] | VI: Khởi đầu hàm AArch64 [b #0x6c89c]
uint64_t fde_sub_028638(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52801000ULL) << 32) | 0x14011099ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028638ULL;
}

// FDE #0148 | PC: 0x02863c..0x028644 (8 B) | Symbol: _Z35GetRequiredMemRam_aacEnc_PsyElementv
// EN: AArch64 prologue [mov w0, #0x80; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x80; ret]
uint64_t fde_sub_02863c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52801000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02863CULL;
}

// FDE #0149 | PC: 0x028644..0x028650 (12 B) | Symbol: _Z25GetRam_aacEnc_PsyInternali
// EN: AArch64 prologue [mov w0, #1; mov w1, #0xf20; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #1; mov w1, #0xf20; b #0x1a748]
uint64_t fde_sub_028644(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5281E401ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028644ULL;
}

// FDE #0150 | PC: 0x028650..0x028658 (8 B) | Symbol: _Z36GetRequiredMemRam_aacEnc_PsyInternalv
// EN: AArch64 prologue [mov w0, #0xf20; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0xf20; ret]
uint64_t fde_sub_028650(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x5281E400ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028650ULL;
}

// FDE #0151 | PC: 0x028658..0x028664 (12 B) | Symbol: _Z23GetRam_aacEnc_PsyStatici
// EN: AArch64 prologue [mov w0, #1; mov w1, #0x11b0; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #1; mov w1, #0x11b0; b #0x1a748]
uint64_t fde_sub_028658(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52823601ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028658ULL;
}

// FDE #0152 | PC: 0x028664..0x02866c (8 B) | Symbol: _Z34GetRequiredMemRam_aacEnc_PsyStaticv
// EN: AArch64 prologue [mov w0, #0x8d80; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x8d80; ret]
uint64_t fde_sub_028664(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x5291B000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028664ULL;
}

// FDE #0153 | PC: 0x02866c..0x028678 (12 B) | Symbol: _Z28GetRam_aacEnc_PsyInputBufferi
// EN: AArch64 prologue [mov w0, #0x800; mov w1, #2; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #0x800; mov w1, #2; b #0x1a748]
uint64_t fde_sub_02866c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800041ULL) << 32) | 0x52810000ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02866CULL;
}

// FDE #0154 | PC: 0x028678..0x028680 (8 B) | Symbol: _Z39GetRequiredMemRam_aacEnc_PsyInputBufferv
// EN: AArch64 prologue [mov w0, #0x8000; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x8000; ret]
uint64_t fde_sub_028678(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52900000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028678ULL;
}

// FDE #0155 | PC: 0x028680..0x028694 (20 B) | Symbol: _Z24GetRam_aacEnc_PsyDynamiciPh
// EN: AArch64 prologue [mov w8, #0x23f8; mov w9, #0x2a80; smaddl x8, w0, w8, x1; movk w9, #1, lsl #16] | VI: Khởi đầu hàm AArch64 [mov w8, #0x23f8; mov w9, #0x2a80; smaddl x8, w0, w8, x1; movk w9, #1, lsl #16]
uint64_t fde_sub_028680(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52855009ULL) << 32) | 0x52847F08ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028680ULL;
}

// FDE #0156 | PC: 0x028694..0x02869c (8 B) | Symbol: _Z29GetRam_TransportDecoderBufferi
// EN: AArch64 prologue [mov w0, #0x2000; b #0x6a9cc] | VI: Khởi đầu hàm AArch64 [mov w0, #0x2000; b #0x6a9cc]
uint64_t fde_sub_028694(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x140108CDULL) << 32) | 0x52840000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028694ULL;
}

// FDE #0157 | PC: 0x02869c..0x0286a0 (4 B) | Symbol: _Z32GetRequiredMemRam_Sbr_signMatrixv
// EN: AArch64 prologue [b #0x6bd04] | VI: Khởi đầu hàm AArch64 [b #0x6bd04]
uint64_t fde_sub_02869c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800020ULL) << 32) | 0x14010D9AULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02869CULL;
}

// FDE #0158 | PC: 0x0286a0..0x0286ac (12 B) | Symbol: _Z20GetRam_aacEnc_PsyOuti
// EN: AArch64 prologue [mov w0, #1; mov w1, #0x80; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #1; mov w1, #0x80; b #0x1a748]
uint64_t fde_sub_0286a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52801001ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0286A0ULL;
}

// FDE #0159 | PC: 0x0286ac..0x0286b8 (12 B) | Symbol: _Z28GetRam_aacEnc_PsyOutElementsi
// EN: AArch64 prologue [mov w0, #1; mov w1, #0x108; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #1; mov w1, #0x108; b #0x1a748]
uint64_t fde_sub_0286ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52802101ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0286ACULL;
}

// FDE #0160 | PC: 0x0286b8..0x0286c0 (8 B) | Symbol: _Z39GetRequiredMemRam_aacEnc_PsyOutElementsv
// EN: AArch64 prologue [mov w0, #0x840; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x840; ret]
uint64_t fde_sub_0286b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52810800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0286B8ULL;
}

// FDE #0161 | PC: 0x0286c0..0x0286cc (12 B) | Symbol: _Z27GetRam_aacEnc_PsyOutChanneli
// EN: AArch64 prologue [mov w0, #1; mov w1, #0x860; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #1; mov w1, #0x860; b #0x1a748]
uint64_t fde_sub_0286c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52810C01ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0286C0ULL;
}

// FDE #0162 | PC: 0x0286cc..0x0286d4 (8 B) | Symbol: _Z38GetRequiredMemRam_aacEnc_PsyOutChannelv
// EN: AArch64 prologue [mov w0, #0x4300; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x4300; ret]
uint64_t fde_sub_0286cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52886000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0286CCULL;
}

// FDE #0163 | PC: 0x0286d4..0x0286e0 (12 B) | Symbol: _Z21GetRam_aacEnc_QCstatei
// EN: AArch64 prologue [mov w0, #1; mov w1, #0x90; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #1; mov w1, #0x90; b #0x1a748]
uint64_t fde_sub_0286d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52801201ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0286D4ULL;
}

// FDE #0164 | PC: 0x0286e0..0x0286e8 (8 B) | Symbol: _Z32GetRequiredMemRam_aacEnc_QCstatev
// EN: AArch64 prologue [mov w0, #0x90; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x90; ret]
uint64_t fde_sub_0286e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52801200ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0286E0ULL;
}

// FDE #0165 | PC: 0x0286e8..0x0286f4 (12 B) | Symbol: _Z29GetRam_aacEnc_AdjustThresholdi
// EN: AArch64 prologue [mov w0, #1; mov w1, #0x88; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #1; mov w1, #0x88; b #0x1a748]
uint64_t fde_sub_0286e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52801101ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0286E8ULL;
}

// FDE #0166 | PC: 0x0286f4..0x0286fc (8 B) | Symbol: _Z40GetRequiredMemRam_aacEnc_AdjustThresholdv
// EN: AArch64 prologue [mov w0, #0x88; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x88; ret]
uint64_t fde_sub_0286f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52801100ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0286F4ULL;
}

// FDE #0167 | PC: 0x0286fc..0x028708 (12 B) | Symbol: _Z32GetRam_aacEnc_AdjThrStateElementi
// EN: AArch64 prologue [mov w0, #1; mov w1, #0x5c; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #1; mov w1, #0x5c; b #0x1a748]
uint64_t fde_sub_0286fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800B81ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0286FCULL;
}

// FDE #0168 | PC: 0x028708..0x028710 (8 B) | Symbol: _Z43GetRequiredMemRam_aacEnc_AdjThrStateElementv
// EN: AArch64 prologue [mov w0, #0x300; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x300; ret]
uint64_t fde_sub_028708(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52806000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028708ULL;
}

// FDE #0169 | PC: 0x028710..0x02871c (12 B) | Symbol: _Z25GetRam_aacEnc_ElementBitsi
// EN: AArch64 prologue [mov w0, #1; mov w1, #0x14; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #1; mov w1, #0x14; b #0x1a748]
uint64_t fde_sub_028710(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800281ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028710ULL;
}

// FDE #0170 | PC: 0x02871c..0x028724 (8 B) | Symbol: _Z36GetRequiredMemRam_aacEnc_ElementBitsv
// EN: AArch64 prologue [mov w0, #0xc0; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0xc0; ret]
uint64_t fde_sub_02871c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52801800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02871CULL;
}

// FDE #0171 | PC: 0x028724..0x02872c (8 B) | Symbol: _Z37GetRequiredMemRam_aacEnc_BitCntrStatev
// EN: AArch64 prologue [mov w0, #0x10; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x10; ret]
uint64_t fde_sub_028724(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800200ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028724ULL;
}

// FDE #0172 | PC: 0x02872c..0x028734 (8 B) | Symbol: _Z23GetRam_aacEnc_BitLookUpiPh
// EN: AArch64 prologue [mov w8, #0x2a80; b #0x6c578] | VI: Khởi đầu hàm AArch64 [mov w8, #0x2a80; b #0x6c578]
uint64_t fde_sub_02872c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14010F92ULL) << 32) | 0x52855008ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02872CULL;
}

// FDE #0173 | PC: 0x028734..0x02873c (8 B) | Symbol: _Z29GetRam_aacEnc_MergeGainLookUpiPh
// EN: AArch64 prologue [mov w8, #0x3410; b #0x6c578] | VI: Khởi đầu hàm AArch64 [mov w8, #0x3410; b #0x6c578]
uint64_t fde_sub_028734(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14010F90ULL) << 32) | 0x52868208ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028734ULL;
}

// FDE #0174 | PC: 0x02873c..0x028748 (12 B) | Symbol: _Z19GetRam_aacEnc_QCouti
// EN: AArch64 prologue [mov w0, #1; mov w1, #0xf0; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #1; mov w1, #0xf0; b #0x1a748]
uint64_t fde_sub_02873c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52801E01ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02873CULL;
}

// FDE #0175 | PC: 0x028748..0x028750 (8 B) | Symbol: _Z30GetRequiredMemRam_aacEnc_QCoutv
// EN: AArch64 prologue [mov w0, #0xf0; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0xf0; ret]
uint64_t fde_sub_028748(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52801E00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028748ULL;
}

// FDE #0176 | PC: 0x028750..0x02875c (12 B) | Symbol: _Z23GetRam_aacEnc_QCelementi
// EN: AArch64 prologue [mov w0, #1; mov w1, #0x7e8; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #1; mov w1, #0x7e8; b #0x1a748]
uint64_t fde_sub_028750(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5280FD01ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028750ULL;
}

// FDE #0177 | PC: 0x02875c..0x028764 (8 B) | Symbol: _Z34GetRequiredMemRam_aacEnc_QCelementv
// EN: AArch64 prologue [mov w0, #0x3f40; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x3f40; ret]
uint64_t fde_sub_02875c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x5287E800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02875CULL;
}

// FDE #0178 | PC: 0x028764..0x028770 (12 B) | Symbol: _Z23GetRam_aacEnc_QCchanneliPh
// EN: AArch64 prologue [mov w8, #0x2550; smaddl x0, w0, w8, x1; ret] | VI: Khởi đầu hàm AArch64 [mov w8, #0x2550; smaddl x0, w0, w8, x1; ret]
uint64_t fde_sub_028764(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9B280400ULL) << 32) | 0x5284AA08ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028764ULL;
}

// FDE #0179 | PC: 0x028770..0x0287a0 (48 B) | Symbol: FDKaacEnc_CalcBitsPerFrame
// EN: AArch64 prologue [orr w9, w2, w1; mov w8, #-1; mov w10, #-2; add w8, w8, #1] | VI: Khởi đầu hàm AArch64 [orr w9, w2, w1; mov w8, #-1; mov w10, #-2; add w8, w8, #1]
uint64_t fde_sub_028770(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12800008ULL) << 32) | 0x2A010049ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028770ULL;
}

// FDE #0180 | PC: 0x0287a0..0x0287d0 (48 B) | Symbol: FDKaacEnc_CalcBitrate
// EN: AArch64 prologue [orr w9, w2, w1; mov w8, #-1; mov w10, #-2; add w8, w8, #1] | VI: Khởi đầu hàm AArch64 [orr w9, w2, w1; mov w8, #-1; mov w10, #-2; add w8, w8, #1]
uint64_t fde_sub_0287a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12800008ULL) << 32) | 0x2A010049ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0287A0ULL;
}

// FDE #0181 | PC: 0x0287d0..0x0288a8 (216 B) | Symbol: FDKaacEnc_LimitBitrate
// EN: AArch64 prologue [mov x6, x30; bl #0x69f4c; mov x30, x6; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x6, x30; bl #0x69f4c; mov x30, x6; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_0287d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940105DEULL) << 32) | 0xAA1E03E6ULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0287D0ULL;
}

// FDE #0182 | PC: 0x0288a8..0x028910 (104 B) | Symbol: FDKaacEnc_GetVBRBitrate
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub w8, w0, #1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub w8, w0, #1]
uint64_t fde_sub_0288a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0288A8ULL;
}

// FDE #0183 | PC: 0x028910..0x028970 (96 B) | Symbol: FDKaacEnc_AacInitDefaultConfig
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w1, #0x58] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w1, #0x58]
uint64_t fde_sub_028910(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028910ULL;
}

// FDE #0184 | PC: 0x028970..0x028a40 (208 B) | Symbol: FDKaacEnc_Open
// EN: AArch64 prologue [cbz x0, #0x28a28; stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x28a28; stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]]
uint64_t fde_sub_028970(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BC5FF8ULL) << 32) | 0xB40005C0ULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028970ULL;
}

// FDE #0185 | PC: 0x028a40..0x02907c (1596 B) | Symbol: FDKaacEnc_Initialize
// EN: AArch64 prologue [sub sp, sp, #0xf0; str x27, [sp, #0x90]; stp x26, x25, [sp, #0xa0]; stp x24, x23, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xf0; str x27, [sp, #0x90]; stp x26, x25, [sp, #0xa0]; stp x24, x23, [sp, #0xb0]]
uint64_t fde_sub_028a40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9004BFBULL) << 32) | 0xD103C3FFULL;
    const uint64_t kPcRange = 0x063CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x028A40ULL;
}

// FDE #0186 | PC: 0x02907c..0x029578 (1276 B) | Symbol: FDKaacEnc_EncodeFrame
// EN: AArch64 prologue [mov x5, x30; bl #0x6a894; mov x30, x5; stp x29, x30, [sp, #0xe0]] | VI: Khởi đầu hàm AArch64 [mov x5, x30; bl #0x6a894; mov x30, x5; stp x29, x30, [sp, #0xe0]]
uint64_t fde_sub_02907c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94010605ULL) << 32) | 0xAA1E03E5ULL;
    const uint64_t kPcRange = 0x04FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02907CULL;
}

// FDE #0187 | PC: 0x029578..0x0295d0 (88 B) | Symbol: FDKaacEnc_Close
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0]]
uint64_t fde_sub_029578(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x029578ULL;
}

// FDE #0188 | PC: 0x0295d0..0x0295dc (12 B) | Symbol: _Z14Get_AacEncoderi
// EN: AArch64 prologue [mov w0, #1; mov w1, #0xa98; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #1; mov w1, #0xa98; b #0x1a748]
uint64_t fde_sub_0295d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52815301ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0295D0ULL;
}

// FDE #0189 | PC: 0x0295dc..0x0295e4 (8 B) | Symbol: _Z25GetRequiredMem_AacEncoderv
// EN: AArch64 prologue [mov w0, #0xa98; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0xa98; ret]
uint64_t fde_sub_0295dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52815300ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0295DCULL;
}

// FDE #0190 | PC: 0x0295e4..0x0296c0 (220 B) | Symbol: _Z19aacEncDefaultConfigP13AACENC_CONFIGP10USER_PARAM
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x6a440] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x6a440]
uint64_t fde_sub_0295e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0295E4ULL;
}

// FDE #0191 | PC: 0x0296c0..0x029944 (644 B) | Symbol: aacEncOpen
// EN: AArch64 prologue [stp x28, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0296c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FCULL;
    const uint64_t kPcRange = 0x0284ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0296C0ULL;
}

// FDE #0192 | PC: 0x029944..0x029968 (36 B) | Symbol: sub_029944
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x0, [x0, #0xe8]; mov w2, w7] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x0, [x0, #0xe8]; mov w2, w7]
uint64_t fde_sub_029944(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x029944ULL;
}

// FDE #0193 | PC: 0x029968..0x0299f8 (144 B) | Symbol: aacEncClose
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x299ec] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x299ec]
uint64_t fde_sub_029968(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x029968ULL;
}

// FDE #0194 | PC: 0x0299f8..0x02ab40 (4424 B) | Symbol: aacEncEncode
// EN: AArch64 prologue [mov x5, x30; bl #0x69f18; mov x30, x5; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x5, x30; bl #0x69f18; mov x30, x5; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_0299f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94010147ULL) << 32) | 0xAA1E03E5ULL;
    const uint64_t kPcRange = 0x1148ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0299F8ULL;
}

// FDE #0195 | PC: 0x02ab40..0x02ab6c (44 B) | Symbol: sub_02ab40
// EN: AArch64 prologue [ldr w8, [x0, #0x10]; cmp w8, #5; ccmp w8, #0x1d, #4, ne; b.ne #0x2ab54] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #0x10]; cmp w8, #5; ccmp w8, #0x1d, #4, ne; b.ne #0x2ab54]
uint64_t fde_sub_02ab40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100151FULL) << 32) | 0xB9401008ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02AB40ULL;
}

// FDE #0196 | PC: 0x02ab6c..0x02abd8 (108 B) | Symbol: sub_02ab6c
// EN: AArch64 prologue [mov w8, w0; cmn w1, #1; mov w0, #-1; b.eq #0x2abc4] | VI: Khởi đầu hàm AArch64 [mov w8, w0; cmn w1, #1; mov w0, #-1; b.eq #0x2abc4]
uint64_t fde_sub_02ab6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3100043FULL) << 32) | 0x2A0003E8ULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02AB6CULL;
}

// FDE #0197 | PC: 0x02abd8..0x02ac7c (164 B) | Symbol: sub_02abd8
// EN: AArch64 prologue [mov x3, x30; bl #0x6a250; mov x30, x3; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x6a250; mov x30, x3; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_02abd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400FD9DULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02ABD8ULL;
}

// FDE #0198 | PC: 0x02ac7c..0x02acb0 (52 B) | Symbol: sub_02ac7c
// EN: AArch64 prologue [ldrsw x9, [x0]; mov x8, x0; mov x0, xzr; cmp x0, x9] | VI: Khởi đầu hàm AArch64 [ldrsw x9, [x0]; mov x8, x0; mov x0, xzr; cmp x0, x9]
uint64_t fde_sub_02ac7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003E8ULL) << 32) | 0xB9800009ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02AC7CULL;
}

// FDE #0199 | PC: 0x02acb0..0x02acfc (76 B) | Symbol: sub_02acb0
// EN: AArch64 prologue [cmp w1, #1; b.lt #0x2acd4; cbz w0, #0x2accc; eor w8, w0, w0, asr #31] | VI: Khởi đầu hàm AArch64 [cmp w1, #1; b.lt #0x2acd4; cbz w0, #0x2accc; eor w8, w0, w0, asr #31]
uint64_t fde_sub_02acb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5400010BULL) << 32) | 0x7100043FULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02ACB0ULL;
}

// FDE #0200 | PC: 0x02acfc..0x02ada0 (164 B) | Symbol: aacEncGetLibInfo
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x2ad44] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x2ad44]
uint64_t fde_sub_02acfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02ACFCULL;
}

// FDE #0201 | PC: 0x02ada0..0x02b270 (1232 B) | Symbol: aacEncoder_SetParam
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x2ae28] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x2ae28]
uint64_t fde_sub_02ada0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x04D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02ADA0ULL;
}

// FDE #0202 | PC: 0x02b270..0x02b408 (408 B) | Symbol: aacEncoder_GetParam
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x2b400] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x2b400]
uint64_t fde_sub_02b270(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0198ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02B270ULL;
}

// FDE #0203 | PC: 0x02b408..0x02b540 (312 B) | Symbol: aacEncInfo
// EN: AArch64 prologue [sub sp, sp, #0xd0; stp x24, x23, [sp, #0x90]; stp x22, x21, [sp, #0xa0]; stp x20, x19, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xd0; stp x24, x23, [sp, #0x90]; stp x22, x21, [sp, #0xa0]; stp x20, x19, [sp, #0xb0]]
uint64_t fde_sub_02b408(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9095FF8ULL) << 32) | 0xD10343FFULL;
    const uint64_t kPcRange = 0x0138ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02B408ULL;
}

// FDE #0204 | PC: 0x02b540..0x02b588 (72 B) | Symbol: _Z30FDKaacEnc_InitPnsConfigurationP10PNS_CONFIGiiiiPKiii
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x8, x5] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x8, x5]
uint64_t fde_sub_02b540(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02B540ULL;
}

// FDE #0205 | PC: 0x02b588..0x02b824 (668 B) | Symbol: _Z19FDKaacEnc_PnsDetectP10PNS_CONFIGP8PNS_DATAiiiPiPKiS3_S3_PsiiiS3_S3_
// EN: AArch64 prologue [mov x8, x30; bl #0x6a250; mov x30, x8; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x6a250; mov x30, x8; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_02b588(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400FB31ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x029CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02B588ULL;
}

// FDE #0206 | PC: 0x02b824..0x02b8e8 (196 B) | Symbol: _Z24FDKaacEnc_CodePnsChanneliP10PNS_CONFIGPiS1_S1_S1_
// EN: AArch64 prologue [ldr w9, [x1, #0x9c]; sxtw x8, w0; cbz w9, #0x2b8c8; mov x9, xzr] | VI: Khởi đầu hàm AArch64 [ldr w9, [x1, #0x9c]; sxtw x8, w0; cbz w9, #0x2b8c8; mov x9, xzr]
uint64_t fde_sub_02b824(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x93407C08ULL) << 32) | 0xB9409C29ULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02B824ULL;
}

// FDE #0207 | PC: 0x02b8e8..0x02b9b8 (208 B) | Symbol: _Z34FDKaacEnc_PreProcessPnsChannelPairiPiS_S_S_S_P10PNS_CONFIGP8PNS_DATAS3_
// EN: AArch64 prologue [mov x8, x30; bl #0x69f4c; mov x30, x8; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x69f4c; mov x30, x8; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_02b8e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400F998ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02B8E8ULL;
}

// FDE #0208 | PC: 0x02b9b8..0x02ba58 (160 B) | Symbol: _Z35FDKaacEnc_PostProcessPnsChannelPairiP10PNS_CONFIGP8PNS_DATAS2_PiS3_
// EN: AArch64 prologue [ldr w8, [x1, #0x9c]; cbz w8, #0x2ba54; mov x8, xzr; sxtw x9, w0] | VI: Khởi đầu hàm AArch64 [ldr w8, [x1, #0x9c]; cbz w8, #0x2ba54; mov x8, xzr; sxtw x9, w0]
uint64_t fde_sub_02b9b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x340004C8ULL) << 32) | 0xB9409C28ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02B9B8ULL;
}

// FDE #0209 | PC: 0x02ba58..0x02bac4 (108 B) | Symbol: _Z32FDKaacEnc_FreqToBandWithRoundingiiiPKi
// EN: AArch64 prologue [ldr w9, [x3, w2, sxtw #2]; mov w10, #2; mul w8, w0, w9; lsl w8, w8, #2] | VI: Khởi đầu hàm AArch64 [ldr w9, [x3, w2, sxtw #2]; mov w10, #2; mul w8, w0, w9; lsl w8, w8, #2]
uint64_t fde_sub_02ba58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5280004AULL) << 32) | 0xB862D869ULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02BA58ULL;
}

// FDE #0210 | PC: 0x02bac4..0x02bdc4 (768 B) | Symbol: _Z30FDKaacEnc_InitTnsConfigurationiiiiiiiP10TNS_CONFIGP17PSY_CONFIGURATIONii
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_02bac4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0300ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02BAC4ULL;
}

// FDE #0211 | PC: 0x02bdc4..0x02beac (232 B) | Symbol: sub_02bdc4
// EN: AArch64 prologue [mov x5, x30; bl #0x6a250; mov x30, x5; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x5, x30; bl #0x6a250; mov x30, x5; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_02bdc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400F922ULL) << 32) | 0xAA1E03E5ULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02BDC4ULL;
}

// FDE #0212 | PC: 0x02beac..0x02c838 (2444 B) | Symbol: _Z19FDKaacEnc_TnsDetectP8TNS_DATAPK10TNS_CONFIGP8TNS_INFOiPiii
// EN: AArch64 prologue [mov x7, x30; bl #0x69f18; mov x30, x7; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x7, x30; bl #0x69f18; mov x30, x7; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_02beac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400F81AULL) << 32) | 0xAA1E03E7ULL;
    const uint64_t kPcRange = 0x098CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02BEACULL;
}

// FDE #0213 | PC: 0x02c838..0x02c89c (100 B) | Symbol: sub_02c838
// EN: AArch64 prologue [sxtw x9, w2; mov w8, wzr; sxtw x10, w3; mov x11, x9] | VI: Khởi đầu hàm AArch64 [sxtw x9, w2; mov w8, wzr; sxtw x10, w3; mov x11, x9]
uint64_t fde_sub_02c838(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E8ULL) << 32) | 0x93407C49ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02C838ULL;
}

// FDE #0214 | PC: 0x02c89c..0x02c91c (128 B) | Symbol: sub_02c89c
// EN: AArch64 prologue [mov x8, x0; mov w0, wzr; cbz w3, #0x2c8e4; sub w10, w2, w3] | VI: Khởi đầu hàm AArch64 [mov x8, x0; mov w0, wzr; cbz w3, #0x2c8e4; sub w10, w2, w3]
uint64_t fde_sub_02c89c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02C89CULL;
}

// FDE #0215 | PC: 0x02c91c..0x02c9b0 (148 B) | Symbol: sub_02c91c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x2] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x2]
uint64_t fde_sub_02c91c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02C91CULL;
}

// FDE #0216 | PC: 0x02c9b0..0x02cb14 (356 B) | Symbol: sub_02c9b0
// EN: AArch64 prologue [mov x3, x30; bl #0x69f8c; mov x30, x3; stp x29, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x69f8c; mov x30, x3; stp x29, x30, [sp, #0x90]]
uint64_t fde_sub_02c9b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400F576ULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x0164ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02C9B0ULL;
}

// FDE #0217 | PC: 0x02cb14..0x02cba4 (144 B) | Symbol: sub_02cb14
// EN: AArch64 prologue [adrp x10, #0x9a000; adrp x11, #0x9a000; ldr x10, [x10, #0x8c0]; ldr x11, [x11, #0x8c8]] | VI: Khởi đầu hàm AArch64 [adrp x10, #0x9a000; adrp x11, #0x9a000; ldr x10, [x10, #0x8c0]; ldr x11, [x11, #0x8c8]]
uint64_t fde_sub_02cb14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD000036BULL) << 32) | 0xD000036AULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CB14ULL;
}

// FDE #0218 | PC: 0x02cba4..0x02ccc8 (292 B) | Symbol: _Z17FDKaacEnc_TnsSyncP8TNS_DATAPKS_P8TNS_INFOS4_iiPK10TNS_CONFIG
// EN: AArch64 prologue [cmp w4, #2; ccmp w5, #2, #0, ne; b.eq #0x2ccc4; cmp w4, #2] | VI: Khởi đầu hàm AArch64 [cmp w4, #2; ccmp w5, #2, #0, ne; b.eq #0x2ccc4; cmp w4, #2]
uint64_t fde_sub_02cba4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7A4218A0ULL) << 32) | 0x7100089FULL;
    const uint64_t kPcRange = 0x0124ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CBA4ULL;
}

// FDE #0219 | PC: 0x02ccc8..0x02d000 (824 B) | Symbol: _Z19FDKaacEnc_TnsEncodeP8TNS_INFOP8TNS_DATAiPK10TNS_CONFIGiPiii
// EN: AArch64 prologue [sub sp, sp, #0x1a0; stp x28, x27, [sp, #0x140]; stp x26, x25, [sp, #0x150]; stp x24, x23, [sp, #0x160]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1a0; stp x28, x27, [sp, #0x140]; stp x26, x25, [sp, #0x150]; stp x24, x23, [sp, #0x160]]
uint64_t fde_sub_02ccc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9146FFCULL) << 32) | 0xD10683FFULL;
    const uint64_t kPcRange = 0x0338ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02CCC8ULL;
}

// FDE #0220 | PC: 0x02d000..0x02d418 (1048 B) | Symbol: _Z23FDKaacEnc_peCalculationP7PE_DATAPP15PSY_OUT_CHANNELPP14QC_OUT_CHANNELP9TOOLSINFOP11ATS_ELEMENTi
// EN: AArch64 prologue [sub sp, sp, #0xd0; stp x28, x27, [sp, #0x70]; stp x26, x25, [sp, #0x80]; stp x24, x23, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xd0; stp x28, x27, [sp, #0x70]; stp x26, x25, [sp, #0x80]; stp x24, x23, [sp, #0x90]]
uint64_t fde_sub_02d000(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9076FFCULL) << 32) | 0xD10343FFULL;
    const uint64_t kPcRange = 0x0418ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D000ULL;
}

// FDE #0221 | PC: 0x02d418..0x02d4c0 (168 B) | Symbol: sub_02d418
// EN: AArch64 prologue [mov x4, x30; bl #0x6aba8; mov x30, x4; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x4, x30; bl #0x6aba8; mov x30, x4; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_02d418(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400F5E3ULL) << 32) | 0xAA1E03E4ULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D418ULL;
}

// FDE #0222 | PC: 0x02d4c0..0x02d6d0 (528 B) | Symbol: _Z22FDKaacEnc_reduceMinSnrP15CHANNEL_MAPPINGPP14QC_OUT_ELEMENTPP15PSY_OUT_ELEMENTPA2_A60_hiPiii
// EN: AArch64 prologue [mov x8, x30; bl #0x69f8c; mov x30, x8; stp x29, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x69f8c; mov x30, x8; stp x29, x30, [sp, #0x90]]
uint64_t fde_sub_02d4c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400F2B2ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x0210ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D4C0ULL;
}

// FDE #0223 | PC: 0x02d6d0..0x02dd78 (1704 B) | Symbol: _Z28FDKaacEnc_AdaptThresholdsVBRPP14QC_OUT_CHANNELPP15PSY_OUT_CHANNELP11ATS_ELEMENTP9TOOLSINFOP7PE_DATAi
// EN: AArch64 prologue [mov x4, x30; bl #0x69f18; mov x30, x4; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x4, x30; bl #0x69f18; mov x30, x4; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_02d6d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400F211ULL) << 32) | 0xAA1E03E4ULL;
    const uint64_t kPcRange = 0x06A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02D6D0ULL;
}

// FDE #0224 | PC: 0x02dd78..0x02de08 (144 B) | Symbol: sub_02dd78
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; mov x3, x30; bl #0x69fa8; mov x30, x3] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; mov x3, x30; bl #0x69fa8; mov x30, x3]
uint64_t fde_sub_02dd78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E3ULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02DD78ULL;
}

// FDE #0225 | PC: 0x02de08..0x02df9c (404 B) | Symbol: sub_02de08
// EN: AArch64 prologue [mov x4, x30; bl #0x69f18; mov x30, x4; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x4, x30; bl #0x69f18; mov x30, x4; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_02de08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400F043ULL) << 32) | 0xAA1E03E4ULL;
    const uint64_t kPcRange = 0x0194ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02DE08ULL;
}

// FDE #0226 | PC: 0x02df9c..0x02e450 (1204 B) | Symbol: sub_02df9c
// EN: AArch64 prologue [mov x6, x30; bl #0x69f8c; mov x30, x6; stp x29, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [mov x6, x30; bl #0x69f8c; mov x30, x6; stp x29, x30, [sp, #0x90]]
uint64_t fde_sub_02df9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400EFFBULL) << 32) | 0xAA1E03E6ULL;
    const uint64_t kPcRange = 0x04B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02DF9CULL;
}

// FDE #0227 | PC: 0x02e450..0x02e4b4 (100 B) | Symbol: _Z19FDKaacEnc_AdjThrNewPP13ADJ_THR_STATEi
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_02e450(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02E450ULL;
}

// FDE #0228 | PC: 0x02e4b4..0x02e7cc (792 B) | Symbol: _Z20FDKaacEnc_AdjThrInitP13ADJ_THR_STATEiPP12ELEMENT_BITSiiiiiii
// EN: AArch64 prologue [mov x8, x30; bl #0x69f4c; mov x30, x8; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x69f4c; mov x30, x8; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_02e4b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400EEA5ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x0318ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02E4B4ULL;
}

// FDE #0229 | PC: 0x02e7cc..0x02ef74 (1960 B) | Symbol: _Z24FDKaacEnc_DistributeBitsP13ADJ_THR_STATEP11ATS_ELEMENTPP15PSY_OUT_CHANNELP7PE_DATAPiS8_iiiiiii
// EN: AArch64 prologue [mov x7, x30; bl #0x69f4c; mov x30, x7; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x7, x30; bl #0x69f4c; mov x30, x7; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_02e7cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400EDDFULL) << 32) | 0xAA1E03E7ULL;
    const uint64_t kPcRange = 0x07A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02E7CCULL;
}

// FDE #0230 | PC: 0x02ef74..0x030408 (5268 B) | Symbol: _Z26FDKaacEnc_AdjustThresholdsPP11ATS_ELEMENTPP14QC_OUT_ELEMENTP6QC_OUTPP15PSY_OUT_ELEMENTiiP15CHANNEL_MAPPING
// EN: AArch64 prologue [mov x2, x30; bl #0x69f18; mov x30, x2; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x69f18; mov x30, x2; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_02ef74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400EBE8ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x1494ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x02EF74ULL;
}

// FDE #0231 | PC: 0x030408..0x03045c (84 B) | Symbol: sub_030408
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x2] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x2]
uint64_t fde_sub_030408(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x030408ULL;
}

// FDE #0232 | PC: 0x03045c..0x030650 (500 B) | Symbol: sub_03045c
// EN: AArch64 prologue [mov x7, x30; bl #0x69f8c; mov x30, x7; stp x29, x30, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [mov x7, x30; bl #0x69f8c; mov x30, x7; stp x29, x30, [sp, #0x90]]
uint64_t fde_sub_03045c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400E6CBULL) << 32) | 0xAA1E03E7ULL;
    const uint64_t kPcRange = 0x01F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03045CULL;
}

// FDE #0233 | PC: 0x030650..0x0306b0 (96 B) | Symbol: _Z21FDKaacEnc_AdjThrClosePP13ADJ_THR_STATE
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_030650(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x030650ULL;
}

// FDE #0234 | PC: 0x0306b0..0x030718 (104 B) | Symbol: _Z29FDKaacEnc_CalcSfbMaxScaleSpecPKiS0_Pii
// EN: AArch64 prologue [mov x8, xzr; sxtw x9, w3; cmp x8, x9; b.ge #0x30714] | VI: Khởi đầu hàm AArch64 [mov x8, xzr; sxtw x9, w3; cmp x8, x9; b.ge #0x30714]
uint64_t fde_sub_0306b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x93407C69ULL) << 32) | 0xAA1F03E8ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0306B0ULL;
}

// FDE #0235 | PC: 0x030718..0x030840 (296 B) | Symbol: _Z30FDKaacEnc_CheckBandEnergyOptimPKiPiS0_iS1_S1_i
// EN: AArch64 prologue [mov x7, x30; bl #0x69f4c; mov x30, x7; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x7, x30; bl #0x69f4c; mov x30, x7; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_030718(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400E60CULL) << 32) | 0xAA1E03E7ULL;
    const uint64_t kPcRange = 0x0128ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x030718ULL;
}

// FDE #0236 | PC: 0x030840..0x030a24 (484 B) | Symbol: _Z33FDKaacEnc_CalcBandEnergyOptimLongPKiPiS0_iS1_S1_
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_030840(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x01E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x030840ULL;
}

// FDE #0237 | PC: 0x030a24..0x030afc (216 B) | Symbol: _Z34FDKaacEnc_CalcBandEnergyOptimShortPKiPiS0_iS1_
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_030a24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x030A24ULL;
}

// FDE #0238 | PC: 0x030afc..0x030cc4 (456 B) | Symbol: _Z26FDKaacEnc_CalcBandNrgMSOptPKiS0_PiS1_S0_iS1_S1_iS1_S1_
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; mov x8, x30; bl #0x69fa8; mov x30, x8] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; mov x8, x30; bl #0x69fa8; mov x30, x8]
uint64_t fde_sub_030afc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E8ULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x01C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x030AFCULL;
}

// FDE #0239 | PC: 0x030cc4..0x030fa8 (740 B) | Symbol: _Z28FDKaacEnc_DetermineBandWidthPiii19AACENC_BITRATE_MODEiiP15CHANNEL_MAPPING12CHANNEL_MODE
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_030cc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x02E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x030CC4ULL;
}

// FDE #0240 | PC: 0x030fa8..0x030fec (68 B) | Symbol: _Z18FDKaacEnc_bitCountPKsiiPi
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; cmp w2, #0; mov w8, #0x1fffffff] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; cmp w2, #0; mov w8, #0x1fffffff]
uint64_t fde_sub_030fa8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x030FA8ULL;
}

// FDE #0241 | PC: 0x030fec..0x0311c8 (476 B) | Symbol: sub_030fec
// EN: AArch64 prologue [mov x3, x30; bl #0x69f4c; mov x30, x3; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x69f4c; mov x30, x3; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_030fec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400E3D7ULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x01DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x030FECULL;
}

// FDE #0242 | PC: 0x0311c8..0x031378 (432 B) | Symbol: sub_0311c8
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x50]!; mov x3, x30; bl #0x69fa8; mov x30, x3] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x50]!; mov x3, x30; bl #0x69fa8; mov x30, x3]
uint64_t fde_sub_0311c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E3ULL) << 32) | 0xA9BB6FFCULL;
    const uint64_t kPcRange = 0x01B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0311C8ULL;
}

// FDE #0243 | PC: 0x031378..0x031470 (248 B) | Symbol: sub_031378
// EN: AArch64 prologue [sxtw x12, w1; adrp x13, #0x9a000; adrp x15, #0x9a000; adrp x16, #0x9a000] | VI: Khởi đầu hàm AArch64 [sxtw x12, w1; adrp x13, #0x9a000; adrp x15, #0x9a000; adrp x16, #0x9a000]
uint64_t fde_sub_031378(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB000034DULL) << 32) | 0x93407C2CULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031378ULL;
}

// FDE #0244 | PC: 0x031470..0x031558 (232 B) | Symbol: sub_031470
// EN: AArch64 prologue [adrp x12, #0x9a000; adrp x14, #0x9a000; adrp x15, #0x9a000; ldr x12, [x12, #0x8f8]] | VI: Khởi đầu hàm AArch64 [adrp x12, #0x9a000; adrp x14, #0x9a000; adrp x15, #0x9a000; ldr x12, [x12, #0x8f8]]
uint64_t fde_sub_031470(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB000034EULL) << 32) | 0xB000034CULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031470ULL;
}

// FDE #0245 | PC: 0x031558..0x03160c (180 B) | Symbol: sub_031558
// EN: AArch64 prologue [adrp x14, #0x9a000; adrp x15, #0x9a000; ldr x14, [x14, #0x900]; ldr x15, [x15, #0x908]] | VI: Khởi đầu hàm AArch64 [adrp x14, #0x9a000; adrp x15, #0x9a000; ldr x14, [x14, #0x900]; ldr x15, [x15, #0x908]]
uint64_t fde_sub_031558(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB000034FULL) << 32) | 0xB000034EULL;
    const uint64_t kPcRange = 0x00B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031558ULL;
}

// FDE #0246 | PC: 0x03160c..0x03169c (144 B) | Symbol: sub_03160c
// EN: AArch64 prologue [adrp x12, #0x9a000; ldr x12, [x12, #0x908]; mov x10, xzr; mov w9, wzr] | VI: Khởi đầu hàm AArch64 [adrp x12, #0x9a000; ldr x12, [x12, #0x908]; mov x10, xzr; mov w9, wzr]
uint64_t fde_sub_03160c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF944858CULL) << 32) | 0xB000034CULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03160CULL;
}

// FDE #0247 | PC: 0x03169c..0x03178c (240 B) | Symbol: sub_03169c
// EN: AArch64 prologue [adrp x14, #0x9a000; ldr x14, [x14, #0x908]; mov x11, xzr; mov w9, wzr] | VI: Khởi đầu hàm AArch64 [adrp x14, #0x9a000; ldr x14, [x14, #0x908]; mov x11, xzr; mov w9, wzr]
uint64_t fde_sub_03169c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94485CEULL) << 32) | 0xB000034EULL;
    const uint64_t kPcRange = 0x00F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03169CULL;
}

// FDE #0248 | PC: 0x03178c..0x031c84 (1272 B) | Symbol: _Z21FDKaacEnc_countValuesPsii
// EN: AArch64 prologue [sub w9, w2, #1; cmp w9, #0xa; b.hi #0x317e4; adrp x10, #0x6c000] | VI: Khởi đầu hàm AArch64 [sub w9, w2, #1; cmp w9, #0xa; b.hi #0x317e4; adrp x10, #0x6c000]
uint64_t fde_sub_03178c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100293FULL) << 32) | 0x51000449ULL;
    const uint64_t kPcRange = 0x04F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03178CULL;
}

// FDE #0249 | PC: 0x031c84..0x0322bc (1592 B) | Symbol: _Z20FDKaacEnc_codeValuesPsiiP13FDK_BITSTREAM
// EN: AArch64 prologue [mov x4, x30; bl #0x69f18; mov x30, x4; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x4, x30; bl #0x69f18; mov x30, x4; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_031c84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400E0A4ULL) << 32) | 0xAA1E03E4ULL;
    const uint64_t kPcRange = 0x0638ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x031C84ULL;
}

// FDE #0250 | PC: 0x0322bc..0x032330 (116 B) | Symbol: sub_0322bc
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0322bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0322BCULL;
}

// FDE #0251 | PC: 0x032330..0x03237c (76 B) | Symbol: _Z30FDKaacEnc_codeScalefactorDeltaiP13FDK_BITSTREAM
// EN: AArch64 prologue [cmp w0, #0; cneg w8, w0, mi; cmp w8, #0x3c; b.le #0x32344] | VI: Khởi đầu hàm AArch64 [cmp w0, #0; cneg w8, w0, mi; cmp w8, #0x3c; b.le #0x32344]
uint64_t fde_sub_032330(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5A805408ULL) << 32) | 0x7100001FULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x032330ULL;
}

// FDE #0252 | PC: 0x03237c..0x0326c0 (836 B) | Symbol: _Z28FDKaacEnc_writeExtensionDataP12TRANSPORTENCP16QC_OUT_EXTENSIONijj17AUDIO_OBJECT_TYPEa
// EN: AArch64 prologue [mov x3, x30; bl #0x69f18; mov x30, x3; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x69f18; mov x30, x3; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_03237c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400DEE6ULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x0344ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03237CULL;
}

// FDE #0253 | PC: 0x0326c0..0x032730 (112 B) | Symbol: sub_0326c0
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0326c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0326C0ULL;
}

// FDE #0254 | PC: 0x032730..0x0328bc (396 B) | Symbol: sub_032730
// EN: AArch64 prologue [mov x4, x30; bl #0x6a250; mov x30, x4; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x4, x30; bl #0x6a250; mov x30, x4; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_032730(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400DEC7ULL) << 32) | 0xAA1E03E4ULL;
    const uint64_t kPcRange = 0x018CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x032730ULL;
}

// FDE #0255 | PC: 0x0328bc..0x033510 (3156 B) | Symbol: _Z29FDKaacEnc_ChannelElementWriteP12TRANSPORTENCP12ELEMENT_INFOPP14QC_OUT_CHANNELP15PSY_OUT_ELEMENTPP15PSY_OUT_CHANNELj17AUDIO_OBJECT_TYPEaPih
// EN: AArch64 prologue [sub sp, sp, #0x110; stp x28, x27, [sp, #0xb0]; stp x26, x25, [sp, #0xc0]; stp x24, x23, [sp, #0xd0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; stp x28, x27, [sp, #0xb0]; stp x26, x25, [sp, #0xc0]; stp x24, x23, [sp, #0xd0]]
uint64_t fde_sub_0328bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90B6FFCULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x0C54ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0328BCULL;
}

// FDE #0256 | PC: 0x033510..0x033908 (1016 B) | Symbol: _Z24FDKaacEnc_WriteBitstreamP12TRANSPORTENCP15CHANNEL_MAPPINGP6QC_OUTP7PSY_OUTP8QC_STATE17AUDIO_OBJECT_TYPEja
// EN: AArch64 prologue [sub sp, sp, #0xd0; stp x28, x27, [sp, #0x70]; stp x26, x25, [sp, #0x80]; stp x24, x23, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xd0; stp x28, x27, [sp, #0x70]; stp x26, x25, [sp, #0x80]; stp x24, x23, [sp, #0x90]]
uint64_t fde_sub_033510(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9076FFCULL) << 32) | 0xD10343FFULL;
    const uint64_t kPcRange = 0x03F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033510ULL;
}

// FDE #0257 | PC: 0x033908..0x033914 (12 B) | Symbol: sub_033908
// EN: AArch64 prologue [mov w2, w1; mov w1, wzr; b #0x322bc] | VI: Khởi đầu hàm AArch64 [mov w2, w1; mov w1, wzr; b #0x322bc]
uint64_t fde_sub_033908(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E1ULL) << 32) | 0x2A0103E2ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033908ULL;
}

// FDE #0258 | PC: 0x033914..0x033970 (92 B) | Symbol: _Z28FDKaacEnc_InitBlockSwitchingP23BLOCK_SWITCHING_CONTROLi
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w19, w1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w19, w1]
uint64_t fde_sub_033914(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033914ULL;
}

// FDE #0259 | PC: 0x033970..0x033c38 (712 B) | Symbol: _Z24FDKaacEnc_BlockSwitchingP23BLOCK_SWITCHING_CONTROLiiPKs
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_033970(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x02C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033970ULL;
}

// FDE #0260 | PC: 0x033c38..0x033ef4 (700 B) | Symbol: _Z28FDKaacEnc_SyncBlockSwitchingP23BLOCK_SWITCHING_CONTROLS0_ii
// EN: AArch64 prologue [cmp w2, #2; ccmp w3, #1, #0, eq; b.eq #0x33c50; ldr w10, [x0, #0x20]] | VI: Khởi đầu hàm AArch64 [cmp w2, #2; ccmp w3, #1, #0, eq; b.eq #0x33c50; ldr w10, [x0, #0x20]]
uint64_t fde_sub_033c38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7A410860ULL) << 32) | 0x7100085FULL;
    const uint64_t kPcRange = 0x02BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033C38ULL;
}

// FDE #0261 | PC: 0x033ef4..0x033f50 (92 B) | Symbol: _Z30FDKaacEnc_getChannelAssignment12CHANNEL_MODE13CHANNEL_ORDER
// EN: AArch64 prologue [adrp x8, #0x78000; adrp x9, #0x77000; add x8, x8, #0x2c; add x9, x9, #0xe24] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x78000; adrp x9, #0x77000; add x8, x8, #0x2c; add x9, x9, #0xe24]
uint64_t fde_sub_033ef4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000229ULL) << 32) | 0xB0000228ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033EF4ULL;
}

// FDE #0262 | PC: 0x033f50..0x033fdc (140 B) | Symbol: _Z30FDKaacEnc_DetermineEncoderModeP12CHANNEL_MODEi
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w19, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w19, [x0]]
uint64_t fde_sub_033f50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033F50ULL;
}

// FDE #0263 | PC: 0x033fdc..0x034014 (56 B) | Symbol: _Z37FDKaacEnc_GetChannelModeConfiguration12CHANNEL_MODE
// EN: AArch64 prologue [adrp x8, #0x78000; mov x9, xzr; add x8, x8, #0x3d4; add x10, x9, #0x10] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x78000; mov x9, xzr; add x8, x8, #0x3d4; add x10, x9, #0x10]
uint64_t fde_sub_033fdc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E9ULL) << 32) | 0xB0000228ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x033FDCULL;
}

// FDE #0264 | PC: 0x034014..0x0342a0 (652 B) | Symbol: _Z28FDKaacEnc_InitChannelMapping12CHANNEL_MODE13CHANNEL_ORDERP15CHANNEL_MAPPING
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_034014(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90357F6ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x028CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x034014ULL;
}

// FDE #0265 | PC: 0x0342a0..0x034374 (212 B) | Symbol: sub_0342a0
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0342a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0342A0ULL;
}

// FDE #0266 | PC: 0x034374..0x0347f8 (1156 B) | Symbol: _Z25FDKaacEnc_InitElementBitsP8QC_STATEP15CHANNEL_MAPPINGiii
// EN: AArch64 prologue [mov x8, x0; cbz w2, #0x3438c; eor w9, w2, w2, asr #31; clz w9, w9] | VI: Khởi đầu hàm AArch64 [mov x8, x0; cbz w2, #0x3438c; eor w9, w2, w2, asr #31; clz w9, w9]
uint64_t fde_sub_034374(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x340000A2ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0484ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x034374ULL;
}

// FDE #0267 | PC: 0x0347f8..0x034834 (60 B) | Symbol: _Z27FDKaacEnc_GetMonoStereoMode12CHANNEL_MODE
// EN: AArch64 prologue [cmp w0, #0x22; b.hi #0x34830; mov w8, w0; mov w9, #1] | VI: Khởi đầu hàm AArch64 [cmp w0, #0x22; b.hi #0x34830; mov w8, w0; mov w9, #1]
uint64_t fde_sub_0347f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x540001A8ULL) << 32) | 0x7100881FULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0347F8ULL;
}

// FDE #0268 | PC: 0x034834..0x034934 (256 B) | Symbol: _Z31FDKaacEnc_CalculateChaosMeasurePiiS_
// EN: AArch64 prologue [mov x3, x30; bl #0x69f4c; mov x30, x3; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x69f4c; mov x30, x3; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_034834(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400D5C5ULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x034834ULL;
}

// FDE #0269 | PC: 0x034934..0x0351d8 (2212 B) | Symbol: _Z21FDKaacEnc_dynBitCountP13BITCNTR_STATEPKsPKjPKiiiiiS6_P12SECTION_DATAS6_S6_S6_j
// EN: AArch64 prologue [sub sp, sp, #0x100; str d8, [sp, #0x90]; stp x28, x27, [sp, #0xa0]; stp x26, x25, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x100; str d8, [sp, #0x90]; stp x28, x27, [sp, #0xa0]; stp x26, x25, [sp, #0xb0]]
uint64_t fde_sub_034934(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD004BE8ULL) << 32) | 0xD10403FFULL;
    const uint64_t kPcRange = 0x08A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x034934ULL;
}

// FDE #0270 | PC: 0x0351d8..0x035208 (48 B) | Symbol: sub_0351d8
// EN: AArch64 prologue [mov x9, xzr; mov w8, #0x1fffffff; cmp x9, #0xc; b.eq #0x35204] | VI: Khởi đầu hàm AArch64 [mov x9, xzr; mov w8, #0x1fffffff; cmp x9, #0xc; b.eq #0x35204]
uint64_t fde_sub_0351d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12BC0008ULL) << 32) | 0xAA1F03E9ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0351D8ULL;
}

// FDE #0271 | PC: 0x035208..0x03523c (52 B) | Symbol: sub_035208
// EN: AArch64 prologue [mov x8, xzr; mov w9, #0x1fffffff; cmp x8, #0x30; b.eq #0x35238] | VI: Khởi đầu hàm AArch64 [mov x8, xzr; mov w9, #0x1fffffff; cmp x8, #0x30; b.eq #0x35238]
uint64_t fde_sub_035208(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12BC0009ULL) << 32) | 0xAA1F03E8ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x035208ULL;
}

// FDE #0272 | PC: 0x03523c..0x0352e0 (164 B) | Symbol: sub_03523c
// EN: AArch64 prologue [add x8, x0, w3, sxtw #4; add x9, x0, w4, sxtw #4; ldr w8, [x8, #8]; ldr w10, [x9, #8]] | VI: Khởi đầu hàm AArch64 [add x8, x0, w3, sxtw #4; add x9, x0, w4, sxtw #4; ldr w8, [x8, #8]; ldr w10, [x9, #8]]
uint64_t fde_sub_03523c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8B24D009ULL) << 32) | 0x8B23D008ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03523CULL;
}

// FDE #0273 | PC: 0x0352e0..0x035320 (64 B) | Symbol: _Z15FDKaacEnc_BCNewPP13BITCNTR_STATEPh
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x6a440] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; bl #0x6a440]
uint64_t fde_sub_0352e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0352E0ULL;
}

// FDE #0274 | PC: 0x035320..0x035330 (16 B) | Symbol: _Z17FDKaacEnc_BCClosePP13BITCNTR_STATE
// EN: AArch64 prologue [ldr x8, [x0]; cbz x8, #0x3532c; b #0x1b568; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; cbz x8, #0x3532c; b #0x1b568; ret]
uint64_t fde_sub_035320(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000048ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x035320ULL;
}

// FDE #0275 | PC: 0x035330..0x0357c4 (1172 B) | Symbol: _Z24FDKaacEnc_groupShortDataPiP13SFB_THRESHOLDP10SFB_ENERGYS3_S3_iiPKiS5_S_S_S_iS5_i
// EN: AArch64 prologue [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x69f18; mov x30, x8; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_035330(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400D2F9ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x0494ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x035330ULL;
}

// FDE #0276 | PC: 0x0357c4..0x036248 (2692 B) | Symbol: _Z35FDKaacEnc_IntensityStereoProcessingPiS_S_S_S_S_S_S_S_S_S_S_S_iiiPKiiS_S_PP8PNS_DATA
// EN: AArch64 prologue [mov x7, x30; bl #0x69f18; mov x30, x7; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x7, x30; bl #0x69f18; mov x30, x7; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_0357c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400D1D4ULL) << 32) | 0xAA1E03E7ULL;
    const uint64_t kPcRange = 0x0A84ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0357C4ULL;
}

// FDE #0277 | PC: 0x036248..0x036290 (72 B) | Symbol: sub_036248
// EN: AArch64 prologue [mov w8, wzr; sxtw x9, w1; sxtw x10, w2; cmp x9, x10] | VI: Khởi đầu hàm AArch64 [mov w8, wzr; sxtw x9, w1; sxtw x10, w2; cmp x9, x10]
uint64_t fde_sub_036248(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x93407C29ULL) << 32) | 0x2A1F03E8ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x036248ULL;
}

// FDE #0278 | PC: 0x036290..0x036384 (244 B) | Symbol: _Z22FDKaacEnc_prepareSfbPeP15PE_CHANNEL_DATAPKiS2_S2_S2_iii
// EN: AArch64 prologue [mov x8, x30; bl #0x6a084; mov x30, x8; stp x29, x30, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x6a084; mov x30, x8; stp x29, x30, [sp, #0x70]]
uint64_t fde_sub_036290(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400CF7CULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x00F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x036290ULL;
}

// FDE #0279 | PC: 0x036384..0x03653c (440 B) | Symbol: _Z19FDKaacEnc_calcSfbPeP15PE_CHANNEL_DATAPKiS2_iiiS2_S2_
// EN: AArch64 prologue [str x23, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; movi v0.2d, #0000000000000000] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x30]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; movi v0.2d, #0000000000000000]
uint64_t fde_sub_036384(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81D0FF7ULL;
    const uint64_t kPcRange = 0x01B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x036384ULL;
}

// FDE #0280 | PC: 0x03653c..0x0365b0 (116 B) | Symbol: _Z22FDK_DRC_Generator_OpenPP8DRC_COMP
// EN: AArch64 prologue [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_03653c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03653CULL;
}

// FDE #0281 | PC: 0x0365b0..0x0365e8 (56 B) | Symbol: _Z23FDK_DRC_Generator_ClosePP8DRC_COMP
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x365dc] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x365dc]
uint64_t fde_sub_0365b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0365B0ULL;
}

// FDE #0282 | PC: 0x0365e8..0x036800 (536 B) | Symbol: _Z28FDK_DRC_Generator_InitializeP8DRC_COMP11DRC_PROFILES1_ij12CHANNEL_MODE13CHANNEL_ORDERh
// EN: AArch64 prologue [sub sp, sp, #0x120; str x28, [sp, #0xe0]; stp x22, x21, [sp, #0xf0]; stp x20, x19, [sp, #0x100]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; str x28, [sp, #0xe0]; stp x22, x21, [sp, #0xf0]; stp x20, x19, [sp, #0x100]]
uint64_t fde_sub_0365e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90073FCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x0218ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0365E8ULL;
}

// FDE #0283 | PC: 0x036800..0x0369ac (428 B) | Symbol: _Z31FDK_DRC_Generator_setDrcProfileP8DRC_COMP11DRC_PROFILES1_
// EN: AArch64 prologue [mov x3, x30; bl #0x69f18; mov x30, x3; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x69f18; mov x30, x3; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_036800(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400CDC5ULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x01ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x036800ULL;
}

// FDE #0284 | PC: 0x0369ac..0x036a74 (200 B) | Symbol: sub_0369ac
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0369ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0369ACULL;
}

// FDE #0285 | PC: 0x036a74..0x037538 (2756 B) | Symbol: _Z22FDK_DRC_Generator_CalcP8DRC_COMPPKsiiiiiPiS3_
// EN: AArch64 prologue [mov x8, x30; bl #0x6a8c0; mov x30, x8; stp x29, x30, [sp, #0xd0]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x6a8c0; mov x30, x8; stp x29, x30, [sp, #0xd0]]
uint64_t fde_sub_036a74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400CF92ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x0AC4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x036A74ULL;
}

// FDE #0286 | PC: 0x037538..0x0375c4 (140 B) | Symbol: sub_037538
// EN: AArch64 prologue [ldr w8, [x2]; cmp w0, #0; ldr w10, [x3]; cneg w9, w0, mi] | VI: Khởi đầu hàm AArch64 [ldr w8, [x2]; cmp w0, #0; ldr w10, [x3]; cneg w9, w0, mi]
uint64_t fde_sub_037538(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100001FULL) << 32) | 0xB9400048ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x037538ULL;
}

// FDE #0287 | PC: 0x0375c4..0x0375cc (8 B) | Symbol: _Z31FDK_DRC_Generator_getDrcProfileP8DRC_COMP
// EN: AArch64 prologue [ldr w0, [x0, #0x90]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0x90]; ret]
uint64_t fde_sub_0375c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9409000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0375C4ULL;
}

// FDE #0288 | PC: 0x0375cc..0x0375d4 (8 B) | Symbol: _Z32FDK_DRC_Generator_getCompProfileP8DRC_COMP
// EN: AArch64 prologue [ldr w0, [x0, #0x94]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0x94]; ret]
uint64_t fde_sub_0375cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9409400ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0375CCULL;
}

// FDE #0289 | PC: 0x0375d4..0x037664 (144 B) | Symbol: _Z20FDK_MetadataEnc_OpenPP20FDK_METADATA_ENCODER
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0375d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0375D4ULL;
}

// FDE #0290 | PC: 0x037664..0x0376b0 (76 B) | Symbol: _Z21FDK_MetadataEnc_ClosePP20FDK_METADATA_ENCODER
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x3769c] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; cbz x0, #0x3769c]
uint64_t fde_sub_037664(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x037664ULL;
}

// FDE #0291 | PC: 0x0376b0..0x037830 (384 B) | Symbol: _Z20FDK_MetadataEnc_InitP20FDK_METADATA_ENCODERiiijjj12CHANNEL_MODE13CHANNEL_ORDER
// EN: AArch64 prologue [mov x8, x30; bl #0x69f4c; mov x30, x8; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x69f4c; mov x30, x8; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_0376b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400CA26ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x0180ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0376B0ULL;
}

// FDE #0292 | PC: 0x037830..0x037920 (240 B) | Symbol: sub_037830
// EN: AArch64 prologue [cbz x3, #0x378b0; stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [cbz x3, #0x378b0; stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]]
uint64_t fde_sub_037830(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BD57F6ULL) << 32) | 0xB4000403ULL;
    const uint64_t kPcRange = 0x00F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x037830ULL;
}

// FDE #0293 | PC: 0x037920..0x037ff8 (1752 B) | Symbol: _Z23FDK_MetadataEnc_ProcessP20FDK_METADATA_ENCODERPsiPK15AACENC_MetaDataPP18AACENC_EXT_PAYLOADPjPi
// EN: AArch64 prologue [sub sp, sp, #0xf0; str d8, [sp, #0x80]; stp x28, x27, [sp, #0x90]; stp x26, x25, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xf0; str d8, [sp, #0x80]; stp x28, x27, [sp, #0x90]; stp x26, x25, [sp, #0xa0]]
uint64_t fde_sub_037920(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0043E8ULL) << 32) | 0xD103C3FFULL;
    const uint64_t kPcRange = 0x06D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x037920ULL;
}

// FDE #0294 | PC: 0x037ff8..0x038004 (12 B) | Symbol: _Z24FDK_MetadataEnc_GetDelayP20FDK_METADATA_ENCODER
// EN: AArch64 prologue [cbz x0, #0x38000; ldr w0, [x0, #0x30]; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x38000; ldr w0, [x0, #0x30]; ret]
uint64_t fde_sub_037ff8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9403000ULL) << 32) | 0xB4000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x037FF8ULL;
}

uint64_t DispatchFdeShard1(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x01cd04ULL: return fde_sub_01cd04(a0, a1, a2);
        case 0x01cd10ULL: return fde_sub_01cd10(a0, a1, a2);
        case 0x01cd34ULL: return fde_sub_01cd34(a0, a1, a2);
        case 0x01cd3cULL: return fde_sub_01cd3c(a0, a1, a2);
        case 0x01cd48ULL: return fde_sub_01cd48(a0, a1, a2);
        case 0x01cd50ULL: return fde_sub_01cd50(a0, a1, a2);
        case 0x01cd58ULL: return fde_sub_01cd58(a0, a1, a2);
        case 0x01cd78ULL: return fde_sub_01cd78(a0, a1, a2);
        case 0x01cd80ULL: return fde_sub_01cd80(a0, a1, a2);
        case 0x01cd88ULL: return fde_sub_01cd88(a0, a1, a2);
        case 0x01cd90ULL: return fde_sub_01cd90(a0, a1, a2);
        case 0x01cd9cULL: return fde_sub_01cd9c(a0, a1, a2);
        case 0x01cda4ULL: return fde_sub_01cda4(a0, a1, a2);
        case 0x01cdacULL: return fde_sub_01cdac(a0, a1, a2);
        case 0x01cdccULL: return fde_sub_01cdcc(a0, a1, a2);
        case 0x01cdd4ULL: return fde_sub_01cdd4(a0, a1, a2);
        case 0x01cddcULL: return fde_sub_01cddc(a0, a1, a2);
        case 0x01cde0ULL: return fde_sub_01cde0(a0, a1, a2);
        case 0x01ce0cULL: return fde_sub_01ce0c(a0, a1, a2);
        case 0x01ce34ULL: return fde_sub_01ce34(a0, a1, a2);
        case 0x01cfb8ULL: return fde_sub_01cfb8(a0, a1, a2);
        case 0x01d1b8ULL: return fde_sub_01d1b8(a0, a1, a2);
        case 0x01d1d8ULL: return fde_sub_01d1d8(a0, a1, a2);
        case 0x01d254ULL: return fde_sub_01d254(a0, a1, a2);
        case 0x01d294ULL: return fde_sub_01d294(a0, a1, a2);
        case 0x01d790ULL: return fde_sub_01d790(a0, a1, a2);
        case 0x01d7a8ULL: return fde_sub_01d7a8(a0, a1, a2);
        case 0x01df00ULL: return fde_sub_01df00(a0, a1, a2);
        case 0x01df10ULL: return fde_sub_01df10(a0, a1, a2);
        case 0x01df60ULL: return fde_sub_01df60(a0, a1, a2);
        case 0x01dfbcULL: return fde_sub_01dfbc(a0, a1, a2);
        case 0x01dfd4ULL: return fde_sub_01dfd4(a0, a1, a2);
        case 0x01e004ULL: return fde_sub_01e004(a0, a1, a2);
        case 0x01e110ULL: return fde_sub_01e110(a0, a1, a2);
        case 0x01e118ULL: return fde_sub_01e118(a0, a1, a2);
        case 0x01e188ULL: return fde_sub_01e188(a0, a1, a2);
        case 0x01e460ULL: return fde_sub_01e460(a0, a1, a2);
        case 0x01e480ULL: return fde_sub_01e480(a0, a1, a2);
        case 0x01e4b8ULL: return fde_sub_01e4b8(a0, a1, a2);
        case 0x01f078ULL: return fde_sub_01f078(a0, a1, a2);
        case 0x01f0f4ULL: return fde_sub_01f0f4(a0, a1, a2);
        case 0x01f134ULL: return fde_sub_01f134(a0, a1, a2);
        case 0x01f210ULL: return fde_sub_01f210(a0, a1, a2);
        case 0x01f2acULL: return fde_sub_01f2ac(a0, a1, a2);
        case 0x01f334ULL: return fde_sub_01f334(a0, a1, a2);
        case 0x01f354ULL: return fde_sub_01f354(a0, a1, a2);
        case 0x01f380ULL: return fde_sub_01f380(a0, a1, a2);
        case 0x01f390ULL: return fde_sub_01f390(a0, a1, a2);
        case 0x01f39cULL: return fde_sub_01f39c(a0, a1, a2);
        case 0x01f438ULL: return fde_sub_01f438(a0, a1, a2);
        case 0x01f970ULL: return fde_sub_01f970(a0, a1, a2);
        case 0x01fad4ULL: return fde_sub_01fad4(a0, a1, a2);
        case 0x01fc84ULL: return fde_sub_01fc84(a0, a1, a2);
        case 0x01fdf4ULL: return fde_sub_01fdf4(a0, a1, a2);
        case 0x01ffa0ULL: return fde_sub_01ffa0(a0, a1, a2);
        case 0x0201bcULL: return fde_sub_0201bc(a0, a1, a2);
        case 0x0202e0ULL: return fde_sub_0202e0(a0, a1, a2);
        case 0x0204b8ULL: return fde_sub_0204b8(a0, a1, a2);
        case 0x0204f4ULL: return fde_sub_0204f4(a0, a1, a2);
        case 0x020500ULL: return fde_sub_020500(a0, a1, a2);
        case 0x020514ULL: return fde_sub_020514(a0, a1, a2);
        case 0x020530ULL: return fde_sub_020530(a0, a1, a2);
        case 0x0205b8ULL: return fde_sub_0205b8(a0, a1, a2);
        case 0x020604ULL: return fde_sub_020604(a0, a1, a2);
        case 0x0208c8ULL: return fde_sub_0208c8(a0, a1, a2);
        case 0x0208f0ULL: return fde_sub_0208f0(a0, a1, a2);
        case 0x020914ULL: return fde_sub_020914(a0, a1, a2);
        case 0x020b48ULL: return fde_sub_020b48(a0, a1, a2);
        case 0x0211dcULL: return fde_sub_0211dc(a0, a1, a2);
        case 0x0212f8ULL: return fde_sub_0212f8(a0, a1, a2);
        case 0x0212fcULL: return fde_sub_0212fc(a0, a1, a2);
        case 0x021328ULL: return fde_sub_021328(a0, a1, a2);
        case 0x02134cULL: return fde_sub_02134c(a0, a1, a2);
        case 0x02138cULL: return fde_sub_02138c(a0, a1, a2);
        case 0x021484ULL: return fde_sub_021484(a0, a1, a2);
        case 0x02153cULL: return fde_sub_02153c(a0, a1, a2);
        case 0x021b18ULL: return fde_sub_021b18(a0, a1, a2);
        case 0x0228b4ULL: return fde_sub_0228b4(a0, a1, a2);
        case 0x022910ULL: return fde_sub_022910(a0, a1, a2);
        case 0x0229e0ULL: return fde_sub_0229e0(a0, a1, a2);
        case 0x022ce8ULL: return fde_sub_022ce8(a0, a1, a2);
        case 0x022cecULL: return fde_sub_022cec(a0, a1, a2);
        case 0x022d20ULL: return fde_sub_022d20(a0, a1, a2);
        case 0x022db8ULL: return fde_sub_022db8(a0, a1, a2);
        case 0x022dc4ULL: return fde_sub_022dc4(a0, a1, a2);
        case 0x022de4ULL: return fde_sub_022de4(a0, a1, a2);
        case 0x023000ULL: return fde_sub_023000(a0, a1, a2);
        case 0x023138ULL: return fde_sub_023138(a0, a1, a2);
        case 0x02326cULL: return fde_sub_02326c(a0, a1, a2);
        case 0x0232e4ULL: return fde_sub_0232e4(a0, a1, a2);
        case 0x023350ULL: return fde_sub_023350(a0, a1, a2);
        case 0x0233b4ULL: return fde_sub_0233b4(a0, a1, a2);
        case 0x023900ULL: return fde_sub_023900(a0, a1, a2);
        case 0x023914ULL: return fde_sub_023914(a0, a1, a2);
        case 0x0239b0ULL: return fde_sub_0239b0(a0, a1, a2);
        case 0x023a58ULL: return fde_sub_023a58(a0, a1, a2);
        case 0x023b70ULL: return fde_sub_023b70(a0, a1, a2);
        case 0x023c9cULL: return fde_sub_023c9c(a0, a1, a2);
        case 0x023e9cULL: return fde_sub_023e9c(a0, a1, a2);
        case 0x024134ULL: return fde_sub_024134(a0, a1, a2);
        case 0x024478ULL: return fde_sub_024478(a0, a1, a2);
        case 0x0244f4ULL: return fde_sub_0244f4(a0, a1, a2);
        case 0x02464cULL: return fde_sub_02464c(a0, a1, a2);
        case 0x02466cULL: return fde_sub_02466c(a0, a1, a2);
        case 0x024858ULL: return fde_sub_024858(a0, a1, a2);
        case 0x0248d0ULL: return fde_sub_0248d0(a0, a1, a2);
        case 0x024c88ULL: return fde_sub_024c88(a0, a1, a2);
        case 0x024ce0ULL: return fde_sub_024ce0(a0, a1, a2);
        case 0x024e50ULL: return fde_sub_024e50(a0, a1, a2);
        case 0x024ee0ULL: return fde_sub_024ee0(a0, a1, a2);
        case 0x024f38ULL: return fde_sub_024f38(a0, a1, a2);
        case 0x024f48ULL: return fde_sub_024f48(a0, a1, a2);
        case 0x024fb0ULL: return fde_sub_024fb0(a0, a1, a2);
        case 0x02505cULL: return fde_sub_02505c(a0, a1, a2);
        case 0x025160ULL: return fde_sub_025160(a0, a1, a2);
        case 0x02516cULL: return fde_sub_02516c(a0, a1, a2);
        case 0x0252a0ULL: return fde_sub_0252a0(a0, a1, a2);
        case 0x0252b8ULL: return fde_sub_0252b8(a0, a1, a2);
        case 0x025c30ULL: return fde_sub_025c30(a0, a1, a2);
        case 0x025ce0ULL: return fde_sub_025ce0(a0, a1, a2);
        case 0x025d44ULL: return fde_sub_025d44(a0, a1, a2);
        case 0x025e2cULL: return fde_sub_025e2c(a0, a1, a2);
        case 0x025ff0ULL: return fde_sub_025ff0(a0, a1, a2);
        case 0x0260acULL: return fde_sub_0260ac(a0, a1, a2);
        case 0x026138ULL: return fde_sub_026138(a0, a1, a2);
        case 0x026150ULL: return fde_sub_026150(a0, a1, a2);
        case 0x026520ULL: return fde_sub_026520(a0, a1, a2);
        case 0x02660cULL: return fde_sub_02660c(a0, a1, a2);
        case 0x0266c4ULL: return fde_sub_0266c4(a0, a1, a2);
        case 0x02678cULL: return fde_sub_02678c(a0, a1, a2);
        case 0x0267d8ULL: return fde_sub_0267d8(a0, a1, a2);
        case 0x026824ULL: return fde_sub_026824(a0, a1, a2);
        case 0x0268ecULL: return fde_sub_0268ec(a0, a1, a2);
        case 0x026a20ULL: return fde_sub_026a20(a0, a1, a2);
        case 0x0277a0ULL: return fde_sub_0277a0(a0, a1, a2);
        case 0x027878ULL: return fde_sub_027878(a0, a1, a2);
        case 0x0278e4ULL: return fde_sub_0278e4(a0, a1, a2);
        case 0x027d00ULL: return fde_sub_027d00(a0, a1, a2);
        case 0x027fd4ULL: return fde_sub_027fd4(a0, a1, a2);
        case 0x028168ULL: return fde_sub_028168(a0, a1, a2);
        case 0x02826cULL: return fde_sub_02826c(a0, a1, a2);
        case 0x028338ULL: return fde_sub_028338(a0, a1, a2);
        case 0x02849cULL: return fde_sub_02849c(a0, a1, a2);
        case 0x02860cULL: return fde_sub_02860c(a0, a1, a2);
        case 0x028618ULL: return fde_sub_028618(a0, a1, a2);
        case 0x028624ULL: return fde_sub_028624(a0, a1, a2);
        case 0x028630ULL: return fde_sub_028630(a0, a1, a2);
        case 0x028638ULL: return fde_sub_028638(a0, a1, a2);
        case 0x02863cULL: return fde_sub_02863c(a0, a1, a2);
        case 0x028644ULL: return fde_sub_028644(a0, a1, a2);
        case 0x028650ULL: return fde_sub_028650(a0, a1, a2);
        case 0x028658ULL: return fde_sub_028658(a0, a1, a2);
        case 0x028664ULL: return fde_sub_028664(a0, a1, a2);
        case 0x02866cULL: return fde_sub_02866c(a0, a1, a2);
        case 0x028678ULL: return fde_sub_028678(a0, a1, a2);
        case 0x028680ULL: return fde_sub_028680(a0, a1, a2);
        case 0x028694ULL: return fde_sub_028694(a0, a1, a2);
        case 0x02869cULL: return fde_sub_02869c(a0, a1, a2);
        case 0x0286a0ULL: return fde_sub_0286a0(a0, a1, a2);
        case 0x0286acULL: return fde_sub_0286ac(a0, a1, a2);
        case 0x0286b8ULL: return fde_sub_0286b8(a0, a1, a2);
        case 0x0286c0ULL: return fde_sub_0286c0(a0, a1, a2);
        case 0x0286ccULL: return fde_sub_0286cc(a0, a1, a2);
        case 0x0286d4ULL: return fde_sub_0286d4(a0, a1, a2);
        case 0x0286e0ULL: return fde_sub_0286e0(a0, a1, a2);
        case 0x0286e8ULL: return fde_sub_0286e8(a0, a1, a2);
        case 0x0286f4ULL: return fde_sub_0286f4(a0, a1, a2);
        case 0x0286fcULL: return fde_sub_0286fc(a0, a1, a2);
        case 0x028708ULL: return fde_sub_028708(a0, a1, a2);
        case 0x028710ULL: return fde_sub_028710(a0, a1, a2);
        case 0x02871cULL: return fde_sub_02871c(a0, a1, a2);
        case 0x028724ULL: return fde_sub_028724(a0, a1, a2);
        case 0x02872cULL: return fde_sub_02872c(a0, a1, a2);
        case 0x028734ULL: return fde_sub_028734(a0, a1, a2);
        case 0x02873cULL: return fde_sub_02873c(a0, a1, a2);
        case 0x028748ULL: return fde_sub_028748(a0, a1, a2);
        case 0x028750ULL: return fde_sub_028750(a0, a1, a2);
        case 0x02875cULL: return fde_sub_02875c(a0, a1, a2);
        case 0x028764ULL: return fde_sub_028764(a0, a1, a2);
        case 0x028770ULL: return fde_sub_028770(a0, a1, a2);
        case 0x0287a0ULL: return fde_sub_0287a0(a0, a1, a2);
        case 0x0287d0ULL: return fde_sub_0287d0(a0, a1, a2);
        case 0x0288a8ULL: return fde_sub_0288a8(a0, a1, a2);
        case 0x028910ULL: return fde_sub_028910(a0, a1, a2);
        case 0x028970ULL: return fde_sub_028970(a0, a1, a2);
        case 0x028a40ULL: return fde_sub_028a40(a0, a1, a2);
        case 0x02907cULL: return fde_sub_02907c(a0, a1, a2);
        case 0x029578ULL: return fde_sub_029578(a0, a1, a2);
        case 0x0295d0ULL: return fde_sub_0295d0(a0, a1, a2);
        case 0x0295dcULL: return fde_sub_0295dc(a0, a1, a2);
        case 0x0295e4ULL: return fde_sub_0295e4(a0, a1, a2);
        case 0x0296c0ULL: return fde_sub_0296c0(a0, a1, a2);
        case 0x029944ULL: return fde_sub_029944(a0, a1, a2);
        case 0x029968ULL: return fde_sub_029968(a0, a1, a2);
        case 0x0299f8ULL: return fde_sub_0299f8(a0, a1, a2);
        case 0x02ab40ULL: return fde_sub_02ab40(a0, a1, a2);
        case 0x02ab6cULL: return fde_sub_02ab6c(a0, a1, a2);
        case 0x02abd8ULL: return fde_sub_02abd8(a0, a1, a2);
        case 0x02ac7cULL: return fde_sub_02ac7c(a0, a1, a2);
        case 0x02acb0ULL: return fde_sub_02acb0(a0, a1, a2);
        case 0x02acfcULL: return fde_sub_02acfc(a0, a1, a2);
        case 0x02ada0ULL: return fde_sub_02ada0(a0, a1, a2);
        case 0x02b270ULL: return fde_sub_02b270(a0, a1, a2);
        case 0x02b408ULL: return fde_sub_02b408(a0, a1, a2);
        case 0x02b540ULL: return fde_sub_02b540(a0, a1, a2);
        case 0x02b588ULL: return fde_sub_02b588(a0, a1, a2);
        case 0x02b824ULL: return fde_sub_02b824(a0, a1, a2);
        case 0x02b8e8ULL: return fde_sub_02b8e8(a0, a1, a2);
        case 0x02b9b8ULL: return fde_sub_02b9b8(a0, a1, a2);
        case 0x02ba58ULL: return fde_sub_02ba58(a0, a1, a2);
        case 0x02bac4ULL: return fde_sub_02bac4(a0, a1, a2);
        case 0x02bdc4ULL: return fde_sub_02bdc4(a0, a1, a2);
        case 0x02beacULL: return fde_sub_02beac(a0, a1, a2);
        case 0x02c838ULL: return fde_sub_02c838(a0, a1, a2);
        case 0x02c89cULL: return fde_sub_02c89c(a0, a1, a2);
        case 0x02c91cULL: return fde_sub_02c91c(a0, a1, a2);
        case 0x02c9b0ULL: return fde_sub_02c9b0(a0, a1, a2);
        case 0x02cb14ULL: return fde_sub_02cb14(a0, a1, a2);
        case 0x02cba4ULL: return fde_sub_02cba4(a0, a1, a2);
        case 0x02ccc8ULL: return fde_sub_02ccc8(a0, a1, a2);
        case 0x02d000ULL: return fde_sub_02d000(a0, a1, a2);
        case 0x02d418ULL: return fde_sub_02d418(a0, a1, a2);
        case 0x02d4c0ULL: return fde_sub_02d4c0(a0, a1, a2);
        case 0x02d6d0ULL: return fde_sub_02d6d0(a0, a1, a2);
        case 0x02dd78ULL: return fde_sub_02dd78(a0, a1, a2);
        case 0x02de08ULL: return fde_sub_02de08(a0, a1, a2);
        case 0x02df9cULL: return fde_sub_02df9c(a0, a1, a2);
        case 0x02e450ULL: return fde_sub_02e450(a0, a1, a2);
        case 0x02e4b4ULL: return fde_sub_02e4b4(a0, a1, a2);
        case 0x02e7ccULL: return fde_sub_02e7cc(a0, a1, a2);
        case 0x02ef74ULL: return fde_sub_02ef74(a0, a1, a2);
        case 0x030408ULL: return fde_sub_030408(a0, a1, a2);
        case 0x03045cULL: return fde_sub_03045c(a0, a1, a2);
        case 0x030650ULL: return fde_sub_030650(a0, a1, a2);
        case 0x0306b0ULL: return fde_sub_0306b0(a0, a1, a2);
        case 0x030718ULL: return fde_sub_030718(a0, a1, a2);
        case 0x030840ULL: return fde_sub_030840(a0, a1, a2);
        case 0x030a24ULL: return fde_sub_030a24(a0, a1, a2);
        case 0x030afcULL: return fde_sub_030afc(a0, a1, a2);
        case 0x030cc4ULL: return fde_sub_030cc4(a0, a1, a2);
        case 0x030fa8ULL: return fde_sub_030fa8(a0, a1, a2);
        case 0x030fecULL: return fde_sub_030fec(a0, a1, a2);
        case 0x0311c8ULL: return fde_sub_0311c8(a0, a1, a2);
        case 0x031378ULL: return fde_sub_031378(a0, a1, a2);
        case 0x031470ULL: return fde_sub_031470(a0, a1, a2);
        case 0x031558ULL: return fde_sub_031558(a0, a1, a2);
        case 0x03160cULL: return fde_sub_03160c(a0, a1, a2);
        case 0x03169cULL: return fde_sub_03169c(a0, a1, a2);
        case 0x03178cULL: return fde_sub_03178c(a0, a1, a2);
        case 0x031c84ULL: return fde_sub_031c84(a0, a1, a2);
        case 0x0322bcULL: return fde_sub_0322bc(a0, a1, a2);
        case 0x032330ULL: return fde_sub_032330(a0, a1, a2);
        case 0x03237cULL: return fde_sub_03237c(a0, a1, a2);
        case 0x0326c0ULL: return fde_sub_0326c0(a0, a1, a2);
        case 0x032730ULL: return fde_sub_032730(a0, a1, a2);
        case 0x0328bcULL: return fde_sub_0328bc(a0, a1, a2);
        case 0x033510ULL: return fde_sub_033510(a0, a1, a2);
        case 0x033908ULL: return fde_sub_033908(a0, a1, a2);
        case 0x033914ULL: return fde_sub_033914(a0, a1, a2);
        case 0x033970ULL: return fde_sub_033970(a0, a1, a2);
        case 0x033c38ULL: return fde_sub_033c38(a0, a1, a2);
        case 0x033ef4ULL: return fde_sub_033ef4(a0, a1, a2);
        case 0x033f50ULL: return fde_sub_033f50(a0, a1, a2);
        case 0x033fdcULL: return fde_sub_033fdc(a0, a1, a2);
        case 0x034014ULL: return fde_sub_034014(a0, a1, a2);
        case 0x0342a0ULL: return fde_sub_0342a0(a0, a1, a2);
        case 0x034374ULL: return fde_sub_034374(a0, a1, a2);
        case 0x0347f8ULL: return fde_sub_0347f8(a0, a1, a2);
        case 0x034834ULL: return fde_sub_034834(a0, a1, a2);
        case 0x034934ULL: return fde_sub_034934(a0, a1, a2);
        case 0x0351d8ULL: return fde_sub_0351d8(a0, a1, a2);
        case 0x035208ULL: return fde_sub_035208(a0, a1, a2);
        case 0x03523cULL: return fde_sub_03523c(a0, a1, a2);
        case 0x0352e0ULL: return fde_sub_0352e0(a0, a1, a2);
        case 0x035320ULL: return fde_sub_035320(a0, a1, a2);
        case 0x035330ULL: return fde_sub_035330(a0, a1, a2);
        case 0x0357c4ULL: return fde_sub_0357c4(a0, a1, a2);
        case 0x036248ULL: return fde_sub_036248(a0, a1, a2);
        case 0x036290ULL: return fde_sub_036290(a0, a1, a2);
        case 0x036384ULL: return fde_sub_036384(a0, a1, a2);
        case 0x03653cULL: return fde_sub_03653c(a0, a1, a2);
        case 0x0365b0ULL: return fde_sub_0365b0(a0, a1, a2);
        case 0x0365e8ULL: return fde_sub_0365e8(a0, a1, a2);
        case 0x036800ULL: return fde_sub_036800(a0, a1, a2);
        case 0x0369acULL: return fde_sub_0369ac(a0, a1, a2);
        case 0x036a74ULL: return fde_sub_036a74(a0, a1, a2);
        case 0x037538ULL: return fde_sub_037538(a0, a1, a2);
        case 0x0375c4ULL: return fde_sub_0375c4(a0, a1, a2);
        case 0x0375ccULL: return fde_sub_0375cc(a0, a1, a2);
        case 0x0375d4ULL: return fde_sub_0375d4(a0, a1, a2);
        case 0x037664ULL: return fde_sub_037664(a0, a1, a2);
        case 0x0376b0ULL: return fde_sub_0376b0(a0, a1, a2);
        case 0x037830ULL: return fde_sub_037830(a0, a1, a2);
        case 0x037920ULL: return fde_sub_037920(a0, a1, a2);
        case 0x037ff8ULL: return fde_sub_037ff8(a0, a1, a2);
        default: return 0ULL;
    }
}

} // namespace fdk_aac
} // namespace opencut
