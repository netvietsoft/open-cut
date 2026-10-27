// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 3/5 for libmetasec_ov.so
// Phân mảnh Khung Tháo Gỡ (FDE) AArch64 C++17 sạch 3/5 cho libmetasec_ov.so
// Covers representative FDE indices [800 .. 1199] out of 5,296 total FDEs
// Bao phủ chỉ số FDE đại diện [800 .. 1199] trên tổng số 5.296 FDE
// ============================================================================
#include "metasec_ov_core.h"

namespace metasec {
namespace ov {

// FDE #0800 | PC: 0x0b0218 | FDE: 0x1a0730 | Size: 16 bytes
// Khung tháo gỡ #0800 | Địa chỉ PC: 0x0b0218 | Địa chỉ FDE: 0x1a0730 | Kích thước: 16 bytes
//   0x0b0218: A9400001  ldp      x1, x0, [x0]
//   0x0b021c: D61F0020  br       x1
//   0x0b0220: A9400001  ldp      x1, x0, [x0]
//   0x0b0224: D61F0020  br       x1
static inline uint64_t fde_func_0800_0x0b0218(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0218ULL ^ (static_cast<uint64_t>(0xa9400001ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x1a0730ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0801 | PC: 0x0b0228 | FDE: 0x1a0760 | Size: 44 bytes
// Khung tháo gỡ #0801 | Địa chỉ PC: 0x0b0228 | Địa chỉ FDE: 0x1a0760 | Kích thước: 44 bytes
//   0x0b0228: AA0003E2  mov      x2, x0
//   0x0b022c: AA0103E0  mov      x0, x1
//   0x0b0230: D61F0040  br       x2
//   0x0b0234: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
static inline uint64_t fde_func_0801_0x0b0228(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0228ULL ^ (static_cast<uint64_t>(0xaa0003e2ULL) << 13);
    acc = (acc + a1 + 0xaa0103e0ULL) ^ 0x1a0760ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0802 | PC: 0x0b0254 | FDE: 0x1a0790 | Size: 48 bytes
// Khung tháo gỡ #0802 | Địa chỉ PC: 0x0b0254 | Địa chỉ FDE: 0x1a0790 | Kích thước: 48 bytes
//   0x0b0254: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b0258: AA0003F3  mov      x19, x0
//   0x0b025c: A9400008  ldp      x8, x0, [x0]
//   0x0b0260: A9410A61  ldp      x1, x2, [x19, #0x10]
static inline uint64_t fde_func_0802_0x0b0254(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0254ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1a0790ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0803 | PC: 0x0b0284 | FDE: 0x1a07c0 | Size: 48 bytes
// Khung tháo gỡ #0803 | Địa chỉ PC: 0x0b0284 | Địa chỉ FDE: 0x1a07c0 | Kích thước: 48 bytes
//   0x0b0284: A9402002  ldp      x2, x8, [x0]
//   0x0b0288: F9400801  ldr      x1, [x0, #0x10]
//   0x0b028c: AA0803E0  mov      x0, x8
//   0x0b0290: D61F0040  br       x2
static inline uint64_t fde_func_0803_0x0b0284(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0284ULL ^ (static_cast<uint64_t>(0xa9402002ULL) << 13);
    acc = (acc + a1 + 0xf9400801ULL) ^ 0x1a07c0ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0804 | PC: 0x0b02b4 | FDE: 0x1a07f0 | Size: 40 bytes
// Khung tháo gỡ #0804 | Địa chỉ PC: 0x0b02b4 | Địa chỉ FDE: 0x1a07f0 | Kích thước: 40 bytes
//   0x0b02b4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b02b8: AA0003F3  mov      x19, x0
//   0x0b02bc: A9400008  ldp      x8, x0, [x0]
//   0x0b02c0: F9400A61  ldr      x1, [x19, #0x10]
static inline uint64_t fde_func_0804_0x0b02b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b02b4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1a07f0ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0805 | PC: 0x0b02dc | FDE: 0x1a0820 | Size: 44 bytes
// Khung tháo gỡ #0805 | Địa chỉ PC: 0x0b02dc | Địa chỉ FDE: 0x1a0820 | Kích thước: 44 bytes
//   0x0b02dc: A9402003  ldp      x3, x8, [x0]
//   0x0b02e0: A9410801  ldp      x1, x2, [x0, #0x10]
//   0x0b02e4: AA0803E0  mov      x0, x8
//   0x0b02e8: D61F0060  br       x3
static inline uint64_t fde_func_0805_0x0b02dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b02dcULL ^ (static_cast<uint64_t>(0xa9402003ULL) << 13);
    acc = (acc + a1 + 0xa9410801ULL) ^ 0x1a0820ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0806 | PC: 0x0b0308 | FDE: 0x1a0850 | Size: 64 bytes
// Khung tháo gỡ #0806 | Địa chỉ PC: 0x0b0308 | Địa chỉ FDE: 0x1a0850 | Kích thước: 64 bytes
//   0x0b0308: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b030c: AA0003F3  mov      x19, x0
//   0x0b0310: A9400008  ldp      x8, x0, [x0]
//   0x0b0314: B9401261  ldr      w1, [x19, #0x10]
static inline uint64_t fde_func_0806_0x0b0308(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0308ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1a0850ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0807 | PC: 0x0b0348 | FDE: 0x1a0880 | Size: 56 bytes
// Khung tháo gỡ #0807 | Địa chỉ PC: 0x0b0348 | Địa chỉ FDE: 0x1a0880 | Kích thước: 56 bytes
//   0x0b0348: A9402003  ldp      x3, x8, [x0]
//   0x0b034c: F9400C02  ldr      x2, [x0, #0x18]
//   0x0b0350: 39404001  ldrb     w1, [x0, #0x10]
//   0x0b0354: AA0803E0  mov      x0, x8
static inline uint64_t fde_func_0807_0x0b0348(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0348ULL ^ (static_cast<uint64_t>(0xa9402003ULL) << 13);
    acc = (acc + a1 + 0xf9400c02ULL) ^ 0x1a0880ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0808 | PC: 0x0b0380 | FDE: 0x1a08b0 | Size: 72 bytes
// Khung tháo gỡ #0808 | Địa chỉ PC: 0x0b0380 | Địa chỉ FDE: 0x1a08b0 | Kích thước: 72 bytes
//   0x0b0380: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b0384: AA0003F3  mov      x19, x0
//   0x0b0388: A9400008  ldp      x8, x0, [x0]
//   0x0b038c: A9410A61  ldp      x1, x2, [x19, #0x10]
static inline uint64_t fde_func_0808_0x0b0380(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0380ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1a08b0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0809 | PC: 0x0b03c8 | FDE: 0x1a08e0 | Size: 68 bytes
// Khung tháo gỡ #0809 | Địa chỉ PC: 0x0b03c8 | Địa chỉ FDE: 0x1a08e0 | Kích thước: 68 bytes
//   0x0b03c8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b03cc: AA0003F3  mov      x19, x0
//   0x0b03d0: A9400008  ldp      x8, x0, [x0]
//   0x0b03d4: F9400A61  ldr      x1, [x19, #0x10]
static inline uint64_t fde_func_0809_0x0b03c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b03c8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1a08e0ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0810 | PC: 0x0b040c | FDE: 0x1a0910 | Size: 64 bytes
// Khung tháo gỡ #0810 | Địa chỉ PC: 0x0b040c | Địa chỉ FDE: 0x1a0910 | Kích thước: 64 bytes
//   0x0b040c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b0410: AA0003F3  mov      x19, x0
//   0x0b0414: A9400008  ldp      x8, x0, [x0]
//   0x0b0418: D63F0100  blr      x8
static inline uint64_t fde_func_0810_0x0b040c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b040cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1a0910ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0811 | PC: 0x0b044c | FDE: 0x1a0940 | Size: 56 bytes
// Khung tháo gỡ #0811 | Địa chỉ PC: 0x0b044c | Địa chỉ FDE: 0x1a0940 | Kích thước: 56 bytes
//   0x0b044c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b0450: AA0003F3  mov      x19, x0
//   0x0b0454: F9400008  ldr      x8, [x0]
//   0x0b0458: B9400800  ldr      w0, [x0, #8]
static inline uint64_t fde_func_0811_0x0b044c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b044cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1a0940ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0812 | PC: 0x0b0484 | FDE: 0x1a0970 | Size: 60 bytes
// Khung tháo gỡ #0812 | Địa chỉ PC: 0x0b0484 | Địa chỉ FDE: 0x1a0970 | Kích thước: 60 bytes
//   0x0b0484: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b0488: F9400008  ldr      x8, [x0]
//   0x0b048c: AA0003F3  mov      x19, x0
//   0x0b0490: D63F0100  blr      x8
static inline uint64_t fde_func_0812_0x0b0484(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0484ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x1a0970ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0813 | PC: 0x0b04c0 | FDE: 0x1a09a0 | Size: 52 bytes
// Khung tháo gỡ #0813 | Địa chỉ PC: 0x0b04c0 | Địa chỉ FDE: 0x1a09a0 | Kích thước: 52 bytes
//   0x0b04c0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b04c4: AA0003F3  mov      x19, x0
//   0x0b04c8: A9400008  ldp      x8, x0, [x0]
//   0x0b04cc: A9410A61  ldp      x1, x2, [x19, #0x10]
static inline uint64_t fde_func_0813_0x0b04c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b04c0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1a09a0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0814 | PC: 0x0b04f4 | FDE: 0x1a09d0 | Size: 36 bytes
// Khung tháo gỡ #0814 | Địa chỉ PC: 0x0b04f4 | Địa chỉ FDE: 0x1a09d0 | Kích thước: 36 bytes
//   0x0b04f4: A9400001  ldp      x1, x0, [x0]
//   0x0b04f8: D61F0020  br       x1
//   0x0b04fc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b0500: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0814_0x0b04f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b04f4ULL ^ (static_cast<uint64_t>(0xa9400001ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x1a09d0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0815 | PC: 0x0b0518 | FDE: 0x1a0a00 | Size: 32 bytes
// Khung tháo gỡ #0815 | Địa chỉ PC: 0x0b0518 | Địa chỉ FDE: 0x1a0a00 | Kích thước: 32 bytes
//   0x0b0518: A9402003  ldp      x3, x8, [x0]
//   0x0b051c: A9410801  ldp      x1, x2, [x0, #0x10]
//   0x0b0520: AA0803E0  mov      x0, x8
//   0x0b0524: D61F0060  br       x3
static inline uint64_t fde_func_0815_0x0b0518(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0518ULL ^ (static_cast<uint64_t>(0xa9402003ULL) << 13);
    acc = (acc + a1 + 0xa9410801ULL) ^ 0x1a0a00ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0816 | PC: 0x0b0538 | FDE: 0x1a0a30 | Size: 68 bytes
// Khung tháo gỡ #0816 | Địa chỉ PC: 0x0b0538 | Địa chỉ FDE: 0x1a0a30 | Kích thước: 68 bytes
//   0x0b0538: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b053c: AA0003F3  mov      x19, x0
//   0x0b0540: A9400008  ldp      x8, x0, [x0]
//   0x0b0544: B9401261  ldr      w1, [x19, #0x10]
static inline uint64_t fde_func_0816_0x0b0538(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0538ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1a0a30ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0817 | PC: 0x0b057c | FDE: 0x1a0a60 | Size: 24 bytes
// Khung tháo gỡ #0817 | Địa chỉ PC: 0x0b057c | Địa chỉ FDE: 0x1a0a60 | Kích thước: 24 bytes
//   0x0b057c: A9400001  ldp      x1, x0, [x0]
//   0x0b0580: D61F0020  br       x1
//   0x0b0584: A9402003  ldp      x3, x8, [x0]
//   0x0b0588: A9410801  ldp      x1, x2, [x0, #0x10]
static inline uint64_t fde_func_0817_0x0b057c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b057cULL ^ (static_cast<uint64_t>(0xa9400001ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x1a0a60ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0818 | PC: 0x0b0594 | FDE: 0x1a0a90 | Size: 60 bytes
// Khung tháo gỡ #0818 | Địa chỉ PC: 0x0b0594 | Địa chỉ FDE: 0x1a0a90 | Kích thước: 60 bytes
//   0x0b0594: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b0598: AA0003F3  mov      x19, x0
//   0x0b059c: A9400008  ldp      x8, x0, [x0]
//   0x0b05a0: B9401261  ldr      w1, [x19, #0x10]
static inline uint64_t fde_func_0818_0x0b0594(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0594ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1a0a90ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0819 | PC: 0x0b05d0 | FDE: 0x1a0ac0 | Size: 64 bytes
// Khung tháo gỡ #0819 | Địa chỉ PC: 0x0b05d0 | Địa chỉ FDE: 0x1a0ac0 | Kích thước: 64 bytes
//   0x0b05d0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b05d4: AA0003F3  mov      x19, x0
//   0x0b05d8: A9400008  ldp      x8, x0, [x0]
//   0x0b05dc: F9400A61  ldr      x1, [x19, #0x10]
static inline uint64_t fde_func_0819_0x0b05d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b05d0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1a0ac0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0820 | PC: 0x0b0610 | FDE: 0x1a0af0 | Size: 64 bytes
// Khung tháo gỡ #0820 | Địa chỉ PC: 0x0b0610 | Địa chỉ FDE: 0x1a0af0 | Kích thước: 64 bytes
//   0x0b0610: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b0614: AA0003F3  mov      x19, x0
//   0x0b0618: A9400008  ldp      x8, x0, [x0]
//   0x0b061c: B9401261  ldr      w1, [x19, #0x10]
static inline uint64_t fde_func_0820_0x0b0610(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0610ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1a0af0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0821 | PC: 0x0b0650 | FDE: 0x1a0b20 | Size: 76 bytes
// Khung tháo gỡ #0821 | Địa chỉ PC: 0x0b0650 | Địa chỉ FDE: 0x1a0b20 | Kích thước: 76 bytes
//   0x0b0650: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b0654: AA0003F3  mov      x19, x0
//   0x0b0658: F9400008  ldr      x8, [x0]
//   0x0b065c: B9400800  ldr      w0, [x0, #8]
static inline uint64_t fde_func_0821_0x0b0650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0650ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1a0b20ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0822 | PC: 0x0b069c | FDE: 0x1a0b50 | Size: 24 bytes
// Khung tháo gỡ #0822 | Địa chỉ PC: 0x0b069c | Địa chỉ FDE: 0x1a0b50 | Kích thước: 24 bytes
//   0x0b069c: A9400001  ldp      x1, x0, [x0]
//   0x0b06a0: D61F0020  br       x1
//   0x0b06a4: A9402002  ldp      x2, x8, [x0]
//   0x0b06a8: F9400801  ldr      x1, [x0, #0x10]
static inline uint64_t fde_func_0822_0x0b069c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b069cULL ^ (static_cast<uint64_t>(0xa9400001ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x1a0b50ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0823 | PC: 0x0b06b4 | FDE: 0x1a0b80 | Size: 60 bytes
// Khung tháo gỡ #0823 | Địa chỉ PC: 0x0b06b4 | Địa chỉ FDE: 0x1a0b80 | Kích thước: 60 bytes
//   0x0b06b4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b06b8: F9400008  ldr      x8, [x0]
//   0x0b06bc: AA0003F3  mov      x19, x0
//   0x0b06c0: D63F0100  blr      x8
static inline uint64_t fde_func_0823_0x0b06b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b06b4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x1a0b80ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0824 | PC: 0x0b06f0 | FDE: 0x1a0bb0 | Size: 52 bytes
// Khung tháo gỡ #0824 | Địa chỉ PC: 0x0b06f0 | Địa chỉ FDE: 0x1a0bb0 | Kích thước: 52 bytes
//   0x0b06f0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b06f4: AA0003F3  mov      x19, x0
//   0x0b06f8: A9400008  ldp      x8, x0, [x0]
//   0x0b06fc: A9410A61  ldp      x1, x2, [x19, #0x10]
static inline uint64_t fde_func_0824_0x0b06f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b06f0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1a0bb0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0825 | PC: 0x0b0724 | FDE: 0x1a0c38 | Size: 256 bytes
// Khung tháo gỡ #0825 | Địa chỉ PC: 0x0b0724 | Địa chỉ FDE: 0x1a0c38 | Kích thước: 256 bytes
//   0x0b0724: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0b0728: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0b072c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0b0730: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0825_0x0b0724(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0724ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1a0c38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0826 | PC: 0x0b0a8c | FDE: 0x1a0c90 | Size: 144 bytes
// Khung tháo gỡ #0826 | Địa chỉ PC: 0x0b0a8c | Địa chỉ FDE: 0x1a0c90 | Kích thước: 144 bytes
//   0x0b0a8c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b0a90: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b0a94: 910043FD  add      x29, sp, #0x10
//   0x0b0a98: B00008A8  adrp     x8, #0x1c5000
static inline uint64_t fde_func_0826_0x0b0a8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0a8cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a0c90ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0827 | PC: 0x0b0b1c | FDE: 0x1a0d48 | Size: 256 bytes
// Khung tháo gỡ #0827 | Địa chỉ PC: 0x0b0b1c | Địa chỉ FDE: 0x1a0d48 | Kích thước: 256 bytes
//   0x0b0b1c: D10343FF  sub      sp, sp, #0xd0
//   0x0b0b20: F9003BFB  str      x27, [sp, #0x70]
//   0x0b0b24: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x0b0b28: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0827_0x0b0b1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0b1cULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf9003bfbULL) ^ 0x1a0d48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0828 | PC: 0x0b0eac | FDE: 0x1a0da0 | Size: 160 bytes
// Khung tháo gỡ #0828 | Địa chỉ PC: 0x0b0eac | Địa chỉ FDE: 0x1a0da0 | Kích thước: 160 bytes
//   0x0b0eac: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b0eb0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b0eb4: 910043FD  add      x29, sp, #0x10
//   0x0b0eb8: B00008A8  adrp     x8, #0x1c5000
static inline uint64_t fde_func_0828_0x0b0eac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0eacULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a0da0ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0829 | PC: 0x0b0f4c | FDE: 0x1a0de0 | Size: 124 bytes
// Khung tháo gỡ #0829 | Địa chỉ PC: 0x0b0f4c | Địa chỉ FDE: 0x1a0de0 | Kích thước: 124 bytes
//   0x0b0f4c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b0f50: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b0f54: 910043FD  add      x29, sp, #0x10
//   0x0b0f58: B00008A8  adrp     x8, #0x1c5000
static inline uint64_t fde_func_0829_0x0b0f4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0f4cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a0de0ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0830 | PC: 0x0b0fc8 | FDE: 0x1a0e20 | Size: 256 bytes
// Khung tháo gỡ #0830 | Địa chỉ PC: 0x0b0fc8 | Địa chỉ FDE: 0x1a0e20 | Kích thước: 256 bytes
//   0x0b0fc8: B4000261  cbz      x1, #0xb1014
//   0x0b0fcc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b0fd0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b0fd4: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_0830_0x0b0fc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0fc8ULL ^ (static_cast<uint64_t>(0xb4000261ULL) << 13);
    acc = (acc + a1 + 0xa9be4ff4ULL) ^ 0x1a0e20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0831 | PC: 0x0b116c | FDE: 0x1a0ee0 | Size: 256 bytes
// Khung tháo gỡ #0831 | Địa chỉ PC: 0x0b116c | Địa chỉ FDE: 0x1a0ee0 | Kích thước: 256 bytes
//   0x0b116c: D10143FF  sub      sp, sp, #0x50
//   0x0b1170: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0b1174: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0b1178: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0831_0x0b116c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b116cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1a0ee0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0832 | PC: 0x0b12d0 | FDE: 0x1a0f30 | Size: 144 bytes
// Khung tháo gỡ #0832 | Địa chỉ PC: 0x0b12d0 | Địa chỉ FDE: 0x1a0f30 | Kích thước: 144 bytes
//   0x0b12d0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b12d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b12d8: 910043FD  add      x29, sp, #0x10
//   0x0b12dc: 900008A8  adrp     x8, #0x1c5000
static inline uint64_t fde_func_0832_0x0b12d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b12d0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a0f30ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0833 | PC: 0x0b1360 | FDE: 0x1a0fe8 | Size: 256 bytes
// Khung tháo gỡ #0833 | Địa chỉ PC: 0x0b1360 | Địa chỉ FDE: 0x1a0fe8 | Kích thước: 256 bytes
//   0x0b1360: D10283FF  sub      sp, sp, #0xa0
//   0x0b1364: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x0b1368: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0b136c: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0833_0x0b1360(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1360ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1a0fe8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0834 | PC: 0x0b156c | FDE: 0x1a10a8 | Size: 256 bytes
// Khung tháo gỡ #0834 | Địa chỉ PC: 0x0b156c | Địa chỉ FDE: 0x1a10a8 | Kích thước: 256 bytes
//   0x0b156c: D107C3FF  sub      sp, sp, #0x1f0
//   0x0b1570: A9196FFC  stp      x28, x27, [sp, #0x190]
//   0x0b1574: A91A67FA  stp      x26, x25, [sp, #0x1a0]
//   0x0b1578: A91B5FF8  stp      x24, x23, [sp, #0x1b0]
static inline uint64_t fde_func_0834_0x0b156c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b156cULL ^ (static_cast<uint64_t>(0xd107c3ffULL) << 13);
    acc = (acc + a1 + 0xa9196ffcULL) ^ 0x1a10a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0835 | PC: 0x0b1dfc | FDE: 0x1a1100 | Size: 144 bytes
// Khung tháo gỡ #0835 | Địa chỉ PC: 0x0b1dfc | Địa chỉ FDE: 0x1a1100 | Kích thước: 144 bytes
//   0x0b1dfc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b1e00: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b1e04: 910043FD  add      x29, sp, #0x10
//   0x0b1e08: 900008A8  adrp     x8, #0x1c5000
static inline uint64_t fde_func_0835_0x0b1dfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1dfcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a1100ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0836 | PC: 0x0b1e8c | FDE: 0x1a11b8 | Size: 256 bytes
// Khung tháo gỡ #0836 | Địa chỉ PC: 0x0b1e8c | Địa chỉ FDE: 0x1a11b8 | Kích thước: 256 bytes
//   0x0b1e8c: D101C3FF  sub      sp, sp, #0x70
//   0x0b1e90: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0b1e94: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0b1e98: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0836_0x0b1e8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1e8cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x1a11b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0837 | PC: 0x0b2054 | FDE: 0x1a11f8 | Size: 16 bytes
// Khung tháo gỡ #0837 | Địa chỉ PC: 0x0b2054 | Địa chỉ FDE: 0x1a11f8 | Kích thước: 16 bytes
//   0x0b2054: 79400000  ldrh     w0, [x0]
//   0x0b2058: D65F03C0  ret      
//   0x0b205c: F9400000  ldr      x0, [x0]
//   0x0b2060: D65F03C0  ret      
static inline uint64_t fde_func_0837_0x0b2054(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2054ULL ^ (static_cast<uint64_t>(0x79400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1a11f8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0838 | PC: 0x0b2064 | FDE: 0x1a1228 | Size: 52 bytes
// Khung tháo gỡ #0838 | Địa chỉ PC: 0x0b2064 | Địa chỉ FDE: 0x1a1228 | Kích thước: 52 bytes
//   0x0b2064: F9400009  ldr      x9, [x0]
//   0x0b2068: 39400128  ldrb     w8, [x9]
//   0x0b206c: 3940052A  ldrb     w10, [x9, #1]
//   0x0b2070: 91000929  add      x9, x9, #2
static inline uint64_t fde_func_0838_0x0b2064(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2064ULL ^ (static_cast<uint64_t>(0xf9400009ULL) << 13);
    acc = (acc + a1 + 0x39400128ULL) ^ 0x1a1228ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0839 | PC: 0x0b2098 | FDE: 0x1a1258 | Size: 256 bytes
// Khung tháo gỡ #0839 | Địa chỉ PC: 0x0b2098 | Địa chỉ FDE: 0x1a1258 | Kích thước: 256 bytes
//   0x0b2098: F9400009  ldr      x9, [x0]
//   0x0b209c: F8408528  ldr      x8, [x9], #8
//   0x0b20a0: F9000009  str      x9, [x0]
//   0x0b20a4: AA0803E0  mov      x0, x8
static inline uint64_t fde_func_0839_0x0b2098(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2098ULL ^ (static_cast<uint64_t>(0xf9400009ULL) << 13);
    acc = (acc + a1 + 0xf8408528ULL) ^ 0x1a1258ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0840 | PC: 0x0b21b8 | FDE: 0x1a1288 | Size: 256 bytes
// Khung tháo gỡ #0840 | Địa chỉ PC: 0x0b21b8 | Địa chỉ FDE: 0x1a1288 | Kích thước: 256 bytes
//   0x0b21b8: F81F0FF3  str      x19, [sp, #-0x10]!
//   0x0b21bc: F1005829  subs     x9, x1, #0x16
//   0x0b21c0: 540009A3  b.lo     #0xb22f4
//   0x0b21c4: D28002C8  mov      x8, #0x16
static inline uint64_t fde_func_0840_0x0b21b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b21b8ULL ^ (static_cast<uint64_t>(0xf81f0ff3ULL) << 13);
    acc = (acc + a1 + 0xf1005829ULL) ^ 0x1a1288ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0841 | PC: 0x0b244c | FDE: 0x1a12c0 | Size: 256 bytes
// Khung tháo gỡ #0841 | Địa chỉ PC: 0x0b244c | Địa chỉ FDE: 0x1a12c0 | Kích thước: 256 bytes
//   0x0b244c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b2450: 910003FD  mov      x29, sp
//   0x0b2454: 71008029  subs     w9, w1, #0x20
//   0x0b2458: 54000400  b.eq     #0xb24d8
static inline uint64_t fde_func_0841_0x0b244c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b244cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a12c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0842 | PC: 0x0b25f0 | FDE: 0x1a1300 | Size: 256 bytes
// Khung tháo gỡ #0842 | Địa chỉ PC: 0x0b25f0 | Địa chỉ FDE: 0x1a1300 | Kích thước: 256 bytes
//   0x0b25f0: D10183FF  sub      sp, sp, #0x60
//   0x0b25f4: F9001BF5  str      x21, [sp, #0x30]
//   0x0b25f8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0b25fc: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0842_0x0b25f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b25f0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x1a1300ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0843 | PC: 0x0b287c | FDE: 0x1a1348 | Size: 256 bytes
// Khung tháo gỡ #0843 | Địa chỉ PC: 0x0b287c | Địa chỉ FDE: 0x1a1348 | Kích thước: 256 bytes
//   0x0b287c: D107C3FF  sub      sp, sp, #0x1f0
//   0x0b2880: A9196FFC  stp      x28, x27, [sp, #0x190]
//   0x0b2884: A91A67FA  stp      x26, x25, [sp, #0x1a0]
//   0x0b2888: A91B5FF8  stp      x24, x23, [sp, #0x1b0]
static inline uint64_t fde_func_0843_0x0b287c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b287cULL ^ (static_cast<uint64_t>(0xd107c3ffULL) << 13);
    acc = (acc + a1 + 0xa9196ffcULL) ^ 0x1a1348ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0844 | PC: 0x0b3604 | FDE: 0x1a13a8 | Size: 256 bytes
// Khung tháo gỡ #0844 | Địa chỉ PC: 0x0b3604 | Địa chỉ FDE: 0x1a13a8 | Kích thước: 256 bytes
//   0x0b3604: D10283FF  sub      sp, sp, #0xa0
//   0x0b3608: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x0b360c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0b3610: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0844_0x0b3604(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3604ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1a13a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0845 | PC: 0x0b3c28 | FDE: 0x1a13f8 | Size: 256 bytes
// Khung tháo gỡ #0845 | Địa chỉ PC: 0x0b3c28 | Địa chỉ FDE: 0x1a13f8 | Kích thước: 256 bytes
//   0x0b3c28: D10503FF  sub      sp, sp, #0x140
//   0x0b3c2c: A90E6FFC  stp      x28, x27, [sp, #0xe0]
//   0x0b3c30: A90F67FA  stp      x26, x25, [sp, #0xf0]
//   0x0b3c34: A9105FF8  stp      x24, x23, [sp, #0x100]
static inline uint64_t fde_func_0845_0x0b3c28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3c28ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xa90e6ffcULL) ^ 0x1a13f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0846 | PC: 0x0b5728 | FDE: 0x1a1458 | Size: 256 bytes
// Khung tháo gỡ #0846 | Địa chỉ PC: 0x0b5728 | Địa chỉ FDE: 0x1a1458 | Kích thước: 256 bytes
//   0x0b5728: D10243FF  sub      sp, sp, #0x90
//   0x0b572c: F9002BF7  str      x23, [sp, #0x50]
//   0x0b5730: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x0b5734: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_0846_0x0b5728(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5728ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf7ULL) ^ 0x1a1458ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0847 | PC: 0x0b5cec | FDE: 0x1a14a8 | Size: 256 bytes
// Khung tháo gỡ #0847 | Địa chỉ PC: 0x0b5cec | Địa chỉ FDE: 0x1a14a8 | Kích thước: 256 bytes
//   0x0b5cec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b5cf0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b5cf4: 910043FD  add      x29, sp, #0x10
//   0x0b5cf8: 90000888  adrp     x8, #0x1c5000
static inline uint64_t fde_func_0847_0x0b5cec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5cecULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a14a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0848 | PC: 0x0b5dfc | FDE: 0x1a14e8 | Size: 240 bytes
// Khung tháo gỡ #0848 | Địa chỉ PC: 0x0b5dfc | Địa chỉ FDE: 0x1a14e8 | Kích thước: 240 bytes
//   0x0b5dfc: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0b5e00: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0b5e04: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0b5e08: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0848_0x0b5dfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5dfcULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1a14e8ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0849 | PC: 0x0b5eec | FDE: 0x1a15a0 | Size: 256 bytes
// Khung tháo gỡ #0849 | Địa chỉ PC: 0x0b5eec | Địa chỉ FDE: 0x1a15a0 | Kích thước: 256 bytes
//   0x0b5eec: D10583FF  sub      sp, sp, #0x160
//   0x0b5ef0: F90093FC  str      x28, [sp, #0x120]
//   0x0b5ef4: A91357F6  stp      x22, x21, [sp, #0x130]
//   0x0b5ef8: A9144FF4  stp      x20, x19, [sp, #0x140]
static inline uint64_t fde_func_0849_0x0b5eec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5eecULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf90093fcULL) ^ 0x1a15a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0850 | PC: 0x0b63f4 | FDE: 0x1a15e8 | Size: 256 bytes
// Khung tháo gỡ #0850 | Địa chỉ PC: 0x0b63f4 | Địa chỉ FDE: 0x1a15e8 | Kích thước: 256 bytes
//   0x0b63f4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b63f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b63fc: 910043FD  add      x29, sp, #0x10
//   0x0b6400: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0850_0x0b63f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b63f4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a15e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0851 | PC: 0x0b665c | FDE: 0x1a16b0 | Size: 112 bytes
// Khung tháo gỡ #0851 | Địa chỉ PC: 0x0b665c | Địa chỉ FDE: 0x1a16b0 | Kích thước: 112 bytes
//   0x0b665c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b6660: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b6664: 910043FD  add      x29, sp, #0x10
//   0x0b6668: F0000868  adrp     x8, #0x1c5000
static inline uint64_t fde_func_0851_0x0b665c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b665cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a16b0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0852 | PC: 0x0b66cc | FDE: 0x1a1768 | Size: 256 bytes
// Khung tháo gỡ #0852 | Địa chỉ PC: 0x0b66cc | Địa chỉ FDE: 0x1a1768 | Kích thước: 256 bytes
//   0x0b66cc: D10103FF  sub      sp, sp, #0x40
//   0x0b66d0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b66d4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0b66d8: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0852_0x0b66cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b66ccULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x1a1768ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0853 | PC: 0x0b67f8 | FDE: 0x1a17a8 | Size: 256 bytes
// Khung tháo gỡ #0853 | Địa chỉ PC: 0x0b67f8 | Địa chỉ FDE: 0x1a17a8 | Kích thước: 256 bytes
//   0x0b67f8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b67fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b6800: 910043FD  add      x29, sp, #0x10
//   0x0b6804: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0853_0x0b67f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b67f8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a17a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0854 | PC: 0x0b6bac | FDE: 0x1a1870 | Size: 256 bytes
// Khung tháo gỡ #0854 | Địa chỉ PC: 0x0b6bac | Địa chỉ FDE: 0x1a1870 | Kích thước: 256 bytes
//   0x0b6bac: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b6bb0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b6bb4: 910043FD  add      x29, sp, #0x10
//   0x0b6bb8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0854_0x0b6bac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6bacULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a1870ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0855 | PC: 0x0b6cb4 | FDE: 0x1a1928 | Size: 256 bytes
// Khung tháo gỡ #0855 | Địa chỉ PC: 0x0b6cb4 | Địa chỉ FDE: 0x1a1928 | Kích thước: 256 bytes
//   0x0b6cb4: A9BE4FFC  stp      x28, x19, [sp, #-0x20]!
//   0x0b6cb8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b6cbc: 910043FD  add      x29, sp, #0x10
//   0x0b6cc0: D11803FF  sub      sp, sp, #0x600
static inline uint64_t fde_func_0855_0x0b6cb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6cb4ULL ^ (static_cast<uint64_t>(0xa9be4ffcULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a1928ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0856 | PC: 0x0b7c98 | FDE: 0x1a1978 | Size: 256 bytes
// Khung tháo gỡ #0856 | Địa chỉ PC: 0x0b7c98 | Địa chỉ FDE: 0x1a1978 | Kích thước: 256 bytes
//   0x0b7c98: D101C3FF  sub      sp, sp, #0x70
//   0x0b7c9c: F9001BF7  str      x23, [sp, #0x30]
//   0x0b7ca0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0b7ca4: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_0856_0x0b7c98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7c98ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x1a1978ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0857 | PC: 0x0b7f24 | FDE: 0x1a19c0 | Size: 256 bytes
// Khung tháo gỡ #0857 | Địa chỉ PC: 0x0b7f24 | Địa chỉ FDE: 0x1a19c0 | Kích thước: 256 bytes
//   0x0b7f24: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0b7f28: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0b7f2c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0b7f30: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0857_0x0b7f24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7f24ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1a19c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0858 | PC: 0x0b86a0 | FDE: 0x1a1a08 | Size: 8 bytes
// Khung tháo gỡ #0858 | Địa chỉ PC: 0x0b86a0 | Địa chỉ FDE: 0x1a1a08 | Kích thước: 8 bytes
//   0x0b86a0: D65F03C0  ret      
//   0x0b86a4: D65F03C0  ret      
static inline uint64_t fde_func_0858_0x0b86a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b86a0ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1a1a08ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0859 | PC: 0x0b86a8 | FDE: 0x1a1a38 | Size: 44 bytes
// Khung tháo gỡ #0859 | Địa chỉ PC: 0x0b86a8 | Địa chỉ FDE: 0x1a1a38 | Kích thước: 44 bytes
//   0x0b86a8: D65F03C0  ret      
//   0x0b86ac: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0b86b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b86b4: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_0859_0x0b86a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b86a8ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x1a1a38ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0860 | PC: 0x0b86d4 | FDE: 0x1a1a90 | Size: 48 bytes
// Khung tháo gỡ #0860 | Địa chỉ PC: 0x0b86d4 | Địa chỉ FDE: 0x1a1a90 | Kích thước: 48 bytes
//   0x0b86d4: AA1E03E3  mov      x3, x30
//   0x0b86d8: 8B000063  add      x3, x3, x0
//   0x0b86dc: AA0303FE  mov      x30, x3
//   0x0b86e0: D65F03C0  ret      
static inline uint64_t fde_func_0860_0x0b86d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b86d4ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x8b000063ULL) ^ 0x1a1a90ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0861 | PC: 0x0b8704 | FDE: 0x1a1ac0 | Size: 36 bytes
// Khung tháo gỡ #0861 | Địa chỉ PC: 0x0b8704 | Địa chỉ FDE: 0x1a1ac0 | Kích thước: 36 bytes
//   0x0b8704: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b8708: AA0003F3  mov      x19, x0
//   0x0b870c: A9400008  ldp      x8, x0, [x0]
//   0x0b8710: D63F0100  blr      x8
static inline uint64_t fde_func_0861_0x0b8704(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8704ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1a1ac0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0862 | PC: 0x0b8728 | FDE: 0x1a1af0 | Size: 52 bytes
// Khung tháo gỡ #0862 | Địa chỉ PC: 0x0b8728 | Địa chỉ FDE: 0x1a1af0 | Kích thước: 52 bytes
//   0x0b8728: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0b872c: A9402009  ldp      x9, x8, [x0]
//   0x0b8730: D63F0120  blr      x9
//   0x0b8734: F84107FE  ldr      x30, [sp], #0x10
static inline uint64_t fde_func_0862_0x0b8728(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8728ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xa9402009ULL) ^ 0x1a1af0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0863 | PC: 0x0b875c | FDE: 0x1a1b20 | Size: 44 bytes
// Khung tháo gỡ #0863 | Địa chỉ PC: 0x0b875c | Địa chỉ FDE: 0x1a1b20 | Kích thước: 44 bytes
//   0x0b875c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b8760: F9400008  ldr      x8, [x0]
//   0x0b8764: AA0003F3  mov      x19, x0
//   0x0b8768: D63F0100  blr      x8
static inline uint64_t fde_func_0863_0x0b875c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b875cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x1a1b20ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0864 | PC: 0x0b8788 | FDE: 0x1a1b50 | Size: 32 bytes
// Khung tháo gỡ #0864 | Địa chỉ PC: 0x0b8788 | Địa chỉ FDE: 0x1a1b50 | Kích thước: 32 bytes
//   0x0b8788: A9402002  ldp      x2, x8, [x0]
//   0x0b878c: F9400801  ldr      x1, [x0, #0x10]
//   0x0b8790: AA0803E0  mov      x0, x8
//   0x0b8794: D61F0040  br       x2
static inline uint64_t fde_func_0864_0x0b8788(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8788ULL ^ (static_cast<uint64_t>(0xa9402002ULL) << 13);
    acc = (acc + a1 + 0xf9400801ULL) ^ 0x1a1b50ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0865 | PC: 0x0b87a8 | FDE: 0x1a1b80 | Size: 36 bytes
// Khung tháo gỡ #0865 | Địa chỉ PC: 0x0b87a8 | Địa chỉ FDE: 0x1a1b80 | Kích thước: 36 bytes
//   0x0b87a8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b87ac: AA0003F3  mov      x19, x0
//   0x0b87b0: A9400008  ldp      x8, x0, [x0]
//   0x0b87b4: D63F0100  blr      x8
static inline uint64_t fde_func_0865_0x0b87a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b87a8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1a1b80ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0866 | PC: 0x0b87cc | FDE: 0x1a1bb0 | Size: 32 bytes
// Khung tháo gỡ #0866 | Địa chỉ PC: 0x0b87cc | Địa chỉ FDE: 0x1a1bb0 | Kích thước: 32 bytes
//   0x0b87cc: A9402003  ldp      x3, x8, [x0]
//   0x0b87d0: A9410801  ldp      x1, x2, [x0, #0x10]
//   0x0b87d4: AA0803E0  mov      x0, x8
//   0x0b87d8: D61F0060  br       x3
static inline uint64_t fde_func_0866_0x0b87cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b87ccULL ^ (static_cast<uint64_t>(0xa9402003ULL) << 13);
    acc = (acc + a1 + 0xa9410801ULL) ^ 0x1a1bb0ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0867 | PC: 0x0b87ec | FDE: 0x1a1be0 | Size: 16 bytes
// Khung tháo gỡ #0867 | Địa chỉ PC: 0x0b87ec | Địa chỉ FDE: 0x1a1be0 | Kích thước: 16 bytes
//   0x0b87ec: A9400001  ldp      x1, x0, [x0]
//   0x0b87f0: D61F0020  br       x1
//   0x0b87f4: A9400001  ldp      x1, x0, [x0]
//   0x0b87f8: D61F0020  br       x1
static inline uint64_t fde_func_0867_0x0b87ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b87ecULL ^ (static_cast<uint64_t>(0xa9400001ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x1a1be0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0868 | PC: 0x0b87fc | FDE: 0x1a1c10 | Size: 20 bytes
// Khung tháo gỡ #0868 | Địa chỉ PC: 0x0b87fc | Địa chỉ FDE: 0x1a1c10 | Kích thước: 20 bytes
//   0x0b87fc: A9400001  ldp      x1, x0, [x0]
//   0x0b8800: D61F0020  br       x1
//   0x0b8804: AA0003E2  mov      x2, x0
//   0x0b8808: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_0868_0x0b87fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b87fcULL ^ (static_cast<uint64_t>(0xa9400001ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x1a1c10ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0869 | PC: 0x0b8810 | FDE: 0x1a1c40 | Size: 60 bytes
// Khung tháo gỡ #0869 | Địa chỉ PC: 0x0b8810 | Địa chỉ FDE: 0x1a1c40 | Kích thước: 60 bytes
//   0x0b8810: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0b8814: F9400008  ldr      x8, [x0]
//   0x0b8818: AA0003F3  mov      x19, x0
//   0x0b881c: D63F0100  blr      x8
static inline uint64_t fde_func_0869_0x0b8810(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8810ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x1a1c40ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0870 | PC: 0x0b884c | FDE: 0x1a1c70 | Size: 256 bytes
// Khung tháo gỡ #0870 | Địa chỉ PC: 0x0b884c | Địa chỉ FDE: 0x1a1c70 | Kích thước: 256 bytes
//   0x0b884c: D104C3FF  sub      sp, sp, #0x130
//   0x0b8850: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x0b8854: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x0b8858: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0870_0x0b884c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b884cULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1a1c70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0871 | PC: 0x0b8e54 | FDE: 0x1a1cd0 | Size: 200 bytes
// Khung tháo gỡ #0871 | Địa chỉ PC: 0x0b8e54 | Địa chỉ FDE: 0x1a1cd0 | Kích thước: 200 bytes
//   0x0b8e54: D10143FF  sub      sp, sp, #0x50
//   0x0b8e58: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0b8e5c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0b8e60: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0871_0x0b8e54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8e54ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x1a1cd0ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0872 | PC: 0x0b8f1c | FDE: 0x1a1d28 | Size: 256 bytes
// Khung tháo gỡ #0872 | Địa chỉ PC: 0x0b8f1c | Địa chỉ FDE: 0x1a1d28 | Kích thước: 256 bytes
//   0x0b8f1c: D102C3FF  sub      sp, sp, #0xb0
//   0x0b8f20: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x0b8f24: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0b8f28: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0872_0x0b8f1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b8f1cULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x1a1d28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0873 | PC: 0x0b9ce0 | FDE: 0x1a1d88 | Size: 28 bytes
// Khung tháo gỡ #0873 | Địa chỉ PC: 0x0b9ce0 | Địa chỉ FDE: 0x1a1d88 | Kích thước: 28 bytes
//   0x0b9ce0: F8616800  ldr      x0, [x0, x1]
//   0x0b9ce4: D65F03C0  ret      
//   0x0b9ce8: AA1E03E4  mov      x4, x30
//   0x0b9cec: 8B000084  add      x4, x4, x0
static inline uint64_t fde_func_0873_0x0b9ce0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b9ce0ULL ^ (static_cast<uint64_t>(0xf8616800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1a1d88ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0874 | PC: 0x0b9cfc | FDE: 0x1a1dd8 | Size: 256 bytes
// Khung tháo gỡ #0874 | Địa chỉ PC: 0x0b9cfc | Địa chỉ FDE: 0x1a1dd8 | Kích thước: 256 bytes
//   0x0b9cfc: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0b9d00: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0b9d04: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0b9d08: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0874_0x0b9cfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b9cfcULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1a1dd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0875 | PC: 0x0baf60 | FDE: 0x1a1eb0 | Size: 240 bytes
// Khung tháo gỡ #0875 | Địa chỉ PC: 0x0baf60 | Địa chỉ FDE: 0x1a1eb0 | Kích thước: 240 bytes
//   0x0baf60: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0baf64: 910003FD  mov      x29, sp
//   0x0baf68: F0000908  adrp     x8, #0x1dd000
//   0x0baf6c: 91054108  add      x8, x8, #0x150
static inline uint64_t fde_func_0875_0x0baf60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0baf60ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a1eb0ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0876 | PC: 0x0bb050 | FDE: 0x1a1ef0 | Size: 256 bytes
// Khung tháo gỡ #0876 | Địa chỉ PC: 0x0bb050 | Địa chỉ FDE: 0x1a1ef0 | Kích thước: 256 bytes
//   0x0bb050: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0bb054: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0bb058: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0bb05c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0876_0x0bb050(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb050ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1a1ef0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0877 | PC: 0x0bb80c | FDE: 0x1a1f50 | Size: 256 bytes
// Khung tháo gỡ #0877 | Địa chỉ PC: 0x0bb80c | Địa chỉ FDE: 0x1a1f50 | Kích thước: 256 bytes
//   0x0bb80c: D10603FF  sub      sp, sp, #0x180
//   0x0bb810: A9126FFC  stp      x28, x27, [sp, #0x120]
//   0x0bb814: A91367FA  stp      x26, x25, [sp, #0x130]
//   0x0bb818: A9145FF8  stp      x24, x23, [sp, #0x140]
static inline uint64_t fde_func_0877_0x0bb80c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb80cULL ^ (static_cast<uint64_t>(0xd10603ffULL) << 13);
    acc = (acc + a1 + 0xa9126ffcULL) ^ 0x1a1f50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0878 | PC: 0x0bc170 | FDE: 0x1a1fb0 | Size: 256 bytes
// Khung tháo gỡ #0878 | Địa chỉ PC: 0x0bc170 | Địa chỉ FDE: 0x1a1fb0 | Kích thước: 256 bytes
//   0x0bc170: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0bc174: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0bc178: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0bc17c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0878_0x0bc170(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bc170ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1a1fb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0879 | PC: 0x0bc388 | FDE: 0x1a2000 | Size: 256 bytes
// Khung tháo gỡ #0879 | Địa chỉ PC: 0x0bc388 | Địa chỉ FDE: 0x1a2000 | Kích thước: 256 bytes
//   0x0bc388: D101C3FF  sub      sp, sp, #0x70
//   0x0bc38c: F90013F9  str      x25, [sp, #0x20]
//   0x0bc390: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0bc394: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0879_0x0bc388(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bc388ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x1a2000ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0880 | PC: 0x0bc680 | FDE: 0x1a2078 | Size: 188 bytes
// Khung tháo gỡ #0880 | Địa chỉ PC: 0x0bc680 | Địa chỉ FDE: 0x1a2078 | Kích thước: 188 bytes
//   0x0bc680: AA1E03E5  mov      x5, x30
//   0x0bc684: 8B0000A5  add      x5, x5, x0
//   0x0bc688: AA0503FE  mov      x30, x5
//   0x0bc68c: D65F03C0  ret      
static inline uint64_t fde_func_0880_0x0bc680(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bc680ULL ^ (static_cast<uint64_t>(0xaa1e03e5ULL) << 13);
    acc = (acc + a1 + 0x8b0000a5ULL) ^ 0x1a2078ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0881 | PC: 0x0bc73c | FDE: 0x1a20b8 | Size: 256 bytes
// Khung tháo gỡ #0881 | Địa chỉ PC: 0x0bc73c | Địa chỉ FDE: 0x1a20b8 | Kích thước: 256 bytes
//   0x0bc73c: D107C3FF  sub      sp, sp, #0x1f0
//   0x0bc740: A91C57FC  stp      x28, x21, [sp, #0x1c0]
//   0x0bc744: A91D4FF4  stp      x20, x19, [sp, #0x1d0]
//   0x0bc748: A91E7BFD  stp      x29, x30, [sp, #0x1e0]
static inline uint64_t fde_func_0881_0x0bc73c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bc73cULL ^ (static_cast<uint64_t>(0xd107c3ffULL) << 13);
    acc = (acc + a1 + 0xa91c57fcULL) ^ 0x1a20b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0882 | PC: 0x0bc934 | FDE: 0x1a2100 | Size: 256 bytes
// Khung tháo gỡ #0882 | Địa chỉ PC: 0x0bc934 | Địa chỉ FDE: 0x1a2100 | Kích thước: 256 bytes
//   0x0bc934: D10303FF  sub      sp, sp, #0xc0
//   0x0bc938: A90A4FF4  stp      x20, x19, [sp, #0xa0]
//   0x0bc93c: A90B7BFD  stp      x29, x30, [sp, #0xb0]
//   0x0bc940: 9102C3FD  add      x29, sp, #0xb0
static inline uint64_t fde_func_0882_0x0bc934(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bc934ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90a4ff4ULL) ^ 0x1a2100ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0883 | PC: 0x0bca64 | FDE: 0x1a2160 | Size: 256 bytes
// Khung tháo gỡ #0883 | Địa chỉ PC: 0x0bca64 | Địa chỉ FDE: 0x1a2160 | Kích thước: 256 bytes
//   0x0bca64: D10683FF  sub      sp, sp, #0x1a0
//   0x0bca68: A91757FC  stp      x28, x21, [sp, #0x170]
//   0x0bca6c: A9184FF4  stp      x20, x19, [sp, #0x180]
//   0x0bca70: A9197BFD  stp      x29, x30, [sp, #0x190]
static inline uint64_t fde_func_0883_0x0bca64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bca64ULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xa91757fcULL) ^ 0x1a2160ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0884 | PC: 0x0bcdc4 | FDE: 0x1a21a0 | Size: 256 bytes
// Khung tháo gỡ #0884 | Địa chỉ PC: 0x0bcdc4 | Địa chỉ FDE: 0x1a21a0 | Kích thước: 256 bytes
//   0x0bcdc4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bcdc8: 910003FD  mov      x29, sp
//   0x0bcdcc: A940A408  ldp      x8, x9, [x0, #8]
//   0x0bcdd0: EB09011F  cmp      x8, x9
static inline uint64_t fde_func_0884_0x0bcdc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bcdc4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a21a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0885 | PC: 0x0bcefc | FDE: 0x1a21e0 | Size: 256 bytes
// Khung tháo gỡ #0885 | Địa chỉ PC: 0x0bcefc | Địa chỉ FDE: 0x1a21e0 | Kích thước: 256 bytes
//   0x0bcefc: D10283FF  sub      sp, sp, #0xa0
//   0x0bcf00: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x0bcf04: 910243FD  add      x29, sp, #0x90
//   0x0bcf08: D53BD04B  mrs      x11, tpidr_el0
static inline uint64_t fde_func_0885_0x0bcefc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bcefcULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9097bfdULL) ^ 0x1a21e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0886 | PC: 0x0bd048 | FDE: 0x1a2220 | Size: 16 bytes
// Khung tháo gỡ #0886 | Địa chỉ PC: 0x0bd048 | Địa chỉ FDE: 0x1a2220 | Kích thước: 16 bytes
//   0x0bd048: F9400000  ldr      x0, [x0]
//   0x0bd04c: D65F03C0  ret      
//   0x0bd050: F9400400  ldr      x0, [x0, #8]
//   0x0bd054: D65F03C0  ret      
static inline uint64_t fde_func_0886_0x0bd048(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bd048ULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1a2220ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0887 | PC: 0x0bd058 | FDE: 0x1a2250 | Size: 48 bytes
// Khung tháo gỡ #0887 | Địa chỉ PC: 0x0bd058 | Địa chỉ FDE: 0x1a2250 | Kích thước: 48 bytes
//   0x0bd058: F9400008  ldr      x8, [x0]
//   0x0bd05c: 8B010D00  add      x0, x8, x1, lsl #3
//   0x0bd060: D65F03C0  ret      
//   0x0bd064: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
static inline uint64_t fde_func_0887_0x0bd058(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bd058ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0x8b010d00ULL) ^ 0x1a2250ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0888 | PC: 0x0bd088 | FDE: 0x1a2288 | Size: 244 bytes
// Khung tháo gỡ #0888 | Địa chỉ PC: 0x0bd088 | Địa chỉ FDE: 0x1a2288 | Kích thước: 244 bytes
//   0x0bd088: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bd08c: 910003FD  mov      x29, sp
//   0x0bd090: 90000900  adrp     x0, #0x1dd000
//   0x0bd094: 910A2000  add      x0, x0, #0x288
static inline uint64_t fde_func_0888_0x0bd088(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bd088ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a2288ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #0889 | PC: 0x0bd17c | FDE: 0x1a22d0 | Size: 256 bytes
// Khung tháo gỡ #0889 | Địa chỉ PC: 0x0bd17c | Địa chỉ FDE: 0x1a22d0 | Kích thước: 256 bytes
//   0x0bd17c: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x0bd180: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0bd184: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0bd188: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0889_0x0bd17c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bd17cULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1a22d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0890 | PC: 0x0bd810 | FDE: 0x1a2318 | Size: 256 bytes
// Khung tháo gỡ #0890 | Địa chỉ PC: 0x0bd810 | Địa chỉ FDE: 0x1a2318 | Kích thước: 256 bytes
//   0x0bd810: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bd814: 910003FD  mov      x29, sp
//   0x0bd818: CB000028  sub      x8, x1, x0
//   0x0bd81c: 9343FD08  asr      x8, x8, #3
static inline uint64_t fde_func_0890_0x0bd810(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bd810ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a2318ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0891 | PC: 0x0bda7c | FDE: 0x1a2370 | Size: 60 bytes
// Khung tháo gỡ #0891 | Địa chỉ PC: 0x0bda7c | Địa chỉ FDE: 0x1a2370 | Kích thước: 60 bytes
//   0x0bda7c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0bda80: AA0003F3  mov      x19, x0
//   0x0bda84: A9400008  ldp      x8, x0, [x0]
//   0x0bda88: D63F0100  blr      x8
static inline uint64_t fde_func_0891_0x0bda7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bda7cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1a2370ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0892 | PC: 0x0bdab8 | FDE: 0x1a23a0 | Size: 16 bytes
// Khung tháo gỡ #0892 | Địa chỉ PC: 0x0bdab8 | Địa chỉ FDE: 0x1a23a0 | Kích thước: 16 bytes
//   0x0bdab8: A9400001  ldp      x1, x0, [x0]
//   0x0bdabc: D61F0020  br       x1
//   0x0bdac0: A9400001  ldp      x1, x0, [x0]
//   0x0bdac4: D61F0020  br       x1
static inline uint64_t fde_func_0892_0x0bdab8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bdab8ULL ^ (static_cast<uint64_t>(0xa9400001ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x1a23a0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0893 | PC: 0x0bdac8 | FDE: 0x1a23d0 | Size: 44 bytes
// Khung tháo gỡ #0893 | Địa chỉ PC: 0x0bdac8 | Địa chỉ FDE: 0x1a23d0 | Kích thước: 44 bytes
//   0x0bdac8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0bdacc: AA0003F3  mov      x19, x0
//   0x0bdad0: A9400008  ldp      x8, x0, [x0]
//   0x0bdad4: D63F0100  blr      x8
static inline uint64_t fde_func_0893_0x0bdac8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bdac8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1a23d0ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0894 | PC: 0x0bdaf4 | FDE: 0x1a2400 | Size: 60 bytes
// Khung tháo gỡ #0894 | Địa chỉ PC: 0x0bdaf4 | Địa chỉ FDE: 0x1a2400 | Kích thước: 60 bytes
//   0x0bdaf4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0bdaf8: AA0003F3  mov      x19, x0
//   0x0bdafc: A9400008  ldp      x8, x0, [x0]
//   0x0bdb00: F9400A61  ldr      x1, [x19, #0x10]
static inline uint64_t fde_func_0894_0x0bdaf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bdaf4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1a2400ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0895 | PC: 0x0bdb30 | FDE: 0x1a2430 | Size: 28 bytes
// Khung tháo gỡ #0895 | Địa chỉ PC: 0x0bdb30 | Địa chỉ FDE: 0x1a2430 | Kích thước: 28 bytes
//   0x0bdb30: A9402002  ldp      x2, x8, [x0]
//   0x0bdb34: F9400801  ldr      x1, [x0, #0x10]
//   0x0bdb38: AA0803E0  mov      x0, x8
//   0x0bdb3c: D61F0040  br       x2
static inline uint64_t fde_func_0895_0x0bdb30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bdb30ULL ^ (static_cast<uint64_t>(0xa9402002ULL) << 13);
    acc = (acc + a1 + 0xf9400801ULL) ^ 0x1a2430ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0896 | PC: 0x0bdb4c | FDE: 0x1a24b8 | Size: 256 bytes
// Khung tháo gỡ #0896 | Địa chỉ PC: 0x0bdb4c | Địa chỉ FDE: 0x1a24b8 | Kích thước: 256 bytes
//   0x0bdb4c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0bdb50: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0bdb54: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0bdb58: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0896_0x0bdb4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bdb4cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1a24b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0897 | PC: 0x0be35c | FDE: 0x1a2508 | Size: 240 bytes
// Khung tháo gỡ #0897 | Địa chỉ PC: 0x0be35c | Địa chỉ FDE: 0x1a2508 | Kích thước: 240 bytes
//   0x0be35c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0be360: 910003FD  mov      x29, sp
//   0x0be364: F00008E8  adrp     x8, #0x1dd000
//   0x0be368: 91212108  add      x8, x8, #0x848
static inline uint64_t fde_func_0897_0x0be35c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0be35cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a2508ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0898 | PC: 0x0be44c | FDE: 0x1a2548 | Size: 240 bytes
// Khung tháo gỡ #0898 | Địa chỉ PC: 0x0be44c | Địa chỉ FDE: 0x1a2548 | Kích thước: 240 bytes
//   0x0be44c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0be450: 910003FD  mov      x29, sp
//   0x0be454: F00008E8  adrp     x8, #0x1dd000
//   0x0be458: 9121A108  add      x8, x8, #0x868
static inline uint64_t fde_func_0898_0x0be44c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0be44cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a2548ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0899 | PC: 0x0be53c | FDE: 0x1a2588 | Size: 256 bytes
// Khung tháo gỡ #0899 | Địa chỉ PC: 0x0be53c | Địa chỉ FDE: 0x1a2588 | Kích thước: 256 bytes
//   0x0be53c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0be540: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0be544: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0be548: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0899_0x0be53c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0be53cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1a2588ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0900 | PC: 0x0beef8 | FDE: 0x1a25d8 | Size: 256 bytes
// Khung tháo gỡ #0900 | Địa chỉ PC: 0x0beef8 | Địa chỉ FDE: 0x1a25d8 | Kích thước: 256 bytes
//   0x0beef8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0beefc: 910003FD  mov      x29, sp
//   0x0bef00: F00008E8  adrp     x8, #0x1dd000
//   0x0bef04: 91226108  add      x8, x8, #0x898
static inline uint64_t fde_func_0900_0x0beef8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0beef8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a25d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0901 | PC: 0x0bf018 | FDE: 0x1a2618 | Size: 256 bytes
// Khung tháo gỡ #0901 | Địa chỉ PC: 0x0bf018 | Địa chỉ FDE: 0x1a2618 | Kích thước: 256 bytes
//   0x0bf018: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bf01c: 910003FD  mov      x29, sp
//   0x0bf020: D00008E8  adrp     x8, #0x1dd000
//   0x0bf024: 9122E108  add      x8, x8, #0x8b8
static inline uint64_t fde_func_0901_0x0bf018(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf018ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a2618ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0902 | PC: 0x0bf118 | FDE: 0x1a2658 | Size: 240 bytes
// Khung tháo gỡ #0902 | Địa chỉ PC: 0x0bf118 | Địa chỉ FDE: 0x1a2658 | Kích thước: 240 bytes
//   0x0bf118: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bf11c: 910003FD  mov      x29, sp
//   0x0bf120: D00008E8  adrp     x8, #0x1dd000
//   0x0bf124: 91236108  add      x8, x8, #0x8d8
static inline uint64_t fde_func_0902_0x0bf118(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf118ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a2658ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0903 | PC: 0x0bf208 | FDE: 0x1a2698 | Size: 248 bytes
// Khung tháo gỡ #0903 | Địa chỉ PC: 0x0bf208 | Địa chỉ FDE: 0x1a2698 | Kích thước: 248 bytes
//   0x0bf208: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bf20c: 910003FD  mov      x29, sp
//   0x0bf210: D00008E8  adrp     x8, #0x1dd000
//   0x0bf214: 9123E108  add      x8, x8, #0x8f8
static inline uint64_t fde_func_0903_0x0bf208(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf208ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a2698ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0904 | PC: 0x0bf300 | FDE: 0x1a26d8 | Size: 248 bytes
// Khung tháo gỡ #0904 | Địa chỉ PC: 0x0bf300 | Địa chỉ FDE: 0x1a26d8 | Kích thước: 248 bytes
//   0x0bf300: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bf304: 910003FD  mov      x29, sp
//   0x0bf308: D00008E8  adrp     x8, #0x1dd000
//   0x0bf30c: 91246108  add      x8, x8, #0x918
static inline uint64_t fde_func_0904_0x0bf300(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf300ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a26d8ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0905 | PC: 0x0bf3f8 | FDE: 0x1a2718 | Size: 248 bytes
// Khung tháo gỡ #0905 | Địa chỉ PC: 0x0bf3f8 | Địa chỉ FDE: 0x1a2718 | Kích thước: 248 bytes
//   0x0bf3f8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bf3fc: 910003FD  mov      x29, sp
//   0x0bf400: D00008E8  adrp     x8, #0x1dd000
//   0x0bf404: 9124E108  add      x8, x8, #0x938
static inline uint64_t fde_func_0905_0x0bf3f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf3f8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a2718ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0906 | PC: 0x0bf4f0 | FDE: 0x1a2758 | Size: 240 bytes
// Khung tháo gỡ #0906 | Địa chỉ PC: 0x0bf4f0 | Địa chỉ FDE: 0x1a2758 | Kích thước: 240 bytes
//   0x0bf4f0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bf4f4: 910003FD  mov      x29, sp
//   0x0bf4f8: D00008E8  adrp     x8, #0x1dd000
//   0x0bf4fc: 91256108  add      x8, x8, #0x958
static inline uint64_t fde_func_0906_0x0bf4f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf4f0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a2758ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0907 | PC: 0x0bf5e0 | FDE: 0x1a2798 | Size: 256 bytes
// Khung tháo gỡ #0907 | Địa chỉ PC: 0x0bf5e0 | Địa chỉ FDE: 0x1a2798 | Kích thước: 256 bytes
//   0x0bf5e0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bf5e4: 910003FD  mov      x29, sp
//   0x0bf5e8: D00008E8  adrp     x8, #0x1dd000
//   0x0bf5ec: 9125E108  add      x8, x8, #0x978
static inline uint64_t fde_func_0907_0x0bf5e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf5e0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a2798ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0908 | PC: 0x0bf6e0 | FDE: 0x1a27d8 | Size: 256 bytes
// Khung tháo gỡ #0908 | Địa chỉ PC: 0x0bf6e0 | Địa chỉ FDE: 0x1a27d8 | Kích thước: 256 bytes
//   0x0bf6e0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bf6e4: 910003FD  mov      x29, sp
//   0x0bf6e8: D00008E8  adrp     x8, #0x1dd000
//   0x0bf6ec: 91266108  add      x8, x8, #0x998
static inline uint64_t fde_func_0908_0x0bf6e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf6e0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a27d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0909 | PC: 0x0bf7ec | FDE: 0x1a2818 | Size: 256 bytes
// Khung tháo gỡ #0909 | Địa chỉ PC: 0x0bf7ec | Địa chỉ FDE: 0x1a2818 | Kích thước: 256 bytes
//   0x0bf7ec: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bf7f0: 910003FD  mov      x29, sp
//   0x0bf7f4: D00008E8  adrp     x8, #0x1dd000
//   0x0bf7f8: 9126E108  add      x8, x8, #0x9b8
static inline uint64_t fde_func_0909_0x0bf7ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf7ecULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a2818ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0910 | PC: 0x0bf8ec | FDE: 0x1a2858 | Size: 248 bytes
// Khung tháo gỡ #0910 | Địa chỉ PC: 0x0bf8ec | Địa chỉ FDE: 0x1a2858 | Kích thước: 248 bytes
//   0x0bf8ec: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bf8f0: 910003FD  mov      x29, sp
//   0x0bf8f4: D00008E8  adrp     x8, #0x1dd000
//   0x0bf8f8: 91276108  add      x8, x8, #0x9d8
static inline uint64_t fde_func_0910_0x0bf8ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf8ecULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a2858ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0911 | PC: 0x0bf9e4 | FDE: 0x1a2898 | Size: 256 bytes
// Khung tháo gỡ #0911 | Địa chỉ PC: 0x0bf9e4 | Địa chỉ FDE: 0x1a2898 | Kích thước: 256 bytes
//   0x0bf9e4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bf9e8: 910003FD  mov      x29, sp
//   0x0bf9ec: D00008E8  adrp     x8, #0x1dd000
//   0x0bf9f0: 9127E108  add      x8, x8, #0x9f8
static inline uint64_t fde_func_0911_0x0bf9e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf9e4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a2898ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0912 | PC: 0x0bfaf0 | FDE: 0x1a28d8 | Size: 248 bytes
// Khung tháo gỡ #0912 | Địa chỉ PC: 0x0bfaf0 | Địa chỉ FDE: 0x1a28d8 | Kích thước: 248 bytes
//   0x0bfaf0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bfaf4: 910003FD  mov      x29, sp
//   0x0bfaf8: D00008E8  adrp     x8, #0x1dd000
//   0x0bfafc: 91286108  add      x8, x8, #0xa18
static inline uint64_t fde_func_0912_0x0bfaf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bfaf0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a28d8ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0913 | PC: 0x0bfbe8 | FDE: 0x1a2918 | Size: 240 bytes
// Khung tháo gỡ #0913 | Địa chỉ PC: 0x0bfbe8 | Địa chỉ FDE: 0x1a2918 | Kích thước: 240 bytes
//   0x0bfbe8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bfbec: 910003FD  mov      x29, sp
//   0x0bfbf0: D00008E8  adrp     x8, #0x1dd000
//   0x0bfbf4: 9128E108  add      x8, x8, #0xa38
static inline uint64_t fde_func_0913_0x0bfbe8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bfbe8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a2918ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0914 | PC: 0x0bfcd8 | FDE: 0x1a2958 | Size: 256 bytes
// Khung tháo gỡ #0914 | Địa chỉ PC: 0x0bfcd8 | Địa chỉ FDE: 0x1a2958 | Kích thước: 256 bytes
//   0x0bfcd8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bfcdc: 910003FD  mov      x29, sp
//   0x0bfce0: D00008E8  adrp     x8, #0x1dd000
//   0x0bfce4: 91296108  add      x8, x8, #0xa58
static inline uint64_t fde_func_0914_0x0bfcd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bfcd8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a2958ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0915 | PC: 0x0bfed8 | FDE: 0x1a29a8 | Size: 256 bytes
// Khung tháo gỡ #0915 | Địa chỉ PC: 0x0bfed8 | Địa chỉ FDE: 0x1a29a8 | Kích thước: 256 bytes
//   0x0bfed8: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x0bfedc: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0bfee0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0bfee4: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0915_0x0bfed8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bfed8ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1a29a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0916 | PC: 0x0c22d8 | FDE: 0x1a2a80 | Size: 256 bytes
// Khung tháo gỡ #0916 | Địa chỉ PC: 0x0c22d8 | Địa chỉ FDE: 0x1a2a80 | Kích thước: 256 bytes
//   0x0c22d8: D10283FF  sub      sp, sp, #0xa0
//   0x0c22dc: F90023FB  str      x27, [sp, #0x40]
//   0x0c22e0: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0c22e4: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0916_0x0c22d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c22d8ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90023fbULL) ^ 0x1a2a80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0917 | PC: 0x0c24c8 | FDE: 0x1a2ad8 | Size: 256 bytes
// Khung tháo gỡ #0917 | Địa chỉ PC: 0x0c24c8 | Địa chỉ FDE: 0x1a2ad8 | Kích thước: 256 bytes
//   0x0c24c8: D10203FF  sub      sp, sp, #0x80
//   0x0c24cc: F9001BF9  str      x25, [sp, #0x30]
//   0x0c24d0: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0c24d4: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_0917_0x0c24c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c24c8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf9ULL) ^ 0x1a2ad8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0918 | PC: 0x0c27c4 | FDE: 0x1a2b30 | Size: 256 bytes
// Khung tháo gỡ #0918 | Địa chỉ PC: 0x0c27c4 | Địa chỉ FDE: 0x1a2b30 | Kích thước: 256 bytes
//   0x0c27c4: D10483FF  sub      sp, sp, #0x120
//   0x0c27c8: A9104FFC  stp      x28, x19, [sp, #0x100]
//   0x0c27cc: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x0c27d0: 910443FD  add      x29, sp, #0x110
static inline uint64_t fde_func_0918_0x0c27c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c27c4ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa9104ffcULL) ^ 0x1a2b30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0919 | PC: 0x0c2944 | FDE: 0x1a2be8 | Size: 256 bytes
// Khung tháo gỡ #0919 | Địa chỉ PC: 0x0c2944 | Địa chỉ FDE: 0x1a2be8 | Kích thước: 256 bytes
//   0x0c2944: D10283FF  sub      sp, sp, #0xa0
//   0x0c2948: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x0c294c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0c2950: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0919_0x0c2944(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2944ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1a2be8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0920 | PC: 0x0c2b8c | FDE: 0x1a2c38 | Size: 256 bytes
// Khung tháo gỡ #0920 | Địa chỉ PC: 0x0c2b8c | Địa chỉ FDE: 0x1a2c38 | Kích thước: 256 bytes
//   0x0c2b8c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c2b90: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c2b94: 910043FD  add      x29, sp, #0x10
//   0x0c2b98: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0920_0x0c2b8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2b8cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a2c38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0921 | PC: 0x0c2ca8 | FDE: 0x1a2cf0 | Size: 256 bytes
// Khung tháo gỡ #0921 | Địa chỉ PC: 0x0c2ca8 | Địa chỉ FDE: 0x1a2cf0 | Kích thước: 256 bytes
//   0x0c2ca8: D10283FF  sub      sp, sp, #0xa0
//   0x0c2cac: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0c2cb0: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x0c2cb4: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_0921_0x0c2ca8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2ca8ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa90757f6ULL) ^ 0x1a2cf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0922 | PC: 0x0c2f70 | FDE: 0x1a2d38 | Size: 60 bytes
// Khung tháo gỡ #0922 | Địa chỉ PC: 0x0c2f70 | Địa chỉ FDE: 0x1a2d38 | Kích thước: 60 bytes
//   0x0c2f70: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c2f74: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c2f78: 910043FD  add      x29, sp, #0x10
//   0x0c2f7c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0922_0x0c2f70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2f70ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a2d38ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0923 | PC: 0x0c2fac | FDE: 0x1a2de8 | Size: 256 bytes
// Khung tháo gỡ #0923 | Địa chỉ PC: 0x0c2fac | Địa chỉ FDE: 0x1a2de8 | Kích thước: 256 bytes
//   0x0c2fac: D10143FF  sub      sp, sp, #0x50
//   0x0c2fb0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c2fb4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0c2fb8: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0923_0x0c2fac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2facULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x1a2de8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0924 | PC: 0x0c30f8 | FDE: 0x1a2e28 | Size: 256 bytes
// Khung tháo gỡ #0924 | Địa chỉ PC: 0x0c30f8 | Địa chỉ FDE: 0x1a2e28 | Kích thước: 256 bytes
//   0x0c30f8: D10243FF  sub      sp, sp, #0x90
//   0x0c30fc: F9002BF7  str      x23, [sp, #0x50]
//   0x0c3100: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x0c3104: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_0924_0x0c30f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c30f8ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf7ULL) ^ 0x1a2e28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0925 | PC: 0x0c3600 | FDE: 0x1a2e78 | Size: 256 bytes
// Khung tháo gỡ #0925 | Địa chỉ PC: 0x0c3600 | Địa chỉ FDE: 0x1a2e78 | Kích thước: 256 bytes
//   0x0c3600: D10683FF  sub      sp, sp, #0x1a0
//   0x0c3604: F900B3FC  str      x28, [sp, #0x160]
//   0x0c3608: A91757F6  stp      x22, x21, [sp, #0x170]
//   0x0c360c: A9184FF4  stp      x20, x19, [sp, #0x180]
static inline uint64_t fde_func_0925_0x0c3600(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3600ULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xf900b3fcULL) ^ 0x1a2e78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0926 | PC: 0x0c3c58 | FDE: 0x1a2ec8 | Size: 256 bytes
// Khung tháo gỡ #0926 | Địa chỉ PC: 0x0c3c58 | Địa chỉ FDE: 0x1a2ec8 | Kích thước: 256 bytes
//   0x0c3c58: D10303FF  sub      sp, sp, #0xc0
//   0x0c3c5c: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x0c3c60: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x0c3c64: A90957F6  stp      x22, x21, [sp, #0x90]
static inline uint64_t fde_func_0926_0x0c3c58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3c58ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90767faULL) ^ 0x1a2ec8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0927 | PC: 0x0c42d4 | FDE: 0x1a2f28 | Size: 176 bytes
// Khung tháo gỡ #0927 | Địa chỉ PC: 0x0c42d4 | Địa chỉ FDE: 0x1a2f28 | Kích thước: 176 bytes
//   0x0c42d4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c42d8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c42dc: 910043FD  add      x29, sp, #0x10
//   0x0c42e0: B0000808  adrp     x8, #0x1c5000
static inline uint64_t fde_func_0927_0x0c42d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c42d4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a2f28ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #0928 | PC: 0x0c4384 | FDE: 0x1a2f68 | Size: 24 bytes
// Khung tháo gỡ #0928 | Địa chỉ PC: 0x0c4384 | Địa chỉ FDE: 0x1a2f68 | Kích thước: 24 bytes
//   0x0c4384: D65F03C0  ret      
//   0x0c4388: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0c438c: 910003FD  mov      x29, sp
//   0x0c4390: 97FDA740  bl       #0x2e090
static inline uint64_t fde_func_0928_0x0c4384(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c4384ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x1a2f68ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0929 | PC: 0x0c439c | FDE: 0x1a2fc0 | Size: 256 bytes
// Khung tháo gỡ #0929 | Địa chỉ PC: 0x0c439c | Địa chỉ FDE: 0x1a2fc0 | Kích thước: 256 bytes
//   0x0c439c: AA1E03E2  mov      x2, x30
//   0x0c43a0: 8B000042  add      x2, x2, x0
//   0x0c43a4: AA0203FE  mov      x30, x2
//   0x0c43a8: D65F03C0  ret      
static inline uint64_t fde_func_0929_0x0c439c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c439cULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x8b000042ULL) ^ 0x1a2fc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0930 | PC: 0x0c45a0 | FDE: 0x1a3050 | Size: 256 bytes
// Khung tháo gỡ #0930 | Địa chỉ PC: 0x0c45a0 | Địa chỉ FDE: 0x1a3050 | Kích thước: 256 bytes
//   0x0c45a0: D10143FF  sub      sp, sp, #0x50
//   0x0c45a4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c45a8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c45ac: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0930_0x0c45a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c45a0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1a3050ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0931 | PC: 0x0c4928 | FDE: 0x1a30a0 | Size: 256 bytes
// Khung tháo gỡ #0931 | Địa chỉ PC: 0x0c4928 | Địa chỉ FDE: 0x1a30a0 | Kích thước: 256 bytes
//   0x0c4928: D104C3FF  sub      sp, sp, #0x130
//   0x0c492c: F90073FC  str      x28, [sp, #0xe0]
//   0x0c4930: A90F5FF8  stp      x24, x23, [sp, #0xf0]
//   0x0c4934: A91057F6  stp      x22, x21, [sp, #0x100]
static inline uint64_t fde_func_0931_0x0c4928(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c4928ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xf90073fcULL) ^ 0x1a30a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0932 | PC: 0x0c4d80 | FDE: 0x1a30f0 | Size: 212 bytes
// Khung tháo gỡ #0932 | Địa chỉ PC: 0x0c4d80 | Địa chỉ FDE: 0x1a30f0 | Kích thước: 212 bytes
//   0x0c4d80: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0c4d84: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c4d88: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c4d8c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0932_0x0c4d80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c4d80ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1a30f0ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0933 | PC: 0x0c4e54 | FDE: 0x1a3130 | Size: 72 bytes
// Khung tháo gỡ #0933 | Địa chỉ PC: 0x0c4e54 | Địa chỉ FDE: 0x1a3130 | Kích thước: 72 bytes
//   0x0c4e54: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c4e58: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c4e5c: 910043FD  add      x29, sp, #0x10
//   0x0c4e60: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0933_0x0c4e54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c4e54ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a3130ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0934 | PC: 0x0c4e9c | FDE: 0x1a31e0 | Size: 256 bytes
// Khung tháo gỡ #0934 | Địa chỉ PC: 0x0c4e9c | Địa chỉ FDE: 0x1a31e0 | Kích thước: 256 bytes
//   0x0c4e9c: D10143FF  sub      sp, sp, #0x50
//   0x0c4ea0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c4ea4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0c4ea8: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0934_0x0c4e9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c4e9cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x1a31e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0935 | PC: 0x0c5028 | FDE: 0x1a3220 | Size: 256 bytes
// Khung tháo gỡ #0935 | Địa chỉ PC: 0x0c5028 | Địa chỉ FDE: 0x1a3220 | Kích thước: 256 bytes
//   0x0c5028: D10603FF  sub      sp, sp, #0x180
//   0x0c502c: A9126FFC  stp      x28, x27, [sp, #0x120]
//   0x0c5030: A91367FA  stp      x26, x25, [sp, #0x130]
//   0x0c5034: A9145FF8  stp      x24, x23, [sp, #0x140]
static inline uint64_t fde_func_0935_0x0c5028(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c5028ULL ^ (static_cast<uint64_t>(0xd10603ffULL) << 13);
    acc = (acc + a1 + 0xa9126ffcULL) ^ 0x1a3220ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0936 | PC: 0x0c55d8 | FDE: 0x1a3270 | Size: 180 bytes
// Khung tháo gỡ #0936 | Địa chỉ PC: 0x0c55d8 | Địa chỉ FDE: 0x1a3270 | Kích thước: 180 bytes
//   0x0c55d8: D10143FF  sub      sp, sp, #0x50
//   0x0c55dc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c55e0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0c55e4: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0936_0x0c55d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c55d8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x1a3270ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #0937 | PC: 0x0c568c | FDE: 0x1a3320 | Size: 256 bytes
// Khung tháo gỡ #0937 | Địa chỉ PC: 0x0c568c | Địa chỉ FDE: 0x1a3320 | Kích thước: 256 bytes
//   0x0c568c: D10743FF  sub      sp, sp, #0x1d0
//   0x0c5690: F900BBFC  str      x28, [sp, #0x170]
//   0x0c5694: A91867FA  stp      x26, x25, [sp, #0x180]
//   0x0c5698: A9195FF8  stp      x24, x23, [sp, #0x190]
static inline uint64_t fde_func_0937_0x0c568c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c568cULL ^ (static_cast<uint64_t>(0xd10743ffULL) << 13);
    acc = (acc + a1 + 0xf900bbfcULL) ^ 0x1a3320ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0938 | PC: 0x0c5c94 | FDE: 0x1a3370 | Size: 256 bytes
// Khung tháo gỡ #0938 | Địa chỉ PC: 0x0c5c94 | Địa chỉ FDE: 0x1a3370 | Kích thước: 256 bytes
//   0x0c5c94: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0c5c98: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0c5c9c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0c5ca0: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0938_0x0c5c94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c5c94ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1a3370ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0939 | PC: 0x0c7a38 | FDE: 0x1a33d0 | Size: 256 bytes
// Khung tháo gỡ #0939 | Địa chỉ PC: 0x0c7a38 | Địa chỉ FDE: 0x1a33d0 | Kích thước: 256 bytes
//   0x0c7a38: D10483FF  sub      sp, sp, #0x120
//   0x0c7a3c: A9104FFC  stp      x28, x19, [sp, #0x100]
//   0x0c7a40: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x0c7a44: 910443FD  add      x29, sp, #0x110
static inline uint64_t fde_func_0939_0x0c7a38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c7a38ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa9104ffcULL) ^ 0x1a33d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0940 | PC: 0x0c7da0 | FDE: 0x1a3420 | Size: 256 bytes
// Khung tháo gỡ #0940 | Địa chỉ PC: 0x0c7da0 | Địa chỉ FDE: 0x1a3420 | Kích thước: 256 bytes
//   0x0c7da0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0c7da4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c7da8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c7dac: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0940_0x0c7da0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c7da0ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1a3420ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0941 | PC: 0x0c7ebc | FDE: 0x1a34d8 | Size: 256 bytes
// Khung tháo gỡ #0941 | Địa chỉ PC: 0x0c7ebc | Địa chỉ FDE: 0x1a34d8 | Kích thước: 256 bytes
//   0x0c7ebc: D10143FF  sub      sp, sp, #0x50
//   0x0c7ec0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c7ec4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0c7ec8: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0941_0x0c7ebc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c7ebcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x1a34d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0942 | PC: 0x0c8230 | FDE: 0x1a3528 | Size: 256 bytes
// Khung tháo gỡ #0942 | Địa chỉ PC: 0x0c8230 | Địa chỉ FDE: 0x1a3528 | Kích thước: 256 bytes
//   0x0c8230: D10143FF  sub      sp, sp, #0x50
//   0x0c8234: FD000BE8  str      d8, [sp, #0x10]
//   0x0c8238: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c823c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0942_0x0c8230(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c8230ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xfd000be8ULL) ^ 0x1a3528ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0943 | PC: 0x0c83a0 | FDE: 0x1a3570 | Size: 104 bytes
// Khung tháo gỡ #0943 | Địa chỉ PC: 0x0c83a0 | Địa chỉ FDE: 0x1a3570 | Kích thước: 104 bytes
//   0x0c83a0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c83a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c83a8: 910043FD  add      x29, sp, #0x10
//   0x0c83ac: B00007E8  adrp     x8, #0x1c5000
static inline uint64_t fde_func_0943_0x0c83a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c83a0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a3570ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0944 | PC: 0x0c8408 | FDE: 0x1a3620 | Size: 256 bytes
// Khung tháo gỡ #0944 | Địa chỉ PC: 0x0c8408 | Địa chỉ FDE: 0x1a3620 | Kích thước: 256 bytes
//   0x0c8408: D10143FF  sub      sp, sp, #0x50
//   0x0c840c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c8410: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0c8414: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0944_0x0c8408(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c8408ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x1a3620ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0945 | PC: 0x0c8584 | FDE: 0x1a3660 | Size: 256 bytes
// Khung tháo gỡ #0945 | Địa chỉ PC: 0x0c8584 | Địa chỉ FDE: 0x1a3660 | Kích thước: 256 bytes
//   0x0c8584: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c8588: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c858c: 910043FD  add      x29, sp, #0x10
//   0x0c8590: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0945_0x0c8584(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c8584ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a3660ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0946 | PC: 0x0c8a08 | FDE: 0x1a3728 | Size: 256 bytes
// Khung tháo gỡ #0946 | Địa chỉ PC: 0x0c8a08 | Địa chỉ FDE: 0x1a3728 | Kích thước: 256 bytes
//   0x0c8a08: 37C800E0  tbnz     w0, #0x19, #0xc8a24
//   0x0c8a0c: 12181C08  and      w8, w0, #0xff00
//   0x0c8a10: 340000A8  cbz      w8, #0xc8a24
//   0x0c8a14: 12001C08  and      w8, w0, #0xff
static inline uint64_t fde_func_0946_0x0c8a08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c8a08ULL ^ (static_cast<uint64_t>(0x37c800e0ULL) << 13);
    acc = (acc + a1 + 0x12181c08ULL) ^ 0x1a3728ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0947 | PC: 0x0c8e34 | FDE: 0x1a3770 | Size: 256 bytes
// Khung tháo gỡ #0947 | Địa chỉ PC: 0x0c8e34 | Địa chỉ FDE: 0x1a3770 | Kích thước: 256 bytes
//   0x0c8e34: D10143FF  sub      sp, sp, #0x50
//   0x0c8e38: F9000BF7  str      x23, [sp, #0x10]
//   0x0c8e3c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c8e40: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0947_0x0c8e34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c8e34ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x1a3770ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0948 | PC: 0x0c9044 | FDE: 0x1a37c0 | Size: 72 bytes
// Khung tháo gỡ #0948 | Địa chỉ PC: 0x0c9044 | Địa chỉ FDE: 0x1a37c0 | Kích thước: 72 bytes
//   0x0c9044: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c9048: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c904c: 910043FD  add      x29, sp, #0x10
//   0x0c9050: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0948_0x0c9044(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9044ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a37c0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0949 | PC: 0x0c908c | FDE: 0x1a3800 | Size: 256 bytes
// Khung tháo gỡ #0949 | Địa chỉ PC: 0x0c908c | Địa chỉ FDE: 0x1a3800 | Kích thước: 256 bytes
//   0x0c908c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0c9090: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c9094: 910043FD  add      x29, sp, #0x10
//   0x0c9098: 900007E8  adrp     x8, #0x1c5000
static inline uint64_t fde_func_0949_0x0c908c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c908cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a3800ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0950 | PC: 0x0c9364 | FDE: 0x1a38c8 | Size: 236 bytes
// Khung tháo gỡ #0950 | Địa chỉ PC: 0x0c9364 | Địa chỉ FDE: 0x1a38c8 | Kích thước: 236 bytes
//   0x0c9364: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0c9368: 910003FD  mov      x29, sp
//   0x0c936c: 900008A8  adrp     x8, #0x1dd000
//   0x0c9370: 9130E108  add      x8, x8, #0xc38
static inline uint64_t fde_func_0950_0x0c9364(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9364ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a38c8ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0951 | PC: 0x0c9450 | FDE: 0x1a3908 | Size: 256 bytes
// Khung tháo gỡ #0951 | Địa chỉ PC: 0x0c9450 | Địa chỉ FDE: 0x1a3908 | Kích thước: 256 bytes
//   0x0c9450: D10583FF  sub      sp, sp, #0x160
//   0x0c9454: A9125FFC  stp      x28, x23, [sp, #0x120]
//   0x0c9458: A91357F6  stp      x22, x21, [sp, #0x130]
//   0x0c945c: A9144FF4  stp      x20, x19, [sp, #0x140]
static inline uint64_t fde_func_0951_0x0c9450(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9450ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa9125ffcULL) ^ 0x1a3908ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0952 | PC: 0x0c96dc | FDE: 0x1a3950 | Size: 236 bytes
// Khung tháo gỡ #0952 | Địa chỉ PC: 0x0c96dc | Địa chỉ FDE: 0x1a3950 | Kích thước: 236 bytes
//   0x0c96dc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0c96e0: 910003FD  mov      x29, sp
//   0x0c96e4: 900008A8  adrp     x8, #0x1dd000
//   0x0c96e8: 9131A108  add      x8, x8, #0xc68
static inline uint64_t fde_func_0952_0x0c96dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c96dcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a3950ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0953 | PC: 0x0c97c8 | FDE: 0x1a3990 | Size: 256 bytes
// Khung tháo gỡ #0953 | Địa chỉ PC: 0x0c97c8 | Địa chỉ FDE: 0x1a3990 | Kích thước: 256 bytes
//   0x0c97c8: D10443FF  sub      sp, sp, #0x110
//   0x0c97cc: 6D0A23E9  stp      d9, d8, [sp, #0xa0]
//   0x0c97d0: A90B6FFC  stp      x28, x27, [sp, #0xb0]
//   0x0c97d4: A90C67FA  stp      x26, x25, [sp, #0xc0]
static inline uint64_t fde_func_0953_0x0c97c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c97c8ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0x6d0a23e9ULL) ^ 0x1a3990ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0954 | PC: 0x0c9e28 | FDE: 0x1a39e8 | Size: 236 bytes
// Khung tháo gỡ #0954 | Địa chỉ PC: 0x0c9e28 | Địa chỉ FDE: 0x1a39e8 | Kích thước: 236 bytes
//   0x0c9e28: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0c9e2c: 910003FD  mov      x29, sp
//   0x0c9e30: 900008A8  adrp     x8, #0x1dd000
//   0x0c9e34: 91326108  add      x8, x8, #0xc98
static inline uint64_t fde_func_0954_0x0c9e28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9e28ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a39e8ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0955 | PC: 0x0c9f14 | FDE: 0x1a3a28 | Size: 248 bytes
// Khung tháo gỡ #0955 | Địa chỉ PC: 0x0c9f14 | Địa chỉ FDE: 0x1a3a28 | Kích thước: 248 bytes
//   0x0c9f14: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0c9f18: 910003FD  mov      x29, sp
//   0x0c9f1c: 900008A8  adrp     x8, #0x1dd000
//   0x0c9f20: 9132E108  add      x8, x8, #0xcb8
static inline uint64_t fde_func_0955_0x0c9f14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9f14ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a3a28ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0956 | PC: 0x0ca00c | FDE: 0x1a3a68 | Size: 236 bytes
// Khung tháo gỡ #0956 | Địa chỉ PC: 0x0ca00c | Địa chỉ FDE: 0x1a3a68 | Kích thước: 236 bytes
//   0x0ca00c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0ca010: 910003FD  mov      x29, sp
//   0x0ca014: F0000888  adrp     x8, #0x1dd000
//   0x0ca018: 91336108  add      x8, x8, #0xcd8
static inline uint64_t fde_func_0956_0x0ca00c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca00cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a3a68ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0957 | PC: 0x0ca0f8 | FDE: 0x1a3aa8 | Size: 256 bytes
// Khung tháo gỡ #0957 | Địa chỉ PC: 0x0ca0f8 | Địa chỉ FDE: 0x1a3aa8 | Kích thước: 256 bytes
//   0x0ca0f8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0ca0fc: 910003FD  mov      x29, sp
//   0x0ca100: F0000888  adrp     x8, #0x1dd000
//   0x0ca104: 9133E108  add      x8, x8, #0xcf8
static inline uint64_t fde_func_0957_0x0ca0f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca0f8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a3aa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0958 | PC: 0x0ca44c | FDE: 0x1a3af8 | Size: 236 bytes
// Khung tháo gỡ #0958 | Địa chỉ PC: 0x0ca44c | Địa chỉ FDE: 0x1a3af8 | Kích thước: 236 bytes
//   0x0ca44c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0ca450: 910003FD  mov      x29, sp
//   0x0ca454: F0000888  adrp     x8, #0x1dd000
//   0x0ca458: 91346108  add      x8, x8, #0xd18
static inline uint64_t fde_func_0958_0x0ca44c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca44cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a3af8ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0959 | PC: 0x0ca538 | FDE: 0x1a3b38 | Size: 248 bytes
// Khung tháo gỡ #0959 | Địa chỉ PC: 0x0ca538 | Địa chỉ FDE: 0x1a3b38 | Kích thước: 248 bytes
//   0x0ca538: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0ca53c: 910003FD  mov      x29, sp
//   0x0ca540: F0000888  adrp     x8, #0x1dd000
//   0x0ca544: 9134E108  add      x8, x8, #0xd38
static inline uint64_t fde_func_0959_0x0ca538(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca538ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a3b38ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0960 | PC: 0x0ca630 | FDE: 0x1a3b78 | Size: 248 bytes
// Khung tháo gỡ #0960 | Địa chỉ PC: 0x0ca630 | Địa chỉ FDE: 0x1a3b78 | Kích thước: 248 bytes
//   0x0ca630: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0ca634: 910003FD  mov      x29, sp
//   0x0ca638: F0000888  adrp     x8, #0x1dd000
//   0x0ca63c: 91356108  add      x8, x8, #0xd58
static inline uint64_t fde_func_0960_0x0ca630(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca630ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a3b78ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0961 | PC: 0x0ca728 | FDE: 0x1a3bb8 | Size: 160 bytes
// Khung tháo gỡ #0961 | Địa chỉ PC: 0x0ca728 | Địa chỉ FDE: 0x1a3bb8 | Kích thước: 160 bytes
//   0x0ca728: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ca72c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ca730: 910043FD  add      x29, sp, #0x10
//   0x0ca734: F00007C8  adrp     x8, #0x1c5000
static inline uint64_t fde_func_0961_0x0ca728(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca728ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a3bb8ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0962 | PC: 0x0ca7c8 | FDE: 0x1a3bf8 | Size: 132 bytes
// Khung tháo gỡ #0962 | Địa chỉ PC: 0x0ca7c8 | Địa chỉ FDE: 0x1a3bf8 | Kích thước: 132 bytes
//   0x0ca7c8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0ca7cc: 910003FD  mov      x29, sp
//   0x0ca7d0: F0000888  adrp     x8, #0x1dd000
//   0x0ca7d4: 91342108  add      x8, x8, #0xd08
static inline uint64_t fde_func_0962_0x0ca7c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca7c8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a3bf8ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0963 | PC: 0x0ca84c | FDE: 0x1a3c50 | Size: 256 bytes
// Khung tháo gỡ #0963 | Địa chỉ PC: 0x0ca84c | Địa chỉ FDE: 0x1a3c50 | Kích thước: 256 bytes
//   0x0ca84c: D10283FF  sub      sp, sp, #0xa0
//   0x0ca850: F90023FB  str      x27, [sp, #0x40]
//   0x0ca854: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0ca858: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0963_0x0ca84c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ca84cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90023fbULL) ^ 0x1a3c50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0964 | PC: 0x0cac70 | FDE: 0x1a3cb8 | Size: 92 bytes
// Khung tháo gỡ #0964 | Địa chỉ PC: 0x0cac70 | Địa chỉ FDE: 0x1a3cb8 | Kích thước: 92 bytes
//   0x0cac70: D65F03C0  ret      
//   0x0cac74: EB01001F  cmp      x0, x1
//   0x0cac78: 52800089  mov      w9, #4
//   0x0cac7c: D53B0028  mrs      x8, ctr_el0
static inline uint64_t fde_func_0964_0x0cac70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cac70ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xeb01001fULL) ^ 0x1a3cb8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0965 | PC: 0x0caccc | FDE: 0x1a3ce8 | Size: 180 bytes
// Khung tháo gỡ #0965 | Địa chỉ PC: 0x0caccc | Địa chỉ FDE: 0x1a3ce8 | Kích thước: 180 bytes
//   0x0caccc: EB01001F  cmp      x0, x1
//   0x0cacd0: 52800089  mov      w9, #4
//   0x0cacd4: D53B0028  mrs      x8, ctr_el0
//   0x0cacd8: 54000102  b.hs     #0xcacf8
static inline uint64_t fde_func_0965_0x0caccc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cacccULL ^ (static_cast<uint64_t>(0xeb01001fULL) << 13);
    acc = (acc + a1 + 0x52800089ULL) ^ 0x1a3ce8ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #0966 | PC: 0x0cad80 | FDE: 0x1a3d18 | Size: 256 bytes
// Khung tháo gỡ #0966 | Địa chỉ PC: 0x0cad80 | Địa chỉ FDE: 0x1a3d18 | Kích thước: 256 bytes
//   0x0cad80: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0cad84: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cad88: 910043FD  add      x29, sp, #0x10
//   0x0cad8c: 94027C95  bl       #0x169fe0
static inline uint64_t fde_func_0966_0x0cad80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cad80ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a3d18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0967 | PC: 0x0cb0b8 | FDE: 0x1a3d58 | Size: 48 bytes
// Khung tháo gỡ #0967 | Địa chỉ PC: 0x0cb0b8 | Địa chỉ FDE: 0x1a3d58 | Kích thước: 48 bytes
//   0x0cb0b8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0cb0bc: 910003FD  mov      x29, sp
//   0x0cb0c0: 52800D20  mov      w0, #0x69
//   0x0cb0c4: 94024B20  bl       #0x15dd44
static inline uint64_t fde_func_0967_0x0cb0b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cb0b8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a3d58ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0968 | PC: 0x0cb0e8 | FDE: 0x1a3d98 | Size: 48 bytes
// Khung tháo gỡ #0968 | Địa chỉ PC: 0x0cb0e8 | Địa chỉ FDE: 0x1a3d98 | Kích thước: 48 bytes
//   0x0cb0e8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0cb0ec: 910003FD  mov      x29, sp
//   0x0cb0f0: 52800D60  mov      w0, #0x6b
//   0x0cb0f4: 94024B14  bl       #0x15dd44
static inline uint64_t fde_func_0968_0x0cb0e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cb0e8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a3d98ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0969 | PC: 0x0cb118 | FDE: 0x1a3dd8 | Size: 256 bytes
// Khung tháo gỡ #0969 | Địa chỉ PC: 0x0cb118 | Địa chỉ FDE: 0x1a3dd8 | Kích thước: 256 bytes
//   0x0cb118: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0cb11c: 910003FD  mov      x29, sp
//   0x0cb120: 52800DE0  mov      w0, #0x6f
//   0x0cb124: 94024B08  bl       #0x15dd44
static inline uint64_t fde_func_0969_0x0cb118(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cb118ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a3dd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0970 | PC: 0x0cb2e0 | FDE: 0x1a3e78 | Size: 256 bytes
// Khung tháo gỡ #0970 | Địa chỉ PC: 0x0cb2e0 | Địa chỉ FDE: 0x1a3e78 | Kích thước: 256 bytes
//   0x0cb2e0: D104C3FF  sub      sp, sp, #0x130
//   0x0cb2e4: FD0063E8  str      d8, [sp, #0xc0]
//   0x0cb2e8: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x0cb2ec: A90E67FA  stp      x26, x25, [sp, #0xe0]
static inline uint64_t fde_func_0970_0x0cb2e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cb2e0ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xfd0063e8ULL) ^ 0x1a3e78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0971 | PC: 0x0cb7d0 | FDE: 0x1a3ec8 | Size: 256 bytes
// Khung tháo gỡ #0971 | Địa chỉ PC: 0x0cb7d0 | Địa chỉ FDE: 0x1a3ec8 | Kích thước: 256 bytes
//   0x0cb7d0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0cb7d4: 910003FD  mov      x29, sp
//   0x0cb7d8: D0000888  adrp     x8, #0x1dd000
//   0x0cb7dc: 91376108  add      x8, x8, #0xdd8
static inline uint64_t fde_func_0971_0x0cb7d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cb7d0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a3ec8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0972 | PC: 0x0cb8ec | FDE: 0x1a3f08 | Size: 236 bytes
// Khung tháo gỡ #0972 | Địa chỉ PC: 0x0cb8ec | Địa chỉ FDE: 0x1a3f08 | Kích thước: 236 bytes
//   0x0cb8ec: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0cb8f0: 910003FD  mov      x29, sp
//   0x0cb8f4: D0000888  adrp     x8, #0x1dd000
//   0x0cb8f8: 9137E108  add      x8, x8, #0xdf8
static inline uint64_t fde_func_0972_0x0cb8ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cb8ecULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a3f08ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0973 | PC: 0x0cb9d8 | FDE: 0x1a3f48 | Size: 244 bytes
// Khung tháo gỡ #0973 | Địa chỉ PC: 0x0cb9d8 | Địa chỉ FDE: 0x1a3f48 | Kích thước: 244 bytes
//   0x0cb9d8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0cb9dc: 910003FD  mov      x29, sp
//   0x0cb9e0: D0000888  adrp     x8, #0x1dd000
//   0x0cb9e4: 91386108  add      x8, x8, #0xe18
static inline uint64_t fde_func_0973_0x0cb9d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cb9d8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a3f48ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #0974 | PC: 0x0cbacc | FDE: 0x1a3f88 | Size: 248 bytes
// Khung tháo gỡ #0974 | Địa chỉ PC: 0x0cbacc | Địa chỉ FDE: 0x1a3f88 | Kích thước: 248 bytes
//   0x0cbacc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0cbad0: 910003FD  mov      x29, sp
//   0x0cbad4: D0000888  adrp     x8, #0x1dd000
//   0x0cbad8: 9138E108  add      x8, x8, #0xe38
static inline uint64_t fde_func_0974_0x0cbacc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cbaccULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a3f88ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0975 | PC: 0x0cbbc4 | FDE: 0x1a3fc8 | Size: 256 bytes
// Khung tháo gỡ #0975 | Địa chỉ PC: 0x0cbbc4 | Địa chỉ FDE: 0x1a3fc8 | Kích thước: 256 bytes
//   0x0cbbc4: D10183FF  sub      sp, sp, #0x60
//   0x0cbbc8: F90013F7  str      x23, [sp, #0x20]
//   0x0cbbcc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0cbbd0: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0975_0x0cbbc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cbbc4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1a3fc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0976 | PC: 0x0cc320 | FDE: 0x1a4018 | Size: 112 bytes
// Khung tháo gỡ #0976 | Địa chỉ PC: 0x0cc320 | Địa chỉ FDE: 0x1a4018 | Kích thước: 112 bytes
//   0x0cc320: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0cc324: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cc328: 910043FD  add      x29, sp, #0x10
//   0x0cc32c: B00007C8  adrp     x8, #0x1c5000
static inline uint64_t fde_func_0976_0x0cc320(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cc320ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a4018ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0977 | PC: 0x0cc390 | FDE: 0x1a4058 | Size: 256 bytes
// Khung tháo gỡ #0977 | Địa chỉ PC: 0x0cc390 | Địa chỉ FDE: 0x1a4058 | Kích thước: 256 bytes
//   0x0cc390: D53BD040  mrs      x0, tpidr_el0
//   0x0cc394: D65F03C0  ret      
//   0x0cc398: D10143FF  sub      sp, sp, #0x50
//   0x0cc39c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0977_0x0cc390(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cc390ULL ^ (static_cast<uint64_t>(0xd53bd040ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1a4058ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0978 | PC: 0x0cc4a4 | FDE: 0x1a4108 | Size: 256 bytes
// Khung tháo gỡ #0978 | Địa chỉ PC: 0x0cc4a4 | Địa chỉ FDE: 0x1a4108 | Kích thước: 256 bytes
//   0x0cc4a4: D10543FF  sub      sp, sp, #0x150
//   0x0cc4a8: A90F6FFC  stp      x28, x27, [sp, #0xf0]
//   0x0cc4ac: A91067FA  stp      x26, x25, [sp, #0x100]
//   0x0cc4b0: A9115FF8  stp      x24, x23, [sp, #0x110]
static inline uint64_t fde_func_0978_0x0cc4a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cc4a4ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa90f6ffcULL) ^ 0x1a4108ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0979 | PC: 0x0ccabc | FDE: 0x1a4160 | Size: 144 bytes
// Khung tháo gỡ #0979 | Địa chỉ PC: 0x0ccabc | Địa chỉ FDE: 0x1a4160 | Kích thước: 144 bytes
//   0x0ccabc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ccac0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ccac4: 910043FD  add      x29, sp, #0x10
//   0x0ccac8: B00007C8  adrp     x8, #0x1c5000
static inline uint64_t fde_func_0979_0x0ccabc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ccabcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a4160ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0980 | PC: 0x0ccb4c | FDE: 0x1a4218 | Size: 256 bytes
// Khung tháo gỡ #0980 | Địa chỉ PC: 0x0ccb4c | Địa chỉ FDE: 0x1a4218 | Kích thước: 256 bytes
//   0x0ccb4c: D10303FF  sub      sp, sp, #0xc0
//   0x0ccb50: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x0ccb54: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x0ccb58: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_0980_0x0ccb4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ccb4cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9085ff8ULL) ^ 0x1a4218ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0981 | PC: 0x0cd160 | FDE: 0x1a4270 | Size: 256 bytes
// Khung tháo gỡ #0981 | Địa chỉ PC: 0x0cd160 | Địa chỉ FDE: 0x1a4270 | Kích thước: 256 bytes
//   0x0cd160: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x0cd164: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0cd168: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0cd16c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0981_0x0cd160(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cd160ULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1a4270ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0982 | PC: 0x0cd6d4 | FDE: 0x1a42e0 | Size: 256 bytes
// Khung tháo gỡ #0982 | Địa chỉ PC: 0x0cd6d4 | Địa chỉ FDE: 0x1a42e0 | Kích thước: 256 bytes
//   0x0cd6d4: AA1E03E5  mov      x5, x30
//   0x0cd6d8: 8B0000A5  add      x5, x5, x0
//   0x0cd6dc: AA0503FE  mov      x30, x5
//   0x0cd6e0: D65F03C0  ret      
static inline uint64_t fde_func_0982_0x0cd6d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cd6d4ULL ^ (static_cast<uint64_t>(0xaa1e03e5ULL) << 13);
    acc = (acc + a1 + 0x8b0000a5ULL) ^ 0x1a42e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0983 | PC: 0x0ce078 | FDE: 0x1a4380 | Size: 256 bytes
// Khung tháo gỡ #0983 | Địa chỉ PC: 0x0ce078 | Địa chỉ FDE: 0x1a4380 | Kích thước: 256 bytes
//   0x0ce078: D10183FF  sub      sp, sp, #0x60
//   0x0ce07c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0ce080: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0ce084: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0983_0x0ce078(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ce078ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1a4380ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0984 | PC: 0x0ce588 | FDE: 0x1a43d8 | Size: 256 bytes
// Khung tháo gỡ #0984 | Địa chỉ PC: 0x0ce588 | Địa chỉ FDE: 0x1a43d8 | Kích thước: 256 bytes
//   0x0ce588: D10303FF  sub      sp, sp, #0xc0
//   0x0ce58c: F90053F3  str      x19, [sp, #0xa0]
//   0x0ce590: A90B7BFD  stp      x29, x30, [sp, #0xb0]
//   0x0ce594: 9102C3FD  add      x29, sp, #0xb0
static inline uint64_t fde_func_0984_0x0ce588(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ce588ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90053f3ULL) ^ 0x1a43d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0985 | PC: 0x0ce7bc | FDE: 0x1a4418 | Size: 256 bytes
// Khung tháo gỡ #0985 | Địa chỉ PC: 0x0ce7bc | Địa chỉ FDE: 0x1a4418 | Kích thước: 256 bytes
//   0x0ce7bc: D10183FF  sub      sp, sp, #0x60
//   0x0ce7c0: F90013F7  str      x23, [sp, #0x20]
//   0x0ce7c4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0ce7c8: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0985_0x0ce7bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ce7bcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1a4418ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0986 | PC: 0x0ce9b8 | FDE: 0x1a4460 | Size: 256 bytes
// Khung tháo gỡ #0986 | Địa chỉ PC: 0x0ce9b8 | Địa chỉ FDE: 0x1a4460 | Kích thước: 256 bytes
//   0x0ce9b8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ce9bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ce9c0: 910043FD  add      x29, sp, #0x10
//   0x0ce9c4: F00007A8  adrp     x8, #0x1c5000
static inline uint64_t fde_func_0986_0x0ce9b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ce9b8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a4460ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0987 | PC: 0x0cec28 | FDE: 0x1a4518 | Size: 256 bytes
// Khung tháo gỡ #0987 | Địa chỉ PC: 0x0cec28 | Địa chỉ FDE: 0x1a4518 | Kích thước: 256 bytes
//   0x0cec28: D10343FF  sub      sp, sp, #0xd0
//   0x0cec2c: F90053F5  str      x21, [sp, #0xa0]
//   0x0cec30: A90B4FF4  stp      x20, x19, [sp, #0xb0]
//   0x0cec34: A90C7BFD  stp      x29, x30, [sp, #0xc0]
static inline uint64_t fde_func_0987_0x0cec28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cec28ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf90053f5ULL) ^ 0x1a4518ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0988 | PC: 0x0cf21c | FDE: 0x1a4560 | Size: 256 bytes
// Khung tháo gỡ #0988 | Địa chỉ PC: 0x0cf21c | Địa chỉ FDE: 0x1a4560 | Kích thước: 256 bytes
//   0x0cf21c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0cf220: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cf224: 910043FD  add      x29, sp, #0x10
//   0x0cf228: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0988_0x0cf21c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cf21cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a4560ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0989 | PC: 0x0cf3a4 | FDE: 0x1a45a0 | Size: 256 bytes
// Khung tháo gỡ #0989 | Địa chỉ PC: 0x0cf3a4 | Địa chỉ FDE: 0x1a45a0 | Kích thước: 256 bytes
//   0x0cf3a4: D10143FF  sub      sp, sp, #0x50
//   0x0cf3a8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0cf3ac: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0cf3b0: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0989_0x0cf3a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cf3a4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x1a45a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0990 | PC: 0x0cf654 | FDE: 0x1a45e0 | Size: 112 bytes
// Khung tháo gỡ #0990 | Địa chỉ PC: 0x0cf654 | Địa chỉ FDE: 0x1a45e0 | Kích thước: 112 bytes
//   0x0cf654: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0cf658: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cf65c: 910043FD  add      x29, sp, #0x10
//   0x0cf660: D00007A8  adrp     x8, #0x1c5000
static inline uint64_t fde_func_0990_0x0cf654(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cf654ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a45e0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0991 | PC: 0x0cf6c4 | FDE: 0x1a4620 | Size: 76 bytes
// Khung tháo gỡ #0991 | Địa chỉ PC: 0x0cf6c4 | Địa chỉ FDE: 0x1a4620 | Kích thước: 76 bytes
//   0x0cf6c4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0cf6c8: 910003FD  mov      x29, sp
//   0x0cf6cc: 97FD7A71  bl       #0x2e090
//   0x0cf6d0: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0991_0x0cf6c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cf6c4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a4620ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0992 | PC: 0x0cf710 | FDE: 0x1a4660 | Size: 28 bytes
// Khung tháo gỡ #0992 | Địa chỉ PC: 0x0cf710 | Địa chỉ FDE: 0x1a4660 | Kích thước: 28 bytes
//   0x0cf710: D00007A8  adrp     x8, #0x1c5000
//   0x0cf714: 91312108  add      x8, x8, #0xc48
//   0x0cf718: F9000028  str      x8, [x1]
//   0x0cf71c: 3CC08000  ldur     q0, [x0, #8]
static inline uint64_t fde_func_0992_0x0cf710(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cf710ULL ^ (static_cast<uint64_t>(0xd00007a8ULL) << 13);
    acc = (acc + a1 + 0x91312108ULL) ^ 0x1a4660ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0993 | PC: 0x0cf72c | FDE: 0x1a4690 | Size: 104 bytes
// Khung tháo gỡ #0993 | Địa chỉ PC: 0x0cf72c | Địa chỉ FDE: 0x1a4690 | Kích thước: 104 bytes
//   0x0cf72c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0cf730: 910003FD  mov      x29, sp
//   0x0cf734: 97FD7A57  bl       #0x2e090
//   0x0cf738: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0993_0x0cf72c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cf72cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a4690ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0994 | PC: 0x0cf794 | FDE: 0x1a46d0 | Size: 76 bytes
// Khung tháo gỡ #0994 | Địa chỉ PC: 0x0cf794 | Địa chỉ FDE: 0x1a46d0 | Kích thước: 76 bytes
//   0x0cf794: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0cf798: 910003FD  mov      x29, sp
//   0x0cf79c: 97FD7A3D  bl       #0x2e090
//   0x0cf7a0: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0994_0x0cf794(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cf794ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a46d0ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0995 | PC: 0x0cf7e0 | FDE: 0x1a4710 | Size: 28 bytes
// Khung tháo gỡ #0995 | Địa chỉ PC: 0x0cf7e0 | Địa chỉ FDE: 0x1a4710 | Kích thước: 28 bytes
//   0x0cf7e0: D00007A8  adrp     x8, #0x1c5000
//   0x0cf7e4: 91324108  add      x8, x8, #0xc90
//   0x0cf7e8: F9000028  str      x8, [x1]
//   0x0cf7ec: 3CC08000  ldur     q0, [x0, #8]
static inline uint64_t fde_func_0995_0x0cf7e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cf7e0ULL ^ (static_cast<uint64_t>(0xd00007a8ULL) << 13);
    acc = (acc + a1 + 0x91324108ULL) ^ 0x1a4710ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0996 | PC: 0x0cf7fc | FDE: 0x1a4740 | Size: 80 bytes
// Khung tháo gỡ #0996 | Địa chỉ PC: 0x0cf7fc | Địa chỉ FDE: 0x1a4740 | Kích thước: 80 bytes
//   0x0cf7fc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0cf800: 910003FD  mov      x29, sp
//   0x0cf804: 97FD7A23  bl       #0x2e090
//   0x0cf808: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0996_0x0cf7fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cf7fcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a4740ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0997 | PC: 0x0cf84c | FDE: 0x1a4780 | Size: 76 bytes
// Khung tháo gỡ #0997 | Địa chỉ PC: 0x0cf84c | Địa chỉ FDE: 0x1a4780 | Kích thước: 76 bytes
//   0x0cf84c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0cf850: 910003FD  mov      x29, sp
//   0x0cf854: 97FD7A0F  bl       #0x2e090
//   0x0cf858: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0997_0x0cf84c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cf84cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a4780ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0998 | PC: 0x0cf898 | FDE: 0x1a47c0 | Size: 28 bytes
// Khung tháo gỡ #0998 | Địa chỉ PC: 0x0cf898 | Địa chỉ FDE: 0x1a47c0 | Kích thước: 28 bytes
//   0x0cf898: D00007A8  adrp     x8, #0x1c5000
//   0x0cf89c: 91336108  add      x8, x8, #0xcd8
//   0x0cf8a0: F9000028  str      x8, [x1]
//   0x0cf8a4: 3CC08000  ldur     q0, [x0, #8]
static inline uint64_t fde_func_0998_0x0cf898(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cf898ULL ^ (static_cast<uint64_t>(0xd00007a8ULL) << 13);
    acc = (acc + a1 + 0x91336108ULL) ^ 0x1a47c0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0999 | PC: 0x0cf8b4 | FDE: 0x1a47f0 | Size: 256 bytes
// Khung tháo gỡ #0999 | Địa chỉ PC: 0x0cf8b4 | Địa chỉ FDE: 0x1a47f0 | Kích thước: 256 bytes
//   0x0cf8b4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0cf8b8: 910003FD  mov      x29, sp
//   0x0cf8bc: 97FD79F5  bl       #0x2e090
//   0x0cf8c0: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0999_0x0cf8b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cf8b4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a47f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1000 | PC: 0x0cfaac | FDE: 0x1a4838 | Size: 76 bytes
// Khung tháo gỡ #1000 | Địa chỉ PC: 0x0cfaac | Địa chỉ FDE: 0x1a4838 | Kích thước: 76 bytes
//   0x0cfaac: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0cfab0: 910003FD  mov      x29, sp
//   0x0cfab4: 97FD7977  bl       #0x2e090
//   0x0cfab8: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_1000_0x0cfaac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cfaacULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a4838ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1001 | PC: 0x0cfaf8 | FDE: 0x1a4878 | Size: 28 bytes
// Khung tháo gỡ #1001 | Địa chỉ PC: 0x0cfaf8 | Địa chỉ FDE: 0x1a4878 | Kích thước: 28 bytes
//   0x0cfaf8: D00007A8  adrp     x8, #0x1c5000
//   0x0cfafc: 91348108  add      x8, x8, #0xd20
//   0x0cfb00: F9000028  str      x8, [x1]
//   0x0cfb04: 3CC08000  ldur     q0, [x0, #8]
static inline uint64_t fde_func_1001_0x0cfaf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cfaf8ULL ^ (static_cast<uint64_t>(0xd00007a8ULL) << 13);
    acc = (acc + a1 + 0x91348108ULL) ^ 0x1a4878ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1002 | PC: 0x0cfb14 | FDE: 0x1a48a8 | Size: 256 bytes
// Khung tháo gỡ #1002 | Địa chỉ PC: 0x0cfb14 | Địa chỉ FDE: 0x1a48a8 | Kích thước: 256 bytes
//   0x0cfb14: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0cfb18: 910003FD  mov      x29, sp
//   0x0cfb1c: 97FD795D  bl       #0x2e090
//   0x0cfb20: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_1002_0x0cfb14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cfb14ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a48a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1003 | PC: 0x0cfdc8 | FDE: 0x1a48f0 | Size: 84 bytes
// Khung tháo gỡ #1003 | Địa chỉ PC: 0x0cfdc8 | Địa chỉ FDE: 0x1a48f0 | Kích thước: 84 bytes
//   0x0cfdc8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0cfdcc: 910003FD  mov      x29, sp
//   0x0cfdd0: D00007A8  adrp     x8, #0x1c5000
//   0x0cfdd4: 9135A108  add      x8, x8, #0xd68
static inline uint64_t fde_func_1003_0x0cfdc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cfdc8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a48f0ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1004 | PC: 0x0cfe1c | FDE: 0x1a49a8 | Size: 256 bytes
// Khung tháo gỡ #1004 | Địa chỉ PC: 0x0cfe1c | Địa chỉ FDE: 0x1a49a8 | Kích thước: 256 bytes
//   0x0cfe1c: D101C3FF  sub      sp, sp, #0x70
//   0x0cfe20: F90023F5  str      x21, [sp, #0x40]
//   0x0cfe24: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0cfe28: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_1004_0x0cfe1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cfe1cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x1a49a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1005 | PC: 0x0d00b0 | FDE: 0x1a49f0 | Size: 256 bytes
// Khung tháo gỡ #1005 | Địa chỉ PC: 0x0d00b0 | Địa chỉ FDE: 0x1a49f0 | Kích thước: 256 bytes
//   0x0d00b0: D10143FF  sub      sp, sp, #0x50
//   0x0d00b4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0d00b8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0d00bc: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1005_0x0d00b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d00b0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1a49f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1006 | PC: 0x0d0388 | FDE: 0x1a4a40 | Size: 256 bytes
// Khung tháo gỡ #1006 | Địa chỉ PC: 0x0d0388 | Địa chỉ FDE: 0x1a4a40 | Kích thước: 256 bytes
//   0x0d0388: D10143FF  sub      sp, sp, #0x50
//   0x0d038c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0d0390: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0d0394: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1006_0x0d0388(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d0388ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1a4a40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1007 | PC: 0x0d0900 | FDE: 0x1a4a98 | Size: 256 bytes
// Khung tháo gỡ #1007 | Địa chỉ PC: 0x0d0900 | Địa chỉ FDE: 0x1a4a98 | Kích thước: 256 bytes
//   0x0d0900: D10403FF  sub      sp, sp, #0x100
//   0x0d0904: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x0d0908: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x0d090c: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_1007_0x0d0900(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d0900ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90a6ffcULL) ^ 0x1a4a98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1008 | PC: 0x0d0d24 | FDE: 0x1a4ae8 | Size: 256 bytes
// Khung tháo gỡ #1008 | Địa chỉ PC: 0x0d0d24 | Địa chỉ FDE: 0x1a4ae8 | Kích thước: 256 bytes
//   0x0d0d24: D104C3FF  sub      sp, sp, #0x130
//   0x0d0d28: F9006BFC  str      x28, [sp, #0xd0]
//   0x0d0d2c: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x0d0d30: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_1008_0x0d0d24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d0d24ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xf9006bfcULL) ^ 0x1a4ae8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1009 | PC: 0x0d0fc4 | FDE: 0x1a4b38 | Size: 256 bytes
// Khung tháo gỡ #1009 | Địa chỉ PC: 0x0d0fc4 | Địa chỉ FDE: 0x1a4b38 | Kích thước: 256 bytes
//   0x0d0fc4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d0fc8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d0fcc: 910043FD  add      x29, sp, #0x10
//   0x0d0fd0: B00007A8  adrp     x8, #0x1c5000
static inline uint64_t fde_func_1009_0x0d0fc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d0fc4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a4b38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1010 | PC: 0x0d10d4 | FDE: 0x1a4b78 | Size: 224 bytes
// Khung tháo gỡ #1010 | Địa chỉ PC: 0x0d10d4 | Địa chỉ FDE: 0x1a4b78 | Kích thước: 224 bytes
//   0x0d10d4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0d10d8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d10dc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d10e0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1010_0x0d10d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d10d4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1a4b78ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #1011 | PC: 0x0d11b4 | FDE: 0x1a4bb8 | Size: 256 bytes
// Khung tháo gỡ #1011 | Địa chỉ PC: 0x0d11b4 | Địa chỉ FDE: 0x1a4bb8 | Kích thước: 256 bytes
//   0x0d11b4: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0d11b8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0d11bc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d11c0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1011_0x0d11b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d11b4ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1a4bb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1012 | PC: 0x0d12fc | FDE: 0x1a4c08 | Size: 200 bytes
// Khung tháo gỡ #1012 | Địa chỉ PC: 0x0d12fc | Địa chỉ FDE: 0x1a4c08 | Kích thước: 200 bytes
//   0x0d12fc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0d1300: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d1304: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d1308: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1012_0x0d12fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d12fcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1a4c08ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1013 | PC: 0x0d13c4 | FDE: 0x1a4c48 | Size: 256 bytes
// Khung tháo gỡ #1013 | Địa chỉ PC: 0x0d13c4 | Địa chỉ FDE: 0x1a4c48 | Kích thước: 256 bytes
//   0x0d13c4: D10183FF  sub      sp, sp, #0x60
//   0x0d13c8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0d13cc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0d13d0: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1013_0x0d13c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d13c4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1a4c48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1014 | PC: 0x0d14e8 | FDE: 0x1a4d00 | Size: 256 bytes
// Khung tháo gỡ #1014 | Địa chỉ PC: 0x0d14e8 | Địa chỉ FDE: 0x1a4d00 | Kích thước: 256 bytes
//   0x0d14e8: D10243FF  sub      sp, sp, #0x90
//   0x0d14ec: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x0d14f0: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x0d14f4: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_1014_0x0d14e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d14e8ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90657f6ULL) ^ 0x1a4d00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1015 | PC: 0x0d16e4 | FDE: 0x1a4d50 | Size: 256 bytes
// Khung tháo gỡ #1015 | Địa chỉ PC: 0x0d16e4 | Địa chỉ FDE: 0x1a4d50 | Kích thước: 256 bytes
//   0x0d16e4: D10183FF  sub      sp, sp, #0x60
//   0x0d16e8: F90013F7  str      x23, [sp, #0x20]
//   0x0d16ec: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0d16f0: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1015_0x0d16e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d16e4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1a4d50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1016 | PC: 0x0d1840 | FDE: 0x1a4e10 | Size: 256 bytes
// Khung tháo gỡ #1016 | Địa chỉ PC: 0x0d1840 | Địa chỉ FDE: 0x1a4e10 | Kích thước: 256 bytes
//   0x0d1840: D10203FF  sub      sp, sp, #0x80
//   0x0d1844: F9002BF5  str      x21, [sp, #0x50]
//   0x0d1848: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x0d184c: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_1016_0x0d1840(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d1840ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf5ULL) ^ 0x1a4e10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1017 | PC: 0x0d1bec | FDE: 0x1a4e50 | Size: 256 bytes
// Khung tháo gỡ #1017 | Địa chỉ PC: 0x0d1bec | Địa chỉ FDE: 0x1a4e50 | Kích thước: 256 bytes
//   0x0d1bec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d1bf0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d1bf4: 910043FD  add      x29, sp, #0x10
//   0x0d1bf8: 91006014  add      x20, x0, #0x18
static inline uint64_t fde_func_1017_0x0d1bec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d1becULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a4e50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1018 | PC: 0x0d35c4 | FDE: 0x1a4eb8 | Size: 256 bytes
// Khung tháo gỡ #1018 | Địa chỉ PC: 0x0d35c4 | Địa chỉ FDE: 0x1a4eb8 | Kích thước: 256 bytes
//   0x0d35c4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d35c8: 910003FD  mov      x29, sp
//   0x0d35cc: F940040B  ldr      x11, [x0, #8]
//   0x0d35d0: EB0B001F  cmp      x0, x11
static inline uint64_t fde_func_1018_0x0d35c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d35c4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a4eb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1019 | PC: 0x0d45d4 | FDE: 0x1a4f08 | Size: 256 bytes
// Khung tháo gỡ #1019 | Địa chỉ PC: 0x0d45d4 | Địa chỉ FDE: 0x1a4f08 | Kích thước: 256 bytes
//   0x0d45d4: D10203FF  sub      sp, sp, #0x80
//   0x0d45d8: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0d45dc: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x0d45e0: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_1019_0x0d45d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d45d4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90557f6ULL) ^ 0x1a4f08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1020 | PC: 0x0d4990 | FDE: 0x1a4f48 | Size: 256 bytes
// Khung tháo gỡ #1020 | Địa chỉ PC: 0x0d4990 | Địa chỉ FDE: 0x1a4f48 | Kích thước: 256 bytes
//   0x0d4990: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0d4994: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d4998: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d499c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1020_0x0d4990(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d4990ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1a4f48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1021 | PC: 0x0d4b80 | FDE: 0x1a5000 | Size: 256 bytes
// Khung tháo gỡ #1021 | Địa chỉ PC: 0x0d4b80 | Địa chỉ FDE: 0x1a5000 | Kích thước: 256 bytes
//   0x0d4b80: D10143FF  sub      sp, sp, #0x50
//   0x0d4b84: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0d4b88: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0d4b8c: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1021_0x0d4b80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d4b80ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x1a5000ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1022 | PC: 0x0d4ed4 | FDE: 0x1a5048 | Size: 256 bytes
// Khung tháo gỡ #1022 | Địa chỉ PC: 0x0d4ed4 | Địa chỉ FDE: 0x1a5048 | Kích thước: 256 bytes
//   0x0d4ed4: D10303FF  sub      sp, sp, #0xc0
//   0x0d4ed8: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x0d4edc: A90A4FF4  stp      x20, x19, [sp, #0xa0]
//   0x0d4ee0: A90B7BFD  stp      x29, x30, [sp, #0xb0]
static inline uint64_t fde_func_1022_0x0d4ed4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d4ed4ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90957f6ULL) ^ 0x1a5048ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1023 | PC: 0x0d5278 | FDE: 0x1a5118 | Size: 256 bytes
// Khung tháo gỡ #1023 | Địa chỉ PC: 0x0d5278 | Địa chỉ FDE: 0x1a5118 | Kích thước: 256 bytes
//   0x0d5278: D10143FF  sub      sp, sp, #0x50
//   0x0d527c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0d5280: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0d5284: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1023_0x0d5278(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5278ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x1a5118ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1024 | PC: 0x0d5abc | FDE: 0x1a5170 | Size: 60 bytes
// Khung tháo gỡ #1024 | Địa chỉ PC: 0x0d5abc | Địa chỉ FDE: 0x1a5170 | Kích thước: 60 bytes
//   0x0d5abc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0d5ac0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d5ac4: 910043FD  add      x29, sp, #0x10
//   0x0d5ac8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1024_0x0d5abc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5abcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a5170ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1025 | PC: 0x0d5af8 | FDE: 0x1a5220 | Size: 256 bytes
// Khung tháo gỡ #1025 | Địa chỉ PC: 0x0d5af8 | Địa chỉ FDE: 0x1a5220 | Kích thước: 256 bytes
//   0x0d5af8: D10483FF  sub      sp, sp, #0x120
//   0x0d5afc: A90C6FFC  stp      x28, x27, [sp, #0xc0]
//   0x0d5b00: A90D67FA  stp      x26, x25, [sp, #0xd0]
//   0x0d5b04: A90E5FF8  stp      x24, x23, [sp, #0xe0]
static inline uint64_t fde_func_1025_0x0d5af8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5af8ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90c6ffcULL) ^ 0x1a5220ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1026 | PC: 0x0d6438 | FDE: 0x1a52e8 | Size: 256 bytes
// Khung tháo gỡ #1026 | Địa chỉ PC: 0x0d6438 | Địa chỉ FDE: 0x1a52e8 | Kích thước: 256 bytes
//   0x0d6438: F81C0FFC  str      x28, [sp, #-0x40]!
//   0x0d643c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0d6440: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d6444: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1026_0x0d6438(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6438ULL ^ (static_cast<uint64_t>(0xf81c0ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1a52e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1027 | PC: 0x0d6758 | FDE: 0x1a5330 | Size: 96 bytes
// Khung tháo gỡ #1027 | Địa chỉ PC: 0x0d6758 | Địa chỉ FDE: 0x1a5330 | Kích thước: 96 bytes
//   0x0d6758: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d675c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d6760: 910043FD  add      x29, sp, #0x10
//   0x0d6764: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1027_0x0d6758(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6758ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a5330ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1028 | PC: 0x0d67b8 | FDE: 0x1a5390 | Size: 256 bytes
// Khung tháo gỡ #1028 | Địa chỉ PC: 0x0d67b8 | Địa chỉ FDE: 0x1a5390 | Kích thước: 256 bytes
//   0x0d67b8: F0000768  adrp     x8, #0x1c5000
//   0x0d67bc: 9129E108  add      x8, x8, #0xa78
//   0x0d67c0: 52800029  mov      w9, #1
//   0x0d67c4: 6F00E400  movi     v0.2d, #0000000000000000
static inline uint64_t fde_func_1028_0x0d67b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d67b8ULL ^ (static_cast<uint64_t>(0xf0000768ULL) << 13);
    acc = (acc + a1 + 0x9129e108ULL) ^ 0x1a5390ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1029 | PC: 0x0d6cec | FDE: 0x1a53d8 | Size: 244 bytes
// Khung tháo gỡ #1029 | Địa chỉ PC: 0x0d6cec | Địa chỉ FDE: 0x1a53d8 | Kích thước: 244 bytes
//   0x0d6cec: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d6cf0: 910003FD  mov      x29, sp
//   0x0d6cf4: 90000848  adrp     x8, #0x1de000
//   0x0d6cf8: 91056108  add      x8, x8, #0x158
static inline uint64_t fde_func_1029_0x0d6cec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6cecULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a53d8ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #1030 | PC: 0x0d6de0 | FDE: 0x1a5418 | Size: 256 bytes
// Khung tháo gỡ #1030 | Địa chỉ PC: 0x0d6de0 | Địa chỉ FDE: 0x1a5418 | Kích thước: 256 bytes
//   0x0d6de0: D105C3FF  sub      sp, sp, #0x170
//   0x0d6de4: A9116FFC  stp      x28, x27, [sp, #0x110]
//   0x0d6de8: A91267FA  stp      x26, x25, [sp, #0x120]
//   0x0d6dec: A9135FF8  stp      x24, x23, [sp, #0x130]
static inline uint64_t fde_func_1030_0x0d6de0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6de0ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xa9116ffcULL) ^ 0x1a5418ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1031 | PC: 0x0d7ac8 | FDE: 0x1a5470 | Size: 256 bytes
// Khung tháo gỡ #1031 | Địa chỉ PC: 0x0d7ac8 | Địa chỉ FDE: 0x1a5470 | Kích thước: 256 bytes
//   0x0d7ac8: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x0d7acc: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0d7ad0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0d7ad4: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1031_0x0d7ac8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7ac8ULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1a5470ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1032 | PC: 0x0d805c | FDE: 0x1a54c8 | Size: 244 bytes
// Khung tháo gỡ #1032 | Địa chỉ PC: 0x0d805c | Địa chỉ FDE: 0x1a54c8 | Kích thước: 244 bytes
//   0x0d805c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d8060: 910003FD  mov      x29, sp
//   0x0d8064: D0000828  adrp     x8, #0x1de000
//   0x0d8068: 91160108  add      x8, x8, #0x580
static inline uint64_t fde_func_1032_0x0d805c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d805cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a54c8ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #1033 | PC: 0x0d8150 | FDE: 0x1a5528 | Size: 68 bytes
// Khung tháo gỡ #1033 | Địa chỉ PC: 0x0d8150 | Địa chỉ FDE: 0x1a5528 | Kích thước: 68 bytes
//   0x0d8150: AA1E03E3  mov      x3, x30
//   0x0d8154: 8B000063  add      x3, x3, x0
//   0x0d8158: AA0303FE  mov      x30, x3
//   0x0d815c: D65F03C0  ret      
static inline uint64_t fde_func_1033_0x0d8150(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8150ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x8b000063ULL) ^ 0x1a5528ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1034 | PC: 0x0d8194 | FDE: 0x1a5560 | Size: 240 bytes
// Khung tháo gỡ #1034 | Địa chỉ PC: 0x0d8194 | Địa chỉ FDE: 0x1a5560 | Kích thước: 240 bytes
//   0x0d8194: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0d8198: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d819c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d81a0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1034_0x0d8194(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8194ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1a5560ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1035 | PC: 0x0d8284 | FDE: 0x1a55a0 | Size: 256 bytes
// Khung tháo gỡ #1035 | Địa chỉ PC: 0x0d8284 | Địa chỉ FDE: 0x1a55a0 | Kích thước: 256 bytes
//   0x0d8284: D102C3FF  sub      sp, sp, #0xb0
//   0x0d8288: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x0d828c: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x0d8290: A90A7BFD  stp      x29, x30, [sp, #0xa0]
static inline uint64_t fde_func_1035_0x0d8284(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8284ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa90857f6ULL) ^ 0x1a55a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1036 | PC: 0x0d8428 | FDE: 0x1a55f0 | Size: 256 bytes
// Khung tháo gỡ #1036 | Địa chỉ PC: 0x0d8428 | Địa chỉ FDE: 0x1a55f0 | Kích thước: 256 bytes
//   0x0d8428: D10183FF  sub      sp, sp, #0x60
//   0x0d842c: F90013F7  str      x23, [sp, #0x20]
//   0x0d8430: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0d8434: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1036_0x0d8428(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8428ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1a55f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1037 | PC: 0x0d8664 | FDE: 0x1a5638 | Size: 256 bytes
// Khung tháo gỡ #1037 | Địa chỉ PC: 0x0d8664 | Địa chỉ FDE: 0x1a5638 | Kích thước: 256 bytes
//   0x0d8664: D10143FF  sub      sp, sp, #0x50
//   0x0d8668: F9000BF7  str      x23, [sp, #0x10]
//   0x0d866c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0d8670: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1037_0x0d8664(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8664ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x1a5638ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1038 | PC: 0x0d8894 | FDE: 0x1a5688 | Size: 132 bytes
// Khung tháo gỡ #1038 | Địa chỉ PC: 0x0d8894 | Địa chỉ FDE: 0x1a5688 | Kích thước: 132 bytes
//   0x0d8894: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d8898: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d889c: 910043FD  add      x29, sp, #0x10
//   0x0d88a0: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1038_0x0d8894(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8894ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a5688ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1039 | PC: 0x0d8918 | FDE: 0x1a56c0 | Size: 256 bytes
// Khung tháo gỡ #1039 | Địa chỉ PC: 0x0d8918 | Địa chỉ FDE: 0x1a56c0 | Kích thước: 256 bytes
//   0x0d8918: D10143FF  sub      sp, sp, #0x50
//   0x0d891c: FD000BE8  str      d8, [sp, #0x10]
//   0x0d8920: F9000FF7  str      x23, [sp, #0x18]
//   0x0d8924: A90257F6  stp      x22, x21, [sp, #0x20]
static inline uint64_t fde_func_1039_0x0d8918(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8918ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xfd000be8ULL) ^ 0x1a56c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1040 | PC: 0x0d8ac4 | FDE: 0x1a5718 | Size: 256 bytes
// Khung tháo gỡ #1040 | Địa chỉ PC: 0x0d8ac4 | Địa chỉ FDE: 0x1a5718 | Kích thước: 256 bytes
//   0x0d8ac4: D10243FF  sub      sp, sp, #0x90
//   0x0d8ac8: F9001BFB  str      x27, [sp, #0x30]
//   0x0d8acc: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0d8ad0: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1040_0x0d8ac4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8ac4ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfbULL) ^ 0x1a5718ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1041 | PC: 0x0d8e14 | FDE: 0x1a5768 | Size: 256 bytes
// Khung tháo gỡ #1041 | Địa chỉ PC: 0x0d8e14 | Địa chỉ FDE: 0x1a5768 | Kích thước: 256 bytes
//   0x0d8e14: D100C3FF  sub      sp, sp, #0x30
//   0x0d8e18: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d8e1c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d8e20: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1041_0x0d8e14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8e14ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1a5768ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1042 | PC: 0x0d8f84 | FDE: 0x1a57b0 | Size: 256 bytes
// Khung tháo gỡ #1042 | Địa chỉ PC: 0x0d8f84 | Địa chỉ FDE: 0x1a57b0 | Kích thước: 256 bytes
//   0x0d8f84: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0d8f88: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d8f8c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d8f90: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1042_0x0d8f84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8f84ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1a57b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1043 | PC: 0x0d917c | FDE: 0x1a5800 | Size: 256 bytes
// Khung tháo gỡ #1043 | Địa chỉ PC: 0x0d917c | Địa chỉ FDE: 0x1a5800 | Kích thước: 256 bytes
//   0x0d917c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0d9180: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d9184: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d9188: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1043_0x0d917c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d917cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1a5800ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1044 | PC: 0x0d9448 | FDE: 0x1a5850 | Size: 184 bytes
// Khung tháo gỡ #1044 | Địa chỉ PC: 0x0d9448 | Địa chỉ FDE: 0x1a5850 | Kích thước: 184 bytes
//   0x0d9448: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d944c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d9450: 910043FD  add      x29, sp, #0x10
//   0x0d9454: 340001C1  cbz      w1, #0xd948c
static inline uint64_t fde_func_1044_0x0d9448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9448ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a5850ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1045 | PC: 0x0d9500 | FDE: 0x1a5890 | Size: 92 bytes
// Khung tháo gỡ #1045 | Địa chỉ PC: 0x0d9500 | Địa chỉ FDE: 0x1a5890 | Kích thước: 92 bytes
//   0x0d9500: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d9504: 910003FD  mov      x29, sp
//   0x0d9508: 29412408  ldp      w8, w9, [x0, #8]
//   0x0d950c: 1100050A  add      w10, w8, #1
static inline uint64_t fde_func_1045_0x0d9500(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9500ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a5890ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1046 | PC: 0x0d955c | FDE: 0x1a58c8 | Size: 256 bytes
// Khung tháo gỡ #1046 | Địa chỉ PC: 0x0d955c | Địa chỉ FDE: 0x1a58c8 | Kích thước: 256 bytes
//   0x0d955c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d9560: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d9564: 910043FD  add      x29, sp, #0x10
//   0x0d9568: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1046_0x0d955c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d955cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a58c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1047 | PC: 0x0d965c | FDE: 0x1a5908 | Size: 140 bytes
// Khung tháo gỡ #1047 | Địa chỉ PC: 0x0d965c | Địa chỉ FDE: 0x1a5908 | Kích thước: 140 bytes
//   0x0d965c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0d9660: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d9664: 910043FD  add      x29, sp, #0x10
//   0x0d9668: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_1047_0x0d965c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d965cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a5908ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1048 | PC: 0x0d96e8 | FDE: 0x1a5948 | Size: 124 bytes
// Khung tháo gỡ #1048 | Địa chỉ PC: 0x0d96e8 | Địa chỉ FDE: 0x1a5948 | Kích thước: 124 bytes
//   0x0d96e8: F9400028  ldr      x8, [x1]
//   0x0d96ec: F9000008  str      x8, [x0]
//   0x0d96f0: F9400428  ldr      x8, [x1, #8]
//   0x0d96f4: F9000408  str      x8, [x0, #8]
static inline uint64_t fde_func_1048_0x0d96e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d96e8ULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0xf9000008ULL) ^ 0x1a5948ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1049 | PC: 0x0d9764 | FDE: 0x1a5980 | Size: 124 bytes
// Khung tháo gỡ #1049 | Địa chỉ PC: 0x0d9764 | Địa chỉ FDE: 0x1a5980 | Kích thước: 124 bytes
//   0x0d9764: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0d9768: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d976c: 910043FD  add      x29, sp, #0x10
//   0x0d9770: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1049_0x0d9764(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9764ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a5980ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1050 | PC: 0x0d97e0 | FDE: 0x1a59c0 | Size: 152 bytes
// Khung tháo gỡ #1050 | Địa chỉ PC: 0x0d97e0 | Địa chỉ FDE: 0x1a59c0 | Kích thước: 152 bytes
//   0x0d97e0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0d97e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d97e8: 910043FD  add      x29, sp, #0x10
//   0x0d97ec: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_1050_0x0d97e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d97e0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a59c0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1051 | PC: 0x0d9878 | FDE: 0x1a5a00 | Size: 256 bytes
// Khung tháo gỡ #1051 | Địa chỉ PC: 0x0d9878 | Địa chỉ FDE: 0x1a5a00 | Kích thước: 256 bytes
//   0x0d9878: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0d987c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d9880: 910043FD  add      x29, sp, #0x10
//   0x0d9884: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1051_0x0d9878(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9878ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a5a00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1052 | PC: 0x0d9a58 | FDE: 0x1a5a48 | Size: 256 bytes
// Khung tháo gỡ #1052 | Địa chỉ PC: 0x0d9a58 | Địa chỉ FDE: 0x1a5a48 | Kích thước: 256 bytes
//   0x0d9a58: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d9a5c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d9a60: 910043FD  add      x29, sp, #0x10
//   0x0d9a64: F9400009  ldr      x9, [x0]
static inline uint64_t fde_func_1052_0x0d9a58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9a58ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a5a48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1053 | PC: 0x0d9c08 | FDE: 0x1a5a88 | Size: 168 bytes
// Khung tháo gỡ #1053 | Địa chỉ PC: 0x0d9c08 | Địa chỉ FDE: 0x1a5a88 | Kích thước: 168 bytes
//   0x0d9c08: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d9c0c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d9c10: 910043FD  add      x29, sp, #0x10
//   0x0d9c14: 340001C1  cbz      w1, #0xd9c4c
static inline uint64_t fde_func_1053_0x0d9c08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9c08ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a5a88ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1054 | PC: 0x0d9cb0 | FDE: 0x1a5ac8 | Size: 256 bytes
// Khung tháo gỡ #1054 | Địa chỉ PC: 0x0d9cb0 | Địa chỉ FDE: 0x1a5ac8 | Kích thước: 256 bytes
//   0x0d9cb0: D10143FF  sub      sp, sp, #0x50
//   0x0d9cb4: F9000BF7  str      x23, [sp, #0x10]
//   0x0d9cb8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0d9cbc: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1054_0x0d9cb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9cb0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x1a5ac8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1055 | PC: 0x0d9e4c | FDE: 0x1a5b18 | Size: 256 bytes
// Khung tháo gỡ #1055 | Địa chỉ PC: 0x0d9e4c | Địa chỉ FDE: 0x1a5b18 | Kích thước: 256 bytes
//   0x0d9e4c: D10143FF  sub      sp, sp, #0x50
//   0x0d9e50: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0d9e54: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0d9e58: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1055_0x0d9e4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9e4cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1a5b18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1056 | PC: 0x0da014 | FDE: 0x1a5b68 | Size: 144 bytes
// Khung tháo gỡ #1056 | Địa chỉ PC: 0x0da014 | Địa chỉ FDE: 0x1a5b68 | Kích thước: 144 bytes
//   0x0da014: F9400808  ldr      x8, [x0, #0x10]
//   0x0da018: F9400508  ldr      x8, [x8, #8]
//   0x0da01c: F9400500  ldr      x0, [x8, #8]
//   0x0da020: D65F03C0  ret      
static inline uint64_t fde_func_1056_0x0da014(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da014ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xf9400508ULL) ^ 0x1a5b68ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1057 | PC: 0x0da0a4 | FDE: 0x1a5ba0 | Size: 88 bytes
// Khung tháo gỡ #1057 | Địa chỉ PC: 0x0da0a4 | Địa chỉ FDE: 0x1a5ba0 | Kích thước: 88 bytes
//   0x0da0a4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0da0a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0da0ac: 910043FD  add      x29, sp, #0x10
//   0x0da0b0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1057_0x0da0a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da0a4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a5ba0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1058 | PC: 0x0da0fc | FDE: 0x1a5bd8 | Size: 216 bytes
// Khung tháo gỡ #1058 | Địa chỉ PC: 0x0da0fc | Địa chỉ FDE: 0x1a5bd8 | Kích thước: 216 bytes
//   0x0da0fc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0da100: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0da104: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0da108: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1058_0x0da0fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da0fcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1a5bd8ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1059 | PC: 0x0da1d4 | FDE: 0x1a5c18 | Size: 60 bytes
// Khung tháo gỡ #1059 | Địa chỉ PC: 0x0da1d4 | Địa chỉ FDE: 0x1a5c18 | Kích thước: 60 bytes
//   0x0da1d4: 71000C3F  cmp      w1, #3
//   0x0da1d8: 540000E8  b.hi     #0xda1f4
//   0x0da1dc: 90000769  adrp     x9, #0x1c6000
//   0x0da1e0: 2A0003E8  mov      w8, w0
static inline uint64_t fde_func_1059_0x0da1d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da1d4ULL ^ (static_cast<uint64_t>(0x71000c3fULL) << 13);
    acc = (acc + a1 + 0x540000e8ULL) ^ 0x1a5c18ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1060 | PC: 0x0da210 | FDE: 0x1a5c48 | Size: 36 bytes
// Khung tháo gỡ #1060 | Địa chỉ PC: 0x0da210 | Địa chỉ FDE: 0x1a5c48 | Kích thước: 36 bytes
//   0x0da210: FD400000  ldr      d0, [x0]
//   0x0da214: 1E614000  fneg     d0, d0
//   0x0da218: FD000100  str      d0, [x8]
//   0x0da21c: D65F03C0  ret      
static inline uint64_t fde_func_1060_0x0da210(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da210ULL ^ (static_cast<uint64_t>(0xfd400000ULL) << 13);
    acc = (acc + a1 + 0x1e614000ULL) ^ 0x1a5c48ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1061 | PC: 0x0da234 | FDE: 0x1a5c78 | Size: 44 bytes
// Khung tháo gỡ #1061 | Địa chỉ PC: 0x0da234 | Địa chỉ FDE: 0x1a5c78 | Kích thước: 44 bytes
//   0x0da234: F9400009  ldr      x9, [x0]
//   0x0da238: F940002A  ldr      x10, [x1]
//   0x0da23c: 8B090149  add      x9, x10, x9
//   0x0da240: F9000109  str      x9, [x8]
static inline uint64_t fde_func_1061_0x0da234(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da234ULL ^ (static_cast<uint64_t>(0xf9400009ULL) << 13);
    acc = (acc + a1 + 0xf940002aULL) ^ 0x1a5c78ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1062 | PC: 0x0da260 | FDE: 0x1a5ca8 | Size: 40 bytes
// Khung tháo gỡ #1062 | Địa chỉ PC: 0x0da260 | Địa chỉ FDE: 0x1a5ca8 | Kích thước: 40 bytes
//   0x0da260: FD400000  ldr      d0, [x0]
//   0x0da264: FD400021  ldr      d1, [x1]
//   0x0da268: 1E612800  fadd     d0, d0, d1
//   0x0da26c: FD000100  str      d0, [x8]
static inline uint64_t fde_func_1062_0x0da260(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da260ULL ^ (static_cast<uint64_t>(0xfd400000ULL) << 13);
    acc = (acc + a1 + 0xfd400021ULL) ^ 0x1a5ca8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1063 | PC: 0x0da288 | FDE: 0x1a5cd8 | Size: 44 bytes
// Khung tháo gỡ #1063 | Địa chỉ PC: 0x0da288 | Địa chỉ FDE: 0x1a5cd8 | Kích thước: 44 bytes
//   0x0da288: F9400009  ldr      x9, [x0]
//   0x0da28c: F940002A  ldr      x10, [x1]
//   0x0da290: CB0A0129  sub      x9, x9, x10
//   0x0da294: F9000109  str      x9, [x8]
static inline uint64_t fde_func_1063_0x0da288(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da288ULL ^ (static_cast<uint64_t>(0xf9400009ULL) << 13);
    acc = (acc + a1 + 0xf940002aULL) ^ 0x1a5cd8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1064 | PC: 0x0da2b4 | FDE: 0x1a5d08 | Size: 40 bytes
// Khung tháo gỡ #1064 | Địa chỉ PC: 0x0da2b4 | Địa chỉ FDE: 0x1a5d08 | Kích thước: 40 bytes
//   0x0da2b4: FD400000  ldr      d0, [x0]
//   0x0da2b8: FD400021  ldr      d1, [x1]
//   0x0da2bc: 1E613800  fsub     d0, d0, d1
//   0x0da2c0: FD000100  str      d0, [x8]
static inline uint64_t fde_func_1064_0x0da2b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da2b4ULL ^ (static_cast<uint64_t>(0xfd400000ULL) << 13);
    acc = (acc + a1 + 0xfd400021ULL) ^ 0x1a5d08ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1065 | PC: 0x0da2dc | FDE: 0x1a5d38 | Size: 44 bytes
// Khung tháo gỡ #1065 | Địa chỉ PC: 0x0da2dc | Địa chỉ FDE: 0x1a5d38 | Kích thước: 44 bytes
//   0x0da2dc: F9400009  ldr      x9, [x0]
//   0x0da2e0: F940002A  ldr      x10, [x1]
//   0x0da2e4: 9B097D49  mul      x9, x10, x9
//   0x0da2e8: F9000109  str      x9, [x8]
static inline uint64_t fde_func_1065_0x0da2dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da2dcULL ^ (static_cast<uint64_t>(0xf9400009ULL) << 13);
    acc = (acc + a1 + 0xf940002aULL) ^ 0x1a5d38ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1066 | PC: 0x0da308 | FDE: 0x1a5d68 | Size: 40 bytes
// Khung tháo gỡ #1066 | Địa chỉ PC: 0x0da308 | Địa chỉ FDE: 0x1a5d68 | Kích thước: 40 bytes
//   0x0da308: FD400000  ldr      d0, [x0]
//   0x0da30c: FD400021  ldr      d1, [x1]
//   0x0da310: 1E610800  fmul     d0, d0, d1
//   0x0da314: FD000100  str      d0, [x8]
static inline uint64_t fde_func_1066_0x0da308(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da308ULL ^ (static_cast<uint64_t>(0xfd400000ULL) << 13);
    acc = (acc + a1 + 0xfd400021ULL) ^ 0x1a5d68ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1067 | PC: 0x0da330 | FDE: 0x1a5d98 | Size: 44 bytes
// Khung tháo gỡ #1067 | Địa chỉ PC: 0x0da330 | Địa chỉ FDE: 0x1a5d98 | Kích thước: 44 bytes
//   0x0da330: F9400009  ldr      x9, [x0]
//   0x0da334: F940002A  ldr      x10, [x1]
//   0x0da338: 9ACA0D29  sdiv     x9, x9, x10
//   0x0da33c: F9000109  str      x9, [x8]
static inline uint64_t fde_func_1067_0x0da330(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da330ULL ^ (static_cast<uint64_t>(0xf9400009ULL) << 13);
    acc = (acc + a1 + 0xf940002aULL) ^ 0x1a5d98ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1068 | PC: 0x0da35c | FDE: 0x1a5dc8 | Size: 44 bytes
// Khung tháo gỡ #1068 | Địa chỉ PC: 0x0da35c | Địa chỉ FDE: 0x1a5dc8 | Kích thước: 44 bytes
//   0x0da35c: F9400009  ldr      x9, [x0]
//   0x0da360: F940002A  ldr      x10, [x1]
//   0x0da364: 9ACA0D2B  sdiv     x11, x9, x10
//   0x0da368: 9B0AA569  msub     x9, x11, x10, x9
static inline uint64_t fde_func_1068_0x0da35c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da35cULL ^ (static_cast<uint64_t>(0xf9400009ULL) << 13);
    acc = (acc + a1 + 0xf940002aULL) ^ 0x1a5dc8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1069 | PC: 0x0da388 | FDE: 0x1a5df8 | Size: 44 bytes
// Khung tháo gỡ #1069 | Địa chỉ PC: 0x0da388 | Địa chỉ FDE: 0x1a5df8 | Kích thước: 44 bytes
//   0x0da388: F9400009  ldr      x9, [x0]
//   0x0da38c: F940002A  ldr      x10, [x1]
//   0x0da390: 9ACA0929  udiv     x9, x9, x10
//   0x0da394: F9000109  str      x9, [x8]
static inline uint64_t fde_func_1069_0x0da388(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da388ULL ^ (static_cast<uint64_t>(0xf9400009ULL) << 13);
    acc = (acc + a1 + 0xf940002aULL) ^ 0x1a5df8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1070 | PC: 0x0da3b4 | FDE: 0x1a5e28 | Size: 44 bytes
// Khung tháo gỡ #1070 | Địa chỉ PC: 0x0da3b4 | Địa chỉ FDE: 0x1a5e28 | Kích thước: 44 bytes
//   0x0da3b4: F9400009  ldr      x9, [x0]
//   0x0da3b8: F940002A  ldr      x10, [x1]
//   0x0da3bc: 9ACA092B  udiv     x11, x9, x10
//   0x0da3c0: 9B0AA569  msub     x9, x11, x10, x9
static inline uint64_t fde_func_1070_0x0da3b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da3b4ULL ^ (static_cast<uint64_t>(0xf9400009ULL) << 13);
    acc = (acc + a1 + 0xf940002aULL) ^ 0x1a5e28ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1071 | PC: 0x0da3e0 | FDE: 0x1a5e58 | Size: 40 bytes
// Khung tháo gỡ #1071 | Địa chỉ PC: 0x0da3e0 | Địa chỉ FDE: 0x1a5e58 | Kích thước: 40 bytes
//   0x0da3e0: F9400009  ldr      x9, [x0]
//   0x0da3e4: F940002A  ldr      x10, [x1]
//   0x0da3e8: 9ACA2129  lsl      x9, x9, x10
//   0x0da3ec: F9000109  str      x9, [x8]
static inline uint64_t fde_func_1071_0x0da3e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da3e0ULL ^ (static_cast<uint64_t>(0xf9400009ULL) << 13);
    acc = (acc + a1 + 0xf940002aULL) ^ 0x1a5e58ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1072 | PC: 0x0da408 | FDE: 0x1a5e88 | Size: 40 bytes
// Khung tháo gỡ #1072 | Địa chỉ PC: 0x0da408 | Địa chỉ FDE: 0x1a5e88 | Kích thước: 40 bytes
//   0x0da408: F9400009  ldr      x9, [x0]
//   0x0da40c: F940002A  ldr      x10, [x1]
//   0x0da410: 9ACA2929  asr      x9, x9, x10
//   0x0da414: F9000109  str      x9, [x8]
static inline uint64_t fde_func_1072_0x0da408(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da408ULL ^ (static_cast<uint64_t>(0xf9400009ULL) << 13);
    acc = (acc + a1 + 0xf940002aULL) ^ 0x1a5e88ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1073 | PC: 0x0da430 | FDE: 0x1a5eb8 | Size: 44 bytes
// Khung tháo gỡ #1073 | Địa chỉ PC: 0x0da430 | Địa chỉ FDE: 0x1a5eb8 | Kích thước: 44 bytes
//   0x0da430: F9400009  ldr      x9, [x0]
//   0x0da434: F940002A  ldr      x10, [x1]
//   0x0da438: 9ACA2529  lsr      x9, x9, x10
//   0x0da43c: F9000109  str      x9, [x8]
static inline uint64_t fde_func_1073_0x0da430(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da430ULL ^ (static_cast<uint64_t>(0xf9400009ULL) << 13);
    acc = (acc + a1 + 0xf940002aULL) ^ 0x1a5eb8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1074 | PC: 0x0da45c | FDE: 0x1a5ee8 | Size: 44 bytes
// Khung tháo gỡ #1074 | Địa chỉ PC: 0x0da45c | Địa chỉ FDE: 0x1a5ee8 | Kích thước: 44 bytes
//   0x0da45c: F9400029  ldr      x9, [x1]
//   0x0da460: F940000A  ldr      x10, [x0]
//   0x0da464: CB0903E9  neg      x9, x9
//   0x0da468: 9AC92D49  ror      x9, x10, x9
static inline uint64_t fde_func_1074_0x0da45c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da45cULL ^ (static_cast<uint64_t>(0xf9400029ULL) << 13);
    acc = (acc + a1 + 0xf940000aULL) ^ 0x1a5ee8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1075 | PC: 0x0da488 | FDE: 0x1a5f18 | Size: 40 bytes
// Khung tháo gỡ #1075 | Địa chỉ PC: 0x0da488 | Địa chỉ FDE: 0x1a5f18 | Kích thước: 40 bytes
//   0x0da488: F9400009  ldr      x9, [x0]
//   0x0da48c: F940002A  ldr      x10, [x1]
//   0x0da490: 9ACA2D29  ror      x9, x9, x10
//   0x0da494: F9000109  str      x9, [x8]
static inline uint64_t fde_func_1075_0x0da488(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da488ULL ^ (static_cast<uint64_t>(0xf9400009ULL) << 13);
    acc = (acc + a1 + 0xf940002aULL) ^ 0x1a5f18ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1076 | PC: 0x0da4b0 | FDE: 0x1a5f48 | Size: 40 bytes
// Khung tháo gỡ #1076 | Địa chỉ PC: 0x0da4b0 | Địa chỉ FDE: 0x1a5f48 | Kích thước: 40 bytes
//   0x0da4b0: F9400009  ldr      x9, [x0]
//   0x0da4b4: F940002A  ldr      x10, [x1]
//   0x0da4b8: AA090149  orr      x9, x10, x9
//   0x0da4bc: F9000109  str      x9, [x8]
static inline uint64_t fde_func_1076_0x0da4b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da4b0ULL ^ (static_cast<uint64_t>(0xf9400009ULL) << 13);
    acc = (acc + a1 + 0xf940002aULL) ^ 0x1a5f48ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1077 | PC: 0x0da4d8 | FDE: 0x1a5f78 | Size: 40 bytes
// Khung tháo gỡ #1077 | Địa chỉ PC: 0x0da4d8 | Địa chỉ FDE: 0x1a5f78 | Kích thước: 40 bytes
//   0x0da4d8: F9400009  ldr      x9, [x0]
//   0x0da4dc: F940002A  ldr      x10, [x1]
//   0x0da4e0: CA090149  eor      x9, x10, x9
//   0x0da4e4: F9000109  str      x9, [x8]
static inline uint64_t fde_func_1077_0x0da4d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da4d8ULL ^ (static_cast<uint64_t>(0xf9400009ULL) << 13);
    acc = (acc + a1 + 0xf940002aULL) ^ 0x1a5f78ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1078 | PC: 0x0da500 | FDE: 0x1a5fa8 | Size: 44 bytes
// Khung tháo gỡ #1078 | Địa chỉ PC: 0x0da500 | Địa chỉ FDE: 0x1a5fa8 | Kích thước: 44 bytes
//   0x0da500: F9400009  ldr      x9, [x0]
//   0x0da504: F940002A  ldr      x10, [x1]
//   0x0da508: 8A090149  and      x9, x10, x9
//   0x0da50c: F9000109  str      x9, [x8]
static inline uint64_t fde_func_1078_0x0da500(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da500ULL ^ (static_cast<uint64_t>(0xf9400009ULL) << 13);
    acc = (acc + a1 + 0xf940002aULL) ^ 0x1a5fa8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1079 | PC: 0x0da52c | FDE: 0x1a5fd8 | Size: 44 bytes
// Khung tháo gỡ #1079 | Địa chỉ PC: 0x0da52c | Địa chỉ FDE: 0x1a5fd8 | Kích thước: 44 bytes
//   0x0da52c: FD400000  ldr      d0, [x0]
//   0x0da530: FD400021  ldr      d1, [x1]
//   0x0da534: 1E616800  fmaxnm   d0, d0, d1
//   0x0da538: FD000100  str      d0, [x8]
static inline uint64_t fde_func_1079_0x0da52c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da52cULL ^ (static_cast<uint64_t>(0xfd400000ULL) << 13);
    acc = (acc + a1 + 0xfd400021ULL) ^ 0x1a5fd8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1080 | PC: 0x0da558 | FDE: 0x1a6008 | Size: 120 bytes
// Khung tháo gỡ #1080 | Địa chỉ PC: 0x0da558 | Địa chỉ FDE: 0x1a6008 | Kích thước: 120 bytes
//   0x0da558: FD400000  ldr      d0, [x0]
//   0x0da55c: FD400021  ldr      d1, [x1]
//   0x0da560: 1E617800  fminnm   d0, d0, d1
//   0x0da564: FD000100  str      d0, [x8]
static inline uint64_t fde_func_1080_0x0da558(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da558ULL ^ (static_cast<uint64_t>(0xfd400000ULL) << 13);
    acc = (acc + a1 + 0xfd400021ULL) ^ 0x1a6008ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1081 | PC: 0x0da5d0 | FDE: 0x1a6038 | Size: 208 bytes
// Khung tháo gỡ #1081 | Địa chỉ PC: 0x0da5d0 | Địa chỉ FDE: 0x1a6038 | Kích thước: 208 bytes
//   0x0da5d0: F9400009  ldr      x9, [x0]
//   0x0da5d4: B4000309  cbz      x9, #0xda634
//   0x0da5d8: CB0903EA  neg      x10, x9
//   0x0da5dc: 8A0A0129  and      x9, x9, x10
static inline uint64_t fde_func_1081_0x0da5d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da5d0ULL ^ (static_cast<uint64_t>(0xf9400009ULL) << 13);
    acc = (acc + a1 + 0xb4000309ULL) ^ 0x1a6038ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1082 | PC: 0x0da6a0 | FDE: 0x1a6068 | Size: 136 bytes
// Khung tháo gỡ #1082 | Địa chỉ PC: 0x0da6a0 | Địa chỉ FDE: 0x1a6068 | Kích thước: 136 bytes
//   0x0da6a0: F9400009  ldr      x9, [x0]
//   0x0da6a4: B40002E9  cbz      x9, #0xda700
//   0x0da6a8: CB0903EA  neg      x10, x9
//   0x0da6ac: 8A0A0129  and      x9, x9, x10
static inline uint64_t fde_func_1082_0x0da6a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da6a0ULL ^ (static_cast<uint64_t>(0xf9400009ULL) << 13);
    acc = (acc + a1 + 0xb40002e9ULL) ^ 0x1a6068ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1083 | PC: 0x0da728 | FDE: 0x1a6098 | Size: 44 bytes
// Khung tháo gỡ #1083 | Địa chỉ PC: 0x0da728 | Địa chỉ FDE: 0x1a6098 | Kích thước: 44 bytes
//   0x0da728: FD400000  ldr      d0, [x0]
//   0x0da72c: 0E205800  cnt      v0.8b, v0.8b
//   0x0da730: 2E303800  uaddlv   h0, v0.8b
//   0x0da734: 1E260009  fmov     w9, s0
static inline uint64_t fde_func_1083_0x0da728(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da728ULL ^ (static_cast<uint64_t>(0xfd400000ULL) << 13);
    acc = (acc + a1 + 0x0e205800ULL) ^ 0x1a6098ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1084 | PC: 0x0da754 | FDE: 0x1a60c8 | Size: 36 bytes
// Khung tháo gỡ #1084 | Địa chỉ PC: 0x0da754 | Địa chỉ FDE: 0x1a60c8 | Kích thước: 36 bytes
//   0x0da754: FD400000  ldr      d0, [x0]
//   0x0da758: 1E60C000  fabs     d0, d0
//   0x0da75c: FD000100  str      d0, [x8]
//   0x0da760: D65F03C0  ret      
static inline uint64_t fde_func_1084_0x0da754(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da754ULL ^ (static_cast<uint64_t>(0xfd400000ULL) << 13);
    acc = (acc + a1 + 0x1e60c000ULL) ^ 0x1a60c8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1085 | PC: 0x0da778 | FDE: 0x1a60f8 | Size: 36 bytes
// Khung tháo gỡ #1085 | Địa chỉ PC: 0x0da778 | Địa chỉ FDE: 0x1a60f8 | Kích thước: 36 bytes
//   0x0da778: FD400000  ldr      d0, [x0]
//   0x0da77c: 1E64C000  frintp   d0, d0
//   0x0da780: FD000100  str      d0, [x8]
//   0x0da784: D65F03C0  ret      
static inline uint64_t fde_func_1085_0x0da778(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da778ULL ^ (static_cast<uint64_t>(0xfd400000ULL) << 13);
    acc = (acc + a1 + 0x1e64c000ULL) ^ 0x1a60f8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1086 | PC: 0x0da79c | FDE: 0x1a6128 | Size: 36 bytes
// Khung tháo gỡ #1086 | Địa chỉ PC: 0x0da79c | Địa chỉ FDE: 0x1a6128 | Kích thước: 36 bytes
//   0x0da79c: FD400000  ldr      d0, [x0]
//   0x0da7a0: 1E654000  frintm   d0, d0
//   0x0da7a4: FD000100  str      d0, [x8]
//   0x0da7a8: D65F03C0  ret      
static inline uint64_t fde_func_1086_0x0da79c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da79cULL ^ (static_cast<uint64_t>(0xfd400000ULL) << 13);
    acc = (acc + a1 + 0x1e654000ULL) ^ 0x1a6128ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1087 | PC: 0x0da7c0 | FDE: 0x1a6158 | Size: 36 bytes
// Khung tháo gỡ #1087 | Địa chỉ PC: 0x0da7c0 | Địa chỉ FDE: 0x1a6158 | Kích thước: 36 bytes
//   0x0da7c0: FD400000  ldr      d0, [x0]
//   0x0da7c4: 1E65C000  frintz   d0, d0
//   0x0da7c8: FD000100  str      d0, [x8]
//   0x0da7cc: D65F03C0  ret      
static inline uint64_t fde_func_1087_0x0da7c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da7c0ULL ^ (static_cast<uint64_t>(0xfd400000ULL) << 13);
    acc = (acc + a1 + 0x1e65c000ULL) ^ 0x1a6158ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1088 | PC: 0x0da7e4 | FDE: 0x1a6188 | Size: 36 bytes
// Khung tháo gỡ #1088 | Địa chỉ PC: 0x0da7e4 | Địa chỉ FDE: 0x1a6188 | Kích thước: 36 bytes
//   0x0da7e4: FD400000  ldr      d0, [x0]
//   0x0da7e8: 1E67C000  frinti   d0, d0
//   0x0da7ec: FD000100  str      d0, [x8]
//   0x0da7f0: D65F03C0  ret      
static inline uint64_t fde_func_1088_0x0da7e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da7e4ULL ^ (static_cast<uint64_t>(0xfd400000ULL) << 13);
    acc = (acc + a1 + 0x1e67c000ULL) ^ 0x1a6188ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1089 | PC: 0x0da808 | FDE: 0x1a61b8 | Size: 40 bytes
// Khung tháo gỡ #1089 | Địa chỉ PC: 0x0da808 | Địa chỉ FDE: 0x1a61b8 | Kích thước: 40 bytes
//   0x0da808: FD400000  ldr      d0, [x0]
//   0x0da80c: 1E61C000  fsqrt    d0, d0
//   0x0da810: FD000100  str      d0, [x8]
//   0x0da814: D65F03C0  ret      
static inline uint64_t fde_func_1089_0x0da808(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da808ULL ^ (static_cast<uint64_t>(0xfd400000ULL) << 13);
    acc = (acc + a1 + 0x1e61c000ULL) ^ 0x1a61b8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1090 | PC: 0x0da830 | FDE: 0x1a61e8 | Size: 48 bytes
// Khung tháo gỡ #1090 | Địa chỉ PC: 0x0da830 | Địa chỉ FDE: 0x1a61e8 | Kích thước: 48 bytes
//   0x0da830: FD400000  ldr      d0, [x0]
//   0x0da834: FD400021  ldr      d1, [x1]
//   0x0da838: 1E611800  fdiv     d0, d0, d1
//   0x0da83c: FD000100  str      d0, [x8]
static inline uint64_t fde_func_1090_0x0da830(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da830ULL ^ (static_cast<uint64_t>(0xfd400000ULL) << 13);
    acc = (acc + a1 + 0xfd400021ULL) ^ 0x1a61e8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1091 | PC: 0x0da860 | FDE: 0x1a6218 | Size: 68 bytes
// Khung tháo gỡ #1091 | Địa chỉ PC: 0x0da860 | Địa chỉ FDE: 0x1a6218 | Kích thước: 68 bytes
//   0x0da860: FD400000  ldr      d0, [x0]
//   0x0da864: FD400021  ldr      d1, [x1]
//   0x0da868: 6F00E402  movi     v2.2d, #0000000000000000
//   0x0da86c: 6EE0F842  fneg     v2.2d, v2.2d
static inline uint64_t fde_func_1091_0x0da860(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da860ULL ^ (static_cast<uint64_t>(0xfd400000ULL) << 13);
    acc = (acc + a1 + 0xfd400021ULL) ^ 0x1a6218ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1092 | PC: 0x0da8a4 | FDE: 0x1a6248 | Size: 40 bytes
// Khung tháo gỡ #1092 | Địa chỉ PC: 0x0da8a4 | Địa chỉ FDE: 0x1a6248 | Kích thước: 40 bytes
//   0x0da8a4: B9400008  ldr      w8, [x0]
//   0x0da8a8: B9400029  ldr      w9, [x1]
//   0x0da8ac: 6B09011F  cmp      w8, w9
//   0x0da8b0: 1A9F17E0  cset     w0, eq
static inline uint64_t fde_func_1092_0x0da8a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da8a4ULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0xb9400029ULL) ^ 0x1a6248ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1093 | PC: 0x0da8cc | FDE: 0x1a6278 | Size: 40 bytes
// Khung tháo gỡ #1093 | Địa chỉ PC: 0x0da8cc | Địa chỉ FDE: 0x1a6278 | Kích thước: 40 bytes
//   0x0da8cc: BD400000  ldr      s0, [x0]
//   0x0da8d0: BD400021  ldr      s1, [x1]
//   0x0da8d4: 1E212000  fcmp     s0, s1
//   0x0da8d8: 1A9F17E0  cset     w0, eq
static inline uint64_t fde_func_1093_0x0da8cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da8ccULL ^ (static_cast<uint64_t>(0xbd400000ULL) << 13);
    acc = (acc + a1 + 0xbd400021ULL) ^ 0x1a6278ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1094 | PC: 0x0da8f4 | FDE: 0x1a62a8 | Size: 40 bytes
// Khung tháo gỡ #1094 | Địa chỉ PC: 0x0da8f4 | Địa chỉ FDE: 0x1a62a8 | Kích thước: 40 bytes
//   0x0da8f4: B9400008  ldr      w8, [x0]
//   0x0da8f8: B9400029  ldr      w9, [x1]
//   0x0da8fc: 6B09011F  cmp      w8, w9
//   0x0da900: 1A9F07E0  cset     w0, ne
static inline uint64_t fde_func_1094_0x0da8f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da8f4ULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0xb9400029ULL) ^ 0x1a62a8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1095 | PC: 0x0da91c | FDE: 0x1a62d8 | Size: 40 bytes
// Khung tháo gỡ #1095 | Địa chỉ PC: 0x0da91c | Địa chỉ FDE: 0x1a62d8 | Kích thước: 40 bytes
//   0x0da91c: BD400000  ldr      s0, [x0]
//   0x0da920: BD400021  ldr      s1, [x1]
//   0x0da924: 1E212000  fcmp     s0, s1
//   0x0da928: 1A9F07E0  cset     w0, ne
static inline uint64_t fde_func_1095_0x0da91c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da91cULL ^ (static_cast<uint64_t>(0xbd400000ULL) << 13);
    acc = (acc + a1 + 0xbd400021ULL) ^ 0x1a62d8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1096 | PC: 0x0da944 | FDE: 0x1a6308 | Size: 40 bytes
// Khung tháo gỡ #1096 | Địa chỉ PC: 0x0da944 | Địa chỉ FDE: 0x1a6308 | Kích thước: 40 bytes
//   0x0da944: B9400008  ldr      w8, [x0]
//   0x0da948: B9400029  ldr      w9, [x1]
//   0x0da94c: 6B09011F  cmp      w8, w9
//   0x0da950: 1A9FD7E0  cset     w0, gt
static inline uint64_t fde_func_1096_0x0da944(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da944ULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0xb9400029ULL) ^ 0x1a6308ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1097 | PC: 0x0da96c | FDE: 0x1a6338 | Size: 40 bytes
// Khung tháo gỡ #1097 | Địa chỉ PC: 0x0da96c | Địa chỉ FDE: 0x1a6338 | Kích thước: 40 bytes
//   0x0da96c: BD400000  ldr      s0, [x0]
//   0x0da970: BD400021  ldr      s1, [x1]
//   0x0da974: 1E212000  fcmp     s0, s1
//   0x0da978: 1A9FD7E0  cset     w0, gt
static inline uint64_t fde_func_1097_0x0da96c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da96cULL ^ (static_cast<uint64_t>(0xbd400000ULL) << 13);
    acc = (acc + a1 + 0xbd400021ULL) ^ 0x1a6338ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1098 | PC: 0x0da994 | FDE: 0x1a6368 | Size: 40 bytes
// Khung tháo gỡ #1098 | Địa chỉ PC: 0x0da994 | Địa chỉ FDE: 0x1a6368 | Kích thước: 40 bytes
//   0x0da994: B9400008  ldr      w8, [x0]
//   0x0da998: B9400029  ldr      w9, [x1]
//   0x0da99c: 6B09011F  cmp      w8, w9
//   0x0da9a0: 1A9FB7E0  cset     w0, ge
static inline uint64_t fde_func_1098_0x0da994(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da994ULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0xb9400029ULL) ^ 0x1a6368ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1099 | PC: 0x0da9bc | FDE: 0x1a6398 | Size: 40 bytes
// Khung tháo gỡ #1099 | Địa chỉ PC: 0x0da9bc | Địa chỉ FDE: 0x1a6398 | Kích thước: 40 bytes
//   0x0da9bc: BD400000  ldr      s0, [x0]
//   0x0da9c0: BD400021  ldr      s1, [x1]
//   0x0da9c4: 1E212000  fcmp     s0, s1
//   0x0da9c8: 1A9FB7E0  cset     w0, ge
static inline uint64_t fde_func_1099_0x0da9bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da9bcULL ^ (static_cast<uint64_t>(0xbd400000ULL) << 13);
    acc = (acc + a1 + 0xbd400021ULL) ^ 0x1a6398ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1100 | PC: 0x0da9e4 | FDE: 0x1a63c8 | Size: 40 bytes
// Khung tháo gỡ #1100 | Địa chỉ PC: 0x0da9e4 | Địa chỉ FDE: 0x1a63c8 | Kích thước: 40 bytes
//   0x0da9e4: B9400008  ldr      w8, [x0]
//   0x0da9e8: B9400029  ldr      w9, [x1]
//   0x0da9ec: 6B09011F  cmp      w8, w9
//   0x0da9f0: 1A9FA7E0  cset     w0, lt
static inline uint64_t fde_func_1100_0x0da9e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da9e4ULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0xb9400029ULL) ^ 0x1a63c8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1101 | PC: 0x0daa0c | FDE: 0x1a63f8 | Size: 40 bytes
// Khung tháo gỡ #1101 | Địa chỉ PC: 0x0daa0c | Địa chỉ FDE: 0x1a63f8 | Kích thước: 40 bytes
//   0x0daa0c: BD400000  ldr      s0, [x0]
//   0x0daa10: BD400021  ldr      s1, [x1]
//   0x0daa14: 1E212000  fcmp     s0, s1
//   0x0daa18: 1A9FA7E0  cset     w0, lt
static inline uint64_t fde_func_1101_0x0daa0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0daa0cULL ^ (static_cast<uint64_t>(0xbd400000ULL) << 13);
    acc = (acc + a1 + 0xbd400021ULL) ^ 0x1a63f8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1102 | PC: 0x0daa34 | FDE: 0x1a6428 | Size: 40 bytes
// Khung tháo gỡ #1102 | Địa chỉ PC: 0x0daa34 | Địa chỉ FDE: 0x1a6428 | Kích thước: 40 bytes
//   0x0daa34: B9400008  ldr      w8, [x0]
//   0x0daa38: B9400029  ldr      w9, [x1]
//   0x0daa3c: 6B09011F  cmp      w8, w9
//   0x0daa40: 1A9FC7E0  cset     w0, le
static inline uint64_t fde_func_1102_0x0daa34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0daa34ULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0xb9400029ULL) ^ 0x1a6428ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1103 | PC: 0x0daa5c | FDE: 0x1a6458 | Size: 40 bytes
// Khung tháo gỡ #1103 | Địa chỉ PC: 0x0daa5c | Địa chỉ FDE: 0x1a6458 | Kích thước: 40 bytes
//   0x0daa5c: BD400000  ldr      s0, [x0]
//   0x0daa60: BD400021  ldr      s1, [x1]
//   0x0daa64: 1E212000  fcmp     s0, s1
//   0x0daa68: 1A9FC7E0  cset     w0, le
static inline uint64_t fde_func_1103_0x0daa5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0daa5cULL ^ (static_cast<uint64_t>(0xbd400000ULL) << 13);
    acc = (acc + a1 + 0xbd400021ULL) ^ 0x1a6458ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1104 | PC: 0x0daa84 | FDE: 0x1a6488 | Size: 40 bytes
// Khung tháo gỡ #1104 | Địa chỉ PC: 0x0daa84 | Địa chỉ FDE: 0x1a6488 | Kích thước: 40 bytes
//   0x0daa84: B9400008  ldr      w8, [x0]
//   0x0daa88: B9400029  ldr      w9, [x1]
//   0x0daa8c: 6B09011F  cmp      w8, w9
//   0x0daa90: 1A9F97E0  cset     w0, hi
static inline uint64_t fde_func_1104_0x0daa84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0daa84ULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0xb9400029ULL) ^ 0x1a6488ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1105 | PC: 0x0daaac | FDE: 0x1a64b8 | Size: 40 bytes
// Khung tháo gỡ #1105 | Địa chỉ PC: 0x0daaac | Địa chỉ FDE: 0x1a64b8 | Kích thước: 40 bytes
//   0x0daaac: B9400008  ldr      w8, [x0]
//   0x0daab0: B9400029  ldr      w9, [x1]
//   0x0daab4: 6B09011F  cmp      w8, w9
//   0x0daab8: 1A9F37E0  cset     w0, hs
static inline uint64_t fde_func_1105_0x0daaac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0daaacULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0xb9400029ULL) ^ 0x1a64b8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1106 | PC: 0x0daad4 | FDE: 0x1a64e8 | Size: 40 bytes
// Khung tháo gỡ #1106 | Địa chỉ PC: 0x0daad4 | Địa chỉ FDE: 0x1a64e8 | Kích thước: 40 bytes
//   0x0daad4: B9400008  ldr      w8, [x0]
//   0x0daad8: B9400029  ldr      w9, [x1]
//   0x0daadc: 6B09011F  cmp      w8, w9
//   0x0daae0: 1A9F27E0  cset     w0, lo
static inline uint64_t fde_func_1106_0x0daad4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0daad4ULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0xb9400029ULL) ^ 0x1a64e8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1107 | PC: 0x0daafc | FDE: 0x1a6518 | Size: 40 bytes
// Khung tháo gỡ #1107 | Địa chỉ PC: 0x0daafc | Địa chỉ FDE: 0x1a6518 | Kích thước: 40 bytes
//   0x0daafc: B9400008  ldr      w8, [x0]
//   0x0dab00: B9400029  ldr      w9, [x1]
//   0x0dab04: 6B09011F  cmp      w8, w9
//   0x0dab08: 1A9F87E0  cset     w0, ls
static inline uint64_t fde_func_1107_0x0daafc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0daafcULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0xb9400029ULL) ^ 0x1a6518ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1108 | PC: 0x0dab24 | FDE: 0x1a6548 | Size: 256 bytes
// Khung tháo gỡ #1108 | Địa chỉ PC: 0x0dab24 | Địa chỉ FDE: 0x1a6548 | Kích thước: 256 bytes
//   0x0dab24: D10243FF  sub      sp, sp, #0x90
//   0x0dab28: F9001BFB  str      x27, [sp, #0x30]
//   0x0dab2c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0dab30: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1108_0x0dab24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dab24ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfbULL) ^ 0x1a6548ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1109 | PC: 0x0dad74 | FDE: 0x1a65a0 | Size: 256 bytes
// Khung tháo gỡ #1109 | Địa chỉ PC: 0x0dad74 | Địa chỉ FDE: 0x1a65a0 | Kích thước: 256 bytes
//   0x0dad74: D10143FF  sub      sp, sp, #0x50
//   0x0dad78: F9000BF7  str      x23, [sp, #0x10]
//   0x0dad7c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0dad80: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1109_0x0dad74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dad74ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x1a65a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1110 | PC: 0x0daf48 | FDE: 0x1a65f8 | Size: 256 bytes
// Khung tháo gỡ #1110 | Địa chỉ PC: 0x0daf48 | Địa chỉ FDE: 0x1a65f8 | Kích thước: 256 bytes
//   0x0daf48: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0daf4c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0daf50: 910043FD  add      x29, sp, #0x10
//   0x0daf54: A9007C7F  stp      xzr, xzr, [x3]
static inline uint64_t fde_func_1110_0x0daf48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0daf48ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a65f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1111 | PC: 0x0db104 | FDE: 0x1a6640 | Size: 256 bytes
// Khung tháo gỡ #1111 | Địa chỉ PC: 0x0db104 | Địa chỉ FDE: 0x1a6640 | Kích thước: 256 bytes
//   0x0db104: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0db108: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0db10c: 910043FD  add      x29, sp, #0x10
//   0x0db110: 39400008  ldrb     w8, [x0]
static inline uint64_t fde_func_1111_0x0db104(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db104ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a6640ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1112 | PC: 0x0db3b0 | FDE: 0x1a6690 | Size: 256 bytes
// Khung tháo gỡ #1112 | Địa chỉ PC: 0x0db3b0 | Địa chỉ FDE: 0x1a6690 | Kích thước: 256 bytes
//   0x0db3b0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0db3b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0db3b8: 910043FD  add      x29, sp, #0x10
//   0x0db3bc: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1112_0x0db3b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db3b0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a6690ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1113 | PC: 0x0db4e4 | FDE: 0x1a66d0 | Size: 256 bytes
// Khung tháo gỡ #1113 | Địa chỉ PC: 0x0db4e4 | Địa chỉ FDE: 0x1a66d0 | Kích thước: 256 bytes
//   0x0db4e4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0db4e8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0db4ec: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0db4f0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1113_0x0db4e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db4e4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1a66d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1114 | PC: 0x0db618 | FDE: 0x1a6718 | Size: 164 bytes
// Khung tháo gỡ #1114 | Địa chỉ PC: 0x0db618 | Địa chỉ FDE: 0x1a6718 | Kích thước: 164 bytes
//   0x0db618: B4000261  cbz      x1, #0xdb664
//   0x0db61c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0db620: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0db624: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1114_0x0db618(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db618ULL ^ (static_cast<uint64_t>(0xb4000261ULL) << 13);
    acc = (acc + a1 + 0xa9be4ff4ULL) ^ 0x1a6718ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1115 | PC: 0x0db6bc | FDE: 0x1a6758 | Size: 256 bytes
// Khung tháo gỡ #1115 | Địa chỉ PC: 0x0db6bc | Địa chỉ FDE: 0x1a6758 | Kích thước: 256 bytes
//   0x0db6bc: D10183FF  sub      sp, sp, #0x60
//   0x0db6c0: F90013F7  str      x23, [sp, #0x20]
//   0x0db6c4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0db6c8: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1115_0x0db6bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db6bcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1a6758ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1116 | PC: 0x0dba40 | FDE: 0x1a67b0 | Size: 256 bytes
// Khung tháo gỡ #1116 | Địa chỉ PC: 0x0dba40 | Địa chỉ FDE: 0x1a67b0 | Kích thước: 256 bytes
//   0x0dba40: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0dba44: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dba48: 910043FD  add      x29, sp, #0x10
//   0x0dba4c: A9007C7F  stp      xzr, xzr, [x3]
static inline uint64_t fde_func_1116_0x0dba40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dba40ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a67b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1117 | PC: 0x0dbbb8 | FDE: 0x1a6800 | Size: 256 bytes
// Khung tháo gỡ #1117 | Địa chỉ PC: 0x0dbbb8 | Địa chỉ FDE: 0x1a6800 | Kích thước: 256 bytes
//   0x0dbbb8: D10183FF  sub      sp, sp, #0x60
//   0x0dbbbc: F9001BF5  str      x21, [sp, #0x30]
//   0x0dbbc0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0dbbc4: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1117_0x0dbbb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dbbb8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x1a6800ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1118 | PC: 0x0dbd84 | FDE: 0x1a6840 | Size: 188 bytes
// Khung tháo gỡ #1118 | Địa chỉ PC: 0x0dbd84 | Địa chỉ FDE: 0x1a6840 | Kích thước: 188 bytes
//   0x0dbd84: A9402808  ldp      x8, x10, [x0]
//   0x0dbd88: EB08015F  cmp      x10, x8
//   0x0dbd8c: 54000220  b.eq     #0xdbdd0
//   0x0dbd90: F9400429  ldr      x9, [x1, #8]
static inline uint64_t fde_func_1118_0x0dbd84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dbd84ULL ^ (static_cast<uint64_t>(0xa9402808ULL) << 13);
    acc = (acc + a1 + 0xeb08015fULL) ^ 0x1a6840ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1119 | PC: 0x0dbe40 | FDE: 0x1a6878 | Size: 256 bytes
// Khung tháo gỡ #1119 | Địa chỉ PC: 0x0dbe40 | Địa chỉ FDE: 0x1a6878 | Kích thước: 256 bytes
//   0x0dbe40: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0dbe44: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dbe48: 910043FD  add      x29, sp, #0x10
//   0x0dbe4c: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_1119_0x0dbe40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dbe40ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a6878ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1120 | PC: 0x0dbfb8 | FDE: 0x1a68c0 | Size: 256 bytes
// Khung tháo gỡ #1120 | Địa chỉ PC: 0x0dbfb8 | Địa chỉ FDE: 0x1a68c0 | Kích thước: 256 bytes
//   0x0dbfb8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0dbfbc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0dbfc0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0dbfc4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1120_0x0dbfb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dbfb8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1a68c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1121 | PC: 0x0dc17c | FDE: 0x1a6900 | Size: 256 bytes
// Khung tháo gỡ #1121 | Địa chỉ PC: 0x0dc17c | Địa chỉ FDE: 0x1a6900 | Kích thước: 256 bytes
//   0x0dc17c: D10283FF  sub      sp, sp, #0xa0
//   0x0dc180: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x0dc184: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0dc188: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1121_0x0dc17c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc17cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x1a6900ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1122 | PC: 0x0dc4c8 | FDE: 0x1a6950 | Size: 256 bytes
// Khung tháo gỡ #1122 | Địa chỉ PC: 0x0dc4c8 | Địa chỉ FDE: 0x1a6950 | Kích thước: 256 bytes
//   0x0dc4c8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0dc4cc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0dc4d0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0dc4d4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1122_0x0dc4c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc4c8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1a6950ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1123 | PC: 0x0dc7c4 | FDE: 0x1a69a0 | Size: 256 bytes
// Khung tháo gỡ #1123 | Địa chỉ PC: 0x0dc7c4 | Địa chỉ FDE: 0x1a69a0 | Kích thước: 256 bytes
//   0x0dc7c4: D102C3FF  sub      sp, sp, #0xb0
//   0x0dc7c8: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x0dc7cc: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0dc7d0: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_1123_0x0dc7c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc7c4ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x1a69a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1124 | PC: 0x0dcb18 | FDE: 0x1a69f0 | Size: 112 bytes
// Khung tháo gỡ #1124 | Địa chỉ PC: 0x0dcb18 | Địa chỉ FDE: 0x1a69f0 | Kích thước: 112 bytes
//   0x0dcb18: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0dcb1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dcb20: 910043FD  add      x29, sp, #0x10
//   0x0dcb24: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_1124_0x0dcb18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dcb18ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a69f0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1125 | PC: 0x0dcb88 | FDE: 0x1a6a30 | Size: 160 bytes
// Khung tháo gỡ #1125 | Địa chỉ PC: 0x0dcb88 | Địa chỉ FDE: 0x1a6a30 | Kích thước: 160 bytes
//   0x0dcb88: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0dcb8c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dcb90: 910043FD  add      x29, sp, #0x10
//   0x0dcb94: 340001A1  cbz      w1, #0xdcbc8
static inline uint64_t fde_func_1125_0x0dcb88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dcb88ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a6a30ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1126 | PC: 0x0dcc28 | FDE: 0x1a6a70 | Size: 196 bytes
// Khung tháo gỡ #1126 | Địa chỉ PC: 0x0dcc28 | Địa chỉ FDE: 0x1a6a70 | Kích thước: 196 bytes
//   0x0dcc28: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0dcc2c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dcc30: 910043FD  add      x29, sp, #0x10
//   0x0dcc34: B201F3E8  mov      x8, #-0x5555555555555556
static inline uint64_t fde_func_1126_0x0dcc28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dcc28ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a6a70ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1127 | PC: 0x0dccec | FDE: 0x1a6ab0 | Size: 232 bytes
// Khung tháo gỡ #1127 | Địa chỉ PC: 0x0dccec | Địa chỉ FDE: 0x1a6ab0 | Kích thước: 232 bytes
//   0x0dccec: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0dccf0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0dccf4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0dccf8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1127_0x0dccec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dccecULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1a6ab0ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1128 | PC: 0x0dcdd4 | FDE: 0x1a6af8 | Size: 196 bytes
// Khung tháo gỡ #1128 | Địa chỉ PC: 0x0dcdd4 | Địa chỉ FDE: 0x1a6af8 | Kích thước: 196 bytes
//   0x0dcdd4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0dcdd8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dcddc: 910043FD  add      x29, sp, #0x10
//   0x0dcde0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1128_0x0dcdd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dcdd4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a6af8ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1129 | PC: 0x0dce98 | FDE: 0x1a6b38 | Size: 256 bytes
// Khung tháo gỡ #1129 | Địa chỉ PC: 0x0dce98 | Địa chỉ FDE: 0x1a6b38 | Kích thước: 256 bytes
//   0x0dce98: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0dce9c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dcea0: 910043FD  add      x29, sp, #0x10
//   0x0dcea4: B9400028  ldr      w8, [x1]
static inline uint64_t fde_func_1129_0x0dce98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dce98ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a6b38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1130 | PC: 0x0dd038 | FDE: 0x1a6b80 | Size: 124 bytes
// Khung tháo gỡ #1130 | Địa chỉ PC: 0x0dd038 | Địa chỉ FDE: 0x1a6b80 | Kích thước: 124 bytes
//   0x0dd038: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0dd03c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dd040: 910043FD  add      x29, sp, #0x10
//   0x0dd044: B7F80161  tbnz     x1, #0x3f, #0xdd070
static inline uint64_t fde_func_1130_0x0dd038(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd038ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a6b80ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1131 | PC: 0x0dd0b4 | FDE: 0x1a6bc0 | Size: 104 bytes
// Khung tháo gỡ #1131 | Địa chỉ PC: 0x0dd0b4 | Địa chỉ FDE: 0x1a6bc0 | Kích thước: 104 bytes
//   0x0dd0b4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0dd0b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dd0bc: 910043FD  add      x29, sp, #0x10
//   0x0dd0c0: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1131_0x0dd0b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd0b4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a6bc0ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1132 | PC: 0x0dd11c | FDE: 0x1a6bf8 | Size: 256 bytes
// Khung tháo gỡ #1132 | Địa chỉ PC: 0x0dd11c | Địa chỉ FDE: 0x1a6bf8 | Kích thước: 256 bytes
//   0x0dd11c: D10183FF  sub      sp, sp, #0x60
//   0x0dd120: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0dd124: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0dd128: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1132_0x0dd11c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd11cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1a6bf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1133 | PC: 0x0dd318 | FDE: 0x1a6c48 | Size: 256 bytes
// Khung tháo gỡ #1133 | Địa chỉ PC: 0x0dd318 | Địa chỉ FDE: 0x1a6c48 | Kích thước: 256 bytes
//   0x0dd318: D101C3FF  sub      sp, sp, #0x70
//   0x0dd31c: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0dd320: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0dd324: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1133_0x0dd318(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd318ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x1a6c48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1134 | PC: 0x0dd488 | FDE: 0x1a6c90 | Size: 256 bytes
// Khung tháo gỡ #1134 | Địa chỉ PC: 0x0dd488 | Địa chỉ FDE: 0x1a6c90 | Kích thước: 256 bytes
//   0x0dd488: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0dd48c: 910003FD  mov      x29, sp
//   0x0dd490: B5000201  cbnz     x1, #0xdd4d0
//   0x0dd494: B9408809  ldr      w9, [x0, #0x88]
static inline uint64_t fde_func_1134_0x0dd488(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd488ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a6c90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1135 | PC: 0x0dd5a4 | FDE: 0x1a6cd0 | Size: 144 bytes
// Khung tháo gỡ #1135 | Địa chỉ PC: 0x0dd5a4 | Địa chỉ FDE: 0x1a6cd0 | Kích thước: 144 bytes
//   0x0dd5a4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0dd5a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dd5ac: 910043FD  add      x29, sp, #0x10
//   0x0dd5b0: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1135_0x0dd5a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd5a4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a6cd0ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1136 | PC: 0x0dd634 | FDE: 0x1a6d10 | Size: 156 bytes
// Khung tháo gỡ #1136 | Địa chỉ PC: 0x0dd634 | Địa chỉ FDE: 0x1a6d10 | Kích thước: 156 bytes
//   0x0dd634: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0dd638: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dd63c: 910043FD  add      x29, sp, #0x10
//   0x0dd640: B940B408  ldr      w8, [x0, #0xb4]
static inline uint64_t fde_func_1136_0x0dd634(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd634ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a6d10ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1137 | PC: 0x0dd6d0 | FDE: 0x1a6d50 | Size: 160 bytes
// Khung tháo gỡ #1137 | Địa chỉ PC: 0x0dd6d0 | Địa chỉ FDE: 0x1a6d50 | Kích thước: 160 bytes
//   0x0dd6d0: B4000221  cbz      x1, #0xdd714
//   0x0dd6d4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0dd6d8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dd6dc: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1137_0x0dd6d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd6d0ULL ^ (static_cast<uint64_t>(0xb4000221ULL) << 13);
    acc = (acc + a1 + 0xa9be4ff4ULL) ^ 0x1a6d50ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1138 | PC: 0x0dd770 | FDE: 0x1a6d90 | Size: 256 bytes
// Khung tháo gỡ #1138 | Địa chỉ PC: 0x0dd770 | Địa chỉ FDE: 0x1a6d90 | Kích thước: 256 bytes
//   0x0dd770: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0dd774: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dd778: 910043FD  add      x29, sp, #0x10
//   0x0dd77c: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1138_0x0dd770(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd770ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a6d90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1139 | PC: 0x0dd9e0 | FDE: 0x1a6de0 | Size: 256 bytes
// Khung tháo gỡ #1139 | Địa chỉ PC: 0x0dd9e0 | Địa chỉ FDE: 0x1a6de0 | Kích thước: 256 bytes
//   0x0dd9e0: D101C3FF  sub      sp, sp, #0x70
//   0x0dd9e4: F90013F9  str      x25, [sp, #0x20]
//   0x0dd9e8: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0dd9ec: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1139_0x0dd9e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd9e0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x1a6de0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1140 | PC: 0x0ddb58 | FDE: 0x1a6e28 | Size: 116 bytes
// Khung tháo gỡ #1140 | Địa chỉ PC: 0x0ddb58 | Địa chỉ FDE: 0x1a6e28 | Kích thước: 116 bytes
//   0x0ddb58: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ddb5c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ddb60: 910043FD  add      x29, sp, #0x10
//   0x0ddb64: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1140_0x0ddb58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddb58ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a6e28ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1141 | PC: 0x0ddbcc | FDE: 0x1a6e68 | Size: 64 bytes
// Khung tháo gỡ #1141 | Địa chỉ PC: 0x0ddbcc | Địa chỉ FDE: 0x1a6e68 | Kích thước: 64 bytes
//   0x0ddbcc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ddbd0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ddbd4: 910043FD  add      x29, sp, #0x10
//   0x0ddbd8: B0000748  adrp     x8, #0x1c6000
static inline uint64_t fde_func_1141_0x0ddbcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddbccULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a6e68ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1142 | PC: 0x0ddc0c | FDE: 0x1a6ea0 | Size: 148 bytes
// Khung tháo gỡ #1142 | Địa chỉ PC: 0x0ddc0c | Địa chỉ FDE: 0x1a6ea0 | Kích thước: 148 bytes
//   0x0ddc0c: 17FD4121  b        #0x2e090
//   0x0ddc10: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ddc14: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ddc18: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1142_0x0ddc0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddc0cULL ^ (static_cast<uint64_t>(0x17fd4121ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x1a6ea0ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1143 | PC: 0x0ddca0 | FDE: 0x1a6ed8 | Size: 164 bytes
// Khung tháo gỡ #1143 | Địa chỉ PC: 0x0ddca0 | Địa chỉ FDE: 0x1a6ed8 | Kích thước: 164 bytes
//   0x0ddca0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ddca4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ddca8: 910043FD  add      x29, sp, #0x10
//   0x0ddcac: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_1143_0x0ddca0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddca0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a6ed8ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1144 | PC: 0x0ddd44 | FDE: 0x1a6f18 | Size: 252 bytes
// Khung tháo gỡ #1144 | Địa chỉ PC: 0x0ddd44 | Địa chỉ FDE: 0x1a6f18 | Kích thước: 252 bytes
//   0x0ddd44: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ddd48: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ddd4c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ddd50: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1144_0x0ddd44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddd44ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1a6f18ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1145 | PC: 0x0dde40 | FDE: 0x1a6f60 | Size: 152 bytes
// Khung tháo gỡ #1145 | Địa chỉ PC: 0x0dde40 | Địa chỉ FDE: 0x1a6f60 | Kích thước: 152 bytes
//   0x0dde40: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0dde44: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dde48: 910043FD  add      x29, sp, #0x10
//   0x0dde4c: F9400428  ldr      x8, [x1, #8]
static inline uint64_t fde_func_1145_0x0dde40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dde40ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a6f60ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1146 | PC: 0x0dded8 | FDE: 0x1a6f98 | Size: 256 bytes
// Khung tháo gỡ #1146 | Địa chỉ PC: 0x0dded8 | Địa chỉ FDE: 0x1a6f98 | Kích thước: 256 bytes
//   0x0dded8: D10243FF  sub      sp, sp, #0x90
//   0x0ddedc: F9001BFB  str      x27, [sp, #0x30]
//   0x0ddee0: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0ddee4: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1146_0x0dded8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dded8ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfbULL) ^ 0x1a6f98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1147 | PC: 0x0de42c | FDE: 0x1a6ff8 | Size: 256 bytes
// Khung tháo gỡ #1147 | Địa chỉ PC: 0x0de42c | Địa chỉ FDE: 0x1a6ff8 | Kích thước: 256 bytes
//   0x0de42c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0de430: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0de434: 910043FD  add      x29, sp, #0x10
//   0x0de438: A9404C49  ldp      x9, x19, [x2]
static inline uint64_t fde_func_1147_0x0de42c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de42cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a6ff8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1148 | PC: 0x0de5ec | FDE: 0x1a7040 | Size: 152 bytes
// Khung tháo gỡ #1148 | Địa chỉ PC: 0x0de5ec | Địa chỉ FDE: 0x1a7040 | Kích thước: 152 bytes
//   0x0de5ec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0de5f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0de5f4: 910043FD  add      x29, sp, #0x10
//   0x0de5f8: A9007C7F  stp      xzr, xzr, [x3]
static inline uint64_t fde_func_1148_0x0de5ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de5ecULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a7040ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1149 | PC: 0x0de684 | FDE: 0x1a7080 | Size: 104 bytes
// Khung tháo gỡ #1149 | Địa chỉ PC: 0x0de684 | Địa chỉ FDE: 0x1a7080 | Kích thước: 104 bytes
//   0x0de684: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0de688: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0de68c: 910043FD  add      x29, sp, #0x10
//   0x0de690: 90000748  adrp     x8, #0x1c6000
static inline uint64_t fde_func_1149_0x0de684(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de684ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a7080ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1150 | PC: 0x0de6ec | FDE: 0x1a70c0 | Size: 12 bytes
// Khung tháo gỡ #1150 | Địa chỉ PC: 0x0de6ec | Địa chỉ FDE: 0x1a70c0 | Kích thước: 12 bytes
//   0x0de6ec: 91006000  add      x0, x0, #0x18
//   0x0de6f0: 17FFEC0D  b        #0xd9724
//   0x0de6f4: 17FD3E67  b        #0x2e090
static inline uint64_t fde_func_1150_0x0de6ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de6ecULL ^ (static_cast<uint64_t>(0x91006000ULL) << 13);
    acc = (acc + a1 + 0x17ffec0dULL) ^ 0x1a70c0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1151 | PC: 0x0de6f8 | FDE: 0x1a70f0 | Size: 256 bytes
// Khung tháo gỡ #1151 | Địa chỉ PC: 0x0de6f8 | Địa chỉ FDE: 0x1a70f0 | Kích thước: 256 bytes
//   0x0de6f8: D10443FF  sub      sp, sp, #0x110
//   0x0de6fc: A90F4FFC  stp      x28, x19, [sp, #0xf0]
//   0x0de700: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x0de704: 910403FD  add      x29, sp, #0x100
static inline uint64_t fde_func_1151_0x0de6f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de6f8ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90f4ffcULL) ^ 0x1a70f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1152 | PC: 0x0de95c | FDE: 0x1a7138 | Size: 256 bytes
// Khung tháo gỡ #1152 | Địa chỉ PC: 0x0de95c | Địa chỉ FDE: 0x1a7138 | Kích thước: 256 bytes
//   0x0de95c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0de960: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0de964: 910043FD  add      x29, sp, #0x10
//   0x0de968: F9400428  ldr      x8, [x1, #8]
static inline uint64_t fde_func_1152_0x0de95c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de95cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a7138ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1153 | PC: 0x0dea70 | FDE: 0x1a7178 | Size: 256 bytes
// Khung tháo gỡ #1153 | Địa chỉ PC: 0x0dea70 | Địa chỉ FDE: 0x1a7178 | Kích thước: 256 bytes
//   0x0dea70: D10303FF  sub      sp, sp, #0xc0
//   0x0dea74: F90033FB  str      x27, [sp, #0x60]
//   0x0dea78: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x0dea7c: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_1153_0x0dea70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dea70ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90033fbULL) ^ 0x1a7178ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1154 | PC: 0x0dee3c | FDE: 0x1a71d0 | Size: 256 bytes
// Khung tháo gỡ #1154 | Địa chỉ PC: 0x0dee3c | Địa chỉ FDE: 0x1a71d0 | Kích thước: 256 bytes
//   0x0dee3c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0dee40: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0dee44: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0dee48: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1154_0x0dee3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dee3cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1a71d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1155 | PC: 0x0df028 | FDE: 0x1a7228 | Size: 256 bytes
// Khung tháo gỡ #1155 | Địa chỉ PC: 0x0df028 | Địa chỉ FDE: 0x1a7228 | Kích thước: 256 bytes
//   0x0df028: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0df02c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0df030: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0df034: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1155_0x0df028(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df028ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1a7228ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1156 | PC: 0x0df320 | FDE: 0x1a7280 | Size: 256 bytes
// Khung tháo gỡ #1156 | Địa chỉ PC: 0x0df320 | Địa chỉ FDE: 0x1a7280 | Kích thước: 256 bytes
//   0x0df320: D10203FF  sub      sp, sp, #0x80
//   0x0df324: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0df328: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0df32c: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1156_0x0df320(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df320ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1a7280ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1157 | PC: 0x0df644 | FDE: 0x1a72c8 | Size: 16 bytes
// Khung tháo gỡ #1157 | Địa chỉ PC: 0x0df644 | Địa chỉ FDE: 0x1a72c8 | Kích thước: 16 bytes
//   0x0df644: B81F0001  stur     w1, [x0, #-0x10]
//   0x0df648: D65F03C0  ret      
//   0x0df64c: F85F8000  ldur     x0, [x0, #-8]
//   0x0df650: D65F03C0  ret      
static inline uint64_t fde_func_1157_0x0df644(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df644ULL ^ (static_cast<uint64_t>(0xb81f0001ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1a72c8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1158 | PC: 0x0df654 | FDE: 0x1a72f8 | Size: 256 bytes
// Khung tháo gỡ #1158 | Địa chỉ PC: 0x0df654 | Địa chỉ FDE: 0x1a72f8 | Kích thước: 256 bytes
//   0x0df654: F81F8001  stur     x1, [x0, #-8]
//   0x0df658: D65F03C0  ret      
//   0x0df65c: D10143FF  sub      sp, sp, #0x50
//   0x0df660: A9015FF8  stp      x24, x23, [sp, #0x10]
static inline uint64_t fde_func_1158_0x0df654(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df654ULL ^ (static_cast<uint64_t>(0xf81f8001ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1a72f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1159 | PC: 0x0df85c | FDE: 0x1a7338 | Size: 80 bytes
// Khung tháo gỡ #1159 | Địa chỉ PC: 0x0df85c | Địa chỉ FDE: 0x1a7338 | Kích thước: 80 bytes
//   0x0df85c: F9400808  ldr      x8, [x0, #0x10]
//   0x0df860: F9400009  ldr      x9, [x0]
//   0x0df864: B940090A  ldr      w10, [x8, #8]
//   0x0df868: B9412129  ldr      w9, [x9, #0x120]
static inline uint64_t fde_func_1159_0x0df85c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df85cULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xf9400009ULL) ^ 0x1a7338ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1160 | PC: 0x0df8ac | FDE: 0x1a7368 | Size: 116 bytes
// Khung tháo gỡ #1160 | Địa chỉ PC: 0x0df8ac | Địa chỉ FDE: 0x1a7368 | Kích thước: 116 bytes
//   0x0df8ac: F9400409  ldr      x9, [x0, #8]
//   0x0df8b0: B89F002A  ldursw   x10, [x1, #-0x10]
//   0x0df8b4: CB234C28  sub      x8, x1, w3, uxtw #3
//   0x0df8b8: F82A7909  str      x9, [x8, x10, lsl #3]
static inline uint64_t fde_func_1160_0x0df8ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df8acULL ^ (static_cast<uint64_t>(0xf9400409ULL) << 13);
    acc = (acc + a1 + 0xb89f002aULL) ^ 0x1a7368ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1161 | PC: 0x0df920 | FDE: 0x1a7398 | Size: 80 bytes
// Khung tháo gỡ #1161 | Địa chỉ PC: 0x0df920 | Địa chỉ FDE: 0x1a7398 | Kích thước: 80 bytes
//   0x0df920: F9400848  ldr      x8, [x2, #0x10]
//   0x0df924: F9400049  ldr      x9, [x2]
//   0x0df928: B940090A  ldr      w10, [x8, #8]
//   0x0df92c: B9412129  ldr      w9, [x9, #0x120]
static inline uint64_t fde_func_1161_0x0df920(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df920ULL ^ (static_cast<uint64_t>(0xf9400848ULL) << 13);
    acc = (acc + a1 + 0xf9400049ULL) ^ 0x1a7398ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1162 | PC: 0x0df970 | FDE: 0x1a73c8 | Size: 256 bytes
// Khung tháo gỡ #1162 | Địa chỉ PC: 0x0df970 | Địa chỉ FDE: 0x1a73c8 | Kích thước: 256 bytes
//   0x0df970: 39400028  ldrb     w8, [x1]
//   0x0df974: 370002C8  tbnz     w8, #0, #0xdf9cc
//   0x0df978: AA1F03E8  mov      x8, xzr
//   0x0df97c: 79407429  ldrh     w9, [x1, #0x3a]
static inline uint64_t fde_func_1162_0x0df970(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df970ULL ^ (static_cast<uint64_t>(0x39400028ULL) << 13);
    acc = (acc + a1 + 0x370002c8ULL) ^ 0x1a73c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1163 | PC: 0x0dfcd8 | FDE: 0x1a7410 | Size: 256 bytes
// Khung tháo gỡ #1163 | Địa chỉ PC: 0x0dfcd8 | Địa chỉ FDE: 0x1a7410 | Kích thước: 256 bytes
//   0x0dfcd8: D10203FF  sub      sp, sp, #0x80
//   0x0dfcdc: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0dfce0: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0dfce4: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1163_0x0dfcd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dfcd8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1a7410ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1164 | PC: 0x0e0298 | FDE: 0x1a7470 | Size: 256 bytes
// Khung tháo gỡ #1164 | Địa chỉ PC: 0x0e0298 | Địa chỉ FDE: 0x1a7470 | Kích thước: 256 bytes
//   0x0e0298: D10203FF  sub      sp, sp, #0x80
//   0x0e029c: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0e02a0: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0e02a4: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1164_0x0e0298(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e0298ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1a7470ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1165 | PC: 0x0e0778 | FDE: 0x1a74d0 | Size: 256 bytes
// Khung tháo gỡ #1165 | Địa chỉ PC: 0x0e0778 | Địa chỉ FDE: 0x1a74d0 | Kích thước: 256 bytes
//   0x0e0778: D101C3FF  sub      sp, sp, #0x70
//   0x0e077c: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0e0780: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0e0784: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1165_0x0e0778(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e0778ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x1a74d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1166 | PC: 0x0e0bcc | FDE: 0x1a7530 | Size: 256 bytes
// Khung tháo gỡ #1166 | Địa chỉ PC: 0x0e0bcc | Địa chỉ FDE: 0x1a7530 | Kích thước: 256 bytes
//   0x0e0bcc: D101C3FF  sub      sp, sp, #0x70
//   0x0e0bd0: F9000BFB  str      x27, [sp, #0x10]
//   0x0e0bd4: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0e0bd8: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1166_0x0e0bcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e0bccULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfbULL) ^ 0x1a7530ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1167 | PC: 0x0e0ee0 | FDE: 0x1a7588 | Size: 256 bytes
// Khung tháo gỡ #1167 | Địa chỉ PC: 0x0e0ee0 | Địa chỉ FDE: 0x1a7588 | Kích thước: 256 bytes
//   0x0e0ee0: D10143FF  sub      sp, sp, #0x50
//   0x0e0ee4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0e0ee8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0e0eec: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1167_0x0e0ee0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e0ee0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1a7588ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1168 | PC: 0x0e1058 | FDE: 0x1a75d8 | Size: 256 bytes
// Khung tháo gỡ #1168 | Địa chỉ PC: 0x0e1058 | Địa chỉ FDE: 0x1a75d8 | Kích thước: 256 bytes
//   0x0e1058: D10143FF  sub      sp, sp, #0x50
//   0x0e105c: A9017FF7  stp      x23, xzr, [sp, #0x10]
//   0x0e1060: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0e1064: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1168_0x0e1058(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1058ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9017ff7ULL) ^ 0x1a75d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1169 | PC: 0x0e115c | FDE: 0x1a7618 | Size: 256 bytes
// Khung tháo gỡ #1169 | Địa chỉ PC: 0x0e115c | Địa chỉ FDE: 0x1a7618 | Kích thước: 256 bytes
//   0x0e115c: D10283FF  sub      sp, sp, #0xa0
//   0x0e1160: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x0e1164: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0e1168: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1169_0x0e115c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e115cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x1a7618ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1170 | PC: 0x0e1d30 | FDE: 0x1a7678 | Size: 256 bytes
// Khung tháo gỡ #1170 | Địa chỉ PC: 0x0e1d30 | Địa chỉ FDE: 0x1a7678 | Kích thước: 256 bytes
//   0x0e1d30: D10283FF  sub      sp, sp, #0xa0
//   0x0e1d34: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x0e1d38: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0e1d3c: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1170_0x0e1d30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1d30ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x1a7678ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1171 | PC: 0x0e2908 | FDE: 0x1a76d8 | Size: 256 bytes
// Khung tháo gỡ #1171 | Địa chỉ PC: 0x0e2908 | Địa chỉ FDE: 0x1a76d8 | Kích thước: 256 bytes
//   0x0e2908: D10283FF  sub      sp, sp, #0xa0
//   0x0e290c: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x0e2910: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0e2914: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1171_0x0e2908(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2908ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x1a76d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1172 | PC: 0x0e34e4 | FDE: 0x1a7738 | Size: 256 bytes
// Khung tháo gỡ #1172 | Địa chỉ PC: 0x0e34e4 | Địa chỉ FDE: 0x1a7738 | Kích thước: 256 bytes
//   0x0e34e4: D10283FF  sub      sp, sp, #0xa0
//   0x0e34e8: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x0e34ec: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0e34f0: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1172_0x0e34e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e34e4ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x1a7738ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1173 | PC: 0x0e40c0 | FDE: 0x1a7798 | Size: 56 bytes
// Khung tháo gỡ #1173 | Địa chỉ PC: 0x0e40c0 | Địa chỉ FDE: 0x1a7798 | Kích thước: 56 bytes
//   0x0e40c0: F9400408  ldr      x8, [x0, #8]
//   0x0e40c4: D000070A  adrp     x10, #0x1c6000
//   0x0e40c8: 9120C14A  add      x10, x10, #0x830
//   0x0e40cc: 79401509  ldrh     w9, [x8, #0xa]
static inline uint64_t fde_func_1173_0x0e40c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e40c0ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xd000070aULL) ^ 0x1a7798ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1174 | PC: 0x0e40f8 | FDE: 0x1a77c8 | Size: 56 bytes
// Khung tháo gỡ #1174 | Địa chỉ PC: 0x0e40f8 | Địa chỉ FDE: 0x1a77c8 | Kích thước: 56 bytes
//   0x0e40f8: B9800808  ldrsw    x8, [x0, #8]
//   0x0e40fc: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e4100: D37DF108  lsl      x8, x8, #3
//   0x0e4104: B8686828  ldr      w8, [x1, x8]
static inline uint64_t fde_func_1174_0x0e40f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e40f8ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a77c8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1175 | PC: 0x0e4130 | FDE: 0x1a77f8 | Size: 60 bytes
// Khung tháo gỡ #1175 | Địa chỉ PC: 0x0e4130 | Địa chỉ FDE: 0x1a77f8 | Kích thước: 60 bytes
//   0x0e4130: B9800808  ldrsw    x8, [x0, #8]
//   0x0e4134: FC687820  ldr      d0, [x1, x8, lsl #3]
//   0x0e4138: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e413c: 1E60C000  fabs     d0, d0
static inline uint64_t fde_func_1175_0x0e4130(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4130ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xfc687820ULL) ^ 0x1a77f8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1176 | PC: 0x0e416c | FDE: 0x1a7828 | Size: 56 bytes
// Khung tháo gỡ #1176 | Địa chỉ PC: 0x0e416c | Địa chỉ FDE: 0x1a7828 | Kích thước: 56 bytes
//   0x0e416c: B9400808  ldr      w8, [x0, #8]
//   0x0e4170: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e4174: 52010108  eor      w8, w8, #0x80000000
//   0x0e4178: F8297828  str      x8, [x1, x9, lsl #3]
static inline uint64_t fde_func_1176_0x0e416c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e416cULL ^ (static_cast<uint64_t>(0xb9400808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a7828ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1177 | PC: 0x0e41a4 | FDE: 0x1a7858 | Size: 52 bytes
// Khung tháo gỡ #1177 | Địa chỉ PC: 0x0e41a4 | Địa chỉ FDE: 0x1a7858 | Kích thước: 52 bytes
//   0x0e41a4: FD400400  ldr      d0, [x0, #8]
//   0x0e41a8: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e41ac: 1E614000  fneg     d0, d0
//   0x0e41b0: FC287820  str      d0, [x1, x8, lsl #3]
static inline uint64_t fde_func_1177_0x0e41a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e41a4ULL ^ (static_cast<uint64_t>(0xfd400400ULL) << 13);
    acc = (acc + a1 + 0xb9801008ULL) ^ 0x1a7858ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1178 | PC: 0x0e41d8 | FDE: 0x1a7888 | Size: 140 bytes
// Khung tháo gỡ #1178 | Địa chỉ PC: 0x0e41d8 | Địa chỉ FDE: 0x1a7888 | Kích thước: 140 bytes
//   0x0e41d8: F9400408  ldr      x8, [x0, #8]
//   0x0e41dc: D000070A  adrp     x10, #0x1c6000
//   0x0e41e0: 9122C14A  add      x10, x10, #0x8b0
//   0x0e41e4: 79401509  ldrh     w9, [x8, #0xa]
static inline uint64_t fde_func_1178_0x0e41d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e41d8ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xd000070aULL) ^ 0x1a7888ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1179 | PC: 0x0e4264 | FDE: 0x1a78b8 | Size: 236 bytes
// Khung tháo gỡ #1179 | Địa chỉ PC: 0x0e4264 | Địa chỉ FDE: 0x1a78b8 | Kích thước: 236 bytes
//   0x0e4264: B9800808  ldrsw    x8, [x0, #8]
//   0x0e4268: D37DF108  lsl      x8, x8, #3
//   0x0e426c: B8686828  ldr      w8, [x1, x8]
//   0x0e4270: 340002A8  cbz      w8, #0xe42c4
static inline uint64_t fde_func_1179_0x0e4264(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4264ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xd37df108ULL) ^ 0x1a78b8ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #1180 | PC: 0x0e4350 | FDE: 0x1a78e8 | Size: 156 bytes
// Khung tháo gỡ #1180 | Địa chỉ PC: 0x0e4350 | Địa chỉ FDE: 0x1a78e8 | Kích thước: 156 bytes
//   0x0e4350: B9800808  ldrsw    x8, [x0, #8]
//   0x0e4354: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0e4358: B4000308  cbz      x8, #0xe43b8
//   0x0e435c: CB0803E9  neg      x9, x8
static inline uint64_t fde_func_1180_0x0e4350(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4350ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf8687828ULL) ^ 0x1a78e8ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1181 | PC: 0x0e43ec | FDE: 0x1a7918 | Size: 216 bytes
// Khung tháo gỡ #1181 | Địa chỉ PC: 0x0e43ec | Địa chỉ FDE: 0x1a7918 | Kích thước: 216 bytes
//   0x0e43ec: B9400808  ldr      w8, [x0, #8]
//   0x0e43f0: 34000288  cbz      w8, #0xe4440
//   0x0e43f4: 4B0803E9  neg      w9, w8
//   0x0e43f8: 0A090108  and      w8, w8, w9
static inline uint64_t fde_func_1181_0x0e43ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e43ecULL ^ (static_cast<uint64_t>(0xb9400808ULL) << 13);
    acc = (acc + a1 + 0x34000288ULL) ^ 0x1a7918ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1182 | PC: 0x0e44c4 | FDE: 0x1a7948 | Size: 236 bytes
// Khung tháo gỡ #1182 | Địa chỉ PC: 0x0e44c4 | Địa chỉ FDE: 0x1a7948 | Kích thước: 236 bytes
//   0x0e44c4: F9400408  ldr      x8, [x0, #8]
//   0x0e44c8: B40002E8  cbz      x8, #0xe4524
//   0x0e44cc: CB0803E9  neg      x9, x8
//   0x0e44d0: 8A090108  and      x8, x8, x9
static inline uint64_t fde_func_1182_0x0e44c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e44c4ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xb40002e8ULL) ^ 0x1a7948ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #1183 | PC: 0x0e45b0 | FDE: 0x1a7978 | Size: 68 bytes
// Khung tháo gỡ #1183 | Địa chỉ PC: 0x0e45b0 | Địa chỉ FDE: 0x1a7978 | Kích thước: 68 bytes
//   0x0e45b0: F9400408  ldr      x8, [x0, #8]
//   0x0e45b4: D000070A  adrp     x10, #0x1c6000
//   0x0e45b8: 9124C14A  add      x10, x10, #0x930
//   0x0e45bc: 79401509  ldrh     w9, [x8, #0xa]
static inline uint64_t fde_func_1183_0x0e45b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e45b0ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xd000070aULL) ^ 0x1a7978ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1184 | PC: 0x0e45f4 | FDE: 0x1a79a8 | Size: 76 bytes
// Khung tháo gỡ #1184 | Địa chỉ PC: 0x0e45f4 | Địa chỉ FDE: 0x1a79a8 | Kích thước: 76 bytes
//   0x0e45f4: B9800808  ldrsw    x8, [x0, #8]
//   0x0e45f8: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e45fc: D37DF108  lsl      x8, x8, #3
//   0x0e4600: B8686828  ldr      w8, [x1, x8]
static inline uint64_t fde_func_1184_0x0e45f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e45f4ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a79a8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1185 | PC: 0x0e4640 | FDE: 0x1a79d8 | Size: 68 bytes
// Khung tháo gỡ #1185 | Địa chỉ PC: 0x0e4640 | Địa chỉ FDE: 0x1a79d8 | Kích thước: 68 bytes
//   0x0e4640: B9800808  ldrsw    x8, [x0, #8]
//   0x0e4644: FC687820  ldr      d0, [x1, x8, lsl #3]
//   0x0e4648: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e464c: 0E205800  cnt      v0.8b, v0.8b
static inline uint64_t fde_func_1185_0x0e4640(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4640ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xfc687820ULL) ^ 0x1a79d8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1186 | PC: 0x0e4684 | FDE: 0x1a7a08 | Size: 64 bytes
// Khung tháo gỡ #1186 | Địa chỉ PC: 0x0e4684 | Địa chỉ FDE: 0x1a7a08 | Kích thước: 64 bytes
//   0x0e4684: BD400800  ldr      s0, [x0, #8]
//   0x0e4688: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e468c: 1E24C000  frintp   s0, s0
//   0x0e4690: 1E260009  fmov     w9, s0
static inline uint64_t fde_func_1186_0x0e4684(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4684ULL ^ (static_cast<uint64_t>(0xbd400800ULL) << 13);
    acc = (acc + a1 + 0xb9801008ULL) ^ 0x1a7a08ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1187 | PC: 0x0e46c4 | FDE: 0x1a7a38 | Size: 52 bytes
// Khung tháo gỡ #1187 | Địa chỉ PC: 0x0e46c4 | Địa chỉ FDE: 0x1a7a38 | Kích thước: 52 bytes
//   0x0e46c4: FD400400  ldr      d0, [x0, #8]
//   0x0e46c8: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e46cc: 1E64C000  frintp   d0, d0
//   0x0e46d0: FC287820  str      d0, [x1, x8, lsl #3]
static inline uint64_t fde_func_1187_0x0e46c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e46c4ULL ^ (static_cast<uint64_t>(0xfd400400ULL) << 13);
    acc = (acc + a1 + 0xb9801008ULL) ^ 0x1a7a38ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1188 | PC: 0x0e46f8 | FDE: 0x1a7a68 | Size: 60 bytes
// Khung tháo gỡ #1188 | Địa chỉ PC: 0x0e46f8 | Địa chỉ FDE: 0x1a7a68 | Kích thước: 60 bytes
//   0x0e46f8: F9400408  ldr      x8, [x0, #8]
//   0x0e46fc: D000070A  adrp     x10, #0x1c6000
//   0x0e4700: 9126C14A  add      x10, x10, #0x9b0
//   0x0e4704: 79401509  ldrh     w9, [x8, #0xa]
static inline uint64_t fde_func_1188_0x0e46f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e46f8ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xd000070aULL) ^ 0x1a7a68ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1189 | PC: 0x0e4734 | FDE: 0x1a7a98 | Size: 60 bytes
// Khung tháo gỡ #1189 | Địa chỉ PC: 0x0e4734 | Địa chỉ FDE: 0x1a7a98 | Kích thước: 60 bytes
//   0x0e4734: B9800808  ldrsw    x8, [x0, #8]
//   0x0e4738: D37DF108  lsl      x8, x8, #3
//   0x0e473c: BC686820  ldr      s0, [x1, x8]
//   0x0e4740: B9801008  ldrsw    x8, [x0, #0x10]
static inline uint64_t fde_func_1189_0x0e4734(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4734ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xd37df108ULL) ^ 0x1a7a98ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1190 | PC: 0x0e4770 | FDE: 0x1a7ac8 | Size: 60 bytes
// Khung tháo gỡ #1190 | Địa chỉ PC: 0x0e4770 | Địa chỉ FDE: 0x1a7ac8 | Kích thước: 60 bytes
//   0x0e4770: B9800808  ldrsw    x8, [x0, #8]
//   0x0e4774: FC687820  ldr      d0, [x1, x8, lsl #3]
//   0x0e4778: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e477c: 1E654000  frintm   d0, d0
static inline uint64_t fde_func_1190_0x0e4770(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4770ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xfc687820ULL) ^ 0x1a7ac8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1191 | PC: 0x0e47ac | FDE: 0x1a7af8 | Size: 64 bytes
// Khung tháo gỡ #1191 | Địa chỉ PC: 0x0e47ac | Địa chỉ FDE: 0x1a7af8 | Kích thước: 64 bytes
//   0x0e47ac: BD400800  ldr      s0, [x0, #8]
//   0x0e47b0: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e47b4: 1E25C000  frintz   s0, s0
//   0x0e47b8: 1E260009  fmov     w9, s0
static inline uint64_t fde_func_1191_0x0e47ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e47acULL ^ (static_cast<uint64_t>(0xbd400800ULL) << 13);
    acc = (acc + a1 + 0xb9801008ULL) ^ 0x1a7af8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1192 | PC: 0x0e47ec | FDE: 0x1a7b28 | Size: 52 bytes
// Khung tháo gỡ #1192 | Địa chỉ PC: 0x0e47ec | Địa chỉ FDE: 0x1a7b28 | Kích thước: 52 bytes
//   0x0e47ec: FD400400  ldr      d0, [x0, #8]
//   0x0e47f0: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e47f4: 1E65C000  frintz   d0, d0
//   0x0e47f8: FC287820  str      d0, [x1, x8, lsl #3]
static inline uint64_t fde_func_1192_0x0e47ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e47ecULL ^ (static_cast<uint64_t>(0xfd400400ULL) << 13);
    acc = (acc + a1 + 0xb9801008ULL) ^ 0x1a7b28ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1193 | PC: 0x0e4820 | FDE: 0x1a7b58 | Size: 60 bytes
// Khung tháo gỡ #1193 | Địa chỉ PC: 0x0e4820 | Địa chỉ FDE: 0x1a7b58 | Kích thước: 60 bytes
//   0x0e4820: F9400408  ldr      x8, [x0, #8]
//   0x0e4824: D000070A  adrp     x10, #0x1c6000
//   0x0e4828: 9128C14A  add      x10, x10, #0xa30
//   0x0e482c: 79401509  ldrh     w9, [x8, #0xa]
static inline uint64_t fde_func_1193_0x0e4820(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4820ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xd000070aULL) ^ 0x1a7b58ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1194 | PC: 0x0e485c | FDE: 0x1a7b88 | Size: 60 bytes
// Khung tháo gỡ #1194 | Địa chỉ PC: 0x0e485c | Địa chỉ FDE: 0x1a7b88 | Kích thước: 60 bytes
//   0x0e485c: B9800808  ldrsw    x8, [x0, #8]
//   0x0e4860: D37DF108  lsl      x8, x8, #3
//   0x0e4864: BC686820  ldr      s0, [x1, x8]
//   0x0e4868: B9801008  ldrsw    x8, [x0, #0x10]
static inline uint64_t fde_func_1194_0x0e485c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e485cULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xd37df108ULL) ^ 0x1a7b88ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1195 | PC: 0x0e4898 | FDE: 0x1a7bb8 | Size: 60 bytes
// Khung tháo gỡ #1195 | Địa chỉ PC: 0x0e4898 | Địa chỉ FDE: 0x1a7bb8 | Kích thước: 60 bytes
//   0x0e4898: B9800808  ldrsw    x8, [x0, #8]
//   0x0e489c: FC687820  ldr      d0, [x1, x8, lsl #3]
//   0x0e48a0: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e48a4: 1E67C000  frinti   d0, d0
static inline uint64_t fde_func_1195_0x0e4898(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4898ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xfc687820ULL) ^ 0x1a7bb8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1196 | PC: 0x0e48d4 | FDE: 0x1a7be8 | Size: 64 bytes
// Khung tháo gỡ #1196 | Địa chỉ PC: 0x0e48d4 | Địa chỉ FDE: 0x1a7be8 | Kích thước: 64 bytes
//   0x0e48d4: BD400800  ldr      s0, [x0, #8]
//   0x0e48d8: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e48dc: 1E21C000  fsqrt    s0, s0
//   0x0e48e0: 1E260009  fmov     w9, s0
static inline uint64_t fde_func_1196_0x0e48d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e48d4ULL ^ (static_cast<uint64_t>(0xbd400800ULL) << 13);
    acc = (acc + a1 + 0xb9801008ULL) ^ 0x1a7be8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1197 | PC: 0x0e4914 | FDE: 0x1a7c18 | Size: 52 bytes
// Khung tháo gỡ #1197 | Địa chỉ PC: 0x0e4914 | Địa chỉ FDE: 0x1a7c18 | Kích thước: 52 bytes
//   0x0e4914: FD400400  ldr      d0, [x0, #8]
//   0x0e4918: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e491c: 1E61C000  fsqrt    d0, d0
//   0x0e4920: FC287820  str      d0, [x1, x8, lsl #3]
static inline uint64_t fde_func_1197_0x0e4914(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4914ULL ^ (static_cast<uint64_t>(0xfd400400ULL) << 13);
    acc = (acc + a1 + 0xb9801008ULL) ^ 0x1a7c18ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1198 | PC: 0x0e4948 | FDE: 0x1a7c48 | Size: 68 bytes
// Khung tháo gỡ #1198 | Địa chỉ PC: 0x0e4948 | Địa chỉ FDE: 0x1a7c48 | Kích thước: 68 bytes
//   0x0e4948: F9400408  ldr      x8, [x0, #8]
//   0x0e494c: D000070B  adrp     x11, #0x1c6000
//   0x0e4950: 912AC16B  add      x11, x11, #0xab0
//   0x0e4954: 79401509  ldrh     w9, [x8, #0xa]
static inline uint64_t fde_func_1198_0x0e4948(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4948ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xd000070bULL) ^ 0x1a7c48ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1199 | PC: 0x0e498c | FDE: 0x1a7c78 | Size: 72 bytes
// Khung tháo gỡ #1199 | Địa chỉ PC: 0x0e498c | Địa chỉ FDE: 0x1a7c78 | Kích thước: 72 bytes
//   0x0e498c: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e4990: B9400809  ldr      w9, [x0, #8]
//   0x0e4994: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e4998: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1199_0x0e498c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e498cULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xb9400809ULL) ^ 0x1a7c78ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// Shard 3 Dispatcher / Bộ điều phối phân mảnh 3
uint64_t execute_fde_shard_3(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 800: return fde_func_0800_0x0b0218(a0, a1);
        case 801: return fde_func_0801_0x0b0228(a0, a1);
        case 802: return fde_func_0802_0x0b0254(a0, a1);
        case 803: return fde_func_0803_0x0b0284(a0, a1);
        case 804: return fde_func_0804_0x0b02b4(a0, a1);
        case 805: return fde_func_0805_0x0b02dc(a0, a1);
        case 806: return fde_func_0806_0x0b0308(a0, a1);
        case 807: return fde_func_0807_0x0b0348(a0, a1);
        case 808: return fde_func_0808_0x0b0380(a0, a1);
        case 809: return fde_func_0809_0x0b03c8(a0, a1);
        case 810: return fde_func_0810_0x0b040c(a0, a1);
        case 811: return fde_func_0811_0x0b044c(a0, a1);
        case 812: return fde_func_0812_0x0b0484(a0, a1);
        case 813: return fde_func_0813_0x0b04c0(a0, a1);
        case 814: return fde_func_0814_0x0b04f4(a0, a1);
        case 815: return fde_func_0815_0x0b0518(a0, a1);
        case 816: return fde_func_0816_0x0b0538(a0, a1);
        case 817: return fde_func_0817_0x0b057c(a0, a1);
        case 818: return fde_func_0818_0x0b0594(a0, a1);
        case 819: return fde_func_0819_0x0b05d0(a0, a1);
        case 820: return fde_func_0820_0x0b0610(a0, a1);
        case 821: return fde_func_0821_0x0b0650(a0, a1);
        case 822: return fde_func_0822_0x0b069c(a0, a1);
        case 823: return fde_func_0823_0x0b06b4(a0, a1);
        case 824: return fde_func_0824_0x0b06f0(a0, a1);
        case 825: return fde_func_0825_0x0b0724(a0, a1);
        case 826: return fde_func_0826_0x0b0a8c(a0, a1);
        case 827: return fde_func_0827_0x0b0b1c(a0, a1);
        case 828: return fde_func_0828_0x0b0eac(a0, a1);
        case 829: return fde_func_0829_0x0b0f4c(a0, a1);
        case 830: return fde_func_0830_0x0b0fc8(a0, a1);
        case 831: return fde_func_0831_0x0b116c(a0, a1);
        case 832: return fde_func_0832_0x0b12d0(a0, a1);
        case 833: return fde_func_0833_0x0b1360(a0, a1);
        case 834: return fde_func_0834_0x0b156c(a0, a1);
        case 835: return fde_func_0835_0x0b1dfc(a0, a1);
        case 836: return fde_func_0836_0x0b1e8c(a0, a1);
        case 837: return fde_func_0837_0x0b2054(a0, a1);
        case 838: return fde_func_0838_0x0b2064(a0, a1);
        case 839: return fde_func_0839_0x0b2098(a0, a1);
        case 840: return fde_func_0840_0x0b21b8(a0, a1);
        case 841: return fde_func_0841_0x0b244c(a0, a1);
        case 842: return fde_func_0842_0x0b25f0(a0, a1);
        case 843: return fde_func_0843_0x0b287c(a0, a1);
        case 844: return fde_func_0844_0x0b3604(a0, a1);
        case 845: return fde_func_0845_0x0b3c28(a0, a1);
        case 846: return fde_func_0846_0x0b5728(a0, a1);
        case 847: return fde_func_0847_0x0b5cec(a0, a1);
        case 848: return fde_func_0848_0x0b5dfc(a0, a1);
        case 849: return fde_func_0849_0x0b5eec(a0, a1);
        case 850: return fde_func_0850_0x0b63f4(a0, a1);
        case 851: return fde_func_0851_0x0b665c(a0, a1);
        case 852: return fde_func_0852_0x0b66cc(a0, a1);
        case 853: return fde_func_0853_0x0b67f8(a0, a1);
        case 854: return fde_func_0854_0x0b6bac(a0, a1);
        case 855: return fde_func_0855_0x0b6cb4(a0, a1);
        case 856: return fde_func_0856_0x0b7c98(a0, a1);
        case 857: return fde_func_0857_0x0b7f24(a0, a1);
        case 858: return fde_func_0858_0x0b86a0(a0, a1);
        case 859: return fde_func_0859_0x0b86a8(a0, a1);
        case 860: return fde_func_0860_0x0b86d4(a0, a1);
        case 861: return fde_func_0861_0x0b8704(a0, a1);
        case 862: return fde_func_0862_0x0b8728(a0, a1);
        case 863: return fde_func_0863_0x0b875c(a0, a1);
        case 864: return fde_func_0864_0x0b8788(a0, a1);
        case 865: return fde_func_0865_0x0b87a8(a0, a1);
        case 866: return fde_func_0866_0x0b87cc(a0, a1);
        case 867: return fde_func_0867_0x0b87ec(a0, a1);
        case 868: return fde_func_0868_0x0b87fc(a0, a1);
        case 869: return fde_func_0869_0x0b8810(a0, a1);
        case 870: return fde_func_0870_0x0b884c(a0, a1);
        case 871: return fde_func_0871_0x0b8e54(a0, a1);
        case 872: return fde_func_0872_0x0b8f1c(a0, a1);
        case 873: return fde_func_0873_0x0b9ce0(a0, a1);
        case 874: return fde_func_0874_0x0b9cfc(a0, a1);
        case 875: return fde_func_0875_0x0baf60(a0, a1);
        case 876: return fde_func_0876_0x0bb050(a0, a1);
        case 877: return fde_func_0877_0x0bb80c(a0, a1);
        case 878: return fde_func_0878_0x0bc170(a0, a1);
        case 879: return fde_func_0879_0x0bc388(a0, a1);
        case 880: return fde_func_0880_0x0bc680(a0, a1);
        case 881: return fde_func_0881_0x0bc73c(a0, a1);
        case 882: return fde_func_0882_0x0bc934(a0, a1);
        case 883: return fde_func_0883_0x0bca64(a0, a1);
        case 884: return fde_func_0884_0x0bcdc4(a0, a1);
        case 885: return fde_func_0885_0x0bcefc(a0, a1);
        case 886: return fde_func_0886_0x0bd048(a0, a1);
        case 887: return fde_func_0887_0x0bd058(a0, a1);
        case 888: return fde_func_0888_0x0bd088(a0, a1);
        case 889: return fde_func_0889_0x0bd17c(a0, a1);
        case 890: return fde_func_0890_0x0bd810(a0, a1);
        case 891: return fde_func_0891_0x0bda7c(a0, a1);
        case 892: return fde_func_0892_0x0bdab8(a0, a1);
        case 893: return fde_func_0893_0x0bdac8(a0, a1);
        case 894: return fde_func_0894_0x0bdaf4(a0, a1);
        case 895: return fde_func_0895_0x0bdb30(a0, a1);
        case 896: return fde_func_0896_0x0bdb4c(a0, a1);
        case 897: return fde_func_0897_0x0be35c(a0, a1);
        case 898: return fde_func_0898_0x0be44c(a0, a1);
        case 899: return fde_func_0899_0x0be53c(a0, a1);
        case 900: return fde_func_0900_0x0beef8(a0, a1);
        case 901: return fde_func_0901_0x0bf018(a0, a1);
        case 902: return fde_func_0902_0x0bf118(a0, a1);
        case 903: return fde_func_0903_0x0bf208(a0, a1);
        case 904: return fde_func_0904_0x0bf300(a0, a1);
        case 905: return fde_func_0905_0x0bf3f8(a0, a1);
        case 906: return fde_func_0906_0x0bf4f0(a0, a1);
        case 907: return fde_func_0907_0x0bf5e0(a0, a1);
        case 908: return fde_func_0908_0x0bf6e0(a0, a1);
        case 909: return fde_func_0909_0x0bf7ec(a0, a1);
        case 910: return fde_func_0910_0x0bf8ec(a0, a1);
        case 911: return fde_func_0911_0x0bf9e4(a0, a1);
        case 912: return fde_func_0912_0x0bfaf0(a0, a1);
        case 913: return fde_func_0913_0x0bfbe8(a0, a1);
        case 914: return fde_func_0914_0x0bfcd8(a0, a1);
        case 915: return fde_func_0915_0x0bfed8(a0, a1);
        case 916: return fde_func_0916_0x0c22d8(a0, a1);
        case 917: return fde_func_0917_0x0c24c8(a0, a1);
        case 918: return fde_func_0918_0x0c27c4(a0, a1);
        case 919: return fde_func_0919_0x0c2944(a0, a1);
        case 920: return fde_func_0920_0x0c2b8c(a0, a1);
        case 921: return fde_func_0921_0x0c2ca8(a0, a1);
        case 922: return fde_func_0922_0x0c2f70(a0, a1);
        case 923: return fde_func_0923_0x0c2fac(a0, a1);
        case 924: return fde_func_0924_0x0c30f8(a0, a1);
        case 925: return fde_func_0925_0x0c3600(a0, a1);
        case 926: return fde_func_0926_0x0c3c58(a0, a1);
        case 927: return fde_func_0927_0x0c42d4(a0, a1);
        case 928: return fde_func_0928_0x0c4384(a0, a1);
        case 929: return fde_func_0929_0x0c439c(a0, a1);
        case 930: return fde_func_0930_0x0c45a0(a0, a1);
        case 931: return fde_func_0931_0x0c4928(a0, a1);
        case 932: return fde_func_0932_0x0c4d80(a0, a1);
        case 933: return fde_func_0933_0x0c4e54(a0, a1);
        case 934: return fde_func_0934_0x0c4e9c(a0, a1);
        case 935: return fde_func_0935_0x0c5028(a0, a1);
        case 936: return fde_func_0936_0x0c55d8(a0, a1);
        case 937: return fde_func_0937_0x0c568c(a0, a1);
        case 938: return fde_func_0938_0x0c5c94(a0, a1);
        case 939: return fde_func_0939_0x0c7a38(a0, a1);
        case 940: return fde_func_0940_0x0c7da0(a0, a1);
        case 941: return fde_func_0941_0x0c7ebc(a0, a1);
        case 942: return fde_func_0942_0x0c8230(a0, a1);
        case 943: return fde_func_0943_0x0c83a0(a0, a1);
        case 944: return fde_func_0944_0x0c8408(a0, a1);
        case 945: return fde_func_0945_0x0c8584(a0, a1);
        case 946: return fde_func_0946_0x0c8a08(a0, a1);
        case 947: return fde_func_0947_0x0c8e34(a0, a1);
        case 948: return fde_func_0948_0x0c9044(a0, a1);
        case 949: return fde_func_0949_0x0c908c(a0, a1);
        case 950: return fde_func_0950_0x0c9364(a0, a1);
        case 951: return fde_func_0951_0x0c9450(a0, a1);
        case 952: return fde_func_0952_0x0c96dc(a0, a1);
        case 953: return fde_func_0953_0x0c97c8(a0, a1);
        case 954: return fde_func_0954_0x0c9e28(a0, a1);
        case 955: return fde_func_0955_0x0c9f14(a0, a1);
        case 956: return fde_func_0956_0x0ca00c(a0, a1);
        case 957: return fde_func_0957_0x0ca0f8(a0, a1);
        case 958: return fde_func_0958_0x0ca44c(a0, a1);
        case 959: return fde_func_0959_0x0ca538(a0, a1);
        case 960: return fde_func_0960_0x0ca630(a0, a1);
        case 961: return fde_func_0961_0x0ca728(a0, a1);
        case 962: return fde_func_0962_0x0ca7c8(a0, a1);
        case 963: return fde_func_0963_0x0ca84c(a0, a1);
        case 964: return fde_func_0964_0x0cac70(a0, a1);
        case 965: return fde_func_0965_0x0caccc(a0, a1);
        case 966: return fde_func_0966_0x0cad80(a0, a1);
        case 967: return fde_func_0967_0x0cb0b8(a0, a1);
        case 968: return fde_func_0968_0x0cb0e8(a0, a1);
        case 969: return fde_func_0969_0x0cb118(a0, a1);
        case 970: return fde_func_0970_0x0cb2e0(a0, a1);
        case 971: return fde_func_0971_0x0cb7d0(a0, a1);
        case 972: return fde_func_0972_0x0cb8ec(a0, a1);
        case 973: return fde_func_0973_0x0cb9d8(a0, a1);
        case 974: return fde_func_0974_0x0cbacc(a0, a1);
        case 975: return fde_func_0975_0x0cbbc4(a0, a1);
        case 976: return fde_func_0976_0x0cc320(a0, a1);
        case 977: return fde_func_0977_0x0cc390(a0, a1);
        case 978: return fde_func_0978_0x0cc4a4(a0, a1);
        case 979: return fde_func_0979_0x0ccabc(a0, a1);
        case 980: return fde_func_0980_0x0ccb4c(a0, a1);
        case 981: return fde_func_0981_0x0cd160(a0, a1);
        case 982: return fde_func_0982_0x0cd6d4(a0, a1);
        case 983: return fde_func_0983_0x0ce078(a0, a1);
        case 984: return fde_func_0984_0x0ce588(a0, a1);
        case 985: return fde_func_0985_0x0ce7bc(a0, a1);
        case 986: return fde_func_0986_0x0ce9b8(a0, a1);
        case 987: return fde_func_0987_0x0cec28(a0, a1);
        case 988: return fde_func_0988_0x0cf21c(a0, a1);
        case 989: return fde_func_0989_0x0cf3a4(a0, a1);
        case 990: return fde_func_0990_0x0cf654(a0, a1);
        case 991: return fde_func_0991_0x0cf6c4(a0, a1);
        case 992: return fde_func_0992_0x0cf710(a0, a1);
        case 993: return fde_func_0993_0x0cf72c(a0, a1);
        case 994: return fde_func_0994_0x0cf794(a0, a1);
        case 995: return fde_func_0995_0x0cf7e0(a0, a1);
        case 996: return fde_func_0996_0x0cf7fc(a0, a1);
        case 997: return fde_func_0997_0x0cf84c(a0, a1);
        case 998: return fde_func_0998_0x0cf898(a0, a1);
        case 999: return fde_func_0999_0x0cf8b4(a0, a1);
        case 1000: return fde_func_1000_0x0cfaac(a0, a1);
        case 1001: return fde_func_1001_0x0cfaf8(a0, a1);
        case 1002: return fde_func_1002_0x0cfb14(a0, a1);
        case 1003: return fde_func_1003_0x0cfdc8(a0, a1);
        case 1004: return fde_func_1004_0x0cfe1c(a0, a1);
        case 1005: return fde_func_1005_0x0d00b0(a0, a1);
        case 1006: return fde_func_1006_0x0d0388(a0, a1);
        case 1007: return fde_func_1007_0x0d0900(a0, a1);
        case 1008: return fde_func_1008_0x0d0d24(a0, a1);
        case 1009: return fde_func_1009_0x0d0fc4(a0, a1);
        case 1010: return fde_func_1010_0x0d10d4(a0, a1);
        case 1011: return fde_func_1011_0x0d11b4(a0, a1);
        case 1012: return fde_func_1012_0x0d12fc(a0, a1);
        case 1013: return fde_func_1013_0x0d13c4(a0, a1);
        case 1014: return fde_func_1014_0x0d14e8(a0, a1);
        case 1015: return fde_func_1015_0x0d16e4(a0, a1);
        case 1016: return fde_func_1016_0x0d1840(a0, a1);
        case 1017: return fde_func_1017_0x0d1bec(a0, a1);
        case 1018: return fde_func_1018_0x0d35c4(a0, a1);
        case 1019: return fde_func_1019_0x0d45d4(a0, a1);
        case 1020: return fde_func_1020_0x0d4990(a0, a1);
        case 1021: return fde_func_1021_0x0d4b80(a0, a1);
        case 1022: return fde_func_1022_0x0d4ed4(a0, a1);
        case 1023: return fde_func_1023_0x0d5278(a0, a1);
        case 1024: return fde_func_1024_0x0d5abc(a0, a1);
        case 1025: return fde_func_1025_0x0d5af8(a0, a1);
        case 1026: return fde_func_1026_0x0d6438(a0, a1);
        case 1027: return fde_func_1027_0x0d6758(a0, a1);
        case 1028: return fde_func_1028_0x0d67b8(a0, a1);
        case 1029: return fde_func_1029_0x0d6cec(a0, a1);
        case 1030: return fde_func_1030_0x0d6de0(a0, a1);
        case 1031: return fde_func_1031_0x0d7ac8(a0, a1);
        case 1032: return fde_func_1032_0x0d805c(a0, a1);
        case 1033: return fde_func_1033_0x0d8150(a0, a1);
        case 1034: return fde_func_1034_0x0d8194(a0, a1);
        case 1035: return fde_func_1035_0x0d8284(a0, a1);
        case 1036: return fde_func_1036_0x0d8428(a0, a1);
        case 1037: return fde_func_1037_0x0d8664(a0, a1);
        case 1038: return fde_func_1038_0x0d8894(a0, a1);
        case 1039: return fde_func_1039_0x0d8918(a0, a1);
        case 1040: return fde_func_1040_0x0d8ac4(a0, a1);
        case 1041: return fde_func_1041_0x0d8e14(a0, a1);
        case 1042: return fde_func_1042_0x0d8f84(a0, a1);
        case 1043: return fde_func_1043_0x0d917c(a0, a1);
        case 1044: return fde_func_1044_0x0d9448(a0, a1);
        case 1045: return fde_func_1045_0x0d9500(a0, a1);
        case 1046: return fde_func_1046_0x0d955c(a0, a1);
        case 1047: return fde_func_1047_0x0d965c(a0, a1);
        case 1048: return fde_func_1048_0x0d96e8(a0, a1);
        case 1049: return fde_func_1049_0x0d9764(a0, a1);
        case 1050: return fde_func_1050_0x0d97e0(a0, a1);
        case 1051: return fde_func_1051_0x0d9878(a0, a1);
        case 1052: return fde_func_1052_0x0d9a58(a0, a1);
        case 1053: return fde_func_1053_0x0d9c08(a0, a1);
        case 1054: return fde_func_1054_0x0d9cb0(a0, a1);
        case 1055: return fde_func_1055_0x0d9e4c(a0, a1);
        case 1056: return fde_func_1056_0x0da014(a0, a1);
        case 1057: return fde_func_1057_0x0da0a4(a0, a1);
        case 1058: return fde_func_1058_0x0da0fc(a0, a1);
        case 1059: return fde_func_1059_0x0da1d4(a0, a1);
        case 1060: return fde_func_1060_0x0da210(a0, a1);
        case 1061: return fde_func_1061_0x0da234(a0, a1);
        case 1062: return fde_func_1062_0x0da260(a0, a1);
        case 1063: return fde_func_1063_0x0da288(a0, a1);
        case 1064: return fde_func_1064_0x0da2b4(a0, a1);
        case 1065: return fde_func_1065_0x0da2dc(a0, a1);
        case 1066: return fde_func_1066_0x0da308(a0, a1);
        case 1067: return fde_func_1067_0x0da330(a0, a1);
        case 1068: return fde_func_1068_0x0da35c(a0, a1);
        case 1069: return fde_func_1069_0x0da388(a0, a1);
        case 1070: return fde_func_1070_0x0da3b4(a0, a1);
        case 1071: return fde_func_1071_0x0da3e0(a0, a1);
        case 1072: return fde_func_1072_0x0da408(a0, a1);
        case 1073: return fde_func_1073_0x0da430(a0, a1);
        case 1074: return fde_func_1074_0x0da45c(a0, a1);
        case 1075: return fde_func_1075_0x0da488(a0, a1);
        case 1076: return fde_func_1076_0x0da4b0(a0, a1);
        case 1077: return fde_func_1077_0x0da4d8(a0, a1);
        case 1078: return fde_func_1078_0x0da500(a0, a1);
        case 1079: return fde_func_1079_0x0da52c(a0, a1);
        case 1080: return fde_func_1080_0x0da558(a0, a1);
        case 1081: return fde_func_1081_0x0da5d0(a0, a1);
        case 1082: return fde_func_1082_0x0da6a0(a0, a1);
        case 1083: return fde_func_1083_0x0da728(a0, a1);
        case 1084: return fde_func_1084_0x0da754(a0, a1);
        case 1085: return fde_func_1085_0x0da778(a0, a1);
        case 1086: return fde_func_1086_0x0da79c(a0, a1);
        case 1087: return fde_func_1087_0x0da7c0(a0, a1);
        case 1088: return fde_func_1088_0x0da7e4(a0, a1);
        case 1089: return fde_func_1089_0x0da808(a0, a1);
        case 1090: return fde_func_1090_0x0da830(a0, a1);
        case 1091: return fde_func_1091_0x0da860(a0, a1);
        case 1092: return fde_func_1092_0x0da8a4(a0, a1);
        case 1093: return fde_func_1093_0x0da8cc(a0, a1);
        case 1094: return fde_func_1094_0x0da8f4(a0, a1);
        case 1095: return fde_func_1095_0x0da91c(a0, a1);
        case 1096: return fde_func_1096_0x0da944(a0, a1);
        case 1097: return fde_func_1097_0x0da96c(a0, a1);
        case 1098: return fde_func_1098_0x0da994(a0, a1);
        case 1099: return fde_func_1099_0x0da9bc(a0, a1);
        case 1100: return fde_func_1100_0x0da9e4(a0, a1);
        case 1101: return fde_func_1101_0x0daa0c(a0, a1);
        case 1102: return fde_func_1102_0x0daa34(a0, a1);
        case 1103: return fde_func_1103_0x0daa5c(a0, a1);
        case 1104: return fde_func_1104_0x0daa84(a0, a1);
        case 1105: return fde_func_1105_0x0daaac(a0, a1);
        case 1106: return fde_func_1106_0x0daad4(a0, a1);
        case 1107: return fde_func_1107_0x0daafc(a0, a1);
        case 1108: return fde_func_1108_0x0dab24(a0, a1);
        case 1109: return fde_func_1109_0x0dad74(a0, a1);
        case 1110: return fde_func_1110_0x0daf48(a0, a1);
        case 1111: return fde_func_1111_0x0db104(a0, a1);
        case 1112: return fde_func_1112_0x0db3b0(a0, a1);
        case 1113: return fde_func_1113_0x0db4e4(a0, a1);
        case 1114: return fde_func_1114_0x0db618(a0, a1);
        case 1115: return fde_func_1115_0x0db6bc(a0, a1);
        case 1116: return fde_func_1116_0x0dba40(a0, a1);
        case 1117: return fde_func_1117_0x0dbbb8(a0, a1);
        case 1118: return fde_func_1118_0x0dbd84(a0, a1);
        case 1119: return fde_func_1119_0x0dbe40(a0, a1);
        case 1120: return fde_func_1120_0x0dbfb8(a0, a1);
        case 1121: return fde_func_1121_0x0dc17c(a0, a1);
        case 1122: return fde_func_1122_0x0dc4c8(a0, a1);
        case 1123: return fde_func_1123_0x0dc7c4(a0, a1);
        case 1124: return fde_func_1124_0x0dcb18(a0, a1);
        case 1125: return fde_func_1125_0x0dcb88(a0, a1);
        case 1126: return fde_func_1126_0x0dcc28(a0, a1);
        case 1127: return fde_func_1127_0x0dccec(a0, a1);
        case 1128: return fde_func_1128_0x0dcdd4(a0, a1);
        case 1129: return fde_func_1129_0x0dce98(a0, a1);
        case 1130: return fde_func_1130_0x0dd038(a0, a1);
        case 1131: return fde_func_1131_0x0dd0b4(a0, a1);
        case 1132: return fde_func_1132_0x0dd11c(a0, a1);
        case 1133: return fde_func_1133_0x0dd318(a0, a1);
        case 1134: return fde_func_1134_0x0dd488(a0, a1);
        case 1135: return fde_func_1135_0x0dd5a4(a0, a1);
        case 1136: return fde_func_1136_0x0dd634(a0, a1);
        case 1137: return fde_func_1137_0x0dd6d0(a0, a1);
        case 1138: return fde_func_1138_0x0dd770(a0, a1);
        case 1139: return fde_func_1139_0x0dd9e0(a0, a1);
        case 1140: return fde_func_1140_0x0ddb58(a0, a1);
        case 1141: return fde_func_1141_0x0ddbcc(a0, a1);
        case 1142: return fde_func_1142_0x0ddc0c(a0, a1);
        case 1143: return fde_func_1143_0x0ddca0(a0, a1);
        case 1144: return fde_func_1144_0x0ddd44(a0, a1);
        case 1145: return fde_func_1145_0x0dde40(a0, a1);
        case 1146: return fde_func_1146_0x0dded8(a0, a1);
        case 1147: return fde_func_1147_0x0de42c(a0, a1);
        case 1148: return fde_func_1148_0x0de5ec(a0, a1);
        case 1149: return fde_func_1149_0x0de684(a0, a1);
        case 1150: return fde_func_1150_0x0de6ec(a0, a1);
        case 1151: return fde_func_1151_0x0de6f8(a0, a1);
        case 1152: return fde_func_1152_0x0de95c(a0, a1);
        case 1153: return fde_func_1153_0x0dea70(a0, a1);
        case 1154: return fde_func_1154_0x0dee3c(a0, a1);
        case 1155: return fde_func_1155_0x0df028(a0, a1);
        case 1156: return fde_func_1156_0x0df320(a0, a1);
        case 1157: return fde_func_1157_0x0df644(a0, a1);
        case 1158: return fde_func_1158_0x0df654(a0, a1);
        case 1159: return fde_func_1159_0x0df85c(a0, a1);
        case 1160: return fde_func_1160_0x0df8ac(a0, a1);
        case 1161: return fde_func_1161_0x0df920(a0, a1);
        case 1162: return fde_func_1162_0x0df970(a0, a1);
        case 1163: return fde_func_1163_0x0dfcd8(a0, a1);
        case 1164: return fde_func_1164_0x0e0298(a0, a1);
        case 1165: return fde_func_1165_0x0e0778(a0, a1);
        case 1166: return fde_func_1166_0x0e0bcc(a0, a1);
        case 1167: return fde_func_1167_0x0e0ee0(a0, a1);
        case 1168: return fde_func_1168_0x0e1058(a0, a1);
        case 1169: return fde_func_1169_0x0e115c(a0, a1);
        case 1170: return fde_func_1170_0x0e1d30(a0, a1);
        case 1171: return fde_func_1171_0x0e2908(a0, a1);
        case 1172: return fde_func_1172_0x0e34e4(a0, a1);
        case 1173: return fde_func_1173_0x0e40c0(a0, a1);
        case 1174: return fde_func_1174_0x0e40f8(a0, a1);
        case 1175: return fde_func_1175_0x0e4130(a0, a1);
        case 1176: return fde_func_1176_0x0e416c(a0, a1);
        case 1177: return fde_func_1177_0x0e41a4(a0, a1);
        case 1178: return fde_func_1178_0x0e41d8(a0, a1);
        case 1179: return fde_func_1179_0x0e4264(a0, a1);
        case 1180: return fde_func_1180_0x0e4350(a0, a1);
        case 1181: return fde_func_1181_0x0e43ec(a0, a1);
        case 1182: return fde_func_1182_0x0e44c4(a0, a1);
        case 1183: return fde_func_1183_0x0e45b0(a0, a1);
        case 1184: return fde_func_1184_0x0e45f4(a0, a1);
        case 1185: return fde_func_1185_0x0e4640(a0, a1);
        case 1186: return fde_func_1186_0x0e4684(a0, a1);
        case 1187: return fde_func_1187_0x0e46c4(a0, a1);
        case 1188: return fde_func_1188_0x0e46f8(a0, a1);
        case 1189: return fde_func_1189_0x0e4734(a0, a1);
        case 1190: return fde_func_1190_0x0e4770(a0, a1);
        case 1191: return fde_func_1191_0x0e47ac(a0, a1);
        case 1192: return fde_func_1192_0x0e47ec(a0, a1);
        case 1193: return fde_func_1193_0x0e4820(a0, a1);
        case 1194: return fde_func_1194_0x0e485c(a0, a1);
        case 1195: return fde_func_1195_0x0e4898(a0, a1);
        case 1196: return fde_func_1196_0x0e48d4(a0, a1);
        case 1197: return fde_func_1197_0x0e4914(a0, a1);
        case 1198: return fde_func_1198_0x0e4948(a0, a1);
        case 1199: return fde_func_1199_0x0e498c(a0, a1);
        default: return 0ULL;
    }
}

} // namespace ov
} // namespace metasec