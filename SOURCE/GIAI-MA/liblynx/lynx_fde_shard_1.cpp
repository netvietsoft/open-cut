// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 1/5 for liblynx.so
// Phân mảnh Khung Tháo Gỡ (FDE) AArch64 C++17 sạch 1/5 cho liblynx.so
// Covers representative FDE indices [0 .. 399] out of 21,675 total FDEs
// Bao phủ chỉ số FDE đại diện [0 .. 399] trên tổng số 21.675 FDE
// ============================================================================
#include "lynx_core.h"

namespace lynx {

// FDE #0000 | PC: 0x14c03c | FDE: 0x0b7750 | Size: 12 bytes [_ZN4lynx5lepus5ValueC2ENS1_20CreateAsUndefinedTagE]
// Khung tháo gỡ #0000 | Địa chỉ PC: 0x14c03c | Địa chỉ FDE: 0x0b7750 | Kích thước: 12 bytes
//   0x14c03c: 52800028  mov      w8, #1
//   0x14c040: 39002008  strb     w8, [x0, #8]
//   0x14c044: D65F03C0  ret      
static inline uint64_t fde_func_0000_0x14c03c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c03cULL ^ (static_cast<uint64_t>(0x52800028ULL) << 13);
    acc = (acc + a1 + 0x39002008ULL) ^ 0x0b7750ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0001 | PC: 0x14c048 | FDE: 0x0b7768 | Size: 124 bytes [_ZN4lynx5lepus5ValueC2ERKS1_]
// Khung tháo gỡ #0001 | Địa chỉ PC: 0x14c048 | Địa chỉ FDE: 0x0b7768 | Kích thước: 124 bytes
//   0x14c048: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x14c04c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14c050: 39402028  ldrb     w8, [x1, #8]
//   0x14c054: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0001_0x14c048(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c048ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b7768ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0002 | PC: 0x14c0c4 | FDE: 0x0b7788 | Size: 240 bytes [_ZN4lynx5lepus5Value13CopyWeakValueERKS1_]
// Khung tháo gỡ #0002 | Địa chỉ PC: 0x14c0c4 | Địa chỉ FDE: 0x0b7788 | Kích thước: 240 bytes
//   0x14c0c4: EB01001F  cmp      x0, x1
//   0x14c0c8: 54000640  b.eq     #0x14c190
//   0x14c0cc: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x14c0d0: A9017BF3  stp      x19, x30, [sp, #0x10]
static inline uint64_t fde_func_0002_0x14c0c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c0c4ULL ^ (static_cast<uint64_t>(0xeb01001fULL) << 13);
    acc = (acc + a1 + 0x54000640ULL) ^ 0x0b7788ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0003 | PC: 0x14c1b4 | FDE: 0x0b77a8 | Size: 116 bytes [_ZN4lynx5lepus5Value9FreeValueEv]
// Khung tháo gỡ #0003 | Địa chỉ PC: 0x14c1b4 | Địa chỉ FDE: 0x0b77a8 | Kích thước: 116 bytes
//   0x14c1b4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x14c1b8: 39402008  ldrb     w8, [x0, #8]
//   0x14c1bc: AA0003F3  mov      x19, x0
//   0x14c1c0: 7100451F  cmp      w8, #0x11
static inline uint64_t fde_func_0003_0x14c1b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c1b4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x39402008ULL) ^ 0x0b77a8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0004 | PC: 0x14c228 | FDE: 0x0b77c0 | Size: 84 bytes [_ZN4lynx5lepus5ValueC2EOS1_]
// Khung tháo gỡ #0004 | Địa chỉ PC: 0x14c228 | Địa chỉ FDE: 0x0b77c0 | Kích thước: 84 bytes
//   0x14c228: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x14c22c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14c230: 39402028  ldrb     w8, [x1, #8]
//   0x14c234: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0004_0x14c228(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c228ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b77c0ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0005 | PC: 0x14c27c | FDE: 0x0b77e0 | Size: 236 bytes [_ZN4lynx5lepus5ValueaSERKS1_]
// Khung tháo gỡ #0005 | Địa chỉ PC: 0x14c27c | Địa chỉ FDE: 0x0b77e0 | Kích thước: 236 bytes
//   0x14c27c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x14c280: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14c284: AA0003F3  mov      x19, x0
//   0x14c288: EB01001F  cmp      x0, x1
static inline uint64_t fde_func_0005_0x14c27c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c27cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b77e0ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0006 | PC: 0x14c368 | FDE: 0x0b7800 | Size: 196 bytes [_ZN4lynx5lepus5ValueaSEOS1_]
// Khung tháo gỡ #0006 | Địa chỉ PC: 0x14c368 | Địa chỉ FDE: 0x0b7800 | Kích thước: 196 bytes
//   0x14c368: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x14c36c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14c370: AA0003F3  mov      x19, x0
//   0x14c374: EB01001F  cmp      x0, x1
static inline uint64_t fde_func_0006_0x14c368(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c368ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b7800ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0007 | PC: 0x14c42c | FDE: 0x0b7820 | Size: 48 bytes [_ZN4lynx5lepus5ValueC1ERKNS_4base6StringE]
// Khung tháo gỡ #0007 | Địa chỉ PC: 0x14c42c | Địa chỉ FDE: 0x0b7820 | Kích thước: 48 bytes
//   0x14c42c: F9400028  ldr      x8, [x1]
//   0x14c430: 52800129  mov      w9, #9
//   0x14c434: B9000C1F  str      wzr, [x0, #0xc]
//   0x14c438: 39002009  strb     w9, [x0, #8]
static inline uint64_t fde_func_0007_0x14c42c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c42cULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0x52800129ULL) ^ 0x0b7820ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0008 | PC: 0x14c45c | FDE: 0x0b7838 | Size: 76 bytes [_ZN4lynx5lepus5ValueC2EONS_4base6StringE]
// Khung tháo gỡ #0008 | Địa chỉ PC: 0x14c45c | Địa chỉ FDE: 0x0b7838 | Kích thước: 76 bytes
//   0x14c45c: F9400028  ldr      x8, [x1]
//   0x14c460: 52800129  mov      w9, #9
//   0x14c464: 39002009  strb     w9, [x0, #8]
//   0x14c468: B9000C1F  str      wzr, [x0, #0xc]
static inline uint64_t fde_func_0008_0x14c45c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c45cULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0x52800129ULL) ^ 0x0b7838ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0009 | PC: 0x14c4a8 | FDE: 0x0b7850 | Size: 48 bytes [_ZN4lynx5lepus5ValueC1ERKNS_3fml6RefPtrINS0_9ByteArrayEEE]
// Khung tháo gỡ #0009 | Địa chỉ PC: 0x14c4a8 | Địa chỉ FDE: 0x0b7850 | Kích thước: 48 bytes
//   0x14c4a8: F9400028  ldr      x8, [x1]
//   0x14c4ac: 52800189  mov      w9, #0xc
//   0x14c4b0: 39002009  strb     w9, [x0, #8]
//   0x14c4b4: B9000C1F  str      wzr, [x0, #0xc]
static inline uint64_t fde_func_0009_0x14c4a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c4a8ULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0x52800189ULL) ^ 0x0b7850ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0010 | PC: 0x14c4d8 | FDE: 0x0b7868 | Size: 28 bytes [_ZN4lynx5lepus5ValueC2EONS_3fml6RefPtrINS0_9ByteArrayEEE]
// Khung tháo gỡ #0010 | Địa chỉ PC: 0x14c4d8 | Địa chỉ FDE: 0x0b7868 | Kích thước: 28 bytes
//   0x14c4d8: F9400028  ldr      x8, [x1]
//   0x14c4dc: 52800189  mov      w9, #0xc
//   0x14c4e0: F900003F  str      xzr, [x1]
//   0x14c4e4: 39002009  strb     w9, [x0, #8]
static inline uint64_t fde_func_0010_0x14c4d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c4d8ULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0x52800189ULL) ^ 0x0b7868ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0011 | PC: 0x14c4f4 | FDE: 0x0b7880 | Size: 88 bytes [_ZN4lynx5lepus5ValueC2ERKNS_3fml6RefPtrINS0_10RefCountedEEE]
// Khung tháo gỡ #0011 | Địa chỉ PC: 0x14c4f4 | Địa chỉ FDE: 0x0b7880 | Kích thước: 88 bytes
//   0x14c4f4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x14c4f8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14c4fc: F9400028  ldr      x8, [x1]
//   0x14c500: 528001A9  mov      w9, #0xd
static inline uint64_t fde_func_0011_0x14c4f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c4f4ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b7880ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0012 | PC: 0x14c54c | FDE: 0x0b78a0 | Size: 72 bytes [_ZN4lynx5lepus5ValueC1EONS_3fml6RefPtrINS0_10RefCountedEEE]
// Khung tháo gỡ #0012 | Địa chỉ PC: 0x14c54c | Địa chỉ FDE: 0x0b78a0 | Kích thước: 72 bytes
//   0x14c54c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x14c550: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14c554: F9400028  ldr      x8, [x1]
//   0x14c558: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0012_0x14c54c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c54cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b78a0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0013 | PC: 0x14c594 | FDE: 0x0b78c0 | Size: 24 bytes [_ZN4lynx5lepus5ValueC1Eb]
// Khung tháo gỡ #0013 | Địa chỉ PC: 0x14c594 | Địa chỉ FDE: 0x0b78c0 | Kích thước: 24 bytes
//   0x14c594: 12000028  and      w8, w1, #1
//   0x14c598: 52800049  mov      w9, #2
//   0x14c59c: 39000008  strb     w8, [x0]
//   0x14c5a0: 39002009  strb     w9, [x0, #8]
static inline uint64_t fde_func_0013_0x14c594(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c594ULL ^ (static_cast<uint64_t>(0x12000028ULL) << 13);
    acc = (acc + a1 + 0x52800049ULL) ^ 0x0b78c0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0014 | PC: 0x14c5ac | FDE: 0x0b78d8 | Size: 64 bytes [_ZN4lynx5lepus5ValueC1EPKc]
// Khung tháo gỡ #0014 | Địa chỉ PC: 0x14c5ac | Địa chỉ FDE: 0x0b78d8 | Kích thước: 64 bytes
//   0x14c5ac: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x14c5b0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14c5b4: AA0003F4  mov      x20, x0
//   0x14c5b8: 52800700  mov      w0, #0x38
static inline uint64_t fde_func_0014_0x14c5ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c5acULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b78d8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0015 | PC: 0x14c5ec | FDE: 0x0b78f8 | Size: 256 bytes [_ZN4lynx5lepus5ValueC1ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE]
// Khung tháo gỡ #0015 | Địa chỉ PC: 0x14c5ec | Địa chỉ FDE: 0x0b78f8 | Kích thước: 256 bytes
//   0x14c5ec: D101C3FF  sub      sp, sp, #0x70
//   0x14c5f0: A9045BF7  stp      x23, x22, [sp, #0x40]
//   0x14c5f4: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x14c5f8: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_0015_0x14c5ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c5ecULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9045bf7ULL) ^ 0x0b78f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0016 | PC: 0x14c6fc | FDE: 0x0b7918 | Size: 148 bytes [_ZN4lynx5lepus5ValueC2EONSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE]
// Khung tháo gỡ #0016 | Địa chỉ PC: 0x14c6fc | Địa chỉ FDE: 0x0b7918 | Kích thước: 148 bytes
//   0x14c6fc: D10183FF  sub      sp, sp, #0x60
//   0x14c700: F9001BF6  str      x22, [sp, #0x30]
//   0x14c704: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x14c708: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0016_0x14c6fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c6fcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf6ULL) ^ 0x0b7918ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0017 | PC: 0x14c790 | FDE: 0x0b7938 | Size: 20 bytes [_ZN4lynx5lepus5ValueC1EPv]
// Khung tháo gỡ #0017 | Địa chỉ PC: 0x14c790 | Địa chỉ FDE: 0x0b7938 | Kích thước: 20 bytes
//   0x14c790: 52800208  mov      w8, #0x10
//   0x14c794: F9000001  str      x1, [x0]
//   0x14c798: 39002008  strb     w8, [x0, #8]
//   0x14c79c: B9000C1F  str      wzr, [x0, #0xc]
static inline uint64_t fde_func_0017_0x14c790(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c790ULL ^ (static_cast<uint64_t>(0x52800208ULL) << 13);
    acc = (acc + a1 + 0xf9000001ULL) ^ 0x0b7938ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0018 | PC: 0x14c7a4 | FDE: 0x0b7950 | Size: 20 bytes [_ZN4lynx5lepus5ValueC2EPFS1_PNS0_7ContextEE]
// Khung tháo gỡ #0018 | Địa chỉ PC: 0x14c7a4 | Địa chỉ FDE: 0x0b7950 | Kích thước: 20 bytes
//   0x14c7a4: 528001C8  mov      w8, #0xe
//   0x14c7a8: F9000001  str      x1, [x0]
//   0x14c7ac: 39002008  strb     w8, [x0, #8]
//   0x14c7b0: B9000C1F  str      wzr, [x0, #0xc]
static inline uint64_t fde_func_0018_0x14c7a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c7a4ULL ^ (static_cast<uint64_t>(0x528001c8ULL) << 13);
    acc = (acc + a1 + 0xf9000001ULL) ^ 0x0b7950ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0019 | PC: 0x14c7b8 | FDE: 0x0b7968 | Size: 20 bytes [_ZN4lynx5lepus5ValueC1EPNS0_20BuiltinFunctionTableE]
// Khung tháo gỡ #0019 | Địa chỉ PC: 0x14c7b8 | Địa chỉ FDE: 0x0b7968 | Kích thước: 20 bytes
//   0x14c7b8: 528001E8  mov      w8, #0xf
//   0x14c7bc: F9000001  str      x1, [x0]
//   0x14c7c0: 39002008  strb     w8, [x0, #8]
//   0x14c7c4: B9000C1F  str      wzr, [x0, #0xc]
static inline uint64_t fde_func_0019_0x14c7b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c7b8ULL ^ (static_cast<uint64_t>(0x528001e8ULL) << 13);
    acc = (acc + a1 + 0xf9000001ULL) ^ 0x0b7968ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0020 | PC: 0x14c7cc | FDE: 0x0b7980 | Size: 24 bytes [_ZN4lynx5lepus5ValueC2Ebb]
// Khung tháo gỡ #0020 | Địa chỉ PC: 0x14c7cc | Địa chỉ FDE: 0x0b7980 | Kích thước: 24 bytes
//   0x14c7cc: 360000A1  tbz      w1, #0, #0x14c7e0
//   0x14c7d0: 12000048  and      w8, w2, #1
//   0x14c7d4: 52800109  mov      w9, #8
//   0x14c7d8: 39000008  strb     w8, [x0]
static inline uint64_t fde_func_0020_0x14c7cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c7ccULL ^ (static_cast<uint64_t>(0x360000a1ULL) << 13);
    acc = (acc + a1 + 0x12000048ULL) ^ 0x0b7980ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0021 | PC: 0x14c7e4 | FDE: 0x0b7998 | Size: 20 bytes [_ZN4lynx5lepus5ValueC1Ed]
// Khung tháo gỡ #0021 | Địa chỉ PC: 0x14c7e4 | Địa chỉ FDE: 0x0b7998 | Kích thước: 20 bytes
//   0x14c7e4: 52800068  mov      w8, #3
//   0x14c7e8: FD000000  str      d0, [x0]
//   0x14c7ec: 39002008  strb     w8, [x0, #8]
//   0x14c7f0: B9000C1F  str      wzr, [x0, #0xc]
static inline uint64_t fde_func_0021_0x14c7e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c7e4ULL ^ (static_cast<uint64_t>(0x52800068ULL) << 13);
    acc = (acc + a1 + 0xfd000000ULL) ^ 0x0b7998ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0022 | PC: 0x14c7f8 | FDE: 0x0b79b0 | Size: 20 bytes [_ZN4lynx5lepus5ValueC1Ei]
// Khung tháo gỡ #0022 | Địa chỉ PC: 0x14c7f8 | Địa chỉ FDE: 0x0b79b0 | Kích thước: 20 bytes
//   0x14c7f8: 52800088  mov      w8, #4
//   0x14c7fc: B9000001  str      w1, [x0]
//   0x14c800: 39002008  strb     w8, [x0, #8]
//   0x14c804: B9000C1F  str      wzr, [x0, #0xc]
static inline uint64_t fde_func_0022_0x14c7f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c7f8ULL ^ (static_cast<uint64_t>(0x52800088ULL) << 13);
    acc = (acc + a1 + 0xb9000001ULL) ^ 0x0b79b0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0023 | PC: 0x14c80c | FDE: 0x0b79c8 | Size: 20 bytes [_ZN4lynx5lepus5ValueC1Ej]
// Khung tháo gỡ #0023 | Địa chỉ PC: 0x14c80c | Địa chỉ FDE: 0x0b79c8 | Kích thước: 20 bytes
//   0x14c80c: 528000A8  mov      w8, #5
//   0x14c810: B9000001  str      w1, [x0]
//   0x14c814: 39002008  strb     w8, [x0, #8]
//   0x14c818: B9000C1F  str      wzr, [x0, #0xc]
static inline uint64_t fde_func_0023_0x14c80c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c80cULL ^ (static_cast<uint64_t>(0x528000a8ULL) << 13);
    acc = (acc + a1 + 0xb9000001ULL) ^ 0x0b79c8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0024 | PC: 0x14c820 | FDE: 0x0b79e0 | Size: 20 bytes [_ZN4lynx5lepus5ValueC1El]
// Khung tháo gỡ #0024 | Địa chỉ PC: 0x14c820 | Địa chỉ FDE: 0x0b79e0 | Kích thước: 20 bytes
//   0x14c820: 528000C8  mov      w8, #6
//   0x14c824: F9000001  str      x1, [x0]
//   0x14c828: 39002008  strb     w8, [x0, #8]
//   0x14c82c: B9000C1F  str      wzr, [x0, #0xc]
static inline uint64_t fde_func_0024_0x14c820(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c820ULL ^ (static_cast<uint64_t>(0x528000c8ULL) << 13);
    acc = (acc + a1 + 0xf9000001ULL) ^ 0x0b79e0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0025 | PC: 0x14c834 | FDE: 0x0b79f8 | Size: 20 bytes [_ZN4lynx5lepus5ValueC1Em]
// Khung tháo gỡ #0025 | Địa chỉ PC: 0x14c834 | Địa chỉ FDE: 0x0b79f8 | Kích thước: 20 bytes
//   0x14c834: 528000E8  mov      w8, #7
//   0x14c838: F9000001  str      x1, [x0]
//   0x14c83c: 39002008  strb     w8, [x0, #8]
//   0x14c840: B9000C1F  str      wzr, [x0, #0xc]
static inline uint64_t fde_func_0025_0x14c834(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c834ULL ^ (static_cast<uint64_t>(0x528000e8ULL) << 13);
    acc = (acc + a1 + 0xf9000001ULL) ^ 0x0b79f8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0026 | PC: 0x14c848 | FDE: 0x0b7a10 | Size: 24 bytes [_ZN4lynx5lepus5ValueC1Eh]
// Khung tháo gỡ #0026 | Địa chỉ PC: 0x14c848 | Địa chỉ FDE: 0x0b7a10 | Kích thước: 24 bytes
//   0x14c848: 12001C28  and      w8, w1, #0xff
//   0x14c84c: 528000A9  mov      w9, #5
//   0x14c850: B9000008  str      w8, [x0]
//   0x14c854: 39002009  strb     w9, [x0, #8]
static inline uint64_t fde_func_0026_0x14c848(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c848ULL ^ (static_cast<uint64_t>(0x12001c28ULL) << 13);
    acc = (acc + a1 + 0x528000a9ULL) ^ 0x0b7a10ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0027 | PC: 0x14c860 | FDE: 0x0b7a28 | Size: 48 bytes [_ZN4lynx5lepus5ValueC2ERKNS_3fml10WeakRefPtrINS0_10DictionaryEEE]
// Khung tháo gỡ #0027 | Địa chỉ PC: 0x14c860 | Địa chỉ FDE: 0x0b7a28 | Kích thước: 48 bytes
//   0x14c860: F9400028  ldr      x8, [x1]
//   0x14c864: 52800169  mov      w9, #0xb
//   0x14c868: 39002009  strb     w9, [x0, #8]
//   0x14c86c: B9000C1F  str      wzr, [x0, #0xc]
static inline uint64_t fde_func_0027_0x14c860(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c860ULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0x52800169ULL) ^ 0x0b7a28ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0028 | PC: 0x14c890 | FDE: 0x0b7a40 | Size: 28 bytes [_ZN4lynx5lepus5ValueC1EONS_3fml6RefPtrINS0_10DictionaryEEE]
// Khung tháo gỡ #0028 | Địa chỉ PC: 0x14c890 | Địa chỉ FDE: 0x0b7a40 | Kích thước: 28 bytes
//   0x14c890: F9400028  ldr      x8, [x1]
//   0x14c894: 52800169  mov      w9, #0xb
//   0x14c898: F900003F  str      xzr, [x1]
//   0x14c89c: 39002009  strb     w9, [x0, #8]
static inline uint64_t fde_func_0028_0x14c890(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c890ULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0x52800169ULL) ^ 0x0b7a40ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0029 | PC: 0x14c8ac | FDE: 0x0b7a58 | Size: 48 bytes [_ZN4lynx5lepus5ValueC2ERKNS_3fml10WeakRefPtrINS0_6CArrayEEE]
// Khung tháo gỡ #0029 | Địa chỉ PC: 0x14c8ac | Địa chỉ FDE: 0x0b7a58 | Kích thước: 48 bytes
//   0x14c8ac: F9400028  ldr      x8, [x1]
//   0x14c8b0: 52800149  mov      w9, #0xa
//   0x14c8b4: 39002009  strb     w9, [x0, #8]
//   0x14c8b8: B9000C1F  str      wzr, [x0, #0xc]
static inline uint64_t fde_func_0029_0x14c8ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c8acULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0x52800149ULL) ^ 0x0b7a58ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0030 | PC: 0x14c8dc | FDE: 0x0b7a70 | Size: 28 bytes [_ZN4lynx5lepus5ValueC2EONS_3fml6RefPtrINS0_6CArrayEEE]
// Khung tháo gỡ #0030 | Địa chỉ PC: 0x14c8dc | Địa chỉ FDE: 0x0b7a70 | Kích thước: 28 bytes
//   0x14c8dc: F9400028  ldr      x8, [x1]
//   0x14c8e0: 52800149  mov      w9, #0xa
//   0x14c8e4: F900003F  str      xzr, [x1]
//   0x14c8e8: 39002009  strb     w9, [x0, #8]
static inline uint64_t fde_func_0030_0x14c8dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c8dcULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0x52800149ULL) ^ 0x0b7a70ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0031 | PC: 0x14c8f8 | FDE: 0x0b7a88 | Size: 12 bytes [_ZN4lynx5lepus5ValueC2EO10lynx_value]
// Khung tháo gỡ #0031 | Địa chỉ PC: 0x14c8f8 | Địa chỉ FDE: 0x0b7a88 | Kích thước: 12 bytes
//   0x14c8f8: 3DC00020  ldr      q0, [x1]
//   0x14c8fc: 3D800000  str      q0, [x0]
//   0x14c900: D65F03C0  ret      
static inline uint64_t fde_func_0031_0x14c8f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c8f8ULL ^ (static_cast<uint64_t>(0x3dc00020ULL) << 13);
    acc = (acc + a1 + 0x3d800000ULL) ^ 0x0b7a88ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0032 | PC: 0x14c904 | FDE: 0x0b7aa0 | Size: 48 bytes [_ZN4lynx5lepus5ValueC2EP14lynx_api_env__li]
// Khung tháo gỡ #0032 | Địa chỉ PC: 0x14c904 | Địa chỉ FDE: 0x0b7aa0 | Kích thước: 48 bytes
//   0x14c904: 52800229  mov      w9, #0x11
//   0x14c908: B9000C03  str      w3, [x0, #0xc]
//   0x14c90c: AA0003E3  mov      x3, x0
//   0x14c910: F9000801  str      x1, [x0, #0x10]
static inline uint64_t fde_func_0032_0x14c904(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c904ULL ^ (static_cast<uint64_t>(0x52800229ULL) << 13);
    acc = (acc + a1 + 0xb9000c03ULL) ^ 0x0b7aa0ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0033 | PC: 0x14c934 | FDE: 0x0b7ab8 | Size: 104 bytes [_ZN4lynx5lepus5ValueC2EP14lynx_api_env__RK10lynx_value]
// Khung tháo gỡ #0033 | Địa chỉ PC: 0x14c934 | Địa chỉ FDE: 0x0b7ab8 | Kích thước: 104 bytes
//   0x14c934: 3DC00040  ldr      q0, [x2]
//   0x14c938: F9000801  str      x1, [x0, #0x10]
//   0x14c93c: 3D800000  str      q0, [x0]
//   0x14c940: B4000141  cbz      x1, #0x14c968
static inline uint64_t fde_func_0033_0x14c934(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c934ULL ^ (static_cast<uint64_t>(0x3dc00040ULL) << 13);
    acc = (acc + a1 + 0xf9000801ULL) ^ 0x0b7ab8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0034 | PC: 0x14c99c | FDE: 0x0b7ad0 | Size: 60 bytes [_ZN4lynx5lepus5ValueC2EP14lynx_api_env__O10lynx_value]
// Khung tháo gỡ #0034 | Địa chỉ PC: 0x14c99c | Địa chỉ FDE: 0x0b7ad0 | Kích thước: 60 bytes
//   0x14c99c: 3DC00040  ldr      q0, [x2]
//   0x14c9a0: F9000801  str      x1, [x0, #0x10]
//   0x14c9a4: 3D800000  str      q0, [x0]
//   0x14c9a8: B4000161  cbz      x1, #0x14c9d4
static inline uint64_t fde_func_0034_0x14c99c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c99cULL ^ (static_cast<uint64_t>(0x3dc00040ULL) << 13);
    acc = (acc + a1 + 0xf9000801ULL) ^ 0x0b7ad0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0035 | PC: 0x14c9d8 | FDE: 0x0b7ae8 | Size: 128 bytes [_ZNK4lynx5lepus5Value12ToLepusValueEb]
// Khung tháo gỡ #0035 | Địa chỉ PC: 0x14c9d8 | Địa chỉ FDE: 0x0b7ae8 | Kích thước: 128 bytes
//   0x14c9d8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x14c9dc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14c9e0: 12000021  and      w1, w1, #1
//   0x14c9e4: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0035_0x14c9d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14c9d8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b7ae8ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0036 | PC: 0x14ca58 | FDE: 0x0b7b08 | Size: 256 bytes [_ZN4lynx5lepus5Value23ToLepusValueRecursivelyERS1_b]
// Khung tháo gỡ #0036 | Địa chỉ PC: 0x14ca58 | Địa chỉ FDE: 0x0b7b08 | Kích thước: 256 bytes
//   0x14ca58: D101C3FF  sub      sp, sp, #0x70
//   0x14ca5c: F90023F6  str      x22, [sp, #0x40]
//   0x14ca60: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x14ca64: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_0036_0x14ca58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ca58ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f6ULL) ^ 0x0b7b08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0037 | PC: 0x14cdf0 | FDE: 0x0b7b28 | Size: 256 bytes [_ZN4lynx5lepus5Value12ToLepusValueEP14lynx_api_env__RK10lynx_valuei]
// Khung tháo gỡ #0037 | Địa chỉ PC: 0x14cdf0 | Địa chỉ FDE: 0x0b7b28 | Kích thước: 256 bytes
//   0x14cdf0: D10203FF  sub      sp, sp, #0x80
//   0x14cdf4: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x14cdf8: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x14cdfc: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0037_0x14cdf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14cdf0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9055bf7ULL) ^ 0x0b7b28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0038 | PC: 0x14d3a4 | FDE: 0x0b7b50 | Size: 196 bytes [_ZNK4lynx5lepus5Value6NumberEv]
// Khung tháo gỡ #0038 | Địa chỉ PC: 0x14d3a4 | Địa chỉ FDE: 0x0b7b50 | Kích thước: 196 bytes
//   0x14d3a4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x14d3a8: 39402008  ldrb     w8, [x0, #8]
//   0x14d3ac: 9E6703E0  fmov     d0, xzr
//   0x14d3b0: 51000D08  sub      w8, w8, #3
static inline uint64_t fde_func_0038_0x14d3a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14d3a4ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x39402008ULL) ^ 0x0b7b50ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0039 | PC: 0x14d468 | FDE: 0x0b7b68 | Size: 60 bytes [_ZNK4lynx5lepus5Value11LEPUSNumberEv]
// Khung tháo gỡ #0039 | Địa chỉ PC: 0x14d468 | Địa chỉ FDE: 0x0b7b68 | Kích thước: 60 bytes
//   0x14d468: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x14d46c: 39402008  ldrb     w8, [x0, #8]
//   0x14d470: 7100451F  cmp      w8, #0x11
//   0x14d474: 54000121  b.ne     #0x14d498
static inline uint64_t fde_func_0039_0x14d468(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14d468ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x39402008ULL) ^ 0x0b7b68ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0040 | PC: 0x14d4a4 | FDE: 0x0b7b80 | Size: 204 bytes [_ZNK4lynx5lepus5Value9StdStringEv]
// Khung tháo gỡ #0040 | Địa chỉ PC: 0x14d4a4 | Địa chỉ FDE: 0x0b7b80 | Kích thước: 204 bytes
//   0x14d4a4: D10083FF  sub      sp, sp, #0x20
//   0x14d4a8: F9000BFE  str      x30, [sp, #0x10]
//   0x14d4ac: 39402009  ldrb     w9, [x0, #8]
//   0x14d4b0: 7100093F  cmp      w9, #2
static inline uint64_t fde_func_0040_0x14d4a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14d4a4ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfeULL) ^ 0x0b7b80ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #0041 | PC: 0x14d570 | FDE: 0x0b7b98 | Size: 196 bytes [_ZNKR4lynx5lepus5Value6StringEv]
// Khung tháo gỡ #0041 | Địa chỉ PC: 0x14d570 | Địa chỉ FDE: 0x0b7b98 | Kích thước: 196 bytes
//   0x14d570: D10083FF  sub      sp, sp, #0x20
//   0x14d574: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14d578: 39402009  ldrb     w9, [x0, #8]
//   0x14d57c: AA0803F3  mov      x19, x8
static inline uint64_t fde_func_0041_0x14d570(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14d570ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b7b98ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0042 | PC: 0x14d634 | FDE: 0x0b7bb0 | Size: 256 bytes [_ZNO4lynx5lepus5Value6StringEv]
// Khung tháo gỡ #0042 | Địa chỉ PC: 0x14d634 | Địa chỉ FDE: 0x0b7bb0 | Kích thước: 256 bytes
//   0x14d634: D10083FF  sub      sp, sp, #0x20
//   0x14d638: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14d63c: 39402009  ldrb     w9, [x0, #8]
//   0x14d640: AA0803F3  mov      x19, x8
static inline uint64_t fde_func_0042_0x14d634(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14d634ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b7bb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0043 | PC: 0x14d790 | FDE: 0x0b7bc8 | Size: 60 bytes [_ZNKR4lynx5lepus5Value9ByteArrayEv]
// Khung tháo gỡ #0043 | Địa chỉ PC: 0x14d790 | Địa chỉ FDE: 0x0b7bc8 | Kích thước: 60 bytes
//   0x14d790: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x14d794: AA0003E9  mov      x9, x0
//   0x14d798: F9400000  ldr      x0, [x0]
//   0x14d79c: AA0803F3  mov      x19, x8
static inline uint64_t fde_func_0043_0x14d790(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14d790ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003e9ULL) ^ 0x0b7bc8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0044 | PC: 0x14d7cc | FDE: 0x0b7be0 | Size: 184 bytes [_ZN4lynx5lepus5Value14DummyByteArrayEv]
// Khung tháo gỡ #0044 | Địa chỉ PC: 0x14d7cc | Địa chỉ FDE: 0x0b7be0 | Kích thước: 184 bytes
//   0x14d7cc: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x14d7d0: F00010A0  adrp     x0, #0x364000
//   0x14d7d4: 91028000  add      x0, x0, #0xa0
//   0x14d7d8: 9407CAB2  bl       #0x3402a0
static inline uint64_t fde_func_0044_0x14d7cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14d7ccULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf00010a0ULL) ^ 0x0b7be0ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0045 | PC: 0x14d884 | FDE: 0x0b7bf8 | Size: 112 bytes [_ZNO4lynx5lepus5Value9ByteArrayEv]
// Khung tháo gỡ #0045 | Địa chỉ PC: 0x14d884 | Địa chỉ FDE: 0x0b7bf8 | Kích thước: 112 bytes
//   0x14d884: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x14d888: F9400009  ldr      x9, [x0]
//   0x14d88c: AA0803F3  mov      x19, x8
//   0x14d890: B4000189  cbz      x9, #0x14d8c0
static inline uint64_t fde_func_0045_0x14d884(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14d884ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400009ULL) ^ 0x0b7bf8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0046 | PC: 0x14d8f4 | FDE: 0x0b7c10 | Size: 60 bytes [_ZNKR4lynx5lepus5Value5TableEv]
// Khung tháo gỡ #0046 | Địa chỉ PC: 0x14d8f4 | Địa chỉ FDE: 0x0b7c10 | Kích thước: 60 bytes
//   0x14d8f4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x14d8f8: AA0003E9  mov      x9, x0
//   0x14d8fc: F9400000  ldr      x0, [x0]
//   0x14d900: AA0803F3  mov      x19, x8
static inline uint64_t fde_func_0046_0x14d8f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14d8f4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003e9ULL) ^ 0x0b7c10ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0047 | PC: 0x14d930 | FDE: 0x0b7c28 | Size: 256 bytes [_ZN4lynx5lepus5Value10DummyTableEv]
// Khung tháo gỡ #0047 | Địa chỉ PC: 0x14d930 | Địa chỉ FDE: 0x0b7c28 | Kích thước: 256 bytes
//   0x14d930: D10083FF  sub      sp, sp, #0x20
//   0x14d934: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14d938: F00010A0  adrp     x0, #0x364000
//   0x14d93c: 91018000  add      x0, x0, #0x60
static inline uint64_t fde_func_0047_0x14d930(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14d930ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b7c28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0048 | PC: 0x14da50 | FDE: 0x0b7c40 | Size: 116 bytes [_ZNO4lynx5lepus5Value5TableEv]
// Khung tháo gỡ #0048 | Địa chỉ PC: 0x14da50 | Địa chỉ FDE: 0x0b7c40 | Kích thước: 116 bytes
//   0x14da50: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x14da54: F9400009  ldr      x9, [x0]
//   0x14da58: AA0803F3  mov      x19, x8
//   0x14da5c: B4000189  cbz      x9, #0x14da8c
static inline uint64_t fde_func_0048_0x14da50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14da50ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400009ULL) ^ 0x0b7c40ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0049 | PC: 0x14dac4 | FDE: 0x0b7c58 | Size: 60 bytes [_ZNKR4lynx5lepus5Value5ArrayEv]
// Khung tháo gỡ #0049 | Địa chỉ PC: 0x14dac4 | Địa chỉ FDE: 0x0b7c58 | Kích thước: 60 bytes
//   0x14dac4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x14dac8: AA0003E9  mov      x9, x0
//   0x14dacc: F9400000  ldr      x0, [x0]
//   0x14dad0: AA0803F3  mov      x19, x8
static inline uint64_t fde_func_0049_0x14dac4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14dac4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003e9ULL) ^ 0x0b7c58ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0050 | PC: 0x14db00 | FDE: 0x0b7c70 | Size: 256 bytes [_ZN4lynx5lepus5Value10DummyArrayEv]
// Khung tháo gỡ #0050 | Địa chỉ PC: 0x14db00 | Địa chỉ FDE: 0x0b7c70 | Kích thước: 256 bytes
//   0x14db00: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x14db04: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14db08: F00010A0  adrp     x0, #0x364000
//   0x14db0c: 91008000  add      x0, x0, #0x20
static inline uint64_t fde_func_0050_0x14db00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14db00ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b7c70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0051 | PC: 0x14dc24 | FDE: 0x0b7c90 | Size: 112 bytes [_ZNO4lynx5lepus5Value5ArrayEv]
// Khung tháo gỡ #0051 | Địa chỉ PC: 0x14dc24 | Địa chỉ FDE: 0x0b7c90 | Kích thước: 112 bytes
//   0x14dc24: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x14dc28: F9400009  ldr      x9, [x0]
//   0x14dc2c: AA0803F3  mov      x19, x8
//   0x14dc30: B4000189  cbz      x9, #0x14dc60
static inline uint64_t fde_func_0051_0x14dc24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14dc24ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400009ULL) ^ 0x0b7c90ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0052 | PC: 0x14dc94 | FDE: 0x0b7ca8 | Size: 32 bytes [_ZNKR4lynx5lepus5Value10RefCountedEv]
// Khung tháo gỡ #0052 | Địa chỉ PC: 0x14dc94 | Địa chỉ FDE: 0x0b7ca8 | Kích thước: 32 bytes
//   0x14dc94: 39402009  ldrb     w9, [x0, #8]
//   0x14dc98: 7100353F  cmp      w9, #0xd
//   0x14dc9c: 54000081  b.ne     #0x14dcac
//   0x14dca0: F9400009  ldr      x9, [x0]
static inline uint64_t fde_func_0052_0x14dc94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14dc94ULL ^ (static_cast<uint64_t>(0x39402009ULL) << 13);
    acc = (acc + a1 + 0x7100353fULL) ^ 0x0b7ca8ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0053 | PC: 0x14dcb4 | FDE: 0x0b7cc0 | Size: 56 bytes [_ZNO4lynx5lepus5Value10RefCountedEv]
// Khung tháo gỡ #0053 | Địa chỉ PC: 0x14dcb4 | Địa chỉ FDE: 0x0b7cc0 | Kích thước: 56 bytes
//   0x14dcb4: 39402009  ldrb     w9, [x0, #8]
//   0x14dcb8: 7100353F  cmp      w9, #0xd
//   0x14dcbc: 54000141  b.ne     #0x14dce4
//   0x14dcc0: F9400009  ldr      x9, [x0]
static inline uint64_t fde_func_0053_0x14dcb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14dcb4ULL ^ (static_cast<uint64_t>(0x39402009ULL) << 13);
    acc = (acc + a1 + 0x7100353fULL) ^ 0x0b7cc0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0054 | PC: 0x14dcec | FDE: 0x0b7cd8 | Size: 28 bytes [_ZNK4lynx5lepus5Value8FunctionEv]
// Khung tháo gỡ #0054 | Địa chỉ PC: 0x14dcec | Địa chỉ FDE: 0x0b7cd8 | Kích thước: 28 bytes
//   0x14dcec: 39402008  ldrb     w8, [x0, #8]
//   0x14dcf0: 7100391F  cmp      w8, #0xe
//   0x14dcf4: 54000061  b.ne     #0x14dd00
//   0x14dcf8: F9400000  ldr      x0, [x0]
static inline uint64_t fde_func_0054_0x14dcec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14dcecULL ^ (static_cast<uint64_t>(0x39402008ULL) << 13);
    acc = (acc + a1 + 0x7100391fULL) ^ 0x0b7cd8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0055 | PC: 0x14dd08 | FDE: 0x0b7cf0 | Size: 28 bytes [_ZNK4lynx5lepus5Value13FunctionTableEv]
// Khung tháo gỡ #0055 | Địa chỉ PC: 0x14dd08 | Địa chỉ FDE: 0x0b7cf0 | Kích thước: 28 bytes
//   0x14dd08: 39402008  ldrb     w8, [x0, #8]
//   0x14dd0c: 71003D1F  cmp      w8, #0xf
//   0x14dd10: 54000061  b.ne     #0x14dd1c
//   0x14dd14: F9400000  ldr      x0, [x0]
static inline uint64_t fde_func_0055_0x14dd08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14dd08ULL ^ (static_cast<uint64_t>(0x39402008ULL) << 13);
    acc = (acc + a1 + 0x71003d1fULL) ^ 0x0b7cf0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0056 | PC: 0x14dd24 | FDE: 0x0b7d08 | Size: 96 bytes [_ZNK4lynx5lepus5Value6CPointEv]
// Khung tháo gỡ #0056 | Địa chỉ PC: 0x14dd24 | Địa chỉ FDE: 0x0b7d08 | Kích thước: 96 bytes
//   0x14dd24: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x14dd28: 39402008  ldrb     w8, [x0, #8]
//   0x14dd2c: 7100451F  cmp      w8, #0x11
//   0x14dd30: 540000C0  b.eq     #0x14dd48
static inline uint64_t fde_func_0056_0x14dd24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14dd24ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x39402008ULL) ^ 0x0b7d08ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0057 | PC: 0x14dd84 | FDE: 0x0b7d20 | Size: 132 bytes [_ZN4lynx5lepus5Value6SetNanEb]
// Khung tháo gỡ #0057 | Địa chỉ PC: 0x14dd84 | Địa chỉ FDE: 0x0b7d20 | Kích thước: 132 bytes
//   0x14dd84: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x14dd88: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14dd8c: 39402008  ldrb     w8, [x0, #8]
//   0x14dd90: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0057_0x14dd84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14dd84ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b7d20ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0058 | PC: 0x14de08 | FDE: 0x0b7d40 | Size: 132 bytes [_ZN4lynx5lepus5Value9SetCPointEPv]
// Khung tháo gỡ #0058 | Địa chỉ PC: 0x14de08 | Địa chỉ FDE: 0x0b7d40 | Kích thước: 132 bytes
//   0x14de08: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x14de0c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14de10: 39402008  ldrb     w8, [x0, #8]
//   0x14de14: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0058_0x14de08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14de08ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b7d40ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0059 | PC: 0x14de8c | FDE: 0x0b7d60 | Size: 132 bytes [_ZN4lynx5lepus5Value12SetCFunctionEPFS1_PNS0_7ContextEE]
// Khung tháo gỡ #0059 | Địa chỉ PC: 0x14de8c | Địa chỉ FDE: 0x0b7d60 | Kích thước: 132 bytes
//   0x14de8c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x14de90: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14de94: 39402008  ldrb     w8, [x0, #8]
//   0x14de98: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0059_0x14de8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14de8cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b7d60ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0060 | PC: 0x14df10 | FDE: 0x0b7d80 | Size: 132 bytes [_ZN4lynx5lepus5Value7SetBoolEb]
// Khung tháo gỡ #0060 | Địa chỉ PC: 0x14df10 | Địa chỉ FDE: 0x0b7d80 | Kích thước: 132 bytes
//   0x14df10: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x14df14: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14df18: 39402008  ldrb     w8, [x0, #8]
//   0x14df1c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0060_0x14df10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14df10ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b7d80ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0061 | PC: 0x14df94 | FDE: 0x0b7da0 | Size: 160 bytes [_ZN4lynx5lepus5Value9SetStringERKNS_4base6StringE]
// Khung tháo gỡ #0061 | Địa chỉ PC: 0x14df94 | Địa chỉ FDE: 0x0b7da0 | Kích thước: 160 bytes
//   0x14df94: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x14df98: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14df9c: 39402008  ldrb     w8, [x0, #8]
//   0x14dfa0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0061_0x14df94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14df94ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b7da0ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0062 | PC: 0x14e034 | FDE: 0x0b7dc0 | Size: 200 bytes [_ZN4lynx5lepus5Value9SetStringEONS_4base6StringE]
// Khung tháo gỡ #0062 | Địa chỉ PC: 0x14e034 | Địa chỉ FDE: 0x0b7dc0 | Kích thước: 200 bytes
//   0x14e034: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x14e038: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14e03c: 39402008  ldrb     w8, [x0, #8]
//   0x14e040: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0062_0x14e034(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e034ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b7dc0ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0063 | PC: 0x14e0fc | FDE: 0x0b7de0 | Size: 160 bytes [_ZN4lynx5lepus5Value8SetTableERKNS_3fml6RefPtrINS0_10DictionaryEEE]
// Khung tháo gỡ #0063 | Địa chỉ PC: 0x14e0fc | Địa chỉ FDE: 0x0b7de0 | Kích thước: 160 bytes
//   0x14e0fc: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x14e100: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14e104: 39402008  ldrb     w8, [x0, #8]
//   0x14e108: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0063_0x14e0fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e0fcULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b7de0ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0064 | PC: 0x14e19c | FDE: 0x0b7e00 | Size: 140 bytes [_ZN4lynx5lepus5Value8SetTableEONS_3fml6RefPtrINS0_10DictionaryEEE]
// Khung tháo gỡ #0064 | Địa chỉ PC: 0x14e19c | Địa chỉ FDE: 0x0b7e00 | Kích thước: 140 bytes
//   0x14e19c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x14e1a0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14e1a4: 39402008  ldrb     w8, [x0, #8]
//   0x14e1a8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0064_0x14e19c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e19cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b7e00ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0065 | PC: 0x14e228 | FDE: 0x0b7e20 | Size: 160 bytes [_ZN4lynx5lepus5Value8SetArrayERKNS_3fml6RefPtrINS0_6CArrayEEE]
// Khung tháo gỡ #0065 | Địa chỉ PC: 0x14e228 | Địa chỉ FDE: 0x0b7e20 | Kích thước: 160 bytes
//   0x14e228: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x14e22c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14e230: 39402008  ldrb     w8, [x0, #8]
//   0x14e234: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0065_0x14e228(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e228ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b7e20ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0066 | PC: 0x14e2c8 | FDE: 0x0b7e40 | Size: 140 bytes [_ZN4lynx5lepus5Value8SetArrayEONS_3fml6RefPtrINS0_6CArrayEEE]
// Khung tháo gỡ #0066 | Địa chỉ PC: 0x14e2c8 | Địa chỉ FDE: 0x0b7e40 | Kích thước: 140 bytes
//   0x14e2c8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x14e2cc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14e2d0: 39402008  ldrb     w8, [x0, #8]
//   0x14e2d4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0066_0x14e2c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e2c8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b7e40ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0067 | PC: 0x14e354 | FDE: 0x0b7e60 | Size: 160 bytes [_ZN4lynx5lepus5Value12SetByteArrayERKNS_3fml6RefPtrINS0_9ByteArrayEEE]
// Khung tháo gỡ #0067 | Địa chỉ PC: 0x14e354 | Địa chỉ FDE: 0x0b7e60 | Kích thước: 160 bytes
//   0x14e354: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x14e358: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14e35c: 39402008  ldrb     w8, [x0, #8]
//   0x14e360: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0067_0x14e354(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e354ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b7e60ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0068 | PC: 0x14e3f4 | FDE: 0x0b7e80 | Size: 140 bytes [_ZN4lynx5lepus5Value12SetByteArrayEONS_3fml6RefPtrINS0_9ByteArrayEEE]
// Khung tháo gỡ #0068 | Địa chỉ PC: 0x14e3f4 | Địa chỉ FDE: 0x0b7e80 | Kích thước: 140 bytes
//   0x14e3f4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x14e3f8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14e3fc: 39402008  ldrb     w8, [x0, #8]
//   0x14e400: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0068_0x14e3f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e3f4ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b7e80ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0069 | PC: 0x14e480 | FDE: 0x0b7ea0 | Size: 180 bytes [_ZN4lynx5lepus5Value13SetRefCountedERKNS_3fml6RefPtrINS0_10RefCountedEEE]
// Khung tháo gỡ #0069 | Địa chỉ PC: 0x14e480 | Địa chỉ FDE: 0x0b7ea0 | Kích thước: 180 bytes
//   0x14e480: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x14e484: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14e488: 39402008  ldrb     w8, [x0, #8]
//   0x14e48c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0069_0x14e480(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e480ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b7ea0ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #0070 | PC: 0x14e534 | FDE: 0x0b7ec0 | Size: 160 bytes [_ZN4lynx5lepus5Value13SetRefCountedEONS_3fml6RefPtrINS0_10RefCountedEEE]
// Khung tháo gỡ #0070 | Địa chỉ PC: 0x14e534 | Địa chỉ FDE: 0x0b7ec0 | Kích thước: 160 bytes
//   0x14e534: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x14e538: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14e53c: 39402008  ldrb     w8, [x0, #8]
//   0x14e540: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0070_0x14e534(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e534ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b7ec0ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0071 | PC: 0x14e5d4 | FDE: 0x0b7ee0 | Size: 156 bytes [_ZNK4lynx5lepus5Value9GetLengthEv]
// Khung tháo gỡ #0071 | Địa chỉ PC: 0x14e5d4 | Địa chỉ FDE: 0x0b7ee0 | Kích thước: 156 bytes
//   0x14e5d4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x14e5d8: F9400001  ldr      x1, [x0]
//   0x14e5dc: B4000221  cbz      x1, #0x14e620
//   0x14e5e0: 39402009  ldrb     w9, [x0, #8]
static inline uint64_t fde_func_0071_0x14e5d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e5d4ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400001ULL) ^ 0x0b7ee0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0072 | PC: 0x14e670 | FDE: 0x0b7ef8 | Size: 4 bytes [_ZNK4lynx5lepus5Value7IsEqualERKS1_]
// Khung tháo gỡ #0072 | Địa chỉ PC: 0x14e670 | Địa chỉ FDE: 0x0b7ef8 | Kích thước: 4 bytes
//   0x14e670: 1407C728  b        #0x340310
static inline uint64_t fde_func_0072_0x14e670(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e670ULL ^ (static_cast<uint64_t>(0x1407c728ULL) << 13);
    acc = (acc + a1 + 0xd10103ffULL) ^ 0x0b7ef8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0073 | PC: 0x14e674 | FDE: 0x0b7f10 | Size: 256 bytes [_ZN4lynx5lepuseqERKNS0_5ValueES3_]
// Khung tháo gỡ #0073 | Địa chỉ PC: 0x14e674 | Địa chỉ FDE: 0x0b7f10 | Kích thước: 256 bytes
//   0x14e674: D10103FF  sub      sp, sp, #0x40
//   0x14e678: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x14e67c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x14e680: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0073_0x14e674(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e674ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0b7f10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0074 | PC: 0x14eadc | FDE: 0x0b7f30 | Size: 256 bytes [_ZN4lynx5lepus5Value11SetPropertyEjRKS1_]
// Khung tháo gỡ #0074 | Địa chỉ PC: 0x14eadc | Địa chỉ FDE: 0x0b7f30 | Kích thước: 256 bytes
//   0x14eadc: D10103FF  sub      sp, sp, #0x40
//   0x14eae0: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x14eae4: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x14eae8: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0074_0x14eadc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14eadcULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0b7f30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0075 | PC: 0x14ec40 | FDE: 0x0b7f50 | Size: 68 bytes [_ZNK4lynx5lepus5Value9IsJSArrayEv]
// Khung tháo gỡ #0075 | Địa chỉ PC: 0x14ec40 | Địa chỉ FDE: 0x0b7f50 | Kích thước: 68 bytes
//   0x14ec40: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x14ec44: 39402008  ldrb     w8, [x0, #8]
//   0x14ec48: 7100451F  cmp      w8, #0x11
//   0x14ec4c: 54000161  b.ne     #0x14ec78
static inline uint64_t fde_func_0075_0x14ec40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ec40ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x39402008ULL) ^ 0x0b7f50ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0076 | PC: 0x14ec84 | FDE: 0x0b7f68 | Size: 256 bytes [_ZN4lynx5lepus5Value11SetPropertyEjOS1_]
// Khung tháo gỡ #0076 | Địa chỉ PC: 0x14ec84 | Địa chỉ FDE: 0x0b7f68 | Kích thước: 256 bytes
//   0x14ec84: D10103FF  sub      sp, sp, #0x40
//   0x14ec88: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x14ec8c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x14ec90: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0076_0x14ec84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ec84ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0b7f68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0077 | PC: 0x14ede8 | FDE: 0x0b7f88 | Size: 188 bytes [_ZN4lynx5lepus5Value11SetPropertyERKNS_4base6StringERKS1_]
// Khung tháo gỡ #0077 | Địa chỉ PC: 0x14ede8 | Địa chỉ FDE: 0x0b7f88 | Kích thước: 188 bytes
//   0x14ede8: D100C3FF  sub      sp, sp, #0x30
//   0x14edec: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x14edf0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x14edf4: 39402008  ldrb     w8, [x0, #8]
static inline uint64_t fde_func_0077_0x14ede8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14ede8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0b7f88ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0078 | PC: 0x14eea4 | FDE: 0x0b7fa8 | Size: 256 bytes [_ZNK4lynx5lepus5Value9IsJSTableEv]
// Khung tháo gỡ #0078 | Địa chỉ PC: 0x14eea4 | Địa chỉ FDE: 0x0b7fa8 | Kích thước: 256 bytes
//   0x14eea4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x14eea8: 39402008  ldrb     w8, [x0, #8]
//   0x14eeac: 7100451F  cmp      w8, #0x11
//   0x14eeb0: 54000161  b.ne     #0x14eedc
static inline uint64_t fde_func_0078_0x14eea4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14eea4ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x39402008ULL) ^ 0x0b7fa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0079 | PC: 0x14f040 | FDE: 0x0b7fe0 | Size: 216 bytes [_ZN4lynx5lepus5Value11SetPropertyEONS_4base6StringERKS1_]
// Khung tháo gỡ #0079 | Địa chỉ PC: 0x14f040 | Địa chỉ FDE: 0x0b7fe0 | Kích thước: 216 bytes
//   0x14f040: D100C3FF  sub      sp, sp, #0x30
//   0x14f044: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x14f048: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x14f04c: 39402008  ldrb     w8, [x0, #8]
static inline uint64_t fde_func_0079_0x14f040(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f040ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0b7fe0ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #0080 | PC: 0x14f118 | FDE: 0x0b8000 | Size: 256 bytes [_ZN4lynx5lepus5Value11SetPropertyEONS_4base6StringEOS1_]
// Khung tháo gỡ #0080 | Địa chỉ PC: 0x14f118 | Địa chỉ FDE: 0x0b8000 | Kích thước: 256 bytes
//   0x14f118: D100C3FF  sub      sp, sp, #0x30
//   0x14f11c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x14f120: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x14f124: 39402008  ldrb     w8, [x0, #8]
static inline uint64_t fde_func_0080_0x14f118(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f118ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0b8000ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0081 | PC: 0x14f314 | FDE: 0x0b8040 | Size: 256 bytes [_ZNK4lynx5lepus5Value11GetPropertyEj]
// Khung tháo gỡ #0081 | Địa chỉ PC: 0x14f314 | Địa chỉ FDE: 0x0b8040 | Kích thước: 256 bytes
//   0x14f314: D100C3FF  sub      sp, sp, #0x30
//   0x14f318: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x14f31c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x14f320: 39402009  ldrb     w9, [x0, #8]
static inline uint64_t fde_func_0081_0x14f314(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f314ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0b8040ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0082 | PC: 0x14f57c | FDE: 0x0b8060 | Size: 256 bytes [_ZNK4lynx5lepus5Value11GetPropertyERKNS_4base6StringE]
// Khung tháo gỡ #0082 | Địa chỉ PC: 0x14f57c | Địa chỉ FDE: 0x0b8060 | Kích thước: 256 bytes
//   0x14f57c: D100C3FF  sub      sp, sp, #0x30
//   0x14f580: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x14f584: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x14f588: 39402009  ldrb     w9, [x0, #8]
static inline uint64_t fde_func_0082_0x14f57c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f57cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0b8060ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0083 | PC: 0x14f6d4 | FDE: 0x0b8080 | Size: 192 bytes [_ZNK4lynx5lepus5Value8ContainsERKNS_4base6StringE]
// Khung tháo gỡ #0083 | Địa chỉ PC: 0x14f6d4 | Địa chỉ FDE: 0x0b8080 | Kích thước: 192 bytes
//   0x14f6d4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x14f6d8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14f6dc: 39402008  ldrb     w8, [x0, #8]
//   0x14f6e0: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0083_0x14f6d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f6d4ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b8080ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #0084 | PC: 0x14f794 | FDE: 0x0b80a0 | Size: 256 bytes [_ZN4lynx5lepus5Value10MergeValueERS1_RKS1_]
// Khung tháo gỡ #0084 | Địa chỉ PC: 0x14f794 | Địa chỉ FDE: 0x0b80a0 | Kích thước: 256 bytes
//   0x14f794: D10703FF  sub      sp, sp, #0x1c0
//   0x14f798: A9166FFC  stp      x28, x27, [sp, #0x160]
//   0x14f79c: A91767FA  stp      x26, x25, [sp, #0x170]
//   0x14f7a0: A9185FF8  stp      x24, x23, [sp, #0x180]
static inline uint64_t fde_func_0084_0x14f794(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f794ULL ^ (static_cast<uint64_t>(0xd10703ffULL) << 13);
    acc = (acc + a1 + 0xa9166ffcULL) ^ 0x0b80a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0085 | PC: 0x14fe44 | FDE: 0x0b80d0 | Size: 256 bytes [_ZN4lynx5lepus5Value17ForEachLepusValueERKS1_NS_4base15MoveOnlyClosureIvJS3_S3_EEE]
// Khung tháo gỡ #0085 | Địa chỉ PC: 0x14fe44 | Địa chỉ FDE: 0x0b80d0 | Kích thước: 256 bytes
//   0x14fe44: D10203FF  sub      sp, sp, #0x80
//   0x14fe48: F90023F8  str      x24, [sp, #0x40]
//   0x14fe4c: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x14fe50: A90653F5  stp      x21, x20, [sp, #0x60]
static inline uint64_t fde_func_0085_0x14fe44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14fe44ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f8ULL) ^ 0x0b80d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0086 | PC: 0x15043c | FDE: 0x0b8118 | Size: 8 bytes [_ZN4lynx5lepus5Value5CloneERKS1_b]
// Khung tháo gỡ #0086 | Địa chỉ PC: 0x15043c | Địa chỉ FDE: 0x0b8118 | Kích thước: 8 bytes
//   0x15043c: 12000021  and      w1, w1, #1
//   0x150440: 1407BF7C  b        #0x340230
static inline uint64_t fde_func_0086_0x15043c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15043cULL ^ (static_cast<uint64_t>(0x12000021ULL) << 13);
    acc = (acc + a1 + 0x1407bf7cULL) ^ 0x0b8118ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0087 | PC: 0x150444 | FDE: 0x0b8130 | Size: 256 bytes [_ZN4lynx5lepus5Value17UpdateValueByPathERS1_RKS1_RKNS_4base6VectorINSt6__ndk112basic_stringIcNS7_11char_traitsIcEENS7_9allocatorIcEEEELm0EEE]
// Khung tháo gỡ #0087 | Địa chỉ PC: 0x150444 | Địa chỉ FDE: 0x0b8130 | Kích thước: 256 bytes
//   0x150444: D101C3FF  sub      sp, sp, #0x70
//   0x150448: F90023F6  str      x22, [sp, #0x40]
//   0x15044c: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x150450: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_0087_0x150444(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150444ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f6ULL) ^ 0x0b8130ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0088 | PC: 0x150620 | FDE: 0x0b8150 | Size: 256 bytes [_ZN4lynx5lepus5Value25SetPropertyToTableOrArrayERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEERKS1_]
// Khung tháo gỡ #0088 | Địa chỉ PC: 0x150620 | Địa chỉ FDE: 0x0b8150 | Kích thước: 256 bytes
//   0x150620: D10103FF  sub      sp, sp, #0x40
//   0x150624: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x150628: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x15062c: 39402008  ldrb     w8, [x0, #8]
static inline uint64_t fde_func_0088_0x150620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150620ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x0b8150ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0089 | PC: 0x15072c | FDE: 0x0b8170 | Size: 256 bytes [_ZNK4lynx5lepus5Value27GetPropertyFromTableOrArrayERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE]
// Khung tháo gỡ #0089 | Địa chỉ PC: 0x15072c | Địa chỉ FDE: 0x0b8170 | Kích thước: 256 bytes
//   0x15072c: D10103FF  sub      sp, sp, #0x40
//   0x150730: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x150734: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x150738: 39402009  ldrb     w9, [x0, #8]
static inline uint64_t fde_func_0089_0x15072c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15072cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x0b8170ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0090 | PC: 0x150840 | FDE: 0x0b8190 | Size: 256 bytes [_ZN4lynx5lepus5Value16CloneRecursivelyERKS1_b]
// Khung tháo gỡ #0090 | Địa chỉ PC: 0x150840 | Địa chỉ FDE: 0x0b8190 | Kích thước: 256 bytes
//   0x150840: D10203FF  sub      sp, sp, #0x80
//   0x150844: F90023F8  str      x24, [sp, #0x40]
//   0x150848: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x15084c: A90653F5  stp      x21, x20, [sp, #0x60]
static inline uint64_t fde_func_0090_0x150840(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150840ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f8ULL) ^ 0x0b8190ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0091 | PC: 0x150c9c | FDE: 0x0b81b8 | Size: 28 bytes [_ZNK4lynx5lepus5Value5Int32Ev]
// Khung tháo gỡ #0091 | Địa chỉ PC: 0x150c9c | Địa chỉ FDE: 0x0b81b8 | Kích thước: 28 bytes
//   0x150c9c: 39402008  ldrb     w8, [x0, #8]
//   0x150ca0: 7100111F  cmp      w8, #4
//   0x150ca4: 54000061  b.ne     #0x150cb0
//   0x150ca8: B9400000  ldr      w0, [x0]
static inline uint64_t fde_func_0091_0x150c9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150c9cULL ^ (static_cast<uint64_t>(0x39402008ULL) << 13);
    acc = (acc + a1 + 0x7100111fULL) ^ 0x0b81b8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0092 | PC: 0x150cb8 | FDE: 0x0b81d0 | Size: 132 bytes [_ZNK4lynx5lepus5Value5Int64Ev]
// Khung tháo gỡ #0092 | Địa chỉ PC: 0x150cb8 | Địa chỉ FDE: 0x0b81d0 | Kích thước: 132 bytes
//   0x150cb8: D10083FF  sub      sp, sp, #0x20
//   0x150cbc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x150cc0: 39402008  ldrb     w8, [x0, #8]
//   0x150cc4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0092_0x150cb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150cb8ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b81d0ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0093 | PC: 0x150d3c | FDE: 0x0b81e8 | Size: 28 bytes [_ZNK4lynx5lepus5Value6UInt32Ev]
// Khung tháo gỡ #0093 | Địa chỉ PC: 0x150d3c | Địa chỉ FDE: 0x0b81e8 | Kích thước: 28 bytes
//   0x150d3c: 39402008  ldrb     w8, [x0, #8]
//   0x150d40: 7100151F  cmp      w8, #5
//   0x150d44: 54000061  b.ne     #0x150d50
//   0x150d48: B9400000  ldr      w0, [x0]
static inline uint64_t fde_func_0093_0x150d3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150d3cULL ^ (static_cast<uint64_t>(0x39402008ULL) << 13);
    acc = (acc + a1 + 0x7100151fULL) ^ 0x0b81e8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0094 | PC: 0x150d58 | FDE: 0x0b8200 | Size: 28 bytes [_ZNK4lynx5lepus5Value6UInt64Ev]
// Khung tháo gỡ #0094 | Địa chỉ PC: 0x150d58 | Địa chỉ FDE: 0x0b8200 | Kích thước: 28 bytes
//   0x150d58: 39402008  ldrb     w8, [x0, #8]
//   0x150d5c: 71001D1F  cmp      w8, #7
//   0x150d60: 54000061  b.ne     #0x150d6c
//   0x150d64: F9400000  ldr      x0, [x0]
static inline uint64_t fde_func_0094_0x150d58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150d58ULL ^ (static_cast<uint64_t>(0x39402008ULL) << 13);
    acc = (acc + a1 + 0x71001d1fULL) ^ 0x0b8200ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0095 | PC: 0x150d74 | FDE: 0x0b8218 | Size: 256 bytes [_ZN4lynx5lepus5Value11ShallowCopyERKS1_b]
// Khung tháo gỡ #0095 | Địa chỉ PC: 0x150d74 | Địa chỉ FDE: 0x0b8218 | Kích thước: 256 bytes
//   0x150d74: D10283FF  sub      sp, sp, #0xa0
//   0x150d78: F90023FC  str      x28, [sp, #0x40]
//   0x150d7c: A9056BFB  stp      x27, x26, [sp, #0x50]
//   0x150d80: A90663F9  stp      x25, x24, [sp, #0x60]
static inline uint64_t fde_func_0095_0x150d74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150d74ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90023fcULL) ^ 0x0b8218ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0096 | PC: 0x15153c | FDE: 0x0b8248 | Size: 256 bytes [_ZNK4lynx5lepus5Value9MarkConstEv]
// Khung tháo gỡ #0096 | Địa chỉ PC: 0x15153c | Địa chỉ FDE: 0x0b8248 | Kích thước: 256 bytes
//   0x15153c: D10143FF  sub      sp, sp, #0x50
//   0x151540: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x151544: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x151548: 39402008  ldrb     w8, [x0, #8]
static inline uint64_t fde_func_0096_0x15153c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15153cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90353f5ULL) ^ 0x0b8248ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0097 | PC: 0x151770 | FDE: 0x0b8268 | Size: 256 bytes [_ZN4lynx5lepus5Value32IsLepusValueEqualToExtendedValueEP14lynx_api_env__RKS1_RK10lynx_value]
// Khung tháo gỡ #0097 | Địa chỉ PC: 0x151770 | Địa chỉ FDE: 0x0b8268 | Kích thước: 256 bytes
//   0x151770: D10183FF  sub      sp, sp, #0x60
//   0x151774: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x151778: A9057BF3  stp      x19, x30, [sp, #0x50]
//   0x15177c: AA0203F3  mov      x19, x2
static inline uint64_t fde_func_0097_0x151770(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x151770ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90453f5ULL) ^ 0x0b8268ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0098 | PC: 0x151b78 | FDE: 0x0b82a8 | Size: 48 bytes [_ZN4lynx5lepus5Value13ResetValueRefEv]
// Khung tháo gỡ #0098 | Địa chỉ PC: 0x151b78 | Địa chỉ FDE: 0x0b82a8 | Kích thước: 48 bytes
//   0x151b78: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x151b7c: 39402008  ldrb     w8, [x0, #8]
//   0x151b80: 7100451F  cmp      w8, #0x11
//   0x151b84: 540000E1  b.ne     #0x151ba0
static inline uint64_t fde_func_0098_0x151b78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x151b78ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x39402008ULL) ^ 0x0b82a8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0099 | PC: 0x151ba8 | FDE: 0x0b82c0 | Size: 24 bytes [_ZNK4lynx5lepus5Value6DoubleEv]
// Khung tháo gỡ #0099 | Địa chỉ PC: 0x151ba8 | Địa chỉ FDE: 0x0b82c0 | Kích thước: 24 bytes
//   0x151ba8: 39402008  ldrb     w8, [x0, #8]
//   0x151bac: 9E6703E0  fmov     d0, xzr
//   0x151bb0: 71000D1F  cmp      w8, #3
//   0x151bb4: 54000041  b.ne     #0x151bbc
static inline uint64_t fde_func_0099_0x151ba8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x151ba8ULL ^ (static_cast<uint64_t>(0x39402008ULL) << 13);
    acc = (acc + a1 + 0x9e6703e0ULL) ^ 0x0b82c0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0100 | PC: 0x151bc0 | FDE: 0x0b82d8 | Size: 68 bytes [_ZNK4lynx5lepus5Value11IsJSIntegerEv]
// Khung tháo gỡ #0100 | Địa chỉ PC: 0x151bc0 | Địa chỉ FDE: 0x0b82d8 | Kích thước: 68 bytes
//   0x151bc0: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x151bc4: 39402008  ldrb     w8, [x0, #8]
//   0x151bc8: 7100451F  cmp      w8, #0x11
//   0x151bcc: 54000161  b.ne     #0x151bf8
static inline uint64_t fde_func_0100_0x151bc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x151bc0ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x39402008ULL) ^ 0x0b82d8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0101 | PC: 0x151c04 | FDE: 0x0b82f0 | Size: 60 bytes [_ZNK4lynx5lepus5Value9JSIntegerEv]
// Khung tháo gỡ #0101 | Địa chỉ PC: 0x151c04 | Địa chỉ FDE: 0x0b82f0 | Kích thước: 60 bytes
//   0x151c04: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x151c08: 39402008  ldrb     w8, [x0, #8]
//   0x151c0c: 7100451F  cmp      w8, #0x11
//   0x151c10: 54000121  b.ne     #0x151c34
static inline uint64_t fde_func_0101_0x151c04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x151c04ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x39402008ULL) ^ 0x0b82f0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0102 | PC: 0x151c40 | FDE: 0x0b8308 | Size: 68 bytes [_ZNK4lynx5lepus5Value12IsJSFunctionEv]
// Khung tháo gỡ #0102 | Địa chỉ PC: 0x151c40 | Địa chỉ FDE: 0x0b8308 | Kích thước: 68 bytes
//   0x151c40: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x151c44: 39402008  ldrb     w8, [x0, #8]
//   0x151c48: 7100451F  cmp      w8, #0x11
//   0x151c4c: 54000161  b.ne     #0x151c78
static inline uint64_t fde_func_0102_0x151c40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x151c40ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x39402008ULL) ^ 0x0b8308ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0103 | PC: 0x151c84 | FDE: 0x0b8320 | Size: 60 bytes [_ZNK4lynx5lepus5Value11GetJSLengthEv]
// Khung tháo gỡ #0103 | Địa chỉ PC: 0x151c84 | Địa chỉ FDE: 0x0b8320 | Kích thước: 60 bytes
//   0x151c84: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x151c88: 39402008  ldrb     w8, [x0, #8]
//   0x151c8c: 7100451F  cmp      w8, #0x11
//   0x151c90: 54000121  b.ne     #0x151cb4
static inline uint64_t fde_func_0103_0x151c84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x151c84ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x39402008ULL) ^ 0x0b8320ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0104 | PC: 0x151cc0 | FDE: 0x0b8338 | Size: 256 bytes [_ZNK4lynx5lepus5Value9IsJSFalseEv]
// Khung tháo gỡ #0104 | Địa chỉ PC: 0x151cc0 | Địa chỉ FDE: 0x0b8338 | Kích thước: 256 bytes
//   0x151cc0: D100C3FF  sub      sp, sp, #0x30
//   0x151cc4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x151cc8: 39402008  ldrb     w8, [x0, #8]
//   0x151ccc: 7100451F  cmp      w8, #0x11
static inline uint64_t fde_func_0104_0x151cc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x151cc0ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9027bf3ULL) ^ 0x0b8338ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0105 | PC: 0x151dfc | FDE: 0x0b8350 | Size: 256 bytes [_ZNK4lynx5lepus5Value8ToStringEv]
// Khung tháo gỡ #0105 | Địa chỉ PC: 0x151dfc | Địa chỉ FDE: 0x0b8350 | Kích thước: 256 bytes
//   0x151dfc: D10143FF  sub      sp, sp, #0x50
//   0x151e00: F90013F6  str      x22, [sp, #0x20]
//   0x151e04: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x151e08: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0105_0x151dfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x151dfcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x0b8350ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0106 | PC: 0x151efc | FDE: 0x0b8370 | Size: 224 bytes [_ZNK4lynx5lepus5Value15IteratorJSValueERKNS_4base15MoveOnlyClosureIvJRKS1_S5_EEE]
// Khung tháo gỡ #0106 | Địa chỉ PC: 0x151efc | Địa chỉ FDE: 0x0b8370 | Kích thước: 224 bytes
//   0x151efc: D10183FF  sub      sp, sp, #0x60
//   0x151f00: F90023F4  str      x20, [sp, #0x40]
//   0x151f04: A9057BF3  stp      x19, x30, [sp, #0x50]
//   0x151f08: 39402008  ldrb     w8, [x0, #8]
static inline uint64_t fde_func_0106_0x151efc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x151efcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90023f4ULL) ^ 0x0b8370ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #0107 | PC: 0x151fdc | FDE: 0x0b8390 | Size: 168 bytes [_ZN4lynx5lepus5Value15ToLynxValueTypeENS0_9ValueTypeE]
// Khung tháo gỡ #0107 | Địa chỉ PC: 0x151fdc | Địa chỉ FDE: 0x0b8390 | Kích thước: 168 bytes
//   0x151fdc: 71004C1F  cmp      w0, #0x13
//   0x151fe0: 54000168  b.hi     #0x15200c
//   0x151fe4: B0FFF889  adrp     x9, #0x62000
//   0x151fe8: 2A0003E8  mov      w8, w0
static inline uint64_t fde_func_0107_0x151fdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x151fdcULL ^ (static_cast<uint64_t>(0x71004c1fULL) << 13);
    acc = (acc + a1 + 0x54000168ULL) ^ 0x0b8390ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #0108 | PC: 0x152084 | FDE: 0x0b83a8 | Size: 216 bytes [_ZN4lynx5lepus5Value23LegacyTypeFromLynxValueERK10lynx_value]
// Khung tháo gỡ #0108 | Địa chỉ PC: 0x152084 | Địa chỉ FDE: 0x0b83a8 | Kích thước: 216 bytes
//   0x152084: 39402008  ldrb     w8, [x0, #8]
//   0x152088: 51000508  sub      w8, w8, #1
//   0x15208c: 7100411F  cmp      w8, #0x10
//   0x152090: 54000228  b.hi     #0x1520d4
static inline uint64_t fde_func_0108_0x152084(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x152084ULL ^ (static_cast<uint64_t>(0x39402008ULL) << 13);
    acc = (acc + a1 + 0x51000508ULL) ^ 0x0b83a8ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #0109 | PC: 0x15215c | FDE: 0x0b83c0 | Size: 256 bytes [_ZN4lynx5lepus5Value12ToLepusArrayEP14lynx_api_env__RK10lynx_valuei]
// Khung tháo gỡ #0109 | Địa chỉ PC: 0x15215c | Địa chỉ FDE: 0x0b83c0 | Kích thước: 256 bytes
//   0x15215c: D10203FF  sub      sp, sp, #0x80
//   0x152160: F9002BF6  str      x22, [sp, #0x50]
//   0x152164: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x152168: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0109_0x15215c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15215cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf6ULL) ^ 0x0b83c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0110 | PC: 0x1522a4 | FDE: 0x0b83e0 | Size: 256 bytes [_ZN4lynx5lepus5Value10ToLepusMapEP14lynx_api_env__RK10lynx_valuei]
// Khung tháo gỡ #0110 | Địa chỉ PC: 0x1522a4 | Địa chỉ FDE: 0x0b83e0 | Kích thước: 256 bytes
//   0x1522a4: D10203FF  sub      sp, sp, #0x80
//   0x1522a8: F9002BF6  str      x22, [sp, #0x50]
//   0x1522ac: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x1522b0: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0110_0x1522a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1522a4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf6ULL) ^ 0x0b83e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0111 | PC: 0x1523f0 | FDE: 0x0b8400 | Size: 256 bytes [_ZN4lynx5lepus5Value32IsLepusArrayEqualToExtendedArrayEP14lynx_api_env__PNS0_6CArrayERK10lynx_value]
// Khung tháo gỡ #0111 | Địa chỉ PC: 0x1523f0 | Địa chỉ FDE: 0x0b8400 | Kích thước: 256 bytes
//   0x1523f0: D101C3FF  sub      sp, sp, #0x70
//   0x1523f4: F9001BF8  str      x24, [sp, #0x30]
//   0x1523f8: A9045BF7  stp      x23, x22, [sp, #0x40]
//   0x1523fc: A90553F5  stp      x21, x20, [sp, #0x50]
static inline uint64_t fde_func_0111_0x1523f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1523f0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf8ULL) ^ 0x0b8400ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0112 | PC: 0x1525f8 | FDE: 0x0b8428 | Size: 256 bytes [_ZN4lynx5lepus5Value30IsLepusDictEqualToExtendedDictEP14lynx_api_env__PNS0_10DictionaryERK10lynx_value]
// Khung tháo gỡ #0112 | Địa chỉ PC: 0x1525f8 | Địa chỉ FDE: 0x0b8428 | Kích thước: 256 bytes
//   0x1525f8: D10103FF  sub      sp, sp, #0x40
//   0x1525fc: A90203F4  stp      x20, x0, [sp, #0x20]
//   0x152600: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x152604: AA0203F3  mov      x19, x2
static inline uint64_t fde_func_0112_0x1525f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1525f8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90203f4ULL) ^ 0x0b8428ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0113 | PC: 0x1528e4 | FDE: 0x0b84a8 | Size: 24 bytes
// Khung tháo gỡ #0113 | Địa chỉ PC: 0x1528e4 | Địa chỉ FDE: 0x0b84a8 | Kích thước: 24 bytes
//   0x1528e4: 2A1F03E0  mov      w0, wzr
//   0x1528e8: D65F03C0  ret      
//   0x1528ec: 52800040  mov      w0, #2
//   0x1528f0: D65F03C0  ret      
static inline uint64_t fde_func_0113_0x1528e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1528e4ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0b84a8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0114 | PC: 0x1528fc | FDE: 0x0b84f0 | Size: 164 bytes [_ZN4lynx7profile15RuntimeProfiler14StartProfilingENS_4base15MoveOnlyClosureIvJEEEb]
// Khung tháo gỡ #0114 | Địa chỉ PC: 0x1528fc | Địa chỉ FDE: 0x0b84f0 | Kích thước: 164 bytes
//   0x1528fc: D65F03C0  ret      
//   0x152900: F9400028  ldr      x8, [x1]
//   0x152904: EB00011F  cmp      x8, x0
//   0x152908: 1A9F17E0  cset     w0, eq
static inline uint64_t fde_func_0114_0x1528fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1528fcULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xf9400028ULL) ^ 0x0b84f0ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0115 | PC: 0x1529a0 | FDE: 0x0b8538 | Size: 256 bytes [_ZN4lynx5piper18PreparedJavaScriptD0Ev]
// Khung tháo gỡ #0115 | Địa chỉ PC: 0x1529a0 | Địa chỉ FDE: 0x0b8538 | Kích thước: 256 bytes
//   0x1529a0: D4200020  brk      #1
//   0x1529a4: 39400008  ldrb     w8, [x0]
//   0x1529a8: AA0103E2  mov      x2, x1
//   0x1529ac: 340001A8  cbz      w8, #0x1529e0
static inline uint64_t fde_func_0115_0x1529a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1529a0ULL ^ (static_cast<uint64_t>(0xd4200020ULL) << 13);
    acc = (acc + a1 + 0x39400008ULL) ^ 0x0b8538ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0116 | PC: 0x152fb0 | FDE: 0x0b85c0 | Size: 256 bytes
// Khung tháo gỡ #0116 | Địa chỉ PC: 0x152fb0 | Địa chỉ FDE: 0x0b85c0 | Kích thước: 256 bytes
//   0x152fb0: D10203FF  sub      sp, sp, #0x80
//   0x152fb4: F90013FC  str      x28, [sp, #0x20]
//   0x152fb8: A9036BFB  stp      x27, x26, [sp, #0x30]
//   0x152fbc: A90463F9  stp      x25, x24, [sp, #0x40]
static inline uint64_t fde_func_0116_0x152fb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x152fb0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fcULL) ^ 0x0b85c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0117 | PC: 0x153d78 | FDE: 0x0b8718 | Size: 256 bytes
// Khung tháo gỡ #0117 | Địa chỉ PC: 0x153d78 | Địa chỉ FDE: 0x0b8718 | Kích thước: 256 bytes
//   0x153d78: D10203FF  sub      sp, sp, #0x80
//   0x153d7c: F90013FC  str      x28, [sp, #0x20]
//   0x153d80: A9036BFB  stp      x27, x26, [sp, #0x30]
//   0x153d84: A90463F9  stp      x25, x24, [sp, #0x40]
static inline uint64_t fde_func_0117_0x153d78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x153d78ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fcULL) ^ 0x0b8718ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0118 | PC: 0x154c74 | FDE: 0x0b8870 | Size: 256 bytes
// Khung tháo gỡ #0118 | Địa chỉ PC: 0x154c74 | Địa chỉ FDE: 0x0b8870 | Kích thước: 256 bytes
//   0x154c74: D10243FF  sub      sp, sp, #0x90
//   0x154c78: A90563F9  stp      x25, x24, [sp, #0x50]
//   0x154c7c: A9065BF7  stp      x23, x22, [sp, #0x60]
//   0x154c80: A90753F5  stp      x21, x20, [sp, #0x70]
static inline uint64_t fde_func_0118_0x154c74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x154c74ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90563f9ULL) ^ 0x0b8870ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0119 | PC: 0x15539c | FDE: 0x0b88e8 | Size: 256 bytes [_ZNK4lynx5lepus5Value5PrintEv]
// Khung tháo gỡ #0119 | Địa chỉ PC: 0x15539c | Địa chỉ FDE: 0x0b88e8 | Kích thước: 256 bytes
//   0x15539c: D10743FF  sub      sp, sp, #0x1d0
//   0x1553a0: F900BBFC  str      x28, [sp, #0x170]
//   0x1553a4: A9186BFB  stp      x27, x26, [sp, #0x180]
//   0x1553a8: A91963F9  stp      x25, x24, [sp, #0x190]
static inline uint64_t fde_func_0119_0x15539c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15539cULL ^ (static_cast<uint64_t>(0xd10743ffULL) << 13);
    acc = (acc + a1 + 0xf900bbfcULL) ^ 0x0b88e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0120 | PC: 0x15551c | FDE: 0x0b8918 | Size: 256 bytes [_ZNK4lynx5lepus5Value10PrintValueERNSt6__ndk113basic_ostreamIcNS2_11char_traitsIcEEEEbbb]
// Khung tháo gỡ #0120 | Địa chỉ PC: 0x15551c | Địa chỉ FDE: 0x0b8918 | Kích thước: 256 bytes
//   0x15551c: D10343FF  sub      sp, sp, #0xd0
//   0x155520: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x155524: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x155528: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0120_0x15551c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15551cULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x0b8918ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0121 | PC: 0x1565a4 | FDE: 0x0b8a00 | Size: 256 bytes
// Khung tháo gỡ #0121 | Địa chỉ PC: 0x1565a4 | Địa chỉ FDE: 0x0b8a00 | Kích thước: 256 bytes
//   0x1565a4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1565a8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1565ac: F9400008  ldr      x8, [x0]
//   0x1565b0: D0000F69  adrp     x9, #0x344000
static inline uint64_t fde_func_0121_0x1565a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1565a4ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b8a00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0122 | PC: 0x156968 | FDE: 0x0b8aa0 | Size: 44 bytes [_ZN4lynx5lepus9ByteArrayC1ENSt6__ndk110unique_ptrIA_hNS2_14default_deleteIS4_EEEEm]
// Khung tháo gỡ #0122 | Địa chỉ PC: 0x156968 | Địa chỉ FDE: 0x0b8aa0 | Kích thước: 44 bytes
//   0x156968: 90FFF868  adrp     x8, #0x62000
//   0x15696c: 3DC0FD00  ldr      q0, [x8, #0x3f0]
//   0x156970: F0001048  adrp     x8, #0x361000
//   0x156974: F9460108  ldr      x8, [x8, #0xc00]
static inline uint64_t fde_func_0122_0x156968(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x156968ULL ^ (static_cast<uint64_t>(0x90fff868ULL) << 13);
    acc = (acc + a1 + 0x3dc0fd00ULL) ^ 0x0b8aa0ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0123 | PC: 0x156994 | FDE: 0x0b8ab8 | Size: 16 bytes [_ZN4lynx5lepus9ByteArray7MovePtrEv]
// Khung tháo gỡ #0123 | Địa chỉ PC: 0x156994 | Địa chỉ FDE: 0x0b8ab8 | Kích thước: 16 bytes
//   0x156994: F9400C09  ldr      x9, [x0, #0x18]
//   0x156998: A901FC1F  stp      xzr, xzr, [x0, #0x18]
//   0x15699c: F9000109  str      x9, [x8]
//   0x1569a0: D65F03C0  ret      
static inline uint64_t fde_func_0123_0x156994(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x156994ULL ^ (static_cast<uint64_t>(0xf9400c09ULL) << 13);
    acc = (acc + a1 + 0xa901fc1fULL) ^ 0x0b8ab8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0124 | PC: 0x1569a4 | FDE: 0x0b8ad0 | Size: 8 bytes [_ZN4lynx5lepus9ByteArray6GetPtrEv]
// Khung tháo gỡ #0124 | Địa chỉ PC: 0x1569a4 | Địa chỉ FDE: 0x0b8ad0 | Kích thước: 8 bytes
//   0x1569a4: F9400C00  ldr      x0, [x0, #0x18]
//   0x1569a8: D65F03C0  ret      
static inline uint64_t fde_func_0124_0x1569a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1569a4ULL ^ (static_cast<uint64_t>(0xf9400c00ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0b8ad0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0125 | PC: 0x1569ac | FDE: 0x0b8ae8 | Size: 256 bytes [_ZN4lynx5lepus9ByteArray9GetLengthEv]
// Khung tháo gỡ #0125 | Địa chỉ PC: 0x1569ac | Địa chỉ FDE: 0x0b8ae8 | Kích thước: 256 bytes
//   0x1569ac: F9401000  ldr      x0, [x0, #0x20]
//   0x1569b0: D65F03C0  ret      
//   0x1569b4: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x1569b8: A90167FA  stp      x26, x25, [sp, #0x10]
static inline uint64_t fde_func_0125_0x1569ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1569acULL ^ (static_cast<uint64_t>(0xf9401000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0b8ae8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0126 | PC: 0x15737c | FDE: 0x0b8b30 | Size: 256 bytes
// Khung tháo gỡ #0126 | Địa chỉ PC: 0x15737c | Địa chỉ FDE: 0x0b8b30 | Kích thước: 256 bytes
//   0x15737c: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x157380: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x157384: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x157388: 91010014  add      x20, x0, #0x40
static inline uint64_t fde_func_0126_0x15737c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15737cULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0b8b30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0127 | PC: 0x157674 | FDE: 0x0b8b88 | Size: 256 bytes [_ZN4lynx5lepus10Dictionary5EraseERKNS_4base6StringE]
// Khung tháo gỡ #0127 | Địa chỉ PC: 0x157674 | Địa chỉ FDE: 0x0b8b88 | Kích thước: 256 bytes
//   0x157674: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x157678: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x15767c: F9400008  ldr      x8, [x0]
//   0x157680: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0127_0x157674(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x157674ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b8b88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0128 | PC: 0x157a00 | FDE: 0x0b8bd8 | Size: 72 bytes [_ZN4lynx5lepus10Dictionary8EraseKeyERKNS_4base6StringE]
// Khung tháo gỡ #0128 | Địa chỉ PC: 0x157a00 | Địa chỉ FDE: 0x0b8bd8 | Kích thước: 72 bytes
//   0x157a00: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x157a04: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x157a08: F9400008  ldr      x8, [x0]
//   0x157a0c: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0128_0x157a00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x157a00ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b8bd8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0129 | PC: 0x157a48 | FDE: 0x0b8bf8 | Size: 164 bytes [_ZNK4lynx5lepus10Dictionary8GetValueERKNS_4base6StringE]
// Khung tháo gỡ #0129 | Địa chỉ PC: 0x157a48 | Địa chỉ FDE: 0x0b8bf8 | Kích thước: 164 bytes
//   0x157a48: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x157a4c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x157a50: 91004000  add      x0, x0, #0x10
//   0x157a54: AA0803F3  mov      x19, x8
static inline uint64_t fde_func_0129_0x157a48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x157a48ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b8bf8ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0130 | PC: 0x157aec | FDE: 0x0b8c18 | Size: 172 bytes [_ZNK4lynx5lepus10Dictionary19GetValueOrUndefinedERKNS_4base6StringE]
// Khung tháo gỡ #0130 | Địa chỉ PC: 0x157aec | Địa chỉ FDE: 0x0b8c18 | Kích thước: 172 bytes
//   0x157aec: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x157af0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x157af4: 91004000  add      x0, x0, #0x10
//   0x157af8: AA0803F3  mov      x19, x8
static inline uint64_t fde_func_0130_0x157aec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x157aecULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b8c18ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0131 | PC: 0x157b98 | FDE: 0x0b8c38 | Size: 256 bytes [_ZNK4lynx5lepus10Dictionary14GetValueOrNullERKNS_4base6StringE]
// Khung tháo gỡ #0131 | Địa chỉ PC: 0x157b98 | Địa chỉ FDE: 0x0b8c38 | Kích thước: 256 bytes
//   0x157b98: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x157b9c: 91004000  add      x0, x0, #0x10
//   0x157ba0: AA0803F3  mov      x19, x8
//   0x157ba4: 940046B3  bl       #0x169670
static inline uint64_t fde_func_0131_0x157b98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x157b98ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x91004000ULL) ^ 0x0b8c38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0132 | PC: 0x157ea4 | FDE: 0x0b8c70 | Size: 256 bytes
// Khung tháo gỡ #0132 | Địa chỉ PC: 0x157ea4 | Địa chỉ FDE: 0x0b8c70 | Kích thước: 256 bytes
//   0x157ea4: D102C3FF  sub      sp, sp, #0xb0
//   0x157ea8: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x157eac: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x157eb0: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0132_0x157ea4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x157ea4ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x0b8c70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0133 | PC: 0x15811c | FDE: 0x0b8cb8 | Size: 124 bytes [_ZN4lynx4base20RefCountedStringImpl6Unsafe11kTrueStringEv]
// Khung tháo gỡ #0133 | Địa chỉ PC: 0x15811c | Địa chỉ FDE: 0x0b8cb8 | Kích thước: 124 bytes
//   0x15811c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x158120: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x158124: F0001068  adrp     x8, #0x367000
//   0x158128: 91144108  add      x8, x8, #0x510
static inline uint64_t fde_func_0133_0x15811c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15811cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b8cb8ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0134 | PC: 0x158198 | FDE: 0x0b8cd8 | Size: 124 bytes [_ZN4lynx4base20RefCountedStringImpl6Unsafe12kFalseStringEv]
// Khung tháo gỡ #0134 | Địa chỉ PC: 0x158198 | Địa chỉ FDE: 0x0b8cd8 | Kích thước: 124 bytes
//   0x158198: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x15819c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1581a0: F0001068  adrp     x8, #0x367000
//   0x1581a4: 91146108  add      x8, x8, #0x518
static inline uint64_t fde_func_0134_0x158198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x158198ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b8cd8ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0135 | PC: 0x158214 | FDE: 0x0b8cf8 | Size: 112 bytes [_ZN4lynx4base20RefCountedStringImplC1EPKc]
// Khung tháo gỡ #0135 | Địa chỉ PC: 0x158214 | Địa chỉ FDE: 0x0b8cf8 | Kích thước: 112 bytes
//   0x158214: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x158218: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x15821c: AA0003F3  mov      x19, x0
//   0x158220: B4000141  cbz      x1, #0x158248
static inline uint64_t fde_func_0135_0x158214(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x158214ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b8cf8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0136 | PC: 0x158284 | FDE: 0x0b8d18 | Size: 236 bytes [_ZN4lynx4base20RefCountedStringImplC1EPKcm]
// Khung tháo gỡ #0136 | Địa chỉ PC: 0x158284 | Địa chỉ FDE: 0x0b8d18 | Kích thước: 236 bytes
//   0x158284: D10103FF  sub      sp, sp, #0x40
//   0x158288: F9000BF6  str      x22, [sp, #0x10]
//   0x15828c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x158290: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0136_0x158284(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x158284ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x0b8d18ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0137 | PC: 0x158370 | FDE: 0x0b8d38 | Size: 152 bytes [_ZN4lynx4base20RefCountedStringImplC1ENSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE]
// Khung tháo gỡ #0137 | Địa chỉ PC: 0x158370 | Địa chỉ FDE: 0x0b8d38 | Kích thước: 152 bytes
//   0x158370: D10083FF  sub      sp, sp, #0x20
//   0x158374: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x158378: B000104A  adrp     x10, #0x361000
//   0x15837c: F946154A  ldr      x10, [x10, #0xc28]
static inline uint64_t fde_func_0137_0x158370(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x158370ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b8d38ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0138 | PC: 0x158408 | FDE: 0x0b8d50 | Size: 232 bytes [_ZN4lynx4base20RefCountedStringImpl11length_utf8Ev]
// Khung tháo gỡ #0138 | Địa chỉ PC: 0x158408 | Địa chỉ FDE: 0x0b8d50 | Kích thước: 232 bytes
//   0x158408: AA0003E8  mov      x8, x0
//   0x15840c: 38410D09  ldrb     w9, [x8, #0x10]!
//   0x158410: 37000689  tbnz     w9, #0, #0x1584e0
//   0x158414: 91000508  add      x8, x8, #1
static inline uint64_t fde_func_0138_0x158408(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x158408ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0x38410d09ULL) ^ 0x0b8d50ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0139 | PC: 0x1584f0 | FDE: 0x0b8d68 | Size: 132 bytes [_ZN4lynx4base20RefCountedStringImpl12length_utf16Ev]
// Khung tháo gỡ #0139 | Địa chỉ PC: 0x1584f0 | Địa chỉ FDE: 0x0b8d68 | Kích thước: 132 bytes
//   0x1584f0: D10103FF  sub      sp, sp, #0x40
//   0x1584f4: F90013F4  str      x20, [sp, #0x20]
//   0x1584f8: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x1584fc: B9403408  ldr      w8, [x0, #0x34]
static inline uint64_t fde_func_0139_0x1584f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1584f0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f4ULL) ^ 0x0b8d68ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0140 | PC: 0x158574 | FDE: 0x0b8da0 | Size: 148 bytes
// Khung tháo gỡ #0140 | Địa chỉ PC: 0x158574 | Địa chỉ FDE: 0x0b8da0 | Kích thước: 148 bytes
//   0x158574: B4000080  cbz      x0, #0x158584
//   0x158578: F9400008  ldr      x8, [x0]
//   0x15857c: F9400901  ldr      x1, [x8, #0x10]
//   0x158580: D61F0020  br       x1
static inline uint64_t fde_func_0140_0x158574(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x158574ULL ^ (static_cast<uint64_t>(0xb4000080ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x0b8da0ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0141 | PC: 0x158608 | FDE: 0x1489b8 | Size: 248 bytes [__extenddftf2]
// Khung tháo gỡ #0141 | Địa chỉ PC: 0x158608 | Địa chỉ FDE: 0x1489b8 | Kích thước: 248 bytes
//   0x158608: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x15860c: 9E660004  fmov     x4, d0
//   0x158610: 910003FD  mov      x29, sp
//   0x158614: D53B4400  mrs      x0, fpcr
static inline uint64_t fde_func_0141_0x158608(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x158608ULL ^ (static_cast<uint64_t>(0xa9be7bfdULL) << 13);
    acc = (acc + a1 + 0x9e660004ULL) ^ 0x1489b8ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0142 | PC: 0x158700 | FDE: 0x1489e0 | Size: 108 bytes [__sfp_handle_exceptions]
// Khung tháo gỡ #0142 | Địa chỉ PC: 0x158700 | Địa chỉ FDE: 0x1489e0 | Kích thước: 108 bytes
//   0x158700: 36000080  tbz      w0, #0, #0x158710
//   0x158704: 1E2703E1  fmov     s1, wzr
//   0x158708: 1E211820  fdiv     s0, s1, s1
//   0x15870c: D53B4421  mrs      x1, fpsr
static inline uint64_t fde_func_0142_0x158700(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x158700ULL ^ (static_cast<uint64_t>(0x36000080ULL) << 13);
    acc = (acc + a1 + 0x1e2703e1ULL) ^ 0x1489e0ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0143 | PC: 0x15876c | FDE: 0x1489f8 | Size: 140 bytes [__floatditf]
// Khung tháo gỡ #0143 | Địa chỉ PC: 0x15876c | Địa chỉ FDE: 0x1489f8 | Kích thước: 140 bytes
//   0x15876c: B4000300  cbz      x0, #0x1587cc
//   0x158770: D37FFC01  lsr      x1, x0, #0x3f
//   0x158774: D2880DE3  mov      x3, #0x406f
//   0x158778: 6B1F003F  cmp      w1, wzr
static inline uint64_t fde_func_0143_0x15876c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15876cULL ^ (static_cast<uint64_t>(0xb4000300ULL) << 13);
    acc = (acc + a1 + 0xd37ffc01ULL) ^ 0x1489f8ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0144 | PC: 0x1587f8 | FDE: 0x148a10 | Size: 256 bytes [__lttf2]
// Khung tháo gỡ #0144 | Địa chỉ PC: 0x1587f8 | Địa chỉ FDE: 0x148a10 | Kích thước: 256 bytes
//   0x1587f8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1587fc: 9E660000  fmov     x0, d0
//   0x158800: 9EAE0001  fmov     x1, v0.d[1]
//   0x158804: 910003FD  mov      x29, sp
static inline uint64_t fde_func_0144_0x1587f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1587f8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x9e660000ULL) ^ 0x148a10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0145 | PC: 0x158934 | FDE: 0x148a38 | Size: 256 bytes [__multf3]
// Khung tháo gỡ #0145 | Địa chỉ PC: 0x158934 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x158934: 9E660000  fmov     x0, d0
//   0x158938: 9EAE0001  fmov     x1, v0.d[1]
//   0x15893c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x158940: AA0003E3  mov      x3, x0
static inline uint64_t fde_func_0145_0x158934(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x158934ULL ^ (static_cast<uint64_t>(0x9e660000ULL) << 13);
    acc = (acc + a1 + 0x9eae0001ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0146 | PC: 0x159014 | FDE: 0x148a68 | Size: 256 bytes [__subtf3]
// Khung tháo gỡ #0146 | Địa chỉ PC: 0x159014 | Địa chỉ FDE: 0x148a68 | Kích thước: 256 bytes
//   0x159014: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x159018: 9E660000  fmov     x0, d0
//   0x15901c: 9EAE0001  fmov     x1, v0.d[1]
//   0x159020: 910003FD  mov      x29, sp
static inline uint64_t fde_func_0146_0x159014(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x159014ULL ^ (static_cast<uint64_t>(0xa9be7bfdULL) << 13);
    acc = (acc + a1 + 0x9e660000ULL) ^ 0x148a68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0147 | PC: 0x159b38 | FDE: 0x0b8e00 | Size: 96 bytes
// Khung tháo gỡ #0147 | Địa chỉ PC: 0x159b38 | Địa chỉ FDE: 0x0b8e00 | Kích thước: 96 bytes
//   0x159b38: D10183FF  sub      sp, sp, #0x60
//   0x159b3c: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x159b40: A9057BF3  stp      x19, x30, [sp, #0x50]
//   0x159b44: 940741FC  bl       #0x32a334
static inline uint64_t fde_func_0147_0x159b38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x159b38ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90453f5ULL) ^ 0x0b8e00ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0148 | PC: 0x159b98 | FDE: 0x0b8e50 | Size: 256 bytes [_ZN4lynx4tasm8recorder18RecorderController6EnableEv]
// Khung tháo gỡ #0148 | Địa chỉ PC: 0x159b98 | Địa chỉ FDE: 0x0b8e50 | Kích thước: 256 bytes
//   0x159b98: 17FFE353  b        #0x1528e4
//   0x159b9c: 52800083  mov      w3, #4
//   0x159ba0: 1407998C  b        #0x3401d0
//   0x159ba4: AA1E03E2  mov      x2, x30
static inline uint64_t fde_func_0148_0x159b98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x159b98ULL ^ (static_cast<uint64_t>(0x17ffe353ULL) << 13);
    acc = (acc + a1 + 0x52800083ULL) ^ 0x0b8e50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0149 | PC: 0x159d60 | FDE: 0x0b8f18 | Size: 256 bytes
// Khung tháo gỡ #0149 | Địa chỉ PC: 0x159d60 | Địa chỉ FDE: 0x0b8f18 | Kích thước: 256 bytes
//   0x159d60: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x159d64: F0000F48  adrp     x8, #0x344000
//   0x159d68: 910EE108  add      x8, x8, #0x3b8
//   0x159d6c: 940726A6  bl       #0x323804
static inline uint64_t fde_func_0149_0x159d60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x159d60ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf0000f48ULL) ^ 0x0b8f18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0150 | PC: 0x15a0b4 | FDE: 0x0b9038 | Size: 256 bytes
// Khung tháo gỡ #0150 | Địa chỉ PC: 0x15a0b4 | Địa chỉ FDE: 0x0b9038 | Kích thước: 256 bytes
//   0x15a0b4: B40000A1  cbz      x1, #0x15a0c8
//   0x15a0b8: AA0103E8  mov      x8, x1
//   0x15a0bc: 2A0203E1  mov      w1, w2
//   0x15a0c0: AA0803E2  mov      x2, x8
static inline uint64_t fde_func_0150_0x15a0b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15a0b4ULL ^ (static_cast<uint64_t>(0xb40000a1ULL) << 13);
    acc = (acc + a1 + 0xaa0103e8ULL) ^ 0x0b9038ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0151 | PC: 0x15a1f4 | FDE: 0x0b90e8 | Size: 156 bytes [_ZN4lynx4tasm8recorder18RecorderController32GetTestBenchBaseRecorderInstanceEv]
// Khung tháo gỡ #0151 | Địa chỉ PC: 0x15a1f4 | Địa chỉ FDE: 0x0b90e8 | Kích thước: 156 bytes
//   0x15a1f4: 14070AAE  b        #0x31ccac
//   0x15a1f8: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x15a1fc: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x15a200: A90253F5  stp      x21, x20, [sp, #0x20]
static inline uint64_t fde_func_0151_0x15a1f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15a1f4ULL ^ (static_cast<uint64_t>(0x14070aaeULL) << 13);
    acc = (acc + a1 + 0xf81c0ff8ULL) ^ 0x0b90e8ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0152 | PC: 0x15a290 | FDE: 0x0b9140 | Size: 256 bytes
// Khung tháo gỡ #0152 | Địa chỉ PC: 0x15a290 | Địa chỉ FDE: 0x0b9140 | Kích thước: 256 bytes
//   0x15a290: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x15a294: 94071F03  bl       #0x321ea0
//   0x15a298: 940715DF  bl       #0x31fa14
//   0x15a29c: 3100041F  cmn      w0, #1
static inline uint64_t fde_func_0152_0x15a290(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15a290ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94071f03ULL) ^ 0x0b9140ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0153 | PC: 0x15a6c8 | FDE: 0x0b9250 | Size: 256 bytes
// Khung tháo gỡ #0153 | Địa chỉ PC: 0x15a6c8 | Địa chỉ FDE: 0x0b9250 | Kích thước: 256 bytes
//   0x15a6c8: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x15a6cc: 39400008  ldrb     w8, [x0]
//   0x15a6d0: 37000068  tbnz     w8, #0, #0x15a6dc
//   0x15a6d4: D341FD09  lsr      x9, x8, #1
static inline uint64_t fde_func_0153_0x15a6c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15a6c8ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x39400008ULL) ^ 0x0b9250ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0154 | PC: 0x15a934 | FDE: 0x0b9358 | Size: 152 bytes
// Khung tháo gỡ #0154 | Địa chỉ PC: 0x15a934 | Địa chỉ FDE: 0x0b9358 | Kích thước: 152 bytes
//   0x15a934: F9400008  ldr      x8, [x0]
//   0x15a938: F85E8108  ldur     x8, [x8, #-0x18]
//   0x15a93c: 8B080008  add      x8, x0, x8
//   0x15a940: 91004100  add      x0, x8, #0x10
static inline uint64_t fde_func_0154_0x15a934(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15a934ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf85e8108ULL) ^ 0x0b9358ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0155 | PC: 0x15a9cc | FDE: 0x0b9448 | Size: 256 bytes
// Khung tháo gỡ #0155 | Địa chỉ PC: 0x15a9cc | Địa chỉ FDE: 0x0b9448 | Kích thước: 256 bytes
//   0x15a9cc: F9400008  ldr      x8, [x0]
//   0x15a9d0: F85E8108  ldur     x8, [x8, #-0x18]
//   0x15a9d4: 8B080000  add      x0, x0, x8
//   0x15a9d8: 17FFFCE2  b        #0x159d60
static inline uint64_t fde_func_0155_0x15a9cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15a9ccULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf85e8108ULL) ^ 0x0b9448ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0156 | PC: 0x15ab9c | FDE: 0x0b9558 | Size: 256 bytes
// Khung tháo gỡ #0156 | Địa chỉ PC: 0x15ab9c | Địa chỉ FDE: 0x0b9558 | Kích thước: 256 bytes
//   0x15ab9c: D100C3FF  sub      sp, sp, #0x30
//   0x15aba0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x15aba4: AA0803F3  mov      x19, x8
//   0x15aba8: F0001028  adrp     x8, #0x361000
static inline uint64_t fde_func_0156_0x15ab9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15ab9cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9027bf3ULL) ^ 0x0b9558ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0157 | PC: 0x15b184 | FDE: 0x0b9688 | Size: 256 bytes
// Khung tháo gỡ #0157 | Địa chỉ PC: 0x15b184 | Địa chỉ FDE: 0x0b9688 | Kích thước: 256 bytes
//   0x15b184: AA1E03E2  mov      x2, x30
//   0x15b188: 94070360  bl       #0x31bf08
//   0x15b18c: AA0203FE  mov      x30, x2
//   0x15b190: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0157_0x15b184(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15b184ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94070360ULL) ^ 0x0b9688ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0158 | PC: 0x15b748 | FDE: 0x0b97b0 | Size: 256 bytes
// Khung tháo gỡ #0158 | Địa chỉ PC: 0x15b748 | Địa chỉ FDE: 0x0b97b0 | Kích thước: 256 bytes
//   0x15b748: 1407072C  b        #0x31d3f8
//   0x15b74c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x15b750: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x15b754: 94072E81  bl       #0x327158
static inline uint64_t fde_func_0158_0x15b748(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15b748ULL ^ (static_cast<uint64_t>(0x1407072cULL) << 13);
    acc = (acc + a1 + 0xf81e0ff4ULL) ^ 0x0b97b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0159 | PC: 0x15b99c | FDE: 0x0b98c8 | Size: 60 bytes
// Khung tháo gỡ #0159 | Địa chỉ PC: 0x15b99c | Địa chỉ FDE: 0x0b98c8 | Kích thước: 60 bytes
//   0x15b99c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x15b9a0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x15b9a4: 9407133B  bl       #0x320690
//   0x15b9a8: B40000D4  cbz      x20, #0x15b9c0
static inline uint64_t fde_func_0159_0x15b99c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15b99cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b98c8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0160 | PC: 0x15b9d8 | FDE: 0x0b98e8 | Size: 256 bytes [_ZN4lynx6canvas21CanvasRuntimeMediator19CreateModuleFactoryEv]
// Khung tháo gỡ #0160 | Địa chỉ PC: 0x15b9d8 | Địa chỉ FDE: 0x0b98e8 | Kích thước: 256 bytes
//   0x15b9d8: D100C3FF  sub      sp, sp, #0x30
//   0x15b9dc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x15b9e0: AA0803F3  mov      x19, x8
//   0x15b9e4: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0160_0x15b9d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15b9d8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9027bf3ULL) ^ 0x0b98e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0161 | PC: 0x15bd28 | FDE: 0x0b9930 | Size: 256 bytes [_ZN4lynx6canvas21CanvasRuntimeMediator15SetRuntimeActorENSt6__ndk110shared_ptrINS_5shell9LynxActorINS_7runtime11LynxRuntimeEEEEE]
// Khung tháo gỡ #0161 | Địa chỉ PC: 0x15bd28 | Địa chỉ FDE: 0x0b9930 | Kích thước: 256 bytes
//   0x15bd28: D10183FF  sub      sp, sp, #0x60
//   0x15bd2c: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x15bd30: A9057BF3  stp      x19, x30, [sp, #0x50]
//   0x15bd34: 9407061D  bl       #0x31d5a8
static inline uint64_t fde_func_0161_0x15bd28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15bd28ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90453f5ULL) ^ 0x0b9930ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0162 | PC: 0x15bed0 | FDE: 0x0b99e8 | Size: 56 bytes
// Khung tháo gỡ #0162 | Địa chỉ PC: 0x15bed0 | Địa chỉ FDE: 0x0b99e8 | Kích thước: 56 bytes
//   0x15bed0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x15bed4: 94076A1E  bl       #0x33674c
//   0x15bed8: 2A1303E1  mov      w1, w19
//   0x15bedc: A8C17BF3  ldp      x19, x30, [sp], #0x10
static inline uint64_t fde_func_0162_0x15bed0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15bed0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94076a1eULL) ^ 0x0b99e8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0163 | PC: 0x15bf08 | FDE: 0x0b9a30 | Size: 256 bytes [_ZN4lynx6canvas21CanvasRuntimeMediator29NotifyCanvasInitializeSuccessEv]
// Khung tháo gỡ #0163 | Địa chỉ PC: 0x15bf08 | Địa chỉ FDE: 0x0b9a30 | Kích thước: 256 bytes
//   0x15bf08: D10203FF  sub      sp, sp, #0x80
//   0x15bf0c: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x15bf10: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x15bf14: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0163_0x15bf08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15bf08ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9055bf7ULL) ^ 0x0b9a30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0164 | PC: 0x15c10c | FDE: 0x0b9af0 | Size: 172 bytes
// Khung tháo gỡ #0164 | Địa chỉ PC: 0x15c10c | Địa chỉ FDE: 0x0b9af0 | Kích thước: 172 bytes
//   0x15c10c: F9400C08  ldr      x8, [x0, #0x18]
//   0x15c110: 90000F49  adrp     x9, #0x344000
//   0x15c114: 91182129  add      x9, x9, #0x608
//   0x15c118: 14070322  b        #0x31cda0
static inline uint64_t fde_func_0164_0x15c10c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15c10cULL ^ (static_cast<uint64_t>(0xf9400c08ULL) << 13);
    acc = (acc + a1 + 0x90000f49ULL) ^ 0x0b9af0ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0165 | PC: 0x15c1b8 | FDE: 0x0b9bc8 | Size: 16 bytes [_ZN4lynx6canvas21CanvasRuntimeMediator9MarkReadyEv]
// Khung tháo gỡ #0165 | Địa chỉ PC: 0x15c1b8 | Địa chỉ FDE: 0x0b9bc8 | Kích thước: 16 bytes
//   0x15c1b8: F9400008  ldr      x8, [x0]
//   0x15c1bc: 52800029  mov      w9, #1
//   0x15c1c0: 3900A009  strb     w9, [x0, #0x28]
//   0x15c1c4: 1407840D  b        #0x33d1f8
static inline uint64_t fde_func_0165_0x15c1b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15c1b8ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0x52800029ULL) ^ 0x0b9bc8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0166 | PC: 0x15c1c8 | FDE: 0x0b9be0 | Size: 256 bytes
// Khung tháo gỡ #0166 | Địa chỉ PC: 0x15c1c8 | Địa chỉ FDE: 0x0b9be0 | Kích thước: 256 bytes
//   0x15c1c8: D101C3FF  sub      sp, sp, #0x70
//   0x15c1cc: F90023F6  str      x22, [sp, #0x40]
//   0x15c1d0: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x15c1d4: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_0166_0x15c1c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15c1c8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f6ULL) ^ 0x0b9be0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0167 | PC: 0x15c418 | FDE: 0x0b9ce0 | Size: 256 bytes
// Khung tháo gỡ #0167 | Địa chỉ PC: 0x15c418 | Địa chỉ FDE: 0x0b9ce0 | Kích thước: 256 bytes
//   0x15c418: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x15c41c: AA0003F3  mov      x19, x0
//   0x15c420: 97FFFFE5  bl       #0x15c3b4
//   0x15c424: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0167_0x15c418(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15c418ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0b9ce0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0168 | PC: 0x15ca34 | FDE: 0x0b9e28 | Size: 256 bytes
// Khung tháo gỡ #0168 | Địa chỉ PC: 0x15ca34 | Địa chỉ FDE: 0x0b9e28 | Kích thước: 256 bytes
//   0x15ca34: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x15ca38: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x15ca3c: F9400440  ldr      x0, [x2, #8]
//   0x15ca40: B4000120  cbz      x0, #0x15ca64
static inline uint64_t fde_func_0168_0x15ca34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15ca34ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0b9e28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0169 | PC: 0x15cdf0 | FDE: 0x0b9f68 | Size: 256 bytes
// Khung tháo gỡ #0169 | Địa chỉ PC: 0x15cdf0 | Địa chỉ FDE: 0x0b9f68 | Kích thước: 256 bytes
//   0x15cdf0: D10203FF  sub      sp, sp, #0x80
//   0x15cdf4: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x15cdf8: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x15cdfc: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0169_0x15cdf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15cdf0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9055bf7ULL) ^ 0x0b9f68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0170 | PC: 0x15d1b0 | FDE: 0x0ba098 | Size: 256 bytes
// Khung tháo gỡ #0170 | Địa chỉ PC: 0x15d1b0 | Địa chỉ FDE: 0x0ba098 | Kích thước: 256 bytes
//   0x15d1b0: D101C3FF  sub      sp, sp, #0x70
//   0x15d1b4: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x15d1b8: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x15d1bc: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0170_0x15d1b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15d1b0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90553f5ULL) ^ 0x0ba098ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0171 | PC: 0x15d61c | FDE: 0x0ba1c8 | Size: 256 bytes
// Khung tháo gỡ #0171 | Địa chỉ PC: 0x15d61c | Địa chỉ FDE: 0x0ba1c8 | Kích thước: 256 bytes
//   0x15d61c: 39404008  ldrb     w8, [x0, #0x10]
//   0x15d620: 34000048  cbz      w8, #0x15d628
//   0x15d624: 14078C2F  b        #0x3406e0
//   0x15d628: D65F03C0  ret      
static inline uint64_t fde_func_0171_0x15d61c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15d61cULL ^ (static_cast<uint64_t>(0x39404008ULL) << 13);
    acc = (acc + a1 + 0x34000048ULL) ^ 0x0ba1c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0172 | PC: 0x15dadc | FDE: 0x0ba2e0 | Size: 256 bytes
// Khung tháo gỡ #0172 | Địa chỉ PC: 0x15dadc | Địa chỉ FDE: 0x0ba2e0 | Kích thước: 256 bytes
//   0x15dadc: AA0003E8  mov      x8, x0
//   0x15dae0: 38440D09  ldrb     w9, [x8, #0x40]!
//   0x15dae4: 37000049  tbnz     w9, #0, #0x15daec
//   0x15dae8: 14074E06  b        #0x331300
static inline uint64_t fde_func_0172_0x15dadc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15dadcULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0x38440d09ULL) ^ 0x0ba2e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0173 | PC: 0x15de9c | FDE: 0x0ba420 | Size: 256 bytes
// Khung tháo gỡ #0173 | Địa chỉ PC: 0x15de9c | Địa chỉ FDE: 0x0ba420 | Kích thước: 256 bytes
//   0x15de9c: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x15dea0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x15dea4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x15dea8: B100407F  cmn      x3, #0x10
static inline uint64_t fde_func_0173_0x15de9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15de9cULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0ba420ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0174 | PC: 0x15e558 | FDE: 0x0ba560 | Size: 256 bytes
// Khung tháo gỡ #0174 | Địa chỉ PC: 0x15e558 | Địa chỉ FDE: 0x0ba560 | Kích thước: 256 bytes
//   0x15e558: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x15e55c: AA0003F3  mov      x19, x0
//   0x15e560: 9100C000  add      x0, x0, #0x30
//   0x15e564: 97FFED87  bl       #0x159b80
static inline uint64_t fde_func_0174_0x15e558(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15e558ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0ba560ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0175 | PC: 0x15e8f0 | FDE: 0x0ba690 | Size: 256 bytes
// Khung tháo gỡ #0175 | Địa chỉ PC: 0x15e8f0 | Địa chỉ FDE: 0x0ba690 | Kích thước: 256 bytes
//   0x15e8f0: 1406F8F8  b        #0x31ccd0
//   0x15e8f4: AA1E03E2  mov      x2, x30
//   0x15e8f8: 9406F971  bl       #0x31cebc
//   0x15e8fc: AA0203FE  mov      x30, x2
static inline uint64_t fde_func_0175_0x15e8f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15e8f0ULL ^ (static_cast<uint64_t>(0x1406f8f8ULL) << 13);
    acc = (acc + a1 + 0xaa1e03e2ULL) ^ 0x0ba690ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0176 | PC: 0x15eebc | FDE: 0x0ba7b8 | Size: 256 bytes
// Khung tháo gỡ #0176 | Địa chỉ PC: 0x15eebc | Địa chỉ FDE: 0x0ba7b8 | Kích thước: 256 bytes
//   0x15eebc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x15eec0: AA0003F3  mov      x19, x0
//   0x15eec4: 97FFFFFA  bl       #0x15eeac
//   0x15eec8: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0176_0x15eebc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15eebcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0ba7b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0177 | PC: 0x15f614 | FDE: 0x0ba8e8 | Size: 256 bytes
// Khung tháo gỡ #0177 | Địa chỉ PC: 0x15f614 | Địa chỉ FDE: 0x0ba8e8 | Kích thước: 256 bytes
//   0x15f614: D10143FF  sub      sp, sp, #0x50
//   0x15f618: F90013F6  str      x22, [sp, #0x20]
//   0x15f61c: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x15f620: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0177_0x15f614(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15f614ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x0ba8e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0178 | PC: 0x15fbd8 | FDE: 0x0baa28 | Size: 256 bytes
// Khung tháo gỡ #0178 | Địa chỉ PC: 0x15fbd8 | Địa chỉ FDE: 0x0baa28 | Kích thước: 256 bytes
//   0x15fbd8: EB01001F  cmp      x0, x1
//   0x15fbdc: 540000A0  b.eq     #0x15fbf0
//   0x15fbe0: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x15fbe4: 94072211  bl       #0x328428
static inline uint64_t fde_func_0178_0x15fbd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15fbd8ULL ^ (static_cast<uint64_t>(0xeb01001fULL) << 13);
    acc = (acc + a1 + 0x540000a0ULL) ^ 0x0baa28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0179 | PC: 0x160108 | FDE: 0x0bab48 | Size: 256 bytes
// Khung tháo gỡ #0179 | Địa chỉ PC: 0x160108 | Địa chỉ FDE: 0x0bab48 | Kích thước: 256 bytes
//   0x160108: D10183FF  sub      sp, sp, #0x60
//   0x16010c: F9001BF6  str      x22, [sp, #0x30]
//   0x160110: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x160114: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0179_0x160108(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x160108ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf6ULL) ^ 0x0bab48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0180 | PC: 0x1602ec | FDE: 0x0bac50 | Size: 256 bytes
// Khung tháo gỡ #0180 | Địa chỉ PC: 0x1602ec | Địa chỉ FDE: 0x0bac50 | Kích thước: 256 bytes
//   0x1602ec: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1602f0: B201F3E8  mov      x8, #-0x5555555555555556
//   0x1602f4: F2E15548  movk     x8, #0xaaa, lsl #48
//   0x1602f8: EB08003F  cmp      x1, x8
static inline uint64_t fde_func_0180_0x1602ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1602ecULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb201f3e8ULL) ^ 0x0bac50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0181 | PC: 0x1605dc | FDE: 0x0bad70 | Size: 256 bytes
// Khung tháo gỡ #0181 | Địa chỉ PC: 0x1605dc | Địa chỉ FDE: 0x0bad70 | Kích thước: 256 bytes
//   0x1605dc: D10183FF  sub      sp, sp, #0x60
//   0x1605e0: FD000BE8  str      d8, [sp, #0x10]
//   0x1605e4: F9000FFA  str      x26, [sp, #0x18]
//   0x1605e8: A90263F9  stp      x25, x24, [sp, #0x20]
static inline uint64_t fde_func_0181_0x1605dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1605dcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xfd000be8ULL) ^ 0x0bad70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0182 | PC: 0x1614dc | FDE: 0x0baeb0 | Size: 256 bytes
// Khung tháo gỡ #0182 | Địa chỉ PC: 0x1614dc | Địa chỉ FDE: 0x0baeb0 | Kích thước: 256 bytes
//   0x1614dc: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1614e0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1614e4: AA0003F4  mov      x20, x0
//   0x1614e8: F9402000  ldr      x0, [x0, #0x40]
static inline uint64_t fde_func_0182_0x1614dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1614dcULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0baeb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0183 | PC: 0x1624b8 | FDE: 0x0bafd0 | Size: 256 bytes
// Khung tháo gỡ #0183 | Địa chỉ PC: 0x1624b8 | Địa chỉ FDE: 0x0bafd0 | Kích thước: 256 bytes
//   0x1624b8: D100C3FF  sub      sp, sp, #0x30
//   0x1624bc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1624c0: D53BD053  mrs      x19, tpidr_el0
//   0x1624c4: F9401668  ldr      x8, [x19, #0x28]
static inline uint64_t fde_func_0183_0x1624b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1624b8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9027bf3ULL) ^ 0x0bafd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0184 | PC: 0x162fa0 | FDE: 0x0bb110 | Size: 256 bytes
// Khung tháo gỡ #0184 | Địa chỉ PC: 0x162fa0 | Địa chỉ FDE: 0x0bb110 | Kích thước: 256 bytes
//   0x162fa0: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x162fa4: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x162fa8: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x162fac: AA0203F3  mov      x19, x2
static inline uint64_t fde_func_0184_0x162fa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x162fa0ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0bb110ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0185 | PC: 0x1634a4 | FDE: 0x0bb240 | Size: 256 bytes
// Khung tháo gỡ #0185 | Địa chỉ PC: 0x1634a4 | Địa chỉ FDE: 0x0bb240 | Kích thước: 256 bytes
//   0x1634a4: D10483FF  sub      sp, sp, #0x120
//   0x1634a8: F90083FC  str      x28, [sp, #0x100]
//   0x1634ac: A9117BF3  stp      x19, x30, [sp, #0x110]
//   0x1634b0: 9406E2C3  bl       #0x31bfbc
static inline uint64_t fde_func_0185_0x1634a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1634a4ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x0bb240ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0186 | PC: 0x1638d4 | FDE: 0x0bb360 | Size: 256 bytes
// Khung tháo gỡ #0186 | Địa chỉ PC: 0x1638d4 | Địa chỉ FDE: 0x0bb360 | Kích thước: 256 bytes
//   0x1638d4: 91034000  add      x0, x0, #0xd0
//   0x1638d8: 14000136  b        #0x163db0
//   0x1638dc: AA1E03E5  mov      x5, x30
//   0x1638e0: 9406EB2B  bl       #0x31e58c
static inline uint64_t fde_func_0186_0x1638d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1638d4ULL ^ (static_cast<uint64_t>(0x91034000ULL) << 13);
    acc = (acc + a1 + 0x14000136ULL) ^ 0x0bb360ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0187 | PC: 0x163d5c | FDE: 0x0bb470 | Size: 256 bytes
// Khung tháo gỡ #0187 | Địa chỉ PC: 0x163d5c | Địa chỉ FDE: 0x0bb470 | Kích thước: 256 bytes
//   0x163d5c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x163d60: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x163d64: 94070E83  bl       #0x327770
//   0x163d68: EB15029F  cmp      x20, x21
static inline uint64_t fde_func_0187_0x163d5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x163d5cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0bb470ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0188 | PC: 0x163ffc | FDE: 0x0bb580 | Size: 256 bytes
// Khung tháo gỡ #0188 | Địa chỉ PC: 0x163ffc | Địa chỉ FDE: 0x0bb580 | Kích thước: 256 bytes
//   0x163ffc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x164000: 9406E6E0  bl       #0x31db80
//   0x164004: 90000F08  adrp     x8, #0x344000
//   0x164008: 912B4108  add      x8, x8, #0xad0
static inline uint64_t fde_func_0188_0x163ffc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x163ffcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9406e6e0ULL) ^ 0x0bb580ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0189 | PC: 0x1641a8 | FDE: 0x0bb690 | Size: 256 bytes
// Khung tháo gỡ #0189 | Địa chỉ PC: 0x1641a8 | Địa chỉ FDE: 0x0bb690 | Kích thước: 256 bytes
//   0x1641a8: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1641ac: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1641b0: 94070D70  bl       #0x327770
//   0x1641b4: EB15029F  cmp      x20, x21
static inline uint64_t fde_func_0189_0x1641a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1641a8ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0bb690ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0190 | PC: 0x164408 | FDE: 0x0bb7a0 | Size: 256 bytes
// Khung tháo gỡ #0190 | Địa chỉ PC: 0x164408 | Địa chỉ FDE: 0x0bb7a0 | Kích thước: 256 bytes
//   0x164408: AA0003E8  mov      x8, x0
//   0x16440c: F9400000  ldr      x0, [x0]
//   0x164410: B4000040  cbz      x0, #0x164418
//   0x164414: 1406EF0C  b        #0x320044
static inline uint64_t fde_func_0190_0x164408(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x164408ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xf9400000ULL) ^ 0x0bb7a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0191 | PC: 0x164508 | FDE: 0x0bb898 | Size: 256 bytes
// Khung tháo gỡ #0191 | Địa chỉ PC: 0x164508 | Địa chỉ FDE: 0x0bb898 | Kích thước: 256 bytes
//   0x164508: D10403FF  sub      sp, sp, #0x100
//   0x16450c: F9005BFA  str      x26, [sp, #0xb0]
//   0x164510: A90C63F9  stp      x25, x24, [sp, #0xc0]
//   0x164514: A90D5BF7  stp      x23, x22, [sp, #0xd0]
static inline uint64_t fde_func_0191_0x164508(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x164508ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xf9005bfaULL) ^ 0x0bb898ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0192 | PC: 0x164b58 | FDE: 0x0bb9b8 | Size: 256 bytes
// Khung tháo gỡ #0192 | Địa chỉ PC: 0x164b58 | Địa chỉ FDE: 0x0bb9b8 | Kích thước: 256 bytes
//   0x164b58: D10103FF  sub      sp, sp, #0x40
//   0x164b5c: F9000BF6  str      x22, [sp, #0x10]
//   0x164b60: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x164b64: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0192_0x164b58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x164b58ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x0bb9b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0193 | PC: 0x164d74 | FDE: 0x0bbac8 | Size: 256 bytes
// Khung tháo gỡ #0193 | Địa chỉ PC: 0x164d74 | Địa chỉ FDE: 0x0bbac8 | Kích thước: 256 bytes
//   0x164d74: 14076E17  b        #0x3405d0
//   0x164d78: D10103FF  sub      sp, sp, #0x40
//   0x164d7c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x164d80: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0193_0x164d74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x164d74ULL ^ (static_cast<uint64_t>(0x14076e17ULL) << 13);
    acc = (acc + a1 + 0xd10103ffULL) ^ 0x0bbac8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0194 | PC: 0x1665a4 | FDE: 0x0bbbe8 | Size: 256 bytes
// Khung tháo gỡ #0194 | Địa chỉ PC: 0x1665a4 | Địa chỉ FDE: 0x0bbbe8 | Kích thước: 256 bytes
//   0x1665a4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1665a8: AA0003F3  mov      x19, x0
//   0x1665ac: 94070304  bl       #0x3271bc
//   0x1665b0: 9406D6D9  bl       #0x31c114
static inline uint64_t fde_func_0194_0x1665a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1665a4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0bbbe8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0195 | PC: 0x166a98 | FDE: 0x0bbd00 | Size: 256 bytes
// Khung tháo gỡ #0195 | Địa chỉ PC: 0x166a98 | Địa chỉ FDE: 0x0bbd00 | Kích thước: 256 bytes
//   0x166a98: 1406D6AF  b        #0x31c554
//   0x166a9c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x166aa0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x166aa4: 9406DACB  bl       #0x31d5d0
static inline uint64_t fde_func_0195_0x166a98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x166a98ULL ^ (static_cast<uint64_t>(0x1406d6afULL) << 13);
    acc = (acc + a1 + 0xa9be53f5ULL) ^ 0x0bbd00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0196 | PC: 0x166e64 | FDE: 0x0bbe18 | Size: 256 bytes
// Khung tháo gỡ #0196 | Địa chỉ PC: 0x166e64 | Địa chỉ FDE: 0x0bbe18 | Kích thước: 256 bytes
//   0x166e64: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x166e68: AA0003F3  mov      x19, x0
//   0x166e6c: 97FFFFDB  bl       #0x166dd8
//   0x166e70: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0196_0x166e64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x166e64ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0bbe18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0197 | PC: 0x167030 | FDE: 0x0bbf20 | Size: 256 bytes
// Khung tháo gỡ #0197 | Địa chỉ PC: 0x167030 | Địa chỉ FDE: 0x0bbf20 | Kích thước: 256 bytes
//   0x167030: D10643FF  sub      sp, sp, #0x190
//   0x167034: FD0093E8  str      d8, [sp, #0x120]
//   0x167038: A9136FFC  stp      x28, x27, [sp, #0x130]
//   0x16703c: A91467FA  stp      x26, x25, [sp, #0x140]
static inline uint64_t fde_func_0197_0x167030(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x167030ULL ^ (static_cast<uint64_t>(0xd10643ffULL) << 13);
    acc = (acc + a1 + 0xfd0093e8ULL) ^ 0x0bbf20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0198 | PC: 0x16819c | FDE: 0x0bc048 | Size: 256 bytes
// Khung tháo gỡ #0198 | Địa chỉ PC: 0x16819c | Địa chỉ FDE: 0x0bc048 | Kích thước: 256 bytes
//   0x16819c: AA1E03E2  mov      x2, x30
//   0x1681a0: 9406F867  bl       #0x32633c
//   0x1681a4: AA0203FE  mov      x30, x2
//   0x1681a8: A90A7BF3  stp      x19, x30, [sp, #0xa0]
static inline uint64_t fde_func_0198_0x16819c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16819cULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9406f867ULL) ^ 0x0bc048ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0199 | PC: 0x16845c | FDE: 0x0bc160 | Size: 256 bytes
// Khung tháo gỡ #0199 | Địa chỉ PC: 0x16845c | Địa chỉ FDE: 0x0bc160 | Kích thước: 256 bytes
//   0x16845c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x168460: 9406D2A8  bl       #0x31cf00
//   0x168464: B40000B3  cbz      x19, #0x168478
//   0x168468: 9406FAC3  bl       #0x326f74
static inline uint64_t fde_func_0199_0x16845c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16845cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9406d2a8ULL) ^ 0x0bc160ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0200 | PC: 0x168a8c | FDE: 0x0bc2a8 | Size: 256 bytes
// Khung tháo gỡ #0200 | Địa chỉ PC: 0x168a8c | Địa chỉ FDE: 0x0bc2a8 | Kích thước: 256 bytes
//   0x168a8c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x168a90: 9406FE48  bl       #0x3283b0
//   0x168a94: 97FFFE7B  bl       #0x168480
//   0x168a98: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0200_0x168a8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x168a8cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9406fe48ULL) ^ 0x0bc2a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0201 | PC: 0x168c84 | FDE: 0x0bc3d0 | Size: 256 bytes
// Khung tháo gỡ #0201 | Địa chỉ PC: 0x168c84 | Địa chỉ FDE: 0x0bc3d0 | Kích thước: 256 bytes
//   0x168c84: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x168c88: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x168c8c: 9406CEC3  bl       #0x31c798
//   0x168c90: 94075EE4  bl       #0x340820
static inline uint64_t fde_func_0201_0x168c84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x168c84ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0bc3d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0202 | PC: 0x168ec8 | FDE: 0x0bc4e8 | Size: 256 bytes
// Khung tháo gỡ #0202 | Địa chỉ PC: 0x168ec8 | Địa chỉ FDE: 0x0bc4e8 | Kích thước: 256 bytes
//   0x168ec8: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x168ecc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x168ed0: 94071947  bl       #0x32f3ec
//   0x168ed4: B40000F5  cbz      x21, #0x168ef0
static inline uint64_t fde_func_0202_0x168ec8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x168ec8ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0bc4e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0203 | PC: 0x169228 | FDE: 0x0bc620 | Size: 256 bytes
// Khung tháo gỡ #0203 | Địa chỉ PC: 0x169228 | Địa chỉ FDE: 0x0bc620 | Kích thước: 256 bytes
//   0x169228: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x16922c: 9406F000  bl       #0x32522c
//   0x169230: 97FFFFBD  bl       #0x169124
//   0x169234: B9000A7F  str      wzr, [x19, #8]
static inline uint64_t fde_func_0203_0x169228(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x169228ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9406f000ULL) ^ 0x0bc620ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0204 | PC: 0x1695cc | FDE: 0x0bc730 | Size: 256 bytes
// Khung tháo gỡ #0204 | Địa chỉ PC: 0x1695cc | Địa chỉ FDE: 0x0bc730 | Kích thước: 256 bytes
//   0x1695cc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1695d0: AA0003F3  mov      x19, x0
//   0x1695d4: 97FFFFF6  bl       #0x1695ac
//   0x1695d8: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0204_0x1695cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1695ccULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0bc730ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0205 | PC: 0x1698c0 | FDE: 0x0bc858 | Size: 256 bytes
// Khung tháo gỡ #0205 | Địa chỉ PC: 0x1698c0 | Địa chỉ FDE: 0x0bc858 | Kích thước: 256 bytes
//   0x1698c0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1698c4: AA0003F3  mov      x19, x0
//   0x1698c8: 97FFFFF5  bl       #0x16989c
//   0x1698cc: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0205_0x1698c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1698c0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0bc858ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0206 | PC: 0x169a2c | FDE: 0x0bc958 | Size: 256 bytes
// Khung tháo gỡ #0206 | Địa chỉ PC: 0x169a2c | Địa chỉ FDE: 0x0bc958 | Kích thước: 256 bytes
//   0x169a2c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x169a30: EB00003F  cmp      x1, x0
//   0x169a34: 1A9F17E9  cset     w9, eq
//   0x169a38: AA0003E8  mov      x8, x0
static inline uint64_t fde_func_0206_0x169a2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x169a2cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xeb00003fULL) ^ 0x0bc958ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0207 | PC: 0x169ee8 | FDE: 0x0bca70 | Size: 256 bytes
// Khung tháo gỡ #0207 | Địa chỉ PC: 0x169ee8 | Địa chỉ FDE: 0x0bca70 | Kích thước: 256 bytes
//   0x169ee8: D10083FF  sub      sp, sp, #0x20
//   0x169eec: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x169ef0: 9406CBC9  bl       #0x31ce14
//   0x169ef4: B50000E0  cbnz     x0, #0x169f10
static inline uint64_t fde_func_0207_0x169ee8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x169ee8ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0bca70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0208 | PC: 0x16a174 | FDE: 0x0bcb90 | Size: 256 bytes
// Khung tháo gỡ #0208 | Địa chỉ PC: 0x16a174 | Địa chỉ FDE: 0x0bcb90 | Kích thước: 256 bytes
//   0x16a174: AA1F03E2  mov      x2, xzr
//   0x16a178: 14000001  b        #0x16a17c
//   0x16a17c: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x16a180: A90153F5  stp      x21, x20, [sp, #0x10]
static inline uint64_t fde_func_0208_0x16a174(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16a174ULL ^ (static_cast<uint64_t>(0xaa1f03e2ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x0bcb90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0209 | PC: 0x16a4c8 | FDE: 0x0bccb0 | Size: 256 bytes
// Khung tháo gỡ #0209 | Địa chỉ PC: 0x16a4c8 | Địa chỉ FDE: 0x0bccb0 | Kích thước: 256 bytes
//   0x16a4c8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x16a4cc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x16a4d0: D1004013  sub      x19, x0, #0x10
//   0x16a4d4: D37CEC34  lsl      x20, x1, #4
static inline uint64_t fde_func_0209_0x16a4c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16a4c8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0bccb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0210 | PC: 0x16a71c | FDE: 0x0bcdb8 | Size: 256 bytes
// Khung tháo gỡ #0210 | Địa chỉ PC: 0x16a71c | Địa chỉ FDE: 0x0bcdb8 | Kích thước: 256 bytes
//   0x16a71c: AA1E03E5  mov      x5, x30
//   0x16a720: 9406E0B5  bl       #0x3229f4
//   0x16a724: AA0503FE  mov      x30, x5
//   0x16a728: A9167BFD  stp      x29, x30, [sp, #0x160]
static inline uint64_t fde_func_0210_0x16a71c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16a71cULL ^ (static_cast<uint64_t>(0xaa1e03e5ULL) << 13);
    acc = (acc + a1 + 0x9406e0b5ULL) ^ 0x0bcdb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0211 | PC: 0x16ac00 | FDE: 0x0bcef0 | Size: 256 bytes
// Khung tháo gỡ #0211 | Địa chỉ PC: 0x16ac00 | Địa chỉ FDE: 0x0bcef0 | Kích thước: 256 bytes
//   0x16ac00: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x16ac04: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x16ac08: 940708C9  bl       #0x32cf2c
//   0x16ac0c: 54000262  b.hs     #0x16ac58
static inline uint64_t fde_func_0211_0x16ac00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16ac00ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0bcef0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0212 | PC: 0x16b310 | FDE: 0x0bd010 | Size: 256 bytes
// Khung tháo gỡ #0212 | Địa chỉ PC: 0x16b310 | Địa chỉ FDE: 0x0bd010 | Kích thước: 256 bytes
//   0x16b310: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x16b314: AA0003F3  mov      x19, x0
//   0x16b318: 97FFFFFA  bl       #0x16b300
//   0x16b31c: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0212_0x16b310(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16b310ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0bd010ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0213 | PC: 0x16b9e4 | FDE: 0x0bd120 | Size: 256 bytes
// Khung tháo gỡ #0213 | Địa chỉ PC: 0x16b9e4 | Địa chỉ FDE: 0x0bd120 | Kích thước: 256 bytes
//   0x16b9e4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x16b9e8: 910023E1  add      x1, sp, #8
//   0x16b9ec: F90007FF  str      xzr, [sp, #8]
//   0x16b9f0: 940000C9  bl       #0x16bd14
static inline uint64_t fde_func_0213_0x16b9e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16b9e4ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x910023e1ULL) ^ 0x0bd120ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0214 | PC: 0x16bda8 | FDE: 0x0bd240 | Size: 256 bytes
// Khung tháo gỡ #0214 | Địa chỉ PC: 0x16bda8 | Địa chỉ FDE: 0x0bd240 | Kích thước: 256 bytes
//   0x16bda8: F9400001  ldr      x1, [x0]
//   0x16bdac: 14000001  b        #0x16bdb0
//   0x16bdb0: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x16bdb4: A9017BF3  stp      x19, x30, [sp, #0x10]
static inline uint64_t fde_func_0214_0x16bda8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16bda8ULL ^ (static_cast<uint64_t>(0xf9400001ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x0bd240ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0215 | PC: 0x16c610 | FDE: 0x0bd378 | Size: 256 bytes
// Khung tháo gỡ #0215 | Địa chỉ PC: 0x16c610 | Địa chỉ FDE: 0x0bd378 | Kích thước: 256 bytes
//   0x16c610: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x16c614: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x16c618: F9401414  ldr      x20, [x0, #0x28]
//   0x16c61c: 90000EC8  adrp     x8, #0x344000
static inline uint64_t fde_func_0215_0x16c610(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16c610ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0bd378ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0216 | PC: 0x16c8fc | FDE: 0x0bd488 | Size: 256 bytes
// Khung tháo gỡ #0216 | Địa chỉ PC: 0x16c8fc | Địa chỉ FDE: 0x0bd488 | Kích thước: 256 bytes
//   0x16c8fc: D100C3FF  sub      sp, sp, #0x30
//   0x16c900: F9000BF4  str      x20, [sp, #0x10]
//   0x16c904: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x16c908: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0216_0x16c8fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16c8fcULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x0bd488ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0217 | PC: 0x16cf70 | FDE: 0x0bd5d0 | Size: 256 bytes
// Khung tháo gỡ #0217 | Địa chỉ PC: 0x16cf70 | Địa chỉ FDE: 0x0bd5d0 | Kích thước: 256 bytes
//   0x16cf70: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x16cf74: 90000EC8  adrp     x8, #0x344000
//   0x16cf78: 913E4108  add      x8, x8, #0xf90
//   0x16cf7c: 9406BDF9  bl       #0x31c760
static inline uint64_t fde_func_0217_0x16cf70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16cf70ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x90000ec8ULL) ^ 0x0bd5d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0218 | PC: 0x16d098 | FDE: 0x0bd6c0 | Size: 256 bytes
// Khung tháo gỡ #0218 | Địa chỉ PC: 0x16d098 | Địa chỉ FDE: 0x0bd6c0 | Kích thước: 256 bytes
//   0x16d098: D101C3FF  sub      sp, sp, #0x70
//   0x16d09c: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x16d0a0: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x16d0a4: 9406BE59  bl       #0x31ca08
static inline uint64_t fde_func_0218_0x16d098(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16d098ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90553f5ULL) ^ 0x0bd6c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0219 | PC: 0x16d478 | FDE: 0x0bd7d8 | Size: 256 bytes
// Khung tháo gỡ #0219 | Địa chỉ PC: 0x16d478 | Địa chỉ FDE: 0x0bd7d8 | Kích thước: 256 bytes
//   0x16d478: AA0003E8  mov      x8, x0
//   0x16d47c: F9400400  ldr      x0, [x0, #8]
//   0x16d480: 90000EC9  adrp     x9, #0x345000
//   0x16d484: 91024129  add      x9, x9, #0x90
static inline uint64_t fde_func_0219_0x16d478(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16d478ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xf9400400ULL) ^ 0x0bd7d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0220 | PC: 0x16d764 | FDE: 0x0bd8e8 | Size: 256 bytes
// Khung tháo gỡ #0220 | Địa chỉ PC: 0x16d764 | Địa chỉ FDE: 0x0bd8e8 | Kích thước: 256 bytes
//   0x16d764: 6DBB2BEB  stp      d11, d10, [sp, #-0x50]!
//   0x16d768: 6D0123E9  stp      d9, d8, [sp, #0x10]
//   0x16d76c: F90013F6  str      x22, [sp, #0x20]
//   0x16d770: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0220_0x16d764(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16d764ULL ^ (static_cast<uint64_t>(0x6dbb2bebULL) << 13);
    acc = (acc + a1 + 0x6d0123e9ULL) ^ 0x0bd8e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0221 | PC: 0x16ddac | FDE: 0x0bda08 | Size: 256 bytes
// Khung tháo gỡ #0221 | Địa chỉ PC: 0x16ddac | Địa chỉ FDE: 0x0bda08 | Kích thước: 256 bytes
//   0x16ddac: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x16ddb0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x16ddb4: AA0003F3  mov      x19, x0
//   0x16ddb8: 52801700  mov      w0, #0xb8
static inline uint64_t fde_func_0221_0x16ddac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16ddacULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0bda08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0222 | PC: 0x16e588 | FDE: 0x0bdb48 | Size: 256 bytes
// Khung tháo gỡ #0222 | Địa chỉ PC: 0x16e588 | Địa chỉ FDE: 0x0bdb48 | Kích thước: 256 bytes
//   0x16e588: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x16e58c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x16e590: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x16e594: 9406B746  bl       #0x31c2ac
static inline uint64_t fde_func_0222_0x16e588(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16e588ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0bdb48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0223 | PC: 0x16e9e4 | FDE: 0x0bdc68 | Size: 256 bytes
// Khung tháo gỡ #0223 | Địa chỉ PC: 0x16e9e4 | Địa chỉ FDE: 0x0bdc68 | Kích thước: 256 bytes
//   0x16e9e4: D10083FF  sub      sp, sp, #0x20
//   0x16e9e8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x16e9ec: 9406C454  bl       #0x31fb3c
//   0x16e9f0: 940015B0  bl       #0x1740b0
static inline uint64_t fde_func_0223_0x16e9e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16e9e4ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0bdc68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0224 | PC: 0x16ed58 | FDE: 0x0bdd88 | Size: 256 bytes
// Khung tháo gỡ #0224 | Địa chỉ PC: 0x16ed58 | Địa chỉ FDE: 0x0bdd88 | Kích thước: 256 bytes
//   0x16ed58: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x16ed5c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x16ed60: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x16ed64: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0224_0x16ed58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16ed58ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0bdd88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0225 | PC: 0x16f374 | FDE: 0x0bdec8 | Size: 256 bytes
// Khung tháo gỡ #0225 | Địa chỉ PC: 0x16f374 | Địa chỉ FDE: 0x0bdec8 | Kích thước: 256 bytes
//   0x16f374: B8408428  ldr      w8, [x1], #8
//   0x16f378: B8008408  str      w8, [x0], #8
//   0x16f37c: 14000001  b        #0x16f380
//   0x16f380: F81D0FF6  str      x22, [sp, #-0x30]!
static inline uint64_t fde_func_0225_0x16f374(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16f374ULL ^ (static_cast<uint64_t>(0xb8408428ULL) << 13);
    acc = (acc + a1 + 0xb8008408ULL) ^ 0x0bdec8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0226 | PC: 0x16f66c | FDE: 0x0bdfe8 | Size: 256 bytes
// Khung tháo gỡ #0226 | Địa chỉ PC: 0x16f66c | Địa chỉ FDE: 0x0bdfe8 | Kích thước: 256 bytes
//   0x16f66c: AA1F03E1  mov      x1, xzr
//   0x16f670: 17FFFFF5  b        #0x16f644
//   0x16f674: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x16f678: A9017BF3  stp      x19, x30, [sp, #0x10]
static inline uint64_t fde_func_0226_0x16f66c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16f66cULL ^ (static_cast<uint64_t>(0xaa1f03e1ULL) << 13);
    acc = (acc + a1 + 0x17fffff5ULL) ^ 0x0bdfe8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0227 | PC: 0x16fd1c | FDE: 0x0be130 | Size: 256 bytes
// Khung tháo gỡ #0227 | Địa chỉ PC: 0x16fd1c | Địa chỉ FDE: 0x0be130 | Kích thước: 256 bytes
//   0x16fd1c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x16fd20: AA0003F3  mov      x19, x0
//   0x16fd24: 9400A9AD  bl       #0x19a3d8
//   0x16fd28: D0000F89  adrp     x9, #0x361000
static inline uint64_t fde_func_0227_0x16fd1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16fd1cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0be130ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0228 | PC: 0x16fefc | FDE: 0x0be248 | Size: 256 bytes
// Khung tháo gỡ #0228 | Địa chỉ PC: 0x16fefc | Địa chỉ FDE: 0x0be248 | Kích thước: 256 bytes
//   0x16fefc: AA1E03E3  mov      x3, x30
//   0x16ff00: 9406B1D9  bl       #0x31c664
//   0x16ff04: AA0303FE  mov      x30, x3
//   0x16ff08: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0228_0x16fefc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16fefcULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x9406b1d9ULL) ^ 0x0be248ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0229 | PC: 0x1704c0 | FDE: 0x0be378 | Size: 256 bytes
// Khung tháo gỡ #0229 | Địa chỉ PC: 0x1704c0 | Địa chỉ FDE: 0x0be378 | Kích thước: 256 bytes
//   0x1704c0: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1704c4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1704c8: 9406C0DF  bl       #0x320844
//   0x1704cc: 54000100  b.eq     #0x1704ec
static inline uint64_t fde_func_0229_0x1704c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1704c0ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0be378ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0230 | PC: 0x170f50 | FDE: 0x0be4b0 | Size: 256 bytes
// Khung tháo gỡ #0230 | Địa chỉ PC: 0x170f50 | Địa chỉ FDE: 0x0be4b0 | Kích thước: 256 bytes
//   0x170f50: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x170f54: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x170f58: 8B020448  add      x8, x2, x2, lsl #1
//   0x170f5c: 9406C6BD  bl       #0x322a50
static inline uint64_t fde_func_0230_0x170f50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170f50ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0be4b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0231 | PC: 0x17156c | FDE: 0x0be5e8 | Size: 256 bytes
// Khung tháo gỡ #0231 | Địa chỉ PC: 0x17156c | Địa chỉ FDE: 0x0be5e8 | Kích thước: 256 bytes
//   0x17156c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x171570: AA0003F3  mov      x19, x0
//   0x171574: 97FFFFF6  bl       #0x17154c
//   0x171578: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0231_0x17156c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17156cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0be5e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0232 | PC: 0x171780 | FDE: 0x0be6f0 | Size: 256 bytes
// Khung tháo gỡ #0232 | Địa chỉ PC: 0x171780 | Địa chỉ FDE: 0x0be6f0 | Kích thước: 256 bytes
//   0x171780: B40001A2  cbz      x2, #0x1717b4
//   0x171784: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x171788: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x17178c: A9027BF3  stp      x19, x30, [sp, #0x20]
static inline uint64_t fde_func_0232_0x171780(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171780ULL ^ (static_cast<uint64_t>(0xb40001a2ULL) << 13);
    acc = (acc + a1 + 0xf81d0ff6ULL) ^ 0x0be6f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0233 | PC: 0x171e34 | FDE: 0x0be818 | Size: 256 bytes
// Khung tháo gỡ #0233 | Địa chỉ PC: 0x171e34 | Địa chỉ FDE: 0x0be818 | Kích thước: 256 bytes
//   0x171e34: AA1E03E2  mov      x2, x30
//   0x171e38: 9406C7BB  bl       #0x323d24
//   0x171e3c: AA0203FE  mov      x30, x2
//   0x171e40: A90F7BFD  stp      x29, x30, [sp, #0xf0]
static inline uint64_t fde_func_0233_0x171e34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171e34ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9406c7bbULL) ^ 0x0be818ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0234 | PC: 0x1725f8 | FDE: 0x0be948 | Size: 256 bytes
// Khung tháo gỡ #0234 | Địa chỉ PC: 0x1725f8 | Địa chỉ FDE: 0x0be948 | Kích thước: 256 bytes
//   0x1725f8: AA1E03E3  mov      x3, x30
//   0x1725fc: 940705D2  bl       #0x333d44
//   0x172600: AA0303FE  mov      x30, x3
//   0x172604: A91B7BF3  stp      x19, x30, [sp, #0x1b0]
static inline uint64_t fde_func_0234_0x1725f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1725f8ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x940705d2ULL) ^ 0x0be948ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0235 | PC: 0x172dd4 | FDE: 0x0bea70 | Size: 256 bytes
// Khung tháo gỡ #0235 | Địa chỉ PC: 0x172dd4 | Địa chỉ FDE: 0x0bea70 | Kích thước: 256 bytes
//   0x172dd4: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x172dd8: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x172ddc: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x172de0: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0235_0x172dd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x172dd4ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0bea70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0236 | PC: 0x173038 | FDE: 0x0beb80 | Size: 256 bytes
// Khung tháo gỡ #0236 | Địa chỉ PC: 0x173038 | Địa chỉ FDE: 0x0beb80 | Kích thước: 256 bytes
//   0x173038: AA0003E8  mov      x8, x0
//   0x17303c: F9401800  ldr      x0, [x0, #0x30]
//   0x173040: B40000C0  cbz      x0, #0x173058
//   0x173044: F9400009  ldr      x9, [x0]
static inline uint64_t fde_func_0236_0x173038(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x173038ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xf9401800ULL) ^ 0x0beb80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0237 | PC: 0x17356c | FDE: 0x0beca8 | Size: 256 bytes
// Khung tháo gỡ #0237 | Địa chỉ PC: 0x17356c | Địa chỉ FDE: 0x0beca8 | Kích thước: 256 bytes
//   0x17356c: D10143FF  sub      sp, sp, #0x50
//   0x173570: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x173574: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x173578: 9406AFAB  bl       #0x31f424
static inline uint64_t fde_func_0237_0x17356c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17356cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90353f5ULL) ^ 0x0beca8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0238 | PC: 0x173914 | FDE: 0x0bedc8 | Size: 256 bytes
// Khung tháo gỡ #0238 | Địa chỉ PC: 0x173914 | Địa chỉ FDE: 0x0bedc8 | Kích thước: 256 bytes
//   0x173914: D101C3FF  sub      sp, sp, #0x70
//   0x173918: F9002BF4  str      x20, [sp, #0x50]
//   0x17391c: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x173920: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0238_0x173914(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x173914ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x0bedc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0239 | PC: 0x173cf8 | FDE: 0x0beef0 | Size: 256 bytes
// Khung tháo gỡ #0239 | Địa chỉ PC: 0x173cf8 | Địa chỉ FDE: 0x0beef0 | Kích thước: 256 bytes
//   0x173cf8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x173cfc: 9406E1A9  bl       #0x32c3a0
//   0x173d00: AA1303E0  mov      x0, x19
//   0x173d04: A8C17BF3  ldp      x19, x30, [sp], #0x10
static inline uint64_t fde_func_0239_0x173cf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x173cf8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9406e1a9ULL) ^ 0x0beef0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0240 | PC: 0x174380 | FDE: 0x0bf048 | Size: 256 bytes
// Khung tháo gỡ #0240 | Địa chỉ PC: 0x174380 | Địa chỉ FDE: 0x0bf048 | Kích thước: 256 bytes
//   0x174380: D10203FF  sub      sp, sp, #0x80
//   0x174384: 6D013BEF  stp      d15, d14, [sp, #0x10]
//   0x174388: 6D0233ED  stp      d13, d12, [sp, #0x20]
//   0x17438c: 6D032BEB  stp      d11, d10, [sp, #0x30]
static inline uint64_t fde_func_0240_0x174380(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x174380ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0x6d013befULL) ^ 0x0bf048ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0241 | PC: 0x174a1c | FDE: 0x0bf1b0 | Size: 256 bytes
// Khung tháo gỡ #0241 | Địa chỉ PC: 0x174a1c | Địa chỉ FDE: 0x0bf1b0 | Kích thước: 256 bytes
//   0x174a1c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x174a20: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x174a24: F9400008  ldr      x8, [x0]
//   0x174a28: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0241_0x174a1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x174a1cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0bf1b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0242 | PC: 0x174f7c | FDE: 0x0bf2f0 | Size: 256 bytes
// Khung tháo gỡ #0242 | Địa chỉ PC: 0x174f7c | Địa chỉ FDE: 0x0bf2f0 | Kích thước: 256 bytes
//   0x174f7c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x174f80: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x174f84: AA0003F5  mov      x21, x0
//   0x174f88: 52800D00  mov      w0, #0x68
static inline uint64_t fde_func_0242_0x174f7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x174f7cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0bf2f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0243 | PC: 0x1759a8 | FDE: 0x0bf430 | Size: 256 bytes [_ZN4lynx4base8UIThread9GetRunnerEb]
// Khung tháo gỡ #0243 | Địa chỉ PC: 0x1759a8 | Địa chỉ FDE: 0x0bf430 | Kích thước: 256 bytes
//   0x1759a8: D101C3FF  sub      sp, sp, #0x70
//   0x1759ac: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x1759b0: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x1759b4: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0243_0x1759a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1759a8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90553f5ULL) ^ 0x0bf430ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0244 | PC: 0x175c38 | FDE: 0x0bf528 | Size: 256 bytes
// Khung tháo gỡ #0244 | Địa chỉ PC: 0x175c38 | Địa chỉ FDE: 0x0bf528 | Kích thước: 256 bytes
//   0x175c38: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x175c3c: AA0003F3  mov      x19, x0
//   0x175c40: 97FFFFFA  bl       #0x175c28
//   0x175c44: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0244_0x175c38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175c38ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0bf528ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0245 | PC: 0x17622c | FDE: 0x0bf640 | Size: 256 bytes
// Khung tháo gỡ #0245 | Địa chỉ PC: 0x17622c | Địa chỉ FDE: 0x0bf640 | Kích thước: 256 bytes
//   0x17622c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x176230: 90000FA8  adrp     x8, #0x36a000
//   0x176234: 911CA108  add      x8, x8, #0x728
//   0x176238: 08DFFD08  ldarb    w8, [x8]
static inline uint64_t fde_func_0245_0x17622c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17622cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x90000fa8ULL) ^ 0x0bf640ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0246 | PC: 0x17699c | FDE: 0x0bf770 | Size: 144 bytes
// Khung tháo gỡ #0246 | Địa chỉ PC: 0x17699c | Địa chỉ FDE: 0x0bf770 | Kích thước: 144 bytes
//   0x17699c: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x1769a0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1769a4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1769a8: 91002016  add      x22, x0, #8
static inline uint64_t fde_func_0246_0x17699c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17699cULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0bf770ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0247 | PC: 0x176a2c | FDE: 0x0bf7a8 | Size: 256 bytes [_ZN4lynx4base20TaskRunnerManufactor11GetJSRunnerERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE]
// Khung tháo gỡ #0247 | Địa chỉ PC: 0x176a2c | Địa chỉ FDE: 0x0bf7a8 | Kích thước: 256 bytes
//   0x176a2c: D10243FF  sub      sp, sp, #0x90
//   0x176a30: F90033F6  str      x22, [sp, #0x60]
//   0x176a34: A90753F5  stp      x21, x20, [sp, #0x70]
//   0x176a38: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_0247_0x176a2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176a2cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90033f6ULL) ^ 0x0bf7a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0248 | PC: 0x176c38 | FDE: 0x0bf7f8 | Size: 36 bytes [_ZN4lynx4base20TaskRunnerManufactor17GetTASMTaskRunnerEv]
// Khung tháo gỡ #0248 | Địa chỉ PC: 0x176c38 | Địa chỉ FDE: 0x0bf7f8 | Kích thước: 36 bytes
//   0x176c38: F9400409  ldr      x9, [x0, #8]
//   0x176c3c: F9000109  str      x9, [x8]
//   0x176c40: B40000C9  cbz      x9, #0x176c58
//   0x176c44: 91002128  add      x8, x9, #8
static inline uint64_t fde_func_0248_0x176c38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176c38ULL ^ (static_cast<uint64_t>(0xf9400409ULL) << 13);
    acc = (acc + a1 + 0xf9000109ULL) ^ 0x0bf7f8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0249 | PC: 0x176c5c | FDE: 0x0bf810 | Size: 36 bytes [_ZN4lynx4base20TaskRunnerManufactor15GetUITaskRunnerEv]
// Khung tháo gỡ #0249 | Địa chỉ PC: 0x176c5c | Địa chỉ FDE: 0x0bf810 | Kích thước: 36 bytes
//   0x176c5c: F9400C09  ldr      x9, [x0, #0x18]
//   0x176c60: F9000109  str      x9, [x8]
//   0x176c64: B40000C9  cbz      x9, #0x176c7c
//   0x176c68: 91002128  add      x8, x9, #8
static inline uint64_t fde_func_0249_0x176c5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176c5cULL ^ (static_cast<uint64_t>(0xf9400c09ULL) << 13);
    acc = (acc + a1 + 0xf9000109ULL) ^ 0x0bf810ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0250 | PC: 0x176c80 | FDE: 0x0bf828 | Size: 256 bytes [_ZN4lynx4base20TaskRunnerManufactor15GetJSTaskRunnerEv]
// Khung tháo gỡ #0250 | Địa chỉ PC: 0x176c80 | Địa chỉ FDE: 0x0bf828 | Kích thước: 256 bytes
//   0x176c80: F9401009  ldr      x9, [x0, #0x20]
//   0x176c84: F9000109  str      x9, [x8]
//   0x176c88: B40000C9  cbz      x9, #0x176ca0
//   0x176c8c: 91002128  add      x8, x9, #8
static inline uint64_t fde_func_0250_0x176c80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176c80ULL ^ (static_cast<uint64_t>(0xf9401009ULL) << 13);
    acc = (acc + a1 + 0xf9000109ULL) ^ 0x0bf828ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0251 | PC: 0x176ef4 | FDE: 0x0bf880 | Size: 256 bytes
// Khung tháo gỡ #0251 | Địa chỉ PC: 0x176ef4 | Địa chỉ FDE: 0x0bf880 | Kích thước: 256 bytes
//   0x176ef4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x176ef8: 52800020  mov      w0, #1
//   0x176efc: 97FFFF7E  bl       #0x176cf4
//   0x176f00: F84107FE  ldr      x30, [sp], #0x10
static inline uint64_t fde_func_0251_0x176ef4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176ef4ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x52800020ULL) ^ 0x0bf880ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0252 | PC: 0x1771cc | FDE: 0x0bf988 | Size: 256 bytes
// Khung tháo gỡ #0252 | Địa chỉ PC: 0x1771cc | Địa chỉ FDE: 0x0bf988 | Kích thước: 256 bytes
//   0x1771cc: D10143FF  sub      sp, sp, #0x50
//   0x1771d0: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x1771d4: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x1771d8: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0252_0x1771cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1771ccULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x0bf988ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0253 | PC: 0x177454 | FDE: 0x0bfaa8 | Size: 256 bytes
// Khung tháo gỡ #0253 | Địa chỉ PC: 0x177454 | Địa chỉ FDE: 0x0bfaa8 | Kích thước: 256 bytes
//   0x177454: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x177458: 940720CE  bl       #0x33f790
//   0x17745c: 94069666  bl       #0x31cdf4
//   0x177460: B4000060  cbz      x0, #0x17746c
static inline uint64_t fde_func_0253_0x177454(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177454ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x940720ceULL) ^ 0x0bfaa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0254 | PC: 0x1777fc | FDE: 0x0bfb78 | Size: 256 bytes [_ZN4lynx4base7android14CheckExceptionEP7_JNIEnv]
// Khung tháo gỡ #0254 | Địa chỉ PC: 0x1777fc | Địa chỉ FDE: 0x0bfb78 | Kích thước: 256 bytes
//   0x1777fc: AA1E03E1  mov      x1, x30
//   0x177800: 9406E24A  bl       #0x330128
//   0x177804: AA0103FE  mov      x30, x1
//   0x177808: A9127BF3  stp      x19, x30, [sp, #0x120]
static inline uint64_t fde_func_0254_0x1777fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1777fcULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x9406e24aULL) ^ 0x0bfb78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0255 | PC: 0x177b6c | FDE: 0x0bfbe8 | Size: 204 bytes [_ZN4lynx4base7android20CallStackUtilAndroid22GetMessageOfCauseChainEP7_JNIEnvRKNS1_18ScopedLocalJavaRefIP11_jthrowableEE]
// Khung tháo gỡ #0255 | Địa chỉ PC: 0x177b6c | Địa chỉ FDE: 0x0bfbe8 | Kích thước: 204 bytes
//   0x177b6c: D10143FF  sub      sp, sp, #0x50
//   0x177b70: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x177b74: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x177b78: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0255_0x177b6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177b6cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x0bfbe8ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #0256 | PC: 0x177c38 | FDE: 0x0bfc08 | Size: 256 bytes [_ZN4lynx4base7android20CallStackUtilAndroid34GetStackTraceStringWithLineTrimmedEP7_JNIEnvRKNS1_18ScopedLocalJavaRefIP11_jthrowableEE]
// Khung tháo gỡ #0256 | Địa chỉ PC: 0x177c38 | Địa chỉ FDE: 0x0bfc08 | Kích thước: 256 bytes
//   0x177c38: D10143FF  sub      sp, sp, #0x50
//   0x177c3c: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x177c40: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x177c44: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0256_0x177c38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177c38ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x0bfc08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0257 | PC: 0x178440 | FDE: 0x0bfd30 | Size: 256 bytes
// Khung tháo gỡ #0257 | Địa chỉ PC: 0x178440 | Địa chỉ FDE: 0x0bfd30 | Kích thước: 256 bytes
//   0x178440: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x178444: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x178448: 9406B682  bl       #0x325e50
//   0x17844c: 9406D193  bl       #0x32ca98
static inline uint64_t fde_func_0257_0x178440(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178440ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0bfd30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0258 | PC: 0x178698 | FDE: 0x0bfe60 | Size: 256 bytes
// Khung tháo gỡ #0258 | Địa chỉ PC: 0x178698 | Địa chỉ FDE: 0x0bfe60 | Kích thước: 256 bytes
//   0x178698: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x17869c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1786a0: 9406A4DE  bl       #0x321a18
//   0x1786a4: D0000F85  adrp     x5, #0x36a000
static inline uint64_t fde_func_0258_0x178698(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178698ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0bfe60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0259 | PC: 0x178a20 | FDE: 0x0bff80 | Size: 256 bytes
// Khung tháo gỡ #0259 | Địa chỉ PC: 0x178a20 | Địa chỉ FDE: 0x0bff80 | Kích thước: 256 bytes
//   0x178a20: D10483FF  sub      sp, sp, #0x120
//   0x178a24: F90083FC  str      x28, [sp, #0x100]
//   0x178a28: A9117BF3  stp      x19, x30, [sp, #0x110]
//   0x178a2c: 94068D64  bl       #0x31bfbc
static inline uint64_t fde_func_0259_0x178a20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178a20ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x0bff80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0260 | PC: 0x178e34 | FDE: 0x0c00c0 | Size: 256 bytes
// Khung tháo gỡ #0260 | Địa chỉ PC: 0x178e34 | Địa chỉ FDE: 0x0c00c0 | Kích thước: 256 bytes
//   0x178e34: D10183FF  sub      sp, sp, #0x60
//   0x178e38: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x178e3c: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x178e40: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0260_0x178e34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178e34ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9035bf7ULL) ^ 0x0c00c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0261 | PC: 0x179058 | FDE: 0x0c01d8 | Size: 256 bytes
// Khung tháo gỡ #0261 | Địa chỉ PC: 0x179058 | Địa chỉ FDE: 0x0c01d8 | Kích thước: 256 bytes
//   0x179058: 39400028  ldrb     w8, [x1]
//   0x17905c: F9400829  ldr      x9, [x1, #0x10]
//   0x179060: 3940004A  ldrb     w10, [x2]
//   0x179064: F940084B  ldr      x11, [x2, #0x10]
static inline uint64_t fde_func_0261_0x179058(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179058ULL ^ (static_cast<uint64_t>(0x39400028ULL) << 13);
    acc = (acc + a1 + 0xf9400829ULL) ^ 0x0c01d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0262 | PC: 0x1794e4 | FDE: 0x0c0310 | Size: 256 bytes
// Khung tháo gỡ #0262 | Địa chỉ PC: 0x1794e4 | Địa chỉ FDE: 0x0c0310 | Kích thước: 256 bytes
//   0x1794e4: D10143FF  sub      sp, sp, #0x50
//   0x1794e8: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x1794ec: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x1794f0: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0262_0x1794e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1794e4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x0c0310ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0263 | PC: 0x179980 | FDE: 0x0c0450 | Size: 256 bytes
// Khung tháo gỡ #0263 | Địa chỉ PC: 0x179980 | Địa chỉ FDE: 0x0c0450 | Kích thước: 256 bytes
//   0x179980: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x179984: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x179988: 9406B1BD  bl       #0x32607c
//   0x17998c: F84984A1  ldr      x1, [x5], #0x98
static inline uint64_t fde_func_0263_0x179980(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179980ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c0450ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0264 | PC: 0x179f64 | FDE: 0x0c0590 | Size: 256 bytes
// Khung tháo gỡ #0264 | Địa chỉ PC: 0x179f64 | Địa chỉ FDE: 0x0c0590 | Kích thước: 256 bytes
//   0x179f64: AA0103E0  mov      x0, x1
//   0x179f68: 17FF8C55  b        #0x15d0bc
//   0x179f6c: F9400420  ldr      x0, [x1, #8]
//   0x179f70: 17FF83E9  b        #0x15af14
static inline uint64_t fde_func_0264_0x179f64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x179f64ULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0x17ff8c55ULL) ^ 0x0c0590ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0265 | PC: 0x17a100 | FDE: 0x0c0698 | Size: 256 bytes
// Khung tháo gỡ #0265 | Địa chỉ PC: 0x17a100 | Địa chỉ FDE: 0x0c0698 | Kích thước: 256 bytes
//   0x17a100: D10203FF  sub      sp, sp, #0x80
//   0x17a104: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x17a108: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x17a10c: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0265_0x17a100(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a100ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9055bf7ULL) ^ 0x0c0698ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0266 | PC: 0x17a36c | FDE: 0x0c07a0 | Size: 256 bytes
// Khung tháo gỡ #0266 | Địa chỉ PC: 0x17a36c | Địa chỉ FDE: 0x0c07a0 | Kích thước: 256 bytes
//   0x17a36c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x17a370: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x17a374: 94068830  bl       #0x31c434
//   0x17a378: 97FFF8B4  bl       #0x178648
static inline uint64_t fde_func_0266_0x17a36c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a36cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c07a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0267 | PC: 0x17a524 | FDE: 0x0c08a8 | Size: 256 bytes
// Khung tháo gỡ #0267 | Địa chỉ PC: 0x17a524 | Địa chỉ FDE: 0x0c08a8 | Kích thước: 256 bytes
//   0x17a524: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x17a528: 9406E1AA  bl       #0x332bd0
//   0x17a52c: D0000E48  adrp     x8, #0x344000
//   0x17a530: 910A2108  add      x8, x8, #0x288
static inline uint64_t fde_func_0267_0x17a524(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a524ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9406e1aaULL) ^ 0x0c08a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0268 | PC: 0x17a8bc | FDE: 0x0c09c8 | Size: 256 bytes
// Khung tháo gỡ #0268 | Địa chỉ PC: 0x17a8bc | Địa chỉ FDE: 0x0c09c8 | Kích thước: 256 bytes
//   0x17a8bc: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x17a8c0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x17a8c4: F9400415  ldr      x21, [x0, #8]
//   0x17a8c8: 940687E5  bl       #0x31c85c
static inline uint64_t fde_func_0268_0x17a8bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a8bcULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c09c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0269 | PC: 0x17adcc | FDE: 0x0c0ae8 | Size: 256 bytes
// Khung tháo gỡ #0269 | Địa chỉ PC: 0x17adcc | Địa chỉ FDE: 0x0c0ae8 | Kích thước: 256 bytes
//   0x17adcc: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x17add0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x17add4: 9406969C  bl       #0x320844
//   0x17add8: 540000A0  b.eq     #0x17adec
static inline uint64_t fde_func_0269_0x17adcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17adccULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c0ae8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0270 | PC: 0x17b240 | FDE: 0x0c0c20 | Size: 256 bytes
// Khung tháo gỡ #0270 | Địa chỉ PC: 0x17b240 | Địa chỉ FDE: 0x0c0c20 | Kích thước: 256 bytes
//   0x17b240: D101C3FF  sub      sp, sp, #0x70
//   0x17b244: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x17b248: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x17b24c: 940696A9  bl       #0x320cf0
static inline uint64_t fde_func_0270_0x17b240(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b240ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90553f5ULL) ^ 0x0c0c20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0271 | PC: 0x17b648 | FDE: 0x100030 | Size: 256 bytes
// Khung tháo gỡ #0271 | Địa chỉ PC: 0x17b648 | Địa chỉ FDE: 0x100030 | Kích thước: 256 bytes
//   0x17b648: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x17b64c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x17b650: B0000F94  adrp     x20, #0x36c000
//   0x17b654: AA1F03F3  mov      x19, xzr
static inline uint64_t fde_func_0271_0x17b648(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b648ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x100030ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0272 | PC: 0x17b7c8 | FDE: 0x0c0c70 | Size: 256 bytes [_ZN4lynx4base6ToJsonERKN9rapidjson12GenericValueINS1_4UTF8IcEENS1_19MemoryPoolAllocatorINS1_12CrtAllocatorEEEEE]
// Khung tháo gỡ #0272 | Địa chỉ PC: 0x17b7c8 | Địa chỉ FDE: 0x0c0c70 | Kích thước: 256 bytes
//   0x17b7c8: D10283FF  sub      sp, sp, #0xa0
//   0x17b7cc: A90853F5  stp      x21, x20, [sp, #0x80]
//   0x17b7d0: A9097BF3  stp      x19, x30, [sp, #0x90]
//   0x17b7d4: 94069CE9  bl       #0x322b78
static inline uint64_t fde_func_0272_0x17b7c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b7c8ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa90853f5ULL) ^ 0x0c0c70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0273 | PC: 0x17ca18 | FDE: 0x0c0d98 | Size: 256 bytes
// Khung tháo gỡ #0273 | Địa chỉ PC: 0x17ca18 | Địa chỉ FDE: 0x0c0d98 | Kích thước: 256 bytes
//   0x17ca18: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x17ca1c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x17ca20: A941A408  ldp      x8, x9, [x0, #0x18]
//   0x17ca24: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0273_0x17ca18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ca18ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c0d98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0274 | PC: 0x17ce1c | FDE: 0x0c0e50 | Size: 68 bytes [_ZN4lynx4base9strToJsonEPKc]
// Khung tháo gỡ #0274 | Địa chỉ PC: 0x17ce1c | Địa chỉ FDE: 0x0c0e50 | Kích thước: 68 bytes
//   0x17ce1c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x17ce20: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x17ce24: 9406C902  bl       #0x32f22c
//   0x17ce28: AA0803F4  mov      x20, x8
static inline uint64_t fde_func_0274_0x17ce1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ce1cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c0e50ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0275 | PC: 0x17ce60 | FDE: 0x0c0e70 | Size: 36 bytes [_ZN4lynx4base12ObserverList11AddObserverEPNS0_8ObserverE]
// Khung tháo gỡ #0275 | Địa chỉ PC: 0x17ce60 | Địa chỉ FDE: 0x0c0e70 | Kích thước: 36 bytes
//   0x17ce60: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x17ce64: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x17ce68: AA0003F4  mov      x20, x0
//   0x17ce6c: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_0275_0x17ce60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ce60ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c0e70ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0276 | PC: 0x17ce84 | FDE: 0x0c0e90 | Size: 200 bytes [_ZN4lynx4base12ObserverList14RemoveObserverEPNS0_8ObserverE]
// Khung tháo gỡ #0276 | Địa chỉ PC: 0x17ce84 | Địa chỉ FDE: 0x0c0e90 | Kích thước: 200 bytes
//   0x17ce84: D10143FF  sub      sp, sp, #0x50
//   0x17ce88: F90013F6  str      x22, [sp, #0x20]
//   0x17ce8c: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x17ce90: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0276_0x17ce84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ce84ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x0c0e90ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0277 | PC: 0x17cf4c | FDE: 0x0c0eb0 | Size: 76 bytes
// Khung tháo gỡ #0277 | Địa chỉ PC: 0x17cf4c | Địa chỉ FDE: 0x0c0eb0 | Kích thước: 76 bytes
//   0x17cf4c: EB04007F  cmp      x3, x4
//   0x17cf50: 54000220  b.eq     #0x17cf94
//   0x17cf54: F9400088  ldr      x8, [x4]
//   0x17cf58: EB02001F  cmp      x0, x2
static inline uint64_t fde_func_0277_0x17cf4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17cf4cULL ^ (static_cast<uint64_t>(0xeb04007fULL) << 13);
    acc = (acc + a1 + 0x54000220ULL) ^ 0x0c0eb0ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0278 | PC: 0x17cf98 | FDE: 0x0c0ec8 | Size: 256 bytes [_ZN4lynx4base12ObserverList15ForEachObserverEv]
// Khung tháo gỡ #0278 | Địa chỉ PC: 0x17cf98 | Địa chỉ FDE: 0x0c0ec8 | Kích thước: 256 bytes
//   0x17cf98: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x17cf9c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x17cfa0: 94069855  bl       #0x3230f4
//   0x17cfa4: EB00027F  cmp      x19, x0
static inline uint64_t fde_func_0278_0x17cf98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17cf98ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c0ec8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0279 | PC: 0x17d2a8 | FDE: 0x0c0fd0 | Size: 256 bytes
// Khung tháo gỡ #0279 | Địa chỉ PC: 0x17d2a8 | Địa chỉ FDE: 0x0c0fd0 | Kích thước: 256 bytes
//   0x17d2a8: B4000040  cbz      x0, #0x17d2b0
//   0x17d2ac: 14000002  b        #0x17d2b4
//   0x17d2b0: D65F03C0  ret      
//   0x17d2b4: 885F7C08  ldxr     w8, [x0]
static inline uint64_t fde_func_0279_0x17d2a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d2a8ULL ^ (static_cast<uint64_t>(0xb4000040ULL) << 13);
    acc = (acc + a1 + 0x14000002ULL) ^ 0x0c0fd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0280 | PC: 0x17dcd0 | FDE: 0x0c1118 | Size: 256 bytes
// Khung tháo gỡ #0280 | Địa chỉ PC: 0x17dcd0 | Địa chỉ FDE: 0x0c1118 | Kích thước: 256 bytes
//   0x17dcd0: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x17dcd4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x17dcd8: 9406847F  bl       #0x31eed4
//   0x17dcdc: 54000360  b.eq     #0x17dd48
static inline uint64_t fde_func_0280_0x17dcd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17dcd0ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c1118ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0281 | PC: 0x17dff8 | FDE: 0x0c1248 | Size: 256 bytes
// Khung tháo gỡ #0281 | Địa chỉ PC: 0x17dff8 | Địa chỉ FDE: 0x0c1248 | Kích thước: 256 bytes
//   0x17dff8: AA1E03E2  mov      x2, x30
//   0x17dffc: 94069A14  bl       #0x32484c
//   0x17e000: AA0203FE  mov      x30, x2
//   0x17e004: 54000042  b.hs     #0x17e00c
static inline uint64_t fde_func_0281_0x17dff8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17dff8ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94069a14ULL) ^ 0x0c1248ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0282 | PC: 0x17e5d0 | FDE: 0x0c1370 | Size: 256 bytes
// Khung tháo gỡ #0282 | Địa chỉ PC: 0x17e5d0 | Địa chỉ FDE: 0x0c1370 | Kích thước: 256 bytes
//   0x17e5d0: AA1E03E3  mov      x3, x30
//   0x17e5d4: 9406AE78  bl       #0x329fb4
//   0x17e5d8: AA0303FE  mov      x30, x3
//   0x17e5dc: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0282_0x17e5d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17e5d0ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x9406ae78ULL) ^ 0x0c1370ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0283 | PC: 0x17f138 | FDE: 0x0c14b8 | Size: 256 bytes
// Khung tháo gỡ #0283 | Địa chỉ PC: 0x17f138 | Địa chỉ FDE: 0x0c14b8 | Kích thước: 256 bytes
//   0x17f138: 8B021028  add      x8, x1, x2, lsl #4
//   0x17f13c: EB08003F  cmp      x1, x8
//   0x17f140: 540001C0  b.eq     #0x17f178
//   0x17f144: F9400029  ldr      x9, [x1]
static inline uint64_t fde_func_0283_0x17f138(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17f138ULL ^ (static_cast<uint64_t>(0x8b021028ULL) << 13);
    acc = (acc + a1 + 0xeb08003fULL) ^ 0x0c14b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0284 | PC: 0x17fa4c | FDE: 0x0c1608 | Size: 256 bytes
// Khung tháo gỡ #0284 | Địa chỉ PC: 0x17fa4c | Địa chỉ FDE: 0x0c1608 | Kích thước: 256 bytes
//   0x17fa4c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x17fa50: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x17fa54: F9400008  ldr      x8, [x0]
//   0x17fa58: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0284_0x17fa4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17fa4cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c1608ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0285 | PC: 0x180550 | FDE: 0x0c1748 | Size: 256 bytes
// Khung tháo gỡ #0285 | Địa chỉ PC: 0x180550 | Địa chỉ FDE: 0x0c1748 | Kích thước: 256 bytes
//   0x180550: 6DBB33ED  stp      d13, d12, [sp, #-0x50]!
//   0x180554: 6D012BEB  stp      d11, d10, [sp, #0x10]
//   0x180558: 6D0223E9  stp      d9, d8, [sp, #0x20]
//   0x18055c: F9001BF4  str      x20, [sp, #0x30]
static inline uint64_t fde_func_0285_0x180550(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x180550ULL ^ (static_cast<uint64_t>(0x6dbb33edULL) << 13);
    acc = (acc + a1 + 0x6d012bebULL) ^ 0x0c1748ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0286 | PC: 0x1813e0 | FDE: 0x0c18a0 | Size: 256 bytes
// Khung tháo gỡ #0286 | Địa chỉ PC: 0x1813e0 | Địa chỉ FDE: 0x0c18a0 | Kích thước: 256 bytes
//   0x1813e0: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x1813e4: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1813e8: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1813ec: B4000181  cbz      x1, #0x18141c
static inline uint64_t fde_func_0286_0x1813e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1813e0ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0c18a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0287 | PC: 0x18175c | FDE: 0x0c19c0 | Size: 256 bytes
// Khung tháo gỡ #0287 | Địa chỉ PC: 0x18175c | Địa chỉ FDE: 0x0c19c0 | Kích thước: 256 bytes
//   0x18175c: EB03003F  cmp      x1, x3
//   0x181760: 54000328  b.hi     #0x1817c4
//   0x181764: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x181768: A9015BF7  stp      x23, x22, [sp, #0x10]
static inline uint64_t fde_func_0287_0x18175c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18175cULL ^ (static_cast<uint64_t>(0xeb03003fULL) << 13);
    acc = (acc + a1 + 0x54000328ULL) ^ 0x0c19c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0288 | PC: 0x181944 | FDE: 0x0c1ad8 | Size: 256 bytes
// Khung tháo gỡ #0288 | Địa chỉ PC: 0x181944 | Địa chỉ FDE: 0x0c1ad8 | Kích thước: 256 bytes
//   0x181944: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x181948: AA0003F3  mov      x19, x0
//   0x18194c: 97FFFFF5  bl       #0x181920
//   0x181950: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0288_0x181944(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x181944ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0c1ad8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0289 | PC: 0x181c60 | FDE: 0x0c1bd8 | Size: 256 bytes
// Khung tháo gỡ #0289 | Địa chỉ PC: 0x181c60 | Địa chỉ FDE: 0x0c1bd8 | Kích thước: 256 bytes
//   0x181c60: F9402400  ldr      x0, [x0, #0x48]
//   0x181c64: B4000060  cbz      x0, #0x181c70
//   0x181c68: F9400008  ldr      x8, [x0]
//   0x181c6c: 1406DC69  b        #0x338e10
static inline uint64_t fde_func_0289_0x181c60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x181c60ULL ^ (static_cast<uint64_t>(0xf9402400ULL) << 13);
    acc = (acc + a1 + 0xb4000060ULL) ^ 0x0c1bd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0290 | PC: 0x181e90 | FDE: 0x0c1cd0 | Size: 256 bytes
// Khung tháo gỡ #0290 | Địa chỉ PC: 0x181e90 | Địa chỉ FDE: 0x0c1cd0 | Kích thước: 256 bytes
//   0x181e90: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x181e94: 39403008  ldrb     w8, [x0, #0xc]
//   0x181e98: AA0003F3  mov      x19, x0
//   0x181e9c: 340000C8  cbz      w8, #0x181eb4
static inline uint64_t fde_func_0290_0x181e90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x181e90ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x39403008ULL) ^ 0x0c1cd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0291 | PC: 0x182188 | FDE: 0x0c1d40 | Size: 256 bytes [_ZN4lynx4tasm13CSSParseToken13GetAttributesEv]
// Khung tháo gỡ #0291 | Địa chỉ PC: 0x182188 | Địa chỉ FDE: 0x0c1d40 | Kích thước: 256 bytes
//   0x182188: D10183FF  sub      sp, sp, #0x60
//   0x18218c: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x182190: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x182194: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0291_0x182188(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x182188ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9035bf7ULL) ^ 0x0c1d40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0292 | PC: 0x182418 | FDE: 0x0c1df0 | Size: 256 bytes
// Khung tháo gỡ #0292 | Địa chỉ PC: 0x182418 | Địa chỉ FDE: 0x0c1df0 | Kích thước: 256 bytes
//   0x182418: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x18241c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x182420: B0000E28  adrp     x8, #0x347000
//   0x182424: 9104A108  add      x8, x8, #0x128
static inline uint64_t fde_func_0292_0x182418(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x182418ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c1df0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0293 | PC: 0x1825b4 | FDE: 0x0c1f18 | Size: 20 bytes
// Khung tháo gỡ #0293 | Địa chỉ PC: 0x1825b4 | Địa chỉ FDE: 0x0c1f18 | Kích thước: 20 bytes
//   0x1825b4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1825b8: 9406F9AE  bl       #0x340c70
//   0x1825bc: F9400000  ldr      x0, [x0]
//   0x1825c0: F84107FE  ldr      x30, [sp], #0x10
static inline uint64_t fde_func_0293_0x1825b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1825b4ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x9406f9aeULL) ^ 0x0c1f18ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0294 | PC: 0x1825c8 | FDE: 0x0c1f30 | Size: 256 bytes [_ZN4lynx4tasm11CSSProperty15GetPropertyNameENS0_13CSSPropertyIDE]
// Khung tháo gỡ #0294 | Địa chỉ PC: 0x1825c8 | Địa chỉ FDE: 0x0c1f30 | Kích thước: 256 bytes
//   0x1825c8: D10103FF  sub      sp, sp, #0x40
//   0x1825cc: F90013F4  str      x20, [sp, #0x20]
//   0x1825d0: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x1825d4: 9406B18A  bl       #0x32ebfc
static inline uint64_t fde_func_0294_0x1825c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1825c8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f4ULL) ^ 0x0c1f30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0295 | PC: 0x183424 | FDE: 0x0c1f80 | Size: 256 bytes [_ZN4lynx4tasm11CSSProperty13GetPropertyIDERKNS_4base13static_string15GenericCacheKeyE]
// Khung tháo gỡ #0295 | Địa chỉ PC: 0x183424 | Địa chỉ FDE: 0x0c1f80 | Kích thước: 256 bytes
//   0x183424: A9BE53FC  stp      x28, x20, [sp, #-0x20]!
//   0x183428: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x18342c: D14007FF  sub      sp, sp, #1, lsl #12
//   0x183430: D13183FF  sub      sp, sp, #0xc60
static inline uint64_t fde_func_0295_0x183424(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x183424ULL ^ (static_cast<uint64_t>(0xa9be53fcULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c1f80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0296 | PC: 0x184ec8 | FDE: 0x0c2068 | Size: 232 bytes
// Khung tháo gỡ #0296 | Địa chỉ PC: 0x184ec8 | Địa chỉ FDE: 0x0c2068 | Kích thước: 232 bytes
//   0x184ec8: AA1E03E2  mov      x2, x30
//   0x184ecc: 94065C0F  bl       #0x31bf08
//   0x184ed0: AA0203FE  mov      x30, x2
//   0x184ed4: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0296_0x184ec8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x184ec8ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94065c0fULL) ^ 0x0c2068ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0297 | PC: 0x184fb0 | FDE: 0x0c20b0 | Size: 244 bytes [_ZN4lynx4tasm11CSSProperty18GetShorthandExpandENS0_13CSSPropertyIDE]
// Khung tháo gỡ #0297 | Địa chỉ PC: 0x184fb0 | Địa chỉ FDE: 0x0c20b0 | Kích thước: 244 bytes
//   0x184fb0: D10103FF  sub      sp, sp, #0x40
//   0x184fb4: F90013F4  str      x20, [sp, #0x20]
//   0x184fb8: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x184fbc: 9406A710  bl       #0x32ebfc
static inline uint64_t fde_func_0297_0x184fb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x184fb0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f4ULL) ^ 0x0c20b0ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #0298 | PC: 0x1850a4 | FDE: 0x0c20e8 | Size: 32 bytes [_ZN4lynx4tasm11CSSProperty19IsShorthandPropertyENS0_13CSSPropertyIDE]
// Khung tháo gỡ #0298 | Địa chỉ PC: 0x1850a4 | Địa chỉ FDE: 0x0c20e8 | Kích thước: 32 bytes
//   0x1850a4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1850a8: 2A0003E1  mov      w1, w0
//   0x1850ac: F0000F20  adrp     x0, #0x36c000
//   0x1850b0: 910F6000  add      x0, x0, #0x3d8
static inline uint64_t fde_func_0298_0x1850a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1850a4ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x2a0003e1ULL) ^ 0x0c20e8ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0299 | PC: 0x1850c4 | FDE: 0x0c2100 | Size: 256 bytes [_ZN4lynx4tasm11CSSProperty26GetTimingOptionsPropertyIDERKNS_4base13static_string15GenericCacheKeyE]
// Khung tháo gỡ #0299 | Địa chỉ PC: 0x1850c4 | Địa chỉ FDE: 0x0c2100 | Kích thước: 256 bytes
//   0x1850c4: D10503FF  sub      sp, sp, #0x140
//   0x1850c8: A91253FC  stp      x28, x20, [sp, #0x120]
//   0x1850cc: A9137BF3  stp      x19, x30, [sp, #0x130]
//   0x1850d0: D53BD053  mrs      x19, tpidr_el0
static inline uint64_t fde_func_0299_0x1850c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1850c4ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xa91253fcULL) ^ 0x0c2100ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0300 | PC: 0x185214 | FDE: 0x0c2120 | Size: 256 bytes [_ZN4lynx4tasm11CSSProperty18GetComputeStyleMapEv]
// Khung tháo gỡ #0300 | Địa chỉ PC: 0x185214 | Địa chỉ FDE: 0x0c2120 | Kích thước: 256 bytes
//   0x185214: AA1E03E0  mov      x0, x30
//   0x185218: 94065B3C  bl       #0x31bf08
//   0x18521c: AA0003FE  mov      x30, x0
//   0x185220: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0300_0x185214(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x185214ULL ^ (static_cast<uint64_t>(0xaa1e03e0ULL) << 13);
    acc = (acc + a1 + 0x94065b3cULL) ^ 0x0c2120ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0301 | PC: 0x186784 | FDE: 0x0c21a0 | Size: 256 bytes
// Khung tháo gỡ #0301 | Địa chỉ PC: 0x186784 | Địa chỉ FDE: 0x0c21a0 | Kích thước: 256 bytes
//   0x186784: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x186788: 94065CBC  bl       #0x31da78
//   0x18678c: 90FFF721  adrp     x1, #0x6a000
//   0x186790: 91006260  add      x0, x19, #0x18
static inline uint64_t fde_func_0301_0x186784(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x186784ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94065cbcULL) ^ 0x0c21a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0302 | PC: 0x186894 | FDE: 0x0c2290 | Size: 256 bytes
// Khung tháo gỡ #0302 | Địa chỉ PC: 0x186894 | Địa chỉ FDE: 0x0c2290 | Kích thước: 256 bytes
//   0x186894: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x186898: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x18689c: 8B020449  add      x9, x2, x2, lsl #1
//   0x1868a0: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0302_0x186894(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x186894ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c2290ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0303 | PC: 0x186a58 | FDE: 0x0c22f8 | Size: 256 bytes [_ZN4lynx4tasm11CSSProperty27IsInspectorFilteredPropertyENS0_13CSSPropertyIDE]
// Khung tháo gỡ #0303 | Địa chỉ PC: 0x186a58 | Địa chỉ FDE: 0x0c22f8 | Kích thước: 256 bytes
//   0x186a58: B0000F28  adrp     x8, #0x36b000
//   0x186a5c: 9132A108  add      x8, x8, #0xca8
//   0x186a60: AA0803EA  mov      x10, x8
//   0x186a64: AA0803E9  mov      x9, x8
static inline uint64_t fde_func_0303_0x186a58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x186a58ULL ^ (static_cast<uint64_t>(0xb0000f28ULL) << 13);
    acc = (acc + a1 + 0x9132a108ULL) ^ 0x0c22f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0304 | PC: 0x186ce4 | FDE: 0x0c23c0 | Size: 256 bytes
// Khung tháo gỡ #0304 | Địa chỉ PC: 0x186ce4 | Địa chỉ FDE: 0x0c23c0 | Kích thước: 256 bytes
//   0x186ce4: 1406557A  b        #0x31c2cc
//   0x186ce8: D103C3FF  sub      sp, sp, #0xf0
//   0x186cec: A90C5BF7  stp      x23, x22, [sp, #0xc0]
//   0x186cf0: A90D53F5  stp      x21, x20, [sp, #0xd0]
static inline uint64_t fde_func_0304_0x186ce4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x186ce4ULL ^ (static_cast<uint64_t>(0x1406557aULL) << 13);
    acc = (acc + a1 + 0xd103c3ffULL) ^ 0x0c23c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0305 | PC: 0x187110 | FDE: 0x0c2508 | Size: 12 bytes [_ZNK4lynx4tasm8CSSValue12AsJsonStringEb]
// Khung tháo gỡ #0305 | Địa chỉ PC: 0x187110 | Địa chỉ FDE: 0x0c2508 | Kích thước: 12 bytes
//   0x187110: 12000021  and      w1, w1, #1
//   0x187114: 2A1F03E2  mov      w2, wzr
//   0x187118: 1406E6DE  b        #0x340c90
static inline uint64_t fde_func_0305_0x187110(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x187110ULL ^ (static_cast<uint64_t>(0x12000021ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e2ULL) ^ 0x0c2508ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0306 | PC: 0x18711c | FDE: 0x0c2520 | Size: 236 bytes [_ZN4lynx4tasm8CSSValue15ResolveVariableERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEERKNS_4base15LinearSearchMapINSB_6StringES1_NSB_20ReducedHashKeyPolicyISD_EELm0ELb0EEERKNS1_13CycleDetectorEiRKNS2_8functionIFvRKSD_SO_EEE]
// Khung tháo gỡ #0306 | Địa chỉ PC: 0x18711c | Địa chỉ FDE: 0x0c2520 | Kích thước: 236 bytes
//   0x18711c: AA1E03E5  mov      x5, x30
//   0x187120: 94068BA5  bl       #0x329fb4
//   0x187124: AA0503FE  mov      x30, x5
//   0x187128: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0306_0x18711c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18711cULL ^ (static_cast<uint64_t>(0xaa1e03e5ULL) << 13);
    acc = (acc + a1 + 0x94068ba5ULL) ^ 0x0c2520ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0307 | PC: 0x187208 | FDE: 0x0c2560 | Size: 256 bytes [_ZN4lynx4tasm8CSSValue12SubstitutionERKS1_RKNS_4base15LinearSearchMapINS4_6StringES1_NS4_20ReducedHashKeyPolicyIS6_EELm0ELb0EEERKNS1_13CycleDetectorEiRKNSt6__ndk18functionIFvRKS6_SI_EEE]
// Khung tháo gỡ #0307 | Địa chỉ PC: 0x187208 | Địa chỉ FDE: 0x0c2560 | Kích thước: 256 bytes
//   0x187208: AA1E03E5  mov      x5, x30
//   0x18720c: 94065CAE  bl       #0x31e4c4
//   0x187210: AA0503FE  mov      x30, x5
//   0x187214: A90D7BFD  stp      x29, x30, [sp, #0xd0]
static inline uint64_t fde_func_0307_0x187208(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x187208ULL ^ (static_cast<uint64_t>(0xaa1e03e5ULL) << 13);
    acc = (acc + a1 + 0x94065caeULL) ^ 0x0c2560ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0308 | PC: 0x187678 | FDE: 0x0c2620 | Size: 256 bytes [_ZN4lynx4tasm8CSSValue15ResolveFallbackERKNS0_12VarReferenceERKNS_4base15LinearSearchMapINS5_6StringES1_NS5_20ReducedHashKeyPolicyIS7_EELm0ELb0EEERKNS1_13CycleDetectorEiRKNSt6__ndk18functionIFvRKS7_SJ_EEE]
// Khung tháo gỡ #0308 | Địa chỉ PC: 0x187678 | Địa chỉ FDE: 0x0c2620 | Kích thước: 256 bytes
//   0x187678: AA1E03E5  mov      x5, x30
//   0x18767c: 94069A6C  bl       #0x32e02c
//   0x187680: AA0503FE  mov      x30, x5
//   0x187684: A9117BF3  stp      x19, x30, [sp, #0x110]
static inline uint64_t fde_func_0308_0x187678(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x187678ULL ^ (static_cast<uint64_t>(0xaa1e03e5ULL) << 13);
    acc = (acc + a1 + 0x94069a6cULL) ^ 0x0c2620ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0309 | PC: 0x18779c | FDE: 0x0c2650 | Size: 256 bytes
// Khung tháo gỡ #0309 | Địa chỉ PC: 0x18779c | Địa chỉ FDE: 0x0c2650 | Kích thước: 256 bytes
//   0x18779c: 39408008  ldrb     w8, [x0, #0x20]
//   0x1877a0: 34000048  cbz      w8, #0x1877a8
//   0x1877a4: 1406E38B  b        #0x3405d0
//   0x1877a8: D65F03C0  ret      
static inline uint64_t fde_func_0309_0x18779c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18779cULL ^ (static_cast<uint64_t>(0x39408008ULL) << 13);
    acc = (acc + a1 + 0x34000048ULL) ^ 0x0c2650ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0310 | PC: 0x18797c | FDE: 0x0c26e0 | Size: 256 bytes [_ZN4lynx4tasm8CSSValue13SubstituteAllERNS_4base15LinearSearchMapINS2_6StringES1_NS2_20ReducedHashKeyPolicyIS4_EELm0ELb0EEEiRKNSt6__ndk18functionIFvRKS4_SC_EEE]
// Khung tháo gỡ #0310 | Địa chỉ PC: 0x18797c | Địa chỉ FDE: 0x0c26e0 | Kích thước: 256 bytes
//   0x18797c: AA1E03E3  mov      x3, x30
//   0x187980: 94065162  bl       #0x31bf08
//   0x187984: AA0303FE  mov      x30, x3
//   0x187988: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0310_0x18797c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18797cULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94065162ULL) ^ 0x0c26e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0311 | PC: 0x187ce4 | FDE: 0x0c27a0 | Size: 256 bytes
// Khung tháo gỡ #0311 | Địa chỉ PC: 0x187ce4 | Địa chỉ FDE: 0x0c27a0 | Kích thước: 256 bytes
//   0x187ce4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x187ce8: 94066751  bl       #0x321a2c
//   0x187cec: 97FF81CD  bl       #0x168420
//   0x187cf0: F9400260  ldr      x0, [x19]
static inline uint64_t fde_func_0311_0x187ce4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x187ce4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94066751ULL) ^ 0x0c27a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0312 | PC: 0x188328 | FDE: 0x0c28e0 | Size: 216 bytes
// Khung tháo gỡ #0312 | Địa chỉ PC: 0x188328 | Địa chỉ FDE: 0x0c28e0 | Kích thước: 216 bytes
//   0x188328: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x18832c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x188330: 8B020448  add      x8, x2, x2, lsl #1
//   0x188334: 940669C7  bl       #0x322a50
static inline uint64_t fde_func_0312_0x188328(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188328ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c28e0ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #0313 | PC: 0x188400 | FDE: 0x0c2940 | Size: 112 bytes [_ZN4lynx4tasm8CSSValue12SubstitutionERKS1_RKNS_4base15LinearSearchMapINS4_6StringES1_NS4_20ReducedHashKeyPolicyIS6_EELm0ELb0EEEiRKNSt6__ndk18functionIFvRKS6_SF_EEE]
// Khung tháo gỡ #0313 | Địa chỉ PC: 0x188400 | Địa chỉ FDE: 0x0c2940 | Kích thước: 112 bytes
//   0x188400: A9BC63FC  stp      x28, x24, [sp, #-0x40]!
//   0x188404: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x188408: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x18840c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0313_0x188400(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188400ULL ^ (static_cast<uint64_t>(0xa9bc63fcULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0c2940ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0314 | PC: 0x188470 | FDE: 0x0c2968 | Size: 256 bytes [_ZN4lynx4tasm8CSSValue14ToVarReferenceEv]
// Khung tháo gỡ #0314 | Địa chỉ PC: 0x188470 | Địa chỉ FDE: 0x0c2968 | Kích thước: 256 bytes
//   0x188470: D103C3FF  sub      sp, sp, #0xf0
//   0x188474: AA1E03E1  mov      x1, x30
//   0x188478: 94065F3F  bl       #0x320174
//   0x18847c: AA0103FE  mov      x30, x1
static inline uint64_t fde_func_0314_0x188470(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188470ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xaa1e03e1ULL) ^ 0x0c2968ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0315 | PC: 0x1889bc | FDE: 0x0c2a18 | Size: 256 bytes [_ZN4lynx4tasm18CSSVariableHandler20GetCSSVariableByRuleERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEPNS0_15AttributeHolderERKNS_4base6StringERKNS_5lepus5ValueE]
// Khung tháo gỡ #0315 | Địa chỉ PC: 0x1889bc | Địa chỉ FDE: 0x0c2a18 | Kích thước: 256 bytes
//   0x1889bc: AA1E03E5  mov      x5, x30
//   0x1889c0: 940659EF  bl       #0x31f17c
//   0x1889c4: AA0503FE  mov      x30, x5
//   0x1889c8: A90A7BF3  stp      x19, x30, [sp, #0xa0]
static inline uint64_t fde_func_0315_0x1889bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1889bcULL ^ (static_cast<uint64_t>(0xaa1e03e5ULL) << 13);
    acc = (acc + a1 + 0x940659efULL) ^ 0x0c2a18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0316 | PC: 0x188b78 | FDE: 0x0c2a48 | Size: 256 bytes
// Khung tháo gỡ #0316 | Địa chỉ PC: 0x188b78 | Địa chỉ FDE: 0x0c2a48 | Kích thước: 256 bytes
//   0x188b78: AA1E03E2  mov      x2, x30
//   0x188b7c: 94065A7D  bl       #0x31f570
//   0x188b80: AA0203FE  mov      x30, x2
//   0x188b84: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0316_0x188b78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188b78ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94065a7dULL) ^ 0x0c2a48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0317 | PC: 0x188ee0 | FDE: 0x0c2b70 | Size: 256 bytes
// Khung tháo gỡ #0317 | Địa chỉ PC: 0x188ee0 | Địa chỉ FDE: 0x0c2b70 | Kích thước: 256 bytes
//   0x188ee0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x188ee4: B4000160  cbz      x0, #0x188f10
//   0x188ee8: AA0003F3  mov      x19, x0
//   0x188eec: 9400000B  bl       #0x188f18
static inline uint64_t fde_func_0317_0x188ee0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188ee0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb4000160ULL) ^ 0x0c2b70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0318 | PC: 0x1897a4 | FDE: 0x0c2c98 | Size: 256 bytes
// Khung tháo gỡ #0318 | Địa chỉ PC: 0x1897a4 | Địa chỉ FDE: 0x0c2c98 | Kích thước: 256 bytes
//   0x1897a4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1897a8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1897ac: 94066EBB  bl       #0x325298
//   0x1897b0: A9417BF3  ldp      x19, x30, [sp, #0x10]
static inline uint64_t fde_func_0318_0x1897a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1897a4ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c2c98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0319 | PC: 0x189c80 | FDE: 0x0c2dd0 | Size: 256 bytes
// Khung tháo gỡ #0319 | Địa chỉ PC: 0x189c80 | Địa chỉ FDE: 0x0c2dd0 | Kích thước: 256 bytes
//   0x189c80: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x189c84: 9406D6B1  bl       #0x33f748
//   0x189c88: 94064C5B  bl       #0x31cdf4
//   0x189c8c: B4000060  cbz      x0, #0x189c98
static inline uint64_t fde_func_0319_0x189c80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x189c80ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9406d6b1ULL) ^ 0x0c2dd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0320 | PC: 0x18a000 | FDE: 0x0c2ed8 | Size: 256 bytes
// Khung tháo gỡ #0320 | Địa chỉ PC: 0x18a000 | Địa chỉ FDE: 0x0c2ed8 | Kích thước: 256 bytes
//   0x18a000: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x18a004: 94065430  bl       #0x31f0c4
//   0x18a008: 97FFFF71  bl       #0x189dcc
//   0x18a00c: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0320_0x18a000(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18a000ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94065430ULL) ^ 0x0c2ed8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0321 | PC: 0x18a6c0 | FDE: 0x0c3010 | Size: 256 bytes
// Khung tháo gỡ #0321 | Địa chỉ PC: 0x18a6c0 | Địa chỉ FDE: 0x0c3010 | Kích thước: 256 bytes
//   0x18a6c0: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x18a6c4: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x18a6c8: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x18a6cc: 94064833  bl       #0x31c798
static inline uint64_t fde_func_0321_0x18a6c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18a6c0ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0c3010ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0322 | PC: 0x18af10 | FDE: 0x0c3128 | Size: 256 bytes
// Khung tháo gỡ #0322 | Địa chỉ PC: 0x18af10 | Địa chỉ FDE: 0x0c3128 | Kích thước: 256 bytes
//   0x18af10: AA1F03E1  mov      x1, xzr
//   0x18af14: 17FFFFF2  b        #0x18aedc
//   0x18af18: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x18af1c: A90153F5  stp      x21, x20, [sp, #0x10]
static inline uint64_t fde_func_0322_0x18af10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18af10ULL ^ (static_cast<uint64_t>(0xaa1f03e1ULL) << 13);
    acc = (acc + a1 + 0x17fffff2ULL) ^ 0x0c3128ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0323 | PC: 0x18b1ac | FDE: 0x0c3250 | Size: 256 bytes [_ZNK4lynx3css15LynxCSSSelector8ToStringEv]
// Khung tháo gỡ #0323 | Địa chỉ PC: 0x18b1ac | Địa chỉ FDE: 0x0c3250 | Kích thước: 256 bytes
//   0x18b1ac: AA1E03E1  mov      x1, x30
//   0x18b1b0: 940647DF  bl       #0x31d12c
//   0x18b1b4: AA0103FE  mov      x30, x1
//   0x18b1b8: A90C7BFD  stp      x29, x30, [sp, #0xc0]
static inline uint64_t fde_func_0323_0x18b1ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18b1acULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x940647dfULL) ^ 0x0c3250ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0324 | PC: 0x18bb58 | FDE: 0x0c33b0 | Size: 256 bytes
// Khung tháo gỡ #0324 | Địa chỉ PC: 0x18bb58 | Địa chỉ FDE: 0x0c33b0 | Kích thước: 256 bytes
//   0x18bb58: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x18bb5c: 9406432F  bl       #0x31c818
//   0x18bb60: B4000113  cbz      x19, #0x18bb80
//   0x18bb64: 39404008  ldrb     w8, [x0, #0x10]
static inline uint64_t fde_func_0324_0x18bb58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18bb58ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9406432fULL) ^ 0x0c33b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0325 | PC: 0x18bf28 | FDE: 0x0c34d8 | Size: 256 bytes
// Khung tháo gỡ #0325 | Địa chỉ PC: 0x18bf28 | Địa chỉ FDE: 0x0c34d8 | Kích thước: 256 bytes
//   0x18bf28: AA1E03E4  mov      x4, x30
//   0x18bf2c: 94069342  bl       #0x330c34
//   0x18bf30: AA0403FE  mov      x30, x4
//   0x18bf34: A9197BF3  stp      x19, x30, [sp, #0x190]
static inline uint64_t fde_func_0325_0x18bf28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18bf28ULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x94069342ULL) ^ 0x0c34d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0326 | PC: 0x18cccc | FDE: 0x0c3658 | Size: 256 bytes
// Khung tháo gỡ #0326 | Địa chỉ PC: 0x18cccc | Địa chỉ FDE: 0x0c3658 | Kích thước: 256 bytes
//   0x18cccc: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x18ccd0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x18ccd4: 94066B79  bl       #0x327ab8
//   0x18ccd8: 9406CED2  bl       #0x340820
static inline uint64_t fde_func_0326_0x18cccc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18ccccULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c3658ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0327 | PC: 0x18d56c | FDE: 0x0c37c0 | Size: 256 bytes
// Khung tháo gỡ #0327 | Địa chỉ PC: 0x18d56c | Địa chỉ FDE: 0x0c37c0 | Kích thước: 256 bytes
//   0x18d56c: AA1E03E4  mov      x4, x30
//   0x18d570: 940663ED  bl       #0x326524
//   0x18d574: AA0403FE  mov      x30, x4
//   0x18d578: A91A7BF3  stp      x19, x30, [sp, #0x1a0]
static inline uint64_t fde_func_0327_0x18d56c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d56cULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x940663edULL) ^ 0x0c37c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0328 | PC: 0x18e568 | FDE: 0x0c3940 | Size: 256 bytes
// Khung tháo gỡ #0328 | Địa chỉ PC: 0x18e568 | Địa chỉ FDE: 0x0c3940 | Kích thước: 256 bytes
//   0x18e568: AA1E03E4  mov      x4, x30
//   0x18e56c: 940686EF  bl       #0x330128
//   0x18e570: AA0403FE  mov      x30, x4
//   0x18e574: A9127BF3  stp      x19, x30, [sp, #0x120]
static inline uint64_t fde_func_0328_0x18e568(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18e568ULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x940686efULL) ^ 0x0c3940ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0329 | PC: 0x18f144 | FDE: 0x0c3a90 | Size: 256 bytes
// Khung tháo gỡ #0329 | Địa chỉ PC: 0x18f144 | Địa chỉ FDE: 0x0c3a90 | Kích thước: 256 bytes
//   0x18f144: AA1E03E3  mov      x3, x30
//   0x18f148: 94063370  bl       #0x31bf08
//   0x18f14c: AA0303FE  mov      x30, x3
//   0x18f150: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0329_0x18f144(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18f144ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94063370ULL) ^ 0x0c3a90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0330 | PC: 0x18fb74 | FDE: 0x0c3bc8 | Size: 256 bytes
// Khung tháo gỡ #0330 | Địa chỉ PC: 0x18fb74 | Địa chỉ FDE: 0x0c3bc8 | Kích thước: 256 bytes
//   0x18fb74: D10583FF  sub      sp, sp, #0x160
//   0x18fb78: FD0083EA  str      d10, [sp, #0x100]
//   0x18fb7c: 6D10A3E9  stp      d9, d8, [sp, #0x108]
//   0x18fb80: F9008FFC  str      x28, [sp, #0x118]
static inline uint64_t fde_func_0330_0x18fb74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18fb74ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xfd0083eaULL) ^ 0x0c3bc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0331 | PC: 0x190848 | FDE: 0x0c3d28 | Size: 256 bytes
// Khung tháo gỡ #0331 | Địa chỉ PC: 0x190848 | Địa chỉ FDE: 0x0c3d28 | Kích thước: 256 bytes
//   0x190848: D10103FF  sub      sp, sp, #0x40
//   0x19084c: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x190850: 9406770A  bl       #0x32e478
//   0x190854: F90013FF  str      xzr, [sp, #0x20]
static inline uint64_t fde_func_0331_0x190848(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x190848ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9037bf3ULL) ^ 0x0c3d28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0332 | PC: 0x190b14 | FDE: 0x0c3e50 | Size: 256 bytes
// Khung tháo gỡ #0332 | Địa chỉ PC: 0x190b14 | Địa chỉ FDE: 0x0c3e50 | Kích thước: 256 bytes
//   0x190b14: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x190b18: 39408008  ldrb     w8, [x0, #0x20]
//   0x190b1c: 39408029  ldrb     w9, [x1, #0x20]
//   0x190b20: 6B09011F  cmp      w8, w9
static inline uint64_t fde_func_0332_0x190b14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x190b14ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x39408008ULL) ^ 0x0c3e50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0333 | PC: 0x190e48 | FDE: 0x0c3f60 | Size: 256 bytes
// Khung tháo gỡ #0333 | Địa chỉ PC: 0x190e48 | Địa chỉ FDE: 0x0c3f60 | Kích thước: 256 bytes
//   0x190e48: AA0103E2  mov      x2, x1
//   0x190e4c: 528001E1  mov      w1, #0xf
//   0x190e50: 17FFFCF5  b        #0x190224
//   0x190e54: F81E0FF4  str      x20, [sp, #-0x20]!
static inline uint64_t fde_func_0333_0x190e48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x190e48ULL ^ (static_cast<uint64_t>(0xaa0103e2ULL) << 13);
    acc = (acc + a1 + 0x528001e1ULL) ^ 0x0c3f60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0334 | PC: 0x1918d8 | FDE: 0x0c4098 | Size: 256 bytes
// Khung tháo gỡ #0334 | Địa chỉ PC: 0x1918d8 | Địa chỉ FDE: 0x0c4098 | Kích thước: 256 bytes
//   0x1918d8: D105C3FF  sub      sp, sp, #0x170
//   0x1918dc: FD0083EA  str      d10, [sp, #0x100]
//   0x1918e0: 6D1123E9  stp      d9, d8, [sp, #0x110]
//   0x1918e4: A9126BFC  stp      x28, x26, [sp, #0x120]
static inline uint64_t fde_func_0334_0x1918d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1918d8ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xfd0083eaULL) ^ 0x0c4098ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0335 | PC: 0x1921ac | FDE: 0x0c41f8 | Size: 256 bytes
// Khung tháo gỡ #0335 | Địa chỉ PC: 0x1921ac | Địa chỉ FDE: 0x0c41f8 | Kích thước: 256 bytes
//   0x1921ac: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1921b0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1921b4: 3943E008  ldrb     w8, [x0, #0xf8]
//   0x1921b8: 350001E8  cbnz     w8, #0x1921f4
static inline uint64_t fde_func_0335_0x1921ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1921acULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c41f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0336 | PC: 0x192590 | FDE: 0x0c4320 | Size: 256 bytes
// Khung tháo gỡ #0336 | Địa chỉ PC: 0x192590 | Địa chỉ FDE: 0x0c4320 | Kích thước: 256 bytes
//   0x192590: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x192594: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x192598: F9400008  ldr      x8, [x0]
//   0x19259c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0336_0x192590(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x192590ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c4320ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0337 | PC: 0x192d2c | FDE: 0x0c4470 | Size: 256 bytes
// Khung tháo gỡ #0337 | Địa chỉ PC: 0x192d2c | Địa chỉ FDE: 0x0c4470 | Kích thước: 256 bytes
//   0x192d2c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x192d30: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x192d34: AA0103F4  mov      x20, x1
//   0x192d38: AA0203F3  mov      x19, x2
static inline uint64_t fde_func_0337_0x192d2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x192d2cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c4470ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0338 | PC: 0x193624 | FDE: 0x0c45b0 | Size: 256 bytes
// Khung tháo gỡ #0338 | Địa chỉ PC: 0x193624 | Địa chỉ FDE: 0x0c45b0 | Kích thước: 256 bytes
//   0x193624: AA1E03E3  mov      x3, x30
//   0x193628: 9406481C  bl       #0x325698
//   0x19362c: AA0303FE  mov      x30, x3
//   0x193630: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0338_0x193624(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x193624ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x9406481cULL) ^ 0x0c45b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0339 | PC: 0x193c14 | FDE: 0x0c46f0 | Size: 256 bytes
// Khung tháo gỡ #0339 | Địa chỉ PC: 0x193c14 | Địa chỉ FDE: 0x0c46f0 | Kích thước: 256 bytes
//   0x193c14: 7105281F  cmp      w0, #0x14a
//   0x193c18: 54000081  b.ne     #0x193c28
//   0x193c1c: F0FFF668  adrp     x8, #0x62000
//   0x193c20: FD42B900  ldr      d0, [x8, #0x570]
static inline uint64_t fde_func_0339_0x193c14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x193c14ULL ^ (static_cast<uint64_t>(0x7105281fULL) << 13);
    acc = (acc + a1 + 0x54000081ULL) ^ 0x0c46f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0340 | PC: 0x1940d8 | FDE: 0x0c4820 | Size: 256 bytes
// Khung tháo gỡ #0340 | Địa chỉ PC: 0x1940d8 | Địa chỉ FDE: 0x0c4820 | Kích thước: 256 bytes
//   0x1940d8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1940dc: 9406A32C  bl       #0x33cd8c
//   0x1940e0: 94062666  bl       #0x31da78
//   0x1940e4: D2E7FE08  mov      x8, #0x3ff0000000000000
static inline uint64_t fde_func_0340_0x1940d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1940d8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9406a32cULL) ^ 0x0c4820ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0341 | PC: 0x194ba0 | FDE: 0x0c4948 | Size: 256 bytes
// Khung tháo gỡ #0341 | Địa chỉ PC: 0x194ba0 | Địa chỉ FDE: 0x0c4948 | Kích thước: 256 bytes
//   0x194ba0: 7100349F  cmp      w4, #0xd
//   0x194ba4: 12800029  mov      w9, #-2
//   0x194ba8: 1A9F0129  csel     w9, w9, wzr, eq
//   0x194bac: 8B224028  add      x8, x1, w2, uxtw
static inline uint64_t fde_func_0341_0x194ba0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x194ba0ULL ^ (static_cast<uint64_t>(0x7100349fULL) << 13);
    acc = (acc + a1 + 0x12800029ULL) ^ 0x0c4948ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0342 | PC: 0x196120 | FDE: 0x0c4a98 | Size: 256 bytes
// Khung tháo gỡ #0342 | Địa chỉ PC: 0x196120 | Địa chỉ FDE: 0x0c4a98 | Kích thước: 256 bytes
//   0x196120: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x196124: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x196128: F9400413  ldr      x19, [x0, #8]
//   0x19612c: F9400035  ldr      x21, [x1]
static inline uint64_t fde_func_0342_0x196120(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x196120ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c4a98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0343 | PC: 0x196d54 | FDE: 0x0c4c00 | Size: 256 bytes
// Khung tháo gỡ #0343 | Địa chỉ PC: 0x196d54 | Địa chỉ FDE: 0x0c4c00 | Kích thước: 256 bytes
//   0x196d54: F81C0FFC  str      x28, [sp, #-0x40]!
//   0x196d58: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x196d5c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x196d60: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0343_0x196d54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x196d54ULL ^ (static_cast<uint64_t>(0xf81c0ffcULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0c4c00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0344 | PC: 0x197ae4 | FDE: 0x0c4d78 | Size: 256 bytes
// Khung tháo gỡ #0344 | Địa chỉ PC: 0x197ae4 | Địa chỉ FDE: 0x0c4d78 | Kích thước: 256 bytes
//   0x197ae4: AA1E03E4  mov      x4, x30
//   0x197ae8: 94066190  bl       #0x330128
//   0x197aec: AA0403FE  mov      x30, x4
//   0x197af0: A9127BF3  stp      x19, x30, [sp, #0x120]
static inline uint64_t fde_func_0344_0x197ae4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x197ae4ULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x94066190ULL) ^ 0x0c4d78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0345 | PC: 0x198928 | FDE: 0x0c4ef8 | Size: 256 bytes
// Khung tháo gỡ #0345 | Địa chỉ PC: 0x198928 | Địa chỉ FDE: 0x0c4ef8 | Kích thước: 256 bytes
//   0x198928: FC190FE8  str      d8, [sp, #-0x70]!
//   0x19892c: AA1E03E4  mov      x4, x30
//   0x198930: 9406156A  bl       #0x31ded8
//   0x198934: AA0403FE  mov      x30, x4
static inline uint64_t fde_func_0345_0x198928(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x198928ULL ^ (static_cast<uint64_t>(0xfc190fe8ULL) << 13);
    acc = (acc + a1 + 0xaa1e03e4ULL) ^ 0x0c4ef8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0346 | PC: 0x1994b4 | FDE: 0x0c5038 | Size: 256 bytes
// Khung tháo gỡ #0346 | Địa chỉ PC: 0x1994b4 | Địa chỉ FDE: 0x0c5038 | Kích thước: 256 bytes
//   0x1994b4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1994b8: 94061703  bl       #0x31f0c4
//   0x1994bc: 94000004  bl       #0x1994cc
//   0x1994c0: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0346_0x1994b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1994b4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94061703ULL) ^ 0x0c5038ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0347 | PC: 0x199694 | FDE: 0x0c5150 | Size: 256 bytes
// Khung tháo gỡ #0347 | Địa chỉ PC: 0x199694 | Địa chỉ FDE: 0x0c5150 | Kích thước: 256 bytes
//   0x199694: 91052000  add      x0, x0, #0x148
//   0x199698: D65F03C0  ret      
//   0x19969c: 9105C000  add      x0, x0, #0x170
//   0x1996a0: D65F03C0  ret      
static inline uint64_t fde_func_0347_0x199694(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x199694ULL ^ (static_cast<uint64_t>(0x91052000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0c5150ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0348 | PC: 0x1997a4 | FDE: 0x0c5248 | Size: 256 bytes
// Khung tháo gỡ #0348 | Địa chỉ PC: 0x1997a4 | Địa chỉ FDE: 0x0c5248 | Kích thước: 256 bytes
//   0x1997a4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1997a8: 9107A000  add      x0, x0, #0x1e8
//   0x1997ac: 97FF406E  bl       #0x169964
//   0x1997b0: B4000040  cbz      x0, #0x1997b8
static inline uint64_t fde_func_0348_0x1997a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1997a4ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x9107a000ULL) ^ 0x0c5248ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0349 | PC: 0x199c50 | FDE: 0x0c5350 | Size: 256 bytes
// Khung tháo gỡ #0349 | Địa chỉ PC: 0x199c50 | Địa chỉ FDE: 0x0c5350 | Kích thước: 256 bytes
//   0x199c50: D10143FF  sub      sp, sp, #0x50
//   0x199c54: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x199c58: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x199c5c: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0349_0x199c50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x199c50ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x0c5350ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0350 | PC: 0x19a08c | FDE: 0x0c5490 | Size: 256 bytes
// Khung tháo gỡ #0350 | Địa chỉ PC: 0x19a08c | Địa chỉ FDE: 0x0c5490 | Kích thước: 256 bytes
//   0x19a08c: AA1E03E2  mov      x2, x30
//   0x19a090: 94060B09  bl       #0x31ccb4
//   0x19a094: AA0203FE  mov      x30, x2
//   0x19a098: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0350_0x19a08c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19a08cULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94060b09ULL) ^ 0x0c5490ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0351 | PC: 0x19a860 | FDE: 0x0c55d8 | Size: 256 bytes
// Khung tháo gỡ #0351 | Địa chỉ PC: 0x19a860 | Địa chỉ FDE: 0x0c55d8 | Kích thước: 256 bytes
//   0x19a860: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x19a864: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x19a868: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x19a86c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0351_0x19a860(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19a860ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0c55d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0352 | PC: 0x19aea8 | FDE: 0x0c5728 | Size: 256 bytes
// Khung tháo gỡ #0352 | Địa chỉ PC: 0x19aea8 | Địa chỉ FDE: 0x0c5728 | Kích thước: 256 bytes
//   0x19aea8: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x19aeac: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x19aeb0: AA0203F3  mov      x19, x2
//   0x19aeb4: 9406080C  bl       #0x31cee4
static inline uint64_t fde_func_0352_0x19aea8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19aea8ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c5728ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0353 | PC: 0x19b244 | FDE: 0x0c5850 | Size: 256 bytes
// Khung tháo gỡ #0353 | Địa chỉ PC: 0x19b244 | Địa chỉ FDE: 0x0c5850 | Kích thước: 256 bytes
//   0x19b244: D10483FF  sub      sp, sp, #0x120
//   0x19b248: F90083FC  str      x28, [sp, #0x100]
//   0x19b24c: A9117BF3  stp      x19, x30, [sp, #0x110]
//   0x19b250: A90893E3  stp      x3, x4, [sp, #0x88]
static inline uint64_t fde_func_0353_0x19b244(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19b244ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x0c5850ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0354 | PC: 0x19b384 | FDE: 0x0c58a8 | Size: 144 bytes [_ZN4lynx4tasm11UnitHandler15ProcessCSSValueENS0_13CSSPropertyIDERKNS0_8CSSValueERNS_4base13LinkedHashMapIS2_S3_Lj32ELj12ENSt6__ndk14hashIS2_EENS8_8equal_toIS2_EEEERKNS0_16CSSParserConfigsE]
// Khung tháo gỡ #0354 | Địa chỉ PC: 0x19b384 | Địa chỉ FDE: 0x0c58a8 | Kích thước: 144 bytes
//   0x19b384: D10183FF  sub      sp, sp, #0x60
//   0x19b388: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x19b38c: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x19b390: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0354_0x19b384(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19b384ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9035bf7ULL) ^ 0x0c58a8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0355 | PC: 0x19b414 | FDE: 0x0c58c8 | Size: 256 bytes [_ZN4lynx4tasm11UnitHandler7ProcessENS0_13CSSPropertyIDERKNS_5lepus5ValueERNS_4base13LinkedHashMapIS2_NS0_8CSSValueELj32ELj12ENSt6__ndk14hashIS2_EENSA_8equal_toIS2_EEEERKNS0_16CSSParserConfigsE]
// Khung tháo gỡ #0355 | Địa chỉ PC: 0x19b414 | Địa chỉ FDE: 0x0c58c8 | Kích thước: 256 bytes
//   0x19b414: AA1E03E4  mov      x4, x30
//   0x19b418: 94060B71  bl       #0x31e1dc
//   0x19b41c: AA0403FE  mov      x30, x4
//   0x19b420: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_0355_0x19b414(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19b414ULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x94060b71ULL) ^ 0x0c58c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0356 | PC: 0x19bab0 | FDE: 0x0c58f0 | Size: 256 bytes [_ZN4lynx4tasm11UnitHandler7ProcessENS0_13CSSPropertyIDERKNS_5lepus5ValueERKNS0_16CSSParserConfigsE]
// Khung tháo gỡ #0356 | Địa chỉ PC: 0x19bab0 | Địa chỉ FDE: 0x0c58f0 | Kích thước: 256 bytes
//   0x19bab0: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x19bab4: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x19bab8: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x19babc: 94060B81  bl       #0x31e8c0
static inline uint64_t fde_func_0356_0x19bab0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19bab0ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0c58f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0357 | PC: 0x19bf18 | FDE: 0x0c59b0 | Size: 256 bytes
// Khung tháo gỡ #0357 | Địa chỉ PC: 0x19bf18 | Địa chỉ FDE: 0x0c59b0 | Kích thước: 256 bytes
//   0x19bf18: D10143FF  sub      sp, sp, #0x50
//   0x19bf1c: F9001BF4  str      x20, [sp, #0x30]
//   0x19bf20: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x19bf24: 90000D69  adrp     x9, #0x347000
static inline uint64_t fde_func_0357_0x19bf18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19bf18ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf4ULL) ^ 0x0c59b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0358 | PC: 0x19c0b8 | FDE: 0x0c5ab8 | Size: 112 bytes
// Khung tháo gỡ #0358 | Địa chỉ PC: 0x19c0b8 | Địa chỉ FDE: 0x0c5ab8 | Kích thước: 112 bytes
//   0x19c0b8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x19c0bc: AA0003F3  mov      x19, x0
//   0x19c0c0: 97FFFFE1  bl       #0x19c044
//   0x19c0c4: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0358_0x19c0b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19c0b8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0c5ab8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0359 | PC: 0x19c128 | FDE: 0x0c5ba8 | Size: 172 bytes
// Khung tháo gỡ #0359 | Địa chỉ PC: 0x19c128 | Địa chỉ FDE: 0x0c5ba8 | Kích thước: 172 bytes
//   0x19c128: 91004000  add      x0, x0, #0x10
//   0x19c12c: 1400052C  b        #0x19d5dc
//   0x19c130: 91004000  add      x0, x0, #0x10
//   0x19c134: 17FF229F  b        #0x164bb0
static inline uint64_t fde_func_0359_0x19c128(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19c128ULL ^ (static_cast<uint64_t>(0x91004000ULL) << 13);
    acc = (acc + a1 + 0x1400052cULL) ^ 0x0c5ba8ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0360 | PC: 0x19c1d4 | FDE: 0x0c5c98 | Size: 256 bytes
// Khung tháo gỡ #0360 | Địa chỉ PC: 0x19c1d4 | Địa chỉ FDE: 0x0c5c98 | Kích thước: 256 bytes
//   0x19c1d4: 91004000  add      x0, x0, #0x10
//   0x19c1d8: 140690E2  b        #0x340560
//   0x19c1dc: 91004000  add      x0, x0, #0x10
//   0x19c1e0: 140690E4  b        #0x340570
static inline uint64_t fde_func_0360_0x19c1d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19c1d4ULL ^ (static_cast<uint64_t>(0x91004000ULL) << 13);
    acc = (acc + a1 + 0x140690e2ULL) ^ 0x0c5c98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0361 | PC: 0x19c3c8 | FDE: 0x0c5da8 | Size: 256 bytes
// Khung tháo gỡ #0361 | Địa chỉ PC: 0x19c3c8 | Địa chỉ FDE: 0x0c5da8 | Kích thước: 256 bytes
//   0x19c3c8: D100C3FF  sub      sp, sp, #0x30
//   0x19c3cc: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x19c3d0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x19c3d4: 94060CF0  bl       #0x31f794
static inline uint64_t fde_func_0361_0x19c3c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19c3c8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0c5da8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0362 | PC: 0x19c8a8 | FDE: 0x0c5ee8 | Size: 256 bytes
// Khung tháo gỡ #0362 | Địa chỉ PC: 0x19c8a8 | Địa chỉ FDE: 0x0c5ee8 | Kích thước: 256 bytes
//   0x19c8a8: D10103FF  sub      sp, sp, #0x40
//   0x19c8ac: F90013F4  str      x20, [sp, #0x20]
//   0x19c8b0: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x19c8b4: 940602C4  bl       #0x31d3c4
static inline uint64_t fde_func_0362_0x19c8a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19c8a8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f4ULL) ^ 0x0c5ee8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0363 | PC: 0x19cda0 | FDE: 0x0c6028 | Size: 256 bytes
// Khung tháo gỡ #0363 | Địa chỉ PC: 0x19cda0 | Địa chỉ FDE: 0x0c6028 | Kích thước: 256 bytes
//   0x19cda0: D10143FF  sub      sp, sp, #0x50
//   0x19cda4: F90013F6  str      x22, [sp, #0x20]
//   0x19cda8: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x19cdac: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0363_0x19cda0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19cda0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x0c6028ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0364 | PC: 0x19d20c | FDE: 0x0c6168 | Size: 256 bytes [_ZN4lynx5piper26makeQuickJsRuntimeProfilerENSt6__ndk110shared_ptrINS0_10JSIContextEEE]
// Khung tháo gỡ #0364 | Địa chỉ PC: 0x19d20c | Địa chỉ FDE: 0x0c6168 | Kích thước: 256 bytes
//   0x19d20c: 17FED5BA  b        #0x1528f4
//   0x19d210: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x19d214: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x19d218: A9027BF3  stp      x19, x30, [sp, #0x20]
static inline uint64_t fde_func_0364_0x19d20c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19d20cULL ^ (static_cast<uint64_t>(0x17fed5baULL) << 13);
    acc = (acc + a1 + 0xf81d0ff6ULL) ^ 0x0c6168ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0365 | PC: 0x19d460 | FDE: 0x0c6288 | Size: 256 bytes
// Khung tháo gỡ #0365 | Địa chỉ PC: 0x19d460 | Địa chỉ FDE: 0x0c6288 | Kích thước: 256 bytes
//   0x19d460: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x19d464: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x19d468: AA0003F4  mov      x20, x0
//   0x19d46c: 52800600  mov      w0, #0x30
static inline uint64_t fde_func_0365_0x19d460(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19d460ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c6288ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0366 | PC: 0x19d618 | FDE: 0x0c6390 | Size: 256 bytes
// Khung tháo gỡ #0366 | Địa chỉ PC: 0x19d618 | Địa chỉ FDE: 0x0c6390 | Kích thước: 256 bytes
//   0x19d618: 39402008  ldrb     w8, [x0, #8]
//   0x19d61c: 7100051F  cmp      w8, #1
//   0x19d620: 54000100  b.eq     #0x19d640
//   0x19d624: 7100451F  cmp      w8, #0x11
static inline uint64_t fde_func_0366_0x19d618(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19d618ULL ^ (static_cast<uint64_t>(0x39402008ULL) << 13);
    acc = (acc + a1 + 0x7100051fULL) ^ 0x0c6390ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0367 | PC: 0x19d998 | FDE: 0x0c64a8 | Size: 256 bytes
// Khung tháo gỡ #0367 | Địa chỉ PC: 0x19d998 | Địa chỉ FDE: 0x0c64a8 | Kích thước: 256 bytes
//   0x19d998: 2A0103E9  mov      w9, w1
//   0x19d99c: 92800008  mov      x8, #-1
//   0x19d9a0: B4000149  cbz      x9, #0x19d9c8
//   0x19d9a4: D341FD2A  lsr      x10, x9, #1
static inline uint64_t fde_func_0367_0x19d998(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19d998ULL ^ (static_cast<uint64_t>(0x2a0103e9ULL) << 13);
    acc = (acc + a1 + 0x92800008ULL) ^ 0x0c64a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0368 | PC: 0x19ea80 | FDE: 0x0c65f0 | Size: 256 bytes
// Khung tháo gỡ #0368 | Địa chỉ PC: 0x19ea80 | Địa chỉ FDE: 0x0c65f0 | Kích thước: 256 bytes
//   0x19ea80: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x19ea84: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x19ea88: 940615AC  bl       #0x324138
//   0x19ea8c: 94062F7E  bl       #0x32a884
static inline uint64_t fde_func_0368_0x19ea80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19ea80ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c65f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0369 | PC: 0x19efc8 | FDE: 0x0c6730 | Size: 256 bytes
// Khung tháo gỡ #0369 | Địa chỉ PC: 0x19efc8 | Địa chỉ FDE: 0x0c6730 | Kích thước: 256 bytes
//   0x19efc8: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x19efcc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x19efd0: 9405FCD8  bl       #0x31e330
//   0x19efd4: 94065477  bl       #0x3341b0
static inline uint64_t fde_func_0369_0x19efc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19efc8ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c6730ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0370 | PC: 0x19f2a8 | FDE: 0x0c6870 | Size: 256 bytes
// Khung tháo gỡ #0370 | Địa chỉ PC: 0x19f2a8 | Địa chỉ FDE: 0x0c6870 | Kích thước: 256 bytes
//   0x19f2a8: D10103FF  sub      sp, sp, #0x40
//   0x19f2ac: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x19f2b0: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x19f2b4: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0370_0x19f2a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19f2a8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0c6870ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0371 | PC: 0x19f478 | FDE: 0x0c69b0 | Size: 256 bytes
// Khung tháo gỡ #0371 | Địa chỉ PC: 0x19f478 | Địa chỉ FDE: 0x0c69b0 | Kích thước: 256 bytes
//   0x19f478: D10103FF  sub      sp, sp, #0x40
//   0x19f47c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x19f480: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x19f484: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0371_0x19f478(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19f478ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0c69b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0372 | PC: 0x19f7e0 | FDE: 0x0c6af8 | Size: 256 bytes
// Khung tháo gỡ #0372 | Địa chỉ PC: 0x19f7e0 | Địa chỉ FDE: 0x0c6af8 | Kích thước: 256 bytes
//   0x19f7e0: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x19f7e4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x19f7e8: 940609A6  bl       #0x321e80
//   0x19f7ec: 12000261  and      w1, w19, #1
static inline uint64_t fde_func_0372_0x19f7e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19f7e0ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c6af8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0373 | PC: 0x19fa94 | FDE: 0x0c6c30 | Size: 256 bytes
// Khung tháo gỡ #0373 | Địa chỉ PC: 0x19fa94 | Địa chỉ FDE: 0x0c6c30 | Kích thước: 256 bytes
//   0x19fa94: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x19fa98: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x19fa9c: 94067255  bl       #0x33c3f0
//   0x19faa0: A9417BF3  ldp      x19, x30, [sp, #0x10]
static inline uint64_t fde_func_0373_0x19fa94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19fa94ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c6c30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0374 | PC: 0x1a054c | FDE: 0x0c6db0 | Size: 256 bytes
// Khung tháo gỡ #0374 | Địa chỉ PC: 0x1a054c | Địa chỉ FDE: 0x0c6db0 | Kích thước: 256 bytes
//   0x1a054c: AA1E03E3  mov      x3, x30
//   0x1a0550: 9405F650  bl       #0x31de90
//   0x1a0554: AA0303FE  mov      x30, x3
//   0x1a0558: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0374_0x1a054c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a054cULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x9405f650ULL) ^ 0x0c6db0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0375 | PC: 0x1a0aec | FDE: 0x0c6ef8 | Size: 256 bytes
// Khung tháo gỡ #0375 | Địa chỉ PC: 0x1a0aec | Địa chỉ FDE: 0x0c6ef8 | Kích thước: 256 bytes
//   0x1a0aec: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1a0af0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1a0af4: 9405F490  bl       #0x31dd34
//   0x1a0af8: F940A2A2  ldr      x2, [x21, #0x140]
static inline uint64_t fde_func_0375_0x1a0aec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a0aecULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c6ef8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0376 | PC: 0x1a0c64 | FDE: 0x0c7038 | Size: 256 bytes
// Khung tháo gỡ #0376 | Địa chỉ PC: 0x1a0c64 | Địa chỉ FDE: 0x0c7038 | Kích thước: 256 bytes
//   0x1a0c64: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1a0c68: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1a0c6c: 9405F432  bl       #0x31dd34
//   0x1a0c70: 94061A4F  bl       #0x3275ac
static inline uint64_t fde_func_0376_0x1a0c64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a0c64ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c7038ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0377 | PC: 0x1a0ea4 | FDE: 0x0c7150 | Size: 256 bytes
// Khung tháo gỡ #0377 | Địa chỉ PC: 0x1a0ea4 | Địa chỉ FDE: 0x0c7150 | Kích thước: 256 bytes
//   0x1a0ea4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1a0ea8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1a0eac: 39476C14  ldrb     w20, [x0, #0x1db]
//   0x1a0eb0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0377_0x1a0ea4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a0ea4ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c7150ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0378 | PC: 0x1a17d4 | FDE: 0x0c72b0 | Size: 256 bytes
// Khung tháo gỡ #0378 | Địa chỉ PC: 0x1a17d4 | Địa chỉ FDE: 0x0c72b0 | Kích thước: 256 bytes
//   0x1a17d4: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1a17d8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1a17dc: 9405F2D5  bl       #0x31e330
//   0x1a17e0: 394796A9  ldrb     w9, [x21, #0x1e5]
static inline uint64_t fde_func_0378_0x1a17d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a17d4ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c72b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0379 | PC: 0x1a1be4 | FDE: 0x0c73e0 | Size: 256 bytes
// Khung tháo gỡ #0379 | Địa chỉ PC: 0x1a1be4 | Địa chỉ FDE: 0x0c73e0 | Kích thước: 256 bytes
//   0x1a1be4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1a1be8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1a1bec: 39430C14  ldrb     w20, [x0, #0xc3]
//   0x1a1bf0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0379_0x1a1be4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a1be4ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c73e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0380 | PC: 0x1a1da8 | FDE: 0x0c7520 | Size: 256 bytes
// Khung tháo gỡ #0380 | Địa chỉ PC: 0x1a1da8 | Địa chỉ FDE: 0x0c7520 | Kích thước: 256 bytes
//   0x1a1da8: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x1a1dac: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1a1db0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1a1db4: 9406410E  bl       #0x3321ec
static inline uint64_t fde_func_0380_0x1a1da8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a1da8ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0c7520ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0381 | PC: 0x1a205c | FDE: 0x0c7638 | Size: 256 bytes
// Khung tháo gỡ #0381 | Địa chỉ PC: 0x1a205c | Địa chỉ FDE: 0x0c7638 | Kích thước: 256 bytes
//   0x1a205c: D101C3FF  sub      sp, sp, #0x70
//   0x1a2060: F9002BF4  str      x20, [sp, #0x50]
//   0x1a2064: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x1a2068: D53BD053  mrs      x19, tpidr_el0
static inline uint64_t fde_func_0381_0x1a205c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a205cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x0c7638ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0382 | PC: 0x1a235c | FDE: 0x0c7790 | Size: 256 bytes
// Khung tháo gỡ #0382 | Địa chỉ PC: 0x1a235c | Địa chỉ FDE: 0x0c7790 | Kích thước: 256 bytes
//   0x1a235c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1a2360: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1a2364: 9405F330  bl       #0x31f024
//   0x1a2368: 12000261  and      w1, w19, #1
static inline uint64_t fde_func_0382_0x1a235c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a235cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c7790ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0383 | PC: 0x1a27d8 | FDE: 0x0c78d8 | Size: 256 bytes
// Khung tháo gỡ #0383 | Địa chỉ PC: 0x1a27d8 | Địa chỉ FDE: 0x0c78d8 | Kích thước: 256 bytes
//   0x1a27d8: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x1a27dc: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1a27e0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1a27e4: AA0003F5  mov      x21, x0
static inline uint64_t fde_func_0383_0x1a27d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a27d8ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0c78d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0384 | PC: 0x1a30f8 | FDE: 0x0c7a40 | Size: 256 bytes
// Khung tháo gỡ #0384 | Địa chỉ PC: 0x1a30f8 | Địa chỉ FDE: 0x0c7a40 | Kích thước: 256 bytes
//   0x1a30f8: AA1E03E3  mov      x3, x30
//   0x1a30fc: 94062B65  bl       #0x32de90
//   0x1a3100: AA0303FE  mov      x30, x3
//   0x1a3104: A90C7BF3  stp      x19, x30, [sp, #0xc0]
static inline uint64_t fde_func_0384_0x1a30f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a30f8ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94062b65ULL) ^ 0x0c7a40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0385 | PC: 0x1a341c | FDE: 0x0c7b50 | Size: 256 bytes
// Khung tháo gỡ #0385 | Địa chỉ PC: 0x1a341c | Địa chỉ FDE: 0x0c7b50 | Kích thước: 256 bytes
//   0x1a341c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1a3420: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1a3424: 39474414  ldrb     w20, [x0, #0x1d1]
//   0x1a3428: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0385_0x1a341c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a341cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c7b50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0386 | PC: 0x1a3a4c | FDE: 0x0c7c80 | Size: 256 bytes
// Khung tháo gỡ #0386 | Địa chỉ PC: 0x1a3a4c | Địa chỉ FDE: 0x0c7c80 | Kích thước: 256 bytes
//   0x1a3a4c: AA1E03E3  mov      x3, x30
//   0x1a3a50: 9405EC8A  bl       #0x31ec78
//   0x1a3a54: AA0303FE  mov      x30, x3
//   0x1a3a58: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_0386_0x1a3a4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a3a4cULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x9405ec8aULL) ^ 0x0c7c80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0387 | PC: 0x1a3ed0 | FDE: 0x0c7dc8 | Size: 256 bytes
// Khung tháo gỡ #0387 | Địa chỉ PC: 0x1a3ed0 | Địa chỉ FDE: 0x0c7dc8 | Kích thước: 256 bytes
//   0x1a3ed0: AA1F03E1  mov      x1, xzr
//   0x1a3ed4: 14000001  b        #0x1a3ed8
//   0x1a3ed8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1a3edc: 9405E409  bl       #0x31cf00
static inline uint64_t fde_func_0387_0x1a3ed0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a3ed0ULL ^ (static_cast<uint64_t>(0xaa1f03e1ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x0c7dc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0388 | PC: 0x1a4118 | FDE: 0x0c7ed8 | Size: 256 bytes
// Khung tháo gỡ #0388 | Địa chỉ PC: 0x1a4118 | Địa chỉ FDE: 0x0c7ed8 | Kích thước: 256 bytes
//   0x1a4118: F100001F  cmp      x0, #0
//   0x1a411c: 1A9F07E8  cset     w8, ne
//   0x1a4120: F100003F  cmp      x1, #0
//   0x1a4124: 1A9F07E9  cset     w9, ne
static inline uint64_t fde_func_0388_0x1a4118(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a4118ULL ^ (static_cast<uint64_t>(0xf100001fULL) << 13);
    acc = (acc + a1 + 0x1a9f07e8ULL) ^ 0x0c7ed8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0389 | PC: 0x1a4478 | FDE: 0x0c7ff8 | Size: 256 bytes
// Khung tháo gỡ #0389 | Địa chỉ PC: 0x1a4478 | Địa chỉ FDE: 0x0c7ff8 | Kích thước: 256 bytes
//   0x1a4478: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1a447c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1a4480: B9400848  ldr      w8, [x2, #8]
//   0x1a4484: 6B01011F  cmp      w8, w1
static inline uint64_t fde_func_0389_0x1a4478(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a4478ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c7ff8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0390 | PC: 0x1a49f8 | FDE: 0x0c8128 | Size: 256 bytes
// Khung tháo gỡ #0390 | Địa chỉ PC: 0x1a49f8 | Địa chỉ FDE: 0x0c8128 | Kích thước: 256 bytes
//   0x1a49f8: D10183FF  sub      sp, sp, #0x60
//   0x1a49fc: F9001BF6  str      x22, [sp, #0x30]
//   0x1a4a00: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x1a4a04: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0390_0x1a49f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a49f8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf6ULL) ^ 0x0c8128ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0391 | PC: 0x1a4d98 | FDE: 0x0c8238 | Size: 256 bytes
// Khung tháo gỡ #0391 | Địa chỉ PC: 0x1a4d98 | Địa chỉ FDE: 0x0c8238 | Kích thước: 256 bytes
//   0x1a4d98: D100C3FF  sub      sp, sp, #0x30
//   0x1a4d9c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1a4da0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1a4da4: 9405F6C9  bl       #0x3228c8
static inline uint64_t fde_func_0391_0x1a4d98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a4d98ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0c8238ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0392 | PC: 0x1a5190 | FDE: 0x0c8360 | Size: 256 bytes
// Khung tháo gỡ #0392 | Địa chỉ PC: 0x1a5190 | Địa chỉ FDE: 0x0c8360 | Kích thước: 256 bytes
//   0x1a5190: F9400008  ldr      x8, [x0]
//   0x1a5194: B4000048  cbz      x8, #0x1a519c
//   0x1a5198: D65F03C0  ret      
//   0x1a519c: 14000012  b        #0x1a51e4
static inline uint64_t fde_func_0392_0x1a5190(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a5190ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xb4000048ULL) ^ 0x0c8360ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0393 | PC: 0x1a5330 | FDE: 0x0c8470 | Size: 256 bytes
// Khung tháo gỡ #0393 | Địa chỉ PC: 0x1a5330 | Địa chỉ FDE: 0x0c8470 | Kích thước: 256 bytes
//   0x1a5330: D10083FF  sub      sp, sp, #0x20
//   0x1a5334: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1a5338: F9400008  ldr      x8, [x0]
//   0x1a533c: B5000388  cbnz     x8, #0x1a53ac
static inline uint64_t fde_func_0393_0x1a5330(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a5330ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0c8470ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0394 | PC: 0x1a5640 | FDE: 0x0c8580 | Size: 256 bytes
// Khung tháo gỡ #0394 | Địa chỉ PC: 0x1a5640 | Địa chỉ FDE: 0x0c8580 | Kích thước: 256 bytes
//   0x1a5640: D101C3FF  sub      sp, sp, #0x70
//   0x1a5644: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x1a5648: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x1a564c: 9405F29C  bl       #0x3220bc
static inline uint64_t fde_func_0394_0x1a5640(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a5640ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90553f5ULL) ^ 0x0c8580ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0395 | PC: 0x1a59e0 | FDE: 0x0c86a8 | Size: 256 bytes
// Khung tháo gỡ #0395 | Địa chỉ PC: 0x1a59e0 | Địa chỉ FDE: 0x0c86a8 | Kích thước: 256 bytes
//   0x1a59e0: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1a59e4: B0000E28  adrp     x8, #0x36a000
//   0x1a59e8: 912F8108  add      x8, x8, #0xbe0
//   0x1a59ec: 08DFFD08  ldarb    w8, [x8]
static inline uint64_t fde_func_0395_0x1a59e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a59e0ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb0000e28ULL) ^ 0x0c86a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0396 | PC: 0x1a5e70 | FDE: 0x0c87c0 | Size: 256 bytes
// Khung tháo gỡ #0396 | Địa chỉ PC: 0x1a5e70 | Địa chỉ FDE: 0x0c87c0 | Kích thước: 256 bytes
//   0x1a5e70: 39409808  ldrb     w8, [x0, #0x26]
//   0x1a5e74: AA1E03E1  mov      x1, x30
//   0x1a5e78: 94063802  bl       #0x333e80
//   0x1a5e7c: AA0103FE  mov      x30, x1
static inline uint64_t fde_func_0396_0x1a5e70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a5e70ULL ^ (static_cast<uint64_t>(0x39409808ULL) << 13);
    acc = (acc + a1 + 0xaa1e03e1ULL) ^ 0x0c87c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0397 | PC: 0x1a64d8 | FDE: 0x0c8908 | Size: 256 bytes [_ZN4lynx9starlight16ComputedCSSStyleC2Efd]
// Khung tháo gỡ #0397 | Địa chỉ PC: 0x1a64d8 | Địa chỉ FDE: 0x0c8908 | Kích thước: 256 bytes
//   0x1a64d8: D10143FF  sub      sp, sp, #0x50
//   0x1a64dc: 6D0223E9  stp      d9, d8, [sp, #0x20]
//   0x1a64e0: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x1a64e4: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0397_0x1a64d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a64d8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0x6d0223e9ULL) ^ 0x0c8908ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0398 | PC: 0x1a66c4 | FDE: 0x0c8980 | Size: 256 bytes [_ZN4lynx9starlight16ComputedCSSStyle8SetValueENS_4tasm13CSSPropertyIDERKNS2_8CSSValueEb]
// Khung tháo gỡ #0398 | Địa chỉ PC: 0x1a66c4 | Địa chỉ FDE: 0x0c8980 | Kích thước: 256 bytes
//   0x1a66c4: D10283FF  sub      sp, sp, #0xa0
//   0x1a66c8: A9075BF7  stp      x23, x22, [sp, #0x70]
//   0x1a66cc: A90853F5  stp      x21, x20, [sp, #0x80]
//   0x1a66d0: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_0398_0x1a66c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a66c4ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9075bf7ULL) ^ 0x0c8980ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0399 | PC: 0x1a6cec | FDE: 0x0c8a48 | Size: 256 bytes
// Khung tháo gỡ #0399 | Địa chỉ PC: 0x1a6cec | Địa chỉ FDE: 0x0c8a48 | Kích thước: 256 bytes
//   0x1a6cec: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1a6cf0: 94064603  bl       #0x3384fc
//   0x1a6cf4: 9405DB53  bl       #0x31da40
//   0x1a6cf8: 940668A6  bl       #0x340f90
static inline uint64_t fde_func_0399_0x1a6cec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a6cecULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94064603ULL) ^ 0x0c8a48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Shard 1 Dispatcher / Bộ điều phối phân mảnh 1
uint64_t execute_fde_shard_1(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 0: return fde_func_0000_0x14c03c(a0, a1);
        case 1: return fde_func_0001_0x14c048(a0, a1);
        case 2: return fde_func_0002_0x14c0c4(a0, a1);
        case 3: return fde_func_0003_0x14c1b4(a0, a1);
        case 4: return fde_func_0004_0x14c228(a0, a1);
        case 5: return fde_func_0005_0x14c27c(a0, a1);
        case 6: return fde_func_0006_0x14c368(a0, a1);
        case 7: return fde_func_0007_0x14c42c(a0, a1);
        case 8: return fde_func_0008_0x14c45c(a0, a1);
        case 9: return fde_func_0009_0x14c4a8(a0, a1);
        case 10: return fde_func_0010_0x14c4d8(a0, a1);
        case 11: return fde_func_0011_0x14c4f4(a0, a1);
        case 12: return fde_func_0012_0x14c54c(a0, a1);
        case 13: return fde_func_0013_0x14c594(a0, a1);
        case 14: return fde_func_0014_0x14c5ac(a0, a1);
        case 15: return fde_func_0015_0x14c5ec(a0, a1);
        case 16: return fde_func_0016_0x14c6fc(a0, a1);
        case 17: return fde_func_0017_0x14c790(a0, a1);
        case 18: return fde_func_0018_0x14c7a4(a0, a1);
        case 19: return fde_func_0019_0x14c7b8(a0, a1);
        case 20: return fde_func_0020_0x14c7cc(a0, a1);
        case 21: return fde_func_0021_0x14c7e4(a0, a1);
        case 22: return fde_func_0022_0x14c7f8(a0, a1);
        case 23: return fde_func_0023_0x14c80c(a0, a1);
        case 24: return fde_func_0024_0x14c820(a0, a1);
        case 25: return fde_func_0025_0x14c834(a0, a1);
        case 26: return fde_func_0026_0x14c848(a0, a1);
        case 27: return fde_func_0027_0x14c860(a0, a1);
        case 28: return fde_func_0028_0x14c890(a0, a1);
        case 29: return fde_func_0029_0x14c8ac(a0, a1);
        case 30: return fde_func_0030_0x14c8dc(a0, a1);
        case 31: return fde_func_0031_0x14c8f8(a0, a1);
        case 32: return fde_func_0032_0x14c904(a0, a1);
        case 33: return fde_func_0033_0x14c934(a0, a1);
        case 34: return fde_func_0034_0x14c99c(a0, a1);
        case 35: return fde_func_0035_0x14c9d8(a0, a1);
        case 36: return fde_func_0036_0x14ca58(a0, a1);
        case 37: return fde_func_0037_0x14cdf0(a0, a1);
        case 38: return fde_func_0038_0x14d3a4(a0, a1);
        case 39: return fde_func_0039_0x14d468(a0, a1);
        case 40: return fde_func_0040_0x14d4a4(a0, a1);
        case 41: return fde_func_0041_0x14d570(a0, a1);
        case 42: return fde_func_0042_0x14d634(a0, a1);
        case 43: return fde_func_0043_0x14d790(a0, a1);
        case 44: return fde_func_0044_0x14d7cc(a0, a1);
        case 45: return fde_func_0045_0x14d884(a0, a1);
        case 46: return fde_func_0046_0x14d8f4(a0, a1);
        case 47: return fde_func_0047_0x14d930(a0, a1);
        case 48: return fde_func_0048_0x14da50(a0, a1);
        case 49: return fde_func_0049_0x14dac4(a0, a1);
        case 50: return fde_func_0050_0x14db00(a0, a1);
        case 51: return fde_func_0051_0x14dc24(a0, a1);
        case 52: return fde_func_0052_0x14dc94(a0, a1);
        case 53: return fde_func_0053_0x14dcb4(a0, a1);
        case 54: return fde_func_0054_0x14dcec(a0, a1);
        case 55: return fde_func_0055_0x14dd08(a0, a1);
        case 56: return fde_func_0056_0x14dd24(a0, a1);
        case 57: return fde_func_0057_0x14dd84(a0, a1);
        case 58: return fde_func_0058_0x14de08(a0, a1);
        case 59: return fde_func_0059_0x14de8c(a0, a1);
        case 60: return fde_func_0060_0x14df10(a0, a1);
        case 61: return fde_func_0061_0x14df94(a0, a1);
        case 62: return fde_func_0062_0x14e034(a0, a1);
        case 63: return fde_func_0063_0x14e0fc(a0, a1);
        case 64: return fde_func_0064_0x14e19c(a0, a1);
        case 65: return fde_func_0065_0x14e228(a0, a1);
        case 66: return fde_func_0066_0x14e2c8(a0, a1);
        case 67: return fde_func_0067_0x14e354(a0, a1);
        case 68: return fde_func_0068_0x14e3f4(a0, a1);
        case 69: return fde_func_0069_0x14e480(a0, a1);
        case 70: return fde_func_0070_0x14e534(a0, a1);
        case 71: return fde_func_0071_0x14e5d4(a0, a1);
        case 72: return fde_func_0072_0x14e670(a0, a1);
        case 73: return fde_func_0073_0x14e674(a0, a1);
        case 74: return fde_func_0074_0x14eadc(a0, a1);
        case 75: return fde_func_0075_0x14ec40(a0, a1);
        case 76: return fde_func_0076_0x14ec84(a0, a1);
        case 77: return fde_func_0077_0x14ede8(a0, a1);
        case 78: return fde_func_0078_0x14eea4(a0, a1);
        case 79: return fde_func_0079_0x14f040(a0, a1);
        case 80: return fde_func_0080_0x14f118(a0, a1);
        case 81: return fde_func_0081_0x14f314(a0, a1);
        case 82: return fde_func_0082_0x14f57c(a0, a1);
        case 83: return fde_func_0083_0x14f6d4(a0, a1);
        case 84: return fde_func_0084_0x14f794(a0, a1);
        case 85: return fde_func_0085_0x14fe44(a0, a1);
        case 86: return fde_func_0086_0x15043c(a0, a1);
        case 87: return fde_func_0087_0x150444(a0, a1);
        case 88: return fde_func_0088_0x150620(a0, a1);
        case 89: return fde_func_0089_0x15072c(a0, a1);
        case 90: return fde_func_0090_0x150840(a0, a1);
        case 91: return fde_func_0091_0x150c9c(a0, a1);
        case 92: return fde_func_0092_0x150cb8(a0, a1);
        case 93: return fde_func_0093_0x150d3c(a0, a1);
        case 94: return fde_func_0094_0x150d58(a0, a1);
        case 95: return fde_func_0095_0x150d74(a0, a1);
        case 96: return fde_func_0096_0x15153c(a0, a1);
        case 97: return fde_func_0097_0x151770(a0, a1);
        case 98: return fde_func_0098_0x151b78(a0, a1);
        case 99: return fde_func_0099_0x151ba8(a0, a1);
        case 100: return fde_func_0100_0x151bc0(a0, a1);
        case 101: return fde_func_0101_0x151c04(a0, a1);
        case 102: return fde_func_0102_0x151c40(a0, a1);
        case 103: return fde_func_0103_0x151c84(a0, a1);
        case 104: return fde_func_0104_0x151cc0(a0, a1);
        case 105: return fde_func_0105_0x151dfc(a0, a1);
        case 106: return fde_func_0106_0x151efc(a0, a1);
        case 107: return fde_func_0107_0x151fdc(a0, a1);
        case 108: return fde_func_0108_0x152084(a0, a1);
        case 109: return fde_func_0109_0x15215c(a0, a1);
        case 110: return fde_func_0110_0x1522a4(a0, a1);
        case 111: return fde_func_0111_0x1523f0(a0, a1);
        case 112: return fde_func_0112_0x1525f8(a0, a1);
        case 113: return fde_func_0113_0x1528e4(a0, a1);
        case 114: return fde_func_0114_0x1528fc(a0, a1);
        case 115: return fde_func_0115_0x1529a0(a0, a1);
        case 116: return fde_func_0116_0x152fb0(a0, a1);
        case 117: return fde_func_0117_0x153d78(a0, a1);
        case 118: return fde_func_0118_0x154c74(a0, a1);
        case 119: return fde_func_0119_0x15539c(a0, a1);
        case 120: return fde_func_0120_0x15551c(a0, a1);
        case 121: return fde_func_0121_0x1565a4(a0, a1);
        case 122: return fde_func_0122_0x156968(a0, a1);
        case 123: return fde_func_0123_0x156994(a0, a1);
        case 124: return fde_func_0124_0x1569a4(a0, a1);
        case 125: return fde_func_0125_0x1569ac(a0, a1);
        case 126: return fde_func_0126_0x15737c(a0, a1);
        case 127: return fde_func_0127_0x157674(a0, a1);
        case 128: return fde_func_0128_0x157a00(a0, a1);
        case 129: return fde_func_0129_0x157a48(a0, a1);
        case 130: return fde_func_0130_0x157aec(a0, a1);
        case 131: return fde_func_0131_0x157b98(a0, a1);
        case 132: return fde_func_0132_0x157ea4(a0, a1);
        case 133: return fde_func_0133_0x15811c(a0, a1);
        case 134: return fde_func_0134_0x158198(a0, a1);
        case 135: return fde_func_0135_0x158214(a0, a1);
        case 136: return fde_func_0136_0x158284(a0, a1);
        case 137: return fde_func_0137_0x158370(a0, a1);
        case 138: return fde_func_0138_0x158408(a0, a1);
        case 139: return fde_func_0139_0x1584f0(a0, a1);
        case 140: return fde_func_0140_0x158574(a0, a1);
        case 141: return fde_func_0141_0x158608(a0, a1);
        case 142: return fde_func_0142_0x158700(a0, a1);
        case 143: return fde_func_0143_0x15876c(a0, a1);
        case 144: return fde_func_0144_0x1587f8(a0, a1);
        case 145: return fde_func_0145_0x158934(a0, a1);
        case 146: return fde_func_0146_0x159014(a0, a1);
        case 147: return fde_func_0147_0x159b38(a0, a1);
        case 148: return fde_func_0148_0x159b98(a0, a1);
        case 149: return fde_func_0149_0x159d60(a0, a1);
        case 150: return fde_func_0150_0x15a0b4(a0, a1);
        case 151: return fde_func_0151_0x15a1f4(a0, a1);
        case 152: return fde_func_0152_0x15a290(a0, a1);
        case 153: return fde_func_0153_0x15a6c8(a0, a1);
        case 154: return fde_func_0154_0x15a934(a0, a1);
        case 155: return fde_func_0155_0x15a9cc(a0, a1);
        case 156: return fde_func_0156_0x15ab9c(a0, a1);
        case 157: return fde_func_0157_0x15b184(a0, a1);
        case 158: return fde_func_0158_0x15b748(a0, a1);
        case 159: return fde_func_0159_0x15b99c(a0, a1);
        case 160: return fde_func_0160_0x15b9d8(a0, a1);
        case 161: return fde_func_0161_0x15bd28(a0, a1);
        case 162: return fde_func_0162_0x15bed0(a0, a1);
        case 163: return fde_func_0163_0x15bf08(a0, a1);
        case 164: return fde_func_0164_0x15c10c(a0, a1);
        case 165: return fde_func_0165_0x15c1b8(a0, a1);
        case 166: return fde_func_0166_0x15c1c8(a0, a1);
        case 167: return fde_func_0167_0x15c418(a0, a1);
        case 168: return fde_func_0168_0x15ca34(a0, a1);
        case 169: return fde_func_0169_0x15cdf0(a0, a1);
        case 170: return fde_func_0170_0x15d1b0(a0, a1);
        case 171: return fde_func_0171_0x15d61c(a0, a1);
        case 172: return fde_func_0172_0x15dadc(a0, a1);
        case 173: return fde_func_0173_0x15de9c(a0, a1);
        case 174: return fde_func_0174_0x15e558(a0, a1);
        case 175: return fde_func_0175_0x15e8f0(a0, a1);
        case 176: return fde_func_0176_0x15eebc(a0, a1);
        case 177: return fde_func_0177_0x15f614(a0, a1);
        case 178: return fde_func_0178_0x15fbd8(a0, a1);
        case 179: return fde_func_0179_0x160108(a0, a1);
        case 180: return fde_func_0180_0x1602ec(a0, a1);
        case 181: return fde_func_0181_0x1605dc(a0, a1);
        case 182: return fde_func_0182_0x1614dc(a0, a1);
        case 183: return fde_func_0183_0x1624b8(a0, a1);
        case 184: return fde_func_0184_0x162fa0(a0, a1);
        case 185: return fde_func_0185_0x1634a4(a0, a1);
        case 186: return fde_func_0186_0x1638d4(a0, a1);
        case 187: return fde_func_0187_0x163d5c(a0, a1);
        case 188: return fde_func_0188_0x163ffc(a0, a1);
        case 189: return fde_func_0189_0x1641a8(a0, a1);
        case 190: return fde_func_0190_0x164408(a0, a1);
        case 191: return fde_func_0191_0x164508(a0, a1);
        case 192: return fde_func_0192_0x164b58(a0, a1);
        case 193: return fde_func_0193_0x164d74(a0, a1);
        case 194: return fde_func_0194_0x1665a4(a0, a1);
        case 195: return fde_func_0195_0x166a98(a0, a1);
        case 196: return fde_func_0196_0x166e64(a0, a1);
        case 197: return fde_func_0197_0x167030(a0, a1);
        case 198: return fde_func_0198_0x16819c(a0, a1);
        case 199: return fde_func_0199_0x16845c(a0, a1);
        case 200: return fde_func_0200_0x168a8c(a0, a1);
        case 201: return fde_func_0201_0x168c84(a0, a1);
        case 202: return fde_func_0202_0x168ec8(a0, a1);
        case 203: return fde_func_0203_0x169228(a0, a1);
        case 204: return fde_func_0204_0x1695cc(a0, a1);
        case 205: return fde_func_0205_0x1698c0(a0, a1);
        case 206: return fde_func_0206_0x169a2c(a0, a1);
        case 207: return fde_func_0207_0x169ee8(a0, a1);
        case 208: return fde_func_0208_0x16a174(a0, a1);
        case 209: return fde_func_0209_0x16a4c8(a0, a1);
        case 210: return fde_func_0210_0x16a71c(a0, a1);
        case 211: return fde_func_0211_0x16ac00(a0, a1);
        case 212: return fde_func_0212_0x16b310(a0, a1);
        case 213: return fde_func_0213_0x16b9e4(a0, a1);
        case 214: return fde_func_0214_0x16bda8(a0, a1);
        case 215: return fde_func_0215_0x16c610(a0, a1);
        case 216: return fde_func_0216_0x16c8fc(a0, a1);
        case 217: return fde_func_0217_0x16cf70(a0, a1);
        case 218: return fde_func_0218_0x16d098(a0, a1);
        case 219: return fde_func_0219_0x16d478(a0, a1);
        case 220: return fde_func_0220_0x16d764(a0, a1);
        case 221: return fde_func_0221_0x16ddac(a0, a1);
        case 222: return fde_func_0222_0x16e588(a0, a1);
        case 223: return fde_func_0223_0x16e9e4(a0, a1);
        case 224: return fde_func_0224_0x16ed58(a0, a1);
        case 225: return fde_func_0225_0x16f374(a0, a1);
        case 226: return fde_func_0226_0x16f66c(a0, a1);
        case 227: return fde_func_0227_0x16fd1c(a0, a1);
        case 228: return fde_func_0228_0x16fefc(a0, a1);
        case 229: return fde_func_0229_0x1704c0(a0, a1);
        case 230: return fde_func_0230_0x170f50(a0, a1);
        case 231: return fde_func_0231_0x17156c(a0, a1);
        case 232: return fde_func_0232_0x171780(a0, a1);
        case 233: return fde_func_0233_0x171e34(a0, a1);
        case 234: return fde_func_0234_0x1725f8(a0, a1);
        case 235: return fde_func_0235_0x172dd4(a0, a1);
        case 236: return fde_func_0236_0x173038(a0, a1);
        case 237: return fde_func_0237_0x17356c(a0, a1);
        case 238: return fde_func_0238_0x173914(a0, a1);
        case 239: return fde_func_0239_0x173cf8(a0, a1);
        case 240: return fde_func_0240_0x174380(a0, a1);
        case 241: return fde_func_0241_0x174a1c(a0, a1);
        case 242: return fde_func_0242_0x174f7c(a0, a1);
        case 243: return fde_func_0243_0x1759a8(a0, a1);
        case 244: return fde_func_0244_0x175c38(a0, a1);
        case 245: return fde_func_0245_0x17622c(a0, a1);
        case 246: return fde_func_0246_0x17699c(a0, a1);
        case 247: return fde_func_0247_0x176a2c(a0, a1);
        case 248: return fde_func_0248_0x176c38(a0, a1);
        case 249: return fde_func_0249_0x176c5c(a0, a1);
        case 250: return fde_func_0250_0x176c80(a0, a1);
        case 251: return fde_func_0251_0x176ef4(a0, a1);
        case 252: return fde_func_0252_0x1771cc(a0, a1);
        case 253: return fde_func_0253_0x177454(a0, a1);
        case 254: return fde_func_0254_0x1777fc(a0, a1);
        case 255: return fde_func_0255_0x177b6c(a0, a1);
        case 256: return fde_func_0256_0x177c38(a0, a1);
        case 257: return fde_func_0257_0x178440(a0, a1);
        case 258: return fde_func_0258_0x178698(a0, a1);
        case 259: return fde_func_0259_0x178a20(a0, a1);
        case 260: return fde_func_0260_0x178e34(a0, a1);
        case 261: return fde_func_0261_0x179058(a0, a1);
        case 262: return fde_func_0262_0x1794e4(a0, a1);
        case 263: return fde_func_0263_0x179980(a0, a1);
        case 264: return fde_func_0264_0x179f64(a0, a1);
        case 265: return fde_func_0265_0x17a100(a0, a1);
        case 266: return fde_func_0266_0x17a36c(a0, a1);
        case 267: return fde_func_0267_0x17a524(a0, a1);
        case 268: return fde_func_0268_0x17a8bc(a0, a1);
        case 269: return fde_func_0269_0x17adcc(a0, a1);
        case 270: return fde_func_0270_0x17b240(a0, a1);
        case 271: return fde_func_0271_0x17b648(a0, a1);
        case 272: return fde_func_0272_0x17b7c8(a0, a1);
        case 273: return fde_func_0273_0x17ca18(a0, a1);
        case 274: return fde_func_0274_0x17ce1c(a0, a1);
        case 275: return fde_func_0275_0x17ce60(a0, a1);
        case 276: return fde_func_0276_0x17ce84(a0, a1);
        case 277: return fde_func_0277_0x17cf4c(a0, a1);
        case 278: return fde_func_0278_0x17cf98(a0, a1);
        case 279: return fde_func_0279_0x17d2a8(a0, a1);
        case 280: return fde_func_0280_0x17dcd0(a0, a1);
        case 281: return fde_func_0281_0x17dff8(a0, a1);
        case 282: return fde_func_0282_0x17e5d0(a0, a1);
        case 283: return fde_func_0283_0x17f138(a0, a1);
        case 284: return fde_func_0284_0x17fa4c(a0, a1);
        case 285: return fde_func_0285_0x180550(a0, a1);
        case 286: return fde_func_0286_0x1813e0(a0, a1);
        case 287: return fde_func_0287_0x18175c(a0, a1);
        case 288: return fde_func_0288_0x181944(a0, a1);
        case 289: return fde_func_0289_0x181c60(a0, a1);
        case 290: return fde_func_0290_0x181e90(a0, a1);
        case 291: return fde_func_0291_0x182188(a0, a1);
        case 292: return fde_func_0292_0x182418(a0, a1);
        case 293: return fde_func_0293_0x1825b4(a0, a1);
        case 294: return fde_func_0294_0x1825c8(a0, a1);
        case 295: return fde_func_0295_0x183424(a0, a1);
        case 296: return fde_func_0296_0x184ec8(a0, a1);
        case 297: return fde_func_0297_0x184fb0(a0, a1);
        case 298: return fde_func_0298_0x1850a4(a0, a1);
        case 299: return fde_func_0299_0x1850c4(a0, a1);
        case 300: return fde_func_0300_0x185214(a0, a1);
        case 301: return fde_func_0301_0x186784(a0, a1);
        case 302: return fde_func_0302_0x186894(a0, a1);
        case 303: return fde_func_0303_0x186a58(a0, a1);
        case 304: return fde_func_0304_0x186ce4(a0, a1);
        case 305: return fde_func_0305_0x187110(a0, a1);
        case 306: return fde_func_0306_0x18711c(a0, a1);
        case 307: return fde_func_0307_0x187208(a0, a1);
        case 308: return fde_func_0308_0x187678(a0, a1);
        case 309: return fde_func_0309_0x18779c(a0, a1);
        case 310: return fde_func_0310_0x18797c(a0, a1);
        case 311: return fde_func_0311_0x187ce4(a0, a1);
        case 312: return fde_func_0312_0x188328(a0, a1);
        case 313: return fde_func_0313_0x188400(a0, a1);
        case 314: return fde_func_0314_0x188470(a0, a1);
        case 315: return fde_func_0315_0x1889bc(a0, a1);
        case 316: return fde_func_0316_0x188b78(a0, a1);
        case 317: return fde_func_0317_0x188ee0(a0, a1);
        case 318: return fde_func_0318_0x1897a4(a0, a1);
        case 319: return fde_func_0319_0x189c80(a0, a1);
        case 320: return fde_func_0320_0x18a000(a0, a1);
        case 321: return fde_func_0321_0x18a6c0(a0, a1);
        case 322: return fde_func_0322_0x18af10(a0, a1);
        case 323: return fde_func_0323_0x18b1ac(a0, a1);
        case 324: return fde_func_0324_0x18bb58(a0, a1);
        case 325: return fde_func_0325_0x18bf28(a0, a1);
        case 326: return fde_func_0326_0x18cccc(a0, a1);
        case 327: return fde_func_0327_0x18d56c(a0, a1);
        case 328: return fde_func_0328_0x18e568(a0, a1);
        case 329: return fde_func_0329_0x18f144(a0, a1);
        case 330: return fde_func_0330_0x18fb74(a0, a1);
        case 331: return fde_func_0331_0x190848(a0, a1);
        case 332: return fde_func_0332_0x190b14(a0, a1);
        case 333: return fde_func_0333_0x190e48(a0, a1);
        case 334: return fde_func_0334_0x1918d8(a0, a1);
        case 335: return fde_func_0335_0x1921ac(a0, a1);
        case 336: return fde_func_0336_0x192590(a0, a1);
        case 337: return fde_func_0337_0x192d2c(a0, a1);
        case 338: return fde_func_0338_0x193624(a0, a1);
        case 339: return fde_func_0339_0x193c14(a0, a1);
        case 340: return fde_func_0340_0x1940d8(a0, a1);
        case 341: return fde_func_0341_0x194ba0(a0, a1);
        case 342: return fde_func_0342_0x196120(a0, a1);
        case 343: return fde_func_0343_0x196d54(a0, a1);
        case 344: return fde_func_0344_0x197ae4(a0, a1);
        case 345: return fde_func_0345_0x198928(a0, a1);
        case 346: return fde_func_0346_0x1994b4(a0, a1);
        case 347: return fde_func_0347_0x199694(a0, a1);
        case 348: return fde_func_0348_0x1997a4(a0, a1);
        case 349: return fde_func_0349_0x199c50(a0, a1);
        case 350: return fde_func_0350_0x19a08c(a0, a1);
        case 351: return fde_func_0351_0x19a860(a0, a1);
        case 352: return fde_func_0352_0x19aea8(a0, a1);
        case 353: return fde_func_0353_0x19b244(a0, a1);
        case 354: return fde_func_0354_0x19b384(a0, a1);
        case 355: return fde_func_0355_0x19b414(a0, a1);
        case 356: return fde_func_0356_0x19bab0(a0, a1);
        case 357: return fde_func_0357_0x19bf18(a0, a1);
        case 358: return fde_func_0358_0x19c0b8(a0, a1);
        case 359: return fde_func_0359_0x19c128(a0, a1);
        case 360: return fde_func_0360_0x19c1d4(a0, a1);
        case 361: return fde_func_0361_0x19c3c8(a0, a1);
        case 362: return fde_func_0362_0x19c8a8(a0, a1);
        case 363: return fde_func_0363_0x19cda0(a0, a1);
        case 364: return fde_func_0364_0x19d20c(a0, a1);
        case 365: return fde_func_0365_0x19d460(a0, a1);
        case 366: return fde_func_0366_0x19d618(a0, a1);
        case 367: return fde_func_0367_0x19d998(a0, a1);
        case 368: return fde_func_0368_0x19ea80(a0, a1);
        case 369: return fde_func_0369_0x19efc8(a0, a1);
        case 370: return fde_func_0370_0x19f2a8(a0, a1);
        case 371: return fde_func_0371_0x19f478(a0, a1);
        case 372: return fde_func_0372_0x19f7e0(a0, a1);
        case 373: return fde_func_0373_0x19fa94(a0, a1);
        case 374: return fde_func_0374_0x1a054c(a0, a1);
        case 375: return fde_func_0375_0x1a0aec(a0, a1);
        case 376: return fde_func_0376_0x1a0c64(a0, a1);
        case 377: return fde_func_0377_0x1a0ea4(a0, a1);
        case 378: return fde_func_0378_0x1a17d4(a0, a1);
        case 379: return fde_func_0379_0x1a1be4(a0, a1);
        case 380: return fde_func_0380_0x1a1da8(a0, a1);
        case 381: return fde_func_0381_0x1a205c(a0, a1);
        case 382: return fde_func_0382_0x1a235c(a0, a1);
        case 383: return fde_func_0383_0x1a27d8(a0, a1);
        case 384: return fde_func_0384_0x1a30f8(a0, a1);
        case 385: return fde_func_0385_0x1a341c(a0, a1);
        case 386: return fde_func_0386_0x1a3a4c(a0, a1);
        case 387: return fde_func_0387_0x1a3ed0(a0, a1);
        case 388: return fde_func_0388_0x1a4118(a0, a1);
        case 389: return fde_func_0389_0x1a4478(a0, a1);
        case 390: return fde_func_0390_0x1a49f8(a0, a1);
        case 391: return fde_func_0391_0x1a4d98(a0, a1);
        case 392: return fde_func_0392_0x1a5190(a0, a1);
        case 393: return fde_func_0393_0x1a5330(a0, a1);
        case 394: return fde_func_0394_0x1a5640(a0, a1);
        case 395: return fde_func_0395_0x1a59e0(a0, a1);
        case 396: return fde_func_0396_0x1a5e70(a0, a1);
        case 397: return fde_func_0397_0x1a64d8(a0, a1);
        case 398: return fde_func_0398_0x1a66c4(a0, a1);
        case 399: return fde_func_0399_0x1a6cec(a0, a1);
        default: return 0ULL;
    }
}

} // namespace lynx