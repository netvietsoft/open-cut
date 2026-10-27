// ============================================================================
// File: animax_fde_shard_2.cpp
// Target 108 / 169: libanimax.so (657,720 bytes)
// EN: Clean-room C++17 AArch64 FDE Shard 2/5 covering FDEs [793..1585]
//     (PC range 0x057a34 .. 0x073f28).
// VI: Phân mảnh FDE AArch64 C++17 2/5 bao phủ FDE [793..1585]
//     (Dải địa chỉ PC 0x057a34 .. 0x073f28).
// ============================================================================
#include "animax_player_core.h"

namespace lynx {
namespace animax {

// FDE #0793 | PC: 0x057a34..0x057a44 (16 B) | Symbol: sub_057a34
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x579fc] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x579fc]
uint64_t fde_sub_057a34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400D707ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057A34ULL;
}

// FDE #0794 | PC: 0x057a44..0x057a54 (16 B) | Symbol: sub_057a44
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x7a8; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x7a8; b #0x8d518]
uint64_t fde_sub_057a44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057A44ULL;
}

// FDE #0795 | PC: 0x057a54..0x057a6c (24 B) | Symbol: sub_057a54
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x57a44; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x57a44; mov x0, x19]
uint64_t fde_sub_057a54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057A54ULL;
}

// FDE #0796 | PC: 0x057a6c..0x057a78 (12 B) | Symbol: sub_057a6c
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x579f0] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x579f0]
uint64_t fde_sub_057a6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400900ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057A6CULL;
}

// FDE #0797 | PC: 0x057a78..0x057b14 (156 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer22UnsubscribeUpdateEventEi
// EN: AArch64 prologue [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_057a78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF6ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057A78ULL;
}

// FDE #0798 | PC: 0x057b14..0x057b24 (16 B) | Symbol: sub_057b14
// EN: AArch64 prologue [cbz x0, #0x57b20; ldr w1, [x1]; b #0x52164; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x57b20; ldr w1, [x1]; b #0x52164; ret]
uint64_t fde_sub_057b14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9400021ULL) << 32) | 0xB4000060ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057B14ULL;
}

// FDE #0799 | PC: 0x057b24..0x057b34 (16 B) | Symbol: sub_057b24
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x7f8; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x7f8; b #0x8d518]
uint64_t fde_sub_057b24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057B24ULL;
}

// FDE #0800 | PC: 0x057b34..0x057b4c (24 B) | Symbol: sub_057b34
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x57b24; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x57b24; mov x0, x19]
uint64_t fde_sub_057b34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057B34ULL;
}

// FDE #0801 | PC: 0x057b4c..0x057b5c (16 B) | Symbol: sub_057b4c
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x57b14] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x57b14]
uint64_t fde_sub_057b4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400D6C1ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057B4CULL;
}

// FDE #0802 | PC: 0x057b5c..0x057ccc (368 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer21SubscribeUpdateEventsENSt6__ndk113unordered_setIiNS2_4hashIiEENS2_8equal_toIiEENS2_9allocatorIiEEEEb
// EN: AArch64 prologue [sub sp, sp, #0xd0; str x24, [sp, #0x90]; stp x23, x22, [sp, #0xa0]; stp x21, x20, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xd0; str x24, [sp, #0x90]; stp x23, x22, [sp, #0xa0]; stp x21, x20, [sp, #0xb0]]
uint64_t fde_sub_057b5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9004BF8ULL) << 32) | 0xD10343FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057B5CULL;
}

// FDE #0803 | PC: 0x057ccc..0x057cdc (16 B) | Symbol: sub_057ccc
// EN: AArch64 prologue [cbz x0, #0x57cd8; ldrb w2, [x1, #0x28]; b #0x5216c; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x57cd8; ldrb w2, [x1, #0x28]; b #0x5216c; ret]
uint64_t fde_sub_057ccc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3940A022ULL) << 32) | 0xB4000060ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057CCCULL;
}

// FDE #0804 | PC: 0x057cdc..0x057cfc (32 B) | Symbol: sub_057cdc
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e128; bl #0x4b7f4] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e128; bl #0x4b7f4]
uint64_t fde_sub_057cdc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057CDCULL;
}

// FDE #0805 | PC: 0x057cfc..0x057d14 (24 B) | Symbol: sub_057cfc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x51348; ldr x0, [x19, #8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x51348; ldr x0, [x19, #8]]
uint64_t fde_sub_057cfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400D787ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057CFCULL;
}

// FDE #0806 | PC: 0x057d14..0x057d24 (16 B) | Symbol: sub_057d14
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0x820; str x8, [x0], #8; b #0x57cfc] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0x820; str x8, [x0], #8; b #0x57cfc]
uint64_t fde_sub_057d14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91208108ULL) << 32) | 0xD0000208ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057D14ULL;
}

// FDE #0807 | PC: 0x057d24..0x057d3c (24 B) | Symbol: sub_057d24
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x57d14; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x57d14; mov x0, x19]
uint64_t fde_sub_057d24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057D24ULL;
}

// FDE #0808 | PC: 0x057d3c..0x057d4c (16 B) | Symbol: sub_057d3c
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x57ccc] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x57ccc]
uint64_t fde_sub_057d3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400D645ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057D3CULL;
}

// FDE #0809 | PC: 0x057d4c..0x057da0 (84 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer15GetCurrentFrameEv
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8df34] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8df34]
uint64_t fde_sub_057d4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90253F5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057D4CULL;
}

// FDE #0810 | PC: 0x057da0..0x057dbc (28 B) | Symbol: sub_057da0
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x57db8; ldr x8, [x8, #0xb8]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x57db8; ldr x8, [x8, #0xb8]]
uint64_t fde_sub_057da0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400908ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057DA0ULL;
}

// FDE #0811 | PC: 0x057dbc..0x057e98 (220 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer6OnShowENS0_15VisibilityStateE
// EN: AArch64 prologue [sub sp, sp, #0x170; stp x28, x22, [sp, #0x140]; stp x21, x20, [sp, #0x150]; stp x19, x30, [sp, #0x160]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; stp x28, x22, [sp, #0x140]; stp x21, x20, [sp, #0x150]; stp x19, x30, [sp, #0x160]]
uint64_t fde_sub_057dbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9145BFCULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057DBCULL;
}

// FDE #0812 | PC: 0x057e98..0x057eac (20 B) | Symbol: sub_057e98
// EN: AArch64 prologue [cbz x0, #0x57ea8; ldr x0, [x0, #0x20]; ldrb w1, [x1]; b #0x52314] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x57ea8; ldr x0, [x0, #0x20]; ldrb w1, [x1]; b #0x52314]
uint64_t fde_sub_057e98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401000ULL) << 32) | 0xB4000080ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057E98ULL;
}

// FDE #0813 | PC: 0x057eac..0x057ebc (16 B) | Symbol: sub_057eac
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x870; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x870; b #0x8d518]
uint64_t fde_sub_057eac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057EACULL;
}

// FDE #0814 | PC: 0x057ebc..0x057ed4 (24 B) | Symbol: sub_057ebc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x57eac; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x57eac; mov x0, x19]
uint64_t fde_sub_057ebc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057EBCULL;
}

// FDE #0815 | PC: 0x057ed4..0x057ee4 (16 B) | Symbol: sub_057ed4
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x57e98] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x57e98]
uint64_t fde_sub_057ed4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400D5DFULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057ED4ULL;
}

// FDE #0816 | PC: 0x057ee4..0x057fc0 (220 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer6OnHideENS0_15VisibilityStateE
// EN: AArch64 prologue [sub sp, sp, #0x170; stp x28, x22, [sp, #0x140]; stp x21, x20, [sp, #0x150]; stp x19, x30, [sp, #0x160]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; stp x28, x22, [sp, #0x140]; stp x21, x20, [sp, #0x150]; stp x19, x30, [sp, #0x160]]
uint64_t fde_sub_057ee4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9145BFCULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057EE4ULL;
}

// FDE #0817 | PC: 0x057fc0..0x057fd4 (20 B) | Symbol: sub_057fc0
// EN: AArch64 prologue [cbz x0, #0x57fd0; ldr x0, [x0, #0x20]; ldrb w1, [x1]; b #0x52400] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x57fd0; ldr x0, [x0, #0x20]; ldrb w1, [x1]; b #0x52400]
uint64_t fde_sub_057fc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401000ULL) << 32) | 0xB4000080ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057FC0ULL;
}

// FDE #0818 | PC: 0x057fd4..0x057fe4 (16 B) | Symbol: sub_057fd4
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x898; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x898; b #0x8d518]
uint64_t fde_sub_057fd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD0000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057FD4ULL;
}

// FDE #0819 | PC: 0x057fe4..0x057ffc (24 B) | Symbol: sub_057fe4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x57fd4; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x57fd4; mov x0, x19]
uint64_t fde_sub_057fe4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057FE4ULL;
}

// FDE #0820 | PC: 0x057ffc..0x05800c (16 B) | Symbol: sub_057ffc
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x57fc0] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x57fc0]
uint64_t fde_sub_057ffc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400D595ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057FFCULL;
}

// FDE #0821 | PC: 0x05800c..0x058148 (316 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer10OnProgressEddb
// EN: AArch64 prologue [sub sp, sp, #0xa0; str x24, [sp, #0x60]; stp x23, x22, [sp, #0x70]; stp x21, x20, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; str x24, [sp, #0x60]; stp x23, x22, [sp, #0x70]; stp x21, x20, [sp, #0x80]]
uint64_t fde_sub_05800c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90033F8ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x013CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05800CULL;
}

// FDE #0822 | PC: 0x058148..0x058180 (56 B) | Symbol: sub_058148
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; cbz x8, #0x5817c; ldrb w9, [x1, #8]; cbz w9, #0x58170] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; cbz x8, #0x5817c; ldrb w9, [x1, #8]; cbz w9, #0x58170]
uint64_t fde_sub_058148(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000188ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058148ULL;
}

// FDE #0823 | PC: 0x058180..0x058198 (24 B) | Symbol: sub_058180
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8e7ac; bl #0x44830; ldr x0, [x19, #8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8e7ac; bl #0x44830; ldr x0, [x19, #8]]
uint64_t fde_sub_058180(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400D98AULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058180ULL;
}

// FDE #0824 | PC: 0x058198..0x0581a8 (16 B) | Symbol: sub_058198
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0x8c0; str x8, [x0], #8; b #0x58180] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0x8c0; str x8, [x0], #8; b #0x58180]
uint64_t fde_sub_058198(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91230108ULL) << 32) | 0xB0000208ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058198ULL;
}

// FDE #0825 | PC: 0x0581a8..0x0581c0 (24 B) | Symbol: sub_0581a8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x58198; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x58198; mov x0, x19]
uint64_t fde_sub_0581a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0581A8ULL;
}

// FDE #0826 | PC: 0x0581c0..0x0581d0 (16 B) | Symbol: sub_0581c0
// EN: AArch64 prologue [ldr x8, [x0, #8]; add x1, x0, #0x18; mov x0, x8; b #0x58148] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; add x1, x0, #0x18; mov x0, x8; b #0x58148]
uint64_t fde_sub_0581c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91006001ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0581C0ULL;
}

// FDE #0827 | PC: 0x0581d0..0x058280 (176 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer5OnTapEff
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]; mrs x21, tpidr_el0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]; mrs x21, tpidr_el0]
uint64_t fde_sub_0581d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90453F5ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0581D0ULL;
}

// FDE #0828 | PC: 0x058280..0x058290 (16 B) | Symbol: sub_058280
// EN: AArch64 prologue [cbz x0, #0x5828c; ldp s0, s1, [x1]; b #0x59d54; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x5828c; ldp s0, s1, [x1]; b #0x59d54; ret]
uint64_t fde_sub_058280(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2D400420ULL) << 32) | 0xB4000060ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058280ULL;
}

// FDE #0829 | PC: 0x058290..0x0582a0 (16 B) | Symbol: sub_058290
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x8e8; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x8e8; b #0x8d518]
uint64_t fde_sub_058290(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058290ULL;
}

// FDE #0830 | PC: 0x0582a0..0x0582b8 (24 B) | Symbol: sub_0582a0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x58290; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x58290; mov x0, x19]
uint64_t fde_sub_0582a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0582A0ULL;
}

// FDE #0831 | PC: 0x0582b8..0x0582c8 (16 B) | Symbol: sub_0582b8
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x58280] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x58280]
uint64_t fde_sub_0582b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400D4E6ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0582B8ULL;
}

// FDE #0832 | PC: 0x0582c8..0x058358 (144 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer28MarkPlatformSurfaceAsInvalidEb
// EN: AArch64 prologue [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_0582c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF6ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0582C8ULL;
}

// FDE #0833 | PC: 0x058358..0x058368 (16 B) | Symbol: sub_058358
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x910; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0x910; b #0x8d518]
uint64_t fde_sub_058358(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058358ULL;
}

// FDE #0834 | PC: 0x058368..0x058380 (24 B) | Symbol: sub_058368
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x58358; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x58358; mov x0, x19]
uint64_t fde_sub_058368(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058368ULL;
}

// FDE #0835 | PC: 0x058380..0x058398 (24 B) | Symbol: sub_058380
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x58394; ldrb w9, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cbz x8, #0x58394; ldrb w9, [x0, #0x18]]
uint64_t fde_sub_058380(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400908ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058380ULL;
}

// FDE #0836 | PC: 0x058398..0x0583d0 (56 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer28ExportDataFromMetricsManagerENS_4base15MoveOnlyClosureIvJNSt6__ndk113unordered_mapINS4_12basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEdNS4_4hashISB_EENS4_8equal_toISB_EENS9_INS4_4pairIKSB_dEEEEEEEEE
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; ldr x8, [x1]; ldr x0, [x0, #0x68]; str x8, [sp, #8]] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; ldr x8, [x1]; ldr x0, [x0, #0x68]; str x8, [sp, #8]]
uint64_t fde_sub_058398(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400028ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058398ULL;
}

// FDE #0837 | PC: 0x0583d0..0x0584a8 (216 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer17GetKeysForKeyPathENSt6__ndk110unique_ptrINS0_13AnimaXKeyPathENS2_14default_deleteIS4_EEEENS_4base15MoveOnlyClosureIvJNS2_6vectorIS4_NS2_9allocatorIS4_EEEEEEE
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x23, x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x23, x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]]
uint64_t fde_sub_0583d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9045BF7ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0583D0ULL;
}

// FDE #0838 | PC: 0x0584a8..0x0584fc (84 B) | Symbol: sub_0584a8
// EN: AArch64 prologue [cbz x0, #0x584f8; sub sp, sp, #0x20; ldr x8, [x1]; str xzr, [x1]] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x584f8; sub sp, sp, #0x20; ldr x8, [x1]; str xzr, [x1]]
uint64_t fde_sub_0584a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10083FFULL) << 32) | 0xB4000280ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0584A8ULL;
}

// FDE #0839 | PC: 0x0584fc..0x058514 (24 B) | Symbol: sub_0584fc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x58514; ldr x0, [x19, #8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x58514; ldr x0, [x19, #8]]
uint64_t fde_sub_0584fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400D587ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0584FCULL;
}

// FDE #0840 | PC: 0x058514..0x058534 (32 B) | Symbol: sub_058514
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #8]; cbz x0, #0x58528] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #8]; cbz x0, #0x58528]
uint64_t fde_sub_058514(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058514ULL;
}

// FDE #0841 | PC: 0x058534..0x058544 (16 B) | Symbol: sub_058534
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0x938; str x8, [x0], #8; b #0x584fc] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0x938; str x8, [x0], #8; b #0x584fc]
uint64_t fde_sub_058534(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9124E108ULL) << 32) | 0xB0000208ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058534ULL;
}

// FDE #0842 | PC: 0x058544..0x05855c (24 B) | Symbol: sub_058544
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x58534; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x58534; mov x0, x19]
uint64_t fde_sub_058544(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058544ULL;
}

// FDE #0843 | PC: 0x05855c..0x05856c (16 B) | Symbol: sub_05855c
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x584a8] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x584a8]
uint64_t fde_sub_05855c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400D43DULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05855CULL;
}

// FDE #0844 | PC: 0x05856c..0x058628 (188 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer19UpdateLayerPropertyENSt6__ndk110unique_ptrINS0_18LayerStaticRequestENS2_14default_deleteIS4_EEEE
// EN: AArch64 prologue [sub sp, sp, #0x70; str x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]]
uint64_t fde_sub_05856c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F6ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05856CULL;
}

// FDE #0845 | PC: 0x058628..0x05864c (36 B) | Symbol: sub_058628
// EN: AArch64 prologue [cbz x0, #0x58648; str x30, [sp, #-0x10]!; bl #0x8ef2c; bl #0x5a478] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x58648; str x30, [sp, #-0x10]!; bl #0x8ef2c; bl #0x5a478]
uint64_t fde_sub_058628(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81F0FFEULL) << 32) | 0xB4000100ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058628ULL;
}

// FDE #0846 | PC: 0x05864c..0x058668 (28 B) | Symbol: sub_05864c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x91da8; cbz x0, #0x5865c; bl #0x8d3c4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x91da8; cbz x0, #0x5865c; bl #0x8d3c4]
uint64_t fde_sub_05864c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400E5D6ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05864CULL;
}

// FDE #0847 | PC: 0x058668..0x058678 (16 B) | Symbol: sub_058668
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0x960; str x8, [x0], #8; b #0x5864c] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0x960; str x8, [x0], #8; b #0x5864c]
uint64_t fde_sub_058668(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91258108ULL) << 32) | 0xB0000208ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058668ULL;
}

// FDE #0848 | PC: 0x058678..0x058690 (24 B) | Symbol: sub_058678
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x58668; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x58668; mov x0, x19]
uint64_t fde_sub_058678(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058678ULL;
}

// FDE #0849 | PC: 0x058690..0x0586a0 (16 B) | Symbol: sub_058690
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x58628] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x58628]
uint64_t fde_sub_058690(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400D3F0ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058690ULL;
}

// FDE #0850 | PC: 0x0586a0..0x05875c (188 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer19SetResourcePropertyENSt6__ndk110unique_ptrINS0_21ResourceUpdateRequestENS2_14default_deleteIS4_EEEE
// EN: AArch64 prologue [sub sp, sp, #0x70; str x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]]
uint64_t fde_sub_0586a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F6ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0586A0ULL;
}

// FDE #0851 | PC: 0x05875c..0x058780 (36 B) | Symbol: sub_05875c
// EN: AArch64 prologue [cbz x0, #0x5877c; str x30, [sp, #-0x10]!; bl #0x8ef2c; bl #0x5a4b0] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x5877c; str x30, [sp, #-0x10]!; bl #0x8ef2c; bl #0x5a4b0]
uint64_t fde_sub_05875c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81F0FFEULL) << 32) | 0xB4000100ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05875CULL;
}

// FDE #0852 | PC: 0x058780..0x058790 (16 B) | Symbol: sub_058780
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0x988; str x8, [x0], #8; b #0x5864c] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0x988; str x8, [x0], #8; b #0x5864c]
uint64_t fde_sub_058780(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91262108ULL) << 32) | 0xB0000208ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058780ULL;
}

// FDE #0853 | PC: 0x058790..0x0587a8 (24 B) | Symbol: sub_058790
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x58780; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x58780; mov x0, x19]
uint64_t fde_sub_058790(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058790ULL;
}

// FDE #0854 | PC: 0x0587a8..0x0587b8 (16 B) | Symbol: sub_0587a8
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x5875c] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x5875c]
uint64_t fde_sub_0587a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400D3AAULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0587A8ULL;
}

// FDE #0855 | PC: 0x0587b8..0x058874 (188 B) | Symbol: _ZN4lynx6animax12AnimaXPlayer24AddLayerPropertyCallbackENSt6__ndk110unique_ptrINS0_20LayerCallbackRequestENS2_14default_deleteIS4_EEEE
// EN: AArch64 prologue [sub sp, sp, #0x70; str x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]]
uint64_t fde_sub_0587b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F6ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0587B8ULL;
}

// FDE #0856 | PC: 0x058874..0x058898 (36 B) | Symbol: sub_058874
// EN: AArch64 prologue [cbz x0, #0x58894; str x30, [sp, #-0x10]!; bl #0x8ef2c; bl #0x5a4e8] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x58894; str x30, [sp, #-0x10]!; bl #0x8ef2c; bl #0x5a4e8]
uint64_t fde_sub_058874(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81F0FFEULL) << 32) | 0xB4000100ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058874ULL;
}

// FDE #0857 | PC: 0x058898..0x0588a8 (16 B) | Symbol: sub_058898
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0x9b0; str x8, [x0], #8; b #0x5864c] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0x9b0; str x8, [x0], #8; b #0x5864c]
uint64_t fde_sub_058898(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9126C108ULL) << 32) | 0xB0000208ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058898ULL;
}

// FDE #0858 | PC: 0x0588a8..0x0588c0 (24 B) | Symbol: sub_0588a8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x58898; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x58898; mov x0, x19]
uint64_t fde_sub_0588a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0588A8ULL;
}

// FDE #0859 | PC: 0x0588c0..0x0588d0 (16 B) | Symbol: sub_0588c0
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x58874] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x58874]
uint64_t fde_sub_0588c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400D364ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0588C0ULL;
}

// FDE #0860 | PC: 0x0588d0..0x0588d8 (8 B) | Symbol: _ZN4lynx6animax19AnimaXPlayerBuilder8SetScaleEf
// EN: AArch64 prologue [str s0, [x0]; ret] | VI: Khởi đầu hàm AArch64 [str s0, [x0]; ret]
uint64_t fde_sub_0588d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xBD000000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0588D0ULL;
}

// FDE #0861 | PC: 0x0588d8..0x0588fc (36 B) | Symbol: _ZN4lynx6animax19AnimaXPlayerBuilder15SetVSyncMonitorENSt6__ndk110shared_ptrINS0_12VSyncMonitorEEE
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; ldp x8, x9, [x1]; stp xzr, xzr, [x1]; bl #0x8db6c] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; ldp x8, x9, [x1]; stp xzr, xzr, [x1]; bl #0x8db6c]
uint64_t fde_sub_0588d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9402428ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0588D8ULL;
}

// FDE #0862 | PC: 0x0588fc..0x058908 (12 B) | Symbol: _ZN4lynx6animax19AnimaXPlayerBuilder27EnableMultiThreadAccelerateEb
// EN: AArch64 prologue [and w8, w1, #1; strb w8, [x0, #0x18]; ret] | VI: Khởi đầu hàm AArch64 [and w8, w1, #1; strb w8, [x0, #0x18]; ret]
uint64_t fde_sub_0588fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39006008ULL) << 32) | 0x12000028ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0588FCULL;
}

// FDE #0863 | PC: 0x058908..0x058914 (12 B) | Symbol: _ZN4lynx6animax19AnimaXPlayerBuilder21SetSkipCountDownEventEb
// EN: AArch64 prologue [and w8, w1, #1; strb w8, [x0, #0x19]; ret] | VI: Khởi đầu hàm AArch64 [and w8, w1, #1; strb w8, [x0, #0x19]; ret]
uint64_t fde_sub_058908(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x39006408ULL) << 32) | 0x12000028ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058908ULL;
}

// FDE #0864 | PC: 0x058914..0x058938 (36 B) | Symbol: _ZN4lynx6animax19AnimaXPlayerBuilder10SetAbilityENSt6__ndk110shared_ptrINS0_13AnimaXAbilityEEE
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; ldp x8, x9, [x1]; stp xzr, xzr, [x1]; bl #0x8e7ac] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; ldp x8, x9, [x1]; stp xzr, xzr, [x1]; bl #0x8e7ac]
uint64_t fde_sub_058914(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9402428ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058914ULL;
}

// FDE #0865 | PC: 0x058938..0x058954 (28 B) | Symbol: _ZN4lynx6animax19AnimaXPlayerBuilder17SetResourceLoaderENSt6__ndk110shared_ptrINS0_6LoaderINS0_15ResourceRequestENS0_16ResourceResponseEEEEE
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x30; bl #0x4c7e0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x30; bl #0x4c7e0]
uint64_t fde_sub_058938(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058938ULL;
}

// FDE #0866 | PC: 0x058954..0x058970 (28 B) | Symbol: _ZN4lynx6animax19AnimaXPlayerBuilder14SetUnzipLoaderENSt6__ndk110shared_ptrINS0_6LoaderINS0_12UnzipRequestENS0_13UnzipResponseEEEEE
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x40; bl #0x4c7e0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x40; bl #0x4c7e0]
uint64_t fde_sub_058954(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058954ULL;
}

// FDE #0867 | PC: 0x058970..0x05898c (28 B) | Symbol: _ZN4lynx6animax19AnimaXPlayerBuilder16AddEventListenerENS_4base15MoveOnlyClosureIvJPNS0_12AnimaXPlayerEKNS0_5EventERKNSt6__ndk13mapINS8_12basic_stringIcNS8_11char_traitsIcEENS8_9allocatorIcEEEENS0_15EventParamValueENS8_4lessISF_EENSD_INS8_4pairIKSF_SG_EEEEEEEEE
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x50; bl #0x4fa7c] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x50; bl #0x4fa7c]
uint64_t fde_sub_058970(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058970ULL;
}

// FDE #0868 | PC: 0x05898c..0x058a28 (156 B) | Symbol: _ZN4lynx6animax19AnimaXPlayerBuilder5BuildEv
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x0]
uint64_t fde_sub_05898c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05898CULL;
}

// FDE #0869 | PC: 0x058a28..0x058a48 (32 B) | Symbol: sub_058a28
// EN: AArch64 prologue [cbz x0, #0x58a44; stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x93850] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x58a44; stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x93850]
uint64_t fde_sub_058a28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BF7BF3ULL) << 32) | 0xB40000E0ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058A28ULL;
}

// FDE #0870 | PC: 0x058a48..0x058a50 (8 B) | Symbol: sub_058a48
// EN: AArch64 prologue [ldr x0, [x0, #0x18]; b #0x58a28] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x18]; b #0x58a28]
uint64_t fde_sub_058a48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF7ULL) << 32) | 0xF9400C00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058A48ULL;
}

// FDE #0871 | PC: 0x058a50..0x058b5c (268 B) | Symbol: sub_058a50
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x99000; add x8, x8, #0xa10] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x99000; add x8, x8, #0xa10]
uint64_t fde_sub_058a50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058A50ULL;
}

// FDE #0872 | PC: 0x058b5c..0x058be0 (132 B) | Symbol: sub_058b5c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x99000; add x8, x8, #0xa10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x99000; add x8, x8, #0xa10; mov x19, x0]
uint64_t fde_sub_058b5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB0000208ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058B5CULL;
}

// FDE #0873 | PC: 0x058be0..0x058bf8 (24 B) | Symbol: sub_058be0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x58b5c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x58b5c; mov x0, x19]
uint64_t fde_sub_058be0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058BE0ULL;
}

// FDE #0874 | PC: 0x058bf8..0x058c00 (8 B) | Symbol: sub_058bf8
// EN: AArch64 prologue [add x0, x0, #0x98; b #0x4ca14] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x98; b #0x4ca14]
uint64_t fde_sub_058bf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFCF86ULL) << 32) | 0x91026000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058BF8ULL;
}

// FDE #0875 | PC: 0x058c00..0x058c08 (8 B) | Symbol: sub_058c00
// EN: AArch64 prologue [add x1, x0, #0xa0; b #0x903f4] | VI: Khởi đầu hàm AArch64 [add x1, x0, #0xa0; b #0x903f4]
uint64_t fde_sub_058c00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400DDFCULL) << 32) | 0x91028001ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058C00ULL;
}

// FDE #0876 | PC: 0x058c08..0x058d08 (256 B) | Symbol: sub_058c08
// EN: AArch64 prologue [sub sp, sp, #0x50; str d8, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str d8, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_058c08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0013E8ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058C08ULL;
}

// FDE #0877 | PC: 0x058d08..0x058d10 (8 B) | Symbol: sub_058d08
// EN: AArch64 prologue [mov x1, xzr; b #0x58d10] | VI: Khởi đầu hàm AArch64 [mov x1, xzr; b #0x58d10]
uint64_t fde_sub_058d08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xAA1F03E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058D08ULL;
}

// FDE #0878 | PC: 0x058d10..0x058dcc (188 B) | Symbol: sub_058d10
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8dcc8; cbz x19, #0x58da4] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8dcc8; cbz x19, #0x58da4]
uint64_t fde_sub_058d10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058D10ULL;
}

// FDE #0879 | PC: 0x058dcc..0x058dd4 (8 B) | Symbol: sub_058dcc
// EN: AArch64 prologue [mov x1, xzr; b #0x58f04] | VI: Khởi đầu hàm AArch64 [mov x1, xzr; b #0x58f04]
uint64_t fde_sub_058dcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400004DULL) << 32) | 0xAA1F03E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058DCCULL;
}

// FDE #0880 | PC: 0x058dd4..0x058ddc (8 B) | Symbol: sub_058dd4
// EN: AArch64 prologue [mov x1, xzr; b #0x58edc] | VI: Khởi đầu hàm AArch64 [mov x1, xzr; b #0x58edc]
uint64_t fde_sub_058dd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000041ULL) << 32) | 0xAA1F03E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058DD4ULL;
}

// FDE #0881 | PC: 0x058ddc..0x058de4 (8 B) | Symbol: sub_058ddc
// EN: AArch64 prologue [mov x1, xzr; b #0x58e50] | VI: Khởi đầu hàm AArch64 [mov x1, xzr; b #0x58e50]
uint64_t fde_sub_058ddc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400001CULL) << 32) | 0xAA1F03E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058DDCULL;
}

// FDE #0882 | PC: 0x058de4..0x058e20 (60 B) | Symbol: sub_058de4
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x21, [x0]; cbz x21, #0x58e18] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x21, [x0]; cbz x21, #0x58e18]
uint64_t fde_sub_058de4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058DE4ULL;
}

// FDE #0883 | PC: 0x058e20..0x058e50 (48 B) | Symbol: sub_058e20
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8dff0; cbz x19, #0x58e48; add x0, x19, #0x10] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8dff0; cbz x19, #0x58e48; add x0, x19, #0x10]
uint64_t fde_sub_058e20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400D473ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058E20ULL;
}

// FDE #0884 | PC: 0x058e50..0x058e94 (68 B) | Symbol: sub_058e50
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8dcc8; cbz x19, #0x58e7c] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8dcc8; cbz x19, #0x58e7c]
uint64_t fde_sub_058e50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058E50ULL;
}

// FDE #0885 | PC: 0x058e94..0x058e9c (8 B) | Symbol: sub_058e94
// EN: AArch64 prologue [mov x1, xzr; b #0x58e9c] | VI: Khởi đầu hàm AArch64 [mov x1, xzr; b #0x58e9c]
uint64_t fde_sub_058e94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xAA1F03E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058E94ULL;
}

// FDE #0886 | PC: 0x058e9c..0x058edc (64 B) | Symbol: sub_058e9c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8dcc8; cbz x19, #0x58ed4; add x0, x19, #0x18] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8dcc8; cbz x19, #0x58ed4; add x0, x19, #0x18]
uint64_t fde_sub_058e9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400D38AULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058E9CULL;
}

// FDE #0887 | PC: 0x058edc..0x058f04 (40 B) | Symbol: sub_058edc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8dcc8; cbz x19, #0x58efc; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8dcc8; cbz x19, #0x58efc; mov x0, x19]
uint64_t fde_sub_058edc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400D37AULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058EDCULL;
}

// FDE #0888 | PC: 0x058f04..0x058f4c (72 B) | Symbol: sub_058f04
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8dcc8; cbz x19, #0x58f44; add x0, x19, #0x20] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8dcc8; cbz x19, #0x58f44; add x0, x19, #0x20]
uint64_t fde_sub_058f04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400D370ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058F04ULL;
}

// FDE #0889 | PC: 0x058f4c..0x059138 (492 B) | Symbol: sub_058f4c
// EN: AArch64 prologue [sub sp, sp, #0x190; stp x28, x22, [sp, #0x160]; stp x21, x20, [sp, #0x170]; stp x19, x30, [sp, #0x180]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x190; stp x28, x22, [sp, #0x160]; stp x21, x20, [sp, #0x170]; stp x19, x30, [sp, #0x180]]
uint64_t fde_sub_058f4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9165BFCULL) << 32) | 0xD10643FFULL;
    const uint64_t kPcRange = 0x01ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058F4CULL;
}

// FDE #0890 | PC: 0x059138..0x059190 (88 B) | Symbol: sub_059138
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8e990] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8e990]
uint64_t fde_sub_059138(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90253F5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059138ULL;
}

// FDE #0891 | PC: 0x059190..0x059198 (8 B) | Symbol: sub_059190
// EN: AArch64 prologue [ldr x1, [x1]; b #0x51254] | VI: Khởi đầu hàm AArch64 [ldr x1, [x1]; b #0x51254]
uint64_t fde_sub_059190(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFE030ULL) << 32) | 0xF9400021ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059190ULL;
}

// FDE #0892 | PC: 0x059198..0x059588 (1008 B) | Symbol: sub_059198
// EN: AArch64 prologue [sub sp, sp, #0x190; stp d9, d8, [sp, #0x140]; str x28, [sp, #0x150]; stp x23, x22, [sp, #0x160]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x190; stp d9, d8, [sp, #0x140]; str x28, [sp, #0x150]; stp x23, x22, [sp, #0x160]]
uint64_t fde_sub_059198(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D1423E9ULL) << 32) | 0xD10643FFULL;
    const uint64_t kPcRange = 0x03F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059198ULL;
}

// FDE #0893 | PC: 0x059588..0x0595a4 (28 B) | Symbol: sub_059588
// EN: AArch64 prologue [cbz x0, #0x595a0; ldr x8, [x0, #0x20]; ldr d0, [x0, #0xb8]; ldr w1, [x0, #0xc0]] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x595a0; ldr x8, [x0, #0x20]; ldr d0, [x0, #0xb8]; ldr w1, [x0, #0xc0]]
uint64_t fde_sub_059588(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401008ULL) << 32) | 0xB40000C0ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059588ULL;
}

// FDE #0894 | PC: 0x0595a4..0x0595b4 (16 B) | Symbol: sub_0595a4
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0xa70; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0xa70; b #0x8d518]
uint64_t fde_sub_0595a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0595A4ULL;
}

// FDE #0895 | PC: 0x0595b4..0x0595cc (24 B) | Symbol: sub_0595b4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x595a4; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x595a4; mov x0, x19]
uint64_t fde_sub_0595b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0595B4ULL;
}

// FDE #0896 | PC: 0x0595cc..0x0595d8 (12 B) | Symbol: sub_0595cc
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x59588] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x59588]
uint64_t fde_sub_0595cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400900ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0595CCULL;
}

// FDE #0897 | PC: 0x0595d8..0x0596b0 (216 B) | Symbol: sub_0595d8
// EN: AArch64 prologue [mov x2, x30; bl #0x8d63c; mov x30, x2; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d63c; mov x30, x2; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_0595d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400D018ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0595D8ULL;
}

// FDE #0898 | PC: 0x0596b0..0x0596bc (12 B) | Symbol: sub_0596b0
// EN: AArch64 prologue [cbz x0, #0x596b8; b #0x51858; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x596b8; b #0x51858; ret]
uint64_t fde_sub_0596b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFE069ULL) << 32) | 0xB4000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0596B0ULL;
}

// FDE #0899 | PC: 0x0596bc..0x0596cc (16 B) | Symbol: sub_0596bc
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0xa98; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0xa98; b #0x8d518]
uint64_t fde_sub_0596bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0596BCULL;
}

// FDE #0900 | PC: 0x0596cc..0x0596e4 (24 B) | Symbol: sub_0596cc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x596bc; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x596bc; mov x0, x19]
uint64_t fde_sub_0596cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0596CCULL;
}

// FDE #0901 | PC: 0x0596e4..0x0596f4 (16 B) | Symbol: sub_0596e4
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x596b0] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x596b0]
uint64_t fde_sub_0596e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400CFDBULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0596E4ULL;
}

// FDE #0902 | PC: 0x0596f4..0x059724 (48 B) | Symbol: sub_0596f4
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; cbz x19, #0x5971c] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; cbz x19, #0x5971c]
uint64_t fde_sub_0596f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0596F4ULL;
}

// FDE #0903 | PC: 0x059724..0x05973c (24 B) | Symbol: sub_059724
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8ddf8; bl #0x44830; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8ddf8; bl #0x44830; mov x0, x19]
uint64_t fde_sub_059724(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400D1B4ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059724ULL;
}

// FDE #0904 | PC: 0x05973c..0x05974c (16 B) | Symbol: sub_05973c
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0xa48; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0xa48; b #0x8d518]
uint64_t fde_sub_05973c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05973CULL;
}

// FDE #0905 | PC: 0x05974c..0x059764 (24 B) | Symbol: sub_05974c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5973c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5973c; mov x0, x19]
uint64_t fde_sub_05974c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05974CULL;
}

// FDE #0906 | PC: 0x059764..0x059774 (16 B) | Symbol: sub_059764
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x59138] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x59138]
uint64_t fde_sub_059764(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400CFBBULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059764ULL;
}

// FDE #0907 | PC: 0x059774..0x0597f8 (132 B) | Symbol: sub_059774
// EN: AArch64 prologue [sub sp, sp, #0x160; stp x28, x22, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; stp x28, x22, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]]
uint64_t fde_sub_059774(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9135BFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059774ULL;
}

// FDE #0908 | PC: 0x0597f8..0x0598b8 (192 B) | Symbol: sub_0597f8
// EN: AArch64 prologue [sub sp, sp, #0x170; str x28, [sp, #0x140]; stp x21, x20, [sp, #0x150]; stp x19, x30, [sp, #0x160]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; str x28, [sp, #0x140]; stp x21, x20, [sp, #0x150]; stp x19, x30, [sp, #0x160]]
uint64_t fde_sub_0597f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900A3FCULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0597F8ULL;
}

// FDE #0909 | PC: 0x0598b8..0x0599d4 (284 B) | Symbol: sub_0598b8
// EN: AArch64 prologue [sub sp, sp, #0x180; stp x28, x22, [sp, #0x150]; stp x21, x20, [sp, #0x160]; stp x19, x30, [sp, #0x170]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x180; stp x28, x22, [sp, #0x150]; stp x21, x20, [sp, #0x160]; stp x19, x30, [sp, #0x170]]
uint64_t fde_sub_0598b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9155BFCULL) << 32) | 0xD10603FFULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0598B8ULL;
}

// FDE #0910 | PC: 0x0599d4..0x059a30 (92 B) | Symbol: sub_0599d4
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; bl #0x8f760; mov x9, x1] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; bl #0x8f760; mov x9, x1]
uint64_t fde_sub_0599d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0599D4ULL;
}

// FDE #0911 | PC: 0x059a30..0x059a50 (32 B) | Symbol: sub_059a30
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x1, x2; mov x19, x0; add x0, x0, #0x18] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x1, x2; mov x19, x0; add x0, x0, #0x18]
uint64_t fde_sub_059a30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0203E1ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059A30ULL;
}

// FDE #0912 | PC: 0x059a50..0x059d10 (704 B) | Symbol: sub_059a50
// EN: AArch64 prologue [sub sp, sp, #0x90; stp d11, d10, [sp, #0x40]; stp d9, d8, [sp, #0x50]; str x22, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp d11, d10, [sp, #0x40]; stp d9, d8, [sp, #0x50]; str x22, [sp, #0x60]]
uint64_t fde_sub_059a50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D042BEBULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x02C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059A50ULL;
}

// FDE #0913 | PC: 0x059d10..0x059d20 (16 B) | Symbol: sub_059d10
// EN: AArch64 prologue [cbz x0, #0x59d1c; mov w1, #0xa; b #0x514b8; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x59d1c; mov w1, #0xa; b #0x514b8; ret]
uint64_t fde_sub_059d10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800141ULL) << 32) | 0xB4000060ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059D10ULL;
}

// FDE #0914 | PC: 0x059d20..0x059d30 (16 B) | Symbol: sub_059d20
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0xac0; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0xac0; b #0x8d518]
uint64_t fde_sub_059d20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x90000209ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059D20ULL;
}

// FDE #0915 | PC: 0x059d30..0x059d48 (24 B) | Symbol: sub_059d30
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x59d20; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x59d20; mov x0, x19]
uint64_t fde_sub_059d30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059D30ULL;
}

// FDE #0916 | PC: 0x059d48..0x059d54 (12 B) | Symbol: sub_059d48
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x59d10] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x59d10]
uint64_t fde_sub_059d48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400900ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059D48ULL;
}

// FDE #0917 | PC: 0x059d54..0x059f50 (508 B) | Symbol: sub_059d54
// EN: AArch64 prologue [stp d11, d10, [sp, #-0x50]!; stp d9, d8, [sp, #0x10]; stp x28, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp d11, d10, [sp, #-0x50]!; stp d9, d8, [sp, #0x10]; stp x28, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]]
uint64_t fde_sub_059d54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D0123E9ULL) << 32) | 0x6DBB2BEBULL;
    const uint64_t kPcRange = 0x01FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059D54ULL;
}

// FDE #0918 | PC: 0x059f50..0x059fd0 (128 B) | Symbol: sub_059f50
// EN: AArch64 prologue [sub sp, sp, #0x60; str d8, [sp, #0x20]; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str d8, [sp, #0x20]; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]]
uint64_t fde_sub_059f50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0013E8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059F50ULL;
}

// FDE #0919 | PC: 0x059fd0..0x059fdc (12 B) | Symbol: sub_059fd0
// EN: AArch64 prologue [cbz x0, #0x59fd8; b #0x514e0; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x59fd8; b #0x514e0; ret]
uint64_t fde_sub_059fd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFDD43ULL) << 32) | 0xB4000040ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059FD0ULL;
}

// FDE #0920 | PC: 0x059fdc..0x059ff4 (24 B) | Symbol: sub_059fdc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x4b524; ldr x0, [x19, #8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8db1c; bl #0x4b524; ldr x0, [x19, #8]]
uint64_t fde_sub_059fdc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400CECFULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059FDCULL;
}

// FDE #0921 | PC: 0x059ff4..0x05a004 (16 B) | Symbol: sub_059ff4
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0xae8; str x8, [x0], #8; b #0x59fdc] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0xae8; str x8, [x0], #8; b #0x59fdc]
uint64_t fde_sub_059ff4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x912BA108ULL) << 32) | 0x90000208ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059FF4ULL;
}

// FDE #0922 | PC: 0x05a004..0x05a01c (24 B) | Symbol: sub_05a004
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x59ff4; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x59ff4; mov x0, x19]
uint64_t fde_sub_05a004(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A004ULL;
}

// FDE #0923 | PC: 0x05a01c..0x05a02c (16 B) | Symbol: sub_05a01c
// EN: AArch64 prologue [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x59fd0] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d654; mov x30, x2; b #0x59fd0]
uint64_t fde_sub_05a01c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400CD8DULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A01CULL;
}

// FDE #0924 | PC: 0x05a02c..0x05a0f8 (204 B) | Symbol: sub_05a02c
// EN: AArch64 prologue [sub sp, sp, #0x50; str d8, [sp, #0x10]; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str d8, [sp, #0x10]; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]]
uint64_t fde_sub_05a02c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD000BE8ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A02CULL;
}

// FDE #0925 | PC: 0x05a0f8..0x05a108 (16 B) | Symbol: sub_05a0f8
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0xb10; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0xb10; b #0x8d518]
uint64_t fde_sub_05a0f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00001E9ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A0F8ULL;
}

// FDE #0926 | PC: 0x05a108..0x05a120 (24 B) | Symbol: sub_05a108
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5a0f8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5a0f8; mov x0, x19]
uint64_t fde_sub_05a108(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A108ULL;
}

// FDE #0927 | PC: 0x05a120..0x05a1fc (220 B) | Symbol: sub_05a120
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x23, x22, [sp, #0x60]; stp x21, x20, [sp, #0x70]; stp x19, x30, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x23, x22, [sp, #0x60]; stp x21, x20, [sp, #0x70]; stp x19, x30, [sp, #0x80]]
uint64_t fde_sub_05a120(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9065BF7ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A120ULL;
}

// FDE #0928 | PC: 0x05a1fc..0x05a294 (152 B) | Symbol: sub_05a1fc
// EN: AArch64 prologue [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]]
uint64_t fde_sub_05a1fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9009BFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A1FCULL;
}

// FDE #0929 | PC: 0x05a294..0x05a3c8 (308 B) | Symbol: sub_05a294
// EN: AArch64 prologue [sub sp, sp, #0x70; str x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]]
uint64_t fde_sub_05a294(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F6ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0134ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A294ULL;
}

// FDE #0930 | PC: 0x05a3c8..0x05a3d8 (16 B) | Symbol: sub_05a3c8
// EN: AArch64 prologue [cbz x0, #0x5a3d4; mov w1, #4; b #0x514b8; ret] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x5a3d4; mov w1, #4; b #0x514b8; ret]
uint64_t fde_sub_05a3c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800081ULL) << 32) | 0xB4000060ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A3C8ULL;
}

// FDE #0931 | PC: 0x05a3d8..0x05a3e8 (16 B) | Symbol: sub_05a3d8
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0xb38; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0xb38; b #0x8d518]
uint64_t fde_sub_05a3d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00001E9ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A3D8ULL;
}

// FDE #0932 | PC: 0x05a3e8..0x05a400 (24 B) | Symbol: sub_05a3e8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5a3d8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5a3d8; mov x0, x19]
uint64_t fde_sub_05a3e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A3E8ULL;
}

// FDE #0933 | PC: 0x05a400..0x05a40c (12 B) | Symbol: sub_05a400
// EN: AArch64 prologue [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x5a3c8] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; b #0x5a3c8]
uint64_t fde_sub_05a400(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400900ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A400ULL;
}

// FDE #0934 | PC: 0x05a40c..0x05a478 (108 B) | Symbol: sub_05a40c
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x19, x30, [sp, #0x20]; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x19, x30, [sp, #0x20]; mrs x19, tpidr_el0; ldr x8, [x19, #0x28]]
uint64_t fde_sub_05a40c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9027BF3ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A40CULL;
}

// FDE #0935 | PC: 0x05a478..0x05a4b0 (56 B) | Symbol: sub_05a478
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; bl #0x8e184; ldr x8, [x8, #0x18]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; bl #0x8e184; ldr x8, [x8, #0x18]]
uint64_t fde_sub_05a478(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A478ULL;
}

// FDE #0936 | PC: 0x05a4b0..0x05a4e8 (56 B) | Symbol: sub_05a4b0
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; bl #0x8e184; ldr x8, [x8, #0x20]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; bl #0x8e184; ldr x8, [x8, #0x20]]
uint64_t fde_sub_05a4b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A4B0ULL;
}

// FDE #0937 | PC: 0x05a4e8..0x05a520 (56 B) | Symbol: sub_05a4e8
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; bl #0x8e184; ldr x8, [x8, #0x28]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; bl #0x8e184; ldr x8, [x8, #0x28]]
uint64_t fde_sub_05a4e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A4E8ULL;
}

// FDE #0938 | PC: 0x05a520..0x05a570 (80 B) | Symbol: _ZN4lynx6animax13AnimaXSurface18CreateAnimaXCanvasEPN5skity6CanvasEiiPNS2_10GPUContextE
// EN: AArch64 prologue [str x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_05a520(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xF81C0FF8ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A520ULL;
}

// FDE #0939 | PC: 0x05a570..0x05a60c (156 B) | Symbol: _ZN4lynx6animax12VSyncMonitor17AsyncRequestVSyncENS_4base15MoveOnlyClosureIvJlEEE
// EN: AArch64 prologue [sub sp, sp, #0x40; str x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_05a570(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A570ULL;
}

// FDE #0940 | PC: 0x05a60c..0x05a61c (16 B) | Symbol: sub_05a60c
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0xb60; b #0x8fa40] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0xb60; b #0x8fa40]
uint64_t fde_sub_05a60c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00001E9ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A60CULL;
}

// FDE #0941 | PC: 0x05a61c..0x05a634 (24 B) | Symbol: sub_05a61c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5a60c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5a60c; mov x0, x19]
uint64_t fde_sub_05a61c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A61CULL;
}

// FDE #0942 | PC: 0x05a634..0x05a6d8 (164 B) | Symbol: sub_05a634
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_05a634(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9025BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A634ULL;
}

// FDE #0943 | PC: 0x05a6d8..0x05a6e8 (16 B) | Symbol: sub_05a6d8
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0xb88; b #0x8fa40] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x99000; add x9, x9, #0xb88; b #0x8fa40]
uint64_t fde_sub_05a6d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00001E9ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A6D8ULL;
}

// FDE #0944 | PC: 0x05a6e8..0x05a700 (24 B) | Symbol: sub_05a6e8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5a6d8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5a6d8; mov x0, x19]
uint64_t fde_sub_05a6e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A6E8ULL;
}

// FDE #0945 | PC: 0x05a700..0x05a75c (92 B) | Symbol: sub_05a700
// EN: AArch64 prologue [sub sp, sp, #0x30; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x0]
uint64_t fde_sub_05a700(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A700ULL;
}

// FDE #0946 | PC: 0x05a75c..0x05a784 (40 B) | Symbol: sub_05a75c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; bl #0x8ee48; ldr x8, [x8, #0xc00]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; bl #0x8ee48; ldr x8, [x8, #0xc00]]
uint64_t fde_sub_05a75c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000208ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A75CULL;
}

// FDE #0947 | PC: 0x05a784..0x05a788 (4 B) | Symbol: _ZN4lynx6animax13VideoShaderGLD0Ev
// EN: AArch64 prologue [brk #1] | VI: Khởi đầu hàm AArch64 [brk #1]
uint64_t fde_sub_05a784(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD10183FFULL) << 32) | 0xD4200020ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A784ULL;
}

// FDE #0948 | PC: 0x05a788..0x05a88c (260 B) | Symbol: sub_05a788
// EN: AArch64 prologue [sub sp, sp, #0x60; mov x4, x30; bl #0x91e38; mov x30, x4] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; mov x4, x30; bl #0x91e38; mov x30, x4]
uint64_t fde_sub_05a788(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E4ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A788ULL;
}

// FDE #0949 | PC: 0x05a88c..0x05a93c (176 B) | Symbol: sub_05a88c
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_05a88c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A88CULL;
}

// FDE #0950 | PC: 0x05a93c..0x05a9cc (144 B) | Symbol: sub_05a93c
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8d614] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8d614]
uint64_t fde_sub_05a93c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A93CULL;
}

// FDE #0951 | PC: 0x05a9cc..0x05a9f0 (36 B) | Symbol: sub_05a9cc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x99000; add x8, x8, #0xcc8; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x99000; add x8, x8, #0xcc8; mov x19, x0]
uint64_t fde_sub_05a9cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00001E8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A9CCULL;
}

// FDE #0952 | PC: 0x05a9f0..0x05aa2c (60 B) | Symbol: sub_05a9f0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x99000; add x8, x8, #0xbe0; bl #0x92c14] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x99000; add x8, x8, #0xbe0; bl #0x92c14]
uint64_t fde_sub_05a9f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00001E8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A9F0ULL;
}

// FDE #0953 | PC: 0x05aa2c..0x05aa44 (24 B) | Symbol: sub_05aa2c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5a9f0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5a9f0; mov x0, x19]
uint64_t fde_sub_05aa2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AA2CULL;
}

// FDE #0954 | PC: 0x05aa44..0x05aa68 (36 B) | Symbol: sub_05aa44
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; ldr x0, [x0, #0x68]; cbz x0, #0x5aa5c; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; ldr x0, [x0, #0x68]; cbz x0, #0x5aa5c; ldr x8, [x0]]
uint64_t fde_sub_05aa44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9403400ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AA44ULL;
}

// FDE #0955 | PC: 0x05aa68..0x05ab10 (168 B) | Symbol: sub_05aa68
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x25, x24, [sp, #0x30]; stp x23, x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x25, x24, [sp, #0x30]; stp x23, x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]]
uint64_t fde_sub_05aa68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90363F9ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AA68ULL;
}

// FDE #0956 | PC: 0x05ab10..0x05ab18 (8 B) | Symbol: sub_05ab10
// EN: AArch64 prologue [add x0, x0, #8; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #8; ret]
uint64_t fde_sub_05ab10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x91002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AB10ULL;
}

// FDE #0957 | PC: 0x05ab18..0x05acc4 (428 B) | Symbol: sub_05ab18
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp x25, x24, [sp, #0x60]; stp x23, x22, [sp, #0x70]; stp x21, x20, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp x25, x24, [sp, #0x60]; stp x23, x22, [sp, #0x70]; stp x21, x20, [sp, #0x80]]
uint64_t fde_sub_05ab18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90663F9ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x01ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AB18ULL;
}

// FDE #0958 | PC: 0x05acc4..0x05ad88 (196 B) | Symbol: sub_05acc4
// EN: AArch64 prologue [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_05acc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF6ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05ACC4ULL;
}

// FDE #0959 | PC: 0x05ad88..0x05ad90 (8 B) | Symbol: sub_05ad88
// EN: AArch64 prologue [mov w0, #5; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #5; ret]
uint64_t fde_sub_05ad88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x528000A0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AD88ULL;
}

// FDE #0960 | PC: 0x05ad90..0x05ae78 (232 B) | Symbol: sub_05ad90
// EN: AArch64 prologue [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldrb w8, [x0, #0x20]] | VI: Khởi đầu hàm AArch64 [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldrb w8, [x0, #0x20]]
uint64_t fde_sub_05ad90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xA9BD5BF7ULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AD90ULL;
}

// FDE #0961 | PC: 0x05ae78..0x05af2c (180 B) | Symbol: sub_05ae78
// EN: AArch64 prologue [str x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_05ae78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xF81C0FF8ULL;
    const uint64_t kPcRange = 0x00B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AE78ULL;
}

// FDE #0962 | PC: 0x05af2c..0x05afc0 (148 B) | Symbol: sub_05af2c
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr x8, [x0, #0x48]] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr x8, [x0, #0x48]]
uint64_t fde_sub_05af2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AF2CULL;
}

// FDE #0963 | PC: 0x05afc0..0x05afc8 (8 B) | Symbol: sub_05afc0
// EN: AArch64 prologue [sub x0, x0, #0x28; b #0x5a9f0] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x28; b #0x5a9f0]
uint64_t fde_sub_05afc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFE8BULL) << 32) | 0xD100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AFC0ULL;
}

// FDE #0964 | PC: 0x05afc8..0x05afd0 (8 B) | Symbol: sub_05afc8
// EN: AArch64 prologue [sub x0, x0, #0x28; b #0x5aa2c] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x28; b #0x5aa2c]
uint64_t fde_sub_05afc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFE98ULL) << 32) | 0xD100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AFC8ULL;
}

// FDE #0965 | PC: 0x05afd0..0x05afdc (12 B) | Symbol: sub_05afd0
// EN: AArch64 prologue [cbz x1, #0x5afd8; b #0x8c248; ret] | VI: Khởi đầu hàm AArch64 [cbz x1, #0x5afd8; b #0x8c248; ret]
uint64_t fde_sub_05afd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400C49DULL) << 32) | 0xB4000041ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AFD0ULL;
}

// FDE #0966 | PC: 0x05afdc..0x05b030 (84 B) | Symbol: sub_05afdc
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_05afdc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9035BF7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AFDCULL;
}

// FDE #0967 | PC: 0x05b030..0x05b04c (28 B) | Symbol: sub_05b030
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x90c98; bl #0x5b074] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x90c98; bl #0x5b074]
uint64_t fde_sub_05b030(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B030ULL;
}

// FDE #0968 | PC: 0x05b04c..0x05b074 (40 B) | Symbol: sub_05b04c
// EN: AArch64 prologue [ldp x8, x9, [x0, #8]; cmp x8, x9; b.eq #0x5b064; sub x9, x9, #8] | VI: Khởi đầu hàm AArch64 [ldp x8, x9, [x0, #8]; cmp x8, x9; b.eq #0x5b064; sub x9, x9, #8]
uint64_t fde_sub_05b04c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xA940A408ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B04CULL;
}

// FDE #0969 | PC: 0x05b074..0x05b0a0 (44 B) | Symbol: sub_05b074
// EN: AArch64 prologue [ldr x10, [x2]; mov x8, x2; sub x2, x1, x0; mov x9, x0] | VI: Khởi đầu hàm AArch64 [ldr x10, [x2]; mov x8, x2; sub x2, x1, x0; mov x9, x0]
uint64_t fde_sub_05b074(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0203E8ULL) << 32) | 0xF940004AULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B074ULL;
}

// FDE #0970 | PC: 0x05b0a0..0x05b0f4 (84 B) | Symbol: sub_05b0a0
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_05b0a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9035BF7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B0A0ULL;
}

// FDE #0971 | PC: 0x05b0f4..0x05b104 (16 B) | Symbol: sub_05b0f4
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0xca8; str x8, [x0], #8; b #0x49870] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0xca8; str x8, [x0], #8; b #0x49870]
uint64_t fde_sub_05b0f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9132A108ULL) << 32) | 0xD00001E8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B0F4ULL;
}

// FDE #0972 | PC: 0x05b104..0x05b11c (24 B) | Symbol: sub_05b104
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5b0f4; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5b0f4; mov x0, x19]
uint64_t fde_sub_05b104(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B104ULL;
}

// FDE #0973 | PC: 0x05b11c..0x05b144 (40 B) | Symbol: sub_05b11c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; ldr x1, [x0]; cbz x1, #0x5b13c; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; ldr x1, [x0]; cbz x1, #0x5b13c; mov x19, x0]
uint64_t fde_sub_05b11c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400001ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B11CULL;
}

// FDE #0974 | PC: 0x05b144..0x05b154 (16 B) | Symbol: sub_05b144
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0xcc8; str x8, [x0], #8; b #0x46c54] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0xcc8; str x8, [x0], #8; b #0x46c54]
uint64_t fde_sub_05b144(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91332108ULL) << 32) | 0xD00001E8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B144ULL;
}

// FDE #0975 | PC: 0x05b154..0x05b158 (4 B) | Symbol: sub_05b154
// EN: AArch64 prologue [b #0x885a4] | VI: Khởi đầu hàm AArch64 [b #0x885a4]
uint64_t fde_sub_05b154(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9BE53F5ULL) << 32) | 0x1400B514ULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B154ULL;
}

// FDE #0976 | PC: 0x05b158..0x05b184 (44 B) | Symbol: sub_05b158
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x21, [x0, #8]; bl #0x8e454] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x21, [x0, #8]; bl #0x8e454]
uint64_t fde_sub_05b158(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B158ULL;
}

// FDE #0977 | PC: 0x05b184..0x05b1c8 (68 B) | Symbol: sub_05b184
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8e108] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8e108]
uint64_t fde_sub_05b184(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B184ULL;
}

// FDE #0978 | PC: 0x05b1c8..0x05b1f4 (44 B) | Symbol: sub_05b1c8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x68]; cbz x0, #0x5b1e0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x68]; cbz x0, #0x5b1e0]
uint64_t fde_sub_05b1c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B1C8ULL;
}

// FDE #0979 | PC: 0x05b1f4..0x05b26c (120 B) | Symbol: sub_05b1f4
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x99000; add x8, x8, #0xd60] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x99000; add x8, x8, #0xd60]
uint64_t fde_sub_05b1f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B1F4ULL;
}

// FDE #0980 | PC: 0x05b26c..0x05b288 (28 B) | Symbol: sub_05b26c
// EN: AArch64 prologue [adrp x8, #0x99000; add x8, x8, #0xd60; add x9, x8, #0x30; fmov d0, x8] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x99000; add x8, x8, #0xd60; add x9, x8, #0x30; fmov d0, x8]
uint64_t fde_sub_05b26c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91358108ULL) << 32) | 0xD00001E8ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B26CULL;
}

// FDE #0981 | PC: 0x05b288..0x05b2a0 (24 B) | Symbol: sub_05b288
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5b26c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5b26c; mov x0, x19]
uint64_t fde_sub_05b288(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B288ULL;
}

// FDE #0982 | PC: 0x05b2a0..0x05b2c0 (32 B) | Symbol: sub_05b2a0
// EN: AArch64 prologue [and w8, w1, #0xffff; cmp w8, #0xce; b.ne #0x5b2bc; ldr x8, [x0, #0x20]] | VI: Khởi đầu hàm AArch64 [and w8, w1, #0xffff; cmp w8, #0xce; b.ne #0x5b2bc; ldr x8, [x0, #0x20]]
uint64_t fde_sub_05b2a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7103391FULL) << 32) | 0x12003C28ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B2A0ULL;
}

// FDE #0983 | PC: 0x05b2c0..0x05b2c8 (8 B) | Symbol: sub_05b2c0
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5b26c] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5b26c]
uint64_t fde_sub_05b2c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFEAULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B2C0ULL;
}

// FDE #0984 | PC: 0x05b2c8..0x05b2d0 (8 B) | Symbol: sub_05b2c8
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5b288] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5b288]
uint64_t fde_sub_05b2c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFEFULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B2C8ULL;
}

// FDE #0985 | PC: 0x05b2d0..0x05b2d8 (8 B) | Symbol: sub_05b2d0
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5b2a0] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5b2a0]
uint64_t fde_sub_05b2d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF3ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B2D0ULL;
}

// FDE #0986 | PC: 0x05b2d8..0x05b2ec (20 B) | Symbol: sub_05b2d8
// EN: AArch64 prologue [mov x1, x0; ldr x0, [x0, #0x10]; cbz x0, #0x5b2e8; b #0x470b8] | VI: Khởi đầu hàm AArch64 [mov x1, x0; ldr x0, [x0, #0x10]; cbz x0, #0x5b2e8; b #0x470b8]
uint64_t fde_sub_05b2d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400800ULL) << 32) | 0xAA0003E1ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B2D8ULL;
}

// FDE #0987 | PC: 0x05b2ec..0x05b3a4 (184 B) | Symbol: sub_05b2ec
// EN: AArch64 prologue [sub sp, sp, #0x40; str d8, [sp, #0x10]; str x22, [sp, #0x18]; stp x21, x20, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str d8, [sp, #0x10]; str x22, [sp, #0x18]; stp x21, x20, [sp, #0x20]]
uint64_t fde_sub_05b2ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD000BE8ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B2ECULL;
}

// FDE #0988 | PC: 0x05b3a4..0x05b3ac (8 B) | Symbol: sub_05b3a4
// EN: AArch64 prologue [mov x1, xzr; b #0x5b3ac] | VI: Khởi đầu hàm AArch64 [mov x1, xzr; b #0x5b3ac]
uint64_t fde_sub_05b3a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xAA1F03E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B3A4ULL;
}

// FDE #0989 | PC: 0x05b3ac..0x05b3d4 (40 B) | Symbol: sub_05b3ac
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8dcc8; cbz x19, #0x5b3cc; ldr x0, [x19, #8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8dcc8; cbz x19, #0x5b3cc; ldr x0, [x19, #8]]
uint64_t fde_sub_05b3ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400CA46ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B3ACULL;
}

// FDE #0990 | PC: 0x05b3d4..0x05b3fc (40 B) | Symbol: sub_05b3d4
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; mov x8, x0; ldr x0, [x0, #0x10]; cbz x0, #0x5b3f0] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; mov x8, x0; ldr x0, [x0, #0x10]; cbz x0, #0x5b3f0]
uint64_t fde_sub_05b3d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003E8ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B3D4ULL;
}

// FDE #0991 | PC: 0x05b3fc..0x05b4e8 (236 B) | Symbol: sub_05b3fc
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; adrp x8, #0x99000] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; adrp x8, #0x99000]
uint64_t fde_sub_05b3fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B3FCULL;
}

// FDE #0992 | PC: 0x05b4e8..0x05b508 (32 B) | Symbol: sub_05b4e8
// EN: AArch64 prologue [mov x8, x0; ldr x0, [x0, #8]; adrp x9, #0x99000; add x9, x9, #0xdc8] | VI: Khởi đầu hàm AArch64 [mov x8, x0; ldr x0, [x0, #8]; adrp x9, #0x99000; add x9, x9, #0xdc8]
uint64_t fde_sub_05b4e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400400ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B4E8ULL;
}

// FDE #0993 | PC: 0x05b508..0x05b520 (24 B) | Symbol: sub_05b508
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5b4e8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5b4e8; mov x0, x19]
uint64_t fde_sub_05b508(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B508ULL;
}

// FDE #0994 | PC: 0x05b520..0x05b574 (84 B) | Symbol: sub_05b520
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; cbz x0, #0x5b56c; bl #0x8ee48; cbz x0, #0x5b534] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; cbz x0, #0x5b56c; bl #0x8ee48; cbz x0, #0x5b534]
uint64_t fde_sub_05b520(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000240ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B520ULL;
}

// FDE #0995 | PC: 0x05b574..0x05b6c8 (340 B) | Symbol: sub_05b574
// EN: AArch64 prologue [stp d11, d10, [sp, #-0x40]!; stp d9, d8, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp d11, d10, [sp, #-0x40]!; stp d9, d8, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_05b574(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D0123E9ULL) << 32) | 0x6DBC2BEBULL;
    const uint64_t kPcRange = 0x0154ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B574ULL;
}

// FDE #0996 | PC: 0x05b6c8..0x05b8bc (500 B) | Symbol: sub_05b6c8
// EN: AArch64 prologue [mov x8, x30; bl #0x90cf0; mov x30, x8; stp x19, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x90cf0; mov x30, x8; stp x19, x30, [sp, #0x60]]
uint64_t fde_sub_05b6c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400D589ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x01F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B6C8ULL;
}

// FDE #0997 | PC: 0x05b8bc..0x05b910 (84 B) | Symbol: sub_05b8bc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x99000; add x8, x8, #0xdf0; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x99000; add x8, x8, #0xdf0; mov x19, x0]
uint64_t fde_sub_05b8bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00001E8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B8BCULL;
}

// FDE #0998 | PC: 0x05b910..0x05b928 (24 B) | Symbol: sub_05b910
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5b8bc; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5b8bc; mov x0, x19]
uint64_t fde_sub_05b910(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B910ULL;
}

// FDE #0999 | PC: 0x05b928..0x05b968 (64 B) | Symbol: sub_05b928
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8ef10; cbz x20, #0x5b950] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8ef10; cbz x20, #0x5b950]
uint64_t fde_sub_05b928(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B928ULL;
}

// FDE #1000 | PC: 0x05b968..0x05b9bc (84 B) | Symbol: sub_05b968
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x60]; cbz x0, #0x5b97c] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x60]; cbz x0, #0x5b97c]
uint64_t fde_sub_05b968(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B968ULL;
}

// FDE #1001 | PC: 0x05b9bc..0x05bccc (784 B) | Symbol: sub_05b9bc
// EN: AArch64 prologue [sub sp, sp, #0xd0; str d14, [sp, #0x50]; stp d13, d12, [sp, #0x58]; stp d11, d10, [sp, #0x68]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xd0; str d14, [sp, #0x50]; stp d13, d12, [sp, #0x58]; stp d11, d10, [sp, #0x68]]
uint64_t fde_sub_05b9bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD002BEEULL) << 32) | 0xD10343FFULL;
    const uint64_t kPcRange = 0x0310ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B9BCULL;
}

// FDE #1002 | PC: 0x05bccc..0x05be2c (352 B) | Symbol: sub_05bccc
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; adrp x8, #0x99000] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; adrp x8, #0x99000]
uint64_t fde_sub_05bccc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90253F5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0160ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05BCCCULL;
}

// FDE #1003 | PC: 0x05be2c..0x05be50 (36 B) | Symbol: sub_05be2c
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; bl #0x8d6cc] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; bl #0x8d6cc]
uint64_t fde_sub_05be2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05BE2CULL;
}

// FDE #1004 | PC: 0x05be50..0x05bedc (140 B) | Symbol: sub_05be50
// EN: AArch64 prologue [mov x8, x30; bl #0x90cf0; mov x30, x8; stp x19, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x90cf0; mov x30, x8; stp x19, x30, [sp, #0x60]]
uint64_t fde_sub_05be50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400D3A7ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05BE50ULL;
}

// FDE #1005 | PC: 0x05bedc..0x05bf4c (112 B) | Symbol: sub_05bedc
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x99000; add x8, x8, #0xe40] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x99000; add x8, x8, #0xe40]
uint64_t fde_sub_05bedc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05BEDCULL;
}

// FDE #1006 | PC: 0x05bf4c..0x05bf64 (24 B) | Symbol: sub_05bf4c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5bedc; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5bedc; mov x0, x19]
uint64_t fde_sub_05bf4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05BF4CULL;
}

// FDE #1007 | PC: 0x05bf64..0x05bfac (72 B) | Symbol: sub_05bf64
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x78]; cbz x0, #0x5bf78] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x78]; cbz x0, #0x5bf78]
uint64_t fde_sub_05bf64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05BF64ULL;
}

// FDE #1008 | PC: 0x05bfac..0x05c0d0 (292 B) | Symbol: sub_05bfac
// EN: AArch64 prologue [stp d9, d8, [sp, #-0x50]!; stp x25, x24, [sp, #0x10]; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp d9, d8, [sp, #-0x50]!; stp x25, x24, [sp, #0x10]; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]]
uint64_t fde_sub_05bfac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90163F9ULL) << 32) | 0x6DBB23E9ULL;
    const uint64_t kPcRange = 0x0124ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05BFACULL;
}

// FDE #1009 | PC: 0x05c0d0..0x05c14c (124 B) | Symbol: sub_05c0d0
// EN: AArch64 prologue [str x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_05c0d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xF81C0FF8ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C0D0ULL;
}

// FDE #1010 | PC: 0x05c14c..0x05c184 (56 B) | Symbol: sub_05c14c
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldp x19, x21, [x2]; add x20, x0, #0x58] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldp x19, x21, [x2]; add x20, x0, #0x58]
uint64_t fde_sub_05c14c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C14CULL;
}

// FDE #1011 | PC: 0x05c184..0x05c204 (128 B) | Symbol: sub_05c184
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; ldr x0, [x0, #0x80]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; ldr x0, [x0, #0x80]]
uint64_t fde_sub_05c184(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C184ULL;
}

// FDE #1012 | PC: 0x05c204..0x05c20c (8 B) | Symbol: sub_05c204
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5bedc] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5bedc]
uint64_t fde_sub_05c204(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF35ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C204ULL;
}

// FDE #1013 | PC: 0x05c20c..0x05c214 (8 B) | Symbol: sub_05c20c
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5bf4c] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5bf4c]
uint64_t fde_sub_05c20c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF4FULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C20CULL;
}

// FDE #1014 | PC: 0x05c214..0x05c21c (8 B) | Symbol: sub_05c214
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5c184] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5c184]
uint64_t fde_sub_05c214(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFDBULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C214ULL;
}

// FDE #1015 | PC: 0x05c21c..0x05c224 (8 B) | Symbol: sub_05c21c
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5c14c] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5c14c]
uint64_t fde_sub_05c21c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFCBULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C21CULL;
}

// FDE #1016 | PC: 0x05c224..0x05c22c (8 B) | Symbol: sub_05c224
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5bf64] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5bf64]
uint64_t fde_sub_05c224(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF4FULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C224ULL;
}

// FDE #1017 | PC: 0x05c22c..0x05c234 (8 B) | Symbol: sub_05c22c
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5bfac] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5bfac]
uint64_t fde_sub_05c22c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF5FULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C22CULL;
}

// FDE #1018 | PC: 0x05c234..0x05c240 (12 B) | Symbol: sub_05c234
// EN: AArch64 prologue [sub x0, x0, #8; mov w3, wzr; b #0x5c0d0] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; mov w3, wzr; b #0x5c0d0]
uint64_t fde_sub_05c234(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E3ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C234ULL;
}

// FDE #1019 | PC: 0x05c240..0x05c310 (208 B) | Symbol: sub_05c240
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_05c240(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9035BF7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C240ULL;
}

// FDE #1020 | PC: 0x05c310..0x05c338 (40 B) | Symbol: sub_05c310
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8dff0; cbz x19, #0x5c330; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8dff0; cbz x19, #0x5c330; mov x0, x19]
uint64_t fde_sub_05c310(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400C737ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C310ULL;
}

// FDE #1021 | PC: 0x05c338..0x05c408 (208 B) | Symbol: sub_05c338
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; ldrb w8, [x2, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; ldrb w8, [x2, #0x60]]
uint64_t fde_sub_05c338(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90253F5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C338ULL;
}

// FDE #1022 | PC: 0x05c408..0x05c430 (40 B) | Symbol: sub_05c408
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x99000; add x8, x8, #0xf30; bl #0x8fe7c] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x99000; add x8, x8, #0xf30; bl #0x8fe7c]
uint64_t fde_sub_05c408(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00001E8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C408ULL;
}

// FDE #1023 | PC: 0x05c430..0x05c448 (24 B) | Symbol: sub_05c430
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5c408; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5c408; mov x0, x19]
uint64_t fde_sub_05c430(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C430ULL;
}

// FDE #1024 | PC: 0x05c448..0x05c46c (36 B) | Symbol: sub_05c448
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5d270; ldr x0, [x19, #0xe8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5d270; ldr x0, [x19, #0xe8]]
uint64_t fde_sub_05c448(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C448ULL;
}

// FDE #1025 | PC: 0x05c46c..0x05c4dc (112 B) | Symbol: sub_05c46c
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldrb w8, [x0, #0x28]] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldrb w8, [x0, #0x28]]
uint64_t fde_sub_05c46c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C46CULL;
}

// FDE #1026 | PC: 0x05c4dc..0x05c4e4 (8 B) | Symbol: sub_05c4dc
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5c408] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5c408]
uint64_t fde_sub_05c4dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFCAULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C4DCULL;
}

// FDE #1027 | PC: 0x05c4e4..0x05c4ec (8 B) | Symbol: sub_05c4e4
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5c430] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5c430]
uint64_t fde_sub_05c4e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFD2ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C4E4ULL;
}

// FDE #1028 | PC: 0x05c4ec..0x05c4f4 (8 B) | Symbol: sub_05c4ec
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5c448] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5c448]
uint64_t fde_sub_05c4ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFD6ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C4ECULL;
}

// FDE #1029 | PC: 0x05c4f4..0x05c4fc (8 B) | Symbol: sub_05c4f4
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5c46c] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5c46c]
uint64_t fde_sub_05c4f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFDDULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C4F4ULL;
}

// FDE #1030 | PC: 0x05c4fc..0x05c5dc (224 B) | Symbol: sub_05c4fc
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; adrp x8, #0x9a000] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; adrp x8, #0x9a000]
uint64_t fde_sub_05c4fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C4FCULL;
}

// FDE #1031 | PC: 0x05c5dc..0x05c5e4 (8 B) | Symbol: sub_05c5dc
// EN: AArch64 prologue [mov x1, xzr; b #0x5c5e4] | VI: Khởi đầu hàm AArch64 [mov x1, xzr; b #0x5c5e4]
uint64_t fde_sub_05c5dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xAA1F03E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C5DCULL;
}

// FDE #1032 | PC: 0x05c5e4..0x05c60c (40 B) | Symbol: sub_05c5e4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8dcc8; cbz x19, #0x5c604; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8dcc8; cbz x19, #0x5c604; mov x0, x19]
uint64_t fde_sub_05c5e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400C5B8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C5E4ULL;
}

// FDE #1033 | PC: 0x05c60c..0x05c654 (72 B) | Symbol: sub_05c60c
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9a000; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9a000; mov x19, x0]
uint64_t fde_sub_05c60c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C60CULL;
}

// FDE #1034 | PC: 0x05c654..0x05c66c (24 B) | Symbol: sub_05c654
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5c60c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5c60c; mov x0, x19]
uint64_t fde_sub_05c654(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C654ULL;
}

// FDE #1035 | PC: 0x05c66c..0x05c6a4 (56 B) | Symbol: sub_05c66c
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldp x21, x22, [x0, #0x40]] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldp x21, x22, [x0, #0x40]]
uint64_t fde_sub_05c66c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C66CULL;
}

// FDE #1036 | PC: 0x05c6a4..0x05c714 (112 B) | Symbol: sub_05c6a4
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr x9, [x1, #8]] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr x9, [x1, #8]]
uint64_t fde_sub_05c6a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C6A4ULL;
}

// FDE #1037 | PC: 0x05c714..0x05c7c4 (176 B) | Symbol: sub_05c714
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr x8, [x0, #0x38]] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr x8, [x0, #0x38]]
uint64_t fde_sub_05c714(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C714ULL;
}

// FDE #1038 | PC: 0x05c7c4..0x05c9dc (536 B) | Symbol: sub_05c7c4
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x25, x24, [sp, #0x20]; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x25, x24, [sp, #0x20]; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]]
uint64_t fde_sub_05c7c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90263F9ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0218ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C7C4ULL;
}

// FDE #1039 | PC: 0x05c9dc..0x05c9f0 (20 B) | Symbol: sub_05c9dc
// EN: AArch64 prologue [cbz x1, #0x5c9ec; ldr x0, [x0, #8]; ldr x1, [x1, #8]; b #0x8c2b4] | VI: Khởi đầu hàm AArch64 [cbz x1, #0x5c9ec; ldr x0, [x0, #8]; ldr x1, [x1, #8]; b #0x8c2b4]
uint64_t fde_sub_05c9dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400400ULL) << 32) | 0xB4000081ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C9DCULL;
}

// FDE #1040 | PC: 0x05c9f0..0x05c9fc (12 B) | Symbol: sub_05c9f0
// EN: AArch64 prologue [cbz x1, #0x5c9f8; b #0x8c1f8; ret] | VI: Khởi đầu hàm AArch64 [cbz x1, #0x5c9f8; b #0x8c1f8; ret]
uint64_t fde_sub_05c9f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400BE01ULL) << 32) | 0xB4000041ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C9F0ULL;
}

// FDE #1041 | PC: 0x05c9fc..0x05ca44 (72 B) | Symbol: sub_05c9fc
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x90a44; sub x20, x8, #8] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x90a44; sub x20, x8, #8]
uint64_t fde_sub_05c9fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C9FCULL;
}

// FDE #1042 | PC: 0x05ca44..0x05cc44 (512 B) | Symbol: sub_05ca44
// EN: AArch64 prologue [sub sp, sp, #0x60; stp d11, d10, [sp, #0x10]; stp d9, d8, [sp, #0x20]; str x22, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp d11, d10, [sp, #0x10]; stp d9, d8, [sp, #0x20]; str x22, [sp, #0x30]]
uint64_t fde_sub_05ca44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D012BEBULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0200ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CA44ULL;
}

// FDE #1043 | PC: 0x05cc44..0x05cd14 (208 B) | Symbol: sub_05cc44
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x2] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x2]
uint64_t fde_sub_05cc44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CC44ULL;
}

// FDE #1044 | PC: 0x05cd14..0x05cd4c (56 B) | Symbol: sub_05cd14
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9a000; add x8, x8, #0xb8; bl #0x91950] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9a000; add x8, x8, #0xb8; bl #0x91950]
uint64_t fde_sub_05cd14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00001E8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CD14ULL;
}

// FDE #1045 | PC: 0x05cd4c..0x05cd64 (24 B) | Symbol: sub_05cd4c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5cd14; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5cd14; mov x0, x19]
uint64_t fde_sub_05cd4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CD4CULL;
}

// FDE #1046 | PC: 0x05cd64..0x05cd9c (56 B) | Symbol: sub_05cd64
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x930f4; cbz x0, #0x5cd74; bl #0x916c8] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x930f4; cbz x0, #0x5cd74; bl #0x916c8]
uint64_t fde_sub_05cd64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400D8E3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CD64ULL;
}

// FDE #1047 | PC: 0x05cd9c..0x05cda4 (8 B) | Symbol: _ZNK4lynx6animax12DocumentData12GetValueTypeEv
// EN: AArch64 prologue [mov w0, #6; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #6; ret]
uint64_t fde_sub_05cd9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x528000C0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CD9CULL;
}

// FDE #1048 | PC: 0x05cda4..0x05cdd0 (44 B) | Symbol: sub_05cda4
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldp x19, x20, [x0, #0x30]; cmp x20, x19] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldp x19, x20, [x0, #0x30]; cmp x20, x19]
uint64_t fde_sub_05cda4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CDA4ULL;
}

// FDE #1049 | PC: 0x05cdd0..0x05cdd8 (8 B) | Symbol: sub_05cdd0
// EN: AArch64 prologue [sub x0, x0, #0x28; b #0x5cd14] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x28; b #0x5cd14]
uint64_t fde_sub_05cdd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFD0ULL) << 32) | 0xD100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CDD0ULL;
}

// FDE #1050 | PC: 0x05cdd8..0x05cde0 (8 B) | Symbol: sub_05cdd8
// EN: AArch64 prologue [sub x0, x0, #0x28; b #0x5cd4c] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x28; b #0x5cd4c]
uint64_t fde_sub_05cdd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFDCULL) << 32) | 0xD100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CDD8ULL;
}

// FDE #1051 | PC: 0x05cde0..0x05cde8 (8 B) | Symbol: sub_05cde0
// EN: AArch64 prologue [sub x0, x0, #0x28; b #0x5cda4] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x28; b #0x5cda4]
uint64_t fde_sub_05cde0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF0ULL) << 32) | 0xD100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CDE0ULL;
}

// FDE #1052 | PC: 0x05cde8..0x05ceec (260 B) | Symbol: sub_05cde8
// EN: AArch64 prologue [stp x27, x26, [sp, #-0x50]!; stp x25, x24, [sp, #0x10]; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x27, x26, [sp, #-0x50]!; stp x25, x24, [sp, #0x10]; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]]
uint64_t fde_sub_05cde8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90163F9ULL) << 32) | 0xA9BB6BFBULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CDE8ULL;
}

// FDE #1053 | PC: 0x05ceec..0x05cf08 (28 B) | Symbol: sub_05ceec
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; str x1, [sp, #8]; add x0, x0, #0x30; add x1, sp, #8] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; str x1, [sp, #8]; add x0, x0, #0x30; add x1, sp, #8]
uint64_t fde_sub_05ceec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90007E1ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CEECULL;
}

// FDE #1054 | PC: 0x05cf08..0x05d258 (848 B) | Symbol: sub_05cf08
// EN: AArch64 prologue [str d8, [sp, #-0x60]!; mov x8, x30; bl #0x91e38; mov x30, x8] | VI: Khởi đầu hàm AArch64 [str d8, [sp, #-0x60]!; mov x8, x30; bl #0x91e38; mov x30, x8]
uint64_t fde_sub_05cf08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E8ULL) << 32) | 0xFC1A0FE8ULL;
    const uint64_t kPcRange = 0x0350ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CF08ULL;
}

// FDE #1055 | PC: 0x05d258..0x05d270 (24 B) | Symbol: sub_05d258
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5c4fc; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5c4fc; mov x0, x19]
uint64_t fde_sub_05d258(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D258ULL;
}

// FDE #1056 | PC: 0x05d270..0x05d2e4 (116 B) | Symbol: sub_05d270
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; ldr x0, [x0, #0x98]] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; ldr x0, [x0, #0x98]]
uint64_t fde_sub_05d270(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D270ULL;
}

// FDE #1057 | PC: 0x05d2e4..0x05d438 (340 B) | Symbol: sub_05d2e4
// EN: AArch64 prologue [sub sp, sp, #0x50; str x24, [sp, #0x10]; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x24, [sp, #0x10]; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]]
uint64_t fde_sub_05d2e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF8ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0154ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D2E4ULL;
}

// FDE #1058 | PC: 0x05d438..0x05d970 (1336 B) | Symbol: sub_05d438
// EN: AArch64 prologue [sub sp, sp, #0xc0; stp d15, d14, [sp, #0x20]; stp d13, d12, [sp, #0x30]; stp d11, d10, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; stp d15, d14, [sp, #0x20]; stp d13, d12, [sp, #0x30]; stp d11, d10, [sp, #0x40]]
uint64_t fde_sub_05d438(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D023BEFULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x0538ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D438ULL;
}

// FDE #1059 | PC: 0x05d970..0x05da70 (256 B) | Symbol: sub_05d970
// EN: AArch64 prologue [mov x3, x30; bl #0x8fc50; mov x30, x3; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x8fc50; mov x30, x3; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_05d970(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400C8B7ULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D970ULL;
}

// FDE #1060 | PC: 0x05da70..0x05db0c (156 B) | Symbol: sub_05da70
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; ldr x0, [x0, #0xc0]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; ldr x0, [x0, #0xc0]]
uint64_t fde_sub_05da70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DA70ULL;
}

// FDE #1061 | PC: 0x05db0c..0x05db14 (8 B) | Symbol: sub_05db0c
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5c4fc] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5c4fc]
uint64_t fde_sub_05db0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFA7BULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DB0CULL;
}

// FDE #1062 | PC: 0x05db14..0x05db1c (8 B) | Symbol: sub_05db14
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5d258] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5d258]
uint64_t fde_sub_05db14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFDD0ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DB14ULL;
}

// FDE #1063 | PC: 0x05db1c..0x05db24 (8 B) | Symbol: sub_05db1c
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5da70] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5da70]
uint64_t fde_sub_05db1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFD4ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DB1CULL;
}

// FDE #1064 | PC: 0x05db24..0x05db2c (8 B) | Symbol: sub_05db24
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5d2e4] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5d2e4]
uint64_t fde_sub_05db24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFDEFULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DB24ULL;
}

// FDE #1065 | PC: 0x05db2c..0x05db34 (8 B) | Symbol: sub_05db2c
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5d270] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5d270]
uint64_t fde_sub_05db2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFDD0ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DB2CULL;
}

// FDE #1066 | PC: 0x05db34..0x05db3c (8 B) | Symbol: sub_05db34
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5d438] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5d438]
uint64_t fde_sub_05db34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFE40ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DB34ULL;
}

// FDE #1067 | PC: 0x05db3c..0x05db48 (12 B) | Symbol: sub_05db3c
// EN: AArch64 prologue [sub x0, x0, #8; mov w3, wzr; b #0x5d970] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; mov w3, wzr; b #0x5d970]
uint64_t fde_sub_05db3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E3ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DB3CULL;
}

// FDE #1068 | PC: 0x05db48..0x05dbd8 (144 B) | Symbol: sub_05db48
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8d614] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8d614]
uint64_t fde_sub_05db48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DB48ULL;
}

// FDE #1069 | PC: 0x05dbd8..0x05dcb0 (216 B) | Symbol: sub_05dbd8
// EN: AArch64 prologue [sub sp, sp, #0x40; str x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_05dbd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DBD8ULL;
}

// FDE #1070 | PC: 0x05dcb0..0x05dce8 (56 B) | Symbol: sub_05dcb0
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9a000; add x8, x8, #0x270] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9a000; add x8, x8, #0x270]
uint64_t fde_sub_05dcb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DCB0ULL;
}

// FDE #1071 | PC: 0x05dce8..0x05dd00 (24 B) | Symbol: sub_05dce8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5dcb0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5dcb0; mov x0, x19]
uint64_t fde_sub_05dce8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DCE8ULL;
}

// FDE #1072 | PC: 0x05dd00..0x05dd08 (8 B) | Symbol: sub_05dd00
// EN: AArch64 prologue [strb wzr, [x0, #0x68]; ret] | VI: Khởi đầu hàm AArch64 [strb wzr, [x0, #0x68]; ret]
uint64_t fde_sub_05dd00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x3901A01FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DD00ULL;
}

// FDE #1073 | PC: 0x05dd08..0x05dfb8 (688 B) | Symbol: sub_05dd08
// EN: AArch64 prologue [stp d15, d14, [sp, #-0x50]!; stp d13, d12, [sp, #0x10]; stp d11, d10, [sp, #0x20]; stp d9, d8, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp d15, d14, [sp, #-0x50]!; stp d13, d12, [sp, #0x10]; stp d11, d10, [sp, #0x20]; stp d9, d8, [sp, #0x30]]
uint64_t fde_sub_05dd08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D0133EDULL) << 32) | 0x6DBB3BEFULL;
    const uint64_t kPcRange = 0x02B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DD08ULL;
}

// FDE #1074 | PC: 0x05dfb8..0x05dfec (52 B) | Symbol: sub_05dfb8
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldp x21, x22, [x1]] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldp x21, x22, [x1]]
uint64_t fde_sub_05dfb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DFB8ULL;
}

// FDE #1075 | PC: 0x05dfec..0x05e01c (48 B) | Symbol: sub_05dfec
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x38]; cbz x0, #0x5e000] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x38]; cbz x0, #0x5e000]
uint64_t fde_sub_05dfec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DFECULL;
}

// FDE #1076 | PC: 0x05e01c..0x05e04c (48 B) | Symbol: sub_05e01c
// EN: AArch64 prologue [and w8, w1, #0xffff; cmp w8, #0xd2; mov x2, x0; b.eq #0x5e03c] | VI: Khởi đầu hàm AArch64 [and w8, w1, #0xffff; cmp w8, #0xd2; mov x2, x0; b.eq #0x5e03c]
uint64_t fde_sub_05e01c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7103491FULL) << 32) | 0x12003C28ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E01CULL;
}

// FDE #1077 | PC: 0x05e04c..0x05e054 (8 B) | Symbol: sub_05e04c
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5dcb0] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5dcb0]
uint64_t fde_sub_05e04c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF18ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E04CULL;
}

// FDE #1078 | PC: 0x05e054..0x05e05c (8 B) | Symbol: sub_05e054
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5dce8] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5dce8]
uint64_t fde_sub_05e054(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF24ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E054ULL;
}

// FDE #1079 | PC: 0x05e05c..0x05e064 (8 B) | Symbol: sub_05e05c
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5e01c] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5e01c]
uint64_t fde_sub_05e05c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFEFULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E05CULL;
}

// FDE #1080 | PC: 0x05e064..0x05e06c (8 B) | Symbol: sub_05e064
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5dfb8] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5dfb8]
uint64_t fde_sub_05e064(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFD4ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E064ULL;
}

// FDE #1081 | PC: 0x05e06c..0x05e074 (8 B) | Symbol: sub_05e06c
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5dfec] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5dfec]
uint64_t fde_sub_05e06c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFDFULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E06CULL;
}

// FDE #1082 | PC: 0x05e074..0x05e07c (8 B) | Symbol: sub_05e074
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5dd08] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5dd08]
uint64_t fde_sub_05e074(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF24ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E074ULL;
}

// FDE #1083 | PC: 0x05e07c..0x05e148 (204 B) | Symbol: sub_05e07c
// EN: AArch64 prologue [str d10, [sp, #-0x60]!; stp d9, d8, [sp, #0x10]; stp x25, x24, [sp, #0x20]; stp x23, x22, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str d10, [sp, #-0x60]!; stp d9, d8, [sp, #0x10]; stp x25, x24, [sp, #0x20]; stp x23, x22, [sp, #0x30]]
uint64_t fde_sub_05e07c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D0123E9ULL) << 32) | 0xFC1A0FEAULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E07CULL;
}

// FDE #1084 | PC: 0x05e148..0x05e2d4 (396 B) | Symbol: sub_05e148
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x911ec] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x911ec]
uint64_t fde_sub_05e148(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x018CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E148ULL;
}

// FDE #1085 | PC: 0x05e2d4..0x05e32c (88 B) | Symbol: sub_05e2d4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9a000; add x8, x8, #0x358; bl #0x92c14] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9a000; add x8, x8, #0x358; bl #0x92c14]
uint64_t fde_sub_05e2d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900001E8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E2D4ULL;
}

// FDE #1086 | PC: 0x05e32c..0x05e344 (24 B) | Symbol: sub_05e32c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5e2d4; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5e2d4; mov x0, x19]
uint64_t fde_sub_05e32c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E32CULL;
}

// FDE #1087 | PC: 0x05e344..0x05e3e8 (164 B) | Symbol: sub_05e344
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; ldr x0, [x0, #0x70]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; ldr x0, [x0, #0x70]]
uint64_t fde_sub_05e344(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E344ULL;
}

// FDE #1088 | PC: 0x05e3e8..0x05e420 (56 B) | Symbol: sub_05e3e8
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldp x19, x21, [x2]; add x20, x0, #0x48] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldp x19, x21, [x2]; add x20, x0, #0x48]
uint64_t fde_sub_05e3e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E3E8ULL;
}

// FDE #1089 | PC: 0x05e420..0x05e468 (72 B) | Symbol: sub_05e420
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x70]; cbz x0, #0x5e434] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x70]; cbz x0, #0x5e434]
uint64_t fde_sub_05e420(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E420ULL;
}

// FDE #1090 | PC: 0x05e468..0x05e590 (296 B) | Symbol: sub_05e468
// EN: AArch64 prologue [mov x4, x30; bl #0x91aac; mov x30, x4; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x4, x30; bl #0x91aac; mov x30, x4; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_05e468(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400CD90ULL) << 32) | 0xAA1E03E4ULL;
    const uint64_t kPcRange = 0x0128ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E468ULL;
}

// FDE #1091 | PC: 0x05e590..0x05e60c (124 B) | Symbol: sub_05e590
// EN: AArch64 prologue [str x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_05e590(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xF81C0FF8ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E590ULL;
}

// FDE #1092 | PC: 0x05e60c..0x05e614 (8 B) | Symbol: sub_05e60c
// EN: AArch64 prologue [sub x0, x0, #0x28; b #0x5e2d4] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x28; b #0x5e2d4]
uint64_t fde_sub_05e60c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF31ULL) << 32) | 0xD100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E60CULL;
}

// FDE #1093 | PC: 0x05e614..0x05e61c (8 B) | Symbol: sub_05e614
// EN: AArch64 prologue [sub x0, x0, #0x28; b #0x5e32c] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x28; b #0x5e32c]
uint64_t fde_sub_05e614(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF45ULL) << 32) | 0xD100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E614ULL;
}

// FDE #1094 | PC: 0x05e61c..0x05e7a0 (388 B) | Symbol: sub_05e61c
// EN: AArch64 prologue [sub sp, sp, #0x40; str x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_05e61c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0184ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E61CULL;
}

// FDE #1095 | PC: 0x05e7a0..0x05e7e0 (64 B) | Symbol: sub_05e7a0
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9a000; add x8, x8, #0x420] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9a000; add x8, x8, #0x420]
uint64_t fde_sub_05e7a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E7A0ULL;
}

// FDE #1096 | PC: 0x05e7e0..0x05e7f8 (24 B) | Symbol: sub_05e7e0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5e7a0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5e7a0; mov x0, x19]
uint64_t fde_sub_05e7e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E7E0ULL;
}

// FDE #1097 | PC: 0x05e7f8..0x05e800 (8 B) | Symbol: sub_05e7f8
// EN: AArch64 prologue [strb wzr, [x0, #0x90]; ret] | VI: Khởi đầu hàm AArch64 [strb wzr, [x0, #0x90]; ret]
uint64_t fde_sub_05e7f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x3902401FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E7F8ULL;
}

// FDE #1098 | PC: 0x05e800..0x05e874 (116 B) | Symbol: sub_05e800
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x90cb4; cbz x0, #0x5e810; bl #0x8d678] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x90cb4; cbz x0, #0x5e810; bl #0x8d678]
uint64_t fde_sub_05e800(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400C92CULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E800ULL;
}

// FDE #1099 | PC: 0x05e874..0x05ef18 (1700 B) | Symbol: sub_05e874
// EN: AArch64 prologue [sub sp, sp, #0x110; stp d15, d14, [sp, #0xa0]; stp d13, d12, [sp, #0xb0]; stp d11, d10, [sp, #0xc0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; stp d15, d14, [sp, #0xa0]; stp d13, d12, [sp, #0xb0]; stp d11, d10, [sp, #0xc0]]
uint64_t fde_sub_05e874(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D0A3BEFULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x06A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E874ULL;
}

// FDE #1100 | PC: 0x05ef18..0x05ef4c (52 B) | Symbol: sub_05ef18
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldp x21, x22, [x1]] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldp x21, x22, [x1]]
uint64_t fde_sub_05ef18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05EF18ULL;
}

// FDE #1101 | PC: 0x05ef4c..0x05efd0 (132 B) | Symbol: sub_05ef4c
// EN: AArch64 prologue [and w8, w1, #0xffff; sub w8, w8, #0xd2; cmp w8, #8; b.hi #0x5ef84] | VI: Khởi đầu hàm AArch64 [and w8, w1, #0xffff; sub w8, w8, #0xd2; cmp w8, #8; b.hi #0x5ef84]
uint64_t fde_sub_05ef4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x51034908ULL) << 32) | 0x12003C28ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05EF4CULL;
}

// FDE #1102 | PC: 0x05efd0..0x05efd8 (8 B) | Symbol: sub_05efd0
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5e7a0] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5e7a0]
uint64_t fde_sub_05efd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFDF3ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05EFD0ULL;
}

// FDE #1103 | PC: 0x05efd8..0x05efe0 (8 B) | Symbol: sub_05efd8
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5e7e0] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5e7e0]
uint64_t fde_sub_05efd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFE01ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05EFD8ULL;
}

// FDE #1104 | PC: 0x05efe0..0x05efe8 (8 B) | Symbol: sub_05efe0
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5ef4c] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5ef4c]
uint64_t fde_sub_05efe0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFDAULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05EFE0ULL;
}

// FDE #1105 | PC: 0x05efe8..0x05eff0 (8 B) | Symbol: sub_05efe8
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5ef18] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5ef18]
uint64_t fde_sub_05efe8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFCBULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05EFE8ULL;
}

// FDE #1106 | PC: 0x05eff0..0x05eff8 (8 B) | Symbol: sub_05eff0
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5e800] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5e800]
uint64_t fde_sub_05eff0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFE03ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05EFF0ULL;
}

// FDE #1107 | PC: 0x05eff8..0x05f000 (8 B) | Symbol: sub_05eff8
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5e874] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5e874]
uint64_t fde_sub_05eff8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFE1EULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05EFF8ULL;
}

// FDE #1108 | PC: 0x05f000..0x05f0fc (252 B) | Symbol: sub_05f000
// EN: AArch64 prologue [sub sp, sp, #0x40; str x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_05f000(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F000ULL;
}

// FDE #1109 | PC: 0x05f0fc..0x05f13c (64 B) | Symbol: sub_05f0fc
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9a000; add x8, x8, #0x508] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9a000; add x8, x8, #0x508]
uint64_t fde_sub_05f0fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F0FCULL;
}

// FDE #1110 | PC: 0x05f13c..0x05f154 (24 B) | Symbol: sub_05f13c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5f0fc; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5f0fc; mov x0, x19]
uint64_t fde_sub_05f13c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F13CULL;
}

// FDE #1111 | PC: 0x05f154..0x05f15c (8 B) | Symbol: sub_05f154
// EN: AArch64 prologue [strb wzr, [x0, #0x80]; ret] | VI: Khởi đầu hàm AArch64 [strb wzr, [x0, #0x80]; ret]
uint64_t fde_sub_05f154(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x3902001FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F154ULL;
}

// FDE #1112 | PC: 0x05f15c..0x05f198 (60 B) | Symbol: sub_05f15c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x48]; cbz x0, #0x5f170] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x48]; cbz x0, #0x5f170]
uint64_t fde_sub_05f15c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F15CULL;
}

// FDE #1113 | PC: 0x05f198..0x05f490 (760 B) | Symbol: sub_05f198
// EN: AArch64 prologue [stp d11, d10, [sp, #-0x60]!; stp d9, d8, [sp, #0x10]; stp x25, x24, [sp, #0x20]; stp x23, x22, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp d11, d10, [sp, #-0x60]!; stp d9, d8, [sp, #0x10]; stp x25, x24, [sp, #0x20]; stp x23, x22, [sp, #0x30]]
uint64_t fde_sub_05f198(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D0123E9ULL) << 32) | 0x6DBA2BEBULL;
    const uint64_t kPcRange = 0x02F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F198ULL;
}

// FDE #1114 | PC: 0x05f490..0x05f4ec (92 B) | Symbol: sub_05f490
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldp x21, x22, [x1]] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldp x21, x22, [x1]]
uint64_t fde_sub_05f490(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F490ULL;
}

// FDE #1115 | PC: 0x05f4ec..0x05f534 (72 B) | Symbol: sub_05f4ec
// EN: AArch64 prologue [and w8, w1, #0xffff; cmp w8, #0xd2; mov x2, x0; b.eq #0x5f518] | VI: Khởi đầu hàm AArch64 [and w8, w1, #0xffff; cmp w8, #0xd2; mov x2, x0; b.eq #0x5f518]
uint64_t fde_sub_05f4ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7103491FULL) << 32) | 0x12003C28ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F4ECULL;
}

// FDE #1116 | PC: 0x05f534..0x05f53c (8 B) | Symbol: sub_05f534
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5f0fc] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5f0fc]
uint64_t fde_sub_05f534(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFEF1ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F534ULL;
}

// FDE #1117 | PC: 0x05f53c..0x05f544 (8 B) | Symbol: sub_05f53c
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5f13c] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5f13c]
uint64_t fde_sub_05f53c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFEFFULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F53CULL;
}

// FDE #1118 | PC: 0x05f544..0x05f54c (8 B) | Symbol: sub_05f544
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5f4ec] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5f4ec]
uint64_t fde_sub_05f544(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFE9ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F544ULL;
}

// FDE #1119 | PC: 0x05f54c..0x05f554 (8 B) | Symbol: sub_05f54c
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5f490] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5f490]
uint64_t fde_sub_05f54c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFD0ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F54CULL;
}

// FDE #1120 | PC: 0x05f554..0x05f55c (8 B) | Symbol: sub_05f554
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5f15c] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5f15c]
uint64_t fde_sub_05f554(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF01ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F554ULL;
}

// FDE #1121 | PC: 0x05f55c..0x05f564 (8 B) | Symbol: sub_05f55c
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5f198] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5f198]
uint64_t fde_sub_05f55c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF0EULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F55CULL;
}

// FDE #1122 | PC: 0x05f564..0x05f654 (240 B) | Symbol: sub_05f564
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_05f564(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F564ULL;
}

// FDE #1123 | PC: 0x05f654..0x05f6a8 (84 B) | Symbol: sub_05f654
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x93064; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x93064; mov x19, x0]
uint64_t fde_sub_05f654(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F654ULL;
}

// FDE #1124 | PC: 0x05f6a8..0x05f6c0 (24 B) | Symbol: sub_05f6a8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5f654; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5f654; mov x0, x19]
uint64_t fde_sub_05f6a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F6A8ULL;
}

// FDE #1125 | PC: 0x05f6c0..0x05f828 (360 B) | Symbol: sub_05f6c0
// EN: AArch64 prologue [str d12, [sp, #-0x70]!; stp d11, d10, [sp, #0x10]; stp d9, d8, [sp, #0x20]; stp x25, x24, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str d12, [sp, #-0x70]!; stp d11, d10, [sp, #0x10]; stp d9, d8, [sp, #0x20]; stp x25, x24, [sp, #0x30]]
uint64_t fde_sub_05f6c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D012BEBULL) << 32) | 0xFC190FECULL;
    const uint64_t kPcRange = 0x0168ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F6C0ULL;
}

// FDE #1126 | PC: 0x05f828..0x05f838 (16 B) | Symbol: sub_05f828
// EN: AArch64 prologue [ldr x0, [x0, #0x60]; cbz x0, #0x5f834; b #0x91a28; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x60]; cbz x0, #0x5f834; b #0x91a28; ret]
uint64_t fde_sub_05f828(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000040ULL) << 32) | 0xF9403000ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F828ULL;
}

// FDE #1127 | PC: 0x05f838..0x05f848 (16 B) | Symbol: sub_05f838
// EN: AArch64 prologue [ldr x0, [x0, #0x60]; cbz x0, #0x5f844; b #0x90a38; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x60]; cbz x0, #0x5f844; b #0x90a38; ret]
uint64_t fde_sub_05f838(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000040ULL) << 32) | 0xF9403000ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F838ULL;
}

// FDE #1128 | PC: 0x05f848..0x05f884 (60 B) | Symbol: sub_05f848
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x48]; cbz x0, #0x5f85c] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x48]; cbz x0, #0x5f85c]
uint64_t fde_sub_05f848(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F848ULL;
}

// FDE #1129 | PC: 0x05f884..0x05f944 (192 B) | Symbol: sub_05f884
// EN: AArch64 prologue [str d10, [sp, #-0x40]!; stp d9, d8, [sp, #8]; str x22, [sp, #0x18]; stp x21, x20, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [str d10, [sp, #-0x40]!; stp d9, d8, [sp, #8]; str x22, [sp, #0x18]; stp x21, x20, [sp, #0x20]]
uint64_t fde_sub_05f884(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D00A3E9ULL) << 32) | 0xFC1C0FEAULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F884ULL;
}

// FDE #1130 | PC: 0x05f944..0x05fa60 (284 B) | Symbol: sub_05f944
// EN: AArch64 prologue [mov x2, x30; bl #0x90b54; mov x30, x2; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x90b54; mov x30, x2; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_05f944(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400C483ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F944ULL;
}

// FDE #1131 | PC: 0x05fa60..0x05faa0 (64 B) | Symbol: sub_05fa60
// EN: AArch64 prologue [str x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_05fa60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xF81C0FF8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FA60ULL;
}

// FDE #1132 | PC: 0x05faa0..0x05fb08 (104 B) | Symbol: sub_05faa0
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; ldr x0, [x0, #0x58]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; ldr x0, [x0, #0x58]]
uint64_t fde_sub_05faa0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FAA0ULL;
}

// FDE #1133 | PC: 0x05fb08..0x05fb10 (8 B) | Symbol: sub_05fb08
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5f654] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5f654]
uint64_t fde_sub_05fb08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFED2ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FB08ULL;
}

// FDE #1134 | PC: 0x05fb10..0x05fb18 (8 B) | Symbol: sub_05fb10
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5f6a8] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5f6a8]
uint64_t fde_sub_05fb10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFEE5ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FB10ULL;
}

// FDE #1135 | PC: 0x05fb18..0x05fb20 (8 B) | Symbol: sub_05fb18
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5faa0] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5faa0]
uint64_t fde_sub_05fb18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFE1ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FB18ULL;
}

// FDE #1136 | PC: 0x05fb20..0x05fb28 (8 B) | Symbol: sub_05fb20
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5fa60] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5fa60]
uint64_t fde_sub_05fb20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFCFULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FB20ULL;
}

// FDE #1137 | PC: 0x05fb28..0x05fb38 (16 B) | Symbol: sub_05fb28
// EN: AArch64 prologue [ldr x0, [x0, #0x58]; cbz x0, #0x5fb34; b #0x90a38; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x58]; cbz x0, #0x5fb34; b #0x90a38; ret]
uint64_t fde_sub_05fb28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000040ULL) << 32) | 0xF9402C00ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FB28ULL;
}

// FDE #1138 | PC: 0x05fb38..0x05fb40 (8 B) | Symbol: sub_05fb38
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5f848] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5f848]
uint64_t fde_sub_05fb38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF43ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FB38ULL;
}

// FDE #1139 | PC: 0x05fb40..0x05fb48 (8 B) | Symbol: sub_05fb40
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5f6c0] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5f6c0]
uint64_t fde_sub_05fb40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFEDFULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FB40ULL;
}

// FDE #1140 | PC: 0x05fb48..0x05fb58 (16 B) | Symbol: sub_05fb48
// EN: AArch64 prologue [ldr x0, [x0, #0x58]; cbz x0, #0x5fb54; b #0x91a28; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x58]; cbz x0, #0x5fb54; b #0x91a28; ret]
uint64_t fde_sub_05fb48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000040ULL) << 32) | 0xF9402C00ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FB48ULL;
}

// FDE #1141 | PC: 0x05fb58..0x05fb60 (8 B) | Symbol: sub_05fb58
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5f944] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5f944]
uint64_t fde_sub_05fb58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF7AULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FB58ULL;
}

// FDE #1142 | PC: 0x05fb60..0x05fb68 (8 B) | Symbol: sub_05fb60
// EN: AArch64 prologue [sub x0, x0, #8; b #0x5f884] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x5f884]
uint64_t fde_sub_05fb60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF48ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FB60ULL;
}

// FDE #1143 | PC: 0x05fb68..0x05fbfc (148 B) | Symbol: sub_05fb68
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x91310] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x91310]
uint64_t fde_sub_05fb68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FB68ULL;
}

// FDE #1144 | PC: 0x05fbfc..0x05fc34 (56 B) | Symbol: sub_05fbfc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9a000; add x8, x8, #0x708; str x8, [x0]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9a000; add x8, x8, #0x708; str x8, [x0]]
uint64_t fde_sub_05fbfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00001C8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FBFCULL;
}

// FDE #1145 | PC: 0x05fc34..0x05fc4c (24 B) | Symbol: sub_05fc34
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5fbfc; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5fbfc; mov x0, x19]
uint64_t fde_sub_05fc34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FC34ULL;
}

// FDE #1146 | PC: 0x05fc4c..0x05fc64 (24 B) | Symbol: sub_05fc4c
// EN: AArch64 prologue [mov x8, x0; ldr x0, [x0, #0x30]; cbz x0, #0x5fc60; add x1, x8, #0x28] | VI: Khởi đầu hàm AArch64 [mov x8, x0; ldr x0, [x0, #0x30]; cbz x0, #0x5fc60; add x1, x8, #0x28]
uint64_t fde_sub_05fc4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401800ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FC4CULL;
}

// FDE #1147 | PC: 0x05fc64..0x05fc6c (8 B) | Symbol: sub_05fc64
// EN: AArch64 prologue [mov w0, #7; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #7; ret]
uint64_t fde_sub_05fc64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x528000E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FC64ULL;
}

// FDE #1148 | PC: 0x05fc6c..0x0603a0 (1844 B) | Symbol: sub_05fc6c
// EN: AArch64 prologue [sub sp, sp, #0x170; stp d15, d14, [sp, #0xd0]; stp d13, d12, [sp, #0xe0]; stp d11, d10, [sp, #0xf0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; stp d15, d14, [sp, #0xd0]; stp d13, d12, [sp, #0xe0]; stp d11, d10, [sp, #0xf0]]
uint64_t fde_sub_05fc6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D0D3BEFULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x0734ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FC6CULL;
}

// FDE #1149 | PC: 0x0603a0..0x0603a8 (8 B) | Symbol: sub_0603a0
// EN: AArch64 prologue [sub x0, x0, #0x28; b #0x5fbfc] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x28; b #0x5fbfc]
uint64_t fde_sub_0603a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFE16ULL) << 32) | 0xD100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0603A0ULL;
}

// FDE #1150 | PC: 0x0603a8..0x0603b0 (8 B) | Symbol: sub_0603a8
// EN: AArch64 prologue [sub x0, x0, #0x28; b #0x5fc34] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x28; b #0x5fc34]
uint64_t fde_sub_0603a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFE22ULL) << 32) | 0xD100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0603A8ULL;
}

// FDE #1151 | PC: 0x0603b0..0x0603ec (60 B) | Symbol: sub_0603b0
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x8, #0x2222222222222222; movk x8, #0x2223] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x8, #0x2222222222222222; movk x8, #0x2223]
uint64_t fde_sub_0603b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0603B0ULL;
}

// FDE #1152 | PC: 0x0603ec..0x060468 (124 B) | Symbol: sub_0603ec
// EN: AArch64 prologue [ldr x8, [x0, #8]; adrp x10, #0x9a000; adrp x11, #0x98000; sub x9, x2, x1] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; adrp x10, #0x9a000; adrp x11, #0x98000; sub x9, x2, x1]
uint64_t fde_sub_0603ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00001CAULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0603ECULL;
}

// FDE #1153 | PC: 0x060468..0x060490 (40 B) | Symbol: sub_060468
// EN: AArch64 prologue [mov x8, #0x2222222222222222; movk x8, #0x2223; movk x8, #0x222, lsl #48; cmp x0, x8] | VI: Khởi đầu hàm AArch64 [mov x8, #0x2222222222222222; movk x8, #0x2223; movk x8, #0x222, lsl #48; cmp x0, x8]
uint64_t fde_sub_060468(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF2844468ULL) << 32) | 0xB203E3E8ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060468ULL;
}

// FDE #1154 | PC: 0x060490..0x060518 (136 B) | Symbol: sub_060490
// EN: AArch64 prologue [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_060490(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF6ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060490ULL;
}

// FDE #1155 | PC: 0x060518..0x06053c (36 B) | Symbol: sub_060518
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e030; mov x0, x20] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e030; mov x0, x20]
uint64_t fde_sub_060518(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060518ULL;
}

// FDE #1156 | PC: 0x06053c..0x06058c (80 B) | Symbol: sub_06053c
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; mov x8, #0x2222222222222222; movk x8, #0x222, lsl #48; cmp x1, x8] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; mov x8, #0x2222222222222222; movk x8, #0x222, lsl #48; cmp x1, x8]
uint64_t fde_sub_06053c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB203E3E8ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06053CULL;
}

// FDE #1157 | PC: 0x06058c..0x0605bc (48 B) | Symbol: sub_06058c
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8df88; cbz x1, #0x605a8] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8df88; cbz x1, #0x605a8]
uint64_t fde_sub_06058c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06058CULL;
}

// FDE #1158 | PC: 0x0605bc..0x060618 (92 B) | Symbol: sub_0605bc
// EN: AArch64 prologue [adrp x8, #0x9a000; add x8, x8, #0x7d8; str x8, [x0]; ldur q0, [x1, #0x14]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9a000; add x8, x8, #0x7d8; str x8, [x0]; ldur q0, [x1, #0x14]]
uint64_t fde_sub_0605bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x911F6108ULL) << 32) | 0xD00001C8ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0605BCULL;
}

// FDE #1159 | PC: 0x060618..0x060664 (76 B) | Symbol: sub_060618
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldp x22, x21, [x0]] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldp x22, x21, [x0]]
uint64_t fde_sub_060618(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060618ULL;
}

// FDE #1160 | PC: 0x060664..0x06068c (40 B) | Symbol: sub_060664
// EN: AArch64 prologue [ldp x8, x9, [x0, #8]; cmp x8, x9; b.eq #0x6067c; sub x9, x9, #0x78] | VI: Khởi đầu hàm AArch64 [ldp x8, x9, [x0, #8]; cmp x8, x9; b.eq #0x6067c; sub x9, x9, #0x78]
uint64_t fde_sub_060664(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xA940A408ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060664ULL;
}

// FDE #1161 | PC: 0x06068c..0x060730 (164 B) | Symbol: sub_06068c
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x91310] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x91310]
uint64_t fde_sub_06068c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06068CULL;
}

// FDE #1162 | PC: 0x060730..0x060768 (56 B) | Symbol: sub_060730
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9a000; add x8, x8, #0x810; bl #0x91950] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9a000; add x8, x8, #0x810; bl #0x91950]
uint64_t fde_sub_060730(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00001C8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060730ULL;
}

// FDE #1163 | PC: 0x060768..0x060780 (24 B) | Symbol: sub_060768
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x60730; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x60730; mov x0, x19]
uint64_t fde_sub_060768(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060768ULL;
}

// FDE #1164 | PC: 0x060780..0x060964 (484 B) | Symbol: sub_060780
// EN: AArch64 prologue [mov x2, x30; bl #0x8d63c; mov x30, x2; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8d63c; mov x30, x2; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_060780(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400B3AEULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x01E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060780ULL;
}

// FDE #1165 | PC: 0x060964..0x06097c (24 B) | Symbol: sub_060964
// EN: AArch64 prologue [mov x8, x0; ldr x0, [x0, #0x38]; cbz x0, #0x60978; add x1, x8, #0x28] | VI: Khởi đầu hàm AArch64 [mov x8, x0; ldr x0, [x0, #0x38]; cbz x0, #0x60978; add x1, x8, #0x28]
uint64_t fde_sub_060964(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401C00ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060964ULL;
}

// FDE #1166 | PC: 0x06097c..0x060a1c (160 B) | Symbol: sub_06097c
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldrb w8, [x0, #0x58]; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldrb w8, [x0, #0x58]; mov x19, x0]
uint64_t fde_sub_06097c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06097CULL;
}

// FDE #1167 | PC: 0x060a1c..0x060a24 (8 B) | Symbol: sub_060a1c
// EN: AArch64 prologue [strb wzr, [x0, #0x58]; ret] | VI: Khởi đầu hàm AArch64 [strb wzr, [x0, #0x58]; ret]
uint64_t fde_sub_060a1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x3901601FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060A1CULL;
}

// FDE #1168 | PC: 0x060a24..0x060a2c (8 B) | Symbol: sub_060a24
// EN: AArch64 prologue [sub x0, x0, #0x28; b #0x60730] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x28; b #0x60730]
uint64_t fde_sub_060a24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF42ULL) << 32) | 0xD100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060A24ULL;
}

// FDE #1169 | PC: 0x060a2c..0x060a34 (8 B) | Symbol: sub_060a2c
// EN: AArch64 prologue [sub x0, x0, #0x28; b #0x60768] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x28; b #0x60768]
uint64_t fde_sub_060a2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF4EULL) << 32) | 0xD100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060A2CULL;
}

// FDE #1170 | PC: 0x060a34..0x060a3c (8 B) | Symbol: sub_060a34
// EN: AArch64 prologue [strb wzr, [x0, #0x30]; ret] | VI: Khởi đầu hàm AArch64 [strb wzr, [x0, #0x30]; ret]
uint64_t fde_sub_060a34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x3900C01FULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060A34ULL;
}

// FDE #1171 | PC: 0x060a3c..0x060a64 (40 B) | Symbol: sub_060a3c
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x2; subs x2, x1, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x2; subs x2, x1, x0]
uint64_t fde_sub_060a3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060A3CULL;
}

// FDE #1172 | PC: 0x060a64..0x060a8c (40 B) | Symbol: sub_060a64
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e564; b.lt #0x60a80] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e564; b.lt #0x60a80]
uint64_t fde_sub_060a64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060A64ULL;
}

// FDE #1173 | PC: 0x060a8c..0x060b54 (200 B) | Symbol: sub_060a8c
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x2] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x2]
uint64_t fde_sub_060a8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060A8CULL;
}

// FDE #1174 | PC: 0x060b54..0x060b90 (60 B) | Symbol: sub_060b54
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9a000; add x8, x8, #0x8d8] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9a000; add x8, x8, #0x8d8]
uint64_t fde_sub_060b54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060B54ULL;
}

// FDE #1175 | PC: 0x060b90..0x060ba8 (24 B) | Symbol: sub_060b90
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x60b54; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x60b54; mov x0, x19]
uint64_t fde_sub_060b90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060B90ULL;
}

// FDE #1176 | PC: 0x060ba8..0x060bd0 (40 B) | Symbol: sub_060ba8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5d270; ldr x0, [x19, #0xe0]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x5d270; ldr x0, [x19, #0xe0]]
uint64_t fde_sub_060ba8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060BA8ULL;
}

// FDE #1177 | PC: 0x060bd0..0x060c50 (128 B) | Symbol: sub_060bd0
// EN: AArch64 prologue [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldrb w8, [x0, #0x28]] | VI: Khởi đầu hàm AArch64 [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldrb w8, [x0, #0x28]]
uint64_t fde_sub_060bd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xA9BD5BF7ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060BD0ULL;
}

// FDE #1178 | PC: 0x060c50..0x060c90 (64 B) | Symbol: sub_060c50
// EN: AArch64 prologue [and w8, w1, #0xffff; cmp w8, #0xca; mov x2, x0; b.eq #0x60c78] | VI: Khởi đầu hàm AArch64 [and w8, w1, #0xffff; cmp w8, #0xca; mov x2, x0; b.eq #0x60c78]
uint64_t fde_sub_060c50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7103291FULL) << 32) | 0x12003C28ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060C50ULL;
}

// FDE #1179 | PC: 0x060c90..0x060c98 (8 B) | Symbol: sub_060c90
// EN: AArch64 prologue [sub x0, x0, #8; b #0x60b54] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x60b54]
uint64_t fde_sub_060c90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFB0ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060C90ULL;
}

// FDE #1180 | PC: 0x060c98..0x060ca0 (8 B) | Symbol: sub_060c98
// EN: AArch64 prologue [sub x0, x0, #8; b #0x60b90] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x60b90]
uint64_t fde_sub_060c98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFBDULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060C98ULL;
}

// FDE #1181 | PC: 0x060ca0..0x060ca8 (8 B) | Symbol: sub_060ca0
// EN: AArch64 prologue [sub x0, x0, #8; b #0x60c50] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x60c50]
uint64_t fde_sub_060ca0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFEBULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060CA0ULL;
}

// FDE #1182 | PC: 0x060ca8..0x060cb0 (8 B) | Symbol: sub_060ca8
// EN: AArch64 prologue [sub x0, x0, #8; b #0x60ba8] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x60ba8]
uint64_t fde_sub_060ca8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFBFULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060CA8ULL;
}

// FDE #1183 | PC: 0x060cb0..0x060cb8 (8 B) | Symbol: sub_060cb0
// EN: AArch64 prologue [sub x0, x0, #8; b #0x60bd0] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #8; b #0x60bd0]
uint64_t fde_sub_060cb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFC7ULL) << 32) | 0xD1002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060CB0ULL;
}

// FDE #1184 | PC: 0x060cb8..0x060de8 (304 B) | Symbol: sub_060cb8
// EN: AArch64 prologue [sub sp, sp, #0x180; stp x28, x22, [sp, #0x150]; stp x21, x20, [sp, #0x160]; stp x19, x30, [sp, #0x170]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x180; stp x28, x22, [sp, #0x150]; stp x21, x20, [sp, #0x160]; stp x19, x30, [sp, #0x170]]
uint64_t fde_sub_060cb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9155BFCULL) << 32) | 0xD10603FFULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060CB8ULL;
}

// FDE #1185 | PC: 0x060de8..0x060f74 (396 B) | Symbol: sub_060de8
// EN: AArch64 prologue [mov x2, x30; bl #0x8fc50; mov x30, x2; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8fc50; mov x30, x2; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_060de8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400BB99ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x018CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060DE8ULL;
}

// FDE #1186 | PC: 0x060f74..0x060fa8 (52 B) | Symbol: sub_060f74
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; ldp x8, x9, [x1]; mov x19, x0; cbz x9, #0x60f90] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; ldp x8, x9, [x1]; mov x19, x0; cbz x9, #0x60f90]
uint64_t fde_sub_060f74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9402428ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060F74ULL;
}

// FDE #1187 | PC: 0x060fa8..0x060ffc (84 B) | Symbol: sub_060fa8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9a000; add x8, x8, #0x9c8; bl #0x8f8e8] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9a000; add x8, x8, #0x9c8; bl #0x8f8e8]
uint64_t fde_sub_060fa8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00001C8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060FA8ULL;
}

// FDE #1188 | PC: 0x060ffc..0x061014 (24 B) | Symbol: sub_060ffc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x60fa8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x60fa8; mov x0, x19]
uint64_t fde_sub_060ffc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060FFCULL;
}

// FDE #1189 | PC: 0x061014..0x061020 (12 B) | Symbol: sub_061014
// EN: AArch64 prologue [ldr x8, [x0, #0x50]; add x0, x8, #0x38; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x50]; add x0, x8, #0x38; ret]
uint64_t fde_sub_061014(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9100E100ULL) << 32) | 0xF9402808ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061014ULL;
}

// FDE #1190 | PC: 0x061020..0x061034 (20 B) | Symbol: sub_061020
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x91db8; mov x0, x19; ldp x19, x30, [sp], #0x10] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x91db8; mov x0, x19; ldp x19, x30, [sp], #0x10]
uint64_t fde_sub_061020(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400C365ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061020ULL;
}

// FDE #1191 | PC: 0x061034..0x061064 (48 B) | Symbol: sub_061034
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e3d4; ldr x8, [x20, #0x1c8]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e3d4; ldr x8, [x20, #0x1c8]]
uint64_t fde_sub_061034(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061034ULL;
}

// FDE #1192 | PC: 0x061064..0x0612a0 (572 B) | Symbol: sub_061064
// EN: AArch64 prologue [sub sp, sp, #0x70; str d8, [sp, #0x20]; str x26, [sp, #0x28]; stp x25, x24, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str d8, [sp, #0x20]; str x26, [sp, #0x28]; stp x25, x24, [sp, #0x30]]
uint64_t fde_sub_061064(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0013E8ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x023CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061064ULL;
}

// FDE #1193 | PC: 0x0612a0..0x0612a8 (8 B) | Symbol: sub_0612a0
// EN: AArch64 prologue [add x0, x0, #0x180; b #0x613a4] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x180; b #0x613a4]
uint64_t fde_sub_0612a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000040ULL) << 32) | 0x91060000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0612A0ULL;
}

// FDE #1194 | PC: 0x0612a8..0x06134c (164 B) | Symbol: sub_0612a8
// EN: AArch64 prologue [sub sp, sp, #0x170; str x28, [sp, #0x130]; stp x23, x22, [sp, #0x140]; stp x21, x20, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; str x28, [sp, #0x130]; stp x23, x22, [sp, #0x140]; stp x21, x20, [sp, #0x150]]
uint64_t fde_sub_0612a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9009BFCULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0612A8ULL;
}

// FDE #1195 | PC: 0x06134c..0x06135c (16 B) | Symbol: sub_06134c
// EN: AArch64 prologue [ldr x0, [x0, #0x178]; cbz x0, #0x61358; b #0x8f94c; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x178]; cbz x0, #0x61358; b #0x8f94c; ret]
uint64_t fde_sub_06134c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000040ULL) << 32) | 0xF940BC00ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06134CULL;
}

// FDE #1196 | PC: 0x06135c..0x061364 (8 B) | Symbol: sub_06135c
// EN: AArch64 prologue [sub x0, x0, #0x28; b #0x60fa8] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x28; b #0x60fa8]
uint64_t fde_sub_06135c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF12ULL) << 32) | 0xD100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06135CULL;
}

// FDE #1197 | PC: 0x061364..0x06136c (8 B) | Symbol: sub_061364
// EN: AArch64 prologue [sub x0, x0, #0x28; b #0x60ffc] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x28; b #0x60ffc]
uint64_t fde_sub_061364(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF25ULL) << 32) | 0xD100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061364ULL;
}

// FDE #1198 | PC: 0x06136c..0x061374 (8 B) | Symbol: sub_06136c
// EN: AArch64 prologue [sub x0, x0, #0x48; b #0x60fa8] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x48; b #0x60fa8]
uint64_t fde_sub_06136c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF0EULL) << 32) | 0xD1012000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06136CULL;
}

// FDE #1199 | PC: 0x061374..0x06137c (8 B) | Symbol: sub_061374
// EN: AArch64 prologue [sub x0, x0, #0x48; b #0x60ffc] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x48; b #0x60ffc]
uint64_t fde_sub_061374(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF21ULL) << 32) | 0xD1012000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061374ULL;
}

// FDE #1200 | PC: 0x06137c..0x061384 (8 B) | Symbol: sub_06137c
// EN: AArch64 prologue [sub x0, x0, #0x190; b #0x60fa8] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x190; b #0x60fa8]
uint64_t fde_sub_06137c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF0AULL) << 32) | 0xD1064000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06137CULL;
}

// FDE #1201 | PC: 0x061384..0x06138c (8 B) | Symbol: sub_061384
// EN: AArch64 prologue [sub x0, x0, #0x190; b #0x60ffc] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x190; b #0x60ffc]
uint64_t fde_sub_061384(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF1DULL) << 32) | 0xD1064000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061384ULL;
}

// FDE #1202 | PC: 0x06138c..0x061394 (8 B) | Symbol: sub_06138c
// EN: AArch64 prologue [sub x0, x0, #0x190; b #0x612a8] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x190; b #0x612a8]
uint64_t fde_sub_06138c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFC6ULL) << 32) | 0xD1064000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06138CULL;
}

// FDE #1203 | PC: 0x061394..0x0613a4 (16 B) | Symbol: sub_061394
// EN: AArch64 prologue [ldur x0, [x0, #-0x18]; cbz x0, #0x613a0; b #0x8f94c; ret] | VI: Khởi đầu hàm AArch64 [ldur x0, [x0, #-0x18]; cbz x0, #0x613a0; b #0x8f94c; ret]
uint64_t fde_sub_061394(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000040ULL) << 32) | 0xF85E8000ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061394ULL;
}

// FDE #1204 | PC: 0x0613a4..0x0613bc (24 B) | Symbol: sub_0613a4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8d530; bl #0x48d40; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8d530; bl #0x48d40; mov x0, x19]
uint64_t fde_sub_0613a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400B062ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0613A4ULL;
}

// FDE #1205 | PC: 0x0613bc..0x0617f4 (1080 B) | Symbol: sub_0613bc
// EN: AArch64 prologue [sub sp, sp, #0x1f0; str x28, [sp, #0x190]; stp x27, x26, [sp, #0x1a0]; stp x25, x24, [sp, #0x1b0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1f0; str x28, [sp, #0x190]; stp x27, x26, [sp, #0x1a0]; stp x25, x24, [sp, #0x1b0]]
uint64_t fde_sub_0613bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900CBFCULL) << 32) | 0xD107C3FFULL;
    const uint64_t kPcRange = 0x0438ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0613BCULL;
}

// FDE #1206 | PC: 0x0617f4..0x06186c (120 B) | Symbol: sub_0617f4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0xa0000; add x8, x8, #0x148; ldarb w8, [x8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0xa0000; add x8, x8, #0x148; ldarb w8, [x8]]
uint64_t fde_sub_0617f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00001E8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0617F4ULL;
}

// FDE #1207 | PC: 0x06186c..0x06187c (16 B) | Symbol: sub_06186c
// EN: AArch64 prologue [ldr x0, [x0, #8]; ldr x8, [x0]; ldr x3, [x8, #0xc0]; br x3] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #8]; ldr x8, [x0]; ldr x3, [x8, #0xc0]; br x3]
uint64_t fde_sub_06186c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xF9400400ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06186CULL;
}

// FDE #1208 | PC: 0x06187c..0x061940 (196 B) | Symbol: sub_06187c
// EN: AArch64 prologue [mov x0, x30; bl #0x90b54; mov x30, x0; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x0, x30; bl #0x90b54; mov x30, x0; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_06187c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400BCB5ULL) << 32) | 0xAA1E03E0ULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06187CULL;
}

// FDE #1209 | PC: 0x061940..0x061994 (84 B) | Symbol: sub_061940
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov w0, #0x50; bl #0x8f1c0; adrp x8, #0x1b000] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov w0, #0x50; bl #0x8f1c0; adrp x8, #0x1b000]
uint64_t fde_sub_061940(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800A00ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061940ULL;
}

// FDE #1210 | PC: 0x061994..0x061998 (4 B) | Symbol: sub_061994
// EN: AArch64 prologue [b #0x93310] | VI: Khởi đầu hàm AArch64 [b #0x93310]
uint64_t fde_sub_061994(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF4ULL) << 32) | 0x1400C65FULL;
    const uint64_t kPcRange = 0x0004ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061994ULL;
}

// FDE #1211 | PC: 0x061998..0x061a78 (224 B) | Symbol: sub_061998
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9a000; add x8, x8, #0xbd0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9a000; add x8, x8, #0xbd0]
uint64_t fde_sub_061998(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061998ULL;
}

// FDE #1212 | PC: 0x061a78..0x061a80 (8 B) | Symbol: sub_061a78
// EN: AArch64 prologue [mov x1, xzr; b #0x61ab8] | VI: Khởi đầu hàm AArch64 [mov x1, xzr; b #0x61ab8]
uint64_t fde_sub_061a78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400000FULL) << 32) | 0xAA1F03E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061A78ULL;
}

// FDE #1213 | PC: 0x061a80..0x061aa0 (32 B) | Symbol: sub_061a80
// EN: AArch64 prologue [ldr x8, [x0, #8]; adrp x9, #0x9a000; add x9, x9, #0xbb0; str x9, [x0]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; adrp x9, #0x9a000; add x9, x9, #0xbb0; str x9, [x0]]
uint64_t fde_sub_061a80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00001C9ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061A80ULL;
}

// FDE #1214 | PC: 0x061aa0..0x061ab8 (24 B) | Symbol: sub_061aa0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x61a80; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x61a80; mov x0, x19]
uint64_t fde_sub_061aa0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061AA0ULL;
}

// FDE #1215 | PC: 0x061ab8..0x061b2c (116 B) | Symbol: sub_061ab8
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8dcc8; cbz x19, #0x61ae8] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8dcc8; cbz x19, #0x61ae8]
uint64_t fde_sub_061ab8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061AB8ULL;
}

// FDE #1216 | PC: 0x061b2c..0x061c50 (292 B) | Symbol: sub_061b2c
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x911ec; adrp x8, #0x9a000] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x911ec; adrp x8, #0x9a000]
uint64_t fde_sub_061b2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0124ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061B2CULL;
}

// FDE #1217 | PC: 0x061c50..0x061ccc (124 B) | Symbol: sub_061c50
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; mov x0, x1] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; mov x0, x1]
uint64_t fde_sub_061c50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061C50ULL;
}

// FDE #1218 | PC: 0x061ccc..0x061cf0 (36 B) | Symbol: sub_061ccc
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; ldr x0, [x0, #0xb0]; cbz x0, #0x61ce4; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; ldr x0, [x0, #0xb0]; cbz x0, #0x61ce4; ldr x8, [x0]]
uint64_t fde_sub_061ccc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9405800ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061CCCULL;
}

// FDE #1219 | PC: 0x061cf0..0x061dc4 (212 B) | Symbol: sub_061cf0
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x25, x24, [sp, #0x30]; stp x23, x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x25, x24, [sp, #0x30]; stp x23, x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]]
uint64_t fde_sub_061cf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90363F9ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061CF0ULL;
}

// FDE #1220 | PC: 0x061dc4..0x062184 (960 B) | Symbol: sub_061dc4
// EN: AArch64 prologue [mov x1, x30; bl #0x90cf0; mov x30, x1; stp x19, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [mov x1, x30; bl #0x90cf0; mov x30, x1; stp x19, x30, [sp, #0x60]]
uint64_t fde_sub_061dc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400BBCAULL) << 32) | 0xAA1E03E1ULL;
    const uint64_t kPcRange = 0x03C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061DC4ULL;
}

// FDE #1221 | PC: 0x062184..0x0627f0 (1644 B) | Symbol: sub_062184
// EN: AArch64 prologue [sub sp, sp, #0xa0; str d10, [sp, #0x20]; stp d9, d8, [sp, #0x30]; mov x4, x30] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; str d10, [sp, #0x20]; stp d9, d8, [sp, #0x30]; mov x4, x30]
uint64_t fde_sub_062184(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0013EAULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x066CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062184ULL;
}

// FDE #1222 | PC: 0x0627f0..0x062890 (160 B) | Symbol: sub_0627f0
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov w20, w3; mov x21, x2] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov w20, w3; mov x21, x2]
uint64_t fde_sub_0627f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0627F0ULL;
}

// FDE #1223 | PC: 0x062890..0x0629b8 (296 B) | Symbol: sub_062890
// EN: AArch64 prologue [str d8, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr x20, [x0, #0xb0]] | VI: Khởi đầu hàm AArch64 [str d8, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr x20, [x0, #0xb0]]
uint64_t fde_sub_062890(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xFC1D0FE8ULL;
    const uint64_t kPcRange = 0x0128ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062890ULL;
}

// FDE #1224 | PC: 0x0629b8..0x062a54 (156 B) | Symbol: sub_0629b8
// EN: AArch64 prologue [stp d9, d8, [sp, #-0x30]!; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldrb w8, [x0, #0x140]] | VI: Khởi đầu hàm AArch64 [stp d9, d8, [sp, #-0x30]!; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldrb w8, [x0, #0x140]]
uint64_t fde_sub_0629b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF4ULL) << 32) | 0x6DBD23E9ULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0629B8ULL;
}

// FDE #1225 | PC: 0x062a54..0x062a5c (8 B) | Symbol: sub_062a54
// EN: AArch64 prologue [sub x0, x0, #0x28; b #0x61998] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x28; b #0x61998]
uint64_t fde_sub_062a54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFBD0ULL) << 32) | 0xD100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062A54ULL;
}

// FDE #1226 | PC: 0x062a5c..0x062a64 (8 B) | Symbol: sub_062a5c
// EN: AArch64 prologue [sub x0, x0, #0x48; b #0x61998] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x48; b #0x61998]
uint64_t fde_sub_062a5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFBCEULL) << 32) | 0xD1012000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062A5CULL;
}

// FDE #1227 | PC: 0x062a64..0x062b54 (240 B) | Symbol: sub_062a64
// EN: AArch64 prologue [stp x27, x26, [sp, #-0x50]!; stp x25, x24, [sp, #0x10]; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x27, x26, [sp, #-0x50]!; stp x25, x24, [sp, #0x10]; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]]
uint64_t fde_sub_062a64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90163F9ULL) << 32) | 0xA9BB6BFBULL;
    const uint64_t kPcRange = 0x00F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062A64ULL;
}

// FDE #1228 | PC: 0x062b54..0x062b8c (56 B) | Symbol: sub_062b54
// EN: AArch64 prologue [sub sp, sp, #0x20; str x30, [sp, #0x10]; adrp x9, #0x1b000; ldr q0, [x0, #0xf0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; str x30, [sp, #0x10]; adrp x9, #0x1b000; ldr q0, [x0, #0xf0]]
uint64_t fde_sub_062b54(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BFEULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062B54ULL;
}

// FDE #1229 | PC: 0x062b8c..0x062c5c (208 B) | Symbol: sub_062b8c
// EN: AArch64 prologue [stp x25, x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x25, x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_062b8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xA9BC63F9ULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062B8CULL;
}

// FDE #1230 | PC: 0x062c5c..0x062cb0 (84 B) | Symbol: sub_062c5c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x90a44; ldr x0, [x8, #0x148]; bl #0x8d460] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x90a44; ldr x0, [x8, #0x148]; bl #0x8d460]
uint64_t fde_sub_062c5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400B779ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062C5CULL;
}

// FDE #1231 | PC: 0x062cb0..0x062ccc (28 B) | Symbol: sub_062cb0
// EN: AArch64 prologue [ldr x8, [x0, #0x50]; ldr x8, [x8, #0xe0]; cbnz x8, #0x62cc8; ldr x0, [x0, #0x80]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x50]; ldr x8, [x8, #0xe0]; cbnz x8, #0x62cc8; ldr x0, [x0, #0x80]]
uint64_t fde_sub_062cb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9407108ULL) << 32) | 0xF9402808ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062CB0ULL;
}

// FDE #1232 | PC: 0x062ccc..0x062ce8 (28 B) | Symbol: sub_062ccc
// EN: AArch64 prologue [ldr x8, [x0, #0x50]; ldr x8, [x8, #0xe8]; cbnz x8, #0x62ce4; ldr x0, [x0, #0x80]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x50]; ldr x8, [x8, #0xe8]; cbnz x8, #0x62ce4; ldr x0, [x0, #0x80]]
uint64_t fde_sub_062ccc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9407508ULL) << 32) | 0xF9402808ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062CCCULL;
}

// FDE #1233 | PC: 0x062ce8..0x062d58 (112 B) | Symbol: sub_062ce8
// EN: AArch64 prologue [sub sp, sp, #0x30; str d8, [sp, #0x10]; str x20, [sp, #0x18]; stp x19, x30, [sp, #0x20]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; str d8, [sp, #0x10]; str x20, [sp, #0x18]; stp x19, x30, [sp, #0x20]]
uint64_t fde_sub_062ce8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD000BE8ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062CE8ULL;
}

// FDE #1234 | PC: 0x062d58..0x062dd8 (128 B) | Symbol: sub_062d58
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8f9c4] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8f9c4]
uint64_t fde_sub_062d58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062D58ULL;
}

// FDE #1235 | PC: 0x062dd8..0x062dfc (36 B) | Symbol: sub_062dd8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9a000; add x8, x8, #0xd08; bl #0x8e03c] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9a000; add x8, x8, #0xd08; bl #0x8e03c]
uint64_t fde_sub_062dd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900001C8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062DD8ULL;
}

// FDE #1236 | PC: 0x062dfc..0x062e14 (24 B) | Symbol: sub_062dfc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x62dd8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x62dd8; mov x0, x19]
uint64_t fde_sub_062dfc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062DFCULL;
}

// FDE #1237 | PC: 0x062e14..0x062e38 (36 B) | Symbol: sub_062e14
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x91db8; ldr x0, [x19, #0x190]; cbz x0, #0x62e30] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x91db8; ldr x0, [x19, #0x190]; cbz x0, #0x62e30]
uint64_t fde_sub_062e14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400BBE8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062E14ULL;
}

// FDE #1238 | PC: 0x062e38..0x062e40 (8 B) | Symbol: sub_062e38
// EN: AArch64 prologue [sub x0, x0, #0x28; b #0x62dd8] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x28; b #0x62dd8]
uint64_t fde_sub_062e38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFE7ULL) << 32) | 0xD100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062E38ULL;
}

// FDE #1239 | PC: 0x062e40..0x062e48 (8 B) | Symbol: sub_062e40
// EN: AArch64 prologue [sub x0, x0, #0x28; b #0x62dfc] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x28; b #0x62dfc]
uint64_t fde_sub_062e40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFEEULL) << 32) | 0xD100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062E40ULL;
}

// FDE #1240 | PC: 0x062e48..0x062e50 (8 B) | Symbol: sub_062e48
// EN: AArch64 prologue [sub x0, x0, #0x48; b #0x62dd8] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x48; b #0x62dd8]
uint64_t fde_sub_062e48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFE3ULL) << 32) | 0xD1012000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062E48ULL;
}

// FDE #1241 | PC: 0x062e50..0x062e58 (8 B) | Symbol: sub_062e50
// EN: AArch64 prologue [sub x0, x0, #0x48; b #0x62dfc] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x48; b #0x62dfc]
uint64_t fde_sub_062e50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFEAULL) << 32) | 0xD1012000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062E50ULL;
}

// FDE #1242 | PC: 0x062e58..0x063064 (524 B) | Symbol: sub_062e58
// EN: AArch64 prologue [sub sp, sp, #0x60; str d10, [sp, #0x20]; stp d9, d8, [sp, #0x28]; str x22, [sp, #0x38]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str d10, [sp, #0x20]; stp d9, d8, [sp, #0x28]; str x22, [sp, #0x38]]
uint64_t fde_sub_062e58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0013EAULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x020CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062E58ULL;
}

// FDE #1243 | PC: 0x063064..0x0630d0 (108 B) | Symbol: sub_063064
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x91d74; adrp x8, #0x9a000; add x8, x8, #0xe18] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x91d74; adrp x8, #0x9a000; add x8, x8, #0xe18]
uint64_t fde_sub_063064(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400BB43ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063064ULL;
}

// FDE #1244 | PC: 0x0630d0..0x063134 (100 B) | Symbol: sub_0630d0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9a000; add x8, x8, #0xe18; bl #0x8f8e8] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9a000; add x8, x8, #0xe18; bl #0x8f8e8]
uint64_t fde_sub_0630d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00001A8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0630D0ULL;
}

// FDE #1245 | PC: 0x063134..0x06314c (24 B) | Symbol: sub_063134
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x630d0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x630d0; mov x0, x19]
uint64_t fde_sub_063134(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063134ULL;
}

// FDE #1246 | PC: 0x06314c..0x0637c0 (1652 B) | Symbol: sub_06314c
// EN: AArch64 prologue [mov x1, x30; bl #0x8d63c; mov x30, x1; stp x29, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [mov x1, x30; bl #0x8d63c; mov x30, x1; stp x29, x30, [sp, #0x50]]
uint64_t fde_sub_06314c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400A93BULL) << 32) | 0xAA1E03E1ULL;
    const uint64_t kPcRange = 0x0674ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06314CULL;
}

// FDE #1247 | PC: 0x0637c0..0x063818 (88 B) | Symbol: sub_0637c0
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8e3d4] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8e3d4]
uint64_t fde_sub_0637c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0637C0ULL;
}

// FDE #1248 | PC: 0x063818..0x063944 (300 B) | Symbol: sub_063818
// EN: AArch64 prologue [stp d9, d8, [sp, #-0x30]!; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov v8.16b, v0.16b] | VI: Khởi đầu hàm AArch64 [stp d9, d8, [sp, #-0x30]!; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov v8.16b, v0.16b]
uint64_t fde_sub_063818(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF4ULL) << 32) | 0x6DBD23E9ULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063818ULL;
}

// FDE #1249 | PC: 0x063944..0x0639e8 (164 B) | Symbol: sub_063944
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_063944(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063944ULL;
}

// FDE #1250 | PC: 0x0639e8..0x063a18 (48 B) | Symbol: sub_0639e8
// EN: AArch64 prologue [str x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_0639e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xF81C0FF8ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0639E8ULL;
}

// FDE #1251 | PC: 0x063a18..0x063a5c (68 B) | Symbol: sub_063a18
// EN: AArch64 prologue [stp d9, d8, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldp x20, x21, [x0, #0x198]] | VI: Khởi đầu hàm AArch64 [stp d9, d8, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldp x20, x21, [x0, #0x198]]
uint64_t fde_sub_063a18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0x6DBD23E9ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063A18ULL;
}

// FDE #1252 | PC: 0x063a5c..0x063a70 (20 B) | Symbol: sub_063a5c
// EN: AArch64 prologue [ldr x0, [x0, #0x178]; cbz x0, #0x63a6c; ldr x8, [x0]; b #0x920dc] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x178]; cbz x0, #0x63a6c; ldr x8, [x0]; b #0x920dc]
uint64_t fde_sub_063a5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000060ULL) << 32) | 0xF940BC00ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063A5CULL;
}

// FDE #1253 | PC: 0x063a70..0x063a78 (8 B) | Symbol: sub_063a70
// EN: AArch64 prologue [sub x0, x0, #0x28; b #0x630d0] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x28; b #0x630d0]
uint64_t fde_sub_063a70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFD97ULL) << 32) | 0xD100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063A70ULL;
}

// FDE #1254 | PC: 0x063a78..0x063a80 (8 B) | Symbol: sub_063a78
// EN: AArch64 prologue [sub x0, x0, #0x28; b #0x63134] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x28; b #0x63134]
uint64_t fde_sub_063a78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFDAEULL) << 32) | 0xD100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063A78ULL;
}

// FDE #1255 | PC: 0x063a80..0x063a88 (8 B) | Symbol: sub_063a80
// EN: AArch64 prologue [sub x0, x0, #0x48; b #0x630d0] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x48; b #0x630d0]
uint64_t fde_sub_063a80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFD93ULL) << 32) | 0xD1012000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063A80ULL;
}

// FDE #1256 | PC: 0x063a88..0x063a90 (8 B) | Symbol: sub_063a88
// EN: AArch64 prologue [sub x0, x0, #0x48; b #0x63134] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x48; b #0x63134]
uint64_t fde_sub_063a88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFDAAULL) << 32) | 0xD1012000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063A88ULL;
}

// FDE #1257 | PC: 0x063a90..0x063a98 (8 B) | Symbol: sub_063a90
// EN: AArch64 prologue [sub x0, x0, #0x190; b #0x630d0] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x190; b #0x630d0]
uint64_t fde_sub_063a90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFD8FULL) << 32) | 0xD1064000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063A90ULL;
}

// FDE #1258 | PC: 0x063a98..0x063aa0 (8 B) | Symbol: sub_063a98
// EN: AArch64 prologue [sub x0, x0, #0x190; b #0x63134] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x190; b #0x63134]
uint64_t fde_sub_063a98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFDA6ULL) << 32) | 0xD1064000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063A98ULL;
}

// FDE #1259 | PC: 0x063aa0..0x063ab4 (20 B) | Symbol: sub_063aa0
// EN: AArch64 prologue [ldur x0, [x0, #-0x18]; cbz x0, #0x63ab0; ldr x8, [x0]; b #0x920dc] | VI: Khởi đầu hàm AArch64 [ldur x0, [x0, #-0x18]; cbz x0, #0x63ab0; ldr x8, [x0]; b #0x920dc]
uint64_t fde_sub_063aa0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000060ULL) << 32) | 0xF85E8000ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063AA0ULL;
}

// FDE #1260 | PC: 0x063ab4..0x063c9c (488 B) | Symbol: sub_063ab4
// EN: AArch64 prologue [sub sp, sp, #0x80; stp d9, d8, [sp, #0x20]; str x26, [sp, #0x30]; stp x25, x24, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp d9, d8, [sp, #0x20]; str x26, [sp, #0x30]; stp x25, x24, [sp, #0x40]]
uint64_t fde_sub_063ab4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D0223E9ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x01E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063AB4ULL;
}

// FDE #1261 | PC: 0x063c9c..0x063cb4 (24 B) | Symbol: sub_063c9c
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x63cb4; mvn w8, w0; and w0, w8, #1] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x63cb4; mvn w8, w0; and w0, w8, #1]
uint64_t fde_sub_063c9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94000005ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063C9CULL;
}

// FDE #1262 | PC: 0x063cb4..0x063d04 (80 B) | Symbol: sub_063cb4
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8eb14; ldrb w8, [x20]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8eb14; ldrb w8, [x20]]
uint64_t fde_sub_063cb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063CB4ULL;
}

// FDE #1263 | PC: 0x063d04..0x063d7c (120 B) | Symbol: sub_063d04
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldrb w8, [x0]; mov x19, x4] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldrb w8, [x0]; mov x19, x4]
uint64_t fde_sub_063d04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063D04ULL;
}

// FDE #1264 | PC: 0x063d7c..0x063e10 (148 B) | Symbol: sub_063d7c
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8d614] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8d614]
uint64_t fde_sub_063d7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063D7CULL;
}

// FDE #1265 | PC: 0x063e10..0x063eb0 (160 B) | Symbol: sub_063e10
// EN: AArch64 prologue [cbz x1, #0x63ea8; fmov d0, x1; mov x3, x30; bl #0x8de04] | VI: Khởi đầu hàm AArch64 [cbz x1, #0x63ea8; fmov d0, x1; mov x3, x30; bl #0x8de04]
uint64_t fde_sub_063e10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9E670020ULL) << 32) | 0xB40004C1ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063E10ULL;
}

// FDE #1266 | PC: 0x063eb0..0x064068 (440 B) | Symbol: sub_063eb0
// EN: AArch64 prologue [sub sp, sp, #0x70; str x26, [sp, #0x20]; stp x25, x24, [sp, #0x30]; stp x23, x22, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x26, [sp, #0x20]; stp x25, x24, [sp, #0x30]; stp x23, x22, [sp, #0x40]]
uint64_t fde_sub_063eb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013FAULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063EB0ULL;
}

// FDE #1267 | PC: 0x064068..0x064070 (8 B) | Symbol: sub_064068
// EN: AArch64 prologue [mov w0, #0x20; b #0x93320] | VI: Khởi đầu hàm AArch64 [mov w0, #0x20; b #0x93320]
uint64_t fde_sub_064068(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400BCADULL) << 32) | 0x52800400ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064068ULL;
}

// FDE #1268 | PC: 0x064070..0x064128 (184 B) | Symbol: sub_064070
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8e990] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; bl #0x8e990]
uint64_t fde_sub_064070(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90253F5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064070ULL;
}

// FDE #1269 | PC: 0x064128..0x064164 (60 B) | Symbol: sub_064128
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9a000; add x8, x8, #0xf68; bl #0x8e03c] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9a000; add x8, x8, #0xf68; bl #0x8e03c]
uint64_t fde_sub_064128(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD00001A8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064128ULL;
}

// FDE #1270 | PC: 0x064164..0x06417c (24 B) | Symbol: sub_064164
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x64128; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x64128; mov x0, x19]
uint64_t fde_sub_064164(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064164ULL;
}

// FDE #1271 | PC: 0x06417c..0x064194 (24 B) | Symbol: sub_06417c
// EN: AArch64 prologue [and w8, w1, #0xffff; cmp w8, #0xca; b.ne #0x64190; add x8, x0, #0x1c8] | VI: Khởi đầu hàm AArch64 [and w8, w1, #0xffff; cmp w8, #0xca; b.ne #0x64190; add x8, x0, #0x1c8]
uint64_t fde_sub_06417c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7103291FULL) << 32) | 0x12003C28ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06417CULL;
}

// FDE #1272 | PC: 0x064194..0x0641dc (72 B) | Symbol: sub_064194
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x91db8; bl #0x93094] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x91db8; bl #0x93094]
uint64_t fde_sub_064194(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064194ULL;
}

// FDE #1273 | PC: 0x0641dc..0x06420c (48 B) | Symbol: sub_0641dc
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e3d4; ldr x8, [x20, #0x1b8]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e3d4; ldr x8, [x20, #0x1b8]]
uint64_t fde_sub_0641dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0641DCULL;
}

// FDE #1274 | PC: 0x06420c..0x0644d4 (712 B) | Symbol: sub_06420c
// EN: AArch64 prologue [sub sp, sp, #0xe0; str d8, [sp, #0x70]; stp x28, x27, [sp, #0x80]; stp x26, x25, [sp, #0x90]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xe0; str d8, [sp, #0x70]; stp x28, x27, [sp, #0x80]; stp x26, x25, [sp, #0x90]]
uint64_t fde_sub_06420c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD003BE8ULL) << 32) | 0xD10383FFULL;
    const uint64_t kPcRange = 0x02C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06420CULL;
}

// FDE #1275 | PC: 0x0644d4..0x0644dc (8 B) | Symbol: sub_0644d4
// EN: AArch64 prologue [sub x0, x0, #0x28; b #0x64128] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x28; b #0x64128]
uint64_t fde_sub_0644d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF14ULL) << 32) | 0xD100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0644D4ULL;
}

// FDE #1276 | PC: 0x0644dc..0x0644e4 (8 B) | Symbol: sub_0644dc
// EN: AArch64 prologue [sub x0, x0, #0x28; b #0x64164] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x28; b #0x64164]
uint64_t fde_sub_0644dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF21ULL) << 32) | 0xD100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0644DCULL;
}

// FDE #1277 | PC: 0x0644e4..0x0644ec (8 B) | Symbol: sub_0644e4
// EN: AArch64 prologue [sub x0, x0, #0x48; b #0x64128] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x48; b #0x64128]
uint64_t fde_sub_0644e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF10ULL) << 32) | 0xD1012000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0644E4ULL;
}

// FDE #1278 | PC: 0x0644ec..0x0644f4 (8 B) | Symbol: sub_0644ec
// EN: AArch64 prologue [sub x0, x0, #0x48; b #0x64164] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x48; b #0x64164]
uint64_t fde_sub_0644ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF1DULL) << 32) | 0xD1012000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0644ECULL;
}

// FDE #1279 | PC: 0x0644f4..0x064684 (400 B) | Symbol: sub_0644f4
// EN: AArch64 prologue [mov x2, x30; bl #0x8fc50; mov x30, x2; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x8fc50; mov x30, x2; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_0644f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400ADD6ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0190ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0644F4ULL;
}

// FDE #1280 | PC: 0x064684..0x06469c (24 B) | Symbol: sub_064684
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x61998; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x61998; mov x0, x19]
uint64_t fde_sub_064684(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064684ULL;
}

// FDE #1281 | PC: 0x06469c..0x0646b8 (28 B) | Symbol: sub_06469c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; and w3, w3, #1; mov x19, x1; bl #0x627f0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; and w3, w3, #1; mov x19, x1; bl #0x627f0]
uint64_t fde_sub_06469c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12000063ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06469CULL;
}

// FDE #1282 | PC: 0x0646b8..0x0646c0 (8 B) | Symbol: sub_0646b8
// EN: AArch64 prologue [sub x0, x0, #0x28; b #0x64684] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x28; b #0x64684]
uint64_t fde_sub_0646b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF2ULL) << 32) | 0xD100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0646B8ULL;
}

// FDE #1283 | PC: 0x0646c0..0x0646c8 (8 B) | Symbol: sub_0646c0
// EN: AArch64 prologue [sub x0, x0, #0x48; b #0x64684] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x48; b #0x64684]
uint64_t fde_sub_0646c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFFF0ULL) << 32) | 0xD1012000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0646C0ULL;
}

// FDE #1284 | PC: 0x0646c8..0x0646e4 (28 B) | Symbol: sub_0646c8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x18; bl #0x646e4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x18; bl #0x646e4]
uint64_t fde_sub_0646c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0646C8ULL;
}

// FDE #1285 | PC: 0x0646e4..0x06470c (40 B) | Symbol: sub_0646e4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; ldr x8, [x0]; cbz x8, #0x64704; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; ldr x8, [x0]; cbz x8, #0x64704; mov x19, x0]
uint64_t fde_sub_0646e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0646E4ULL;
}

// FDE #1286 | PC: 0x06470c..0x06473c (48 B) | Symbol: sub_06470c
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldp x21, x20, [x0]; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldp x21, x20, [x0]; mov x19, x0]
uint64_t fde_sub_06470c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06470CULL;
}

// FDE #1287 | PC: 0x06473c..0x064754 (24 B) | Symbol: sub_06473c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x91d74; bl #0x8fbe8; stp xzr, xzr, [x19, #0x190]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x91d74; bl #0x8fbe8; stp xzr, xzr, [x19, #0x190]]
uint64_t fde_sub_06473c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400B58DULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06473CULL;
}

// FDE #1288 | PC: 0x064754..0x064784 (48 B) | Symbol: sub_064754
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x198]; bl #0x8fbe8] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x198]; bl #0x8fbe8]
uint64_t fde_sub_064754(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064754ULL;
}

// FDE #1289 | PC: 0x064784..0x06479c (24 B) | Symbol: sub_064784
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x64754; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x64754; mov x0, x19]
uint64_t fde_sub_064784(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064784ULL;
}

// FDE #1290 | PC: 0x06479c..0x0648d0 (308 B) | Symbol: sub_06479c
// EN: AArch64 prologue [sub sp, sp, #0x90; str x24, [sp, #0x50]; stp x23, x22, [sp, #0x60]; stp x21, x20, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x24, [sp, #0x50]; stp x23, x22, [sp, #0x60]; stp x21, x20, [sp, #0x70]]
uint64_t fde_sub_06479c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9002BF8ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0134ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06479CULL;
}

// FDE #1291 | PC: 0x0648d0..0x064918 (72 B) | Symbol: sub_0648d0
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; and w20, w3, #1; mov w3, w20] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; and w20, w3, #1; mov w3, w20]
uint64_t fde_sub_0648d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0648D0ULL;
}

// FDE #1292 | PC: 0x064918..0x0649c0 (168 B) | Symbol: sub_064918
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_064918(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064918ULL;
}

// FDE #1293 | PC: 0x0649c0..0x0649d8 (24 B) | Symbol: sub_0649c0
// EN: AArch64 prologue [ldr x0, [x0, #0x190]; cbz x0, #0x649d4; ldr x8, [x0]; ldr x5, [x8, #0x28]] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x190]; cbz x0, #0x649d4; ldr x8, [x0]; ldr x5, [x8, #0x28]]
uint64_t fde_sub_0649c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000080ULL) << 32) | 0xF940C800ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0649C0ULL;
}

// FDE #1294 | PC: 0x0649d8..0x0649e0 (8 B) | Symbol: sub_0649d8
// EN: AArch64 prologue [sub x0, x0, #0x28; b #0x64754] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x28; b #0x64754]
uint64_t fde_sub_0649d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF5EULL) << 32) | 0xD100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0649D8ULL;
}

// FDE #1295 | PC: 0x0649e0..0x0649e8 (8 B) | Symbol: sub_0649e0
// EN: AArch64 prologue [sub x0, x0, #0x28; b #0x64784] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x28; b #0x64784]
uint64_t fde_sub_0649e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF68ULL) << 32) | 0xD100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0649E0ULL;
}

// FDE #1296 | PC: 0x0649e8..0x0649f0 (8 B) | Symbol: sub_0649e8
// EN: AArch64 prologue [sub x0, x0, #0x48; b #0x64754] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x48; b #0x64754]
uint64_t fde_sub_0649e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF5AULL) << 32) | 0xD1012000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0649E8ULL;
}

// FDE #1297 | PC: 0x0649f0..0x0649f8 (8 B) | Symbol: sub_0649f0
// EN: AArch64 prologue [sub x0, x0, #0x48; b #0x64784] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x48; b #0x64784]
uint64_t fde_sub_0649f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF64ULL) << 32) | 0xD1012000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0649F0ULL;
}

// FDE #1298 | PC: 0x0649f8..0x064a1c (36 B) | Symbol: sub_0649f8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9b000; add x8, x8, #0x298; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9b000; add x8, x8, #0x298; mov x19, x0]
uint64_t fde_sub_0649f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00001A8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0649F8ULL;
}

// FDE #1299 | PC: 0x064a1c..0x064ab0 (148 B) | Symbol: sub_064a1c
// EN: AArch64 prologue [stp x25, x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x25, x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_064a1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xA9BC63F9ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064A1CULL;
}

// FDE #1300 | PC: 0x064ab0..0x064ac0 (16 B) | Symbol: sub_064ab0
// EN: AArch64 prologue [adrp x8, #0x9b000; add x8, x8, #0x298; str x8, [x0], #8; b #0x46c54] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9b000; add x8, x8, #0x298; str x8, [x0], #8; b #0x46c54]
uint64_t fde_sub_064ab0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910A6108ULL) << 32) | 0xF00001A8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064AB0ULL;
}

// FDE #1301 | PC: 0x064ac0..0x064af4 (52 B) | Symbol: sub_064ac0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x91d74; adrp x8, #0x9b000; add x8, x8, #0x2c8] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x91d74; adrp x8, #0x9b000; add x8, x8, #0x2c8]
uint64_t fde_sub_064ac0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400B4ACULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064AC0ULL;
}

// FDE #1302 | PC: 0x064af4..0x064b30 (60 B) | Symbol: sub_064af4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9b000; add x8, x8, #0x2c8; bl #0x8e03c] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9b000; add x8, x8, #0x2c8; bl #0x8e03c]
uint64_t fde_sub_064af4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF00001A8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064AF4ULL;
}

// FDE #1303 | PC: 0x064b30..0x064b48 (24 B) | Symbol: sub_064b30
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x64af4; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x64af4; mov x0, x19]
uint64_t fde_sub_064b30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064B30ULL;
}

// FDE #1304 | PC: 0x064b48..0x064b60 (24 B) | Symbol: sub_064b48
// EN: AArch64 prologue [and w8, w1, #0xffff; cmp w8, #0xca; b.ne #0x64b5c; add x8, x0, #0x1b0] | VI: Khởi đầu hàm AArch64 [and w8, w1, #0xffff; cmp w8, #0xca; b.ne #0x64b5c; add x8, x0, #0x1b0]
uint64_t fde_sub_064b48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7103291FULL) << 32) | 0x12003C28ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064B48ULL;
}

// FDE #1305 | PC: 0x064b60..0x064bc4 (100 B) | Symbol: sub_064b60
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x91db8; bl #0x93094] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x91db8; bl #0x93094]
uint64_t fde_sub_064b60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064B60ULL;
}

// FDE #1306 | PC: 0x064bc4..0x064c1c (88 B) | Symbol: sub_064bc4
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e3d4; ldr x8, [x20, #0x50]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e3d4; ldr x8, [x20, #0x50]]
uint64_t fde_sub_064bc4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064BC4ULL;
}

// FDE #1307 | PC: 0x064c1c..0x064db8 (412 B) | Symbol: sub_064c1c
// EN: AArch64 prologue [str d8, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str d8, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_064c1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xFC1C0FE8ULL;
    const uint64_t kPcRange = 0x019CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064C1CULL;
}

// FDE #1308 | PC: 0x064db8..0x064dc0 (8 B) | Symbol: sub_064db8
// EN: AArch64 prologue [sub x0, x0, #0x28; b #0x64af4] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x28; b #0x64af4]
uint64_t fde_sub_064db8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF4EULL) << 32) | 0xD100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064DB8ULL;
}

// FDE #1309 | PC: 0x064dc0..0x064dc8 (8 B) | Symbol: sub_064dc0
// EN: AArch64 prologue [sub x0, x0, #0x28; b #0x64b30] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x28; b #0x64b30]
uint64_t fde_sub_064dc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF5BULL) << 32) | 0xD100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064DC0ULL;
}

// FDE #1310 | PC: 0x064dc8..0x064dd0 (8 B) | Symbol: sub_064dc8
// EN: AArch64 prologue [sub x0, x0, #0x48; b #0x64af4] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x48; b #0x64af4]
uint64_t fde_sub_064dc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF4AULL) << 32) | 0xD1012000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064DC8ULL;
}

// FDE #1311 | PC: 0x064dd0..0x064dd8 (8 B) | Symbol: sub_064dd0
// EN: AArch64 prologue [sub x0, x0, #0x48; b #0x64b30] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x48; b #0x64b30]
uint64_t fde_sub_064dd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF57ULL) << 32) | 0xD1012000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064DD0ULL;
}

// FDE #1312 | PC: 0x064dd8..0x064de0 (8 B) | Symbol: _ZN4lynx6animax21TextContentDataSourceC1ERKNS0_19TextLayerAnimationsERNS0_16FontAssetManagerE
// EN: AArch64 prologue [stp x1, x2, [x0]; ret] | VI: Khởi đầu hàm AArch64 [stp x1, x2, [x0]; ret]
uint64_t fde_sub_064dd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xA9000801ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064DD8ULL;
}

// FDE #1313 | PC: 0x064de0..0x064dec (12 B) | Symbol: _ZNK4lynx6animax21TextContentDataSource15GetDocumentDataEv
// EN: AArch64 prologue [ldr x8, [x0]; ldr x0, [x8]; b #0x92cfc] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr x0, [x8]; b #0x92cfc]
uint64_t fde_sub_064de0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400100ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064DE0ULL;
}

// FDE #1314 | PC: 0x064dec..0x064df4 (8 B) | Symbol: _ZNK4lynx6animax21TextContentDataSource20GetFontMgrCollectionEv
// EN: AArch64 prologue [ldr x0, [x0, #8]; b #0x8e770] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #8]; b #0x8e770]
uint64_t fde_sub_064dec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400A660ULL) << 32) | 0xF9400400ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064DECULL;
}

// FDE #1315 | PC: 0x064df4..0x064e30 (60 B) | Symbol: _ZNK4lynx6animax21TextContentDataSource8GetColorEv
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; ldr x8, [x0]; ldp x9, x10, [x8, #8]; cmp x9, x10] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; ldr x8, [x0]; ldp x9, x10, [x8, #8]; cmp x9, x10]
uint64_t fde_sub_064df4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064DF4ULL;
}

// FDE #1316 | PC: 0x064e30..0x064e7c (76 B) | Symbol: sub_064e30
// EN: AArch64 prologue [ldrb w8, [x0, #9]; cbz w8, #0x64e40; ldrb w8, [x0, #8]; lsl w8, w8, #0x18] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #9]; cbz w8, #0x64e40; ldrb w8, [x0, #8]; lsl w8, w8, #0x18]
uint64_t fde_sub_064e30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34000068ULL) << 32) | 0x39402408ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064E30ULL;
}

// FDE #1317 | PC: 0x064e7c..0x064eb8 (60 B) | Symbol: _ZNK4lynx6animax21TextContentDataSource14GetStrokeColorEv
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x91a18; cbz x9, #0x64ea4; ldur x0, [x10, #-0x20]] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x91a18; cbz x9, #0x64ea4; ldur x0, [x10, #-0x20]]
uint64_t fde_sub_064e7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400B2E6ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064E7CULL;
}

// FDE #1318 | PC: 0x064eb8..0x064ef4 (60 B) | Symbol: _ZNK4lynx6animax21TextContentDataSource14GetStrokeWidthEv
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x91a18; cbz x9, #0x64ee0; ldur x0, [x10, #-0x18]] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x91a18; cbz x9, #0x64ee0; ldur x0, [x10, #-0x18]]
uint64_t fde_sub_064eb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400B2D7ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064EB8ULL;
}

// FDE #1319 | PC: 0x064ef4..0x064f74 (128 B) | Symbol: _ZNK4lynx6animax21TextContentDataSource11GetTrackingEv
// EN: AArch64 prologue [stp d9, d8, [sp, #-0x30]!; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [stp d9, d8, [sp, #-0x30]!; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr x8, [x0]]
uint64_t fde_sub_064ef4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF4ULL) << 32) | 0x6DBD23E9ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064EF4ULL;
}

// FDE #1320 | PC: 0x064f74..0x064fd0 (92 B) | Symbol: _ZNK4lynx6animax21TextContentDataSource11GetTextSizeEv
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; bl #0x91a18; cbz x9, #0x64fa0; ldur x0, [x10, #-8]] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; bl #0x91a18; cbz x9, #0x64fa0; ldur x0, [x10, #-8]]
uint64_t fde_sub_064f74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400B2A8ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064F74ULL;
}

// FDE #1321 | PC: 0x064fd0..0x065048 (120 B) | Symbol: _ZNK4lynx6animax21TextContentDataSource11GetFontNameEv
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; mrs x21, tpidr_el0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]; mrs x21, tpidr_el0]
uint64_t fde_sub_064fd0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90253F5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064FD0ULL;
}

// FDE #1322 | PC: 0x065048..0x065154 (268 B) | Symbol: _ZNK4lynx6animax21TextContentDataSource12GetFontAssetEv
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x25, x24, [sp, #0x20]; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x25, x24, [sp, #0x20]; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]]
uint64_t fde_sub_065048(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90263F9ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065048ULL;
}

// FDE #1323 | PC: 0x065154..0x0651b0 (92 B) | Symbol: _ZNK4lynx6animax21TextContentDataSource17GetLayoutOnlyOnceEv
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; ldr x8, [x0]; mov x19, x0; ldr x0, [x8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; ldr x8, [x0]; mov x19, x0; ldr x0, [x8]]
uint64_t fde_sub_065154(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400008ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065154ULL;
}

// FDE #1324 | PC: 0x0651b0..0x065244 (148 B) | Symbol: sub_0651b0
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x21, [x0, #0x78]; adrp x8, #0x9b000] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x21, [x0, #0x78]; adrp x8, #0x9b000]
uint64_t fde_sub_0651b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0651B0ULL;
}

// FDE #1325 | PC: 0x065244..0x06525c (24 B) | Symbol: sub_065244
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x651b0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x651b0; mov x0, x19]
uint64_t fde_sub_065244(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065244ULL;
}

// FDE #1326 | PC: 0x06525c..0x065a08 (1964 B) | Symbol: sub_06525c
// EN: AArch64 prologue [sub sp, sp, #0x190; stp d15, d14, [sp, #0xf0]; stp d13, d12, [sp, #0x100]; stp d11, d10, [sp, #0x110]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x190; stp d15, d14, [sp, #0xf0]; stp d13, d12, [sp, #0x100]; stp d11, d10, [sp, #0x110]]
uint64_t fde_sub_06525c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D0F3BEFULL) << 32) | 0xD10643FFULL;
    const uint64_t kPcRange = 0x07ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06525CULL;
}

// FDE #1327 | PC: 0x065a08..0x065aa8 (160 B) | Symbol: sub_065a08
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8f6c4] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8f6c4]
uint64_t fde_sub_065a08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065A08ULL;
}

// FDE #1328 | PC: 0x065aa8..0x065be8 (320 B) | Symbol: sub_065aa8
// EN: AArch64 prologue [sub sp, sp, #0x60; mov x2, x30; bl #0x91e38; mov x30, x2] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; mov x2, x30; bl #0x91e38; mov x30, x2]
uint64_t fde_sub_065aa8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E2ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0140ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065AA8ULL;
}

// FDE #1329 | PC: 0x065be8..0x065cec (260 B) | Symbol: sub_065be8
// EN: AArch64 prologue [str x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_065be8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xF81C0FF8ULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065BE8ULL;
}

// FDE #1330 | PC: 0x065cec..0x065d40 (84 B) | Symbol: sub_065cec
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldrb w8, [x0]; bl #0x8e454] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldrb w8, [x0]; bl #0x8e454]
uint64_t fde_sub_065cec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065CECULL;
}

// FDE #1331 | PC: 0x065d40..0x065d60 (32 B) | Symbol: sub_065d40
// EN: AArch64 prologue [ldrb w9, [x0]; tbnz w9, #0, #0x65d54; add x8, x0, #4; lsr x9, x9, #1] | VI: Khởi đầu hàm AArch64 [ldrb w9, [x0]; tbnz w9, #0, #0x65d54; add x8, x0, #4; lsr x9, x9, #1]
uint64_t fde_sub_065d40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x37000089ULL) << 32) | 0x39400009ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065D40ULL;
}

// FDE #1332 | PC: 0x065d60..0x065d78 (24 B) | Symbol: sub_065d60
// EN: AArch64 prologue [lsr x8, x0, #0x3e; cbnz x8, #0x65d70; lsl x0, x0, #2; b #0x93320] | VI: Khởi đầu hàm AArch64 [lsr x8, x0, #0x3e; cbnz x8, #0x65d70; lsl x0, x0, #2; b #0x93320]
uint64_t fde_sub_065d60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB5000068ULL) << 32) | 0xD37EFC08ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065D60ULL;
}

// FDE #1333 | PC: 0x065d78..0x065da0 (40 B) | Symbol: sub_065d78
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8dff0; cbz x19, #0x65d98; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8dff0; cbz x19, #0x65d98; mov x0, x19]
uint64_t fde_sub_065d78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400A09DULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065D78ULL;
}

// FDE #1334 | PC: 0x065da0..0x065e00 (96 B) | Symbol: _ZN4lynx6animax10TextHelper4ImplEv
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9d000; ldr x8, [x8, #0xc08]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9d000; ldr x8, [x8, #0xc08]]
uint64_t fde_sub_065da0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065DA0ULL;
}

// FDE #1335 | PC: 0x065e00..0x065e6c (108 B) | Symbol: _ZN4lynx6animax10TextHelperC1Ev
// EN: AArch64 prologue [sub sp, sp, #0x150; stp x28, x20, [sp, #0x130]; stp x19, x30, [sp, #0x140]; mrs x19, tpidr_el0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x150; stp x28, x20, [sp, #0x130]; stp x19, x30, [sp, #0x140]; mrs x19, tpidr_el0]
uint64_t fde_sub_065e00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA91353FCULL) << 32) | 0xD10543FFULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065E00ULL;
}

// FDE #1336 | PC: 0x065e6c..0x065ed8 (108 B) | Symbol: _ZN4lynx6animax10TextHelper17CreateTextContentERKNS0_21TextContentDataSourceE
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov w0, #0x90; mov x19, x1] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov w0, #0x90; mov x19, x1]
uint64_t fde_sub_065e6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065E6CULL;
}

// FDE #1337 | PC: 0x065ed8..0x065f18 (64 B) | Symbol: _ZN4lynx6animax10TextHelper22CreateFontAssetManagerEv
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov w0, #0x30; bl #0x8f1c0; adrp x8, #0x9b000] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov w0, #0x30; bl #0x8f1c0; adrp x8, #0x9b000]
uint64_t fde_sub_065ed8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800600ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065ED8ULL;
}

// FDE #1338 | PC: 0x065f18..0x065f6c (84 B) | Symbol: sub_065f18
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x20, [x0, #0x18]; adrp x8, #0x9b000] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x20, [x0, #0x18]; adrp x8, #0x9b000]
uint64_t fde_sub_065f18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065F18ULL;
}

// FDE #1339 | PC: 0x065f6c..0x065f84 (24 B) | Symbol: sub_065f6c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x65f18; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x65f18; mov x0, x19]
uint64_t fde_sub_065f6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065F6CULL;
}

// FDE #1340 | PC: 0x065f84..0x065f8c (8 B) | Symbol: sub_065f84
// EN: AArch64 prologue [mov x0, x8; b #0x47f90] | VI: Khởi đầu hàm AArch64 [mov x0, x8; b #0x47f90]
uint64_t fde_sub_065f84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF8802ULL) << 32) | 0xAA0803E0ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065F84ULL;
}

// FDE #1341 | PC: 0x065f8c..0x065f9c (16 B) | Symbol: _ZN4lynx6animax10TextHelper12RegisterImplEPS1_
// EN: AArch64 prologue [adrp x8, #0x9d000; ldr x8, [x8, #0xc08]; str x0, [x8]; ret] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9d000; ldr x8, [x8, #0xc08]; str x0, [x8]; ret]
uint64_t fde_sub_065f8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9460508ULL) << 32) | 0x900001C8ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065F8CULL;
}

// FDE #1342 | PC: 0x065f9c..0x0661bc (544 B) | Symbol: sub_065f9c
// EN: AArch64 prologue [mov x3, x30; bl #0x91b18; mov x30, x3; stp x29, x30, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x91b18; mov x30, x3; stp x29, x30, [sp, #0xa0]]
uint64_t fde_sub_065f9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400AEDEULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x0220ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065F9CULL;
}

// FDE #1343 | PC: 0x0661bc..0x0661f0 (52 B) | Symbol: sub_0661bc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x20; bl #0x44b18] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x20; bl #0x44b18]
uint64_t fde_sub_0661bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0661BCULL;
}

// FDE #1344 | PC: 0x0661f0..0x066240 (80 B) | Symbol: sub_0661f0
// EN: AArch64 prologue [str x30, [sp, #-0x10]!; mov x8, #0x6666666666666666; movk x8, #0x666, lsl #48; cmp x1, x8] | VI: Khởi đầu hàm AArch64 [str x30, [sp, #-0x10]!; mov x8, #0x6666666666666666; movk x8, #0x666, lsl #48; cmp x1, x8]
uint64_t fde_sub_0661f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB203E7E8ULL) << 32) | 0xF81F0FFEULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0661F0ULL;
}

// FDE #1345 | PC: 0x066240..0x06627c (60 B) | Symbol: sub_066240
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8df88; cbz x1, #0x66264] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8df88; cbz x1, #0x66264]
uint64_t fde_sub_066240(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066240ULL;
}

// FDE #1346 | PC: 0x06627c..0x0662bc (64 B) | Symbol: sub_06627c
// EN: AArch64 prologue [ldr x8, [x1]; str xzr, [x1]; str x8, [x0]; ldr x8, [x1, #8]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1]; str xzr, [x1]; str x8, [x0]; ldr x8, [x1, #8]]
uint64_t fde_sub_06627c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900003FULL) << 32) | 0xF9400028ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06627CULL;
}

// FDE #1347 | PC: 0x0662bc..0x066308 (76 B) | Symbol: sub_0662bc
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldp x22, x21, [x0]] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldp x22, x21, [x0]]
uint64_t fde_sub_0662bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0662BCULL;
}

// FDE #1348 | PC: 0x066308..0x066344 (60 B) | Symbol: sub_066308
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e030; bl #0x900d8] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e030; bl #0x900d8]
uint64_t fde_sub_066308(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066308ULL;
}

// FDE #1349 | PC: 0x066344..0x0663c8 (132 B) | Symbol: sub_066344
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; add x8, x8, #0x460] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; add x8, x8, #0x460]
uint64_t fde_sub_066344(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066344ULL;
}

// FDE #1350 | PC: 0x0663c8..0x0663e0 (24 B) | Symbol: sub_0663c8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x66344; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x66344; mov x0, x19]
uint64_t fde_sub_0663c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0663C8ULL;
}

// FDE #1351 | PC: 0x0663e0..0x0665bc (476 B) | Symbol: sub_0663e0
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_0663e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9035BF7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x01DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0663E0ULL;
}

// FDE #1352 | PC: 0x0665bc..0x0666f4 (312 B) | Symbol: sub_0665bc
// EN: AArch64 prologue [sub sp, sp, #0x40; str x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_0665bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0138ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0665BCULL;
}

// FDE #1353 | PC: 0x0666f4..0x066720 (44 B) | Symbol: sub_0666f4
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e3d4; ldr x8, [x20, #0x58]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e3d4; ldr x8, [x20, #0x58]]
uint64_t fde_sub_0666f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0666F4ULL;
}

// FDE #1354 | PC: 0x066720..0x066778 (88 B) | Symbol: sub_066720
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr x8, [x0, #0x1b0]] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr x8, [x0, #0x1b0]]
uint64_t fde_sub_066720(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066720ULL;
}

// FDE #1355 | PC: 0x066778..0x066780 (8 B) | Symbol: sub_066778
// EN: AArch64 prologue [sub x0, x0, #0x28; b #0x66344] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x28; b #0x66344]
uint64_t fde_sub_066778(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFEF2ULL) << 32) | 0xD100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066778ULL;
}

// FDE #1356 | PC: 0x066780..0x066788 (8 B) | Symbol: sub_066780
// EN: AArch64 prologue [sub x0, x0, #0x28; b #0x663c8] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x28; b #0x663c8]
uint64_t fde_sub_066780(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF11ULL) << 32) | 0xD100A000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066780ULL;
}

// FDE #1357 | PC: 0x066788..0x066790 (8 B) | Symbol: sub_066788
// EN: AArch64 prologue [sub x0, x0, #0x48; b #0x66344] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x48; b #0x66344]
uint64_t fde_sub_066788(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFEEEULL) << 32) | 0xD1012000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066788ULL;
}

// FDE #1358 | PC: 0x066790..0x066798 (8 B) | Symbol: sub_066790
// EN: AArch64 prologue [sub x0, x0, #0x48; b #0x663c8] | VI: Khởi đầu hàm AArch64 [sub x0, x0, #0x48; b #0x663c8]
uint64_t fde_sub_066790(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF0DULL) << 32) | 0xD1012000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066790ULL;
}

// FDE #1359 | PC: 0x066798..0x0667a0 (8 B) | Symbol: sub_066798
// EN: AArch64 prologue [mov x1, xzr; b #0x4c700] | VI: Khởi đầu hàm AArch64 [mov x1, xzr; b #0x4c700]
uint64_t fde_sub_066798(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF97D9ULL) << 32) | 0xAA1F03E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066798ULL;
}

// FDE #1360 | PC: 0x0667a0..0x0668cc (300 B) | Symbol: sub_0667a0
// EN: AArch64 prologue [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_0667a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF6ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0667A0ULL;
}

// FDE #1361 | PC: 0x0668cc..0x0668e4 (24 B) | Symbol: _ZN4lynx6animax9TextLayer12ApplyEffectsERNS0_5PaintE
// EN: AArch64 prologue [mov x2, x0; ldr x0, [x0, #0x1c0]; cbz x0, #0x668e0; mov w3, wzr] | VI: Khởi đầu hàm AArch64 [mov x2, x0; ldr x0, [x0, #0x1c0]; cbz x0, #0x668e0; mov w3, wzr]
uint64_t fde_sub_0668cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF940E000ULL) << 32) | 0xAA0003E2ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0668CCULL;
}

// FDE #1362 | PC: 0x0668e4..0x0669f4 (272 B) | Symbol: sub_0668e4
// EN: AArch64 prologue [mov x8, x30; bl #0x913b8; mov x30, x8; stp x29, x30, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [mov x8, x30; bl #0x913b8; mov x30, x8; stp x29, x30, [sp, #0x70]]
uint64_t fde_sub_0668e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400AAB4ULL) << 32) | 0xAA1E03E8ULL;
    const uint64_t kPcRange = 0x0110ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0668E4ULL;
}

// FDE #1363 | PC: 0x0669f4..0x066a90 (156 B) | Symbol: sub_0669f4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x88]; adrp x8, #0x9b000] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x88]; adrp x8, #0x9b000]
uint64_t fde_sub_0669f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x009CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0669F4ULL;
}

// FDE #1364 | PC: 0x066a90..0x066aa8 (24 B) | Symbol: sub_066a90
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x669f4; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x669f4; mov x0, x19]
uint64_t fde_sub_066a90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066A90ULL;
}

// FDE #1365 | PC: 0x066aa8..0x066ab0 (8 B) | Symbol: sub_066aa8
// EN: AArch64 prologue [mov w0, #2; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #2; ret]
uint64_t fde_sub_066aa8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800040ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066AA8ULL;
}

// FDE #1366 | PC: 0x066ab0..0x066e64 (948 B) | Symbol: sub_066ab0
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x27, x26, [sp, #0x20]; stp x25, x24, [sp, #0x30]; stp x23, x22, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x27, x26, [sp, #0x20]; stp x25, x24, [sp, #0x30]; stp x23, x22, [sp, #0x40]]
uint64_t fde_sub_066ab0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9026BFBULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x03B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066AB0ULL;
}

// FDE #1367 | PC: 0x066e64..0x066e90 (44 B) | Symbol: sub_066e64
// EN: AArch64 prologue [ldr x9, [x0, #8]; ldp x8, x9, [x9]; cmp x8, x9; b.eq #0x66e88] | VI: Khởi đầu hàm AArch64 [ldr x9, [x0, #8]; ldp x8, x9, [x9]; cmp x8, x9; b.eq #0x66e88]
uint64_t fde_sub_066e64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9402528ULL) << 32) | 0xF9400409ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066E64ULL;
}

// FDE #1368 | PC: 0x066e90..0x066ea0 (16 B) | Symbol: sub_066e90
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; adrp x9, #0x9b000; add x9, x9, #0x5a0; b #0x8d518] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; adrp x9, #0x9b000; add x9, x9, #0x5a0; b #0x8d518]
uint64_t fde_sub_066e90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00001A9ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066E90ULL;
}

// FDE #1369 | PC: 0x066ea0..0x066eb0 (16 B) | Symbol: sub_066ea0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8dd18; ldp x19, x30, [sp], #0x10; b #0x932e0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8dd18; ldp x19, x30, [sp], #0x10; b #0x932e0]
uint64_t fde_sub_066ea0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94009B9DULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066EA0ULL;
}

// FDE #1370 | PC: 0x066eb0..0x066eec (60 B) | Symbol: sub_066eb0
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x0]
uint64_t fde_sub_066eb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066EB0ULL;
}

// FDE #1371 | PC: 0x066eec..0x066f2c (64 B) | Symbol: sub_066eec
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x0]
uint64_t fde_sub_066eec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066EECULL;
}

// FDE #1372 | PC: 0x066f2c..0x066f6c (64 B) | Symbol: sub_066f2c
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x0]
uint64_t fde_sub_066f2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066F2CULL;
}

// FDE #1373 | PC: 0x066f6c..0x066fac (64 B) | Symbol: sub_066f6c
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x0]
uint64_t fde_sub_066f6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066F6CULL;
}

// FDE #1374 | PC: 0x066fac..0x06705c (176 B) | Symbol: sub_066fac
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x23, x22, [sp, #0x20]; stp x21, x20, [sp, #0x30]; stp x19, x30, [sp, #0x40]]
uint64_t fde_sub_066fac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9025BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066FACULL;
}

// FDE #1375 | PC: 0x06705c..0x067090 (52 B) | Symbol: sub_06705c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8ee48; ldr x8, [x0]; bl #0x8d584] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8ee48; ldr x8, [x0]; bl #0x8d584]
uint64_t fde_sub_06705c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94009F7AULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06705CULL;
}

// FDE #1376 | PC: 0x067090..0x067138 (168 B) | Symbol: sub_067090
// EN: AArch64 prologue [sub sp, sp, #0x60; str x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]; ldr x1, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]; ldr x1, [x0, #0x18]]
uint64_t fde_sub_067090(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F4ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067090ULL;
}

// FDE #1377 | PC: 0x067138..0x0671e4 (172 B) | Symbol: sub_067138
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x0]
uint64_t fde_sub_067138(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067138ULL;
}

// FDE #1378 | PC: 0x0671e4..0x067224 (64 B) | Symbol: sub_0671e4
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x0]
uint64_t fde_sub_0671e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0671E4ULL;
}

// FDE #1379 | PC: 0x067224..0x067258 (52 B) | Symbol: sub_067224
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; mov x19, x0]
uint64_t fde_sub_067224(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067224ULL;
}

// FDE #1380 | PC: 0x067258..0x067270 (24 B) | Symbol: sub_067258
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x67224; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x67224; mov x0, x19]
uint64_t fde_sub_067258(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067258ULL;
}

// FDE #1381 | PC: 0x067270..0x067278 (8 B) | Symbol: sub_067270
// EN: AArch64 prologue [mov w0, #0xa; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0xa; ret]
uint64_t fde_sub_067270(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800140ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067270ULL;
}

// FDE #1382 | PC: 0x067278..0x067384 (268 B) | Symbol: sub_067278
// EN: AArch64 prologue [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]]
uint64_t fde_sub_067278(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9009BFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067278ULL;
}

// FDE #1383 | PC: 0x067384..0x06738c (8 B) | Symbol: sub_067384
// EN: AArch64 prologue [mov x1, xzr; b #0x6738c] | VI: Khởi đầu hàm AArch64 [mov x1, xzr; b #0x6738c]
uint64_t fde_sub_067384(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xAA1F03E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067384ULL;
}

// FDE #1384 | PC: 0x06738c..0x0673c0 (52 B) | Symbol: sub_06738c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8dcc8; cbz x19, #0x673b8; add x0, x19, #0x40] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8dcc8; cbz x19, #0x673b8; add x0, x19, #0x40]
uint64_t fde_sub_06738c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94009A4EULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06738CULL;
}

// FDE #1385 | PC: 0x0673c0..0x0673e4 (36 B) | Symbol: sub_0673c0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8dff0; cbz x19, #0x673dc; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8dff0; cbz x19, #0x673dc; mov x0, x19]
uint64_t fde_sub_0673c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94009B0BULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0673C0ULL;
}

// FDE #1386 | PC: 0x0673e4..0x067404 (32 B) | Symbol: sub_0673e4
// EN: AArch64 prologue [fsub s0, s1, s0; mov w8, #0x447a0000; fdiv s0, s0, s2; fmov s1, w8] | VI: Khởi đầu hàm AArch64 [fsub s0, s1, s0; mov w8, #0x447a0000; fdiv s0, s0, s2; fmov s1, w8]
uint64_t fde_sub_0673e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52A88F48ULL) << 32) | 0x1E203820ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0673E4ULL;
}

// FDE #1387 | PC: 0x067404..0x067440 (60 B) | Symbol: sub_067404
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; add x8, x8, #0x678] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; add x8, x8, #0x678]
uint64_t fde_sub_067404(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067404ULL;
}

// FDE #1388 | PC: 0x067440..0x06749c (92 B) | Symbol: sub_067440
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; mov x19, x0]
uint64_t fde_sub_067440(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067440ULL;
}

// FDE #1389 | PC: 0x06749c..0x0674b4 (24 B) | Symbol: sub_06749c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x67440; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x67440; mov x0, x19]
uint64_t fde_sub_06749c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06749CULL;
}

// FDE #1390 | PC: 0x0674b4..0x0674f0 (60 B) | Symbol: sub_0674b4
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; add x8, x8, #0x678] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; add x8, x8, #0x678]
uint64_t fde_sub_0674b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0674B4ULL;
}

// FDE #1391 | PC: 0x0674f0..0x067510 (32 B) | Symbol: sub_0674f0
// EN: AArch64 prologue [cbz x1, #0x67508; ldr x8, [x1]; ldr x2, [x8, #0x20]; mov x8, x0] | VI: Khởi đầu hàm AArch64 [cbz x1, #0x67508; ldr x8, [x1]; ldr x2, [x8, #0x20]; mov x8, x0]
uint64_t fde_sub_0674f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400028ULL) << 32) | 0xB40000C1ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0674F0ULL;
}

// FDE #1392 | PC: 0x067510..0x06753c (44 B) | Symbol: sub_067510
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; add x0, x0, #0x28] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; add x0, x0, #0x28]
uint64_t fde_sub_067510(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067510ULL;
}

// FDE #1393 | PC: 0x06753c..0x067558 (28 B) | Symbol: sub_06753c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x91018; cbz x0, #0x6754c; bl #0x8d3c4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x91018; cbz x0, #0x6754c; bl #0x8d3c4]
uint64_t fde_sub_06753c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400A6B6ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06753CULL;
}

// FDE #1394 | PC: 0x067558..0x067598 (64 B) | Symbol: sub_067558
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8e7ac; cbz x0, #0x67588; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8e7ac; cbz x0, #0x67588; ldr x8, [x0]]
uint64_t fde_sub_067558(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94009C94ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067558ULL;
}

// FDE #1395 | PC: 0x067598..0x0675b4 (28 B) | Symbol: sub_067598
// EN: AArch64 prologue [ldr x8, [x0, #0x40]; cbnz x8, #0x675a8; ldr x8, [x0, #0x48]; cbz x8, #0x675ac] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x40]; cbnz x8, #0x675a8; ldr x8, [x0, #0x48]; cbz x8, #0x675ac]
uint64_t fde_sub_067598(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB5000068ULL) << 32) | 0xF9402008ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067598ULL;
}

// FDE #1396 | PC: 0x0675b4..0x0675f8 (68 B) | Symbol: sub_0675b4
// EN: AArch64 prologue [ldr x8, [x0, #8]; fmov s0, wzr; cbz x8, #0x675f4; ldp s1, s2, [x8, #0x14]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; fmov s0, wzr; cbz x8, #0x675f4; ldp s1, s2, [x8, #0x14]]
uint64_t fde_sub_0675b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1E2703E0ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0675B4ULL;
}

// FDE #1397 | PC: 0x0675f8..0x067688 (144 B) | Symbol: sub_0675f8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; ldr x8, [x0, #8]; fmov s1, #1.00000000; cbz x8, #0x67618] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; ldr x8, [x0, #8]; fmov s1, #1.00000000; cbz x8, #0x67618]
uint64_t fde_sub_0675f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400408ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0675F8ULL;
}

// FDE #1398 | PC: 0x067688..0x0676c8 (64 B) | Symbol: sub_067688
// EN: AArch64 prologue [str d8, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov v8.16b, v0.16b; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str d8, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov v8.16b, v0.16b; mov x19, x0]
uint64_t fde_sub_067688(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xFC1E0FE8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067688ULL;
}

// FDE #1399 | PC: 0x0676c8..0x067724 (92 B) | Symbol: sub_0676c8
// EN: AArch64 prologue [ldrb w8, [x0, #0xc]; ldrb w10, [x0, #0x14]; mov w9, #8; cmp w8, #0] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0xc]; ldrb w10, [x0, #0x14]; mov w9, #8; cmp w8, #0]
uint64_t fde_sub_0676c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3940500AULL) << 32) | 0x39403008ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0676C8ULL;
}

// FDE #1400 | PC: 0x067724..0x0678d0 (428 B) | Symbol: sub_067724
// EN: AArch64 prologue [sub sp, sp, #0x70; str x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x22, [sp, #0x40]; stp x21, x20, [sp, #0x50]; stp x19, x30, [sp, #0x60]]
uint64_t fde_sub_067724(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F6ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067724ULL;
}

// FDE #1401 | PC: 0x0678d0..0x067924 (84 B) | Symbol: sub_0678d0
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x22, x0] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x22, x0]
uint64_t fde_sub_0678d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0678D0ULL;
}

// FDE #1402 | PC: 0x067924..0x06794c (40 B) | Symbol: sub_067924
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x8d880; bl #0x929b0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x8d880; bl #0x929b0]
uint64_t fde_sub_067924(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067924ULL;
}

// FDE #1403 | PC: 0x06794c..0x067990 (68 B) | Symbol: sub_06794c
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; add x8, x8, #0x6a8] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; add x8, x8, #0x6a8]
uint64_t fde_sub_06794c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06794CULL;
}

// FDE #1404 | PC: 0x067990..0x0679a8 (24 B) | Symbol: sub_067990
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x6794c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x6794c; mov x0, x19]
uint64_t fde_sub_067990(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067990ULL;
}

// FDE #1405 | PC: 0x0679a8..0x067a2c (132 B) | Symbol: sub_0679a8
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; mov w0, #0xf8] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; mov w0, #0xf8]
uint64_t fde_sub_0679a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0679A8ULL;
}

// FDE #1406 | PC: 0x067a2c..0x067bdc (432 B) | Symbol: sub_067a2c
// EN: AArch64 prologue [sub sp, sp, #0xc0; stp d11, d10, [sp, #0x40]; stp d9, d8, [sp, #0x50]; stp x28, x27, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; stp d11, d10, [sp, #0x40]; stp d9, d8, [sp, #0x50]; stp x28, x27, [sp, #0x60]]
uint64_t fde_sub_067a2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D042BEBULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x01B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067A2CULL;
}

// FDE #1407 | PC: 0x067bdc..0x067c50 (116 B) | Symbol: sub_067bdc
// EN: AArch64 prologue [ldp s3, s2, [x1]; ldp s1, s0, [x1, #8]; fcmp s3, s1; fccmp s2, s0, #0, mi] | VI: Khởi đầu hàm AArch64 [ldp s3, s2, [x1]; ldp s1, s0, [x1, #8]; fcmp s3, s1; fccmp s2, s0, #0, mi]
uint64_t fde_sub_067bdc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2D410021ULL) << 32) | 0x2D400823ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067BDCULL;
}

// FDE #1408 | PC: 0x067c50..0x067cc8 (120 B) | Symbol: sub_067c50
// EN: AArch64 prologue [ldr s0, [x1, #8]; ldr s5, [x0]; fcmp s5, s0; b.pl #0x67cc4] | VI: Khởi đầu hàm AArch64 [ldr s0, [x1, #8]; ldr s5, [x0]; fcmp s5, s0; b.pl #0x67cc4]
uint64_t fde_sub_067c50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xBD400005ULL) << 32) | 0xBD400820ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067C50ULL;
}

// FDE #1409 | PC: 0x067cc8..0x067d0c (68 B) | Symbol: sub_067cc8
// EN: AArch64 prologue [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x0] | VI: Khởi đầu hàm AArch64 [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x0]
uint64_t fde_sub_067cc8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xA9BD5BF7ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067CC8ULL;
}

// FDE #1410 | PC: 0x067d0c..0x067d38 (44 B) | Symbol: sub_067d0c
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x0] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x0]
uint64_t fde_sub_067d0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067D0CULL;
}

// FDE #1411 | PC: 0x067d38..0x067d64 (44 B) | Symbol: sub_067d38
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x0] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x0]
uint64_t fde_sub_067d38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067D38ULL;
}

// FDE #1412 | PC: 0x067d64..0x067d90 (44 B) | Symbol: sub_067d64
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x0] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x0]
uint64_t fde_sub_067d64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067D64ULL;
}

// FDE #1413 | PC: 0x067d90..0x067dbc (44 B) | Symbol: sub_067d90
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x0] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x0]
uint64_t fde_sub_067d90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067D90ULL;
}

// FDE #1414 | PC: 0x067dbc..0x067de8 (44 B) | Symbol: sub_067dbc
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x0] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x0]
uint64_t fde_sub_067dbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067DBCULL;
}

// FDE #1415 | PC: 0x067de8..0x067e14 (44 B) | Symbol: sub_067de8
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x0] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x0]
uint64_t fde_sub_067de8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067DE8ULL;
}

// FDE #1416 | PC: 0x067e14..0x067e40 (44 B) | Symbol: sub_067e14
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x0] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x0]
uint64_t fde_sub_067e14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067E14ULL;
}

// FDE #1417 | PC: 0x067e40..0x067e6c (44 B) | Symbol: sub_067e40
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x0] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x0]
uint64_t fde_sub_067e40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067E40ULL;
}

// FDE #1418 | PC: 0x067e6c..0x067ea4 (56 B) | Symbol: sub_067e6c
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; mov x19, x0]
uint64_t fde_sub_067e6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067E6CULL;
}

// FDE #1419 | PC: 0x067ea4..0x067ebc (24 B) | Symbol: sub_067ea4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x67e6c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x67e6c; mov x0, x19]
uint64_t fde_sub_067ea4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067EA4ULL;
}

// FDE #1420 | PC: 0x067ebc..0x067f14 (88 B) | Symbol: sub_067ebc
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; mov x19, x0]
uint64_t fde_sub_067ebc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067EBCULL;
}

// FDE #1421 | PC: 0x067f14..0x067f2c (24 B) | Symbol: sub_067f14
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x67ebc; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x67ebc; mov x0, x19]
uint64_t fde_sub_067f14(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067F14ULL;
}

// FDE #1422 | PC: 0x067f2c..0x067f6c (64 B) | Symbol: sub_067f2c
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; mov x19, x0]
uint64_t fde_sub_067f2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067F2CULL;
}

// FDE #1423 | PC: 0x067f6c..0x067f84 (24 B) | Symbol: sub_067f6c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x67f2c; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x67f2c; mov x0, x19]
uint64_t fde_sub_067f6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067F6CULL;
}

// FDE #1424 | PC: 0x067f84..0x067fbc (56 B) | Symbol: sub_067f84
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; mov x19, x0]
uint64_t fde_sub_067f84(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067F84ULL;
}

// FDE #1425 | PC: 0x067fbc..0x067fd4 (24 B) | Symbol: sub_067fbc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x67f84; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x67f84; mov x0, x19]
uint64_t fde_sub_067fbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067FBCULL;
}

// FDE #1426 | PC: 0x067fd4..0x067ff8 (36 B) | Symbol: sub_067fd4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9b000; add x8, x8, #0x798; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9b000; add x8, x8, #0x798; mov x19, x0]
uint64_t fde_sub_067fd4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x900001A8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067FD4ULL;
}

// FDE #1427 | PC: 0x067ff8..0x068010 (24 B) | Symbol: sub_067ff8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x67fd4; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x67fd4; mov x0, x19]
uint64_t fde_sub_067ff8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067FF8ULL;
}

// FDE #1428 | PC: 0x068010..0x068048 (56 B) | Symbol: sub_068010
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; mov x19, x0]
uint64_t fde_sub_068010(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068010ULL;
}

// FDE #1429 | PC: 0x068048..0x068060 (24 B) | Symbol: sub_068048
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x68010; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x68010; mov x0, x19]
uint64_t fde_sub_068048(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068048ULL;
}

// FDE #1430 | PC: 0x068060..0x068094 (52 B) | Symbol: sub_068060
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9b000; add x8, x8, #0x7f8; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9b000; add x8, x8, #0x7f8; mov x19, x0]
uint64_t fde_sub_068060(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000188ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068060ULL;
}

// FDE #1431 | PC: 0x068094..0x0680ac (24 B) | Symbol: sub_068094
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x68060; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x68060; mov x0, x19]
uint64_t fde_sub_068094(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068094ULL;
}

// FDE #1432 | PC: 0x0680ac..0x0680d0 (36 B) | Symbol: sub_0680ac
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9b000; add x8, x8, #0x828; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9b000; add x8, x8, #0x828; mov x19, x0]
uint64_t fde_sub_0680ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000188ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0680ACULL;
}

// FDE #1433 | PC: 0x0680d0..0x0680e8 (24 B) | Symbol: sub_0680d0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x680ac; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x680ac; mov x0, x19]
uint64_t fde_sub_0680d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0680D0ULL;
}

// FDE #1434 | PC: 0x0680e8..0x06812c (68 B) | Symbol: sub_0680e8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9b000; add x8, x8, #0x858; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9b000; add x8, x8, #0x858; mov x19, x0]
uint64_t fde_sub_0680e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF0000188ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0680E8ULL;
}

// FDE #1435 | PC: 0x06812c..0x068174 (72 B) | Symbol: sub_06812c
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x20, [x0]; cbz x20, #0x6816c] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x20, [x0]; cbz x20, #0x6816c]
uint64_t fde_sub_06812c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06812CULL;
}

// FDE #1436 | PC: 0x068174..0x06818c (24 B) | Symbol: sub_068174
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x680e8; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x680e8; mov x0, x19]
uint64_t fde_sub_068174(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068174ULL;
}

// FDE #1437 | PC: 0x06818c..0x068194 (8 B) | Symbol: sub_06818c
// EN: AArch64 prologue [mov w0, #4; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #4; ret]
uint64_t fde_sub_06818c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800080ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06818CULL;
}

// FDE #1438 | PC: 0x068194..0x06819c (8 B) | Symbol: sub_068194
// EN: AArch64 prologue [ldrb w8, [x0, #0xc]; b #0x8e6c8] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0xc]; b #0x8e6c8]
uint64_t fde_sub_068194(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400994CULL) << 32) | 0x39403008ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068194ULL;
}

// FDE #1439 | PC: 0x06819c..0x0681f8 (92 B) | Symbol: sub_06819c
// EN: AArch64 prologue [sub sp, sp, #0x30; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8e364] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8e364]
uint64_t fde_sub_06819c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06819CULL;
}

// FDE #1440 | PC: 0x0681f8..0x068264 (108 B) | Symbol: sub_0681f8
// EN: AArch64 prologue [sub sp, sp, #0x30; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8e364] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8e364]
uint64_t fde_sub_0681f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0681F8ULL;
}

// FDE #1441 | PC: 0x068264..0x0682a0 (60 B) | Symbol: sub_068264
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; mov w0, #0x10] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; mov w0, #0x10]
uint64_t fde_sub_068264(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068264ULL;
}

// FDE #1442 | PC: 0x0682a0..0x0682c4 (36 B) | Symbol: sub_0682a0
// EN: AArch64 prologue [ldrb w8, [x0, #9]; cbz w8, #0x682c0; ldrb w8, [x0, #0xb]; cbz w8, #0x682c0] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #9]; cbz w8, #0x682c0; ldrb w8, [x0, #0xb]; cbz w8, #0x682c0]
uint64_t fde_sub_0682a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x340000E8ULL) << 32) | 0x39402408ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0682A0ULL;
}

// FDE #1443 | PC: 0x0682c4..0x06834c (136 B) | Symbol: sub_0682c4
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e364; tbz w0, #0, #0x682e4] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e364; tbz w0, #0, #0x682e4]
uint64_t fde_sub_0682c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0682C4ULL;
}

// FDE #1444 | PC: 0x06834c..0x06836c (32 B) | Symbol: sub_06834c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x8d6cc; bl #0x91ff4] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x8d6cc; bl #0x91ff4]
uint64_t fde_sub_06834c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06834CULL;
}

// FDE #1445 | PC: 0x06836c..0x0683d8 (108 B) | Symbol: sub_06836c
// EN: AArch64 prologue [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x23, x0] | VI: Khởi đầu hàm AArch64 [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x23, x0]
uint64_t fde_sub_06836c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xA9BD5BF7ULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06836CULL;
}

// FDE #1446 | PC: 0x0683d8..0x06840c (52 B) | Symbol: _ZN4lynx6animax5ColorC1Ei
// EN: AArch64 prologue [mov x2, x30; bl #0x91ff4; mov x30, x2; lsr w9, w1, #0x18] | VI: Khởi đầu hàm AArch64 [mov x2, x30; bl #0x91ff4; mov x30, x2; lsr w9, w1, #0x18]
uint64_t fde_sub_0683d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400A706ULL) << 32) | 0xAA1E03E2ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0683D8ULL;
}

// FDE #1447 | PC: 0x06840c..0x068420 (20 B) | Symbol: sub_06840c
// EN: AArch64 prologue [mov w4, w1; lsr w1, w1, #0x18; lsr w2, w4, #0x10; lsr w3, w4, #8] | VI: Khởi đầu hàm AArch64 [mov w4, w1; lsr w1, w1, #0x18; lsr w2, w4, #0x10; lsr w3, w4, #8]
uint64_t fde_sub_06840c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x53187C21ULL) << 32) | 0x2A0103E4ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06840CULL;
}

// FDE #1448 | PC: 0x068420..0x068454 (52 B) | Symbol: sub_068420
// EN: AArch64 prologue [mov w8, #0x100; mov w9, #0x100; mov w10, #0x100; mov w11, #0x100] | VI: Khởi đầu hàm AArch64 [mov w8, #0x100; mov w9, #0x100; mov w10, #0x100; mov w11, #0x100]
uint64_t fde_sub_068420(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52802009ULL) << 32) | 0x52802008ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068420ULL;
}

// FDE #1449 | PC: 0x068454..0x0684a0 (76 B) | Symbol: _ZN4lynx6animax12DocumentDataC1Ev
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; ldr x8, [x8, #0xc18]; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; adrp x8, #0x9d000; ldr x8, [x8, #0xc18]; mov x19, x0]
uint64_t fde_sub_068454(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB00001A8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068454ULL;
}

// FDE #1450 | PC: 0x0684a0..0x0684e8 (72 B) | Symbol: sub_0684a0
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9d000; ldr x8, [x8, #0xc18]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9d000; ldr x8, [x8, #0xc18]]
uint64_t fde_sub_0684a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0684A0ULL;
}

// FDE #1451 | PC: 0x0684e8..0x068500 (24 B) | Symbol: sub_0684e8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x684a0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x684a0; mov x0, x19]
uint64_t fde_sub_0684e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0684E8ULL;
}

// FDE #1452 | PC: 0x068500..0x068508 (8 B) | Symbol: _ZNK4lynx6animax12DocumentData7IsEmptyEv
// EN: AArch64 prologue [ldrb w8, [x0, #0x3c]; b #0x8e6c8] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x3c]; b #0x8e6c8]
uint64_t fde_sub_068500(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14009871ULL) << 32) | 0x3940F008ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068500ULL;
}

// FDE #1453 | PC: 0x068508..0x0685e8 (224 B) | Symbol: _ZNK4lynx6animax12DocumentData4CopyEv
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x0]
uint64_t fde_sub_068508(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068508ULL;
}

// FDE #1454 | PC: 0x0685e8..0x068638 (80 B) | Symbol: sub_0685e8
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x21, x0; mov w0, #0x28] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x21, x0; mov w0, #0x28]
uint64_t fde_sub_0685e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0685E8ULL;
}

// FDE #1455 | PC: 0x068638..0x068720 (232 B) | Symbol: _ZN4lynx6animax12DocumentDataC2ENSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEES8_fNS0_21DocumentJustificationEjffiifbNS2_10unique_ptrINS0_6PointFENS2_14default_deleteISB_EEEESE_
// EN: AArch64 prologue [stp d11, d10, [sp, #-0x70]!; stp d9, d8, [sp, #0x10]; stp x27, x26, [sp, #0x20]; stp x25, x24, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp d11, d10, [sp, #-0x70]!; stp d9, d8, [sp, #0x10]; stp x27, x26, [sp, #0x20]; stp x25, x24, [sp, #0x30]]
uint64_t fde_sub_068638(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D0123E9ULL) << 32) | 0x6DB92BEBULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068638ULL;
}

// FDE #1456 | PC: 0x068720..0x068738 (24 B) | Symbol: sub_068720
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x45c18; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x45c18; mov x0, x19]
uint64_t fde_sub_068720(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068720ULL;
}

// FDE #1457 | PC: 0x068738..0x068740 (8 B) | Symbol: sub_068738
// EN: AArch64 prologue [mov w0, #8; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #8; ret]
uint64_t fde_sub_068738(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800100ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068738ULL;
}

// FDE #1458 | PC: 0x068740..0x068750 (16 B) | Symbol: sub_068740
// EN: AArch64 prologue [ldr w8, [x0, #8]; cmp w8, #1; cset w0, lt; ret] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #8]; cmp w8, #1; cset w0, lt; ret]
uint64_t fde_sub_068740(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100051FULL) << 32) | 0xB9400808ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068740ULL;
}

// FDE #1459 | PC: 0x068750..0x0687d0 (128 B) | Symbol: sub_068750
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x21, x0; mov w0, #0x20] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x21, x0; mov w0, #0x20]
uint64_t fde_sub_068750(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068750ULL;
}

// FDE #1460 | PC: 0x0687d0..0x068860 (144 B) | Symbol: sub_0687d0
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr w8, [x0, #8]; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr w8, [x0, #8]; mov x19, x0]
uint64_t fde_sub_0687d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0687D0ULL;
}

// FDE #1461 | PC: 0x068860..0x068888 (40 B) | Symbol: sub_068860
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x2; subs x2, x1, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x2; subs x2, x1, x0]
uint64_t fde_sub_068860(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068860ULL;
}

// FDE #1462 | PC: 0x068888..0x0688a0 (24 B) | Symbol: sub_068888
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x47b64; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x47b64; mov x0, x19]
uint64_t fde_sub_068888(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068888ULL;
}

// FDE #1463 | PC: 0x0688a0..0x0688a8 (8 B) | Symbol: sub_0688a0
// EN: AArch64 prologue [add x0, x0, #8; b #0x45048] | VI: Khởi đầu hàm AArch64 [add x0, x0, #8; b #0x45048]
uint64_t fde_sub_0688a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FF71E9ULL) << 32) | 0x91002000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0688A0ULL;
}

// FDE #1464 | PC: 0x0688a8..0x068968 (192 B) | Symbol: sub_0688a8
// EN: AArch64 prologue [str x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_0688a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xF81C0FF8ULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0688A8ULL;
}

// FDE #1465 | PC: 0x068968..0x0689b8 (80 B) | Symbol: sub_068968
// EN: AArch64 prologue [sub x8, x1, x0; cbz x8, #0x689b0; ldur q0, [x0, #0x14]; ldur q1, [x0, #8]] | VI: Khởi đầu hàm AArch64 [sub x8, x1, x0; cbz x8, #0x689b0; ldur q0, [x0, #0x14]; ldur q1, [x0, #8]]
uint64_t fde_sub_068968(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000228ULL) << 32) | 0xCB000028ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068968ULL;
}

// FDE #1466 | PC: 0x0689b8..0x0690b4 (1788 B) | Symbol: sub_0689b8
// EN: AArch64 prologue [stp d9, d8, [sp, #-0x70]!; mov x4, x30; bl #0x90cd8; mov x30, x4] | VI: Khởi đầu hàm AArch64 [stp d9, d8, [sp, #-0x70]!; mov x4, x30; bl #0x90cd8; mov x30, x4]
uint64_t fde_sub_0689b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E4ULL) << 32) | 0x6DB923E9ULL;
    const uint64_t kPcRange = 0x06FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0689B8ULL;
}

// FDE #1467 | PC: 0x0690b4..0x0690fc (72 B) | Symbol: sub_0690b4
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; movi v0.2d, #0000000000000000; mov w8, #0x400; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; movi v0.2d, #0000000000000000; mov w8, #0x400; mov x19, x0]
uint64_t fde_sub_0690b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6F00E400ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0690B4ULL;
}

// FDE #1468 | PC: 0x0690fc..0x0692bc (448 B) | Symbol: sub_0690fc
// EN: AArch64 prologue [sub sp, sp, #0xa0; str x20, [sp, #0x80]; stp x19, x30, [sp, #0x90]; mrs x20, tpidr_el0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; str x20, [sp, #0x80]; stp x19, x30, [sp, #0x90]; mrs x20, tpidr_el0]
uint64_t fde_sub_0690fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90043F4ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x01C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0690FCULL;
}

// FDE #1469 | PC: 0x0692bc..0x0692dc (32 B) | Symbol: sub_0692bc
// EN: AArch64 prologue [mov x8, xzr; cmp x8, #0x10; b.eq #0x692d8; ldr w9, [x1]] | VI: Khởi đầu hàm AArch64 [mov x8, xzr; cmp x8, #0x10; b.eq #0x692d8; ldr w9, [x1]]
uint64_t fde_sub_0692bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF100411FULL) << 32) | 0xAA1F03E8ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0692BCULL;
}

// FDE #1470 | PC: 0x0692dc..0x069354 (120 B) | Symbol: sub_0692dc
// EN: AArch64 prologue [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x2] | VI: Khởi đầu hàm AArch64 [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x2]
uint64_t fde_sub_0692dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xA9BD5BF7ULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0692DCULL;
}

// FDE #1471 | PC: 0x069354..0x0693a8 (84 B) | Symbol: sub_069354
// EN: AArch64 prologue [ldrh w8, [x1, #0x16]; cmp w8, #4; b.ne #0x69398; ldr x11, [x1, #8]] | VI: Khởi đầu hàm AArch64 [ldrh w8, [x1, #0x16]; cmp w8, #4; b.ne #0x69398; ldr x11, [x1, #8]]
uint64_t fde_sub_069354(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100111FULL) << 32) | 0x79402C28ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069354ULL;
}

// FDE #1472 | PC: 0x0693a8..0x0693dc (52 B) | Symbol: sub_0693a8
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; str x1, [x0]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x20, x0; str x1, [x0]]
uint64_t fde_sub_0693a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0693A8ULL;
}

// FDE #1473 | PC: 0x0693dc..0x06942c (80 B) | Symbol: sub_0693dc
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldp q0, q1, [x1]; bl #0x8e7a0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldp q0, q1, [x1]; bl #0x8e7a0]
uint64_t fde_sub_0693dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0693DCULL;
}

// FDE #1474 | PC: 0x06942c..0x069448 (28 B) | Symbol: sub_06942c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x9310c; add x0, x19, #0x38; bl #0x46c54] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x9310c; add x0, x19, #0x38; bl #0x46c54]
uint64_t fde_sub_06942c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400A737ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06942CULL;
}

// FDE #1475 | PC: 0x069448..0x0694c0 (120 B) | Symbol: sub_069448
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x23, x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_069448(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9035BF7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069448ULL;
}

// FDE #1476 | PC: 0x0694c0..0x0694fc (60 B) | Symbol: sub_0694c0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x930d4; adrp x8, #0x9b000; add x8, x8, #0x570] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x930d4; adrp x8, #0x9b000; add x8, x8, #0x570]
uint64_t fde_sub_0694c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9400A704ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0694C0ULL;
}

// FDE #1477 | PC: 0x0694fc..0x06972c (560 B) | Symbol: sub_0694fc
// EN: AArch64 prologue [str x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_0694fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xF81C0FF8ULL;
    const uint64_t kPcRange = 0x0230ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0694FCULL;
}

// FDE #1478 | PC: 0x06972c..0x0697c0 (148 B) | Symbol: sub_06972c
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8d614] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; bl #0x8d614]
uint64_t fde_sub_06972c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06972CULL;
}

// FDE #1479 | PC: 0x0697c0..0x069824 (100 B) | Symbol: sub_0697c0
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x20, [x0, #0x20]; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x20, [x0, #0x20]; mov x19, x0]
uint64_t fde_sub_0697c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0697C0ULL;
}

// FDE #1480 | PC: 0x069824..0x069848 (36 B) | Symbol: sub_069824
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8db6c; bl #0x931d0; ldr x0, [x19, #8]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8db6c; bl #0x931d0; ldr x0, [x19, #8]]
uint64_t fde_sub_069824(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940090D1ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069824ULL;
}

// FDE #1481 | PC: 0x069848..0x0699d4 (396 B) | Symbol: sub_069848
// EN: AArch64 prologue [sub sp, sp, #0x160; stp x28, x22, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; stp x28, x22, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]]
uint64_t fde_sub_069848(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9135BFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x018CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069848ULL;
}

// FDE #1482 | PC: 0x0699d4..0x0699dc (8 B) | Symbol: sub_0699d4
// EN: AArch64 prologue [ldr x0, [x0, #0x18]; b #0x69848] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x18]; b #0x69848]
uint64_t fde_sub_0699d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFFF9CULL) << 32) | 0xF9400C00ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0699D4ULL;
}

// FDE #1483 | PC: 0x0699dc..0x0699e4 (8 B) | Symbol: sub_0699dc
// EN: AArch64 prologue [ldr w8, [x0]; b #0x92b94] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0]; b #0x92b94]
uint64_t fde_sub_0699dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400A46DULL) << 32) | 0xB9400008ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0699DCULL;
}

// FDE #1484 | PC: 0x0699e4..0x069a2c (72 B) | Symbol: sub_0699e4
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8db6c; ldr x8, [x19, #0x18]] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8db6c; ldr x8, [x19, #0x18]]
uint64_t fde_sub_0699e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0699E4ULL;
}

// FDE #1485 | PC: 0x069a2c..0x069a74 (72 B) | Symbol: sub_069a2c
// EN: AArch64 prologue [mov x9, #0x2600; mov w8, #1; movk x9, #1, lsl #32; ldr x10, [x0]] | VI: Khởi đầu hàm AArch64 [mov x9, #0x2600; mov w8, #1; movk x9, #1, lsl #32; ldr x10, [x0]]
uint64_t fde_sub_069a2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800028ULL) << 32) | 0xD284C009ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069A2CULL;
}

// FDE #1486 | PC: 0x069a74..0x06a660 (3052 B) | Symbol: sub_069a74
// EN: AArch64 prologue [str d8, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str d8, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_069a74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xFC1C0FE8ULL;
    const uint64_t kPcRange = 0x0BECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069A74ULL;
}

// FDE #1487 | PC: 0x06a660..0x06aa40 (992 B) | Symbol: sub_06a660
// EN: AArch64 prologue [sub sp, sp, #0x70; mov x4, x30; bl #0x90cd8; mov x30, x4] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; mov x4, x30; bl #0x90cd8; mov x30, x4]
uint64_t fde_sub_06a660(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E4ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x03E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A660ULL;
}

// FDE #1488 | PC: 0x06aa40..0x06aa90 (80 B) | Symbol: sub_06aa40
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8ef10; cbz x20, #0x6aa58] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8ef10; cbz x20, #0x6aa58]
uint64_t fde_sub_06aa40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AA40ULL;
}

// FDE #1489 | PC: 0x06aa90..0x06aad0 (64 B) | Symbol: sub_06aa90
// EN: AArch64 prologue [str d8, [sp, #-0x10]!; str x30, [sp, #8]; mov v8.16b, v0.16b; cmn w0, #0x134] | VI: Khởi đầu hàm AArch64 [str d8, [sp, #-0x10]!; str x30, [sp, #8]; mov v8.16b, v0.16b; cmn w0, #0x134]
uint64_t fde_sub_06aa90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90007FEULL) << 32) | 0xFC1F0FE8ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AA90ULL;
}

// FDE #1490 | PC: 0x06aad0..0x06ab64 (148 B) | Symbol: sub_06aad0
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; cbz x1, #0x6ab58] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; cbz x1, #0x6ab58]
uint64_t fde_sub_06aad0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AAD0ULL;
}

// FDE #1491 | PC: 0x06ab64..0x06abb4 (80 B) | Symbol: sub_06ab64
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8ef10; cbz x20, #0x6ab7c] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8ef10; cbz x20, #0x6ab7c]
uint64_t fde_sub_06ab64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AB64ULL;
}

// FDE #1492 | PC: 0x06abb4..0x06ac44 (144 B) | Symbol: sub_06abb4
// EN: AArch64 prologue [mov x8, x0; mov w0, wzr; mov w9, #4; cbz w9, #0x6ac2c] | VI: Khởi đầu hàm AArch64 [mov x8, x0; mov w0, wzr; mov w9, #4; cbz w9, #0x6ac2c]
uint64_t fde_sub_06abb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x2A1F03E0ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06ABB4ULL;
}

// FDE #1493 | PC: 0x06ac44..0x06acf4 (176 B) | Symbol: sub_06ac44
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldp x20, x8, [x0, #0x40]] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldp x20, x8, [x0, #0x40]]
uint64_t fde_sub_06ac44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AC44ULL;
}

// FDE #1494 | PC: 0x06acf4..0x06ad44 (80 B) | Symbol: sub_06acf4
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldp x8, x9, [x0, #0x40]; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldp x8, x9, [x0, #0x40]; mov x19, x0]
uint64_t fde_sub_06acf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06ACF4ULL;
}

// FDE #1495 | PC: 0x06ad44..0x06af38 (500 B) | Symbol: sub_06ad44
// EN: AArch64 prologue [sub sp, sp, #0x190; stp x28, x26, [sp, #0x140]; stp x25, x24, [sp, #0x150]; stp x23, x22, [sp, #0x160]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x190; stp x28, x26, [sp, #0x140]; stp x25, x24, [sp, #0x150]; stp x23, x22, [sp, #0x160]]
uint64_t fde_sub_06ad44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9146BFCULL) << 32) | 0xD10643FFULL;
    const uint64_t kPcRange = 0x01F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AD44ULL;
}

// FDE #1496 | PC: 0x06af38..0x06af58 (32 B) | Symbol: sub_06af38
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x6af58; adrp x8, #0x9b000] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x6af58; adrp x8, #0x9b000]
uint64_t fde_sub_06af38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AF38ULL;
}

// FDE #1497 | PC: 0x06af58..0x06af68 (16 B) | Symbol: sub_06af58
// EN: AArch64 prologue [adrp x8, #0x9b000; add x8, x8, #0x5a0; str x8, [x0], #8; b #0x44768] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x9b000; add x8, x8, #0x5a0; str x8, [x0], #8; b #0x44768]
uint64_t fde_sub_06af58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91168108ULL) << 32) | 0xB0000188ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AF58ULL;
}

// FDE #1498 | PC: 0x06af68..0x06b170 (520 B) | Symbol: sub_06af68
// EN: AArch64 prologue [sub sp, sp, #0x1a0; stp x28, x27, [sp, #0x140]; stp x26, x25, [sp, #0x150]; stp x24, x23, [sp, #0x160]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1a0; stp x28, x27, [sp, #0x140]; stp x26, x25, [sp, #0x150]; stp x24, x23, [sp, #0x160]]
uint64_t fde_sub_06af68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9146FFCULL) << 32) | 0xD10683FFULL;
    const uint64_t kPcRange = 0x0208ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AF68ULL;
}

// FDE #1499 | PC: 0x06b170..0x06b8fc (1932 B) | Symbol: sub_06b170
// EN: AArch64 prologue [sub sp, sp, #0x160; stp x28, x27, [sp, #0x100]; stp x26, x25, [sp, #0x110]; stp x24, x23, [sp, #0x120]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; stp x28, x27, [sp, #0x100]; stp x26, x25, [sp, #0x110]; stp x24, x23, [sp, #0x120]]
uint64_t fde_sub_06b170(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9106FFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x078CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B170ULL;
}

// FDE #1500 | PC: 0x06b8fc..0x06b984 (136 B) | Symbol: sub_06b8fc
// EN: AArch64 prologue [str x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_06b8fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xF81C0FF8ULL;
    const uint64_t kPcRange = 0x0088ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B8FCULL;
}

// FDE #1501 | PC: 0x06b984..0x06b98c (8 B) | Symbol: sub_06b984
// EN: AArch64 prologue [fmov s0, #1.00000000; b #0x6ff04] | VI: Khởi đầu hàm AArch64 [fmov s0, #1.00000000; b #0x6ff04]
uint64_t fde_sub_06b984(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x1400115FULL) << 32) | 0x1E2E1000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B984ULL;
}

// FDE #1502 | PC: 0x06b98c..0x06b9f8 (108 B) | Symbol: sub_06b98c
// EN: AArch64 prologue [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; cbz x0, #0x6b9e0; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; stp x19, x30, [sp, #0x10]; cbz x0, #0x6b9e0; ldr x8, [x0]]
uint64_t fde_sub_06b98c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B98CULL;
}

// FDE #1503 | PC: 0x06b9f8..0x06ba44 (76 B) | Symbol: sub_06b9f8
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x0] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x0]
uint64_t fde_sub_06b9f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B9F8ULL;
}

// FDE #1504 | PC: 0x06ba44..0x06ba4c (8 B) | Symbol: sub_06ba44
// EN: AArch64 prologue [mov w3, #1; b #0x6ba4c] | VI: Khởi đầu hàm AArch64 [mov w3, #1; b #0x6ba4c]
uint64_t fde_sub_06ba44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0x52800023ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BA44ULL;
}

// FDE #1505 | PC: 0x06ba4c..0x06bab4 (104 B) | Symbol: sub_06ba4c
// EN: AArch64 prologue [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x22, x0] | VI: Khởi đầu hàm AArch64 [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x22, x0]
uint64_t fde_sub_06ba4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xA9BD5BF7ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BA4CULL;
}

// FDE #1506 | PC: 0x06bab4..0x06baf0 (60 B) | Symbol: sub_06bab4
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x0] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x0]
uint64_t fde_sub_06bab4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BAB4ULL;
}

// FDE #1507 | PC: 0x06baf0..0x06bb10 (32 B) | Symbol: sub_06baf0
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x6af58; adrp x8, #0x9b000] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x6af58; adrp x8, #0x9b000]
uint64_t fde_sub_06baf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BAF0ULL;
}

// FDE #1508 | PC: 0x06bb10..0x06bb50 (64 B) | Symbol: sub_06bb10
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x0] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x0]
uint64_t fde_sub_06bb10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BB10ULL;
}

// FDE #1509 | PC: 0x06bb50..0x06bb94 (68 B) | Symbol: sub_06bb50
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x0] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x0]
uint64_t fde_sub_06bb50(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BB50ULL;
}

// FDE #1510 | PC: 0x06bb94..0x06bbd8 (68 B) | Symbol: sub_06bb94
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x0] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x21, x0]
uint64_t fde_sub_06bb94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BB94ULL;
}

// FDE #1511 | PC: 0x06bbd8..0x06d070 (5272 B) | Symbol: sub_06bbd8
// EN: AArch64 prologue [str d14, [sp, #-0xa0]!; stp d13, d12, [sp, #0x10]; stp d11, d10, [sp, #0x20]; stp d9, d8, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str d14, [sp, #-0xa0]!; stp d13, d12, [sp, #0x10]; stp d11, d10, [sp, #0x20]; stp d9, d8, [sp, #0x30]]
uint64_t fde_sub_06bbd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D0133EDULL) << 32) | 0xFC160FEEULL;
    const uint64_t kPcRange = 0x1498ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BBD8ULL;
}

// FDE #1512 | PC: 0x06d070..0x06d0bc (76 B) | Symbol: sub_06d070
// EN: AArch64 prologue [ldrh w8, [x0, #0x16]; tbnz w8, #9, #0x6d090; tbnz w8, #5, #0x6d098; tbnz w8, #6, #0x6d0a4] | VI: Khởi đầu hàm AArch64 [ldrh w8, [x0, #0x16]; tbnz w8, #9, #0x6d090; tbnz w8, #5, #0x6d098; tbnz w8, #6, #0x6d0a4]
uint64_t fde_sub_06d070(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x374800E8ULL) << 32) | 0x79402C08ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D070ULL;
}

// FDE #1513 | PC: 0x06d0bc..0x06d0e0 (36 B) | Symbol: sub_06d0bc
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8eb14; mov x1, x19] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8eb14; mov x1, x19]
uint64_t fde_sub_06d0bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D0BCULL;
}

// FDE #1514 | PC: 0x06d0e0..0x06d100 (32 B) | Symbol: sub_06d0e0
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x92110; bl #0x8e734] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x92110; bl #0x8e734]
uint64_t fde_sub_06d0e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D0E0ULL;
}

// FDE #1515 | PC: 0x06d100..0x06d120 (32 B) | Symbol: sub_06d100
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x38; bl #0x46c54] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; add x0, x0, #0x38; bl #0x46c54]
uint64_t fde_sub_06d100(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D100ULL;
}

// FDE #1516 | PC: 0x06d120..0x06d130 (16 B) | Symbol: sub_06d120
// EN: AArch64 prologue [ldr x0, [x0, #0x18]; cbz x0, #0x6d12c; b #0x8d448; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x18]; cbz x0, #0x6d12c; b #0x8d448; ret]
uint64_t fde_sub_06d120(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000040ULL) << 32) | 0xF9400C00ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D120ULL;
}

// FDE #1517 | PC: 0x06d130..0x06f204 (8404 B) | Symbol: sub_06d130
// EN: AArch64 prologue [str d8, [sp, #-0x70]!; mov x3, x30; bl #0x90cd8; mov x30, x3] | VI: Khởi đầu hàm AArch64 [str d8, [sp, #-0x70]!; mov x3, x30; bl #0x90cd8; mov x30, x3]
uint64_t fde_sub_06d130(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA1E03E3ULL) << 32) | 0xFC190FE8ULL;
    const uint64_t kPcRange = 0x20D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06D130ULL;
}

// FDE #1518 | PC: 0x06f204..0x06f23c (56 B) | Symbol: sub_06f204
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; mov x19, x0]
uint64_t fde_sub_06f204(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F204ULL;
}

// FDE #1519 | PC: 0x06f23c..0x06f254 (24 B) | Symbol: sub_06f23c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x6f204; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x6f204; mov x0, x19]
uint64_t fde_sub_06f23c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F23CULL;
}

// FDE #1520 | PC: 0x06f254..0x06f280 (44 B) | Symbol: sub_06f254
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x0] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x0]
uint64_t fde_sub_06f254(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F254ULL;
}

// FDE #1521 | PC: 0x06f280..0x06f2ec (108 B) | Symbol: sub_06f280
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr x21, [x1]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr x21, [x1]]
uint64_t fde_sub_06f280(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F280ULL;
}

// FDE #1522 | PC: 0x06f2ec..0x06f420 (308 B) | Symbol: sub_06f2ec
// EN: AArch64 prologue [str x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_06f2ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xF81C0FF8ULL;
    const uint64_t kPcRange = 0x0134ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F2ECULL;
}

// FDE #1523 | PC: 0x06f420..0x06f468 (72 B) | Symbol: sub_06f420
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x88]; adrp x8, #0x9b000] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x88]; adrp x8, #0x9b000]
uint64_t fde_sub_06f420(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F420ULL;
}

// FDE #1524 | PC: 0x06f468..0x06f480 (24 B) | Symbol: sub_06f468
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x6f420; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x6f420; mov x0, x19]
uint64_t fde_sub_06f468(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F468ULL;
}

// FDE #1525 | PC: 0x06f480..0x06f4ac (44 B) | Symbol: sub_06f480
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x0] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x0]
uint64_t fde_sub_06f480(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F480ULL;
}

// FDE #1526 | PC: 0x06f4ac..0x06f578 (204 B) | Symbol: sub_06f4ac
// EN: AArch64 prologue [str d8, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str d8, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_06f4ac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xFC1C0FE8ULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F4ACULL;
}

// FDE #1527 | PC: 0x06f578..0x06f7a8 (560 B) | Symbol: sub_06f578
// EN: AArch64 prologue [sub sp, sp, #0x1c0; stp d11, d10, [sp, #0x140]; stp d9, d8, [sp, #0x150]; str x28, [sp, #0x160]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1c0; stp d11, d10, [sp, #0x140]; stp d9, d8, [sp, #0x150]; str x28, [sp, #0x160]]
uint64_t fde_sub_06f578(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D142BEBULL) << 32) | 0xD10703FFULL;
    const uint64_t kPcRange = 0x0230ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F578ULL;
}

// FDE #1528 | PC: 0x06f7a8..0x06f83c (148 B) | Symbol: sub_06f7a8
// EN: AArch64 prologue [sub sp, sp, #0x150; stp x28, x20, [sp, #0x130]; stp x19, x30, [sp, #0x140]; mrs x19, tpidr_el0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x150; stp x28, x20, [sp, #0x130]; stp x19, x30, [sp, #0x140]; mrs x19, tpidr_el0]
uint64_t fde_sub_06f7a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA91353FCULL) << 32) | 0xD10543FFULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F7A8ULL;
}

// FDE #1529 | PC: 0x06f83c..0x06f8dc (160 B) | Symbol: sub_06f83c
// EN: AArch64 prologue [stp x25, x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x25, x24, [sp, #-0x40]!; stp x23, x22, [sp, #0x10]; stp x21, x20, [sp, #0x20]; stp x19, x30, [sp, #0x30]]
uint64_t fde_sub_06f83c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015BF7ULL) << 32) | 0xA9BC63F9ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F83CULL;
}

// FDE #1530 | PC: 0x06f8dc..0x06f94c (112 B) | Symbol: sub_06f8dc
// EN: AArch64 prologue [sub sp, sp, #0x20; str x30, [sp, #0x10]; ldrb w8, [x1, #0xc]; ldrb w10, [x2, #0xc]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x20; str x30, [sp, #0x10]; ldrb w8, [x1, #0xc]; ldrb w10, [x2, #0xc]]
uint64_t fde_sub_06f8dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BFEULL) << 32) | 0xD10083FFULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F8DCULL;
}

// FDE #1531 | PC: 0x06f94c..0x06fea8 (1372 B) | Symbol: sub_06f94c
// EN: AArch64 prologue [sub sp, sp, #0xe0; stp d13, d12, [sp, #0x50]; stp d11, d10, [sp, #0x60]; stp d9, d8, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xe0; stp d13, d12, [sp, #0x50]; stp d11, d10, [sp, #0x60]; stp d9, d8, [sp, #0x70]]
uint64_t fde_sub_06f94c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D0533EDULL) << 32) | 0xD10383FFULL;
    const uint64_t kPcRange = 0x055CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06F94CULL;
}

// FDE #1532 | PC: 0x06fea8..0x06ff04 (92 B) | Symbol: sub_06fea8
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x2] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x19, x2]
uint64_t fde_sub_06fea8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FEA8ULL;
}

// FDE #1533 | PC: 0x06ff04..0x070088 (388 B) | Symbol: sub_06ff04
// EN: AArch64 prologue [sub sp, sp, #0x1a0; str d8, [sp, #0x130]; stp x28, x27, [sp, #0x140]; stp x26, x25, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1a0; str d8, [sp, #0x130]; stp x28, x27, [sp, #0x140]; stp x26, x25, [sp, #0x150]]
uint64_t fde_sub_06ff04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD009BE8ULL) << 32) | 0xD10683FFULL;
    const uint64_t kPcRange = 0x0184ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06FF04ULL;
}

// FDE #1534 | PC: 0x070088..0x0701d8 (336 B) | Symbol: sub_070088
// EN: AArch64 prologue [sub sp, sp, #0x60; str x26, [sp, #0x10]; stp x25, x24, [sp, #0x20]; stp x23, x22, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x26, [sp, #0x10]; stp x25, x24, [sp, #0x20]; stp x23, x22, [sp, #0x30]]
uint64_t fde_sub_070088(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BFAULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0150ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x070088ULL;
}

// FDE #1535 | PC: 0x0701d8..0x0716bc (5348 B) | Symbol: sub_0701d8
// EN: AArch64 prologue [str d14, [sp, #-0xa0]!; stp d13, d12, [sp, #0x10]; stp d11, d10, [sp, #0x20]; stp d9, d8, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str d14, [sp, #-0xa0]!; stp d13, d12, [sp, #0x10]; stp d11, d10, [sp, #0x20]; stp d9, d8, [sp, #0x30]]
uint64_t fde_sub_0701d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D0133EDULL) << 32) | 0xFC160FEEULL;
    const uint64_t kPcRange = 0x14E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0701D8ULL;
}

// FDE #1536 | PC: 0x0716bc..0x0716d4 (24 B) | Symbol: sub_0716bc
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x64ab0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x64ab0; mov x0, x19]
uint64_t fde_sub_0716bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0716BCULL;
}

// FDE #1537 | PC: 0x0716d4..0x071738 (100 B) | Symbol: sub_0716d4
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; mov w0, #0x60] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; mov w0, #0x60]
uint64_t fde_sub_0716d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0716D4ULL;
}

// FDE #1538 | PC: 0x071738..0x071770 (56 B) | Symbol: sub_071738
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9b000; mov x19, x0]
uint64_t fde_sub_071738(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071738ULL;
}

// FDE #1539 | PC: 0x071770..0x071788 (24 B) | Symbol: sub_071770
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x71738; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x71738; mov x0, x19]
uint64_t fde_sub_071770(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071770ULL;
}

// FDE #1540 | PC: 0x071788..0x0717b4 (44 B) | Symbol: sub_071788
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x0] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x20, x0]
uint64_t fde_sub_071788(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071788ULL;
}

// FDE #1541 | PC: 0x0717b4..0x0717f8 (68 B) | Symbol: sub_0717b4
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e578; bl #0x91588] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e578; bl #0x91588]
uint64_t fde_sub_0717b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0717B4ULL;
}

// FDE #1542 | PC: 0x0717f8..0x071818 (32 B) | Symbol: sub_0717f8
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x9310c; add x0, x19, #0x30; bl #0x46c54] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x9310c; add x0, x19, #0x30; bl #0x46c54]
uint64_t fde_sub_0717f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94008644ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0717F8ULL;
}

// FDE #1543 | PC: 0x071818..0x071848 (48 B) | Symbol: sub_071818
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x88]; adrp x8, #0x9b000] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; ldr x0, [x0, #0x88]; adrp x8, #0x9b000]
uint64_t fde_sub_071818(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071818ULL;
}

// FDE #1544 | PC: 0x071848..0x071860 (24 B) | Symbol: sub_071848
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x71818; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x71818; mov x0, x19]
uint64_t fde_sub_071848(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071848ULL;
}

// FDE #1545 | PC: 0x071860..0x07186c (12 B) | Symbol: sub_071860
// EN: AArch64 prologue [ldr x8, [x1]; ldr x2, [x8, #0x10]; b #0x8fa58] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1]; ldr x2, [x8, #0x10]; b #0x8fa58]
uint64_t fde_sub_071860(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400902ULL) << 32) | 0xF9400028ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071860ULL;
}

// FDE #1546 | PC: 0x07186c..0x071874 (8 B) | Symbol: sub_07186c
// EN: AArch64 prologue [mov x1, xzr; b #0x71874] | VI: Khởi đầu hàm AArch64 [mov x1, xzr; b #0x71874]
uint64_t fde_sub_07186c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14000001ULL) << 32) | 0xAA1F03E1ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x07186CULL;
}

// FDE #1547 | PC: 0x071874..0x0718a0 (44 B) | Symbol: sub_071874
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8dcc8; cbz x19, #0x71898; ldr x8, [x19, #0x10]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8dcc8; cbz x19, #0x71898; ldr x8, [x19, #0x10]]
uint64_t fde_sub_071874(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x94007114ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x071874ULL;
}

// FDE #1548 | PC: 0x0718a0..0x072984 (4324 B) | Symbol: sub_0718a0
// EN: AArch64 prologue [str d12, [sp, #-0x90]!; stp d11, d10, [sp, #0x10]; stp d9, d8, [sp, #0x20]; stp x28, x27, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str d12, [sp, #-0x90]!; stp d11, d10, [sp, #0x10]; stp d9, d8, [sp, #0x20]; stp x28, x27, [sp, #0x30]]
uint64_t fde_sub_0718a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6D012BEBULL) << 32) | 0xFC170FECULL;
    const uint64_t kPcRange = 0x10E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0718A0ULL;
}

// FDE #1549 | PC: 0x072984..0x0729dc (88 B) | Symbol: sub_072984
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x22, x0] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; mov x22, x0]
uint64_t fde_sub_072984(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x072984ULL;
}

// FDE #1550 | PC: 0x0729dc..0x0729e4 (8 B) | Symbol: sub_0729dc
// EN: AArch64 prologue [mov w0, #0xc; ret] | VI: Khởi đầu hàm AArch64 [mov w0, #0xc; ret]
uint64_t fde_sub_0729dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x52800180ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0729DCULL;
}

// FDE #1551 | PC: 0x0729e4..0x072a18 (52 B) | Symbol: sub_0729e4
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8fb40; ldur q0, [x19, #8]] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8fb40; ldur q0, [x19, #8]]
uint64_t fde_sub_0729e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0729E4ULL;
}

// FDE #1552 | PC: 0x072a18..0x072a48 (48 B) | Symbol: sub_072a18
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x19, x30, [sp, #0x30]; bl #0x90988; b.hs #0x72a40] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x19, x30, [sp, #0x30]; bl #0x90988; b.hs #0x72a40]
uint64_t fde_sub_072a18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9037BF3ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x072A18ULL;
}

// FDE #1553 | PC: 0x072a48..0x072a88 (64 B) | Symbol: sub_072a48
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8df88; cbz x1, #0x72a68] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8df88; cbz x1, #0x72a68]
uint64_t fde_sub_072a48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x072A48ULL;
}

// FDE #1554 | PC: 0x072a88..0x072aa8 (32 B) | Symbol: sub_072a88
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e134; b.lt #0x72a9c] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e134; b.lt #0x72a9c]
uint64_t fde_sub_072a88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x072A88ULL;
}

// FDE #1555 | PC: 0x072aa8..0x072ac4 (28 B) | Symbol: sub_072aa8
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x90c98; bl #0x72fb4] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x90c98; bl #0x72fb4]
uint64_t fde_sub_072aa8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x072AA8ULL;
}

// FDE #1556 | PC: 0x072ac4..0x072aec (40 B) | Symbol: sub_072ac4
// EN: AArch64 prologue [ldp x8, x9, [x0, #8]; cmp x8, x9; b.eq #0x72adc; sub x9, x9, #0x18] | VI: Khởi đầu hàm AArch64 [ldp x8, x9, [x0, #8]; cmp x8, x9; b.eq #0x72adc; sub x9, x9, #0x18]
uint64_t fde_sub_072ac4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB09011FULL) << 32) | 0xA940A408ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x072AC4ULL;
}

// FDE #1557 | PC: 0x072aec..0x072e18 (812 B) | Symbol: sub_072aec
// EN: AArch64 prologue [sub sp, sp, #0xc0; stp x28, x27, [sp, #0x60]; stp x26, x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; stp x28, x27, [sp, #0x60]; stp x26, x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]]
uint64_t fde_sub_072aec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9066FFCULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x032CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x072AECULL;
}

// FDE #1558 | PC: 0x072e18..0x072e94 (124 B) | Symbol: sub_072e18
// EN: AArch64 prologue [cmp x2, x0; b.eq #0x72e7c; cmp x2, x1; b.eq #0x72e84] | VI: Khởi đầu hàm AArch64 [cmp x2, x0; b.eq #0x72e7c; cmp x2, x1; b.eq #0x72e84]
uint64_t fde_sub_072e18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000300ULL) << 32) | 0xEB00005FULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x072E18ULL;
}

// FDE #1559 | PC: 0x072e94..0x072f40 (172 B) | Symbol: sub_072e94
// EN: AArch64 prologue [cmp x3, x1; mov x8, x0; b.eq #0x72f00; cmp x3, x2] | VI: Khởi đầu hàm AArch64 [cmp x3, x1; mov x8, x0; b.eq #0x72f00; cmp x3, x2]
uint64_t fde_sub_072e94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003E8ULL) << 32) | 0xEB01007FULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x072E94ULL;
}

// FDE #1560 | PC: 0x072f40..0x072fb4 (116 B) | Symbol: sub_072f40
// EN: AArch64 prologue [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x22, [sp, #0x30]; stp x21, x20, [sp, #0x40]; stp x19, x30, [sp, #0x50]]
uint64_t fde_sub_072f40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF6ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x072F40ULL;
}

// FDE #1561 | PC: 0x072fb4..0x072ff4 (64 B) | Symbol: sub_072fb4
// EN: AArch64 prologue [adrp x9, #0x9b000; sub x8, x0, x1; add x9, x9, #0x8f8; cbz x8, #0x72ff0] | VI: Khởi đầu hàm AArch64 [adrp x9, #0x9b000; sub x8, x0, x1; add x9, x9, #0x8f8; cbz x8, #0x72ff0]
uint64_t fde_sub_072fb4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xCB010008ULL) << 32) | 0xB0000149ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x072FB4ULL;
}

// FDE #1562 | PC: 0x072ff4..0x073068 (116 B) | Symbol: _ZN4lynx6animax17VideoPlayerCustomC2ENSt6__ndk110unique_ptrINS0_18VideoDecoderCustomENS2_14default_deleteIS4_EEEE
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e128; bl #0x73068] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; bl #0x8e128; bl #0x73068]
uint64_t fde_sub_072ff4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x072FF4ULL;
}

// FDE #1563 | PC: 0x073068..0x0730d4 (108 B) | Symbol: sub_073068
// EN: AArch64 prologue [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]]
uint64_t fde_sub_073068(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9009BFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073068ULL;
}

// FDE #1564 | PC: 0x0730d4..0x073168 (148 B) | Symbol: _ZN4lynx6animax17VideoPlayerCustomD1Ev
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9d000; bl #0x930f4] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; adrp x8, #0x9d000; bl #0x930f4]
uint64_t fde_sub_0730d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0094ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0730D4ULL;
}

// FDE #1565 | PC: 0x073168..0x073180 (24 B) | Symbol: _ZN4lynx6animax17VideoPlayerCustomD0Ev
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x93aa0; mov x0, x19] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; mov x19, x0; bl #0x93aa0; mov x0, x19]
uint64_t fde_sub_073168(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xAA0003F3ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073168ULL;
}

// FDE #1566 | PC: 0x073180..0x0732bc (316 B) | Symbol: _ZN4lynx6animax17VideoPlayerCustom13UpdateTextureEi
// EN: AArch64 prologue [sub sp, sp, #0x1a0; stp x28, x22, [sp, #0x170]; stp x21, x20, [sp, #0x180]; stp x19, x30, [sp, #0x190]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1a0; stp x28, x22, [sp, #0x170]; stp x21, x20, [sp, #0x180]; stp x19, x30, [sp, #0x190]]
uint64_t fde_sub_073180(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9175BFCULL) << 32) | 0xD10683FFULL;
    const uint64_t kPcRange = 0x013CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073180ULL;
}

// FDE #1567 | PC: 0x0732bc..0x0732c4 (8 B) | Symbol: _ZN4lynx6animax17VideoPlayerCustom12GetTransformEv
// EN: AArch64 prologue [add x0, x0, #0x58; ret] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x58; ret]
uint64_t fde_sub_0732bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0x91016000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0732BCULL;
}

// FDE #1568 | PC: 0x0732c4..0x073400 (316 B) | Symbol: _ZN4lynx6animax17VideoPlayerCustom11AttachAssetENSt6__ndk110shared_ptrINS0_10VideoAssetEEE
// EN: AArch64 prologue [sub sp, sp, #0x170; stp x28, x20, [sp, #0x150]; stp x19, x30, [sp, #0x160]; bl #0x8dab0] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; stp x28, x20, [sp, #0x150]; stp x19, x30, [sp, #0x160]; bl #0x8dab0]
uint64_t fde_sub_0732c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA91553FCULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x013CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0732C4ULL;
}

// FDE #1569 | PC: 0x073400..0x073478 (120 B) | Symbol: _ZN4lynx6animax17VideoPlayerCustom16PrepareNextFrameEv
// EN: AArch64 prologue [sub sp, sp, #0x30; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr x8, [x0, #0x98]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; str x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; ldr x8, [x0, #0x98]]
uint64_t fde_sub_073400(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073400ULL;
}

// FDE #1570 | PC: 0x073478..0x073658 (480 B) | Symbol: _ZN4lynx6animax17VideoPlayerCustom19DecodeAndCacheFrameEi
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp x25, x24, [sp, #0x60]; stp x23, x22, [sp, #0x70]; stp x21, x20, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp x25, x24, [sp, #0x60]; stp x23, x22, [sp, #0x70]; stp x21, x20, [sp, #0x80]]
uint64_t fde_sub_073478(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90663F9ULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x01E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073478ULL;
}

// FDE #1571 | PC: 0x073658..0x0736cc (116 B) | Symbol: _ZNK4lynx6animax17VideoPlayerCustom14GetCachedFrameEi
// EN: AArch64 prologue [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; add x19, x0, #0xa8] | VI: Khởi đầu hàm AArch64 [str x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; add x19, x0, #0xa8]
uint64_t fde_sub_073658(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xF81D0FF6ULL;
    const uint64_t kPcRange = 0x0074ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073658ULL;
}

// FDE #1572 | PC: 0x0736cc..0x073730 (100 B) | Symbol: _ZN4lynx6animax17VideoPlayerCustom20ClearAllCachedFramesEv
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; add x19, x0, #0xa8; mov x20, x0] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; add x19, x0, #0xa8; mov x20, x0]
uint64_t fde_sub_0736cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0064ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0736CCULL;
}

// FDE #1573 | PC: 0x073730..0x073778 (72 B) | Symbol: _ZNK4lynx6animax17VideoPlayerCustom13IsFrameCachedEi
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; add x21, x0, #0xa8; mov x20, x0] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; add x21, x0, #0xa8; mov x20, x0]
uint64_t fde_sub_073730(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073730ULL;
}

// FDE #1574 | PC: 0x073778..0x0737f8 (128 B) | Symbol: _ZN4lynx6animax17VideoPlayerCustom16GetReusableFrameEv
// EN: AArch64 prologue [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; add x19, x0, #0xa8] | VI: Khởi đầu hàm AArch64 [stp x23, x22, [sp, #-0x30]!; stp x21, x20, [sp, #0x10]; stp x19, x30, [sp, #0x20]; add x19, x0, #0xa8]
uint64_t fde_sub_073778(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90153F5ULL) << 32) | 0xA9BD5BF7ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073778ULL;
}

// FDE #1575 | PC: 0x0737f8..0x073d3c (1348 B) | Symbol: _ZN4lynx6animax17VideoPlayerCustom10CacheFrameEiNSt6__ndk110shared_ptrINS0_12YUVFrameInfoEEE
// EN: AArch64 prologue [mov x3, x30; bl #0x913b8; mov x30, x3; stp x29, x30, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [mov x3, x30; bl #0x913b8; mov x30, x3; stp x29, x30, [sp, #0x70]]
uint64_t fde_sub_0737f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940076EFULL) << 32) | 0xAA1E03E3ULL;
    const uint64_t kPcRange = 0x0544ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0737F8ULL;
}

// FDE #1576 | PC: 0x073d3c..0x073d4c (16 B) | Symbol: sub_073d3c
// EN: AArch64 prologue [tst w1, #0xff; b.eq #0x73d48; b #0x93b20; ret] | VI: Khởi đầu hàm AArch64 [tst w1, #0xff; b.eq #0x73d48; b #0x93b20; ret]
uint64_t fde_sub_073d3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000040ULL) << 32) | 0x72001C3FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073D3CULL;
}

// FDE #1577 | PC: 0x073d4c..0x073d7c (48 B) | Symbol: sub_073d4c
// EN: AArch64 prologue [stp x19, x30, [sp, #-0x10]!; bl #0x8dff0; cbz x19, #0x73d74; ldrb w8, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [stp x19, x30, [sp, #-0x10]!; bl #0x8dff0; cbz x19, #0x73d74; ldrb w8, [x0, #0x10]]
uint64_t fde_sub_073d4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x940068A8ULL) << 32) | 0xA9BF7BF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073D4CULL;
}

// FDE #1578 | PC: 0x073d7c..0x073db0 (52 B) | Symbol: sub_073d7c
// EN: AArch64 prologue [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x21, [x0, #8]; bl #0x8e454] | VI: Khởi đầu hàm AArch64 [stp x21, x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; ldr x21, [x0, #8]; bl #0x8e454]
uint64_t fde_sub_073d7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xA9BE53F5ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073D7CULL;
}

// FDE #1579 | PC: 0x073db0..0x073e58 (168 B) | Symbol: sub_073db0
// EN: AArch64 prologue [ldr x8, [x0, #8]; cbz x8, #0x73e50; fmov d0, x8; cnt v0.8b, v0.8b] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; cbz x8, #0x73e50; fmov d0, x8; cnt v0.8b, v0.8b]
uint64_t fde_sub_073db0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB40004E8ULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073DB0ULL;
}

// FDE #1580 | PC: 0x073e58..0x073e68 (16 B) | Symbol: sub_073e58
// EN: AArch64 prologue [tst w1, #0xff; b.eq #0x73e64; b #0x93b30; ret] | VI: Khởi đầu hàm AArch64 [tst w1, #0xff; b.eq #0x73e64; b #0x93b30; ret]
uint64_t fde_sub_073e58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000040ULL) << 32) | 0x72001C3FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073E58ULL;
}

// FDE #1581 | PC: 0x073e68..0x073e98 (48 B) | Symbol: sub_073e68
// EN: AArch64 prologue [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; cbz x19, #0x73e90] | VI: Khởi đầu hàm AArch64 [str x20, [sp, #-0x20]!; stp x19, x30, [sp, #0x10]; mov x19, x0; cbz x19, #0x73e90]
uint64_t fde_sub_073e68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BF3ULL) << 32) | 0xF81E0FF4ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073E68ULL;
}

// FDE #1582 | PC: 0x073e98..0x073f08 (112 B) | Symbol: sub_073e98
// EN: AArch64 prologue [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x160; str x28, [sp, #0x130]; stp x21, x20, [sp, #0x140]; stp x19, x30, [sp, #0x150]]
uint64_t fde_sub_073e98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9009BFCULL) << 32) | 0xD10583FFULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073E98ULL;
}

// FDE #1583 | PC: 0x073f08..0x073f10 (8 B) | Symbol: _ZNK4lynx6animax12YUVFrameInfo8GetWidthEv
// EN: AArch64 prologue [ldr w0, [x0, #0x20]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0x20]; ret]
uint64_t fde_sub_073f08(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9402000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073F08ULL;
}

// FDE #1584 | PC: 0x073f10..0x073f18 (8 B) | Symbol: _ZNK4lynx6animax6Bitmap9AlphaTypeEv
// EN: AArch64 prologue [ldr w0, [x0, #0x24]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0, #0x24]; ret]
uint64_t fde_sub_073f10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9402400ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073F10ULL;
}

// FDE #1585 | PC: 0x073f18..0x073f28 (16 B) | Symbol: _ZN4lynx6animax12YUVFrameInfo11SetLineSizeEjj
// EN: AArch64 prologue [cmp w1, #2; b.hi #0x73f24; str w2, [x0, w1, uxtw #2]; ret] | VI: Khởi đầu hàm AArch64 [cmp w1, #2; b.hi #0x73f24; str w2, [x0, w1, uxtw #2]; ret]
uint64_t fde_sub_073f18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000048ULL) << 32) | 0x7100083FULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x073F18ULL;
}

uint64_t DispatchAnimaXShard2(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x057a34ULL: return fde_sub_057a34(a0, a1, a2);
        case 0x057a44ULL: return fde_sub_057a44(a0, a1, a2);
        case 0x057a54ULL: return fde_sub_057a54(a0, a1, a2);
        case 0x057a6cULL: return fde_sub_057a6c(a0, a1, a2);
        case 0x057a78ULL: return fde_sub_057a78(a0, a1, a2);
        case 0x057b14ULL: return fde_sub_057b14(a0, a1, a2);
        case 0x057b24ULL: return fde_sub_057b24(a0, a1, a2);
        case 0x057b34ULL: return fde_sub_057b34(a0, a1, a2);
        case 0x057b4cULL: return fde_sub_057b4c(a0, a1, a2);
        case 0x057b5cULL: return fde_sub_057b5c(a0, a1, a2);
        case 0x057cccULL: return fde_sub_057ccc(a0, a1, a2);
        case 0x057cdcULL: return fde_sub_057cdc(a0, a1, a2);
        case 0x057cfcULL: return fde_sub_057cfc(a0, a1, a2);
        case 0x057d14ULL: return fde_sub_057d14(a0, a1, a2);
        case 0x057d24ULL: return fde_sub_057d24(a0, a1, a2);
        case 0x057d3cULL: return fde_sub_057d3c(a0, a1, a2);
        case 0x057d4cULL: return fde_sub_057d4c(a0, a1, a2);
        case 0x057da0ULL: return fde_sub_057da0(a0, a1, a2);
        case 0x057dbcULL: return fde_sub_057dbc(a0, a1, a2);
        case 0x057e98ULL: return fde_sub_057e98(a0, a1, a2);
        case 0x057eacULL: return fde_sub_057eac(a0, a1, a2);
        case 0x057ebcULL: return fde_sub_057ebc(a0, a1, a2);
        case 0x057ed4ULL: return fde_sub_057ed4(a0, a1, a2);
        case 0x057ee4ULL: return fde_sub_057ee4(a0, a1, a2);
        case 0x057fc0ULL: return fde_sub_057fc0(a0, a1, a2);
        case 0x057fd4ULL: return fde_sub_057fd4(a0, a1, a2);
        case 0x057fe4ULL: return fde_sub_057fe4(a0, a1, a2);
        case 0x057ffcULL: return fde_sub_057ffc(a0, a1, a2);
        case 0x05800cULL: return fde_sub_05800c(a0, a1, a2);
        case 0x058148ULL: return fde_sub_058148(a0, a1, a2);
        case 0x058180ULL: return fde_sub_058180(a0, a1, a2);
        case 0x058198ULL: return fde_sub_058198(a0, a1, a2);
        case 0x0581a8ULL: return fde_sub_0581a8(a0, a1, a2);
        case 0x0581c0ULL: return fde_sub_0581c0(a0, a1, a2);
        case 0x0581d0ULL: return fde_sub_0581d0(a0, a1, a2);
        case 0x058280ULL: return fde_sub_058280(a0, a1, a2);
        case 0x058290ULL: return fde_sub_058290(a0, a1, a2);
        case 0x0582a0ULL: return fde_sub_0582a0(a0, a1, a2);
        case 0x0582b8ULL: return fde_sub_0582b8(a0, a1, a2);
        case 0x0582c8ULL: return fde_sub_0582c8(a0, a1, a2);
        case 0x058358ULL: return fde_sub_058358(a0, a1, a2);
        case 0x058368ULL: return fde_sub_058368(a0, a1, a2);
        case 0x058380ULL: return fde_sub_058380(a0, a1, a2);
        case 0x058398ULL: return fde_sub_058398(a0, a1, a2);
        case 0x0583d0ULL: return fde_sub_0583d0(a0, a1, a2);
        case 0x0584a8ULL: return fde_sub_0584a8(a0, a1, a2);
        case 0x0584fcULL: return fde_sub_0584fc(a0, a1, a2);
        case 0x058514ULL: return fde_sub_058514(a0, a1, a2);
        case 0x058534ULL: return fde_sub_058534(a0, a1, a2);
        case 0x058544ULL: return fde_sub_058544(a0, a1, a2);
        case 0x05855cULL: return fde_sub_05855c(a0, a1, a2);
        case 0x05856cULL: return fde_sub_05856c(a0, a1, a2);
        case 0x058628ULL: return fde_sub_058628(a0, a1, a2);
        case 0x05864cULL: return fde_sub_05864c(a0, a1, a2);
        case 0x058668ULL: return fde_sub_058668(a0, a1, a2);
        case 0x058678ULL: return fde_sub_058678(a0, a1, a2);
        case 0x058690ULL: return fde_sub_058690(a0, a1, a2);
        case 0x0586a0ULL: return fde_sub_0586a0(a0, a1, a2);
        case 0x05875cULL: return fde_sub_05875c(a0, a1, a2);
        case 0x058780ULL: return fde_sub_058780(a0, a1, a2);
        case 0x058790ULL: return fde_sub_058790(a0, a1, a2);
        case 0x0587a8ULL: return fde_sub_0587a8(a0, a1, a2);
        case 0x0587b8ULL: return fde_sub_0587b8(a0, a1, a2);
        case 0x058874ULL: return fde_sub_058874(a0, a1, a2);
        case 0x058898ULL: return fde_sub_058898(a0, a1, a2);
        case 0x0588a8ULL: return fde_sub_0588a8(a0, a1, a2);
        case 0x0588c0ULL: return fde_sub_0588c0(a0, a1, a2);
        case 0x0588d0ULL: return fde_sub_0588d0(a0, a1, a2);
        case 0x0588d8ULL: return fde_sub_0588d8(a0, a1, a2);
        case 0x0588fcULL: return fde_sub_0588fc(a0, a1, a2);
        case 0x058908ULL: return fde_sub_058908(a0, a1, a2);
        case 0x058914ULL: return fde_sub_058914(a0, a1, a2);
        case 0x058938ULL: return fde_sub_058938(a0, a1, a2);
        case 0x058954ULL: return fde_sub_058954(a0, a1, a2);
        case 0x058970ULL: return fde_sub_058970(a0, a1, a2);
        case 0x05898cULL: return fde_sub_05898c(a0, a1, a2);
        case 0x058a28ULL: return fde_sub_058a28(a0, a1, a2);
        case 0x058a48ULL: return fde_sub_058a48(a0, a1, a2);
        case 0x058a50ULL: return fde_sub_058a50(a0, a1, a2);
        case 0x058b5cULL: return fde_sub_058b5c(a0, a1, a2);
        case 0x058be0ULL: return fde_sub_058be0(a0, a1, a2);
        case 0x058bf8ULL: return fde_sub_058bf8(a0, a1, a2);
        case 0x058c00ULL: return fde_sub_058c00(a0, a1, a2);
        case 0x058c08ULL: return fde_sub_058c08(a0, a1, a2);
        case 0x058d08ULL: return fde_sub_058d08(a0, a1, a2);
        case 0x058d10ULL: return fde_sub_058d10(a0, a1, a2);
        case 0x058dccULL: return fde_sub_058dcc(a0, a1, a2);
        case 0x058dd4ULL: return fde_sub_058dd4(a0, a1, a2);
        case 0x058ddcULL: return fde_sub_058ddc(a0, a1, a2);
        case 0x058de4ULL: return fde_sub_058de4(a0, a1, a2);
        case 0x058e20ULL: return fde_sub_058e20(a0, a1, a2);
        case 0x058e50ULL: return fde_sub_058e50(a0, a1, a2);
        case 0x058e94ULL: return fde_sub_058e94(a0, a1, a2);
        case 0x058e9cULL: return fde_sub_058e9c(a0, a1, a2);
        case 0x058edcULL: return fde_sub_058edc(a0, a1, a2);
        case 0x058f04ULL: return fde_sub_058f04(a0, a1, a2);
        case 0x058f4cULL: return fde_sub_058f4c(a0, a1, a2);
        case 0x059138ULL: return fde_sub_059138(a0, a1, a2);
        case 0x059190ULL: return fde_sub_059190(a0, a1, a2);
        case 0x059198ULL: return fde_sub_059198(a0, a1, a2);
        case 0x059588ULL: return fde_sub_059588(a0, a1, a2);
        case 0x0595a4ULL: return fde_sub_0595a4(a0, a1, a2);
        case 0x0595b4ULL: return fde_sub_0595b4(a0, a1, a2);
        case 0x0595ccULL: return fde_sub_0595cc(a0, a1, a2);
        case 0x0595d8ULL: return fde_sub_0595d8(a0, a1, a2);
        case 0x0596b0ULL: return fde_sub_0596b0(a0, a1, a2);
        case 0x0596bcULL: return fde_sub_0596bc(a0, a1, a2);
        case 0x0596ccULL: return fde_sub_0596cc(a0, a1, a2);
        case 0x0596e4ULL: return fde_sub_0596e4(a0, a1, a2);
        case 0x0596f4ULL: return fde_sub_0596f4(a0, a1, a2);
        case 0x059724ULL: return fde_sub_059724(a0, a1, a2);
        case 0x05973cULL: return fde_sub_05973c(a0, a1, a2);
        case 0x05974cULL: return fde_sub_05974c(a0, a1, a2);
        case 0x059764ULL: return fde_sub_059764(a0, a1, a2);
        case 0x059774ULL: return fde_sub_059774(a0, a1, a2);
        case 0x0597f8ULL: return fde_sub_0597f8(a0, a1, a2);
        case 0x0598b8ULL: return fde_sub_0598b8(a0, a1, a2);
        case 0x0599d4ULL: return fde_sub_0599d4(a0, a1, a2);
        case 0x059a30ULL: return fde_sub_059a30(a0, a1, a2);
        case 0x059a50ULL: return fde_sub_059a50(a0, a1, a2);
        case 0x059d10ULL: return fde_sub_059d10(a0, a1, a2);
        case 0x059d20ULL: return fde_sub_059d20(a0, a1, a2);
        case 0x059d30ULL: return fde_sub_059d30(a0, a1, a2);
        case 0x059d48ULL: return fde_sub_059d48(a0, a1, a2);
        case 0x059d54ULL: return fde_sub_059d54(a0, a1, a2);
        case 0x059f50ULL: return fde_sub_059f50(a0, a1, a2);
        case 0x059fd0ULL: return fde_sub_059fd0(a0, a1, a2);
        case 0x059fdcULL: return fde_sub_059fdc(a0, a1, a2);
        case 0x059ff4ULL: return fde_sub_059ff4(a0, a1, a2);
        case 0x05a004ULL: return fde_sub_05a004(a0, a1, a2);
        case 0x05a01cULL: return fde_sub_05a01c(a0, a1, a2);
        case 0x05a02cULL: return fde_sub_05a02c(a0, a1, a2);
        case 0x05a0f8ULL: return fde_sub_05a0f8(a0, a1, a2);
        case 0x05a108ULL: return fde_sub_05a108(a0, a1, a2);
        case 0x05a120ULL: return fde_sub_05a120(a0, a1, a2);
        case 0x05a1fcULL: return fde_sub_05a1fc(a0, a1, a2);
        case 0x05a294ULL: return fde_sub_05a294(a0, a1, a2);
        case 0x05a3c8ULL: return fde_sub_05a3c8(a0, a1, a2);
        case 0x05a3d8ULL: return fde_sub_05a3d8(a0, a1, a2);
        case 0x05a3e8ULL: return fde_sub_05a3e8(a0, a1, a2);
        case 0x05a400ULL: return fde_sub_05a400(a0, a1, a2);
        case 0x05a40cULL: return fde_sub_05a40c(a0, a1, a2);
        case 0x05a478ULL: return fde_sub_05a478(a0, a1, a2);
        case 0x05a4b0ULL: return fde_sub_05a4b0(a0, a1, a2);
        case 0x05a4e8ULL: return fde_sub_05a4e8(a0, a1, a2);
        case 0x05a520ULL: return fde_sub_05a520(a0, a1, a2);
        case 0x05a570ULL: return fde_sub_05a570(a0, a1, a2);
        case 0x05a60cULL: return fde_sub_05a60c(a0, a1, a2);
        case 0x05a61cULL: return fde_sub_05a61c(a0, a1, a2);
        case 0x05a634ULL: return fde_sub_05a634(a0, a1, a2);
        case 0x05a6d8ULL: return fde_sub_05a6d8(a0, a1, a2);
        case 0x05a6e8ULL: return fde_sub_05a6e8(a0, a1, a2);
        case 0x05a700ULL: return fde_sub_05a700(a0, a1, a2);
        case 0x05a75cULL: return fde_sub_05a75c(a0, a1, a2);
        case 0x05a784ULL: return fde_sub_05a784(a0, a1, a2);
        case 0x05a788ULL: return fde_sub_05a788(a0, a1, a2);
        case 0x05a88cULL: return fde_sub_05a88c(a0, a1, a2);
        case 0x05a93cULL: return fde_sub_05a93c(a0, a1, a2);
        case 0x05a9ccULL: return fde_sub_05a9cc(a0, a1, a2);
        case 0x05a9f0ULL: return fde_sub_05a9f0(a0, a1, a2);
        case 0x05aa2cULL: return fde_sub_05aa2c(a0, a1, a2);
        case 0x05aa44ULL: return fde_sub_05aa44(a0, a1, a2);
        case 0x05aa68ULL: return fde_sub_05aa68(a0, a1, a2);
        case 0x05ab10ULL: return fde_sub_05ab10(a0, a1, a2);
        case 0x05ab18ULL: return fde_sub_05ab18(a0, a1, a2);
        case 0x05acc4ULL: return fde_sub_05acc4(a0, a1, a2);
        case 0x05ad88ULL: return fde_sub_05ad88(a0, a1, a2);
        case 0x05ad90ULL: return fde_sub_05ad90(a0, a1, a2);
        case 0x05ae78ULL: return fde_sub_05ae78(a0, a1, a2);
        case 0x05af2cULL: return fde_sub_05af2c(a0, a1, a2);
        case 0x05afc0ULL: return fde_sub_05afc0(a0, a1, a2);
        case 0x05afc8ULL: return fde_sub_05afc8(a0, a1, a2);
        case 0x05afd0ULL: return fde_sub_05afd0(a0, a1, a2);
        case 0x05afdcULL: return fde_sub_05afdc(a0, a1, a2);
        case 0x05b030ULL: return fde_sub_05b030(a0, a1, a2);
        case 0x05b04cULL: return fde_sub_05b04c(a0, a1, a2);
        case 0x05b074ULL: return fde_sub_05b074(a0, a1, a2);
        case 0x05b0a0ULL: return fde_sub_05b0a0(a0, a1, a2);
        case 0x05b0f4ULL: return fde_sub_05b0f4(a0, a1, a2);
        case 0x05b104ULL: return fde_sub_05b104(a0, a1, a2);
        case 0x05b11cULL: return fde_sub_05b11c(a0, a1, a2);
        case 0x05b144ULL: return fde_sub_05b144(a0, a1, a2);
        case 0x05b154ULL: return fde_sub_05b154(a0, a1, a2);
        case 0x05b158ULL: return fde_sub_05b158(a0, a1, a2);
        case 0x05b184ULL: return fde_sub_05b184(a0, a1, a2);
        case 0x05b1c8ULL: return fde_sub_05b1c8(a0, a1, a2);
        case 0x05b1f4ULL: return fde_sub_05b1f4(a0, a1, a2);
        case 0x05b26cULL: return fde_sub_05b26c(a0, a1, a2);
        case 0x05b288ULL: return fde_sub_05b288(a0, a1, a2);
        case 0x05b2a0ULL: return fde_sub_05b2a0(a0, a1, a2);
        case 0x05b2c0ULL: return fde_sub_05b2c0(a0, a1, a2);
        case 0x05b2c8ULL: return fde_sub_05b2c8(a0, a1, a2);
        case 0x05b2d0ULL: return fde_sub_05b2d0(a0, a1, a2);
        case 0x05b2d8ULL: return fde_sub_05b2d8(a0, a1, a2);
        case 0x05b2ecULL: return fde_sub_05b2ec(a0, a1, a2);
        case 0x05b3a4ULL: return fde_sub_05b3a4(a0, a1, a2);
        case 0x05b3acULL: return fde_sub_05b3ac(a0, a1, a2);
        case 0x05b3d4ULL: return fde_sub_05b3d4(a0, a1, a2);
        case 0x05b3fcULL: return fde_sub_05b3fc(a0, a1, a2);
        case 0x05b4e8ULL: return fde_sub_05b4e8(a0, a1, a2);
        case 0x05b508ULL: return fde_sub_05b508(a0, a1, a2);
        case 0x05b520ULL: return fde_sub_05b520(a0, a1, a2);
        case 0x05b574ULL: return fde_sub_05b574(a0, a1, a2);
        case 0x05b6c8ULL: return fde_sub_05b6c8(a0, a1, a2);
        case 0x05b8bcULL: return fde_sub_05b8bc(a0, a1, a2);
        case 0x05b910ULL: return fde_sub_05b910(a0, a1, a2);
        case 0x05b928ULL: return fde_sub_05b928(a0, a1, a2);
        case 0x05b968ULL: return fde_sub_05b968(a0, a1, a2);
        case 0x05b9bcULL: return fde_sub_05b9bc(a0, a1, a2);
        case 0x05bcccULL: return fde_sub_05bccc(a0, a1, a2);
        case 0x05be2cULL: return fde_sub_05be2c(a0, a1, a2);
        case 0x05be50ULL: return fde_sub_05be50(a0, a1, a2);
        case 0x05bedcULL: return fde_sub_05bedc(a0, a1, a2);
        case 0x05bf4cULL: return fde_sub_05bf4c(a0, a1, a2);
        case 0x05bf64ULL: return fde_sub_05bf64(a0, a1, a2);
        case 0x05bfacULL: return fde_sub_05bfac(a0, a1, a2);
        case 0x05c0d0ULL: return fde_sub_05c0d0(a0, a1, a2);
        case 0x05c14cULL: return fde_sub_05c14c(a0, a1, a2);
        case 0x05c184ULL: return fde_sub_05c184(a0, a1, a2);
        case 0x05c204ULL: return fde_sub_05c204(a0, a1, a2);
        case 0x05c20cULL: return fde_sub_05c20c(a0, a1, a2);
        case 0x05c214ULL: return fde_sub_05c214(a0, a1, a2);
        case 0x05c21cULL: return fde_sub_05c21c(a0, a1, a2);
        case 0x05c224ULL: return fde_sub_05c224(a0, a1, a2);
        case 0x05c22cULL: return fde_sub_05c22c(a0, a1, a2);
        case 0x05c234ULL: return fde_sub_05c234(a0, a1, a2);
        case 0x05c240ULL: return fde_sub_05c240(a0, a1, a2);
        case 0x05c310ULL: return fde_sub_05c310(a0, a1, a2);
        case 0x05c338ULL: return fde_sub_05c338(a0, a1, a2);
        case 0x05c408ULL: return fde_sub_05c408(a0, a1, a2);
        case 0x05c430ULL: return fde_sub_05c430(a0, a1, a2);
        case 0x05c448ULL: return fde_sub_05c448(a0, a1, a2);
        case 0x05c46cULL: return fde_sub_05c46c(a0, a1, a2);
        case 0x05c4dcULL: return fde_sub_05c4dc(a0, a1, a2);
        case 0x05c4e4ULL: return fde_sub_05c4e4(a0, a1, a2);
        case 0x05c4ecULL: return fde_sub_05c4ec(a0, a1, a2);
        case 0x05c4f4ULL: return fde_sub_05c4f4(a0, a1, a2);
        case 0x05c4fcULL: return fde_sub_05c4fc(a0, a1, a2);
        case 0x05c5dcULL: return fde_sub_05c5dc(a0, a1, a2);
        case 0x05c5e4ULL: return fde_sub_05c5e4(a0, a1, a2);
        case 0x05c60cULL: return fde_sub_05c60c(a0, a1, a2);
        case 0x05c654ULL: return fde_sub_05c654(a0, a1, a2);
        case 0x05c66cULL: return fde_sub_05c66c(a0, a1, a2);
        case 0x05c6a4ULL: return fde_sub_05c6a4(a0, a1, a2);
        case 0x05c714ULL: return fde_sub_05c714(a0, a1, a2);
        case 0x05c7c4ULL: return fde_sub_05c7c4(a0, a1, a2);
        case 0x05c9dcULL: return fde_sub_05c9dc(a0, a1, a2);
        case 0x05c9f0ULL: return fde_sub_05c9f0(a0, a1, a2);
        case 0x05c9fcULL: return fde_sub_05c9fc(a0, a1, a2);
        case 0x05ca44ULL: return fde_sub_05ca44(a0, a1, a2);
        case 0x05cc44ULL: return fde_sub_05cc44(a0, a1, a2);
        case 0x05cd14ULL: return fde_sub_05cd14(a0, a1, a2);
        case 0x05cd4cULL: return fde_sub_05cd4c(a0, a1, a2);
        case 0x05cd64ULL: return fde_sub_05cd64(a0, a1, a2);
        case 0x05cd9cULL: return fde_sub_05cd9c(a0, a1, a2);
        case 0x05cda4ULL: return fde_sub_05cda4(a0, a1, a2);
        case 0x05cdd0ULL: return fde_sub_05cdd0(a0, a1, a2);
        case 0x05cdd8ULL: return fde_sub_05cdd8(a0, a1, a2);
        case 0x05cde0ULL: return fde_sub_05cde0(a0, a1, a2);
        case 0x05cde8ULL: return fde_sub_05cde8(a0, a1, a2);
        case 0x05ceecULL: return fde_sub_05ceec(a0, a1, a2);
        case 0x05cf08ULL: return fde_sub_05cf08(a0, a1, a2);
        case 0x05d258ULL: return fde_sub_05d258(a0, a1, a2);
        case 0x05d270ULL: return fde_sub_05d270(a0, a1, a2);
        case 0x05d2e4ULL: return fde_sub_05d2e4(a0, a1, a2);
        case 0x05d438ULL: return fde_sub_05d438(a0, a1, a2);
        case 0x05d970ULL: return fde_sub_05d970(a0, a1, a2);
        case 0x05da70ULL: return fde_sub_05da70(a0, a1, a2);
        case 0x05db0cULL: return fde_sub_05db0c(a0, a1, a2);
        case 0x05db14ULL: return fde_sub_05db14(a0, a1, a2);
        case 0x05db1cULL: return fde_sub_05db1c(a0, a1, a2);
        case 0x05db24ULL: return fde_sub_05db24(a0, a1, a2);
        case 0x05db2cULL: return fde_sub_05db2c(a0, a1, a2);
        case 0x05db34ULL: return fde_sub_05db34(a0, a1, a2);
        case 0x05db3cULL: return fde_sub_05db3c(a0, a1, a2);
        case 0x05db48ULL: return fde_sub_05db48(a0, a1, a2);
        case 0x05dbd8ULL: return fde_sub_05dbd8(a0, a1, a2);
        case 0x05dcb0ULL: return fde_sub_05dcb0(a0, a1, a2);
        case 0x05dce8ULL: return fde_sub_05dce8(a0, a1, a2);
        case 0x05dd00ULL: return fde_sub_05dd00(a0, a1, a2);
        case 0x05dd08ULL: return fde_sub_05dd08(a0, a1, a2);
        case 0x05dfb8ULL: return fde_sub_05dfb8(a0, a1, a2);
        case 0x05dfecULL: return fde_sub_05dfec(a0, a1, a2);
        case 0x05e01cULL: return fde_sub_05e01c(a0, a1, a2);
        case 0x05e04cULL: return fde_sub_05e04c(a0, a1, a2);
        case 0x05e054ULL: return fde_sub_05e054(a0, a1, a2);
        case 0x05e05cULL: return fde_sub_05e05c(a0, a1, a2);
        case 0x05e064ULL: return fde_sub_05e064(a0, a1, a2);
        case 0x05e06cULL: return fde_sub_05e06c(a0, a1, a2);
        case 0x05e074ULL: return fde_sub_05e074(a0, a1, a2);
        case 0x05e07cULL: return fde_sub_05e07c(a0, a1, a2);
        case 0x05e148ULL: return fde_sub_05e148(a0, a1, a2);
        case 0x05e2d4ULL: return fde_sub_05e2d4(a0, a1, a2);
        case 0x05e32cULL: return fde_sub_05e32c(a0, a1, a2);
        case 0x05e344ULL: return fde_sub_05e344(a0, a1, a2);
        case 0x05e3e8ULL: return fde_sub_05e3e8(a0, a1, a2);
        case 0x05e420ULL: return fde_sub_05e420(a0, a1, a2);
        case 0x05e468ULL: return fde_sub_05e468(a0, a1, a2);
        case 0x05e590ULL: return fde_sub_05e590(a0, a1, a2);
        case 0x05e60cULL: return fde_sub_05e60c(a0, a1, a2);
        case 0x05e614ULL: return fde_sub_05e614(a0, a1, a2);
        case 0x05e61cULL: return fde_sub_05e61c(a0, a1, a2);
        case 0x05e7a0ULL: return fde_sub_05e7a0(a0, a1, a2);
        case 0x05e7e0ULL: return fde_sub_05e7e0(a0, a1, a2);
        case 0x05e7f8ULL: return fde_sub_05e7f8(a0, a1, a2);
        case 0x05e800ULL: return fde_sub_05e800(a0, a1, a2);
        case 0x05e874ULL: return fde_sub_05e874(a0, a1, a2);
        case 0x05ef18ULL: return fde_sub_05ef18(a0, a1, a2);
        case 0x05ef4cULL: return fde_sub_05ef4c(a0, a1, a2);
        case 0x05efd0ULL: return fde_sub_05efd0(a0, a1, a2);
        case 0x05efd8ULL: return fde_sub_05efd8(a0, a1, a2);
        case 0x05efe0ULL: return fde_sub_05efe0(a0, a1, a2);
        case 0x05efe8ULL: return fde_sub_05efe8(a0, a1, a2);
        case 0x05eff0ULL: return fde_sub_05eff0(a0, a1, a2);
        case 0x05eff8ULL: return fde_sub_05eff8(a0, a1, a2);
        case 0x05f000ULL: return fde_sub_05f000(a0, a1, a2);
        case 0x05f0fcULL: return fde_sub_05f0fc(a0, a1, a2);
        case 0x05f13cULL: return fde_sub_05f13c(a0, a1, a2);
        case 0x05f154ULL: return fde_sub_05f154(a0, a1, a2);
        case 0x05f15cULL: return fde_sub_05f15c(a0, a1, a2);
        case 0x05f198ULL: return fde_sub_05f198(a0, a1, a2);
        case 0x05f490ULL: return fde_sub_05f490(a0, a1, a2);
        case 0x05f4ecULL: return fde_sub_05f4ec(a0, a1, a2);
        case 0x05f534ULL: return fde_sub_05f534(a0, a1, a2);
        case 0x05f53cULL: return fde_sub_05f53c(a0, a1, a2);
        case 0x05f544ULL: return fde_sub_05f544(a0, a1, a2);
        case 0x05f54cULL: return fde_sub_05f54c(a0, a1, a2);
        case 0x05f554ULL: return fde_sub_05f554(a0, a1, a2);
        case 0x05f55cULL: return fde_sub_05f55c(a0, a1, a2);
        case 0x05f564ULL: return fde_sub_05f564(a0, a1, a2);
        case 0x05f654ULL: return fde_sub_05f654(a0, a1, a2);
        case 0x05f6a8ULL: return fde_sub_05f6a8(a0, a1, a2);
        case 0x05f6c0ULL: return fde_sub_05f6c0(a0, a1, a2);
        case 0x05f828ULL: return fde_sub_05f828(a0, a1, a2);
        case 0x05f838ULL: return fde_sub_05f838(a0, a1, a2);
        case 0x05f848ULL: return fde_sub_05f848(a0, a1, a2);
        case 0x05f884ULL: return fde_sub_05f884(a0, a1, a2);
        case 0x05f944ULL: return fde_sub_05f944(a0, a1, a2);
        case 0x05fa60ULL: return fde_sub_05fa60(a0, a1, a2);
        case 0x05faa0ULL: return fde_sub_05faa0(a0, a1, a2);
        case 0x05fb08ULL: return fde_sub_05fb08(a0, a1, a2);
        case 0x05fb10ULL: return fde_sub_05fb10(a0, a1, a2);
        case 0x05fb18ULL: return fde_sub_05fb18(a0, a1, a2);
        case 0x05fb20ULL: return fde_sub_05fb20(a0, a1, a2);
        case 0x05fb28ULL: return fde_sub_05fb28(a0, a1, a2);
        case 0x05fb38ULL: return fde_sub_05fb38(a0, a1, a2);
        case 0x05fb40ULL: return fde_sub_05fb40(a0, a1, a2);
        case 0x05fb48ULL: return fde_sub_05fb48(a0, a1, a2);
        case 0x05fb58ULL: return fde_sub_05fb58(a0, a1, a2);
        case 0x05fb60ULL: return fde_sub_05fb60(a0, a1, a2);
        case 0x05fb68ULL: return fde_sub_05fb68(a0, a1, a2);
        case 0x05fbfcULL: return fde_sub_05fbfc(a0, a1, a2);
        case 0x05fc34ULL: return fde_sub_05fc34(a0, a1, a2);
        case 0x05fc4cULL: return fde_sub_05fc4c(a0, a1, a2);
        case 0x05fc64ULL: return fde_sub_05fc64(a0, a1, a2);
        case 0x05fc6cULL: return fde_sub_05fc6c(a0, a1, a2);
        case 0x0603a0ULL: return fde_sub_0603a0(a0, a1, a2);
        case 0x0603a8ULL: return fde_sub_0603a8(a0, a1, a2);
        case 0x0603b0ULL: return fde_sub_0603b0(a0, a1, a2);
        case 0x0603ecULL: return fde_sub_0603ec(a0, a1, a2);
        case 0x060468ULL: return fde_sub_060468(a0, a1, a2);
        case 0x060490ULL: return fde_sub_060490(a0, a1, a2);
        case 0x060518ULL: return fde_sub_060518(a0, a1, a2);
        case 0x06053cULL: return fde_sub_06053c(a0, a1, a2);
        case 0x06058cULL: return fde_sub_06058c(a0, a1, a2);
        case 0x0605bcULL: return fde_sub_0605bc(a0, a1, a2);
        case 0x060618ULL: return fde_sub_060618(a0, a1, a2);
        case 0x060664ULL: return fde_sub_060664(a0, a1, a2);
        case 0x06068cULL: return fde_sub_06068c(a0, a1, a2);
        case 0x060730ULL: return fde_sub_060730(a0, a1, a2);
        case 0x060768ULL: return fde_sub_060768(a0, a1, a2);
        case 0x060780ULL: return fde_sub_060780(a0, a1, a2);
        case 0x060964ULL: return fde_sub_060964(a0, a1, a2);
        case 0x06097cULL: return fde_sub_06097c(a0, a1, a2);
        case 0x060a1cULL: return fde_sub_060a1c(a0, a1, a2);
        case 0x060a24ULL: return fde_sub_060a24(a0, a1, a2);
        case 0x060a2cULL: return fde_sub_060a2c(a0, a1, a2);
        case 0x060a34ULL: return fde_sub_060a34(a0, a1, a2);
        case 0x060a3cULL: return fde_sub_060a3c(a0, a1, a2);
        case 0x060a64ULL: return fde_sub_060a64(a0, a1, a2);
        case 0x060a8cULL: return fde_sub_060a8c(a0, a1, a2);
        case 0x060b54ULL: return fde_sub_060b54(a0, a1, a2);
        case 0x060b90ULL: return fde_sub_060b90(a0, a1, a2);
        case 0x060ba8ULL: return fde_sub_060ba8(a0, a1, a2);
        case 0x060bd0ULL: return fde_sub_060bd0(a0, a1, a2);
        case 0x060c50ULL: return fde_sub_060c50(a0, a1, a2);
        case 0x060c90ULL: return fde_sub_060c90(a0, a1, a2);
        case 0x060c98ULL: return fde_sub_060c98(a0, a1, a2);
        case 0x060ca0ULL: return fde_sub_060ca0(a0, a1, a2);
        case 0x060ca8ULL: return fde_sub_060ca8(a0, a1, a2);
        case 0x060cb0ULL: return fde_sub_060cb0(a0, a1, a2);
        case 0x060cb8ULL: return fde_sub_060cb8(a0, a1, a2);
        case 0x060de8ULL: return fde_sub_060de8(a0, a1, a2);
        case 0x060f74ULL: return fde_sub_060f74(a0, a1, a2);
        case 0x060fa8ULL: return fde_sub_060fa8(a0, a1, a2);
        case 0x060ffcULL: return fde_sub_060ffc(a0, a1, a2);
        case 0x061014ULL: return fde_sub_061014(a0, a1, a2);
        case 0x061020ULL: return fde_sub_061020(a0, a1, a2);
        case 0x061034ULL: return fde_sub_061034(a0, a1, a2);
        case 0x061064ULL: return fde_sub_061064(a0, a1, a2);
        case 0x0612a0ULL: return fde_sub_0612a0(a0, a1, a2);
        case 0x0612a8ULL: return fde_sub_0612a8(a0, a1, a2);
        case 0x06134cULL: return fde_sub_06134c(a0, a1, a2);
        case 0x06135cULL: return fde_sub_06135c(a0, a1, a2);
        case 0x061364ULL: return fde_sub_061364(a0, a1, a2);
        case 0x06136cULL: return fde_sub_06136c(a0, a1, a2);
        case 0x061374ULL: return fde_sub_061374(a0, a1, a2);
        case 0x06137cULL: return fde_sub_06137c(a0, a1, a2);
        case 0x061384ULL: return fde_sub_061384(a0, a1, a2);
        case 0x06138cULL: return fde_sub_06138c(a0, a1, a2);
        case 0x061394ULL: return fde_sub_061394(a0, a1, a2);
        case 0x0613a4ULL: return fde_sub_0613a4(a0, a1, a2);
        case 0x0613bcULL: return fde_sub_0613bc(a0, a1, a2);
        case 0x0617f4ULL: return fde_sub_0617f4(a0, a1, a2);
        case 0x06186cULL: return fde_sub_06186c(a0, a1, a2);
        case 0x06187cULL: return fde_sub_06187c(a0, a1, a2);
        case 0x061940ULL: return fde_sub_061940(a0, a1, a2);
        case 0x061994ULL: return fde_sub_061994(a0, a1, a2);
        case 0x061998ULL: return fde_sub_061998(a0, a1, a2);
        case 0x061a78ULL: return fde_sub_061a78(a0, a1, a2);
        case 0x061a80ULL: return fde_sub_061a80(a0, a1, a2);
        case 0x061aa0ULL: return fde_sub_061aa0(a0, a1, a2);
        case 0x061ab8ULL: return fde_sub_061ab8(a0, a1, a2);
        case 0x061b2cULL: return fde_sub_061b2c(a0, a1, a2);
        case 0x061c50ULL: return fde_sub_061c50(a0, a1, a2);
        case 0x061cccULL: return fde_sub_061ccc(a0, a1, a2);
        case 0x061cf0ULL: return fde_sub_061cf0(a0, a1, a2);
        case 0x061dc4ULL: return fde_sub_061dc4(a0, a1, a2);
        case 0x062184ULL: return fde_sub_062184(a0, a1, a2);
        case 0x0627f0ULL: return fde_sub_0627f0(a0, a1, a2);
        case 0x062890ULL: return fde_sub_062890(a0, a1, a2);
        case 0x0629b8ULL: return fde_sub_0629b8(a0, a1, a2);
        case 0x062a54ULL: return fde_sub_062a54(a0, a1, a2);
        case 0x062a5cULL: return fde_sub_062a5c(a0, a1, a2);
        case 0x062a64ULL: return fde_sub_062a64(a0, a1, a2);
        case 0x062b54ULL: return fde_sub_062b54(a0, a1, a2);
        case 0x062b8cULL: return fde_sub_062b8c(a0, a1, a2);
        case 0x062c5cULL: return fde_sub_062c5c(a0, a1, a2);
        case 0x062cb0ULL: return fde_sub_062cb0(a0, a1, a2);
        case 0x062cccULL: return fde_sub_062ccc(a0, a1, a2);
        case 0x062ce8ULL: return fde_sub_062ce8(a0, a1, a2);
        case 0x062d58ULL: return fde_sub_062d58(a0, a1, a2);
        case 0x062dd8ULL: return fde_sub_062dd8(a0, a1, a2);
        case 0x062dfcULL: return fde_sub_062dfc(a0, a1, a2);
        case 0x062e14ULL: return fde_sub_062e14(a0, a1, a2);
        case 0x062e38ULL: return fde_sub_062e38(a0, a1, a2);
        case 0x062e40ULL: return fde_sub_062e40(a0, a1, a2);
        case 0x062e48ULL: return fde_sub_062e48(a0, a1, a2);
        case 0x062e50ULL: return fde_sub_062e50(a0, a1, a2);
        case 0x062e58ULL: return fde_sub_062e58(a0, a1, a2);
        case 0x063064ULL: return fde_sub_063064(a0, a1, a2);
        case 0x0630d0ULL: return fde_sub_0630d0(a0, a1, a2);
        case 0x063134ULL: return fde_sub_063134(a0, a1, a2);
        case 0x06314cULL: return fde_sub_06314c(a0, a1, a2);
        case 0x0637c0ULL: return fde_sub_0637c0(a0, a1, a2);
        case 0x063818ULL: return fde_sub_063818(a0, a1, a2);
        case 0x063944ULL: return fde_sub_063944(a0, a1, a2);
        case 0x0639e8ULL: return fde_sub_0639e8(a0, a1, a2);
        case 0x063a18ULL: return fde_sub_063a18(a0, a1, a2);
        case 0x063a5cULL: return fde_sub_063a5c(a0, a1, a2);
        case 0x063a70ULL: return fde_sub_063a70(a0, a1, a2);
        case 0x063a78ULL: return fde_sub_063a78(a0, a1, a2);
        case 0x063a80ULL: return fde_sub_063a80(a0, a1, a2);
        case 0x063a88ULL: return fde_sub_063a88(a0, a1, a2);
        case 0x063a90ULL: return fde_sub_063a90(a0, a1, a2);
        case 0x063a98ULL: return fde_sub_063a98(a0, a1, a2);
        case 0x063aa0ULL: return fde_sub_063aa0(a0, a1, a2);
        case 0x063ab4ULL: return fde_sub_063ab4(a0, a1, a2);
        case 0x063c9cULL: return fde_sub_063c9c(a0, a1, a2);
        case 0x063cb4ULL: return fde_sub_063cb4(a0, a1, a2);
        case 0x063d04ULL: return fde_sub_063d04(a0, a1, a2);
        case 0x063d7cULL: return fde_sub_063d7c(a0, a1, a2);
        case 0x063e10ULL: return fde_sub_063e10(a0, a1, a2);
        case 0x063eb0ULL: return fde_sub_063eb0(a0, a1, a2);
        case 0x064068ULL: return fde_sub_064068(a0, a1, a2);
        case 0x064070ULL: return fde_sub_064070(a0, a1, a2);
        case 0x064128ULL: return fde_sub_064128(a0, a1, a2);
        case 0x064164ULL: return fde_sub_064164(a0, a1, a2);
        case 0x06417cULL: return fde_sub_06417c(a0, a1, a2);
        case 0x064194ULL: return fde_sub_064194(a0, a1, a2);
        case 0x0641dcULL: return fde_sub_0641dc(a0, a1, a2);
        case 0x06420cULL: return fde_sub_06420c(a0, a1, a2);
        case 0x0644d4ULL: return fde_sub_0644d4(a0, a1, a2);
        case 0x0644dcULL: return fde_sub_0644dc(a0, a1, a2);
        case 0x0644e4ULL: return fde_sub_0644e4(a0, a1, a2);
        case 0x0644ecULL: return fde_sub_0644ec(a0, a1, a2);
        case 0x0644f4ULL: return fde_sub_0644f4(a0, a1, a2);
        case 0x064684ULL: return fde_sub_064684(a0, a1, a2);
        case 0x06469cULL: return fde_sub_06469c(a0, a1, a2);
        case 0x0646b8ULL: return fde_sub_0646b8(a0, a1, a2);
        case 0x0646c0ULL: return fde_sub_0646c0(a0, a1, a2);
        case 0x0646c8ULL: return fde_sub_0646c8(a0, a1, a2);
        case 0x0646e4ULL: return fde_sub_0646e4(a0, a1, a2);
        case 0x06470cULL: return fde_sub_06470c(a0, a1, a2);
        case 0x06473cULL: return fde_sub_06473c(a0, a1, a2);
        case 0x064754ULL: return fde_sub_064754(a0, a1, a2);
        case 0x064784ULL: return fde_sub_064784(a0, a1, a2);
        case 0x06479cULL: return fde_sub_06479c(a0, a1, a2);
        case 0x0648d0ULL: return fde_sub_0648d0(a0, a1, a2);
        case 0x064918ULL: return fde_sub_064918(a0, a1, a2);
        case 0x0649c0ULL: return fde_sub_0649c0(a0, a1, a2);
        case 0x0649d8ULL: return fde_sub_0649d8(a0, a1, a2);
        case 0x0649e0ULL: return fde_sub_0649e0(a0, a1, a2);
        case 0x0649e8ULL: return fde_sub_0649e8(a0, a1, a2);
        case 0x0649f0ULL: return fde_sub_0649f0(a0, a1, a2);
        case 0x0649f8ULL: return fde_sub_0649f8(a0, a1, a2);
        case 0x064a1cULL: return fde_sub_064a1c(a0, a1, a2);
        case 0x064ab0ULL: return fde_sub_064ab0(a0, a1, a2);
        case 0x064ac0ULL: return fde_sub_064ac0(a0, a1, a2);
        case 0x064af4ULL: return fde_sub_064af4(a0, a1, a2);
        case 0x064b30ULL: return fde_sub_064b30(a0, a1, a2);
        case 0x064b48ULL: return fde_sub_064b48(a0, a1, a2);
        case 0x064b60ULL: return fde_sub_064b60(a0, a1, a2);
        case 0x064bc4ULL: return fde_sub_064bc4(a0, a1, a2);
        case 0x064c1cULL: return fde_sub_064c1c(a0, a1, a2);
        case 0x064db8ULL: return fde_sub_064db8(a0, a1, a2);
        case 0x064dc0ULL: return fde_sub_064dc0(a0, a1, a2);
        case 0x064dc8ULL: return fde_sub_064dc8(a0, a1, a2);
        case 0x064dd0ULL: return fde_sub_064dd0(a0, a1, a2);
        case 0x064dd8ULL: return fde_sub_064dd8(a0, a1, a2);
        case 0x064de0ULL: return fde_sub_064de0(a0, a1, a2);
        case 0x064decULL: return fde_sub_064dec(a0, a1, a2);
        case 0x064df4ULL: return fde_sub_064df4(a0, a1, a2);
        case 0x064e30ULL: return fde_sub_064e30(a0, a1, a2);
        case 0x064e7cULL: return fde_sub_064e7c(a0, a1, a2);
        case 0x064eb8ULL: return fde_sub_064eb8(a0, a1, a2);
        case 0x064ef4ULL: return fde_sub_064ef4(a0, a1, a2);
        case 0x064f74ULL: return fde_sub_064f74(a0, a1, a2);
        case 0x064fd0ULL: return fde_sub_064fd0(a0, a1, a2);
        case 0x065048ULL: return fde_sub_065048(a0, a1, a2);
        case 0x065154ULL: return fde_sub_065154(a0, a1, a2);
        case 0x0651b0ULL: return fde_sub_0651b0(a0, a1, a2);
        case 0x065244ULL: return fde_sub_065244(a0, a1, a2);
        case 0x06525cULL: return fde_sub_06525c(a0, a1, a2);
        case 0x065a08ULL: return fde_sub_065a08(a0, a1, a2);
        case 0x065aa8ULL: return fde_sub_065aa8(a0, a1, a2);
        case 0x065be8ULL: return fde_sub_065be8(a0, a1, a2);
        case 0x065cecULL: return fde_sub_065cec(a0, a1, a2);
        case 0x065d40ULL: return fde_sub_065d40(a0, a1, a2);
        case 0x065d60ULL: return fde_sub_065d60(a0, a1, a2);
        case 0x065d78ULL: return fde_sub_065d78(a0, a1, a2);
        case 0x065da0ULL: return fde_sub_065da0(a0, a1, a2);
        case 0x065e00ULL: return fde_sub_065e00(a0, a1, a2);
        case 0x065e6cULL: return fde_sub_065e6c(a0, a1, a2);
        case 0x065ed8ULL: return fde_sub_065ed8(a0, a1, a2);
        case 0x065f18ULL: return fde_sub_065f18(a0, a1, a2);
        case 0x065f6cULL: return fde_sub_065f6c(a0, a1, a2);
        case 0x065f84ULL: return fde_sub_065f84(a0, a1, a2);
        case 0x065f8cULL: return fde_sub_065f8c(a0, a1, a2);
        case 0x065f9cULL: return fde_sub_065f9c(a0, a1, a2);
        case 0x0661bcULL: return fde_sub_0661bc(a0, a1, a2);
        case 0x0661f0ULL: return fde_sub_0661f0(a0, a1, a2);
        case 0x066240ULL: return fde_sub_066240(a0, a1, a2);
        case 0x06627cULL: return fde_sub_06627c(a0, a1, a2);
        case 0x0662bcULL: return fde_sub_0662bc(a0, a1, a2);
        case 0x066308ULL: return fde_sub_066308(a0, a1, a2);
        case 0x066344ULL: return fde_sub_066344(a0, a1, a2);
        case 0x0663c8ULL: return fde_sub_0663c8(a0, a1, a2);
        case 0x0663e0ULL: return fde_sub_0663e0(a0, a1, a2);
        case 0x0665bcULL: return fde_sub_0665bc(a0, a1, a2);
        case 0x0666f4ULL: return fde_sub_0666f4(a0, a1, a2);
        case 0x066720ULL: return fde_sub_066720(a0, a1, a2);
        case 0x066778ULL: return fde_sub_066778(a0, a1, a2);
        case 0x066780ULL: return fde_sub_066780(a0, a1, a2);
        case 0x066788ULL: return fde_sub_066788(a0, a1, a2);
        case 0x066790ULL: return fde_sub_066790(a0, a1, a2);
        case 0x066798ULL: return fde_sub_066798(a0, a1, a2);
        case 0x0667a0ULL: return fde_sub_0667a0(a0, a1, a2);
        case 0x0668ccULL: return fde_sub_0668cc(a0, a1, a2);
        case 0x0668e4ULL: return fde_sub_0668e4(a0, a1, a2);
        case 0x0669f4ULL: return fde_sub_0669f4(a0, a1, a2);
        case 0x066a90ULL: return fde_sub_066a90(a0, a1, a2);
        case 0x066aa8ULL: return fde_sub_066aa8(a0, a1, a2);
        case 0x066ab0ULL: return fde_sub_066ab0(a0, a1, a2);
        case 0x066e64ULL: return fde_sub_066e64(a0, a1, a2);
        case 0x066e90ULL: return fde_sub_066e90(a0, a1, a2);
        case 0x066ea0ULL: return fde_sub_066ea0(a0, a1, a2);
        case 0x066eb0ULL: return fde_sub_066eb0(a0, a1, a2);
        case 0x066eecULL: return fde_sub_066eec(a0, a1, a2);
        case 0x066f2cULL: return fde_sub_066f2c(a0, a1, a2);
        case 0x066f6cULL: return fde_sub_066f6c(a0, a1, a2);
        case 0x066facULL: return fde_sub_066fac(a0, a1, a2);
        case 0x06705cULL: return fde_sub_06705c(a0, a1, a2);
        case 0x067090ULL: return fde_sub_067090(a0, a1, a2);
        case 0x067138ULL: return fde_sub_067138(a0, a1, a2);
        case 0x0671e4ULL: return fde_sub_0671e4(a0, a1, a2);
        case 0x067224ULL: return fde_sub_067224(a0, a1, a2);
        case 0x067258ULL: return fde_sub_067258(a0, a1, a2);
        case 0x067270ULL: return fde_sub_067270(a0, a1, a2);
        case 0x067278ULL: return fde_sub_067278(a0, a1, a2);
        case 0x067384ULL: return fde_sub_067384(a0, a1, a2);
        case 0x06738cULL: return fde_sub_06738c(a0, a1, a2);
        case 0x0673c0ULL: return fde_sub_0673c0(a0, a1, a2);
        case 0x0673e4ULL: return fde_sub_0673e4(a0, a1, a2);
        case 0x067404ULL: return fde_sub_067404(a0, a1, a2);
        case 0x067440ULL: return fde_sub_067440(a0, a1, a2);
        case 0x06749cULL: return fde_sub_06749c(a0, a1, a2);
        case 0x0674b4ULL: return fde_sub_0674b4(a0, a1, a2);
        case 0x0674f0ULL: return fde_sub_0674f0(a0, a1, a2);
        case 0x067510ULL: return fde_sub_067510(a0, a1, a2);
        case 0x06753cULL: return fde_sub_06753c(a0, a1, a2);
        case 0x067558ULL: return fde_sub_067558(a0, a1, a2);
        case 0x067598ULL: return fde_sub_067598(a0, a1, a2);
        case 0x0675b4ULL: return fde_sub_0675b4(a0, a1, a2);
        case 0x0675f8ULL: return fde_sub_0675f8(a0, a1, a2);
        case 0x067688ULL: return fde_sub_067688(a0, a1, a2);
        case 0x0676c8ULL: return fde_sub_0676c8(a0, a1, a2);
        case 0x067724ULL: return fde_sub_067724(a0, a1, a2);
        case 0x0678d0ULL: return fde_sub_0678d0(a0, a1, a2);
        case 0x067924ULL: return fde_sub_067924(a0, a1, a2);
        case 0x06794cULL: return fde_sub_06794c(a0, a1, a2);
        case 0x067990ULL: return fde_sub_067990(a0, a1, a2);
        case 0x0679a8ULL: return fde_sub_0679a8(a0, a1, a2);
        case 0x067a2cULL: return fde_sub_067a2c(a0, a1, a2);
        case 0x067bdcULL: return fde_sub_067bdc(a0, a1, a2);
        case 0x067c50ULL: return fde_sub_067c50(a0, a1, a2);
        case 0x067cc8ULL: return fde_sub_067cc8(a0, a1, a2);
        case 0x067d0cULL: return fde_sub_067d0c(a0, a1, a2);
        case 0x067d38ULL: return fde_sub_067d38(a0, a1, a2);
        case 0x067d64ULL: return fde_sub_067d64(a0, a1, a2);
        case 0x067d90ULL: return fde_sub_067d90(a0, a1, a2);
        case 0x067dbcULL: return fde_sub_067dbc(a0, a1, a2);
        case 0x067de8ULL: return fde_sub_067de8(a0, a1, a2);
        case 0x067e14ULL: return fde_sub_067e14(a0, a1, a2);
        case 0x067e40ULL: return fde_sub_067e40(a0, a1, a2);
        case 0x067e6cULL: return fde_sub_067e6c(a0, a1, a2);
        case 0x067ea4ULL: return fde_sub_067ea4(a0, a1, a2);
        case 0x067ebcULL: return fde_sub_067ebc(a0, a1, a2);
        case 0x067f14ULL: return fde_sub_067f14(a0, a1, a2);
        case 0x067f2cULL: return fde_sub_067f2c(a0, a1, a2);
        case 0x067f6cULL: return fde_sub_067f6c(a0, a1, a2);
        case 0x067f84ULL: return fde_sub_067f84(a0, a1, a2);
        case 0x067fbcULL: return fde_sub_067fbc(a0, a1, a2);
        case 0x067fd4ULL: return fde_sub_067fd4(a0, a1, a2);
        case 0x067ff8ULL: return fde_sub_067ff8(a0, a1, a2);
        case 0x068010ULL: return fde_sub_068010(a0, a1, a2);
        case 0x068048ULL: return fde_sub_068048(a0, a1, a2);
        case 0x068060ULL: return fde_sub_068060(a0, a1, a2);
        case 0x068094ULL: return fde_sub_068094(a0, a1, a2);
        case 0x0680acULL: return fde_sub_0680ac(a0, a1, a2);
        case 0x0680d0ULL: return fde_sub_0680d0(a0, a1, a2);
        case 0x0680e8ULL: return fde_sub_0680e8(a0, a1, a2);
        case 0x06812cULL: return fde_sub_06812c(a0, a1, a2);
        case 0x068174ULL: return fde_sub_068174(a0, a1, a2);
        case 0x06818cULL: return fde_sub_06818c(a0, a1, a2);
        case 0x068194ULL: return fde_sub_068194(a0, a1, a2);
        case 0x06819cULL: return fde_sub_06819c(a0, a1, a2);
        case 0x0681f8ULL: return fde_sub_0681f8(a0, a1, a2);
        case 0x068264ULL: return fde_sub_068264(a0, a1, a2);
        case 0x0682a0ULL: return fde_sub_0682a0(a0, a1, a2);
        case 0x0682c4ULL: return fde_sub_0682c4(a0, a1, a2);
        case 0x06834cULL: return fde_sub_06834c(a0, a1, a2);
        case 0x06836cULL: return fde_sub_06836c(a0, a1, a2);
        case 0x0683d8ULL: return fde_sub_0683d8(a0, a1, a2);
        case 0x06840cULL: return fde_sub_06840c(a0, a1, a2);
        case 0x068420ULL: return fde_sub_068420(a0, a1, a2);
        case 0x068454ULL: return fde_sub_068454(a0, a1, a2);
        case 0x0684a0ULL: return fde_sub_0684a0(a0, a1, a2);
        case 0x0684e8ULL: return fde_sub_0684e8(a0, a1, a2);
        case 0x068500ULL: return fde_sub_068500(a0, a1, a2);
        case 0x068508ULL: return fde_sub_068508(a0, a1, a2);
        case 0x0685e8ULL: return fde_sub_0685e8(a0, a1, a2);
        case 0x068638ULL: return fde_sub_068638(a0, a1, a2);
        case 0x068720ULL: return fde_sub_068720(a0, a1, a2);
        case 0x068738ULL: return fde_sub_068738(a0, a1, a2);
        case 0x068740ULL: return fde_sub_068740(a0, a1, a2);
        case 0x068750ULL: return fde_sub_068750(a0, a1, a2);
        case 0x0687d0ULL: return fde_sub_0687d0(a0, a1, a2);
        case 0x068860ULL: return fde_sub_068860(a0, a1, a2);
        case 0x068888ULL: return fde_sub_068888(a0, a1, a2);
        case 0x0688a0ULL: return fde_sub_0688a0(a0, a1, a2);
        case 0x0688a8ULL: return fde_sub_0688a8(a0, a1, a2);
        case 0x068968ULL: return fde_sub_068968(a0, a1, a2);
        case 0x0689b8ULL: return fde_sub_0689b8(a0, a1, a2);
        case 0x0690b4ULL: return fde_sub_0690b4(a0, a1, a2);
        case 0x0690fcULL: return fde_sub_0690fc(a0, a1, a2);
        case 0x0692bcULL: return fde_sub_0692bc(a0, a1, a2);
        case 0x0692dcULL: return fde_sub_0692dc(a0, a1, a2);
        case 0x069354ULL: return fde_sub_069354(a0, a1, a2);
        case 0x0693a8ULL: return fde_sub_0693a8(a0, a1, a2);
        case 0x0693dcULL: return fde_sub_0693dc(a0, a1, a2);
        case 0x06942cULL: return fde_sub_06942c(a0, a1, a2);
        case 0x069448ULL: return fde_sub_069448(a0, a1, a2);
        case 0x0694c0ULL: return fde_sub_0694c0(a0, a1, a2);
        case 0x0694fcULL: return fde_sub_0694fc(a0, a1, a2);
        case 0x06972cULL: return fde_sub_06972c(a0, a1, a2);
        case 0x0697c0ULL: return fde_sub_0697c0(a0, a1, a2);
        case 0x069824ULL: return fde_sub_069824(a0, a1, a2);
        case 0x069848ULL: return fde_sub_069848(a0, a1, a2);
        case 0x0699d4ULL: return fde_sub_0699d4(a0, a1, a2);
        case 0x0699dcULL: return fde_sub_0699dc(a0, a1, a2);
        case 0x0699e4ULL: return fde_sub_0699e4(a0, a1, a2);
        case 0x069a2cULL: return fde_sub_069a2c(a0, a1, a2);
        case 0x069a74ULL: return fde_sub_069a74(a0, a1, a2);
        case 0x06a660ULL: return fde_sub_06a660(a0, a1, a2);
        case 0x06aa40ULL: return fde_sub_06aa40(a0, a1, a2);
        case 0x06aa90ULL: return fde_sub_06aa90(a0, a1, a2);
        case 0x06aad0ULL: return fde_sub_06aad0(a0, a1, a2);
        case 0x06ab64ULL: return fde_sub_06ab64(a0, a1, a2);
        case 0x06abb4ULL: return fde_sub_06abb4(a0, a1, a2);
        case 0x06ac44ULL: return fde_sub_06ac44(a0, a1, a2);
        case 0x06acf4ULL: return fde_sub_06acf4(a0, a1, a2);
        case 0x06ad44ULL: return fde_sub_06ad44(a0, a1, a2);
        case 0x06af38ULL: return fde_sub_06af38(a0, a1, a2);
        case 0x06af58ULL: return fde_sub_06af58(a0, a1, a2);
        case 0x06af68ULL: return fde_sub_06af68(a0, a1, a2);
        case 0x06b170ULL: return fde_sub_06b170(a0, a1, a2);
        case 0x06b8fcULL: return fde_sub_06b8fc(a0, a1, a2);
        case 0x06b984ULL: return fde_sub_06b984(a0, a1, a2);
        case 0x06b98cULL: return fde_sub_06b98c(a0, a1, a2);
        case 0x06b9f8ULL: return fde_sub_06b9f8(a0, a1, a2);
        case 0x06ba44ULL: return fde_sub_06ba44(a0, a1, a2);
        case 0x06ba4cULL: return fde_sub_06ba4c(a0, a1, a2);
        case 0x06bab4ULL: return fde_sub_06bab4(a0, a1, a2);
        case 0x06baf0ULL: return fde_sub_06baf0(a0, a1, a2);
        case 0x06bb10ULL: return fde_sub_06bb10(a0, a1, a2);
        case 0x06bb50ULL: return fde_sub_06bb50(a0, a1, a2);
        case 0x06bb94ULL: return fde_sub_06bb94(a0, a1, a2);
        case 0x06bbd8ULL: return fde_sub_06bbd8(a0, a1, a2);
        case 0x06d070ULL: return fde_sub_06d070(a0, a1, a2);
        case 0x06d0bcULL: return fde_sub_06d0bc(a0, a1, a2);
        case 0x06d0e0ULL: return fde_sub_06d0e0(a0, a1, a2);
        case 0x06d100ULL: return fde_sub_06d100(a0, a1, a2);
        case 0x06d120ULL: return fde_sub_06d120(a0, a1, a2);
        case 0x06d130ULL: return fde_sub_06d130(a0, a1, a2);
        case 0x06f204ULL: return fde_sub_06f204(a0, a1, a2);
        case 0x06f23cULL: return fde_sub_06f23c(a0, a1, a2);
        case 0x06f254ULL: return fde_sub_06f254(a0, a1, a2);
        case 0x06f280ULL: return fde_sub_06f280(a0, a1, a2);
        case 0x06f2ecULL: return fde_sub_06f2ec(a0, a1, a2);
        case 0x06f420ULL: return fde_sub_06f420(a0, a1, a2);
        case 0x06f468ULL: return fde_sub_06f468(a0, a1, a2);
        case 0x06f480ULL: return fde_sub_06f480(a0, a1, a2);
        case 0x06f4acULL: return fde_sub_06f4ac(a0, a1, a2);
        case 0x06f578ULL: return fde_sub_06f578(a0, a1, a2);
        case 0x06f7a8ULL: return fde_sub_06f7a8(a0, a1, a2);
        case 0x06f83cULL: return fde_sub_06f83c(a0, a1, a2);
        case 0x06f8dcULL: return fde_sub_06f8dc(a0, a1, a2);
        case 0x06f94cULL: return fde_sub_06f94c(a0, a1, a2);
        case 0x06fea8ULL: return fde_sub_06fea8(a0, a1, a2);
        case 0x06ff04ULL: return fde_sub_06ff04(a0, a1, a2);
        case 0x070088ULL: return fde_sub_070088(a0, a1, a2);
        case 0x0701d8ULL: return fde_sub_0701d8(a0, a1, a2);
        case 0x0716bcULL: return fde_sub_0716bc(a0, a1, a2);
        case 0x0716d4ULL: return fde_sub_0716d4(a0, a1, a2);
        case 0x071738ULL: return fde_sub_071738(a0, a1, a2);
        case 0x071770ULL: return fde_sub_071770(a0, a1, a2);
        case 0x071788ULL: return fde_sub_071788(a0, a1, a2);
        case 0x0717b4ULL: return fde_sub_0717b4(a0, a1, a2);
        case 0x0717f8ULL: return fde_sub_0717f8(a0, a1, a2);
        case 0x071818ULL: return fde_sub_071818(a0, a1, a2);
        case 0x071848ULL: return fde_sub_071848(a0, a1, a2);
        case 0x071860ULL: return fde_sub_071860(a0, a1, a2);
        case 0x07186cULL: return fde_sub_07186c(a0, a1, a2);
        case 0x071874ULL: return fde_sub_071874(a0, a1, a2);
        case 0x0718a0ULL: return fde_sub_0718a0(a0, a1, a2);
        case 0x072984ULL: return fde_sub_072984(a0, a1, a2);
        case 0x0729dcULL: return fde_sub_0729dc(a0, a1, a2);
        case 0x0729e4ULL: return fde_sub_0729e4(a0, a1, a2);
        case 0x072a18ULL: return fde_sub_072a18(a0, a1, a2);
        case 0x072a48ULL: return fde_sub_072a48(a0, a1, a2);
        case 0x072a88ULL: return fde_sub_072a88(a0, a1, a2);
        case 0x072aa8ULL: return fde_sub_072aa8(a0, a1, a2);
        case 0x072ac4ULL: return fde_sub_072ac4(a0, a1, a2);
        case 0x072aecULL: return fde_sub_072aec(a0, a1, a2);
        case 0x072e18ULL: return fde_sub_072e18(a0, a1, a2);
        case 0x072e94ULL: return fde_sub_072e94(a0, a1, a2);
        case 0x072f40ULL: return fde_sub_072f40(a0, a1, a2);
        case 0x072fb4ULL: return fde_sub_072fb4(a0, a1, a2);
        case 0x072ff4ULL: return fde_sub_072ff4(a0, a1, a2);
        case 0x073068ULL: return fde_sub_073068(a0, a1, a2);
        case 0x0730d4ULL: return fde_sub_0730d4(a0, a1, a2);
        case 0x073168ULL: return fde_sub_073168(a0, a1, a2);
        case 0x073180ULL: return fde_sub_073180(a0, a1, a2);
        case 0x0732bcULL: return fde_sub_0732bc(a0, a1, a2);
        case 0x0732c4ULL: return fde_sub_0732c4(a0, a1, a2);
        case 0x073400ULL: return fde_sub_073400(a0, a1, a2);
        case 0x073478ULL: return fde_sub_073478(a0, a1, a2);
        case 0x073658ULL: return fde_sub_073658(a0, a1, a2);
        case 0x0736ccULL: return fde_sub_0736cc(a0, a1, a2);
        case 0x073730ULL: return fde_sub_073730(a0, a1, a2);
        case 0x073778ULL: return fde_sub_073778(a0, a1, a2);
        case 0x0737f8ULL: return fde_sub_0737f8(a0, a1, a2);
        case 0x073d3cULL: return fde_sub_073d3c(a0, a1, a2);
        case 0x073d4cULL: return fde_sub_073d4c(a0, a1, a2);
        case 0x073d7cULL: return fde_sub_073d7c(a0, a1, a2);
        case 0x073db0ULL: return fde_sub_073db0(a0, a1, a2);
        case 0x073e58ULL: return fde_sub_073e58(a0, a1, a2);
        case 0x073e68ULL: return fde_sub_073e68(a0, a1, a2);
        case 0x073e98ULL: return fde_sub_073e98(a0, a1, a2);
        case 0x073f08ULL: return fde_sub_073f08(a0, a1, a2);
        case 0x073f10ULL: return fde_sub_073f10(a0, a1, a2);
        case 0x073f18ULL: return fde_sub_073f18(a0, a1, a2);
        default: return 0ULL;
    }
}

} // namespace animax
} // namespace lynx
