// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 2/5 for liblynx.so
// Phân mảnh Khung Tháo Gỡ (FDE) AArch64 C++17 sạch 2/5 cho liblynx.so
// Covers representative FDE indices [400 .. 799] out of 21,675 total FDEs
// Bao phủ chỉ số FDE đại diện [400 .. 799] trên tổng số 21.675 FDE
// ============================================================================
#include "lynx_core.h"

namespace lynx {

// FDE #0400 | PC: 0x1a7288 | FDE: 0x0c8b60 | Size: 256 bytes
// Khung tháo gỡ #0400 | Địa chỉ PC: 0x1a7288 | Địa chỉ FDE: 0x0c8b60 | Kích thước: 256 bytes
//   0x1a7288: F940B829  ldr      x9, [x1, #0x170]
//   0x1a728c: B40000C9  cbz      x9, #0x1a72a4
//   0x1a7290: F940192A  ldr      x10, [x9, #0x30]
//   0x1a7294: B400010A  cbz      x10, #0x1a72b4
static inline uint64_t fde_func_0400_0x1a7288(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a7288ULL ^ (static_cast<uint64_t>(0xf940b829ULL) << 13);
    acc = (acc + a1 + 0xb40000c9ULL) ^ 0x0c8b60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0401 | PC: 0x1a77f4 | FDE: 0x0c8c88 | Size: 256 bytes
// Khung tháo gỡ #0401 | Địa chỉ PC: 0x1a77f4 | Địa chỉ FDE: 0x0c8c88 | Kích thước: 256 bytes
//   0x1a77f4: BD400440  ldr      s0, [x2, #4]
//   0x1a77f8: 1405F66E  b        #0x3251b0
//   0x1a77fc: AA1E03E3  mov      x3, x30
//   0x1a7800: 9405EF19  bl       #0x323464
static inline uint64_t fde_func_0401_0x1a77f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a77f4ULL ^ (static_cast<uint64_t>(0xbd400440ULL) << 13);
    acc = (acc + a1 + 0x1405f66eULL) ^ 0x0c8c88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0402 | PC: 0x1a7954 | FDE: 0x0c8d98 | Size: 256 bytes
// Khung tháo gỡ #0402 | Địa chỉ PC: 0x1a7954 | Địa chỉ FDE: 0x0c8d98 | Kích thước: 256 bytes
//   0x1a7954: F9405C29  ldr      x9, [x1, #0xb8]
//   0x1a7958: AA0803E0  mov      x0, x8
//   0x1a795c: B4000069  cbz      x9, #0x1a7968
//   0x1a7960: BD400520  ldr      s0, [x9, #4]
static inline uint64_t fde_func_0402_0x1a7954(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a7954ULL ^ (static_cast<uint64_t>(0xf9405c29ULL) << 13);
    acc = (acc + a1 + 0xaa0803e0ULL) ^ 0x0c8d98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0403 | PC: 0x1a7cd8 | FDE: 0x0c8ea8 | Size: 256 bytes
// Khung tháo gỡ #0403 | Địa chỉ PC: 0x1a7cd8 | Địa chỉ FDE: 0x0c8ea8 | Kích thước: 256 bytes
//   0x1a7cd8: F9405C29  ldr      x9, [x1, #0xb8]
//   0x1a7cdc: AA0803E0  mov      x0, x8
//   0x1a7ce0: B4000069  cbz      x9, #0x1a7cec
//   0x1a7ce4: B9407D21  ldr      w1, [x9, #0x7c]
static inline uint64_t fde_func_0403_0x1a7cd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a7cd8ULL ^ (static_cast<uint64_t>(0xf9405c29ULL) << 13);
    acc = (acc + a1 + 0xaa0803e0ULL) ^ 0x0c8ea8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0404 | PC: 0x1a84f8 | FDE: 0x0c8ff0 | Size: 256 bytes
// Khung tháo gỡ #0404 | Địa chỉ PC: 0x1a84f8 | Địa chỉ FDE: 0x0c8ff0 | Kích thước: 256 bytes
//   0x1a84f8: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1a84fc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1a8500: 90000CE8  adrp     x8, #0x344000
//   0x1a8504: 91080108  add      x8, x8, #0x200
static inline uint64_t fde_func_0404_0x1a84f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a84f8ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c8ff0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0405 | PC: 0x1a87f4 | FDE: 0x0c9120 | Size: 256 bytes
// Khung tháo gỡ #0405 | Địa chỉ PC: 0x1a87f4 | Địa chỉ FDE: 0x0c9120 | Kích thước: 256 bytes
//   0x1a87f4: FC190FE8  str      d8, [sp, #-0x70]!
//   0x1a87f8: AA1E03E5  mov      x5, x30
//   0x1a87fc: 9405D5B7  bl       #0x31ded8
//   0x1a8800: AA0503FE  mov      x30, x5
static inline uint64_t fde_func_0405_0x1a87f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a87f4ULL ^ (static_cast<uint64_t>(0xfc190fe8ULL) << 13);
    acc = (acc + a1 + 0xaa1e03e5ULL) ^ 0x0c9120ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0406 | PC: 0x1a96a4 | FDE: 0x0c9248 | Size: 256 bytes
// Khung tháo gỡ #0406 | Địa chỉ PC: 0x1a96a4 | Địa chỉ FDE: 0x0c9248 | Kích thước: 256 bytes
//   0x1a96a4: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1a96a8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1a96ac: AA0003F3  mov      x19, x0
//   0x1a96b0: 52801800  mov      w0, #0xc0
static inline uint64_t fde_func_0406_0x1a96a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a96a4ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c9248ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0407 | PC: 0x1aa620 | FDE: 0x0c93b8 | Size: 256 bytes
// Khung tháo gỡ #0407 | Địa chỉ PC: 0x1aa620 | Địa chỉ FDE: 0x0c93b8 | Kích thước: 256 bytes
//   0x1aa620: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1aa624: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1aa628: A9405413  ldp      x19, x21, [x0]
//   0x1aa62c: A9402034  ldp      x20, x8, [x1]
static inline uint64_t fde_func_0407_0x1aa620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aa620ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c93b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0408 | PC: 0x1aab44 | FDE: 0x0c94e8 | Size: 256 bytes
// Khung tháo gỡ #0408 | Địa chỉ PC: 0x1aab44 | Địa chỉ FDE: 0x0c94e8 | Kích thước: 256 bytes
//   0x1aab44: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1aab48: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1aab4c: F9400054  ldr      x20, [x2]
//   0x1aab50: AA0203F3  mov      x19, x2
static inline uint64_t fde_func_0408_0x1aab44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aab44ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c94e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0409 | PC: 0x1ab70c | FDE: 0x0c9628 | Size: 256 bytes
// Khung tháo gỡ #0409 | Địa chỉ PC: 0x1ab70c | Địa chỉ FDE: 0x0c9628 | Kích thước: 256 bytes
//   0x1ab70c: D10203FF  sub      sp, sp, #0x80
//   0x1ab710: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x1ab714: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x1ab718: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0409_0x1ab70c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ab70cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9055bf7ULL) ^ 0x0c9628ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0410 | PC: 0x1abd74 | FDE: 0x0c9770 | Size: 256 bytes
// Khung tháo gỡ #0410 | Địa chỉ PC: 0x1abd74 | Địa chỉ FDE: 0x0c9770 | Kích thước: 256 bytes
//   0x1abd74: F9400008  ldr      x8, [x0]
//   0x1abd78: B40000E8  cbz      x8, #0x1abd94
//   0x1abd7c: 91002108  add      x8, x8, #8
//   0x1abd80: AA1E03E2  mov      x2, x30
static inline uint64_t fde_func_0410_0x1abd74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1abd74ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xb40000e8ULL) ^ 0x0c9770ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0411 | PC: 0x1ac4cc | FDE: 0x0c98c8 | Size: 256 bytes
// Khung tháo gỡ #0411 | Địa chỉ PC: 0x1ac4cc | Địa chỉ FDE: 0x0c98c8 | Kích thước: 256 bytes
//   0x1ac4cc: AA1F03E8  mov      x8, xzr
//   0x1ac4d0: F100311F  cmp      x8, #0xc
//   0x1ac4d4: 54000180  b.eq     #0x1ac504
//   0x1ac4d8: BC686822  ldr      s2, [x1, x8]
static inline uint64_t fde_func_0411_0x1ac4cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ac4ccULL ^ (static_cast<uint64_t>(0xaa1f03e8ULL) << 13);
    acc = (acc + a1 + 0xf100311fULL) ^ 0x0c98c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0412 | PC: 0x1ad154 | FDE: 0x0c99e8 | Size: 256 bytes
// Khung tháo gỡ #0412 | Địa chỉ PC: 0x1ad154 | Địa chỉ FDE: 0x0c99e8 | Kích thước: 256 bytes
//   0x1ad154: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1ad158: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1ad15c: AA0003F4  mov      x20, x0
//   0x1ad160: 94063EF9  bl       #0x33cd44
static inline uint64_t fde_func_0412_0x1ad154(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad154ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c99e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0413 | PC: 0x1add10 | FDE: 0x0c9b40 | Size: 256 bytes
// Khung tháo gỡ #0413 | Địa chỉ PC: 0x1add10 | Địa chỉ FDE: 0x0c9b40 | Kích thước: 256 bytes
//   0x1add10: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1add14: AA0003F3  mov      x19, x0
//   0x1add18: 97FF77AE  bl       #0x18bbd0
//   0x1add1c: 0F03F600  fmov     v0.2s, #1.00000000
static inline uint64_t fde_func_0413_0x1add10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1add10ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0c9b40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0414 | PC: 0x1ae418 | FDE: 0x0c9cb0 | Size: 256 bytes
// Khung tháo gỡ #0414 | Địa chỉ PC: 0x1ae418 | Địa chỉ FDE: 0x0c9cb0 | Kích thước: 256 bytes
//   0x1ae418: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1ae41c: D2918268  mov      x8, #0x8c13
//   0x1ae420: F2B656E8  movk     x8, #0xb2b7, lsl #16
//   0x1ae424: F2C439E8  movk     x8, #0x21cf, lsl #32
static inline uint64_t fde_func_0414_0x1ae418(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ae418ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xd2918268ULL) ^ 0x0c9cb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0415 | PC: 0x1aea64 | FDE: 0x0c9de0 | Size: 256 bytes
// Khung tháo gỡ #0415 | Địa chỉ PC: 0x1aea64 | Địa chỉ FDE: 0x0c9de0 | Kích thước: 256 bytes
//   0x1aea64: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1aea68: AA0003E8  mov      x8, x0
//   0x1aea6c: AA0003F3  mov      x19, x0
//   0x1aea70: 9406496C  bl       #0x341020
static inline uint64_t fde_func_0415_0x1aea64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aea64ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x0c9de0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0416 | PC: 0x1b1960 | FDE: 0x0c9f18 | Size: 256 bytes
// Khung tháo gỡ #0416 | Địa chỉ PC: 0x1b1960 | Địa chỉ FDE: 0x0c9f18 | Kích thước: 256 bytes
//   0x1b1960: D10103FF  sub      sp, sp, #0x40
//   0x1b1964: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1b1968: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x1b196c: 9405DBB8  bl       #0x32884c
static inline uint64_t fde_func_0416_0x1b1960(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b1960ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x0c9f18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0417 | PC: 0x1b23e4 | FDE: 0x0ca060 | Size: 256 bytes
// Khung tháo gỡ #0417 | Địa chỉ PC: 0x1b23e4 | Địa chỉ FDE: 0x0ca060 | Kích thước: 256 bytes
//   0x1b23e4: AA1E03E3  mov      x3, x30
//   0x1b23e8: 940600F6  bl       #0x3327c0
//   0x1b23ec: AA0303FE  mov      x30, x3
//   0x1b23f0: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0417_0x1b23e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b23e4ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x940600f6ULL) ^ 0x0ca060ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0418 | PC: 0x1b26b0 | FDE: 0x0ca170 | Size: 256 bytes
// Khung tháo gỡ #0418 | Địa chỉ PC: 0x1b26b0 | Địa chỉ FDE: 0x0ca170 | Kích thước: 256 bytes
//   0x1b26b0: D10203FF  sub      sp, sp, #0x80
//   0x1b26b4: F9003BFE  str      x30, [sp, #0x70]
//   0x1b26b8: 9406215D  bl       #0x33ac2c
//   0x1b26bc: F90037E9  str      x9, [sp, #0x68]
static inline uint64_t fde_func_0418_0x1b26b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b26b0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9003bfeULL) ^ 0x0ca170ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0419 | PC: 0x1b30ec | FDE: 0x0ca290 | Size: 256 bytes
// Khung tháo gỡ #0419 | Địa chỉ PC: 0x1b30ec | Địa chỉ FDE: 0x0ca290 | Kích thước: 256 bytes
//   0x1b30ec: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1b30f0: F9401008  ldr      x8, [x0, #0x20]
//   0x1b30f4: 2A0103F3  mov      w19, w1
//   0x1b30f8: B4000068  cbz      x8, #0x1b3104
static inline uint64_t fde_func_0419_0x1b30ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b30ecULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9401008ULL) ^ 0x0ca290ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0420 | PC: 0x1b35ec | FDE: 0x0ca3a0 | Size: 256 bytes
// Khung tháo gỡ #0420 | Địa chỉ PC: 0x1b35ec | Địa chỉ FDE: 0x0ca3a0 | Kích thước: 256 bytes
//   0x1b35ec: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1b35f0: F9408008  ldr      x8, [x0, #0x100]
//   0x1b35f4: 52800029  mov      w9, #1
//   0x1b35f8: 390B0009  strb     w9, [x0, #0x2c0]
static inline uint64_t fde_func_0420_0x1b35ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b35ecULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9408008ULL) ^ 0x0ca3a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0421 | PC: 0x1b4278 | FDE: 0x0ca4e8 | Size: 256 bytes
// Khung tháo gỡ #0421 | Địa chỉ PC: 0x1b4278 | Địa chỉ FDE: 0x0ca4e8 | Kích thước: 256 bytes
//   0x1b4278: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x1b427c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1b4280: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1b4284: AA0203F3  mov      x19, x2
static inline uint64_t fde_func_0421_0x1b4278(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b4278ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0ca4e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0422 | PC: 0x1b468c | FDE: 0x0ca5f8 | Size: 256 bytes
// Khung tháo gỡ #0422 | Địa chỉ PC: 0x1b468c | Địa chỉ FDE: 0x0ca5f8 | Kích thước: 256 bytes
//   0x1b468c: D103C3FF  sub      sp, sp, #0xf0
//   0x1b4690: F90073FE  str      x30, [sp, #0xe0]
//   0x1b4694: D53BD048  mrs      x8, tpidr_el0
//   0x1b4698: F9401509  ldr      x9, [x8, #0x28]
static inline uint64_t fde_func_0422_0x1b468c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b468cULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf90073feULL) ^ 0x0ca5f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0423 | PC: 0x1b498c | FDE: 0x0ca710 | Size: 256 bytes
// Khung tháo gỡ #0423 | Địa chỉ PC: 0x1b498c | Địa chỉ FDE: 0x0ca710 | Kích thước: 256 bytes
//   0x1b498c: D10203FF  sub      sp, sp, #0x80
//   0x1b4990: F9002BF6  str      x22, [sp, #0x50]
//   0x1b4994: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x1b4998: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0423_0x1b498c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b498cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf6ULL) ^ 0x0ca710ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0424 | PC: 0x1b4d30 | FDE: 0x0ca840 | Size: 256 bytes
// Khung tháo gỡ #0424 | Địa chỉ PC: 0x1b4d30 | Địa chỉ FDE: 0x0ca840 | Kích thước: 256 bytes
//   0x1b4d30: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x1b4d34: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1b4d38: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1b4d3c: F0000C88  adrp     x8, #0x347000
static inline uint64_t fde_func_0424_0x1b4d30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b4d30ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0ca840ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0425 | PC: 0x1b5140 | FDE: 0x0ca978 | Size: 256 bytes
// Khung tháo gỡ #0425 | Địa chỉ PC: 0x1b5140 | Địa chỉ FDE: 0x0ca978 | Kích thước: 256 bytes
//   0x1b5140: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1b5144: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1b5148: F941B008  ldr      x8, [x0, #0x360]
//   0x1b514c: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0425_0x1b5140(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b5140ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0ca978ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0426 | PC: 0x1b53a0 | FDE: 0x0caa88 | Size: 172 bytes
// Khung tháo gỡ #0426 | Địa chỉ PC: 0x1b53a0 | Địa chỉ FDE: 0x0caa88 | Kích thước: 172 bytes
//   0x1b53a0: F940F400  ldr      x0, [x0, #0x1e8]
//   0x1b53a4: D65F03C0  ret      
//   0x1b53a8: B9419008  ldr      w8, [x0, #0x190]
//   0x1b53ac: 34000068  cbz      w8, #0x1b53b8
static inline uint64_t fde_func_0426_0x1b53a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b53a0ULL ^ (static_cast<uint64_t>(0xf940f400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0caa88ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0427 | PC: 0x1b544c | FDE: 0x0cab78 | Size: 252 bytes
// Khung tháo gỡ #0427 | Địa chỉ PC: 0x1b544c | Địa chỉ FDE: 0x0cab78 | Kích thước: 252 bytes
//   0x1b544c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1b5450: 94060C25  bl       #0x3384e4
//   0x1b5454: 3941E260  ldrb     w0, [x19, #0x78]
//   0x1b5458: A8C17BF3  ldp      x19, x30, [sp], #0x10
static inline uint64_t fde_func_0427_0x1b544c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b544cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94060c25ULL) ^ 0x0cab78ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0428 | PC: 0x1b5548 | FDE: 0x0cac78 | Size: 92 bytes
// Khung tháo gỡ #0428 | Địa chỉ PC: 0x1b5548 | Địa chỉ FDE: 0x0cac78 | Kích thước: 92 bytes
//   0x1b5548: 14060F81  b        #0x33934c
//   0x1b554c: D100A000  sub      x0, x0, #0x28
//   0x1b5550: 17FFFF8A  b        #0x1b5378
//   0x1b5554: F9407008  ldr      x8, [x0, #0xe0]
static inline uint64_t fde_func_0428_0x1b5548(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b5548ULL ^ (static_cast<uint64_t>(0x14060f81ULL) << 13);
    acc = (acc + a1 + 0xd100a000ULL) ^ 0x0cac78ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0429 | PC: 0x1b55a4 | FDE: 0x0cad68 | Size: 256 bytes
// Khung tháo gỡ #0429 | Địa chỉ PC: 0x1b55a4 | Địa chỉ FDE: 0x0cad68 | Kích thước: 256 bytes
//   0x1b55a4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1b55a8: 94059CF2  bl       #0x31c970
//   0x1b55ac: 97FF1F3F  bl       #0x17d2a8
//   0x1b55b0: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0429_0x1b55a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b55a4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94059cf2ULL) ^ 0x0cad68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0430 | PC: 0x1b5950 | FDE: 0x0cae88 | Size: 256 bytes
// Khung tháo gỡ #0430 | Địa chỉ PC: 0x1b5950 | Địa chỉ FDE: 0x0cae88 | Kích thước: 256 bytes
//   0x1b5950: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x1b5954: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1b5958: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1b595c: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0430_0x1b5950(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b5950ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0cae88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0431 | PC: 0x1b5bc8 | FDE: 0x0cafa8 | Size: 256 bytes
// Khung tháo gỡ #0431 | Địa chỉ PC: 0x1b5bc8 | Địa chỉ FDE: 0x0cafa8 | Kích thước: 256 bytes
//   0x1b5bc8: 1406082D  b        #0x337c7c
//   0x1b5bcc: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1b5bd0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1b5bd4: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0431_0x1b5bc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b5bc8ULL ^ (static_cast<uint64_t>(0x1406082dULL) << 13);
    acc = (acc + a1 + 0xf81e0ff4ULL) ^ 0x0cafa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0432 | PC: 0x1b5ce4 | FDE: 0x0cb0b0 | Size: 84 bytes
// Khung tháo gỡ #0432 | Địa chỉ PC: 0x1b5ce4 | Địa chỉ FDE: 0x0cb0b0 | Kích thước: 84 bytes
//   0x1b5ce4: D100A000  sub      x0, x0, #0x28
//   0x1b5ce8: 17FFFF14  b        #0x1b5938
//   0x1b5cec: D105C000  sub      x0, x0, #0x170
//   0x1b5cf0: 17FFFEE8  b        #0x1b5890
static inline uint64_t fde_func_0432_0x1b5ce4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b5ce4ULL ^ (static_cast<uint64_t>(0xd100a000ULL) << 13);
    acc = (acc + a1 + 0x17ffff14ULL) ^ 0x0cb0b0ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0433 | PC: 0x1b5d38 | FDE: 0x0cb1a0 | Size: 256 bytes
// Khung tháo gỡ #0433 | Địa chỉ PC: 0x1b5d38 | Địa chỉ FDE: 0x0cb1a0 | Kích thước: 256 bytes
//   0x1b5d38: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1b5d3c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1b5d40: 12000042  and      w2, w2, #1
//   0x1b5d44: 94059A95  bl       #0x31c798
static inline uint64_t fde_func_0433_0x1b5d38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b5d38ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0cb1a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0434 | PC: 0x1b5f2c | FDE: 0x0cb260 | Size: 256 bytes [_ZN4lynx4tasm16ComponentElement14GetCSSFragmentEv]
// Khung tháo gỡ #0434 | Địa chỉ PC: 0x1b5f2c | Địa chỉ FDE: 0x0cb260 | Kích thước: 256 bytes
//   0x1b5f2c: D10183FF  sub      sp, sp, #0x60
//   0x1b5f30: F9001BF6  str      x22, [sp, #0x30]
//   0x1b5f34: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x1b5f38: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0434_0x1b5f2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b5f2cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf6ULL) ^ 0x0cb260ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0435 | PC: 0x1b61b4 | FDE: 0x0cb2c0 | Size: 256 bytes
// Khung tháo gỡ #0435 | Địa chỉ PC: 0x1b61b4 | Địa chỉ FDE: 0x0cb2c0 | Kích thước: 256 bytes
//   0x1b61b4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1b61b8: 9405F11C  bl       #0x332628
//   0x1b61bc: B5000040  cbnz     x0, #0x1b61c4
//   0x1b61c0: 9405CF70  bl       #0x329f80
static inline uint64_t fde_func_0435_0x1b61b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b61b4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9405f11cULL) ^ 0x0cb2c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0436 | PC: 0x1b6564 | FDE: 0x0cb3c0 | Size: 256 bytes
// Khung tháo gỡ #0436 | Địa chỉ PC: 0x1b6564 | Địa chỉ FDE: 0x0cb3c0 | Kích thước: 256 bytes
//   0x1b6564: B25E77EA  mov      x10, #-0x400000000
//   0x1b6568: B0000CC9  adrp     x9, #0x34f000
//   0x1b656c: F900100A  str      x10, [x0, #0x20]
//   0x1b6570: 9101200A  add      x10, x0, #0x48
static inline uint64_t fde_func_0436_0x1b6564(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b6564ULL ^ (static_cast<uint64_t>(0xb25e77eaULL) << 13);
    acc = (acc + a1 + 0xb0000cc9ULL) ^ 0x0cb3c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0437 | PC: 0x1b6cf4 | FDE: 0x0cb4e0 | Size: 256 bytes
// Khung tháo gỡ #0437 | Địa chỉ PC: 0x1b6cf4 | Địa chỉ FDE: 0x0cb4e0 | Kích thước: 256 bytes
//   0x1b6cf4: D10203FF  sub      sp, sp, #0x80
//   0x1b6cf8: F9002BF6  str      x22, [sp, #0x50]
//   0x1b6cfc: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x1b6d00: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0437_0x1b6cf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b6cf4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf6ULL) ^ 0x0cb4e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0438 | PC: 0x1b7148 | FDE: 0x0cb5f0 | Size: 256 bytes
// Khung tháo gỡ #0438 | Địa chỉ PC: 0x1b7148 | Địa chỉ FDE: 0x0cb5f0 | Kích thước: 256 bytes
//   0x1b7148: D10203FF  sub      sp, sp, #0x80
//   0x1b714c: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x1b7150: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x1b7154: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0438_0x1b7148(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b7148ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9055bf7ULL) ^ 0x0cb5f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0439 | PC: 0x1b77b4 | FDE: 0x0cb710 | Size: 256 bytes
// Khung tháo gỡ #0439 | Địa chỉ PC: 0x1b77b4 | Địa chỉ FDE: 0x0cb710 | Kích thước: 256 bytes
//   0x1b77b4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1b77b8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1b77bc: 9405931E  bl       #0x31c434
//   0x1b77c0: 97FFFB86  bl       #0x1b65d8
static inline uint64_t fde_func_0439_0x1b77b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b77b4ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0cb710ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0440 | PC: 0x1b7d48 | FDE: 0x0cb850 | Size: 256 bytes
// Khung tháo gỡ #0440 | Địa chỉ PC: 0x1b7d48 | Địa chỉ FDE: 0x0cb850 | Kích thước: 256 bytes
//   0x1b7d48: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x1b7d4c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1b7d50: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1b7d54: B9400028  ldr      w8, [x1]
static inline uint64_t fde_func_0440_0x1b7d48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b7d48ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0cb850ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0441 | PC: 0x1b8254 | FDE: 0x0cb978 | Size: 256 bytes
// Khung tháo gỡ #0441 | Địa chỉ PC: 0x1b8254 | Địa chỉ FDE: 0x0cb978 | Kích thước: 256 bytes
//   0x1b8254: AA1E03E0  mov      x0, x30
//   0x1b8258: 94059A19  bl       #0x31eabc
//   0x1b825c: AA0003FE  mov      x30, x0
//   0x1b8260: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0441_0x1b8254(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b8254ULL ^ (static_cast<uint64_t>(0xaa1e03e0ULL) << 13);
    acc = (acc + a1 + 0x94059a19ULL) ^ 0x0cb978ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0442 | PC: 0x1b8e70 | FDE: 0x0cbad8 | Size: 256 bytes
// Khung tháo gỡ #0442 | Địa chỉ PC: 0x1b8e70 | Địa chỉ FDE: 0x0cbad8 | Kích thước: 256 bytes
//   0x1b8e70: AA1E03E2  mov      x2, x30
//   0x1b8e74: 940594DA  bl       #0x31e1dc
//   0x1b8e78: AA0203FE  mov      x30, x2
//   0x1b8e7c: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_0442_0x1b8e70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b8e70ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x940594daULL) ^ 0x0cbad8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0443 | PC: 0x1ba430 | FDE: 0x0cbc38 | Size: 256 bytes
// Khung tháo gỡ #0443 | Địa chỉ PC: 0x1ba430 | Địa chỉ FDE: 0x0cbc38 | Kích thước: 256 bytes
//   0x1ba430: D100C3FF  sub      sp, sp, #0x30
//   0x1ba434: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1ba438: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1ba43c: D53BD055  mrs      x21, tpidr_el0
static inline uint64_t fde_func_0443_0x1ba430(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ba430ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0cbc38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0444 | PC: 0x1ba898 | FDE: 0x0cbd58 | Size: 256 bytes
// Khung tháo gỡ #0444 | Địa chỉ PC: 0x1ba898 | Địa chỉ FDE: 0x0cbd58 | Kích thước: 256 bytes
//   0x1ba898: D105C000  sub      x0, x0, #0x170
//   0x1ba89c: 17FFF09B  b        #0x1b6b08
//   0x1ba8a0: 1405E353  b        #0x3335ec
//   0x1ba8a4: D105E000  sub      x0, x0, #0x178
static inline uint64_t fde_func_0444_0x1ba898(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ba898ULL ^ (static_cast<uint64_t>(0xd105c000ULL) << 13);
    acc = (acc + a1 + 0x17fff09bULL) ^ 0x0cbd58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0445 | PC: 0x1ba9dc | FDE: 0x0cbe58 | Size: 256 bytes
// Khung tháo gỡ #0445 | Địa chỉ PC: 0x1ba9dc | Địa chỉ FDE: 0x0cbe58 | Kích thước: 256 bytes
//   0x1ba9dc: F9407408  ldr      x8, [x0, #0xe8]
//   0x1ba9e0: F9409D08  ldr      x8, [x8, #0x138]
//   0x1ba9e4: B40000C8  cbz      x8, #0x1ba9fc
//   0x1ba9e8: 39495108  ldrb     w8, [x8, #0x254]
static inline uint64_t fde_func_0445_0x1ba9dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ba9dcULL ^ (static_cast<uint64_t>(0xf9407408ULL) << 13);
    acc = (acc + a1 + 0xf9409d08ULL) ^ 0x0cbe58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0446 | PC: 0x1bad6c | FDE: 0x0cbf80 | Size: 256 bytes
// Khung tháo gỡ #0446 | Địa chỉ PC: 0x1bad6c | Địa chỉ FDE: 0x0cbf80 | Kích thước: 256 bytes
//   0x1bad6c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1bad70: F8480C08  ldr      x8, [x0, #0x80]!
//   0x1bad74: B4000068  cbz      x8, #0x1bad80
//   0x1bad78: 97FEBC5C  bl       #0x169ee8
static inline uint64_t fde_func_0446_0x1bad6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1bad6cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf8480c08ULL) ^ 0x0cbf80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0447 | PC: 0x1bb09c | FDE: 0x0cc090 | Size: 256 bytes
// Khung tháo gỡ #0447 | Địa chỉ PC: 0x1bb09c | Địa chỉ FDE: 0x0cc090 | Kích thước: 256 bytes
//   0x1bb09c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1bb0a0: B9405408  ldr      w8, [x0, #0x54]
//   0x1bb0a4: AA0103F3  mov      x19, x1
//   0x1bb0a8: 0A020108  and      w8, w8, w2
static inline uint64_t fde_func_0447_0x1bb09c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1bb09cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb9405408ULL) ^ 0x0cc090ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0448 | PC: 0x1bb668 | FDE: 0x0cc1b0 | Size: 256 bytes
// Khung tháo gỡ #0448 | Địa chỉ PC: 0x1bb668 | Địa chỉ FDE: 0x0cc1b0 | Kích thước: 256 bytes
//   0x1bb668: D10083FF  sub      sp, sp, #0x20
//   0x1bb66c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1bb670: 940585E9  bl       #0x31ce14
//   0x1bb674: B50001A0  cbnz     x0, #0x1bb6a8
static inline uint64_t fde_func_0448_0x1bb668(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1bb668ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0cc1b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0449 | PC: 0x1bbb3c | FDE: 0x0cc2e0 | Size: 256 bytes
// Khung tháo gỡ #0449 | Địa chỉ PC: 0x1bbb3c | Địa chỉ FDE: 0x0cc2e0 | Kích thước: 256 bytes
//   0x1bbb3c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1bbb40: AA0003F3  mov      x19, x0
//   0x1bbb44: 94000014  bl       #0x1bbb94
//   0x1bbb48: B5000080  cbnz     x0, #0x1bbb58
static inline uint64_t fde_func_0449_0x1bbb3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1bbb3cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0cc2e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0450 | PC: 0x1bbff4 | FDE: 0x0cc3e0 | Size: 256 bytes
// Khung tháo gỡ #0450 | Địa chỉ PC: 0x1bbff4 | Địa chỉ FDE: 0x0cc3e0 | Kích thước: 256 bytes
//   0x1bbff4: D10083FF  sub      sp, sp, #0x20
//   0x1bbff8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1bbffc: 94058386  bl       #0x31ce14
//   0x1bc000: B50000E0  cbnz     x0, #0x1bc01c
static inline uint64_t fde_func_0450_0x1bbff4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1bbff4ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0cc3e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0451 | PC: 0x1bc260 | FDE: 0x0cc4e0 | Size: 256 bytes
// Khung tháo gỡ #0451 | Địa chỉ PC: 0x1bc260 | Địa chỉ FDE: 0x0cc4e0 | Kích thước: 256 bytes
//   0x1bc260: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1bc264: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1bc268: 8B020848  add      x8, x2, x2, lsl #2
//   0x1bc26c: 94058072  bl       #0x31c434
static inline uint64_t fde_func_0451_0x1bc260(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1bc260ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0cc4e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0452 | PC: 0x1bca50 | FDE: 0x0cc648 | Size: 256 bytes
// Khung tháo gỡ #0452 | Địa chỉ PC: 0x1bca50 | Địa chỉ FDE: 0x0cc648 | Kích thước: 256 bytes
//   0x1bca50: D10083FF  sub      sp, sp, #0x20
//   0x1bca54: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1bca58: 940580EF  bl       #0x31ce14
//   0x1bca5c: B50001C0  cbnz     x0, #0x1bca94
static inline uint64_t fde_func_0452_0x1bca50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1bca50ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0cc648ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0453 | PC: 0x1bd024 | FDE: 0x0cc778 | Size: 256 bytes
// Khung tháo gỡ #0453 | Địa chỉ PC: 0x1bd024 | Địa chỉ FDE: 0x0cc778 | Kích thước: 256 bytes
//   0x1bd024: F9400808  ldr      x8, [x0, #0x10]
//   0x1bd028: B4000128  cbz      x8, #0x1bd04c
//   0x1bd02c: EB01011F  cmp      x8, x1
//   0x1bd030: 540000E8  b.hi     #0x1bd04c
static inline uint64_t fde_func_0453_0x1bd024(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1bd024ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xb4000128ULL) ^ 0x0cc778ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0454 | PC: 0x1bd2c4 | FDE: 0x0cc898 | Size: 256 bytes
// Khung tháo gỡ #0454 | Địa chỉ PC: 0x1bd2c4 | Địa chỉ FDE: 0x0cc898 | Kích thước: 256 bytes
//   0x1bd2c4: F9400408  ldr      x8, [x0, #8]
//   0x1bd2c8: 91004001  add      x1, x0, #0x10
//   0x1bd2cc: AA0803E0  mov      x0, x8
//   0x1bd2d0: 14000001  b        #0x1bd2d4
static inline uint64_t fde_func_0454_0x1bd2c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1bd2c4ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x91004001ULL) ^ 0x0cc898ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0455 | PC: 0x1bd574 | FDE: 0x0cc9a8 | Size: 256 bytes
// Khung tháo gỡ #0455 | Địa chỉ PC: 0x1bd574 | Địa chỉ FDE: 0x0cc9a8 | Kích thước: 256 bytes
//   0x1bd574: D10203FF  sub      sp, sp, #0x80
//   0x1bd578: 6D0523E9  stp      d9, d8, [sp, #0x50]
//   0x1bd57c: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x1bd580: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0455_0x1bd574(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1bd574ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0x6d0523e9ULL) ^ 0x0cc9a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0456 | PC: 0x1bda08 | FDE: 0x0ccad0 | Size: 256 bytes
// Khung tháo gỡ #0456 | Địa chỉ PC: 0x1bda08 | Địa chỉ FDE: 0x0ccad0 | Kích thước: 256 bytes
//   0x1bda08: F9400408  ldr      x8, [x0, #8]
//   0x1bda0c: 29420801  ldp      w1, w2, [x0, #0x10]
//   0x1bda10: F940D508  ldr      x8, [x8, #0x1a8]
//   0x1bda14: F9400109  ldr      x9, [x8]
static inline uint64_t fde_func_0456_0x1bda08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1bda08ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x29420801ULL) ^ 0x0ccad0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0457 | PC: 0x1bdc94 | FDE: 0x0ccbd8 | Size: 256 bytes
// Khung tháo gỡ #0457 | Địa chỉ PC: 0x1bdc94 | Địa chỉ FDE: 0x0ccbd8 | Kích thước: 256 bytes
//   0x1bdc94: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1bdc98: AA0003F3  mov      x19, x0
//   0x1bdc9c: 97FFFFFA  bl       #0x1bdc84
//   0x1bdca0: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0457_0x1bdc94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1bdc94ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0ccbd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0458 | PC: 0x1bde60 | FDE: 0x0ccce0 | Size: 256 bytes
// Khung tháo gỡ #0458 | Địa chỉ PC: 0x1bde60 | Địa chỉ FDE: 0x0ccce0 | Kích thước: 256 bytes
//   0x1bde60: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1bde64: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1bde68: 91006014  add      x20, x0, #0x18
//   0x1bde6c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0458_0x1bde60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1bde60ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0ccce0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0459 | PC: 0x1be0b0 | FDE: 0x0ccdf8 | Size: 256 bytes
// Khung tháo gỡ #0459 | Địa chỉ PC: 0x1be0b0 | Địa chỉ FDE: 0x0ccdf8 | Kích thước: 256 bytes
//   0x1be0b0: AA0003E8  mov      x8, x0
//   0x1be0b4: F9400000  ldr      x0, [x0]
//   0x1be0b8: F900011F  str      xzr, [x8]
//   0x1be0bc: B40000E0  cbz      x0, #0x1be0d8
static inline uint64_t fde_func_0459_0x1be0b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1be0b0ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xf9400000ULL) ^ 0x0ccdf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0460 | PC: 0x1be8bc | FDE: 0x0ccf38 | Size: 256 bytes
// Khung tháo gỡ #0460 | Địa chỉ PC: 0x1be8bc | Địa chỉ FDE: 0x0ccf38 | Kích thước: 256 bytes
//   0x1be8bc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1be8c0: F9400008  ldr      x8, [x0]
//   0x1be8c4: 2A1F03E2  mov      w2, wzr
//   0x1be8c8: AA1F03E3  mov      x3, xzr
static inline uint64_t fde_func_0460_0x1be8bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1be8bcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x0ccf38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0461 | PC: 0x1bebd0 | FDE: 0x0cd048 | Size: 256 bytes
// Khung tháo gỡ #0461 | Địa chỉ PC: 0x1bebd0 | Địa chỉ FDE: 0x0cd048 | Kích thước: 256 bytes
//   0x1bebd0: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1bebd4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1bebd8: 52800908  mov      w8, #0x48
//   0x1bebdc: 928008E9  mov      x9, #-0x48
static inline uint64_t fde_func_0461_0x1bebd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1bebd0ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0cd048ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0462 | PC: 0x1bed3c | FDE: 0x0cd140 | Size: 256 bytes
// Khung tháo gỡ #0462 | Địa chỉ PC: 0x1bed3c | Địa chỉ FDE: 0x0cd140 | Kích thước: 256 bytes
//   0x1bed3c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1bed40: 91002013  add      x19, x0, #8
//   0x1bed44: AA1303E0  mov      x0, x19
//   0x1bed48: 97FF99D9  bl       #0x1a54ac
static inline uint64_t fde_func_0462_0x1bed3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1bed3cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x91002013ULL) ^ 0x0cd140ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0463 | PC: 0x1bf72c | FDE: 0x0cd278 | Size: 256 bytes
// Khung tháo gỡ #0463 | Địa chỉ PC: 0x1bf72c | Địa chỉ FDE: 0x0cd278 | Kích thước: 256 bytes
//   0x1bf72c: D106C3FF  sub      sp, sp, #0x1b0
//   0x1bf730: A91763FC  stp      x28, x24, [sp, #0x170]
//   0x1bf734: A9185BF7  stp      x23, x22, [sp, #0x180]
//   0x1bf738: A91953F5  stp      x21, x20, [sp, #0x190]
static inline uint64_t fde_func_0463_0x1bf72c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1bf72cULL ^ (static_cast<uint64_t>(0xd106c3ffULL) << 13);
    acc = (acc + a1 + 0xa91763fcULL) ^ 0x0cd278ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0464 | PC: 0x1bfc04 | FDE: 0x0cd390 | Size: 256 bytes
// Khung tháo gỡ #0464 | Địa chỉ PC: 0x1bfc04 | Địa chỉ FDE: 0x0cd390 | Kích thước: 256 bytes
//   0x1bfc04: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1bfc08: 940574BE  bl       #0x31cf00
//   0x1bfc0c: B40000D3  cbz      x19, #0x1bfc24
//   0x1bfc10: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0464_0x1bfc04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1bfc04ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x940574beULL) ^ 0x0cd390ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0465 | PC: 0x1bfd0c | FDE: 0x0cd3e8 | Size: 256 bytes [_ZN4lynx4tasm12FiberElement8SetStyleENS0_13CSSPropertyIDERKNS_5lepus5ValueE]
// Khung tháo gỡ #0465 | Địa chỉ PC: 0x1bfd0c | Địa chỉ FDE: 0x0cd3e8 | Kích thước: 256 bytes
//   0x1bfd0c: AA1E03E3  mov      x3, x30
//   0x1bfd10: 9405764C  bl       #0x31d640
//   0x1bfd14: AA0303FE  mov      x30, x3
//   0x1bfd18: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_0465_0x1bfd0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1bfd0cULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x9405764cULL) ^ 0x0cd3e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0466 | PC: 0x1c00c0 | FDE: 0x0cd4c0 | Size: 256 bytes
// Khung tháo gỡ #0466 | Địa chỉ PC: 0x1c00c0 | Địa chỉ FDE: 0x0cd4c0 | Kích thước: 256 bytes
//   0x1c00c0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1c00c4: AA0003F3  mov      x19, x0
//   0x1c00c8: 94057123  bl       #0x31c554
//   0x1c00cc: B0000C48  adrp     x8, #0x349000
static inline uint64_t fde_func_0466_0x1c00c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c00c0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0cd4c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0467 | PC: 0x1c0364 | FDE: 0x0cd5d0 | Size: 256 bytes
// Khung tháo gỡ #0467 | Địa chỉ PC: 0x1c0364 | Địa chỉ FDE: 0x0cd5d0 | Kích thước: 256 bytes
//   0x1c0364: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1c0368: 9405748B  bl       #0x31d594
//   0x1c036c: B9401A61  ldr      w1, [x19, #0x18]
//   0x1c0370: 9400A309  bl       #0x1e8f94
static inline uint64_t fde_func_0467_0x1c0364(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c0364ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9405748bULL) ^ 0x0cd5d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0468 | PC: 0x1c0e80 | FDE: 0x0cd710 | Size: 256 bytes
// Khung tháo gỡ #0468 | Địa chỉ PC: 0x1c0e80 | Địa chỉ FDE: 0x0cd710 | Kích thước: 256 bytes
//   0x1c0e80: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x1c0e84: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1c0e88: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1c0e8c: A9007C1F  stp      xzr, xzr, [x0]
static inline uint64_t fde_func_0468_0x1c0e80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c0e80ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0cd710ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0469 | PC: 0x1c1144 | FDE: 0x0cd850 | Size: 256 bytes
// Khung tháo gỡ #0469 | Địa chỉ PC: 0x1c1144 | Địa chỉ FDE: 0x0cd850 | Kích thước: 256 bytes
//   0x1c1144: 8B020C28  add      x8, x1, x2, lsl #3
//   0x1c1148: EB08003F  cmp      x1, x8
//   0x1c114c: 54000160  b.eq     #0x1c1178
//   0x1c1150: AA1E03E2  mov      x2, x30
static inline uint64_t fde_func_0469_0x1c1144(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c1144ULL ^ (static_cast<uint64_t>(0x8b020c28ULL) << 13);
    acc = (acc + a1 + 0xeb08003fULL) ^ 0x0cd850ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0470 | PC: 0x1c1404 | FDE: 0x0cd978 | Size: 256 bytes
// Khung tháo gỡ #0470 | Địa chỉ PC: 0x1c1404 | Địa chỉ FDE: 0x0cd978 | Kích thước: 256 bytes
//   0x1c1404: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1c1408: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1c140c: F9407014  ldr      x20, [x0, #0xe0]
//   0x1c1410: 9405DC1C  bl       #0x338480
static inline uint64_t fde_func_0470_0x1c1404(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c1404ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0cd978ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0471 | PC: 0x1c1510 | FDE: 0x0cd9d0 | Size: 96 bytes [_ZN4lynx4tasm12FiberElement14RemoveAllClassEv]
// Khung tháo gỡ #0471 | Địa chỉ PC: 0x1c1510 | Địa chỉ FDE: 0x0cd9d0 | Kích thước: 96 bytes
//   0x1c1510: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1c1514: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1c1518: F9407014  ldr      x20, [x0, #0xe0]
//   0x1c151c: 9405DBD9  bl       #0x338480
static inline uint64_t fde_func_0471_0x1c1510(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c1510ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0cd9d0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0472 | PC: 0x1c1570 | FDE: 0x0cda08 | Size: 256 bytes [_ZN4lynx4tasm12FiberElement21RemoveAllInlineStylesEv]
// Khung tháo gỡ #0472 | Địa chỉ PC: 0x1c1570 | Địa chỉ FDE: 0x0cda08 | Kích thước: 256 bytes
//   0x1c1570: AA1E03E1  mov      x1, x30
//   0x1c1574: 94056DD0  bl       #0x31ccb4
//   0x1c1578: AA0103FE  mov      x30, x1
//   0x1c157c: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0472_0x1c1570(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c1570ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x94056dd0ULL) ^ 0x0cda08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0473 | PC: 0x1c1984 | FDE: 0x0cdac8 | Size: 256 bytes
// Khung tháo gỡ #0473 | Địa chỉ PC: 0x1c1984 | Địa chỉ FDE: 0x0cdac8 | Kích thước: 256 bytes
//   0x1c1984: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1c1988: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1c198c: 2941200A  ldp      w10, w8, [x0, #8]
//   0x1c1990: 94058357  bl       #0x3226ec
static inline uint64_t fde_func_0473_0x1c1984(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c1984ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0cdac8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0474 | PC: 0x1c1b88 | FDE: 0x0cdbc8 | Size: 256 bytes
// Khung tháo gỡ #0474 | Địa chỉ PC: 0x1c1b88 | Địa chỉ FDE: 0x0cdbc8 | Kích thước: 256 bytes
//   0x1c1b88: AA1E03E5  mov      x5, x30
//   0x1c1b8c: 9405A10A  bl       #0x329fb4
//   0x1c1b90: AA0503FE  mov      x30, x5
//   0x1c1b94: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0474_0x1c1b88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c1b88ULL ^ (static_cast<uint64_t>(0xaa1e03e5ULL) << 13);
    acc = (acc + a1 + 0x9405a10aULL) ^ 0x0cdbc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0475 | PC: 0x1c1f2c | FDE: 0x0cdce8 | Size: 256 bytes
// Khung tháo gỡ #0475 | Địa chỉ PC: 0x1c1f2c | Địa chỉ FDE: 0x0cdce8 | Kích thước: 256 bytes
//   0x1c1f2c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1c1f30: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1c1f34: 940579D7  bl       #0x320690
//   0x1c1f38: B40000D4  cbz      x20, #0x1c1f50
static inline uint64_t fde_func_0475_0x1c1f2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c1f2cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0cdce8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0476 | PC: 0x1c221c | FDE: 0x0cde08 | Size: 256 bytes
// Khung tháo gỡ #0476 | Địa chỉ PC: 0x1c221c | Địa chỉ FDE: 0x0cde08 | Kích thước: 256 bytes
//   0x1c221c: AA1E03E2  mov      x2, x30
//   0x1c2220: 94056AA5  bl       #0x31ccb4
//   0x1c2224: AA0203FE  mov      x30, x2
//   0x1c2228: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0476_0x1c221c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c221cULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94056aa5ULL) ^ 0x0cde08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0477 | PC: 0x1c263c | FDE: 0x0cdf30 | Size: 256 bytes
// Khung tháo gỡ #0477 | Địa chỉ PC: 0x1c263c | Địa chỉ FDE: 0x0cdf30 | Kích thước: 256 bytes
//   0x1c263c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1c2640: F8498C08  ldr      x8, [x0, #0x98]!
//   0x1c2644: AA0103F3  mov      x19, x1
//   0x1c2648: B5000068  cbnz     x8, #0x1c2654
static inline uint64_t fde_func_0477_0x1c263c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c263cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf8498c08ULL) ^ 0x0cdf30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0478 | PC: 0x1c2a8c | FDE: 0x0ce058 | Size: 256 bytes
// Khung tháo gỡ #0478 | Địa chỉ PC: 0x1c2a8c | Địa chỉ FDE: 0x0ce058 | Kích thước: 256 bytes
//   0x1c2a8c: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x1c2a90: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1c2a94: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1c2a98: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0478_0x1c2a8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c2a8cULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0ce058ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0479 | PC: 0x1c2efc | FDE: 0x0ce170 | Size: 256 bytes
// Khung tháo gỡ #0479 | Địa chỉ PC: 0x1c2efc | Địa chỉ FDE: 0x0ce170 | Kích thước: 256 bytes
//   0x1c2efc: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x1c2f00: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1c2f04: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1c2f08: B9400C17  ldr      w23, [x0, #0xc]
static inline uint64_t fde_func_0479_0x1c2efc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c2efcULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0ce170ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0480 | PC: 0x1c326c | FDE: 0x0ce280 | Size: 256 bytes
// Khung tháo gỡ #0480 | Địa chỉ PC: 0x1c326c | Địa chỉ FDE: 0x0ce280 | Kích thước: 256 bytes
//   0x1c326c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1c3270: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1c3274: D0000C28  adrp     x8, #0x349000
//   0x1c3278: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0480_0x1c326c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c326cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0ce280ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0481 | PC: 0x1c366c | FDE: 0x0ce3b0 | Size: 256 bytes
// Khung tháo gỡ #0481 | Địa chỉ PC: 0x1c366c | Địa chỉ FDE: 0x0ce3b0 | Kích thước: 256 bytes
//   0x1c366c: A940A408  ldp      x8, x9, [x0, #8]
//   0x1c3670: A9422C0A  ldp      x10, x11, [x0, #0x20]
//   0x1c3674: EB080128  subs     x8, x9, x8
//   0x1c3678: D37AE508  lsl      x8, x8, #6
static inline uint64_t fde_func_0481_0x1c366c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c366cULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0xa9422c0aULL) ^ 0x0ce3b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0482 | PC: 0x1c3da4 | FDE: 0x0ce4e8 | Size: 256 bytes
// Khung tháo gỡ #0482 | Địa chỉ PC: 0x1c3da4 | Địa chỉ FDE: 0x0ce4e8 | Kích thước: 256 bytes
//   0x1c3da4: D10543FF  sub      sp, sp, #0x150
//   0x1c3da8: FD0073E8  str      d8, [sp, #0xe0]
//   0x1c3dac: AA1E03E2  mov      x2, x30
//   0x1c3db0: 94056FFA  bl       #0x31fd98
static inline uint64_t fde_func_0482_0x1c3da4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c3da4ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xfd0073e8ULL) ^ 0x0ce4e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0483 | PC: 0x1c46dc | FDE: 0x0ce640 | Size: 256 bytes
// Khung tháo gỡ #0483 | Địa chỉ PC: 0x1c46dc | Địa chỉ FDE: 0x0ce640 | Kích thước: 256 bytes
//   0x1c46dc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1c46e0: AA0003F3  mov      x19, x0
//   0x1c46e4: 97FFFFE3  bl       #0x1c4670
//   0x1c46e8: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0483_0x1c46dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c46dcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0ce640ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0484 | PC: 0x1c48d8 | FDE: 0x0ce750 | Size: 256 bytes
// Khung tháo gỡ #0484 | Địa chỉ PC: 0x1c48d8 | Địa chỉ FDE: 0x0ce750 | Kích thước: 256 bytes
//   0x1c48d8: D102C3FF  sub      sp, sp, #0xb0
//   0x1c48dc: A9085BF7  stp      x23, x22, [sp, #0x80]
//   0x1c48e0: A90953F5  stp      x21, x20, [sp, #0x90]
//   0x1c48e4: A90A7BF3  stp      x19, x30, [sp, #0xa0]
static inline uint64_t fde_func_0484_0x1c48d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c48d8ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9085bf7ULL) ^ 0x0ce750ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0485 | PC: 0x1c4d50 | FDE: 0x0ce880 | Size: 256 bytes
// Khung tháo gỡ #0485 | Địa chỉ PC: 0x1c4d50 | Địa chỉ FDE: 0x0ce880 | Kích thước: 256 bytes
//   0x1c4d50: D100C3FF  sub      sp, sp, #0x30
//   0x1c4d54: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1c4d58: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1c4d5c: 91010014  add      x20, x0, #0x40
static inline uint64_t fde_func_0485_0x1c4d50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c4d50ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0ce880ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0486 | PC: 0x1c4f9c | FDE: 0x0ce990 | Size: 256 bytes
// Khung tháo gỡ #0486 | Địa chỉ PC: 0x1c4f9c | Địa chỉ FDE: 0x0ce990 | Kích thước: 256 bytes
//   0x1c4f9c: 92780008  and      x8, x0, #0x100
//   0x1c4fa0: 36000081  tbz      w1, #0, #0x1c4fb0
//   0x1c4fa4: B50000A8  cbnz     x8, #0x1c4fb8
//   0x1c4fa8: 2A1F03E0  mov      w0, wzr
static inline uint64_t fde_func_0486_0x1c4f9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c4f9cULL ^ (static_cast<uint64_t>(0x92780008ULL) << 13);
    acc = (acc + a1 + 0x36000081ULL) ^ 0x0ce990ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0487 | PC: 0x1c5264 | FDE: 0x0ceaa8 | Size: 256 bytes
// Khung tháo gỡ #0487 | Địa chỉ PC: 0x1c5264 | Địa chỉ FDE: 0x0ceaa8 | Kích thước: 256 bytes
//   0x1c5264: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1c5268: F9400008  ldr      x8, [x0]
//   0x1c526c: AA0003F3  mov      x19, x0
//   0x1c5270: 94056FAA  bl       #0x321118
static inline uint64_t fde_func_0487_0x1c5264(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c5264ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x0ceaa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0488 | PC: 0x1c55a4 | FDE: 0x0cebe8 | Size: 256 bytes
// Khung tháo gỡ #0488 | Địa chỉ PC: 0x1c55a4 | Địa chỉ FDE: 0x0cebe8 | Kích thước: 256 bytes
//   0x1c55a4: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1c55a8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1c55ac: 9405B7EC  bl       #0x33355c
//   0x1c55b0: F9409E88  ldr      x8, [x20, #0x138]
static inline uint64_t fde_func_0488_0x1c55a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c55a4ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0cebe8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0489 | PC: 0x1c6294 | FDE: 0x0ced48 | Size: 208 bytes
// Khung tháo gỡ #0489 | Địa chỉ PC: 0x1c6294 | Địa chỉ FDE: 0x0ced48 | Kích thước: 208 bytes
//   0x1c6294: D100A000  sub      x0, x0, #0x28
//   0x1c6298: 17FFFB71  b        #0x1c505c
//   0x1c629c: D105C000  sub      x0, x0, #0x170
//   0x1c62a0: 17FFFB4E  b        #0x1c4fd8
static inline uint64_t fde_func_0489_0x1c6294(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c6294ULL ^ (static_cast<uint64_t>(0xd100a000ULL) << 13);
    acc = (acc + a1 + 0x17fffb71ULL) ^ 0x0ced48ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0490 | PC: 0x1c6364 | FDE: 0x0cee48 | Size: 256 bytes
// Khung tháo gỡ #0490 | Địa chỉ PC: 0x1c6364 | Địa chỉ FDE: 0x0cee48 | Kích thước: 256 bytes
//   0x1c6364: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1c6368: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1c636c: D37BFC28  lsr      x8, x1, #0x3b
//   0x1c6370: B50000E8  cbnz     x8, #0x1c638c
static inline uint64_t fde_func_0490_0x1c6364(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c6364ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0cee48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0491 | PC: 0x1c6594 | FDE: 0x0cef50 | Size: 256 bytes
// Khung tháo gỡ #0491 | Địa chỉ PC: 0x1c6594 | Địa chỉ FDE: 0x0cef50 | Kích thước: 256 bytes
//   0x1c6594: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1c6598: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1c659c: AA0103F3  mov      x19, x1
//   0x1c65a0: F0FFF541  adrp     x1, #0x71000
static inline uint64_t fde_func_0491_0x1c6594(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c6594ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0cef50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0492 | PC: 0x1c6854 | FDE: 0x0cf070 | Size: 256 bytes
// Khung tháo gỡ #0492 | Địa chỉ PC: 0x1c6854 | Địa chỉ FDE: 0x0cf070 | Kích thước: 256 bytes
//   0x1c6854: F9400001  ldr      x1, [x0]
//   0x1c6858: 14000001  b        #0x1c685c
//   0x1c685c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1c6860: A9017BF3  stp      x19, x30, [sp, #0x10]
static inline uint64_t fde_func_0492_0x1c6854(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c6854ULL ^ (static_cast<uint64_t>(0xf9400001ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x0cf070ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0493 | PC: 0x1c6b68 | FDE: 0x0cf188 | Size: 256 bytes
// Khung tháo gỡ #0493 | Địa chỉ PC: 0x1c6b68 | Địa chỉ FDE: 0x0cf188 | Kích thước: 256 bytes
//   0x1c6b68: F9400408  ldr      x8, [x0, #8]
//   0x1c6b6c: F9401D08  ldr      x8, [x8, #0x38]
//   0x1c6b70: B40000A8  cbz      x8, #0x1c6b84
//   0x1c6b74: F9407508  ldr      x8, [x8, #0xe8]
static inline uint64_t fde_func_0493_0x1c6b68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c6b68ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf9401d08ULL) ^ 0x0cf188ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0494 | PC: 0x1c7084 | FDE: 0x0cf2b0 | Size: 256 bytes
// Khung tháo gỡ #0494 | Địa chỉ PC: 0x1c7084 | Địa chỉ FDE: 0x0cf2b0 | Kích thước: 256 bytes
//   0x1c7084: D10143FF  sub      sp, sp, #0x50
//   0x1c7088: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x1c708c: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x1c7090: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0494_0x1c7084(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c7084ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x0cf2b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0495 | PC: 0x1c7524 | FDE: 0x0cf3e0 | Size: 256 bytes
// Khung tháo gỡ #0495 | Địa chỉ PC: 0x1c7524 | Địa chỉ FDE: 0x0cf3e0 | Kích thước: 256 bytes
//   0x1c7524: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1c7528: AA0003F3  mov      x19, x0
//   0x1c752c: 97FFFFFA  bl       #0x1c7514
//   0x1c7530: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0495_0x1c7524(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c7524ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0cf3e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0496 | PC: 0x1c7cb0 | FDE: 0x0cf518 | Size: 256 bytes
// Khung tháo gỡ #0496 | Địa chỉ PC: 0x1c7cb0 | Địa chỉ FDE: 0x0cf518 | Kích thước: 256 bytes
//   0x1c7cb0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1c7cb4: AA0003F3  mov      x19, x0
//   0x1c7cb8: 97FFFFF4  bl       #0x1c7c88
//   0x1c7cbc: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0496_0x1c7cb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c7cb0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0cf518ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0497 | PC: 0x1c7e78 | FDE: 0x0cf620 | Size: 256 bytes
// Khung tháo gỡ #0497 | Địa chỉ PC: 0x1c7e78 | Địa chỉ FDE: 0x0cf620 | Kích thước: 256 bytes
//   0x1c7e78: AA0003E8  mov      x8, x0
//   0x1c7e7c: 90FFF60A  adrp     x10, #0x87000
//   0x1c7e80: AA1F03E0  mov      x0, xzr
//   0x1c7e84: 8B010109  add      x9, x8, x1
static inline uint64_t fde_func_0497_0x1c7e78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c7e78ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0x90fff60aULL) ^ 0x0cf620ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0498 | PC: 0x1c8254 | FDE: 0x0cf738 | Size: 256 bytes
// Khung tháo gỡ #0498 | Địa chỉ PC: 0x1c8254 | Địa chỉ FDE: 0x0cf738 | Kích thước: 256 bytes
//   0x1c8254: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x1c8258: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1c825c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1c8260: AA0003F6  mov      x22, x0
static inline uint64_t fde_func_0498_0x1c8254(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c8254ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0cf738ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0499 | PC: 0x1c841c | FDE: 0x0cf838 | Size: 256 bytes
// Khung tháo gỡ #0499 | Địa chỉ PC: 0x1c841c | Địa chỉ FDE: 0x0cf838 | Kích thước: 256 bytes
//   0x1c841c: D10243FF  sub      sp, sp, #0x90
//   0x1c8420: F90033F6  str      x22, [sp, #0x60]
//   0x1c8424: A90753F5  stp      x21, x20, [sp, #0x70]
//   0x1c8428: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_0499_0x1c841c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c841cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90033f6ULL) ^ 0x0cf838ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0500 | PC: 0x1c87b8 | FDE: 0x0cf960 | Size: 256 bytes
// Khung tháo gỡ #0500 | Địa chỉ PC: 0x1c87b8 | Địa chỉ FDE: 0x0cf960 | Kích thước: 256 bytes
//   0x1c87b8: D100C3FF  sub      sp, sp, #0x30
//   0x1c87bc: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1c87c0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1c87c4: 91010014  add      x20, x0, #0x40
static inline uint64_t fde_func_0500_0x1c87b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c87b8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0cf960ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0501 | PC: 0x1c8998 | FDE: 0x0cfa68 | Size: 256 bytes
// Khung tháo gỡ #0501 | Địa chỉ PC: 0x1c8998 | Địa chỉ FDE: 0x0cfa68 | Kích thước: 256 bytes
//   0x1c8998: D105E000  sub      x0, x0, #0x178
//   0x1c899c: 17FFFE9A  b        #0x1c8404
//   0x1c89a0: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1c89a4: 39401022  ldrb     w2, [x1, #4]
static inline uint64_t fde_func_0501_0x1c8998(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c8998ULL ^ (static_cast<uint64_t>(0xd105e000ULL) << 13);
    acc = (acc + a1 + 0x17fffe9aULL) ^ 0x0cfa68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0502 | PC: 0x1c8de0 | FDE: 0x0cfb78 | Size: 256 bytes
// Khung tháo gỡ #0502 | Địa chỉ PC: 0x1c8de0 | Địa chỉ FDE: 0x0cfb78 | Kích thước: 256 bytes
//   0x1c8de0: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1c8de4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1c8de8: F9400008  ldr      x8, [x0]
//   0x1c8dec: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0502_0x1c8de0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c8de0ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0cfb78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0503 | PC: 0x1c9280 | FDE: 0x0cfcb8 | Size: 256 bytes
// Khung tháo gỡ #0503 | Địa chỉ PC: 0x1c9280 | Địa chỉ FDE: 0x0cfcb8 | Kích thước: 256 bytes
//   0x1c9280: AA1E03E3  mov      x3, x30
//   0x1c9284: 940553B8  bl       #0x31e164
//   0x1c9288: AA0303FE  mov      x30, x3
//   0x1c928c: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_0503_0x1c9280(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c9280ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x940553b8ULL) ^ 0x0cfcb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0504 | PC: 0x1c990c | FDE: 0x0cfe08 | Size: 256 bytes
// Khung tháo gỡ #0504 | Địa chỉ PC: 0x1c990c | Địa chỉ FDE: 0x0cfe08 | Kích thước: 256 bytes
//   0x1c990c: AA1E03E3  mov      x3, x30
//   0x1c9910: 94055495  bl       #0x31eb64
//   0x1c9914: AA0303FE  mov      x30, x3
//   0x1c9918: A9137BFD  stp      x29, x30, [sp, #0x130]
static inline uint64_t fde_func_0504_0x1c990c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c990cULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94055495ULL) ^ 0x0cfe08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0505 | PC: 0x1c9e20 | FDE: 0x0cff18 | Size: 256 bytes
// Khung tháo gỡ #0505 | Địa chỉ PC: 0x1c9e20 | Địa chỉ FDE: 0x0cff18 | Kích thước: 256 bytes
//   0x1c9e20: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1c9e24: AA0003F3  mov      x19, x0
//   0x1c9e28: 97FFFFFA  bl       #0x1c9e10
//   0x1c9e2c: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0505_0x1c9e20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1c9e20ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0cff18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0506 | PC: 0x1ca078 | FDE: 0x0d0028 | Size: 256 bytes
// Khung tháo gỡ #0506 | Địa chỉ PC: 0x1ca078 | Địa chỉ FDE: 0x0d0028 | Kích thước: 256 bytes
//   0x1ca078: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x1ca07c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1ca080: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1ca084: 12000075  and      w21, w3, #1
static inline uint64_t fde_func_0506_0x1ca078(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ca078ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0d0028ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0507 | PC: 0x1ca2b8 | FDE: 0x0d0150 | Size: 256 bytes
// Khung tháo gỡ #0507 | Địa chỉ PC: 0x1ca2b8 | Địa chỉ FDE: 0x0d0150 | Kích thước: 256 bytes
//   0x1ca2b8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1ca2bc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1ca2c0: AA0103F3  mov      x19, x1
//   0x1ca2c4: D0000CC1  adrp     x1, #0x364000
static inline uint64_t fde_func_0507_0x1ca2b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ca2b8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d0150ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0508 | PC: 0x1ca570 | FDE: 0x0d0270 | Size: 256 bytes
// Khung tháo gỡ #0508 | Địa chỉ PC: 0x1ca570 | Địa chỉ FDE: 0x0d0270 | Kích thước: 256 bytes
//   0x1ca570: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1ca574: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1ca578: 940558B3  bl       #0x320844
//   0x1ca57c: 54000140  b.eq     #0x1ca5a4
static inline uint64_t fde_func_0508_0x1ca570(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ca570ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d0270ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0509 | PC: 0x1cabbc | FDE: 0x0d03a0 | Size: 256 bytes
// Khung tháo gỡ #0509 | Địa chỉ PC: 0x1cabbc | Địa chỉ FDE: 0x0d03a0 | Kích thước: 256 bytes
//   0x1cabbc: 52800081  mov      w1, #4
//   0x1cabc0: 140060EA  b        #0x1e2f68
//   0x1cabc4: AA1E03E6  mov      x6, x30
//   0x1cabc8: 94055112  bl       #0x31f010
static inline uint64_t fde_func_0509_0x1cabbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1cabbcULL ^ (static_cast<uint64_t>(0x52800081ULL) << 13);
    acc = (acc + a1 + 0x140060eaULL) ^ 0x0d03a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0510 | PC: 0x1cb6b4 | FDE: 0x0d04f0 | Size: 256 bytes
// Khung tháo gỡ #0510 | Địa chỉ PC: 0x1cb6b4 | Địa chỉ FDE: 0x0d04f0 | Kích thước: 256 bytes
//   0x1cb6b4: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x1cb6b8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1cb6bc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1cb6c0: B9409028  ldr      w8, [x1, #0x90]
static inline uint64_t fde_func_0510_0x1cb6b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1cb6b4ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0d04f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0511 | PC: 0x1cc15c | FDE: 0x0d0640 | Size: 256 bytes
// Khung tháo gỡ #0511 | Địa chỉ PC: 0x1cc15c | Địa chỉ FDE: 0x0d0640 | Kích thước: 256 bytes
//   0x1cc15c: AA0003E8  mov      x8, x0
//   0x1cc160: F9400800  ldr      x0, [x0, #0x10]
//   0x1cc164: B4000040  cbz      x0, #0x1cc16c
//   0x1cc168: 14057E3A  b        #0x32ba50
static inline uint64_t fde_func_0511_0x1cc15c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1cc15cULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xf9400800ULL) ^ 0x0d0640ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0512 | PC: 0x1cca08 | FDE: 0x0d0768 | Size: 168 bytes
// Khung tháo gỡ #0512 | Địa chỉ PC: 0x1cca08 | Địa chỉ FDE: 0x0d0768 | Kích thước: 168 bytes
//   0x1cca08: AA1E03E2  mov      x2, x30
//   0x1cca0c: 94055E13  bl       #0x324258
//   0x1cca10: AA0203FE  mov      x30, x2
//   0x1cca14: 39408028  ldrb     w8, [x1, #0x20]
static inline uint64_t fde_func_0512_0x1cca08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1cca08ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94055e13ULL) ^ 0x0d0768ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #0513 | PC: 0x1ccab0 | FDE: 0x0d07a0 | Size: 256 bytes [_ZN4lynx4tasm20FiberElementSelector6SelectEPNS0_12FiberElementERKNS0_17NodeSelectOptionsE]
// Khung tháo gỡ #0513 | Địa chỉ PC: 0x1ccab0 | Địa chỉ FDE: 0x0d07a0 | Kích thước: 256 bytes
//   0x1ccab0: D10443FF  sub      sp, sp, #0x110
//   0x1ccab4: A90C6BFC  stp      x28, x26, [sp, #0xc0]
//   0x1ccab8: A90D63F9  stp      x25, x24, [sp, #0xd0]
//   0x1ccabc: A90E5BF7  stp      x23, x22, [sp, #0xe0]
static inline uint64_t fde_func_0513_0x1ccab0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ccab0ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90c6bfcULL) ^ 0x0d07a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0514 | PC: 0x1cd244 | FDE: 0x0d08d0 | Size: 256 bytes
// Khung tháo gỡ #0514 | Địa chỉ PC: 0x1cd244 | Địa chỉ FDE: 0x0d08d0 | Kích thước: 256 bytes
//   0x1cd244: AA1E03E3  mov      x3, x30
//   0x1cd248: 94054772  bl       #0x31f010
//   0x1cd24c: AA0303FE  mov      x30, x3
//   0x1cd250: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0514_0x1cd244(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1cd244ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94054772ULL) ^ 0x0d08d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0515 | PC: 0x1cd87c | FDE: 0x0d0a18 | Size: 256 bytes
// Khung tháo gỡ #0515 | Địa chỉ PC: 0x1cd87c | Địa chỉ FDE: 0x0d0a18 | Kích thước: 256 bytes
//   0x1cd87c: AA1E03E5  mov      x5, x30
//   0x1cd880: 94054311  bl       #0x31e4c4
//   0x1cd884: AA0503FE  mov      x30, x5
//   0x1cd888: A90D7BFD  stp      x29, x30, [sp, #0xd0]
static inline uint64_t fde_func_0515_0x1cd87c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1cd87cULL ^ (static_cast<uint64_t>(0xaa1e03e5ULL) << 13);
    acc = (acc + a1 + 0x94054311ULL) ^ 0x0d0a18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0516 | PC: 0x1cdca0 | FDE: 0x0d0aa8 | Size: 256 bytes [_ZN4lynx4tasm20FiberElementSelector6SelectERKNSt6__ndk110unique_ptrINS0_14ElementManagerENS2_14default_deleteIS4_EEEERKNS0_14NodeSelectRootERKNS0_17NodeSelectOptionsE]
// Khung tháo gỡ #0516 | Địa chỉ PC: 0x1cdca0 | Địa chỉ FDE: 0x0d0aa8 | Kích thước: 256 bytes
//   0x1cdca0: AA1E03E3  mov      x3, x30
//   0x1cdca4: 94054558  bl       #0x31f204
//   0x1cdca8: AA0303FE  mov      x30, x3
//   0x1cdcac: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_0516_0x1cdca0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1cdca0ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94054558ULL) ^ 0x0d0aa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0517 | PC: 0x1ce0c8 | FDE: 0x0d0b60 | Size: 256 bytes
// Khung tháo gỡ #0517 | Địa chỉ PC: 0x1ce0c8 | Địa chỉ FDE: 0x0d0b60 | Kích thước: 256 bytes
//   0x1ce0c8: AA1E03E2  mov      x2, x30
//   0x1ce0cc: 94053B7C  bl       #0x31cebc
//   0x1ce0d0: AA0203FE  mov      x30, x2
//   0x1ce0d4: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_0517_0x1ce0c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ce0c8ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94053b7cULL) ^ 0x0d0b60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0518 | PC: 0x1cea44 | FDE: 0x0d0cd8 | Size: 256 bytes
// Khung tháo gỡ #0518 | Địa chỉ PC: 0x1cea44 | Địa chỉ FDE: 0x0d0cd8 | Kích thước: 256 bytes
//   0x1cea44: AA1E03E2  mov      x2, x30
//   0x1cea48: 94053989  bl       #0x31d06c
//   0x1cea4c: AA0203FE  mov      x30, x2
//   0x1cea50: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_0518_0x1cea44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1cea44ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94053989ULL) ^ 0x0d0cd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0519 | PC: 0x1cee40 | FDE: 0x0d0e28 | Size: 256 bytes
// Khung tháo gỡ #0519 | Địa chỉ PC: 0x1cee40 | Địa chỉ FDE: 0x0d0e28 | Kích thước: 256 bytes
//   0x1cee40: AA1E03E2  mov      x2, x30
//   0x1cee44: 9405388A  bl       #0x31d06c
//   0x1cee48: AA0203FE  mov      x30, x2
//   0x1cee4c: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_0519_0x1cee40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1cee40ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9405388aULL) ^ 0x0d0e28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0520 | PC: 0x1cf5ec | FDE: 0x0d0f88 | Size: 256 bytes
// Khung tháo gỡ #0520 | Địa chỉ PC: 0x1cf5ec | Địa chỉ FDE: 0x0d0f88 | Kích thước: 256 bytes
//   0x1cf5ec: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1cf5f0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1cf5f4: B201F3E8  mov      x8, #-0x5555555555555556
//   0x1cf5f8: F2955568  movk     x8, #0xaaab
static inline uint64_t fde_func_0520_0x1cf5ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1cf5ecULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d0f88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0521 | PC: 0x1cfa64 | FDE: 0x0d1020 | Size: 256 bytes [_ZN4lynx4tasm17RadonNodeSelector6SelectEPNS0_9RadonBaseERKNS0_17NodeSelectOptionsE]
// Khung tháo gỡ #0521 | Địa chỉ PC: 0x1cfa64 | Địa chỉ FDE: 0x0d1020 | Kích thước: 256 bytes
//   0x1cfa64: D10443FF  sub      sp, sp, #0x110
//   0x1cfa68: F90063FC  str      x28, [sp, #0xc0]
//   0x1cfa6c: A90D63F9  stp      x25, x24, [sp, #0xd0]
//   0x1cfa70: A90E5BF7  stp      x23, x22, [sp, #0xe0]
static inline uint64_t fde_func_0521_0x1cfa64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1cfa64ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xf90063fcULL) ^ 0x0d1020ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0522 | PC: 0x1d0084 | FDE: 0x0d10f8 | Size: 256 bytes
// Khung tháo gỡ #0522 | Địa chỉ PC: 0x1d0084 | Địa chỉ FDE: 0x0d10f8 | Kích thước: 256 bytes
//   0x1d0084: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x1d0088: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x1d008c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1d0090: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0522_0x1d0084(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1d0084ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0d10f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0523 | PC: 0x1d0594 | FDE: 0x0d11d0 | Size: 256 bytes [_ZN4lynx4tasm17RadonNodeSelector6SelectEPNS0_9RadonPageERKNS0_14NodeSelectRootERKNS0_17NodeSelectOptionsE]
// Khung tháo gỡ #0523 | Địa chỉ PC: 0x1d0594 | Địa chỉ FDE: 0x0d11d0 | Kích thước: 256 bytes
//   0x1d0594: AA1E03E3  mov      x3, x30
//   0x1d0598: 94053B1B  bl       #0x31f204
//   0x1d059c: AA0303FE  mov      x30, x3
//   0x1d05a0: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_0523_0x1d0594(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1d0594ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94053b1bULL) ^ 0x0d11d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0524 | PC: 0x1d0708 | FDE: 0x0d1240 | Size: 256 bytes [_ZN4lynx9starlight12LayoutObject16SetSLMeasureFuncEPF9FloatSizePvRKNSt6__ndk15arrayINS0_17OneSideConstraintELm2EEEbE]
// Khung tháo gỡ #0524 | Địa chỉ PC: 0x1d0708 | Địa chỉ FDE: 0x0d1240 | Kích thước: 256 bytes
//   0x1d0708: F9002401  str      x1, [x0, #0x48]
//   0x1d070c: D65F03C0  ret      
//   0x1d0710: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1d0714: A9017BF3  stp      x19, x30, [sp, #0x10]
static inline uint64_t fde_func_0524_0x1d0708(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1d0708ULL ^ (static_cast<uint64_t>(0xf9002401ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0d1240ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0525 | PC: 0x1d0938 | FDE: 0x0d1368 | Size: 256 bytes
// Khung tháo gỡ #0525 | Địa chỉ PC: 0x1d0938 | Địa chỉ FDE: 0x0d1368 | Kích thước: 256 bytes
//   0x1d0938: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1d093c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1d0940: 94058BB6  bl       #0x333818
//   0x1d0944: B40000D4  cbz      x20, #0x1d095c
static inline uint64_t fde_func_0525_0x1d0938(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1d0938ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d1368ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0526 | PC: 0x1d0be8 | FDE: 0x0d1498 | Size: 256 bytes
// Khung tháo gỡ #0526 | Địa chỉ PC: 0x1d0be8 | Địa chỉ FDE: 0x0d1498 | Kích thước: 256 bytes
//   0x1d0be8: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1d0bec: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1d0bf0: 940537F6  bl       #0x31ebc8
//   0x1d0bf4: B4000153  cbz      x19, #0x1d0c1c
static inline uint64_t fde_func_0526_0x1d0be8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1d0be8ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d1498ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0527 | PC: 0x1d1554 | FDE: 0x0d15f8 | Size: 256 bytes
// Khung tháo gỡ #0527 | Địa chỉ PC: 0x1d1554 | Địa chỉ FDE: 0x0d15f8 | Kích thước: 256 bytes
//   0x1d1554: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1d1558: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1d155c: 94052BB6  bl       #0x31c434
//   0x1d1560: 97FFE404  bl       #0x1ca570
static inline uint64_t fde_func_0527_0x1d1554(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1d1554ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d15f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0528 | PC: 0x1d1cd0 | FDE: 0x0d1748 | Size: 256 bytes
// Khung tháo gỡ #0528 | Địa chỉ PC: 0x1d1cd0 | Địa chỉ FDE: 0x0d1748 | Kích thước: 256 bytes
//   0x1d1cd0: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1d1cd4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1d1cd8: AA0203F3  mov      x19, x2
//   0x1d1cdc: 94052C82  bl       #0x31cee4
static inline uint64_t fde_func_0528_0x1d1cd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1d1cd0ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d1748ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0529 | PC: 0x1d1f9c | FDE: 0x0d1868 | Size: 256 bytes
// Khung tháo gỡ #0529 | Địa chỉ PC: 0x1d1f9c | Địa chỉ FDE: 0x0d1868 | Kích thước: 256 bytes
//   0x1d1f9c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1d1fa0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1d1fa4: F9405808  ldr      x8, [x0, #0xb0]
//   0x1d1fa8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0529_0x1d1f9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1d1f9cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d1868ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0530 | PC: 0x1d24f8 | FDE: 0x0d19b0 | Size: 256 bytes
// Khung tháo gỡ #0530 | Địa chỉ PC: 0x1d24f8 | Địa chỉ FDE: 0x0d19b0 | Kích thước: 256 bytes
//   0x1d24f8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1d24fc: AA0003F3  mov      x19, x0
//   0x1d2500: 97FFFFC2  bl       #0x1d2408
//   0x1d2504: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0530_0x1d24f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1d24f8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0d19b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0531 | PC: 0x1d2ec0 | FDE: 0x0d1ad8 | Size: 256 bytes
// Khung tháo gỡ #0531 | Địa chỉ PC: 0x1d2ec0 | Địa chỉ FDE: 0x0d1ad8 | Kích thước: 256 bytes
//   0x1d2ec0: F9406800  ldr      x0, [x0, #0xd0]
//   0x1d2ec4: D65F03C0  ret      
//   0x1d2ec8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1d2ecc: A9017BF3  stp      x19, x30, [sp, #0x10]
static inline uint64_t fde_func_0531_0x1d2ec0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1d2ec0ULL ^ (static_cast<uint64_t>(0xf9406800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0d1ad8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0532 | PC: 0x1d31fc | FDE: 0x0d1c00 | Size: 256 bytes
// Khung tháo gỡ #0532 | Địa chỉ PC: 0x1d31fc | Địa chỉ FDE: 0x0d1c00 | Kích thước: 256 bytes
//   0x1d31fc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1d3200: 3941A808  ldrb     w8, [x0, #0x6a]
//   0x1d3204: AA0003F3  mov      x19, x0
//   0x1d3208: 9405561F  bl       #0x328a84
static inline uint64_t fde_func_0532_0x1d31fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1d31fcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x3941a808ULL) ^ 0x0d1c00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0533 | PC: 0x1d371c | FDE: 0x0d1d10 | Size: 256 bytes
// Khung tháo gỡ #0533 | Địa chỉ PC: 0x1d371c | Địa chỉ FDE: 0x0d1d10 | Kích thước: 256 bytes
//   0x1d371c: D100C3FF  sub      sp, sp, #0x30
//   0x1d3720: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1d3724: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1d3728: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0533_0x1d371c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1d371cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0d1d10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0534 | PC: 0x1d4144 | FDE: 0x0d1e50 | Size: 256 bytes
// Khung tháo gỡ #0534 | Địa chỉ PC: 0x1d4144 | Địa chỉ FDE: 0x0d1e50 | Kích thước: 256 bytes
//   0x1d4144: AA1E03E3  mov      x3, x30
//   0x1d4148: 94052DDA  bl       #0x31f8b0
//   0x1d414c: AA0303FE  mov      x30, x3
//   0x1d4150: A9147BFD  stp      x29, x30, [sp, #0x140]
static inline uint64_t fde_func_0534_0x1d4144(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1d4144ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94052ddaULL) ^ 0x0d1e50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0535 | PC: 0x1d47f4 | FDE: 0x0d1f78 | Size: 256 bytes
// Khung tháo gỡ #0535 | Địa chỉ PC: 0x1d47f4 | Địa chỉ FDE: 0x0d1f78 | Kích thước: 256 bytes
//   0x1d47f4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1d47f8: AA0003F3  mov      x19, x0
//   0x1d47fc: B8008401  str      w1, [x0], #8
//   0x1d4800: AA0203E1  mov      x1, x2
static inline uint64_t fde_func_0535_0x1d47f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1d47f4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0d1f78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0536 | PC: 0x1d4ad4 | FDE: 0x0d2090 | Size: 256 bytes
// Khung tháo gỡ #0536 | Địa chỉ PC: 0x1d4ad4 | Địa chỉ FDE: 0x0d2090 | Kích thước: 256 bytes
//   0x1d4ad4: B40001A2  cbz      x2, #0x1d4b08
//   0x1d4ad8: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1d4adc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1d4ae0: AA0103F5  mov      x21, x1
static inline uint64_t fde_func_0536_0x1d4ad4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1d4ad4ULL ^ (static_cast<uint64_t>(0xb40001a2ULL) << 13);
    acc = (acc + a1 + 0xa9be53f5ULL) ^ 0x0d2090ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0537 | PC: 0x1d5164 | FDE: 0x0d21e0 | Size: 256 bytes
// Khung tháo gỡ #0537 | Địa chỉ PC: 0x1d5164 | Địa chỉ FDE: 0x0d21e0 | Kích thước: 256 bytes
//   0x1d5164: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1d5168: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1d516c: AA0003F4  mov      x20, x0
//   0x1d5170: 9107C000  add      x0, x0, #0x1f0
static inline uint64_t fde_func_0537_0x1d5164(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1d5164ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d21e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0538 | PC: 0x1d59c4 | FDE: 0x0d2328 | Size: 256 bytes
// Khung tháo gỡ #0538 | Địa chỉ PC: 0x1d59c4 | Địa chỉ FDE: 0x0d2328 | Kích thước: 256 bytes
//   0x1d59c4: D10583FF  sub      sp, sp, #0x160
//   0x1d59c8: A9135BFC  stp      x28, x22, [sp, #0x130]
//   0x1d59cc: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x1d59d0: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0538_0x1d59c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1d59c4ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa9135bfcULL) ^ 0x0d2328ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0539 | PC: 0x1d5d34 | FDE: 0x0d2458 | Size: 256 bytes
// Khung tháo gỡ #0539 | Địa chỉ PC: 0x1d5d34 | Địa chỉ FDE: 0x0d2458 | Kích thước: 256 bytes
//   0x1d5d34: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1d5d38: 97FF104E  bl       #0x199e70
//   0x1d5d3c: 531F7C00  lsr      w0, w0, #0x1f
//   0x1d5d40: F84107FE  ldr      x30, [sp], #0x10
static inline uint64_t fde_func_0539_0x1d5d34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1d5d34ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x97ff104eULL) ^ 0x0d2458ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0540 | PC: 0x1d61ac | FDE: 0x0d2588 | Size: 256 bytes
// Khung tháo gỡ #0540 | Địa chỉ PC: 0x1d61ac | Địa chỉ FDE: 0x0d2588 | Kích thước: 256 bytes
//   0x1d61ac: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1d61b0: AA0003F3  mov      x19, x0
//   0x1d61b4: 97FFFFF6  bl       #0x1d618c
//   0x1d61b8: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0540_0x1d61ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1d61acULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0d2588ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0541 | PC: 0x1d6658 | FDE: 0x0d26b8 | Size: 256 bytes
// Khung tháo gỡ #0541 | Địa chỉ PC: 0x1d6658 | Địa chỉ FDE: 0x0d26b8 | Kích thước: 256 bytes
//   0x1d6658: 528000C2  mov      w2, #6
//   0x1d665c: 14000087  b        #0x1d6878
//   0x1d6660: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1d6664: A9017BF3  stp      x19, x30, [sp, #0x10]
static inline uint64_t fde_func_0541_0x1d6658(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1d6658ULL ^ (static_cast<uint64_t>(0x528000c2ULL) << 13);
    acc = (acc + a1 + 0x14000087ULL) ^ 0x0d26b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0542 | PC: 0x1d6d9c | FDE: 0x0d27e8 | Size: 256 bytes
// Khung tháo gỡ #0542 | Địa chỉ PC: 0x1d6d9c | Địa chỉ FDE: 0x0d27e8 | Kích thước: 256 bytes
//   0x1d6d9c: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x1d6da0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1d6da4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1d6da8: 910D0015  add      x21, x0, #0x340
static inline uint64_t fde_func_0542_0x1d6d9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1d6d9cULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0d27e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0543 | PC: 0x1d74b4 | FDE: 0x0d2928 | Size: 256 bytes
// Khung tháo gỡ #0543 | Địa chỉ PC: 0x1d74b4 | Địa chỉ FDE: 0x0d2928 | Kích thước: 256 bytes
//   0x1d74b4: D100C3FF  sub      sp, sp, #0x30
//   0x1d74b8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1d74bc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1d74c0: 94052F2E  bl       #0x323178
static inline uint64_t fde_func_0543_0x1d74b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1d74b4ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0d2928ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0544 | PC: 0x1d75d4 | FDE: 0x0d2998 | Size: 256 bytes [_ZN4lynx4tasm14RadonComponent11ComponentIdEv]
// Khung tháo gỡ #0544 | Địa chỉ PC: 0x1d75d4 | Địa chỉ FDE: 0x0d2998 | Kích thước: 256 bytes
//   0x1d75d4: B941BC00  ldr      w0, [x0, #0x1bc]
//   0x1d75d8: D65F03C0  ret      
//   0x1d75dc: AA1E03E4  mov      x4, x30
//   0x1d75e0: 94056743  bl       #0x3312ec
static inline uint64_t fde_func_0544_0x1d75d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1d75d4ULL ^ (static_cast<uint64_t>(0xb941bc00ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0d2998ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0545 | PC: 0x1d77b0 | FDE: 0x0d2a50 | Size: 256 bytes
// Khung tháo gỡ #0545 | Địa chỉ PC: 0x1d77b0 | Địa chỉ FDE: 0x0d2a50 | Kích thước: 256 bytes
//   0x1d77b0: 2A1F03E8  mov      w8, wzr
//   0x1d77b4: B40000E1  cbz      x1, #0x1d77d0
//   0x1d77b8: B9439809  ldr      w9, [x0, #0x398]
//   0x1d77bc: 6B09011F  cmp      w8, w9
static inline uint64_t fde_func_0545_0x1d77b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1d77b0ULL ^ (static_cast<uint64_t>(0x2a1f03e8ULL) << 13);
    acc = (acc + a1 + 0xb40000e1ULL) ^ 0x0d2a50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0546 | PC: 0x1d7d18 | FDE: 0x0d2b78 | Size: 256 bytes
// Khung tháo gỡ #0546 | Địa chỉ PC: 0x1d7d18 | Địa chỉ FDE: 0x0d2b78 | Kích thước: 256 bytes
//   0x1d7d18: D1082000  sub      x0, x0, #0x208
//   0x1d7d1c: 17FFFF60  b        #0x1d7a9c
//   0x1d7d20: D1082000  sub      x0, x0, #0x208
//   0x1d7d24: 17FFFF64  b        #0x1d7ab4
static inline uint64_t fde_func_0546_0x1d7d18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1d7d18ULL ^ (static_cast<uint64_t>(0xd1082000ULL) << 13);
    acc = (acc + a1 + 0x17ffff60ULL) ^ 0x0d2b78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0547 | PC: 0x1d7fc8 | FDE: 0x0d2c98 | Size: 256 bytes
// Khung tháo gỡ #0547 | Địa chỉ PC: 0x1d7fc8 | Địa chỉ FDE: 0x0d2c98 | Kích thước: 256 bytes
//   0x1d7fc8: D10183FF  sub      sp, sp, #0x60
//   0x1d7fcc: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x1d7fd0: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x1d7fd4: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0547_0x1d7fc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1d7fc8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9035bf7ULL) ^ 0x0d2c98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0548 | PC: 0x1d92b4 | FDE: 0x0d2de0 | Size: 256 bytes
// Khung tháo gỡ #0548 | Địa chỉ PC: 0x1d92b4 | Địa chỉ FDE: 0x0d2de0 | Kích thước: 256 bytes
//   0x1d92b4: D100C3FF  sub      sp, sp, #0x30
//   0x1d92b8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1d92bc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1d92c0: 394DEC08  ldrb     w8, [x0, #0x37b]
static inline uint64_t fde_func_0548_0x1d92b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1d92b4ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0d2de0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0549 | PC: 0x1d98f8 | FDE: 0x0d2f18 | Size: 256 bytes
// Khung tháo gỡ #0549 | Địa chỉ PC: 0x1d98f8 | Địa chỉ FDE: 0x0d2f18 | Kích thước: 256 bytes
//   0x1d98f8: D1082000  sub      x0, x0, #0x208
//   0x1d98fc: 17FFFF65  b        #0x1d9690
//   0x1d9900: D1082000  sub      x0, x0, #0x208
//   0x1d9904: 17FFFE8E  b        #0x1d933c
static inline uint64_t fde_func_0549_0x1d98f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1d98f8ULL ^ (static_cast<uint64_t>(0xd1082000ULL) << 13);
    acc = (acc + a1 + 0x17ffff65ULL) ^ 0x0d2f18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0550 | PC: 0x1da014 | FDE: 0x0d3030 | Size: 256 bytes
// Khung tháo gỡ #0550 | Địa chỉ PC: 0x1da014 | Địa chỉ FDE: 0x0d3030 | Kích thước: 256 bytes
//   0x1da014: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x1da018: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x1da01c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1da020: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0550_0x1da014(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1da014ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0d3030ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0551 | PC: 0x1da674 | FDE: 0x0d3168 | Size: 256 bytes
// Khung tháo gỡ #0551 | Địa chỉ PC: 0x1da674 | Địa chỉ FDE: 0x0d3168 | Kích thước: 256 bytes
//   0x1da674: AA1E03E2  mov      x2, x30
//   0x1da678: 94050EBB  bl       #0x31e164
//   0x1da67c: AA0203FE  mov      x30, x2
//   0x1da680: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_0551_0x1da674(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1da674ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94050ebbULL) ^ 0x0d3168ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0552 | PC: 0x1da9d8 | FDE: 0x0d3288 | Size: 256 bytes
// Khung tháo gỡ #0552 | Địa chỉ PC: 0x1da9d8 | Địa chỉ FDE: 0x0d3288 | Kích thước: 256 bytes
//   0x1da9d8: D1050000  sub      x0, x0, #0x140
//   0x1da9dc: 17FFFEEB  b        #0x1da588
//   0x1da9e0: D10103FF  sub      sp, sp, #0x40
//   0x1da9e4: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0552_0x1da9d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1da9d8ULL ^ (static_cast<uint64_t>(0xd1050000ULL) << 13);
    acc = (acc + a1 + 0x17fffeebULL) ^ 0x0d3288ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0553 | PC: 0x1db0a0 | FDE: 0x0d33c0 | Size: 256 bytes
// Khung tháo gỡ #0553 | Địa chỉ PC: 0x1db0a0 | Địa chỉ FDE: 0x0d33c0 | Kích thước: 256 bytes
//   0x1db0a0: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1db0a4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1db0a8: 9405078F  bl       #0x31cee4
//   0x1db0ac: F9017C04  str      x4, [x0, #0x2f8]
static inline uint64_t fde_func_0553_0x1db0a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1db0a0ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d33c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0554 | PC: 0x1db5e8 | FDE: 0x0d34e8 | Size: 256 bytes
// Khung tháo gỡ #0554 | Địa chỉ PC: 0x1db5e8 | Địa chỉ FDE: 0x0d34e8 | Kích thước: 256 bytes
//   0x1db5e8: D10083FF  sub      sp, sp, #0x20
//   0x1db5ec: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1db5f0: F941E808  ldr      x8, [x0, #0x3d0]
//   0x1db5f4: B40001A8  cbz      x8, #0x1db628
static inline uint64_t fde_func_0554_0x1db5e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1db5e8ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d34e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0555 | PC: 0x1dbe40 | FDE: 0x0d3638 | Size: 256 bytes
// Khung tháo gỡ #0555 | Địa chỉ PC: 0x1dbe40 | Địa chỉ FDE: 0x0d3638 | Kích thước: 256 bytes
//   0x1dbe40: D1082000  sub      x0, x0, #0x208
//   0x1dbe44: 17FFFF23  b        #0x1dbad0
//   0x1dbe48: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x1dbe4c: A9015BF7  stp      x23, x22, [sp, #0x10]
static inline uint64_t fde_func_0555_0x1dbe40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1dbe40ULL ^ (static_cast<uint64_t>(0xd1082000ULL) << 13);
    acc = (acc + a1 + 0x17ffff23ULL) ^ 0x0d3638ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0556 | PC: 0x1dc184 | FDE: 0x0d3750 | Size: 256 bytes
// Khung tháo gỡ #0556 | Địa chỉ PC: 0x1dc184 | Địa chỉ FDE: 0x0d3750 | Kích thước: 256 bytes
//   0x1dc184: F9406400  ldr      x0, [x0, #0xc8]
//   0x1dc188: 17FF9680  b        #0x1c1b88
//   0x1dc18c: F81C0FFC  str      x28, [sp, #-0x40]!
//   0x1dc190: A9015BF7  stp      x23, x22, [sp, #0x10]
static inline uint64_t fde_func_0556_0x1dc184(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1dc184ULL ^ (static_cast<uint64_t>(0xf9406400ULL) << 13);
    acc = (acc + a1 + 0x17ff9680ULL) ^ 0x0d3750ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0557 | PC: 0x1dd104 | FDE: 0x0d38b8 | Size: 256 bytes
// Khung tháo gỡ #0557 | Địa chỉ PC: 0x1dd104 | Địa chỉ FDE: 0x0d38b8 | Kích thước: 256 bytes
//   0x1dd104: AA1E03E5  mov      x5, x30
//   0x1dd108: 94050135  bl       #0x31d5dc
//   0x1dd10c: AA0503FE  mov      x30, x5
//   0x1dd110: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0557_0x1dd104(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1dd104ULL ^ (static_cast<uint64_t>(0xaa1e03e5ULL) << 13);
    acc = (acc + a1 + 0x94050135ULL) ^ 0x0d38b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0558 | PC: 0x1dd68c | FDE: 0x0d3a00 | Size: 256 bytes
// Khung tháo gỡ #0558 | Địa chỉ PC: 0x1dd68c | Địa chỉ FDE: 0x0d3a00 | Kích thước: 256 bytes
//   0x1dd68c: F9406008  ldr      x8, [x0, #0xc0]
//   0x1dd690: F9401500  ldr      x0, [x8, #0x28]
//   0x1dd694: 3942D008  ldrb     w8, [x0, #0xb4]
//   0x1dd698: 34000048  cbz      w8, #0x1dd6a0
static inline uint64_t fde_func_0558_0x1dd68c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1dd68cULL ^ (static_cast<uint64_t>(0xf9406008ULL) << 13);
    acc = (acc + a1 + 0xf9401500ULL) ^ 0x0d3a00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0559 | PC: 0x1de564 | FDE: 0x0d3b30 | Size: 256 bytes
// Khung tháo gỡ #0559 | Địa chỉ PC: 0x1de564 | Địa chỉ FDE: 0x0d3b30 | Kích thước: 256 bytes
//   0x1de564: AA1E03E1  mov      x1, x30
//   0x1de568: 9405085B  bl       #0x3206d4
//   0x1de56c: AA0103FE  mov      x30, x1
//   0x1de570: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0559_0x1de564(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1de564ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x9405085bULL) ^ 0x0d3b30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0560 | PC: 0x1dee58 | FDE: 0x0d3c68 | Size: 256 bytes
// Khung tháo gỡ #0560 | Địa chỉ PC: 0x1dee58 | Địa chỉ FDE: 0x0d3c68 | Kích thước: 256 bytes
//   0x1dee58: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1dee5c: 9405821C  bl       #0x33f6cc
//   0x1dee60: 91002260  add      x0, x19, #8
//   0x1dee64: A8C17BF3  ldp      x19, x30, [sp], #0x10
static inline uint64_t fde_func_0560_0x1dee58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1dee58ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9405821cULL) ^ 0x0d3c68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0561 | PC: 0x1df0d8 | FDE: 0x0d3d68 | Size: 256 bytes
// Khung tháo gỡ #0561 | Địa chỉ PC: 0x1df0d8 | Địa chỉ FDE: 0x0d3d68 | Kích thước: 256 bytes
//   0x1df0d8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1df0dc: AA0003F3  mov      x19, x0
//   0x1df0e0: 97FFFFFA  bl       #0x1df0c8
//   0x1df0e4: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0561_0x1df0d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1df0d8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0d3d68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0562 | PC: 0x1df458 | FDE: 0x0d3e98 | Size: 256 bytes
// Khung tháo gỡ #0562 | Địa chỉ PC: 0x1df458 | Địa chỉ FDE: 0x0d3e98 | Kích thước: 256 bytes
//   0x1df458: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1df45c: 94054DC7  bl       #0x332b78
//   0x1df460: B40002A0  cbz      x0, #0x1df4b4
//   0x1df464: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0562_0x1df458(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1df458ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94054dc7ULL) ^ 0x0d3e98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0563 | PC: 0x1df908 | FDE: 0x0d3fb8 | Size: 256 bytes
// Khung tháo gỡ #0563 | Địa chỉ PC: 0x1df908 | Địa chỉ FDE: 0x0d3fb8 | Kích thước: 256 bytes
//   0x1df908: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x1df90c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x1df910: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1df914: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0563_0x1df908(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1df908ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0d3fb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0564 | PC: 0x1dfe84 | FDE: 0x0d40e0 | Size: 256 bytes
// Khung tháo gỡ #0564 | Địa chỉ PC: 0x1dfe84 | Địa chỉ FDE: 0x0d40e0 | Kích thước: 256 bytes
//   0x1dfe84: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1dfe88: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1dfe8c: AA0003F4  mov      x20, x0
//   0x1dfe90: 52800200  mov      w0, #0x10
static inline uint64_t fde_func_0564_0x1dfe84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1dfe84ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d40e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0565 | PC: 0x1e0364 | FDE: 0x0d4220 | Size: 256 bytes
// Khung tháo gỡ #0565 | Địa chỉ PC: 0x1e0364 | Địa chỉ FDE: 0x0d4220 | Kích thước: 256 bytes
//   0x1e0364: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1e0368: B9401008  ldr      w8, [x0, #0x10]
//   0x1e036c: 34000268  cbz      w8, #0x1e03b8
//   0x1e0370: F9400409  ldr      x9, [x0, #8]
static inline uint64_t fde_func_0565_0x1e0364(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e0364ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb9401008ULL) ^ 0x0d4220ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0566 | PC: 0x1e0804 | FDE: 0x0d4340 | Size: 256 bytes
// Khung tháo gỡ #0566 | Địa chỉ PC: 0x1e0804 | Địa chỉ FDE: 0x0d4340 | Kích thước: 256 bytes
//   0x1e0804: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1e0808: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1e080c: F9406008  ldr      x8, [x0, #0xc0]
//   0x1e0810: 9404EF09  bl       #0x31c434
static inline uint64_t fde_func_0566_0x1e0804(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e0804ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d4340ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0567 | PC: 0x1e1008 | FDE: 0x0d4488 | Size: 256 bytes
// Khung tháo gỡ #0567 | Địa chỉ PC: 0x1e1008 | Địa chỉ FDE: 0x0d4488 | Kích thước: 256 bytes
//   0x1e1008: D1050000  sub      x0, x0, #0x140
//   0x1e100c: 17FFFDB7  b        #0x1e06e8
//   0x1e1010: D100C3FF  sub      sp, sp, #0x30
//   0x1e1014: A9027BF3  stp      x19, x30, [sp, #0x20]
static inline uint64_t fde_func_0567_0x1e1008(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e1008ULL ^ (static_cast<uint64_t>(0xd1050000ULL) << 13);
    acc = (acc + a1 + 0x17fffdb7ULL) ^ 0x0d4488ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0568 | PC: 0x1e1434 | FDE: 0x0d45c0 | Size: 256 bytes
// Khung tháo gỡ #0568 | Địa chỉ PC: 0x1e1434 | Địa chỉ FDE: 0x0d45c0 | Kích thước: 256 bytes
//   0x1e1434: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1e1438: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1e143c: AA0003F3  mov      x19, x0
//   0x1e1440: 9405175F  bl       #0x3271bc
static inline uint64_t fde_func_0568_0x1e1434(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e1434ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d45c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0569 | PC: 0x1e2200 | FDE: 0x0d4710 | Size: 256 bytes
// Khung tháo gỡ #0569 | Địa chỉ PC: 0x1e2200 | Địa chỉ FDE: 0x0d4710 | Kích thước: 256 bytes
//   0x1e2200: AA1E03E2  mov      x2, x30
//   0x1e2204: 9404F383  bl       #0x31f010
//   0x1e2208: AA0203FE  mov      x30, x2
//   0x1e220c: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0569_0x1e2200(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e2200ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9404f383ULL) ^ 0x0d4710ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0570 | PC: 0x1e26a8 | FDE: 0x0d4840 | Size: 256 bytes
// Khung tháo gỡ #0570 | Địa chỉ PC: 0x1e26a8 | Địa chỉ FDE: 0x0d4840 | Kích thước: 256 bytes
//   0x1e26a8: D10203FF  sub      sp, sp, #0x80
//   0x1e26ac: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x1e26b0: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x1e26b4: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0570_0x1e26a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e26a8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9055bf7ULL) ^ 0x0d4840ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0571 | PC: 0x1e2a78 | FDE: 0x0d4970 | Size: 256 bytes
// Khung tháo gỡ #0571 | Địa chỉ PC: 0x1e2a78 | Địa chỉ FDE: 0x0d4970 | Kích thước: 256 bytes
//   0x1e2a78: D100C3FF  sub      sp, sp, #0x30
//   0x1e2a7c: F9000BF4  str      x20, [sp, #0x10]
//   0x1e2a80: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1e2a84: 9404F528  bl       #0x31ff24
static inline uint64_t fde_func_0571_0x1e2a78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e2a78ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x0d4970ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0572 | PC: 0x1e2c58 | FDE: 0x0d4a78 | Size: 256 bytes
// Khung tháo gỡ #0572 | Địa chỉ PC: 0x1e2c58 | Địa chỉ FDE: 0x0d4a78 | Kích thước: 256 bytes
//   0x1e2c58: A941A009  ldp      x9, x8, [x0, #0x18]
//   0x1e2c5c: 12000043  and      w3, w2, #1
//   0x1e2c60: AA1E03E4  mov      x4, x30
//   0x1e2c64: 94055292  bl       #0x3376ac
static inline uint64_t fde_func_0572_0x1e2c58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e2c58ULL ^ (static_cast<uint64_t>(0xa941a009ULL) << 13);
    acc = (acc + a1 + 0x12000043ULL) ^ 0x0d4a78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0573 | PC: 0x1e2da4 | FDE: 0x0d4b70 | Size: 256 bytes
// Khung tháo gỡ #0573 | Địa chỉ PC: 0x1e2da4 | Địa chỉ FDE: 0x0d4b70 | Kích thước: 256 bytes
//   0x1e2da4: F9401008  ldr      x8, [x0, #0x20]
//   0x1e2da8: AA1E03E1  mov      x1, x30
//   0x1e2dac: 94050234  bl       #0x32367c
//   0x1e2db0: AA0103FE  mov      x30, x1
static inline uint64_t fde_func_0573_0x1e2da4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e2da4ULL ^ (static_cast<uint64_t>(0xf9401008ULL) << 13);
    acc = (acc + a1 + 0xaa1e03e1ULL) ^ 0x0d4b70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0574 | PC: 0x1e3084 | FDE: 0x0d4c88 | Size: 256 bytes
// Khung tháo gỡ #0574 | Địa chỉ PC: 0x1e3084 | Địa chỉ FDE: 0x0d4c88 | Kích thước: 256 bytes
//   0x1e3084: D10303FF  sub      sp, sp, #0xc0
//   0x1e3088: AA1E03E2  mov      x2, x30
//   0x1e308c: 940508EC  bl       #0x32543c
//   0x1e3090: AA0203FE  mov      x30, x2
static inline uint64_t fde_func_0574_0x1e3084(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e3084ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xaa1e03e2ULL) ^ 0x0d4c88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0575 | PC: 0x1e399c | FDE: 0x0d4db8 | Size: 256 bytes
// Khung tháo gỡ #0575 | Địa chỉ PC: 0x1e399c | Địa chỉ FDE: 0x0d4db8 | Kích thước: 256 bytes
//   0x1e399c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1e39a0: AA0003F3  mov      x19, x0
//   0x1e39a4: 97FFFFCE  bl       #0x1e38dc
//   0x1e39a8: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0575_0x1e399c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e399cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0d4db8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0576 | PC: 0x1e45cc | FDE: 0x0d4f20 | Size: 256 bytes
// Khung tháo gỡ #0576 | Địa chỉ PC: 0x1e45cc | Địa chỉ FDE: 0x0d4f20 | Kích thước: 256 bytes
//   0x1e45cc: A941A009  ldp      x9, x8, [x0, #0x18]
//   0x1e45d0: AA0203E3  mov      x3, x2
//   0x1e45d4: F9402508  ldr      x8, [x8, #0x48]
//   0x1e45d8: B9404929  ldr      w9, [x9, #0x48]
static inline uint64_t fde_func_0576_0x1e45cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e45ccULL ^ (static_cast<uint64_t>(0xa941a009ULL) << 13);
    acc = (acc + a1 + 0xaa0203e3ULL) ^ 0x0d4f20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0577 | PC: 0x1e4da8 | FDE: 0x0d5070 | Size: 256 bytes
// Khung tháo gỡ #0577 | Địa chỉ PC: 0x1e4da8 | Địa chỉ FDE: 0x0d5070 | Kích thước: 256 bytes
//   0x1e4da8: AA1E03E7  mov      x7, x30
//   0x1e4dac: 9404DFC2  bl       #0x31ccb4
//   0x1e4db0: AA0703FE  mov      x30, x7
//   0x1e4db4: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0577_0x1e4da8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e4da8ULL ^ (static_cast<uint64_t>(0xaa1e03e7ULL) << 13);
    acc = (acc + a1 + 0x9404dfc2ULL) ^ 0x0d5070ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0578 | PC: 0x1e56cc | FDE: 0x0d51a8 | Size: 256 bytes
// Khung tháo gỡ #0578 | Địa chỉ PC: 0x1e56cc | Địa chỉ FDE: 0x0d51a8 | Kích thước: 256 bytes
//   0x1e56cc: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1e56d0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1e56d4: F9401808  ldr      x8, [x0, #0x30]
//   0x1e56d8: AA0203F3  mov      x19, x2
static inline uint64_t fde_func_0578_0x1e56cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e56ccULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d51a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0579 | PC: 0x1e5fac | FDE: 0x0d52c0 | Size: 256 bytes
// Khung tháo gỡ #0579 | Địa chỉ PC: 0x1e5fac | Địa chỉ FDE: 0x0d52c0 | Kích thước: 256 bytes
//   0x1e5fac: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1e5fb0: AA0003F3  mov      x19, x0
//   0x1e5fb4: 9404D8C6  bl       #0x31c2cc
//   0x1e5fb8: D0000B48  adrp     x8, #0x34f000
static inline uint64_t fde_func_0579_0x1e5fac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e5facULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0d52c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0580 | PC: 0x1e64c8 | FDE: 0x0d53e0 | Size: 256 bytes
// Khung tháo gỡ #0580 | Địa chỉ PC: 0x1e64c8 | Địa chỉ FDE: 0x0d53e0 | Kích thước: 256 bytes
//   0x1e64c8: AA1E03E5  mov      x5, x30
//   0x1e64cc: 9404E348  bl       #0x31f1ec
//   0x1e64d0: AA0503FE  mov      x30, x5
//   0x1e64d4: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_0580_0x1e64c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e64c8ULL ^ (static_cast<uint64_t>(0xaa1e03e5ULL) << 13);
    acc = (acc + a1 + 0x9404e348ULL) ^ 0x0d53e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0581 | PC: 0x1e68b0 | FDE: 0x0d5500 | Size: 256 bytes
// Khung tháo gỡ #0581 | Địa chỉ PC: 0x1e68b0 | Địa chỉ FDE: 0x0d5500 | Kích thước: 256 bytes
//   0x1e68b0: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1e68b4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1e68b8: A9402408  ldp      x8, x9, [x0]
//   0x1e68bc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0581_0x1e68b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e68b0ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d5500ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0582 | PC: 0x1e6e34 | FDE: 0x0d5640 | Size: 256 bytes
// Khung tháo gỡ #0582 | Địa chỉ PC: 0x1e6e34 | Địa chỉ FDE: 0x0d5640 | Kích thước: 256 bytes
//   0x1e6e34: D10183FF  sub      sp, sp, #0x60
//   0x1e6e38: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x1e6e3c: A9057BF3  stp      x19, x30, [sp, #0x50]
//   0x1e6e40: 9404F296  bl       #0x323898
static inline uint64_t fde_func_0582_0x1e6e34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e6e34ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90453f5ULL) ^ 0x0d5640ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0583 | PC: 0x1e73a4 | FDE: 0x0d5768 | Size: 256 bytes
// Khung tháo gỡ #0583 | Địa chỉ PC: 0x1e73a4 | Địa chỉ FDE: 0x0d5768 | Kích thước: 256 bytes
//   0x1e73a4: D10203FF  sub      sp, sp, #0x80
//   0x1e73a8: F9002BF6  str      x22, [sp, #0x50]
//   0x1e73ac: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x1e73b0: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0583_0x1e73a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e73a4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf6ULL) ^ 0x0d5768ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0584 | PC: 0x1e75a4 | FDE: 0x0d57a0 | Size: 256 bytes [_ZN4lynx4tasm14ElementManager13OnPatchFinishERNSt6__ndk110shared_ptrINS0_15PipelineOptionsEEEPNS0_7ElementE]
// Khung tháo gỡ #0584 | Địa chỉ PC: 0x1e75a4 | Địa chỉ FDE: 0x0d57a0 | Kích thước: 256 bytes
//   0x1e75a4: AA1E03E3  mov      x3, x30
//   0x1e75a8: 9404E95F  bl       #0x321b24
//   0x1e75ac: AA0303FE  mov      x30, x3
//   0x1e75b0: A90A7BF3  stp      x19, x30, [sp, #0xa0]
static inline uint64_t fde_func_0584_0x1e75a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e75a4ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x9404e95fULL) ^ 0x0d57a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0585 | PC: 0x1e7cb0 | FDE: 0x0d5898 | Size: 256 bytes
// Khung tháo gỡ #0585 | Địa chỉ PC: 0x1e7cb0 | Địa chỉ FDE: 0x0d5898 | Kích thước: 256 bytes
//   0x1e7cb0: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1e7cb4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1e7cb8: AA0003F3  mov      x19, x0
//   0x1e7cbc: F9406C00  ldr      x0, [x0, #0xd8]
static inline uint64_t fde_func_0585_0x1e7cb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e7cb0ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d5898ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0586 | PC: 0x1e8474 | FDE: 0x0d59d8 | Size: 256 bytes
// Khung tháo gỡ #0586 | Địa chỉ PC: 0x1e8474 | Địa chỉ FDE: 0x0d59d8 | Kích thước: 256 bytes
//   0x1e8474: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1e8478: 9404D447  bl       #0x31d594
//   0x1e847c: 37000040  tbnz     w0, #0, #0x1e8484
//   0x1e8480: 97FDEE42  bl       #0x163d88
static inline uint64_t fde_func_0586_0x1e8474(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e8474ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9404d447ULL) ^ 0x0d59d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0587 | PC: 0x1e89c8 | FDE: 0x0d5b28 | Size: 192 bytes [_ZN4lynx4tasm14ElementManager27SetInspectorElementObserverERKNSt6__ndk110shared_ptrINS0_24InspectorElementObserverEEE]
// Khung tháo gỡ #0587 | Địa chỉ PC: 0x1e89c8 | Địa chỉ FDE: 0x0d5b28 | Kích thước: 192 bytes
//   0x1e89c8: D10143FF  sub      sp, sp, #0x50
//   0x1e89cc: F90013F6  str      x22, [sp, #0x20]
//   0x1e89d0: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x1e89d4: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0587_0x1e89c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e89c8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x0d5b28ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #0588 | PC: 0x1e8a88 | FDE: 0x0d5b48 | Size: 256 bytes [_ZN4lynx4tasm14ElementManager19OnFinishUpdatePropsEPNS0_7ElementERNSt6__ndk110shared_ptrINS0_15PipelineOptionsEEE]
// Khung tháo gỡ #0588 | Địa chỉ PC: 0x1e8a88 | Địa chỉ FDE: 0x0d5b48 | Kích thước: 256 bytes
//   0x1e8a88: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1e8a8c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1e8a90: F9400028  ldr      x8, [x1]
//   0x1e8a94: AA0003F5  mov      x21, x0
static inline uint64_t fde_func_0588_0x1e8a88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e8a88ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d5b48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0589 | PC: 0x1e8f68 | FDE: 0x0d5c38 | Size: 44 bytes [_ZN4lynx4tasm14ElementManager15SetRootOnLayoutEi]
// Khung tháo gỡ #0589 | Địa chỉ PC: 0x1e8f68 | Địa chỉ FDE: 0x0d5c38 | Kích thước: 44 bytes
//   0x1e8f68: F940D400  ldr      x0, [x0, #0x1a8]
//   0x1e8f6c: F9400008  ldr      x8, [x0]
//   0x1e8f70: F9405D02  ldr      x2, [x8, #0xb8]
//   0x1e8f74: D61F0040  br       x2
static inline uint64_t fde_func_0589_0x1e8f68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e8f68ULL ^ (static_cast<uint64_t>(0xf940d400ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x0d5c38ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0590 | PC: 0x1e8f94 | FDE: 0x0d5c68 | Size: 256 bytes
// Khung tháo gỡ #0590 | Địa chỉ PC: 0x1e8f94 | Địa chỉ FDE: 0x0d5c68 | Kích thước: 256 bytes
//   0x1e8f94: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1e8f98: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1e8f9c: F940E808  ldr      x8, [x0, #0x1d0]
//   0x1e8fa0: 940519A5  bl       #0x32f634
static inline uint64_t fde_func_0590_0x1e8f94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e8f94ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d5c68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0591 | PC: 0x1e94d4 | FDE: 0x0d5d98 | Size: 256 bytes
// Khung tháo gỡ #0591 | Địa chỉ PC: 0x1e94d4 | Địa chỉ FDE: 0x0d5d98 | Kích thước: 256 bytes
//   0x1e94d4: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x1e94d8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1e94dc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1e94e0: F9400016  ldr      x22, [x0]
static inline uint64_t fde_func_0591_0x1e94d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e94d4ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0d5d98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0592 | PC: 0x1e9864 | FDE: 0x0d5eb8 | Size: 256 bytes
// Khung tháo gỡ #0592 | Địa chỉ PC: 0x1e9864 | Địa chỉ FDE: 0x0d5eb8 | Kích thước: 256 bytes
//   0x1e9864: D101C3FF  sub      sp, sp, #0x70
//   0x1e9868: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x1e986c: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x1e9870: 9404CC66  bl       #0x31ca08
static inline uint64_t fde_func_0592_0x1e9864(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e9864ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90553f5ULL) ^ 0x0d5eb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0593 | PC: 0x1e9f08 | FDE: 0x0d5ff0 | Size: 256 bytes
// Khung tháo gỡ #0593 | Địa chỉ PC: 0x1e9f08 | Địa chỉ FDE: 0x0d5ff0 | Kích thước: 256 bytes
//   0x1e9f08: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x1e9f0c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1e9f10: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1e9f14: AA0003F5  mov      x21, x0
static inline uint64_t fde_func_0593_0x1e9f08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1e9f08ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0d5ff0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0594 | PC: 0x1ea100 | FDE: 0x0d6140 | Size: 256 bytes
// Khung tháo gỡ #0594 | Địa chỉ PC: 0x1ea100 | Địa chỉ FDE: 0x0d6140 | Kích thước: 256 bytes
//   0x1ea100: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1ea104: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1ea108: AA0003F4  mov      x20, x0
//   0x1ea10c: 52806D00  mov      w0, #0x368
static inline uint64_t fde_func_0594_0x1ea100(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ea100ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d6140ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0595 | PC: 0x1ea684 | FDE: 0x0d6280 | Size: 256 bytes
// Khung tháo gỡ #0595 | Địa chỉ PC: 0x1ea684 | Địa chỉ FDE: 0x0d6280 | Kích thước: 256 bytes
//   0x1ea684: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1ea688: 12001C28  and      w8, w1, #0xff
//   0x1ea68c: 7100051F  cmp      w8, #1
//   0x1ea690: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0595_0x1ea684(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ea684ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x12001c28ULL) ^ 0x0d6280ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0596 | PC: 0x1eabec | FDE: 0x0d6398 | Size: 256 bytes
// Khung tháo gỡ #0596 | Địa chỉ PC: 0x1eabec | Địa chỉ FDE: 0x0d6398 | Kích thước: 256 bytes
//   0x1eabec: AA1E03E3  mov      x3, x30
//   0x1eabf0: 9404D17F  bl       #0x31f1ec
//   0x1eabf4: AA0303FE  mov      x30, x3
//   0x1eabf8: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_0596_0x1eabec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1eabecULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x9404d17fULL) ^ 0x0d6398ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0597 | PC: 0x1eb7dc | FDE: 0x0d64e8 | Size: 256 bytes
// Khung tháo gỡ #0597 | Địa chỉ PC: 0x1eb7dc | Địa chỉ FDE: 0x0d64e8 | Kích thước: 256 bytes
//   0x1eb7dc: D10143FF  sub      sp, sp, #0x50
//   0x1eb7e0: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x1eb7e4: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x1eb7e8: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_0597_0x1eb7dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1eb7dcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90353f5ULL) ^ 0x0d64e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0598 | PC: 0x1ebc3c | FDE: 0x0d6610 | Size: 256 bytes
// Khung tháo gỡ #0598 | Địa chỉ PC: 0x1ebc3c | Địa chỉ FDE: 0x0d6610 | Kích thước: 256 bytes
//   0x1ebc3c: B4000102  cbz      x2, #0x1ebc5c
//   0x1ebc40: 394DA048  ldrb     w8, [x2, #0x368]
//   0x1ebc44: 7100351F  cmp      w8, #0xd
//   0x1ebc48: 540000A1  b.ne     #0x1ebc5c
static inline uint64_t fde_func_0598_0x1ebc3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ebc3cULL ^ (static_cast<uint64_t>(0xb4000102ULL) << 13);
    acc = (acc + a1 + 0x394da048ULL) ^ 0x0d6610ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0599 | PC: 0x1ebee8 | FDE: 0x0d6720 | Size: 256 bytes
// Khung tháo gỡ #0599 | Địa chỉ PC: 0x1ebee8 | Địa chỉ FDE: 0x0d6720 | Kích thước: 256 bytes
//   0x1ebee8: F81C0FFC  str      x28, [sp, #-0x40]!
//   0x1ebeec: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x1ebef0: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1ebef4: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0599_0x1ebee8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ebee8ULL ^ (static_cast<uint64_t>(0xf81c0ffcULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0d6720ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0600 | PC: 0x1ec3c0 | FDE: 0x0d6850 | Size: 256 bytes
// Khung tháo gỡ #0600 | Địa chỉ PC: 0x1ec3c0 | Địa chỉ FDE: 0x0d6850 | Kích thước: 256 bytes
//   0x1ec3c0: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1ec3c4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1ec3c8: 39401028  ldrb     w8, [x1, #4]
//   0x1ec3cc: B9400029  ldr      w9, [x1]
static inline uint64_t fde_func_0600_0x1ec3c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ec3c0ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d6850ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0601 | PC: 0x1ecf64 | FDE: 0x0d6998 | Size: 256 bytes
// Khung tháo gỡ #0601 | Địa chỉ PC: 0x1ecf64 | Địa chỉ FDE: 0x0d6998 | Kích thước: 256 bytes
//   0x1ecf64: D10203FF  sub      sp, sp, #0x80
//   0x1ecf68: F90033F4  str      x20, [sp, #0x60]
//   0x1ecf6c: A9077BF3  stp      x19, x30, [sp, #0x70]
//   0x1ecf70: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0601_0x1ecf64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ecf64ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90033f4ULL) ^ 0x0d6998ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0602 | PC: 0x1ed25c | FDE: 0x0d6a40 | Size: 256 bytes [_ZN4lynx4tasm18InspectorAttributeC2Ev]
// Khung tháo gỡ #0602 | Địa chỉ PC: 0x1ed25c | Địa chỉ FDE: 0x0d6a40 | Kích thước: 256 bytes
//   0x1ed25c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1ed260: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1ed264: 9404D1F2  bl       #0x321a2c
//   0x1ed268: 97FDB62E  bl       #0x15ab20
static inline uint64_t fde_func_0602_0x1ed25c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ed25cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d6a40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0603 | PC: 0x1ed35c | FDE: 0x0d6a60 | Size: 256 bytes [_ZN4lynx4tasm18InspectorAttributeD1Ev]
// Khung tháo gỡ #0603 | Địa chỉ PC: 0x1ed35c | Địa chỉ FDE: 0x0d6a60 | Kích thước: 256 bytes
//   0x1ed35c: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x1ed360: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x1ed364: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1ed368: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0603_0x1ed35c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ed35cULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0d6a60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0604 | PC: 0x1ed5f4 | FDE: 0x0d6ae0 | Size: 256 bytes
// Khung tháo gỡ #0604 | Địa chỉ PC: 0x1ed5f4 | Địa chỉ FDE: 0x0d6ae0 | Kích thước: 256 bytes
//   0x1ed5f4: D10103FF  sub      sp, sp, #0x40
//   0x1ed5f8: FD000BE8  str      d8, [sp, #0x10]
//   0x1ed5fc: F9000FF6  str      x22, [sp, #0x18]
//   0x1ed600: A90253F5  stp      x21, x20, [sp, #0x20]
static inline uint64_t fde_func_0604_0x1ed5f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ed5f4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xfd000be8ULL) ^ 0x0d6ae0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0605 | PC: 0x1edee4 | FDE: 0x0d6c00 | Size: 256 bytes [_ZN4lynx4tasm7Element10ResetStyleERKNS_4base6VectorINS0_13CSSPropertyIDELm0EEE]
// Khung tháo gỡ #0605 | Địa chỉ PC: 0x1edee4 | Địa chỉ FDE: 0x0d6c00 | Kích thước: 256 bytes
//   0x1edee4: AA1E03E2  mov      x2, x30
//   0x1edee8: 9404E197  bl       #0x326544
//   0x1edeec: AA0203FE  mov      x30, x2
//   0x1edef0: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_0605_0x1edee4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1edee4ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9404e197ULL) ^ 0x0d6c00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0606 | PC: 0x1ee0d4 | FDE: 0x0d6c50 | Size: 256 bytes
// Khung tháo gỡ #0606 | Địa chỉ PC: 0x1ee0d4 | Địa chỉ FDE: 0x0d6c50 | Kích thước: 256 bytes
//   0x1ee0d4: AA1E03E1  mov      x1, x30
//   0x1ee0d8: 9404C44B  bl       #0x31f204
//   0x1ee0dc: AA0103FE  mov      x30, x1
//   0x1ee0e0: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_0606_0x1ee0d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ee0d4ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x9404c44bULL) ^ 0x0d6c50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0607 | PC: 0x1ee350 | FDE: 0x0d6d08 | Size: 52 bytes [_ZN4lynx4tasm7Element11GetFontSizeEv]
// Khung tháo gỡ #0607 | Địa chỉ PC: 0x1ee350 | Địa chỉ FDE: 0x0d6d08 | Kích thước: 52 bytes
//   0x1ee350: F9408808  ldr      x8, [x0, #0x110]
//   0x1ee354: BD40D900  ldr      s0, [x8, #0xd8]
//   0x1ee358: 1E22C000  fcvt     d0, s0
//   0x1ee35c: D65F03C0  ret      
static inline uint64_t fde_func_0607_0x1ee350(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ee350ULL ^ (static_cast<uint64_t>(0xf9408808ULL) << 13);
    acc = (acc + a1 + 0xbd40d900ULL) ^ 0x0d6d08ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0608 | PC: 0x1ee384 | FDE: 0x0d6d50 | Size: 256 bytes
// Khung tháo gỡ #0608 | Địa chỉ PC: 0x1ee384 | Địa chỉ FDE: 0x0d6d50 | Kích thước: 256 bytes
//   0x1ee384: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1ee388: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1ee38c: B4000141  cbz      x1, #0x1ee3b4
//   0x1ee390: 9404C802  bl       #0x320398
static inline uint64_t fde_func_0608_0x1ee384(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ee384ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d6d50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0609 | PC: 0x1eee7c | FDE: 0x0d6ea0 | Size: 256 bytes
// Khung tháo gỡ #0609 | Địa chỉ PC: 0x1eee7c | Địa chỉ FDE: 0x0d6ea0 | Kích thước: 256 bytes
//   0x1eee7c: F9407408  ldr      x8, [x0, #0xe8]
//   0x1eee80: F9409D08  ldr      x8, [x8, #0x138]
//   0x1eee84: B4000068  cbz      x8, #0x1eee90
//   0x1eee88: 39474D08  ldrb     w8, [x8, #0x1d3]
static inline uint64_t fde_func_0609_0x1eee7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1eee7cULL ^ (static_cast<uint64_t>(0xf9407408ULL) << 13);
    acc = (acc + a1 + 0xf9409d08ULL) ^ 0x0d6ea0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0610 | PC: 0x1ef08c | FDE: 0x0d6f98 | Size: 256 bytes
// Khung tháo gỡ #0610 | Địa chỉ PC: 0x1ef08c | Địa chỉ FDE: 0x0d6f98 | Kích thước: 256 bytes
//   0x1ef08c: F9406008  ldr      x8, [x0, #0xc0]
//   0x1ef090: F9409D08  ldr      x8, [x8, #0x138]
//   0x1ef094: B4000068  cbz      x8, #0x1ef0a0
//   0x1ef098: 39474D08  ldrb     w8, [x8, #0x1d3]
static inline uint64_t fde_func_0610_0x1ef08c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ef08cULL ^ (static_cast<uint64_t>(0xf9406008ULL) << 13);
    acc = (acc + a1 + 0xf9409d08ULL) ^ 0x0d6f98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0611 | PC: 0x1ef348 | FDE: 0x0d70a8 | Size: 256 bytes
// Khung tháo gỡ #0611 | Địa chỉ PC: 0x1ef348 | Địa chỉ FDE: 0x0d70a8 | Kích thước: 256 bytes
//   0x1ef348: AA1E03E3  mov      x3, x30
//   0x1ef34c: 9404E068  bl       #0x3274ec
//   0x1ef350: AA0303FE  mov      x30, x3
//   0x1ef354: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_0611_0x1ef348(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ef348ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x9404e068ULL) ^ 0x0d70a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0612 | PC: 0x1ef720 | FDE: 0x0d71d8 | Size: 256 bytes
// Khung tháo gỡ #0612 | Địa chỉ PC: 0x1ef720 | Địa chỉ FDE: 0x0d71d8 | Kích thước: 256 bytes
//   0x1ef720: D101C3FF  sub      sp, sp, #0x70
//   0x1ef724: F90023F6  str      x22, [sp, #0x40]
//   0x1ef728: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x1ef72c: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_0612_0x1ef720(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ef720ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f6ULL) ^ 0x0d71d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0613 | PC: 0x1efd6c | FDE: 0x0d7300 | Size: 256 bytes
// Khung tháo gỡ #0613 | Địa chỉ PC: 0x1efd6c | Địa chỉ FDE: 0x0d7300 | Kích thước: 256 bytes
//   0x1efd6c: AA1E03E4  mov      x4, x30
//   0x1efd70: 9404D973  bl       #0x32633c
//   0x1efd74: AA0403FE  mov      x30, x4
//   0x1efd78: A90A7BF3  stp      x19, x30, [sp, #0xa0]
static inline uint64_t fde_func_0613_0x1efd6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1efd6cULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x9404d973ULL) ^ 0x0d7300ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0614 | PC: 0x1f0a84 | FDE: 0x0d7440 | Size: 256 bytes
// Khung tháo gỡ #0614 | Địa chỉ PC: 0x1f0a84 | Địa chỉ FDE: 0x0d7440 | Kích thước: 256 bytes
//   0x1f0a84: B25D73E8  mov      x8, #-0x800000000
//   0x1f0a88: 91004009  add      x9, x0, #0x10
//   0x1f0a8c: A9002009  stp      x9, x8, [x0]
//   0x1f0a90: 17FEB3A1  b        #0x19d914
static inline uint64_t fde_func_0614_0x1f0a84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f0a84ULL ^ (static_cast<uint64_t>(0xb25d73e8ULL) << 13);
    acc = (acc + a1 + 0x91004009ULL) ^ 0x0d7440ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0615 | PC: 0x1f197c | FDE: 0x0d7588 | Size: 256 bytes
// Khung tháo gỡ #0615 | Địa chỉ PC: 0x1f197c | Địa chỉ FDE: 0x0d7588 | Kích thước: 256 bytes
//   0x1f197c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1f1980: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1f1984: 7100043F  cmp      w1, #1
//   0x1f1988: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0615_0x1f197c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f197cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d7588ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0616 | PC: 0x1f2028 | FDE: 0x0d76c0 | Size: 256 bytes
// Khung tháo gỡ #0616 | Địa chỉ PC: 0x1f2028 | Địa chỉ FDE: 0x0d76c0 | Kích thước: 256 bytes
//   0x1f2028: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1f202c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1f2030: B9000FE1  str      w1, [sp, #0xc]
//   0x1f2034: 3941CC08  ldrb     w8, [x0, #0x73]
static inline uint64_t fde_func_0616_0x1f2028(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f2028ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d76c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0617 | PC: 0x1f2414 | FDE: 0x0d77e0 | Size: 256 bytes
// Khung tháo gỡ #0617 | Địa chỉ PC: 0x1f2414 | Địa chỉ FDE: 0x0d77e0 | Kích thước: 256 bytes
//   0x1f2414: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1f2418: 9404D79E  bl       #0x328290
//   0x1f241c: 9404CED8  bl       #0x325f7c
//   0x1f2420: B40000A0  cbz      x0, #0x1f2434
static inline uint64_t fde_func_0617_0x1f2414(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f2414ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9404d79eULL) ^ 0x0d77e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0618 | PC: 0x1f325c | FDE: 0x0d7930 | Size: 256 bytes
// Khung tháo gỡ #0618 | Địa chỉ PC: 0x1f325c | Địa chỉ FDE: 0x0d7930 | Kích thước: 256 bytes
//   0x1f325c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1f3260: F9407008  ldr      x8, [x0, #0xe0]
//   0x1f3264: B4000128  cbz      x8, #0x1f3288
//   0x1f3268: F9406500  ldr      x0, [x8, #0xc8]
static inline uint64_t fde_func_0618_0x1f325c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f325cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9407008ULL) ^ 0x0d7930ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0619 | PC: 0x1f3bd8 | FDE: 0x0d7a78 | Size: 256 bytes
// Khung tháo gỡ #0619 | Địa chỉ PC: 0x1f3bd8 | Địa chỉ FDE: 0x0d7a78 | Kích thước: 256 bytes
//   0x1f3bd8: F9407008  ldr      x8, [x0, #0xe0]
//   0x1f3bdc: B40000C8  cbz      x8, #0x1f3bf4
//   0x1f3be0: F9406508  ldr      x8, [x8, #0xc8]
//   0x1f3be4: F9402508  ldr      x8, [x8, #0x48]
static inline uint64_t fde_func_0619_0x1f3bd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f3bd8ULL ^ (static_cast<uint64_t>(0xf9407008ULL) << 13);
    acc = (acc + a1 + 0xb40000c8ULL) ^ 0x0d7a78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0620 | PC: 0x1f3e48 | FDE: 0x0d7b78 | Size: 256 bytes
// Khung tháo gỡ #0620 | Địa chỉ PC: 0x1f3e48 | Địa chỉ FDE: 0x0d7b78 | Kích thước: 256 bytes
//   0x1f3e48: F9400008  ldr      x8, [x0]
//   0x1f3e4c: B941B002  ldr      w2, [x0, #0x1b0]
//   0x1f3e50: F940B903  ldr      x3, [x8, #0x170]
//   0x1f3e54: D61F0060  br       x3
static inline uint64_t fde_func_0620_0x1f3e48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f3e48ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xb941b002ULL) ^ 0x0d7b78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0621 | PC: 0x1f4034 | FDE: 0x0d7c88 | Size: 256 bytes
// Khung tháo gỡ #0621 | Địa chỉ PC: 0x1f4034 | Địa chỉ FDE: 0x0d7c88 | Kích thước: 256 bytes
//   0x1f4034: F9407408  ldr      x8, [x0, #0xe8]
//   0x1f4038: B9404801  ldr      w1, [x0, #0x48]
//   0x1f403c: F940D508  ldr      x8, [x8, #0x1a8]
//   0x1f4040: F9400109  ldr      x9, [x8]
static inline uint64_t fde_func_0621_0x1f4034(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f4034ULL ^ (static_cast<uint64_t>(0xf9407408ULL) << 13);
    acc = (acc + a1 + 0xb9404801ULL) ^ 0x0d7c88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0622 | PC: 0x1f423c | FDE: 0x0d7d98 | Size: 256 bytes
// Khung tháo gỡ #0622 | Địa chỉ PC: 0x1f423c | Địa chỉ FDE: 0x0d7d98 | Kích thước: 256 bytes
//   0x1f423c: F9407008  ldr      x8, [x0, #0xe0]
//   0x1f4240: B4000108  cbz      x8, #0x1f4260
//   0x1f4244: F9406500  ldr      x0, [x8, #0xc8]
//   0x1f4248: B40000C0  cbz      x0, #0x1f4260
static inline uint64_t fde_func_0622_0x1f423c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f423cULL ^ (static_cast<uint64_t>(0xf9407008ULL) << 13);
    acc = (acc + a1 + 0xb4000108ULL) ^ 0x0d7d98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0623 | PC: 0x1f45c8 | FDE: 0x0d7e98 | Size: 256 bytes
// Khung tháo gỡ #0623 | Địa chỉ PC: 0x1f45c8 | Địa chỉ FDE: 0x0d7e98 | Kích thước: 256 bytes
//   0x1f45c8: 39466800  ldrb     w0, [x0, #0x19a]
//   0x1f45cc: D65F03C0  ret      
//   0x1f45d0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1f45d4: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0623_0x1f45c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f45c8ULL ^ (static_cast<uint64_t>(0x39466800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0d7e98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0624 | PC: 0x1f4738 | FDE: 0x0d7fa8 | Size: 256 bytes
// Khung tháo gỡ #0624 | Địa chỉ PC: 0x1f4738 | Địa chỉ FDE: 0x0d7fa8 | Kích thước: 256 bytes
//   0x1f4738: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1f473c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1f4740: 39418C08  ldrb     w8, [x0, #0x63]
//   0x1f4744: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0624_0x1f4738(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f4738ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d7fa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0625 | PC: 0x1f49e4 | FDE: 0x0d8090 | Size: 72 bytes [_ZN4lynx4tasm15AttributeHolder11EventBundle20DefaultEmptyEventMapEv]
// Khung tháo gỡ #0625 | Địa chỉ PC: 0x1f49e4 | Địa chỉ FDE: 0x0d8090 | Kích thước: 72 bytes
//   0x1f49e4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1f49e8: D0000BA8  adrp     x8, #0x36a000
//   0x1f49ec: 9135A108  add      x8, x8, #0xd68
//   0x1f49f0: 08DFFD08  ldarb    w8, [x8]
static inline uint64_t fde_func_0625_0x1f49e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f49e4ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xd0000ba8ULL) ^ 0x0d8090ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0626 | PC: 0x1f4a2c | FDE: 0x0d80a8 | Size: 72 bytes [_ZN4lynx4tasm15AttributeHolder17CSSVariableBundle26DefaultEmptyCSSVariableMapEv]
// Khung tháo gỡ #0626 | Địa chỉ PC: 0x1f4a2c | Địa chỉ FDE: 0x0d80a8 | Kích thước: 72 bytes
//   0x1f4a2c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1f4a30: D0000BA8  adrp     x8, #0x36a000
//   0x1f4a34: 9135C108  add      x8, x8, #0xd70
//   0x1f4a38: 08DFFD08  ldarb    w8, [x8]
static inline uint64_t fde_func_0626_0x1f4a2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f4a2cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xd0000ba8ULL) ^ 0x0d80a8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0627 | PC: 0x1f4a74 | FDE: 0x0d80c0 | Size: 104 bytes [_ZN4lynx4tasm15AttributeHolder17CSSVariableBundle23DefaultEmptyCSSValueMapEv]
// Khung tháo gỡ #0627 | Địa chỉ PC: 0x1f4a74 | Địa chỉ FDE: 0x0d80c0 | Kích thước: 104 bytes
//   0x1f4a74: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1f4a78: D0000BA8  adrp     x8, #0x36a000
//   0x1f4a7c: 9135E108  add      x8, x8, #0xd78
//   0x1f4a80: 08DFFD08  ldarb    w8, [x8]
static inline uint64_t fde_func_0627_0x1f4a74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f4a74ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xd0000ba8ULL) ^ 0x0d80c0ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0628 | PC: 0x1f4adc | FDE: 0x0d80d8 | Size: 76 bytes [_ZN4lynx4tasm15AttributeHolder22DefaultEmptyGestureMapEv]
// Khung tháo gỡ #0628 | Địa chỉ PC: 0x1f4adc | Địa chỉ FDE: 0x0d80d8 | Kích thước: 76 bytes
//   0x1f4adc: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1f4ae0: D0000BA8  adrp     x8, #0x36a000
//   0x1f4ae4: 91360108  add      x8, x8, #0xd80
//   0x1f4ae8: 08DFFD08  ldarb    w8, [x8]
static inline uint64_t fde_func_0628_0x1f4adc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f4adcULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xd0000ba8ULL) ^ 0x0d80d8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0629 | PC: 0x1f4b28 | FDE: 0x0d80f0 | Size: 256 bytes [_ZN4lynx4tasm15AttributeHolder19DefaultEmptyDataMapEv]
// Khung tháo gỡ #0629 | Địa chỉ PC: 0x1f4b28 | Địa chỉ FDE: 0x0d80f0 | Kích thước: 256 bytes
//   0x1f4b28: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1f4b2c: D0000BA8  adrp     x8, #0x36a000
//   0x1f4b30: 91362108  add      x8, x8, #0xd88
//   0x1f4b34: 08DFFD08  ldarb    w8, [x8]
static inline uint64_t fde_func_0629_0x1f4b28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f4b28ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xd0000ba8ULL) ^ 0x0d80f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0630 | PC: 0x1f4e50 | FDE: 0x0d81c8 | Size: 256 bytes
// Khung tháo gỡ #0630 | Địa chỉ PC: 0x1f4e50 | Địa chỉ FDE: 0x0d81c8 | Kích thước: 256 bytes
//   0x1f4e50: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1f4e54: F9400008  ldr      x8, [x0]
//   0x1f4e58: AA0103F3  mov      x19, x1
//   0x1f4e5c: 9404AAF0  bl       #0x31fa1c
static inline uint64_t fde_func_0630_0x1f4e50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f4e50ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x0d81c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0631 | PC: 0x1f5420 | FDE: 0x0d8308 | Size: 256 bytes
// Khung tháo gỡ #0631 | Địa chỉ PC: 0x1f5420 | Địa chỉ FDE: 0x0d8308 | Kích thước: 256 bytes
//   0x1f5420: AA1E03E3  mov      x3, x30
//   0x1f5424: 94049E24  bl       #0x31ccb4
//   0x1f5428: AA0303FE  mov      x30, x3
//   0x1f542c: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0631_0x1f5420(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f5420ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94049e24ULL) ^ 0x0d8308ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0632 | PC: 0x1f5818 | FDE: 0x0d8428 | Size: 256 bytes
// Khung tháo gỡ #0632 | Địa chỉ PC: 0x1f5818 | Địa chỉ FDE: 0x0d8428 | Kích thước: 256 bytes
//   0x1f5818: D1004000  sub      x0, x0, #0x10
//   0x1f581c: 17FFFFE9  b        #0x1f57c0
//   0x1f5820: F9406400  ldr      x0, [x0, #0xc8]
//   0x1f5824: B4000040  cbz      x0, #0x1f582c
static inline uint64_t fde_func_0632_0x1f5818(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f5818ULL ^ (static_cast<uint64_t>(0xd1004000ULL) << 13);
    acc = (acc + a1 + 0x17ffffe9ULL) ^ 0x0d8428ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0633 | PC: 0x1f5b50 | FDE: 0x0d8530 | Size: 32 bytes
// Khung tháo gỡ #0633 | Địa chỉ PC: 0x1f5b50 | Địa chỉ FDE: 0x0d8530 | Kích thước: 32 bytes
//   0x1f5b50: B940B400  ldr      w0, [x0, #0xb4]
//   0x1f5b54: D65F03C0  ret      
//   0x1f5b58: B940B408  ldr      w8, [x0, #0xb4]
//   0x1f5b5c: 14051279  b        #0x33a540
static inline uint64_t fde_func_0633_0x1f5b50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f5b50ULL ^ (static_cast<uint64_t>(0xb940b400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0d8530ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0634 | PC: 0x1f5b70 | FDE: 0x0d8590 | Size: 60 bytes [_ZN4lynx9starlight12LayoutObject10GetBoxInfoEv]
// Khung tháo gỡ #0634 | Địa chỉ PC: 0x1f5b70 | Địa chỉ FDE: 0x0d8590 | Kích thước: 60 bytes
//   0x1f5b70: 140507C7  b        #0x337a8c
//   0x1f5b74: B940A400  ldr      w0, [x0, #0xa4]
//   0x1f5b78: D65F03C0  ret      
//   0x1f5b7c: B940A408  ldr      w8, [x0, #0xa4]
static inline uint64_t fde_func_0634_0x1f5b70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f5b70ULL ^ (static_cast<uint64_t>(0x140507c7ULL) << 13);
    acc = (acc + a1 + 0xb940a400ULL) ^ 0x0d8590ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0635 | PC: 0x1f5bac | FDE: 0x0d8620 | Size: 256 bytes
// Khung tháo gỡ #0635 | Địa chỉ PC: 0x1f5bac | Địa chỉ FDE: 0x0d8620 | Kích thước: 256 bytes
//   0x1f5bac: D100C3FF  sub      sp, sp, #0x30
//   0x1f5bb0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1f5bb4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1f5bb8: A9415414  ldp      x20, x21, [x0, #0x10]
static inline uint64_t fde_func_0635_0x1f5bac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f5bacULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0d8620ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0636 | PC: 0x1f5f30 | FDE: 0x0d8748 | Size: 256 bytes
// Khung tháo gỡ #0636 | Địa chỉ PC: 0x1f5f30 | Địa chỉ FDE: 0x0d8748 | Kích thước: 256 bytes
//   0x1f5f30: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1f5f34: AA0003F3  mov      x19, x0
//   0x1f5f38: 97FFFFF8  bl       #0x1f5f18
//   0x1f5f3c: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0636_0x1f5f30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f5f30ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0d8748ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0637 | PC: 0x1f660c | FDE: 0x0d8888 | Size: 256 bytes
// Khung tháo gỡ #0637 | Địa chỉ PC: 0x1f660c | Địa chỉ FDE: 0x0d8888 | Kích thước: 256 bytes
//   0x1f660c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1f6610: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1f6614: 94050D28  bl       #0x339ab4
//   0x1f6618: 39400008  ldrb     w8, [x0]
static inline uint64_t fde_func_0637_0x1f660c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f660cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d8888ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0638 | PC: 0x1f7030 | FDE: 0x0d89f0 | Size: 256 bytes
// Khung tháo gỡ #0638 | Địa chỉ PC: 0x1f7030 | Địa chỉ FDE: 0x0d89f0 | Kích thước: 256 bytes
//   0x1f7030: D10103FF  sub      sp, sp, #0x40
//   0x1f7034: F90013F4  str      x20, [sp, #0x20]
//   0x1f7038: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x1f703c: 9404CB50  bl       #0x329d7c
static inline uint64_t fde_func_0638_0x1f7030(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f7030ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f4ULL) ^ 0x0d89f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0639 | PC: 0x1f7214 | FDE: 0x0d8a38 | Size: 256 bytes [_ZN4lynx4tasm13StyleResolver17GetCSSMatchedRuleEPNS0_15AttributeHolderEPNS0_11CSSFragmentE]
// Khung tháo gỡ #0639 | Địa chỉ PC: 0x1f7214 | Địa chỉ FDE: 0x0d8a38 | Kích thước: 256 bytes
//   0x1f7214: D100C3FF  sub      sp, sp, #0x30
//   0x1f7218: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1f721c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1f7220: AA0803F3  mov      x19, x8
static inline uint64_t fde_func_0639_0x1f7214(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f7214ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0d8a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0640 | PC: 0x1f770c | FDE: 0x0d8b28 | Size: 256 bytes
// Khung tháo gỡ #0640 | Địa chỉ PC: 0x1f770c | Địa chỉ FDE: 0x0d8b28 | Kích thước: 256 bytes
//   0x1f770c: D10343FF  sub      sp, sp, #0xd0
//   0x1f7710: A90A5BF7  stp      x23, x22, [sp, #0xa0]
//   0x1f7714: A90B53F5  stp      x21, x20, [sp, #0xb0]
//   0x1f7718: A90C7BF3  stp      x19, x30, [sp, #0xc0]
static inline uint64_t fde_func_0640_0x1f770c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f770cULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa90a5bf7ULL) ^ 0x0d8b28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0641 | PC: 0x1f7cd8 | FDE: 0x0d8c48 | Size: 256 bytes
// Khung tháo gỡ #0641 | Địa chỉ PC: 0x1f7cd8 | Địa chỉ FDE: 0x0d8c48 | Kích thước: 256 bytes
//   0x1f7cd8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1f7cdc: B0000AC8  adrp     x8, #0x350000
//   0x1f7ce0: 9101E108  add      x8, x8, #0x78
//   0x1f7ce4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0641_0x1f7cd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f7cd8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb0000ac8ULL) ^ 0x0d8c48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0642 | PC: 0x1f8c14 | FDE: 0x0d8da8 | Size: 256 bytes
// Khung tháo gỡ #0642 | Địa chỉ PC: 0x1f8c14 | Địa chỉ FDE: 0x0d8da8 | Kích thước: 256 bytes
//   0x1f8c14: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1f8c18: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1f8c1c: 94048EDF  bl       #0x31c798
//   0x1f8c20: 97FD87C0  bl       #0x15ab20
static inline uint64_t fde_func_0642_0x1f8c14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f8c14ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d8da8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0643 | PC: 0x1f991c | FDE: 0x0d8f00 | Size: 256 bytes
// Khung tháo gỡ #0643 | Địa chỉ PC: 0x1f991c | Địa chỉ FDE: 0x0d8f00 | Kích thước: 256 bytes
//   0x1f991c: D100C3FF  sub      sp, sp, #0x30
//   0x1f9920: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1f9924: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1f9928: AA0203F4  mov      x20, x2
static inline uint64_t fde_func_0643_0x1f991c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1f991cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0d8f00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0644 | PC: 0x1fa5cc | FDE: 0x0d9070 | Size: 256 bytes
// Khung tháo gỡ #0644 | Địa chỉ PC: 0x1fa5cc | Địa chỉ FDE: 0x0d9070 | Kích thước: 256 bytes
//   0x1fa5cc: D10703FF  sub      sp, sp, #0x1c0
//   0x1fa5d0: A9166FFC  stp      x28, x27, [sp, #0x160]
//   0x1fa5d4: A91767FA  stp      x26, x25, [sp, #0x170]
//   0x1fa5d8: A9185FF8  stp      x24, x23, [sp, #0x180]
static inline uint64_t fde_func_0644_0x1fa5cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1fa5ccULL ^ (static_cast<uint64_t>(0xd10703ffULL) << 13);
    acc = (acc + a1 + 0xa9166ffcULL) ^ 0x0d9070ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0645 | PC: 0x1fb3bc | FDE: 0x0d91e0 | Size: 256 bytes
// Khung tháo gỡ #0645 | Địa chỉ PC: 0x1fb3bc | Địa chỉ FDE: 0x0d91e0 | Kích thước: 256 bytes
//   0x1fb3bc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1fb3c0: AA0003F3  mov      x19, x0
//   0x1fb3c4: 94048464  bl       #0x31c554
//   0x1fb3c8: B0000AA8  adrp     x8, #0x350000
static inline uint64_t fde_func_0645_0x1fb3bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1fb3bcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0d91e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0646 | PC: 0x1fcb1c | FDE: 0x0d9350 | Size: 256 bytes
// Khung tháo gỡ #0646 | Địa chỉ PC: 0x1fcb1c | Địa chỉ FDE: 0x0d9350 | Kích thước: 256 bytes
//   0x1fcb1c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1fcb20: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1fcb24: 940485F6  bl       #0x31e2fc
//   0x1fcb28: 94050F3A  bl       #0x340810
static inline uint64_t fde_func_0646_0x1fcb1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1fcb1cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d9350ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0647 | PC: 0x1fd5c0 | FDE: 0x0d94a0 | Size: 256 bytes
// Khung tháo gỡ #0647 | Địa chỉ PC: 0x1fd5c0 | Địa chỉ FDE: 0x0d94a0 | Kích thước: 256 bytes
//   0x1fd5c0: AA1E03E3  mov      x3, x30
//   0x1fd5c4: 9404950C  bl       #0x3229f4
//   0x1fd5c8: AA0303FE  mov      x30, x3
//   0x1fd5cc: A9167BFD  stp      x29, x30, [sp, #0x160]
static inline uint64_t fde_func_0647_0x1fd5c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1fd5c0ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x9404950cULL) ^ 0x0d94a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0648 | PC: 0x1fdb34 | FDE: 0x0d95f0 | Size: 256 bytes
// Khung tháo gỡ #0648 | Địa chỉ PC: 0x1fdb34 | Địa chỉ FDE: 0x0d95f0 | Kích thước: 256 bytes
//   0x1fdb34: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x1fdb38: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1fdb3c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1fdb40: B9402815  ldr      w21, [x0, #0x28]
static inline uint64_t fde_func_0648_0x1fdb34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1fdb34ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0d95f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0649 | PC: 0x1fe1d4 | FDE: 0x0d9720 | Size: 256 bytes
// Khung tháo gỡ #0649 | Địa chỉ PC: 0x1fe1d4 | Địa chỉ FDE: 0x0d9720 | Kích thước: 256 bytes
//   0x1fe1d4: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1fe1d8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1fe1dc: D0000A89  adrp     x9, #0x350000
//   0x1fe1e0: 9108A129  add      x9, x9, #0x228
static inline uint64_t fde_func_0649_0x1fe1d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1fe1d4ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d9720ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0650 | PC: 0x1fe4f4 | FDE: 0x0d9840 | Size: 256 bytes
// Khung tháo gỡ #0650 | Địa chỉ PC: 0x1fe4f4 | Địa chỉ FDE: 0x0d9840 | Kích thước: 256 bytes
//   0x1fe4f4: D10243FF  sub      sp, sp, #0x90
//   0x1fe4f8: F90033F6  str      x22, [sp, #0x60]
//   0x1fe4fc: A90753F5  stp      x21, x20, [sp, #0x70]
//   0x1fe500: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_0650_0x1fe4f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1fe4f4ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90033f6ULL) ^ 0x0d9840ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0651 | PC: 0x1fe8cc | FDE: 0x0d9958 | Size: 256 bytes
// Khung tháo gỡ #0651 | Địa chỉ PC: 0x1fe8cc | Địa chỉ FDE: 0x0d9958 | Kích thước: 256 bytes
//   0x1fe8cc: F9404400  ldr      x0, [x0, #0x88]
//   0x1fe8d0: 17FFFE8D  b        #0x1fe304
//   0x1fe8d4: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x1fe8d8: A90153F5  stp      x21, x20, [sp, #0x10]
static inline uint64_t fde_func_0651_0x1fe8cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1fe8ccULL ^ (static_cast<uint64_t>(0xf9404400ULL) << 13);
    acc = (acc + a1 + 0x17fffe8dULL) ^ 0x0d9958ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0652 | PC: 0x1fee38 | FDE: 0x0d9a98 | Size: 256 bytes
// Khung tháo gỡ #0652 | Địa chỉ PC: 0x1fee38 | Địa chỉ FDE: 0x0d9a98 | Kích thước: 256 bytes
//   0x1fee38: D0000A88  adrp     x8, #0x350000
//   0x1fee3c: 91114108  add      x8, x8, #0x450
//   0x1fee40: F8008408  str      x8, [x0], #8
//   0x1fee44: 140505E3  b        #0x3405d0
static inline uint64_t fde_func_0652_0x1fee38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1fee38ULL ^ (static_cast<uint64_t>(0xd0000a88ULL) << 13);
    acc = (acc + a1 + 0x91114108ULL) ^ 0x0d9a98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0653 | PC: 0x1ff158 | FDE: 0x0d9bb0 | Size: 256 bytes
// Khung tháo gỡ #0653 | Địa chỉ PC: 0x1ff158 | Địa chỉ FDE: 0x0d9bb0 | Kích thước: 256 bytes
//   0x1ff158: 1404F13B  b        #0x33b644
//   0x1ff15c: D10143FF  sub      sp, sp, #0x50
//   0x1ff160: F9001BF4  str      x20, [sp, #0x30]
//   0x1ff164: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0653_0x1ff158(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ff158ULL ^ (static_cast<uint64_t>(0x1404f13bULL) << 13);
    acc = (acc + a1 + 0xd10143ffULL) ^ 0x0d9bb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0654 | PC: 0x1ff440 | FDE: 0x0d9cc8 | Size: 256 bytes
// Khung tháo gỡ #0654 | Địa chỉ PC: 0x1ff440 | Địa chỉ FDE: 0x0d9cc8 | Kích thước: 256 bytes
//   0x1ff440: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1ff444: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1ff448: AA0003F3  mov      x19, x0
//   0x1ff44c: 940473A0  bl       #0x31c2cc
static inline uint64_t fde_func_0654_0x1ff440(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ff440ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d9cc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0655 | PC: 0x1ff850 | FDE: 0x0d9de8 | Size: 256 bytes
// Khung tháo gỡ #0655 | Địa chỉ PC: 0x1ff850 | Địa chỉ FDE: 0x0d9de8 | Kích thước: 256 bytes
//   0x1ff850: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1ff854: AA0003F3  mov      x19, x0
//   0x1ff858: 97FD9C90  bl       #0x166a98
//   0x1ff85c: B0000A88  adrp     x8, #0x350000
static inline uint64_t fde_func_0655_0x1ff850(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ff850ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0d9de8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0656 | PC: 0x1ff9d8 | FDE: 0x0d9ee0 | Size: 256 bytes
// Khung tháo gỡ #0656 | Địa chỉ PC: 0x1ff9d8 | Địa chỉ FDE: 0x0d9ee0 | Kích thước: 256 bytes
//   0x1ff9d8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1ff9dc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1ff9e0: 91016013  add      x19, x0, #0x58
//   0x1ff9e4: 52800034  mov      w20, #1
static inline uint64_t fde_func_0656_0x1ff9d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ff9d8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0d9ee0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0657 | PC: 0x1ffc38 | FDE: 0x0d9ff8 | Size: 256 bytes
// Khung tháo gỡ #0657 | Địa chỉ PC: 0x1ffc38 | Địa chỉ FDE: 0x0d9ff8 | Kích thước: 256 bytes
//   0x1ffc38: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1ffc3c: 9404E20B  bl       #0x338468
//   0x1ffc40: B0000A88  adrp     x8, #0x350000
//   0x1ffc44: 91172108  add      x8, x8, #0x5c8
static inline uint64_t fde_func_0657_0x1ffc38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ffc38ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9404e20bULL) ^ 0x0d9ff8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0658 | PC: 0x20012c | FDE: 0x0da108 | Size: 256 bytes [_ZN4lynx9starlight7BoxInfo17InitializeBoxInfoERKNSt6__ndk15arrayINS0_17OneSideConstraintELm2EEERNS0_12LayoutObjectERKNS0_13LayoutConfigsE]
// Khung tháo gỡ #0658 | Địa chỉ PC: 0x20012c | Địa chỉ FDE: 0x0da108 | Kích thước: 256 bytes
//   0x20012c: D10383FF  sub      sp, sp, #0xe0
//   0x200130: 6D0723E9  stp      d9, d8, [sp, #0x70]
//   0x200134: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x200138: A90967FA  stp      x26, x25, [sp, #0x90]
static inline uint64_t fde_func_0658_0x20012c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20012cULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0x6d0723e9ULL) ^ 0x0da108ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0659 | PC: 0x20045c | FDE: 0x0da140 | Size: 256 bytes
// Khung tháo gỡ #0659 | Địa chỉ PC: 0x20045c | Địa chỉ FDE: 0x0da140 | Kích thước: 256 bytes
//   0x20045c: D10343FF  sub      sp, sp, #0xd0
//   0x200460: 6D0623E9  stp      d9, d8, [sp, #0x60]
//   0x200464: AA1E03E4  mov      x4, x30
//   0x200468: 940474EF  bl       #0x31d824
static inline uint64_t fde_func_0659_0x20045c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20045cULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0x6d0623e9ULL) ^ 0x0da140ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0660 | PC: 0x200c88 | FDE: 0x0da238 | Size: 124 bytes [_ZN4lynx9starlight13ContainerNode11RemoveChildEPS1_]
// Khung tháo gỡ #0660 | Địa chỉ PC: 0x200c88 | Địa chỉ FDE: 0x0da238 | Kích thước: 124 bytes
//   0x200c88: B4000301  cbz      x1, #0x200ce8
//   0x200c8c: B9403008  ldr      w8, [x0, #0x30]
//   0x200c90: 340002C8  cbz      w8, #0x200ce8
//   0x200c94: F8408C28  ldr      x8, [x1, #8]!
static inline uint64_t fde_func_0660_0x200c88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x200c88ULL ^ (static_cast<uint64_t>(0xb4000301ULL) << 13);
    acc = (acc + a1 + 0xb9403008ULL) ^ 0x0da238ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0661 | PC: 0x200d04 | FDE: 0x0da268 | Size: 48 bytes [_ZN4lynx9starlight13ContainerNode4FindEi]
// Khung tháo gỡ #0661 | Địa chỉ PC: 0x200d04 | Địa chỉ FDE: 0x0da268 | Kích thước: 48 bytes
//   0x200d04: 34000121  cbz      w1, #0x200d28
//   0x200d08: 37F80141  tbnz     w1, #0x1f, #0x200d30
//   0x200d0c: 91008008  add      x8, x0, #0x20
//   0x200d10: F9400100  ldr      x0, [x8]
static inline uint64_t fde_func_0661_0x200d04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x200d04ULL ^ (static_cast<uint64_t>(0x34000121ULL) << 13);
    acc = (acc + a1 + 0x37f80141ULL) ^ 0x0da268ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0662 | PC: 0x200d34 | FDE: 0x0da280 | Size: 48 bytes [_ZN4lynx9starlight13ContainerNode7IndexOfEPNS0_4NodeE]
// Khung tháo gỡ #0662 | Địa chỉ PC: 0x200d34 | Địa chỉ FDE: 0x0da280 | Kích thước: 48 bytes
//   0x200d34: AA0003E8  mov      x8, x0
//   0x200d38: 2A1F03E0  mov      w0, wzr
//   0x200d3c: 91008108  add      x8, x8, #0x20
//   0x200d40: F9400108  ldr      x8, [x8]
static inline uint64_t fde_func_0662_0x200d34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x200d34ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e0ULL) ^ 0x0da280ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0663 | PC: 0x200d64 | FDE: 0x0da298 | Size: 8 bytes [_ZN4lynx9starlight13ContainerNode11AppendChildEPS1_]
// Khung tháo gỡ #0663 | Địa chỉ PC: 0x200d64 | Địa chỉ FDE: 0x0da298 | Kích thước: 8 bytes
//   0x200d64: AA1F03E2  mov      x2, xzr
//   0x200d68: 14050102  b        #0x341170
static inline uint64_t fde_func_0663_0x200d64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x200d64ULL ^ (static_cast<uint64_t>(0xaa1f03e2ULL) << 13);
    acc = (acc + a1 + 0x14050102ULL) ^ 0x0da298ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0664 | PC: 0x200d6c | FDE: 0x0da2b0 | Size: 256 bytes [_ZN4lynx9starlight13ContainerNode17InsertChildBeforeEPS1_S2_]
// Khung tháo gỡ #0664 | Địa chỉ PC: 0x200d6c | Địa chỉ FDE: 0x0da2b0 | Kích thước: 256 bytes
//   0x200d6c: D101C3FF  sub      sp, sp, #0x70
//   0x200d70: F9002BF4  str      x20, [sp, #0x50]
//   0x200d74: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x200d78: 94047651  bl       #0x31e6bc
static inline uint64_t fde_func_0664_0x200d6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x200d6cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x0da2b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0665 | PC: 0x201494 | FDE: 0x0da3c0 | Size: 256 bytes
// Khung tháo gỡ #0665 | Địa chỉ PC: 0x201494 | Địa chỉ FDE: 0x0da3c0 | Kích thước: 256 bytes
//   0x201494: D10243FF  sub      sp, sp, #0x90
//   0x201498: FD002BE8  str      d8, [sp, #0x50]
//   0x20149c: F9002FF8  str      x24, [sp, #0x58]
//   0x2014a0: A9065BF7  stp      x23, x22, [sp, #0x60]
static inline uint64_t fde_func_0665_0x201494(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x201494ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xfd002be8ULL) ^ 0x0da3c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0666 | PC: 0x202c90 | FDE: 0x0da548 | Size: 256 bytes
// Khung tháo gỡ #0666 | Địa chỉ PC: 0x202c90 | Địa chỉ FDE: 0x0da548 | Kích thước: 256 bytes
//   0x202c90: D10243FF  sub      sp, sp, #0x90
//   0x202c94: FD000BEC  str      d12, [sp, #0x10]
//   0x202c98: 6D01ABEB  stp      d11, d10, [sp, #0x18]
//   0x202c9c: 6D02A3E9  stp      d9, d8, [sp, #0x28]
static inline uint64_t fde_func_0666_0x202c90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x202c90ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xfd000becULL) ^ 0x0da548ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0667 | PC: 0x203004 | FDE: 0x0da670 | Size: 256 bytes
// Khung tháo gỡ #0667 | Địa chỉ PC: 0x203004 | Địa chỉ FDE: 0x0da670 | Kích thước: 256 bytes
//   0x203004: B4000080  cbz      x0, #0x203014
//   0x203008: 39420408  ldrb     w8, [x0, #0x81]
//   0x20300c: BD400400  ldr      s0, [x0, #4]
//   0x203010: 1404825E  b        #0x323988
static inline uint64_t fde_func_0667_0x203004(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x203004ULL ^ (static_cast<uint64_t>(0xb4000080ULL) << 13);
    acc = (acc + a1 + 0x39420408ULL) ^ 0x0da670ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0668 | PC: 0x2032e0 | FDE: 0x0da780 | Size: 256 bytes
// Khung tháo gỡ #0668 | Địa chỉ PC: 0x2032e0 | Địa chỉ FDE: 0x0da780 | Kích thước: 256 bytes
//   0x2032e0: F9401808  ldr      x8, [x0, #0x30]
//   0x2032e4: 7100003F  cmp      w1, #0
//   0x2032e8: 52801F89  mov      w9, #0xfc
//   0x2032ec: 52801E8A  mov      w10, #0xf4
static inline uint64_t fde_func_0668_0x2032e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2032e0ULL ^ (static_cast<uint64_t>(0xf9401808ULL) << 13);
    acc = (acc + a1 + 0x7100003fULL) ^ 0x0da780ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0669 | PC: 0x20448c | FDE: 0x0da8e8 | Size: 256 bytes
// Khung tháo gỡ #0669 | Địa chỉ PC: 0x20448c | Địa chỉ FDE: 0x0da8e8 | Kích thước: 256 bytes
//   0x20448c: F9401829  ldr      x9, [x1, #0x30]
//   0x204490: F9404528  ldr      x8, [x9, #0x88]
//   0x204494: F9400908  ldr      x8, [x8, #0x10]
//   0x204498: 3943A108  ldrb     w8, [x8, #0xe8]
static inline uint64_t fde_func_0669_0x20448c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20448cULL ^ (static_cast<uint64_t>(0xf9401829ULL) << 13);
    acc = (acc + a1 + 0xf9404528ULL) ^ 0x0da8e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0670 | PC: 0x2062d4 | FDE: 0x0daa50 | Size: 256 bytes
// Khung tháo gỡ #0670 | Địa chỉ PC: 0x2062d4 | Địa chỉ FDE: 0x0daa50 | Kích thước: 256 bytes
//   0x2062d4: D10103FF  sub      sp, sp, #0x40
//   0x2062d8: 6D0223E9  stp      d9, d8, [sp, #0x20]
//   0x2062dc: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x2062e0: 940464B0  bl       #0x31f5a0
static inline uint64_t fde_func_0670_0x2062d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2062d4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0x6d0223e9ULL) ^ 0x0daa50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0671 | PC: 0x207948 | FDE: 0x0dabb0 | Size: 256 bytes
// Khung tháo gỡ #0671 | Địa chỉ PC: 0x207948 | Địa chỉ FDE: 0x0dabb0 | Kích thước: 256 bytes
//   0x207948: AA1E03E6  mov      x6, x30
//   0x20794c: 94045C5C  bl       #0x31eabc
//   0x207950: AA0603FE  mov      x30, x6
//   0x207954: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0671_0x207948(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x207948ULL ^ (static_cast<uint64_t>(0xaa1e03e6ULL) << 13);
    acc = (acc + a1 + 0x94045c5cULL) ^ 0x0dabb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0672 | PC: 0x208140 | FDE: 0x0dacf8 | Size: 256 bytes
// Khung tháo gỡ #0672 | Địa chỉ PC: 0x208140 | Địa chỉ FDE: 0x0dacf8 | Kích thước: 256 bytes
//   0x208140: 7100001F  cmp      w0, #0
//   0x208144: 52801F88  mov      w8, #0xfc
//   0x208148: 52801E89  mov      w9, #0xf4
//   0x20814c: 5280200A  mov      w10, #0x100
static inline uint64_t fde_func_0672_0x208140(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x208140ULL ^ (static_cast<uint64_t>(0x7100001fULL) << 13);
    acc = (acc + a1 + 0x52801f88ULL) ^ 0x0dacf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0673 | PC: 0x20872c | FDE: 0x0dae38 | Size: 256 bytes
// Khung tháo gỡ #0673 | Địa chỉ PC: 0x20872c | Địa chỉ FDE: 0x0dae38 | Kích thước: 256 bytes
//   0x20872c: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x208730: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x208734: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x208738: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0673_0x20872c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20872cULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0dae38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0674 | PC: 0x208ecc | FDE: 0x0daeb8 | Size: 256 bytes [_ZN4lynx9starlight12LayoutObjectC2ERKNS0_13LayoutConfigsEPKNS0_19LayoutComputedStyleE]
// Khung tháo gỡ #0674 | Địa chỉ PC: 0x208ecc | Địa chỉ FDE: 0x0daeb8 | Kích thước: 256 bytes
//   0x208ecc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x208ed0: F9004402  str      x2, [x0, #0x88]
//   0x208ed4: 940461AB  bl       #0x321580
//   0x208ed8: 90000A48  adrp     x8, #0x350000
static inline uint64_t fde_func_0674_0x208ecc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x208eccULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9004402ULL) ^ 0x0daeb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0675 | PC: 0x209cf0 | FDE: 0x0dafa8 | Size: 256 bytes
// Khung tháo gỡ #0675 | Địa chỉ PC: 0x209cf0 | Địa chỉ FDE: 0x0dafa8 | Kích thước: 256 bytes
//   0x209cf0: B9400008  ldr      w8, [x0]
//   0x209cf4: 6B01011F  cmp      w8, w1
//   0x209cf8: 54000161  b.ne     #0x209d24
//   0x209cfc: B9400408  ldr      w8, [x0, #4]
static inline uint64_t fde_func_0675_0x209cf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x209cf0ULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0x6b01011fULL) ^ 0x0dafa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0676 | PC: 0x209ecc | FDE: 0x0db0d0 | Size: 176 bytes
// Khung tháo gỡ #0676 | Địa chỉ PC: 0x209ecc | Địa chỉ FDE: 0x0db0d0 | Kích thước: 176 bytes
//   0x209ecc: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x209ed0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x209ed4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x209ed8: 2A0203F3  mov      w19, w2
static inline uint64_t fde_func_0676_0x209ecc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x209eccULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0db0d0ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #0677 | PC: 0x209f7c | FDE: 0x0db108 | Size: 8 bytes [_ZN4lynx9starlight12LayoutObject10SetContextEPv]
// Khung tháo gỡ #0677 | Địa chỉ PC: 0x209f7c | Địa chỉ FDE: 0x0db108 | Kích thước: 8 bytes
//   0x209f7c: F9003401  str      x1, [x0, #0x68]
//   0x209f80: D65F03C0  ret      
static inline uint64_t fde_func_0677_0x209f7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x209f7cULL ^ (static_cast<uint64_t>(0xf9003401ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0db108ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0678 | PC: 0x209f84 | FDE: 0x0db120 | Size: 8 bytes [_ZNK4lynx9starlight12LayoutObject10GetContextEv]
// Khung tháo gỡ #0678 | Địa chỉ PC: 0x209f84 | Địa chỉ FDE: 0x0db120 | Kích thước: 8 bytes
//   0x209f84: F9403400  ldr      x0, [x0, #0x68]
//   0x209f88: D65F03C0  ret      
static inline uint64_t fde_func_0678_0x209f84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x209f84ULL ^ (static_cast<uint64_t>(0xf9403400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0db120ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0679 | PC: 0x209f8c | FDE: 0x0db138 | Size: 8 bytes [_ZN4lynx9starlight12LayoutObject22SetSLRequestLayoutFuncEPFvPvE]
// Khung tháo gỡ #0679 | Địa chỉ PC: 0x209f8c | Địa chỉ FDE: 0x0db138 | Kích thước: 8 bytes
//   0x209f8c: F9002801  str      x1, [x0, #0x50]
//   0x209f90: D65F03C0  ret      
static inline uint64_t fde_func_0679_0x209f8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x209f8cULL ^ (static_cast<uint64_t>(0xf9002801ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0db138ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0680 | PC: 0x209f94 | FDE: 0x0db150 | Size: 256 bytes [_ZN4lynx9starlight12LayoutObject18SetSLAlignmentFuncEPFvPvE]
// Khung tháo gỡ #0680 | Địa chỉ PC: 0x209f94 | Địa chỉ FDE: 0x0db150 | Kích thước: 256 bytes
//   0x209f94: F9002C01  str      x1, [x0, #0x58]
//   0x209f98: D65F03C0  ret      
//   0x209f9c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x209fa0: 9404B966  bl       #0x338538
static inline uint64_t fde_func_0680_0x209f94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x209f94ULL ^ (static_cast<uint64_t>(0xf9002c01ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0db150ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0681 | PC: 0x20a528 | FDE: 0x0db1f8 | Size: 72 bytes
// Khung tháo gỡ #0681 | Địa chỉ PC: 0x20a528 | Địa chỉ FDE: 0x0db1f8 | Kích thước: 72 bytes
//   0x20a528: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x20a52c: F90007F4  str      x20, [sp, #8]
//   0x20a530: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x20a534: BD419C08  ldr      s8, [x0, #0x19c]
static inline uint64_t fde_func_0681_0x20a528(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20a528ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xf90007f4ULL) ^ 0x0db1f8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0682 | PC: 0x20a570 | FDE: 0x0db218 | Size: 12 bytes [_ZNK4lynx9starlight12LayoutObject24GetLayoutBorderLeftWidthEv]
// Khung tháo gỡ #0682 | Địa chỉ PC: 0x20a570 | Địa chỉ FDE: 0x0db218 | Kích thước: 12 bytes
//   0x20a570: F9404408  ldr      x8, [x0, #0x88]
//   0x20a574: F9405D00  ldr      x0, [x8, #0xb8]
//   0x20a578: 17FFE29E  b        #0x202ff0
static inline uint64_t fde_func_0682_0x20a570(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20a570ULL ^ (static_cast<uint64_t>(0xf9404408ULL) << 13);
    acc = (acc + a1 + 0xf9405d00ULL) ^ 0x0db218ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0683 | PC: 0x20a57c | FDE: 0x0db230 | Size: 12 bytes [_ZNK4lynx9starlight12LayoutObject25GetLayoutBorderRightWidthEv]
// Khung tháo gỡ #0683 | Địa chỉ PC: 0x20a57c | Địa chỉ FDE: 0x0db230 | Kích thước: 12 bytes
//   0x20a57c: F9404408  ldr      x8, [x0, #0x88]
//   0x20a580: F9405D00  ldr      x0, [x8, #0xb8]
//   0x20a584: 17FFE2A0  b        #0x203004
static inline uint64_t fde_func_0683_0x20a57c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20a57cULL ^ (static_cast<uint64_t>(0xf9404408ULL) << 13);
    acc = (acc + a1 + 0xf9405d00ULL) ^ 0x0db230ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0684 | PC: 0x20a588 | FDE: 0x0db248 | Size: 12 bytes [_ZNK4lynx9starlight12LayoutObject23GetLayoutBorderTopWidthEv]
// Khung tháo gỡ #0684 | Địa chỉ PC: 0x20a588 | Địa chỉ FDE: 0x0db248 | Kích thước: 12 bytes
//   0x20a588: F9404408  ldr      x8, [x0, #0x88]
//   0x20a58c: F9405D00  ldr      x0, [x8, #0xb8]
//   0x20a590: 17FFE2A2  b        #0x203018
static inline uint64_t fde_func_0684_0x20a588(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20a588ULL ^ (static_cast<uint64_t>(0xf9404408ULL) << 13);
    acc = (acc + a1 + 0xf9405d00ULL) ^ 0x0db248ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0685 | PC: 0x20a594 | FDE: 0x0db260 | Size: 256 bytes [_ZNK4lynx9starlight12LayoutObject26GetLayoutBorderBottomWidthEv]
// Khung tháo gỡ #0685 | Địa chỉ PC: 0x20a594 | Địa chỉ FDE: 0x0db260 | Kích thước: 256 bytes
//   0x20a594: F9404408  ldr      x8, [x0, #0x88]
//   0x20a598: F9405D00  ldr      x0, [x8, #0xb8]
//   0x20a59c: 17FFE2A4  b        #0x20302c
//   0x20a5a0: D0FFF3C8  adrp     x8, #0x84000
static inline uint64_t fde_func_0685_0x20a594(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20a594ULL ^ (static_cast<uint64_t>(0xf9404408ULL) << 13);
    acc = (acc + a1 + 0xf9405d00ULL) ^ 0x0db260ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0686 | PC: 0x20a6ac | FDE: 0x0db310 | Size: 8 bytes [_ZNK4lynx9starlight12LayoutObject20GetLayoutPaddingLeftEv]
// Khung tháo gỡ #0686 | Địa chỉ PC: 0x20a6ac | Địa chỉ FDE: 0x0db310 | Kích thước: 8 bytes
//   0x20a6ac: BD40A000  ldr      s0, [x0, #0xa0]
//   0x20a6b0: D65F03C0  ret      
static inline uint64_t fde_func_0686_0x20a6ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20a6acULL ^ (static_cast<uint64_t>(0xbd40a000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0db310ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0687 | PC: 0x20a6b4 | FDE: 0x0db328 | Size: 8 bytes [_ZNK4lynx9starlight12LayoutObject19GetLayoutPaddingTopEv]
// Khung tháo gỡ #0687 | Địa chỉ PC: 0x20a6b4 | Địa chỉ FDE: 0x0db328 | Kích thước: 8 bytes
//   0x20a6b4: BD40A800  ldr      s0, [x0, #0xa8]
//   0x20a6b8: D65F03C0  ret      
static inline uint64_t fde_func_0687_0x20a6b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20a6b4ULL ^ (static_cast<uint64_t>(0xbd40a800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0db328ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0688 | PC: 0x20a6bc | FDE: 0x0db340 | Size: 8 bytes [_ZNK4lynx9starlight12LayoutObject21GetLayoutPaddingRightEv]
// Khung tháo gỡ #0688 | Địa chỉ PC: 0x20a6bc | Địa chỉ FDE: 0x0db340 | Kích thước: 8 bytes
//   0x20a6bc: BD40A400  ldr      s0, [x0, #0xa4]
//   0x20a6c0: D65F03C0  ret      
static inline uint64_t fde_func_0688_0x20a6bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20a6bcULL ^ (static_cast<uint64_t>(0xbd40a400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0db340ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0689 | PC: 0x20a6c4 | FDE: 0x0db358 | Size: 8 bytes [_ZNK4lynx9starlight12LayoutObject22GetLayoutPaddingBottomEv]
// Khung tháo gỡ #0689 | Địa chỉ PC: 0x20a6c4 | Địa chỉ FDE: 0x0db358 | Kích thước: 8 bytes
//   0x20a6c4: BD40AC00  ldr      s0, [x0, #0xac]
//   0x20a6c8: D65F03C0  ret      
static inline uint64_t fde_func_0689_0x20a6c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20a6c4ULL ^ (static_cast<uint64_t>(0xbd40ac00ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0db358ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0690 | PC: 0x20a6cc | FDE: 0x0db370 | Size: 8 bytes [_ZNK4lynx9starlight12LayoutObject19GetLayoutMarginLeftEv]
// Khung tháo gỡ #0690 | Địa chỉ PC: 0x20a6cc | Địa chỉ FDE: 0x0db370 | Kích thước: 8 bytes
//   0x20a6cc: BD40B000  ldr      s0, [x0, #0xb0]
//   0x20a6d0: D65F03C0  ret      
static inline uint64_t fde_func_0690_0x20a6cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20a6ccULL ^ (static_cast<uint64_t>(0xbd40b000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0db370ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0691 | PC: 0x20a6d4 | FDE: 0x0db388 | Size: 8 bytes [_ZNK4lynx9starlight12LayoutObject18GetLayoutMarginTopEv]
// Khung tháo gỡ #0691 | Địa chỉ PC: 0x20a6d4 | Địa chỉ FDE: 0x0db388 | Kích thước: 8 bytes
//   0x20a6d4: BD40B800  ldr      s0, [x0, #0xb8]
//   0x20a6d8: D65F03C0  ret      
static inline uint64_t fde_func_0691_0x20a6d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20a6d4ULL ^ (static_cast<uint64_t>(0xbd40b800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0db388ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0692 | PC: 0x20a6dc | FDE: 0x0db3a0 | Size: 8 bytes [_ZNK4lynx9starlight12LayoutObject20GetLayoutMarginRightEv]
// Khung tháo gỡ #0692 | Địa chỉ PC: 0x20a6dc | Địa chỉ FDE: 0x0db3a0 | Kích thước: 8 bytes
//   0x20a6dc: BD40B400  ldr      s0, [x0, #0xb4]
//   0x20a6e0: D65F03C0  ret      
static inline uint64_t fde_func_0692_0x20a6dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20a6dcULL ^ (static_cast<uint64_t>(0xbd40b400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0db3a0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0693 | PC: 0x20a6e4 | FDE: 0x0db3b8 | Size: 8 bytes [_ZNK4lynx9starlight12LayoutObject21GetLayoutMarginBottomEv]
// Khung tháo gỡ #0693 | Địa chỉ PC: 0x20a6e4 | Địa chỉ FDE: 0x0db3b8 | Kích thước: 8 bytes
//   0x20a6e4: BD40BC00  ldr      s0, [x0, #0xbc]
//   0x20a6e8: D65F03C0  ret      
static inline uint64_t fde_func_0693_0x20a6e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20a6e4ULL ^ (static_cast<uint64_t>(0xbd40bc00ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0db3b8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0694 | PC: 0x20a6ec | FDE: 0x0db3d0 | Size: 256 bytes [_ZN4lynx9starlight12LayoutObject7IsDirtyEv]
// Khung tháo gỡ #0694 | Địa chỉ PC: 0x20a6ec | Địa chỉ FDE: 0x0db3d0 | Kích thước: 256 bytes
//   0x20a6ec: 39464000  ldrb     w0, [x0, #0x190]
//   0x20a6f0: D65F03C0  ret      
//   0x20a6f4: AA1E03E2  mov      x2, x30
//   0x20a6f8: 94044E84  bl       #0x31e108
static inline uint64_t fde_func_0694_0x20a6ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20a6ecULL ^ (static_cast<uint64_t>(0x39464000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0db3d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0695 | PC: 0x20a880 | FDE: 0x0db410 | Size: 256 bytes [_ZN4lynx9starlight12LayoutObject23ReLayoutWithConstraintsERNSt6__ndk15arrayINS0_17OneSideConstraintELm2EEEPKNS2_13unordered_setIPS1_NS2_4hashIS8_EENS2_8equal_toIS8_EENS2_9allocatorIS8_EEEE]
// Khung tháo gỡ #0695 | Địa chỉ PC: 0x20a880 | Địa chỉ FDE: 0x0db410 | Kích thước: 256 bytes
//   0x20a880: D10103FF  sub      sp, sp, #0x40
//   0x20a884: F9000BF6  str      x22, [sp, #0x10]
//   0x20a888: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x20a88c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0695_0x20a880(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20a880ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x0db410ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0696 | PC: 0x20a9d0 | FDE: 0x0db4b0 | Size: 116 bytes [_ZN4lynx9starlight12LayoutObject12MarkNotDirtyEv]
// Khung tháo gỡ #0696 | Địa chỉ PC: 0x20a9d0 | Địa chỉ FDE: 0x0db4b0 | Kích thước: 116 bytes
//   0x20a9d0: 52800028  mov      w8, #1
//   0x20a9d4: 3906401F  strb     wzr, [x0, #0x190]
//   0x20a9d8: 39064808  strb     w8, [x0, #0x192]
//   0x20a9dc: D65F03C0  ret      
static inline uint64_t fde_func_0696_0x20a9d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20a9d0ULL ^ (static_cast<uint64_t>(0x52800028ULL) << 13);
    acc = (acc + a1 + 0x3906401fULL) ^ 0x0db4b0ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0697 | PC: 0x20aa44 | FDE: 0x0db520 | Size: 256 bytes
// Khung tháo gỡ #0697 | Địa chỉ PC: 0x20aa44 | Địa chỉ FDE: 0x0db520 | Kích thước: 256 bytes
//   0x20aa44: F9400008  ldr      x8, [x0]
//   0x20aa48: 9100A100  add      x0, x8, #0x28
//   0x20aa4c: D65F03C0  ret      
//   0x20aa50: 91022000  add      x0, x0, #0x88
static inline uint64_t fde_func_0697_0x20aa44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20aa44ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0x9100a100ULL) ^ 0x0db520ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0698 | PC: 0x20abdc | FDE: 0x0db638 | Size: 256 bytes
// Khung tháo gỡ #0698 | Địa chỉ PC: 0x20abdc | Địa chỉ FDE: 0x0db638 | Kích thước: 256 bytes
//   0x20abdc: FC1D0FE8  str      d8, [sp, #-0x30]!
//   0x20abe0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x20abe4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x20abe8: AA0103F5  mov      x21, x1
static inline uint64_t fde_func_0698_0x20abdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20abdcULL ^ (static_cast<uint64_t>(0xfc1d0fe8ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0db638ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0699 | PC: 0x20ad4c | FDE: 0x0db698 | Size: 256 bytes [_ZN4lynx9starlight12LayoutObject5ResetEPS1_]
// Khung tháo gỡ #0699 | Địa chỉ PC: 0x20ad4c | Địa chỉ FDE: 0x0db698 | Kích thước: 256 bytes
//   0x20ad4c: D10143FF  sub      sp, sp, #0x50
//   0x20ad50: F90013F6  str      x22, [sp, #0x20]
//   0x20ad54: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x20ad58: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0699_0x20ad4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20ad4cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x0db698ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0700 | PC: 0x20b124 | FDE: 0x0db738 | Size: 68 bytes [_ZN4lynx9starlight12LayoutObject50SetCanReuseLayoutWithSameSizeAsGivenConstraintFuncEPFbPvbE]
// Khung tháo gỡ #0700 | Địa chỉ PC: 0x20b124 | Địa chỉ FDE: 0x0db738 | Kích thước: 68 bytes
//   0x20b124: F9003001  str      x1, [x0, #0x60]
//   0x20b128: 17FFFB81  b        #0x209f2c
//   0x20b12c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x20b130: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0700_0x20b124(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20b124ULL ^ (static_cast<uint64_t>(0xf9003001ULL) << 13);
    acc = (acc + a1 + 0x17fffb81ULL) ^ 0x0db738ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0701 | PC: 0x20b168 | FDE: 0x0db768 | Size: 256 bytes
// Khung tháo gỡ #0701 | Địa chỉ PC: 0x20b168 | Địa chỉ FDE: 0x0db768 | Kích thước: 256 bytes
//   0x20b168: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x20b16c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x20b170: B0000A28  adrp     x8, #0x350000
//   0x20b174: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0701_0x20b168(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20b168ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0db768ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0702 | PC: 0x20babc | FDE: 0x0db8d8 | Size: 256 bytes
// Khung tháo gỡ #0702 | Địa chỉ PC: 0x20babc | Địa chỉ FDE: 0x0db8d8 | Kích thước: 256 bytes
//   0x20babc: 91008002  add      x2, x0, #0x20
//   0x20bac0: 1400000C  b        #0x20baf0
//   0x20bac4: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x20bac8: A9017BF3  stp      x19, x30, [sp, #0x10]
static inline uint64_t fde_func_0702_0x20babc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20babcULL ^ (static_cast<uint64_t>(0x91008002ULL) << 13);
    acc = (acc + a1 + 0x1400000cULL) ^ 0x0db8d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0703 | PC: 0x20c46c | FDE: 0x0dba08 | Size: 256 bytes
// Khung tháo gỡ #0703 | Địa chỉ PC: 0x20c46c | Địa chỉ FDE: 0x0dba08 | Kích thước: 256 bytes
//   0x20c46c: 90000A28  adrp     x8, #0x350000
//   0x20c470: 91262108  add      x8, x8, #0x988
//   0x20c474: 14044D33  b        #0x31f940
//   0x20c478: F9404428  ldr      x8, [x1, #0x88]
static inline uint64_t fde_func_0703_0x20c46c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20c46cULL ^ (static_cast<uint64_t>(0x90000a28ULL) << 13);
    acc = (acc + a1 + 0x91262108ULL) ^ 0x0dba08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0704 | PC: 0x20cc34 | FDE: 0x0dbb28 | Size: 256 bytes
// Khung tháo gỡ #0704 | Địa chỉ PC: 0x20cc34 | Địa chỉ FDE: 0x0dbb28 | Kích thước: 256 bytes
//   0x20cc34: 39401C2E  ldrb     w14, [x1, #7]
//   0x20cc38: 78405028  ldurh    w8, [x1, #5]
//   0x20cc3c: 39403C2F  ldrb     w15, [x1, #0xf]
//   0x20cc40: 7840D02A  ldurh    w10, [x1, #0xd]
static inline uint64_t fde_func_0704_0x20cc34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20cc34ULL ^ (static_cast<uint64_t>(0x39401c2eULL) << 13);
    acc = (acc + a1 + 0x78405028ULL) ^ 0x0dbb28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0705 | PC: 0x20d524 | FDE: 0x0dbc60 | Size: 256 bytes [_ZN4lynx9starlight14property_utils26GenerateDefaultConstraintsERKNS0_12LayoutObjectERKNSt6__ndk15arrayINS0_17OneSideConstraintELm2EEE]
// Khung tháo gỡ #0705 | Địa chỉ PC: 0x20d524 | Địa chỉ FDE: 0x0dbc60 | Kích thước: 256 bytes
//   0x20d524: D10143FF  sub      sp, sp, #0x50
//   0x20d528: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x20d52c: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x20d530: 940440A4  bl       #0x31d7c0
static inline uint64_t fde_func_0705_0x20d524(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20d524ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90353f5ULL) ^ 0x0dbc60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0706 | PC: 0x20d698 | FDE: 0x0dbc98 | Size: 256 bytes
// Khung tháo gỡ #0706 | Địa chỉ PC: 0x20d698 | Địa chỉ FDE: 0x0dbc98 | Kích thước: 256 bytes
//   0x20d698: D100C3FF  sub      sp, sp, #0x30
//   0x20d69c: F9000BF4  str      x20, [sp, #0x10]
//   0x20d6a0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x20d6a4: 94043F48  bl       #0x31d3c4
static inline uint64_t fde_func_0706_0x20d698(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20d698ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x0dbc98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0707 | PC: 0x20de40 | FDE: 0x0dbdd0 | Size: 256 bytes
// Khung tháo gỡ #0707 | Địa chỉ PC: 0x20de40 | Địa chỉ FDE: 0x0dbdd0 | Kích thước: 256 bytes
//   0x20de40: AA1E03E3  mov      x3, x30
//   0x20de44: 94044013  bl       #0x31de90
//   0x20de48: AA0303FE  mov      x30, x3
//   0x20de4c: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0707_0x20de40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20de40ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94044013ULL) ^ 0x0dbdd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0708 | PC: 0x20e7bc | FDE: 0x0dbf20 | Size: 256 bytes
// Khung tháo gỡ #0708 | Địa chỉ PC: 0x20e7bc | Địa chỉ FDE: 0x0dbf20 | Kích thước: 256 bytes
//   0x20e7bc: D0000A08  adrp     x8, #0x350000
//   0x20e7c0: 912B2108  add      x8, x8, #0xac8
//   0x20e7c4: 14043A21  b        #0x31d048
//   0x20e7c8: F9400021  ldr      x1, [x1]
static inline uint64_t fde_func_0708_0x20e7bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20e7bcULL ^ (static_cast<uint64_t>(0xd0000a08ULL) << 13);
    acc = (acc + a1 + 0x912b2108ULL) ^ 0x0dbf20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0709 | PC: 0x20ea04 | FDE: 0x0dc038 | Size: 256 bytes
// Khung tháo gỡ #0709 | Địa chỉ PC: 0x20ea04 | Địa chỉ FDE: 0x0dc038 | Kích thước: 256 bytes
//   0x20ea04: AA1E03E2  mov      x2, x30
//   0x20ea08: 94043EAF  bl       #0x31e4c4
//   0x20ea0c: AA0203FE  mov      x30, x2
//   0x20ea10: A90D7BFD  stp      x29, x30, [sp, #0xd0]
static inline uint64_t fde_func_0709_0x20ea04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20ea04ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94043eafULL) ^ 0x0dc038ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0710 | PC: 0x20ef94 | FDE: 0x0dc160 | Size: 256 bytes
// Khung tháo gỡ #0710 | Địa chỉ PC: 0x20ef94 | Địa chỉ FDE: 0x0dc160 | Kích thước: 256 bytes
//   0x20ef94: D100C3FF  sub      sp, sp, #0x30
//   0x20ef98: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x20ef9c: 94046A67  bl       #0x329938
//   0x20efa0: F9405808  ldr      x8, [x0, #0xb0]
static inline uint64_t fde_func_0710_0x20ef94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20ef94ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9027bf3ULL) ^ 0x0dc160ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0711 | PC: 0x20f0b4 | FDE: 0x0dc198 | Size: 216 bytes [_ZN4lynx9starlight11BordersDataC1Eb]
// Khung tháo gỡ #0711 | Địa chỉ PC: 0x20f0b4 | Địa chỉ FDE: 0x0dc198 | Kích thước: 216 bytes
//   0x20f0b4: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x20f0b8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x20f0bc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x20f0c0: 7200003F  tst      w1, #1
static inline uint64_t fde_func_0711_0x20f0b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20f0b4ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0dc198ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #0712 | PC: 0x20f18c | FDE: 0x0dc1b8 | Size: 124 bytes [_ZN4lynx9starlight7BoxDataC2ERKS1_]
// Khung tháo gỡ #0712 | Địa chỉ PC: 0x20f18c | Địa chỉ FDE: 0x0dc1b8 | Kích thước: 124 bytes
//   0x20f18c: B0000A09  adrp     x9, #0x350000
//   0x20f190: 52800028  mov      w8, #1
//   0x20f194: 912E4129  add      x9, x9, #0xb90
//   0x20f198: A9002009  stp      x9, x8, [x0]
static inline uint64_t fde_func_0712_0x20f18c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20f18cULL ^ (static_cast<uint64_t>(0xb0000a09ULL) << 13);
    acc = (acc + a1 + 0x52800028ULL) ^ 0x0dc1b8ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0713 | PC: 0x20f208 | FDE: 0x0dc1d0 | Size: 232 bytes [_ZN4lynx9starlight8FlexDataC1ERKS1_]
// Khung tháo gỡ #0713 | Địa chỉ PC: 0x20f208 | Địa chỉ FDE: 0x0dc1d0 | Kích thước: 232 bytes
//   0x20f208: B0000A09  adrp     x9, #0x350000
//   0x20f20c: 52800028  mov      w8, #1
//   0x20f210: 912E4129  add      x9, x9, #0xb90
//   0x20f214: A9002009  stp      x9, x8, [x0]
static inline uint64_t fde_func_0713_0x20f208(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20f208ULL ^ (static_cast<uint64_t>(0xb0000a09ULL) << 13);
    acc = (acc + a1 + 0x52800028ULL) ^ 0x0dc1d0ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0714 | PC: 0x20f2f0 | FDE: 0x0dc220 | Size: 232 bytes [_ZN4lynx9starlight8GridDataC2ERKS1_]
// Khung tháo gỡ #0714 | Địa chỉ PC: 0x20f2f0 | Địa chỉ FDE: 0x0dc220 | Kích thước: 232 bytes
//   0x20f2f0: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x20f2f4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x20f2f8: B0000A09  adrp     x9, #0x350000
//   0x20f2fc: 94043527  bl       #0x31c798
static inline uint64_t fde_func_0714_0x20f2f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20f2f0ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0dc220ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0715 | PC: 0x20f3d8 | FDE: 0x0dc240 | Size: 256 bytes [_ZN4lynx9starlight19LayoutComputedStyleC1Ed]
// Khung tháo gỡ #0715 | Địa chỉ PC: 0x20f3d8 | Địa chỉ FDE: 0x0dc240 | Kích thước: 256 bytes
//   0x20f3d8: D10143FF  sub      sp, sp, #0x50
//   0x20f3dc: FD000BE8  str      d8, [sp, #0x10]
//   0x20f3e0: F9000FF8  str      x24, [sp, #0x18]
//   0x20f3e4: A9025BF7  stp      x23, x22, [sp, #0x20]
static inline uint64_t fde_func_0715_0x20f3d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20f3d8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xfd000be8ULL) ^ 0x0dc240ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0716 | PC: 0x20f660 | FDE: 0x0dc268 | Size: 256 bytes [_ZN4lynx9starlight19LayoutComputedStyleC2ERKS1_]
// Khung tháo gỡ #0716 | Địa chỉ PC: 0x20f660 | Địa chỉ FDE: 0x0dc268 | Kích thước: 256 bytes
//   0x20f660: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x20f664: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x20f668: 94047EFA  bl       #0x32f250
//   0x20f66c: 6F00E400  movi     v0.2d, #0000000000000000
static inline uint64_t fde_func_0716_0x20f660(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20f660ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0dc268ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0717 | PC: 0x20f760 | FDE: 0x0dc288 | Size: 256 bytes
// Khung tháo gỡ #0717 | Địa chỉ PC: 0x20f760 | Địa chỉ FDE: 0x0dc288 | Kích thước: 256 bytes
//   0x20f760: D101C3FF  sub      sp, sp, #0x70
//   0x20f764: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x20f768: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x20f76c: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0717_0x20f760(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20f760ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90553f5ULL) ^ 0x0dc288ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0718 | PC: 0x20f99c | FDE: 0x0dc2e0 | Size: 80 bytes [_ZNK4lynx9starlight7NLengtheqERKS1_]
// Khung tháo gỡ #0718 | Địa chỉ PC: 0x20f99c | Địa chỉ FDE: 0x0dc2e0 | Kích thước: 80 bytes
//   0x20f99c: 39402808  ldrb     w8, [x0, #0xa]
//   0x20f9a0: 39402829  ldrb     w9, [x1, #0xa]
//   0x20f9a4: 6B09011F  cmp      w8, w9
//   0x20f9a8: 54000201  b.ne     #0x20f9e8
static inline uint64_t fde_func_0718_0x20f99c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20f99cULL ^ (static_cast<uint64_t>(0x39402808ULL) << 13);
    acc = (acc + a1 + 0x39402829ULL) ^ 0x0dc2e0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0719 | PC: 0x20f9ec | FDE: 0x0dc2f8 | Size: 20 bytes [_ZNK4lynx9starlight7NLengthneERKS1_]
// Khung tháo gỡ #0719 | Địa chỉ PC: 0x20f9ec | Địa chỉ FDE: 0x0dc2f8 | Kích thước: 20 bytes
//   0x20f9ec: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x20f9f0: 9404C544  bl       #0x340f00
//   0x20f9f4: 940457BC  bl       #0x3258e4
//   0x20f9f8: F84107FE  ldr      x30, [sp], #0x10
static inline uint64_t fde_func_0719_0x20f9ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20f9ecULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x9404c544ULL) ^ 0x0dc2f8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0720 | PC: 0x20fa00 | FDE: 0x0dc310 | Size: 8 bytes [_ZN4lynx9starlight7NLength15MakeAutoNLengthEv]
// Khung tháo gỡ #0720 | Địa chỉ PC: 0x20fa00 | Địa chỉ FDE: 0x0dc310 | Kích thước: 8 bytes
//   0x20fa00: B800711F  stur     wzr, [x8, #7]
//   0x20fa04: 17FD0BBC  b        #0x1528f4
static inline uint64_t fde_func_0720_0x20fa00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20fa00ULL ^ (static_cast<uint64_t>(0xb800711fULL) << 13);
    acc = (acc + a1 + 0x17fd0bbcULL) ^ 0x0dc310ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0721 | PC: 0x20fa08 | FDE: 0x0dc328 | Size: 20 bytes [_ZN4lynx9starlight7NLength21MakeMaxContentNLengthEv]
// Khung tháo gỡ #0721 | Địa chỉ PC: 0x20fa08 | Địa chỉ FDE: 0x0dc328 | Kích thước: 20 bytes
//   0x20fa08: 52800089  mov      w9, #4
//   0x20fa0c: 7900111F  strh     wzr, [x8, #8]
//   0x20fa10: F900011F  str      xzr, [x8]
//   0x20fa14: 39002909  strb     w9, [x8, #0xa]
static inline uint64_t fde_func_0721_0x20fa08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20fa08ULL ^ (static_cast<uint64_t>(0x52800089ULL) << 13);
    acc = (acc + a1 + 0x7900111fULL) ^ 0x0dc328ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0722 | PC: 0x20fa1c | FDE: 0x0dc340 | Size: 24 bytes [_ZN4lynx9starlight7NLength15MakeUnitNLengthEf]
// Khung tháo gỡ #0722 | Địa chỉ PC: 0x20fa1c | Địa chỉ FDE: 0x0dc340 | Kích thước: 24 bytes
//   0x20fa1c: 52800029  mov      w9, #1
//   0x20fa20: BD000100  str      s0, [x8]
//   0x20fa24: B900051F  str      wzr, [x8, #4]
//   0x20fa28: 79001109  strh     w9, [x8, #8]
static inline uint64_t fde_func_0722_0x20fa1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20fa1cULL ^ (static_cast<uint64_t>(0x52800029ULL) << 13);
    acc = (acc + a1 + 0xbd000100ULL) ^ 0x0dc340ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0723 | PC: 0x20fa34 | FDE: 0x0dc358 | Size: 40 bytes [_ZN4lynx9starlight7NLength21MakePercentageNLengthEf]
// Khung tháo gỡ #0723 | Địa chỉ PC: 0x20fa34 | Địa chỉ FDE: 0x0dc358 | Kích thước: 40 bytes
//   0x20fa34: 52802029  mov      w9, #0x101
//   0x20fa38: 5280004A  mov      w10, #2
//   0x20fa3c: B900011F  str      wzr, [x8]
//   0x20fa40: BD000500  str      s0, [x8, #4]
static inline uint64_t fde_func_0723_0x20fa34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20fa34ULL ^ (static_cast<uint64_t>(0x52802029ULL) << 13);
    acc = (acc + a1 + 0x5280004aULL) ^ 0x0dc358ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0724 | PC: 0x20fa5c | FDE: 0x0dc388 | Size: 256 bytes
// Khung tháo gỡ #0724 | Địa chỉ PC: 0x20fa5c | Địa chỉ FDE: 0x0dc388 | Kích thước: 256 bytes
//   0x20fa5c: 39402028  ldrb     w8, [x1, #8]
//   0x20fa60: 34000168  cbz      w8, #0x20fa8c
//   0x20fa64: 39402428  ldrb     w8, [x1, #9]
//   0x20fa68: BD400021  ldr      s1, [x1]
static inline uint64_t fde_func_0724_0x20fa5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20fa5cULL ^ (static_cast<uint64_t>(0x39402028ULL) << 13);
    acc = (acc + a1 + 0x34000168ULL) ^ 0x0dc388ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0725 | PC: 0x20febc | FDE: 0x0dc4a0 | Size: 256 bytes
// Khung tháo gỡ #0725 | Địa chỉ PC: 0x20febc | Địa chỉ FDE: 0x0dc4a0 | Kích thước: 256 bytes
//   0x20febc: D10083FF  sub      sp, sp, #0x20
//   0x20fec0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x20fec4: 94043627  bl       #0x31d760
//   0x20fec8: 910013E3  add      x3, sp, #4
static inline uint64_t fde_func_0725_0x20febc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x20febcULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0dc4a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0726 | PC: 0x210768 | FDE: 0x0dc5f0 | Size: 256 bytes
// Khung tháo gỡ #0726 | Địa chỉ PC: 0x210768 | Địa chỉ FDE: 0x0dc5f0 | Kích thước: 256 bytes
//   0x210768: AA1E03E3  mov      x3, x30
//   0x21076c: 940432C1  bl       #0x31d270
//   0x210770: AA0303FE  mov      x30, x3
//   0x210774: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_0726_0x210768(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x210768ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x940432c1ULL) ^ 0x0dc5f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0727 | PC: 0x210bc0 | FDE: 0x0dc720 | Size: 256 bytes
// Khung tháo gỡ #0727 | Địa chỉ PC: 0x210bc0 | Địa chỉ FDE: 0x0dc720 | Kích thước: 256 bytes
//   0x210bc0: F9429C00  ldr      x0, [x0, #0x538]
//   0x210bc4: B4000040  cbz      x0, #0x210bcc
//   0x210bc8: 14048620  b        #0x332448
//   0x210bcc: D65F03C0  ret      
static inline uint64_t fde_func_0727_0x210bc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x210bc0ULL ^ (static_cast<uint64_t>(0xf9429c00ULL) << 13);
    acc = (acc + a1 + 0xb4000040ULL) ^ 0x0dc720ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0728 | PC: 0x210db8 | FDE: 0x0dc820 | Size: 256 bytes
// Khung tháo gỡ #0728 | Địa chỉ PC: 0x210db8 | Địa chỉ FDE: 0x0dc820 | Kích thước: 256 bytes
//   0x210db8: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x210dbc: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x210dc0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x210dc4: 94043014  bl       #0x31ce14
static inline uint64_t fde_func_0728_0x210db8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x210db8ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0dc820ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0729 | PC: 0x2111b4 | FDE: 0x0dc968 | Size: 256 bytes
// Khung tháo gỡ #0729 | Địa chỉ PC: 0x2111b4 | Địa chỉ FDE: 0x0dc968 | Kích thước: 256 bytes
//   0x2111b4: D10203FF  sub      sp, sp, #0x80
//   0x2111b8: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x2111bc: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x2111c0: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0729_0x2111b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2111b4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9055bf7ULL) ^ 0x0dc968ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0730 | PC: 0x211958 | FDE: 0x0dcab8 | Size: 256 bytes
// Khung tháo gỡ #0730 | Địa chỉ PC: 0x211958 | Địa chỉ FDE: 0x0dcab8 | Kích thước: 256 bytes
//   0x211958: AA1E03E1  mov      x1, x30
//   0x21195c: 94048EAE  bl       #0x335414
//   0x211960: AA0103FE  mov      x30, x1
//   0x211964: A91E7BFD  stp      x29, x30, [sp, #0x1e0]
static inline uint64_t fde_func_0730_0x211958(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x211958ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x94048eaeULL) ^ 0x0dcab8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0731 | PC: 0x212948 | FDE: 0x0dcc18 | Size: 256 bytes
// Khung tháo gỡ #0731 | Địa chỉ PC: 0x212948 | Địa chỉ FDE: 0x0dcc18 | Kích thước: 256 bytes
//   0x212948: D10103FF  sub      sp, sp, #0x40
//   0x21294c: F90013F4  str      x20, [sp, #0x20]
//   0x212950: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x212954: 94042939  bl       #0x31ce38
static inline uint64_t fde_func_0731_0x212948(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x212948ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f4ULL) ^ 0x0dcc18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0732 | PC: 0x2134c4 | FDE: 0x0dcd78 | Size: 256 bytes
// Khung tháo gỡ #0732 | Địa chỉ PC: 0x2134c4 | Địa chỉ FDE: 0x0dcd78 | Kích thước: 256 bytes
//   0x2134c4: B9400029  ldr      w9, [x1]
//   0x2134c8: B9400008  ldr      w8, [x0]
//   0x2134cc: B940004A  ldr      w10, [x2]
//   0x2134d0: 6B08013F  cmp      w9, w8
static inline uint64_t fde_func_0732_0x2134c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2134c4ULL ^ (static_cast<uint64_t>(0xb9400029ULL) << 13);
    acc = (acc + a1 + 0xb9400008ULL) ^ 0x0dcd78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0733 | PC: 0x213b4c | FDE: 0x0dcea0 | Size: 256 bytes
// Khung tháo gỡ #0733 | Địa chỉ PC: 0x213b4c | Địa chỉ FDE: 0x0dcea0 | Kích thước: 256 bytes
//   0x213b4c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x213b50: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x213b54: AA0003F3  mov      x19, x0
//   0x213b58: F9405400  ldr      x0, [x0, #0xa8]
static inline uint64_t fde_func_0733_0x213b4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x213b4cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0dcea0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0734 | PC: 0x214074 | FDE: 0x0dcfd8 | Size: 256 bytes
// Khung tháo gỡ #0734 | Địa chỉ PC: 0x214074 | Địa chỉ FDE: 0x0dcfd8 | Kích thước: 256 bytes
//   0x214074: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x214078: B4000121  cbz      x1, #0x21409c
//   0x21407c: F9402013  ldr      x19, [x0, #0x40]
//   0x214080: 9100C021  add      x1, x1, #0x30
static inline uint64_t fde_func_0734_0x214074(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x214074ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb4000121ULL) ^ 0x0dcfd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0735 | PC: 0x214e7c | FDE: 0x0dd130 | Size: 256 bytes
// Khung tháo gỡ #0735 | Địa chỉ PC: 0x214e7c | Địa chỉ FDE: 0x0dd130 | Kích thước: 256 bytes
//   0x214e7c: D10143FF  sub      sp, sp, #0x50
//   0x214e80: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x214e84: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x214e88: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0735_0x214e7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x214e7cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x0dd130ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0736 | PC: 0x215188 | FDE: 0x0dd248 | Size: 256 bytes
// Khung tháo gỡ #0736 | Địa chỉ PC: 0x215188 | Địa chỉ FDE: 0x0dd248 | Kích thước: 256 bytes
//   0x215188: B40001A1  cbz      x1, #0x2151bc
//   0x21518c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x215190: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x215194: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0736_0x215188(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x215188ULL ^ (static_cast<uint64_t>(0xb40001a1ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff4ULL) ^ 0x0dd248ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0737 | PC: 0x2153ac | FDE: 0x0dd350 | Size: 256 bytes
// Khung tháo gỡ #0737 | Địa chỉ PC: 0x2153ac | Địa chỉ FDE: 0x0dd350 | Kích thước: 256 bytes
//   0x2153ac: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2153b0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2153b4: AA0003F4  mov      x20, x0
//   0x2153b8: F9402400  ldr      x0, [x0, #0x48]
static inline uint64_t fde_func_0737_0x2153ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2153acULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0dd350ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0738 | PC: 0x215520 | FDE: 0x0dd450 | Size: 256 bytes
// Khung tháo gỡ #0738 | Địa chỉ PC: 0x215520 | Địa chỉ FDE: 0x0dd450 | Kích thước: 256 bytes
//   0x215520: AA1E03E4  mov      x4, x30
//   0x215524: 940420D9  bl       #0x31d888
//   0x215528: AA0403FE  mov      x30, x4
//   0x21552c: A90B7BFD  stp      x29, x30, [sp, #0xb0]
static inline uint64_t fde_func_0738_0x215520(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x215520ULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x940420d9ULL) ^ 0x0dd450ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0739 | PC: 0x215fe8 | FDE: 0x0dd590 | Size: 256 bytes
// Khung tháo gỡ #0739 | Địa chỉ PC: 0x215fe8 | Địa chỉ FDE: 0x0dd590 | Kích thước: 256 bytes
//   0x215fe8: F9400C28  ldr      x8, [x1, #0x18]
//   0x215fec: 14046ABA  b        #0x330ad4
//   0x215ff0: 39404428  ldrb     w8, [x1, #0x11]
//   0x215ff4: 35000068  cbnz     w8, #0x216000
static inline uint64_t fde_func_0739_0x215fe8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x215fe8ULL ^ (static_cast<uint64_t>(0xf9400c28ULL) << 13);
    acc = (acc + a1 + 0x14046abaULL) ^ 0x0dd590ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0740 | PC: 0x216144 | FDE: 0x0dd688 | Size: 256 bytes
// Khung tháo gỡ #0740 | Địa chỉ PC: 0x216144 | Địa chỉ FDE: 0x0dd688 | Kích thước: 256 bytes
//   0x216144: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x216148: F90007F4  str      x20, [sp, #8]
//   0x21614c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x216150: F9402408  ldr      x8, [x0, #0x48]
static inline uint64_t fde_func_0740_0x216144(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x216144ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xf90007f4ULL) ^ 0x0dd688ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0741 | PC: 0x216bf0 | FDE: 0x0dd7f0 | Size: 256 bytes
// Khung tháo gỡ #0741 | Địa chỉ PC: 0x216bf0 | Địa chỉ FDE: 0x0dd7f0 | Kích thước: 256 bytes
//   0x216bf0: F00009C8  adrp     x8, #0x351000
//   0x216bf4: 91178108  add      x8, x8, #0x5e0
//   0x216bf8: 140419AA  b        #0x31d2a0
//   0x216bfc: 6DBD23E9  stp      d9, d8, [sp, #-0x30]!
static inline uint64_t fde_func_0741_0x216bf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x216bf0ULL ^ (static_cast<uint64_t>(0xf00009c8ULL) << 13);
    acc = (acc + a1 + 0x91178108ULL) ^ 0x0dd7f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0742 | PC: 0x216fa4 | FDE: 0x0dd8f8 | Size: 256 bytes
// Khung tháo gỡ #0742 | Địa chỉ PC: 0x216fa4 | Địa chỉ FDE: 0x0dd8f8 | Kích thước: 256 bytes
//   0x216fa4: B9407008  ldr      w8, [x0, #0x70]
//   0x216fa8: 7100051F  cmp      w8, #1
//   0x216fac: 540000A1  b.ne     #0x216fc0
//   0x216fb0: BD405C00  ldr      s0, [x0, #0x5c]
static inline uint64_t fde_func_0742_0x216fa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x216fa4ULL ^ (static_cast<uint64_t>(0xb9407008ULL) << 13);
    acc = (acc + a1 + 0x7100051fULL) ^ 0x0dd8f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0743 | PC: 0x2177e0 | FDE: 0x0dda48 | Size: 256 bytes
// Khung tháo gỡ #0743 | Địa chỉ PC: 0x2177e0 | Địa chỉ FDE: 0x0dda48 | Kích thước: 256 bytes
//   0x2177e0: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x2177e4: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x2177e8: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x2177ec: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0743_0x2177e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2177e0ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0dda48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0744 | PC: 0x217e8c | FDE: 0x0ddb90 | Size: 256 bytes
// Khung tháo gỡ #0744 | Địa chỉ PC: 0x217e8c | Địa chỉ FDE: 0x0ddb90 | Kích thước: 256 bytes
//   0x217e8c: D101C3FF  sub      sp, sp, #0x70
//   0x217e90: A9045BF7  stp      x23, x22, [sp, #0x40]
//   0x217e94: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x217e98: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_0744_0x217e8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x217e8cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9045bf7ULL) ^ 0x0ddb90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0745 | PC: 0x2181c0 | FDE: 0x0ddcb0 | Size: 256 bytes
// Khung tháo gỡ #0745 | Địa chỉ PC: 0x2181c0 | Địa chỉ FDE: 0x0ddcb0 | Kích thước: 256 bytes
//   0x2181c0: 6DBC23E9  stp      d9, d8, [sp, #-0x40]!
//   0x2181c4: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x2181c8: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x2181cc: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0745_0x2181c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2181c0ULL ^ (static_cast<uint64_t>(0x6dbc23e9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0ddcb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0746 | PC: 0x2184d4 | FDE: 0x0dddd0 | Size: 256 bytes
// Khung tháo gỡ #0746 | Địa chỉ PC: 0x2184d4 | Địa chỉ FDE: 0x0dddd0 | Kích thước: 256 bytes
//   0x2184d4: D10243FF  sub      sp, sp, #0x90
//   0x2184d8: F9003BF4  str      x20, [sp, #0x70]
//   0x2184dc: A9087BF3  stp      x19, x30, [sp, #0x80]
//   0x2184e0: D53BD053  mrs      x19, tpidr_el0
static inline uint64_t fde_func_0746_0x2184d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2184d4ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf4ULL) ^ 0x0dddd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0747 | PC: 0x218ccc | FDE: 0x0ddf00 | Size: 256 bytes
// Khung tháo gỡ #0747 | Địa chỉ PC: 0x218ccc | Địa chỉ FDE: 0x0ddf00 | Kích thước: 256 bytes
//   0x218ccc: AA1E03E3  mov      x3, x30
//   0x218cd0: 94041A8F  bl       #0x31f70c
//   0x218cd4: AA0303FE  mov      x30, x3
//   0x218cd8: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0747_0x218ccc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x218cccULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94041a8fULL) ^ 0x0ddf00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0748 | PC: 0x219354 | FDE: 0x0de020 | Size: 256 bytes
// Khung tháo gỡ #0748 | Địa chỉ PC: 0x219354 | Địa chỉ FDE: 0x0de020 | Kích thước: 256 bytes
//   0x219354: AA1E03E3  mov      x3, x30
//   0x219358: 94041F0F  bl       #0x320f94
//   0x21935c: AA0303FE  mov      x30, x3
//   0x219360: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_0748_0x219354(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x219354ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94041f0fULL) ^ 0x0de020ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0749 | PC: 0x219804 | FDE: 0x0de140 | Size: 256 bytes
// Khung tháo gỡ #0749 | Địa chỉ PC: 0x219804 | Địa chỉ FDE: 0x0de140 | Kích thước: 256 bytes
//   0x219804: FC1D0FEA  str      d10, [sp, #-0x30]!
//   0x219808: 6D00A3E9  stp      d9, d8, [sp, #8]
//   0x21980c: F9000FF4  str      x20, [sp, #0x18]
//   0x219810: A9027BF3  stp      x19, x30, [sp, #0x20]
static inline uint64_t fde_func_0749_0x219804(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x219804ULL ^ (static_cast<uint64_t>(0xfc1d0feaULL) << 13);
    acc = (acc + a1 + 0x6d00a3e9ULL) ^ 0x0de140ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0750 | PC: 0x219cb4 | FDE: 0x0de268 | Size: 256 bytes
// Khung tháo gỡ #0750 | Địa chỉ PC: 0x219cb4 | Địa chỉ FDE: 0x0de268 | Kích thước: 256 bytes
//   0x219cb4: D10203FF  sub      sp, sp, #0x80
//   0x219cb8: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x219cbc: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x219cc0: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0750_0x219cb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x219cb4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9055bf7ULL) ^ 0x0de268ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0751 | PC: 0x21a0d4 | FDE: 0x0de388 | Size: 256 bytes
// Khung tháo gỡ #0751 | Địa chỉ PC: 0x21a0d4 | Địa chỉ FDE: 0x0de388 | Kích thước: 256 bytes
//   0x21a0d4: D10183FF  sub      sp, sp, #0x60
//   0x21a0d8: A9057BF3  stp      x19, x30, [sp, #0x50]
//   0x21a0dc: 94040DA1  bl       #0x31d760
//   0x21a0e0: F00009A9  adrp     x9, #0x351000
static inline uint64_t fde_func_0751_0x21a0d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x21a0d4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9057bf3ULL) ^ 0x0de388ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0752 | PC: 0x21a324 | FDE: 0x0de490 | Size: 256 bytes
// Khung tháo gỡ #0752 | Địa chỉ PC: 0x21a324 | Địa chỉ FDE: 0x0de490 | Kích thước: 256 bytes
//   0x21a324: FC1B0FEC  str      d12, [sp, #-0x50]!
//   0x21a328: 6D012BEB  stp      d11, d10, [sp, #0x10]
//   0x21a32c: 6D0223E9  stp      d9, d8, [sp, #0x20]
//   0x21a330: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0752_0x21a324(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x21a324ULL ^ (static_cast<uint64_t>(0xfc1b0fecULL) << 13);
    acc = (acc + a1 + 0x6d012bebULL) ^ 0x0de490ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0753 | PC: 0x21a5a0 | FDE: 0x0de5b8 | Size: 256 bytes
// Khung tháo gỡ #0753 | Địa chỉ PC: 0x21a5a0 | Địa chỉ FDE: 0x0de5b8 | Kích thước: 256 bytes
//   0x21a5a0: F00009A8  adrp     x8, #0x351000
//   0x21a5a4: 912E2108  add      x8, x8, #0xb88
//   0x21a5a8: 14040B3E  b        #0x31d2a0
//   0x21a5ac: D100C3FF  sub      sp, sp, #0x30
static inline uint64_t fde_func_0753_0x21a5a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x21a5a0ULL ^ (static_cast<uint64_t>(0xf00009a8ULL) << 13);
    acc = (acc + a1 + 0x912e2108ULL) ^ 0x0de5b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0754 | PC: 0x21b770 | FDE: 0x0de6d0 | Size: 256 bytes
// Khung tháo gỡ #0754 | Địa chỉ PC: 0x21b770 | Địa chỉ FDE: 0x0de6d0 | Kích thước: 256 bytes
//   0x21b770: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x21b774: AA0003F3  mov      x19, x0
//   0x21b778: 97FFFFFA  bl       #0x21b760
//   0x21b77c: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0754_0x21b770(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x21b770ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0de6d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0755 | PC: 0x21b920 | FDE: 0x0de7c8 | Size: 256 bytes
// Khung tháo gỡ #0755 | Địa chỉ PC: 0x21b920 | Địa chỉ FDE: 0x0de7c8 | Kích thước: 256 bytes
//   0x21b920: D00009A8  adrp     x8, #0x351000
//   0x21b924: 9134C108  add      x8, x8, #0xd30
//   0x21b928: 14041006  b        #0x31f940
//   0x21b92c: F9400020  ldr      x0, [x1]
static inline uint64_t fde_func_0755_0x21b920(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x21b920ULL ^ (static_cast<uint64_t>(0xd00009a8ULL) << 13);
    acc = (acc + a1 + 0x9134c108ULL) ^ 0x0de7c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0756 | PC: 0x21bc34 | FDE: 0x0de8d0 | Size: 256 bytes
// Khung tháo gỡ #0756 | Địa chỉ PC: 0x21bc34 | Địa chỉ FDE: 0x0de8d0 | Kích thước: 256 bytes
//   0x21bc34: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x21bc38: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x21bc3c: 94040C9C  bl       #0x31eeac
//   0x21bc40: B40000C1  cbz      x1, #0x21bc58
static inline uint64_t fde_func_0756_0x21bc34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x21bc34ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0de8d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0757 | PC: 0x21bda8 | FDE: 0x0de9d0 | Size: 256 bytes
// Khung tháo gỡ #0757 | Địa chỉ PC: 0x21bda8 | Địa chỉ FDE: 0x0de9d0 | Kích thước: 256 bytes
//   0x21bda8: 39404409  ldrb     w9, [x0, #0x11]
//   0x21bdac: 12000028  and      w8, w1, #1
//   0x21bdb0: 34000169  cbz      w9, #0x21bddc
//   0x21bdb4: 37000141  tbnz     w1, #0, #0x21bddc
static inline uint64_t fde_func_0757_0x21bda8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x21bda8ULL ^ (static_cast<uint64_t>(0x39404409ULL) << 13);
    acc = (acc + a1 + 0x12000028ULL) ^ 0x0de9d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0758 | PC: 0x21d380 | FDE: 0x0deb00 | Size: 256 bytes
// Khung tháo gỡ #0758 | Địa chỉ PC: 0x21d380 | Địa chỉ FDE: 0x0deb00 | Kích thước: 256 bytes
//   0x21d380: AA0003E8  mov      x8, x0
//   0x21d384: F9401C00  ldr      x0, [x0, #0x38]
//   0x21d388: B4000140  cbz      x0, #0x21d3b0
//   0x21d38c: 3900711F  strb     wzr, [x8, #0x1c]
static inline uint64_t fde_func_0758_0x21d380(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x21d380ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xf9401c00ULL) ^ 0x0deb00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0759 | PC: 0x21dd14 | FDE: 0x0dec20 | Size: 256 bytes
// Khung tháo gỡ #0759 | Địa chỉ PC: 0x21dd14 | Địa chỉ FDE: 0x0dec20 | Kích thước: 256 bytes
//   0x21dd14: B900B001  str      w1, [x0, #0xb0]
//   0x21dd18: D65F03C0  ret      
//   0x21dd1c: B940B000  ldr      w0, [x0, #0xb0]
//   0x21dd20: D65F03C0  ret      
static inline uint64_t fde_func_0759_0x21dd14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x21dd14ULL ^ (static_cast<uint64_t>(0xb900b001ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0dec20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0760 | PC: 0x21dff8 | FDE: 0x0ded30 | Size: 256 bytes
// Khung tháo gỡ #0760 | Địa chỉ PC: 0x21dff8 | Địa chỉ FDE: 0x0ded30 | Kích thước: 256 bytes
//   0x21dff8: D10343FF  sub      sp, sp, #0xd0
//   0x21dffc: FD004BE8  str      d8, [sp, #0x90]
//   0x21e000: F9004FF8  str      x24, [sp, #0x98]
//   0x21e004: A90A5BF7  stp      x23, x22, [sp, #0xa0]
static inline uint64_t fde_func_0760_0x21dff8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x21dff8ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xfd004be8ULL) ^ 0x0ded30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0761 | PC: 0x21e8cc | FDE: 0x0dee78 | Size: 256 bytes
// Khung tháo gỡ #0761 | Địa chỉ PC: 0x21e8cc | Địa chỉ FDE: 0x0dee78 | Kích thước: 256 bytes
//   0x21e8cc: D10543FF  sub      sp, sp, #0x150
//   0x21e8d0: FD006BEC  str      d12, [sp, #0xd0]
//   0x21e8d4: 6D0DABEB  stp      d11, d10, [sp, #0xd8]
//   0x21e8d8: 6D0EA3E9  stp      d9, d8, [sp, #0xe8]
static inline uint64_t fde_func_0761_0x21e8cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x21e8ccULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xfd006becULL) ^ 0x0dee78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0762 | PC: 0x21f764 | FDE: 0x0deff8 | Size: 256 bytes
// Khung tháo gỡ #0762 | Địa chỉ PC: 0x21f764 | Địa chỉ FDE: 0x0deff8 | Kích thước: 256 bytes
//   0x21f764: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x21f768: B4000101  cbz      x1, #0x21f788
//   0x21f76c: 39412028  ldrb     w8, [x1, #0x48]
//   0x21f770: 340000E8  cbz      w8, #0x21f78c
static inline uint64_t fde_func_0762_0x21f764(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x21f764ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb4000101ULL) ^ 0x0deff8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0763 | PC: 0x21fac0 | FDE: 0x0df110 | Size: 256 bytes
// Khung tháo gỡ #0763 | Địa chỉ PC: 0x21fac0 | Địa chỉ FDE: 0x0df110 | Kích thước: 256 bytes
//   0x21fac0: F9400028  ldr      x8, [x1]
//   0x21fac4: B9400809  ldr      w9, [x0, #8]
//   0x21fac8: B9006909  str      w9, [x8, #0x68]
//   0x21facc: 39403009  ldrb     w9, [x0, #0xc]
static inline uint64_t fde_func_0763_0x21fac0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x21fac0ULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0xb9400809ULL) ^ 0x0df110ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0764 | PC: 0x220020 | FDE: 0x0df258 | Size: 256 bytes
// Khung tháo gỡ #0764 | Địa chỉ PC: 0x220020 | Địa chỉ FDE: 0x0df258 | Kích thước: 256 bytes
//   0x220020: D10283FF  sub      sp, sp, #0xa0
//   0x220024: FD002BEA  str      d10, [sp, #0x50]
//   0x220028: 6D0623E9  stp      d9, d8, [sp, #0x60]
//   0x22002c: A9075BF7  stp      x23, x22, [sp, #0x70]
static inline uint64_t fde_func_0764_0x220020(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x220020ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xfd002beaULL) ^ 0x0df258ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0765 | PC: 0x220880 | FDE: 0x0df3c0 | Size: 256 bytes
// Khung tháo gỡ #0765 | Địa chỉ PC: 0x220880 | Địa chỉ FDE: 0x0df3c0 | Kích thước: 256 bytes
//   0x220880: D0000988  adrp     x8, #0x352000
//   0x220884: 91040108  add      x8, x8, #0x100
//   0x220888: 1403F1F0  b        #0x31d048
//   0x22088c: F81F0FFE  str      x30, [sp, #-0x10]!
static inline uint64_t fde_func_0765_0x220880(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x220880ULL ^ (static_cast<uint64_t>(0xd0000988ULL) << 13);
    acc = (acc + a1 + 0x91040108ULL) ^ 0x0df3c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0766 | PC: 0x2209ec | FDE: 0x0df4b0 | Size: 256 bytes
// Khung tháo gỡ #0766 | Địa chỉ PC: 0x2209ec | Địa chỉ FDE: 0x0df4b0 | Kích thước: 256 bytes
//   0x2209ec: F9400408  ldr      x8, [x0, #8]
//   0x2209f0: 1E2703E0  fmov     s0, wzr
//   0x2209f4: B40000C8  cbz      x8, #0x220a0c
//   0x2209f8: F9402108  ldr      x8, [x8, #0x40]
static inline uint64_t fde_func_0766_0x2209ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2209ecULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x1e2703e0ULL) ^ 0x0df4b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0767 | PC: 0x220b3c | FDE: 0x0df5b0 | Size: 256 bytes
// Khung tháo gỡ #0767 | Địa chỉ PC: 0x220b3c | Địa chỉ FDE: 0x0df5b0 | Kích thước: 256 bytes
//   0x220b3c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x220b40: F9400408  ldr      x8, [x0, #8]
//   0x220b44: 94046927  bl       #0x33afe0
//   0x220b48: B4000173  cbz      x19, #0x220b74
static inline uint64_t fde_func_0767_0x220b3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x220b3cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400408ULL) ^ 0x0df5b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0768 | PC: 0x220d0c | FDE: 0x0df6b8 | Size: 256 bytes
// Khung tháo gỡ #0768 | Địa chỉ PC: 0x220d0c | Địa chỉ FDE: 0x0df6b8 | Kích thước: 256 bytes
//   0x220d0c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x220d10: AA0003F3  mov      x19, x0
//   0x220d14: 97FFFFEF  bl       #0x220cd0
//   0x220d18: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0768_0x220d0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x220d0cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0df6b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0769 | PC: 0x221654 | FDE: 0x0df810 | Size: 256 bytes
// Khung tháo gỡ #0769 | Địa chỉ PC: 0x221654 | Địa chỉ FDE: 0x0df810 | Kích thước: 256 bytes
//   0x221654: EB01001F  cmp      x0, x1
//   0x221658: 54000160  b.eq     #0x221684
//   0x22165c: 91001008  add      x8, x0, #4
//   0x221660: EB08003F  cmp      x1, x8
static inline uint64_t fde_func_0769_0x221654(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x221654ULL ^ (static_cast<uint64_t>(0xeb01001fULL) << 13);
    acc = (acc + a1 + 0x54000160ULL) ^ 0x0df810ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0770 | PC: 0x221f98 | FDE: 0x0df978 | Size: 256 bytes
// Khung tháo gỡ #0770 | Địa chỉ PC: 0x221f98 | Địa chỉ FDE: 0x0df978 | Kích thước: 256 bytes
//   0x221f98: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x221f9c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x221fa0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x221fa4: EB02003F  cmp      x1, x2
static inline uint64_t fde_func_0770_0x221f98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x221f98ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0df978ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0771 | PC: 0x222458 | FDE: 0x0dfab0 | Size: 256 bytes
// Khung tháo gỡ #0771 | Địa chỉ PC: 0x222458 | Địa chỉ FDE: 0x0dfab0 | Kích thước: 256 bytes
//   0x222458: D10183FF  sub      sp, sp, #0x60
//   0x22245c: A9057BF3  stp      x19, x30, [sp, #0x50]
//   0x222460: 9403ECC0  bl       #0x31d760
//   0x222464: 90000989  adrp     x9, #0x352000
static inline uint64_t fde_func_0771_0x222458(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x222458ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9057bf3ULL) ^ 0x0dfab0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0772 | PC: 0x2226ac | FDE: 0x0dfbc0 | Size: 256 bytes
// Khung tháo gỡ #0772 | Địa chỉ PC: 0x2226ac | Địa chỉ FDE: 0x0dfbc0 | Kích thước: 256 bytes
//   0x2226ac: D101C3FF  sub      sp, sp, #0x70
//   0x2226b0: F90023F6  str      x22, [sp, #0x40]
//   0x2226b4: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x2226b8: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_0772_0x2226ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2226acULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f6ULL) ^ 0x0dfbc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0773 | PC: 0x222ddc | FDE: 0x0dfcf8 | Size: 256 bytes
// Khung tháo gỡ #0773 | Địa chỉ PC: 0x222ddc | Địa chỉ FDE: 0x0dfcf8 | Kích thước: 256 bytes
//   0x222ddc: D10143FF  sub      sp, sp, #0x50
//   0x222de0: F90013F6  str      x22, [sp, #0x20]
//   0x222de4: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x222de8: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0773_0x222ddc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x222ddcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x0dfcf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0774 | PC: 0x223454 | FDE: 0x0dfe40 | Size: 256 bytes
// Khung tháo gỡ #0774 | Địa chỉ PC: 0x223454 | Địa chỉ FDE: 0x0dfe40 | Kích thước: 256 bytes
//   0x223454: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x223458: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x22345c: 3941C408  ldrb     w8, [x0, #0x71]
//   0x223460: 9404359A  bl       #0x330ac8
static inline uint64_t fde_func_0774_0x223454(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x223454ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0dfe40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0775 | PC: 0x223a2c | FDE: 0x0dff90 | Size: 256 bytes
// Khung tháo gỡ #0775 | Địa chỉ PC: 0x223a2c | Địa chỉ FDE: 0x0dff90 | Kích thước: 256 bytes
//   0x223a2c: F9400400  ldr      x0, [x0, #8]
//   0x223a30: 17FFFF77  b        #0x22380c
//   0x223a34: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x223a38: A9017BF3  stp      x19, x30, [sp, #0x10]
static inline uint64_t fde_func_0775_0x223a2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x223a2cULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0x17ffff77ULL) ^ 0x0dff90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0776 | PC: 0x2241dc | FDE: 0x0e00d0 | Size: 256 bytes
// Khung tháo gỡ #0776 | Địa chỉ PC: 0x2241dc | Địa chỉ FDE: 0x0e00d0 | Kích thước: 256 bytes
//   0x2241dc: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x2241e0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x2241e4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x2241e8: 9403E176  bl       #0x31c7c0
static inline uint64_t fde_func_0776_0x2241dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2241dcULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0e00d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0777 | PC: 0x22449c | FDE: 0x0e0200 | Size: 256 bytes
// Khung tháo gỡ #0777 | Địa chỉ PC: 0x22449c | Địa chỉ FDE: 0x0e0200 | Kích thước: 256 bytes
//   0x22449c: D10183FF  sub      sp, sp, #0x60
//   0x2244a0: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x2244a4: A9057BF3  stp      x19, x30, [sp, #0x50]
//   0x2244a8: D53BD055  mrs      x21, tpidr_el0
static inline uint64_t fde_func_0777_0x22449c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x22449cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90453f5ULL) ^ 0x0e0200ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0778 | PC: 0x2249f4 | FDE: 0x0e0340 | Size: 256 bytes
// Khung tháo gỡ #0778 | Địa chỉ PC: 0x2249f4 | Địa chỉ FDE: 0x0e0340 | Kích thước: 256 bytes
//   0x2249f4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x2249f8: 94000193  bl       #0x225044
//   0x2249fc: B4000080  cbz      x0, #0x224a0c
//   0x224a00: 52800021  mov      w1, #1
static inline uint64_t fde_func_0778_0x2249f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2249f4ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x94000193ULL) ^ 0x0e0340ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0779 | PC: 0x224c50 | FDE: 0x0e0430 | Size: 256 bytes
// Khung tháo gỡ #0779 | Địa chỉ PC: 0x224c50 | Địa chỉ FDE: 0x0e0430 | Kích thước: 256 bytes
//   0x224c50: D10083FF  sub      sp, sp, #0x20
//   0x224c54: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x224c58: 9403E48A  bl       #0x31de80
//   0x224c5c: B40000E0  cbz      x0, #0x224c78
static inline uint64_t fde_func_0779_0x224c50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x224c50ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0e0430ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0780 | PC: 0x224f88 | FDE: 0x0e0538 | Size: 80 bytes
// Khung tháo gỡ #0780 | Địa chỉ PC: 0x224f88 | Địa chỉ FDE: 0x0e0538 | Kích thước: 80 bytes
//   0x224f88: D1006000  sub      x0, x0, #0x18
//   0x224f8c: 17FFFE08  b        #0x2247ac
//   0x224f90: D1006000  sub      x0, x0, #0x18
//   0x224f94: 17FFFE53  b        #0x2248e0
static inline uint64_t fde_func_0780_0x224f88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x224f88ULL ^ (static_cast<uint64_t>(0xd1006000ULL) << 13);
    acc = (acc + a1 + 0x17fffe08ULL) ^ 0x0e0538ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0781 | PC: 0x224fd8 | FDE: 0x0e0628 | Size: 80 bytes
// Khung tháo gỡ #0781 | Địa chỉ PC: 0x224fd8 | Địa chỉ FDE: 0x0e0628 | Kích thước: 80 bytes
//   0x224fd8: D1006000  sub      x0, x0, #0x18
//   0x224fdc: 17FFFF7C  b        #0x224dcc
//   0x224fe0: D1006000  sub      x0, x0, #0x18
//   0x224fe4: 17FFFF8F  b        #0x224e20
static inline uint64_t fde_func_0781_0x224fd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x224fd8ULL ^ (static_cast<uint64_t>(0xd1006000ULL) << 13);
    acc = (acc + a1 + 0x17ffff7cULL) ^ 0x0e0628ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0782 | PC: 0x225028 | FDE: 0x0e0718 | Size: 256 bytes
// Khung tháo gỡ #0782 | Địa chỉ PC: 0x225028 | Địa chỉ FDE: 0x0e0718 | Kích thước: 256 bytes
//   0x225028: D1006000  sub      x0, x0, #0x18
//   0x22502c: 17FFFF42  b        #0x224d34
//   0x225030: D1006000  sub      x0, x0, #0x18
//   0x225034: 12000084  and      w4, w4, #1
static inline uint64_t fde_func_0782_0x225028(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x225028ULL ^ (static_cast<uint64_t>(0xd1006000ULL) << 13);
    acc = (acc + a1 + 0x17ffff42ULL) ^ 0x0e0718ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0783 | PC: 0x225364 | FDE: 0x0e0828 | Size: 256 bytes
// Khung tháo gỡ #0783 | Địa chỉ PC: 0x225364 | Địa chỉ FDE: 0x0e0828 | Kích thước: 256 bytes
//   0x225364: D100C3FF  sub      sp, sp, #0x30
//   0x225368: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x22536c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x225370: F9402808  ldr      x8, [x0, #0x50]
static inline uint64_t fde_func_0783_0x225364(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x225364ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0e0828ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0784 | PC: 0x226048 | FDE: 0x0e0970 | Size: 256 bytes
// Khung tháo gỡ #0784 | Địa chỉ PC: 0x226048 | Địa chỉ FDE: 0x0e0970 | Kích thước: 256 bytes
//   0x226048: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x22604c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x226050: 9403E0AB  bl       #0x31e2fc
//   0x226054: 97FFFBFC  bl       #0x225044
static inline uint64_t fde_func_0784_0x226048(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x226048ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0e0970ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0785 | PC: 0x2268bc | FDE: 0x0e0ac8 | Size: 256 bytes
// Khung tháo gỡ #0785 | Địa chỉ PC: 0x2268bc | Địa chỉ FDE: 0x0e0ac8 | Kích thước: 256 bytes
//   0x2268bc: AA1E03E3  mov      x3, x30
//   0x2268c0: 9403D769  bl       #0x31c664
//   0x2268c4: AA0303FE  mov      x30, x3
//   0x2268c8: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0785_0x2268bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2268bcULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x9403d769ULL) ^ 0x0e0ac8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0786 | PC: 0x227618 | FDE: 0x0e0c08 | Size: 256 bytes
// Khung tháo gỡ #0786 | Địa chỉ PC: 0x227618 | Địa chỉ FDE: 0x0e0c08 | Kích thước: 256 bytes
//   0x227618: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x22761c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x227620: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x227624: 2A0203F3  mov      w19, w2
static inline uint64_t fde_func_0786_0x227618(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x227618ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0e0c08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0787 | PC: 0x227be4 | FDE: 0x0e0d40 | Size: 256 bytes
// Khung tháo gỡ #0787 | Địa chỉ PC: 0x227be4 | Địa chỉ FDE: 0x0e0d40 | Kích thước: 256 bytes
//   0x227be4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x227be8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x227bec: 9403D749  bl       #0x31d910
//   0x227bf0: B9400814  ldr      w20, [x0, #8]
static inline uint64_t fde_func_0787_0x227be4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x227be4ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0e0d40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0788 | PC: 0x227fe4 | FDE: 0x0e0e70 | Size: 256 bytes
// Khung tháo gỡ #0788 | Địa chỉ PC: 0x227fe4 | Địa chỉ FDE: 0x0e0e70 | Kích thước: 256 bytes
//   0x227fe4: D10283FF  sub      sp, sp, #0xa0
//   0x227fe8: FD002BE8  str      d8, [sp, #0x50]
//   0x227fec: F9002FFC  str      x28, [sp, #0x58]
//   0x227ff0: A90663F9  stp      x25, x24, [sp, #0x60]
static inline uint64_t fde_func_0788_0x227fe4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x227fe4ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xfd002be8ULL) ^ 0x0e0e70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0789 | PC: 0x2285a0 | FDE: 0x0e0f98 | Size: 256 bytes
// Khung tháo gỡ #0789 | Địa chỉ PC: 0x2285a0 | Địa chỉ FDE: 0x0e0f98 | Kích thước: 256 bytes
//   0x2285a0: F9402800  ldr      x0, [x0, #0x50]
//   0x2285a4: 1403EF1E  b        #0x32421c
//   0x2285a8: 39401008  ldrb     w8, [x0, #4]
//   0x2285ac: 3900141F  strb     wzr, [x0, #5]
static inline uint64_t fde_func_0789_0x2285a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2285a0ULL ^ (static_cast<uint64_t>(0xf9402800ULL) << 13);
    acc = (acc + a1 + 0x1403ef1eULL) ^ 0x0e0f98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0790 | PC: 0x228f3c | FDE: 0x0e10f0 | Size: 256 bytes
// Khung tháo gỡ #0790 | Địa chỉ PC: 0x228f3c | Địa chỉ FDE: 0x0e10f0 | Kích thước: 256 bytes
//   0x228f3c: D10083FF  sub      sp, sp, #0x20
//   0x228f40: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x228f44: 91006013  add      x19, x0, #0x18
//   0x228f48: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0790_0x228f3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x228f3cULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0e10f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0791 | PC: 0x229414 | FDE: 0x0e1238 | Size: 256 bytes
// Khung tháo gỡ #0791 | Địa chỉ PC: 0x229414 | Địa chỉ FDE: 0x0e1238 | Kích thước: 256 bytes
//   0x229414: AA1E03E5  mov      x5, x30
//   0x229418: 9403D071  bl       #0x31d5dc
//   0x22941c: AA0503FE  mov      x30, x5
//   0x229420: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0791_0x229414(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x229414ULL ^ (static_cast<uint64_t>(0xaa1e03e5ULL) << 13);
    acc = (acc + a1 + 0x9403d071ULL) ^ 0x0e1238ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0792 | PC: 0x229884 | FDE: 0x0e1398 | Size: 256 bytes
// Khung tháo gỡ #0792 | Địa chỉ PC: 0x229884 | Địa chỉ FDE: 0x0e1398 | Kích thước: 256 bytes
//   0x229884: D10203FF  sub      sp, sp, #0x80
//   0x229888: F9002BF6  str      x22, [sp, #0x50]
//   0x22988c: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x229890: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0792_0x229884(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x229884ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf6ULL) ^ 0x0e1398ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0793 | PC: 0x22a018 | FDE: 0x0e1500 | Size: 256 bytes
// Khung tháo gỡ #0793 | Địa chỉ PC: 0x22a018 | Địa chỉ FDE: 0x0e1500 | Kích thước: 256 bytes
//   0x22a018: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x22a01c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x22a020: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x22a024: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0793_0x22a018(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x22a018ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0e1500ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0794 | PC: 0x22a254 | FDE: 0x0e1620 | Size: 256 bytes
// Khung tháo gỡ #0794 | Địa chỉ PC: 0x22a254 | Địa chỉ FDE: 0x0e1620 | Kích thước: 256 bytes
//   0x22a254: F9400048  ldr      x8, [x2]
//   0x22a258: AA0203E0  mov      x0, x2
//   0x22a25c: 2A0303E1  mov      w1, w3
//   0x22a260: F9401D02  ldr      x2, [x8, #0x38]
static inline uint64_t fde_func_0794_0x22a254(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x22a254ULL ^ (static_cast<uint64_t>(0xf9400048ULL) << 13);
    acc = (acc + a1 + 0xaa0203e0ULL) ^ 0x0e1620ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0795 | PC: 0x22a408 | FDE: 0x0e1720 | Size: 256 bytes
// Khung tháo gỡ #0795 | Địa chỉ PC: 0x22a408 | Địa chỉ FDE: 0x0e1720 | Kích thước: 256 bytes
//   0x22a408: D10243FF  sub      sp, sp, #0x90
//   0x22a40c: FD0023EA  str      d10, [sp, #0x40]
//   0x22a410: 6D04A3E9  stp      d9, d8, [sp, #0x48]
//   0x22a414: F9002FF8  str      x24, [sp, #0x58]
static inline uint64_t fde_func_0795_0x22a408(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x22a408ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xfd0023eaULL) ^ 0x0e1720ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0796 | PC: 0x22af40 | FDE: 0x0e1898 | Size: 256 bytes
// Khung tháo gỡ #0796 | Địa chỉ PC: 0x22af40 | Địa chỉ FDE: 0x0e1898 | Kích thước: 256 bytes
//   0x22af40: D10443FF  sub      sp, sp, #0x110
//   0x22af44: FD0053E8  str      d8, [sp, #0xa0]
//   0x22af48: A90B6FFC  stp      x28, x27, [sp, #0xb0]
//   0x22af4c: A90C67FA  stp      x26, x25, [sp, #0xc0]
static inline uint64_t fde_func_0796_0x22af40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x22af40ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xfd0053e8ULL) ^ 0x0e1898ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0797 | PC: 0x22ba54 | FDE: 0x0e19b8 | Size: 256 bytes
// Khung tháo gỡ #0797 | Địa chỉ PC: 0x22ba54 | Địa chỉ FDE: 0x0e19b8 | Kích thước: 256 bytes
//   0x22ba54: A941240A  ldp      x10, x9, [x0, #0x10]
//   0x22ba58: D37AE548  lsl      x8, x10, #6
//   0x22ba5c: 9100054A  add      x10, x10, #1
//   0x22ba60: B5000129  cbnz     x9, #0x22ba84
static inline uint64_t fde_func_0797_0x22ba54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x22ba54ULL ^ (static_cast<uint64_t>(0xa941240aULL) << 13);
    acc = (acc + a1 + 0xd37ae548ULL) ^ 0x0e19b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0798 | PC: 0x22bb98 | FDE: 0x0e1a50 | Size: 24 bytes [_ZN4lynx4tasm9Catalyzer23getBoundingClientOriginEPNS0_7ElementE]
// Khung tháo gỡ #0798 | Địa chỉ PC: 0x22bb98 | Địa chỉ FDE: 0x0e1a50 | Kích thước: 24 bytes
//   0x22bb98: F9400409  ldr      x9, [x0, #8]
//   0x22bb9c: B9404821  ldr      w1, [x1, #0x48]
//   0x22bba0: F9400520  ldr      x0, [x9, #8]
//   0x22bba4: F9400009  ldr      x9, [x0]
static inline uint64_t fde_func_0798_0x22bb98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x22bb98ULL ^ (static_cast<uint64_t>(0xf9400409ULL) << 13);
    acc = (acc + a1 + 0xb9404821ULL) ^ 0x0e1a50ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0799 | PC: 0x22bbb0 | FDE: 0x0e1a68 | Size: 24 bytes [_ZN4lynx4tasm9Catalyzer13getWindowSizeEPNS0_7ElementE]
// Khung tháo gỡ #0799 | Địa chỉ PC: 0x22bbb0 | Địa chỉ FDE: 0x0e1a68 | Kích thước: 24 bytes
//   0x22bbb0: F9400409  ldr      x9, [x0, #8]
//   0x22bbb4: B9404821  ldr      w1, [x1, #0x48]
//   0x22bbb8: F9400520  ldr      x0, [x9, #8]
//   0x22bbbc: F9400009  ldr      x9, [x0]
static inline uint64_t fde_func_0799_0x22bbb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x22bbb0ULL ^ (static_cast<uint64_t>(0xf9400409ULL) << 13);
    acc = (acc + a1 + 0xb9404821ULL) ^ 0x0e1a68ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// Shard 2 Dispatcher / Bộ điều phối phân mảnh 2
uint64_t execute_fde_shard_2(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 400: return fde_func_0400_0x1a7288(a0, a1);
        case 401: return fde_func_0401_0x1a77f4(a0, a1);
        case 402: return fde_func_0402_0x1a7954(a0, a1);
        case 403: return fde_func_0403_0x1a7cd8(a0, a1);
        case 404: return fde_func_0404_0x1a84f8(a0, a1);
        case 405: return fde_func_0405_0x1a87f4(a0, a1);
        case 406: return fde_func_0406_0x1a96a4(a0, a1);
        case 407: return fde_func_0407_0x1aa620(a0, a1);
        case 408: return fde_func_0408_0x1aab44(a0, a1);
        case 409: return fde_func_0409_0x1ab70c(a0, a1);
        case 410: return fde_func_0410_0x1abd74(a0, a1);
        case 411: return fde_func_0411_0x1ac4cc(a0, a1);
        case 412: return fde_func_0412_0x1ad154(a0, a1);
        case 413: return fde_func_0413_0x1add10(a0, a1);
        case 414: return fde_func_0414_0x1ae418(a0, a1);
        case 415: return fde_func_0415_0x1aea64(a0, a1);
        case 416: return fde_func_0416_0x1b1960(a0, a1);
        case 417: return fde_func_0417_0x1b23e4(a0, a1);
        case 418: return fde_func_0418_0x1b26b0(a0, a1);
        case 419: return fde_func_0419_0x1b30ec(a0, a1);
        case 420: return fde_func_0420_0x1b35ec(a0, a1);
        case 421: return fde_func_0421_0x1b4278(a0, a1);
        case 422: return fde_func_0422_0x1b468c(a0, a1);
        case 423: return fde_func_0423_0x1b498c(a0, a1);
        case 424: return fde_func_0424_0x1b4d30(a0, a1);
        case 425: return fde_func_0425_0x1b5140(a0, a1);
        case 426: return fde_func_0426_0x1b53a0(a0, a1);
        case 427: return fde_func_0427_0x1b544c(a0, a1);
        case 428: return fde_func_0428_0x1b5548(a0, a1);
        case 429: return fde_func_0429_0x1b55a4(a0, a1);
        case 430: return fde_func_0430_0x1b5950(a0, a1);
        case 431: return fde_func_0431_0x1b5bc8(a0, a1);
        case 432: return fde_func_0432_0x1b5ce4(a0, a1);
        case 433: return fde_func_0433_0x1b5d38(a0, a1);
        case 434: return fde_func_0434_0x1b5f2c(a0, a1);
        case 435: return fde_func_0435_0x1b61b4(a0, a1);
        case 436: return fde_func_0436_0x1b6564(a0, a1);
        case 437: return fde_func_0437_0x1b6cf4(a0, a1);
        case 438: return fde_func_0438_0x1b7148(a0, a1);
        case 439: return fde_func_0439_0x1b77b4(a0, a1);
        case 440: return fde_func_0440_0x1b7d48(a0, a1);
        case 441: return fde_func_0441_0x1b8254(a0, a1);
        case 442: return fde_func_0442_0x1b8e70(a0, a1);
        case 443: return fde_func_0443_0x1ba430(a0, a1);
        case 444: return fde_func_0444_0x1ba898(a0, a1);
        case 445: return fde_func_0445_0x1ba9dc(a0, a1);
        case 446: return fde_func_0446_0x1bad6c(a0, a1);
        case 447: return fde_func_0447_0x1bb09c(a0, a1);
        case 448: return fde_func_0448_0x1bb668(a0, a1);
        case 449: return fde_func_0449_0x1bbb3c(a0, a1);
        case 450: return fde_func_0450_0x1bbff4(a0, a1);
        case 451: return fde_func_0451_0x1bc260(a0, a1);
        case 452: return fde_func_0452_0x1bca50(a0, a1);
        case 453: return fde_func_0453_0x1bd024(a0, a1);
        case 454: return fde_func_0454_0x1bd2c4(a0, a1);
        case 455: return fde_func_0455_0x1bd574(a0, a1);
        case 456: return fde_func_0456_0x1bda08(a0, a1);
        case 457: return fde_func_0457_0x1bdc94(a0, a1);
        case 458: return fde_func_0458_0x1bde60(a0, a1);
        case 459: return fde_func_0459_0x1be0b0(a0, a1);
        case 460: return fde_func_0460_0x1be8bc(a0, a1);
        case 461: return fde_func_0461_0x1bebd0(a0, a1);
        case 462: return fde_func_0462_0x1bed3c(a0, a1);
        case 463: return fde_func_0463_0x1bf72c(a0, a1);
        case 464: return fde_func_0464_0x1bfc04(a0, a1);
        case 465: return fde_func_0465_0x1bfd0c(a0, a1);
        case 466: return fde_func_0466_0x1c00c0(a0, a1);
        case 467: return fde_func_0467_0x1c0364(a0, a1);
        case 468: return fde_func_0468_0x1c0e80(a0, a1);
        case 469: return fde_func_0469_0x1c1144(a0, a1);
        case 470: return fde_func_0470_0x1c1404(a0, a1);
        case 471: return fde_func_0471_0x1c1510(a0, a1);
        case 472: return fde_func_0472_0x1c1570(a0, a1);
        case 473: return fde_func_0473_0x1c1984(a0, a1);
        case 474: return fde_func_0474_0x1c1b88(a0, a1);
        case 475: return fde_func_0475_0x1c1f2c(a0, a1);
        case 476: return fde_func_0476_0x1c221c(a0, a1);
        case 477: return fde_func_0477_0x1c263c(a0, a1);
        case 478: return fde_func_0478_0x1c2a8c(a0, a1);
        case 479: return fde_func_0479_0x1c2efc(a0, a1);
        case 480: return fde_func_0480_0x1c326c(a0, a1);
        case 481: return fde_func_0481_0x1c366c(a0, a1);
        case 482: return fde_func_0482_0x1c3da4(a0, a1);
        case 483: return fde_func_0483_0x1c46dc(a0, a1);
        case 484: return fde_func_0484_0x1c48d8(a0, a1);
        case 485: return fde_func_0485_0x1c4d50(a0, a1);
        case 486: return fde_func_0486_0x1c4f9c(a0, a1);
        case 487: return fde_func_0487_0x1c5264(a0, a1);
        case 488: return fde_func_0488_0x1c55a4(a0, a1);
        case 489: return fde_func_0489_0x1c6294(a0, a1);
        case 490: return fde_func_0490_0x1c6364(a0, a1);
        case 491: return fde_func_0491_0x1c6594(a0, a1);
        case 492: return fde_func_0492_0x1c6854(a0, a1);
        case 493: return fde_func_0493_0x1c6b68(a0, a1);
        case 494: return fde_func_0494_0x1c7084(a0, a1);
        case 495: return fde_func_0495_0x1c7524(a0, a1);
        case 496: return fde_func_0496_0x1c7cb0(a0, a1);
        case 497: return fde_func_0497_0x1c7e78(a0, a1);
        case 498: return fde_func_0498_0x1c8254(a0, a1);
        case 499: return fde_func_0499_0x1c841c(a0, a1);
        case 500: return fde_func_0500_0x1c87b8(a0, a1);
        case 501: return fde_func_0501_0x1c8998(a0, a1);
        case 502: return fde_func_0502_0x1c8de0(a0, a1);
        case 503: return fde_func_0503_0x1c9280(a0, a1);
        case 504: return fde_func_0504_0x1c990c(a0, a1);
        case 505: return fde_func_0505_0x1c9e20(a0, a1);
        case 506: return fde_func_0506_0x1ca078(a0, a1);
        case 507: return fde_func_0507_0x1ca2b8(a0, a1);
        case 508: return fde_func_0508_0x1ca570(a0, a1);
        case 509: return fde_func_0509_0x1cabbc(a0, a1);
        case 510: return fde_func_0510_0x1cb6b4(a0, a1);
        case 511: return fde_func_0511_0x1cc15c(a0, a1);
        case 512: return fde_func_0512_0x1cca08(a0, a1);
        case 513: return fde_func_0513_0x1ccab0(a0, a1);
        case 514: return fde_func_0514_0x1cd244(a0, a1);
        case 515: return fde_func_0515_0x1cd87c(a0, a1);
        case 516: return fde_func_0516_0x1cdca0(a0, a1);
        case 517: return fde_func_0517_0x1ce0c8(a0, a1);
        case 518: return fde_func_0518_0x1cea44(a0, a1);
        case 519: return fde_func_0519_0x1cee40(a0, a1);
        case 520: return fde_func_0520_0x1cf5ec(a0, a1);
        case 521: return fde_func_0521_0x1cfa64(a0, a1);
        case 522: return fde_func_0522_0x1d0084(a0, a1);
        case 523: return fde_func_0523_0x1d0594(a0, a1);
        case 524: return fde_func_0524_0x1d0708(a0, a1);
        case 525: return fde_func_0525_0x1d0938(a0, a1);
        case 526: return fde_func_0526_0x1d0be8(a0, a1);
        case 527: return fde_func_0527_0x1d1554(a0, a1);
        case 528: return fde_func_0528_0x1d1cd0(a0, a1);
        case 529: return fde_func_0529_0x1d1f9c(a0, a1);
        case 530: return fde_func_0530_0x1d24f8(a0, a1);
        case 531: return fde_func_0531_0x1d2ec0(a0, a1);
        case 532: return fde_func_0532_0x1d31fc(a0, a1);
        case 533: return fde_func_0533_0x1d371c(a0, a1);
        case 534: return fde_func_0534_0x1d4144(a0, a1);
        case 535: return fde_func_0535_0x1d47f4(a0, a1);
        case 536: return fde_func_0536_0x1d4ad4(a0, a1);
        case 537: return fde_func_0537_0x1d5164(a0, a1);
        case 538: return fde_func_0538_0x1d59c4(a0, a1);
        case 539: return fde_func_0539_0x1d5d34(a0, a1);
        case 540: return fde_func_0540_0x1d61ac(a0, a1);
        case 541: return fde_func_0541_0x1d6658(a0, a1);
        case 542: return fde_func_0542_0x1d6d9c(a0, a1);
        case 543: return fde_func_0543_0x1d74b4(a0, a1);
        case 544: return fde_func_0544_0x1d75d4(a0, a1);
        case 545: return fde_func_0545_0x1d77b0(a0, a1);
        case 546: return fde_func_0546_0x1d7d18(a0, a1);
        case 547: return fde_func_0547_0x1d7fc8(a0, a1);
        case 548: return fde_func_0548_0x1d92b4(a0, a1);
        case 549: return fde_func_0549_0x1d98f8(a0, a1);
        case 550: return fde_func_0550_0x1da014(a0, a1);
        case 551: return fde_func_0551_0x1da674(a0, a1);
        case 552: return fde_func_0552_0x1da9d8(a0, a1);
        case 553: return fde_func_0553_0x1db0a0(a0, a1);
        case 554: return fde_func_0554_0x1db5e8(a0, a1);
        case 555: return fde_func_0555_0x1dbe40(a0, a1);
        case 556: return fde_func_0556_0x1dc184(a0, a1);
        case 557: return fde_func_0557_0x1dd104(a0, a1);
        case 558: return fde_func_0558_0x1dd68c(a0, a1);
        case 559: return fde_func_0559_0x1de564(a0, a1);
        case 560: return fde_func_0560_0x1dee58(a0, a1);
        case 561: return fde_func_0561_0x1df0d8(a0, a1);
        case 562: return fde_func_0562_0x1df458(a0, a1);
        case 563: return fde_func_0563_0x1df908(a0, a1);
        case 564: return fde_func_0564_0x1dfe84(a0, a1);
        case 565: return fde_func_0565_0x1e0364(a0, a1);
        case 566: return fde_func_0566_0x1e0804(a0, a1);
        case 567: return fde_func_0567_0x1e1008(a0, a1);
        case 568: return fde_func_0568_0x1e1434(a0, a1);
        case 569: return fde_func_0569_0x1e2200(a0, a1);
        case 570: return fde_func_0570_0x1e26a8(a0, a1);
        case 571: return fde_func_0571_0x1e2a78(a0, a1);
        case 572: return fde_func_0572_0x1e2c58(a0, a1);
        case 573: return fde_func_0573_0x1e2da4(a0, a1);
        case 574: return fde_func_0574_0x1e3084(a0, a1);
        case 575: return fde_func_0575_0x1e399c(a0, a1);
        case 576: return fde_func_0576_0x1e45cc(a0, a1);
        case 577: return fde_func_0577_0x1e4da8(a0, a1);
        case 578: return fde_func_0578_0x1e56cc(a0, a1);
        case 579: return fde_func_0579_0x1e5fac(a0, a1);
        case 580: return fde_func_0580_0x1e64c8(a0, a1);
        case 581: return fde_func_0581_0x1e68b0(a0, a1);
        case 582: return fde_func_0582_0x1e6e34(a0, a1);
        case 583: return fde_func_0583_0x1e73a4(a0, a1);
        case 584: return fde_func_0584_0x1e75a4(a0, a1);
        case 585: return fde_func_0585_0x1e7cb0(a0, a1);
        case 586: return fde_func_0586_0x1e8474(a0, a1);
        case 587: return fde_func_0587_0x1e89c8(a0, a1);
        case 588: return fde_func_0588_0x1e8a88(a0, a1);
        case 589: return fde_func_0589_0x1e8f68(a0, a1);
        case 590: return fde_func_0590_0x1e8f94(a0, a1);
        case 591: return fde_func_0591_0x1e94d4(a0, a1);
        case 592: return fde_func_0592_0x1e9864(a0, a1);
        case 593: return fde_func_0593_0x1e9f08(a0, a1);
        case 594: return fde_func_0594_0x1ea100(a0, a1);
        case 595: return fde_func_0595_0x1ea684(a0, a1);
        case 596: return fde_func_0596_0x1eabec(a0, a1);
        case 597: return fde_func_0597_0x1eb7dc(a0, a1);
        case 598: return fde_func_0598_0x1ebc3c(a0, a1);
        case 599: return fde_func_0599_0x1ebee8(a0, a1);
        case 600: return fde_func_0600_0x1ec3c0(a0, a1);
        case 601: return fde_func_0601_0x1ecf64(a0, a1);
        case 602: return fde_func_0602_0x1ed25c(a0, a1);
        case 603: return fde_func_0603_0x1ed35c(a0, a1);
        case 604: return fde_func_0604_0x1ed5f4(a0, a1);
        case 605: return fde_func_0605_0x1edee4(a0, a1);
        case 606: return fde_func_0606_0x1ee0d4(a0, a1);
        case 607: return fde_func_0607_0x1ee350(a0, a1);
        case 608: return fde_func_0608_0x1ee384(a0, a1);
        case 609: return fde_func_0609_0x1eee7c(a0, a1);
        case 610: return fde_func_0610_0x1ef08c(a0, a1);
        case 611: return fde_func_0611_0x1ef348(a0, a1);
        case 612: return fde_func_0612_0x1ef720(a0, a1);
        case 613: return fde_func_0613_0x1efd6c(a0, a1);
        case 614: return fde_func_0614_0x1f0a84(a0, a1);
        case 615: return fde_func_0615_0x1f197c(a0, a1);
        case 616: return fde_func_0616_0x1f2028(a0, a1);
        case 617: return fde_func_0617_0x1f2414(a0, a1);
        case 618: return fde_func_0618_0x1f325c(a0, a1);
        case 619: return fde_func_0619_0x1f3bd8(a0, a1);
        case 620: return fde_func_0620_0x1f3e48(a0, a1);
        case 621: return fde_func_0621_0x1f4034(a0, a1);
        case 622: return fde_func_0622_0x1f423c(a0, a1);
        case 623: return fde_func_0623_0x1f45c8(a0, a1);
        case 624: return fde_func_0624_0x1f4738(a0, a1);
        case 625: return fde_func_0625_0x1f49e4(a0, a1);
        case 626: return fde_func_0626_0x1f4a2c(a0, a1);
        case 627: return fde_func_0627_0x1f4a74(a0, a1);
        case 628: return fde_func_0628_0x1f4adc(a0, a1);
        case 629: return fde_func_0629_0x1f4b28(a0, a1);
        case 630: return fde_func_0630_0x1f4e50(a0, a1);
        case 631: return fde_func_0631_0x1f5420(a0, a1);
        case 632: return fde_func_0632_0x1f5818(a0, a1);
        case 633: return fde_func_0633_0x1f5b50(a0, a1);
        case 634: return fde_func_0634_0x1f5b70(a0, a1);
        case 635: return fde_func_0635_0x1f5bac(a0, a1);
        case 636: return fde_func_0636_0x1f5f30(a0, a1);
        case 637: return fde_func_0637_0x1f660c(a0, a1);
        case 638: return fde_func_0638_0x1f7030(a0, a1);
        case 639: return fde_func_0639_0x1f7214(a0, a1);
        case 640: return fde_func_0640_0x1f770c(a0, a1);
        case 641: return fde_func_0641_0x1f7cd8(a0, a1);
        case 642: return fde_func_0642_0x1f8c14(a0, a1);
        case 643: return fde_func_0643_0x1f991c(a0, a1);
        case 644: return fde_func_0644_0x1fa5cc(a0, a1);
        case 645: return fde_func_0645_0x1fb3bc(a0, a1);
        case 646: return fde_func_0646_0x1fcb1c(a0, a1);
        case 647: return fde_func_0647_0x1fd5c0(a0, a1);
        case 648: return fde_func_0648_0x1fdb34(a0, a1);
        case 649: return fde_func_0649_0x1fe1d4(a0, a1);
        case 650: return fde_func_0650_0x1fe4f4(a0, a1);
        case 651: return fde_func_0651_0x1fe8cc(a0, a1);
        case 652: return fde_func_0652_0x1fee38(a0, a1);
        case 653: return fde_func_0653_0x1ff158(a0, a1);
        case 654: return fde_func_0654_0x1ff440(a0, a1);
        case 655: return fde_func_0655_0x1ff850(a0, a1);
        case 656: return fde_func_0656_0x1ff9d8(a0, a1);
        case 657: return fde_func_0657_0x1ffc38(a0, a1);
        case 658: return fde_func_0658_0x20012c(a0, a1);
        case 659: return fde_func_0659_0x20045c(a0, a1);
        case 660: return fde_func_0660_0x200c88(a0, a1);
        case 661: return fde_func_0661_0x200d04(a0, a1);
        case 662: return fde_func_0662_0x200d34(a0, a1);
        case 663: return fde_func_0663_0x200d64(a0, a1);
        case 664: return fde_func_0664_0x200d6c(a0, a1);
        case 665: return fde_func_0665_0x201494(a0, a1);
        case 666: return fde_func_0666_0x202c90(a0, a1);
        case 667: return fde_func_0667_0x203004(a0, a1);
        case 668: return fde_func_0668_0x2032e0(a0, a1);
        case 669: return fde_func_0669_0x20448c(a0, a1);
        case 670: return fde_func_0670_0x2062d4(a0, a1);
        case 671: return fde_func_0671_0x207948(a0, a1);
        case 672: return fde_func_0672_0x208140(a0, a1);
        case 673: return fde_func_0673_0x20872c(a0, a1);
        case 674: return fde_func_0674_0x208ecc(a0, a1);
        case 675: return fde_func_0675_0x209cf0(a0, a1);
        case 676: return fde_func_0676_0x209ecc(a0, a1);
        case 677: return fde_func_0677_0x209f7c(a0, a1);
        case 678: return fde_func_0678_0x209f84(a0, a1);
        case 679: return fde_func_0679_0x209f8c(a0, a1);
        case 680: return fde_func_0680_0x209f94(a0, a1);
        case 681: return fde_func_0681_0x20a528(a0, a1);
        case 682: return fde_func_0682_0x20a570(a0, a1);
        case 683: return fde_func_0683_0x20a57c(a0, a1);
        case 684: return fde_func_0684_0x20a588(a0, a1);
        case 685: return fde_func_0685_0x20a594(a0, a1);
        case 686: return fde_func_0686_0x20a6ac(a0, a1);
        case 687: return fde_func_0687_0x20a6b4(a0, a1);
        case 688: return fde_func_0688_0x20a6bc(a0, a1);
        case 689: return fde_func_0689_0x20a6c4(a0, a1);
        case 690: return fde_func_0690_0x20a6cc(a0, a1);
        case 691: return fde_func_0691_0x20a6d4(a0, a1);
        case 692: return fde_func_0692_0x20a6dc(a0, a1);
        case 693: return fde_func_0693_0x20a6e4(a0, a1);
        case 694: return fde_func_0694_0x20a6ec(a0, a1);
        case 695: return fde_func_0695_0x20a880(a0, a1);
        case 696: return fde_func_0696_0x20a9d0(a0, a1);
        case 697: return fde_func_0697_0x20aa44(a0, a1);
        case 698: return fde_func_0698_0x20abdc(a0, a1);
        case 699: return fde_func_0699_0x20ad4c(a0, a1);
        case 700: return fde_func_0700_0x20b124(a0, a1);
        case 701: return fde_func_0701_0x20b168(a0, a1);
        case 702: return fde_func_0702_0x20babc(a0, a1);
        case 703: return fde_func_0703_0x20c46c(a0, a1);
        case 704: return fde_func_0704_0x20cc34(a0, a1);
        case 705: return fde_func_0705_0x20d524(a0, a1);
        case 706: return fde_func_0706_0x20d698(a0, a1);
        case 707: return fde_func_0707_0x20de40(a0, a1);
        case 708: return fde_func_0708_0x20e7bc(a0, a1);
        case 709: return fde_func_0709_0x20ea04(a0, a1);
        case 710: return fde_func_0710_0x20ef94(a0, a1);
        case 711: return fde_func_0711_0x20f0b4(a0, a1);
        case 712: return fde_func_0712_0x20f18c(a0, a1);
        case 713: return fde_func_0713_0x20f208(a0, a1);
        case 714: return fde_func_0714_0x20f2f0(a0, a1);
        case 715: return fde_func_0715_0x20f3d8(a0, a1);
        case 716: return fde_func_0716_0x20f660(a0, a1);
        case 717: return fde_func_0717_0x20f760(a0, a1);
        case 718: return fde_func_0718_0x20f99c(a0, a1);
        case 719: return fde_func_0719_0x20f9ec(a0, a1);
        case 720: return fde_func_0720_0x20fa00(a0, a1);
        case 721: return fde_func_0721_0x20fa08(a0, a1);
        case 722: return fde_func_0722_0x20fa1c(a0, a1);
        case 723: return fde_func_0723_0x20fa34(a0, a1);
        case 724: return fde_func_0724_0x20fa5c(a0, a1);
        case 725: return fde_func_0725_0x20febc(a0, a1);
        case 726: return fde_func_0726_0x210768(a0, a1);
        case 727: return fde_func_0727_0x210bc0(a0, a1);
        case 728: return fde_func_0728_0x210db8(a0, a1);
        case 729: return fde_func_0729_0x2111b4(a0, a1);
        case 730: return fde_func_0730_0x211958(a0, a1);
        case 731: return fde_func_0731_0x212948(a0, a1);
        case 732: return fde_func_0732_0x2134c4(a0, a1);
        case 733: return fde_func_0733_0x213b4c(a0, a1);
        case 734: return fde_func_0734_0x214074(a0, a1);
        case 735: return fde_func_0735_0x214e7c(a0, a1);
        case 736: return fde_func_0736_0x215188(a0, a1);
        case 737: return fde_func_0737_0x2153ac(a0, a1);
        case 738: return fde_func_0738_0x215520(a0, a1);
        case 739: return fde_func_0739_0x215fe8(a0, a1);
        case 740: return fde_func_0740_0x216144(a0, a1);
        case 741: return fde_func_0741_0x216bf0(a0, a1);
        case 742: return fde_func_0742_0x216fa4(a0, a1);
        case 743: return fde_func_0743_0x2177e0(a0, a1);
        case 744: return fde_func_0744_0x217e8c(a0, a1);
        case 745: return fde_func_0745_0x2181c0(a0, a1);
        case 746: return fde_func_0746_0x2184d4(a0, a1);
        case 747: return fde_func_0747_0x218ccc(a0, a1);
        case 748: return fde_func_0748_0x219354(a0, a1);
        case 749: return fde_func_0749_0x219804(a0, a1);
        case 750: return fde_func_0750_0x219cb4(a0, a1);
        case 751: return fde_func_0751_0x21a0d4(a0, a1);
        case 752: return fde_func_0752_0x21a324(a0, a1);
        case 753: return fde_func_0753_0x21a5a0(a0, a1);
        case 754: return fde_func_0754_0x21b770(a0, a1);
        case 755: return fde_func_0755_0x21b920(a0, a1);
        case 756: return fde_func_0756_0x21bc34(a0, a1);
        case 757: return fde_func_0757_0x21bda8(a0, a1);
        case 758: return fde_func_0758_0x21d380(a0, a1);
        case 759: return fde_func_0759_0x21dd14(a0, a1);
        case 760: return fde_func_0760_0x21dff8(a0, a1);
        case 761: return fde_func_0761_0x21e8cc(a0, a1);
        case 762: return fde_func_0762_0x21f764(a0, a1);
        case 763: return fde_func_0763_0x21fac0(a0, a1);
        case 764: return fde_func_0764_0x220020(a0, a1);
        case 765: return fde_func_0765_0x220880(a0, a1);
        case 766: return fde_func_0766_0x2209ec(a0, a1);
        case 767: return fde_func_0767_0x220b3c(a0, a1);
        case 768: return fde_func_0768_0x220d0c(a0, a1);
        case 769: return fde_func_0769_0x221654(a0, a1);
        case 770: return fde_func_0770_0x221f98(a0, a1);
        case 771: return fde_func_0771_0x222458(a0, a1);
        case 772: return fde_func_0772_0x2226ac(a0, a1);
        case 773: return fde_func_0773_0x222ddc(a0, a1);
        case 774: return fde_func_0774_0x223454(a0, a1);
        case 775: return fde_func_0775_0x223a2c(a0, a1);
        case 776: return fde_func_0776_0x2241dc(a0, a1);
        case 777: return fde_func_0777_0x22449c(a0, a1);
        case 778: return fde_func_0778_0x2249f4(a0, a1);
        case 779: return fde_func_0779_0x224c50(a0, a1);
        case 780: return fde_func_0780_0x224f88(a0, a1);
        case 781: return fde_func_0781_0x224fd8(a0, a1);
        case 782: return fde_func_0782_0x225028(a0, a1);
        case 783: return fde_func_0783_0x225364(a0, a1);
        case 784: return fde_func_0784_0x226048(a0, a1);
        case 785: return fde_func_0785_0x2268bc(a0, a1);
        case 786: return fde_func_0786_0x227618(a0, a1);
        case 787: return fde_func_0787_0x227be4(a0, a1);
        case 788: return fde_func_0788_0x227fe4(a0, a1);
        case 789: return fde_func_0789_0x2285a0(a0, a1);
        case 790: return fde_func_0790_0x228f3c(a0, a1);
        case 791: return fde_func_0791_0x229414(a0, a1);
        case 792: return fde_func_0792_0x229884(a0, a1);
        case 793: return fde_func_0793_0x22a018(a0, a1);
        case 794: return fde_func_0794_0x22a254(a0, a1);
        case 795: return fde_func_0795_0x22a408(a0, a1);
        case 796: return fde_func_0796_0x22af40(a0, a1);
        case 797: return fde_func_0797_0x22ba54(a0, a1);
        case 798: return fde_func_0798_0x22bb98(a0, a1);
        case 799: return fde_func_0799_0x22bbb0(a0, a1);
        default: return 0ULL;
    }
}

} // namespace lynx