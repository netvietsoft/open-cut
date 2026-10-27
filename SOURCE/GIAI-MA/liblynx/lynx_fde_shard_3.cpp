// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 3/5 for liblynx.so
// Phân mảnh Khung Tháo Gỡ (FDE) AArch64 C++17 sạch 3/5 cho liblynx.so
// Covers representative FDE indices [800 .. 1199] out of 21,675 total FDEs
// Bao phủ chỉ số FDE đại diện [800 .. 1199] trên tổng số 21.675 FDE
// ============================================================================
#include "lynx_core.h"

namespace lynx {

// FDE #0800 | PC: 0x22bbc8 | FDE: 0x0e1a80 | Size: 156 bytes [_ZN4lynx4tasm9Catalyzer15GetRectToWindowEPNS0_7ElementE]
// Khung tháo gỡ #0800 | Địa chỉ PC: 0x22bbc8 | Địa chỉ FDE: 0x0e1a80 | Kích thước: 156 bytes
//   0x22bbc8: F9400409  ldr      x9, [x0, #8]
//   0x22bbcc: B9404821  ldr      w1, [x1, #0x48]
//   0x22bbd0: F9400520  ldr      x0, [x9, #8]
//   0x22bbd4: F9400009  ldr      x9, [x0]
static inline uint64_t fde_func_0800_0x22bbc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x22bbc8ULL ^ (static_cast<uint64_t>(0xf9400409ULL) << 13);
    acc = (acc + a1 + 0xb9404821ULL) ^ 0x0e1a80ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0801 | PC: 0x22bc64 | FDE: 0x0e1ab8 | Size: 256 bytes
// Khung tháo gỡ #0801 | Địa chỉ PC: 0x22bc64 | Địa chỉ FDE: 0x0e1ab8 | Kích thước: 256 bytes
//   0x22bc64: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x22bc68: B9000FE1  str      w1, [sp, #0xc]
//   0x22bc6c: 91008000  add      x0, x0, #0x20
//   0x22bc70: 94042337  bl       #0x33494c
static inline uint64_t fde_func_0801_0x22bc64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x22bc64ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb9000fe1ULL) ^ 0x0e1ab8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0802 | PC: 0x22bf54 | FDE: 0x0e1bd0 | Size: 256 bytes
// Khung tháo gỡ #0802 | Địa chỉ PC: 0x22bf54 | Địa chỉ FDE: 0x0e1bd0 | Kích thước: 256 bytes
//   0x22bf54: F9400408  ldr      x8, [x0, #8]
//   0x22bf58: 29430801  ldp      w1, w2, [x0, #0x18]
//   0x22bf5c: B9402003  ldr      w3, [x0, #0x20]
//   0x22bf60: 39409004  ldrb     w4, [x0, #0x24]
static inline uint64_t fde_func_0802_0x22bf54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x22bf54ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x29430801ULL) ^ 0x0e1bd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0803 | PC: 0x22c21c | FDE: 0x0e1ce0 | Size: 256 bytes
// Khung tháo gỡ #0803 | Địa chỉ PC: 0x22c21c | Địa chỉ FDE: 0x0e1ce0 | Kích thước: 256 bytes
//   0x22c21c: D10103FF  sub      sp, sp, #0x40
//   0x22c220: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x22c224: 94040AB1  bl       #0x32ece8
//   0x22c228: A940A109  ldp      x9, x8, [x8, #8]
static inline uint64_t fde_func_0803_0x22c21c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x22c21cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9037bf3ULL) ^ 0x0e1ce0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0804 | PC: 0x22c478 | FDE: 0x0e1de8 | Size: 256 bytes
// Khung tháo gỡ #0804 | Địa chỉ PC: 0x22c478 | Địa chỉ FDE: 0x0e1de8 | Kích thước: 256 bytes
//   0x22c478: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x22c47c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x22c480: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x22c484: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0804_0x22c478(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x22c478ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0e1de8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0805 | PC: 0x22c658 | FDE: 0x0e1ef8 | Size: 256 bytes
// Khung tháo gỡ #0805 | Địa chỉ PC: 0x22c658 | Địa chỉ FDE: 0x0e1ef8 | Kích thước: 256 bytes
//   0x22c658: D0000928  adrp     x8, #0x352000
//   0x22c65c: 91302108  add      x8, x8, #0xc08
//   0x22c660: F8008408  str      x8, [x0], #8
//   0x22c664: 17FFFFF6  b        #0x22c63c
static inline uint64_t fde_func_0805_0x22c658(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x22c658ULL ^ (static_cast<uint64_t>(0xd0000928ULL) << 13);
    acc = (acc + a1 + 0x91302108ULL) ^ 0x0e1ef8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0806 | PC: 0x22c84c | FDE: 0x0e1ff8 | Size: 256 bytes
// Khung tháo gỡ #0806 | Địa chỉ PC: 0x22c84c | Địa chỉ FDE: 0x0e1ff8 | Kích thước: 256 bytes
//   0x22c84c: F9400408  ldr      x8, [x0, #8]
//   0x22c850: F940100A  ldr      x10, [x0, #0x20]
//   0x22c854: B9401801  ldr      w1, [x0, #0x18]
//   0x22c858: 39407002  ldrb     w2, [x0, #0x1c]
static inline uint64_t fde_func_0806_0x22c84c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x22c84cULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf940100aULL) ^ 0x0e1ff8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0807 | PC: 0x22ca3c | FDE: 0x0e2110 | Size: 256 bytes
// Khung tháo gỡ #0807 | Địa chỉ PC: 0x22ca3c | Địa chỉ FDE: 0x0e2110 | Kích thước: 256 bytes
//   0x22ca3c: F9400808  ldr      x8, [x0, #0x10]
//   0x22ca40: D0000929  adrp     x9, #0x352000
//   0x22ca44: 91334129  add      x9, x9, #0xcd0
//   0x22ca48: 1403C0D6  b        #0x31cda0
static inline uint64_t fde_func_0807_0x22ca3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x22ca3cULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xd0000929ULL) ^ 0x0e2110ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0808 | PC: 0x22cca8 | FDE: 0x0e2228 | Size: 256 bytes
// Khung tháo gỡ #0808 | Địa chỉ PC: 0x22cca8 | Địa chỉ FDE: 0x0e2228 | Kích thước: 256 bytes
//   0x22cca8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x22ccac: AA0003F3  mov      x19, x0
//   0x22ccb0: 97FFFFFA  bl       #0x22cc98
//   0x22ccb4: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0808_0x22cca8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x22cca8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0e2228ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0809 | PC: 0x22ce28 | FDE: 0x0e2320 | Size: 256 bytes
// Khung tháo gỡ #0809 | Địa chỉ PC: 0x22ce28 | Địa chỉ FDE: 0x0e2320 | Kích thước: 256 bytes
//   0x22ce28: D10143FF  sub      sp, sp, #0x50
//   0x22ce2c: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x22ce30: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x22ce34: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0809_0x22ce28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x22ce28ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x0e2320ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0810 | PC: 0x22d284 | FDE: 0x0e2450 | Size: 256 bytes
// Khung tháo gỡ #0810 | Địa chỉ PC: 0x22d284 | Địa chỉ FDE: 0x0e2450 | Kích thước: 256 bytes
//   0x22d284: 2A0103E9  mov      w9, w1
//   0x22d288: 92800008  mov      x8, #-1
//   0x22d28c: B40000A9  cbz      x9, #0x22d2a0
//   0x22d290: AA1E03E1  mov      x1, x30
static inline uint64_t fde_func_0810_0x22d284(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x22d284ULL ^ (static_cast<uint64_t>(0x2a0103e9ULL) << 13);
    acc = (acc + a1 + 0x92800008ULL) ^ 0x0e2450ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0811 | PC: 0x22d418 | FDE: 0x0e2558 | Size: 256 bytes
// Khung tháo gỡ #0811 | Địa chỉ PC: 0x22d418 | Địa chỉ FDE: 0x0e2558 | Kích thước: 256 bytes
//   0x22d418: 1403D1F9  b        #0x321bfc
//   0x22d41c: F9400029  ldr      x9, [x1]
//   0x22d420: F9000109  str      x9, [x8]
//   0x22d424: F900003F  str      xzr, [x1]
static inline uint64_t fde_func_0811_0x22d418(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x22d418ULL ^ (static_cast<uint64_t>(0x1403d1f9ULL) << 13);
    acc = (acc + a1 + 0xf9400029ULL) ^ 0x0e2558ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0812 | PC: 0x22d66c | FDE: 0x0e2670 | Size: 256 bytes
// Khung tháo gỡ #0812 | Địa chỉ PC: 0x22d66c | Địa chỉ FDE: 0x0e2670 | Kích thước: 256 bytes
//   0x22d66c: D100A000  sub      x0, x0, #0x28
//   0x22d670: 17FFFF77  b        #0x22d44c
//   0x22d674: D100A000  sub      x0, x0, #0x28
//   0x22d678: 17FFFF91  b        #0x22d4bc
static inline uint64_t fde_func_0812_0x22d66c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x22d66cULL ^ (static_cast<uint64_t>(0xd100a000ULL) << 13);
    acc = (acc + a1 + 0x17ffff77ULL) ^ 0x0e2670ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0813 | PC: 0x22dce0 | FDE: 0x0e27a0 | Size: 256 bytes
// Khung tháo gỡ #0813 | Địa chỉ PC: 0x22dce0 | Địa chỉ FDE: 0x0e27a0 | Kích thước: 256 bytes
//   0x22dce0: AA1E03E2  mov      x2, x30
//   0x22dce4: 9403C68A  bl       #0x31f70c
//   0x22dce8: AA0203FE  mov      x30, x2
//   0x22dcec: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0813_0x22dce0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x22dce0ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9403c68aULL) ^ 0x0e27a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0814 | PC: 0x22e3d8 | FDE: 0x0e28d0 | Size: 256 bytes
// Khung tháo gỡ #0814 | Địa chỉ PC: 0x22e3d8 | Địa chỉ FDE: 0x0e28d0 | Kích thước: 256 bytes
//   0x22e3d8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x22e3dc: 9403C1A7  bl       #0x31ea78
//   0x22e3e0: B0000928  adrp     x8, #0x353000
//   0x22e3e4: 91030108  add      x8, x8, #0xc0
static inline uint64_t fde_func_0814_0x22e3d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x22e3d8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9403c1a7ULL) ^ 0x0e28d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0815 | PC: 0x22e9f0 | FDE: 0x0e2a10 | Size: 256 bytes
// Khung tháo gỡ #0815 | Địa chỉ PC: 0x22e9f0 | Địa chỉ FDE: 0x0e2a10 | Kích thước: 256 bytes
//   0x22e9f0: AA1E03E4  mov      x4, x30
//   0x22e9f4: 9403C032  bl       #0x31eabc
//   0x22e9f8: AA0403FE  mov      x30, x4
//   0x22e9fc: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0815_0x22e9f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x22e9f0ULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x9403c032ULL) ^ 0x0e2a10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0816 | PC: 0x22f058 | FDE: 0x0e2b68 | Size: 256 bytes
// Khung tháo gỡ #0816 | Địa chỉ PC: 0x22f058 | Địa chỉ FDE: 0x0e2b68 | Kích thước: 256 bytes
//   0x22f058: D10183FF  sub      sp, sp, #0x60
//   0x22f05c: FD0013EA  str      d10, [sp, #0x20]
//   0x22f060: 6D02A3E9  stp      d9, d8, [sp, #0x28]
//   0x22f064: F9001FF6  str      x22, [sp, #0x38]
static inline uint64_t fde_func_0816_0x22f058(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x22f058ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xfd0013eaULL) ^ 0x0e2b68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0817 | PC: 0x22f350 | FDE: 0x0e2c90 | Size: 256 bytes
// Khung tháo gỡ #0817 | Địa chỉ PC: 0x22f350 | Địa chỉ FDE: 0x0e2c90 | Kích thước: 256 bytes
//   0x22f350: 91006000  add      x0, x0, #0x18
//   0x22f354: 17FFEB4E  b        #0x22a08c
//   0x22f358: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x22f35c: A9017BF3  stp      x19, x30, [sp, #0x10]
static inline uint64_t fde_func_0817_0x22f350(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x22f350ULL ^ (static_cast<uint64_t>(0x91006000ULL) << 13);
    acc = (acc + a1 + 0x17ffeb4eULL) ^ 0x0e2c90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0818 | PC: 0x22fad8 | FDE: 0x0e2dc8 | Size: 256 bytes
// Khung tháo gỡ #0818 | Địa chỉ PC: 0x22fad8 | Địa chỉ FDE: 0x0e2dc8 | Kích thước: 256 bytes
//   0x22fad8: D10503FF  sub      sp, sp, #0x140
//   0x22fadc: FD0073E8  str      d8, [sp, #0xe0]
//   0x22fae0: F90077FC  str      x28, [sp, #0xe8]
//   0x22fae4: A90F6BFB  stp      x27, x26, [sp, #0xf0]
static inline uint64_t fde_func_0818_0x22fad8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x22fad8ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xfd0073e8ULL) ^ 0x0e2dc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0819 | PC: 0x230630 | FDE: 0x0e2f40 | Size: 256 bytes
// Khung tháo gỡ #0819 | Địa chỉ PC: 0x230630 | Địa chỉ FDE: 0x0e2f40 | Kích thước: 256 bytes
//   0x230630: AA1E03E2  mov      x2, x30
//   0x230634: 9403B991  bl       #0x31ec78
//   0x230638: AA0203FE  mov      x30, x2
//   0x23063c: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_0819_0x230630(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x230630ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9403b991ULL) ^ 0x0e2f40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0820 | PC: 0x231240 | FDE: 0x0e30d0 | Size: 256 bytes
// Khung tháo gỡ #0820 | Địa chỉ PC: 0x231240 | Địa chỉ FDE: 0x0e30d0 | Kích thước: 256 bytes
//   0x231240: F9400020  ldr      x0, [x1]
//   0x231244: B4000080  cbz      x0, #0x231254
//   0x231248: F9400008  ldr      x8, [x0]
//   0x23124c: 2A1F03E1  mov      w1, wzr
static inline uint64_t fde_func_0820_0x231240(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x231240ULL ^ (static_cast<uint64_t>(0xf9400020ULL) << 13);
    acc = (acc + a1 + 0xb4000080ULL) ^ 0x0e30d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0821 | PC: 0x231970 | FDE: 0x0e3208 | Size: 256 bytes
// Khung tháo gỡ #0821 | Địa chỉ PC: 0x231970 | Địa chỉ FDE: 0x0e3208 | Kích thước: 256 bytes
//   0x231970: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x231974: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x231978: 9403AB88  bl       #0x31c798
//   0x23197c: 94043D95  bl       #0x340fd0
static inline uint64_t fde_func_0821_0x231970(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x231970ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0e3208ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0822 | PC: 0x231cf8 | FDE: 0x0e3320 | Size: 256 bytes
// Khung tháo gỡ #0822 | Địa chỉ PC: 0x231cf8 | Địa chỉ FDE: 0x0e3320 | Kích thước: 256 bytes
//   0x231cf8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x231cfc: 9403C99D  bl       #0x324370
//   0x231d00: F9400660  ldr      x0, [x19, #8]
//   0x231d04: A8C17BF3  ldp      x19, x30, [sp], #0x10
static inline uint64_t fde_func_0822_0x231cf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x231cf8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9403c99dULL) ^ 0x0e3320ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0823 | PC: 0x231e98 | FDE: 0x0e3428 | Size: 256 bytes
// Khung tháo gỡ #0823 | Địa chỉ PC: 0x231e98 | Địa chỉ FDE: 0x0e3428 | Kích thước: 256 bytes
//   0x231e98: AA1E03E1  mov      x1, x30
//   0x231e9c: 9403B308  bl       #0x31eabc
//   0x231ea0: AA0103FE  mov      x30, x1
//   0x231ea4: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0823_0x231e98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x231e98ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x9403b308ULL) ^ 0x0e3428ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0824 | PC: 0x2320cc | FDE: 0x0e3538 | Size: 256 bytes
// Khung tháo gỡ #0824 | Địa chỉ PC: 0x2320cc | Địa chỉ FDE: 0x0e3538 | Kích thước: 256 bytes
//   0x2320cc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2320d0: 9403A984  bl       #0x31c6e0
//   0x2320d4: 97FFE565  bl       #0x22b668
//   0x2320d8: F9400660  ldr      x0, [x19, #8]
static inline uint64_t fde_func_0824_0x2320cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2320ccULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9403a984ULL) ^ 0x0e3538ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0825 | PC: 0x2322b0 | FDE: 0x0e3640 | Size: 256 bytes
// Khung tháo gỡ #0825 | Địa chỉ PC: 0x2322b0 | Địa chỉ FDE: 0x0e3640 | Kích thước: 256 bytes
//   0x2322b0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2322b4: 9403ACB8  bl       #0x31d594
//   0x2322b8: 97FCC66D  bl       #0x163c6c
//   0x2322bc: F9400660  ldr      x0, [x19, #8]
static inline uint64_t fde_func_0825_0x2322b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2322b0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9403acb8ULL) ^ 0x0e3640ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0826 | PC: 0x232534 | FDE: 0x0e3750 | Size: 256 bytes
// Khung tháo gỡ #0826 | Địa chỉ PC: 0x232534 | Địa chỉ FDE: 0x0e3750 | Kích thước: 256 bytes
//   0x232534: B0000908  adrp     x8, #0x353000
//   0x232538: 911CC108  add      x8, x8, #0x730
//   0x23253c: F8008408  str      x8, [x0], #8
//   0x232540: 17FFFFF7  b        #0x23251c
static inline uint64_t fde_func_0826_0x232534(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x232534ULL ^ (static_cast<uint64_t>(0xb0000908ULL) << 13);
    acc = (acc + a1 + 0x911cc108ULL) ^ 0x0e3750ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0827 | PC: 0x233a80 | FDE: 0x0e38d0 | Size: 256 bytes
// Khung tháo gỡ #0827 | Địa chỉ PC: 0x233a80 | Địa chỉ FDE: 0x0e38d0 | Kích thước: 256 bytes
//   0x233a80: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x233a84: 9403A365  bl       #0x31c818
//   0x233a88: B4000113  cbz      x19, #0x233aa8
//   0x233a8c: 39404008  ldrb     w8, [x0, #0x10]
static inline uint64_t fde_func_0827_0x233a80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x233a80ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9403a365ULL) ^ 0x0e38d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0828 | PC: 0x233c08 | FDE: 0x0e39e0 | Size: 256 bytes
// Khung tháo gỡ #0828 | Địa chỉ PC: 0x233c08 | Địa chỉ FDE: 0x0e39e0 | Kích thước: 256 bytes
//   0x233c08: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x233c0c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x233c10: 9403ACB1  bl       #0x31eed4
//   0x233c14: 54000120  b.eq     #0x233c38
static inline uint64_t fde_func_0828_0x233c08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x233c08ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0e39e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0829 | PC: 0x233de4 | FDE: 0x0e3af0 | Size: 256 bytes
// Khung tháo gỡ #0829 | Địa chỉ PC: 0x233de4 | Địa chỉ FDE: 0x0e3af0 | Kích thước: 256 bytes
//   0x233de4: D10103FF  sub      sp, sp, #0x40
//   0x233de8: F90013F4  str      x20, [sp, #0x20]
//   0x233dec: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x233df0: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0829_0x233de4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x233de4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f4ULL) ^ 0x0e3af0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0830 | PC: 0x234084 | FDE: 0x0e3c00 | Size: 256 bytes
// Khung tháo gỡ #0830 | Địa chỉ PC: 0x234084 | Địa chỉ FDE: 0x0e3c00 | Kích thước: 256 bytes
//   0x234084: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x234088: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x23408c: F00009A8  adrp     x8, #0x36b000
//   0x234090: 91020108  add      x8, x8, #0x80
static inline uint64_t fde_func_0830_0x234084(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x234084ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0e3c00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0831 | PC: 0x23449c | FDE: 0x0e3d28 | Size: 256 bytes
// Khung tháo gỡ #0831 | Địa chỉ PC: 0x23449c | Địa chỉ FDE: 0x0e3d28 | Kích thước: 256 bytes
//   0x23449c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2344a0: F9400C08  ldr      x8, [x0, #0x18]
//   0x2344a4: B40000C8  cbz      x8, #0x2344bc
//   0x2344a8: 91004013  add      x19, x0, #0x10
static inline uint64_t fde_func_0831_0x23449c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23449cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400c08ULL) ^ 0x0e3d28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0832 | PC: 0x234948 | FDE: 0x0e3e68 | Size: 256 bytes
// Khung tháo gỡ #0832 | Địa chỉ PC: 0x234948 | Địa chỉ FDE: 0x0e3e68 | Kích thước: 256 bytes
//   0x234948: D10143FF  sub      sp, sp, #0x50
//   0x23494c: F90013F6  str      x22, [sp, #0x20]
//   0x234950: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x234954: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0832_0x234948(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x234948ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x0e3e68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0833 | PC: 0x234e74 | FDE: 0x0e3fa0 | Size: 256 bytes
// Khung tháo gỡ #0833 | Địa chỉ PC: 0x234e74 | Địa chỉ FDE: 0x0e3fa0 | Kích thước: 256 bytes
//   0x234e74: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x234e78: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x234e7c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x234e80: 9403BE04  bl       #0x324690
static inline uint64_t fde_func_0833_0x234e74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x234e74ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0e3fa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0834 | PC: 0x235040 | FDE: 0x0e40a8 | Size: 256 bytes
// Khung tháo gỡ #0834 | Địa chỉ PC: 0x235040 | Địa chỉ FDE: 0x0e40a8 | Kích thước: 256 bytes
//   0x235040: F9400400  ldr      x0, [x0, #8]
//   0x235044: 1403BC76  b        #0x32421c
//   0x235048: F9400808  ldr      x8, [x0, #0x10]
//   0x23504c: D00008E9  adrp     x9, #0x353000
static inline uint64_t fde_func_0834_0x235040(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x235040ULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0x1403bc76ULL) ^ 0x0e40a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0835 | PC: 0x235240 | FDE: 0x0e41a8 | Size: 256 bytes
// Khung tháo gỡ #0835 | Địa chỉ PC: 0x235240 | Địa chỉ FDE: 0x0e41a8 | Kích thước: 256 bytes
//   0x235240: F9405C28  ldr      x8, [x1, #0xb8]
//   0x235244: B40000A8  cbz      x8, #0x235258
//   0x235248: F9400009  ldr      x9, [x0]
//   0x23524c: B9407D02  ldr      w2, [x8, #0x7c]
static inline uint64_t fde_func_0835_0x235240(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x235240ULL ^ (static_cast<uint64_t>(0xf9405c28ULL) << 13);
    acc = (acc + a1 + 0xb40000a8ULL) ^ 0x0e41a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0836 | PC: 0x235550 | FDE: 0x0e42c0 | Size: 256 bytes
// Khung tháo gỡ #0836 | Địa chỉ PC: 0x235550 | Địa chỉ FDE: 0x0e42c0 | Kích thước: 256 bytes
//   0x235550: F9405C28  ldr      x8, [x1, #0xb8]
//   0x235554: B4000088  cbz      x8, #0x235564
//   0x235558: BD400500  ldr      s0, [x8, #4]
//   0x23555c: 1E22C000  fcvt     d0, s0
static inline uint64_t fde_func_0836_0x235550(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x235550ULL ^ (static_cast<uint64_t>(0xf9405c28ULL) << 13);
    acc = (acc + a1 + 0xb4000088ULL) ^ 0x0e42c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0837 | PC: 0x2357c8 | FDE: 0x0e43b8 | Size: 256 bytes
// Khung tháo gỡ #0837 | Địa chỉ PC: 0x2357c8 | Địa chỉ FDE: 0x0e43b8 | Kích thước: 256 bytes
//   0x2357c8: F940B828  ldr      x8, [x1, #0x170]
//   0x2357cc: B40000A8  cbz      x8, #0x2357e0
//   0x2357d0: F9400009  ldr      x9, [x0]
//   0x2357d4: 39420902  ldrb     w2, [x8, #0x82]
static inline uint64_t fde_func_0837_0x2357c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2357c8ULL ^ (static_cast<uint64_t>(0xf940b828ULL) << 13);
    acc = (acc + a1 + 0xb40000a8ULL) ^ 0x0e43b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0838 | PC: 0x235b18 | FDE: 0x0e44e0 | Size: 256 bytes
// Khung tháo gỡ #0838 | Địa chỉ PC: 0x235b18 | Địa chỉ FDE: 0x0e44e0 | Kích thước: 256 bytes
//   0x235b18: F940A828  ldr      x8, [x1, #0x150]
//   0x235b1c: F9400009  ldr      x9, [x0]
//   0x235b20: 52800841  mov      w1, #0x42
//   0x235b24: F9400108  ldr      x8, [x8]
static inline uint64_t fde_func_0838_0x235b18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x235b18ULL ^ (static_cast<uint64_t>(0xf940a828ULL) << 13);
    acc = (acc + a1 + 0xf9400009ULL) ^ 0x0e44e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0839 | PC: 0x235dd0 | FDE: 0x0e45e8 | Size: 256 bytes
// Khung tháo gỡ #0839 | Địa chỉ PC: 0x235dd0 | Địa chỉ FDE: 0x0e45e8 | Kích thước: 256 bytes
//   0x235dd0: F940A028  ldr      x8, [x1, #0x140]
//   0x235dd4: F9400009  ldr      x9, [x0]
//   0x235dd8: 52800A61  mov      w1, #0x53
//   0x235ddc: FD400100  ldr      d0, [x8]
static inline uint64_t fde_func_0839_0x235dd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x235dd0ULL ^ (static_cast<uint64_t>(0xf940a028ULL) << 13);
    acc = (acc + a1 + 0xf9400009ULL) ^ 0x0e45e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0840 | PC: 0x235f64 | FDE: 0x0e46f0 | Size: 256 bytes
// Khung tháo gỡ #0840 | Địa chỉ PC: 0x235f64 | Địa chỉ FDE: 0x0e46f0 | Kích thước: 256 bytes
//   0x235f64: F940A028  ldr      x8, [x1, #0x140]
//   0x235f68: F9400009  ldr      x9, [x0]
//   0x235f6c: 52800BA1  mov      w1, #0x5d
//   0x235f70: FD401900  ldr      d0, [x8, #0x30]
static inline uint64_t fde_func_0840_0x235f64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x235f64ULL ^ (static_cast<uint64_t>(0xf940a028ULL) << 13);
    acc = (acc + a1 + 0xf9400009ULL) ^ 0x0e46f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0841 | PC: 0x23637c | FDE: 0x0e4810 | Size: 256 bytes
// Khung tháo gỡ #0841 | Địa chỉ PC: 0x23637c | Địa chỉ FDE: 0x0e4810 | Kích thước: 256 bytes
//   0x23637c: D101C3FF  sub      sp, sp, #0x70
//   0x236380: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x236384: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x236388: 940399A0  bl       #0x31ca08
static inline uint64_t fde_func_0841_0x23637c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23637cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90553f5ULL) ^ 0x0e4810ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0842 | PC: 0x2365ac | FDE: 0x0e4920 | Size: 256 bytes
// Khung tháo gỡ #0842 | Địa chỉ PC: 0x2365ac | Địa chỉ FDE: 0x0e4920 | Kích thước: 256 bytes
//   0x2365ac: F940B828  ldr      x8, [x1, #0x170]
//   0x2365b0: B40000A8  cbz      x8, #0x2365c4
//   0x2365b4: F9400009  ldr      x9, [x0]
//   0x2365b8: 39421D02  ldrb     w2, [x8, #0x87]
static inline uint64_t fde_func_0842_0x2365ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2365acULL ^ (static_cast<uint64_t>(0xf940b828ULL) << 13);
    acc = (acc + a1 + 0xb40000a8ULL) ^ 0x0e4920ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0843 | PC: 0x2367f8 | FDE: 0x0e4a28 | Size: 256 bytes
// Khung tháo gỡ #0843 | Địa chỉ PC: 0x2367f8 | Địa chỉ FDE: 0x0e4a28 | Kích thước: 256 bytes
//   0x2367f8: D10203FF  sub      sp, sp, #0x80
//   0x2367fc: F90033F4  str      x20, [sp, #0x60]
//   0x236800: A9077BF3  stp      x19, x30, [sp, #0x70]
//   0x236804: 9403BA15  bl       #0x325058
static inline uint64_t fde_func_0843_0x2367f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2367f8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90033f4ULL) ^ 0x0e4a28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0844 | PC: 0x236b78 | FDE: 0x0e4b50 | Size: 256 bytes
// Khung tháo gỡ #0844 | Địa chỉ PC: 0x236b78 | Địa chỉ FDE: 0x0e4b50 | Kích thước: 256 bytes
//   0x236b78: D10203FF  sub      sp, sp, #0x80
//   0x236b7c: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x236b80: A9077BF3  stp      x19, x30, [sp, #0x70]
//   0x236b84: D53BD055  mrs      x21, tpidr_el0
static inline uint64_t fde_func_0844_0x236b78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x236b78ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90653f5ULL) ^ 0x0e4b50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0845 | PC: 0x236fc4 | FDE: 0x0e4c78 | Size: 256 bytes
// Khung tháo gỡ #0845 | Địa chỉ PC: 0x236fc4 | Địa chỉ FDE: 0x0e4c78 | Kích thước: 256 bytes
//   0x236fc4: D100C3FF  sub      sp, sp, #0x30
//   0x236fc8: F90013FE  str      x30, [sp, #0x20]
//   0x236fcc: F9409C28  ldr      x8, [x1, #0x138]
//   0x236fd0: B4000108  cbz      x8, #0x236ff0
static inline uint64_t fde_func_0845_0x236fc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x236fc4ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013feULL) ^ 0x0e4c78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0846 | PC: 0x2371a8 | FDE: 0x0e4d78 | Size: 256 bytes
// Khung tháo gỡ #0846 | Địa chỉ PC: 0x2371a8 | Địa chỉ FDE: 0x0e4d78 | Kích thước: 256 bytes
//   0x2371a8: D10203FF  sub      sp, sp, #0x80
//   0x2371ac: F90033F4  str      x20, [sp, #0x60]
//   0x2371b0: A9077BF3  stp      x19, x30, [sp, #0x70]
//   0x2371b4: 9404017F  bl       #0x3377b0
static inline uint64_t fde_func_0846_0x2371a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2371a8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90033f4ULL) ^ 0x0e4d78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0847 | PC: 0x237440 | FDE: 0x0e4e88 | Size: 256 bytes
// Khung tháo gỡ #0847 | Địa chỉ PC: 0x237440 | Địa chỉ FDE: 0x0e4e88 | Kích thước: 256 bytes
//   0x237440: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x237444: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x237448: AA0003F4  mov      x20, x0
//   0x23744c: 52800400  mov      w0, #0x20
static inline uint64_t fde_func_0847_0x237440(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x237440ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0e4e88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0848 | PC: 0x23763c | FDE: 0x0e4f90 | Size: 256 bytes
// Khung tháo gỡ #0848 | Địa chỉ PC: 0x23763c | Địa chỉ FDE: 0x0e4f90 | Kích thước: 256 bytes
//   0x23763c: AA1E03E1  mov      x1, x30
//   0x237640: 9403A655  bl       #0x320f94
//   0x237644: AA0103FE  mov      x30, x1
//   0x237648: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_0848_0x23763c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23763cULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x9403a655ULL) ^ 0x0e4f90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0849 | PC: 0x237a08 | FDE: 0x0e50a0 | Size: 256 bytes
// Khung tháo gỡ #0849 | Địa chỉ PC: 0x237a08 | Địa chỉ FDE: 0x0e50a0 | Kích thước: 256 bytes
//   0x237a08: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x237a0c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x237a10: 9403A262  bl       #0x320398
//   0x237a14: 94042387  bl       #0x340830
static inline uint64_t fde_func_0849_0x237a08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x237a08ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0e50a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0850 | PC: 0x237b84 | FDE: 0x0e50e0 | Size: 256 bytes [_ZN4lynx4tasm17ForEachLepusValueERKNS_5lepus5ValueENS_4base15MoveOnlyClosureIvJS4_S4_EEE]
// Khung tháo gỡ #0850 | Địa chỉ PC: 0x237b84 | Địa chỉ FDE: 0x0e50e0 | Kích thước: 256 bytes
//   0x237b84: D10183FF  sub      sp, sp, #0x60
//   0x237b88: F9001BF6  str      x22, [sp, #0x30]
//   0x237b8c: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x237b90: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0850_0x237b84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x237b84ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf6ULL) ^ 0x0e50e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0851 | PC: 0x23808c | FDE: 0x0e51b8 | Size: 152 bytes [_ZN4lynx4tasm7LynxEnv11GetInstanceEv]
// Khung tháo gỡ #0851 | Địa chỉ PC: 0x23808c | Địa chỉ FDE: 0x0e51b8 | Kích thước: 152 bytes
//   0x23808c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x238090: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x238094: F0000988  adrp     x8, #0x36b000
//   0x238098: 91040108  add      x8, x8, #0x100
static inline uint64_t fde_func_0851_0x23808c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23808cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0e51b8ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0852 | PC: 0x238124 | FDE: 0x0e51d8 | Size: 240 bytes [_ZN4lynx4tasm7LynxEnv14onPiperInvokedERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEESA_SA_SA_SA_]
// Khung tháo gỡ #0852 | Địa chỉ PC: 0x238124 | Địa chỉ FDE: 0x0e51d8 | Kích thước: 240 bytes
//   0x238124: AA1E03E4  mov      x4, x30
//   0x238128: 9403B885  bl       #0x32633c
//   0x23812c: AA0403FE  mov      x30, x4
//   0x238130: A90A7BF3  stp      x19, x30, [sp, #0xa0]
static inline uint64_t fde_func_0852_0x238124(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x238124ULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x9403b885ULL) ^ 0x0e51d8ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0853 | PC: 0x238214 | FDE: 0x0e5200 | Size: 76 bytes [_ZN4lynx4tasm7LynxEnv10ContainKeyERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE]
// Khung tháo gỡ #0853 | Địa chỉ PC: 0x238214 | Địa chỉ FDE: 0x0e5200 | Kích thước: 76 bytes
//   0x238214: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x238218: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x23821c: 94039086  bl       #0x31c434
//   0x238220: 9404210C  bl       #0x340650
static inline uint64_t fde_func_0853_0x238214(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x238214ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0e5200ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0854 | PC: 0x238260 | FDE: 0x0e5238 | Size: 104 bytes [_ZN4lynx4tasm7LynxEnv15SetBoolLocalEnvERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEb]
// Khung tháo gỡ #0854 | Địa chỉ PC: 0x238260 | Địa chỉ FDE: 0x0e5238 | Kích thước: 104 bytes
//   0x238260: D10103FF  sub      sp, sp, #0x40
//   0x238264: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x238268: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x23826c: 940394CF  bl       #0x31d5a8
static inline uint64_t fde_func_0854_0x238260(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x238260ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x0e5238ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0855 | PC: 0x2382c8 | FDE: 0x0e5258 | Size: 256 bytes [_ZN4lynx4tasm7LynxEnv11SetLocalEnvERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEESA_]
// Khung tháo gỡ #0855 | Địa chỉ PC: 0x2382c8 | Địa chỉ FDE: 0x0e5258 | Kích thước: 256 bytes
//   0x2382c8: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x2382cc: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x2382d0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x2382d4: 94039ABB  bl       #0x31edc0
static inline uint64_t fde_func_0855_0x2382c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2382c8ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0e5258ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0856 | PC: 0x238580 | FDE: 0x0e52c0 | Size: 256 bytes [_ZN4lynx4tasm7LynxEnv13SetGroupedEnvERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEbSA_]
// Khung tháo gỡ #0856 | Địa chỉ PC: 0x238580 | Địa chỉ FDE: 0x0e52c0 | Kích thước: 256 bytes
//   0x238580: AA1E03E4  mov      x4, x30
//   0x238584: 9403ADE8  bl       #0x323d24
//   0x238588: AA0403FE  mov      x30, x4
//   0x23858c: A90F7BFD  stp      x29, x30, [sp, #0xf0]
static inline uint64_t fde_func_0856_0x238580(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x238580ULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x9403ade8ULL) ^ 0x0e52c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0857 | PC: 0x2387bc | FDE: 0x0e52f0 | Size: 256 bytes [_ZN4lynx4tasm7LynxEnv13SetGroupedEnvERKNSt6__ndk113unordered_setINS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEENS2_4hashIS9_EENS2_8equal_toIS9_EENS7_IS9_EEEERKS9_]
// Khung tháo gỡ #0857 | Địa chỉ PC: 0x2387bc | Địa chỉ FDE: 0x0e52f0 | Kích thước: 256 bytes
//   0x2387bc: AA1E03E3  mov      x3, x30
//   0x2387c0: 9403922B  bl       #0x31d06c
//   0x2387c4: AA0303FE  mov      x30, x3
//   0x2387c8: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_0857_0x2387bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2387bcULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x9403922bULL) ^ 0x0e52f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0858 | PC: 0x238a5c | FDE: 0x0e5320 | Size: 148 bytes [_ZN4lynx4tasm7LynxEnv10GetLongEnvENS1_3KeyEiNS1_7EnvTypeE]
// Khung tháo gỡ #0858 | Địa chỉ PC: 0x238a5c | Địa chỉ FDE: 0x0e5320 | Kích thước: 148 bytes
//   0x238a5c: D10143FF  sub      sp, sp, #0x50
//   0x238a60: F9001BF4  str      x20, [sp, #0x30]
//   0x238a64: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x238a68: 94039257  bl       #0x31d3c4
static inline uint64_t fde_func_0858_0x238a5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x238a5cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf4ULL) ^ 0x0e5320ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0859 | PC: 0x238af0 | FDE: 0x0e5340 | Size: 112 bytes [_ZN4lynx4tasm7LynxEnv12GetStringEnvENS1_3KeyENS1_7EnvTypeE]
// Khung tháo gỡ #0859 | Địa chỉ PC: 0x238af0 | Địa chỉ FDE: 0x0e5340 | Kích thước: 112 bytes
//   0x238af0: D10143FF  sub      sp, sp, #0x50
//   0x238af4: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x238af8: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x238afc: 9403A81F  bl       #0x322b78
static inline uint64_t fde_func_0859_0x238af0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x238af0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90353f5ULL) ^ 0x0e5340ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0860 | PC: 0x238b60 | FDE: 0x0e5360 | Size: 256 bytes [_ZN4lynx4tasm7LynxEnv14GetExternalEnvENS1_3KeyE]
// Khung tháo gỡ #0860 | Địa chỉ PC: 0x238b60 | Địa chỉ FDE: 0x0e5360 | Kích thước: 256 bytes
//   0x238b60: D10283FF  sub      sp, sp, #0xa0
//   0x238b64: AA1E03E2  mov      x2, x30
//   0x238b68: 9403F101  bl       #0x334f6c
//   0x238b6c: AA0203FE  mov      x30, x2
static inline uint64_t fde_func_0860_0x238b60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x238b60ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xaa1e03e2ULL) ^ 0x0e5360ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0861 | PC: 0x238e68 | FDE: 0x0e5390 | Size: 256 bytes [_ZN4lynx4tasm7LynxEnv11GetLocalEnvENS1_3KeyE]
// Khung tháo gỡ #0861 | Địa chỉ PC: 0x238e68 | Địa chỉ FDE: 0x0e5390 | Kích thước: 256 bytes
//   0x238e68: D101C3FF  sub      sp, sp, #0x70
//   0x238e6c: A9045BF7  stp      x23, x22, [sp, #0x40]
//   0x238e70: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x238e74: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_0861_0x238e68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x238e68ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9045bf7ULL) ^ 0x0e5390ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0862 | PC: 0x239c34 | FDE: 0x0e53e0 | Size: 256 bytes [_ZN4lynx4tasm7LynxEnv10GetEnvMaskENS1_3KeyE]
// Khung tháo gỡ #0862 | Địa chỉ PC: 0x239c34 | Địa chỉ FDE: 0x0e53e0 | Kích thước: 256 bytes
//   0x239c34: D10103FF  sub      sp, sp, #0x40
//   0x239c38: F90013F4  str      x20, [sp, #0x20]
//   0x239c3c: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x239c40: 9403C041  bl       #0x329d44
static inline uint64_t fde_func_0862_0x239c34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x239c34ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f4ULL) ^ 0x0e53e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0863 | PC: 0x239e3c | FDE: 0x0e5478 | Size: 256 bytes [_ZN4lynx4tasm7LynxEnv13ConvertToBoolERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE]
// Khung tháo gỡ #0863 | Địa chỉ PC: 0x239e3c | Địa chỉ FDE: 0x0e5478 | Kích thước: 256 bytes
//   0x239e3c: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x239e40: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x239e44: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x239e48: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0863_0x239e3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x239e3cULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0e5478ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0864 | PC: 0x239f6c | FDE: 0x0e5498 | Size: 68 bytes [_ZN4lynx4tasm7LynxEnv10GetBoolEnvERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEb]
// Khung tháo gỡ #0864 | Địa chỉ PC: 0x239f6c | Địa chỉ FDE: 0x0e5498 | Kích thước: 68 bytes
//   0x239f6c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x239f70: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x239f74: 2A0203F4  mov      w20, w2
//   0x239f78: AA0103F5  mov      x21, x1
static inline uint64_t fde_func_0864_0x239f6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x239f6cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0e5498ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0865 | PC: 0x239fb0 | FDE: 0x0e54b8 | Size: 100 bytes [_ZN4lynx4tasm7LynxEnv10GetBoolEnvENS1_3KeyEbNS1_7EnvTypeE]
// Khung tháo gỡ #0865 | Địa chỉ PC: 0x239fb0 | Địa chỉ FDE: 0x0e54b8 | Kích thước: 100 bytes
//   0x239fb0: D10143FF  sub      sp, sp, #0x50
//   0x239fb4: F9001BF4  str      x20, [sp, #0x30]
//   0x239fb8: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x239fbc: 94038D02  bl       #0x31d3c4
static inline uint64_t fde_func_0865_0x239fb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x239fb0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf4ULL) ^ 0x0e54b8ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0866 | PC: 0x23a014 | FDE: 0x0e54d8 | Size: 256 bytes [_ZN4lynx4tasm7LynxEnv19GetDebugDescriptionEv]
// Khung tháo gỡ #0866 | Địa chỉ PC: 0x23a014 | Địa chỉ FDE: 0x0e54d8 | Kích thước: 256 bytes
//   0x23a014: AA1E03E1  mov      x1, x30
//   0x23a018: 9403CF51  bl       #0x32dd5c
//   0x23a01c: AA0103FE  mov      x30, x1
//   0x23a020: A90F7BF3  stp      x19, x30, [sp, #0xf0]
static inline uint64_t fde_func_0866_0x23a014(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a014ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x9403cf51ULL) ^ 0x0e54d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0867 | PC: 0x23a158 | FDE: 0x0e5538 | Size: 256 bytes [_ZN4lynx4tasm7LynxEnv10SetEnvMaskERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEb]
// Khung tháo gỡ #0867 | Địa chỉ PC: 0x23a158 | Địa chỉ FDE: 0x0e5538 | Kích thước: 256 bytes
//   0x23a158: AA1E03E3  mov      x3, x30
//   0x23a15c: 94038BC4  bl       #0x31d06c
//   0x23a160: AA0303FE  mov      x30, x3
//   0x23a164: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_0867_0x23a158(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a158ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94038bc4ULL) ^ 0x0e5538ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0868 | PC: 0x23a414 | FDE: 0x0e5568 | Size: 80 bytes [_ZN4lynx4tasm7LynxEnv13GetGroupedEnvERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE]
// Khung tháo gỡ #0868 | Địa chỉ PC: 0x23a414 | Địa chỉ FDE: 0x0e5568 | Kích thước: 80 bytes
//   0x23a414: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x23a418: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x23a41c: AA0103F5  mov      x21, x1
//   0x23a420: 9403F822  bl       #0x3384a8
static inline uint64_t fde_func_0868_0x23a414(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a414ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0e5568ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0869 | PC: 0x23a464 | FDE: 0x0e5588 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv24IsDevToolComponentAttachEv]
// Khung tháo gỡ #0869 | Địa chỉ PC: 0x23a464 | Địa chỉ FDE: 0x0e5588 | Kích thước: 8 bytes
//   0x23a464: 52800021  mov      w1, #1
//   0x23a468: 1403ADC2  b        #0x325b70
static inline uint64_t fde_func_0869_0x23a464(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a464ULL ^ (static_cast<uint64_t>(0x52800021ULL) << 13);
    acc = (acc + a1 + 0x1403adc2ULL) ^ 0x0e5588ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0870 | PC: 0x23a46c | FDE: 0x0e55a0 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv18IsLynxDebugEnabledEv]
// Khung tháo gỡ #0870 | Địa chỉ PC: 0x23a46c | Địa chỉ FDE: 0x0e55a0 | Kích thước: 8 bytes
//   0x23a46c: 52800CE1  mov      w1, #0x67
//   0x23a470: 1403ADC0  b        #0x325b70
static inline uint64_t fde_func_0870_0x23a46c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a46cULL ^ (static_cast<uint64_t>(0x52800ce1ULL) << 13);
    acc = (acc + a1 + 0x1403adc0ULL) ^ 0x0e55a0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0871 | PC: 0x23a474 | FDE: 0x0e55b8 | Size: 48 bytes [_ZN4lynx4tasm7LynxEnv16IsDevToolEnabledEv]
// Khung tháo gỡ #0871 | Địa chỉ PC: 0x23a474 | Địa chỉ FDE: 0x0e55b8 | Kích thước: 48 bytes
//   0x23a474: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x23a478: AA0003F3  mov      x19, x0
//   0x23a47c: 94041CCD  bl       #0x3417b0
//   0x23a480: 360000C0  tbz      w0, #0, #0x23a498
static inline uint64_t fde_func_0871_0x23a474(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a474ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0e55b8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0872 | PC: 0x23a4a4 | FDE: 0x0e55d0 | Size: 48 bytes [_ZN4lynx4tasm7LynxEnv15IsLogBoxEnabledEv]
// Khung tháo gỡ #0872 | Địa chỉ PC: 0x23a4a4 | Địa chỉ FDE: 0x0e55d0 | Kích thước: 48 bytes
//   0x23a4a4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x23a4a8: AA0003F3  mov      x19, x0
//   0x23a4ac: 94041CC1  bl       #0x3417b0
//   0x23a4b0: 360000C0  tbz      w0, #0, #0x23a4c8
static inline uint64_t fde_func_0872_0x23a4a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a4a4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0e55d0ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0873 | PC: 0x23a4d4 | FDE: 0x0e55e8 | Size: 60 bytes [_ZN4lynx4tasm7LynxEnv21IsQuickjsCacheEnabledEv]
// Khung tháo gỡ #0873 | Địa chỉ PC: 0x23a4d4 | Địa chỉ FDE: 0x0e55e8 | Kích thước: 60 bytes
//   0x23a4d4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x23a4d8: 52800081  mov      w1, #4
//   0x23a4dc: 52800022  mov      w2, #1
//   0x23a4e0: 52800023  mov      w3, #1
static inline uint64_t fde_func_0873_0x23a4d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a4d4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x52800081ULL) ^ 0x0e55e8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0874 | PC: 0x23a510 | FDE: 0x0e5600 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv18IsDisableTracingGCEv]
// Khung tháo gỡ #0874 | Địa chỉ PC: 0x23a510 | Địa chỉ FDE: 0x0e5600 | Kích thước: 8 bytes
//   0x23a510: 528000A1  mov      w1, #5
//   0x23a514: 14038B5D  b        #0x31d288
static inline uint64_t fde_func_0874_0x23a510(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a510ULL ^ (static_cast<uint64_t>(0x528000a1ULL) << 13);
    acc = (acc + a1 + 0x14038b5dULL) ^ 0x0e5600ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0875 | PC: 0x23a518 | FDE: 0x0e5618 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv26IsLayoutPerformanceEnabledEv]
// Khung tháo gỡ #0875 | Địa chỉ PC: 0x23a518 | Địa chỉ FDE: 0x0e5618 | Kích thước: 8 bytes
//   0x23a518: 528000C1  mov      w1, #6
//   0x23a51c: 1403AD95  b        #0x325b70
static inline uint64_t fde_func_0875_0x23a518(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a518ULL ^ (static_cast<uint64_t>(0x528000c1ULL) << 13);
    acc = (acc + a1 + 0x1403ad95ULL) ^ 0x0e5618ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0876 | PC: 0x23a520 | FDE: 0x0e5630 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv21IsPiperMonitorEnabledEv]
// Khung tháo gỡ #0876 | Địa chỉ PC: 0x23a520 | Địa chỉ FDE: 0x0e5630 | Kích thước: 8 bytes
//   0x23a520: 52800101  mov      w1, #8
//   0x23a524: 1403AD93  b        #0x325b70
static inline uint64_t fde_func_0876_0x23a520(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a520ULL ^ (static_cast<uint64_t>(0x52800101ULL) << 13);
    acc = (acc + a1 + 0x1403ad93ULL) ^ 0x0e5630ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0877 | PC: 0x23a528 | FDE: 0x0e5648 | Size: 48 bytes [_ZN4lynx4tasm7LynxEnv16IsDomTreeEnabledEb]
// Khung tháo gỡ #0877 | Địa chỉ PC: 0x23a528 | Địa chỉ FDE: 0x0e5648 | Kích thước: 48 bytes
//   0x23a528: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x23a52c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x23a530: 9403D95C  bl       #0x330aa0
//   0x23a534: 370000A0  tbnz     w0, #0, #0x23a548
static inline uint64_t fde_func_0877_0x23a528(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a528ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0e5648ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0878 | PC: 0x23a558 | FDE: 0x0e5668 | Size: 16 bytes [_ZN4lynx4tasm7LynxEnv32GetVsyncAlignedFlushGlobalSwitchEv]
// Khung tháo gỡ #0878 | Địa chỉ PC: 0x23a558 | Địa chỉ FDE: 0x0e5668 | Kích thước: 16 bytes
//   0x23a558: 52800161  mov      w1, #0xb
//   0x23a55c: 52800022  mov      w2, #1
//   0x23a560: 2A1F03E3  mov      w3, wzr
//   0x23a564: 14041C3F  b        #0x341660
static inline uint64_t fde_func_0878_0x23a558(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a558ULL ^ (static_cast<uint64_t>(0x52800161ULL) << 13);
    acc = (acc + a1 + 0x52800022ULL) ^ 0x0e5668ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0879 | PC: 0x23a568 | FDE: 0x0e5680 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv34EnableGlobalFeatureSwitchStatisticEv]
// Khung tháo gỡ #0879 | Địa chỉ PC: 0x23a568 | Địa chỉ FDE: 0x0e5680 | Kích thước: 8 bytes
//   0x23a568: 52800181  mov      w1, #0xc
//   0x23a56c: 14038B47  b        #0x31d288
static inline uint64_t fde_func_0879_0x23a568(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a568ULL ^ (static_cast<uint64_t>(0x52800181ULL) << 13);
    acc = (acc + a1 + 0x14038b47ULL) ^ 0x0e5680ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0880 | PC: 0x23a570 | FDE: 0x0e5698 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv20EnableFeatureCounterEv]
// Khung tháo gỡ #0880 | Địa chỉ PC: 0x23a570 | Địa chỉ FDE: 0x0e5698 | Kích thước: 8 bytes
//   0x23a570: 528001A1  mov      w1, #0xd
//   0x23a574: 14038B45  b        #0x31d288
static inline uint64_t fde_func_0880_0x23a570(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a570ULL ^ (static_cast<uint64_t>(0x528001a1ULL) << 13);
    acc = (acc + a1 + 0x14038b45ULL) ^ 0x0e5698ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0881 | PC: 0x23a578 | FDE: 0x0e56b0 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv26EnablePresetThreadPriorityEv]
// Khung tháo gỡ #0881 | Địa chỉ PC: 0x23a578 | Địa chỉ FDE: 0x0e56b0 | Kích thước: 8 bytes
//   0x23a578: 52800561  mov      w1, #0x2b
//   0x23a57c: 14038B43  b        #0x31d288
static inline uint64_t fde_func_0881_0x23a578(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a578ULL ^ (static_cast<uint64_t>(0x52800561ULL) << 13);
    acc = (acc + a1 + 0x14038b43ULL) ^ 0x0e56b0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0882 | PC: 0x23a580 | FDE: 0x0e56c8 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv15EnableJSBTimingEv]
// Khung tháo gỡ #0882 | Địa chỉ PC: 0x23a580 | Địa chỉ FDE: 0x0e56c8 | Kích thước: 8 bytes
//   0x23a580: 528001C1  mov      w1, #0xe
//   0x23a584: 14038B41  b        #0x31d288
static inline uint64_t fde_func_0882_0x23a580(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a580ULL ^ (static_cast<uint64_t>(0x528001c1ULL) << 13);
    acc = (acc + a1 + 0x14038b41ULL) ^ 0x0e56c8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0883 | PC: 0x23a588 | FDE: 0x0e56e0 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv20EnableAsyncJSBTimingEv]
// Khung tháo gỡ #0883 | Địa chỉ PC: 0x23a588 | Địa chỉ FDE: 0x0e56e0 | Kích thước: 8 bytes
//   0x23a588: 528001E1  mov      w1, #0xf
//   0x23a58c: 14038B3F  b        #0x31d288
static inline uint64_t fde_func_0883_0x23a588(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a588ULL ^ (static_cast<uint64_t>(0x528001e1ULL) << 13);
    acc = (acc + a1 + 0x14038b3fULL) ^ 0x0e56e0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0884 | PC: 0x23a590 | FDE: 0x0e56f8 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv20EnableLongTaskTimingEv]
// Khung tháo gỡ #0884 | Địa chỉ PC: 0x23a590 | Địa chỉ FDE: 0x0e56f8 | Kích thước: 8 bytes
//   0x23a590: 52800201  mov      w1, #0x10
//   0x23a594: 14038B3D  b        #0x31d288
static inline uint64_t fde_func_0884_0x23a590(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a590ULL ^ (static_cast<uint64_t>(0x52800201ULL) << 13);
    acc = (acc + a1 + 0x14038b3dULL) ^ 0x0e56f8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0885 | PC: 0x23a598 | FDE: 0x0e5710 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv19EnableMemoryMonitorEv]
// Khung tháo gỡ #0885 | Địa chỉ PC: 0x23a598 | Địa chỉ FDE: 0x0e5710 | Kích thước: 8 bytes
//   0x23a598: 52800221  mov      w1, #0x11
//   0x23a59c: 14038B3B  b        #0x31d288
static inline uint64_t fde_func_0885_0x23a598(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a598ULL ^ (static_cast<uint64_t>(0x52800221ULL) << 13);
    acc = (acc + a1 + 0x14038b3bULL) ^ 0x0e5710ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0886 | PC: 0x23a5a0 | FDE: 0x0e5728 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv23EnableJSBlockingMonitorEv]
// Khung tháo gỡ #0886 | Địa chỉ PC: 0x23a5a0 | Địa chỉ FDE: 0x0e5728 | Kích thước: 8 bytes
//   0x23a5a0: 52800241  mov      w1, #0x12
//   0x23a5a4: 14038B39  b        #0x31d288
static inline uint64_t fde_func_0886_0x23a5a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a5a0ULL ^ (static_cast<uint64_t>(0x52800241ULL) << 13);
    acc = (acc + a1 + 0x14038b39ULL) ^ 0x0e5728ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0887 | PC: 0x23a5a8 | FDE: 0x0e5740 | Size: 24 bytes [_ZN4lynx4tasm7LynxEnv24GetJSBlockingThresholdMsEv]
// Khung tháo gỡ #0887 | Địa chỉ PC: 0x23a5a8 | Địa chỉ FDE: 0x0e5740 | Kích thước: 24 bytes
//   0x23a5a8: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x23a5ac: 52800261  mov      w1, #0x13
//   0x23a5b0: 52800282  mov      w2, #0x14
//   0x23a5b4: 9403B022  bl       #0x32663c
static inline uint64_t fde_func_0887_0x23a5a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a5a8ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x52800261ULL) ^ 0x0e5740ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0888 | PC: 0x23a5c0 | FDE: 0x0e5758 | Size: 24 bytes [_ZN4lynx4tasm7LynxEnv29GetJSBlockingReportIntervalMsEv]
// Khung tháo gỡ #0888 | Địa chỉ PC: 0x23a5c0 | Địa chỉ FDE: 0x0e5758 | Kích thước: 24 bytes
//   0x23a5c0: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x23a5c4: 52800281  mov      w1, #0x14
//   0x23a5c8: 52827102  mov      w2, #0x1388
//   0x23a5cc: 9403B01C  bl       #0x32663c
static inline uint64_t fde_func_0888_0x23a5c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a5c0ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x52800281ULL) ^ 0x0e5758ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0889 | PC: 0x23a5d8 | FDE: 0x0e5770 | Size: 24 bytes [_ZN4lynx4tasm7LynxEnv21TimingMapExceededSizeEv]
// Khung tháo gỡ #0889 | Địa chỉ PC: 0x23a5d8 | Địa chỉ FDE: 0x0e5770 | Kích thước: 24 bytes
//   0x23a5d8: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x23a5dc: 528002A1  mov      w1, #0x15
//   0x23a5e0: 52807D02  mov      w2, #0x3e8
//   0x23a5e4: 9403B016  bl       #0x32663c
static inline uint64_t fde_func_0889_0x23a5d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a5d8ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x528002a1ULL) ^ 0x0e5770ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0890 | PC: 0x23a5f0 | FDE: 0x0e5788 | Size: 20 bytes [_ZN4lynx4tasm7LynxEnv26GetMemoryChangeThresholdMbEv]
// Khung tháo gỡ #0890 | Địa chỉ PC: 0x23a5f0 | Địa chỉ FDE: 0x0e5788 | Kích thước: 20 bytes
//   0x23a5f0: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x23a5f4: 528002C1  mov      w1, #0x16
//   0x23a5f8: 9403C2E9  bl       #0x32b19c
//   0x23a5fc: F84107FE  ldr      x30, [sp], #0x10
static inline uint64_t fde_func_0890_0x23a5f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a5f0ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x528002c1ULL) ^ 0x0e5788ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0891 | PC: 0x23a604 | FDE: 0x0e57a0 | Size: 24 bytes [_ZN4lynx4tasm7LynxEnv28GetMemoryAcquisitionDelaySecEv]
// Khung tháo gỡ #0891 | Địa chỉ PC: 0x23a604 | Địa chỉ FDE: 0x0e57a0 | Kích thước: 24 bytes
//   0x23a604: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x23a608: 528002E1  mov      w1, #0x17
//   0x23a60c: 52800042  mov      w2, #2
//   0x23a610: 9403B00B  bl       #0x32663c
static inline uint64_t fde_func_0891_0x23a604(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a604ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x528002e1ULL) ^ 0x0e57a0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0892 | PC: 0x23a61c | FDE: 0x0e57b8 | Size: 24 bytes [_ZN4lynx4tasm7LynxEnv26GetMemoryReportIntervalSecEv]
// Khung tháo gỡ #0892 | Địa chỉ PC: 0x23a61c | Địa chỉ FDE: 0x0e57b8 | Kích thước: 24 bytes
//   0x23a61c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x23a620: 52800301  mov      w1, #0x18
//   0x23a624: 52809602  mov      w2, #0x4b0
//   0x23a628: 9403B005  bl       #0x32663c
static inline uint64_t fde_func_0892_0x23a61c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a61cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x52800301ULL) ^ 0x0e57b8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0893 | PC: 0x23a634 | FDE: 0x0e57d0 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv18IsDevToolConnectedEv]
// Khung tháo gỡ #0893 | Địa chỉ PC: 0x23a634 | Địa chỉ FDE: 0x0e57d0 | Kích thước: 8 bytes
//   0x23a634: 52800321  mov      w1, #0x19
//   0x23a638: 1403AD4E  b        #0x325b70
static inline uint64_t fde_func_0893_0x23a634(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a634ULL ^ (static_cast<uint64_t>(0x52800321ULL) << 13);
    acc = (acc + a1 + 0x1403ad4eULL) ^ 0x0e57d0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0894 | PC: 0x23a63c | FDE: 0x0e57e8 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv23EnableHarmonyNewOverlayEv]
// Khung tháo gỡ #0894 | Địa chỉ PC: 0x23a63c | Địa chỉ FDE: 0x0e57e8 | Kích thước: 8 bytes
//   0x23a63c: 52800A81  mov      w1, #0x54
//   0x23a640: 14038B12  b        #0x31d288
static inline uint64_t fde_func_0894_0x23a63c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a63cULL ^ (static_cast<uint64_t>(0x52800a81ULL) << 13);
    acc = (acc + a1 + 0x14038b12ULL) ^ 0x0e57e8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0895 | PC: 0x23a644 | FDE: 0x0e5800 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv23IsTableDeepCheckEnabledEv]
// Khung tháo gỡ #0895 | Địa chỉ PC: 0x23a644 | Địa chỉ FDE: 0x0e5800 | Kích thước: 8 bytes
//   0x23a644: 52800361  mov      w1, #0x1b
//   0x23a648: 1403AD4A  b        #0x325b70
static inline uint64_t fde_func_0895_0x23a644(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a644ULL ^ (static_cast<uint64_t>(0x52800361ULL) << 13);
    acc = (acc + a1 + 0x1403ad4aULL) ^ 0x0e5800ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0896 | PC: 0x23a64c | FDE: 0x0e5818 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv25IsDisabledLepusngOptimizeEv]
// Khung tháo gỡ #0896 | Địa chỉ PC: 0x23a64c | Địa chỉ FDE: 0x0e5818 | Kích thước: 8 bytes
//   0x23a64c: 52800381  mov      w1, #0x1c
//   0x23a650: 14038B0E  b        #0x31d288
static inline uint64_t fde_func_0896_0x23a64c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a64cULL ^ (static_cast<uint64_t>(0x52800381ULL) << 13);
    acc = (acc + a1 + 0x14038b0eULL) ^ 0x0e5818ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0897 | PC: 0x23a654 | FDE: 0x0e5830 | Size: 84 bytes [_ZN4lynx4tasm7LynxEnv22GetActivatedCDPDomainsEv]
// Khung tháo gỡ #0897 | Địa chỉ PC: 0x23a654 | Địa chỉ FDE: 0x0e5830 | Kích thước: 84 bytes
//   0x23a654: D10103FF  sub      sp, sp, #0x40
//   0x23a658: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x23a65c: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x23a660: 9403D402  bl       #0x32f668
static inline uint64_t fde_func_0897_0x23a654(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a654ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x0e5830ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0898 | PC: 0x23a6a8 | FDE: 0x0e5850 | Size: 16 bytes [_ZN4lynx4tasm7LynxEnv13GetV8HeapSizeEv]
// Khung tháo gỡ #0898 | Địa chỉ PC: 0x23a6a8 | Địa chỉ FDE: 0x0e5850 | Kích thước: 16 bytes
//   0x23a6a8: 528004E1  mov      w1, #0x27
//   0x23a6ac: 52800023  mov      w3, #1
//   0x23a6b0: 2A1F03E2  mov      w2, wzr
//   0x23a6b4: 14041C47  b        #0x3417d0
static inline uint64_t fde_func_0898_0x23a6a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a6a8ULL ^ (static_cast<uint64_t>(0x528004e1ULL) << 13);
    acc = (acc + a1 + 0x52800023ULL) ^ 0x0e5850ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0899 | PC: 0x23a6b8 | FDE: 0x0e5868 | Size: 88 bytes [_ZN4lynx4tasm7LynxEnv18CleanExternalCacheEv]
// Khung tháo gỡ #0899 | Địa chỉ PC: 0x23a6b8 | Địa chỉ FDE: 0x0e5868 | Kích thước: 88 bytes
//   0x23a6b8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x23a6bc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x23a6c0: 91028013  add      x19, x0, #0xa0
//   0x23a6c4: 940393BF  bl       #0x31f5c0
static inline uint64_t fde_func_0899_0x23a6b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a6b8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0e5868ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0900 | PC: 0x23a710 | FDE: 0x0e5888 | Size: 24 bytes [_ZN4lynx4tasm7LynxEnv29GetGlobalQuickContextPoolSizeEi]
// Khung tháo gỡ #0900 | Địa chỉ PC: 0x23a710 | Địa chỉ FDE: 0x0e5888 | Kích thước: 24 bytes
//   0x23a710: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x23a714: 2A0103E2  mov      w2, w1
//   0x23a718: 528005A1  mov      w1, #0x2d
//   0x23a71c: 9403AFC8  bl       #0x32663c
static inline uint64_t fde_func_0900_0x23a710(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a710ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x2a0103e2ULL) ^ 0x0e5888ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0901 | PC: 0x23a728 | FDE: 0x0e58a0 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv15EnableUIOpBatchEv]
// Khung tháo gỡ #0901 | Địa chỉ PC: 0x23a728 | Địa chỉ FDE: 0x0e58a0 | Kích thước: 8 bytes
//   0x23a728: 52800641  mov      w1, #0x32
//   0x23a72c: 14038AD7  b        #0x31d288
static inline uint64_t fde_func_0901_0x23a728(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a728ULL ^ (static_cast<uint64_t>(0x52800641ULL) << 13);
    acc = (acc + a1 + 0x14038ad7ULL) ^ 0x0e58a0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0902 | PC: 0x23a730 | FDE: 0x0e58b8 | Size: 88 bytes [_ZN4lynx4tasm7LynxEnv19EnableCSSLazyImportEv]
// Khung tháo gỡ #0902 | Địa chỉ PC: 0x23a730 | Địa chỉ FDE: 0x0e58b8 | Kích thước: 88 bytes
//   0x23a730: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x23a734: B0000988  adrp     x8, #0x36b000
//   0x23a738: 91044108  add      x8, x8, #0x110
//   0x23a73c: 08DFFD08  ldarb    w8, [x8]
static inline uint64_t fde_func_0902_0x23a730(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a730ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb0000988ULL) ^ 0x0e58b8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0903 | PC: 0x23a788 | FDE: 0x0e58d0 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv22EnableNewAnimatorFiberEv]
// Khung tháo gỡ #0903 | Địa chỉ PC: 0x23a788 | Địa chỉ FDE: 0x0e58d0 | Kích thước: 8 bytes
//   0x23a788: 52800741  mov      w1, #0x3a
//   0x23a78c: 14039D59  b        #0x321cf0
static inline uint64_t fde_func_0903_0x23a788(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a788ULL ^ (static_cast<uint64_t>(0x52800741ULL) << 13);
    acc = (acc + a1 + 0x14039d59ULL) ^ 0x0e58d0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0904 | PC: 0x23a790 | FDE: 0x0e58e8 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv33IsVSyncTriggeredInUiThreadAndroidEv]
// Khung tháo gỡ #0904 | Địa chỉ PC: 0x23a790 | Địa chỉ FDE: 0x0e58e8 | Kích thước: 8 bytes
//   0x23a790: 52800601  mov      w1, #0x30
//   0x23a794: 14038ABD  b        #0x31d288
static inline uint64_t fde_func_0904_0x23a790(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a790ULL ^ (static_cast<uint64_t>(0x52800601ULL) << 13);
    acc = (acc + a1 + 0x14038abdULL) ^ 0x0e58e8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0905 | PC: 0x23a798 | FDE: 0x0e5900 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv26IsVSyncPostTaskByEmergencyEv]
// Khung tháo gỡ #0905 | Địa chỉ PC: 0x23a798 | Địa chỉ FDE: 0x0e5900 | Kích thước: 8 bytes
//   0x23a798: 52800681  mov      w1, #0x34
//   0x23a79c: 14038ABB  b        #0x31d288
static inline uint64_t fde_func_0905_0x23a798(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a798ULL ^ (static_cast<uint64_t>(0x52800681ULL) << 13);
    acc = (acc + a1 + 0x14038abbULL) ^ 0x0e5900ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0906 | PC: 0x23a7a0 | FDE: 0x0e5918 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv28EnableUseMapBufferForUIPropsEv]
// Khung tháo gỡ #0906 | Địa chỉ PC: 0x23a7a0 | Địa chỉ FDE: 0x0e5918 | Kích thước: 8 bytes
//   0x23a7a0: 528006A1  mov      w1, #0x35
//   0x23a7a4: 14038AB9  b        #0x31d288
static inline uint64_t fde_func_0906_0x23a7a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a7a0ULL ^ (static_cast<uint64_t>(0x528006a1ULL) << 13);
    acc = (acc + a1 + 0x14038ab9ULL) ^ 0x0e5918ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0907 | PC: 0x23a7a8 | FDE: 0x0e5930 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv34EnablePostDataBeforeUpdateTemplateEv]
// Khung tháo gỡ #0907 | Địa chỉ PC: 0x23a7a8 | Địa chỉ FDE: 0x0e5930 | Kích thước: 8 bytes
//   0x23a7a8: 52800761  mov      w1, #0x3b
//   0x23a7ac: 14039D51  b        #0x321cf0
static inline uint64_t fde_func_0907_0x23a7a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a7a8ULL ^ (static_cast<uint64_t>(0x52800761ULL) << 13);
    acc = (acc + a1 + 0x14039d51ULL) ^ 0x0e5930ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0908 | PC: 0x23a7b0 | FDE: 0x0e5948 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv33EnableReportListItemLifeStatisticEv]
// Khung tháo gỡ #0908 | Địa chỉ PC: 0x23a7b0 | Địa chỉ FDE: 0x0e5948 | Kích thước: 8 bytes
//   0x23a7b0: 52800781  mov      w1, #0x3c
//   0x23a7b4: 14038AB5  b        #0x31d288
static inline uint64_t fde_func_0908_0x23a7b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a7b0ULL ^ (static_cast<uint64_t>(0x52800781ULL) << 13);
    acc = (acc + a1 + 0x14038ab5ULL) ^ 0x0e5948ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0909 | PC: 0x23a7b8 | FDE: 0x0e5960 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv22EnableNativeListNestedEv]
// Khung tháo gỡ #0909 | Địa chỉ PC: 0x23a7b8 | Địa chỉ FDE: 0x0e5960 | Kích thước: 8 bytes
//   0x23a7b8: 528007A1  mov      w1, #0x3d
//   0x23a7bc: 14039D4D  b        #0x321cf0
static inline uint64_t fde_func_0909_0x23a7b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a7b8ULL ^ (static_cast<uint64_t>(0x528007a1ULL) << 13);
    acc = (acc + a1 + 0x14039d4dULL) ^ 0x0e5960ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0910 | PC: 0x23a7c0 | FDE: 0x0e5978 | Size: 20 bytes [_ZN4lynx4tasm7LynxEnv24EnableAsyncDestroyEngineEv]
// Khung tháo gỡ #0910 | Địa chỉ PC: 0x23a7c0 | Địa chỉ FDE: 0x0e5978 | Kích thước: 20 bytes
//   0x23a7c0: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x23a7c4: 528007C1  mov      w1, #0x3e
//   0x23a7c8: 9403C275  bl       #0x32b19c
//   0x23a7cc: F84107FE  ldr      x30, [sp], #0x10
static inline uint64_t fde_func_0910_0x23a7c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a7c0ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x528007c1ULL) ^ 0x0e5978ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0911 | PC: 0x23a7d4 | FDE: 0x0e5990 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv26EnableComponentAsyncDecodeEv]
// Khung tháo gỡ #0911 | Địa chỉ PC: 0x23a7d4 | Địa chỉ FDE: 0x0e5990 | Kích thước: 8 bytes
//   0x23a7d4: 528004C1  mov      w1, #0x26
//   0x23a7d8: 14038AAC  b        #0x31d288
static inline uint64_t fde_func_0911_0x23a7d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a7d4ULL ^ (static_cast<uint64_t>(0x528004c1ULL) << 13);
    acc = (acc + a1 + 0x14038aacULL) ^ 0x0e5990ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0912 | PC: 0x23a7dc | FDE: 0x0e59a8 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv20EnableUseContextPoolEv]
// Khung tháo gỡ #0912 | Địa chỉ PC: 0x23a7dc | Địa chỉ FDE: 0x0e59a8 | Kích thước: 8 bytes
//   0x23a7dc: 52800801  mov      w1, #0x40
//   0x23a7e0: 14039D44  b        #0x321cf0
static inline uint64_t fde_func_0912_0x23a7dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a7dcULL ^ (static_cast<uint64_t>(0x52800801ULL) << 13);
    acc = (acc + a1 + 0x14039d44ULL) ^ 0x0e59a8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0913 | PC: 0x23a7e4 | FDE: 0x0e59c0 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv27EnableNativeCreateViewAsyncEv]
// Khung tháo gỡ #0913 | Địa chỉ PC: 0x23a7e4 | Địa chỉ FDE: 0x0e59c0 | Kích thước: 8 bytes
//   0x23a7e4: 52800841  mov      w1, #0x42
//   0x23a7e8: 14038AA8  b        #0x31d288
static inline uint64_t fde_func_0913_0x23a7e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a7e4ULL ^ (static_cast<uint64_t>(0x52800841ULL) << 13);
    acc = (acc + a1 + 0x14038aa8ULL) ^ 0x0e59c0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0914 | PC: 0x23a7ec | FDE: 0x0e59d8 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv15EnableSignalAPIEv]
// Khung tháo gỡ #0914 | Địa chỉ PC: 0x23a7ec | Địa chỉ FDE: 0x0e59d8 | Kích thước: 8 bytes
//   0x23a7ec: 52800861  mov      w1, #0x43
//   0x23a7f0: 14038AA6  b        #0x31d288
static inline uint64_t fde_func_0914_0x23a7ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a7ecULL ^ (static_cast<uint64_t>(0x52800861ULL) << 13);
    acc = (acc + a1 + 0x14038aa6ULL) ^ 0x0e59d8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0915 | PC: 0x23a7f4 | FDE: 0x0e59f0 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv14EnableFixedNewEv]
// Khung tháo gỡ #0915 | Địa chỉ PC: 0x23a7f4 | Địa chỉ FDE: 0x0e59f0 | Kích thước: 8 bytes
//   0x23a7f4: 52800881  mov      w1, #0x44
//   0x23a7f8: 14038AA4  b        #0x31d288
static inline uint64_t fde_func_0915_0x23a7f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a7f4ULL ^ (static_cast<uint64_t>(0x52800881ULL) << 13);
    acc = (acc + a1 + 0x14038aa4ULL) ^ 0x0e59f0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0916 | PC: 0x23a7fc | FDE: 0x0e5a08 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv16EnableMultiTouchEv]
// Khung tháo gỡ #0916 | Địa chỉ PC: 0x23a7fc | Địa chỉ FDE: 0x0e5a08 | Kích thước: 8 bytes
//   0x23a7fc: 528008A1  mov      w1, #0x45
//   0x23a800: 14038AA2  b        #0x31d288
static inline uint64_t fde_func_0916_0x23a7fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a7fcULL ^ (static_cast<uint64_t>(0x528008a1ULL) << 13);
    acc = (acc + a1 + 0x14038aa2ULL) ^ 0x0e5a08ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0917 | PC: 0x23a804 | FDE: 0x0e5a20 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv29EnableNewIntersectionObserverEv]
// Khung tháo gỡ #0917 | Địa chỉ PC: 0x23a804 | Địa chỉ FDE: 0x0e5a20 | Kích thước: 8 bytes
//   0x23a804: 528008C1  mov      w1, #0x46
//   0x23a808: 14038AA0  b        #0x31d288
static inline uint64_t fde_func_0917_0x23a804(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a804ULL ^ (static_cast<uint64_t>(0x528008c1ULL) << 13);
    acc = (acc + a1 + 0x14038aa0ULL) ^ 0x0e5a20ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0918 | PC: 0x23a80c | FDE: 0x0e5a38 | Size: 88 bytes [_ZN4lynx4tasm7LynxEnv30EnableAnimationVsyncOnUIThreadEv]
// Khung tháo gỡ #0918 | Địa chỉ PC: 0x23a80c | Địa chỉ FDE: 0x0e5a38 | Kích thước: 88 bytes
//   0x23a80c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x23a810: B0000988  adrp     x8, #0x36b000
//   0x23a814: 91046108  add      x8, x8, #0x118
//   0x23a818: 08DFFD08  ldarb    w8, [x8]
static inline uint64_t fde_func_0918_0x23a80c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a80cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb0000988ULL) ^ 0x0e5a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0919 | PC: 0x23a864 | FDE: 0x0e5a50 | Size: 88 bytes [_ZN4lynx4tasm7LynxEnv25EnableAnimationInfoReportEv]
// Khung tháo gỡ #0919 | Địa chỉ PC: 0x23a864 | Địa chỉ FDE: 0x0e5a50 | Kích thước: 88 bytes
//   0x23a864: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x23a868: B0000988  adrp     x8, #0x36b000
//   0x23a86c: 91048108  add      x8, x8, #0x120
//   0x23a870: 08DFFD08  ldarb    w8, [x8]
static inline uint64_t fde_func_0919_0x23a864(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a864ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb0000988ULL) ^ 0x0e5a50ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0920 | PC: 0x23a8bc | FDE: 0x0e5a68 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv35EnableBatchLayoutTaskWithSyncLayoutEv]
// Khung tháo gỡ #0920 | Địa chỉ PC: 0x23a8bc | Địa chỉ FDE: 0x0e5a68 | Kích thước: 8 bytes
//   0x23a8bc: 52800981  mov      w1, #0x4c
//   0x23a8c0: 14038A72  b        #0x31d288
static inline uint64_t fde_func_0920_0x23a8bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a8bcULL ^ (static_cast<uint64_t>(0x52800981ULL) << 13);
    acc = (acc + a1 + 0x14038a72ULL) ^ 0x0e5a68ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0921 | PC: 0x23a8c4 | FDE: 0x0e5a80 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv22FixParallelZIndexCrashEv]
// Khung tháo gỡ #0921 | Địa chỉ PC: 0x23a8c4 | Địa chỉ FDE: 0x0e5a80 | Kích thước: 8 bytes
//   0x23a8c4: 528009E1  mov      w1, #0x4f
//   0x23a8c8: 14039D0A  b        #0x321cf0
static inline uint64_t fde_func_0921_0x23a8c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a8c4ULL ^ (static_cast<uint64_t>(0x528009e1ULL) << 13);
    acc = (acc + a1 + 0x14039d0aULL) ^ 0x0e5a80ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0922 | PC: 0x23a8cc | FDE: 0x0e5a98 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv23FixInsertBeforeFixedBugEv]
// Khung tháo gỡ #0922 | Địa chỉ PC: 0x23a8cc | Địa chỉ FDE: 0x0e5a98 | Kích thước: 8 bytes
//   0x23a8cc: 52800A01  mov      w1, #0x50
//   0x23a8d0: 14039D08  b        #0x321cf0
static inline uint64_t fde_func_0922_0x23a8cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a8ccULL ^ (static_cast<uint64_t>(0x52800a01ULL) << 13);
    acc = (acc + a1 + 0x14039d08ULL) ^ 0x0e5a98ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0923 | PC: 0x23a8d4 | FDE: 0x0e5ab0 | Size: 60 bytes [_ZN4lynx4tasm7LynxEnv17EnableJSVMRuntimeEv]
// Khung tháo gỡ #0923 | Địa chỉ PC: 0x23a8d4 | Địa chỉ FDE: 0x0e5ab0 | Kích thước: 60 bytes
//   0x23a8d4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x23a8d8: 528009A1  mov      w1, #0x4d
//   0x23a8dc: 52800023  mov      w3, #1
//   0x23a8e0: 2A1F03E2  mov      w2, wzr
static inline uint64_t fde_func_0923_0x23a8d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a8d4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x528009a1ULL) ^ 0x0e5ab0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0924 | PC: 0x23a910 | FDE: 0x0e5ac8 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv26EnableUnifiedPixelPipelineEv]
// Khung tháo gỡ #0924 | Địa chỉ PC: 0x23a910 | Địa chỉ FDE: 0x0e5ac8 | Kích thước: 8 bytes
//   0x23a910: 528009C1  mov      w1, #0x4e
//   0x23a914: 14038A5D  b        #0x31d288
static inline uint64_t fde_func_0924_0x23a910(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a910ULL ^ (static_cast<uint64_t>(0x528009c1ULL) << 13);
    acc = (acc + a1 + 0x14038a5dULL) ^ 0x0e5ac8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0925 | PC: 0x23a918 | FDE: 0x0e5ae0 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv25EnableEventHandleRefactorEv]
// Khung tháo gỡ #0925 | Địa chỉ PC: 0x23a918 | Địa chỉ FDE: 0x0e5ae0 | Kích thước: 8 bytes
//   0x23a918: 52800B41  mov      w1, #0x5a
//   0x23a91c: 14038A5B  b        #0x31d288
static inline uint64_t fde_func_0925_0x23a918(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a918ULL ^ (static_cast<uint64_t>(0x52800b41ULL) << 13);
    acc = (acc + a1 + 0x14038a5bULL) ^ 0x0e5ae0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0926 | PC: 0x23a920 | FDE: 0x0e5af8 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv19EnableDecoupledListEv]
// Khung tháo gỡ #0926 | Địa chỉ PC: 0x23a920 | Địa chỉ FDE: 0x0e5af8 | Kích thước: 8 bytes
//   0x23a920: 52800B61  mov      w1, #0x5b
//   0x23a924: 14038A59  b        #0x31d288
static inline uint64_t fde_func_0926_0x23a920(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a920ULL ^ (static_cast<uint64_t>(0x52800b61ULL) << 13);
    acc = (acc + a1 + 0x14038a59ULL) ^ 0x0e5af8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0927 | PC: 0x23a928 | FDE: 0x0e5b10 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv27EnableReportMTSContextEventEv]
// Khung tháo gỡ #0927 | Địa chỉ PC: 0x23a928 | Địa chỉ FDE: 0x0e5b10 | Kích thước: 8 bytes
//   0x23a928: 52800A21  mov      w1, #0x51
//   0x23a92c: 14038A57  b        #0x31d288
static inline uint64_t fde_func_0927_0x23a928(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a928ULL ^ (static_cast<uint64_t>(0x52800a21ULL) << 13);
    acc = (acc + a1 + 0x14038a57ULL) ^ 0x0e5b10ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0928 | PC: 0x23a930 | FDE: 0x0e5b28 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv30EnableFiberElementMemoryReportEv]
// Khung tháo gỡ #0928 | Địa chỉ PC: 0x23a930 | Địa chỉ FDE: 0x0e5b28 | Kích thước: 8 bytes
//   0x23a930: 52800A41  mov      w1, #0x52
//   0x23a934: 14039CEF  b        #0x321cf0
static inline uint64_t fde_func_0928_0x23a930(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a930ULL ^ (static_cast<uint64_t>(0x52800a41ULL) << 13);
    acc = (acc + a1 + 0x14039cefULL) ^ 0x0e5b28ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0929 | PC: 0x23a938 | FDE: 0x0e5b40 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv37FixFontSizeOverrideDirectionChangeBugEv]
// Khung tháo gỡ #0929 | Địa chỉ PC: 0x23a938 | Địa chỉ FDE: 0x0e5b40 | Kích thước: 8 bytes
//   0x23a938: 52800A61  mov      w1, #0x53
//   0x23a93c: 14039CED  b        #0x321cf0
static inline uint64_t fde_func_0929_0x23a938(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a938ULL ^ (static_cast<uint64_t>(0x52800a61ULL) << 13);
    acc = (acc + a1 + 0x14039cedULL) ^ 0x0e5b40ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0930 | PC: 0x23a940 | FDE: 0x0e5b58 | Size: 88 bytes [_ZN4lynx4tasm7LynxEnv33EnableNewAnimatorOnPatchFinishOptEv]
// Khung tháo gỡ #0930 | Địa chỉ PC: 0x23a940 | Địa chỉ FDE: 0x0e5b58 | Kích thước: 88 bytes
//   0x23a940: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x23a944: B0000988  adrp     x8, #0x36b000
//   0x23a948: 9104A108  add      x8, x8, #0x128
//   0x23a94c: 08DFFD08  ldarb    w8, [x8]
static inline uint64_t fde_func_0930_0x23a940(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a940ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb0000988ULL) ^ 0x0e5b58ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0931 | PC: 0x23a998 | FDE: 0x0e5b70 | Size: 88 bytes [_ZN4lynx4tasm7LynxEnv35FixRadonTransitionPropertyRemoveBugEv]
// Khung tháo gỡ #0931 | Địa chỉ PC: 0x23a998 | Địa chỉ FDE: 0x0e5b70 | Kích thước: 88 bytes
//   0x23a998: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x23a99c: B0000988  adrp     x8, #0x36b000
//   0x23a9a0: 9104C108  add      x8, x8, #0x130
//   0x23a9a4: 08DFFD08  ldarb    w8, [x8]
static inline uint64_t fde_func_0931_0x23a998(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a998ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb0000988ULL) ^ 0x0e5b70ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0932 | PC: 0x23a9f0 | FDE: 0x0e5b88 | Size: 88 bytes [_ZN4lynx4tasm7LynxEnv26EnableGlobalFontCollectionEv]
// Khung tháo gỡ #0932 | Địa chỉ PC: 0x23a9f0 | Địa chỉ FDE: 0x0e5b88 | Kích thước: 88 bytes
//   0x23a9f0: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x23a9f4: B0000988  adrp     x8, #0x36b000
//   0x23a9f8: 9104E108  add      x8, x8, #0x138
//   0x23a9fc: 08DFFD08  ldarb    w8, [x8]
static inline uint64_t fde_func_0932_0x23a9f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23a9f0ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb0000988ULL) ^ 0x0e5b88ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0933 | PC: 0x23aa48 | FDE: 0x0e5ba0 | Size: 88 bytes [_ZN4lynx4tasm7LynxEnv18EnableGCOnceOnIdleEv]
// Khung tháo gỡ #0933 | Địa chỉ PC: 0x23aa48 | Địa chỉ FDE: 0x0e5ba0 | Kích thước: 88 bytes
//   0x23aa48: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x23aa4c: B0000988  adrp     x8, #0x36b000
//   0x23aa50: 91050108  add      x8, x8, #0x140
//   0x23aa54: 08DFFD08  ldarb    w8, [x8]
static inline uint64_t fde_func_0933_0x23aa48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23aa48ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb0000988ULL) ^ 0x0e5ba0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0934 | PC: 0x23aaa0 | FDE: 0x0e5bb8 | Size: 88 bytes [_ZN4lynx4tasm7LynxEnv24EnableCSSInlineVariablesEv]
// Khung tháo gỡ #0934 | Địa chỉ PC: 0x23aaa0 | Địa chỉ FDE: 0x0e5bb8 | Kích thước: 88 bytes
//   0x23aaa0: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x23aaa4: B0000988  adrp     x8, #0x36b000
//   0x23aaa8: 91052108  add      x8, x8, #0x148
//   0x23aaac: 08DFFD08  ldarb    w8, [x8]
static inline uint64_t fde_func_0934_0x23aaa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23aaa0ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb0000988ULL) ^ 0x0e5bb8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0935 | PC: 0x23aaf8 | FDE: 0x0e5bd0 | Size: 88 bytes [_ZN4lynx4tasm7LynxEnv24EnableOptimizeHasOpacityEv]
// Khung tháo gỡ #0935 | Địa chỉ PC: 0x23aaf8 | Địa chỉ FDE: 0x0e5bd0 | Kích thước: 88 bytes
//   0x23aaf8: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x23aafc: B0000988  adrp     x8, #0x36b000
//   0x23ab00: 91054108  add      x8, x8, #0x150
//   0x23ab04: 08DFFD08  ldarb    w8, [x8]
static inline uint64_t fde_func_0935_0x23aaf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23aaf8ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb0000988ULL) ^ 0x0e5bd0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0936 | PC: 0x23ab50 | FDE: 0x0e5be8 | Size: 88 bytes [_ZN4lynx4tasm7LynxEnv18DisableJSModeStripEv]
// Khung tháo gỡ #0936 | Địa chỉ PC: 0x23ab50 | Địa chỉ FDE: 0x0e5be8 | Kích thước: 88 bytes
//   0x23ab50: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x23ab54: B0000988  adrp     x8, #0x36b000
//   0x23ab58: 91056108  add      x8, x8, #0x158
//   0x23ab5c: 08DFFD08  ldarb    w8, [x8]
static inline uint64_t fde_func_0936_0x23ab50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23ab50ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb0000988ULL) ^ 0x0e5be8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0937 | PC: 0x23aba8 | FDE: 0x0e5c00 | Size: 88 bytes [_ZN4lynx4tasm7LynxEnv21EnablePlatformDataFixEv]
// Khung tháo gỡ #0937 | Địa chỉ PC: 0x23aba8 | Địa chỉ FDE: 0x0e5c00 | Kích thước: 88 bytes
//   0x23aba8: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x23abac: B0000988  adrp     x8, #0x36b000
//   0x23abb0: 91058108  add      x8, x8, #0x160
//   0x23abb4: 08DFFD08  ldarb    w8, [x8]
static inline uint64_t fde_func_0937_0x23aba8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23aba8ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb0000988ULL) ^ 0x0e5c00ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0938 | PC: 0x23ac00 | FDE: 0x0e5c18 | Size: 112 bytes [_ZN4lynx4tasm7LynxEnv26EnableQuickJsThreadCheckerEv]
// Khung tháo gỡ #0938 | Địa chỉ PC: 0x23ac00 | Địa chỉ FDE: 0x0e5c18 | Kích thước: 112 bytes
//   0x23ac00: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x23ac04: B0000988  adrp     x8, #0x36b000
//   0x23ac08: 9105A108  add      x8, x8, #0x168
//   0x23ac0c: 08DFFD08  ldarb    w8, [x8]
static inline uint64_t fde_func_0938_0x23ac00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23ac00ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb0000988ULL) ^ 0x0e5c18ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0939 | PC: 0x23ac70 | FDE: 0x0e5c30 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv26EnableLevelOrderTraversingEv]
// Khung tháo gỡ #0939 | Địa chỉ PC: 0x23ac70 | Địa chỉ FDE: 0x0e5c30 | Kích thước: 8 bytes
//   0x23ac70: 52800CC1  mov      w1, #0x66
//   0x23ac74: 14038985  b        #0x31d288
static inline uint64_t fde_func_0939_0x23ac70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23ac70ULL ^ (static_cast<uint64_t>(0x52800cc1ULL) << 13);
    acc = (acc + a1 + 0x14038985ULL) ^ 0x0e5c30ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0940 | PC: 0x23ac78 | FDE: 0x0e5c48 | Size: 88 bytes [_ZN4lynx4tasm7LynxEnv24FixRadonInlineConvertBugEv]
// Khung tháo gỡ #0940 | Địa chỉ PC: 0x23ac78 | Địa chỉ FDE: 0x0e5c48 | Kích thước: 88 bytes
//   0x23ac78: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x23ac7c: B0000988  adrp     x8, #0x36b000
//   0x23ac80: 9105C108  add      x8, x8, #0x170
//   0x23ac84: 08DFFD08  ldarb    w8, [x8]
static inline uint64_t fde_func_0940_0x23ac78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23ac78ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb0000988ULL) ^ 0x0e5c48ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0941 | PC: 0x23acd0 | FDE: 0x0e5c60 | Size: 8 bytes [_ZN4lynx4tasm7LynxEnv21FixNewFixedRemovalBugEv]
// Khung tháo gỡ #0941 | Địa chỉ PC: 0x23acd0 | Địa chỉ FDE: 0x0e5c60 | Kích thước: 8 bytes
//   0x23acd0: 52800BC1  mov      w1, #0x5e
//   0x23acd4: 14039C07  b        #0x321cf0
static inline uint64_t fde_func_0941_0x23acd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23acd0ULL ^ (static_cast<uint64_t>(0x52800bc1ULL) << 13);
    acc = (acc + a1 + 0x14039c07ULL) ^ 0x0e5c60ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0942 | PC: 0x23acd8 | FDE: 0x0e5c78 | Size: 60 bytes [_ZN4lynx4tasm7LynxEnv12GetV8EnabledEb]
// Khung tháo gỡ #0942 | Địa chỉ PC: 0x23acd8 | Địa chỉ FDE: 0x0e5c78 | Kích thước: 60 bytes
//   0x23acd8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x23acdc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x23ace0: 9403D770  bl       #0x330aa0
//   0x23ace4: 370000A0  tbnz     w0, #0, #0x23acf8
static inline uint64_t fde_func_0942_0x23acd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23acd8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0e5c78ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0943 | PC: 0x23ad14 | FDE: 0x0e5c98 | Size: 48 bytes [_ZN4lynx4tasm7LynxEnv21IsQuickjsDebugEnabledEb]
// Khung tháo gỡ #0943 | Địa chỉ PC: 0x23ad14 | Địa chỉ FDE: 0x0e5c98 | Kích thước: 48 bytes
//   0x23ad14: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x23ad18: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x23ad1c: 9403D761  bl       #0x330aa0
//   0x23ad20: 370000A0  tbnz     w0, #0, #0x23ad34
static inline uint64_t fde_func_0943_0x23ad14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23ad14ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0e5c98ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0944 | PC: 0x23ad44 | FDE: 0x0e5cb8 | Size: 256 bytes [_ZN4lynx4tasm7LynxEnv16IsJsDebugEnabledEbb]
// Khung tháo gỡ #0944 | Địa chỉ PC: 0x23ad44 | Địa chỉ FDE: 0x0e5cb8 | Kích thước: 256 bytes
//   0x23ad44: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x23ad48: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x23ad4c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x23ad50: 12000055  and      w21, w2, #1
static inline uint64_t fde_func_0944_0x23ad44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23ad44ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0e5cb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0945 | PC: 0x23b030 | FDE: 0x0e5da8 | Size: 256 bytes
// Khung tháo gỡ #0945 | Địa chỉ PC: 0x23b030 | Địa chỉ FDE: 0x0e5da8 | Kích thước: 256 bytes
//   0x23b030: D101C3FF  sub      sp, sp, #0x70
//   0x23b034: F90023F6  str      x22, [sp, #0x40]
//   0x23b038: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x23b03c: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_0945_0x23b030(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23b030ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f6ULL) ^ 0x0e5da8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0946 | PC: 0x23b51c | FDE: 0x0e5ee0 | Size: 256 bytes
// Khung tháo gỡ #0946 | Địa chỉ PC: 0x23b51c | Địa chỉ FDE: 0x0e5ee0 | Kích thước: 256 bytes
//   0x23b51c: D10183FF  sub      sp, sp, #0x60
//   0x23b520: F9001BF6  str      x22, [sp, #0x30]
//   0x23b524: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x23b528: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0946_0x23b51c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23b51cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf6ULL) ^ 0x0e5ee0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0947 | PC: 0x23be8c | FDE: 0x0e6040 | Size: 256 bytes
// Khung tháo gỡ #0947 | Địa chỉ PC: 0x23be8c | Địa chỉ FDE: 0x0e6040 | Kích thước: 256 bytes
//   0x23be8c: F9400408  ldr      x8, [x0, #8]
//   0x23be90: 93407C21  sxtw     x1, w1
//   0x23be94: F9400108  ldr      x8, [x8]
//   0x23be98: 91004100  add      x0, x8, #0x10
static inline uint64_t fde_func_0947_0x23be8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23be8cULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x93407c21ULL) ^ 0x0e6040ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0948 | PC: 0x23c1e0 | FDE: 0x0e6150 | Size: 256 bytes
// Khung tháo gỡ #0948 | Địa chỉ PC: 0x23c1e0 | Địa chỉ FDE: 0x0e6150 | Kích thước: 256 bytes
//   0x23c1e0: D10183FF  sub      sp, sp, #0x60
//   0x23c1e4: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x23c1e8: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x23c1ec: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0948_0x23c1e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23c1e0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9035bf7ULL) ^ 0x0e6150ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0949 | PC: 0x23c920 | FDE: 0x0e6280 | Size: 256 bytes
// Khung tháo gỡ #0949 | Địa chỉ PC: 0x23c920 | Địa chỉ FDE: 0x0e6280 | Kích thước: 256 bytes
//   0x23c920: AA1E03E2  mov      x2, x30
//   0x23c924: 9403AAF2  bl       #0x3274ec
//   0x23c928: AA0203FE  mov      x30, x2
//   0x23c92c: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_0949_0x23c920(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23c920ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9403aaf2ULL) ^ 0x0e6280ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0950 | PC: 0x23cffc | FDE: 0x0e63c8 | Size: 256 bytes
// Khung tháo gỡ #0950 | Địa chỉ PC: 0x23cffc | Địa chỉ FDE: 0x0e63c8 | Kích thước: 256 bytes
//   0x23cffc: B4000101  cbz      x1, #0x23d01c
//   0x23d000: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x23d004: AA0103E0  mov      x0, x1
//   0x23d008: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0950_0x23cffc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23cffcULL ^ (static_cast<uint64_t>(0xb4000101ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bf3ULL) ^ 0x0e63c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0951 | PC: 0x23d58c | FDE: 0x0e6500 | Size: 256 bytes
// Khung tháo gỡ #0951 | Địa chỉ PC: 0x23d58c | Địa chỉ FDE: 0x0e6500 | Kích thước: 256 bytes
//   0x23d58c: D10143FF  sub      sp, sp, #0x50
//   0x23d590: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x23d594: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x23d598: 94039562  bl       #0x322b20
static inline uint64_t fde_func_0951_0x23d58c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23d58cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90353f5ULL) ^ 0x0e6500ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0952 | PC: 0x23dbf0 | FDE: 0x0e6658 | Size: 256 bytes
// Khung tháo gỡ #0952 | Địa chỉ PC: 0x23dbf0 | Địa chỉ FDE: 0x0e6658 | Kích thước: 256 bytes
//   0x23dbf0: D10203FF  sub      sp, sp, #0x80
//   0x23dbf4: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x23dbf8: A9077BF3  stp      x19, x30, [sp, #0x70]
//   0x23dbfc: 9403B1E4  bl       #0x32a38c
static inline uint64_t fde_func_0952_0x23dbf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23dbf0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90653f5ULL) ^ 0x0e6658ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0953 | PC: 0x23e3f4 | FDE: 0x0e67b0 | Size: 256 bytes
// Khung tháo gỡ #0953 | Địa chỉ PC: 0x23e3f4 | Địa chỉ FDE: 0x0e67b0 | Kích thước: 256 bytes
//   0x23e3f4: D10103FF  sub      sp, sp, #0x40
//   0x23e3f8: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x23e3fc: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x23e400: 9403AFE9  bl       #0x32a3a4
static inline uint64_t fde_func_0953_0x23e3f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23e3f4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x0e67b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0954 | PC: 0x23ef1c | FDE: 0x0e6908 | Size: 256 bytes
// Khung tháo gỡ #0954 | Địa chỉ PC: 0x23ef1c | Địa chỉ FDE: 0x0e6908 | Kích thước: 256 bytes
//   0x23ef1c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x23ef20: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x23ef24: F9400808  ldr      x8, [x0, #0x10]
//   0x23ef28: 94039076  bl       #0x323100
static inline uint64_t fde_func_0954_0x23ef1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23ef1cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0e6908ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0955 | PC: 0x23f57c | FDE: 0x0e6a48 | Size: 256 bytes
// Khung tháo gỡ #0955 | Địa chỉ PC: 0x23f57c | Địa chỉ FDE: 0x0e6a48 | Kích thước: 256 bytes
//   0x23f57c: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x23f580: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x23f584: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x23f588: B00008A8  adrp     x8, #0x354000
static inline uint64_t fde_func_0955_0x23f57c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23f57cULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0e6a48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0956 | PC: 0x23fd68 | FDE: 0x0e6b80 | Size: 256 bytes
// Khung tháo gỡ #0956 | Địa chỉ PC: 0x23fd68 | Địa chỉ FDE: 0x0e6b80 | Kích thước: 256 bytes
//   0x23fd68: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x23fd6c: AA0003F3  mov      x19, x0
//   0x23fd70: 97FFFFF8  bl       #0x23fd50
//   0x23fd74: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0956_0x23fd68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x23fd68ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0e6b80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0957 | PC: 0x240370 | FDE: 0x0e6cb8 | Size: 256 bytes
// Khung tháo gỡ #0957 | Địa chỉ PC: 0x240370 | Địa chỉ FDE: 0x0e6cb8 | Kích thước: 256 bytes
//   0x240370: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x240374: 9E620020  scvtf    d0, x1
//   0x240378: 94040572  bl       #0x341940
//   0x24037c: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_0957_0x240370(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x240370ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x9e620020ULL) ^ 0x0e6cb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0958 | PC: 0x2408e4 | FDE: 0x0e6de0 | Size: 256 bytes
// Khung tháo gỡ #0958 | Địa chỉ PC: 0x2408e4 | Địa chỉ FDE: 0x0e6de0 | Kích thước: 256 bytes
//   0x2408e4: AA1E03E8  mov      x8, x30
//   0x2408e8: 9403A7AA  bl       #0x32a790
//   0x2408ec: AA0803FE  mov      x30, x8
//   0x2408f0: A9177BFD  stp      x29, x30, [sp, #0x170]
static inline uint64_t fde_func_0958_0x2408e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2408e4ULL ^ (static_cast<uint64_t>(0xaa1e03e8ULL) << 13);
    acc = (acc + a1 + 0x9403a7aaULL) ^ 0x0e6de0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0959 | PC: 0x241374 | FDE: 0x0e6f40 | Size: 256 bytes
// Khung tháo gỡ #0959 | Địa chỉ PC: 0x241374 | Địa chỉ FDE: 0x0e6f40 | Kích thước: 256 bytes
//   0x241374: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x241378: AA0103E0  mov      x0, x1
//   0x24137c: 52800021  mov      w1, #1
//   0x241380: 2A0403F3  mov      w19, w4
static inline uint64_t fde_func_0959_0x241374(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x241374ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0103e0ULL) ^ 0x0e6f40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0960 | PC: 0x242100 | FDE: 0x0e70b8 | Size: 256 bytes
// Khung tháo gỡ #0960 | Địa chỉ PC: 0x242100 | Địa chỉ FDE: 0x0e70b8 | Kích thước: 256 bytes
//   0x242100: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x242104: 1E22C000  fcvt     d0, s0
//   0x242108: 9403FE0E  bl       #0x341940
//   0x24210c: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_0960_0x242100(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x242100ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x1e22c000ULL) ^ 0x0e70b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0961 | PC: 0x2426b4 | FDE: 0x0e71d8 | Size: 256 bytes
// Khung tháo gỡ #0961 | Địa chỉ PC: 0x2426b4 | Địa chỉ FDE: 0x0e71d8 | Kích thước: 256 bytes
//   0x2426b4: D10243FF  sub      sp, sp, #0x90
//   0x2426b8: A9065BF7  stp      x23, x22, [sp, #0x60]
//   0x2426bc: A90753F5  stp      x21, x20, [sp, #0x70]
//   0x2426c0: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_0961_0x2426b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2426b4ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9065bf7ULL) ^ 0x0e71d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0962 | PC: 0x242a7c | FDE: 0x0e7300 | Size: 256 bytes
// Khung tháo gỡ #0962 | Địa chỉ PC: 0x242a7c | Địa chỉ FDE: 0x0e7300 | Kích thước: 256 bytes
//   0x242a7c: B4000100  cbz      x0, #0x242a9c
//   0x242a80: 885F7C08  ldxr     w8, [x0]
//   0x242a84: 71000508  subs     w8, w8, #1
//   0x242a88: 8809FC08  stlxr    w9, w8, [x0]
static inline uint64_t fde_func_0962_0x242a7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x242a7cULL ^ (static_cast<uint64_t>(0xb4000100ULL) << 13);
    acc = (acc + a1 + 0x885f7c08ULL) ^ 0x0e7300ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0963 | PC: 0x243204 | FDE: 0x0e7438 | Size: 256 bytes
// Khung tháo gỡ #0963 | Địa chỉ PC: 0x243204 | Địa chỉ FDE: 0x0e7438 | Kích thước: 256 bytes
//   0x243204: D102C3FF  sub      sp, sp, #0xb0
//   0x243208: A9085BF7  stp      x23, x22, [sp, #0x80]
//   0x24320c: A90953F5  stp      x21, x20, [sp, #0x90]
//   0x243210: A90A7BF3  stp      x19, x30, [sp, #0xa0]
static inline uint64_t fde_func_0963_0x243204(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x243204ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9085bf7ULL) ^ 0x0e7438ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0964 | PC: 0x2436b8 | FDE: 0x0e7560 | Size: 256 bytes
// Khung tháo gỡ #0964 | Địa chỉ PC: 0x2436b8 | Địa chỉ FDE: 0x0e7560 | Kích thước: 256 bytes
//   0x2436b8: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x2436bc: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x2436c0: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x2436c4: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0964_0x2436b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2436b8ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0e7560ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0965 | PC: 0x243c64 | FDE: 0x0e7698 | Size: 256 bytes
// Khung tháo gỡ #0965 | Địa chỉ PC: 0x243c64 | Địa chỉ FDE: 0x0e7698 | Kích thước: 256 bytes
//   0x243c64: D101C3FF  sub      sp, sp, #0x70
//   0x243c68: F9002BF4  str      x20, [sp, #0x50]
//   0x243c6c: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x243c70: 94036777  bl       #0x31da4c
static inline uint64_t fde_func_0965_0x243c64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x243c64ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x0e7698ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0966 | PC: 0x244188 | FDE: 0x0e77c8 | Size: 256 bytes [_ZN4lynx4tasm6replay16ReplayController13GetLayoutTreeEPNS_9starlight12LayoutObjectE]
// Khung tháo gỡ #0966 | Địa chỉ PC: 0x244188 | Địa chỉ FDE: 0x0e77c8 | Kích thước: 256 bytes
//   0x244188: 1403C708  b        #0x335da8
//   0x24418c: 14038E7D  b        #0x327b80
//   0x244190: AA1E03E3  mov      x3, x30
//   0x244194: 94036134  bl       #0x31c664
static inline uint64_t fde_func_0966_0x244188(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x244188ULL ^ (static_cast<uint64_t>(0x1403c708ULL) << 13);
    acc = (acc + a1 + 0x14038e7dULL) ^ 0x0e77c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0967 | PC: 0x244960 | FDE: 0x0e78f0 | Size: 256 bytes
// Khung tháo gỡ #0967 | Địa chỉ PC: 0x244960 | Địa chỉ FDE: 0x0e78f0 | Kích thước: 256 bytes
//   0x244960: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x244964: AA0003F3  mov      x19, x0
//   0x244968: 97FFFFF6  bl       #0x244940
//   0x24496c: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0967_0x244960(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x244960ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0e78f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0968 | PC: 0x244bd0 | FDE: 0x0e79f8 | Size: 256 bytes
// Khung tháo gỡ #0968 | Địa chỉ PC: 0x244bd0 | Địa chỉ FDE: 0x0e79f8 | Kích thước: 256 bytes
//   0x244bd0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x244bd4: AA0003F3  mov      x19, x0
//   0x244bd8: 91002020  add      x0, x1, #8
//   0x244bdc: AA0203E1  mov      x1, x2
static inline uint64_t fde_func_0968_0x244bd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x244bd0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0e79f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0969 | PC: 0x244d98 | FDE: 0x0e7af8 | Size: 84 bytes
// Khung tháo gỡ #0969 | Địa chỉ PC: 0x244d98 | Địa chỉ FDE: 0x0e7af8 | Kích thước: 84 bytes
//   0x244d98: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x244d9c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x244da0: 94036E3C  bl       #0x320690
//   0x244da4: B40000D4  cbz      x20, #0x244dbc
static inline uint64_t fde_func_0969_0x244d98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x244d98ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0e7af8ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0970 | PC: 0x244dec | FDE: 0x0e7b30 | Size: 256 bytes [_ZN4lynx4tasm13LynxEnvConfigC1Efffd]
// Khung tháo gỡ #0970 | Địa chỉ PC: 0x244dec | Địa chỉ FDE: 0x0e7b30 | Kích thước: 256 bytes
//   0x244dec: 52800028  mov      w8, #1
//   0x244df0: 39003008  strb     w8, [x0, #0xc]
//   0x244df4: 39005008  strb     w8, [x0, #0x14]
//   0x244df8: 52A7F008  mov      w8, #0x3f800000
static inline uint64_t fde_func_0970_0x244dec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x244decULL ^ (static_cast<uint64_t>(0x52800028ULL) << 13);
    acc = (acc + a1 + 0x39003008ULL) ^ 0x0e7b30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0971 | PC: 0x245584 | FDE: 0x0e7c38 | Size: 256 bytes
// Khung tháo gỡ #0971 | Địa chỉ PC: 0x245584 | Địa chỉ FDE: 0x0e7c38 | Kích thước: 256 bytes
//   0x245584: AA1E03E4  mov      x4, x30
//   0x245588: 940362E0  bl       #0x31e108
//   0x24558c: AA0403FE  mov      x30, x4
//   0x245590: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0971_0x245584(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x245584ULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x940362e0ULL) ^ 0x0e7c38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0972 | PC: 0x245dd8 | FDE: 0x0e7da0 | Size: 256 bytes
// Khung tháo gỡ #0972 | Địa chỉ PC: 0x245dd8 | Địa chỉ FDE: 0x0e7da0 | Kích thước: 256 bytes
//   0x245dd8: D101C3FF  sub      sp, sp, #0x70
//   0x245ddc: F90023F6  str      x22, [sp, #0x40]
//   0x245de0: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x245de4: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_0972_0x245dd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x245dd8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f6ULL) ^ 0x0e7da0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0973 | PC: 0x2463a8 | FDE: 0x0e7ed8 | Size: 256 bytes
// Khung tháo gỡ #0973 | Địa chỉ PC: 0x2463a8 | Địa chỉ FDE: 0x0e7ed8 | Kích thước: 256 bytes
//   0x2463a8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2463ac: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2463b0: D0000868  adrp     x8, #0x354000
//   0x2463b4: 912E6108  add      x8, x8, #0xb98
static inline uint64_t fde_func_0973_0x2463a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2463a8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0e7ed8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0974 | PC: 0x2465fc | FDE: 0x0e7fe0 | Size: 256 bytes
// Khung tháo gỡ #0974 | Địa chỉ PC: 0x2465fc | Địa chỉ FDE: 0x0e7fe0 | Kích thước: 256 bytes
//   0x2465fc: F9400028  ldr      x8, [x1]
//   0x246600: B4000088  cbz      x8, #0x246610
//   0x246604: 3943A909  ldrb     w9, [x8, #0xea]
//   0x246608: 34000049  cbz      w9, #0x246610
static inline uint64_t fde_func_0974_0x2465fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2465fcULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0xb4000088ULL) ^ 0x0e7fe0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0975 | PC: 0x246da4 | FDE: 0x0e8110 | Size: 256 bytes
// Khung tháo gỡ #0975 | Địa chỉ PC: 0x246da4 | Địa chỉ FDE: 0x0e8110 | Kích thước: 256 bytes
//   0x246da4: B4000040  cbz      x0, #0x246dac
//   0x246da8: 17FE6A0B  b        #0x1e15d4
//   0x246dac: D65F03C0  ret      
//   0x246db0: D10243FF  sub      sp, sp, #0x90
static inline uint64_t fde_func_0975_0x246da4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x246da4ULL ^ (static_cast<uint64_t>(0xb4000040ULL) << 13);
    acc = (acc + a1 + 0x17fe6a0bULL) ^ 0x0e8110ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0976 | PC: 0x2477ac | FDE: 0x0e8260 | Size: 256 bytes
// Khung tháo gỡ #0976 | Địa chỉ PC: 0x2477ac | Địa chỉ FDE: 0x0e8260 | Kích thước: 256 bytes
//   0x2477ac: D10283FF  sub      sp, sp, #0xa0
//   0x2477b0: F9003BF6  str      x22, [sp, #0x70]
//   0x2477b4: A90853F5  stp      x21, x20, [sp, #0x80]
//   0x2477b8: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_0976_0x2477ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2477acULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf6ULL) ^ 0x0e8260ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0977 | PC: 0x2486bc | FDE: 0x0e83c8 | Size: 256 bytes
// Khung tháo gỡ #0977 | Địa chỉ PC: 0x2486bc | Địa chỉ FDE: 0x0e83c8 | Kích thước: 256 bytes
//   0x2486bc: D10183FF  sub      sp, sp, #0x60
//   0x2486c0: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x2486c4: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x2486c8: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0977_0x2486bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2486bcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9035bf7ULL) ^ 0x0e83c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0978 | PC: 0x2495ac | FDE: 0x0e8520 | Size: 256 bytes
// Khung tháo gỡ #0978 | Địa chỉ PC: 0x2495ac | Địa chỉ FDE: 0x0e8520 | Kích thước: 256 bytes
//   0x2495ac: F0000848  adrp     x8, #0x354000
//   0x2495b0: 912F8108  add      x8, x8, #0xbe0
//   0x2495b4: 14034EA5  b        #0x31d048
//   0x2495b8: D101C3FF  sub      sp, sp, #0x70
static inline uint64_t fde_func_0978_0x2495ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2495acULL ^ (static_cast<uint64_t>(0xf0000848ULL) << 13);
    acc = (acc + a1 + 0x912f8108ULL) ^ 0x0e8520ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0979 | PC: 0x249784 | FDE: 0x0e85b0 | Size: 176 bytes [_ZN4lynx4tasm6Config8InstanceEv]
// Khung tháo gỡ #0979 | Địa chỉ PC: 0x249784 | Địa chỉ FDE: 0x0e85b0 | Kích thước: 176 bytes
//   0x249784: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x249788: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x24978c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x249790: D0000908  adrp     x8, #0x36b000
static inline uint64_t fde_func_0979_0x249784(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x249784ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0e85b0ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #0980 | PC: 0x249834 | FDE: 0x0e85d0 | Size: 256 bytes [_ZN4lynx4tasm6Config17InitializeVersionERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE]
// Khung tháo gỡ #0980 | Địa chỉ PC: 0x249834 | Địa chỉ FDE: 0x0e85d0 | Kích thước: 256 bytes
//   0x249834: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x249838: AA0003F3  mov      x19, x0
//   0x24983c: 9403DDE5  bl       #0x340fd0
//   0x249840: 91002000  add      x0, x0, #8
static inline uint64_t fde_func_0980_0x249834(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x249834ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0e85d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0981 | PC: 0x249ac4 | FDE: 0x0e8650 | Size: 256 bytes
// Khung tháo gỡ #0981 | Địa chỉ PC: 0x249ac4 | Địa chỉ FDE: 0x0e8650 | Kích thước: 256 bytes
//   0x249ac4: AA1E03E5  mov      x5, x30
//   0x249ac8: 940355C9  bl       #0x31f1ec
//   0x249acc: AA0503FE  mov      x30, x5
//   0x249ad0: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_0981_0x249ac4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x249ac4ULL ^ (static_cast<uint64_t>(0xaa1e03e5ULL) << 13);
    acc = (acc + a1 + 0x940355c9ULL) ^ 0x0e8650ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0982 | PC: 0x24a0c0 | FDE: 0x0e8788 | Size: 256 bytes
// Khung tháo gỡ #0982 | Địa chỉ PC: 0x24a0c0 | Địa chỉ FDE: 0x0e8788 | Kích thước: 256 bytes
//   0x24a0c0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x24a0c4: AA0003F3  mov      x19, x0
//   0x24a0c8: 97FFFFF6  bl       #0x24a0a0
//   0x24a0cc: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0982_0x24a0c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x24a0c0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0e8788ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0983 | PC: 0x24a668 | FDE: 0x0e88a8 | Size: 256 bytes
// Khung tháo gỡ #0983 | Địa chỉ PC: 0x24a668 | Địa chỉ FDE: 0x0e88a8 | Kích thước: 256 bytes
//   0x24a668: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x24a66c: D0000848  adrp     x8, #0x354000
//   0x24a670: 9139A108  add      x8, x8, #0xe68
//   0x24a674: 940392FA  bl       #0x32f25c
static inline uint64_t fde_func_0983_0x24a668(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x24a668ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xd0000848ULL) ^ 0x0e88a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0984 | PC: 0x24aa34 | FDE: 0x0e89b8 | Size: 256 bytes
// Khung tháo gỡ #0984 | Địa chỉ PC: 0x24aa34 | Địa chỉ FDE: 0x0e89b8 | Kích thước: 256 bytes
//   0x24aa34: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x24aa38: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x24aa3c: F9429808  ldr      x8, [x0, #0x530]
//   0x24aa40: F9400D08  ldr      x8, [x8, #0x18]
static inline uint64_t fde_func_0984_0x24aa34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x24aa34ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0e89b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0985 | PC: 0x24b074 | FDE: 0x0e8ac8 | Size: 256 bytes
// Khung tháo gỡ #0985 | Địa chỉ PC: 0x24b074 | Địa chỉ FDE: 0x0e8ac8 | Kích thước: 256 bytes
//   0x24b074: 9108C000  add      x0, x0, #0x230
//   0x24b078: D65F03C0  ret      
//   0x24b07c: D10243FF  sub      sp, sp, #0x90
//   0x24b080: A9065BF7  stp      x23, x22, [sp, #0x60]
static inline uint64_t fde_func_0985_0x24b074(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x24b074ULL ^ (static_cast<uint64_t>(0x9108c000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0e8ac8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0986 | PC: 0x24b1e0 | FDE: 0x0e8bc8 | Size: 80 bytes
// Khung tháo gỡ #0986 | Địa chỉ PC: 0x24b1e0 | Địa chỉ FDE: 0x0e8bc8 | Kích thước: 80 bytes
//   0x24b1e0: D101E000  sub      x0, x0, #0x78
//   0x24b1e4: 17FFFE85  b        #0x24abf8
//   0x24b1e8: 9103A000  add      x0, x0, #0xe8
//   0x24b1ec: D65F03C0  ret      
static inline uint64_t fde_func_0986_0x24b1e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x24b1e0ULL ^ (static_cast<uint64_t>(0xd101e000ULL) << 13);
    acc = (acc + a1 + 0x17fffe85ULL) ^ 0x0e8bc8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0987 | PC: 0x24b230 | FDE: 0x0e8cb8 | Size: 256 bytes
// Khung tháo gỡ #0987 | Địa chỉ PC: 0x24b230 | Địa chỉ FDE: 0x0e8cb8 | Kích thước: 256 bytes
//   0x24b230: D1022000  sub      x0, x0, #0x88
//   0x24b234: 17FFFF92  b        #0x24b07c
//   0x24b238: D1022000  sub      x0, x0, #0x88
//   0x24b23c: 17FFFE12  b        #0x24aa84
static inline uint64_t fde_func_0987_0x24b230(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x24b230ULL ^ (static_cast<uint64_t>(0xd1022000ULL) << 13);
    acc = (acc + a1 + 0x17ffff92ULL) ^ 0x0e8cb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0988 | PC: 0x24b43c | FDE: 0x0e8dc0 | Size: 256 bytes
// Khung tháo gỡ #0988 | Địa chỉ PC: 0x24b43c | Địa chỉ FDE: 0x0e8dc0 | Kích thước: 256 bytes
//   0x24b43c: D10143FF  sub      sp, sp, #0x50
//   0x24b440: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x24b444: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x24b448: 9403D2FD  bl       #0x34003c
static inline uint64_t fde_func_0988_0x24b43c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x24b43cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90353f5ULL) ^ 0x0e8dc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0989 | PC: 0x24b738 | FDE: 0x0e8ee0 | Size: 256 bytes
// Khung tháo gỡ #0989 | Địa chỉ PC: 0x24b738 | Địa chỉ FDE: 0x0e8ee0 | Kích thước: 256 bytes
//   0x24b738: AA1E03E4  mov      x4, x30
//   0x24b73c: 94037584  bl       #0x328d4c
//   0x24b740: AA0403FE  mov      x30, x4
//   0x24b744: A90D7BF3  stp      x19, x30, [sp, #0xd0]
static inline uint64_t fde_func_0989_0x24b738(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x24b738ULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x94037584ULL) ^ 0x0e8ee0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0990 | PC: 0x24bb78 | FDE: 0x0e8fe0 | Size: 104 bytes [_ZN4lynx4tasm17TemplateAssembler16SetLepusObserverERKNSt6__ndk110shared_ptrINS_5lepus22InspectorLepusObserverEEE]
// Khung tháo gỡ #0990 | Địa chỉ PC: 0x24bb78 | Địa chỉ FDE: 0x0e8fe0 | Kích thước: 104 bytes
//   0x24bb78: D100C3FF  sub      sp, sp, #0x30
//   0x24bb7c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x24bb80: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x24bb84: A9402428  ldp      x8, x9, [x1]
static inline uint64_t fde_func_0990_0x24bb78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x24bb78ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0e8fe0ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0991 | PC: 0x24bbe0 | FDE: 0x0e9018 | Size: 256 bytes
// Khung tháo gỡ #0991 | Địa chỉ PC: 0x24bbe0 | Địa chỉ FDE: 0x0e9018 | Kích thước: 256 bytes
//   0x24bbe0: AA1E03E2  mov      x2, x30
//   0x24bbe4: 940352BC  bl       #0x3206d4
//   0x24bbe8: AA0203FE  mov      x30, x2
//   0x24bbec: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0991_0x24bbe0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x24bbe0ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x940352bcULL) ^ 0x0e9018ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0992 | PC: 0x24bf5c | FDE: 0x0e9138 | Size: 256 bytes
// Khung tháo gỡ #0992 | Địa chỉ PC: 0x24bf5c | Địa chỉ FDE: 0x0e9138 | Kích thước: 256 bytes
//   0x24bf5c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x24bf60: 9403B145  bl       #0x338474
//   0x24bf64: 9403D19B  bl       #0x3405d0
//   0x24bf68: 91030260  add      x0, x19, #0xc0
static inline uint64_t fde_func_0992_0x24bf5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x24bf5cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9403b145ULL) ^ 0x0e9138ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0993 | PC: 0x24cae0 | FDE: 0x0e9278 | Size: 256 bytes
// Khung tháo gỡ #0993 | Địa chỉ PC: 0x24cae0 | Địa chỉ FDE: 0x0e9278 | Kích thước: 256 bytes
//   0x24cae0: F9414808  ldr      x8, [x0, #0x290]
//   0x24cae4: B4000148  cbz      x8, #0x24cb0c
//   0x24cae8: 39496908  ldrb     w8, [x8, #0x25a]
//   0x24caec: 51000D08  sub      w8, w8, #3
static inline uint64_t fde_func_0993_0x24cae0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x24cae0ULL ^ (static_cast<uint64_t>(0xf9414808ULL) << 13);
    acc = (acc + a1 + 0xb4000148ULL) ^ 0x0e9278ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0994 | PC: 0x24e604 | FDE: 0x0e93e0 | Size: 256 bytes
// Khung tháo gỡ #0994 | Địa chỉ PC: 0x24e604 | Địa chỉ FDE: 0x0e93e0 | Kích thước: 256 bytes
//   0x24e604: D0000828  adrp     x8, #0x354000
//   0x24e608: 913EA108  add      x8, x8, #0xfa8
//   0x24e60c: F8010408  str      x8, [x0], #0x10
//   0x24e610: 17FE75AB  b        #0x1ebcbc
static inline uint64_t fde_func_0994_0x24e604(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x24e604ULL ^ (static_cast<uint64_t>(0xd0000828ULL) << 13);
    acc = (acc + a1 + 0x913ea108ULL) ^ 0x0e93e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0995 | PC: 0x24eafc | FDE: 0x0e9520 | Size: 256 bytes
// Khung tháo gỡ #0995 | Địa chỉ PC: 0x24eafc | Địa chỉ FDE: 0x0e9520 | Kích thước: 256 bytes
//   0x24eafc: D10283FF  sub      sp, sp, #0xa0
//   0x24eb00: A9075BF7  stp      x23, x22, [sp, #0x70]
//   0x24eb04: A90853F5  stp      x21, x20, [sp, #0x80]
//   0x24eb08: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_0995_0x24eafc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x24eafcULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9075bf7ULL) ^ 0x0e9520ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0996 | PC: 0x24f618 | FDE: 0x0e9678 | Size: 256 bytes
// Khung tháo gỡ #0996 | Địa chỉ PC: 0x24f618 | Địa chỉ FDE: 0x0e9678 | Kích thước: 256 bytes
//   0x24f618: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x24f61c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x24f620: 940373AA  bl       #0x32c4c8
//   0x24f624: 94035507  bl       #0x324a40
static inline uint64_t fde_func_0996_0x24f618(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x24f618ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0e9678ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0997 | PC: 0x24fa24 | FDE: 0x0e97b0 | Size: 256 bytes
// Khung tháo gỡ #0997 | Địa chỉ PC: 0x24fa24 | Địa chỉ FDE: 0x0e97b0 | Kích thước: 256 bytes
//   0x24fa24: D105C3FF  sub      sp, sp, #0x170
//   0x24fa28: F9008BFC  str      x28, [sp, #0x110]
//   0x24fa2c: A9126BFB  stp      x27, x26, [sp, #0x120]
//   0x24fa30: A91363F9  stp      x25, x24, [sp, #0x130]
static inline uint64_t fde_func_0997_0x24fa24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x24fa24ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xf9008bfcULL) ^ 0x0e97b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0998 | PC: 0x24fe04 | FDE: 0x0e98c0 | Size: 256 bytes
// Khung tháo gỡ #0998 | Địa chỉ PC: 0x24fe04 | Địa chỉ FDE: 0x0e98c0 | Kích thước: 256 bytes
//   0x24fe04: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x24fe08: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x24fe0c: 39556C08  ldrb     w8, [x0, #0x55b]
//   0x24fe10: 34000168  cbz      w8, #0x24fe3c
static inline uint64_t fde_func_0998_0x24fe04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x24fe04ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0e98c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0999 | PC: 0x2502b8 | FDE: 0x0e9a08 | Size: 256 bytes
// Khung tháo gỡ #0999 | Địa chỉ PC: 0x2502b8 | Địa chỉ FDE: 0x0e9a08 | Kích thước: 256 bytes
//   0x2502b8: D10703FF  sub      sp, sp, #0x1c0
//   0x2502bc: A9166FFC  stp      x28, x27, [sp, #0x160]
//   0x2502c0: A91767FA  stp      x26, x25, [sp, #0x170]
//   0x2502c4: A9185FF8  stp      x24, x23, [sp, #0x180]
static inline uint64_t fde_func_0999_0x2502b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2502b8ULL ^ (static_cast<uint64_t>(0xd10703ffULL) << 13);
    acc = (acc + a1 + 0xa9166ffcULL) ^ 0x0e9a08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1000 | PC: 0x250d78 | FDE: 0x0e9b70 | Size: 256 bytes
// Khung tháo gỡ #1000 | Địa chỉ PC: 0x250d78 | Địa chỉ FDE: 0x0e9b70 | Kích thước: 256 bytes
//   0x250d78: B40000C0  cbz      x0, #0x250d90
//   0x250d7c: BD411800  ldr      s0, [x0, #0x118]
//   0x250d80: FD409001  ldr      d1, [x0, #0x120]
//   0x250d84: 1E22C000  fcvt     d0, s0
static inline uint64_t fde_func_1000_0x250d78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x250d78ULL ^ (static_cast<uint64_t>(0xb40000c0ULL) << 13);
    acc = (acc + a1 + 0xbd411800ULL) ^ 0x0e9b70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1001 | PC: 0x2516a4 | FDE: 0x0e9cc0 | Size: 256 bytes
// Khung tháo gỡ #1001 | Địa chỉ PC: 0x2516a4 | Địa chỉ FDE: 0x0e9cc0 | Kích thước: 256 bytes
//   0x2516a4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2516a8: 94032C5C  bl       #0x31c818
//   0x2516ac: B4000173  cbz      x19, #0x2516d8
//   0x2516b0: F9406E60  ldr      x0, [x19, #0xd8]
static inline uint64_t fde_func_1001_0x2516a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2516a4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94032c5cULL) ^ 0x0e9cc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1002 | PC: 0x251fa8 | FDE: 0x0e9e20 | Size: 256 bytes
// Khung tháo gỡ #1002 | Địa chỉ PC: 0x251fa8 | Địa chỉ FDE: 0x0e9e20 | Kích thước: 256 bytes
//   0x251fa8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x251fac: 910DE000  add      x0, x0, #0x378
//   0x251fb0: AA0203F3  mov      x19, x2
//   0x251fb4: 97FE23A2  bl       #0x1dae3c
static inline uint64_t fde_func_1002_0x251fa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x251fa8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x910de000ULL) ^ 0x0e9e20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1003 | PC: 0x2523f4 | FDE: 0x0e9f48 | Size: 256 bytes
// Khung tháo gỡ #1003 | Địa chỉ PC: 0x2523f4 | Địa chỉ FDE: 0x0e9f48 | Kích thước: 256 bytes
//   0x2523f4: F81D0FFC  str      x28, [sp, #-0x30]!
//   0x2523f8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x2523fc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x252400: D10F83FF  sub      sp, sp, #0x3e0
static inline uint64_t fde_func_1003_0x2523f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2523f4ULL ^ (static_cast<uint64_t>(0xf81d0ffcULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0e9f48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1004 | PC: 0x252840 | FDE: 0x0ea070 | Size: 256 bytes
// Khung tháo gỡ #1004 | Địa chỉ PC: 0x252840 | Địa chỉ FDE: 0x0ea070 | Kích thước: 256 bytes
//   0x252840: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x252844: AA0003F3  mov      x19, x0
//   0x252848: 97FFFFF6  bl       #0x252820
//   0x25284c: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1004_0x252840(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x252840ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0ea070ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1005 | PC: 0x252ab8 | FDE: 0x0ea178 | Size: 256 bytes
// Khung tháo gỡ #1005 | Địa chỉ PC: 0x252ab8 | Địa chỉ FDE: 0x0ea178 | Kích thước: 256 bytes
//   0x252ab8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x252abc: AA0003F3  mov      x19, x0
//   0x252ac0: 97FFFFC9  bl       #0x2529e4
//   0x252ac4: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1005_0x252ab8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x252ab8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0ea178ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1006 | PC: 0x252e54 | FDE: 0x0ea280 | Size: 256 bytes
// Khung tháo gỡ #1006 | Địa chỉ PC: 0x252e54 | Địa chỉ FDE: 0x0ea280 | Kích thước: 256 bytes
//   0x252e54: D10143FF  sub      sp, sp, #0x50
//   0x252e58: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x252e5c: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x252e60: 94033171  bl       #0x31f424
static inline uint64_t fde_func_1006_0x252e54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x252e54ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90353f5ULL) ^ 0x0ea280ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1007 | PC: 0x25399c | FDE: 0x0ea3c8 | Size: 256 bytes
// Khung tháo gỡ #1007 | Địa chỉ PC: 0x25399c | Địa chỉ FDE: 0x0ea3c8 | Kích thước: 256 bytes
//   0x25399c: 72001C08  ands     w8, w0, #0xff
//   0x2539a0: 54000080  b.eq     #0x2539b0
//   0x2539a4: 7100091F  cmp      w8, #2
//   0x2539a8: 54000060  b.eq     #0x2539b4
static inline uint64_t fde_func_1007_0x25399c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x25399cULL ^ (static_cast<uint64_t>(0x72001c08ULL) << 13);
    acc = (acc + a1 + 0x54000080ULL) ^ 0x0ea3c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1008 | PC: 0x2543a8 | FDE: 0x0ea510 | Size: 256 bytes
// Khung tháo gỡ #1008 | Địa chỉ PC: 0x2543a8 | Địa chỉ FDE: 0x0ea510 | Kích thước: 256 bytes
//   0x2543a8: AA1E03E2  mov      x2, x30
//   0x2543ac: 940322C4  bl       #0x31cebc
//   0x2543b0: AA0203FE  mov      x30, x2
//   0x2543b4: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_1008_0x2543a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2543a8ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x940322c4ULL) ^ 0x0ea510ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1009 | PC: 0x254890 | FDE: 0x0ea640 | Size: 256 bytes
// Khung tháo gỡ #1009 | Địa chỉ PC: 0x254890 | Địa chỉ FDE: 0x0ea640 | Kích thước: 256 bytes
//   0x254890: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x254894: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x254898: 94032F7E  bl       #0x320690
//   0x25489c: B40000D4  cbz      x20, #0x2548b4
static inline uint64_t fde_func_1009_0x254890(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x254890ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0ea640ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1010 | PC: 0x254bb4 | FDE: 0x0ea760 | Size: 256 bytes
// Khung tháo gỡ #1010 | Địa chỉ PC: 0x254bb4 | Địa chỉ FDE: 0x0ea760 | Kích thước: 256 bytes
//   0x254bb4: AA1E03E3  mov      x3, x30
//   0x254bb8: 9403476C  bl       #0x326968
//   0x254bbc: AA0303FE  mov      x30, x3
//   0x254bc0: A90B7BF3  stp      x19, x30, [sp, #0xb0]
static inline uint64_t fde_func_1010_0x254bb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x254bb4ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x9403476cULL) ^ 0x0ea760ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1011 | PC: 0x2556b8 | FDE: 0x0ea8b8 | Size: 256 bytes
// Khung tháo gỡ #1011 | Địa chỉ PC: 0x2556b8 | Địa chỉ FDE: 0x0ea8b8 | Kích thước: 256 bytes
//   0x2556b8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2556bc: AA0003F3  mov      x19, x0
//   0x2556c0: 97FFFFF6  bl       #0x255698
//   0x2556c4: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1011_0x2556b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2556b8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0ea8b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1012 | PC: 0x255b6c | FDE: 0x0ea9e0 | Size: 256 bytes
// Khung tháo gỡ #1012 | Địa chỉ PC: 0x255b6c | Địa chỉ FDE: 0x0ea9e0 | Kích thước: 256 bytes
//   0x255b6c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x255b70: AA0003F3  mov      x19, x0
//   0x255b74: 97FFD680  bl       #0x24b574
//   0x255b78: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1012_0x255b6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x255b6cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0ea9e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1013 | PC: 0x255e78 | FDE: 0x0eaaf8 | Size: 256 bytes
// Khung tháo gỡ #1013 | Địa chỉ PC: 0x255e78 | Địa chỉ FDE: 0x0eaaf8 | Kích thước: 256 bytes
//   0x255e78: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x255e7c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x255e80: B4000160  cbz      x0, #0x255eac
//   0x255e84: 94036EAB  bl       #0x331930
static inline uint64_t fde_func_1013_0x255e78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x255e78ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0eaaf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1014 | PC: 0x2562e8 | FDE: 0x0eac28 | Size: 256 bytes
// Khung tháo gỡ #1014 | Địa chỉ PC: 0x2562e8 | Địa chỉ FDE: 0x0eac28 | Kích thước: 256 bytes
//   0x2562e8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2562ec: 940318FD  bl       #0x31c6e0
//   0x2562f0: 97FC209A  bl       #0x15e558
//   0x2562f4: F9400660  ldr      x0, [x19, #8]
static inline uint64_t fde_func_1014_0x2562e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2562e8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x940318fdULL) ^ 0x0eac28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1015 | PC: 0x2565f4 | FDE: 0x0ead40 | Size: 256 bytes
// Khung tháo gỡ #1015 | Địa chỉ PC: 0x2565f4 | Địa chỉ FDE: 0x0ead40 | Kích thước: 256 bytes
//   0x2565f4: F81C0FFC  str      x28, [sp, #-0x40]!
//   0x2565f8: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x2565fc: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x256600: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1015_0x2565f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2565f4ULL ^ (static_cast<uint64_t>(0xf81c0ffcULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0ead40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1016 | PC: 0x256bac | FDE: 0x0eae70 | Size: 256 bytes
// Khung tháo gỡ #1016 | Địa chỉ PC: 0x256bac | Địa chỉ FDE: 0x0eae70 | Kích thước: 256 bytes
//   0x256bac: F00007E8  adrp     x8, #0x355000
//   0x256bb0: 9111C108  add      x8, x8, #0x470
//   0x256bb4: F8008408  str      x8, [x0], #8
//   0x256bb8: 17FFFF9E  b        #0x256a30
static inline uint64_t fde_func_1016_0x256bac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x256bacULL ^ (static_cast<uint64_t>(0xf00007e8ULL) << 13);
    acc = (acc + a1 + 0x9111c108ULL) ^ 0x0eae70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1017 | PC: 0x257744 | FDE: 0x0eaf88 | Size: 256 bytes
// Khung tháo gỡ #1017 | Địa chỉ PC: 0x257744 | Địa chỉ FDE: 0x0eaf88 | Kích thước: 256 bytes
//   0x257744: AA1E03E3  mov      x3, x30
//   0x257748: 94031EAF  bl       #0x31f204
//   0x25774c: AA0303FE  mov      x30, x3
//   0x257750: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_1017_0x257744(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x257744ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94031eafULL) ^ 0x0eaf88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1018 | PC: 0x257bc8 | FDE: 0x0eb0b8 | Size: 256 bytes
// Khung tháo gỡ #1018 | Địa chỉ PC: 0x257bc8 | Địa chỉ FDE: 0x0eb0b8 | Kích thước: 256 bytes
//   0x257bc8: D10203FF  sub      sp, sp, #0x80
//   0x257bcc: F9002BF6  str      x22, [sp, #0x50]
//   0x257bd0: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x257bd4: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1018_0x257bc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x257bc8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf6ULL) ^ 0x0eb0b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1019 | PC: 0x258260 | FDE: 0x0eb1e0 | Size: 256 bytes
// Khung tháo gỡ #1019 | Địa chỉ PC: 0x258260 | Địa chỉ FDE: 0x0eb1e0 | Kích thước: 256 bytes
//   0x258260: F9400408  ldr      x8, [x0, #8]
//   0x258264: 91006001  add      x1, x0, #0x18
//   0x258268: AA0803E0  mov      x0, x8
//   0x25826c: 17FFFFA4  b        #0x2580fc
static inline uint64_t fde_func_1019_0x258260(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x258260ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x91006001ULL) ^ 0x0eb1e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1020 | PC: 0x258810 | FDE: 0x0eb310 | Size: 256 bytes
// Khung tháo gỡ #1020 | Địa chỉ PC: 0x258810 | Địa chỉ FDE: 0x0eb310 | Kích thước: 256 bytes
//   0x258810: B00007E8  adrp     x8, #0x355000
//   0x258814: 9115E108  add      x8, x8, #0x578
//   0x258818: F8008408  str      x8, [x0], #8
//   0x25881c: 17FFFFF7  b        #0x2587f8
static inline uint64_t fde_func_1020_0x258810(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x258810ULL ^ (static_cast<uint64_t>(0xb00007e8ULL) << 13);
    acc = (acc + a1 + 0x9115e108ULL) ^ 0x0eb310ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1021 | PC: 0x258ef8 | FDE: 0x0eb438 | Size: 256 bytes
// Khung tháo gỡ #1021 | Địa chỉ PC: 0x258ef8 | Địa chỉ FDE: 0x0eb438 | Kích thước: 256 bytes
//   0x258ef8: AA1E03E3  mov      x3, x30
//   0x258efc: 940324A8  bl       #0x32219c
//   0x258f00: AA0303FE  mov      x30, x3
//   0x258f04: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_1021_0x258ef8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x258ef8ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x940324a8ULL) ^ 0x0eb438ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1022 | PC: 0x25959c | FDE: 0x0eb560 | Size: 256 bytes
// Khung tháo gỡ #1022 | Địa chỉ PC: 0x25959c | Địa chỉ FDE: 0x0eb560 | Kích thước: 256 bytes
//   0x25959c: AA1E03E2  mov      x2, x30
//   0x2595a0: 94031EE0  bl       #0x321120
//   0x2595a4: AA0203FE  mov      x30, x2
//   0x2595a8: A90B7BF3  stp      x19, x30, [sp, #0xb0]
static inline uint64_t fde_func_1022_0x25959c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x25959cULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94031ee0ULL) ^ 0x0eb560ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1023 | PC: 0x259960 | FDE: 0x0eb6a0 | Size: 256 bytes
// Khung tháo gỡ #1023 | Địa chỉ PC: 0x259960 | Địa chỉ FDE: 0x0eb6a0 | Kích thước: 256 bytes
//   0x259960: AA1E03E8  mov      x8, x30
//   0x259964: 94030969  bl       #0x31bf08
//   0x259968: AA0803FE  mov      x30, x8
//   0x25996c: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1023_0x259960(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x259960ULL ^ (static_cast<uint64_t>(0xaa1e03e8ULL) << 13);
    acc = (acc + a1 + 0x94030969ULL) ^ 0x0eb6a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1024 | PC: 0x25a1a0 | FDE: 0x0eb7f0 | Size: 256 bytes
// Khung tháo gỡ #1024 | Địa chỉ PC: 0x25a1a0 | Địa chỉ FDE: 0x0eb7f0 | Kích thước: 256 bytes
//   0x25a1a0: D10083FF  sub      sp, sp, #0x20
//   0x25a1a4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x25a1a8: B0000888  adrp     x8, #0x36b000
//   0x25a1ac: 9113E108  add      x8, x8, #0x4f8
static inline uint64_t fde_func_1024_0x25a1a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x25a1a0ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0eb7f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1025 | PC: 0x25a598 | FDE: 0x0eb910 | Size: 256 bytes
// Khung tháo gỡ #1025 | Địa chỉ PC: 0x25a598 | Địa chỉ FDE: 0x0eb910 | Kích thước: 256 bytes
//   0x25a598: D10143FF  sub      sp, sp, #0x50
//   0x25a59c: F90013F6  str      x22, [sp, #0x20]
//   0x25a5a0: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x25a5a4: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1025_0x25a598(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x25a598ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x0eb910ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1026 | PC: 0x25a998 | FDE: 0x0eba38 | Size: 256 bytes
// Khung tháo gỡ #1026 | Địa chỉ PC: 0x25a998 | Địa chỉ FDE: 0x0eba38 | Kích thước: 256 bytes
//   0x25a998: AA1E03E3  mov      x3, x30
//   0x25a99c: 94031048  bl       #0x31eabc
//   0x25a9a0: AA0303FE  mov      x30, x3
//   0x25a9a4: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1026_0x25a998(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x25a998ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94031048ULL) ^ 0x0eba38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1027 | PC: 0x25aac4 | FDE: 0x0ebaf0 | Size: 124 bytes [_ZN4lynx5piper10JSExecutor12GetJSRuntimeEv]
// Khung tháo gỡ #1027 | Địa chỉ PC: 0x25aac4 | Địa chỉ FDE: 0x0ebaf0 | Kích thước: 124 bytes
//   0x25aac4: F9402809  ldr      x9, [x0, #0x50]
//   0x25aac8: F9000109  str      x9, [x8]
//   0x25aacc: F9402C09  ldr      x9, [x0, #0x58]
//   0x25aad0: F9000509  str      x9, [x8, #8]
static inline uint64_t fde_func_1027_0x25aac4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x25aac4ULL ^ (static_cast<uint64_t>(0xf9402809ULL) << 13);
    acc = (acc + a1 + 0xf9000109ULL) ^ 0x0ebaf0ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1028 | PC: 0x25ab40 | FDE: 0x0ebb40 | Size: 256 bytes
// Khung tháo gỡ #1028 | Địa chỉ PC: 0x25ab40 | Địa chỉ FDE: 0x0ebb40 | Kích thước: 256 bytes
//   0x25ab40: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x25ab44: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x25ab48: F00007E8  adrp     x8, #0x359000
//   0x25ab4c: 9129C108  add      x8, x8, #0xa70
static inline uint64_t fde_func_1028_0x25ab40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x25ab40ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0ebb40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1029 | PC: 0x25b078 | FDE: 0x0ebc68 | Size: 256 bytes
// Khung tháo gỡ #1029 | Địa chỉ PC: 0x25b078 | Địa chỉ FDE: 0x0ebc68 | Kích thước: 256 bytes
//   0x25b078: D10183FF  sub      sp, sp, #0x60
//   0x25b07c: F9001BF6  str      x22, [sp, #0x30]
//   0x25b080: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x25b084: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1029_0x25b078(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x25b078ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf6ULL) ^ 0x0ebc68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1030 | PC: 0x25ba50 | FDE: 0x0ebd88 | Size: 256 bytes
// Khung tháo gỡ #1030 | Địa chỉ PC: 0x25ba50 | Địa chỉ FDE: 0x0ebd88 | Kích thước: 256 bytes
//   0x25ba50: D10103FF  sub      sp, sp, #0x40
//   0x25ba54: F9000BF6  str      x22, [sp, #0x10]
//   0x25ba58: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x25ba5c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1030_0x25ba50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x25ba50ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x0ebd88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1031 | PC: 0x25bc80 | FDE: 0x0ebe98 | Size: 256 bytes
// Khung tháo gỡ #1031 | Địa chỉ PC: 0x25bc80 | Địa chỉ FDE: 0x0ebe98 | Kích thước: 256 bytes
//   0x25bc80: B9401808  ldr      w8, [x0, #0x18]
//   0x25bc84: 140352A5  b        #0x330718
//   0x25bc88: B9401808  ldr      w8, [x0, #0x18]
//   0x25bc8c: 1403552F  b        #0x331148
static inline uint64_t fde_func_1031_0x25bc80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x25bc80ULL ^ (static_cast<uint64_t>(0xb9401808ULL) << 13);
    acc = (acc + a1 + 0x140352a5ULL) ^ 0x0ebe98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1032 | PC: 0x25be9c | FDE: 0x0ebfa8 | Size: 256 bytes
// Khung tháo gỡ #1032 | Địa chỉ PC: 0x25be9c | Địa chỉ FDE: 0x0ebfa8 | Kích thước: 256 bytes
//   0x25be9c: D10183FF  sub      sp, sp, #0x60
//   0x25bea0: F9001BF6  str      x22, [sp, #0x30]
//   0x25bea4: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x25bea8: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1032_0x25be9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x25be9cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf6ULL) ^ 0x0ebfa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1033 | PC: 0x25ca14 | FDE: 0x0ec0f0 | Size: 256 bytes
// Khung tháo gỡ #1033 | Địa chỉ PC: 0x25ca14 | Địa chỉ FDE: 0x0ec0f0 | Kích thước: 256 bytes
//   0x25ca14: D100C3FF  sub      sp, sp, #0x30
//   0x25ca18: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x25ca1c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x25ca20: 94031B9A  bl       #0x323888
static inline uint64_t fde_func_1033_0x25ca14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x25ca14ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0ec0f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1034 | PC: 0x25d298 | FDE: 0x0ec228 | Size: 256 bytes
// Khung tháo gỡ #1034 | Địa chỉ PC: 0x25d298 | Địa chỉ FDE: 0x0ec228 | Kích thước: 256 bytes
//   0x25d298: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x25d29c: 900007C8  adrp     x8, #0x355000
//   0x25d2a0: 912EE108  add      x8, x8, #0xbb8
//   0x25d2a4: 9402FD2F  bl       #0x31c760
static inline uint64_t fde_func_1034_0x25d298(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x25d298ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x900007c8ULL) ^ 0x0ec228ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1035 | PC: 0x25eee8 | FDE: 0x0ec358 | Size: 256 bytes
// Khung tháo gỡ #1035 | Địa chỉ PC: 0x25eee8 | Địa chỉ FDE: 0x0ec358 | Kích thước: 256 bytes
//   0x25eee8: D10143FF  sub      sp, sp, #0x50
//   0x25eeec: F90013F6  str      x22, [sp, #0x20]
//   0x25eef0: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x25eef4: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1035_0x25eee8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x25eee8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x0ec358ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1036 | PC: 0x25f20c | FDE: 0x0ec478 | Size: 256 bytes
// Khung tháo gỡ #1036 | Địa chỉ PC: 0x25f20c | Địa chỉ FDE: 0x0ec478 | Kích thước: 256 bytes
//   0x25f20c: D100C3FF  sub      sp, sp, #0x30
//   0x25f210: F9000BF4  str      x20, [sp, #0x10]
//   0x25f214: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x25f218: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1036_0x25f20c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x25f20cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x0ec478ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1037 | PC: 0x25f444 | FDE: 0x0ec590 | Size: 256 bytes
// Khung tháo gỡ #1037 | Địa chỉ PC: 0x25f444 | Địa chỉ FDE: 0x0ec590 | Kích thước: 256 bytes
//   0x25f444: D10143FF  sub      sp, sp, #0x50
//   0x25f448: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x25f44c: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x25f450: 940334D7  bl       #0x32c7ac
static inline uint64_t fde_func_1037_0x25f444(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x25f444ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90353f5ULL) ^ 0x0ec590ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1038 | PC: 0x25f7e8 | FDE: 0x0ec6b8 | Size: 256 bytes
// Khung tháo gỡ #1038 | Địa chỉ PC: 0x25f7e8 | Địa chỉ FDE: 0x0ec6b8 | Kích thước: 256 bytes
//   0x25f7e8: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x25f7ec: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x25f7f0: F9402014  ldr      x20, [x0, #0x40]
//   0x25f7f4: D00007A8  adrp     x8, #0x355000
static inline uint64_t fde_func_1038_0x25f7e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x25f7e8ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0ec6b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1039 | PC: 0x26109c | FDE: 0x0ec818 | Size: 256 bytes
// Khung tháo gỡ #1039 | Địa chỉ PC: 0x26109c | Địa chỉ FDE: 0x0ec818 | Kích thước: 256 bytes
//   0x26109c: D10183FF  sub      sp, sp, #0x60
//   0x2610a0: F9001BF6  str      x22, [sp, #0x30]
//   0x2610a4: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x2610a8: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1039_0x26109c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x26109cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf6ULL) ^ 0x0ec818ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1040 | PC: 0x26140c | FDE: 0x0ec938 | Size: 256 bytes
// Khung tháo gỡ #1040 | Địa chỉ PC: 0x26140c | Địa chỉ FDE: 0x0ec938 | Kích thước: 256 bytes
//   0x26140c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x261410: AA0003F3  mov      x19, x0
//   0x261414: 97FFFFFA  bl       #0x2613fc
//   0x261418: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1040_0x26140c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x26140cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0ec938ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1041 | PC: 0x2616dc | FDE: 0x0eca50 | Size: 256 bytes
// Khung tháo gỡ #1041 | Địa chỉ PC: 0x2616dc | Địa chỉ FDE: 0x0eca50 | Kích thước: 256 bytes
//   0x2616dc: 91008000  add      x0, x0, #0x20
//   0x2616e0: 14000001  b        #0x2616e4
//   0x2616e4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2616e8: 9403453F  bl       #0x332be4
static inline uint64_t fde_func_1041_0x2616dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2616dcULL ^ (static_cast<uint64_t>(0x91008000ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x0eca50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1042 | PC: 0x261f68 | FDE: 0x0ecb80 | Size: 256 bytes
// Khung tháo gỡ #1042 | Địa chỉ PC: 0x261f68 | Địa chỉ FDE: 0x0ecb80 | Kích thước: 256 bytes
//   0x261f68: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x261f6c: AA0003F3  mov      x19, x0
//   0x261f70: 97FFFFBF  bl       #0x261e6c
//   0x261f74: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1042_0x261f68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x261f68ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0ecb80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1043 | PC: 0x262a9c | FDE: 0x0eccb0 | Size: 256 bytes
// Khung tháo gỡ #1043 | Địa chỉ PC: 0x262a9c | Địa chỉ FDE: 0x0eccb0 | Kích thước: 256 bytes
//   0x262a9c: AA0003E9  mov      x9, x0
//   0x262aa0: 38418D28  ldrb     w8, [x9, #0x18]!
//   0x262aa4: 37000088  tbnz     w8, #0, #0x262ab4
//   0x262aa8: D341FD08  lsr      x8, x8, #1
static inline uint64_t fde_func_1043_0x262a9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x262a9cULL ^ (static_cast<uint64_t>(0xaa0003e9ULL) << 13);
    acc = (acc + a1 + 0x38418d28ULL) ^ 0x0eccb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1044 | PC: 0x262e00 | FDE: 0x0ecdc8 | Size: 256 bytes
// Khung tháo gỡ #1044 | Địa chỉ PC: 0x262e00 | Địa chỉ FDE: 0x0ecdc8 | Kích thước: 256 bytes
//   0x262e00: AA0103E0  mov      x0, x1
//   0x262e04: 14000001  b        #0x262e08
//   0x262e08: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x262e0c: 9402F0AE  bl       #0x31f0c4
static inline uint64_t fde_func_1044_0x262e00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x262e00ULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x0ecdc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1045 | PC: 0x2631a4 | FDE: 0x0eced8 | Size: 256 bytes
// Khung tháo gỡ #1045 | Địa chỉ PC: 0x2631a4 | Địa chỉ FDE: 0x0eced8 | Kích thước: 256 bytes
//   0x2631a4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2631a8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2631ac: 9402F6D5  bl       #0x320d00
//   0x2631b0: B4000088  cbz      x8, #0x2631c0
static inline uint64_t fde_func_1045_0x2631a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2631a4ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0eced8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1046 | PC: 0x263d0c | FDE: 0x0ed000 | Size: 256 bytes
// Khung tháo gỡ #1046 | Địa chỉ PC: 0x263d0c | Địa chỉ FDE: 0x0ed000 | Kích thước: 256 bytes
//   0x263d0c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x263d10: AA0003F3  mov      x19, x0
//   0x263d14: 97FFFFFA  bl       #0x263cfc
//   0x263d18: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1046_0x263d0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x263d0cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0ed000ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1047 | PC: 0x263e7c | FDE: 0x0ed0f8 | Size: 256 bytes
// Khung tháo gỡ #1047 | Địa chỉ PC: 0x263e7c | Địa chỉ FDE: 0x0ed0f8 | Kích thước: 256 bytes
//   0x263e7c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x263e80: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x263e84: F00007A8  adrp     x8, #0x35a000
//   0x263e88: 91338108  add      x8, x8, #0xce0
static inline uint64_t fde_func_1047_0x263e7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x263e7cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0ed0f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1048 | PC: 0x2642c4 | FDE: 0x0ed210 | Size: 156 bytes
// Khung tháo gỡ #1048 | Địa chỉ PC: 0x2642c4 | Địa chỉ FDE: 0x0ed210 | Kích thước: 156 bytes
//   0x2642c4: 91002009  add      x9, x0, #8
//   0x2642c8: 08DFFD29  ldarb    w9, [x9]
//   0x2642cc: 37000049  tbnz     w9, #0, #0x2642d4
//   0x2642d0: 17FBB989  b        #0x1528f4
static inline uint64_t fde_func_1048_0x2642c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2642c4ULL ^ (static_cast<uint64_t>(0x91002009ULL) << 13);
    acc = (acc + a1 + 0x08dffd29ULL) ^ 0x0ed210ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1049 | PC: 0x264360 | FDE: 0x0ed240 | Size: 200 bytes [_ZN4lynx7runtime29RegisterExternalRuntimeHelperEPNS0_17LynxRuntimeHelperE]
// Khung tháo gỡ #1049 | Địa chỉ PC: 0x264360 | Địa chỉ FDE: 0x0ed240 | Kích thước: 200 bytes
//   0x264360: D101C3FF  sub      sp, sp, #0x70
//   0x264364: F9002BF4  str      x20, [sp, #0x50]
//   0x264368: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x26436c: 9402E8D4  bl       #0x31e6bc
static inline uint64_t fde_func_1049_0x264360(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x264360ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x0ed240ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1050 | PC: 0x264428 | FDE: 0x0ed260 | Size: 256 bytes [_ZN4lynx7runtime28IsExternalRuntimeHelperValidEv]
// Khung tháo gỡ #1050 | Địa chỉ PC: 0x264428 | Địa chỉ FDE: 0x0ed260 | Kích thước: 256 bytes
//   0x264428: 90000808  adrp     x8, #0x364000
//   0x26442c: 910C0108  add      x8, x8, #0x300
//   0x264430: 08DFFD08  ldarb    w8, [x8]
//   0x264434: 12000100  and      w0, w8, #1
static inline uint64_t fde_func_1050_0x264428(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x264428ULL ^ (static_cast<uint64_t>(0x90000808ULL) << 13);
    acc = (acc + a1 + 0x910c0108ULL) ^ 0x0ed260ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1051 | PC: 0x265a98 | FDE: 0x0ed350 | Size: 256 bytes
// Khung tháo gỡ #1051 | Địa chỉ PC: 0x265a98 | Địa chỉ FDE: 0x0ed350 | Kích thước: 256 bytes
//   0x265a98: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x265a9c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x265aa0: 9402EA55  bl       #0x3203f4
//   0x265aa4: A9417BF3  ldp      x19, x30, [sp, #0x10]
static inline uint64_t fde_func_1051_0x265a98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x265a98ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0ed350ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1052 | PC: 0x266804 | FDE: 0x0ed490 | Size: 256 bytes
// Khung tháo gỡ #1052 | Địa chỉ PC: 0x266804 | Địa chỉ FDE: 0x0ed490 | Kích thước: 256 bytes
//   0x266804: F9400048  ldr      x8, [x2]
//   0x266808: F900005F  str      xzr, [x2]
//   0x26680c: 1402E44D  b        #0x31f940
//   0x266810: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_1052_0x266804(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x266804ULL ^ (static_cast<uint64_t>(0xf9400048ULL) << 13);
    acc = (acc + a1 + 0xf900005fULL) ^ 0x0ed490ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1053 | PC: 0x2669dc | FDE: 0x0ed5b0 | Size: 256 bytes
// Khung tháo gỡ #1053 | Địa chỉ PC: 0x2669dc | Địa chỉ FDE: 0x0ed5b0 | Kích thước: 256 bytes
//   0x2669dc: F9400000  ldr      x0, [x0]
//   0x2669e0: 17FC4D9A  b        #0x17a048
//   0x2669e4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2669e8: A9017BF3  stp      x19, x30, [sp, #0x10]
static inline uint64_t fde_func_1053_0x2669dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2669dcULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0x17fc4d9aULL) ^ 0x0ed5b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1054 | PC: 0x267464 | FDE: 0x0ed6e0 | Size: 256 bytes
// Khung tháo gỡ #1054 | Địa chỉ PC: 0x267464 | Địa chỉ FDE: 0x0ed6e0 | Kích thước: 256 bytes
//   0x267464: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x267468: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x26746c: D0000788  adrp     x8, #0x359000
//   0x267470: 9129C108  add      x8, x8, #0xa70
static inline uint64_t fde_func_1054_0x267464(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x267464ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0ed6e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1055 | PC: 0x267764 | FDE: 0x0ed800 | Size: 256 bytes
// Khung tháo gỡ #1055 | Địa chỉ PC: 0x267764 | Địa chỉ FDE: 0x0ed800 | Kích thước: 256 bytes
//   0x267764: AA1E03E2  mov      x2, x30
//   0x267768: 9402E66E  bl       #0x321120
//   0x26776c: AA0203FE  mov      x30, x2
//   0x267770: A90B7BF3  stp      x19, x30, [sp, #0xb0]
static inline uint64_t fde_func_1055_0x267764(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x267764ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9402e66eULL) ^ 0x0ed800ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1056 | PC: 0x267c98 | FDE: 0x0ed920 | Size: 256 bytes
// Khung tháo gỡ #1056 | Địa chỉ PC: 0x267c98 | Địa chỉ FDE: 0x0ed920 | Kích thước: 256 bytes
//   0x267c98: F9400808  ldr      x8, [x0, #0x10]
//   0x267c9c: F0000769  adrp     x9, #0x356000
//   0x267ca0: 910AE129  add      x9, x9, #0x2b8
//   0x267ca4: 140300B1  b        #0x327f68
static inline uint64_t fde_func_1056_0x267c98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x267c98ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xf0000769ULL) ^ 0x0ed920ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1057 | PC: 0x268358 | FDE: 0x0eda58 | Size: 256 bytes
// Khung tháo gỡ #1057 | Địa chỉ PC: 0x268358 | Địa chỉ FDE: 0x0eda58 | Kích thước: 256 bytes
//   0x268358: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x26835c: AA0003F3  mov      x19, x0
//   0x268360: 97FFFFF6  bl       #0x268338
//   0x268364: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1057_0x268358(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x268358ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0eda58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1058 | PC: 0x2697a4 | FDE: 0x0edbb0 | Size: 256 bytes
// Khung tháo gỡ #1058 | Địa chỉ PC: 0x2697a4 | Địa chỉ FDE: 0x0edbb0 | Kích thước: 256 bytes
//   0x2697a4: 39400008  ldrb     w8, [x0]
//   0x2697a8: 39400029  ldrb     w9, [x1]
//   0x2697ac: 6B09011F  cmp      w8, w9
//   0x2697b0: 54000221  b.ne     #0x2697f4
static inline uint64_t fde_func_1058_0x2697a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2697a4ULL ^ (static_cast<uint64_t>(0x39400008ULL) << 13);
    acc = (acc + a1 + 0x39400029ULL) ^ 0x0edbb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1059 | PC: 0x269f10 | FDE: 0x0edce8 | Size: 256 bytes
// Khung tháo gỡ #1059 | Địa chỉ PC: 0x269f10 | Địa chỉ FDE: 0x0edce8 | Kích thước: 256 bytes
//   0x269f10: F9400409  ldr      x9, [x0, #8]
//   0x269f14: AA0203E8  mov      x8, x2
//   0x269f18: CB030122  sub      x2, x9, x3
//   0x269f1c: 9342FC4A  asr      x10, x2, #2
static inline uint64_t fde_func_1059_0x269f10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x269f10ULL ^ (static_cast<uint64_t>(0xf9400409ULL) << 13);
    acc = (acc + a1 + 0xaa0203e8ULL) ^ 0x0edce8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1060 | PC: 0x26a228 | FDE: 0x0ede20 | Size: 256 bytes
// Khung tháo gỡ #1060 | Địa chỉ PC: 0x26a228 | Địa chỉ FDE: 0x0ede20 | Kích thước: 256 bytes
//   0x26a228: D10143FF  sub      sp, sp, #0x50
//   0x26a22c: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x26a230: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x26a234: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1060_0x26a228(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x26a228ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x0ede20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1061 | PC: 0x26addc | FDE: 0x0edf70 | Size: 256 bytes
// Khung tháo gỡ #1061 | Địa chỉ PC: 0x26addc | Địa chỉ FDE: 0x0edf70 | Kích thước: 256 bytes
//   0x26addc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x26ade0: AA0003F3  mov      x19, x0
//   0x26ade4: 97FFFFF6  bl       #0x26adbc
//   0x26ade8: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1061_0x26addc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x26addcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0edf70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1062 | PC: 0x26b044 | FDE: 0x0ee080 | Size: 256 bytes
// Khung tháo gỡ #1062 | Địa chỉ PC: 0x26b044 | Địa chỉ FDE: 0x0ee080 | Kích thước: 256 bytes
//   0x26b044: 91002000  add      x0, x0, #8
//   0x26b048: 17FC3E37  b        #0x17a924
//   0x26b04c: 91002001  add      x1, x0, #8
//   0x26b050: AA0803E0  mov      x0, x8
static inline uint64_t fde_func_1062_0x26b044(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x26b044ULL ^ (static_cast<uint64_t>(0x91002000ULL) << 13);
    acc = (acc + a1 + 0x17fc3e37ULL) ^ 0x0ee080ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1063 | PC: 0x26b770 | FDE: 0x0ee1b0 | Size: 256 bytes
// Khung tháo gỡ #1063 | Địa chỉ PC: 0x26b770 | Địa chỉ FDE: 0x0ee1b0 | Kích thước: 256 bytes
//   0x26b770: A9BD5BFC  stp      x28, x22, [sp, #-0x30]!
//   0x26b774: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x26b778: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x26b77c: D10743FF  sub      sp, sp, #0x1d0
static inline uint64_t fde_func_1063_0x26b770(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x26b770ULL ^ (static_cast<uint64_t>(0xa9bd5bfcULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0ee1b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1064 | PC: 0x26ced0 | FDE: 0x0ee2e8 | Size: 256 bytes
// Khung tháo gỡ #1064 | Địa chỉ PC: 0x26ced0 | Địa chỉ FDE: 0x0ee2e8 | Kích thước: 256 bytes
//   0x26ced0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x26ced4: AA0003F3  mov      x19, x0
//   0x26ced8: 97FFFFFA  bl       #0x26cec0
//   0x26cedc: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1064_0x26ced0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x26ced0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0ee2e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1065 | PC: 0x26d8e0 | FDE: 0x0ee420 | Size: 256 bytes
// Khung tháo gỡ #1065 | Địa chỉ PC: 0x26d8e0 | Địa chỉ FDE: 0x0ee420 | Kích thước: 256 bytes
//   0x26d8e0: D10283FF  sub      sp, sp, #0xa0
//   0x26d8e4: A9075BF7  stp      x23, x22, [sp, #0x70]
//   0x26d8e8: A90853F5  stp      x21, x20, [sp, #0x80]
//   0x26d8ec: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_1065_0x26d8e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x26d8e0ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9075bf7ULL) ^ 0x0ee420ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1066 | PC: 0x26e0b4 | FDE: 0x0ee550 | Size: 256 bytes
// Khung tháo gỡ #1066 | Địa chỉ PC: 0x26e0b4 | Địa chỉ FDE: 0x0ee550 | Kích thước: 256 bytes
//   0x26e0b4: AA1E03E2  mov      x2, x30
//   0x26e0b8: 9402C453  bl       #0x31f204
//   0x26e0bc: AA0203FE  mov      x30, x2
//   0x26e0c0: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_1066_0x26e0b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x26e0b4ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9402c453ULL) ^ 0x0ee550ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1067 | PC: 0x26ec74 | FDE: 0x0ee6a8 | Size: 256 bytes
// Khung tháo gỡ #1067 | Địa chỉ PC: 0x26ec74 | Địa chỉ FDE: 0x0ee6a8 | Kích thước: 256 bytes
//   0x26ec74: AA1E03E2  mov      x2, x30
//   0x26ec78: 9402D68E  bl       #0x3246b0
//   0x26ec7c: AA0203FE  mov      x30, x2
//   0x26ec80: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_1067_0x26ec74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x26ec74ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9402d68eULL) ^ 0x0ee6a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1068 | PC: 0x27021c | FDE: 0x0ee828 | Size: 256 bytes
// Khung tháo gỡ #1068 | Địa chỉ PC: 0x27021c | Địa chỉ FDE: 0x0ee828 | Kích thước: 256 bytes
//   0x27021c: AA1E03E2  mov      x2, x30
//   0x270220: 9402D51E  bl       #0x325698
//   0x270224: AA0203FE  mov      x30, x2
//   0x270228: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1068_0x27021c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x27021cULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9402d51eULL) ^ 0x0ee828ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1069 | PC: 0x271860 | FDE: 0x0ee9c0 | Size: 256 bytes
// Khung tháo gỡ #1069 | Địa chỉ PC: 0x271860 | Địa chỉ FDE: 0x0ee9c0 | Kích thước: 256 bytes
//   0x271860: AA1E03E2  mov      x2, x30
//   0x271864: 9402CB93  bl       #0x3246b0
//   0x271868: AA0203FE  mov      x30, x2
//   0x27186c: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_1069_0x271860(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x271860ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9402cb93ULL) ^ 0x0ee9c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1070 | PC: 0x272c74 | FDE: 0x0eeb28 | Size: 256 bytes
// Khung tháo gỡ #1070 | Địa chỉ PC: 0x272c74 | Địa chỉ FDE: 0x0eeb28 | Kích thước: 256 bytes
//   0x272c74: D10503FF  sub      sp, sp, #0x140
//   0x272c78: F9008BFC  str      x28, [sp, #0x110]
//   0x272c7c: A91253F5  stp      x21, x20, [sp, #0x120]
//   0x272c80: A9137BF3  stp      x19, x30, [sp, #0x130]
static inline uint64_t fde_func_1070_0x272c74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x272c74ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xf9008bfcULL) ^ 0x0eeb28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1071 | PC: 0x2734f4 | FDE: 0x0eec70 | Size: 256 bytes
// Khung tháo gỡ #1071 | Địa chỉ PC: 0x2734f4 | Địa chỉ FDE: 0x0eec70 | Kích thước: 256 bytes
//   0x2734f4: AA1E03E1  mov      x1, x30
//   0x2734f8: 9402B0EE  bl       #0x31f8b0
//   0x2734fc: AA0103FE  mov      x30, x1
//   0x273500: A9147BFD  stp      x29, x30, [sp, #0x140]
static inline uint64_t fde_func_1071_0x2734f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2734f4ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x9402b0eeULL) ^ 0x0eec70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1072 | PC: 0x274834 | FDE: 0x0eedb8 | Size: 256 bytes
// Khung tháo gỡ #1072 | Địa chỉ PC: 0x274834 | Địa chỉ FDE: 0x0eedb8 | Kích thước: 256 bytes
//   0x274834: AA1E03E8  mov      x8, x30
//   0x274838: 9402AFA7  bl       #0x3206d4
//   0x27483c: AA0803FE  mov      x30, x8
//   0x274840: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1072_0x274834(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x274834ULL ^ (static_cast<uint64_t>(0xaa1e03e8ULL) << 13);
    acc = (acc + a1 + 0x9402afa7ULL) ^ 0x0eedb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1073 | PC: 0x275d68 | FDE: 0x0eef30 | Size: 256 bytes
// Khung tháo gỡ #1073 | Địa chỉ PC: 0x275d68 | Địa chỉ FDE: 0x0eef30 | Kích thước: 256 bytes
//   0x275d68: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x275d6c: 90FFF0A1  adrp     x1, #0x89000
//   0x275d70: 9114C021  add      x1, x1, #0x530
//   0x275d74: 97FC9035  bl       #0x199e48
static inline uint64_t fde_func_1073_0x275d68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x275d68ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x90fff0a1ULL) ^ 0x0eef30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1074 | PC: 0x275eec | FDE: 0x0ef038 | Size: 256 bytes
// Khung tháo gỡ #1074 | Địa chỉ PC: 0x275eec | Địa chỉ FDE: 0x0ef038 | Kích thước: 256 bytes
//   0x275eec: AA1E03E4  mov      x4, x30
//   0x275ef0: 9402A9F9  bl       #0x3206d4
//   0x275ef4: AA0403FE  mov      x30, x4
//   0x275ef8: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1074_0x275eec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x275eecULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x9402a9f9ULL) ^ 0x0ef038ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1075 | PC: 0x2770dc | FDE: 0x0ef1d8 | Size: 256 bytes
// Khung tháo gỡ #1075 | Địa chỉ PC: 0x2770dc | Địa chỉ FDE: 0x0ef1d8 | Kích thước: 256 bytes
//   0x2770dc: D10143FF  sub      sp, sp, #0x50
//   0x2770e0: F9001BF4  str      x20, [sp, #0x30]
//   0x2770e4: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x2770e8: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1075_0x2770dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2770dcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf4ULL) ^ 0x0ef1d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1076 | PC: 0x2777c8 | FDE: 0x0ef308 | Size: 256 bytes
// Khung tháo gỡ #1076 | Địa chỉ PC: 0x2777c8 | Địa chỉ FDE: 0x0ef308 | Kích thước: 256 bytes
//   0x2777c8: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x2777cc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2777d0: 9402BFE5  bl       #0x327764
//   0x2777d4: 37F80168  tbnz     w8, #0x1f, #0x277800
static inline uint64_t fde_func_1076_0x2777c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2777c8ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0ef308ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1077 | PC: 0x278520 | FDE: 0x0ef428 | Size: 256 bytes
// Khung tháo gỡ #1077 | Địa chỉ PC: 0x278520 | Địa chỉ FDE: 0x0ef428 | Kích thước: 256 bytes
//   0x278520: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x278524: F00006E8  adrp     x8, #0x357000
//   0x278528: 910B6108  add      x8, x8, #0x2d8
//   0x27852c: 9402908D  bl       #0x31c760
static inline uint64_t fde_func_1077_0x278520(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x278520ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf00006e8ULL) ^ 0x0ef428ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1078 | PC: 0x278cc8 | FDE: 0x0ef568 | Size: 256 bytes
// Khung tháo gỡ #1078 | Địa chỉ PC: 0x278cc8 | Địa chỉ FDE: 0x0ef568 | Kích thước: 256 bytes
//   0x278cc8: D10383FF  sub      sp, sp, #0xe0
//   0x278ccc: A90B5BF7  stp      x23, x22, [sp, #0xb0]
//   0x278cd0: A90C53F5  stp      x21, x20, [sp, #0xc0]
//   0x278cd4: A90D7BF3  stp      x19, x30, [sp, #0xd0]
static inline uint64_t fde_func_1078_0x278cc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x278cc8ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa90b5bf7ULL) ^ 0x0ef568ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1079 | PC: 0x279a94 | FDE: 0x0ef6d0 | Size: 256 bytes
// Khung tháo gỡ #1079 | Địa chỉ PC: 0x279a94 | Địa chỉ FDE: 0x0ef6d0 | Kích thước: 256 bytes
//   0x279a94: D10783FF  sub      sp, sp, #0x1e0
//   0x279a98: AA1E03E2  mov      x2, x30
//   0x279a9c: 940295BF  bl       #0x31f198
//   0x279aa0: AA0203FE  mov      x30, x2
static inline uint64_t fde_func_1079_0x279a94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x279a94ULL ^ (static_cast<uint64_t>(0xd10783ffULL) << 13);
    acc = (acc + a1 + 0xaa1e03e2ULL) ^ 0x0ef6d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1080 | PC: 0x27a540 | FDE: 0x0ef838 | Size: 256 bytes
// Khung tháo gỡ #1080 | Địa chỉ PC: 0x27a540 | Địa chỉ FDE: 0x0ef838 | Kích thước: 256 bytes
//   0x27a540: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x27a544: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x27a548: F9400828  ldr      x8, [x1, #0x10]
//   0x27a54c: 3DC00020  ldr      q0, [x1]
static inline uint64_t fde_func_1080_0x27a540(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x27a540ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0ef838ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1081 | PC: 0x27a94c | FDE: 0x0ef960 | Size: 256 bytes
// Khung tháo gỡ #1081 | Địa chỉ PC: 0x27a94c | Địa chỉ FDE: 0x0ef960 | Kích thước: 256 bytes
//   0x27a94c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x27a950: AA0003F3  mov      x19, x0
//   0x27a954: 91010000  add      x0, x0, #0x40
//   0x27a958: 97FB7C8A  bl       #0x159b80
static inline uint64_t fde_func_1081_0x27a94c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x27a94cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0ef960ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1082 | PC: 0x27ae48 | FDE: 0x0efa68 | Size: 256 bytes
// Khung tháo gỡ #1082 | Địa chỉ PC: 0x27ae48 | Địa chỉ FDE: 0x0efa68 | Kích thước: 256 bytes
//   0x27ae48: D10683FF  sub      sp, sp, #0x1a0
//   0x27ae4c: F900ABFC  str      x28, [sp, #0x150]
//   0x27ae50: A91663F9  stp      x25, x24, [sp, #0x160]
//   0x27ae54: A9175BF7  stp      x23, x22, [sp, #0x170]
static inline uint64_t fde_func_1082_0x27ae48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x27ae48ULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xf900abfcULL) ^ 0x0efa68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1083 | PC: 0x27b9c4 | FDE: 0x0efb90 | Size: 256 bytes
// Khung tháo gỡ #1083 | Địa chỉ PC: 0x27b9c4 | Địa chỉ FDE: 0x0efb90 | Kích thước: 256 bytes
//   0x27b9c4: D107C3FF  sub      sp, sp, #0x1f0
//   0x27b9c8: A91B63FC  stp      x28, x24, [sp, #0x1b0]
//   0x27b9cc: A91C5BF7  stp      x23, x22, [sp, #0x1c0]
//   0x27b9d0: A91D53F5  stp      x21, x20, [sp, #0x1d0]
static inline uint64_t fde_func_1083_0x27b9c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x27b9c4ULL ^ (static_cast<uint64_t>(0xd107c3ffULL) << 13);
    acc = (acc + a1 + 0xa91b63fcULL) ^ 0x0efb90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1084 | PC: 0x27d794 | FDE: 0x0efd10 | Size: 256 bytes
// Khung tháo gỡ #1084 | Địa chỉ PC: 0x27d794 | Địa chỉ FDE: 0x0efd10 | Kích thước: 256 bytes
//   0x27d794: D10583FF  sub      sp, sp, #0x160
//   0x27d798: A91263FC  stp      x28, x24, [sp, #0x120]
//   0x27d79c: A9135BF7  stp      x23, x22, [sp, #0x130]
//   0x27d7a0: A91453F5  stp      x21, x20, [sp, #0x140]
static inline uint64_t fde_func_1084_0x27d794(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x27d794ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa91263fcULL) ^ 0x0efd10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1085 | PC: 0x27df38 | FDE: 0x0efe58 | Size: 256 bytes
// Khung tháo gỡ #1085 | Địa chỉ PC: 0x27df38 | Địa chỉ FDE: 0x0efe58 | Kích thước: 256 bytes
//   0x27df38: D10143FF  sub      sp, sp, #0x50
//   0x27df3c: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x27df40: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x27df44: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1085_0x27df38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x27df38ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x0efe58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1086 | PC: 0x27ea54 | FDE: 0x0effb8 | Size: 256 bytes
// Khung tháo gỡ #1086 | Địa chỉ PC: 0x27ea54 | Địa chỉ FDE: 0x0effb8 | Kích thước: 256 bytes
//   0x27ea54: D10143FF  sub      sp, sp, #0x50
//   0x27ea58: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x27ea5c: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x27ea60: 94028BBD  bl       #0x321954
static inline uint64_t fde_func_1086_0x27ea54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x27ea54ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90353f5ULL) ^ 0x0effb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1087 | PC: 0x27f684 | FDE: 0x0f0118 | Size: 256 bytes
// Khung tháo gỡ #1087 | Địa chỉ PC: 0x27f684 | Địa chỉ FDE: 0x0f0118 | Kích thước: 256 bytes
//   0x27f684: D10203FF  sub      sp, sp, #0x80
//   0x27f688: AA1E03E3  mov      x3, x30
//   0x27f68c: 940278BA  bl       #0x31d974
//   0x27f690: AA0303FE  mov      x30, x3
static inline uint64_t fde_func_1087_0x27f684(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x27f684ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xaa1e03e3ULL) ^ 0x0f0118ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1088 | PC: 0x27fedc | FDE: 0x0f0268 | Size: 256 bytes
// Khung tháo gỡ #1088 | Địa chỉ PC: 0x27fedc | Địa chỉ FDE: 0x0f0268 | Kích thước: 256 bytes
//   0x27fedc: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x27fee0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x27fee4: 900006C8  adrp     x8, #0x357000
//   0x27fee8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1088_0x27fedc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x27fedcULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f0268ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1089 | PC: 0x2803f8 | FDE: 0x0f03a8 | Size: 256 bytes
// Khung tháo gỡ #1089 | Địa chỉ PC: 0x2803f8 | Địa chỉ FDE: 0x0f03a8 | Kích thước: 256 bytes
//   0x2803f8: F00006A8  adrp     x8, #0x357000
//   0x2803fc: 912C4108  add      x8, x8, #0xb10
//   0x280400: F8020408  str      x8, [x0], #0x20
//   0x280404: 14030073  b        #0x3405d0
static inline uint64_t fde_func_1089_0x2803f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2803f8ULL ^ (static_cast<uint64_t>(0xf00006a8ULL) << 13);
    acc = (acc + a1 + 0x912c4108ULL) ^ 0x0f03a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1090 | PC: 0x2809c0 | FDE: 0x0f04d8 | Size: 256 bytes
// Khung tháo gỡ #1090 | Địa chỉ PC: 0x2809c0 | Địa chỉ FDE: 0x0f04d8 | Kích thước: 256 bytes
//   0x2809c0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2809c4: 94029F00  bl       #0x3285c4
//   0x2809c8: F9400660  ldr      x0, [x19, #8]
//   0x2809cc: A8C17BF3  ldp      x19, x30, [sp], #0x10
static inline uint64_t fde_func_1090_0x2809c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2809c0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94029f00ULL) ^ 0x0f04d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1091 | PC: 0x280b7c | FDE: 0x0f05d8 | Size: 256 bytes
// Khung tháo gỡ #1091 | Địa chỉ PC: 0x280b7c | Địa chỉ FDE: 0x0f05d8 | Kích thước: 256 bytes
//   0x280b7c: D100C3FF  sub      sp, sp, #0x30
//   0x280b80: F9000BF4  str      x20, [sp, #0x10]
//   0x280b84: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x280b88: 9402C5F7  bl       #0x332364
static inline uint64_t fde_func_1091_0x280b7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x280b7cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x0f05d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1092 | PC: 0x281064 | FDE: 0x0f06f0 | Size: 256 bytes
// Khung tháo gỡ #1092 | Địa chỉ PC: 0x281064 | Địa chỉ FDE: 0x0f06f0 | Kích thước: 256 bytes
//   0x281064: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x281068: D00006A8  adrp     x8, #0x357000
//   0x28106c: 9132E108  add      x8, x8, #0xcb8
//   0x281070: 94026DBC  bl       #0x31c760
static inline uint64_t fde_func_1092_0x281064(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x281064ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xd00006a8ULL) ^ 0x0f06f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1093 | PC: 0x281690 | FDE: 0x0f0808 | Size: 256 bytes
// Khung tháo gỡ #1093 | Địa chỉ PC: 0x281690 | Địa chỉ FDE: 0x0f0808 | Kích thước: 256 bytes
//   0x281690: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x281694: F9402808  ldr      x8, [x0, #0x50]
//   0x281698: AA0003F3  mov      x19, x0
//   0x28169c: B4000088  cbz      x8, #0x2816ac
static inline uint64_t fde_func_1093_0x281690(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x281690ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9402808ULL) ^ 0x0f0808ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1094 | PC: 0x2819c0 | FDE: 0x0f0918 | Size: 256 bytes
// Khung tháo gỡ #1094 | Địa chỉ PC: 0x2819c0 | Địa chỉ FDE: 0x0f0918 | Kích thước: 256 bytes
//   0x2819c0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2819c4: F0FFEF41  adrp     x1, #0x6c000
//   0x2819c8: 90000002  adrp     x2, #0x281000
//   0x2819cc: 91346C21  add      x1, x1, #0xd1b
static inline uint64_t fde_func_1094_0x2819c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2819c0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf0ffef41ULL) ^ 0x0f0918ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1095 | PC: 0x282258 | FDE: 0x0f0a50 | Size: 256 bytes
// Khung tháo gỡ #1095 | Địa chỉ PC: 0x282258 | Địa chỉ FDE: 0x0f0a50 | Kích thước: 256 bytes
//   0x282258: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x28225c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x282260: 940266A7  bl       #0x31bcfc
//   0x282264: 940266B0  bl       #0x31bd24
static inline uint64_t fde_func_1095_0x282258(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x282258ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f0a50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1096 | PC: 0x2823e8 | FDE: 0x0f0b90 | Size: 256 bytes
// Khung tháo gỡ #1096 | Địa chỉ PC: 0x2823e8 | Địa chỉ FDE: 0x0f0b90 | Kích thước: 256 bytes
//   0x2823e8: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x2823ec: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2823f0: 94026643  bl       #0x31bcfc
//   0x2823f4: 9402664C  bl       #0x31bd24
static inline uint64_t fde_func_1096_0x2823e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2823e8ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f0b90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1097 | PC: 0x282578 | FDE: 0x0f0cd0 | Size: 256 bytes
// Khung tháo gỡ #1097 | Địa chỉ PC: 0x282578 | Địa chỉ FDE: 0x0f0cd0 | Kích thước: 256 bytes
//   0x282578: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x28257c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x282580: 940265DF  bl       #0x31bcfc
//   0x282584: 940265E8  bl       #0x31bd24
static inline uint64_t fde_func_1097_0x282578(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x282578ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f0cd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1098 | PC: 0x282700 | FDE: 0x0f0e10 | Size: 256 bytes
// Khung tháo gỡ #1098 | Địa chỉ PC: 0x282700 | Địa chỉ FDE: 0x0f0e10 | Kích thước: 256 bytes
//   0x282700: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x282704: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x282708: 9402657D  bl       #0x31bcfc
//   0x28270c: 94026586  bl       #0x31bd24
static inline uint64_t fde_func_1098_0x282700(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x282700ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f0e10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1099 | PC: 0x28389c | FDE: 0x0f0f50 | Size: 256 bytes
// Khung tháo gỡ #1099 | Địa chỉ PC: 0x28389c | Địa chỉ FDE: 0x0f0f50 | Kích thước: 256 bytes
//   0x28389c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x2838a0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2838a4: 94026116  bl       #0x31bcfc
//   0x2838a8: 9402611F  bl       #0x31bd24
static inline uint64_t fde_func_1099_0x28389c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x28389cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f0f50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1100 | PC: 0x283a2c | FDE: 0x0f1090 | Size: 256 bytes
// Khung tháo gỡ #1100 | Địa chỉ PC: 0x283a2c | Địa chỉ FDE: 0x0f1090 | Kích thước: 256 bytes
//   0x283a2c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x283a30: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x283a34: 940260B2  bl       #0x31bcfc
//   0x283a38: 940260BB  bl       #0x31bd24
static inline uint64_t fde_func_1100_0x283a2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x283a2cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f1090ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1101 | PC: 0x283bbc | FDE: 0x0f11d0 | Size: 256 bytes
// Khung tháo gỡ #1101 | Địa chỉ PC: 0x283bbc | Địa chỉ FDE: 0x0f11d0 | Kích thước: 256 bytes
//   0x283bbc: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x283bc0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x283bc4: 9402604E  bl       #0x31bcfc
//   0x283bc8: 94026057  bl       #0x31bd24
static inline uint64_t fde_func_1101_0x283bbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x283bbcULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f11d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1102 | PC: 0x283d4c | FDE: 0x0f1310 | Size: 256 bytes
// Khung tháo gỡ #1102 | Địa chỉ PC: 0x283d4c | Địa chỉ FDE: 0x0f1310 | Kích thước: 256 bytes
//   0x283d4c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x283d50: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x283d54: 94025FEA  bl       #0x31bcfc
//   0x283d58: 94025FF3  bl       #0x31bd24
static inline uint64_t fde_func_1102_0x283d4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x283d4cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f1310ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1103 | PC: 0x283edc | FDE: 0x0f1450 | Size: 256 bytes
// Khung tháo gỡ #1103 | Địa chỉ PC: 0x283edc | Địa chỉ FDE: 0x0f1450 | Kích thước: 256 bytes
//   0x283edc: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x283ee0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x283ee4: 94025F86  bl       #0x31bcfc
//   0x283ee8: 94025F8F  bl       #0x31bd24
static inline uint64_t fde_func_1103_0x283edc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x283edcULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f1450ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1104 | PC: 0x28406c | FDE: 0x0f1590 | Size: 256 bytes
// Khung tháo gỡ #1104 | Địa chỉ PC: 0x28406c | Địa chỉ FDE: 0x0f1590 | Kích thước: 256 bytes
//   0x28406c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x284070: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x284074: 94025F22  bl       #0x31bcfc
//   0x284078: 94025F2B  bl       #0x31bd24
static inline uint64_t fde_func_1104_0x28406c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x28406cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f1590ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1105 | PC: 0x2841fc | FDE: 0x0f16d0 | Size: 256 bytes
// Khung tháo gỡ #1105 | Địa chỉ PC: 0x2841fc | Địa chỉ FDE: 0x0f16d0 | Kích thước: 256 bytes
//   0x2841fc: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x284200: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x284204: 94025EBE  bl       #0x31bcfc
//   0x284208: 94025EC7  bl       #0x31bd24
static inline uint64_t fde_func_1105_0x2841fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2841fcULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f16d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1106 | PC: 0x28438c | FDE: 0x0f1810 | Size: 256 bytes
// Khung tháo gỡ #1106 | Địa chỉ PC: 0x28438c | Địa chỉ FDE: 0x0f1810 | Kích thước: 256 bytes
//   0x28438c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x284390: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x284394: 94025E5A  bl       #0x31bcfc
//   0x284398: 94025E63  bl       #0x31bd24
static inline uint64_t fde_func_1106_0x28438c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x28438cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f1810ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1107 | PC: 0x28451c | FDE: 0x0f1950 | Size: 256 bytes
// Khung tháo gỡ #1107 | Địa chỉ PC: 0x28451c | Địa chỉ FDE: 0x0f1950 | Kích thước: 256 bytes
//   0x28451c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x284520: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x284524: 94025DF6  bl       #0x31bcfc
//   0x284528: 94025DFF  bl       #0x31bd24
static inline uint64_t fde_func_1107_0x28451c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x28451cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f1950ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1108 | PC: 0x2846ac | FDE: 0x0f1a90 | Size: 256 bytes
// Khung tháo gỡ #1108 | Địa chỉ PC: 0x2846ac | Địa chỉ FDE: 0x0f1a90 | Kích thước: 256 bytes
//   0x2846ac: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x2846b0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2846b4: 94025D92  bl       #0x31bcfc
//   0x2846b8: 94025D9B  bl       #0x31bd24
static inline uint64_t fde_func_1108_0x2846ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2846acULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f1a90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1109 | PC: 0x28483c | FDE: 0x0f1bd0 | Size: 256 bytes
// Khung tháo gỡ #1109 | Địa chỉ PC: 0x28483c | Địa chỉ FDE: 0x0f1bd0 | Kích thước: 256 bytes
//   0x28483c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x284840: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x284844: 94025D2E  bl       #0x31bcfc
//   0x284848: 94025D37  bl       #0x31bd24
static inline uint64_t fde_func_1109_0x28483c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x28483cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f1bd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1110 | PC: 0x2849cc | FDE: 0x0f1d10 | Size: 256 bytes
// Khung tháo gỡ #1110 | Địa chỉ PC: 0x2849cc | Địa chỉ FDE: 0x0f1d10 | Kích thước: 256 bytes
//   0x2849cc: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x2849d0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2849d4: 94025CCA  bl       #0x31bcfc
//   0x2849d8: 94025CD3  bl       #0x31bd24
static inline uint64_t fde_func_1110_0x2849cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2849ccULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f1d10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1111 | PC: 0x284b5c | FDE: 0x0f1e50 | Size: 256 bytes
// Khung tháo gỡ #1111 | Địa chỉ PC: 0x284b5c | Địa chỉ FDE: 0x0f1e50 | Kích thước: 256 bytes
//   0x284b5c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x284b60: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x284b64: 94025C66  bl       #0x31bcfc
//   0x284b68: 94025C6F  bl       #0x31bd24
static inline uint64_t fde_func_1111_0x284b5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x284b5cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f1e50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1112 | PC: 0x284cec | FDE: 0x0f1f90 | Size: 256 bytes
// Khung tháo gỡ #1112 | Địa chỉ PC: 0x284cec | Địa chỉ FDE: 0x0f1f90 | Kích thước: 256 bytes
//   0x284cec: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x284cf0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x284cf4: 94025C02  bl       #0x31bcfc
//   0x284cf8: 94025C0B  bl       #0x31bd24
static inline uint64_t fde_func_1112_0x284cec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x284cecULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f1f90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1113 | PC: 0x284e7c | FDE: 0x0f20d0 | Size: 256 bytes
// Khung tháo gỡ #1113 | Địa chỉ PC: 0x284e7c | Địa chỉ FDE: 0x0f20d0 | Kích thước: 256 bytes
//   0x284e7c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x284e80: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x284e84: 94025B9E  bl       #0x31bcfc
//   0x284e88: 94025BA7  bl       #0x31bd24
static inline uint64_t fde_func_1113_0x284e7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x284e7cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f20d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1114 | PC: 0x28500c | FDE: 0x0f2210 | Size: 256 bytes
// Khung tháo gỡ #1114 | Địa chỉ PC: 0x28500c | Địa chỉ FDE: 0x0f2210 | Kích thước: 256 bytes
//   0x28500c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x285010: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x285014: 94025B3A  bl       #0x31bcfc
//   0x285018: 94025B43  bl       #0x31bd24
static inline uint64_t fde_func_1114_0x28500c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x28500cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f2210ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1115 | PC: 0x28519c | FDE: 0x0f2350 | Size: 256 bytes
// Khung tháo gỡ #1115 | Địa chỉ PC: 0x28519c | Địa chỉ FDE: 0x0f2350 | Kích thước: 256 bytes
//   0x28519c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x2851a0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2851a4: 94025AD6  bl       #0x31bcfc
//   0x2851a8: 94025ADF  bl       #0x31bd24
static inline uint64_t fde_func_1115_0x28519c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x28519cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f2350ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1116 | PC: 0x285990 | FDE: 0x0f24a0 | Size: 256 bytes
// Khung tháo gỡ #1116 | Địa chỉ PC: 0x285990 | Địa chỉ FDE: 0x0f24a0 | Kích thước: 256 bytes
//   0x285990: AA1E03E3  mov      x3, x30
//   0x285994: 9402644A  bl       #0x31eabc
//   0x285998: AA0303FE  mov      x30, x3
//   0x28599c: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1116_0x285990(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x285990ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x9402644aULL) ^ 0x0f24a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1117 | PC: 0x285ef8 | FDE: 0x0f25f0 | Size: 256 bytes
// Khung tháo gỡ #1117 | Địa chỉ PC: 0x285ef8 | Địa chỉ FDE: 0x0f25f0 | Kích thước: 256 bytes
//   0x285ef8: D10343FF  sub      sp, sp, #0xd0
//   0x285efc: A90A5BF7  stp      x23, x22, [sp, #0xa0]
//   0x285f00: A90B53F5  stp      x21, x20, [sp, #0xb0]
//   0x285f04: A90C7BF3  stp      x19, x30, [sp, #0xc0]
static inline uint64_t fde_func_1117_0x285ef8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x285ef8ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa90a5bf7ULL) ^ 0x0f25f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1118 | PC: 0x2864e0 | FDE: 0x0f2740 | Size: 256 bytes
// Khung tháo gỡ #1118 | Địa chỉ PC: 0x2864e0 | Địa chỉ FDE: 0x0f2740 | Kích thước: 256 bytes
//   0x2864e0: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2864e4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2864e8: 94027E40  bl       #0x325de8
//   0x2864ec: B40000E0  cbz      x0, #0x286508
static inline uint64_t fde_func_1118_0x2864e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2864e0ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f2740ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1119 | PC: 0x286ddc | FDE: 0x0f2890 | Size: 256 bytes
// Khung tháo gỡ #1119 | Địa chỉ PC: 0x286ddc | Địa chỉ FDE: 0x0f2890 | Kích thước: 256 bytes
//   0x286ddc: D10303FF  sub      sp, sp, #0xc0
//   0x286de0: F90053F4  str      x20, [sp, #0xa0]
//   0x286de4: A90B7BF3  stp      x19, x30, [sp, #0xb0]
//   0x286de8: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1119_0x286ddc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x286ddcULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90053f4ULL) ^ 0x0f2890ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1120 | PC: 0x287990 | FDE: 0x0f29e8 | Size: 256 bytes
// Khung tháo gỡ #1120 | Địa chỉ PC: 0x287990 | Địa chỉ FDE: 0x0f29e8 | Kích thước: 256 bytes
//   0x287990: AA1E03E3  mov      x3, x30
//   0x287994: 9402B2B1  bl       #0x334458
//   0x287998: AA0303FE  mov      x30, x3
//   0x28799c: A90D7BF3  stp      x19, x30, [sp, #0xd0]
static inline uint64_t fde_func_1120_0x287990(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x287990ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x9402b2b1ULL) ^ 0x0f29e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1121 | PC: 0x288570 | FDE: 0x0f2b68 | Size: 256 bytes
// Khung tháo gỡ #1121 | Địa chỉ PC: 0x288570 | Địa chỉ FDE: 0x0f2b68 | Kích thước: 256 bytes
//   0x288570: AA1E03E4  mov      x4, x30
//   0x288574: 94025252  bl       #0x31cebc
//   0x288578: AA0403FE  mov      x30, x4
//   0x28857c: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_1121_0x288570(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x288570ULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x94025252ULL) ^ 0x0f2b68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1122 | PC: 0x288ce8 | FDE: 0x0f2ca0 | Size: 256 bytes
// Khung tháo gỡ #1122 | Địa chỉ PC: 0x288ce8 | Địa chỉ FDE: 0x0f2ca0 | Kích thước: 256 bytes
//   0x288ce8: D10103FF  sub      sp, sp, #0x40
//   0x288cec: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x288cf0: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x288cf4: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1122_0x288ce8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x288ce8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0f2ca0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1123 | PC: 0x2898b4 | FDE: 0x0f2e10 | Size: 256 bytes
// Khung tháo gỡ #1123 | Địa chỉ PC: 0x2898b4 | Địa chỉ FDE: 0x0f2e10 | Kích thước: 256 bytes
//   0x2898b4: AA1E03E2  mov      x2, x30
//   0x2898b8: 9402770D  bl       #0x3274ec
//   0x2898bc: AA0203FE  mov      x30, x2
//   0x2898c0: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_1123_0x2898b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2898b4ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9402770dULL) ^ 0x0f2e10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1124 | PC: 0x28a71c | FDE: 0x0f2f88 | Size: 256 bytes
// Khung tháo gỡ #1124 | Địa chỉ PC: 0x28a71c | Địa chỉ FDE: 0x0f2f88 | Kích thước: 256 bytes
//   0x28a71c: AA1E03E3  mov      x3, x30
//   0x28a720: 94025864  bl       #0x3208b0
//   0x28a724: AA0303FE  mov      x30, x3
//   0x28a728: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1124_0x28a71c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x28a71cULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94025864ULL) ^ 0x0f2f88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1125 | PC: 0x28ad3c | FDE: 0x0f30c8 | Size: 256 bytes
// Khung tháo gỡ #1125 | Địa chỉ PC: 0x28ad3c | Địa chỉ FDE: 0x0f30c8 | Kích thước: 256 bytes
//   0x28ad3c: D10103FF  sub      sp, sp, #0x40
//   0x28ad40: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x28ad44: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x28ad48: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1125_0x28ad3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x28ad3cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0f30c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1126 | PC: 0x28b84c | FDE: 0x0f3220 | Size: 256 bytes
// Khung tháo gỡ #1126 | Địa chỉ PC: 0x28b84c | Địa chỉ FDE: 0x0f3220 | Kích thước: 256 bytes
//   0x28b84c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x28b850: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x28b854: 94026E8F  bl       #0x327290
//   0x28b858: 54000121  b.ne     #0x28b87c
static inline uint64_t fde_func_1126_0x28b84c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x28b84cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f3220ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1127 | PC: 0x28bea8 | FDE: 0x0f3378 | Size: 256 bytes
// Khung tháo gỡ #1127 | Địa chỉ PC: 0x28bea8 | Địa chỉ FDE: 0x0f3378 | Kích thước: 256 bytes
//   0x28bea8: D10143FF  sub      sp, sp, #0x50
//   0x28beac: F9001BF4  str      x20, [sp, #0x30]
//   0x28beb0: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x28beb4: 940277BA  bl       #0x329d9c
static inline uint64_t fde_func_1127_0x28bea8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x28bea8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf4ULL) ^ 0x0f3378ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1128 | PC: 0x28c518 | FDE: 0x0f34d0 | Size: 256 bytes
// Khung tháo gỡ #1128 | Địa chỉ PC: 0x28c518 | Địa chỉ FDE: 0x0f34d0 | Kích thước: 256 bytes
//   0x28c518: D100C3FF  sub      sp, sp, #0x30
//   0x28c51c: F9000BF4  str      x20, [sp, #0x10]
//   0x28c520: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x28c524: 940297AA  bl       #0x3323cc
static inline uint64_t fde_func_1128_0x28c518(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x28c518ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x0f34d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1129 | PC: 0x28d0d8 | FDE: 0x0f3640 | Size: 256 bytes
// Khung tháo gỡ #1129 | Địa chỉ PC: 0x28d0d8 | Địa chỉ FDE: 0x0f3640 | Kích thước: 256 bytes
//   0x28d0d8: D10143FF  sub      sp, sp, #0x50
//   0x28d0dc: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x28d0e0: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x28d0e4: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1129_0x28d0d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x28d0d8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x0f3640ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1130 | PC: 0x28d99c | FDE: 0x0f3798 | Size: 256 bytes
// Khung tháo gỡ #1130 | Địa chỉ PC: 0x28d99c | Địa chỉ FDE: 0x0f3798 | Kích thước: 256 bytes
//   0x28d99c: D100C3FF  sub      sp, sp, #0x30
//   0x28d9a0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x28d9a4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x28d9a8: D53BD055  mrs      x21, tpidr_el0
static inline uint64_t fde_func_1130_0x28d99c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x28d99cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0f3798ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1131 | PC: 0x28e0c0 | FDE: 0x0f38d8 | Size: 256 bytes
// Khung tháo gỡ #1131 | Địa chỉ PC: 0x28e0c0 | Địa chỉ FDE: 0x0f38d8 | Kích thước: 256 bytes
//   0x28e0c0: A940A001  ldp      x1, x8, [x0, #8]
//   0x28e0c4: F9401100  ldr      x0, [x8, #0x20]
//   0x28e0c8: 17FBE565  b        #0x18765c
//   0x28e0cc: AA1E03E3  mov      x3, x30
static inline uint64_t fde_func_1131_0x28e0c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x28e0c0ULL ^ (static_cast<uint64_t>(0xa940a001ULL) << 13);
    acc = (acc + a1 + 0xf9401100ULL) ^ 0x0f38d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1132 | PC: 0x28e944 | FDE: 0x0f3a30 | Size: 256 bytes
// Khung tháo gỡ #1132 | Địa chỉ PC: 0x28e944 | Địa chỉ FDE: 0x0f3a30 | Kích thước: 256 bytes
//   0x28e944: D10143FF  sub      sp, sp, #0x50
//   0x28e948: F90013F6  str      x22, [sp, #0x20]
//   0x28e94c: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x28e950: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1132_0x28e944(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x28e944ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x0f3a30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1133 | PC: 0x28f314 | FDE: 0x0f3b98 | Size: 256 bytes
// Khung tháo gỡ #1133 | Địa chỉ PC: 0x28f314 | Địa chỉ FDE: 0x0f3b98 | Kích thước: 256 bytes
//   0x28f314: D10103FF  sub      sp, sp, #0x40
//   0x28f318: F9000BF6  str      x22, [sp, #0x10]
//   0x28f31c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x28f320: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1133_0x28f314(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x28f314ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x0f3b98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1134 | PC: 0x2901ac | FDE: 0x0f3ce8 | Size: 256 bytes
// Khung tháo gỡ #1134 | Địa chỉ PC: 0x2901ac | Địa chỉ FDE: 0x0f3ce8 | Kích thước: 256 bytes
//   0x2901ac: D10503FF  sub      sp, sp, #0x140
//   0x2901b0: F9007BFC  str      x28, [sp, #0xf0]
//   0x2901b4: A91063F9  stp      x25, x24, [sp, #0x100]
//   0x2901b8: A9115BF7  stp      x23, x22, [sp, #0x110]
static inline uint64_t fde_func_1134_0x2901ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2901acULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xf9007bfcULL) ^ 0x0f3ce8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1135 | PC: 0x290d48 | FDE: 0x0f3e68 | Size: 256 bytes
// Khung tháo gỡ #1135 | Địa chỉ PC: 0x290d48 | Địa chỉ FDE: 0x0f3e68 | Kích thước: 256 bytes
//   0x290d48: D10143FF  sub      sp, sp, #0x50
//   0x290d4c: F90013F6  str      x22, [sp, #0x20]
//   0x290d50: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x290d54: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1135_0x290d48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x290d48ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x0f3e68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1136 | PC: 0x29177c | FDE: 0x0f3fc0 | Size: 256 bytes
// Khung tháo gỡ #1136 | Địa chỉ PC: 0x29177c | Địa chỉ FDE: 0x0f3fc0 | Kích thước: 256 bytes
//   0x29177c: D10103FF  sub      sp, sp, #0x40
//   0x291780: F9000BF6  str      x22, [sp, #0x10]
//   0x291784: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x291788: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1136_0x29177c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x29177cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x0f3fc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1137 | PC: 0x291c94 | FDE: 0x0f40f0 | Size: 256 bytes
// Khung tháo gỡ #1137 | Địa chỉ PC: 0x291c94 | Địa chỉ FDE: 0x0f40f0 | Kích thước: 256 bytes
//   0x291c94: AA1E03E3  mov      x3, x30
//   0x291c98: 94023B06  bl       #0x3208b0
//   0x291c9c: AA0303FE  mov      x30, x3
//   0x291ca0: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1137_0x291c94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x291c94ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94023b06ULL) ^ 0x0f40f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1138 | PC: 0x2929c0 | FDE: 0x0f4238 | Size: 256 bytes
// Khung tháo gỡ #1138 | Địa chỉ PC: 0x2929c0 | Địa chỉ FDE: 0x0f4238 | Kích thước: 256 bytes
//   0x2929c0: AA1E03E3  mov      x3, x30
//   0x2929c4: 94022E06  bl       #0x31e1dc
//   0x2929c8: AA0303FE  mov      x30, x3
//   0x2929cc: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_1138_0x2929c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2929c0ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94022e06ULL) ^ 0x0f4238ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1139 | PC: 0x293144 | FDE: 0x0f4378 | Size: 256 bytes
// Khung tháo gỡ #1139 | Địa chỉ PC: 0x293144 | Địa chỉ FDE: 0x0f4378 | Kích thước: 256 bytes
//   0x293144: D10103FF  sub      sp, sp, #0x40
//   0x293148: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x29314c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x293150: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1139_0x293144(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x293144ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0f4378ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1140 | PC: 0x293b6c | FDE: 0x0f44d8 | Size: 256 bytes
// Khung tháo gỡ #1140 | Địa chỉ PC: 0x293b6c | Địa chỉ FDE: 0x0f44d8 | Kích thước: 256 bytes
//   0x293b6c: AA1E03E3  mov      x3, x30
//   0x293b70: 94022966  bl       #0x31e108
//   0x293b74: AA0303FE  mov      x30, x3
//   0x293b78: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1140_0x293b6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x293b6cULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94022966ULL) ^ 0x0f44d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1141 | PC: 0x294768 | FDE: 0x0f4628 | Size: 256 bytes
// Khung tháo gỡ #1141 | Địa chỉ PC: 0x294768 | Địa chỉ FDE: 0x0f4628 | Kích thước: 256 bytes
//   0x294768: 52800049  mov      w9, #2
//   0x29476c: 9101A008  add      x8, x0, #0x68
//   0x294770: B9001C09  str      w9, [x0, #0x1c]
//   0x294774: AA0803E0  mov      x0, x8
static inline uint64_t fde_func_1141_0x294768(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x294768ULL ^ (static_cast<uint64_t>(0x52800049ULL) << 13);
    acc = (acc + a1 + 0x9101a008ULL) ^ 0x0f4628ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1142 | PC: 0x294d8c | FDE: 0x0f4768 | Size: 256 bytes
// Khung tháo gỡ #1142 | Địa chỉ PC: 0x294d8c | Địa chỉ FDE: 0x0f4768 | Kích thước: 256 bytes
//   0x294d8c: D10243FF  sub      sp, sp, #0x90
//   0x294d90: F90033F6  str      x22, [sp, #0x60]
//   0x294d94: A90753F5  stp      x21, x20, [sp, #0x70]
//   0x294d98: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_1142_0x294d8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x294d8cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90033f6ULL) ^ 0x0f4768ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1143 | PC: 0x2953d4 | FDE: 0x0f48a0 | Size: 256 bytes
// Khung tháo gỡ #1143 | Địa chỉ PC: 0x2953d4 | Địa chỉ FDE: 0x0f48a0 | Kích thước: 256 bytes
//   0x2953d4: D101C3FF  sub      sp, sp, #0x70
//   0x2953d8: F90023F6  str      x22, [sp, #0x40]
//   0x2953dc: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x2953e0: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_1143_0x2953d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2953d4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f6ULL) ^ 0x0f48a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1144 | PC: 0x295b98 | FDE: 0x0f49d0 | Size: 256 bytes
// Khung tháo gỡ #1144 | Địa chỉ PC: 0x295b98 | Địa chỉ FDE: 0x0f49d0 | Kích thước: 256 bytes
//   0x295b98: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x295b9c: AA0003F3  mov      x19, x0
//   0x295ba0: 97FFFFAE  bl       #0x295a58
//   0x295ba4: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1144_0x295b98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x295b98ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0f49d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1145 | PC: 0x2961a4 | FDE: 0x0f4b18 | Size: 256 bytes
// Khung tháo gỡ #1145 | Địa chỉ PC: 0x2961a4 | Địa chỉ FDE: 0x0f4b18 | Kích thước: 256 bytes
//   0x2961a4: AA1E03E2  mov      x2, x30
//   0x2961a8: 94022411  bl       #0x31f1ec
//   0x2961ac: AA0203FE  mov      x30, x2
//   0x2961b0: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_1145_0x2961a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2961a4ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94022411ULL) ^ 0x0f4b18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1146 | PC: 0x296798 | FDE: 0x0f4c58 | Size: 256 bytes
// Khung tháo gỡ #1146 | Địa chỉ PC: 0x296798 | Địa chỉ FDE: 0x0f4c58 | Kích thước: 256 bytes
//   0x296798: 14024539  b        #0x327c7c
//   0x29679c: D10203FF  sub      sp, sp, #0x80
//   0x2967a0: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x2967a4: A90653F5  stp      x21, x20, [sp, #0x60]
static inline uint64_t fde_func_1146_0x296798(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x296798ULL ^ (static_cast<uint64_t>(0x14024539ULL) << 13);
    acc = (acc + a1 + 0xd10203ffULL) ^ 0x0f4c58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1147 | PC: 0x296cdc | FDE: 0x0f4d28 | Size: 256 bytes [_ZN4lynx5piper15NapiEnvironment4FromEN4Napi3EnvE]
// Khung tháo gỡ #1147 | Địa chỉ PC: 0x296cdc | Địa chỉ FDE: 0x0f4d28 | Kích thước: 256 bytes
//   0x296cdc: D10083FF  sub      sp, sp, #0x20
//   0x296ce0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x296ce4: 94021A9F  bl       #0x31d760
//   0x296ce8: D0000601  adrp     x1, #0x358000
static inline uint64_t fde_func_1147_0x296cdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x296cdcULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f4d28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1148 | PC: 0x296de0 | FDE: 0x0f4d78 | Size: 76 bytes [_ZN4lynx5piper15NapiEnvironment14RegisterModuleERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEENS2_10unique_ptrINS1_6ModuleENS2_14default_deleteISC_EEEE]
// Khung tháo gỡ #1148 | Địa chỉ PC: 0x296de0 | Địa chỉ FDE: 0x0f4d78 | Kích thước: 76 bytes
//   0x296de0: D10083FF  sub      sp, sp, #0x20
//   0x296de4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x296de8: 94022AB4  bl       #0x3218b8
//   0x296dec: F9400048  ldr      x8, [x2]
static inline uint64_t fde_func_1148_0x296de0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x296de0ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f4d78ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1149 | PC: 0x296e2c | FDE: 0x0f4d90 | Size: 256 bytes [_ZN4lynx5piper15NapiEnvironment9GetModuleERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE]
// Khung tháo gỡ #1149 | Địa chỉ PC: 0x296e2c | Địa chỉ FDE: 0x0f4d90 | Kích thước: 256 bytes
//   0x296e2c: F9400000  ldr      x0, [x0]
//   0x296e30: 14029EBD  b        #0x33e924
//   0x296e34: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x296e38: 940245D7  bl       #0x328594
static inline uint64_t fde_func_1149_0x296e2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x296e2cULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0x14029ebdULL) ^ 0x0f4d90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1150 | PC: 0x297358 | FDE: 0x0f4ec0 | Size: 256 bytes
// Khung tháo gỡ #1150 | Địa chỉ PC: 0x297358 | Địa chỉ FDE: 0x0f4ec0 | Kích thước: 256 bytes
//   0x297358: D10283FF  sub      sp, sp, #0xa0
//   0x29735c: F90043F4  str      x20, [sp, #0x80]
//   0x297360: A9097BF3  stp      x19, x30, [sp, #0x90]
//   0x297364: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1150_0x297358(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x297358ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90043f4ULL) ^ 0x0f4ec0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1151 | PC: 0x2976c8 | FDE: 0x0f4f58 | Size: 4 bytes [_Z29RegisterV8RuntimeProxyFactoryPN4lynx5piper25NapiRuntimeProxyV8FactoryE]
// Khung tháo gỡ #1151 | Địa chỉ PC: 0x2976c8 | Địa chỉ FDE: 0x0f4f58 | Kích thước: 4 bytes
//   0x2976c8: 14027259  b        #0x33402c
static inline uint64_t fde_func_1151_0x2976c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2976c8ULL ^ (static_cast<uint64_t>(0x14027259ULL) << 13);
    acc = (acc + a1 + 0x14027254ULL) ^ 0x0f4f58ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1152 | PC: 0x2976cc | FDE: 0x0f4f70 | Size: 4 bytes [_Z31RegisterJSVMRuntimeProxyFactoryPN4lynx5piper27NapiRuntimeProxyJSVMFactoryE]
// Khung tháo gỡ #1152 | Địa chỉ PC: 0x2976cc | Địa chỉ FDE: 0x0f4f70 | Kích thước: 4 bytes
//   0x2976cc: 14027254  b        #0x33401c
static inline uint64_t fde_func_1152_0x2976cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2976ccULL ^ (static_cast<uint64_t>(0x14027254ULL) << 13);
    acc = (acc + a1 + 0xaa1e03e2ULL) ^ 0x0f4f70ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1153 | PC: 0x2976d0 | FDE: 0x0f4f88 | Size: 256 bytes [_ZN4lynx5piper16NapiRuntimeProxy6CreateENSt6__ndk110shared_ptrINS0_7RuntimeEEEPNS_7runtime16TemplateDelegateE]
// Khung tháo gỡ #1153 | Địa chỉ PC: 0x2976d0 | Địa chỉ FDE: 0x0f4f88 | Kích thước: 256 bytes
//   0x2976d0: AA1E03E2  mov      x2, x30
//   0x2976d4: 94023FE4  bl       #0x327664
//   0x2976d8: AA0203FE  mov      x30, x2
//   0x2976dc: A90D7BF3  stp      x19, x30, [sp, #0xd0]
static inline uint64_t fde_func_1153_0x2976d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2976d0ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94023fe4ULL) ^ 0x0f4f88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1154 | PC: 0x297a44 | FDE: 0x0f4ff0 | Size: 92 bytes
// Khung tháo gỡ #1154 | Địa chỉ PC: 0x297a44 | Địa chỉ FDE: 0x0f4ff0 | Kích thước: 92 bytes
//   0x297a44: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x297a48: AA0003F3  mov      x19, x0
//   0x297a4c: 97FFFFF8  bl       #0x297a2c
//   0x297a50: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1154_0x297a44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x297a44ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0f4ff0ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1155 | PC: 0x297aa0 | FDE: 0x0f5028 | Size: 156 bytes [_ZN4lynx5piper16NapiRuntimeProxyC1EPNS_7runtime16TemplateDelegateE]
// Khung tháo gỡ #1155 | Địa chỉ PC: 0x297aa0 | Địa chỉ FDE: 0x0f5028 | Kích thước: 156 bytes
//   0x297aa0: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x297aa4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x297aa8: D0000648  adrp     x8, #0x361000
//   0x297aac: F9466108  ldr      x8, [x8, #0xcc0]
static inline uint64_t fde_func_1155_0x297aa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x297aa0ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f5028ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1156 | PC: 0x297b3c | FDE: 0x0f5048 | Size: 52 bytes [_ZN4lynx5piper16NapiRuntimeProxyD2Ev]
// Khung tháo gỡ #1156 | Địa chỉ PC: 0x297b3c | Địa chỉ FDE: 0x0f5048 | Kích thước: 52 bytes
//   0x297b3c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x297b40: D0000648  adrp     x8, #0x361000
//   0x297b44: 94022D6C  bl       #0x3230f4
//   0x297b48: F9466108  ldr      x8, [x8, #0xcc0]
static inline uint64_t fde_func_1156_0x297b3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x297b3cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xd0000648ULL) ^ 0x0f5048ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1157 | PC: 0x297b70 | FDE: 0x0f5060 | Size: 24 bytes [_ZN4lynx5piper16NapiRuntimeProxyD0Ev]
// Khung tháo gỡ #1157 | Địa chỉ PC: 0x297b70 | Địa chỉ FDE: 0x0f5060 | Kích thước: 24 bytes
//   0x297b70: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x297b74: AA0003F3  mov      x19, x0
//   0x297b78: 9402A8E2  bl       #0x341f00
//   0x297b7c: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1157_0x297b70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x297b70ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0f5060ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1158 | PC: 0x297b88 | FDE: 0x0f5078 | Size: 68 bytes [_ZN4lynx5piper16NapiRuntimeProxy6DetachEv]
// Khung tháo gỡ #1158 | Địa chỉ PC: 0x297b88 | Địa chỉ FDE: 0x0f5078 | Kích thước: 68 bytes
//   0x297b88: F9400400  ldr      x0, [x0, #8]
//   0x297b8c: 1402A8E1  b        #0x341f10
//   0x297b90: F9400400  ldr      x0, [x0, #8]
//   0x297b94: D65F03C0  ret      
static inline uint64_t fde_func_1158_0x297b88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x297b88ULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0x1402a8e1ULL) ^ 0x0f5078ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1159 | PC: 0x297bcc | FDE: 0x0f50d8 | Size: 256 bytes [_ZN4lynx5piper16NapiRuntimeProxy11SetupLoaderEv]
// Khung tháo gỡ #1159 | Địa chỉ PC: 0x297bcc | Địa chỉ FDE: 0x0f50d8 | Kích thước: 256 bytes
//   0x297bcc: D102C3FF  sub      sp, sp, #0xb0
//   0x297bd0: A9085BF7  stp      x23, x22, [sp, #0x80]
//   0x297bd4: A90953F5  stp      x21, x20, [sp, #0x90]
//   0x297bd8: A90A7BF3  stp      x19, x30, [sp, #0xa0]
static inline uint64_t fde_func_1159_0x297bcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x297bccULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9085bf7ULL) ^ 0x0f50d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1160 | PC: 0x297d8c | FDE: 0x0f5100 | Size: 256 bytes [_ZN4lynx5piper16NapiRuntimeProxy12RemoveLoaderEv]
// Khung tháo gỡ #1160 | Địa chỉ PC: 0x297d8c | Địa chỉ FDE: 0x0f5100 | Kích thước: 256 bytes
//   0x297d8c: D10243FF  sub      sp, sp, #0x90
//   0x297d90: A9065BF7  stp      x23, x22, [sp, #0x60]
//   0x297d94: A90753F5  stp      x21, x20, [sp, #0x70]
//   0x297d98: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_1160_0x297d8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x297d8cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9065bf7ULL) ^ 0x0f5100ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1161 | PC: 0x297e8c | FDE: 0x0f5128 | Size: 256 bytes [_ZN4lynx5piper16NapiRuntimeProxy27SetUncaughtExceptionHandlerEv]
// Khung tháo gỡ #1161 | Địa chỉ PC: 0x297e8c | Địa chỉ FDE: 0x0f5128 | Kích thước: 256 bytes
//   0x297e8c: D10083FF  sub      sp, sp, #0x20
//   0x297e90: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x297e94: 94021633  bl       #0x31d760
//   0x297e98: D29FB721  mov      x1, #0xfdb9
static inline uint64_t fde_func_1161_0x297e8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x297e8cULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f5128ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1162 | PC: 0x2988b8 | FDE: 0x0f5240 | Size: 256 bytes
// Khung tháo gỡ #1162 | Địa chỉ PC: 0x2988b8 | Địa chỉ FDE: 0x0f5240 | Kích thước: 256 bytes
//   0x2988b8: D10283FF  sub      sp, sp, #0xa0
//   0x2988bc: F9003BF6  str      x22, [sp, #0x70]
//   0x2988c0: A90853F5  stp      x21, x20, [sp, #0x80]
//   0x2988c4: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_1162_0x2988b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2988b8ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf6ULL) ^ 0x0f5240ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1163 | PC: 0x298a9c | FDE: 0x0f5340 | Size: 256 bytes
// Khung tháo gỡ #1163 | Địa chỉ PC: 0x298a9c | Địa chỉ FDE: 0x0f5340 | Kích thước: 256 bytes
//   0x298a9c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x298aa0: AA0003F3  mov      x19, x0
//   0x298aa4: 9402A53F  bl       #0x341fa0
//   0x298aa8: F9400660  ldr      x0, [x19, #8]
static inline uint64_t fde_func_1163_0x298a9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x298a9cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0f5340ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1164 | PC: 0x299070 | FDE: 0x0f5460 | Size: 256 bytes
// Khung tháo gỡ #1164 | Địa chỉ PC: 0x299070 | Địa chỉ FDE: 0x0f5460 | Kích thước: 256 bytes
//   0x299070: 39416008  ldrb     w8, [x0, #0x58]
//   0x299074: 34000048  cbz      w8, #0x29907c
//   0x299078: 17FFFFF0  b        #0x299038
//   0x29907c: D65F03C0  ret      
static inline uint64_t fde_func_1164_0x299070(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x299070ULL ^ (static_cast<uint64_t>(0x39416008ULL) << 13);
    acc = (acc + a1 + 0x34000048ULL) ^ 0x0f5460ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1165 | PC: 0x299310 | FDE: 0x0f5580 | Size: 256 bytes
// Khung tháo gỡ #1165 | Địa chỉ PC: 0x299310 | Địa chỉ FDE: 0x0f5580 | Kích thước: 256 bytes
//   0x299310: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x299314: AA0003F3  mov      x19, x0
//   0x299318: 97FE008F  bl       #0x219554
//   0x29931c: 90000608  adrp     x8, #0x359000
static inline uint64_t fde_func_1165_0x299310(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x299310ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0f5580ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1166 | PC: 0x299e84 | FDE: 0x0f56c0 | Size: 256 bytes
// Khung tháo gỡ #1166 | Địa chỉ PC: 0x299e84 | Địa chỉ FDE: 0x0f56c0 | Kích thước: 256 bytes
//   0x299e84: AA1E03E3  mov      x3, x30
//   0x299e88: 94020820  bl       #0x31bf08
//   0x299e8c: AA0303FE  mov      x30, x3
//   0x299e90: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1166_0x299e84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x299e84ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94020820ULL) ^ 0x0f56c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1167 | PC: 0x29ac7c | FDE: 0x0f5808 | Size: 256 bytes
// Khung tháo gỡ #1167 | Địa chỉ PC: 0x29ac7c | Địa chỉ FDE: 0x0f5808 | Kích thước: 256 bytes
//   0x29ac7c: D100C3FF  sub      sp, sp, #0x30
//   0x29ac80: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x29ac84: 940234E9  bl       #0x328028
//   0x29ac88: 97FFFFE6  bl       #0x29ac20
static inline uint64_t fde_func_1167_0x29ac7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x29ac7cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9027bf3ULL) ^ 0x0f5808ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1168 | PC: 0x29b030 | FDE: 0x0f5938 | Size: 256 bytes
// Khung tháo gỡ #1168 | Địa chỉ PC: 0x29b030 | Địa chỉ FDE: 0x0f5938 | Kích thước: 256 bytes
//   0x29b030: AA1E03E1  mov      x1, x30
//   0x29b034: 94020983  bl       #0x31d640
//   0x29b038: AA0103FE  mov      x30, x1
//   0x29b03c: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_1168_0x29b030(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x29b030ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x94020983ULL) ^ 0x0f5938ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1169 | PC: 0x29cb30 | FDE: 0x0f5ab8 | Size: 256 bytes
// Khung tháo gỡ #1169 | Địa chỉ PC: 0x29cb30 | Địa chỉ FDE: 0x0f5ab8 | Kích thước: 256 bytes
//   0x29cb30: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x29cb34: F0000668  adrp     x8, #0x36b000
//   0x29cb38: 9112C108  add      x8, x8, #0x4b0
//   0x29cb3c: 08DFFD08  ldarb    w8, [x8]
static inline uint64_t fde_func_1169_0x29cb30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x29cb30ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf0000668ULL) ^ 0x0f5ab8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1170 | PC: 0x29d7bc | FDE: 0x0f5c00 | Size: 256 bytes
// Khung tháo gỡ #1170 | Địa chỉ PC: 0x29d7bc | Địa chỉ FDE: 0x0f5c00 | Kích thước: 256 bytes
//   0x29d7bc: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x29d7c0: 90FFEF61  adrp     x1, #0x89000
//   0x29d7c4: 912CA021  add      x1, x1, #0xb28
//   0x29d7c8: 97FBF1A0  bl       #0x199e48
static inline uint64_t fde_func_1170_0x29d7bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x29d7bcULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x90ffef61ULL) ^ 0x0f5c00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1171 | PC: 0x29df58 | FDE: 0x0f5d48 | Size: 256 bytes
// Khung tháo gỡ #1171 | Địa chỉ PC: 0x29df58 | Địa chỉ FDE: 0x0f5d48 | Kích thước: 256 bytes
//   0x29df58: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x29df5c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x29df60: AA0003F3  mov      x19, x0
//   0x29df64: 97FB63E4  bl       #0x176ef4
static inline uint64_t fde_func_1171_0x29df58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x29df58ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f5d48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1172 | PC: 0x29eb74 | FDE: 0x0f5e78 | Size: 256 bytes
// Khung tháo gỡ #1172 | Địa chỉ PC: 0x29eb74 | Địa chỉ FDE: 0x0f5e78 | Kích thước: 256 bytes
//   0x29eb74: D105C3FF  sub      sp, sp, #0x170
//   0x29eb78: F9008BFC  str      x28, [sp, #0x110]
//   0x29eb7c: A9126BFB  stp      x27, x26, [sp, #0x120]
//   0x29eb80: A91363F9  stp      x25, x24, [sp, #0x130]
static inline uint64_t fde_func_1172_0x29eb74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x29eb74ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xf9008bfcULL) ^ 0x0f5e78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1173 | PC: 0x29f270 | FDE: 0x0f5fa0 | Size: 256 bytes
// Khung tháo gỡ #1173 | Địa chỉ PC: 0x29f270 | Địa chỉ FDE: 0x0f5fa0 | Kích thước: 256 bytes
//   0x29f270: AA1E03E5  mov      x5, x30
//   0x29f274: 9402150F  bl       #0x3246b0
//   0x29f278: AA0503FE  mov      x30, x5
//   0x29f27c: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_1173_0x29f270(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x29f270ULL ^ (static_cast<uint64_t>(0xaa1e03e5ULL) << 13);
    acc = (acc + a1 + 0x9402150fULL) ^ 0x0f5fa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1174 | PC: 0x29fdb8 | FDE: 0x0f6108 | Size: 256 bytes
// Khung tháo gỡ #1174 | Địa chỉ PC: 0x29fdb8 | Địa chỉ FDE: 0x0f6108 | Kích thước: 256 bytes
//   0x29fdb8: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x29fdbc: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x29fdc0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x29fdc4: AA0303F7  mov      x23, x3
static inline uint64_t fde_func_1174_0x29fdb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x29fdb8ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0f6108ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1175 | PC: 0x2a0170 | FDE: 0x0f6218 | Size: 120 bytes [_ZN4lynx5piper5cache13TryGetCacheV8ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEESA_lNS2_10unique_ptrINS1_14CacheGeneratorENS2_14default_deleteISC_EEEE]
// Khung tháo gỡ #1175 | Địa chỉ PC: 0x2a0170 | Địa chỉ FDE: 0x0f6218 | Kích thước: 120 bytes
//   0x2a0170: D10103FF  sub      sp, sp, #0x40
//   0x2a0174: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x2a0178: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x2a017c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1175_0x2a0170(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a0170ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0f6218ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1176 | PC: 0x2a01e8 | FDE: 0x0f6238 | Size: 100 bytes [_ZN4lynx5piper5cache24RequestCacheGenerationV8ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEESA_RKNS2_10shared_ptrIKNS0_6BufferEEENS2_10unique_ptrINS1_14CacheGeneratorENS2_14default_deleteISI_EEEEb]
// Khung tháo gỡ #1176 | Địa chỉ PC: 0x2a01e8 | Địa chỉ FDE: 0x0f6238 | Kích thước: 100 bytes
//   0x2a01e8: D10103FF  sub      sp, sp, #0x40
//   0x2a01ec: A901D3FF  stp      xzr, x20, [sp, #0x18]
//   0x2a01f0: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x2a01f4: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_1176_0x2a01e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a01e8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa901d3ffULL) ^ 0x0f6238ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1177 | PC: 0x2a024c | FDE: 0x0f6258 | Size: 256 bytes
// Khung tháo gỡ #1177 | Địa chỉ PC: 0x2a024c | Địa chỉ FDE: 0x0f6258 | Kích thước: 256 bytes
//   0x2a024c: D10783FF  sub      sp, sp, #0x1e0
//   0x2a0250: AA1E03E4  mov      x4, x30
//   0x2a0254: 9401FBD1  bl       #0x31f198
//   0x2a0258: AA0403FE  mov      x30, x4
static inline uint64_t fde_func_1177_0x2a024c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a024cULL ^ (static_cast<uint64_t>(0xd10783ffULL) << 13);
    acc = (acc + a1 + 0xaa1e03e4ULL) ^ 0x0f6258ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1178 | PC: 0x2a0af0 | FDE: 0x0f6390 | Size: 256 bytes
// Khung tháo gỡ #1178 | Địa chỉ PC: 0x2a0af0 | Địa chỉ FDE: 0x0f6390 | Kích thước: 256 bytes
//   0x2a0af0: B00005C8  adrp     x8, #0x359000
//   0x2a0af4: 910CA108  add      x8, x8, #0x328
//   0x2a0af8: 14020BEE  b        #0x323ab0
//   0x2a0afc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
static inline uint64_t fde_func_1178_0x2a0af0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a0af0ULL ^ (static_cast<uint64_t>(0xb00005c8ULL) << 13);
    acc = (acc + a1 + 0x910ca108ULL) ^ 0x0f6390ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1179 | PC: 0x2a0f88 | FDE: 0x0f64d8 | Size: 256 bytes
// Khung tháo gỡ #1179 | Địa chỉ PC: 0x2a0f88 | Địa chỉ FDE: 0x0f64d8 | Kích thước: 256 bytes
//   0x2a0f88: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2a0f8c: AA0003F3  mov      x19, x0
//   0x2a0f90: 91016000  add      x0, x0, #0x58
//   0x2a0f94: 97FAE2FB  bl       #0x159b80
static inline uint64_t fde_func_1179_0x2a0f88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a0f88ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0f64d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1180 | PC: 0x2a14a4 | FDE: 0x0f6620 | Size: 256 bytes
// Khung tháo gỡ #1180 | Địa chỉ PC: 0x2a14a4 | Địa chỉ FDE: 0x0f6620 | Kích thước: 256 bytes
//   0x2a14a4: D10143FF  sub      sp, sp, #0x50
//   0x2a14a8: F90013F6  str      x22, [sp, #0x20]
//   0x2a14ac: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x2a14b0: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1180_0x2a14a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a14a4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x0f6620ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1181 | PC: 0x2a1ddc | FDE: 0x0f6760 | Size: 256 bytes
// Khung tháo gỡ #1181 | Địa chỉ PC: 0x2a1ddc | Địa chỉ FDE: 0x0f6760 | Kích thước: 256 bytes
//   0x2a1ddc: D10183FF  sub      sp, sp, #0x60
//   0x2a1de0: F90023F4  str      x20, [sp, #0x40]
//   0x2a1de4: A9057BF3  stp      x19, x30, [sp, #0x50]
//   0x2a1de8: 9401EF19  bl       #0x31da4c
static inline uint64_t fde_func_1181_0x2a1ddc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a1ddcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90023f4ULL) ^ 0x0f6760ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1182 | PC: 0x2a267c | FDE: 0x0f68a8 | Size: 256 bytes
// Khung tháo gỡ #1182 | Địa chỉ PC: 0x2a267c | Địa chỉ FDE: 0x0f68a8 | Kích thước: 256 bytes
//   0x2a267c: AA1E03E3  mov      x3, x30
//   0x2a2680: 9401EFC3  bl       #0x31e58c
//   0x2a2684: AA0303FE  mov      x30, x3
//   0x2a2688: A9107BFD  stp      x29, x30, [sp, #0x100]
static inline uint64_t fde_func_1182_0x2a267c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a267cULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x9401efc3ULL) ^ 0x0f68a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1183 | PC: 0x2a2878 | FDE: 0x0f68d8 | Size: 256 bytes [_ZN4lynx5piper21QuickjsContextWrapperC2ENSt6__ndk110shared_ptrINS0_10VMInstanceEEE]
// Khung tháo gỡ #1183 | Địa chỉ PC: 0x2a2878 | Địa chỉ FDE: 0x0f68d8 | Kích thước: 256 bytes
//   0x2a2878: D10203FF  sub      sp, sp, #0x80
//   0x2a287c: F9002BF6  str      x22, [sp, #0x50]
//   0x2a2880: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x2a2884: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1183_0x2a2878(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a2878ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf6ULL) ^ 0x0f68d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1184 | PC: 0x2a299c | FDE: 0x0f68f8 | Size: 128 bytes [_ZN4lynx5piper21QuickjsContextWrapper16RegisterWasmFuncEv]
// Khung tháo gỡ #1184 | Địa chỉ PC: 0x2a299c | Địa chỉ FDE: 0x0f68f8 | Kích thước: 128 bytes
//   0x2a299c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x2a29a0: B0000648  adrp     x8, #0x36b000
//   0x2a29a4: 9113A108  add      x8, x8, #0x4e8
//   0x2a29a8: 08DFFD08  ldarb    w8, [x8]
static inline uint64_t fde_func_1184_0x2a299c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a299cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb0000648ULL) ^ 0x0f68f8ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1185 | PC: 0x2a2a1c | FDE: 0x0f6928 | Size: 160 bytes [_ZN4lynx5piper21QuickjsContextWrapperD2Ev]
// Khung tháo gỡ #1185 | Địa chỉ PC: 0x2a2a1c | Địa chỉ FDE: 0x0f6928 | Kích thước: 160 bytes
//   0x2a2a1c: D101C3FF  sub      sp, sp, #0x70
//   0x2a2a20: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x2a2a24: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x2a2a28: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1185_0x2a2a1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a2a1cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90553f5ULL) ^ 0x0f6928ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1186 | PC: 0x2a2abc | FDE: 0x0f6948 | Size: 168 bytes [_ZN4lynx5piper21QuickjsContextWrapperD0Ev]
// Khung tháo gỡ #1186 | Địa chỉ PC: 0x2a2abc | Địa chỉ FDE: 0x0f6948 | Kích thước: 168 bytes
//   0x2a2abc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2a2ac0: AA0003F3  mov      x19, x0
//   0x2a2ac4: 94027D9B  bl       #0x342130
//   0x2a2ac8: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1186_0x2a2abc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a2abcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0f6948ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1187 | PC: 0x2a2b64 | FDE: 0x0f6998 | Size: 52 bytes [_ZNK4lynx5piper21QuickjsContextWrapper10getRuntimeEv]
// Khung tháo gỡ #1187 | Địa chỉ PC: 0x2a2b64 | Địa chỉ FDE: 0x0f6998 | Kích thước: 52 bytes
//   0x2a2b64: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2a2b68: AA0003E8  mov      x8, x0
//   0x2a2b6c: F9401000  ldr      x0, [x0, #0x20]
//   0x2a2b70: F9400D08  ldr      x8, [x8, #0x18]
static inline uint64_t fde_func_1187_0x2a2b64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a2b64ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x0f6998ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1188 | PC: 0x2a2b98 | FDE: 0x0f69b0 | Size: 8 bytes [_ZNK4lynx5piper21QuickjsContextWrapper10getContextEv]
// Khung tháo gỡ #1188 | Địa chỉ PC: 0x2a2b98 | Địa chỉ FDE: 0x0f69b0 | Kích thước: 8 bytes
//   0x2a2b98: F9401C00  ldr      x0, [x0, #0x38]
//   0x2a2b9c: D65F03C0  ret      
static inline uint64_t fde_func_1188_0x2a2b98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a2b98ULL ^ (static_cast<uint64_t>(0xf9401c00ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0f69b0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1189 | PC: 0x2a2ba0 | FDE: 0x0f69c8 | Size: 256 bytes
// Khung tháo gỡ #1189 | Địa chỉ PC: 0x2a2ba0 | Địa chỉ FDE: 0x0f69c8 | Kích thước: 256 bytes
//   0x2a2ba0: D10283FF  sub      sp, sp, #0xa0
//   0x2a2ba4: F90043F4  str      x20, [sp, #0x80]
//   0x2a2ba8: A9097BF3  stp      x19, x30, [sp, #0x90]
//   0x2a2bac: 9401EBA8  bl       #0x31da4c
static inline uint64_t fde_func_1189_0x2a2ba0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a2ba0ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90043f4ULL) ^ 0x0f69c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1190 | PC: 0x2a2dfc | FDE: 0x0f6ad0 | Size: 256 bytes
// Khung tháo gỡ #1190 | Địa chỉ PC: 0x2a2dfc | Địa chỉ FDE: 0x0f6ad0 | Kích thước: 256 bytes
//   0x2a2dfc: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x2a2e00: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2a2e04: 94023FEA  bl       #0x332dac
//   0x2a2e08: 94027CE2  bl       #0x342190
static inline uint64_t fde_func_1190_0x2a2dfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a2dfcULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f6ad0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1191 | PC: 0x2a3484 | FDE: 0x0f6c00 | Size: 256 bytes
// Khung tháo gỡ #1191 | Địa chỉ PC: 0x2a3484 | Địa chỉ FDE: 0x0f6c00 | Kích thước: 256 bytes
//   0x2a3484: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2a3488: B40000E1  cbz      x1, #0x2a34a4
//   0x2a348c: 9401FA85  bl       #0x321ea0
//   0x2a3490: B40000A8  cbz      x8, #0x2a34a4
static inline uint64_t fde_func_1191_0x2a3484(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a3484ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb40000e1ULL) ^ 0x0f6c00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1192 | PC: 0x2a3bc8 | FDE: 0x0f6d18 | Size: 256 bytes
// Khung tháo gỡ #1192 | Địa chỉ PC: 0x2a3bc8 | Địa chỉ FDE: 0x0f6d18 | Kích thước: 256 bytes
//   0x2a3bc8: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x2a3bcc: 94025757  bl       #0x339928
//   0x2a3bd0: 39400008  ldrb     w8, [x0]
//   0x2a3bd4: 36000068  tbz      w8, #0, #0x2a3be0
static inline uint64_t fde_func_1192_0x2a3bc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a3bc8ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x94025757ULL) ^ 0x0f6d18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1193 | PC: 0x2a3df4 | FDE: 0x0f6e38 | Size: 256 bytes
// Khung tháo gỡ #1193 | Địa chỉ PC: 0x2a3df4 | Địa chỉ FDE: 0x0f6e38 | Kích thước: 256 bytes
//   0x2a3df4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2a3df8: AA0003F3  mov      x19, x0
//   0x2a3dfc: 97FFFFEA  bl       #0x2a3da4
//   0x2a3e00: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1193_0x2a3df4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a3df4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0f6e38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1194 | PC: 0x2a472c | FDE: 0x0f6f70 | Size: 256 bytes
// Khung tháo gỡ #1194 | Địa chỉ PC: 0x2a472c | Địa chỉ FDE: 0x0f6f70 | Kích thước: 256 bytes
//   0x2a472c: D103C3FF  sub      sp, sp, #0xf0
//   0x2a4730: AA1E03E4  mov      x4, x30
//   0x2a4734: 9401EE90  bl       #0x320174
//   0x2a4738: AA0403FE  mov      x30, x4
static inline uint64_t fde_func_1194_0x2a472c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a472cULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xaa1e03e4ULL) ^ 0x0f6f70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1195 | PC: 0x2a4c88 | FDE: 0x0f7098 | Size: 256 bytes
// Khung tháo gỡ #1195 | Địa chỉ PC: 0x2a4c88 | Địa chỉ FDE: 0x0f7098 | Kích thước: 256 bytes
//   0x2a4c88: F9409009  ldr      x9, [x0, #0x120]
//   0x2a4c8c: F9000109  str      x9, [x8]
//   0x2a4c90: F9409409  ldr      x9, [x0, #0x128]
//   0x2a4c94: F9000509  str      x9, [x8, #8]
static inline uint64_t fde_func_1195_0x2a4c88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a4c88ULL ^ (static_cast<uint64_t>(0xf9409009ULL) << 13);
    acc = (acc + a1 + 0xf9000109ULL) ^ 0x0f7098ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1196 | PC: 0x2a5ce8 | FDE: 0x0f71f8 | Size: 256 bytes
// Khung tháo gỡ #1196 | Địa chỉ PC: 0x2a5ce8 | Địa chỉ FDE: 0x0f71f8 | Kích thước: 256 bytes
//   0x2a5ce8: 140262FD  b        #0x33e8dc
//   0x2a5cec: D10183FF  sub      sp, sp, #0x60
//   0x2a5cf0: F9001BF6  str      x22, [sp, #0x30]
//   0x2a5cf4: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_1196_0x2a5ce8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a5ce8ULL ^ (static_cast<uint64_t>(0x140262fdULL) << 13);
    acc = (acc + a1 + 0xd10183ffULL) ^ 0x0f71f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1197 | PC: 0x2a6090 | FDE: 0x0f7320 | Size: 256 bytes
// Khung tháo gỡ #1197 | Địa chỉ PC: 0x2a6090 | Địa chỉ FDE: 0x0f7320 | Kích thước: 256 bytes
//   0x2a6090: F9400009  ldr      x9, [x0]
//   0x2a6094: F9409523  ldr      x3, [x9, #0x128]
//   0x2a6098: D61F0060  br       x3
//   0x2a609c: F81E0FF4  str      x20, [sp, #-0x20]!
static inline uint64_t fde_func_1197_0x2a6090(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a6090ULL ^ (static_cast<uint64_t>(0xf9400009ULL) << 13);
    acc = (acc + a1 + 0xf9409523ULL) ^ 0x0f7320ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1198 | PC: 0x2a6880 | FDE: 0x0f7458 | Size: 256 bytes
// Khung tháo gỡ #1198 | Địa chỉ PC: 0x2a6880 | Địa chỉ FDE: 0x0f7458 | Kích thước: 256 bytes
//   0x2a6880: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x2a6884: 94024C19  bl       #0x3398e8
//   0x2a6888: 94026EB6  bl       #0x342360
//   0x2a688c: 7100001F  cmp      w0, #0
static inline uint64_t fde_func_1198_0x2a6880(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a6880ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x94024c19ULL) ^ 0x0f7458ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1199 | PC: 0x2a6f88 | FDE: 0x0f7588 | Size: 256 bytes
// Khung tháo gỡ #1199 | Địa chỉ PC: 0x2a6f88 | Địa chỉ FDE: 0x0f7588 | Kích thước: 256 bytes
//   0x2a6f88: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x2a6f8c: F9400028  ldr      x8, [x1]
//   0x2a6f90: F9409009  ldr      x9, [x0, #0x120]
//   0x2a6f94: 90FFEE22  adrp     x2, #0x6a000
static inline uint64_t fde_func_1199_0x2a6f88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a6f88ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400028ULL) ^ 0x0f7588ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Shard 3 Dispatcher / Bộ điều phối phân mảnh 3
uint64_t execute_fde_shard_3(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 800: return fde_func_0800_0x22bbc8(a0, a1);
        case 801: return fde_func_0801_0x22bc64(a0, a1);
        case 802: return fde_func_0802_0x22bf54(a0, a1);
        case 803: return fde_func_0803_0x22c21c(a0, a1);
        case 804: return fde_func_0804_0x22c478(a0, a1);
        case 805: return fde_func_0805_0x22c658(a0, a1);
        case 806: return fde_func_0806_0x22c84c(a0, a1);
        case 807: return fde_func_0807_0x22ca3c(a0, a1);
        case 808: return fde_func_0808_0x22cca8(a0, a1);
        case 809: return fde_func_0809_0x22ce28(a0, a1);
        case 810: return fde_func_0810_0x22d284(a0, a1);
        case 811: return fde_func_0811_0x22d418(a0, a1);
        case 812: return fde_func_0812_0x22d66c(a0, a1);
        case 813: return fde_func_0813_0x22dce0(a0, a1);
        case 814: return fde_func_0814_0x22e3d8(a0, a1);
        case 815: return fde_func_0815_0x22e9f0(a0, a1);
        case 816: return fde_func_0816_0x22f058(a0, a1);
        case 817: return fde_func_0817_0x22f350(a0, a1);
        case 818: return fde_func_0818_0x22fad8(a0, a1);
        case 819: return fde_func_0819_0x230630(a0, a1);
        case 820: return fde_func_0820_0x231240(a0, a1);
        case 821: return fde_func_0821_0x231970(a0, a1);
        case 822: return fde_func_0822_0x231cf8(a0, a1);
        case 823: return fde_func_0823_0x231e98(a0, a1);
        case 824: return fde_func_0824_0x2320cc(a0, a1);
        case 825: return fde_func_0825_0x2322b0(a0, a1);
        case 826: return fde_func_0826_0x232534(a0, a1);
        case 827: return fde_func_0827_0x233a80(a0, a1);
        case 828: return fde_func_0828_0x233c08(a0, a1);
        case 829: return fde_func_0829_0x233de4(a0, a1);
        case 830: return fde_func_0830_0x234084(a0, a1);
        case 831: return fde_func_0831_0x23449c(a0, a1);
        case 832: return fde_func_0832_0x234948(a0, a1);
        case 833: return fde_func_0833_0x234e74(a0, a1);
        case 834: return fde_func_0834_0x235040(a0, a1);
        case 835: return fde_func_0835_0x235240(a0, a1);
        case 836: return fde_func_0836_0x235550(a0, a1);
        case 837: return fde_func_0837_0x2357c8(a0, a1);
        case 838: return fde_func_0838_0x235b18(a0, a1);
        case 839: return fde_func_0839_0x235dd0(a0, a1);
        case 840: return fde_func_0840_0x235f64(a0, a1);
        case 841: return fde_func_0841_0x23637c(a0, a1);
        case 842: return fde_func_0842_0x2365ac(a0, a1);
        case 843: return fde_func_0843_0x2367f8(a0, a1);
        case 844: return fde_func_0844_0x236b78(a0, a1);
        case 845: return fde_func_0845_0x236fc4(a0, a1);
        case 846: return fde_func_0846_0x2371a8(a0, a1);
        case 847: return fde_func_0847_0x237440(a0, a1);
        case 848: return fde_func_0848_0x23763c(a0, a1);
        case 849: return fde_func_0849_0x237a08(a0, a1);
        case 850: return fde_func_0850_0x237b84(a0, a1);
        case 851: return fde_func_0851_0x23808c(a0, a1);
        case 852: return fde_func_0852_0x238124(a0, a1);
        case 853: return fde_func_0853_0x238214(a0, a1);
        case 854: return fde_func_0854_0x238260(a0, a1);
        case 855: return fde_func_0855_0x2382c8(a0, a1);
        case 856: return fde_func_0856_0x238580(a0, a1);
        case 857: return fde_func_0857_0x2387bc(a0, a1);
        case 858: return fde_func_0858_0x238a5c(a0, a1);
        case 859: return fde_func_0859_0x238af0(a0, a1);
        case 860: return fde_func_0860_0x238b60(a0, a1);
        case 861: return fde_func_0861_0x238e68(a0, a1);
        case 862: return fde_func_0862_0x239c34(a0, a1);
        case 863: return fde_func_0863_0x239e3c(a0, a1);
        case 864: return fde_func_0864_0x239f6c(a0, a1);
        case 865: return fde_func_0865_0x239fb0(a0, a1);
        case 866: return fde_func_0866_0x23a014(a0, a1);
        case 867: return fde_func_0867_0x23a158(a0, a1);
        case 868: return fde_func_0868_0x23a414(a0, a1);
        case 869: return fde_func_0869_0x23a464(a0, a1);
        case 870: return fde_func_0870_0x23a46c(a0, a1);
        case 871: return fde_func_0871_0x23a474(a0, a1);
        case 872: return fde_func_0872_0x23a4a4(a0, a1);
        case 873: return fde_func_0873_0x23a4d4(a0, a1);
        case 874: return fde_func_0874_0x23a510(a0, a1);
        case 875: return fde_func_0875_0x23a518(a0, a1);
        case 876: return fde_func_0876_0x23a520(a0, a1);
        case 877: return fde_func_0877_0x23a528(a0, a1);
        case 878: return fde_func_0878_0x23a558(a0, a1);
        case 879: return fde_func_0879_0x23a568(a0, a1);
        case 880: return fde_func_0880_0x23a570(a0, a1);
        case 881: return fde_func_0881_0x23a578(a0, a1);
        case 882: return fde_func_0882_0x23a580(a0, a1);
        case 883: return fde_func_0883_0x23a588(a0, a1);
        case 884: return fde_func_0884_0x23a590(a0, a1);
        case 885: return fde_func_0885_0x23a598(a0, a1);
        case 886: return fde_func_0886_0x23a5a0(a0, a1);
        case 887: return fde_func_0887_0x23a5a8(a0, a1);
        case 888: return fde_func_0888_0x23a5c0(a0, a1);
        case 889: return fde_func_0889_0x23a5d8(a0, a1);
        case 890: return fde_func_0890_0x23a5f0(a0, a1);
        case 891: return fde_func_0891_0x23a604(a0, a1);
        case 892: return fde_func_0892_0x23a61c(a0, a1);
        case 893: return fde_func_0893_0x23a634(a0, a1);
        case 894: return fde_func_0894_0x23a63c(a0, a1);
        case 895: return fde_func_0895_0x23a644(a0, a1);
        case 896: return fde_func_0896_0x23a64c(a0, a1);
        case 897: return fde_func_0897_0x23a654(a0, a1);
        case 898: return fde_func_0898_0x23a6a8(a0, a1);
        case 899: return fde_func_0899_0x23a6b8(a0, a1);
        case 900: return fde_func_0900_0x23a710(a0, a1);
        case 901: return fde_func_0901_0x23a728(a0, a1);
        case 902: return fde_func_0902_0x23a730(a0, a1);
        case 903: return fde_func_0903_0x23a788(a0, a1);
        case 904: return fde_func_0904_0x23a790(a0, a1);
        case 905: return fde_func_0905_0x23a798(a0, a1);
        case 906: return fde_func_0906_0x23a7a0(a0, a1);
        case 907: return fde_func_0907_0x23a7a8(a0, a1);
        case 908: return fde_func_0908_0x23a7b0(a0, a1);
        case 909: return fde_func_0909_0x23a7b8(a0, a1);
        case 910: return fde_func_0910_0x23a7c0(a0, a1);
        case 911: return fde_func_0911_0x23a7d4(a0, a1);
        case 912: return fde_func_0912_0x23a7dc(a0, a1);
        case 913: return fde_func_0913_0x23a7e4(a0, a1);
        case 914: return fde_func_0914_0x23a7ec(a0, a1);
        case 915: return fde_func_0915_0x23a7f4(a0, a1);
        case 916: return fde_func_0916_0x23a7fc(a0, a1);
        case 917: return fde_func_0917_0x23a804(a0, a1);
        case 918: return fde_func_0918_0x23a80c(a0, a1);
        case 919: return fde_func_0919_0x23a864(a0, a1);
        case 920: return fde_func_0920_0x23a8bc(a0, a1);
        case 921: return fde_func_0921_0x23a8c4(a0, a1);
        case 922: return fde_func_0922_0x23a8cc(a0, a1);
        case 923: return fde_func_0923_0x23a8d4(a0, a1);
        case 924: return fde_func_0924_0x23a910(a0, a1);
        case 925: return fde_func_0925_0x23a918(a0, a1);
        case 926: return fde_func_0926_0x23a920(a0, a1);
        case 927: return fde_func_0927_0x23a928(a0, a1);
        case 928: return fde_func_0928_0x23a930(a0, a1);
        case 929: return fde_func_0929_0x23a938(a0, a1);
        case 930: return fde_func_0930_0x23a940(a0, a1);
        case 931: return fde_func_0931_0x23a998(a0, a1);
        case 932: return fde_func_0932_0x23a9f0(a0, a1);
        case 933: return fde_func_0933_0x23aa48(a0, a1);
        case 934: return fde_func_0934_0x23aaa0(a0, a1);
        case 935: return fde_func_0935_0x23aaf8(a0, a1);
        case 936: return fde_func_0936_0x23ab50(a0, a1);
        case 937: return fde_func_0937_0x23aba8(a0, a1);
        case 938: return fde_func_0938_0x23ac00(a0, a1);
        case 939: return fde_func_0939_0x23ac70(a0, a1);
        case 940: return fde_func_0940_0x23ac78(a0, a1);
        case 941: return fde_func_0941_0x23acd0(a0, a1);
        case 942: return fde_func_0942_0x23acd8(a0, a1);
        case 943: return fde_func_0943_0x23ad14(a0, a1);
        case 944: return fde_func_0944_0x23ad44(a0, a1);
        case 945: return fde_func_0945_0x23b030(a0, a1);
        case 946: return fde_func_0946_0x23b51c(a0, a1);
        case 947: return fde_func_0947_0x23be8c(a0, a1);
        case 948: return fde_func_0948_0x23c1e0(a0, a1);
        case 949: return fde_func_0949_0x23c920(a0, a1);
        case 950: return fde_func_0950_0x23cffc(a0, a1);
        case 951: return fde_func_0951_0x23d58c(a0, a1);
        case 952: return fde_func_0952_0x23dbf0(a0, a1);
        case 953: return fde_func_0953_0x23e3f4(a0, a1);
        case 954: return fde_func_0954_0x23ef1c(a0, a1);
        case 955: return fde_func_0955_0x23f57c(a0, a1);
        case 956: return fde_func_0956_0x23fd68(a0, a1);
        case 957: return fde_func_0957_0x240370(a0, a1);
        case 958: return fde_func_0958_0x2408e4(a0, a1);
        case 959: return fde_func_0959_0x241374(a0, a1);
        case 960: return fde_func_0960_0x242100(a0, a1);
        case 961: return fde_func_0961_0x2426b4(a0, a1);
        case 962: return fde_func_0962_0x242a7c(a0, a1);
        case 963: return fde_func_0963_0x243204(a0, a1);
        case 964: return fde_func_0964_0x2436b8(a0, a1);
        case 965: return fde_func_0965_0x243c64(a0, a1);
        case 966: return fde_func_0966_0x244188(a0, a1);
        case 967: return fde_func_0967_0x244960(a0, a1);
        case 968: return fde_func_0968_0x244bd0(a0, a1);
        case 969: return fde_func_0969_0x244d98(a0, a1);
        case 970: return fde_func_0970_0x244dec(a0, a1);
        case 971: return fde_func_0971_0x245584(a0, a1);
        case 972: return fde_func_0972_0x245dd8(a0, a1);
        case 973: return fde_func_0973_0x2463a8(a0, a1);
        case 974: return fde_func_0974_0x2465fc(a0, a1);
        case 975: return fde_func_0975_0x246da4(a0, a1);
        case 976: return fde_func_0976_0x2477ac(a0, a1);
        case 977: return fde_func_0977_0x2486bc(a0, a1);
        case 978: return fde_func_0978_0x2495ac(a0, a1);
        case 979: return fde_func_0979_0x249784(a0, a1);
        case 980: return fde_func_0980_0x249834(a0, a1);
        case 981: return fde_func_0981_0x249ac4(a0, a1);
        case 982: return fde_func_0982_0x24a0c0(a0, a1);
        case 983: return fde_func_0983_0x24a668(a0, a1);
        case 984: return fde_func_0984_0x24aa34(a0, a1);
        case 985: return fde_func_0985_0x24b074(a0, a1);
        case 986: return fde_func_0986_0x24b1e0(a0, a1);
        case 987: return fde_func_0987_0x24b230(a0, a1);
        case 988: return fde_func_0988_0x24b43c(a0, a1);
        case 989: return fde_func_0989_0x24b738(a0, a1);
        case 990: return fde_func_0990_0x24bb78(a0, a1);
        case 991: return fde_func_0991_0x24bbe0(a0, a1);
        case 992: return fde_func_0992_0x24bf5c(a0, a1);
        case 993: return fde_func_0993_0x24cae0(a0, a1);
        case 994: return fde_func_0994_0x24e604(a0, a1);
        case 995: return fde_func_0995_0x24eafc(a0, a1);
        case 996: return fde_func_0996_0x24f618(a0, a1);
        case 997: return fde_func_0997_0x24fa24(a0, a1);
        case 998: return fde_func_0998_0x24fe04(a0, a1);
        case 999: return fde_func_0999_0x2502b8(a0, a1);
        case 1000: return fde_func_1000_0x250d78(a0, a1);
        case 1001: return fde_func_1001_0x2516a4(a0, a1);
        case 1002: return fde_func_1002_0x251fa8(a0, a1);
        case 1003: return fde_func_1003_0x2523f4(a0, a1);
        case 1004: return fde_func_1004_0x252840(a0, a1);
        case 1005: return fde_func_1005_0x252ab8(a0, a1);
        case 1006: return fde_func_1006_0x252e54(a0, a1);
        case 1007: return fde_func_1007_0x25399c(a0, a1);
        case 1008: return fde_func_1008_0x2543a8(a0, a1);
        case 1009: return fde_func_1009_0x254890(a0, a1);
        case 1010: return fde_func_1010_0x254bb4(a0, a1);
        case 1011: return fde_func_1011_0x2556b8(a0, a1);
        case 1012: return fde_func_1012_0x255b6c(a0, a1);
        case 1013: return fde_func_1013_0x255e78(a0, a1);
        case 1014: return fde_func_1014_0x2562e8(a0, a1);
        case 1015: return fde_func_1015_0x2565f4(a0, a1);
        case 1016: return fde_func_1016_0x256bac(a0, a1);
        case 1017: return fde_func_1017_0x257744(a0, a1);
        case 1018: return fde_func_1018_0x257bc8(a0, a1);
        case 1019: return fde_func_1019_0x258260(a0, a1);
        case 1020: return fde_func_1020_0x258810(a0, a1);
        case 1021: return fde_func_1021_0x258ef8(a0, a1);
        case 1022: return fde_func_1022_0x25959c(a0, a1);
        case 1023: return fde_func_1023_0x259960(a0, a1);
        case 1024: return fde_func_1024_0x25a1a0(a0, a1);
        case 1025: return fde_func_1025_0x25a598(a0, a1);
        case 1026: return fde_func_1026_0x25a998(a0, a1);
        case 1027: return fde_func_1027_0x25aac4(a0, a1);
        case 1028: return fde_func_1028_0x25ab40(a0, a1);
        case 1029: return fde_func_1029_0x25b078(a0, a1);
        case 1030: return fde_func_1030_0x25ba50(a0, a1);
        case 1031: return fde_func_1031_0x25bc80(a0, a1);
        case 1032: return fde_func_1032_0x25be9c(a0, a1);
        case 1033: return fde_func_1033_0x25ca14(a0, a1);
        case 1034: return fde_func_1034_0x25d298(a0, a1);
        case 1035: return fde_func_1035_0x25eee8(a0, a1);
        case 1036: return fde_func_1036_0x25f20c(a0, a1);
        case 1037: return fde_func_1037_0x25f444(a0, a1);
        case 1038: return fde_func_1038_0x25f7e8(a0, a1);
        case 1039: return fde_func_1039_0x26109c(a0, a1);
        case 1040: return fde_func_1040_0x26140c(a0, a1);
        case 1041: return fde_func_1041_0x2616dc(a0, a1);
        case 1042: return fde_func_1042_0x261f68(a0, a1);
        case 1043: return fde_func_1043_0x262a9c(a0, a1);
        case 1044: return fde_func_1044_0x262e00(a0, a1);
        case 1045: return fde_func_1045_0x2631a4(a0, a1);
        case 1046: return fde_func_1046_0x263d0c(a0, a1);
        case 1047: return fde_func_1047_0x263e7c(a0, a1);
        case 1048: return fde_func_1048_0x2642c4(a0, a1);
        case 1049: return fde_func_1049_0x264360(a0, a1);
        case 1050: return fde_func_1050_0x264428(a0, a1);
        case 1051: return fde_func_1051_0x265a98(a0, a1);
        case 1052: return fde_func_1052_0x266804(a0, a1);
        case 1053: return fde_func_1053_0x2669dc(a0, a1);
        case 1054: return fde_func_1054_0x267464(a0, a1);
        case 1055: return fde_func_1055_0x267764(a0, a1);
        case 1056: return fde_func_1056_0x267c98(a0, a1);
        case 1057: return fde_func_1057_0x268358(a0, a1);
        case 1058: return fde_func_1058_0x2697a4(a0, a1);
        case 1059: return fde_func_1059_0x269f10(a0, a1);
        case 1060: return fde_func_1060_0x26a228(a0, a1);
        case 1061: return fde_func_1061_0x26addc(a0, a1);
        case 1062: return fde_func_1062_0x26b044(a0, a1);
        case 1063: return fde_func_1063_0x26b770(a0, a1);
        case 1064: return fde_func_1064_0x26ced0(a0, a1);
        case 1065: return fde_func_1065_0x26d8e0(a0, a1);
        case 1066: return fde_func_1066_0x26e0b4(a0, a1);
        case 1067: return fde_func_1067_0x26ec74(a0, a1);
        case 1068: return fde_func_1068_0x27021c(a0, a1);
        case 1069: return fde_func_1069_0x271860(a0, a1);
        case 1070: return fde_func_1070_0x272c74(a0, a1);
        case 1071: return fde_func_1071_0x2734f4(a0, a1);
        case 1072: return fde_func_1072_0x274834(a0, a1);
        case 1073: return fde_func_1073_0x275d68(a0, a1);
        case 1074: return fde_func_1074_0x275eec(a0, a1);
        case 1075: return fde_func_1075_0x2770dc(a0, a1);
        case 1076: return fde_func_1076_0x2777c8(a0, a1);
        case 1077: return fde_func_1077_0x278520(a0, a1);
        case 1078: return fde_func_1078_0x278cc8(a0, a1);
        case 1079: return fde_func_1079_0x279a94(a0, a1);
        case 1080: return fde_func_1080_0x27a540(a0, a1);
        case 1081: return fde_func_1081_0x27a94c(a0, a1);
        case 1082: return fde_func_1082_0x27ae48(a0, a1);
        case 1083: return fde_func_1083_0x27b9c4(a0, a1);
        case 1084: return fde_func_1084_0x27d794(a0, a1);
        case 1085: return fde_func_1085_0x27df38(a0, a1);
        case 1086: return fde_func_1086_0x27ea54(a0, a1);
        case 1087: return fde_func_1087_0x27f684(a0, a1);
        case 1088: return fde_func_1088_0x27fedc(a0, a1);
        case 1089: return fde_func_1089_0x2803f8(a0, a1);
        case 1090: return fde_func_1090_0x2809c0(a0, a1);
        case 1091: return fde_func_1091_0x280b7c(a0, a1);
        case 1092: return fde_func_1092_0x281064(a0, a1);
        case 1093: return fde_func_1093_0x281690(a0, a1);
        case 1094: return fde_func_1094_0x2819c0(a0, a1);
        case 1095: return fde_func_1095_0x282258(a0, a1);
        case 1096: return fde_func_1096_0x2823e8(a0, a1);
        case 1097: return fde_func_1097_0x282578(a0, a1);
        case 1098: return fde_func_1098_0x282700(a0, a1);
        case 1099: return fde_func_1099_0x28389c(a0, a1);
        case 1100: return fde_func_1100_0x283a2c(a0, a1);
        case 1101: return fde_func_1101_0x283bbc(a0, a1);
        case 1102: return fde_func_1102_0x283d4c(a0, a1);
        case 1103: return fde_func_1103_0x283edc(a0, a1);
        case 1104: return fde_func_1104_0x28406c(a0, a1);
        case 1105: return fde_func_1105_0x2841fc(a0, a1);
        case 1106: return fde_func_1106_0x28438c(a0, a1);
        case 1107: return fde_func_1107_0x28451c(a0, a1);
        case 1108: return fde_func_1108_0x2846ac(a0, a1);
        case 1109: return fde_func_1109_0x28483c(a0, a1);
        case 1110: return fde_func_1110_0x2849cc(a0, a1);
        case 1111: return fde_func_1111_0x284b5c(a0, a1);
        case 1112: return fde_func_1112_0x284cec(a0, a1);
        case 1113: return fde_func_1113_0x284e7c(a0, a1);
        case 1114: return fde_func_1114_0x28500c(a0, a1);
        case 1115: return fde_func_1115_0x28519c(a0, a1);
        case 1116: return fde_func_1116_0x285990(a0, a1);
        case 1117: return fde_func_1117_0x285ef8(a0, a1);
        case 1118: return fde_func_1118_0x2864e0(a0, a1);
        case 1119: return fde_func_1119_0x286ddc(a0, a1);
        case 1120: return fde_func_1120_0x287990(a0, a1);
        case 1121: return fde_func_1121_0x288570(a0, a1);
        case 1122: return fde_func_1122_0x288ce8(a0, a1);
        case 1123: return fde_func_1123_0x2898b4(a0, a1);
        case 1124: return fde_func_1124_0x28a71c(a0, a1);
        case 1125: return fde_func_1125_0x28ad3c(a0, a1);
        case 1126: return fde_func_1126_0x28b84c(a0, a1);
        case 1127: return fde_func_1127_0x28bea8(a0, a1);
        case 1128: return fde_func_1128_0x28c518(a0, a1);
        case 1129: return fde_func_1129_0x28d0d8(a0, a1);
        case 1130: return fde_func_1130_0x28d99c(a0, a1);
        case 1131: return fde_func_1131_0x28e0c0(a0, a1);
        case 1132: return fde_func_1132_0x28e944(a0, a1);
        case 1133: return fde_func_1133_0x28f314(a0, a1);
        case 1134: return fde_func_1134_0x2901ac(a0, a1);
        case 1135: return fde_func_1135_0x290d48(a0, a1);
        case 1136: return fde_func_1136_0x29177c(a0, a1);
        case 1137: return fde_func_1137_0x291c94(a0, a1);
        case 1138: return fde_func_1138_0x2929c0(a0, a1);
        case 1139: return fde_func_1139_0x293144(a0, a1);
        case 1140: return fde_func_1140_0x293b6c(a0, a1);
        case 1141: return fde_func_1141_0x294768(a0, a1);
        case 1142: return fde_func_1142_0x294d8c(a0, a1);
        case 1143: return fde_func_1143_0x2953d4(a0, a1);
        case 1144: return fde_func_1144_0x295b98(a0, a1);
        case 1145: return fde_func_1145_0x2961a4(a0, a1);
        case 1146: return fde_func_1146_0x296798(a0, a1);
        case 1147: return fde_func_1147_0x296cdc(a0, a1);
        case 1148: return fde_func_1148_0x296de0(a0, a1);
        case 1149: return fde_func_1149_0x296e2c(a0, a1);
        case 1150: return fde_func_1150_0x297358(a0, a1);
        case 1151: return fde_func_1151_0x2976c8(a0, a1);
        case 1152: return fde_func_1152_0x2976cc(a0, a1);
        case 1153: return fde_func_1153_0x2976d0(a0, a1);
        case 1154: return fde_func_1154_0x297a44(a0, a1);
        case 1155: return fde_func_1155_0x297aa0(a0, a1);
        case 1156: return fde_func_1156_0x297b3c(a0, a1);
        case 1157: return fde_func_1157_0x297b70(a0, a1);
        case 1158: return fde_func_1158_0x297b88(a0, a1);
        case 1159: return fde_func_1159_0x297bcc(a0, a1);
        case 1160: return fde_func_1160_0x297d8c(a0, a1);
        case 1161: return fde_func_1161_0x297e8c(a0, a1);
        case 1162: return fde_func_1162_0x2988b8(a0, a1);
        case 1163: return fde_func_1163_0x298a9c(a0, a1);
        case 1164: return fde_func_1164_0x299070(a0, a1);
        case 1165: return fde_func_1165_0x299310(a0, a1);
        case 1166: return fde_func_1166_0x299e84(a0, a1);
        case 1167: return fde_func_1167_0x29ac7c(a0, a1);
        case 1168: return fde_func_1168_0x29b030(a0, a1);
        case 1169: return fde_func_1169_0x29cb30(a0, a1);
        case 1170: return fde_func_1170_0x29d7bc(a0, a1);
        case 1171: return fde_func_1171_0x29df58(a0, a1);
        case 1172: return fde_func_1172_0x29eb74(a0, a1);
        case 1173: return fde_func_1173_0x29f270(a0, a1);
        case 1174: return fde_func_1174_0x29fdb8(a0, a1);
        case 1175: return fde_func_1175_0x2a0170(a0, a1);
        case 1176: return fde_func_1176_0x2a01e8(a0, a1);
        case 1177: return fde_func_1177_0x2a024c(a0, a1);
        case 1178: return fde_func_1178_0x2a0af0(a0, a1);
        case 1179: return fde_func_1179_0x2a0f88(a0, a1);
        case 1180: return fde_func_1180_0x2a14a4(a0, a1);
        case 1181: return fde_func_1181_0x2a1ddc(a0, a1);
        case 1182: return fde_func_1182_0x2a267c(a0, a1);
        case 1183: return fde_func_1183_0x2a2878(a0, a1);
        case 1184: return fde_func_1184_0x2a299c(a0, a1);
        case 1185: return fde_func_1185_0x2a2a1c(a0, a1);
        case 1186: return fde_func_1186_0x2a2abc(a0, a1);
        case 1187: return fde_func_1187_0x2a2b64(a0, a1);
        case 1188: return fde_func_1188_0x2a2b98(a0, a1);
        case 1189: return fde_func_1189_0x2a2ba0(a0, a1);
        case 1190: return fde_func_1190_0x2a2dfc(a0, a1);
        case 1191: return fde_func_1191_0x2a3484(a0, a1);
        case 1192: return fde_func_1192_0x2a3bc8(a0, a1);
        case 1193: return fde_func_1193_0x2a3df4(a0, a1);
        case 1194: return fde_func_1194_0x2a472c(a0, a1);
        case 1195: return fde_func_1195_0x2a4c88(a0, a1);
        case 1196: return fde_func_1196_0x2a5ce8(a0, a1);
        case 1197: return fde_func_1197_0x2a6090(a0, a1);
        case 1198: return fde_func_1198_0x2a6880(a0, a1);
        case 1199: return fde_func_1199_0x2a6f88(a0, a1);
        default: return 0ULL;
    }
}

} // namespace lynx