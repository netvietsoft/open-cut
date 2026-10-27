// ============================================================================
// File: cxx_shared_fde_shard_2.cpp
// Target 111 / 169: libc++_shared.so (919,888 bytes)
// EN: Clean-room C++17 AArch64 FDE Shard 2/5 covering FDEs [391..781]
//     (PC range 0x05df98 .. 0x074f74).
// VI: Phân mảnh FDE AArch64 C++17 2/5 bao phủ FDE [391..781]
//     (Dải địa chỉ PC 0x05df98 .. 0x074f74).
// ============================================================================
#include "cxx_shared_core.h"

namespace ndk_libcxx_recon {

// FDE #0391 | PC: 0x05df98..0x05dff4 (92 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE4swapERS3_
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_05df98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DF98ULL;
}

// FDE #0392 | PC: 0x05dff4..0x05e040 (76 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryC1ERS3_
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; strb wzr, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; strb wzr, [x0]]
uint64_t fde_sub_05dff4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DFF4ULL;
}

// FDE #0393 | PC: 0x05e040..0x05e0f4 (180 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #8]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #8]]
uint64_t fde_sub_05e040(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x00B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E040ULL;
}

// FDE #0394 | PC: 0x05e0f4..0x05e0f8 (4 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEPFRS3_S4_E
// EN: AArch64 prologue [br x1] | VI: Khởi đầu hàm AArch64 [br x1]
uint64_t fde_sub_05e0f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0xD61F0020ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E0F4ULL;
}

// FDE #0395 | PC: 0x05e0f8..0x05e128 (48 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEPFRNS_9basic_iosIcS2_EES6_E
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_05e0f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E0F8ULL;
}

// FDE #0396 | PC: 0x05e128..0x05e158 (48 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEPFRNS_8ios_baseES5_E
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_05e128(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E128ULL;
}

// FDE #0397 | PC: 0x05e158..0x05e348 (496 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEb
// EN: AArch64 prologue [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_05e158(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F9ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E158ULL;
}

// FDE #0398 | PC: 0x05e348..0x05e558 (528 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEs
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_05e348(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90267FAULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0210ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E348ULL;
}

// FDE #0399 | PC: 0x05e558..0x05e748 (496 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEt
// EN: AArch64 prologue [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_05e558(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F9ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E558ULL;
}

// FDE #0400 | PC: 0x05e748..0x05e958 (528 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEi
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_05e748(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90267FAULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0210ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E748ULL;
}

// FDE #0401 | PC: 0x05e958..0x05eb48 (496 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEj
// EN: AArch64 prologue [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_05e958(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F9ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E958ULL;
}

// FDE #0402 | PC: 0x05eb48..0x05ed38 (496 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEl
// EN: AArch64 prologue [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_05eb48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F9ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05EB48ULL;
}

// FDE #0403 | PC: 0x05ed38..0x05ef28 (496 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEm
// EN: AArch64 prologue [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_05ed38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F9ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05ED38ULL;
}

// FDE #0404 | PC: 0x05ef28..0x05f118 (496 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEx
// EN: AArch64 prologue [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_05ef28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F9ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05EF28ULL;
}

// FDE #0405 | PC: 0x05f118..0x05f308 (496 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEy
// EN: AArch64 prologue [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_05f118(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F9ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F118ULL;
}

// FDE #0406 | PC: 0x05f308..0x05f4f8 (496 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEf
// EN: AArch64 prologue [sub sp, sp, #0x70; str d8, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str d8, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_05f308(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0013E8ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F308ULL;
}

// FDE #0407 | PC: 0x05f4f8..0x05f6e8 (496 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEd
// EN: AArch64 prologue [sub sp, sp, #0x70; str d8, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str d8, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_05f4f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0013E8ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F4F8ULL;
}

// FDE #0408 | PC: 0x05f6e8..0x05f8d0 (488 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEe
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_05f6e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9035FF8ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F6E8ULL;
}

// FDE #0409 | PC: 0x05f8d0..0x05fac0 (496 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEPKv
// EN: AArch64 prologue [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_05f8d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F9ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F8D0ULL;
}

// FDE #0410 | PC: 0x05fac0..0x05fd28 (616 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEPNS_15basic_streambufIcS2_EE
// EN: AArch64 prologue [sub sp, sp, #0x60; str x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_05fac0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0268ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FAC0ULL;
}

// FDE #0411 | PC: 0x05fd28..0x05fe84 (348 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE3putEc
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_05fd28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x015CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FD28ULL;
}

// FDE #0412 | PC: 0x05fe84..0x05ffcc (328 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE5writeEPKcl
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_05fe84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90257F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0148ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FE84ULL;
}

// FDE #0413 | PC: 0x05ffcc..0x060024 (88 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE5tellpEv
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0]; mov w10, #5] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0]; mov w10, #5]
uint64_t fde_sub_05ffcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FFCCULL;
}

// FDE #0414 | PC: 0x060024..0x060150 (300 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE5seekpENS_4fposI9mbstate_tEE
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_060024(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90257F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060024ULL;
}

// FDE #0415 | PC: 0x060150..0x06027c (300 B) | Symbol: _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE5seekpExNS_8ios_base7seekdirE
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_060150(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90257F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060150ULL;
}

// FDE #0416 | PC: 0x06027c..0x060304 (136 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEEC2EPNS_15basic_streambufIwS2_EE
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x1]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x1]]
uint64_t fde_sub_06027c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06027CULL;
}

// FDE #0417 | PC: 0x060304..0x060380 (124 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEEC1EPNS_15basic_streambufIwS2_EE
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_060304(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060304ULL;
}

// FDE #0418 | PC: 0x060380..0x060384 (4 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEED2Ev
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_060380(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91002000ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060380ULL;
}

// FDE #0419 | PC: 0x060384..0x06038c (8 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEED1Ev
// EN: AArch64 prologue [add x0, x0, #8; b #0x47b90] | VI: Khởi đầu hàm AArch64 [add x0, x0, #8; b #0x47b90]
uint64_t fde_sub_060384(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF9E02ULL) << 32) | 0x91002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060384ULL;
}

// FDE #0420 | PC: 0x06038c..0x0603a0 (20 B) | Symbol: _ZTv0_n24_NSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEED1Ev
// EN: AArch64 prologue [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x8, x0, x8; add x0, x8, #8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x8, x0, x8; add x0, x8, #8]
uint64_t fde_sub_06038c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF85E8108ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06038CULL;
}

// FDE #0421 | PC: 0x0603a0..0x0603c8 (40 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0603a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0603A0ULL;
}

// FDE #0422 | PC: 0x0603c8..0x0603f8 (48 B) | Symbol: _ZTv0_n24_NSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_0603c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0603C8ULL;
}

// FDE #0423 | PC: 0x0603f8..0x060454 (92 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEE4swapERS3_
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_0603f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0603F8ULL;
}

// FDE #0424 | PC: 0x060454..0x0604a0 (76 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEE6sentryC1ERS3_
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; strb wzr, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; strb wzr, [x0]]
uint64_t fde_sub_060454(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060454ULL;
}

// FDE #0425 | PC: 0x0604a0..0x060554 (180 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEE6sentryD1Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #8]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #8]]
uint64_t fde_sub_0604a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x00B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0604A0ULL;
}

// FDE #0426 | PC: 0x060554..0x060558 (4 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEPFRS3_S4_E
// EN: AArch64 prologue [br x1] | VI: Khởi đầu hàm AArch64 [br x1]
uint64_t fde_sub_060554(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0xD61F0020ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060554ULL;
}

// FDE #0427 | PC: 0x060558..0x060588 (48 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEPFRNS_9basic_iosIwS2_EES6_E
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_060558(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060558ULL;
}

// FDE #0428 | PC: 0x060588..0x0605b8 (48 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEPFRNS_8ios_baseES5_E
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_060588(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060588ULL;
}

// FDE #0429 | PC: 0x0605b8..0x0607a8 (496 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEb
// EN: AArch64 prologue [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_0605b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F9ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0605B8ULL;
}

// FDE #0430 | PC: 0x0607a8..0x0609b8 (528 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEs
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_0607a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90267FAULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0210ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0607A8ULL;
}

// FDE #0431 | PC: 0x0609b8..0x060ba8 (496 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEt
// EN: AArch64 prologue [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_0609b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F9ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0609B8ULL;
}

// FDE #0432 | PC: 0x060ba8..0x060db8 (528 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEi
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_060ba8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90267FAULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0210ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060BA8ULL;
}

// FDE #0433 | PC: 0x060db8..0x060fa8 (496 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEj
// EN: AArch64 prologue [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_060db8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F9ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060DB8ULL;
}

// FDE #0434 | PC: 0x060fa8..0x061198 (496 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEl
// EN: AArch64 prologue [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_060fa8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F9ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060FA8ULL;
}

// FDE #0435 | PC: 0x061198..0x061388 (496 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEm
// EN: AArch64 prologue [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_061198(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F9ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061198ULL;
}

// FDE #0436 | PC: 0x061388..0x061578 (496 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEx
// EN: AArch64 prologue [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_061388(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F9ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061388ULL;
}

// FDE #0437 | PC: 0x061578..0x061768 (496 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEy
// EN: AArch64 prologue [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_061578(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F9ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061578ULL;
}

// FDE #0438 | PC: 0x061768..0x061958 (496 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEf
// EN: AArch64 prologue [sub sp, sp, #0x70; str d8, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str d8, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_061768(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0013E8ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061768ULL;
}

// FDE #0439 | PC: 0x061958..0x061b48 (496 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEd
// EN: AArch64 prologue [sub sp, sp, #0x70; str d8, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str d8, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_061958(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0013E8ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061958ULL;
}

// FDE #0440 | PC: 0x061b48..0x061d30 (488 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEe
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]]
uint64_t fde_sub_061b48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9035FF8ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061B48ULL;
}

// FDE #0441 | PC: 0x061d30..0x061f20 (496 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEPKv
// EN: AArch64 prologue [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_061d30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F9ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061D30ULL;
}

// FDE #0442 | PC: 0x061f20..0x06219c (636 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEElsEPNS_15basic_streambufIwS2_EE
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_061f20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9025FF8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x027CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061F20ULL;
}

// FDE #0443 | PC: 0x06219c..0x062304 (360 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEE3putEw
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_06219c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0168ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06219CULL;
}

// FDE #0444 | PC: 0x062304..0x06244c (328 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEE5writeEPKwl
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_062304(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90257F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0148ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062304ULL;
}

// FDE #0445 | PC: 0x06244c..0x0624a4 (88 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEE5tellpEv
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0]; mov w10, #5] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0]; mov w10, #5]
uint64_t fde_sub_06244c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06244CULL;
}

// FDE #0446 | PC: 0x0624a4..0x0625d0 (300 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEE5seekpENS_4fposI9mbstate_tEE
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_0624a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90257F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0624A4ULL;
}

// FDE #0447 | PC: 0x0625d0..0x0626fc (300 B) | Symbol: _ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEE5seekpExNS_8ios_base7seekdirE
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_0625d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90257F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0625D0ULL;
}

// FDE #0448 | PC: 0x0626fc..0x0627cc (208 B) | Symbol: _ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEEC2EPNS_15basic_streambufIcS2_EE
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0626fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0626FCULL;
}

// FDE #0449 | PC: 0x0627cc..0x062874 (168 B) | Symbol: _ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEEC1EPNS_15basic_streambufIcS2_EE
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_0627cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0627CCULL;
}

// FDE #0450 | PC: 0x062874..0x062878 (4 B) | Symbol: _ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED2Ev
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_062874(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91006000ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062874ULL;
}

// FDE #0451 | PC: 0x062878..0x062880 (8 B) | Symbol: _ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED1Ev
// EN: AArch64 prologue [add x0, x0, #0x18; b #0x47b90] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x18; b #0x47b90]
uint64_t fde_sub_062878(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF94C5ULL) << 32) | 0x91006000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062878ULL;
}

// FDE #0452 | PC: 0x062880..0x062888 (8 B) | Symbol: _ZThn16_NSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED1Ev
// EN: AArch64 prologue [add x0, x0, #8; b #0x47b90] | VI: Khởi đầu hàm AArch64 [add x0, x0, #8; b #0x47b90]
uint64_t fde_sub_062880(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF94C3ULL) << 32) | 0x91002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062880ULL;
}

// FDE #0453 | PC: 0x062888..0x06289c (20 B) | Symbol: _ZTv0_n24_NSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED1Ev
// EN: AArch64 prologue [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x8, x0, x8; add x0, x8, #0x18] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldur x8, [x8, #-0x18]; add x8, x0, x8; add x0, x8, #0x18]
uint64_t fde_sub_062888(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF85E8108ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062888ULL;
}

// FDE #0454 | PC: 0x06289c..0x0628c4 (40 B) | Symbol: _ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_06289c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06289CULL;
}

// FDE #0455 | PC: 0x0628c4..0x0628ec (40 B) | Symbol: _ZThn16_NSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub x19, x0, #0x10] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; sub x19, x0, #0x10]
uint64_t fde_sub_0628c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0628C4ULL;
}

// FDE #0456 | PC: 0x0628ec..0x06291c (48 B) | Symbol: _ZTv0_n24_NSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_0628ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0628ECULL;
}

// FDE #0457 | PC: 0x06291c..0x062988 (108 B) | Symbol: _ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEE4swapERS3_
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x1, #8]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x1, #8]]
uint64_t fde_sub_06291c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06291CULL;
}

// FDE #0458 | PC: 0x062988..0x062a5c (212 B) | Symbol: sub_062988
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_062988(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062988ULL;
}

// FDE #0459 | PC: 0x062a5c..0x062a80 (36 B) | Symbol: sub_062a5c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_062a5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062A5CULL;
}

// FDE #0460 | PC: 0x062a80..0x062f30 (1200 B) | Symbol: _ZNSt6__ndk18ios_base4InitC1Ev
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_062a80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9026FFCULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x04B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062A80ULL;
}

// FDE #0461 | PC: 0x062f30..0x062f78 (72 B) | Symbol: _ZNSt6__ndk18ios_base4InitD2Ev
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0xe3000; ldr x0, [x0, #0xb78]] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; adrp x0, #0xe3000; ldr x0, [x0, #0xb78]]
uint64_t fde_sub_062f30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062F30ULL;
}

// FDE #0462 | PC: 0x062f78..0x063070 (248 B) | Symbol: sub_062f78
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_062f78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062F78ULL;
}

// FDE #0463 | PC: 0x063070..0x063168 (248 B) | Symbol: sub_063070
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_063070(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063070ULL;
}

// FDE #0464 | PC: 0x063168..0x06319c (52 B) | Symbol: sub_063168
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_063168(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063168ULL;
}

// FDE #0465 | PC: 0x06319c..0x063214 (120 B) | Symbol: sub_06319c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x8, x1] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x8, x1]
uint64_t fde_sub_06319c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06319CULL;
}

// FDE #0466 | PC: 0x063214..0x06321c (8 B) | Symbol: sub_063214
// EN: AArch64 prologue [mov w1, wzr; b #0x63374] | VI: Khởi đầu hàm AArch64 [mov w1, wzr; b #0x63374]
uint64_t fde_sub_063214(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000057ULL) << 32) | 0x2A1F03E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063214ULL;
}

// FDE #0467 | PC: 0x06321c..0x063224 (8 B) | Symbol: sub_06321c
// EN: AArch64 prologue [mov w1, #1; b #0x63374] | VI: Khởi đầu hàm AArch64 [mov w1, #1; b #0x63374]
uint64_t fde_sub_06321c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000055ULL) << 32) | 0x52800021ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06321CULL;
}

// FDE #0468 | PC: 0x063224..0x063340 (284 B) | Symbol: sub_063224
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_063224(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90357F6ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063224ULL;
}

// FDE #0469 | PC: 0x063340..0x063374 (52 B) | Symbol: sub_063340
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_063340(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063340ULL;
}

// FDE #0470 | PC: 0x063374..0x063504 (400 B) | Symbol: sub_063374
// EN: AArch64 prologue [sub sp, sp, #0x80; str x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]]
uint64_t fde_sub_063374(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF9ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0190ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063374ULL;
}

// FDE #0471 | PC: 0x063504..0x063538 (52 B) | Symbol: sub_063504
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_063504(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063504ULL;
}

// FDE #0472 | PC: 0x063538..0x0635b0 (120 B) | Symbol: sub_063538
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x8, x1] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x8, x1]
uint64_t fde_sub_063538(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063538ULL;
}

// FDE #0473 | PC: 0x0635b0..0x0635b8 (8 B) | Symbol: sub_0635b0
// EN: AArch64 prologue [mov w1, wzr; b #0x63724] | VI: Khởi đầu hàm AArch64 [mov w1, wzr; b #0x63724]
uint64_t fde_sub_0635b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400005CULL) << 32) | 0x2A1F03E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0635B0ULL;
}

// FDE #0474 | PC: 0x0635b8..0x0635c0 (8 B) | Symbol: sub_0635b8
// EN: AArch64 prologue [mov w1, #1; b #0x63724] | VI: Khởi đầu hàm AArch64 [mov w1, #1; b #0x63724]
uint64_t fde_sub_0635b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400005AULL) << 32) | 0x52800021ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0635B8ULL;
}

// FDE #0475 | PC: 0x0635c0..0x0636dc (284 B) | Symbol: sub_0635c0
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_0635c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90357F6ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0635C0ULL;
}

// FDE #0476 | PC: 0x0636dc..0x0636f0 (20 B) | Symbol: sub_0636dc
// EN: AArch64 prologue [adrp x8, #0xe3000; ldr x8, [x8, #0xc78]; add x8, x8, #0x10; str x8, [x0], #8] | VI: Khởi đầu hàm AArch64 [adrp x8, #0xe3000; ldr x8, [x8, #0xc78]; add x8, x8, #0x10; str x8, [x0], #8]
uint64_t fde_sub_0636dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9463D08ULL) << 32) | 0x90000408ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0636DCULL;
}

// FDE #0477 | PC: 0x0636f0..0x063724 (52 B) | Symbol: sub_0636f0
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_0636f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0636F0ULL;
}

// FDE #0478 | PC: 0x063724..0x0638b4 (400 B) | Symbol: sub_063724
// EN: AArch64 prologue [sub sp, sp, #0x80; str x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]]
uint64_t fde_sub_063724(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF9ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0190ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063724ULL;
}

// FDE #0479 | PC: 0x0638b4..0x0638c8 (20 B) | Symbol: sub_0638b4
// EN: AArch64 prologue [adrp x8, #0xe3000; ldr x8, [x8, #0xc08]; add x8, x8, #0x10; str x8, [x0], #8] | VI: Khởi đầu hàm AArch64 [adrp x8, #0xe3000; ldr x8, [x8, #0xc08]; add x8, x8, #0x10; str x8, [x0], #8]
uint64_t fde_sub_0638b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9460508ULL) << 32) | 0x90000408ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0638B4ULL;
}

// FDE #0480 | PC: 0x0638c8..0x0638fc (52 B) | Symbol: sub_0638c8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_0638c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0638C8ULL;
}

// FDE #0481 | PC: 0x0638fc..0x063950 (84 B) | Symbol: sub_0638fc
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_0638fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0638FCULL;
}

// FDE #0482 | PC: 0x063950..0x063a18 (200 B) | Symbol: sub_063950
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_063950(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9025FF8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063950ULL;
}

// FDE #0483 | PC: 0x063a18..0x063ab0 (152 B) | Symbol: sub_063a18
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_063a18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063A18ULL;
}

// FDE #0484 | PC: 0x063ab0..0x063bf4 (324 B) | Symbol: sub_063ab0
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]]
uint64_t fde_sub_063ab0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90367FAULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0144ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063AB0ULL;
}

// FDE #0485 | PC: 0x063bf4..0x063c28 (52 B) | Symbol: sub_063bf4
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_063bf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063BF4ULL;
}

// FDE #0486 | PC: 0x063c28..0x063c7c (84 B) | Symbol: sub_063c28
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_063c28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063C28ULL;
}

// FDE #0487 | PC: 0x063c7c..0x063d44 (200 B) | Symbol: sub_063c7c
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_063c7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9025FF8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063C7CULL;
}

// FDE #0488 | PC: 0x063d44..0x063ddc (152 B) | Symbol: sub_063d44
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_063d44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063D44ULL;
}

// FDE #0489 | PC: 0x063ddc..0x063f20 (324 B) | Symbol: sub_063ddc
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]]
uint64_t fde_sub_063ddc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90367FAULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0144ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063DDCULL;
}

// FDE #0490 | PC: 0x063f20..0x063fc0 (160 B) | Symbol: sub_063f20
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #8]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #8]]
uint64_t fde_sub_063f20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063F20ULL;
}

// FDE #0491 | PC: 0x063fc0..0x064060 (160 B) | Symbol: sub_063fc0
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #8]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #8]]
uint64_t fde_sub_063fc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063FC0ULL;
}

// FDE #0492 | PC: 0x064060..0x0640e0 (128 B) | Symbol: _ZNSt6__ndk16__clocEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000]
uint64_t fde_sub_064060(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064060ULL;
}

// FDE #0493 | PC: 0x0640e0..0x064174 (148 B) | Symbol: _ZNSt6__ndk114__num_put_base12__format_intEPcPKcbj
// EN: AArch64 prologue [tbnz w3, #0xb, #0x640f4; tbnz w3, #9, #0x64100; ldrb w8, [x1]; cbnz w8, #0x64110] | VI: Khởi đầu hàm AArch64 [tbnz w3, #0xb, #0x640f4; tbnz w3, #9, #0x64100; ldrb w8, [x1]; cbnz w8, #0x64110]
uint64_t fde_sub_0640e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x374800E3ULL) << 32) | 0x375800A3ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0640E0ULL;
}

// FDE #0494 | PC: 0x064174..0x0641e0 (108 B) | Symbol: _ZNSt6__ndk114__num_put_base18__identify_paddingEPcS1_RKNS_8ios_baseE
// EN: AArch64 prologue [ldr w8, [x2, #8]; mov w9, #0xb0; and w8, w8, w9; cmp w8, #0x20] | VI: Khởi đầu hàm AArch64 [ldr w8, [x2, #8]; mov w9, #0xb0; and w8, w8, w9; cmp w8, #0x20]
uint64_t fde_sub_064174(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52801609ULL) << 32) | 0xB9400848ULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064174ULL;
}

// FDE #0495 | PC: 0x0641e0..0x0642a0 (192 B) | Symbol: _ZNSt6__ndk114__num_put_base14__format_floatEPcPKcj
// EN: AArch64 prologue [tbz w2, #0xb, #0x641ec; mov w8, #0x2b; strb w8, [x0], #1; tbz w2, #0xa, #0x641f8] | VI: Khởi đầu hàm AArch64 [tbz w2, #0xb, #0x641ec; mov w8, #0x2b; strb w8, [x0], #1; tbz w2, #0xa, #0x641f8]
uint64_t fde_sub_0641e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800568ULL) << 32) | 0x36580062ULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0641E0ULL;
}

// FDE #0496 | PC: 0x0642a0..0x064330 (144 B) | Symbol: _ZNKSt6__ndk110__time_put8__do_putEPcRS1_PK2tmcc
// EN: AArch64 prologue [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0642a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0642A0ULL;
}

// FDE #0497 | PC: 0x064330..0x064440 (272 B) | Symbol: _ZNKSt6__ndk110__time_put8__do_putEPwRS1_PK2tmcc
// EN: AArch64 prologue [sub sp, sp, #0xc0; str x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]; stp x20, x19, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; str x23, [sp, #0x80]; stp x22, x21, [sp, #0x90]; stp x20, x19, [sp, #0xa0]]
uint64_t fde_sub_064330(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90043F7ULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x0110ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064330ULL;
}

// FDE #0498 | PC: 0x064440..0x064444 (4 B) | Symbol: _ZNSt6__ndk112__do_nothingEPv
// EN: AArch64 prologue [ret] | VI: Khởi đầu hàm AArch64 [ret]
uint64_t fde_sub_064440(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE4FF4ULL) << 32) | 0xD65F03C0ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064440ULL;
}

// FDE #0499 | PC: 0x064444..0x064494 (80 B) | Symbol: _ZNSt6__ndk121__throw_runtime_errorEPKc
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0]
uint64_t fde_sub_064444(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064444ULL;
}

// FDE #0500 | PC: 0x064494..0x06459c (264 B) | Symbol: _ZNSt6__ndk116__check_groupingERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPjS8_Rj
// EN: AArch64 prologue [ldrb w11, [x0]; ldr x8, [x0, #8]; lsr x9, x11, #1; tst w11, #1] | VI: Khởi đầu hàm AArch64 [ldrb w11, [x0]; ldr x8, [x0, #8]; lsr x9, x11, #1; tst w11, #1]
uint64_t fde_sub_064494(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400408ULL) << 32) | 0x3940000BULL;
    const uint64_t kPcRange = 0x0108ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064494ULL;
}

// FDE #0501 | PC: 0x06459c..0x064640 (164 B) | Symbol: sub_06459c
// EN: AArch64 prologue [sub sp, sp, #0x110; stp x28, x19, [sp, #0xf0]; stp x29, x30, [sp, #0x100]; add x29, sp, #0x100] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; stp x28, x19, [sp, #0xf0]; stp x29, x30, [sp, #0x100]; add x29, sp, #0x100]
uint64_t fde_sub_06459c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90F4FFCULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06459CULL;
}

// FDE #0502 | PC: 0x064640..0x066294 (7252 B) | Symbol: sub_064640
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp x28, x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp x28, x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]]
uint64_t fde_sub_064640(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9046FFCULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x1C54ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064640ULL;
}

// FDE #0503 | PC: 0x066294..0x0669e8 (1876 B) | Symbol: sub_066294
// EN: AArch64 prologue [sub sp, sp, #0x80; str x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_066294(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013FBULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0754ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066294ULL;
}

// FDE #0504 | PC: 0x0669e8..0x066a78 (144 B) | Symbol: _ZNSt6__ndk16locale7classicEv
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000]
uint64_t fde_sub_0669e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0669E8ULL;
}

// FDE #0505 | PC: 0x066a78..0x066c14 (412 B) | Symbol: sub_066a78
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_066a78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x019CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066A78ULL;
}

// FDE #0506 | PC: 0x066c14..0x06732c (1816 B) | Symbol: sub_066c14
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_066c14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9026FFCULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0718ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066C14ULL;
}

// FDE #0507 | PC: 0x06732c..0x068c98 (6508 B) | Symbol: sub_06732c
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp x28, x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp x28, x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]]
uint64_t fde_sub_06732c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9046FFCULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x196CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06732CULL;
}

// FDE #0508 | PC: 0x068c98..0x068f00 (616 B) | Symbol: sub_068c98
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_068c98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x0268ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068C98ULL;
}

// FDE #0509 | PC: 0x068f00..0x068fac (172 B) | Symbol: sub_068f00
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_068f00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068F00ULL;
}

// FDE #0510 | PC: 0x068fac..0x069058 (172 B) | Symbol: sub_068fac
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_068fac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068FACULL;
}

// FDE #0511 | PC: 0x069058..0x06907c (36 B) | Symbol: sub_069058
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_069058(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069058ULL;
}

// FDE #0512 | PC: 0x06907c..0x0690a8 (44 B) | Symbol: sub_06907c
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldp x8, x9, [x0, #0x10]; sub x9, x9, x8] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldp x8, x9, [x0, #0x10]; sub x9, x9, x8]
uint64_t fde_sub_06907c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06907CULL;
}

// FDE #0513 | PC: 0x0690a8..0x0690e0 (56 B) | Symbol: sub_0690a8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x19, #0xe6000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x19, #0xe6000]
uint64_t fde_sub_0690a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0690A8ULL;
}

// FDE #0514 | PC: 0x0690e0..0x069184 (164 B) | Symbol: sub_0690e0
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000]
uint64_t fde_sub_0690e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0690E0ULL;
}

// FDE #0515 | PC: 0x069184..0x069274 (240 B) | Symbol: _ZNSt6__ndk16locale8__globalEv
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_069184(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069184ULL;
}

// FDE #0516 | PC: 0x069274..0x0692a0 (44 B) | Symbol: _ZNSt6__ndk16localeC2Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_069274(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069274ULL;
}

// FDE #0517 | PC: 0x0692a0..0x0692b0 (16 B) | Symbol: _ZNSt6__ndk16localeC1ERKS0_
// EN: AArch64 prologue [ldr x8, [x1]; str x8, [x0]; mov x0, x8; b #0x47dd0] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1]; str x8, [x0]; mov x0, x8; b #0x47dd0]
uint64_t fde_sub_0692a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000008ULL) << 32) | 0xF9400028ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0692A0ULL;
}

// FDE #0518 | PC: 0x0692b0..0x0692b8 (8 B) | Symbol: _ZNSt6__ndk16localeD1Ev
// EN: AArch64 prologue [ldr x0, [x0]; b #0x48020] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0]; b #0x48020]
uint64_t fde_sub_0692b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF7B5BULL) << 32) | 0xF9400000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0692B0ULL;
}

// FDE #0519 | PC: 0x0692b8..0x0692f8 (64 B) | Symbol: _ZNSt6__ndk16localeaSERKS0_
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x1]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x1]]
uint64_t fde_sub_0692b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0692B8ULL;
}

// FDE #0520 | PC: 0x0692f8..0x0693cc (212 B) | Symbol: _ZNSt6__ndk16localeC1EPKc
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_0692f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90257F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0692F8ULL;
}

// FDE #0521 | PC: 0x0693cc..0x069428 (92 B) | Symbol: _ZNSt6__ndk16localeC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0693cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0693CCULL;
}

// FDE #0522 | PC: 0x069428..0x069514 (236 B) | Symbol: _ZNSt6__ndk16localeC1ERKS0_PKci
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_069428(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9025FF8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069428ULL;
}

// FDE #0523 | PC: 0x069514..0x06957c (104 B) | Symbol: _ZNSt6__ndk16localeC1ERKS0_RKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEi
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_069514(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069514ULL;
}

// FDE #0524 | PC: 0x06957c..0x0695e4 (104 B) | Symbol: _ZNSt6__ndk16localeC1ERKS0_S2_i
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06957c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06957CULL;
}

// FDE #0525 | PC: 0x0695e4..0x0695f4 (16 B) | Symbol: _ZNKSt6__ndk16locale4nameEv
// EN: AArch64 prologue [ldr x9, [x0]; mov x0, x8; add x1, x9, #0x120; b #0x48580] | VI: Khởi đầu hàm AArch64 [ldr x9, [x0]; mov x0, x8; add x1, x9, #0x120; b #0x48580]
uint64_t fde_sub_0695e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0xF9400009ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0695E4ULL;
}

// FDE #0526 | PC: 0x0695f4..0x069668 (116 B) | Symbol: _ZNSt6__ndk16locale14__install_ctorERKS0_PNS0_5facetEl
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0695f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0695F4ULL;
}

// FDE #0527 | PC: 0x069668..0x0697d8 (368 B) | Symbol: _ZNSt6__ndk16locale6globalERKS0_
// EN: AArch64 prologue [sub sp, sp, #0x60; str x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_069668(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069668ULL;
}

// FDE #0528 | PC: 0x0697d8..0x069898 (192 B) | Symbol: _ZNKSt6__ndk16locale9has_facetERNS0_2idE
// EN: AArch64 prologue [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_0697d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF5ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0697D8ULL;
}

// FDE #0529 | PC: 0x069898..0x069928 (144 B) | Symbol: _ZNSt6__ndk16locale2id5__getEv
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]; add x29, sp, #0x40] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]; add x29, sp, #0x40]
uint64_t fde_sub_069898(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9034FF4ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069898ULL;
}

// FDE #0530 | PC: 0x069928..0x0699e0 (184 B) | Symbol: _ZNKSt6__ndk16locale9use_facetERNS0_2idE
// EN: AArch64 prologue [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_069928(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF5ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069928ULL;
}

// FDE #0531 | PC: 0x0699e0..0x069af4 (276 B) | Symbol: _ZNKSt6__ndk16localeeqERKS0_
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x9, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x9, [x0]]
uint64_t fde_sub_0699e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0699E0ULL;
}

// FDE #0532 | PC: 0x069af4..0x069b18 (36 B) | Symbol: _ZNSt6__ndk16locale5facetD0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_069af4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069AF4ULL;
}

// FDE #0533 | PC: 0x069b18..0x069b2c (20 B) | Symbol: _ZNSt6__ndk16locale5facet16__on_zero_sharedEv
// EN: AArch64 prologue [cbz x0, #0x69b28; ldr x8, [x0]; ldr x1, [x8, #8]; br x1] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x69b28; ldr x8, [x0]; ldr x1, [x8, #8]; br x1]
uint64_t fde_sub_069b18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xB4000080ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069B18ULL;
}

// FDE #0534 | PC: 0x069b2c..0x069b4c (32 B) | Symbol: _ZNSt6__ndk16locale2id6__initEv
// EN: AArch64 prologue [adrp x8, #0xe3000; ldr x8, [x8, #0xf68]; ldaxr w9, [x8]; add w9, w9, #1] | VI: Khởi đầu hàm AArch64 [adrp x8, #0xe3000; ldr x8, [x8, #0xf68]; ldaxr w9, [x8]; add w9, w9, #1]
uint64_t fde_sub_069b2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF947B508ULL) << 32) | 0xD00003C8ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069B2CULL;
}

// FDE #0535 | PC: 0x069b4c..0x069c54 (264 B) | Symbol: _ZNSt6__ndk114collate_bynameIcEC1EPKcm
// EN: AArch64 prologue [sub sp, sp, #0x70; str x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_069b4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F5ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0108ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069B4CULL;
}

// FDE #0536 | PC: 0x069c54..0x069ca4 (80 B) | Symbol: sub_069c54
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x20, x0]
uint64_t fde_sub_069c54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069C54ULL;
}

// FDE #0537 | PC: 0x069ca4..0x069d78 (212 B) | Symbol: _ZNSt6__ndk114collate_bynameIcEC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEm
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_069ca4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069CA4ULL;
}

// FDE #0538 | PC: 0x069d78..0x069dc4 (76 B) | Symbol: _ZNSt6__ndk114collate_bynameIcED1Ev
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_069d78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069D78ULL;
}

// FDE #0539 | PC: 0x069dc4..0x069e18 (84 B) | Symbol: _ZNSt6__ndk114collate_bynameIcED0Ev
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_069dc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069DC4ULL;
}

// FDE #0540 | PC: 0x069e18..0x06a070 (600 B) | Symbol: _ZNKSt6__ndk114collate_bynameIcE10do_compareEPKcS3_S3_S3_
// EN: AArch64 prologue [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]]
uint64_t fde_sub_069e18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F9ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0258ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069E18ULL;
}

// FDE #0541 | PC: 0x06a070..0x06a274 (516 B) | Symbol: _ZNKSt6__ndk114collate_bynameIcE12do_transformEPKcS3_
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_06a070(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9025FF8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0204ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A070ULL;
}

// FDE #0542 | PC: 0x06a274..0x06a37c (264 B) | Symbol: _ZNSt6__ndk114collate_bynameIwEC2EPKcm
// EN: AArch64 prologue [sub sp, sp, #0x70; str x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_06a274(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F5ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0108ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A274ULL;
}

// FDE #0543 | PC: 0x06a37c..0x06a450 (212 B) | Symbol: _ZNSt6__ndk114collate_bynameIwEC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEm
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_06a37c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A37CULL;
}

// FDE #0544 | PC: 0x06a450..0x06a49c (76 B) | Symbol: _ZNSt6__ndk114collate_bynameIwED2Ev
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_06a450(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A450ULL;
}

// FDE #0545 | PC: 0x06a49c..0x06a4f0 (84 B) | Symbol: _ZNSt6__ndk114collate_bynameIwED0Ev
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_06a49c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A49CULL;
}

// FDE #0546 | PC: 0x06a4f0..0x06a7b0 (704 B) | Symbol: _ZNKSt6__ndk114collate_bynameIwE10do_compareEPKwS3_S3_S3_
// EN: AArch64 prologue [sub sp, sp, #0xa0; str x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; str x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]]
uint64_t fde_sub_06a4f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023FBULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x02C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A4F0ULL;
}

// FDE #0547 | PC: 0x06a7b0..0x06aa38 (648 B) | Symbol: _ZNKSt6__ndk114collate_bynameIwE12do_transformEPKwS3_
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_06a7b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90267FAULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0288ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A7B0ULL;
}

// FDE #0548 | PC: 0x06aa38..0x06aa5c (36 B) | Symbol: _ZNSt6__ndk15ctypeIwED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_06aa38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AA38ULL;
}

// FDE #0549 | PC: 0x06aa5c..0x06aa84 (40 B) | Symbol: _ZNKSt6__ndk15ctypeIwE5do_isEmw
// EN: AArch64 prologue [cmp w2, #0x7f; b.hi #0x6aa7c; adrp x8, #0xb6000; add x8, x8, #0xfc8] | VI: Khởi đầu hàm AArch64 [cmp w2, #0x7f; b.hi #0x6aa7c; adrp x8, #0xb6000; add x8, x8, #0xfc8]
uint64_t fde_sub_06aa5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x540000E8ULL) << 32) | 0x7101FC5FULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AA5CULL;
}

// FDE #0550 | PC: 0x06aa84..0x06aa90 (12 B) | Symbol: _ZNSt6__ndk15ctypeIcE13classic_tableEv
// EN: AArch64 prologue [adrp x0, #0xb6000; add x0, x0, #0xfc8; ret] | VI: Khởi đầu hàm AArch64 [adrp x0, #0xb6000; add x0, x0, #0xfc8; ret]
uint64_t fde_sub_06aa84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x913F2000ULL) << 32) | 0x90000260ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AA84ULL;
}

// FDE #0551 | PC: 0x06aa90..0x06aad8 (72 B) | Symbol: _ZNKSt6__ndk15ctypeIwE5do_isEPKwS3_Pm
// EN: AArch64 prologue [mov x0, x1; cmp x1, x2; b.eq #0x6aad4; adrp x8, #0xb6000] | VI: Khởi đầu hàm AArch64 [mov x0, x1; cmp x1, x2; b.eq #0x6aad4; adrp x8, #0xb6000]
uint64_t fde_sub_06aa90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB02003FULL) << 32) | 0xAA0103E0ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AA90ULL;
}

// FDE #0552 | PC: 0x06aad8..0x06ab20 (72 B) | Symbol: _ZNKSt6__ndk15ctypeIwE10do_scan_isEmPKwS3_
// EN: AArch64 prologue [mov x0, x2; cmp x2, x3; b.eq #0x6ab14; adrp x8, #0xb6000] | VI: Khởi đầu hàm AArch64 [mov x0, x2; cmp x2, x3; b.eq #0x6ab14; adrp x8, #0xb6000]
uint64_t fde_sub_06aad8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB03005FULL) << 32) | 0xAA0203E0ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AAD8ULL;
}

// FDE #0553 | PC: 0x06ab20..0x06ab60 (64 B) | Symbol: _ZNKSt6__ndk15ctypeIwE11do_scan_notEmPKwS3_
// EN: AArch64 prologue [mov x0, x2; cmp x2, x3; b.eq #0x6ab5c; adrp x8, #0xb6000] | VI: Khởi đầu hàm AArch64 [mov x0, x2; cmp x2, x3; b.eq #0x6ab5c; adrp x8, #0xb6000]
uint64_t fde_sub_06ab20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB03005FULL) << 32) | 0xAA0203E0ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AB20ULL;
}

// FDE #0554 | PC: 0x06ab60..0x06ac04 (164 B) | Symbol: _ZNKSt6__ndk15ctypeIwE10do_toupperEw
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w19, w1] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w19, w1]
uint64_t fde_sub_06ab60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AB60ULL;
}

// FDE #0555 | PC: 0x06ac04..0x06acd8 (212 B) | Symbol: _ZNKSt6__ndk15ctypeIwE10do_toupperEPwPKw
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06ac04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AC04ULL;
}

// FDE #0556 | PC: 0x06acd8..0x06ad7c (164 B) | Symbol: _ZNKSt6__ndk15ctypeIwE10do_tolowerEw
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w19, w1] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w19, w1]
uint64_t fde_sub_06acd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06ACD8ULL;
}

// FDE #0557 | PC: 0x06ad7c..0x06ae50 (212 B) | Symbol: _ZNKSt6__ndk15ctypeIwE10do_tolowerEPwPKw
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06ad7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AD7CULL;
}

// FDE #0558 | PC: 0x06ae50..0x06ae58 (8 B) | Symbol: _ZNKSt6__ndk15ctypeIwE8do_widenEc
// EN: AArch64 prologue [and w0, w1, #0xff; ret] | VI: Khởi đầu hàm AArch64 [and w0, w1, #0xff; ret]
uint64_t fde_sub_06ae50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x12001C20ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AE50ULL;
}

// FDE #0559 | PC: 0x06ae58..0x06ae7c (36 B) | Symbol: _ZNKSt6__ndk15ctypeIwE8do_widenEPKcS3_Pw
// EN: AArch64 prologue [mov x0, x1; cmp x1, x2; b.eq #0x6ae78; ldrb w8, [x0], #1] | VI: Khởi đầu hàm AArch64 [mov x0, x1; cmp x1, x2; b.eq #0x6ae78; ldrb w8, [x0], #1]
uint64_t fde_sub_06ae58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB02003FULL) << 32) | 0xAA0103E0ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AE58ULL;
}

// FDE #0560 | PC: 0x06ae7c..0x06ae88 (12 B) | Symbol: _ZNKSt6__ndk15ctypeIwE9do_narrowEwc
// EN: AArch64 prologue [cmp w1, #0x80; csel w0, w1, w2, lo; ret] | VI: Khởi đầu hàm AArch64 [cmp w1, #0x80; csel w0, w1, w2, lo; ret]
uint64_t fde_sub_06ae7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1A823020ULL) << 32) | 0x7102003FULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AE7CULL;
}

// FDE #0561 | PC: 0x06ae88..0x06af60 (216 B) | Symbol: _ZNKSt6__ndk15ctypeIwE9do_narrowEPKwS3_cPc
// EN: AArch64 prologue [mov x0, x1; cmp x1, x2; b.eq #0x6af5c; sub x8, x2, x0] | VI: Khởi đầu hàm AArch64 [mov x0, x1; cmp x1, x2; b.eq #0x6af5c; sub x8, x2, x0]
uint64_t fde_sub_06ae88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB02003FULL) << 32) | 0xAA0103E0ULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AE88ULL;
}

// FDE #0562 | PC: 0x06af60..0x06af98 (56 B) | Symbol: _ZNSt6__ndk15ctypeIcEC1EPKmbm
// EN: AArch64 prologue [adrp x10, #0xe3000; ldr x10, [x10, #0xd70]; and w8, w2, #1; sub x9, x3, #1] | VI: Khởi đầu hàm AArch64 [adrp x10, #0xe3000; ldr x10, [x10, #0xd70]; and w8, w2, #1; sub x9, x3, #1]
uint64_t fde_sub_06af60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF946B94AULL) << 32) | 0xB00003CAULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AF60ULL;
}

// FDE #0563 | PC: 0x06af98..0x06afdc (68 B) | Symbol: _ZNSt6__ndk15ctypeIcED1Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_06af98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AF98ULL;
}

// FDE #0564 | PC: 0x06afdc..0x06b028 (76 B) | Symbol: _ZNSt6__ndk15ctypeIcED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_06afdc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AFDCULL;
}

// FDE #0565 | PC: 0x06b028..0x06b0cc (164 B) | Symbol: _ZNKSt6__ndk15ctypeIcE10do_toupperEc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w19, w1] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w19, w1]
uint64_t fde_sub_06b028(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B028ULL;
}

// FDE #0566 | PC: 0x06b0cc..0x06b1a4 (216 B) | Symbol: _ZNKSt6__ndk15ctypeIcE10do_toupperEPcPKc
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06b0cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B0CCULL;
}

// FDE #0567 | PC: 0x06b1a4..0x06b248 (164 B) | Symbol: _ZNKSt6__ndk15ctypeIcE10do_tolowerEc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w19, w1] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w19, w1]
uint64_t fde_sub_06b1a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B1A4ULL;
}

// FDE #0568 | PC: 0x06b248..0x06b320 (216 B) | Symbol: _ZNKSt6__ndk15ctypeIcE10do_tolowerEPcPKc
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06b248(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B248ULL;
}

// FDE #0569 | PC: 0x06b320..0x06b328 (8 B) | Symbol: _ZNKSt6__ndk15ctypeIcE8do_widenEc
// EN: AArch64 prologue [mov w0, w1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, w1; ret]
uint64_t fde_sub_06b320(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A0103E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B320ULL;
}

// FDE #0570 | PC: 0x06b328..0x06b3b4 (140 B) | Symbol: _ZNKSt6__ndk15ctypeIcE8do_widenEPKcS3_Pc
// EN: AArch64 prologue [mov x0, x1; cmp x1, x2; b.eq #0x6b3b0; sub x9, x2, x0] | VI: Khởi đầu hàm AArch64 [mov x0, x1; cmp x1, x2; b.eq #0x6b3b0; sub x9, x2, x0]
uint64_t fde_sub_06b328(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB02003FULL) << 32) | 0xAA0103E0ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B328ULL;
}

// FDE #0571 | PC: 0x06b3b4..0x06b3c4 (16 B) | Symbol: _ZNKSt6__ndk15ctypeIcE9do_narrowEcc
// EN: AArch64 prologue [sxtb w8, w1; cmp w8, #0; csel w0, w1, w2, ge; ret] | VI: Khởi đầu hàm AArch64 [sxtb w8, w1; cmp w8, #0; csel w0, w1, w2, ge; ret]
uint64_t fde_sub_06b3b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100011FULL) << 32) | 0x13001C28ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B3B4ULL;
}

// FDE #0572 | PC: 0x06b3c4..0x06b454 (144 B) | Symbol: _ZNKSt6__ndk15ctypeIcE9do_narrowEPKcS3_cPc
// EN: AArch64 prologue [mov x0, x1; cmp x1, x2; b.eq #0x6b414; sub x10, x2, x0] | VI: Khởi đầu hàm AArch64 [mov x0, x1; cmp x1, x2; b.eq #0x6b414; sub x10, x2, x0]
uint64_t fde_sub_06b3c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB02003FULL) << 32) | 0xAA0103E0ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B3C4ULL;
}

// FDE #0573 | PC: 0x06b454..0x06b590 (316 B) | Symbol: _ZNSt6__ndk112ctype_bynameIcEC2EPKcm
// EN: AArch64 prologue [sub sp, sp, #0x70; str x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_06b454(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F5ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x013CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B454ULL;
}

// FDE #0574 | PC: 0x06b590..0x06b698 (264 B) | Symbol: _ZNSt6__ndk112ctype_bynameIcEC2ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEm
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_06b590(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0108ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B590ULL;
}

// FDE #0575 | PC: 0x06b698..0x06b710 (120 B) | Symbol: _ZNSt6__ndk112ctype_bynameIcED0Ev
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_06b698(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B698ULL;
}

// FDE #0576 | PC: 0x06b710..0x06b728 (24 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIcE10do_toupperEc
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; and w0, w1, #0xff; bl #0x47790] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; and w0, w1, #0xff; bl #0x47790]
uint64_t fde_sub_06b710(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B710ULL;
}

// FDE #0577 | PC: 0x06b728..0x06b76c (68 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIcE10do_toupperEPcPKc
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1]
uint64_t fde_sub_06b728(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B728ULL;
}

// FDE #0578 | PC: 0x06b76c..0x06b784 (24 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIcE10do_tolowerEc
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; and w0, w1, #0xff; bl #0x47db0] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; and w0, w1, #0xff; bl #0x47db0]
uint64_t fde_sub_06b76c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B76CULL;
}

// FDE #0579 | PC: 0x06b784..0x06b7c8 (68 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIcE10do_tolowerEPcPKc
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1]
uint64_t fde_sub_06b784(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B784ULL;
}

// FDE #0580 | PC: 0x06b7c8..0x06b8d0 (264 B) | Symbol: _ZNSt6__ndk112ctype_bynameIwEC1EPKcm
// EN: AArch64 prologue [sub sp, sp, #0x70; str x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_06b7c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F5ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0108ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B7C8ULL;
}

// FDE #0581 | PC: 0x06b8d0..0x06b9a4 (212 B) | Symbol: _ZNSt6__ndk112ctype_bynameIwEC2ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEm
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_06b8d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B8D0ULL;
}

// FDE #0582 | PC: 0x06b9a4..0x06b9f8 (84 B) | Symbol: _ZNSt6__ndk112ctype_bynameIwED0Ev
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_06b9a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B9A4ULL;
}

// FDE #0583 | PC: 0x06b9f8..0x06bb3c (324 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIwE5do_isEmw
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06b9f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0144ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B9F8ULL;
}

// FDE #0584 | PC: 0x06bb3c..0x06bca4 (360 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIwE5do_isEPKwS3_Pm
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06bb3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0168ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BB3CULL;
}

// FDE #0585 | PC: 0x06bca4..0x06bda0 (252 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIwE10do_scan_isEmPKwS3_
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06bca4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BCA4ULL;
}

// FDE #0586 | PC: 0x06bda0..0x06be98 (248 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIwE11do_scan_notEmPKwS3_
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06bda0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BDA0ULL;
}

// FDE #0587 | PC: 0x06be98..0x06bea0 (8 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIwE10do_toupperEw
// EN: AArch64 prologue [mov w0, w1; b #0x481c0] | VI: Khởi đầu hàm AArch64 [mov w0, w1; b #0x481c0]
uint64_t fde_sub_06be98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF70C9ULL) << 32) | 0x2A0103E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BE98ULL;
}

// FDE #0588 | PC: 0x06bea0..0x06bee4 (68 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIwE10do_toupperEPwPKw
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1]
uint64_t fde_sub_06bea0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BEA0ULL;
}

// FDE #0589 | PC: 0x06bee4..0x06beec (8 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIwE10do_tolowerEw
// EN: AArch64 prologue [mov w0, w1; b #0x48660] | VI: Khởi đầu hàm AArch64 [mov w0, w1; b #0x48660]
uint64_t fde_sub_06bee4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF71DEULL) << 32) | 0x2A0103E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BEE4ULL;
}

// FDE #0590 | PC: 0x06beec..0x06bf30 (68 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIwE10do_tolowerEPwPKw
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1]
uint64_t fde_sub_06beec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BEECULL;
}

// FDE #0591 | PC: 0x06bf30..0x06bf94 (100 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIwE8do_widenEc
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x0, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x0, [x0, #0x10]]
uint64_t fde_sub_06bf30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BF30ULL;
}

// FDE #0592 | PC: 0x06bf94..0x06c03c (168 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIwE8do_widenEPKcS3_Pw
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06bf94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BF94ULL;
}

// FDE #0593 | PC: 0x06c03c..0x06c0b0 (116 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIwE9do_narrowEwc
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06c03c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C03CULL;
}

// FDE #0594 | PC: 0x06c0b0..0x06c16c (188 B) | Symbol: _ZNKSt6__ndk112ctype_bynameIwE9do_narrowEPKwS3_cPc
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_06c0b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C0B0ULL;
}

// FDE #0595 | PC: 0x06c16c..0x06c190 (36 B) | Symbol: _ZNSt6__ndk17codecvtIcc9mbstate_tED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_06c16c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C16CULL;
}

// FDE #0596 | PC: 0x06c190..0x06c1a0 (16 B) | Symbol: _ZNKSt6__ndk17codecvtIcc9mbstate_tE6do_outERS1_PKcS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [mov w0, #3; str x2, [x4]; str x5, [x7]; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #3; str x2, [x4]; str x5, [x7]; ret]
uint64_t fde_sub_06c190(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000082ULL) << 32) | 0x52800060ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C190ULL;
}

// FDE #0597 | PC: 0x06c1a0..0x06c1b0 (16 B) | Symbol: _ZNKSt6__ndk17codecvtIcc9mbstate_tE5do_inERS1_PKcS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [mov w0, #3; str x2, [x4]; str x5, [x7]; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #3; str x2, [x4]; str x5, [x7]; ret]
uint64_t fde_sub_06c1a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000082ULL) << 32) | 0x52800060ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C1A0ULL;
}

// FDE #0598 | PC: 0x06c1b0..0x06c1bc (12 B) | Symbol: _ZNKSt6__ndk17codecvtIcc9mbstate_tE10do_unshiftERS1_PcS4_RS4_
// EN: AArch64 prologue [mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_06c1b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000082ULL) << 32) | 0x52800060ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C1B0ULL;
}

// FDE #0599 | PC: 0x06c1bc..0x06c1c4 (8 B) | Symbol: _ZNKSt6__ndk17codecvtIcc9mbstate_tE11do_encodingEv
// EN: AArch64 prologue [mov w0, #1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #1; ret]
uint64_t fde_sub_06c1bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C1BCULL;
}

// FDE #0600 | PC: 0x06c1c4..0x06c1cc (8 B) | Symbol: _ZNKSt6__ndk17codecvtIcc9mbstate_tE16do_always_noconvEv
// EN: AArch64 prologue [mov w0, #1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #1; ret]
uint64_t fde_sub_06c1c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C1C4ULL;
}

// FDE #0601 | PC: 0x06c1cc..0x06c1dc (16 B) | Symbol: _ZNKSt6__ndk17codecvtIcc9mbstate_tE9do_lengthERS1_PKcS5_m
// EN: AArch64 prologue [sub x8, x3, x2; cmp x8, x4; csel w0, w8, w4, lo; ret] | VI: Khởi đầu hàm AArch64 [sub x8, x3, x2; cmp x8, x4; csel w0, w8, w4, lo; ret]
uint64_t fde_sub_06c1cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB04011FULL) << 32) | 0xCB020068ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C1CCULL;
}

// FDE #0602 | PC: 0x06c1dc..0x06c1e4 (8 B) | Symbol: _ZNKSt6__ndk17codecvtIcc9mbstate_tE13do_max_lengthEv
// EN: AArch64 prologue [mov w0, #1; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #1; ret]
uint64_t fde_sub_06c1dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800020ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C1DCULL;
}

// FDE #0603 | PC: 0x06c1e4..0x06c288 (164 B) | Symbol: _ZNSt6__ndk17codecvtIwc9mbstate_tEC2Em
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000]
uint64_t fde_sub_06c1e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C1E4ULL;
}

// FDE #0604 | PC: 0x06c288..0x06c390 (264 B) | Symbol: _ZNSt6__ndk17codecvtIwc9mbstate_tEC2EPKcm
// EN: AArch64 prologue [sub sp, sp, #0x70; str x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_06c288(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F5ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0108ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C288ULL;
}

// FDE #0605 | PC: 0x06c390..0x06c3b4 (36 B) | Symbol: _ZNSt6__ndk17codecvtIwc9mbstate_tED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_06c390(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C390ULL;
}

// FDE #0606 | PC: 0x06c3b4..0x06c6f8 (836 B) | Symbol: _ZNKSt6__ndk17codecvtIwc9mbstate_tE6do_outERS1_PKwS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]]
uint64_t fde_sub_06c3b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9056FFCULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x0344ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C3B4ULL;
}

// FDE #0607 | PC: 0x06c6f8..0x06ca2c (820 B) | Symbol: _ZNKSt6__ndk17codecvtIwc9mbstate_tE5do_inERS1_PKcS5_RS5_PwS7_RS7_
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp x28, x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp x28, x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]]
uint64_t fde_sub_06c6f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9046FFCULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x0334ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C6F8ULL;
}

// FDE #0608 | PC: 0x06ca2c..0x06cb4c (288 B) | Symbol: _ZNKSt6__ndk17codecvtIwc9mbstate_tE10do_unshiftERS1_PcS4_RS4_
// EN: AArch64 prologue [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_06ca2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0120ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06CA2CULL;
}

// FDE #0609 | PC: 0x06cb4c..0x06cc20 (212 B) | Symbol: _ZNKSt6__ndk17codecvtIwc9mbstate_tE11do_encodingEv
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06cb4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06CB4CULL;
}

// FDE #0610 | PC: 0x06cc20..0x06cc28 (8 B) | Symbol: _ZNKSt6__ndk17codecvtIwc9mbstate_tE16do_always_noconvEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06cc20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06CC20ULL;
}

// FDE #0611 | PC: 0x06cc28..0x06cd1c (244 B) | Symbol: _ZNKSt6__ndk17codecvtIwc9mbstate_tE9do_lengthERS1_PKcS5_m
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_06cc28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x00F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06CC28ULL;
}

// FDE #0612 | PC: 0x06cd1c..0x06cd8c (112 B) | Symbol: _ZNKSt6__ndk17codecvtIwc9mbstate_tE13do_max_lengthEv
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x0, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x0, [x0, #0x10]]
uint64_t fde_sub_06cd1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06CD1CULL;
}

// FDE #0613 | PC: 0x06cd8c..0x06cdb0 (36 B) | Symbol: _ZNSt6__ndk17codecvtIDsc9mbstate_tED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_06cd8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06CD8CULL;
}

// FDE #0614 | PC: 0x06cdb0..0x06ce40 (144 B) | Symbol: _ZNKSt6__ndk17codecvtIDsc9mbstate_tE6do_outERS1_PKDsS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_06cdb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06CDB0ULL;
}

// FDE #0615 | PC: 0x06ce40..0x06d080 (576 B) | Symbol: sub_06ce40
// EN: AArch64 prologue [str x0, [x2]; str x3, [x5]; tbz w7, #1, #0x6ce98; sub x8, x4, x3] | VI: Khởi đầu hàm AArch64 [str x0, [x2]; str x3, [x5]; tbz w7, #1, #0x6ce98; sub x8, x4, x3]
uint64_t fde_sub_06ce40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90000A3ULL) << 32) | 0xF9000040ULL;
    const uint64_t kPcRange = 0x0240ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06CE40ULL;
}

// FDE #0616 | PC: 0x06d080..0x06d0e8 (104 B) | Symbol: _ZNKSt6__ndk17codecvtIDsc9mbstate_tE5do_inERS1_PKcS5_RS5_PDsS7_RS7_
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06d080(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D080ULL;
}

// FDE #0617 | PC: 0x06d0e8..0x06d368 (640 B) | Symbol: sub_06d0e8
// EN: AArch64 prologue [str x0, [x2]; str x3, [x5]; ldr x12, [x2]; tbz w7, #2, #0x6d130] | VI: Khởi đầu hàm AArch64 [str x0, [x2]; str x3, [x5]; ldr x12, [x2]; tbz w7, #2, #0x6d130]
uint64_t fde_sub_06d0e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90000A3ULL) << 32) | 0xF9000040ULL;
    const uint64_t kPcRange = 0x0280ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D0E8ULL;
}

// FDE #0618 | PC: 0x06d368..0x06d374 (12 B) | Symbol: _ZNKSt6__ndk17codecvtIDsc9mbstate_tE10do_unshiftERS1_PcS4_RS4_
// EN: AArch64 prologue [mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_06d368(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000082ULL) << 32) | 0x52800060ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D368ULL;
}

// FDE #0619 | PC: 0x06d374..0x06d37c (8 B) | Symbol: _ZNKSt6__ndk17codecvtIDsc9mbstate_tE11do_encodingEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06d374(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D374ULL;
}

// FDE #0620 | PC: 0x06d37c..0x06d384 (8 B) | Symbol: _ZNKSt6__ndk17codecvtIDsc9mbstate_tE16do_always_noconvEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06d37c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D37CULL;
}

// FDE #0621 | PC: 0x06d384..0x06d39c (24 B) | Symbol: _ZNKSt6__ndk17codecvtIDsc9mbstate_tE9do_lengthERS1_PKcS5_m
// EN: AArch64 prologue [mov x1, x3; mov w3, #0x10ffff; mov x0, x2; mov x2, x4] | VI: Khởi đầu hàm AArch64 [mov x1, x3; mov w3, #0x10ffff; mov x0, x2; mov x2, x4]
uint64_t fde_sub_06d384(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12BFFDE3ULL) << 32) | 0xAA0303E1ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D384ULL;
}

// FDE #0622 | PC: 0x06d39c..0x06d5ac (528 B) | Symbol: sub_06d39c
// EN: AArch64 prologue [mov x8, x0; tbz w4, #2, #0x6d3e4; sub x8, x1, x0; cmp x8, #3] | VI: Khởi đầu hàm AArch64 [mov x8, x0; tbz w4, #2, #0x6d3e4; sub x8, x1, x0; cmp x8, #3]
uint64_t fde_sub_06d39c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x36100224ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0210ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D39CULL;
}

// FDE #0623 | PC: 0x06d5ac..0x06d5b4 (8 B) | Symbol: _ZNKSt6__ndk17codecvtIDsc9mbstate_tE13do_max_lengthEv
// EN: AArch64 prologue [mov w0, #4; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #4; ret]
uint64_t fde_sub_06d5ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800080ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D5ACULL;
}

// FDE #0624 | PC: 0x06d5b4..0x06d5d8 (36 B) | Symbol: _ZNSt6__ndk17codecvtIDic9mbstate_tED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_06d5b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D5B4ULL;
}

// FDE #0625 | PC: 0x06d5d8..0x06d6e4 (268 B) | Symbol: _ZNKSt6__ndk17codecvtIDic9mbstate_tE6do_outERS1_PKDiS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [cmp x2, x3; b.hs #0x6d6cc; mov w8, #0xd800; mov w0, #2] | VI: Khởi đầu hàm AArch64 [cmp x2, x3; b.hs #0x6d6cc; mov w8, #0xd800; mov w0, #2]
uint64_t fde_sub_06d5d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000782ULL) << 32) | 0xEB03005FULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D5D8ULL;
}

// FDE #0626 | PC: 0x06d6e4..0x06d874 (400 B) | Symbol: sub_06d6e4
// EN: AArch64 prologue [str x0, [x2]; str x3, [x5]; tbz w7, #1, #0x6d73c; sub x8, x4, x3] | VI: Khởi đầu hàm AArch64 [str x0, [x2]; str x3, [x5]; tbz w7, #1, #0x6d73c; sub x8, x4, x3]
uint64_t fde_sub_06d6e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90000A3ULL) << 32) | 0xF9000040ULL;
    const uint64_t kPcRange = 0x0190ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D6E4ULL;
}

// FDE #0627 | PC: 0x06d874..0x06d8dc (104 B) | Symbol: _ZNKSt6__ndk17codecvtIDic9mbstate_tE5do_inERS1_PKcS5_RS5_PDiS7_RS7_
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06d874(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D874ULL;
}

// FDE #0628 | PC: 0x06d8dc..0x06db14 (568 B) | Symbol: sub_06d8dc
// EN: AArch64 prologue [str x0, [x2]; str x3, [x5]; ldr x8, [x2]; tbz w7, #2, #0x6d924] | VI: Khởi đầu hàm AArch64 [str x0, [x2]; str x3, [x5]; ldr x8, [x2]; tbz w7, #2, #0x6d924]
uint64_t fde_sub_06d8dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90000A3ULL) << 32) | 0xF9000040ULL;
    const uint64_t kPcRange = 0x0238ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D8DCULL;
}

// FDE #0629 | PC: 0x06db14..0x06db20 (12 B) | Symbol: _ZNKSt6__ndk17codecvtIDic9mbstate_tE10do_unshiftERS1_PcS4_RS4_
// EN: AArch64 prologue [mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_06db14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000082ULL) << 32) | 0x52800060ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06DB14ULL;
}

// FDE #0630 | PC: 0x06db20..0x06db28 (8 B) | Symbol: _ZNKSt6__ndk17codecvtIDic9mbstate_tE11do_encodingEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06db20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06DB20ULL;
}

// FDE #0631 | PC: 0x06db28..0x06db30 (8 B) | Symbol: _ZNKSt6__ndk17codecvtIDic9mbstate_tE16do_always_noconvEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06db28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06DB28ULL;
}

// FDE #0632 | PC: 0x06db30..0x06db48 (24 B) | Symbol: _ZNKSt6__ndk17codecvtIDic9mbstate_tE9do_lengthERS1_PKcS5_m
// EN: AArch64 prologue [mov x1, x3; mov w3, #0x10ffff; mov x0, x2; mov x2, x4] | VI: Khởi đầu hàm AArch64 [mov x1, x3; mov w3, #0x10ffff; mov x0, x2; mov x2, x4]
uint64_t fde_sub_06db30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12BFFDE3ULL) << 32) | 0xAA0303E1ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06DB30ULL;
}

// FDE #0633 | PC: 0x06db48..0x06dd64 (540 B) | Symbol: sub_06db48
// EN: AArch64 prologue [mov x8, x0; tbz w4, #2, #0x6db90; sub x8, x1, x0; cmp x8, #3] | VI: Khởi đầu hàm AArch64 [mov x8, x0; tbz w4, #2, #0x6db90; sub x8, x1, x0; cmp x8, #3]
uint64_t fde_sub_06db48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x36100224ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x021CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06DB48ULL;
}

// FDE #0634 | PC: 0x06dd64..0x06dd6c (8 B) | Symbol: _ZNKSt6__ndk17codecvtIDic9mbstate_tE13do_max_lengthEv
// EN: AArch64 prologue [mov w0, #4; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #4; ret]
uint64_t fde_sub_06dd64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800080ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06DD64ULL;
}

// FDE #0635 | PC: 0x06dd6c..0x06de00 (148 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IwE6do_outER9mbstate_tPKwS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_06dd6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06DD6CULL;
}

// FDE #0636 | PC: 0x06de00..0x06de6c (108 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IwE5do_inER9mbstate_tPKcS5_RS5_PwS7_RS7_
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06de00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06DE00ULL;
}

// FDE #0637 | PC: 0x06de6c..0x06de78 (12 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IwE10do_unshiftER9mbstate_tPcS4_RS4_
// EN: AArch64 prologue [mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_06de6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000082ULL) << 32) | 0x52800060ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06DE6CULL;
}

// FDE #0638 | PC: 0x06de78..0x06de80 (8 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IwE11do_encodingEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06de78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06DE78ULL;
}

// FDE #0639 | PC: 0x06de80..0x06de88 (8 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IwE16do_always_noconvEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06de80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06DE80ULL;
}

// FDE #0640 | PC: 0x06de88..0x06dea4 (28 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IwE9do_lengthER9mbstate_tPKcS5_m
// EN: AArch64 prologue [mov x8, x4; mov x1, x3; ldr x3, [x0, #0x18]; ldr w4, [x0, #0x20]] | VI: Khởi đầu hàm AArch64 [mov x8, x4; mov x1, x3; ldr x3, [x0, #0x18]; ldr w4, [x0, #0x20]]
uint64_t fde_sub_06de88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0303E1ULL) << 32) | 0xAA0403E8ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06DE88ULL;
}

// FDE #0641 | PC: 0x06dea4..0x06debc (24 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IwE13do_max_lengthEv
// EN: AArch64 prologue [ldrb w8, [x0, #0x20]; mov w9, #7; tst w8, #4; mov w8, #4] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x20]; mov w9, #7; tst w8, #4; mov w8, #4]
uint64_t fde_sub_06dea4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x528000E9ULL) << 32) | 0x39408008ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06DEA4ULL;
}

// FDE #0642 | PC: 0x06debc..0x06dfb8 (252 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IDsE6do_outER9mbstate_tPKDsS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #1, #0x6deec; sub x9, x6, x5] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #1, #0x6deec; sub x9, x6, x5]
uint64_t fde_sub_06debc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400808ULL) << 32) | 0x39406009ULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06DEBCULL;
}

// FDE #0643 | PC: 0x06dfb8..0x06e120 (360 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IDsE5do_inER9mbstate_tPKcS5_RS5_PDsS7_RS7_
// EN: AArch64 prologue [ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #2, #0x6dff8; sub x9, x3, x2] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #2, #0x6dff8; sub x9, x3, x2]
uint64_t fde_sub_06dfb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400808ULL) << 32) | 0x39406009ULL;
    const uint64_t kPcRange = 0x0168ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06DFB8ULL;
}

// FDE #0644 | PC: 0x06e120..0x06e12c (12 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IDsE10do_unshiftER9mbstate_tPcS4_RS4_
// EN: AArch64 prologue [mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_06e120(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000082ULL) << 32) | 0x52800060ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E120ULL;
}

// FDE #0645 | PC: 0x06e12c..0x06e134 (8 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IDsE11do_encodingEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06e12c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E12CULL;
}

// FDE #0646 | PC: 0x06e134..0x06e13c (8 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IDsE16do_always_noconvEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06e134(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E134ULL;
}

// FDE #0647 | PC: 0x06e13c..0x06e2b4 (376 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IDsE9do_lengthER9mbstate_tPKcS5_m
// EN: AArch64 prologue [ldrb w10, [x0, #0x18]; ldr x9, [x0, #0x10]; mov x8, x2; tbz w10, #2, #0x6e18c] | VI: Khởi đầu hàm AArch64 [ldrb w10, [x0, #0x18]; ldr x9, [x0, #0x10]; mov x8, x2; tbz w10, #2, #0x6e18c]
uint64_t fde_sub_06e13c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400809ULL) << 32) | 0x3940600AULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E13CULL;
}

// FDE #0648 | PC: 0x06e2b4..0x06e2cc (24 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IDsE13do_max_lengthEv
// EN: AArch64 prologue [ldrb w8, [x0, #0x18]; mov w9, #6; tst w8, #4; mov w8, #3] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x18]; mov w9, #6; tst w8, #4; mov w8, #3]
uint64_t fde_sub_06e2b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x528000C9ULL) << 32) | 0x39406008ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E2B4ULL;
}

// FDE #0649 | PC: 0x06e2cc..0x06e360 (148 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IDiE6do_outER9mbstate_tPKDiS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_06e2cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E2CCULL;
}

// FDE #0650 | PC: 0x06e360..0x06e3cc (108 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IDiE5do_inER9mbstate_tPKcS5_RS5_PDiS7_RS7_
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06e360(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E360ULL;
}

// FDE #0651 | PC: 0x06e3cc..0x06e3d8 (12 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IDiE10do_unshiftER9mbstate_tPcS4_RS4_
// EN: AArch64 prologue [mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_06e3cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000082ULL) << 32) | 0x52800060ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E3CCULL;
}

// FDE #0652 | PC: 0x06e3d8..0x06e3e0 (8 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IDiE11do_encodingEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06e3d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E3D8ULL;
}

// FDE #0653 | PC: 0x06e3e0..0x06e3e8 (8 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IDiE16do_always_noconvEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06e3e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E3E0ULL;
}

// FDE #0654 | PC: 0x06e3e8..0x06e404 (28 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IDiE9do_lengthER9mbstate_tPKcS5_m
// EN: AArch64 prologue [mov x8, x4; mov x1, x3; ldr x3, [x0, #0x10]; ldr w4, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [mov x8, x4; mov x1, x3; ldr x3, [x0, #0x10]; ldr w4, [x0, #0x18]]
uint64_t fde_sub_06e3e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0303E1ULL) << 32) | 0xAA0403E8ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E3E8ULL;
}

// FDE #0655 | PC: 0x06e404..0x06e41c (24 B) | Symbol: _ZNKSt6__ndk114__codecvt_utf8IDiE13do_max_lengthEv
// EN: AArch64 prologue [ldrb w8, [x0, #0x18]; mov w9, #7; tst w8, #4; mov w8, #4] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x18]; mov w9, #7; tst w8, #4; mov w8, #4]
uint64_t fde_sub_06e404(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x528000E9ULL) << 32) | 0x39406008ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E404ULL;
}

// FDE #0656 | PC: 0x06e41c..0x06e4fc (224 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IwLb0EE6do_outER9mbstate_tPKwS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [ldrb w9, [x0, #0x20]; ldr x8, [x0, #0x18]; tbz w9, #1, #0x6e43c; sub x9, x6, x5] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x0, #0x20]; ldr x8, [x0, #0x18]; tbz w9, #1, #0x6e43c; sub x9, x6, x5]
uint64_t fde_sub_06e41c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400C08ULL) << 32) | 0x39408009ULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E41CULL;
}

// FDE #0657 | PC: 0x06e4fc..0x06e60c (272 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IwLb0EE5do_inER9mbstate_tPKcS5_RS5_PwS7_RS7_
// EN: AArch64 prologue [ldrb w9, [x0, #0x20]; ldr x8, [x0, #0x18]; tbz w9, #2, #0x6e530; sub x9, x3, x2] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x0, #0x20]; ldr x8, [x0, #0x18]; tbz w9, #2, #0x6e530; sub x9, x3, x2]
uint64_t fde_sub_06e4fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400C08ULL) << 32) | 0x39408009ULL;
    const uint64_t kPcRange = 0x0110ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E4FCULL;
}

// FDE #0658 | PC: 0x06e60c..0x06e618 (12 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IwLb0EE10do_unshiftER9mbstate_tPcS4_RS4_
// EN: AArch64 prologue [mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_06e60c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000082ULL) << 32) | 0x52800060ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E60CULL;
}

// FDE #0659 | PC: 0x06e618..0x06e620 (8 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IwLb0EE11do_encodingEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06e618(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E618ULL;
}

// FDE #0660 | PC: 0x06e620..0x06e628 (8 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IwLb0EE16do_always_noconvEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06e620(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E620ULL;
}

// FDE #0661 | PC: 0x06e628..0x06e724 (252 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IwLb0EE9do_lengthER9mbstate_tPKcS5_m
// EN: AArch64 prologue [ldrb w10, [x0, #0x20]; ldr x9, [x0, #0x18]; mov x8, x2; tbz w10, #2, #0x6e668] | VI: Khởi đầu hàm AArch64 [ldrb w10, [x0, #0x20]; ldr x9, [x0, #0x18]; mov x8, x2; tbz w10, #2, #0x6e668]
uint64_t fde_sub_06e628(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400C09ULL) << 32) | 0x3940800AULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E628ULL;
}

// FDE #0662 | PC: 0x06e724..0x06e73c (24 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IwLb0EE13do_max_lengthEv
// EN: AArch64 prologue [ldrb w8, [x0, #0x20]; mov w9, #6; tst w8, #4; mov w8, #4] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x20]; mov w9, #6; tst w8, #4; mov w8, #4]
uint64_t fde_sub_06e724(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x528000C9ULL) << 32) | 0x39408008ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E724ULL;
}

// FDE #0663 | PC: 0x06e73c..0x06e80c (208 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IwLb1EE6do_outER9mbstate_tPKwS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [ldrb w9, [x0, #0x20]; ldr x8, [x0, #0x18]; tbz w9, #1, #0x6e75c; sub x9, x6, x5] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x0, #0x20]; ldr x8, [x0, #0x18]; tbz w9, #1, #0x6e75c; sub x9, x6, x5]
uint64_t fde_sub_06e73c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400C08ULL) << 32) | 0x39408009ULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E73CULL;
}

// FDE #0664 | PC: 0x06e80c..0x06e91c (272 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IwLb1EE5do_inER9mbstate_tPKcS5_RS5_PwS7_RS7_
// EN: AArch64 prologue [ldrb w9, [x0, #0x20]; ldr x8, [x0, #0x18]; tbz w9, #2, #0x6e840; sub x9, x3, x2] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x0, #0x20]; ldr x8, [x0, #0x18]; tbz w9, #2, #0x6e840; sub x9, x3, x2]
uint64_t fde_sub_06e80c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400C08ULL) << 32) | 0x39408009ULL;
    const uint64_t kPcRange = 0x0110ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E80CULL;
}

// FDE #0665 | PC: 0x06e91c..0x06e928 (12 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IwLb1EE10do_unshiftER9mbstate_tPcS4_RS4_
// EN: AArch64 prologue [mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_06e91c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000082ULL) << 32) | 0x52800060ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E91CULL;
}

// FDE #0666 | PC: 0x06e928..0x06e930 (8 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IwLb1EE11do_encodingEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06e928(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E928ULL;
}

// FDE #0667 | PC: 0x06e930..0x06e938 (8 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IwLb1EE16do_always_noconvEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06e930(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E930ULL;
}

// FDE #0668 | PC: 0x06e938..0x06ea34 (252 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IwLb1EE9do_lengthER9mbstate_tPKcS5_m
// EN: AArch64 prologue [ldrb w10, [x0, #0x20]; ldr x9, [x0, #0x18]; mov x8, x2; tbz w10, #2, #0x6e978] | VI: Khởi đầu hàm AArch64 [ldrb w10, [x0, #0x20]; ldr x9, [x0, #0x18]; mov x8, x2; tbz w10, #2, #0x6e978]
uint64_t fde_sub_06e938(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400C09ULL) << 32) | 0x3940800AULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06E938ULL;
}

// FDE #0669 | PC: 0x06ea34..0x06ea4c (24 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IwLb1EE13do_max_lengthEv
// EN: AArch64 prologue [ldrb w8, [x0, #0x20]; mov w9, #6; tst w8, #4; mov w8, #4] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x20]; mov w9, #6; tst w8, #4; mov w8, #4]
uint64_t fde_sub_06ea34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x528000C9ULL) << 32) | 0x39408008ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EA34ULL;
}

// FDE #0670 | PC: 0x06ea4c..0x06eac8 (124 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDsLb0EE6do_outER9mbstate_tPKDsS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #1, #0x6ea6c; sub x9, x6, x5] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #1, #0x6ea6c; sub x9, x6, x5]
uint64_t fde_sub_06ea4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400808ULL) << 32) | 0x39406009ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EA4CULL;
}

// FDE #0671 | PC: 0x06eac8..0x06eb58 (144 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDsLb0EE5do_inER9mbstate_tPKcS5_RS5_PDsS7_RS7_
// EN: AArch64 prologue [ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #2, #0x6eafc; sub x9, x3, x2] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #2, #0x6eafc; sub x9, x3, x2]
uint64_t fde_sub_06eac8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400808ULL) << 32) | 0x39406009ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EAC8ULL;
}

// FDE #0672 | PC: 0x06eb58..0x06eb64 (12 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDsLb0EE10do_unshiftER9mbstate_tPcS4_RS4_
// EN: AArch64 prologue [mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_06eb58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000082ULL) << 32) | 0x52800060ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EB58ULL;
}

// FDE #0673 | PC: 0x06eb64..0x06eb6c (8 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDsLb0EE11do_encodingEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06eb64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EB64ULL;
}

// FDE #0674 | PC: 0x06eb6c..0x06eb74 (8 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDsLb0EE16do_always_noconvEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06eb6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EB6CULL;
}

// FDE #0675 | PC: 0x06eb74..0x06ec08 (148 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDsLb0EE9do_lengthER9mbstate_tPKcS5_m
// EN: AArch64 prologue [ldrb w10, [x0, #0x18]; ldr x9, [x0, #0x10]; mov x8, x2; tbz w10, #2, #0x6ebb4] | VI: Khởi đầu hàm AArch64 [ldrb w10, [x0, #0x18]; ldr x9, [x0, #0x10]; mov x8, x2; tbz w10, #2, #0x6ebb4]
uint64_t fde_sub_06eb74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400809ULL) << 32) | 0x3940600AULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EB74ULL;
}

// FDE #0676 | PC: 0x06ec08..0x06ec20 (24 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDsLb0EE13do_max_lengthEv
// EN: AArch64 prologue [ldrb w8, [x0, #0x18]; mov w9, #4; tst w8, #4; mov w8, #2] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x18]; mov w9, #4; tst w8, #4; mov w8, #2]
uint64_t fde_sub_06ec08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800089ULL) << 32) | 0x39406008ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EC08ULL;
}

// FDE #0677 | PC: 0x06ec20..0x06ec98 (120 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDsLb1EE6do_outER9mbstate_tPKDsS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #1, #0x6ec40; sub x9, x6, x5] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #1, #0x6ec40; sub x9, x6, x5]
uint64_t fde_sub_06ec20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400808ULL) << 32) | 0x39406009ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EC20ULL;
}

// FDE #0678 | PC: 0x06ec98..0x06ed28 (144 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDsLb1EE5do_inER9mbstate_tPKcS5_RS5_PDsS7_RS7_
// EN: AArch64 prologue [ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #2, #0x6eccc; sub x9, x3, x2] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #2, #0x6eccc; sub x9, x3, x2]
uint64_t fde_sub_06ec98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400808ULL) << 32) | 0x39406009ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EC98ULL;
}

// FDE #0679 | PC: 0x06ed28..0x06ed34 (12 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDsLb1EE10do_unshiftER9mbstate_tPcS4_RS4_
// EN: AArch64 prologue [mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_06ed28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000082ULL) << 32) | 0x52800060ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06ED28ULL;
}

// FDE #0680 | PC: 0x06ed34..0x06ed3c (8 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDsLb1EE11do_encodingEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06ed34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06ED34ULL;
}

// FDE #0681 | PC: 0x06ed3c..0x06ed44 (8 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDsLb1EE16do_always_noconvEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06ed3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06ED3CULL;
}

// FDE #0682 | PC: 0x06ed44..0x06edf0 (172 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDsLb1EE9do_lengthER9mbstate_tPKcS5_m
// EN: AArch64 prologue [ldrb w10, [x0, #0x18]; ldr x8, [x0, #0x10]; mov x9, x2; tbz w10, #2, #0x6ed74] | VI: Khởi đầu hàm AArch64 [ldrb w10, [x0, #0x18]; ldr x8, [x0, #0x10]; mov x9, x2; tbz w10, #2, #0x6ed74]
uint64_t fde_sub_06ed44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400808ULL) << 32) | 0x3940600AULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06ED44ULL;
}

// FDE #0683 | PC: 0x06edf0..0x06ee08 (24 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDsLb1EE13do_max_lengthEv
// EN: AArch64 prologue [ldrb w8, [x0, #0x18]; mov w9, #4; tst w8, #4; mov w8, #2] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x18]; mov w9, #4; tst w8, #4; mov w8, #2]
uint64_t fde_sub_06edf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800089ULL) << 32) | 0x39406008ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EDF0ULL;
}

// FDE #0684 | PC: 0x06ee08..0x06eee8 (224 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDiLb0EE6do_outER9mbstate_tPKDiS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #1, #0x6ee28; sub x9, x6, x5] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #1, #0x6ee28; sub x9, x6, x5]
uint64_t fde_sub_06ee08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400808ULL) << 32) | 0x39406009ULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EE08ULL;
}

// FDE #0685 | PC: 0x06eee8..0x06eff8 (272 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDiLb0EE5do_inER9mbstate_tPKcS5_RS5_PDiS7_RS7_
// EN: AArch64 prologue [ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #2, #0x6ef1c; sub x9, x3, x2] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #2, #0x6ef1c; sub x9, x3, x2]
uint64_t fde_sub_06eee8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400808ULL) << 32) | 0x39406009ULL;
    const uint64_t kPcRange = 0x0110ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EEE8ULL;
}

// FDE #0686 | PC: 0x06eff8..0x06f004 (12 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDiLb0EE10do_unshiftER9mbstate_tPcS4_RS4_
// EN: AArch64 prologue [mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_06eff8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000082ULL) << 32) | 0x52800060ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06EFF8ULL;
}

// FDE #0687 | PC: 0x06f004..0x06f00c (8 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDiLb0EE11do_encodingEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06f004(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F004ULL;
}

// FDE #0688 | PC: 0x06f00c..0x06f014 (8 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDiLb0EE16do_always_noconvEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06f00c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F00CULL;
}

// FDE #0689 | PC: 0x06f014..0x06f110 (252 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDiLb0EE9do_lengthER9mbstate_tPKcS5_m
// EN: AArch64 prologue [ldrb w10, [x0, #0x18]; ldr x9, [x0, #0x10]; mov x8, x2; tbz w10, #2, #0x6f054] | VI: Khởi đầu hàm AArch64 [ldrb w10, [x0, #0x18]; ldr x9, [x0, #0x10]; mov x8, x2; tbz w10, #2, #0x6f054]
uint64_t fde_sub_06f014(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400809ULL) << 32) | 0x3940600AULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F014ULL;
}

// FDE #0690 | PC: 0x06f110..0x06f128 (24 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDiLb0EE13do_max_lengthEv
// EN: AArch64 prologue [ldrb w8, [x0, #0x18]; mov w9, #6; tst w8, #4; mov w8, #4] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x18]; mov w9, #6; tst w8, #4; mov w8, #4]
uint64_t fde_sub_06f110(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x528000C9ULL) << 32) | 0x39406008ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F110ULL;
}

// FDE #0691 | PC: 0x06f128..0x06f1f8 (208 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDiLb1EE6do_outER9mbstate_tPKDiS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #1, #0x6f148; sub x9, x6, x5] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #1, #0x6f148; sub x9, x6, x5]
uint64_t fde_sub_06f128(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400808ULL) << 32) | 0x39406009ULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F128ULL;
}

// FDE #0692 | PC: 0x06f1f8..0x06f308 (272 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDiLb1EE5do_inER9mbstate_tPKcS5_RS5_PDiS7_RS7_
// EN: AArch64 prologue [ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #2, #0x6f22c; sub x9, x3, x2] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x0, #0x18]; ldr x8, [x0, #0x10]; tbz w9, #2, #0x6f22c; sub x9, x3, x2]
uint64_t fde_sub_06f1f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400808ULL) << 32) | 0x39406009ULL;
    const uint64_t kPcRange = 0x0110ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F1F8ULL;
}

// FDE #0693 | PC: 0x06f308..0x06f314 (12 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDiLb1EE10do_unshiftER9mbstate_tPcS4_RS4_
// EN: AArch64 prologue [mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_06f308(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000082ULL) << 32) | 0x52800060ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F308ULL;
}

// FDE #0694 | PC: 0x06f314..0x06f31c (8 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDiLb1EE11do_encodingEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06f314(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F314ULL;
}

// FDE #0695 | PC: 0x06f31c..0x06f324 (8 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDiLb1EE16do_always_noconvEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06f31c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F31CULL;
}

// FDE #0696 | PC: 0x06f324..0x06f420 (252 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDiLb1EE9do_lengthER9mbstate_tPKcS5_m
// EN: AArch64 prologue [ldrb w10, [x0, #0x18]; ldr x9, [x0, #0x10]; mov x8, x2; tbz w10, #2, #0x6f364] | VI: Khởi đầu hàm AArch64 [ldrb w10, [x0, #0x18]; ldr x9, [x0, #0x10]; mov x8, x2; tbz w10, #2, #0x6f364]
uint64_t fde_sub_06f324(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400809ULL) << 32) | 0x3940600AULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F324ULL;
}

// FDE #0697 | PC: 0x06f420..0x06f438 (24 B) | Symbol: _ZNKSt6__ndk115__codecvt_utf16IDiLb1EE13do_max_lengthEv
// EN: AArch64 prologue [ldrb w8, [x0, #0x18]; mov w9, #6; tst w8, #4; mov w8, #4] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x18]; mov w9, #6; tst w8, #4; mov w8, #4]
uint64_t fde_sub_06f420(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x528000C9ULL) << 32) | 0x39406008ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F420ULL;
}

// FDE #0698 | PC: 0x06f438..0x06f4cc (148 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IwE6do_outER9mbstate_tPKwS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_06f438(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F438ULL;
}

// FDE #0699 | PC: 0x06f4cc..0x06f6f4 (552 B) | Symbol: sub_06f4cc
// EN: AArch64 prologue [str x0, [x2]; str x3, [x5]; tbz w7, #1, #0x6f524; sub x8, x4, x3] | VI: Khởi đầu hàm AArch64 [str x0, [x2]; str x3, [x5]; tbz w7, #1, #0x6f524; sub x8, x4, x3]
uint64_t fde_sub_06f4cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90000A3ULL) << 32) | 0xF9000040ULL;
    const uint64_t kPcRange = 0x0228ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F4CCULL;
}

// FDE #0700 | PC: 0x06f6f4..0x06f760 (108 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IwE5do_inER9mbstate_tPKcS5_RS5_PwS7_RS7_
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06f6f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F6F4ULL;
}

// FDE #0701 | PC: 0x06f760..0x06f9e0 (640 B) | Symbol: sub_06f760
// EN: AArch64 prologue [str x0, [x2]; str x3, [x5]; ldr x11, [x2]; tbz w7, #2, #0x6f7a8] | VI: Khởi đầu hàm AArch64 [str x0, [x2]; str x3, [x5]; ldr x11, [x2]; tbz w7, #2, #0x6f7a8]
uint64_t fde_sub_06f760(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90000A3ULL) << 32) | 0xF9000040ULL;
    const uint64_t kPcRange = 0x0280ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F760ULL;
}

// FDE #0702 | PC: 0x06f9e0..0x06f9ec (12 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IwE10do_unshiftER9mbstate_tPcS4_RS4_
// EN: AArch64 prologue [mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_06f9e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000082ULL) << 32) | 0x52800060ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F9E0ULL;
}

// FDE #0703 | PC: 0x06f9ec..0x06f9f4 (8 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IwE11do_encodingEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06f9ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F9ECULL;
}

// FDE #0704 | PC: 0x06f9f4..0x06f9fc (8 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IwE16do_always_noconvEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06f9f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F9F4ULL;
}

// FDE #0705 | PC: 0x06f9fc..0x06fa18 (28 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IwE9do_lengthER9mbstate_tPKcS5_m
// EN: AArch64 prologue [mov x8, x4; mov x1, x3; ldr x3, [x0, #0x18]; ldr w4, [x0, #0x20]] | VI: Khởi đầu hàm AArch64 [mov x8, x4; mov x1, x3; ldr x3, [x0, #0x18]; ldr w4, [x0, #0x20]]
uint64_t fde_sub_06f9fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0303E1ULL) << 32) | 0xAA0403E8ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F9FCULL;
}

// FDE #0706 | PC: 0x06fa18..0x06fa30 (24 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IwE13do_max_lengthEv
// EN: AArch64 prologue [ldrb w8, [x0, #0x20]; mov w9, #7; tst w8, #4; mov w8, #4] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x20]; mov w9, #7; tst w8, #4; mov w8, #4]
uint64_t fde_sub_06fa18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x528000E9ULL) << 32) | 0x39408008ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FA18ULL;
}

// FDE #0707 | PC: 0x06fa30..0x06fac4 (148 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IDsE6do_outER9mbstate_tPKDsS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_06fa30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FA30ULL;
}

// FDE #0708 | PC: 0x06fac4..0x06fb30 (108 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IDsE5do_inER9mbstate_tPKcS5_RS5_PDsS7_RS7_
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06fac4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FAC4ULL;
}

// FDE #0709 | PC: 0x06fb30..0x06fb3c (12 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IDsE10do_unshiftER9mbstate_tPcS4_RS4_
// EN: AArch64 prologue [mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_06fb30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000082ULL) << 32) | 0x52800060ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FB30ULL;
}

// FDE #0710 | PC: 0x06fb3c..0x06fb44 (8 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IDsE11do_encodingEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06fb3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FB3CULL;
}

// FDE #0711 | PC: 0x06fb44..0x06fb4c (8 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IDsE16do_always_noconvEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06fb44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FB44ULL;
}

// FDE #0712 | PC: 0x06fb4c..0x06fb68 (28 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IDsE9do_lengthER9mbstate_tPKcS5_m
// EN: AArch64 prologue [mov x8, x4; mov x1, x3; ldr x3, [x0, #0x10]; ldr w4, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [mov x8, x4; mov x1, x3; ldr x3, [x0, #0x10]; ldr w4, [x0, #0x18]]
uint64_t fde_sub_06fb4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0303E1ULL) << 32) | 0xAA0403E8ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FB4CULL;
}

// FDE #0713 | PC: 0x06fb68..0x06fb80 (24 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IDsE13do_max_lengthEv
// EN: AArch64 prologue [ldrb w8, [x0, #0x18]; mov w9, #7; tst w8, #4; mov w8, #4] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x18]; mov w9, #7; tst w8, #4; mov w8, #4]
uint64_t fde_sub_06fb68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x528000E9ULL) << 32) | 0x39406008ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FB68ULL;
}

// FDE #0714 | PC: 0x06fb80..0x06fc14 (148 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IDiE6do_outER9mbstate_tPKDiS5_RS5_PcS7_RS7_
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_06fb80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FB80ULL;
}

// FDE #0715 | PC: 0x06fc14..0x06fc80 (108 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IDiE5do_inER9mbstate_tPKcS5_RS5_PDiS7_RS7_
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06fc14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FC14ULL;
}

// FDE #0716 | PC: 0x06fc80..0x06fc8c (12 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IDiE10do_unshiftER9mbstate_tPcS4_RS4_
// EN: AArch64 prologue [mov w0, #3; str x2, [x4]; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #3; str x2, [x4]; ret]
uint64_t fde_sub_06fc80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000082ULL) << 32) | 0x52800060ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FC80ULL;
}

// FDE #0717 | PC: 0x06fc8c..0x06fc94 (8 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IDiE11do_encodingEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06fc8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FC8CULL;
}

// FDE #0718 | PC: 0x06fc94..0x06fc9c (8 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IDiE16do_always_noconvEv
// EN: AArch64 prologue [mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w0, wzr; ret]
uint64_t fde_sub_06fc94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x2A1F03E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FC94ULL;
}

// FDE #0719 | PC: 0x06fc9c..0x06fcb8 (28 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IDiE9do_lengthER9mbstate_tPKcS5_m
// EN: AArch64 prologue [mov x8, x4; mov x1, x3; ldr x3, [x0, #0x10]; ldr w4, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [mov x8, x4; mov x1, x3; ldr x3, [x0, #0x10]; ldr w4, [x0, #0x18]]
uint64_t fde_sub_06fc9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0303E1ULL) << 32) | 0xAA0403E8ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FC9CULL;
}

// FDE #0720 | PC: 0x06fcb8..0x06fcd0 (24 B) | Symbol: _ZNKSt6__ndk120__codecvt_utf8_utf16IDiE13do_max_lengthEv
// EN: AArch64 prologue [ldrb w8, [x0, #0x18]; mov w9, #7; tst w8, #4; mov w8, #4] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x18]; mov w9, #7; tst w8, #4; mov w8, #4]
uint64_t fde_sub_06fcb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x528000E9ULL) << 32) | 0x39406008ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FCB8ULL;
}

// FDE #0721 | PC: 0x06fcd0..0x06fcf4 (36 B) | Symbol: _ZNSt6__ndk116__narrow_to_utf8ILm16EED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_06fcd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FCD0ULL;
}

// FDE #0722 | PC: 0x06fcf4..0x06fd18 (36 B) | Symbol: _ZNSt6__ndk116__narrow_to_utf8ILm32EED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_06fcf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FCF4ULL;
}

// FDE #0723 | PC: 0x06fd18..0x06fd3c (36 B) | Symbol: _ZNSt6__ndk117__widen_from_utf8ILm16EED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_06fd18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FD18ULL;
}

// FDE #0724 | PC: 0x06fd3c..0x06fd60 (36 B) | Symbol: _ZNSt6__ndk117__widen_from_utf8ILm32EED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_06fd3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FD3CULL;
}

// FDE #0725 | PC: 0x06fd60..0x06fd88 (40 B) | Symbol: _ZNSt6__ndk18numpunctIcEC1Em
// EN: AArch64 prologue [adrp x9, #0xe3000; ldr x9, [x9, #0xcc8]; sub x8, x1, #1; mov w10, #0x2c2e] | VI: Khởi đầu hàm AArch64 [adrp x9, #0xe3000; ldr x9, [x9, #0xcc8]; sub x8, x1, #1; mov w10, #0x2c2e]
uint64_t fde_sub_06fd60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9466529ULL) << 32) | 0x900003A9ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FD60ULL;
}

// FDE #0726 | PC: 0x06fd88..0x06fdb4 (44 B) | Symbol: _ZNSt6__ndk18numpunctIwEC2Em
// EN: AArch64 prologue [adrp x9, #0xe3000; ldr x9, [x9, #0xeb0]; adrp x10, #0xb6000; ldr d0, [x10, #0xdc0]] | VI: Khởi đầu hàm AArch64 [adrp x9, #0xe3000; ldr x9, [x9, #0xeb0]; adrp x10, #0xb6000; ldr d0, [x10, #0xdc0]]
uint64_t fde_sub_06fd88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9475929ULL) << 32) | 0x900003A9ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FD88ULL;
}

// FDE #0727 | PC: 0x06fdb4..0x06fdf4 (64 B) | Symbol: _ZNSt6__ndk18numpunctIcED2Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000]
uint64_t fde_sub_06fdb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FDB4ULL;
}

// FDE #0728 | PC: 0x06fdf4..0x06fe3c (72 B) | Symbol: _ZNSt6__ndk18numpunctIcED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000]
uint64_t fde_sub_06fdf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FDF4ULL;
}

// FDE #0729 | PC: 0x06fe3c..0x06fe7c (64 B) | Symbol: _ZNSt6__ndk18numpunctIwED1Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000]
uint64_t fde_sub_06fe3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FE3CULL;
}

// FDE #0730 | PC: 0x06fe7c..0x06fec4 (72 B) | Symbol: _ZNSt6__ndk18numpunctIwED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000]
uint64_t fde_sub_06fe7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FE7CULL;
}

// FDE #0731 | PC: 0x06fec4..0x06fecc (8 B) | Symbol: _ZNKSt6__ndk18numpunctIcE16do_decimal_pointEv
// EN: AArch64 prologue [ldrb w0, [x0, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [ldrb w0, [x0, #0x10]; ret]
uint64_t fde_sub_06fec4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x39404000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FEC4ULL;
}

// FDE #0732 | PC: 0x06fecc..0x06fed4 (8 B) | Symbol: _ZNKSt6__ndk18numpunctIwE16do_decimal_pointEv
// EN: AArch64 prologue [ldr w0, [x0, #0x10]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0x10]; ret]
uint64_t fde_sub_06fecc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9401000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FECCULL;
}

// FDE #0733 | PC: 0x06fed4..0x06fedc (8 B) | Symbol: _ZNKSt6__ndk18numpunctIcE16do_thousands_sepEv
// EN: AArch64 prologue [ldrb w0, [x0, #0x11]; ret] | VI: Khởi đầu hàm AArch64 [ldrb w0, [x0, #0x11]; ret]
uint64_t fde_sub_06fed4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x39404400ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FED4ULL;
}

// FDE #0734 | PC: 0x06fedc..0x06fee4 (8 B) | Symbol: _ZNKSt6__ndk18numpunctIwE16do_thousands_sepEv
// EN: AArch64 prologue [ldr w0, [x0, #0x14]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0x14]; ret]
uint64_t fde_sub_06fedc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9401400ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FEDCULL;
}

// FDE #0735 | PC: 0x06fee4..0x06fef0 (12 B) | Symbol: _ZNKSt6__ndk18numpunctIcE11do_groupingEv
// EN: AArch64 prologue [add x1, x0, #0x18; mov x0, x8; b #0x48580] | VI: Khởi đầu hàm AArch64 [add x1, x0, #0x18; mov x0, x8; b #0x48580]
uint64_t fde_sub_06fee4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0x91006001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FEE4ULL;
}

// FDE #0736 | PC: 0x06fef0..0x06fefc (12 B) | Symbol: _ZNKSt6__ndk18numpunctIwE11do_groupingEv
// EN: AArch64 prologue [add x1, x0, #0x18; mov x0, x8; b #0x48580] | VI: Khởi đầu hàm AArch64 [add x1, x0, #0x18; mov x0, x8; b #0x48580]
uint64_t fde_sub_06fef0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0803E0ULL) << 32) | 0x91006001ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FEF0ULL;
}

// FDE #0737 | PC: 0x06fefc..0x06ff0c (16 B) | Symbol: _ZNKSt6__ndk18numpunctIcE11do_truenameEv
// EN: AArch64 prologue [adrp x1, #0xb7000; add x1, x1, #0xd6f; mov x0, x8; b #0x481a0] | VI: Khởi đầu hàm AArch64 [adrp x1, #0xb7000; add x1, x1, #0xd6f; mov x0, x8; b #0x481a0]
uint64_t fde_sub_06fefc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9135BC21ULL) << 32) | 0x90000241ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FEFCULL;
}

// FDE #0738 | PC: 0x06ff0c..0x06ff1c (16 B) | Symbol: _ZNKSt6__ndk18numpunctIwE11do_truenameEv
// EN: AArch64 prologue [adrp x1, #0xb8000; add x1, x1, #0x54; mov x0, x8; b #0x48150] | VI: Khởi đầu hàm AArch64 [adrp x1, #0xb8000; add x1, x1, #0x54; mov x0, x8; b #0x48150]
uint64_t fde_sub_06ff0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91015021ULL) << 32) | 0xB0000241ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FF0CULL;
}

// FDE #0739 | PC: 0x06ff1c..0x06ff2c (16 B) | Symbol: _ZNKSt6__ndk18numpunctIcE12do_falsenameEv
// EN: AArch64 prologue [adrp x1, #0xb7000; add x1, x1, #0xd74; mov x0, x8; b #0x481a0] | VI: Khởi đầu hàm AArch64 [adrp x1, #0xb7000; add x1, x1, #0xd74; mov x0, x8; b #0x481a0]
uint64_t fde_sub_06ff1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9135D021ULL) << 32) | 0x90000241ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FF1CULL;
}

// FDE #0740 | PC: 0x06ff2c..0x06ff3c (16 B) | Symbol: _ZNKSt6__ndk18numpunctIwE12do_falsenameEv
// EN: AArch64 prologue [adrp x1, #0xb8000; add x1, x1, #0x68; mov x0, x8; b #0x48150] | VI: Khởi đầu hàm AArch64 [adrp x1, #0xb8000; add x1, x1, #0x68; mov x0, x8; b #0x48150]
uint64_t fde_sub_06ff2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9101A021ULL) << 32) | 0xB0000241ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FF2CULL;
}

// FDE #0741 | PC: 0x06ff3c..0x06ffb4 (120 B) | Symbol: _ZNSt6__ndk115numpunct_bynameIcEC1EPKcm
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; str xzr, [x0, #0x28]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; str xzr, [x0, #0x28]]
uint64_t fde_sub_06ff3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FF3CULL;
}

// FDE #0742 | PC: 0x06ffb4..0x0702f8 (836 B) | Symbol: _ZNSt6__ndk115numpunct_bynameIcE6__initEPKc
// EN: AArch64 prologue [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]]
uint64_t fde_sub_06ffb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F9ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0344ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FFB4ULL;
}

// FDE #0743 | PC: 0x0702f8..0x070380 (136 B) | Symbol: _ZNSt6__ndk115numpunct_bynameIcEC2ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEm
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w9, #0x2c2e] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w9, #0x2c2e]
uint64_t fde_sub_0702f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0702F8ULL;
}

// FDE #0744 | PC: 0x070380..0x0703c8 (72 B) | Symbol: _ZNSt6__ndk115numpunct_bynameIcED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000]
uint64_t fde_sub_070380(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070380ULL;
}

// FDE #0745 | PC: 0x0703c8..0x070444 (124 B) | Symbol: _ZNSt6__ndk115numpunct_bynameIwEC2EPKcm
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; str xzr, [x0, #0x28]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; str xzr, [x0, #0x28]]
uint64_t fde_sub_0703c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0703C8ULL;
}

// FDE #0746 | PC: 0x070444..0x0706a8 (612 B) | Symbol: _ZNSt6__ndk115numpunct_bynameIwE6__initEPKc
// EN: AArch64 prologue [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]]
uint64_t fde_sub_070444(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F9ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0264ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070444ULL;
}

// FDE #0747 | PC: 0x0706a8..0x070734 (140 B) | Symbol: _ZNSt6__ndk115numpunct_bynameIwEC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEm
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xb6000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xb6000]
uint64_t fde_sub_0706a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0706A8ULL;
}

// FDE #0748 | PC: 0x070734..0x07077c (72 B) | Symbol: _ZNSt6__ndk115numpunct_bynameIwED0Ev
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x9, #0xe3000]
uint64_t fde_sub_070734(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070734ULL;
}

// FDE #0749 | PC: 0x07077c..0x0707bc (64 B) | Symbol: _ZNSt6__ndk114__num_get_base10__get_baseERNS_8ios_baseE
// EN: AArch64 prologue [ldr w8, [x0, #8]; mov w9, #0x4a; ands w8, w8, w9; b.eq #0x707a4] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #8]; mov w9, #0x4a; ands w8, w8, w9; b.eq #0x707a4]
uint64_t fde_sub_07077c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800949ULL) << 32) | 0xB9400808ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07077CULL;
}

// FDE #0750 | PC: 0x0707bc..0x0709cc (528 B) | Symbol: _ZNKSt6__ndk120__time_get_c_storageIcE7__weeksEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000]
uint64_t fde_sub_0707bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0210ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0707BCULL;
}

// FDE #0751 | PC: 0x0709cc..0x070bdc (528 B) | Symbol: _ZNKSt6__ndk120__time_get_c_storageIwE7__weeksEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000]
uint64_t fde_sub_0709cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0210ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0709CCULL;
}

// FDE #0752 | PC: 0x070bdc..0x070e90 (692 B) | Symbol: _ZNKSt6__ndk120__time_get_c_storageIcE8__monthsEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000]
uint64_t fde_sub_070bdc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x02B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070BDCULL;
}

// FDE #0753 | PC: 0x070e90..0x071144 (692 B) | Symbol: _ZNKSt6__ndk120__time_get_c_storageIwE8__monthsEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000]
uint64_t fde_sub_070e90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x02B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070E90ULL;
}

// FDE #0754 | PC: 0x071144..0x071240 (252 B) | Symbol: _ZNKSt6__ndk120__time_get_c_storageIcE7__am_pmEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000]
uint64_t fde_sub_071144(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071144ULL;
}

// FDE #0755 | PC: 0x071240..0x07133c (252 B) | Symbol: _ZNKSt6__ndk120__time_get_c_storageIwE7__am_pmEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000]
uint64_t fde_sub_071240(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071240ULL;
}

// FDE #0756 | PC: 0x07133c..0x0713d4 (152 B) | Symbol: _ZNKSt6__ndk120__time_get_c_storageIcE3__xEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000]
uint64_t fde_sub_07133c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07133CULL;
}

// FDE #0757 | PC: 0x0713d4..0x07146c (152 B) | Symbol: _ZNKSt6__ndk120__time_get_c_storageIwE3__xEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000]
uint64_t fde_sub_0713d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0713D4ULL;
}

// FDE #0758 | PC: 0x07146c..0x071504 (152 B) | Symbol: _ZNKSt6__ndk120__time_get_c_storageIcE3__XEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000]
uint64_t fde_sub_07146c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07146CULL;
}

// FDE #0759 | PC: 0x071504..0x07159c (152 B) | Symbol: _ZNKSt6__ndk120__time_get_c_storageIwE3__XEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe5000]
uint64_t fde_sub_071504(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071504ULL;
}

// FDE #0760 | PC: 0x07159c..0x071634 (152 B) | Symbol: _ZNKSt6__ndk120__time_get_c_storageIcE3__cEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe6000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe6000]
uint64_t fde_sub_07159c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07159CULL;
}

// FDE #0761 | PC: 0x071634..0x0716cc (152 B) | Symbol: _ZNKSt6__ndk120__time_get_c_storageIwE3__cEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe6000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe6000]
uint64_t fde_sub_071634(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071634ULL;
}

// FDE #0762 | PC: 0x0716cc..0x071764 (152 B) | Symbol: _ZNKSt6__ndk120__time_get_c_storageIcE3__rEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe6000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe6000]
uint64_t fde_sub_0716cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0716CCULL;
}

// FDE #0763 | PC: 0x071764..0x0717fc (152 B) | Symbol: _ZNKSt6__ndk120__time_get_c_storageIwE3__rEv
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe6000] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe6000]
uint64_t fde_sub_071764(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071764ULL;
}

// FDE #0764 | PC: 0x0717fc..0x0718ec (240 B) | Symbol: _ZNSt6__ndk110__time_getC2EPKc
// EN: AArch64 prologue [sub sp, sp, #0x70; str x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_0717fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F5ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x00F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0717FCULL;
}

// FDE #0765 | PC: 0x0718ec..0x071998 (172 B) | Symbol: _ZNSt6__ndk110__time_getC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_0718ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0718ECULL;
}

// FDE #0766 | PC: 0x071998..0x0719b4 (28 B) | Symbol: _ZNSt6__ndk110__time_getD1Ev
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x0, [x0]; bl #0x47ca0] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x0, [x0]; bl #0x47ca0]
uint64_t fde_sub_071998(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071998ULL;
}

// FDE #0767 | PC: 0x0719b4..0x071fac (1528 B) | Symbol: _ZNSt6__ndk118__time_get_storageIcE9__analyzeEcRKNS_5ctypeIcEE
// EN: AArch64 prologue [sub sp, sp, #0x140; stp x28, x27, [sp, #0xe0]; stp x26, x25, [sp, #0xf0]; stp x24, x23, [sp, #0x100]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x140; stp x28, x27, [sp, #0xe0]; stp x26, x25, [sp, #0xf0]; stp x24, x23, [sp, #0x100]]
uint64_t fde_sub_0719b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90E6FFCULL) << 32) | 0xD10503FFULL;
    const uint64_t kPcRange = 0x05F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0719B4ULL;
}

// FDE #0768 | PC: 0x071fac..0x0726a4 (1784 B) | Symbol: _ZNSt6__ndk118__time_get_storageIwE9__analyzeEcRKNS_5ctypeIwEE
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_071fac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x06F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071FACULL;
}

// FDE #0769 | PC: 0x0726a4..0x072b3c (1176 B) | Symbol: _ZNSt6__ndk118__time_get_storageIcE4initERKNS_5ctypeIcEE
// EN: AArch64 prologue [sub sp, sp, #0x120; stp x28, x25, [sp, #0xd0]; stp x24, x23, [sp, #0xe0]; stp x22, x21, [sp, #0xf0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x120; stp x28, x25, [sp, #0xd0]; stp x24, x23, [sp, #0xe0]; stp x22, x21, [sp, #0xf0]]
uint64_t fde_sub_0726a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90D67FCULL) << 32) | 0xD10483FFULL;
    const uint64_t kPcRange = 0x0498ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0726A4ULL;
}

// FDE #0770 | PC: 0x072b3c..0x0737b8 (3196 B) | Symbol: _ZNSt6__ndk118__time_get_storageIwE4initERKNS_5ctypeIwEE
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_072b3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0C7CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x072B3CULL;
}

// FDE #0771 | PC: 0x0737b8..0x073b04 (844 B) | Symbol: _ZNSt6__ndk118__time_get_storageIcEC1EPKc
// EN: AArch64 prologue [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_0737b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF5ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x034CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0737B8ULL;
}

// FDE #0772 | PC: 0x073b04..0x073b74 (112 B) | Symbol: _ZNSt6__ndk112ctype_bynameIcED1Ev
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_073b04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073B04ULL;
}

// FDE #0773 | PC: 0x073b74..0x073f18 (932 B) | Symbol: _ZNSt6__ndk118__time_get_storageIcEC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE
// EN: AArch64 prologue [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_073b74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF5ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x03A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073B74ULL;
}

// FDE #0774 | PC: 0x073f18..0x07421c (772 B) | Symbol: _ZNSt6__ndk118__time_get_storageIwEC1EPKc
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_073f18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0304ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073F18ULL;
}

// FDE #0775 | PC: 0x07421c..0x074268 (76 B) | Symbol: _ZNSt6__ndk112ctype_bynameIwED2Ev
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; adrp x8, #0xe3000]
uint64_t fde_sub_07421c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07421CULL;
}

// FDE #0776 | PC: 0x074268..0x0745c4 (860 B) | Symbol: _ZNSt6__ndk118__time_get_storageIwEC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_074268(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x035CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074268ULL;
}

// FDE #0777 | PC: 0x0745c4..0x07497c (952 B) | Symbol: _ZNKSt6__ndk118__time_get_storageIcE15__do_date_orderEv
// EN: AArch64 prologue [ldrb w9, [x0, #0x3f8]; add x8, x0, #0x3f9; mov w11, #2; lsr x10, x9, #1] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x0, #0x3f8]; add x8, x0, #0x3f9; mov w11, #2; lsr x10, x9, #1]
uint64_t fde_sub_0745c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910FE408ULL) << 32) | 0x394FE009ULL;
    const uint64_t kPcRange = 0x03B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0745C4ULL;
}

// FDE #0778 | PC: 0x07497c..0x074d34 (952 B) | Symbol: _ZNKSt6__ndk118__time_get_storageIwE15__do_date_orderEv
// EN: AArch64 prologue [ldrb w9, [x0, #0x3f8]; add x8, x0, #0x3fc; mov w11, #2; lsr x10, x9, #1] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x0, #0x3f8]; add x8, x0, #0x3fc; mov w11, #2; lsr x10, x9, #1]
uint64_t fde_sub_07497c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910FF008ULL) << 32) | 0x394FE009ULL;
    const uint64_t kPcRange = 0x03B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07497CULL;
}

// FDE #0779 | PC: 0x074d34..0x074e24 (240 B) | Symbol: _ZNSt6__ndk110__time_putC1EPKc
// EN: AArch64 prologue [sub sp, sp, #0x70; str x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x21, [sp, #0x40]; stp x20, x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]]
uint64_t fde_sub_074d34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F5ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x00F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074D34ULL;
}

// FDE #0780 | PC: 0x074e24..0x074ed0 (172 B) | Symbol: _ZNSt6__ndk110__time_putC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_074e24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074E24ULL;
}

// FDE #0781 | PC: 0x074ed0..0x074f74 (164 B) | Symbol: _ZNSt6__ndk110__time_putD2Ev
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_074ed0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x074ED0ULL;
}

uint64_t DispatchCxxSharedShard2(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x05df98ULL: return fde_sub_05df98(a0, a1, a2);
        case 0x05dff4ULL: return fde_sub_05dff4(a0, a1, a2);
        case 0x05e040ULL: return fde_sub_05e040(a0, a1, a2);
        case 0x05e0f4ULL: return fde_sub_05e0f4(a0, a1, a2);
        case 0x05e0f8ULL: return fde_sub_05e0f8(a0, a1, a2);
        case 0x05e128ULL: return fde_sub_05e128(a0, a1, a2);
        case 0x05e158ULL: return fde_sub_05e158(a0, a1, a2);
        case 0x05e348ULL: return fde_sub_05e348(a0, a1, a2);
        case 0x05e558ULL: return fde_sub_05e558(a0, a1, a2);
        case 0x05e748ULL: return fde_sub_05e748(a0, a1, a2);
        case 0x05e958ULL: return fde_sub_05e958(a0, a1, a2);
        case 0x05eb48ULL: return fde_sub_05eb48(a0, a1, a2);
        case 0x05ed38ULL: return fde_sub_05ed38(a0, a1, a2);
        case 0x05ef28ULL: return fde_sub_05ef28(a0, a1, a2);
        case 0x05f118ULL: return fde_sub_05f118(a0, a1, a2);
        case 0x05f308ULL: return fde_sub_05f308(a0, a1, a2);
        case 0x05f4f8ULL: return fde_sub_05f4f8(a0, a1, a2);
        case 0x05f6e8ULL: return fde_sub_05f6e8(a0, a1, a2);
        case 0x05f8d0ULL: return fde_sub_05f8d0(a0, a1, a2);
        case 0x05fac0ULL: return fde_sub_05fac0(a0, a1, a2);
        case 0x05fd28ULL: return fde_sub_05fd28(a0, a1, a2);
        case 0x05fe84ULL: return fde_sub_05fe84(a0, a1, a2);
        case 0x05ffccULL: return fde_sub_05ffcc(a0, a1, a2);
        case 0x060024ULL: return fde_sub_060024(a0, a1, a2);
        case 0x060150ULL: return fde_sub_060150(a0, a1, a2);
        case 0x06027cULL: return fde_sub_06027c(a0, a1, a2);
        case 0x060304ULL: return fde_sub_060304(a0, a1, a2);
        case 0x060380ULL: return fde_sub_060380(a0, a1, a2);
        case 0x060384ULL: return fde_sub_060384(a0, a1, a2);
        case 0x06038cULL: return fde_sub_06038c(a0, a1, a2);
        case 0x0603a0ULL: return fde_sub_0603a0(a0, a1, a2);
        case 0x0603c8ULL: return fde_sub_0603c8(a0, a1, a2);
        case 0x0603f8ULL: return fde_sub_0603f8(a0, a1, a2);
        case 0x060454ULL: return fde_sub_060454(a0, a1, a2);
        case 0x0604a0ULL: return fde_sub_0604a0(a0, a1, a2);
        case 0x060554ULL: return fde_sub_060554(a0, a1, a2);
        case 0x060558ULL: return fde_sub_060558(a0, a1, a2);
        case 0x060588ULL: return fde_sub_060588(a0, a1, a2);
        case 0x0605b8ULL: return fde_sub_0605b8(a0, a1, a2);
        case 0x0607a8ULL: return fde_sub_0607a8(a0, a1, a2);
        case 0x0609b8ULL: return fde_sub_0609b8(a0, a1, a2);
        case 0x060ba8ULL: return fde_sub_060ba8(a0, a1, a2);
        case 0x060db8ULL: return fde_sub_060db8(a0, a1, a2);
        case 0x060fa8ULL: return fde_sub_060fa8(a0, a1, a2);
        case 0x061198ULL: return fde_sub_061198(a0, a1, a2);
        case 0x061388ULL: return fde_sub_061388(a0, a1, a2);
        case 0x061578ULL: return fde_sub_061578(a0, a1, a2);
        case 0x061768ULL: return fde_sub_061768(a0, a1, a2);
        case 0x061958ULL: return fde_sub_061958(a0, a1, a2);
        case 0x061b48ULL: return fde_sub_061b48(a0, a1, a2);
        case 0x061d30ULL: return fde_sub_061d30(a0, a1, a2);
        case 0x061f20ULL: return fde_sub_061f20(a0, a1, a2);
        case 0x06219cULL: return fde_sub_06219c(a0, a1, a2);
        case 0x062304ULL: return fde_sub_062304(a0, a1, a2);
        case 0x06244cULL: return fde_sub_06244c(a0, a1, a2);
        case 0x0624a4ULL: return fde_sub_0624a4(a0, a1, a2);
        case 0x0625d0ULL: return fde_sub_0625d0(a0, a1, a2);
        case 0x0626fcULL: return fde_sub_0626fc(a0, a1, a2);
        case 0x0627ccULL: return fde_sub_0627cc(a0, a1, a2);
        case 0x062874ULL: return fde_sub_062874(a0, a1, a2);
        case 0x062878ULL: return fde_sub_062878(a0, a1, a2);
        case 0x062880ULL: return fde_sub_062880(a0, a1, a2);
        case 0x062888ULL: return fde_sub_062888(a0, a1, a2);
        case 0x06289cULL: return fde_sub_06289c(a0, a1, a2);
        case 0x0628c4ULL: return fde_sub_0628c4(a0, a1, a2);
        case 0x0628ecULL: return fde_sub_0628ec(a0, a1, a2);
        case 0x06291cULL: return fde_sub_06291c(a0, a1, a2);
        case 0x062988ULL: return fde_sub_062988(a0, a1, a2);
        case 0x062a5cULL: return fde_sub_062a5c(a0, a1, a2);
        case 0x062a80ULL: return fde_sub_062a80(a0, a1, a2);
        case 0x062f30ULL: return fde_sub_062f30(a0, a1, a2);
        case 0x062f78ULL: return fde_sub_062f78(a0, a1, a2);
        case 0x063070ULL: return fde_sub_063070(a0, a1, a2);
        case 0x063168ULL: return fde_sub_063168(a0, a1, a2);
        case 0x06319cULL: return fde_sub_06319c(a0, a1, a2);
        case 0x063214ULL: return fde_sub_063214(a0, a1, a2);
        case 0x06321cULL: return fde_sub_06321c(a0, a1, a2);
        case 0x063224ULL: return fde_sub_063224(a0, a1, a2);
        case 0x063340ULL: return fde_sub_063340(a0, a1, a2);
        case 0x063374ULL: return fde_sub_063374(a0, a1, a2);
        case 0x063504ULL: return fde_sub_063504(a0, a1, a2);
        case 0x063538ULL: return fde_sub_063538(a0, a1, a2);
        case 0x0635b0ULL: return fde_sub_0635b0(a0, a1, a2);
        case 0x0635b8ULL: return fde_sub_0635b8(a0, a1, a2);
        case 0x0635c0ULL: return fde_sub_0635c0(a0, a1, a2);
        case 0x0636dcULL: return fde_sub_0636dc(a0, a1, a2);
        case 0x0636f0ULL: return fde_sub_0636f0(a0, a1, a2);
        case 0x063724ULL: return fde_sub_063724(a0, a1, a2);
        case 0x0638b4ULL: return fde_sub_0638b4(a0, a1, a2);
        case 0x0638c8ULL: return fde_sub_0638c8(a0, a1, a2);
        case 0x0638fcULL: return fde_sub_0638fc(a0, a1, a2);
        case 0x063950ULL: return fde_sub_063950(a0, a1, a2);
        case 0x063a18ULL: return fde_sub_063a18(a0, a1, a2);
        case 0x063ab0ULL: return fde_sub_063ab0(a0, a1, a2);
        case 0x063bf4ULL: return fde_sub_063bf4(a0, a1, a2);
        case 0x063c28ULL: return fde_sub_063c28(a0, a1, a2);
        case 0x063c7cULL: return fde_sub_063c7c(a0, a1, a2);
        case 0x063d44ULL: return fde_sub_063d44(a0, a1, a2);
        case 0x063ddcULL: return fde_sub_063ddc(a0, a1, a2);
        case 0x063f20ULL: return fde_sub_063f20(a0, a1, a2);
        case 0x063fc0ULL: return fde_sub_063fc0(a0, a1, a2);
        case 0x064060ULL: return fde_sub_064060(a0, a1, a2);
        case 0x0640e0ULL: return fde_sub_0640e0(a0, a1, a2);
        case 0x064174ULL: return fde_sub_064174(a0, a1, a2);
        case 0x0641e0ULL: return fde_sub_0641e0(a0, a1, a2);
        case 0x0642a0ULL: return fde_sub_0642a0(a0, a1, a2);
        case 0x064330ULL: return fde_sub_064330(a0, a1, a2);
        case 0x064440ULL: return fde_sub_064440(a0, a1, a2);
        case 0x064444ULL: return fde_sub_064444(a0, a1, a2);
        case 0x064494ULL: return fde_sub_064494(a0, a1, a2);
        case 0x06459cULL: return fde_sub_06459c(a0, a1, a2);
        case 0x064640ULL: return fde_sub_064640(a0, a1, a2);
        case 0x066294ULL: return fde_sub_066294(a0, a1, a2);
        case 0x0669e8ULL: return fde_sub_0669e8(a0, a1, a2);
        case 0x066a78ULL: return fde_sub_066a78(a0, a1, a2);
        case 0x066c14ULL: return fde_sub_066c14(a0, a1, a2);
        case 0x06732cULL: return fde_sub_06732c(a0, a1, a2);
        case 0x068c98ULL: return fde_sub_068c98(a0, a1, a2);
        case 0x068f00ULL: return fde_sub_068f00(a0, a1, a2);
        case 0x068facULL: return fde_sub_068fac(a0, a1, a2);
        case 0x069058ULL: return fde_sub_069058(a0, a1, a2);
        case 0x06907cULL: return fde_sub_06907c(a0, a1, a2);
        case 0x0690a8ULL: return fde_sub_0690a8(a0, a1, a2);
        case 0x0690e0ULL: return fde_sub_0690e0(a0, a1, a2);
        case 0x069184ULL: return fde_sub_069184(a0, a1, a2);
        case 0x069274ULL: return fde_sub_069274(a0, a1, a2);
        case 0x0692a0ULL: return fde_sub_0692a0(a0, a1, a2);
        case 0x0692b0ULL: return fde_sub_0692b0(a0, a1, a2);
        case 0x0692b8ULL: return fde_sub_0692b8(a0, a1, a2);
        case 0x0692f8ULL: return fde_sub_0692f8(a0, a1, a2);
        case 0x0693ccULL: return fde_sub_0693cc(a0, a1, a2);
        case 0x069428ULL: return fde_sub_069428(a0, a1, a2);
        case 0x069514ULL: return fde_sub_069514(a0, a1, a2);
        case 0x06957cULL: return fde_sub_06957c(a0, a1, a2);
        case 0x0695e4ULL: return fde_sub_0695e4(a0, a1, a2);
        case 0x0695f4ULL: return fde_sub_0695f4(a0, a1, a2);
        case 0x069668ULL: return fde_sub_069668(a0, a1, a2);
        case 0x0697d8ULL: return fde_sub_0697d8(a0, a1, a2);
        case 0x069898ULL: return fde_sub_069898(a0, a1, a2);
        case 0x069928ULL: return fde_sub_069928(a0, a1, a2);
        case 0x0699e0ULL: return fde_sub_0699e0(a0, a1, a2);
        case 0x069af4ULL: return fde_sub_069af4(a0, a1, a2);
        case 0x069b18ULL: return fde_sub_069b18(a0, a1, a2);
        case 0x069b2cULL: return fde_sub_069b2c(a0, a1, a2);
        case 0x069b4cULL: return fde_sub_069b4c(a0, a1, a2);
        case 0x069c54ULL: return fde_sub_069c54(a0, a1, a2);
        case 0x069ca4ULL: return fde_sub_069ca4(a0, a1, a2);
        case 0x069d78ULL: return fde_sub_069d78(a0, a1, a2);
        case 0x069dc4ULL: return fde_sub_069dc4(a0, a1, a2);
        case 0x069e18ULL: return fde_sub_069e18(a0, a1, a2);
        case 0x06a070ULL: return fde_sub_06a070(a0, a1, a2);
        case 0x06a274ULL: return fde_sub_06a274(a0, a1, a2);
        case 0x06a37cULL: return fde_sub_06a37c(a0, a1, a2);
        case 0x06a450ULL: return fde_sub_06a450(a0, a1, a2);
        case 0x06a49cULL: return fde_sub_06a49c(a0, a1, a2);
        case 0x06a4f0ULL: return fde_sub_06a4f0(a0, a1, a2);
        case 0x06a7b0ULL: return fde_sub_06a7b0(a0, a1, a2);
        case 0x06aa38ULL: return fde_sub_06aa38(a0, a1, a2);
        case 0x06aa5cULL: return fde_sub_06aa5c(a0, a1, a2);
        case 0x06aa84ULL: return fde_sub_06aa84(a0, a1, a2);
        case 0x06aa90ULL: return fde_sub_06aa90(a0, a1, a2);
        case 0x06aad8ULL: return fde_sub_06aad8(a0, a1, a2);
        case 0x06ab20ULL: return fde_sub_06ab20(a0, a1, a2);
        case 0x06ab60ULL: return fde_sub_06ab60(a0, a1, a2);
        case 0x06ac04ULL: return fde_sub_06ac04(a0, a1, a2);
        case 0x06acd8ULL: return fde_sub_06acd8(a0, a1, a2);
        case 0x06ad7cULL: return fde_sub_06ad7c(a0, a1, a2);
        case 0x06ae50ULL: return fde_sub_06ae50(a0, a1, a2);
        case 0x06ae58ULL: return fde_sub_06ae58(a0, a1, a2);
        case 0x06ae7cULL: return fde_sub_06ae7c(a0, a1, a2);
        case 0x06ae88ULL: return fde_sub_06ae88(a0, a1, a2);
        case 0x06af60ULL: return fde_sub_06af60(a0, a1, a2);
        case 0x06af98ULL: return fde_sub_06af98(a0, a1, a2);
        case 0x06afdcULL: return fde_sub_06afdc(a0, a1, a2);
        case 0x06b028ULL: return fde_sub_06b028(a0, a1, a2);
        case 0x06b0ccULL: return fde_sub_06b0cc(a0, a1, a2);
        case 0x06b1a4ULL: return fde_sub_06b1a4(a0, a1, a2);
        case 0x06b248ULL: return fde_sub_06b248(a0, a1, a2);
        case 0x06b320ULL: return fde_sub_06b320(a0, a1, a2);
        case 0x06b328ULL: return fde_sub_06b328(a0, a1, a2);
        case 0x06b3b4ULL: return fde_sub_06b3b4(a0, a1, a2);
        case 0x06b3c4ULL: return fde_sub_06b3c4(a0, a1, a2);
        case 0x06b454ULL: return fde_sub_06b454(a0, a1, a2);
        case 0x06b590ULL: return fde_sub_06b590(a0, a1, a2);
        case 0x06b698ULL: return fde_sub_06b698(a0, a1, a2);
        case 0x06b710ULL: return fde_sub_06b710(a0, a1, a2);
        case 0x06b728ULL: return fde_sub_06b728(a0, a1, a2);
        case 0x06b76cULL: return fde_sub_06b76c(a0, a1, a2);
        case 0x06b784ULL: return fde_sub_06b784(a0, a1, a2);
        case 0x06b7c8ULL: return fde_sub_06b7c8(a0, a1, a2);
        case 0x06b8d0ULL: return fde_sub_06b8d0(a0, a1, a2);
        case 0x06b9a4ULL: return fde_sub_06b9a4(a0, a1, a2);
        case 0x06b9f8ULL: return fde_sub_06b9f8(a0, a1, a2);
        case 0x06bb3cULL: return fde_sub_06bb3c(a0, a1, a2);
        case 0x06bca4ULL: return fde_sub_06bca4(a0, a1, a2);
        case 0x06bda0ULL: return fde_sub_06bda0(a0, a1, a2);
        case 0x06be98ULL: return fde_sub_06be98(a0, a1, a2);
        case 0x06bea0ULL: return fde_sub_06bea0(a0, a1, a2);
        case 0x06bee4ULL: return fde_sub_06bee4(a0, a1, a2);
        case 0x06beecULL: return fde_sub_06beec(a0, a1, a2);
        case 0x06bf30ULL: return fde_sub_06bf30(a0, a1, a2);
        case 0x06bf94ULL: return fde_sub_06bf94(a0, a1, a2);
        case 0x06c03cULL: return fde_sub_06c03c(a0, a1, a2);
        case 0x06c0b0ULL: return fde_sub_06c0b0(a0, a1, a2);
        case 0x06c16cULL: return fde_sub_06c16c(a0, a1, a2);
        case 0x06c190ULL: return fde_sub_06c190(a0, a1, a2);
        case 0x06c1a0ULL: return fde_sub_06c1a0(a0, a1, a2);
        case 0x06c1b0ULL: return fde_sub_06c1b0(a0, a1, a2);
        case 0x06c1bcULL: return fde_sub_06c1bc(a0, a1, a2);
        case 0x06c1c4ULL: return fde_sub_06c1c4(a0, a1, a2);
        case 0x06c1ccULL: return fde_sub_06c1cc(a0, a1, a2);
        case 0x06c1dcULL: return fde_sub_06c1dc(a0, a1, a2);
        case 0x06c1e4ULL: return fde_sub_06c1e4(a0, a1, a2);
        case 0x06c288ULL: return fde_sub_06c288(a0, a1, a2);
        case 0x06c390ULL: return fde_sub_06c390(a0, a1, a2);
        case 0x06c3b4ULL: return fde_sub_06c3b4(a0, a1, a2);
        case 0x06c6f8ULL: return fde_sub_06c6f8(a0, a1, a2);
        case 0x06ca2cULL: return fde_sub_06ca2c(a0, a1, a2);
        case 0x06cb4cULL: return fde_sub_06cb4c(a0, a1, a2);
        case 0x06cc20ULL: return fde_sub_06cc20(a0, a1, a2);
        case 0x06cc28ULL: return fde_sub_06cc28(a0, a1, a2);
        case 0x06cd1cULL: return fde_sub_06cd1c(a0, a1, a2);
        case 0x06cd8cULL: return fde_sub_06cd8c(a0, a1, a2);
        case 0x06cdb0ULL: return fde_sub_06cdb0(a0, a1, a2);
        case 0x06ce40ULL: return fde_sub_06ce40(a0, a1, a2);
        case 0x06d080ULL: return fde_sub_06d080(a0, a1, a2);
        case 0x06d0e8ULL: return fde_sub_06d0e8(a0, a1, a2);
        case 0x06d368ULL: return fde_sub_06d368(a0, a1, a2);
        case 0x06d374ULL: return fde_sub_06d374(a0, a1, a2);
        case 0x06d37cULL: return fde_sub_06d37c(a0, a1, a2);
        case 0x06d384ULL: return fde_sub_06d384(a0, a1, a2);
        case 0x06d39cULL: return fde_sub_06d39c(a0, a1, a2);
        case 0x06d5acULL: return fde_sub_06d5ac(a0, a1, a2);
        case 0x06d5b4ULL: return fde_sub_06d5b4(a0, a1, a2);
        case 0x06d5d8ULL: return fde_sub_06d5d8(a0, a1, a2);
        case 0x06d6e4ULL: return fde_sub_06d6e4(a0, a1, a2);
        case 0x06d874ULL: return fde_sub_06d874(a0, a1, a2);
        case 0x06d8dcULL: return fde_sub_06d8dc(a0, a1, a2);
        case 0x06db14ULL: return fde_sub_06db14(a0, a1, a2);
        case 0x06db20ULL: return fde_sub_06db20(a0, a1, a2);
        case 0x06db28ULL: return fde_sub_06db28(a0, a1, a2);
        case 0x06db30ULL: return fde_sub_06db30(a0, a1, a2);
        case 0x06db48ULL: return fde_sub_06db48(a0, a1, a2);
        case 0x06dd64ULL: return fde_sub_06dd64(a0, a1, a2);
        case 0x06dd6cULL: return fde_sub_06dd6c(a0, a1, a2);
        case 0x06de00ULL: return fde_sub_06de00(a0, a1, a2);
        case 0x06de6cULL: return fde_sub_06de6c(a0, a1, a2);
        case 0x06de78ULL: return fde_sub_06de78(a0, a1, a2);
        case 0x06de80ULL: return fde_sub_06de80(a0, a1, a2);
        case 0x06de88ULL: return fde_sub_06de88(a0, a1, a2);
        case 0x06dea4ULL: return fde_sub_06dea4(a0, a1, a2);
        case 0x06debcULL: return fde_sub_06debc(a0, a1, a2);
        case 0x06dfb8ULL: return fde_sub_06dfb8(a0, a1, a2);
        case 0x06e120ULL: return fde_sub_06e120(a0, a1, a2);
        case 0x06e12cULL: return fde_sub_06e12c(a0, a1, a2);
        case 0x06e134ULL: return fde_sub_06e134(a0, a1, a2);
        case 0x06e13cULL: return fde_sub_06e13c(a0, a1, a2);
        case 0x06e2b4ULL: return fde_sub_06e2b4(a0, a1, a2);
        case 0x06e2ccULL: return fde_sub_06e2cc(a0, a1, a2);
        case 0x06e360ULL: return fde_sub_06e360(a0, a1, a2);
        case 0x06e3ccULL: return fde_sub_06e3cc(a0, a1, a2);
        case 0x06e3d8ULL: return fde_sub_06e3d8(a0, a1, a2);
        case 0x06e3e0ULL: return fde_sub_06e3e0(a0, a1, a2);
        case 0x06e3e8ULL: return fde_sub_06e3e8(a0, a1, a2);
        case 0x06e404ULL: return fde_sub_06e404(a0, a1, a2);
        case 0x06e41cULL: return fde_sub_06e41c(a0, a1, a2);
        case 0x06e4fcULL: return fde_sub_06e4fc(a0, a1, a2);
        case 0x06e60cULL: return fde_sub_06e60c(a0, a1, a2);
        case 0x06e618ULL: return fde_sub_06e618(a0, a1, a2);
        case 0x06e620ULL: return fde_sub_06e620(a0, a1, a2);
        case 0x06e628ULL: return fde_sub_06e628(a0, a1, a2);
        case 0x06e724ULL: return fde_sub_06e724(a0, a1, a2);
        case 0x06e73cULL: return fde_sub_06e73c(a0, a1, a2);
        case 0x06e80cULL: return fde_sub_06e80c(a0, a1, a2);
        case 0x06e91cULL: return fde_sub_06e91c(a0, a1, a2);
        case 0x06e928ULL: return fde_sub_06e928(a0, a1, a2);
        case 0x06e930ULL: return fde_sub_06e930(a0, a1, a2);
        case 0x06e938ULL: return fde_sub_06e938(a0, a1, a2);
        case 0x06ea34ULL: return fde_sub_06ea34(a0, a1, a2);
        case 0x06ea4cULL: return fde_sub_06ea4c(a0, a1, a2);
        case 0x06eac8ULL: return fde_sub_06eac8(a0, a1, a2);
        case 0x06eb58ULL: return fde_sub_06eb58(a0, a1, a2);
        case 0x06eb64ULL: return fde_sub_06eb64(a0, a1, a2);
        case 0x06eb6cULL: return fde_sub_06eb6c(a0, a1, a2);
        case 0x06eb74ULL: return fde_sub_06eb74(a0, a1, a2);
        case 0x06ec08ULL: return fde_sub_06ec08(a0, a1, a2);
        case 0x06ec20ULL: return fde_sub_06ec20(a0, a1, a2);
        case 0x06ec98ULL: return fde_sub_06ec98(a0, a1, a2);
        case 0x06ed28ULL: return fde_sub_06ed28(a0, a1, a2);
        case 0x06ed34ULL: return fde_sub_06ed34(a0, a1, a2);
        case 0x06ed3cULL: return fde_sub_06ed3c(a0, a1, a2);
        case 0x06ed44ULL: return fde_sub_06ed44(a0, a1, a2);
        case 0x06edf0ULL: return fde_sub_06edf0(a0, a1, a2);
        case 0x06ee08ULL: return fde_sub_06ee08(a0, a1, a2);
        case 0x06eee8ULL: return fde_sub_06eee8(a0, a1, a2);
        case 0x06eff8ULL: return fde_sub_06eff8(a0, a1, a2);
        case 0x06f004ULL: return fde_sub_06f004(a0, a1, a2);
        case 0x06f00cULL: return fde_sub_06f00c(a0, a1, a2);
        case 0x06f014ULL: return fde_sub_06f014(a0, a1, a2);
        case 0x06f110ULL: return fde_sub_06f110(a0, a1, a2);
        case 0x06f128ULL: return fde_sub_06f128(a0, a1, a2);
        case 0x06f1f8ULL: return fde_sub_06f1f8(a0, a1, a2);
        case 0x06f308ULL: return fde_sub_06f308(a0, a1, a2);
        case 0x06f314ULL: return fde_sub_06f314(a0, a1, a2);
        case 0x06f31cULL: return fde_sub_06f31c(a0, a1, a2);
        case 0x06f324ULL: return fde_sub_06f324(a0, a1, a2);
        case 0x06f420ULL: return fde_sub_06f420(a0, a1, a2);
        case 0x06f438ULL: return fde_sub_06f438(a0, a1, a2);
        case 0x06f4ccULL: return fde_sub_06f4cc(a0, a1, a2);
        case 0x06f6f4ULL: return fde_sub_06f6f4(a0, a1, a2);
        case 0x06f760ULL: return fde_sub_06f760(a0, a1, a2);
        case 0x06f9e0ULL: return fde_sub_06f9e0(a0, a1, a2);
        case 0x06f9ecULL: return fde_sub_06f9ec(a0, a1, a2);
        case 0x06f9f4ULL: return fde_sub_06f9f4(a0, a1, a2);
        case 0x06f9fcULL: return fde_sub_06f9fc(a0, a1, a2);
        case 0x06fa18ULL: return fde_sub_06fa18(a0, a1, a2);
        case 0x06fa30ULL: return fde_sub_06fa30(a0, a1, a2);
        case 0x06fac4ULL: return fde_sub_06fac4(a0, a1, a2);
        case 0x06fb30ULL: return fde_sub_06fb30(a0, a1, a2);
        case 0x06fb3cULL: return fde_sub_06fb3c(a0, a1, a2);
        case 0x06fb44ULL: return fde_sub_06fb44(a0, a1, a2);
        case 0x06fb4cULL: return fde_sub_06fb4c(a0, a1, a2);
        case 0x06fb68ULL: return fde_sub_06fb68(a0, a1, a2);
        case 0x06fb80ULL: return fde_sub_06fb80(a0, a1, a2);
        case 0x06fc14ULL: return fde_sub_06fc14(a0, a1, a2);
        case 0x06fc80ULL: return fde_sub_06fc80(a0, a1, a2);
        case 0x06fc8cULL: return fde_sub_06fc8c(a0, a1, a2);
        case 0x06fc94ULL: return fde_sub_06fc94(a0, a1, a2);
        case 0x06fc9cULL: return fde_sub_06fc9c(a0, a1, a2);
        case 0x06fcb8ULL: return fde_sub_06fcb8(a0, a1, a2);
        case 0x06fcd0ULL: return fde_sub_06fcd0(a0, a1, a2);
        case 0x06fcf4ULL: return fde_sub_06fcf4(a0, a1, a2);
        case 0x06fd18ULL: return fde_sub_06fd18(a0, a1, a2);
        case 0x06fd3cULL: return fde_sub_06fd3c(a0, a1, a2);
        case 0x06fd60ULL: return fde_sub_06fd60(a0, a1, a2);
        case 0x06fd88ULL: return fde_sub_06fd88(a0, a1, a2);
        case 0x06fdb4ULL: return fde_sub_06fdb4(a0, a1, a2);
        case 0x06fdf4ULL: return fde_sub_06fdf4(a0, a1, a2);
        case 0x06fe3cULL: return fde_sub_06fe3c(a0, a1, a2);
        case 0x06fe7cULL: return fde_sub_06fe7c(a0, a1, a2);
        case 0x06fec4ULL: return fde_sub_06fec4(a0, a1, a2);
        case 0x06feccULL: return fde_sub_06fecc(a0, a1, a2);
        case 0x06fed4ULL: return fde_sub_06fed4(a0, a1, a2);
        case 0x06fedcULL: return fde_sub_06fedc(a0, a1, a2);
        case 0x06fee4ULL: return fde_sub_06fee4(a0, a1, a2);
        case 0x06fef0ULL: return fde_sub_06fef0(a0, a1, a2);
        case 0x06fefcULL: return fde_sub_06fefc(a0, a1, a2);
        case 0x06ff0cULL: return fde_sub_06ff0c(a0, a1, a2);
        case 0x06ff1cULL: return fde_sub_06ff1c(a0, a1, a2);
        case 0x06ff2cULL: return fde_sub_06ff2c(a0, a1, a2);
        case 0x06ff3cULL: return fde_sub_06ff3c(a0, a1, a2);
        case 0x06ffb4ULL: return fde_sub_06ffb4(a0, a1, a2);
        case 0x0702f8ULL: return fde_sub_0702f8(a0, a1, a2);
        case 0x070380ULL: return fde_sub_070380(a0, a1, a2);
        case 0x0703c8ULL: return fde_sub_0703c8(a0, a1, a2);
        case 0x070444ULL: return fde_sub_070444(a0, a1, a2);
        case 0x0706a8ULL: return fde_sub_0706a8(a0, a1, a2);
        case 0x070734ULL: return fde_sub_070734(a0, a1, a2);
        case 0x07077cULL: return fde_sub_07077c(a0, a1, a2);
        case 0x0707bcULL: return fde_sub_0707bc(a0, a1, a2);
        case 0x0709ccULL: return fde_sub_0709cc(a0, a1, a2);
        case 0x070bdcULL: return fde_sub_070bdc(a0, a1, a2);
        case 0x070e90ULL: return fde_sub_070e90(a0, a1, a2);
        case 0x071144ULL: return fde_sub_071144(a0, a1, a2);
        case 0x071240ULL: return fde_sub_071240(a0, a1, a2);
        case 0x07133cULL: return fde_sub_07133c(a0, a1, a2);
        case 0x0713d4ULL: return fde_sub_0713d4(a0, a1, a2);
        case 0x07146cULL: return fde_sub_07146c(a0, a1, a2);
        case 0x071504ULL: return fde_sub_071504(a0, a1, a2);
        case 0x07159cULL: return fde_sub_07159c(a0, a1, a2);
        case 0x071634ULL: return fde_sub_071634(a0, a1, a2);
        case 0x0716ccULL: return fde_sub_0716cc(a0, a1, a2);
        case 0x071764ULL: return fde_sub_071764(a0, a1, a2);
        case 0x0717fcULL: return fde_sub_0717fc(a0, a1, a2);
        case 0x0718ecULL: return fde_sub_0718ec(a0, a1, a2);
        case 0x071998ULL: return fde_sub_071998(a0, a1, a2);
        case 0x0719b4ULL: return fde_sub_0719b4(a0, a1, a2);
        case 0x071facULL: return fde_sub_071fac(a0, a1, a2);
        case 0x0726a4ULL: return fde_sub_0726a4(a0, a1, a2);
        case 0x072b3cULL: return fde_sub_072b3c(a0, a1, a2);
        case 0x0737b8ULL: return fde_sub_0737b8(a0, a1, a2);
        case 0x073b04ULL: return fde_sub_073b04(a0, a1, a2);
        case 0x073b74ULL: return fde_sub_073b74(a0, a1, a2);
        case 0x073f18ULL: return fde_sub_073f18(a0, a1, a2);
        case 0x07421cULL: return fde_sub_07421c(a0, a1, a2);
        case 0x074268ULL: return fde_sub_074268(a0, a1, a2);
        case 0x0745c4ULL: return fde_sub_0745c4(a0, a1, a2);
        case 0x07497cULL: return fde_sub_07497c(a0, a1, a2);
        case 0x074d34ULL: return fde_sub_074d34(a0, a1, a2);
        case 0x074e24ULL: return fde_sub_074e24(a0, a1, a2);
        case 0x074ed0ULL: return fde_sub_074ed0(a0, a1, a2);
        default: return 0ULL;
    }
}

} // namespace ndk_libcxx_recon
