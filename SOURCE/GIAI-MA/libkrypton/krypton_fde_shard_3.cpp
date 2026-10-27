// ============================================================================
// Clean-Room C++17 AArch64 Function Shard 3/5 for libkrypton.so
// Phân mảnh Hàm AArch64 C++17 sạch 3/5 cho libkrypton.so
// Covers representative FDE indices [800 .. 1199] out of 9,255 total FDEs
// Bao phủ chỉ số FDE đại diện [800 .. 1199] trên tổng số 9.255 FDE
// ============================================================================
#include "krypton_core.h"

namespace lynx {
namespace canvas {

// FDE #0800 | PC: 0x100994 | FDE: 0x07cf68 | Size: 256 bytes
// Khung tháo gỡ #0800 | Địa chỉ PC: 0x100994 | Địa chỉ FDE: 0x07cf68 | Kích thước: 256 bytes
//   0x100994: AA1E03E8  mov      x8, x30
//   0x100998: 9401D7D9  bl       #0x1768fc
//   0x10099c: AA0803FE  mov      x30, x8
//   0x1009a0: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0800_0x100994(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x100994ULL ^ (static_cast<uint64_t>(0xaa1e03e8ULL) << 13);
    acc = (acc + a1 + 0x9401d7d9ULL) ^ 0x07cf68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0801 | PC: 0x100c58 | FDE: 0x07cff0 | Size: 256 bytes
// Khung tháo gỡ #0801 | Địa chỉ PC: 0x100c58 | Địa chỉ FDE: 0x07cff0 | Kích thước: 256 bytes
//   0x100c58: AA1E03E8  mov      x8, x30
//   0x100c5c: 9401EA34  bl       #0x17b52c
//   0x100c60: AA0803FE  mov      x30, x8
//   0x100c64: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_0801_0x100c58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x100c58ULL ^ (static_cast<uint64_t>(0xaa1e03e8ULL) << 13);
    acc = (acc + a1 + 0x9401ea34ULL) ^ 0x07cff0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0802 | PC: 0x101080 | FDE: 0x07d080 | Size: 256 bytes
// Khung tháo gỡ #0802 | Địa chỉ PC: 0x101080 | Địa chỉ FDE: 0x07d080 | Kích thước: 256 bytes
//   0x101080: 12904508  mov      w8, #-0x8229
//   0x101084: 0B080008  add      w8, w0, w8
//   0x101088: 71004D1F  cmp      w8, #0x13
//   0x10108c: 54000689  b.ls     #0x10115c
static inline uint64_t fde_func_0802_0x101080(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101080ULL ^ (static_cast<uint64_t>(0x12904508ULL) << 13);
    acc = (acc + a1 + 0x0b080008ULL) ^ 0x07d080ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0803 | PC: 0x1015d0 | FDE: 0x07d100 | Size: 256 bytes
// Khung tháo gỡ #0803 | Địa chỉ PC: 0x1015d0 | Địa chỉ FDE: 0x07d100 | Kích thước: 256 bytes
//   0x1015d0: 91002008  add      x8, x0, #8
//   0x1015d4: AA0803E9  mov      x9, x8
//   0x1015d8: AA0803E0  mov      x0, x8
//   0x1015dc: F940012A  ldr      x10, [x9]
static inline uint64_t fde_func_0803_0x1015d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1015d0ULL ^ (static_cast<uint64_t>(0x91002008ULL) << 13);
    acc = (acc + a1 + 0xaa0803e9ULL) ^ 0x07d100ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0804 | PC: 0x101848 | FDE: 0x07d180 | Size: 256 bytes
// Khung tháo gỡ #0804 | Địa chỉ PC: 0x101848 | Địa chỉ FDE: 0x07d180 | Kích thước: 256 bytes
//   0x101848: D10183FF  sub      sp, sp, #0x60
//   0x10184c: F90023F4  str      x20, [sp, #0x40]
//   0x101850: A9057BF3  stp      x19, x30, [sp, #0x50]
//   0x101854: 9401D251  bl       #0x176198
static inline uint64_t fde_func_0804_0x101848(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101848ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90023f4ULL) ^ 0x07d180ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0805 | PC: 0x1019b0 | FDE: 0x07d1f8 | Size: 256 bytes
// Khung tháo gỡ #0805 | Địa chỉ PC: 0x1019b0 | Địa chỉ FDE: 0x07d1f8 | Kích thước: 256 bytes
//   0x1019b0: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1019b4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1019b8: AA0003F3  mov      x19, x0
//   0x1019bc: 94020BD1  bl       #0x184900
static inline uint64_t fde_func_0805_0x1019b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1019b0ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x07d1f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0806 | PC: 0x101b34 | FDE: 0x07d280 | Size: 256 bytes
// Khung tháo gỡ #0806 | Địa chỉ PC: 0x101b34 | Địa chỉ FDE: 0x07d280 | Kích thước: 256 bytes
//   0x101b34: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x101b38: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x101b3c: B4000341  cbz      x1, #0x101ba4
//   0x101b40: F9400028  ldr      x8, [x1]
static inline uint64_t fde_func_0806_0x101b34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101b34ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x07d280ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0807 | PC: 0x101d30 | FDE: 0x07d2f8 | Size: 256 bytes
// Khung tháo gỡ #0807 | Địa chỉ PC: 0x101d30 | Địa chỉ FDE: 0x07d2f8 | Kích thước: 256 bytes
//   0x101d30: D10103FF  sub      sp, sp, #0x40
//   0x101d34: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x101d38: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x101d3c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0807_0x101d30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101d30ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x07d2f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0808 | PC: 0x101efc | FDE: 0x07d368 | Size: 256 bytes
// Khung tháo gỡ #0808 | Địa chỉ PC: 0x101efc | Địa chỉ FDE: 0x07d368 | Kích thước: 256 bytes
//   0x101efc: D100C3FF  sub      sp, sp, #0x30
//   0x101f00: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x101f04: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x101f08: F942E815  ldr      x21, [x0, #0x5d0]
static inline uint64_t fde_func_0808_0x101efc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x101efcULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x07d368ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0809 | PC: 0x102068 | FDE: 0x07d3d8 | Size: 256 bytes
// Khung tháo gỡ #0809 | Địa chỉ PC: 0x102068 | Địa chỉ FDE: 0x07d3d8 | Kích thước: 256 bytes
//   0x102068: D100C3FF  sub      sp, sp, #0x30
//   0x10206c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x102070: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x102074: 2A0103F3  mov      w19, w1
static inline uint64_t fde_func_0809_0x102068(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x102068ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x07d3d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0810 | PC: 0x1025d8 | FDE: 0x07d460 | Size: 256 bytes
// Khung tháo gỡ #0810 | Địa chỉ PC: 0x1025d8 | Địa chỉ FDE: 0x07d460 | Kích thước: 256 bytes
//   0x1025d8: D10143FF  sub      sp, sp, #0x50
//   0x1025dc: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x1025e0: 9401D0CD  bl       #0x176914
//   0x1025e4: 910003E0  mov      x0, sp
static inline uint64_t fde_func_0810_0x1025d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1025d8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9047bf3ULL) ^ 0x07d460ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0811 | PC: 0x1027fc | FDE: 0x07d4d8 | Size: 256 bytes
// Khung tháo gỡ #0811 | Địa chỉ PC: 0x1027fc | Địa chỉ FDE: 0x07d4d8 | Kích thước: 256 bytes
//   0x1027fc: AA1E03E5  mov      x5, x30
//   0x102800: 9401D6C3  bl       #0x17830c
//   0x102804: AA0503FE  mov      x30, x5
//   0x102808: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_0811_0x1027fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1027fcULL ^ (static_cast<uint64_t>(0xaa1e03e5ULL) << 13);
    acc = (acc + a1 + 0x9401d6c3ULL) ^ 0x07d4d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0812 | PC: 0x102b14 | FDE: 0x07d560 | Size: 256 bytes
// Khung tháo gỡ #0812 | Địa chỉ PC: 0x102b14 | Địa chỉ FDE: 0x07d560 | Kích thước: 256 bytes
//   0x102b14: D100C3FF  sub      sp, sp, #0x30
//   0x102b18: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x102b1c: 9401CF7E  bl       #0x176914
//   0x102b20: D0FFF961  adrp     x1, #0x30000
static inline uint64_t fde_func_0812_0x102b14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x102b14ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9027bf3ULL) ^ 0x07d560ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0813 | PC: 0x102d54 | FDE: 0x07d5d8 | Size: 256 bytes
// Khung tháo gỡ #0813 | Địa chỉ PC: 0x102d54 | Địa chỉ FDE: 0x07d5d8 | Kích thước: 256 bytes
//   0x102d54: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x102d58: F9400808  ldr      x8, [x0, #0x10]
//   0x102d5c: B4000068  cbz      x8, #0x102d68
//   0x102d60: B9400103  ldr      w3, [x8]
static inline uint64_t fde_func_0813_0x102d54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x102d54ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400808ULL) ^ 0x07d5d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0814 | PC: 0x102f5c | FDE: 0x07d650 | Size: 256 bytes
// Khung tháo gỡ #0814 | Địa chỉ PC: 0x102f5c | Địa chỉ FDE: 0x07d650 | Kích thước: 256 bytes
//   0x102f5c: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x102f60: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x102f64: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x102f68: D0FFF976  adrp     x22, #0x30000
static inline uint64_t fde_func_0814_0x102f5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x102f5cULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x07d650ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0815 | PC: 0x1031a0 | FDE: 0x07d6c8 | Size: 256 bytes
// Khung tháo gỡ #0815 | Địa chỉ PC: 0x1031a0 | Địa chỉ FDE: 0x07d6c8 | Kích thước: 256 bytes
//   0x1031a0: D10103FF  sub      sp, sp, #0x40
//   0x1031a4: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1031a8: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x1031ac: B9404014  ldr      w20, [x0, #0x40]
static inline uint64_t fde_func_0815_0x1031a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1031a0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x07d6c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0816 | PC: 0x10337c | FDE: 0x07d738 | Size: 256 bytes
// Khung tháo gỡ #0816 | Địa chỉ PC: 0x10337c | Địa chỉ FDE: 0x07d738 | Kích thước: 256 bytes
//   0x10337c: AA1E03E4  mov      x4, x30
//   0x103380: 9401EEBD  bl       #0x17ee74
//   0x103384: AA0403FE  mov      x30, x4
//   0x103388: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0816_0x10337c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10337cULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x9401eebdULL) ^ 0x07d738ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0817 | PC: 0x1037b4 | FDE: 0x07d7c0 | Size: 256 bytes
// Khung tháo gỡ #0817 | Địa chỉ PC: 0x1037b4 | Địa chỉ FDE: 0x07d7c0 | Kích thước: 256 bytes
//   0x1037b4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1037b8: 9401DB0A  bl       #0x17a3e0
//   0x1037bc: 94021751  bl       #0x189500
//   0x1037c0: 52800200  mov      w0, #0x10
static inline uint64_t fde_func_0817_0x1037b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1037b4ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x9401db0aULL) ^ 0x07d7c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0818 | PC: 0x1038bc | FDE: 0x07d828 | Size: 256 bytes
// Khung tháo gỡ #0818 | Địa chỉ PC: 0x1038bc | Địa chỉ FDE: 0x07d828 | Kích thước: 256 bytes
//   0x1038bc: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1038c0: 712D103F  cmp      w1, #0xb44
//   0x1038c4: 540002C0  b.eq     #0x10391c
//   0x1038c8: 712DC43F  cmp      w1, #0xb71
static inline uint64_t fde_func_0818_0x1038bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1038bcULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x712d103fULL) ^ 0x07d828ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0819 | PC: 0x1039fc | FDE: 0x07d888 | Size: 256 bytes
// Khung tháo gỡ #0819 | Địa chỉ PC: 0x1039fc | Địa chỉ FDE: 0x07d888 | Kích thước: 256 bytes
//   0x1039fc: 1E202008  fcmp     s0, #0.0
//   0x103a00: 540000EC  b.gt     #0x103a1c
//   0x103a04: D0FFF962  adrp     x2, #0x31000
//   0x103a08: D0FFF963  adrp     x3, #0x31000
static inline uint64_t fde_func_0819_0x1039fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1039fcULL ^ (static_cast<uint64_t>(0x1e202008ULL) << 13);
    acc = (acc + a1 + 0x540000ecULL) ^ 0x07d888ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0820 | PC: 0x103c68 | FDE: 0x07d900 | Size: 256 bytes
// Khung tháo gỡ #0820 | Địa chỉ PC: 0x103c68 | Địa chỉ FDE: 0x07d900 | Kích thước: 256 bytes
//   0x103c68: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x103c6c: 2D400400  ldp      s0, s1, [x0]
//   0x103c70: 940214B8  bl       #0x188f50
//   0x103c74: 52800100  mov      w0, #8
static inline uint64_t fde_func_0820_0x103c68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x103c68ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x2d400400ULL) ^ 0x07d900ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0821 | PC: 0x10423c | FDE: 0x07d990 | Size: 256 bytes
// Khung tháo gỡ #0821 | Địa chỉ PC: 0x10423c | Địa chỉ FDE: 0x07d990 | Kích thước: 256 bytes
//   0x10423c: D10183FF  sub      sp, sp, #0x60
//   0x104240: F90023F4  str      x20, [sp, #0x40]
//   0x104244: A9057BF3  stp      x19, x30, [sp, #0x50]
//   0x104248: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0821_0x10423c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10423cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90023f4ULL) ^ 0x07d990ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0822 | PC: 0x104424 | FDE: 0x07da08 | Size: 256 bytes
// Khung tháo gỡ #0822 | Địa chỉ PC: 0x104424 | Địa chỉ FDE: 0x07da08 | Kích thước: 256 bytes
//   0x104424: 2A030088  orr      w8, w4, w3
//   0x104428: 37F80308  tbnz     w8, #0x1f, #0x104488
//   0x10442c: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x104430: A9015BF7  stp      x23, x22, [sp, #0x10]
static inline uint64_t fde_func_0822_0x104424(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x104424ULL ^ (static_cast<uint64_t>(0x2a030088ULL) << 13);
    acc = (acc + a1 + 0x37f80308ULL) ^ 0x07da08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0823 | PC: 0x10465c | FDE: 0x07da90 | Size: 248 bytes
// Khung tháo gỡ #0823 | Địa chỉ PC: 0x10465c | Địa chỉ FDE: 0x07da90 | Kích thước: 248 bytes
//   0x10465c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x104660: 9401DFC8  bl       #0x17c580
//   0x104664: 9402124B  bl       #0x188f90
//   0x104668: 52800200  mov      w0, #0x10
static inline uint64_t fde_func_0823_0x10465c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10465cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x9401dfc8ULL) ^ 0x07da90ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0824 | PC: 0x104754 | FDE: 0x07db00 | Size: 256 bytes
// Khung tháo gỡ #0824 | Địa chỉ PC: 0x104754 | Địa chỉ FDE: 0x07db00 | Kích thước: 256 bytes
//   0x104754: D10103FF  sub      sp, sp, #0x40
//   0x104758: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x10475c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x104760: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0824_0x104754(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x104754ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x07db00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0825 | PC: 0x104aac | FDE: 0x07db88 | Size: 256 bytes
// Khung tháo gỡ #0825 | Địa chỉ PC: 0x104aac | Địa chỉ FDE: 0x07db88 | Kích thước: 256 bytes
//   0x104aac: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x104ab0: AA0003E8  mov      x8, x0
//   0x104ab4: 39404009  ldrb     w9, [x0, #0x10]
//   0x104ab8: B9400000  ldr      w0, [x0]
static inline uint64_t fde_func_0825_0x104aac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x104aacULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x07db88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0826 | PC: 0x104bd4 | FDE: 0x07dc00 | Size: 232 bytes
// Khung tháo gỡ #0826 | Địa chỉ PC: 0x104bd4 | Địa chỉ FDE: 0x07dc00 | Kích thước: 232 bytes
//   0x104bd4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x104bd8: 9401DE6A  bl       #0x17c580
//   0x104bdc: 94020BD5  bl       #0x187b30
//   0x104be0: 52800200  mov      w0, #0x10
static inline uint64_t fde_func_0826_0x104bd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x104bd4ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x9401de6aULL) ^ 0x07dc00ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0827 | PC: 0x104cbc | FDE: 0x07dc68 | Size: 256 bytes
// Khung tháo gỡ #0827 | Địa chỉ PC: 0x104cbc | Địa chỉ FDE: 0x07dc68 | Kích thước: 256 bytes
//   0x104cbc: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x104cc0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x104cc4: AA0203E8  mov      x8, x2
//   0x104cc8: EB01007F  cmp      x3, x1
static inline uint64_t fde_func_0827_0x104cbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x104cbcULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x07dc68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0828 | PC: 0x104e14 | FDE: 0x07dce0 | Size: 256 bytes
// Khung tháo gỡ #0828 | Địa chỉ PC: 0x104e14 | Địa chỉ FDE: 0x07dce0 | Kích thước: 256 bytes
//   0x104e14: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x104e18: B9400001  ldr      w1, [x0]
//   0x104e1c: AA0003F3  mov      x19, x0
//   0x104e20: 9401FE67  bl       #0x1847bc
static inline uint64_t fde_func_0828_0x104e14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x104e14ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb9400001ULL) ^ 0x07dce0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0829 | PC: 0x104fb0 | FDE: 0x07dd50 | Size: 256 bytes
// Khung tháo gỡ #0829 | Địa chỉ PC: 0x104fb0 | Địa chỉ FDE: 0x07dd50 | Kích thước: 256 bytes
//   0x104fb0: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x104fb4: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x104fb8: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x104fbc: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_0829_0x104fb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x104fb0ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x07dd50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0830 | PC: 0x105294 | FDE: 0x07ddc8 | Size: 256 bytes
// Khung tháo gỡ #0830 | Địa chỉ PC: 0x105294 | Địa chỉ FDE: 0x07ddc8 | Kích thước: 256 bytes
//   0x105294: D100C3FF  sub      sp, sp, #0x30
//   0x105298: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x10529c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1052a0: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_0830_0x105294(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x105294ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x07ddc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0831 | PC: 0x1053f4 | FDE: 0x07de40 | Size: 256 bytes
// Khung tháo gỡ #0831 | Địa chỉ PC: 0x1053f4 | Địa chỉ FDE: 0x07de40 | Kích thước: 256 bytes
//   0x1053f4: D10103FF  sub      sp, sp, #0x40
//   0x1053f8: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x1053fc: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x105400: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0831_0x1053f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1053f4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x07de40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0832 | PC: 0x10580c | FDE: 0x07ded0 | Size: 256 bytes
// Khung tháo gỡ #0832 | Địa chỉ PC: 0x10580c | Địa chỉ FDE: 0x07ded0 | Kích thước: 256 bytes
//   0x10580c: D100C3FF  sub      sp, sp, #0x30
//   0x105810: F9000BF4  str      x20, [sp, #0x10]
//   0x105814: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x105818: AA0103E8  mov      x8, x1
static inline uint64_t fde_func_0832_0x10580c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10580cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x07ded0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0833 | PC: 0x105bac | FDE: 0x07df50 | Size: 256 bytes
// Khung tháo gỡ #0833 | Địa chỉ PC: 0x105bac | Địa chỉ FDE: 0x07df50 | Kích thước: 256 bytes
//   0x105bac: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x105bb0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x105bb4: AA0103E8  mov      x8, x1
//   0x105bb8: D0FFF961  adrp     x1, #0x33000
static inline uint64_t fde_func_0833_0x105bac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x105bacULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x07df50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0834 | PC: 0x105cd4 | FDE: 0x07dfc0 | Size: 256 bytes
// Khung tháo gỡ #0834 | Địa chỉ PC: 0x105cd4 | Địa chỉ FDE: 0x07dfc0 | Kích thước: 256 bytes
//   0x105cd4: D100C3FF  sub      sp, sp, #0x30
//   0x105cd8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x105cdc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x105ce0: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0834_0x105cd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x105cd4ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x07dfc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0835 | PC: 0x106a10 | FDE: 0x07e060 | Size: 132 bytes
// Khung tháo gỡ #0835 | Địa chỉ PC: 0x106a10 | Địa chỉ FDE: 0x07e060 | Kích thước: 132 bytes
//   0x106a10: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x106a14: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x106a18: AA0003F3  mov      x19, x0
//   0x106a1c: 9401C484  bl       #0x177c2c
static inline uint64_t fde_func_0835_0x106a10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106a10ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x07e060ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0836 | PC: 0x106a94 | FDE: 0x07e0c8 | Size: 256 bytes
// Khung tháo gỡ #0836 | Địa chỉ PC: 0x106a94 | Địa chỉ FDE: 0x07e0c8 | Kích thước: 256 bytes
//   0x106a94: D10103FF  sub      sp, sp, #0x40
//   0x106a98: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x106a9c: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x106aa0: 910073E2  add      x2, sp, #0x1c
static inline uint64_t fde_func_0836_0x106a94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106a94ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x07e0c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0837 | PC: 0x106c7c | FDE: 0x07e138 | Size: 256 bytes
// Khung tháo gỡ #0837 | Địa chỉ PC: 0x106c7c | Địa chỉ FDE: 0x07e138 | Kích thước: 256 bytes
//   0x106c7c: 5291B328  mov      w8, #0x8d99
//   0x106c80: 6B08001F  cmp      w0, w8
//   0x106c84: 54000380  b.eq     #0x106cf4
//   0x106c88: 528320E8  mov      w8, #0x1907
static inline uint64_t fde_func_0837_0x106c7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106c7cULL ^ (static_cast<uint64_t>(0x5291b328ULL) << 13);
    acc = (acc + a1 + 0x6b08001fULL) ^ 0x07e138ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0838 | PC: 0x1070f0 | FDE: 0x07e1b8 | Size: 256 bytes
// Khung tháo gỡ #0838 | Địa chỉ PC: 0x1070f0 | Địa chỉ FDE: 0x07e1b8 | Kích thước: 256 bytes
//   0x1070f0: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x1070f4: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1070f8: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1070fc: B9439817  ldr      w23, [x0, #0x398]
static inline uint64_t fde_func_0838_0x1070f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1070f0ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x07e1b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0839 | PC: 0x1072cc | FDE: 0x07e238 | Size: 256 bytes
// Khung tháo gỡ #0839 | Địa chỉ PC: 0x1072cc | Địa chỉ FDE: 0x07e238 | Kích thước: 256 bytes
//   0x1072cc: 340004A3  cbz      w3, #0x107360
//   0x1072d0: 12827FE9  mov      w9, #-0x1400
//   0x1072d4: 0B090049  add      w9, w2, w9
//   0x1072d8: AA0103E8  mov      x8, x1
static inline uint64_t fde_func_0839_0x1072cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1072ccULL ^ (static_cast<uint64_t>(0x340004a3ULL) << 13);
    acc = (acc + a1 + 0x12827fe9ULL) ^ 0x07e238ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0840 | PC: 0x1075e8 | FDE: 0x07e298 | Size: 256 bytes
// Khung tháo gỡ #0840 | Địa chỉ PC: 0x1075e8 | Địa chỉ FDE: 0x07e298 | Kích thước: 256 bytes
//   0x1075e8: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x1075ec: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1075f0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1075f4: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0840_0x1075e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1075e8ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x07e298ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0841 | PC: 0x107b00 | FDE: 0x07e338 | Size: 256 bytes
// Khung tháo gỡ #0841 | Địa chỉ PC: 0x107b00 | Địa chỉ FDE: 0x07e338 | Kích thước: 256 bytes
//   0x107b00: AA1E03E8  mov      x8, x30
//   0x107b04: 9401BF32  bl       #0x1777cc
//   0x107b08: AA0803FE  mov      x30, x8
//   0x107b0c: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_0841_0x107b00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x107b00ULL ^ (static_cast<uint64_t>(0xaa1e03e8ULL) << 13);
    acc = (acc + a1 + 0x9401bf32ULL) ^ 0x07e338ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0842 | PC: 0x108114 | FDE: 0x07e3f0 | Size: 256 bytes
// Khung tháo gỡ #0842 | Địa chỉ PC: 0x108114 | Địa chỉ FDE: 0x07e3f0 | Kích thước: 256 bytes
//   0x108114: AA1E03E8  mov      x8, x30
//   0x108118: 9401B74C  bl       #0x175e48
//   0x10811c: AA0803FE  mov      x30, x8
//   0x108120: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0842_0x108114(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108114ULL ^ (static_cast<uint64_t>(0xaa1e03e8ULL) << 13);
    acc = (acc + a1 + 0x9401b74cULL) ^ 0x07e3f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0843 | PC: 0x108838 | FDE: 0x07e4b0 | Size: 256 bytes
// Khung tháo gỡ #0843 | Địa chỉ PC: 0x108838 | Địa chỉ FDE: 0x07e4b0 | Kích thước: 256 bytes
//   0x108838: D10483FF  sub      sp, sp, #0x120
//   0x10883c: F9006BFC  str      x28, [sp, #0xd0]
//   0x108840: A90E63F9  stp      x25, x24, [sp, #0xe0]
//   0x108844: A90F5BF7  stp      x23, x22, [sp, #0xf0]
static inline uint64_t fde_func_0843_0x108838(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108838ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf9006bfcULL) ^ 0x07e4b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0844 | PC: 0x108e14 | FDE: 0x07e548 | Size: 256 bytes
// Khung tháo gỡ #0844 | Địa chỉ PC: 0x108e14 | Địa chỉ FDE: 0x07e548 | Kích thước: 256 bytes
//   0x108e14: D100C3FF  sub      sp, sp, #0x30
//   0x108e18: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x108e1c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x108e20: AA0103F5  mov      x21, x1
static inline uint64_t fde_func_0844_0x108e14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108e14ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x07e548ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0845 | PC: 0x109564 | FDE: 0x07e5d8 | Size: 144 bytes
// Khung tháo gỡ #0845 | Địa chỉ PC: 0x109564 | Địa chỉ FDE: 0x07e5d8 | Kích thước: 144 bytes
//   0x109564: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x109568: 9401C49C  bl       #0x17a7d8
//   0x10956c: 9401FFF5  bl       #0x189540
//   0x109570: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_0845_0x109564(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109564ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x9401c49cULL) ^ 0x07e5d8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0846 | PC: 0x1095f4 | FDE: 0x07e640 | Size: 256 bytes
// Khung tháo gỡ #0846 | Địa chỉ PC: 0x1095f4 | Địa chỉ FDE: 0x07e640 | Kích thước: 256 bytes
//   0x1095f4: D10103FF  sub      sp, sp, #0x40
//   0x1095f8: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x1095fc: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x109600: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0846_0x1095f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1095f4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x07e640ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0847 | PC: 0x109ab0 | FDE: 0x07e6c0 | Size: 256 bytes
// Khung tháo gỡ #0847 | Địa chỉ PC: 0x109ab0 | Địa chỉ FDE: 0x07e6c0 | Kích thước: 256 bytes
//   0x109ab0: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x109ab4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x109ab8: F9400008  ldr      x8, [x0]
//   0x109abc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0847_0x109ab0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109ab0ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x07e6c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0848 | PC: 0x109bf8 | FDE: 0x07e758 | Size: 256 bytes
// Khung tháo gỡ #0848 | Địa chỉ PC: 0x109bf8 | Địa chỉ FDE: 0x07e758 | Kích thước: 256 bytes
//   0x109bf8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x109bfc: 9401B34D  bl       #0x176930
//   0x109c00: 9401FBCC  bl       #0x188b30
//   0x109c04: 9401BE80  bl       #0x179604
static inline uint64_t fde_func_0848_0x109bf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109bf8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9401b34dULL) ^ 0x07e758ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0849 | PC: 0x109d08 | FDE: 0x07e7e8 | Size: 256 bytes
// Khung tháo gỡ #0849 | Địa chỉ PC: 0x109d08 | Địa chỉ FDE: 0x07e7e8 | Kích thước: 256 bytes
//   0x109d08: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x109d0c: 9401B309  bl       #0x176930
//   0x109d10: 9401FB8C  bl       #0x188b40
//   0x109d14: 9401BE3C  bl       #0x179604
static inline uint64_t fde_func_0849_0x109d08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109d08ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9401b309ULL) ^ 0x07e7e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0850 | PC: 0x109e18 | FDE: 0x07e878 | Size: 256 bytes
// Khung tháo gỡ #0850 | Địa chỉ PC: 0x109e18 | Địa chỉ FDE: 0x07e878 | Kích thước: 256 bytes
//   0x109e18: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x109e1c: 9401B2C5  bl       #0x176930
//   0x109e20: 9401FDDC  bl       #0x189590
//   0x109e24: 9401BDF8  bl       #0x179604
static inline uint64_t fde_func_0850_0x109e18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109e18ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9401b2c5ULL) ^ 0x07e878ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0851 | PC: 0x109f28 | FDE: 0x07e908 | Size: 256 bytes
// Khung tháo gỡ #0851 | Địa chỉ PC: 0x109f28 | Địa chỉ FDE: 0x07e908 | Kích thước: 256 bytes
//   0x109f28: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x109f2c: 9401B281  bl       #0x176930
//   0x109f30: 9401FDA0  bl       #0x1895b0
//   0x109f34: 9401BDB4  bl       #0x179604
static inline uint64_t fde_func_0851_0x109f28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x109f28ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9401b281ULL) ^ 0x07e908ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0852 | PC: 0x10a038 | FDE: 0x07e998 | Size: 256 bytes
// Khung tháo gỡ #0852 | Địa chỉ PC: 0x10a038 | Địa chỉ FDE: 0x07e998 | Kích thước: 256 bytes
//   0x10a038: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x10a03c: 9401B23D  bl       #0x176930
//   0x10a040: 9401FD64  bl       #0x1895d0
//   0x10a044: 9401BD70  bl       #0x179604
static inline uint64_t fde_func_0852_0x10a038(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10a038ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9401b23dULL) ^ 0x07e998ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0853 | PC: 0x10a148 | FDE: 0x07ea28 | Size: 256 bytes
// Khung tháo gỡ #0853 | Địa chỉ PC: 0x10a148 | Địa chỉ FDE: 0x07ea28 | Kích thước: 256 bytes
//   0x10a148: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x10a14c: 9401B1F9  bl       #0x176930
//   0x10a150: 9401FD28  bl       #0x1895f0
//   0x10a154: 9401BD2C  bl       #0x179604
static inline uint64_t fde_func_0853_0x10a148(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10a148ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9401b1f9ULL) ^ 0x07ea28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0854 | PC: 0x10a2b4 | FDE: 0x07eaa0 | Size: 256 bytes
// Khung tháo gỡ #0854 | Địa chỉ PC: 0x10a2b4 | Địa chỉ FDE: 0x07eaa0 | Kích thước: 256 bytes
//   0x10a2b4: B4000261  cbz      x1, #0x10a300
//   0x10a2b8: D10143FF  sub      sp, sp, #0x50
//   0x10a2bc: F9001BF4  str      x20, [sp, #0x30]
//   0x10a2c0: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0854_0x10a2b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10a2b4ULL ^ (static_cast<uint64_t>(0xb4000261ULL) << 13);
    acc = (acc + a1 + 0xd10143ffULL) ^ 0x07eaa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0855 | PC: 0x10a4b4 | FDE: 0x07eb20 | Size: 256 bytes
// Khung tháo gỡ #0855 | Địa chỉ PC: 0x10a4b4 | Địa chỉ FDE: 0x07eb20 | Kích thước: 256 bytes
//   0x10a4b4: D10183FF  sub      sp, sp, #0x60
//   0x10a4b8: 6D0223E9  stp      d9, d8, [sp, #0x20]
//   0x10a4bc: F9001BF6  str      x22, [sp, #0x30]
//   0x10a4c0: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0855_0x10a4b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10a4b4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0x6d0223e9ULL) ^ 0x07eb20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0856 | PC: 0x10a6f0 | FDE: 0x07ebb0 | Size: 256 bytes
// Khung tháo gỡ #0856 | Địa chỉ PC: 0x10a6f0 | Địa chỉ FDE: 0x07ebb0 | Kích thước: 256 bytes
//   0x10a6f0: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x10a6f4: 9401C7A7  bl       #0x17c590
//   0x10a6f8: 9401FBC6  bl       #0x189610
//   0x10a6fc: 52800180  mov      w0, #0xc
static inline uint64_t fde_func_0856_0x10a6f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10a6f0ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x9401c7a7ULL) ^ 0x07ebb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0857 | PC: 0x10a884 | FDE: 0x07ec30 | Size: 256 bytes
// Khung tháo gỡ #0857 | Địa chỉ PC: 0x10a884 | Địa chỉ FDE: 0x07ec30 | Kích thước: 256 bytes
//   0x10a884: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x10a888: 9401EB85  bl       #0x18569c
//   0x10a88c: 9401FB65  bl       #0x189620
//   0x10a890: 52800200  mov      w0, #0x10
static inline uint64_t fde_func_0857_0x10a884(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10a884ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x9401eb85ULL) ^ 0x07ec30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0858 | PC: 0x10aa10 | FDE: 0x07ecb0 | Size: 256 bytes
// Khung tháo gỡ #0858 | Địa chỉ PC: 0x10aa10 | Địa chỉ FDE: 0x07ecb0 | Kích thước: 256 bytes
//   0x10aa10: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x10aa14: 9401C6DB  bl       #0x17c580
//   0x10aa18: 9401FB06  bl       #0x189630
//   0x10aa1c: 52800200  mov      w0, #0x10
static inline uint64_t fde_func_0858_0x10aa10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10aa10ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x9401c6dbULL) ^ 0x07ecb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0859 | PC: 0x10abb4 | FDE: 0x07ed38 | Size: 256 bytes
// Khung tháo gỡ #0859 | Địa chỉ PC: 0x10abb4 | Địa chỉ FDE: 0x07ed38 | Kích thước: 256 bytes
//   0x10abb4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x10abb8: 9401EAB4  bl       #0x185688
//   0x10abbc: 9401FAA1  bl       #0x189640
//   0x10abc0: 52800280  mov      w0, #0x14
static inline uint64_t fde_func_0859_0x10abb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10abb4ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x9401eab4ULL) ^ 0x07ed38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0860 | PC: 0x10ad54 | FDE: 0x07edb8 | Size: 256 bytes
// Khung tháo gỡ #0860 | Địa chỉ PC: 0x10ad54 | Địa chỉ FDE: 0x07edb8 | Kích thước: 256 bytes
//   0x10ad54: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x10ad58: 9401C344  bl       #0x17ba68
//   0x10ad5c: 9401FA3D  bl       #0x189650
//   0x10ad60: 52800280  mov      w0, #0x14
static inline uint64_t fde_func_0860_0x10ad54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10ad54ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x9401c344ULL) ^ 0x07edb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0861 | PC: 0x10ae88 | FDE: 0x07ee40 | Size: 256 bytes
// Khung tháo gỡ #0861 | Địa chỉ PC: 0x10ae88 | Địa chỉ FDE: 0x07ee40 | Kích thước: 256 bytes
//   0x10ae88: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x10ae8c: 9401B08F  bl       #0x1770c8
//   0x10ae90: 9401F9F4  bl       #0x189660
//   0x10ae94: 9401BE0B  bl       #0x17a6c0
static inline uint64_t fde_func_0861_0x10ae88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10ae88ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9401b08fULL) ^ 0x07ee40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0862 | PC: 0x10af98 | FDE: 0x07eed0 | Size: 256 bytes
// Khung tháo gỡ #0862 | Địa chỉ PC: 0x10af98 | Địa chỉ FDE: 0x07eed0 | Kích thước: 256 bytes
//   0x10af98: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x10af9c: 9401B04B  bl       #0x1770c8
//   0x10afa0: 9401F82C  bl       #0x189050
//   0x10afa4: 9401BDC7  bl       #0x17a6c0
static inline uint64_t fde_func_0862_0x10af98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10af98ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9401b04bULL) ^ 0x07eed0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0863 | PC: 0x10b0a8 | FDE: 0x07ef60 | Size: 256 bytes
// Khung tháo gỡ #0863 | Địa chỉ PC: 0x10b0a8 | Địa chỉ FDE: 0x07ef60 | Kích thước: 256 bytes
//   0x10b0a8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x10b0ac: 9401B007  bl       #0x1770c8
//   0x10b0b0: 9401F978  bl       #0x189690
//   0x10b0b4: 9401BD83  bl       #0x17a6c0
static inline uint64_t fde_func_0863_0x10b0a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10b0a8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9401b007ULL) ^ 0x07ef60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0864 | PC: 0x10b1b8 | FDE: 0x07eff0 | Size: 256 bytes
// Khung tháo gỡ #0864 | Địa chỉ PC: 0x10b1b8 | Địa chỉ FDE: 0x07eff0 | Kích thước: 256 bytes
//   0x10b1b8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x10b1bc: 9401AFC3  bl       #0x1770c8
//   0x10b1c0: 9401F93C  bl       #0x1896b0
//   0x10b1c4: 9401BD3F  bl       #0x17a6c0
static inline uint64_t fde_func_0864_0x10b1b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10b1b8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9401afc3ULL) ^ 0x07eff0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0865 | PC: 0x10b2c8 | FDE: 0x07f080 | Size: 256 bytes
// Khung tháo gỡ #0865 | Địa chỉ PC: 0x10b2c8 | Địa chỉ FDE: 0x07f080 | Kích thước: 256 bytes
//   0x10b2c8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x10b2cc: 9401AF7F  bl       #0x1770c8
//   0x10b2d0: 9401F900  bl       #0x1896d0
//   0x10b2d4: 9401BCFB  bl       #0x17a6c0
static inline uint64_t fde_func_0865_0x10b2c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10b2c8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9401af7fULL) ^ 0x07f080ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0866 | PC: 0x10b438 | FDE: 0x07f0f8 | Size: 256 bytes
// Khung tháo gỡ #0866 | Địa chỉ PC: 0x10b438 | Địa chỉ FDE: 0x07f0f8 | Kích thước: 256 bytes
//   0x10b438: D10203FF  sub      sp, sp, #0x80
//   0x10b43c: F9002BF6  str      x22, [sp, #0x50]
//   0x10b440: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x10b444: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0866_0x10b438(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10b438ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf6ULL) ^ 0x07f0f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0867 | PC: 0x10b608 | FDE: 0x07f178 | Size: 256 bytes
// Khung tháo gỡ #0867 | Địa chỉ PC: 0x10b608 | Địa chỉ FDE: 0x07f178 | Kích thước: 256 bytes
//   0x10b608: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x10b60c: 9401EA57  bl       #0x185f68
//   0x10b610: 52800100  mov      w0, #8
//   0x10b614: F84107FE  ldr      x30, [sp], #0x10
static inline uint64_t fde_func_0867_0x10b608(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10b608ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x9401ea57ULL) ^ 0x07f178ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0868 | PC: 0x10b75c | FDE: 0x07f1e8 | Size: 256 bytes
// Khung tháo gỡ #0868 | Địa chỉ PC: 0x10b75c | Địa chỉ FDE: 0x07f1e8 | Kích thước: 256 bytes
//   0x10b75c: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x10b760: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x10b764: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x10b768: 9401BCDA  bl       #0x17aad0
static inline uint64_t fde_func_0868_0x10b75c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10b75cULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x07f1e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0869 | PC: 0x10b944 | FDE: 0x07f260 | Size: 256 bytes
// Khung tháo gỡ #0869 | Địa chỉ PC: 0x10b944 | Địa chỉ FDE: 0x07f260 | Kích thước: 256 bytes
//   0x10b944: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x10b948: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x10b94c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x10b950: 9401BAE8  bl       #0x17a4f0
static inline uint64_t fde_func_0869_0x10b944(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10b944ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x07f260ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0870 | PC: 0x10bb28 | FDE: 0x07f2d8 | Size: 256 bytes
// Khung tháo gỡ #0870 | Địa chỉ PC: 0x10bb28 | Địa chỉ FDE: 0x07f2d8 | Kích thước: 256 bytes
//   0x10bb28: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x10bb2c: B9400008  ldr      w8, [x0]
//   0x10bb30: BD400400  ldr      s0, [x0, #4]
//   0x10bb34: 2A0803E0  mov      w0, w8
static inline uint64_t fde_func_0870_0x10bb28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10bb28ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb9400008ULL) ^ 0x07f2d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0871 | PC: 0x10bc8c | FDE: 0x07f348 | Size: 256 bytes
// Khung tháo gỡ #0871 | Địa chỉ PC: 0x10bc8c | Địa chỉ FDE: 0x07f348 | Kích thước: 256 bytes
//   0x10bc8c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x10bc90: 9401E683  bl       #0x18569c
//   0x10bc94: 9401F69B  bl       #0x189700
//   0x10bc98: 52800200  mov      w0, #0x10
static inline uint64_t fde_func_0871_0x10bc8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10bc8cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x9401e683ULL) ^ 0x07f348ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0872 | PC: 0x10bd94 | FDE: 0x07f3b0 | Size: 256 bytes
// Khung tháo gỡ #0872 | Địa chỉ PC: 0x10bd94 | Địa chỉ FDE: 0x07f3b0 | Kích thước: 256 bytes
//   0x10bd94: AA1E03E7  mov      x7, x30
//   0x10bd98: 9401B0B7  bl       #0x178074
//   0x10bd9c: AA0703FE  mov      x30, x7
//   0x10bda0: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0872_0x10bd94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10bd94ULL ^ (static_cast<uint64_t>(0xaa1e03e7ULL) << 13);
    acc = (acc + a1 + 0x9401b0b7ULL) ^ 0x07f3b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0873 | PC: 0x10c100 | FDE: 0x07f430 | Size: 236 bytes
// Khung tháo gỡ #0873 | Địa chỉ PC: 0x10c100 | Địa chỉ FDE: 0x07f430 | Kích thước: 236 bytes
//   0x10c100: D10583FF  sub      sp, sp, #0x160
//   0x10c104: F9009BFC  str      x28, [sp, #0x130]
//   0x10c108: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x10c10c: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0873_0x10c100(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c100ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x07f430ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0874 | PC: 0x10c1ec | FDE: 0x07f4a0 | Size: 256 bytes
// Khung tháo gỡ #0874 | Địa chỉ PC: 0x10c1ec | Địa chỉ FDE: 0x07f4a0 | Kích thước: 256 bytes
//   0x10c1ec: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x10c1f0: F9400008  ldr      x8, [x0]
//   0x10c1f4: B9400100  ldr      w0, [x8]
//   0x10c1f8: 9401F202  bl       #0x188a00
static inline uint64_t fde_func_0874_0x10c1ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c1ecULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x07f4a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0875 | PC: 0x10c440 | FDE: 0x07f520 | Size: 256 bytes
// Khung tháo gỡ #0875 | Địa chỉ PC: 0x10c440 | Địa chỉ FDE: 0x07f520 | Kích thước: 256 bytes
//   0x10c440: D100C3FF  sub      sp, sp, #0x30
//   0x10c444: F9000BF4  str      x20, [sp, #0x10]
//   0x10c448: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x10c44c: 9401B18C  bl       #0x178a7c
static inline uint64_t fde_func_0875_0x10c440(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c440ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x07f520ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0876 | PC: 0x10c578 | FDE: 0x07f598 | Size: 256 bytes
// Khung tháo gỡ #0876 | Địa chỉ PC: 0x10c578 | Địa chỉ FDE: 0x07f598 | Kích thước: 256 bytes
//   0x10c578: D100C3FF  sub      sp, sp, #0x30
//   0x10c57c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x10c580: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x10c584: 9100C034  add      x20, x1, #0x30
static inline uint64_t fde_func_0876_0x10c578(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c578ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x07f598ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0877 | PC: 0x10c778 | FDE: 0x07f618 | Size: 256 bytes
// Khung tháo gỡ #0877 | Địa chỉ PC: 0x10c778 | Địa chỉ FDE: 0x07f618 | Kích thước: 256 bytes
//   0x10c778: 91002008  add      x8, x0, #8
//   0x10c77c: AA0803E9  mov      x9, x8
//   0x10c780: AA0803E0  mov      x0, x8
//   0x10c784: F940012A  ldr      x10, [x9]
static inline uint64_t fde_func_0877_0x10c778(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c778ULL ^ (static_cast<uint64_t>(0x91002008ULL) << 13);
    acc = (acc + a1 + 0xaa0803e9ULL) ^ 0x07f618ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0878 | PC: 0x10c908 | FDE: 0x07f688 | Size: 256 bytes
// Khung tháo gỡ #0878 | Địa chỉ PC: 0x10c908 | Địa chỉ FDE: 0x07f688 | Kích thước: 256 bytes
//   0x10c908: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x10c90c: AA0003F3  mov      x19, x0
//   0x10c910: 97FFFFF6  bl       #0x10c8e8
//   0x10c914: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0878_0x10c908(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c908ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x07f688ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0879 | PC: 0x10cb90 | FDE: 0x07f708 | Size: 256 bytes
// Khung tháo gỡ #0879 | Địa chỉ PC: 0x10cb90 | Địa chỉ FDE: 0x07f708 | Kích thước: 256 bytes
//   0x10cb90: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x10cb94: F9400000  ldr      x0, [x0]
//   0x10cb98: 97FF67C4  bl       #0xe6aa8
//   0x10cb9c: 52800100  mov      w0, #8
static inline uint64_t fde_func_0879_0x10cb90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10cb90ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400000ULL) ^ 0x07f708ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0880 | PC: 0x10ccfc | FDE: 0x07f778 | Size: 256 bytes
// Khung tháo gỡ #0880 | Địa chỉ PC: 0x10ccfc | Địa chỉ FDE: 0x07f778 | Kích thước: 256 bytes
//   0x10ccfc: F9403C08  ldr      x8, [x0, #0x78]
//   0x10cd00: 5280060A  mov      w10, #0x30
//   0x10cd04: 12000049  and      w9, w2, #1
//   0x10cd08: 9BAA2028  umaddl   x8, w1, w10, x8
static inline uint64_t fde_func_0880_0x10ccfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10ccfcULL ^ (static_cast<uint64_t>(0xf9403c08ULL) << 13);
    acc = (acc + a1 + 0x5280060aULL) ^ 0x07f778ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0881 | PC: 0x10cebc | FDE: 0x07f7e8 | Size: 256 bytes
// Khung tháo gỡ #0881 | Địa chỉ PC: 0x10cebc | Địa chỉ FDE: 0x07f7e8 | Kích thước: 256 bytes
//   0x10cebc: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x10cec0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x10cec4: 9401D93E  bl       #0x1833bc
//   0x10cec8: 91012015  add      x21, x0, #0x48
static inline uint64_t fde_func_0881_0x10cebc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10cebcULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x07f7e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0882 | PC: 0x10d06c | FDE: 0x07f868 | Size: 256 bytes
// Khung tháo gỡ #0882 | Địa chỉ PC: 0x10d06c | Địa chỉ FDE: 0x07f868 | Kích thước: 256 bytes
//   0x10d06c: D10143FF  sub      sp, sp, #0x50
//   0x10d070: F9001BF4  str      x20, [sp, #0x30]
//   0x10d074: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x10d078: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0882_0x10d06c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d06cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf4ULL) ^ 0x07f868ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0883 | PC: 0x10d198 | FDE: 0x07f8d8 | Size: 256 bytes
// Khung tháo gỡ #0883 | Địa chỉ PC: 0x10d198 | Địa chỉ FDE: 0x07f8d8 | Kích thước: 256 bytes
//   0x10d198: FC1B0FE8  str      d8, [sp, #-0x50]!
//   0x10d19c: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x10d1a0: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x10d1a4: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0883_0x10d198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d198ULL ^ (static_cast<uint64_t>(0xfc1b0fe8ULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x07f8d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0884 | PC: 0x10d3a4 | FDE: 0x07f950 | Size: 184 bytes
// Khung tháo gỡ #0884 | Địa chỉ PC: 0x10d3a4 | Địa chỉ FDE: 0x07f950 | Kích thước: 184 bytes
//   0x10d3a4: D10183FF  sub      sp, sp, #0x60
//   0x10d3a8: F90023F4  str      x20, [sp, #0x40]
//   0x10d3ac: A9057BF3  stp      x19, x30, [sp, #0x50]
//   0x10d3b0: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0884_0x10d3a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d3a4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90023f4ULL) ^ 0x07f950ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0885 | PC: 0x10d45c | FDE: 0x07f9b8 | Size: 224 bytes
// Khung tháo gỡ #0885 | Địa chỉ PC: 0x10d45c | Địa chỉ FDE: 0x07f9b8 | Kích thước: 224 bytes
//   0x10d45c: D10083FF  sub      sp, sp, #0x20
//   0x10d460: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x10d464: F9400408  ldr      x8, [x0, #8]
//   0x10d468: F9400908  ldr      x8, [x8, #0x10]
static inline uint64_t fde_func_0885_0x10d45c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d45cULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x07f9b8ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #0886 | PC: 0x10d53c | FDE: 0x07fa18 | Size: 256 bytes
// Khung tháo gỡ #0886 | Địa chỉ PC: 0x10d53c | Địa chỉ FDE: 0x07fa18 | Kích thước: 256 bytes
//   0x10d53c: D10283FF  sub      sp, sp, #0xa0
//   0x10d540: FD002BEA  str      d10, [sp, #0x50]
//   0x10d544: 6D0623E9  stp      d9, d8, [sp, #0x60]
//   0x10d548: A9075BF7  stp      x23, x22, [sp, #0x70]
static inline uint64_t fde_func_0886_0x10d53c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d53cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xfd002beaULL) ^ 0x07fa18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0887 | PC: 0x10d790 | FDE: 0x07fab8 | Size: 256 bytes
// Khung tháo gỡ #0887 | Địa chỉ PC: 0x10d790 | Địa chỉ FDE: 0x07fab8 | Kích thước: 256 bytes
//   0x10d790: D10583FF  sub      sp, sp, #0x160
//   0x10d794: A9135BFC  stp      x28, x22, [sp, #0x130]
//   0x10d798: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x10d79c: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0887_0x10d790(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d790ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa9135bfcULL) ^ 0x07fab8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0888 | PC: 0x10d948 | FDE: 0x07fb40 | Size: 256 bytes
// Khung tháo gỡ #0888 | Địa chỉ PC: 0x10d948 | Địa chỉ FDE: 0x07fb40 | Kích thước: 256 bytes
//   0x10d948: AA1E03E3  mov      x3, x30
//   0x10d94c: 9401B53A  bl       #0x17ae34
//   0x10d950: AA0303FE  mov      x30, x3
//   0x10d954: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0888_0x10d948(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d948ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x9401b53aULL) ^ 0x07fb40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0889 | PC: 0x10dbe4 | FDE: 0x07fbd8 | Size: 256 bytes
// Khung tháo gỡ #0889 | Địa chỉ PC: 0x10dbe4 | Địa chỉ FDE: 0x07fbd8 | Kích thước: 256 bytes
//   0x10dbe4: D10483FF  sub      sp, sp, #0x120
//   0x10dbe8: F90083FC  str      x28, [sp, #0x100]
//   0x10dbec: A9117BF3  stp      x19, x30, [sp, #0x110]
//   0x10dbf0: 94019F33  bl       #0x1758bc
static inline uint64_t fde_func_0889_0x10dbe4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10dbe4ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x07fbd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0890 | PC: 0x10de14 | FDE: 0x07fc58 | Size: 256 bytes
// Khung tháo gỡ #0890 | Địa chỉ PC: 0x10de14 | Địa chỉ FDE: 0x07fc58 | Kích thước: 256 bytes
//   0x10de14: AA1E03E2  mov      x2, x30
//   0x10de18: 9401BF59  bl       #0x17db7c
//   0x10de1c: AA0203FE  mov      x30, x2
//   0x10de20: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_0890_0x10de14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10de14ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9401bf59ULL) ^ 0x07fc58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0891 | PC: 0x10df60 | FDE: 0x07fcc8 | Size: 256 bytes
// Khung tháo gỡ #0891 | Địa chỉ PC: 0x10df60 | Địa chỉ FDE: 0x07fcc8 | Kích thước: 256 bytes
//   0x10df60: F0000408  adrp     x8, #0x190000
//   0x10df64: 913C0108  add      x8, x8, #0xf00
//   0x10df68: 1401AF3D  b        #0x179c5c
//   0x10df6c: D10243FF  sub      sp, sp, #0x90
static inline uint64_t fde_func_0891_0x10df60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10df60ULL ^ (static_cast<uint64_t>(0xf0000408ULL) << 13);
    acc = (acc + a1 + 0x913c0108ULL) ^ 0x07fcc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0892 | PC: 0x10e088 | FDE: 0x07fd30 | Size: 256 bytes
// Khung tháo gỡ #0892 | Địa chỉ PC: 0x10e088 | Địa chỉ FDE: 0x07fd30 | Kích thước: 256 bytes
//   0x10e088: D0000408  adrp     x8, #0x190000
//   0x10e08c: 913D2108  add      x8, x8, #0xf48
//   0x10e090: 1401B420  b        #0x17b110
//   0x10e094: D10103FF  sub      sp, sp, #0x40
static inline uint64_t fde_func_0892_0x10e088(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10e088ULL ^ (static_cast<uint64_t>(0xd0000408ULL) << 13);
    acc = (acc + a1 + 0x913d2108ULL) ^ 0x07fd30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0893 | PC: 0x10e1b8 | FDE: 0x07fda0 | Size: 256 bytes
// Khung tháo gỡ #0893 | Địa chỉ PC: 0x10e1b8 | Địa chỉ FDE: 0x07fda0 | Kích thước: 256 bytes
//   0x10e1b8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x10e1bc: AA0003F3  mov      x19, x0
//   0x10e1c0: 9401A6A0  bl       #0x177c40
//   0x10e1c4: D0000408  adrp     x8, #0x190000
static inline uint64_t fde_func_0893_0x10e1b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10e1b8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x07fda0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0894 | PC: 0x10e3e4 | FDE: 0x07fe18 | Size: 256 bytes
// Khung tháo gỡ #0894 | Địa chỉ PC: 0x10e3e4 | Địa chỉ FDE: 0x07fe18 | Kích thước: 256 bytes
//   0x10e3e4: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x10e3e8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x10e3ec: 94019EED  bl       #0x175fa0
//   0x10e3f0: 9401E454  bl       #0x187540
static inline uint64_t fde_func_0894_0x10e3e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10e3e4ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x07fe18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0895 | PC: 0x10e898 | FDE: 0x07feb0 | Size: 256 bytes
// Khung tháo gỡ #0895 | Địa chỉ PC: 0x10e898 | Địa chỉ FDE: 0x07feb0 | Kích thước: 256 bytes
//   0x10e898: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x10e89c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x10e8a0: A942A014  ldp      x20, x8, [x0, #0x28]
//   0x10e8a4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0895_0x10e898(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10e898ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x07feb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0896 | PC: 0x10eb5c | FDE: 0x07ff28 | Size: 256 bytes
// Khung tháo gỡ #0896 | Địa chỉ PC: 0x10eb5c | Địa chỉ FDE: 0x07ff28 | Kích thước: 256 bytes
//   0x10eb5c: D10703FF  sub      sp, sp, #0x1c0
//   0x10eb60: A9176BFC  stp      x28, x26, [sp, #0x170]
//   0x10eb64: A91863F9  stp      x25, x24, [sp, #0x180]
//   0x10eb68: A9195BF7  stp      x23, x22, [sp, #0x190]
static inline uint64_t fde_func_0896_0x10eb5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10eb5cULL ^ (static_cast<uint64_t>(0xd10703ffULL) << 13);
    acc = (acc + a1 + 0xa9176bfcULL) ^ 0x07ff28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0897 | PC: 0x10eef4 | FDE: 0x07ffb0 | Size: 256 bytes
// Khung tháo gỡ #0897 | Địa chỉ PC: 0x10eef4 | Địa chỉ FDE: 0x07ffb0 | Kích thước: 256 bytes
//   0x10eef4: AA1E03E4  mov      x4, x30
//   0x10eef8: 9401B844  bl       #0x17d008
//   0x10eefc: AA0403FE  mov      x30, x4
//   0x10ef00: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0897_0x10eef4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10eef4ULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x9401b844ULL) ^ 0x07ffb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0898 | PC: 0x10f58c | FDE: 0x080038 | Size: 248 bytes
// Khung tháo gỡ #0898 | Địa chỉ PC: 0x10f58c | Địa chỉ FDE: 0x080038 | Kích thước: 248 bytes
//   0x10f58c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x10f590: 94000021  bl       #0x10f614
//   0x10f594: 9401AAA3  bl       #0x17a020
//   0x10f598: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_0898_0x10f58c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10f58cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x94000021ULL) ^ 0x080038ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0899 | PC: 0x10f684 | FDE: 0x0800a0 | Size: 124 bytes [AttachKryptonTraceHandler]
// Khung tháo gỡ #0899 | Địa chỉ PC: 0x10f684 | Địa chỉ FDE: 0x0800a0 | Kích thước: 124 bytes
//   0x10f684: D10583FF  sub      sp, sp, #0x160
//   0x10f688: F9009BFC  str      x28, [sp, #0x130]
//   0x10f68c: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x10f690: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0899_0x10f684(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10f684ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x0800a0ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0900 | PC: 0x10f700 | FDE: 0x0800c0 | Size: 168 bytes [_ZN4lynx6canvas7tracing5trace16ScopedTraceEventC2EPKciS5_S5_S5_S5_]
// Khung tháo gỡ #0900 | Địa chỉ PC: 0x10f700 | Địa chỉ FDE: 0x0800c0 | Kích thước: 168 bytes
//   0x10f700: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x10f704: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x10f708: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x10f70c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0900_0x10f700(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10f700ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0800c0ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #0901 | PC: 0x10f7a8 | FDE: 0x0800e8 | Size: 256 bytes [_ZN4lynx6canvas7tracing5trace16ScopedTraceEventD1Ev]
// Khung tháo gỡ #0901 | Địa chỉ PC: 0x10f7a8 | Địa chỉ FDE: 0x0800e8 | Kích thước: 256 bytes
//   0x10f7a8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x10f7ac: AA0003F3  mov      x19, x0
//   0x10f7b0: 9401B154  bl       #0x17bd00
//   0x10f7b4: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0901_0x10f7a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10f7a8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0800e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0902 | PC: 0x10fa44 | FDE: 0x080128 | Size: 256 bytes
// Khung tháo gỡ #0902 | Địa chỉ PC: 0x10fa44 | Địa chỉ FDE: 0x080128 | Kích thước: 256 bytes
//   0x10fa44: D10583FF  sub      sp, sp, #0x160
//   0x10fa48: A9135BFC  stp      x28, x22, [sp, #0x130]
//   0x10fa4c: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x10fa50: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0902_0x10fa44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10fa44ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa9135bfcULL) ^ 0x080128ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0903 | PC: 0x10fcc0 | FDE: 0x0801b0 | Size: 256 bytes
// Khung tháo gỡ #0903 | Địa chỉ PC: 0x10fcc0 | Địa chỉ FDE: 0x0801b0 | Kích thước: 256 bytes
//   0x10fcc0: D10543FF  sub      sp, sp, #0x150
//   0x10fcc4: A91353FC  stp      x28, x20, [sp, #0x130]
//   0x10fcc8: A9147BF3  stp      x19, x30, [sp, #0x140]
//   0x10fccc: 9401A539  bl       #0x1791b0
static inline uint64_t fde_func_0903_0x10fcc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10fcc0ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa91353fcULL) ^ 0x0801b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0904 | PC: 0x1100c4 | FDE: 0x080238 | Size: 256 bytes
// Khung tháo gỡ #0904 | Địa chỉ PC: 0x1100c4 | Địa chỉ FDE: 0x080238 | Kích thước: 256 bytes
//   0x1100c4: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x1100c8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1100cc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1100d0: 39422408  ldrb     w8, [x0, #0x89]
static inline uint64_t fde_func_0904_0x1100c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1100c4ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x080238ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0905 | PC: 0x11038c | FDE: 0x0802b8 | Size: 208 bytes
// Khung tháo gỡ #0905 | Địa chỉ PC: 0x11038c | Địa chỉ FDE: 0x0802b8 | Kích thước: 208 bytes
//   0x11038c: 3940A008  ldrb     w8, [x0, #0x28]
//   0x110390: 34000068  cbz      w8, #0x11039c
//   0x110394: 91004000  add      x0, x0, #0x10
//   0x110398: 17FE627C  b        #0xa8d88
static inline uint64_t fde_func_0905_0x11038c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11038cULL ^ (static_cast<uint64_t>(0x3940a008ULL) << 13);
    acc = (acc + a1 + 0x34000068ULL) ^ 0x0802b8ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0906 | PC: 0x11045c | FDE: 0x080320 | Size: 256 bytes
// Khung tháo gỡ #0906 | Địa chỉ PC: 0x11045c | Địa chỉ FDE: 0x080320 | Kích thước: 256 bytes
//   0x11045c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x110460: 9401CD95  bl       #0x183ab4
//   0x110464: 97FE6CF7  bl       #0xab840
//   0x110468: 91004260  add      x0, x19, #0x10
static inline uint64_t fde_func_0906_0x11045c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11045cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9401cd95ULL) ^ 0x080320ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0907 | PC: 0x11056c | FDE: 0x080388 | Size: 256 bytes
// Khung tháo gỡ #0907 | Địa chỉ PC: 0x11056c | Địa chỉ FDE: 0x080388 | Kích thước: 256 bytes
//   0x11056c: B0000408  adrp     x8, #0x191000
//   0x110570: 91020108  add      x8, x8, #0x80
//   0x110574: F8008408  str      x8, [x0], #8
//   0x110578: 17FFFFEA  b        #0x110520
static inline uint64_t fde_func_0907_0x11056c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11056cULL ^ (static_cast<uint64_t>(0xb0000408ULL) << 13);
    acc = (acc + a1 + 0x91020108ULL) ^ 0x080388ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0908 | PC: 0x110810 | FDE: 0x080400 | Size: 132 bytes
// Khung tháo gỡ #0908 | Địa chỉ PC: 0x110810 | Địa chỉ FDE: 0x080400 | Kích thước: 132 bytes
//   0x110810: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x110814: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x110818: F9400028  ldr      x8, [x1]
//   0x11081c: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0908_0x110810(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x110810ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x080400ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0909 | PC: 0x110894 | FDE: 0x080468 | Size: 116 bytes
// Khung tháo gỡ #0909 | Địa chỉ PC: 0x110894 | Địa chỉ FDE: 0x080468 | Kích thước: 116 bytes
//   0x110894: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x110898: AA0003F3  mov      x19, x0
//   0x11089c: 97FFFFFA  bl       #0x110884
//   0x1108a0: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0909_0x110894(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x110894ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x080468ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0910 | PC: 0x110908 | FDE: 0x0804c8 | Size: 116 bytes
// Khung tháo gỡ #0910 | Địa chỉ PC: 0x110908 | Địa chỉ FDE: 0x0804c8 | Kích thước: 116 bytes
//   0x110908: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x11090c: AA0003F3  mov      x19, x0
//   0x110910: 97FFFFFA  bl       #0x1108f8
//   0x110914: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0910_0x110908(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x110908ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0804c8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0911 | PC: 0x11097c | FDE: 0x080530 | Size: 256 bytes
// Khung tháo gỡ #0911 | Địa chỉ PC: 0x11097c | Địa chỉ FDE: 0x080530 | Kích thước: 256 bytes
//   0x11097c: AA1E03E2  mov      x2, x30
//   0x110980: 9401B92B  bl       #0x17ee2c
//   0x110984: AA0203FE  mov      x30, x2
//   0x110988: A90C7BF3  stp      x19, x30, [sp, #0xc0]
static inline uint64_t fde_func_0911_0x11097c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11097cULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9401b92bULL) ^ 0x080530ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0912 | PC: 0x110b54 | FDE: 0x0805a8 | Size: 88 bytes
// Khung tháo gỡ #0912 | Địa chỉ PC: 0x110b54 | Địa chỉ FDE: 0x0805a8 | Kích thước: 88 bytes
//   0x110b54: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x110b58: AA0003F3  mov      x19, x0
//   0x110b5c: 97FFFFFA  bl       #0x110b44
//   0x110b60: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0912_0x110b54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x110b54ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0805a8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0913 | PC: 0x110bac | FDE: 0x080610 | Size: 256 bytes
// Khung tháo gỡ #0913 | Địa chỉ PC: 0x110bac | Địa chỉ FDE: 0x080610 | Kích thước: 256 bytes
//   0x110bac: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x110bb0: AA0003F3  mov      x19, x0
//   0x110bb4: F9401400  ldr      x0, [x0, #0x28]
//   0x110bb8: 97FE6A9D  bl       #0xab62c
static inline uint64_t fde_func_0913_0x110bac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x110bacULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x080610ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0914 | PC: 0x110d8c | FDE: 0x080688 | Size: 256 bytes
// Khung tháo gỡ #0914 | Địa chỉ PC: 0x110d8c | Địa chỉ FDE: 0x080688 | Kích thước: 256 bytes
//   0x110d8c: B0000408  adrp     x8, #0x191000
//   0x110d90: 91056108  add      x8, x8, #0x158
//   0x110d94: F8008408  str      x8, [x0], #8
//   0x110d98: 17FFFFEA  b        #0x110d40
static inline uint64_t fde_func_0914_0x110d8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x110d8cULL ^ (static_cast<uint64_t>(0xb0000408ULL) << 13);
    acc = (acc + a1 + 0x91056108ULL) ^ 0x080688ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0915 | PC: 0x111030 | FDE: 0x080700 | Size: 112 bytes
// Khung tháo gỡ #0915 | Địa chỉ PC: 0x111030 | Địa chỉ FDE: 0x080700 | Kích thước: 112 bytes
//   0x111030: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x111034: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x111038: F9400028  ldr      x8, [x1]
//   0x11103c: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0915_0x111030(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x111030ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x080700ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0916 | PC: 0x1110a0 | FDE: 0x080768 | Size: 256 bytes
// Khung tháo gỡ #0916 | Địa chỉ PC: 0x1110a0 | Địa chỉ FDE: 0x080768 | Kích thước: 256 bytes
//   0x1110a0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1110a4: AA0003F3  mov      x19, x0
//   0x1110a8: 97FFFFFA  bl       #0x111090
//   0x1110ac: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0916_0x1110a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1110a0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x080768ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0917 | PC: 0x11120c | FDE: 0x0807e0 | Size: 80 bytes
// Khung tháo gỡ #0917 | Địa chỉ PC: 0x11120c | Địa chỉ FDE: 0x0807e0 | Kích thước: 80 bytes
//   0x11120c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x111210: 94019EC9  bl       #0x178d34
//   0x111214: 97FFFE66  bl       #0x110bac
//   0x111218: F9400660  ldr      x0, [x19, #8]
static inline uint64_t fde_func_0917_0x11120c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11120cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94019ec9ULL) ^ 0x0807e0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0918 | PC: 0x11125c | FDE: 0x080840 | Size: 256 bytes [_ZN4lynx6canvas20PlatformViewObserver16OnSurfaceCreatedENSt6__ndk110unique_ptrINS0_7SurfaceENS2_14default_deleteIS4_EEEEmRKNS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEENS0_13SurfaceConfigE]
// Khung tháo gỡ #0918 | Địa chỉ PC: 0x11125c | Địa chỉ FDE: 0x080840 | Kích thước: 256 bytes
//   0x11125c: AA1E03E5  mov      x5, x30
//   0x111260: 940192FA  bl       #0x175e48
//   0x111264: AA0503FE  mov      x30, x5
//   0x111268: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0918_0x11125c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11125cULL ^ (static_cast<uint64_t>(0xaa1e03e5ULL) << 13);
    acc = (acc + a1 + 0x940192faULL) ^ 0x080840ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0919 | PC: 0x111954 | FDE: 0x0808d8 | Size: 256 bytes
// Khung tháo gỡ #0919 | Địa chỉ PC: 0x111954 | Địa chỉ FDE: 0x0808d8 | Kích thước: 256 bytes
//   0x111954: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x111958: 9401AA97  bl       #0x17c3b4
//   0x11195c: 94000004  bl       #0x11196c
//   0x111960: F9400660  ldr      x0, [x19, #8]
static inline uint64_t fde_func_0919_0x111954(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x111954ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9401aa97ULL) ^ 0x0808d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0920 | PC: 0x111dc8 | FDE: 0x080958 | Size: 256 bytes
// Khung tháo gỡ #0920 | Địa chỉ PC: 0x111dc8 | Địa chỉ FDE: 0x080958 | Kích thước: 256 bytes
//   0x111dc8: D10683FF  sub      sp, sp, #0x1a0
//   0x111dcc: A9156BFC  stp      x28, x26, [sp, #0x150]
//   0x111dd0: A91663F9  stp      x25, x24, [sp, #0x160]
//   0x111dd4: A9175BF7  stp      x23, x22, [sp, #0x170]
static inline uint64_t fde_func_0920_0x111dc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x111dc8ULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xa9156bfcULL) ^ 0x080958ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0921 | PC: 0x1120b0 | FDE: 0x0809e0 | Size: 256 bytes
// Khung tháo gỡ #0921 | Địa chỉ PC: 0x1120b0 | Địa chỉ FDE: 0x0809e0 | Kích thước: 256 bytes
//   0x1120b0: AA1E03E2  mov      x2, x30
//   0x1120b4: 940196F4  bl       #0x177c84
//   0x1120b8: AA0203FE  mov      x30, x2
//   0x1120bc: 17FFFD2A  b        #0x111564
static inline uint64_t fde_func_0921_0x1120b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1120b0ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x940196f4ULL) ^ 0x0809e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0922 | PC: 0x11226c | FDE: 0x080a50 | Size: 40 bytes
// Khung tháo gỡ #0922 | Địa chỉ PC: 0x11226c | Địa chỉ FDE: 0x080a50 | Kích thước: 40 bytes
//   0x11226c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x112270: AA0003F3  mov      x19, x0
//   0x112274: 97FFFFFA  bl       #0x11225c
//   0x112278: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0922_0x11226c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11226cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x080a50ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0923 | PC: 0x112294 | FDE: 0x080a80 | Size: 256 bytes [_ZN4lynx6canvas20PlatformViewObserver18OnSurfaceDestroyedERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEm]
// Khung tháo gỡ #0923 | Địa chỉ PC: 0x112294 | Địa chỉ FDE: 0x080a80 | Kích thước: 256 bytes
//   0x112294: D10683FF  sub      sp, sp, #0x1a0
//   0x112298: F900ABFC  str      x28, [sp, #0x150]
//   0x11229c: A91663F9  stp      x25, x24, [sp, #0x160]
//   0x1122a0: A9175BF7  stp      x23, x22, [sp, #0x170]
static inline uint64_t fde_func_0923_0x112294(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x112294ULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xf900abfcULL) ^ 0x080a80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0924 | PC: 0x1125b8 | FDE: 0x080ad0 | Size: 256 bytes
// Khung tháo gỡ #0924 | Địa chỉ PC: 0x1125b8 | Địa chỉ FDE: 0x080ad0 | Kích thước: 256 bytes
//   0x1125b8: F00003E8  adrp     x8, #0x191000
//   0x1125bc: 91088108  add      x8, x8, #0x220
//   0x1125c0: F8008408  str      x8, [x0], #8
//   0x1125c4: 17FFFF20  b        #0x112244
static inline uint64_t fde_func_0924_0x1125b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1125b8ULL ^ (static_cast<uint64_t>(0xf00003e8ULL) << 13);
    acc = (acc + a1 + 0x91088108ULL) ^ 0x080ad0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0925 | PC: 0x1127d4 | FDE: 0x080b48 | Size: 256 bytes
// Khung tháo gỡ #0925 | Địa chỉ PC: 0x1127d4 | Địa chỉ FDE: 0x080b48 | Kích thước: 256 bytes
//   0x1127d4: D105C3FF  sub      sp, sp, #0x170
//   0x1127d8: A9145BFC  stp      x28, x22, [sp, #0x140]
//   0x1127dc: A91553F5  stp      x21, x20, [sp, #0x150]
//   0x1127e0: A9167BF3  stp      x19, x30, [sp, #0x160]
static inline uint64_t fde_func_0925_0x1127d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1127d4ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xa9145bfcULL) ^ 0x080b48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0926 | PC: 0x1129d8 | FDE: 0x080bd0 | Size: 256 bytes
// Khung tháo gỡ #0926 | Địa chỉ PC: 0x1129d8 | Địa chỉ FDE: 0x080bd0 | Kích thước: 256 bytes
//   0x1129d8: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1129dc: 97FFFFD6  bl       #0x112934
//   0x1129e0: B4000120  cbz      x0, #0x112a04
//   0x1129e4: B9402008  ldr      w8, [x0, #0x20]
static inline uint64_t fde_func_0926_0x1129d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1129d8ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x97ffffd6ULL) ^ 0x080bd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0927 | PC: 0x112e94 | FDE: 0x080c60 | Size: 256 bytes
// Khung tháo gỡ #0927 | Địa chỉ PC: 0x112e94 | Địa chỉ FDE: 0x080c60 | Kích thước: 256 bytes
//   0x112e94: AA1E03E1  mov      x1, x30
//   0x112e98: 94018BEC  bl       #0x175e48
//   0x112e9c: AA0103FE  mov      x30, x1
//   0x112ea0: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0927_0x112e94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x112e94ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x94018becULL) ^ 0x080c60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0928 | PC: 0x113734 | FDE: 0x080d08 | Size: 256 bytes
// Khung tháo gỡ #0928 | Địa chỉ PC: 0x113734 | Địa chỉ FDE: 0x080d08 | Kích thước: 256 bytes
//   0x113734: AA1E03E0  mov      x0, x30
//   0x113738: 9401BE9A  bl       #0x1831a0
//   0x11373c: AA0003FE  mov      x30, x0
//   0x113740: A9147BFD  stp      x29, x30, [sp, #0x140]
static inline uint64_t fde_func_0928_0x113734(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x113734ULL ^ (static_cast<uint64_t>(0xaa1e03e0ULL) << 13);
    acc = (acc + a1 + 0x9401be9aULL) ^ 0x080d08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0929 | PC: 0x115830 | FDE: 0x080da0 | Size: 256 bytes
// Khung tháo gỡ #0929 | Địa chỉ PC: 0x115830 | Địa chỉ FDE: 0x080da0 | Kích thước: 256 bytes
//   0x115830: D10143FF  sub      sp, sp, #0x50
//   0x115834: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x115838: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x11583c: 940197B0  bl       #0x17b6fc
static inline uint64_t fde_func_0929_0x115830(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115830ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90353f5ULL) ^ 0x080da0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0930 | PC: 0x115a58 | FDE: 0x080e10 | Size: 256 bytes
// Khung tháo gỡ #0930 | Địa chỉ PC: 0x115a58 | Địa chỉ FDE: 0x080e10 | Kích thước: 256 bytes
//   0x115a58: AA1E03E2  mov      x2, x30
//   0x115a5c: 9401A415  bl       #0x17eab0
//   0x115a60: AA0203FE  mov      x30, x2
//   0x115a64: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_0930_0x115a58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115a58ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9401a415ULL) ^ 0x080e10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0931 | PC: 0x116598 | FDE: 0x080ec0 | Size: 256 bytes
// Khung tháo gỡ #0931 | Địa chỉ PC: 0x116598 | Địa chỉ FDE: 0x080ec0 | Kích thước: 256 bytes
//   0x116598: D105C3FF  sub      sp, sp, #0x170
//   0x11659c: 6D1023E9  stp      d9, d8, [sp, #0x100]
//   0x1165a0: A9116FFC  stp      x28, x27, [sp, #0x110]
//   0x1165a4: A91267FA  stp      x26, x25, [sp, #0x120]
static inline uint64_t fde_func_0931_0x116598(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x116598ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0x6d1023e9ULL) ^ 0x080ec0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0932 | PC: 0x116e04 | FDE: 0x080f50 | Size: 256 bytes
// Khung tháo gỡ #0932 | Địa chỉ PC: 0x116e04 | Địa chỉ FDE: 0x080f50 | Kích thước: 256 bytes
//   0x116e04: FC1D0FE8  str      d8, [sp, #-0x30]!
//   0x116e08: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x116e0c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x116e10: 94017C64  bl       #0x175fa0
static inline uint64_t fde_func_0932_0x116e04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x116e04ULL ^ (static_cast<uint64_t>(0xfc1d0fe8ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x080f50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0933 | PC: 0x116fb0 | FDE: 0x080fc0 | Size: 256 bytes
// Khung tháo gỡ #0933 | Địa chỉ PC: 0x116fb0 | Địa chỉ FDE: 0x080fc0 | Kích thước: 256 bytes
//   0x116fb0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x116fb4: B9402008  ldr      w8, [x0, #0x20]
//   0x116fb8: AA0003F3  mov      x19, x0
//   0x116fbc: 340000A8  cbz      w8, #0x116fd0
static inline uint64_t fde_func_0933_0x116fb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x116fb0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb9402008ULL) ^ 0x080fc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0934 | PC: 0x117114 | FDE: 0x081020 | Size: 256 bytes
// Khung tháo gỡ #0934 | Địa chỉ PC: 0x117114 | Địa chỉ FDE: 0x081020 | Kích thước: 256 bytes
//   0x117114: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x117118: B9402008  ldr      w8, [x0, #0x20]
//   0x11711c: AA0003F3  mov      x19, x0
//   0x117120: 350000C8  cbnz     w8, #0x117138
static inline uint64_t fde_func_0934_0x117114(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x117114ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb9402008ULL) ^ 0x081020ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0935 | PC: 0x11849c | FDE: 0x081098 | Size: 256 bytes
// Khung tháo gỡ #0935 | Địa chỉ PC: 0x11849c | Địa chỉ FDE: 0x081098 | Kích thước: 256 bytes
//   0x11849c: AA1F03E8  mov      x8, xzr
//   0x1184a0: EB28405F  cmp      x2, w8, uxtw
//   0x1184a4: 54000169  b.ls     #0x1184d0
//   0x1184a8: 8B080009  add      x9, x0, x8
static inline uint64_t fde_func_0935_0x11849c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11849cULL ^ (static_cast<uint64_t>(0xaa1f03e8ULL) << 13);
    acc = (acc + a1 + 0xeb28405fULL) ^ 0x081098ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0936 | PC: 0x1185e4 | FDE: 0x0810f8 | Size: 236 bytes
// Khung tháo gỡ #0936 | Địa chỉ PC: 0x1185e4 | Địa chỉ FDE: 0x0810f8 | Kích thước: 236 bytes
//   0x1185e4: D10543FF  sub      sp, sp, #0x150
//   0x1185e8: A91353FC  stp      x28, x20, [sp, #0x130]
//   0x1185ec: A9147BF3  stp      x19, x30, [sp, #0x140]
//   0x1185f0: D53BD053  mrs      x19, tpidr_el0
static inline uint64_t fde_func_0936_0x1185e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1185e4ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa91353fcULL) ^ 0x0810f8ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0937 | PC: 0x1186d0 | FDE: 0x081160 | Size: 256 bytes
// Khung tháo gỡ #0937 | Địa chỉ PC: 0x1186d0 | Địa chỉ FDE: 0x081160 | Kích thước: 256 bytes
//   0x1186d0: AA1F03E8  mov      x8, xzr
//   0x1186d4: EB28405F  cmp      x2, w8, uxtw
//   0x1186d8: 54000129  b.ls     #0x1186fc
//   0x1186dc: 8B080009  add      x9, x0, x8
static inline uint64_t fde_func_0937_0x1186d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1186d0ULL ^ (static_cast<uint64_t>(0xaa1f03e8ULL) << 13);
    acc = (acc + a1 + 0xeb28405fULL) ^ 0x081160ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0938 | PC: 0x1187d4 | FDE: 0x0811c0 | Size: 256 bytes
// Khung tháo gỡ #0938 | Địa chỉ PC: 0x1187d4 | Địa chỉ FDE: 0x0811c0 | Kích thước: 256 bytes
//   0x1187d4: D10543FF  sub      sp, sp, #0x150
//   0x1187d8: A91353FC  stp      x28, x20, [sp, #0x130]
//   0x1187dc: A9147BF3  stp      x19, x30, [sp, #0x140]
//   0x1187e0: D53BD053  mrs      x19, tpidr_el0
static inline uint64_t fde_func_0938_0x1187d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1187d4ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa91353fcULL) ^ 0x0811c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0939 | PC: 0x11891c | FDE: 0x081240 | Size: 256 bytes
// Khung tháo gỡ #0939 | Địa chỉ PC: 0x11891c | Địa chỉ FDE: 0x081240 | Kích thước: 256 bytes
//   0x11891c: AA1F03E8  mov      x8, xzr
//   0x118920: EB28405F  cmp      x2, w8, uxtw
//   0x118924: 540001A9  b.ls     #0x118958
//   0x118928: 8B080009  add      x9, x0, x8
static inline uint64_t fde_func_0939_0x11891c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11891cULL ^ (static_cast<uint64_t>(0xaa1f03e8ULL) << 13);
    acc = (acc + a1 + 0xeb28405fULL) ^ 0x081240ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0940 | PC: 0x119000 | FDE: 0x0812c0 | Size: 256 bytes
// Khung tháo gỡ #0940 | Địa chỉ PC: 0x119000 | Địa chỉ FDE: 0x0812c0 | Kích thước: 256 bytes
//   0x119000: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x119004: 97FFFE9A  bl       #0x118a6c
//   0x119008: F84107FE  ldr      x30, [sp], #0x10
//   0x11900c: 14000001  b        #0x119010
static inline uint64_t fde_func_0940_0x119000(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119000ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x97fffe9aULL) ^ 0x0812c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0941 | PC: 0x1195ec | FDE: 0x081340 | Size: 28 bytes
// Khung tháo gỡ #0941 | Địa chỉ PC: 0x1195ec | Địa chỉ FDE: 0x081340 | Kích thước: 28 bytes
//   0x1195ec: B5000042  cbnz     x2, #0x1195f4
//   0x1195f0: F9400422  ldr      x2, [x1, #8]
//   0x1195f4: F9400028  ldr      x8, [x1]
//   0x1195f8: F900003F  str      xzr, [x1]
static inline uint64_t fde_func_0941_0x1195ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1195ecULL ^ (static_cast<uint64_t>(0xb5000042ULL) << 13);
    acc = (acc + a1 + 0xf9400422ULL) ^ 0x081340ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0942 | PC: 0x119608 | FDE: 0x081358 | Size: 252 bytes [_ZN4lynx6canvas45WrapDataPtrToArrayBufferWithOwnershipTransferEN4Napi3EnvEPvm]
// Khung tháo gỡ #0942 | Địa chỉ PC: 0x119608 | Địa chỉ FDE: 0x081358 | Kích thước: 252 bytes
//   0x119608: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x11960c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x119610: 94017D17  bl       #0x178a6c
//   0x119614: 97FE6089  bl       #0xb1838
static inline uint64_t fde_func_0942_0x119608(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119608ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x081358ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0943 | PC: 0x119704 | FDE: 0x0813a8 | Size: 188 bytes [_ZN4lynx6canvas11MediaStreamC2ENS1_4TypeENSt6__ndk110unique_ptrINS0_12VideoContextENS3_14default_deleteIS5_EEEE]
// Khung tháo gỡ #0943 | Địa chỉ PC: 0x119704 | Địa chỉ FDE: 0x0813a8 | Kích thước: 188 bytes
//   0x119704: D10103FF  sub      sp, sp, #0x40
//   0x119708: F9000BF6  str      x22, [sp, #0x10]
//   0x11970c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x119710: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0943_0x119704(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119704ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x0813a8ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0944 | PC: 0x1197c0 | FDE: 0x0813c8 | Size: 160 bytes [_ZN4lynx6canvas11MediaStream7DisposeEv]
// Khung tháo gỡ #0944 | Địa chỉ PC: 0x1197c0 | Địa chỉ FDE: 0x0813c8 | Kích thước: 160 bytes
//   0x1197c0: D10543FF  sub      sp, sp, #0x150
//   0x1197c4: A91353FC  stp      x28, x20, [sp, #0x130]
//   0x1197c8: A9147BF3  stp      x19, x30, [sp, #0x140]
//   0x1197cc: D53BD053  mrs      x19, tpidr_el0
static inline uint64_t fde_func_0944_0x1197c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1197c0ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa91353fcULL) ^ 0x0813c8ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0945 | PC: 0x119860 | FDE: 0x081418 | Size: 188 bytes [_ZN4lynx6canvas11MediaStream16SetBeautifyParamEffff]
// Khung tháo gỡ #0945 | Địa chỉ PC: 0x119860 | Địa chỉ FDE: 0x081418 | Kích thước: 188 bytes
//   0x119860: D105C3FF  sub      sp, sp, #0x170
//   0x119864: 6D132BEB  stp      d11, d10, [sp, #0x130]
//   0x119868: 6D1423E9  stp      d9, d8, [sp, #0x140]
//   0x11986c: A91553FC  stp      x28, x20, [sp, #0x150]
static inline uint64_t fde_func_0945_0x119860(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119860ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0x6d132bebULL) ^ 0x081418ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0946 | PC: 0x11991c | FDE: 0x081448 | Size: 252 bytes [_ZN4lynx6canvas12VideoContextC2ERKNSt6__ndk110shared_ptrINS0_9CanvasAppEEE]
// Khung tháo gỡ #0946 | Địa chỉ PC: 0x11991c | Địa chỉ FDE: 0x081448 | Kích thước: 252 bytes
//   0x11991c: D10103FF  sub      sp, sp, #0x40
//   0x119920: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x119924: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x119928: 900003E8  adrp     x8, #0x195000
static inline uint64_t fde_func_0946_0x11991c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11991cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x081448ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0947 | PC: 0x119a18 | FDE: 0x081498 | Size: 88 bytes
// Khung tháo gỡ #0947 | Địa chỉ PC: 0x119a18 | Địa chỉ FDE: 0x081498 | Kích thước: 88 bytes
//   0x119a18: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x119a1c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x119a20: 91004013  add      x19, x0, #0x10
//   0x119a24: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0947_0x119a18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119a18ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x081498ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0948 | PC: 0x119a70 | FDE: 0x0814d8 | Size: 28 bytes [_ZN4lynx6canvas12VideoContext10AutoResumeEv]
// Khung tháo gỡ #0948 | Địa chỉ PC: 0x119a70 | Địa chỉ FDE: 0x0814d8 | Kích thước: 28 bytes
//   0x119a70: 39408408  ldrb     w8, [x0, #0x21]
//   0x119a74: 340000A8  cbz      w8, #0x119a88
//   0x119a78: 39408008  ldrb     w8, [x0, #0x20]
//   0x119a7c: 3900841F  strb     wzr, [x0, #0x21]
static inline uint64_t fde_func_0948_0x119a70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119a70ULL ^ (static_cast<uint64_t>(0x39408408ULL) << 13);
    acc = (acc + a1 + 0x340000a8ULL) ^ 0x0814d8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0949 | PC: 0x119a8c | FDE: 0x0814f0 | Size: 24 bytes [_ZN4lynx6canvas12VideoContext9AutoPauseEv]
// Khung tháo gỡ #0949 | Địa chỉ PC: 0x119a8c | Địa chỉ FDE: 0x0814f0 | Kích thước: 24 bytes
//   0x119a8c: 39408008  ldrb     w8, [x0, #0x20]
//   0x119a90: 52800029  mov      w9, #1
//   0x119a94: 39008409  strb     w9, [x0, #0x21]
//   0x119a98: 34000048  cbz      w8, #0x119aa0
static inline uint64_t fde_func_0949_0x119a8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119a8cULL ^ (static_cast<uint64_t>(0x39408008ULL) << 13);
    acc = (acc + a1 + 0x52800029ULL) ^ 0x0814f0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0950 | PC: 0x119aa4 | FDE: 0x081508 | Size: 96 bytes [_ZN4lynx6canvas12VideoContextD1Ev]
// Khung tháo gỡ #0950 | Địa chỉ PC: 0x119aa4 | Địa chỉ FDE: 0x081508 | Kích thước: 96 bytes
//   0x119aa4: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x119aa8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x119aac: 900003E8  adrp     x8, #0x195000
//   0x119ab0: F9403815  ldr      x21, [x0, #0x70]
static inline uint64_t fde_func_0950_0x119aa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119aa4ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x081508ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0951 | PC: 0x119b04 | FDE: 0x081528 | Size: 72 bytes [_ZN4lynx6canvas12VideoContext11NotifyStateENS1_5StateE]
// Khung tháo gỡ #0951 | Địa chỉ PC: 0x119b04 | Địa chỉ FDE: 0x081528 | Kích thước: 72 bytes
//   0x119b04: D10103FF  sub      sp, sp, #0x40
//   0x119b08: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x119b0c: 94017382  bl       #0x176914
//   0x119b10: F90017E8  str      x8, [sp, #0x28]
static inline uint64_t fde_func_0951_0x119b04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119b04ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9037bf3ULL) ^ 0x081528ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0952 | PC: 0x119b4c | FDE: 0x081540 | Size: 92 bytes [_ZN4lynx6canvas12VideoContext27NotifyStateWithExtraMessageENS1_5StateENSt6__ndk18optionalINS3_12basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEEE]
// Khung tháo gỡ #0952 | Địa chỉ PC: 0x119b4c | Địa chỉ FDE: 0x081540 | Kích thước: 92 bytes
//   0x119b4c: D10143FF  sub      sp, sp, #0x50
//   0x119b50: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x119b54: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x119b58: D53BD055  mrs      x21, tpidr_el0
static inline uint64_t fde_func_0952_0x119b4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119b4cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90353f5ULL) ^ 0x081540ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0953 | PC: 0x119ba8 | FDE: 0x081560 | Size: 64 bytes [_ZN4lynx6canvas12VideoContext6DoPlayEv]
// Khung tháo gỡ #0953 | Địa chỉ PC: 0x119ba8 | Địa chỉ FDE: 0x081560 | Kích thước: 64 bytes
//   0x119ba8: D10543FF  sub      sp, sp, #0x150
//   0x119bac: A91353FC  stp      x28, x20, [sp, #0x130]
//   0x119bb0: A9147BF3  stp      x19, x30, [sp, #0x140]
//   0x119bb4: 9401A61B  bl       #0x183420
static inline uint64_t fde_func_0953_0x119ba8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119ba8ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa91353fcULL) ^ 0x081560ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0954 | PC: 0x119be8 | FDE: 0x081580 | Size: 64 bytes [_ZN4lynx6canvas12VideoContext7DoPauseEv]
// Khung tháo gỡ #0954 | Địa chỉ PC: 0x119be8 | Địa chỉ FDE: 0x081580 | Kích thước: 64 bytes
//   0x119be8: D10543FF  sub      sp, sp, #0x150
//   0x119bec: A91353FC  stp      x28, x20, [sp, #0x130]
//   0x119bf0: A9147BF3  stp      x19, x30, [sp, #0x140]
//   0x119bf4: 9401A60B  bl       #0x183420
static inline uint64_t fde_func_0954_0x119be8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119be8ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa91353fcULL) ^ 0x081580ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0955 | PC: 0x119c28 | FDE: 0x0815a0 | Size: 256 bytes [_ZN4lynx6canvas12VideoContext21RegisterStateListenerENSt6__ndk18functionIFvNS1_5StateENS2_8optionalINS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEEEEEE]
// Khung tháo gỡ #0955 | Địa chỉ PC: 0x119c28 | Địa chỉ FDE: 0x0815a0 | Kích thước: 256 bytes
//   0x119c28: D10243FF  sub      sp, sp, #0x90
//   0x119c2c: F90033F6  str      x22, [sp, #0x60]
//   0x119c30: A90753F5  stp      x21, x20, [sp, #0x70]
//   0x119c34: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_0955_0x119c28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119c28ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90033f6ULL) ^ 0x0815a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0956 | PC: 0x119d84 | FDE: 0x0815c0 | Size: 24 bytes [_ZN4lynx6canvas12VideoContext4PlayEv]
// Khung tháo gỡ #0956 | Địa chỉ PC: 0x119d84 | Địa chỉ FDE: 0x0815c0 | Kích thước: 24 bytes
//   0x119d84: 39408408  ldrb     w8, [x0, #0x21]
//   0x119d88: 52800029  mov      w9, #1
//   0x119d8c: 39008009  strb     w9, [x0, #0x20]
//   0x119d90: 34000048  cbz      w8, #0x119d98
static inline uint64_t fde_func_0956_0x119d84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119d84ULL ^ (static_cast<uint64_t>(0x39408408ULL) << 13);
    acc = (acc + a1 + 0x52800029ULL) ^ 0x0815c0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0957 | PC: 0x119d9c | FDE: 0x0815d8 | Size: 28 bytes [_ZN4lynx6canvas12VideoContext5PauseEv]
// Khung tháo gỡ #0957 | Địa chỉ PC: 0x119d9c | Địa chỉ FDE: 0x0815d8 | Kích thước: 28 bytes
//   0x119d9c: 39408008  ldrb     w8, [x0, #0x20]
//   0x119da0: 340000A8  cbz      w8, #0x119db4
//   0x119da4: F9400008  ldr      x8, [x0]
//   0x119da8: 3900801F  strb     wzr, [x0, #0x20]
static inline uint64_t fde_func_0957_0x119d9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119d9cULL ^ (static_cast<uint64_t>(0x39408008ULL) << 13);
    acc = (acc + a1 + 0x340000a8ULL) ^ 0x0815d8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0958 | PC: 0x119db8 | FDE: 0x0815f0 | Size: 256 bytes
// Khung tháo gỡ #0958 | Địa chỉ PC: 0x119db8 | Địa chỉ FDE: 0x0815f0 | Kích thước: 256 bytes
//   0x119db8: D10583FF  sub      sp, sp, #0x160
//   0x119dbc: F9009BFC  str      x28, [sp, #0x130]
//   0x119dc0: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x119dc4: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0958_0x119db8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119db8ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x0815f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0959 | PC: 0x119fcc | FDE: 0x081650 | Size: 32 bytes [_ZN4lynx6canvas12VideoElement8GetWidthEv]
// Khung tháo gỡ #0959 | Địa chỉ PC: 0x119fcc | Địa chỉ FDE: 0x081650 | Kích thước: 32 bytes
//   0x119fcc: F9405808  ldr      x8, [x0, #0xb0]
//   0x119fd0: B4000088  cbz      x8, #0x119fe0
//   0x119fd4: B940D000  ldr      w0, [x0, #0xd0]
//   0x119fd8: 34000060  cbz      w0, #0x119fe4
static inline uint64_t fde_func_0959_0x119fcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119fccULL ^ (static_cast<uint64_t>(0xf9405808ULL) << 13);
    acc = (acc + a1 + 0xb4000088ULL) ^ 0x081650ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0960 | PC: 0x119fec | FDE: 0x081668 | Size: 32 bytes [_ZN4lynx6canvas12VideoElement9GetHeightEv]
// Khung tháo gỡ #0960 | Địa chỉ PC: 0x119fec | Địa chỉ FDE: 0x081668 | Kích thước: 32 bytes
//   0x119fec: F9405808  ldr      x8, [x0, #0xb0]
//   0x119ff0: B4000088  cbz      x8, #0x11a000
//   0x119ff4: B940D400  ldr      w0, [x0, #0xd4]
//   0x119ff8: 34000060  cbz      w0, #0x11a004
static inline uint64_t fde_func_0960_0x119fec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119fecULL ^ (static_cast<uint64_t>(0xf9405808ULL) << 13);
    acc = (acc + a1 + 0xb4000088ULL) ^ 0x081668ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0961 | PC: 0x11a00c | FDE: 0x081680 | Size: 256 bytes [_ZN4lynx6canvas12VideoElement16GetTextureSourceEv]
// Khung tháo gỡ #0961 | Địa chỉ PC: 0x11a00c | Địa chỉ FDE: 0x081680 | Kích thước: 256 bytes
//   0x11a00c: F9405800  ldr      x0, [x0, #0xb0]
//   0x11a010: B4000080  cbz      x0, #0x11a020
//   0x11a014: F9400009  ldr      x9, [x0]
//   0x11a018: F9400D21  ldr      x1, [x9, #0x18]
static inline uint64_t fde_func_0961_0x11a00c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a00cULL ^ (static_cast<uint64_t>(0xf9405800ULL) << 13);
    acc = (acc + a1 + 0xb4000080ULL) ^ 0x081680ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0962 | PC: 0x11a134 | FDE: 0x0816d8 | Size: 64 bytes
// Khung tháo gỡ #0962 | Địa chỉ PC: 0x11a134 | Địa chỉ FDE: 0x0816d8 | Kích thước: 64 bytes
//   0x11a134: D1012000  sub      x0, x0, #0x48
//   0x11a138: 17FFFF63  b        #0x119ec4
//   0x11a13c: D1012000  sub      x0, x0, #0x48
//   0x11a140: 17FFFF9D  b        #0x119fb4
static inline uint64_t fde_func_0962_0x11a134(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a134ULL ^ (static_cast<uint64_t>(0xd1012000ULL) << 13);
    acc = (acc + a1 + 0x17ffff63ULL) ^ 0x0816d8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0963 | PC: 0x11a174 | FDE: 0x081738 | Size: 256 bytes
// Khung tháo gỡ #0963 | Địa chỉ PC: 0x11a174 | Địa chỉ FDE: 0x081738 | Kích thước: 256 bytes
//   0x11a174: AA1E03E2  mov      x2, x30
//   0x11a178: 94016F34  bl       #0x175e48
//   0x11a17c: AA0203FE  mov      x30, x2
//   0x11a180: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0963_0x11a174(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a174ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94016f34ULL) ^ 0x081738ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0964 | PC: 0x11a75c | FDE: 0x0817b8 | Size: 128 bytes
// Khung tháo gỡ #0964 | Địa chỉ PC: 0x11a75c | Địa chỉ FDE: 0x0817b8 | Kích thước: 128 bytes
//   0x11a75c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x11a760: AA0003F3  mov      x19, x0
//   0x11a764: 94017537  bl       #0x177c40
//   0x11a768: F00003A8  adrp     x8, #0x191000
static inline uint64_t fde_func_0964_0x11a75c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a75cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0817b8ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0965 | PC: 0x11a7dc | FDE: 0x081818 | Size: 256 bytes
// Khung tháo gỡ #0965 | Địa chỉ PC: 0x11a7dc | Địa chỉ FDE: 0x081818 | Kích thước: 256 bytes
//   0x11a7dc: D10483FF  sub      sp, sp, #0x120
//   0x11a7e0: A90E63FC  stp      x28, x24, [sp, #0xe0]
//   0x11a7e4: A90F5BF7  stp      x23, x22, [sp, #0xf0]
//   0x11a7e8: A91053F5  stp      x21, x20, [sp, #0x100]
static inline uint64_t fde_func_0965_0x11a7dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a7dcULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90e63fcULL) ^ 0x081818ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0966 | PC: 0x11acc4 | FDE: 0x081898 | Size: 80 bytes
// Khung tháo gỡ #0966 | Địa chỉ PC: 0x11acc4 | Địa chỉ FDE: 0x081898 | Kích thước: 80 bytes
//   0x11acc4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x11acc8: 94019939  bl       #0x1811ac
//   0x11accc: 97FE41E1  bl       #0xab450
//   0x11acd0: F9400A60  ldr      x0, [x19, #0x10]
static inline uint64_t fde_func_0966_0x11acc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11acc4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94019939ULL) ^ 0x081898ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0967 | PC: 0x11ad14 | FDE: 0x0818f8 | Size: 256 bytes
// Khung tháo gỡ #0967 | Địa chỉ PC: 0x11ad14 | Địa chỉ FDE: 0x0818f8 | Kích thước: 256 bytes
//   0x11ad14: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x11ad18: B0FFF9C1  adrp     x1, #0x53000
//   0x11ad1c: 913DB421  add      x1, x1, #0xf6d
//   0x11ad20: 97FE40AB  bl       #0xaafcc
static inline uint64_t fde_func_0967_0x11ad14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ad14ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb0fff9c1ULL) ^ 0x0818f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0968 | PC: 0x11af8c | FDE: 0x081970 | Size: 184 bytes
// Khung tháo gỡ #0968 | Địa chỉ PC: 0x11af8c | Địa chỉ FDE: 0x081970 | Kích thước: 184 bytes
//   0x11af8c: B9408008  ldr      w8, [x0, #0x80]
//   0x11af90: 7100051F  cmp      w8, #1
//   0x11af94: 540000A0  b.eq     #0x11afa8
//   0x11af98: 35000108  cbnz     w8, #0x11afb8
static inline uint64_t fde_func_0968_0x11af8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11af8cULL ^ (static_cast<uint64_t>(0xb9408008ULL) << 13);
    acc = (acc + a1 + 0x7100051fULL) ^ 0x081970ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0969 | PC: 0x11b044 | FDE: 0x0819d0 | Size: 208 bytes
// Khung tháo gỡ #0969 | Địa chỉ PC: 0x11b044 | Địa chỉ FDE: 0x0819d0 | Kích thước: 208 bytes
//   0x11b044: B9408008  ldr      w8, [x0, #0x80]
//   0x11b048: 7100051F  cmp      w8, #1
//   0x11b04c: 540000A0  b.eq     #0x11b060
//   0x11b050: 35000148  cbnz     w8, #0x11b078
static inline uint64_t fde_func_0969_0x11b044(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b044ULL ^ (static_cast<uint64_t>(0xb9408008ULL) << 13);
    acc = (acc + a1 + 0x7100051fULL) ^ 0x0819d0ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0970 | PC: 0x11b114 | FDE: 0x081a30 | Size: 256 bytes
// Khung tháo gỡ #0970 | Địa chỉ PC: 0x11b114 | Địa chỉ FDE: 0x081a30 | Kích thước: 256 bytes
//   0x11b114: AA0003E8  mov      x8, x0
//   0x11b118: F9405800  ldr      x0, [x0, #0xb0]
//   0x11b11c: B40000A0  cbz      x0, #0x11b130
//   0x11b120: B9408108  ldr      w8, [x8, #0x80]
static inline uint64_t fde_func_0970_0x11b114(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b114ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xf9405800ULL) ^ 0x081a30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0971 | PC: 0x11b25c | FDE: 0x081aa0 | Size: 256 bytes
// Khung tháo gỡ #0971 | Địa chỉ PC: 0x11b25c | Địa chỉ FDE: 0x081aa0 | Kích thước: 256 bytes
//   0x11b25c: FC1C0FEC  str      d12, [sp, #-0x40]!
//   0x11b260: 6D00ABEB  stp      d11, d10, [sp, #8]
//   0x11b264: 6D01A3E9  stp      d9, d8, [sp, #0x18]
//   0x11b268: F90017F4  str      x20, [sp, #0x28]
static inline uint64_t fde_func_0971_0x11b25c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b25cULL ^ (static_cast<uint64_t>(0xfc1c0fecULL) << 13);
    acc = (acc + a1 + 0x6d00abebULL) ^ 0x081aa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0972 | PC: 0x11b600 | FDE: 0x081b48 | Size: 256 bytes
// Khung tháo gỡ #0972 | Địa chỉ PC: 0x11b600 | Địa chỉ FDE: 0x081b48 | Kích thước: 256 bytes
//   0x11b600: FC1C0FEC  str      d12, [sp, #-0x40]!
//   0x11b604: 6D00ABEB  stp      d11, d10, [sp, #8]
//   0x11b608: 6D01A3E9  stp      d9, d8, [sp, #0x18]
//   0x11b60c: F90017F4  str      x20, [sp, #0x28]
static inline uint64_t fde_func_0972_0x11b600(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b600ULL ^ (static_cast<uint64_t>(0xfc1c0fecULL) << 13);
    acc = (acc + a1 + 0x6d00abebULL) ^ 0x081b48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0973 | PC: 0x11b758 | FDE: 0x081bc8 | Size: 256 bytes
// Khung tháo gỡ #0973 | Địa chỉ PC: 0x11b758 | Địa chỉ FDE: 0x081bc8 | Kích thước: 256 bytes
//   0x11b758: D10103FF  sub      sp, sp, #0x40
//   0x11b75c: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x11b760: 94016C6D  bl       #0x176914
//   0x11b764: 910023E2  add      x2, sp, #8
static inline uint64_t fde_func_0973_0x11b758(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b758ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9037bf3ULL) ^ 0x081bc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0974 | PC: 0x11b85c | FDE: 0x081c30 | Size: 256 bytes
// Khung tháo gỡ #0974 | Địa chỉ PC: 0x11b85c | Địa chỉ FDE: 0x081c30 | Kích thước: 256 bytes
//   0x11b85c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x11b860: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x11b864: 39420008  ldrb     w8, [x0, #0x80]
//   0x11b868: 12000034  and      w20, w1, #1
static inline uint64_t fde_func_0974_0x11b85c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b85cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x081c30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0975 | PC: 0x11bd14 | FDE: 0x081cc0 | Size: 228 bytes
// Khung tháo gỡ #0975 | Địa chỉ PC: 0x11bd14 | Địa chỉ FDE: 0x081cc0 | Kích thước: 228 bytes
//   0x11bd14: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x11bd18: AA0003F3  mov      x19, x0
//   0x11bd1c: 97FFFFFA  bl       #0x11bd04
//   0x11bd20: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0975_0x11bd14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11bd14ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x081cc0ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0976 | PC: 0x11bdf8 | FDE: 0x081d28 | Size: 216 bytes
// Khung tháo gỡ #0976 | Địa chỉ PC: 0x11bdf8 | Địa chỉ FDE: 0x081d28 | Kích thước: 216 bytes
//   0x11bdf8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x11bdfc: AA0003F3  mov      x19, x0
//   0x11be00: 97FFFFE2  bl       #0x11bd88
//   0x11be04: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0976_0x11bdf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11bdf8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x081d28ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #0977 | PC: 0x11bed0 | FDE: 0x081d98 | Size: 256 bytes
// Khung tháo gỡ #0977 | Địa chỉ PC: 0x11bed0 | Địa chỉ FDE: 0x081d98 | Kích thước: 256 bytes
//   0x11bed0: AA1E03E2  mov      x2, x30
//   0x11bed4: 94019655  bl       #0x181828
//   0x11bed8: AA0203FE  mov      x30, x2
//   0x11bedc: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_0977_0x11bed0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11bed0ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94019655ULL) ^ 0x081d98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0978 | PC: 0x11c1e8 | FDE: 0x081e28 | Size: 224 bytes
// Khung tháo gỡ #0978 | Địa chỉ PC: 0x11c1e8 | Địa chỉ FDE: 0x081e28 | Kích thước: 224 bytes
//   0x11c1e8: FD405800  ldr      d0, [x0, #0xb0]
//   0x11c1ec: D65F03C0  ret      
//   0x11c1f0: D10483FF  sub      sp, sp, #0x120
//   0x11c1f4: F90083FC  str      x28, [sp, #0x100]
static inline uint64_t fde_func_0978_0x11c1e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11c1e8ULL ^ (static_cast<uint64_t>(0xfd405800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x081e28ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #0979 | PC: 0x11c2c8 | FDE: 0x081e98 | Size: 8 bytes
// Khung tháo gỡ #0979 | Địa chỉ PC: 0x11c2c8 | Địa chỉ FDE: 0x081e98 | Kích thước: 8 bytes
//   0x11c2c8: F9401800  ldr      x0, [x0, #0x30]
//   0x11c2cc: D65F03C0  ret      
static inline uint64_t fde_func_0979_0x11c2c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11c2c8ULL ^ (static_cast<uint64_t>(0xf9401800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x081e98ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0980 | PC: 0x11c2d0 | FDE: 0x081eb0 | Size: 232 bytes [_ZN4lynx6canvas10NapiWorker12ToImplUnsafeEv]
// Khung tháo gỡ #0980 | Địa chỉ PC: 0x11c2d0 | Địa chỉ FDE: 0x081eb0 | Kích thước: 232 bytes
//   0x11c2d0: F9401C00  ldr      x0, [x0, #0x38]
//   0x11c2d4: D65F03C0  ret      
//   0x11c2d8: B4000141  cbz      x1, #0x11c300
//   0x11c2dc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
static inline uint64_t fde_func_0980_0x11c2d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11c2d0ULL ^ (static_cast<uint64_t>(0xf9401c00ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x081eb0ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0981 | PC: 0x11c3b8 | FDE: 0x081f00 | Size: 256 bytes
// Khung tháo gỡ #0981 | Địa chỉ PC: 0x11c3b8 | Địa chỉ FDE: 0x081f00 | Kích thước: 256 bytes
//   0x11c3b8: D10143FF  sub      sp, sp, #0x50
//   0x11c3bc: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x11c3c0: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x11c3c4: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0981_0x11c3b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11c3b8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x081f00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0982 | PC: 0x11c678 | FDE: 0x081f80 | Size: 136 bytes
// Khung tháo gỡ #0982 | Địa chỉ PC: 0x11c678 | Địa chỉ FDE: 0x081f80 | Kích thước: 136 bytes
//   0x11c678: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x11c67c: 94016F76  bl       #0x178454
//   0x11c680: B4000061  cbz      x1, #0x11c68c
//   0x11c684: 940168B0  bl       #0x176944
static inline uint64_t fde_func_0982_0x11c678(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11c678ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94016f76ULL) ^ 0x081f80ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0983 | PC: 0x11c700 | FDE: 0x081fe8 | Size: 256 bytes
// Khung tháo gỡ #0983 | Địa chỉ PC: 0x11c700 | Địa chỉ FDE: 0x081fe8 | Kích thước: 256 bytes
//   0x11c700: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x11c704: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x11c708: B9400C08  ldr      w8, [x0, #0xc]
//   0x11c70c: 7100011F  cmp      w8, #0
static inline uint64_t fde_func_0983_0x11c700(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11c700ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x081fe8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0984 | PC: 0x11cd28 | FDE: 0x082080 | Size: 256 bytes
// Khung tháo gỡ #0984 | Địa chỉ PC: 0x11cd28 | Địa chỉ FDE: 0x082080 | Kích thước: 256 bytes
//   0x11cd28: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x11cd2c: AA0003F3  mov      x19, x0
//   0x11cd30: 97FFFFDB  bl       #0x11cc9c
//   0x11cd34: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0984_0x11cd28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11cd28ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x082080ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0985 | PC: 0x11cf34 | FDE: 0x082100 | Size: 96 bytes
// Khung tháo gỡ #0985 | Địa chỉ PC: 0x11cf34 | Địa chỉ FDE: 0x082100 | Kích thước: 96 bytes
//   0x11cf34: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x11cf38: 94018426  bl       #0x17dfd0
//   0x11cf3c: B00003A8  adrp     x8, #0x191000
//   0x11cf40: 91208108  add      x8, x8, #0x820
static inline uint64_t fde_func_0985_0x11cf34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11cf34ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94018426ULL) ^ 0x082100ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0986 | PC: 0x11cf94 | FDE: 0x082160 | Size: 256 bytes
// Khung tháo gỡ #0986 | Địa chỉ PC: 0x11cf94 | Địa chỉ FDE: 0x082160 | Kích thước: 256 bytes
//   0x11cf94: D10103FF  sub      sp, sp, #0x40
//   0x11cf98: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x11cf9c: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x11cfa0: 940163B0  bl       #0x175e60
static inline uint64_t fde_func_0986_0x11cf94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11cf94ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x082160ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0987 | PC: 0x11d4f0 | FDE: 0x0821e8 | Size: 256 bytes
// Khung tháo gỡ #0987 | Địa chỉ PC: 0x11d4f0 | Địa chỉ FDE: 0x0821e8 | Kích thước: 256 bytes
//   0x11d4f0: AA1E03E1  mov      x1, x30
//   0x11d4f4: 94016502  bl       #0x1768fc
//   0x11d4f8: AA0103FE  mov      x30, x1
//   0x11d4fc: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0987_0x11d4f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11d4f0ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x94016502ULL) ^ 0x0821e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0988 | PC: 0x11dac4 | FDE: 0x082270 | Size: 256 bytes
// Khung tháo gỡ #0988 | Địa chỉ PC: 0x11dac4 | Địa chỉ FDE: 0x082270 | Kích thước: 256 bytes
//   0x11dac4: D10183FF  sub      sp, sp, #0x60
//   0x11dac8: FD001BE8  str      d8, [sp, #0x30]
//   0x11dacc: F9001FF6  str      x22, [sp, #0x38]
//   0x11dad0: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0988_0x11dac4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11dac4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xfd001be8ULL) ^ 0x082270ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0989 | PC: 0x11dcfc | FDE: 0x0822f0 | Size: 256 bytes
// Khung tháo gỡ #0989 | Địa chỉ PC: 0x11dcfc | Địa chỉ FDE: 0x0822f0 | Kích thước: 256 bytes
//   0x11dcfc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x11dd00: AA0003F3  mov      x19, x0
//   0x11dd04: 97FFFFFA  bl       #0x11dcec
//   0x11dd08: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0989_0x11dcfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11dcfcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0822f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0990 | PC: 0x11e024 | FDE: 0x082368 | Size: 256 bytes
// Khung tháo gỡ #0990 | Địa chỉ PC: 0x11e024 | Địa chỉ FDE: 0x082368 | Kích thước: 256 bytes
//   0x11e024: AA1E03E2  mov      x2, x30
//   0x11e028: 94017BF8  bl       #0x17d008
//   0x11e02c: AA0203FE  mov      x30, x2
//   0x11e030: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0990_0x11e024(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e024ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94017bf8ULL) ^ 0x082368ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0991 | PC: 0x11e37c | FDE: 0x0823e8 | Size: 144 bytes
// Khung tháo gỡ #0991 | Địa chỉ PC: 0x11e37c | Địa chỉ FDE: 0x0823e8 | Kích thước: 144 bytes
//   0x11e37c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x11e380: B4000140  cbz      x0, #0x11e3a8
//   0x11e384: AA0003F3  mov      x19, x0
//   0x11e388: 94016074  bl       #0x176558
static inline uint64_t fde_func_0991_0x11e37c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e37cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb4000140ULL) ^ 0x0823e8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0992 | PC: 0x11e40c | FDE: 0x082448 | Size: 256 bytes
// Khung tháo gỡ #0992 | Địa chỉ PC: 0x11e40c | Địa chỉ FDE: 0x082448 | Kích thước: 256 bytes
//   0x11e40c: F0000388  adrp     x8, #0x191000
//   0x11e410: 9121C108  add      x8, x8, #0x870
//   0x11e414: F9000028  str      x8, [x1]
//   0x11e418: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0992_0x11e40c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e40cULL ^ (static_cast<uint64_t>(0xf0000388ULL) << 13);
    acc = (acc + a1 + 0x9121c108ULL) ^ 0x082448ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0993 | PC: 0x11e50c | FDE: 0x0824b8 | Size: 256 bytes
// Khung tháo gỡ #0993 | Địa chỉ PC: 0x11e50c | Địa chỉ FDE: 0x0824b8 | Kích thước: 256 bytes
//   0x11e50c: D10343FF  sub      sp, sp, #0xd0
//   0x11e510: FD0053E8  str      d8, [sp, #0xa0]
//   0x11e514: F90057F6  str      x22, [sp, #0xa8]
//   0x11e518: A90B53F5  stp      x21, x20, [sp, #0xb0]
static inline uint64_t fde_func_0993_0x11e50c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e50cULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xfd0053e8ULL) ^ 0x0824b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0994 | PC: 0x11e708 | FDE: 0x082538 | Size: 120 bytes
// Khung tháo gỡ #0994 | Địa chỉ PC: 0x11e708 | Địa chỉ FDE: 0x082538 | Kích thước: 120 bytes
//   0x11e708: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x11e70c: AA0003F3  mov      x19, x0
//   0x11e710: 97FFFFF8  bl       #0x11e6f0
//   0x11e714: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0994_0x11e708(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e708ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x082538ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0995 | PC: 0x11e780 | FDE: 0x082598 | Size: 256 bytes
// Khung tháo gỡ #0995 | Địa chỉ PC: 0x11e780 | Địa chỉ FDE: 0x082598 | Kích thước: 256 bytes
//   0x11e780: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x11e784: 94016693  bl       #0x1781d0
//   0x11e788: 97FFFFCD  bl       #0x11e6bc
//   0x11e78c: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0995_0x11e780(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e780ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94016693ULL) ^ 0x082598ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0996 | PC: 0x11e9a4 | FDE: 0x082610 | Size: 256 bytes
// Khung tháo gỡ #0996 | Địa chỉ PC: 0x11e9a4 | Địa chỉ FDE: 0x082610 | Kích thước: 256 bytes
//   0x11e9a4: F0000388  adrp     x8, #0x191000
//   0x11e9a8: 91240108  add      x8, x8, #0x900
//   0x11e9ac: 140171D9  b        #0x17b110
//   0x11e9b0: F81F0FFE  str      x30, [sp, #-0x10]!
static inline uint64_t fde_func_0996_0x11e9a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e9a4ULL ^ (static_cast<uint64_t>(0xf0000388ULL) << 13);
    acc = (acc + a1 + 0x91240108ULL) ^ 0x082610ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0997 | PC: 0x11eb3c | FDE: 0x082678 | Size: 112 bytes
// Khung tháo gỡ #0997 | Địa chỉ PC: 0x11eb3c | Địa chỉ FDE: 0x082678 | Kích thước: 112 bytes
//   0x11eb3c: F9400808  ldr      x8, [x0, #0x10]
//   0x11eb40: F0000389  adrp     x9, #0x191000
//   0x11eb44: 9125E129  add      x9, x9, #0x978
//   0x11eb48: F9000009  str      x9, [x0]
static inline uint64_t fde_func_0997_0x11eb3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11eb3cULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xf0000389ULL) ^ 0x082678ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0998 | PC: 0x11ebac | FDE: 0x0826e0 | Size: 256 bytes
// Khung tháo gỡ #0998 | Địa chỉ PC: 0x11ebac | Địa chỉ FDE: 0x0826e0 | Kích thước: 256 bytes
//   0x11ebac: AA1E03E4  mov      x4, x30
//   0x11ebb0: 94017379  bl       #0x17b994
//   0x11ebb4: AA0403FE  mov      x30, x4
//   0x11ebb8: A9167BF3  stp      x19, x30, [sp, #0x160]
static inline uint64_t fde_func_0998_0x11ebac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ebacULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x94017379ULL) ^ 0x0826e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0999 | PC: 0x11eea4 | FDE: 0x082760 | Size: 256 bytes
// Khung tháo gỡ #0999 | Địa chỉ PC: 0x11eea4 | Địa chỉ FDE: 0x082760 | Kích thước: 256 bytes
//   0x11eea4: D10083FF  sub      sp, sp, #0x20
//   0x11eea8: F9000BFE  str      x30, [sp, #0x10]
//   0x11eeac: 940183A4  bl       #0x17fd3c
//   0x11eeb0: F94003E8  ldr      x8, [sp]
static inline uint64_t fde_func_0999_0x11eea4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11eea4ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfeULL) ^ 0x082760ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1000 | PC: 0x11f270 | FDE: 0x0827d8 | Size: 256 bytes
// Khung tháo gỡ #1000 | Địa chỉ PC: 0x11f270 | Địa chỉ FDE: 0x0827d8 | Kích thước: 256 bytes
//   0x11f270: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x11f274: AA0003F3  mov      x19, x0
//   0x11f278: 97FFFFFA  bl       #0x11f260
//   0x11f27c: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1000_0x11f270(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f270ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0827d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1001 | PC: 0x11f5a4 | FDE: 0x082860 | Size: 244 bytes
// Khung tháo gỡ #1001 | Địa chỉ PC: 0x11f5a4 | Địa chỉ FDE: 0x082860 | Kích thước: 244 bytes
//   0x11f5a4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x11f5a8: AA0003F3  mov      x19, x0
//   0x11f5ac: 9100A000  add      x0, x0, #0x28
//   0x11f5b0: 97FE25F6  bl       #0xa8d88
static inline uint64_t fde_func_1001_0x11f5a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f5a4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x082860ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #1002 | PC: 0x11f698 | FDE: 0x0828c8 | Size: 136 bytes
// Khung tháo gỡ #1002 | Địa chỉ PC: 0x11f698 | Địa chỉ FDE: 0x0828c8 | Kích thước: 136 bytes
//   0x11f698: F9400808  ldr      x8, [x0, #0x10]
//   0x11f69c: D0000389  adrp     x9, #0x191000
//   0x11f6a0: 91288129  add      x9, x9, #0xa20
//   0x11f6a4: 14016D59  b        #0x17ac08
static inline uint64_t fde_func_1002_0x11f698(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f698ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xd0000389ULL) ^ 0x0828c8ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1003 | PC: 0x11f720 | FDE: 0x082928 | Size: 256 bytes
// Khung tháo gỡ #1003 | Địa chỉ PC: 0x11f720 | Địa chỉ FDE: 0x082928 | Kích thước: 256 bytes
//   0x11f720: AA1E03E3  mov      x3, x30
//   0x11f724: 9401981A  bl       #0x18578c
//   0x11f728: AA0303FE  mov      x30, x3
//   0x11f72c: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1003_0x11f720(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f720ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x9401981aULL) ^ 0x082928ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1004 | PC: 0x11fb78 | FDE: 0x0829a8 | Size: 96 bytes
// Khung tháo gỡ #1004 | Địa chỉ PC: 0x11fb78 | Địa chỉ FDE: 0x0829a8 | Kích thước: 96 bytes
//   0x11fb78: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x11fb7c: 9401646E  bl       #0x178d34
//   0x11fb80: 94000004  bl       #0x11fb90
//   0x11fb84: F9400660  ldr      x0, [x19, #8]
static inline uint64_t fde_func_1004_0x11fb78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11fb78ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9401646eULL) ^ 0x0829a8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1005 | PC: 0x11fbd8 | FDE: 0x082a08 | Size: 80 bytes
// Khung tháo gỡ #1005 | Địa chỉ PC: 0x11fbd8 | Địa chỉ FDE: 0x082a08 | Kích thước: 80 bytes
//   0x11fbd8: F9400808  ldr      x8, [x0, #0x10]
//   0x11fbdc: 91008001  add      x1, x0, #0x20
//   0x11fbe0: F9400908  ldr      x8, [x8, #0x10]
//   0x11fbe4: AA0803E0  mov      x0, x8
static inline uint64_t fde_func_1005_0x11fbd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11fbd8ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0x91008001ULL) ^ 0x082a08ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1006 | PC: 0x11fc28 | FDE: 0x082a68 | Size: 256 bytes
// Khung tháo gỡ #1006 | Địa chỉ PC: 0x11fc28 | Địa chỉ FDE: 0x082a68 | Kích thước: 256 bytes
//   0x11fc28: D10083FF  sub      sp, sp, #0x20
//   0x11fc2c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x11fc30: D53BD053  mrs      x19, tpidr_el0
//   0x11fc34: F9401668  ldr      x8, [x19, #0x28]
static inline uint64_t fde_func_1006_0x11fc28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11fc28ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x082a68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1007 | PC: 0x11fedc | FDE: 0x082ae8 | Size: 256 bytes
// Khung tháo gỡ #1007 | Địa chỉ PC: 0x11fedc | Địa chỉ FDE: 0x082ae8 | Kích thước: 256 bytes
//   0x11fedc: D0000388  adrp     x8, #0x191000
//   0x11fee0: 912B0108  add      x8, x8, #0xac0
//   0x11fee4: F8008408  str      x8, [x0], #8
//   0x11fee8: 17FE2DCB  b        #0xab614
static inline uint64_t fde_func_1007_0x11fedc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11fedcULL ^ (static_cast<uint64_t>(0xd0000388ULL) << 13);
    acc = (acc + a1 + 0x912b0108ULL) ^ 0x082ae8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1008 | PC: 0x12008c | FDE: 0x082b58 | Size: 144 bytes
// Khung tháo gỡ #1008 | Địa chỉ PC: 0x12008c | Địa chỉ FDE: 0x082b58 | Kích thước: 144 bytes
//   0x12008c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x120090: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x120094: 940157C3  bl       #0x175fa0
//   0x120098: 97FE547F  bl       #0xb5294
static inline uint64_t fde_func_1008_0x12008c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12008cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x082b58ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1009 | PC: 0x12011c | FDE: 0x082bc0 | Size: 120 bytes
// Khung tháo gỡ #1009 | Địa chỉ PC: 0x12011c | Địa chỉ FDE: 0x082bc0 | Kích thước: 120 bytes
//   0x12011c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x120120: AA0003F3  mov      x19, x0
//   0x120124: 97FFFFF8  bl       #0x120104
//   0x120128: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1009_0x12011c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12011cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x082bc0ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1010 | PC: 0x120194 | FDE: 0x082c20 | Size: 256 bytes
// Khung tháo gỡ #1010 | Địa chỉ PC: 0x120194 | Địa chỉ FDE: 0x082c20 | Kích thước: 256 bytes
//   0x120194: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x120198: 9401600E  bl       #0x1781d0
//   0x12019c: 97FFFFCD  bl       #0x1200d0
//   0x1201a0: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1010_0x120194(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x120194ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9401600eULL) ^ 0x082c20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1011 | PC: 0x1202a0 | FDE: 0x082c88 | Size: 212 bytes
// Khung tháo gỡ #1011 | Địa chỉ PC: 0x1202a0 | Địa chỉ FDE: 0x082c88 | Kích thước: 212 bytes
//   0x1202a0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1202a4: AA0003F3  mov      x19, x0
//   0x1202a8: 97FFFFFA  bl       #0x120290
//   0x1202ac: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1011_0x1202a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1202a0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x082c88ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1012 | PC: 0x120374 | FDE: 0x082cf0 | Size: 256 bytes
// Khung tháo gỡ #1012 | Địa chỉ PC: 0x120374 | Địa chỉ FDE: 0x082cf0 | Kích thước: 256 bytes
//   0x120374: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x120378: AA0003F3  mov      x19, x0
//   0x12037c: 97FFFFF3  bl       #0x120348
//   0x120380: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1012_0x120374(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x120374ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x082cf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1013 | PC: 0x12057c | FDE: 0x082d68 | Size: 252 bytes
// Khung tháo gỡ #1013 | Địa chỉ PC: 0x12057c | Địa chỉ FDE: 0x082d68 | Kích thước: 252 bytes
//   0x12057c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x120580: AA0003F3  mov      x19, x0
//   0x120584: 97FFFFF6  bl       #0x12055c
//   0x120588: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1013_0x12057c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12057cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x082d68ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1014 | PC: 0x120678 | FDE: 0x082dc8 | Size: 256 bytes
// Khung tháo gỡ #1014 | Địa chỉ PC: 0x120678 | Địa chỉ FDE: 0x082dc8 | Kích thước: 256 bytes
//   0x120678: 1401A092  b        #0x1888c0
//   0x12067c: D105C3FF  sub      sp, sp, #0x170
//   0x120680: A9145BFC  stp      x28, x22, [sp, #0x140]
//   0x120684: A91553F5  stp      x21, x20, [sp, #0x150]
static inline uint64_t fde_func_1014_0x120678(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x120678ULL ^ (static_cast<uint64_t>(0x1401a092ULL) << 13);
    acc = (acc + a1 + 0xd105c3ffULL) ^ 0x082dc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1015 | PC: 0x120a88 | FDE: 0x082e50 | Size: 256 bytes [_ZN4lynx6canvas12EffectHelper8InstanceEv]
// Khung tháo gỡ #1015 | Địa chỉ PC: 0x120a88 | Địa chỉ FDE: 0x082e50 | Kích thước: 256 bytes
//   0x120a88: D10683FF  sub      sp, sp, #0x1a0
//   0x120a8c: A9156BFC  stp      x28, x26, [sp, #0x150]
//   0x120a90: A91663F9  stp      x25, x24, [sp, #0x160]
//   0x120a94: A9175BF7  stp      x23, x22, [sp, #0x170]
static inline uint64_t fde_func_1015_0x120a88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x120a88ULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xa9156bfcULL) ^ 0x082e50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1016 | PC: 0x120d68 | FDE: 0x082ee0 | Size: 256 bytes
// Khung tháo gỡ #1016 | Địa chỉ PC: 0x120d68 | Địa chỉ FDE: 0x082ee0 | Kích thước: 256 bytes
//   0x120d68: D10583FF  sub      sp, sp, #0x160
//   0x120d6c: A9135BFC  stp      x28, x22, [sp, #0x130]
//   0x120d70: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x120d74: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_1016_0x120d68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x120d68ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa9135bfcULL) ^ 0x082ee0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1017 | PC: 0x120ef4 | FDE: 0x082f70 | Size: 256 bytes
// Khung tháo gỡ #1017 | Địa chỉ PC: 0x120ef4 | Địa chỉ FDE: 0x082f70 | Kích thước: 256 bytes
//   0x120ef4: D10603FF  sub      sp, sp, #0x180
//   0x120ef8: 6D132BEB  stp      d11, d10, [sp, #0x130]
//   0x120efc: 6D1423E9  stp      d9, d8, [sp, #0x140]
//   0x120f00: A9155BFC  stp      x28, x22, [sp, #0x150]
static inline uint64_t fde_func_1017_0x120ef4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x120ef4ULL ^ (static_cast<uint64_t>(0xd10603ffULL) << 13);
    acc = (acc + a1 + 0x6d132bebULL) ^ 0x082f70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1018 | PC: 0x12114c | FDE: 0x082ff0 | Size: 16 bytes [_ZN4lynx6canvas6effect28ThreadLocalAmazingContextPtrEv]
// Khung tháo gỡ #1018 | Địa chỉ PC: 0x12114c | Địa chỉ FDE: 0x082ff0 | Kích thước: 16 bytes
//   0x12114c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x121150: 940163E6  bl       #0x17a0e8
//   0x121154: F84107FE  ldr      x30, [sp], #0x10
//   0x121158: D65F03C0  ret      
static inline uint64_t fde_func_1018_0x12114c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12114cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x940163e6ULL) ^ 0x082ff0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1019 | PC: 0x12115c | FDE: 0x083008 | Size: 32 bytes [_ZN4lynx6canvas6effect11GLStateSaveEPv]
// Khung tháo gỡ #1019 | Địa chỉ PC: 0x12115c | Địa chỉ FDE: 0x083008 | Kích thước: 32 bytes
//   0x12115c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x121160: 940163E2  bl       #0x17a0e8
//   0x121164: F9400000  ldr      x0, [x0]
//   0x121168: AA1F03E1  mov      x1, xzr
static inline uint64_t fde_func_1019_0x12115c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12115cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x940163e2ULL) ^ 0x083008ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1020 | PC: 0x12117c | FDE: 0x083020 | Size: 28 bytes [_ZN4lynx6canvas6effect14GLStateRestoreEPv]
// Khung tháo gỡ #1020 | Địa chỉ PC: 0x12117c | Địa chỉ FDE: 0x083020 | Kích thước: 28 bytes
//   0x12117c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x121180: 940163DA  bl       #0x17a0e8
//   0x121184: F9400000  ldr      x0, [x0]
//   0x121188: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_1020_0x12117c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12117cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x940163daULL) ^ 0x083020ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1021 | PC: 0x121198 | FDE: 0x083038 | Size: 256 bytes [_ZN4lynx6canvas6effect14GetTextureFuncEPvS2_]
// Khung tháo gỡ #1021 | Địa chỉ PC: 0x121198 | Địa chỉ FDE: 0x083038 | Kích thước: 256 bytes
//   0x121198: D10203FF  sub      sp, sp, #0x80
//   0x12119c: F9002BF6  str      x22, [sp, #0x50]
//   0x1211a0: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x1211a4: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1021_0x121198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x121198ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf6ULL) ^ 0x083038ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1022 | PC: 0x12130c | FDE: 0x083058 | Size: 52 bytes [_ZN4lynx6canvas6effect16BeforeUpdateFuncEPvPKjmj]
// Khung tháo gỡ #1022 | Địa chỉ PC: 0x12130c | Địa chỉ FDE: 0x083058 | Kích thước: 52 bytes
//   0x12130c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x121310: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x121314: 2A0303F3  mov      w19, w3
//   0x121318: 94017EC4  bl       #0x180e28
static inline uint64_t fde_func_1022_0x12130c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12130cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x083058ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1023 | PC: 0x121340 | FDE: 0x083078 | Size: 256 bytes
// Khung tháo gỡ #1023 | Địa chỉ PC: 0x121340 | Địa chỉ FDE: 0x083078 | Kích thước: 256 bytes
//   0x121340: D102C3FF  sub      sp, sp, #0xb0
//   0x121344: F90043F6  str      x22, [sp, #0x80]
//   0x121348: A90953F5  stp      x21, x20, [sp, #0x90]
//   0x12134c: A90A7BF3  stp      x19, x30, [sp, #0xa0]
static inline uint64_t fde_func_1023_0x121340(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x121340ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90043f6ULL) ^ 0x083078ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1024 | PC: 0x1215d0 | FDE: 0x0830b8 | Size: 256 bytes [_ZN4lynx6canvas6effect15AfterUpdateFuncEPvPKjmj]
// Khung tháo gỡ #1024 | Địa chỉ PC: 0x1215d0 | Địa chỉ FDE: 0x0830b8 | Kích thước: 256 bytes
//   0x1215d0: D102C3FF  sub      sp, sp, #0xb0
//   0x1215d4: F90043F6  str      x22, [sp, #0x80]
//   0x1215d8: A90953F5  stp      x21, x20, [sp, #0x90]
//   0x1215dc: A90A7BF3  stp      x19, x30, [sp, #0xa0]
static inline uint64_t fde_func_1024_0x1215d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1215d0ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90043f6ULL) ^ 0x0830b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1025 | PC: 0x121788 | FDE: 0x0830f8 | Size: 92 bytes [_ZN4lynx6canvas6effect12URLTranslateEPKcPcPiPv]
// Khung tháo gỡ #1025 | Địa chỉ PC: 0x121788 | Địa chỉ FDE: 0x0830f8 | Kích thước: 92 bytes
//   0x121788: D10543FF  sub      sp, sp, #0x150
//   0x12178c: A91353FC  stp      x28, x20, [sp, #0x130]
//   0x121790: A9147BF3  stp      x19, x30, [sp, #0x140]
//   0x121794: 94015460  bl       #0x176914
static inline uint64_t fde_func_1025_0x121788(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x121788ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa91353fcULL) ^ 0x0830f8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1026 | PC: 0x1217e4 | FDE: 0x083118 | Size: 256 bytes [_ZN4lynx6canvas6effect29MakeSureAmazingContextCreatedEv]
// Khung tháo gỡ #1026 | Địa chỉ PC: 0x1217e4 | Địa chỉ FDE: 0x083118 | Kích thước: 256 bytes
//   0x1217e4: D10083FF  sub      sp, sp, #0x20
//   0x1217e8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1217ec: 9401623F  bl       #0x17a0e8
//   0x1217f0: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_1026_0x1217e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1217e4ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x083118ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1027 | PC: 0x1219d8 | FDE: 0x083178 | Size: 256 bytes
// Khung tháo gỡ #1027 | Địa chỉ PC: 0x1219d8 | Địa chỉ FDE: 0x083178 | Kích thước: 256 bytes
//   0x1219d8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1219dc: AA0003F3  mov      x19, x0
//   0x1219e0: 91002000  add      x0, x0, #8
//   0x1219e4: 97FE23B3  bl       #0xaa8b0
static inline uint64_t fde_func_1027_0x1219d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1219d8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x083178ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1028 | PC: 0x121d9c | FDE: 0x0831f0 | Size: 256 bytes
// Khung tháo gỡ #1028 | Địa chỉ PC: 0x121d9c | Địa chỉ FDE: 0x0831f0 | Kích thước: 256 bytes
//   0x121d9c: B9400028  ldr      w8, [x1]
//   0x121da0: B9400009  ldr      w9, [x0]
//   0x121da4: B940004A  ldr      w10, [x2]
//   0x121da8: 6B09011F  cmp      w8, w9
static inline uint64_t fde_func_1028_0x121d9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x121d9cULL ^ (static_cast<uint64_t>(0xb9400028ULL) << 13);
    acc = (acc + a1 + 0xb9400009ULL) ^ 0x0831f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1029 | PC: 0x12209c | FDE: 0x083268 | Size: 256 bytes
// Khung tháo gỡ #1029 | Địa chỉ PC: 0x12209c | Địa chỉ FDE: 0x083268 | Kích thước: 256 bytes
//   0x12209c: AA1E03E1  mov      x1, x30
//   0x1220a0: 940164FD  bl       #0x17b494
//   0x1220a4: AA0103FE  mov      x30, x1
//   0x1220a8: A9177BF3  stp      x19, x30, [sp, #0x170]
static inline uint64_t fde_func_1029_0x12209c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12209cULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x940164fdULL) ^ 0x083268ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1030 | PC: 0x122658 | FDE: 0x0832f8 | Size: 256 bytes [_ZN4lynx6canvas6remote10RefManager19OnRemoteRefReleasedEjj]
// Khung tháo gỡ #1030 | Địa chỉ PC: 0x122658 | Địa chỉ FDE: 0x0832f8 | Kích thước: 256 bytes
//   0x122658: D10103FF  sub      sp, sp, #0x40
//   0x12265c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x122660: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x122664: D53BD055  mrs      x21, tpidr_el0
static inline uint64_t fde_func_1030_0x122658(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x122658ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x0832f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1031 | PC: 0x122870 | FDE: 0x083330 | Size: 100 bytes [_ZN4lynx6canvas6remote12RemoteBridgeC2ENS1_9RemoteEnvENSt6__ndk110unique_ptrINS_7binding8ImplBaseENS4_14default_deleteIS7_EEEEjNS4_6vectorIjNS4_9allocatorIjEEEE]
// Khung tháo gỡ #1031 | Địa chỉ PC: 0x122870 | Địa chỉ FDE: 0x083330 | Kích thước: 100 bytes
//   0x122870: F9000801  str      x1, [x0, #0x10]
//   0x122874: F000038A  adrp     x10, #0x195000
//   0x122878: F9412D4A  ldr      x10, [x10, #0x258]
//   0x12287c: 52800029  mov      w9, #1
static inline uint64_t fde_func_1031_0x122870(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x122870ULL ^ (static_cast<uint64_t>(0xf9000801ULL) << 13);
    acc = (acc + a1 + 0xf000038aULL) ^ 0x083330ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1032 | PC: 0x1228d4 | FDE: 0x083348 | Size: 4 bytes [_ZN4lynx6canvas6remote12RemoteBridge13GetBaseObjectEv]
// Khung tháo gỡ #1032 | Địa chỉ PC: 0x1228d4 | Địa chỉ FDE: 0x083348 | Kích thước: 4 bytes
//   0x1228d4: 14019C13  b        #0x189920
static inline uint64_t fde_func_1032_0x1228d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1228d4ULL ^ (static_cast<uint64_t>(0x14019c13ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff4ULL) ^ 0x083348ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1033 | PC: 0x1228d8 | FDE: 0x083360 | Size: 60 bytes [_ZN4lynx6canvas6remote12RemoteBridge12GetStrongRefEv]
// Khung tháo gỡ #1033 | Địa chỉ PC: 0x1228d8 | Địa chỉ FDE: 0x083360 | Kích thước: 60 bytes
//   0x1228d8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1228dc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1228e0: AA0803F4  mov      x20, x8
//   0x1228e4: 910023E8  add      x8, sp, #8
static inline uint64_t fde_func_1033_0x1228d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1228d8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x083360ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1034 | PC: 0x122914 | FDE: 0x083380 | Size: 8 bytes [_ZN4lynx6canvas6remote12RemoteBridge6GetEnvEv]
// Khung tháo gỡ #1034 | Địa chỉ PC: 0x122914 | Địa chỉ FDE: 0x083380 | Kích thước: 8 bytes
//   0x122914: F9400800  ldr      x0, [x0, #0x10]
//   0x122918: 14019702  b        #0x188520
static inline uint64_t fde_func_1034_0x122914(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x122914ULL ^ (static_cast<uint64_t>(0xf9400800ULL) << 13);
    acc = (acc + a1 + 0x14019702ULL) ^ 0x083380ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1035 | PC: 0x12291c | FDE: 0x083398 | Size: 256 bytes [_ZN4lynx6canvas6remote12RemoteBridgeD2Ev]
// Khung tháo gỡ #1035 | Địa chỉ PC: 0x12291c | Địa chỉ FDE: 0x083398 | Kích thước: 256 bytes
//   0x12291c: D10103FF  sub      sp, sp, #0x40
//   0x122920: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x122924: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x122928: D53BD055  mrs      x21, tpidr_el0
static inline uint64_t fde_func_1035_0x12291c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12291cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x083398ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1036 | PC: 0x122b40 | FDE: 0x0833d0 | Size: 48 bytes [_ZN4lynx6canvas6remote12RemoteBridge5ResetEv]
// Khung tháo gỡ #1036 | Địa chỉ PC: 0x122b40 | Địa chỉ FDE: 0x0833d0 | Kích thước: 48 bytes
//   0x122b40: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x122b44: 94015DD4  bl       #0x17a294
//   0x122b48: B4000100  cbz      x0, #0x122b68
//   0x122b4c: 94014F59  bl       #0x1768b0
static inline uint64_t fde_func_1036_0x122b40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x122b40ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94015dd4ULL) ^ 0x0833d0ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1037 | PC: 0x122b70 | FDE: 0x0833e8 | Size: 256 bytes [_ZN4lynx6canvas6remote12RemoteBridge12WrapInternalENS1_9RemoteEnvEPNS_7binding8ImplBaseEjNSt6__ndk16vectorIjNS7_9allocatorIjEEEE]
// Khung tháo gỡ #1037 | Địa chỉ PC: 0x122b70 | Địa chỉ FDE: 0x0833e8 | Kích thước: 256 bytes
//   0x122b70: D10283FF  sub      sp, sp, #0xa0
//   0x122b74: A9056BFB  stp      x27, x26, [sp, #0x50]
//   0x122b78: A90663F9  stp      x25, x24, [sp, #0x60]
//   0x122b7c: A9075BF7  stp      x23, x22, [sp, #0x70]
static inline uint64_t fde_func_1037_0x122b70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x122b70ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9056bfbULL) ^ 0x0833e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1038 | PC: 0x122f08 | FDE: 0x083458 | Size: 16 bytes [_ZN4lynx6canvas6remote10FromRemoteENS1_9RemoteEnvE]
// Khung tháo gỡ #1038 | Địa chỉ PC: 0x122f08 | Địa chỉ FDE: 0x083458 | Kích thước: 16 bytes
//   0x122f08: B4000040  cbz      x0, #0x122f10
//   0x122f0c: D65F03C0  ret      
//   0x122f10: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x122f14: 940190BB  bl       #0x187200
static inline uint64_t fde_func_1038_0x122f08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x122f08ULL ^ (static_cast<uint64_t>(0xb4000040ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x083458ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1039 | PC: 0x122f18 | FDE: 0x083470 | Size: 120 bytes
// Khung tháo gỡ #1039 | Địa chỉ PC: 0x122f18 | Địa chỉ FDE: 0x083470 | Kích thước: 120 bytes
//   0x122f18: D10103FF  sub      sp, sp, #0x40
//   0x122f1c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x122f20: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x122f24: D53BD055  mrs      x21, tpidr_el0
static inline uint64_t fde_func_1039_0x122f18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x122f18ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x083470ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1040 | PC: 0x122f90 | FDE: 0x083490 | Size: 204 bytes [_ZN4lynx6canvas6remote13RemoteEnvImplD2Ev]
// Khung tháo gỡ #1040 | Địa chỉ PC: 0x122f90 | Địa chỉ FDE: 0x083490 | Kích thước: 204 bytes
//   0x122f90: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x122f94: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x122f98: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x122f9c: F0000388  adrp     x8, #0x195000
static inline uint64_t fde_func_1040_0x122f90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x122f90ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x083490ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1041 | PC: 0x12305c | FDE: 0x0834b0 | Size: 24 bytes [_ZN4lynx6canvas6remote13RemoteEnvImplD0Ev]
// Khung tháo gỡ #1041 | Địa chỉ PC: 0x12305c | Địa chỉ FDE: 0x0834b0 | Kích thước: 24 bytes
//   0x12305c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x123060: AA0003F3  mov      x19, x0
//   0x123064: 94019A37  bl       #0x189940
//   0x123068: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1041_0x12305c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12305cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0834b0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1042 | PC: 0x123074 | FDE: 0x0834c8 | Size: 164 bytes [_ZN4lynx6canvas6remote13RemoteEnvImpl15GetInstanceDataEm]
// Khung tháo gỡ #1042 | Địa chỉ PC: 0x123074 | Địa chỉ FDE: 0x0834c8 | Kích thước: 164 bytes
//   0x123074: F9401008  ldr      x8, [x0, #0x20]
//   0x123078: B40004A8  cbz      x8, #0x12310c
//   0x12307c: 9E670100  fmov     d0, x8
//   0x123080: AA1E03E2  mov      x2, x30
static inline uint64_t fde_func_1042_0x123074(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x123074ULL ^ (static_cast<uint64_t>(0xf9401008ULL) << 13);
    acc = (acc + a1 + 0xb40004a8ULL) ^ 0x0834c8ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1043 | PC: 0x123118 | FDE: 0x0834e0 | Size: 256 bytes [_ZN4lynx6canvas6remote13RemoteEnvImpl15SetInstanceDataEmPvPFvNS_7binding3EnvES3_S3_ES3_]
// Khung tháo gỡ #1043 | Địa chỉ PC: 0x123118 | Địa chỉ FDE: 0x0834e0 | Kích thước: 256 bytes
//   0x123118: AA1E03E5  mov      x5, x30
//   0x12311c: 94016062  bl       #0x17b2a4
//   0x123120: AA0503FE  mov      x30, x5
//   0x123124: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1043_0x123118(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x123118ULL ^ (static_cast<uint64_t>(0xaa1e03e5ULL) << 13);
    acc = (acc + a1 + 0x94016062ULL) ^ 0x0834e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1044 | PC: 0x123348 | FDE: 0x083508 | Size: 256 bytes [_ZN4lynx6canvas6remote13RemoteEnvImpl11SendMessageERKNS_7binding6ObjectERKNSt6__ndk112basic_stringIcNS7_11char_traitsIcEENS7_9allocatorIcEEEESF_RKNS3_5ValueE]
// Khung tháo gỡ #1044 | Địa chỉ PC: 0x123348 | Địa chỉ FDE: 0x083508 | Kích thước: 256 bytes
//   0x123348: D10383FF  sub      sp, sp, #0xe0
//   0x12334c: A90A63F9  stp      x25, x24, [sp, #0xa0]
//   0x123350: A90B5BF7  stp      x23, x22, [sp, #0xb0]
//   0x123354: A90C53F5  stp      x21, x20, [sp, #0xc0]
static inline uint64_t fde_func_1044_0x123348(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x123348ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa90a63f9ULL) ^ 0x083508ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1045 | PC: 0x12358c | FDE: 0x083568 | Size: 24 bytes
// Khung tháo gỡ #1045 | Địa chỉ PC: 0x12358c | Địa chỉ FDE: 0x083568 | Kích thước: 24 bytes
//   0x12358c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x123590: AA0003F3  mov      x19, x0
//   0x123594: 97FFFFF6  bl       #0x12356c
//   0x123598: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1045_0x12358c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12358cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x083568ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1046 | PC: 0x1235a4 | FDE: 0x083580 | Size: 8 bytes [_ZN4lynx6canvas6remote13RemoteEnvImpl6CreateEv]
// Khung tháo gỡ #1046 | Địa chỉ PC: 0x1235a4 | Địa chỉ FDE: 0x083580 | Kích thước: 8 bytes
//   0x1235a4: AA0803E0  mov      x0, x8
//   0x1235a8: 17FFFE2B  b        #0x122e54
static inline uint64_t fde_func_1046_0x1235a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1235a4ULL ^ (static_cast<uint64_t>(0xaa0803e0ULL) << 13);
    acc = (acc + a1 + 0x17fffe2bULL) ^ 0x083580ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1047 | PC: 0x1235ac | FDE: 0x083598 | Size: 32 bytes [_ZN4lynx6canvas6remote13RemoteEnvImpl12SetJSChannelENSt6__ndk110unique_ptrINS1_15RemoteJSChannelENS3_14default_deleteIS5_EEEE]
// Khung tháo gỡ #1047 | Địa chỉ PC: 0x1235ac | Địa chỉ FDE: 0x083598 | Kích thước: 32 bytes
//   0x1235ac: F9400029  ldr      x9, [x1]
//   0x1235b0: F900003F  str      xzr, [x1]
//   0x1235b4: AA0003E8  mov      x8, x0
//   0x1235b8: F9402000  ldr      x0, [x0, #0x40]
static inline uint64_t fde_func_1047_0x1235ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1235acULL ^ (static_cast<uint64_t>(0xf9400029ULL) << 13);
    acc = (acc + a1 + 0xf900003fULL) ^ 0x083598ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1048 | PC: 0x1235cc | FDE: 0x0835b0 | Size: 16 bytes [_ZN4lynx6canvas6remote13RemoteEnvImpl11SendMessageERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEjSB_SB_]
// Khung tháo gỡ #1048 | Địa chỉ PC: 0x1235cc | Địa chỉ FDE: 0x0835b0 | Kích thước: 16 bytes
//   0x1235cc: F9402000  ldr      x0, [x0, #0x40]
//   0x1235d0: F9400008  ldr      x8, [x0]
//   0x1235d4: F9400105  ldr      x5, [x8]
//   0x1235d8: D61F00A0  br       x5
static inline uint64_t fde_func_1048_0x1235cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1235ccULL ^ (static_cast<uint64_t>(0xf9402000ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x0835b0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1049 | PC: 0x1235dc | FDE: 0x0835c8 | Size: 28 bytes [_ZN4lynx6canvas6remote13RemoteEnvImpl13ConnectToNapiEPv]
// Khung tháo gỡ #1049 | Địa chỉ PC: 0x1235dc | Địa chỉ FDE: 0x0835c8 | Kích thước: 28 bytes
//   0x1235dc: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1235e0: F9402408  ldr      x8, [x0, #0x48]
//   0x1235e4: B5000088  cbnz     x8, #0x1235f4
//   0x1235e8: F9002401  str      x1, [x0, #0x48]
static inline uint64_t fde_func_1049_0x1235dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1235dcULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9402408ULL) ^ 0x0835c8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1050 | PC: 0x1235f8 | FDE: 0x0835e0 | Size: 28 bytes [_ZN4lynx6canvas6remote13RemoteEnvImpl18DisconnectFromNapiEv]
// Khung tháo gỡ #1050 | Địa chỉ PC: 0x1235f8 | Địa chỉ FDE: 0x0835e0 | Kích thước: 28 bytes
//   0x1235f8: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1235fc: F9402408  ldr      x8, [x0, #0x48]
//   0x123600: B4000088  cbz      x8, #0x123610
//   0x123604: F900241F  str      xzr, [x0, #0x48]
static inline uint64_t fde_func_1050_0x1235f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1235f8ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9402408ULL) ^ 0x0835e0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1051 | PC: 0x123614 | FDE: 0x0835f8 | Size: 164 bytes [_ZN4lynx6canvas6remote13RemoteEnvImpl22RegisterCommandHandlerEPFbjjPjRjjRNS1_10RefManagerEPS2_RNS_7binding14ExceptionStateERNS8_5ValueEE]
// Khung tháo gỡ #1051 | Địa chỉ PC: 0x123614 | Địa chỉ FDE: 0x0835f8 | Kích thước: 164 bytes
//   0x123614: AA1E03E2  mov      x2, x30
//   0x123618: 94015297  bl       #0x178074
//   0x12361c: AA0203FE  mov      x30, x2
//   0x123620: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1051_0x123614(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x123614ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94015297ULL) ^ 0x0835f8ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1052 | PC: 0x1236b8 | FDE: 0x083620 | Size: 256 bytes [_ZN4lynx6canvas6remote13RemoteEnvImpl13RegisterTypesENSt6__ndk16vectorINS3_4pairIjPKcEENS3_9allocatorIS8_EEEE]
// Khung tháo gỡ #1052 | Địa chỉ PC: 0x1236b8 | Địa chỉ FDE: 0x083620 | Kích thước: 256 bytes
//   0x1236b8: AA1E03E2  mov      x2, x30
//   0x1236bc: 94014C90  bl       #0x1768fc
//   0x1236c0: AA0203FE  mov      x30, x2
//   0x1236c4: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1052_0x1236b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1236b8ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94014c90ULL) ^ 0x083620ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1053 | PC: 0x12390c | FDE: 0x083650 | Size: 256 bytes [_ZN4lynx6canvas6remote13RemoteEnvImpl9RunBufferEPv]
// Khung tháo gỡ #1053 | Địa chỉ PC: 0x12390c | Địa chỉ FDE: 0x083650 | Kích thước: 256 bytes
//   0x12390c: AA1E03E2  mov      x2, x30
//   0x123910: 9401494E  bl       #0x175e48
//   0x123914: AA0203FE  mov      x30, x2
//   0x123918: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1053_0x12390c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12390cULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9401494eULL) ^ 0x083650ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1054 | PC: 0x123c80 | FDE: 0x083680 | Size: 184 bytes [_ZN4lynx6canvas6remote13RemoteEnvImpl14RegisterModuleEPFvPS2_E]
// Khung tháo gỡ #1054 | Địa chỉ PC: 0x123c80 | Địa chỉ FDE: 0x083680 | Kích thước: 184 bytes
//   0x123c80: AA1E03E1  mov      x1, x30
//   0x123c84: 940150FC  bl       #0x178074
//   0x123c88: AA0103FE  mov      x30, x1
//   0x123c8c: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1054_0x123c80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x123c80ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x940150fcULL) ^ 0x083680ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1055 | PC: 0x123d38 | FDE: 0x0836a8 | Size: 96 bytes [_ZN4lynx6canvas6remote13RemoteEnvImpl16BootstrapModulesEv]
// Khung tháo gỡ #1055 | Địa chỉ PC: 0x123d38 | Địa chỉ FDE: 0x0836a8 | Kích thước: 96 bytes
//   0x123d38: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x123d3c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x123d40: D0000388  adrp     x8, #0x195000
//   0x123d44: F9410108  ldr      x8, [x8, #0x200]
static inline uint64_t fde_func_1055_0x123d38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x123d38ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0836a8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1056 | PC: 0x123d98 | FDE: 0x0836e8 | Size: 52 bytes
// Khung tháo gỡ #1056 | Địa chỉ PC: 0x123d98 | Địa chỉ FDE: 0x0836e8 | Kích thước: 52 bytes
//   0x123d98: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x123d9c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x123da0: AA0003F3  mov      x19, x0
//   0x123da4: 52800200  mov      w0, #0x10
static inline uint64_t fde_func_1056_0x123d98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x123d98ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0836e8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1057 | PC: 0x123dcc | FDE: 0x083708 | Size: 48 bytes [_ZN4lynx6canvas6remote10FromRemoteEPNS1_12RemoteBridgeE]
// Khung tháo gỡ #1057 | Địa chỉ PC: 0x123dcc | Địa chỉ FDE: 0x083708 | Kích thước: 48 bytes
//   0x123dcc: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x123dd0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x123dd4: AA0803F3  mov      x19, x8
//   0x123dd8: B40000C0  cbz      x0, #0x123df0
static inline uint64_t fde_func_1057_0x123dcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x123dccULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x083708ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1058 | PC: 0x123dfc | FDE: 0x083728 | Size: 52 bytes [_ZN4lynx6canvas6remote8ToRemoteENS_7binding6ObjectE]
// Khung tháo gỡ #1058 | Địa chỉ PC: 0x123dfc | Địa chỉ FDE: 0x083728 | Kích thước: 52 bytes
//   0x123dfc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x123e00: 94014E60  bl       #0x177780
//   0x123e04: B40000E0  cbz      x0, #0x123e20
//   0x123e08: 9401473F  bl       #0x175b04
static inline uint64_t fde_func_1058_0x123dfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x123dfcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94014e60ULL) ^ 0x083728ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1059 | PC: 0x123e30 | FDE: 0x083758 | Size: 256 bytes
// Khung tháo gỡ #1059 | Địa chỉ PC: 0x123e30 | Địa chỉ FDE: 0x083758 | Kích thước: 256 bytes
//   0x123e30: F9400408  ldr      x8, [x0, #8]
//   0x123e34: D0000369  adrp     x9, #0x191000
//   0x123e38: 91394129  add      x9, x9, #0xe50
//   0x123e3c: F9000009  str      x9, [x0]
static inline uint64_t fde_func_1059_0x123e30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x123e30ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xd0000369ULL) ^ 0x083758ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1060 | PC: 0x1243cc | FDE: 0x0837d8 | Size: 256 bytes
// Khung tháo gỡ #1060 | Địa chỉ PC: 0x1243cc | Địa chỉ FDE: 0x0837d8 | Kích thước: 256 bytes
//   0x1243cc: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1243d0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1243d4: B9400008  ldr      w8, [x0]
//   0x1243d8: 71002D1F  cmp      w8, #0xb
static inline uint64_t fde_func_1060_0x1243cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1243ccULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0837d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1061 | PC: 0x1246cc | FDE: 0x083850 | Size: 256 bytes
// Khung tháo gỡ #1061 | Địa chỉ PC: 0x1246cc | Địa chỉ FDE: 0x083850 | Kích thước: 256 bytes
//   0x1246cc: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1246d0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1246d4: 94018043  bl       #0x1847e0
//   0x1246d8: EB1402BF  cmp      x21, x20
static inline uint64_t fde_func_1061_0x1246cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1246ccULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x083850ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1062 | PC: 0x1247d0 | FDE: 0x0838c8 | Size: 228 bytes
// Khung tháo gỡ #1062 | Địa chỉ PC: 0x1247d0 | Địa chỉ FDE: 0x0838c8 | Kích thước: 228 bytes
//   0x1247d0: F9400008  ldr      x8, [x0]
//   0x1247d4: AA0103E0  mov      x0, x1
//   0x1247d8: F9400108  ldr      x8, [x8]
//   0x1247dc: AA0803E1  mov      x1, x8
static inline uint64_t fde_func_1062_0x1247d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1247d0ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xaa0103e0ULL) ^ 0x0838c8ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1063 | PC: 0x1248b4 | FDE: 0x083958 | Size: 256 bytes
// Khung tháo gỡ #1063 | Địa chỉ PC: 0x1248b4 | Địa chỉ FDE: 0x083958 | Kích thước: 256 bytes
//   0x1248b4: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x1248b8: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x1248bc: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1248c0: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1063_0x1248b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1248b4ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x083958ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1064 | PC: 0x124ab4 | FDE: 0x0839f8 | Size: 256 bytes
// Khung tháo gỡ #1064 | Địa chỉ PC: 0x124ab4 | Địa chỉ FDE: 0x0839f8 | Kích thước: 256 bytes
//   0x124ab4: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x124ab8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x124abc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x124ac0: 940164EE  bl       #0x17de78
static inline uint64_t fde_func_1064_0x124ab4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x124ab4ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0839f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1065 | PC: 0x124bf0 | FDE: 0x083a78 | Size: 256 bytes
// Khung tháo gỡ #1065 | Địa chỉ PC: 0x124bf0 | Địa chỉ FDE: 0x083a78 | Kích thước: 256 bytes
//   0x124bf0: D10103FF  sub      sp, sp, #0x40
//   0x124bf4: F90013F4  str      x20, [sp, #0x20]
//   0x124bf8: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x124bfc: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1065_0x124bf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x124bf0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f4ULL) ^ 0x083a78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1066 | PC: 0x124e80 | FDE: 0x083b00 | Size: 256 bytes
// Khung tháo gỡ #1066 | Địa chỉ PC: 0x124e80 | Địa chỉ FDE: 0x083b00 | Kích thước: 256 bytes
//   0x124e80: EB03003F  cmp      x1, x3
//   0x124e84: 540000C1  b.ne     #0x124e9c
//   0x124e88: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x124e8c: 97FF7F8C  bl       #0x104cbc
static inline uint64_t fde_func_1066_0x124e80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x124e80ULL ^ (static_cast<uint64_t>(0xeb03003fULL) << 13);
    acc = (acc + a1 + 0x540000c1ULL) ^ 0x083b00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1067 | PC: 0x125340 | FDE: 0x083b80 | Size: 256 bytes
// Khung tháo gỡ #1067 | Địa chỉ PC: 0x125340 | Địa chỉ FDE: 0x083b80 | Kích thước: 256 bytes
//   0x125340: D10183FF  sub      sp, sp, #0x60
//   0x125344: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x125348: A9057BF3  stp      x19, x30, [sp, #0x50]
//   0x12534c: 9401551B  bl       #0x17a7b8
static inline uint64_t fde_func_1067_0x125340(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x125340ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90453f5ULL) ^ 0x083b80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1068 | PC: 0x126a64 | FDE: 0x083c18 | Size: 256 bytes
// Khung tháo gỡ #1068 | Địa chỉ PC: 0x126a64 | Địa chỉ FDE: 0x083c18 | Kích thước: 256 bytes
//   0x126a64: D10103FF  sub      sp, sp, #0x40
//   0x126a68: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x126a6c: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x126a70: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1068_0x126a64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x126a64ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x083c18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1069 | PC: 0x127150 | FDE: 0x083cb8 | Size: 256 bytes
// Khung tháo gỡ #1069 | Địa chỉ PC: 0x127150 | Địa chỉ FDE: 0x083cb8 | Kích thước: 256 bytes
//   0x127150: D10783FF  sub      sp, sp, #0x1e0
//   0x127154: A91A63FC  stp      x28, x24, [sp, #0x1a0]
//   0x127158: A91B5BF7  stp      x23, x22, [sp, #0x1b0]
//   0x12715c: A91C53F5  stp      x21, x20, [sp, #0x1c0]
static inline uint64_t fde_func_1069_0x127150(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x127150ULL ^ (static_cast<uint64_t>(0xd10783ffULL) << 13);
    acc = (acc + a1 + 0xa91a63fcULL) ^ 0x083cb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1070 | PC: 0x127a50 | FDE: 0x083d58 | Size: 256 bytes
// Khung tháo gỡ #1070 | Địa chỉ PC: 0x127a50 | Địa chỉ FDE: 0x083d58 | Kích thước: 256 bytes
//   0x127a50: AA1E03E1  mov      x1, x30
//   0x127a54: 94017B6C  bl       #0x186804
//   0x127a58: AA0103FE  mov      x30, x1
//   0x127a5c: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_1070_0x127a50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x127a50ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x94017b6cULL) ^ 0x083d58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1071 | PC: 0x127e4c | FDE: 0x083df0 | Size: 256 bytes
// Khung tháo gỡ #1071 | Địa chỉ PC: 0x127e4c | Địa chỉ FDE: 0x083df0 | Kích thước: 256 bytes
//   0x127e4c: D10183FF  sub      sp, sp, #0x60
//   0x127e50: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x127e54: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x127e58: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1071_0x127e4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x127e4cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9035bf7ULL) ^ 0x083df0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1072 | PC: 0x127fbc | FDE: 0x083e58 | Size: 256 bytes
// Khung tháo gỡ #1072 | Địa chỉ PC: 0x127fbc | Địa chỉ FDE: 0x083e58 | Kích thước: 256 bytes
//   0x127fbc: AA1E03E2  mov      x2, x30
//   0x127fc0: 940141E8  bl       #0x178760
//   0x127fc4: AA0203FE  mov      x30, x2
//   0x127fc8: A9167BF3  stp      x19, x30, [sp, #0x160]
static inline uint64_t fde_func_1072_0x127fbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x127fbcULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x940141e8ULL) ^ 0x083e58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1073 | PC: 0x128100 | FDE: 0x083ed0 | Size: 124 bytes
// Khung tháo gỡ #1073 | Địa chỉ PC: 0x128100 | Địa chỉ FDE: 0x083ed0 | Kích thước: 124 bytes
//   0x128100: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x128104: 9401430C  bl       #0x178d34
//   0x128108: 97FFD6F1  bl       #0x11dccc
//   0x12810c: F9400660  ldr      x0, [x19, #8]
static inline uint64_t fde_func_1073_0x128100(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x128100ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9401430cULL) ^ 0x083ed0ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1074 | PC: 0x12817c | FDE: 0x083f30 | Size: 120 bytes
// Khung tháo gỡ #1074 | Địa chỉ PC: 0x12817c | Địa chỉ FDE: 0x083f30 | Kích thước: 120 bytes
//   0x12817c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x128180: AA0003F3  mov      x19, x0
//   0x128184: 97FE288F  bl       #0xb23c0
//   0x128188: B0000348  adrp     x8, #0x191000
static inline uint64_t fde_func_1074_0x12817c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12817cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x083f30ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1075 | PC: 0x1281f4 | FDE: 0x083f90 | Size: 256 bytes
// Khung tháo gỡ #1075 | Địa chỉ PC: 0x1281f4 | Địa chỉ FDE: 0x083f90 | Kích thước: 256 bytes
//   0x1281f4: D10343FF  sub      sp, sp, #0xd0
//   0x1281f8: F90053F6  str      x22, [sp, #0xa0]
//   0x1281fc: A90B53F5  stp      x21, x20, [sp, #0xb0]
//   0x128200: A90C7BF3  stp      x19, x30, [sp, #0xc0]
static inline uint64_t fde_func_1075_0x1281f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1281f4ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf90053f6ULL) ^ 0x083f90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1076 | PC: 0x12837c | FDE: 0x084000 | Size: 256 bytes
// Khung tháo gỡ #1076 | Địa chỉ PC: 0x12837c | Địa chỉ FDE: 0x084000 | Kích thước: 256 bytes
//   0x12837c: F9400408  ldr      x8, [x0, #8]
//   0x128380: B0000349  adrp     x9, #0x191000
//   0x128384: 913E6129  add      x9, x9, #0xf98
//   0x128388: F9000009  str      x9, [x0]
static inline uint64_t fde_func_1076_0x12837c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12837cULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xb0000349ULL) ^ 0x084000ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1077 | PC: 0x128514 | FDE: 0x084070 | Size: 256 bytes
// Khung tháo gỡ #1077 | Địa chỉ PC: 0x128514 | Địa chỉ FDE: 0x084070 | Kích thước: 256 bytes
//   0x128514: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x128518: AA0003F3  mov      x19, x0
//   0x12851c: 97FFFFF8  bl       #0x1284fc
//   0x128520: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1077_0x128514(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x128514ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x084070ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1078 | PC: 0x128684 | FDE: 0x0840e0 | Size: 256 bytes
// Khung tháo gỡ #1078 | Địa chỉ PC: 0x128684 | Địa chỉ FDE: 0x0840e0 | Kích thước: 256 bytes
//   0x128684: F9400408  ldr      x8, [x0, #8]
//   0x128688: D0000349  adrp     x9, #0x192000
//   0x12868c: 91002129  add      x9, x9, #8
//   0x128690: F9000009  str      x9, [x0]
static inline uint64_t fde_func_1078_0x128684(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x128684ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xd0000349ULL) ^ 0x0840e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1079 | PC: 0x1287e4 | FDE: 0x084150 | Size: 256 bytes
// Khung tháo gỡ #1079 | Địa chỉ PC: 0x1287e4 | Địa chỉ FDE: 0x084150 | Kích thước: 256 bytes
//   0x1287e4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1287e8: AA0003F3  mov      x19, x0
//   0x1287ec: 97FFFFF8  bl       #0x1287cc
//   0x1287f0: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1079_0x1287e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1287e4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x084150ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1080 | PC: 0x12895c | FDE: 0x0841b8 | Size: 144 bytes
// Khung tháo gỡ #1080 | Địa chỉ PC: 0x12895c | Địa chỉ FDE: 0x0841b8 | Kích thước: 144 bytes
//   0x12895c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x128960: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x128964: 94015563  bl       #0x17def0
//   0x128968: F9401668  ldr      x8, [x19, #0x28]
static inline uint64_t fde_func_1080_0x12895c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12895cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0841b8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1081 | PC: 0x1289ec | FDE: 0x084220 | Size: 256 bytes
// Khung tháo gỡ #1081 | Địa chỉ PC: 0x1289ec | Địa chỉ FDE: 0x084220 | Kích thước: 256 bytes
//   0x1289ec: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1289f0: AA0003F3  mov      x19, x0
//   0x1289f4: 97FFFFF8  bl       #0x1289d4
//   0x1289f8: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1081_0x1289ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1289ecULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x084220ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1082 | PC: 0x128c30 | FDE: 0x084298 | Size: 212 bytes
// Khung tháo gỡ #1082 | Địa chỉ PC: 0x128c30 | Địa chỉ FDE: 0x084298 | Kích thước: 212 bytes
//   0x128c30: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x128c34: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x128c38: F9400028  ldr      x8, [x1]
//   0x128c3c: F900003F  str      xzr, [x1]
static inline uint64_t fde_func_1082_0x128c30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x128c30ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x084298ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1083 | PC: 0x128d04 | FDE: 0x084300 | Size: 120 bytes
// Khung tháo gỡ #1083 | Địa chỉ PC: 0x128d04 | Địa chỉ FDE: 0x084300 | Kích thước: 120 bytes
//   0x128d04: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x128d08: AA0003F3  mov      x19, x0
//   0x128d0c: 97FFFFF8  bl       #0x128cec
//   0x128d10: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1083_0x128d04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x128d04ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x084300ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1084 | PC: 0x128d7c | FDE: 0x084360 | Size: 256 bytes
// Khung tháo gỡ #1084 | Địa chỉ PC: 0x128d7c | Địa chỉ FDE: 0x084360 | Kích thước: 256 bytes
//   0x128d7c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x128d80: 94013D14  bl       #0x1781d0
//   0x128d84: 97FFFFCD  bl       #0x128cb8
//   0x128d88: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1084_0x128d7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x128d7cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94013d14ULL) ^ 0x084360ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1085 | PC: 0x1290fc | FDE: 0x0843e8 | Size: 100 bytes
// Khung tháo gỡ #1085 | Địa chỉ PC: 0x1290fc | Địa chỉ FDE: 0x0843e8 | Kích thước: 100 bytes
//   0x1290fc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x129100: 94013F0D  bl       #0x178d34
//   0x129104: 94000004  bl       #0x129114
//   0x129108: F9400660  ldr      x0, [x19, #8]
static inline uint64_t fde_func_1085_0x1290fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1290fcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94013f0dULL) ^ 0x0843e8ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1086 | PC: 0x129160 | FDE: 0x084448 | Size: 172 bytes
// Khung tháo gỡ #1086 | Địa chỉ PC: 0x129160 | Địa chỉ FDE: 0x084448 | Kích thước: 172 bytes
//   0x129160: AA1E03E2  mov      x2, x30
//   0x129164: 94013AC8  bl       #0x177c84
//   0x129168: AA0203FE  mov      x30, x2
//   0x12916c: 17FFFF61  b        #0x128ef0
static inline uint64_t fde_func_1086_0x129160(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129160ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94013ac8ULL) ^ 0x084448ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1087 | PC: 0x12920c | FDE: 0x0844b0 | Size: 72 bytes
// Khung tháo gỡ #1087 | Địa chỉ PC: 0x12920c | Địa chỉ FDE: 0x0844b0 | Kích thước: 72 bytes
//   0x12920c: 91006000  add      x0, x0, #0x18
//   0x129210: 14000001  b        #0x129214
//   0x129214: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x129218: 9401441F  bl       #0x17a294
static inline uint64_t fde_func_1087_0x12920c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12920cULL ^ (static_cast<uint64_t>(0x91006000ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x0844b0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1088 | PC: 0x129254 | FDE: 0x084510 | Size: 232 bytes
// Khung tháo gỡ #1088 | Địa chỉ PC: 0x129254 | Địa chỉ FDE: 0x084510 | Kích thước: 232 bytes
//   0x129254: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x129258: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x12925c: AA0003F5  mov      x21, x0
//   0x129260: F9400C00  ldr      x0, [x0, #0x18]
static inline uint64_t fde_func_1088_0x129254(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129254ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x084510ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1089 | PC: 0x12933c | FDE: 0x084578 | Size: 256 bytes
// Khung tháo gỡ #1089 | Địa chỉ PC: 0x12933c | Địa chỉ FDE: 0x084578 | Kích thước: 256 bytes
//   0x12933c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x129340: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x129344: F90007E1  str      x1, [sp, #8]
//   0x129348: 91004000  add      x0, x0, #0x10
static inline uint64_t fde_func_1089_0x12933c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12933cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x084578ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1090 | PC: 0x129448 | FDE: 0x0845f0 | Size: 256 bytes
// Khung tháo gỡ #1090 | Địa chỉ PC: 0x129448 | Địa chỉ FDE: 0x0845f0 | Kích thước: 256 bytes
//   0x129448: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x12944c: F90007E1  str      x1, [sp, #8]
//   0x129450: 91004000  add      x0, x0, #0x10
//   0x129454: 910023E1  add      x1, sp, #8
static inline uint64_t fde_func_1090_0x129448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129448ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf90007e1ULL) ^ 0x0845f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1091 | PC: 0x1295ec | FDE: 0x084670 | Size: 256 bytes
// Khung tháo gỡ #1091 | Địa chỉ PC: 0x1295ec | Địa chỉ FDE: 0x084670 | Kích thước: 256 bytes
//   0x1295ec: AA1E03E3  mov      x3, x30
//   0x1295f0: 94014611  bl       #0x17ae34
//   0x1295f4: AA0303FE  mov      x30, x3
//   0x1295f8: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1091_0x1295ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1295ecULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94014611ULL) ^ 0x084670ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1092 | PC: 0x1298b8 | FDE: 0x0846f0 | Size: 188 bytes [_ZN4lynx6canvas15NapiMediaStream4InitENSt6__ndk110unique_ptrINS0_11MediaStreamENS2_14default_deleteIS4_EEEE]
// Khung tháo gỡ #1092 | Địa chỉ PC: 0x1298b8 | Địa chỉ FDE: 0x0846f0 | Kích thước: 188 bytes
//   0x1298b8: D10203FF  sub      sp, sp, #0x80
//   0x1298bc: F90033F4  str      x20, [sp, #0x60]
//   0x1298c0: A9077BF3  stp      x19, x30, [sp, #0x70]
//   0x1298c4: 94013737  bl       #0x1775a0
static inline uint64_t fde_func_1092_0x1298b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1298b8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90033f4ULL) ^ 0x0846f0ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1093 | PC: 0x129974 | FDE: 0x084760 | Size: 64 bytes
// Khung tháo gỡ #1093 | Địa chỉ PC: 0x129974 | Địa chỉ FDE: 0x084760 | Kích thước: 64 bytes
//   0x129974: F9401C08  ldr      x8, [x0, #0x38]
//   0x129978: F9400420  ldr      x0, [x1, #8]
//   0x12997c: B9402108  ldr      w8, [x8, #0x20]
//   0x129980: 14014421  b        #0x17aa04
static inline uint64_t fde_func_1093_0x129974(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129974ULL ^ (static_cast<uint64_t>(0xf9401c08ULL) << 13);
    acc = (acc + a1 + 0xf9400420ULL) ^ 0x084760ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1094 | PC: 0x1299b4 | FDE: 0x0847c0 | Size: 256 bytes
// Khung tháo gỡ #1094 | Địa chỉ PC: 0x1299b4 | Địa chỉ FDE: 0x0847c0 | Kích thước: 256 bytes
//   0x1299b4: F9401C08  ldr      x8, [x0, #0x38]
//   0x1299b8: F9400420  ldr      x0, [x1, #8]
//   0x1299bc: B9403908  ldr      w8, [x8, #0x38]
//   0x1299c0: 14014411  b        #0x17aa04
static inline uint64_t fde_func_1094_0x1299b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1299b4ULL ^ (static_cast<uint64_t>(0xf9401c08ULL) << 13);
    acc = (acc + a1 + 0xf9400420ULL) ^ 0x0847c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1095 | PC: 0x129b08 | FDE: 0x084830 | Size: 72 bytes
// Khung tháo gỡ #1095 | Địa chỉ PC: 0x129b08 | Địa chỉ FDE: 0x084830 | Kích thước: 72 bytes
//   0x129b08: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x129b0c: AA0003F3  mov      x19, x0
//   0x129b10: 97FFFFE3  bl       #0x129a9c
//   0x129b14: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1095_0x129b08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129b08ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x084830ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1096 | PC: 0x129b50 | FDE: 0x084860 | Size: 256 bytes [_ZN4lynx6canvas23NapiCanvasCommandBuffer22RegisterBufferedObjectEPN4Napi15ScriptWrappableE]
// Khung tháo gỡ #1096 | Địa chỉ PC: 0x129b50 | Địa chỉ FDE: 0x084860 | Kích thước: 256 bytes
//   0x129b50: AA1E03E1  mov      x1, x30
//   0x129b54: 94014790  bl       #0x17b994
//   0x129b58: AA0103FE  mov      x30, x1
//   0x129b5c: A9167BF3  stp      x19, x30, [sp, #0x160]
static inline uint64_t fde_func_1096_0x129b50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129b50ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x94014790ULL) ^ 0x084860ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1097 | PC: 0x129d58 | FDE: 0x0848a0 | Size: 256 bytes [_ZN4lynx6canvas23NapiCanvasCommandBuffer24UnregisterBufferedObjectEPN4Napi15ScriptWrappableEj]
// Khung tháo gỡ #1097 | Địa chỉ PC: 0x129d58 | Địa chỉ FDE: 0x0848a0 | Kích thước: 256 bytes
//   0x129d58: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x129d5c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x129d60: 2A0103F4  mov      w20, w1
//   0x129d64: 97FFFFE8  bl       #0x129d04
static inline uint64_t fde_func_1097_0x129d58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129d58ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0848a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1098 | PC: 0x129f64 | FDE: 0x084918 | Size: 256 bytes
// Khung tháo gỡ #1098 | Địa chỉ PC: 0x129f64 | Địa chỉ FDE: 0x084918 | Kích thước: 256 bytes
//   0x129f64: AA1E03E1  mov      x1, x30
//   0x129f68: 94016145  bl       #0x18247c
//   0x129f6c: AA0103FE  mov      x30, x1
//   0x129f70: A90E7BF3  stp      x19, x30, [sp, #0xe0]
static inline uint64_t fde_func_1098_0x129f64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129f64ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x94016145ULL) ^ 0x084918ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1099 | PC: 0x12a160 | FDE: 0x084990 | Size: 256 bytes
// Khung tháo gỡ #1099 | Địa chỉ PC: 0x12a160 | Địa chỉ FDE: 0x084990 | Kích thước: 256 bytes
//   0x12a160: AA1E03E3  mov      x3, x30
//   0x12a164: 940135BB  bl       #0x177850
//   0x12a168: AA0303FE  mov      x30, x3
//   0x12a16c: A9197BFD  stp      x29, x30, [sp, #0x190]
static inline uint64_t fde_func_1099_0x12a160(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12a160ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x940135bbULL) ^ 0x084990ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1100 | PC: 0x12a468 | FDE: 0x084a20 | Size: 256 bytes
// Khung tháo gỡ #1100 | Địa chỉ PC: 0x12a468 | Địa chỉ FDE: 0x084a20 | Kích thước: 256 bytes
//   0x12a468: AA1E03E4  mov      x4, x30
//   0x12a46c: 940137A8  bl       #0x17830c
//   0x12a470: AA0403FE  mov      x30, x4
//   0x12a474: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_1100_0x12a468(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12a468ULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x940137a8ULL) ^ 0x084a20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1101 | PC: 0x12a954 | FDE: 0x084aa8 | Size: 256 bytes
// Khung tháo gỡ #1101 | Địa chỉ PC: 0x12a954 | Địa chỉ FDE: 0x084aa8 | Kích thước: 256 bytes
//   0x12a954: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x12a958: AA0003F3  mov      x19, x0
//   0x12a95c: 97FFFFF4  bl       #0x12a92c
//   0x12a960: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1101_0x12a954(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12a954ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x084aa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1102 | PC: 0x12d038 | FDE: 0x084b30 | Size: 256 bytes
// Khung tháo gỡ #1102 | Địa chỉ PC: 0x12d038 | Địa chỉ FDE: 0x084b30 | Kích thước: 256 bytes
//   0x12d038: 51000449  sub      w9, w2, #1
//   0x12d03c: 52800028  mov      w8, #1
//   0x12d040: 7100293F  cmp      w9, #0xa
//   0x12d044: A9007C1F  stp      xzr, xzr, [x0]
static inline uint64_t fde_func_1102_0x12d038(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12d038ULL ^ (static_cast<uint64_t>(0x51000449ULL) << 13);
    acc = (acc + a1 + 0x52800028ULL) ^ 0x084b30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1103 | PC: 0x12d168 | FDE: 0x084b90 | Size: 256 bytes
// Khung tháo gỡ #1103 | Địa chỉ PC: 0x12d168 | Địa chỉ FDE: 0x084b90 | Kích thước: 256 bytes
//   0x12d168: D102C3FF  sub      sp, sp, #0xb0
//   0x12d16c: A90763F9  stp      x25, x24, [sp, #0x70]
//   0x12d170: A9085BF7  stp      x23, x22, [sp, #0x80]
//   0x12d174: A90953F5  stp      x21, x20, [sp, #0x90]
static inline uint64_t fde_func_1103_0x12d168(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12d168ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa90763f9ULL) ^ 0x084b90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1104 | PC: 0x12d620 | FDE: 0x084c28 | Size: 256 bytes
// Khung tháo gỡ #1104 | Địa chỉ PC: 0x12d620 | Địa chỉ FDE: 0x084c28 | Kích thước: 256 bytes
//   0x12d620: D10203FF  sub      sp, sp, #0x80
//   0x12d624: F90033F4  str      x20, [sp, #0x60]
//   0x12d628: A9077BF3  stp      x19, x30, [sp, #0x70]
//   0x12d62c: 940132DE  bl       #0x17a1a4
static inline uint64_t fde_func_1104_0x12d620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12d620ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90033f4ULL) ^ 0x084c28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1105 | PC: 0x12d804 | FDE: 0x084ca8 | Size: 256 bytes [_ZN4lynx6canvas16NapiVideoElement12ToImplUnsafeEv]
// Khung tháo gỡ #1105 | Địa chỉ PC: 0x12d804 | Địa chỉ FDE: 0x084ca8 | Kích thước: 256 bytes
//   0x12d804: 14015EDF  b        #0x185380
//   0x12d808: A9BC63FC  stp      x28, x24, [sp, #-0x40]!
//   0x12d80c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x12d810: A90253F5  stp      x21, x20, [sp, #0x20]
static inline uint64_t fde_func_1105_0x12d804(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12d804ULL ^ (static_cast<uint64_t>(0x14015edfULL) << 13);
    acc = (acc + a1 + 0xa9bc63fcULL) ^ 0x084ca8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1106 | PC: 0x12daa4 | FDE: 0x084d20 | Size: 212 bytes
// Khung tháo gỡ #1106 | Địa chỉ PC: 0x12daa4 | Địa chỉ FDE: 0x084d20 | Kích thước: 212 bytes
//   0x12daa4: AA1E03E6  mov      x6, x30
//   0x12daa8: 9401343C  bl       #0x17ab98
//   0x12daac: AA0603FE  mov      x30, x6
//   0x12dab0: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1106_0x12daa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12daa4ULL ^ (static_cast<uint64_t>(0xaa1e03e6ULL) << 13);
    acc = (acc + a1 + 0x9401343cULL) ^ 0x084d20ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1107 | PC: 0x12db78 | FDE: 0x084d98 | Size: 172 bytes
// Khung tháo gỡ #1107 | Địa chỉ PC: 0x12db78 | Địa chỉ FDE: 0x084d98 | Kích thước: 172 bytes
//   0x12db78: D10103FF  sub      sp, sp, #0x40
//   0x12db7c: F90013F4  str      x20, [sp, #0x20]
//   0x12db80: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x12db84: 94012D7B  bl       #0x179170
static inline uint64_t fde_func_1107_0x12db78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12db78ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f4ULL) ^ 0x084d98ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1108 | PC: 0x12dc24 | FDE: 0x084e08 | Size: 256 bytes
// Khung tháo gỡ #1108 | Địa chỉ PC: 0x12dc24 | Địa chỉ FDE: 0x084e08 | Kích thước: 256 bytes
//   0x12dc24: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x12dc28: 940133E4  bl       #0x17abb8
//   0x12dc2c: 97FECD8C  bl       #0xe125c
//   0x12dc30: 9E630000  ucvtf    d0, x0
static inline uint64_t fde_func_1108_0x12dc24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12dc24ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x940133e4ULL) ^ 0x084e08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1109 | PC: 0x12e170 | FDE: 0x084e78 | Size: 256 bytes
// Khung tháo gỡ #1109 | Địa chỉ PC: 0x12e170 | Địa chỉ FDE: 0x084e78 | Kích thước: 256 bytes
//   0x12e170: AA1E03E2  mov      x2, x30
//   0x12e174: 94014F57  bl       #0x181ed0
//   0x12e178: AA0203FE  mov      x30, x2
//   0x12e17c: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1109_0x12e170(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12e170ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94014f57ULL) ^ 0x084e78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1110 | PC: 0x12e5b4 | FDE: 0x084f08 | Size: 256 bytes
// Khung tháo gỡ #1110 | Địa chỉ PC: 0x12e5b4 | Địa chỉ FDE: 0x084f08 | Kích thước: 256 bytes
//   0x12e5b4: D10303FF  sub      sp, sp, #0xc0
//   0x12e5b8: A9095BF7  stp      x23, x22, [sp, #0x90]
//   0x12e5bc: A90A53F5  stp      x21, x20, [sp, #0xa0]
//   0x12e5c0: A90B7BF3  stp      x19, x30, [sp, #0xb0]
static inline uint64_t fde_func_1110_0x12e5b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12e5b4ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9095bf7ULL) ^ 0x084f08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1111 | PC: 0x12e748 | FDE: 0x084f80 | Size: 256 bytes
// Khung tháo gỡ #1111 | Địa chỉ PC: 0x12e748 | Địa chỉ FDE: 0x084f80 | Kích thước: 256 bytes
//   0x12e748: D10243FF  sub      sp, sp, #0x90
//   0x12e74c: A9065BF7  stp      x23, x22, [sp, #0x60]
//   0x12e750: A90753F5  stp      x21, x20, [sp, #0x70]
//   0x12e754: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_1111_0x12e748(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12e748ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9065bf7ULL) ^ 0x084f80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1112 | PC: 0x12eab0 | FDE: 0x085018 | Size: 256 bytes
// Khung tháo gỡ #1112 | Địa chỉ PC: 0x12eab0 | Địa chỉ FDE: 0x085018 | Kích thước: 256 bytes
//   0x12eab0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x12eab4: 94013D40  bl       #0x17dfb4
//   0x12eab8: 9400839B  bl       #0x14f924
//   0x12eabc: F9000260  str      x0, [x19]
static inline uint64_t fde_func_1112_0x12eab0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12eab0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94013d40ULL) ^ 0x085018ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1113 | PC: 0x12ed78 | FDE: 0x0850a0 | Size: 256 bytes
// Khung tháo gỡ #1113 | Địa chỉ PC: 0x12ed78 | Địa chỉ FDE: 0x0850a0 | Kích thước: 256 bytes
//   0x12ed78: D10303FF  sub      sp, sp, #0xc0
//   0x12ed7c: A9095BF7  stp      x23, x22, [sp, #0x90]
//   0x12ed80: A90A53F5  stp      x21, x20, [sp, #0xa0]
//   0x12ed84: A90B7BF3  stp      x19, x30, [sp, #0xb0]
static inline uint64_t fde_func_1113_0x12ed78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ed78ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9095bf7ULL) ^ 0x0850a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1114 | PC: 0x12f8fc | FDE: 0x085130 | Size: 220 bytes
// Khung tháo gỡ #1114 | Địa chỉ PC: 0x12f8fc | Địa chỉ FDE: 0x085130 | Kích thước: 220 bytes
//   0x12f8fc: AA1E03E6  mov      x6, x30
//   0x12f900: 94012CA6  bl       #0x17ab98
//   0x12f904: AA0603FE  mov      x30, x6
//   0x12f908: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1114_0x12f8fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12f8fcULL ^ (static_cast<uint64_t>(0xaa1e03e6ULL) << 13);
    acc = (acc + a1 + 0x94012ca6ULL) ^ 0x085130ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #1115 | PC: 0x12f9d8 | FDE: 0x0851a8 | Size: 248 bytes
// Khung tháo gỡ #1115 | Địa chỉ PC: 0x12f9d8 | Địa chỉ FDE: 0x0851a8 | Kích thước: 248 bytes
//   0x12f9d8: D10143FF  sub      sp, sp, #0x50
//   0x12f9dc: F9001BF4  str      x20, [sp, #0x30]
//   0x12f9e0: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x12f9e4: 94011CD8  bl       #0x176d44
static inline uint64_t fde_func_1115_0x12f9d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12f9d8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf4ULL) ^ 0x0851a8ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1116 | PC: 0x12fad0 | FDE: 0x085220 | Size: 256 bytes
// Khung tháo gỡ #1116 | Địa chỉ PC: 0x12fad0 | Địa chỉ FDE: 0x085220 | Kích thước: 256 bytes
//   0x12fad0: D10203FF  sub      sp, sp, #0x80
//   0x12fad4: F9002BF6  str      x22, [sp, #0x50]
//   0x12fad8: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x12fadc: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1116_0x12fad0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12fad0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf6ULL) ^ 0x085220ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1117 | PC: 0x12fd40 | FDE: 0x0852a0 | Size: 256 bytes
// Khung tháo gỡ #1117 | Địa chỉ PC: 0x12fd40 | Địa chỉ FDE: 0x0852a0 | Kích thước: 256 bytes
//   0x12fd40: D10203FF  sub      sp, sp, #0x80
//   0x12fd44: F9002BF6  str      x22, [sp, #0x50]
//   0x12fd48: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x12fd4c: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1117_0x12fd40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12fd40ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf6ULL) ^ 0x0852a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1118 | PC: 0x12fe64 | FDE: 0x085308 | Size: 148 bytes
// Khung tháo gỡ #1118 | Địa chỉ PC: 0x12fe64 | Địa chỉ FDE: 0x085308 | Kích thước: 148 bytes
//   0x12fe64: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x12fe68: 940127D7  bl       #0x179dc4
//   0x12fe6c: 94011ECE  bl       #0x1779a4
//   0x12fe70: F9407101  ldr      x1, [x8, #0xe0]
static inline uint64_t fde_func_1118_0x12fe64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12fe64ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x940127d7ULL) ^ 0x085308ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1119 | PC: 0x12fef8 | FDE: 0x085370 | Size: 196 bytes
// Khung tháo gỡ #1119 | Địa chỉ PC: 0x12fef8 | Địa chỉ FDE: 0x085370 | Kích thước: 196 bytes
//   0x12fef8: D10143FF  sub      sp, sp, #0x50
//   0x12fefc: F9001BF4  str      x20, [sp, #0x30]
//   0x12ff00: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x12ff04: 94011B90  bl       #0x176d44
static inline uint64_t fde_func_1119_0x12fef8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12fef8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf4ULL) ^ 0x085370ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1120 | PC: 0x12ffbc | FDE: 0x0853e0 | Size: 244 bytes
// Khung tháo gỡ #1120 | Địa chỉ PC: 0x12ffbc | Địa chỉ FDE: 0x0853e0 | Kích thước: 244 bytes
//   0x12ffbc: D10143FF  sub      sp, sp, #0x50
//   0x12ffc0: F9001BF4  str      x20, [sp, #0x30]
//   0x12ffc4: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x12ffc8: 94011B5F  bl       #0x176d44
static inline uint64_t fde_func_1120_0x12ffbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ffbcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf4ULL) ^ 0x0853e0ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #1121 | PC: 0x1300b0 | FDE: 0x085458 | Size: 148 bytes
// Khung tháo gỡ #1121 | Địa chỉ PC: 0x1300b0 | Địa chỉ FDE: 0x085458 | Kích thước: 148 bytes
//   0x1300b0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1300b4: 94012744  bl       #0x179dc4
//   0x1300b8: 94011E3B  bl       #0x1779a4
//   0x1300bc: F9405101  ldr      x1, [x8, #0xa0]
static inline uint64_t fde_func_1121_0x1300b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1300b0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94012744ULL) ^ 0x085458ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1122 | PC: 0x130144 | FDE: 0x0854c0 | Size: 256 bytes
// Khung tháo gỡ #1122 | Địa chỉ PC: 0x130144 | Địa chỉ FDE: 0x0854c0 | Kích thước: 256 bytes
//   0x130144: D10143FF  sub      sp, sp, #0x50
//   0x130148: F9001BF4  str      x20, [sp, #0x30]
//   0x13014c: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x130150: 94011AFD  bl       #0x176d44
static inline uint64_t fde_func_1122_0x130144(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130144ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf4ULL) ^ 0x0854c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1123 | PC: 0x130264 | FDE: 0x085540 | Size: 256 bytes
// Khung tháo gỡ #1123 | Địa chỉ PC: 0x130264 | Địa chỉ FDE: 0x085540 | Kích thước: 256 bytes
//   0x130264: D10143FF  sub      sp, sp, #0x50
//   0x130268: F9001BF4  str      x20, [sp, #0x30]
//   0x13026c: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x130270: 94011AB5  bl       #0x176d44
static inline uint64_t fde_func_1123_0x130264(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130264ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf4ULL) ^ 0x085540ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1124 | PC: 0x130384 | FDE: 0x0855c0 | Size: 256 bytes
// Khung tháo gỡ #1124 | Địa chỉ PC: 0x130384 | Địa chỉ FDE: 0x0855c0 | Kích thước: 256 bytes
//   0x130384: D100C3FF  sub      sp, sp, #0x30
//   0x130388: F9000BF4  str      x20, [sp, #0x10]
//   0x13038c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x130390: 94011D69  bl       #0x177934
static inline uint64_t fde_func_1124_0x130384(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130384ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x0855c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1125 | PC: 0x13049c | FDE: 0x085640 | Size: 256 bytes
// Khung tháo gỡ #1125 | Địa chỉ PC: 0x13049c | Địa chỉ FDE: 0x085640 | Kích thước: 256 bytes
//   0x13049c: D100C3FF  sub      sp, sp, #0x30
//   0x1304a0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1304a4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1304a8: 94014C06  bl       #0x1834c0
static inline uint64_t fde_func_1125_0x13049c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13049cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x085640ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1126 | PC: 0x1306f8 | FDE: 0x0856e0 | Size: 256 bytes
// Khung tháo gỡ #1126 | Địa chỉ PC: 0x1306f8 | Địa chỉ FDE: 0x0856e0 | Kích thước: 256 bytes
//   0x1306f8: D10243FF  sub      sp, sp, #0x90
//   0x1306fc: A9065BF7  stp      x23, x22, [sp, #0x60]
//   0x130700: A90753F5  stp      x21, x20, [sp, #0x70]
//   0x130704: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_1126_0x1306f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1306f8ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9065bf7ULL) ^ 0x0856e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1127 | PC: 0x130adc | FDE: 0x085780 | Size: 256 bytes
// Khung tháo gỡ #1127 | Địa chỉ PC: 0x130adc | Địa chỉ FDE: 0x085780 | Kích thước: 256 bytes
//   0x130adc: D102C3FF  sub      sp, sp, #0xb0
//   0x130ae0: F90043F6  str      x22, [sp, #0x80]
//   0x130ae4: A90953F5  stp      x21, x20, [sp, #0x90]
//   0x130ae8: A90A7BF3  stp      x19, x30, [sp, #0xa0]
static inline uint64_t fde_func_1127_0x130adc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130adcULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90043f6ULL) ^ 0x085780ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1128 | PC: 0x130e34 | FDE: 0x085818 | Size: 256 bytes
// Khung tháo gỡ #1128 | Địa chỉ PC: 0x130e34 | Địa chỉ FDE: 0x085818 | Kích thước: 256 bytes
//   0x130e34: D100C3FF  sub      sp, sp, #0x30
//   0x130e38: F9000BF4  str      x20, [sp, #0x10]
//   0x130e3c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x130e40: 94011ABD  bl       #0x177934
static inline uint64_t fde_func_1128_0x130e34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130e34ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x085818ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1129 | PC: 0x13103c | FDE: 0x085898 | Size: 256 bytes
// Khung tháo gỡ #1129 | Địa chỉ PC: 0x13103c | Địa chỉ FDE: 0x085898 | Kích thước: 256 bytes
//   0x13103c: D10103FF  sub      sp, sp, #0x40
//   0x131040: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x131044: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x131048: 9401170E  bl       #0x176c80
static inline uint64_t fde_func_1129_0x13103c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13103cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x085898ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1130 | PC: 0x1313d8 | FDE: 0x085930 | Size: 256 bytes
// Khung tháo gỡ #1130 | Địa chỉ PC: 0x1313d8 | Địa chỉ FDE: 0x085930 | Kích thước: 256 bytes
//   0x1313d8: AA1E03E2  mov      x2, x30
//   0x1313dc: 940142BD  bl       #0x181ed0
//   0x1313e0: AA0203FE  mov      x30, x2
//   0x1313e4: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1130_0x1313d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1313d8ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x940142bdULL) ^ 0x085930ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1131 | PC: 0x131e10 | FDE: 0x0859e8 | Size: 256 bytes
// Khung tháo gỡ #1131 | Địa chỉ PC: 0x131e10 | Địa chỉ FDE: 0x0859e8 | Kích thước: 256 bytes
//   0x131e10: D10303FF  sub      sp, sp, #0xc0
//   0x131e14: A9076BFB  stp      x27, x26, [sp, #0x70]
//   0x131e18: A90863F9  stp      x25, x24, [sp, #0x80]
//   0x131e1c: A9095BF7  stp      x23, x22, [sp, #0x90]
static inline uint64_t fde_func_1131_0x131e10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131e10ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9076bfbULL) ^ 0x0859e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1132 | PC: 0x1322e8 | FDE: 0x085a88 | Size: 256 bytes
// Khung tháo gỡ #1132 | Địa chỉ PC: 0x1322e8 | Địa chỉ FDE: 0x085a88 | Kích thước: 256 bytes
//   0x1322e8: D10103FF  sub      sp, sp, #0x40
//   0x1322ec: FD000BE8  str      d8, [sp, #0x10]
//   0x1322f0: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1322f4: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1132_0x1322e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1322e8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xfd000be8ULL) ^ 0x085a88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1133 | PC: 0x1324d8 | FDE: 0x085b20 | Size: 256 bytes
// Khung tháo gỡ #1133 | Địa chỉ PC: 0x1324d8 | Địa chỉ FDE: 0x085b20 | Kích thước: 256 bytes
//   0x1324d8: D10203FF  sub      sp, sp, #0x80
//   0x1324dc: 6D042BEB  stp      d11, d10, [sp, #0x40]
//   0x1324e0: 6D0523E9  stp      d9, d8, [sp, #0x50]
//   0x1324e4: A90653F5  stp      x21, x20, [sp, #0x60]
static inline uint64_t fde_func_1133_0x1324d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1324d8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0x6d042bebULL) ^ 0x085b20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1134 | PC: 0x1327e4 | FDE: 0x085be0 | Size: 256 bytes
// Khung tháo gỡ #1134 | Địa chỉ PC: 0x1327e4 | Địa chỉ FDE: 0x085be0 | Kích thước: 256 bytes
//   0x1327e4: D10303FF  sub      sp, sp, #0xc0
//   0x1327e8: A9095BF7  stp      x23, x22, [sp, #0x90]
//   0x1327ec: A90A53F5  stp      x21, x20, [sp, #0xa0]
//   0x1327f0: A90B7BF3  stp      x19, x30, [sp, #0xb0]
static inline uint64_t fde_func_1134_0x1327e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1327e4ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9095bf7ULL) ^ 0x085be0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1135 | PC: 0x132958 | FDE: 0x085c58 | Size: 256 bytes
// Khung tháo gỡ #1135 | Địa chỉ PC: 0x132958 | Địa chỉ FDE: 0x085c58 | Kích thước: 256 bytes
//   0x132958: D100C3FF  sub      sp, sp, #0x30
//   0x13295c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x132960: 940110F1  bl       #0x176d24
//   0x132964: 36000120  tbz      w0, #0, #0x132988
static inline uint64_t fde_func_1135_0x132958(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132958ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9027bf3ULL) ^ 0x085c58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1136 | PC: 0x132d94 | FDE: 0x085ce0 | Size: 256 bytes
// Khung tháo gỡ #1136 | Địa chỉ PC: 0x132d94 | Địa chỉ FDE: 0x085ce0 | Kích thước: 256 bytes
//   0x132d94: D10203FF  sub      sp, sp, #0x80
//   0x132d98: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x132d9c: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x132da0: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1136_0x132d94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132d94ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9055bf7ULL) ^ 0x085ce0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1137 | PC: 0x1331dc | FDE: 0x085d70 | Size: 256 bytes
// Khung tháo gỡ #1137 | Địa chỉ PC: 0x1331dc | Địa chỉ FDE: 0x085d70 | Kích thước: 256 bytes
//   0x1331dc: D100C3FF  sub      sp, sp, #0x30
//   0x1331e0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1331e4: 94010ED0  bl       #0x176d24
//   0x1331e8: 36000120  tbz      w0, #0, #0x13320c
static inline uint64_t fde_func_1137_0x1331dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1331dcULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9027bf3ULL) ^ 0x085d70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1138 | PC: 0x133424 | FDE: 0x085de0 | Size: 80 bytes
// Khung tháo gỡ #1138 | Địa chỉ PC: 0x133424 | Địa chỉ FDE: 0x085de0 | Kích thước: 80 bytes
//   0x133424: D10103FF  sub      sp, sp, #0x40
//   0x133428: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x13342c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x133430: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1138_0x133424(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x133424ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x085de0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1139 | PC: 0x133474 | FDE: 0x085e48 | Size: 48 bytes
// Khung tháo gỡ #1139 | Địa chỉ PC: 0x133474 | Địa chỉ FDE: 0x085e48 | Kích thước: 48 bytes
//   0x133474: 140139BA  b        #0x181b5c
//   0x133478: 140139C1  b        #0x181b7c
//   0x13347c: F9400420  ldr      x0, [x1, #8]
//   0x133480: 52800021  mov      w1, #1
static inline uint64_t fde_func_1139_0x133474(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x133474ULL ^ (static_cast<uint64_t>(0x140139baULL) << 13);
    acc = (acc + a1 + 0x140139c1ULL) ^ 0x085e48ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1140 | PC: 0x1334a4 | FDE: 0x085ea8 | Size: 256 bytes
// Khung tháo gỡ #1140 | Địa chỉ PC: 0x1334a4 | Địa chỉ FDE: 0x085ea8 | Kích thước: 256 bytes
//   0x1334a4: D10303FF  sub      sp, sp, #0xc0
//   0x1334a8: A9095BF7  stp      x23, x22, [sp, #0x90]
//   0x1334ac: A90A53F5  stp      x21, x20, [sp, #0xa0]
//   0x1334b0: A90B7BF3  stp      x19, x30, [sp, #0xb0]
static inline uint64_t fde_func_1140_0x1334a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1334a4ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9095bf7ULL) ^ 0x085ea8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1141 | PC: 0x133710 | FDE: 0x085f20 | Size: 256 bytes
// Khung tháo gỡ #1141 | Địa chỉ PC: 0x133710 | Địa chỉ FDE: 0x085f20 | Kích thước: 256 bytes
//   0x133710: D102C3FF  sub      sp, sp, #0xb0
//   0x133714: A9085BF7  stp      x23, x22, [sp, #0x80]
//   0x133718: A90953F5  stp      x21, x20, [sp, #0x90]
//   0x13371c: A90A7BF3  stp      x19, x30, [sp, #0xa0]
static inline uint64_t fde_func_1141_0x133710(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x133710ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9085bf7ULL) ^ 0x085f20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1142 | PC: 0x1339c8 | FDE: 0x085fa8 | Size: 128 bytes
// Khung tháo gỡ #1142 | Địa chỉ PC: 0x1339c8 | Địa chỉ FDE: 0x085fa8 | Kích thước: 128 bytes
//   0x1339c8: F9401C08  ldr      x8, [x0, #0x38]
//   0x1339cc: F9400420  ldr      x0, [x1, #8]
//   0x1339d0: F9401108  ldr      x8, [x8, #0x20]
//   0x1339d4: FD401500  ldr      d0, [x8, #0x28]
static inline uint64_t fde_func_1142_0x1339c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1339c8ULL ^ (static_cast<uint64_t>(0xf9401c08ULL) << 13);
    acc = (acc + a1 + 0xf9400420ULL) ^ 0x085fa8ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1143 | PC: 0x133a48 | FDE: 0x086010 | Size: 200 bytes
// Khung tháo gỡ #1143 | Địa chỉ PC: 0x133a48 | Địa chỉ FDE: 0x086010 | Kích thước: 200 bytes
//   0x133a48: F9401C08  ldr      x8, [x0, #0x38]
//   0x133a4c: F9400420  ldr      x0, [x1, #8]
//   0x133a50: F9401108  ldr      x8, [x8, #0x20]
//   0x133a54: FD402100  ldr      d0, [x8, #0x40]
static inline uint64_t fde_func_1143_0x133a48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x133a48ULL ^ (static_cast<uint64_t>(0xf9401c08ULL) << 13);
    acc = (acc + a1 + 0xf9400420ULL) ^ 0x086010ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1144 | PC: 0x133b10 | FDE: 0x086078 | Size: 256 bytes
// Khung tháo gỡ #1144 | Địa chỉ PC: 0x133b10 | Địa chỉ FDE: 0x086078 | Kích thước: 256 bytes
//   0x133b10: D101C3FF  sub      sp, sp, #0x70
//   0x133b14: F90023F6  str      x22, [sp, #0x40]
//   0x133b18: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x133b1c: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_1144_0x133b10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x133b10ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f6ULL) ^ 0x086078ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1145 | PC: 0x133d60 | FDE: 0x086108 | Size: 256 bytes
// Khung tháo gỡ #1145 | Địa chỉ PC: 0x133d60 | Địa chỉ FDE: 0x086108 | Kích thước: 256 bytes
//   0x133d60: D10483FF  sub      sp, sp, #0x120
//   0x133d64: A90E63FC  stp      x28, x24, [sp, #0xe0]
//   0x133d68: A90F5BF7  stp      x23, x22, [sp, #0xf0]
//   0x133d6c: A91053F5  stp      x21, x20, [sp, #0x100]
static inline uint64_t fde_func_1145_0x133d60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x133d60ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90e63fcULL) ^ 0x086108ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1146 | PC: 0x13424c | FDE: 0x086190 | Size: 256 bytes
// Khung tháo gỡ #1146 | Địa chỉ PC: 0x13424c | Địa chỉ FDE: 0x086190 | Kích thước: 256 bytes
//   0x13424c: D10103FF  sub      sp, sp, #0x40
//   0x134250: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x134254: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x134258: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1146_0x13424c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13424cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x086190ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1147 | PC: 0x13453c | FDE: 0x086210 | Size: 256 bytes
// Khung tháo gỡ #1147 | Địa chỉ PC: 0x13453c | Địa chỉ FDE: 0x086210 | Kích thước: 256 bytes
//   0x13453c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x134540: B9405001  ldr      w1, [x0, #0x50]
//   0x134544: D00002E8  adrp     x8, #0x192000
//   0x134548: 9114A108  add      x8, x8, #0x528
static inline uint64_t fde_func_1147_0x13453c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13453cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb9405001ULL) ^ 0x086210ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1148 | PC: 0x134664 | FDE: 0x086280 | Size: 256 bytes
// Khung tháo gỡ #1148 | Địa chỉ PC: 0x134664 | Địa chỉ FDE: 0x086280 | Kích thước: 256 bytes
//   0x134664: D10103FF  sub      sp, sp, #0x40
//   0x134668: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x13466c: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x134670: 94010D1B  bl       #0x177adc
static inline uint64_t fde_func_1148_0x134664(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134664ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x086280ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1149 | PC: 0x1348e4 | FDE: 0x086300 | Size: 256 bytes
// Khung tháo gỡ #1149 | Địa chỉ PC: 0x1348e4 | Địa chỉ FDE: 0x086300 | Kích thước: 256 bytes
//   0x1348e4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1348e8: AA0003F3  mov      x19, x0
//   0x1348ec: 97FFFFF6  bl       #0x1348c4
//   0x1348f0: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1149_0x1348e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1348e4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x086300ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1150 | PC: 0x134c80 | FDE: 0x086388 | Size: 120 bytes
// Khung tháo gỡ #1150 | Địa chỉ PC: 0x134c80 | Địa chỉ FDE: 0x086388 | Kích thước: 120 bytes
//   0x134c80: D10103FF  sub      sp, sp, #0x40
//   0x134c84: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x134c88: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x134c8c: 94010B94  bl       #0x177adc
static inline uint64_t fde_func_1150_0x134c80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134c80ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x086388ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1151 | PC: 0x134cf8 | FDE: 0x0863f0 | Size: 240 bytes
// Khung tháo gỡ #1151 | Địa chỉ PC: 0x134cf8 | Địa chỉ FDE: 0x0863f0 | Kích thước: 240 bytes
//   0x134cf8: F9402408  ldr      x8, [x0, #0x48]
//   0x134cfc: F9400420  ldr      x0, [x1, #8]
//   0x134d00: BD407500  ldr      s0, [x8, #0x74]
//   0x134d04: 14012165  b        #0x17d298
static inline uint64_t fde_func_1151_0x134cf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134cf8ULL ^ (static_cast<uint64_t>(0xf9402408ULL) << 13);
    acc = (acc + a1 + 0xf9400420ULL) ^ 0x0863f0ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1152 | PC: 0x134de8 | FDE: 0x086460 | Size: 256 bytes
// Khung tháo gỡ #1152 | Địa chỉ PC: 0x134de8 | Địa chỉ FDE: 0x086460 | Kích thước: 256 bytes
//   0x134de8: D10283FF  sub      sp, sp, #0xa0
//   0x134dec: F9003BF6  str      x22, [sp, #0x70]
//   0x134df0: A90853F5  stp      x21, x20, [sp, #0x80]
//   0x134df4: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_1152_0x134de8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x134de8ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf6ULL) ^ 0x086460ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1153 | PC: 0x1350e4 | FDE: 0x0864c8 | Size: 256 bytes
// Khung tháo gỡ #1153 | Địa chỉ PC: 0x1350e4 | Địa chỉ FDE: 0x0864c8 | Kích thước: 256 bytes
//   0x1350e4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1350e8: 94012CE1  bl       #0x18046c
//   0x1350ec: 97FE03FF  bl       #0xb60e8
//   0x1350f0: 94012932  bl       #0x17f5b8
static inline uint64_t fde_func_1153_0x1350e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1350e4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94012ce1ULL) ^ 0x0864c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1154 | PC: 0x1352d4 | FDE: 0x086548 | Size: 36 bytes
// Khung tháo gỡ #1154 | Địa chỉ PC: 0x1352d4 | Địa chỉ FDE: 0x086548 | Kích thước: 36 bytes
//   0x1352d4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1352d8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1352dc: AA0103F3  mov      x19, x1
//   0x1352e0: 90FFF801  adrp     x1, #0x35000
static inline uint64_t fde_func_1154_0x1352d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1352d4ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x086548ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1155 | PC: 0x1352f8 | FDE: 0x086568 | Size: 148 bytes [_ZN4lynx6canvas15NapiMediaStreamC2ERKN4Napi12CallbackInfoEb]
// Khung tháo gỡ #1155 | Địa chỉ PC: 0x1352f8 | Địa chỉ FDE: 0x086568 | Kích thước: 148 bytes
//   0x1352f8: D10143FF  sub      sp, sp, #0x50
//   0x1352fc: F90013F6  str      x22, [sp, #0x20]
//   0x135300: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x135304: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1155_0x1352f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1352f8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x086568ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1156 | PC: 0x13538c | FDE: 0x086588 | Size: 64 bytes [_ZN4lynx6canvas15NapiMediaStreamD1Ev]
// Khung tháo gỡ #1156 | Địa chỉ PC: 0x13538c | Địa chỉ FDE: 0x086588 | Kích thước: 64 bytes
//   0x13538c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x135390: 90000308  adrp     x8, #0x195000
//   0x135394: F9413508  ldr      x8, [x8, #0x268]
//   0x135398: B9404001  ldr      w1, [x0, #0x40]
static inline uint64_t fde_func_1156_0x13538c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13538cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x90000308ULL) ^ 0x086588ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1157 | PC: 0x1353cc | FDE: 0x0865a0 | Size: 24 bytes [_ZN4lynx6canvas15NapiMediaStreamD0Ev]
// Khung tháo gỡ #1157 | Địa chỉ PC: 0x1353cc | Địa chỉ FDE: 0x0865a0 | Kích thước: 24 bytes
//   0x1353cc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1353d0: AA0003F3  mov      x19, x0
//   0x1353d4: 940151BB  bl       #0x189ac0
//   0x1353d8: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1157_0x1353cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1353ccULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0865a0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1158 | PC: 0x1353e4 | FDE: 0x0865b8 | Size: 184 bytes [_ZN4lynx6canvas15NapiMediaStream23PropagateDescendantTypeEPv]
// Khung tháo gỡ #1158 | Địa chỉ PC: 0x1353e4 | Địa chỉ FDE: 0x0865b8 | Kích thước: 184 bytes
//   0x1353e4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1353e8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1353ec: F90007E1  str      x1, [sp, #8]
//   0x1353f0: 9400000A  bl       #0x135418
static inline uint64_t fde_func_1158_0x1353e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1353e4ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0865b8ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1159 | PC: 0x13549c | FDE: 0x086608 | Size: 112 bytes [_ZN4lynx6canvas15NapiMediaStream4WrapENSt6__ndk110unique_ptrINS0_11MediaStreamENS2_14default_deleteIS4_EEEEN4Napi3EnvE]
// Khung tháo gỡ #1159 | Địa chỉ PC: 0x13549c | Địa chỉ FDE: 0x086608 | Kích thước: 112 bytes
//   0x13549c: D10183FF  sub      sp, sp, #0x60
//   0x1354a0: F9001BF6  str      x22, [sp, #0x30]
//   0x1354a4: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x1354a8: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1159_0x13549c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13549cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf6ULL) ^ 0x086608ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1160 | PC: 0x13550c | FDE: 0x086628 | Size: 156 bytes [_ZN4lynx6canvas15NapiMediaStream11ConstructorEN4Napi3EnvE]
// Khung tháo gỡ #1160 | Địa chỉ PC: 0x13550c | Địa chỉ FDE: 0x086628 | Kích thước: 156 bytes
//   0x13550c: D100C3FF  sub      sp, sp, #0x30
//   0x135510: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x135514: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x135518: 94010320  bl       #0x176198
static inline uint64_t fde_func_1160_0x13550c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13550cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x086628ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1161 | PC: 0x1355a8 | FDE: 0x086648 | Size: 256 bytes [_ZN4lynx6canvas15NapiMediaStream5ClassEN4Napi3EnvE]
// Khung tháo gỡ #1161 | Địa chỉ PC: 0x1355a8 | Địa chỉ FDE: 0x086648 | Kích thước: 256 bytes
//   0x1355a8: D10343FF  sub      sp, sp, #0xd0
//   0x1355ac: A90A5BF7  stp      x23, x22, [sp, #0xa0]
//   0x1355b0: A90B53F5  stp      x21, x20, [sp, #0xb0]
//   0x1355b4: A90C7BF3  stp      x19, x30, [sp, #0xc0]
static inline uint64_t fde_func_1161_0x1355a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1355a8ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa90a5bf7ULL) ^ 0x086648ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1162 | PC: 0x1356a8 | FDE: 0x086670 | Size: 256 bytes [_ZN4lynx6canvas15NapiMediaStream22SetBeautifyParamMethodERKN4Napi12CallbackInfoE]
// Khung tháo gỡ #1162 | Địa chỉ PC: 0x1356a8 | Địa chỉ FDE: 0x086670 | Kích thước: 256 bytes
//   0x1356a8: D10143FF  sub      sp, sp, #0x50
//   0x1356ac: 6D012BEB  stp      d11, d10, [sp, #0x10]
//   0x1356b0: 6D0223E9  stp      d9, d8, [sp, #0x20]
//   0x1356b4: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1162_0x1356a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1356a8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0x6d012bebULL) ^ 0x086670ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1163 | PC: 0x13582c | FDE: 0x0866b8 | Size: 256 bytes [_ZN4lynx6canvas15NapiMediaStream13DisposeMethodERKN4Napi12CallbackInfoE]
// Khung tháo gỡ #1163 | Địa chỉ PC: 0x13582c | Địa chỉ FDE: 0x0866b8 | Kích thước: 256 bytes
//   0x13582c: D100C3FF  sub      sp, sp, #0x30
//   0x135830: F9000BF4  str      x20, [sp, #0x10]
//   0x135834: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x135838: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1163_0x13582c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13582cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x0866b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1164 | PC: 0x135950 | FDE: 0x086730 | Size: 116 bytes [_ZN4lynx6canvas15NapiMediaStream10IsInstanceEPN4Napi15ScriptWrappableE]
// Khung tháo gỡ #1164 | Địa chỉ PC: 0x135950 | Địa chỉ FDE: 0x086730 | Kích thước: 116 bytes
//   0x135950: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x135954: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x135958: B4000320  cbz      x0, #0x1359bc
//   0x13595c: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_1164_0x135950(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135950ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x086730ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1165 | PC: 0x1359c4 | FDE: 0x086750 | Size: 256 bytes [_ZN4lynx6canvas15NapiMediaStream7InstallEN4Napi3EnvERNS2_6ObjectE]
// Khung tháo gỡ #1165 | Địa chỉ PC: 0x1359c4 | Địa chỉ FDE: 0x086750 | Kích thước: 256 bytes
//   0x1359c4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1359c8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1359cc: AA0103F3  mov      x19, x1
//   0x1359d0: 90FFF7E1  adrp     x1, #0x31000
static inline uint64_t fde_func_1165_0x1359c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1359c4ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x086750ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1166 | PC: 0x135bb4 | FDE: 0x0867b0 | Size: 256 bytes
// Khung tháo gỡ #1166 | Địa chỉ PC: 0x135bb4 | Địa chỉ FDE: 0x0867b0 | Kích thước: 256 bytes
//   0x135bb4: D100C3FF  sub      sp, sp, #0x30
//   0x135bb8: F9000BF4  str      x20, [sp, #0x10]
//   0x135bbc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x135bc0: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1166_0x135bb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135bb4ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x0867b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1167 | PC: 0x135d7c | FDE: 0x086838 | Size: 256 bytes
// Khung tháo gỡ #1167 | Địa chỉ PC: 0x135d7c | Địa chỉ FDE: 0x086838 | Kích thước: 256 bytes
//   0x135d7c: AA1E03E2  mov      x2, x30
//   0x135d80: 94013780  bl       #0x183b80
//   0x135d84: AA0203FE  mov      x30, x2
//   0x135d88: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1167_0x135d7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x135d7cULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94013780ULL) ^ 0x086838ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1168 | PC: 0x136034 | FDE: 0x0868f0 | Size: 256 bytes
// Khung tháo gỡ #1168 | Địa chỉ PC: 0x136034 | Địa chỉ FDE: 0x0868f0 | Kích thước: 256 bytes
//   0x136034: D102C3FF  sub      sp, sp, #0xb0
//   0x136038: FD002BEE  str      d14, [sp, #0x50]
//   0x13603c: 6D0633ED  stp      d13, d12, [sp, #0x60]
//   0x136040: 6D072BEB  stp      d11, d10, [sp, #0x70]
static inline uint64_t fde_func_1168_0x136034(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x136034ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xfd002beeULL) ^ 0x0868f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1169 | PC: 0x1362a8 | FDE: 0x086988 | Size: 256 bytes
// Khung tháo gỡ #1169 | Địa chỉ PC: 0x1362a8 | Địa chỉ FDE: 0x086988 | Kích thước: 256 bytes
//   0x1362a8: F9401C08  ldr      x8, [x0, #0x38]
//   0x1362ac: F9400420  ldr      x0, [x1, #8]
//   0x1362b0: FD402D00  ldr      d0, [x8, #0x58]
//   0x1362b4: 14014B6F  b        #0x189070
static inline uint64_t fde_func_1169_0x1362a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1362a8ULL ^ (static_cast<uint64_t>(0xf9401c08ULL) << 13);
    acc = (acc + a1 + 0xf9400420ULL) ^ 0x086988ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1170 | PC: 0x13640c | FDE: 0x086a08 | Size: 256 bytes
// Khung tháo gỡ #1170 | Địa chỉ PC: 0x13640c | Địa chỉ FDE: 0x086a08 | Kích thước: 256 bytes
//   0x13640c: D10143FF  sub      sp, sp, #0x50
//   0x136410: F9001BF4  str      x20, [sp, #0x30]
//   0x136414: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x136418: 94011A78  bl       #0x17cdf8
static inline uint64_t fde_func_1170_0x13640c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13640cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf4ULL) ^ 0x086a08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1171 | PC: 0x1365e4 | FDE: 0x086a90 | Size: 124 bytes
// Khung tháo gỡ #1171 | Địa chỉ PC: 0x1365e4 | Địa chỉ FDE: 0x086a90 | Kích thước: 124 bytes
//   0x1365e4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1365e8: 94011174  bl       #0x17abb8
//   0x1365ec: 97FF9236  bl       #0x11aec4
//   0x1365f0: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1171_0x1365e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1365e4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94011174ULL) ^ 0x086a90ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1172 | PC: 0x136660 | FDE: 0x086af8 | Size: 124 bytes
// Khung tháo gỡ #1172 | Địa chỉ PC: 0x136660 | Địa chỉ FDE: 0x086af8 | Kích thước: 124 bytes
//   0x136660: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x136664: 94011155  bl       #0x17abb8
//   0x136668: 97FF926C  bl       #0x11b018
//   0x13666c: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1172_0x136660(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x136660ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94011155ULL) ^ 0x086af8ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1173 | PC: 0x1366dc | FDE: 0x086b60 | Size: 128 bytes
// Khung tháo gỡ #1173 | Địa chỉ PC: 0x1366dc | Địa chỉ FDE: 0x086b60 | Kích thước: 128 bytes
//   0x1366dc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1366e0: 94011136  bl       #0x17abb8
//   0x1366e4: 97FF9281  bl       #0x11b0e8
//   0x1366e8: 9401108F  bl       #0x17a924
static inline uint64_t fde_func_1173_0x1366dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1366dcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94011136ULL) ^ 0x086b60ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1174 | PC: 0x13675c | FDE: 0x086bc8 | Size: 176 bytes
// Khung tháo gỡ #1174 | Địa chỉ PC: 0x13675c | Địa chỉ FDE: 0x086bc8 | Kích thước: 176 bytes
//   0x13675c: D10103FF  sub      sp, sp, #0x40
//   0x136760: F90013F4  str      x20, [sp, #0x20]
//   0x136764: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x136768: 940122E0  bl       #0x17f2e8
static inline uint64_t fde_func_1174_0x13675c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13675cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f4ULL) ^ 0x086bc8ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1175 | PC: 0x13680c | FDE: 0x086c38 | Size: 204 bytes
// Khung tháo gỡ #1175 | Địa chỉ PC: 0x13680c | Địa chỉ FDE: 0x086c38 | Kích thước: 204 bytes
//   0x13680c: D10103FF  sub      sp, sp, #0x40
//   0x136810: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x136814: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x136818: 940104B1  bl       #0x177adc
static inline uint64_t fde_func_1175_0x13680c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13680cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x086c38ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1176 | PC: 0x1368d8 | FDE: 0x086cb0 | Size: 256 bytes
// Khung tháo gỡ #1176 | Địa chỉ PC: 0x1368d8 | Địa chỉ FDE: 0x086cb0 | Kích thước: 256 bytes
//   0x1368d8: D100C3FF  sub      sp, sp, #0x30
//   0x1368dc: F9000BF4  str      x20, [sp, #0x10]
//   0x1368e0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1368e4: 940133A1  bl       #0x183768
static inline uint64_t fde_func_1176_0x1368d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1368d8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x086cb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1177 | PC: 0x136bd8 | FDE: 0x086d48 | Size: 256 bytes
// Khung tháo gỡ #1177 | Địa chỉ PC: 0x136bd8 | Địa chỉ FDE: 0x086d48 | Kích thước: 256 bytes
//   0x136bd8: AA1E03E2  mov      x2, x30
//   0x136bdc: 94012FA8  bl       #0x182a7c
//   0x136be0: AA0203FE  mov      x30, x2
//   0x136be4: A9157BFD  stp      x29, x30, [sp, #0x150]
static inline uint64_t fde_func_1177_0x136bd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x136bd8ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94012fa8ULL) ^ 0x086d48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1178 | PC: 0x1370c8 | FDE: 0x086dd8 | Size: 256 bytes
// Khung tháo gỡ #1178 | Địa chỉ PC: 0x1370c8 | Địa chỉ FDE: 0x086dd8 | Kích thước: 256 bytes
//   0x1370c8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1370cc: AA0003F3  mov      x19, x0
//   0x1370d0: 97FFFFE4  bl       #0x137060
//   0x1370d4: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1178_0x1370c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1370c8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x086dd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1179 | PC: 0x1371d4 | FDE: 0x086e48 | Size: 256 bytes
// Khung tháo gỡ #1179 | Địa chỉ PC: 0x1371d4 | Địa chỉ FDE: 0x086e48 | Kích thước: 256 bytes
//   0x1371d4: A9BC63FC  stp      x28, x24, [sp, #-0x40]!
//   0x1371d8: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x1371dc: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1371e0: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1179_0x1371d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1371d4ULL ^ (static_cast<uint64_t>(0xa9bc63fcULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x086e48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1180 | PC: 0x137a3c | FDE: 0x086eb8 | Size: 256 bytes
// Khung tháo gỡ #1180 | Địa chỉ PC: 0x137a3c | Địa chỉ FDE: 0x086eb8 | Kích thước: 256 bytes
//   0x137a3c: F00002C8  adrp     x8, #0x192000
//   0x137a40: 91254108  add      x8, x8, #0x950
//   0x137a44: F9000028  str      x8, [x1]
//   0x137a48: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_1180_0x137a3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x137a3cULL ^ (static_cast<uint64_t>(0xf00002c8ULL) << 13);
    acc = (acc + a1 + 0x91254108ULL) ^ 0x086eb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1181 | PC: 0x137c60 | FDE: 0x086f38 | Size: 256 bytes
// Khung tháo gỡ #1181 | Địa chỉ PC: 0x137c60 | Địa chỉ FDE: 0x086f38 | Kích thước: 256 bytes
//   0x137c60: D101C3FF  sub      sp, sp, #0x70
//   0x137c64: F90023F6  str      x22, [sp, #0x40]
//   0x137c68: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x137c6c: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_1181_0x137c60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x137c60ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f6ULL) ^ 0x086f38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1182 | PC: 0x1389ec | FDE: 0x086fe0 | Size: 256 bytes
// Khung tháo gỡ #1182 | Địa chỉ PC: 0x1389ec | Địa chỉ FDE: 0x086fe0 | Kích thước: 256 bytes
//   0x1389ec: AA1E03E2  mov      x2, x30
//   0x1389f0: 940113F3  bl       #0x17d9bc
//   0x1389f4: AA0203FE  mov      x30, x2
//   0x1389f8: A9117BFD  stp      x29, x30, [sp, #0x110]
static inline uint64_t fde_func_1182_0x1389ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1389ecULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x940113f3ULL) ^ 0x086fe0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1183 | PC: 0x138fa8 | FDE: 0x087088 | Size: 256 bytes
// Khung tháo gỡ #1183 | Địa chỉ PC: 0x138fa8 | Địa chỉ FDE: 0x087088 | Kích thước: 256 bytes
//   0x138fa8: D10203FF  sub      sp, sp, #0x80
//   0x138fac: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x138fb0: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x138fb4: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1183_0x138fa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x138fa8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9055bf7ULL) ^ 0x087088ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1184 | PC: 0x139434 | FDE: 0x087128 | Size: 256 bytes
// Khung tháo gỡ #1184 | Địa chỉ PC: 0x139434 | Địa chỉ FDE: 0x087128 | Kích thước: 256 bytes
//   0x139434: AA1E03E2  mov      x2, x30
//   0x139438: 940106DE  bl       #0x17afb0
//   0x13943c: AA0203FE  mov      x30, x2
//   0x139440: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_1184_0x139434(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x139434ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x940106deULL) ^ 0x087128ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1185 | PC: 0x1398b4 | FDE: 0x0871c8 | Size: 256 bytes
// Khung tháo gỡ #1185 | Địa chỉ PC: 0x1398b4 | Địa chỉ FDE: 0x0871c8 | Kích thước: 256 bytes
//   0x1398b4: AA1E03E2  mov      x2, x30
//   0x1398b8: 940105BE  bl       #0x17afb0
//   0x1398bc: AA0203FE  mov      x30, x2
//   0x1398c0: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_1185_0x1398b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1398b4ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x940105beULL) ^ 0x0871c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1186 | PC: 0x139c28 | FDE: 0x087258 | Size: 256 bytes
// Khung tháo gỡ #1186 | Địa chỉ PC: 0x139c28 | Địa chỉ FDE: 0x087258 | Kích thước: 256 bytes
//   0x139c28: D10383FF  sub      sp, sp, #0xe0
//   0x139c2c: F90053F8  str      x24, [sp, #0xa0]
//   0x139c30: A90B5BF7  stp      x23, x22, [sp, #0xb0]
//   0x139c34: A90C53F5  stp      x21, x20, [sp, #0xc0]
static inline uint64_t fde_func_1186_0x139c28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x139c28ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xf90053f8ULL) ^ 0x087258ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1187 | PC: 0x139fd4 | FDE: 0x0872f8 | Size: 256 bytes
// Khung tháo gỡ #1187 | Địa chỉ PC: 0x139fd4 | Địa chỉ FDE: 0x0872f8 | Kích thước: 256 bytes
//   0x139fd4: D10183FF  sub      sp, sp, #0x60
//   0x139fd8: F9001BF6  str      x22, [sp, #0x30]
//   0x139fdc: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x139fe0: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1187_0x139fd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x139fd4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf6ULL) ^ 0x0872f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1188 | PC: 0x13a484 | FDE: 0x087390 | Size: 256 bytes
// Khung tháo gỡ #1188 | Địa chỉ PC: 0x13a484 | Địa chỉ FDE: 0x087390 | Kích thước: 256 bytes
//   0x13a484: D10183FF  sub      sp, sp, #0x60
//   0x13a488: F9001BF6  str      x22, [sp, #0x30]
//   0x13a48c: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x13a490: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1188_0x13a484(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13a484ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf6ULL) ^ 0x087390ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1189 | PC: 0x13a810 | FDE: 0x087418 | Size: 256 bytes
// Khung tháo gỡ #1189 | Địa chỉ PC: 0x13a810 | Địa chỉ FDE: 0x087418 | Kích thước: 256 bytes
//   0x13a810: D10143FF  sub      sp, sp, #0x50
//   0x13a814: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x13a818: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x13a81c: 9401065F  bl       #0x17c198
static inline uint64_t fde_func_1189_0x13a810(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13a810ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90353f5ULL) ^ 0x087418ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1190 | PC: 0x13b00c | FDE: 0x0874c8 | Size: 256 bytes
// Khung tháo gỡ #1190 | Địa chỉ PC: 0x13b00c | Địa chỉ FDE: 0x0874c8 | Kích thước: 256 bytes
//   0x13b00c: AA1E03E2  mov      x2, x30
//   0x13b010: 9400F210  bl       #0x177850
//   0x13b014: AA0203FE  mov      x30, x2
//   0x13b018: A9197BFD  stp      x29, x30, [sp, #0x190]
static inline uint64_t fde_func_1190_0x13b00c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13b00cULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9400f210ULL) ^ 0x0874c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1191 | PC: 0x13bde4 | FDE: 0x087568 | Size: 256 bytes
// Khung tháo gỡ #1191 | Địa chỉ PC: 0x13bde4 | Địa chỉ FDE: 0x087568 | Kích thước: 256 bytes
//   0x13bde4: D100C3FF  sub      sp, sp, #0x30
//   0x13bde8: F9000BF4  str      x20, [sp, #0x10]
//   0x13bdec: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x13bdf0: 9400E939  bl       #0x1762d4
static inline uint64_t fde_func_1191_0x13bde4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13bde4ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x087568ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1192 | PC: 0x13bf84 | FDE: 0x0875e8 | Size: 256 bytes
// Khung tháo gỡ #1192 | Địa chỉ PC: 0x13bf84 | Địa chỉ FDE: 0x0875e8 | Kích thước: 256 bytes
//   0x13bf84: D100C3FF  sub      sp, sp, #0x30
//   0x13bf88: F9000BF4  str      x20, [sp, #0x10]
//   0x13bf8c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x13bf90: 9400E8D1  bl       #0x1762d4
static inline uint64_t fde_func_1192_0x13bf84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13bf84ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x0875e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1193 | PC: 0x13c124 | FDE: 0x087668 | Size: 256 bytes
// Khung tháo gỡ #1193 | Địa chỉ PC: 0x13c124 | Địa chỉ FDE: 0x087668 | Kích thước: 256 bytes
//   0x13c124: D100C3FF  sub      sp, sp, #0x30
//   0x13c128: F9000BF4  str      x20, [sp, #0x10]
//   0x13c12c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x13c130: 9400F416  bl       #0x179188
static inline uint64_t fde_func_1193_0x13c124(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13c124ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x087668ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1194 | PC: 0x13c29c | FDE: 0x0876e0 | Size: 256 bytes
// Khung tháo gỡ #1194 | Địa chỉ PC: 0x13c29c | Địa chỉ FDE: 0x0876e0 | Kích thước: 256 bytes
//   0x13c29c: AA1E03E2  mov      x2, x30
//   0x13c2a0: 9400FB44  bl       #0x17afb0
//   0x13c2a4: AA0203FE  mov      x30, x2
//   0x13c2a8: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_1194_0x13c29c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13c29cULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9400fb44ULL) ^ 0x0876e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1195 | PC: 0x13c55c | FDE: 0x087768 | Size: 256 bytes
// Khung tháo gỡ #1195 | Địa chỉ PC: 0x13c55c | Địa chỉ FDE: 0x087768 | Kích thước: 256 bytes
//   0x13c55c: AA1E03E2  mov      x2, x30
//   0x13c560: 9400FA94  bl       #0x17afb0
//   0x13c564: AA0203FE  mov      x30, x2
//   0x13c568: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_1195_0x13c55c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13c55cULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9400fa94ULL) ^ 0x087768ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1196 | PC: 0x13c954 | FDE: 0x087808 | Size: 256 bytes
// Khung tháo gỡ #1196 | Địa chỉ PC: 0x13c954 | Địa chỉ FDE: 0x087808 | Kích thước: 256 bytes
//   0x13c954: D10203FF  sub      sp, sp, #0x80
//   0x13c958: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x13c95c: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x13c960: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1196_0x13c954(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13c954ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9055bf7ULL) ^ 0x087808ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1197 | PC: 0x13cd4c | FDE: 0x0878a8 | Size: 256 bytes
// Khung tháo gỡ #1197 | Địa chỉ PC: 0x13cd4c | Địa chỉ FDE: 0x0878a8 | Kích thước: 256 bytes
//   0x13cd4c: D10203FF  sub      sp, sp, #0x80
//   0x13cd50: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x13cd54: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x13cd58: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1197_0x13cd4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13cd4cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9055bf7ULL) ^ 0x0878a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1198 | PC: 0x13d03c | FDE: 0x087938 | Size: 256 bytes
// Khung tháo gỡ #1198 | Địa chỉ PC: 0x13d03c | Địa chỉ FDE: 0x087938 | Kích thước: 256 bytes
//   0x13d03c: D10603FF  sub      sp, sp, #0x180
//   0x13d040: A9126FFC  stp      x28, x27, [sp, #0x120]
//   0x13d044: A91367FA  stp      x26, x25, [sp, #0x130]
//   0x13d048: A9145FF8  stp      x24, x23, [sp, #0x140]
static inline uint64_t fde_func_1198_0x13d03c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d03cULL ^ (static_cast<uint64_t>(0xd10603ffULL) << 13);
    acc = (acc + a1 + 0xa9126ffcULL) ^ 0x087938ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1199 | PC: 0x13d45c | FDE: 0x0879d0 | Size: 256 bytes
// Khung tháo gỡ #1199 | Địa chỉ PC: 0x13d45c | Địa chỉ FDE: 0x0879d0 | Kích thước: 256 bytes
//   0x13d45c: D10103FF  sub      sp, sp, #0x40
//   0x13d460: F90013F4  str      x20, [sp, #0x20]
//   0x13d464: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x13d468: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1199_0x13d45c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d45cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f4ULL) ^ 0x0879d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Shard 3 Dispatcher / Bộ điều phối phân mảnh 3
uint64_t execute_fde_shard_3(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 800: return fde_func_0800_0x100994(a0, a1);
        case 801: return fde_func_0801_0x100c58(a0, a1);
        case 802: return fde_func_0802_0x101080(a0, a1);
        case 803: return fde_func_0803_0x1015d0(a0, a1);
        case 804: return fde_func_0804_0x101848(a0, a1);
        case 805: return fde_func_0805_0x1019b0(a0, a1);
        case 806: return fde_func_0806_0x101b34(a0, a1);
        case 807: return fde_func_0807_0x101d30(a0, a1);
        case 808: return fde_func_0808_0x101efc(a0, a1);
        case 809: return fde_func_0809_0x102068(a0, a1);
        case 810: return fde_func_0810_0x1025d8(a0, a1);
        case 811: return fde_func_0811_0x1027fc(a0, a1);
        case 812: return fde_func_0812_0x102b14(a0, a1);
        case 813: return fde_func_0813_0x102d54(a0, a1);
        case 814: return fde_func_0814_0x102f5c(a0, a1);
        case 815: return fde_func_0815_0x1031a0(a0, a1);
        case 816: return fde_func_0816_0x10337c(a0, a1);
        case 817: return fde_func_0817_0x1037b4(a0, a1);
        case 818: return fde_func_0818_0x1038bc(a0, a1);
        case 819: return fde_func_0819_0x1039fc(a0, a1);
        case 820: return fde_func_0820_0x103c68(a0, a1);
        case 821: return fde_func_0821_0x10423c(a0, a1);
        case 822: return fde_func_0822_0x104424(a0, a1);
        case 823: return fde_func_0823_0x10465c(a0, a1);
        case 824: return fde_func_0824_0x104754(a0, a1);
        case 825: return fde_func_0825_0x104aac(a0, a1);
        case 826: return fde_func_0826_0x104bd4(a0, a1);
        case 827: return fde_func_0827_0x104cbc(a0, a1);
        case 828: return fde_func_0828_0x104e14(a0, a1);
        case 829: return fde_func_0829_0x104fb0(a0, a1);
        case 830: return fde_func_0830_0x105294(a0, a1);
        case 831: return fde_func_0831_0x1053f4(a0, a1);
        case 832: return fde_func_0832_0x10580c(a0, a1);
        case 833: return fde_func_0833_0x105bac(a0, a1);
        case 834: return fde_func_0834_0x105cd4(a0, a1);
        case 835: return fde_func_0835_0x106a10(a0, a1);
        case 836: return fde_func_0836_0x106a94(a0, a1);
        case 837: return fde_func_0837_0x106c7c(a0, a1);
        case 838: return fde_func_0838_0x1070f0(a0, a1);
        case 839: return fde_func_0839_0x1072cc(a0, a1);
        case 840: return fde_func_0840_0x1075e8(a0, a1);
        case 841: return fde_func_0841_0x107b00(a0, a1);
        case 842: return fde_func_0842_0x108114(a0, a1);
        case 843: return fde_func_0843_0x108838(a0, a1);
        case 844: return fde_func_0844_0x108e14(a0, a1);
        case 845: return fde_func_0845_0x109564(a0, a1);
        case 846: return fde_func_0846_0x1095f4(a0, a1);
        case 847: return fde_func_0847_0x109ab0(a0, a1);
        case 848: return fde_func_0848_0x109bf8(a0, a1);
        case 849: return fde_func_0849_0x109d08(a0, a1);
        case 850: return fde_func_0850_0x109e18(a0, a1);
        case 851: return fde_func_0851_0x109f28(a0, a1);
        case 852: return fde_func_0852_0x10a038(a0, a1);
        case 853: return fde_func_0853_0x10a148(a0, a1);
        case 854: return fde_func_0854_0x10a2b4(a0, a1);
        case 855: return fde_func_0855_0x10a4b4(a0, a1);
        case 856: return fde_func_0856_0x10a6f0(a0, a1);
        case 857: return fde_func_0857_0x10a884(a0, a1);
        case 858: return fde_func_0858_0x10aa10(a0, a1);
        case 859: return fde_func_0859_0x10abb4(a0, a1);
        case 860: return fde_func_0860_0x10ad54(a0, a1);
        case 861: return fde_func_0861_0x10ae88(a0, a1);
        case 862: return fde_func_0862_0x10af98(a0, a1);
        case 863: return fde_func_0863_0x10b0a8(a0, a1);
        case 864: return fde_func_0864_0x10b1b8(a0, a1);
        case 865: return fde_func_0865_0x10b2c8(a0, a1);
        case 866: return fde_func_0866_0x10b438(a0, a1);
        case 867: return fde_func_0867_0x10b608(a0, a1);
        case 868: return fde_func_0868_0x10b75c(a0, a1);
        case 869: return fde_func_0869_0x10b944(a0, a1);
        case 870: return fde_func_0870_0x10bb28(a0, a1);
        case 871: return fde_func_0871_0x10bc8c(a0, a1);
        case 872: return fde_func_0872_0x10bd94(a0, a1);
        case 873: return fde_func_0873_0x10c100(a0, a1);
        case 874: return fde_func_0874_0x10c1ec(a0, a1);
        case 875: return fde_func_0875_0x10c440(a0, a1);
        case 876: return fde_func_0876_0x10c578(a0, a1);
        case 877: return fde_func_0877_0x10c778(a0, a1);
        case 878: return fde_func_0878_0x10c908(a0, a1);
        case 879: return fde_func_0879_0x10cb90(a0, a1);
        case 880: return fde_func_0880_0x10ccfc(a0, a1);
        case 881: return fde_func_0881_0x10cebc(a0, a1);
        case 882: return fde_func_0882_0x10d06c(a0, a1);
        case 883: return fde_func_0883_0x10d198(a0, a1);
        case 884: return fde_func_0884_0x10d3a4(a0, a1);
        case 885: return fde_func_0885_0x10d45c(a0, a1);
        case 886: return fde_func_0886_0x10d53c(a0, a1);
        case 887: return fde_func_0887_0x10d790(a0, a1);
        case 888: return fde_func_0888_0x10d948(a0, a1);
        case 889: return fde_func_0889_0x10dbe4(a0, a1);
        case 890: return fde_func_0890_0x10de14(a0, a1);
        case 891: return fde_func_0891_0x10df60(a0, a1);
        case 892: return fde_func_0892_0x10e088(a0, a1);
        case 893: return fde_func_0893_0x10e1b8(a0, a1);
        case 894: return fde_func_0894_0x10e3e4(a0, a1);
        case 895: return fde_func_0895_0x10e898(a0, a1);
        case 896: return fde_func_0896_0x10eb5c(a0, a1);
        case 897: return fde_func_0897_0x10eef4(a0, a1);
        case 898: return fde_func_0898_0x10f58c(a0, a1);
        case 899: return fde_func_0899_0x10f684(a0, a1);
        case 900: return fde_func_0900_0x10f700(a0, a1);
        case 901: return fde_func_0901_0x10f7a8(a0, a1);
        case 902: return fde_func_0902_0x10fa44(a0, a1);
        case 903: return fde_func_0903_0x10fcc0(a0, a1);
        case 904: return fde_func_0904_0x1100c4(a0, a1);
        case 905: return fde_func_0905_0x11038c(a0, a1);
        case 906: return fde_func_0906_0x11045c(a0, a1);
        case 907: return fde_func_0907_0x11056c(a0, a1);
        case 908: return fde_func_0908_0x110810(a0, a1);
        case 909: return fde_func_0909_0x110894(a0, a1);
        case 910: return fde_func_0910_0x110908(a0, a1);
        case 911: return fde_func_0911_0x11097c(a0, a1);
        case 912: return fde_func_0912_0x110b54(a0, a1);
        case 913: return fde_func_0913_0x110bac(a0, a1);
        case 914: return fde_func_0914_0x110d8c(a0, a1);
        case 915: return fde_func_0915_0x111030(a0, a1);
        case 916: return fde_func_0916_0x1110a0(a0, a1);
        case 917: return fde_func_0917_0x11120c(a0, a1);
        case 918: return fde_func_0918_0x11125c(a0, a1);
        case 919: return fde_func_0919_0x111954(a0, a1);
        case 920: return fde_func_0920_0x111dc8(a0, a1);
        case 921: return fde_func_0921_0x1120b0(a0, a1);
        case 922: return fde_func_0922_0x11226c(a0, a1);
        case 923: return fde_func_0923_0x112294(a0, a1);
        case 924: return fde_func_0924_0x1125b8(a0, a1);
        case 925: return fde_func_0925_0x1127d4(a0, a1);
        case 926: return fde_func_0926_0x1129d8(a0, a1);
        case 927: return fde_func_0927_0x112e94(a0, a1);
        case 928: return fde_func_0928_0x113734(a0, a1);
        case 929: return fde_func_0929_0x115830(a0, a1);
        case 930: return fde_func_0930_0x115a58(a0, a1);
        case 931: return fde_func_0931_0x116598(a0, a1);
        case 932: return fde_func_0932_0x116e04(a0, a1);
        case 933: return fde_func_0933_0x116fb0(a0, a1);
        case 934: return fde_func_0934_0x117114(a0, a1);
        case 935: return fde_func_0935_0x11849c(a0, a1);
        case 936: return fde_func_0936_0x1185e4(a0, a1);
        case 937: return fde_func_0937_0x1186d0(a0, a1);
        case 938: return fde_func_0938_0x1187d4(a0, a1);
        case 939: return fde_func_0939_0x11891c(a0, a1);
        case 940: return fde_func_0940_0x119000(a0, a1);
        case 941: return fde_func_0941_0x1195ec(a0, a1);
        case 942: return fde_func_0942_0x119608(a0, a1);
        case 943: return fde_func_0943_0x119704(a0, a1);
        case 944: return fde_func_0944_0x1197c0(a0, a1);
        case 945: return fde_func_0945_0x119860(a0, a1);
        case 946: return fde_func_0946_0x11991c(a0, a1);
        case 947: return fde_func_0947_0x119a18(a0, a1);
        case 948: return fde_func_0948_0x119a70(a0, a1);
        case 949: return fde_func_0949_0x119a8c(a0, a1);
        case 950: return fde_func_0950_0x119aa4(a0, a1);
        case 951: return fde_func_0951_0x119b04(a0, a1);
        case 952: return fde_func_0952_0x119b4c(a0, a1);
        case 953: return fde_func_0953_0x119ba8(a0, a1);
        case 954: return fde_func_0954_0x119be8(a0, a1);
        case 955: return fde_func_0955_0x119c28(a0, a1);
        case 956: return fde_func_0956_0x119d84(a0, a1);
        case 957: return fde_func_0957_0x119d9c(a0, a1);
        case 958: return fde_func_0958_0x119db8(a0, a1);
        case 959: return fde_func_0959_0x119fcc(a0, a1);
        case 960: return fde_func_0960_0x119fec(a0, a1);
        case 961: return fde_func_0961_0x11a00c(a0, a1);
        case 962: return fde_func_0962_0x11a134(a0, a1);
        case 963: return fde_func_0963_0x11a174(a0, a1);
        case 964: return fde_func_0964_0x11a75c(a0, a1);
        case 965: return fde_func_0965_0x11a7dc(a0, a1);
        case 966: return fde_func_0966_0x11acc4(a0, a1);
        case 967: return fde_func_0967_0x11ad14(a0, a1);
        case 968: return fde_func_0968_0x11af8c(a0, a1);
        case 969: return fde_func_0969_0x11b044(a0, a1);
        case 970: return fde_func_0970_0x11b114(a0, a1);
        case 971: return fde_func_0971_0x11b25c(a0, a1);
        case 972: return fde_func_0972_0x11b600(a0, a1);
        case 973: return fde_func_0973_0x11b758(a0, a1);
        case 974: return fde_func_0974_0x11b85c(a0, a1);
        case 975: return fde_func_0975_0x11bd14(a0, a1);
        case 976: return fde_func_0976_0x11bdf8(a0, a1);
        case 977: return fde_func_0977_0x11bed0(a0, a1);
        case 978: return fde_func_0978_0x11c1e8(a0, a1);
        case 979: return fde_func_0979_0x11c2c8(a0, a1);
        case 980: return fde_func_0980_0x11c2d0(a0, a1);
        case 981: return fde_func_0981_0x11c3b8(a0, a1);
        case 982: return fde_func_0982_0x11c678(a0, a1);
        case 983: return fde_func_0983_0x11c700(a0, a1);
        case 984: return fde_func_0984_0x11cd28(a0, a1);
        case 985: return fde_func_0985_0x11cf34(a0, a1);
        case 986: return fde_func_0986_0x11cf94(a0, a1);
        case 987: return fde_func_0987_0x11d4f0(a0, a1);
        case 988: return fde_func_0988_0x11dac4(a0, a1);
        case 989: return fde_func_0989_0x11dcfc(a0, a1);
        case 990: return fde_func_0990_0x11e024(a0, a1);
        case 991: return fde_func_0991_0x11e37c(a0, a1);
        case 992: return fde_func_0992_0x11e40c(a0, a1);
        case 993: return fde_func_0993_0x11e50c(a0, a1);
        case 994: return fde_func_0994_0x11e708(a0, a1);
        case 995: return fde_func_0995_0x11e780(a0, a1);
        case 996: return fde_func_0996_0x11e9a4(a0, a1);
        case 997: return fde_func_0997_0x11eb3c(a0, a1);
        case 998: return fde_func_0998_0x11ebac(a0, a1);
        case 999: return fde_func_0999_0x11eea4(a0, a1);
        case 1000: return fde_func_1000_0x11f270(a0, a1);
        case 1001: return fde_func_1001_0x11f5a4(a0, a1);
        case 1002: return fde_func_1002_0x11f698(a0, a1);
        case 1003: return fde_func_1003_0x11f720(a0, a1);
        case 1004: return fde_func_1004_0x11fb78(a0, a1);
        case 1005: return fde_func_1005_0x11fbd8(a0, a1);
        case 1006: return fde_func_1006_0x11fc28(a0, a1);
        case 1007: return fde_func_1007_0x11fedc(a0, a1);
        case 1008: return fde_func_1008_0x12008c(a0, a1);
        case 1009: return fde_func_1009_0x12011c(a0, a1);
        case 1010: return fde_func_1010_0x120194(a0, a1);
        case 1011: return fde_func_1011_0x1202a0(a0, a1);
        case 1012: return fde_func_1012_0x120374(a0, a1);
        case 1013: return fde_func_1013_0x12057c(a0, a1);
        case 1014: return fde_func_1014_0x120678(a0, a1);
        case 1015: return fde_func_1015_0x120a88(a0, a1);
        case 1016: return fde_func_1016_0x120d68(a0, a1);
        case 1017: return fde_func_1017_0x120ef4(a0, a1);
        case 1018: return fde_func_1018_0x12114c(a0, a1);
        case 1019: return fde_func_1019_0x12115c(a0, a1);
        case 1020: return fde_func_1020_0x12117c(a0, a1);
        case 1021: return fde_func_1021_0x121198(a0, a1);
        case 1022: return fde_func_1022_0x12130c(a0, a1);
        case 1023: return fde_func_1023_0x121340(a0, a1);
        case 1024: return fde_func_1024_0x1215d0(a0, a1);
        case 1025: return fde_func_1025_0x121788(a0, a1);
        case 1026: return fde_func_1026_0x1217e4(a0, a1);
        case 1027: return fde_func_1027_0x1219d8(a0, a1);
        case 1028: return fde_func_1028_0x121d9c(a0, a1);
        case 1029: return fde_func_1029_0x12209c(a0, a1);
        case 1030: return fde_func_1030_0x122658(a0, a1);
        case 1031: return fde_func_1031_0x122870(a0, a1);
        case 1032: return fde_func_1032_0x1228d4(a0, a1);
        case 1033: return fde_func_1033_0x1228d8(a0, a1);
        case 1034: return fde_func_1034_0x122914(a0, a1);
        case 1035: return fde_func_1035_0x12291c(a0, a1);
        case 1036: return fde_func_1036_0x122b40(a0, a1);
        case 1037: return fde_func_1037_0x122b70(a0, a1);
        case 1038: return fde_func_1038_0x122f08(a0, a1);
        case 1039: return fde_func_1039_0x122f18(a0, a1);
        case 1040: return fde_func_1040_0x122f90(a0, a1);
        case 1041: return fde_func_1041_0x12305c(a0, a1);
        case 1042: return fde_func_1042_0x123074(a0, a1);
        case 1043: return fde_func_1043_0x123118(a0, a1);
        case 1044: return fde_func_1044_0x123348(a0, a1);
        case 1045: return fde_func_1045_0x12358c(a0, a1);
        case 1046: return fde_func_1046_0x1235a4(a0, a1);
        case 1047: return fde_func_1047_0x1235ac(a0, a1);
        case 1048: return fde_func_1048_0x1235cc(a0, a1);
        case 1049: return fde_func_1049_0x1235dc(a0, a1);
        case 1050: return fde_func_1050_0x1235f8(a0, a1);
        case 1051: return fde_func_1051_0x123614(a0, a1);
        case 1052: return fde_func_1052_0x1236b8(a0, a1);
        case 1053: return fde_func_1053_0x12390c(a0, a1);
        case 1054: return fde_func_1054_0x123c80(a0, a1);
        case 1055: return fde_func_1055_0x123d38(a0, a1);
        case 1056: return fde_func_1056_0x123d98(a0, a1);
        case 1057: return fde_func_1057_0x123dcc(a0, a1);
        case 1058: return fde_func_1058_0x123dfc(a0, a1);
        case 1059: return fde_func_1059_0x123e30(a0, a1);
        case 1060: return fde_func_1060_0x1243cc(a0, a1);
        case 1061: return fde_func_1061_0x1246cc(a0, a1);
        case 1062: return fde_func_1062_0x1247d0(a0, a1);
        case 1063: return fde_func_1063_0x1248b4(a0, a1);
        case 1064: return fde_func_1064_0x124ab4(a0, a1);
        case 1065: return fde_func_1065_0x124bf0(a0, a1);
        case 1066: return fde_func_1066_0x124e80(a0, a1);
        case 1067: return fde_func_1067_0x125340(a0, a1);
        case 1068: return fde_func_1068_0x126a64(a0, a1);
        case 1069: return fde_func_1069_0x127150(a0, a1);
        case 1070: return fde_func_1070_0x127a50(a0, a1);
        case 1071: return fde_func_1071_0x127e4c(a0, a1);
        case 1072: return fde_func_1072_0x127fbc(a0, a1);
        case 1073: return fde_func_1073_0x128100(a0, a1);
        case 1074: return fde_func_1074_0x12817c(a0, a1);
        case 1075: return fde_func_1075_0x1281f4(a0, a1);
        case 1076: return fde_func_1076_0x12837c(a0, a1);
        case 1077: return fde_func_1077_0x128514(a0, a1);
        case 1078: return fde_func_1078_0x128684(a0, a1);
        case 1079: return fde_func_1079_0x1287e4(a0, a1);
        case 1080: return fde_func_1080_0x12895c(a0, a1);
        case 1081: return fde_func_1081_0x1289ec(a0, a1);
        case 1082: return fde_func_1082_0x128c30(a0, a1);
        case 1083: return fde_func_1083_0x128d04(a0, a1);
        case 1084: return fde_func_1084_0x128d7c(a0, a1);
        case 1085: return fde_func_1085_0x1290fc(a0, a1);
        case 1086: return fde_func_1086_0x129160(a0, a1);
        case 1087: return fde_func_1087_0x12920c(a0, a1);
        case 1088: return fde_func_1088_0x129254(a0, a1);
        case 1089: return fde_func_1089_0x12933c(a0, a1);
        case 1090: return fde_func_1090_0x129448(a0, a1);
        case 1091: return fde_func_1091_0x1295ec(a0, a1);
        case 1092: return fde_func_1092_0x1298b8(a0, a1);
        case 1093: return fde_func_1093_0x129974(a0, a1);
        case 1094: return fde_func_1094_0x1299b4(a0, a1);
        case 1095: return fde_func_1095_0x129b08(a0, a1);
        case 1096: return fde_func_1096_0x129b50(a0, a1);
        case 1097: return fde_func_1097_0x129d58(a0, a1);
        case 1098: return fde_func_1098_0x129f64(a0, a1);
        case 1099: return fde_func_1099_0x12a160(a0, a1);
        case 1100: return fde_func_1100_0x12a468(a0, a1);
        case 1101: return fde_func_1101_0x12a954(a0, a1);
        case 1102: return fde_func_1102_0x12d038(a0, a1);
        case 1103: return fde_func_1103_0x12d168(a0, a1);
        case 1104: return fde_func_1104_0x12d620(a0, a1);
        case 1105: return fde_func_1105_0x12d804(a0, a1);
        case 1106: return fde_func_1106_0x12daa4(a0, a1);
        case 1107: return fde_func_1107_0x12db78(a0, a1);
        case 1108: return fde_func_1108_0x12dc24(a0, a1);
        case 1109: return fde_func_1109_0x12e170(a0, a1);
        case 1110: return fde_func_1110_0x12e5b4(a0, a1);
        case 1111: return fde_func_1111_0x12e748(a0, a1);
        case 1112: return fde_func_1112_0x12eab0(a0, a1);
        case 1113: return fde_func_1113_0x12ed78(a0, a1);
        case 1114: return fde_func_1114_0x12f8fc(a0, a1);
        case 1115: return fde_func_1115_0x12f9d8(a0, a1);
        case 1116: return fde_func_1116_0x12fad0(a0, a1);
        case 1117: return fde_func_1117_0x12fd40(a0, a1);
        case 1118: return fde_func_1118_0x12fe64(a0, a1);
        case 1119: return fde_func_1119_0x12fef8(a0, a1);
        case 1120: return fde_func_1120_0x12ffbc(a0, a1);
        case 1121: return fde_func_1121_0x1300b0(a0, a1);
        case 1122: return fde_func_1122_0x130144(a0, a1);
        case 1123: return fde_func_1123_0x130264(a0, a1);
        case 1124: return fde_func_1124_0x130384(a0, a1);
        case 1125: return fde_func_1125_0x13049c(a0, a1);
        case 1126: return fde_func_1126_0x1306f8(a0, a1);
        case 1127: return fde_func_1127_0x130adc(a0, a1);
        case 1128: return fde_func_1128_0x130e34(a0, a1);
        case 1129: return fde_func_1129_0x13103c(a0, a1);
        case 1130: return fde_func_1130_0x1313d8(a0, a1);
        case 1131: return fde_func_1131_0x131e10(a0, a1);
        case 1132: return fde_func_1132_0x1322e8(a0, a1);
        case 1133: return fde_func_1133_0x1324d8(a0, a1);
        case 1134: return fde_func_1134_0x1327e4(a0, a1);
        case 1135: return fde_func_1135_0x132958(a0, a1);
        case 1136: return fde_func_1136_0x132d94(a0, a1);
        case 1137: return fde_func_1137_0x1331dc(a0, a1);
        case 1138: return fde_func_1138_0x133424(a0, a1);
        case 1139: return fde_func_1139_0x133474(a0, a1);
        case 1140: return fde_func_1140_0x1334a4(a0, a1);
        case 1141: return fde_func_1141_0x133710(a0, a1);
        case 1142: return fde_func_1142_0x1339c8(a0, a1);
        case 1143: return fde_func_1143_0x133a48(a0, a1);
        case 1144: return fde_func_1144_0x133b10(a0, a1);
        case 1145: return fde_func_1145_0x133d60(a0, a1);
        case 1146: return fde_func_1146_0x13424c(a0, a1);
        case 1147: return fde_func_1147_0x13453c(a0, a1);
        case 1148: return fde_func_1148_0x134664(a0, a1);
        case 1149: return fde_func_1149_0x1348e4(a0, a1);
        case 1150: return fde_func_1150_0x134c80(a0, a1);
        case 1151: return fde_func_1151_0x134cf8(a0, a1);
        case 1152: return fde_func_1152_0x134de8(a0, a1);
        case 1153: return fde_func_1153_0x1350e4(a0, a1);
        case 1154: return fde_func_1154_0x1352d4(a0, a1);
        case 1155: return fde_func_1155_0x1352f8(a0, a1);
        case 1156: return fde_func_1156_0x13538c(a0, a1);
        case 1157: return fde_func_1157_0x1353cc(a0, a1);
        case 1158: return fde_func_1158_0x1353e4(a0, a1);
        case 1159: return fde_func_1159_0x13549c(a0, a1);
        case 1160: return fde_func_1160_0x13550c(a0, a1);
        case 1161: return fde_func_1161_0x1355a8(a0, a1);
        case 1162: return fde_func_1162_0x1356a8(a0, a1);
        case 1163: return fde_func_1163_0x13582c(a0, a1);
        case 1164: return fde_func_1164_0x135950(a0, a1);
        case 1165: return fde_func_1165_0x1359c4(a0, a1);
        case 1166: return fde_func_1166_0x135bb4(a0, a1);
        case 1167: return fde_func_1167_0x135d7c(a0, a1);
        case 1168: return fde_func_1168_0x136034(a0, a1);
        case 1169: return fde_func_1169_0x1362a8(a0, a1);
        case 1170: return fde_func_1170_0x13640c(a0, a1);
        case 1171: return fde_func_1171_0x1365e4(a0, a1);
        case 1172: return fde_func_1172_0x136660(a0, a1);
        case 1173: return fde_func_1173_0x1366dc(a0, a1);
        case 1174: return fde_func_1174_0x13675c(a0, a1);
        case 1175: return fde_func_1175_0x13680c(a0, a1);
        case 1176: return fde_func_1176_0x1368d8(a0, a1);
        case 1177: return fde_func_1177_0x136bd8(a0, a1);
        case 1178: return fde_func_1178_0x1370c8(a0, a1);
        case 1179: return fde_func_1179_0x1371d4(a0, a1);
        case 1180: return fde_func_1180_0x137a3c(a0, a1);
        case 1181: return fde_func_1181_0x137c60(a0, a1);
        case 1182: return fde_func_1182_0x1389ec(a0, a1);
        case 1183: return fde_func_1183_0x138fa8(a0, a1);
        case 1184: return fde_func_1184_0x139434(a0, a1);
        case 1185: return fde_func_1185_0x1398b4(a0, a1);
        case 1186: return fde_func_1186_0x139c28(a0, a1);
        case 1187: return fde_func_1187_0x139fd4(a0, a1);
        case 1188: return fde_func_1188_0x13a484(a0, a1);
        case 1189: return fde_func_1189_0x13a810(a0, a1);
        case 1190: return fde_func_1190_0x13b00c(a0, a1);
        case 1191: return fde_func_1191_0x13bde4(a0, a1);
        case 1192: return fde_func_1192_0x13bf84(a0, a1);
        case 1193: return fde_func_1193_0x13c124(a0, a1);
        case 1194: return fde_func_1194_0x13c29c(a0, a1);
        case 1195: return fde_func_1195_0x13c55c(a0, a1);
        case 1196: return fde_func_1196_0x13c954(a0, a1);
        case 1197: return fde_func_1197_0x13cd4c(a0, a1);
        case 1198: return fde_func_1198_0x13d03c(a0, a1);
        case 1199: return fde_func_1199_0x13d45c(a0, a1);
        default: return 0ULL;
    }
}

} // namespace canvas
} // namespace lynx