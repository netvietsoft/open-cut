// ============================================================================
// File: rex_fde_shard_5.cpp
// Target 109 / 169: librex.so (690,264 bytes)
// EN: Clean-room C++17 AArch64 Function Shard 5/5 covering [1280..1599]
//     (PC range 0x03feb4 .. 0x097c48).
// VI: Phân mảnh hàm AArch64 C++17 5/5 bao phủ [1280..1599]
//     (Dải địa chỉ PC 0x03feb4 .. 0x097c48).
// ============================================================================
#include "rex_date_format.h"

namespace bytedance {
namespace rex {

// Func #1280 | PC: 0x03feb4..0x03fef4 (64 B) | Symbol: sub_03feb4
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x9d000; add x8, x8, #0x38a; ldur q0, [x8, #9]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x9d000; add x8, x8, #0x38a; ldur q0, [x8, #9]]
uint64_t fde_sub_03feb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00002E8ULL) << 32) | 0x97FF073BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03FEB4ULL;
}

// Func #1281 | PC: 0x03ff14..0x03ff54 (64 B) | Symbol: sub_03ff14
// EN: AArch64 prologue [bl #0x1ba0; adrp x10, #0x9d000; add x10, x10, #0x3a4; ldp q0, q1, [x10]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x10, #0x9d000; add x10, x10, #0x3a4; ldp q0, q1, [x10]]
uint64_t fde_sub_03ff14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00002EAULL) << 32) | 0x97FF0723ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03FF14ULL;
}

// Func #1282 | PC: 0x03ffe0..0x040020 (64 B) | Symbol: sub_03ffe0
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xcf0]; adrp x15, #0x99000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xcf0]; adrp x15, #0x99000]
uint64_t fde_sub_03ffe0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900002C9ULL) << 32) | 0x97FF06F0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x03FFE0ULL;
}

// Func #1283 | PC: 0x040398..0x0403d8 (64 B) | Symbol: sub_040398
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9d000; add x9, x9, #0x40b; ldr q0, [x9]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9d000; add x9, x9, #0x40b; ldr q0, [x9]]
uint64_t fde_sub_040398(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00002E9ULL) << 32) | 0x97FF0602ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x040398ULL;
}

// Func #1284 | PC: 0x04046c..0x0404ac (64 B) | Symbol: sub_04046c
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xd30]; add x9, x26, #0x3f8] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xd30]; add x9, x26, #0x3f8]
uint64_t fde_sub_04046c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00002A8ULL) << 32) | 0x97FF05CDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04046CULL;
}

// Func #1285 | PC: 0x0405bc..0x0405fc (64 B) | Symbol: sub_0405bc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0405bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x94012071ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0405BCULL;
}

// Func #1286 | PC: 0x0405cc..0x04060c (64 B) | Symbol: sub_0405cc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0405cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x9401206DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0405CCULL;
}

// Func #1287 | PC: 0x0405dc..0x04061c (64 B) | Symbol: sub_0405dc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x88]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0405dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94047E1ULL) << 32) | 0x94012069ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0405DCULL;
}

// Func #1288 | PC: 0x0405ec..0x04062c (64 B) | Symbol: sub_0405ec
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0xa0]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0xa0]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0405ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94053E1ULL) << 32) | 0x94012065ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0405ECULL;
}

// Func #1289 | PC: 0x0405fc..0x04063c (64 B) | Symbol: sub_0405fc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0405fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x94012061ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0405FCULL;
}

// Func #1290 | PC: 0x04060c..0x04064c (64 B) | Symbol: sub_04060c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_04060c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x9401205DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04060CULL;
}

// Func #1291 | PC: 0x04061c..0x04065c (64 B) | Symbol: sub_04061c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_04061c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x94012059ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04061CULL;
}

// Func #1292 | PC: 0x04062c..0x04066c (64 B) | Symbol: sub_04062c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_04062c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x94012055ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04062CULL;
}

// Func #1293 | PC: 0x04063c..0x04067c (64 B) | Symbol: sub_04063c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_04063c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94003E1ULL) << 32) | 0x94012051ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04063CULL;
}

// Func #1294 | PC: 0x04064c..0x04068c (64 B) | Symbol: sub_04064c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_04064c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x9401204DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04064CULL;
}

// Func #1295 | PC: 0x04065c..0x04069c (64 B) | Symbol: sub_04065c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_04065c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x94012049ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04065CULL;
}

// Func #1296 | PC: 0x04066c..0x0406ac (64 B) | Symbol: sub_04066c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_04066c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x94012045ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04066CULL;
}

// Func #1297 | PC: 0x04067c..0x0406bc (64 B) | Symbol: sub_04067c
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x20; mov x2, x20] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x20; mov x2, x20]
uint64_t fde_sub_04067c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94012041ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04067CULL;
}

// Func #1298 | PC: 0x04068c..0x0406cc (64 B) | Symbol: sub_04068c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_04068c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x9401203DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04068CULL;
}

// Func #1299 | PC: 0x04069c..0x0406dc (64 B) | Symbol: sub_04069c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_04069c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x94012039ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04069CULL;
}

// Func #1300 | PC: 0x0406ac..0x0406ec (64 B) | Symbol: sub_0406ac
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0406ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x94012035ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0406ACULL;
}

// Func #1301 | PC: 0x0406bc..0x0406fc (64 B) | Symbol: sub_0406bc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0406bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x94012031ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0406BCULL;
}

// Func #1302 | PC: 0x0406cc..0x04070c (64 B) | Symbol: sub_0406cc
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0406cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x9401202DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0406CCULL;
}

// Func #1303 | PC: 0x0406dc..0x04071c (64 B) | Symbol: sub_0406dc
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x28; mov x2, x28] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x28; mov x2, x28]
uint64_t fde_sub_0406dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94012029ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0406DCULL;
}

// Func #1304 | PC: 0x0406ec..0x04072c (64 B) | Symbol: sub_0406ec
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0406ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x94012025ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0406ECULL;
}

// Func #1305 | PC: 0x0406fc..0x04073c (64 B) | Symbol: sub_0406fc
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22]
uint64_t fde_sub_0406fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94012021ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0406FCULL;
}

// Func #1306 | PC: 0x04070c..0x04074c (64 B) | Symbol: sub_04070c
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_04070c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x9401201DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04070CULL;
}

// Func #1307 | PC: 0x04071c..0x04075c (64 B) | Symbol: sub_04071c
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x27; mov x2, x27] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x27; mov x2, x27]
uint64_t fde_sub_04071c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94012019ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04071CULL;
}

// Func #1308 | PC: 0x04072c..0x04076c (64 B) | Symbol: sub_04072c
// EN: AArch64 prologue [bl #0x88780; mov x10, #0x9ad0; movk x10, #0xb5d0, lsl #16; movk x10, #0x88d1, lsl #32] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x10, #0x9ad0; movk x10, #0xb5d0, lsl #16; movk x10, #0x88d1, lsl #32]
uint64_t fde_sub_04072c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD2935A0AULL) << 32) | 0x94012015ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04072CULL;
}

// Func #1309 | PC: 0x040fd4..0x041014 (64 B) | Symbol: sub_040fd4
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x100]; adrp x8, #0x9d000; add x8, x8, #0x53f] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x100]; adrp x8, #0x9d000; add x8, x8, #0x53f]
uint64_t fde_sub_040fd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC043E0ULL) << 32) | 0x97FF02F3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x040FD4ULL;
}

// Func #1310 | PC: 0x041024..0x041064 (64 B) | Symbol: sub_041024
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x100]; str x0, [x28, #0x170]; adrp x9, #0x9d000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x100]; str x0, [x28, #0x170]; adrp x9, #0x9d000]
uint64_t fde_sub_041024(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC043E0ULL) << 32) | 0x97FF02DFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041024ULL;
}

// Func #1311 | PC: 0x0410b8..0x0410f8 (64 B) | Symbol: sub_0410b8
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc90]; adrp x8, #0x9d000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc90]; adrp x8, #0x9d000]
uint64_t fde_sub_0410b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00002A8ULL) << 32) | 0x97FF02BAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0410B8ULL;
}

// Func #1312 | PC: 0x041110..0x041150 (64 B) | Symbol: sub_041110
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x90]; str x0, [x28, #0x2f0]; adrp x9, #0x9d000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x90]; str x0, [x28, #0x2f0]; adrp x9, #0x9d000]
uint64_t fde_sub_041110(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC027E0ULL) << 32) | 0x97FF02A4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041110ULL;
}

// Func #1313 | PC: 0x041374..0x0413b4 (64 B) | Symbol: sub_041374
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9d000; add x9, x9, #0x5c9; adrp x8, #0x97000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9d000; add x9, x9, #0x5c9; adrp x8, #0x97000]
uint64_t fde_sub_041374(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900002E9ULL) << 32) | 0x97FF020BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041374ULL;
}

// Func #1314 | PC: 0x0413ac..0x0413ec (64 B) | Symbol: sub_0413ac
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xd0]; add x8, sp, #1, lsl #12; add x8, x8, #0xa89] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xd0]; add x8, sp, #1, lsl #12; add x8, x8, #0xa89]
uint64_t fde_sub_0413ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC037E0ULL) << 32) | 0x97FF01FDULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0413ACULL;
}

// Func #1315 | PC: 0x04143c..0x04147c (64 B) | Symbol: sub_04143c
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x100]; str x0, [sp, #0x1c10]; ldr x19, [sp, #0xb8]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x100]; str x0, [sp, #0x1c10]; ldr x19, [sp, #0xb8]]
uint64_t fde_sub_04143c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC043E0ULL) << 32) | 0x97FF01D9ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04143CULL;
}

// Func #1316 | PC: 0x041464..0x0414a4 (64 B) | Symbol: sub_041464
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x100]; add x8, sp, #1, lsl #12; add x8, x8, #0xb19] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x100]; add x8, sp, #1, lsl #12; add x8, x8, #0xb19]
uint64_t fde_sub_041464(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC043E0ULL) << 32) | 0x97FF01CFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041464ULL;
}

// Func #1317 | PC: 0x041500..0x041540 (64 B) | Symbol: sub_041500
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x598; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x598; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_041500(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911663E0ULL) << 32) | 0x94011F7DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041500ULL;
}

// Func #1318 | PC: 0x041508..0x041548 (64 B) | Symbol: sub_041508
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x4151c; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x4151c; subs x19, x19, #0x30]
uint64_t fde_sub_041508(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x940117D9ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041508ULL;
}

// Func #1319 | PC: 0x041538..0x041578 (64 B) | Symbol: sub_041538
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x41514; add x8, x26, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x20, #-0x30]; tbz w8, #0, #0x41514; add x8, x26, x19]
uint64_t fde_sub_041538(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D0288ULL) << 32) | 0x97FF0166ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041538ULL;
}

// Func #1320 | PC: 0x04154c..0x04158c (64 B) | Symbol: sub_04154c
// EN: AArch64 prologue [bl #0x1ad0; b #0x41514; adrp x0, #0xda000; add x0, x0, #0x70] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x41514; adrp x0, #0xda000; add x0, x0, #0x70]
uint64_t fde_sub_04154c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FF0161ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04154CULL;
}

// Func #1321 | PC: 0x04155c..0x04159c (64 B) | Symbol: sub_04155c
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xe8]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xe8]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_04155c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94077F3ULL) << 32) | 0x97FF0165ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04155CULL;
}

// Func #1322 | PC: 0x041598..0x0415d8 (64 B) | Symbol: sub_041598
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_041598(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FF018AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041598ULL;
}

// Func #1323 | PC: 0x04159c..0x04339c (7680 B) | Symbol: rex_locale_init_ctor_32
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_04159c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04159CULL;
}

// Func #1324 | PC: 0x0415b8..0x0415f8 (64 B) | Symbol: sub_0415b8
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xcc0; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xcc0; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_0415b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD13303FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0415B8ULL;
}

// Func #1325 | PC: 0x0415bc..0x0415fc (64 B) | Symbol: sub_0415bc
// EN: AArch64 prologue [sub sp, sp, #0xcc0; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xcc0; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_0415bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD13303FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0415BCULL;
}

// Func #1326 | PC: 0x0415e4..0x041624 (64 B) | Symbol: sub_0415e4
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x434c4; str x19, [sp, #0xe8]; movi v0.2d, #0000000000000000] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x434c4; str x19, [sp, #0xe8]; movi v0.2d, #0000000000000000]
uint64_t fde_sub_0415e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3400F6E0ULL) << 32) | 0x97FF0187ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0415E4ULL;
}

// Func #1327 | PC: 0x04181c..0x04185c (64 B) | Symbol: sub_04181c
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc60]; adrp x8, #0x9d000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q0, [x8, #0xc60]; adrp x8, #0x9d000]
uint64_t fde_sub_04181c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00002A8ULL) << 32) | 0x97FF00E1ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04181CULL;
}

// Func #1328 | PC: 0x041a70..0x041ab0 (64 B) | Symbol: sub_041a70
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x120]; str x0, [sp, #0x7f0]; add x9, sp, #0x6f9] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x120]; str x0, [sp, #0x7f0]; add x9, sp, #0x6f9]
uint64_t fde_sub_041a70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC04BE0ULL) << 32) | 0x97FF004CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041A70ULL;
}

// Func #1329 | PC: 0x041ac0..0x041b00 (64 B) | Symbol: sub_041ac0
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9d000; add x9, x9, #0x69e; adrp x8, #0x97000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9d000; add x9, x9, #0x69e; adrp x8, #0x97000]
uint64_t fde_sub_041ac0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900002E9ULL) << 32) | 0x97FF0038ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041AC0ULL;
}

// Func #1330 | PC: 0x041afc..0x041b3c (64 B) | Symbol: sub_041afc
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9d000; add x9, x9, #0x6c3; adrp x8, #0x97000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9d000; add x9, x9, #0x6c3; adrp x8, #0x97000]
uint64_t fde_sub_041afc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900002E9ULL) << 32) | 0x97FF0029ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041AFCULL;
}

// Func #1331 | PC: 0x041b38..0x041b78 (64 B) | Symbol: sub_041b38
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9d000; add x9, x9, #0x6df; adrp x8, #0x97000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9d000; add x9, x9, #0x6df; adrp x8, #0x97000]
uint64_t fde_sub_041b38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900002E9ULL) << 32) | 0x97FF001AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041B38ULL;
}

// Func #1332 | PC: 0x041b70..0x041bb0 (64 B) | Symbol: sub_041b70
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x9d000; add x8, x8, #0x701; ldr x9, [x8, #0x10]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x9d000; add x8, x8, #0x701; ldr x9, [x8, #0x10]]
uint64_t fde_sub_041b70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900002E8ULL) << 32) | 0x97FF000CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041B70ULL;
}

// Func #1333 | PC: 0x041ba4..0x041be4 (64 B) | Symbol: sub_041ba4
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9d000; add x9, x9, #0x71a; adrp x8, #0x97000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9d000; add x9, x9, #0x71a; adrp x8, #0x97000]
uint64_t fde_sub_041ba4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900002E9ULL) << 32) | 0x97FEFFFFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041BA4ULL;
}

// Func #1334 | PC: 0x041bdc..0x041c1c (64 B) | Symbol: sub_041bdc
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9d000; add x9, x9, #0x748; adrp x8, #0x97000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9d000; add x9, x9, #0x748; adrp x8, #0x97000]
uint64_t fde_sub_041bdc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900002E9ULL) << 32) | 0x97FEFFF1ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041BDCULL;
}

// Func #1335 | PC: 0x041c18..0x041c58 (64 B) | Symbol: sub_041c18
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x110]; str x0, [sp, #0x8b0]; adrp x8, #0x9d000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x110]; str x0, [sp, #0x8b0]; adrp x8, #0x9d000]
uint64_t fde_sub_041c18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC047E0ULL) << 32) | 0x97FEFFE2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041C18ULL;
}

// Func #1336 | PC: 0x041d14..0x041d54 (64 B) | Symbol: sub_041d14
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x100]; add x8, sp, #0x819; adrp x11, #0x9d000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x100]; add x8, sp, #0x819; adrp x11, #0x9d000]
uint64_t fde_sub_041d14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC043E0ULL) << 32) | 0x97FEFFA3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x041D14ULL;
}

// Func #1337 | PC: 0x0420c0..0x042100 (64 B) | Symbol: sub_0420c0
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9d000; add x9, x9, #0x7ab; adrp x8, #0x97000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9d000; add x9, x9, #0x7ab; adrp x8, #0x97000]
uint64_t fde_sub_0420c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00002C9ULL) << 32) | 0x97FEFEB8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0420C0ULL;
}

// Func #1338 | PC: 0x042180..0x0421c0 (64 B) | Symbol: sub_042180
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x120]; add x9, x20, #0x180; str x0, [sp, #0x2b0]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x120]; add x9, x20, #0x180; str x0, [sp, #0x2b0]]
uint64_t fde_sub_042180(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC04BE0ULL) << 32) | 0x97FEFE88ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042180ULL;
}

// Func #1339 | PC: 0x0422a0..0x0422e0 (64 B) | Symbol: sub_0422a0
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xd80]; mov x11, #0x4848] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x97000; ldr q0, [x9, #0xd80]; mov x11, #0x4848]
uint64_t fde_sub_0422a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00002A9ULL) << 32) | 0x97FEFE40ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0422A0ULL;
}

// Func #1340 | PC: 0x042718..0x042758 (64 B) | Symbol: sub_042718
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_042718(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x9401181AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042718ULL;
}

// Func #1341 | PC: 0x042728..0x042768 (64 B) | Symbol: sub_042728
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_042728(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x94011816ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042728ULL;
}

// Func #1342 | PC: 0x042738..0x042778 (64 B) | Symbol: sub_042738
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_042738(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x94011812ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042738ULL;
}

// Func #1343 | PC: 0x042748..0x042788 (64 B) | Symbol: sub_042748
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x80]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_042748(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94043E1ULL) << 32) | 0x9401180EULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042748ULL;
}

// Func #1344 | PC: 0x042758..0x042798 (64 B) | Symbol: sub_042758
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_042758(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x9401180AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042758ULL;
}

// Func #1345 | PC: 0x042768..0x0427a8 (64 B) | Symbol: sub_042768
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_042768(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x94011806ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042768ULL;
}

// Func #1346 | PC: 0x042778..0x0427b8 (64 B) | Symbol: sub_042778
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_042778(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x94011802ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042778ULL;
}

// Func #1347 | PC: 0x042788..0x0427c8 (64 B) | Symbol: sub_042788
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_042788(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x940117FEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042788ULL;
}

// Func #1348 | PC: 0x042798..0x0427d8 (64 B) | Symbol: sub_042798
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_042798(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x940117FAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042798ULL;
}

// Func #1349 | PC: 0x0427a8..0x0427e8 (64 B) | Symbol: sub_0427a8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0427a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x940117F6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0427A8ULL;
}

// Func #1350 | PC: 0x0427b8..0x0427f8 (64 B) | Symbol: sub_0427b8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0427b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x940117F2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0427B8ULL;
}

// Func #1351 | PC: 0x0427c8..0x042808 (64 B) | Symbol: sub_0427c8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0427c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x940117EEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0427C8ULL;
}

// Func #1352 | PC: 0x0427d8..0x042818 (64 B) | Symbol: sub_0427d8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0427d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x940117EAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0427D8ULL;
}

// Func #1353 | PC: 0x0427e8..0x042828 (64 B) | Symbol: sub_0427e8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0427e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x940117E6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0427E8ULL;
}

// Func #1354 | PC: 0x0427f8..0x042838 (64 B) | Symbol: sub_0427f8
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0427f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x940117E2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0427F8ULL;
}

// Func #1355 | PC: 0x042808..0x042848 (64 B) | Symbol: sub_042808
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_042808(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x940117DEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042808ULL;
}

// Func #1356 | PC: 0x042818..0x042858 (64 B) | Symbol: sub_042818
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_042818(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94003E1ULL) << 32) | 0x940117DAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042818ULL;
}

// Func #1357 | PC: 0x042828..0x042868 (64 B) | Symbol: sub_042828
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26]
uint64_t fde_sub_042828(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x940117D6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042828ULL;
}

// Func #1358 | PC: 0x042838..0x042878 (64 B) | Symbol: sub_042838
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x28; mov x2, x28] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x28; mov x2, x28]
uint64_t fde_sub_042838(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x940117D2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042838ULL;
}

// Func #1359 | PC: 0x042848..0x042888 (64 B) | Symbol: sub_042848
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x23; mov x2, x23]
uint64_t fde_sub_042848(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x940117CEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042848ULL;
}

// Func #1360 | PC: 0x042858..0x042898 (64 B) | Symbol: sub_042858
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_042858(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x940117CAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042858ULL;
}

// Func #1361 | PC: 0x042868..0x0428a8 (64 B) | Symbol: sub_042868
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x24; mov x2, x24] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x24; mov x2, x24]
uint64_t fde_sub_042868(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x940117C6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042868ULL;
}

// Func #1362 | PC: 0x042878..0x0428b8 (64 B) | Symbol: sub_042878
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x22; mov x2, x22]
uint64_t fde_sub_042878(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x940117C2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042878ULL;
}

// Func #1363 | PC: 0x042888..0x0428c8 (64 B) | Symbol: sub_042888
// EN: AArch64 prologue [bl #0x88780; add x11, sp, #0x5b8; movi v0.2d, #0000000000000000; add x9, sp, #0x939] | VI: Khởi đầu hàm AArch64 [bl #0x88780; add x11, sp, #0x5b8; movi v0.2d, #0000000000000000; add x9, sp, #0x939]
uint64_t fde_sub_042888(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9116E3EBULL) << 32) | 0x940117BEULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042888ULL;
}

// Func #1364 | PC: 0x042934..0x042974 (64 B) | Symbol: sub_042934
// EN: AArch64 prologue [bl #0x1ba0; ldr x22, [sp, #0xa8]; ldr q0, [sp, #0x110]; adrp x8, #0x9d000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr x22, [sp, #0xa8]; ldr q0, [sp, #0x110]; adrp x8, #0x9d000]
uint64_t fde_sub_042934(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94057F6ULL) << 32) | 0x97FEFC9BULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042934ULL;
}

// Func #1365 | PC: 0x0429a0..0x0429e0 (64 B) | Symbol: sub_0429a0
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x9d000; add x8, x8, #0x837; ldp q0, q1, [x8]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x9d000; add x8, x8, #0x837; ldp q0, q1, [x8]]
uint64_t fde_sub_0429a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00002C8ULL) << 32) | 0x97FEFC80ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0429A0ULL;
}

// Func #1366 | PC: 0x0429d0..0x042a10 (64 B) | Symbol: sub_0429d0
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x110]; add x8, sp, #0x9f9; add x10, sp, #0x5b8] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x110]; add x8, sp, #0x9f9; add x10, sp, #0x5b8]
uint64_t fde_sub_0429d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC047E0ULL) << 32) | 0x97FEFC74ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0429D0ULL;
}

// Func #1367 | PC: 0x042af8..0x042b38 (64 B) | Symbol: sub_042af8
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x9d000; add x8, x8, #0x8ab; ldr q0, [sp, #0x120]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x9d000; add x8, x8, #0x8ab; ldr q0, [sp, #0x120]]
uint64_t fde_sub_042af8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00002C8ULL) << 32) | 0x97FEFC2AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042AF8ULL;
}

// Func #1368 | PC: 0x042d08..0x042d48 (64 B) | Symbol: sub_042d08
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x100]; adrp x8, #0x9d000; add x8, x8, #0x8f1] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x100]; adrp x8, #0x9d000; add x8, x8, #0x8f1]
uint64_t fde_sub_042d08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC043E0ULL) << 32) | 0x97FEFBA6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042D08ULL;
}

// Func #1369 | PC: 0x042dd8..0x042e18 (64 B) | Symbol: sub_042dd8
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xd0]; adrp x8, #0x9d000; add x8, x8, #0x923] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xd0]; adrp x8, #0x9d000; add x8, x8, #0x923]
uint64_t fde_sub_042dd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC037E0ULL) << 32) | 0x97FEFB72ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042DD8ULL;
}

// Func #1370 | PC: 0x042e38..0x042e78 (64 B) | Symbol: sub_042e38
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x100]; adrp x8, #0x9d000; add x8, x8, #0x948] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x100]; adrp x8, #0x9d000; add x8, x8, #0x948]
uint64_t fde_sub_042e38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC043E0ULL) << 32) | 0x97FEFB5AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042E38ULL;
}

// Func #1371 | PC: 0x042e94..0x042ed4 (64 B) | Symbol: sub_042e94
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x110]; adrp x8, #0x9d000; add x8, x8, #0x967] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x110]; adrp x8, #0x9d000; add x8, x8, #0x967]
uint64_t fde_sub_042e94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC047E0ULL) << 32) | 0x97FEFB43ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042E94ULL;
}

// Func #1372 | PC: 0x042ef0..0x042f30 (64 B) | Symbol: sub_042ef0
// EN: AArch64 prologue [bl #0x1ba0; mov w8, #0x21; str x8, [sp, #0x14b0]; adrp x8, #0x9d000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; mov w8, #0x21; str x8, [sp, #0x14b0]; adrp x8, #0x9d000]
uint64_t fde_sub_042ef0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800428ULL) << 32) | 0x97FEFB2CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042EF0ULL;
}

// Func #1373 | PC: 0x042f50..0x042f90 (64 B) | Symbol: sub_042f50
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xf0]; adrp x9, #0x9d000; add x9, x9, #0x9a2] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xf0]; adrp x9, #0x9d000; add x9, x9, #0x9a2]
uint64_t fde_sub_042f50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03FE0ULL) << 32) | 0x97FEFB14ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042F50ULL;
}

// Func #1374 | PC: 0x042fb4..0x042ff4 (64 B) | Symbol: sub_042fb4
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x110]; adrp x8, #0x9d000; add x8, x8, #0x9c4] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x110]; adrp x8, #0x9d000; add x8, x8, #0x9c4]
uint64_t fde_sub_042fb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC047E0ULL) << 32) | 0x97FEFAFBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x042FB4ULL;
}

// Func #1375 | PC: 0x043064..0x0430a4 (64 B) | Symbol: sub_043064
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xf0]; adrp x8, #0x9d000; add x8, x8, #0x9f3] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xf0]; adrp x8, #0x9d000; add x8, x8, #0x9f3]
uint64_t fde_sub_043064(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC03FE0ULL) << 32) | 0x97FEFACFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043064ULL;
}

// Func #1376 | PC: 0x0430c0..0x043100 (64 B) | Symbol: sub_0430c0
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x120]; adrp x8, #0x9d000; add x8, x8, #0xa15] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x120]; adrp x8, #0x9d000; add x8, x8, #0xa15]
uint64_t fde_sub_0430c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC04BE0ULL) << 32) | 0x97FEFAB8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0430C0ULL;
}

// Func #1377 | PC: 0x04311c..0x04315c (64 B) | Symbol: sub_04311c
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x120]; adrp x8, #0x9d000; add x8, x8, #0xa2e] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x120]; adrp x8, #0x9d000; add x8, x8, #0xa2e]
uint64_t fde_sub_04311c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC04BE0ULL) << 32) | 0x97FEFAA1ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04311CULL;
}

// Func #1378 | PC: 0x043178..0x0431b8 (64 B) | Symbol: sub_043178
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x120]; adrp x8, #0x9d000; add x8, x8, #0xa47] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x120]; adrp x8, #0x9d000; add x8, x8, #0xa47]
uint64_t fde_sub_043178(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC04BE0ULL) << 32) | 0x97FEFA8AULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043178ULL;
}

// Func #1379 | PC: 0x0431d4..0x043214 (64 B) | Symbol: sub_0431d4
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0x100]; mov w13, #0x14; str x0, [x22, #0x530]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0x100]; mov w13, #0x14; str x0, [x22, #0x530]]
uint64_t fde_sub_0431d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC043E0ULL) << 32) | 0x97FEFA73ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0431D4ULL;
}

// Func #1380 | PC: 0x043460..0x0434a0 (64 B) | Symbol: sub_043460
// EN: AArch64 prologue [bl #0x892f4; add x0, sp, #0x5b8; bl #0x8746c; mov w19, #0x480] | VI: Khởi đầu hàm AArch64 [bl #0x892f4; add x0, sp, #0x5b8; bl #0x8746c; mov w19, #0x480]
uint64_t fde_sub_043460(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9116E3E0ULL) << 32) | 0x940117A5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043460ULL;
}

// Func #1381 | PC: 0x043468..0x0434a8 (64 B) | Symbol: sub_043468
// EN: AArch64 prologue [bl #0x8746c; mov w19, #0x480; b #0x4347c; subs x19, x19, #0x30] | VI: Khởi đầu hàm AArch64 [bl #0x8746c; mov w19, #0x480; b #0x4347c; subs x19, x19, #0x30]
uint64_t fde_sub_043468(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52809013ULL) << 32) | 0x94011001ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043468ULL;
}

// Func #1382 | PC: 0x043498..0x0434d8 (64 B) | Symbol: sub_043498
// EN: AArch64 prologue [bl #0x1ad0; ldurb w8, [x21, #-0x30]; tbz w8, #0, #0x43474; add x8, x20, x19] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; ldurb w8, [x21, #-0x30]; tbz w8, #0, #0x43474; add x8, x20, x19]
uint64_t fde_sub_043498(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x385D02A8ULL) << 32) | 0x97FEF98EULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043498ULL;
}

// Func #1383 | PC: 0x0434ac..0x0434ec (64 B) | Symbol: sub_0434ac
// EN: AArch64 prologue [bl #0x1ad0; b #0x43474; adrp x0, #0xdb000; add x0, x0, #0x770] | VI: Khởi đầu hàm AArch64 [bl #0x1ad0; b #0x43474; adrp x0, #0xdb000; add x0, x0, #0x770]
uint64_t fde_sub_0434ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF1ULL) << 32) | 0x97FEF989ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0434ACULL;
}

// Func #1384 | PC: 0x0434bc..0x0434fc (64 B) | Symbol: sub_0434bc
// EN: AArch64 prologue [bl #0x1af0; ldr x19, [sp, #0xe8]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [bl #0x1af0; ldr x19, [sp, #0xe8]; ldr x8, [x19, #0x28]; ldur x9, [x29, #-0x60]]
uint64_t fde_sub_0434bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94077F3ULL) << 32) | 0x97FEF98DULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0434BCULL;
}

// Func #1385 | PC: 0x0434f8..0x043538 (64 B) | Symbol: sub_0434f8
// EN: AArch64 prologue [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [bl #0x1bc0; stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]]
uint64_t fde_sub_0434f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BA6FFCULL) << 32) | 0x97FEF9B2ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0434F8ULL;
}

// Func #1386 | PC: 0x0434fc..0x0452fc (7680 B) | Symbol: rex_locale_init_ctor_33
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0434fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0434FCULL;
}

// Func #1387 | PC: 0x043518..0x043558 (64 B) | Symbol: sub_043518
// EN: AArch64 prologue [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc70; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #1, lsl #12; sub sp, sp, #0xc70; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_043518(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD131C3FFULL) << 32) | 0xD14007FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043518ULL;
}

// Func #1388 | PC: 0x04351c..0x04355c (64 B) | Symbol: sub_04351c
// EN: AArch64 prologue [sub sp, sp, #0xc70; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc70; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]; stur x8, [x29, #-0x60]]
uint64_t fde_sub_04351c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD53BD053ULL) << 32) | 0xD131C3FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04351CULL;
}

// Func #1389 | PC: 0x043544..0x043584 (64 B) | Symbol: sub_043544
// EN: AArch64 prologue [bl #0x1c00; cbz w0, #0x456dc; add x12, sp, #0x568; mov w8, #0x1620] | VI: Khởi đầu hàm AArch64 [bl #0x1c00; cbz w0, #0x456dc; add x12, sp, #0x568; mov w8, #0x1620]
uint64_t fde_sub_043544(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34010CA0ULL) << 32) | 0x97FEF9AFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043544ULL;
}

// Func #1390 | PC: 0x0435c8..0x043608 (64 B) | Symbol: sub_0435c8
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9d000; add x9, x9, #0xaae; ldr q0, [x9]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9d000; add x9, x9, #0xaae; ldr q0, [x9]]
uint64_t fde_sub_0435c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00002C9ULL) << 32) | 0x97FEF976ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0435C8ULL;
}

// Func #1391 | PC: 0x043714..0x043754 (64 B) | Symbol: sub_043714
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9d000; add x9, x9, #0xb24; adrp x8, #0x97000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9d000; add x9, x9, #0xb24; adrp x8, #0x97000]
uint64_t fde_sub_043714(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00002C9ULL) << 32) | 0x97FEF923ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043714ULL;
}

// Func #1392 | PC: 0x04374c..0x04378c (64 B) | Symbol: sub_04374c
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xc0]; add x8, sp, #0x559; str xzr, [sp, #0x680]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xc0]; add x8, sp, #0x559; str xzr, [sp, #0x680]]
uint64_t fde_sub_04374c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC033E0ULL) << 32) | 0x97FEF915ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04374CULL;
}

// Func #1393 | PC: 0x0437bc..0x0437fc (64 B) | Symbol: sub_0437bc
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xc0]; add x8, sp, #0x589; str x0, [sp, #0x698]] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xc0]; add x8, sp, #0x589; str x0, [sp, #0x698]]
uint64_t fde_sub_0437bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC033E0ULL) << 32) | 0x97FEF8F9ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0437BCULL;
}

// Func #1394 | PC: 0x043b18..0x043b58 (64 B) | Symbol: sub_043b18
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xc0]; adrp x11, #0x9d000; add x8, sp, #0x739] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xc0]; adrp x11, #0x9d000; add x8, sp, #0x739]
uint64_t fde_sub_043b18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC033E0ULL) << 32) | 0x97FEF822ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043B18ULL;
}

// Func #1395 | PC: 0x043ff4..0x044034 (64 B) | Symbol: sub_043ff4
// EN: AArch64 prologue [bl #0x1ba0; adrp x9, #0x9d000; add x9, x9, #0xd13; adrp x8, #0x97000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x9, #0x9d000; add x9, x9, #0xd13; adrp x8, #0x97000]
uint64_t fde_sub_043ff4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00002C9ULL) << 32) | 0x97FEF6EBULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x043FF4ULL;
}

// Func #1396 | PC: 0x0440b8..0x0440f8 (64 B) | Symbol: sub_0440b8
// EN: AArch64 prologue [bl #0x1ba0; ldr q0, [sp, #0xc0]; adrp x15, #0x97000; add x15, x15, #0xee4] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; ldr q0, [sp, #0xc0]; adrp x15, #0x97000; add x15, x15, #0xee4]
uint64_t fde_sub_0440b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC033E0ULL) << 32) | 0x97FEF6BAULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0440B8ULL;
}

// Func #1397 | PC: 0x044640..0x044680 (64 B) | Symbol: sub_044640
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x90]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_044640(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9404BE1ULL) << 32) | 0x94011050ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044640ULL;
}

// Func #1398 | PC: 0x044650..0x044690 (64 B) | Symbol: sub_044650
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x78]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_044650(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403FE1ULL) << 32) | 0x9401104CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044650ULL;
}

// Func #1399 | PC: 0x044660..0x0446a0 (64 B) | Symbol: sub_044660
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x68]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_044660(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94037E1ULL) << 32) | 0x94011048ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044660ULL;
}

// Func #1400 | PC: 0x044670..0x0446b0 (64 B) | Symbol: sub_044670
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x70]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_044670(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403BE1ULL) << 32) | 0x94011044ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044670ULL;
}

// Func #1401 | PC: 0x044680..0x0446c0 (64 B) | Symbol: sub_044680
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x60]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_044680(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94033E1ULL) << 32) | 0x94011040ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044680ULL;
}

// Func #1402 | PC: 0x044690..0x0446d0 (64 B) | Symbol: sub_044690
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x50]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_044690(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402BE1ULL) << 32) | 0x9401103CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044690ULL;
}

// Func #1403 | PC: 0x0446a0..0x0446e0 (64 B) | Symbol: sub_0446a0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x58]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0446a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402FE1ULL) << 32) | 0x94011038ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0446A0ULL;
}

// Func #1404 | PC: 0x0446b0..0x0446f0 (64 B) | Symbol: sub_0446b0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x10]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0446b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400BE1ULL) << 32) | 0x94011034ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0446B0ULL;
}

// Func #1405 | PC: 0x0446c0..0x044700 (64 B) | Symbol: sub_0446c0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x18]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0446c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400FE1ULL) << 32) | 0x94011030ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0446C0ULL;
}

// Func #1406 | PC: 0x0446d0..0x044710 (64 B) | Symbol: sub_0446d0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0xc0]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0xc0]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0446d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94063E1ULL) << 32) | 0x9401102CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0446D0ULL;
}

// Func #1407 | PC: 0x0446e0..0x044720 (64 B) | Symbol: sub_0446e0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0xa0]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0xa0]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0446e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94053E1ULL) << 32) | 0x94011028ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0446E0ULL;
}

// Func #1408 | PC: 0x0446f0..0x044730 (64 B) | Symbol: sub_0446f0
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x48]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_0446f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94027E1ULL) << 32) | 0x94011024ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0446F0ULL;
}

// Func #1409 | PC: 0x044700..0x044740 (64 B) | Symbol: sub_044700
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x40]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_044700(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94023E1ULL) << 32) | 0x94011020ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044700ULL;
}

// Func #1410 | PC: 0x044710..0x044750 (64 B) | Symbol: sub_044710
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x38]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_044710(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401FE1ULL) << 32) | 0x9401101CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044710ULL;
}

// Func #1411 | PC: 0x044720..0x044760 (64 B) | Symbol: sub_044720
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x30]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_044720(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401BE1ULL) << 32) | 0x94011018ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044720ULL;
}

// Func #1412 | PC: 0x044730..0x044770 (64 B) | Symbol: sub_044730
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x28]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_044730(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94017E1ULL) << 32) | 0x94011014ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044730ULL;
}

// Func #1413 | PC: 0x044740..0x044780 (64 B) | Symbol: sub_044740
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #8]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_044740(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94007E1ULL) << 32) | 0x94011010ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044740ULL;
}

// Func #1414 | PC: 0x044750..0x044790 (64 B) | Symbol: sub_044750
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x26; mov x2, x26]
uint64_t fde_sub_044750(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x9401100CULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044750ULL;
}

// Func #1415 | PC: 0x044760..0x0447a0 (64 B) | Symbol: sub_044760
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x21; mov x2, x21] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x21; mov x2, x21]
uint64_t fde_sub_044760(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94011008ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044760ULL;
}

// Func #1416 | PC: 0x044770..0x0447b0 (64 B) | Symbol: sub_044770
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x28; mov x2, x28] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x28; mov x2, x28]
uint64_t fde_sub_044770(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94011004ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044770ULL;
}

// Func #1417 | PC: 0x044780..0x0447c0 (64 B) | Symbol: sub_044780
// EN: AArch64 prologue [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1] | VI: Khởi đầu hàm AArch64 [bl #0x88780; ldr x1, [sp, #0x20]; mov x0, x19; mov x2, x1]
uint64_t fde_sub_044780(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF94013E1ULL) << 32) | 0x94011000ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044780ULL;
}

// Func #1418 | PC: 0x044790..0x0447d0 (64 B) | Symbol: sub_044790
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x20; mov x2, x20] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x20; mov x2, x20]
uint64_t fde_sub_044790(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94010FFCULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044790ULL;
}

// Func #1419 | PC: 0x0447a0..0x0447e0 (64 B) | Symbol: sub_0447a0
// EN: AArch64 prologue [bl #0x88780; mov x0, x19; mov x1, x27; mov x2, x27] | VI: Khởi đầu hàm AArch64 [bl #0x88780; mov x0, x19; mov x1, x27; mov x2, x27]
uint64_t fde_sub_0447a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1303E0ULL) << 32) | 0x94010FF8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0447A0ULL;
}

// Func #1420 | PC: 0x0447b0..0x0447f0 (64 B) | Symbol: sub_0447b0
// EN: AArch64 prologue [bl #0x88780; movi v1.2d, #0000000000000000; add x9, sp, #0x8e9; add x8, x24, #0x478] | VI: Khởi đầu hàm AArch64 [bl #0x88780; movi v1.2d, #0000000000000000; add x9, sp, #0x8e9; add x8, x24, #0x478]
uint64_t fde_sub_0447b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6F00E401ULL) << 32) | 0x94010FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0447B0ULL;
}

// Func #1421 | PC: 0x044c64..0x044ca4 (64 B) | Symbol: sub_044c64
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q2, [x8, #0xd10]; adrp x8, #0x9d000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q2, [x8, #0xd10]; adrp x8, #0x9d000]
uint64_t fde_sub_044c64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000288ULL) << 32) | 0x97FEF3CFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044C64ULL;
}

// Func #1422 | PC: 0x044ccc..0x044d0c (64 B) | Symbol: sub_044ccc
// EN: AArch64 prologue [bl #0x1ba0; adrp x8, #0x97000; ldr q2, [x8, #0xd50]; adrp x8, #0x9d000] | VI: Khởi đầu hàm AArch64 [bl #0x1ba0; adrp x8, #0x97000; ldr q2, [x8, #0xd50]; adrp x8, #0x9d000]
uint64_t fde_sub_044ccc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000288ULL) << 32) | 0x97FEF3B5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x044CCCULL;
}

// Func #1423 | PC: 0x045714..0x047514 (7680 B) | Symbol: rex_locale_init_ctor_34
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_045714(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x045714ULL;
}

// Func #1424 | PC: 0x047358..0x049158 (7680 B) | Symbol: rex_locale_init_ctor_35
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_047358(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x047358ULL;
}

// Func #1425 | PC: 0x049374..0x04b174 (7680 B) | Symbol: rex_locale_init_ctor_36
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_049374(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049374ULL;
}

// Func #1426 | PC: 0x04b4c0..0x04d2c0 (7680 B) | Symbol: rex_locale_init_ctor_37
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_04b4c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B4C0ULL;
}

// Func #1427 | PC: 0x04d670..0x04f470 (7680 B) | Symbol: rex_locale_init_ctor_38
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_04d670(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D670ULL;
}

// Func #1428 | PC: 0x04f910..0x051710 (7680 B) | Symbol: rex_locale_init_ctor_39
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_04f910(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F910ULL;
}

// Func #1429 | PC: 0x051514..0x053314 (7680 B) | Symbol: rex_locale_init_ctor_40
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_051514(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051514ULL;
}

// Func #1430 | PC: 0x053458..0x055258 (7680 B) | Symbol: rex_locale_init_ctor_41
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_053458(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053458ULL;
}

// Func #1431 | PC: 0x0551b4..0x056fb4 (7680 B) | Symbol: rex_locale_init_ctor_42
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0551b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0551B4ULL;
}

// Func #1432 | PC: 0x056fd0..0x058dd0 (7680 B) | Symbol: rex_locale_init_ctor_43
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_056fd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056FD0ULL;
}

// Func #1433 | PC: 0x0591c8..0x05afc8 (7680 B) | Symbol: rex_locale_init_ctor_44
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0591c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0591C8ULL;
}

// Func #1434 | PC: 0x05b314..0x05d114 (7680 B) | Symbol: rex_locale_init_ctor_45
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_05b314(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B314ULL;
}

// Func #1435 | PC: 0x05d77c..0x05f57c (7680 B) | Symbol: rex_locale_init_ctor_46
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_05d77c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D77CULL;
}

// Func #1436 | PC: 0x05f6cc..0x0614cc (7680 B) | Symbol: rex_locale_init_ctor_47
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_05f6cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F6CCULL;
}

// Func #1437 | PC: 0x061624..0x063424 (7680 B) | Symbol: rex_locale_init_ctor_48
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_061624(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061624ULL;
}

// Func #1438 | PC: 0x063574..0x065374 (7680 B) | Symbol: rex_locale_init_ctor_49
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_063574(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063574ULL;
}

// Func #1439 | PC: 0x065778..0x067578 (7680 B) | Symbol: rex_locale_init_ctor_50
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_065778(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065778ULL;
}

// Func #1440 | PC: 0x067ae0..0x0698e0 (7680 B) | Symbol: rex_locale_init_ctor_51
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_067ae0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067AE0ULL;
}

// Func #1441 | PC: 0x069d88..0x06bb88 (7680 B) | Symbol: rex_locale_init_ctor_52
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_069d88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069D88ULL;
}

// Func #1442 | PC: 0x06c174..0x06df74 (7680 B) | Symbol: rex_locale_init_ctor_53
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_06c174(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C174ULL;
}

// Func #1443 | PC: 0x06e090..0x06fe90 (7680 B) | Symbol: rex_locale_init_ctor_54
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_06e090(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E090ULL;
}

// Func #1444 | PC: 0x06fe78..0x071c78 (7680 B) | Symbol: rex_locale_init_ctor_55
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_06fe78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FE78ULL;
}

// Func #1445 | PC: 0x071d84..0x073b84 (7680 B) | Symbol: rex_locale_init_ctor_56
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_071d84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071D84ULL;
}

// Func #1446 | PC: 0x073f98..0x075d98 (7680 B) | Symbol: rex_locale_init_ctor_57
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_073f98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073F98ULL;
}

// Func #1447 | PC: 0x076264..0x078064 (7680 B) | Symbol: rex_locale_init_ctor_58
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_076264(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x076264ULL;
}

// Func #1448 | PC: 0x078030..0x079e30 (7680 B) | Symbol: rex_locale_init_ctor_59
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_078030(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x078030ULL;
}

// Func #1449 | PC: 0x079e60..0x07bc60 (7680 B) | Symbol: rex_locale_init_ctor_60
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_079e60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x079E60ULL;
}

// Func #1450 | PC: 0x07c320..0x07e120 (7680 B) | Symbol: rex_locale_init_ctor_61
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_07c320(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07C320ULL;
}

// Func #1451 | PC: 0x07e198..0x07ff98 (7680 B) | Symbol: rex_locale_init_ctor_62
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_07e198(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07E198ULL;
}

// Func #1452 | PC: 0x07ff80..0x081d80 (7680 B) | Symbol: rex_locale_init_ctor_63
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_07ff80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07FF80ULL;
}

// Func #1453 | PC: 0x081c7c..0x083a7c (7680 B) | Symbol: rex_locale_init_ctor_64
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_081c7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x081C7CULL;
}

// Func #1454 | PC: 0x083908..0x085708 (7680 B) | Symbol: rex_locale_init_ctor_65
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_083908(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x083908ULL;
}

// Func #1455 | PC: 0x0855ec..0x0873ec (7680 B) | Symbol: rex_locale_init_ctor_66
// EN: AArch64 prologue [adrp x1, #0x10a000; adrp x0, #0x8d000; adrp x2, #0xab000; add x1, x1, #0xf70] | VI: Khởi đầu hàm AArch64 [adrp x1, #0x10a000; adrp x0, #0x8d000; adrp x2, #0xab000; add x1, x1, #0xf70]
uint64_t fde_sub_0855ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000040ULL) << 32) | 0xB0000421ULL;
    const uint64_t kPcRange = 0x1E00ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0855ECULL;
}

// Func #1456 | PC: 0x085620..0x087430 (7696 B) | Symbol: sub_085620
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_085620(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1E10ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x085620ULL;
}

// Func #1457 | PC: 0x08746c..0x0876f8 (652 B) | Symbol: sub_08746c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_08746c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x028CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08746CULL;
}

// Func #1458 | PC: 0x0876f8..0x088300 (3080 B) | Symbol: sub_0876f8
// EN: AArch64 prologue [stp x28, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x28, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0876f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57FCULL;
    const uint64_t kPcRange = 0x0C08ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0876F8ULL;
}

// Func #1459 | PC: 0x088300..0x0884cc (460 B) | Symbol: sub_088300
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x198]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x198]]
uint64_t fde_sub_088300(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x01CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088300ULL;
}

// Func #1460 | PC: 0x0884cc..0x088590 (196 B) | Symbol: sub_0884cc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x90]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x90]]
uint64_t fde_sub_0884cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0884CCULL;
}

// Func #1461 | PC: 0x088590..0x0886cc (316 B) | Symbol: sub_088590
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x108]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x108]]
uint64_t fde_sub_088590(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x013CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088590ULL;
}

// Func #1462 | PC: 0x0886cc..0x088780 (180 B) | Symbol: sub_0886cc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0xb8]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0xb8]]
uint64_t fde_sub_0886cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x00B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0886CCULL;
}

// Func #1463 | PC: 0x088780..0x088a7c (764 B) | Symbol: sub_088780
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_088780(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9026FFCULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x02FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088780ULL;
}

// Func #1464 | PC: 0x088a7c..0x088b60 (228 B) | Symbol: sub_088a7c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_088a7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088A7CULL;
}

// Func #1465 | PC: 0x088b60..0x088ee0 (896 B) | Symbol: sub_088b60
// EN: AArch64 prologue [cmp x2, #0x20; b.hi #0x88b7c; cmp x2, #0x10; b.hi #0x88c44] | VI: Khởi đầu hàm AArch64 [cmp x2, #0x20; b.hi #0x88b7c; cmp x2, #0x10; b.hi #0x88c44]
uint64_t fde_sub_088b60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x540000C8ULL) << 32) | 0xF100805FULL;
    const uint64_t kPcRange = 0x0380ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088B60ULL;
}

// Func #1466 | PC: 0x088ee0..0x088fe4 (260 B) | Symbol: sub_088ee0
// EN: AArch64 prologue [cmp x1, #9; mov x8, x0; b.lo #0x88f40; add x9, x8, x1] | VI: Khởi đầu hàm AArch64 [cmp x1, #9; mov x8, x0; b.lo #0x88f40; add x9, x8, x1]
uint64_t fde_sub_088ee0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003E8ULL) << 32) | 0xF100243FULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088EE0ULL;
}

// Func #1467 | PC: 0x088fe4..0x08908c (168 B) | Symbol: sub_088fe4
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_088fe4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x088FE4ULL;
}

// Func #1468 | PC: 0x08908c..0x0892f4 (616 B) | Symbol: sub_08908c
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_08908c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9026FFCULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0268ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08908CULL;
}

// Func #1469 | PC: 0x0892f4..0x089c14 (2336 B) | Symbol: sub_0892f4
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x9, [x1, #0x10]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x9, [x1, #0x10]]
uint64_t fde_sub_0892f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0920ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0892F4ULL;
}

// Func #1470 | PC: 0x089c14..0x08a51c (2312 B) | Symbol: sub_089c14
// EN: AArch64 prologue [strb wzr, [x0]; strb wzr, [x0, #0x18]; ldrb w8, [x1, #0x18]; cbz w8, #0x89c44] | VI: Khởi đầu hàm AArch64 [strb wzr, [x0]; strb wzr, [x0, #0x18]; ldrb w8, [x1, #0x18]; cbz w8, #0x89c44]
uint64_t fde_sub_089c14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3900601FULL) << 32) | 0x3900001FULL;
    const uint64_t kPcRange = 0x0908ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x089C14ULL;
}

// Func #1471 | PC: 0x08a51c..0x08a814 (760 B) | Symbol: sub_08a51c
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_08a51c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9026FFCULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x02F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08A51CULL;
}

// Func #1472 | PC: 0x08a814..0x08a8f8 (228 B) | Symbol: sub_08a814
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_08a814(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08A814ULL;
}

// Func #1473 | PC: 0x08a8f8..0x08ab60 (616 B) | Symbol: sub_08a8f8
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_08a8f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9026FFCULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0268ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08A8F8ULL;
}

// Func #1474 | PC: 0x08ab60..0x08afe8 (1160 B) | Symbol: sub_08ab60
// EN: AArch64 prologue [sub sp, sp, #0x80; str x21, [sp, #0x50]; stp x20, x19, [sp, #0x60]; stp x29, x30, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x21, [sp, #0x50]; stp x20, x19, [sp, #0x60]; stp x29, x30, [sp, #0x70]]
uint64_t fde_sub_08ab60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9002BF5ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0488ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08AB60ULL;
}

// Func #1475 | PC: 0x08afe8..0x08b0a0 (184 B) | Symbol: sub_08afe8
// EN: AArch64 prologue [sub sp, sp, #0x70; str x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]; add x29, sp, #0x60] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]; add x29, sp, #0x60]
uint64_t fde_sub_08afe8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9002BF3ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08AFE8ULL;
}

// Func #1476 | PC: 0x08b0a0..0x08b23c (412 B) | Symbol: sub_08b0a0
// EN: AArch64 prologue [sub sp, sp, #0x60; str x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_08b0a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x019CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B0A0ULL;
}

// Func #1477 | PC: 0x08b23c..0x08b618 (988 B) | Symbol: sub_08b23c
// EN: AArch64 prologue [sub sp, sp, #0xe0; stp x28, x27, [sp, #0x80]; stp x26, x25, [sp, #0x90]; stp x24, x23, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xe0; stp x28, x27, [sp, #0x80]; stp x26, x25, [sp, #0x90]; stp x24, x23, [sp, #0xa0]]
uint64_t fde_sub_08b23c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9086FFCULL) << 32) | 0xD10383FFULL;
    const uint64_t kPcRange = 0x03DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B23CULL;
}

// Func #1478 | PC: 0x08b618..0x08b74c (308 B) | Symbol: sub_08b618
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_08b618(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x0134ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B618ULL;
}

// Func #1479 | PC: 0x08b74c..0x08b834 (232 B) | Symbol: sub_08b74c
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_08b74c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B74CULL;
}

// Func #1480 | PC: 0x08b834..0x08be10 (1500 B) | Symbol: sub_08b834
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_08b834(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9025FF8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x05DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08B834ULL;
}

// Func #1481 | PC: 0x08be10..0x08bf30 (288 B) | Symbol: sub_08be10
// EN: AArch64 prologue [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_08be10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F9ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0120ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BE10ULL;
}

// Func #1482 | PC: 0x08bf30..0x08c134 (516 B) | Symbol: sub_08bf30
// EN: AArch64 prologue [sub sp, sp, #0xe0; str x23, [sp, #0xa0]; stp x22, x21, [sp, #0xb0]; stp x20, x19, [sp, #0xc0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xe0; str x23, [sp, #0xa0]; stp x22, x21, [sp, #0xb0]; stp x20, x19, [sp, #0xc0]]
uint64_t fde_sub_08bf30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90053F7ULL) << 32) | 0xD10383FFULL;
    const uint64_t kPcRange = 0x0204ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08BF30ULL;
}

// Func #1483 | PC: 0x08c134..0x08c220 (236 B) | Symbol: sub_08c134
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_08c134(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C134ULL;
}

// Func #1484 | PC: 0x08c220..0x08c2e4 (196 B) | Symbol: sub_08c220
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_08c220(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C220ULL;
}

// Func #1485 | PC: 0x08c2e4..0x08c418 (308 B) | Symbol: sub_08c2e4
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_08c2e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0134ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C2E4ULL;
}

// Func #1486 | PC: 0x08c418..0x08c4ac (148 B) | Symbol: sub_08c418
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_08c418(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C418ULL;
}

// Func #1487 | PC: 0x08c4ac..0x08c5cc (288 B) | Symbol: sub_08c4ac
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_08c4ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0120ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C4ACULL;
}

// Func #1488 | PC: 0x08c5cc..0x08c794 (456 B) | Symbol: sub_08c5cc
// EN: AArch64 prologue [sub sp, sp, #0x70; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_08c5cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BFBULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C5CCULL;
}

// Func #1489 | PC: 0x08c794..0x08caa8 (788 B) | Symbol: sub_08c794
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_08c794(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9026FFCULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0314ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08C794ULL;
}

// Func #1490 | PC: 0x08caa8..0x08cb8c (228 B) | Symbol: sub_08caa8
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_08caa8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08CAA8ULL;
}

// Func #1491 | PC: 0x08cb8c..0x08cdf4 (616 B) | Symbol: sub_08cb8c
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_08cb8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9026FFCULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0268ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08CB8CULL;
}

// Func #1492 | PC: 0x08cdf4..0x08cfbc (456 B) | Symbol: sub_08cdf4
// EN: AArch64 prologue [sub sp, sp, #0x70; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_08cdf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BFBULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08CDF4ULL;
}

// Func #1493 | PC: 0x08cfbc..0x08d07c (192 B) | Symbol: sub_08cfbc
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_08cfbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08CFBCULL;
}

// Func #1494 | PC: 0x08d07c..0x08d270 (500 B) | Symbol: Java_com_bytedance_bddatefmt_BDDateFormat_nFormat
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]; stp x22, x21, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]; stp x22, x21, [sp, #0x80]]
uint64_t fde_sub_08d07c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90667FAULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x01F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D07CULL;
}

// Func #1495 | PC: 0x08d270..0x08d3d0 (352 B) | Symbol: Java_com_bytedance_bddatefmt_BDDateFormat_nFormatAbbr
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]]
uint64_t fde_sub_08d270(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90467FAULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0160ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D270ULL;
}

// Func #1496 | PC: 0x08d3d0..0x08d530 (352 B) | Symbol: Java_com_bytedance_bddatefmt_BDDateFormat_nFormatRelative
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]]
uint64_t fde_sub_08d3d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90467FAULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0160ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D3D0ULL;
}

// Func #1497 | PC: 0x08d530..0x08d7d0 (672 B) | Symbol: Java_com_bytedance_bddatefmt_BDDateFormat_nFormatTimeZone
// EN: AArch64 prologue [sub sp, sp, #0xc0; stp x26, x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; stp x26, x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]]
uint64_t fde_sub_08d530(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90767FAULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x02A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D530ULL;
}

// Func #1498 | PC: 0x08d7d0..0x08d944 (372 B) | Symbol: Java_com_bytedance_bddatefmt_BDDateFormat_nFormatTimeRange
// EN: AArch64 prologue [sub sp, sp, #0xa0; str x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; str x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]]
uint64_t fde_sub_08d7d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023FBULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x0174ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D7D0ULL;
}

// Func #1499 | PC: 0x08d944..0x08d9f4 (176 B) | Symbol: JNI_OnLoad
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_08d944(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D944ULL;
}

// Func #1500 | PC: 0x08d9f4..0x08da08 (20 B) | Symbol: sub_08d9f4
// EN: AArch64 prologue [ldrb w8, [x0, #8]; tbnz w8, #0, #0x8da00; ret; ldr x0, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #8]; tbnz w8, #0, #0x8da00; ret; ldr x0, [x0, #0x18]]
uint64_t fde_sub_08d9f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x37000048ULL) << 32) | 0x39402008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08D9F4ULL;
}

// Func #1501 | PC: 0x08da08..0x08dc30 (552 B) | Symbol: sub_08da08
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]; stp x22, x21, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]; stp x22, x21, [sp, #0x80]]
uint64_t fde_sub_08da08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90667FAULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x0228ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DA08ULL;
}

// Func #1502 | PC: 0x08dc30..0x08f6f8 (6856 B) | Symbol: sub_08dc30
// EN: AArch64 prologue [stp d9, d8, [sp, #-0x70]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp d9, d8, [sp, #-0x70]!; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_08dc30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9016FFCULL) << 32) | 0x6DB923E9ULL;
    const uint64_t kPcRange = 0x1AC8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08DC30ULL;
}

// Func #1503 | PC: 0x08f6f8..0x0906d4 (4060 B) | Symbol: sub_08f6f8
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_08f6f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0FDCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x08F6F8ULL;
}

// Func #1504 | PC: 0x0906d4..0x090760 (140 B) | Symbol: sub_0906d4
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0906d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0906D4ULL;
}

// Func #1505 | PC: 0x090760..0x091710 (4016 B) | Symbol: sub_090760
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_090760(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0FB0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x090760ULL;
}

// Func #1506 | PC: 0x091710..0x091a18 (776 B) | Symbol: sub_091710
// EN: AArch64 prologue [sub sp, sp, #0x100; stp x26, x25, [sp, #0xb0]; stp x24, x23, [sp, #0xc0]; stp x22, x21, [sp, #0xd0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x100; stp x26, x25, [sp, #0xb0]; stp x24, x23, [sp, #0xc0]; stp x22, x21, [sp, #0xd0]]
uint64_t fde_sub_091710(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90B67FAULL) << 32) | 0xD10403FFULL;
    const uint64_t kPcRange = 0x0308ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091710ULL;
}

// Func #1507 | PC: 0x091a18..0x0920f0 (1752 B) | Symbol: sub_091a18
// EN: AArch64 prologue [str x28, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x28, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_091a18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FFCULL;
    const uint64_t kPcRange = 0x06D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x091A18ULL;
}

// Func #1508 | PC: 0x0920f0..0x092574 (1156 B) | Symbol: sub_0920f0
// EN: AArch64 prologue [sub sp, sp, #0x180; str x28, [sp, #0x120]; stp x26, x25, [sp, #0x130]; stp x24, x23, [sp, #0x140]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x180; str x28, [sp, #0x120]; stp x26, x25, [sp, #0x130]; stp x24, x23, [sp, #0x140]]
uint64_t fde_sub_0920f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90093FCULL) << 32) | 0xD10603FFULL;
    const uint64_t kPcRange = 0x0484ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0920F0ULL;
}

// Func #1509 | PC: 0x092574..0x092860 (748 B) | Symbol: sub_092574
// EN: AArch64 prologue [sub sp, sp, #0x110; stp x28, x23, [sp, #0xd0]; stp x22, x21, [sp, #0xe0]; stp x20, x19, [sp, #0xf0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; stp x28, x23, [sp, #0xd0]; stp x22, x21, [sp, #0xe0]; stp x20, x19, [sp, #0xf0]]
uint64_t fde_sub_092574(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90D5FFCULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x02ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092574ULL;
}

// Func #1510 | PC: 0x092860..0x092864 (4 B) | Symbol: sub_092860
// EN: AArch64 prologue [b #0x8dc30] | VI: Khởi đầu hàm AArch64 [b #0x8dc30]
uint64_t fde_sub_092860(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39402008ULL) << 32) | 0x17FFECF4ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092860ULL;
}

// Func #1511 | PC: 0x092864..0x092884 (32 B) | Symbol: sub_092864
// EN: AArch64 prologue [ldrb w8, [x0, #8]; adrp x9, #0xab000; add x9, x9, #0xa88; str x9, [x0]] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #8]; adrp x9, #0xab000; add x9, x9, #0xa88; str x9, [x0]]
uint64_t fde_sub_092864(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00000C9ULL) << 32) | 0x39402008ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092864ULL;
}

// Func #1512 | PC: 0x092884..0x0928c0 (60 B) | Symbol: sub_092884
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #8]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #8]]
uint64_t fde_sub_092884(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092884ULL;
}

// Func #1513 | PC: 0x0928c0..0x092900 (64 B) | Symbol: sub_0928c0
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0928c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0928C0ULL;
}

// Func #1514 | PC: 0x092900..0x09291c (28 B) | Symbol: sub_092900
// EN: AArch64 prologue [adrp x9, #0xab000; mov x8, x1; add x9, x9, #0xa88; str x9, [x8], #8] | VI: Khởi đầu hàm AArch64 [adrp x9, #0xab000; mov x8, x1; add x9, x9, #0xa88; str x9, [x8], #8]
uint64_t fde_sub_092900(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0103E8ULL) << 32) | 0xB00000C9ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092900ULL;
}

// Func #1515 | PC: 0x09291c..0x092930 (20 B) | Symbol: sub_09291c
// EN: AArch64 prologue [ldrb w8, [x0, #8]; tbnz w8, #0, #0x92928; ret; ldr x0, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #8]; tbnz w8, #0, #0x92928; ret; ldr x0, [x0, #0x18]]
uint64_t fde_sub_09291c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x37000048ULL) << 32) | 0x39402008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09291CULL;
}

// Func #1516 | PC: 0x092930..0x092960 (48 B) | Symbol: sub_092930
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #8]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #8]]
uint64_t fde_sub_092930(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092930ULL;
}

// Func #1517 | PC: 0x092960..0x09296c (12 B) | Symbol: sub_092960
// EN: AArch64 prologue [ldr w2, [x2]; add x0, x0, #8; b #0x9296c] | VI: Khởi đầu hàm AArch64 [ldr w2, [x2]; add x0, x0, #8; b #0x9296c]
uint64_t fde_sub_092960(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91002000ULL) << 32) | 0xB9400042ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092960ULL;
}

// Func #1518 | PC: 0x09296c..0x092a30 (196 B) | Symbol: sub_09296c
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_09296c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09296CULL;
}

// Func #1519 | PC: 0x092a30..0x092a3c (12 B) | Symbol: sub_092a30
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x1b50] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x1b50]
uint64_t fde_sub_092a30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092A30ULL;
}

// Func #1520 | PC: 0x092a3c..0x092a40 (4 B) | Symbol: sub_092a3c
// EN: AArch64 prologue [b #0x1ad0] | VI: Khởi đầu hàm AArch64 [b #0x1ad0]
uint64_t fde_sub_092a3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0x17FDBC25ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092A3CULL;
}

// Func #1521 | PC: 0x092a40..0x092a64 (36 B) | Symbol: sub_092a40
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w0, #0x10; bl #0x1ba0] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w0, #0x10; bl #0x1ba0]
uint64_t fde_sub_092a40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092A40ULL;
}

// Func #1522 | PC: 0x092a64..0x092a74 (16 B) | Symbol: sub_092a64
// EN: AArch64 prologue [adrp x8, #0xab000; add x8, x8, #0xad0; str x8, [x1]; ret] | VI: Khởi đầu hàm AArch64 [adrp x8, #0xab000; add x8, x8, #0xad0; str x8, [x1]; ret]
uint64_t fde_sub_092a64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x912B4108ULL) << 32) | 0xB00000C8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092A64ULL;
}

// Func #1523 | PC: 0x092a74..0x092a78 (4 B) | Symbol: sub_092a74
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_092a74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FDBC16ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092A74ULL;
}

// Func #1524 | PC: 0x092a78..0x092a7c (4 B) | Symbol: sub_092a78
// EN: AArch64 prologue [b #0x1ad0] | VI: Khởi đầu hàm AArch64 [b #0x1ad0]
uint64_t fde_sub_092a78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800022ULL) << 32) | 0x17FDBC16ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092A78ULL;
}

// Func #1525 | PC: 0x092a7c..0x092a90 (20 B) | Symbol: sub_092a7c
// EN: AArch64 prologue [mov w2, #1; mov x3, #-1; mov x0, x8; mov x4, x1] | VI: Khởi đầu hàm AArch64 [mov w2, #1; mov x3, #-1; mov x0, x8; mov x4, x1]
uint64_t fde_sub_092a7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x92800003ULL) << 32) | 0x52800022ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092A7CULL;
}

// Func #1526 | PC: 0x092a90..0x092ad0 (64 B) | Symbol: sub_092a90
// EN: AArch64 prologue [mov x8, x0; ldr x0, [x0, #0x40]; adrp x9, #0xab000; add x10, x8, #0x20] | VI: Khởi đầu hàm AArch64 [mov x8, x0; ldr x0, [x0, #0x40]; adrp x9, #0xab000; add x10, x8, #0x20]
uint64_t fde_sub_092a90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402000ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092A90ULL;
}

// Func #1527 | PC: 0x092ad0..0x092b28 (88 B) | Symbol: sub_092ad0
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_092ad0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092AD0ULL;
}

// Func #1528 | PC: 0x092b28..0x092bac (132 B) | Symbol: sub_092b28
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0]
uint64_t fde_sub_092b28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092B28ULL;
}

// Func #1529 | PC: 0x092bac..0x092c2c (128 B) | Symbol: sub_092bac
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xab000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xab000]
uint64_t fde_sub_092bac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092BACULL;
}

// Func #1530 | PC: 0x092c2c..0x092c60 (52 B) | Symbol: sub_092c2c
// EN: AArch64 prologue [mov x8, x0; ldr x0, [x0, #0x40]; add x8, x8, #0x20; cmp x8, x0] | VI: Khởi đầu hàm AArch64 [mov x8, x0; ldr x0, [x0, #0x40]; add x8, x8, #0x20; cmp x8, x0]
uint64_t fde_sub_092c2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402000ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092C2CULL;
}

// Func #1531 | PC: 0x092c60..0x092cac (76 B) | Symbol: sub_092c60
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_092c60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092C60ULL;
}

// Func #1532 | PC: 0x092cac..0x092cb8 (12 B) | Symbol: sub_092cac
// EN: AArch64 prologue [ldr w2, [x2]; add x0, x0, #0x10; b #0x92cb8] | VI: Khởi đầu hàm AArch64 [ldr w2, [x2]; add x0, x0, #0x10; b #0x92cb8]
uint64_t fde_sub_092cac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91004000ULL) << 32) | 0xB9400042ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092CACULL;
}

// Func #1533 | PC: 0x092cb8..0x092ec8 (528 B) | Symbol: sub_092cb8
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]]
uint64_t fde_sub_092cb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9056FFCULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x0210ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092CB8ULL;
}

// Func #1534 | PC: 0x092ec8..0x092f60 (152 B) | Symbol: sub_092ec8
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_092ec8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092EC8ULL;
}

// Func #1535 | PC: 0x092f60..0x092ff0 (144 B) | Symbol: sub_092f60
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_092f60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092F60ULL;
}

// Func #1536 | PC: 0x092ff0..0x0930ec (252 B) | Symbol: sub_092ff0
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_092ff0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x092FF0ULL;
}

// Func #1537 | PC: 0x0930ec..0x0931d8 (236 B) | Symbol: sub_0930ec
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0930ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0930ECULL;
}

// Func #1538 | PC: 0x0931d8..0x093264 (140 B) | Symbol: sub_0931d8
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0931d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0931D8ULL;
}

// Func #1539 | PC: 0x093264..0x0932e8 (132 B) | Symbol: sub_093264
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_093264(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093264ULL;
}

// Func #1540 | PC: 0x0932e8..0x0933c0 (216 B) | Symbol: sub_0932e8
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0932e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0932E8ULL;
}

// Func #1541 | PC: 0x0933c0..0x0933c4 (4 B) | Symbol: sub_0933c0
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_0933c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FDB9C3ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0933C0ULL;
}

// Func #1542 | PC: 0x0933c4..0x0933c8 (4 B) | Symbol: sub_0933c4
// EN: AArch64 prologue [b #0x1ad0] | VI: Khởi đầu hàm AArch64 [b #0x1ad0]
uint64_t fde_sub_0933c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0x17FDB9C3ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0933C4ULL;
}

// Func #1543 | PC: 0x0933c8..0x0933ec (36 B) | Symbol: sub_0933c8
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w0, #0x10; bl #0x1ba0] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w0, #0x10; bl #0x1ba0]
uint64_t fde_sub_0933c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0933C8ULL;
}

// Func #1544 | PC: 0x0933ec..0x0933fc (16 B) | Symbol: sub_0933ec
// EN: AArch64 prologue [adrp x8, #0xab000; add x8, x8, #0xba8; str x8, [x1]; ret] | VI: Khởi đầu hàm AArch64 [adrp x8, #0xab000; add x8, x8, #0xba8; str x8, [x1]; ret]
uint64_t fde_sub_0933ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x912EA108ULL) << 32) | 0x900000C8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0933ECULL;
}

// Func #1545 | PC: 0x0933fc..0x093400 (4 B) | Symbol: sub_0933fc
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_0933fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FDB9B4ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0933FCULL;
}

// Func #1546 | PC: 0x093400..0x093404 (4 B) | Symbol: sub_093400
// EN: AArch64 prologue [b #0x1ad0] | VI: Khởi đầu hàm AArch64 [b #0x1ad0]
uint64_t fde_sub_093400(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE4FF4ULL) << 32) | 0x17FDB9B4ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093400ULL;
}

// Func #1547 | PC: 0x093404..0x0934a0 (156 B) | Symbol: sub_093404
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w10, [x2]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w10, [x2]]
uint64_t fde_sub_093404(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093404ULL;
}

// Func #1548 | PC: 0x0934a0..0x093528 (136 B) | Symbol: sub_0934a0
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0934a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0934A0ULL;
}

// Func #1549 | PC: 0x093528..0x0935ac (132 B) | Symbol: sub_093528
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_093528(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093528ULL;
}

// Func #1550 | PC: 0x0935ac..0x093678 (204 B) | Symbol: sub_0935ac
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0]
uint64_t fde_sub_0935ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0935ACULL;
}

// Func #1551 | PC: 0x093678..0x093740 (200 B) | Symbol: sub_093678
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xab000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xab000]
uint64_t fde_sub_093678(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093678ULL;
}

// Func #1552 | PC: 0x093740..0x0937bc (124 B) | Symbol: sub_093740
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_093740(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093740ULL;
}

// Func #1553 | PC: 0x0937bc..0x093834 (120 B) | Symbol: sub_0937bc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0937bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0937BCULL;
}

// Func #1554 | PC: 0x093834..0x093840 (12 B) | Symbol: sub_093834
// EN: AArch64 prologue [ldr w2, [x2]; add x0, x0, #0x10; b #0x93840] | VI: Khởi đầu hàm AArch64 [ldr w2, [x2]; add x0, x0, #0x10; b #0x93840]
uint64_t fde_sub_093834(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91004000ULL) << 32) | 0xB9400042ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093834ULL;
}

// Func #1555 | PC: 0x093840..0x09391c (220 B) | Symbol: sub_093840
// EN: AArch64 prologue [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_093840(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF5ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093840ULL;
}

// Func #1556 | PC: 0x09391c..0x0939a4 (136 B) | Symbol: sub_09391c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_09391c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09391CULL;
}

// Func #1557 | PC: 0x0939a4..0x093a28 (132 B) | Symbol: sub_0939a4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0939a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0939A4ULL;
}

// Func #1558 | PC: 0x093a28..0x093af4 (204 B) | Symbol: sub_093a28
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0]
uint64_t fde_sub_093a28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093A28ULL;
}

// Func #1559 | PC: 0x093af4..0x093bbc (200 B) | Symbol: sub_093af4
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xab000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xab000]
uint64_t fde_sub_093af4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093AF4ULL;
}

// Func #1560 | PC: 0x093bbc..0x093c38 (124 B) | Symbol: sub_093bbc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_093bbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093BBCULL;
}

// Func #1561 | PC: 0x093c38..0x093cb0 (120 B) | Symbol: sub_093c38
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_093c38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093C38ULL;
}

// Func #1562 | PC: 0x093cb0..0x093cbc (12 B) | Symbol: sub_093cb0
// EN: AArch64 prologue [ldr w2, [x2]; add x0, x0, #0x10; b #0x93cbc] | VI: Khởi đầu hàm AArch64 [ldr w2, [x2]; add x0, x0, #0x10; b #0x93cbc]
uint64_t fde_sub_093cb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91004000ULL) << 32) | 0xB9400042ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093CB0ULL;
}

// Func #1563 | PC: 0x093cbc..0x093da4 (232 B) | Symbol: sub_093cbc
// EN: AArch64 prologue [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_093cbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF7ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093CBCULL;
}

// Func #1564 | PC: 0x093da4..0x093e3c (152 B) | Symbol: sub_093da4
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_093da4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093DA4ULL;
}

// Func #1565 | PC: 0x093e3c..0x093ecc (144 B) | Symbol: sub_093e3c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_093e3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093E3CULL;
}

// Func #1566 | PC: 0x093ecc..0x093fc8 (252 B) | Symbol: sub_093ecc
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_093ecc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093ECCULL;
}

// Func #1567 | PC: 0x093fc8..0x0940b4 (236 B) | Symbol: sub_093fc8
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_093fc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x093FC8ULL;
}

// Func #1568 | PC: 0x0940b4..0x094140 (140 B) | Symbol: sub_0940b4
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0940b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0940B4ULL;
}

// Func #1569 | PC: 0x094140..0x0941c4 (132 B) | Symbol: sub_094140
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_094140(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x094140ULL;
}

// Func #1570 | PC: 0x0941c4..0x0941d0 (12 B) | Symbol: sub_0941c4
// EN: AArch64 prologue [ldr w2, [x2]; add x0, x0, #8; b #0x941d0] | VI: Khởi đầu hàm AArch64 [ldr w2, [x2]; add x0, x0, #8; b #0x941d0]
uint64_t fde_sub_0941c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91002000ULL) << 32) | 0xB9400042ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0941C4ULL;
}

// Func #1571 | PC: 0x0941d0..0x0943d0 (512 B) | Symbol: sub_0941d0
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]]
uint64_t fde_sub_0941d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9056FFCULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x0200ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0941D0ULL;
}

// Func #1572 | PC: 0x0943d0..0x0943d4 (4 B) | Symbol: sub_0943d0
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_0943d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FDB5BFULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0943D0ULL;
}

// Func #1573 | PC: 0x0943d4..0x0943d8 (4 B) | Symbol: sub_0943d4
// EN: AArch64 prologue [b #0x1ad0] | VI: Khởi đầu hàm AArch64 [b #0x1ad0]
uint64_t fde_sub_0943d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BFDULL) << 32) | 0x17FDB5BFULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0943D4ULL;
}

// Func #1574 | PC: 0x0943d8..0x0943fc (36 B) | Symbol: sub_0943d8
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w0, #0x10; bl #0x1ba0] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w0, #0x10; bl #0x1ba0]
uint64_t fde_sub_0943d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0943D8ULL;
}

// Func #1575 | PC: 0x0943fc..0x09440c (16 B) | Symbol: sub_0943fc
// EN: AArch64 prologue [adrp x8, #0xab000; add x8, x8, #0xcc8; str x8, [x1]; ret] | VI: Khởi đầu hàm AArch64 [adrp x8, #0xab000; add x8, x8, #0xcc8; str x8, [x1]; ret]
uint64_t fde_sub_0943fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91332108ULL) << 32) | 0xF00000A8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0943FCULL;
}

// Func #1576 | PC: 0x09440c..0x094410 (4 B) | Symbol: sub_09440c
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_09440c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FDB5B0ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09440CULL;
}

// Func #1577 | PC: 0x094410..0x094414 (4 B) | Symbol: sub_094410
// EN: AArch64 prologue [b #0x1ad0] | VI: Khởi đầu hàm AArch64 [b #0x1ad0]
uint64_t fde_sub_094410(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39400029ULL) << 32) | 0x17FDB5B0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x094410ULL;
}

// Func #1578 | PC: 0x094414..0x09443c (40 B) | Symbol: sub_094414
// EN: AArch64 prologue [ldrb w9, [x1]; ldr x10, [x1, #8]; mov w2, #1; mov x0, x8] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x1]; ldr x10, [x1, #8]; mov w2, #1; mov x0, x8]
uint64_t fde_sub_094414(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF940042AULL) << 32) | 0x39400029ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x094414ULL;
}

// Func #1579 | PC: 0x09443c..0x0945d4 (408 B) | Symbol: sub_09443c
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_09443c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x0198ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09443CULL;
}

// Func #1580 | PC: 0x0945d4..0x0946c0 (236 B) | Symbol: sub_0945d4
// EN: AArch64 prologue [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_0945d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F9ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0945D4ULL;
}

// Func #1581 | PC: 0x0946c0..0x09487c (444 B) | Symbol: sub_0946c0
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x24, x23, [sp, #0x70]; stp x22, x21, [sp, #0x80]; stp x20, x19, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x24, x23, [sp, #0x70]; stp x22, x21, [sp, #0x80]; stp x20, x19, [sp, #0x90]]
uint64_t fde_sub_0946c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9075FF8ULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x01BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0946C0ULL;
}

// Func #1582 | PC: 0x09487c..0x094958 (220 B) | Symbol: sub_09487c
// EN: AArch64 prologue [sub sp, sp, #0x60; str x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]; add x29, sp, #0x50] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]; add x29, sp, #0x50]
uint64_t fde_sub_09487c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F3ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09487CULL;
}

// Func #1583 | PC: 0x094958..0x094bf4 (668 B) | Symbol: sub_094958
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x24, x23, [sp, #0x70]; stp x22, x21, [sp, #0x80]; stp x20, x19, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x24, x23, [sp, #0x70]; stp x22, x21, [sp, #0x80]; stp x20, x19, [sp, #0x90]]
uint64_t fde_sub_094958(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9075FF8ULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x029CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x094958ULL;
}

// Func #1584 | PC: 0x094bf4..0x095c08 (4116 B) | Symbol: sub_094bf4
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_094bf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x1014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x094BF4ULL;
}

// Func #1585 | PC: 0x095c08..0x095f24 (796 B) | Symbol: sub_095c08
// EN: AArch64 prologue [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]]
uint64_t fde_sub_095c08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F9ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x031CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x095C08ULL;
}

// Func #1586 | PC: 0x095f24..0x0960ec (456 B) | Symbol: sub_095f24
// EN: AArch64 prologue [sub sp, sp, #0x70; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_095f24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BFBULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x095F24ULL;
}

// Func #1587 | PC: 0x0960ec..0x096300 (532 B) | Symbol: sub_0960ec
// EN: AArch64 prologue [sub sp, sp, #0x120; stp x28, x27, [sp, #0xc0]; stp x26, x25, [sp, #0xd0]; stp x24, x23, [sp, #0xe0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; stp x28, x27, [sp, #0xc0]; stp x26, x25, [sp, #0xd0]; stp x24, x23, [sp, #0xe0]]
uint64_t fde_sub_0960ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90C6FFCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x0214ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0960ECULL;
}

// Func #1588 | PC: 0x096300..0x0963ec (236 B) | Symbol: sub_096300
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_096300(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9025FF8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x096300ULL;
}

// Func #1589 | PC: 0x0963ec..0x09649c (176 B) | Symbol: sub_0963ec
// EN: AArch64 prologue [mov w9, w0; cmp w0, #8; mov x0, x8; b.hi #0x96428] | VI: Khởi đầu hàm AArch64 [mov w9, w0; cmp w0, #8; mov x0, x8; b.hi #0x96428]
uint64_t fde_sub_0963ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100201FULL) << 32) | 0x2A0003E9ULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0963ECULL;
}

// Func #1590 | PC: 0x09649c..0x096830 (916 B) | Symbol: sub_09649c
// EN: AArch64 prologue [sub sp, sp, #0x180; stp x28, x27, [sp, #0x120]; stp x26, x25, [sp, #0x130]; stp x24, x23, [sp, #0x140]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x180; stp x28, x27, [sp, #0x120]; stp x26, x25, [sp, #0x130]; stp x24, x23, [sp, #0x140]]
uint64_t fde_sub_09649c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9126FFCULL) << 32) | 0xD10603FFULL;
    const uint64_t kPcRange = 0x0394ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09649CULL;
}

// Func #1591 | PC: 0x096830..0x0968e0 (176 B) | Symbol: sub_096830
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_096830(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x096830ULL;
}

// Func #1592 | PC: 0x0968e0..0x096998 (184 B) | Symbol: sub_0968e0
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0968e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0968E0ULL;
}

// Func #1593 | PC: 0x096998..0x097180 (2024 B) | Symbol: sub_096998
// EN: AArch64 prologue [mov w8, #0xe100; movk w8, #0x5f5, lsl #16; cmp x0, x8; b.hs #0x969d4] | VI: Khởi đầu hàm AArch64 [mov w8, #0xe100; movk w8, #0x5f5, lsl #16; cmp x0, x8; b.hs #0x969d4]
uint64_t fde_sub_096998(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72A0BEA8ULL) << 32) | 0x529C2008ULL;
    const uint64_t kPcRange = 0x07E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x096998ULL;
}

// Func #1594 | PC: 0x097180..0x0971c4 (68 B) | Symbol: sub_097180
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x1, #0x10a000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x1, #0x10a000]
uint64_t fde_sub_097180(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x097180ULL;
}

// Func #1595 | PC: 0x0971c4..0x0974c4 (768 B) | Symbol: sub_0971c4
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp x28, x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp x28, x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]]
uint64_t fde_sub_0971c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9046FFCULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x0300ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0971C4ULL;
}

// Func #1596 | PC: 0x0974c4..0x097808 (836 B) | Symbol: sub_0974c4
// EN: AArch64 prologue [sub sp, sp, #0xf0; stp x28, x27, [sp, #0x90]; stp x26, x25, [sp, #0xa0]; stp x24, x23, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xf0; stp x28, x27, [sp, #0x90]; stp x26, x25, [sp, #0xa0]; stp x24, x23, [sp, #0xb0]]
uint64_t fde_sub_0974c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9096FFCULL) << 32) | 0xD103C3FFULL;
    const uint64_t kPcRange = 0x0344ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0974C4ULL;
}

// Func #1597 | PC: 0x097808..0x09798c (388 B) | Symbol: sub_097808
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_097808(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9016FFCULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0184ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x097808ULL;
}

// Func #1598 | PC: 0x09798c..0x097a80 (244 B) | Symbol: sub_09798c
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_09798c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x00F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x09798CULL;
}

// Func #1599 | PC: 0x097a80..0x097c48 (456 B) | Symbol: sub_097a80
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_097a80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x01C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x097A80ULL;
}

uint64_t DispatchRexShard5(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x03feb4ULL: return fde_sub_03feb4(a0, a1, a2);
        case 0x03ff14ULL: return fde_sub_03ff14(a0, a1, a2);
        case 0x03ffe0ULL: return fde_sub_03ffe0(a0, a1, a2);
        case 0x040398ULL: return fde_sub_040398(a0, a1, a2);
        case 0x04046cULL: return fde_sub_04046c(a0, a1, a2);
        case 0x0405bcULL: return fde_sub_0405bc(a0, a1, a2);
        case 0x0405ccULL: return fde_sub_0405cc(a0, a1, a2);
        case 0x0405dcULL: return fde_sub_0405dc(a0, a1, a2);
        case 0x0405ecULL: return fde_sub_0405ec(a0, a1, a2);
        case 0x0405fcULL: return fde_sub_0405fc(a0, a1, a2);
        case 0x04060cULL: return fde_sub_04060c(a0, a1, a2);
        case 0x04061cULL: return fde_sub_04061c(a0, a1, a2);
        case 0x04062cULL: return fde_sub_04062c(a0, a1, a2);
        case 0x04063cULL: return fde_sub_04063c(a0, a1, a2);
        case 0x04064cULL: return fde_sub_04064c(a0, a1, a2);
        case 0x04065cULL: return fde_sub_04065c(a0, a1, a2);
        case 0x04066cULL: return fde_sub_04066c(a0, a1, a2);
        case 0x04067cULL: return fde_sub_04067c(a0, a1, a2);
        case 0x04068cULL: return fde_sub_04068c(a0, a1, a2);
        case 0x04069cULL: return fde_sub_04069c(a0, a1, a2);
        case 0x0406acULL: return fde_sub_0406ac(a0, a1, a2);
        case 0x0406bcULL: return fde_sub_0406bc(a0, a1, a2);
        case 0x0406ccULL: return fde_sub_0406cc(a0, a1, a2);
        case 0x0406dcULL: return fde_sub_0406dc(a0, a1, a2);
        case 0x0406ecULL: return fde_sub_0406ec(a0, a1, a2);
        case 0x0406fcULL: return fde_sub_0406fc(a0, a1, a2);
        case 0x04070cULL: return fde_sub_04070c(a0, a1, a2);
        case 0x04071cULL: return fde_sub_04071c(a0, a1, a2);
        case 0x04072cULL: return fde_sub_04072c(a0, a1, a2);
        case 0x040fd4ULL: return fde_sub_040fd4(a0, a1, a2);
        case 0x041024ULL: return fde_sub_041024(a0, a1, a2);
        case 0x0410b8ULL: return fde_sub_0410b8(a0, a1, a2);
        case 0x041110ULL: return fde_sub_041110(a0, a1, a2);
        case 0x041374ULL: return fde_sub_041374(a0, a1, a2);
        case 0x0413acULL: return fde_sub_0413ac(a0, a1, a2);
        case 0x04143cULL: return fde_sub_04143c(a0, a1, a2);
        case 0x041464ULL: return fde_sub_041464(a0, a1, a2);
        case 0x041500ULL: return fde_sub_041500(a0, a1, a2);
        case 0x041508ULL: return fde_sub_041508(a0, a1, a2);
        case 0x041538ULL: return fde_sub_041538(a0, a1, a2);
        case 0x04154cULL: return fde_sub_04154c(a0, a1, a2);
        case 0x04155cULL: return fde_sub_04155c(a0, a1, a2);
        case 0x041598ULL: return fde_sub_041598(a0, a1, a2);
        case 0x04159cULL: return fde_sub_04159c(a0, a1, a2);
        case 0x0415b8ULL: return fde_sub_0415b8(a0, a1, a2);
        case 0x0415bcULL: return fde_sub_0415bc(a0, a1, a2);
        case 0x0415e4ULL: return fde_sub_0415e4(a0, a1, a2);
        case 0x04181cULL: return fde_sub_04181c(a0, a1, a2);
        case 0x041a70ULL: return fde_sub_041a70(a0, a1, a2);
        case 0x041ac0ULL: return fde_sub_041ac0(a0, a1, a2);
        case 0x041afcULL: return fde_sub_041afc(a0, a1, a2);
        case 0x041b38ULL: return fde_sub_041b38(a0, a1, a2);
        case 0x041b70ULL: return fde_sub_041b70(a0, a1, a2);
        case 0x041ba4ULL: return fde_sub_041ba4(a0, a1, a2);
        case 0x041bdcULL: return fde_sub_041bdc(a0, a1, a2);
        case 0x041c18ULL: return fde_sub_041c18(a0, a1, a2);
        case 0x041d14ULL: return fde_sub_041d14(a0, a1, a2);
        case 0x0420c0ULL: return fde_sub_0420c0(a0, a1, a2);
        case 0x042180ULL: return fde_sub_042180(a0, a1, a2);
        case 0x0422a0ULL: return fde_sub_0422a0(a0, a1, a2);
        case 0x042718ULL: return fde_sub_042718(a0, a1, a2);
        case 0x042728ULL: return fde_sub_042728(a0, a1, a2);
        case 0x042738ULL: return fde_sub_042738(a0, a1, a2);
        case 0x042748ULL: return fde_sub_042748(a0, a1, a2);
        case 0x042758ULL: return fde_sub_042758(a0, a1, a2);
        case 0x042768ULL: return fde_sub_042768(a0, a1, a2);
        case 0x042778ULL: return fde_sub_042778(a0, a1, a2);
        case 0x042788ULL: return fde_sub_042788(a0, a1, a2);
        case 0x042798ULL: return fde_sub_042798(a0, a1, a2);
        case 0x0427a8ULL: return fde_sub_0427a8(a0, a1, a2);
        case 0x0427b8ULL: return fde_sub_0427b8(a0, a1, a2);
        case 0x0427c8ULL: return fde_sub_0427c8(a0, a1, a2);
        case 0x0427d8ULL: return fde_sub_0427d8(a0, a1, a2);
        case 0x0427e8ULL: return fde_sub_0427e8(a0, a1, a2);
        case 0x0427f8ULL: return fde_sub_0427f8(a0, a1, a2);
        case 0x042808ULL: return fde_sub_042808(a0, a1, a2);
        case 0x042818ULL: return fde_sub_042818(a0, a1, a2);
        case 0x042828ULL: return fde_sub_042828(a0, a1, a2);
        case 0x042838ULL: return fde_sub_042838(a0, a1, a2);
        case 0x042848ULL: return fde_sub_042848(a0, a1, a2);
        case 0x042858ULL: return fde_sub_042858(a0, a1, a2);
        case 0x042868ULL: return fde_sub_042868(a0, a1, a2);
        case 0x042878ULL: return fde_sub_042878(a0, a1, a2);
        case 0x042888ULL: return fde_sub_042888(a0, a1, a2);
        case 0x042934ULL: return fde_sub_042934(a0, a1, a2);
        case 0x0429a0ULL: return fde_sub_0429a0(a0, a1, a2);
        case 0x0429d0ULL: return fde_sub_0429d0(a0, a1, a2);
        case 0x042af8ULL: return fde_sub_042af8(a0, a1, a2);
        case 0x042d08ULL: return fde_sub_042d08(a0, a1, a2);
        case 0x042dd8ULL: return fde_sub_042dd8(a0, a1, a2);
        case 0x042e38ULL: return fde_sub_042e38(a0, a1, a2);
        case 0x042e94ULL: return fde_sub_042e94(a0, a1, a2);
        case 0x042ef0ULL: return fde_sub_042ef0(a0, a1, a2);
        case 0x042f50ULL: return fde_sub_042f50(a0, a1, a2);
        case 0x042fb4ULL: return fde_sub_042fb4(a0, a1, a2);
        case 0x043064ULL: return fde_sub_043064(a0, a1, a2);
        case 0x0430c0ULL: return fde_sub_0430c0(a0, a1, a2);
        case 0x04311cULL: return fde_sub_04311c(a0, a1, a2);
        case 0x043178ULL: return fde_sub_043178(a0, a1, a2);
        case 0x0431d4ULL: return fde_sub_0431d4(a0, a1, a2);
        case 0x043460ULL: return fde_sub_043460(a0, a1, a2);
        case 0x043468ULL: return fde_sub_043468(a0, a1, a2);
        case 0x043498ULL: return fde_sub_043498(a0, a1, a2);
        case 0x0434acULL: return fde_sub_0434ac(a0, a1, a2);
        case 0x0434bcULL: return fde_sub_0434bc(a0, a1, a2);
        case 0x0434f8ULL: return fde_sub_0434f8(a0, a1, a2);
        case 0x0434fcULL: return fde_sub_0434fc(a0, a1, a2);
        case 0x043518ULL: return fde_sub_043518(a0, a1, a2);
        case 0x04351cULL: return fde_sub_04351c(a0, a1, a2);
        case 0x043544ULL: return fde_sub_043544(a0, a1, a2);
        case 0x0435c8ULL: return fde_sub_0435c8(a0, a1, a2);
        case 0x043714ULL: return fde_sub_043714(a0, a1, a2);
        case 0x04374cULL: return fde_sub_04374c(a0, a1, a2);
        case 0x0437bcULL: return fde_sub_0437bc(a0, a1, a2);
        case 0x043b18ULL: return fde_sub_043b18(a0, a1, a2);
        case 0x043ff4ULL: return fde_sub_043ff4(a0, a1, a2);
        case 0x0440b8ULL: return fde_sub_0440b8(a0, a1, a2);
        case 0x044640ULL: return fde_sub_044640(a0, a1, a2);
        case 0x044650ULL: return fde_sub_044650(a0, a1, a2);
        case 0x044660ULL: return fde_sub_044660(a0, a1, a2);
        case 0x044670ULL: return fde_sub_044670(a0, a1, a2);
        case 0x044680ULL: return fde_sub_044680(a0, a1, a2);
        case 0x044690ULL: return fde_sub_044690(a0, a1, a2);
        case 0x0446a0ULL: return fde_sub_0446a0(a0, a1, a2);
        case 0x0446b0ULL: return fde_sub_0446b0(a0, a1, a2);
        case 0x0446c0ULL: return fde_sub_0446c0(a0, a1, a2);
        case 0x0446d0ULL: return fde_sub_0446d0(a0, a1, a2);
        case 0x0446e0ULL: return fde_sub_0446e0(a0, a1, a2);
        case 0x0446f0ULL: return fde_sub_0446f0(a0, a1, a2);
        case 0x044700ULL: return fde_sub_044700(a0, a1, a2);
        case 0x044710ULL: return fde_sub_044710(a0, a1, a2);
        case 0x044720ULL: return fde_sub_044720(a0, a1, a2);
        case 0x044730ULL: return fde_sub_044730(a0, a1, a2);
        case 0x044740ULL: return fde_sub_044740(a0, a1, a2);
        case 0x044750ULL: return fde_sub_044750(a0, a1, a2);
        case 0x044760ULL: return fde_sub_044760(a0, a1, a2);
        case 0x044770ULL: return fde_sub_044770(a0, a1, a2);
        case 0x044780ULL: return fde_sub_044780(a0, a1, a2);
        case 0x044790ULL: return fde_sub_044790(a0, a1, a2);
        case 0x0447a0ULL: return fde_sub_0447a0(a0, a1, a2);
        case 0x0447b0ULL: return fde_sub_0447b0(a0, a1, a2);
        case 0x044c64ULL: return fde_sub_044c64(a0, a1, a2);
        case 0x044cccULL: return fde_sub_044ccc(a0, a1, a2);
        case 0x045714ULL: return fde_sub_045714(a0, a1, a2);
        case 0x047358ULL: return fde_sub_047358(a0, a1, a2);
        case 0x049374ULL: return fde_sub_049374(a0, a1, a2);
        case 0x04b4c0ULL: return fde_sub_04b4c0(a0, a1, a2);
        case 0x04d670ULL: return fde_sub_04d670(a0, a1, a2);
        case 0x04f910ULL: return fde_sub_04f910(a0, a1, a2);
        case 0x051514ULL: return fde_sub_051514(a0, a1, a2);
        case 0x053458ULL: return fde_sub_053458(a0, a1, a2);
        case 0x0551b4ULL: return fde_sub_0551b4(a0, a1, a2);
        case 0x056fd0ULL: return fde_sub_056fd0(a0, a1, a2);
        case 0x0591c8ULL: return fde_sub_0591c8(a0, a1, a2);
        case 0x05b314ULL: return fde_sub_05b314(a0, a1, a2);
        case 0x05d77cULL: return fde_sub_05d77c(a0, a1, a2);
        case 0x05f6ccULL: return fde_sub_05f6cc(a0, a1, a2);
        case 0x061624ULL: return fde_sub_061624(a0, a1, a2);
        case 0x063574ULL: return fde_sub_063574(a0, a1, a2);
        case 0x065778ULL: return fde_sub_065778(a0, a1, a2);
        case 0x067ae0ULL: return fde_sub_067ae0(a0, a1, a2);
        case 0x069d88ULL: return fde_sub_069d88(a0, a1, a2);
        case 0x06c174ULL: return fde_sub_06c174(a0, a1, a2);
        case 0x06e090ULL: return fde_sub_06e090(a0, a1, a2);
        case 0x06fe78ULL: return fde_sub_06fe78(a0, a1, a2);
        case 0x071d84ULL: return fde_sub_071d84(a0, a1, a2);
        case 0x073f98ULL: return fde_sub_073f98(a0, a1, a2);
        case 0x076264ULL: return fde_sub_076264(a0, a1, a2);
        case 0x078030ULL: return fde_sub_078030(a0, a1, a2);
        case 0x079e60ULL: return fde_sub_079e60(a0, a1, a2);
        case 0x07c320ULL: return fde_sub_07c320(a0, a1, a2);
        case 0x07e198ULL: return fde_sub_07e198(a0, a1, a2);
        case 0x07ff80ULL: return fde_sub_07ff80(a0, a1, a2);
        case 0x081c7cULL: return fde_sub_081c7c(a0, a1, a2);
        case 0x083908ULL: return fde_sub_083908(a0, a1, a2);
        case 0x0855ecULL: return fde_sub_0855ec(a0, a1, a2);
        case 0x085620ULL: return fde_sub_085620(a0, a1, a2);
        case 0x08746cULL: return fde_sub_08746c(a0, a1, a2);
        case 0x0876f8ULL: return fde_sub_0876f8(a0, a1, a2);
        case 0x088300ULL: return fde_sub_088300(a0, a1, a2);
        case 0x0884ccULL: return fde_sub_0884cc(a0, a1, a2);
        case 0x088590ULL: return fde_sub_088590(a0, a1, a2);
        case 0x0886ccULL: return fde_sub_0886cc(a0, a1, a2);
        case 0x088780ULL: return fde_sub_088780(a0, a1, a2);
        case 0x088a7cULL: return fde_sub_088a7c(a0, a1, a2);
        case 0x088b60ULL: return fde_sub_088b60(a0, a1, a2);
        case 0x088ee0ULL: return fde_sub_088ee0(a0, a1, a2);
        case 0x088fe4ULL: return fde_sub_088fe4(a0, a1, a2);
        case 0x08908cULL: return fde_sub_08908c(a0, a1, a2);
        case 0x0892f4ULL: return fde_sub_0892f4(a0, a1, a2);
        case 0x089c14ULL: return fde_sub_089c14(a0, a1, a2);
        case 0x08a51cULL: return fde_sub_08a51c(a0, a1, a2);
        case 0x08a814ULL: return fde_sub_08a814(a0, a1, a2);
        case 0x08a8f8ULL: return fde_sub_08a8f8(a0, a1, a2);
        case 0x08ab60ULL: return fde_sub_08ab60(a0, a1, a2);
        case 0x08afe8ULL: return fde_sub_08afe8(a0, a1, a2);
        case 0x08b0a0ULL: return fde_sub_08b0a0(a0, a1, a2);
        case 0x08b23cULL: return fde_sub_08b23c(a0, a1, a2);
        case 0x08b618ULL: return fde_sub_08b618(a0, a1, a2);
        case 0x08b74cULL: return fde_sub_08b74c(a0, a1, a2);
        case 0x08b834ULL: return fde_sub_08b834(a0, a1, a2);
        case 0x08be10ULL: return fde_sub_08be10(a0, a1, a2);
        case 0x08bf30ULL: return fde_sub_08bf30(a0, a1, a2);
        case 0x08c134ULL: return fde_sub_08c134(a0, a1, a2);
        case 0x08c220ULL: return fde_sub_08c220(a0, a1, a2);
        case 0x08c2e4ULL: return fde_sub_08c2e4(a0, a1, a2);
        case 0x08c418ULL: return fde_sub_08c418(a0, a1, a2);
        case 0x08c4acULL: return fde_sub_08c4ac(a0, a1, a2);
        case 0x08c5ccULL: return fde_sub_08c5cc(a0, a1, a2);
        case 0x08c794ULL: return fde_sub_08c794(a0, a1, a2);
        case 0x08caa8ULL: return fde_sub_08caa8(a0, a1, a2);
        case 0x08cb8cULL: return fde_sub_08cb8c(a0, a1, a2);
        case 0x08cdf4ULL: return fde_sub_08cdf4(a0, a1, a2);
        case 0x08cfbcULL: return fde_sub_08cfbc(a0, a1, a2);
        case 0x08d07cULL: return fde_sub_08d07c(a0, a1, a2);
        case 0x08d270ULL: return fde_sub_08d270(a0, a1, a2);
        case 0x08d3d0ULL: return fde_sub_08d3d0(a0, a1, a2);
        case 0x08d530ULL: return fde_sub_08d530(a0, a1, a2);
        case 0x08d7d0ULL: return fde_sub_08d7d0(a0, a1, a2);
        case 0x08d944ULL: return fde_sub_08d944(a0, a1, a2);
        case 0x08d9f4ULL: return fde_sub_08d9f4(a0, a1, a2);
        case 0x08da08ULL: return fde_sub_08da08(a0, a1, a2);
        case 0x08dc30ULL: return fde_sub_08dc30(a0, a1, a2);
        case 0x08f6f8ULL: return fde_sub_08f6f8(a0, a1, a2);
        case 0x0906d4ULL: return fde_sub_0906d4(a0, a1, a2);
        case 0x090760ULL: return fde_sub_090760(a0, a1, a2);
        case 0x091710ULL: return fde_sub_091710(a0, a1, a2);
        case 0x091a18ULL: return fde_sub_091a18(a0, a1, a2);
        case 0x0920f0ULL: return fde_sub_0920f0(a0, a1, a2);
        case 0x092574ULL: return fde_sub_092574(a0, a1, a2);
        case 0x092860ULL: return fde_sub_092860(a0, a1, a2);
        case 0x092864ULL: return fde_sub_092864(a0, a1, a2);
        case 0x092884ULL: return fde_sub_092884(a0, a1, a2);
        case 0x0928c0ULL: return fde_sub_0928c0(a0, a1, a2);
        case 0x092900ULL: return fde_sub_092900(a0, a1, a2);
        case 0x09291cULL: return fde_sub_09291c(a0, a1, a2);
        case 0x092930ULL: return fde_sub_092930(a0, a1, a2);
        case 0x092960ULL: return fde_sub_092960(a0, a1, a2);
        case 0x09296cULL: return fde_sub_09296c(a0, a1, a2);
        case 0x092a30ULL: return fde_sub_092a30(a0, a1, a2);
        case 0x092a3cULL: return fde_sub_092a3c(a0, a1, a2);
        case 0x092a40ULL: return fde_sub_092a40(a0, a1, a2);
        case 0x092a64ULL: return fde_sub_092a64(a0, a1, a2);
        case 0x092a74ULL: return fde_sub_092a74(a0, a1, a2);
        case 0x092a78ULL: return fde_sub_092a78(a0, a1, a2);
        case 0x092a7cULL: return fde_sub_092a7c(a0, a1, a2);
        case 0x092a90ULL: return fde_sub_092a90(a0, a1, a2);
        case 0x092ad0ULL: return fde_sub_092ad0(a0, a1, a2);
        case 0x092b28ULL: return fde_sub_092b28(a0, a1, a2);
        case 0x092bacULL: return fde_sub_092bac(a0, a1, a2);
        case 0x092c2cULL: return fde_sub_092c2c(a0, a1, a2);
        case 0x092c60ULL: return fde_sub_092c60(a0, a1, a2);
        case 0x092cacULL: return fde_sub_092cac(a0, a1, a2);
        case 0x092cb8ULL: return fde_sub_092cb8(a0, a1, a2);
        case 0x092ec8ULL: return fde_sub_092ec8(a0, a1, a2);
        case 0x092f60ULL: return fde_sub_092f60(a0, a1, a2);
        case 0x092ff0ULL: return fde_sub_092ff0(a0, a1, a2);
        case 0x0930ecULL: return fde_sub_0930ec(a0, a1, a2);
        case 0x0931d8ULL: return fde_sub_0931d8(a0, a1, a2);
        case 0x093264ULL: return fde_sub_093264(a0, a1, a2);
        case 0x0932e8ULL: return fde_sub_0932e8(a0, a1, a2);
        case 0x0933c0ULL: return fde_sub_0933c0(a0, a1, a2);
        case 0x0933c4ULL: return fde_sub_0933c4(a0, a1, a2);
        case 0x0933c8ULL: return fde_sub_0933c8(a0, a1, a2);
        case 0x0933ecULL: return fde_sub_0933ec(a0, a1, a2);
        case 0x0933fcULL: return fde_sub_0933fc(a0, a1, a2);
        case 0x093400ULL: return fde_sub_093400(a0, a1, a2);
        case 0x093404ULL: return fde_sub_093404(a0, a1, a2);
        case 0x0934a0ULL: return fde_sub_0934a0(a0, a1, a2);
        case 0x093528ULL: return fde_sub_093528(a0, a1, a2);
        case 0x0935acULL: return fde_sub_0935ac(a0, a1, a2);
        case 0x093678ULL: return fde_sub_093678(a0, a1, a2);
        case 0x093740ULL: return fde_sub_093740(a0, a1, a2);
        case 0x0937bcULL: return fde_sub_0937bc(a0, a1, a2);
        case 0x093834ULL: return fde_sub_093834(a0, a1, a2);
        case 0x093840ULL: return fde_sub_093840(a0, a1, a2);
        case 0x09391cULL: return fde_sub_09391c(a0, a1, a2);
        case 0x0939a4ULL: return fde_sub_0939a4(a0, a1, a2);
        case 0x093a28ULL: return fde_sub_093a28(a0, a1, a2);
        case 0x093af4ULL: return fde_sub_093af4(a0, a1, a2);
        case 0x093bbcULL: return fde_sub_093bbc(a0, a1, a2);
        case 0x093c38ULL: return fde_sub_093c38(a0, a1, a2);
        case 0x093cb0ULL: return fde_sub_093cb0(a0, a1, a2);
        case 0x093cbcULL: return fde_sub_093cbc(a0, a1, a2);
        case 0x093da4ULL: return fde_sub_093da4(a0, a1, a2);
        case 0x093e3cULL: return fde_sub_093e3c(a0, a1, a2);
        case 0x093eccULL: return fde_sub_093ecc(a0, a1, a2);
        case 0x093fc8ULL: return fde_sub_093fc8(a0, a1, a2);
        case 0x0940b4ULL: return fde_sub_0940b4(a0, a1, a2);
        case 0x094140ULL: return fde_sub_094140(a0, a1, a2);
        case 0x0941c4ULL: return fde_sub_0941c4(a0, a1, a2);
        case 0x0941d0ULL: return fde_sub_0941d0(a0, a1, a2);
        case 0x0943d0ULL: return fde_sub_0943d0(a0, a1, a2);
        case 0x0943d4ULL: return fde_sub_0943d4(a0, a1, a2);
        case 0x0943d8ULL: return fde_sub_0943d8(a0, a1, a2);
        case 0x0943fcULL: return fde_sub_0943fc(a0, a1, a2);
        case 0x09440cULL: return fde_sub_09440c(a0, a1, a2);
        case 0x094410ULL: return fde_sub_094410(a0, a1, a2);
        case 0x094414ULL: return fde_sub_094414(a0, a1, a2);
        case 0x09443cULL: return fde_sub_09443c(a0, a1, a2);
        case 0x0945d4ULL: return fde_sub_0945d4(a0, a1, a2);
        case 0x0946c0ULL: return fde_sub_0946c0(a0, a1, a2);
        case 0x09487cULL: return fde_sub_09487c(a0, a1, a2);
        case 0x094958ULL: return fde_sub_094958(a0, a1, a2);
        case 0x094bf4ULL: return fde_sub_094bf4(a0, a1, a2);
        case 0x095c08ULL: return fde_sub_095c08(a0, a1, a2);
        case 0x095f24ULL: return fde_sub_095f24(a0, a1, a2);
        case 0x0960ecULL: return fde_sub_0960ec(a0, a1, a2);
        case 0x096300ULL: return fde_sub_096300(a0, a1, a2);
        case 0x0963ecULL: return fde_sub_0963ec(a0, a1, a2);
        case 0x09649cULL: return fde_sub_09649c(a0, a1, a2);
        case 0x096830ULL: return fde_sub_096830(a0, a1, a2);
        case 0x0968e0ULL: return fde_sub_0968e0(a0, a1, a2);
        case 0x096998ULL: return fde_sub_096998(a0, a1, a2);
        case 0x097180ULL: return fde_sub_097180(a0, a1, a2);
        case 0x0971c4ULL: return fde_sub_0971c4(a0, a1, a2);
        case 0x0974c4ULL: return fde_sub_0974c4(a0, a1, a2);
        case 0x097808ULL: return fde_sub_097808(a0, a1, a2);
        case 0x09798cULL: return fde_sub_09798c(a0, a1, a2);
        case 0x097a80ULL: return fde_sub_097a80(a0, a1, a2);
        default: return 0ULL;
    }
}

uint64_t DispatchRexShard1(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept;
uint64_t DispatchRexShard2(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept;
uint64_t DispatchRexShard3(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept;
uint64_t DispatchRexShard4(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept;

uint64_t ExecuteRexFdeByAddress(uint64_t fde_pc_begin, uint64_t arg0, uint64_t arg1, uint64_t arg2) noexcept {
    if (fde_pc_begin >= 0x001c10ULL && fde_pc_begin <= 0x010facULL) {
        return DispatchRexShard1(fde_pc_begin, arg0, arg1, arg2);
    }
    if (fde_pc_begin >= 0x010fbcULL && fde_pc_begin <= 0x020c20ULL) {
        return DispatchRexShard2(fde_pc_begin, arg0, arg1, arg2);
    }
    if (fde_pc_begin >= 0x020c30ULL && fde_pc_begin <= 0x030254ULL) {
        return DispatchRexShard3(fde_pc_begin, arg0, arg1, arg2);
    }
    if (fde_pc_begin >= 0x030264ULL && fde_pc_begin <= 0x03f5b0ULL) {
        return DispatchRexShard4(fde_pc_begin, arg0, arg1, arg2);
    }
    if (fde_pc_begin >= 0x03feb4ULL && fde_pc_begin <= 0x097a80ULL) {
        return DispatchRexShard5(fde_pc_begin, arg0, arg1, arg2);
    }
    return 0ULL;
}

} // namespace rex
} // namespace bytedance
