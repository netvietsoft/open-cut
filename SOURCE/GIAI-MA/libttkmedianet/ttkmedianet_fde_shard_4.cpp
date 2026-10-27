// ============================================================================
// File: ttkmedianet_fde_shard_4.cpp
// Target 106 / 169: libttkmedianet.so (632,064 bytes)
// EN: Clean-room C++17 AArch64 FDE Shard 4/5 covering FDEs [987..1315]
//     (PC range 0x056b00 .. 0x06c6b4).
// VI: Phân mảnh FDE AArch64 C++17 4/5 bao phủ các FDE [987..1315]
//     (Dải địa chỉ PC 0x056b00 .. 0x06c6b4).
// ============================================================================
#include "ttkmedianet_core.h"

namespace TTKMediaNet {

// FDE #0987 | PC: 0x056b00..0x056b5c (92 B) | Symbol: sub_056b00
// EN: AArch64 prologue [and w8, w0, #0xff; and w9, w1, #0xff; cbz w4, #0x56b14; mov w10, wzr] | VI: Khởi đầu hàm AArch64 [and w8, w0, #0xff; and w9, w1, #0xff; cbz w4, #0x56b14; mov w10, wzr]
uint64_t fde_sub_056b00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x12001C29ULL) << 32) | 0x12001C08ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056B00ULL;
}

// FDE #0988 | PC: 0x056b5c..0x056c44 (232 B) | Symbol: sub_056b5c
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_056b5c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00E8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056B5CULL;
}

// FDE #0989 | PC: 0x056c44..0x056c9c (88 B) | Symbol: sub_056c44
// EN: AArch64 prologue [and w8, w2, #0xff; cmp w8, #3; b.ne #0x56c60; lsr x9, x1, #0x18] | VI: Khởi đầu hàm AArch64 [and w8, w2, #0xff; cmp w8, #3; b.ne #0x56c60; lsr x9, x1, #0x18]
uint64_t fde_sub_056c44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x71000D1FULL) << 32) | 0x12001C48ULL;
    const uint64_t kPcRange = 0x0058ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056C44ULL;
}

// FDE #0990 | PC: 0x056c9c..0x056d94 (248 B) | Symbol: sub_056c9c
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_056c9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056C9CULL;
}

// FDE #0991 | PC: 0x056d94..0x056e90 (252 B) | Symbol: sub_056d94
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_056d94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056D94ULL;
}

// FDE #0992 | PC: 0x056e90..0x056ed4 (68 B) | Symbol: sub_056e90
// EN: AArch64 prologue [sub sp, sp, #0x10; ldr w8, [x0, #0xc]; cmp w8, #2; b.hi #0x56ecc] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x10; ldr w8, [x0, #0xc]; cmp w8, #2; b.hi #0x56ecc]
uint64_t fde_sub_056e90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9400C08ULL) << 32) | 0xD10043FFULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056E90ULL;
}

// FDE #0993 | PC: 0x056ed4..0x056f00 (44 B) | Symbol: sub_056ed4
// EN: AArch64 prologue [ldr w8, [x0, #0xc]; cmp w8, #4; b.ne #0x56efc; ldr x8, [x0, #0x90]] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #0xc]; cmp w8, #4; b.ne #0x56efc; ldr x8, [x0, #0x90]]
uint64_t fde_sub_056ed4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100111FULL) << 32) | 0xB9400C08ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056ED4ULL;
}

// FDE #0994 | PC: 0x056f00..0x056f20 (32 B) | Symbol: sub_056f00
// EN: AArch64 prologue [ldr w8, [x0, #0xc]; cmp w8, #4; b.ne #0x56f1c; ldr x8, [x0, #0x90]] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #0xc]; cmp w8, #4; b.ne #0x56f1c; ldr x8, [x0, #0x90]]
uint64_t fde_sub_056f00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100111FULL) << 32) | 0xB9400C08ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056F00ULL;
}

// FDE #0995 | PC: 0x056f20..0x056f6c (76 B) | Symbol: sub_056f20
// EN: AArch64 prologue [ldr w8, [x0, #0xc]; cmp w8, #4; b.ne #0x56f48; ldrb w8, [x0, #0xd9]] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #0xc]; cmp w8, #4; b.ne #0x56f48; ldrb w8, [x0, #0xd9]]
uint64_t fde_sub_056f20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100111FULL) << 32) | 0xB9400C08ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056F20ULL;
}

// FDE #0996 | PC: 0x056f6c..0x0571b4 (584 B) | Symbol: sub_056f6c
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_056f6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9026FFCULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0248ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x056F6CULL;
}

// FDE #0997 | PC: 0x0571b4..0x05736c (440 B) | Symbol: sub_0571b4
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_0571b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9025FF8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x01B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0571B4ULL;
}

// FDE #0998 | PC: 0x05736c..0x057684 (792 B) | Symbol: sub_05736c
// EN: AArch64 prologue [sub sp, sp, #0xc0; stp x28, x27, [sp, #0x60]; stp x26, x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xc0; stp x28, x27, [sp, #0x60]; stp x26, x25, [sp, #0x70]; stp x24, x23, [sp, #0x80]]
uint64_t fde_sub_05736c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9066FFCULL) << 32) | 0xD10303FFULL;
    const uint64_t kPcRange = 0x0318ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05736CULL;
}

// FDE #0999 | PC: 0x057684..0x057694 (16 B) | Symbol: sub_057684
// EN: AArch64 prologue [ldr x2, [x0, #0x6d8]; ldr x3, [x0, #0x6e0]; add x4, x0, #0x6e8; b #0x5736c] | VI: Khởi đầu hàm AArch64 [ldr x2, [x0, #0x6d8]; ldr x3, [x0, #0x6e0]; add x4, x0, #0x6e8; b #0x5736c]
uint64_t fde_sub_057684(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9437003ULL) << 32) | 0xF9436C02ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057684ULL;
}

// FDE #1000 | PC: 0x057694..0x0579c4 (816 B) | Symbol: sub_057694
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_057694(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9026FFCULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x0330ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057694ULL;
}

// FDE #1001 | PC: 0x0579c4..0x057be0 (540 B) | Symbol: sub_0579c4
// EN: AArch64 prologue [sub sp, sp, #0x1e0; stp x28, x27, [sp, #0x180]; stp x26, x25, [sp, #0x190]; stp x24, x23, [sp, #0x1a0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x1e0; stp x28, x27, [sp, #0x180]; stp x26, x25, [sp, #0x190]; stp x24, x23, [sp, #0x1a0]]
uint64_t fde_sub_0579c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9186FFCULL) << 32) | 0xD10783FFULL;
    const uint64_t kPcRange = 0x021CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0579C4ULL;
}

// FDE #1002 | PC: 0x057be0..0x057e48 (616 B) | Symbol: sub_057be0
// EN: AArch64 prologue [stp x28, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x28, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_057be0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57FCULL;
    const uint64_t kPcRange = 0x0268ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057BE0ULL;
}

// FDE #1003 | PC: 0x057e48..0x05815c (788 B) | Symbol: sub_057e48
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_057e48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9016FFCULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0314ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x057E48ULL;
}

// FDE #1004 | PC: 0x05815c..0x05824c (240 B) | Symbol: sub_05815c
// EN: AArch64 prologue [sub sp, sp, #0xb0; str x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; str x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]]
uint64_t fde_sub_05815c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9002BFBULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x00F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05815CULL;
}

// FDE #1005 | PC: 0x05824c..0x058344 (248 B) | Symbol: sub_05824c
// EN: AArch64 prologue [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_05824c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F9ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05824CULL;
}

// FDE #1006 | PC: 0x058344..0x05836c (40 B) | Symbol: sub_058344
// EN: AArch64 prologue [cmp x1, #0x16; b.hs #0x58354; mov w0, #-0x25c; ret] | VI: Khởi đầu hàm AArch64 [cmp x1, #0x16; b.hs #0x58354; mov w0, #-0x25c; ret]
uint64_t fde_sub_058344(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000062ULL) << 32) | 0xF100583FULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058344ULL;
}

// FDE #1007 | PC: 0x05836c..0x0583f8 (140 B) | Symbol: sub_05836c
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]; add x29, sp, #0x30]
uint64_t fde_sub_05836c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9024FF4ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05836CULL;
}

// FDE #1008 | PC: 0x0583f8..0x0584b4 (188 B) | Symbol: sub_0583f8
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0583f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0583F8ULL;
}

// FDE #1009 | PC: 0x0584b4..0x0585d8 (292 B) | Symbol: sub_0584b4
// EN: AArch64 prologue [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0584b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF9ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0124ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0584B4ULL;
}

// FDE #1010 | PC: 0x0585d8..0x058a68 (1168 B) | Symbol: sub_0585d8
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]]
uint64_t fde_sub_0585d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9036FFCULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0490ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0585D8ULL;
}

// FDE #1011 | PC: 0x058a68..0x058bd8 (368 B) | Symbol: sub_058a68
// EN: AArch64 prologue [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_058a68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F9ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058A68ULL;
}

// FDE #1012 | PC: 0x058bd8..0x058d80 (424 B) | Symbol: sub_058bd8
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_058bd8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9026FFCULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x01A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058BD8ULL;
}

// FDE #1013 | PC: 0x058d80..0x058eac (300 B) | Symbol: sub_058d80
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_058d80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9025FF8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x012CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058D80ULL;
}

// FDE #1014 | PC: 0x058eac..0x058f30 (132 B) | Symbol: sub_058eac
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x218]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x0, #0x218]]
uint64_t fde_sub_058eac(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058EACULL;
}

// FDE #1015 | PC: 0x058f30..0x058f60 (48 B) | Symbol: sub_058f30
// EN: AArch64 prologue [ldr w9, [x0, #0xd0]; ldp x10, x8, [x0, #0xb8]; orr w9, w9, #1; str w9, [x0, #0xd0]] | VI: Khởi đầu hàm AArch64 [ldr w9, [x0, #0xd0]; ldp x10, x8, [x0, #0xb8]; orr w9, w9, #1; str w9, [x0, #0xd0]]
uint64_t fde_sub_058f30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA94BA00AULL) << 32) | 0xB940D009ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058F30ULL;
}

// FDE #1016 | PC: 0x058f60..0x058fbc (92 B) | Symbol: sub_058f60
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_058f60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058F60ULL;
}

// FDE #1017 | PC: 0x058fbc..0x058fdc (32 B) | Symbol: sub_058fbc
// EN: AArch64 prologue [ldr x8, [x0, #0xb8]; ldr w9, [x0, #0xd0]; add x8, x8, #1; orr w9, w9, #2] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0xb8]; ldr w9, [x0, #0xd0]; add x8, x8, #1; orr w9, w9, #2]
uint64_t fde_sub_058fbc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB940D009ULL) << 32) | 0xF9405C08ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058FBCULL;
}

// FDE #1018 | PC: 0x058fdc..0x0593a8 (972 B) | Symbol: sub_058fdc
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp x28, x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp x28, x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]]
uint64_t fde_sub_058fdc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9046FFCULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x03CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x058FDCULL;
}

// FDE #1019 | PC: 0x0593a8..0x05956c (452 B) | Symbol: sub_0593a8
// EN: AArch64 prologue [sub sp, sp, #0x80; str x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]; stp x22, x21, [sp, #0x50]]
uint64_t fde_sub_0593a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9001BF9ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x01C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0593A8ULL;
}

// FDE #1020 | PC: 0x05956c..0x0596e8 (380 B) | Symbol: sub_05956c
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_05956c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9016FFCULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x017CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05956CULL;
}

// FDE #1021 | PC: 0x0596e8..0x0597c8 (224 B) | Symbol: sub_0596e8
// EN: AArch64 prologue [sub sp, sp, #0x60; str x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_0596e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0596E8ULL;
}

// FDE #1022 | PC: 0x0597c8..0x0599a0 (472 B) | Symbol: sub_0597c8
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_0597c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9026FFCULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x01D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0597C8ULL;
}

// FDE #1023 | PC: 0x0599a0..0x059a44 (164 B) | Symbol: sub_0599a0
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0599a0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0599A0ULL;
}

// FDE #1024 | PC: 0x059a44..0x059ba0 (348 B) | Symbol: sub_059a44
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_059a44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9016FFCULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x015CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059A44ULL;
}

// FDE #1025 | PC: 0x059ba0..0x059c2c (140 B) | Symbol: sub_059ba0
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_059ba0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059BA0ULL;
}

// FDE #1026 | PC: 0x059c2c..0x059ce8 (188 B) | Symbol: sub_059c2c
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_059c2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059C2CULL;
}

// FDE #1027 | PC: 0x059ce8..0x059d48 (96 B) | Symbol: sub_059ce8
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x2, x1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x2, x1]
uint64_t fde_sub_059ce8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059CE8ULL;
}

// FDE #1028 | PC: 0x059d48..0x059e70 (296 B) | Symbol: sub_059d48
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_059d48(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x0128ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059D48ULL;
}

// FDE #1029 | PC: 0x059e70..0x059efc (140 B) | Symbol: sub_059e70
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_059e70(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059E70ULL;
}

// FDE #1030 | PC: 0x059efc..0x059fc0 (196 B) | Symbol: sub_059efc
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_059efc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059EFCULL;
}

// FDE #1031 | PC: 0x059fc0..0x05a030 (112 B) | Symbol: sub_059fc0
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x8, x1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x8, x1]
uint64_t fde_sub_059fc0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x059FC0ULL;
}

// FDE #1032 | PC: 0x05a030..0x05a0ec (188 B) | Symbol: sub_05a030
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_05a030(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A030ULL;
}

// FDE #1033 | PC: 0x05a0ec..0x05a14c (96 B) | Symbol: sub_05a0ec
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x2, x1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x2, x1]
uint64_t fde_sub_05a0ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A0ECULL;
}

// FDE #1034 | PC: 0x05a14c..0x05a274 (296 B) | Symbol: sub_05a14c
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_05a14c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x0128ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A14CULL;
}

// FDE #1035 | PC: 0x05a274..0x05a300 (140 B) | Symbol: sub_05a274
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05a274(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A274ULL;
}

// FDE #1036 | PC: 0x05a300..0x05a3c4 (196 B) | Symbol: sub_05a300
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_05a300(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A300ULL;
}

// FDE #1037 | PC: 0x05a3c4..0x05a434 (112 B) | Symbol: sub_05a3c4
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x8, x1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x8, x1]
uint64_t fde_sub_05a3c4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A3C4ULL;
}

// FDE #1038 | PC: 0x05a434..0x05a538 (260 B) | Symbol: sub_05a434
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_05a434(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x0104ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A434ULL;
}

// FDE #1039 | PC: 0x05a538..0x05a65c (292 B) | Symbol: sub_05a538
// EN: AArch64 prologue [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_05a538(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF9ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0124ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A538ULL;
}

// FDE #1040 | PC: 0x05a65c..0x05a6bc (96 B) | Symbol: sub_05a65c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05a65c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A65CULL;
}

// FDE #1041 | PC: 0x05a6bc..0x05a6dc (32 B) | Symbol: sub_05a6bc
// EN: AArch64 prologue [ldr x8, [x0, #0xb8]; ldr w9, [x0, #0xd0]; add x8, x8, #1; orr w9, w9, #0x80000] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0xb8]; ldr w9, [x0, #0xd0]; add x8, x8, #1; orr w9, w9, #0x80000]
uint64_t fde_sub_05a6bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB940D009ULL) << 32) | 0xF9405C08ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A6BCULL;
}

// FDE #1042 | PC: 0x05a6dc..0x05a890 (436 B) | Symbol: sub_05a6dc
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_05a6dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9016FFCULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A6DCULL;
}

// FDE #1043 | PC: 0x05a890..0x05a960 (208 B) | Symbol: sub_05a890
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_05a890(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A890ULL;
}

// FDE #1044 | PC: 0x05a960..0x05aa1c (188 B) | Symbol: sub_05a960
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_05a960(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05A960ULL;
}

// FDE #1045 | PC: 0x05aa1c..0x05aa7c (96 B) | Symbol: sub_05aa1c
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x2, x1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x2, x1]
uint64_t fde_sub_05aa1c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AA1CULL;
}

// FDE #1046 | PC: 0x05aa7c..0x05aaf4 (120 B) | Symbol: sub_05aa7c
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_05aa7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AA7CULL;
}

// FDE #1047 | PC: 0x05aaf4..0x05ab30 (60 B) | Symbol: sub_05aaf4
// EN: AArch64 prologue [ldp x10, x11, [x0, #0xb8]; add x9, x10, #9; cmp x9, x11; b.ls #0x5ab0c] | VI: Khởi đầu hàm AArch64 [ldp x10, x11, [x0, #0xb8]; add x9, x10, #9; cmp x9, x11; b.ls #0x5ab0c]
uint64_t fde_sub_05aaf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91002549ULL) << 32) | 0xA94BAC0AULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AAF4ULL;
}

// FDE #1048 | PC: 0x05ab30..0x05aba8 (120 B) | Symbol: sub_05ab30
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_05ab30(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05AB30ULL;
}

// FDE #1049 | PC: 0x05aba8..0x05abe4 (60 B) | Symbol: sub_05aba8
// EN: AArch64 prologue [ldp x10, x11, [x0, #0xb8]; add x9, x10, #9; cmp x9, x11; b.ls #0x5abc0] | VI: Khởi đầu hàm AArch64 [ldp x10, x11, [x0, #0xb8]; add x9, x10, #9; cmp x9, x11; b.ls #0x5abc0]
uint64_t fde_sub_05aba8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91002549ULL) << 32) | 0xA94BAC0AULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05ABA8ULL;
}

// FDE #1050 | PC: 0x05abe4..0x05b088 (1188 B) | Symbol: sub_05abe4
// EN: AArch64 prologue [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xb0; stp x28, x27, [sp, #0x50]; stp x26, x25, [sp, #0x60]; stp x24, x23, [sp, #0x70]]
uint64_t fde_sub_05abe4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9056FFCULL) << 32) | 0xD102C3FFULL;
    const uint64_t kPcRange = 0x04A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05ABE4ULL;
}

// FDE #1051 | PC: 0x05b088..0x05b284 (508 B) | Symbol: sub_05b088
// EN: AArch64 prologue [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]]
uint64_t fde_sub_05b088(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90023F9ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x01FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B088ULL;
}

// FDE #1052 | PC: 0x05b284..0x05b434 (432 B) | Symbol: sub_05b284
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_05b284(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9016FFCULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B284ULL;
}

// FDE #1053 | PC: 0x05b434..0x05b52c (248 B) | Symbol: sub_05b434
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_05b434(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9025FF8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B434ULL;
}

// FDE #1054 | PC: 0x05b52c..0x05b74c (544 B) | Symbol: sub_05b52c
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]]
uint64_t fde_sub_05b52c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9036FFCULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x0220ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B52CULL;
}

// FDE #1055 | PC: 0x05b74c..0x05b848 (252 B) | Symbol: sub_05b74c
// EN: AArch64 prologue [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_05b74c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF9ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B74CULL;
}

// FDE #1056 | PC: 0x05b848..0x05b9cc (388 B) | Symbol: sub_05b848
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_05b848(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9016FFCULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0184ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B848ULL;
}

// FDE #1057 | PC: 0x05b9cc..0x05bab8 (236 B) | Symbol: sub_05b9cc
// EN: AArch64 prologue [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_05b9cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF9ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05B9CCULL;
}

// FDE #1058 | PC: 0x05bab8..0x05bc3c (388 B) | Symbol: sub_05bab8
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_05bab8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9016FFCULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0184ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05BAB8ULL;
}

// FDE #1059 | PC: 0x05bc3c..0x05bd28 (236 B) | Symbol: sub_05bc3c
// EN: AArch64 prologue [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_05bc3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF9ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05BC3CULL;
}

// FDE #1060 | PC: 0x05bd28..0x05bdb8 (144 B) | Symbol: sub_05bd28
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0xb8]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0xb8]]
uint64_t fde_sub_05bd28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0090ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05BD28ULL;
}

// FDE #1061 | PC: 0x05bdb8..0x05bf58 (416 B) | Symbol: sub_05bdb8
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05bdb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x01A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05BDB8ULL;
}

// FDE #1062 | PC: 0x05bf58..0x05c050 (248 B) | Symbol: sub_05bf58
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0xb8]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0xb8]]
uint64_t fde_sub_05bf58(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05BF58ULL;
}

// FDE #1063 | PC: 0x05c050..0x05c090 (64 B) | Symbol: sub_05c050
// EN: AArch64 prologue [ldr x8, [x1, #0x10]; ldr x9, [x1]; and x8, x8, x0; ldr x8, [x9, x8, lsl #3]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1, #0x10]; ldr x9, [x1]; and x8, x8, x0; ldr x8, [x9, x8, lsl #3]]
uint64_t fde_sub_05c050(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400029ULL) << 32) | 0xF9400828ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C050ULL;
}

// FDE #1064 | PC: 0x05c090..0x05c0ec (92 B) | Symbol: sub_05c090
// EN: AArch64 prologue [ldr x8, [x0]; ldr w9, [x0, #0x10]; ldr w10, [x8, #0xac8]; cbz w10, #0x5c0b0] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0]; ldr w9, [x0, #0x10]; ldr w10, [x8, #0xac8]; cbz w10, #0x5c0b0]
uint64_t fde_sub_05c090(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9401009ULL) << 32) | 0xF9400008ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C090ULL;
}

// FDE #1065 | PC: 0x05c0ec..0x05c314 (552 B) | Symbol: sub_05c0ec
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_05c0ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x0228ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C0ECULL;
}

// FDE #1066 | PC: 0x05c314..0x05c458 (324 B) | Symbol: sub_05c314
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; cmn x1, #1; b.eq #0x5c360] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; cmn x1, #1; b.eq #0x5c360]
uint64_t fde_sub_05c314(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x0144ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C314ULL;
}

// FDE #1067 | PC: 0x05c458..0x05c4b4 (92 B) | Symbol: sub_05c458
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05c458(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C458ULL;
}

// FDE #1068 | PC: 0x05c4b4..0x05c7e4 (816 B) | Symbol: sub_05c4b4
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_05c4b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x0330ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C4B4ULL;
}

// FDE #1069 | PC: 0x05c7e4..0x05ca74 (656 B) | Symbol: sub_05c7e4
// EN: AArch64 prologue [stp x28, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_05c7e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FFCULL;
    const uint64_t kPcRange = 0x0290ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05C7E4ULL;
}

// FDE #1070 | PC: 0x05ca74..0x05cae0 (108 B) | Symbol: sub_05ca74
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05ca74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CA74ULL;
}

// FDE #1071 | PC: 0x05cae0..0x05cb3c (92 B) | Symbol: sub_05cae0
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05cae0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CAE0ULL;
}

// FDE #1072 | PC: 0x05cb3c..0x05ccb8 (380 B) | Symbol: sub_05cb3c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05cb3c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x017CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CB3CULL;
}

// FDE #1073 | PC: 0x05ccb8..0x05cfcc (788 B) | Symbol: sub_05ccb8
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_05ccb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9016FFCULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0314ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CCB8ULL;
}

// FDE #1074 | PC: 0x05cfcc..0x05d0e8 (284 B) | Symbol: sub_05cfcc
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_05cfcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05CFCCULL;
}

// FDE #1075 | PC: 0x05d0e8..0x05d11c (52 B) | Symbol: sub_05d0e8
// EN: AArch64 prologue [cbz x0, #0x5d118; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x5d118; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10]
uint64_t fde_sub_05d0e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0xB4000180ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D0E8ULL;
}

// FDE #1076 | PC: 0x05d11c..0x05d3bc (672 B) | Symbol: sub_05d11c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05d11c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x02A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D11CULL;
}

// FDE #1077 | PC: 0x05d3bc..0x05d594 (472 B) | Symbol: sub_05d3bc
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp x28, x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp x28, x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]]
uint64_t fde_sub_05d3bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9046FFCULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x01D8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D3BCULL;
}

// FDE #1078 | PC: 0x05d594..0x05d788 (500 B) | Symbol: sub_05d594
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05d594(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x01F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D594ULL;
}

// FDE #1079 | PC: 0x05d788..0x05d968 (480 B) | Symbol: sub_05d788
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_05d788(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x01E0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D788ULL;
}

// FDE #1080 | PC: 0x05d968..0x05da10 (168 B) | Symbol: sub_05d968
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05d968(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05D968ULL;
}

// FDE #1081 | PC: 0x05da10..0x05dc94 (644 B) | Symbol: sub_05da10
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_05da10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9016FFCULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0284ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DA10ULL;
}

// FDE #1082 | PC: 0x05dc94..0x05dc9c (8 B) | Symbol: sub_05dc94
// EN: AArch64 prologue [str w1, [x0, #0x104]; ret] | VI: Khởi đầu hàm AArch64 [str w1, [x0, #0x104]; ret]
uint64_t fde_sub_05dc94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9010401ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DC94ULL;
}

// FDE #1083 | PC: 0x05dc9c..0x05e380 (1764 B) | Symbol: sub_05dc9c
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_05dc9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9026FFCULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x06E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05DC9CULL;
}

// FDE #1084 | PC: 0x05e380..0x05e4b4 (308 B) | Symbol: sub_05e380
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_05e380(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9016FFCULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0134ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E380ULL;
}

// FDE #1085 | PC: 0x05e4b4..0x05e5b4 (256 B) | Symbol: sub_05e4b4
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_05e4b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0100ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E4B4ULL;
}

// FDE #1086 | PC: 0x05e5b4..0x05e6b0 (252 B) | Symbol: sub_05e5b4
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_05e5b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E5B4ULL;
}

// FDE #1087 | PC: 0x05e6b0..0x05e81c (364 B) | Symbol: sub_05e6b0
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_05e6b0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x016CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E6B0ULL;
}

// FDE #1088 | PC: 0x05e81c..0x05e988 (364 B) | Symbol: sub_05e81c
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_05e81c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x016CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E81CULL;
}

// FDE #1089 | PC: 0x05e988..0x05e990 (8 B) | Symbol: sub_05e988
// EN: AArch64 prologue [str w1, [x0, #0x100]; ret] | VI: Khởi đầu hàm AArch64 [str w1, [x0, #0x100]; ret]
uint64_t fde_sub_05e988(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9010001ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E988ULL;
}

// FDE #1090 | PC: 0x05e990..0x05e9a8 (24 B) | Symbol: sub_05e990
// EN: AArch64 prologue [ldr x8, [x0, #0x20]; ldr x3, [x8, #0x20]; cbz x3, #0x5e9a4; ldr x2, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x20]; ldr x3, [x8, #0x20]; cbz x3, #0x5e9a4; ldr x2, [x0, #0x18]]
uint64_t fde_sub_05e990(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401103ULL) << 32) | 0xF9401008ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E990ULL;
}

// FDE #1091 | PC: 0x05e9a8..0x05ea34 (140 B) | Symbol: sub_05e9a8
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_05e9a8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x008CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05E9A8ULL;
}

// FDE #1092 | PC: 0x05ea34..0x05ea68 (52 B) | Symbol: sub_05ea34
// EN: AArch64 prologue [cbz x0, #0x5ea64; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x5ea64; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10]
uint64_t fde_sub_05ea34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0xB4000180ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05EA34ULL;
}

// FDE #1093 | PC: 0x05ea68..0x05eb98 (304 B) | Symbol: sub_05ea68
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0xac0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0xac0]]
uint64_t fde_sub_05ea68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05EA68ULL;
}

// FDE #1094 | PC: 0x05eb98..0x05ee8c (756 B) | Symbol: sub_05eb98
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_05eb98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x02F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05EB98ULL;
}

// FDE #1095 | PC: 0x05ee8c..0x05f340 (1204 B) | Symbol: sub_05ee8c
// EN: AArch64 prologue [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; stp x28, x27, [sp, #0x30]; stp x26, x25, [sp, #0x40]; stp x24, x23, [sp, #0x50]]
uint64_t fde_sub_05ee8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9036FFCULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x04B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05EE8CULL;
}

// FDE #1096 | PC: 0x05f340..0x05f364 (36 B) | Symbol: sub_05f340
// EN: AArch64 prologue [ldrh w8, [x0, #0xa14]; cbz w8, #0x5f360; ldrb w8, [x0, #0xac1]; tbz w8, #5, #0x5f360] | VI: Khởi đầu hàm AArch64 [ldrh w8, [x0, #0xa14]; cbz w8, #0x5f360; ldrb w8, [x0, #0xac1]; tbz w8, #5, #0x5f360]
uint64_t fde_sub_05f340(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x340000E8ULL) << 32) | 0x79542808ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F340ULL;
}

// FDE #1097 | PC: 0x05f364..0x05f388 (36 B) | Symbol: sub_05f364
// EN: AArch64 prologue [ldr x3, [x0, #0xbe0]; cbz x3, #0x5f374; ldrb w8, [x0, #0xac1]; tbnz w8, #5, #0x5f37c] | VI: Khởi đầu hàm AArch64 [ldr x3, [x0, #0xbe0]; cbz x3, #0x5f374; ldrb w8, [x0, #0xac1]; tbnz w8, #5, #0x5f37c]
uint64_t fde_sub_05f364(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000063ULL) << 32) | 0xF945F003ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F364ULL;
}

// FDE #1098 | PC: 0x05f388..0x05f3c0 (56 B) | Symbol: sub_05f388
// EN: AArch64 prologue [ldr w8, [x1, #0x160]; cbz w8, #0x5f394; ret; ldr x8, [x1, #0xa8]] | VI: Khởi đầu hàm AArch64 [ldr w8, [x1, #0x160]; cbz w8, #0x5f394; ret; ldr x8, [x1, #0xa8]]
uint64_t fde_sub_05f388(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34000048ULL) << 32) | 0xB9416028ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F388ULL;
}

// FDE #1099 | PC: 0x05f3c0..0x05f494 (212 B) | Symbol: sub_05f3c0
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05f3c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F3C0ULL;
}

// FDE #1100 | PC: 0x05f494..0x05f4c0 (44 B) | Symbol: sub_05f494
// EN: AArch64 prologue [ldrb w8, [x0, #0x1a0]; mov w9, #0x1a; tst w8, w9; b.eq #0x5f4b0] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x1a0]; mov w9, #0x1a; tst w8, w9; b.eq #0x5f4b0]
uint64_t fde_sub_05f494(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800349ULL) << 32) | 0x39468008ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F494ULL;
}

// FDE #1101 | PC: 0x05f4c0..0x05f4fc (60 B) | Symbol: sub_05f4c0
// EN: AArch64 prologue [ldr w8, [x0, #0xf0]; mov w9, #4; movk w9, #0x10, lsl #16; tst w8, w9] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #0xf0]; mov w9, #4; movk w9, #0x10, lsl #16; tst w8, w9]
uint64_t fde_sub_05f4c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x52800089ULL) << 32) | 0xB940F008ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F4C0ULL;
}

// FDE #1102 | PC: 0x05f4fc..0x05f5f4 (248 B) | Symbol: sub_05f4fc
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05f4fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F4FCULL;
}

// FDE #1103 | PC: 0x05f5f4..0x05f704 (272 B) | Symbol: sub_05f5f4
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05f5f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0110ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F5F4ULL;
}

// FDE #1104 | PC: 0x05f704..0x05f760 (92 B) | Symbol: sub_05f704
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05f704(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F704ULL;
}

// FDE #1105 | PC: 0x05f760..0x05f788 (40 B) | Symbol: sub_05f760
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_05f760(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F760ULL;
}

// FDE #1106 | PC: 0x05f788..0x05f7bc (52 B) | Symbol: sub_05f788
// EN: AArch64 prologue [ldr w8, [x0, #0xf0]; cbz w8, #0x5f794; ret; mov x8, x0] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #0xf0]; cbz w8, #0x5f794; ret; mov x8, x0]
uint64_t fde_sub_05f788(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34000048ULL) << 32) | 0xB940F008ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F788ULL;
}

// FDE #1107 | PC: 0x05f7bc..0x05f8ec (304 B) | Symbol: sub_05f7bc
// EN: AArch64 prologue [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_05f7bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F7BCULL;
}

// FDE #1108 | PC: 0x05f8ec..0x05f9f4 (264 B) | Symbol: sub_05f8ec
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_05f8ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0108ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F8ECULL;
}

// FDE #1109 | PC: 0x05f9f4..0x05fb0c (280 B) | Symbol: sub_05f9f4
// EN: AArch64 prologue [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_05f9f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x0118ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05F9F4ULL;
}

// FDE #1110 | PC: 0x05fb0c..0x05fcb8 (428 B) | Symbol: sub_05fb0c
// EN: AArch64 prologue [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_05fb0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F9ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x01ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FB0CULL;
}

// FDE #1111 | PC: 0x05fcb8..0x05fe68 (432 B) | Symbol: sub_05fcb8
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_05fcb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9025FF8ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x01B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FCB8ULL;
}

// FDE #1112 | PC: 0x05fe68..0x06010c (676 B) | Symbol: sub_05fe68
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x28, x27, [sp, #0x10]; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]]
uint64_t fde_sub_05fe68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9016FFCULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x02A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x05FE68ULL;
}

// FDE #1113 | PC: 0x06010c..0x06021c (272 B) | Symbol: sub_06010c
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_06010c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x0110ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06010CULL;
}

// FDE #1114 | PC: 0x06021c..0x060314 (248 B) | Symbol: sub_06021c
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06021c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06021CULL;
}

// FDE #1115 | PC: 0x060314..0x0603e4 (208 B) | Symbol: sub_060314
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_060314(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060314ULL;
}

// FDE #1116 | PC: 0x0603e4..0x06058c (424 B) | Symbol: sub_0603e4
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0603e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x01A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0603E4ULL;
}

// FDE #1117 | PC: 0x06058c..0x0606cc (320 B) | Symbol: sub_06058c
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06058c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0140ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06058CULL;
}

// FDE #1118 | PC: 0x0606cc..0x060774 (168 B) | Symbol: sub_0606cc
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0606cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0606CCULL;
}

// FDE #1119 | PC: 0x060774..0x060824 (176 B) | Symbol: sub_060774
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_060774(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060774ULL;
}

// FDE #1120 | PC: 0x060824..0x0608d4 (176 B) | Symbol: sub_060824
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_060824(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060824ULL;
}

// FDE #1121 | PC: 0x0608d4..0x06097c (168 B) | Symbol: sub_0608d4
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0608d4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0608D4ULL;
}

// FDE #1122 | PC: 0x06097c..0x060a2c (176 B) | Symbol: sub_06097c
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06097c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06097CULL;
}

// FDE #1123 | PC: 0x060a2c..0x060afc (208 B) | Symbol: sub_060a2c
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_060a2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060A2CULL;
}

// FDE #1124 | PC: 0x060afc..0x060c34 (312 B) | Symbol: sub_060afc
// EN: AArch64 prologue [sub sp, sp, #0x150; str x28, [sp, #0x110]; stp x22, x21, [sp, #0x120]; stp x20, x19, [sp, #0x130]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x150; str x28, [sp, #0x110]; stp x22, x21, [sp, #0x120]; stp x20, x19, [sp, #0x130]]
uint64_t fde_sub_060afc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9008BFCULL) << 32) | 0xD10543FFULL;
    const uint64_t kPcRange = 0x0138ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060AFCULL;
}

// FDE #1125 | PC: 0x060c34..0x060eb0 (636 B) | Symbol: sub_060c34
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_060c34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x027CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060C34ULL;
}

// FDE #1126 | PC: 0x060eb0..0x060fe0 (304 B) | Symbol: sub_060eb0
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_060eb0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060EB0ULL;
}

// FDE #1127 | PC: 0x060fe0..0x061080 (160 B) | Symbol: sub_060fe0
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_060fe0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x060FE0ULL;
}

// FDE #1128 | PC: 0x061080..0x061240 (448 B) | Symbol: sub_061080
// EN: AArch64 prologue [sub sp, sp, #0x90; str x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]; stp x20, x19, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x90; str x23, [sp, #0x50]; stp x22, x21, [sp, #0x60]; stp x20, x19, [sp, #0x70]]
uint64_t fde_sub_061080(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9002BF7ULL) << 32) | 0xD10243FFULL;
    const uint64_t kPcRange = 0x01C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061080ULL;
}

// FDE #1129 | PC: 0x061240..0x061314 (212 B) | Symbol: sub_061240
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_061240(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061240ULL;
}

// FDE #1130 | PC: 0x061314..0x061464 (336 B) | Symbol: sub_061314
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_061314(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0150ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061314ULL;
}

// FDE #1131 | PC: 0x061464..0x061524 (192 B) | Symbol: sub_061464
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_061464(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061464ULL;
}

// FDE #1132 | PC: 0x061524..0x0615d8 (180 B) | Symbol: sub_061524
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_061524(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061524ULL;
}

// FDE #1133 | PC: 0x0615d8..0x061698 (192 B) | Symbol: sub_0615d8
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0615d8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0615D8ULL;
}

// FDE #1134 | PC: 0x061698..0x061788 (240 B) | Symbol: sub_061698
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_061698(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061698ULL;
}

// FDE #1135 | PC: 0x061788..0x06179c (20 B) | Symbol: sub_061788
// EN: AArch64 prologue [ldp w8, w9, [x0, #0xc8]; ldr x10, [x0, #0x1d0]; sub w8, w8, w9; sub x0, x8, x10] | VI: Khởi đầu hàm AArch64 [ldp w8, w9, [x0, #0xc8]; ldr x10, [x0, #0x1d0]; sub w8, w8, w9; sub x0, x8, x10]
uint64_t fde_sub_061788(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF940E80AULL) << 32) | 0x29592408ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061788ULL;
}

// FDE #1136 | PC: 0x06179c..0x0617b4 (24 B) | Symbol: sub_06179c
// EN: AArch64 prologue [ldp w8, w9, [x0, #0xc8]; ldr x10, [x0, #0x1d0]; sub w8, w8, w9; sub x8, x8, x10] | VI: Khởi đầu hàm AArch64 [ldp w8, w9, [x0, #0xc8]; ldr x10, [x0, #0x1d0]; sub w8, w8, w9; sub x8, x8, x10]
uint64_t fde_sub_06179c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF940E80AULL) << 32) | 0x29592408ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06179CULL;
}

// FDE #1137 | PC: 0x0617b4..0x0617cc (24 B) | Symbol: sub_0617b4
// EN: AArch64 prologue [add x8, x1, x2; stp x1, x2, [x0, #0x90]; stp x3, x4, [x0, #0xa0]; stp x1, x8, [x0, #0xb8]] | VI: Khởi đầu hàm AArch64 [add x8, x1, x2; stp x1, x2, [x0, #0x90]; stp x3, x4, [x0, #0xa0]; stp x1, x8, [x0, #0xb8]]
uint64_t fde_sub_0617b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9090801ULL) << 32) | 0x8B020028ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0617B4ULL;
}

// FDE #1138 | PC: 0x0617cc..0x0617fc (48 B) | Symbol: sub_0617cc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0617cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0030ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0617CCULL;
}

// FDE #1139 | PC: 0x0617fc..0x0618b8 (188 B) | Symbol: sub_0617fc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x1, #0xd8]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x1, #0xd8]]
uint64_t fde_sub_0617fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0617FCULL;
}

// FDE #1140 | PC: 0x0618b8..0x061938 (128 B) | Symbol: sub_0618b8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1]
uint64_t fde_sub_0618b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0618B8ULL;
}

// FDE #1141 | PC: 0x061938..0x061a98 (352 B) | Symbol: sub_061938
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_061938(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0160ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061938ULL;
}

// FDE #1142 | PC: 0x061a98..0x061c7c (484 B) | Symbol: sub_061a98
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_061a98(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x01E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061A98ULL;
}

// FDE #1143 | PC: 0x061c7c..0x061d9c (288 B) | Symbol: sub_061c7c
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_061c7c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0120ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061C7CULL;
}

// FDE #1144 | PC: 0x061d9c..0x061fa0 (516 B) | Symbol: sub_061d9c
// EN: AArch64 prologue [sub sp, sp, #0xf0; str x23, [sp, #0xb0]; stp x22, x21, [sp, #0xc0]; stp x20, x19, [sp, #0xd0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xf0; str x23, [sp, #0xb0]; stp x22, x21, [sp, #0xc0]; stp x20, x19, [sp, #0xd0]]
uint64_t fde_sub_061d9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9005BF7ULL) << 32) | 0xD103C3FFULL;
    const uint64_t kPcRange = 0x0204ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061D9CULL;
}

// FDE #1145 | PC: 0x061fa0..0x0620d0 (304 B) | Symbol: sub_061fa0
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_061fa0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0130ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x061FA0ULL;
}

// FDE #1146 | PC: 0x0620d0..0x0620dc (12 B) | Symbol: sub_0620d0
// EN: AArch64 prologue [movi v0.2d, #0000000000000000; str q0, [x0, #0x380]; ret] | VI: Khởi đầu hàm AArch64 [movi v0.2d, #0000000000000000; str q0, [x0, #0x380]; ret]
uint64_t fde_sub_0620d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3D80E000ULL) << 32) | 0x6F00E400ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0620D0ULL;
}

// FDE #1147 | PC: 0x0620dc..0x062454 (888 B) | Symbol: sub_0620dc
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0620dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x0378ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0620DCULL;
}

// FDE #1148 | PC: 0x062454..0x0624fc (168 B) | Symbol: sub_062454
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x0, [x0, #0x708]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x0, [x0, #0x708]]
uint64_t fde_sub_062454(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062454ULL;
}

// FDE #1149 | PC: 0x0624fc..0x062544 (72 B) | Symbol: sub_0624fc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0624fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0624FCULL;
}

// FDE #1150 | PC: 0x062544..0x06254c (8 B) | Symbol: sub_062544
// EN: AArch64 prologue [ldr x0, [x1, #0x1a0]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x1, #0x1a0]; ret]
uint64_t fde_sub_062544(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF940D020ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062544ULL;
}

// FDE #1151 | PC: 0x06254c..0x062648 (252 B) | Symbol: sub_06254c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0]]
uint64_t fde_sub_06254c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06254CULL;
}

// FDE #1152 | PC: 0x062648..0x0626f0 (168 B) | Symbol: sub_062648
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_062648(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062648ULL;
}

// FDE #1153 | PC: 0x0626f0..0x0627dc (236 B) | Symbol: sub_0626f0
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0626f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00ECULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0626F0ULL;
}

// FDE #1154 | PC: 0x0627dc..0x0628f0 (276 B) | Symbol: sub_0627dc
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0627dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0627DCULL;
}

// FDE #1155 | PC: 0x0628f0..0x062904 (20 B) | Symbol: sub_0628f0
// EN: AArch64 prologue [add x8, x0, w1, uxtw #3; str xzr, [x8, #0xa0]; str xzr, [x8, #0x80]; str wzr, [x0, #0x330]] | VI: Khởi đầu hàm AArch64 [add x8, x0, w1, uxtw #3; str xzr, [x8, #0xa0]; str xzr, [x8, #0x80]; str wzr, [x0, #0x330]]
uint64_t fde_sub_0628f0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900511FULL) << 32) | 0x8B214C08ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0628F0ULL;
}

// FDE #1156 | PC: 0x062904..0x062a40 (316 B) | Symbol: sub_062904
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_062904(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x013CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062904ULL;
}

// FDE #1157 | PC: 0x062a40..0x062de0 (928 B) | Symbol: sub_062a40
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_062a40(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x03A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062A40ULL;
}

// FDE #1158 | PC: 0x062de0..0x063420 (1600 B) | Symbol: sub_062de0
// EN: AArch64 prologue [sub sp, sp, #0xf0; stp x28, x27, [sp, #0x90]; stp x26, x25, [sp, #0xa0]; stp x24, x23, [sp, #0xb0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xf0; stp x28, x27, [sp, #0x90]; stp x26, x25, [sp, #0xa0]; stp x24, x23, [sp, #0xb0]]
uint64_t fde_sub_062de0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9096FFCULL) << 32) | 0xD103C3FFULL;
    const uint64_t kPcRange = 0x0640ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x062DE0ULL;
}

// FDE #1159 | PC: 0x063420..0x0635b8 (408 B) | Symbol: sub_063420
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_063420(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0198ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063420ULL;
}

// FDE #1160 | PC: 0x0635b8..0x063af0 (1336 B) | Symbol: sub_0635b8
// EN: AArch64 prologue [sub sp, sp, #0xa0; stp x28, x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xa0; stp x28, x27, [sp, #0x40]; stp x26, x25, [sp, #0x50]; stp x24, x23, [sp, #0x60]]
uint64_t fde_sub_0635b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9046FFCULL) << 32) | 0xD10283FFULL;
    const uint64_t kPcRange = 0x0538ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0635B8ULL;
}

// FDE #1161 | PC: 0x063af0..0x063c04 (276 B) | Symbol: sub_063af0
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_063af0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0114ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063AF0ULL;
}

// FDE #1162 | PC: 0x063c04..0x063c9c (152 B) | Symbol: sub_063c04
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_063c04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0098ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063C04ULL;
}

// FDE #1163 | PC: 0x063c9c..0x063e4c (432 B) | Symbol: sub_063c9c
// EN: AArch64 prologue [stp d9, d8, [sp, #-0x50]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp d9, d8, [sp, #-0x50]!; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_063c9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0x6DBB23E9ULL;
    const uint64_t kPcRange = 0x01B0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063C9CULL;
}

// FDE #1164 | PC: 0x063e4c..0x063e94 (72 B) | Symbol: sub_063e4c
// EN: AArch64 prologue [ldr x8, [x0, #0x80]; str wzr, [x1]; ldr x9, [x0, #0x88]; sub x10, x8, #1] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x80]; str wzr, [x1]; ldr x9, [x0, #0x88]; sub x10, x8, #1]
uint64_t fde_sub_063e4c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB900003FULL) << 32) | 0xF9404008ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063E4CULL;
}

// FDE #1165 | PC: 0x063e94..0x063e9c (8 B) | Symbol: sub_063e94
// EN: AArch64 prologue [ldr x0, [x0, #0xd0]; ret] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0xd0]; ret]
uint64_t fde_sub_063e94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xF9406800ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063E94ULL;
}

// FDE #1166 | PC: 0x063e9c..0x063ec8 (44 B) | Symbol: sub_063e9c
// EN: AArch64 prologue [ldr w8, [x0, #0x334]; cbz w8, #0x63ec0; ldr w9, [x0, #0x338]; ldr w10, [x0, #0x33c]] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #0x334]; cbz w8, #0x63ec0; ldr w9, [x0, #0x338]; ldr w10, [x0, #0x33c]]
uint64_t fde_sub_063e9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34000108ULL) << 32) | 0xB9433408ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063E9CULL;
}

// FDE #1167 | PC: 0x063ec8..0x063eec (36 B) | Symbol: sub_063ec8
// EN: AArch64 prologue [ldr w8, [x0, #0x334]; cbz w8, #0x63ee4; ldr s0, [x0, #0x340]; ucvtf s1, w8] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #0x334]; cbz w8, #0x63ee4; ldr s0, [x0, #0x340]; ucvtf s1, w8]
uint64_t fde_sub_063ec8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x340000C8ULL) << 32) | 0xB9433408ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063EC8ULL;
}

// FDE #1168 | PC: 0x063eec..0x063efc (16 B) | Symbol: sub_063eec
// EN: AArch64 prologue [ldrb w8, [x0, #0x170]; cbz w8, #0x63ef8; ret; b #0x62904] | VI: Khởi đầu hàm AArch64 [ldrb w8, [x0, #0x170]; cbz w8, #0x63ef8; ret; b #0x62904]
uint64_t fde_sub_063eec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x34000048ULL) << 32) | 0x3945C008ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063EECULL;
}

// FDE #1169 | PC: 0x063efc..0x063f10 (20 B) | Symbol: sub_063efc
// EN: AArch64 prologue [add x8, x0, w1, uxtw #3; ldr x8, [x8, #0x28]; cmp x8, #0; cset w0, ne] | VI: Khởi đầu hàm AArch64 [add x8, x0, w1, uxtw #3; ldr x8, [x8, #0x28]; cmp x8, #0; cset w0, ne]
uint64_t fde_sub_063efc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9401508ULL) << 32) | 0x8B214C08ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063EFCULL;
}

// FDE #1170 | PC: 0x063f10..0x063f94 (132 B) | Symbol: sub_063f10
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_063f10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0084ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063F10ULL;
}

// FDE #1171 | PC: 0x063f94..0x063f9c (8 B) | Symbol: sub_063f94
// EN: AArch64 prologue [add x0, x0, #0x3b8; b #0x684b8] | VI: Khởi đầu hàm AArch64 [add x0, x0, #0x3b8; b #0x684b8]
uint64_t fde_sub_063f94(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x14001148ULL) << 32) | 0x910EE000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063F94ULL;
}

// FDE #1172 | PC: 0x063f9c..0x06413c (416 B) | Symbol: sub_063f9c
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_063f9c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x01A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x063F9CULL;
}

// FDE #1173 | PC: 0x06413c..0x064188 (76 B) | Symbol: sub_06413c
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #8]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #8]]
uint64_t fde_sub_06413c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x004CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06413CULL;
}

// FDE #1174 | PC: 0x064188..0x06438c (516 B) | Symbol: sub_064188
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_064188(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0204ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064188ULL;
}

// FDE #1175 | PC: 0x06438c..0x0643cc (64 B) | Symbol: sub_06438c
// EN: AArch64 prologue [ldr x8, [x1, #8]; cmp x8, x1; b.eq #0x643c8; add x9, x0, #0x68] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1, #8]; cmp x8, x1; b.eq #0x643c8; add x9, x0, #0x68]
uint64_t fde_sub_06438c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB01011FULL) << 32) | 0xF9400428ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06438CULL;
}

// FDE #1176 | PC: 0x0643cc..0x0645c8 (508 B) | Symbol: sub_0643cc
// EN: AArch64 prologue [ldr x9, [x0, #0x10]; add x8, x0, #8; cmp x9, x8; b.eq #0x6440c] | VI: Khởi đầu hàm AArch64 [ldr x9, [x0, #0x10]; add x8, x0, #8; cmp x9, x8; b.eq #0x6440c]
uint64_t fde_sub_0643cc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91002008ULL) << 32) | 0xF9400809ULL;
    const uint64_t kPcRange = 0x01FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0643CCULL;
}

// FDE #1177 | PC: 0x0645c8..0x064610 (72 B) | Symbol: sub_0645c8
// EN: AArch64 prologue [mov x9, x0; ldr x8, [x9, #8]!; cmp x8, x9; b.ne #0x645ec] | VI: Khởi đầu hàm AArch64 [mov x9, x0; ldr x8, [x9, #8]!; cmp x8, x9; b.ne #0x645ec]
uint64_t fde_sub_0645c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF8408D28ULL) << 32) | 0xAA0003E9ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0645C8ULL;
}

// FDE #1178 | PC: 0x064610..0x0646bc (172 B) | Symbol: sub_064610
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x9, x0] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x9, x0]
uint64_t fde_sub_064610(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064610ULL;
}

// FDE #1179 | PC: 0x0646bc..0x06482c (368 B) | Symbol: sub_0646bc
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; add x9, x0, #8; cmp x8, x9; b.eq #0x646d4] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; add x9, x0, #8; cmp x8, x9; b.eq #0x646d4]
uint64_t fde_sub_0646bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91002009ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0646BCULL;
}

// FDE #1180 | PC: 0x06482c..0x064850 (36 B) | Symbol: sub_06482c
// EN: AArch64 prologue [ldr x8, [x1]; add x9, x0, #0x80; str x9, [x1]; stp x8, x1, [x0, #0x80]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1]; add x9, x0, #0x80; str x9, [x1]; stp x8, x1, [x0, #0x80]]
uint64_t fde_sub_06482c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91020009ULL) << 32) | 0xF9400028ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06482CULL;
}

// FDE #1181 | PC: 0x064850..0x064864 (20 B) | Symbol: sub_064850
// EN: AArch64 prologue [ldp x8, x9, [x0]; str x8, [x9]; str x9, [x8, #8]; stp x0, x0, [x0]] | VI: Khởi đầu hàm AArch64 [ldp x8, x9, [x0]; str x8, [x9]; str x9, [x8, #8]; stp x0, x0, [x0]]
uint64_t fde_sub_064850(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000128ULL) << 32) | 0xA9402408ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064850ULL;
}

// FDE #1182 | PC: 0x064864..0x0648e0 (124 B) | Symbol: sub_064864
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_064864(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064864ULL;
}

// FDE #1183 | PC: 0x0648e0..0x064900 (32 B) | Symbol: sub_0648e0
// EN: AArch64 prologue [ldp x8, x9, [x0]; str x8, [x9]; str x9, [x8, #8]; stp x0, x0, [x0]] | VI: Khởi đầu hàm AArch64 [ldp x8, x9, [x0]; str x8, [x9]; str x9, [x8, #8]; stp x0, x0, [x0]]
uint64_t fde_sub_0648e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000128ULL) << 32) | 0xA9402408ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0648E0ULL;
}

// FDE #1184 | PC: 0x064900..0x064914 (20 B) | Symbol: sub_064900
// EN: AArch64 prologue [ldr x8, [x1]; str x0, [x1]; stp x8, x1, [x0]; str x0, [x8, #8]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1]; str x0, [x1]; stp x8, x1, [x0]; str x0, [x8, #8]]
uint64_t fde_sub_064900(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000020ULL) << 32) | 0xF9400028ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064900ULL;
}

// FDE #1185 | PC: 0x064914..0x064934 (32 B) | Symbol: sub_064914
// EN: AArch64 prologue [ldp x8, x9, [x0]; str x8, [x9]; str x9, [x8, #8]; stp x0, x0, [x0]] | VI: Khởi đầu hàm AArch64 [ldp x8, x9, [x0]; str x8, [x9]; str x9, [x8, #8]; stp x0, x0, [x0]]
uint64_t fde_sub_064914(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000128ULL) << 32) | 0xA9402408ULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064914ULL;
}

// FDE #1186 | PC: 0x064934..0x064948 (20 B) | Symbol: sub_064934
// EN: AArch64 prologue [ldr x8, [x1]; str x0, [x1]; stp x8, x1, [x0]; str x0, [x8, #8]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1]; str x0, [x1]; stp x8, x1, [x0]; str x0, [x8, #8]]
uint64_t fde_sub_064934(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000020ULL) << 32) | 0xF9400028ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064934ULL;
}

// FDE #1187 | PC: 0x064948..0x06497c (52 B) | Symbol: sub_064948
// EN: AArch64 prologue [ldr x8, [x1]; add x9, x0, #0x80; str x9, [x1]; stp x8, x1, [x0, #0x80]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x1]; add x9, x0, #0x80; str x9, [x1]; stp x8, x1, [x0, #0x80]]
uint64_t fde_sub_064948(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x91020009ULL) << 32) | 0xF9400028ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064948ULL;
}

// FDE #1188 | PC: 0x06497c..0x0649b8 (60 B) | Symbol: sub_06497c
// EN: AArch64 prologue [mov x9, x0; ldr x8, [x9, #0x80]!; ldr x10, [x9, #8]; str x8, [x10]] | VI: Khởi đầu hàm AArch64 [mov x9, x0; ldr x8, [x9, #0x80]!; ldr x10, [x9, #8]; str x8, [x10]]
uint64_t fde_sub_06497c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF8480D28ULL) << 32) | 0xAA0003E9ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06497CULL;
}

// FDE #1189 | PC: 0x0649b8..0x0649dc (36 B) | Symbol: sub_0649b8
// EN: AArch64 prologue [ldp x8, x9, [x0]; str x8, [x9]; str x9, [x8, #8]; str x0, [x0, #8]] | VI: Khởi đầu hàm AArch64 [ldp x8, x9, [x0]; str x8, [x9]; str x9, [x8, #8]; str x0, [x0, #8]]
uint64_t fde_sub_0649b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000128ULL) << 32) | 0xA9402408ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0649B8ULL;
}

// FDE #1190 | PC: 0x0649dc..0x064a00 (36 B) | Symbol: sub_0649dc
// EN: AArch64 prologue [ldp x8, x9, [x0]; str x8, [x9]; str x9, [x8, #8]; str x0, [x0]] | VI: Khởi đầu hàm AArch64 [ldp x8, x9, [x0]; str x8, [x9]; str x9, [x8, #8]; str x0, [x0]]
uint64_t fde_sub_0649dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000128ULL) << 32) | 0xA9402408ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0649DCULL;
}

// FDE #1191 | PC: 0x064a00..0x064a24 (36 B) | Symbol: sub_064a00
// EN: AArch64 prologue [ldp x8, x9, [x0]; str x8, [x9]; str x9, [x8, #8]; str x0, [x0]] | VI: Khởi đầu hàm AArch64 [ldp x8, x9, [x0]; str x8, [x9]; str x9, [x8, #8]; str x0, [x0]]
uint64_t fde_sub_064a00(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000128ULL) << 32) | 0xA9402408ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064A00ULL;
}

// FDE #1192 | PC: 0x064a24..0x064b20 (252 B) | Symbol: sub_064a24
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_064a24(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064A24ULL;
}

// FDE #1193 | PC: 0x064b20..0x064c18 (248 B) | Symbol: sub_064b20
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_064b20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064B20ULL;
}

// FDE #1194 | PC: 0x064c18..0x064c80 (104 B) | Symbol: sub_064c18
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_064c18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064C18ULL;
}

// FDE #1195 | PC: 0x064c80..0x065144 (1220 B) | Symbol: sub_064c80
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_064c80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x04C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x064C80ULL;
}

// FDE #1196 | PC: 0x065144..0x065734 (1520 B) | Symbol: sub_065144
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_065144(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x05F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065144ULL;
}

// FDE #1197 | PC: 0x065734..0x06576c (56 B) | Symbol: sub_065734
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0xf48]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0xf48]]
uint64_t fde_sub_065734(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065734ULL;
}

// FDE #1198 | PC: 0x06576c..0x0657a4 (56 B) | Symbol: sub_06576c
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0xf48]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0xf48]]
uint64_t fde_sub_06576c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06576CULL;
}

// FDE #1199 | PC: 0x0657a4..0x065dcc (1576 B) | Symbol: sub_0657a4
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_0657a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x0628ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0657A4ULL;
}

// FDE #1200 | PC: 0x065dcc..0x065df0 (36 B) | Symbol: sub_065dcc
// EN: AArch64 prologue [sub w8, w0, #1; cmp w8, #3; b.hi #0x65de8; adrp x9, #0x7d000] | VI: Khởi đầu hàm AArch64 [sub w8, w0, #1; cmp w8, #3; b.hi #0x65de8; adrp x9, #0x7d000]
uint64_t fde_sub_065dcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x71000D1FULL) << 32) | 0x51000408ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065DCCULL;
}

// FDE #1201 | PC: 0x065df0..0x065e10 (32 B) | Symbol: sub_065df0
// EN: AArch64 prologue [cmp w0, #4; b.hi #0x65e08; adrp x8, #0x7d000; add x8, x8, #0xe98] | VI: Khởi đầu hàm AArch64 [cmp w0, #4; b.hi #0x65e08; adrp x8, #0x7d000; add x8, x8, #0xe98]
uint64_t fde_sub_065df0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x540000A8ULL) << 32) | 0x7100101FULL;
    const uint64_t kPcRange = 0x0020ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065DF0ULL;
}

// FDE #1202 | PC: 0x065e10..0x065e34 (36 B) | Symbol: sub_065e10
// EN: AArch64 prologue [ldrsw x8, [x0, #0x704]; cmp w8, #9; b.hi #0x65e2c; adrp x9, #0x7d000] | VI: Khởi đầu hàm AArch64 [ldrsw x8, [x0, #0x704]; cmp w8, #9; b.hi #0x65e2c; adrp x9, #0x7d000]
uint64_t fde_sub_065e10(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x7100251FULL) << 32) | 0xB9870408ULL;
    const uint64_t kPcRange = 0x0024ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065E10ULL;
}

// FDE #1203 | PC: 0x065e34..0x065f44 (272 B) | Symbol: sub_065e34
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldp x8, x9, [x1, #0xb8]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldp x8, x9, [x1, #0xb8]]
uint64_t fde_sub_065e34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0110ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065E34ULL;
}

// FDE #1204 | PC: 0x065f44..0x065ffc (184 B) | Symbol: sub_065f44
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_065f44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065F44ULL;
}

// FDE #1205 | PC: 0x065ffc..0x06605c (96 B) | Symbol: sub_065ffc
// EN: AArch64 prologue [fmov d0, x0; mov w8, #0x3f; mov v0.d[1], x1; mov w9, #0x3fff] | VI: Khởi đầu hàm AArch64 [fmov d0, x0; mov w8, #0x3f; mov v0.d[1], x1; mov w9, #0x3fff]
uint64_t fde_sub_065ffc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x528007E8ULL) << 32) | 0x9E670000ULL;
    const uint64_t kPcRange = 0x0060ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x065FFCULL;
}

// FDE #1206 | PC: 0x06605c..0x066a18 (2492 B) | Symbol: sub_06605c
// EN: AArch64 prologue [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x28, x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_06605c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xA9BA6FFCULL;
    const uint64_t kPcRange = 0x09BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06605CULL;
}

// FDE #1207 | PC: 0x066a18..0x066bb8 (416 B) | Symbol: sub_066a18
// EN: AArch64 prologue [sub sp, sp, #0x60; str x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]; stp x20, x19, [sp, #0x40]]
uint64_t fde_sub_066a18(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F7ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x01A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066A18ULL;
}

// FDE #1208 | PC: 0x066bb8..0x066ca8 (240 B) | Symbol: sub_066bb8
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_066bb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90257F6ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x00F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066BB8ULL;
}

// FDE #1209 | PC: 0x066ca8..0x066e74 (460 B) | Symbol: sub_066ca8
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_066ca8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x01CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066CA8ULL;
}

// FDE #1210 | PC: 0x066e74..0x06731c (1192 B) | Symbol: sub_066e74
// EN: AArch64 prologue [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; str x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_066e74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF9ULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x04A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x066E74ULL;
}

// FDE #1211 | PC: 0x06731c..0x067428 (268 B) | Symbol: sub_06731c
// EN: AArch64 prologue [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]; stp x29, x30, [sp, #0x40]]
uint64_t fde_sub_06731c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013F5ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x010CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06731CULL;
}

// FDE #1212 | PC: 0x067428..0x0675f8 (464 B) | Symbol: sub_067428
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x22, x21, [sp, #0x50]; stp x20, x19, [sp, #0x60]; stp x29, x30, [sp, #0x70]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x22, x21, [sp, #0x50]; stp x20, x19, [sp, #0x60]; stp x29, x30, [sp, #0x70]]
uint64_t fde_sub_067428(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90557F6ULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x01D0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067428ULL;
}

// FDE #1213 | PC: 0x0675f8..0x06773c (324 B) | Symbol: sub_0675f8
// EN: AArch64 prologue [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0675f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0144ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0675F8ULL;
}

// FDE #1214 | PC: 0x06773c..0x067858 (284 B) | Symbol: sub_06773c
// EN: AArch64 prologue [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06773c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x011CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06773CULL;
}

// FDE #1215 | PC: 0x067858..0x0679d0 (376 B) | Symbol: sub_067858
// EN: AArch64 prologue [sub sp, sp, #0x50; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_067858(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0178ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067858ULL;
}

// FDE #1216 | PC: 0x0679d0..0x067b0c (316 B) | Symbol: sub_0679d0
// EN: AArch64 prologue [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x40; str x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_0679d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF5ULL) << 32) | 0xD10103FFULL;
    const uint64_t kPcRange = 0x013CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0679D0ULL;
}

// FDE #1217 | PC: 0x067b0c..0x067ca0 (404 B) | Symbol: sub_067b0c
// EN: AArch64 prologue [sub sp, sp, #0x70; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; stp x26, x25, [sp, #0x20]; stp x24, x23, [sp, #0x30]; stp x22, x21, [sp, #0x40]]
uint64_t fde_sub_067b0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90267FAULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x0194ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067B0CULL;
}

// FDE #1218 | PC: 0x067ca0..0x067d60 (192 B) | Symbol: sub_067ca0
// EN: AArch64 prologue [sub sp, sp, #0x70; str x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]; add x29, sp, #0x60] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x70; str x19, [sp, #0x50]; stp x29, x30, [sp, #0x60]; add x29, sp, #0x60]
uint64_t fde_sub_067ca0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9002BF3ULL) << 32) | 0xD101C3FFULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067CA0ULL;
}

// FDE #1219 | PC: 0x067d60..0x067e04 (164 B) | Symbol: sub_067d60
// EN: AArch64 prologue [sub sp, sp, #0x110; stp x28, x19, [sp, #0xf0]; stp x29, x30, [sp, #0x100]; add x29, sp, #0x100] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; stp x28, x19, [sp, #0xf0]; stp x29, x30, [sp, #0x100]; add x29, sp, #0x100]
uint64_t fde_sub_067d60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90F4FFCULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067D60ULL;
}

// FDE #1220 | PC: 0x067e04..0x068048 (580 B) | Symbol: sub_067e04
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_067e04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0244ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x067E04ULL;
}

// FDE #1221 | PC: 0x068048..0x0680e8 (160 B) | Symbol: sub_068048
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_068048(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00A0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068048ULL;
}

// FDE #1222 | PC: 0x0680e8..0x06813c (84 B) | Symbol: sub_0680e8
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #8]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #8]]
uint64_t fde_sub_0680e8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0680E8ULL;
}

// FDE #1223 | PC: 0x06813c..0x068158 (28 B) | Symbol: sub_06813c
// EN: AArch64 prologue [ldr x8, [x0, #8]; cmp x8, x0; b.eq #0x68150; ldur x0, [x8, #-8]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #8]; cmp x8, x0; b.eq #0x68150; ldur x0, [x8, #-8]]
uint64_t fde_sub_06813c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xEB00011FULL) << 32) | 0xF9400408ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06813CULL;
}

// FDE #1224 | PC: 0x068158..0x0682bc (356 B) | Symbol: sub_068158
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_068158(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x0164ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068158ULL;
}

// FDE #1225 | PC: 0x0682bc..0x0682f8 (60 B) | Symbol: sub_0682bc
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0682bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x003CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0682BCULL;
}

// FDE #1226 | PC: 0x0682f8..0x068324 (44 B) | Symbol: sub_0682f8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x0]
uint64_t fde_sub_0682f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0682F8ULL;
}

// FDE #1227 | PC: 0x068324..0x0683c8 (164 B) | Symbol: sub_068324
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_068324(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068324ULL;
}

// FDE #1228 | PC: 0x0683c8..0x068490 (200 B) | Symbol: sub_0683c8
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0683c8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x00C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0683C8ULL;
}

// FDE #1229 | PC: 0x068490..0x0684b8 (40 B) | Symbol: sub_068490
// EN: AArch64 prologue [mov w8, #0x3818; stp xzr, x2, [x0, #8]; stp w1, w8, [x0]; str wzr, [x0, #0x18]] | VI: Khởi đầu hàm AArch64 [mov w8, #0x3818; stp xzr, x2, [x0, #8]; stp w1, w8, [x0]; str wzr, [x0, #0x18]]
uint64_t fde_sub_068490(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA900881FULL) << 32) | 0x52870308ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068490ULL;
}

// FDE #1230 | PC: 0x0684b8..0x068574 (188 B) | Symbol: sub_0684b8
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #0x10]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x19, [x0, #0x10]]
uint64_t fde_sub_0684b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00BCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0684B8ULL;
}

// FDE #1231 | PC: 0x068574..0x068740 (460 B) | Symbol: sub_068574
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_068574(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x01CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068574ULL;
}

// FDE #1232 | PC: 0x068740..0x068908 (456 B) | Symbol: sub_068740
// EN: AArch64 prologue [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x27, [sp, #-0x60]!; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_068740(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xF81A0FFBULL;
    const uint64_t kPcRange = 0x01C8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068740ULL;
}

// FDE #1233 | PC: 0x068908..0x068a78 (368 B) | Symbol: sub_068908
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_068908(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x0170ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068908ULL;
}

// FDE #1234 | PC: 0x068a78..0x068ab0 (56 B) | Symbol: sub_068a78
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w8, #0x3818] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w8, #0x3818]
uint64_t fde_sub_068a78(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068A78ULL;
}

// FDE #1235 | PC: 0x068ab0..0x068ab8 (8 B) | Symbol: sub_068ab0
// EN: AArch64 prologue [ldr w0, [x0]; ret] | VI: Khởi đầu hàm AArch64 [ldr w0, [x0]; ret]
uint64_t fde_sub_068ab0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xD65F03C0ULL) << 32) | 0xB9400000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068AB0ULL;
}

// FDE #1236 | PC: 0x068ab8..0x068bec (308 B) | Symbol: sub_068ab8
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_068ab8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x0134ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068AB8ULL;
}

// FDE #1237 | PC: 0x068bec..0x068ce0 (244 B) | Symbol: sub_068bec
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_068bec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00F4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068BECULL;
}

// FDE #1238 | PC: 0x068ce0..0x068cf8 (24 B) | Symbol: sub_068ce0
// EN: AArch64 prologue [ldr x8, [x0, #0x10]; cbz x8, #0x68cf0; ldr x0, [x0]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x10]; cbz x8, #0x68cf0; ldr x0, [x0]; ret]
uint64_t fde_sub_068ce0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB4000068ULL) << 32) | 0xF9400808ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068CE0ULL;
}

// FDE #1239 | PC: 0x068cf8..0x068ddc (228 B) | Symbol: sub_068cf8
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_068cf8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x00E4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068CF8ULL;
}

// FDE #1240 | PC: 0x068ddc..0x068eb8 (220 B) | Symbol: sub_068ddc
// EN: AArch64 prologue [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x24, x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_068ddc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xA9BC5FF8ULL;
    const uint64_t kPcRange = 0x00DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068DDCULL;
}

// FDE #1241 | PC: 0x068eb8..0x068f6c (180 B) | Symbol: sub_068eb8
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_068eb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x00B4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068EB8ULL;
}

// FDE #1242 | PC: 0x068f6c..0x069018 (172 B) | Symbol: sub_068f6c
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_068f6c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x068F6CULL;
}

// FDE #1243 | PC: 0x069018..0x069068 (80 B) | Symbol: sub_069018
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x19, x1]
uint64_t fde_sub_069018(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069018ULL;
}

// FDE #1244 | PC: 0x069068..0x0690d0 (104 B) | Symbol: sub_069068
// EN: AArch64 prologue [cbz x0, #0x690cc; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10] | VI: Khởi đầu hàm AArch64 [cbz x0, #0x690cc; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10]
uint64_t fde_sub_069068(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF81E0FF3ULL) << 32) | 0xB4000320ULL;
    const uint64_t kPcRange = 0x0068ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069068ULL;
}

// FDE #1245 | PC: 0x0690d0..0x069234 (356 B) | Symbol: sub_0690d0
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0690d0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0164ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0690D0ULL;
}

// FDE #1246 | PC: 0x069234..0x069248 (20 B) | Symbol: sub_069234
// EN: AArch64 prologue [ldr x8, [x0, #0x370]; add x1, x1, #0x16c; mov w2, #8; ldr x0, [x8, #0x40a0]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x370]; add x1, x1, #0x16c; mov w2, #8; ldr x0, [x8, #0x40a0]]
uint64_t fde_sub_069234(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x9105B021ULL) << 32) | 0xF941B808ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069234ULL;
}

// FDE #1247 | PC: 0x069248..0x069368 (288 B) | Symbol: sub_069248
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w2, [x1, #0x51c]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w2, [x1, #0x51c]]
uint64_t fde_sub_069248(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0120ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069248ULL;
}

// FDE #1248 | PC: 0x069368..0x0694c0 (344 B) | Symbol: sub_069368
// EN: AArch64 prologue [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_069368(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xF81B0FF9ULL;
    const uint64_t kPcRange = 0x0158ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069368ULL;
}

// FDE #1249 | PC: 0x0694c0..0x0697c0 (768 B) | Symbol: sub_0694c0
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0694c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x0300ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0694C0ULL;
}

// FDE #1250 | PC: 0x0697c0..0x0698fc (316 B) | Symbol: sub_0697c0
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_0697c0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x013CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0697C0ULL;
}

// FDE #1251 | PC: 0x0698fc..0x0699bc (192 B) | Symbol: sub_0698fc
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_0698fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x00C0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0698FCULL;
}

// FDE #1252 | PC: 0x0699bc..0x069a68 (172 B) | Symbol: sub_0699bc
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0, #0x880]; cmp x8, #1] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; ldr x8, [x0, #0x880]; cmp x8, #1]
uint64_t fde_sub_0699bc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x0699BCULL;
}

// FDE #1253 | PC: 0x069a68..0x069a90 (40 B) | Symbol: sub_069a68
// EN: AArch64 prologue [mov x8, x0; ldr w0, [x0, #0xa10]; sub w9, w0, #4; cmp w9, #2] | VI: Khởi đầu hàm AArch64 [mov x8, x0; ldr w0, [x0, #0xa10]; sub w9, w0, #4; cmp w9, #2]
uint64_t fde_sub_069a68(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB94A1000ULL) << 32) | 0xAA0003E8ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069A68ULL;
}

// FDE #1254 | PC: 0x069a90..0x069aa4 (20 B) | Symbol: sub_069a90
// EN: AArch64 prologue [sub w8, w0, #4; cmp w8, #3; mov w8, #-0x291; csel w0, wzr, w8, lo] | VI: Khởi đầu hàm AArch64 [sub w8, w0, #4; cmp w8, #3; mov w8, #-0x291; csel w0, wzr, w8, lo]
uint64_t fde_sub_069a90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x71000D1FULL) << 32) | 0x51001008ULL;
    const uint64_t kPcRange = 0x0014ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069A90ULL;
}

// FDE #1255 | PC: 0x069aa4..0x069aec (72 B) | Symbol: sub_069aa4
// EN: AArch64 prologue [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [str x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_069aa4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xF81D0FF5ULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069AA4ULL;
}

// FDE #1256 | PC: 0x069aec..0x069b20 (52 B) | Symbol: sub_069aec
// EN: AArch64 prologue [add x8, x0, #0xf50; add x9, x0, #0xf58; ldr x9, [x9]; cmp x9, x8] | VI: Khởi đầu hàm AArch64 [add x8, x0, #0xf50; add x9, x0, #0xf58; ldr x9, [x9]; cmp x9, x8]
uint64_t fde_sub_069aec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x913D6009ULL) << 32) | 0x913D4008ULL;
    const uint64_t kPcRange = 0x0034ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069AECULL;
}

// FDE #1257 | PC: 0x069b20..0x069b8c (108 B) | Symbol: sub_069b20
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; add x8, x0, #0xf50] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; add x8, x0, #0xf50]
uint64_t fde_sub_069b20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069B20ULL;
}

// FDE #1258 | PC: 0x069b8c..0x069bcc (64 B) | Symbol: sub_069b8c
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0xf58]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0xf58]]
uint64_t fde_sub_069b8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069B8CULL;
}

// FDE #1259 | PC: 0x069bcc..0x069c04 (56 B) | Symbol: sub_069bcc
// EN: AArch64 prologue [add x8, x0, #0xf50; add x10, x0, #0xf58; ldr x9, [x10]; cmp x9, x8] | VI: Khởi đầu hàm AArch64 [add x8, x0, #0xf50; add x10, x0, #0xf58; ldr x9, [x10]; cmp x9, x8]
uint64_t fde_sub_069bcc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x913D600AULL) << 32) | 0x913D4008ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069BCCULL;
}

// FDE #1260 | PC: 0x069c04..0x069c80 (124 B) | Symbol: sub_069c04
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_069c04(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x007CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069C04ULL;
}

// FDE #1261 | PC: 0x069c80..0x069d2c (172 B) | Symbol: sub_069c80
// EN: AArch64 prologue [ldr w8, [x0, #0xf40]; str w8, [x1, #0x74]; ldr w8, [x0, #0xf68]; cmp w8, #2] | VI: Khởi đầu hàm AArch64 [ldr w8, [x0, #0xf40]; str w8, [x1, #0x74]; ldr w8, [x0, #0xf68]; cmp w8, #2]
uint64_t fde_sub_069c80(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9007428ULL) << 32) | 0xB94F4008ULL;
    const uint64_t kPcRange = 0x00ACULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069C80ULL;
}

// FDE #1262 | PC: 0x069d2c..0x069ea0 (372 B) | Symbol: sub_069d2c
// EN: AArch64 prologue [adrp x8, #0x7e000; ldr q0, [x8, #0xa0]; add x14, x0, #0xf50; stur q0, [x2, #0xa4]] | VI: Khởi đầu hàm AArch64 [adrp x8, #0x7e000; ldr q0, [x8, #0xa0]; add x14, x0, #0xf50; stur q0, [x2, #0xa4]]
uint64_t fde_sub_069d2c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x3DC02900ULL) << 32) | 0xB00000A8ULL;
    const uint64_t kPcRange = 0x0174ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069D2CULL;
}

// FDE #1263 | PC: 0x069ea0..0x06a090 (496 B) | Symbol: sub_069ea0
// EN: AArch64 prologue [sub sp, sp, #0xf0; str d8, [sp, #0x80]; stp x28, x27, [sp, #0x90]; stp x26, x25, [sp, #0xa0]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0xf0; str d8, [sp, #0x80]; stp x28, x27, [sp, #0x90]; stp x26, x25, [sp, #0xa0]]
uint64_t fde_sub_069ea0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xFD0043E8ULL) << 32) | 0xD103C3FFULL;
    const uint64_t kPcRange = 0x01F0ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x069EA0ULL;
}

// FDE #1264 | PC: 0x06a090..0x06a134 (164 B) | Symbol: sub_06a090
// EN: AArch64 prologue [sub sp, sp, #0x110; stp x28, x19, [sp, #0xf0]; stp x29, x30, [sp, #0x100]; add x29, sp, #0x100] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; stp x28, x19, [sp, #0xf0]; stp x29, x30, [sp, #0x100]; add x29, sp, #0x100]
uint64_t fde_sub_06a090(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90F4FFCULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A090ULL;
}

// FDE #1265 | PC: 0x06a134..0x06a310 (476 B) | Symbol: sub_06a134
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x1, #0x114]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrb w8, [x1, #0x114]]
uint64_t fde_sub_06a134(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x01DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A134ULL;
}

// FDE #1266 | PC: 0x06a310..0x06a338 (40 B) | Symbol: sub_06a310
// EN: AArch64 prologue [ldr x8, [x2, #0xd8]; cmp x8, #7; b.hi #0x6a334; mov w9, #0x58] | VI: Khởi đầu hàm AArch64 [ldr x8, [x2, #0xd8]; cmp x8, #7; b.hi #0x6a334; mov w9, #0x58]
uint64_t fde_sub_06a310(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF1001D1FULL) << 32) | 0xF9406C48ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A310ULL;
}

// FDE #1267 | PC: 0x06a338..0x06a3a4 (108 B) | Symbol: sub_06a338
// EN: AArch64 prologue [mov x9, x1; ldr x8, [x9, #0x80]!; ldr x10, [x9, #8]; str x8, [x10]] | VI: Khởi đầu hàm AArch64 [mov x9, x1; ldr x8, [x9, #0x80]!; ldr x10, [x9, #8]; str x8, [x10]]
uint64_t fde_sub_06a338(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF8480D28ULL) << 32) | 0xAA0103E9ULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A338ULL;
}

// FDE #1268 | PC: 0x06a3a4..0x06a3f4 (80 B) | Symbol: sub_06a3a4
// EN: AArch64 prologue [mov x9, x1; ldr x8, [x9, #0x80]!; ldr x10, [x9, #8]; str x8, [x10]] | VI: Khởi đầu hàm AArch64 [mov x9, x1; ldr x8, [x9, #0x80]!; ldr x10, [x9, #8]; str x8, [x10]]
uint64_t fde_sub_06a3a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF8480D28ULL) << 32) | 0xAA0103E9ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A3A4ULL;
}

// FDE #1269 | PC: 0x06a3f4..0x06a474 (128 B) | Symbol: sub_06a3f4
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrh w8, [x0]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldrh w8, [x0]]
uint64_t fde_sub_06a3f4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0080ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A3F4ULL;
}

// FDE #1270 | PC: 0x06a474..0x06a56c (248 B) | Symbol: sub_06a474
// EN: AArch64 prologue [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [str x23, [sp, #-0x40]!; stp x22, x21, [sp, #0x10]; stp x20, x19, [sp, #0x20]; stp x29, x30, [sp, #0x30]]
uint64_t fde_sub_06a474(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90157F6ULL) << 32) | 0xF81C0FF7ULL;
    const uint64_t kPcRange = 0x00F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A474ULL;
}

// FDE #1271 | PC: 0x06a56c..0x06a730 (452 B) | Symbol: sub_06a56c
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_06a56c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x01C4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A56CULL;
}

// FDE #1272 | PC: 0x06a730..0x06a78c (92 B) | Symbol: sub_06a730
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w2, [x0, #0x51c]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w2, [x0, #0x51c]]
uint64_t fde_sub_06a730(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x005CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A730ULL;
}

// FDE #1273 | PC: 0x06a78c..0x06a794 (8 B) | Symbol: sub_06a78c
// EN: AArch64 prologue [ldr x0, [x0, #0x200]; b #0x54c24] | VI: Khởi đầu hàm AArch64 [ldr x0, [x0, #0x200]; b #0x54c24]
uint64_t fde_sub_06a78c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFA925ULL) << 32) | 0xF9410000ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A78CULL;
}

// FDE #1274 | PC: 0x06a794..0x06a84c (184 B) | Symbol: sub_06a794
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0x168]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr w8, [x0, #0x168]]
uint64_t fde_sub_06a794(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x00B8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A794ULL;
}

// FDE #1275 | PC: 0x06a84c..0x06ab44 (760 B) | Symbol: sub_06a84c
// EN: AArch64 prologue [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [stp x26, x25, [sp, #-0x50]!; stp x24, x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_06a84c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9015FF8ULL) << 32) | 0xA9BB67FAULL;
    const uint64_t kPcRange = 0x02F8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06A84CULL;
}

// FDE #1276 | PC: 0x06ab44..0x06ab60 (28 B) | Symbol: sub_06ab44
// EN: AArch64 prologue [ldr x8, [x0, #0x200]; ldr x9, [x0]; ldr x8, [x8, #0xf48]; ldr x8, [x8]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x0, #0x200]; ldr x9, [x0]; ldr x8, [x8, #0xf48]; ldr x8, [x8]]
uint64_t fde_sub_06ab44(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9400009ULL) << 32) | 0xF9410008ULL;
    const uint64_t kPcRange = 0x001CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AB44ULL;
}

// FDE #1277 | PC: 0x06ab60..0x06ac34 (212 B) | Symbol: sub_06ab60
// EN: AArch64 prologue [cbz x1, #0x6ac30; movi v0.2d, #0000000000000000; stp q0, q0, [x1, #0x40]; stp q0, q0, [x1, #0x20]] | VI: Khởi đầu hàm AArch64 [cbz x1, #0x6ac30; movi v0.2d, #0000000000000000; stp q0, q0, [x1, #0x40]; stp q0, q0, [x1, #0x20]]
uint64_t fde_sub_06ab60(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x6F00E400ULL) << 32) | 0xB4000681ULL;
    const uint64_t kPcRange = 0x00D4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AB60ULL;
}

// FDE #1278 | PC: 0x06ac34..0x06ac88 (84 B) | Symbol: sub_06ac34
// EN: AArch64 prologue [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0x198]] | VI: Khởi đầu hàm AArch64 [stp x20, x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x0, #0x198]]
uint64_t fde_sub_06ac34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xA9BE4FF4ULL;
    const uint64_t kPcRange = 0x0054ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AC34ULL;
}

// FDE #1279 | PC: 0x06ac88..0x06add4 (332 B) | Symbol: sub_06ac88
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06ac88(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x014CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06AC88ULL;
}

// FDE #1280 | PC: 0x06add4..0x06b8fc (2856 B) | Symbol: sub_06add4
// EN: AArch64 prologue [sub sp, sp, #0x60; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x60; stp x26, x25, [sp, #0x10]; stp x24, x23, [sp, #0x20]; stp x22, x21, [sp, #0x30]]
uint64_t fde_sub_06add4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90167FAULL) << 32) | 0xD10183FFULL;
    const uint64_t kPcRange = 0x0B28ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06ADD4ULL;
}

// FDE #1281 | PC: 0x06b8fc..0x06b944 (72 B) | Symbol: sub_06b8fc
// EN: AArch64 prologue [cmp w1, #1; b.ne #0x6b93c; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]] | VI: Khởi đầu hàm AArch64 [cmp w1, #1; b.ne #0x6b93c; str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]]
uint64_t fde_sub_06b8fc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x540001E1ULL) << 32) | 0x7100043FULL;
    const uint64_t kPcRange = 0x0048ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B8FCULL;
}

// FDE #1282 | PC: 0x06b944..0x06b970 (44 B) | Symbol: sub_06b944
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x2; mov x1, x3] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x2; mov x1, x3]
uint64_t fde_sub_06b944(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B944ULL;
}

// FDE #1283 | PC: 0x06b970..0x06b9b4 (68 B) | Symbol: sub_06b970
// EN: AArch64 prologue [cmp w1, #1; b.ne #0x6b9ac; sub x9, x3, x2; mov x8, x0] | VI: Khởi đầu hàm AArch64 [cmp w1, #1; b.ne #0x6b9ac; sub x9, x3, x2; mov x8, x0]
uint64_t fde_sub_06b970(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x540001C1ULL) << 32) | 0x7100043FULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B970ULL;
}

// FDE #1284 | PC: 0x06b9b4..0x06b9e0 (44 B) | Symbol: sub_06b9b4
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x2; mov x1, x3] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x2; mov x1, x3]
uint64_t fde_sub_06b9b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B9B4ULL;
}

// FDE #1285 | PC: 0x06b9e0..0x06ba0c (44 B) | Symbol: sub_06b9e0
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x2; mov x1, x3] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x2; mov x1, x3]
uint64_t fde_sub_06b9e0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06B9E0ULL;
}

// FDE #1286 | PC: 0x06ba0c..0x06ba38 (44 B) | Symbol: sub_06ba0c
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x2; mov x1, x3] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x2; mov x1, x3]
uint64_t fde_sub_06ba0c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BA0CULL;
}

// FDE #1287 | PC: 0x06ba38..0x06ba64 (44 B) | Symbol: sub_06ba38
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x2; mov x1, x3] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x2; mov x1, x3]
uint64_t fde_sub_06ba38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BA38ULL;
}

// FDE #1288 | PC: 0x06ba64..0x06ba90 (44 B) | Symbol: sub_06ba64
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x2; mov x1, x3] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x2; mov x1, x3]
uint64_t fde_sub_06ba64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BA64ULL;
}

// FDE #1289 | PC: 0x06ba90..0x06babc (44 B) | Symbol: sub_06ba90
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x2; mov x1, x3] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x2; mov x1, x3]
uint64_t fde_sub_06ba90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BA90ULL;
}

// FDE #1290 | PC: 0x06babc..0x06bae8 (44 B) | Symbol: sub_06babc
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x2; mov x1, x3] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x2; mov x1, x3]
uint64_t fde_sub_06babc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BABCULL;
}

// FDE #1291 | PC: 0x06bae8..0x06bb38 (80 B) | Symbol: sub_06bae8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; add x19, x0, #0xf0] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; add x19, x0, #0xf0]
uint64_t fde_sub_06bae8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0050ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BAE8ULL;
}

// FDE #1292 | PC: 0x06bb38..0x06bb64 (44 B) | Symbol: sub_06bb38
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x2; mov x1, x3] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x2; mov x1, x3]
uint64_t fde_sub_06bb38(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BB38ULL;
}

// FDE #1293 | PC: 0x06bb64..0x06bb74 (16 B) | Symbol: sub_06bb64
// EN: AArch64 prologue [mov w8, #1; str x8, [x0, #0x100]; mov w0, wzr; ret] | VI: Khởi đầu hàm AArch64 [mov w8, #1; str x8, [x0, #0x100]; mov w0, wzr; ret]
uint64_t fde_sub_06bb64(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9008008ULL) << 32) | 0x52800028ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BB64ULL;
}

// FDE #1294 | PC: 0x06bb74..0x06bc8c (280 B) | Symbol: sub_06bb74
// EN: AArch64 prologue [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [stp x22, x21, [sp, #-0x30]!; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06bb74(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xA9BD57F6ULL;
    const uint64_t kPcRange = 0x0118ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BB74ULL;
}

// FDE #1295 | PC: 0x06bc8c..0x06bcb8 (44 B) | Symbol: sub_06bc8c
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x2; mov x1, x3] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x2; mov x1, x3]
uint64_t fde_sub_06bc8c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BC8CULL;
}

// FDE #1296 | PC: 0x06bcb8..0x06bcf0 (56 B) | Symbol: sub_06bcb8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x1, x2] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x1, x2]
uint64_t fde_sub_06bcb8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BCB8ULL;
}

// FDE #1297 | PC: 0x06bcf0..0x06bd28 (56 B) | Symbol: sub_06bcf0
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x1, x2] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov x1, x2]
uint64_t fde_sub_06bcf0(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0038ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BCF0ULL;
}

// FDE #1298 | PC: 0x06bd28..0x06bdf4 (204 B) | Symbol: sub_06bd28
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, #0x6d04; movk x8, #0x1b66, lsl #16] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, #0x6d04; movk x8, #0x1b66, lsl #16]
uint64_t fde_sub_06bd28(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x00CCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BD28ULL;
}

// FDE #1299 | PC: 0x06bdf4..0x06be20 (44 B) | Symbol: sub_06bdf4
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x2; mov x1, x3] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x2; mov x1, x3]
uint64_t fde_sub_06bdf4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BDF4ULL;
}

// FDE #1300 | PC: 0x06be20..0x06be90 (112 B) | Symbol: sub_06be20
// EN: AArch64 prologue [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x30; stp x20, x19, [sp, #0x10]; stp x29, x30, [sp, #0x20]; add x29, sp, #0x20]
uint64_t fde_sub_06be20(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9014FF4ULL) << 32) | 0xD100C3FFULL;
    const uint64_t kPcRange = 0x0070ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BE20ULL;
}

// FDE #1301 | PC: 0x06be90..0x06bebc (44 B) | Symbol: sub_06be90
// EN: AArch64 prologue [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x2; mov x1, x3] | VI: Khởi đầu hàm AArch64 [stp x29, x30, [sp, #-0x10]!; mov x29, sp; mov x8, x2; mov x1, x3]
uint64_t fde_sub_06be90(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x910003FDULL) << 32) | 0xA9BF7BFDULL;
    const uint64_t kPcRange = 0x002CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BE90ULL;
}

// FDE #1302 | PC: 0x06bebc..0x06bf34 (120 B) | Symbol: sub_06bebc
// EN: AArch64 prologue [cmp x0, #0x11; b.hs #0x6bec8; ret; mov x8, #0x6d03] | VI: Khởi đầu hàm AArch64 [cmp x0, #0x11; b.hs #0x6bec8; ret; mov x8, #0x6d03]
uint64_t fde_sub_06bebc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x54000042ULL) << 32) | 0xF100441FULL;
    const uint64_t kPcRange = 0x0078ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BEBCULL;
}

// FDE #1303 | PC: 0x06bf34..0x06c0dc (424 B) | Symbol: sub_06bf34
// EN: AArch64 prologue [sub sp, sp, #0x80; str x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; str x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_06bf34(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF90013FBULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x01A8ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06BF34ULL;
}

// FDE #1304 | PC: 0x06c0dc..0x06c2b8 (476 B) | Symbol: sub_06c0dc
// EN: AArch64 prologue [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x80; stp x28, x27, [sp, #0x20]; stp x26, x25, [sp, #0x30]; stp x24, x23, [sp, #0x40]]
uint64_t fde_sub_06c0dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9026FFCULL) << 32) | 0xD10203FFULL;
    const uint64_t kPcRange = 0x01DCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C0DCULL;
}

// FDE #1305 | PC: 0x06c2b8..0x06c3b4 (252 B) | Symbol: sub_06c2b8
// EN: AArch64 prologue [sub sp, sp, #0x170; str x28, [sp, #0x130]; stp x22, x21, [sp, #0x140]; stp x20, x19, [sp, #0x150]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x170; str x28, [sp, #0x130]; stp x22, x21, [sp, #0x140]; stp x20, x19, [sp, #0x150]]
uint64_t fde_sub_06c2b8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9009BFCULL) << 32) | 0xD105C3FFULL;
    const uint64_t kPcRange = 0x00FCULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C2B8ULL;
}

// FDE #1306 | PC: 0x06c3b4..0x06c458 (164 B) | Symbol: sub_06c3b4
// EN: AArch64 prologue [sub sp, sp, #0x110; stp x28, x19, [sp, #0xf0]; stp x29, x30, [sp, #0x100]; add x29, sp, #0x100] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x110; stp x28, x19, [sp, #0xf0]; stp x29, x30, [sp, #0x100]; add x29, sp, #0x100]
uint64_t fde_sub_06c3b4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA90F4FFCULL) << 32) | 0xD10443FFULL;
    const uint64_t kPcRange = 0x00A4ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C3B4ULL;
}

// FDE #1307 | PC: 0x06c458..0x06c49c (68 B) | Symbol: sub_06c458
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w2, #0x240] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; mov w2, #0x240]
uint64_t fde_sub_06c458(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x0044ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C458ULL;
}

// FDE #1308 | PC: 0x06c49c..0x06c4dc (64 B) | Symbol: sub_06c49c
// EN: AArch64 prologue [ldp x9, x8, [x2]; mov w12, #8; lsl w12, w12, w0; ldr w10, [x8, #0x174]] | VI: Khởi đầu hàm AArch64 [ldp x9, x8, [x2]; mov w12, #8; lsl w12, w12, w0; ldr w10, [x8, #0x174]]
uint64_t fde_sub_06c49c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x5280010CULL) << 32) | 0xA9402049ULL;
    const uint64_t kPcRange = 0x0040ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C49CULL;
}

// FDE #1309 | PC: 0x06c4dc..0x06c5e4 (264 B) | Symbol: sub_06c4dc
// EN: AArch64 prologue [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]] | VI: Khởi đầu hàm AArch64 [sub sp, sp, #0x50; str x23, [sp, #0x10]; stp x22, x21, [sp, #0x20]; stp x20, x19, [sp, #0x30]]
uint64_t fde_sub_06c4dc(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9000BF7ULL) << 32) | 0xD10143FFULL;
    const uint64_t kPcRange = 0x0108ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C4DCULL;
}

// FDE #1310 | PC: 0x06c5e4..0x06c5ec (8 B) | Symbol: sub_06c5e4
// EN: AArch64 prologue [add x0, x2, #0x3b8; b #0x68574] | VI: Khởi đầu hàm AArch64 [add x0, x2, #0x3b8; b #0x68574]
uint64_t fde_sub_06c5e4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0x17FFEFE3ULL) << 32) | 0x910EE040ULL;
    const uint64_t kPcRange = 0x0008ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C5E4ULL;
}

// FDE #1311 | PC: 0x06c5ec..0x06c5f8 (12 B) | Symbol: sub_06c5ec
// EN: AArch64 prologue [ldr x8, [x2, #8]; str xzr, [x8, #0x160]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x2, #8]; str xzr, [x8, #0x160]; ret]
uint64_t fde_sub_06c5ec(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF900B11FULL) << 32) | 0xF9400448ULL;
    const uint64_t kPcRange = 0x000CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C5ECULL;
}

// FDE #1312 | PC: 0x06c5f8..0x06c664 (108 B) | Symbol: sub_06c5f8
// EN: AArch64 prologue [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x2]] | VI: Khởi đầu hàm AArch64 [str x19, [sp, #-0x20]!; stp x29, x30, [sp, #0x10]; add x29, sp, #0x10; ldr x8, [x2]]
uint64_t fde_sub_06c5f8(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xA9017BFDULL) << 32) | 0xF81E0FF3ULL;
    const uint64_t kPcRange = 0x006CULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C5F8ULL;
}

// FDE #1313 | PC: 0x06c664..0x06c67c (24 B) | Symbol: sub_06c664
// EN: AArch64 prologue [ldr x0, [x2, #8]; ldr w8, [x0, #0x168]; cmp w8, #3; b.hi #0x6c678] | VI: Khởi đầu hàm AArch64 [ldr x0, [x2, #8]; ldr w8, [x0, #0x168]; cmp w8, #3; b.hi #0x6c678]
uint64_t fde_sub_06c664(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB9416808ULL) << 32) | 0xF9400440ULL;
    const uint64_t kPcRange = 0x0018ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C664ULL;
}

// FDE #1314 | PC: 0x06c67c..0x06c6a4 (40 B) | Symbol: sub_06c67c
// EN: AArch64 prologue [ldr x8, [x2, #0xac0]; ldr x9, [x2, #0xf38]; orr x8, x8, #0x20; str x8, [x2, #0xac0]] | VI: Khởi đầu hàm AArch64 [ldr x8, [x2, #0xac0]; ldr x9, [x2, #0xf38]; orr x8, x8, #0x20; str x8, [x2, #0xac0]]
uint64_t fde_sub_06c67c(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xF9479C49ULL) << 32) | 0xF9456048ULL;
    const uint64_t kPcRange = 0x0028ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C67CULL;
}

// FDE #1315 | PC: 0x06c6a4..0x06c6b4 (16 B) | Symbol: sub_06c6a4
// EN: AArch64 prologue [ldr x8, [x2, #0xac0]; orr x8, x8, #0x20; str x8, [x2, #0xac0]; ret] | VI: Khởi đầu hàm AArch64 [ldr x8, [x2, #0xac0]; orr x8, x8, #0x20; str x8, [x2, #0xac0]; ret]
uint64_t fde_sub_06c6a4(uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    const uint64_t kOpcodePrologue = (static_cast<uint64_t>(0xB27B0108ULL) << 32) | 0xF9456048ULL;
    const uint64_t kPcRange = 0x0010ULL;
    uint64_t state = (a0 ^ kOpcodePrologue) + (a1 * 0x9E3779B97F4A7C15ULL) + (a2 ^ kPcRange);
    state ^= (state >> 30);
    state *= 0xBF58476D1CE4E5B9ULL;
    state ^= (state >> 27);
    return state ^ 0x06C6A4ULL;
}

uint64_t DispatchTtkMediaNetShard4(uint64_t fde_pc_begin, uint64_t a0, uint64_t a1, uint64_t a2) noexcept {
    switch (fde_pc_begin) {
        case 0x056b00ULL: return fde_sub_056b00(a0, a1, a2);
        case 0x056b5cULL: return fde_sub_056b5c(a0, a1, a2);
        case 0x056c44ULL: return fde_sub_056c44(a0, a1, a2);
        case 0x056c9cULL: return fde_sub_056c9c(a0, a1, a2);
        case 0x056d94ULL: return fde_sub_056d94(a0, a1, a2);
        case 0x056e90ULL: return fde_sub_056e90(a0, a1, a2);
        case 0x056ed4ULL: return fde_sub_056ed4(a0, a1, a2);
        case 0x056f00ULL: return fde_sub_056f00(a0, a1, a2);
        case 0x056f20ULL: return fde_sub_056f20(a0, a1, a2);
        case 0x056f6cULL: return fde_sub_056f6c(a0, a1, a2);
        case 0x0571b4ULL: return fde_sub_0571b4(a0, a1, a2);
        case 0x05736cULL: return fde_sub_05736c(a0, a1, a2);
        case 0x057684ULL: return fde_sub_057684(a0, a1, a2);
        case 0x057694ULL: return fde_sub_057694(a0, a1, a2);
        case 0x0579c4ULL: return fde_sub_0579c4(a0, a1, a2);
        case 0x057be0ULL: return fde_sub_057be0(a0, a1, a2);
        case 0x057e48ULL: return fde_sub_057e48(a0, a1, a2);
        case 0x05815cULL: return fde_sub_05815c(a0, a1, a2);
        case 0x05824cULL: return fde_sub_05824c(a0, a1, a2);
        case 0x058344ULL: return fde_sub_058344(a0, a1, a2);
        case 0x05836cULL: return fde_sub_05836c(a0, a1, a2);
        case 0x0583f8ULL: return fde_sub_0583f8(a0, a1, a2);
        case 0x0584b4ULL: return fde_sub_0584b4(a0, a1, a2);
        case 0x0585d8ULL: return fde_sub_0585d8(a0, a1, a2);
        case 0x058a68ULL: return fde_sub_058a68(a0, a1, a2);
        case 0x058bd8ULL: return fde_sub_058bd8(a0, a1, a2);
        case 0x058d80ULL: return fde_sub_058d80(a0, a1, a2);
        case 0x058eacULL: return fde_sub_058eac(a0, a1, a2);
        case 0x058f30ULL: return fde_sub_058f30(a0, a1, a2);
        case 0x058f60ULL: return fde_sub_058f60(a0, a1, a2);
        case 0x058fbcULL: return fde_sub_058fbc(a0, a1, a2);
        case 0x058fdcULL: return fde_sub_058fdc(a0, a1, a2);
        case 0x0593a8ULL: return fde_sub_0593a8(a0, a1, a2);
        case 0x05956cULL: return fde_sub_05956c(a0, a1, a2);
        case 0x0596e8ULL: return fde_sub_0596e8(a0, a1, a2);
        case 0x0597c8ULL: return fde_sub_0597c8(a0, a1, a2);
        case 0x0599a0ULL: return fde_sub_0599a0(a0, a1, a2);
        case 0x059a44ULL: return fde_sub_059a44(a0, a1, a2);
        case 0x059ba0ULL: return fde_sub_059ba0(a0, a1, a2);
        case 0x059c2cULL: return fde_sub_059c2c(a0, a1, a2);
        case 0x059ce8ULL: return fde_sub_059ce8(a0, a1, a2);
        case 0x059d48ULL: return fde_sub_059d48(a0, a1, a2);
        case 0x059e70ULL: return fde_sub_059e70(a0, a1, a2);
        case 0x059efcULL: return fde_sub_059efc(a0, a1, a2);
        case 0x059fc0ULL: return fde_sub_059fc0(a0, a1, a2);
        case 0x05a030ULL: return fde_sub_05a030(a0, a1, a2);
        case 0x05a0ecULL: return fde_sub_05a0ec(a0, a1, a2);
        case 0x05a14cULL: return fde_sub_05a14c(a0, a1, a2);
        case 0x05a274ULL: return fde_sub_05a274(a0, a1, a2);
        case 0x05a300ULL: return fde_sub_05a300(a0, a1, a2);
        case 0x05a3c4ULL: return fde_sub_05a3c4(a0, a1, a2);
        case 0x05a434ULL: return fde_sub_05a434(a0, a1, a2);
        case 0x05a538ULL: return fde_sub_05a538(a0, a1, a2);
        case 0x05a65cULL: return fde_sub_05a65c(a0, a1, a2);
        case 0x05a6bcULL: return fde_sub_05a6bc(a0, a1, a2);
        case 0x05a6dcULL: return fde_sub_05a6dc(a0, a1, a2);
        case 0x05a890ULL: return fde_sub_05a890(a0, a1, a2);
        case 0x05a960ULL: return fde_sub_05a960(a0, a1, a2);
        case 0x05aa1cULL: return fde_sub_05aa1c(a0, a1, a2);
        case 0x05aa7cULL: return fde_sub_05aa7c(a0, a1, a2);
        case 0x05aaf4ULL: return fde_sub_05aaf4(a0, a1, a2);
        case 0x05ab30ULL: return fde_sub_05ab30(a0, a1, a2);
        case 0x05aba8ULL: return fde_sub_05aba8(a0, a1, a2);
        case 0x05abe4ULL: return fde_sub_05abe4(a0, a1, a2);
        case 0x05b088ULL: return fde_sub_05b088(a0, a1, a2);
        case 0x05b284ULL: return fde_sub_05b284(a0, a1, a2);
        case 0x05b434ULL: return fde_sub_05b434(a0, a1, a2);
        case 0x05b52cULL: return fde_sub_05b52c(a0, a1, a2);
        case 0x05b74cULL: return fde_sub_05b74c(a0, a1, a2);
        case 0x05b848ULL: return fde_sub_05b848(a0, a1, a2);
        case 0x05b9ccULL: return fde_sub_05b9cc(a0, a1, a2);
        case 0x05bab8ULL: return fde_sub_05bab8(a0, a1, a2);
        case 0x05bc3cULL: return fde_sub_05bc3c(a0, a1, a2);
        case 0x05bd28ULL: return fde_sub_05bd28(a0, a1, a2);
        case 0x05bdb8ULL: return fde_sub_05bdb8(a0, a1, a2);
        case 0x05bf58ULL: return fde_sub_05bf58(a0, a1, a2);
        case 0x05c050ULL: return fde_sub_05c050(a0, a1, a2);
        case 0x05c090ULL: return fde_sub_05c090(a0, a1, a2);
        case 0x05c0ecULL: return fde_sub_05c0ec(a0, a1, a2);
        case 0x05c314ULL: return fde_sub_05c314(a0, a1, a2);
        case 0x05c458ULL: return fde_sub_05c458(a0, a1, a2);
        case 0x05c4b4ULL: return fde_sub_05c4b4(a0, a1, a2);
        case 0x05c7e4ULL: return fde_sub_05c7e4(a0, a1, a2);
        case 0x05ca74ULL: return fde_sub_05ca74(a0, a1, a2);
        case 0x05cae0ULL: return fde_sub_05cae0(a0, a1, a2);
        case 0x05cb3cULL: return fde_sub_05cb3c(a0, a1, a2);
        case 0x05ccb8ULL: return fde_sub_05ccb8(a0, a1, a2);
        case 0x05cfccULL: return fde_sub_05cfcc(a0, a1, a2);
        case 0x05d0e8ULL: return fde_sub_05d0e8(a0, a1, a2);
        case 0x05d11cULL: return fde_sub_05d11c(a0, a1, a2);
        case 0x05d3bcULL: return fde_sub_05d3bc(a0, a1, a2);
        case 0x05d594ULL: return fde_sub_05d594(a0, a1, a2);
        case 0x05d788ULL: return fde_sub_05d788(a0, a1, a2);
        case 0x05d968ULL: return fde_sub_05d968(a0, a1, a2);
        case 0x05da10ULL: return fde_sub_05da10(a0, a1, a2);
        case 0x05dc94ULL: return fde_sub_05dc94(a0, a1, a2);
        case 0x05dc9cULL: return fde_sub_05dc9c(a0, a1, a2);
        case 0x05e380ULL: return fde_sub_05e380(a0, a1, a2);
        case 0x05e4b4ULL: return fde_sub_05e4b4(a0, a1, a2);
        case 0x05e5b4ULL: return fde_sub_05e5b4(a0, a1, a2);
        case 0x05e6b0ULL: return fde_sub_05e6b0(a0, a1, a2);
        case 0x05e81cULL: return fde_sub_05e81c(a0, a1, a2);
        case 0x05e988ULL: return fde_sub_05e988(a0, a1, a2);
        case 0x05e990ULL: return fde_sub_05e990(a0, a1, a2);
        case 0x05e9a8ULL: return fde_sub_05e9a8(a0, a1, a2);
        case 0x05ea34ULL: return fde_sub_05ea34(a0, a1, a2);
        case 0x05ea68ULL: return fde_sub_05ea68(a0, a1, a2);
        case 0x05eb98ULL: return fde_sub_05eb98(a0, a1, a2);
        case 0x05ee8cULL: return fde_sub_05ee8c(a0, a1, a2);
        case 0x05f340ULL: return fde_sub_05f340(a0, a1, a2);
        case 0x05f364ULL: return fde_sub_05f364(a0, a1, a2);
        case 0x05f388ULL: return fde_sub_05f388(a0, a1, a2);
        case 0x05f3c0ULL: return fde_sub_05f3c0(a0, a1, a2);
        case 0x05f494ULL: return fde_sub_05f494(a0, a1, a2);
        case 0x05f4c0ULL: return fde_sub_05f4c0(a0, a1, a2);
        case 0x05f4fcULL: return fde_sub_05f4fc(a0, a1, a2);
        case 0x05f5f4ULL: return fde_sub_05f5f4(a0, a1, a2);
        case 0x05f704ULL: return fde_sub_05f704(a0, a1, a2);
        case 0x05f760ULL: return fde_sub_05f760(a0, a1, a2);
        case 0x05f788ULL: return fde_sub_05f788(a0, a1, a2);
        case 0x05f7bcULL: return fde_sub_05f7bc(a0, a1, a2);
        case 0x05f8ecULL: return fde_sub_05f8ec(a0, a1, a2);
        case 0x05f9f4ULL: return fde_sub_05f9f4(a0, a1, a2);
        case 0x05fb0cULL: return fde_sub_05fb0c(a0, a1, a2);
        case 0x05fcb8ULL: return fde_sub_05fcb8(a0, a1, a2);
        case 0x05fe68ULL: return fde_sub_05fe68(a0, a1, a2);
        case 0x06010cULL: return fde_sub_06010c(a0, a1, a2);
        case 0x06021cULL: return fde_sub_06021c(a0, a1, a2);
        case 0x060314ULL: return fde_sub_060314(a0, a1, a2);
        case 0x0603e4ULL: return fde_sub_0603e4(a0, a1, a2);
        case 0x06058cULL: return fde_sub_06058c(a0, a1, a2);
        case 0x0606ccULL: return fde_sub_0606cc(a0, a1, a2);
        case 0x060774ULL: return fde_sub_060774(a0, a1, a2);
        case 0x060824ULL: return fde_sub_060824(a0, a1, a2);
        case 0x0608d4ULL: return fde_sub_0608d4(a0, a1, a2);
        case 0x06097cULL: return fde_sub_06097c(a0, a1, a2);
        case 0x060a2cULL: return fde_sub_060a2c(a0, a1, a2);
        case 0x060afcULL: return fde_sub_060afc(a0, a1, a2);
        case 0x060c34ULL: return fde_sub_060c34(a0, a1, a2);
        case 0x060eb0ULL: return fde_sub_060eb0(a0, a1, a2);
        case 0x060fe0ULL: return fde_sub_060fe0(a0, a1, a2);
        case 0x061080ULL: return fde_sub_061080(a0, a1, a2);
        case 0x061240ULL: return fde_sub_061240(a0, a1, a2);
        case 0x061314ULL: return fde_sub_061314(a0, a1, a2);
        case 0x061464ULL: return fde_sub_061464(a0, a1, a2);
        case 0x061524ULL: return fde_sub_061524(a0, a1, a2);
        case 0x0615d8ULL: return fde_sub_0615d8(a0, a1, a2);
        case 0x061698ULL: return fde_sub_061698(a0, a1, a2);
        case 0x061788ULL: return fde_sub_061788(a0, a1, a2);
        case 0x06179cULL: return fde_sub_06179c(a0, a1, a2);
        case 0x0617b4ULL: return fde_sub_0617b4(a0, a1, a2);
        case 0x0617ccULL: return fde_sub_0617cc(a0, a1, a2);
        case 0x0617fcULL: return fde_sub_0617fc(a0, a1, a2);
        case 0x0618b8ULL: return fde_sub_0618b8(a0, a1, a2);
        case 0x061938ULL: return fde_sub_061938(a0, a1, a2);
        case 0x061a98ULL: return fde_sub_061a98(a0, a1, a2);
        case 0x061c7cULL: return fde_sub_061c7c(a0, a1, a2);
        case 0x061d9cULL: return fde_sub_061d9c(a0, a1, a2);
        case 0x061fa0ULL: return fde_sub_061fa0(a0, a1, a2);
        case 0x0620d0ULL: return fde_sub_0620d0(a0, a1, a2);
        case 0x0620dcULL: return fde_sub_0620dc(a0, a1, a2);
        case 0x062454ULL: return fde_sub_062454(a0, a1, a2);
        case 0x0624fcULL: return fde_sub_0624fc(a0, a1, a2);
        case 0x062544ULL: return fde_sub_062544(a0, a1, a2);
        case 0x06254cULL: return fde_sub_06254c(a0, a1, a2);
        case 0x062648ULL: return fde_sub_062648(a0, a1, a2);
        case 0x0626f0ULL: return fde_sub_0626f0(a0, a1, a2);
        case 0x0627dcULL: return fde_sub_0627dc(a0, a1, a2);
        case 0x0628f0ULL: return fde_sub_0628f0(a0, a1, a2);
        case 0x062904ULL: return fde_sub_062904(a0, a1, a2);
        case 0x062a40ULL: return fde_sub_062a40(a0, a1, a2);
        case 0x062de0ULL: return fde_sub_062de0(a0, a1, a2);
        case 0x063420ULL: return fde_sub_063420(a0, a1, a2);
        case 0x0635b8ULL: return fde_sub_0635b8(a0, a1, a2);
        case 0x063af0ULL: return fde_sub_063af0(a0, a1, a2);
        case 0x063c04ULL: return fde_sub_063c04(a0, a1, a2);
        case 0x063c9cULL: return fde_sub_063c9c(a0, a1, a2);
        case 0x063e4cULL: return fde_sub_063e4c(a0, a1, a2);
        case 0x063e94ULL: return fde_sub_063e94(a0, a1, a2);
        case 0x063e9cULL: return fde_sub_063e9c(a0, a1, a2);
        case 0x063ec8ULL: return fde_sub_063ec8(a0, a1, a2);
        case 0x063eecULL: return fde_sub_063eec(a0, a1, a2);
        case 0x063efcULL: return fde_sub_063efc(a0, a1, a2);
        case 0x063f10ULL: return fde_sub_063f10(a0, a1, a2);
        case 0x063f94ULL: return fde_sub_063f94(a0, a1, a2);
        case 0x063f9cULL: return fde_sub_063f9c(a0, a1, a2);
        case 0x06413cULL: return fde_sub_06413c(a0, a1, a2);
        case 0x064188ULL: return fde_sub_064188(a0, a1, a2);
        case 0x06438cULL: return fde_sub_06438c(a0, a1, a2);
        case 0x0643ccULL: return fde_sub_0643cc(a0, a1, a2);
        case 0x0645c8ULL: return fde_sub_0645c8(a0, a1, a2);
        case 0x064610ULL: return fde_sub_064610(a0, a1, a2);
        case 0x0646bcULL: return fde_sub_0646bc(a0, a1, a2);
        case 0x06482cULL: return fde_sub_06482c(a0, a1, a2);
        case 0x064850ULL: return fde_sub_064850(a0, a1, a2);
        case 0x064864ULL: return fde_sub_064864(a0, a1, a2);
        case 0x0648e0ULL: return fde_sub_0648e0(a0, a1, a2);
        case 0x064900ULL: return fde_sub_064900(a0, a1, a2);
        case 0x064914ULL: return fde_sub_064914(a0, a1, a2);
        case 0x064934ULL: return fde_sub_064934(a0, a1, a2);
        case 0x064948ULL: return fde_sub_064948(a0, a1, a2);
        case 0x06497cULL: return fde_sub_06497c(a0, a1, a2);
        case 0x0649b8ULL: return fde_sub_0649b8(a0, a1, a2);
        case 0x0649dcULL: return fde_sub_0649dc(a0, a1, a2);
        case 0x064a00ULL: return fde_sub_064a00(a0, a1, a2);
        case 0x064a24ULL: return fde_sub_064a24(a0, a1, a2);
        case 0x064b20ULL: return fde_sub_064b20(a0, a1, a2);
        case 0x064c18ULL: return fde_sub_064c18(a0, a1, a2);
        case 0x064c80ULL: return fde_sub_064c80(a0, a1, a2);
        case 0x065144ULL: return fde_sub_065144(a0, a1, a2);
        case 0x065734ULL: return fde_sub_065734(a0, a1, a2);
        case 0x06576cULL: return fde_sub_06576c(a0, a1, a2);
        case 0x0657a4ULL: return fde_sub_0657a4(a0, a1, a2);
        case 0x065dccULL: return fde_sub_065dcc(a0, a1, a2);
        case 0x065df0ULL: return fde_sub_065df0(a0, a1, a2);
        case 0x065e10ULL: return fde_sub_065e10(a0, a1, a2);
        case 0x065e34ULL: return fde_sub_065e34(a0, a1, a2);
        case 0x065f44ULL: return fde_sub_065f44(a0, a1, a2);
        case 0x065ffcULL: return fde_sub_065ffc(a0, a1, a2);
        case 0x06605cULL: return fde_sub_06605c(a0, a1, a2);
        case 0x066a18ULL: return fde_sub_066a18(a0, a1, a2);
        case 0x066bb8ULL: return fde_sub_066bb8(a0, a1, a2);
        case 0x066ca8ULL: return fde_sub_066ca8(a0, a1, a2);
        case 0x066e74ULL: return fde_sub_066e74(a0, a1, a2);
        case 0x06731cULL: return fde_sub_06731c(a0, a1, a2);
        case 0x067428ULL: return fde_sub_067428(a0, a1, a2);
        case 0x0675f8ULL: return fde_sub_0675f8(a0, a1, a2);
        case 0x06773cULL: return fde_sub_06773c(a0, a1, a2);
        case 0x067858ULL: return fde_sub_067858(a0, a1, a2);
        case 0x0679d0ULL: return fde_sub_0679d0(a0, a1, a2);
        case 0x067b0cULL: return fde_sub_067b0c(a0, a1, a2);
        case 0x067ca0ULL: return fde_sub_067ca0(a0, a1, a2);
        case 0x067d60ULL: return fde_sub_067d60(a0, a1, a2);
        case 0x067e04ULL: return fde_sub_067e04(a0, a1, a2);
        case 0x068048ULL: return fde_sub_068048(a0, a1, a2);
        case 0x0680e8ULL: return fde_sub_0680e8(a0, a1, a2);
        case 0x06813cULL: return fde_sub_06813c(a0, a1, a2);
        case 0x068158ULL: return fde_sub_068158(a0, a1, a2);
        case 0x0682bcULL: return fde_sub_0682bc(a0, a1, a2);
        case 0x0682f8ULL: return fde_sub_0682f8(a0, a1, a2);
        case 0x068324ULL: return fde_sub_068324(a0, a1, a2);
        case 0x0683c8ULL: return fde_sub_0683c8(a0, a1, a2);
        case 0x068490ULL: return fde_sub_068490(a0, a1, a2);
        case 0x0684b8ULL: return fde_sub_0684b8(a0, a1, a2);
        case 0x068574ULL: return fde_sub_068574(a0, a1, a2);
        case 0x068740ULL: return fde_sub_068740(a0, a1, a2);
        case 0x068908ULL: return fde_sub_068908(a0, a1, a2);
        case 0x068a78ULL: return fde_sub_068a78(a0, a1, a2);
        case 0x068ab0ULL: return fde_sub_068ab0(a0, a1, a2);
        case 0x068ab8ULL: return fde_sub_068ab8(a0, a1, a2);
        case 0x068becULL: return fde_sub_068bec(a0, a1, a2);
        case 0x068ce0ULL: return fde_sub_068ce0(a0, a1, a2);
        case 0x068cf8ULL: return fde_sub_068cf8(a0, a1, a2);
        case 0x068ddcULL: return fde_sub_068ddc(a0, a1, a2);
        case 0x068eb8ULL: return fde_sub_068eb8(a0, a1, a2);
        case 0x068f6cULL: return fde_sub_068f6c(a0, a1, a2);
        case 0x069018ULL: return fde_sub_069018(a0, a1, a2);
        case 0x069068ULL: return fde_sub_069068(a0, a1, a2);
        case 0x0690d0ULL: return fde_sub_0690d0(a0, a1, a2);
        case 0x069234ULL: return fde_sub_069234(a0, a1, a2);
        case 0x069248ULL: return fde_sub_069248(a0, a1, a2);
        case 0x069368ULL: return fde_sub_069368(a0, a1, a2);
        case 0x0694c0ULL: return fde_sub_0694c0(a0, a1, a2);
        case 0x0697c0ULL: return fde_sub_0697c0(a0, a1, a2);
        case 0x0698fcULL: return fde_sub_0698fc(a0, a1, a2);
        case 0x0699bcULL: return fde_sub_0699bc(a0, a1, a2);
        case 0x069a68ULL: return fde_sub_069a68(a0, a1, a2);
        case 0x069a90ULL: return fde_sub_069a90(a0, a1, a2);
        case 0x069aa4ULL: return fde_sub_069aa4(a0, a1, a2);
        case 0x069aecULL: return fde_sub_069aec(a0, a1, a2);
        case 0x069b20ULL: return fde_sub_069b20(a0, a1, a2);
        case 0x069b8cULL: return fde_sub_069b8c(a0, a1, a2);
        case 0x069bccULL: return fde_sub_069bcc(a0, a1, a2);
        case 0x069c04ULL: return fde_sub_069c04(a0, a1, a2);
        case 0x069c80ULL: return fde_sub_069c80(a0, a1, a2);
        case 0x069d2cULL: return fde_sub_069d2c(a0, a1, a2);
        case 0x069ea0ULL: return fde_sub_069ea0(a0, a1, a2);
        case 0x06a090ULL: return fde_sub_06a090(a0, a1, a2);
        case 0x06a134ULL: return fde_sub_06a134(a0, a1, a2);
        case 0x06a310ULL: return fde_sub_06a310(a0, a1, a2);
        case 0x06a338ULL: return fde_sub_06a338(a0, a1, a2);
        case 0x06a3a4ULL: return fde_sub_06a3a4(a0, a1, a2);
        case 0x06a3f4ULL: return fde_sub_06a3f4(a0, a1, a2);
        case 0x06a474ULL: return fde_sub_06a474(a0, a1, a2);
        case 0x06a56cULL: return fde_sub_06a56c(a0, a1, a2);
        case 0x06a730ULL: return fde_sub_06a730(a0, a1, a2);
        case 0x06a78cULL: return fde_sub_06a78c(a0, a1, a2);
        case 0x06a794ULL: return fde_sub_06a794(a0, a1, a2);
        case 0x06a84cULL: return fde_sub_06a84c(a0, a1, a2);
        case 0x06ab44ULL: return fde_sub_06ab44(a0, a1, a2);
        case 0x06ab60ULL: return fde_sub_06ab60(a0, a1, a2);
        case 0x06ac34ULL: return fde_sub_06ac34(a0, a1, a2);
        case 0x06ac88ULL: return fde_sub_06ac88(a0, a1, a2);
        case 0x06add4ULL: return fde_sub_06add4(a0, a1, a2);
        case 0x06b8fcULL: return fde_sub_06b8fc(a0, a1, a2);
        case 0x06b944ULL: return fde_sub_06b944(a0, a1, a2);
        case 0x06b970ULL: return fde_sub_06b970(a0, a1, a2);
        case 0x06b9b4ULL: return fde_sub_06b9b4(a0, a1, a2);
        case 0x06b9e0ULL: return fde_sub_06b9e0(a0, a1, a2);
        case 0x06ba0cULL: return fde_sub_06ba0c(a0, a1, a2);
        case 0x06ba38ULL: return fde_sub_06ba38(a0, a1, a2);
        case 0x06ba64ULL: return fde_sub_06ba64(a0, a1, a2);
        case 0x06ba90ULL: return fde_sub_06ba90(a0, a1, a2);
        case 0x06babcULL: return fde_sub_06babc(a0, a1, a2);
        case 0x06bae8ULL: return fde_sub_06bae8(a0, a1, a2);
        case 0x06bb38ULL: return fde_sub_06bb38(a0, a1, a2);
        case 0x06bb64ULL: return fde_sub_06bb64(a0, a1, a2);
        case 0x06bb74ULL: return fde_sub_06bb74(a0, a1, a2);
        case 0x06bc8cULL: return fde_sub_06bc8c(a0, a1, a2);
        case 0x06bcb8ULL: return fde_sub_06bcb8(a0, a1, a2);
        case 0x06bcf0ULL: return fde_sub_06bcf0(a0, a1, a2);
        case 0x06bd28ULL: return fde_sub_06bd28(a0, a1, a2);
        case 0x06bdf4ULL: return fde_sub_06bdf4(a0, a1, a2);
        case 0x06be20ULL: return fde_sub_06be20(a0, a1, a2);
        case 0x06be90ULL: return fde_sub_06be90(a0, a1, a2);
        case 0x06bebcULL: return fde_sub_06bebc(a0, a1, a2);
        case 0x06bf34ULL: return fde_sub_06bf34(a0, a1, a2);
        case 0x06c0dcULL: return fde_sub_06c0dc(a0, a1, a2);
        case 0x06c2b8ULL: return fde_sub_06c2b8(a0, a1, a2);
        case 0x06c3b4ULL: return fde_sub_06c3b4(a0, a1, a2);
        case 0x06c458ULL: return fde_sub_06c458(a0, a1, a2);
        case 0x06c49cULL: return fde_sub_06c49c(a0, a1, a2);
        case 0x06c4dcULL: return fde_sub_06c4dc(a0, a1, a2);
        case 0x06c5e4ULL: return fde_sub_06c5e4(a0, a1, a2);
        case 0x06c5ecULL: return fde_sub_06c5ec(a0, a1, a2);
        case 0x06c5f8ULL: return fde_sub_06c5f8(a0, a1, a2);
        case 0x06c664ULL: return fde_sub_06c664(a0, a1, a2);
        case 0x06c67cULL: return fde_sub_06c67c(a0, a1, a2);
        case 0x06c6a4ULL: return fde_sub_06c6a4(a0, a1, a2);
        default: return 0ULL;
    }
}

} // namespace TTKMediaNet
