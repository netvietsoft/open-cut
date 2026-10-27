// ============================================================================
// File: cxx_shared_fde_shard_1.cpp
// Target 111 / 169: libc++_shared.so (919,888 bytes)
// EN: Clean-room C++17 AArch64 FDE Shard 1/5 covering FDEs [0..390]
//     (PC range 0x0487b0 .. 0x05df98).
// VI: Phân mảnh FDE AArch64 C++17 1/5 bao phủ FDE [0..390]
//     (Dải địa chỉ PC 0x0487b0 .. 0x05df98).
// ============================================================================
#include "cxx_shared_core.h"

namespace ndk_libcxx_recon {

// FDE #0000 | PC: 0x0487b0..0x0487dc (44 B) | Symbol: sub_0487b0
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x47810; adrp x0, #0xe3000] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x47810; adrp x0, #0xe3000]
uint64_t fde_sub_0487b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0487B0ULL;
}

// FDE #0001 | PC: 0x0487dc..0x048940 (356 B) | Symbol: sub_0487dc
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xe6000; ldrb w8, [x8, #0x1a0]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xe6000; ldrb w8, [x8, #0x1a0]]
uint64_t fde_sub_0487dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0164ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0487DCULL;
}

// FDE #0002 | PC: 0x048940..0x048aa4 (356 B) | Symbol: sub_048940
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xe6000; ldrb w8, [x8, #0x2f8]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xe6000; ldrb w8, [x8, #0x2f8]]
uint64_t fde_sub_048940(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0164ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048940ULL;
}

// FDE #0003 | PC: 0x048aa4..0x048aec (72 B) | Symbol: sub_048aa4
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x20, #0xe6000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x20, #0xe6000]
uint64_t fde_sub_048aa4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048AA4ULL;
}

// FDE #0004 | PC: 0x048aec..0x048b34 (72 B) | Symbol: sub_048aec
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x20, #0xe6000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x20, #0xe6000]
uint64_t fde_sub_048aec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048AECULL;
}

// FDE #0005 | PC: 0x048b34..0x048b78 (68 B) | Symbol: sub_048b34
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xe6000; ldrb w8, [x8, #0x7c0]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xe6000; ldrb w8, [x8, #0x7c0]]
uint64_t fde_sub_048b34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048B34ULL;
}

// FDE #0006 | PC: 0x048b78..0x048bbc (68 B) | Symbol: sub_048b78
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xe6000; ldrb w8, [x8, #0x7f8]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xe6000; ldrb w8, [x8, #0x7f8]]
uint64_t fde_sub_048b78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048B78ULL;
}

// FDE #0007 | PC: 0x048bf8..0x048c24 (44 B) | Symbol: _ZNSt6__ndk112__rs_defaultC2Ev
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0xe4000; add x0, x0, #0x104] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0xe4000; add x0, x0, #0x104]
uint64_t fde_sub_048bf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048BF8ULL;
}

// FDE #0008 | PC: 0x048c24..0x048c3c (24 B) | Symbol: _ZNSt6__ndk112__rs_defaultC2ERKS0_
// EN: AArch64 prologue [adrp x8, #0xe3000; ldr x8, [x8, #0xf30]; ldr w9, [x8]; add w9, w9, #1] | VI: Khởi đầu hàm AArch64 [adrp x8, #0xe3000; ldr x8, [x8, #0xf30]; ldr w9, [x8]; add w9, w9, #1]
uint64_t fde_sub_048c24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9479908ULL) << 32) | 0xF00004C8ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048C24ULL;
}

// FDE #0009 | PC: 0x048c3c..0x048c74 (56 B) | Symbol: _ZNSt6__ndk112__rs_defaultD1Ev
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xe3000; ldr x8, [x8, #0xf30]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xe3000; ldr x8, [x8, #0xf30]]
uint64_t fde_sub_048c3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048C3CULL;
}

// FDE #0010 | PC: 0x048c74..0x048dc8 (340 B) | Symbol: _ZNSt6__ndk112__rs_defaultclEv
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xe5000; add x8, x8, #0x4b8] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xe5000; add x8, x8, #0x4b8]
uint64_t fde_sub_048c74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0154ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048C74ULL;
}

// FDE #0011 | PC: 0x048dc8..0x048df4 (44 B) | Symbol: _ZNSt6__ndk18__rs_getEv
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0xe4000; add x0, x0, #0x104] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0xe4000; add x0, x0, #0x104]
uint64_t fde_sub_048dc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048DC8ULL;
}

// FDE #0012 | PC: 0x048df4..0x049320 (1324 B) | Symbol: _ZNSt6__ndk16__sortIRNS_6__lessIccEEPcEEvT0_S5_T_
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_048df4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x052CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x048DF4ULL;
}

// FDE #0013 | PC: 0x049320..0x0494a8 (392 B) | Symbol: sub_049320
// EN: AArch64 prologue [ldrb w11, [x1]; ldrb w10, [x0]; ldrb w9, [x2]; cmp w11, w10] | VI: Khởi đầu hàm AArch64 [ldrb w11, [x1]; ldrb w10, [x0]; ldrb w9, [x2]; cmp w11, w10]
uint64_t fde_sub_049320(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3940000AULL) << 32) | 0x3940002BULL;
    const uint64_t kPcRange = 0x0188ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049320ULL;
}

// FDE #0014 | PC: 0x0494a8..0x04973c (660 B) | Symbol: _ZNSt6__ndk127__insertion_sort_incompleteIRNS_6__lessIccEEPcEEbT0_S5_T_
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x8, x1, x0; cmp x8, #5] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x8, x1, x0; cmp x8, #5]
uint64_t fde_sub_0494a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0294ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0494A8ULL;
}

// FDE #0015 | PC: 0x04973c..0x049c48 (1292 B) | Symbol: _ZNSt6__ndk16__sortIRNS_6__lessIwwEEPwEEvT0_S5_T_
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_04973c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x050CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04973CULL;
}

// FDE #0016 | PC: 0x049c48..0x049dd0 (392 B) | Symbol: sub_049c48
// EN: AArch64 prologue [ldr w11, [x1]; ldr w10, [x0]; ldr w9, [x2]; cmp w11, w10] | VI: Khởi đầu hàm AArch64 [ldr w11, [x1]; ldr w10, [x0]; ldr w9, [x2]; cmp w11, w10]
uint64_t fde_sub_049c48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB940000AULL) << 32) | 0xB940002BULL;
    const uint64_t kPcRange = 0x0188ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049C48ULL;
}

// FDE #0017 | PC: 0x049dd0..0x04a028 (600 B) | Symbol: _ZNSt6__ndk127__insertion_sort_incompleteIRNS_6__lessIwwEEPwEEbT0_S5_T_
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x8, x1, x0; asr x8, x8, #2] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x8, x1, x0; asr x8, x8, #2]
uint64_t fde_sub_049dd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0258ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x049DD0ULL;
}

// FDE #0018 | PC: 0x04a028..0x04a554 (1324 B) | Symbol: _ZNSt6__ndk16__sortIRNS_6__lessIaaEEPaEEvT0_S5_T_
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_04a028(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x052CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A028ULL;
}

// FDE #0019 | PC: 0x04a554..0x04a6dc (392 B) | Symbol: sub_04a554
// EN: AArch64 prologue [ldrsb w11, [x1]; ldrsb w10, [x0]; ldrsb w9, [x2]; cmp w11, w10] | VI: Khởi đầu hàm AArch64 [ldrsb w11, [x1]; ldrsb w10, [x0]; ldrsb w9, [x2]; cmp w11, w10]
uint64_t fde_sub_04a554(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39C0000AULL) << 32) | 0x39C0002BULL;
    const uint64_t kPcRange = 0x0188ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A554ULL;
}

// FDE #0020 | PC: 0x04a6dc..0x04a970 (660 B) | Symbol: _ZNSt6__ndk127__insertion_sort_incompleteIRNS_6__lessIaaEEPaEEbT0_S5_T_
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x8, x1, x0; cmp x8, #5] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x8, x1, x0; cmp x8, #5]
uint64_t fde_sub_04a6dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0294ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A6DCULL;
}

// FDE #0021 | PC: 0x04a970..0x04ae9c (1324 B) | Symbol: _ZNSt6__ndk16__sortIRNS_6__lessIhhEEPhEEvT0_S5_T_
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_04a970(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x052CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04A970ULL;
}

// FDE #0022 | PC: 0x04ae9c..0x04b024 (392 B) | Symbol: sub_04ae9c
// EN: AArch64 prologue [ldrb w11, [x1]; ldrb w10, [x0]; ldrb w9, [x2]; cmp w11, w10] | VI: Khởi đầu hàm AArch64 [ldrb w11, [x1]; ldrb w10, [x0]; ldrb w9, [x2]; cmp w11, w10]
uint64_t fde_sub_04ae9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3940000AULL) << 32) | 0x3940002BULL;
    const uint64_t kPcRange = 0x0188ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04AE9CULL;
}

// FDE #0023 | PC: 0x04b024..0x04b2b8 (660 B) | Symbol: _ZNSt6__ndk127__insertion_sort_incompleteIRNS_6__lessIhhEEPhEEbT0_S5_T_
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x8, x1, x0; cmp x8, #5] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x8, x1, x0; cmp x8, #5]
uint64_t fde_sub_04b024(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0294ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B024ULL;
}

// FDE #0024 | PC: 0x04b2b8..0x04b800 (1352 B) | Symbol: _ZNSt6__ndk16__sortIRNS_6__lessIssEEPsEEvT0_S5_T_
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_04b2b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x0548ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B2B8ULL;
}

// FDE #0025 | PC: 0x04b800..0x04b988 (392 B) | Symbol: sub_04b800
// EN: AArch64 prologue [ldrsh w11, [x1]; ldrsh w10, [x0]; ldrsh w9, [x2]; cmp w11, w10] | VI: Khởi đầu hàm AArch64 [ldrsh w11, [x1]; ldrsh w10, [x0]; ldrsh w9, [x2]; cmp w11, w10]
uint64_t fde_sub_04b800(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x79C0000AULL) << 32) | 0x79C0002BULL;
    const uint64_t kPcRange = 0x0188ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B800ULL;
}

// FDE #0026 | PC: 0x04b988..0x04bc1c (660 B) | Symbol: _ZNSt6__ndk127__insertion_sort_incompleteIRNS_6__lessIssEEPsEEbT0_S5_T_
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x8, x1, x0; asr x8, x8, #1] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x8, x1, x0; asr x8, x8, #1]
uint64_t fde_sub_04b988(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0294ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04B988ULL;
}

// FDE #0027 | PC: 0x04bc1c..0x04c164 (1352 B) | Symbol: _ZNSt6__ndk16__sortIRNS_6__lessIttEEPtEEvT0_S5_T_
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_04bc1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x0548ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04BC1CULL;
}

// FDE #0028 | PC: 0x04c164..0x04c2ec (392 B) | Symbol: sub_04c164
// EN: AArch64 prologue [ldrh w11, [x1]; ldrh w10, [x0]; ldrh w9, [x2]; cmp w11, w10] | VI: Khởi đầu hàm AArch64 [ldrh w11, [x1]; ldrh w10, [x0]; ldrh w9, [x2]; cmp w11, w10]
uint64_t fde_sub_04c164(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7940000AULL) << 32) | 0x7940002BULL;
    const uint64_t kPcRange = 0x0188ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C164ULL;
}

// FDE #0029 | PC: 0x04c2ec..0x04c580 (660 B) | Symbol: _ZNSt6__ndk127__insertion_sort_incompleteIRNS_6__lessIttEEPtEEbT0_S5_T_
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x8, x1, x0; asr x8, x8, #1] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x8, x1, x0; asr x8, x8, #1]
uint64_t fde_sub_04c2ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0294ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C2ECULL;
}

// FDE #0030 | PC: 0x04c580..0x04ca8c (1292 B) | Symbol: _ZNSt6__ndk16__sortIRNS_6__lessIiiEEPiEEvT0_S5_T_
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_04c580(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x050CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04C580ULL;
}

// FDE #0031 | PC: 0x04ca8c..0x04cc14 (392 B) | Symbol: sub_04ca8c
// EN: AArch64 prologue [ldr w11, [x1]; ldr w10, [x0]; ldr w9, [x2]; cmp w11, w10] | VI: Khởi đầu hàm AArch64 [ldr w11, [x1]; ldr w10, [x0]; ldr w9, [x2]; cmp w11, w10]
uint64_t fde_sub_04ca8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB940000AULL) << 32) | 0xB940002BULL;
    const uint64_t kPcRange = 0x0188ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04CA8CULL;
}

// FDE #0032 | PC: 0x04cc14..0x04ce6c (600 B) | Symbol: _ZNSt6__ndk127__insertion_sort_incompleteIRNS_6__lessIiiEEPiEEbT0_S5_T_
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x8, x1, x0; asr x8, x8, #2] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x8, x1, x0; asr x8, x8, #2]
uint64_t fde_sub_04cc14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0258ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04CC14ULL;
}

// FDE #0033 | PC: 0x04ce6c..0x04d378 (1292 B) | Symbol: _ZNSt6__ndk16__sortIRNS_6__lessIjjEEPjEEvT0_S5_T_
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_04ce6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x050CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04CE6CULL;
}

// FDE #0034 | PC: 0x04d378..0x04d500 (392 B) | Symbol: sub_04d378
// EN: AArch64 prologue [ldr w11, [x1]; ldr w10, [x0]; ldr w9, [x2]; cmp w11, w10] | VI: Khởi đầu hàm AArch64 [ldr w11, [x1]; ldr w10, [x0]; ldr w9, [x2]; cmp w11, w10]
uint64_t fde_sub_04d378(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB940000AULL) << 32) | 0xB940002BULL;
    const uint64_t kPcRange = 0x0188ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D378ULL;
}

// FDE #0035 | PC: 0x04d500..0x04d758 (600 B) | Symbol: _ZNSt6__ndk127__insertion_sort_incompleteIRNS_6__lessIjjEEPjEEbT0_S5_T_
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x8, x1, x0; asr x8, x8, #2] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x8, x1, x0; asr x8, x8, #2]
uint64_t fde_sub_04d500(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0258ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D500ULL;
}

// FDE #0036 | PC: 0x04d758..0x04dc78 (1312 B) | Symbol: _ZNSt6__ndk16__sortIRNS_6__lessIllEEPlEEvT0_S5_T_
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_04d758(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x0520ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04D758ULL;
}

// FDE #0037 | PC: 0x04dc78..0x04de00 (392 B) | Symbol: sub_04dc78
// EN: AArch64 prologue [ldr x11, [x1]; ldr x10, [x0]; ldr x9, [x2]; cmp x11, x10] | VI: Khởi đầu hàm AArch64 [ldr x11, [x1]; ldr x10, [x0]; ldr x9, [x2]; cmp x11, x10]
uint64_t fde_sub_04dc78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF940000AULL) << 32) | 0xF940002BULL;
    const uint64_t kPcRange = 0x0188ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04DC78ULL;
}

// FDE #0038 | PC: 0x04de00..0x04e058 (600 B) | Symbol: _ZNSt6__ndk127__insertion_sort_incompleteIRNS_6__lessIllEEPlEEbT0_S5_T_
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x8, x1, x0; asr x8, x8, #3] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x8, x1, x0; asr x8, x8, #3]
uint64_t fde_sub_04de00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0258ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04DE00ULL;
}

// FDE #0039 | PC: 0x04e058..0x04e578 (1312 B) | Symbol: _ZNSt6__ndk16__sortIRNS_6__lessImmEEPmEEvT0_S5_T_
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_04e058(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x0520ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E058ULL;
}

// FDE #0040 | PC: 0x04e578..0x04e700 (392 B) | Symbol: sub_04e578
// EN: AArch64 prologue [ldr x11, [x1]; ldr x10, [x0]; ldr x9, [x2]; cmp x11, x10] | VI: Khởi đầu hàm AArch64 [ldr x11, [x1]; ldr x10, [x0]; ldr x9, [x2]; cmp x11, x10]
uint64_t fde_sub_04e578(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF940000AULL) << 32) | 0xF940002BULL;
    const uint64_t kPcRange = 0x0188ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E578ULL;
}

// FDE #0041 | PC: 0x04e700..0x04e958 (600 B) | Symbol: _ZNSt6__ndk127__insertion_sort_incompleteIRNS_6__lessImmEEPmEEbT0_S5_T_
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x8, x1, x0; asr x8, x8, #3] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x8, x1, x0; asr x8, x8, #3]
uint64_t fde_sub_04e700(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0258ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E700ULL;
}

// FDE #0042 | PC: 0x04e958..0x04ee78 (1312 B) | Symbol: _ZNSt6__ndk16__sortIRNS_6__lessIxxEEPxEEvT0_S5_T_
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_04e958(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x0520ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04E958ULL;
}

// FDE #0043 | PC: 0x04ee78..0x04f000 (392 B) | Symbol: sub_04ee78
// EN: AArch64 prologue [ldr x11, [x1]; ldr x10, [x0]; ldr x9, [x2]; cmp x11, x10] | VI: Khởi đầu hàm AArch64 [ldr x11, [x1]; ldr x10, [x0]; ldr x9, [x2]; cmp x11, x10]
uint64_t fde_sub_04ee78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF940000AULL) << 32) | 0xF940002BULL;
    const uint64_t kPcRange = 0x0188ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04EE78ULL;
}

// FDE #0044 | PC: 0x04f000..0x04f258 (600 B) | Symbol: _ZNSt6__ndk127__insertion_sort_incompleteIRNS_6__lessIxxEEPxEEbT0_S5_T_
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x8, x1, x0; asr x8, x8, #3] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x8, x1, x0; asr x8, x8, #3]
uint64_t fde_sub_04f000(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0258ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F000ULL;
}

// FDE #0045 | PC: 0x04f258..0x04f778 (1312 B) | Symbol: _ZNSt6__ndk16__sortIRNS_6__lessIyyEEPyEEvT0_S5_T_
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_04f258(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x0520ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F258ULL;
}

// FDE #0046 | PC: 0x04f778..0x04f900 (392 B) | Symbol: sub_04f778
// EN: AArch64 prologue [ldr x11, [x1]; ldr x10, [x0]; ldr x9, [x2]; cmp x11, x10] | VI: Khởi đầu hàm AArch64 [ldr x11, [x1]; ldr x10, [x0]; ldr x9, [x2]; cmp x11, x10]
uint64_t fde_sub_04f778(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF940000AULL) << 32) | 0xF940002BULL;
    const uint64_t kPcRange = 0x0188ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F778ULL;
}

// FDE #0047 | PC: 0x04f900..0x04fb58 (600 B) | Symbol: _ZNSt6__ndk127__insertion_sort_incompleteIRNS_6__lessIyyEEPyEEbT0_S5_T_
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x8, x1, x0; asr x8, x8, #3] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x8, x1, x0; asr x8, x8, #3]
uint64_t fde_sub_04f900(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0258ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04F900ULL;
}

// FDE #0048 | PC: 0x04fb58..0x05006c (1300 B) | Symbol: _ZNSt6__ndk16__sortIRNS_6__lessIffEEPfEEvT0_S5_T_
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_04fb58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x0514ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x04FB58ULL;
}

// FDE #0049 | PC: 0x05006c..0x0501f4 (392 B) | Symbol: sub_05006c
// EN: AArch64 prologue [ldr s2, [x1]; ldr s1, [x0]; ldr s0, [x2]; fcmp s2, s1] | VI: Khởi đầu hàm AArch64 [ldr s2, [x1]; ldr s1, [x0]; ldr s0, [x2]; fcmp s2, s1]
uint64_t fde_sub_05006c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xBD400001ULL) << 32) | 0xBD400022ULL;
    const uint64_t kPcRange = 0x0188ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05006CULL;
}

// FDE #0050 | PC: 0x0501f4..0x050454 (608 B) | Symbol: _ZNSt6__ndk127__insertion_sort_incompleteIRNS_6__lessIffEEPfEEbT0_S5_T_
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x8, x1, x0; asr x8, x8, #2] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x8, x1, x0; asr x8, x8, #2]
uint64_t fde_sub_0501f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0260ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0501F4ULL;
}

// FDE #0051 | PC: 0x050454..0x05097c (1320 B) | Symbol: _ZNSt6__ndk16__sortIRNS_6__lessIddEEPdEEvT0_S5_T_
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_050454(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x0528ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x050454ULL;
}

// FDE #0052 | PC: 0x05097c..0x050b04 (392 B) | Symbol: sub_05097c
// EN: AArch64 prologue [ldr d2, [x1]; ldr d1, [x0]; ldr d0, [x2]; fcmp d2, d1] | VI: Khởi đầu hàm AArch64 [ldr d2, [x1]; ldr d1, [x0]; ldr d0, [x2]; fcmp d2, d1]
uint64_t fde_sub_05097c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD400001ULL) << 32) | 0xFD400022ULL;
    const uint64_t kPcRange = 0x0188ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05097CULL;
}

// FDE #0053 | PC: 0x050b04..0x050d64 (608 B) | Symbol: _ZNSt6__ndk127__insertion_sort_incompleteIRNS_6__lessIddEEPdEEbT0_S5_T_
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x8, x1, x0; asr x8, x8, #3] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; sub x8, x1, x0; asr x8, x8, #3]
uint64_t fde_sub_050b04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0260ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x050B04ULL;
}

// FDE #0054 | PC: 0x050d64..0x0514d0 (1900 B) | Symbol: _ZNSt6__ndk16__sortIRNS_6__lessIeeEEPeEEvT0_S5_T_
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]]
uint64_t fde_sub_050d64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9036FFCULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x076CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x050D64ULL;
}

// FDE #0055 | PC: 0x0514d0..0x05174c (636 B) | Symbol: _ZNSt6__ndk17__sort5IRNS_6__lessIeeEEPeEEjT0_S5_S5_S5_S5_T_
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_0514d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9035FF8ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x027CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0514D0ULL;
}

// FDE #0056 | PC: 0x05174c..0x051b14 (968 B) | Symbol: _ZNSt6__ndk127__insertion_sort_incompleteIRNS_6__lessIeeEEPeEEbT0_S5_T_
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_05174c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9035FF8ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x03C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05174CULL;
}

// FDE #0057 | PC: 0x051b14..0x051b20 (12 B) | Symbol: sub_051b14
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x48190; bl #0x480a0] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x48190; bl #0x480a0]
uint64_t fde_sub_051b14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x97FFD99EULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051B14ULL;
}

// FDE #0058 | PC: 0x051b20..0x051b2c (12 B) | Symbol: _ZNKSt12bad_any_cast4whatEv
// EN: AArch64 prologue [adrp x0, #0xb6000; add x0, x0, #0x354; ret] | VI: Khởi đầu hàm AArch64 [adrp x0, #0xb6000; add x0, x0, #0x354; ret]
uint64_t fde_sub_051b20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910D5000ULL) << 32) | 0xB0000320ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051B20ULL;
}

// FDE #0059 | PC: 0x051b2c..0x051b38 (12 B) | Symbol: _ZNKSt12experimental15fundamentals_v112bad_any_cast4whatEv
// EN: AArch64 prologue [adrp x0, #0xb6000; add x0, x0, #0x354; ret] | VI: Khởi đầu hàm AArch64 [adrp x0, #0xb6000; add x0, x0, #0x354; ret]
uint64_t fde_sub_051b2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910D5000ULL) << 32) | 0xB0000320ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051B2CULL;
}

// FDE #0060 | PC: 0x051b38..0x051b5c (36 B) | Symbol: _ZNSt12bad_any_castD0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_051b38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051B38ULL;
}

// FDE #0061 | PC: 0x051b5c..0x051b80 (36 B) | Symbol: _ZNSt12experimental15fundamentals_v112bad_any_castD0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_051b5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051B5CULL;
}

// FDE #0062 | PC: 0x051b80..0x051cfc (380 B) | Symbol: _ZNSt6__ndk16__itoa8__u32toaEjPc
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w8, #0xe100] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w8, #0xe100]
uint64_t fde_sub_051b80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x017CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051B80ULL;
}

// FDE #0063 | PC: 0x051cfc..0x051ffc (768 B) | Symbol: _ZNSt6__ndk16__itoa8__u64toaEmPc
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_051cfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0300ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051CFCULL;
}

// FDE #0064 | PC: 0x051ffc..0x0520d4 (216 B) | Symbol: sub_051ffc
// EN: AArch64 prologue [cmp w1, #0x63; b.hi #0x52020; cmp w1, #9; b.hi #0x52070] | VI: Khởi đầu hàm AArch64 [cmp w1, #0x63; b.hi #0x52020; cmp w1, #9; b.hi #0x52070]
uint64_t fde_sub_051ffc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000108ULL) << 32) | 0x71018C3FULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x051FFCULL;
}

// FDE #0065 | PC: 0x0520d4..0x052168 (148 B) | Symbol: _ZNSt6__ndk16chrono12system_clock3nowEv
// EN: AArch64 prologue [sub sp, sp, #0x40; str x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30]
uint64_t fde_sub_0520d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F3ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0520D4ULL;
}

// FDE #0066 | PC: 0x052168..0x05218c (36 B) | Symbol: _ZNSt6__ndk16chrono12system_clock9to_time_tERKNS0_10time_pointIS1_NS0_8durationIxNS_5ratioILl1ELl1000000EEEEEEE
// EN: AArch64 prologue [ldr x8, [x0]; mov x9, #0x34db; movk x9, #0xd7b6, lsl #16; movk x9, #0xde82, lsl #32] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; mov x9, #0x34db; movk x9, #0xd7b6, lsl #16; movk x9, #0xde82, lsl #32]
uint64_t fde_sub_052168(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD2869B69ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052168ULL;
}

// FDE #0067 | PC: 0x05218c..0x05219c (16 B) | Symbol: _ZNSt6__ndk16chrono12system_clock11from_time_tEl
// EN: AArch64 prologue [mov w8, #0x4240; movk w8, #0xf, lsl #16; mul x0, x0, x8; ret] | VI: Khởi đầu hàm AArch64 [mov w8, #0x4240; movk w8, #0xf, lsl #16; mul x0, x0, x8; ret]
uint64_t fde_sub_05218c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x72A001E8ULL) << 32) | 0x52884808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05218CULL;
}

// FDE #0068 | PC: 0x05219c..0x052214 (120 B) | Symbol: _ZNSt6__ndk16chrono12steady_clock3nowEv
// EN: AArch64 prologue [sub sp, sp, #0x40; str x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30]
uint64_t fde_sub_05219c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F3ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05219CULL;
}

// FDE #0069 | PC: 0x052214..0x05222c (24 B) | Symbol: _ZNSt6__ndk118condition_variable10notify_oneEv
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x48710; ldp x29, x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x48710; ldp x29, x30, [sp], #0x10]
uint64_t fde_sub_052214(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052214ULL;
}

// FDE #0070 | PC: 0x05222c..0x052244 (24 B) | Symbol: _ZNSt6__ndk118condition_variable10notify_allEv
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x485a0; ldp x29, x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x485a0; ldp x29, x30, [sp], #0x10]
uint64_t fde_sub_05222c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05222CULL;
}

// FDE #0071 | PC: 0x052244..0x05228c (72 B) | Symbol: _ZNSt6__ndk118condition_variable4waitERNS_11unique_lockINS_5mutexEEE
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x1, #8]; cbz w8, #0x52268] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldrb w8, [x1, #8]; cbz w8, #0x52268]
uint64_t fde_sub_052244(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052244ULL;
}

// FDE #0072 | PC: 0x05228c..0x052350 (196 B) | Symbol: _ZNSt6__ndk118condition_variable15__do_timed_waitERNS_11unique_lockINS_5mutexEEENS_6chrono10time_pointINS5_12system_clockENS5_8durationIxNS_5ratioILl1ELl1000000000EEEEEEE
// EN: AArch64 prologue [sub sp, sp, #0x40; str x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30]
uint64_t fde_sub_05228c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F3ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05228CULL;
}

// FDE #0073 | PC: 0x052350..0x0523d8 (136 B) | Symbol: _ZNSt6__ndk125notify_all_at_thread_exitERNS_18condition_variableENS_11unique_lockINS_5mutexEEE
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_052350(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052350ULL;
}

// FDE #0074 | PC: 0x0523d8..0x0523f0 (24 B) | Symbol: _ZNSt6__ndk118condition_variableD2Ev
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x47390; ldp x29, x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x47390; ldp x29, x30, [sp], #0x10]
uint64_t fde_sub_0523d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0523D8ULL;
}

// FDE #0075 | PC: 0x0523f0..0x05260c (540 B) | Symbol: _ZNKSt6__ndk119__libcpp_debug_info4whatEv
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x22, x21, [sp, #0x60]; stp x20, x19, [sp, #0x70]; stp x29, x30, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x22, x21, [sp, #0x60]; stp x20, x19, [sp, #0x70]; stp x29, x30, [sp, #0x80]]
uint64_t fde_sub_0523f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90657F6ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x021CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0523F0ULL;
}

// FDE #0076 | PC: 0x05260c..0x052660 (84 B) | Symbol: _ZNSt6__ndk129__libcpp_abort_debug_functionERKNS_19__libcpp_debug_infoE
// EN: AArch64 prologue [sub sp, sp, #0x40; str x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30]
uint64_t fde_sub_05260c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F3ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05260CULL;
}

// FDE #0077 | PC: 0x052660..0x052678 (24 B) | Symbol: _ZNSt6__ndk127__libcpp_set_debug_functionEPFvRKNS_19__libcpp_debug_infoEE
// EN: AArch64 prologue [adrp x9, #0xe3000; ldr x9, [x9, #0xb30]; mov x8, x0; mov w0, #1] | VI: Khởi đầu hàm AArch64 [adrp x9, #0xe3000; ldr x9, [x9, #0xb30]; mov x8, x0; mov w0, #1]
uint64_t fde_sub_052660(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9459929ULL) << 32) | 0xB0000489ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052660ULL;
}

// FDE #0078 | PC: 0x052678..0x0526d4 (92 B) | Symbol: _ZNSt6__ndk18__get_dbEv
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xe5000; add x8, x8, #0x4f0] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xe5000; add x8, x8, #0x4f0]
uint64_t fde_sub_052678(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052678ULL;
}

// FDE #0079 | PC: 0x0526d4..0x052730 (92 B) | Symbol: _ZNSt6__ndk114__get_const_dbEv
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xe5000; add x8, x8, #0x4f0] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xe5000; add x8, x8, #0x4f0]
uint64_t fde_sub_0526d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0526D4ULL;
}

// FDE #0080 | PC: 0x052730..0x052768 (56 B) | Symbol: _ZNSt6__ndk18__i_nodeD1Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_052730(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052730ULL;
}

// FDE #0081 | PC: 0x052768..0x0527c0 (88 B) | Symbol: _ZNSt6__ndk18__c_nodeD1Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_052768(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052768ULL;
}

// FDE #0082 | PC: 0x0527c0..0x0527c4 (4 B) | Symbol: _ZNSt6__ndk18__c_nodeD0Ev
// EN: AArch64 prologue [brk #1] | VI: Khởi đầu hàm AArch64 [brk #1]
uint64_t fde_sub_0527c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6F00E400ULL) << 32) | 0xD4200020ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0527C0ULL;
}

// FDE #0083 | PC: 0x0527c4..0x0527d4 (16 B) | Symbol: _ZNSt6__ndk111__libcpp_dbC1Ev
// EN: AArch64 prologue [movi v0.2d, #0000000000000000; stp q0, q0, [x0, #0x10]; str q0, [x0]; ret] | VI: Khởi đầu hàm AArch64 [movi v0.2d, #0000000000000000; stp q0, q0, [x0, #0x10]; str q0, [x0]; ret]
uint64_t fde_sub_0527c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAD008000ULL) << 32) | 0x6F00E400ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0527C4ULL;
}

// FDE #0084 | PC: 0x0527d4..0x052898 (196 B) | Symbol: _ZNSt6__ndk111__libcpp_dbD2Ev
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0]]
uint64_t fde_sub_0527d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0527D4ULL;
}

// FDE #0085 | PC: 0x052898..0x05297c (228 B) | Symbol: _ZNKSt6__ndk111__libcpp_db15__find_c_from_iEPv
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000]
uint64_t fde_sub_052898(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052898ULL;
}

// FDE #0086 | PC: 0x05297c..0x0529f8 (124 B) | Symbol: sub_05297c
// EN: AArch64 prologue [ldp x8, x9, [x0, #0x18]; cmp x8, x9; b.eq #0x529f0; mov x12, #0x2d69] | VI: Khởi đầu hàm AArch64 [ldp x8, x9, [x0, #0x18]; cmp x8, x9; b.eq #0x529f0; mov x12, #0x2d69]
uint64_t fde_sub_05297c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xA941A408ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05297CULL;
}

// FDE #0087 | PC: 0x0529f8..0x052b14 (284 B) | Symbol: _ZNSt6__ndk111__libcpp_db11__insert_icEPvPKv
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0529f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0529F8ULL;
}

// FDE #0088 | PC: 0x052b14..0x052c80 (364 B) | Symbol: sub_052b14
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_052b14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x016CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052B14ULL;
}

// FDE #0089 | PC: 0x052c80..0x052d28 (168 B) | Symbol: _ZNSt6__ndk18__c_node5__addEPNS_8__i_nodeE
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_052c80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052C80ULL;
}

// FDE #0090 | PC: 0x052d28..0x052f04 (476 B) | Symbol: _ZNSt6__ndk111__libcpp_db10__insert_cEPvPFPNS_8__c_nodeES1_S1_S3_E
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_052d28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x01DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052D28ULL;
}

// FDE #0091 | PC: 0x052f04..0x05306c (360 B) | Symbol: _ZNSt6__ndk111__libcpp_db9__erase_iEPv
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_052f04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0168ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x052F04ULL;
}

// FDE #0092 | PC: 0x05306c..0x0530c4 (88 B) | Symbol: sub_05306c
// EN: AArch64 prologue [mov x8, x0; ldp x9, x0, [x0, #0x18]; cmp x9, x0; b.eq #0x530a0] | VI: Khởi đầu hàm AArch64 [mov x8, x0; ldp x9, x0, [x0, #0x18]; cmp x9, x0; b.eq #0x530a0]
uint64_t fde_sub_05306c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9418009ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05306CULL;
}

// FDE #0093 | PC: 0x0530c4..0x0531c0 (252 B) | Symbol: _ZNSt6__ndk111__libcpp_db16__invalidate_allEPv
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000]
uint64_t fde_sub_0530c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0530C4ULL;
}

// FDE #0094 | PC: 0x0531c0..0x0532c8 (264 B) | Symbol: _ZNKSt6__ndk111__libcpp_db17__find_c_and_lockEPv
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0531c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0108ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0531C0ULL;
}

// FDE #0095 | PC: 0x0532c8..0x053330 (104 B) | Symbol: _ZNKSt6__ndk111__libcpp_db8__find_cEPv
// EN: AArch64 prologue [mov x10, #0x2d69; lsl w9, w1, #3; movk x10, #0xeb38, lsl #16; lsr x8, x1, #0x20] | VI: Khởi đầu hàm AArch64 [mov x10, #0x2d69; lsl w9, w1, #3; movk x10, #0xeb38, lsl #16; lsr x8, x1, #0x20]
uint64_t fde_sub_0532c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x531D7029ULL) << 32) | 0xD285AD2AULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0532C8ULL;
}

// FDE #0096 | PC: 0x053330..0x053378 (72 B) | Symbol: _ZNKSt6__ndk111__libcpp_db6unlockEv
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xe5000; add x8, x8, #0x520] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x8, #0xe5000; add x8, x8, #0x520]
uint64_t fde_sub_053330(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053330ULL;
}

// FDE #0097 | PC: 0x053378..0x0534b4 (316 B) | Symbol: _ZNSt6__ndk111__libcpp_db9__erase_cEPv
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_053378(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x013CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053378ULL;
}

// FDE #0098 | PC: 0x0534b4..0x0536b4 (512 B) | Symbol: _ZNSt6__ndk111__libcpp_db15__iterator_copyEPvPKv
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0534b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0200ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0534B4ULL;
}

// FDE #0099 | PC: 0x0536b4..0x0537d0 (284 B) | Symbol: _ZNKSt6__ndk111__libcpp_db17__dereferenceableEPKv
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000]
uint64_t fde_sub_0536b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0536B4ULL;
}

// FDE #0100 | PC: 0x0537d0..0x0538ec (284 B) | Symbol: _ZNKSt6__ndk111__libcpp_db15__decrementableEPKv
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000]
uint64_t fde_sub_0537d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0537D0ULL;
}

// FDE #0101 | PC: 0x0538ec..0x053a18 (300 B) | Symbol: _ZNKSt6__ndk111__libcpp_db9__addableEPKvl
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0538ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0538ECULL;
}

// FDE #0102 | PC: 0x053a18..0x053b44 (300 B) | Symbol: _ZNKSt6__ndk111__libcpp_db15__subscriptableEPKvl
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_053a18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053A18ULL;
}

// FDE #0103 | PC: 0x053b44..0x053ca8 (356 B) | Symbol: _ZNKSt6__ndk111__libcpp_db22__less_than_comparableEPKvS2_
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_053b44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0164ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053B44ULL;
}

// FDE #0104 | PC: 0x053ca8..0x053e2c (388 B) | Symbol: _ZNSt6__ndk111__libcpp_db4swapEPvS1_
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_053ca8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0184ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053CA8ULL;
}

// FDE #0105 | PC: 0x053e2c..0x053eb4 (136 B) | Symbol: _ZNSt6__ndk111__libcpp_db10__insert_iEPv
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000]
uint64_t fde_sub_053e2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053E2CULL;
}

// FDE #0106 | PC: 0x053eb4..0x053f4c (152 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2IDnEEPKc
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_053eb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053EB4ULL;
}

// FDE #0107 | PC: 0x053f4c..0x053f60 (20 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev
// EN: AArch64 prologue [ldrb w8, [x0]; tbnz w8, #0, #0x53f58; ret; ldr x0, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0]; tbnz w8, #0, #0x53f58; ret; ldr x0, [x0, #0x10]]
uint64_t fde_sub_053f4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x37000048ULL) << 32) | 0x39400008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053F4CULL;
}

// FDE #0108 | PC: 0x053f60..0x053f74 (20 B) | Symbol: _ZNKSt6__ndk121__basic_string_commonILb1EE20__throw_length_errorEv
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0xba000; add x0, x0, #0x6f4] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0xba000; add x0, x0, #0x6f4]
uint64_t fde_sub_053f60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053F60ULL;
}

// FDE #0109 | PC: 0x053f74..0x053fc4 (80 B) | Symbol: sub_053f74
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0]
uint64_t fde_sub_053f74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053F74ULL;
}

// FDE #0110 | PC: 0x053fc4..0x053ff4 (48 B) | Symbol: sub_053fc4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_053fc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053FC4ULL;
}

// FDE #0111 | PC: 0x053ff4..0x054118 (292 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKcm
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_053ff4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0124ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x053FF4ULL;
}

// FDE #0112 | PC: 0x054118..0x05412c (20 B) | Symbol: _ZNKSt6__ndk121__basic_string_commonILb1EE20__throw_out_of_rangeEv
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0xba000; add x0, x0, #0x6f4] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0xba000; add x0, x0, #0x6f4]
uint64_t fde_sub_054118(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054118ULL;
}

// FDE #0113 | PC: 0x05412c..0x054264 (312 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE21__grow_by_and_replaceEmmmmmmPKc
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_05412c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0138ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05412CULL;
}

// FDE #0114 | PC: 0x054264..0x0542b4 (80 B) | Symbol: sub_054264
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0]
uint64_t fde_sub_054264(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054264ULL;
}

// FDE #0115 | PC: 0x0542b4..0x0542e4 (48 B) | Symbol: sub_0542b4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0542b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0542B4ULL;
}

// FDE #0116 | PC: 0x0542e4..0x0543a8 (196 B) | Symbol: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0542e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0542E4ULL;
}

// FDE #0117 | PC: 0x0543a8..0x0543c4 (28 B) | Symbol: _ZSt18uncaught_exceptionv
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x47ac0; cmp w0, #0] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl #0x47ac0; cmp w0, #0]
uint64_t fde_sub_0543a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0543A8ULL;
}

// FDE #0118 | PC: 0x0543c4..0x0543c8 (4 B) | Symbol: _ZSt19uncaught_exceptionsv
// EN: AArch64 prologue [b #0x47ac0] | VI: Khởi đầu hàm AArch64 [b #0x47ac0]
uint64_t fde_sub_0543c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400000ULL) << 32) | 0x17FFCDBFULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0543C4ULL;
}

// FDE #0119 | PC: 0x0543c8..0x0543d0 (8 B) | Symbol: _ZNSt13exception_ptrD1Ev
// EN: AArch64 prologue [ldr x0, [x0]; b #0x48270] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0]; b #0x48270]
uint64_t fde_sub_0543c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFCFA9ULL) << 32) | 0xF9400000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0543C8ULL;
}

// FDE #0120 | PC: 0x0543d0..0x0543e0 (16 B) | Symbol: _ZNSt13exception_ptrC2ERKS_
// EN: AArch64 prologue [ldr x8, [x1]; str x8, [x0]; mov x0, x8; b #0x483f0] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1]; str x8, [x0]; mov x0, x8; b #0x483f0]
uint64_t fde_sub_0543d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000008ULL) << 32) | 0xF9400028ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0543D0ULL;
}

// FDE #0121 | PC: 0x0543e0..0x054428 (72 B) | Symbol: _ZNSt13exception_ptraSERKS_
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0543e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0543E0ULL;
}

// FDE #0122 | PC: 0x054428..0x05445c (52 B) | Symbol: _ZNSt16nested_exceptionC2Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_054428(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054428ULL;
}

// FDE #0123 | PC: 0x05445c..0x054480 (36 B) | Symbol: _ZSt17current_exceptionv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x8] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x8]
uint64_t fde_sub_05445c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05445CULL;
}

// FDE #0124 | PC: 0x054480..0x05449c (28 B) | Symbol: _ZNSt16nested_exceptionD1Ev
// EN: AArch64 prologue [adrp x9, #0xe3000; ldr x8, [x0, #8]; ldr x9, [x9, #0xd40]; add x9, x9, #0x10] | VI: Khởi đầu hàm AArch64 [adrp x9, #0xe3000; ldr x8, [x0, #8]; ldr x9, [x9, #0xd40]; add x9, x9, #0x10]
uint64_t fde_sub_054480(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400408ULL) << 32) | 0xF0000469ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054480ULL;
}

// FDE #0125 | PC: 0x05449c..0x0544d4 (56 B) | Symbol: _ZNSt16nested_exceptionD0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_05449c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05449CULL;
}

// FDE #0126 | PC: 0x0544d4..0x054528 (84 B) | Symbol: _ZNKSt16nested_exception14rethrow_nestedEv
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0544d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0544D4ULL;
}

// FDE #0127 | PC: 0x054528..0x05453c (20 B) | Symbol: _ZSt17rethrow_exceptionSt13exception_ptr
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x0, [x0]; bl #0x479c0] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x0, [x0]; bl #0x479c0]
uint64_t fde_sub_054528(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054528ULL;
}

// FDE #0128 | PC: 0x05453c..0x054548 (12 B) | Symbol: sub_05453c
// EN: AArch64 prologue [adrp x0, #0xb6000; add x0, x0, #0x5af; ret] | VI: Khởi đầu hàm AArch64 [adrp x0, #0xb6000; add x0, x0, #0x5af; ret]
uint64_t fde_sub_05453c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9116BC00ULL) << 32) | 0xD0000300ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05453CULL;
}

// FDE #0129 | PC: 0x054548..0x054570 (40 B) | Symbol: sub_054548
// EN: AArch64 prologue [cmp w1, #4; mov x0, x8; b.hi #0x54564; adrp x8, #0xdc000] | VI: Khởi đầu hàm AArch64 [cmp w1, #4; mov x0, x8; b.hi #0x54564; adrp x8, #0xdc000]
uint64_t fde_sub_054548(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0x7100103FULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054548ULL;
}

// FDE #0130 | PC: 0x054570..0x0545f4 (132 B) | Symbol: _ZNSt6__ndk115future_categoryEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000]
uint64_t fde_sub_054570(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054570ULL;
}

// FDE #0131 | PC: 0x0545f4..0x054698 (164 B) | Symbol: _ZNSt6__ndk112future_errorC1ENS_10error_codeE
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]; add x29, sp, #0x40] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]; add x29, sp, #0x40]
uint64_t fde_sub_0545f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9034FF4ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0545F4ULL;
}

// FDE #0132 | PC: 0x054698..0x05469c (4 B) | Symbol: _ZNSt6__ndk112future_errorD2Ev
// EN: AArch64 prologue [b #0x47060] | VI: Khởi đầu hàm AArch64 [b #0x47060]
uint64_t fde_sub_054698(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0x17FFCA72ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054698ULL;
}

// FDE #0133 | PC: 0x05469c..0x0546c0 (36 B) | Symbol: _ZNSt6__ndk112future_errorD0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_05469c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05469CULL;
}

// FDE #0134 | PC: 0x0546c0..0x0546d4 (20 B) | Symbol: _ZNSt6__ndk117__assoc_sub_state16__on_zero_sharedEv
// EN: AArch64 prologue [cbz x0, #0x546d0; ldr x8, [x0]; ldr x1, [x8, #8]; br x1] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x546d0; ldr x8, [x0]; ldr x1, [x8, #8]; br x1]
uint64_t fde_sub_0546c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xB4000080ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0546C0ULL;
}

// FDE #0135 | PC: 0x0546d4..0x054784 (176 B) | Symbol: _ZNSt6__ndk117__assoc_sub_state9set_valueEv
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0546d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0546D4ULL;
}

// FDE #0136 | PC: 0x054784..0x05483c (184 B) | Symbol: _ZNSt6__ndk117__assoc_sub_state24set_value_at_thread_exitEv
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_054784(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054784ULL;
}

// FDE #0137 | PC: 0x05483c..0x054900 (196 B) | Symbol: _ZNSt6__ndk117__assoc_sub_state13set_exceptionESt13exception_ptr
// EN: AArch64 prologue [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_05483c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05483CULL;
}

// FDE #0138 | PC: 0x054900..0x0549c4 (196 B) | Symbol: _ZNSt6__ndk117__assoc_sub_state28set_exception_at_thread_exitESt13exception_ptr
// EN: AArch64 prologue [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_054900(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054900ULL;
}

// FDE #0139 | PC: 0x0549c4..0x054a04 (64 B) | Symbol: _ZNSt6__ndk117__assoc_sub_state12__make_readyEv
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; add x20, x0, #0x18] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; add x20, x0, #0x18]
uint64_t fde_sub_0549c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0549C4ULL;
}

// FDE #0140 | PC: 0x054a04..0x054b20 (284 B) | Symbol: _ZNSt6__ndk117__assoc_sub_state4copyEv
// EN: AArch64 prologue [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_054a04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF5ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054A04ULL;
}

// FDE #0141 | PC: 0x054b20..0x054bb4 (148 B) | Symbol: _ZNSt6__ndk117__assoc_sub_state10__sub_waitERNS_11unique_lockINS_5mutexEEE
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_054b20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054B20ULL;
}

// FDE #0142 | PC: 0x054bb4..0x054c90 (220 B) | Symbol: _ZNSt6__ndk117__assoc_sub_state4waitEv
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_054bb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054BB4ULL;
}

// FDE #0143 | PC: 0x054c90..0x054ca0 (16 B) | Symbol: _ZNSt6__ndk117__assoc_sub_state9__executeEv
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w0, #3; bl #0x5518c] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov w0, #3; bl #0x5518c]
uint64_t fde_sub_054c90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054C90ULL;
}

// FDE #0144 | PC: 0x054ca0..0x054d08 (104 B) | Symbol: _ZNSt6__ndk16futureIvEC1EPNS_17__assoc_sub_stateE
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; add x19, x1, #0x18] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; add x19, x1, #0x18]
uint64_t fde_sub_054ca0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054CA0ULL;
}

// FDE #0145 | PC: 0x054d08..0x054d18 (16 B) | Symbol: _ZNSt6__ndk16futureIvED1Ev
// EN: AArch64 prologue [ldr x0, [x0]; cbz x0, #0x54d14; b #0x48020; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0]; cbz x0, #0x54d14; b #0x48020; ret]
uint64_t fde_sub_054d08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000040ULL) << 32) | 0xF9400000ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054D08ULL;
}

// FDE #0146 | PC: 0x054d18..0x054d6c (84 B) | Symbol: _ZNSt6__ndk16futureIvE3getEv
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0]]
uint64_t fde_sub_054d18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054D18ULL;
}

// FDE #0147 | PC: 0x054d6c..0x054db8 (76 B) | Symbol: _ZNSt6__ndk17promiseIvEC2Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_054d6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054D6CULL;
}

// FDE #0148 | PC: 0x054db8..0x054f80 (456 B) | Symbol: _ZNSt6__ndk17promiseIvED1Ev
// EN: AArch64 prologue [sub sp, sp, #0x90; str x21, [sp, #0x60]; stp x20, x19, [sp, #0x70]; stp x29, x30, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x21, [sp, #0x60]; stp x20, x19, [sp, #0x70]; stp x29, x30, [sp, #0x80]]
uint64_t fde_sub_054db8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90033F5ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x01C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054DB8ULL;
}

// FDE #0149 | PC: 0x054f80..0x054ff4 (116 B) | Symbol: _ZNSt6__ndk17promiseIvE10get_futureEv
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x20, [x0]]
uint64_t fde_sub_054f80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054F80ULL;
}

// FDE #0150 | PC: 0x054ff4..0x055014 (32 B) | Symbol: _ZNSt6__ndk17promiseIvE9set_valueEv
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x0, [x0]; cbz x0, #0x5500c] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x0, [x0]; cbz x0, #0x5500c]
uint64_t fde_sub_054ff4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x054FF4ULL;
}

// FDE #0151 | PC: 0x055014..0x055094 (128 B) | Symbol: _ZNSt6__ndk17promiseIvE13set_exceptionESt13exception_ptr
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_055014(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055014ULL;
}

// FDE #0152 | PC: 0x055094..0x0550b4 (32 B) | Symbol: _ZNSt6__ndk17promiseIvE24set_value_at_thread_exitEv
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x0, [x0]; cbz x0, #0x550ac] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x0, [x0]; cbz x0, #0x550ac]
uint64_t fde_sub_055094(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055094ULL;
}

// FDE #0153 | PC: 0x0550b4..0x055134 (128 B) | Symbol: _ZNSt6__ndk17promiseIvE28set_exception_at_thread_exitESt13exception_ptr
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0550b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0550B4ULL;
}

// FDE #0154 | PC: 0x055134..0x055144 (16 B) | Symbol: _ZNSt6__ndk113shared_futureIvED2Ev
// EN: AArch64 prologue [ldr x0, [x0]; cbz x0, #0x55140; b #0x48020; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0]; cbz x0, #0x55140; b #0x48020; ret]
uint64_t fde_sub_055134(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000040ULL) << 32) | 0xF9400000ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055134ULL;
}

// FDE #0155 | PC: 0x055144..0x05518c (72 B) | Symbol: _ZNSt6__ndk113shared_futureIvEaSERKS1_
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x1]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x1]]
uint64_t fde_sub_055144(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055144ULL;
}

// FDE #0156 | PC: 0x05518c..0x05524c (192 B) | Symbol: sub_05518c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05518c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05518CULL;
}

// FDE #0157 | PC: 0x05524c..0x0552cc (128 B) | Symbol: sub_05524c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05524c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05524CULL;
}

// FDE #0158 | PC: 0x0552cc..0x055318 (76 B) | Symbol: _ZNSt6__ndk117__assoc_sub_stateD2Ev
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_0552cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0552CCULL;
}

// FDE #0159 | PC: 0x055318..0x05536c (84 B) | Symbol: _ZNSt6__ndk117__assoc_sub_stateD0Ev
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_055318(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055318ULL;
}

// FDE #0160 | PC: 0x05536c..0x055390 (36 B) | Symbol: sub_05536c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_05536c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05536CULL;
}

// FDE #0161 | PC: 0x055390..0x055aa8 (1816 B) | Symbol: _ZNSt6__ndk112__next_primeEm
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; cmp x0, #0xd3; b.hi #0x553d8] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; cmp x0, #0xd3; b.hi #0x553d8]
uint64_t fde_sub_055390(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0718ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055390ULL;
}

// FDE #0162 | PC: 0x055aa8..0x055af8 (80 B) | Symbol: sub_055aa8
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0]
uint64_t fde_sub_055aa8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055AA8ULL;
}

// FDE #0163 | PC: 0x055af8..0x055b28 (48 B) | Symbol: sub_055af8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_055af8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055AF8ULL;
}

// FDE #0164 | PC: 0x055b28..0x055bac (132 B) | Symbol: _ZNSt6__ndk18ios_baseD1Ev
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000]
uint64_t fde_sub_055b28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055B28ULL;
}

// FDE #0165 | PC: 0x055bac..0x055c04 (88 B) | Symbol: _ZNSt6__ndk18ios_base16__call_callbacksENS0_5eventE
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_055bac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055BACULL;
}

// FDE #0166 | PC: 0x055c04..0x055ec8 (708 B) | Symbol: _ZNSt6__ndk18ios_base7copyfmtERKS0_
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_055c04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x02C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055C04ULL;
}

// FDE #0167 | PC: 0x055ec8..0x055ed4 (12 B) | Symbol: _ZNKSt6__ndk18ios_base6getlocEv
// EN: AArch64 prologue [add x1, x0, #0x30; mov x0, x8; b #0x477e0] | VI: Khởi đầu hàm AArch64 [add x1, x0, #0x30; mov x0, x8; b #0x477e0]
uint64_t fde_sub_055ec8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0x9100C001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055EC8ULL;
}

// FDE #0168 | PC: 0x055ed4..0x055efc (40 B) | Symbol: _ZNSt6__ndk18ios_base33__set_badbit_and_consider_rethrowEv
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr w8, [x0, #0x20]; ldrb w9, [x0, #0x24]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr w8, [x0, #0x20]; ldrb w9, [x0, #0x24]]
uint64_t fde_sub_055ed4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055ED4ULL;
}

// FDE #0169 | PC: 0x055efc..0x055f24 (40 B) | Symbol: _ZNSt6__ndk18ios_base34__set_failbit_and_consider_rethrowEv
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr w8, [x0, #0x20]; ldrb w9, [x0, #0x24]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr w8, [x0, #0x20]; ldrb w9, [x0, #0x24]]
uint64_t fde_sub_055efc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055EFCULL;
}

// FDE #0170 | PC: 0x055f24..0x055f30 (12 B) | Symbol: sub_055f24
// EN: AArch64 prologue [adrp x0, #0xba000; add x0, x0, #0x87d; ret] | VI: Khởi đầu hàm AArch64 [adrp x0, #0xba000; add x0, x0, #0x87d; ret]
uint64_t fde_sub_055f24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9121F400ULL) << 32) | 0xB0000320ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055F24ULL;
}

// FDE #0171 | PC: 0x055f30..0x055f54 (36 B) | Symbol: sub_055f30
// EN: AArch64 prologue [cmp w1, #1; b.eq #0x55f44; cmp w1, #0xfff; b.gt #0x55f44] | VI: Khởi đầu hàm AArch64 [cmp w1, #1; b.eq #0x55f44; cmp w1, #0xfff; b.gt #0x55f44]
uint64_t fde_sub_055f30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000080ULL) << 32) | 0x7100043FULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055F30ULL;
}

// FDE #0172 | PC: 0x055f54..0x055fd8 (132 B) | Symbol: _ZNSt6__ndk117iostream_categoryEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000]
uint64_t fde_sub_055f54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055F54ULL;
}

// FDE #0173 | PC: 0x055fd8..0x056010 (56 B) | Symbol: _ZNSt6__ndk18ios_base7failureC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERKNS_10error_codeE
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x3, x1] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x3, x1]
uint64_t fde_sub_055fd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x055FD8ULL;
}

// FDE #0174 | PC: 0x056010..0x056048 (56 B) | Symbol: _ZNSt6__ndk18ios_base7failureC1EPKcRKNS_10error_codeE
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x3, x1] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x3, x1]
uint64_t fde_sub_056010(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056010ULL;
}

// FDE #0175 | PC: 0x056048..0x05604c (4 B) | Symbol: _ZNSt6__ndk18ios_base7failureD1Ev
// EN: AArch64 prologue [b #0x47560] | VI: Khởi đầu hàm AArch64 [b #0x47560]
uint64_t fde_sub_056048(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0x17FFC546ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056048ULL;
}

// FDE #0176 | PC: 0x05604c..0x056070 (36 B) | Symbol: _ZNSt6__ndk18ios_base7failureD0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_05604c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05604CULL;
}

// FDE #0177 | PC: 0x056070..0x0560fc (140 B) | Symbol: _ZNSt6__ndk18ios_base5imbueERKNS_6localeE
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_056070(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056070ULL;
}

// FDE #0178 | PC: 0x0560fc..0x056118 (28 B) | Symbol: _ZNSt6__ndk18ios_base6xallocEv
// EN: AArch64 prologue [adrp x8, #0xe3000; ldr x8, [x8, #0xe60]; ldaxr w0, [x8]; add w9, w0, #1] | VI: Khởi đầu hàm AArch64 [adrp x8, #0xe3000; ldr x8, [x8, #0xe60]; ldaxr w0, [x8]; add w9, w0, #1]
uint64_t fde_sub_0560fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9473108ULL) << 32) | 0xB0000468ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0560FCULL;
}

// FDE #0179 | PC: 0x056118..0x05621c (260 B) | Symbol: _ZNSt6__ndk18ios_base5iwordEi
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_056118(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056118ULL;
}

// FDE #0180 | PC: 0x05621c..0x0562fc (224 B) | Symbol: _ZNSt6__ndk18ios_base5pwordEi
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05621c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05621CULL;
}

// FDE #0181 | PC: 0x0562fc..0x0563d8 (220 B) | Symbol: _ZNSt6__ndk18ios_base17register_callbackEPFvNS0_5eventERS0_iEi
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0562fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0562FCULL;
}

// FDE #0182 | PC: 0x0563d8..0x0563fc (36 B) | Symbol: _ZNSt6__ndk18ios_baseD0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0563d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0563D8ULL;
}

// FDE #0183 | PC: 0x0563fc..0x056438 (60 B) | Symbol: _ZNSt6__ndk18ios_base5clearEj
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0, #0x28]; ldr w9, [x0, #0x24]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0, #0x28]; ldr w9, [x0, #0x24]]
uint64_t fde_sub_0563fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0563FCULL;
}

// FDE #0184 | PC: 0x056438..0x056480 (72 B) | Symbol: _ZNSt6__ndk18ios_base4initEPv
// EN: AArch64 prologue [adrp x8, #0xb6000; ldr q0, [x8, #0x900]; cmp x1, #0; mov w9, #0x1002] | VI: Khởi đầu hàm AArch64 [adrp x8, #0xb6000; ldr q0, [x8, #0x900]; cmp x1, #0; mov w9, #0x1002]
uint64_t fde_sub_056438(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC24100ULL) << 32) | 0x90000308ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056438ULL;
}

// FDE #0185 | PC: 0x056480..0x056504 (132 B) | Symbol: _ZNSt6__ndk18ios_base4moveERS0_
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x1, #8]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x1, #8]]
uint64_t fde_sub_056480(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056480ULL;
}

// FDE #0186 | PC: 0x056504..0x056650 (332 B) | Symbol: _ZNSt6__ndk18ios_base4swapERS0_
// EN: AArch64 prologue [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_056504(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x014CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056504ULL;
}

// FDE #0187 | PC: 0x056650..0x056668 (24 B) | Symbol: _ZNSt6__ndk18ios_base15sync_with_stdioEb
// EN: AArch64 prologue [adrp x9, #0xe4000; ldrb w8, [x9, #0x10]; and w10, w0, #1; strb w10, [x9, #0x10]] | VI: Khởi đầu hàm AArch64 [adrp x9, #0xe4000; ldrb w8, [x9, #0x10]; and w10, w0, #1; strb w10, [x9, #0x10]]
uint64_t fde_sub_056650(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39404128ULL) << 32) | 0xD0000469ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056650ULL;
}

// FDE #0188 | PC: 0x056668..0x05666c (4 B) | Symbol: _ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED1Ev
// EN: AArch64 prologue [b #0x47b90] | VI: Khởi đầu hàm AArch64 [b #0x47b90]
uint64_t fde_sub_056668(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0x17FFC54AULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056668ULL;
}

// FDE #0189 | PC: 0x05666c..0x056690 (36 B) | Symbol: _ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_05666c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05666CULL;
}

// FDE #0190 | PC: 0x056690..0x056770 (224 B) | Symbol: _ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEE7copyfmtERKS3_
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_056690(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056690ULL;
}

// FDE #0191 | PC: 0x056770..0x056774 (4 B) | Symbol: _ZNSt6__ndk19basic_iosIwNS_11char_traitsIwEEED2Ev
// EN: AArch64 prologue [b #0x47b90] | VI: Khởi đầu hàm AArch64 [b #0x47b90]
uint64_t fde_sub_056770(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0x17FFC508ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056770ULL;
}

// FDE #0192 | PC: 0x056774..0x056798 (36 B) | Symbol: _ZNSt6__ndk19basic_iosIwNS_11char_traitsIwEEED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_056774(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056774ULL;
}

// FDE #0193 | PC: 0x056798..0x056878 (224 B) | Symbol: _ZNSt6__ndk19basic_iosIwNS_11char_traitsIwEEE7copyfmtERKS3_
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_056798(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056798ULL;
}

// FDE #0194 | PC: 0x056878..0x05688c (20 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev
// EN: AArch64 prologue [adrp x8, #0xe3000; ldr x8, [x8, #0xc08]; add x8, x8, #0x10; str x8, [x0], #8] | VI: Khởi đầu hàm AArch64 [adrp x8, #0xe3000; ldr x8, [x8, #0xc08]; add x8, x8, #0x10; str x8, [x0], #8]
uint64_t fde_sub_056878(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9460508ULL) << 32) | 0xB0000468ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056878ULL;
}

// FDE #0195 | PC: 0x05688c..0x0568c0 (52 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_05688c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05688CULL;
}

// FDE #0196 | PC: 0x0568c0..0x05690c (76 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE8pubimbueERKNS_6localeE
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0568c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0568C0ULL;
}

// FDE #0197 | PC: 0x05690c..0x056918 (12 B) | Symbol: _ZNKSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE6getlocEv
// EN: AArch64 prologue [add x1, x0, #8; mov x0, x8; b #0x477e0] | VI: Khởi đầu hàm AArch64 [add x1, x0, #8; mov x0, x8; b #0x477e0]
uint64_t fde_sub_05690c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0x91002001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05690CULL;
}

// FDE #0198 | PC: 0x056918..0x056924 (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE9pubsetbufEPcl
// EN: AArch64 prologue [ldr x8, [x0]; ldr x3, [x8, #0x18]; br x3] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x3, [x8, #0x18]; br x3]
uint64_t fde_sub_056918(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400D03ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056918ULL;
}

// FDE #0199 | PC: 0x056924..0x056930 (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE10pubseekoffExNS_8ios_base7seekdirEj
// EN: AArch64 prologue [ldr x8, [x0]; ldr x4, [x8, #0x20]; br x4] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x4, [x8, #0x20]; br x4]
uint64_t fde_sub_056924(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401104ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056924ULL;
}

// FDE #0200 | PC: 0x056930..0x05693c (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE10pubseekposENS_4fposI9mbstate_tEEj
// EN: AArch64 prologue [ldr x8, [x0]; ldr x4, [x8, #0x28]; br x4] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x4, [x8, #0x28]; br x4]
uint64_t fde_sub_056930(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401504ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056930ULL;
}

// FDE #0201 | PC: 0x05693c..0x056948 (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE7pubsyncEv
// EN: AArch64 prologue [ldr x8, [x0]; ldr x1, [x8, #0x30]; br x1] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x1, [x8, #0x30]; br x1]
uint64_t fde_sub_05693c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401901ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05693CULL;
}

// FDE #0202 | PC: 0x056948..0x056968 (32 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE8in_availEv
// EN: AArch64 prologue [ldp x8, x9, [x0, #0x18]; cmp x8, x9; b.hs #0x5695c; sub x0, x9, x8] | VI: Khởi đầu hàm AArch64 [ldp x8, x9, [x0, #0x18]; cmp x8, x9; b.hs #0x5695c; sub x0, x9, x8]
uint64_t fde_sub_056948(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xA941A408ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056948ULL;
}

// FDE #0203 | PC: 0x056968..0x0569e4 (124 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE6snextcEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldp x9, x8, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldp x9, x8, [x0, #0x18]]
uint64_t fde_sub_056968(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056968ULL;
}

// FDE #0204 | PC: 0x0569e4..0x056a0c (40 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE6sbumpcEv
// EN: AArch64 prologue [ldp x8, x9, [x0, #0x18]; cmp x8, x9; b.eq #0x56a00; add x9, x8, #1] | VI: Khởi đầu hàm AArch64 [ldp x8, x9, [x0, #0x18]; cmp x8, x9; b.eq #0x56a00; add x9, x8, #1]
uint64_t fde_sub_0569e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xA941A408ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0569E4ULL;
}

// FDE #0205 | PC: 0x056a0c..0x056a2c (32 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE5sgetcEv
// EN: AArch64 prologue [ldp x8, x9, [x0, #0x18]; cmp x8, x9; b.eq #0x56a20; ldrb w0, [x8]] | VI: Khởi đầu hàm AArch64 [ldp x8, x9, [x0, #0x18]; cmp x8, x9; b.eq #0x56a20; ldrb w0, [x8]]
uint64_t fde_sub_056a0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xA941A408ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056A0CULL;
}

// FDE #0206 | PC: 0x056a2c..0x056a38 (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE5sgetnEPcl
// EN: AArch64 prologue [ldr x8, [x0]; ldr x3, [x8, #0x40]; br x3] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x3, [x8, #0x40]; br x3]
uint64_t fde_sub_056a2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402103ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056A2CULL;
}

// FDE #0207 | PC: 0x056a38..0x056a6c (52 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE9sputbackcEc
// EN: AArch64 prologue [ldp x9, x8, [x0, #0x10]; cmp x9, x8; b.eq #0x56a5c; ldrb w9, [x8, #-1]!] | VI: Khởi đầu hàm AArch64 [ldp x9, x8, [x0, #0x10]; cmp x9, x8; b.eq #0x56a5c; ldrb w9, [x8, #-1]!]
uint64_t fde_sub_056a38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB08013FULL) << 32) | 0xA9412009ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056A38ULL;
}

// FDE #0208 | PC: 0x056a6c..0x056a98 (44 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE7sungetcEv
// EN: AArch64 prologue [ldp x9, x8, [x0, #0x10]; cmp x9, x8; b.eq #0x56a88; sub x9, x8, #1] | VI: Khởi đầu hàm AArch64 [ldp x9, x8, [x0, #0x10]; cmp x9, x8; b.eq #0x56a88; sub x9, x8, #1]
uint64_t fde_sub_056a6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB08013FULL) << 32) | 0xA9412009ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056A6CULL;
}

// FDE #0209 | PC: 0x056a98..0x056acc (52 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE5sputcEc
// EN: AArch64 prologue [ldp x9, x8, [x0, #0x30]; cmp x9, x8; b.eq #0x56abc; add x10, x9, #1] | VI: Khởi đầu hàm AArch64 [ldp x9, x8, [x0, #0x30]; cmp x9, x8; b.eq #0x56abc; add x10, x9, #1]
uint64_t fde_sub_056a98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB08013FULL) << 32) | 0xA9432009ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056A98ULL;
}

// FDE #0210 | PC: 0x056acc..0x056ad8 (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE5sputnEPKcl
// EN: AArch64 prologue [ldr x8, [x0]; ldr x3, [x8, #0x60]; br x3] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x3, [x8, #0x60]; br x3]
uint64_t fde_sub_056acc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403103ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056ACCULL;
}

// FDE #0211 | PC: 0x056ad8..0x056b14 (60 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC1Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_056ad8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056AD8ULL;
}

// FDE #0212 | PC: 0x056b14..0x056b68 (84 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC2ERKS3_
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_056b14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056B14ULL;
}

// FDE #0213 | PC: 0x056b68..0x056bb0 (72 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEaSERKS3_
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1]
uint64_t fde_sub_056b68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056B68ULL;
}

// FDE #0214 | PC: 0x056bb0..0x056c9c (236 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE4swapERS3_
// EN: AArch64 prologue [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_056bb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056BB0ULL;
}

// FDE #0215 | PC: 0x056c9c..0x056cac (16 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE5gbumpEi
// EN: AArch64 prologue [ldr x8, [x0, #0x18]; add x8, x8, w1, sxtw; str x8, [x0, #0x18]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x18]; add x8, x8, w1, sxtw; str x8, [x0, #0x18]; ret]
uint64_t fde_sub_056c9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8B21C108ULL) << 32) | 0xF9400C08ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056C9CULL;
}

// FDE #0216 | PC: 0x056cac..0x056cb8 (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE4setgEPcS4_S4_
// EN: AArch64 prologue [stp x1, x2, [x0, #0x10]; str x3, [x0, #0x20]; ret] | VI: Khởi đầu hàm AArch64 [stp x1, x2, [x0, #0x10]; str x3, [x0, #0x20]; ret]
uint64_t fde_sub_056cac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001003ULL) << 32) | 0xA9010801ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056CACULL;
}

// FDE #0217 | PC: 0x056cb8..0x056cc8 (16 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE5pbumpEi
// EN: AArch64 prologue [ldr x8, [x0, #0x30]; add x8, x8, w1, sxtw; str x8, [x0, #0x30]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x30]; add x8, x8, w1, sxtw; str x8, [x0, #0x30]; ret]
uint64_t fde_sub_056cb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8B21C108ULL) << 32) | 0xF9401808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056CB8ULL;
}

// FDE #0218 | PC: 0x056cc8..0x056cd4 (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE4setpEPcS4_
// EN: AArch64 prologue [stp x1, x1, [x0, #0x28]; str x2, [x0, #0x38]; ret] | VI: Khởi đầu hàm AArch64 [stp x1, x1, [x0, #0x28]; str x2, [x0, #0x38]; ret]
uint64_t fde_sub_056cc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001C02ULL) << 32) | 0xA9028401ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056CC8ULL;
}

// FDE #0219 | PC: 0x056cd4..0x056cd8 (4 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE5imbueERKNS_6localeE
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_056cd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056CD4ULL;
}

// FDE #0220 | PC: 0x056cd8..0x056cdc (4 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE6setbufEPcl
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_056cd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x92800001ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056CD8ULL;
}

// FDE #0221 | PC: 0x056cdc..0x056ce8 (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE7seekoffExNS_8ios_base7seekdirEj
// EN: AArch64 prologue [mov x1, #-1; mov x0, xzr; ret] | VI: Khởi đầu hàm AArch64 [mov x1, #-1; mov x0, xzr; ret]
uint64_t fde_sub_056cdc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E0ULL) << 32) | 0x92800001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056CDCULL;
}

// FDE #0222 | PC: 0x056ce8..0x056cf4 (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE7seekposENS_4fposI9mbstate_tEEj
// EN: AArch64 prologue [mov x1, #-1; mov x0, xzr; ret] | VI: Khởi đầu hàm AArch64 [mov x1, #-1; mov x0, xzr; ret]
uint64_t fde_sub_056ce8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E0ULL) << 32) | 0x92800001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056CE8ULL;
}

// FDE #0223 | PC: 0x056cf4..0x056cfc (8 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE4syncEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_056cf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056CF4ULL;
}

// FDE #0224 | PC: 0x056cfc..0x056d04 (8 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE9showmanycEv
// EN: AArch64 prologue [mov x0, xzr; ret] | VI: Khởi đầu hàm AArch64 [mov x0, xzr; ret]
uint64_t fde_sub_056cfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xAA1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056CFCULL;
}

// FDE #0225 | PC: 0x056d04..0x056dcc (200 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE6xsgetnEPcl
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_056d04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056D04ULL;
}

// FDE #0226 | PC: 0x056dcc..0x056dd4 (8 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE9underflowEv
// EN: AArch64 prologue [mov w0, #-1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #-1; ret]
uint64_t fde_sub_056dcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x12800000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056DCCULL;
}

// FDE #0227 | PC: 0x056dd4..0x056e14 (64 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE5uflowEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_056dd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056DD4ULL;
}

// FDE #0228 | PC: 0x056e14..0x056e1c (8 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE9pbackfailEi
// EN: AArch64 prologue [mov w0, #-1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #-1; ret]
uint64_t fde_sub_056e14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x12800000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056E14ULL;
}

// FDE #0229 | PC: 0x056e1c..0x056ee4 (200 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE6xsputnEPKcl
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_056e1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056E1CULL;
}

// FDE #0230 | PC: 0x056ee4..0x056eec (8 B) | Symbol: _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE8overflowEi
// EN: AArch64 prologue [mov w0, #-1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #-1; ret]
uint64_t fde_sub_056ee4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x12800000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056EE4ULL;
}

// FDE #0231 | PC: 0x056eec..0x056f00 (20 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEED1Ev
// EN: AArch64 prologue [adrp x8, #0xe3000; ldr x8, [x8, #0xc78]; add x8, x8, #0x10; str x8, [x0], #8] | VI: Khởi đầu hàm AArch64 [adrp x8, #0xe3000; ldr x8, [x8, #0xc78]; add x8, x8, #0x10; str x8, [x0], #8]
uint64_t fde_sub_056eec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9463D08ULL) << 32) | 0xB0000468ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056EECULL;
}

// FDE #0232 | PC: 0x056f00..0x056f34 (52 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_056f00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056F00ULL;
}

// FDE #0233 | PC: 0x056f34..0x056f80 (76 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE8pubimbueERKNS_6localeE
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_056f34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056F34ULL;
}

// FDE #0234 | PC: 0x056f80..0x056f8c (12 B) | Symbol: _ZNKSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE6getlocEv
// EN: AArch64 prologue [add x1, x0, #8; mov x0, x8; b #0x477e0] | VI: Khởi đầu hàm AArch64 [add x1, x0, #8; mov x0, x8; b #0x477e0]
uint64_t fde_sub_056f80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0x91002001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056F80ULL;
}

// FDE #0235 | PC: 0x056f8c..0x056f98 (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE9pubsetbufEPwl
// EN: AArch64 prologue [ldr x8, [x0]; ldr x3, [x8, #0x18]; br x3] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x3, [x8, #0x18]; br x3]
uint64_t fde_sub_056f8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400D03ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056F8CULL;
}

// FDE #0236 | PC: 0x056f98..0x056fa4 (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE10pubseekoffExNS_8ios_base7seekdirEj
// EN: AArch64 prologue [ldr x8, [x0]; ldr x4, [x8, #0x20]; br x4] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x4, [x8, #0x20]; br x4]
uint64_t fde_sub_056f98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401104ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056F98ULL;
}

// FDE #0237 | PC: 0x056fa4..0x056fb0 (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE10pubseekposENS_4fposI9mbstate_tEEj
// EN: AArch64 prologue [ldr x8, [x0]; ldr x4, [x8, #0x28]; br x4] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x4, [x8, #0x28]; br x4]
uint64_t fde_sub_056fa4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401504ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056FA4ULL;
}

// FDE #0238 | PC: 0x056fb0..0x056fbc (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE7pubsyncEv
// EN: AArch64 prologue [ldr x8, [x0]; ldr x1, [x8, #0x30]; br x1] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x1, [x8, #0x30]; br x1]
uint64_t fde_sub_056fb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401901ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056FB0ULL;
}

// FDE #0239 | PC: 0x056fbc..0x056fe0 (36 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE8in_availEv
// EN: AArch64 prologue [ldp x8, x9, [x0, #0x18]; cmp x8, x9; b.hs #0x56fd4; sub x8, x9, x8] | VI: Khởi đầu hàm AArch64 [ldp x8, x9, [x0, #0x18]; cmp x8, x9; b.hs #0x56fd4; sub x8, x9, x8]
uint64_t fde_sub_056fbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xA941A408ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056FBCULL;
}

// FDE #0240 | PC: 0x056fe0..0x057060 (128 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE6snextcEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldp x8, x9, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldp x8, x9, [x0, #0x18]]
uint64_t fde_sub_056fe0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056FE0ULL;
}

// FDE #0241 | PC: 0x057060..0x057088 (40 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE6sbumpcEv
// EN: AArch64 prologue [ldp x8, x9, [x0, #0x18]; cmp x8, x9; b.eq #0x5707c; add x9, x8, #4] | VI: Khởi đầu hàm AArch64 [ldp x8, x9, [x0, #0x18]; cmp x8, x9; b.eq #0x5707c; add x9, x8, #4]
uint64_t fde_sub_057060(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xA941A408ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057060ULL;
}

// FDE #0242 | PC: 0x057088..0x0570a8 (32 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE5sgetcEv
// EN: AArch64 prologue [ldp x8, x9, [x0, #0x18]; cmp x8, x9; b.eq #0x5709c; ldr w0, [x8]] | VI: Khởi đầu hàm AArch64 [ldp x8, x9, [x0, #0x18]; cmp x8, x9; b.eq #0x5709c; ldr w0, [x8]]
uint64_t fde_sub_057088(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xA941A408ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057088ULL;
}

// FDE #0243 | PC: 0x0570a8..0x0570b4 (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE5sgetnEPwl
// EN: AArch64 prologue [ldr x8, [x0]; ldr x3, [x8, #0x40]; br x3] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x3, [x8, #0x40]; br x3]
uint64_t fde_sub_0570a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9402103ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0570A8ULL;
}

// FDE #0244 | PC: 0x0570b4..0x0570e4 (48 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE9sputbackcEw
// EN: AArch64 prologue [ldp x9, x8, [x0, #0x10]; cmp x9, x8; b.eq #0x570d8; ldr w9, [x8, #-4]!] | VI: Khởi đầu hàm AArch64 [ldp x9, x8, [x0, #0x10]; cmp x9, x8; b.eq #0x570d8; ldr w9, [x8, #-4]!]
uint64_t fde_sub_0570b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB08013FULL) << 32) | 0xA9412009ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0570B4ULL;
}

// FDE #0245 | PC: 0x0570e4..0x057110 (44 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE7sungetcEv
// EN: AArch64 prologue [ldp x9, x8, [x0, #0x10]; cmp x9, x8; b.eq #0x57100; sub x9, x8, #4] | VI: Khởi đầu hàm AArch64 [ldp x9, x8, [x0, #0x10]; cmp x9, x8; b.eq #0x57100; sub x9, x8, #4]
uint64_t fde_sub_0570e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB08013FULL) << 32) | 0xA9412009ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0570E4ULL;
}

// FDE #0246 | PC: 0x057110..0x05713c (44 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE5sputcEw
// EN: AArch64 prologue [ldp x8, x9, [x0, #0x30]; cmp x8, x9; b.eq #0x57130; add x9, x8, #4] | VI: Khởi đầu hàm AArch64 [ldp x8, x9, [x0, #0x30]; cmp x8, x9; b.eq #0x57130; add x9, x8, #4]
uint64_t fde_sub_057110(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xA9432408ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057110ULL;
}

// FDE #0247 | PC: 0x05713c..0x057148 (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE5sputnEPKwl
// EN: AArch64 prologue [ldr x8, [x0]; ldr x3, [x8, #0x60]; br x3] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x3, [x8, #0x60]; br x3]
uint64_t fde_sub_05713c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403103ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05713CULL;
}

// FDE #0248 | PC: 0x057148..0x057184 (60 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEEC2Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_057148(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057148ULL;
}

// FDE #0249 | PC: 0x057184..0x0571d8 (84 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEEC2ERKS3_
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_057184(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057184ULL;
}

// FDE #0250 | PC: 0x0571d8..0x057220 (72 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEEaSERKS3_
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1]
uint64_t fde_sub_0571d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0571D8ULL;
}

// FDE #0251 | PC: 0x057220..0x05730c (236 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE4swapERS3_
// EN: AArch64 prologue [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_057220(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057220ULL;
}

// FDE #0252 | PC: 0x05730c..0x05731c (16 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE5gbumpEi
// EN: AArch64 prologue [ldr x8, [x0, #0x18]; add x8, x8, w1, sxtw #2; str x8, [x0, #0x18]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x18]; add x8, x8, w1, sxtw #2; str x8, [x0, #0x18]; ret]
uint64_t fde_sub_05730c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8B21C908ULL) << 32) | 0xF9400C08ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05730CULL;
}

// FDE #0253 | PC: 0x05731c..0x057328 (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE4setgEPwS4_S4_
// EN: AArch64 prologue [stp x1, x2, [x0, #0x10]; str x3, [x0, #0x20]; ret] | VI: Khởi đầu hàm AArch64 [stp x1, x2, [x0, #0x10]; str x3, [x0, #0x20]; ret]
uint64_t fde_sub_05731c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001003ULL) << 32) | 0xA9010801ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05731CULL;
}

// FDE #0254 | PC: 0x057328..0x057338 (16 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE5pbumpEi
// EN: AArch64 prologue [ldr x8, [x0, #0x30]; add x8, x8, w1, sxtw #2; str x8, [x0, #0x30]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x30]; add x8, x8, w1, sxtw #2; str x8, [x0, #0x30]; ret]
uint64_t fde_sub_057328(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x8B21C908ULL) << 32) | 0xF9401808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057328ULL;
}

// FDE #0255 | PC: 0x057338..0x057344 (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE4setpEPwS4_
// EN: AArch64 prologue [stp x1, x1, [x0, #0x28]; str x2, [x0, #0x38]; ret] | VI: Khởi đầu hàm AArch64 [stp x1, x1, [x0, #0x28]; str x2, [x0, #0x38]; ret]
uint64_t fde_sub_057338(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001C02ULL) << 32) | 0xA9028401ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057338ULL;
}

// FDE #0256 | PC: 0x057344..0x057348 (4 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE5imbueERKNS_6localeE
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_057344(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057344ULL;
}

// FDE #0257 | PC: 0x057348..0x05734c (4 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE6setbufEPwl
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_057348(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x92800001ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057348ULL;
}

// FDE #0258 | PC: 0x05734c..0x057358 (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE7seekoffExNS_8ios_base7seekdirEj
// EN: AArch64 prologue [mov x1, #-1; mov x0, xzr; ret] | VI: Khởi đầu hàm AArch64 [mov x1, #-1; mov x0, xzr; ret]
uint64_t fde_sub_05734c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E0ULL) << 32) | 0x92800001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05734CULL;
}

// FDE #0259 | PC: 0x057358..0x057364 (12 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE7seekposENS_4fposI9mbstate_tEEj
// EN: AArch64 prologue [mov x1, #-1; mov x0, xzr; ret] | VI: Khởi đầu hàm AArch64 [mov x1, #-1; mov x0, xzr; ret]
uint64_t fde_sub_057358(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1F03E0ULL) << 32) | 0x92800001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057358ULL;
}

// FDE #0260 | PC: 0x057364..0x05736c (8 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE4syncEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_057364(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057364ULL;
}

// FDE #0261 | PC: 0x05736c..0x057374 (8 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE9showmanycEv
// EN: AArch64 prologue [mov x0, xzr; ret] | VI: Khởi đầu hàm AArch64 [mov x0, xzr; ret]
uint64_t fde_sub_05736c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xAA1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05736CULL;
}

// FDE #0262 | PC: 0x057374..0x057448 (212 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE6xsgetnEPwl
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_057374(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057374ULL;
}

// FDE #0263 | PC: 0x057448..0x057450 (8 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE9underflowEv
// EN: AArch64 prologue [mov w0, #-1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #-1; ret]
uint64_t fde_sub_057448(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x12800000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057448ULL;
}

// FDE #0264 | PC: 0x057450..0x057490 (64 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE5uflowEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_057450(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057450ULL;
}

// FDE #0265 | PC: 0x057490..0x057498 (8 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE9pbackfailEj
// EN: AArch64 prologue [mov w0, #-1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #-1; ret]
uint64_t fde_sub_057490(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x12800000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057490ULL;
}

// FDE #0266 | PC: 0x057498..0x05756c (212 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE6xsputnEPKwl
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_057498(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057498ULL;
}

// FDE #0267 | PC: 0x05756c..0x057574 (8 B) | Symbol: _ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEE8overflowEj
// EN: AArch64 prologue [mov w0, #-1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #-1; ret]
uint64_t fde_sub_05756c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x12800000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05756CULL;
}

// FDE #0268 | PC: 0x057574..0x057600 (140 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEEC2EPNS_15basic_streambufIcS2_EE
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x1]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x1]]
uint64_t fde_sub_057574(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057574ULL;
}

// FDE #0269 | PC: 0x057600..0x057684 (132 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEEC1EPNS_15basic_streambufIcS2_EE
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_057600(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057600ULL;
}

// FDE #0270 | PC: 0x057684..0x057688 (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED2Ev
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_057684(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91004000ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057684ULL;
}

// FDE #0271 | PC: 0x057688..0x057690 (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED1Ev
// EN: AArch64 prologue [add x0, x0, #0x10; b #0x47b90] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x10; b #0x47b90]
uint64_t fde_sub_057688(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFC141ULL) << 32) | 0x91004000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057688ULL;
}

// FDE #0272 | PC: 0x057690..0x0576a4 (20 B) | Symbol: _ZTv0_n24_NSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED1Ev
// EN: AArch64 prologue [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x8, x0, x8; add x0, x8, #0x10] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x8, x0, x8; add x0, x8, #0x10]
uint64_t fde_sub_057690(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF85E8108ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057690ULL;
}

// FDE #0273 | PC: 0x0576a4..0x0576cc (40 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0576a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0576A4ULL;
}

// FDE #0274 | PC: 0x0576cc..0x0576fc (48 B) | Symbol: _ZTv0_n24_NSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_0576cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0576CCULL;
}

// FDE #0275 | PC: 0x0576fc..0x057768 (108 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE4swapERS3_
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x1, #8]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x1, #8]]
uint64_t fde_sub_0576fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0576FCULL;
}

// FDE #0276 | PC: 0x057768..0x057998 (560 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE6sentryC1ERS3_b
// EN: AArch64 prologue [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_057768(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0230ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057768ULL;
}

// FDE #0277 | PC: 0x057998..0x057adc (324 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE5flushEv
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_057998(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0144ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057998ULL;
}

// FDE #0278 | PC: 0x057adc..0x057ae0 (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsEPFRS3_S4_E
// EN: AArch64 prologue [br x1] | VI: Khởi đầu hàm AArch64 [br x1]
uint64_t fde_sub_057adc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0xD61F0020ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057ADCULL;
}

// FDE #0279 | PC: 0x057ae0..0x057b10 (48 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsEPFRNS_9basic_iosIcS2_EES6_E
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_057ae0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057AE0ULL;
}

// FDE #0280 | PC: 0x057b10..0x057b40 (48 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsEPFRNS_8ios_baseES5_E
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_057b10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057B10ULL;
}

// FDE #0281 | PC: 0x057b40..0x057d3c (508 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsEPNS_15basic_streambufIcS2_EE
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_057b40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x01FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057B40ULL;
}

// FDE #0282 | PC: 0x057d3c..0x057d40 (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERb
// EN: AArch64 prologue [b #0x57d40] | VI: Khởi đầu hàm AArch64 [b #0x57d40]
uint64_t fde_sub_057d3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x14000001ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057D3CULL;
}

// FDE #0283 | PC: 0x057d40..0x057eb0 (368 B) | Symbol: sub_057d40
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_057d40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057D40ULL;
}

// FDE #0284 | PC: 0x057eb0..0x057eb4 (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERs
// EN: AArch64 prologue [b #0x57eb4] | VI: Khởi đầu hàm AArch64 [b #0x57eb4]
uint64_t fde_sub_057eb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x14000001ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057EB0ULL;
}

// FDE #0285 | PC: 0x057eb4..0x058064 (432 B) | Symbol: sub_057eb4
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_057eb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x01B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057EB4ULL;
}

// FDE #0286 | PC: 0x058064..0x058068 (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERt
// EN: AArch64 prologue [b #0x58068] | VI: Khởi đầu hàm AArch64 [b #0x58068]
uint64_t fde_sub_058064(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x14000001ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058064ULL;
}

// FDE #0287 | PC: 0x058068..0x0581d8 (368 B) | Symbol: sub_058068
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_058068(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058068ULL;
}

// FDE #0288 | PC: 0x0581d8..0x0581dc (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERi
// EN: AArch64 prologue [b #0x581dc] | VI: Khởi đầu hàm AArch64 [b #0x581dc]
uint64_t fde_sub_0581d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x14000001ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0581D8ULL;
}

// FDE #0289 | PC: 0x0581dc..0x058390 (436 B) | Symbol: sub_0581dc
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_0581dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x01B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0581DCULL;
}

// FDE #0290 | PC: 0x058390..0x058394 (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERj
// EN: AArch64 prologue [b #0x58394] | VI: Khởi đầu hàm AArch64 [b #0x58394]
uint64_t fde_sub_058390(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x14000001ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058390ULL;
}

// FDE #0291 | PC: 0x058394..0x058504 (368 B) | Symbol: sub_058394
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_058394(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058394ULL;
}

// FDE #0292 | PC: 0x058504..0x058508 (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERl
// EN: AArch64 prologue [b #0x58508] | VI: Khởi đầu hàm AArch64 [b #0x58508]
uint64_t fde_sub_058504(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x14000001ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058504ULL;
}

// FDE #0293 | PC: 0x058508..0x058678 (368 B) | Symbol: sub_058508
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_058508(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058508ULL;
}

// FDE #0294 | PC: 0x058678..0x05867c (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERm
// EN: AArch64 prologue [b #0x5867c] | VI: Khởi đầu hàm AArch64 [b #0x5867c]
uint64_t fde_sub_058678(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x14000001ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058678ULL;
}

// FDE #0295 | PC: 0x05867c..0x0587ec (368 B) | Symbol: sub_05867c
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_05867c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05867CULL;
}

// FDE #0296 | PC: 0x0587ec..0x0587f0 (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERx
// EN: AArch64 prologue [b #0x587f0] | VI: Khởi đầu hàm AArch64 [b #0x587f0]
uint64_t fde_sub_0587ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x14000001ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0587ECULL;
}

// FDE #0297 | PC: 0x0587f0..0x058960 (368 B) | Symbol: sub_0587f0
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_0587f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0587F0ULL;
}

// FDE #0298 | PC: 0x058960..0x058964 (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERy
// EN: AArch64 prologue [b #0x58964] | VI: Khởi đầu hàm AArch64 [b #0x58964]
uint64_t fde_sub_058960(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x14000001ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058960ULL;
}

// FDE #0299 | PC: 0x058964..0x058ad4 (368 B) | Symbol: sub_058964
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_058964(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058964ULL;
}

// FDE #0300 | PC: 0x058ad4..0x058ad8 (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERf
// EN: AArch64 prologue [b #0x58ad8] | VI: Khởi đầu hàm AArch64 [b #0x58ad8]
uint64_t fde_sub_058ad4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x14000001ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058AD4ULL;
}

// FDE #0301 | PC: 0x058ad8..0x058c48 (368 B) | Symbol: sub_058ad8
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_058ad8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058AD8ULL;
}

// FDE #0302 | PC: 0x058c48..0x058c4c (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERd
// EN: AArch64 prologue [b #0x58c4c] | VI: Khởi đầu hàm AArch64 [b #0x58c4c]
uint64_t fde_sub_058c48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x14000001ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058C48ULL;
}

// FDE #0303 | PC: 0x058c4c..0x058dbc (368 B) | Symbol: sub_058c4c
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_058c4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058C4CULL;
}

// FDE #0304 | PC: 0x058dbc..0x058dc0 (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERe
// EN: AArch64 prologue [b #0x58dc0] | VI: Khởi đầu hàm AArch64 [b #0x58dc0]
uint64_t fde_sub_058dbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x14000001ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058DBCULL;
}

// FDE #0305 | PC: 0x058dc0..0x058f30 (368 B) | Symbol: sub_058dc0
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_058dc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058DC0ULL;
}

// FDE #0306 | PC: 0x058f30..0x058f34 (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERPv
// EN: AArch64 prologue [b #0x58f34] | VI: Khởi đầu hàm AArch64 [b #0x58f34]
uint64_t fde_sub_058f30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x14000001ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058F30ULL;
}

// FDE #0307 | PC: 0x058f34..0x0590a4 (368 B) | Symbol: sub_058f34
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_058f34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058F34ULL;
}

// FDE #0308 | PC: 0x0590a4..0x059208 (356 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE3getEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_0590a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0164ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0590A4ULL;
}

// FDE #0309 | PC: 0x059208..0x05923c (52 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE3getERc
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x1]
uint64_t fde_sub_059208(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059208ULL;
}

// FDE #0310 | PC: 0x05923c..0x059304 (200 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE3getEPcl
// EN: AArch64 prologue [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_05923c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05923CULL;
}

// FDE #0311 | PC: 0x059304..0x05953c (568 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE3getEPclc
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_059304(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x0238ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059304ULL;
}

// FDE #0312 | PC: 0x05953c..0x0595f4 (184 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE3getERNS_15basic_streambufIcS2_EE
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_05953c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05953CULL;
}

// FDE #0313 | PC: 0x0595f4..0x0597a8 (436 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE3getERNS_15basic_streambufIcS2_EEc
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0595f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x01B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0595F4ULL;
}

// FDE #0314 | PC: 0x0597a8..0x059870 (200 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE7getlineEPcl
// EN: AArch64 prologue [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0597a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0597A8ULL;
}

// FDE #0315 | PC: 0x059870..0x059ae8 (632 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE7getlineEPclc
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_059870(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x0278ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059870ULL;
}

// FDE #0316 | PC: 0x059ae8..0x059ce4 (508 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE6ignoreEli
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_059ae8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x01FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059AE8ULL;
}

// FDE #0317 | PC: 0x059ce4..0x059e30 (332 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE4peekEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_059ce4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x014CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059CE4ULL;
}

// FDE #0318 | PC: 0x059e30..0x059f7c (332 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE4readEPcl
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_059e30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x014CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059E30ULL;
}

// FDE #0319 | PC: 0x059f7c..0x05a124 (424 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE8readsomeEPcl
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_059f7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x01A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059F7CULL;
}

// FDE #0320 | PC: 0x05a124..0x05a2c4 (416 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE7putbackEc
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05a124(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x01A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A124ULL;
}

// FDE #0321 | PC: 0x05a2c4..0x05a450 (396 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE5ungetEv
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_05a2c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x018CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A2C4ULL;
}

// FDE #0322 | PC: 0x05a450..0x05a584 (308 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE4syncEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_05a450(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0134ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A450ULL;
}

// FDE #0323 | PC: 0x05a584..0x05a6bc (312 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE5tellgEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_05a584(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0138ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A584ULL;
}

// FDE #0324 | PC: 0x05a6bc..0x05a830 (372 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE5seekgENS_4fposI9mbstate_tEE
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05a6bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0174ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A6BCULL;
}

// FDE #0325 | PC: 0x05a830..0x05a9a4 (372 B) | Symbol: _ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE5seekgExNS_8ios_base7seekdirE
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05a830(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0174ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A830ULL;
}

// FDE #0326 | PC: 0x05a9a4..0x05aa30 (140 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEEC2EPNS_15basic_streambufIwS2_EE
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x1]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x1]]
uint64_t fde_sub_05a9a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A9A4ULL;
}

// FDE #0327 | PC: 0x05aa30..0x05aab4 (132 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEEC1EPNS_15basic_streambufIwS2_EE
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_05aa30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AA30ULL;
}

// FDE #0328 | PC: 0x05aab4..0x05aab8 (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEED2Ev
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_05aab4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91004000ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AAB4ULL;
}

// FDE #0329 | PC: 0x05aab8..0x05aac0 (8 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEED1Ev
// EN: AArch64 prologue [add x0, x0, #0x10; b #0x47b90] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x10; b #0x47b90]
uint64_t fde_sub_05aab8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFB435ULL) << 32) | 0x91004000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AAB8ULL;
}

// FDE #0330 | PC: 0x05aac0..0x05aad4 (20 B) | Symbol: _ZTv0_n24_NSt6__ndk113basic_istreamIwNS_11char_traitsIwEEED1Ev
// EN: AArch64 prologue [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x8, x0, x8; add x0, x8, #0x10] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x8, x0, x8; add x0, x8, #0x10]
uint64_t fde_sub_05aac0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF85E8108ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AAC0ULL;
}

// FDE #0331 | PC: 0x05aad4..0x05aafc (40 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_05aad4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AAD4ULL;
}

// FDE #0332 | PC: 0x05aafc..0x05ab2c (48 B) | Symbol: _ZTv0_n24_NSt6__ndk113basic_istreamIwNS_11char_traitsIwEEED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_05aafc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AAFCULL;
}

// FDE #0333 | PC: 0x05ab2c..0x05ab98 (108 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE4swapERS3_
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x1, #8]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x1, #8]]
uint64_t fde_sub_05ab2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AB2CULL;
}

// FDE #0334 | PC: 0x05ab98..0x05ade4 (588 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE6sentryC1ERS3_b
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_05ab98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x024CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AB98ULL;
}

// FDE #0335 | PC: 0x05ade4..0x05af28 (324 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEE5flushEv
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_05ade4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0144ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05ADE4ULL;
}

// FDE #0336 | PC: 0x05af28..0x05af2c (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsEPFRS3_S4_E
// EN: AArch64 prologue [br x1] | VI: Khởi đầu hàm AArch64 [br x1]
uint64_t fde_sub_05af28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0xD61F0020ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AF28ULL;
}

// FDE #0337 | PC: 0x05af2c..0x05af5c (48 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsEPFRNS_9basic_iosIwS2_EES6_E
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_05af2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AF2CULL;
}

// FDE #0338 | PC: 0x05af5c..0x05af8c (48 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsEPFRNS_8ios_baseES5_E
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_05af5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AF5CULL;
}

// FDE #0339 | PC: 0x05af8c..0x05b190 (516 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsEPNS_15basic_streambufIwS2_EE
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05af8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0204ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AF8CULL;
}

// FDE #0340 | PC: 0x05b190..0x05b194 (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsERb
// EN: AArch64 prologue [b #0x5b194] | VI: Khởi đầu hàm AArch64 [b #0x5b194]
uint64_t fde_sub_05b190(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x14000001ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B190ULL;
}

// FDE #0341 | PC: 0x05b194..0x05b304 (368 B) | Symbol: sub_05b194
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_05b194(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B194ULL;
}

// FDE #0342 | PC: 0x05b304..0x05b308 (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsERs
// EN: AArch64 prologue [b #0x5b308] | VI: Khởi đầu hàm AArch64 [b #0x5b308]
uint64_t fde_sub_05b304(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x14000001ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B304ULL;
}

// FDE #0343 | PC: 0x05b308..0x05b4b8 (432 B) | Symbol: sub_05b308
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_05b308(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x01B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B308ULL;
}

// FDE #0344 | PC: 0x05b4b8..0x05b4bc (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsERt
// EN: AArch64 prologue [b #0x5b4bc] | VI: Khởi đầu hàm AArch64 [b #0x5b4bc]
uint64_t fde_sub_05b4b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x14000001ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B4B8ULL;
}

// FDE #0345 | PC: 0x05b4bc..0x05b62c (368 B) | Symbol: sub_05b4bc
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_05b4bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B4BCULL;
}

// FDE #0346 | PC: 0x05b62c..0x05b630 (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsERi
// EN: AArch64 prologue [b #0x5b630] | VI: Khởi đầu hàm AArch64 [b #0x5b630]
uint64_t fde_sub_05b62c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x14000001ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B62CULL;
}

// FDE #0347 | PC: 0x05b630..0x05b7e4 (436 B) | Symbol: sub_05b630
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_05b630(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x01B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B630ULL;
}

// FDE #0348 | PC: 0x05b7e4..0x05b7e8 (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsERj
// EN: AArch64 prologue [b #0x5b7e8] | VI: Khởi đầu hàm AArch64 [b #0x5b7e8]
uint64_t fde_sub_05b7e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x14000001ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B7E4ULL;
}

// FDE #0349 | PC: 0x05b7e8..0x05b958 (368 B) | Symbol: sub_05b7e8
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_05b7e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B7E8ULL;
}

// FDE #0350 | PC: 0x05b958..0x05b95c (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsERl
// EN: AArch64 prologue [b #0x5b95c] | VI: Khởi đầu hàm AArch64 [b #0x5b95c]
uint64_t fde_sub_05b958(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x14000001ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B958ULL;
}

// FDE #0351 | PC: 0x05b95c..0x05bacc (368 B) | Symbol: sub_05b95c
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_05b95c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B95CULL;
}

// FDE #0352 | PC: 0x05bacc..0x05bad0 (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsERm
// EN: AArch64 prologue [b #0x5bad0] | VI: Khởi đầu hàm AArch64 [b #0x5bad0]
uint64_t fde_sub_05bacc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x14000001ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05BACCULL;
}

// FDE #0353 | PC: 0x05bad0..0x05bc40 (368 B) | Symbol: sub_05bad0
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_05bad0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05BAD0ULL;
}

// FDE #0354 | PC: 0x05bc40..0x05bc44 (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsERx
// EN: AArch64 prologue [b #0x5bc44] | VI: Khởi đầu hàm AArch64 [b #0x5bc44]
uint64_t fde_sub_05bc40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x14000001ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05BC40ULL;
}

// FDE #0355 | PC: 0x05bc44..0x05bdb4 (368 B) | Symbol: sub_05bc44
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_05bc44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05BC44ULL;
}

// FDE #0356 | PC: 0x05bdb4..0x05bdb8 (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsERy
// EN: AArch64 prologue [b #0x5bdb8] | VI: Khởi đầu hàm AArch64 [b #0x5bdb8]
uint64_t fde_sub_05bdb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x14000001ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05BDB4ULL;
}

// FDE #0357 | PC: 0x05bdb8..0x05bf28 (368 B) | Symbol: sub_05bdb8
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_05bdb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05BDB8ULL;
}

// FDE #0358 | PC: 0x05bf28..0x05bf2c (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsERf
// EN: AArch64 prologue [b #0x5bf2c] | VI: Khởi đầu hàm AArch64 [b #0x5bf2c]
uint64_t fde_sub_05bf28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x14000001ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05BF28ULL;
}

// FDE #0359 | PC: 0x05bf2c..0x05c09c (368 B) | Symbol: sub_05bf2c
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_05bf2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05BF2CULL;
}

// FDE #0360 | PC: 0x05c09c..0x05c0a0 (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsERd
// EN: AArch64 prologue [b #0x5c0a0] | VI: Khởi đầu hàm AArch64 [b #0x5c0a0]
uint64_t fde_sub_05c09c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x14000001ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C09CULL;
}

// FDE #0361 | PC: 0x05c0a0..0x05c210 (368 B) | Symbol: sub_05c0a0
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_05c0a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C0A0ULL;
}

// FDE #0362 | PC: 0x05c210..0x05c214 (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsERe
// EN: AArch64 prologue [b #0x5c214] | VI: Khởi đầu hàm AArch64 [b #0x5c214]
uint64_t fde_sub_05c210(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x14000001ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C210ULL;
}

// FDE #0363 | PC: 0x05c214..0x05c384 (368 B) | Symbol: sub_05c214
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_05c214(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C214ULL;
}

// FDE #0364 | PC: 0x05c384..0x05c388 (4 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEErsERPv
// EN: AArch64 prologue [b #0x5c388] | VI: Khởi đầu hàm AArch64 [b #0x5c388]
uint64_t fde_sub_05c384(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10143FFULL) << 32) | 0x14000001ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C384ULL;
}

// FDE #0365 | PC: 0x05c388..0x05c4f8 (368 B) | Symbol: sub_05c388
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_05c388(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C388ULL;
}

// FDE #0366 | PC: 0x05c4f8..0x05c660 (360 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE3getEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_05c4f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0168ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C4F8ULL;
}

// FDE #0367 | PC: 0x05c660..0x05c694 (52 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE3getERw
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x1]
uint64_t fde_sub_05c660(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C660ULL;
}

// FDE #0368 | PC: 0x05c694..0x05c75c (200 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE3getEPwl
// EN: AArch64 prologue [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_05c694(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C694ULL;
}

// FDE #0369 | PC: 0x05c75c..0x05c998 (572 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE3getEPwlw
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_05c75c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x023CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C75CULL;
}

// FDE #0370 | PC: 0x05c998..0x05ca50 (184 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE3getERNS_15basic_streambufIwS2_EE
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_05c998(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C998ULL;
}

// FDE #0371 | PC: 0x05ca50..0x05cc08 (440 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE3getERNS_15basic_streambufIwS2_EEw
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05ca50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x01B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CA50ULL;
}

// FDE #0372 | PC: 0x05cc08..0x05ccd0 (200 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE7getlineEPwl
// EN: AArch64 prologue [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_05cc08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CC08ULL;
}

// FDE #0373 | PC: 0x05ccd0..0x05cf44 (628 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE7getlineEPwlw
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_05ccd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x0274ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CCD0ULL;
}

// FDE #0374 | PC: 0x05cf44..0x05d140 (508 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE6ignoreElj
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05cf44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x01FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CF44ULL;
}

// FDE #0375 | PC: 0x05d140..0x05d28c (332 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE4peekEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_05d140(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x014CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D140ULL;
}

// FDE #0376 | PC: 0x05d28c..0x05d3d8 (332 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE4readEPwl
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05d28c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x014CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D28CULL;
}

// FDE #0377 | PC: 0x05d3d8..0x05d584 (428 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE8readsomeEPwl
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05d3d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x01ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D3D8ULL;
}

// FDE #0378 | PC: 0x05d584..0x05d730 (428 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE7putbackEw
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05d584(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x01ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D584ULL;
}

// FDE #0379 | PC: 0x05d730..0x05d8c8 (408 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE5ungetEv
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_05d730(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0198ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D730ULL;
}

// FDE #0380 | PC: 0x05d8c8..0x05d9fc (308 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE4syncEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_05d8c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0134ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D8C8ULL;
}

// FDE #0381 | PC: 0x05d9fc..0x05db34 (312 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE5tellgEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_05d9fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0138ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D9FCULL;
}

// FDE #0382 | PC: 0x05db34..0x05dca8 (372 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE5seekgENS_4fposI9mbstate_tEE
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05db34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0174ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DB34ULL;
}

// FDE #0383 | PC: 0x05dca8..0x05de1c (372 B) | Symbol: _ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE5seekgExNS_8ios_base7seekdirE
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05dca8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0174ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DCA8ULL;
}

// FDE #0384 | PC: 0x05de1c..0x05dea4 (136 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEEC2EPNS_15basic_streambufIcS2_EE
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x1]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x1]]
uint64_t fde_sub_05de1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DE1CULL;
}

// FDE #0385 | PC: 0x05dea4..0x05df20 (124 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEEC1EPNS_15basic_streambufIcS2_EE
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_05dea4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DEA4ULL;
}

// FDE #0386 | PC: 0x05df20..0x05df24 (4 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED2Ev
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_05df20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91002000ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DF20ULL;
}

// FDE #0387 | PC: 0x05df24..0x05df2c (8 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED1Ev
// EN: AArch64 prologue [add x0, x0, #8; b #0x47b90] | VI: Khởi đầu hàm AArch64 [add x0, x0, #8; b #0x47b90]
uint64_t fde_sub_05df24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFA71AULL) << 32) | 0x91002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DF24ULL;
}

// FDE #0388 | PC: 0x05df2c..0x05df40 (20 B) | Symbol: _ZTv0_n24_NSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED1Ev
// EN: AArch64 prologue [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x8, x0, x8; add x0, x8, #8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x8, x0, x8; add x0, x8, #8]
uint64_t fde_sub_05df2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF85E8108ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DF2CULL;
}

// FDE #0389 | PC: 0x05df40..0x05df68 (40 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_05df40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DF40ULL;
}

// FDE #0390 | PC: 0x05df68..0x05df98 (48 B) | Symbol: _ZTv0_n24_NSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_05df68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DF68ULL;
}

uint64_t DispatchCxxSharedShard1(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x0487b0ULL: return fde_sub_0487b0(a0, a1, a2);
        case 0x0487dcULL: return fde_sub_0487dc(a0, a1, a2);
        case 0x048940ULL: return fde_sub_048940(a0, a1, a2);
        case 0x048aa4ULL: return fde_sub_048aa4(a0, a1, a2);
        case 0x048aecULL: return fde_sub_048aec(a0, a1, a2);
        case 0x048b34ULL: return fde_sub_048b34(a0, a1, a2);
        case 0x048b78ULL: return fde_sub_048b78(a0, a1, a2);
        case 0x048bf8ULL: return fde_sub_048bf8(a0, a1, a2);
        case 0x048c24ULL: return fde_sub_048c24(a0, a1, a2);
        case 0x048c3cULL: return fde_sub_048c3c(a0, a1, a2);
        case 0x048c74ULL: return fde_sub_048c74(a0, a1, a2);
        case 0x048dc8ULL: return fde_sub_048dc8(a0, a1, a2);
        case 0x048df4ULL: return fde_sub_048df4(a0, a1, a2);
        case 0x049320ULL: return fde_sub_049320(a0, a1, a2);
        case 0x0494a8ULL: return fde_sub_0494a8(a0, a1, a2);
        case 0x04973cULL: return fde_sub_04973c(a0, a1, a2);
        case 0x049c48ULL: return fde_sub_049c48(a0, a1, a2);
        case 0x049dd0ULL: return fde_sub_049dd0(a0, a1, a2);
        case 0x04a028ULL: return fde_sub_04a028(a0, a1, a2);
        case 0x04a554ULL: return fde_sub_04a554(a0, a1, a2);
        case 0x04a6dcULL: return fde_sub_04a6dc(a0, a1, a2);
        case 0x04a970ULL: return fde_sub_04a970(a0, a1, a2);
        case 0x04ae9cULL: return fde_sub_04ae9c(a0, a1, a2);
        case 0x04b024ULL: return fde_sub_04b024(a0, a1, a2);
        case 0x04b2b8ULL: return fde_sub_04b2b8(a0, a1, a2);
        case 0x04b800ULL: return fde_sub_04b800(a0, a1, a2);
        case 0x04b988ULL: return fde_sub_04b988(a0, a1, a2);
        case 0x04bc1cULL: return fde_sub_04bc1c(a0, a1, a2);
        case 0x04c164ULL: return fde_sub_04c164(a0, a1, a2);
        case 0x04c2ecULL: return fde_sub_04c2ec(a0, a1, a2);
        case 0x04c580ULL: return fde_sub_04c580(a0, a1, a2);
        case 0x04ca8cULL: return fde_sub_04ca8c(a0, a1, a2);
        case 0x04cc14ULL: return fde_sub_04cc14(a0, a1, a2);
        case 0x04ce6cULL: return fde_sub_04ce6c(a0, a1, a2);
        case 0x04d378ULL: return fde_sub_04d378(a0, a1, a2);
        case 0x04d500ULL: return fde_sub_04d500(a0, a1, a2);
        case 0x04d758ULL: return fde_sub_04d758(a0, a1, a2);
        case 0x04dc78ULL: return fde_sub_04dc78(a0, a1, a2);
        case 0x04de00ULL: return fde_sub_04de00(a0, a1, a2);
        case 0x04e058ULL: return fde_sub_04e058(a0, a1, a2);
        case 0x04e578ULL: return fde_sub_04e578(a0, a1, a2);
        case 0x04e700ULL: return fde_sub_04e700(a0, a1, a2);
        case 0x04e958ULL: return fde_sub_04e958(a0, a1, a2);
        case 0x04ee78ULL: return fde_sub_04ee78(a0, a1, a2);
        case 0x04f000ULL: return fde_sub_04f000(a0, a1, a2);
        case 0x04f258ULL: return fde_sub_04f258(a0, a1, a2);
        case 0x04f778ULL: return fde_sub_04f778(a0, a1, a2);
        case 0x04f900ULL: return fde_sub_04f900(a0, a1, a2);
        case 0x04fb58ULL: return fde_sub_04fb58(a0, a1, a2);
        case 0x05006cULL: return fde_sub_05006c(a0, a1, a2);
        case 0x0501f4ULL: return fde_sub_0501f4(a0, a1, a2);
        case 0x050454ULL: return fde_sub_050454(a0, a1, a2);
        case 0x05097cULL: return fde_sub_05097c(a0, a1, a2);
        case 0x050b04ULL: return fde_sub_050b04(a0, a1, a2);
        case 0x050d64ULL: return fde_sub_050d64(a0, a1, a2);
        case 0x0514d0ULL: return fde_sub_0514d0(a0, a1, a2);
        case 0x05174cULL: return fde_sub_05174c(a0, a1, a2);
        case 0x051b14ULL: return fde_sub_051b14(a0, a1, a2);
        case 0x051b20ULL: return fde_sub_051b20(a0, a1, a2);
        case 0x051b2cULL: return fde_sub_051b2c(a0, a1, a2);
        case 0x051b38ULL: return fde_sub_051b38(a0, a1, a2);
        case 0x051b5cULL: return fde_sub_051b5c(a0, a1, a2);
        case 0x051b80ULL: return fde_sub_051b80(a0, a1, a2);
        case 0x051cfcULL: return fde_sub_051cfc(a0, a1, a2);
        case 0x051ffcULL: return fde_sub_051ffc(a0, a1, a2);
        case 0x0520d4ULL: return fde_sub_0520d4(a0, a1, a2);
        case 0x052168ULL: return fde_sub_052168(a0, a1, a2);
        case 0x05218cULL: return fde_sub_05218c(a0, a1, a2);
        case 0x05219cULL: return fde_sub_05219c(a0, a1, a2);
        case 0x052214ULL: return fde_sub_052214(a0, a1, a2);
        case 0x05222cULL: return fde_sub_05222c(a0, a1, a2);
        case 0x052244ULL: return fde_sub_052244(a0, a1, a2);
        case 0x05228cULL: return fde_sub_05228c(a0, a1, a2);
        case 0x052350ULL: return fde_sub_052350(a0, a1, a2);
        case 0x0523d8ULL: return fde_sub_0523d8(a0, a1, a2);
        case 0x0523f0ULL: return fde_sub_0523f0(a0, a1, a2);
        case 0x05260cULL: return fde_sub_05260c(a0, a1, a2);
        case 0x052660ULL: return fde_sub_052660(a0, a1, a2);
        case 0x052678ULL: return fde_sub_052678(a0, a1, a2);
        case 0x0526d4ULL: return fde_sub_0526d4(a0, a1, a2);
        case 0x052730ULL: return fde_sub_052730(a0, a1, a2);
        case 0x052768ULL: return fde_sub_052768(a0, a1, a2);
        case 0x0527c0ULL: return fde_sub_0527c0(a0, a1, a2);
        case 0x0527c4ULL: return fde_sub_0527c4(a0, a1, a2);
        case 0x0527d4ULL: return fde_sub_0527d4(a0, a1, a2);
        case 0x052898ULL: return fde_sub_052898(a0, a1, a2);
        case 0x05297cULL: return fde_sub_05297c(a0, a1, a2);
        case 0x0529f8ULL: return fde_sub_0529f8(a0, a1, a2);
        case 0x052b14ULL: return fde_sub_052b14(a0, a1, a2);
        case 0x052c80ULL: return fde_sub_052c80(a0, a1, a2);
        case 0x052d28ULL: return fde_sub_052d28(a0, a1, a2);
        case 0x052f04ULL: return fde_sub_052f04(a0, a1, a2);
        case 0x05306cULL: return fde_sub_05306c(a0, a1, a2);
        case 0x0530c4ULL: return fde_sub_0530c4(a0, a1, a2);
        case 0x0531c0ULL: return fde_sub_0531c0(a0, a1, a2);
        case 0x0532c8ULL: return fde_sub_0532c8(a0, a1, a2);
        case 0x053330ULL: return fde_sub_053330(a0, a1, a2);
        case 0x053378ULL: return fde_sub_053378(a0, a1, a2);
        case 0x0534b4ULL: return fde_sub_0534b4(a0, a1, a2);
        case 0x0536b4ULL: return fde_sub_0536b4(a0, a1, a2);
        case 0x0537d0ULL: return fde_sub_0537d0(a0, a1, a2);
        case 0x0538ecULL: return fde_sub_0538ec(a0, a1, a2);
        case 0x053a18ULL: return fde_sub_053a18(a0, a1, a2);
        case 0x053b44ULL: return fde_sub_053b44(a0, a1, a2);
        case 0x053ca8ULL: return fde_sub_053ca8(a0, a1, a2);
        case 0x053e2cULL: return fde_sub_053e2c(a0, a1, a2);
        case 0x053eb4ULL: return fde_sub_053eb4(a0, a1, a2);
        case 0x053f4cULL: return fde_sub_053f4c(a0, a1, a2);
        case 0x053f60ULL: return fde_sub_053f60(a0, a1, a2);
        case 0x053f74ULL: return fde_sub_053f74(a0, a1, a2);
        case 0x053fc4ULL: return fde_sub_053fc4(a0, a1, a2);
        case 0x053ff4ULL: return fde_sub_053ff4(a0, a1, a2);
        case 0x054118ULL: return fde_sub_054118(a0, a1, a2);
        case 0x05412cULL: return fde_sub_05412c(a0, a1, a2);
        case 0x054264ULL: return fde_sub_054264(a0, a1, a2);
        case 0x0542b4ULL: return fde_sub_0542b4(a0, a1, a2);
        case 0x0542e4ULL: return fde_sub_0542e4(a0, a1, a2);
        case 0x0543a8ULL: return fde_sub_0543a8(a0, a1, a2);
        case 0x0543c4ULL: return fde_sub_0543c4(a0, a1, a2);
        case 0x0543c8ULL: return fde_sub_0543c8(a0, a1, a2);
        case 0x0543d0ULL: return fde_sub_0543d0(a0, a1, a2);
        case 0x0543e0ULL: return fde_sub_0543e0(a0, a1, a2);
        case 0x054428ULL: return fde_sub_054428(a0, a1, a2);
        case 0x05445cULL: return fde_sub_05445c(a0, a1, a2);
        case 0x054480ULL: return fde_sub_054480(a0, a1, a2);
        case 0x05449cULL: return fde_sub_05449c(a0, a1, a2);
        case 0x0544d4ULL: return fde_sub_0544d4(a0, a1, a2);
        case 0x054528ULL: return fde_sub_054528(a0, a1, a2);
        case 0x05453cULL: return fde_sub_05453c(a0, a1, a2);
        case 0x054548ULL: return fde_sub_054548(a0, a1, a2);
        case 0x054570ULL: return fde_sub_054570(a0, a1, a2);
        case 0x0545f4ULL: return fde_sub_0545f4(a0, a1, a2);
        case 0x054698ULL: return fde_sub_054698(a0, a1, a2);
        case 0x05469cULL: return fde_sub_05469c(a0, a1, a2);
        case 0x0546c0ULL: return fde_sub_0546c0(a0, a1, a2);
        case 0x0546d4ULL: return fde_sub_0546d4(a0, a1, a2);
        case 0x054784ULL: return fde_sub_054784(a0, a1, a2);
        case 0x05483cULL: return fde_sub_05483c(a0, a1, a2);
        case 0x054900ULL: return fde_sub_054900(a0, a1, a2);
        case 0x0549c4ULL: return fde_sub_0549c4(a0, a1, a2);
        case 0x054a04ULL: return fde_sub_054a04(a0, a1, a2);
        case 0x054b20ULL: return fde_sub_054b20(a0, a1, a2);
        case 0x054bb4ULL: return fde_sub_054bb4(a0, a1, a2);
        case 0x054c90ULL: return fde_sub_054c90(a0, a1, a2);
        case 0x054ca0ULL: return fde_sub_054ca0(a0, a1, a2);
        case 0x054d08ULL: return fde_sub_054d08(a0, a1, a2);
        case 0x054d18ULL: return fde_sub_054d18(a0, a1, a2);
        case 0x054d6cULL: return fde_sub_054d6c(a0, a1, a2);
        case 0x054db8ULL: return fde_sub_054db8(a0, a1, a2);
        case 0x054f80ULL: return fde_sub_054f80(a0, a1, a2);
        case 0x054ff4ULL: return fde_sub_054ff4(a0, a1, a2);
        case 0x055014ULL: return fde_sub_055014(a0, a1, a2);
        case 0x055094ULL: return fde_sub_055094(a0, a1, a2);
        case 0x0550b4ULL: return fde_sub_0550b4(a0, a1, a2);
        case 0x055134ULL: return fde_sub_055134(a0, a1, a2);
        case 0x055144ULL: return fde_sub_055144(a0, a1, a2);
        case 0x05518cULL: return fde_sub_05518c(a0, a1, a2);
        case 0x05524cULL: return fde_sub_05524c(a0, a1, a2);
        case 0x0552ccULL: return fde_sub_0552cc(a0, a1, a2);
        case 0x055318ULL: return fde_sub_055318(a0, a1, a2);
        case 0x05536cULL: return fde_sub_05536c(a0, a1, a2);
        case 0x055390ULL: return fde_sub_055390(a0, a1, a2);
        case 0x055aa8ULL: return fde_sub_055aa8(a0, a1, a2);
        case 0x055af8ULL: return fde_sub_055af8(a0, a1, a2);
        case 0x055b28ULL: return fde_sub_055b28(a0, a1, a2);
        case 0x055bacULL: return fde_sub_055bac(a0, a1, a2);
        case 0x055c04ULL: return fde_sub_055c04(a0, a1, a2);
        case 0x055ec8ULL: return fde_sub_055ec8(a0, a1, a2);
        case 0x055ed4ULL: return fde_sub_055ed4(a0, a1, a2);
        case 0x055efcULL: return fde_sub_055efc(a0, a1, a2);
        case 0x055f24ULL: return fde_sub_055f24(a0, a1, a2);
        case 0x055f30ULL: return fde_sub_055f30(a0, a1, a2);
        case 0x055f54ULL: return fde_sub_055f54(a0, a1, a2);
        case 0x055fd8ULL: return fde_sub_055fd8(a0, a1, a2);
        case 0x056010ULL: return fde_sub_056010(a0, a1, a2);
        case 0x056048ULL: return fde_sub_056048(a0, a1, a2);
        case 0x05604cULL: return fde_sub_05604c(a0, a1, a2);
        case 0x056070ULL: return fde_sub_056070(a0, a1, a2);
        case 0x0560fcULL: return fde_sub_0560fc(a0, a1, a2);
        case 0x056118ULL: return fde_sub_056118(a0, a1, a2);
        case 0x05621cULL: return fde_sub_05621c(a0, a1, a2);
        case 0x0562fcULL: return fde_sub_0562fc(a0, a1, a2);
        case 0x0563d8ULL: return fde_sub_0563d8(a0, a1, a2);
        case 0x0563fcULL: return fde_sub_0563fc(a0, a1, a2);
        case 0x056438ULL: return fde_sub_056438(a0, a1, a2);
        case 0x056480ULL: return fde_sub_056480(a0, a1, a2);
        case 0x056504ULL: return fde_sub_056504(a0, a1, a2);
        case 0x056650ULL: return fde_sub_056650(a0, a1, a2);
        case 0x056668ULL: return fde_sub_056668(a0, a1, a2);
        case 0x05666cULL: return fde_sub_05666c(a0, a1, a2);
        case 0x056690ULL: return fde_sub_056690(a0, a1, a2);
        case 0x056770ULL: return fde_sub_056770(a0, a1, a2);
        case 0x056774ULL: return fde_sub_056774(a0, a1, a2);
        case 0x056798ULL: return fde_sub_056798(a0, a1, a2);
        case 0x056878ULL: return fde_sub_056878(a0, a1, a2);
        case 0x05688cULL: return fde_sub_05688c(a0, a1, a2);
        case 0x0568c0ULL: return fde_sub_0568c0(a0, a1, a2);
        case 0x05690cULL: return fde_sub_05690c(a0, a1, a2);
        case 0x056918ULL: return fde_sub_056918(a0, a1, a2);
        case 0x056924ULL: return fde_sub_056924(a0, a1, a2);
        case 0x056930ULL: return fde_sub_056930(a0, a1, a2);
        case 0x05693cULL: return fde_sub_05693c(a0, a1, a2);
        case 0x056948ULL: return fde_sub_056948(a0, a1, a2);
        case 0x056968ULL: return fde_sub_056968(a0, a1, a2);
        case 0x0569e4ULL: return fde_sub_0569e4(a0, a1, a2);
        case 0x056a0cULL: return fde_sub_056a0c(a0, a1, a2);
        case 0x056a2cULL: return fde_sub_056a2c(a0, a1, a2);
        case 0x056a38ULL: return fde_sub_056a38(a0, a1, a2);
        case 0x056a6cULL: return fde_sub_056a6c(a0, a1, a2);
        case 0x056a98ULL: return fde_sub_056a98(a0, a1, a2);
        case 0x056accULL: return fde_sub_056acc(a0, a1, a2);
        case 0x056ad8ULL: return fde_sub_056ad8(a0, a1, a2);
        case 0x056b14ULL: return fde_sub_056b14(a0, a1, a2);
        case 0x056b68ULL: return fde_sub_056b68(a0, a1, a2);
        case 0x056bb0ULL: return fde_sub_056bb0(a0, a1, a2);
        case 0x056c9cULL: return fde_sub_056c9c(a0, a1, a2);
        case 0x056cacULL: return fde_sub_056cac(a0, a1, a2);
        case 0x056cb8ULL: return fde_sub_056cb8(a0, a1, a2);
        case 0x056cc8ULL: return fde_sub_056cc8(a0, a1, a2);
        case 0x056cd4ULL: return fde_sub_056cd4(a0, a1, a2);
        case 0x056cd8ULL: return fde_sub_056cd8(a0, a1, a2);
        case 0x056cdcULL: return fde_sub_056cdc(a0, a1, a2);
        case 0x056ce8ULL: return fde_sub_056ce8(a0, a1, a2);
        case 0x056cf4ULL: return fde_sub_056cf4(a0, a1, a2);
        case 0x056cfcULL: return fde_sub_056cfc(a0, a1, a2);
        case 0x056d04ULL: return fde_sub_056d04(a0, a1, a2);
        case 0x056dccULL: return fde_sub_056dcc(a0, a1, a2);
        case 0x056dd4ULL: return fde_sub_056dd4(a0, a1, a2);
        case 0x056e14ULL: return fde_sub_056e14(a0, a1, a2);
        case 0x056e1cULL: return fde_sub_056e1c(a0, a1, a2);
        case 0x056ee4ULL: return fde_sub_056ee4(a0, a1, a2);
        case 0x056eecULL: return fde_sub_056eec(a0, a1, a2);
        case 0x056f00ULL: return fde_sub_056f00(a0, a1, a2);
        case 0x056f34ULL: return fde_sub_056f34(a0, a1, a2);
        case 0x056f80ULL: return fde_sub_056f80(a0, a1, a2);
        case 0x056f8cULL: return fde_sub_056f8c(a0, a1, a2);
        case 0x056f98ULL: return fde_sub_056f98(a0, a1, a2);
        case 0x056fa4ULL: return fde_sub_056fa4(a0, a1, a2);
        case 0x056fb0ULL: return fde_sub_056fb0(a0, a1, a2);
        case 0x056fbcULL: return fde_sub_056fbc(a0, a1, a2);
        case 0x056fe0ULL: return fde_sub_056fe0(a0, a1, a2);
        case 0x057060ULL: return fde_sub_057060(a0, a1, a2);
        case 0x057088ULL: return fde_sub_057088(a0, a1, a2);
        case 0x0570a8ULL: return fde_sub_0570a8(a0, a1, a2);
        case 0x0570b4ULL: return fde_sub_0570b4(a0, a1, a2);
        case 0x0570e4ULL: return fde_sub_0570e4(a0, a1, a2);
        case 0x057110ULL: return fde_sub_057110(a0, a1, a2);
        case 0x05713cULL: return fde_sub_05713c(a0, a1, a2);
        case 0x057148ULL: return fde_sub_057148(a0, a1, a2);
        case 0x057184ULL: return fde_sub_057184(a0, a1, a2);
        case 0x0571d8ULL: return fde_sub_0571d8(a0, a1, a2);
        case 0x057220ULL: return fde_sub_057220(a0, a1, a2);
        case 0x05730cULL: return fde_sub_05730c(a0, a1, a2);
        case 0x05731cULL: return fde_sub_05731c(a0, a1, a2);
        case 0x057328ULL: return fde_sub_057328(a0, a1, a2);
        case 0x057338ULL: return fde_sub_057338(a0, a1, a2);
        case 0x057344ULL: return fde_sub_057344(a0, a1, a2);
        case 0x057348ULL: return fde_sub_057348(a0, a1, a2);
        case 0x05734cULL: return fde_sub_05734c(a0, a1, a2);
        case 0x057358ULL: return fde_sub_057358(a0, a1, a2);
        case 0x057364ULL: return fde_sub_057364(a0, a1, a2);
        case 0x05736cULL: return fde_sub_05736c(a0, a1, a2);
        case 0x057374ULL: return fde_sub_057374(a0, a1, a2);
        case 0x057448ULL: return fde_sub_057448(a0, a1, a2);
        case 0x057450ULL: return fde_sub_057450(a0, a1, a2);
        case 0x057490ULL: return fde_sub_057490(a0, a1, a2);
        case 0x057498ULL: return fde_sub_057498(a0, a1, a2);
        case 0x05756cULL: return fde_sub_05756c(a0, a1, a2);
        case 0x057574ULL: return fde_sub_057574(a0, a1, a2);
        case 0x057600ULL: return fde_sub_057600(a0, a1, a2);
        case 0x057684ULL: return fde_sub_057684(a0, a1, a2);
        case 0x057688ULL: return fde_sub_057688(a0, a1, a2);
        case 0x057690ULL: return fde_sub_057690(a0, a1, a2);
        case 0x0576a4ULL: return fde_sub_0576a4(a0, a1, a2);
        case 0x0576ccULL: return fde_sub_0576cc(a0, a1, a2);
        case 0x0576fcULL: return fde_sub_0576fc(a0, a1, a2);
        case 0x057768ULL: return fde_sub_057768(a0, a1, a2);
        case 0x057998ULL: return fde_sub_057998(a0, a1, a2);
        case 0x057adcULL: return fde_sub_057adc(a0, a1, a2);
        case 0x057ae0ULL: return fde_sub_057ae0(a0, a1, a2);
        case 0x057b10ULL: return fde_sub_057b10(a0, a1, a2);
        case 0x057b40ULL: return fde_sub_057b40(a0, a1, a2);
        case 0x057d3cULL: return fde_sub_057d3c(a0, a1, a2);
        case 0x057d40ULL: return fde_sub_057d40(a0, a1, a2);
        case 0x057eb0ULL: return fde_sub_057eb0(a0, a1, a2);
        case 0x057eb4ULL: return fde_sub_057eb4(a0, a1, a2);
        case 0x058064ULL: return fde_sub_058064(a0, a1, a2);
        case 0x058068ULL: return fde_sub_058068(a0, a1, a2);
        case 0x0581d8ULL: return fde_sub_0581d8(a0, a1, a2);
        case 0x0581dcULL: return fde_sub_0581dc(a0, a1, a2);
        case 0x058390ULL: return fde_sub_058390(a0, a1, a2);
        case 0x058394ULL: return fde_sub_058394(a0, a1, a2);
        case 0x058504ULL: return fde_sub_058504(a0, a1, a2);
        case 0x058508ULL: return fde_sub_058508(a0, a1, a2);
        case 0x058678ULL: return fde_sub_058678(a0, a1, a2);
        case 0x05867cULL: return fde_sub_05867c(a0, a1, a2);
        case 0x0587ecULL: return fde_sub_0587ec(a0, a1, a2);
        case 0x0587f0ULL: return fde_sub_0587f0(a0, a1, a2);
        case 0x058960ULL: return fde_sub_058960(a0, a1, a2);
        case 0x058964ULL: return fde_sub_058964(a0, a1, a2);
        case 0x058ad4ULL: return fde_sub_058ad4(a0, a1, a2);
        case 0x058ad8ULL: return fde_sub_058ad8(a0, a1, a2);
        case 0x058c48ULL: return fde_sub_058c48(a0, a1, a2);
        case 0x058c4cULL: return fde_sub_058c4c(a0, a1, a2);
        case 0x058dbcULL: return fde_sub_058dbc(a0, a1, a2);
        case 0x058dc0ULL: return fde_sub_058dc0(a0, a1, a2);
        case 0x058f30ULL: return fde_sub_058f30(a0, a1, a2);
        case 0x058f34ULL: return fde_sub_058f34(a0, a1, a2);
        case 0x0590a4ULL: return fde_sub_0590a4(a0, a1, a2);
        case 0x059208ULL: return fde_sub_059208(a0, a1, a2);
        case 0x05923cULL: return fde_sub_05923c(a0, a1, a2);
        case 0x059304ULL: return fde_sub_059304(a0, a1, a2);
        case 0x05953cULL: return fde_sub_05953c(a0, a1, a2);
        case 0x0595f4ULL: return fde_sub_0595f4(a0, a1, a2);
        case 0x0597a8ULL: return fde_sub_0597a8(a0, a1, a2);
        case 0x059870ULL: return fde_sub_059870(a0, a1, a2);
        case 0x059ae8ULL: return fde_sub_059ae8(a0, a1, a2);
        case 0x059ce4ULL: return fde_sub_059ce4(a0, a1, a2);
        case 0x059e30ULL: return fde_sub_059e30(a0, a1, a2);
        case 0x059f7cULL: return fde_sub_059f7c(a0, a1, a2);
        case 0x05a124ULL: return fde_sub_05a124(a0, a1, a2);
        case 0x05a2c4ULL: return fde_sub_05a2c4(a0, a1, a2);
        case 0x05a450ULL: return fde_sub_05a450(a0, a1, a2);
        case 0x05a584ULL: return fde_sub_05a584(a0, a1, a2);
        case 0x05a6bcULL: return fde_sub_05a6bc(a0, a1, a2);
        case 0x05a830ULL: return fde_sub_05a830(a0, a1, a2);
        case 0x05a9a4ULL: return fde_sub_05a9a4(a0, a1, a2);
        case 0x05aa30ULL: return fde_sub_05aa30(a0, a1, a2);
        case 0x05aab4ULL: return fde_sub_05aab4(a0, a1, a2);
        case 0x05aab8ULL: return fde_sub_05aab8(a0, a1, a2);
        case 0x05aac0ULL: return fde_sub_05aac0(a0, a1, a2);
        case 0x05aad4ULL: return fde_sub_05aad4(a0, a1, a2);
        case 0x05aafcULL: return fde_sub_05aafc(a0, a1, a2);
        case 0x05ab2cULL: return fde_sub_05ab2c(a0, a1, a2);
        case 0x05ab98ULL: return fde_sub_05ab98(a0, a1, a2);
        case 0x05ade4ULL: return fde_sub_05ade4(a0, a1, a2);
        case 0x05af28ULL: return fde_sub_05af28(a0, a1, a2);
        case 0x05af2cULL: return fde_sub_05af2c(a0, a1, a2);
        case 0x05af5cULL: return fde_sub_05af5c(a0, a1, a2);
        case 0x05af8cULL: return fde_sub_05af8c(a0, a1, a2);
        case 0x05b190ULL: return fde_sub_05b190(a0, a1, a2);
        case 0x05b194ULL: return fde_sub_05b194(a0, a1, a2);
        case 0x05b304ULL: return fde_sub_05b304(a0, a1, a2);
        case 0x05b308ULL: return fde_sub_05b308(a0, a1, a2);
        case 0x05b4b8ULL: return fde_sub_05b4b8(a0, a1, a2);
        case 0x05b4bcULL: return fde_sub_05b4bc(a0, a1, a2);
        case 0x05b62cULL: return fde_sub_05b62c(a0, a1, a2);
        case 0x05b630ULL: return fde_sub_05b630(a0, a1, a2);
        case 0x05b7e4ULL: return fde_sub_05b7e4(a0, a1, a2);
        case 0x05b7e8ULL: return fde_sub_05b7e8(a0, a1, a2);
        case 0x05b958ULL: return fde_sub_05b958(a0, a1, a2);
        case 0x05b95cULL: return fde_sub_05b95c(a0, a1, a2);
        case 0x05baccULL: return fde_sub_05bacc(a0, a1, a2);
        case 0x05bad0ULL: return fde_sub_05bad0(a0, a1, a2);
        case 0x05bc40ULL: return fde_sub_05bc40(a0, a1, a2);
        case 0x05bc44ULL: return fde_sub_05bc44(a0, a1, a2);
        case 0x05bdb4ULL: return fde_sub_05bdb4(a0, a1, a2);
        case 0x05bdb8ULL: return fde_sub_05bdb8(a0, a1, a2);
        case 0x05bf28ULL: return fde_sub_05bf28(a0, a1, a2);
        case 0x05bf2cULL: return fde_sub_05bf2c(a0, a1, a2);
        case 0x05c09cULL: return fde_sub_05c09c(a0, a1, a2);
        case 0x05c0a0ULL: return fde_sub_05c0a0(a0, a1, a2);
        case 0x05c210ULL: return fde_sub_05c210(a0, a1, a2);
        case 0x05c214ULL: return fde_sub_05c214(a0, a1, a2);
        case 0x05c384ULL: return fde_sub_05c384(a0, a1, a2);
        case 0x05c388ULL: return fde_sub_05c388(a0, a1, a2);
        case 0x05c4f8ULL: return fde_sub_05c4f8(a0, a1, a2);
        case 0x05c660ULL: return fde_sub_05c660(a0, a1, a2);
        case 0x05c694ULL: return fde_sub_05c694(a0, a1, a2);
        case 0x05c75cULL: return fde_sub_05c75c(a0, a1, a2);
        case 0x05c998ULL: return fde_sub_05c998(a0, a1, a2);
        case 0x05ca50ULL: return fde_sub_05ca50(a0, a1, a2);
        case 0x05cc08ULL: return fde_sub_05cc08(a0, a1, a2);
        case 0x05ccd0ULL: return fde_sub_05ccd0(a0, a1, a2);
        case 0x05cf44ULL: return fde_sub_05cf44(a0, a1, a2);
        case 0x05d140ULL: return fde_sub_05d140(a0, a1, a2);
        case 0x05d28cULL: return fde_sub_05d28c(a0, a1, a2);
        case 0x05d3d8ULL: return fde_sub_05d3d8(a0, a1, a2);
        case 0x05d584ULL: return fde_sub_05d584(a0, a1, a2);
        case 0x05d730ULL: return fde_sub_05d730(a0, a1, a2);
        case 0x05d8c8ULL: return fde_sub_05d8c8(a0, a1, a2);
        case 0x05d9fcULL: return fde_sub_05d9fc(a0, a1, a2);
        case 0x05db34ULL: return fde_sub_05db34(a0, a1, a2);
        case 0x05dca8ULL: return fde_sub_05dca8(a0, a1, a2);
        case 0x05de1cULL: return fde_sub_05de1c(a0, a1, a2);
        case 0x05dea4ULL: return fde_sub_05dea4(a0, a1, a2);
        case 0x05df20ULL: return fde_sub_05df20(a0, a1, a2);
        case 0x05df24ULL: return fde_sub_05df24(a0, a1, a2);
        case 0x05df2cULL: return fde_sub_05df2c(a0, a1, a2);
        case 0x05df40ULL: return fde_sub_05df40(a0, a1, a2);
        case 0x05df68ULL: return fde_sub_05df68(a0, a1, a2);
        default: return 0ULL;
    }
}

} // namespace ndk_libcxx_recon
