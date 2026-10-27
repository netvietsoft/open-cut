// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 5/5 for liblynx.so
// Phân mảnh Khung Tháo Gỡ (FDE) AArch64 C++17 sạch 5/5 cho liblynx.so
// Covers representative FDE indices [1600 .. 1999] out of 21,675 total FDEs
// Bao phủ chỉ số FDE đại diện [1600 .. 1999] trên tổng số 21.675 FDE
// ============================================================================
#include "lynx_core.h"

namespace lynx {

// FDE #1600 | PC: 0x317a48 | FDE: 0x10ea40 | Size: 256 bytes
// Khung tháo gỡ #1600 | Địa chỉ PC: 0x317a48 | Địa chỉ FDE: 0x10ea40 | Kích thước: 256 bytes
//   0x317a48: D10283FF  sub      sp, sp, #0xa0
//   0x317a4c: A9075BF7  stp      x23, x22, [sp, #0x70]
//   0x317a50: A90853F5  stp      x21, x20, [sp, #0x80]
//   0x317a54: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_1600_0x317a48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x317a48ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9075bf7ULL) ^ 0x10ea40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1601 | PC: 0x317e64 | FDE: 0x10eb60 | Size: 256 bytes
// Khung tháo gỡ #1601 | Địa chỉ PC: 0x317e64 | Địa chỉ FDE: 0x10eb60 | Kích thước: 256 bytes
//   0x317e64: FC1F0FE8  str      d8, [sp, #-0x10]!
//   0x317e68: F90007FE  str      x30, [sp, #8]
//   0x317e6c: 94003D69  bl       #0x327410
//   0x317e70: 54000121  b.ne     #0x317e94
static inline uint64_t fde_func_1601_0x317e64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x317e64ULL ^ (static_cast<uint64_t>(0xfc1f0fe8ULL) << 13);
    acc = (acc + a1 + 0xf90007feULL) ^ 0x10eb60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1602 | PC: 0x318108 | FDE: 0x10ec88 | Size: 256 bytes
// Khung tháo gỡ #1602 | Địa chỉ PC: 0x318108 | Địa chỉ FDE: 0x10ec88 | Kích thước: 256 bytes
//   0x318108: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x31810c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x318110: 940037E1  bl       #0x326094
//   0x318114: 54000161  b.ne     #0x318140
static inline uint64_t fde_func_1602_0x318108(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x318108ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x10ec88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1603 | PC: 0x318730 | FDE: 0x10edd0 | Size: 256 bytes
// Khung tháo gỡ #1603 | Địa chỉ PC: 0x318730 | Địa chỉ FDE: 0x10edd0 | Kích thước: 256 bytes
//   0x318730: D10303FF  sub      sp, sp, #0xc0
//   0x318734: A9095BF7  stp      x23, x22, [sp, #0x90]
//   0x318738: A90A53F5  stp      x21, x20, [sp, #0xa0]
//   0x31873c: A90B7BF3  stp      x19, x30, [sp, #0xb0]
static inline uint64_t fde_func_1603_0x318730(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x318730ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9095bf7ULL) ^ 0x10edd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1604 | PC: 0x318cfc | FDE: 0x10ef10 | Size: 256 bytes
// Khung tháo gỡ #1604 | Địa chỉ PC: 0x318cfc | Địa chỉ FDE: 0x10ef10 | Kích thước: 256 bytes
//   0x318cfc: D10143FF  sub      sp, sp, #0x50
//   0x318d00: F9001BF4  str      x20, [sp, #0x30]
//   0x318d04: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x318d08: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1604_0x318cfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x318cfcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf4ULL) ^ 0x10ef10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1605 | PC: 0x318dfc | FDE: 0x10ef70 | Size: 256 bytes [_ZN4lynx3pub10ValueUtils24ConvertValueToLepusValueERKNS0_5ValueEPNSt6__ndk16vectorINS5_10unique_ptrIS2_NS5_14default_deleteIS2_EEEENS5_9allocatorISA_EEEEi]
// Khung tháo gỡ #1605 | Địa chỉ PC: 0x318dfc | Địa chỉ FDE: 0x10ef70 | Kích thước: 256 bytes
//   0x318dfc: AA1E03E3  mov      x3, x30
//   0x318e00: 940014F7  bl       #0x31e1dc
//   0x318e04: AA0303FE  mov      x30, x3
//   0x318e08: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_1605_0x318dfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x318dfcULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x940014f7ULL) ^ 0x10ef70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1606 | PC: 0x3197e4 | FDE: 0x10f068 | Size: 256 bytes
// Khung tháo gỡ #1606 | Địa chỉ PC: 0x3197e4 | Địa chỉ FDE: 0x10f068 | Kích thước: 256 bytes
//   0x3197e4: D10143FF  sub      sp, sp, #0x50
//   0x3197e8: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x3197ec: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x3197f0: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1606_0x3197e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3197e4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x10f068ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1607 | PC: 0x31a2dc | FDE: 0x10f1c8 | Size: 256 bytes
// Khung tháo gỡ #1607 | Địa chỉ PC: 0x31a2dc | Địa chỉ FDE: 0x10f1c8 | Kích thước: 256 bytes
//   0x31a2dc: D10443FF  sub      sp, sp, #0x110
//   0x31a2e0: F9007BFC  str      x28, [sp, #0xf0]
//   0x31a2e4: A9107BF3  stp      x19, x30, [sp, #0x100]
//   0x31a2e8: 94000E45  bl       #0x31dbfc
static inline uint64_t fde_func_1607_0x31a2dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31a2dcULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xf9007bfcULL) ^ 0x10f1c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1608 | PC: 0x31a6cc | FDE: 0x10f300 | Size: 256 bytes
// Khung tháo gỡ #1608 | Địa chỉ PC: 0x31a6cc | Địa chỉ FDE: 0x10f300 | Kích thước: 256 bytes
//   0x31a6cc: D10283FF  sub      sp, sp, #0xa0
//   0x31a6d0: F90043F4  str      x20, [sp, #0x80]
//   0x31a6d4: A9097BF3  stp      x19, x30, [sp, #0x90]
//   0x31a6d8: 94001AB8  bl       #0x3211b8
static inline uint64_t fde_func_1608_0x31a6cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31a6ccULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90043f4ULL) ^ 0x10f300ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1609 | PC: 0x31aa7c | FDE: 0x10f438 | Size: 256 bytes
// Khung tháo gỡ #1609 | Địa chỉ PC: 0x31aa7c | Địa chỉ FDE: 0x10f438 | Kích thước: 256 bytes
//   0x31aa7c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x31aa80: A9420413  ldp      x19, x1, [x0, #0x20]
//   0x31aa84: 94007536  bl       #0x337f5c
//   0x31aa88: 940005A3  bl       #0x31c114
static inline uint64_t fde_func_1609_0x31aa7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31aa7cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xa9420413ULL) ^ 0x10f438ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1610 | PC: 0x31abf8 | FDE: 0x10f540 | Size: 256 bytes
// Khung tháo gỡ #1610 | Địa chỉ PC: 0x31abf8 | Địa chỉ FDE: 0x10f540 | Kích thước: 256 bytes
//   0x31abf8: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x31abfc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x31ac00: F9400055  ldr      x21, [x2]
//   0x31ac04: 94000F2F  bl       #0x31e8c0
static inline uint64_t fde_func_1610_0x31abf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31abf8ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x10f540ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1611 | PC: 0x31ae08 | FDE: 0x10f670 | Size: 256 bytes
// Khung tháo gỡ #1611 | Địa chỉ PC: 0x31ae08 | Địa chỉ FDE: 0x10f670 | Kích thước: 256 bytes
//   0x31ae08: D10443FF  sub      sp, sp, #0x110
//   0x31ae0c: F9007BFC  str      x28, [sp, #0xf0]
//   0x31ae10: A9107BF3  stp      x19, x30, [sp, #0x100]
//   0x31ae14: A90817E4  stp      x4, x5, [sp, #0x80]
static inline uint64_t fde_func_1611_0x31ae08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31ae08ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xf9007bfcULL) ^ 0x10f670ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1612 | PC: 0x31b114 | FDE: 0x10f780 | Size: 136 bytes
// Khung tháo gỡ #1612 | Địa chỉ PC: 0x31b114 | Địa chỉ FDE: 0x10f780 | Kích thước: 136 bytes
//   0x31b114: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x31b118: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x31b11c: F9400408  ldr      x8, [x0, #8]
//   0x31b120: EB01011F  cmp      x8, x1
static inline uint64_t fde_func_1612_0x31b114(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31b114ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x10f780ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1613 | PC: 0x31b19c | FDE: 0x10f7b8 | Size: 256 bytes [JNI_OnLoad]
// Khung tháo gỡ #1613 | Địa chỉ PC: 0x31b19c | Địa chỉ FDE: 0x10f7b8 | Kích thước: 256 bytes
//   0x31b19c: D10283FF  sub      sp, sp, #0xa0
//   0x31b1a0: F9003BF6  str      x22, [sp, #0x70]
//   0x31b1a4: A90853F5  stp      x21, x20, [sp, #0x80]
//   0x31b1a8: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_1613_0x31b19c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31b19cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf6ULL) ^ 0x10f7b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1614 | PC: 0x31bd40 | FDE: 0x10f880 | Size: 228 bytes
// Khung tháo gỡ #1614 | Địa chỉ PC: 0x31bd40 | Địa chỉ FDE: 0x10f880 | Kích thước: 228 bytes
//   0x31bd40: F9400008  ldr      x8, [x0]
//   0x31bd44: F9400108  ldr      x8, [x8]
//   0x31bd48: D61F0100  br       x8
//   0x31bd4c: A9444FF4  ldp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1614_0x31bd40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31bd40ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9400108ULL) ^ 0x10f880ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1615 | PC: 0x31be24 | FDE: 0x10f970 | Size: 184 bytes
// Khung tháo gỡ #1615 | Địa chỉ PC: 0x31be24 | Địa chỉ FDE: 0x10f970 | Kích thước: 184 bytes
//   0x31be24: F940DFE8  ldr      x8, [sp, #0x1b8]
//   0x31be28: B981AFE9  ldrsw    x9, [sp, #0x1ac]
//   0x31be2c: F869791D  ldr      x29, [x8, x9, lsl #3]
//   0x31be30: 11000529  add      w9, w9, #1
static inline uint64_t fde_func_1615_0x31be24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31be24ULL ^ (static_cast<uint64_t>(0xf940dfe8ULL) << 13);
    acc = (acc + a1 + 0xb981afe9ULL) ^ 0x10f970ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1616 | PC: 0x31bedc | FDE: 0x10fa60 | Size: 192 bytes
// Khung tháo gỡ #1616 | Địa chỉ PC: 0x31bedc | Địa chỉ FDE: 0x10fa60 | Kích thước: 192 bytes
//   0x31bedc: 910023E0  add      x0, sp, #8
//   0x31bee0: 140091BC  b        #0x3405d0
//   0x31bee4: 910203FF  add      sp, sp, #0x80
//   0x31bee8: D65F03C0  ret      
static inline uint64_t fde_func_1616_0x31bedc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31bedcULL ^ (static_cast<uint64_t>(0x910023e0ULL) << 13);
    acc = (acc + a1 + 0x140091bcULL) ^ 0x10fa60ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1617 | PC: 0x31bf9c | FDE: 0x10fb50 | Size: 208 bytes
// Khung tháo gỡ #1617 | Địa chỉ PC: 0x31bf9c | Địa chỉ FDE: 0x10fb50 | Kích thước: 208 bytes
//   0x31bf9c: F9401FE9  ldr      x9, [sp, #0x38]
//   0x31bfa0: EB09011F  cmp      x8, x9
//   0x31bfa4: D65F03C0  ret      
//   0x31bfa8: 0E205800  cnt      v0.8b, v0.8b
static inline uint64_t fde_func_1617_0x31bf9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31bf9cULL ^ (static_cast<uint64_t>(0xf9401fe9ULL) << 13);
    acc = (acc + a1 + 0xeb09011fULL) ^ 0x10fb50ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1618 | PC: 0x31c06c | FDE: 0x10fc40 | Size: 188 bytes
// Khung tháo gỡ #1618 | Địa chỉ PC: 0x31c06c | Địa chỉ FDE: 0x10fc40 | Kích thước: 188 bytes
//   0x31c06c: 1E220802  fmul     s2, s0, s2
//   0x31c070: 1E212040  fcmp     s2, s1
//   0x31c074: D65F03C0  ret      
//   0x31c078: F9400E68  ldr      x8, [x19, #0x18]
static inline uint64_t fde_func_1618_0x31c06c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31c06cULL ^ (static_cast<uint64_t>(0x1e220802ULL) << 13);
    acc = (acc + a1 + 0x1e212040ULL) ^ 0x10fc40ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1619 | PC: 0x31c128 | FDE: 0x10fd30 | Size: 204 bytes
// Khung tháo gỡ #1619 | Địa chỉ PC: 0x31c128 | Địa chỉ FDE: 0x10fd30 | Kích thước: 204 bytes
//   0x31c128: 0E205800  cnt      v0.8b, v0.8b
//   0x31c12c: 2E303800  uaddlv   h0, v0.8b
//   0x31c130: 1E260009  fmov     w9, s0
//   0x31c134: 9E230100  ucvtf    s0, x8
static inline uint64_t fde_func_1619_0x31c128(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31c128ULL ^ (static_cast<uint64_t>(0x0e205800ULL) << 13);
    acc = (acc + a1 + 0x2e303800ULL) ^ 0x10fd30ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1620 | PC: 0x31c1f4 | FDE: 0x10fe20 | Size: 216 bytes
// Khung tháo gỡ #1620 | Địa chỉ PC: 0x31c1f4 | Địa chỉ FDE: 0x10fe20 | Kích thước: 216 bytes
//   0x31c1f4: F9400008  ldr      x8, [x0]
//   0x31c1f8: F9401108  ldr      x8, [x8, #0x20]
//   0x31c1fc: D61F0100  br       x8
//   0x31c200: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1620_0x31c1f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31c1f4ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9401108ULL) ^ 0x10fe20ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1621 | PC: 0x31c2cc | FDE: 0x10ff10 | Size: 176 bytes
// Khung tháo gỡ #1621 | Địa chỉ PC: 0x31c2cc | Địa chỉ FDE: 0x10ff10 | Kích thước: 176 bytes
//   0x31c2cc: 52800400  mov      w0, #0x20
//   0x31c2d0: 14008F9C  b        #0x340140
//   0x31c2d4: F9400269  ldr      x9, [x19]
//   0x31c2d8: D1000699  sub      x25, x20, #1
static inline uint64_t fde_func_1621_0x31c2cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31c2ccULL ^ (static_cast<uint64_t>(0x52800400ULL) << 13);
    acc = (acc + a1 + 0x14008f9cULL) ^ 0x10ff10ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1622 | PC: 0x31c37c | FDE: 0x110000 | Size: 140 bytes
// Khung tháo gỡ #1622 | Địa chỉ PC: 0x31c37c | Địa chỉ FDE: 0x110000 | Kích thước: 140 bytes
//   0x31c37c: 9E670120  fmov     d0, x9
//   0x31c380: 0E205800  cnt      v0.8b, v0.8b
//   0x31c384: 2E303800  uaddlv   h0, v0.8b
//   0x31c388: 1E26000B  fmov     w11, s0
static inline uint64_t fde_func_1622_0x31c37c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31c37cULL ^ (static_cast<uint64_t>(0x9e670120ULL) << 13);
    acc = (acc + a1 + 0x0e205800ULL) ^ 0x110000ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1623 | PC: 0x31c408 | FDE: 0x1100f0 | Size: 252 bytes
// Khung tháo gỡ #1623 | Địa chỉ PC: 0x31c408 | Địa chỉ FDE: 0x1100f0 | Kích thước: 252 bytes
//   0x31c408: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x31c40c: AA0003F5  mov      x21, x0
//   0x31c410: AA0103E0  mov      x0, x1
//   0x31c414: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1623_0x31c408(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31c408ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xaa0003f5ULL) ^ 0x1100f0ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1624 | PC: 0x31c504 | FDE: 0x1101e8 | Size: 108 bytes
// Khung tháo gỡ #1624 | Địa chỉ PC: 0x31c504 | Địa chỉ FDE: 0x1101e8 | Kích thước: 108 bytes
//   0x31c504: 910003E1  mov      x1, sp
//   0x31c508: AA1303E0  mov      x0, x19
//   0x31c50c: D65F03C0  ret      
//   0x31c510: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1624_0x31c504(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31c504ULL ^ (static_cast<uint64_t>(0x910003e1ULL) << 13);
    acc = (acc + a1 + 0xaa1303e0ULL) ^ 0x1101e8ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1625 | PC: 0x31c570 | FDE: 0x1102d8 | Size: 184 bytes
// Khung tháo gỡ #1625 | Địa chỉ PC: 0x31c570 | Địa chỉ FDE: 0x1102d8 | Kích thước: 184 bytes
//   0x31c570: AA1303E0  mov      x0, x19
//   0x31c574: AA1503E1  mov      x1, x21
//   0x31c578: D65F03C0  ret      
//   0x31c57c: F1000F1F  cmp      x24, #3
static inline uint64_t fde_func_1625_0x31c570(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31c570ULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0xaa1503e1ULL) ^ 0x1102d8ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1626 | PC: 0x31c628 | FDE: 0x1103c8 | Size: 256 bytes
// Khung tháo gỡ #1626 | Địa chỉ PC: 0x31c628 | Địa chỉ FDE: 0x1103c8 | Kích thước: 256 bytes
//   0x31c628: 528001E8  mov      w8, #0xf
//   0x31c62c: 9AC80828  udiv     x8, x1, x8
//   0x31c630: F100783F  cmp      x1, #0x1e
//   0x31c634: 528007E9  mov      w9, #0x3f
static inline uint64_t fde_func_1626_0x31c628(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31c628ULL ^ (static_cast<uint64_t>(0x528001e8ULL) << 13);
    acc = (acc + a1 + 0x9ac80828ULL) ^ 0x1103c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1627 | PC: 0x31c72c | FDE: 0x1104c0 | Size: 200 bytes
// Khung tháo gỡ #1627 | Địa chỉ PC: 0x31c72c | Địa chỉ FDE: 0x1104c0 | Kích thước: 200 bytes
//   0x31c72c: F1000F3F  cmp      x25, #3
//   0x31c730: D1000728  sub      x8, x25, #1
//   0x31c734: 1A9F27E9  cset     w9, lo
//   0x31c738: EA08033F  tst      x25, x8
static inline uint64_t fde_func_1627_0x31c72c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31c72cULL ^ (static_cast<uint64_t>(0xf1000f3fULL) << 13);
    acc = (acc + a1 + 0xd1000728ULL) ^ 0x1104c0ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1628 | PC: 0x31c7f4 | FDE: 0x1105b0 | Size: 116 bytes
// Khung tháo gỡ #1628 | Địa chỉ PC: 0x31c7f4 | Địa chỉ FDE: 0x1105b0 | Kích thước: 116 bytes
//   0x31c7f4: 910443E1  add      x1, sp, #0x110
//   0x31c7f8: AA1403E0  mov      x0, x20
//   0x31c7fc: B90113E8  str      w8, [sp, #0x110]
//   0x31c800: 17FFB7A8  b        #0x30a6a0
static inline uint64_t fde_func_1628_0x31c7f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31c7f4ULL ^ (static_cast<uint64_t>(0x910443e1ULL) << 13);
    acc = (acc + a1 + 0xaa1403e0ULL) ^ 0x1105b0ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1629 | PC: 0x31c868 | FDE: 0x1106a0 | Size: 152 bytes
// Khung tháo gỡ #1629 | Địa chỉ PC: 0x31c868 | Địa chỉ FDE: 0x1106a0 | Kích thước: 152 bytes
//   0x31c868: D53BD057  mrs      x23, tpidr_el0
//   0x31c86c: F94016E8  ldr      x8, [x23, #0x28]
//   0x31c870: AA0303F3  mov      x19, x3
//   0x31c874: 2A0203F4  mov      w20, w2
static inline uint64_t fde_func_1629_0x31c868(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31c868ULL ^ (static_cast<uint64_t>(0xd53bd057ULL) << 13);
    acc = (acc + a1 + 0xf94016e8ULL) ^ 0x1106a0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1630 | PC: 0x31c900 | FDE: 0x110790 | Size: 196 bytes
// Khung tháo gỡ #1630 | Địa chỉ PC: 0x31c900 | Địa chỉ FDE: 0x110790 | Kích thước: 196 bytes
//   0x31c900: 7100013F  cmp      w9, #0
//   0x31c904: 5A895529  cneg     w9, w9, mi
//   0x31c908: D37EF529  lsl      x9, x9, #2
//   0x31c90c: 91001D29  add      x9, x9, #7
static inline uint64_t fde_func_1630_0x31c900(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31c900ULL ^ (static_cast<uint64_t>(0x7100013fULL) << 13);
    acc = (acc + a1 + 0x5a895529ULL) ^ 0x110790ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1631 | PC: 0x31c9c4 | FDE: 0x110880 | Size: 168 bytes
// Khung tháo gỡ #1631 | Địa chỉ PC: 0x31c9c4 | Địa chỉ FDE: 0x110880 | Kích thước: 168 bytes
//   0x31c9c4: AA0103F4  mov      x20, x1
//   0x31c9c8: AA0003F3  mov      x19, x0
//   0x31c9cc: 17F8FD41  b        #0x15bed0
//   0x31c9d0: 910103E0  add      x0, sp, #0x40
static inline uint64_t fde_func_1631_0x31c9c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31c9c4ULL ^ (static_cast<uint64_t>(0xaa0103f4ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x110880ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1632 | PC: 0x31ca6c | FDE: 0x110970 | Size: 164 bytes
// Khung tháo gỡ #1632 | Địa chỉ PC: 0x31ca6c | Địa chỉ FDE: 0x110970 | Kích thước: 164 bytes
//   0x31ca6c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x31ca70: 97F8F444  bl       #0x159b80
//   0x31ca74: AA1303E0  mov      x0, x19
//   0x31ca78: F84107FE  ldr      x30, [sp], #0x10
static inline uint64_t fde_func_1632_0x31ca6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31ca6cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x97f8f444ULL) ^ 0x110970ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1633 | PC: 0x31cb10 | FDE: 0x110a68 | Size: 124 bytes
// Khung tháo gỡ #1633 | Địa chỉ PC: 0x31cb10 | Địa chỉ FDE: 0x110a68 | Kích thước: 124 bytes
//   0x31cb10: AA0003F6  mov      x22, x0
//   0x31cb14: 9100C3E0  add      x0, sp, #0x30
//   0x31cb18: AA1503E1  mov      x1, x21
//   0x31cb1c: 2A1403E2  mov      w2, w20
static inline uint64_t fde_func_1633_0x31cb10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31cb10ULL ^ (static_cast<uint64_t>(0xaa0003f6ULL) << 13);
    acc = (acc + a1 + 0x9100c3e0ULL) ^ 0x110a68ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1634 | PC: 0x31cb8c | FDE: 0x110b58 | Size: 164 bytes
// Khung tháo gỡ #1634 | Địa chỉ PC: 0x31cb8c | Địa chỉ FDE: 0x110b58 | Kích thước: 164 bytes
//   0x31cb8c: D53BD059  mrs      x25, tpidr_el0
//   0x31cb90: F9401728  ldr      x8, [x25, #0x28]
//   0x31cb94: AA0003F7  mov      x23, x0
//   0x31cb98: 52801A00  mov      w0, #0xd0
static inline uint64_t fde_func_1634_0x31cb8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31cb8cULL ^ (static_cast<uint64_t>(0xd53bd059ULL) << 13);
    acc = (acc + a1 + 0xf9401728ULL) ^ 0x110b58ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1635 | PC: 0x31cc30 | FDE: 0x110c50 | Size: 256 bytes
// Khung tháo gỡ #1635 | Địa chỉ PC: 0x31cc30 | Địa chỉ FDE: 0x110c50 | Kích thước: 256 bytes
//   0x31cc30: AA1303E8  mov      x8, x19
//   0x31cc34: F8410D16  ldr      x22, [x8, #0x10]!
//   0x31cc38: D65F03C0  ret      
//   0x31cc3c: AA1303E9  mov      x9, x19
static inline uint64_t fde_func_1635_0x31cc30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31cc30ULL ^ (static_cast<uint64_t>(0xaa1303e8ULL) << 13);
    acc = (acc + a1 + 0xf8410d16ULL) ^ 0x110c50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1636 | PC: 0x31cd30 | FDE: 0x110d50 | Size: 112 bytes
// Khung tháo gỡ #1636 | Địa chỉ PC: 0x31cd30 | Địa chỉ FDE: 0x110d50 | Kích thước: 112 bytes
//   0x31cd30: 910083E0  add      x0, sp, #0x20
//   0x31cd34: 14008E27  b        #0x3405d0
//   0x31cd38: F82D79C8  str      x8, [x14, x13, lsl #3]
//   0x31cd3c: AA0D03EA  mov      x10, x13
static inline uint64_t fde_func_1636_0x31cd30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31cd30ULL ^ (static_cast<uint64_t>(0x910083e0ULL) << 13);
    acc = (acc + a1 + 0x14008e27ULL) ^ 0x110d50ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1637 | PC: 0x31cda0 | FDE: 0x110e40 | Size: 116 bytes
// Khung tháo gỡ #1637 | Địa chỉ PC: 0x31cda0 | Địa chỉ FDE: 0x110e40 | Kích thước: 116 bytes
//   0x31cda0: F9000009  str      x9, [x0]
//   0x31cda4: AA0803E0  mov      x0, x8
//   0x31cda8: 17F8F85B  b        #0x15af14
//   0x31cdac: 910063E0  add      x0, sp, #0x18
static inline uint64_t fde_func_1637_0x31cda0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31cda0ULL ^ (static_cast<uint64_t>(0xf9000009ULL) << 13);
    acc = (acc + a1 + 0xaa0803e0ULL) ^ 0x110e40ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1638 | PC: 0x31ce14 | FDE: 0x110f30 | Size: 148 bytes
// Khung tháo gỡ #1638 | Địa chỉ PC: 0x31ce14 | Địa chỉ FDE: 0x110f30 | Kích thước: 148 bytes
//   0x31ce14: AA0003F3  mov      x19, x0
//   0x31ce18: F9400000  ldr      x0, [x0]
//   0x31ce1c: D65F03C0  ret      
//   0x31ce20: B9401190  ldr      w16, [x12, #0x10]
static inline uint64_t fde_func_1638_0x31ce14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31ce14ULL ^ (static_cast<uint64_t>(0xaa0003f3ULL) << 13);
    acc = (acc + a1 + 0xf9400000ULL) ^ 0x110f30ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1639 | PC: 0x31cea8 | FDE: 0x111020 | Size: 180 bytes
// Khung tháo gỡ #1639 | Địa chỉ PC: 0x31cea8 | Địa chỉ FDE: 0x111020 | Kích thước: 180 bytes
//   0x31cea8: 910003E1  mov      x1, sp
//   0x31ceac: AA1403E0  mov      x0, x20
//   0x31ceb0: D65F03C0  ret      
//   0x31ceb4: F9402908  ldr      x8, [x8, #0x50]
static inline uint64_t fde_func_1639_0x31cea8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31cea8ULL ^ (static_cast<uint64_t>(0x910003e1ULL) << 13);
    acc = (acc + a1 + 0xaa1403e0ULL) ^ 0x111020ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1640 | PC: 0x31cf5c | FDE: 0x111110 | Size: 208 bytes
// Khung tháo gỡ #1640 | Địa chỉ PC: 0x31cf5c | Địa chỉ FDE: 0x111110 | Kích thước: 208 bytes
//   0x31cf5c: F9400028  ldr      x8, [x1]
//   0x31cf60: 52800029  mov      w9, #1
//   0x31cf64: F9000188  str      x8, [x12]
//   0x31cf68: F900003F  str      xzr, [x1]
static inline uint64_t fde_func_1640_0x31cf5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31cf5cULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0x52800029ULL) ^ 0x111110ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1641 | PC: 0x31d02c | FDE: 0x111200 | Size: 180 bytes
// Khung tháo gỡ #1641 | Địa chỉ PC: 0x31d02c | Địa chỉ FDE: 0x111200 | Kích thước: 180 bytes
//   0x31d02c: A94F4FF4  ldp      x20, x19, [sp, #0xf0]
//   0x31d030: A94E57F6  ldp      x22, x21, [sp, #0xe0]
//   0x31d034: A94D5FF8  ldp      x24, x23, [sp, #0xd0]
//   0x31d038: A94C67FA  ldp      x26, x25, [sp, #0xc0]
static inline uint64_t fde_func_1641_0x31d02c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31d02cULL ^ (static_cast<uint64_t>(0xa94f4ff4ULL) << 13);
    acc = (acc + a1 + 0xa94e57f6ULL) ^ 0x111200ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1642 | PC: 0x31d0e0 | FDE: 0x1112f0 | Size: 156 bytes
// Khung tháo gỡ #1642 | Địa chỉ PC: 0x31d0e0 | Địa chỉ FDE: 0x1112f0 | Kích thước: 156 bytes
//   0x31d0e0: F9400268  ldr      x8, [x19]
//   0x31d0e4: AA1303E0  mov      x0, x19
//   0x31d0e8: D65F03C0  ret      
//   0x31d0ec: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1642_0x31d0e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31d0e0ULL ^ (static_cast<uint64_t>(0xf9400268ULL) << 13);
    acc = (acc + a1 + 0xaa1303e0ULL) ^ 0x1112f0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1643 | PC: 0x31d17c | FDE: 0x1113e8 | Size: 144 bytes
// Khung tháo gỡ #1643 | Địa chỉ PC: 0x31d17c | Địa chỉ FDE: 0x1113e8 | Kích thước: 144 bytes
//   0x31d17c: F9400501  ldr      x1, [x8, #8]
//   0x31d180: D61F0020  br       x1
//   0x31d184: D53BD056  mrs      x22, tpidr_el0
//   0x31d188: F94016C8  ldr      x8, [x22, #0x28]
static inline uint64_t fde_func_1643_0x31d17c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31d17cULL ^ (static_cast<uint64_t>(0xf9400501ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x1113e8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1644 | PC: 0x31d20c | FDE: 0x1114d8 | Size: 256 bytes
// Khung tháo gỡ #1644 | Địa chỉ PC: 0x31d20c | Địa chỉ FDE: 0x1114d8 | Kích thước: 256 bytes
//   0x31d20c: F94013E8  ldr      x8, [sp, #0x20]
//   0x31d210: 910023E0  add      x0, sp, #8
//   0x31d214: 910083E1  add      x1, sp, #0x20
//   0x31d218: AA1403E3  mov      x3, x20
static inline uint64_t fde_func_1644_0x31d20c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31d20cULL ^ (static_cast<uint64_t>(0xf94013e8ULL) << 13);
    acc = (acc + a1 + 0x910023e0ULL) ^ 0x1114d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1645 | PC: 0x31d328 | FDE: 0x1115c8 | Size: 156 bytes
// Khung tháo gỡ #1645 | Địa chỉ PC: 0x31d328 | Địa chỉ FDE: 0x1115c8 | Kích thước: 156 bytes
//   0x31d328: AA1503E0  mov      x0, x21
//   0x31d32c: 17F91EAB  b        #0x164dd8
//   0x31d330: F84207F4  ldr      x20, [sp], #0x20
//   0x31d334: 17FCE62C  b        #0x256be4
static inline uint64_t fde_func_1645_0x31d328(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31d328ULL ^ (static_cast<uint64_t>(0xaa1503e0ULL) << 13);
    acc = (acc + a1 + 0x17f91eabULL) ^ 0x1115c8ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1646 | PC: 0x31d3c4 | FDE: 0x1116b8 | Size: 192 bytes
// Khung tháo gỡ #1646 | Địa chỉ PC: 0x31d3c4 | Địa chỉ FDE: 0x1116b8 | Kích thước: 192 bytes
//   0x31d3c4: D53BD054  mrs      x20, tpidr_el0
//   0x31d3c8: F9401688  ldr      x8, [x20, #0x28]
//   0x31d3cc: D65F03C0  ret      
//   0x31d3d0: 39400308  ldrb     w8, [x24]
static inline uint64_t fde_func_1646_0x31d3c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31d3c4ULL ^ (static_cast<uint64_t>(0xd53bd054ULL) << 13);
    acc = (acc + a1 + 0xf9401688ULL) ^ 0x1116b8ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1647 | PC: 0x31d484 | FDE: 0x1117a8 | Size: 184 bytes
// Khung tháo gỡ #1647 | Địa chỉ PC: 0x31d484 | Địa chỉ FDE: 0x1117a8 | Kích thước: 184 bytes
//   0x31d484: 9100A3E0  add      x0, sp, #0x28
//   0x31d488: 14008B5E  b        #0x340200
//   0x31d48c: F9400901  ldr      x1, [x8, #0x10]
//   0x31d490: D61F0020  br       x1
static inline uint64_t fde_func_1647_0x31d484(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31d484ULL ^ (static_cast<uint64_t>(0x9100a3e0ULL) << 13);
    acc = (acc + a1 + 0x14008b5eULL) ^ 0x1117a8ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1648 | PC: 0x31d53c | FDE: 0x111898 | Size: 136 bytes
// Khung tháo gỡ #1648 | Địa chỉ PC: 0x31d53c | Địa chỉ FDE: 0x111898 | Kích thước: 136 bytes
//   0x31d53c: D0FFEB21  adrp     x1, #0x83000
//   0x31d540: 90FFEA62  adrp     x2, #0x69000
//   0x31d544: 9136D021  add      x1, x1, #0xdb4
//   0x31d548: 912C7442  add      x2, x2, #0xb1d
static inline uint64_t fde_func_1648_0x31d53c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31d53cULL ^ (static_cast<uint64_t>(0xd0ffeb21ULL) << 13);
    acc = (acc + a1 + 0x90ffea62ULL) ^ 0x111898ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1649 | PC: 0x31d5c4 | FDE: 0x111988 | Size: 180 bytes
// Khung tháo gỡ #1649 | Địa chỉ PC: 0x31d5c4 | Địa chỉ FDE: 0x111988 | Kích thước: 180 bytes
//   0x31d5c4: F9400675  ldr      x21, [x19, #8]
//   0x31d5c8: EB15029F  cmp      x20, x21
//   0x31d5cc: D65F03C0  ret      
//   0x31d5d0: F1000428  subs     x8, x1, #1
static inline uint64_t fde_func_1649_0x31d5c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31d5c4ULL ^ (static_cast<uint64_t>(0xf9400675ULL) << 13);
    acc = (acc + a1 + 0xeb15029fULL) ^ 0x111988ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1650 | PC: 0x31d678 | FDE: 0x111a78 | Size: 168 bytes
// Khung tháo gỡ #1650 | Địa chỉ PC: 0x31d678 | Địa chỉ FDE: 0x111a78 | Kích thước: 168 bytes
//   0x31d678: F94067E9  ldr      x9, [sp, #0xc8]
//   0x31d67c: EB09011F  cmp      x8, x9
//   0x31d680: D65F03C0  ret      
//   0x31d684: 9100E3E0  add      x0, sp, #0x38
static inline uint64_t fde_func_1650_0x31d678(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31d678ULL ^ (static_cast<uint64_t>(0xf94067e9ULL) << 13);
    acc = (acc + a1 + 0xeb09011fULL) ^ 0x111a78ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1651 | PC: 0x31d720 | FDE: 0x111b68 | Size: 176 bytes
// Khung tháo gỡ #1651 | Địa chỉ PC: 0x31d720 | Địa chỉ FDE: 0x111b68 | Kích thước: 176 bytes
//   0x31d720: A9405008  ldp      x8, x20, [x0]
//   0x31d724: AA0003F3  mov      x19, x0
//   0x31d728: F9400509  ldr      x9, [x8, #8]
//   0x31d72c: F940028A  ldr      x10, [x20]
static inline uint64_t fde_func_1651_0x31d720(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31d720ULL ^ (static_cast<uint64_t>(0xa9405008ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x111b68ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1652 | PC: 0x31d7d0 | FDE: 0x111c58 | Size: 124 bytes
// Khung tháo gỡ #1652 | Địa chỉ PC: 0x31d7d0 | Địa chỉ FDE: 0x111c58 | Kích thước: 124 bytes
//   0x31d7d0: 9103C3FF  add      sp, sp, #0xf0
//   0x31d7d4: D65F03C0  ret      
//   0x31d7d8: 91006280  add      x0, x20, #0x18
//   0x31d7dc: F84207F4  ldr      x20, [sp], #0x20
static inline uint64_t fde_func_1652_0x31d7d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31d7d0ULL ^ (static_cast<uint64_t>(0x9103c3ffULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x111c58ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1653 | PC: 0x31d84c | FDE: 0x111d48 | Size: 196 bytes
// Khung tháo gỡ #1653 | Địa chỉ PC: 0x31d84c | Địa chỉ FDE: 0x111d48 | Kích thước: 196 bytes
//   0x31d84c: 910603E0  add      x0, sp, #0x180
//   0x31d850: 910683E2  add      x2, sp, #0x1a0
//   0x31d854: D65F03C0  ret      
//   0x31d858: 910123E0  add      x0, sp, #0x48
static inline uint64_t fde_func_1653_0x31d84c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31d84cULL ^ (static_cast<uint64_t>(0x910603e0ULL) << 13);
    acc = (acc + a1 + 0x910683e2ULL) ^ 0x111d48ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1654 | PC: 0x31d910 | FDE: 0x111e40 | Size: 168 bytes
// Khung tháo gỡ #1654 | Địa chỉ PC: 0x31d910 | Địa chỉ FDE: 0x111e40 | Kích thước: 168 bytes
//   0x31d910: D0000240  adrp     x0, #0x367000
//   0x31d914: 91110000  add      x0, x0, #0x440
//   0x31d918: 14008A62  b        #0x3402a0
//   0x31d91c: 91000042  add      x2, x2, #0
static inline uint64_t fde_func_1654_0x31d910(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31d910ULL ^ (static_cast<uint64_t>(0xd0000240ULL) << 13);
    acc = (acc + a1 + 0x91110000ULL) ^ 0x111e40ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1655 | PC: 0x31d9b8 | FDE: 0x111f30 | Size: 164 bytes
// Khung tháo gỡ #1655 | Địa chỉ PC: 0x31d9b8 | Địa chỉ FDE: 0x111f30 | Kích thước: 164 bytes
//   0x31d9b8: F9400008  ldr      x8, [x0]
//   0x31d9bc: F9409908  ldr      x8, [x8, #0x130]
//   0x31d9c0: D61F0100  br       x8
//   0x31d9c4: AA1503E0  mov      x0, x21
static inline uint64_t fde_func_1655_0x31d9b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31d9b8ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9409908ULL) ^ 0x111f30ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1656 | PC: 0x31da5c | FDE: 0x112020 | Size: 156 bytes
// Khung tháo gỡ #1656 | Địa chỉ PC: 0x31da5c | Địa chỉ FDE: 0x112020 | Kích thước: 156 bytes
//   0x31da5c: F9400109  ldr      x9, [x8]
//   0x31da60: F90002E9  str      x9, [x23]
//   0x31da64: F9000117  str      x23, [x8]
//   0x31da68: D65F03C0  ret      
static inline uint64_t fde_func_1656_0x31da5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31da5cULL ^ (static_cast<uint64_t>(0xf9400109ULL) << 13);
    acc = (acc + a1 + 0xf90002e9ULL) ^ 0x112020ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1657 | PC: 0x31daf8 | FDE: 0x112118 | Size: 156 bytes
// Khung tháo gỡ #1657 | Địa chỉ PC: 0x31daf8 | Địa chỉ FDE: 0x112118 | Kích thước: 156 bytes
//   0x31daf8: 910003E1  mov      x1, sp
//   0x31dafc: AA1503E0  mov      x0, x21
//   0x31db00: D65F03C0  ret      
//   0x31db04: A9454FF4  ldp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1657_0x31daf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31daf8ULL ^ (static_cast<uint64_t>(0x910003e1ULL) << 13);
    acc = (acc + a1 + 0xaa1503e0ULL) ^ 0x112118ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1658 | PC: 0x31db94 | FDE: 0x112208 | Size: 256 bytes
// Khung tháo gỡ #1658 | Địa chỉ PC: 0x31db94 | Địa chỉ FDE: 0x112208 | Kích thước: 256 bytes
//   0x31db94: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x31db98: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x31db9c: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x31dba0: A90757F6  stp      x22, x21, [sp, #0x70]
static inline uint64_t fde_func_1658_0x31db94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31db94ULL ^ (static_cast<uint64_t>(0xa9046ffcULL) << 13);
    acc = (acc + a1 + 0xa90567faULL) ^ 0x112208ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1659 | PC: 0x31dc9c | FDE: 0x1122f8 | Size: 184 bytes
// Khung tháo gỡ #1659 | Địa chỉ PC: 0x31dc9c | Địa chỉ FDE: 0x1122f8 | Kích thước: 184 bytes
//   0x31dc9c: F9400508  ldr      x8, [x8, #8]
//   0x31dca0: D1000709  sub      x9, x24, #1
//   0x31dca4: EA09031F  tst      x24, x9
//   0x31dca8: D65F03C0  ret      
static inline uint64_t fde_func_1659_0x31dc9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31dc9cULL ^ (static_cast<uint64_t>(0xf9400508ULL) << 13);
    acc = (acc + a1 + 0xd1000709ULL) ^ 0x1122f8ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1660 | PC: 0x31dd54 | FDE: 0x1123e8 | Size: 204 bytes
// Khung tháo gỡ #1660 | Địa chỉ PC: 0x31dd54 | Địa chỉ FDE: 0x1123e8 | Kích thước: 204 bytes
//   0x31dd54: AA1303E0  mov      x0, x19
//   0x31dd58: 17F9C4C7  b        #0x18f074
//   0x31dd5c: AA1303E0  mov      x0, x19
//   0x31dd60: 17F97538  b        #0x17b240
static inline uint64_t fde_func_1660_0x31dd54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31dd54ULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0x17f9c4c7ULL) ^ 0x1123e8ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1661 | PC: 0x31de20 | FDE: 0x1124e0 | Size: 224 bytes
// Khung tháo gỡ #1661 | Địa chỉ PC: 0x31de20 | Địa chỉ FDE: 0x1124e0 | Kích thước: 224 bytes
//   0x31de20: B94037E8  ldr      w8, [sp, #0x34]
//   0x31de24: 7100035F  cmp      w26, #0
//   0x31de28: 1A9F07E9  cset     w9, ne
//   0x31de2c: 6B0A033F  cmp      w25, w10
static inline uint64_t fde_func_1661_0x31de20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31de20ULL ^ (static_cast<uint64_t>(0xb94037e8ULL) << 13);
    acc = (acc + a1 + 0x7100035fULL) ^ 0x1124e0ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #1662 | PC: 0x31df00 | FDE: 0x1125d0 | Size: 192 bytes
// Khung tháo gỡ #1662 | Địa chỉ PC: 0x31df00 | Địa chỉ FDE: 0x1125d0 | Kích thước: 192 bytes
//   0x31df00: 2A1F03E1  mov      w1, wzr
//   0x31df04: 14008C5F  b        #0x341080
//   0x31df08: F9401408  ldr      x8, [x0, #0x28]
//   0x31df0c: 9E230020  ucvtf    s0, x1
static inline uint64_t fde_func_1662_0x31df00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31df00ULL ^ (static_cast<uint64_t>(0x2a1f03e1ULL) << 13);
    acc = (acc + a1 + 0x14008c5fULL) ^ 0x1125d0ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1663 | PC: 0x31dfc0 | FDE: 0x1126d0 | Size: 100 bytes
// Khung tháo gỡ #1663 | Địa chỉ PC: 0x31dfc0 | Địa chỉ FDE: 0x1126d0 | Kích thước: 100 bytes
//   0x31dfc0: F90007E0  str      x0, [sp, #8]
//   0x31dfc4: AA0803E0  mov      x0, x8
//   0x31dfc8: 140088A2  b        #0x340250
//   0x31dfcc: 6F00E400  movi     v0.2d, #0000000000000000
static inline uint64_t fde_func_1663_0x31dfc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31dfc0ULL ^ (static_cast<uint64_t>(0xf90007e0ULL) << 13);
    acc = (acc + a1 + 0xaa0803e0ULL) ^ 0x1126d0ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1664 | PC: 0x31e024 | FDE: 0x1127c0 | Size: 200 bytes
// Khung tháo gỡ #1664 | Địa chỉ PC: 0x31e024 | Địa chỉ FDE: 0x1127c0 | Kích thước: 200 bytes
//   0x31e024: 910543FF  add      sp, sp, #0x150
//   0x31e028: D65F03C0  ret      
//   0x31e02c: 910143E0  add      x0, sp, #0x50
//   0x31e030: 17F8EEE9  b        #0x159bd4
static inline uint64_t fde_func_1664_0x31e024(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31e024ULL ^ (static_cast<uint64_t>(0x910543ffULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1127c0ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1665 | PC: 0x31e0ec | FDE: 0x1128b0 | Size: 180 bytes
// Khung tháo gỡ #1665 | Địa chỉ PC: 0x31e0ec | Địa chỉ FDE: 0x1128b0 | Kích thước: 180 bytes
//   0x31e0ec: 91006013  add      x19, x0, #0x18
//   0x31e0f0: AA0003F6  mov      x22, x0
//   0x31e0f4: AA1303E0  mov      x0, x19
//   0x31e0f8: 2A0203F4  mov      w20, w2
static inline uint64_t fde_func_1665_0x31e0ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31e0ecULL ^ (static_cast<uint64_t>(0x91006013ULL) << 13);
    acc = (acc + a1 + 0xaa0003f6ULL) ^ 0x1128b0ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1666 | PC: 0x31e1a0 | FDE: 0x1129a0 | Size: 184 bytes
// Khung tháo gỡ #1666 | Địa chỉ PC: 0x31e1a0 | Địa chỉ FDE: 0x1129a0 | Kích thước: 184 bytes
//   0x31e1a0: AA0003E2  mov      x2, x0
//   0x31e1a4: 9100E3E0  add      x0, sp, #0x38
//   0x31e1a8: AA1403E1  mov      x1, x20
//   0x31e1ac: 17F914A9  b        #0x163450
static inline uint64_t fde_func_1666_0x31e1a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31e1a0ULL ^ (static_cast<uint64_t>(0xaa0003e2ULL) << 13);
    acc = (acc + a1 + 0x9100e3e0ULL) ^ 0x1129a0ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1667 | PC: 0x31e258 | FDE: 0x112a90 | Size: 164 bytes
// Khung tháo gỡ #1667 | Địa chỉ PC: 0x31e258 | Địa chỉ FDE: 0x112a90 | Kích thước: 164 bytes
//   0x31e258: 9102A3E0  add      x0, sp, #0xa8
//   0x31e25c: 140088DD  b        #0x3405d0
//   0x31e260: A95453F5  ldp      x21, x20, [sp, #0x140]
//   0x31e264: A9535BF7  ldp      x23, x22, [sp, #0x130]
static inline uint64_t fde_func_1667_0x31e258(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31e258ULL ^ (static_cast<uint64_t>(0x9102a3e0ULL) << 13);
    acc = (acc + a1 + 0x140088ddULL) ^ 0x112a90ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1668 | PC: 0x31e2fc | FDE: 0x112b80 | Size: 108 bytes
// Khung tháo gỡ #1668 | Địa chỉ PC: 0x31e2fc | Địa chỉ FDE: 0x112b80 | Kích thước: 108 bytes
//   0x31e2fc: AA0203F3  mov      x19, x2
//   0x31e300: AA0003F4  mov      x20, x0
//   0x31e304: D65F03C0  ret      
//   0x31e308: AA1F03E0  mov      x0, xzr
static inline uint64_t fde_func_1668_0x31e2fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31e2fcULL ^ (static_cast<uint64_t>(0xaa0203f3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f4ULL) ^ 0x112b80ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1669 | PC: 0x31e368 | FDE: 0x112c70 | Size: 128 bytes
// Khung tháo gỡ #1669 | Địa chỉ PC: 0x31e368 | Địa chỉ FDE: 0x112c70 | Kích thước: 128 bytes
//   0x31e368: AA1403E0  mov      x0, x20
//   0x31e36c: AA1703E1  mov      x1, x23
//   0x31e370: D65F03C0  ret      
//   0x31e374: F9000008  str      x8, [x0]
static inline uint64_t fde_func_1669_0x31e368(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31e368ULL ^ (static_cast<uint64_t>(0xaa1403e0ULL) << 13);
    acc = (acc + a1 + 0xaa1703e1ULL) ^ 0x112c70ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1670 | PC: 0x31e3e8 | FDE: 0x112d60 | Size: 172 bytes
// Khung tháo gỡ #1670 | Địa chỉ PC: 0x31e3e8 | Địa chỉ FDE: 0x112d60 | Kích thước: 172 bytes
//   0x31e3e8: AA0303F4  mov      x20, x3
//   0x31e3ec: 12000A88  and      w8, w20, #7
//   0x31e3f0: 52800039  mov      w25, #1
//   0x31e3f4: AA0403F5  mov      x21, x4
static inline uint64_t fde_func_1670_0x31e3e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31e3e8ULL ^ (static_cast<uint64_t>(0xaa0303f4ULL) << 13);
    acc = (acc + a1 + 0x12000a88ULL) ^ 0x112d60ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1671 | PC: 0x31e494 | FDE: 0x112e50 | Size: 232 bytes
// Khung tháo gỡ #1671 | Địa chỉ PC: 0x31e494 | Địa chỉ FDE: 0x112e50 | Kích thước: 232 bytes
//   0x31e494: AA1403E0  mov      x0, x20
//   0x31e498: 17F92FA2  b        #0x16a320
//   0x31e49c: AA0003F4  mov      x20, x0
//   0x31e4a0: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1671_0x31e494(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31e494ULL ^ (static_cast<uint64_t>(0xaa1403e0ULL) << 13);
    acc = (acc + a1 + 0x17f92fa2ULL) ^ 0x112e50ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1672 | PC: 0x31e57c | FDE: 0x112f40 | Size: 256 bytes
// Khung tháo gỡ #1672 | Địa chỉ PC: 0x31e57c | Địa chỉ FDE: 0x112f40 | Kích thước: 256 bytes
//   0x31e57c: 910033E1  add      x1, sp, #0xc
//   0x31e580: 910043E2  add      x2, sp, #0x10
//   0x31e584: AA1303E0  mov      x0, x19
//   0x31e588: 17F9B9A1  b        #0x18cc0c
static inline uint64_t fde_func_1672_0x31e57c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31e57cULL ^ (static_cast<uint64_t>(0x910033e1ULL) << 13);
    acc = (acc + a1 + 0x910043e2ULL) ^ 0x112f40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1673 | PC: 0x31e6ac | FDE: 0x113038 | Size: 152 bytes
// Khung tháo gỡ #1673 | Địa chỉ PC: 0x31e6ac | Địa chỉ FDE: 0x113038 | Kích thước: 152 bytes
//   0x31e6ac: F9401668  ldr      x8, [x19, #0x28]
//   0x31e6b0: 91000508  add      x8, x8, #1
//   0x31e6b4: F9001668  str      x8, [x19, #0x28]
//   0x31e6b8: D65F03C0  ret      
static inline uint64_t fde_func_1673_0x31e6ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31e6acULL ^ (static_cast<uint64_t>(0xf9401668ULL) << 13);
    acc = (acc + a1 + 0x91000508ULL) ^ 0x113038ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1674 | PC: 0x31e744 | FDE: 0x113128 | Size: 184 bytes
// Khung tháo gỡ #1674 | Địa chỉ PC: 0x31e744 | Địa chỉ FDE: 0x113128 | Kích thước: 184 bytes
//   0x31e744: AA1603E1  mov      x1, x22
//   0x31e748: 17F8ED23  b        #0x159bd4
//   0x31e74c: AA1403E1  mov      x1, x20
//   0x31e750: 17F8ED21  b        #0x159bd4
static inline uint64_t fde_func_1674_0x31e744(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31e744ULL ^ (static_cast<uint64_t>(0xaa1603e1ULL) << 13);
    acc = (acc + a1 + 0x17f8ed23ULL) ^ 0x113128ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1675 | PC: 0x31e7fc | FDE: 0x113218 | Size: 144 bytes
// Khung tháo gỡ #1675 | Địa chỉ PC: 0x31e7fc | Địa chỉ FDE: 0x113218 | Kích thước: 144 bytes
//   0x31e7fc: 910283E0  add      x0, sp, #0xa0
//   0x31e800: 17F8ECE0  b        #0x159b80
//   0x31e804: 2A0203F3  mov      w19, w2
//   0x31e808: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_1675_0x31e7fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31e7fcULL ^ (static_cast<uint64_t>(0x910283e0ULL) << 13);
    acc = (acc + a1 + 0x17f8ece0ULL) ^ 0x113218ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1676 | PC: 0x31e88c | FDE: 0x113308 | Size: 132 bytes
// Khung tháo gỡ #1676 | Địa chỉ PC: 0x31e88c | Địa chỉ FDE: 0x113308 | Kích thước: 132 bytes
//   0x31e88c: 9E290009  fcvtpu   x9, s0
//   0x31e890: EB09011F  cmp      x8, x9
//   0x31e894: 9A883137  csel     x23, x9, x8, lo
//   0x31e898: F10006E8  subs     x8, x23, #1
static inline uint64_t fde_func_1676_0x31e88c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31e88cULL ^ (static_cast<uint64_t>(0x9e290009ULL) << 13);
    acc = (acc + a1 + 0xeb09011fULL) ^ 0x113308ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1677 | PC: 0x31e910 | FDE: 0x1133f8 | Size: 212 bytes
// Khung tháo gỡ #1677 | Địa chỉ PC: 0x31e910 | Địa chỉ FDE: 0x1133f8 | Kích thước: 212 bytes
//   0x31e910: F9408FE9  ldr      x9, [sp, #0x118]
//   0x31e914: EB09011F  cmp      x8, x9
//   0x31e918: D65F03C0  ret      
//   0x31e91c: 910003E8  mov      x8, sp
static inline uint64_t fde_func_1677_0x31e910(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31e910ULL ^ (static_cast<uint64_t>(0xf9408fe9ULL) << 13);
    acc = (acc + a1 + 0xeb09011fULL) ^ 0x1133f8ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1678 | PC: 0x31e9e4 | FDE: 0x1134f0 | Size: 132 bytes
// Khung tháo gỡ #1678 | Địa chỉ PC: 0x31e9e4 | Địa chỉ FDE: 0x1134f0 | Kích thước: 132 bytes
//   0x31e9e4: EB0002DF  cmp      x22, x0
//   0x31e9e8: 9A963001  csel     x1, x0, x22, lo
//   0x31e9ec: EB17003F  cmp      x1, x23
//   0x31e9f0: D65F03C0  ret      
static inline uint64_t fde_func_1678_0x31e9e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31e9e4ULL ^ (static_cast<uint64_t>(0xeb0002dfULL) << 13);
    acc = (acc + a1 + 0x9a963001ULL) ^ 0x1134f0ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1679 | PC: 0x31ea68 | FDE: 0x1135e0 | Size: 192 bytes
// Khung tháo gỡ #1679 | Địa chỉ PC: 0x31ea68 | Địa chỉ FDE: 0x1135e0 | Kích thước: 192 bytes
//   0x31ea68: AA1303E0  mov      x0, x19
//   0x31ea6c: 17FE3888  b        #0x2acc8c
//   0x31ea70: AA1603E1  mov      x1, x22
//   0x31ea74: 17F91EC0  b        #0x166574
static inline uint64_t fde_func_1679_0x31ea68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31ea68ULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0x17fe3888ULL) ^ 0x1135e0ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1680 | PC: 0x31eb28 | FDE: 0x1136d8 | Size: 148 bytes
// Khung tháo gỡ #1680 | Địa chỉ PC: 0x31eb28 | Địa chỉ FDE: 0x1136d8 | Kích thước: 148 bytes
//   0x31eb28: A94B4FF4  ldp      x20, x19, [sp, #0xb0]
//   0x31eb2c: A94A57F6  ldp      x22, x21, [sp, #0xa0]
//   0x31eb30: A9495FF8  ldp      x24, x23, [sp, #0x90]
//   0x31eb34: A94867FA  ldp      x26, x25, [sp, #0x80]
static inline uint64_t fde_func_1680_0x31eb28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31eb28ULL ^ (static_cast<uint64_t>(0xa94b4ff4ULL) << 13);
    acc = (acc + a1 + 0xa94a57f6ULL) ^ 0x1136d8ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1681 | PC: 0x31ebbc | FDE: 0x1137c8 | Size: 180 bytes
// Khung tháo gỡ #1681 | Địa chỉ PC: 0x31ebbc | Địa chỉ FDE: 0x1137c8 | Kích thước: 180 bytes
//   0x31ebbc: 9ADA0909  udiv     x9, x8, x26
//   0x31ebc0: 9B1AA128  msub     x8, x9, x26, x8
//   0x31ebc4: D65F03C0  ret      
//   0x31ebc8: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1681_0x31ebbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31ebbcULL ^ (static_cast<uint64_t>(0x9ada0909ULL) << 13);
    acc = (acc + a1 + 0x9b1aa128ULL) ^ 0x1137c8ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1682 | PC: 0x31ec70 | FDE: 0x1138b8 | Size: 112 bytes
// Khung tháo gỡ #1682 | Địa chỉ PC: 0x31ec70 | Địa chỉ FDE: 0x1138b8 | Kích thước: 112 bytes
//   0x31ec70: AA1503E1  mov      x1, x21
//   0x31ec74: 17F8EBD8  b        #0x159bd4
//   0x31ec78: D101C3FF  sub      sp, sp, #0x70
//   0x31ec7c: F9001BF8  str      x24, [sp, #0x30]
static inline uint64_t fde_func_1682_0x31ec70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31ec70ULL ^ (static_cast<uint64_t>(0xaa1503e1ULL) << 13);
    acc = (acc + a1 + 0x17f8ebd8ULL) ^ 0x1138b8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1683 | PC: 0x31ece0 | FDE: 0x1139a8 | Size: 176 bytes
// Khung tháo gỡ #1683 | Địa chỉ PC: 0x31ece0 | Địa chỉ FDE: 0x1139a8 | Kích thước: 176 bytes
//   0x31ece0: AA0003F3  mov      x19, x0
//   0x31ece4: 91006000  add      x0, x0, #0x18
//   0x31ece8: 1400863A  b        #0x3405d0
//   0x31ecec: 910403E0  add      x0, sp, #0x100
static inline uint64_t fde_func_1683_0x31ece0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31ece0ULL ^ (static_cast<uint64_t>(0xaa0003f3ULL) << 13);
    acc = (acc + a1 + 0x91006000ULL) ^ 0x1139a8ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1684 | PC: 0x31ed90 | FDE: 0x113a98 | Size: 256 bytes
// Khung tháo gỡ #1684 | Địa chỉ PC: 0x31ed90 | Địa chỉ FDE: 0x113a98 | Kích thước: 256 bytes
//   0x31ed90: F1000F7F  cmp      x27, #3
//   0x31ed94: D1000768  sub      x8, x27, #1
//   0x31ed98: 1A9F27E9  cset     w9, lo
//   0x31ed9c: EA08037F  tst      x27, x8
static inline uint64_t fde_func_1684_0x31ed90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31ed90ULL ^ (static_cast<uint64_t>(0xf1000f7fULL) << 13);
    acc = (acc + a1 + 0xd1000768ULL) ^ 0x113a98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1685 | PC: 0x31ee98 | FDE: 0x113b88 | Size: 168 bytes
// Khung tháo gỡ #1685 | Địa chỉ PC: 0x31ee98 | Địa chỉ FDE: 0x113b88 | Kích thước: 168 bytes
//   0x31ee98: F9400109  ldr      x9, [x8]
//   0x31ee9c: F90002A9  str      x9, [x21]
//   0x31eea0: F9000115  str      x21, [x8]
//   0x31eea4: F94003F5  ldr      x21, [sp]
static inline uint64_t fde_func_1685_0x31ee98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31ee98ULL ^ (static_cast<uint64_t>(0xf9400109ULL) << 13);
    acc = (acc + a1 + 0xf90002a9ULL) ^ 0x113b88ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1686 | PC: 0x31ef40 | FDE: 0x113c78 | Size: 172 bytes
// Khung tháo gỡ #1686 | Địa chỉ PC: 0x31ef40 | Địa chỉ FDE: 0x113c78 | Kích thước: 172 bytes
//   0x31ef40: A95C4FF4  ldp      x20, x19, [sp, #0x1c0]
//   0x31ef44: A95B57F6  ldp      x22, x21, [sp, #0x1b0]
//   0x31ef48: A95A5FF8  ldp      x24, x23, [sp, #0x1a0]
//   0x31ef4c: A95967FA  ldp      x26, x25, [sp, #0x190]
static inline uint64_t fde_func_1686_0x31ef40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31ef40ULL ^ (static_cast<uint64_t>(0xa95c4ff4ULL) << 13);
    acc = (acc + a1 + 0xa95b57f6ULL) ^ 0x113c78ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1687 | PC: 0x31efec | FDE: 0x113d68 | Size: 152 bytes
// Khung tháo gỡ #1687 | Địa chỉ PC: 0x31efec | Địa chỉ FDE: 0x113d68 | Kích thước: 152 bytes
//   0x31efec: 910203E0  add      x0, sp, #0x80
//   0x31eff0: 17F8EAE4  b        #0x159b80
//   0x31eff4: 9100C3E0  add      x0, sp, #0x30
//   0x31eff8: 17F91D5F  b        #0x166574
static inline uint64_t fde_func_1687_0x31efec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31efecULL ^ (static_cast<uint64_t>(0x910203e0ULL) << 13);
    acc = (acc + a1 + 0x17f8eae4ULL) ^ 0x113d68ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1688 | PC: 0x31f084 | FDE: 0x113e58 | Size: 120 bytes
// Khung tháo gỡ #1688 | Địa chỉ PC: 0x31f084 | Địa chỉ FDE: 0x113e58 | Kích thước: 120 bytes
//   0x31f084: A94153F5  ldp      x21, x20, [sp, #0x10]
//   0x31f088: A8C35BFC  ldp      x28, x22, [sp], #0x30
//   0x31f08c: D65F03C0  ret      
//   0x31f090: AA1403E1  mov      x1, x20
static inline uint64_t fde_func_1688_0x31f084(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31f084ULL ^ (static_cast<uint64_t>(0xa94153f5ULL) << 13);
    acc = (acc + a1 + 0xa8c35bfcULL) ^ 0x113e58ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1689 | PC: 0x31f0fc | FDE: 0x113f48 | Size: 216 bytes
// Khung tháo gỡ #1689 | Địa chỉ PC: 0x31f0fc | Địa chỉ FDE: 0x113f48 | Kích thước: 216 bytes
//   0x31f0fc: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x31f100: 97F8EAA0  bl       #0x159b80
//   0x31f104: F9402FE0  ldr      x0, [sp, #0x58]
//   0x31f108: 394183E1  ldrb     w1, [sp, #0x60]
static inline uint64_t fde_func_1689_0x31f0fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31f0fcULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x97f8eaa0ULL) ^ 0x113f48ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1690 | PC: 0x31f1d4 | FDE: 0x114040 | Size: 132 bytes
// Khung tháo gỡ #1690 | Địa chỉ PC: 0x31f1d4 | Địa chỉ FDE: 0x114040 | Kích thước: 132 bytes
//   0x31f1d4: 9342FD08  asr      x8, x8, #2
//   0x31f1d8: EB01011F  cmp      x8, x1
//   0x31f1dc: 9A883020  csel     x0, x1, x8, lo
//   0x31f1e0: D65F03C0  ret      
static inline uint64_t fde_func_1690_0x31f1d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31f1d4ULL ^ (static_cast<uint64_t>(0x9342fd08ULL) << 13);
    acc = (acc + a1 + 0xeb01011fULL) ^ 0x114040ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1691 | PC: 0x31f258 | FDE: 0x114130 | Size: 256 bytes
// Khung tháo gỡ #1691 | Địa chỉ PC: 0x31f258 | Địa chỉ FDE: 0x114130 | Kích thước: 256 bytes
//   0x31f258: A9402428  ldp      x8, x9, [x1]
//   0x31f25c: F940050A  ldr      x10, [x8, #8]
//   0x31f260: F940012B  ldr      x11, [x9]
//   0x31f264: F900056A  str      x10, [x11, #8]
static inline uint64_t fde_func_1691_0x31f258(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31f258ULL ^ (static_cast<uint64_t>(0xa9402428ULL) << 13);
    acc = (acc + a1 + 0xf940050aULL) ^ 0x114130ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1692 | PC: 0x31f360 | FDE: 0x114228 | Size: 212 bytes
// Khung tháo gỡ #1692 | Địa chỉ PC: 0x31f360 | Địa chỉ FDE: 0x114228 | Kích thước: 212 bytes
//   0x31f360: F9400268  ldr      x8, [x19]
//   0x31f364: AA1303E0  mov      x0, x19
//   0x31f368: F9402108  ldr      x8, [x8, #0x40]
//   0x31f36c: D61F0100  br       x8
static inline uint64_t fde_func_1692_0x31f360(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31f360ULL ^ (static_cast<uint64_t>(0xf9400268ULL) << 13);
    acc = (acc + a1 + 0xaa1303e0ULL) ^ 0x114228ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1693 | PC: 0x31f434 | FDE: 0x114330 | Size: 188 bytes
// Khung tháo gỡ #1693 | Địa chỉ PC: 0x31f434 | Địa chỉ FDE: 0x114330 | Kích thước: 188 bytes
//   0x31f434: 52800142  mov      w2, #0xa
//   0x31f438: AA1F03E1  mov      x1, xzr
//   0x31f43c: 14008D21  b        #0x3428c0
//   0x31f440: D53BD05B  mrs      x27, tpidr_el0
static inline uint64_t fde_func_1693_0x31f434(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31f434ULL ^ (static_cast<uint64_t>(0x52800142ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e1ULL) ^ 0x114330ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1694 | PC: 0x31f4f0 | FDE: 0x114420 | Size: 148 bytes
// Khung tháo gỡ #1694 | Địa chỉ PC: 0x31f4f0 | Địa chỉ FDE: 0x114420 | Kích thước: 148 bytes
//   0x31f4f0: A9402668  ldp      x8, x9, [x19]
//   0x31f4f4: F9400D08  ldr      x8, [x8, #0x18]
//   0x31f4f8: 8B090009  add      x9, x0, x9
//   0x31f4fc: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1694_0x31f4f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31f4f0ULL ^ (static_cast<uint64_t>(0xa9402668ULL) << 13);
    acc = (acc + a1 + 0xf9400d08ULL) ^ 0x114420ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1695 | PC: 0x31f584 | FDE: 0x114510 | Size: 156 bytes
// Khung tháo gỡ #1695 | Địa chỉ PC: 0x31f584 | Địa chỉ FDE: 0x114510 | Kích thước: 156 bytes
//   0x31f584: AA1303E0  mov      x0, x19
//   0x31f588: 17F92404  b        #0x168598
//   0x31f58c: 9105C3FF  add      sp, sp, #0x170
//   0x31f590: D65F03C0  ret      
static inline uint64_t fde_func_1695_0x31f584(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31f584ULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0x17f92404ULL) ^ 0x114510ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1696 | PC: 0x31f620 | FDE: 0x114600 | Size: 184 bytes
// Khung tháo gỡ #1696 | Địa chỉ PC: 0x31f620 | Địa chỉ FDE: 0x114600 | Kích thước: 184 bytes
//   0x31f620: D1022008  sub      x8, x0, #0x88
//   0x31f624: F100001F  cmp      x0, #0
//   0x31f628: 9A8803E8  csel     x8, xzr, x8, eq
//   0x31f62c: D65F03C0  ret      
static inline uint64_t fde_func_1696_0x31f620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31f620ULL ^ (static_cast<uint64_t>(0xd1022008ULL) << 13);
    acc = (acc + a1 + 0xf100001fULL) ^ 0x114600ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1697 | PC: 0x31f6d8 | FDE: 0x1146f0 | Size: 124 bytes
// Khung tháo gỡ #1697 | Địa chỉ PC: 0x31f6d8 | Địa chỉ FDE: 0x1146f0 | Kích thước: 124 bytes
//   0x31f6d8: D1000748  sub      x8, x26, #1
//   0x31f6dc: EA08035F  tst      x26, x8
//   0x31f6e0: D65F03C0  ret      
//   0x31f6e4: F9400288  ldr      x8, [x20]
static inline uint64_t fde_func_1697_0x31f6d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31f6d8ULL ^ (static_cast<uint64_t>(0xd1000748ULL) << 13);
    acc = (acc + a1 + 0xea08035fULL) ^ 0x1146f0ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1698 | PC: 0x31f754 | FDE: 0x1147e0 | Size: 168 bytes
// Khung tháo gỡ #1698 | Địa chỉ PC: 0x31f754 | Địa chỉ FDE: 0x1147e0 | Kích thước: 168 bytes
//   0x31f754: AA0003F3  mov      x19, x0
//   0x31f758: F90007E8  str      x8, [sp, #8]
//   0x31f75c: D65F03C0  ret      
//   0x31f760: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1698_0x31f754(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31f754ULL ^ (static_cast<uint64_t>(0xaa0003f3ULL) << 13);
    acc = (acc + a1 + 0xf90007e8ULL) ^ 0x1147e0ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1699 | PC: 0x31f7fc | FDE: 0x1148d0 | Size: 156 bytes
// Khung tháo gỡ #1699 | Địa chỉ PC: 0x31f7fc | Địa chỉ FDE: 0x1148d0 | Kích thước: 156 bytes
//   0x31f7fc: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x31f800: 97F9111B  bl       #0x163c6c
//   0x31f804: AA1F03E0  mov      x0, xzr
//   0x31f808: F84107FE  ldr      x30, [sp], #0x10
static inline uint64_t fde_func_1699_0x31f7fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31f7fcULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x97f9111bULL) ^ 0x1148d0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1700 | PC: 0x31f898 | FDE: 0x1149c8 | Size: 152 bytes
// Khung tháo gỡ #1700 | Địa chỉ PC: 0x31f898 | Địa chỉ FDE: 0x1149c8 | Kích thước: 152 bytes
//   0x31f898: 910163E2  add      x2, sp, #0x58
//   0x31f89c: 910103E3  add      x3, sp, #0x40
//   0x31f8a0: D65F03C0  ret      
//   0x31f8a4: 9100A3E1  add      x1, sp, #0x28
static inline uint64_t fde_func_1700_0x31f898(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31f898ULL ^ (static_cast<uint64_t>(0x910163e2ULL) << 13);
    acc = (acc + a1 + 0x910103e3ULL) ^ 0x1149c8ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1701 | PC: 0x31f930 | FDE: 0x114ab8 | Size: 200 bytes
// Khung tháo gỡ #1701 | Địa chỉ PC: 0x31f930 | Địa chỉ FDE: 0x114ab8 | Kích thước: 200 bytes
//   0x31f930: 910083E1  add      x1, sp, #0x20
//   0x31f934: 52800023  mov      w3, #1
//   0x31f938: AA1303E0  mov      x0, x19
//   0x31f93c: 17FE86BC  b        #0x2c142c
static inline uint64_t fde_func_1701_0x31f930(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31f930ULL ^ (static_cast<uint64_t>(0x910083e1ULL) << 13);
    acc = (acc + a1 + 0x52800023ULL) ^ 0x114ab8ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1702 | PC: 0x31f9f8 | FDE: 0x114ba8 | Size: 128 bytes
// Khung tháo gỡ #1702 | Địa chỉ PC: 0x31f9f8 | Địa chỉ FDE: 0x114ba8 | Kích thước: 128 bytes
//   0x31f9f8: AA0003F5  mov      x21, x0
//   0x31f9fc: F9000008  str      x8, [x0]
//   0x31fa00: 3C808000  stur     q0, [x0, #8]
//   0x31fa04: 91006000  add      x0, x0, #0x18
static inline uint64_t fde_func_1702_0x31f9f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31f9f8ULL ^ (static_cast<uint64_t>(0xaa0003f5ULL) << 13);
    acc = (acc + a1 + 0xf9000008ULL) ^ 0x114ba8ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1703 | PC: 0x31fa78 | FDE: 0x114c98 | Size: 140 bytes
// Khung tháo gỡ #1703 | Địa chỉ PC: 0x31fa78 | Địa chỉ FDE: 0x114c98 | Kích thước: 140 bytes
//   0x31fa78: AA1403E1  mov      x1, x20
//   0x31fa7c: 17F8E84A  b        #0x159ba4
//   0x31fa80: 910003E0  mov      x0, sp
//   0x31fa84: AA1303E1  mov      x1, x19
static inline uint64_t fde_func_1703_0x31fa78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31fa78ULL ^ (static_cast<uint64_t>(0xaa1403e1ULL) << 13);
    acc = (acc + a1 + 0x17f8e84aULL) ^ 0x114c98ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1704 | PC: 0x31fb04 | FDE: 0x114d90 | Size: 256 bytes
// Khung tháo gỡ #1704 | Địa chỉ PC: 0x31fb04 | Địa chỉ FDE: 0x114d90 | Kích thước: 256 bytes
//   0x31fb04: A9402269  ldp      x9, x8, [x19]
//   0x31fb08: 8B080008  add      x8, x0, x8
//   0x31fb0c: 39400D08  ldrb     w8, [x8, #3]
//   0x31fb10: F9400929  ldr      x9, [x9, #0x10]
static inline uint64_t fde_func_1704_0x31fb04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31fb04ULL ^ (static_cast<uint64_t>(0xa9402269ULL) << 13);
    acc = (acc + a1 + 0x8b080008ULL) ^ 0x114d90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1705 | PC: 0x31fc28 | FDE: 0x114e80 | Size: 256 bytes
// Khung tháo gỡ #1705 | Địa chỉ PC: 0x31fc28 | Địa chỉ FDE: 0x114e80 | Kích thước: 256 bytes
//   0x31fc28: B9400A82  ldr      w2, [x20, #8]
//   0x31fc2c: AA1303E1  mov      x1, x19
//   0x31fc30: D65F03C0  ret      
//   0x31fc34: AA1303EA  mov      x10, x19
static inline uint64_t fde_func_1705_0x31fc28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31fc28ULL ^ (static_cast<uint64_t>(0xb9400a82ULL) << 13);
    acc = (acc + a1 + 0xaa1303e1ULL) ^ 0x114e80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1706 | PC: 0x31fd90 | FDE: 0x114f70 | Size: 160 bytes
// Khung tháo gỡ #1706 | Địa chỉ PC: 0x31fd90 | Địa chỉ FDE: 0x114f70 | Kích thước: 160 bytes
//   0x31fd90: 9100A3E0  add      x0, sp, #0x28
//   0x31fd94: 17F919F8  b        #0x166574
//   0x31fd98: A90F6FFC  stp      x28, x27, [sp, #0xf0]
//   0x31fd9c: A91067FA  stp      x26, x25, [sp, #0x100]
static inline uint64_t fde_func_1706_0x31fd90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31fd90ULL ^ (static_cast<uint64_t>(0x9100a3e0ULL) << 13);
    acc = (acc + a1 + 0x17f919f8ULL) ^ 0x114f70ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1707 | PC: 0x31fe30 | FDE: 0x115060 | Size: 220 bytes
// Khung tháo gỡ #1707 | Địa chỉ PC: 0x31fe30 | Địa chỉ FDE: 0x115060 | Kích thước: 220 bytes
//   0x31fe30: D53BD056  mrs      x22, tpidr_el0
//   0x31fe34: F94016C8  ldr      x8, [x22, #0x28]
//   0x31fe38: F90027E8  str      x8, [sp, #0x48]
//   0x31fe3c: D65F03C0  ret      
static inline uint64_t fde_func_1707_0x31fe30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31fe30ULL ^ (static_cast<uint64_t>(0xd53bd056ULL) << 13);
    acc = (acc + a1 + 0xf94016c8ULL) ^ 0x115060ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #1708 | PC: 0x31ff0c | FDE: 0x115150 | Size: 188 bytes
// Khung tháo gỡ #1708 | Địa chỉ PC: 0x31ff0c | Địa chỉ FDE: 0x115150 | Kích thước: 188 bytes
//   0x31ff0c: AA0003F6  mov      x22, x0
//   0x31ff10: F9000008  str      x8, [x0]
//   0x31ff14: 3C808000  stur     q0, [x0, #8]
//   0x31ff18: 91006000  add      x0, x0, #0x18
static inline uint64_t fde_func_1708_0x31ff0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31ff0cULL ^ (static_cast<uint64_t>(0xaa0003f6ULL) << 13);
    acc = (acc + a1 + 0xf9000008ULL) ^ 0x115150ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1709 | PC: 0x31ffc8 | FDE: 0x115240 | Size: 124 bytes
// Khung tháo gỡ #1709 | Địa chỉ PC: 0x31ffc8 | Địa chỉ FDE: 0x115240 | Kích thước: 124 bytes
//   0x31ffc8: 910003E0  mov      x0, sp
//   0x31ffcc: 17F9196A  b        #0x166574
//   0x31ffd0: AA0003F3  mov      x19, x0
//   0x31ffd4: F90037E8  str      x8, [sp, #0x68]
static inline uint64_t fde_func_1709_0x31ffc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31ffc8ULL ^ (static_cast<uint64_t>(0x910003e0ULL) << 13);
    acc = (acc + a1 + 0x17f9196aULL) ^ 0x115240ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1710 | PC: 0x320044 | FDE: 0x115338 | Size: 104 bytes
// Khung tháo gỡ #1710 | Địa chỉ PC: 0x320044 | Địa chỉ FDE: 0x115338 | Kích thước: 104 bytes
//   0x320044: F9000500  str      x0, [x8, #8]
//   0x320048: 1400804E  b        #0x340180
//   0x32004c: D37DF000  lsl      x0, x0, #3
//   0x320050: 1400803C  b        #0x340140
static inline uint64_t fde_func_1710_0x320044(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x320044ULL ^ (static_cast<uint64_t>(0xf9000500ULL) << 13);
    acc = (acc + a1 + 0x1400804eULL) ^ 0x115338ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1711 | PC: 0x3200ac | FDE: 0x115428 | Size: 144 bytes
// Khung tháo gỡ #1711 | Địa chỉ PC: 0x3200ac | Địa chỉ FDE: 0x115428 | Kích thước: 144 bytes
//   0x3200ac: AA0203F4  mov      x20, x2
//   0x3200b0: AA0103F5  mov      x21, x1
//   0x3200b4: D65F03C0  ret      
//   0x3200b8: 9AD90A88  udiv     x8, x20, x25
static inline uint64_t fde_func_1711_0x3200ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3200acULL ^ (static_cast<uint64_t>(0xaa0203f4ULL) << 13);
    acc = (acc + a1 + 0xaa0103f5ULL) ^ 0x115428ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1712 | PC: 0x32013c | FDE: 0x115520 | Size: 148 bytes
// Khung tháo gỡ #1712 | Địa chỉ PC: 0x32013c | Địa chỉ FDE: 0x115520 | Kích thước: 148 bytes
//   0x32013c: AA1503E0  mov      x0, x21
//   0x320140: 17F9134D  b        #0x164e74
//   0x320144: AA1503E0  mov      x0, x21
//   0x320148: 17F9536F  b        #0x174f04
static inline uint64_t fde_func_1712_0x32013c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32013cULL ^ (static_cast<uint64_t>(0xaa1503e0ULL) << 13);
    acc = (acc + a1 + 0x17f9134dULL) ^ 0x115520ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1713 | PC: 0x3201d0 | FDE: 0x115610 | Size: 256 bytes
// Khung tháo gỡ #1713 | Địa chỉ PC: 0x3201d0 | Địa chỉ FDE: 0x115610 | Kích thước: 256 bytes
//   0x3201d0: F2CF3729  movk     x9, #0x79b9, lsl #32
//   0x3201d4: F940026A  ldr      x10, [x19]
//   0x3201d8: F2F3C6E9  movk     x9, #0x9e37, lsl #48
//   0x3201dc: 9B097F28  mul      x8, x25, x9
static inline uint64_t fde_func_1713_0x3201d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3201d0ULL ^ (static_cast<uint64_t>(0xf2cf3729ULL) << 13);
    acc = (acc + a1 + 0xf940026aULL) ^ 0x115610ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1714 | PC: 0x3202d0 | FDE: 0x115700 | Size: 116 bytes
// Khung tháo gỡ #1714 | Địa chỉ PC: 0x3202d0 | Địa chỉ FDE: 0x115700 | Kích thước: 116 bytes
//   0x3202d0: EB01011F  cmp      x8, x1
//   0x3202d4: 9A883020  csel     x0, x1, x8, lo
//   0x3202d8: D65F03C0  ret      
//   0x3202dc: A9007E7F  stp      xzr, xzr, [x19]
static inline uint64_t fde_func_1714_0x3202d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3202d0ULL ^ (static_cast<uint64_t>(0xeb01011fULL) << 13);
    acc = (acc + a1 + 0x9a883020ULL) ^ 0x115700ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1715 | PC: 0x320344 | FDE: 0x1157f0 | Size: 148 bytes
// Khung tháo gỡ #1715 | Địa chỉ PC: 0x320344 | Địa chỉ FDE: 0x1157f0 | Kích thước: 148 bytes
//   0x320344: F94003E8  ldr      x8, [sp]
//   0x320348: 910083E0  add      x0, sp, #0x20
//   0x32034c: F90002E8  str      x8, [x23]
//   0x320350: 17F8E60C  b        #0x159b80
static inline uint64_t fde_func_1715_0x320344(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x320344ULL ^ (static_cast<uint64_t>(0xf94003e8ULL) << 13);
    acc = (acc + a1 + 0x910083e0ULL) ^ 0x1157f0ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1716 | PC: 0x3203d8 | FDE: 0x1158e0 | Size: 200 bytes
// Khung tháo gỡ #1716 | Địa chỉ PC: 0x3203d8 | Địa chỉ FDE: 0x1158e0 | Kích thước: 200 bytes
//   0x3203d8: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x3203dc: AA0103F3  mov      x19, x1
//   0x3203e0: AA0003F4  mov      x20, x0
//   0x3203e4: 97F90F4B  bl       #0x164110
static inline uint64_t fde_func_1716_0x3203d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3203d8ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xaa0103f3ULL) ^ 0x1158e0ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1717 | PC: 0x3204a0 | FDE: 0x1159e8 | Size: 192 bytes
// Khung tháo gỡ #1717 | Địa chỉ PC: 0x3204a0 | Địa chỉ FDE: 0x1159e8 | Kích thước: 192 bytes
//   0x3204a0: B9402028  ldr      w8, [x1, #0x20]
//   0x3204a4: AA0003F3  mov      x19, x0
//   0x3204a8: B9002008  str      w8, [x0, #0x20]
//   0x3204ac: F9400421  ldr      x1, [x1, #8]
static inline uint64_t fde_func_1717_0x3204a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3204a0ULL ^ (static_cast<uint64_t>(0xb9402028ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1159e8ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1718 | PC: 0x320560 | FDE: 0x115ad8 | Size: 144 bytes
// Khung tháo gỡ #1718 | Địa chỉ PC: 0x320560 | Địa chỉ FDE: 0x115ad8 | Kích thước: 144 bytes
//   0x320560: 52800021  mov      w1, #1
//   0x320564: AA1303E0  mov      x0, x19
//   0x320568: 17F903A5  b        #0x1613fc
//   0x32056c: 2A1F03E3  mov      w3, wzr
static inline uint64_t fde_func_1718_0x320560(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x320560ULL ^ (static_cast<uint64_t>(0x52800021ULL) << 13);
    acc = (acc + a1 + 0xaa1303e0ULL) ^ 0x115ad8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1719 | PC: 0x3205f0 | FDE: 0x115bc8 | Size: 160 bytes
// Khung tháo gỡ #1719 | Địa chỉ PC: 0x3205f0 | Địa chỉ FDE: 0x115bc8 | Kích thước: 160 bytes
//   0x3205f0: 910143E0  add      x0, sp, #0x50
//   0x3205f4: 14007FF7  b        #0x3405d0
//   0x3205f8: 910143E0  add      x0, sp, #0x50
//   0x3205fc: 17F917DE  b        #0x166574
static inline uint64_t fde_func_1719_0x3205f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3205f0ULL ^ (static_cast<uint64_t>(0x910143e0ULL) << 13);
    acc = (acc + a1 + 0x14007ff7ULL) ^ 0x115bc8ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1720 | PC: 0x320690 | FDE: 0x115cb8 | Size: 204 bytes
// Khung tháo gỡ #1720 | Địa chỉ PC: 0x320690 | Địa chỉ FDE: 0x115cb8 | Kích thước: 204 bytes
//   0x320690: F9400814  ldr      x20, [x0, #0x10]
//   0x320694: AA0003F3  mov      x19, x0
//   0x320698: D65F03C0  ret      
//   0x32069c: D53BD058  mrs      x24, tpidr_el0
static inline uint64_t fde_func_1720_0x320690(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x320690ULL ^ (static_cast<uint64_t>(0xf9400814ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x115cb8ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1721 | PC: 0x32075c | FDE: 0x115da8 | Size: 180 bytes
// Khung tháo gỡ #1721 | Địa chỉ PC: 0x32075c | Địa chỉ FDE: 0x115da8 | Kích thước: 180 bytes
//   0x32075c: D53BD054  mrs      x20, tpidr_el0
//   0x320760: F9401688  ldr      x8, [x20, #0x28]
//   0x320764: AA0003F3  mov      x19, x0
//   0x320768: 910023E0  add      x0, sp, #8
static inline uint64_t fde_func_1721_0x32075c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32075cULL ^ (static_cast<uint64_t>(0xd53bd054ULL) << 13);
    acc = (acc + a1 + 0xf9401688ULL) ^ 0x115da8ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1722 | PC: 0x320810 | FDE: 0x115ea0 | Size: 140 bytes
// Khung tháo gỡ #1722 | Địa chỉ PC: 0x320810 | Địa chỉ FDE: 0x115ea0 | Kích thước: 140 bytes
//   0x320810: A94153F5  ldp      x21, x20, [sp, #0x10]
//   0x320814: F84307F6  ldr      x22, [sp], #0x30
//   0x320818: 14007EE6  b        #0x3403b0
//   0x32081c: AA1603E1  mov      x1, x22
static inline uint64_t fde_func_1722_0x320810(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x320810ULL ^ (static_cast<uint64_t>(0xa94153f5ULL) << 13);
    acc = (acc + a1 + 0xf84307f6ULL) ^ 0x115ea0ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1723 | PC: 0x32089c | FDE: 0x115f90 | Size: 256 bytes
// Khung tháo gỡ #1723 | Địa chỉ PC: 0x32089c | Địa chỉ FDE: 0x115f90 | Kích thước: 256 bytes
//   0x32089c: D53BD055  mrs      x21, tpidr_el0
//   0x3208a0: F94016A8  ldr      x8, [x21, #0x28]
//   0x3208a4: AA0103F4  mov      x20, x1
//   0x3208a8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1723_0x32089c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32089cULL ^ (static_cast<uint64_t>(0xd53bd055ULL) << 13);
    acc = (acc + a1 + 0xf94016a8ULL) ^ 0x115f90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1724 | PC: 0x3209d8 | FDE: 0x116088 | Size: 256 bytes
// Khung tháo gỡ #1724 | Địa chỉ PC: 0x3209d8 | Địa chỉ FDE: 0x116088 | Kích thước: 256 bytes
//   0x3209d8: D28F82AA  mov      x10, #0x7c15
//   0x3209dc: 9B092328  madd     x8, x25, x9, x8
//   0x3209e0: B980111C  ldrsw    x28, [x8, #0x10]
//   0x3209e4: F9002FE8  str      x8, [sp, #0x58]
static inline uint64_t fde_func_1724_0x3209d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3209d8ULL ^ (static_cast<uint64_t>(0xd28f82aaULL) << 13);
    acc = (acc + a1 + 0x9b092328ULL) ^ 0x116088ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1725 | PC: 0x320b24 | FDE: 0x116178 | Size: 140 bytes
// Khung tháo gỡ #1725 | Địa chỉ PC: 0x320b24 | Địa chỉ FDE: 0x116178 | Kích thước: 140 bytes
//   0x320b24: F9400A65  ldr      x5, [x19, #0x10]
//   0x320b28: F0FFEA81  adrp     x1, #0x73000
//   0x320b2c: 910163F7  add      x23, sp, #0x58
//   0x320b30: 9101A821  add      x1, x1, #0x6a
static inline uint64_t fde_func_1725_0x320b24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x320b24ULL ^ (static_cast<uint64_t>(0xf9400a65ULL) << 13);
    acc = (acc + a1 + 0xf0ffea81ULL) ^ 0x116178ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1726 | PC: 0x320bb0 | FDE: 0x116268 | Size: 184 bytes
// Khung tháo gỡ #1726 | Địa chỉ PC: 0x320bb0 | Địa chỉ FDE: 0x116268 | Kích thước: 184 bytes
//   0x320bb0: 9100C3E0  add      x0, sp, #0x30
//   0x320bb4: 14007D93  b        #0x340200
//   0x320bb8: 910063E1  add      x1, sp, #0x18
//   0x320bbc: AA1403E0  mov      x0, x20
static inline uint64_t fde_func_1726_0x320bb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x320bb0ULL ^ (static_cast<uint64_t>(0x9100c3e0ULL) << 13);
    acc = (acc + a1 + 0x14007d93ULL) ^ 0x116268ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1727 | PC: 0x320c68 | FDE: 0x116358 | Size: 180 bytes
// Khung tháo gỡ #1727 | Địa chỉ PC: 0x320c68 | Địa chỉ FDE: 0x116358 | Kích thước: 180 bytes
//   0x320c68: F9400508  ldr      x8, [x8, #8]
//   0x320c6c: B100051F  cmn      x8, #1
//   0x320c70: D65F03C0  ret      
//   0x320c74: AA0003F7  mov      x23, x0
static inline uint64_t fde_func_1727_0x320c68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x320c68ULL ^ (static_cast<uint64_t>(0xf9400508ULL) << 13);
    acc = (acc + a1 + 0xb100051fULL) ^ 0x116358ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1728 | PC: 0x320d1c | FDE: 0x116448 | Size: 88 bytes
// Khung tháo gỡ #1728 | Địa chỉ PC: 0x320d1c | Địa chỉ FDE: 0x116448 | Kích thước: 88 bytes
//   0x320d1c: AA1603E0  mov      x0, x22
//   0x320d20: 14007E0C  b        #0x340550
//   0x320d24: AA1603E0  mov      x0, x22
//   0x320d28: 17FD7412  b        #0x27dd70
static inline uint64_t fde_func_1728_0x320d1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x320d1cULL ^ (static_cast<uint64_t>(0xaa1603e0ULL) << 13);
    acc = (acc + a1 + 0x14007e0cULL) ^ 0x116448ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1729 | PC: 0x320d74 | FDE: 0x116538 | Size: 188 bytes
// Khung tháo gỡ #1729 | Địa chỉ PC: 0x320d74 | Địa chỉ FDE: 0x116538 | Kích thước: 188 bytes
//   0x320d74: 910003E0  mov      x0, sp
//   0x320d78: 17FC249B  b        #0x229fe4
//   0x320d7c: D53BD057  mrs      x23, tpidr_el0
//   0x320d80: F94016E8  ldr      x8, [x23, #0x28]
static inline uint64_t fde_func_1729_0x320d74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x320d74ULL ^ (static_cast<uint64_t>(0x910003e0ULL) << 13);
    acc = (acc + a1 + 0x17fc249bULL) ^ 0x116538ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1730 | PC: 0x320e30 | FDE: 0x116628 | Size: 188 bytes
// Khung tháo gỡ #1730 | Địa chỉ PC: 0x320e30 | Địa chỉ FDE: 0x116628 | Kích thước: 188 bytes
//   0x320e30: 528000A3  mov      w3, #5
//   0x320e34: 910023F4  add      x20, sp, #8
//   0x320e38: 14008026  b        #0x340ed0
//   0x320e3c: D1000768  sub      x8, x27, #1
static inline uint64_t fde_func_1730_0x320e30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x320e30ULL ^ (static_cast<uint64_t>(0x528000a3ULL) << 13);
    acc = (acc + a1 + 0x910023f4ULL) ^ 0x116628ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1731 | PC: 0x320eec | FDE: 0x116718 | Size: 152 bytes
// Khung tháo gỡ #1731 | Địa chỉ PC: 0x320eec | Địa chỉ FDE: 0x116718 | Kích thước: 152 bytes
//   0x320eec: F94083E8  ldr      x8, [sp, #0x100]
//   0x320ef0: AA0003E1  mov      x1, x0
//   0x320ef4: AA0803E0  mov      x0, x8
//   0x320ef8: 14007D16  b        #0x340350
static inline uint64_t fde_func_1731_0x320eec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x320eecULL ^ (static_cast<uint64_t>(0xf94083e8ULL) << 13);
    acc = (acc + a1 + 0xaa0003e1ULL) ^ 0x116718ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1732 | PC: 0x320f84 | FDE: 0x116808 | Size: 228 bytes
// Khung tháo gỡ #1732 | Địa chỉ PC: 0x320f84 | Địa chỉ FDE: 0x116808 | Kích thước: 228 bytes
//   0x320f84: 910263E0  add      x0, sp, #0x98
//   0x320f88: 17F8E313  b        #0x159bd4
//   0x320f8c: F940C508  ldr      x8, [x8, #0x188]
//   0x320f90: D61F0100  br       x8
static inline uint64_t fde_func_1732_0x320f84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x320f84ULL ^ (static_cast<uint64_t>(0x910263e0ULL) << 13);
    acc = (acc + a1 + 0x17f8e313ULL) ^ 0x116808ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1733 | PC: 0x321068 | FDE: 0x1168f8 | Size: 220 bytes
// Khung tháo gỡ #1733 | Địa chỉ PC: 0x321068 | Địa chỉ FDE: 0x1168f8 | Kích thước: 220 bytes
//   0x321068: F9400501  ldr      x1, [x8, #8]
//   0x32106c: F84207F4  ldr      x20, [sp], #0x20
//   0x321070: D61F0020  br       x1
//   0x321074: D1000708  sub      x8, x24, #1
static inline uint64_t fde_func_1733_0x321068(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x321068ULL ^ (static_cast<uint64_t>(0xf9400501ULL) << 13);
    acc = (acc + a1 + 0xf84207f4ULL) ^ 0x1168f8ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #1734 | PC: 0x321144 | FDE: 0x1169e8 | Size: 184 bytes
// Khung tháo gỡ #1734 | Địa chỉ PC: 0x321144 | Địa chỉ FDE: 0x1169e8 | Kích thước: 184 bytes
//   0x321144: 910043A1  add      x1, x29, #0x10
//   0x321148: AA1503E0  mov      x0, x21
//   0x32114c: 17F92196  b        #0x1697a4
//   0x321150: F9400269  ldr      x9, [x19]
static inline uint64_t fde_func_1734_0x321144(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x321144ULL ^ (static_cast<uint64_t>(0x910043a1ULL) << 13);
    acc = (acc + a1 + 0xaa1503e0ULL) ^ 0x1169e8ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1735 | PC: 0x3211fc | FDE: 0x116ad8 | Size: 136 bytes
// Khung tháo gỡ #1735 | Địa chỉ PC: 0x3211fc | Địa chỉ FDE: 0x116ad8 | Kích thước: 136 bytes
//   0x3211fc: AA1603E0  mov      x0, x22
//   0x321200: AA1703E1  mov      x1, x23
//   0x321204: 14007E6B  b        #0x340bb0
//   0x321208: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1735_0x3211fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3211fcULL ^ (static_cast<uint64_t>(0xaa1603e0ULL) << 13);
    acc = (acc + a1 + 0xaa1703e1ULL) ^ 0x116ad8ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1736 | PC: 0x321284 | FDE: 0x116bd0 | Size: 212 bytes
// Khung tháo gỡ #1736 | Địa chỉ PC: 0x321284 | Địa chỉ FDE: 0x116bd0 | Kích thước: 212 bytes
//   0x321284: AA0003F3  mov      x19, x0
//   0x321288: 910003E0  mov      x0, sp
//   0x32128c: D65F03C0  ret      
//   0x321290: F84207F4  ldr      x20, [sp], #0x20
static inline uint64_t fde_func_1736_0x321284(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x321284ULL ^ (static_cast<uint64_t>(0xaa0003f3ULL) << 13);
    acc = (acc + a1 + 0x910003e0ULL) ^ 0x116bd0ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1737 | PC: 0x321358 | FDE: 0x116cc8 | Size: 208 bytes
// Khung tháo gỡ #1737 | Địa chỉ PC: 0x321358 | Địa chỉ FDE: 0x116cc8 | Kích thước: 208 bytes
//   0x321358: AA0003F4  mov      x20, x0
//   0x32135c: AA0103E0  mov      x0, x1
//   0x321360: AA0103F3  mov      x19, x1
//   0x321364: 14007C87  b        #0x340580
static inline uint64_t fde_func_1737_0x321358(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x321358ULL ^ (static_cast<uint64_t>(0xaa0003f4ULL) << 13);
    acc = (acc + a1 + 0xaa0103e0ULL) ^ 0x116cc8ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1738 | PC: 0x321428 | FDE: 0x116dc0 | Size: 256 bytes
// Khung tháo gỡ #1738 | Địa chỉ PC: 0x321428 | Địa chỉ FDE: 0x116dc0 | Kích thước: 256 bytes
//   0x321428: B9401288  ldr      w8, [x20, #0x10]
//   0x32142c: 7100111F  cmp      w8, #4
//   0x321430: D65F03C0  ret      
//   0x321434: F940A7E9  ldr      x9, [sp, #0x148]
static inline uint64_t fde_func_1738_0x321428(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x321428ULL ^ (static_cast<uint64_t>(0xb9401288ULL) << 13);
    acc = (acc + a1 + 0x7100111fULL) ^ 0x116dc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1739 | PC: 0x321540 | FDE: 0x116eb0 | Size: 188 bytes
// Khung tháo gỡ #1739 | Địa chỉ PC: 0x321540 | Địa chỉ FDE: 0x116eb0 | Kích thước: 188 bytes
//   0x321540: D1022008  sub      x8, x0, #0x88
//   0x321544: F100001F  cmp      x0, #0
//   0x321548: 9A8803E8  csel     x8, xzr, x8, eq
//   0x32154c: F9405D00  ldr      x0, [x8, #0xb8]
static inline uint64_t fde_func_1739_0x321540(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x321540ULL ^ (static_cast<uint64_t>(0xd1022008ULL) << 13);
    acc = (acc + a1 + 0xf100001fULL) ^ 0x116eb0ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1740 | PC: 0x3215fc | FDE: 0x116fa0 | Size: 248 bytes
// Khung tháo gỡ #1740 | Địa chỉ PC: 0x3215fc | Địa chỉ FDE: 0x116fa0 | Kích thước: 248 bytes
//   0x3215fc: D0FFEB01  adrp     x1, #0x83000
//   0x321600: D0FFEA62  adrp     x2, #0x6f000
//   0x321604: 9136D021  add      x1, x1, #0xdb4
//   0x321608: 91290442  add      x2, x2, #0xa41
static inline uint64_t fde_func_1740_0x3215fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3215fcULL ^ (static_cast<uint64_t>(0xd0ffeb01ULL) << 13);
    acc = (acc + a1 + 0xd0ffea62ULL) ^ 0x116fa0ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1741 | PC: 0x3216f4 | FDE: 0x117090 | Size: 256 bytes
// Khung tháo gỡ #1741 | Địa chỉ PC: 0x3216f4 | Địa chỉ FDE: 0x117090 | Kích thước: 256 bytes
//   0x3216f4: 9101C3E0  add      x0, sp, #0x70
//   0x3216f8: 17F8EECB  b        #0x15d224
//   0x3216fc: 910163E1  add      x1, sp, #0x58
//   0x321700: AA1403E0  mov      x0, x20
static inline uint64_t fde_func_1741_0x3216f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3216f4ULL ^ (static_cast<uint64_t>(0x9101c3e0ULL) << 13);
    acc = (acc + a1 + 0x17f8eecbULL) ^ 0x117090ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1742 | PC: 0x3217fc | FDE: 0x117180 | Size: 204 bytes
// Khung tháo gỡ #1742 | Địa chỉ PC: 0x3217fc | Địa chỉ FDE: 0x117180 | Kích thước: 204 bytes
//   0x3217fc: 9100E3E1  add      x1, sp, #0x38
//   0x321800: AA1403E0  mov      x0, x20
//   0x321804: D65F03C0  ret      
//   0x321808: D53BD056  mrs      x22, tpidr_el0
static inline uint64_t fde_func_1742_0x3217fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3217fcULL ^ (static_cast<uint64_t>(0x9100e3e1ULL) << 13);
    acc = (acc + a1 + 0xaa1403e0ULL) ^ 0x117180ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1743 | PC: 0x3218c8 | FDE: 0x117270 | Size: 208 bytes
// Khung tháo gỡ #1743 | Địa chỉ PC: 0x3218c8 | Địa chỉ FDE: 0x117270 | Kích thước: 208 bytes
//   0x3218c8: F9400529  ldr      x9, [x9, #8]
//   0x3218cc: D100078A  sub      x10, x28, #1
//   0x3218d0: EA0A039F  tst      x28, x10
//   0x3218d4: D65F03C0  ret      
static inline uint64_t fde_func_1743_0x3218c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3218c8ULL ^ (static_cast<uint64_t>(0xf9400529ULL) << 13);
    acc = (acc + a1 + 0xd100078aULL) ^ 0x117270ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1744 | PC: 0x321998 | FDE: 0x117368 | Size: 128 bytes
// Khung tháo gỡ #1744 | Địa chỉ PC: 0x321998 | Địa chỉ FDE: 0x117368 | Kích thước: 128 bytes
//   0x321998: AA1503E1  mov      x1, x21
//   0x32199c: 14007AC5  b        #0x3404b0
//   0x3219a0: F9000FE8  str      x8, [sp, #0x18]
//   0x3219a4: 17F8E08C  b        #0x159bd4
static inline uint64_t fde_func_1744_0x321998(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x321998ULL ^ (static_cast<uint64_t>(0xaa1503e1ULL) << 13);
    acc = (acc + a1 + 0x14007ac5ULL) ^ 0x117368ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1745 | PC: 0x321a18 | FDE: 0x117458 | Size: 164 bytes
// Khung tháo gỡ #1745 | Địa chỉ PC: 0x321a18 | Địa chỉ FDE: 0x117458 | Kích thước: 164 bytes
//   0x321a18: AA0003F3  mov      x19, x0
//   0x321a1c: 14007B29  b        #0x3406c0
//   0x321a20: AA0003F3  mov      x19, x0
//   0x321a24: 2A0103F4  mov      w20, w1
static inline uint64_t fde_func_1745_0x321a18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x321a18ULL ^ (static_cast<uint64_t>(0xaa0003f3ULL) << 13);
    acc = (acc + a1 + 0x14007b29ULL) ^ 0x117458ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1746 | PC: 0x321abc | FDE: 0x117558 | Size: 124 bytes
// Khung tháo gỡ #1746 | Địa chỉ PC: 0x321abc | Địa chỉ FDE: 0x117558 | Kích thước: 124 bytes
//   0x321abc: AA1403E0  mov      x0, x20
//   0x321ac0: 17FD3077  b        #0x26dc9c
//   0x321ac4: AA1403E0  mov      x0, x20
//   0x321ac8: 17F93F12  b        #0x171710
static inline uint64_t fde_func_1746_0x321abc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x321abcULL ^ (static_cast<uint64_t>(0xaa1403e0ULL) << 13);
    acc = (acc + a1 + 0x17fd3077ULL) ^ 0x117558ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1747 | PC: 0x321b38 | FDE: 0x117648 | Size: 156 bytes
// Khung tháo gỡ #1747 | Địa chỉ PC: 0x321b38 | Địa chỉ FDE: 0x117648 | Kích thước: 156 bytes
//   0x321b38: F9404FE0  ldr      x0, [sp, #0x98]
//   0x321b3c: B940A3E8  ldr      w8, [sp, #0xa0]
//   0x321b40: AA1303E2  mov      x2, x19
//   0x321b44: 8B080C01  add      x1, x0, x8, lsl #3
static inline uint64_t fde_func_1747_0x321b38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x321b38ULL ^ (static_cast<uint64_t>(0xf9404fe0ULL) << 13);
    acc = (acc + a1 + 0xb940a3e8ULL) ^ 0x117648ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1748 | PC: 0x321bd4 | FDE: 0x117738 | Size: 124 bytes
// Khung tháo gỡ #1748 | Địa chỉ PC: 0x321bd4 | Địa chỉ FDE: 0x117738 | Kích thước: 124 bytes
//   0x321bd4: 9100C3E2  add      x2, sp, #0x30
//   0x321bd8: 910063E3  add      x3, sp, #0x18
//   0x321bdc: D65F03C0  ret      
//   0x321be0: 0EA98508  add      v8.2s, v8.2s, v9.2s
static inline uint64_t fde_func_1748_0x321bd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x321bd4ULL ^ (static_cast<uint64_t>(0x9100c3e2ULL) << 13);
    acc = (acc + a1 + 0x910063e3ULL) ^ 0x117738ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1749 | PC: 0x321c50 | FDE: 0x117828 | Size: 180 bytes
// Khung tháo gỡ #1749 | Địa chỉ PC: 0x321c50 | Địa chỉ FDE: 0x117828 | Kích thước: 180 bytes
//   0x321c50: 910103E0  add      x0, sp, #0x40
//   0x321c54: 17F91248  b        #0x166574
//   0x321c58: 910023E2  add      x2, sp, #8
//   0x321c5c: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1749_0x321c50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x321c50ULL ^ (static_cast<uint64_t>(0x910103e0ULL) << 13);
    acc = (acc + a1 + 0x17f91248ULL) ^ 0x117828ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1750 | PC: 0x321d04 | FDE: 0x117918 | Size: 232 bytes
// Khung tháo gỡ #1750 | Địa chỉ PC: 0x321d04 | Địa chỉ FDE: 0x117918 | Kích thước: 232 bytes
//   0x321d04: F94002E8  ldr      x8, [x23]
//   0x321d08: AA1703E0  mov      x0, x23
//   0x321d0c: D65F03C0  ret      
//   0x321d10: F9400E74  ldr      x20, [x19, #0x18]
static inline uint64_t fde_func_1750_0x321d04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x321d04ULL ^ (static_cast<uint64_t>(0xf94002e8ULL) << 13);
    acc = (acc + a1 + 0xaa1703e0ULL) ^ 0x117918ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1751 | PC: 0x321dec | FDE: 0x117a08 | Size: 216 bytes
// Khung tháo gỡ #1751 | Địa chỉ PC: 0x321dec | Địa chỉ FDE: 0x117a08 | Kích thước: 216 bytes
//   0x321dec: D53BD058  mrs      x24, tpidr_el0
//   0x321df0: F9401709  ldr      x9, [x24, #0x28]
//   0x321df4: AA0403F6  mov      x22, x4
//   0x321df8: AA0303F5  mov      x21, x3
static inline uint64_t fde_func_1751_0x321dec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x321decULL ^ (static_cast<uint64_t>(0xd53bd058ULL) << 13);
    acc = (acc + a1 + 0xf9401709ULL) ^ 0x117a08ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1752 | PC: 0x321ec4 | FDE: 0x117b00 | Size: 204 bytes
// Khung tháo gỡ #1752 | Địa chỉ PC: 0x321ec4 | Địa chỉ FDE: 0x117b00 | Kích thước: 204 bytes
//   0x321ec4: 52800028  mov      w8, #1
//   0x321ec8: 910083E0  add      x0, sp, #0x20
//   0x321ecc: 910103E1  add      x1, sp, #0x40
//   0x321ed0: 290123FF  stp      wzr, w8, [sp, #8]
static inline uint64_t fde_func_1752_0x321ec4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x321ec4ULL ^ (static_cast<uint64_t>(0x52800028ULL) << 13);
    acc = (acc + a1 + 0x910083e0ULL) ^ 0x117b00ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1753 | PC: 0x321f90 | FDE: 0x117bf0 | Size: 92 bytes
// Khung tháo gỡ #1753 | Địa chỉ PC: 0x321f90 | Địa chỉ FDE: 0x117bf0 | Kích thước: 92 bytes
//   0x321f90: AA1303E0  mov      x0, x19
//   0x321f94: 14007A4F  b        #0x3408d0
//   0x321f98: AA1303E0  mov      x0, x19
//   0x321f9c: 14007A3D  b        #0x340890
static inline uint64_t fde_func_1753_0x321f90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x321f90ULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0x14007a4fULL) ^ 0x117bf0ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1754 | PC: 0x321fec | FDE: 0x117ce0 | Size: 132 bytes
// Khung tháo gỡ #1754 | Địa chỉ PC: 0x321fec | Địa chỉ FDE: 0x117ce0 | Kích thước: 132 bytes
//   0x321fec: AA1503E0  mov      x0, x21
//   0x321ff0: 14007A04  b        #0x340800
//   0x321ff4: AA1503E0  mov      x0, x21
//   0x321ff8: AA1803E1  mov      x1, x24
static inline uint64_t fde_func_1754_0x321fec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x321fecULL ^ (static_cast<uint64_t>(0xaa1503e0ULL) << 13);
    acc = (acc + a1 + 0x14007a04ULL) ^ 0x117ce0ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1755 | PC: 0x322070 | FDE: 0x117dd8 | Size: 192 bytes
// Khung tháo gỡ #1755 | Địa chỉ PC: 0x322070 | Địa chỉ FDE: 0x117dd8 | Kích thước: 192 bytes
//   0x322070: AA1403E0  mov      x0, x20
//   0x322074: 1400787B  b        #0x340260
//   0x322078: AA1403E0  mov      x0, x20
//   0x32207c: 17F8DEC1  b        #0x159b80
static inline uint64_t fde_func_1755_0x322070(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x322070ULL ^ (static_cast<uint64_t>(0xaa1403e0ULL) << 13);
    acc = (acc + a1 + 0x1400787bULL) ^ 0x117dd8ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1756 | PC: 0x322130 | FDE: 0x117ec8 | Size: 136 bytes
// Khung tháo gỡ #1756 | Địa chỉ PC: 0x322130 | Địa chỉ FDE: 0x117ec8 | Kích thước: 136 bytes
//   0x322130: 1E281800  fdiv     s0, s0, s8
//   0x322134: 910203E3  add      x3, sp, #0x80
//   0x322138: BD0083E0  str      s0, [sp, #0x80]
//   0x32213c: 17F97629  b        #0x17f9e0
static inline uint64_t fde_func_1756_0x322130(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x322130ULL ^ (static_cast<uint64_t>(0x1e281800ULL) << 13);
    acc = (acc + a1 + 0x910203e3ULL) ^ 0x117ec8ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1757 | PC: 0x3221b8 | FDE: 0x117fb8 | Size: 200 bytes
// Khung tháo gỡ #1757 | Địa chỉ PC: 0x3221b8 | Địa chỉ FDE: 0x117fb8 | Kích thước: 200 bytes
//   0x3221b8: D10243FF  sub      sp, sp, #0x90
//   0x3221bc: F90023FA  str      x26, [sp, #0x40]
//   0x3221c0: A90563F9  stp      x25, x24, [sp, #0x50]
//   0x3221c4: A9065BF7  stp      x23, x22, [sp, #0x60]
static inline uint64_t fde_func_1757_0x3221b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3221b8ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90023faULL) ^ 0x117fb8ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1758 | PC: 0x322280 | FDE: 0x1180a8 | Size: 256 bytes
// Khung tháo gỡ #1758 | Địa chỉ PC: 0x322280 | Địa chỉ FDE: 0x1180a8 | Kích thước: 256 bytes
//   0x322280: B9401C28  ldr      w8, [x1, #0x1c]
//   0x322284: B9401C09  ldr      w9, [x0, #0x1c]
//   0x322288: 33007909  bfxil    w9, w8, #0, #0x1f
//   0x32228c: B9001C09  str      w9, [x0, #0x1c]
static inline uint64_t fde_func_1758_0x322280(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x322280ULL ^ (static_cast<uint64_t>(0xb9401c28ULL) << 13);
    acc = (acc + a1 + 0xb9401c09ULL) ^ 0x1180a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1759 | PC: 0x322398 | FDE: 0x118198 | Size: 204 bytes
// Khung tháo gỡ #1759 | Địa chỉ PC: 0x322398 | Địa chỉ FDE: 0x118198 | Kích thước: 204 bytes
//   0x322398: B9400A88  ldr      w8, [x20, #8]
//   0x32239c: F9400289  ldr      x9, [x20]
//   0x3223a0: AA1403E0  mov      x0, x20
//   0x3223a4: AA1503E1  mov      x1, x21
static inline uint64_t fde_func_1759_0x322398(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x322398ULL ^ (static_cast<uint64_t>(0xb9400a88ULL) << 13);
    acc = (acc + a1 + 0xf9400289ULL) ^ 0x118198ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1760 | PC: 0x322464 | FDE: 0x118288 | Size: 168 bytes
// Khung tháo gỡ #1760 | Địa chỉ PC: 0x322464 | Địa chỉ FDE: 0x118288 | Kích thước: 168 bytes
//   0x322464: 9103A3E1  add      x1, sp, #0xe8
//   0x322468: AA1303E0  mov      x0, x19
//   0x32246c: B900EBFF  str      wzr, [sp, #0xe8]
//   0x322470: 17FCE571  b        #0x25ba34
static inline uint64_t fde_func_1760_0x322464(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x322464ULL ^ (static_cast<uint64_t>(0x9103a3e1ULL) << 13);
    acc = (acc + a1 + 0xaa1303e0ULL) ^ 0x118288ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1761 | PC: 0x32250c | FDE: 0x118378 | Size: 180 bytes
// Khung tháo gỡ #1761 | Địa chỉ PC: 0x32250c | Địa chỉ FDE: 0x118378 | Kích thước: 180 bytes
//   0x32250c: 2A1F03E8  mov      w8, wzr
//   0x322510: 2A1F03E9  mov      w9, wzr
//   0x322514: 2A1F03F9  mov      w25, wzr
//   0x322518: 2A1F03F3  mov      w19, wzr
static inline uint64_t fde_func_1761_0x32250c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32250cULL ^ (static_cast<uint64_t>(0x2a1f03e8ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e9ULL) ^ 0x118378ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1762 | PC: 0x3225c0 | FDE: 0x118468 | Size: 252 bytes
// Khung tháo gỡ #1762 | Địa chỉ PC: 0x3225c0 | Địa chỉ FDE: 0x118468 | Kích thước: 252 bytes
//   0x3225c0: AA0303E0  mov      x0, x3
//   0x3225c4: AA0303F3  mov      x19, x3
//   0x3225c8: AA0203F4  mov      x20, x2
//   0x3225cc: 17F962F2  b        #0x17b194
static inline uint64_t fde_func_1762_0x3225c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3225c0ULL ^ (static_cast<uint64_t>(0xaa0303e0ULL) << 13);
    acc = (acc + a1 + 0xaa0303f3ULL) ^ 0x118468ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1763 | PC: 0x3226bc | FDE: 0x118558 | Size: 192 bytes
// Khung tháo gỡ #1763 | Địa chỉ PC: 0x3226bc | Địa chỉ FDE: 0x118558 | Kích thước: 192 bytes
//   0x3226bc: D53BD056  mrs      x22, tpidr_el0
//   0x3226c0: AA0803F3  mov      x19, x8
//   0x3226c4: F94016C8  ldr      x8, [x22, #0x28]
//   0x3226c8: 7100045F  cmp      w2, #1
static inline uint64_t fde_func_1763_0x3226bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3226bcULL ^ (static_cast<uint64_t>(0xd53bd056ULL) << 13);
    acc = (acc + a1 + 0xaa0803f3ULL) ^ 0x118558ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1764 | PC: 0x32277c | FDE: 0x118648 | Size: 232 bytes
// Khung tháo gỡ #1764 | Địa chỉ PC: 0x32277c | Địa chỉ FDE: 0x118648 | Kích thước: 232 bytes
//   0x32277c: F9400288  ldr      x8, [x20]
//   0x322780: 910023E3  add      x3, sp, #8
//   0x322784: AA1403E0  mov      x0, x20
//   0x322788: AA1503E1  mov      x1, x21
static inline uint64_t fde_func_1764_0x32277c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32277cULL ^ (static_cast<uint64_t>(0xf9400288ULL) << 13);
    acc = (acc + a1 + 0x910023e3ULL) ^ 0x118648ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1765 | PC: 0x322864 | FDE: 0x118740 | Size: 164 bytes
// Khung tháo gỡ #1765 | Địa chỉ PC: 0x322864 | Địa chỉ FDE: 0x118740 | Kích thước: 164 bytes
//   0x322864: AA0003F5  mov      x21, x0
//   0x322868: F9000008  str      x8, [x0]
//   0x32286c: 3C808000  stur     q0, [x0, #8]
//   0x322870: 91006000  add      x0, x0, #0x18
static inline uint64_t fde_func_1765_0x322864(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x322864ULL ^ (static_cast<uint64_t>(0xaa0003f5ULL) << 13);
    acc = (acc + a1 + 0xf9000008ULL) ^ 0x118740ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1766 | PC: 0x322908 | FDE: 0x118830 | Size: 144 bytes
// Khung tháo gỡ #1766 | Địa chỉ PC: 0x322908 | Địa chỉ FDE: 0x118830 | Kích thước: 144 bytes
//   0x322908: D53BD05A  mrs      x26, tpidr_el0
//   0x32290c: F9401748  ldr      x8, [x26, #0x28]
//   0x322910: AA0003F3  mov      x19, x0
//   0x322914: D65F03C0  ret      
static inline uint64_t fde_func_1766_0x322908(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x322908ULL ^ (static_cast<uint64_t>(0xd53bd05aULL) << 13);
    acc = (acc + a1 + 0xf9401748ULL) ^ 0x118830ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1767 | PC: 0x322998 | FDE: 0x118928 | Size: 200 bytes
// Khung tháo gỡ #1767 | Địa chỉ PC: 0x322998 | Địa chỉ FDE: 0x118928 | Kích thước: 200 bytes
//   0x322998: 910003E0  mov      x0, sp
//   0x32299c: 910083E1  add      x1, sp, #0x20
//   0x3229a0: F90013FA  str      x26, [sp, #0x20]
//   0x3229a4: B9002BE8  str      w8, [sp, #0x28]
static inline uint64_t fde_func_1767_0x322998(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x322998ULL ^ (static_cast<uint64_t>(0x910003e0ULL) << 13);
    acc = (acc + a1 + 0x910083e1ULL) ^ 0x118928ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1768 | PC: 0x322a60 | FDE: 0x118a20 | Size: 144 bytes
// Khung tháo gỡ #1768 | Địa chỉ PC: 0x322a60 | Địa chỉ FDE: 0x118a20 | Kích thước: 144 bytes
//   0x322a60: AA0103E0  mov      x0, x1
//   0x322a64: AA0103F4  mov      x20, x1
//   0x322a68: D65F03C0  ret      
//   0x322a6c: 910083E0  add      x0, sp, #0x20
static inline uint64_t fde_func_1768_0x322a60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x322a60ULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0xaa0103f4ULL) ^ 0x118a20ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1769 | PC: 0x322af0 | FDE: 0x118b10 | Size: 224 bytes
// Khung tháo gỡ #1769 | Địa chỉ PC: 0x322af0 | Địa chỉ FDE: 0x118b10 | Kích thước: 224 bytes
//   0x322af0: D53BD055  mrs      x21, tpidr_el0
//   0x322af4: F94016A8  ldr      x8, [x21, #0x28]
//   0x322af8: AA0003F3  mov      x19, x0
//   0x322afc: F9002FE8  str      x8, [sp, #0x58]
static inline uint64_t fde_func_1769_0x322af0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x322af0ULL ^ (static_cast<uint64_t>(0xd53bd055ULL) << 13);
    acc = (acc + a1 + 0xf94016a8ULL) ^ 0x118b10ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #1770 | PC: 0x322bd0 | FDE: 0x118c00 | Size: 196 bytes
// Khung tháo gỡ #1770 | Địa chỉ PC: 0x322bd0 | Địa chỉ FDE: 0x118c00 | Kích thước: 196 bytes
//   0x322bd0: F9402500  ldr      x0, [x8, #0x48]
//   0x322bd4: 17FBEDD1  b        #0x21e318
//   0x322bd8: F94017E8  ldr      x8, [sp, #0x28]
//   0x322bdc: 528000C9  mov      w9, #6
static inline uint64_t fde_func_1770_0x322bd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x322bd0ULL ^ (static_cast<uint64_t>(0xf9402500ULL) << 13);
    acc = (acc + a1 + 0x17fbedd1ULL) ^ 0x118c00ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1771 | PC: 0x322c94 | FDE: 0x118cf0 | Size: 172 bytes
// Khung tháo gỡ #1771 | Địa chỉ PC: 0x322c94 | Địa chỉ FDE: 0x118cf0 | Kích thước: 172 bytes
//   0x322c94: B9401808  ldr      w8, [x0, #0x18]
//   0x322c98: EB08029F  cmp      x20, x8
//   0x322c9c: D65F03C0  ret      
//   0x322ca0: 6B0802FF  cmp      w23, w8
static inline uint64_t fde_func_1771_0x322c94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x322c94ULL ^ (static_cast<uint64_t>(0xb9401808ULL) << 13);
    acc = (acc + a1 + 0xeb08029fULL) ^ 0x118cf0ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1772 | PC: 0x322d40 | FDE: 0x118de0 | Size: 160 bytes
// Khung tháo gỡ #1772 | Địa chỉ PC: 0x322d40 | Địa chỉ FDE: 0x118de0 | Kích thước: 160 bytes
//   0x322d40: 910263E0  add      x0, sp, #0x98
//   0x322d44: 17F8DB8F  b        #0x159b80
//   0x322d48: 9103E3E0  add      x0, sp, #0xf8
//   0x322d4c: 910263E1  add      x1, sp, #0x98
static inline uint64_t fde_func_1772_0x322d40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x322d40ULL ^ (static_cast<uint64_t>(0x910263e0ULL) << 13);
    acc = (acc + a1 + 0x17f8db8fULL) ^ 0x118de0ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1773 | PC: 0x322de0 | FDE: 0x118ed0 | Size: 180 bytes
// Khung tháo gỡ #1773 | Địa chỉ PC: 0x322de0 | Địa chỉ FDE: 0x118ed0 | Kích thước: 180 bytes
//   0x322de0: 90FFEA81  adrp     x1, #0x72000
//   0x322de4: 91255021  add      x1, x1, #0x954
//   0x322de8: D65F03C0  ret      
//   0x322dec: 9100E3E0  add      x0, sp, #0x38
static inline uint64_t fde_func_1773_0x322de0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x322de0ULL ^ (static_cast<uint64_t>(0x90ffea81ULL) << 13);
    acc = (acc + a1 + 0x91255021ULL) ^ 0x118ed0ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1774 | PC: 0x322e94 | FDE: 0x118fc0 | Size: 160 bytes
// Khung tháo gỡ #1774 | Địa chỉ PC: 0x322e94 | Địa chỉ FDE: 0x118fc0 | Kích thước: 160 bytes
//   0x322e94: D53BD056  mrs      x22, tpidr_el0
//   0x322e98: F94016C8  ldr      x8, [x22, #0x28]
//   0x322e9c: AA0003F5  mov      x21, x0
//   0x322ea0: 910003E0  mov      x0, sp
static inline uint64_t fde_func_1774_0x322e94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x322e94ULL ^ (static_cast<uint64_t>(0xd53bd056ULL) << 13);
    acc = (acc + a1 + 0xf94016c8ULL) ^ 0x118fc0ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1775 | PC: 0x322f34 | FDE: 0x1190b0 | Size: 156 bytes
// Khung tháo gỡ #1775 | Địa chỉ PC: 0x322f34 | Địa chỉ FDE: 0x1190b0 | Kích thước: 156 bytes
//   0x322f34: D53BD058  mrs      x24, tpidr_el0
//   0x322f38: AA0803F3  mov      x19, x8
//   0x322f3c: F9401708  ldr      x8, [x24, #0x28]
//   0x322f40: AA0003F5  mov      x21, x0
static inline uint64_t fde_func_1775_0x322f34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x322f34ULL ^ (static_cast<uint64_t>(0xd53bd058ULL) << 13);
    acc = (acc + a1 + 0xaa0803f3ULL) ^ 0x1190b0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1776 | PC: 0x322fd0 | FDE: 0x1191a8 | Size: 140 bytes
// Khung tháo gỡ #1776 | Địa chỉ PC: 0x322fd0 | Địa chỉ FDE: 0x1191a8 | Kích thước: 140 bytes
//   0x322fd0: 2A1F03E2  mov      w2, wzr
//   0x322fd4: 17FE3386  b        #0x2afdec
//   0x322fd8: 7100045F  cmp      w2, #1
//   0x322fdc: F90007E8  str      x8, [sp, #8]
static inline uint64_t fde_func_1776_0x322fd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x322fd0ULL ^ (static_cast<uint64_t>(0x2a1f03e2ULL) << 13);
    acc = (acc + a1 + 0x17fe3386ULL) ^ 0x1191a8ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1777 | PC: 0x32305c | FDE: 0x119298 | Size: 132 bytes
// Khung tháo gỡ #1777 | Địa chỉ PC: 0x32305c | Địa chỉ FDE: 0x119298 | Kích thước: 132 bytes
//   0x32305c: AA1603E0  mov      x0, x22
//   0x323060: 140074FC  b        #0x340450
//   0x323064: F9400268  ldr      x8, [x19]
//   0x323068: F87A7908  ldr      x8, [x8, x26, lsl #3]
static inline uint64_t fde_func_1777_0x32305c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32305cULL ^ (static_cast<uint64_t>(0xaa1603e0ULL) << 13);
    acc = (acc + a1 + 0x140074fcULL) ^ 0x119298ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1778 | PC: 0x3230e0 | FDE: 0x119388 | Size: 112 bytes
// Khung tháo gỡ #1778 | Địa chỉ PC: 0x3230e0 | Địa chỉ FDE: 0x119388 | Kích thước: 112 bytes
//   0x3230e0: AA1403E1  mov      x1, x20
//   0x3230e4: AA1603E2  mov      x2, x22
//   0x3230e8: D65F03C0  ret      
//   0x3230ec: AA1503E0  mov      x0, x21
static inline uint64_t fde_func_1778_0x3230e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3230e0ULL ^ (static_cast<uint64_t>(0xaa1403e1ULL) << 13);
    acc = (acc + a1 + 0xaa1603e2ULL) ^ 0x119388ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1779 | PC: 0x323150 | FDE: 0x119478 | Size: 160 bytes
// Khung tháo gỡ #1779 | Địa chỉ PC: 0x323150 | Địa chỉ FDE: 0x119478 | Kích thước: 160 bytes
//   0x323150: AA1403E0  mov      x0, x20
//   0x323154: 17F90697  b        #0x164bb0
//   0x323158: AA0003F4  mov      x20, x0
//   0x32315c: AA1503E0  mov      x0, x21
static inline uint64_t fde_func_1779_0x323150(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x323150ULL ^ (static_cast<uint64_t>(0xaa1403e0ULL) << 13);
    acc = (acc + a1 + 0x17f90697ULL) ^ 0x119478ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1780 | PC: 0x3231f0 | FDE: 0x119568 | Size: 108 bytes
// Khung tháo gỡ #1780 | Địa chỉ PC: 0x3231f0 | Địa chỉ FDE: 0x119568 | Kích thước: 108 bytes
//   0x3231f0: F9402500  ldr      x0, [x8, #0x48]
//   0x3231f4: 17FBEACC  b        #0x21dd24
//   0x3231f8: D0FFEA61  adrp     x1, #0x71000
//   0x3231fc: 9134F021  add      x1, x1, #0xd3c
static inline uint64_t fde_func_1780_0x3231f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3231f0ULL ^ (static_cast<uint64_t>(0xf9402500ULL) << 13);
    acc = (acc + a1 + 0x17fbeaccULL) ^ 0x119568ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1781 | PC: 0x32325c | FDE: 0x119658 | Size: 228 bytes
// Khung tháo gỡ #1781 | Địa chỉ PC: 0x32325c | Địa chỉ FDE: 0x119658 | Kích thước: 228 bytes
//   0x32325c: F9410AC9  ldr      x9, [x22, #0x210]
//   0x323260: 9E780008  fcvtzs   x8, d0
//   0x323264: EB08013F  cmp      x9, x8
//   0x323268: D65F03C0  ret      
static inline uint64_t fde_func_1781_0x32325c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32325cULL ^ (static_cast<uint64_t>(0xf9410ac9ULL) << 13);
    acc = (acc + a1 + 0x9e780008ULL) ^ 0x119658ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1782 | PC: 0x323340 | FDE: 0x119750 | Size: 208 bytes
// Khung tháo gỡ #1782 | Địa chỉ PC: 0x323340 | Địa chỉ FDE: 0x119750 | Kích thước: 208 bytes
//   0x323340: F94002AA  ldr      x10, [x21]
//   0x323344: F8297948  str      x8, [x10, x9, lsl #3]
//   0x323348: D65F03C0  ret      
//   0x32334c: 5AC002E8  rbit     w8, w23
static inline uint64_t fde_func_1782_0x323340(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x323340ULL ^ (static_cast<uint64_t>(0xf94002aaULL) << 13);
    acc = (acc + a1 + 0xf8297948ULL) ^ 0x119750ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1783 | PC: 0x323410 | FDE: 0x119840 | Size: 124 bytes
// Khung tháo gỡ #1783 | Địa chỉ PC: 0x323410 | Địa chỉ FDE: 0x119840 | Kích thước: 124 bytes
//   0x323410: D37FF928  lsl      x8, x9, #1
//   0x323414: EB01011F  cmp      x8, x1
//   0x323418: 9A883028  csel     x8, x1, x8, lo
//   0x32341c: D65F03C0  ret      
static inline uint64_t fde_func_1783_0x323410(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x323410ULL ^ (static_cast<uint64_t>(0xd37ff928ULL) << 13);
    acc = (acc + a1 + 0xeb01011fULL) ^ 0x119840ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1784 | PC: 0x32348c | FDE: 0x119930 | Size: 180 bytes
// Khung tháo gỡ #1784 | Địa chỉ PC: 0x32348c | Địa chỉ FDE: 0x119930 | Kích thước: 180 bytes
//   0x32348c: 910023E2  add      x2, sp, #8
//   0x323490: AA1403E0  mov      x0, x20
//   0x323494: D65F03C0  ret      
//   0x323498: F9400AC8  ldr      x8, [x22, #0x10]
static inline uint64_t fde_func_1784_0x32348c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32348cULL ^ (static_cast<uint64_t>(0x910023e2ULL) << 13);
    acc = (acc + a1 + 0xaa1403e0ULL) ^ 0x119930ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1785 | PC: 0x323540 | FDE: 0x119a20 | Size: 220 bytes
// Khung tháo gỡ #1785 | Địa chỉ PC: 0x323540 | Địa chỉ FDE: 0x119a20 | Kích thước: 220 bytes
//   0x323540: A900FFFF  stp      xzr, xzr, [sp, #8]
//   0x323544: F90003FF  str      xzr, [sp]
//   0x323548: D65F03C0  ret      
//   0x32354c: 910043E8  add      x8, sp, #0x10
static inline uint64_t fde_func_1785_0x323540(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x323540ULL ^ (static_cast<uint64_t>(0xa900ffffULL) << 13);
    acc = (acc + a1 + 0xf90003ffULL) ^ 0x119a20ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #1786 | PC: 0x32361c | FDE: 0x119b18 | Size: 136 bytes
// Khung tháo gỡ #1786 | Địa chỉ PC: 0x32361c | Địa chỉ FDE: 0x119b18 | Kích thước: 136 bytes
//   0x32361c: AA0103F5  mov      x21, x1
//   0x323620: AA0003F6  mov      x22, x0
//   0x323624: D65F03C0  ret      
//   0x323628: AA0103F5  mov      x21, x1
static inline uint64_t fde_func_1786_0x32361c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32361cULL ^ (static_cast<uint64_t>(0xaa0103f5ULL) << 13);
    acc = (acc + a1 + 0xaa0003f6ULL) ^ 0x119b18ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1787 | PC: 0x3236a4 | FDE: 0x119c08 | Size: 244 bytes
// Khung tháo gỡ #1787 | Địa chỉ PC: 0x3236a4 | Địa chỉ FDE: 0x119c08 | Kích thước: 244 bytes
//   0x3236a4: F9400408  ldr      x8, [x0, #8]
//   0x3236a8: D37CED09  lsl      x9, x8, #4
//   0x3236ac: CB080128  sub      x8, x9, x8
//   0x3236b0: 91003900  add      x0, x8, #0xe
static inline uint64_t fde_func_1787_0x3236a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3236a4ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xd37ced09ULL) ^ 0x119c08ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #1788 | PC: 0x323798 | FDE: 0x119d00 | Size: 108 bytes
// Khung tháo gỡ #1788 | Địa chỉ PC: 0x323798 | Địa chỉ FDE: 0x119d00 | Kích thước: 108 bytes
//   0x323798: AA1303E0  mov      x0, x19
//   0x32379c: AA1503E2  mov      x2, x21
//   0x3237a0: D65F03C0  ret      
//   0x3237a4: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1788_0x323798(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x323798ULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0xaa1503e2ULL) ^ 0x119d00ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1789 | PC: 0x323804 | FDE: 0x119df0 | Size: 112 bytes
// Khung tháo gỡ #1789 | Địa chỉ PC: 0x323804 | Địa chỉ FDE: 0x119df0 | Kích thước: 112 bytes
//   0x323804: AA0003F3  mov      x19, x0
//   0x323808: F9000008  str      x8, [x0]
//   0x32380c: D65F03C0  ret      
//   0x323810: D53BD057  mrs      x23, tpidr_el0
static inline uint64_t fde_func_1789_0x323804(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x323804ULL ^ (static_cast<uint64_t>(0xaa0003f3ULL) << 13);
    acc = (acc + a1 + 0xf9000008ULL) ^ 0x119df0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1790 | PC: 0x323874 | FDE: 0x119ee0 | Size: 144 bytes
// Khung tháo gỡ #1790 | Địa chỉ PC: 0x323874 | Địa chỉ FDE: 0x119ee0 | Kích thước: 144 bytes
//   0x323874: 910083E8  add      x8, sp, #0x20
//   0x323878: D61F0120  br       x9
//   0x32387c: AA0003F4  mov      x20, x0
//   0x323880: F90007E8  str      x8, [sp, #8]
static inline uint64_t fde_func_1790_0x323874(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x323874ULL ^ (static_cast<uint64_t>(0x910083e8ULL) << 13);
    acc = (acc + a1 + 0xd61f0120ULL) ^ 0x119ee0ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1791 | PC: 0x323904 | FDE: 0x119fd0 | Size: 152 bytes
// Khung tháo gỡ #1791 | Địa chỉ PC: 0x323904 | Địa chỉ FDE: 0x119fd0 | Kích thước: 152 bytes
//   0x323904: 910683E0  add      x0, sp, #0x1a0
//   0x323908: 17F8D8B3  b        #0x159bd4
//   0x32390c: A95153F5  ldp      x21, x20, [sp, #0x110]
//   0x323910: A9505BF7  ldp      x23, x22, [sp, #0x100]
static inline uint64_t fde_func_1791_0x323904(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x323904ULL ^ (static_cast<uint64_t>(0x910683e0ULL) << 13);
    acc = (acc + a1 + 0x17f8d8b3ULL) ^ 0x119fd0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1792 | PC: 0x32399c | FDE: 0x11a0c0 | Size: 176 bytes
// Khung tháo gỡ #1792 | Địa chỉ PC: 0x32399c | Địa chỉ FDE: 0x11a0c0 | Kích thước: 176 bytes
//   0x32399c: A9422909  ldp      x9, x10, [x8, #0x20]
//   0x3239a0: FD400D00  ldr      d0, [x8, #0x18]
//   0x3239a4: F9400129  ldr      x9, [x9]
//   0x3239a8: F85F814A  ldur     x10, [x10, #-8]
static inline uint64_t fde_func_1792_0x32399c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32399cULL ^ (static_cast<uint64_t>(0xa9422909ULL) << 13);
    acc = (acc + a1 + 0xfd400d00ULL) ^ 0x11a0c0ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1793 | PC: 0x323a4c | FDE: 0x11a1b0 | Size: 196 bytes
// Khung tháo gỡ #1793 | Địa chỉ PC: 0x323a4c | Địa chỉ FDE: 0x11a1b0 | Kích thước: 196 bytes
//   0x323a4c: F9405122  ldr      x2, [x9, #0xa0]
//   0x323a50: 1E22C000  fcvt     d0, s0
//   0x323a54: D61F0040  br       x2
//   0x323a58: F8008509  str      x9, [x8], #8
static inline uint64_t fde_func_1793_0x323a4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x323a4cULL ^ (static_cast<uint64_t>(0xf9405122ULL) << 13);
    acc = (acc + a1 + 0x1e22c000ULL) ^ 0x11a1b0ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1794 | PC: 0x323b10 | FDE: 0x11a2a0 | Size: 156 bytes
// Khung tháo gỡ #1794 | Địa chỉ PC: 0x323b10 | Địa chỉ FDE: 0x11a2a0 | Kích thước: 156 bytes
//   0x323b10: 910223E0  add      x0, sp, #0x88
//   0x323b14: 17F8E700  b        #0x15d714
//   0x323b18: A9000000  stp      x0, x0, [x0]
//   0x323b1c: D00001E8  adrp     x8, #0x361000
static inline uint64_t fde_func_1794_0x323b10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x323b10ULL ^ (static_cast<uint64_t>(0x910223e0ULL) << 13);
    acc = (acc + a1 + 0x17f8e700ULL) ^ 0x11a2a0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1795 | PC: 0x323bac | FDE: 0x11a390 | Size: 236 bytes
// Khung tháo gỡ #1795 | Địa chỉ PC: 0x323bac | Địa chỉ FDE: 0x11a390 | Kích thước: 236 bytes
//   0x323bac: 7100013F  cmp      w9, #0
//   0x323bb0: 5A895529  cneg     w9, w9, mi
//   0x323bb4: D37EF529  lsl      x9, x9, #2
//   0x323bb8: 91001D29  add      x9, x9, #7
static inline uint64_t fde_func_1795_0x323bac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x323bacULL ^ (static_cast<uint64_t>(0x7100013fULL) << 13);
    acc = (acc + a1 + 0x5a895529ULL) ^ 0x11a390ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #1796 | PC: 0x323c98 | FDE: 0x11a480 | Size: 184 bytes
// Khung tháo gỡ #1796 | Địa chỉ PC: 0x323c98 | Địa chỉ FDE: 0x11a480 | Kích thước: 184 bytes
//   0x323c98: AA1F03E2  mov      x2, xzr
//   0x323c9c: 17F8E60B  b        #0x15d4c8
//   0x323ca0: AA1F03E2  mov      x2, xzr
//   0x323ca4: F9404908  ldr      x8, [x8, #0x90]
static inline uint64_t fde_func_1796_0x323c98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x323c98ULL ^ (static_cast<uint64_t>(0xaa1f03e2ULL) << 13);
    acc = (acc + a1 + 0x17f8e60bULL) ^ 0x11a480ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1797 | PC: 0x323d50 | FDE: 0x11a570 | Size: 144 bytes
// Khung tháo gỡ #1797 | Địa chỉ PC: 0x323d50 | Địa chỉ FDE: 0x11a570 | Kích thước: 144 bytes
//   0x323d50: 9100E3E0  add      x0, sp, #0x38
//   0x323d54: 17F92FF2  b        #0x16fd1c
//   0x323d58: 910103E0  add      x0, sp, #0x40
//   0x323d5c: 52800021  mov      w1, #1
static inline uint64_t fde_func_1797_0x323d50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x323d50ULL ^ (static_cast<uint64_t>(0x9100e3e0ULL) << 13);
    acc = (acc + a1 + 0x17f92ff2ULL) ^ 0x11a570ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1798 | PC: 0x323de0 | FDE: 0x11a660 | Size: 164 bytes
// Khung tháo gỡ #1798 | Địa chỉ PC: 0x323de0 | Địa chỉ FDE: 0x11a660 | Kích thước: 164 bytes
//   0x323de0: F9401108  ldr      x8, [x8, #0x20]
//   0x323de4: AA1F03E3  mov      x3, xzr
//   0x323de8: D61F0100  br       x8
//   0x323dec: F94002E8  ldr      x8, [x23]
static inline uint64_t fde_func_1798_0x323de0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x323de0ULL ^ (static_cast<uint64_t>(0xf9401108ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e3ULL) ^ 0x11a660ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1799 | PC: 0x323e84 | FDE: 0x11a750 | Size: 200 bytes
// Khung tháo gỡ #1799 | Địa chỉ PC: 0x323e84 | Địa chỉ FDE: 0x11a750 | Kích thước: 200 bytes
//   0x323e84: F94007E0  ldr      x0, [sp, #8]
//   0x323e88: 910003E1  mov      x1, sp
//   0x323e8c: 1E22C000  fcvt     d0, s0
//   0x323e90: FD0003E0  str      d0, [sp]
static inline uint64_t fde_func_1799_0x323e84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x323e84ULL ^ (static_cast<uint64_t>(0xf94007e0ULL) << 13);
    acc = (acc + a1 + 0x910003e1ULL) ^ 0x11a750ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1800 | PC: 0x323f4c | FDE: 0x11a840 | Size: 256 bytes
// Khung tháo gỡ #1800 | Địa chỉ PC: 0x323f4c | Địa chỉ FDE: 0x11a840 | Kích thước: 256 bytes
//   0x323f4c: F9000BE8  str      x8, [sp, #0x10]
//   0x323f50: 3D8003E0  str      q0, [sp]
//   0x323f54: F9400A68  ldr      x8, [x19, #0x10]
//   0x323f58: 3DC00260  ldr      q0, [x19]
static inline uint64_t fde_func_1800_0x323f4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x323f4cULL ^ (static_cast<uint64_t>(0xf9000be8ULL) << 13);
    acc = (acc + a1 + 0x3d8003e0ULL) ^ 0x11a840ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1801 | PC: 0x324070 | FDE: 0x11a930 | Size: 168 bytes
// Khung tháo gỡ #1801 | Địa chỉ PC: 0x324070 | Địa chỉ FDE: 0x11a930 | Kích thước: 168 bytes
//   0x324070: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x324074: 97F8D6CC  bl       #0x159ba4
//   0x324078: 52800028  mov      w8, #1
//   0x32407c: F84107FE  ldr      x30, [sp], #0x10
static inline uint64_t fde_func_1801_0x324070(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x324070ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x97f8d6ccULL) ^ 0x11a930ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1802 | PC: 0x324118 | FDE: 0x11aa28 | Size: 192 bytes
// Khung tháo gỡ #1802 | Địa chỉ PC: 0x324118 | Địa chỉ FDE: 0x11aa28 | Kích thước: 192 bytes
//   0x324118: AA1B03E0  mov      x0, x27
//   0x32411c: 17F902A5  b        #0x164bb0
//   0x324120: 2A1F03E1  mov      w1, wzr
//   0x324124: 17F9ABD4  b        #0x18f074
static inline uint64_t fde_func_1802_0x324118(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x324118ULL ^ (static_cast<uint64_t>(0xaa1b03e0ULL) << 13);
    acc = (acc + a1 + 0x17f902a5ULL) ^ 0x11aa28ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1803 | PC: 0x3241d8 | FDE: 0x11ab18 | Size: 140 bytes
// Khung tháo gỡ #1803 | Địa chỉ PC: 0x3241d8 | Địa chỉ FDE: 0x11ab18 | Kích thước: 140 bytes
//   0x3241d8: AA0203F3  mov      x19, x2
//   0x3241dc: 52800402  mov      w2, #0x20
//   0x3241e0: AA0103F5  mov      x21, x1
//   0x3241e4: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1803_0x3241d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3241d8ULL ^ (static_cast<uint64_t>(0xaa0203f3ULL) << 13);
    acc = (acc + a1 + 0x52800402ULL) ^ 0x11ab18ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1804 | PC: 0x324264 | FDE: 0x11ac10 | Size: 128 bytes
// Khung tháo gỡ #1804 | Địa chỉ PC: 0x324264 | Địa chỉ FDE: 0x11ac10 | Kích thước: 128 bytes
//   0x324264: AA1703E0  mov      x0, x23
//   0x324268: 1400723E  b        #0x340b60
//   0x32426c: AA1603E0  mov      x0, x22
//   0x324270: 140070A8  b        #0x340510
static inline uint64_t fde_func_1804_0x324264(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x324264ULL ^ (static_cast<uint64_t>(0xaa1703e0ULL) << 13);
    acc = (acc + a1 + 0x1400723eULL) ^ 0x11ac10ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1805 | PC: 0x3242e4 | FDE: 0x11ad00 | Size: 104 bytes
// Khung tháo gỡ #1805 | Địa chỉ PC: 0x3242e4 | Địa chỉ FDE: 0x11ad00 | Kích thước: 104 bytes
//   0x3242e4: 910003E8  mov      x8, sp
//   0x3242e8: 1400705A  b        #0x340450
//   0x3242ec: AA1603E1  mov      x1, x22
//   0x3242f0: F9400117  ldr      x23, [x8]
static inline uint64_t fde_func_1805_0x3242e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3242e4ULL ^ (static_cast<uint64_t>(0x910003e8ULL) << 13);
    acc = (acc + a1 + 0x1400705aULL) ^ 0x11ad00ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1806 | PC: 0x32434c | FDE: 0x11adf0 | Size: 212 bytes
// Khung tháo gỡ #1806 | Địa chỉ PC: 0x32434c | Địa chỉ FDE: 0x11adf0 | Kích thước: 212 bytes
//   0x32434c: 910003E0  mov      x0, sp
//   0x324350: 17F8ED8B  b        #0x15f97c
//   0x324354: 910003E0  mov      x0, sp
//   0x324358: 910083E1  add      x1, sp, #0x20
static inline uint64_t fde_func_1806_0x32434c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32434cULL ^ (static_cast<uint64_t>(0x910003e0ULL) << 13);
    acc = (acc + a1 + 0x17f8ed8bULL) ^ 0x11adf0ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1807 | PC: 0x324420 | FDE: 0x11aee8 | Size: 120 bytes
// Khung tháo gỡ #1807 | Địa chỉ PC: 0x324420 | Địa chỉ FDE: 0x11aee8 | Kích thước: 120 bytes
//   0x324420: A9007C1F  stp      xzr, xzr, [x0]
//   0x324424: F900081F  str      xzr, [x0, #0x10]
//   0x324428: D65F03C0  ret      
//   0x32442c: 910083E0  add      x0, sp, #0x20
static inline uint64_t fde_func_1807_0x324420(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x324420ULL ^ (static_cast<uint64_t>(0xa9007c1fULL) << 13);
    acc = (acc + a1 + 0xf900081fULL) ^ 0x11aee8ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1808 | PC: 0x324498 | FDE: 0x11afd8 | Size: 168 bytes
// Khung tháo gỡ #1808 | Địa chỉ PC: 0x324498 | Địa chỉ FDE: 0x11afd8 | Kích thước: 168 bytes
//   0x324498: AA1403E0  mov      x0, x20
//   0x32449c: 17F8D5CE  b        #0x159bd4
//   0x3244a0: F9001FE8  str      x8, [sp, #0x38]
//   0x3244a4: 14007087  b        #0x3406c0
static inline uint64_t fde_func_1808_0x324498(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x324498ULL ^ (static_cast<uint64_t>(0xaa1403e0ULL) << 13);
    acc = (acc + a1 + 0x17f8d5ceULL) ^ 0x11afd8ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1809 | PC: 0x324540 | FDE: 0x11b0c8 | Size: 252 bytes
// Khung tháo gỡ #1809 | Địa chỉ PC: 0x324540 | Địa chỉ FDE: 0x11b0c8 | Kích thước: 252 bytes
//   0x324540: 4EA31C68  mov      v8.16b, v3.16b
//   0x324544: 4EA21C49  mov      v9.16b, v2.16b
//   0x324548: 4EA11C2A  mov      v10.16b, v1.16b
//   0x32454c: 4EA01C0B  mov      v11.16b, v0.16b
static inline uint64_t fde_func_1809_0x324540(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x324540ULL ^ (static_cast<uint64_t>(0x4ea31c68ULL) << 13);
    acc = (acc + a1 + 0x4ea21c49ULL) ^ 0x11b0c8ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1810 | PC: 0x32463c | FDE: 0x11b1c0 | Size: 212 bytes
// Khung tháo gỡ #1810 | Địa chỉ PC: 0x32463c | Địa chỉ FDE: 0x11b1c0 | Kích thước: 212 bytes
//   0x32463c: B9000268  str      w8, [x19]
//   0x324640: B90002A9  str      w9, [x21]
//   0x324644: B9400268  ldr      w8, [x19]
//   0x324648: B9400289  ldr      w9, [x20]
static inline uint64_t fde_func_1810_0x32463c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32463cULL ^ (static_cast<uint64_t>(0xb9000268ULL) << 13);
    acc = (acc + a1 + 0xb90002a9ULL) ^ 0x11b1c0ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1811 | PC: 0x324710 | FDE: 0x11b2b0 | Size: 184 bytes
// Khung tháo gỡ #1811 | Địa chỉ PC: 0x324710 | Địa chỉ FDE: 0x11b2b0 | Kích thước: 184 bytes
//   0x324710: B90002A8  str      w8, [x21]
//   0x324714: B90002C9  str      w9, [x22]
//   0x324718: B94002A8  ldr      w8, [x21]
//   0x32471c: B9400269  ldr      w9, [x19]
static inline uint64_t fde_func_1811_0x324710(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x324710ULL ^ (static_cast<uint64_t>(0xb90002a8ULL) << 13);
    acc = (acc + a1 + 0xb90002c9ULL) ^ 0x11b2b0ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1812 | PC: 0x3247c8 | FDE: 0x11b3a0 | Size: 152 bytes
// Khung tháo gỡ #1812 | Địa chỉ PC: 0x3247c8 | Địa chỉ FDE: 0x11b3a0 | Kích thước: 152 bytes
//   0x3247c8: 5AC00009  rbit     w9, w0
//   0x3247cc: 5AC01129  clz      w9, w9
//   0x3247d0: D37CED29  lsl      x9, x9, #4
//   0x3247d4: B8696909  ldr      w9, [x8, x9]
static inline uint64_t fde_func_1812_0x3247c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3247c8ULL ^ (static_cast<uint64_t>(0x5ac00009ULL) << 13);
    acc = (acc + a1 + 0x5ac01129ULL) ^ 0x11b3a0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1813 | PC: 0x324860 | FDE: 0x11b490 | Size: 196 bytes
// Khung tháo gỡ #1813 | Địa chỉ PC: 0x324860 | Địa chỉ FDE: 0x11b490 | Kích thước: 196 bytes
//   0x324860: B9400029  ldr      w9, [x1]
//   0x324864: D1006108  sub      x8, x8, #0x18
//   0x324868: B9000009  str      w9, [x0]
//   0x32486c: F9400429  ldr      x9, [x1, #8]
static inline uint64_t fde_func_1813_0x324860(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x324860ULL ^ (static_cast<uint64_t>(0xb9400029ULL) << 13);
    acc = (acc + a1 + 0xd1006108ULL) ^ 0x11b490ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1814 | PC: 0x324924 | FDE: 0x11b580 | Size: 200 bytes
// Khung tháo gỡ #1814 | Địa chỉ PC: 0x324924 | Địa chỉ FDE: 0x11b580 | Kích thước: 200 bytes
//   0x324924: F940028A  ldr      x10, [x20]
//   0x324928: 8B150C08  add      x8, x0, x21, lsl #3
//   0x32492c: AA0803E9  mov      x9, x8
//   0x324930: F900029F  str      xzr, [x20]
static inline uint64_t fde_func_1814_0x324924(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x324924ULL ^ (static_cast<uint64_t>(0xf940028aULL) << 13);
    acc = (acc + a1 + 0x8b150c08ULL) ^ 0x11b580ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1815 | PC: 0x3249ec | FDE: 0x11b670 | Size: 192 bytes
// Khung tháo gỡ #1815 | Địa chỉ PC: 0x3249ec | Địa chỉ FDE: 0x11b670 | Kích thước: 192 bytes
//   0x3249ec: A940AB69  ldp      x9, x10, [x27, #8]
//   0x3249f0: CB090149  sub      x9, x10, x9
//   0x3249f4: 9AD80D29  sdiv     x9, x9, x24
//   0x3249f8: 6B09011F  cmp      w8, w9
static inline uint64_t fde_func_1815_0x3249ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3249ecULL ^ (static_cast<uint64_t>(0xa940ab69ULL) << 13);
    acc = (acc + a1 + 0xcb090149ULL) ^ 0x11b670ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1816 | PC: 0x324aac | FDE: 0x11b760 | Size: 196 bytes
// Khung tháo gỡ #1816 | Địa chỉ PC: 0x324aac | Địa chỉ FDE: 0x11b760 | Kích thước: 196 bytes
//   0x324aac: F94006C8  ldr      x8, [x22, #8]
//   0x324ab0: AA1303EA  mov      x10, x19
//   0x324ab4: 9100066A  add      x10, x19, #1
//   0x324ab8: 8B0A0289  add      x9, x20, x10
static inline uint64_t fde_func_1816_0x324aac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x324aacULL ^ (static_cast<uint64_t>(0xf94006c8ULL) << 13);
    acc = (acc + a1 + 0xaa1303eaULL) ^ 0x11b760ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1817 | PC: 0x324b70 | FDE: 0x11b850 | Size: 116 bytes
// Khung tháo gỡ #1817 | Địa chỉ PC: 0x324b70 | Địa chỉ FDE: 0x11b850 | Kích thước: 116 bytes
//   0x324b70: 910006F7  add      x23, x23, #1
//   0x324b74: 8B170389  add      x9, x28, x23
//   0x324b78: EB0802FF  cmp      x23, x8
//   0x324b7c: 8A09011C  and      x28, x8, x9
static inline uint64_t fde_func_1817_0x324b70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x324b70ULL ^ (static_cast<uint64_t>(0x910006f7ULL) << 13);
    acc = (acc + a1 + 0x8b170389ULL) ^ 0x11b850ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1818 | PC: 0x324be4 | FDE: 0x11b940 | Size: 180 bytes
// Khung tháo gỡ #1818 | Địa chỉ PC: 0x324be4 | Địa chỉ FDE: 0x11b940 | Kích thước: 180 bytes
//   0x324be4: 9100C3E0  add      x0, sp, #0x30
//   0x324be8: 910063E1  add      x1, sp, #0x18
//   0x324bec: D65F03C0  ret      
//   0x324bf0: 9100C3E0  add      x0, sp, #0x30
static inline uint64_t fde_func_1818_0x324be4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x324be4ULL ^ (static_cast<uint64_t>(0x9100c3e0ULL) << 13);
    acc = (acc + a1 + 0x910063e1ULL) ^ 0x11b940ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1819 | PC: 0x324c98 | FDE: 0x11ba38 | Size: 216 bytes
// Khung tháo gỡ #1819 | Địa chỉ PC: 0x324c98 | Địa chỉ FDE: 0x11ba38 | Kích thước: 216 bytes
//   0x324c98: D53BD056  mrs      x22, tpidr_el0
//   0x324c9c: F94016C8  ldr      x8, [x22, #0x28]
//   0x324ca0: AA0003F5  mov      x21, x0
//   0x324ca4: D65F03C0  ret      
static inline uint64_t fde_func_1819_0x324c98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x324c98ULL ^ (static_cast<uint64_t>(0xd53bd056ULL) << 13);
    acc = (acc + a1 + 0xf94016c8ULL) ^ 0x11ba38ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1820 | PC: 0x324d70 | FDE: 0x11bb30 | Size: 224 bytes
// Khung tháo gỡ #1820 | Địa chỉ PC: 0x324d70 | Địa chỉ FDE: 0x11bb30 | Kích thước: 224 bytes
//   0x324d70: F9000309  str      x9, [x24]
//   0x324d74: F85F0109  ldur     x9, [x8, #-0x10]
//   0x324d78: F9000118  str      x24, [x8]
//   0x324d7c: F83B7928  str      x8, [x9, x27, lsl #3]
static inline uint64_t fde_func_1820_0x324d70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x324d70ULL ^ (static_cast<uint64_t>(0xf9000309ULL) << 13);
    acc = (acc + a1 + 0xf85f0109ULL) ^ 0x11bb30ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #1821 | PC: 0x324e50 | FDE: 0x11bc28 | Size: 176 bytes
// Khung tháo gỡ #1821 | Địa chỉ PC: 0x324e50 | Địa chỉ FDE: 0x11bc28 | Kích thước: 176 bytes
//   0x324e50: F1000EBF  cmp      x21, #3
//   0x324e54: D10006A8  sub      x8, x21, #1
//   0x324e58: 1A9F27E9  cset     w9, lo
//   0x324e5c: EA0802BF  tst      x21, x8
static inline uint64_t fde_func_1821_0x324e50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x324e50ULL ^ (static_cast<uint64_t>(0xf1000ebfULL) << 13);
    acc = (acc + a1 + 0xd10006a8ULL) ^ 0x11bc28ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1822 | PC: 0x324f00 | FDE: 0x11bd18 | Size: 160 bytes
// Khung tháo gỡ #1822 | Địa chỉ PC: 0x324f00 | Địa chỉ FDE: 0x11bd18 | Kích thước: 160 bytes
//   0x324f00: F90003E8  str      x8, [sp]
//   0x324f04: F900003F  str      xzr, [x1]
//   0x324f08: F9400008  ldr      x8, [x0]
//   0x324f0c: 910003E1  mov      x1, sp
static inline uint64_t fde_func_1822_0x324f00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x324f00ULL ^ (static_cast<uint64_t>(0xf90003e8ULL) << 13);
    acc = (acc + a1 + 0xf900003fULL) ^ 0x11bd18ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1823 | PC: 0x324fa0 | FDE: 0x11be08 | Size: 164 bytes
// Khung tháo gỡ #1823 | Địa chỉ PC: 0x324fa0 | Địa chỉ FDE: 0x11be08 | Kích thước: 164 bytes
//   0x324fa0: AA1803E1  mov      x1, x24
//   0x324fa4: 17F8FEA6  b        #0x164a3c
//   0x324fa8: 927FF908  and      x8, x8, #0xfffffffffffffffe
//   0x324fac: F9000808  str      x8, [x0, #0x10]
static inline uint64_t fde_func_1823_0x324fa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x324fa0ULL ^ (static_cast<uint64_t>(0xaa1803e1ULL) << 13);
    acc = (acc + a1 + 0x17f8fea6ULL) ^ 0x11be08ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1824 | PC: 0x325044 | FDE: 0x11bef8 | Size: 228 bytes
// Khung tháo gỡ #1824 | Địa chỉ PC: 0x325044 | Địa chỉ FDE: 0x11bef8 | Kích thước: 228 bytes
//   0x325044: D53BD054  mrs      x20, tpidr_el0
//   0x325048: F9401688  ldr      x8, [x20, #0x28]
//   0x32504c: AA0003F3  mov      x19, x0
//   0x325050: 910003E0  mov      x0, sp
static inline uint64_t fde_func_1824_0x325044(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x325044ULL ^ (static_cast<uint64_t>(0xd53bd054ULL) << 13);
    acc = (acc + a1 + 0xf9401688ULL) ^ 0x11bef8ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1825 | PC: 0x325128 | FDE: 0x11bfe8 | Size: 128 bytes
// Khung tháo gỡ #1825 | Địa chỉ PC: 0x325128 | Địa chỉ FDE: 0x11bfe8 | Kích thước: 128 bytes
//   0x325128: AA1703E0  mov      x0, x23
//   0x32512c: 14006D41  b        #0x340630
//   0x325130: AA1703E0  mov      x0, x23
//   0x325134: 14006CDF  b        #0x3404b0
static inline uint64_t fde_func_1825_0x325128(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x325128ULL ^ (static_cast<uint64_t>(0xaa1703e0ULL) << 13);
    acc = (acc + a1 + 0x14006d41ULL) ^ 0x11bfe8ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1826 | PC: 0x3251a8 | FDE: 0x11c0d8 | Size: 96 bytes
// Khung tháo gỡ #1826 | Địa chỉ PC: 0x3251a8 | Địa chỉ FDE: 0x11c0d8 | Kích thước: 96 bytes
//   0x3251a8: AA1303E0  mov      x0, x19
//   0x3251ac: 17F957FA  b        #0x17b194
//   0x3251b0: AA0803E0  mov      x0, x8
//   0x3251b4: 17FA0CB9  b        #0x1a8498
static inline uint64_t fde_func_1826_0x3251a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3251a8ULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0x17f957faULL) ^ 0x11c0d8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1827 | PC: 0x325208 | FDE: 0x11c1c8 | Size: 188 bytes
// Khung tháo gỡ #1827 | Địa chỉ PC: 0x325208 | Địa chỉ FDE: 0x11c1c8 | Kích thước: 188 bytes
//   0x325208: AA1503E0  mov      x0, x21
//   0x32520c: 17F8D272  b        #0x159bd4
//   0x325210: AA0103F4  mov      x20, x1
//   0x325214: AA0003F5  mov      x21, x0
static inline uint64_t fde_func_1827_0x325208(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x325208ULL ^ (static_cast<uint64_t>(0xaa1503e0ULL) << 13);
    acc = (acc + a1 + 0x17f8d272ULL) ^ 0x11c1c8ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1828 | PC: 0x3252c4 | FDE: 0x11c2c0 | Size: 108 bytes
// Khung tháo gỡ #1828 | Địa chỉ PC: 0x3252c4 | Địa chỉ FDE: 0x11c2c0 | Kích thước: 108 bytes
//   0x3252c4: 910083E0  add      x0, sp, #0x20
//   0x3252c8: F90013FF  str      xzr, [sp, #0x20]
//   0x3252cc: D65F03C0  ret      
//   0x3252d0: 910023E0  add      x0, sp, #8
static inline uint64_t fde_func_1828_0x3252c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3252c4ULL ^ (static_cast<uint64_t>(0x910083e0ULL) << 13);
    acc = (acc + a1 + 0xf90013ffULL) ^ 0x11c2c0ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1829 | PC: 0x325330 | FDE: 0x11c3b0 | Size: 204 bytes
// Khung tháo gỡ #1829 | Địa chỉ PC: 0x325330 | Địa chỉ FDE: 0x11c3b0 | Kích thước: 204 bytes
//   0x325330: D53BD055  mrs      x21, tpidr_el0
//   0x325334: F94016A8  ldr      x8, [x21, #0x28]
//   0x325338: AA0003F3  mov      x19, x0
//   0x32533c: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_1829_0x325330(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x325330ULL ^ (static_cast<uint64_t>(0xd53bd055ULL) << 13);
    acc = (acc + a1 + 0xf94016a8ULL) ^ 0x11c3b0ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1830 | PC: 0x3253fc | FDE: 0x11c4a0 | Size: 152 bytes
// Khung tháo gỡ #1830 | Địa chỉ PC: 0x3253fc | Địa chỉ FDE: 0x11c4a0 | Kích thước: 152 bytes
//   0x3253fc: 52800A82  mov      w2, #0x54
//   0x325400: AA1403E1  mov      x1, x20
//   0x325404: 14006B57  b        #0x340160
//   0x325408: 2A0003E1  mov      w1, w0
static inline uint64_t fde_func_1830_0x3253fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3253fcULL ^ (static_cast<uint64_t>(0x52800a82ULL) << 13);
    acc = (acc + a1 + 0xaa1403e1ULL) ^ 0x11c4a0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1831 | PC: 0x325494 | FDE: 0x11c590 | Size: 232 bytes
// Khung tháo gỡ #1831 | Địa chỉ PC: 0x325494 | Địa chỉ FDE: 0x11c590 | Kích thước: 232 bytes
//   0x325494: 910063F3  add      x19, sp, #0x18
//   0x325498: 17F8D1C1  b        #0x159b9c
//   0x32549c: 9E780008  fcvtzs   x8, d0
//   0x3254a0: EB08013F  cmp      x9, x8
static inline uint64_t fde_func_1831_0x325494(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x325494ULL ^ (static_cast<uint64_t>(0x910063f3ULL) << 13);
    acc = (acc + a1 + 0x17f8d1c1ULL) ^ 0x11c590ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1832 | PC: 0x32557c | FDE: 0x11c680 | Size: 164 bytes
// Khung tháo gỡ #1832 | Địa chỉ PC: 0x32557c | Địa chỉ FDE: 0x11c680 | Kích thước: 164 bytes
//   0x32557c: F945FD29  ldr      x9, [x9, #0xbf8]
//   0x325580: D0FFEAC4  adrp     x4, #0x7f000
//   0x325584: 910776A5  add      x5, x21, #0x1dd
//   0x325588: 91008102  add      x2, x8, #0x20
static inline uint64_t fde_func_1832_0x32557c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32557cULL ^ (static_cast<uint64_t>(0xf945fd29ULL) << 13);
    acc = (acc + a1 + 0xd0ffeac4ULL) ^ 0x11c680ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1833 | PC: 0x325620 | FDE: 0x11c770 | Size: 120 bytes
// Khung tháo gỡ #1833 | Địa chỉ PC: 0x325620 | Địa chỉ FDE: 0x11c770 | Kích thước: 120 bytes
//   0x325620: 91000042  add      x2, x2, #0
//   0x325624: 14006B2B  b        #0x3402d0
//   0x325628: B94002C8  ldr      w8, [x22]
//   0x32562c: 7100151F  cmp      w8, #5
static inline uint64_t fde_func_1833_0x325620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x325620ULL ^ (static_cast<uint64_t>(0x91000042ULL) << 13);
    acc = (acc + a1 + 0x14006b2bULL) ^ 0x11c770ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1834 | PC: 0x325698 | FDE: 0x11c860 | Size: 196 bytes
// Khung tháo gỡ #1834 | Địa chỉ PC: 0x325698 | Địa chỉ FDE: 0x11c860 | Kích thước: 196 bytes
//   0x325698: A9BB6BFC  stp      x28, x26, [sp, #-0x50]!
//   0x32569c: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x3256a0: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x3256a4: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1834_0x325698(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x325698ULL ^ (static_cast<uint64_t>(0xa9bb6bfcULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x11c860ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1835 | PC: 0x32575c | FDE: 0x11c950 | Size: 172 bytes
// Khung tháo gỡ #1835 | Địa chỉ PC: 0x32575c | Địa chỉ FDE: 0x11c950 | Kích thước: 172 bytes
//   0x32575c: 5AC00308  rbit     w8, w24
//   0x325760: 5AC01108  clz      w8, w8
//   0x325764: AA1703FD  mov      x29, x23
//   0x325768: AA1603F7  mov      x23, x22
static inline uint64_t fde_func_1835_0x32575c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32575cULL ^ (static_cast<uint64_t>(0x5ac00308ULL) << 13);
    acc = (acc + a1 + 0x5ac01108ULL) ^ 0x11c950ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1836 | PC: 0x325808 | FDE: 0x11ca40 | Size: 124 bytes
// Khung tháo gỡ #1836 | Địa chỉ PC: 0x325808 | Địa chỉ FDE: 0x11ca40 | Kích thước: 124 bytes
//   0x325808: B9401808  ldr      w8, [x0, #0x18]
//   0x32580c: 7100091F  cmp      w8, #2
//   0x325810: D65F03C0  ret      
//   0x325814: F9400A69  ldr      x9, [x19, #0x10]
static inline uint64_t fde_func_1836_0x325808(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x325808ULL ^ (static_cast<uint64_t>(0xb9401808ULL) << 13);
    acc = (acc + a1 + 0x7100091fULL) ^ 0x11ca40ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1837 | PC: 0x325884 | FDE: 0x11cb30 | Size: 236 bytes
// Khung tháo gỡ #1837 | Địa chỉ PC: 0x325884 | Địa chỉ FDE: 0x11cb30 | Kích thước: 236 bytes
//   0x325884: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x325888: 97F8D475  bl       #0x15aa5c
//   0x32588c: F9405288  ldr      x8, [x20, #0xa0]
//   0x325890: 3DC02680  ldr      q0, [x20, #0x90]
static inline uint64_t fde_func_1837_0x325884(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x325884ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x97f8d475ULL) ^ 0x11cb30ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #1838 | PC: 0x325970 | FDE: 0x11cc30 | Size: 232 bytes
// Khung tháo gỡ #1838 | Địa chỉ PC: 0x325970 | Địa chỉ FDE: 0x11cc30 | Kích thước: 232 bytes
//   0x325970: 910103E1  add      x1, sp, #0x40
//   0x325974: AA1403E0  mov      x0, x20
//   0x325978: D65F03C0  ret      
//   0x32597c: D53BD056  mrs      x22, tpidr_el0
static inline uint64_t fde_func_1838_0x325970(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x325970ULL ^ (static_cast<uint64_t>(0x910103e1ULL) << 13);
    acc = (acc + a1 + 0xaa1403e0ULL) ^ 0x11cc30ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1839 | PC: 0x325a58 | FDE: 0x11cd20 | Size: 172 bytes
// Khung tháo gỡ #1839 | Địa chỉ PC: 0x325a58 | Địa chỉ FDE: 0x11cd20 | Kích thước: 172 bytes
//   0x325a58: F9400260  ldr      x0, [x19]
//   0x325a5c: B9400808  ldr      w8, [x0, #8]
//   0x325a60: D65F03C0  ret      
//   0x325a64: AA0203F4  mov      x20, x2
static inline uint64_t fde_func_1839_0x325a58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x325a58ULL ^ (static_cast<uint64_t>(0xf9400260ULL) << 13);
    acc = (acc + a1 + 0xb9400808ULL) ^ 0x11cd20ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1840 | PC: 0x325b04 | FDE: 0x11ce18 | Size: 108 bytes
// Khung tháo gỡ #1840 | Địa chỉ PC: 0x325b04 | Địa chỉ FDE: 0x11ce18 | Kích thước: 108 bytes
//   0x325b04: AA1303E2  mov      x2, x19
//   0x325b08: AA0003F4  mov      x20, x0
//   0x325b0c: 17F9A9C6  b        #0x190224
//   0x325b10: AA0103F5  mov      x21, x1
static inline uint64_t fde_func_1840_0x325b04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x325b04ULL ^ (static_cast<uint64_t>(0xaa1303e2ULL) << 13);
    acc = (acc + a1 + 0xaa0003f4ULL) ^ 0x11ce18ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1841 | PC: 0x325b70 | FDE: 0x11cf08 | Size: 156 bytes
// Khung tháo gỡ #1841 | Địa chỉ PC: 0x325b70 | Địa chỉ FDE: 0x11cf08 | Kích thước: 156 bytes
//   0x325b70: 2A1F03E2  mov      w2, wzr
//   0x325b74: 2A1F03E3  mov      w3, wzr
//   0x325b78: 14006EBA  b        #0x341660
//   0x325b7c: F94002A8  ldr      x8, [x21]
static inline uint64_t fde_func_1841_0x325b70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x325b70ULL ^ (static_cast<uint64_t>(0x2a1f03e2ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e3ULL) ^ 0x11cf08ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1842 | PC: 0x325c0c | FDE: 0x11cff8 | Size: 100 bytes
// Khung tháo gỡ #1842 | Địa chỉ PC: 0x325c0c | Địa chỉ FDE: 0x11cff8 | Kích thước: 100 bytes
//   0x325c0c: F9400008  ldr      x8, [x0]
//   0x325c10: F9401D08  ldr      x8, [x8, #0x38]
//   0x325c14: D61F0100  br       x8
//   0x325c18: AA1603E2  mov      x2, x22
static inline uint64_t fde_func_1842_0x325c0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x325c0cULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9401d08ULL) ^ 0x11cff8ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1843 | PC: 0x325c70 | FDE: 0x11d0e8 | Size: 108 bytes
// Khung tháo gỡ #1843 | Địa chỉ PC: 0x325c70 | Địa chỉ FDE: 0x11d0e8 | Kích thước: 108 bytes
//   0x325c70: AA1603E0  mov      x0, x22
//   0x325c74: 140069F3  b        #0x340440
//   0x325c78: AA1603E0  mov      x0, x22
//   0x325c7c: 17F93CA2  b        #0x174f04
static inline uint64_t fde_func_1843_0x325c70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x325c70ULL ^ (static_cast<uint64_t>(0xaa1603e0ULL) << 13);
    acc = (acc + a1 + 0x140069f3ULL) ^ 0x11d0e8ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1844 | PC: 0x325cdc | FDE: 0x11d1d8 | Size: 100 bytes
// Khung tháo gỡ #1844 | Địa chỉ PC: 0x325cdc | Địa chỉ FDE: 0x11d1d8 | Kích thước: 100 bytes
//   0x325cdc: AA1303E0  mov      x0, x19
//   0x325ce0: F9406508  ldr      x8, [x8, #0xc8]
//   0x325ce4: D61F0100  br       x8
//   0x325ce8: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1844_0x325cdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x325cdcULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0xf9406508ULL) ^ 0x11d1d8ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1845 | PC: 0x325d40 | FDE: 0x11d2c8 | Size: 112 bytes
// Khung tháo gỡ #1845 | Địa chỉ PC: 0x325d40 | Địa chỉ FDE: 0x11d2c8 | Kích thước: 112 bytes
//   0x325d40: D3483C28  ubfx     x8, x1, #8, #8
//   0x325d44: 8B081415  add      x21, x0, x8, lsl #5
//   0x325d48: AA0003F3  mov      x19, x0
//   0x325d4c: AA1503E0  mov      x0, x21
static inline uint64_t fde_func_1845_0x325d40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x325d40ULL ^ (static_cast<uint64_t>(0xd3483c28ULL) << 13);
    acc = (acc + a1 + 0x8b081415ULL) ^ 0x11d2c8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1846 | PC: 0x325db0 | FDE: 0x11d3b8 | Size: 136 bytes
// Khung tháo gỡ #1846 | Địa chỉ PC: 0x325db0 | Địa chỉ FDE: 0x11d3b8 | Kích thước: 136 bytes
//   0x325db0: AA1503E0  mov      x0, x21
//   0x325db4: 17F8A50F  b        #0x14f1f0
//   0x325db8: AA0103F4  mov      x20, x1
//   0x325dbc: F9000FE8  str      x8, [sp, #0x18]
static inline uint64_t fde_func_1846_0x325db0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x325db0ULL ^ (static_cast<uint64_t>(0xaa1503e0ULL) << 13);
    acc = (acc + a1 + 0x17f8a50fULL) ^ 0x11d3b8ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1847 | PC: 0x325e38 | FDE: 0x11d4a8 | Size: 204 bytes
// Khung tháo gỡ #1847 | Địa chỉ PC: 0x325e38 | Địa chỉ FDE: 0x11d4a8 | Kích thước: 204 bytes
//   0x325e38: AA0003E2  mov      x2, x0
//   0x325e3c: 910003E0  mov      x0, sp
//   0x325e40: AA1803E1  mov      x1, x24
//   0x325e44: AA1603E3  mov      x3, x22
static inline uint64_t fde_func_1847_0x325e38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x325e38ULL ^ (static_cast<uint64_t>(0xaa0003e2ULL) << 13);
    acc = (acc + a1 + 0x910003e0ULL) ^ 0x11d4a8ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1848 | PC: 0x325f04 | FDE: 0x11d598 | Size: 104 bytes
// Khung tháo gỡ #1848 | Địa chỉ PC: 0x325f04 | Địa chỉ FDE: 0x11d598 | Kích thước: 104 bytes
//   0x325f04: AA1303E1  mov      x1, x19
//   0x325f08: 17F8CF33  b        #0x159bd4
//   0x325f0c: AA1403E0  mov      x0, x20
//   0x325f10: 14006A3C  b        #0x340800
static inline uint64_t fde_func_1848_0x325f04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x325f04ULL ^ (static_cast<uint64_t>(0xaa1303e1ULL) << 13);
    acc = (acc + a1 + 0x17f8cf33ULL) ^ 0x11d598ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1849 | PC: 0x325f6c | FDE: 0x11d688 | Size: 192 bytes
// Khung tháo gỡ #1849 | Địa chỉ PC: 0x325f6c | Địa chỉ FDE: 0x11d688 | Kích thước: 192 bytes
//   0x325f6c: 910743FF  add      sp, sp, #0x1d0
//   0x325f70: D65F03C0  ret      
//   0x325f74: F9410D08  ldr      x8, [x8, #0x218]
//   0x325f78: D61F0100  br       x8
static inline uint64_t fde_func_1849_0x325f6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x325f6cULL ^ (static_cast<uint64_t>(0x910743ffULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x11d688ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1850 | PC: 0x32602c | FDE: 0x11d778 | Size: 144 bytes
// Khung tháo gỡ #1850 | Địa chỉ PC: 0x32602c | Địa chỉ FDE: 0x11d778 | Kích thước: 144 bytes
//   0x32602c: 79402C08  ldrh     w8, [x0, #0x16]
//   0x326030: 7100291F  cmp      w8, #0xa
//   0x326034: 1A9F17E0  cset     w0, eq
//   0x326038: D65F03C0  ret      
static inline uint64_t fde_func_1850_0x32602c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32602cULL ^ (static_cast<uint64_t>(0x79402c08ULL) << 13);
    acc = (acc + a1 + 0x7100291fULL) ^ 0x11d778ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1851 | PC: 0x3260bc | FDE: 0x11d868 | Size: 136 bytes
// Khung tháo gỡ #1851 | Địa chỉ PC: 0x3260bc | Địa chỉ FDE: 0x11d868 | Kích thước: 136 bytes
//   0x3260bc: 90FFEA61  adrp     x1, #0x72000
//   0x3260c0: 91176821  add      x1, x1, #0x5da
//   0x3260c4: 910683E0  add      x0, sp, #0x1a0
//   0x3260c8: D65F03C0  ret      
static inline uint64_t fde_func_1851_0x3260bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3260bcULL ^ (static_cast<uint64_t>(0x90ffea61ULL) << 13);
    acc = (acc + a1 + 0x91176821ULL) ^ 0x11d868ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1852 | PC: 0x326144 | FDE: 0x11d958 | Size: 156 bytes
// Khung tháo gỡ #1852 | Địa chỉ PC: 0x326144 | Địa chỉ FDE: 0x11d958 | Kích thước: 156 bytes
//   0x326144: B9400A89  ldr      w9, [x20, #8]
//   0x326148: F940028A  ldr      x10, [x20]
//   0x32614c: 9100310B  add      x11, x8, #0xc
//   0x326150: B9000909  str      w9, [x8, #8]
static inline uint64_t fde_func_1852_0x326144(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x326144ULL ^ (static_cast<uint64_t>(0xb9400a89ULL) << 13);
    acc = (acc + a1 + 0xf940028aULL) ^ 0x11d958ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1853 | PC: 0x3261e0 | FDE: 0x11da48 | Size: 232 bytes
// Khung tháo gỡ #1853 | Địa chỉ PC: 0x3261e0 | Địa chỉ FDE: 0x11da48 | Kích thước: 232 bytes
//   0x3261e0: 90FFEA61  adrp     x1, #0x72000
//   0x3261e4: 911A3C21  add      x1, x1, #0x68f
//   0x3261e8: 910023E0  add      x0, sp, #8
//   0x3261ec: D65F03C0  ret      
static inline uint64_t fde_func_1853_0x3261e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3261e0ULL ^ (static_cast<uint64_t>(0x90ffea61ULL) << 13);
    acc = (acc + a1 + 0x911a3c21ULL) ^ 0x11da48ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1854 | PC: 0x3262c8 | FDE: 0x11db38 | Size: 228 bytes
// Khung tháo gỡ #1854 | Địa chỉ PC: 0x3262c8 | Địa chỉ FDE: 0x11db38 | Kích thước: 228 bytes
//   0x3262c8: F0FFEA41  adrp     x1, #0x71000
//   0x3262cc: 913AB821  add      x1, x1, #0xeae
//   0x3262d0: 910263E0  add      x0, sp, #0x98
//   0x3262d4: D65F03C0  ret      
static inline uint64_t fde_func_1854_0x3262c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3262c8ULL ^ (static_cast<uint64_t>(0xf0ffea41ULL) << 13);
    acc = (acc + a1 + 0x913ab821ULL) ^ 0x11db38ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1855 | PC: 0x3263ac | FDE: 0x11dc28 | Size: 172 bytes
// Khung tháo gỡ #1855 | Địa chỉ PC: 0x3263ac | Địa chỉ FDE: 0x11dc28 | Kích thước: 172 bytes
//   0x3263ac: D53BD048  mrs      x8, tpidr_el0
//   0x3263b0: F9000BE8  str      x8, [sp, #0x10]
//   0x3263b4: F9401508  ldr      x8, [x8, #0x28]
//   0x3263b8: D65F03C0  ret      
static inline uint64_t fde_func_1855_0x3263ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3263acULL ^ (static_cast<uint64_t>(0xd53bd048ULL) << 13);
    acc = (acc + a1 + 0xf9000be8ULL) ^ 0x11dc28ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1856 | PC: 0x326458 | FDE: 0x11dd18 | Size: 172 bytes
// Khung tháo gỡ #1856 | Địa chỉ PC: 0x326458 | Địa chỉ FDE: 0x11dd18 | Kích thước: 172 bytes
//   0x326458: 90FFEB21  adrp     x1, #0x8a000
//   0x32645c: 9100C2E0  add      x0, x23, #0x30
//   0x326460: 910D3821  add      x1, x1, #0x34e
//   0x326464: 17F8CDDC  b        #0x159bd4
static inline uint64_t fde_func_1856_0x326458(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x326458ULL ^ (static_cast<uint64_t>(0x90ffeb21ULL) << 13);
    acc = (acc + a1 + 0x9100c2e0ULL) ^ 0x11dd18ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1857 | PC: 0x326504 | FDE: 0x11de10 | Size: 188 bytes
// Khung tháo gỡ #1857 | Địa chỉ PC: 0x326504 | Địa chỉ FDE: 0x11de10 | Kích thước: 188 bytes
//   0x326504: 52800062  mov      w2, #3
//   0x326508: AA1403E0  mov      x0, x20
//   0x32650c: AA1503E1  mov      x1, x21
//   0x326510: 17FE5722  b        #0x2bc198
static inline uint64_t fde_func_1857_0x326504(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x326504ULL ^ (static_cast<uint64_t>(0x52800062ULL) << 13);
    acc = (acc + a1 + 0xaa1403e0ULL) ^ 0x11de10ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1858 | PC: 0x3265c0 | FDE: 0x11df00 | Size: 124 bytes
// Khung tháo gỡ #1858 | Địa chỉ PC: 0x3265c0 | Địa chỉ FDE: 0x11df00 | Kích thước: 124 bytes
//   0x3265c0: 9106E3E1  add      x1, sp, #0x1b8
//   0x3265c4: AA1303E0  mov      x0, x19
//   0x3265c8: B901BBFF  str      wzr, [sp, #0x1b8]
//   0x3265cc: 17FCD51A  b        #0x25ba34
static inline uint64_t fde_func_1858_0x3265c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3265c0ULL ^ (static_cast<uint64_t>(0x9106e3e1ULL) << 13);
    acc = (acc + a1 + 0xaa1303e0ULL) ^ 0x11df00ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1859 | PC: 0x32663c | FDE: 0x11dff0 | Size: 120 bytes
// Khung tháo gỡ #1859 | Địa chỉ PC: 0x32663c | Địa chỉ FDE: 0x11dff0 | Kích thước: 120 bytes
//   0x32663c: 52800023  mov      w3, #1
//   0x326640: 14006C64  b        #0x3417d0
//   0x326644: 3D800400  str      q0, [x0, #0x10]
//   0x326648: F9001008  str      x8, [x0, #0x20]
static inline uint64_t fde_func_1859_0x32663c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32663cULL ^ (static_cast<uint64_t>(0x52800023ULL) << 13);
    acc = (acc + a1 + 0x14006c64ULL) ^ 0x11dff0ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1860 | PC: 0x3266b4 | FDE: 0x11e0e0 | Size: 128 bytes
// Khung tháo gỡ #1860 | Địa chỉ PC: 0x3266b4 | Địa chỉ FDE: 0x11e0e0 | Kích thước: 128 bytes
//   0x3266b4: F94017E1  ldr      x1, [sp, #0x28]
//   0x3266b8: B9400296  ldr      w22, [x20]
//   0x3266bc: 910023E0  add      x0, sp, #8
//   0x3266c0: 140069BC  b        #0x340db0
static inline uint64_t fde_func_1860_0x3266b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3266b4ULL ^ (static_cast<uint64_t>(0xf94017e1ULL) << 13);
    acc = (acc + a1 + 0xb9400296ULL) ^ 0x11e0e0ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1861 | PC: 0x326734 | FDE: 0x11e1d0 | Size: 140 bytes
// Khung tháo gỡ #1861 | Địa chỉ PC: 0x326734 | Địa chỉ FDE: 0x11e1d0 | Kích thước: 140 bytes
//   0x326734: 90FFEA61  adrp     x1, #0x72000
//   0x326738: 91235821  add      x1, x1, #0x8d6
//   0x32673c: 911323E0  add      x0, sp, #0x4c8
//   0x326740: 17F8CD25  b        #0x159bd4
static inline uint64_t fde_func_1861_0x326734(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x326734ULL ^ (static_cast<uint64_t>(0x90ffea61ULL) << 13);
    acc = (acc + a1 + 0x91235821ULL) ^ 0x11e1d0ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1862 | PC: 0x3267c0 | FDE: 0x11e2c0 | Size: 132 bytes
// Khung tháo gỡ #1862 | Địa chỉ PC: 0x3267c0 | Địa chỉ FDE: 0x11e2c0 | Kích thước: 132 bytes
//   0x3267c0: 910103E2  add      x2, sp, #0x40
//   0x3267c4: 9100A3E3  add      x3, sp, #0x28
//   0x3267c8: D65F03C0  ret      
//   0x3267cc: F9001BE8  str      x8, [sp, #0x30]
static inline uint64_t fde_func_1862_0x3267c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3267c0ULL ^ (static_cast<uint64_t>(0x910103e2ULL) << 13);
    acc = (acc + a1 + 0x9100a3e3ULL) ^ 0x11e2c0ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1863 | PC: 0x326844 | FDE: 0x11e3b0 | Size: 200 bytes
// Khung tháo gỡ #1863 | Địa chỉ PC: 0x326844 | Địa chỉ FDE: 0x11e3b0 | Kích thước: 200 bytes
//   0x326844: 910003E1  mov      x1, sp
//   0x326848: AA0003F5  mov      x21, x0
//   0x32684c: 3C8083E0  stur     q0, [sp, #8]
//   0x326850: A9007E7F  stp      xzr, xzr, [x19]
static inline uint64_t fde_func_1863_0x326844(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x326844ULL ^ (static_cast<uint64_t>(0x910003e1ULL) << 13);
    acc = (acc + a1 + 0xaa0003f5ULL) ^ 0x11e3b0ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1864 | PC: 0x32690c | FDE: 0x11e4a0 | Size: 180 bytes
// Khung tháo gỡ #1864 | Địa chỉ PC: 0x32690c | Địa chỉ FDE: 0x11e4a0 | Kích thước: 180 bytes
//   0x32690c: 3DC007E0  ldr      q0, [sp, #0x10]
//   0x326910: 3DC00261  ldr      q1, [x19]
//   0x326914: 910043E0  add      x0, sp, #0x10
//   0x326918: 3D800260  str      q0, [x19]
static inline uint64_t fde_func_1864_0x32690c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32690cULL ^ (static_cast<uint64_t>(0x3dc007e0ULL) << 13);
    acc = (acc + a1 + 0x3dc00261ULL) ^ 0x11e4a0ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1865 | PC: 0x3269c0 | FDE: 0x11e590 | Size: 188 bytes
// Khung tháo gỡ #1865 | Địa chỉ PC: 0x3269c0 | Địa chỉ FDE: 0x11e590 | Kích thước: 188 bytes
//   0x3269c0: D53BD059  mrs      x25, tpidr_el0
//   0x3269c4: AA0803F3  mov      x19, x8
//   0x3269c8: F9401728  ldr      x8, [x25, #0x28]
//   0x3269cc: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1865_0x3269c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3269c0ULL ^ (static_cast<uint64_t>(0xd53bd059ULL) << 13);
    acc = (acc + a1 + 0xaa0803f3ULL) ^ 0x11e590ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1866 | PC: 0x326a7c | FDE: 0x11e680 | Size: 224 bytes
// Khung tháo gỡ #1866 | Địa chỉ PC: 0x326a7c | Địa chỉ FDE: 0x11e680 | Kích thước: 224 bytes
//   0x326a7c: F9400269  ldr      x9, [x19]
//   0x326a80: F8287935  str      x21, [x9, x8, lsl #3]
//   0x326a84: D65F03C0  ret      
//   0x326a88: D53BD058  mrs      x24, tpidr_el0
static inline uint64_t fde_func_1866_0x326a7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x326a7cULL ^ (static_cast<uint64_t>(0xf9400269ULL) << 13);
    acc = (acc + a1 + 0xf8287935ULL) ^ 0x11e680ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #1867 | PC: 0x326b5c | FDE: 0x11e770 | Size: 220 bytes
// Khung tháo gỡ #1867 | Địa chỉ PC: 0x326b5c | Địa chỉ FDE: 0x11e770 | Kích thước: 220 bytes
//   0x326b5c: F9400288  ldr      x8, [x20]
//   0x326b60: AA1403E0  mov      x0, x20
//   0x326b64: F9417D08  ldr      x8, [x8, #0x2f8]
//   0x326b68: D61F0100  br       x8
static inline uint64_t fde_func_1867_0x326b5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x326b5cULL ^ (static_cast<uint64_t>(0xf9400288ULL) << 13);
    acc = (acc + a1 + 0xaa1403e0ULL) ^ 0x11e770ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #1868 | PC: 0x326c38 | FDE: 0x11e860 | Size: 184 bytes
// Khung tháo gỡ #1868 | Địa chỉ PC: 0x326c38 | Địa chỉ FDE: 0x11e860 | Kích thước: 184 bytes
//   0x326c38: AA1303E2  mov      x2, x19
//   0x326c3c: 17F8DA5C  b        #0x15d5ac
//   0x326c40: 6F00E400  movi     v0.2d, #0000000000000000
//   0x326c44: AA0003F7  mov      x23, x0
static inline uint64_t fde_func_1868_0x326c38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x326c38ULL ^ (static_cast<uint64_t>(0xaa1303e2ULL) << 13);
    acc = (acc + a1 + 0x17f8da5cULL) ^ 0x11e860ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1869 | PC: 0x326cf0 | FDE: 0x11e950 | Size: 204 bytes
// Khung tháo gỡ #1869 | Địa chỉ PC: 0x326cf0 | Địa chỉ FDE: 0x11e950 | Kích thước: 204 bytes
//   0x326cf0: F94002A8  ldr      x8, [x21]
//   0x326cf4: AA1503E0  mov      x0, x21
//   0x326cf8: F9401D08  ldr      x8, [x8, #0x38]
//   0x326cfc: D61F0100  br       x8
static inline uint64_t fde_func_1869_0x326cf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x326cf0ULL ^ (static_cast<uint64_t>(0xf94002a8ULL) << 13);
    acc = (acc + a1 + 0xaa1503e0ULL) ^ 0x11e950ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1870 | PC: 0x326dbc | FDE: 0x11ea40 | Size: 156 bytes
// Khung tháo gỡ #1870 | Địa chỉ PC: 0x326dbc | Địa chỉ FDE: 0x11ea40 | Kích thước: 156 bytes
//   0x326dbc: F9401508  ldr      x8, [x8, #0x28]
//   0x326dc0: 3942ED08  ldrb     w8, [x8, #0xbb]
//   0x326dc4: D65F03C0  ret      
//   0x326dc8: F9401508  ldr      x8, [x8, #0x28]
static inline uint64_t fde_func_1870_0x326dbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x326dbcULL ^ (static_cast<uint64_t>(0xf9401508ULL) << 13);
    acc = (acc + a1 + 0x3942ed08ULL) ^ 0x11ea40ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1871 | PC: 0x326e58 | FDE: 0x11eb30 | Size: 120 bytes
// Khung tháo gỡ #1871 | Địa chỉ PC: 0x326e58 | Địa chỉ FDE: 0x11eb30 | Kích thước: 120 bytes
//   0x326e58: AA1503E1  mov      x1, x21
//   0x326e5c: 17F8DC07  b        #0x15de78
//   0x326e60: AA1703E1  mov      x1, x23
//   0x326e64: AA1603E3  mov      x3, x22
static inline uint64_t fde_func_1871_0x326e58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x326e58ULL ^ (static_cast<uint64_t>(0xaa1503e1ULL) << 13);
    acc = (acc + a1 + 0x17f8dc07ULL) ^ 0x11eb30ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1872 | PC: 0x326ed0 | FDE: 0x11ec20 | Size: 144 bytes
// Khung tháo gỡ #1872 | Địa chỉ PC: 0x326ed0 | Địa chỉ FDE: 0x11ec20 | Kích thước: 144 bytes
//   0x326ed0: AA1603E0  mov      x0, x22
//   0x326ed4: 17F9CBDD  b        #0x199e48
//   0x326ed8: AA1603E0  mov      x0, x22
//   0x326edc: 17F8CB29  b        #0x159b80
static inline uint64_t fde_func_1872_0x326ed0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x326ed0ULL ^ (static_cast<uint64_t>(0xaa1603e0ULL) << 13);
    acc = (acc + a1 + 0x17f9cbddULL) ^ 0x11ec20ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1873 | PC: 0x326f60 | FDE: 0x11ed10 | Size: 104 bytes
// Khung tháo gỡ #1873 | Địa chỉ PC: 0x326f60 | Địa chỉ FDE: 0x11ed10 | Kích thước: 104 bytes
//   0x326f60: AA0203F5  mov      x21, x2
//   0x326f64: AA0003F4  mov      x20, x0
//   0x326f68: D65F03C0  ret      
//   0x326f6c: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1873_0x326f60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x326f60ULL ^ (static_cast<uint64_t>(0xaa0203f5ULL) << 13);
    acc = (acc + a1 + 0xaa0003f4ULL) ^ 0x11ed10ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1874 | PC: 0x326fc8 | FDE: 0x11ee00 | Size: 132 bytes
// Khung tháo gỡ #1874 | Địa chỉ PC: 0x326fc8 | Địa chỉ FDE: 0x11ee00 | Kích thước: 132 bytes
//   0x326fc8: AA1303E8  mov      x8, x19
//   0x326fcc: F8440D09  ldr      x9, [x8, #0x40]!
//   0x326fd0: F90002C9  str      x9, [x22]
//   0x326fd4: F85F0109  ldur     x9, [x8, #-0x10]
static inline uint64_t fde_func_1874_0x326fc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x326fc8ULL ^ (static_cast<uint64_t>(0xaa1303e8ULL) << 13);
    acc = (acc + a1 + 0xf8440d09ULL) ^ 0x11ee00ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1875 | PC: 0x32704c | FDE: 0x11eef0 | Size: 252 bytes
// Khung tháo gỡ #1875 | Địa chỉ PC: 0x32704c | Địa chỉ FDE: 0x11eef0 | Kích thước: 252 bytes
//   0x32704c: AA0003F3  mov      x19, x0
//   0x327050: AA0103E0  mov      x0, x1
//   0x327054: AA0203F4  mov      x20, x2
//   0x327058: D65F03C0  ret      
static inline uint64_t fde_func_1875_0x32704c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32704cULL ^ (static_cast<uint64_t>(0xaa0003f3ULL) << 13);
    acc = (acc + a1 + 0xaa0103e0ULL) ^ 0x11eef0ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1876 | PC: 0x327148 | FDE: 0x11efe0 | Size: 212 bytes
// Khung tháo gỡ #1876 | Địa chỉ PC: 0x327148 | Địa chỉ FDE: 0x11efe0 | Kích thước: 212 bytes
//   0x327148: AA0003E2  mov      x2, x0
//   0x32714c: AA1403E0  mov      x0, x20
//   0x327150: AA1303E3  mov      x3, x19
//   0x327154: 17F8F0F8  b        #0x163534
static inline uint64_t fde_func_1876_0x327148(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x327148ULL ^ (static_cast<uint64_t>(0xaa0003e2ULL) << 13);
    acc = (acc + a1 + 0xaa1403e0ULL) ^ 0x11efe0ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1877 | PC: 0x32721c | FDE: 0x11f0e8 | Size: 100 bytes
// Khung tháo gỡ #1877 | Địa chỉ PC: 0x32721c | Địa chỉ FDE: 0x11f0e8 | Kích thước: 100 bytes
//   0x32721c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x327220: 97F8CA58  bl       #0x159b80
//   0x327224: F9400288  ldr      x8, [x20]
//   0x327228: F84107FE  ldr      x30, [sp], #0x10
static inline uint64_t fde_func_1877_0x32721c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32721cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x97f8ca58ULL) ^ 0x11f0e8ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1878 | PC: 0x327280 | FDE: 0x11f1e0 | Size: 188 bytes
// Khung tháo gỡ #1878 | Địa chỉ PC: 0x327280 | Địa chỉ FDE: 0x11f1e0 | Kích thước: 188 bytes
//   0x327280: AA0003F4  mov      x20, x0
//   0x327284: 91002261  add      x1, x19, #8
//   0x327288: F8008408  str      x8, [x0], #8
//   0x32728c: D65F03C0  ret      
static inline uint64_t fde_func_1878_0x327280(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x327280ULL ^ (static_cast<uint64_t>(0xaa0003f4ULL) << 13);
    acc = (acc + a1 + 0x91002261ULL) ^ 0x11f1e0ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1879 | PC: 0x32733c | FDE: 0x11f2d0 | Size: 180 bytes
// Khung tháo gỡ #1879 | Địa chỉ PC: 0x32733c | Địa chỉ FDE: 0x11f2d0 | Kích thước: 180 bytes
//   0x32733c: F9418108  ldr      x8, [x8, #0x300]
//   0x327340: D61F0100  br       x8
//   0x327344: F9400283  ldr      x3, [x20]
//   0x327348: 910003E1  mov      x1, sp
static inline uint64_t fde_func_1879_0x32733c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32733cULL ^ (static_cast<uint64_t>(0xf9418108ULL) << 13);
    acc = (acc + a1 + 0xd61f0100ULL) ^ 0x11f2d0ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1880 | PC: 0x3273f0 | FDE: 0x11f3c0 | Size: 140 bytes
// Khung tháo gỡ #1880 | Địa chỉ PC: 0x3273f0 | Địa chỉ FDE: 0x11f3c0 | Kích thước: 140 bytes
//   0x3273f0: B0FFEAC1  adrp     x1, #0x80000
//   0x3273f4: 9127B021  add      x1, x1, #0x9ec
//   0x3273f8: 910183E0  add      x0, sp, #0x60
//   0x3273fc: 910123E2  add      x2, sp, #0x48
static inline uint64_t fde_func_1880_0x3273f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3273f0ULL ^ (static_cast<uint64_t>(0xb0ffeac1ULL) << 13);
    acc = (acc + a1 + 0x9127b021ULL) ^ 0x11f3c0ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1881 | PC: 0x32747c | FDE: 0x11f4b0 | Size: 152 bytes
// Khung tháo gỡ #1881 | Địa chỉ PC: 0x32747c | Địa chỉ FDE: 0x11f4b0 | Kích thước: 152 bytes
//   0x32747c: 90000200  adrp     x0, #0x367000
//   0x327480: 91020000  add      x0, x0, #0x80
//   0x327484: 14006387  b        #0x3402a0
//   0x327488: F9409009  ldr      x9, [x0, #0x120]
static inline uint64_t fde_func_1881_0x32747c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32747cULL ^ (static_cast<uint64_t>(0x90000200ULL) << 13);
    acc = (acc + a1 + 0x91020000ULL) ^ 0x11f4b0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1882 | PC: 0x327514 | FDE: 0x11f5a0 | Size: 164 bytes
// Khung tháo gỡ #1882 | Địa chỉ PC: 0x327514 | Địa chỉ FDE: 0x11f5a0 | Kích thước: 164 bytes
//   0x327514: 2A1603E1  mov      w1, w22
//   0x327518: AA1403E2  mov      x2, x20
//   0x32751c: 2A1F03E7  mov      w7, wzr
//   0x327520: 4EA81D00  mov      v0.16b, v8.16b
static inline uint64_t fde_func_1882_0x327514(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x327514ULL ^ (static_cast<uint64_t>(0x2a1603e1ULL) << 13);
    acc = (acc + a1 + 0xaa1403e2ULL) ^ 0x11f5a0ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1883 | PC: 0x3275b8 | FDE: 0x11f690 | Size: 192 bytes
// Khung tháo gỡ #1883 | Địa chỉ PC: 0x3275b8 | Địa chỉ FDE: 0x11f690 | Kích thước: 192 bytes
//   0x3275b8: 91032262  add      x2, x19, #0xc8
//   0x3275bc: 91077663  add      x3, x19, #0x1dd
//   0x3275c0: 52800024  mov      w4, #1
//   0x3275c4: AA1403E0  mov      x0, x20
static inline uint64_t fde_func_1883_0x3275b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3275b8ULL ^ (static_cast<uint64_t>(0x91032262ULL) << 13);
    acc = (acc + a1 + 0x91077663ULL) ^ 0x11f690ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1884 | PC: 0x327678 | FDE: 0x11f780 | Size: 128 bytes
// Khung tháo gỡ #1884 | Địa chỉ PC: 0x327678 | Địa chỉ FDE: 0x11f780 | Kích thước: 128 bytes
//   0x327678: D10006C8  sub      x8, x22, #1
//   0x32767c: EA0802DF  tst      x22, x8
//   0x327680: D65F03C0  ret      
//   0x327684: 1E624000  fcvt     s0, d0
static inline uint64_t fde_func_1884_0x327678(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x327678ULL ^ (static_cast<uint64_t>(0xd10006c8ULL) << 13);
    acc = (acc + a1 + 0xea0802dfULL) ^ 0x11f780ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1885 | PC: 0x3276f8 | FDE: 0x11f870 | Size: 152 bytes
// Khung tháo gỡ #1885 | Địa chỉ PC: 0x3276f8 | Địa chỉ FDE: 0x11f870 | Kích thước: 152 bytes
//   0x3276f8: 52800063  mov      w3, #3
//   0x3276fc: AA1603E0  mov      x0, x22
//   0x327700: AA1703E1  mov      x1, x23
//   0x327704: 52800078  mov      w24, #3
static inline uint64_t fde_func_1885_0x3276f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3276f8ULL ^ (static_cast<uint64_t>(0x52800063ULL) << 13);
    acc = (acc + a1 + 0xaa1603e0ULL) ^ 0x11f870ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1886 | PC: 0x327790 | FDE: 0x11f960 | Size: 200 bytes
// Khung tháo gỡ #1886 | Địa chỉ PC: 0x327790 | Địa chỉ FDE: 0x11f960 | Kích thước: 200 bytes
//   0x327790: 90FFEAE1  adrp     x1, #0x83000
//   0x327794: D0FFEA22  adrp     x2, #0x6d000
//   0x327798: 9136D021  add      x1, x1, #0xdb4
//   0x32779c: 910EE042  add      x2, x2, #0x3b8
static inline uint64_t fde_func_1886_0x327790(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x327790ULL ^ (static_cast<uint64_t>(0x90ffeae1ULL) << 13);
    acc = (acc + a1 + 0xd0ffea22ULL) ^ 0x11f960ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1887 | PC: 0x327858 | FDE: 0x11fa50 | Size: 148 bytes
// Khung tháo gỡ #1887 | Địa chỉ PC: 0x327858 | Địa chỉ FDE: 0x11fa50 | Kích thước: 148 bytes
//   0x327858: B84046A8  ldr      w8, [x21], #4
//   0x32785c: F94007E0  ldr      x0, [sp, #8]
//   0x327860: 910223E1  add      x1, sp, #0x88
//   0x327864: B9008BE8  str      w8, [sp, #0x88]
static inline uint64_t fde_func_1887_0x327858(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x327858ULL ^ (static_cast<uint64_t>(0xb84046a8ULL) << 13);
    acc = (acc + a1 + 0xf94007e0ULL) ^ 0x11fa50ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1888 | PC: 0x3278ec | FDE: 0x11fb40 | Size: 96 bytes
// Khung tháo gỡ #1888 | Địa chỉ PC: 0x3278ec | Địa chỉ FDE: 0x11fb40 | Kích thước: 96 bytes
//   0x3278ec: 910103E8  add      x8, sp, #0x40
//   0x3278f0: AA1703E0  mov      x0, x23
//   0x3278f4: 14006307  b        #0x340510
//   0x3278f8: FD0003E0  str      d0, [sp]
static inline uint64_t fde_func_1888_0x3278ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3278ecULL ^ (static_cast<uint64_t>(0x910103e8ULL) << 13);
    acc = (acc + a1 + 0xaa1703e0ULL) ^ 0x11fb40ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1889 | PC: 0x32794c | FDE: 0x11fc30 | Size: 140 bytes
// Khung tháo gỡ #1889 | Địa chỉ PC: 0x32794c | Địa chỉ FDE: 0x11fc30 | Kích thước: 140 bytes
//   0x32794c: 910A83E0  add      x0, sp, #0x2a0
//   0x327950: 17F8C88C  b        #0x159b80
//   0x327954: 6B1A029F  cmp      w20, w26
//   0x327958: B9006FF4  str      w20, [sp, #0x6c]
static inline uint64_t fde_func_1889_0x32794c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32794cULL ^ (static_cast<uint64_t>(0x910a83e0ULL) << 13);
    acc = (acc + a1 + 0x17f8c88cULL) ^ 0x11fc30ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1890 | PC: 0x3279d8 | FDE: 0x11fd20 | Size: 180 bytes
// Khung tháo gỡ #1890 | Địa chỉ PC: 0x3279d8 | Địa chỉ FDE: 0x11fd20 | Kích thước: 180 bytes
//   0x3279d8: 9AD50909  udiv     x9, x8, x21
//   0x3279dc: 9B15A128  msub     x8, x9, x21, x8
//   0x3279e0: D65F03C0  ret      
//   0x3279e4: F9400F29  ldr      x9, [x25, #0x18]
static inline uint64_t fde_func_1890_0x3279d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3279d8ULL ^ (static_cast<uint64_t>(0x9ad50909ULL) << 13);
    acc = (acc + a1 + 0x9b15a128ULL) ^ 0x11fd20ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1891 | PC: 0x327a8c | FDE: 0x11fe10 | Size: 152 bytes
// Khung tháo gỡ #1891 | Địa chỉ PC: 0x327a8c | Địa chỉ FDE: 0x11fe10 | Kích thước: 152 bytes
//   0x327a8c: 910163E0  add      x0, sp, #0x58
//   0x327a90: 17F8FAB9  b        #0x166574
//   0x327a94: 9100A3E0  add      x0, sp, #0x28
//   0x327a98: AA1503E1  mov      x1, x21
static inline uint64_t fde_func_1891_0x327a8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x327a8cULL ^ (static_cast<uint64_t>(0x910163e0ULL) << 13);
    acc = (acc + a1 + 0x17f8fab9ULL) ^ 0x11fe10ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1892 | PC: 0x327b24 | FDE: 0x11ff00 | Size: 132 bytes
// Khung tháo gỡ #1892 | Địa chỉ PC: 0x327b24 | Địa chỉ FDE: 0x11ff00 | Kích thước: 132 bytes
//   0x327b24: 910023E3  add      x3, sp, #8
//   0x327b28: AA0903E0  mov      x0, x9
//   0x327b2c: AA0803E2  mov      x2, x8
//   0x327b30: F90007EA  str      x10, [sp, #8]
static inline uint64_t fde_func_1892_0x327b24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x327b24ULL ^ (static_cast<uint64_t>(0x910023e3ULL) << 13);
    acc = (acc + a1 + 0xaa0903e0ULL) ^ 0x11ff00ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1893 | PC: 0x327ba8 | FDE: 0x11fff0 | Size: 136 bytes
// Khung tháo gỡ #1893 | Địa chỉ PC: 0x327ba8 | Địa chỉ FDE: 0x11fff0 | Kích thước: 136 bytes
//   0x327ba8: 9ADC092A  udiv     x10, x9, x28
//   0x327bac: 9B1CA549  msub     x9, x10, x28, x9
//   0x327bb0: D65F03C0  ret      
//   0x327bb4: AA1C03E0  mov      x0, x28
static inline uint64_t fde_func_1893_0x327ba8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x327ba8ULL ^ (static_cast<uint64_t>(0x9adc092aULL) << 13);
    acc = (acc + a1 + 0x9b1ca549ULL) ^ 0x11fff0ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1894 | PC: 0x327c30 | FDE: 0x1200e0 | Size: 136 bytes
// Khung tháo gỡ #1894 | Địa chỉ PC: 0x327c30 | Địa chỉ FDE: 0x1200e0 | Kích thước: 136 bytes
//   0x327c30: 910083E1  add      x1, sp, #0x20
//   0x327c34: AA1603E0  mov      x0, x22
//   0x327c38: D65F03C0  ret      
//   0x327c3c: 910083E1  add      x1, sp, #0x20
static inline uint64_t fde_func_1894_0x327c30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x327c30ULL ^ (static_cast<uint64_t>(0x910083e1ULL) << 13);
    acc = (acc + a1 + 0xaa1603e0ULL) ^ 0x1200e0ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1895 | PC: 0x327cb8 | FDE: 0x1201d0 | Size: 180 bytes
// Khung tháo gỡ #1895 | Địa chỉ PC: 0x327cb8 | Địa chỉ FDE: 0x1201d0 | Kích thước: 180 bytes
//   0x327cb8: AA0003E3  mov      x3, x0
//   0x327cbc: 9102E3E2  add      x2, sp, #0xb8
//   0x327cc0: AA1503E0  mov      x0, x21
//   0x327cc4: AA1703E1  mov      x1, x23
static inline uint64_t fde_func_1895_0x327cb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x327cb8ULL ^ (static_cast<uint64_t>(0xaa0003e3ULL) << 13);
    acc = (acc + a1 + 0x9102e3e2ULL) ^ 0x1201d0ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1896 | PC: 0x327d6c | FDE: 0x1202c0 | Size: 164 bytes
// Khung tháo gỡ #1896 | Địa chỉ PC: 0x327d6c | Địa chỉ FDE: 0x1202c0 | Kích thước: 164 bytes
//   0x327d6c: F94002E8  ldr      x8, [x23]
//   0x327d70: 910023E1  add      x1, sp, #8
//   0x327d74: AA1703E0  mov      x0, x23
//   0x327d78: F9402108  ldr      x8, [x8, #0x40]
static inline uint64_t fde_func_1896_0x327d6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x327d6cULL ^ (static_cast<uint64_t>(0xf94002e8ULL) << 13);
    acc = (acc + a1 + 0x910023e1ULL) ^ 0x1202c0ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1897 | PC: 0x327e10 | FDE: 0x1203b0 | Size: 164 bytes
// Khung tháo gỡ #1897 | Địa chỉ PC: 0x327e10 | Địa chỉ FDE: 0x1203b0 | Kích thước: 164 bytes
//   0x327e10: F9400E74  ldr      x20, [x19, #0x18]
//   0x327e14: 910343E0  add      x0, sp, #0xd0
//   0x327e18: AA1303E1  mov      x1, x19
//   0x327e1c: 910343F5  add      x21, sp, #0xd0
static inline uint64_t fde_func_1897_0x327e10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x327e10ULL ^ (static_cast<uint64_t>(0xf9400e74ULL) << 13);
    acc = (acc + a1 + 0x910343e0ULL) ^ 0x1203b0ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1898 | PC: 0x327eb4 | FDE: 0x1204a0 | Size: 128 bytes
// Khung tháo gỡ #1898 | Địa chỉ PC: 0x327eb4 | Địa chỉ FDE: 0x1204a0 | Kích thước: 128 bytes
//   0x327eb4: 910043E0  add      x0, sp, #0x10
//   0x327eb8: AA1503E1  mov      x1, x21
//   0x327ebc: 17F8CFD8  b        #0x15be1c
//   0x327ec0: 910043E0  add      x0, sp, #0x10
static inline uint64_t fde_func_1898_0x327eb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x327eb4ULL ^ (static_cast<uint64_t>(0x910043e0ULL) << 13);
    acc = (acc + a1 + 0xaa1503e1ULL) ^ 0x1204a0ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1899 | PC: 0x327f34 | FDE: 0x120590 | Size: 120 bytes
// Khung tháo gỡ #1899 | Địa chỉ PC: 0x327f34 | Địa chỉ FDE: 0x120590 | Kích thước: 120 bytes
//   0x327f34: F9400FE0  ldr      x0, [sp, #0x18]
//   0x327f38: 17F8CBF7  b        #0x15af14
//   0x327f3c: 910043E1  add      x1, sp, #0x10
//   0x327f40: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1899_0x327f34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x327f34ULL ^ (static_cast<uint64_t>(0xf9400fe0ULL) << 13);
    acc = (acc + a1 + 0x17f8cbf7ULL) ^ 0x120590ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1900 | PC: 0x327fac | FDE: 0x120680 | Size: 180 bytes
// Khung tháo gỡ #1900 | Địa chỉ PC: 0x327fac | Địa chỉ FDE: 0x120680 | Kích thước: 180 bytes
//   0x327fac: 910023E1  add      x1, sp, #8
//   0x327fb0: AA1603E0  mov      x0, x22
//   0x327fb4: 140060EB  b        #0x340360
//   0x327fb8: 910023E1  add      x1, sp, #8
static inline uint64_t fde_func_1900_0x327fac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x327facULL ^ (static_cast<uint64_t>(0x910023e1ULL) << 13);
    acc = (acc + a1 + 0xaa1603e0ULL) ^ 0x120680ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1901 | PC: 0x328060 | FDE: 0x120770 | Size: 156 bytes
// Khung tháo gỡ #1901 | Địa chỉ PC: 0x328060 | Địa chỉ FDE: 0x120770 | Kích thước: 156 bytes
//   0x328060: AA0003E1  mov      x1, x0
//   0x328064: 910003E0  mov      x0, sp
//   0x328068: D65F03C0  ret      
//   0x32806c: AA0003E1  mov      x1, x0
static inline uint64_t fde_func_1901_0x328060(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x328060ULL ^ (static_cast<uint64_t>(0xaa0003e1ULL) << 13);
    acc = (acc + a1 + 0x910003e0ULL) ^ 0x120770ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1902 | PC: 0x3280fc | FDE: 0x120860 | Size: 124 bytes
// Khung tháo gỡ #1902 | Địa chỉ PC: 0x3280fc | Địa chỉ FDE: 0x120860 | Kích thước: 124 bytes
//   0x3280fc: 910063E0  add      x0, sp, #0x18
//   0x328100: 17F8CB79  b        #0x15aee4
//   0x328104: 7100011F  cmp      w8, #0
//   0x328108: 1A9F17E8  cset     w8, eq
static inline uint64_t fde_func_1902_0x3280fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3280fcULL ^ (static_cast<uint64_t>(0x910063e0ULL) << 13);
    acc = (acc + a1 + 0x17f8cb79ULL) ^ 0x120860ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1903 | PC: 0x328178 | FDE: 0x120950 | Size: 168 bytes
// Khung tháo gỡ #1903 | Địa chỉ PC: 0x328178 | Địa chỉ FDE: 0x120950 | Kích thước: 168 bytes
//   0x328178: 2A0103E0  mov      w0, w1
//   0x32817c: 140062BD  b        #0x340c70
//   0x328180: 2A1F03E2  mov      w2, wzr
//   0x328184: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1903_0x328178(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x328178ULL ^ (static_cast<uint64_t>(0x2a0103e0ULL) << 13);
    acc = (acc + a1 + 0x140062bdULL) ^ 0x120950ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1904 | PC: 0x328220 | FDE: 0x120a40 | Size: 160 bytes
// Khung tháo gỡ #1904 | Địa chỉ PC: 0x328220 | Địa chỉ FDE: 0x120a40 | Kích thước: 160 bytes
//   0x328220: D53BD054  mrs      x20, tpidr_el0
//   0x328224: F9401689  ldr      x9, [x20, #0x28]
//   0x328228: D65F03C0  ret      
//   0x32822c: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1904_0x328220(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x328220ULL ^ (static_cast<uint64_t>(0xd53bd054ULL) << 13);
    acc = (acc + a1 + 0xf9401689ULL) ^ 0x120a40ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1905 | PC: 0x3282c0 | FDE: 0x120b30 | Size: 168 bytes
// Khung tháo gỡ #1905 | Địa chỉ PC: 0x3282c0 | Địa chỉ FDE: 0x120b30 | Kích thước: 168 bytes
//   0x3282c0: F9400008  ldr      x8, [x0]
//   0x3282c4: B9400809  ldr      w9, [x0, #8]
//   0x3282c8: AA0203F4  mov      x20, x2
//   0x3282cc: AA0003F5  mov      x21, x0
static inline uint64_t fde_func_1905_0x3282c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3282c0ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xb9400809ULL) ^ 0x120b30ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1906 | PC: 0x328368 | FDE: 0x120c20 | Size: 148 bytes
// Khung tháo gỡ #1906 | Địa chỉ PC: 0x328368 | Địa chỉ FDE: 0x120c20 | Kích thước: 148 bytes
//   0x328368: AA1703E1  mov      x1, x23
//   0x32836c: AA1603E2  mov      x2, x22
//   0x328370: D65F03C0  ret      
//   0x328374: D53BD05A  mrs      x26, tpidr_el0
static inline uint64_t fde_func_1906_0x328368(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x328368ULL ^ (static_cast<uint64_t>(0xaa1703e1ULL) << 13);
    acc = (acc + a1 + 0xaa1603e2ULL) ^ 0x120c20ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1907 | PC: 0x3283fc | FDE: 0x120d10 | Size: 136 bytes
// Khung tháo gỡ #1907 | Địa chỉ PC: 0x3283fc | Địa chỉ FDE: 0x120d10 | Kích thước: 136 bytes
//   0x3283fc: AA1603E0  mov      x0, x22
//   0x328400: AA1903E1  mov      x1, x25
//   0x328404: D65F03C0  ret      
//   0x328408: AA1603E0  mov      x0, x22
static inline uint64_t fde_func_1907_0x3283fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3283fcULL ^ (static_cast<uint64_t>(0xaa1603e0ULL) << 13);
    acc = (acc + a1 + 0xaa1903e1ULL) ^ 0x120d10ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1908 | PC: 0x328484 | FDE: 0x120e00 | Size: 104 bytes
// Khung tháo gỡ #1908 | Địa chỉ PC: 0x328484 | Địa chỉ FDE: 0x120e00 | Kích thước: 104 bytes
//   0x328484: AA1303E0  mov      x0, x19
//   0x328488: AA1503E3  mov      x3, x21
//   0x32848c: D65F03C0  ret      
//   0x328490: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1908_0x328484(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x328484ULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0xaa1503e3ULL) ^ 0x120e00ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1909 | PC: 0x3284ec | FDE: 0x120ef0 | Size: 120 bytes
// Khung tháo gỡ #1909 | Địa chỉ PC: 0x3284ec | Địa chỉ FDE: 0x120ef0 | Kích thước: 120 bytes
//   0x3284ec: AA1303E0  mov      x0, x19
//   0x3284f0: 17FCCD51  b        #0x25ba34
//   0x3284f4: AA1603E1  mov      x1, x22
//   0x3284f8: 17FADD1A  b        #0x1df960
static inline uint64_t fde_func_1909_0x3284ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3284ecULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0x17fccd51ULL) ^ 0x120ef0ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1910 | PC: 0x328564 | FDE: 0x120fe0 | Size: 164 bytes
// Khung tháo gỡ #1910 | Địa chỉ PC: 0x328564 | Địa chỉ FDE: 0x120fe0 | Kích thước: 164 bytes
//   0x328564: 910003E0  mov      x0, sp
//   0x328568: 17F91DED  b        #0x16fd1c
//   0x32856c: 910003E0  mov      x0, sp
//   0x328570: AA1703E1  mov      x1, x23
static inline uint64_t fde_func_1910_0x328564(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x328564ULL ^ (static_cast<uint64_t>(0x910003e0ULL) << 13);
    acc = (acc + a1 + 0x17f91dedULL) ^ 0x120fe0ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1911 | PC: 0x328608 | FDE: 0x1210d0 | Size: 188 bytes
// Khung tháo gỡ #1911 | Địa chỉ PC: 0x328608 | Địa chỉ FDE: 0x1210d0 | Kích thước: 188 bytes
//   0x328608: D53BD057  mrs      x23, tpidr_el0
//   0x32860c: F94016E8  ldr      x8, [x23, #0x28]
//   0x328610: 2A0003F5  mov      w21, w0
//   0x328614: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_1911_0x328608(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x328608ULL ^ (static_cast<uint64_t>(0xd53bd057ULL) << 13);
    acc = (acc + a1 + 0xf94016e8ULL) ^ 0x1210d0ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1912 | PC: 0x3286c4 | FDE: 0x1211c0 | Size: 112 bytes
// Khung tháo gỡ #1912 | Địa chỉ PC: 0x3286c4 | Địa chỉ FDE: 0x1211c0 | Kích thước: 112 bytes
//   0x3286c4: AA0103E0  mov      x0, x1
//   0x3286c8: AA0803E1  mov      x1, x8
//   0x3286cc: D61F0120  br       x9
//   0x3286d0: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_1912_0x3286c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3286c4ULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0xaa0803e1ULL) ^ 0x1211c0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1913 | PC: 0x328734 | FDE: 0x1212b0 | Size: 120 bytes
// Khung tháo gỡ #1913 | Địa chỉ PC: 0x328734 | Địa chỉ FDE: 0x1212b0 | Kích thước: 120 bytes
//   0x328734: 910023E0  add      x0, sp, #8
//   0x328738: 17F8EF34  b        #0x164408
//   0x32873c: 910023E0  add      x0, sp, #8
//   0x328740: 910043E1  add      x1, sp, #0x10
static inline uint64_t fde_func_1913_0x328734(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x328734ULL ^ (static_cast<uint64_t>(0x910023e0ULL) << 13);
    acc = (acc + a1 + 0x17f8ef34ULL) ^ 0x1212b0ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1914 | PC: 0x3287ac | FDE: 0x1213a0 | Size: 104 bytes
// Khung tháo gỡ #1914 | Địa chỉ PC: 0x3287ac | Địa chỉ FDE: 0x1213a0 | Kích thước: 104 bytes
//   0x3287ac: AA1303E1  mov      x1, x19
//   0x3287b0: F9400008  ldr      x8, [x0]
//   0x3287b4: D65F03C0  ret      
//   0x3287b8: AA1403E0  mov      x0, x20
static inline uint64_t fde_func_1914_0x3287ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3287acULL ^ (static_cast<uint64_t>(0xaa1303e1ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x1213a0ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1915 | PC: 0x328814 | FDE: 0x121490 | Size: 160 bytes
// Khung tháo gỡ #1915 | Địa chỉ PC: 0x328814 | Địa chỉ FDE: 0x121490 | Kích thước: 160 bytes
//   0x328814: AA0003F4  mov      x20, x0
//   0x328818: AA0103E0  mov      x0, x1
//   0x32881c: D65F03C0  ret      
//   0x328820: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1915_0x328814(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x328814ULL ^ (static_cast<uint64_t>(0xaa0003f4ULL) << 13);
    acc = (acc + a1 + 0xaa0103e0ULL) ^ 0x121490ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1916 | PC: 0x3288b4 | FDE: 0x121580 | Size: 180 bytes
// Khung tháo gỡ #1916 | Địa chỉ PC: 0x3288b4 | Địa chỉ FDE: 0x121580 | Kích thước: 180 bytes
//   0x3288b4: B0000169  adrp     x9, #0x355000
//   0x3288b8: 52800048  mov      w8, #2
//   0x3288bc: 91258129  add      x9, x9, #0x960
//   0x3288c0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1916_0x3288b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3288b4ULL ^ (static_cast<uint64_t>(0xb0000169ULL) << 13);
    acc = (acc + a1 + 0x52800048ULL) ^ 0x121580ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1917 | PC: 0x328968 | FDE: 0x121670 | Size: 252 bytes
// Khung tháo gỡ #1917 | Địa chỉ PC: 0x328968 | Địa chỉ FDE: 0x121670 | Kích thước: 252 bytes
//   0x328968: A9465268  ldp      x8, x20, [x19, #0x60]
//   0x32896c: 91018275  add      x21, x19, #0x60
//   0x328970: F9400509  ldr      x9, [x8, #8]
//   0x328974: F940028A  ldr      x10, [x20]
static inline uint64_t fde_func_1917_0x328968(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x328968ULL ^ (static_cast<uint64_t>(0xa9465268ULL) << 13);
    acc = (acc + a1 + 0x91018275ULL) ^ 0x121670ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1918 | PC: 0x328a64 | FDE: 0x121768 | Size: 228 bytes
// Khung tháo gỡ #1918 | Địa chỉ PC: 0x328a64 | Địa chỉ FDE: 0x121768 | Kích thước: 228 bytes
//   0x328a64: D53BD05B  mrs      x27, tpidr_el0
//   0x328a68: F9401768  ldr      x8, [x27, #0x28]
//   0x328a6c: AA0003FD  mov      x29, x0
//   0x328a70: 9100C3E0  add      x0, sp, #0x30
static inline uint64_t fde_func_1918_0x328a64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x328a64ULL ^ (static_cast<uint64_t>(0xd53bd05bULL) << 13);
    acc = (acc + a1 + 0xf9401768ULL) ^ 0x121768ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1919 | PC: 0x328b48 | FDE: 0x121858 | Size: 172 bytes
// Khung tháo gỡ #1919 | Địa chỉ PC: 0x328b48 | Địa chỉ FDE: 0x121858 | Kích thước: 172 bytes
//   0x328b48: 8B081528  add      x8, x9, x8, lsl #5
//   0x328b4c: 385E8109  ldurb    w9, [x8, #-0x18]
//   0x328b50: 71002D3F  cmp      w9, #0xb
//   0x328b54: D65F03C0  ret      
static inline uint64_t fde_func_1919_0x328b48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x328b48ULL ^ (static_cast<uint64_t>(0x8b081528ULL) << 13);
    acc = (acc + a1 + 0x385e8109ULL) ^ 0x121858ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1920 | PC: 0x328bf4 | FDE: 0x121948 | Size: 204 bytes
// Khung tháo gỡ #1920 | Địa chỉ PC: 0x328bf4 | Địa chỉ FDE: 0x121948 | Kích thước: 204 bytes
//   0x328bf4: D100056C  sub      x12, x11, #1
//   0x328bf8: EA0C017F  tst      x11, x12
//   0x328bfc: 91004129  add      x9, x9, #0x10
//   0x328c00: D65F03C0  ret      
static inline uint64_t fde_func_1920_0x328bf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x328bf4ULL ^ (static_cast<uint64_t>(0xd100056cULL) << 13);
    acc = (acc + a1 + 0xea0c017fULL) ^ 0x121948ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1921 | PC: 0x328cc0 | FDE: 0x121a38 | Size: 192 bytes
// Khung tháo gỡ #1921 | Địa chỉ PC: 0x328cc0 | Địa chỉ FDE: 0x121a38 | Kích thước: 192 bytes
//   0x328cc0: 91002101  add      x1, x8, #8
//   0x328cc4: 17F8C888  b        #0x15aee4
//   0x328cc8: 91002001  add      x1, x0, #8
//   0x328ccc: 910003E0  mov      x0, sp
static inline uint64_t fde_func_1921_0x328cc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x328cc0ULL ^ (static_cast<uint64_t>(0x91002101ULL) << 13);
    acc = (acc + a1 + 0x17f8c888ULL) ^ 0x121a38ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1922 | PC: 0x328d80 | FDE: 0x121b28 | Size: 232 bytes
// Khung tháo gỡ #1922 | Địa chỉ PC: 0x328d80 | Địa chỉ FDE: 0x121b28 | Kích thước: 232 bytes
//   0x328d80: 91004294  add      x20, x20, #0x10
//   0x328d84: D10042B5  sub      x21, x21, #0x10
//   0x328d88: D65F03C0  ret      
//   0x328d8c: F81F0FFE  str      x30, [sp, #-0x10]!
static inline uint64_t fde_func_1922_0x328d80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x328d80ULL ^ (static_cast<uint64_t>(0x91004294ULL) << 13);
    acc = (acc + a1 + 0xd10042b5ULL) ^ 0x121b28ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1923 | PC: 0x328e68 | FDE: 0x121c20 | Size: 196 bytes
// Khung tháo gỡ #1923 | Địa chỉ PC: 0x328e68 | Địa chỉ FDE: 0x121c20 | Kích thước: 196 bytes
//   0x328e68: 90FFEAE9  adrp     x9, #0x84000
//   0x328e6c: 912F5129  add      x9, x9, #0xbd4
//   0x328e70: 39403F08  ldrb     w8, [x24, #0xf]
//   0x328e74: 38746929  ldrb     w9, [x9, x20]
static inline uint64_t fde_func_1923_0x328e68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x328e68ULL ^ (static_cast<uint64_t>(0x90ffeae9ULL) << 13);
    acc = (acc + a1 + 0x912f5129ULL) ^ 0x121c20ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1924 | PC: 0x328f2c | FDE: 0x121d10 | Size: 144 bytes
// Khung tháo gỡ #1924 | Địa chỉ PC: 0x328f2c | Địa chỉ FDE: 0x121d10 | Kích thước: 144 bytes
//   0x328f2c: 9AD80B28  udiv     x8, x25, x24
//   0x328f30: 9B18E51A  msub     x26, x8, x24, x25
//   0x328f34: D65F03C0  ret      
//   0x328f38: 9101C3F3  add      x19, sp, #0x70
static inline uint64_t fde_func_1924_0x328f2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x328f2cULL ^ (static_cast<uint64_t>(0x9ad80b28ULL) << 13);
    acc = (acc + a1 + 0x9b18e51aULL) ^ 0x121d10ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1925 | PC: 0x328fbc | FDE: 0x121e00 | Size: 164 bytes
// Khung tháo gỡ #1925 | Địa chỉ PC: 0x328fbc | Địa chỉ FDE: 0x121e00 | Kích thước: 164 bytes
//   0x328fbc: 91006282  add      x2, x20, #0x18
//   0x328fc0: AA1403E1  mov      x1, x20
//   0x328fc4: D65F03C0  ret      
//   0x328fc8: B9401190  ldr      w16, [x12, #0x10]
static inline uint64_t fde_func_1925_0x328fbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x328fbcULL ^ (static_cast<uint64_t>(0x91006282ULL) << 13);
    acc = (acc + a1 + 0xaa1403e1ULL) ^ 0x121e00ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1926 | PC: 0x329060 | FDE: 0x121ef8 | Size: 144 bytes
// Khung tháo gỡ #1926 | Địa chỉ PC: 0x329060 | Địa chỉ FDE: 0x121ef8 | Kích thước: 144 bytes
//   0x329060: D29D1756  mov      x22, #0xe8ba
//   0x329064: F2B17456  movk     x22, #0x8ba2, lsl #16
//   0x329068: 52800B0B  mov      w11, #0x58
//   0x32906c: CB0A02A8  sub      x8, x21, x10
static inline uint64_t fde_func_1926_0x329060(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x329060ULL ^ (static_cast<uint64_t>(0xd29d1756ULL) << 13);
    acc = (acc + a1 + 0xf2b17456ULL) ^ 0x121ef8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1927 | PC: 0x3290f0 | FDE: 0x121fe8 | Size: 116 bytes
// Khung tháo gỡ #1927 | Địa chỉ PC: 0x3290f0 | Địa chỉ FDE: 0x121fe8 | Kích thước: 116 bytes
//   0x3290f0: 910343E0  add      x0, sp, #0xd0
//   0x3290f4: 9104C3E2  add      x2, sp, #0x130
//   0x3290f8: D65F03C0  ret      
//   0x3290fc: 9103A3E0  add      x0, sp, #0xe8
static inline uint64_t fde_func_1927_0x3290f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3290f0ULL ^ (static_cast<uint64_t>(0x910343e0ULL) << 13);
    acc = (acc + a1 + 0x9104c3e2ULL) ^ 0x121fe8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1928 | PC: 0x329164 | FDE: 0x1220d8 | Size: 180 bytes
// Khung tháo gỡ #1928 | Địa chỉ PC: 0x329164 | Địa chỉ FDE: 0x1220d8 | Kích thước: 180 bytes
//   0x329164: 91001294  add      x20, x20, #4
//   0x329168: D10012B5  sub      x21, x21, #4
//   0x32916c: D65F03C0  ret      
//   0x329170: 51000661  sub      w1, w19, #1
static inline uint64_t fde_func_1928_0x329164(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x329164ULL ^ (static_cast<uint64_t>(0x91001294ULL) << 13);
    acc = (acc + a1 + 0xd10012b5ULL) ^ 0x1220d8ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1929 | PC: 0x329218 | FDE: 0x1221c8 | Size: 236 bytes
// Khung tháo gỡ #1929 | Địa chỉ PC: 0x329218 | Địa chỉ FDE: 0x1221c8 | Kích thước: 236 bytes
//   0x329218: B0FFEA41  adrp     x1, #0x72000
//   0x32921c: 9129FC21  add      x1, x1, #0xa7f
//   0x329220: 910023E0  add      x0, sp, #8
//   0x329224: D65F03C0  ret      
static inline uint64_t fde_func_1929_0x329218(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x329218ULL ^ (static_cast<uint64_t>(0xb0ffea41ULL) << 13);
    acc = (acc + a1 + 0x9129fc21ULL) ^ 0x1221c8ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #1930 | PC: 0x329304 | FDE: 0x1222c0 | Size: 132 bytes
// Khung tháo gỡ #1930 | Địa chỉ PC: 0x329304 | Địa chỉ FDE: 0x1222c0 | Kích thước: 132 bytes
//   0x329304: A9402668  ldp      x8, x9, [x19]
//   0x329308: AA0003F5  mov      x21, x0
//   0x32930c: A9025FFF  stp      xzr, x23, [sp, #0x20]
//   0x329310: CB080128  sub      x8, x9, x8
static inline uint64_t fde_func_1930_0x329304(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x329304ULL ^ (static_cast<uint64_t>(0xa9402668ULL) << 13);
    acc = (acc + a1 + 0xaa0003f5ULL) ^ 0x1222c0ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1931 | PC: 0x329388 | FDE: 0x1223b0 | Size: 120 bytes
// Khung tháo gỡ #1931 | Địa chỉ PC: 0x329388 | Địa chỉ FDE: 0x1223b0 | Kích thước: 120 bytes
//   0x329388: 9100A3E0  add      x0, sp, #0x28
//   0x32938c: 910023E1  add      x1, sp, #8
//   0x329390: D65F03C0  ret      
//   0x329394: 9100A3E0  add      x0, sp, #0x28
static inline uint64_t fde_func_1931_0x329388(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x329388ULL ^ (static_cast<uint64_t>(0x9100a3e0ULL) << 13);
    acc = (acc + a1 + 0x910023e1ULL) ^ 0x1223b0ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1932 | PC: 0x329400 | FDE: 0x1224a0 | Size: 112 bytes
// Khung tháo gỡ #1932 | Địa chỉ PC: 0x329400 | Địa chỉ FDE: 0x1224a0 | Kích thước: 112 bytes
//   0x329400: 9102C3E0  add      x0, sp, #0xb0
//   0x329404: 14005C73  b        #0x3405d0
//   0x329408: B0FFEA41  adrp     x1, #0x72000
//   0x32940c: 91235821  add      x1, x1, #0x8d6
static inline uint64_t fde_func_1932_0x329400(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x329400ULL ^ (static_cast<uint64_t>(0x9102c3e0ULL) << 13);
    acc = (acc + a1 + 0x14005c73ULL) ^ 0x1224a0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1933 | PC: 0x329470 | FDE: 0x122590 | Size: 228 bytes
// Khung tháo gỡ #1933 | Địa chỉ PC: 0x329470 | Địa chỉ FDE: 0x122590 | Kích thước: 228 bytes
//   0x329470: 2A1403E8  mov      w8, w20
//   0x329474: D343FD09  lsr      x9, x8, #3
//   0x329478: 927D6529  and      x9, x9, #0x1ffffff8
//   0x32947c: 8B090269  add      x9, x19, x9
static inline uint64_t fde_func_1933_0x329470(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x329470ULL ^ (static_cast<uint64_t>(0x2a1403e8ULL) << 13);
    acc = (acc + a1 + 0xd343fd09ULL) ^ 0x122590ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1934 | PC: 0x329554 | FDE: 0x122680 | Size: 196 bytes
// Khung tháo gỡ #1934 | Địa chỉ PC: 0x329554 | Địa chỉ FDE: 0x122680 | Kích thước: 196 bytes
//   0x329554: AD0007E0  stp      q0, q1, [sp]
//   0x329558: AD010FE2  stp      q2, q3, [sp, #0x20]
//   0x32955c: AD0217E4  stp      q4, q5, [sp, #0x40]
//   0x329560: AD031FE6  stp      q6, q7, [sp, #0x60]
static inline uint64_t fde_func_1934_0x329554(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x329554ULL ^ (static_cast<uint64_t>(0xad0007e0ULL) << 13);
    acc = (acc + a1 + 0xad010fe2ULL) ^ 0x122680ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1935 | PC: 0x329618 | FDE: 0x122770 | Size: 216 bytes
// Khung tháo gỡ #1935 | Địa chỉ PC: 0x329618 | Địa chỉ FDE: 0x122770 | Kích thước: 216 bytes
//   0x329618: F9401D01  ldr      x1, [x8, #0x38]
//   0x32961c: D61F0020  br       x1
//   0x329620: 910003E1  mov      x1, sp
//   0x329624: 17F8D96D  b        #0x15fbd8
static inline uint64_t fde_func_1935_0x329618(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x329618ULL ^ (static_cast<uint64_t>(0xf9401d01ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x122770ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1936 | PC: 0x3296f0 | FDE: 0x122860 | Size: 168 bytes
// Khung tháo gỡ #1936 | Địa chỉ PC: 0x3296f0 | Địa chỉ FDE: 0x122860 | Kích thước: 168 bytes
//   0x3296f0: F9400660  ldr      x0, [x19, #8]
//   0x3296f4: F900067F  str      xzr, [x19, #8]
//   0x3296f8: D65F03C0  ret      
//   0x3296fc: F9400660  ldr      x0, [x19, #8]
static inline uint64_t fde_func_1936_0x3296f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3296f0ULL ^ (static_cast<uint64_t>(0xf9400660ULL) << 13);
    acc = (acc + a1 + 0xf900067fULL) ^ 0x122860ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1937 | PC: 0x329798 | FDE: 0x122950 | Size: 164 bytes
// Khung tháo gỡ #1937 | Địa chỉ PC: 0x329798 | Địa chỉ FDE: 0x122950 | Kích thước: 164 bytes
//   0x329798: F9400688  ldr      x8, [x20, #8]
//   0x32979c: EB16011F  cmp      x8, x22
//   0x3297a0: D65F03C0  ret      
//   0x3297a4: F9400688  ldr      x8, [x20, #8]
static inline uint64_t fde_func_1937_0x329798(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x329798ULL ^ (static_cast<uint64_t>(0xf9400688ULL) << 13);
    acc = (acc + a1 + 0xeb16011fULL) ^ 0x122950ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1938 | PC: 0x32983c | FDE: 0x122a40 | Size: 148 bytes
// Khung tháo gỡ #1938 | Địa chỉ PC: 0x32983c | Địa chỉ FDE: 0x122a40 | Kích thước: 148 bytes
//   0x32983c: AA1903E0  mov      x0, x25
//   0x329840: 17FAB126  b        #0x1d5cd8
//   0x329844: F94023E0  ldr      x0, [sp, #0x40]
//   0x329848: F90023FF  str      xzr, [sp, #0x40]
static inline uint64_t fde_func_1938_0x32983c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32983cULL ^ (static_cast<uint64_t>(0xaa1903e0ULL) << 13);
    acc = (acc + a1 + 0x17fab126ULL) ^ 0x122a40ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1939 | PC: 0x3298d0 | FDE: 0x122b30 | Size: 144 bytes
// Khung tháo gỡ #1939 | Địa chỉ PC: 0x3298d0 | Địa chỉ FDE: 0x122b30 | Kích thước: 144 bytes
//   0x3298d0: F9400013  ldr      x19, [x0]
//   0x3298d4: 14005A2B  b        #0x340180
//   0x3298d8: AA0203F4  mov      x20, x2
//   0x3298dc: AA0103F6  mov      x22, x1
static inline uint64_t fde_func_1939_0x3298d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3298d0ULL ^ (static_cast<uint64_t>(0xf9400013ULL) << 13);
    acc = (acc + a1 + 0x14005a2bULL) ^ 0x122b30ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1940 | PC: 0x329960 | FDE: 0x122c20 | Size: 256 bytes
// Khung tháo gỡ #1940 | Địa chỉ PC: 0x329960 | Địa chỉ FDE: 0x122c20 | Kích thước: 256 bytes
//   0x329960: F94003E8  ldr      x8, [sp]
//   0x329964: F9408A69  ldr      x9, [x19, #0x110]
//   0x329968: F9400FF4  ldr      x20, [sp, #0x18]
//   0x32996c: BD400100  ldr      s0, [x8]
static inline uint64_t fde_func_1940_0x329960(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x329960ULL ^ (static_cast<uint64_t>(0xf94003e8ULL) << 13);
    acc = (acc + a1 + 0xf9408a69ULL) ^ 0x122c20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1941 | PC: 0x329a88 | FDE: 0x122d10 | Size: 192 bytes
// Khung tháo gỡ #1941 | Địa chỉ PC: 0x329a88 | Địa chỉ FDE: 0x122d10 | Kích thước: 192 bytes
//   0x329a88: EB1802FF  cmp      x23, x24
//   0x329a8c: AA1803F9  mov      x25, x24
//   0x329a90: D65F03C0  ret      
//   0x329a94: 3DC003E0  ldr      q0, [sp]
static inline uint64_t fde_func_1941_0x329a88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x329a88ULL ^ (static_cast<uint64_t>(0xeb1802ffULL) << 13);
    acc = (acc + a1 + 0xaa1803f9ULL) ^ 0x122d10ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1942 | PC: 0x329b48 | FDE: 0x122e00 | Size: 116 bytes
// Khung tháo gỡ #1942 | Địa chỉ PC: 0x329b48 | Địa chỉ FDE: 0x122e00 | Kích thước: 116 bytes
//   0x329b48: 910063E0  add      x0, sp, #0x18
//   0x329b4c: 910163E1  add      x1, sp, #0x58
//   0x329b50: 910383E2  add      x2, sp, #0xe0
//   0x329b54: D65F03C0  ret      
static inline uint64_t fde_func_1942_0x329b48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x329b48ULL ^ (static_cast<uint64_t>(0x910063e0ULL) << 13);
    acc = (acc + a1 + 0x910163e1ULL) ^ 0x122e00ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1943 | PC: 0x329bbc | FDE: 0x122ef0 | Size: 172 bytes
// Khung tháo gỡ #1943 | Địa chỉ PC: 0x329bbc | Địa chỉ FDE: 0x122ef0 | Kích thước: 172 bytes
//   0x329bbc: AA1A03E0  mov      x0, x26
//   0x329bc0: 2A1703E1  mov      w1, w23
//   0x329bc4: 2A1803E2  mov      w2, w24
//   0x329bc8: D65F03C0  ret      
static inline uint64_t fde_func_1943_0x329bbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x329bbcULL ^ (static_cast<uint64_t>(0xaa1a03e0ULL) << 13);
    acc = (acc + a1 + 0x2a1703e1ULL) ^ 0x122ef0ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1944 | PC: 0x329c68 | FDE: 0x122fe0 | Size: 220 bytes
// Khung tháo gỡ #1944 | Địa chỉ PC: 0x329c68 | Địa chỉ FDE: 0x122fe0 | Kích thước: 220 bytes
//   0x329c68: AA0003F5  mov      x21, x0
//   0x329c6c: 910003E0  mov      x0, sp
//   0x329c70: D65F03C0  ret      
//   0x329c74: F9400E68  ldr      x8, [x19, #0x18]
static inline uint64_t fde_func_1944_0x329c68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x329c68ULL ^ (static_cast<uint64_t>(0xaa0003f5ULL) << 13);
    acc = (acc + a1 + 0x910003e0ULL) ^ 0x122fe0ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #1945 | PC: 0x329d44 | FDE: 0x1230d0 | Size: 256 bytes
// Khung tháo gỡ #1945 | Địa chỉ PC: 0x329d44 | Địa chỉ FDE: 0x1230d0 | Kích thước: 256 bytes
//   0x329d44: D53BD054  mrs      x20, tpidr_el0
//   0x329d48: F9401688  ldr      x8, [x20, #0x28]
//   0x329d4c: AA0003F3  mov      x19, x0
//   0x329d50: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_1945_0x329d44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x329d44ULL ^ (static_cast<uint64_t>(0xd53bd054ULL) << 13);
    acc = (acc + a1 + 0xf9401688ULL) ^ 0x1230d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1946 | PC: 0x329e44 | FDE: 0x1231c0 | Size: 184 bytes
// Khung tháo gỡ #1946 | Địa chỉ PC: 0x329e44 | Địa chỉ FDE: 0x1231c0 | Kích thước: 184 bytes
//   0x329e44: AA1603E2  mov      x2, x22
//   0x329e48: 140058C6  b        #0x340160
//   0x329e4c: AA1503E1  mov      x1, x21
//   0x329e50: 17F8D762  b        #0x15fbd8
static inline uint64_t fde_func_1946_0x329e44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x329e44ULL ^ (static_cast<uint64_t>(0xaa1603e2ULL) << 13);
    acc = (acc + a1 + 0x140058c6ULL) ^ 0x1231c0ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1947 | PC: 0x329efc | FDE: 0x1232b8 | Size: 120 bytes
// Khung tháo gỡ #1947 | Địa chỉ PC: 0x329efc | Địa chỉ FDE: 0x1232b8 | Kích thước: 120 bytes
//   0x329efc: F9400028  ldr      x8, [x1]
//   0x329f00: 927FF908  and      x8, x8, #0xfffffffffffffffe
//   0x329f04: F9000008  str      x8, [x0]
//   0x329f08: F9400029  ldr      x9, [x1]
static inline uint64_t fde_func_1947_0x329efc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x329efcULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0x927ff908ULL) ^ 0x1232b8ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1948 | PC: 0x329f74 | FDE: 0x1233a8 | Size: 124 bytes
// Khung tháo gỡ #1948 | Địa chỉ PC: 0x329f74 | Địa chỉ FDE: 0x1233a8 | Kích thước: 124 bytes
//   0x329f74: F9400268  ldr      x8, [x19]
//   0x329f78: B9400A69  ldr      w9, [x19, #8]
//   0x329f7c: D65F03C0  ret      
//   0x329f80: F9400268  ldr      x8, [x19]
static inline uint64_t fde_func_1948_0x329f74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x329f74ULL ^ (static_cast<uint64_t>(0xf9400268ULL) << 13);
    acc = (acc + a1 + 0xb9400a69ULL) ^ 0x1233a8ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1949 | PC: 0x329ff0 | FDE: 0x123498 | Size: 104 bytes
// Khung tháo gỡ #1949 | Địa chỉ PC: 0x329ff0 | Địa chỉ FDE: 0x123498 | Kích thước: 104 bytes
//   0x329ff0: AA1303E0  mov      x0, x19
//   0x329ff4: 4EA01C08  mov      v8.16b, v0.16b
//   0x329ff8: D65F03C0  ret      
//   0x329ffc: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1949_0x329ff0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x329ff0ULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0x4ea01c08ULL) ^ 0x123498ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1950 | PC: 0x32a058 | FDE: 0x123588 | Size: 140 bytes
// Khung tháo gỡ #1950 | Địa chỉ PC: 0x32a058 | Địa chỉ FDE: 0x123588 | Kích thước: 140 bytes
//   0x32a058: AA1503E0  mov      x0, x21
//   0x32a05c: 2A1903E1  mov      w1, w25
//   0x32a060: 2A1A03E2  mov      w2, w26
//   0x32a064: D65F03C0  ret      
static inline uint64_t fde_func_1950_0x32a058(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32a058ULL ^ (static_cast<uint64_t>(0xaa1503e0ULL) << 13);
    acc = (acc + a1 + 0x2a1903e1ULL) ^ 0x123588ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1951 | PC: 0x32a0e4 | FDE: 0x123678 | Size: 132 bytes
// Khung tháo gỡ #1951 | Địa chỉ PC: 0x32a0e4 | Địa chỉ FDE: 0x123678 | Kích thước: 132 bytes
//   0x32a0e4: 910003E0  mov      x0, sp
//   0x32a0e8: F90003FF  str      xzr, [sp]
//   0x32a0ec: D65F03C0  ret      
//   0x32a0f0: 910003E0  mov      x0, sp
static inline uint64_t fde_func_1951_0x32a0e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32a0e4ULL ^ (static_cast<uint64_t>(0x910003e0ULL) << 13);
    acc = (acc + a1 + 0xf90003ffULL) ^ 0x123678ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1952 | PC: 0x32a168 | FDE: 0x123768 | Size: 184 bytes
// Khung tháo gỡ #1952 | Địa chỉ PC: 0x32a168 | Địa chỉ FDE: 0x123768 | Kích thước: 184 bytes
//   0x32a168: D53BD057  mrs      x23, tpidr_el0
//   0x32a16c: F94016E8  ldr      x8, [x23, #0x28]
//   0x32a170: AA0103F3  mov      x19, x1
//   0x32a174: D65F03C0  ret      
static inline uint64_t fde_func_1952_0x32a168(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32a168ULL ^ (static_cast<uint64_t>(0xd53bd057ULL) << 13);
    acc = (acc + a1 + 0xf94016e8ULL) ^ 0x123768ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1953 | PC: 0x32a220 | FDE: 0x123860 | Size: 112 bytes
// Khung tháo gỡ #1953 | Địa chỉ PC: 0x32a220 | Địa chỉ FDE: 0x123860 | Kích thước: 112 bytes
//   0x32a220: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x32a224: 97F8BE57  bl       #0x159b80
//   0x32a228: D10062B5  sub      x21, x21, #0x18
//   0x32a22c: B10062BF  cmn      x21, #0x18
static inline uint64_t fde_func_1953_0x32a220(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32a220ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x97f8be57ULL) ^ 0x123860ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1954 | PC: 0x32a290 | FDE: 0x123958 | Size: 140 bytes
// Khung tháo gỡ #1954 | Địa chỉ PC: 0x32a290 | Địa chỉ FDE: 0x123958 | Kích thước: 140 bytes
//   0x32a290: AA1303E1  mov      x1, x19
//   0x32a294: 17F8D651  b        #0x15fbd8
//   0x32a298: AA1403E0  mov      x0, x20
//   0x32a29c: AA1703E2  mov      x2, x23
static inline uint64_t fde_func_1954_0x32a290(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32a290ULL ^ (static_cast<uint64_t>(0xaa1303e1ULL) << 13);
    acc = (acc + a1 + 0x17f8d651ULL) ^ 0x123958ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1955 | PC: 0x32a31c | FDE: 0x123a48 | Size: 256 bytes
// Khung tháo gỡ #1955 | Địa chỉ PC: 0x32a31c | Địa chỉ FDE: 0x123a48 | Kích thước: 256 bytes
//   0x32a31c: D53BD055  mrs      x21, tpidr_el0
//   0x32a320: F94016A8  ldr      x8, [x21, #0x28]
//   0x32a324: F90017E8  str      x8, [sp, #0x28]
//   0x32a328: F9401013  ldr      x19, [x0, #0x20]
static inline uint64_t fde_func_1955_0x32a31c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32a31cULL ^ (static_cast<uint64_t>(0xd53bd055ULL) << 13);
    acc = (acc + a1 + 0xf94016a8ULL) ^ 0x123a48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1956 | PC: 0x32a41c | FDE: 0x123b38 | Size: 160 bytes
// Khung tháo gỡ #1956 | Địa chỉ PC: 0x32a41c | Địa chỉ FDE: 0x123b38 | Kích thước: 160 bytes
//   0x32a41c: F90033E0  str      x0, [sp, #0x60]
//   0x32a420: F9400288  ldr      x8, [x20]
//   0x32a424: 910183E1  add      x1, sp, #0x60
//   0x32a428: AA1403E0  mov      x0, x20
static inline uint64_t fde_func_1956_0x32a41c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32a41cULL ^ (static_cast<uint64_t>(0xf90033e0ULL) << 13);
    acc = (acc + a1 + 0xf9400288ULL) ^ 0x123b38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1957 | PC: 0x32a4bc | FDE: 0x123c28 | Size: 192 bytes
// Khung tháo gỡ #1957 | Địa chỉ PC: 0x32a4bc | Địa chỉ FDE: 0x123c28 | Kích thước: 192 bytes
//   0x32a4bc: 914007E0  add      x0, sp, #1, lsl #12
//   0x32a4c0: 9116E000  add      x0, x0, #0x5b8
//   0x32a4c4: 14005843  b        #0x3405d0
//   0x32a4c8: 910403E0  add      x0, sp, #0x100
static inline uint64_t fde_func_1957_0x32a4bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32a4bcULL ^ (static_cast<uint64_t>(0x914007e0ULL) << 13);
    acc = (acc + a1 + 0x9116e000ULL) ^ 0x123c28ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1958 | PC: 0x32a57c | FDE: 0x123d20 | Size: 124 bytes
// Khung tháo gỡ #1958 | Địa chỉ PC: 0x32a57c | Địa chỉ FDE: 0x123d20 | Kích thước: 124 bytes
//   0x32a57c: F9410108  ldr      x8, [x8, #0x200]
//   0x32a580: AA1503E2  mov      x2, x21
//   0x32a584: D61F0100  br       x8
//   0x32a588: 9AC8098A  udiv     x10, x12, x8
static inline uint64_t fde_func_1958_0x32a57c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32a57cULL ^ (static_cast<uint64_t>(0xf9410108ULL) << 13);
    acc = (acc + a1 + 0xaa1503e2ULL) ^ 0x123d20ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1959 | PC: 0x32a5f8 | FDE: 0x123e10 | Size: 136 bytes
// Khung tháo gỡ #1959 | Địa chỉ PC: 0x32a5f8 | Địa chỉ FDE: 0x123e10 | Kích thước: 136 bytes
//   0x32a5f8: A900029F  stp      xzr, x0, [x20]
//   0x32a5fc: AA1303E0  mov      x0, x19
//   0x32a600: AA1403E1  mov      x1, x20
//   0x32a604: 17F934FD  b        #0x1779f8
static inline uint64_t fde_func_1959_0x32a5f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32a5f8ULL ^ (static_cast<uint64_t>(0xa900029fULL) << 13);
    acc = (acc + a1 + 0xaa1303e0ULL) ^ 0x123e10ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1960 | PC: 0x32a680 | FDE: 0x123f00 | Size: 140 bytes
// Khung tháo gỡ #1960 | Địa chỉ PC: 0x32a680 | Địa chỉ FDE: 0x123f00 | Kích thước: 140 bytes
//   0x32a680: 910423E1  add      x1, sp, #0x108
//   0x32a684: AA1303E0  mov      x0, x19
//   0x32a688: F90087E8  str      x8, [sp, #0x108]
//   0x32a68c: 17FE06A0  b        #0x2ac10c
static inline uint64_t fde_func_1960_0x32a680(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32a680ULL ^ (static_cast<uint64_t>(0x910423e1ULL) << 13);
    acc = (acc + a1 + 0xaa1303e0ULL) ^ 0x123f00ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1961 | PC: 0x32a70c | FDE: 0x123ff0 | Size: 176 bytes
// Khung tháo gỡ #1961 | Địa chỉ PC: 0x32a70c | Địa chỉ FDE: 0x123ff0 | Kích thước: 176 bytes
//   0x32a70c: F940F108  ldr      x8, [x8, #0x1e0]
//   0x32a710: D61F0100  br       x8
//   0x32a714: 3DC00181  ldr      q1, [x12]
//   0x32a718: 6EA08C21  cmeq     v1.4s, v1.4s, v0.4s
static inline uint64_t fde_func_1961_0x32a70c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32a70cULL ^ (static_cast<uint64_t>(0xf940f108ULL) << 13);
    acc = (acc + a1 + 0xd61f0100ULL) ^ 0x123ff0ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1962 | PC: 0x32a7bc | FDE: 0x1240e0 | Size: 164 bytes
// Khung tháo gỡ #1962 | Địa chỉ PC: 0x32a7bc | Địa chỉ FDE: 0x1240e0 | Kích thước: 164 bytes
//   0x32a7bc: 394023E8  ldrb     w8, [sp, #8]
//   0x32a7c0: F9400FE9  ldr      x9, [sp, #0x18]
//   0x32a7c4: D65F03C0  ret      
//   0x32a7c8: 52801602  mov      w2, #0xb0
static inline uint64_t fde_func_1962_0x32a7bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32a7bcULL ^ (static_cast<uint64_t>(0x394023e8ULL) << 13);
    acc = (acc + a1 + 0xf9400fe9ULL) ^ 0x1240e0ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1963 | PC: 0x32a860 | FDE: 0x1241d0 | Size: 180 bytes
// Khung tháo gỡ #1963 | Địa chỉ PC: 0x32a860 | Địa chỉ FDE: 0x1241d0 | Kích thước: 180 bytes
//   0x32a860: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x32a864: 97F9E63B  bl       #0x1a4150
//   0x32a868: F940BA68  ldr      x8, [x19, #0x170]
//   0x32a86c: F84107FE  ldr      x30, [sp], #0x10
static inline uint64_t fde_func_1963_0x32a860(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32a860ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x97f9e63bULL) ^ 0x1241d0ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1964 | PC: 0x32a914 | FDE: 0x1242c8 | Size: 164 bytes
// Khung tháo gỡ #1964 | Địa chỉ PC: 0x32a914 | Địa chỉ FDE: 0x1242c8 | Kích thước: 164 bytes
//   0x32a914: F9405EC1  ldr      x1, [x22, #0xb8]
//   0x32a918: 910023E2  add      x2, sp, #8
//   0x32a91c: AA0003F6  mov      x22, x0
//   0x32a920: 17FD89DB  b        #0x28d08c
static inline uint64_t fde_func_1964_0x32a914(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32a914ULL ^ (static_cast<uint64_t>(0xf9405ec1ULL) << 13);
    acc = (acc + a1 + 0x910023e2ULL) ^ 0x1242c8ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1965 | PC: 0x32a9b8 | FDE: 0x1243b8 | Size: 188 bytes
// Khung tháo gỡ #1965 | Địa chỉ PC: 0x32a9b8 | Địa chỉ FDE: 0x1243b8 | Kích thước: 188 bytes
//   0x32a9b8: 91006015  add      x21, x0, #0x18
//   0x32a9bc: AA0003F4  mov      x20, x0
//   0x32a9c0: 910083E8  add      x8, sp, #0x20
//   0x32a9c4: 52800029  mov      w9, #1
static inline uint64_t fde_func_1965_0x32a9b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32a9b8ULL ^ (static_cast<uint64_t>(0x91006015ULL) << 13);
    acc = (acc + a1 + 0xaa0003f4ULL) ^ 0x1243b8ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1966 | PC: 0x32aa74 | FDE: 0x1244a8 | Size: 168 bytes
// Khung tháo gỡ #1966 | Địa chỉ PC: 0x32aa74 | Địa chỉ FDE: 0x1244a8 | Kích thước: 168 bytes
//   0x32aa74: 910042B3  add      x19, x21, #0x10
//   0x32aa78: 910023E1  add      x1, sp, #8
//   0x32aa7c: AA1303E0  mov      x0, x19
//   0x32aa80: 17FBF448  b        #0x227ba0
static inline uint64_t fde_func_1966_0x32aa74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32aa74ULL ^ (static_cast<uint64_t>(0x910042b3ULL) << 13);
    acc = (acc + a1 + 0x910023e1ULL) ^ 0x1244a8ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1967 | PC: 0x32ab1c | FDE: 0x124598 | Size: 176 bytes
// Khung tháo gỡ #1967 | Địa chỉ PC: 0x32ab1c | Địa chỉ FDE: 0x124598 | Kích thước: 176 bytes
//   0x32ab1c: F9400FE8  ldr      x8, [sp, #0x18]
//   0x32ab20: 3CC083E0  ldur     q0, [sp, #8]
//   0x32ab24: 910083E1  add      x1, sp, #0x20
//   0x32ab28: AA1603E0  mov      x0, x22
static inline uint64_t fde_func_1967_0x32ab1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32ab1cULL ^ (static_cast<uint64_t>(0xf9400fe8ULL) << 13);
    acc = (acc + a1 + 0x3cc083e0ULL) ^ 0x124598ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1968 | PC: 0x32abcc | FDE: 0x124688 | Size: 176 bytes
// Khung tháo gỡ #1968 | Địa chỉ PC: 0x32abcc | Địa chỉ FDE: 0x124688 | Kích thước: 176 bytes
//   0x32abcc: D53BD048  mrs      x8, tpidr_el0
//   0x32abd0: F90007E8  str      x8, [sp, #8]
//   0x32abd4: F9401508  ldr      x8, [x8, #0x28]
//   0x32abd8: AA0103F7  mov      x23, x1
static inline uint64_t fde_func_1968_0x32abcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32abccULL ^ (static_cast<uint64_t>(0xd53bd048ULL) << 13);
    acc = (acc + a1 + 0xf90007e8ULL) ^ 0x124688ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1969 | PC: 0x32ac7c | FDE: 0x124778 | Size: 160 bytes
// Khung tháo gỡ #1969 | Địa chỉ PC: 0x32ac7c | Địa chỉ FDE: 0x124778 | Kích thước: 160 bytes
//   0x32ac7c: A9400F02  ldp      x2, x3, [x24]
//   0x32ac80: 9100C3E0  add      x0, sp, #0x30
//   0x32ac84: AA1603E1  mov      x1, x22
//   0x32ac88: 17FEC5C0  b        #0x2dc388
static inline uint64_t fde_func_1969_0x32ac7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32ac7cULL ^ (static_cast<uint64_t>(0xa9400f02ULL) << 13);
    acc = (acc + a1 + 0x9100c3e0ULL) ^ 0x124778ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1970 | PC: 0x32ad1c | FDE: 0x124868 | Size: 164 bytes
// Khung tháo gỡ #1970 | Địa chỉ PC: 0x32ad1c | Địa chỉ FDE: 0x124868 | Kích thước: 164 bytes
//   0x32ad1c: F9400100  ldr      x0, [x8]
//   0x32ad20: 17FEE503  b        #0x2e412c
//   0x32ad24: 4E71B800  addv     h0, v0.8h
//   0x32ad28: 1E260008  fmov     w8, s0
static inline uint64_t fde_func_1970_0x32ad1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32ad1cULL ^ (static_cast<uint64_t>(0xf9400100ULL) << 13);
    acc = (acc + a1 + 0x17fee503ULL) ^ 0x124868ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1971 | PC: 0x32adc0 | FDE: 0x124958 | Size: 132 bytes
// Khung tháo gỡ #1971 | Địa chỉ PC: 0x32adc0 | Địa chỉ FDE: 0x124958 | Kích thước: 132 bytes
//   0x32adc0: D10443FF  sub      sp, sp, #0x110
//   0x32adc4: A90D63FC  stp      x28, x24, [sp, #0xd0]
//   0x32adc8: A90E5BF7  stp      x23, x22, [sp, #0xe0]
//   0x32adcc: A90F53F5  stp      x21, x20, [sp, #0xf0]
static inline uint64_t fde_func_1971_0x32adc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32adc0ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90d63fcULL) ^ 0x124958ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1972 | PC: 0x32ae44 | FDE: 0x124a48 | Size: 200 bytes
// Khung tháo gỡ #1972 | Địa chỉ PC: 0x32ae44 | Địa chỉ FDE: 0x124a48 | Kích thước: 200 bytes
//   0x32ae44: D10643FF  sub      sp, sp, #0x190
//   0x32ae48: F9009BFC  str      x28, [sp, #0x130]
//   0x32ae4c: A9146BFB  stp      x27, x26, [sp, #0x140]
//   0x32ae50: A91563F9  stp      x25, x24, [sp, #0x150]
static inline uint64_t fde_func_1972_0x32ae44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32ae44ULL ^ (static_cast<uint64_t>(0xd10643ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x124a48ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1973 | PC: 0x32af0c | FDE: 0x124b38 | Size: 144 bytes
// Khung tháo gỡ #1973 | Địa chỉ PC: 0x32af0c | Địa chỉ FDE: 0x124b38 | Kích thước: 144 bytes
//   0x32af0c: 128003E1  mov      w1, #-0x20
//   0x32af10: 52800042  mov      w2, #2
//   0x32af14: 17F98890  b        #0x18d154
//   0x32af18: 910383E0  add      x0, sp, #0xe0
static inline uint64_t fde_func_1973_0x32af0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32af0cULL ^ (static_cast<uint64_t>(0x128003e1ULL) << 13);
    acc = (acc + a1 + 0x52800042ULL) ^ 0x124b38ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1974 | PC: 0x32af9c | FDE: 0x124c28 | Size: 172 bytes
// Khung tháo gỡ #1974 | Địa chỉ PC: 0x32af9c | Địa chỉ FDE: 0x124c28 | Kích thước: 172 bytes
//   0x32af9c: 910B23E1  add      x1, sp, #0x2c8
//   0x32afa0: AA1603E0  mov      x0, x22
//   0x32afa4: B902CBFC  str      w28, [sp, #0x2c8]
//   0x32afa8: 17F9136B  b        #0x16fd54
static inline uint64_t fde_func_1974_0x32af9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32af9cULL ^ (static_cast<uint64_t>(0x910b23e1ULL) << 13);
    acc = (acc + a1 + 0xaa1603e0ULL) ^ 0x124c28ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1975 | PC: 0x32b048 | FDE: 0x124d18 | Size: 156 bytes
// Khung tháo gỡ #1975 | Địa chỉ PC: 0x32b048 | Địa chỉ FDE: 0x124d18 | Kích thước: 156 bytes
//   0x32b048: F9001EA8  str      x8, [x21, #0x38]
//   0x32b04c: 3C8282A0  stur     q0, [x21, #0x28]
//   0x32b050: 17F8BE83  b        #0x15aa5c
//   0x32b054: 12000341  and      w1, w26, #1
static inline uint64_t fde_func_1975_0x32b048(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32b048ULL ^ (static_cast<uint64_t>(0xf9001ea8ULL) << 13);
    acc = (acc + a1 + 0x3c8282a0ULL) ^ 0x124d18ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1976 | PC: 0x32b0e4 | FDE: 0x124e08 | Size: 236 bytes
// Khung tháo gỡ #1976 | Địa chỉ PC: 0x32b0e4 | Địa chỉ FDE: 0x124e08 | Kích thước: 236 bytes
//   0x32b0e4: A9402668  ldp      x8, x9, [x19]
//   0x32b0e8: AA0003E1  mov      x1, x0
//   0x32b0ec: 910023E0  add      x0, sp, #8
//   0x32b0f0: AA1503E3  mov      x3, x21
static inline uint64_t fde_func_1976_0x32b0e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32b0e4ULL ^ (static_cast<uint64_t>(0xa9402668ULL) << 13);
    acc = (acc + a1 + 0xaa0003e1ULL) ^ 0x124e08ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #1977 | PC: 0x32b1d0 | FDE: 0x124f00 | Size: 136 bytes
// Khung tháo gỡ #1977 | Địa chỉ PC: 0x32b1d0 | Địa chỉ FDE: 0x124f00 | Kích thước: 136 bytes
//   0x32b1d0: 910042C0  add      x0, x22, #0x10
//   0x32b1d4: 91004321  add      x1, x25, #0x10
//   0x32b1d8: 9100A2D7  add      x23, x22, #0x28
//   0x32b1dc: 17F8D27F  b        #0x15fbd8
static inline uint64_t fde_func_1977_0x32b1d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32b1d0ULL ^ (static_cast<uint64_t>(0x910042c0ULL) << 13);
    acc = (acc + a1 + 0x91004321ULL) ^ 0x124f00ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1978 | PC: 0x32b258 | FDE: 0x124ff0 | Size: 188 bytes
// Khung tháo gỡ #1978 | Địa chỉ PC: 0x32b258 | Địa chỉ FDE: 0x124ff0 | Kích thước: 188 bytes
//   0x32b258: 910163E1  add      x1, sp, #0x58
//   0x32b25c: AA1503E0  mov      x0, x21
//   0x32b260: D65F03C0  ret      
//   0x32b264: 910163E1  add      x1, sp, #0x58
static inline uint64_t fde_func_1978_0x32b258(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32b258ULL ^ (static_cast<uint64_t>(0x910163e1ULL) << 13);
    acc = (acc + a1 + 0xaa1503e0ULL) ^ 0x124ff0ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1979 | PC: 0x32b314 | FDE: 0x1250e0 | Size: 136 bytes
// Khung tháo gỡ #1979 | Địa chỉ PC: 0x32b314 | Địa chỉ FDE: 0x1250e0 | Kích thước: 136 bytes
//   0x32b314: A9534FF4  ldp      x20, x19, [sp, #0x130]
//   0x32b318: A95257F6  ldp      x22, x21, [sp, #0x120]
//   0x32b31c: A9515FF8  ldp      x24, x23, [sp, #0x110]
//   0x32b320: A95067FA  ldp      x26, x25, [sp, #0x100]
static inline uint64_t fde_func_1979_0x32b314(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32b314ULL ^ (static_cast<uint64_t>(0xa9534ff4ULL) << 13);
    acc = (acc + a1 + 0xa95257f6ULL) ^ 0x1250e0ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1980 | PC: 0x32b39c | FDE: 0x1251d0 | Size: 124 bytes
// Khung tháo gỡ #1980 | Địa chỉ PC: 0x32b39c | Địa chỉ FDE: 0x1251d0 | Kích thước: 124 bytes
//   0x32b39c: F940FD09  ldr      x9, [x8, #0x1f8]
//   0x32b3a0: 910263E8  add      x8, sp, #0x98
//   0x32b3a4: D61F0120  br       x9
//   0x32b3a8: 910363E1  add      x1, sp, #0xd8
static inline uint64_t fde_func_1980_0x32b39c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32b39cULL ^ (static_cast<uint64_t>(0xf940fd09ULL) << 13);
    acc = (acc + a1 + 0x910263e8ULL) ^ 0x1251d0ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1981 | PC: 0x32b418 | FDE: 0x1252c0 | Size: 116 bytes
// Khung tháo gỡ #1981 | Địa chỉ PC: 0x32b418 | Địa chỉ FDE: 0x1252c0 | Kích thước: 116 bytes
//   0x32b418: 910203E1  add      x1, sp, #0x80
//   0x32b41c: AA1403E0  mov      x0, x20
//   0x32b420: D65F03C0  ret      
//   0x32b424: 9101A3E1  add      x1, sp, #0x68
static inline uint64_t fde_func_1981_0x32b418(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32b418ULL ^ (static_cast<uint64_t>(0x910203e1ULL) << 13);
    acc = (acc + a1 + 0xaa1403e0ULL) ^ 0x1252c0ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1982 | PC: 0x32b48c | FDE: 0x1253b0 | Size: 144 bytes
// Khung tháo gỡ #1982 | Địa chỉ PC: 0x32b48c | Địa chỉ FDE: 0x1253b0 | Kích thước: 144 bytes
//   0x32b48c: 9100E3E0  add      x0, sp, #0x38
//   0x32b490: 910003E1  mov      x1, sp
//   0x32b494: 910063E2  add      x2, sp, #0x18
//   0x32b498: 140057AA  b        #0x341340
static inline uint64_t fde_func_1982_0x32b48c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32b48cULL ^ (static_cast<uint64_t>(0x9100e3e0ULL) << 13);
    acc = (acc + a1 + 0x910003e1ULL) ^ 0x1253b0ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1983 | PC: 0x32b51c | FDE: 0x1254a0 | Size: 172 bytes
// Khung tháo gỡ #1983 | Địa chỉ PC: 0x32b51c | Địa chỉ FDE: 0x1254a0 | Kích thước: 172 bytes
//   0x32b51c: 3D801BE0  str      q0, [sp, #0x60]
//   0x32b520: F9003BE8  str      x8, [sp, #0x70]
//   0x32b524: 17F8BD4E  b        #0x15aa5c
//   0x32b528: F81F0FFE  str      x30, [sp, #-0x10]!
static inline uint64_t fde_func_1983_0x32b51c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32b51cULL ^ (static_cast<uint64_t>(0x3d801be0ULL) << 13);
    acc = (acc + a1 + 0xf9003be8ULL) ^ 0x1254a0ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1984 | PC: 0x32b5c8 | FDE: 0x125598 | Size: 100 bytes
// Khung tháo gỡ #1984 | Địa chỉ PC: 0x32b5c8 | Địa chỉ FDE: 0x125598 | Kích thước: 100 bytes
//   0x32b5c8: F9000A88  str      x8, [x20, #0x10]
//   0x32b5cc: 3D800280  str      q0, [x20]
//   0x32b5d0: D65F03C0  ret      
//   0x32b5d4: AA1F03E1  mov      x1, xzr
static inline uint64_t fde_func_1984_0x32b5c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32b5c8ULL ^ (static_cast<uint64_t>(0xf9000a88ULL) << 13);
    acc = (acc + a1 + 0x3d800280ULL) ^ 0x125598ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1985 | PC: 0x32b62c | FDE: 0x125688 | Size: 172 bytes
// Khung tháo gỡ #1985 | Địa chỉ PC: 0x32b62c | Địa chỉ FDE: 0x125688 | Kích thước: 172 bytes
//   0x32b62c: 9AD8096C  udiv     x12, x11, x24
//   0x32b630: 9B18AD8B  msub     x11, x12, x24, x11
//   0x32b634: D65F03C0  ret      
//   0x32b638: F94002E8  ldr      x8, [x23]
static inline uint64_t fde_func_1985_0x32b62c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32b62cULL ^ (static_cast<uint64_t>(0x9ad8096cULL) << 13);
    acc = (acc + a1 + 0x9b18ad8bULL) ^ 0x125688ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1986 | PC: 0x32b6d8 | FDE: 0x125778 | Size: 172 bytes
// Khung tháo gỡ #1986 | Địa chỉ PC: 0x32b6d8 | Địa chỉ FDE: 0x125778 | Kích thước: 172 bytes
//   0x32b6d8: 910063E1  add      x1, sp, #0x18
//   0x32b6dc: AA0003F3  mov      x19, x0
//   0x32b6e0: 17FFBCA1  b        #0x31a964
//   0x32b6e4: 910063E1  add      x1, sp, #0x18
static inline uint64_t fde_func_1986_0x32b6d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32b6d8ULL ^ (static_cast<uint64_t>(0x910063e1ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x125778ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1987 | PC: 0x32b784 | FDE: 0x125868 | Size: 156 bytes
// Khung tháo gỡ #1987 | Địa chỉ PC: 0x32b784 | Địa chỉ FDE: 0x125868 | Kích thước: 156 bytes
//   0x32b784: 9100E3E1  add      x1, sp, #0x38
//   0x32b788: AA1303E0  mov      x0, x19
//   0x32b78c: B9003BFF  str      wzr, [sp, #0x38]
//   0x32b790: 17FE088B  b        #0x2ad9bc
static inline uint64_t fde_func_1987_0x32b784(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32b784ULL ^ (static_cast<uint64_t>(0x9100e3e1ULL) << 13);
    acc = (acc + a1 + 0xaa1303e0ULL) ^ 0x125868ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1988 | PC: 0x32b820 | FDE: 0x125958 | Size: 168 bytes
// Khung tháo gỡ #1988 | Địa chỉ PC: 0x32b820 | Địa chỉ FDE: 0x125958 | Kích thước: 168 bytes
//   0x32b820: 910043E0  add      x0, sp, #0x10
//   0x32b824: AA0103F3  mov      x19, x1
//   0x32b828: F9000FE8  str      x8, [sp, #0x18]
//   0x32b82c: 17FCDE72  b        #0x2631f4
static inline uint64_t fde_func_1988_0x32b820(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32b820ULL ^ (static_cast<uint64_t>(0x910043e0ULL) << 13);
    acc = (acc + a1 + 0xaa0103f3ULL) ^ 0x125958ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1989 | PC: 0x32b8c8 | FDE: 0x125a48 | Size: 208 bytes
// Khung tháo gỡ #1989 | Địa chỉ PC: 0x32b8c8 | Địa chỉ FDE: 0x125a48 | Kích thước: 208 bytes
//   0x32b8c8: 910023E1  add      x1, sp, #8
//   0x32b8cc: 17FBA18B  b        #0x213ef8
//   0x32b8d0: 910023E1  add      x1, sp, #8
//   0x32b8d4: F90007E8  str      x8, [sp, #8]
static inline uint64_t fde_func_1989_0x32b8c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32b8c8ULL ^ (static_cast<uint64_t>(0x910023e1ULL) << 13);
    acc = (acc + a1 + 0x17fba18bULL) ^ 0x125a48ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1990 | PC: 0x32b998 | FDE: 0x125b38 | Size: 120 bytes
// Khung tháo gỡ #1990 | Địa chỉ PC: 0x32b998 | Địa chỉ FDE: 0x125b38 | Kích thước: 120 bytes
//   0x32b998: AA0203F4  mov      x20, x2
//   0x32b99c: F9000FE8  str      x8, [sp, #0x18]
//   0x32b9a0: D65F03C0  ret      
//   0x32b9a4: AA0203F4  mov      x20, x2
static inline uint64_t fde_func_1990_0x32b998(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32b998ULL ^ (static_cast<uint64_t>(0xaa0203f4ULL) << 13);
    acc = (acc + a1 + 0xf9000fe8ULL) ^ 0x125b38ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1991 | PC: 0x32ba10 | FDE: 0x125c28 | Size: 172 bytes
// Khung tháo gỡ #1991 | Địa chỉ PC: 0x32ba10 | Địa chỉ FDE: 0x125c28 | Kích thước: 172 bytes
//   0x32ba10: F9401708  ldr      x8, [x24, #0x28]
//   0x32ba14: AA0003F6  mov      x22, x0
//   0x32ba18: D65F03C0  ret      
//   0x32ba1c: D53BD058  mrs      x24, tpidr_el0
static inline uint64_t fde_func_1991_0x32ba10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32ba10ULL ^ (static_cast<uint64_t>(0xf9401708ULL) << 13);
    acc = (acc + a1 + 0xaa0003f6ULL) ^ 0x125c28ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1992 | PC: 0x32babc | FDE: 0x125d18 | Size: 204 bytes
// Khung tháo gỡ #1992 | Địa chỉ PC: 0x32babc | Địa chỉ FDE: 0x125d18 | Kích thước: 204 bytes
//   0x32babc: F9400288  ldr      x8, [x20]
//   0x32bac0: 910023E3  add      x3, sp, #8
//   0x32bac4: AA1403E0  mov      x0, x20
//   0x32bac8: AA1503E1  mov      x1, x21
static inline uint64_t fde_func_1992_0x32babc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32babcULL ^ (static_cast<uint64_t>(0xf9400288ULL) << 13);
    acc = (acc + a1 + 0x910023e3ULL) ^ 0x125d18ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1993 | PC: 0x32bb88 | FDE: 0x125e10 | Size: 148 bytes
// Khung tháo gỡ #1993 | Địa chỉ PC: 0x32bb88 | Địa chỉ FDE: 0x125e10 | Kích thước: 148 bytes
//   0x32bb88: AA0803F3  mov      x19, x8
//   0x32bb8c: 1400516D  b        #0x340140
//   0x32bb90: 12800008  mov      w8, #-1
//   0x32bb94: 7901101F  strh     wzr, [x0, #0x88]
static inline uint64_t fde_func_1993_0x32bb88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32bb88ULL ^ (static_cast<uint64_t>(0xaa0803f3ULL) << 13);
    acc = (acc + a1 + 0x1400516dULL) ^ 0x125e10ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1994 | PC: 0x32bc1c | FDE: 0x125f00 | Size: 176 bytes
// Khung tháo gỡ #1994 | Địa chỉ PC: 0x32bc1c | Địa chỉ FDE: 0x125f00 | Kích thước: 176 bytes
//   0x32bc1c: F9400808  ldr      x8, [x0, #0x10]
//   0x32bc20: 3DC00000  ldr      q0, [x0]
//   0x32bc24: F9000BE8  str      x8, [sp, #0x10]
//   0x32bc28: 3D8003E0  str      q0, [sp]
static inline uint64_t fde_func_1994_0x32bc1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32bc1cULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0x3dc00000ULL) ^ 0x125f00ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1995 | PC: 0x32bccc | FDE: 0x125ff0 | Size: 164 bytes
// Khung tháo gỡ #1995 | Địa chỉ PC: 0x32bccc | Địa chỉ FDE: 0x125ff0 | Kích thước: 164 bytes
//   0x32bccc: AA0003F5  mov      x21, x0
//   0x32bcd0: F9000008  str      x8, [x0]
//   0x32bcd4: 3C808000  stur     q0, [x0, #8]
//   0x32bcd8: 91006000  add      x0, x0, #0x18
static inline uint64_t fde_func_1995_0x32bccc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32bcccULL ^ (static_cast<uint64_t>(0xaa0003f5ULL) << 13);
    acc = (acc + a1 + 0xf9000008ULL) ^ 0x125ff0ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1996 | PC: 0x32bd70 | FDE: 0x1260e8 | Size: 136 bytes
// Khung tháo gỡ #1996 | Địa chỉ PC: 0x32bd70 | Địa chỉ FDE: 0x1260e8 | Kích thước: 136 bytes
//   0x32bd70: F8008408  str      x8, [x0], #8
//   0x32bd74: 17F8C4D2  b        #0x15d0bc
//   0x32bd78: F8008408  str      x8, [x0], #8
//   0x32bd7c: 17F8B781  b        #0x159b80
static inline uint64_t fde_func_1996_0x32bd70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32bd70ULL ^ (static_cast<uint64_t>(0xf8008408ULL) << 13);
    acc = (acc + a1 + 0x17f8c4d2ULL) ^ 0x1260e8ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1997 | PC: 0x32bdf8 | FDE: 0x1261d8 | Size: 192 bytes
// Khung tháo gỡ #1997 | Địa chỉ PC: 0x32bdf8 | Địa chỉ FDE: 0x1261d8 | Kích thước: 192 bytes
//   0x32bdf8: F9400008  ldr      x8, [x0]
//   0x32bdfc: F9408509  ldr      x9, [x8, #0x108]
//   0x32be00: 910023E8  add      x8, sp, #8
//   0x32be04: D61F0120  br       x9
static inline uint64_t fde_func_1997_0x32bdf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32bdf8ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9408509ULL) ^ 0x1261d8ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1998 | PC: 0x32beb8 | FDE: 0x1262c8 | Size: 128 bytes
// Khung tháo gỡ #1998 | Địa chỉ PC: 0x32beb8 | Địa chỉ FDE: 0x1262c8 | Kích thước: 128 bytes
//   0x32beb8: F9400008  ldr      x8, [x0]
//   0x32bebc: F940A108  ldr      x8, [x8, #0x140]
//   0x32bec0: D61F0100  br       x8
//   0x32bec4: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_1998_0x32beb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32beb8ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf940a108ULL) ^ 0x1262c8ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1999 | PC: 0x32bf38 | FDE: 0x1263b8 | Size: 256 bytes
// Khung tháo gỡ #1999 | Địa chỉ PC: 0x32bf38 | Địa chỉ FDE: 0x1263b8 | Kích thước: 256 bytes
//   0x32bf38: AA1503E1  mov      x1, x21
//   0x32bf3c: AA1403E3  mov      x3, x20
//   0x32bf40: D65F03C0  ret      
//   0x32bf44: AA0003F8  mov      x24, x0
static inline uint64_t fde_func_1999_0x32bf38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x32bf38ULL ^ (static_cast<uint64_t>(0xaa1503e1ULL) << 13);
    acc = (acc + a1 + 0xaa1403e3ULL) ^ 0x1263b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Shard 5 Dispatcher / Bộ điều phối phân mảnh 5
uint64_t execute_fde_shard_5(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 1600: return fde_func_1600_0x317a48(a0, a1);
        case 1601: return fde_func_1601_0x317e64(a0, a1);
        case 1602: return fde_func_1602_0x318108(a0, a1);
        case 1603: return fde_func_1603_0x318730(a0, a1);
        case 1604: return fde_func_1604_0x318cfc(a0, a1);
        case 1605: return fde_func_1605_0x318dfc(a0, a1);
        case 1606: return fde_func_1606_0x3197e4(a0, a1);
        case 1607: return fde_func_1607_0x31a2dc(a0, a1);
        case 1608: return fde_func_1608_0x31a6cc(a0, a1);
        case 1609: return fde_func_1609_0x31aa7c(a0, a1);
        case 1610: return fde_func_1610_0x31abf8(a0, a1);
        case 1611: return fde_func_1611_0x31ae08(a0, a1);
        case 1612: return fde_func_1612_0x31b114(a0, a1);
        case 1613: return fde_func_1613_0x31b19c(a0, a1);
        case 1614: return fde_func_1614_0x31bd40(a0, a1);
        case 1615: return fde_func_1615_0x31be24(a0, a1);
        case 1616: return fde_func_1616_0x31bedc(a0, a1);
        case 1617: return fde_func_1617_0x31bf9c(a0, a1);
        case 1618: return fde_func_1618_0x31c06c(a0, a1);
        case 1619: return fde_func_1619_0x31c128(a0, a1);
        case 1620: return fde_func_1620_0x31c1f4(a0, a1);
        case 1621: return fde_func_1621_0x31c2cc(a0, a1);
        case 1622: return fde_func_1622_0x31c37c(a0, a1);
        case 1623: return fde_func_1623_0x31c408(a0, a1);
        case 1624: return fde_func_1624_0x31c504(a0, a1);
        case 1625: return fde_func_1625_0x31c570(a0, a1);
        case 1626: return fde_func_1626_0x31c628(a0, a1);
        case 1627: return fde_func_1627_0x31c72c(a0, a1);
        case 1628: return fde_func_1628_0x31c7f4(a0, a1);
        case 1629: return fde_func_1629_0x31c868(a0, a1);
        case 1630: return fde_func_1630_0x31c900(a0, a1);
        case 1631: return fde_func_1631_0x31c9c4(a0, a1);
        case 1632: return fde_func_1632_0x31ca6c(a0, a1);
        case 1633: return fde_func_1633_0x31cb10(a0, a1);
        case 1634: return fde_func_1634_0x31cb8c(a0, a1);
        case 1635: return fde_func_1635_0x31cc30(a0, a1);
        case 1636: return fde_func_1636_0x31cd30(a0, a1);
        case 1637: return fde_func_1637_0x31cda0(a0, a1);
        case 1638: return fde_func_1638_0x31ce14(a0, a1);
        case 1639: return fde_func_1639_0x31cea8(a0, a1);
        case 1640: return fde_func_1640_0x31cf5c(a0, a1);
        case 1641: return fde_func_1641_0x31d02c(a0, a1);
        case 1642: return fde_func_1642_0x31d0e0(a0, a1);
        case 1643: return fde_func_1643_0x31d17c(a0, a1);
        case 1644: return fde_func_1644_0x31d20c(a0, a1);
        case 1645: return fde_func_1645_0x31d328(a0, a1);
        case 1646: return fde_func_1646_0x31d3c4(a0, a1);
        case 1647: return fde_func_1647_0x31d484(a0, a1);
        case 1648: return fde_func_1648_0x31d53c(a0, a1);
        case 1649: return fde_func_1649_0x31d5c4(a0, a1);
        case 1650: return fde_func_1650_0x31d678(a0, a1);
        case 1651: return fde_func_1651_0x31d720(a0, a1);
        case 1652: return fde_func_1652_0x31d7d0(a0, a1);
        case 1653: return fde_func_1653_0x31d84c(a0, a1);
        case 1654: return fde_func_1654_0x31d910(a0, a1);
        case 1655: return fde_func_1655_0x31d9b8(a0, a1);
        case 1656: return fde_func_1656_0x31da5c(a0, a1);
        case 1657: return fde_func_1657_0x31daf8(a0, a1);
        case 1658: return fde_func_1658_0x31db94(a0, a1);
        case 1659: return fde_func_1659_0x31dc9c(a0, a1);
        case 1660: return fde_func_1660_0x31dd54(a0, a1);
        case 1661: return fde_func_1661_0x31de20(a0, a1);
        case 1662: return fde_func_1662_0x31df00(a0, a1);
        case 1663: return fde_func_1663_0x31dfc0(a0, a1);
        case 1664: return fde_func_1664_0x31e024(a0, a1);
        case 1665: return fde_func_1665_0x31e0ec(a0, a1);
        case 1666: return fde_func_1666_0x31e1a0(a0, a1);
        case 1667: return fde_func_1667_0x31e258(a0, a1);
        case 1668: return fde_func_1668_0x31e2fc(a0, a1);
        case 1669: return fde_func_1669_0x31e368(a0, a1);
        case 1670: return fde_func_1670_0x31e3e8(a0, a1);
        case 1671: return fde_func_1671_0x31e494(a0, a1);
        case 1672: return fde_func_1672_0x31e57c(a0, a1);
        case 1673: return fde_func_1673_0x31e6ac(a0, a1);
        case 1674: return fde_func_1674_0x31e744(a0, a1);
        case 1675: return fde_func_1675_0x31e7fc(a0, a1);
        case 1676: return fde_func_1676_0x31e88c(a0, a1);
        case 1677: return fde_func_1677_0x31e910(a0, a1);
        case 1678: return fde_func_1678_0x31e9e4(a0, a1);
        case 1679: return fde_func_1679_0x31ea68(a0, a1);
        case 1680: return fde_func_1680_0x31eb28(a0, a1);
        case 1681: return fde_func_1681_0x31ebbc(a0, a1);
        case 1682: return fde_func_1682_0x31ec70(a0, a1);
        case 1683: return fde_func_1683_0x31ece0(a0, a1);
        case 1684: return fde_func_1684_0x31ed90(a0, a1);
        case 1685: return fde_func_1685_0x31ee98(a0, a1);
        case 1686: return fde_func_1686_0x31ef40(a0, a1);
        case 1687: return fde_func_1687_0x31efec(a0, a1);
        case 1688: return fde_func_1688_0x31f084(a0, a1);
        case 1689: return fde_func_1689_0x31f0fc(a0, a1);
        case 1690: return fde_func_1690_0x31f1d4(a0, a1);
        case 1691: return fde_func_1691_0x31f258(a0, a1);
        case 1692: return fde_func_1692_0x31f360(a0, a1);
        case 1693: return fde_func_1693_0x31f434(a0, a1);
        case 1694: return fde_func_1694_0x31f4f0(a0, a1);
        case 1695: return fde_func_1695_0x31f584(a0, a1);
        case 1696: return fde_func_1696_0x31f620(a0, a1);
        case 1697: return fde_func_1697_0x31f6d8(a0, a1);
        case 1698: return fde_func_1698_0x31f754(a0, a1);
        case 1699: return fde_func_1699_0x31f7fc(a0, a1);
        case 1700: return fde_func_1700_0x31f898(a0, a1);
        case 1701: return fde_func_1701_0x31f930(a0, a1);
        case 1702: return fde_func_1702_0x31f9f8(a0, a1);
        case 1703: return fde_func_1703_0x31fa78(a0, a1);
        case 1704: return fde_func_1704_0x31fb04(a0, a1);
        case 1705: return fde_func_1705_0x31fc28(a0, a1);
        case 1706: return fde_func_1706_0x31fd90(a0, a1);
        case 1707: return fde_func_1707_0x31fe30(a0, a1);
        case 1708: return fde_func_1708_0x31ff0c(a0, a1);
        case 1709: return fde_func_1709_0x31ffc8(a0, a1);
        case 1710: return fde_func_1710_0x320044(a0, a1);
        case 1711: return fde_func_1711_0x3200ac(a0, a1);
        case 1712: return fde_func_1712_0x32013c(a0, a1);
        case 1713: return fde_func_1713_0x3201d0(a0, a1);
        case 1714: return fde_func_1714_0x3202d0(a0, a1);
        case 1715: return fde_func_1715_0x320344(a0, a1);
        case 1716: return fde_func_1716_0x3203d8(a0, a1);
        case 1717: return fde_func_1717_0x3204a0(a0, a1);
        case 1718: return fde_func_1718_0x320560(a0, a1);
        case 1719: return fde_func_1719_0x3205f0(a0, a1);
        case 1720: return fde_func_1720_0x320690(a0, a1);
        case 1721: return fde_func_1721_0x32075c(a0, a1);
        case 1722: return fde_func_1722_0x320810(a0, a1);
        case 1723: return fde_func_1723_0x32089c(a0, a1);
        case 1724: return fde_func_1724_0x3209d8(a0, a1);
        case 1725: return fde_func_1725_0x320b24(a0, a1);
        case 1726: return fde_func_1726_0x320bb0(a0, a1);
        case 1727: return fde_func_1727_0x320c68(a0, a1);
        case 1728: return fde_func_1728_0x320d1c(a0, a1);
        case 1729: return fde_func_1729_0x320d74(a0, a1);
        case 1730: return fde_func_1730_0x320e30(a0, a1);
        case 1731: return fde_func_1731_0x320eec(a0, a1);
        case 1732: return fde_func_1732_0x320f84(a0, a1);
        case 1733: return fde_func_1733_0x321068(a0, a1);
        case 1734: return fde_func_1734_0x321144(a0, a1);
        case 1735: return fde_func_1735_0x3211fc(a0, a1);
        case 1736: return fde_func_1736_0x321284(a0, a1);
        case 1737: return fde_func_1737_0x321358(a0, a1);
        case 1738: return fde_func_1738_0x321428(a0, a1);
        case 1739: return fde_func_1739_0x321540(a0, a1);
        case 1740: return fde_func_1740_0x3215fc(a0, a1);
        case 1741: return fde_func_1741_0x3216f4(a0, a1);
        case 1742: return fde_func_1742_0x3217fc(a0, a1);
        case 1743: return fde_func_1743_0x3218c8(a0, a1);
        case 1744: return fde_func_1744_0x321998(a0, a1);
        case 1745: return fde_func_1745_0x321a18(a0, a1);
        case 1746: return fde_func_1746_0x321abc(a0, a1);
        case 1747: return fde_func_1747_0x321b38(a0, a1);
        case 1748: return fde_func_1748_0x321bd4(a0, a1);
        case 1749: return fde_func_1749_0x321c50(a0, a1);
        case 1750: return fde_func_1750_0x321d04(a0, a1);
        case 1751: return fde_func_1751_0x321dec(a0, a1);
        case 1752: return fde_func_1752_0x321ec4(a0, a1);
        case 1753: return fde_func_1753_0x321f90(a0, a1);
        case 1754: return fde_func_1754_0x321fec(a0, a1);
        case 1755: return fde_func_1755_0x322070(a0, a1);
        case 1756: return fde_func_1756_0x322130(a0, a1);
        case 1757: return fde_func_1757_0x3221b8(a0, a1);
        case 1758: return fde_func_1758_0x322280(a0, a1);
        case 1759: return fde_func_1759_0x322398(a0, a1);
        case 1760: return fde_func_1760_0x322464(a0, a1);
        case 1761: return fde_func_1761_0x32250c(a0, a1);
        case 1762: return fde_func_1762_0x3225c0(a0, a1);
        case 1763: return fde_func_1763_0x3226bc(a0, a1);
        case 1764: return fde_func_1764_0x32277c(a0, a1);
        case 1765: return fde_func_1765_0x322864(a0, a1);
        case 1766: return fde_func_1766_0x322908(a0, a1);
        case 1767: return fde_func_1767_0x322998(a0, a1);
        case 1768: return fde_func_1768_0x322a60(a0, a1);
        case 1769: return fde_func_1769_0x322af0(a0, a1);
        case 1770: return fde_func_1770_0x322bd0(a0, a1);
        case 1771: return fde_func_1771_0x322c94(a0, a1);
        case 1772: return fde_func_1772_0x322d40(a0, a1);
        case 1773: return fde_func_1773_0x322de0(a0, a1);
        case 1774: return fde_func_1774_0x322e94(a0, a1);
        case 1775: return fde_func_1775_0x322f34(a0, a1);
        case 1776: return fde_func_1776_0x322fd0(a0, a1);
        case 1777: return fde_func_1777_0x32305c(a0, a1);
        case 1778: return fde_func_1778_0x3230e0(a0, a1);
        case 1779: return fde_func_1779_0x323150(a0, a1);
        case 1780: return fde_func_1780_0x3231f0(a0, a1);
        case 1781: return fde_func_1781_0x32325c(a0, a1);
        case 1782: return fde_func_1782_0x323340(a0, a1);
        case 1783: return fde_func_1783_0x323410(a0, a1);
        case 1784: return fde_func_1784_0x32348c(a0, a1);
        case 1785: return fde_func_1785_0x323540(a0, a1);
        case 1786: return fde_func_1786_0x32361c(a0, a1);
        case 1787: return fde_func_1787_0x3236a4(a0, a1);
        case 1788: return fde_func_1788_0x323798(a0, a1);
        case 1789: return fde_func_1789_0x323804(a0, a1);
        case 1790: return fde_func_1790_0x323874(a0, a1);
        case 1791: return fde_func_1791_0x323904(a0, a1);
        case 1792: return fde_func_1792_0x32399c(a0, a1);
        case 1793: return fde_func_1793_0x323a4c(a0, a1);
        case 1794: return fde_func_1794_0x323b10(a0, a1);
        case 1795: return fde_func_1795_0x323bac(a0, a1);
        case 1796: return fde_func_1796_0x323c98(a0, a1);
        case 1797: return fde_func_1797_0x323d50(a0, a1);
        case 1798: return fde_func_1798_0x323de0(a0, a1);
        case 1799: return fde_func_1799_0x323e84(a0, a1);
        case 1800: return fde_func_1800_0x323f4c(a0, a1);
        case 1801: return fde_func_1801_0x324070(a0, a1);
        case 1802: return fde_func_1802_0x324118(a0, a1);
        case 1803: return fde_func_1803_0x3241d8(a0, a1);
        case 1804: return fde_func_1804_0x324264(a0, a1);
        case 1805: return fde_func_1805_0x3242e4(a0, a1);
        case 1806: return fde_func_1806_0x32434c(a0, a1);
        case 1807: return fde_func_1807_0x324420(a0, a1);
        case 1808: return fde_func_1808_0x324498(a0, a1);
        case 1809: return fde_func_1809_0x324540(a0, a1);
        case 1810: return fde_func_1810_0x32463c(a0, a1);
        case 1811: return fde_func_1811_0x324710(a0, a1);
        case 1812: return fde_func_1812_0x3247c8(a0, a1);
        case 1813: return fde_func_1813_0x324860(a0, a1);
        case 1814: return fde_func_1814_0x324924(a0, a1);
        case 1815: return fde_func_1815_0x3249ec(a0, a1);
        case 1816: return fde_func_1816_0x324aac(a0, a1);
        case 1817: return fde_func_1817_0x324b70(a0, a1);
        case 1818: return fde_func_1818_0x324be4(a0, a1);
        case 1819: return fde_func_1819_0x324c98(a0, a1);
        case 1820: return fde_func_1820_0x324d70(a0, a1);
        case 1821: return fde_func_1821_0x324e50(a0, a1);
        case 1822: return fde_func_1822_0x324f00(a0, a1);
        case 1823: return fde_func_1823_0x324fa0(a0, a1);
        case 1824: return fde_func_1824_0x325044(a0, a1);
        case 1825: return fde_func_1825_0x325128(a0, a1);
        case 1826: return fde_func_1826_0x3251a8(a0, a1);
        case 1827: return fde_func_1827_0x325208(a0, a1);
        case 1828: return fde_func_1828_0x3252c4(a0, a1);
        case 1829: return fde_func_1829_0x325330(a0, a1);
        case 1830: return fde_func_1830_0x3253fc(a0, a1);
        case 1831: return fde_func_1831_0x325494(a0, a1);
        case 1832: return fde_func_1832_0x32557c(a0, a1);
        case 1833: return fde_func_1833_0x325620(a0, a1);
        case 1834: return fde_func_1834_0x325698(a0, a1);
        case 1835: return fde_func_1835_0x32575c(a0, a1);
        case 1836: return fde_func_1836_0x325808(a0, a1);
        case 1837: return fde_func_1837_0x325884(a0, a1);
        case 1838: return fde_func_1838_0x325970(a0, a1);
        case 1839: return fde_func_1839_0x325a58(a0, a1);
        case 1840: return fde_func_1840_0x325b04(a0, a1);
        case 1841: return fde_func_1841_0x325b70(a0, a1);
        case 1842: return fde_func_1842_0x325c0c(a0, a1);
        case 1843: return fde_func_1843_0x325c70(a0, a1);
        case 1844: return fde_func_1844_0x325cdc(a0, a1);
        case 1845: return fde_func_1845_0x325d40(a0, a1);
        case 1846: return fde_func_1846_0x325db0(a0, a1);
        case 1847: return fde_func_1847_0x325e38(a0, a1);
        case 1848: return fde_func_1848_0x325f04(a0, a1);
        case 1849: return fde_func_1849_0x325f6c(a0, a1);
        case 1850: return fde_func_1850_0x32602c(a0, a1);
        case 1851: return fde_func_1851_0x3260bc(a0, a1);
        case 1852: return fde_func_1852_0x326144(a0, a1);
        case 1853: return fde_func_1853_0x3261e0(a0, a1);
        case 1854: return fde_func_1854_0x3262c8(a0, a1);
        case 1855: return fde_func_1855_0x3263ac(a0, a1);
        case 1856: return fde_func_1856_0x326458(a0, a1);
        case 1857: return fde_func_1857_0x326504(a0, a1);
        case 1858: return fde_func_1858_0x3265c0(a0, a1);
        case 1859: return fde_func_1859_0x32663c(a0, a1);
        case 1860: return fde_func_1860_0x3266b4(a0, a1);
        case 1861: return fde_func_1861_0x326734(a0, a1);
        case 1862: return fde_func_1862_0x3267c0(a0, a1);
        case 1863: return fde_func_1863_0x326844(a0, a1);
        case 1864: return fde_func_1864_0x32690c(a0, a1);
        case 1865: return fde_func_1865_0x3269c0(a0, a1);
        case 1866: return fde_func_1866_0x326a7c(a0, a1);
        case 1867: return fde_func_1867_0x326b5c(a0, a1);
        case 1868: return fde_func_1868_0x326c38(a0, a1);
        case 1869: return fde_func_1869_0x326cf0(a0, a1);
        case 1870: return fde_func_1870_0x326dbc(a0, a1);
        case 1871: return fde_func_1871_0x326e58(a0, a1);
        case 1872: return fde_func_1872_0x326ed0(a0, a1);
        case 1873: return fde_func_1873_0x326f60(a0, a1);
        case 1874: return fde_func_1874_0x326fc8(a0, a1);
        case 1875: return fde_func_1875_0x32704c(a0, a1);
        case 1876: return fde_func_1876_0x327148(a0, a1);
        case 1877: return fde_func_1877_0x32721c(a0, a1);
        case 1878: return fde_func_1878_0x327280(a0, a1);
        case 1879: return fde_func_1879_0x32733c(a0, a1);
        case 1880: return fde_func_1880_0x3273f0(a0, a1);
        case 1881: return fde_func_1881_0x32747c(a0, a1);
        case 1882: return fde_func_1882_0x327514(a0, a1);
        case 1883: return fde_func_1883_0x3275b8(a0, a1);
        case 1884: return fde_func_1884_0x327678(a0, a1);
        case 1885: return fde_func_1885_0x3276f8(a0, a1);
        case 1886: return fde_func_1886_0x327790(a0, a1);
        case 1887: return fde_func_1887_0x327858(a0, a1);
        case 1888: return fde_func_1888_0x3278ec(a0, a1);
        case 1889: return fde_func_1889_0x32794c(a0, a1);
        case 1890: return fde_func_1890_0x3279d8(a0, a1);
        case 1891: return fde_func_1891_0x327a8c(a0, a1);
        case 1892: return fde_func_1892_0x327b24(a0, a1);
        case 1893: return fde_func_1893_0x327ba8(a0, a1);
        case 1894: return fde_func_1894_0x327c30(a0, a1);
        case 1895: return fde_func_1895_0x327cb8(a0, a1);
        case 1896: return fde_func_1896_0x327d6c(a0, a1);
        case 1897: return fde_func_1897_0x327e10(a0, a1);
        case 1898: return fde_func_1898_0x327eb4(a0, a1);
        case 1899: return fde_func_1899_0x327f34(a0, a1);
        case 1900: return fde_func_1900_0x327fac(a0, a1);
        case 1901: return fde_func_1901_0x328060(a0, a1);
        case 1902: return fde_func_1902_0x3280fc(a0, a1);
        case 1903: return fde_func_1903_0x328178(a0, a1);
        case 1904: return fde_func_1904_0x328220(a0, a1);
        case 1905: return fde_func_1905_0x3282c0(a0, a1);
        case 1906: return fde_func_1906_0x328368(a0, a1);
        case 1907: return fde_func_1907_0x3283fc(a0, a1);
        case 1908: return fde_func_1908_0x328484(a0, a1);
        case 1909: return fde_func_1909_0x3284ec(a0, a1);
        case 1910: return fde_func_1910_0x328564(a0, a1);
        case 1911: return fde_func_1911_0x328608(a0, a1);
        case 1912: return fde_func_1912_0x3286c4(a0, a1);
        case 1913: return fde_func_1913_0x328734(a0, a1);
        case 1914: return fde_func_1914_0x3287ac(a0, a1);
        case 1915: return fde_func_1915_0x328814(a0, a1);
        case 1916: return fde_func_1916_0x3288b4(a0, a1);
        case 1917: return fde_func_1917_0x328968(a0, a1);
        case 1918: return fde_func_1918_0x328a64(a0, a1);
        case 1919: return fde_func_1919_0x328b48(a0, a1);
        case 1920: return fde_func_1920_0x328bf4(a0, a1);
        case 1921: return fde_func_1921_0x328cc0(a0, a1);
        case 1922: return fde_func_1922_0x328d80(a0, a1);
        case 1923: return fde_func_1923_0x328e68(a0, a1);
        case 1924: return fde_func_1924_0x328f2c(a0, a1);
        case 1925: return fde_func_1925_0x328fbc(a0, a1);
        case 1926: return fde_func_1926_0x329060(a0, a1);
        case 1927: return fde_func_1927_0x3290f0(a0, a1);
        case 1928: return fde_func_1928_0x329164(a0, a1);
        case 1929: return fde_func_1929_0x329218(a0, a1);
        case 1930: return fde_func_1930_0x329304(a0, a1);
        case 1931: return fde_func_1931_0x329388(a0, a1);
        case 1932: return fde_func_1932_0x329400(a0, a1);
        case 1933: return fde_func_1933_0x329470(a0, a1);
        case 1934: return fde_func_1934_0x329554(a0, a1);
        case 1935: return fde_func_1935_0x329618(a0, a1);
        case 1936: return fde_func_1936_0x3296f0(a0, a1);
        case 1937: return fde_func_1937_0x329798(a0, a1);
        case 1938: return fde_func_1938_0x32983c(a0, a1);
        case 1939: return fde_func_1939_0x3298d0(a0, a1);
        case 1940: return fde_func_1940_0x329960(a0, a1);
        case 1941: return fde_func_1941_0x329a88(a0, a1);
        case 1942: return fde_func_1942_0x329b48(a0, a1);
        case 1943: return fde_func_1943_0x329bbc(a0, a1);
        case 1944: return fde_func_1944_0x329c68(a0, a1);
        case 1945: return fde_func_1945_0x329d44(a0, a1);
        case 1946: return fde_func_1946_0x329e44(a0, a1);
        case 1947: return fde_func_1947_0x329efc(a0, a1);
        case 1948: return fde_func_1948_0x329f74(a0, a1);
        case 1949: return fde_func_1949_0x329ff0(a0, a1);
        case 1950: return fde_func_1950_0x32a058(a0, a1);
        case 1951: return fde_func_1951_0x32a0e4(a0, a1);
        case 1952: return fde_func_1952_0x32a168(a0, a1);
        case 1953: return fde_func_1953_0x32a220(a0, a1);
        case 1954: return fde_func_1954_0x32a290(a0, a1);
        case 1955: return fde_func_1955_0x32a31c(a0, a1);
        case 1956: return fde_func_1956_0x32a41c(a0, a1);
        case 1957: return fde_func_1957_0x32a4bc(a0, a1);
        case 1958: return fde_func_1958_0x32a57c(a0, a1);
        case 1959: return fde_func_1959_0x32a5f8(a0, a1);
        case 1960: return fde_func_1960_0x32a680(a0, a1);
        case 1961: return fde_func_1961_0x32a70c(a0, a1);
        case 1962: return fde_func_1962_0x32a7bc(a0, a1);
        case 1963: return fde_func_1963_0x32a860(a0, a1);
        case 1964: return fde_func_1964_0x32a914(a0, a1);
        case 1965: return fde_func_1965_0x32a9b8(a0, a1);
        case 1966: return fde_func_1966_0x32aa74(a0, a1);
        case 1967: return fde_func_1967_0x32ab1c(a0, a1);
        case 1968: return fde_func_1968_0x32abcc(a0, a1);
        case 1969: return fde_func_1969_0x32ac7c(a0, a1);
        case 1970: return fde_func_1970_0x32ad1c(a0, a1);
        case 1971: return fde_func_1971_0x32adc0(a0, a1);
        case 1972: return fde_func_1972_0x32ae44(a0, a1);
        case 1973: return fde_func_1973_0x32af0c(a0, a1);
        case 1974: return fde_func_1974_0x32af9c(a0, a1);
        case 1975: return fde_func_1975_0x32b048(a0, a1);
        case 1976: return fde_func_1976_0x32b0e4(a0, a1);
        case 1977: return fde_func_1977_0x32b1d0(a0, a1);
        case 1978: return fde_func_1978_0x32b258(a0, a1);
        case 1979: return fde_func_1979_0x32b314(a0, a1);
        case 1980: return fde_func_1980_0x32b39c(a0, a1);
        case 1981: return fde_func_1981_0x32b418(a0, a1);
        case 1982: return fde_func_1982_0x32b48c(a0, a1);
        case 1983: return fde_func_1983_0x32b51c(a0, a1);
        case 1984: return fde_func_1984_0x32b5c8(a0, a1);
        case 1985: return fde_func_1985_0x32b62c(a0, a1);
        case 1986: return fde_func_1986_0x32b6d8(a0, a1);
        case 1987: return fde_func_1987_0x32b784(a0, a1);
        case 1988: return fde_func_1988_0x32b820(a0, a1);
        case 1989: return fde_func_1989_0x32b8c8(a0, a1);
        case 1990: return fde_func_1990_0x32b998(a0, a1);
        case 1991: return fde_func_1991_0x32ba10(a0, a1);
        case 1992: return fde_func_1992_0x32babc(a0, a1);
        case 1993: return fde_func_1993_0x32bb88(a0, a1);
        case 1994: return fde_func_1994_0x32bc1c(a0, a1);
        case 1995: return fde_func_1995_0x32bccc(a0, a1);
        case 1996: return fde_func_1996_0x32bd70(a0, a1);
        case 1997: return fde_func_1997_0x32bdf8(a0, a1);
        case 1998: return fde_func_1998_0x32beb8(a0, a1);
        case 1999: return fde_func_1999_0x32bf38(a0, a1);
        default: return 0ULL;
    }
}

} // namespace lynx