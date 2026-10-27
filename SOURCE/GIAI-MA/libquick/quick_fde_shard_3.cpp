// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 3/5 for libquick.so
// Phân mảnh Khung Tháo Gỡ (FDE) AArch64 C++17 sạch 3/5 cho libquick.so
// Covers FDE indices [758 .. 1136] out of 1,893 total FDEs
// Bao phủ chỉ số FDE [758 .. 1136] trên tổng số 1.893 FDE
// ============================================================================
#include "quick_core.h"

// FDE #0758 | PC: 0x0cbccc | FDE: 0x041450 | Size: 256 bytes
// Khung tháo gỡ #0758 | Địa chỉ PC: 0x0cbccc | Địa chỉ FDE: 0x041450 | Kích thước: 256 bytes
//   0x0cbccc: D10243FF  sub      sp, sp, #0x90
//   0x0cbcd0: A9046BFB  stp      x27, x26, [sp, #0x40]
//   0x0cbcd4: A90563F9  stp      x25, x24, [sp, #0x50]
//   0x0cbcd8: A9065BF7  stp      x23, x22, [sp, #0x60]
static inline uint64_t fde_func_0758_0x0cbccc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cbcccULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9046bfbULL) ^ 0x041450ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0759 | PC: 0x0cc0ec | FDE: 0x041480 | Size: 256 bytes
// Khung tháo gỡ #0759 | Địa chỉ PC: 0x0cc0ec | Địa chỉ FDE: 0x041480 | Kích thước: 256 bytes
//   0x0cc0ec: D10403FF  sub      sp, sp, #0x100
//   0x0cc0f0: F90053FC  str      x28, [sp, #0xa0]
//   0x0cc0f4: A90B6BFB  stp      x27, x26, [sp, #0xb0]
//   0x0cc0f8: A90C63F9  stp      x25, x24, [sp, #0xc0]
static inline uint64_t fde_func_0759_0x0cc0ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cc0ecULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xf90053fcULL) ^ 0x041480ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0760 | PC: 0x0ccadc | FDE: 0x0414b0 | Size: 256 bytes
// Khung tháo gỡ #0760 | Địa chỉ PC: 0x0ccadc | Địa chỉ FDE: 0x0414b0 | Kích thước: 256 bytes
//   0x0ccadc: D102C3FF  sub      sp, sp, #0xb0
//   0x0ccae0: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x0ccae4: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0ccae8: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0760_0x0ccadc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ccadcULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x0414b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0761 | PC: 0x0ccff4 | FDE: 0x0414e0 | Size: 256 bytes
// Khung tháo gỡ #0761 | Địa chỉ PC: 0x0ccff4 | Địa chỉ FDE: 0x0414e0 | Kích thước: 256 bytes
//   0x0ccff4: D10103FF  sub      sp, sp, #0x40
//   0x0ccff8: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0ccffc: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0cd000: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0761_0x0ccff4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ccff4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0414e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0762 | PC: 0x0cd368 | FDE: 0x041500 | Size: 152 bytes
// Khung tháo gỡ #0762 | Địa chỉ PC: 0x0cd368 | Địa chỉ FDE: 0x041500 | Kích thước: 152 bytes
//   0x0cd368: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0cd36c: 92504428  and      x8, x1, #0xffff000000000003
//   0x0cd370: B25047E9  mov      x9, #-0xfffffffffffd
//   0x0cd374: EB09011F  cmp      x8, x9
static inline uint64_t fde_func_0762_0x0cd368(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cd368ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x92504428ULL) ^ 0x041500ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0763 | PC: 0x0cd400 | FDE: 0x041518 | Size: 256 bytes
// Khung tháo gỡ #0763 | Địa chỉ PC: 0x0cd400 | Địa chỉ FDE: 0x041518 | Kích thước: 256 bytes
//   0x0cd400: D10283FF  sub      sp, sp, #0xa0
//   0x0cd404: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x0cd408: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0cd40c: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0763_0x0cd400(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cd400ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x041518ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0764 | PC: 0x0cda0c | FDE: 0x041548 | Size: 256 bytes
// Khung tháo gỡ #0764 | Địa chỉ PC: 0x0cda0c | Địa chỉ FDE: 0x041548 | Kích thước: 256 bytes
//   0x0cda0c: D10143FF  sub      sp, sp, #0x50
//   0x0cda10: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0cda14: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x0cda18: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0764_0x0cda0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cda0cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x041548ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0765 | PC: 0x0cdb90 | FDE: 0x041568 | Size: 256 bytes
// Khung tháo gỡ #0765 | Địa chỉ PC: 0x0cdb90 | Địa chỉ FDE: 0x041568 | Kích thước: 256 bytes
//   0x0cdb90: D10283FF  sub      sp, sp, #0xa0
//   0x0cdb94: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x0cdb98: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0cdb9c: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0765_0x0cdb90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cdb90ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x041568ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0766 | PC: 0x0cdf50 | FDE: 0x041598 | Size: 256 bytes
// Khung tháo gỡ #0766 | Địa chỉ PC: 0x0cdf50 | Địa chỉ FDE: 0x041598 | Kích thước: 256 bytes
//   0x0cdf50: D10283FF  sub      sp, sp, #0xa0
//   0x0cdf54: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x0cdf58: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0cdf5c: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0766_0x0cdf50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cdf50ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x041598ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0767 | PC: 0x0ce964 | FDE: 0x0415c8 | Size: 256 bytes
// Khung tháo gỡ #0767 | Địa chỉ PC: 0x0ce964 | Địa chỉ FDE: 0x0415c8 | Kích thước: 256 bytes
//   0x0ce964: B9400428  ldr      w8, [x1, #4]
//   0x0ce968: 72007909  ands     w9, w8, #0x7fffffff
//   0x0ce96c: 540000C0  b.eq     #0xce984
//   0x0ce970: B940040A  ldr      w10, [x0, #4]
static inline uint64_t fde_func_0767_0x0ce964(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ce964ULL ^ (static_cast<uint64_t>(0xb9400428ULL) << 13);
    acc = (acc + a1 + 0x72007909ULL) ^ 0x0415c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0768 | PC: 0x0ceaa0 | FDE: 0x0415e0 | Size: 256 bytes
// Khung tháo gỡ #0768 | Địa chỉ PC: 0x0ceaa0 | Địa chỉ FDE: 0x0415e0 | Kích thước: 256 bytes
//   0x0ceaa0: D101C3FF  sub      sp, sp, #0x70
//   0x0ceaa4: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x0ceaa8: A9045BF7  stp      x23, x22, [sp, #0x40]
//   0x0ceaac: A90553F5  stp      x21, x20, [sp, #0x50]
static inline uint64_t fde_func_0768_0x0ceaa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ceaa0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90363f9ULL) ^ 0x0415e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0769 | PC: 0x0ced50 | FDE: 0x041608 | Size: 256 bytes
// Khung tháo gỡ #0769 | Địa chỉ PC: 0x0ced50 | Địa chỉ FDE: 0x041608 | Kích thước: 256 bytes
//   0x0ced50: D10203FF  sub      sp, sp, #0x80
//   0x0ced54: F9001BFA  str      x26, [sp, #0x30]
//   0x0ced58: A90463F9  stp      x25, x24, [sp, #0x40]
//   0x0ced5c: A9055BF7  stp      x23, x22, [sp, #0x50]
static inline uint64_t fde_func_0769_0x0ced50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ced50ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfaULL) ^ 0x041608ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0770 | PC: 0x0ceffc | FDE: 0x041630 | Size: 256 bytes
// Khung tháo gỡ #0770 | Địa chỉ PC: 0x0ceffc | Địa chỉ FDE: 0x041630 | Kích thước: 256 bytes
//   0x0ceffc: D10343FF  sub      sp, sp, #0xd0
//   0x0cf000: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x0cf004: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x0cf008: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0770_0x0ceffc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ceffcULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x041630ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0771 | PC: 0x0cf53c | FDE: 0x041660 | Size: 256 bytes
// Khung tháo gỡ #0771 | Địa chỉ PC: 0x0cf53c | Địa chỉ FDE: 0x041660 | Kích thước: 256 bytes
//   0x0cf53c: D10103FF  sub      sp, sp, #0x40
//   0x0cf540: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x0cf544: D53BD053  mrs      x19, tpidr_el0
//   0x0cf548: F9401668  ldr      x8, [x19, #0x28]
static inline uint64_t fde_func_0771_0x0cf53c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cf53cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9037bf3ULL) ^ 0x041660ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0772 | PC: 0x0cf6b0 | FDE: 0x041678 | Size: 112 bytes
// Khung tháo gỡ #0772 | Địa chỉ PC: 0x0cf6b0 | Địa chỉ FDE: 0x041678 | Kích thước: 112 bytes
//   0x0cf6b0: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0cf6b4: 927FF828  and      x8, x1, #0xfffffffffffffffe
//   0x0cf6b8: F100191F  cmp      x8, #6
//   0x0cf6bc: 540002C0  b.eq     #0xcf714
static inline uint64_t fde_func_0772_0x0cf6b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cf6b0ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x927ff828ULL) ^ 0x041678ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0773 | PC: 0x0cf720 | FDE: 0x041690 | Size: 256 bytes
// Khung tháo gỡ #0773 | Địa chỉ PC: 0x0cf720 | Địa chỉ FDE: 0x041690 | Kích thước: 256 bytes
//   0x0cf720: D10183FF  sub      sp, sp, #0x60
//   0x0cf724: F90013F8  str      x24, [sp, #0x20]
//   0x0cf728: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0cf72c: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0773_0x0cf720(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cf720ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f8ULL) ^ 0x041690ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0774 | PC: 0x0cfaf0 | FDE: 0x0416b8 | Size: 256 bytes
// Khung tháo gỡ #0774 | Địa chỉ PC: 0x0cfaf0 | Địa chỉ FDE: 0x0416b8 | Kích thước: 256 bytes
//   0x0cfaf0: D10183FF  sub      sp, sp, #0x60
//   0x0cfaf4: F90013F8  str      x24, [sp, #0x20]
//   0x0cfaf8: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0cfafc: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0774_0x0cfaf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cfaf0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f8ULL) ^ 0x0416b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0775 | PC: 0x0cfe6c | FDE: 0x0416e0 | Size: 256 bytes
// Khung tháo gỡ #0775 | Địa chỉ PC: 0x0cfe6c | Địa chỉ FDE: 0x0416e0 | Kích thước: 256 bytes
//   0x0cfe6c: D10183FF  sub      sp, sp, #0x60
//   0x0cfe70: F90013F8  str      x24, [sp, #0x20]
//   0x0cfe74: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0cfe78: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0775_0x0cfe6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cfe6cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f8ULL) ^ 0x0416e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0776 | PC: 0x0d0228 | FDE: 0x041708 | Size: 256 bytes
// Khung tháo gỡ #0776 | Địa chỉ PC: 0x0d0228 | Địa chỉ FDE: 0x041708 | Kích thước: 256 bytes
//   0x0d0228: D10283FF  sub      sp, sp, #0xa0
//   0x0d022c: F90033F8  str      x24, [sp, #0x60]
//   0x0d0230: A9075BF7  stp      x23, x22, [sp, #0x70]
//   0x0d0234: A90853F5  stp      x21, x20, [sp, #0x80]
static inline uint64_t fde_func_0776_0x0d0228(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d0228ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90033f8ULL) ^ 0x041708ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0777 | PC: 0x0d0668 | FDE: 0x041730 | Size: 256 bytes
// Khung tháo gỡ #0777 | Địa chỉ PC: 0x0d0668 | Địa chỉ FDE: 0x041730 | Kích thước: 256 bytes
//   0x0d0668: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0d066c: D371FC28  lsr      x8, x1, #0x31
//   0x0d0670: B6800041  tbz      x1, #0x30, #0xd0678
//   0x0d0674: B4000108  cbz      x8, #0xd0694
static inline uint64_t fde_func_0777_0x0d0668(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d0668ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xd371fc28ULL) ^ 0x041730ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0778 | PC: 0x0d07b0 | FDE: 0x041748 | Size: 256 bytes
// Khung tháo gỡ #0778 | Địa chỉ PC: 0x0d07b0 | Địa chỉ FDE: 0x041748 | Kích thước: 256 bytes
//   0x0d07b0: D10283FF  sub      sp, sp, #0xa0
//   0x0d07b4: A90663F9  stp      x25, x24, [sp, #0x60]
//   0x0d07b8: A9075BF7  stp      x23, x22, [sp, #0x70]
//   0x0d07bc: A90853F5  stp      x21, x20, [sp, #0x80]
static inline uint64_t fde_func_0778_0x0d07b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d07b0ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa90663f9ULL) ^ 0x041748ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0779 | PC: 0x0d0b3c | FDE: 0x041770 | Size: 140 bytes
// Khung tháo gỡ #0779 | Địa chỉ PC: 0x0d0b3c | Địa chỉ FDE: 0x041770 | Kích thước: 140 bytes
//   0x0d0b3c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0d0b40: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0d0b44: F9400061  ldr      x1, [x3]
//   0x0d0b48: AA0303F4  mov      x20, x3
static inline uint64_t fde_func_0779_0x0d0b3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d0b3cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x041770ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0780 | PC: 0x0d0bc8 | FDE: 0x041790 | Size: 256 bytes
// Khung tháo gỡ #0780 | Địa chỉ PC: 0x0d0bc8 | Địa chỉ FDE: 0x041790 | Kích thước: 256 bytes
//   0x0d0bc8: D10383FF  sub      sp, sp, #0xe0
//   0x0d0bcc: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x0d0bd0: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x0d0bd4: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_0780_0x0d0bc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d0bc8ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x041790ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0781 | PC: 0x0d15b8 | FDE: 0x0417c0 | Size: 256 bytes
// Khung tháo gỡ #0781 | Địa chỉ PC: 0x0d15b8 | Địa chỉ FDE: 0x0417c0 | Kích thước: 256 bytes
//   0x0d15b8: D10243FF  sub      sp, sp, #0x90
//   0x0d15bc: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0d15c0: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0d15c4: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0781_0x0d15b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d15b8ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x0417c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0782 | PC: 0x0d18a0 | FDE: 0x0417f0 | Size: 256 bytes [_Z18js_array_concat_gcP12LEPUSContext10LEPUSValueiPS1_]
// Khung tháo gỡ #0782 | Địa chỉ PC: 0x0d18a0 | Địa chỉ FDE: 0x0417f0 | Kích thước: 256 bytes
//   0x0d18a0: D10243FF  sub      sp, sp, #0x90
//   0x0d18a4: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0d18a8: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0d18ac: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0782_0x0d18a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d18a0ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x0417f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0783 | PC: 0x0d1c5c | FDE: 0x041820 | Size: 256 bytes
// Khung tháo gỡ #0783 | Địa chỉ PC: 0x0d1c5c | Địa chỉ FDE: 0x041820 | Kích thước: 256 bytes
//   0x0d1c5c: D10203FF  sub      sp, sp, #0x80
//   0x0d1c60: F9001BFA  str      x26, [sp, #0x30]
//   0x0d1c64: A90463F9  stp      x25, x24, [sp, #0x40]
//   0x0d1c68: A9055BF7  stp      x23, x22, [sp, #0x50]
static inline uint64_t fde_func_0783_0x0d1c5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d1c5cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfaULL) ^ 0x041820ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0784 | PC: 0x0d1e90 | FDE: 0x041848 | Size: 256 bytes
// Khung tháo gỡ #0784 | Địa chỉ PC: 0x0d1e90 | Địa chỉ FDE: 0x041848 | Kích thước: 256 bytes
//   0x0d1e90: D10303FF  sub      sp, sp, #0xc0
//   0x0d1e94: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x0d1e98: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x0d1e9c: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_0784_0x0d1e90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d1e90ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x041848ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0785 | PC: 0x0d2410 | FDE: 0x041878 | Size: 256 bytes
// Khung tháo gỡ #0785 | Địa chỉ PC: 0x0d2410 | Địa chỉ FDE: 0x041878 | Kích thước: 256 bytes
//   0x0d2410: D10203FF  sub      sp, sp, #0x80
//   0x0d2414: A9036BFB  stp      x27, x26, [sp, #0x30]
//   0x0d2418: A90463F9  stp      x25, x24, [sp, #0x40]
//   0x0d241c: A9055BF7  stp      x23, x22, [sp, #0x50]
static inline uint64_t fde_func_0785_0x0d2410(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2410ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9036bfbULL) ^ 0x041878ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0786 | PC: 0x0d2708 | FDE: 0x0418a8 | Size: 256 bytes
// Khung tháo gỡ #0786 | Địa chỉ PC: 0x0d2708 | Địa chỉ FDE: 0x0418a8 | Kích thước: 256 bytes
//   0x0d2708: D10203FF  sub      sp, sp, #0x80
//   0x0d270c: F9001BFA  str      x26, [sp, #0x30]
//   0x0d2710: A90463F9  stp      x25, x24, [sp, #0x40]
//   0x0d2714: A9055BF7  stp      x23, x22, [sp, #0x50]
static inline uint64_t fde_func_0786_0x0d2708(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2708ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfaULL) ^ 0x0418a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0787 | PC: 0x0d298c | FDE: 0x0418d0 | Size: 256 bytes
// Khung tháo gỡ #0787 | Địa chỉ PC: 0x0d298c | Địa chỉ FDE: 0x0418d0 | Kích thước: 256 bytes
//   0x0d298c: D102C3FF  sub      sp, sp, #0xb0
//   0x0d2990: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x0d2994: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0d2998: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0787_0x0d298c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d298cULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x0418d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0788 | PC: 0x0d2f64 | FDE: 0x041900 | Size: 256 bytes
// Khung tháo gỡ #0788 | Địa chỉ PC: 0x0d2f64 | Địa chỉ FDE: 0x041900 | Kích thước: 256 bytes
//   0x0d2f64: D10103FF  sub      sp, sp, #0x40
//   0x0d2f68: F9000BF6  str      x22, [sp, #0x10]
//   0x0d2f6c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0d2f70: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0788_0x0d2f64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2f64ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x041900ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0789 | PC: 0x0d3114 | FDE: 0x041920 | Size: 256 bytes
// Khung tháo gỡ #0789 | Địa chỉ PC: 0x0d3114 | Địa chỉ FDE: 0x041920 | Kích thước: 256 bytes
//   0x0d3114: D10243FF  sub      sp, sp, #0x90
//   0x0d3118: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0d311c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0d3120: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0789_0x0d3114(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d3114ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x041920ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0790 | PC: 0x0d35fc | FDE: 0x041950 | Size: 256 bytes
// Khung tháo gỡ #0790 | Địa chỉ PC: 0x0d35fc | Địa chỉ FDE: 0x041950 | Kích thước: 256 bytes
//   0x0d35fc: D102C3FF  sub      sp, sp, #0xb0
//   0x0d3600: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x0d3604: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0d3608: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0790_0x0d35fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d35fcULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x041950ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0791 | PC: 0x0d3b94 | FDE: 0x041980 | Size: 256 bytes
// Khung tháo gỡ #0791 | Địa chỉ PC: 0x0d3b94 | Địa chỉ FDE: 0x041980 | Kích thước: 256 bytes
//   0x0d3b94: D10443FF  sub      sp, sp, #0x110
//   0x0d3b98: A90B6FFC  stp      x28, x27, [sp, #0xb0]
//   0x0d3b9c: A90C67FA  stp      x26, x25, [sp, #0xc0]
//   0x0d3ba0: A90D5FF8  stp      x24, x23, [sp, #0xd0]
static inline uint64_t fde_func_0791_0x0d3b94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d3b94ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90b6ffcULL) ^ 0x041980ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0792 | PC: 0x0d4588 | FDE: 0x0419b0 | Size: 256 bytes
// Khung tháo gỡ #0792 | Địa chỉ PC: 0x0d4588 | Địa chỉ FDE: 0x0419b0 | Kích thước: 256 bytes
//   0x0d4588: D10203FF  sub      sp, sp, #0x80
//   0x0d458c: A9036BFB  stp      x27, x26, [sp, #0x30]
//   0x0d4590: A90463F9  stp      x25, x24, [sp, #0x40]
//   0x0d4594: A9055BF7  stp      x23, x22, [sp, #0x50]
static inline uint64_t fde_func_0792_0x0d4588(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d4588ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9036bfbULL) ^ 0x0419b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0793 | PC: 0x0d47fc | FDE: 0x0419e0 | Size: 256 bytes
// Khung tháo gỡ #0793 | Địa chỉ PC: 0x0d47fc | Địa chỉ FDE: 0x0419e0 | Kích thước: 256 bytes
//   0x0d47fc: D10243FF  sub      sp, sp, #0x90
//   0x0d4800: A9046BFB  stp      x27, x26, [sp, #0x40]
//   0x0d4804: A90563F9  stp      x25, x24, [sp, #0x50]
//   0x0d4808: A9065BF7  stp      x23, x22, [sp, #0x60]
static inline uint64_t fde_func_0793_0x0d47fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d47fcULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9046bfbULL) ^ 0x0419e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0794 | PC: 0x0d4b54 | FDE: 0x041a10 | Size: 256 bytes
// Khung tháo gỡ #0794 | Địa chỉ PC: 0x0d4b54 | Địa chỉ FDE: 0x041a10 | Kích thước: 256 bytes
//   0x0d4b54: D102C3FF  sub      sp, sp, #0xb0
//   0x0d4b58: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x0d4b5c: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0d4b60: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0794_0x0d4b54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d4b54ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x041a10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0795 | PC: 0x0d4e18 | FDE: 0x041a40 | Size: 256 bytes
// Khung tháo gỡ #0795 | Địa chỉ PC: 0x0d4e18 | Địa chỉ FDE: 0x041a40 | Kích thước: 256 bytes
//   0x0d4e18: D101C3FF  sub      sp, sp, #0x70
//   0x0d4e1c: A9026BFB  stp      x27, x26, [sp, #0x20]
//   0x0d4e20: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x0d4e24: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_0795_0x0d4e18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d4e18ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9026bfbULL) ^ 0x041a40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0796 | PC: 0x0d5200 | FDE: 0x041a68 | Size: 256 bytes
// Khung tháo gỡ #0796 | Địa chỉ PC: 0x0d5200 | Địa chỉ FDE: 0x041a68 | Kích thước: 256 bytes
//   0x0d5200: D10283FF  sub      sp, sp, #0xa0
//   0x0d5204: F90033F8  str      x24, [sp, #0x60]
//   0x0d5208: A9075BF7  stp      x23, x22, [sp, #0x70]
//   0x0d520c: A90853F5  stp      x21, x20, [sp, #0x80]
static inline uint64_t fde_func_0796_0x0d5200(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5200ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90033f8ULL) ^ 0x041a68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0797 | PC: 0x0d5540 | FDE: 0x041a90 | Size: 120 bytes
// Khung tháo gỡ #0797 | Địa chỉ PC: 0x0d5540 | Địa chỉ FDE: 0x041a90 | Kích thước: 120 bytes
//   0x0d5540: F9400808  ldr      x8, [x0, #0x10]
//   0x0d5544: AA0303E5  mov      x5, x3
//   0x0d5548: AA0003E3  mov      x3, x0
//   0x0d554c: 7100005F  cmp      w2, #0
static inline uint64_t fde_func_0797_0x0d5540(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5540ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xaa0303e5ULL) ^ 0x041a90ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0798 | PC: 0x0d55b8 | FDE: 0x041aa8 | Size: 256 bytes
// Khung tháo gỡ #0798 | Địa chỉ PC: 0x0d55b8 | Địa chỉ FDE: 0x041aa8 | Kích thước: 256 bytes
//   0x0d55b8: D10203FF  sub      sp, sp, #0x80
//   0x0d55bc: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0d55c0: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0d55c4: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0798_0x0d55b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d55b8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x041aa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0799 | PC: 0x0d5b84 | FDE: 0x041ad8 | Size: 256 bytes
// Khung tháo gỡ #0799 | Địa chỉ PC: 0x0d5b84 | Địa chỉ FDE: 0x041ad8 | Kích thước: 256 bytes
//   0x0d5b84: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0d5b88: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0d5b8c: AA0003F3  mov      x19, x0
//   0x0d5b90: B4000601  cbz      x1, #0xd5c50
static inline uint64_t fde_func_0799_0x0d5b84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5b84ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x041ad8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0800 | PC: 0x0d5cfc | FDE: 0x041af8 | Size: 52 bytes
// Khung tháo gỡ #0800 | Địa chỉ PC: 0x0d5cfc | Địa chỉ FDE: 0x041af8 | Kích thước: 52 bytes
//   0x0d5cfc: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0d5d00: AA0103E2  mov      x2, x1
//   0x0d5d04: F9400061  ldr      x1, [x3]
//   0x0d5d08: 94000076  bl       #0xd5ee0
static inline uint64_t fde_func_0800_0x0d5cfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5cfcULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xaa0103e2ULL) ^ 0x041af8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0801 | PC: 0x0d5d30 | FDE: 0x041b10 | Size: 256 bytes
// Khung tháo gỡ #0801 | Địa chỉ PC: 0x0d5d30 | Địa chỉ FDE: 0x041b10 | Kích thước: 256 bytes
//   0x0d5d30: D101C3FF  sub      sp, sp, #0x70
//   0x0d5d34: F9002BF4  str      x20, [sp, #0x50]
//   0x0d5d38: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x0d5d3c: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0801_0x0d5d30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5d30ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x041b10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0802 | PC: 0x0d5e64 | FDE: 0x041b30 | Size: 124 bytes
// Khung tháo gỡ #0802 | Địa chỉ PC: 0x0d5e64 | Địa chỉ FDE: 0x041b30 | Kích thước: 124 bytes
//   0x0d5e64: 52800240  mov      w0, #0x12
//   0x0d5e68: B40003A1  cbz      x1, #0xd5edc
//   0x0d5e6c: D2800048  mov      x8, #2
//   0x0d5e70: F2FFFFE8  movk     x8, #0xffff, lsl #48
static inline uint64_t fde_func_0802_0x0d5e64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5e64ULL ^ (static_cast<uint64_t>(0x52800240ULL) << 13);
    acc = (acc + a1 + 0xb40003a1ULL) ^ 0x041b30ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0803 | PC: 0x0d5ee0 | FDE: 0x041b48 | Size: 256 bytes
// Khung tháo gỡ #0803 | Địa chỉ PC: 0x0d5ee0 | Địa chỉ FDE: 0x041b48 | Kích thước: 256 bytes
//   0x0d5ee0: D10103FF  sub      sp, sp, #0x40
//   0x0d5ee4: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0d5ee8: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0d5eec: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0803_0x0d5ee0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5ee0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x041b48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0804 | PC: 0x0d6128 | FDE: 0x041b68 | Size: 256 bytes [_Z18JS_IsInstanceOf_GCP12LEPUSContext10LEPUSValueS1_]
// Khung tháo gỡ #0804 | Địa chỉ PC: 0x0d6128 | Địa chỉ FDE: 0x041b68 | Kích thước: 256 bytes
//   0x0d6128: D10103FF  sub      sp, sp, #0x40
//   0x0d612c: F9000BF6  str      x22, [sp, #0x10]
//   0x0d6130: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0d6134: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0804_0x0d6128(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6128ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x041b68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0805 | PC: 0x0d6288 | FDE: 0x041b88 | Size: 120 bytes
// Khung tháo gỡ #0805 | Địa chỉ PC: 0x0d6288 | Địa chỉ FDE: 0x041b88 | Kích thước: 120 bytes
//   0x0d6288: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0d628c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0d6290: 528006C2  mov      w2, #0x36
//   0x0d6294: AA0103E3  mov      x3, x1
static inline uint64_t fde_func_0805_0x0d6288(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6288ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x041b88ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0806 | PC: 0x0d6300 | FDE: 0x041ba8 | Size: 4 bytes
// Khung tháo gỡ #0806 | Địa chỉ PC: 0x0d6300 | Địa chỉ FDE: 0x041ba8 | Kích thước: 4 bytes
//   0x0d6300: 17FF0EEB  b        #0x99eac
static inline uint64_t fde_func_0806_0x0d6300(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6300ULL ^ (static_cast<uint64_t>(0x17ff0eebULL) << 13);
    acc = (acc + a1 + 0xd10143ffULL) ^ 0x041ba8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0807 | PC: 0x0d6304 | FDE: 0x041bc0 | Size: 256 bytes
// Khung tháo gỡ #0807 | Địa chỉ PC: 0x0d6304 | Địa chỉ FDE: 0x041bc0 | Kích thước: 256 bytes
//   0x0d6304: D10143FF  sub      sp, sp, #0x50
//   0x0d6308: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x0d630c: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0d6310: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0807_0x0d6304(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6304ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x041bc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0808 | PC: 0x0d64c0 | FDE: 0x041be8 | Size: 256 bytes
// Khung tháo gỡ #0808 | Địa chỉ PC: 0x0d64c0 | Địa chỉ FDE: 0x041be8 | Kích thước: 256 bytes
//   0x0d64c0: D10143FF  sub      sp, sp, #0x50
//   0x0d64c4: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0d64c8: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x0d64cc: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0808_0x0d64c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d64c0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x041be8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0809 | PC: 0x0d6664 | FDE: 0x041c08 | Size: 256 bytes
// Khung tháo gỡ #0809 | Địa chỉ PC: 0x0d6664 | Địa chỉ FDE: 0x041c08 | Kích thước: 256 bytes
//   0x0d6664: D10203FF  sub      sp, sp, #0x80
//   0x0d6668: F90023F8  str      x24, [sp, #0x40]
//   0x0d666c: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x0d6670: A90653F5  stp      x21, x20, [sp, #0x60]
static inline uint64_t fde_func_0809_0x0d6664(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6664ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f8ULL) ^ 0x041c08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0810 | PC: 0x0d6850 | FDE: 0x041c30 | Size: 196 bytes
// Khung tháo gỡ #0810 | Địa chỉ PC: 0x0d6850 | Địa chỉ FDE: 0x041c30 | Kích thước: 196 bytes
//   0x0d6850: D10103FF  sub      sp, sp, #0x40
//   0x0d6854: F9000BF6  str      x22, [sp, #0x10]
//   0x0d6858: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0d685c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0810_0x0d6850(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6850ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x041c30ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0811 | PC: 0x0d6914 | FDE: 0x041c50 | Size: 124 bytes
// Khung tháo gỡ #0811 | Địa chỉ PC: 0x0d6914 | Địa chỉ FDE: 0x041c50 | Kích thước: 124 bytes
//   0x0d6914: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0d6918: B27C0028  orr      x8, x1, #0x10
//   0x0d691c: F100491F  cmp      x8, #0x12
//   0x0d6920: 540000E1  b.ne     #0xd693c
static inline uint64_t fde_func_0811_0x0d6914(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6914ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb27c0028ULL) ^ 0x041c50ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0812 | PC: 0x0d6990 | FDE: 0x041c68 | Size: 256 bytes
// Khung tháo gỡ #0812 | Địa chỉ PC: 0x0d6990 | Địa chỉ FDE: 0x041c68 | Kích thước: 256 bytes
//   0x0d6990: D101C3FF  sub      sp, sp, #0x70
//   0x0d6994: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x0d6998: A9045BF7  stp      x23, x22, [sp, #0x40]
//   0x0d699c: A90553F5  stp      x21, x20, [sp, #0x50]
static inline uint64_t fde_func_0812_0x0d6990(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6990ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90363f9ULL) ^ 0x041c68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0813 | PC: 0x0d6cfc | FDE: 0x041c90 | Size: 256 bytes
// Khung tháo gỡ #0813 | Địa chỉ PC: 0x0d6cfc | Địa chỉ FDE: 0x041c90 | Kích thước: 256 bytes
//   0x0d6cfc: D10243FF  sub      sp, sp, #0x90
//   0x0d6d00: F90023FA  str      x26, [sp, #0x40]
//   0x0d6d04: A90563F9  stp      x25, x24, [sp, #0x50]
//   0x0d6d08: A9065BF7  stp      x23, x22, [sp, #0x60]
static inline uint64_t fde_func_0813_0x0d6cfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6cfcULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90023faULL) ^ 0x041c90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0814 | PC: 0x0d6f80 | FDE: 0x041cb8 | Size: 256 bytes
// Khung tháo gỡ #0814 | Địa chỉ PC: 0x0d6f80 | Địa chỉ FDE: 0x041cb8 | Kích thước: 256 bytes
//   0x0d6f80: D10183FF  sub      sp, sp, #0x60
//   0x0d6f84: F90013F8  str      x24, [sp, #0x20]
//   0x0d6f88: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0d6f8c: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0814_0x0d6f80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6f80ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f8ULL) ^ 0x041cb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0815 | PC: 0x0d715c | FDE: 0x041ce0 | Size: 216 bytes
// Khung tháo gỡ #0815 | Địa chỉ PC: 0x0d715c | Địa chỉ FDE: 0x041ce0 | Kích thước: 216 bytes
//   0x0d715c: D10103FF  sub      sp, sp, #0x40
//   0x0d7160: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0d7164: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0d7168: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0815_0x0d715c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d715cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x041ce0ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #0816 | PC: 0x0d7234 | FDE: 0x041d00 | Size: 256 bytes
// Khung tháo gỡ #0816 | Địa chỉ PC: 0x0d7234 | Địa chỉ FDE: 0x041d00 | Kích thước: 256 bytes
//   0x0d7234: D10103FF  sub      sp, sp, #0x40
//   0x0d7238: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0d723c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0d7240: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0816_0x0d7234(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7234ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x041d00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0817 | PC: 0x0d7360 | FDE: 0x041d20 | Size: 16 bytes
// Khung tháo gỡ #0817 | Địa chỉ PC: 0x0d7360 | Địa chỉ FDE: 0x041d20 | Kích thước: 16 bytes
//   0x0d7360: F9400061  ldr      x1, [x3]
//   0x0d7364: 52800022  mov      w2, #1
//   0x0d7368: 2A1F03E3  mov      w3, wzr
//   0x0d736c: 17FF640E  b        #0xb03a4
static inline uint64_t fde_func_0817_0x0d7360(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7360ULL ^ (static_cast<uint64_t>(0xf9400061ULL) << 13);
    acc = (acc + a1 + 0x52800022ULL) ^ 0x041d20ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0818 | PC: 0x0d7370 | FDE: 0x041d38 | Size: 16 bytes
// Khung tháo gỡ #0818 | Địa chỉ PC: 0x0d7370 | Địa chỉ FDE: 0x041d38 | Kích thước: 16 bytes
//   0x0d7370: F9400061  ldr      x1, [x3]
//   0x0d7374: 52800042  mov      w2, #2
//   0x0d7378: 2A1F03E3  mov      w3, wzr
//   0x0d737c: 17FF640A  b        #0xb03a4
static inline uint64_t fde_func_0818_0x0d7370(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7370ULL ^ (static_cast<uint64_t>(0xf9400061ULL) << 13);
    acc = (acc + a1 + 0x52800042ULL) ^ 0x041d38ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0819 | PC: 0x0d7380 | FDE: 0x041d50 | Size: 16 bytes
// Khung tháo gỡ #0819 | Địa chỉ PC: 0x0d7380 | Địa chỉ FDE: 0x041d50 | Kích thước: 16 bytes
//   0x0d7380: F9400061  ldr      x1, [x3]
//   0x0d7384: 52800222  mov      w2, #0x11
//   0x0d7388: 2A0403E3  mov      w3, w4
//   0x0d738c: 17FF6406  b        #0xb03a4
static inline uint64_t fde_func_0819_0x0d7380(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7380ULL ^ (static_cast<uint64_t>(0xf9400061ULL) << 13);
    acc = (acc + a1 + 0x52800222ULL) ^ 0x041d50ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0820 | PC: 0x0d7390 | FDE: 0x041d68 | Size: 256 bytes
// Khung tháo gỡ #0820 | Địa chỉ PC: 0x0d7390 | Địa chỉ FDE: 0x041d68 | Kích thước: 256 bytes
//   0x0d7390: D10383FF  sub      sp, sp, #0xe0
//   0x0d7394: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x0d7398: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x0d739c: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_0820_0x0d7390(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7390ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x041d68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0821 | PC: 0x0d77f8 | FDE: 0x041d98 | Size: 36 bytes
// Khung tháo gỡ #0821 | Địa chỉ PC: 0x0d77f8 | Địa chỉ FDE: 0x041d98 | Kích thước: 36 bytes
//   0x0d77f8: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0d77fc: A9400861  ldp      x1, x2, [x3]
//   0x0d7800: 52800023  mov      w3, #1
//   0x0d7804: 97FEB9C5  bl       #0x85f18
static inline uint64_t fde_func_0821_0x0d77f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d77f8ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xa9400861ULL) ^ 0x041d98ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0822 | PC: 0x0d781c | FDE: 0x041db0 | Size: 256 bytes
// Khung tháo gỡ #0822 | Địa chỉ PC: 0x0d781c | Địa chỉ FDE: 0x041db0 | Kích thước: 256 bytes
//   0x0d781c: D101C3FF  sub      sp, sp, #0x70
//   0x0d7820: F90013FA  str      x26, [sp, #0x20]
//   0x0d7824: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x0d7828: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_0822_0x0d781c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d781cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013faULL) ^ 0x041db0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0823 | PC: 0x0d79f0 | FDE: 0x041dd8 | Size: 256 bytes
// Khung tháo gỡ #0823 | Địa chỉ PC: 0x0d79f0 | Địa chỉ FDE: 0x041dd8 | Kích thước: 256 bytes
//   0x0d79f0: D10283FF  sub      sp, sp, #0xa0
//   0x0d79f4: F90023FC  str      x28, [sp, #0x40]
//   0x0d79f8: A9056BFB  stp      x27, x26, [sp, #0x50]
//   0x0d79fc: A90663F9  stp      x25, x24, [sp, #0x60]
static inline uint64_t fde_func_0823_0x0d79f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d79f0ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90023fcULL) ^ 0x041dd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0824 | PC: 0x0d7c60 | FDE: 0x041e08 | Size: 256 bytes
// Khung tháo gỡ #0824 | Địa chỉ PC: 0x0d7c60 | Địa chỉ FDE: 0x041e08 | Kích thước: 256 bytes
//   0x0d7c60: D10203FF  sub      sp, sp, #0x80
//   0x0d7c64: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x0d7c68: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x0d7c6c: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0824_0x0d7c60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7c60ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9055bf7ULL) ^ 0x041e08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0825 | PC: 0x0d7f14 | FDE: 0x041e30 | Size: 256 bytes
// Khung tháo gỡ #0825 | Địa chỉ PC: 0x0d7f14 | Địa chỉ FDE: 0x041e30 | Kích thước: 256 bytes
//   0x0d7f14: D102C3FF  sub      sp, sp, #0xb0
//   0x0d7f18: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x0d7f1c: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0d7f20: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0825_0x0d7f14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7f14ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x041e30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0826 | PC: 0x0d83f8 | FDE: 0x041e60 | Size: 256 bytes
// Khung tháo gỡ #0826 | Địa chỉ PC: 0x0d83f8 | Địa chỉ FDE: 0x041e60 | Kích thước: 256 bytes
//   0x0d83f8: D10203FF  sub      sp, sp, #0x80
//   0x0d83fc: F90013FC  str      x28, [sp, #0x20]
//   0x0d8400: A9036BFB  stp      x27, x26, [sp, #0x30]
//   0x0d8404: A90463F9  stp      x25, x24, [sp, #0x40]
static inline uint64_t fde_func_0826_0x0d83f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d83f8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fcULL) ^ 0x041e60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0827 | PC: 0x0d8630 | FDE: 0x041e90 | Size: 256 bytes
// Khung tháo gỡ #0827 | Địa chỉ PC: 0x0d8630 | Địa chỉ FDE: 0x041e90 | Kích thước: 256 bytes
//   0x0d8630: D102C3FF  sub      sp, sp, #0xb0
//   0x0d8634: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x0d8638: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0d863c: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0827_0x0d8630(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8630ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x041e90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0828 | PC: 0x0d88d8 | FDE: 0x041ec0 | Size: 16 bytes [_Z22JS_AddIntrinsicEval_GCP12LEPUSContext]
// Khung tháo gỡ #0828 | Địa chỉ PC: 0x0d88d8 | Địa chỉ FDE: 0x041ec0 | Kích thước: 16 bytes
//   0x0d88d8: B0FFFDC8  adrp     x8, #0x91000
//   0x0d88dc: 911BC108  add      x8, x8, #0x6f0
//   0x0d88e0: F9008008  str      x8, [x0, #0x100]
//   0x0d88e4: D65F03C0  ret      
static inline uint64_t fde_func_0828_0x0d88d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d88d8ULL ^ (static_cast<uint64_t>(0xb0fffdc8ULL) << 13);
    acc = (acc + a1 + 0x911bc108ULL) ^ 0x041ec0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0829 | PC: 0x0d88e8 | FDE: 0x041ed8 | Size: 20 bytes [_Z22JS_AddIntrinsicJSON_GCP12LEPUSContext]
// Khung tháo gỡ #0829 | Địa chỉ PC: 0x0d88e8 | Địa chỉ FDE: 0x041ed8 | Kích thước: 20 bytes
//   0x0d88e8: F9406401  ldr      x1, [x0, #0xc8]
//   0x0d88ec: 900006E2  adrp     x2, #0x1b4000
//   0x0d88f0: 91216042  add      x2, x2, #0x858
//   0x0d88f4: 52800023  mov      w3, #1
static inline uint64_t fde_func_0829_0x0d88e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d88e8ULL ^ (static_cast<uint64_t>(0xf9406401ULL) << 13);
    acc = (acc + a1 + 0x900006e2ULL) ^ 0x041ed8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0830 | PC: 0x0d88fc | FDE: 0x041ef0 | Size: 12 bytes [_Z19JS_SetClassProto_GCP12LEPUSContextj10LEPUSValue]
// Khung tháo gỡ #0830 | Địa chỉ PC: 0x0d88fc | Địa chỉ FDE: 0x041ef0 | Kích thước: 12 bytes
//   0x0d88fc: F9401C08  ldr      x8, [x0, #0x38]
//   0x0d8900: F8215902  str      x2, [x8, w1, uxtw #3]
//   0x0d8904: D65F03C0  ret      
static inline uint64_t fde_func_0830_0x0d88fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d88fcULL ^ (static_cast<uint64_t>(0xf9401c08ULL) << 13);
    acc = (acc + a1 + 0xf8215902ULL) ^ 0x041ef0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0831 | PC: 0x0d8908 | FDE: 0x041f08 | Size: 12 bytes [_Z19JS_GetClassProto_GCP12LEPUSContextj]
// Khung tháo gỡ #0831 | Địa chỉ PC: 0x0d8908 | Địa chỉ FDE: 0x041f08 | Kích thước: 12 bytes
//   0x0d8908: F9401C08  ldr      x8, [x0, #0x38]
//   0x0d890c: F8615900  ldr      x0, [x8, w1, uxtw #3]
//   0x0d8910: D65F03C0  ret      
static inline uint64_t fde_func_0831_0x0d8908(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8908ULL ^ (static_cast<uint64_t>(0xf9401c08ULL) << 13);
    acc = (acc + a1 + 0xf8615900ULL) ^ 0x041f08ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0832 | PC: 0x0d8914 | FDE: 0x041f20 | Size: 40 bytes [_Z14JS_NewInt64_GCP12LEPUSContextl]
// Khung tháo gỡ #0832 | Địa chỉ PC: 0x0d8914 | Địa chỉ FDE: 0x041f20 | Kích thước: 40 bytes
//   0x0d8914: EB21C03F  cmp      x1, w1, sxtw
//   0x0d8918: 54000081  b.ne     #0xd8928
//   0x0d891c: D2FFFFC0  mov      x0, #-0x2000000000000
//   0x0d8920: B3407C20  bfxil    x0, x1, #0, #0x20
static inline uint64_t fde_func_0832_0x0d8914(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8914ULL ^ (static_cast<uint64_t>(0xeb21c03fULL) << 13);
    acc = (acc + a1 + 0x54000081ULL) ^ 0x041f20ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0833 | PC: 0x0d893c | FDE: 0x041f38 | Size: 48 bytes [_Z15JS_NewString_GCP12LEPUSContextPKc]
// Khung tháo gỡ #0833 | Địa chỉ PC: 0x0d893c | Địa chỉ FDE: 0x041f38 | Kích thước: 48 bytes
//   0x0d893c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0d8940: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0d8944: AA0003F4  mov      x20, x0
//   0x0d8948: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_0833_0x0d893c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d893cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x041f38ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0834 | PC: 0x0d896c | FDE: 0x041f58 | Size: 152 bytes
// Khung tháo gỡ #0834 | Địa chỉ PC: 0x0d896c | Địa chỉ FDE: 0x041f58 | Kích thước: 152 bytes
//   0x0d896c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0d8970: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0d8974: F9400813  ldr      x19, [x0, #0x10]
//   0x0d8978: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0834_0x0d896c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d896cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x041f58ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0835 | PC: 0x0d8a04 | FDE: 0x041f78 | Size: 232 bytes
// Khung tháo gỡ #0835 | Địa chỉ PC: 0x0d8a04 | Địa chỉ FDE: 0x041f78 | Kích thước: 232 bytes
//   0x0d8a04: D101C3FF  sub      sp, sp, #0x70
//   0x0d8a08: F9002BF4  str      x20, [sp, #0x50]
//   0x0d8a0c: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x0d8a10: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0835_0x0d8a04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8a04ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x041f78ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0836 | PC: 0x0d8aec | FDE: 0x041f98 | Size: 204 bytes [_Z17JS_AtomToValue_GCP12LEPUSContextj]
// Khung tháo gỡ #0836 | Địa chỉ PC: 0x0d8aec | Địa chỉ FDE: 0x041f98 | Kích thước: 204 bytes
//   0x0d8aec: D101C3FF  sub      sp, sp, #0x70
//   0x0d8af0: F9002BF4  str      x20, [sp, #0x50]
//   0x0d8af4: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x0d8af8: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0836_0x0d8aec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8aecULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x041f98ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #0837 | PC: 0x0d8bb8 | FDE: 0x041fb8 | Size: 188 bytes [_Z18JS_AtomToString_GCP12LEPUSContextj]
// Khung tháo gỡ #0837 | Địa chỉ PC: 0x0d8bb8 | Địa chỉ FDE: 0x041fb8 | Kích thước: 188 bytes
//   0x0d8bb8: D101C3FF  sub      sp, sp, #0x70
//   0x0d8bbc: F9002BF4  str      x20, [sp, #0x50]
//   0x0d8bc0: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x0d8bc4: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0837_0x0d8bb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8bb8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x041fb8ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0838 | PC: 0x0d8c74 | FDE: 0x041fd8 | Size: 256 bytes [_Z19JS_AtomToCString_GCP12LEPUSContextj]
// Khung tháo gỡ #0838 | Địa chỉ PC: 0x0d8c74 | Địa chỉ FDE: 0x041fd8 | Kích thước: 256 bytes
//   0x0d8c74: D10203FF  sub      sp, sp, #0x80
//   0x0d8c78: F9002BF6  str      x22, [sp, #0x50]
//   0x0d8c7c: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x0d8c80: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0838_0x0d8c74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8c74ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf6ULL) ^ 0x041fd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0839 | PC: 0x0d8dc4 | FDE: 0x041ff8 | Size: 120 bytes [_ZN11HandleScope13PushLEPUSAtomEj]
// Khung tháo gỡ #0839 | Địa chỉ PC: 0x0d8dc4 | Địa chỉ FDE: 0x041ff8 | Kích thước: 120 bytes
//   0x0d8dc4: 71032C3F  cmp      w1, #0xcb
//   0x0d8dc8: 5400030B  b.lt     #0xd8e28
//   0x0d8dcc: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0d8dd0: A9017BF3  stp      x19, x30, [sp, #0x10]
static inline uint64_t fde_func_0839_0x0d8dc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8dc4ULL ^ (static_cast<uint64_t>(0x71032c3fULL) << 13);
    acc = (acc + a1 + 0x5400030bULL) ^ 0x041ff8ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0840 | PC: 0x0d8e3c | FDE: 0x042018 | Size: 8 bytes [_Z14JS_ToString_GCP12LEPUSContext10LEPUSValue]
// Khung tháo gỡ #0840 | Địa chỉ PC: 0x0d8e3c | Địa chỉ FDE: 0x042018 | Kích thước: 8 bytes
//   0x0d8e3c: 2A1F03E2  mov      w2, wzr
//   0x0d8e40: 17FE9AED  b        #0x7f9f4
static inline uint64_t fde_func_0840_0x0d8e3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8e3cULL ^ (static_cast<uint64_t>(0x2a1f03e2ULL) << 13);
    acc = (acc + a1 + 0x17fe9aedULL) ^ 0x042018ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0841 | PC: 0x0d8e44 | FDE: 0x042030 | Size: 4 bytes [_Z31JS_GetSeparableStringContent_GCP12LEPUSContext10LEPUSValue]
// Khung tháo gỡ #0841 | Địa chỉ PC: 0x0d8e44 | Địa chỉ FDE: 0x042030 | Kích thước: 4 bytes
//   0x0d8e44: 17FE9BD1  b        #0x7fd88
static inline uint64_t fde_func_0841_0x0d8e44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8e44ULL ^ (static_cast<uint64_t>(0x17fe9bd1ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff4ULL) ^ 0x042030ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0842 | PC: 0x0d8e48 | FDE: 0x042048 | Size: 236 bytes [_Z25JS_NewObjectProtoClass_GCP12LEPUSContext10LEPUSValuej]
// Khung tháo gỡ #0842 | Địa chỉ PC: 0x0d8e48 | Địa chỉ FDE: 0x042048 | Kích thước: 236 bytes
//   0x0d8e48: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0d8e4c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0d8e50: 2A0203F3  mov      w19, w2
//   0x0d8e54: AA0103E8  mov      x8, x1
static inline uint64_t fde_func_0842_0x0d8e48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8e48ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x042048ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0843 | PC: 0x0d8f34 | FDE: 0x042068 | Size: 24 bytes [_Z14JS_NewArray_GCP12LEPUSContext]
// Khung tháo gỡ #0843 | Địa chỉ PC: 0x0d8f34 | Địa chỉ FDE: 0x042068 | Kích thước: 24 bytes
//   0x0d8f34: F9401801  ldr      x1, [x0, #0x30]
//   0x0d8f38: 52800042  mov      w2, #2
//   0x0d8f3c: B9400028  ldr      w8, [x1]
//   0x0d8f40: 11000508  add      w8, w8, #1
static inline uint64_t fde_func_0843_0x0d8f34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8f34ULL ^ (static_cast<uint64_t>(0xf9401801ULL) << 13);
    acc = (acc + a1 + 0x52800042ULL) ^ 0x042068ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0844 | PC: 0x0d8f4c | FDE: 0x042080 | Size: 120 bytes
// Khung tháo gỡ #0844 | Địa chỉ PC: 0x0d8f4c | Địa chỉ FDE: 0x042080 | Kích thước: 120 bytes
//   0x0d8f4c: B40003A1  cbz      x1, #0xd8fc0
//   0x0d8f50: D2800048  mov      x8, #2
//   0x0d8f54: F2FFFFE8  movk     x8, #0xffff, lsl #48
//   0x0d8f58: 8A080029  and      x9, x1, x8
static inline uint64_t fde_func_0844_0x0d8f4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8f4cULL ^ (static_cast<uint64_t>(0xb40003a1ULL) << 13);
    acc = (acc + a1 + 0xd2800048ULL) ^ 0x042080ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0845 | PC: 0x0d8fc4 | FDE: 0x042098 | Size: 256 bytes
// Khung tháo gỡ #0845 | Địa chỉ PC: 0x0d8fc4 | Địa chỉ FDE: 0x042098 | Kích thước: 256 bytes
//   0x0d8fc4: D10143FF  sub      sp, sp, #0x50
//   0x0d8fc8: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x0d8fcc: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0d8fd0: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0845_0x0d8fc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8fc4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x042098ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0846 | PC: 0x0d9194 | FDE: 0x0420c0 | Size: 256 bytes
// Khung tháo gỡ #0846 | Địa chỉ PC: 0x0d9194 | Địa chỉ FDE: 0x0420c0 | Kích thước: 256 bytes
//   0x0d9194: D10203FF  sub      sp, sp, #0x80
//   0x0d9198: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x0d919c: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x0d91a0: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0846_0x0d9194(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9194ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9055bf7ULL) ^ 0x0420c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0847 | PC: 0x0d9328 | FDE: 0x0420e8 | Size: 20 bytes [_Z25JS_DefinePropertyValue_GCP12LEPUSContext10LEPUSValuejS1_i]
// Khung tháo gỡ #0847 | Địa chỉ PC: 0x0d9328 | Địa chỉ FDE: 0x0420e8 | Kích thước: 20 bytes
//   0x0d9328: 5284E008  mov      w8, #0x2700
//   0x0d932c: 2A080086  orr      w6, w4, w8
//   0x0d9330: 52800244  mov      w4, #0x12
//   0x0d9334: 52800245  mov      w5, #0x12
static inline uint64_t fde_func_0847_0x0d9328(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9328ULL ^ (static_cast<uint64_t>(0x5284e008ULL) << 13);
    acc = (acc + a1 + 0x2a080086ULL) ^ 0x0420e8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0848 | PC: 0x0d933c | FDE: 0x042100 | Size: 28 bytes
// Khung tháo gỡ #0848 | Địa chỉ PC: 0x0d933c | Địa chỉ FDE: 0x042100 | Kích thước: 28 bytes
//   0x0d933c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0d9340: D0FFFAC1  adrp     x1, #0x33000
//   0x0d9344: 9116CC21  add      x1, x1, #0x5b3
//   0x0d9348: 94003DF5  bl       #0xe8b1c
static inline uint64_t fde_func_0848_0x0d933c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d933cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xd0fffac1ULL) ^ 0x042100ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0849 | PC: 0x0d9358 | FDE: 0x042118 | Size: 12 bytes [_Z15JS_MarkValue_GCP12LEPUSRuntime10LEPUSValuePFvS0_S1_mEi]
// Khung tháo gỡ #0849 | Địa chỉ PC: 0x0d9358 | Địa chỉ FDE: 0x042118 | Kích thước: 12 bytes
//   0x0d9358: AA0203E4  mov      x4, x2
//   0x0d935c: 93407C62  sxtw     x2, w3
//   0x0d9360: D61F0080  br       x4
static inline uint64_t fde_func_0849_0x0d9358(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9358ULL ^ (static_cast<uint64_t>(0xaa0203e4ULL) << 13);
    acc = (acc + a1 + 0x93407c62ULL) ^ 0x042118ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0850 | PC: 0x0d9364 | FDE: 0x042130 | Size: 16 bytes [_Z11JS_RunGC_GCP12LEPUSRuntime]
// Khung tháo gỡ #0850 | Địa chỉ PC: 0x0d9364 | Địa chỉ FDE: 0x042130 | Kích thước: 16 bytes
//   0x0d9364: F9418C00  ldr      x0, [x0, #0x318]
//   0x0d9368: AA1F03E1  mov      x1, xzr
//   0x0d936c: 2A1F03E2  mov      w2, wzr
//   0x0d9370: 17FEC598  b        #0x8a9d0
static inline uint64_t fde_func_0850_0x0d9364(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9364ULL ^ (static_cast<uint64_t>(0xf9418c00ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e1ULL) ^ 0x042130ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0851 | PC: 0x0d9374 | FDE: 0x042148 | Size: 164 bytes [LEPUS_RunAllGC]
// Khung tháo gỡ #0851 | Địa chỉ PC: 0x0d9374 | Địa chỉ FDE: 0x042148 | Kích thước: 164 bytes
//   0x0d9374: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0d9378: F0000720  adrp     x0, #0x1c0000
//   0x0d937c: 9111F000  add      x0, x0, #0x47c
//   0x0d9380: 94035D94  bl       #0x1b09d0
static inline uint64_t fde_func_0851_0x0d9374(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9374ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf0000720ULL) ^ 0x042148ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0852 | PC: 0x0d9418 | FDE: 0x042160 | Size: 8 bytes [_Z21JS_GetGlobalObject_GCP12LEPUSContext]
// Khung tháo gỡ #0852 | Địa chỉ PC: 0x0d9418 | Địa chỉ FDE: 0x042160 | Kích thước: 8 bytes
//   0x0d9418: F9406400  ldr      x0, [x0, #0xc8]
//   0x0d941c: D65F03C0  ret      
static inline uint64_t fde_func_0852_0x0d9418(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9418ULL ^ (static_cast<uint64_t>(0xf9406400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x042160ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0853 | PC: 0x0d9420 | FDE: 0x042178 | Size: 8 bytes [_Z14JS_NewError_GCP12LEPUSContext]
// Khung tháo gỡ #0853 | Địa chỉ PC: 0x0d9420 | Địa chỉ FDE: 0x042178 | Kích thước: 8 bytes
//   0x0d9420: 52800061  mov      w1, #3
//   0x0d9424: 17FF010E  b        #0x9985c
static inline uint64_t fde_func_0853_0x0d9420(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9420ULL ^ (static_cast<uint64_t>(0x52800061ULL) << 13);
    acc = (acc + a1 + 0x17ff010eULL) ^ 0x042178ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0854 | PC: 0x0d9428 | FDE: 0x042190 | Size: 104 bytes
// Khung tháo gỡ #0854 | Địa chỉ PC: 0x0d9428 | Địa chỉ FDE: 0x042190 | Kích thước: 104 bytes
//   0x0d9428: D101C3FF  sub      sp, sp, #0x70
//   0x0d942c: F9002BF4  str      x20, [sp, #0x50]
//   0x0d9430: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x0d9434: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0854_0x0d9428(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9428ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x042190ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0855 | PC: 0x0d9490 | FDE: 0x0421b0 | Size: 120 bytes
// Khung tháo gỡ #0855 | Địa chỉ PC: 0x0d9490 | Địa chỉ FDE: 0x0421b0 | Kích thước: 120 bytes
//   0x0d9490: D101C3FF  sub      sp, sp, #0x70
//   0x0d9494: F9002BF4  str      x20, [sp, #0x50]
//   0x0d9498: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x0d949c: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0855_0x0d9490(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9490ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x0421b0ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0856 | PC: 0x0d9508 | FDE: 0x0421d0 | Size: 8 bytes [_Z18JS_SetPrototype_GCP12LEPUSContext10LEPUSValueS1_]
// Khung tháo gỡ #0856 | Địa chỉ PC: 0x0d9508 | Địa chỉ FDE: 0x0421d0 | Kích thước: 8 bytes
//   0x0d9508: 52800023  mov      w3, #1
//   0x0d950c: 17FF060B  b        #0x9ad38
static inline uint64_t fde_func_0856_0x0d9508(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9508ULL ^ (static_cast<uint64_t>(0x52800023ULL) << 13);
    acc = (acc + a1 + 0x17ff060bULL) ^ 0x0421d0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0857 | PC: 0x0d9510 | FDE: 0x0421e8 | Size: 4 bytes [_Z25JS_GetPropertyInternal_GCP12LEPUSContext10LEPUSValuejS1_i]
// Khung tháo gỡ #0857 | Địa chỉ PC: 0x0d9510 | Địa chỉ FDE: 0x0421e8 | Kích thước: 4 bytes
//   0x0d9510: 17FE9D72  b        #0x80ad8
static inline uint64_t fde_func_0857_0x0d9510(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9510ULL ^ (static_cast<uint64_t>(0x17fe9d72ULL) << 13);
    acc = (acc + a1 + 0x37f80082ULL) ^ 0x0421e8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0858 | PC: 0x0d9514 | FDE: 0x042200 | Size: 36 bytes [_Z23JS_GetPropertyUint32_GCP12LEPUSContext10LEPUSValuej]
// Khung tháo gỡ #0858 | Địa chỉ PC: 0x0d9514 | Địa chỉ FDE: 0x042200 | Kích thước: 36 bytes
//   0x0d9514: 37F80082  tbnz     w2, #0x1f, #0xd9524
//   0x0d9518: 2A0203E8  mov      w8, w2
//   0x0d951c: B24F3902  orr      x2, x8, #0xfffe000000000000
//   0x0d9520: 17FEA18E  b        #0x81b58
static inline uint64_t fde_func_0858_0x0d9514(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9514ULL ^ (static_cast<uint64_t>(0x37f80082ULL) << 13);
    acc = (acc + a1 + 0x2a0203e8ULL) ^ 0x042200ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0859 | PC: 0x0d9538 | FDE: 0x042218 | Size: 256 bytes
// Khung tháo gỡ #0859 | Địa chỉ PC: 0x0d9538 | Địa chỉ FDE: 0x042218 | Kích thước: 256 bytes
//   0x0d9538: D10283FF  sub      sp, sp, #0xa0
//   0x0d953c: A9056BFB  stp      x27, x26, [sp, #0x50]
//   0x0d9540: A90663F9  stp      x25, x24, [sp, #0x60]
//   0x0d9544: A9075BF7  stp      x23, x22, [sp, #0x70]
static inline uint64_t fde_func_0859_0x0d9538(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9538ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9056bfbULL) ^ 0x042218ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0860 | PC: 0x0d9744 | FDE: 0x042248 | Size: 256 bytes
// Khung tháo gỡ #0860 | Địa chỉ PC: 0x0d9744 | Địa chỉ FDE: 0x042248 | Kích thước: 256 bytes
//   0x0d9744: D101C3FF  sub      sp, sp, #0x70
//   0x0d9748: F9002BF4  str      x20, [sp, #0x50]
//   0x0d974c: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x0d9750: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0860_0x0d9744(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9744ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x042248ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0861 | PC: 0x0d98a4 | FDE: 0x042268 | Size: 256 bytes
// Khung tháo gỡ #0861 | Địa chỉ PC: 0x0d98a4 | Địa chỉ FDE: 0x042268 | Kích thước: 256 bytes
//   0x0d98a4: D101C3FF  sub      sp, sp, #0x70
//   0x0d98a8: F9002BF4  str      x20, [sp, #0x50]
//   0x0d98ac: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x0d98b0: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0861_0x0d98a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d98a4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x042268ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0862 | PC: 0x0d9a08 | FDE: 0x042288 | Size: 256 bytes
// Khung tháo gỡ #0862 | Địa chỉ PC: 0x0d9a08 | Địa chỉ FDE: 0x042288 | Kích thước: 256 bytes
//   0x0d9a08: D10183FF  sub      sp, sp, #0x60
//   0x0d9a0c: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x0d9a10: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x0d9a14: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_0862_0x0d9a08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9a08ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x042288ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0863 | PC: 0x0d9ca4 | FDE: 0x0422b0 | Size: 256 bytes
// Khung tháo gỡ #0863 | Địa chỉ PC: 0x0d9ca4 | Địa chỉ FDE: 0x0422b0 | Kích thước: 256 bytes
//   0x0d9ca4: D10143FF  sub      sp, sp, #0x50
//   0x0d9ca8: F9000BF8  str      x24, [sp, #0x10]
//   0x0d9cac: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0d9cb0: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0863_0x0d9ca4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9ca4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf8ULL) ^ 0x0422b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0864 | PC: 0x0d9f2c | FDE: 0x0422d8 | Size: 76 bytes [_Z25JS_GetOwnPropertyNames_GCP12LEPUSContextPP17LEPUSPropertyEnumPj10LEPUSValuei]
// Khung tháo gỡ #0864 | Địa chỉ PC: 0x0d9f2c | Địa chỉ FDE: 0x0422d8 | Kích thước: 76 bytes
//   0x0d9f2c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0d9f30: B4000183  cbz      x3, #0xd9f60
//   0x0d9f34: D2800048  mov      x8, #2
//   0x0d9f38: F2FFFFE8  movk     x8, #0xffff, lsl #48
static inline uint64_t fde_func_0864_0x0d9f2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9f2cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb4000183ULL) ^ 0x0422d8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0865 | PC: 0x0d9f78 | FDE: 0x0422f0 | Size: 76 bytes [_Z20JS_GetOwnProperty_GCP12LEPUSContextP23LEPUSPropertyDescriptor10LEPUSValuej]
// Khung tháo gỡ #0865 | Địa chỉ PC: 0x0d9f78 | Địa chỉ FDE: 0x0422f0 | Kích thước: 76 bytes
//   0x0d9f78: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0d9f7c: B4000182  cbz      x2, #0xd9fac
//   0x0d9f80: D2800048  mov      x8, #2
//   0x0d9f84: F2FFFFE8  movk     x8, #0xffff, lsl #48
static inline uint64_t fde_func_0865_0x0d9f78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9f78ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb4000182ULL) ^ 0x0422f0ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0866 | PC: 0x0d9fc4 | FDE: 0x042308 | Size: 76 bytes [_Z18JS_IsExtensible_GCP12LEPUSContext10LEPUSValue]
// Khung tháo gỡ #0866 | Địa chỉ PC: 0x0d9fc4 | Địa chỉ FDE: 0x042308 | Kích thước: 76 bytes
//   0x0d9fc4: 2A1F03E8  mov      w8, wzr
//   0x0d9fc8: B40001E1  cbz      x1, #0xda004
//   0x0d9fcc: D2800049  mov      x9, #2
//   0x0d9fd0: F2FFFFE9  movk     x9, #0xffff, lsl #48
static inline uint64_t fde_func_0866_0x0d9fc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9fc4ULL ^ (static_cast<uint64_t>(0x2a1f03e8ULL) << 13);
    acc = (acc + a1 + 0xb40001e1ULL) ^ 0x042308ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0867 | PC: 0x0da010 | FDE: 0x042320 | Size: 8 bytes [_Z19JS_ToPropertyKey_GCP12LEPUSContext10LEPUSValue]
// Khung tháo gỡ #0867 | Địa chỉ PC: 0x0da010 | Địa chỉ FDE: 0x042320 | Kích thước: 8 bytes
//   0x0da010: 52800022  mov      w2, #1
//   0x0da014: 17FE9678  b        #0x7f9f4
static inline uint64_t fde_func_0867_0x0da010(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da010ULL ^ (static_cast<uint64_t>(0x52800022ULL) << 13);
    acc = (acc + a1 + 0x17fe9678ULL) ^ 0x042320ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0868 | PC: 0x0da018 | FDE: 0x042338 | Size: 216 bytes [_Z20JS_GetPropertyStr_GCP12LEPUSContext10LEPUSValuePKc]
// Khung tháo gỡ #0868 | Địa chỉ PC: 0x0da018 | Địa chỉ FDE: 0x042338 | Kích thước: 216 bytes
//   0x0da018: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x0da01c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0da020: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0da024: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0868_0x0da018(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da018ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x042338ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #0869 | PC: 0x0da0f0 | FDE: 0x042360 | Size: 4 bytes [_Z13JS_ToInt32_GCP12LEPUSContextPi10LEPUSValue]
// Khung tháo gỡ #0869 | Địa chỉ PC: 0x0da0f0 | Địa chỉ FDE: 0x042360 | Kích thước: 4 bytes
//   0x0da0f0: 17FEA472  b        #0x832b8
static inline uint64_t fde_func_0869_0x0da0f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da0f0ULL ^ (static_cast<uint64_t>(0x17fea472ULL) << 13);
    acc = (acc + a1 + 0x17febbafULL) ^ 0x042360ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0870 | PC: 0x0da0f4 | FDE: 0x042378 | Size: 4 bytes [_Z25JS_SetPropertyInternal_GCP12LEPUSContext10LEPUSValuejS1_i]
// Khung tháo gỡ #0870 | Địa chỉ PC: 0x0da0f4 | Địa chỉ FDE: 0x042378 | Kích thước: 4 bytes
//   0x0da0f4: 17FEBBAF  b        #0x88fb0
static inline uint64_t fde_func_0870_0x0da0f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da0f4ULL ^ (static_cast<uint64_t>(0x17febbafULL) << 13);
    acc = (acc + a1 + 0x37f800a2ULL) ^ 0x042378ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0871 | PC: 0x0da0f8 | FDE: 0x042390 | Size: 44 bytes [_Z23JS_SetPropertyUint32_GCP12LEPUSContext10LEPUSValuejS1_]
// Khung tháo gỡ #0871 | Địa chỉ PC: 0x0da0f8 | Địa chỉ FDE: 0x042390 | Kích thước: 44 bytes
//   0x0da0f8: 37F800A2  tbnz     w2, #0x1f, #0xda10c
//   0x0da0fc: 2A0203E8  mov      w8, w2
//   0x0da100: B24F3902  orr      x2, x8, #0xfffe000000000000
//   0x0da104: 52880004  mov      w4, #0x4000
static inline uint64_t fde_func_0871_0x0da0f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da0f8ULL ^ (static_cast<uint64_t>(0x37f800a2ULL) << 13);
    acc = (acc + a1 + 0x2a0203e8ULL) ^ 0x042390ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0872 | PC: 0x0da124 | FDE: 0x0423a8 | Size: 220 bytes [_Z20JS_SetPropertyStr_GCP12LEPUSContext10LEPUSValuePKcS1_]
// Khung tháo gỡ #0872 | Địa chỉ PC: 0x0da124 | Địa chỉ FDE: 0x0423a8 | Kích thước: 220 bytes
//   0x0da124: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x0da128: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0da12c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0da130: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0872_0x0da124(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da124ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0423a8ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0873 | PC: 0x0da200 | FDE: 0x0423d0 | Size: 236 bytes
// Khung tháo gỡ #0873 | Địa chỉ PC: 0x0da200 | Địa chỉ FDE: 0x0423d0 | Kích thước: 236 bytes
//   0x0da200: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x0da204: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x0da208: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0da20c: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0873_0x0da200(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da200ULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x0423d0ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0874 | PC: 0x0da2ec | FDE: 0x0423f8 | Size: 244 bytes [_Z28JS_DefinePropertyValueStr_GCP12LEPUSContext10LEPUSValuePKcS1_i]
// Khung tháo gỡ #0874 | Địa chỉ PC: 0x0da2ec | Địa chỉ FDE: 0x0423f8 | Kích thước: 244 bytes
//   0x0da2ec: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x0da2f0: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x0da2f4: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0da2f8: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0874_0x0da2ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da2ecULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x0423f8ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #0875 | PC: 0x0da3e0 | FDE: 0x042420 | Size: 28 bytes [_Z26JS_DefinePropertyGetSet_GCP12LEPUSContext10LEPUSValuejS1_S1_i]
// Khung tháo gỡ #0875 | Địa chỉ PC: 0x0da3e0 | Địa chỉ FDE: 0x042420 | Kích thước: 28 bytes
//   0x0da3e0: AA0403E8  mov      x8, x4
//   0x0da3e4: 5283A009  mov      w9, #0x1d00
//   0x0da3e8: AA0303E4  mov      x4, x3
//   0x0da3ec: 2A0900A6  orr      w6, w5, w9
static inline uint64_t fde_func_0875_0x0da3e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da3e0ULL ^ (static_cast<uint64_t>(0xaa0403e8ULL) << 13);
    acc = (acc + a1 + 0x5283a009ULL) ^ 0x042420ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0876 | PC: 0x0da3fc | FDE: 0x042438 | Size: 256 bytes [_Z22JS_DefineObjectName_GCP12LEPUSContext10LEPUSValueji]
// Khung tháo gỡ #0876 | Địa chỉ PC: 0x0da3fc | Địa chỉ FDE: 0x042438 | Kích thước: 256 bytes
//   0x0da3fc: D10283FF  sub      sp, sp, #0xa0
//   0x0da400: F9002BFA  str      x26, [sp, #0x50]
//   0x0da404: A90663F9  stp      x25, x24, [sp, #0x60]
//   0x0da408: A9075BF7  stp      x23, x22, [sp, #0x70]
static inline uint64_t fde_func_0876_0x0da3fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da3fcULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9002bfaULL) ^ 0x042438ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0877 | PC: 0x0da620 | FDE: 0x042460 | Size: 256 bytes
// Khung tháo gỡ #0877 | Địa chỉ PC: 0x0da620 | Địa chỉ FDE: 0x042460 | Kích thước: 256 bytes
//   0x0da620: D10183FF  sub      sp, sp, #0x60
//   0x0da624: F9000BFA  str      x26, [sp, #0x10]
//   0x0da628: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x0da62c: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_0877_0x0da620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da620ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfaULL) ^ 0x042460ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0878 | PC: 0x0da8b0 | FDE: 0x042488 | Size: 104 bytes
// Khung tháo gỡ #0878 | Địa chỉ PC: 0x0da8b0 | Địa chỉ FDE: 0x042488 | Kích thước: 104 bytes
//   0x0da8b0: D101C3FF  sub      sp, sp, #0x70
//   0x0da8b4: F9002BF4  str      x20, [sp, #0x50]
//   0x0da8b8: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x0da8bc: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0878_0x0da8b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da8b0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x042488ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0879 | PC: 0x0da918 | FDE: 0x0424a8 | Size: 256 bytes
// Khung tháo gỡ #0879 | Địa chỉ PC: 0x0da918 | Địa chỉ FDE: 0x0424a8 | Kích thước: 256 bytes
//   0x0da918: D101C3FF  sub      sp, sp, #0x70
//   0x0da91c: F9002BF4  str      x20, [sp, #0x50]
//   0x0da920: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x0da924: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0879_0x0da918(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da918ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x0424a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0880 | PC: 0x0daab0 | FDE: 0x0424c8 | Size: 256 bytes
// Khung tháo gỡ #0880 | Địa chỉ PC: 0x0daab0 | Địa chỉ FDE: 0x0424c8 | Kích thước: 256 bytes
//   0x0daab0: D10143FF  sub      sp, sp, #0x50
//   0x0daab4: F9000BF8  str      x24, [sp, #0x10]
//   0x0daab8: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0daabc: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0880_0x0daab0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0daab0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf8ULL) ^ 0x0424c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0881 | PC: 0x0dac34 | FDE: 0x0424f0 | Size: 148 bytes
// Khung tháo gỡ #0881 | Địa chỉ PC: 0x0dac34 | Địa chỉ FDE: 0x0424f0 | Kích thước: 148 bytes
//   0x0dac34: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0dac38: F0000709  adrp     x9, #0x1bd000
//   0x0dac3c: F9406408  ldr      x8, [x0, #0xc8]
//   0x0dac40: F940D929  ldr      x9, [x9, #0x1b0]
static inline uint64_t fde_func_0881_0x0dac34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dac34ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf0000709ULL) ^ 0x0424f0ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0882 | PC: 0x0dacc8 | FDE: 0x042508 | Size: 4 bytes [_Z18JS_GetGlobalVar_GCP12LEPUSContextji]
// Khung tháo gỡ #0882 | Địa chỉ PC: 0x0dacc8 | Địa chỉ FDE: 0x042508 | Kích thước: 4 bytes
//   0x0dacc8: 14000001  b        #0xdaccc
static inline uint64_t fde_func_0882_0x0dacc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dacc8ULL ^ (static_cast<uint64_t>(0x14000001ULL) << 13);
    acc = (acc + a1 + 0xd101c3ffULL) ^ 0x042508ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0883 | PC: 0x0daccc | FDE: 0x042520 | Size: 256 bytes
// Khung tháo gỡ #0883 | Địa chỉ PC: 0x0daccc | Địa chỉ FDE: 0x042520 | Kích thước: 256 bytes
//   0x0daccc: D101C3FF  sub      sp, sp, #0x70
//   0x0dacd0: F9002BF4  str      x20, [sp, #0x50]
//   0x0dacd4: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x0dacd8: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0883_0x0daccc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dacccULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x042520ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0884 | PC: 0x0dadd4 | FDE: 0x042540 | Size: 256 bytes
// Khung tháo gỡ #0884 | Địa chỉ PC: 0x0dadd4 | Địa chỉ FDE: 0x042540 | Kích thước: 256 bytes
//   0x0dadd4: D10203FF  sub      sp, sp, #0x80
//   0x0dadd8: F9002BF6  str      x22, [sp, #0x50]
//   0x0daddc: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x0dade0: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0884_0x0dadd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dadd4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf6ULL) ^ 0x042540ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0885 | PC: 0x0dafdc | FDE: 0x042560 | Size: 140 bytes
// Khung tháo gỡ #0885 | Địa chỉ PC: 0x0dafdc | Địa chỉ FDE: 0x042560 | Kích thước: 140 bytes
//   0x0dafdc: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0dafe0: F0000709  adrp     x9, #0x1bd000
//   0x0dafe4: F9406808  ldr      x8, [x0, #0xd0]
//   0x0dafe8: F940D929  ldr      x9, [x9, #0x1b0]
static inline uint64_t fde_func_0885_0x0dafdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dafdcULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf0000709ULL) ^ 0x042560ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0886 | PC: 0x0db068 | FDE: 0x042578 | Size: 256 bytes [_Z18JS_SetGlobalVar_GCP12LEPUSContextj10LEPUSValuei]
// Khung tháo gỡ #0886 | Địa chỉ PC: 0x0db068 | Địa chỉ FDE: 0x042578 | Kích thước: 256 bytes
//   0x0db068: D101C3FF  sub      sp, sp, #0x70
//   0x0db06c: F9002BF4  str      x20, [sp, #0x50]
//   0x0db070: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x0db074: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0886_0x0db068(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db068ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x042578ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0887 | PC: 0x0db1f0 | FDE: 0x042598 | Size: 76 bytes
// Khung tháo gỡ #0887 | Địa chỉ PC: 0x0db1f0 | Địa chỉ FDE: 0x042598 | Kích thước: 76 bytes
//   0x0db1f0: 2A1F03E0  mov      w0, wzr
//   0x0db1f4: B40001E1  cbz      x1, #0xdb230
//   0x0db1f8: D2800048  mov      x8, #2
//   0x0db1fc: F2FFFFE8  movk     x8, #0xffff, lsl #48
static inline uint64_t fde_func_0887_0x0db1f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db1f0ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xb40001e1ULL) ^ 0x042598ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0888 | PC: 0x0db23c | FDE: 0x0425b0 | Size: 4 bytes [_Z12JS_ToBool_GCP12LEPUSContext10LEPUSValue]
// Khung tháo gỡ #0888 | Địa chỉ PC: 0x0db23c | Địa chỉ FDE: 0x0425b0 | Kích thước: 4 bytes
//   0x0db23c: 17FE9F18  b        #0x82e9c
static inline uint64_t fde_func_0888_0x0db23c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db23cULL ^ (static_cast<uint64_t>(0x17fe9f18ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff4ULL) ^ 0x0425b0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0889 | PC: 0x0db240 | FDE: 0x0425c8 | Size: 96 bytes [_Z13JS_ToIndex_GCP12LEPUSContextPm10LEPUSValue]
// Khung tháo gỡ #0889 | Địa chỉ PC: 0x0db240 | Địa chỉ FDE: 0x0425c8 | Kích thước: 96 bytes
//   0x0db240: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0db244: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0db248: AA0103F3  mov      x19, x1
//   0x0db24c: 910023E1  add      x1, sp, #8
static inline uint64_t fde_func_0889_0x0db240(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db240ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0425c8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0890 | PC: 0x0db2a0 | FDE: 0x0425e8 | Size: 120 bytes [_Z20JS_SetStringCache_GCP12LEPUSContext10LEPUSValuePv]
// Khung tháo gỡ #0890 | Địa chỉ PC: 0x0db2a0 | Địa chỉ FDE: 0x0425e8 | Kích thước: 120 bytes
//   0x0db2a0: 92504428  and      x8, x1, #0xffff000000000003
//   0x0db2a4: B25047E9  mov      x9, #-0xfffffffffffd
//   0x0db2a8: EB09011F  cmp      x8, x9
//   0x0db2ac: 54000120  b.eq     #0xdb2d0
static inline uint64_t fde_func_0890_0x0db2a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db2a0ULL ^ (static_cast<uint64_t>(0x92504428ULL) << 13);
    acc = (acc + a1 + 0xb25047e9ULL) ^ 0x0425e8ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0891 | PC: 0x0db318 | FDE: 0x042600 | Size: 104 bytes [LEPUS_GetStringCache]
// Khung tháo gỡ #0891 | Địa chỉ PC: 0x0db318 | Địa chỉ FDE: 0x042600 | Kích thước: 104 bytes
//   0x0db318: 92504408  and      x8, x0, #0xffff000000000003
//   0x0db31c: B25047E9  mov      x9, #-0xfffffffffffd
//   0x0db320: EB09011F  cmp      x8, x9
//   0x0db324: 54000120  b.eq     #0xdb348
static inline uint64_t fde_func_0891_0x0db318(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db318ULL ^ (static_cast<uint64_t>(0x92504408ULL) << 13);
    acc = (acc + a1 + 0xb25047e9ULL) ^ 0x042600ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0892 | PC: 0x0db380 | FDE: 0x042618 | Size: 256 bytes
// Khung tháo gỡ #0892 | Địa chỉ PC: 0x0db380 | Địa chỉ FDE: 0x042618 | Kích thước: 256 bytes
//   0x0db380: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0db384: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0db388: AA0003F3  mov      x19, x0
//   0x0db38c: D371FC28  lsr      x8, x1, #0x31
static inline uint64_t fde_func_0892_0x0db380(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db380ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x042618ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0893 | PC: 0x0db5b8 | FDE: 0x042638 | Size: 256 bytes
// Khung tháo gỡ #0893 | Địa chỉ PC: 0x0db5b8 | Địa chỉ FDE: 0x042638 | Kích thước: 256 bytes
//   0x0db5b8: D10183FF  sub      sp, sp, #0x60
//   0x0db5bc: F9000BFA  str      x26, [sp, #0x10]
//   0x0db5c0: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x0db5c4: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_0893_0x0db5b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db5b8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfaULL) ^ 0x042638ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0894 | PC: 0x0db8b4 | FDE: 0x042660 | Size: 256 bytes
// Khung tháo gỡ #0894 | Địa chỉ PC: 0x0db8b4 | Địa chỉ FDE: 0x042660 | Kích thước: 256 bytes
//   0x0db8b4: D10203FF  sub      sp, sp, #0x80
//   0x0db8b8: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0db8bc: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0db8c0: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0894_0x0db8b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db8b4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x042660ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0895 | PC: 0x0dbbdc | FDE: 0x042690 | Size: 256 bytes
// Khung tháo gỡ #0895 | Địa chỉ PC: 0x0dbbdc | Địa chỉ FDE: 0x042690 | Kích thước: 256 bytes
//   0x0dbbdc: D10183FF  sub      sp, sp, #0x60
//   0x0dbbe0: F9000BFA  str      x26, [sp, #0x10]
//   0x0dbbe4: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x0dbbe8: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_0895_0x0dbbdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dbbdcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfaULL) ^ 0x042690ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0896 | PC: 0x0dbd18 | FDE: 0x0426b8 | Size: 256 bytes
// Khung tháo gỡ #0896 | Địa chỉ PC: 0x0dbd18 | Địa chỉ FDE: 0x0426b8 | Kích thước: 256 bytes
//   0x0dbd18: D102C3FF  sub      sp, sp, #0xb0
//   0x0dbd1c: F9002BFC  str      x28, [sp, #0x50]
//   0x0dbd20: A9066BFB  stp      x27, x26, [sp, #0x60]
//   0x0dbd24: A90763F9  stp      x25, x24, [sp, #0x70]
static inline uint64_t fde_func_0896_0x0dbd18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dbd18ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bfcULL) ^ 0x0426b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0897 | PC: 0x0dbef0 | FDE: 0x0426e8 | Size: 256 bytes
// Khung tháo gỡ #0897 | Địa chỉ PC: 0x0dbef0 | Địa chỉ FDE: 0x0426e8 | Kích thước: 256 bytes
//   0x0dbef0: D10183FF  sub      sp, sp, #0x60
//   0x0dbef4: F90013F8  str      x24, [sp, #0x20]
//   0x0dbef8: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0dbefc: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0897_0x0dbef0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dbef0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f8ULL) ^ 0x0426e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0898 | PC: 0x0dc040 | FDE: 0x042710 | Size: 120 bytes
// Khung tháo gỡ #0898 | Địa chỉ PC: 0x0dc040 | Địa chỉ FDE: 0x042710 | Kích thước: 120 bytes
//   0x0dc040: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0dc044: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0dc048: F9400808  ldr      x8, [x0, #0x10]
//   0x0dc04c: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0898_0x0dc040(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc040ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x042710ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0899 | PC: 0x0dc0b8 | FDE: 0x042730 | Size: 100 bytes [_Z10JS_Call_GCP12LEPUSContext10LEPUSValueS1_iPS1_]
// Khung tháo gỡ #0899 | Địa chỉ PC: 0x0dc0b8 | Địa chỉ FDE: 0x042730 | Kích thước: 100 bytes
//   0x0dc0b8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0dc0bc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0dc0c0: F9400808  ldr      x8, [x0, #0x10]
//   0x0dc0c4: F9418913  ldr      x19, [x8, #0x310]
static inline uint64_t fde_func_0899_0x0dc0b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc0b8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x042730ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0900 | PC: 0x0dc11c | FDE: 0x042750 | Size: 124 bytes
// Khung tháo gỡ #0900 | Địa chỉ PC: 0x0dc11c | Địa chỉ FDE: 0x042750 | Kích thước: 124 bytes
//   0x0dc11c: D10083FF  sub      sp, sp, #0x20
//   0x0dc120: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0dc124: AA0103F3  mov      x19, x1
//   0x0dc128: F85F8021  ldur     x1, [x1, #-8]
static inline uint64_t fde_func_0900_0x0dc11c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc11cULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x042750ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0901 | PC: 0x0dc198 | FDE: 0x042768 | Size: 256 bytes
// Khung tháo gỡ #0901 | Địa chỉ PC: 0x0dc198 | Địa chỉ FDE: 0x042768 | Kích thước: 256 bytes
//   0x0dc198: D10243FF  sub      sp, sp, #0x90
//   0x0dc19c: F9001BFC  str      x28, [sp, #0x30]
//   0x0dc1a0: A9046BFB  stp      x27, x26, [sp, #0x40]
//   0x0dc1a4: A90563F9  stp      x25, x24, [sp, #0x50]
static inline uint64_t fde_func_0901_0x0dc198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc198ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfcULL) ^ 0x042768ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0902 | PC: 0x0dc5e8 | FDE: 0x042798 | Size: 60 bytes [_Z20JS_CallInternalTI_GCP12LEPUSContext10LEPUSValueS1_S1_iPS1_i]
// Khung tháo gỡ #0902 | Địa chỉ PC: 0x0dc5e8 | Địa chỉ FDE: 0x042798 | Kích thước: 60 bytes
//   0x0dc5e8: F9400809  ldr      x9, [x0, #0x10]
//   0x0dc5ec: 3948612A  ldrb     w10, [x9, #0x218]
//   0x0dc5f0: 3400016A  cbz      w10, #0xdc61c
//   0x0dc5f4: B000070A  adrp     x10, #0x1bd000
static inline uint64_t fde_func_0902_0x0dc5e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc5e8ULL ^ (static_cast<uint64_t>(0xf9400809ULL) << 13);
    acc = (acc + a1 + 0x3948612aULL) ^ 0x042798ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0903 | PC: 0x0dc624 | FDE: 0x0427b0 | Size: 8 bytes [_Z22JS_CallConstructor2_GCP12LEPUSContext10LEPUSValueS1_iPS1_]
// Khung tháo gỡ #0903 | Địa chỉ PC: 0x0dc624 | Địa chỉ FDE: 0x0427b0 | Kích thước: 8 bytes
//   0x0dc624: 52800045  mov      w5, #2
//   0x0dc628: 17FEA7DA  b        #0x86590
static inline uint64_t fde_func_0903_0x0dc624(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc624ULL ^ (static_cast<uint64_t>(0x52800045ULL) << 13);
    acc = (acc + a1 + 0x17fea7daULL) ^ 0x0427b0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0904 | PC: 0x0dc62c | FDE: 0x0427c8 | Size: 20 bytes [_Z21JS_CallConstructor_GCP12LEPUSContext10LEPUSValueiPS1_]
// Khung tháo gỡ #0904 | Địa chỉ PC: 0x0dc62c | Địa chỉ FDE: 0x0427c8 | Kích thước: 20 bytes
//   0x0dc62c: AA0303E4  mov      x4, x3
//   0x0dc630: 2A0203E3  mov      w3, w2
//   0x0dc634: 52800045  mov      w5, #2
//   0x0dc638: AA0103E2  mov      x2, x1
static inline uint64_t fde_func_0904_0x0dc62c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc62cULL ^ (static_cast<uint64_t>(0xaa0303e4ULL) << 13);
    acc = (acc + a1 + 0x2a0203e3ULL) ^ 0x0427c8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0905 | PC: 0x0dc640 | FDE: 0x0427e0 | Size: 136 bytes [_Z12JS_Invoke_GCP12LEPUSContext10LEPUSValuejiPS1_]
// Khung tháo gỡ #0905 | Địa chỉ PC: 0x0dc640 | Địa chỉ FDE: 0x0427e0 | Kích thước: 136 bytes
//   0x0dc640: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0dc644: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0dc648: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0dc64c: AA0403F3  mov      x19, x4
static inline uint64_t fde_func_0905_0x0dc640(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc640ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0427e0ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0906 | PC: 0x0dc6c8 | FDE: 0x042800 | Size: 256 bytes
// Khung tháo gỡ #0906 | Địa chỉ PC: 0x0dc6c8 | Địa chỉ FDE: 0x042800 | Kích thước: 256 bytes
//   0x0dc6c8: D10283FF  sub      sp, sp, #0xa0
//   0x0dc6cc: A90663F9  stp      x25, x24, [sp, #0x60]
//   0x0dc6d0: A9075BF7  stp      x23, x22, [sp, #0x70]
//   0x0dc6d4: A90853F5  stp      x21, x20, [sp, #0x80]
static inline uint64_t fde_func_0906_0x0dc6c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc6c8ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa90663f9ULL) ^ 0x042800ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0907 | PC: 0x0dce7c | FDE: 0x042828 | Size: 12 bytes [_Z18JS_EvalFunction_GCP12LEPUSContext10LEPUSValueS1_]
// Khung tháo gỡ #0907 | Địa chỉ PC: 0x0dce7c | Địa chỉ FDE: 0x042828 | Kích thước: 12 bytes
//   0x0dce7c: AA1F03E3  mov      x3, xzr
//   0x0dce80: AA1F03E4  mov      x4, xzr
//   0x0dce84: 17FF6C81  b        #0xb8088
static inline uint64_t fde_func_0907_0x0dce7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dce7cULL ^ (static_cast<uint64_t>(0xaa1f03e3ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e4ULL) ^ 0x042828ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0908 | PC: 0x0dce88 | FDE: 0x042840 | Size: 92 bytes [_Z10JS_Eval_GCP12LEPUSContextPKcmS2_ii]
// Khung tháo gỡ #0908 | Địa chỉ PC: 0x0dce88 | Địa chỉ FDE: 0x042840 | Kích thước: 92 bytes
//   0x0dce88: D10083FF  sub      sp, sp, #0x20
//   0x0dce8c: F9000BFE  str      x30, [sp, #0x10]
//   0x0dce90: F9408009  ldr      x9, [x0, #0x100]
//   0x0dce94: B40001E9  cbz      x9, #0xdced0
static inline uint64_t fde_func_0908_0x0dce88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dce88ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfeULL) ^ 0x042840ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0909 | PC: 0x0dcee4 | FDE: 0x042858 | Size: 256 bytes [_Z16JS_EvalBinary_GCP12LEPUSContextPKhmi]
// Khung tháo gỡ #0909 | Địa chỉ PC: 0x0dcee4 | Địa chỉ FDE: 0x042858 | Kích thước: 256 bytes
//   0x0dcee4: D10103FF  sub      sp, sp, #0x40
//   0x0dcee8: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0dceec: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0dcef0: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0909_0x0dcee4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dcee4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x042858ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0910 | PC: 0x0dd010 | FDE: 0x042878 | Size: 8 bytes [_ZN11HandleScope27PushLEPUSPropertyDescriptorEP23LEPUSPropertyDescriptor]
// Khung tháo gỡ #0910 | Địa chỉ PC: 0x0dd010 | Địa chỉ FDE: 0x042878 | Kích thước: 8 bytes
//   0x0dd010: F9400000  ldr      x0, [x0]
//   0x0dd014: 17FF3CEC  b        #0xac3c4
static inline uint64_t fde_func_0910_0x0dd010(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd010ULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0x17ff3cecULL) ^ 0x042878ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0911 | PC: 0x0dd018 | FDE: 0x042890 | Size: 256 bytes [_Z15JS_DeepEqual_GCP12LEPUSContext10LEPUSValueS1_]
// Khung tháo gỡ #0911 | Địa chỉ PC: 0x0dd018 | Địa chỉ FDE: 0x042890 | Kích thước: 256 bytes
//   0x0dd018: D10243FF  sub      sp, sp, #0x90
//   0x0dd01c: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0dd020: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0dd024: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0911_0x0dd018(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd018ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x042890ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0912 | PC: 0x0dd53c | FDE: 0x0428c0 | Size: 256 bytes [_Z19JS_IterateObject_GCP12LEPUSContext10LEPUSValuePFvS0_S1_S1_PvS2_ES2_S2_]
// Khung tháo gỡ #0912 | Địa chỉ PC: 0x0dd53c | Địa chỉ FDE: 0x0428c0 | Kích thước: 256 bytes
//   0x0dd53c: D10303FF  sub      sp, sp, #0xc0
//   0x0dd540: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x0dd544: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x0dd548: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_0912_0x0dd53c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd53cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x0428c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0913 | PC: 0x0dd848 | FDE: 0x0428f0 | Size: 256 bytes [_Z15JS_GetLength_GCP12LEPUSContext10LEPUSValue]
// Khung tháo gỡ #0913 | Địa chỉ PC: 0x0dd848 | Địa chỉ FDE: 0x0428f0 | Kích thước: 256 bytes
//   0x0dd848: D10083FF  sub      sp, sp, #0x20
//   0x0dd84c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0dd850: AA0003F3  mov      x19, x0
//   0x0dd854: D371FC28  lsr      x8, x1, #0x31
static inline uint64_t fde_func_0913_0x0dd848(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd848ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0428f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0914 | PC: 0x0dd9a8 | FDE: 0x042908 | Size: 80 bytes
// Khung tháo gỡ #0914 | Địa chỉ PC: 0x0dd9a8 | Địa chỉ FDE: 0x042908 | Kích thước: 80 bytes
//   0x0dd9a8: B4000201  cbz      x1, #0xdd9e8
//   0x0dd9ac: D2800048  mov      x8, #2
//   0x0dd9b0: F2FFFFE8  movk     x8, #0xffff, lsl #48
//   0x0dd9b4: 8A080028  and      x8, x1, x8
static inline uint64_t fde_func_0914_0x0dd9a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd9a8ULL ^ (static_cast<uint64_t>(0xb4000201ULL) << 13);
    acc = (acc + a1 + 0xd2800048ULL) ^ 0x042908ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0915 | PC: 0x0dd9f8 | FDE: 0x042920 | Size: 164 bytes [_ZN11HandleScope25PushLEPUSValueArrayHandleEP10LEPUSValueib]
// Khung tháo gỡ #0915 | Địa chỉ PC: 0x0dd9f8 | Địa chỉ FDE: 0x042920 | Kích thước: 164 bytes
//   0x0dd9f8: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x0dd9fc: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0dda00: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0dda04: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0915_0x0dd9f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd9f8ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x042920ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0916 | PC: 0x0dda9c | FDE: 0x042948 | Size: 16 bytes [lre_realloc]
// Khung tháo gỡ #0916 | Địa chỉ PC: 0x0dda9c | Địa chỉ FDE: 0x042948 | Kích thước: 16 bytes
//   0x0dda9c: F9400808  ldr      x8, [x0, #0x10]
//   0x0ddaa0: F9400904  ldr      x4, [x8, #0x10]
//   0x0ddaa4: 910D2100  add      x0, x8, #0x348
//   0x0ddaa8: D61F0080  br       x4
static inline uint64_t fde_func_0916_0x0dda9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dda9cULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xf9400904ULL) ^ 0x042948ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0917 | PC: 0x0ddaac | FDE: 0x042960 | Size: 16 bytes [_Z32JS_AddIntrinsicRegExpCompiler_GCP12LEPUSContext]
// Khung tháo gỡ #0917 | Địa chỉ PC: 0x0ddaac | Địa chỉ FDE: 0x042960 | Kích thước: 16 bytes
//   0x0ddaac: 90FFFEA8  adrp     x8, #0xb1000
//   0x0ddab0: 91262108  add      x8, x8, #0x988
//   0x0ddab4: F9007C08  str      x8, [x0, #0xf8]
//   0x0ddab8: D65F03C0  ret      
static inline uint64_t fde_func_0917_0x0ddaac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddaacULL ^ (static_cast<uint64_t>(0x90fffea8ULL) << 13);
    acc = (acc + a1 + 0x91262108ULL) ^ 0x042960ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0918 | PC: 0x0ddabc | FDE: 0x042978 | Size: 60 bytes [_Z39JS_MoveUnhandledRejectionToException_GCP12LEPUSContext]
// Khung tháo gỡ #0918 | Địa chỉ PC: 0x0ddabc | Địa chỉ FDE: 0x042978 | Kích thước: 60 bytes
//   0x0ddabc: F9400809  ldr      x9, [x0, #0x10]
//   0x0ddac0: F940D128  ldr      x8, [x9, #0x1a0]
//   0x0ddac4: 9106612A  add      x10, x9, #0x198
//   0x0ddac8: EB0A011F  cmp      x8, x10
static inline uint64_t fde_func_0918_0x0ddabc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddabcULL ^ (static_cast<uint64_t>(0xf9400809ULL) << 13);
    acc = (acc + a1 + 0xf940d128ULL) ^ 0x042978ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0919 | PC: 0x0ddaf8 | FDE: 0x042990 | Size: 8 bytes [_Z26JS_NewPromiseCapability_GCP12LEPUSContextP10LEPUSValue]
// Khung tháo gỡ #0919 | Địa chỉ PC: 0x0ddaf8 | Địa chỉ FDE: 0x042990 | Kích thước: 8 bytes
//   0x0ddaf8: 52800242  mov      w2, #0x12
//   0x0ddafc: 17FEE3BB  b        #0x969e8
static inline uint64_t fde_func_0919_0x0ddaf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddaf8ULL ^ (static_cast<uint64_t>(0x52800242ULL) << 13);
    acc = (acc + a1 + 0x17fee3bbULL) ^ 0x042990ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0920 | PC: 0x0ddb00 | FDE: 0x0429a8 | Size: 8 bytes [_Z14JS_StrictEq_GCP12LEPUSContext10LEPUSValueS1_]
// Khung tháo gỡ #0920 | Địa chỉ PC: 0x0ddb00 | Địa chỉ FDE: 0x0429a8 | Kích thước: 8 bytes
//   0x0ddb00: 2A1F03E3  mov      w3, wzr
//   0x0ddb04: 17FEA105  b        #0x85f18
static inline uint64_t fde_func_0920_0x0ddb00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddb00ULL ^ (static_cast<uint64_t>(0x2a1f03e3ULL) << 13);
    acc = (acc + a1 + 0x17fea105ULL) ^ 0x0429a8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0921 | PC: 0x0ddb08 | FDE: 0x0429c0 | Size: 8 bytes [_Z15JS_SameValue_GCP12LEPUSContext10LEPUSValueS1_]
// Khung tháo gỡ #0921 | Địa chỉ PC: 0x0ddb08 | Địa chỉ FDE: 0x0429c0 | Kích thước: 8 bytes
//   0x0ddb08: 52800023  mov      w3, #1
//   0x0ddb0c: 17FEA103  b        #0x85f18
static inline uint64_t fde_func_0921_0x0ddb08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddb08ULL ^ (static_cast<uint64_t>(0x52800023ULL) << 13);
    acc = (acc + a1 + 0x17fea103ULL) ^ 0x0429c0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0922 | PC: 0x0ddb10 | FDE: 0x0429d8 | Size: 40 bytes [_Z20JS_NewArrayBuffer_GCP12LEPUSContextPhmPFvP12LEPUSRuntimePvS4_ES4_i]
// Khung tháo gỡ #0922 | Địa chỉ PC: 0x0ddb10 | Địa chỉ FDE: 0x0429d8 | Kích thước: 40 bytes
//   0x0ddb10: AA0303E8  mov      x8, x3
//   0x0ddb14: 710000BF  cmp      w5, #0
//   0x0ddb18: 52800269  mov      w9, #0x13
//   0x0ddb1c: AA0403E6  mov      x6, x4
static inline uint64_t fde_func_0922_0x0ddb10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddb10ULL ^ (static_cast<uint64_t>(0xaa0303e8ULL) << 13);
    acc = (acc + a1 + 0x710000bfULL) ^ 0x0429d8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0923 | PC: 0x0ddb38 | FDE: 0x0429f0 | Size: 28 bytes [_Z24JS_NewArrayBufferCopy_GCP12LEPUSContextPKhm]
// Khung tháo gỡ #0923 | Địa chỉ PC: 0x0ddb38 | Địa chỉ FDE: 0x0429f0 | Kích thước: 28 bytes
//   0x0ddb38: AA0103E4  mov      x4, x1
//   0x0ddb3c: 52800241  mov      w1, #0x12
//   0x0ddb40: 52800263  mov      w3, #0x13
//   0x0ddb44: 52800027  mov      w7, #1
static inline uint64_t fde_func_0923_0x0ddb38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddb38ULL ^ (static_cast<uint64_t>(0xaa0103e4ULL) << 13);
    acc = (acc + a1 + 0x52800241ULL) ^ 0x0429f0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0924 | PC: 0x0ddb54 | FDE: 0x042a08 | Size: 184 bytes [_Z23JS_DetachArrayBuffer_GCP12LEPUSContext10LEPUSValue]
// Khung tháo gỡ #0924 | Địa chỉ PC: 0x0ddb54 | Địa chỉ FDE: 0x042a08 | Kích thước: 184 bytes
//   0x0ddb54: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0ddb58: B4000421  cbz      x1, #0xddbdc
//   0x0ddb5c: D2800048  mov      x8, #2
//   0x0ddb60: F2FFFFE8  movk     x8, #0xffff, lsl #48
static inline uint64_t fde_func_0924_0x0ddb54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddb54ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb4000421ULL) ^ 0x042a08ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0925 | PC: 0x0ddc0c | FDE: 0x042a20 | Size: 224 bytes [_Z20JS_GetArrayBuffer_GCP12LEPUSContextPm10LEPUSValue]
// Khung tháo gỡ #0925 | Địa chỉ PC: 0x0ddc0c | Địa chỉ FDE: 0x042a20 | Kích thước: 224 bytes
//   0x0ddc0c: D101C3FF  sub      sp, sp, #0x70
//   0x0ddc10: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x0ddc14: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x0ddc18: D53BD055  mrs      x21, tpidr_el0
static inline uint64_t fde_func_0925_0x0ddc0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddc0cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90553f5ULL) ^ 0x042a20ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #0926 | PC: 0x0ddcec | FDE: 0x042a40 | Size: 256 bytes [_Z21JS_MoveArrayBuffer_GCP12LEPUSContextPm10LEPUSValue]
// Khung tháo gỡ #0926 | Địa chỉ PC: 0x0ddcec | Địa chỉ FDE: 0x042a40 | Kích thước: 256 bytes
//   0x0ddcec: D10203FF  sub      sp, sp, #0x80
//   0x0ddcf0: F9002BF6  str      x22, [sp, #0x50]
//   0x0ddcf4: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x0ddcf8: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0926_0x0ddcec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddcecULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf6ULL) ^ 0x042a40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0927 | PC: 0x0dde6c | FDE: 0x042a60 | Size: 196 bytes [_Z16JS_NewWString_GCP12LEPUSContextPKtm]
// Khung tháo gỡ #0927 | Địa chỉ PC: 0x0dde6c | Địa chỉ FDE: 0x042a60 | Kích thước: 196 bytes
//   0x0dde6c: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x0dde70: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0dde74: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0dde78: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_0927_0x0dde6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dde6cULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x042a60ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0928 | PC: 0x0ddf30 | FDE: 0x042a80 | Size: 100 bytes [_Z20JS_GetStringChars_GCP12LEPUSContext10LEPUSValue]
// Khung tháo gỡ #0928 | Địa chỉ PC: 0x0ddf30 | Địa chỉ FDE: 0x042a80 | Kích thước: 100 bytes
//   0x0ddf30: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0ddf34: AA2103E8  mvn      x8, x1
//   0x0ddf38: F250451F  tst      x8, #-0xfffffffffffd
//   0x0ddf3c: 54000061  b.ne     #0xddf48
static inline uint64_t fde_func_0928_0x0ddf30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddf30ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xaa2103e8ULL) ^ 0x042a80ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0929 | PC: 0x0ddf94 | FDE: 0x042a98 | Size: 96 bytes [_Z14JS_DeepCopy_GCP12LEPUSContext10LEPUSValue]
// Khung tháo gỡ #0929 | Địa chỉ PC: 0x0ddf94 | Địa chỉ FDE: 0x042a98 | Kích thước: 96 bytes
//   0x0ddf94: D10103FF  sub      sp, sp, #0x40
//   0x0ddf98: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0ddf9c: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x0ddfa0: D53BD055  mrs      x21, tpidr_el0
static inline uint64_t fde_func_0929_0x0ddf94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddf94ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x042a98ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0930 | PC: 0x0ddff4 | FDE: 0x042ab8 | Size: 256 bytes
// Khung tháo gỡ #0930 | Địa chỉ PC: 0x0ddff4 | Địa chỉ FDE: 0x042ab8 | Kích thước: 256 bytes
//   0x0ddff4: D10183FF  sub      sp, sp, #0x60
//   0x0ddff8: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0ddffc: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x0de000: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0930_0x0ddff4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddff4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9035bf7ULL) ^ 0x042ab8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0931 | PC: 0x0de134 | FDE: 0x042ad8 | Size: 8 bytes
// Khung tháo gỡ #0931 | Địa chỉ PC: 0x0de134 | Địa chỉ FDE: 0x042ad8 | Kích thước: 8 bytes
//   0x0de134: F8216802  str      x2, [x0, x1]
//   0x0de138: D65F03C0  ret      
static inline uint64_t fde_func_0931_0x0de134(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de134ULL ^ (static_cast<uint64_t>(0xf8216802ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x042ad8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0932 | PC: 0x0de13c | FDE: 0x042af0 | Size: 64 bytes [_ZN9Finalizer14close_var_refsEP15LEPUSStackFrame]
// Khung tháo gỡ #0932 | Địa chỉ PC: 0x0de13c | Địa chỉ FDE: 0x042af0 | Kích thước: 64 bytes
//   0x0de13c: F9401429  ldr      x9, [x1, #0x28]
//   0x0de140: 91008028  add      x8, x1, #0x20
//   0x0de144: EB08013F  cmp      x9, x8
//   0x0de148: 54000180  b.eq     #0xde178
static inline uint64_t fde_func_0932_0x0de13c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de13cULL ^ (static_cast<uint64_t>(0xf9401429ULL) << 13);
    acc = (acc + a1 + 0x91008028ULL) ^ 0x042af0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0933 | PC: 0x0de17c | FDE: 0x042b08 | Size: 64 bytes
// Khung tháo gỡ #0933 | Địa chỉ PC: 0x0de17c | Địa chỉ FDE: 0x042b08 | Kích thước: 64 bytes
//   0x0de17c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0de180: 2A2203E8  mvn      w8, w2
//   0x0de184: 128000E9  mov      w9, #-8
//   0x0de188: 321E7508  orr      w8, w8, #0xfffffffc
static inline uint64_t fde_func_0933_0x0de17c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de17cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x2a2203e8ULL) ^ 0x042b08ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0934 | PC: 0x0de1bc | FDE: 0x042b20 | Size: 256 bytes
// Khung tháo gỡ #0934 | Địa chỉ PC: 0x0de1bc | Địa chỉ FDE: 0x042b20 | Kích thước: 256 bytes
//   0x0de1bc: D10243FF  sub      sp, sp, #0x90
//   0x0de1c0: A90563F9  stp      x25, x24, [sp, #0x50]
//   0x0de1c4: A9065BF7  stp      x23, x22, [sp, #0x60]
//   0x0de1c8: A90753F5  stp      x21, x20, [sp, #0x70]
static inline uint64_t fde_func_0934_0x0de1bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de1bcULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90563f9ULL) ^ 0x042b20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0935 | PC: 0x0de41c | FDE: 0x042b48 | Size: 256 bytes
// Khung tháo gỡ #0935 | Địa chỉ PC: 0x0de41c | Địa chỉ FDE: 0x042b48 | Kích thước: 256 bytes
//   0x0de41c: D10243FF  sub      sp, sp, #0x90
//   0x0de420: F9001BFC  str      x28, [sp, #0x30]
//   0x0de424: A9046BFB  stp      x27, x26, [sp, #0x40]
//   0x0de428: A90563F9  stp      x25, x24, [sp, #0x50]
static inline uint64_t fde_func_0935_0x0de41c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de41cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfcULL) ^ 0x042b48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0936 | PC: 0x0de920 | FDE: 0x042b78 | Size: 56 bytes
// Khung tháo gỡ #0936 | Địa chỉ PC: 0x0de920 | Địa chỉ FDE: 0x042b78 | Kích thước: 56 bytes
//   0x0de920: F85F8028  ldur     x8, [x1, #-8]
//   0x0de924: D2801EE9  mov      x9, #0xf7
//   0x0de928: 91002020  add      x0, x1, #8
//   0x0de92c: F2FFFFE9  movk     x9, #0xffff, lsl #48
static inline uint64_t fde_func_0936_0x0de920(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de920ULL ^ (static_cast<uint64_t>(0xf85f8028ULL) << 13);
    acc = (acc + a1 + 0xd2801ee9ULL) ^ 0x042b78ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0937 | PC: 0x0de958 | FDE: 0x042b90 | Size: 256 bytes
// Khung tháo gỡ #0937 | Địa chỉ PC: 0x0de958 | Địa chỉ FDE: 0x042b90 | Kích thước: 256 bytes
//   0x0de958: D10103FF  sub      sp, sp, #0x40
//   0x0de95c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0de960: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0de964: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0937_0x0de958(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de958ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x042b90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0938 | PC: 0x0deaa0 | FDE: 0x042bb0 | Size: 256 bytes
// Khung tháo gỡ #0938 | Địa chỉ PC: 0x0deaa0 | Địa chỉ FDE: 0x042bb0 | Kích thước: 256 bytes
//   0x0deaa0: D10103FF  sub      sp, sp, #0x40
//   0x0deaa4: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0deaa8: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0deaac: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0938_0x0deaa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0deaa0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x042bb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0939 | PC: 0x0dec18 | FDE: 0x042bd0 | Size: 96 bytes
// Khung tháo gỡ #0939 | Địa chỉ PC: 0x0dec18 | Địa chỉ FDE: 0x042bd0 | Kích thước: 96 bytes
//   0x0dec18: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0dec1c: AA0003F3  mov      x19, x0
//   0x0dec20: 97FE89D3  bl       #0x8136c
//   0x0dec24: F102081F  cmp      x0, #0x82
static inline uint64_t fde_func_0939_0x0dec18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dec18ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x042bd0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0940 | PC: 0x0dec78 | FDE: 0x042be8 | Size: 256 bytes
// Khung tháo gỡ #0940 | Địa chỉ PC: 0x0dec78 | Địa chỉ FDE: 0x042be8 | Kích thước: 256 bytes
//   0x0dec78: D10183FF  sub      sp, sp, #0x60
//   0x0dec7c: F90013F8  str      x24, [sp, #0x20]
//   0x0dec80: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0dec84: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0940_0x0dec78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dec78ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f8ULL) ^ 0x042be8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0941 | PC: 0x0df078 | FDE: 0x042c10 | Size: 256 bytes
// Khung tháo gỡ #0941 | Địa chỉ PC: 0x0df078 | Địa chỉ FDE: 0x042c10 | Kích thước: 256 bytes
//   0x0df078: D101C3FF  sub      sp, sp, #0x70
//   0x0df07c: FD0013E8  str      d8, [sp, #0x20]
//   0x0df080: F90017FA  str      x26, [sp, #0x28]
//   0x0df084: A90363F9  stp      x25, x24, [sp, #0x30]
static inline uint64_t fde_func_0941_0x0df078(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df078ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xfd0013e8ULL) ^ 0x042c10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0942 | PC: 0x0df830 | FDE: 0x042c40 | Size: 256 bytes
// Khung tháo gỡ #0942 | Địa chỉ PC: 0x0df830 | Địa chỉ FDE: 0x042c40 | Kích thước: 256 bytes
//   0x0df830: D10183FF  sub      sp, sp, #0x60
//   0x0df834: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x0df838: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0df83c: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0942_0x0df830(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df830ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90263f9ULL) ^ 0x042c40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0943 | PC: 0x0dfa04 | FDE: 0x042c68 | Size: 256 bytes
// Khung tháo gỡ #0943 | Địa chỉ PC: 0x0dfa04 | Địa chỉ FDE: 0x042c68 | Kích thước: 256 bytes
//   0x0dfa04: D10243FF  sub      sp, sp, #0x90
//   0x0dfa08: FD0013EA  str      d10, [sp, #0x20]
//   0x0dfa0c: 6D0323E9  stp      d9, d8, [sp, #0x30]
//   0x0dfa10: A9046BFB  stp      x27, x26, [sp, #0x40]
static inline uint64_t fde_func_0943_0x0dfa04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dfa04ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xfd0013eaULL) ^ 0x042c68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0944 | PC: 0x0e01fc | FDE: 0x042ca0 | Size: 4 bytes
// Khung tháo gỡ #0944 | Địa chỉ PC: 0x0e01fc | Địa chỉ FDE: 0x042ca0 | Kích thước: 4 bytes
//   0x0e01fc: 140342FD  b        #0x1b0df0
static inline uint64_t fde_func_0944_0x0e01fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e01fcULL ^ (static_cast<uint64_t>(0x140342fdULL) << 13);
    acc = (acc + a1 + 0xd10183ffULL) ^ 0x042ca0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0945 | PC: 0x0e0200 | FDE: 0x042cb8 | Size: 256 bytes
// Khung tháo gỡ #0945 | Địa chỉ PC: 0x0e0200 | Địa chỉ FDE: 0x042cb8 | Kích thước: 256 bytes
//   0x0e0200: D10183FF  sub      sp, sp, #0x60
//   0x0e0204: F90013F8  str      x24, [sp, #0x20]
//   0x0e0208: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0e020c: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0945_0x0e0200(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e0200ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f8ULL) ^ 0x042cb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0946 | PC: 0x0e0540 | FDE: 0x042ce0 | Size: 256 bytes
// Khung tháo gỡ #0946 | Địa chỉ PC: 0x0e0540 | Địa chỉ FDE: 0x042ce0 | Kích thước: 256 bytes
//   0x0e0540: D10143FF  sub      sp, sp, #0x50
//   0x0e0544: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0e0548: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x0e054c: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0946_0x0e0540(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e0540ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x042ce0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0947 | PC: 0x0e06fc | FDE: 0x042d00 | Size: 256 bytes
// Khung tháo gỡ #0947 | Địa chỉ PC: 0x0e06fc | Địa chỉ FDE: 0x042d00 | Kích thước: 256 bytes
//   0x0e06fc: D101C3FF  sub      sp, sp, #0x70
//   0x0e0700: A9026BFB  stp      x27, x26, [sp, #0x20]
//   0x0e0704: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x0e0708: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_0947_0x0e06fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e06fcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9026bfbULL) ^ 0x042d00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0948 | PC: 0x0e0dd8 | FDE: 0x042d28 | Size: 256 bytes
// Khung tháo gỡ #0948 | Địa chỉ PC: 0x0e0dd8 | Địa chỉ FDE: 0x042d28 | Kích thước: 256 bytes
//   0x0e0dd8: D10203FF  sub      sp, sp, #0x80
//   0x0e0ddc: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0e0de0: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0e0de4: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0948_0x0e0dd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e0dd8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x042d28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0949 | PC: 0x0e14cc | FDE: 0x042d58 | Size: 36 bytes
// Khung tháo gỡ #0949 | Địa chỉ PC: 0x0e14cc | Địa chỉ FDE: 0x042d58 | Kích thước: 36 bytes
//   0x0e14cc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e14d0: 2A0303F3  mov      w19, w3
//   0x0e14d4: 2A1F03E3  mov      w3, wzr
//   0x0e14d8: 97FE9290  bl       #0x85f18
static inline uint64_t fde_func_0949_0x0e14cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e14ccULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x2a0303f3ULL) ^ 0x042d58ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0950 | PC: 0x0e14f0 | FDE: 0x042d70 | Size: 44 bytes
// Khung tháo gỡ #0950 | Địa chỉ PC: 0x0e14f0 | Địa chỉ FDE: 0x042d70 | Kích thước: 44 bytes
//   0x0e14f0: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0e14f4: 97FFD30D  bl       #0xd6128
//   0x0e14f8: 37F800C0  tbnz     w0, #0x1f, #0xe1510
//   0x0e14fc: 7100001F  cmp      w0, #0
static inline uint64_t fde_func_0950_0x0e14f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e14f0ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x97ffd30dULL) ^ 0x042d70ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0951 | PC: 0x0e151c | FDE: 0x042d88 | Size: 256 bytes
// Khung tháo gỡ #0951 | Địa chỉ PC: 0x0e151c | Địa chỉ FDE: 0x042d88 | Kích thước: 256 bytes
//   0x0e151c: D10143FF  sub      sp, sp, #0x50
//   0x0e1520: F9000BF8  str      x24, [sp, #0x10]
//   0x0e1524: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0e1528: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0951_0x0e151c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e151cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf8ULL) ^ 0x042d88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0952 | PC: 0x0e161c | FDE: 0x042db0 | Size: 256 bytes
// Khung tháo gỡ #0952 | Địa chỉ PC: 0x0e161c | Địa chỉ FDE: 0x042db0 | Kích thước: 256 bytes
//   0x0e161c: D10483FF  sub      sp, sp, #0x120
//   0x0e1620: F90073FC  str      x28, [sp, #0xe0]
//   0x0e1624: A90F5BF7  stp      x23, x22, [sp, #0xf0]
//   0x0e1628: A91053F5  stp      x21, x20, [sp, #0x100]
static inline uint64_t fde_func_0952_0x0e161c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e161cULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf90073fcULL) ^ 0x042db0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0953 | PC: 0x0e183c | FDE: 0x042dd8 | Size: 228 bytes
// Khung tháo gỡ #0953 | Địa chỉ PC: 0x0e183c | Địa chỉ FDE: 0x042dd8 | Kích thước: 228 bytes
//   0x0e183c: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x0e1840: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0e1844: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0e1848: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0953_0x0e183c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e183cULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x042dd8ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0954 | PC: 0x0e1920 | FDE: 0x042e00 | Size: 20 bytes [_ZN11HandleScopeC1EP12LEPUSRuntime]
// Khung tháo gỡ #0954 | Địa chỉ PC: 0x0e1920 | Địa chỉ FDE: 0x042e00 | Kích thước: 20 bytes
//   0x0e1920: F9418828  ldr      x8, [x1, #0x310]
//   0x0e1924: F9000008  str      x8, [x0]
//   0x0e1928: B9400108  ldr      w8, [x8]
//   0x0e192c: B9000808  str      w8, [x0, #8]
static inline uint64_t fde_func_0954_0x0e1920(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1920ULL ^ (static_cast<uint64_t>(0xf9418828ULL) << 13);
    acc = (acc + a1 + 0xf9000008ULL) ^ 0x042e00ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0955 | PC: 0x0e1934 | FDE: 0x042e18 | Size: 24 bytes [_ZN11HandleScopeC2EP12LEPUSContext]
// Khung tháo gỡ #0955 | Địa chỉ PC: 0x0e1934 | Địa chỉ FDE: 0x042e18 | Kích thước: 24 bytes
//   0x0e1934: F9400828  ldr      x8, [x1, #0x10]
//   0x0e1938: F9418908  ldr      x8, [x8, #0x310]
//   0x0e193c: F9000008  str      x8, [x0]
//   0x0e1940: B9400108  ldr      w8, [x8]
static inline uint64_t fde_func_0955_0x0e1934(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1934ULL ^ (static_cast<uint64_t>(0xf9400828ULL) << 13);
    acc = (acc + a1 + 0xf9418908ULL) ^ 0x042e18ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0956 | PC: 0x0e194c | FDE: 0x042e30 | Size: 120 bytes [_ZN11HandleScopeC2EP12LEPUSContextPv10HandleType]
// Khung tháo gỡ #0956 | Địa chỉ PC: 0x0e194c | Địa chỉ FDE: 0x042e30 | Kích thước: 120 bytes
//   0x0e194c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0e1950: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e1954: F9400828  ldr      x8, [x1, #0x10]
//   0x0e1958: 2A0303F3  mov      w19, w3
static inline uint64_t fde_func_0956_0x0e194c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e194cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x042e30ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0957 | PC: 0x0e19c4 | FDE: 0x042e50 | Size: 104 bytes [_ZN10PtrHandles10PushHandleEPv10HandleType]
// Khung tháo gỡ #0957 | Địa chỉ PC: 0x0e19c4 | Địa chỉ FDE: 0x042e50 | Kích thước: 104 bytes
//   0x0e19c4: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0e19c8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e19cc: 29402408  ldp      w8, w9, [x0]
//   0x0e19d0: 2A0203F4  mov      w20, w2
static inline uint64_t fde_func_0957_0x0e19c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e19c4ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x042e50ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0958 | PC: 0x0e1a2c | FDE: 0x042e70 | Size: 16 bytes [_ZN11HandleScopeD1Ev]
// Khung tháo gỡ #0958 | Địa chỉ PC: 0x0e1a2c | Địa chỉ FDE: 0x042e70 | Kích thước: 16 bytes
//   0x0e1a2c: F9400008  ldr      x8, [x0]
//   0x0e1a30: B9400809  ldr      w9, [x0, #8]
//   0x0e1a34: B9000109  str      w9, [x8]
//   0x0e1a38: D65F03C0  ret      
static inline uint64_t fde_func_0958_0x0e1a2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1a2cULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xb9400809ULL) ^ 0x042e70ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0959 | PC: 0x0e1a3c | FDE: 0x042e88 | Size: 120 bytes [_ZN10PtrHandles13PushLEPUSAtomEj]
// Khung tháo gỡ #0959 | Địa chỉ PC: 0x0e1a3c | Địa chỉ FDE: 0x042e88 | Kích thước: 120 bytes
//   0x0e1a3c: 71032C3F  cmp      w1, #0xcb
//   0x0e1a40: 5400030B  b.lt     #0xe1aa0
//   0x0e1a44: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0e1a48: A9017BF3  stp      x19, x30, [sp, #0x10]
static inline uint64_t fde_func_0959_0x0e1a3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1a3cULL ^ (static_cast<uint64_t>(0x71032c3fULL) << 13);
    acc = (acc + a1 + 0x5400030bULL) ^ 0x042e88ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0960 | PC: 0x0e1ab4 | FDE: 0x042ea8 | Size: 164 bytes [_ZN10PtrHandles25PushLEPUSValueArrayHandleEP10LEPUSValueib]
// Khung tháo gỡ #0960 | Địa chỉ PC: 0x0e1ab4 | Địa chỉ FDE: 0x042ea8 | Kích thước: 164 bytes
//   0x0e1ab4: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x0e1ab8: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0e1abc: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0e1ac0: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0960_0x0e1ab4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1ab4ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x042ea8ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0961 | PC: 0x0e1b58 | FDE: 0x042ed0 | Size: 96 bytes [_ZN11HandleScope11ResetHandleEPv10HandleType]
// Khung tháo gỡ #0961 | Địa chỉ PC: 0x0e1b58 | Địa chỉ FDE: 0x042ed0 | Kích thước: 96 bytes
//   0x0e1b58: F9400008  ldr      x8, [x0]
//   0x0e1b5c: B9800109  ldrsw    x9, [x8]
//   0x0e1b60: 7100053F  cmp      w9, #1
//   0x0e1b64: 5400028B  b.lt     #0xe1bb4
static inline uint64_t fde_func_0961_0x0e1b58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1b58ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xb9800109ULL) ^ 0x042ed0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0962 | PC: 0x0e1bb8 | FDE: 0x042ee8 | Size: 92 bytes [_ZN10PtrHandles11ResetHandleEPv10HandleType]
// Khung tháo gỡ #0962 | Địa chỉ PC: 0x0e1bb8 | Địa chỉ FDE: 0x042ee8 | Kích thước: 92 bytes
//   0x0e1bb8: B9800008  ldrsw    x8, [x0]
//   0x0e1bbc: 7100051F  cmp      w8, #1
//   0x0e1bc0: 5400028B  b.lt     #0xe1c10
//   0x0e1bc4: F940040A  ldr      x10, [x0, #8]
static inline uint64_t fde_func_0962_0x0e1bb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1bb8ULL ^ (static_cast<uint64_t>(0xb9800008ULL) << 13);
    acc = (acc + a1 + 0x7100051fULL) ^ 0x042ee8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0963 | PC: 0x0e1c14 | FDE: 0x042f00 | Size: 168 bytes [LEPUS_PushHandle]
// Khung tháo gỡ #0963 | Địa chỉ PC: 0x0e1c14 | Địa chỉ FDE: 0x042f00 | Kích thước: 168 bytes
//   0x0e1c14: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0e1c18: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e1c1c: AA0103F3  mov      x19, x1
//   0x0e1c20: 7100085F  cmp      w2, #2
static inline uint64_t fde_func_0963_0x0e1c14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1c14ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x042f00ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #0964 | PC: 0x0e1cbc | FDE: 0x042f20 | Size: 188 bytes [LEPUS_ResetHandle]
// Khung tháo gỡ #0964 | Địa chỉ PC: 0x0e1cbc | Địa chỉ FDE: 0x042f20 | Kích thước: 188 bytes
//   0x0e1cbc: 7100085F  cmp      w2, #2
//   0x0e1cc0: 540002C0  b.eq     #0xe1d18
//   0x0e1cc4: 7100045F  cmp      w2, #1
//   0x0e1cc8: 54000561  b.ne     #0xe1d74
static inline uint64_t fde_func_0964_0x0e1cbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1cbcULL ^ (static_cast<uint64_t>(0x7100085fULL) << 13);
    acc = (acc + a1 + 0x540002c0ULL) ^ 0x042f20ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0965 | PC: 0x0e1d78 | FDE: 0x042f38 | Size: 20 bytes [_Z15gc_info_enabledv]
// Khung tháo gỡ #0965 | Địa chỉ PC: 0x0e1d78 | Địa chỉ FDE: 0x042f38 | Kích thước: 20 bytes
//   0x0e1d78: 900006E8  adrp     x8, #0x1bd000
//   0x0e1d7c: F9410D08  ldr      x8, [x8, #0x218]
//   0x0e1d80: 39400108  ldrb     w8, [x8]
//   0x0e1d84: 53020900  ubfx     w0, w8, #2, #1
static inline uint64_t fde_func_0965_0x0e1d78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1d78ULL ^ (static_cast<uint64_t>(0x900006e8ULL) << 13);
    acc = (acc + a1 + 0xf9410d08ULL) ^ 0x042f38ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0966 | PC: 0x0e1d8c | FDE: 0x042f50 | Size: 20 bytes [_Z24lepusng_stragety_enabledv]
// Khung tháo gỡ #0966 | Địa chỉ PC: 0x0e1d8c | Địa chỉ FDE: 0x042f50 | Kích thước: 20 bytes
//   0x0e1d8c: 900006E8  adrp     x8, #0x1bd000
//   0x0e1d90: F9410D08  ldr      x8, [x8, #0x218]
//   0x0e1d94: 39400508  ldrb     w8, [x8, #1]
//   0x0e1d98: 53030D00  ubfx     w0, w8, #3, #1
static inline uint64_t fde_func_0966_0x0e1d8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1d8cULL ^ (static_cast<uint64_t>(0x900006e8ULL) << 13);
    acc = (acc + a1 + 0xf9410d08ULL) ^ 0x042f50ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0967 | PC: 0x0e1da0 | FDE: 0x042f68 | Size: 8 bytes [_ZN16GarbageCollector15MarkLiveObjectsEv]
// Khung tháo gỡ #0967 | Địa chỉ PC: 0x0e1da0 | Địa chỉ FDE: 0x042f68 | Kích thước: 8 bytes
//   0x0e1da0: F9400C00  ldr      x0, [x0, #0x18]
//   0x0e1da4: 17FEA3D6  b        #0x8acfc
static inline uint64_t fde_func_0967_0x0e1da0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1da0ULL ^ (static_cast<uint64_t>(0xf9400c00ULL) << 13);
    acc = (acc + a1 + 0x17fea3d6ULL) ^ 0x042f68ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0968 | PC: 0x0e1da8 | FDE: 0x042f80 | Size: 236 bytes [_ZN16GarbageCollector16SweepDeadObjectsEv]
// Khung tháo gỡ #0968 | Địa chỉ PC: 0x0e1da8 | Địa chỉ FDE: 0x042f80 | Kích thước: 236 bytes
//   0x0e1da8: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0e1dac: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0e1db0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0e1db4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0968_0x0e1da8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1da8ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x042f80ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0969 | PC: 0x0e1e94 | FDE: 0x042fa0 | Size: 160 bytes [_ZN16GarbageCollector22UpdateNGFootprintLimitEm]
// Khung tháo gỡ #0969 | Địa chỉ PC: 0x0e1e94 | Địa chỉ FDE: 0x042fa0 | Kích thước: 160 bytes
//   0x0e1e94: F9400408  ldr      x8, [x0, #8]
//   0x0e1e98: F9401809  ldr      x9, [x0, #0x30]
//   0x0e1e9c: 12B0000B  mov      w11, #0x7fffffff
//   0x0e1ea0: F942190A  ldr      x10, [x8, #0x430]
static inline uint64_t fde_func_0969_0x0e1e94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1e94ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf9401809ULL) ^ 0x042fa0ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0970 | PC: 0x0e1f34 | FDE: 0x042fb8 | Size: 116 bytes [_ZN7Visitor11PushObjAtomEji]
// Khung tháo gỡ #0970 | Địa chỉ PC: 0x0e1f34 | Địa chỉ FDE: 0x042fb8 | Kích thước: 116 bytes
//   0x0e1f34: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0e1f38: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e1f3c: 71032C3F  cmp      w1, #0xcb
//   0x0e1f40: 540002EB  b.lt     #0xe1f9c
static inline uint64_t fde_func_0970_0x0e1f34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1f34ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x042fb8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0971 | PC: 0x0e1fa8 | FDE: 0x042fd8 | Size: 152 bytes [_ZN7Visitor22VisitRootBCReaderStateEP13BCReaderStatei]
// Khung tháo gỡ #0971 | Địa chỉ PC: 0x0e1fa8 | Địa chỉ FDE: 0x042fd8 | Kích thước: 152 bytes
//   0x0e1fa8: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x0e1fac: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0e1fb0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0e1fb4: AA0103F5  mov      x21, x1
static inline uint64_t fde_func_0971_0x0e1fa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1fa8ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x042fd8ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0972 | PC: 0x0e2040 | FDE: 0x042ff8 | Size: 140 bytes [_ZN7Visitor20VisitRootValueBufferEP11ValueBufferi]
// Khung tháo gỡ #0972 | Địa chỉ PC: 0x0e2040 | Địa chỉ FDE: 0x042ff8 | Kích thước: 140 bytes
//   0x0e2040: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x0e2044: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0e2048: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0e204c: B9403028  ldr      w8, [x1, #0x30]
static inline uint64_t fde_func_0972_0x0e2040(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2040ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x042ff8ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0973 | PC: 0x0e20cc | FDE: 0x043018 | Size: 256 bytes [_ZN7Visitor23VisitRootHeapObjForTaskEP5QueuePv]
// Khung tháo gỡ #0973 | Địa chỉ PC: 0x0e20cc | Địa chỉ FDE: 0x043018 | Kích thước: 256 bytes
//   0x0e20cc: D10303FF  sub      sp, sp, #0xc0
//   0x0e20d0: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x0e20d4: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x0e20d8: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_0973_0x0e20cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e20ccULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x043018ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0974 | PC: 0x0e2448 | FDE: 0x043048 | Size: 52 bytes
// Khung tháo gỡ #0974 | Địa chỉ PC: 0x0e2448 | Địa chỉ FDE: 0x043048 | Kích thước: 52 bytes
//   0x0e2448: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e244c: AA0003F3  mov      x19, x0
//   0x0e2450: 52800400  mov      w0, #0x20
//   0x0e2454: 9403397F  bl       #0x1b0a50
static inline uint64_t fde_func_0974_0x0e2448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2448ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x043048ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0975 | PC: 0x0e247c | FDE: 0x043060 | Size: 32 bytes
// Khung tháo gỡ #0975 | Địa chỉ PC: 0x0e247c | Địa chỉ FDE: 0x043060 | Kích thước: 32 bytes
//   0x0e247c: B00006A8  adrp     x8, #0x1b7000
//   0x0e2480: 9139E108  add      x8, x8, #0xe78
//   0x0e2484: F9000028  str      x8, [x1]
//   0x0e2488: F9400C08  ldr      x8, [x0, #0x18]
static inline uint64_t fde_func_0975_0x0e247c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e247cULL ^ (static_cast<uint64_t>(0xb00006a8ULL) << 13);
    acc = (acc + a1 + 0x9139e108ULL) ^ 0x043060ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0976 | PC: 0x0e249c | FDE: 0x043078 | Size: 16 bytes
// Khung tháo gỡ #0976 | Địa chỉ PC: 0x0e249c | Địa chỉ FDE: 0x043078 | Kích thước: 16 bytes
//   0x0e249c: A9408408  ldp      x8, x1, [x0, #8]
//   0x0e24a0: F9400C02  ldr      x2, [x0, #0x18]
//   0x0e24a4: AA0803E0  mov      x0, x8
//   0x0e24a8: 17FFFF09  b        #0xe20cc
static inline uint64_t fde_func_0976_0x0e249c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e249cULL ^ (static_cast<uint64_t>(0xa9408408ULL) << 13);
    acc = (acc + a1 + 0xf9400c02ULL) ^ 0x043078ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0977 | PC: 0x0e24ac | FDE: 0x043090 | Size: 28 bytes
// Khung tháo gỡ #0977 | Địa chỉ PC: 0x0e24ac | Địa chỉ FDE: 0x043090 | Kích thước: 28 bytes
//   0x0e24ac: F9400428  ldr      x8, [x1, #8]
//   0x0e24b0: 90FFFAA9  adrp     x9, #0x36000
//   0x0e24b4: 91124D29  add      x9, x9, #0x493
//   0x0e24b8: 9100200A  add      x10, x0, #8
static inline uint64_t fde_func_0977_0x0e24ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e24acULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0x90fffaa9ULL) ^ 0x043090ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0978 | PC: 0x0e24c8 | FDE: 0x0430a8 | Size: 12 bytes
// Khung tháo gỡ #0978 | Địa chỉ PC: 0x0e24c8 | Địa chỉ FDE: 0x0430a8 | Kích thước: 12 bytes
//   0x0e24c8: B00006A0  adrp     x0, #0x1b7000
//   0x0e24cc: 913B6000  add      x0, x0, #0xed8
//   0x0e24d0: D65F03C0  ret      
static inline uint64_t fde_func_0978_0x0e24c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e24c8ULL ^ (static_cast<uint64_t>(0xb00006a0ULL) << 13);
    acc = (acc + a1 + 0x913b6000ULL) ^ 0x0430a8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0979 | PC: 0x0e24d4 | FDE: 0x0430c0 | Size: 32 bytes [_Z13set_mark_funcP12LEPUSRuntime10LEPUSValuem]
// Khung tháo gỡ #0979 | Địa chỉ PC: 0x0e24d4 | Địa chỉ FDE: 0x0430c0 | Kích thước: 32 bytes
//   0x0e24d4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0e24d8: F90007E1  str      x1, [sp, #8]
//   0x0e24dc: F9418C08  ldr      x8, [x0, #0x318]
//   0x0e24e0: 910023E1  add      x1, sp, #8
static inline uint64_t fde_func_0979_0x0e24d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e24d4ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf90007e1ULL) ^ 0x0430c0ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0980 | PC: 0x0e24f4 | FDE: 0x0430d8 | Size: 28 bytes [_ZN7Visitor11VisitJSAtomEji]
// Khung tháo gỡ #0980 | Địa chỉ PC: 0x0e24f4 | Địa chỉ FDE: 0x0430d8 | Kích thước: 28 bytes
//   0x0e24f4: 71032C3F  cmp      w1, #0xcb
//   0x0e24f8: 540000AB  b.lt     #0xe250c
//   0x0e24fc: F9400008  ldr      x8, [x0]
//   0x0e2500: F9402108  ldr      x8, [x8, #0x40]
static inline uint64_t fde_func_0980_0x0e24f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e24f4ULL ^ (static_cast<uint64_t>(0x71032c3fULL) << 13);
    acc = (acc + a1 + 0x540000abULL) ^ 0x0430d8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0981 | PC: 0x0e2510 | FDE: 0x0430f0 | Size: 52 bytes [_ZN7Visitor27PushObjJSAsyncFunctionStateEP20JSAsyncFunctionStatei]
// Khung tháo gỡ #0981 | Địa chỉ PC: 0x0e2510 | Địa chỉ FDE: 0x0430f0 | Kích thước: 52 bytes
//   0x0e2510: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0e2514: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e2518: AA0103F4  mov      x20, x1
//   0x0e251c: 91004021  add      x1, x1, #0x10
static inline uint64_t fde_func_0981_0x0e2510(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2510ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0430f0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0982 | PC: 0x0e2544 | FDE: 0x043110 | Size: 248 bytes [_ZN7Visitor18PushObjJStackFrameEP15LEPUSStackFramei]
// Khung tháo gỡ #0982 | Địa chỉ PC: 0x0e2544 | Địa chỉ FDE: 0x043110 | Kích thước: 248 bytes
//   0x0e2544: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x0e2548: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0e254c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0e2550: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_0982_0x0e2544(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2544ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x043110ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0983 | PC: 0x0e263c | FDE: 0x043130 | Size: 256 bytes [_ZN7Visitor17PushBytecodeAtomsEPKhiii]
// Khung tháo gỡ #0983 | Địa chỉ PC: 0x0e263c | Địa chỉ FDE: 0x043130 | Kích thước: 256 bytes
//   0x0e263c: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x0e2640: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x0e2644: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x0e2648: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_0983_0x0e263c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e263cULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x043130ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0984 | PC: 0x0e2744 | FDE: 0x043160 | Size: 188 bytes [_ZN7Visitor15PushObjJSRegExpEP8JSRegExpi]
// Khung tháo gỡ #0984 | Địa chỉ PC: 0x0e2744 | Địa chỉ FDE: 0x043160 | Kích thước: 188 bytes
//   0x0e2744: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0e2748: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0e274c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0e2750: 8B22CC15  add      x21, x0, w2, sxtw #3
static inline uint64_t fde_func_0984_0x0e2744(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2744ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x043160ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0985 | PC: 0x0e2800 | FDE: 0x043180 | Size: 256 bytes [_ZN7Visitor11PushObjFuncEP11LEPUSObjecti]
// Khung tháo gỡ #0985 | Địa chỉ PC: 0x0e2800 | Địa chỉ FDE: 0x043180 | Kích thước: 256 bytes
//   0x0e2800: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x0e2804: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x0e2808: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0e280c: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0985_0x0e2800(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2800ULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x043180ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0986 | PC: 0x0e29ac | FDE: 0x0431a8 | Size: 212 bytes [_ZN7Visitor12PushObjArrayEP11LEPUSObjecti]
// Khung tháo gỡ #0986 | Địa chỉ PC: 0x0e29ac | Địa chỉ FDE: 0x0431a8 | Kích thước: 212 bytes
//   0x0e29ac: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x0e29b0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0e29b4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0e29b8: F9401C36  ldr      x22, [x1, #0x38]
static inline uint64_t fde_func_0986_0x0e29ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e29acULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0431a8ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0987 | PC: 0x0e2a80 | FDE: 0x0431c8 | Size: 188 bytes [_ZN7Visitor13PushObjRegExpEP11LEPUSObjecti]
// Khung tháo gỡ #0987 | Địa chỉ PC: 0x0e2a80 | Địa chỉ FDE: 0x0431c8 | Kích thước: 188 bytes
//   0x0e2a80: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0e2a84: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0e2a88: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0e2a8c: 8B22CC15  add      x21, x0, w2, sxtw #3
static inline uint64_t fde_func_0987_0x0e2a80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2a80ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0431c8ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0988 | PC: 0x0e2b3c | FDE: 0x0431e8 | Size: 256 bytes [_ZN7Visitor15PushObjPropertyEP10JSPropertyii]
// Khung tháo gỡ #0988 | Địa chỉ PC: 0x0e2b3c | Địa chỉ FDE: 0x0431e8 | Kích thước: 256 bytes
//   0x0e2b3c: 721C0448  ands     w8, w2, #0x30
//   0x0e2b40: 54000061  b.ne     #0xe2b4c
//   0x0e2b44: 2A0303E2  mov      w2, w3
//   0x0e2b48: 17FEA863  b        #0x8ccd4
static inline uint64_t fde_func_0988_0x0e2b3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2b3cULL ^ (static_cast<uint64_t>(0x721c0448ULL) << 13);
    acc = (acc + a1 + 0x54000061ULL) ^ 0x0431e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0989 | PC: 0x0e2c84 | FDE: 0x043200 | Size: 256 bytes [_ZN7Visitor11VisitJShapeEPvi]
// Khung tháo gỡ #0989 | Địa chỉ PC: 0x0e2c84 | Địa chỉ FDE: 0x043200 | Kích thước: 256 bytes
//   0x0e2c84: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x0e2c88: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0e2c8c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0e2c90: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0989_0x0e2c84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2c84ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x043200ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0990 | PC: 0x0e2da8 | FDE: 0x043228 | Size: 256 bytes [_ZN7Visitor23VisitJSFunctionBytecodeEPvi]
// Khung tháo gỡ #0990 | Địa chỉ PC: 0x0e2da8 | Địa chỉ FDE: 0x043228 | Kích thước: 256 bytes
//   0x0e2da8: D101C3FF  sub      sp, sp, #0x70
//   0x0e2dac: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0e2db0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0e2db4: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0990_0x0e2da8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2da8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x043228ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0991 | PC: 0x0e3268 | FDE: 0x043258 | Size: 256 bytes [_ZN7Visitor13VisitJSObjectEPvi]
// Khung tháo gỡ #0991 | Địa chỉ PC: 0x0e3268 | Địa chỉ FDE: 0x043258 | Kích thước: 256 bytes
//   0x0e3268: D101C3FF  sub      sp, sp, #0x70
//   0x0e326c: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0e3270: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0e3274: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0991_0x0e3268(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3268ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x043258ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0992 | PC: 0x0e37d0 | FDE: 0x043288 | Size: 116 bytes [_ZN7Visitor20VisitJSBoundFunctionEPvi]
// Khung tháo gỡ #0992 | Địa chỉ PC: 0x0e37d0 | Địa chỉ FDE: 0x043288 | Kích thước: 116 bytes
//   0x0e37d0: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x0e37d4: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0e37d8: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0e37dc: 2A0203F3  mov      w19, w2
static inline uint64_t fde_func_0992_0x0e37d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e37d0ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x043288ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0993 | PC: 0x0e3844 | FDE: 0x0432a8 | Size: 92 bytes [_ZN7Visitor26VisitJSCFunctionDataRecordEPvi]
// Khung tháo gỡ #0993 | Địa chỉ PC: 0x0e3844 | Địa chỉ FDE: 0x0432a8 | Kích thước: 92 bytes
//   0x0e3844: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x0e3848: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0e384c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0e3850: 39402428  ldrb     w8, [x1, #9]
static inline uint64_t fde_func_0993_0x0e3844(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3844ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0432a8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0994 | PC: 0x0e38a0 | FDE: 0x0432c8 | Size: 108 bytes [_ZN7Visitor18VisitJSArrayBufferEPvi]
// Khung tháo gỡ #0994 | Địa chỉ PC: 0x0e38a0 | Địa chỉ FDE: 0x0432c8 | Kích thước: 108 bytes
//   0x0e38a0: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0e38a4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e38a8: B9403028  ldr      w8, [x1, #0x30]
//   0x0e38ac: 340002A8  cbz      w8, #0xe3900
static inline uint64_t fde_func_0994_0x0e38a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e38a0ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0432c8ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0995 | PC: 0x0e390c | FDE: 0x0432e8 | Size: 100 bytes [_ZN7Visitor17VisitJSTypedArrayEPvi]
// Khung tháo gỡ #0995 | Địa chỉ PC: 0x0e390c | Địa chỉ FDE: 0x0432e8 | Kích thước: 100 bytes
//   0x0e390c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0e3910: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e3914: F9400C34  ldr      x20, [x1, #0x18]
//   0x0e3918: B4000274  cbz      x20, #0xe3964
static inline uint64_t fde_func_0995_0x0e390c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e390cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0432e8ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0996 | PC: 0x0e3970 | FDE: 0x043308 | Size: 256 bytes [_ZN7Visitor15VisitJSMapStateEPvi]
// Khung tháo gỡ #0996 | Địa chỉ PC: 0x0e3970 | Địa chỉ FDE: 0x043308 | Kích thước: 256 bytes
//   0x0e3970: A9BB6BFB  stp      x27, x26, [sp, #-0x50]!
//   0x0e3974: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x0e3978: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0e397c: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0996_0x0e3970(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3970ULL ^ (static_cast<uint64_t>(0xa9bb6bfbULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x043308ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0997 | PC: 0x0e3aa8 | FDE: 0x043330 | Size: 132 bytes [_ZN7Visitor22VisitJSMapIteratorDataEPvi]
// Khung tháo gỡ #0997 | Địa chỉ PC: 0x0e3aa8 | Địa chỉ FDE: 0x043330 | Kích thước: 132 bytes
//   0x0e3aa8: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x0e3aac: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0e3ab0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0e3ab4: F9400837  ldr      x23, [x1, #0x10]
static inline uint64_t fde_func_0997_0x0e3aa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3aa8ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x043330ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0998 | PC: 0x0e3b2c | FDE: 0x043350 | Size: 48 bytes [_ZN7Visitor31VisitJSRegExpStringIteratorDataEPvi]
// Khung tháo gỡ #0998 | Địa chỉ PC: 0x0e3b2c | Địa chỉ FDE: 0x043350 | Kích thước: 48 bytes
//   0x0e3b2c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0e3b30: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e3b34: 2A0203F3  mov      w19, w2
//   0x0e3b38: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_0998_0x0e3b2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3b2cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x043350ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0999 | PC: 0x0e3b5c | FDE: 0x043370 | Size: 76 bytes [_ZN7Visitor20VisitJSGeneratorDataEPvi]
// Khung tháo gỡ #0999 | Địa chỉ PC: 0x0e3b5c | Địa chỉ FDE: 0x043370 | Kích thước: 76 bytes
//   0x0e3b5c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0e3b60: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e3b64: B9400028  ldr      w8, [x1]
//   0x0e3b68: 7100111F  cmp      w8, #4
static inline uint64_t fde_func_0999_0x0e3b5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3b5cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x043370ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1000 | PC: 0x0e3ba8 | FDE: 0x043390 | Size: 64 bytes [_ZN7Visitor16VisitJSProxyDataEPvi]
// Khung tháo gỡ #1000 | Địa chỉ PC: 0x0e3ba8 | Địa chỉ FDE: 0x043390 | Kích thước: 64 bytes
//   0x0e3ba8: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0e3bac: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e3bb0: 2A0203F3  mov      w19, w2
//   0x0e3bb4: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_1000_0x0e3ba8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3ba8ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x043390ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1001 | PC: 0x0e3be8 | FDE: 0x0433b0 | Size: 256 bytes [_ZN7Visitor18VisitJSPromiseDataEPvi]
// Khung tháo gỡ #1001 | Địa chỉ PC: 0x0e3be8 | Địa chỉ FDE: 0x0433b0 | Kích thước: 256 bytes
//   0x0e3be8: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x0e3bec: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x0e3bf0: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0e3bf4: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1001_0x0e3be8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3be8ULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x0433b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1002 | PC: 0x0e3d14 | FDE: 0x0433d8 | Size: 68 bytes [_ZN7Visitor26VisitJSPromiseReactionDataEPvi]
// Khung tháo gỡ #1002 | Địa chỉ PC: 0x0e3d14 | Địa chỉ FDE: 0x0433d8 | Kích thước: 68 bytes
//   0x0e3d14: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0e3d18: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e3d1c: AA0103F4  mov      x20, x1
//   0x0e3d20: 91004021  add      x1, x1, #0x10
static inline uint64_t fde_func_1002_0x0e3d14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3d14ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0433d8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1003 | PC: 0x0e3d58 | FDE: 0x0433f8 | Size: 132 bytes [_ZN7Visitor26VisitJSPromiseFunctionDataEPvi]
// Khung tháo gỡ #1003 | Địa chỉ PC: 0x0e3d58 | Địa chỉ FDE: 0x0433f8 | Kích thước: 132 bytes
//   0x0e3d58: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x0e3d5c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0e3d60: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0e3d64: F9400437  ldr      x23, [x1, #8]
static inline uint64_t fde_func_1003_0x0e3d58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3d58ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0433f8ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1004 | PC: 0x0e3ddc | FDE: 0x043418 | Size: 112 bytes [_ZN7Visitor24VisitJSAsyncFunctionDataEPvi]
// Khung tháo gỡ #1004 | Địa chỉ PC: 0x0e3ddc | Địa chỉ FDE: 0x043418 | Kích thước: 112 bytes
//   0x0e3ddc: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0e3de0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0e3de4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0e3de8: B9401828  ldr      w8, [x1, #0x18]
static inline uint64_t fde_func_1004_0x0e3ddc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3ddcULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x043418ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1005 | PC: 0x0e3e4c | FDE: 0x043438 | Size: 256 bytes [_ZN7Visitor25VisitJSAsyncGeneratorDataEPvi]
// Khung tháo gỡ #1005 | Địa chỉ PC: 0x0e3e4c | Địa chỉ FDE: 0x043438 | Kích thước: 256 bytes
//   0x0e3e4c: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x0e3e50: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x0e3e54: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0e3e58: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1005_0x0e3e4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3e4cULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x043438ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1006 | PC: 0x0e3f84 | FDE: 0x043460 | Size: 184 bytes [_ZN7Visitor19VisitJSPropertyEnumEPvi]
// Khung tháo gỡ #1006 | Địa chỉ PC: 0x0e3f84 | Địa chỉ FDE: 0x043460 | Kích thước: 184 bytes
//   0x0e3f84: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x0e3f88: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0e3f8c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0e3f90: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1006_0x0e3f84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3f84ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x043460ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1007 | PC: 0x0e403c | FDE: 0x043488 | Size: 256 bytes [_ZN7Visitor16VisitJSModuleDefEPvi]
// Khung tháo gỡ #1007 | Địa chỉ PC: 0x0e403c | Địa chỉ FDE: 0x043488 | Kích thước: 256 bytes
//   0x0e403c: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x0e4040: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x0e4044: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x0e4048: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1007_0x0e403c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e403cULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x043488ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1008 | PC: 0x0e44c4 | FDE: 0x0434b8 | Size: 256 bytes [_ZN7Visitor18VisitJSFunctionDefEPvi]
// Khung tháo gỡ #1008 | Địa chỉ PC: 0x0e44c4 | Địa chỉ FDE: 0x0434b8 | Kích thước: 256 bytes
//   0x0e44c4: D101C3FF  sub      sp, sp, #0x70
//   0x0e44c8: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0e44cc: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0e44d0: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1008_0x0e44c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e44c4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x0434b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1009 | PC: 0x0e4ea0 | FDE: 0x0434e8 | Size: 84 bytes [_ZN7Visitor17VisitJSValueArrayEPvi]
// Khung tháo gỡ #1009 | Địa chỉ PC: 0x0e4ea0 | Địa chỉ FDE: 0x0434e8 | Kích thước: 84 bytes
//   0x0e4ea0: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0e4ea4: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0e4ea8: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0e4eac: B85F8028  ldur     w8, [x1, #-8]
static inline uint64_t fde_func_1009_0x0e4ea0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4ea0ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0434e8ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1010 | PC: 0x0e4ef4 | FDE: 0x043508 | Size: 184 bytes [_ZN7Visitor14VisitValueSlotEPvi]
// Khung tháo gỡ #1010 | Địa chỉ PC: 0x0e4ef4 | Địa chỉ FDE: 0x043508 | Kích thước: 184 bytes
//   0x0e4ef4: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x0e4ef8: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0e4efc: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0e4f00: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1010_0x0e4ef4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4ef4ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x043508ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1011 | PC: 0x0e4fac | FDE: 0x043530 | Size: 104 bytes [_ZN7Visitor17VisitJsonStrArrayEPvi]
// Khung tháo gỡ #1011 | Địa chỉ PC: 0x0e4fac | Địa chỉ FDE: 0x043530 | Kích thước: 104 bytes
//   0x0e4fac: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0e4fb0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0e4fb4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0e4fb8: B85F8028  ldur     w8, [x1, #-8]
static inline uint64_t fde_func_1011_0x0e4fac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4facULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x043530ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1012 | PC: 0x0e5014 | FDE: 0x043550 | Size: 212 bytes [_ZN7Visitor29VisitFinalizationRegistryDataEPvi]
// Khung tháo gỡ #1012 | Địa chỉ PC: 0x0e5014 | Địa chỉ FDE: 0x043550 | Kích thước: 212 bytes
//   0x0e5014: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x0e5018: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0e501c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0e5020: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1012_0x0e5014(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5014ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x043550ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1013 | PC: 0x0e50e8 | FDE: 0x043578 | Size: 204 bytes [_ZN9Finalizer9free_atomEP12LEPUSRuntimeP8JSString]
// Khung tháo gỡ #1013 | Địa chỉ PC: 0x0e50e8 | Địa chỉ FDE: 0x043578 | Kích thước: 204 bytes
//   0x0e50e8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0e50ec: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e50f0: F9400840  ldr      x0, [x2, #0x10]
//   0x0e50f4: AA0203F4  mov      x20, x2
static inline uint64_t fde_func_1013_0x0e50e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e50e8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x043578ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1014 | PC: 0x0e51b4 | FDE: 0x043598 | Size: 28 bytes [_ZN9Finalizer19JSLepusRefFinalizerEPv]
// Khung tháo gỡ #1014 | Địa chỉ PC: 0x0e51b4 | Địa chỉ FDE: 0x043598 | Kích thước: 28 bytes
//   0x0e51b4: F9400000  ldr      x0, [x0]
//   0x0e51b8: F940E002  ldr      x2, [x0, #0x1c0]
//   0x0e51bc: B4000082  cbz      x2, #0xe51cc
//   0x0e51c0: 927EB428  and      x8, x1, #0xfffffffffffc
static inline uint64_t fde_func_1014_0x0e51b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e51b4ULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0xf940e002ULL) ^ 0x043598ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1015 | PC: 0x0e51d0 | FDE: 0x0435b0 | Size: 244 bytes [_ZN9Finalizer17JSStringFinalizerEPv]
// Khung tháo gỡ #1015 | Địa chỉ PC: 0x0e51d0 | Địa chỉ FDE: 0x0435b0 | Kích thước: 244 bytes
//   0x0e51d0: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0e51d4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e51d8: F8404028  ldur     x8, [x1, #4]
//   0x0e51dc: F9400014  ldr      x20, [x0]
static inline uint64_t fde_func_1015_0x0e51d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e51d0ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0435b0ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #1016 | PC: 0x0e52c4 | FDE: 0x0435d0 | Size: 52 bytes [_ZN9Finalizer21JSStringOnlyFinalizerEPv]
// Khung tháo gỡ #1016 | Địa chỉ PC: 0x0e52c4 | Địa chỉ FDE: 0x0435d0 | Kích thước: 52 bytes
//   0x0e52c4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e52c8: F9400828  ldr      x8, [x1, #0x10]
//   0x0e52cc: B4000128  cbz      x8, #0xe52f0
//   0x0e52d0: F9400009  ldr      x9, [x0]
static inline uint64_t fde_func_1016_0x0e52c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e52c4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400828ULL) ^ 0x0435d0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1017 | PC: 0x0e52f8 | FDE: 0x0435e8 | Size: 104 bytes [_ZN9Finalizer16JSShapeFinalizerEPv]
// Khung tháo gỡ #1017 | Địa chỉ PC: 0x0e52f8 | Địa chỉ FDE: 0x0435e8 | Kích thước: 104 bytes
//   0x0e52f8: B85F8028  ldur     w8, [x1, #-8]
//   0x0e52fc: 13067D08  asr      w8, w8, #6
//   0x0e5300: 8B28C828  add      x8, x1, w8, sxtw #2
//   0x0e5304: 39401509  ldrb     w9, [x8, #5]
static inline uint64_t fde_func_1017_0x0e52f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e52f8ULL ^ (static_cast<uint64_t>(0xb85f8028ULL) << 13);
    acc = (acc + a1 + 0x13067d08ULL) ^ 0x0435e8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1018 | PC: 0x0e5360 | FDE: 0x043600 | Size: 256 bytes [_ZN9Finalizer17JSObjectFinalizerEPv]
// Khung tháo gỡ #1018 | Địa chỉ PC: 0x0e5360 | Địa chỉ FDE: 0x043600 | Kích thước: 256 bytes
//   0x0e5360: A9BB6BFB  stp      x27, x26, [sp, #-0x50]!
//   0x0e5364: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x0e5368: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0e536c: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1018_0x0e5360(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5360ULL ^ (static_cast<uint64_t>(0xa9bb6bfbULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x043600ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1019 | PC: 0x0e5560 | FDE: 0x043628 | Size: 40 bytes [_ZN9Finalizer21JSObjectOnlyFinalizerEPv]
// Khung tháo gỡ #1019 | Địa chỉ PC: 0x0e5560 | Địa chỉ FDE: 0x043628 | Kích thước: 40 bytes
//   0x0e5560: F9400000  ldr      x0, [x0]
//   0x0e5564: 79400C29  ldrh     w9, [x1, #6]
//   0x0e5568: 5280050A  mov      w10, #0x28
//   0x0e556c: F9402808  ldr      x8, [x0, #0x50]
static inline uint64_t fde_func_1019_0x0e5560(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5560ULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0x79400c29ULL) ^ 0x043628ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1020 | PC: 0x0e5588 | FDE: 0x043640 | Size: 40 bytes [_ZN9Finalizer22JSArrayBufferFinalizerEPv]
// Khung tháo gỡ #1020 | Địa chỉ PC: 0x0e5588 | Địa chỉ FDE: 0x043640 | Kích thước: 40 bytes
//   0x0e5588: B9403028  ldr      w8, [x1, #0x30]
//   0x0e558c: 34000048  cbz      w8, #0xe5594
//   0x0e5590: D65F03C0  ret      
//   0x0e5594: F9401423  ldr      x3, [x1, #0x28]
static inline uint64_t fde_func_1020_0x0e5588(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5588ULL ^ (static_cast<uint64_t>(0xb9403028ULL) << 13);
    acc = (acc + a1 + 0x34000048ULL) ^ 0x043640ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1021 | PC: 0x0e55b0 | FDE: 0x043658 | Size: 60 bytes [_ZN9Finalizer21JSTypedArrayFinalizerEPv]
// Khung tháo gỡ #1021 | Địa chỉ PC: 0x0e55b0 | Địa chỉ FDE: 0x043658 | Kích thước: 60 bytes
//   0x0e55b0: B40001C1  cbz      x1, #0xe55e8
//   0x0e55b4: F9400C28  ldr      x8, [x1, #0x18]
//   0x0e55b8: F27EB508  ands     x8, x8, #0xfffffffffffc
//   0x0e55bc: 54000160  b.eq     #0xe55e8
static inline uint64_t fde_func_1021_0x0e55b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e55b0ULL ^ (static_cast<uint64_t>(0xb40001c1ULL) << 13);
    acc = (acc + a1 + 0xf9400c28ULL) ^ 0x043658ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1022 | PC: 0x0e55ec | FDE: 0x043670 | Size: 124 bytes [_ZN9Finalizer19JSMapStateFinalizerEPv]
// Khung tháo gỡ #1022 | Địa chỉ PC: 0x0e55ec | Địa chỉ FDE: 0x043670 | Kích thước: 124 bytes
//   0x0e55ec: F940082B  ldr      x11, [x1, #0x10]
//   0x0e55f0: 91002028  add      x8, x1, #8
//   0x0e55f4: EB08017F  cmp      x11, x8
//   0x0e55f8: 54000360  b.eq     #0xe5664
static inline uint64_t fde_func_1022_0x0e55ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e55ecULL ^ (static_cast<uint64_t>(0xf940082bULL) << 13);
    acc = (acc + a1 + 0x91002028ULL) ^ 0x043670ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1023 | PC: 0x0e5668 | FDE: 0x043688 | Size: 100 bytes [_ZN9Finalizer26JSMapIteratorDataFinalizerEPv]
// Khung tháo gỡ #1023 | Địa chỉ PC: 0x0e5668 | Địa chỉ FDE: 0x043688 | Kích thước: 100 bytes
//   0x0e5668: F9400028  ldr      x8, [x1]
//   0x0e566c: B4000248  cbz      x8, #0xe56b4
//   0x0e5670: D2800049  mov      x9, #2
//   0x0e5674: F2FFFFE9  movk     x9, #0xffff, lsl #48
static inline uint64_t fde_func_1023_0x0e5668(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5668ULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0xb4000248ULL) ^ 0x043688ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1024 | PC: 0x0e56cc | FDE: 0x0436a0 | Size: 84 bytes [_ZN9Finalizer24JSGeneratorDataFinalizerEPv]
// Khung tháo gỡ #1024 | Địa chỉ PC: 0x0e56cc | Địa chỉ FDE: 0x0436a0 | Kích thước: 84 bytes
//   0x0e56cc: B9400028  ldr      w8, [x1]
//   0x0e56d0: 7100111F  cmp      w8, #4
//   0x0e56d4: 54000240  b.eq     #0xe571c
//   0x0e56d8: F9402029  ldr      x9, [x1, #0x40]
static inline uint64_t fde_func_1024_0x0e56cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e56ccULL ^ (static_cast<uint64_t>(0xb9400028ULL) << 13);
    acc = (acc + a1 + 0x7100111fULL) ^ 0x0436a0ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1025 | PC: 0x0e5720 | FDE: 0x0436b8 | Size: 72 bytes [_ZN9Finalizer28JSAsyncFunctionDataFinalizerEPv]
// Khung tháo gỡ #1025 | Địa chỉ PC: 0x0e5720 | Địa chỉ FDE: 0x0436b8 | Kích thước: 72 bytes
//   0x0e5720: B9401828  ldr      w8, [x1, #0x18]
//   0x0e5724: 34000208  cbz      w8, #0xe5764
//   0x0e5728: F9402C29  ldr      x9, [x1, #0x58]
//   0x0e572c: 91014028  add      x8, x1, #0x50
static inline uint64_t fde_func_1025_0x0e5720(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5720ULL ^ (static_cast<uint64_t>(0xb9401828ULL) << 13);
    acc = (acc + a1 + 0x34000208ULL) ^ 0x0436b8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1026 | PC: 0x0e5768 | FDE: 0x0436d0 | Size: 80 bytes [_ZN9Finalizer29JSAsyncGeneratorDataFinalizerEPv]
// Khung tháo gỡ #1026 | Địa chỉ PC: 0x0e5768 | Địa chỉ FDE: 0x0436d0 | Kích thước: 80 bytes
//   0x0e5768: B9400828  ldr      w8, [x1, #8]
//   0x0e576c: 121F7908  and      w8, w8, #0xfffffffe
//   0x0e5770: 7100111F  cmp      w8, #4
//   0x0e5774: 54000200  b.eq     #0xe57b4
static inline uint64_t fde_func_1026_0x0e5768(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5768ULL ^ (static_cast<uint64_t>(0xb9400828ULL) << 13);
    acc = (acc + a1 + 0x121f7908ULL) ^ 0x0436d0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1027 | PC: 0x0e57b8 | FDE: 0x0436e8 | Size: 20 bytes [_ZN9Finalizer20JSModuleDefFinalizerEPv]
// Khung tháo gỡ #1027 | Địa chỉ PC: 0x0e57b8 | Địa chỉ FDE: 0x0436e8 | Kích thước: 20 bytes
//   0x0e57b8: A940A428  ldp      x8, x9, [x1, #8]
//   0x0e57bc: F9000509  str      x9, [x8, #8]
//   0x0e57c0: F9000128  str      x8, [x9]
//   0x0e57c4: A900FC3F  stp      xzr, xzr, [x1, #8]
static inline uint64_t fde_func_1027_0x0e57b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e57b8ULL ^ (static_cast<uint64_t>(0xa940a428ULL) << 13);
    acc = (acc + a1 + 0xf9000509ULL) ^ 0x0436e8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1028 | PC: 0x0e57cc | FDE: 0x043700 | Size: 52 bytes [_ZN9Finalizer22JSFunctionDefFinalizerEPv]
// Khung tháo gỡ #1028 | Địa chỉ PC: 0x0e57cc | Địa chỉ FDE: 0x043700 | Kích thước: 52 bytes
//   0x0e57cc: F9400428  ldr      x8, [x1, #8]
//   0x0e57d0: B4000108  cbz      x8, #0xe57f0
//   0x0e57d4: AA0103E8  mov      x8, x1
//   0x0e57d8: F8428D09  ldr      x9, [x8, #0x28]!
static inline uint64_t fde_func_1028_0x0e57cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e57ccULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0xb4000108ULL) ^ 0x043700ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1029 | PC: 0x0e5800 | FDE: 0x043718 | Size: 96 bytes [_ZN9Finalizer33FinalizationRegistryDataFinalizerEPv]
// Khung tháo gỡ #1029 | Địa chỉ PC: 0x0e5800 | Địa chỉ FDE: 0x043718 | Kích thước: 96 bytes
//   0x0e5800: B40002E1  cbz      x1, #0xe585c
//   0x0e5804: F9400828  ldr      x8, [x1, #0x10]
//   0x0e5808: 91002029  add      x9, x1, #8
//   0x0e580c: EB09011F  cmp      x8, x9
static inline uint64_t fde_func_1029_0x0e5800(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5800ULL ^ (static_cast<uint64_t>(0xb40002e1ULL) << 13);
    acc = (acc + a1 + 0xf9400828ULL) ^ 0x043718ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1030 | PC: 0x0e5860 | FDE: 0x043730 | Size: 84 bytes [_ZN9Finalizer20WeakRefDataFinalizerEPv]
// Khung tháo gỡ #1030 | Địa chỉ PC: 0x0e5860 | Địa chỉ FDE: 0x043730 | Kích thước: 84 bytes
//   0x0e5860: F9400028  ldr      x8, [x1]
//   0x0e5864: B4000268  cbz      x8, #0xe58b0
//   0x0e5868: D2800049  mov      x9, #2
//   0x0e586c: F2FFFFE9  movk     x9, #0xffff, lsl #48
static inline uint64_t fde_func_1030_0x0e5860(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5860ULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0xb4000268ULL) ^ 0x043730ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1031 | PC: 0x0e58b4 | FDE: 0x043748 | Size: 20 bytes [_Z12do_finalizerPvS_b]
// Khung tháo gỡ #1031 | Địa chỉ PC: 0x0e58b4 | Địa chỉ FDE: 0x043748 | Kích thước: 20 bytes
//   0x0e58b4: F9418C08  ldr      x8, [x0, #0x318]
//   0x0e58b8: F9401100  ldr      x0, [x8, #0x20]
//   0x0e58bc: 36000042  tbz      w2, #0, #0xe58c4
//   0x0e58c0: 17FE0F69  b        #0x69664
static inline uint64_t fde_func_1031_0x0e58b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e58b4ULL ^ (static_cast<uint64_t>(0xf9418c08ULL) << 13);
    acc = (acc + a1 + 0xf9401100ULL) ^ 0x043748ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1032 | PC: 0x0e58c8 | FDE: 0x043760 | Size: 256 bytes [_Z19do_global_finalizerPv]
// Khung tháo gỡ #1032 | Địa chỉ PC: 0x0e58c8 | Địa chỉ FDE: 0x043760 | Kích thước: 256 bytes
//   0x0e58c8: A9BB6BFB  stp      x27, x26, [sp, #-0x50]!
//   0x0e58cc: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x0e58d0: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0e58d4: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1032_0x0e58c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e58c8ULL ^ (static_cast<uint64_t>(0xa9bb6bfbULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x043760ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1033 | PC: 0x0e59dc | FDE: 0x043788 | Size: 152 bytes [LEPUS_GetGCTimingInfo]
// Khung tháo gỡ #1033 | Địa chỉ PC: 0x0e59dc | Địa chỉ FDE: 0x043788 | Kích thước: 152 bytes
//   0x0e59dc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e59e0: 39458008  ldrb     w8, [x0, #0x160]
//   0x0e59e4: 34000408  cbz      w8, #0xe5a64
//   0x0e59e8: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_1033_0x0e59dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e59dcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x39458008ULL) ^ 0x043788ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1034 | PC: 0x0e5a74 | FDE: 0x0437a0 | Size: 76 bytes [_Z16AddLepusRefCountP12LEPUSContext]
// Khung tháo gỡ #1034 | Địa chỉ PC: 0x0e5a74 | Địa chỉ FDE: 0x0437a0 | Kích thước: 76 bytes
//   0x0e5a74: F9400800  ldr      x0, [x0, #0x10]
//   0x0e5a78: 529175AA  mov      w10, #0x8bad
//   0x0e5a7c: 72AD1B6A  movk     w10, #0x68db, lsl #16
//   0x0e5a80: F9418C08  ldr      x8, [x0, #0x318]
static inline uint64_t fde_func_1034_0x0e5a74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5a74ULL ^ (static_cast<uint64_t>(0xf9400800ULL) << 13);
    acc = (acc + a1 + 0x529175aaULL) ^ 0x0437a0ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1035 | PC: 0x0e5ac0 | FDE: 0x0437b8 | Size: 44 bytes [_ZN10PtrHandlesC1EP12LEPUSRuntime]
// Khung tháo gỡ #1035 | Địa chỉ PC: 0x0e5ac0 | Địa chỉ FDE: 0x0437b8 | Kích thước: 44 bytes
//   0x0e5ac0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e5ac4: AA0003F3  mov      x19, x0
//   0x0e5ac8: F9000801  str      x1, [x0, #0x10]
//   0x0e5acc: 52810000  mov      w0, #0x800
static inline uint64_t fde_func_1035_0x0e5ac0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5ac0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0437b8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1036 | PC: 0x0e5aec | FDE: 0x0437d0 | Size: 40 bytes [_ZN10PtrHandles14InitialHandlesEv]
// Khung tháo gỡ #1036 | Địa chỉ PC: 0x0e5aec | Địa chỉ FDE: 0x0437d0 | Kích thước: 40 bytes
//   0x0e5aec: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e5af0: AA0003F3  mov      x19, x0
//   0x0e5af4: 52810000  mov      w0, #0x800
//   0x0e5af8: 94032BA2  bl       #0x1b0980
static inline uint64_t fde_func_1036_0x0e5aec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5aecULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0437d0ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1037 | PC: 0x0e5b14 | FDE: 0x0437e8 | Size: 16 bytes [_ZN10CheckToolsD1Ev]
// Khung tháo gỡ #1037 | Địa chỉ PC: 0x0e5b14 | Địa chỉ FDE: 0x0437e8 | Kích thước: 16 bytes
//   0x0e5b14: F9400400  ldr      x0, [x0, #8]
//   0x0e5b18: B4000040  cbz      x0, #0xe5b20
//   0x0e5b1c: 14032B95  b        #0x1b0970
//   0x0e5b20: D65F03C0  ret      
static inline uint64_t fde_func_1037_0x0e5b14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5b14ULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0xb4000040ULL) ^ 0x0437e8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1038 | PC: 0x0e5b24 | FDE: 0x043800 | Size: 40 bytes [_ZN10CheckToolsC1Ev]
// Khung tháo gỡ #1038 | Địa chỉ PC: 0x0e5b24 | Địa chỉ FDE: 0x043800 | Kích thước: 40 bytes
//   0x0e5b24: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e5b28: F0FFFA28  adrp     x8, #0x2c000
//   0x0e5b2c: FD464500  ldr      d0, [x8, #0xc88]
//   0x0e5b30: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1038_0x0e5b24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5b24ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf0fffa28ULL) ^ 0x043800ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1039 | PC: 0x0e5b4c | FDE: 0x043818 | Size: 140 bytes [_ZN10CheckTools7PushTidEi]
// Khung tháo gỡ #1039 | Địa chỉ PC: 0x0e5b4c | Địa chỉ FDE: 0x043818 | Kích thước: 140 bytes
//   0x0e5b4c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0e5b50: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e5b54: 29402408  ldp      w8, w9, [x0]
//   0x0e5b58: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1039_0x0e5b4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5b4cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x043818ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1040 | PC: 0x0e5bd8 | FDE: 0x043838 | Size: 56 bytes [_ZN10CheckTools10IsValidTidEi]
// Khung tháo gỡ #1040 | Địa chỉ PC: 0x0e5bd8 | Địa chỉ FDE: 0x043838 | Kích thước: 56 bytes
//   0x0e5bd8: B9800008  ldrsw    x8, [x0]
//   0x0e5bdc: 7100051F  cmp      w8, #1
//   0x0e5be0: 5400010B  b.lt     #0xe5c00
//   0x0e5be4: F9400409  ldr      x9, [x0, #8]
static inline uint64_t fde_func_1040_0x0e5bd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5bd8ULL ^ (static_cast<uint64_t>(0xb9800008ULL) << 13);
    acc = (acc + a1 + 0x7100051fULL) ^ 0x043838ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1041 | PC: 0x0e5c10 | FDE: 0x043850 | Size: 108 bytes [_ZN5QueueC2EPvi]
// Khung tháo gỡ #1041 | Địa chỉ PC: 0x0e5c10 | Địa chỉ FDE: 0x043850 | Kích thước: 108 bytes
//   0x0e5c10: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0e5c14: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e5c18: A900FC01  stp      x1, xzr, [x0, #8]
//   0x0e5c1c: B900181F  str      wzr, [x0, #0x18]
static inline uint64_t fde_func_1041_0x0e5c10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5c10ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x043850ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1042 | PC: 0x0e5c7c | FDE: 0x043870 | Size: 76 bytes [_ZN5QueueC1EPv]
// Khung tháo gỡ #1042 | Địa chỉ PC: 0x0e5c7c | Địa chỉ FDE: 0x043870 | Kích thước: 76 bytes
//   0x0e5c7c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e5c80: AA0003F3  mov      x19, x0
//   0x0e5c84: A900FC01  stp      x1, xzr, [x0, #8]
//   0x0e5c88: B900181F  str      wzr, [x0, #0x18]
static inline uint64_t fde_func_1042_0x0e5c7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5c7cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x043870ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1043 | PC: 0x0e5cc8 | FDE: 0x043888 | Size: 44 bytes [_ZN5QueueD1Ev]
// Khung tháo gỡ #1043 | Địa chỉ PC: 0x0e5cc8 | Địa chỉ FDE: 0x043888 | Kích thước: 44 bytes
//   0x0e5cc8: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0e5ccc: AA0003E8  mov      x8, x0
//   0x0e5cd0: F9400000  ldr      x0, [x0]
//   0x0e5cd4: B40000A0  cbz      x0, #0xe5ce8
static inline uint64_t fde_func_1043_0x0e5cc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5cc8ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x043888ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1044 | PC: 0x0e5cf4 | FDE: 0x0438a0 | Size: 16 bytes [_ZN5Queue7IsEmptyEv]
// Khung tháo gỡ #1044 | Địa chỉ PC: 0x0e5cf4 | Địa chỉ FDE: 0x0438a0 | Kích thước: 16 bytes
//   0x0e5cf4: B9401808  ldr      w8, [x0, #0x18]
//   0x0e5cf8: 7100011F  cmp      w8, #0
//   0x0e5cfc: 1A9F17E0  cset     w0, eq
//   0x0e5d00: D65F03C0  ret      
static inline uint64_t fde_func_1044_0x0e5cf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5cf4ULL ^ (static_cast<uint64_t>(0xb9401808ULL) << 13);
    acc = (acc + a1 + 0x7100011fULL) ^ 0x0438a0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1045 | PC: 0x0e5d04 | FDE: 0x0438b8 | Size: 20 bytes [_ZN5Queue6IsFullEv]
// Khung tháo gỡ #1045 | Địa chỉ PC: 0x0e5d04 | Địa chỉ FDE: 0x0438b8 | Kích thước: 20 bytes
//   0x0e5d04: 29432009  ldp      w9, w8, [x0, #0x18]
//   0x0e5d08: 51000508  sub      w8, w8, #1
//   0x0e5d0c: 6B08013F  cmp      w9, w8
//   0x0e5d10: 1A9F17E0  cset     w0, eq
static inline uint64_t fde_func_1045_0x0e5d04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5d04ULL ^ (static_cast<uint64_t>(0x29432009ULL) << 13);
    acc = (acc + a1 + 0x51000508ULL) ^ 0x0438b8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1046 | PC: 0x0e5d18 | FDE: 0x0438d0 | Size: 96 bytes [_ZN5Queue7EnQueueEPv]
// Khung tháo gỡ #1046 | Địa chỉ PC: 0x0e5d18 | Địa chỉ FDE: 0x0438d0 | Kích thước: 96 bytes
//   0x0e5d18: B40002E1  cbz      x1, #0xe5d74
//   0x0e5d1c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0e5d20: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e5d24: 29432009  ldp      w9, w8, [x0, #0x18]
static inline uint64_t fde_func_1046_0x0e5d18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5d18ULL ^ (static_cast<uint64_t>(0xb40002e1ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff4ULL) ^ 0x0438d0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1047 | PC: 0x0e5d78 | FDE: 0x0438f0 | Size: 220 bytes [_ZN5Queue11ResizeQueueEv]
// Khung tháo gỡ #1047 | Địa chỉ PC: 0x0e5d78 | Địa chỉ FDE: 0x0438f0 | Kích thước: 220 bytes
//   0x0e5d78: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0e5d7c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e5d80: B9801C15  ldrsw    x21, [x0, #0x1c]
//   0x0e5d84: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1047_0x0e5d78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5d78ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0438f0ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #1048 | PC: 0x0e5e54 | FDE: 0x043910 | Size: 84 bytes [_ZN5Queue7DeQueueEv]
// Khung tháo gỡ #1048 | Địa chỉ PC: 0x0e5e54 | Địa chỉ FDE: 0x043910 | Kích thước: 84 bytes
//   0x0e5e54: F9400008  ldr      x8, [x0]
//   0x0e5e58: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e5e5c: B940180A  ldr      w10, [x0, #0x18]
//   0x0e5e60: F8697908  ldr      x8, [x8, x9, lsl #3]
static inline uint64_t fde_func_1048_0x0e5e54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5e54ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x043910ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1049 | PC: 0x0e5ea8 | FDE: 0x043928 | Size: 16 bytes [_ZN5Queue5FrontEv]
// Khung tháo gỡ #1049 | Địa chỉ PC: 0x0e5ea8 | Địa chỉ FDE: 0x043928 | Kích thước: 16 bytes
//   0x0e5ea8: F9400008  ldr      x8, [x0]
//   0x0e5eac: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e5eb0: F8697900  ldr      x0, [x8, x9, lsl #3]
//   0x0e5eb4: D65F03C0  ret      
static inline uint64_t fde_func_1049_0x0e5ea8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5ea8ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x043928ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1050 | PC: 0x0e5eb8 | FDE: 0x043940 | Size: 164 bytes [VersionInit]
// Khung tháo gỡ #1050 | Địa chỉ PC: 0x0e5eb8 | Địa chỉ FDE: 0x043940 | Kích thước: 164 bytes
//   0x0e5eb8: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0e5ebc: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0e5ec0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0e5ec4: AA0003F5  mov      x21, x0
static inline uint64_t fde_func_1050_0x0e5eb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5eb8ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x043940ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1051 | PC: 0x0e5f5c | FDE: 0x043960 | Size: 160 bytes [VersionLessOrEqual]
// Khung tháo gỡ #1051 | Địa chỉ PC: 0x0e5f5c | Địa chỉ FDE: 0x043960 | Kích thước: 160 bytes
//   0x0e5f5c: D360FC28  lsr      x8, x1, #0x20
//   0x0e5f60: 6B02001F  cmp      w0, w2
//   0x0e5f64: D360FC69  lsr      x9, x3, #0x20
//   0x0e5f68: 54000161  b.ne     #0xe5f94
static inline uint64_t fde_func_1051_0x0e5f5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5f5cULL ^ (static_cast<uint64_t>(0xd360fc28ULL) << 13);
    acc = (acc + a1 + 0x6b02001fULL) ^ 0x043960ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1052 | PC: 0x0e5ffc | FDE: 0x043978 | Size: 256 bytes [IsHigherOrEqual]
// Khung tháo gỡ #1052 | Địa chỉ PC: 0x0e5ffc | Địa chỉ FDE: 0x043978 | Kích thước: 256 bytes
//   0x0e5ffc: D10143FF  sub      sp, sp, #0x50
//   0x0e6000: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x0e6004: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x0e6008: D53BD055  mrs      x21, tpidr_el0
static inline uint64_t fde_func_1052_0x0e5ffc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5ffcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90353f5ULL) ^ 0x043978ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1053 | PC: 0x0e61c8 | FDE: 0x043998 | Size: 256 bytes [_Z20js_std_dump_error_gcP12LEPUSContext]
// Khung tháo gỡ #1053 | Địa chỉ PC: 0x0e61c8 | Địa chỉ FDE: 0x043998 | Kích thước: 256 bytes
//   0x0e61c8: D10143FF  sub      sp, sp, #0x50
//   0x0e61cc: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0e61d0: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x0e61d4: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1053_0x0e61c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e61c8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x043998ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1054 | PC: 0x0e6368 | FDE: 0x0439b8 | Size: 208 bytes
// Khung tháo gỡ #1054 | Địa chỉ PC: 0x0e6368 | Địa chỉ FDE: 0x0439b8 | Kích thước: 208 bytes
//   0x0e6368: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0e636c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e6370: 39458008  ldrb     w8, [x0, #0x160]
//   0x0e6374: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1054_0x0e6368(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6368ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0439b8ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1055 | PC: 0x0e6438 | FDE: 0x0439d8 | Size: 44 bytes [_Z21js_std_add_helpers_gcP12LEPUSContextiPPc]
// Khung tháo gỡ #1055 | Địa chỉ PC: 0x0e6438 | Địa chỉ FDE: 0x0439d8 | Kích thước: 44 bytes
//   0x0e6438: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e643c: F9400813  ldr      x19, [x0, #0x10]
//   0x0e6440: 52800300  mov      w0, #0x18
//   0x0e6444: 9403294F  bl       #0x1b0980
static inline uint64_t fde_func_1055_0x0e6438(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6438ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400813ULL) ^ 0x0439d8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1056 | PC: 0x0e6464 | FDE: 0x0439f0 | Size: 256 bytes [lepus_std_loop]
// Khung tháo gỡ #1056 | Địa chỉ PC: 0x0e6464 | Địa chỉ FDE: 0x0439f0 | Kích thước: 256 bytes
//   0x0e6464: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x0e6468: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0e646c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0e6470: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1056_0x0e6464(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6464ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0439f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1057 | PC: 0x0e66cc | FDE: 0x043a38 | Size: 196 bytes
// Khung tháo gỡ #1057 | Địa chỉ PC: 0x0e66cc | Địa chỉ FDE: 0x043a38 | Kích thước: 196 bytes
//   0x0e66cc: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0e66d0: F9400062  ldr      x2, [x3]
//   0x0e66d4: D371FC48  lsr      x8, x2, #0x31
//   0x0e66d8: B6800042  tbz      x2, #0x30, #0xe66e0
static inline uint64_t fde_func_1057_0x0e66cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e66ccULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400062ULL) ^ 0x043a38ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1058 | PC: 0x0e6790 | FDE: 0x043a50 | Size: 212 bytes
// Khung tháo gỡ #1058 | Địa chỉ PC: 0x0e6790 | Địa chỉ FDE: 0x043a50 | Kích thước: 212 bytes
//   0x0e6790: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0e6794: F9400062  ldr      x2, [x3]
//   0x0e6798: D371FC48  lsr      x8, x2, #0x31
//   0x0e679c: B6800042  tbz      x2, #0x30, #0xe67a4
static inline uint64_t fde_func_1058_0x0e6790(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6790ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400062ULL) ^ 0x043a50ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1059 | PC: 0x0e6864 | FDE: 0x043a68 | Size: 232 bytes
// Khung tháo gỡ #1059 | Địa chỉ PC: 0x0e6864 | Địa chỉ FDE: 0x043a68 | Kích thước: 232 bytes
//   0x0e6864: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0e6868: F9400062  ldr      x2, [x3]
//   0x0e686c: D371FC48  lsr      x8, x2, #0x31
//   0x0e6870: B6800042  tbz      x2, #0x30, #0xe6878
static inline uint64_t fde_func_1059_0x0e6864(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6864ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400062ULL) ^ 0x043a68ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1060 | PC: 0x0e694c | FDE: 0x043a80 | Size: 248 bytes
// Khung tháo gỡ #1060 | Địa chỉ PC: 0x0e694c | Địa chỉ FDE: 0x043a80 | Kích thước: 248 bytes
//   0x0e694c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0e6950: F9400062  ldr      x2, [x3]
//   0x0e6954: D371FC48  lsr      x8, x2, #0x31
//   0x0e6958: B6800042  tbz      x2, #0x30, #0xe6960
static inline uint64_t fde_func_1060_0x0e694c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e694cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400062ULL) ^ 0x043a80ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1061 | PC: 0x0e6a44 | FDE: 0x043a98 | Size: 256 bytes
// Khung tháo gỡ #1061 | Địa chỉ PC: 0x0e6a44 | Địa chỉ FDE: 0x043a98 | Kích thước: 256 bytes
//   0x0e6a44: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0e6a48: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0e6a4c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0e6a50: F9400062  ldr      x2, [x3]
static inline uint64_t fde_func_1061_0x0e6a44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6a44ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x043a98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1062 | PC: 0x0e6cb4 | FDE: 0x043ab8 | Size: 256 bytes
// Khung tháo gỡ #1062 | Địa chỉ PC: 0x0e6cb4 | Địa chỉ FDE: 0x043ab8 | Kích thước: 256 bytes
//   0x0e6cb4: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0e6cb8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0e6cbc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0e6cc0: F9400062  ldr      x2, [x3]
static inline uint64_t fde_func_1062_0x0e6cb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6cb4ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x043ab8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1063 | PC: 0x0e6ea8 | FDE: 0x043ad8 | Size: 56 bytes
// Khung tháo gỡ #1063 | Địa chỉ PC: 0x0e6ea8 | Địa chỉ FDE: 0x043ad8 | Kích thước: 56 bytes
//   0x0e6ea8: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0e6eac: F9400062  ldr      x2, [x3]
//   0x0e6eb0: 910023E1  add      x1, sp, #8
//   0x0e6eb4: 9400B303  bl       #0x113ac0
static inline uint64_t fde_func_1063_0x0e6ea8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6ea8ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400062ULL) ^ 0x043ad8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1064 | PC: 0x0e6ee0 | FDE: 0x043af0 | Size: 72 bytes
// Khung tháo gỡ #1064 | Địa chỉ PC: 0x0e6ee0 | Địa chỉ FDE: 0x043af0 | Kích thước: 72 bytes
//   0x0e6ee0: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0e6ee4: F9400062  ldr      x2, [x3]
//   0x0e6ee8: 910023E1  add      x1, sp, #8
//   0x0e6eec: 9400B2F5  bl       #0x113ac0
static inline uint64_t fde_func_1064_0x0e6ee0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6ee0ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400062ULL) ^ 0x043af0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1065 | PC: 0x0e6f28 | FDE: 0x043b08 | Size: 256 bytes
// Khung tháo gỡ #1065 | Địa chỉ PC: 0x0e6f28 | Địa chỉ FDE: 0x043b08 | Kích thước: 256 bytes
//   0x0e6f28: D10203FF  sub      sp, sp, #0x80
//   0x0e6f2c: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0e6f30: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0e6f34: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1065_0x0e6f28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6f28ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x043b08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1066 | PC: 0x0e743c | FDE: 0x043b38 | Size: 256 bytes
// Khung tháo gỡ #1066 | Địa chỉ PC: 0x0e743c | Địa chỉ FDE: 0x043b38 | Kích thước: 256 bytes
//   0x0e743c: D102C3FF  sub      sp, sp, #0xb0
//   0x0e7440: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x0e7444: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0e7448: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_1066_0x0e743c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e743cULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x043b38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1067 | PC: 0x0e7d2c | FDE: 0x043b68 | Size: 256 bytes
// Khung tháo gỡ #1067 | Địa chỉ PC: 0x0e7d2c | Địa chỉ FDE: 0x043b68 | Kích thước: 256 bytes
//   0x0e7d2c: D10283FF  sub      sp, sp, #0xa0
//   0x0e7d30: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x0e7d34: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0e7d38: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1067_0x0e7d2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7d2cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x043b68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1068 | PC: 0x0e8070 | FDE: 0x043b98 | Size: 256 bytes
// Khung tháo gỡ #1068 | Địa chỉ PC: 0x0e8070 | Địa chỉ FDE: 0x043b98 | Kích thước: 256 bytes
//   0x0e8070: D101C3FF  sub      sp, sp, #0x70
//   0x0e8074: A9026BFB  stp      x27, x26, [sp, #0x20]
//   0x0e8078: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x0e807c: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_1068_0x0e8070(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8070ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9026bfbULL) ^ 0x043b98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1069 | PC: 0x0e84ec | FDE: 0x043bc0 | Size: 100 bytes
// Khung tháo gỡ #1069 | Địa chỉ PC: 0x0e84ec | Địa chỉ FDE: 0x043bc0 | Kích thước: 100 bytes
//   0x0e84ec: D10083FF  sub      sp, sp, #0x20
//   0x0e84f0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e84f4: AA0003F3  mov      x19, x0
//   0x0e84f8: 910003E0  mov      x0, sp
static inline uint64_t fde_func_1069_0x0e84ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e84ecULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x043bc0ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1070 | PC: 0x0e8550 | FDE: 0x043bd8 | Size: 256 bytes
// Khung tháo gỡ #1070 | Địa chỉ PC: 0x0e8550 | Địa chỉ FDE: 0x043bd8 | Kích thước: 256 bytes
//   0x0e8550: D10183FF  sub      sp, sp, #0x60
//   0x0e8554: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0e8558: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x0e855c: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1070_0x0e8550(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8550ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9035bf7ULL) ^ 0x043bd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1071 | PC: 0x0e8b1c | FDE: 0x043bf8 | Size: 160 bytes [LEPUS_ThrowInternalError]
// Khung tháo gỡ #1071 | Địa chỉ PC: 0x0e8b1c | Địa chỉ FDE: 0x043bf8 | Kích thước: 160 bytes
//   0x0e8b1c: D10483FF  sub      sp, sp, #0x120
//   0x0e8b20: F90083FC  str      x28, [sp, #0x100]
//   0x0e8b24: A9117BF3  stp      x19, x30, [sp, #0x110]
//   0x0e8b28: A9080FE2  stp      x2, x3, [sp, #0x80]
static inline uint64_t fde_func_1071_0x0e8b1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8b1cULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x043bf8ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1072 | PC: 0x0e8bbc | FDE: 0x043c18 | Size: 164 bytes
// Khung tháo gỡ #1072 | Địa chỉ PC: 0x0e8bbc | Địa chỉ FDE: 0x043c18 | Kích thước: 164 bytes
//   0x0e8bbc: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0e8bc0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e8bc4: 29422408  ldp      w8, w9, [x0, #0x10]
//   0x0e8bc8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1072_0x0e8bbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8bbcULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x043c18ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1073 | PC: 0x0e8c60 | FDE: 0x043c38 | Size: 256 bytes [CheckObjectCtx]
// Khung tháo gỡ #1073 | Địa chỉ PC: 0x0e8c60 | Địa chỉ FDE: 0x043c38 | Kích thước: 256 bytes
//   0x0e8c60: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0e8c64: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0e8c68: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0e8c6c: 39458808  ldrb     w8, [x0, #0x162]
static inline uint64_t fde_func_1073_0x0e8c60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8c60ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x043c38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1074 | PC: 0x0e8dd4 | FDE: 0x043c58 | Size: 256 bytes
// Khung tháo gỡ #1074 | Địa chỉ PC: 0x0e8dd4 | Địa chỉ FDE: 0x043c58 | Kích thước: 256 bytes
//   0x0e8dd4: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0e8dd8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0e8ddc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e8de0: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1074_0x0e8dd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8dd4ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x043c58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1075 | PC: 0x0e93c4 | FDE: 0x043c88 | Size: 256 bytes
// Khung tháo gỡ #1075 | Địa chỉ PC: 0x0e93c4 | Địa chỉ FDE: 0x043c88 | Kích thước: 256 bytes
//   0x0e93c4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e93c8: B9401C08  ldr      w8, [x0, #0x1c]
//   0x0e93cc: 34000068  cbz      w8, #0xe93d8
//   0x0e93d0: 52801053  mov      w19, #0x82
static inline uint64_t fde_func_1075_0x0e93c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e93c4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb9401c08ULL) ^ 0x043c88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1076 | PC: 0x0e94f8 | FDE: 0x043ca0 | Size: 256 bytes [_Z22JS_FreeSeparableStringP12LEPUSRuntime10LEPUSValue]
// Khung tháo gỡ #1076 | Địa chỉ PC: 0x0e94f8 | Địa chỉ FDE: 0x043ca0 | Kích thước: 256 bytes
//   0x0e94f8: D101C3FF  sub      sp, sp, #0x70
//   0x0e94fc: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0e9500: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0e9504: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1076_0x0e94f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e94f8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x043ca0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1077 | PC: 0x0e98c8 | FDE: 0x043cd0 | Size: 256 bytes
// Khung tháo gỡ #1077 | Địa chỉ PC: 0x0e98c8 | Địa chỉ FDE: 0x043cd0 | Kích thước: 256 bytes
//   0x0e98c8: D10203FF  sub      sp, sp, #0x80
//   0x0e98cc: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0e98d0: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0e98d4: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1077_0x0e98c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e98c8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x043cd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1078 | PC: 0x0ea048 | FDE: 0x043d00 | Size: 244 bytes [LEPUS_FreeAtomRT]
// Khung tháo gỡ #1078 | Địa chỉ PC: 0x0ea048 | Địa chỉ FDE: 0x043d00 | Kích thước: 244 bytes
//   0x0ea048: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0ea04c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0ea050: 71032C3F  cmp      w1, #0xcb
//   0x0ea054: 540006EB  b.lt     #0xea130
static inline uint64_t fde_func_1078_0x0ea048(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea048ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x043d00ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #1079 | PC: 0x0ea13c | FDE: 0x043d20 | Size: 256 bytes
// Khung tháo gỡ #1079 | Địa chỉ PC: 0x0ea13c | Địa chỉ FDE: 0x043d20 | Kích thước: 256 bytes
//   0x0ea13c: D100C3FF  sub      sp, sp, #0x30
//   0x0ea140: F9000BF4  str      x20, [sp, #0x10]
//   0x0ea144: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0ea148: B40000C1  cbz      x1, #0xea160
static inline uint64_t fde_func_1079_0x0ea13c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea13cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x043d20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1080 | PC: 0x0ea250 | FDE: 0x043d40 | Size: 256 bytes
// Khung tháo gỡ #1080 | Địa chỉ PC: 0x0ea250 | Địa chỉ FDE: 0x043d40 | Kích thước: 256 bytes
//   0x0ea250: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0ea254: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0ea258: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0ea25c: B9400028  ldr      w8, [x1]
static inline uint64_t fde_func_1080_0x0ea250(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea250ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x043d40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1081 | PC: 0x0ea384 | FDE: 0x043d60 | Size: 256 bytes
// Khung tháo gỡ #1081 | Địa chỉ PC: 0x0ea384 | Địa chỉ FDE: 0x043d60 | Kích thước: 256 bytes
//   0x0ea384: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0ea388: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0ea38c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0ea390: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1081_0x0ea384(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea384ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x043d60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1082 | PC: 0x0f6850 | FDE: 0x043d90 | Size: 256 bytes [JS_ThrowTypeErrorNotFunction]
// Khung tháo gỡ #1082 | Địa chỉ PC: 0x0f6850 | Địa chỉ FDE: 0x043d90 | Kích thước: 256 bytes
//   0x0f6850: D10283FF  sub      sp, sp, #0xa0
//   0x0f6854: A90663F9  stp      x25, x24, [sp, #0x60]
//   0x0f6858: A9075BF7  stp      x23, x22, [sp, #0x70]
//   0x0f685c: A90853F5  stp      x21, x20, [sp, #0x80]
static inline uint64_t fde_func_1082_0x0f6850(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f6850ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa90663f9ULL) ^ 0x043d90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1083 | PC: 0x0f6c58 | FDE: 0x043db8 | Size: 256 bytes
// Khung tháo gỡ #1083 | Địa chỉ PC: 0x0f6c58 | Địa chỉ FDE: 0x043db8 | Kích thước: 256 bytes
//   0x0f6c58: D10283FF  sub      sp, sp, #0xa0
//   0x0f6c5c: A9056BFB  stp      x27, x26, [sp, #0x50]
//   0x0f6c60: A90663F9  stp      x25, x24, [sp, #0x60]
//   0x0f6c64: A9075BF7  stp      x23, x22, [sp, #0x70]
static inline uint64_t fde_func_1083_0x0f6c58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f6c58ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9056bfbULL) ^ 0x043db8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1084 | PC: 0x0f7000 | FDE: 0x043de8 | Size: 256 bytes
// Khung tháo gỡ #1084 | Địa chỉ PC: 0x0f7000 | Địa chỉ FDE: 0x043de8 | Kích thước: 256 bytes
//   0x0f7000: D102C3FF  sub      sp, sp, #0xb0
//   0x0f7004: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x0f7008: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0f700c: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_1084_0x0f7000(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f7000ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x043de8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1085 | PC: 0x0f7a8c | FDE: 0x043e18 | Size: 256 bytes
// Khung tháo gỡ #1085 | Địa chỉ PC: 0x0f7a8c | Địa chỉ FDE: 0x043e18 | Kích thước: 256 bytes
//   0x0f7a8c: D101C3FF  sub      sp, sp, #0x70
//   0x0f7a90: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x0f7a94: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x0f7a98: D53BD055  mrs      x21, tpidr_el0
static inline uint64_t fde_func_1085_0x0f7a8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f7a8cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90553f5ULL) ^ 0x043e18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1086 | PC: 0x0f7bb8 | FDE: 0x043e38 | Size: 256 bytes [LEPUS_ToObject]
// Khung tháo gỡ #1086 | Địa chỉ PC: 0x0f7bb8 | Địa chỉ FDE: 0x043e38 | Kích thước: 256 bytes
//   0x0f7bb8: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x0f7bbc: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0f7bc0: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0f7bc4: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1086_0x0f7bb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f7bb8ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x043e38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1087 | PC: 0x0f8174 | FDE: 0x043e60 | Size: 236 bytes
// Khung tháo gỡ #1087 | Địa chỉ PC: 0x0f8174 | Địa chỉ FDE: 0x043e60 | Kích thước: 236 bytes
//   0x0f8174: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0f8178: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0f817c: 2A0203F3  mov      w19, w2
//   0x0f8180: AA0103E8  mov      x8, x1
static inline uint64_t fde_func_1087_0x0f8174(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8174ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x043e60ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #1088 | PC: 0x0f8260 | FDE: 0x043e80 | Size: 256 bytes
// Khung tháo gỡ #1088 | Địa chỉ PC: 0x0f8260 | Địa chỉ FDE: 0x043e80 | Kích thước: 256 bytes
//   0x0f8260: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x0f8264: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0f8268: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0f826c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1088_0x0f8260(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8260ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x043e80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1089 | PC: 0x0f83bc | FDE: 0x043ea8 | Size: 256 bytes
// Khung tháo gỡ #1089 | Địa chỉ PC: 0x0f83bc | Địa chỉ FDE: 0x043ea8 | Kích thước: 256 bytes
//   0x0f83bc: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x0f83c0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0f83c4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0f83c8: F9400814  ldr      x20, [x0, #0x10]
static inline uint64_t fde_func_1089_0x0f83bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f83bcULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x043ea8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1090 | PC: 0x0f861c | FDE: 0x043ec8 | Size: 256 bytes
// Khung tháo gỡ #1090 | Địa chỉ PC: 0x0f861c | Địa chỉ FDE: 0x043ec8 | Kích thước: 256 bytes
//   0x0f861c: D101C3FF  sub      sp, sp, #0x70
//   0x0f8620: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0f8624: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0f8628: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1090_0x0f861c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f861cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x043ec8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1091 | PC: 0x0f89c4 | FDE: 0x043ef8 | Size: 256 bytes
// Khung tháo gỡ #1091 | Địa chỉ PC: 0x0f89c4 | Địa chỉ FDE: 0x043ef8 | Kích thước: 256 bytes
//   0x0f89c4: A9BB6BFB  stp      x27, x26, [sp, #-0x50]!
//   0x0f89c8: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x0f89cc: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0f89d0: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1091_0x0f89c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f89c4ULL ^ (static_cast<uint64_t>(0xa9bb6bfbULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x043ef8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1092 | PC: 0x0f8d34 | FDE: 0x043f20 | Size: 256 bytes
// Khung tháo gỡ #1092 | Địa chỉ PC: 0x0f8d34 | Địa chỉ FDE: 0x043f20 | Kích thước: 256 bytes
//   0x0f8d34: D101C3FF  sub      sp, sp, #0x70
//   0x0f8d38: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0f8d3c: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0f8d40: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1092_0x0f8d34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8d34ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x043f20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1093 | PC: 0x0f9034 | FDE: 0x043f50 | Size: 160 bytes [LEPUS_ThrowTypeError]
// Khung tháo gỡ #1093 | Địa chỉ PC: 0x0f9034 | Địa chỉ FDE: 0x043f50 | Kích thước: 160 bytes
//   0x0f9034: D10483FF  sub      sp, sp, #0x120
//   0x0f9038: F90083FC  str      x28, [sp, #0x100]
//   0x0f903c: A9117BF3  stp      x19, x30, [sp, #0x110]
//   0x0f9040: A9080FE2  stp      x2, x3, [sp, #0x80]
static inline uint64_t fde_func_1093_0x0f9034(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9034ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x043f50ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1094 | PC: 0x0f90d4 | FDE: 0x043f70 | Size: 256 bytes [LEPUS_Throw]
// Khung tháo gỡ #1094 | Địa chỉ PC: 0x0f90d4 | Địa chỉ FDE: 0x043f70 | Kích thước: 256 bytes
//   0x0f90d4: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x0f90d8: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0f90dc: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0f90e0: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1094_0x0f90d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f90d4ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x043f70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1095 | PC: 0x0f9220 | FDE: 0x043f98 | Size: 256 bytes
// Khung tháo gỡ #1095 | Địa chỉ PC: 0x0f9220 | Địa chỉ FDE: 0x043f98 | Kích thước: 256 bytes
//   0x0f9220: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0f9224: AA0103F3  mov      x19, x1
//   0x0f9228: 37F801E2  tbnz     w2, #0x1f, #0xf9264
//   0x0f922c: 340002C2  cbz      w2, #0xf9284
static inline uint64_t fde_func_1095_0x0f9220(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9220ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0103f3ULL) ^ 0x043f98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1096 | PC: 0x0f93bc | FDE: 0x043fb0 | Size: 160 bytes [LEPUS_ThrowSyntaxError]
// Khung tháo gỡ #1096 | Địa chỉ PC: 0x0f93bc | Địa chỉ FDE: 0x043fb0 | Kích thước: 160 bytes
//   0x0f93bc: D10483FF  sub      sp, sp, #0x120
//   0x0f93c0: F90083FC  str      x28, [sp, #0x100]
//   0x0f93c4: A9117BF3  stp      x19, x30, [sp, #0x110]
//   0x0f93c8: A9080FE2  stp      x2, x3, [sp, #0x80]
static inline uint64_t fde_func_1096_0x0f93bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f93bcULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x043fb0ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1097 | PC: 0x0f945c | FDE: 0x043fd0 | Size: 160 bytes [LEPUS_ThrowReferenceError]
// Khung tháo gỡ #1097 | Địa chỉ PC: 0x0f945c | Địa chỉ FDE: 0x043fd0 | Kích thước: 160 bytes
//   0x0f945c: D10483FF  sub      sp, sp, #0x120
//   0x0f9460: F90083FC  str      x28, [sp, #0x100]
//   0x0f9464: A9117BF3  stp      x19, x30, [sp, #0x110]
//   0x0f9468: A9080FE2  stp      x2, x3, [sp, #0x80]
static inline uint64_t fde_func_1097_0x0f945c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f945cULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x043fd0ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1098 | PC: 0x0f94fc | FDE: 0x043ff0 | Size: 256 bytes
// Khung tháo gỡ #1098 | Địa chỉ PC: 0x0f94fc | Địa chỉ FDE: 0x043ff0 | Kích thước: 256 bytes
//   0x0f94fc: D10183FF  sub      sp, sp, #0x60
//   0x0f9500: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x0f9504: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0f9508: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_1098_0x0f94fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f94fcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90263f9ULL) ^ 0x043ff0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1099 | PC: 0x0f96c4 | FDE: 0x044018 | Size: 256 bytes
// Khung tháo gỡ #1099 | Địa chỉ PC: 0x0f96c4 | Địa chỉ FDE: 0x044018 | Kích thước: 256 bytes
//   0x0f96c4: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x0f96c8: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x0f96cc: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0f96d0: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1099_0x0f96c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f96c4ULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x044018ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1100 | PC: 0x0f9ab8 | FDE: 0x044040 | Size: 256 bytes
// Khung tháo gỡ #1100 | Địa chỉ PC: 0x0f9ab8 | Địa chỉ FDE: 0x044040 | Kích thước: 256 bytes
//   0x0f9ab8: D10103FF  sub      sp, sp, #0x40
//   0x0f9abc: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0f9ac0: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x0f9ac4: AA0103E2  mov      x2, x1
static inline uint64_t fde_func_1100_0x0f9ab8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9ab8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x044040ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1101 | PC: 0x0fa098 | FDE: 0x044060 | Size: 256 bytes [js_dynamic_import]
// Khung tháo gỡ #1101 | Địa chỉ PC: 0x0fa098 | Địa chỉ FDE: 0x044060 | Kích thước: 256 bytes
//   0x0fa098: D10283FF  sub      sp, sp, #0xa0
//   0x0fa09c: A9056BFB  stp      x27, x26, [sp, #0x50]
//   0x0fa0a0: A90663F9  stp      x25, x24, [sp, #0x60]
//   0x0fa0a4: A9075BF7  stp      x23, x22, [sp, #0x70]
static inline uint64_t fde_func_1101_0x0fa098(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fa098ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9056bfbULL) ^ 0x044060ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1102 | PC: 0x0fabd8 | FDE: 0x044090 | Size: 256 bytes [LEPUS_HasProperty]
// Khung tháo gỡ #1102 | Địa chỉ PC: 0x0fabd8 | Địa chỉ FDE: 0x044090 | Kích thước: 256 bytes
//   0x0fabd8: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x0fabdc: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0fabe0: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0fabe4: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1102_0x0fabd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fabd8ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x044090ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1103 | PC: 0x0fae2c | FDE: 0x0440b8 | Size: 256 bytes
// Khung tháo gỡ #1103 | Địa chỉ PC: 0x0fae2c | Địa chỉ FDE: 0x0440b8 | Kích thước: 256 bytes
//   0x0fae2c: D101C3FF  sub      sp, sp, #0x70
//   0x0fae30: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x0fae34: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x0fae38: D53BD055  mrs      x21, tpidr_el0
static inline uint64_t fde_func_1103_0x0fae2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fae2cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90553f5ULL) ^ 0x0440b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1104 | PC: 0x0fafb8 | FDE: 0x0440d8 | Size: 256 bytes
// Khung tháo gỡ #1104 | Địa chỉ PC: 0x0fafb8 | Địa chỉ FDE: 0x0440d8 | Kích thước: 256 bytes
//   0x0fafb8: D10203FF  sub      sp, sp, #0x80
//   0x0fafbc: F9002BF6  str      x22, [sp, #0x50]
//   0x0fafc0: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x0fafc4: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1104_0x0fafb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fafb8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf6ULL) ^ 0x0440d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1105 | PC: 0x0fb2ec | FDE: 0x0440f8 | Size: 256 bytes
// Khung tháo gỡ #1105 | Địa chỉ PC: 0x0fb2ec | Địa chỉ FDE: 0x0440f8 | Kích thước: 256 bytes
//   0x0fb2ec: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x0fb2f0: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0fb2f4: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0fb2f8: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1105_0x0fb2ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb2ecULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0440f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1106 | PC: 0x0fb570 | FDE: 0x044120 | Size: 256 bytes
// Khung tháo gỡ #1106 | Địa chỉ PC: 0x0fb570 | Địa chỉ FDE: 0x044120 | Kích thước: 256 bytes
//   0x0fb570: D10303FF  sub      sp, sp, #0xc0
//   0x0fb574: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x0fb578: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x0fb57c: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_1106_0x0fb570(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb570ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x044120ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1107 | PC: 0x0fcf10 | FDE: 0x044150 | Size: 256 bytes
// Khung tháo gỡ #1107 | Địa chỉ PC: 0x0fcf10 | Địa chỉ FDE: 0x044150 | Kích thước: 256 bytes
//   0x0fcf10: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x0fcf14: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0fcf18: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0fcf1c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1107_0x0fcf10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fcf10ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x044150ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1108 | PC: 0x0fd0f0 | FDE: 0x044178 | Size: 256 bytes
// Khung tháo gỡ #1108 | Địa chỉ PC: 0x0fd0f0 | Địa chỉ FDE: 0x044178 | Kích thước: 256 bytes
//   0x0fd0f0: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x0fd0f4: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0fd0f8: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0fd0fc: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1108_0x0fd0f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fd0f0ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x044178ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1109 | PC: 0x0fd294 | FDE: 0x0441a0 | Size: 256 bytes
// Khung tháo gỡ #1109 | Địa chỉ PC: 0x0fd294 | Địa chỉ FDE: 0x0441a0 | Kích thước: 256 bytes
//   0x0fd294: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0fd298: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0fd29c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0fd2a0: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1109_0x0fd294(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fd294ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0441a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1110 | PC: 0x0fd550 | FDE: 0x0441c0 | Size: 256 bytes
// Khung tháo gỡ #1110 | Địa chỉ PC: 0x0fd550 | Địa chỉ FDE: 0x0441c0 | Kích thước: 256 bytes
//   0x0fd550: D10383FF  sub      sp, sp, #0xe0
//   0x0fd554: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x0fd558: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x0fd55c: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_1110_0x0fd550(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fd550ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x0441c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1111 | PC: 0x0fe1a0 | FDE: 0x0441f0 | Size: 244 bytes [LEPUS_FreeAtom]
// Khung tháo gỡ #1111 | Địa chỉ PC: 0x0fe1a0 | Địa chỉ FDE: 0x0441f0 | Kích thước: 244 bytes
//   0x0fe1a0: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0fe1a4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0fe1a8: 71032C3F  cmp      w1, #0xcb
//   0x0fe1ac: 540006EB  b.lt     #0xfe288
static inline uint64_t fde_func_1111_0x0fe1a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fe1a0ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0441f0ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #1112 | PC: 0x0fe294 | FDE: 0x044210 | Size: 256 bytes
// Khung tháo gỡ #1112 | Địa chỉ PC: 0x0fe294 | Địa chỉ FDE: 0x044210 | Kích thước: 256 bytes
//   0x0fe294: D10383FF  sub      sp, sp, #0xe0
//   0x0fe298: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x0fe29c: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x0fe2a0: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_1112_0x0fe294(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fe294ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x044210ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1113 | PC: 0x0ff764 | FDE: 0x044240 | Size: 256 bytes
// Khung tháo gỡ #1113 | Địa chỉ PC: 0x0ff764 | Địa chỉ FDE: 0x044240 | Kích thước: 256 bytes
//   0x0ff764: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x0ff768: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0ff76c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0ff770: F85F8036  ldur     x22, [x1, #-8]
static inline uint64_t fde_func_1113_0x0ff764(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ff764ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x044240ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1114 | PC: 0x0ff864 | FDE: 0x044260 | Size: 256 bytes
// Khung tháo gỡ #1114 | Địa chỉ PC: 0x0ff864 | Địa chỉ FDE: 0x044260 | Kích thước: 256 bytes
//   0x0ff864: D10203FF  sub      sp, sp, #0x80
//   0x0ff868: F90013FC  str      x28, [sp, #0x20]
//   0x0ff86c: A9036BFB  stp      x27, x26, [sp, #0x30]
//   0x0ff870: A90463F9  stp      x25, x24, [sp, #0x40]
static inline uint64_t fde_func_1114_0x0ff864(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ff864ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fcULL) ^ 0x044260ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1115 | PC: 0x0ffc8c | FDE: 0x044290 | Size: 256 bytes
// Khung tháo gỡ #1115 | Địa chỉ PC: 0x0ffc8c | Địa chỉ FDE: 0x044290 | Kích thước: 256 bytes
//   0x0ffc8c: D10243FF  sub      sp, sp, #0x90
//   0x0ffc90: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0ffc94: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0ffc98: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1115_0x0ffc8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ffc8cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x044290ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1116 | PC: 0x100660 | FDE: 0x0442c0 | Size: 256 bytes
// Khung tháo gỡ #1116 | Địa chỉ PC: 0x100660 | Địa chỉ FDE: 0x0442c0 | Kích thước: 256 bytes
//   0x100660: D10283FF  sub      sp, sp, #0xa0
//   0x100664: F9002BFA  str      x26, [sp, #0x50]
//   0x100668: A90663F9  stp      x25, x24, [sp, #0x60]
//   0x10066c: A9075BF7  stp      x23, x22, [sp, #0x70]
static inline uint64_t fde_func_1116_0x100660(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x100660ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9002bfaULL) ^ 0x0442c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1117 | PC: 0x100950 | FDE: 0x0442e8 | Size: 256 bytes
// Khung tháo gỡ #1117 | Địa chỉ PC: 0x100950 | Địa chỉ FDE: 0x0442e8 | Kích thước: 256 bytes
//   0x100950: D10203FF  sub      sp, sp, #0x80
//   0x100954: F90023F8  str      x24, [sp, #0x40]
//   0x100958: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x10095c: A90653F5  stp      x21, x20, [sp, #0x60]
static inline uint64_t fde_func_1117_0x100950(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x100950ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f8ULL) ^ 0x0442e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1118 | PC: 0x100ea8 | FDE: 0x044310 | Size: 256 bytes
// Khung tháo gỡ #1118 | Địa chỉ PC: 0x100ea8 | Địa chỉ FDE: 0x044310 | Kích thước: 256 bytes
//   0x100ea8: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x100eac: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x100eb0: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x100eb4: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1118_0x100ea8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x100ea8ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x044310ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1119 | PC: 0x10107c | FDE: 0x044338 | Size: 256 bytes [LEPUS_ValueToAtom]
// Khung tháo gỡ #1119 | Địa chỉ PC: 0x10107c | Địa chỉ FDE: 0x044338 | Kích thước: 256 bytes
//   0x10107c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x101080: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x101084: 39458008  ldrb     w8, [x0, #0x160]
//   0x101088: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1119_0x10107c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10107cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x044338ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1120 | PC: 0x1011e8 | FDE: 0x044358 | Size: 256 bytes
// Khung tháo gỡ #1120 | Địa chỉ PC: 0x1011e8 | Địa chỉ FDE: 0x044358 | Kích thước: 256 bytes
//   0x1011e8: D10243FF  sub      sp, sp, #0x90
//   0x1011ec: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x1011f0: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x1011f4: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1120_0x1011e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1011e8ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x044358ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1121 | PC: 0x101e40 | FDE: 0x044388 | Size: 256 bytes
// Khung tháo gỡ #1121 | Địa chỉ PC: 0x101e40 | Địa chỉ FDE: 0x044388 | Kích thước: 256 bytes
//   0x101e40: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x101e44: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x101e48: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x101e4c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1121_0x101e40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101e40ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x044388ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1122 | PC: 0x102244 | FDE: 0x0443b0 | Size: 256 bytes
// Khung tháo gỡ #1122 | Địa chỉ PC: 0x102244 | Địa chỉ FDE: 0x0443b0 | Kích thước: 256 bytes
//   0x102244: D101C3FF  sub      sp, sp, #0x70
//   0x102248: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x10224c: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x102250: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1122_0x102244(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x102244ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x0443b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1123 | PC: 0x102cfc | FDE: 0x0443e0 | Size: 256 bytes
// Khung tháo gỡ #1123 | Địa chỉ PC: 0x102cfc | Địa chỉ FDE: 0x0443e0 | Kích thước: 256 bytes
//   0x102cfc: D10343FF  sub      sp, sp, #0xd0
//   0x102d00: F9003BFC  str      x28, [sp, #0x70]
//   0x102d04: A9086BFB  stp      x27, x26, [sp, #0x80]
//   0x102d08: A90963F9  stp      x25, x24, [sp, #0x90]
static inline uint64_t fde_func_1123_0x102cfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x102cfcULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf9003bfcULL) ^ 0x0443e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1124 | PC: 0x10359c | FDE: 0x044410 | Size: 256 bytes
// Khung tháo gỡ #1124 | Địa chỉ PC: 0x10359c | Địa chỉ FDE: 0x044410 | Kích thước: 256 bytes
//   0x10359c: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x1035a0: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x1035a4: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x1035a8: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1124_0x10359c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10359cULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x044410ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1125 | PC: 0x1037c0 | FDE: 0x044438 | Size: 256 bytes
// Khung tháo gỡ #1125 | Địa chỉ PC: 0x1037c0 | Địa chỉ FDE: 0x044438 | Kích thước: 256 bytes
//   0x1037c0: D10203FF  sub      sp, sp, #0x80
//   0x1037c4: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x1037c8: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x1037cc: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1125_0x1037c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1037c0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x044438ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1126 | PC: 0x103aa8 | FDE: 0x044468 | Size: 256 bytes
// Khung tháo gỡ #1126 | Địa chỉ PC: 0x103aa8 | Địa chỉ FDE: 0x044468 | Kích thước: 256 bytes
//   0x103aa8: 6DB923E9  stp      d9, d8, [sp, #-0x70]!
//   0x103aac: F9000BFC  str      x28, [sp, #0x10]
//   0x103ab0: A9026BFB  stp      x27, x26, [sp, #0x20]
//   0x103ab4: A90363F9  stp      x25, x24, [sp, #0x30]
static inline uint64_t fde_func_1126_0x103aa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x103aa8ULL ^ (static_cast<uint64_t>(0x6db923e9ULL) << 13);
    acc = (acc + a1 + 0xf9000bfcULL) ^ 0x044468ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1127 | PC: 0x104440 | FDE: 0x044498 | Size: 256 bytes
// Khung tháo gỡ #1127 | Địa chỉ PC: 0x104440 | Địa chỉ FDE: 0x044498 | Kích thước: 256 bytes
//   0x104440: D10203FF  sub      sp, sp, #0x80
//   0x104444: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x104448: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x10444c: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1127_0x104440(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x104440ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x044498ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1128 | PC: 0x104c24 | FDE: 0x0444c8 | Size: 256 bytes [_Z23JS_ConcatStringOriginalP12LEPUSContext10LEPUSValueS1_]
// Khung tháo gỡ #1128 | Địa chỉ PC: 0x104c24 | Địa chỉ FDE: 0x0444c8 | Kích thước: 256 bytes
//   0x104c24: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x104c28: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x104c2c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x104c30: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1128_0x104c24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x104c24ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0444c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1129 | PC: 0x105400 | FDE: 0x0444f8 | Size: 256 bytes
// Khung tháo gỡ #1129 | Địa chỉ PC: 0x105400 | Địa chỉ FDE: 0x0444f8 | Kích thước: 256 bytes
//   0x105400: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x105404: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x105408: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x10540c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1129_0x105400(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x105400ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0444f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1130 | PC: 0x1057b0 | FDE: 0x044520 | Size: 256 bytes
// Khung tháo gỡ #1130 | Địa chỉ PC: 0x1057b0 | Địa chỉ FDE: 0x044520 | Kích thước: 256 bytes
//   0x1057b0: FC190FEA  str      d10, [sp, #-0x70]!
//   0x1057b4: 6D00A3E9  stp      d9, d8, [sp, #8]
//   0x1057b8: F9000FFC  str      x28, [sp, #0x18]
//   0x1057bc: A9026BFB  stp      x27, x26, [sp, #0x20]
static inline uint64_t fde_func_1130_0x1057b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1057b0ULL ^ (static_cast<uint64_t>(0xfc190feaULL) << 13);
    acc = (acc + a1 + 0x6d00a3e9ULL) ^ 0x044520ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1131 | PC: 0x106108 | FDE: 0x044558 | Size: 256 bytes [_Z19js_unary_arith_slowP12LEPUSContextP10LEPUSValue10OPCodeEnum]
// Khung tháo gỡ #1131 | Địa chỉ PC: 0x106108 | Địa chỉ FDE: 0x044558 | Kích thước: 256 bytes
//   0x106108: D101C3FF  sub      sp, sp, #0x70
//   0x10610c: A9026BFB  stp      x27, x26, [sp, #0x20]
//   0x106110: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x106114: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_1131_0x106108(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106108ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9026bfbULL) ^ 0x044558ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1132 | PC: 0x1065dc | FDE: 0x044580 | Size: 236 bytes [_Z16js_post_inc_slowP12LEPUSContextP10LEPUSValue10OPCodeEnum]
// Khung tháo gỡ #1132 | Địa chỉ PC: 0x1065dc | Địa chỉ FDE: 0x044580 | Kích thước: 236 bytes
//   0x1065dc: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x1065e0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1065e4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1065e8: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1132_0x1065dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1065dcULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x044580ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #1133 | PC: 0x1066c8 | FDE: 0x0445a0 | Size: 256 bytes
// Khung tháo gỡ #1133 | Địa chỉ PC: 0x1066c8 | Địa chỉ FDE: 0x0445a0 | Kích thước: 256 bytes
//   0x1066c8: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x1066cc: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x1066d0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1066d4: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1133_0x1066c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1066c8ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0445a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1134 | PC: 0x1069d0 | FDE: 0x0445d0 | Size: 256 bytes
// Khung tháo gỡ #1134 | Địa chỉ PC: 0x1069d0 | Địa chỉ FDE: 0x0445d0 | Kích thước: 256 bytes
//   0x1069d0: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x1069d4: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x1069d8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1069dc: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1134_0x1069d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1069d0ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0445d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1135 | PC: 0x10707c | FDE: 0x044600 | Size: 256 bytes
// Khung tháo gỡ #1135 | Địa chỉ PC: 0x10707c | Địa chỉ FDE: 0x044600 | Kích thước: 256 bytes
//   0x10707c: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x107080: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x107084: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x107088: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1135_0x10707c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10707cULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x044600ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1136 | PC: 0x1075d0 | FDE: 0x044630 | Size: 256 bytes
// Khung tháo gỡ #1136 | Địa chỉ PC: 0x1075d0 | Địa chỉ FDE: 0x044630 | Kích thước: 256 bytes
//   0x1075d0: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x1075d4: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x1075d8: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x1075dc: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1136_0x1075d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1075d0ULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x044630ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Shard 3 Dispatcher / Bộ điều phối phân mảnh 3
uint64_t execute_fde_shard_3(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 758: return fde_func_0758_0x0cbccc(a0, a1);
        case 759: return fde_func_0759_0x0cc0ec(a0, a1);
        case 760: return fde_func_0760_0x0ccadc(a0, a1);
        case 761: return fde_func_0761_0x0ccff4(a0, a1);
        case 762: return fde_func_0762_0x0cd368(a0, a1);
        case 763: return fde_func_0763_0x0cd400(a0, a1);
        case 764: return fde_func_0764_0x0cda0c(a0, a1);
        case 765: return fde_func_0765_0x0cdb90(a0, a1);
        case 766: return fde_func_0766_0x0cdf50(a0, a1);
        case 767: return fde_func_0767_0x0ce964(a0, a1);
        case 768: return fde_func_0768_0x0ceaa0(a0, a1);
        case 769: return fde_func_0769_0x0ced50(a0, a1);
        case 770: return fde_func_0770_0x0ceffc(a0, a1);
        case 771: return fde_func_0771_0x0cf53c(a0, a1);
        case 772: return fde_func_0772_0x0cf6b0(a0, a1);
        case 773: return fde_func_0773_0x0cf720(a0, a1);
        case 774: return fde_func_0774_0x0cfaf0(a0, a1);
        case 775: return fde_func_0775_0x0cfe6c(a0, a1);
        case 776: return fde_func_0776_0x0d0228(a0, a1);
        case 777: return fde_func_0777_0x0d0668(a0, a1);
        case 778: return fde_func_0778_0x0d07b0(a0, a1);
        case 779: return fde_func_0779_0x0d0b3c(a0, a1);
        case 780: return fde_func_0780_0x0d0bc8(a0, a1);
        case 781: return fde_func_0781_0x0d15b8(a0, a1);
        case 782: return fde_func_0782_0x0d18a0(a0, a1);
        case 783: return fde_func_0783_0x0d1c5c(a0, a1);
        case 784: return fde_func_0784_0x0d1e90(a0, a1);
        case 785: return fde_func_0785_0x0d2410(a0, a1);
        case 786: return fde_func_0786_0x0d2708(a0, a1);
        case 787: return fde_func_0787_0x0d298c(a0, a1);
        case 788: return fde_func_0788_0x0d2f64(a0, a1);
        case 789: return fde_func_0789_0x0d3114(a0, a1);
        case 790: return fde_func_0790_0x0d35fc(a0, a1);
        case 791: return fde_func_0791_0x0d3b94(a0, a1);
        case 792: return fde_func_0792_0x0d4588(a0, a1);
        case 793: return fde_func_0793_0x0d47fc(a0, a1);
        case 794: return fde_func_0794_0x0d4b54(a0, a1);
        case 795: return fde_func_0795_0x0d4e18(a0, a1);
        case 796: return fde_func_0796_0x0d5200(a0, a1);
        case 797: return fde_func_0797_0x0d5540(a0, a1);
        case 798: return fde_func_0798_0x0d55b8(a0, a1);
        case 799: return fde_func_0799_0x0d5b84(a0, a1);
        case 800: return fde_func_0800_0x0d5cfc(a0, a1);
        case 801: return fde_func_0801_0x0d5d30(a0, a1);
        case 802: return fde_func_0802_0x0d5e64(a0, a1);
        case 803: return fde_func_0803_0x0d5ee0(a0, a1);
        case 804: return fde_func_0804_0x0d6128(a0, a1);
        case 805: return fde_func_0805_0x0d6288(a0, a1);
        case 806: return fde_func_0806_0x0d6300(a0, a1);
        case 807: return fde_func_0807_0x0d6304(a0, a1);
        case 808: return fde_func_0808_0x0d64c0(a0, a1);
        case 809: return fde_func_0809_0x0d6664(a0, a1);
        case 810: return fde_func_0810_0x0d6850(a0, a1);
        case 811: return fde_func_0811_0x0d6914(a0, a1);
        case 812: return fde_func_0812_0x0d6990(a0, a1);
        case 813: return fde_func_0813_0x0d6cfc(a0, a1);
        case 814: return fde_func_0814_0x0d6f80(a0, a1);
        case 815: return fde_func_0815_0x0d715c(a0, a1);
        case 816: return fde_func_0816_0x0d7234(a0, a1);
        case 817: return fde_func_0817_0x0d7360(a0, a1);
        case 818: return fde_func_0818_0x0d7370(a0, a1);
        case 819: return fde_func_0819_0x0d7380(a0, a1);
        case 820: return fde_func_0820_0x0d7390(a0, a1);
        case 821: return fde_func_0821_0x0d77f8(a0, a1);
        case 822: return fde_func_0822_0x0d781c(a0, a1);
        case 823: return fde_func_0823_0x0d79f0(a0, a1);
        case 824: return fde_func_0824_0x0d7c60(a0, a1);
        case 825: return fde_func_0825_0x0d7f14(a0, a1);
        case 826: return fde_func_0826_0x0d83f8(a0, a1);
        case 827: return fde_func_0827_0x0d8630(a0, a1);
        case 828: return fde_func_0828_0x0d88d8(a0, a1);
        case 829: return fde_func_0829_0x0d88e8(a0, a1);
        case 830: return fde_func_0830_0x0d88fc(a0, a1);
        case 831: return fde_func_0831_0x0d8908(a0, a1);
        case 832: return fde_func_0832_0x0d8914(a0, a1);
        case 833: return fde_func_0833_0x0d893c(a0, a1);
        case 834: return fde_func_0834_0x0d896c(a0, a1);
        case 835: return fde_func_0835_0x0d8a04(a0, a1);
        case 836: return fde_func_0836_0x0d8aec(a0, a1);
        case 837: return fde_func_0837_0x0d8bb8(a0, a1);
        case 838: return fde_func_0838_0x0d8c74(a0, a1);
        case 839: return fde_func_0839_0x0d8dc4(a0, a1);
        case 840: return fde_func_0840_0x0d8e3c(a0, a1);
        case 841: return fde_func_0841_0x0d8e44(a0, a1);
        case 842: return fde_func_0842_0x0d8e48(a0, a1);
        case 843: return fde_func_0843_0x0d8f34(a0, a1);
        case 844: return fde_func_0844_0x0d8f4c(a0, a1);
        case 845: return fde_func_0845_0x0d8fc4(a0, a1);
        case 846: return fde_func_0846_0x0d9194(a0, a1);
        case 847: return fde_func_0847_0x0d9328(a0, a1);
        case 848: return fde_func_0848_0x0d933c(a0, a1);
        case 849: return fde_func_0849_0x0d9358(a0, a1);
        case 850: return fde_func_0850_0x0d9364(a0, a1);
        case 851: return fde_func_0851_0x0d9374(a0, a1);
        case 852: return fde_func_0852_0x0d9418(a0, a1);
        case 853: return fde_func_0853_0x0d9420(a0, a1);
        case 854: return fde_func_0854_0x0d9428(a0, a1);
        case 855: return fde_func_0855_0x0d9490(a0, a1);
        case 856: return fde_func_0856_0x0d9508(a0, a1);
        case 857: return fde_func_0857_0x0d9510(a0, a1);
        case 858: return fde_func_0858_0x0d9514(a0, a1);
        case 859: return fde_func_0859_0x0d9538(a0, a1);
        case 860: return fde_func_0860_0x0d9744(a0, a1);
        case 861: return fde_func_0861_0x0d98a4(a0, a1);
        case 862: return fde_func_0862_0x0d9a08(a0, a1);
        case 863: return fde_func_0863_0x0d9ca4(a0, a1);
        case 864: return fde_func_0864_0x0d9f2c(a0, a1);
        case 865: return fde_func_0865_0x0d9f78(a0, a1);
        case 866: return fde_func_0866_0x0d9fc4(a0, a1);
        case 867: return fde_func_0867_0x0da010(a0, a1);
        case 868: return fde_func_0868_0x0da018(a0, a1);
        case 869: return fde_func_0869_0x0da0f0(a0, a1);
        case 870: return fde_func_0870_0x0da0f4(a0, a1);
        case 871: return fde_func_0871_0x0da0f8(a0, a1);
        case 872: return fde_func_0872_0x0da124(a0, a1);
        case 873: return fde_func_0873_0x0da200(a0, a1);
        case 874: return fde_func_0874_0x0da2ec(a0, a1);
        case 875: return fde_func_0875_0x0da3e0(a0, a1);
        case 876: return fde_func_0876_0x0da3fc(a0, a1);
        case 877: return fde_func_0877_0x0da620(a0, a1);
        case 878: return fde_func_0878_0x0da8b0(a0, a1);
        case 879: return fde_func_0879_0x0da918(a0, a1);
        case 880: return fde_func_0880_0x0daab0(a0, a1);
        case 881: return fde_func_0881_0x0dac34(a0, a1);
        case 882: return fde_func_0882_0x0dacc8(a0, a1);
        case 883: return fde_func_0883_0x0daccc(a0, a1);
        case 884: return fde_func_0884_0x0dadd4(a0, a1);
        case 885: return fde_func_0885_0x0dafdc(a0, a1);
        case 886: return fde_func_0886_0x0db068(a0, a1);
        case 887: return fde_func_0887_0x0db1f0(a0, a1);
        case 888: return fde_func_0888_0x0db23c(a0, a1);
        case 889: return fde_func_0889_0x0db240(a0, a1);
        case 890: return fde_func_0890_0x0db2a0(a0, a1);
        case 891: return fde_func_0891_0x0db318(a0, a1);
        case 892: return fde_func_0892_0x0db380(a0, a1);
        case 893: return fde_func_0893_0x0db5b8(a0, a1);
        case 894: return fde_func_0894_0x0db8b4(a0, a1);
        case 895: return fde_func_0895_0x0dbbdc(a0, a1);
        case 896: return fde_func_0896_0x0dbd18(a0, a1);
        case 897: return fde_func_0897_0x0dbef0(a0, a1);
        case 898: return fde_func_0898_0x0dc040(a0, a1);
        case 899: return fde_func_0899_0x0dc0b8(a0, a1);
        case 900: return fde_func_0900_0x0dc11c(a0, a1);
        case 901: return fde_func_0901_0x0dc198(a0, a1);
        case 902: return fde_func_0902_0x0dc5e8(a0, a1);
        case 903: return fde_func_0903_0x0dc624(a0, a1);
        case 904: return fde_func_0904_0x0dc62c(a0, a1);
        case 905: return fde_func_0905_0x0dc640(a0, a1);
        case 906: return fde_func_0906_0x0dc6c8(a0, a1);
        case 907: return fde_func_0907_0x0dce7c(a0, a1);
        case 908: return fde_func_0908_0x0dce88(a0, a1);
        case 909: return fde_func_0909_0x0dcee4(a0, a1);
        case 910: return fde_func_0910_0x0dd010(a0, a1);
        case 911: return fde_func_0911_0x0dd018(a0, a1);
        case 912: return fde_func_0912_0x0dd53c(a0, a1);
        case 913: return fde_func_0913_0x0dd848(a0, a1);
        case 914: return fde_func_0914_0x0dd9a8(a0, a1);
        case 915: return fde_func_0915_0x0dd9f8(a0, a1);
        case 916: return fde_func_0916_0x0dda9c(a0, a1);
        case 917: return fde_func_0917_0x0ddaac(a0, a1);
        case 918: return fde_func_0918_0x0ddabc(a0, a1);
        case 919: return fde_func_0919_0x0ddaf8(a0, a1);
        case 920: return fde_func_0920_0x0ddb00(a0, a1);
        case 921: return fde_func_0921_0x0ddb08(a0, a1);
        case 922: return fde_func_0922_0x0ddb10(a0, a1);
        case 923: return fde_func_0923_0x0ddb38(a0, a1);
        case 924: return fde_func_0924_0x0ddb54(a0, a1);
        case 925: return fde_func_0925_0x0ddc0c(a0, a1);
        case 926: return fde_func_0926_0x0ddcec(a0, a1);
        case 927: return fde_func_0927_0x0dde6c(a0, a1);
        case 928: return fde_func_0928_0x0ddf30(a0, a1);
        case 929: return fde_func_0929_0x0ddf94(a0, a1);
        case 930: return fde_func_0930_0x0ddff4(a0, a1);
        case 931: return fde_func_0931_0x0de134(a0, a1);
        case 932: return fde_func_0932_0x0de13c(a0, a1);
        case 933: return fde_func_0933_0x0de17c(a0, a1);
        case 934: return fde_func_0934_0x0de1bc(a0, a1);
        case 935: return fde_func_0935_0x0de41c(a0, a1);
        case 936: return fde_func_0936_0x0de920(a0, a1);
        case 937: return fde_func_0937_0x0de958(a0, a1);
        case 938: return fde_func_0938_0x0deaa0(a0, a1);
        case 939: return fde_func_0939_0x0dec18(a0, a1);
        case 940: return fde_func_0940_0x0dec78(a0, a1);
        case 941: return fde_func_0941_0x0df078(a0, a1);
        case 942: return fde_func_0942_0x0df830(a0, a1);
        case 943: return fde_func_0943_0x0dfa04(a0, a1);
        case 944: return fde_func_0944_0x0e01fc(a0, a1);
        case 945: return fde_func_0945_0x0e0200(a0, a1);
        case 946: return fde_func_0946_0x0e0540(a0, a1);
        case 947: return fde_func_0947_0x0e06fc(a0, a1);
        case 948: return fde_func_0948_0x0e0dd8(a0, a1);
        case 949: return fde_func_0949_0x0e14cc(a0, a1);
        case 950: return fde_func_0950_0x0e14f0(a0, a1);
        case 951: return fde_func_0951_0x0e151c(a0, a1);
        case 952: return fde_func_0952_0x0e161c(a0, a1);
        case 953: return fde_func_0953_0x0e183c(a0, a1);
        case 954: return fde_func_0954_0x0e1920(a0, a1);
        case 955: return fde_func_0955_0x0e1934(a0, a1);
        case 956: return fde_func_0956_0x0e194c(a0, a1);
        case 957: return fde_func_0957_0x0e19c4(a0, a1);
        case 958: return fde_func_0958_0x0e1a2c(a0, a1);
        case 959: return fde_func_0959_0x0e1a3c(a0, a1);
        case 960: return fde_func_0960_0x0e1ab4(a0, a1);
        case 961: return fde_func_0961_0x0e1b58(a0, a1);
        case 962: return fde_func_0962_0x0e1bb8(a0, a1);
        case 963: return fde_func_0963_0x0e1c14(a0, a1);
        case 964: return fde_func_0964_0x0e1cbc(a0, a1);
        case 965: return fde_func_0965_0x0e1d78(a0, a1);
        case 966: return fde_func_0966_0x0e1d8c(a0, a1);
        case 967: return fde_func_0967_0x0e1da0(a0, a1);
        case 968: return fde_func_0968_0x0e1da8(a0, a1);
        case 969: return fde_func_0969_0x0e1e94(a0, a1);
        case 970: return fde_func_0970_0x0e1f34(a0, a1);
        case 971: return fde_func_0971_0x0e1fa8(a0, a1);
        case 972: return fde_func_0972_0x0e2040(a0, a1);
        case 973: return fde_func_0973_0x0e20cc(a0, a1);
        case 974: return fde_func_0974_0x0e2448(a0, a1);
        case 975: return fde_func_0975_0x0e247c(a0, a1);
        case 976: return fde_func_0976_0x0e249c(a0, a1);
        case 977: return fde_func_0977_0x0e24ac(a0, a1);
        case 978: return fde_func_0978_0x0e24c8(a0, a1);
        case 979: return fde_func_0979_0x0e24d4(a0, a1);
        case 980: return fde_func_0980_0x0e24f4(a0, a1);
        case 981: return fde_func_0981_0x0e2510(a0, a1);
        case 982: return fde_func_0982_0x0e2544(a0, a1);
        case 983: return fde_func_0983_0x0e263c(a0, a1);
        case 984: return fde_func_0984_0x0e2744(a0, a1);
        case 985: return fde_func_0985_0x0e2800(a0, a1);
        case 986: return fde_func_0986_0x0e29ac(a0, a1);
        case 987: return fde_func_0987_0x0e2a80(a0, a1);
        case 988: return fde_func_0988_0x0e2b3c(a0, a1);
        case 989: return fde_func_0989_0x0e2c84(a0, a1);
        case 990: return fde_func_0990_0x0e2da8(a0, a1);
        case 991: return fde_func_0991_0x0e3268(a0, a1);
        case 992: return fde_func_0992_0x0e37d0(a0, a1);
        case 993: return fde_func_0993_0x0e3844(a0, a1);
        case 994: return fde_func_0994_0x0e38a0(a0, a1);
        case 995: return fde_func_0995_0x0e390c(a0, a1);
        case 996: return fde_func_0996_0x0e3970(a0, a1);
        case 997: return fde_func_0997_0x0e3aa8(a0, a1);
        case 998: return fde_func_0998_0x0e3b2c(a0, a1);
        case 999: return fde_func_0999_0x0e3b5c(a0, a1);
        case 1000: return fde_func_1000_0x0e3ba8(a0, a1);
        case 1001: return fde_func_1001_0x0e3be8(a0, a1);
        case 1002: return fde_func_1002_0x0e3d14(a0, a1);
        case 1003: return fde_func_1003_0x0e3d58(a0, a1);
        case 1004: return fde_func_1004_0x0e3ddc(a0, a1);
        case 1005: return fde_func_1005_0x0e3e4c(a0, a1);
        case 1006: return fde_func_1006_0x0e3f84(a0, a1);
        case 1007: return fde_func_1007_0x0e403c(a0, a1);
        case 1008: return fde_func_1008_0x0e44c4(a0, a1);
        case 1009: return fde_func_1009_0x0e4ea0(a0, a1);
        case 1010: return fde_func_1010_0x0e4ef4(a0, a1);
        case 1011: return fde_func_1011_0x0e4fac(a0, a1);
        case 1012: return fde_func_1012_0x0e5014(a0, a1);
        case 1013: return fde_func_1013_0x0e50e8(a0, a1);
        case 1014: return fde_func_1014_0x0e51b4(a0, a1);
        case 1015: return fde_func_1015_0x0e51d0(a0, a1);
        case 1016: return fde_func_1016_0x0e52c4(a0, a1);
        case 1017: return fde_func_1017_0x0e52f8(a0, a1);
        case 1018: return fde_func_1018_0x0e5360(a0, a1);
        case 1019: return fde_func_1019_0x0e5560(a0, a1);
        case 1020: return fde_func_1020_0x0e5588(a0, a1);
        case 1021: return fde_func_1021_0x0e55b0(a0, a1);
        case 1022: return fde_func_1022_0x0e55ec(a0, a1);
        case 1023: return fde_func_1023_0x0e5668(a0, a1);
        case 1024: return fde_func_1024_0x0e56cc(a0, a1);
        case 1025: return fde_func_1025_0x0e5720(a0, a1);
        case 1026: return fde_func_1026_0x0e5768(a0, a1);
        case 1027: return fde_func_1027_0x0e57b8(a0, a1);
        case 1028: return fde_func_1028_0x0e57cc(a0, a1);
        case 1029: return fde_func_1029_0x0e5800(a0, a1);
        case 1030: return fde_func_1030_0x0e5860(a0, a1);
        case 1031: return fde_func_1031_0x0e58b4(a0, a1);
        case 1032: return fde_func_1032_0x0e58c8(a0, a1);
        case 1033: return fde_func_1033_0x0e59dc(a0, a1);
        case 1034: return fde_func_1034_0x0e5a74(a0, a1);
        case 1035: return fde_func_1035_0x0e5ac0(a0, a1);
        case 1036: return fde_func_1036_0x0e5aec(a0, a1);
        case 1037: return fde_func_1037_0x0e5b14(a0, a1);
        case 1038: return fde_func_1038_0x0e5b24(a0, a1);
        case 1039: return fde_func_1039_0x0e5b4c(a0, a1);
        case 1040: return fde_func_1040_0x0e5bd8(a0, a1);
        case 1041: return fde_func_1041_0x0e5c10(a0, a1);
        case 1042: return fde_func_1042_0x0e5c7c(a0, a1);
        case 1043: return fde_func_1043_0x0e5cc8(a0, a1);
        case 1044: return fde_func_1044_0x0e5cf4(a0, a1);
        case 1045: return fde_func_1045_0x0e5d04(a0, a1);
        case 1046: return fde_func_1046_0x0e5d18(a0, a1);
        case 1047: return fde_func_1047_0x0e5d78(a0, a1);
        case 1048: return fde_func_1048_0x0e5e54(a0, a1);
        case 1049: return fde_func_1049_0x0e5ea8(a0, a1);
        case 1050: return fde_func_1050_0x0e5eb8(a0, a1);
        case 1051: return fde_func_1051_0x0e5f5c(a0, a1);
        case 1052: return fde_func_1052_0x0e5ffc(a0, a1);
        case 1053: return fde_func_1053_0x0e61c8(a0, a1);
        case 1054: return fde_func_1054_0x0e6368(a0, a1);
        case 1055: return fde_func_1055_0x0e6438(a0, a1);
        case 1056: return fde_func_1056_0x0e6464(a0, a1);
        case 1057: return fde_func_1057_0x0e66cc(a0, a1);
        case 1058: return fde_func_1058_0x0e6790(a0, a1);
        case 1059: return fde_func_1059_0x0e6864(a0, a1);
        case 1060: return fde_func_1060_0x0e694c(a0, a1);
        case 1061: return fde_func_1061_0x0e6a44(a0, a1);
        case 1062: return fde_func_1062_0x0e6cb4(a0, a1);
        case 1063: return fde_func_1063_0x0e6ea8(a0, a1);
        case 1064: return fde_func_1064_0x0e6ee0(a0, a1);
        case 1065: return fde_func_1065_0x0e6f28(a0, a1);
        case 1066: return fde_func_1066_0x0e743c(a0, a1);
        case 1067: return fde_func_1067_0x0e7d2c(a0, a1);
        case 1068: return fde_func_1068_0x0e8070(a0, a1);
        case 1069: return fde_func_1069_0x0e84ec(a0, a1);
        case 1070: return fde_func_1070_0x0e8550(a0, a1);
        case 1071: return fde_func_1071_0x0e8b1c(a0, a1);
        case 1072: return fde_func_1072_0x0e8bbc(a0, a1);
        case 1073: return fde_func_1073_0x0e8c60(a0, a1);
        case 1074: return fde_func_1074_0x0e8dd4(a0, a1);
        case 1075: return fde_func_1075_0x0e93c4(a0, a1);
        case 1076: return fde_func_1076_0x0e94f8(a0, a1);
        case 1077: return fde_func_1077_0x0e98c8(a0, a1);
        case 1078: return fde_func_1078_0x0ea048(a0, a1);
        case 1079: return fde_func_1079_0x0ea13c(a0, a1);
        case 1080: return fde_func_1080_0x0ea250(a0, a1);
        case 1081: return fde_func_1081_0x0ea384(a0, a1);
        case 1082: return fde_func_1082_0x0f6850(a0, a1);
        case 1083: return fde_func_1083_0x0f6c58(a0, a1);
        case 1084: return fde_func_1084_0x0f7000(a0, a1);
        case 1085: return fde_func_1085_0x0f7a8c(a0, a1);
        case 1086: return fde_func_1086_0x0f7bb8(a0, a1);
        case 1087: return fde_func_1087_0x0f8174(a0, a1);
        case 1088: return fde_func_1088_0x0f8260(a0, a1);
        case 1089: return fde_func_1089_0x0f83bc(a0, a1);
        case 1090: return fde_func_1090_0x0f861c(a0, a1);
        case 1091: return fde_func_1091_0x0f89c4(a0, a1);
        case 1092: return fde_func_1092_0x0f8d34(a0, a1);
        case 1093: return fde_func_1093_0x0f9034(a0, a1);
        case 1094: return fde_func_1094_0x0f90d4(a0, a1);
        case 1095: return fde_func_1095_0x0f9220(a0, a1);
        case 1096: return fde_func_1096_0x0f93bc(a0, a1);
        case 1097: return fde_func_1097_0x0f945c(a0, a1);
        case 1098: return fde_func_1098_0x0f94fc(a0, a1);
        case 1099: return fde_func_1099_0x0f96c4(a0, a1);
        case 1100: return fde_func_1100_0x0f9ab8(a0, a1);
        case 1101: return fde_func_1101_0x0fa098(a0, a1);
        case 1102: return fde_func_1102_0x0fabd8(a0, a1);
        case 1103: return fde_func_1103_0x0fae2c(a0, a1);
        case 1104: return fde_func_1104_0x0fafb8(a0, a1);
        case 1105: return fde_func_1105_0x0fb2ec(a0, a1);
        case 1106: return fde_func_1106_0x0fb570(a0, a1);
        case 1107: return fde_func_1107_0x0fcf10(a0, a1);
        case 1108: return fde_func_1108_0x0fd0f0(a0, a1);
        case 1109: return fde_func_1109_0x0fd294(a0, a1);
        case 1110: return fde_func_1110_0x0fd550(a0, a1);
        case 1111: return fde_func_1111_0x0fe1a0(a0, a1);
        case 1112: return fde_func_1112_0x0fe294(a0, a1);
        case 1113: return fde_func_1113_0x0ff764(a0, a1);
        case 1114: return fde_func_1114_0x0ff864(a0, a1);
        case 1115: return fde_func_1115_0x0ffc8c(a0, a1);
        case 1116: return fde_func_1116_0x100660(a0, a1);
        case 1117: return fde_func_1117_0x100950(a0, a1);
        case 1118: return fde_func_1118_0x100ea8(a0, a1);
        case 1119: return fde_func_1119_0x10107c(a0, a1);
        case 1120: return fde_func_1120_0x1011e8(a0, a1);
        case 1121: return fde_func_1121_0x101e40(a0, a1);
        case 1122: return fde_func_1122_0x102244(a0, a1);
        case 1123: return fde_func_1123_0x102cfc(a0, a1);
        case 1124: return fde_func_1124_0x10359c(a0, a1);
        case 1125: return fde_func_1125_0x1037c0(a0, a1);
        case 1126: return fde_func_1126_0x103aa8(a0, a1);
        case 1127: return fde_func_1127_0x104440(a0, a1);
        case 1128: return fde_func_1128_0x104c24(a0, a1);
        case 1129: return fde_func_1129_0x105400(a0, a1);
        case 1130: return fde_func_1130_0x1057b0(a0, a1);
        case 1131: return fde_func_1131_0x106108(a0, a1);
        case 1132: return fde_func_1132_0x1065dc(a0, a1);
        case 1133: return fde_func_1133_0x1066c8(a0, a1);
        case 1134: return fde_func_1134_0x1069d0(a0, a1);
        case 1135: return fde_func_1135_0x10707c(a0, a1);
        case 1136: return fde_func_1136_0x1075d0(a0, a1);
        default: return 0ULL;
    }
}