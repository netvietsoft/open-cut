// ============================================================================
// File: fdk_aac_fde_shard_5.cpp
// Target 105 / 169: libfdk-aac.so (625,312 bytes)
// EN: Clean-room C++17 AArch64 FDE Shard 5/5 covering FDEs [1180..1470]
//     (PC range 0x06b760 .. 0x06c8a8).
// VI: Phân mảnh FDE AArch64 C++17 5/5 bao phủ các FDE [1180..1470]
//     (Dải địa chỉ PC 0x06b760 .. 0x06c8a8).
// ============================================================================
#include "fdk_aac_codec_core.h"

namespace opencut {
namespace fdk_aac {

// FDE #1180 | PC: 0x06b760..0x06b778 (24 B) | Symbol: sub_06b760
// EN: AArch64 prologue [ldr x0, [sp, #0x68]; ldr w1, [sp, #0x54]; sub x6, x29, #0x5c; mov x2, x28] | VI: Khởi đầu hàm AArch64 [ldr x0, [sp, #0x68]; ldr w1, [sp, #0x54]; sub x6, x29, #0x5c; mov x2, x28]
uint64_t fde_sub_06b760(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB94057E1ULL) << 32) | 0xF94037E0ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B760ULL;
}

// FDE #1181 | PC: 0x06b778..0x06b788 (16 B) | Symbol: sub_06b778
// EN: AArch64 prologue [mov w2, #4; mov x0, x19; mov w1, w22; b #0x322bc] | VI: Khởi đầu hàm AArch64 [mov w2, #4; mov x0, x19; mov w1, w22; b #0x322bc]
uint64_t fde_sub_06b778(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x52800082ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B778ULL;
}

// FDE #1182 | PC: 0x06b788..0x06b790 (8 B) | Symbol: sub_06b788
// EN: AArch64 prologue [mov x0, x26; b #0x1d1b8] | VI: Khởi đầu hàm AArch64 [mov x0, x26; b #0x1d1b8]
uint64_t fde_sub_06b788(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC68BULL) << 32) | 0xAA1A03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B788ULL;
}

// FDE #1183 | PC: 0x06b790..0x06b79c (12 B) | Symbol: sub_06b790
// EN: AArch64 prologue [mov x22, x4; mov x23, x3; ret] | VI: Khởi đầu hàm AArch64 [mov x22, x4; mov x23, x3; ret]
uint64_t fde_sub_06b790(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0303F7ULL) << 32) | 0xAA0403F6ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B790ULL;
}

// FDE #1184 | PC: 0x06b79c..0x06b7b4 (24 B) | Symbol: sub_06b79c
// EN: AArch64 prologue [ldp x0, x2, [x29, #-0x78]; ldr x1, [sp, #0x88]; ldur x3, [x29, #-0x80]; ldp x5, x4, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [ldp x0, x2, [x29, #-0x78]; ldr x1, [sp, #0x88]; ldur x3, [x29, #-0x80]; ldp x5, x4, [sp, #0x70]]
uint64_t fde_sub_06b79c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94047E1ULL) << 32) | 0xA9788BA0ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B79CULL;
}

// FDE #1185 | PC: 0x06b7b4..0x06b7c0 (12 B) | Symbol: sub_06b7b4
// EN: AArch64 prologue [add x29, sp, #0x50; sub sp, sp, #1, lsl #12; ret] | VI: Khởi đầu hàm AArch64 [add x29, sp, #0x50; sub sp, sp, #1, lsl #12; ret]
uint64_t fde_sub_06b7b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD14007FFULL) << 32) | 0x910143FDULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B7B4ULL;
}

// FDE #1186 | PC: 0x06b7c0..0x06b7d0 (16 B) | Symbol: sub_06b7c0
// EN: AArch64 prologue [mov x2, xzr; mov w3, w19; mov w5, wzr; b #0x1c718] | VI: Khởi đầu hàm AArch64 [mov x2, xzr; mov w3, w19; mov w5, wzr; b #0x1c718]
uint64_t fde_sub_06b7c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1303E3ULL) << 32) | 0xAA1F03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B7C0ULL;
}

// FDE #1187 | PC: 0x06b7d0..0x06b7d8 (8 B) | Symbol: sub_06b7d0
// EN: AArch64 prologue [mov w0, #1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #1; ret]
uint64_t fde_sub_06b7d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B7D0ULL;
}

// FDE #1188 | PC: 0x06b7d8..0x06b7f0 (24 B) | Symbol: sub_06b7d8
// EN: AArch64 prologue [mov w6, #0x1267; mov x0, x21; mov x4, x14; str w9, [sp, #8]] | VI: Khởi đầu hàm AArch64 [mov w6, #0x1267; mov x0, x21; mov x4, x14; str w9, [sp, #8]]
uint64_t fde_sub_06b7d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E0ULL) << 32) | 0x52824CE6ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B7D8ULL;
}

// FDE #1189 | PC: 0x06b7f0..0x06b800 (16 B) | Symbol: sub_06b7f0
// EN: AArch64 prologue [mov w1, w26; mov w2, w27; add x0, x8, x19, lsl #2; b #0x2660c] | VI: Khởi đầu hàm AArch64 [mov w1, w26; mov w2, w27; add x0, x8, x19, lsl #2; b #0x2660c]
uint64_t fde_sub_06b7f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1B03E2ULL) << 32) | 0x2A1A03E1ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B7F0ULL;
}

// FDE #1190 | PC: 0x06b800..0x06b818 (24 B) | Symbol: sub_06b800
// EN: AArch64 prologue [ldr x27, [x27, #0x900]; mov x23, xzr; sxtw x24, w1; mov w26, #0x1a] | VI: Khởi đầu hàm AArch64 [ldr x27, [x27, #0x900]; mov x23, xzr; sxtw x24, w1; mov w26, #0x1a]
uint64_t fde_sub_06b800(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03F7ULL) << 32) | 0xF944837BULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B800ULL;
}

// FDE #1191 | PC: 0x06b818..0x06b830 (24 B) | Symbol: sub_06b818
// EN: AArch64 prologue [ldr x26, [x26, #0x8e8]; mov x21, xzr; sxtw x22, w1; mov w23, #0x12] | VI: Khởi đầu hàm AArch64 [ldr x26, [x26, #0x8e8]; mov x21, xzr; sxtw x22, w1; mov w23, #0x12]
uint64_t fde_sub_06b818(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03F5ULL) << 32) | 0xF944775AULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B818ULL;
}

// FDE #1192 | PC: 0x06b830..0x06b848 (24 B) | Symbol: sub_06b830
// EN: AArch64 prologue [ldr w8, [sp, #0xc]; neg w10, w8; lsl w9, w0, w8; cmp w8, #0] | VI: Khởi đầu hàm AArch64 [ldr w8, [sp, #0xc]; neg w10, w8; lsl w9, w0, w8; cmp w8, #0]
uint64_t fde_sub_06b830(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4B0803EAULL) << 32) | 0xB9400FE8ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B830ULL;
}

// FDE #1193 | PC: 0x06b848..0x06b860 (24 B) | Symbol: sub_06b848
// EN: AArch64 prologue [ldr w3, [x19, #0x2a8]; ldr w5, [x19, #0x44]; ldr w6, [x19, #0x2b4]; ldrb w8, [x19, #0x2cc]] | VI: Khởi đầu hàm AArch64 [ldr w3, [x19, #0x2a8]; ldr w5, [x19, #0x44]; ldr w6, [x19, #0x2b4]; ldrb w8, [x19, #0x2cc]]
uint64_t fde_sub_06b848(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9404665ULL) << 32) | 0xB942AA63ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B848ULL;
}

// FDE #1194 | PC: 0x06b860..0x06b878 (24 B) | Symbol: sub_06b860
// EN: AArch64 prologue [sub w9, w8, #0xa; sub w8, w20, w8; lsl w10, w0, w9; asr w8, w0, w8] | VI: Khởi đầu hàm AArch64 [sub w9, w8, #0xa; sub w8, w20, w8; lsl w10, w0, w9; asr w8, w0, w8]
uint64_t fde_sub_06b860(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4B080288ULL) << 32) | 0x51002909ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B860ULL;
}

// FDE #1195 | PC: 0x06b878..0x06b880 (8 B) | Symbol: sub_06b878
// EN: AArch64 prologue [ldp w2, w1, [x19, #0x98]; b #0x369ac] | VI: Khởi đầu hàm AArch64 [ldp w2, w1, [x19, #0x98]; b #0x369ac]
uint64_t fde_sub_06b878(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF2C4CULL) << 32) | 0x29530662ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B878ULL;
}

// FDE #1196 | PC: 0x06b880..0x06b898 (24 B) | Symbol: sub_06b880
// EN: AArch64 prologue [asr w9, w9, #1; asr w12, w10, #1; sub w8, w9, w8; sub w9, w12, w11] | VI: Khởi đầu hàm AArch64 [asr w9, w9, #1; asr w12, w10, #1; sub w8, w9, w8; sub w9, w12, w11]
uint64_t fde_sub_06b880(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x13017D4CULL) << 32) | 0x13017D29ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B880ULL;
}

// FDE #1197 | PC: 0x06b898..0x06b8c0 (40 B) | Symbol: sub_06b898
// EN: AArch64 prologue [add x15, x8, x9, lsl #1; ldrsh x16, [x15]; ldrsh x17, [x15, #2]; ldrsh x1, [x15, #4]] | VI: Khởi đầu hàm AArch64 [add x15, x8, x9, lsl #1; ldrsh x16, [x15]; ldrsh x17, [x15, #2]; ldrsh x1, [x15, #4]]
uint64_t fde_sub_06b898(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x798001F0ULL) << 32) | 0x8B09050FULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B898ULL;
}

// FDE #1198 | PC: 0x06b8c0..0x06b8d0 (16 B) | Symbol: sub_06b8c0
// EN: AArch64 prologue [ldur w8, [x29, #-0x60]; ldur w9, [x29, #-0x80]; cmp w8, w9; ret] | VI: Khởi đầu hàm AArch64 [ldur w8, [x29, #-0x60]; ldur w9, [x29, #-0x80]; cmp w8, w9; ret]
uint64_t fde_sub_06b8c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB85803A9ULL) << 32) | 0xB85A03A8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B8C0ULL;
}

// FDE #1199 | PC: 0x06b8d0..0x06b8e0 (16 B) | Symbol: sub_06b8d0
// EN: AArch64 prologue [ldp x2, x1, [x29, #-0x70]; sub x5, x29, #0x60; mov x3, x22; ret] | VI: Khởi đầu hàm AArch64 [ldp x2, x1, [x29, #-0x70]; sub x5, x29, #0x60; mov x3, x22; ret]
uint64_t fde_sub_06b8d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183A5ULL) << 32) | 0xA97907A2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B8D0ULL;
}

// FDE #1200 | PC: 0x06b8e0..0x06b8f0 (16 B) | Symbol: sub_06b8e0
// EN: AArch64 prologue [add x11, sp, #0x48; mov w12, #1; add x13, sp, #0x38; ret] | VI: Khởi đầu hàm AArch64 [add x11, sp, #0x48; mov w12, #1; add x13, sp, #0x38; ret]
uint64_t fde_sub_06b8e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5280002CULL) << 32) | 0x910123EBULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B8E0ULL;
}

// FDE #1201 | PC: 0x06b8f0..0x06b908 (24 B) | Symbol: sub_06b8f0
// EN: AArch64 prologue [ldrsw x8, [x21, x25, lsl #2]; ldr x13, [sp, #0x98]; mvn w9, w20; sxtw x10, w0] | VI: Khởi đầu hàm AArch64 [ldrsw x8, [x21, x25, lsl #2]; ldr x13, [sp, #0x98]; mvn w9, w20; sxtw x10, w0]
uint64_t fde_sub_06b8f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404FEDULL) << 32) | 0xB8B97AA8ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B8F0ULL;
}

// FDE #1202 | PC: 0x06b908..0x06b918 (16 B) | Symbol: sub_06b908
// EN: AArch64 prologue [str xzr, [sp, #0x18]; str wzr, [sp, #0x10]; stp x24, x26, [sp]; b #0x5e2f0] | VI: Khởi đầu hàm AArch64 [str xzr, [sp, #0x18]; str wzr, [sp, #0x10]; stp x24, x26, [sp]; b #0x5e2f0]
uint64_t fde_sub_06b908(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB90013FFULL) << 32) | 0xF9000FFFULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B908ULL;
}

// FDE #1203 | PC: 0x06b918..0x06b928 (16 B) | Symbol: sub_06b918
// EN: AArch64 prologue [mov x0, x22; mov x1, x28; mov w2, w27; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x22; mov x1, x28; mov w2, w27; ret]
uint64_t fde_sub_06b918(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1C03E1ULL) << 32) | 0xAA1603E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B918ULL;
}

// FDE #1204 | PC: 0x06b928..0x06b934 (12 B) | Symbol: sub_06b928
// EN: AArch64 prologue [mov x0, x22; mov x1, x21; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x22; mov x1, x21; ret]
uint64_t fde_sub_06b928(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E1ULL) << 32) | 0xAA1603E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B928ULL;
}

// FDE #1205 | PC: 0x06b934..0x06b94c (24 B) | Symbol: sub_06b934
// EN: AArch64 prologue [mov x1, x28; mov w2, w25; mov w3, w27; mov w4, wzr] | VI: Khởi đầu hàm AArch64 [mov x1, x28; mov w2, w25; mov w3, w27; mov w4, wzr]
uint64_t fde_sub_06b934(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1903E2ULL) << 32) | 0xAA1C03E1ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B934ULL;
}

// FDE #1206 | PC: 0x06b94c..0x06b954 (8 B) | Symbol: sub_06b94c
// EN: AArch64 prologue [and w0, w8, #0xfffffffe; b #0x38f9c] | VI: Khởi đầu hàm AArch64 [and w0, w8, #0xfffffffe; b #0x38f9c]
uint64_t fde_sub_06b94c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF3593ULL) << 32) | 0x121F7900ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B94CULL;
}

// FDE #1207 | PC: 0x06b954..0x06b960 (12 B) | Symbol: sub_06b954
// EN: AArch64 prologue [cmp w9, #3; ccmp w9, #2, #4, ls; ret] | VI: Khởi đầu hàm AArch64 [cmp w9, #3; ccmp w9, #2, #4, ls; ret]
uint64_t fde_sub_06b954(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7A429924ULL) << 32) | 0x71000D3FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B954ULL;
}

// FDE #1208 | PC: 0x06b960..0x06b970 (16 B) | Symbol: sub_06b960
// EN: AArch64 prologue [add x21, x21, #8; add x19, x19, #8; add w23, w23, #1; ret] | VI: Khởi đầu hàm AArch64 [add x21, x21, #8; add x19, x19, #8; add w23, w23, #1; ret]
uint64_t fde_sub_06b960(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91002273ULL) << 32) | 0x910022B5ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B960ULL;
}

// FDE #1209 | PC: 0x06b970..0x06b97c (12 B) | Symbol: sub_06b970
// EN: AArch64 prologue [ldrb w8, [x19, #0x1ce]; ldrb w9, [x19, #0x1cf]; ret] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x19, #0x1ce]; ldrb w9, [x19, #0x1cf]; ret]
uint64_t fde_sub_06b970(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39473E69ULL) << 32) | 0x39473A68ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B970ULL;
}

// FDE #1210 | PC: 0x06b97c..0x06b994 (24 B) | Symbol: sub_06b97c
// EN: AArch64 prologue [ldr x14, [x0, x13, lsl #3]; ldr x15, [x4, x13, lsl #3]; add x13, x13, #1; ldr w14, [x14, x11, lsl #2]] | VI: Khởi đầu hàm AArch64 [ldr x14, [x0, x13, lsl #3]; ldr x15, [x4, x13, lsl #3]; add x13, x13, #1; ldr w14, [x14, x11, lsl #2]]
uint64_t fde_sub_06b97c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF86D788FULL) << 32) | 0xF86D780EULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B97CULL;
}

// FDE #1211 | PC: 0x06b994..0x06b9ac (24 B) | Symbol: sub_06b994
// EN: AArch64 prologue [ldp x20, x19, [sp, #0x80]; ldp x22, x21, [sp, #0x70]; ldp x24, x23, [sp, #0x60]; ldp x26, x25, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0x80]; ldp x22, x21, [sp, #0x70]; ldp x24, x23, [sp, #0x60]; ldp x26, x25, [sp, #0x50]]
uint64_t fde_sub_06b994(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94757F6ULL) << 32) | 0xA9484FF4ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B994ULL;
}

// FDE #1212 | PC: 0x06b9ac..0x06b9c4 (24 B) | Symbol: sub_06b9ac
// EN: AArch64 prologue [lsl w8, w8, #1; sub w8, w8, #2; smull x9, w9, w9; cmp w8, #0x1f] | VI: Khởi đầu hàm AArch64 [lsl w8, w8, #1; sub w8, w8, #2; smull x9, w9, w9; cmp w8, #0x1f]
uint64_t fde_sub_06b9ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x51000908ULL) << 32) | 0x531F7908ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B9ACULL;
}

// FDE #1213 | PC: 0x06b9c4..0x06b9dc (24 B) | Symbol: sub_06b9c4
// EN: AArch64 prologue [ldp w11, w12, [x10, #-0x10]; ldp w13, w14, [x10, #-8]; ldp w15, w16, [x10]; ldp w17, w0, [x10, #8]] | VI: Khởi đầu hàm AArch64 [ldp w11, w12, [x10, #-0x10]; ldp w13, w14, [x10, #-8]; ldp w15, w16, [x10]; ldp w17, w0, [x10, #8]]
uint64_t fde_sub_06b9c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x297F394DULL) << 32) | 0x297E314BULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B9C4ULL;
}

// FDE #1214 | PC: 0x06b9dc..0x06b9ec (16 B) | Symbol: sub_06b9dc
// EN: AArch64 prologue [mov w7, #7; mov w6, wzr; str x8, [sp]; b #0x629e8] | VI: Khởi đầu hàm AArch64 [mov w7, #7; mov w6, wzr; str x8, [sp]; b #0x629e8]
uint64_t fde_sub_06b9dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E6ULL) << 32) | 0x528000E7ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B9DCULL;
}

// FDE #1215 | PC: 0x06b9ec..0x06b9f8 (12 B) | Symbol: sub_06b9ec
// EN: AArch64 prologue [ldr x9, [sp, #0x38]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [sp, #0x38]; cmp x8, x9; ret]
uint64_t fde_sub_06b9ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xF9401FE9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B9ECULL;
}

// FDE #1216 | PC: 0x06b9f8..0x06ba08 (16 B) | Symbol: sub_06b9f8
// EN: AArch64 prologue [mov w6, wzr; ldr w5, [x1], #0x1c; ldr w7, [x25, #0xc]; b #0x1c5a8] | VI: Khởi đầu hàm AArch64 [mov w6, wzr; ldr w5, [x1], #0x1c; ldr w7, [x25, #0xc]; b #0x1c5a8]
uint64_t fde_sub_06b9f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB841C425ULL) << 32) | 0x2A1F03E6ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B9F8ULL;
}

// FDE #1217 | PC: 0x06ba08..0x06ba18 (16 B) | Symbol: sub_06ba08
// EN: AArch64 prologue [str w10, [x11]; ldr w10, [x9], #8; str w10, [x11, #4]; ret] | VI: Khởi đầu hàm AArch64 [str w10, [x11]; ldr w10, [x9], #8; str w10, [x11, #4]; ret]
uint64_t fde_sub_06ba08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB840852AULL) << 32) | 0xB900016AULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BA08ULL;
}

// FDE #1218 | PC: 0x06ba18..0x06ba20 (8 B) | Symbol: sub_06ba18
// EN: AArch64 prologue [mov x0, x20; b #0x1a928] | VI: Khởi đầu hàm AArch64 [mov x0, x20; b #0x1a928]
uint64_t fde_sub_06ba18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBBC3ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BA18ULL;
}

// FDE #1219 | PC: 0x06ba20..0x06ba28 (8 B) | Symbol: sub_06ba20
// EN: AArch64 prologue [mov w2, w21; b #0x1a948] | VI: Khởi đầu hàm AArch64 [mov w2, w21; b #0x1a948]
uint64_t fde_sub_06ba20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBBC9ULL) << 32) | 0x2A1503E2ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BA20ULL;
}

// FDE #1220 | PC: 0x06ba28..0x06ba38 (16 B) | Symbol: sub_06ba28
// EN: AArch64 prologue [ldr x2, [sp, #0x28]; mov x0, x25; mov w3, w21; ret] | VI: Khởi đầu hàm AArch64 [ldr x2, [sp, #0x28]; mov x0, x25; mov w3, w21; ret]
uint64_t fde_sub_06ba28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1903E0ULL) << 32) | 0xF94017E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BA28ULL;
}

// FDE #1221 | PC: 0x06ba38..0x06ba44 (12 B) | Symbol: sub_06ba38
// EN: AArch64 prologue [mov x19, x1; mov x21, x0; ret] | VI: Khởi đầu hàm AArch64 [mov x19, x1; mov x21, x0; ret]
uint64_t fde_sub_06ba38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F5ULL) << 32) | 0xAA0103F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BA38ULL;
}

// FDE #1222 | PC: 0x06ba44..0x06ba4c (8 B) | Symbol: sub_06ba44
// EN: AArch64 prologue [mov x0, x25; b #0x2ab40] | VI: Khởi đầu hàm AArch64 [mov x0, x25; b #0x2ab40]
uint64_t fde_sub_06ba44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEFC3EULL) << 32) | 0xAA1903E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BA44ULL;
}

// FDE #1223 | PC: 0x06ba4c..0x06ba54 (8 B) | Symbol: sub_06ba4c
// EN: AArch64 prologue [mov x0, x19; b #0x1a7e8] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x1a7e8]
uint64_t fde_sub_06ba4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBB66ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BA4CULL;
}

// FDE #1224 | PC: 0x06ba54..0x06ba64 (16 B) | Symbol: sub_06ba54
// EN: AArch64 prologue [mov x0, x19; mov x1, x20; mov x2, x21; b #0x52c7c] | VI: Khởi đầu hàm AArch64 [mov x0, x19; mov x1, x20; mov x2, x21; b #0x52c7c]
uint64_t fde_sub_06ba54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E1ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BA54ULL;
}

// FDE #1225 | PC: 0x06ba64..0x06ba6c (8 B) | Symbol: sub_06ba64
// EN: AArch64 prologue [mov x0, x19; b #0x1a928] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x1a928]
uint64_t fde_sub_06ba64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBBB0ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BA64ULL;
}

// FDE #1226 | PC: 0x06ba6c..0x06ba78 (12 B) | Symbol: sub_06ba6c
// EN: AArch64 prologue [mrs x27, tpidr_el0; ldr x8, [x27, #0x28]; ret] | VI: Khởi đầu hàm AArch64 [mrs x27, tpidr_el0; ldr x8, [x27, #0x28]; ret]
uint64_t fde_sub_06ba6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401768ULL) << 32) | 0xD53BD05BULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BA6CULL;
}

// FDE #1227 | PC: 0x06ba78..0x06ba88 (16 B) | Symbol: sub_06ba78
// EN: AArch64 prologue [cmp w8, w10; mov w8, #0x403; csel w0, wzr, w8, eq; ret] | VI: Khởi đầu hàm AArch64 [cmp w8, w10; mov w8, #0x403; csel w0, wzr, w8, eq; ret]
uint64_t fde_sub_06ba78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52808068ULL) << 32) | 0x6B0A011FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BA78ULL;
}

// FDE #1228 | PC: 0x06ba88..0x06ba98 (16 B) | Symbol: sub_06ba88
// EN: AArch64 prologue [add w13, w9, w8; add x8, x8, #1; strb w11, [x12, w13, sxtw]; ret] | VI: Khởi đầu hàm AArch64 [add w13, w9, w8; add x8, x8, #1; strb w11, [x12, w13, sxtw]; ret]
uint64_t fde_sub_06ba88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91000508ULL) << 32) | 0x0B08012DULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BA88ULL;
}

// FDE #1229 | PC: 0x06ba98..0x06bab0 (24 B) | Symbol: sub_06ba98
// EN: AArch64 prologue [mul x8, x8, x9; lsr x8, x8, #0x1f; and w8, w8, #0xfffffffe; neg w11, w10] | VI: Khởi đầu hàm AArch64 [mul x8, x8, x9; lsr x8, x8, #0x1f; and w8, w8, #0xfffffffe; neg w11, w10]
uint64_t fde_sub_06ba98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD35FFD08ULL) << 32) | 0x9B097D08ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BA98ULL;
}

// FDE #1230 | PC: 0x06bab0..0x06bac0 (16 B) | Symbol: sub_06bab0
// EN: AArch64 prologue [mrs x9, tpidr_el0; ldr x8, [x9, #0x28]; stur x8, [x29, #-0x60]; ret] | VI: Khởi đầu hàm AArch64 [mrs x9, tpidr_el0; ldr x8, [x9, #0x28]; stur x8, [x29, #-0x60]; ret]
uint64_t fde_sub_06bab0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401528ULL) << 32) | 0xD53BD049ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BAB0ULL;
}

// FDE #1231 | PC: 0x06bac0..0x06bad8 (24 B) | Symbol: sub_06bac0
// EN: AArch64 prologue [neg w11, w9; lsl w10, w8, w9; cmp w9, #0; asr w8, w8, w11] | VI: Khởi đầu hàm AArch64 [neg w11, w9; lsl w10, w8, w9; cmp w9, #0; asr w8, w8, w11]
uint64_t fde_sub_06bac0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1AC9210AULL) << 32) | 0x4B0903EBULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BAC0ULL;
}

// FDE #1232 | PC: 0x06bad8..0x06bae4 (12 B) | Symbol: sub_06bad8
// EN: AArch64 prologue [mov x1, x24; mov x2, x23; ret] | VI: Khởi đầu hàm AArch64 [mov x1, x24; mov x2, x23; ret]
uint64_t fde_sub_06bad8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1703E2ULL) << 32) | 0xAA1803E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BAD8ULL;
}

// FDE #1233 | PC: 0x06bae4..0x06bafc (24 B) | Symbol: sub_06bae4
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x43304; ldp w10, w8, [sp, #0x98]; ldp w11, w9, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x43304; ldp w10, w8, [sp, #0x98]; ldp w11, w9, [sp, #0x90]]
uint64_t fde_sub_06bae4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x97FF5E07ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BAE4ULL;
}

// FDE #1234 | PC: 0x06bafc..0x06bb0c (16 B) | Symbol: sub_06bafc
// EN: AArch64 prologue [mov w1, #1; mov w2, #1; mov x0, x22; b #0x1bdb8] | VI: Khởi đầu hàm AArch64 [mov w1, #1; mov w2, #1; mov x0, x22; b #0x1bdb8]
uint64_t fde_sub_06bafc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800022ULL) << 32) | 0x52800021ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BAFCULL;
}

// FDE #1235 | PC: 0x06bb0c..0x06bb24 (24 B) | Symbol: sub_06bb0c
// EN: AArch64 prologue [add x8, x0, #8; neg w9, w8; and x9, x9, #7; add x8, x8, x9] | VI: Khởi đầu hàm AArch64 [add x8, x0, #8; neg w9, w8; and x9, x9, #7; add x8, x8, x9]
uint64_t fde_sub_06bb0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4B0803E9ULL) << 32) | 0x91002008ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BB0CULL;
}

// FDE #1236 | PC: 0x06bb24..0x06bb30 (12 B) | Symbol: sub_06bb24
// EN: AArch64 prologue [ldur x9, [x29, #-0x58]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldur x9, [x29, #-0x58]; cmp x8, x9; ret]
uint64_t fde_sub_06bb24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xF85A83A9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BB24ULL;
}

// FDE #1237 | PC: 0x06bb30..0x06bb48 (24 B) | Symbol: sub_06bb30
// EN: AArch64 prologue [mov x0, x24; mov x1, x22; mov x2, x21; mov w4, w19] | VI: Khởi đầu hàm AArch64 [mov x0, x24; mov x1, x22; mov x2, x21; mov w4, w19]
uint64_t fde_sub_06bb30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E1ULL) << 32) | 0xAA1803E0ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BB30ULL;
}

// FDE #1238 | PC: 0x06bb48..0x06bb58 (16 B) | Symbol: sub_06bb48
// EN: AArch64 prologue [ldr x8, [x24, x26, lsl #3]; mov w1, w25; add x0, x8, x22, lsl #2; b #0x1a7e8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x24, x26, lsl #3]; mov w1, w25; add x0, x8, x22, lsl #2; b #0x1a7e8]
uint64_t fde_sub_06bb48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1903E1ULL) << 32) | 0xF87A7B08ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BB48ULL;
}

// FDE #1239 | PC: 0x06bb58..0x06bb68 (16 B) | Symbol: sub_06bb58
// EN: AArch64 prologue [ldrb w0, [x21, #0x22]; mov x1, x22; mov x2, x19; b #0x53bb0] | VI: Khởi đầu hàm AArch64 [ldrb w0, [x21, #0x22]; mov x1, x22; mov x2, x19; b #0x53bb0]
uint64_t fde_sub_06bb58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E1ULL) << 32) | 0x39408AA0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BB58ULL;
}

// FDE #1240 | PC: 0x06bb68..0x06bb88 (32 B) | Symbol: sub_06bb68
// EN: AArch64 prologue [ldp x17, x16, [x0, #0xd8]; add x16, x16, x15; add x16, x16, x12, lsl #1; ldrh w16, [x16, x13]] | VI: Khởi đầu hàm AArch64 [ldp x17, x16, [x0, #0xd8]; add x16, x16, x15; add x16, x16, x12, lsl #1; ldrh w16, [x16, x13]]
uint64_t fde_sub_06bb68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8B0F0210ULL) << 32) | 0xA94DC011ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BB68ULL;
}

// FDE #1241 | PC: 0x06bb88..0x06bb90 (8 B) | Symbol: sub_06bb88
// EN: AArch64 prologue [mov w1, #0x100; b #0x1a7e8] | VI: Khởi đầu hàm AArch64 [mov w1, #0x100; b #0x1a7e8]
uint64_t fde_sub_06bb88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBB17ULL) << 32) | 0x52802001ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BB88ULL;
}

// FDE #1242 | PC: 0x06bb90..0x06bb98 (8 B) | Symbol: sub_06bb90
// EN: AArch64 prologue [str d0, [x19, #0x18]; b #0x1ba38] | VI: Khởi đầu hàm AArch64 [str d0, [x19, #0x18]; b #0x1ba38]
uint64_t fde_sub_06bb90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBFA9ULL) << 32) | 0xFD000E60ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BB90ULL;
}

// FDE #1243 | PC: 0x06bb98..0x06bba8 (16 B) | Symbol: sub_06bb98
// EN: AArch64 prologue [asr w8, w8, #1; add w8, w8, w9, asr #1; mvn w0, w8; b #0x1b3f8] | VI: Khởi đầu hàm AArch64 [asr w8, w8, #1; add w8, w8, w9, asr #1; mvn w0, w8; b #0x1b3f8]
uint64_t fde_sub_06bb98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x0B890508ULL) << 32) | 0x13017D08ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BB98ULL;
}

// FDE #1244 | PC: 0x06bba8..0x06bbc0 (24 B) | Symbol: sub_06bba8
// EN: AArch64 prologue [add x9, x25, x8; ldrsb w10, [x9]; ldursb w11, [x9, #-1]; sub x8, x8, #1] | VI: Khởi đầu hàm AArch64 [add x9, x25, x8; ldrsb w10, [x9]; ldursb w11, [x9, #-1]; sub x8, x8, #1]
uint64_t fde_sub_06bba8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39C0012AULL) << 32) | 0x8B080329ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BBA8ULL;
}

// FDE #1245 | PC: 0x06bbc0..0x06bbd8 (24 B) | Symbol: sub_06bbc0
// EN: AArch64 prologue [ldr w1, [sp, #0x5c]; ldr w2, [sp, #0x4c]; ldr x3, [sp, #0x50]; ldr x4, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [ldr w1, [sp, #0x5c]; ldr w2, [sp, #0x4c]; ldr x3, [sp, #0x50]; ldr x4, [sp, #0x40]]
uint64_t fde_sub_06bbc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9404FE2ULL) << 32) | 0xB9405FE1ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BBC0ULL;
}

// FDE #1246 | PC: 0x06bbd8..0x06bbf4 (28 B) | Symbol: sub_06bbd8
// EN: AArch64 prologue [sub sp, sp, #0x70; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_06bbd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BFBULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BBD8ULL;
}

// FDE #1247 | PC: 0x06bbf4..0x06bc00 (12 B) | Symbol: sub_06bbf4
// EN: AArch64 prologue [mov w2, wzr; mov w3, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w2, wzr; mov w3, wzr; ret]
uint64_t fde_sub_06bbf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E3ULL) << 32) | 0x2A1F03E2ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BBF4ULL;
}

// FDE #1248 | PC: 0x06bc00..0x06bc08 (8 B) | Symbol: sub_06bc00
// EN: AArch64 prologue [mov w2, wzr; b #0x1be28] | VI: Khởi đầu hàm AArch64 [mov w2, wzr; b #0x1be28]
uint64_t fde_sub_06bc00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC089ULL) << 32) | 0x2A1F03E2ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BC00ULL;
}

// FDE #1249 | PC: 0x06bc08..0x06bc18 (16 B) | Symbol: sub_06bc08
// EN: AArch64 prologue [ldp x20, x19, [sp, #0x20]; ldp x22, x21, [sp, #0x10]; ldr x23, [sp], #0x30; ret] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0x20]; ldp x22, x21, [sp, #0x10]; ldr x23, [sp], #0x30; ret]
uint64_t fde_sub_06bc08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94157F6ULL) << 32) | 0xA9424FF4ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BC08ULL;
}

// FDE #1250 | PC: 0x06bc18..0x06bc28 (16 B) | Symbol: sub_06bc18
// EN: AArch64 prologue [ldp x20, x19, [sp, #0x20]; ldr x21, [sp, #0x10]; add sp, sp, #0x40; ret] | VI: Khởi đầu hàm AArch64 [ldp x20, x19, [sp, #0x20]; ldr x21, [sp, #0x10]; add sp, sp, #0x40; ret]
uint64_t fde_sub_06bc18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BF5ULL) << 32) | 0xA9424FF4ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BC18ULL;
}

// FDE #1251 | PC: 0x06bc28..0x06bc34 (12 B) | Symbol: sub_06bc28
// EN: AArch64 prologue [cmp w8, #2; cset w8, eq; ret] | VI: Khởi đầu hàm AArch64 [cmp w8, #2; cset w8, eq; ret]
uint64_t fde_sub_06bc28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1A9F17E8ULL) << 32) | 0x7100091FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BC28ULL;
}

// FDE #1252 | PC: 0x06bc34..0x06bc5c (40 B) | Symbol: sub_06bc34
// EN: AArch64 prologue [mul x10, x11, x10; sub w8, w8, w9; lsr x10, x10, #0x1f; neg w9, w8] | VI: Khởi đầu hàm AArch64 [mul x10, x11, x10; sub w8, w8, w9; lsr x10, x10, #0x1f; neg w9, w8]
uint64_t fde_sub_06bc34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4B090108ULL) << 32) | 0x9B0A7D6AULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BC34ULL;
}

// FDE #1253 | PC: 0x06bc5c..0x06bc74 (24 B) | Symbol: sub_06bc5c
// EN: AArch64 prologue [mov w8, #1; stp xzr, xzr, [x19]; str wzr, [x19, #0x18]; str xzr, [x19, #0x10]] | VI: Khởi đầu hàm AArch64 [mov w8, #1; stp xzr, xzr, [x19]; str wzr, [x19, #0x18]; str xzr, [x19, #0x10]]
uint64_t fde_sub_06bc5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9007E7FULL) << 32) | 0x52800028ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BC5CULL;
}

// FDE #1254 | PC: 0x06bc74..0x06bc8c (24 B) | Symbol: sub_06bc74
// EN: AArch64 prologue [mov w8, #1; mov w9, #0x218; str w8, [sp, #0xc]; umaddl x8, w3, w9, x19] | VI: Khởi đầu hàm AArch64 [mov w8, #1; mov w9, #0x218; str w8, [sp, #0xc]; umaddl x8, w3, w9, x19]
uint64_t fde_sub_06bc74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52804309ULL) << 32) | 0x52800028ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BC74ULL;
}

// FDE #1255 | PC: 0x06bc8c..0x06bcb4 (40 B) | Symbol: sub_06bc8c
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; mov w0, w22; str w8, [x20, x24]; bl #0x1b3e8] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; mov w0, w22; str w8, [x20, x24]; bl #0x1b3e8]
uint64_t fde_sub_06bc8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1603E0ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BC8CULL;
}

// FDE #1256 | PC: 0x06bcb4..0x06bcbc (8 B) | Symbol: sub_06bcb4
// EN: AArch64 prologue [mov x0, x21; b #0x1a948] | VI: Khởi đầu hàm AArch64 [mov x0, x21; b #0x1a948]
uint64_t fde_sub_06bcb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBB24ULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BCB4ULL;
}

// FDE #1257 | PC: 0x06bcbc..0x06bccc (16 B) | Symbol: sub_06bcbc
// EN: AArch64 prologue [mov x0, x21; mov x1, x22; mov w2, wzr; b #0x5be28] | VI: Khởi đầu hàm AArch64 [mov x0, x21; mov x1, x22; mov w2, wzr; b #0x5be28]
uint64_t fde_sub_06bcbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E1ULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BCBCULL;
}

// FDE #1258 | PC: 0x06bccc..0x06bcd4 (8 B) | Symbol: sub_06bccc
// EN: AArch64 prologue [mov x0, x21; b #0x322bc] | VI: Khởi đầu hàm AArch64 [mov x0, x21; b #0x322bc]
uint64_t fde_sub_06bccc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF197BULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BCCCULL;
}

// FDE #1259 | PC: 0x06bcd4..0x06bce0 (12 B) | Symbol: sub_06bcd4
// EN: AArch64 prologue [mov w8, wzr; mov w9, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w8, wzr; mov w9, wzr; ret]
uint64_t fde_sub_06bcd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E9ULL) << 32) | 0x2A1F03E8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BCD4ULL;
}

// FDE #1260 | PC: 0x06bce0..0x06bcec (12 B) | Symbol: sub_06bce0
// EN: AArch64 prologue [mov w8, wzr; mov w22, w24; ret] | VI: Khởi đầu hàm AArch64 [mov w8, wzr; mov w22, w24; ret]
uint64_t fde_sub_06bce0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1803F6ULL) << 32) | 0x2A1F03E8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BCE0ULL;
}

// FDE #1261 | PC: 0x06bcec..0x06bcf4 (8 B) | Symbol: sub_06bcec
// EN: AArch64 prologue [mov x0, x27; b #0x1d1b8] | VI: Khởi đầu hàm AArch64 [mov x0, x27; b #0x1d1b8]
uint64_t fde_sub_06bcec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC532ULL) << 32) | 0xAA1B03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BCECULL;
}

// FDE #1262 | PC: 0x06bcf4..0x06bd04 (16 B) | Symbol: sub_06bcf4
// EN: AArch64 prologue [mov x0, x27; mov w2, w26; mov x3, x28; b #0x37830] | VI: Khởi đầu hàm AArch64 [mov x0, x27; mov w2, w26; mov x3, x28; b #0x37830]
uint64_t fde_sub_06bcf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1A03E2ULL) << 32) | 0xAA1B03E0ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BCF4ULL;
}

// FDE #1263 | PC: 0x06bd04..0x06bd0c (8 B) | Symbol: sub_06bd04
// EN: AArch64 prologue [mov w0, #0x2000; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x2000; ret]
uint64_t fde_sub_06bd04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52840000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BD04ULL;
}

// FDE #1264 | PC: 0x06bd0c..0x06bd1c (16 B) | Symbol: sub_06bd0c
// EN: AArch64 prologue [sub w9, w28, w21; bic w9, w9, w9, asr #31; strh w9, [x25, #0x6c]; ret] | VI: Khởi đầu hàm AArch64 [sub w9, w28, w21; bic w9, w9, w9, asr #31; strh w9, [x25, #0x6c]; ret]
uint64_t fde_sub_06bd0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x0AA97D29ULL) << 32) | 0x4B150389ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BD0CULL;
}

// FDE #1265 | PC: 0x06bd1c..0x06bd38 (28 B) | Symbol: sub_06bd1c
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0]; bl #0x1cbd8] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0]; bl #0x1cbd8]
uint64_t fde_sub_06bd1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BD1CULL;
}

// FDE #1266 | PC: 0x06bd38..0x06bd40 (8 B) | Symbol: sub_06bd38
// EN: AArch64 prologue [mov w1, w24; b #0x322bc] | VI: Khởi đầu hàm AArch64 [mov w1, w24; b #0x322bc]
uint64_t fde_sub_06bd38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF1960ULL) << 32) | 0x2A1803E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BD38ULL;
}

// FDE #1267 | PC: 0x06bd40..0x06bd4c (12 B) | Symbol: sub_06bd40
// EN: AArch64 prologue [mov w2, #3; mov x1, x23; b #0x5a224] | VI: Khởi đầu hàm AArch64 [mov w2, #3; mov x1, x23; b #0x5a224]
uint64_t fde_sub_06bd40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1703E1ULL) << 32) | 0x52800062ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BD40ULL;
}

// FDE #1268 | PC: 0x06bd4c..0x06bd54 (8 B) | Symbol: sub_06bd4c
// EN: AArch64 prologue [add x21, sp, #0x78; b #0x46204] | VI: Khởi đầu hàm AArch64 [add x21, sp, #0x78; b #0x46204]
uint64_t fde_sub_06bd4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF692DULL) << 32) | 0x9101E3F5ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BD4CULL;
}

// FDE #1269 | PC: 0x06bd54..0x06bd68 (20 B) | Symbol: sub_06bd54
// EN: AArch64 prologue [bic w9, w9, w10; str w9, [x12, x8]; ldr x8, [sp, #0x28]; str xzr, [x8, #0x3188]] | VI: Khởi đầu hàm AArch64 [bic w9, w9, w10; str w9, [x12, x8]; ldr x8, [sp, #0x28]; str xzr, [x8, #0x3188]]
uint64_t fde_sub_06bd54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB8286989ULL) << 32) | 0x0A2A0129ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BD54ULL;
}

// FDE #1270 | PC: 0x06bd68..0x06bd7c (20 B) | Symbol: sub_06bd68
// EN: AArch64 prologue [ldr w8, [sp, #0x40]; str w8, [x19]; ldr w8, [sp, #0x44]; str w8, [x19, #4]] | VI: Khởi đầu hàm AArch64 [ldr w8, [sp, #0x40]; str w8, [x19]; ldr w8, [sp, #0x44]; str w8, [x19, #4]]
uint64_t fde_sub_06bd68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9000268ULL) << 32) | 0xB94043E8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BD68ULL;
}

// FDE #1271 | PC: 0x06bd7c..0x06bd84 (8 B) | Symbol: sub_06bd7c
// EN: AArch64 prologue [mov x0, sp; b #0x45ee4] | VI: Khởi đầu hàm AArch64 [mov x0, sp; b #0x45ee4]
uint64_t fde_sub_06bd7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF6859ULL) << 32) | 0x910003E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BD7CULL;
}

// FDE #1272 | PC: 0x06bd84..0x06bd90 (12 B) | Symbol: sub_06bd84
// EN: AArch64 prologue [mov w2, w19; sub w1, w8, w9; b #0x2660c] | VI: Khởi đầu hàm AArch64 [mov w2, w19; sub w1, w8, w9; b #0x2660c]
uint64_t fde_sub_06bd84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x4B090101ULL) << 32) | 0x2A1303E2ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BD84ULL;
}

// FDE #1273 | PC: 0x06bd90..0x06bda4 (20 B) | Symbol: sub_06bd90
// EN: AArch64 prologue [cmp w19, w0; add x27, x27, #0x30; csel w20, w19, w0, lt; sub x28, x28, #1] | VI: Khởi đầu hàm AArch64 [cmp w19, w0; add x27, x27, #0x30; csel w20, w19, w0, lt; sub x28, x28, #1]
uint64_t fde_sub_06bd90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9100C37BULL) << 32) | 0x6B00027FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BD90ULL;
}

// FDE #1274 | PC: 0x06bda4..0x06bdb8 (20 B) | Symbol: sub_06bda4
// EN: AArch64 prologue [ldr w12, [x20, x9, lsl #2]; ldr w13, [x11, x9, lsl #2]; ldr w14, [x23, w10, sxtw #2]; ldr w15, [x20, w10, sxtw #2]] | VI: Khởi đầu hàm AArch64 [ldr w12, [x20, x9, lsl #2]; ldr w13, [x11, x9, lsl #2]; ldr w14, [x23, w10, sxtw #2]; ldr w15, [x20, w10, sxtw #2]]
uint64_t fde_sub_06bda4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB869796DULL) << 32) | 0xB8697A8CULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BDA4ULL;
}

// FDE #1275 | PC: 0x06bdb8..0x06bdc4 (12 B) | Symbol: sub_06bdb8
// EN: AArch64 prologue [mov w0, w25; mov w1, w21; b #0x1cbe8] | VI: Khởi đầu hàm AArch64 [mov w0, w25; mov w1, w21; b #0x1cbe8]
uint64_t fde_sub_06bdb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1503E1ULL) << 32) | 0x2A1903E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BDB8ULL;
}

// FDE #1276 | PC: 0x06bdc4..0x06bdd8 (20 B) | Symbol: sub_06bdc4
// EN: AArch64 prologue [asr w11, w11, w9; str w11, [x23, x8, lsl #2]; str wzr, [x22, x8, lsl #2]; add x8, x8, #1] | VI: Khởi đầu hàm AArch64 [asr w11, w11, w9; str w11, [x23, x8, lsl #2]; str wzr, [x22, x8, lsl #2]; add x8, x8, #1]
uint64_t fde_sub_06bdc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB8287AEBULL) << 32) | 0x1AC9296BULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BDC4ULL;
}

// FDE #1277 | PC: 0x06bdd8..0x06bde4 (12 B) | Symbol: sub_06bdd8
// EN: AArch64 prologue [add x0, sp, #0x40; mov w2, #8; b #0x322bc] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x40; mov w2, #8; b #0x322bc]
uint64_t fde_sub_06bdd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800102ULL) << 32) | 0x910103E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BDD8ULL;
}

// FDE #1278 | PC: 0x06bde4..0x06bdf0 (12 B) | Symbol: sub_06bde4
// EN: AArch64 prologue [add x0, sp, #0x40; mov w2, #4; b #0x322bc] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x40; mov w2, #4; b #0x322bc]
uint64_t fde_sub_06bde4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800082ULL) << 32) | 0x910103E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BDE4ULL;
}

// FDE #1279 | PC: 0x06bdf0..0x06bdfc (12 B) | Symbol: sub_06bdf0
// EN: AArch64 prologue [add x0, sp, #0x40; mov w2, #7; b #0x322bc] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x40; mov w2, #7; b #0x322bc]
uint64_t fde_sub_06bdf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x528000E2ULL) << 32) | 0x910103E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BDF0ULL;
}

// FDE #1280 | PC: 0x06bdfc..0x06be08 (12 B) | Symbol: sub_06bdfc
// EN: AArch64 prologue [mov x1, x19; mov w2, w22; ret] | VI: Khởi đầu hàm AArch64 [mov x1, x19; mov w2, w22; ret]
uint64_t fde_sub_06bdfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1603E2ULL) << 32) | 0xAA1303E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BDFCULL;
}

// FDE #1281 | PC: 0x06be08..0x06be10 (8 B) | Symbol: sub_06be08
// EN: AArch64 prologue [mov w1, w19; b #0x1a7e8] | VI: Khởi đầu hàm AArch64 [mov w1, w19; b #0x1a7e8]
uint64_t fde_sub_06be08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBA77ULL) << 32) | 0x2A1303E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BE08ULL;
}

// FDE #1282 | PC: 0x06be10..0x06be1c (12 B) | Symbol: sub_06be10
// EN: AArch64 prologue [mov x22, x1; mov x19, x0; ret] | VI: Khởi đầu hàm AArch64 [mov x22, x1; mov x19, x0; ret]
uint64_t fde_sub_06be10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xAA0103F6ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BE10ULL;
}

// FDE #1283 | PC: 0x06be1c..0x06be30 (20 B) | Symbol: sub_06be1c
// EN: AArch64 prologue [bic w8, w8, w8, asr #31; cmp w9, w8; csel w8, w9, w8, gt; cmp w10, w8] | VI: Khởi đầu hàm AArch64 [bic w8, w8, w8, asr #31; cmp w9, w8; csel w8, w9, w8, gt; cmp w10, w8]
uint64_t fde_sub_06be1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6B08013FULL) << 32) | 0x0AA87D08ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BE1CULL;
}

// FDE #1284 | PC: 0x06be30..0x06be44 (20 B) | Symbol: sub_06be30
// EN: AArch64 prologue [ldr w2, [x19, #0x34]; mov x0, x20; mov x1, x28; mov w3, w26] | VI: Khởi đầu hàm AArch64 [ldr w2, [x19, #0x34]; mov x0, x20; mov x1, x28; mov w3, w26]
uint64_t fde_sub_06be30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0xB9403662ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BE30ULL;
}

// FDE #1285 | PC: 0x06be44..0x06be4c (8 B) | Symbol: sub_06be44
// EN: AArch64 prologue [mov w2, w22; b #0x1a948] | VI: Khởi đầu hàm AArch64 [mov w2, w22; b #0x1a948]
uint64_t fde_sub_06be44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBAC0ULL) << 32) | 0x2A1603E2ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BE44ULL;
}

// FDE #1286 | PC: 0x06be4c..0x06be54 (8 B) | Symbol: sub_06be4c
// EN: AArch64 prologue [mov w5, w24; b #0x41708] | VI: Khởi đầu hàm AArch64 [mov w5, w24; b #0x41708]
uint64_t fde_sub_06be4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF562EULL) << 32) | 0x2A1803E5ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BE4CULL;
}

// FDE #1287 | PC: 0x06be54..0x06be60 (12 B) | Symbol: sub_06be54
// EN: AArch64 prologue [mov x19, x2; mov x20, x1; ret] | VI: Khởi đầu hàm AArch64 [mov x19, x2; mov x20, x1; ret]
uint64_t fde_sub_06be54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103F4ULL) << 32) | 0xAA0203F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BE54ULL;
}

// FDE #1288 | PC: 0x06be60..0x06be6c (12 B) | Symbol: sub_06be60
// EN: AArch64 prologue [mov x19, x2; mov x20, x1; b #0x1d1b8] | VI: Khởi đầu hàm AArch64 [mov x19, x2; mov x20, x1; b #0x1d1b8]
uint64_t fde_sub_06be60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103F4ULL) << 32) | 0xAA0203F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BE60ULL;
}

// FDE #1289 | PC: 0x06be6c..0x06be80 (20 B) | Symbol: sub_06be6c
// EN: AArch64 prologue [ldr w2, [x25, #-8]!; ldr w8, [sp, #0x44]; add w20, w20, #1; ldr w3, [x25, #4]] | VI: Khởi đầu hàm AArch64 [ldr w2, [x25, #-8]!; ldr w8, [sp, #0x44]; add w20, w20, #1; ldr w3, [x25, #4]]
uint64_t fde_sub_06be6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB94047E8ULL) << 32) | 0xB85F8F22ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BE6CULL;
}

// FDE #1290 | PC: 0x06be80..0x06be8c (12 B) | Symbol: sub_06be80
// EN: AArch64 prologue [add x1, sp, #0x14; mov x0, x19; b #0x4d1fc] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0x14; mov x0, x19; b #0x4d1fc]
uint64_t fde_sub_06be80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x910053E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BE80ULL;
}

// FDE #1291 | PC: 0x06be8c..0x06bea0 (20 B) | Symbol: sub_06be8c
// EN: AArch64 prologue [ldr w8, [sp, #0x44]; add x0, sp, #0x44; add x1, sp, #0x40; mov x4, x21] | VI: Khởi đầu hàm AArch64 [ldr w8, [sp, #0x44]; add x0, sp, #0x44; add x1, sp, #0x40; mov x4, x21]
uint64_t fde_sub_06be8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910113E0ULL) << 32) | 0xB94047E8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BE8CULL;
}

// FDE #1292 | PC: 0x06bea0..0x06beb4 (20 B) | Symbol: sub_06bea0
// EN: AArch64 prologue [ldr w25, [sp, #0x28]; adrp x26, #0x78000; add x21, sp, #0x110; add x26, x26, #0xa8c] | VI: Khởi đầu hàm AArch64 [ldr w25, [sp, #0x28]; adrp x26, #0x78000; add x21, sp, #0x110; add x26, x26, #0xa8c]
uint64_t fde_sub_06bea0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB000007AULL) << 32) | 0xB9402BF9ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BEA0ULL;
}

// FDE #1293 | PC: 0x06beb4..0x06bec0 (12 B) | Symbol: sub_06beb4
// EN: AArch64 prologue [add x1, sp, #0x1e0; mov w2, wzr; b #0x41680] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0x1e0; mov w2, wzr; b #0x41680]
uint64_t fde_sub_06beb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E2ULL) << 32) | 0x910783E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BEB4ULL;
}

// FDE #1294 | PC: 0x06bec0..0x06bed4 (20 B) | Symbol: sub_06bec0
// EN: AArch64 prologue [ldr x0, [x20, x25, lsl #3]; ldr w3, [x19, #0x2b4]; mov x1, x21; mov w4, w28] | VI: Khởi đầu hàm AArch64 [ldr x0, [x20, x25, lsl #3]; ldr w3, [x19, #0x2b4]; mov x1, x21; mov w4, w28]
uint64_t fde_sub_06bec0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB942B663ULL) << 32) | 0xF8797A80ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BEC0ULL;
}

// FDE #1295 | PC: 0x06bed4..0x06bee8 (20 B) | Symbol: sub_06bed4
// EN: AArch64 prologue [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #2; mov w3, #1] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #2; mov w3, #1]
uint64_t fde_sub_06bed4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910783E1ULL) << 32) | 0x910243E0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BED4ULL;
}

// FDE #1296 | PC: 0x06bee8..0x06befc (20 B) | Symbol: sub_06bee8
// EN: AArch64 prologue [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #1; mov w3, #4] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #1; mov w3, #4]
uint64_t fde_sub_06bee8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910783E1ULL) << 32) | 0x910243E0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BEE8ULL;
}

// FDE #1297 | PC: 0x06befc..0x06bf10 (20 B) | Symbol: sub_06befc
// EN: AArch64 prologue [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #1; mov w3, #6] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #1; mov w3, #6]
uint64_t fde_sub_06befc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910783E1ULL) << 32) | 0x910243E0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BEFCULL;
}

// FDE #1298 | PC: 0x06bf10..0x06bf24 (20 B) | Symbol: sub_06bf10
// EN: AArch64 prologue [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #1; mov w3, #5] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #1; mov w3, #5]
uint64_t fde_sub_06bf10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910783E1ULL) << 32) | 0x910243E0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BF10ULL;
}

// FDE #1299 | PC: 0x06bf24..0x06bf38 (20 B) | Symbol: sub_06bf24
// EN: AArch64 prologue [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #1; mov w3, #2] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #1; mov w3, #2]
uint64_t fde_sub_06bf24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910783E1ULL) << 32) | 0x910243E0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BF24ULL;
}

// FDE #1300 | PC: 0x06bf38..0x06bf4c (20 B) | Symbol: sub_06bf38
// EN: AArch64 prologue [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #4; mov w3, #3] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x90; add x1, sp, #0x1e0; mov w2, #4; mov w3, #3]
uint64_t fde_sub_06bf38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910783E1ULL) << 32) | 0x910243E0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BF38ULL;
}

// FDE #1301 | PC: 0x06bf4c..0x06bf58 (12 B) | Symbol: sub_06bf4c
// EN: AArch64 prologue [sub x0, x29, #0x5c; sub x1, x29, #0x60; ret] | VI: Khởi đầu hàm AArch64 [sub x0, x29, #0x5c; sub x1, x29, #0x60; ret]
uint64_t fde_sub_06bf4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183A1ULL) << 32) | 0xD10173A0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BF4CULL;
}

// FDE #1302 | PC: 0x06bf58..0x06bf64 (12 B) | Symbol: sub_06bf58
// EN: AArch64 prologue [sub x1, x29, #0x58; mov x4, x22; ret] | VI: Khởi đầu hàm AArch64 [sub x1, x29, #0x58; mov x4, x22; ret]
uint64_t fde_sub_06bf58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E4ULL) << 32) | 0xD10163A1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BF58ULL;
}

// FDE #1303 | PC: 0x06bf64..0x06bf78 (20 B) | Symbol: sub_06bf64
// EN: AArch64 prologue [add w9, w9, w22; sub w10, w10, #1; str w8, [x21]; and w8, w10, w9] | VI: Khởi đầu hàm AArch64 [add w9, w9, w22; sub w10, w10, #1; str w8, [x21]; and w8, w10, w9]
uint64_t fde_sub_06bf64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5100054AULL) << 32) | 0x0B160129ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BF64ULL;
}

// FDE #1304 | PC: 0x06bf78..0x06bf84 (12 B) | Symbol: sub_06bf78
// EN: AArch64 prologue [mov w1, #5; mov w2, #1; b #0x1cbf8] | VI: Khởi đầu hàm AArch64 [mov w1, #5; mov w2, #1; b #0x1cbf8]
uint64_t fde_sub_06bf78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800022ULL) << 32) | 0x528000A1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BF78ULL;
}

// FDE #1305 | PC: 0x06bf84..0x06bf8c (8 B) | Symbol: sub_06bf84
// EN: AArch64 prologue [mov w2, #0x20; b #0x1a948] | VI: Khởi đầu hàm AArch64 [mov w2, #0x20; b #0x1a948]
uint64_t fde_sub_06bf84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBA70ULL) << 32) | 0x52800402ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BF84ULL;
}

// FDE #1306 | PC: 0x06bf8c..0x06bf94 (8 B) | Symbol: sub_06bf8c
// EN: AArch64 prologue [mov x0, x23; b #0x1a948] | VI: Khởi đầu hàm AArch64 [mov x0, x23; b #0x1a948]
uint64_t fde_sub_06bf8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBA6EULL) << 32) | 0xAA1703E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BF8CULL;
}

// FDE #1307 | PC: 0x06bf94..0x06bfa0 (12 B) | Symbol: sub_06bf94
// EN: AArch64 prologue [mov x0, x23; mov x1, x19; b #0x55c40] | VI: Khởi đầu hàm AArch64 [mov x0, x23; mov x1, x19; b #0x55c40]
uint64_t fde_sub_06bf94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E1ULL) << 32) | 0xAA1703E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BF94ULL;
}

// FDE #1308 | PC: 0x06bfa0..0x06bfb4 (20 B) | Symbol: sub_06bfa0
// EN: AArch64 prologue [mov x0, x23; mov x1, x27; mov w2, wzr; mov w3, w21] | VI: Khởi đầu hàm AArch64 [mov x0, x23; mov x1, x27; mov w2, wzr; mov w3, w21]
uint64_t fde_sub_06bfa0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1B03E1ULL) << 32) | 0xAA1703E0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BFA0ULL;
}

// FDE #1309 | PC: 0x06bfb4..0x06bfbc (8 B) | Symbol: sub_06bfb4
// EN: AArch64 prologue [mov x0, x23; b #0x1d1b8] | VI: Khởi đầu hàm AArch64 [mov x0, x23; b #0x1d1b8]
uint64_t fde_sub_06bfb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC480ULL) << 32) | 0xAA1703E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BFB4ULL;
}

// FDE #1310 | PC: 0x06bfbc..0x06bfc4 (8 B) | Symbol: sub_06bfbc
// EN: AArch64 prologue [mov x1, x21; b #0x1bcc8] | VI: Khởi đầu hàm AArch64 [mov x1, x21; b #0x1bcc8]
uint64_t fde_sub_06bfbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBF42ULL) << 32) | 0xAA1503E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BFBCULL;
}

// FDE #1311 | PC: 0x06bfc4..0x06bfd8 (20 B) | Symbol: sub_06bfc4
// EN: AArch64 prologue [mov x2, xzr; mov w3, w19; mov w4, wzr; mov w5, wzr] | VI: Khởi đầu hàm AArch64 [mov x2, xzr; mov w3, w19; mov w4, wzr; mov w5, wzr]
uint64_t fde_sub_06bfc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1303E3ULL) << 32) | 0xAA1F03E2ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BFC4ULL;
}

// FDE #1312 | PC: 0x06bfd8..0x06bfe0 (8 B) | Symbol: sub_06bfd8
// EN: AArch64 prologue [ldr x3, [sp, #0x68]; b #0x64318] | VI: Khởi đầu hàm AArch64 [ldr x3, [sp, #0x68]; b #0x64318]
uint64_t fde_sub_06bfd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFE0CFULL) << 32) | 0xF94037E3ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BFD8ULL;
}

// FDE #1313 | PC: 0x06bfe0..0x06bfec (12 B) | Symbol: sub_06bfe0
// EN: AArch64 prologue [mov w3, wzr; mov w7, w22; b #0x1bfb8] | VI: Khởi đầu hàm AArch64 [mov w3, wzr; mov w7, w22; b #0x1bfb8]
uint64_t fde_sub_06bfe0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1603E7ULL) << 32) | 0x2A1F03E3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BFE0ULL;
}

// FDE #1314 | PC: 0x06bfec..0x06bff8 (12 B) | Symbol: sub_06bfec
// EN: AArch64 prologue [mov x26, x15; mov x24, x14; b #0x1c5f8] | VI: Khởi đầu hàm AArch64 [mov x26, x15; mov x24, x14; b #0x1c5f8]
uint64_t fde_sub_06bfec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0E03F8ULL) << 32) | 0xAA0F03FAULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BFECULL;
}

// FDE #1315 | PC: 0x06bff8..0x06c004 (12 B) | Symbol: sub_06bff8
// EN: AArch64 prologue [mov w1, w26; mov w2, w23; b #0x2660c] | VI: Khởi đầu hàm AArch64 [mov w1, w26; mov w2, w23; b #0x2660c]
uint64_t fde_sub_06bff8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1703E2ULL) << 32) | 0x2A1A03E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BFF8ULL;
}

// FDE #1316 | PC: 0x06c004..0x06c018 (20 B) | Symbol: sub_06c004
// EN: AArch64 prologue [sxtw x10, w8; add x8, x25, w8, sxtw #4; ldrh w1, [x8, w9, sxtw #1]; add x8, x26, x10, lsl #5] | VI: Khởi đầu hàm AArch64 [sxtw x10, w8; add x8, x25, w8, sxtw #4; ldrh w1, [x8, w9, sxtw #1]; add x8, x26, x10, lsl #5]
uint64_t fde_sub_06c004(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8B28D328ULL) << 32) | 0x93407D0AULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C004ULL;
}

// FDE #1317 | PC: 0x06c018..0x06c024 (12 B) | Symbol: sub_06c018
// EN: AArch64 prologue [add x0, sp, #0x1c0; mov w1, #0x20; b #0x1a7e8] | VI: Khởi đầu hàm AArch64 [add x0, sp, #0x1c0; mov w1, #0x20; b #0x1a7e8]
uint64_t fde_sub_06c018(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800401ULL) << 32) | 0x910703E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C018ULL;
}

// FDE #1318 | PC: 0x06c024..0x06c030 (12 B) | Symbol: sub_06c024
// EN: AArch64 prologue [sub w1, w20, w0; mov x0, x27; b #0x1df60] | VI: Khởi đầu hàm AArch64 [sub w1, w20, w0; mov x0, x27; b #0x1df60]
uint64_t fde_sub_06c024(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1B03E0ULL) << 32) | 0x4B000281ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C024ULL;
}

// FDE #1319 | PC: 0x06c030..0x06c03c (12 B) | Symbol: sub_06c030
// EN: AArch64 prologue [mov w1, w28; mov w2, w26; b #0x36248] | VI: Khởi đầu hàm AArch64 [mov w1, w28; mov w2, w26; b #0x36248]
uint64_t fde_sub_06c030(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1A03E2ULL) << 32) | 0x2A1C03E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C030ULL;
}

// FDE #1320 | PC: 0x06c03c..0x06c048 (12 B) | Symbol: sub_06c03c
// EN: AArch64 prologue [mov x1, x27; mov w3, wzr; b #0x25e2c] | VI: Khởi đầu hàm AArch64 [mov x1, x27; mov w3, wzr; b #0x25e2c]
uint64_t fde_sub_06c03c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E3ULL) << 32) | 0xAA1B03E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C03CULL;
}

// FDE #1321 | PC: 0x06c048..0x06c05c (20 B) | Symbol: sub_06c048
// EN: AArch64 prologue [mov w1, #0x69ed; movk w1, #0x9344, lsl #16; mov w17, #-0x40000000; mov w16, #0x7fffffff] | VI: Khởi đầu hàm AArch64 [mov w1, #0x69ed; movk w1, #0x9344, lsl #16; mov w17, #-0x40000000; mov w16, #0x7fffffff]
uint64_t fde_sub_06c048(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72B26881ULL) << 32) | 0x528D3DA1ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C048ULL;
}

// FDE #1322 | PC: 0x06c05c..0x06c068 (12 B) | Symbol: sub_06c05c
// EN: AArch64 prologue [add x8, x9, x8, lsl #2; add x0, x8, #8; b #0x2660c] | VI: Khởi đầu hàm AArch64 [add x8, x9, x8, lsl #2; add x0, x8, #8; b #0x2660c]
uint64_t fde_sub_06c05c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91002100ULL) << 32) | 0x8B080928ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C05CULL;
}

// FDE #1323 | PC: 0x06c068..0x06c074 (12 B) | Symbol: sub_06c068
// EN: AArch64 prologue [ldrb w0, [x8, #0x72]; add x1, x8, #0x73; b #0x5a1b0] | VI: Khởi đầu hàm AArch64 [ldrb w0, [x8, #0x72]; add x1, x8, #0x73; b #0x5a1b0]
uint64_t fde_sub_06c068(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9101CD01ULL) << 32) | 0x3941C900ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C068ULL;
}

// FDE #1324 | PC: 0x06c074..0x06c080 (12 B) | Symbol: sub_06c074
// EN: AArch64 prologue [ldr w2, [x22, #0x10]; mov w1, w19; b #0x2660c] | VI: Khởi đầu hàm AArch64 [ldr w2, [x22, #0x10]; mov w1, w19; b #0x2660c]
uint64_t fde_sub_06c074(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1303E1ULL) << 32) | 0xB94012C2ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C074ULL;
}

// FDE #1325 | PC: 0x06c080..0x06c0a4 (36 B) | Symbol: sub_06c080
// EN: AArch64 prologue [add x13, x10, #1; ldrsh w15, [x11, x10, lsl #1]; ldrsh x14, [x11, x13, lsl #1]; sxtw x8, w8] | VI: Khởi đầu hàm AArch64 [add x13, x10, #1; ldrsh w15, [x11, x10, lsl #1]; ldrsh x14, [x11, x13, lsl #1]; sxtw x8, w8]
uint64_t fde_sub_06c080(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x78EA796FULL) << 32) | 0x9100054DULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C080ULL;
}

// FDE #1326 | PC: 0x06c0a4..0x06c0b8 (20 B) | Symbol: sub_06c0a4
// EN: AArch64 prologue [ldr x8, [sp, #0x18]; mov w9, #0x16f; add x27, x27, #0x22; madd x8, x8, x9, x21] | VI: Khởi đầu hàm AArch64 [ldr x8, [sp, #0x18]; mov w9, #0x16f; add x27, x27, #0x22; madd x8, x8, x9, x21]
uint64_t fde_sub_06c0a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52802DE9ULL) << 32) | 0xF9400FE8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C0A4ULL;
}

// FDE #1327 | PC: 0x06c0b8..0x06c0c4 (12 B) | Symbol: sub_06c0b8
// EN: AArch64 prologue [mov w1, #0x2000; ldr x0, [x8]; b #0x1a7e8] | VI: Khởi đầu hàm AArch64 [mov w1, #0x2000; ldr x0, [x8]; b #0x1a7e8]
uint64_t fde_sub_06c0b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400100ULL) << 32) | 0x52840001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C0B8ULL;
}

// FDE #1328 | PC: 0x06c0c4..0x06c0e8 (36 B) | Symbol: sub_06c0c4
// EN: AArch64 prologue [eor w9, w0, w0, asr #31; mov w10, #2; clz w9, w9; sub w11, w9, #1] | VI: Khởi đầu hàm AArch64 [eor w9, w0, w0, asr #31; mov w10, #2; clz w9, w9; sub w11, w9, #1]
uint64_t fde_sub_06c0c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5280004AULL) << 32) | 0x4A807C09ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C0C4ULL;
}

// FDE #1329 | PC: 0x06c0e8..0x06c0f0 (8 B) | Symbol: sub_06c0e8
// EN: AArch64 prologue [mov x1, x22; b #0x1a948] | VI: Khởi đầu hàm AArch64 [mov x1, x22; b #0x1a948]
uint64_t fde_sub_06c0e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBA17ULL) << 32) | 0xAA1603E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C0E8ULL;
}

// FDE #1330 | PC: 0x06c0f0..0x06c0f8 (8 B) | Symbol: sub_06c0f0
// EN: AArch64 prologue [ldr w0, [x0]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0]; ret]
uint64_t fde_sub_06c0f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9400000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C0F0ULL;
}

// FDE #1331 | PC: 0x06c0f8..0x06c10c (20 B) | Symbol: sub_06c0f8
// EN: AArch64 prologue [ldr w8, [sp, #0x84]; str w8, [x19, #0xbc]; ldur x8, [sp, #0x6c]; str x8, [x19, #0xc0]] | VI: Khởi đầu hàm AArch64 [ldr w8, [sp, #0x84]; str w8, [x19, #0xbc]; ldur x8, [sp, #0x6c]; str x8, [x19, #0xc0]]
uint64_t fde_sub_06c0f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB900BE68ULL) << 32) | 0xB94087E8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C0F8ULL;
}

// FDE #1332 | PC: 0x06c10c..0x06c120 (20 B) | Symbol: sub_06c10c
// EN: AArch64 prologue [cmp w1, #0; cneg w8, w1, mi; sxth w8, w8; cmp w8, #2, lsl #12] | VI: Khởi đầu hàm AArch64 [cmp w1, #0; cneg w8, w1, mi; sxth w8, w8; cmp w8, #2, lsl #12]
uint64_t fde_sub_06c10c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5A815428ULL) << 32) | 0x7100003FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C10CULL;
}

// FDE #1333 | PC: 0x06c120..0x06c12c (12 B) | Symbol: sub_06c120
// EN: AArch64 prologue [mov w2, #1; mov x0, x25; ret] | VI: Khởi đầu hàm AArch64 [mov w2, #1; mov x0, x25; ret]
uint64_t fde_sub_06c120(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1903E0ULL) << 32) | 0x52800022ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C120ULL;
}

// FDE #1334 | PC: 0x06c12c..0x06c140 (20 B) | Symbol: sub_06c12c
// EN: AArch64 prologue [add x6, sp, #0x74; mov w4, #1; mov w5, #1; mov x0, xzr] | VI: Khởi đầu hàm AArch64 [add x6, sp, #0x74; mov w4, #1; mov w5, #1; mov x0, xzr]
uint64_t fde_sub_06c12c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800024ULL) << 32) | 0x9101D3E6ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C12CULL;
}

// FDE #1335 | PC: 0x06c140..0x06c164 (36 B) | Symbol: sub_06c140
// EN: AArch64 prologue [adrp x11, #0x9a000; ldr x11, [x11, #0x8f0]; mov x9, xzr; mov w0, wzr] | VI: Khởi đầu hàm AArch64 [adrp x11, #0x9a000; ldr x11, [x11, #0x8f0]; mov x9, xzr; mov w0, wzr]
uint64_t fde_sub_06c140(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF944796BULL) << 32) | 0xD000016BULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C140ULL;
}

// FDE #1336 | PC: 0x06c164..0x06c170 (12 B) | Symbol: sub_06c164
// EN: AArch64 prologue [mov w7, w22; str x8, [sp]; b #0x1cc08] | VI: Khởi đầu hàm AArch64 [mov w7, w22; str x8, [sp]; b #0x1cc08]
uint64_t fde_sub_06c164(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90003E8ULL) << 32) | 0x2A1603E7ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C164ULL;
}

// FDE #1337 | PC: 0x06c170..0x06c194 (36 B) | Symbol: sub_06c170
// EN: AArch64 prologue [adrp x14, #0x9a000; ldr x14, [x14, #0x8e0]; mov x9, xzr; mov w0, wzr] | VI: Khởi đầu hàm AArch64 [adrp x14, #0x9a000; ldr x14, [x14, #0x8e0]; mov x9, xzr; mov w0, wzr]
uint64_t fde_sub_06c170(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94471CEULL) << 32) | 0xD000016EULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C170ULL;
}

// FDE #1338 | PC: 0x06c194..0x06c1a0 (12 B) | Symbol: sub_06c194
// EN: AArch64 prologue [mov x1, x20; mov w2, w23; ret] | VI: Khởi đầu hàm AArch64 [mov x1, x20; mov w2, w23; ret]
uint64_t fde_sub_06c194(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1703E2ULL) << 32) | 0xAA1403E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C194ULL;
}

// FDE #1339 | PC: 0x06c1a0..0x06c1ac (12 B) | Symbol: sub_06c1a0
// EN: AArch64 prologue [mov x1, x20; mov x2, x19; ret] | VI: Khởi đầu hàm AArch64 [mov x1, x20; mov x2, x19; ret]
uint64_t fde_sub_06c1a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E2ULL) << 32) | 0xAA1403E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C1A0ULL;
}

// FDE #1340 | PC: 0x06c1ac..0x06c1b8 (12 B) | Symbol: sub_06c1ac
// EN: AArch64 prologue [add x4, sp, #0x27c; add x5, sp, #0x274; b #0x4ff04] | VI: Khởi đầu hàm AArch64 [add x4, sp, #0x27c; add x5, sp, #0x274; b #0x4ff04]
uint64_t fde_sub_06c1ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9109D3E5ULL) << 32) | 0x9109F3E4ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C1ACULL;
}

// FDE #1341 | PC: 0x06c1b8..0x06c1c4 (12 B) | Symbol: sub_06c1b8
// EN: AArch64 prologue [mov w16, #0x3c; mov w17, #0x7fffffff; ret] | VI: Khởi đầu hàm AArch64 [mov w16, #0x3c; mov w17, #0x7fffffff; ret]
uint64_t fde_sub_06c1b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12B00011ULL) << 32) | 0x52800790ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C1B8ULL;
}

// FDE #1342 | PC: 0x06c1c4..0x06c1cc (8 B) | Symbol: sub_06c1c4
// EN: AArch64 prologue [add x3, sp, #8; b #0x43884] | VI: Khởi đầu hàm AArch64 [add x3, sp, #8; b #0x43884]
uint64_t fde_sub_06c1c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF5DAFULL) << 32) | 0x910023E3ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C1C4ULL;
}

// FDE #1343 | PC: 0x06c1cc..0x06c1d4 (8 B) | Symbol: sub_06c1cc
// EN: AArch64 prologue [mov w2, #8; b #0x1b768] | VI: Khởi đầu hàm AArch64 [mov w2, #8; b #0x1b768]
uint64_t fde_sub_06c1cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBD66ULL) << 32) | 0x52800102ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C1CCULL;
}

// FDE #1344 | PC: 0x06c1d4..0x06c1e8 (20 B) | Symbol: sub_06c1d4
// EN: AArch64 prologue [ldrsw x8, [x21, x25, lsl #2]; ldr x13, [sp, #0x98]; sxtw x9, w0; add x14, sp, #0xc0] | VI: Khởi đầu hàm AArch64 [ldrsw x8, [x21, x25, lsl #2]; ldr x13, [sp, #0x98]; sxtw x9, w0; add x14, sp, #0xc0]
uint64_t fde_sub_06c1d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404FEDULL) << 32) | 0xB8B97AA8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C1D4ULL;
}

// FDE #1345 | PC: 0x06c1e8..0x06c1fc (20 B) | Symbol: sub_06c1e8
// EN: AArch64 prologue [lsl w10, w10, w19; str w10, [x23, x8, lsl #2]; str wzr, [x22, x8, lsl #2]; add x8, x8, #1] | VI: Khởi đầu hàm AArch64 [lsl w10, w10, w19; str w10, [x23, x8, lsl #2]; str wzr, [x22, x8, lsl #2]; add x8, x8, #1]
uint64_t fde_sub_06c1e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB8287AEAULL) << 32) | 0x1AD3214AULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C1E8ULL;
}

// FDE #1346 | PC: 0x06c1fc..0x06c210 (20 B) | Symbol: sub_06c1fc
// EN: AArch64 prologue [ldr x8, [sp, #0xb8]; ldr x9, [x22, x20, lsl #3]; mov w2, #0xf0; ldr x8, [x8, x20, lsl #3]] | VI: Khởi đầu hàm AArch64 [ldr x8, [sp, #0xb8]; ldr x9, [x22, x20, lsl #3]; mov w2, #0xf0; ldr x8, [x8, x20, lsl #3]]
uint64_t fde_sub_06c1fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF8747AC9ULL) << 32) | 0xF9405FE8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C1FCULL;
}

// FDE #1347 | PC: 0x06c210..0x06c218 (8 B) | Symbol: sub_06c210
// EN: AArch64 prologue [mov x0, x22; b #0x1a7e8] | VI: Khởi đầu hàm AArch64 [mov x0, x22; b #0x1a7e8]
uint64_t fde_sub_06c210(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEB975ULL) << 32) | 0xAA1603E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C210ULL;
}

// FDE #1348 | PC: 0x06c218..0x06c220 (8 B) | Symbol: sub_06c218
// EN: AArch64 prologue [mov x0, x22; b #0x1e460] | VI: Khởi đầu hàm AArch64 [mov x0, x22; b #0x1e460]
uint64_t fde_sub_06c218(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC891ULL) << 32) | 0xAA1603E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C218ULL;
}

// FDE #1349 | PC: 0x06c220..0x06c22c (12 B) | Symbol: sub_06c220
// EN: AArch64 prologue [mov x13, xzr; mov w14, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov x13, xzr; mov w14, wzr; ret]
uint64_t fde_sub_06c220(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03EEULL) << 32) | 0xAA1F03EDULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C220ULL;
}

// FDE #1350 | PC: 0x06c22c..0x06c234 (8 B) | Symbol: sub_06c22c
// EN: AArch64 prologue [mov x0, xzr; ret] | VI: Khởi đầu hàm AArch64 [mov x0, xzr; ret]
uint64_t fde_sub_06c22c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xAA1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C22CULL;
}

// FDE #1351 | PC: 0x06c234..0x06c240 (12 B) | Symbol: sub_06c234
// EN: AArch64 prologue [add x0, x19, x8; mov w1, #0x58; b #0x1a7e8] | VI: Khởi đầu hàm AArch64 [add x0, x19, x8; mov w1, #0x58; b #0x1a7e8]
uint64_t fde_sub_06c234(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800B01ULL) << 32) | 0x8B080260ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C234ULL;
}

// FDE #1352 | PC: 0x06c240..0x06c24c (12 B) | Symbol: sub_06c240
// EN: AArch64 prologue [mov w21, w6; mov x19, x0; b #0x48880] | VI: Khởi đầu hàm AArch64 [mov w21, w6; mov x19, x0; b #0x48880]
uint64_t fde_sub_06c240(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0x2A0603F5ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C240ULL;
}

// FDE #1353 | PC: 0x06c24c..0x06c258 (12 B) | Symbol: sub_06c24c
// EN: AArch64 prologue [add x1, sp, #8; mov x0, x20; b #0x1aa58] | VI: Khởi đầu hàm AArch64 [add x1, sp, #8; mov x0, x20; b #0x1aa58]
uint64_t fde_sub_06c24c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0x910023E1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C24CULL;
}

// FDE #1354 | PC: 0x06c258..0x06c264 (12 B) | Symbol: sub_06c258
// EN: AArch64 prologue [add x19, x0, x8; ldr w9, [x19, #0x18]; ret] | VI: Khởi đầu hàm AArch64 [add x19, x0, x8; ldr w9, [x19, #0x18]; ret]
uint64_t fde_sub_06c258(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9401A69ULL) << 32) | 0x8B080013ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C258ULL;
}

// FDE #1355 | PC: 0x06c264..0x06c26c (8 B) | Symbol: sub_06c264
// EN: AArch64 prologue [mov w2, #0x10; b #0x1b428] | VI: Khởi đầu hàm AArch64 [mov w2, #0x10; b #0x1b428]
uint64_t fde_sub_06c264(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBC70ULL) << 32) | 0x52800202ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C264ULL;
}

// FDE #1356 | PC: 0x06c26c..0x06c274 (8 B) | Symbol: sub_06c26c
// EN: AArch64 prologue [add x0, sp, #8; b #0x1d254] | VI: Khởi đầu hàm AArch64 [add x0, sp, #8; b #0x1d254]
uint64_t fde_sub_06c26c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC3F9ULL) << 32) | 0x910023E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C26CULL;
}

// FDE #1357 | PC: 0x06c274..0x06c280 (12 B) | Symbol: sub_06c274
// EN: AArch64 prologue [add x0, sp, #8; mov w2, #0x10; ret] | VI: Khởi đầu hàm AArch64 [add x0, sp, #8; mov w2, #0x10; ret]
uint64_t fde_sub_06c274(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800202ULL) << 32) | 0x910023E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C274ULL;
}

// FDE #1358 | PC: 0x06c280..0x06c288 (8 B) | Symbol: sub_06c280
// EN: AArch64 prologue [str w8, [x2]; ret] | VI: Khởi đầu hàm AArch64 [str w8, [x2]; ret]
uint64_t fde_sub_06c280(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9000048ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C280ULL;
}

// FDE #1359 | PC: 0x06c288..0x06c294 (12 B) | Symbol: sub_06c288
// EN: AArch64 prologue [add x11, sp, #0x480; add x12, sp, #0x390; ret] | VI: Khởi đầu hàm AArch64 [add x11, sp, #0x480; add x12, sp, #0x390; ret]
uint64_t fde_sub_06c288(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910E43ECULL) << 32) | 0x911203EBULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C288ULL;
}

// FDE #1360 | PC: 0x06c294..0x06c2a8 (20 B) | Symbol: sub_06c294
// EN: AArch64 prologue [add x8, x8, x4; str w13, [x21, w15, sxtw #2]; add w10, w10, w11; add w9, w9, w11] | VI: Khởi đầu hàm AArch64 [add x8, x8, x4; str w13, [x21, w15, sxtw #2]; add w10, w10, w11; add w9, w9, w11]
uint64_t fde_sub_06c294(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB82FDAADULL) << 32) | 0x8B040108ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C294ULL;
}

// FDE #1361 | PC: 0x06c2a8..0x06c2bc (20 B) | Symbol: sub_06c2a8
// EN: AArch64 prologue [lsl w8, w8, #1; sub w8, w8, #1; and w8, w8, w9; cmp w8, w0, uxth] | VI: Khởi đầu hàm AArch64 [lsl w8, w8, #1; sub w8, w8, #1; and w8, w8, w9; cmp w8, w0, uxth]
uint64_t fde_sub_06c2a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x51000508ULL) << 32) | 0x531F7908ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C2A8ULL;
}

// FDE #1362 | PC: 0x06c2bc..0x06c2d0 (20 B) | Symbol: sub_06c2bc
// EN: AArch64 prologue [add w22, w22, w0; add x25, x25, #1; add x26, x26, #0x50; mov x23, x24] | VI: Khởi đầu hàm AArch64 [add w22, w22, w0; add x25, x25, #1; add x26, x26, #0x50; mov x23, x24]
uint64_t fde_sub_06c2bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91000739ULL) << 32) | 0x0B0002D6ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C2BCULL;
}

// FDE #1363 | PC: 0x06c2d0..0x06c2e4 (20 B) | Symbol: sub_06c2d0
// EN: AArch64 prologue [add x1, sp, #0x10; mov w0, w21; mov w2, w22; mov x3, x20] | VI: Khởi đầu hàm AArch64 [add x1, sp, #0x10; mov w0, w21; mov w2, w22; mov x3, x20]
uint64_t fde_sub_06c2d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1503E0ULL) << 32) | 0x910043E1ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C2D0ULL;
}

// FDE #1364 | PC: 0x06c2e4..0x06c2f8 (20 B) | Symbol: sub_06c2e4
// EN: AArch64 prologue [add x9, x21, x9, lsl #2; ldr w9, [x9, #4]; add w8, w10, w8; cmp w8, w9] | VI: Khởi đầu hàm AArch64 [add x9, x21, x9, lsl #2; ldr w9, [x9, #4]; add w8, w10, w8; cmp w8, w9]
uint64_t fde_sub_06c2e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9400529ULL) << 32) | 0x8B090AA9ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C2E4ULL;
}

// FDE #1365 | PC: 0x06c2f8..0x06c30c (20 B) | Symbol: sub_06c2f8
// EN: AArch64 prologue [add x10, x0, #0x144; add x13, x0, #0x188; add x15, x0, #0x190; add x11, x0, #0x1b4] | VI: Khởi đầu hàm AArch64 [add x10, x0, #0x144; add x13, x0, #0x188; add x15, x0, #0x190; add x11, x0, #0x1b4]
uint64_t fde_sub_06c2f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9106200DULL) << 32) | 0x9105100AULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C2F8ULL;
}

// FDE #1366 | PC: 0x06c30c..0x06c320 (20 B) | Symbol: sub_06c30c
// EN: AArch64 prologue [add w22, w22, w0, uxtb; add x24, x20, x26; cmp w8, #4; ccmp w8, #1, #4, ne] | VI: Khởi đầu hàm AArch64 [add w22, w22, w0, uxtb; add x24, x20, x26; cmp w8, #4; ccmp w8, #1, #4, ne]
uint64_t fde_sub_06c30c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8B1A0298ULL) << 32) | 0x0B2002D6ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C30CULL;
}

// FDE #1367 | PC: 0x06c320..0x06c334 (20 B) | Symbol: sub_06c320
// EN: AArch64 prologue [add x10, x0, #0x104; add x13, x0, #0x184; add x15, x0, #0x18c; add x11, x0, #0x194] | VI: Khởi đầu hàm AArch64 [add x10, x0, #0x104; add x13, x0, #0x184; add x15, x0, #0x18c; add x11, x0, #0x194]
uint64_t fde_sub_06c320(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9106100DULL) << 32) | 0x9104100AULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C320ULL;
}

// FDE #1368 | PC: 0x06c334..0x06c348 (20 B) | Symbol: sub_06c334
// EN: AArch64 prologue [lsl w9, w23, #1; mov x8, xzr; sxtw x9, w9; add x10, x21, #0x10] | VI: Khởi đầu hàm AArch64 [lsl w9, w23, #1; mov x8, xzr; sxtw x9, w9; add x10, x21, #0x10]
uint64_t fde_sub_06c334(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E8ULL) << 32) | 0x531F7AE9ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C334ULL;
}

// FDE #1369 | PC: 0x06c348..0x06c354 (12 B) | Symbol: sub_06c348
// EN: AArch64 prologue [mov w10, #0x1ff8; mov x8, xzr; ret] | VI: Khởi đầu hàm AArch64 [mov w10, #0x1ff8; mov x8, xzr; ret]
uint64_t fde_sub_06c348(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E8ULL) << 32) | 0x5283FF0AULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C348ULL;
}

// FDE #1370 | PC: 0x06c354..0x06c368 (20 B) | Symbol: sub_06c354
// EN: AArch64 prologue [cmp w11, w12; csel w11, w11, w12, gt; str w11, [x23, x9, lsl #2]; add x9, x9, #1] | VI: Khởi đầu hàm AArch64 [cmp w11, w12; csel w11, w11, w12, gt; str w11, [x23, x9, lsl #2]; add x9, x9, #1]
uint64_t fde_sub_06c354(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1A8CC16BULL) << 32) | 0x6B0C017FULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C354ULL;
}

// FDE #1371 | PC: 0x06c368..0x06c370 (8 B) | Symbol: sub_06c368
// EN: AArch64 prologue [mov w6, wzr; b #0x1c5a8] | VI: Khởi đầu hàm AArch64 [mov w6, wzr; b #0x1c5a8]
uint64_t fde_sub_06c368(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC08FULL) << 32) | 0x2A1F03E6ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C368ULL;
}

// FDE #1372 | PC: 0x06c370..0x06c384 (20 B) | Symbol: sub_06c370
// EN: AArch64 prologue [adrp x8, #0x77000; add x8, x8, #0x9b0; mov w9, #0xc; smaddl x8, w3, w9, x8] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x77000; add x8, x8, #0x9b0; mov w9, #0xc; smaddl x8, w3, w9, x8]
uint64_t fde_sub_06c370(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9126C108ULL) << 32) | 0xF0000048ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C370ULL;
}

// FDE #1373 | PC: 0x06c384..0x06c390 (12 B) | Symbol: sub_06c384
// EN: AArch64 prologue [mov w8, #0x16f; madd x8, x27, x8, x21; ret] | VI: Khởi đầu hàm AArch64 [mov w8, #0x16f; madd x8, x27, x8, x21; ret]
uint64_t fde_sub_06c384(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9B085768ULL) << 32) | 0x52802DE8ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C384ULL;
}

// FDE #1374 | PC: 0x06c390..0x06c3a4 (20 B) | Symbol: sub_06c390
// EN: AArch64 prologue [ldp x3, x6, [sp, #0x68]; ldr x2, [sp, #0x38]; ldr w16, [sp, #0x84]; ldr x17, [sp, #0x78]] | VI: Khởi đầu hàm AArch64 [ldp x3, x6, [sp, #0x68]; ldr x2, [sp, #0x38]; ldr w16, [sp, #0x84]; ldr x17, [sp, #0x78]]
uint64_t fde_sub_06c390(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE2ULL) << 32) | 0xA9469BE3ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C390ULL;
}

// FDE #1375 | PC: 0x06c3a4..0x06c3b8 (20 B) | Symbol: sub_06c3a4
// EN: AArch64 prologue [mov w8, w0; mov w19, w1; mov w0, w1; mov w1, w8] | VI: Khởi đầu hàm AArch64 [mov w8, w0; mov w19, w1; mov w0, w1; mov w1, w8]
uint64_t fde_sub_06c3a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A0103F3ULL) << 32) | 0x2A0003E8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C3A4ULL;
}

// FDE #1376 | PC: 0x06c3b8..0x06c3c4 (12 B) | Symbol: sub_06c3b8
// EN: AArch64 prologue [mov x0, x20; mov x1, xzr; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x20; mov x1, xzr; ret]
uint64_t fde_sub_06c3b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E1ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C3B8ULL;
}

// FDE #1377 | PC: 0x06c3c4..0x06c3d0 (12 B) | Symbol: sub_06c3c4
// EN: AArch64 prologue [mov x0, x20; mov w1, w22; b #0x1af28] | VI: Khởi đầu hàm AArch64 [mov x0, x20; mov w1, w22; b #0x1af28]
uint64_t fde_sub_06c3c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1603E1ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C3C4ULL;
}

// FDE #1378 | PC: 0x06c3d0..0x06c3dc (12 B) | Symbol: sub_06c3d0
// EN: AArch64 prologue [mov x0, x20; mov x1, x22; b #0x5c038] | VI: Khởi đầu hàm AArch64 [mov x0, x20; mov x1, x22; b #0x5c038]
uint64_t fde_sub_06c3d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E1ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C3D0ULL;
}

// FDE #1379 | PC: 0x06c3dc..0x06c3e4 (8 B) | Symbol: sub_06c3dc
// EN: AArch64 prologue [mov x0, x20; b #0x1df00] | VI: Khởi đầu hàm AArch64 [mov x0, x20; b #0x1df00]
uint64_t fde_sub_06c3dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC6C8ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C3DCULL;
}

// FDE #1380 | PC: 0x06c3e4..0x06c3f0 (12 B) | Symbol: sub_06c3e4
// EN: AArch64 prologue [mov x0, x20; mov x1, x19; b #0x1c608] | VI: Khởi đầu hàm AArch64 [mov x0, x20; mov x1, x19; b #0x1c608]
uint64_t fde_sub_06c3e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E1ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C3E4ULL;
}

// FDE #1381 | PC: 0x06c3f0..0x06c3fc (12 B) | Symbol: sub_06c3f0
// EN: AArch64 prologue [mov x0, x20; mov w1, w21; b #0x228b4] | VI: Khởi đầu hàm AArch64 [mov x0, x20; mov w1, w21; b #0x228b4]
uint64_t fde_sub_06c3f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1503E1ULL) << 32) | 0xAA1403E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C3F0ULL;
}

// FDE #1382 | PC: 0x06c3fc..0x06c408 (12 B) | Symbol: sub_06c3fc
// EN: AArch64 prologue [cmp w8, w9; csel w8, w8, w9, gt; ret] | VI: Khởi đầu hàm AArch64 [cmp w8, w9; csel w8, w8, w9, gt; ret]
uint64_t fde_sub_06c3fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1A89C108ULL) << 32) | 0x6B09011FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C3FCULL;
}

// FDE #1383 | PC: 0x06c408..0x06c414 (12 B) | Symbol: sub_06c408
// EN: AArch64 prologue [cmp w8, w9; csel w8, w8, w9, lt; ret] | VI: Khởi đầu hàm AArch64 [cmp w8, w9; csel w8, w8, w9, lt; ret]
uint64_t fde_sub_06c408(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1A89B108ULL) << 32) | 0x6B09011FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C408ULL;
}

// FDE #1384 | PC: 0x06c414..0x06c420 (12 B) | Symbol: sub_06c414
// EN: AArch64 prologue [ldr w5, [x1], #0x1c; ldr w7, [x25, #0xc]; ret] | VI: Khởi đầu hàm AArch64 [ldr w5, [x1], #0x1c; ldr w7, [x25, #0xc]; ret]
uint64_t fde_sub_06c414(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9400F27ULL) << 32) | 0xB841C425ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C414ULL;
}

// FDE #1385 | PC: 0x06c420..0x06c434 (20 B) | Symbol: sub_06c420
// EN: AArch64 prologue [mov x19, x1; mov x20, x0; mov x21, xzr; sxtw x22, w2] | VI: Khởi đầu hàm AArch64 [mov x19, x1; mov x20, x0; mov x21, xzr; sxtw x22, w2]
uint64_t fde_sub_06c420(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F4ULL) << 32) | 0xAA0103F3ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C420ULL;
}

// FDE #1386 | PC: 0x06c434..0x06c448 (20 B) | Symbol: sub_06c434
// EN: AArch64 prologue [mov x19, x1; mov x20, x0; add x9, x1, x9; str x9, [sp, #0x10]] | VI: Khởi đầu hàm AArch64 [mov x19, x1; mov x20, x0; add x9, x1, x9; str x9, [sp, #0x10]]
uint64_t fde_sub_06c434(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F4ULL) << 32) | 0xAA0103F3ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C434ULL;
}

// FDE #1387 | PC: 0x06c448..0x06c454 (12 B) | Symbol: sub_06c448
// EN: AArch64 prologue [mov w10, #0x60; madd x10, x25, x10, x24; ret] | VI: Khởi đầu hàm AArch64 [mov w10, #0x60; madd x10, x25, x10, x24; ret]
uint64_t fde_sub_06c448(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9B0A632AULL) << 32) | 0x52800C0AULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C448ULL;
}

// FDE #1388 | PC: 0x06c454..0x06c460 (12 B) | Symbol: sub_06c454
// EN: AArch64 prologue [mov x0, x25; mov w1, w23; b #0x322bc] | VI: Khởi đầu hàm AArch64 [mov x0, x25; mov w1, w23; b #0x322bc]
uint64_t fde_sub_06c454(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1703E1ULL) << 32) | 0xAA1903E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C454ULL;
}

// FDE #1389 | PC: 0x06c460..0x06c468 (8 B) | Symbol: sub_06c460
// EN: AArch64 prologue [mov x0, x25; b #0x1d1d8] | VI: Khởi đầu hàm AArch64 [mov x0, x25; b #0x1d1d8]
uint64_t fde_sub_06c460(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC35DULL) << 32) | 0xAA1903E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C460ULL;
}

// FDE #1390 | PC: 0x06c468..0x06c474 (12 B) | Symbol: sub_06c468
// EN: AArch64 prologue [mov x0, x25; and w22, w19, #0xff; b #0x1d1d8] | VI: Khởi đầu hàm AArch64 [mov x0, x25; and w22, w19, #0xff; b #0x1d1d8]
uint64_t fde_sub_06c468(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12001E76ULL) << 32) | 0xAA1903E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C468ULL;
}

// FDE #1391 | PC: 0x06c474..0x06c47c (8 B) | Symbol: sub_06c474
// EN: AArch64 prologue [stp x24, x27, [sp]; b #0x5e2f0] | VI: Khởi đầu hàm AArch64 [stp x24, x27, [sp]; b #0x5e2f0]
uint64_t fde_sub_06c474(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFC79EULL) << 32) | 0xA9006FF8ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C474ULL;
}

// FDE #1392 | PC: 0x06c47c..0x06c488 (12 B) | Symbol: sub_06c47c
// EN: AArch64 prologue [ldr w2, [x27, #0xc00]; ldr w3, [x27, #0xc04]; ret] | VI: Khởi đầu hàm AArch64 [ldr w2, [x27, #0xc00]; ldr w3, [x27, #0xc04]; ret]
uint64_t fde_sub_06c47c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB94C0763ULL) << 32) | 0xB94C0362ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C47CULL;
}

// FDE #1393 | PC: 0x06c488..0x06c490 (8 B) | Symbol: sub_06c488
// EN: AArch64 prologue [mov x0, x19; b #0x1d254] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x1d254]
uint64_t fde_sub_06c488(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC372ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C488ULL;
}

// FDE #1394 | PC: 0x06c490..0x06c49c (12 B) | Symbol: sub_06c490
// EN: AArch64 prologue [mov x0, x19; mov w1, w23; b #0x228b4] | VI: Khởi đầu hàm AArch64 [mov x0, x19; mov w1, w23; b #0x228b4]
uint64_t fde_sub_06c490(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1703E1ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C490ULL;
}

// FDE #1395 | PC: 0x06c49c..0x06c4a4 (8 B) | Symbol: sub_06c49c
// EN: AArch64 prologue [mov x0, x19; b #0x4e84c] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x4e84c]
uint64_t fde_sub_06c49c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF88EBULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C49CULL;
}

// FDE #1396 | PC: 0x06c4a4..0x06c4b0 (12 B) | Symbol: sub_06c4a4
// EN: AArch64 prologue [mov x0, x19; mov w1, w22; b #0x1d1d8] | VI: Khởi đầu hàm AArch64 [mov x0, x19; mov w1, w22; b #0x1d1d8]
uint64_t fde_sub_06c4a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1603E1ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C4A4ULL;
}

// FDE #1397 | PC: 0x06c4b0..0x06c4b8 (8 B) | Symbol: sub_06c4b0
// EN: AArch64 prologue [mov x0, x19; b #0x4bf88] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x4bf88]
uint64_t fde_sub_06c4b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF7EB5ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C4B0ULL;
}

// FDE #1398 | PC: 0x06c4b8..0x06c4c4 (12 B) | Symbol: sub_06c4b8
// EN: AArch64 prologue [mov x0, x19; mov x1, x21; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x19; mov x1, x21; ret]
uint64_t fde_sub_06c4b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1503E1ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C4B8ULL;
}

// FDE #1399 | PC: 0x06c4c4..0x06c4d0 (12 B) | Symbol: sub_06c4c4
// EN: AArch64 prologue [mov x0, x19; str w8, [x21, #4]; b #0x1d1d8] | VI: Khởi đầu hàm AArch64 [mov x0, x19; str w8, [x21, #4]; b #0x1d1d8]
uint64_t fde_sub_06c4c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB90006A8ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C4C4ULL;
}

// FDE #1400 | PC: 0x06c4d0..0x06c4dc (12 B) | Symbol: sub_06c4d0
// EN: AArch64 prologue [mov x0, x19; mov w1, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x19; mov w1, wzr; ret]
uint64_t fde_sub_06c4d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E1ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C4D0ULL;
}

// FDE #1401 | PC: 0x06c4dc..0x06c4e4 (8 B) | Symbol: sub_06c4dc
// EN: AArch64 prologue [mov x0, x19; b #0x4e808] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x4e808]
uint64_t fde_sub_06c4dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF88CAULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C4DCULL;
}

// FDE #1402 | PC: 0x06c4e4..0x06c4ec (8 B) | Symbol: sub_06c4e4
// EN: AArch64 prologue [mov x0, x19; b #0x1df00] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x1df00]
uint64_t fde_sub_06c4e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC686ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C4E4ULL;
}

// FDE #1403 | PC: 0x06c4ec..0x06c4f4 (8 B) | Symbol: sub_06c4ec
// EN: AArch64 prologue [mov x0, x19; b #0x1df60] | VI: Khởi đầu hàm AArch64 [mov x0, x19; b #0x1df60]
uint64_t fde_sub_06c4ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC69CULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C4ECULL;
}

// FDE #1404 | PC: 0x06c4f4..0x06c508 (20 B) | Symbol: sub_06c4f4
// EN: AArch64 prologue [mov x0, x19; mov x1, x26; mov w3, w20; mov w4, w21] | VI: Khởi đầu hàm AArch64 [mov x0, x19; mov x1, x26; mov w3, w20; mov w4, w21]
uint64_t fde_sub_06c4f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1A03E1ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C4F4ULL;
}

// FDE #1405 | PC: 0x06c508..0x06c514 (12 B) | Symbol: sub_06c508
// EN: AArch64 prologue [mov x0, x19; mov x1, x23; b #0x205b8] | VI: Khởi đầu hàm AArch64 [mov x0, x19; mov x1, x23; b #0x205b8]
uint64_t fde_sub_06c508(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1703E1ULL) << 32) | 0xAA1303E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C508ULL;
}

// FDE #1406 | PC: 0x06c514..0x06c520 (12 B) | Symbol: sub_06c514
// EN: AArch64 prologue [mov w8, #0x60; madd x23, x22, x8, x20; ret] | VI: Khởi đầu hàm AArch64 [mov w8, #0x60; madd x23, x22, x8, x20; ret]
uint64_t fde_sub_06c514(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9B0852D7ULL) << 32) | 0x52800C08ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C514ULL;
}

// FDE #1407 | PC: 0x06c520..0x06c52c (12 B) | Symbol: sub_06c520
// EN: AArch64 prologue [ldr x8, [x8, #0xd8]; add x0, x8, #0x280; b #0x1cc18] | VI: Khởi đầu hàm AArch64 [ldr x8, [x8, #0xd8]; add x0, x8, #0x280; b #0x1cc18]
uint64_t fde_sub_06c520(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910A0100ULL) << 32) | 0xF9406D08ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C520ULL;
}

// FDE #1408 | PC: 0x06c52c..0x06c534 (8 B) | Symbol: sub_06c52c
// EN: AArch64 prologue [mov w2, w24; b #0x53808] | VI: Khởi đầu hàm AArch64 [mov w2, w24; b #0x53808]
uint64_t fde_sub_06c52c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF9CB6ULL) << 32) | 0x2A1803E2ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C52CULL;
}

// FDE #1409 | PC: 0x06c534..0x06c540 (12 B) | Symbol: sub_06c534
// EN: AArch64 prologue [ldr w8, [x8, #8]; cmp w8, #4; ret] | VI: Khởi đầu hàm AArch64 [ldr w8, [x8, #8]; cmp w8, #4; ret]
uint64_t fde_sub_06c534(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100111FULL) << 32) | 0xB9400908ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C534ULL;
}

// FDE #1410 | PC: 0x06c540..0x06c54c (12 B) | Symbol: sub_06c540
// EN: AArch64 prologue [mov w3, w19; mov w4, wzr; b #0x1c718] | VI: Khởi đầu hàm AArch64 [mov w3, w19; mov w4, wzr; b #0x1c718]
uint64_t fde_sub_06c540(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E4ULL) << 32) | 0x2A1303E3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C540ULL;
}

// FDE #1411 | PC: 0x06c54c..0x06c558 (12 B) | Symbol: sub_06c54c
// EN: AArch64 prologue [str w9, [x19, #0xc]; stp w8, w10, [x19, #0x48]; b #0x43304] | VI: Khởi đầu hàm AArch64 [str w9, [x19, #0xc]; stp w8, w10, [x19, #0x48]; b #0x43304]
uint64_t fde_sub_06c54c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x29092A68ULL) << 32) | 0xB9000E69ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C54CULL;
}

// FDE #1412 | PC: 0x06c558..0x06c56c (20 B) | Symbol: sub_06c558
// EN: AArch64 prologue [ldr w13, [x11, x10, lsl #2]; ldr w14, [x12, x10, lsl #2]; add x10, x10, #1; cmp w13, w14] | VI: Khởi đầu hàm AArch64 [ldr w13, [x11, x10, lsl #2]; ldr w14, [x12, x10, lsl #2]; add x10, x10, #1; cmp w13, w14]
uint64_t fde_sub_06c558(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB86A798EULL) << 32) | 0xB86A796DULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C558ULL;
}

// FDE #1413 | PC: 0x06c56c..0x06c578 (12 B) | Symbol: sub_06c56c
// EN: AArch64 prologue [ldr x24, [x8]; add x0, sp, #0x110; b #0x1cc28] | VI: Khởi đầu hàm AArch64 [ldr x24, [x8]; add x0, sp, #0x110; b #0x1cc28]
uint64_t fde_sub_06c56c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910443E0ULL) << 32) | 0xF9400118ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C56CULL;
}

// FDE #1414 | PC: 0x06c578..0x06c584 (12 B) | Symbol: sub_06c578
// EN: AArch64 prologue [movk w8, #1, lsl #16; add x0, x1, x8; ret] | VI: Khởi đầu hàm AArch64 [movk w8, #1, lsl #16; add x0, x1, x8; ret]
uint64_t fde_sub_06c578(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8B080020ULL) << 32) | 0x72A00028ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C578ULL;
}

// FDE #1415 | PC: 0x06c584..0x06c598 (20 B) | Symbol: sub_06c584
// EN: AArch64 prologue [add w8, w8, #1; udiv w9, w8, w9; add w9, w9, w9, lsl #1; sub w8, w8, w9] | VI: Khởi đầu hàm AArch64 [add w8, w8, #1; udiv w9, w8, w9; add w9, w9, w9, lsl #1; sub w8, w8, w9]
uint64_t fde_sub_06c584(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1AC90909ULL) << 32) | 0x11000508ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C584ULL;
}

// FDE #1416 | PC: 0x06c598..0x06c5ac (20 B) | Symbol: sub_06c598
// EN: AArch64 prologue [mov w3, w26; mov w4, w20; mov w6, w27; mov x7, x24] | VI: Khởi đầu hàm AArch64 [mov w3, w26; mov w4, w20; mov w6, w27; mov x7, x24]
uint64_t fde_sub_06c598(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1403E4ULL) << 32) | 0x2A1A03E3ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C598ULL;
}

// FDE #1417 | PC: 0x06c5ac..0x06c5b4 (8 B) | Symbol: sub_06c5ac
// EN: AArch64 prologue [add x0, x8, x9; ret] | VI: Khởi đầu hàm AArch64 [add x0, x8, x9; ret]
uint64_t fde_sub_06c5ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x8B090100ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C5ACULL;
}

// FDE #1418 | PC: 0x06c5b4..0x06c5c8 (20 B) | Symbol: sub_06c5b4
// EN: AArch64 prologue [mov w9, #3; lsl w1, w22, #2; mov x0, x26; strb w8, [x19, #0x22]] | VI: Khởi đầu hàm AArch64 [mov w9, #3; lsl w1, w22, #2; mov x0, x26; strb w8, [x19, #0x22]]
uint64_t fde_sub_06c5b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x531E76C1ULL) << 32) | 0x52800069ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C5B4ULL;
}

// FDE #1419 | PC: 0x06c5c8..0x06c5d4 (12 B) | Symbol: sub_06c5c8
// EN: AArch64 prologue [cmp w0, #0; cset w0, ne; ret] | VI: Khởi đầu hàm AArch64 [cmp w0, #0; cset w0, ne; ret]
uint64_t fde_sub_06c5c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1A9F07E0ULL) << 32) | 0x7100001FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C5C8ULL;
}

// FDE #1420 | PC: 0x06c5d4..0x06c5e0 (12 B) | Symbol: sub_06c5d4
// EN: AArch64 prologue [cmp w0, #0; cset w8, ne; ret] | VI: Khởi đầu hàm AArch64 [cmp w0, #0; cset w8, ne; ret]
uint64_t fde_sub_06c5d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1A9F07E8ULL) << 32) | 0x7100001FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C5D4ULL;
}

// FDE #1421 | PC: 0x06c5e0..0x06c5ec (12 B) | Symbol: sub_06c5e0
// EN: AArch64 prologue [ldrb w1, [x21, #7]; mov w2, w19; b #0x2660c] | VI: Khởi đầu hàm AArch64 [ldrb w1, [x21, #7]; mov w2, w19; b #0x2660c]
uint64_t fde_sub_06c5e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1303E2ULL) << 32) | 0x39401EA1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C5E0ULL;
}

// FDE #1422 | PC: 0x06c5ec..0x06c5f8 (12 B) | Symbol: sub_06c5ec
// EN: AArch64 prologue [sub w1, w0, w19; mov x0, x24; b #0x1df00] | VI: Khởi đầu hàm AArch64 [sub w1, w0, w19; mov x0, x24; b #0x1df00]
uint64_t fde_sub_06c5ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1803E0ULL) << 32) | 0x4B130001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C5ECULL;
}

// FDE #1423 | PC: 0x06c5f8..0x06c60c (20 B) | Symbol: sub_06c5f8
// EN: AArch64 prologue [ldr x0, [sp, #0xd0]; ldr x2, [sp, #0x58]; add x9, x19, #0x20; add x10, x10, #0x70] | VI: Khởi đầu hàm AArch64 [ldr x0, [sp, #0xd0]; ldr x2, [sp, #0x58]; add x9, x19, #0x20; add x10, x10, #0x70]
uint64_t fde_sub_06c5f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE2ULL) << 32) | 0xF9406BE0ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C5F8ULL;
}

// FDE #1424 | PC: 0x06c60c..0x06c620 (20 B) | Symbol: sub_06c60c
// EN: AArch64 prologue [ldrsw x12, [x19, x11]; add x10, x10, #1; mul x12, x12, x8; lsr x12, x12, #0x20] | VI: Khởi đầu hàm AArch64 [ldrsw x12, [x19, x11]; add x10, x10, #1; mul x12, x12, x8; lsr x12, x12, #0x20]
uint64_t fde_sub_06c60c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9100054AULL) << 32) | 0xB8AB6A6CULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C60CULL;
}

// FDE #1425 | PC: 0x06c620..0x06c62c (12 B) | Symbol: sub_06c620
// EN: AArch64 prologue [mov w19, w2; mov x20, x0; ret] | VI: Khởi đầu hàm AArch64 [mov w19, w2; mov x20, x0; ret]
uint64_t fde_sub_06c620(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F4ULL) << 32) | 0x2A0203F3ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C620ULL;
}

// FDE #1426 | PC: 0x06c62c..0x06c640 (20 B) | Symbol: sub_06c62c
// EN: AArch64 prologue [mov x24, x1; mov x26, x0; mov x27, xzr; mov w25, wzr] | VI: Khởi đầu hàm AArch64 [mov x24, x1; mov x26, x0; mov x27, xzr; mov w25, wzr]
uint64_t fde_sub_06c62c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003FAULL) << 32) | 0xAA0103F8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C62CULL;
}

// FDE #1427 | PC: 0x06c640..0x06c64c (12 B) | Symbol: sub_06c640
// EN: AArch64 prologue [ldp x28, x19, [sp, #0x110]; add sp, sp, #0x130; ret] | VI: Khởi đầu hàm AArch64 [ldp x28, x19, [sp, #0x110]; add sp, sp, #0x130; ret]
uint64_t fde_sub_06c640(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9104C3FFULL) << 32) | 0xA9514FFCULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C640ULL;
}

// FDE #1428 | PC: 0x06c64c..0x06c658 (12 B) | Symbol: sub_06c64c
// EN: AArch64 prologue [mov w0, wzr; add sp, sp, #0x90; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; add sp, sp, #0x90; ret]
uint64_t fde_sub_06c64c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910243FFULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C64CULL;
}

// FDE #1429 | PC: 0x06c658..0x06c660 (8 B) | Symbol: sub_06c658
// EN: AArch64 prologue [add sp, sp, #0x140; ret] | VI: Khởi đầu hàm AArch64 [add sp, sp, #0x140; ret]
uint64_t fde_sub_06c658(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x910503FFULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C658ULL;
}

// FDE #1430 | PC: 0x06c660..0x06c66c (12 B) | Symbol: sub_06c660
// EN: AArch64 prologue [sub x1, x29, #0x54; mov x4, x22; ret] | VI: Khởi đầu hàm AArch64 [sub x1, x29, #0x54; mov x4, x22; ret]
uint64_t fde_sub_06c660(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E4ULL) << 32) | 0xD10153A1ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C660ULL;
}

// FDE #1431 | PC: 0x06c66c..0x06c680 (20 B) | Symbol: sub_06c66c
// EN: AArch64 prologue [ldr w9, [x19, #0x2160]; lsl w9, w9, #1; sub w9, w9, #1; str w9, [x19, #0xc04]] | VI: Khởi đầu hàm AArch64 [ldr w9, [x19, #0x2160]; lsl w9, w9, #1; sub w9, w9, #1; str w9, [x19, #0xc04]]
uint64_t fde_sub_06c66c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x531F7929ULL) << 32) | 0xB9616269ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C66CULL;
}

// FDE #1432 | PC: 0x06c680..0x06c694 (20 B) | Symbol: sub_06c680
// EN: AArch64 prologue [lsr x11, x11, #0x20; lsr x10, x10, #0x20; add w11, w11, #4, lsl #12; add w10, w10, #4, lsl #12] | VI: Khởi đầu hàm AArch64 [lsr x11, x11, #0x20; lsr x10, x10, #0x20; add w11, w11, #4, lsl #12; add w10, w10, #4, lsl #12]
uint64_t fde_sub_06c680(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD360FD4AULL) << 32) | 0xD360FD6BULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C680ULL;
}

// FDE #1433 | PC: 0x06c694..0x06c6a8 (20 B) | Symbol: sub_06c694
// EN: AArch64 prologue [add w10, w11, w8, asr #1; asr w13, w9, #1; asr w8, w8, #1; add w9, w12, w9, asr #1] | VI: Khởi đầu hàm AArch64 [add w10, w11, w8, asr #1; asr w13, w9, #1; asr w8, w8, #1; add w9, w12, w9, asr #1]
uint64_t fde_sub_06c694(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x13017D2DULL) << 32) | 0x0B88056AULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C694ULL;
}

// FDE #1434 | PC: 0x06c6a8..0x06c6bc (20 B) | Symbol: sub_06c6a8
// EN: AArch64 prologue [add x8, sp, #0x100; add x3, sp, #0x3d0; add x6, sp, #0x2e0; add x7, sp, #0xbd0] | VI: Khởi đầu hàm AArch64 [add x8, sp, #0x100; add x3, sp, #0x3d0; add x6, sp, #0x2e0; add x7, sp, #0xbd0]
uint64_t fde_sub_06c6a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910F43E3ULL) << 32) | 0x910403E8ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C6A8ULL;
}

// FDE #1435 | PC: 0x06c6bc..0x06c6d0 (20 B) | Symbol: sub_06c6bc
// EN: AArch64 prologue [mul x8, x9, x8; lsr x8, x8, #0x1f; and w0, w8, #0xfffffffe; add w1, w11, w10] | VI: Khởi đầu hàm AArch64 [mul x8, x9, x8; lsr x8, x8, #0x1f; and w0, w8, #0xfffffffe; add w1, w11, w10]
uint64_t fde_sub_06c6bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD35FFD08ULL) << 32) | 0x9B087D28ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C6BCULL;
}

// FDE #1436 | PC: 0x06c6d0..0x06c6e4 (20 B) | Symbol: sub_06c6d0
// EN: AArch64 prologue [add x8, x8, #1; add x11, x11, #0xc0; add x12, x12, #0xc0; add x9, x14, w9, sxtw] | VI: Khởi đầu hàm AArch64 [add x8, x8, #1; add x11, x11, #0xc0; add x12, x12, #0xc0; add x9, x14, w9, sxtw]
uint64_t fde_sub_06c6d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9103016BULL) << 32) | 0x91000508ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C6D0ULL;
}

// FDE #1437 | PC: 0x06c6e4..0x06c6f8 (20 B) | Symbol: sub_06c6e4
// EN: AArch64 prologue [sub w8, w8, #1; cmp w8, #2; csel w8, w9, wzr, lo; strb w8, [x19, #0x23]] | VI: Khởi đầu hàm AArch64 [sub w8, w8, #1; cmp w8, #2; csel w8, w9, wzr, lo; strb w8, [x19, #0x23]]
uint64_t fde_sub_06c6e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100091FULL) << 32) | 0x51000508ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C6E4ULL;
}

// FDE #1438 | PC: 0x06c6f8..0x06c704 (12 B) | Symbol: sub_06c6f8
// EN: AArch64 prologue [mov x9, xzr; mov w10, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov x9, xzr; mov w10, wzr; ret]
uint64_t fde_sub_06c6f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03EAULL) << 32) | 0xAA1F03E9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C6F8ULL;
}

// FDE #1439 | PC: 0x06c704..0x06c710 (12 B) | Symbol: sub_06c704
// EN: AArch64 prologue [lsr x9, x9, #0x1f; and w9, w9, #0xfffffffe; ret] | VI: Khởi đầu hàm AArch64 [lsr x9, x9, #0x1f; and w9, w9, #0xfffffffe; ret]
uint64_t fde_sub_06c704(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x121F7929ULL) << 32) | 0xD35FFD29ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C704ULL;
}

// FDE #1440 | PC: 0x06c710..0x06c71c (12 B) | Symbol: sub_06c710
// EN: AArch64 prologue [cmp w8, #1; cinc w5, w25, gt; b #0x1c5a8] | VI: Khởi đầu hàm AArch64 [cmp w8, #1; cinc w5, w25, gt; b #0x1c5a8]
uint64_t fde_sub_06c710(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1A99D725ULL) << 32) | 0x7100051FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C710ULL;
}

// FDE #1441 | PC: 0x06c71c..0x06c724 (8 B) | Symbol: sub_06c71c
// EN: AArch64 prologue [mov w0, #7; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #7; ret]
uint64_t fde_sub_06c71c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x528000E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C71CULL;
}

// FDE #1442 | PC: 0x06c724..0x06c738 (20 B) | Symbol: sub_06c724
// EN: AArch64 prologue [neg w10, w8; lsl w9, w0, w8; asr w10, w0, w10; cmp w8, #0] | VI: Khởi đầu hàm AArch64 [neg w10, w8; lsl w9, w0, w8; asr w10, w0, w10; cmp w8, #0]
uint64_t fde_sub_06c724(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1AC82009ULL) << 32) | 0x4B0803EAULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C724ULL;
}

// FDE #1443 | PC: 0x06c738..0x06c74c (20 B) | Symbol: sub_06c738
// EN: AArch64 prologue [ldr x8, [x25, #0x10]; ldr q0, [x25]; ldr x0, [x23, x26, lsl #3]; ldr x3, [x27]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x25, #0x10]; ldr q0, [x25]; ldr x0, [x23, x26, lsl #3]; ldr x3, [x27]]
uint64_t fde_sub_06c738(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC00320ULL) << 32) | 0xF9400B28ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C738ULL;
}

// FDE #1444 | PC: 0x06c74c..0x06c754 (8 B) | Symbol: sub_06c74c
// EN: AArch64 prologue [mov x1, x23; b #0x1a948] | VI: Khởi đầu hàm AArch64 [mov x1, x23; b #0x1a948]
uint64_t fde_sub_06c74c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEB87EULL) << 32) | 0xAA1703E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C74CULL;
}

// FDE #1445 | PC: 0x06c754..0x06c768 (20 B) | Symbol: sub_06c754
// EN: AArch64 prologue [add x9, x25, x8; ldrsb w10, [x9]; ldrsb w11, [x9, #1]; sub w11, w10, w11] | VI: Khởi đầu hàm AArch64 [add x9, x25, x8; ldrsb w10, [x9]; ldrsb w11, [x9, #1]; sub w11, w10, w11]
uint64_t fde_sub_06c754(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39C0012AULL) << 32) | 0x8B080329ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C754ULL;
}

// FDE #1446 | PC: 0x06c768..0x06c774 (12 B) | Symbol: sub_06c768
// EN: AArch64 prologue [ldr x28, [sp, #0x30]; ldrb w9, [sp, #0x110]; ret] | VI: Khởi đầu hàm AArch64 [ldr x28, [sp, #0x30]; ldrb w9, [sp, #0x110]; ret]
uint64_t fde_sub_06c768(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x394443E9ULL) << 32) | 0xF9401BFCULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C768ULL;
}

// FDE #1447 | PC: 0x06c774..0x06c788 (20 B) | Symbol: sub_06c774
// EN: AArch64 prologue [adrp x0, #0x72000; adrp x2, #0x72000; add x0, x0, #0x953; add x2, x2, #0x97d] | VI: Khởi đầu hàm AArch64 [adrp x0, #0x72000; adrp x2, #0x72000; add x0, x0, #0x953; add x2, x2, #0x97d]
uint64_t fde_sub_06c774(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000022ULL) << 32) | 0xD0000020ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C774ULL;
}

// FDE #1448 | PC: 0x06c788..0x06c79c (20 B) | Symbol: sub_06c788
// EN: AArch64 prologue [add x8, x8, #0xf82; fmov d1, x9; adrp x1, #0x72000; mov v1.d[1], x8] | VI: Khởi đầu hàm AArch64 [add x8, x8, #0xf82; fmov d1, x9; adrp x1, #0x72000; mov v1.d[1], x8]
uint64_t fde_sub_06c788(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9E670121ULL) << 32) | 0x913E0908ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C788ULL;
}

// FDE #1449 | PC: 0x06c79c..0x06c7a8 (12 B) | Symbol: sub_06c79c
// EN: AArch64 prologue [mov w0, w0; mov w1, w1; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, w0; mov w1, w1; b #0x1a748]
uint64_t fde_sub_06c79c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A0103E1ULL) << 32) | 0x2A0003E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C79CULL;
}

// FDE #1450 | PC: 0x06c7a8..0x06c7b0 (8 B) | Symbol: sub_06c7a8
// EN: AArch64 prologue [str d0, [x20, #0x18]; b #0x1ba38] | VI: Khởi đầu hàm AArch64 [str d0, [x20, #0x18]; b #0x1ba38]
uint64_t fde_sub_06c7a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEBCA3ULL) << 32) | 0xFD000E80ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C7A8ULL;
}

// FDE #1451 | PC: 0x06c7b0..0x06c7c4 (20 B) | Symbol: sub_06c7b0
// EN: AArch64 prologue [adrp x1, #0x72000; add x0, x20, #0x24; add x1, x1, #0xf79; mov w2, #2] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x72000; add x0, x20, #0x24; add x1, x1, #0xf79; mov w2, #2]
uint64_t fde_sub_06c7b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91009280ULL) << 32) | 0xD0000021ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C7B0ULL;
}

// FDE #1452 | PC: 0x06c7c4..0x06c7d0 (12 B) | Symbol: sub_06c7c4
// EN: AArch64 prologue [mov w20, w1; mov x19, x0; ret] | VI: Khởi đầu hàm AArch64 [mov w20, w1; mov x19, x0; ret]
uint64_t fde_sub_06c7c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0x2A0103F4ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C7C4ULL;
}

// FDE #1453 | PC: 0x06c7d0..0x06c7d8 (8 B) | Symbol: sub_06c7d0
// EN: AArch64 prologue [mov w23, #1; b #0x1d1d8] | VI: Khởi đầu hàm AArch64 [mov w23, #1; b #0x1d1d8]
uint64_t fde_sub_06c7d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC281ULL) << 32) | 0x52800037ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C7D0ULL;
}

// FDE #1454 | PC: 0x06c7d8..0x06c7ec (20 B) | Symbol: sub_06c7d8
// EN: AArch64 prologue [ldr x17, [sp, #0x10]; ldrh w9, [x23, #0x5c]; ldrh w8, [x23, #0x5e]; mov w10, wzr] | VI: Khởi đầu hàm AArch64 [ldr x17, [sp, #0x10]; ldrh w9, [x23, #0x5c]; ldrh w8, [x23, #0x5e]; mov w10, wzr]
uint64_t fde_sub_06c7d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7940BAE9ULL) << 32) | 0xF9400BF1ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C7D8ULL;
}

// FDE #1455 | PC: 0x06c7ec..0x06c7f8 (12 B) | Symbol: sub_06c7ec
// EN: AArch64 prologue [mov w0, w22; mov w1, w21; b #0x5e2ac] | VI: Khởi đầu hàm AArch64 [mov w0, w22; mov w1, w21; b #0x5e2ac]
uint64_t fde_sub_06c7ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1503E1ULL) << 32) | 0x2A1603E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C7ECULL;
}

// FDE #1456 | PC: 0x06c7f8..0x06c804 (12 B) | Symbol: sub_06c7f8
// EN: AArch64 prologue [mov x0, x21; mov x1, x22; b #0x5bfd0] | VI: Khởi đầu hàm AArch64 [mov x0, x21; mov x1, x22; b #0x5bfd0]
uint64_t fde_sub_06c7f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E1ULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C7F8ULL;
}

// FDE #1457 | PC: 0x06c804..0x06c810 (12 B) | Symbol: sub_06c804
// EN: AArch64 prologue [mov x0, x21; mov x1, x22; b #0x5bb88] | VI: Khởi đầu hàm AArch64 [mov x0, x21; mov x1, x22; b #0x5bb88]
uint64_t fde_sub_06c804(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1603E1ULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C804ULL;
}

// FDE #1458 | PC: 0x06c810..0x06c81c (12 B) | Symbol: sub_06c810
// EN: AArch64 prologue [mov x0, x21; mov w1, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov x0, x21; mov w1, wzr; ret]
uint64_t fde_sub_06c810(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E1ULL) << 32) | 0xAA1503E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C810ULL;
}

// FDE #1459 | PC: 0x06c81c..0x06c828 (12 B) | Symbol: sub_06c81c
// EN: AArch64 prologue [mov w1, #1; mov x0, x20; ret] | VI: Khởi đầu hàm AArch64 [mov w1, #1; mov x0, x20; ret]
uint64_t fde_sub_06c81c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1403E0ULL) << 32) | 0x52800021ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C81CULL;
}

// FDE #1460 | PC: 0x06c828..0x06c83c (20 B) | Symbol: sub_06c828
// EN: AArch64 prologue [lsl w11, w9, w8; lsr w9, w9, w10; cmp w8, #0; csel w9, w11, w9, gt] | VI: Khởi đầu hàm AArch64 [lsl w11, w9, w8; lsr w9, w9, w10; cmp w8, #0; csel w9, w11, w9, gt]
uint64_t fde_sub_06c828(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1ACA2529ULL) << 32) | 0x1AC8212BULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C828ULL;
}

// FDE #1461 | PC: 0x06c83c..0x06c848 (12 B) | Symbol: sub_06c83c
// EN: AArch64 prologue [mov x21, x1; mov x19, x0; ret] | VI: Khởi đầu hàm AArch64 [mov x21, x1; mov x19, x0; ret]
uint64_t fde_sub_06c83c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xAA0103F5ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C83CULL;
}

// FDE #1462 | PC: 0x06c848..0x06c854 (12 B) | Symbol: sub_06c848
// EN: AArch64 prologue [mov x0, x1; mov w1, w8; b #0x322bc] | VI: Khởi đầu hàm AArch64 [mov x0, x1; mov w1, w8; b #0x322bc]
uint64_t fde_sub_06c848(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A0803E1ULL) << 32) | 0xAA0103E0ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C848ULL;
}

// FDE #1463 | PC: 0x06c854..0x06c860 (12 B) | Symbol: sub_06c854
// EN: AArch64 prologue [cmp w8, #0; cset w0, ne; ret] | VI: Khởi đầu hàm AArch64 [cmp w8, #0; cset w0, ne; ret]
uint64_t fde_sub_06c854(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1A9F07E0ULL) << 32) | 0x7100011FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C854ULL;
}

// FDE #1464 | PC: 0x06c860..0x06c86c (12 B) | Symbol: sub_06c860
// EN: AArch64 prologue [ldr x9, [sp, #0x18]; cmp x8, x9; ret] | VI: Khởi đầu hàm AArch64 [ldr x9, [sp, #0x18]; cmp x8, x9; ret]
uint64_t fde_sub_06c860(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xF9400FE9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C860ULL;
}

// FDE #1465 | PC: 0x06c86c..0x06c878 (12 B) | Symbol: sub_06c86c
// EN: AArch64 prologue [str x9, [sp, #8]; strb w8, [sp]; b #0x1cc38] | VI: Khởi đầu hàm AArch64 [str x9, [sp, #8]; strb w8, [sp]; b #0x1cc38]
uint64_t fde_sub_06c86c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x390003E8ULL) << 32) | 0xF90007E9ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C86CULL;
}

// FDE #1466 | PC: 0x06c878..0x06c884 (12 B) | Symbol: sub_06c878
// EN: AArch64 prologue [str w9, [x19, #0x1c]; stp w8, w10, [x19, #0x58]; b #0x43304] | VI: Khởi đầu hàm AArch64 [str w9, [x19, #0x1c]; stp w8, w10, [x19, #0x58]; b #0x43304]
uint64_t fde_sub_06c878(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x290B2A68ULL) << 32) | 0xB9001E69ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C878ULL;
}

// FDE #1467 | PC: 0x06c884..0x06c88c (8 B) | Symbol: sub_06c884
// EN: AArch64 prologue [mov w0, #0x2010; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0x2010; ret]
uint64_t fde_sub_06c884(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52840200ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C884ULL;
}

// FDE #1468 | PC: 0x06c88c..0x06c894 (8 B) | Symbol: sub_06c88c
// EN: AArch64 prologue [mov w1, #8; b #0x1cc48] | VI: Khởi đầu hàm AArch64 [mov w1, #8; b #0x1cc48]
uint64_t fde_sub_06c88c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC0EEULL) << 32) | 0x52800101ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C88CULL;
}

// FDE #1469 | PC: 0x06c894..0x06c89c (8 B) | Symbol: sub_06c894
// EN: AArch64 prologue [mov x19, x0; b #0x1d1d8] | VI: Khởi đầu hàm AArch64 [mov x19, x0; b #0x1d1d8]
uint64_t fde_sub_06c894(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FEC250ULL) << 32) | 0xAA0003F3ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C894ULL;
}

// FDE #1470 | PC: 0x06c89c..0x06c8a8 (12 B) | Symbol: sub_06c89c
// EN: AArch64 prologue [mov w0, #1; mov w1, #0x10; b #0x1a748] | VI: Khởi đầu hàm AArch64 [mov w0, #1; mov w1, #0x10; b #0x1a748]
uint64_t fde_sub_06c89c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800201ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C89CULL;
}

uint64_t DispatchFdeShard5(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x06b760ULL: return fde_sub_06b760(a0, a1, a2);
        case 0x06b778ULL: return fde_sub_06b778(a0, a1, a2);
        case 0x06b788ULL: return fde_sub_06b788(a0, a1, a2);
        case 0x06b790ULL: return fde_sub_06b790(a0, a1, a2);
        case 0x06b79cULL: return fde_sub_06b79c(a0, a1, a2);
        case 0x06b7b4ULL: return fde_sub_06b7b4(a0, a1, a2);
        case 0x06b7c0ULL: return fde_sub_06b7c0(a0, a1, a2);
        case 0x06b7d0ULL: return fde_sub_06b7d0(a0, a1, a2);
        case 0x06b7d8ULL: return fde_sub_06b7d8(a0, a1, a2);
        case 0x06b7f0ULL: return fde_sub_06b7f0(a0, a1, a2);
        case 0x06b800ULL: return fde_sub_06b800(a0, a1, a2);
        case 0x06b818ULL: return fde_sub_06b818(a0, a1, a2);
        case 0x06b830ULL: return fde_sub_06b830(a0, a1, a2);
        case 0x06b848ULL: return fde_sub_06b848(a0, a1, a2);
        case 0x06b860ULL: return fde_sub_06b860(a0, a1, a2);
        case 0x06b878ULL: return fde_sub_06b878(a0, a1, a2);
        case 0x06b880ULL: return fde_sub_06b880(a0, a1, a2);
        case 0x06b898ULL: return fde_sub_06b898(a0, a1, a2);
        case 0x06b8c0ULL: return fde_sub_06b8c0(a0, a1, a2);
        case 0x06b8d0ULL: return fde_sub_06b8d0(a0, a1, a2);
        case 0x06b8e0ULL: return fde_sub_06b8e0(a0, a1, a2);
        case 0x06b8f0ULL: return fde_sub_06b8f0(a0, a1, a2);
        case 0x06b908ULL: return fde_sub_06b908(a0, a1, a2);
        case 0x06b918ULL: return fde_sub_06b918(a0, a1, a2);
        case 0x06b928ULL: return fde_sub_06b928(a0, a1, a2);
        case 0x06b934ULL: return fde_sub_06b934(a0, a1, a2);
        case 0x06b94cULL: return fde_sub_06b94c(a0, a1, a2);
        case 0x06b954ULL: return fde_sub_06b954(a0, a1, a2);
        case 0x06b960ULL: return fde_sub_06b960(a0, a1, a2);
        case 0x06b970ULL: return fde_sub_06b970(a0, a1, a2);
        case 0x06b97cULL: return fde_sub_06b97c(a0, a1, a2);
        case 0x06b994ULL: return fde_sub_06b994(a0, a1, a2);
        case 0x06b9acULL: return fde_sub_06b9ac(a0, a1, a2);
        case 0x06b9c4ULL: return fde_sub_06b9c4(a0, a1, a2);
        case 0x06b9dcULL: return fde_sub_06b9dc(a0, a1, a2);
        case 0x06b9ecULL: return fde_sub_06b9ec(a0, a1, a2);
        case 0x06b9f8ULL: return fde_sub_06b9f8(a0, a1, a2);
        case 0x06ba08ULL: return fde_sub_06ba08(a0, a1, a2);
        case 0x06ba18ULL: return fde_sub_06ba18(a0, a1, a2);
        case 0x06ba20ULL: return fde_sub_06ba20(a0, a1, a2);
        case 0x06ba28ULL: return fde_sub_06ba28(a0, a1, a2);
        case 0x06ba38ULL: return fde_sub_06ba38(a0, a1, a2);
        case 0x06ba44ULL: return fde_sub_06ba44(a0, a1, a2);
        case 0x06ba4cULL: return fde_sub_06ba4c(a0, a1, a2);
        case 0x06ba54ULL: return fde_sub_06ba54(a0, a1, a2);
        case 0x06ba64ULL: return fde_sub_06ba64(a0, a1, a2);
        case 0x06ba6cULL: return fde_sub_06ba6c(a0, a1, a2);
        case 0x06ba78ULL: return fde_sub_06ba78(a0, a1, a2);
        case 0x06ba88ULL: return fde_sub_06ba88(a0, a1, a2);
        case 0x06ba98ULL: return fde_sub_06ba98(a0, a1, a2);
        case 0x06bab0ULL: return fde_sub_06bab0(a0, a1, a2);
        case 0x06bac0ULL: return fde_sub_06bac0(a0, a1, a2);
        case 0x06bad8ULL: return fde_sub_06bad8(a0, a1, a2);
        case 0x06bae4ULL: return fde_sub_06bae4(a0, a1, a2);
        case 0x06bafcULL: return fde_sub_06bafc(a0, a1, a2);
        case 0x06bb0cULL: return fde_sub_06bb0c(a0, a1, a2);
        case 0x06bb24ULL: return fde_sub_06bb24(a0, a1, a2);
        case 0x06bb30ULL: return fde_sub_06bb30(a0, a1, a2);
        case 0x06bb48ULL: return fde_sub_06bb48(a0, a1, a2);
        case 0x06bb58ULL: return fde_sub_06bb58(a0, a1, a2);
        case 0x06bb68ULL: return fde_sub_06bb68(a0, a1, a2);
        case 0x06bb88ULL: return fde_sub_06bb88(a0, a1, a2);
        case 0x06bb90ULL: return fde_sub_06bb90(a0, a1, a2);
        case 0x06bb98ULL: return fde_sub_06bb98(a0, a1, a2);
        case 0x06bba8ULL: return fde_sub_06bba8(a0, a1, a2);
        case 0x06bbc0ULL: return fde_sub_06bbc0(a0, a1, a2);
        case 0x06bbd8ULL: return fde_sub_06bbd8(a0, a1, a2);
        case 0x06bbf4ULL: return fde_sub_06bbf4(a0, a1, a2);
        case 0x06bc00ULL: return fde_sub_06bc00(a0, a1, a2);
        case 0x06bc08ULL: return fde_sub_06bc08(a0, a1, a2);
        case 0x06bc18ULL: return fde_sub_06bc18(a0, a1, a2);
        case 0x06bc28ULL: return fde_sub_06bc28(a0, a1, a2);
        case 0x06bc34ULL: return fde_sub_06bc34(a0, a1, a2);
        case 0x06bc5cULL: return fde_sub_06bc5c(a0, a1, a2);
        case 0x06bc74ULL: return fde_sub_06bc74(a0, a1, a2);
        case 0x06bc8cULL: return fde_sub_06bc8c(a0, a1, a2);
        case 0x06bcb4ULL: return fde_sub_06bcb4(a0, a1, a2);
        case 0x06bcbcULL: return fde_sub_06bcbc(a0, a1, a2);
        case 0x06bcccULL: return fde_sub_06bccc(a0, a1, a2);
        case 0x06bcd4ULL: return fde_sub_06bcd4(a0, a1, a2);
        case 0x06bce0ULL: return fde_sub_06bce0(a0, a1, a2);
        case 0x06bcecULL: return fde_sub_06bcec(a0, a1, a2);
        case 0x06bcf4ULL: return fde_sub_06bcf4(a0, a1, a2);
        case 0x06bd04ULL: return fde_sub_06bd04(a0, a1, a2);
        case 0x06bd0cULL: return fde_sub_06bd0c(a0, a1, a2);
        case 0x06bd1cULL: return fde_sub_06bd1c(a0, a1, a2);
        case 0x06bd38ULL: return fde_sub_06bd38(a0, a1, a2);
        case 0x06bd40ULL: return fde_sub_06bd40(a0, a1, a2);
        case 0x06bd4cULL: return fde_sub_06bd4c(a0, a1, a2);
        case 0x06bd54ULL: return fde_sub_06bd54(a0, a1, a2);
        case 0x06bd68ULL: return fde_sub_06bd68(a0, a1, a2);
        case 0x06bd7cULL: return fde_sub_06bd7c(a0, a1, a2);
        case 0x06bd84ULL: return fde_sub_06bd84(a0, a1, a2);
        case 0x06bd90ULL: return fde_sub_06bd90(a0, a1, a2);
        case 0x06bda4ULL: return fde_sub_06bda4(a0, a1, a2);
        case 0x06bdb8ULL: return fde_sub_06bdb8(a0, a1, a2);
        case 0x06bdc4ULL: return fde_sub_06bdc4(a0, a1, a2);
        case 0x06bdd8ULL: return fde_sub_06bdd8(a0, a1, a2);
        case 0x06bde4ULL: return fde_sub_06bde4(a0, a1, a2);
        case 0x06bdf0ULL: return fde_sub_06bdf0(a0, a1, a2);
        case 0x06bdfcULL: return fde_sub_06bdfc(a0, a1, a2);
        case 0x06be08ULL: return fde_sub_06be08(a0, a1, a2);
        case 0x06be10ULL: return fde_sub_06be10(a0, a1, a2);
        case 0x06be1cULL: return fde_sub_06be1c(a0, a1, a2);
        case 0x06be30ULL: return fde_sub_06be30(a0, a1, a2);
        case 0x06be44ULL: return fde_sub_06be44(a0, a1, a2);
        case 0x06be4cULL: return fde_sub_06be4c(a0, a1, a2);
        case 0x06be54ULL: return fde_sub_06be54(a0, a1, a2);
        case 0x06be60ULL: return fde_sub_06be60(a0, a1, a2);
        case 0x06be6cULL: return fde_sub_06be6c(a0, a1, a2);
        case 0x06be80ULL: return fde_sub_06be80(a0, a1, a2);
        case 0x06be8cULL: return fde_sub_06be8c(a0, a1, a2);
        case 0x06bea0ULL: return fde_sub_06bea0(a0, a1, a2);
        case 0x06beb4ULL: return fde_sub_06beb4(a0, a1, a2);
        case 0x06bec0ULL: return fde_sub_06bec0(a0, a1, a2);
        case 0x06bed4ULL: return fde_sub_06bed4(a0, a1, a2);
        case 0x06bee8ULL: return fde_sub_06bee8(a0, a1, a2);
        case 0x06befcULL: return fde_sub_06befc(a0, a1, a2);
        case 0x06bf10ULL: return fde_sub_06bf10(a0, a1, a2);
        case 0x06bf24ULL: return fde_sub_06bf24(a0, a1, a2);
        case 0x06bf38ULL: return fde_sub_06bf38(a0, a1, a2);
        case 0x06bf4cULL: return fde_sub_06bf4c(a0, a1, a2);
        case 0x06bf58ULL: return fde_sub_06bf58(a0, a1, a2);
        case 0x06bf64ULL: return fde_sub_06bf64(a0, a1, a2);
        case 0x06bf78ULL: return fde_sub_06bf78(a0, a1, a2);
        case 0x06bf84ULL: return fde_sub_06bf84(a0, a1, a2);
        case 0x06bf8cULL: return fde_sub_06bf8c(a0, a1, a2);
        case 0x06bf94ULL: return fde_sub_06bf94(a0, a1, a2);
        case 0x06bfa0ULL: return fde_sub_06bfa0(a0, a1, a2);
        case 0x06bfb4ULL: return fde_sub_06bfb4(a0, a1, a2);
        case 0x06bfbcULL: return fde_sub_06bfbc(a0, a1, a2);
        case 0x06bfc4ULL: return fde_sub_06bfc4(a0, a1, a2);
        case 0x06bfd8ULL: return fde_sub_06bfd8(a0, a1, a2);
        case 0x06bfe0ULL: return fde_sub_06bfe0(a0, a1, a2);
        case 0x06bfecULL: return fde_sub_06bfec(a0, a1, a2);
        case 0x06bff8ULL: return fde_sub_06bff8(a0, a1, a2);
        case 0x06c004ULL: return fde_sub_06c004(a0, a1, a2);
        case 0x06c018ULL: return fde_sub_06c018(a0, a1, a2);
        case 0x06c024ULL: return fde_sub_06c024(a0, a1, a2);
        case 0x06c030ULL: return fde_sub_06c030(a0, a1, a2);
        case 0x06c03cULL: return fde_sub_06c03c(a0, a1, a2);
        case 0x06c048ULL: return fde_sub_06c048(a0, a1, a2);
        case 0x06c05cULL: return fde_sub_06c05c(a0, a1, a2);
        case 0x06c068ULL: return fde_sub_06c068(a0, a1, a2);
        case 0x06c074ULL: return fde_sub_06c074(a0, a1, a2);
        case 0x06c080ULL: return fde_sub_06c080(a0, a1, a2);
        case 0x06c0a4ULL: return fde_sub_06c0a4(a0, a1, a2);
        case 0x06c0b8ULL: return fde_sub_06c0b8(a0, a1, a2);
        case 0x06c0c4ULL: return fde_sub_06c0c4(a0, a1, a2);
        case 0x06c0e8ULL: return fde_sub_06c0e8(a0, a1, a2);
        case 0x06c0f0ULL: return fde_sub_06c0f0(a0, a1, a2);
        case 0x06c0f8ULL: return fde_sub_06c0f8(a0, a1, a2);
        case 0x06c10cULL: return fde_sub_06c10c(a0, a1, a2);
        case 0x06c120ULL: return fde_sub_06c120(a0, a1, a2);
        case 0x06c12cULL: return fde_sub_06c12c(a0, a1, a2);
        case 0x06c140ULL: return fde_sub_06c140(a0, a1, a2);
        case 0x06c164ULL: return fde_sub_06c164(a0, a1, a2);
        case 0x06c170ULL: return fde_sub_06c170(a0, a1, a2);
        case 0x06c194ULL: return fde_sub_06c194(a0, a1, a2);
        case 0x06c1a0ULL: return fde_sub_06c1a0(a0, a1, a2);
        case 0x06c1acULL: return fde_sub_06c1ac(a0, a1, a2);
        case 0x06c1b8ULL: return fde_sub_06c1b8(a0, a1, a2);
        case 0x06c1c4ULL: return fde_sub_06c1c4(a0, a1, a2);
        case 0x06c1ccULL: return fde_sub_06c1cc(a0, a1, a2);
        case 0x06c1d4ULL: return fde_sub_06c1d4(a0, a1, a2);
        case 0x06c1e8ULL: return fde_sub_06c1e8(a0, a1, a2);
        case 0x06c1fcULL: return fde_sub_06c1fc(a0, a1, a2);
        case 0x06c210ULL: return fde_sub_06c210(a0, a1, a2);
        case 0x06c218ULL: return fde_sub_06c218(a0, a1, a2);
        case 0x06c220ULL: return fde_sub_06c220(a0, a1, a2);
        case 0x06c22cULL: return fde_sub_06c22c(a0, a1, a2);
        case 0x06c234ULL: return fde_sub_06c234(a0, a1, a2);
        case 0x06c240ULL: return fde_sub_06c240(a0, a1, a2);
        case 0x06c24cULL: return fde_sub_06c24c(a0, a1, a2);
        case 0x06c258ULL: return fde_sub_06c258(a0, a1, a2);
        case 0x06c264ULL: return fde_sub_06c264(a0, a1, a2);
        case 0x06c26cULL: return fde_sub_06c26c(a0, a1, a2);
        case 0x06c274ULL: return fde_sub_06c274(a0, a1, a2);
        case 0x06c280ULL: return fde_sub_06c280(a0, a1, a2);
        case 0x06c288ULL: return fde_sub_06c288(a0, a1, a2);
        case 0x06c294ULL: return fde_sub_06c294(a0, a1, a2);
        case 0x06c2a8ULL: return fde_sub_06c2a8(a0, a1, a2);
        case 0x06c2bcULL: return fde_sub_06c2bc(a0, a1, a2);
        case 0x06c2d0ULL: return fde_sub_06c2d0(a0, a1, a2);
        case 0x06c2e4ULL: return fde_sub_06c2e4(a0, a1, a2);
        case 0x06c2f8ULL: return fde_sub_06c2f8(a0, a1, a2);
        case 0x06c30cULL: return fde_sub_06c30c(a0, a1, a2);
        case 0x06c320ULL: return fde_sub_06c320(a0, a1, a2);
        case 0x06c334ULL: return fde_sub_06c334(a0, a1, a2);
        case 0x06c348ULL: return fde_sub_06c348(a0, a1, a2);
        case 0x06c354ULL: return fde_sub_06c354(a0, a1, a2);
        case 0x06c368ULL: return fde_sub_06c368(a0, a1, a2);
        case 0x06c370ULL: return fde_sub_06c370(a0, a1, a2);
        case 0x06c384ULL: return fde_sub_06c384(a0, a1, a2);
        case 0x06c390ULL: return fde_sub_06c390(a0, a1, a2);
        case 0x06c3a4ULL: return fde_sub_06c3a4(a0, a1, a2);
        case 0x06c3b8ULL: return fde_sub_06c3b8(a0, a1, a2);
        case 0x06c3c4ULL: return fde_sub_06c3c4(a0, a1, a2);
        case 0x06c3d0ULL: return fde_sub_06c3d0(a0, a1, a2);
        case 0x06c3dcULL: return fde_sub_06c3dc(a0, a1, a2);
        case 0x06c3e4ULL: return fde_sub_06c3e4(a0, a1, a2);
        case 0x06c3f0ULL: return fde_sub_06c3f0(a0, a1, a2);
        case 0x06c3fcULL: return fde_sub_06c3fc(a0, a1, a2);
        case 0x06c408ULL: return fde_sub_06c408(a0, a1, a2);
        case 0x06c414ULL: return fde_sub_06c414(a0, a1, a2);
        case 0x06c420ULL: return fde_sub_06c420(a0, a1, a2);
        case 0x06c434ULL: return fde_sub_06c434(a0, a1, a2);
        case 0x06c448ULL: return fde_sub_06c448(a0, a1, a2);
        case 0x06c454ULL: return fde_sub_06c454(a0, a1, a2);
        case 0x06c460ULL: return fde_sub_06c460(a0, a1, a2);
        case 0x06c468ULL: return fde_sub_06c468(a0, a1, a2);
        case 0x06c474ULL: return fde_sub_06c474(a0, a1, a2);
        case 0x06c47cULL: return fde_sub_06c47c(a0, a1, a2);
        case 0x06c488ULL: return fde_sub_06c488(a0, a1, a2);
        case 0x06c490ULL: return fde_sub_06c490(a0, a1, a2);
        case 0x06c49cULL: return fde_sub_06c49c(a0, a1, a2);
        case 0x06c4a4ULL: return fde_sub_06c4a4(a0, a1, a2);
        case 0x06c4b0ULL: return fde_sub_06c4b0(a0, a1, a2);
        case 0x06c4b8ULL: return fde_sub_06c4b8(a0, a1, a2);
        case 0x06c4c4ULL: return fde_sub_06c4c4(a0, a1, a2);
        case 0x06c4d0ULL: return fde_sub_06c4d0(a0, a1, a2);
        case 0x06c4dcULL: return fde_sub_06c4dc(a0, a1, a2);
        case 0x06c4e4ULL: return fde_sub_06c4e4(a0, a1, a2);
        case 0x06c4ecULL: return fde_sub_06c4ec(a0, a1, a2);
        case 0x06c4f4ULL: return fde_sub_06c4f4(a0, a1, a2);
        case 0x06c508ULL: return fde_sub_06c508(a0, a1, a2);
        case 0x06c514ULL: return fde_sub_06c514(a0, a1, a2);
        case 0x06c520ULL: return fde_sub_06c520(a0, a1, a2);
        case 0x06c52cULL: return fde_sub_06c52c(a0, a1, a2);
        case 0x06c534ULL: return fde_sub_06c534(a0, a1, a2);
        case 0x06c540ULL: return fde_sub_06c540(a0, a1, a2);
        case 0x06c54cULL: return fde_sub_06c54c(a0, a1, a2);
        case 0x06c558ULL: return fde_sub_06c558(a0, a1, a2);
        case 0x06c56cULL: return fde_sub_06c56c(a0, a1, a2);
        case 0x06c578ULL: return fde_sub_06c578(a0, a1, a2);
        case 0x06c584ULL: return fde_sub_06c584(a0, a1, a2);
        case 0x06c598ULL: return fde_sub_06c598(a0, a1, a2);
        case 0x06c5acULL: return fde_sub_06c5ac(a0, a1, a2);
        case 0x06c5b4ULL: return fde_sub_06c5b4(a0, a1, a2);
        case 0x06c5c8ULL: return fde_sub_06c5c8(a0, a1, a2);
        case 0x06c5d4ULL: return fde_sub_06c5d4(a0, a1, a2);
        case 0x06c5e0ULL: return fde_sub_06c5e0(a0, a1, a2);
        case 0x06c5ecULL: return fde_sub_06c5ec(a0, a1, a2);
        case 0x06c5f8ULL: return fde_sub_06c5f8(a0, a1, a2);
        case 0x06c60cULL: return fde_sub_06c60c(a0, a1, a2);
        case 0x06c620ULL: return fde_sub_06c620(a0, a1, a2);
        case 0x06c62cULL: return fde_sub_06c62c(a0, a1, a2);
        case 0x06c640ULL: return fde_sub_06c640(a0, a1, a2);
        case 0x06c64cULL: return fde_sub_06c64c(a0, a1, a2);
        case 0x06c658ULL: return fde_sub_06c658(a0, a1, a2);
        case 0x06c660ULL: return fde_sub_06c660(a0, a1, a2);
        case 0x06c66cULL: return fde_sub_06c66c(a0, a1, a2);
        case 0x06c680ULL: return fde_sub_06c680(a0, a1, a2);
        case 0x06c694ULL: return fde_sub_06c694(a0, a1, a2);
        case 0x06c6a8ULL: return fde_sub_06c6a8(a0, a1, a2);
        case 0x06c6bcULL: return fde_sub_06c6bc(a0, a1, a2);
        case 0x06c6d0ULL: return fde_sub_06c6d0(a0, a1, a2);
        case 0x06c6e4ULL: return fde_sub_06c6e4(a0, a1, a2);
        case 0x06c6f8ULL: return fde_sub_06c6f8(a0, a1, a2);
        case 0x06c704ULL: return fde_sub_06c704(a0, a1, a2);
        case 0x06c710ULL: return fde_sub_06c710(a0, a1, a2);
        case 0x06c71cULL: return fde_sub_06c71c(a0, a1, a2);
        case 0x06c724ULL: return fde_sub_06c724(a0, a1, a2);
        case 0x06c738ULL: return fde_sub_06c738(a0, a1, a2);
        case 0x06c74cULL: return fde_sub_06c74c(a0, a1, a2);
        case 0x06c754ULL: return fde_sub_06c754(a0, a1, a2);
        case 0x06c768ULL: return fde_sub_06c768(a0, a1, a2);
        case 0x06c774ULL: return fde_sub_06c774(a0, a1, a2);
        case 0x06c788ULL: return fde_sub_06c788(a0, a1, a2);
        case 0x06c79cULL: return fde_sub_06c79c(a0, a1, a2);
        case 0x06c7a8ULL: return fde_sub_06c7a8(a0, a1, a2);
        case 0x06c7b0ULL: return fde_sub_06c7b0(a0, a1, a2);
        case 0x06c7c4ULL: return fde_sub_06c7c4(a0, a1, a2);
        case 0x06c7d0ULL: return fde_sub_06c7d0(a0, a1, a2);
        case 0x06c7d8ULL: return fde_sub_06c7d8(a0, a1, a2);
        case 0x06c7ecULL: return fde_sub_06c7ec(a0, a1, a2);
        case 0x06c7f8ULL: return fde_sub_06c7f8(a0, a1, a2);
        case 0x06c804ULL: return fde_sub_06c804(a0, a1, a2);
        case 0x06c810ULL: return fde_sub_06c810(a0, a1, a2);
        case 0x06c81cULL: return fde_sub_06c81c(a0, a1, a2);
        case 0x06c828ULL: return fde_sub_06c828(a0, a1, a2);
        case 0x06c83cULL: return fde_sub_06c83c(a0, a1, a2);
        case 0x06c848ULL: return fde_sub_06c848(a0, a1, a2);
        case 0x06c854ULL: return fde_sub_06c854(a0, a1, a2);
        case 0x06c860ULL: return fde_sub_06c860(a0, a1, a2);
        case 0x06c86cULL: return fde_sub_06c86c(a0, a1, a2);
        case 0x06c878ULL: return fde_sub_06c878(a0, a1, a2);
        case 0x06c884ULL: return fde_sub_06c884(a0, a1, a2);
        case 0x06c88cULL: return fde_sub_06c88c(a0, a1, a2);
        case 0x06c894ULL: return fde_sub_06c894(a0, a1, a2);
        case 0x06c89cULL: return fde_sub_06c89c(a0, a1, a2);
        default: return 0ULL;
    }
}

uint64_t DispatchFdeShard1(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept;
uint64_t DispatchFdeShard2(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept;
uint64_t DispatchFdeShard3(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept;
uint64_t DispatchFdeShard4(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept;

// EN: Unified router across all 1,471 AArch64 FDEs in libfdk-aac.so
// VI: Bộ định tuyến hợp nhất trên toàn bộ 1.471 hàm AArch64 FDE trong libfdk-aac.so
uint64_t ExecuteFdkAacFdeByAddress(uint64_t fde_pc_begin, uint64_t arg0, uint64_t arg1, uint64_t arg2) noexcept {
    if (fde_pc_begin >= 0x01cd04ULL && fde_pc_begin <= 0x037ff8ULL) {
        return DispatchFdeShard1(fde_pc_begin, arg0, arg1, arg2);
    }
    if (fde_pc_begin >= 0x038004ULL && fde_pc_begin <= 0x04e184ULL) {
        return DispatchFdeShard2(fde_pc_begin, arg0, arg1, arg2);
    }
    if (fde_pc_begin >= 0x04e194ULL && fde_pc_begin <= 0x069f18ULL) {
        return DispatchFdeShard3(fde_pc_begin, arg0, arg1, arg2);
    }
    if (fde_pc_begin >= 0x069f30ULL && fde_pc_begin <= 0x06b750ULL) {
        return DispatchFdeShard4(fde_pc_begin, arg0, arg1, arg2);
    }
    if (fde_pc_begin >= 0x06b760ULL && fde_pc_begin <= 0x06c89cULL) {
        return DispatchFdeShard5(fde_pc_begin, arg0, arg1, arg2);
    }
    return 0ULL;
}

} // namespace fdk_aac
} // namespace opencut
