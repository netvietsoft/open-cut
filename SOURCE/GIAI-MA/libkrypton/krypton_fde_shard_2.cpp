// ============================================================================
// Clean-Room C++17 AArch64 Function Shard 2/5 for libkrypton.so
// Phân mảnh Hàm AArch64 C++17 sạch 2/5 cho libkrypton.so
// Covers representative FDE indices [400 .. 799] out of 9,255 total FDEs
// Bao phủ chỉ số FDE đại diện [400 .. 799] trên tổng số 9.255 FDE
// ============================================================================
#include "krypton_core.h"

namespace lynx {
namespace canvas {

// FDE #0400 | PC: 0x0d95b0 | FDE: 0x073d60 | Size: 256 bytes [_ZN4lynx6canvas22CanvasResourceProvider26FlushCommandBufferInternalEbbl]
// Khung tháo gỡ #0400 | Địa chỉ PC: 0x0d95b0 | Địa chỉ FDE: 0x073d60 | Kích thước: 256 bytes
//   0x0d95b0: AA1E03E4  mov      x4, x30
//   0x0d95b4: 9402A112  bl       #0x1819fc
//   0x0d95b8: AA0403FE  mov      x30, x4
//   0x0d95bc: A91B7BFD  stp      x29, x30, [sp, #0x1b0]
static inline uint64_t fde_func_0400_0x0d95b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d95b0ULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x9402a112ULL) ^ 0x073d60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0401 | PC: 0x0d9910 | FDE: 0x073d90 | Size: 256 bytes [_ZN4lynx6canvas22CanvasResourceProvider26WaitForLastGPUTaskFinishedEv]
// Khung tháo gỡ #0401 | Địa chỉ PC: 0x0d9910 | Địa chỉ FDE: 0x073d90 | Kích thước: 256 bytes
//   0x0d9910: D106C3FF  sub      sp, sp, #0x1b0
//   0x0d9914: F900ABFC  str      x28, [sp, #0x150]
//   0x0d9918: A9166BFB  stp      x27, x26, [sp, #0x160]
//   0x0d991c: A91763F9  stp      x25, x24, [sp, #0x170]
static inline uint64_t fde_func_0401_0x0d9910(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9910ULL ^ (static_cast<uint64_t>(0xd106c3ffULL) << 13);
    acc = (acc + a1 + 0xf900abfcULL) ^ 0x073d90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0402 | PC: 0x0d9a44 | FDE: 0x073dc0 | Size: 240 bytes [_ZN4lynx6canvas22CanvasResourceProvider22CreateDoRasterCallbackEl]
// Khung tháo gỡ #0402 | Địa chỉ PC: 0x0d9a44 | Địa chỉ FDE: 0x073dc0 | Kích thước: 240 bytes
//   0x0d9a44: D100C3FF  sub      sp, sp, #0x30
//   0x0d9a48: F9000BF4  str      x20, [sp, #0x10]
//   0x0d9a4c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0d9a50: F9402809  ldr      x9, [x0, #0x50]
static inline uint64_t fde_func_0402_0x0d9a44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9a44ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x073dc0ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0403 | PC: 0x0d9b34 | FDE: 0x073df8 | Size: 252 bytes [_ZN4lynx6canvas22CanvasResourceProvider12SyncRunOnGPUENSt6__ndk18functionIFvRKNS2_10unique_ptrINS0_6RasterENS2_14default_deleteIS5_EEEEEEE]
// Khung tháo gỡ #0403 | Địa chỉ PC: 0x0d9b34 | Địa chỉ FDE: 0x073df8 | Kích thước: 252 bytes
//   0x0d9b34: D10243FF  sub      sp, sp, #0x90
//   0x0d9b38: A9065BF7  stp      x23, x22, [sp, #0x60]
//   0x0d9b3c: A90753F5  stp      x21, x20, [sp, #0x70]
//   0x0d9b40: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_0403_0x0d9b34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9b34ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9065bf7ULL) ^ 0x073df8ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0404 | PC: 0x0d9c30 | FDE: 0x073e38 | Size: 248 bytes [_ZN4lynx6canvas22CanvasResourceProvider26OnFirstFrameDoRasterFinishEv]
// Khung tháo gỡ #0404 | Địa chỉ PC: 0x0d9c30 | Địa chỉ FDE: 0x073e38 | Kích thước: 248 bytes
//   0x0d9c30: D105C3FF  sub      sp, sp, #0x170
//   0x0d9c34: F900A3FC  str      x28, [sp, #0x140]
//   0x0d9c38: A91553F5  stp      x21, x20, [sp, #0x150]
//   0x0d9c3c: A9167BF3  stp      x19, x30, [sp, #0x160]
static inline uint64_t fde_func_0404_0x0d9c30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9c30ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xf900a3fcULL) ^ 0x073e38ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0405 | PC: 0x0d9d28 | FDE: 0x073e58 | Size: 212 bytes [_ZN4lynx6canvas22CanvasResourceProvider16OnDoRasterFinishEll]
// Khung tháo gỡ #0405 | Địa chỉ PC: 0x0d9d28 | Địa chỉ FDE: 0x073e58 | Kích thước: 212 bytes
//   0x0d9d28: D10183FF  sub      sp, sp, #0x60
//   0x0d9d2c: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0d9d30: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x0d9d34: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0405_0x0d9d28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9d28ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9035bf7ULL) ^ 0x073e58ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0406 | PC: 0x0d9dfc | FDE: 0x073e78 | Size: 28 bytes
// Khung tháo gỡ #0406 | Địa chỉ PC: 0x0d9dfc | Địa chỉ FDE: 0x073e78 | Kích thước: 28 bytes
//   0x0d9dfc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0d9e00: AA0003F3  mov      x19, x0
//   0x0d9e04: 9100A000  add      x0, x0, #0x28
//   0x0d9e08: 9400009F  bl       #0xda084
static inline uint64_t fde_func_0406_0x0d9dfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9dfcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x073e78ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0407 | PC: 0x0d9e18 | FDE: 0x073e90 | Size: 256 bytes [_ZN4lynx6canvas22CanvasResourceProvider8RunOnGPUENSt6__ndk18functionIFvRKNS2_10unique_ptrINS0_6RasterENS2_14default_deleteIS5_EEEEEEE]
// Khung tháo gỡ #0407 | Địa chỉ PC: 0x0d9e18 | Địa chỉ FDE: 0x073e90 | Kích thước: 256 bytes
//   0x0d9e18: D10303FF  sub      sp, sp, #0xc0
//   0x0d9e1c: F9004BF6  str      x22, [sp, #0x90]
//   0x0d9e20: A90A53F5  stp      x21, x20, [sp, #0xa0]
//   0x0d9e24: A90B7BF3  stp      x19, x30, [sp, #0xb0]
static inline uint64_t fde_func_0407_0x0d9e18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9e18ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf9004bf6ULL) ^ 0x073e90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0408 | PC: 0x0d9f48 | FDE: 0x073ee0 | Size: 80 bytes
// Khung tháo gỡ #0408 | Địa chỉ PC: 0x0d9f48 | Địa chỉ FDE: 0x073ee0 | Kích thước: 80 bytes
//   0x0d9f48: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0d9f4c: 94027B7A  bl       #0x178d34
//   0x0d9f50: 97FF4752  bl       #0xabc98
//   0x0d9f54: F9400660  ldr      x0, [x19, #8]
static inline uint64_t fde_func_0408_0x0d9f48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9f48ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94027b7aULL) ^ 0x073ee0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0409 | PC: 0x0d9f98 | FDE: 0x073f40 | Size: 136 bytes
// Khung tháo gỡ #0409 | Địa chỉ PC: 0x0d9f98 | Địa chỉ FDE: 0x073f40 | Kích thước: 136 bytes
//   0x0d9f98: F9400408  ldr      x8, [x0, #8]
//   0x0d9f9c: B00005A9  adrp     x9, #0x18e000
//   0x0d9fa0: 912CE129  add      x9, x9, #0xb38
//   0x0d9fa4: F9000009  str      x9, [x0]
static inline uint64_t fde_func_0409_0x0d9f98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9f98ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xb00005a9ULL) ^ 0x073f40ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0410 | PC: 0x0da020 | FDE: 0x073fa0 | Size: 124 bytes
// Khung tháo gỡ #0410 | Địa chỉ PC: 0x0da020 | Địa chỉ FDE: 0x073fa0 | Kích thước: 124 bytes
//   0x0da020: F9400400  ldr      x0, [x0, #8]
//   0x0da024: 17FFFFB5  b        #0xd9ef8
//   0x0da028: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0da02c: 94027869  bl       #0x1781d0
static inline uint64_t fde_func_0410_0x0da020(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da020ULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0x17ffffb5ULL) ^ 0x073fa0ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0411 | PC: 0x0da09c | FDE: 0x074000 | Size: 88 bytes
// Khung tháo gỡ #0411 | Địa chỉ PC: 0x0da09c | Địa chỉ FDE: 0x074000 | Kích thước: 88 bytes
//   0x0da09c: 900005A8  adrp     x8, #0x18e000
//   0x0da0a0: 912EA108  add      x8, x8, #0xba8
//   0x0da0a4: F8020408  str      x8, [x0], #0x20
//   0x0da0a8: 17FF46FC  b        #0xabc98
static inline uint64_t fde_func_0411_0x0da09c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da09cULL ^ (static_cast<uint64_t>(0x900005a8ULL) << 13);
    acc = (acc + a1 + 0x912ea108ULL) ^ 0x074000ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0412 | PC: 0x0da0f4 | FDE: 0x074060 | Size: 120 bytes
// Khung tháo gỡ #0412 | Địa chỉ PC: 0x0da0f4 | Địa chỉ FDE: 0x074060 | Kích thước: 120 bytes
//   0x0da0f4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0da0f8: AA0003F3  mov      x19, x0
//   0x0da0fc: 97FFFFF8  bl       #0xda0dc
//   0x0da100: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0412_0x0da0f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da0f4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x074060ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0413 | PC: 0x0da16c | FDE: 0x0740c0 | Size: 256 bytes
// Khung tháo gỡ #0413 | Địa chỉ PC: 0x0da16c | Địa chỉ FDE: 0x0740c0 | Kích thước: 256 bytes
//   0x0da16c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0da170: 94027818  bl       #0x1781d0
//   0x0da174: 97FFFEA2  bl       #0xd9bfc
//   0x0da178: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0413_0x0da16c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da16cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94027818ULL) ^ 0x0740c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0414 | PC: 0x0da3f4 | FDE: 0x074140 | Size: 48 bytes
// Khung tháo gỡ #0414 | Địa chỉ PC: 0x0da3f4 | Địa chỉ FDE: 0x074140 | Kích thước: 48 bytes
//   0x0da3f4: 52800028  mov      w8, #1
//   0x0da3f8: 39002408  strb     w8, [x0, #9]
//   0x0da3fc: D65F03C0  ret      
//   0x0da400: 52800028  mov      w8, #1
static inline uint64_t fde_func_0414_0x0da3f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da3f4ULL ^ (static_cast<uint64_t>(0x52800028ULL) << 13);
    acc = (acc + a1 + 0x39002408ULL) ^ 0x074140ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0415 | PC: 0x0da424 | FDE: 0x0741a0 | Size: 256 bytes
// Khung tháo gỡ #0415 | Địa chỉ PC: 0x0da424 | Địa chỉ FDE: 0x0741a0 | Kích thước: 256 bytes
//   0x0da424: D102C3FF  sub      sp, sp, #0xb0
//   0x0da428: A9085BF7  stp      x23, x22, [sp, #0x80]
//   0x0da42c: A90953F5  stp      x21, x20, [sp, #0x90]
//   0x0da430: A90A7BF3  stp      x19, x30, [sp, #0xa0]
static inline uint64_t fde_func_0415_0x0da424(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da424ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9085bf7ULL) ^ 0x0741a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0416 | PC: 0x0da668 | FDE: 0x074220 | Size: 72 bytes
// Khung tháo gỡ #0416 | Địa chỉ PC: 0x0da668 | Địa chỉ FDE: 0x074220 | Kích thước: 72 bytes
//   0x0da668: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0da66c: 9402A52A  bl       #0x183b14
//   0x0da670: A8C17BF3  ldp      x19, x30, [sp], #0x10
//   0x0da674: 17FF43A8  b        #0xab514
static inline uint64_t fde_func_0416_0x0da668(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da668ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9402a52aULL) ^ 0x074220ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0417 | PC: 0x0da6b0 | FDE: 0x074280 | Size: 120 bytes
// Khung tháo gỡ #0417 | Địa chỉ PC: 0x0da6b0 | Địa chỉ FDE: 0x074280 | Kích thước: 120 bytes
//   0x0da6b0: B40001E0  cbz      x0, #0xda6ec
//   0x0da6b4: D10083FF  sub      sp, sp, #0x20
//   0x0da6b8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0da6bc: 9402B131  bl       #0x186b80
static inline uint64_t fde_func_0417_0x0da6b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da6b0ULL ^ (static_cast<uint64_t>(0xb40001e0ULL) << 13);
    acc = (acc + a1 + 0xd10083ffULL) ^ 0x074280ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0418 | PC: 0x0da728 | FDE: 0x0742e0 | Size: 156 bytes
// Khung tháo gỡ #0418 | Địa chỉ PC: 0x0da728 | Địa chỉ FDE: 0x0742e0 | Kích thước: 156 bytes
//   0x0da728: B4000300  cbz      x0, #0xda788
//   0x0da72c: D100C3FF  sub      sp, sp, #0x30
//   0x0da730: F9000BF4  str      x20, [sp, #0x10]
//   0x0da734: A9027BF3  stp      x19, x30, [sp, #0x20]
static inline uint64_t fde_func_0418_0x0da728(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da728ULL ^ (static_cast<uint64_t>(0xb4000300ULL) << 13);
    acc = (acc + a1 + 0xd100c3ffULL) ^ 0x0742e0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0419 | PC: 0x0da7c4 | FDE: 0x074348 | Size: 12 bytes [_ZN4lynx6canvas22CanvasResourceProvider14SetNeedPresentEv]
// Khung tháo gỡ #0419 | Địa chỉ PC: 0x0da7c4 | Địa chỉ FDE: 0x074348 | Kích thước: 12 bytes
//   0x0da7c4: 52800028  mov      w8, #1
//   0x0da7c8: 3903E408  strb     w8, [x0, #0xf9]
//   0x0da7cc: 1402B7CD  b        #0x188700
static inline uint64_t fde_func_0419_0x0da7c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da7c4ULL ^ (static_cast<uint64_t>(0x52800028ULL) << 13);
    acc = (acc + a1 + 0x3903e408ULL) ^ 0x074348ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0420 | PC: 0x0da7d0 | FDE: 0x074360 | Size: 192 bytes [_ZN4lynx6canvas22CanvasResourceProvider12RequestVSyncEv]
// Khung tháo gỡ #0420 | Địa chỉ PC: 0x0da7d0 | Địa chỉ FDE: 0x074360 | Kích thước: 192 bytes
//   0x0da7d0: D10083FF  sub      sp, sp, #0x20
//   0x0da7d4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0da7d8: 39420408  ldrb     w8, [x0, #0x81]
//   0x0da7dc: 340000E8  cbz      w8, #0xda7f8
static inline uint64_t fde_func_0420_0x0da7d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da7d0ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x074360ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #0421 | PC: 0x0da890 | FDE: 0x0743a8 | Size: 32 bytes
// Khung tháo gỡ #0421 | Địa chỉ PC: 0x0da890 | Địa chỉ FDE: 0x0743a8 | Kích thước: 32 bytes
//   0x0da890: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0da894: AA0003F3  mov      x19, x0
//   0x0da898: 97FFFFF6  bl       #0xda870
//   0x0da89c: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0421_0x0da890(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da890ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0743a8ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0422 | PC: 0x0da8b0 | FDE: 0x0743d8 | Size: 256 bytes [_ZN4lynx6canvas22CanvasResourceProviderD2Ev]
// Khung tháo gỡ #0422 | Địa chỉ PC: 0x0da8b0 | Địa chỉ FDE: 0x0743d8 | Kích thước: 256 bytes
//   0x0da8b0: AA1E03E1  mov      x1, x30
//   0x0da8b4: 94029CBE  bl       #0x181bac
//   0x0da8b8: AA0103FE  mov      x30, x1
//   0x0da8bc: A91A7BF3  stp      x19, x30, [sp, #0x1a0]
static inline uint64_t fde_func_0422_0x0da8b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da8b0ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x94029cbeULL) ^ 0x0743d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0423 | PC: 0x0dab9c | FDE: 0x074408 | Size: 16 bytes [_ZN4lynx6canvas22CanvasResourceProvider24SetGLStatisticsCollectorEPNS0_21GLStatisticsCollectorE]
// Khung tháo gỡ #0423 | Địa chỉ PC: 0x0dab9c | Địa chỉ FDE: 0x074408 | Kích thước: 16 bytes
//   0x0dab9c: F9007001  str      x1, [x0, #0xe0]
//   0x0daba0: F900AC01  str      x1, [x0, #0x158]
//   0x0daba4: F9010801  str      x1, [x0, #0x210]
//   0x0daba8: D65F03C0  ret      
static inline uint64_t fde_func_0423_0x0dab9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dab9cULL ^ (static_cast<uint64_t>(0xf9007001ULL) << 13);
    acc = (acc + a1 + 0xf900ac01ULL) ^ 0x074408ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0424 | PC: 0x0dabac | FDE: 0x074420 | Size: 180 bytes [_ZN4lynx6canvas22CanvasResourceProvider7DoFrameEl]
// Khung tháo gỡ #0424 | Địa chỉ PC: 0x0dabac | Địa chỉ FDE: 0x074420 | Kích thước: 180 bytes
//   0x0dabac: D10143FF  sub      sp, sp, #0x50
//   0x0dabb0: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x0dabb4: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x0dabb8: 94027EE1  bl       #0x17a73c
static inline uint64_t fde_func_0424_0x0dabac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dabacULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90353f5ULL) ^ 0x074420ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #0425 | PC: 0x0dac60 | FDE: 0x074440 | Size: 248 bytes [_ZN4lynx6canvas22CanvasResourceProvider5FlushEbbbl]
// Khung tháo gỡ #0425 | Địa chỉ PC: 0x0dac60 | Địa chỉ FDE: 0x074440 | Kích thước: 248 bytes
//   0x0dac60: AA1E03E5  mov      x5, x30
//   0x0dac64: 94028758  bl       #0x17c9c4
//   0x0dac68: AA0503FE  mov      x30, x5
//   0x0dac6c: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_0425_0x0dac60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dac60ULL ^ (static_cast<uint64_t>(0xaa1e03e5ULL) << 13);
    acc = (acc + a1 + 0x94028758ULL) ^ 0x074440ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0426 | PC: 0x0dad58 | FDE: 0x074468 | Size: 256 bytes [_ZN4lynx6canvas22CanvasResourceProvider23UpdateStatisticsOnFrameEv]
// Khung tháo gỡ #0426 | Địa chỉ PC: 0x0dad58 | Địa chỉ FDE: 0x074468 | Kích thước: 256 bytes
//   0x0dad58: D10103FF  sub      sp, sp, #0x40
//   0x0dad5c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0dad60: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x0dad64: D53BD055  mrs      x21, tpidr_el0
static inline uint64_t fde_func_0426_0x0dad58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dad58ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x074468ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0427 | PC: 0x0dae74 | FDE: 0x0744a0 | Size: 256 bytes [_ZN4lynx6canvas22CanvasResourceProvider13FPSStatistics13UpdateOnFrameEPKc]
// Khung tháo gỡ #0427 | Địa chỉ PC: 0x0dae74 | Địa chỉ FDE: 0x0744a0 | Kích thước: 256 bytes
//   0x0dae74: D10183FF  sub      sp, sp, #0x60
//   0x0dae78: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0dae7c: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x0dae80: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0427_0x0dae74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dae74ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9035bf7ULL) ^ 0x0744a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0428 | PC: 0x0dafec | FDE: 0x0744f0 | Size: 184 bytes [_ZN4lynx6canvas22CanvasResourceProvider15FrameStatistics13UpdateOnFrameEv]
// Khung tháo gỡ #0428 | Địa chỉ PC: 0x0dafec | Địa chỉ FDE: 0x0744f0 | Kích thước: 184 bytes
//   0x0dafec: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0daff0: 94028BBD  bl       #0x17dee4
//   0x0daff4: 91000508  add      x8, x8, #1
//   0x0daff8: F9000408  str      x8, [x0, #8]
static inline uint64_t fde_func_0428_0x0dafec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dafecULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94028bbdULL) ^ 0x0744f0ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0429 | PC: 0x0db0a4 | FDE: 0x074508 | Size: 244 bytes [_ZN4lynx6canvas22CanvasResourceProvider21TimeToInteractiveData13UpdateOnFrameEv]
// Khung tháo gỡ #0429 | Địa chỉ PC: 0x0db0a4 | Địa chỉ FDE: 0x074508 | Kích thước: 244 bytes
//   0x0db0a4: D10583FF  sub      sp, sp, #0x160
//   0x0db0a8: F9009BFC  str      x28, [sp, #0x130]
//   0x0db0ac: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0db0b0: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0429_0x0db0a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db0a4ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x074508ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #0430 | PC: 0x0db198 | FDE: 0x074528 | Size: 256 bytes [_ZN4lynx6canvas22CanvasResourceProvider18DrawCallStatistics13UpdateOnFrameEv]
// Khung tháo gỡ #0430 | Địa chỉ PC: 0x0db198 | Địa chỉ FDE: 0x074528 | Kích thước: 256 bytes
//   0x0db198: AA1E03E1  mov      x1, x30
//   0x0db19c: 94027328  bl       #0x177e3c
//   0x0db1a0: AA0103FE  mov      x30, x1
//   0x0db1a4: A90D7BFD  stp      x29, x30, [sp, #0xd0]
static inline uint64_t fde_func_0430_0x0db198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db198ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x94027328ULL) ^ 0x074528ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0431 | PC: 0x0db5d0 | FDE: 0x074588 | Size: 176 bytes
// Khung tháo gỡ #0431 | Địa chỉ PC: 0x0db5d0 | Địa chỉ FDE: 0x074588 | Kích thước: 176 bytes
//   0x0db5d0: D10183FF  sub      sp, sp, #0x60
//   0x0db5d4: F9001BF6  str      x22, [sp, #0x30]
//   0x0db5d8: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x0db5dc: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0431_0x0db5d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db5d0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf6ULL) ^ 0x074588ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #0432 | PC: 0x0db680 | FDE: 0x0745f0 | Size: 232 bytes [_ZN4lynx6canvas22CanvasResourceProvider21TimeToInteractiveData22CheckTimeToInteractiveEii]
// Khung tháo gỡ #0432 | Địa chỉ PC: 0x0db680 | Địa chỉ FDE: 0x0745f0 | Kích thước: 232 bytes
//   0x0db680: D10143FF  sub      sp, sp, #0x50
//   0x0db684: FD000BE8  str      d8, [sp, #0x10]
//   0x0db688: F9000FF8  str      x24, [sp, #0x18]
//   0x0db68c: A9025BF7  stp      x23, x22, [sp, #0x20]
static inline uint64_t fde_func_0432_0x0db680(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db680ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xfd000be8ULL) ^ 0x0745f0ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0433 | PC: 0x0db768 | FDE: 0x074618 | Size: 256 bytes [_ZN4lynx6canvas22CanvasResourceProvider21TimeToInteractiveData7DisableEv]
// Khung tháo gỡ #0433 | Địa chỉ PC: 0x0db768 | Địa chỉ FDE: 0x074618 | Kích thước: 256 bytes
//   0x0db768: D10583FF  sub      sp, sp, #0x160
//   0x0db76c: F9009BFC  str      x28, [sp, #0x130]
//   0x0db770: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0db774: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0433_0x0db768(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db768ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x074618ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0434 | PC: 0x0dbb50 | FDE: 0x074680 | Size: 176 bytes
// Khung tháo gỡ #0434 | Địa chỉ PC: 0x0dbb50 | Địa chỉ FDE: 0x074680 | Kích thước: 176 bytes
//   0x0dbb50: A9422408  ldp      x8, x9, [x0, #0x20]
//   0x0dbb54: A940AC0A  ldp      x10, x11, [x0, #8]
//   0x0dbb58: 8B090108  add      x8, x8, x9
//   0x0dbb5c: D347FD09  lsr      x9, x8, #7
static inline uint64_t fde_func_0434_0x0dbb50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dbb50ULL ^ (static_cast<uint64_t>(0xa9422408ULL) << 13);
    acc = (acc + a1 + 0xa940ac0aULL) ^ 0x074680ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #0435 | PC: 0x0dbc00 | FDE: 0x0746e0 | Size: 256 bytes [_ZN4lynx6canvas22CanvasResourceProvider21FlushIgnoreClientSideEbbbl]
// Khung tháo gỡ #0435 | Địa chỉ PC: 0x0dbc00 | Địa chỉ FDE: 0x0746e0 | Kích thước: 256 bytes
//   0x0dbc00: AA1E03E5  mov      x5, x30
//   0x0dbc04: 94027C8C  bl       #0x17ae34
//   0x0dbc08: AA0503FE  mov      x30, x5
//   0x0dbc0c: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0435_0x0dbc00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dbc00ULL ^ (static_cast<uint64_t>(0xaa1e03e5ULL) << 13);
    acc = (acc + a1 + 0x94027c8cULL) ^ 0x0746e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0436 | PC: 0x0dbf1c | FDE: 0x074760 | Size: 256 bytes
// Khung tháo gỡ #0436 | Địa chỉ PC: 0x0dbf1c | Địa chỉ FDE: 0x074760 | Kích thước: 256 bytes
//   0x0dbf1c: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x0dbf20: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0dbf24: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0dbf28: A940D414  ldp      x20, x21, [x0, #8]
static inline uint64_t fde_func_0436_0x0dbf1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dbf1cULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x074760ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0437 | PC: 0x0dc0a0 | FDE: 0x0747d0 | Size: 40 bytes
// Khung tháo gỡ #0437 | Địa chỉ PC: 0x0dc0a0 | Địa chỉ FDE: 0x0747d0 | Kích thước: 40 bytes
//   0x0dc0a0: AA1E03E2  mov      x2, x30
//   0x0dc0a4: 94026EF8  bl       #0x177c84
//   0x0dc0a8: AA0203FE  mov      x30, x2
//   0x0dc0ac: 17FFFF00  b        #0xdbcac
static inline uint64_t fde_func_0437_0x0dc0a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc0a0ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94026ef8ULL) ^ 0x0747d0ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0438 | PC: 0x0dc0c8 | FDE: 0x074800 | Size: 256 bytes [_ZN4lynx6canvas22CanvasResourceProvider4InitERKNS_3fml6RefPtrINS2_10TaskRunnerEEE]
// Khung tháo gỡ #0438 | Địa chỉ PC: 0x0dc0c8 | Địa chỉ FDE: 0x074800 | Kích thước: 256 bytes
//   0x0dc0c8: AA1E03E2  mov      x2, x30
//   0x0dc0cc: 94028469  bl       #0x17d270
//   0x0dc0d0: AA0203FE  mov      x30, x2
//   0x0dc0d4: A90F7BFD  stp      x29, x30, [sp, #0xf0]
static inline uint64_t fde_func_0438_0x0dc0c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc0c8ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94028469ULL) ^ 0x074800ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0439 | PC: 0x0dc698 | FDE: 0x074860 | Size: 80 bytes
// Khung tháo gỡ #0439 | Địa chỉ PC: 0x0dc698 | Địa chỉ FDE: 0x074860 | Kích thước: 80 bytes
//   0x0dc698: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0dc69c: 94026FCE  bl       #0x1785d4
//   0x0dc6a0: B40000D3  cbz      x19, #0xdc6b8
//   0x0dc6a4: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0439_0x0dc698(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc698ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94026fceULL) ^ 0x074860ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0440 | PC: 0x0dc6e8 | FDE: 0x0748a8 | Size: 160 bytes [_ZN4lynx6canvas22CanvasResourceProvider18FlushNewCanvasSizeEv]
// Khung tháo gỡ #0440 | Địa chỉ PC: 0x0dc6e8 | Địa chỉ FDE: 0x0748a8 | Kích thước: 160 bytes
//   0x0dc6e8: D101C3FF  sub      sp, sp, #0x70
//   0x0dc6ec: F9002BF4  str      x20, [sp, #0x50]
//   0x0dc6f0: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x0dc6f4: 9402A85E  bl       #0x18686c
static inline uint64_t fde_func_0440_0x0dc6e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc6e8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x0748a8ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0441 | PC: 0x0dc788 | FDE: 0x0748c8 | Size: 200 bytes
// Khung tháo gỡ #0441 | Địa chỉ PC: 0x0dc788 | Địa chỉ FDE: 0x0748c8 | Kích thước: 200 bytes
//   0x0dc788: F9400808  ldr      x8, [x0, #0x10]
//   0x0dc78c: D0000589  adrp     x9, #0x18e000
//   0x0dc790: 91366129  add      x9, x9, #0xd98
//   0x0dc794: F9000009  str      x9, [x0]
static inline uint64_t fde_func_0441_0x0dc788(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc788ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xd0000589ULL) ^ 0x0748c8ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0442 | PC: 0x0dc850 | FDE: 0x074930 | Size: 108 bytes
// Khung tháo gỡ #0442 | Địa chỉ PC: 0x0dc850 | Địa chỉ FDE: 0x074930 | Kích thước: 108 bytes
//   0x0dc850: D0000588  adrp     x8, #0x18e000
//   0x0dc854: 91370108  add      x8, x8, #0xdc0
//   0x0dc858: 14026D21  b        #0x177cdc
//   0x0dc85c: F9400028  ldr      x8, [x1]
static inline uint64_t fde_func_0442_0x0dc850(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc850ULL ^ (static_cast<uint64_t>(0xd0000588ULL) << 13);
    acc = (acc + a1 + 0x91370108ULL) ^ 0x074930ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0443 | PC: 0x0dc8bc | FDE: 0x074990 | Size: 120 bytes
// Khung tháo gỡ #0443 | Địa chỉ PC: 0x0dc8bc | Địa chỉ FDE: 0x074990 | Kích thước: 120 bytes
//   0x0dc8bc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0dc8c0: AA0003F3  mov      x19, x0
//   0x0dc8c4: 97FF56BF  bl       #0xb23c0
//   0x0dc8c8: D0000588  adrp     x8, #0x18e000
static inline uint64_t fde_func_0443_0x0dc8bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc8bcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x074990ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0444 | PC: 0x0dc934 | FDE: 0x0749f0 | Size: 80 bytes
// Khung tháo gỡ #0444 | Địa chỉ PC: 0x0dc934 | Địa chỉ FDE: 0x0749f0 | Kích thước: 80 bytes
//   0x0dc934: F9400408  ldr      x8, [x0, #8]
//   0x0dc938: F9400508  ldr      x8, [x8, #8]
//   0x0dc93c: F9403D00  ldr      x0, [x8, #0x78]
//   0x0dc940: 14028548  b        #0x17de60
static inline uint64_t fde_func_0444_0x0dc934(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc934ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf9400508ULL) ^ 0x0749f0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0445 | PC: 0x0dc984 | FDE: 0x074a50 | Size: 36 bytes
// Khung tháo gỡ #0445 | Địa chỉ PC: 0x0dc984 | Địa chỉ FDE: 0x074a50 | Kích thước: 36 bytes
//   0x0dc984: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0dc988: 9402A8AF  bl       #0x186c44
//   0x0dc98c: F9400A60  ldr      x0, [x19, #0x10]
//   0x0dc990: F9000A7F  str      xzr, [x19, #0x10]
static inline uint64_t fde_func_0445_0x0dc984(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc984ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9402a8afULL) ^ 0x074a50ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0446 | PC: 0x0dc9a8 | FDE: 0x074a68 | Size: 16 bytes [_ZNK4lynx6canvas22CanvasResourceProvider14GetCanvasWidthEv]
// Khung tháo gỡ #0446 | Địa chỉ PC: 0x0dc9a8 | Địa chỉ FDE: 0x074a68 | Kích thước: 16 bytes
//   0x0dc9a8: F9402800  ldr      x0, [x0, #0x50]
//   0x0dc9ac: B4000040  cbz      x0, #0xdc9b4
//   0x0dc9b0: 1402916E  b        #0x180f68
//   0x0dc9b4: D65F03C0  ret      
static inline uint64_t fde_func_0446_0x0dc9a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc9a8ULL ^ (static_cast<uint64_t>(0xf9402800ULL) << 13);
    acc = (acc + a1 + 0xb4000040ULL) ^ 0x074a68ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0447 | PC: 0x0dc9b8 | FDE: 0x074a80 | Size: 16 bytes [_ZNK4lynx6canvas22CanvasResourceProvider15GetCanvasHeightEv]
// Khung tháo gỡ #0447 | Địa chỉ PC: 0x0dc9b8 | Địa chỉ FDE: 0x074a80 | Kích thước: 16 bytes
//   0x0dc9b8: F9402800  ldr      x0, [x0, #0x50]
//   0x0dc9bc: B4000040  cbz      x0, #0xdc9c4
//   0x0dc9c0: 1402A7CA  b        #0x1868e8
//   0x0dc9c4: D65F03C0  ret      
static inline uint64_t fde_func_0447_0x0dc9b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc9b8ULL ^ (static_cast<uint64_t>(0xf9402800ULL) << 13);
    acc = (acc + a1 + 0xb4000040ULL) ^ 0x074a80ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0448 | PC: 0x0dc9c8 | FDE: 0x074a98 | Size: 16 bytes [_ZN4lynx6canvas22CanvasResourceProvider13SetNeedRedrawEv]
// Khung tháo gỡ #0448 | Địa chỉ PC: 0x0dc9c8 | Địa chỉ FDE: 0x074a98 | Kích thước: 16 bytes
//   0x0dc9c8: 52800028  mov      w8, #1
//   0x0dc9cc: 3903E008  strb     w8, [x0, #0xf8]
//   0x0dc9d0: 3903E808  strb     w8, [x0, #0xfa]
//   0x0dc9d4: 1402AF47  b        #0x1886f0
static inline uint64_t fde_func_0448_0x0dc9c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc9c8ULL ^ (static_cast<uint64_t>(0x52800028ULL) << 13);
    acc = (acc + a1 + 0x3903e008ULL) ^ 0x074a98ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0449 | PC: 0x0dc9d8 | FDE: 0x074ab0 | Size: 8 bytes [_ZN4lynx6canvas22CanvasResourceProvider16SetCanvasElementEPNS0_13CanvasElementE]
// Khung tháo gỡ #0449 | Địa chỉ PC: 0x0dc9d8 | Địa chỉ FDE: 0x074ab0 | Kích thước: 8 bytes
//   0x0dc9d8: F9002801  str      x1, [x0, #0x50]
//   0x0dc9dc: D65F03C0  ret      
static inline uint64_t fde_func_0449_0x0dc9d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc9d8ULL ^ (static_cast<uint64_t>(0xf9002801ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x074ab0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0450 | PC: 0x0dc9e0 | FDE: 0x074ac8 | Size: 40 bytes [_ZN4lynx6canvas22CanvasResourceProvider6OnShowEv]
// Khung tháo gỡ #0450 | Địa chỉ PC: 0x0dc9e0 | Địa chỉ FDE: 0x074ac8 | Kích thước: 40 bytes
//   0x0dc9e0: 39420408  ldrb     w8, [x0, #0x81]
//   0x0dc9e4: 34000048  cbz      w8, #0xdc9ec
//   0x0dc9e8: D65F03C0  ret      
//   0x0dc9ec: 52800028  mov      w8, #1
static inline uint64_t fde_func_0450_0x0dc9e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc9e0ULL ^ (static_cast<uint64_t>(0x39420408ULL) << 13);
    acc = (acc + a1 + 0x34000048ULL) ^ 0x074ac8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0451 | PC: 0x0dca08 | FDE: 0x074ae0 | Size: 12 bytes [_ZN4lynx6canvas22CanvasResourceProvider13FPSStatistics5ResetEv]
// Khung tháo gỡ #0451 | Địa chỉ PC: 0x0dca08 | Địa chỉ FDE: 0x074ae0 | Kích thước: 12 bytes
//   0x0dca08: A9007C1F  stp      xzr, xzr, [x0]
//   0x0dca0c: B900101F  str      wzr, [x0, #0x10]
//   0x0dca10: D65F03C0  ret      
static inline uint64_t fde_func_0451_0x0dca08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dca08ULL ^ (static_cast<uint64_t>(0xa9007c1fULL) << 13);
    acc = (acc + a1 + 0xb900101fULL) ^ 0x074ae0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0452 | PC: 0x0dca14 | FDE: 0x074af8 | Size: 24 bytes [_ZN4lynx6canvas22CanvasResourceProvider6OnHideEv]
// Khung tháo gỡ #0452 | Địa chỉ PC: 0x0dca14 | Địa chỉ FDE: 0x074af8 | Kích thước: 24 bytes
//   0x0dca14: 91086008  add      x8, x0, #0x218
//   0x0dca18: 6F00E400  movi     v0.2d, #0000000000000000
//   0x0dca1c: 3902041F  strb     wzr, [x0, #0x81]
//   0x0dca20: B902281F  str      wzr, [x0, #0x228]
static inline uint64_t fde_func_0452_0x0dca14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dca14ULL ^ (static_cast<uint64_t>(0x91086008ULL) << 13);
    acc = (acc + a1 + 0x6f00e400ULL) ^ 0x074af8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0453 | PC: 0x0dca2c | FDE: 0x074b10 | Size: 60 bytes [_ZN4lynx6canvas22CanvasResourceProvider19OnCanvasSizeChangedEv]
// Khung tháo gỡ #0453 | Địa chỉ PC: 0x0dca2c | Địa chỉ FDE: 0x074b10 | Kích thước: 60 bytes
//   0x0dca2c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0dca30: 52800023  mov      w3, #1
//   0x0dca34: 2A1F03E1  mov      w1, wzr
//   0x0dca38: 2A1F03E2  mov      w2, wzr
static inline uint64_t fde_func_0453_0x0dca2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dca2cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x52800023ULL) ^ 0x074b10ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0454 | PC: 0x0dca68 | FDE: 0x074b28 | Size: 256 bytes [_ZN4lynx6canvas22CanvasResourceProvider22AttachToOnscreenCanvasEv]
// Khung tháo gỡ #0454 | Địa chỉ PC: 0x0dca68 | Địa chỉ FDE: 0x074b28 | Kích thước: 256 bytes
//   0x0dca68: D102C3FF  sub      sp, sp, #0xb0
//   0x0dca6c: F90043F6  str      x22, [sp, #0x80]
//   0x0dca70: A90953F5  stp      x21, x20, [sp, #0x90]
//   0x0dca74: A90A7BF3  stp      x19, x30, [sp, #0xa0]
static inline uint64_t fde_func_0454_0x0dca68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dca68ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90043f6ULL) ^ 0x074b28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0455 | PC: 0x0dcb90 | FDE: 0x074b78 | Size: 120 bytes
// Khung tháo gỡ #0455 | Địa chỉ PC: 0x0dcb90 | Địa chỉ FDE: 0x074b78 | Kích thước: 120 bytes
//   0x0dcb90: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0dcb94: AA0003F3  mov      x19, x0
//   0x0dcb98: 97FFFFF8  bl       #0xdcb78
//   0x0dcb9c: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0455_0x0dcb90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dcb90ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x074b78ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0456 | PC: 0x0dcc08 | FDE: 0x074bd8 | Size: 76 bytes
// Khung tháo gỡ #0456 | Địa chỉ PC: 0x0dcc08 | Địa chỉ FDE: 0x074bd8 | Kích thước: 76 bytes
//   0x0dcc08: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0dcc0c: 94026D71  bl       #0x1781d0
//   0x0dcc10: 97FFFFCD  bl       #0xdcb44
//   0x0dcc14: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0456_0x0dcc08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dcc08ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94026d71ULL) ^ 0x074bd8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0457 | PC: 0x0dcc54 | FDE: 0x074c10 | Size: 128 bytes [_ZN4lynx6canvas22CanvasResourceProvider20UpdateRasterPriorityEi]
// Khung tháo gỡ #0457 | Địa chỉ PC: 0x0dcc54 | Địa chỉ FDE: 0x074c10 | Kích thước: 128 bytes
//   0x0dcc54: D10183FF  sub      sp, sp, #0x60
//   0x0dcc58: F90023F4  str      x20, [sp, #0x40]
//   0x0dcc5c: A9057BF3  stp      x19, x30, [sp, #0x50]
//   0x0dcc60: 9402654E  bl       #0x176198
static inline uint64_t fde_func_0457_0x0dcc54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dcc54ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90023f4ULL) ^ 0x074c10ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0458 | PC: 0x0dccd4 | FDE: 0x074c48 | Size: 156 bytes
// Khung tháo gỡ #0458 | Địa chỉ PC: 0x0dccd4 | Địa chỉ FDE: 0x074c48 | Kích thước: 156 bytes
//   0x0dccd4: D0000588  adrp     x8, #0x18e000
//   0x0dccd8: 913A2108  add      x8, x8, #0xe88
//   0x0dccdc: 140265D5  b        #0x176430
//   0x0dcce0: D10103FF  sub      sp, sp, #0x40
static inline uint64_t fde_func_0458_0x0dccd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dccd4ULL ^ (static_cast<uint64_t>(0xd0000588ULL) << 13);
    acc = (acc + a1 + 0x913a2108ULL) ^ 0x074c48ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0459 | PC: 0x0dcd70 | FDE: 0x074c80 | Size: 88 bytes [_ZN4lynx6canvas22CanvasResourceProvider24DetachFromOnscreenCanvasEv]
// Khung tháo gỡ #0459 | Địa chỉ PC: 0x0dcd70 | Địa chỉ FDE: 0x074c80 | Kích thước: 88 bytes
//   0x0dcd70: D10143FF  sub      sp, sp, #0x50
//   0x0dcd74: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x0dcd78: 940266E7  bl       #0x176914
//   0x0dcd7c: D0000589  adrp     x9, #0x18e000
static inline uint64_t fde_func_0459_0x0dcd70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dcd70ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9047bf3ULL) ^ 0x074c80ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0460 | PC: 0x0dcdc8 | FDE: 0x074cb0 | Size: 28 bytes
// Khung tháo gỡ #0460 | Địa chỉ PC: 0x0dcdc8 | Địa chỉ FDE: 0x074cb0 | Kích thước: 28 bytes
//   0x0dcdc8: D0000588  adrp     x8, #0x18e000
//   0x0dcdcc: 913B4108  add      x8, x8, #0xed0
//   0x0dcdd0: 140278D0  b        #0x17b110
//   0x0dcdd4: F9400028  ldr      x8, [x1]
static inline uint64_t fde_func_0460_0x0dcdc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dcdc8ULL ^ (static_cast<uint64_t>(0xd0000588ULL) << 13);
    acc = (acc + a1 + 0x913b4108ULL) ^ 0x074cb0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0461 | PC: 0x0dcde4 | FDE: 0x074ce0 | Size: 12 bytes [_ZNK4lynx6canvas22CanvasResourceProvider11reading_fboEv]
// Khung tháo gỡ #0461 | Địa chỉ PC: 0x0dcde4 | Địa chỉ FDE: 0x074ce0 | Kích thước: 12 bytes
//   0x0dcde4: F9403C08  ldr      x8, [x0, #0x78]
//   0x0dcde8: 91018108  add      x8, x8, #0x60
//   0x0dcdec: 14029EF3  b        #0x1849b8
static inline uint64_t fde_func_0461_0x0dcde4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dcde4ULL ^ (static_cast<uint64_t>(0xf9403c08ULL) << 13);
    acc = (acc + a1 + 0x91018108ULL) ^ 0x074ce0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0462 | PC: 0x0dcdf0 | FDE: 0x074cf8 | Size: 12 bytes [_ZNK4lynx6canvas22CanvasResourceProvider11drawing_fboEv]
// Khung tháo gỡ #0462 | Địa chỉ PC: 0x0dcdf0 | Địa chỉ FDE: 0x074cf8 | Kích thước: 12 bytes
//   0x0dcdf0: F9403C08  ldr      x8, [x0, #0x78]
//   0x0dcdf4: 91019108  add      x8, x8, #0x64
//   0x0dcdf8: 14029EF0  b        #0x1849b8
static inline uint64_t fde_func_0462_0x0dcdf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dcdf0ULL ^ (static_cast<uint64_t>(0xf9403c08ULL) << 13);
    acc = (acc + a1 + 0x91019108ULL) ^ 0x074cf8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0463 | PC: 0x0dcdfc | FDE: 0x074d10 | Size: 76 bytes [_ZNK4lynx6canvas22CanvasResourceProvider17IsCanvasOffscreenEv]
// Khung tháo gỡ #0463 | Địa chỉ PC: 0x0dcdfc | Địa chỉ FDE: 0x074d10 | Kích thước: 76 bytes
//   0x0dcdfc: D10103FF  sub      sp, sp, #0x40
//   0x0dce00: F90013F4  str      x20, [sp, #0x20]
//   0x0dce04: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x0dce08: 94027670  bl       #0x17a7c8
static inline uint64_t fde_func_0463_0x0dcdfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dcdfcULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f4ULL) ^ 0x074d10ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0464 | PC: 0x0dce48 | FDE: 0x074d30 | Size: 52 bytes [_ZN4lynx6canvas22CanvasResourceProvider22GetFrameStatisticsDataEb]
// Khung tháo gỡ #0464 | Địa chỉ PC: 0x0dce48 | Địa chỉ FDE: 0x074d30 | Kích thước: 52 bytes
//   0x0dce48: F9408409  ldr      x9, [x0, #0x108]
//   0x0dce4c: F9000109  str      x9, [x8]
//   0x0dce50: A952A40A  ldp      x10, x9, [x0, #0x128]
//   0x0dce54: CB0A012A  sub      x10, x9, x10
static inline uint64_t fde_func_0464_0x0dce48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dce48ULL ^ (static_cast<uint64_t>(0xf9408409ULL) << 13);
    acc = (acc + a1 + 0xf9000109ULL) ^ 0x074d30ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0465 | PC: 0x0dce7c | FDE: 0x074d48 | Size: 20 bytes [_ZN4lynx6canvas22CanvasResourceProvider15FrameStatistics15ResetStatisticsEv]
// Khung tháo gỡ #0465 | Địa chỉ PC: 0x0dce7c | Địa chỉ FDE: 0x074d48 | Kích thước: 20 bytes
//   0x0dce7c: F9401808  ldr      x8, [x0, #0x30]
//   0x0dce80: A900FC1F  stp      xzr, xzr, [x0, #8]
//   0x0dce84: F9000C1F  str      xzr, [x0, #0x18]
//   0x0dce88: F9001408  str      x8, [x0, #0x28]
static inline uint64_t fde_func_0465_0x0dce7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dce7cULL ^ (static_cast<uint64_t>(0xf9401808ULL) << 13);
    acc = (acc + a1 + 0xa900fc1fULL) ^ 0x074d48ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0466 | PC: 0x0dce90 | FDE: 0x074d60 | Size: 80 bytes [_ZN4lynx6canvas22CanvasResourceProvider24SetEnableFrameStatisticsEb]
// Khung tháo gỡ #0466 | Địa chỉ PC: 0x0dce90 | Địa chỉ FDE: 0x074d60 | Kích thước: 80 bytes
//   0x0dce90: 39440009  ldrb     w9, [x0, #0x100]
//   0x0dce94: 12000028  and      w8, w1, #1
//   0x0dce98: 6B08013F  cmp      w9, w8
//   0x0dce9c: 54000200  b.eq     #0xdcedc
static inline uint64_t fde_func_0466_0x0dce90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dce90ULL ^ (static_cast<uint64_t>(0x39440009ULL) << 13);
    acc = (acc + a1 + 0x12000028ULL) ^ 0x074d60ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0467 | PC: 0x0dcee0 | FDE: 0x074d78 | Size: 48 bytes [_ZN4lynx6canvas22CanvasResourceProvider15FrameStatistics21ResetAllExceptEnabledEv]
// Khung tháo gỡ #0467 | Địa chỉ PC: 0x0dcee0 | Địa chỉ FDE: 0x074d78 | Kích thước: 48 bytes
//   0x0dcee0: 6F00E400  movi     v0.2d, #0000000000000000
//   0x0dcee4: F0FFFA68  adrp     x8, #0x2b000
//   0x0dcee8: 3C828000  stur     q0, [x0, #0x28]
//   0x0dceec: 3C818000  stur     q0, [x0, #0x18]
static inline uint64_t fde_func_0467_0x0dcee0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dcee0ULL ^ (static_cast<uint64_t>(0x6f00e400ULL) << 13);
    acc = (acc + a1 + 0xf0fffa68ULL) ^ 0x074d78ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0468 | PC: 0x0dcf10 | FDE: 0x074d90 | Size: 60 bytes [_ZN4lynx6canvas22CanvasResourceProvider27ResetAllFrameStatisticsDataEv]
// Khung tháo gỡ #0468 | Địa chỉ PC: 0x0dcf10 | Địa chỉ FDE: 0x074d90 | Kích thước: 60 bytes
//   0x0dcf10: 91042009  add      x9, x0, #0x108
//   0x0dcf14: 9104A00A  add      x10, x0, #0x128
//   0x0dcf18: 6F00E400  movi     v0.2d, #0000000000000000
//   0x0dcf1c: 9104600B  add      x11, x0, #0x118
static inline uint64_t fde_func_0468_0x0dcf10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dcf10ULL ^ (static_cast<uint64_t>(0x91042009ULL) << 13);
    acc = (acc + a1 + 0x9104a00aULL) ^ 0x074d90ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0469 | PC: 0x0dcf4c | FDE: 0x074da8 | Size: 8 bytes [_ZN4lynx6canvas22CanvasResourceProvider21TimeToInteractiveData24SetGLStatisticsCollectorEPNS0_21GLStatisticsCollectorE]
// Khung tháo gỡ #0469 | Địa chỉ PC: 0x0dcf4c | Địa chỉ FDE: 0x074da8 | Kích thước: 8 bytes
//   0x0dcf4c: F9000001  str      x1, [x0]
//   0x0dcf50: D65F03C0  ret      
static inline uint64_t fde_func_0469_0x0dcf4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dcf4cULL ^ (static_cast<uint64_t>(0xf9000001ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x074da8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0470 | PC: 0x0dcf54 | FDE: 0x074dc0 | Size: 84 bytes [_ZN4lynx6canvas22CanvasResourceProvider28SetTimeToInteractiveCallbackENS_4base15MoveOnlyClosureIvJfEEE]
// Khung tháo gỡ #0470 | Địa chỉ PC: 0x0dcf54 | Địa chỉ FDE: 0x074dc0 | Kích thước: 84 bytes
//   0x0dcf54: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0dcf58: F9400028  ldr      x8, [x1]
//   0x0dcf5c: B40001C8  cbz      x8, #0xdcf94
//   0x0dcf60: F9407009  ldr      x9, [x0, #0xe0]
static inline uint64_t fde_func_0470_0x0dcf54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dcf54ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400028ULL) ^ 0x074dc0ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0471 | PC: 0x0dcfa8 | FDE: 0x074dd8 | Size: 180 bytes [_ZN4lynx6canvas22CanvasResourceProvider21TimeToInteractiveData18EnableWithCallbackENS_4base15MoveOnlyClosureIvJfEEE]
// Khung tháo gỡ #0471 | Địa chỉ PC: 0x0dcfa8 | Địa chỉ FDE: 0x074dd8 | Kích thước: 180 bytes
//   0x0dcfa8: D10583FF  sub      sp, sp, #0x160
//   0x0dcfac: A9135BFC  stp      x28, x22, [sp, #0x130]
//   0x0dcfb0: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0dcfb4: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0471_0x0dcfa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dcfa8ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa9135bfcULL) ^ 0x074dd8ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #0472 | PC: 0x0dd05c | FDE: 0x074e20 | Size: 48 bytes [_ZN4lynx6canvas22CanvasResourceProvider21TimeToInteractiveDataC2Ev]
// Khung tháo gỡ #0472 | Địa chỉ PC: 0x0dd05c | Địa chỉ FDE: 0x074e20 | Kích thước: 48 bytes
//   0x0dd05c: 6F00E400  movi     v0.2d, #0000000000000000
//   0x0dd060: F900001F  str      xzr, [x0]
//   0x0dd064: 3900201F  strb     wzr, [x0, #8]
//   0x0dd068: F800C01F  stur     xzr, [x0, #0xc]
static inline uint64_t fde_func_0472_0x0dd05c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd05cULL ^ (static_cast<uint64_t>(0x6f00e400ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x074e20ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0473 | PC: 0x0dd08c | FDE: 0x074e38 | Size: 48 bytes [_ZN4lynx6canvas22CanvasResourceProvider27SetEnableDrawCallStatisticsEb]
// Khung tháo gỡ #0473 | Địa chỉ PC: 0x0dd08c | Địa chỉ FDE: 0x074e38 | Kích thước: 48 bytes
//   0x0dd08c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0dd090: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0dd094: 39476008  ldrb     w8, [x0, #0x1d8]
//   0x0dd098: 12000034  and      w20, w1, #1
static inline uint64_t fde_func_0473_0x0dd08c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd08cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x074e38ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0474 | PC: 0x0dd0bc | FDE: 0x074e58 | Size: 112 bytes [_ZN4lynx6canvas24CanvasResourceProvider3DC1EPNS0_13CanvasElementENSt6__ndk110shared_ptrINS0_12KryptonActorINS0_14KryptonRuntimeEEEEENS5_INS_5shell9LynxActorINS0_15SurfaceRegistryEEEEENS0_22CanvasResourceProvider6OptionE]
// Khung tháo gỡ #0474 | Địa chỉ PC: 0x0dd0bc | Địa chỉ FDE: 0x074e58 | Kích thước: 112 bytes
//   0x0dd0bc: D10143FF  sub      sp, sp, #0x50
//   0x0dd0c0: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x0dd0c4: 3DC00040  ldr      q0, [x2]
//   0x0dd0c8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0474_0x0dd0bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd0bcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9047bf3ULL) ^ 0x074e58ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0475 | PC: 0x0dd12c | FDE: 0x074e70 | Size: 44 bytes [_ZN4lynx6canvas24CanvasResourceProvider3DD2Ev]
// Khung tháo gỡ #0475 | Địa chỉ PC: 0x0dd12c | Địa chỉ FDE: 0x074e70 | Kích thước: 44 bytes
//   0x0dd12c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0dd130: 900005C8  adrp     x8, #0x195000
//   0x0dd134: F9410D08  ldr      x8, [x8, #0x218]
//   0x0dd138: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0475_0x0dd12c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd12cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x900005c8ULL) ^ 0x074e70ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0476 | PC: 0x0dd158 | FDE: 0x074e88 | Size: 24 bytes [_ZN4lynx6canvas24CanvasResourceProvider3DD0Ev]
// Khung tháo gỡ #0476 | Địa chỉ PC: 0x0dd158 | Địa chỉ FDE: 0x074e88 | Kích thước: 24 bytes
//   0x0dd158: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0dd15c: AA0003F3  mov      x19, x0
//   0x0dd160: 9402AD9C  bl       #0x1887d0
//   0x0dd164: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0476_0x0dd158(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd158ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x074e88ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0477 | PC: 0x0dd170 | FDE: 0x074ea0 | Size: 236 bytes [_ZN4lynx6canvas24CanvasResourceProvider3D10ReadPixelsEiiiiPvb]
// Khung tháo gỡ #0477 | Địa chỉ PC: 0x0dd170 | Địa chỉ FDE: 0x074ea0 | Kích thước: 236 bytes
//   0x0dd170: D10203FF  sub      sp, sp, #0x80
//   0x0dd174: F90013FC  str      x28, [sp, #0x20]
//   0x0dd178: AA1E03E7  mov      x7, x30
//   0x0dd17c: 94027D0F  bl       #0x17c5b8
static inline uint64_t fde_func_0477_0x0dd170(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd170ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fcULL) ^ 0x074ea0ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0478 | PC: 0x0dd25c | FDE: 0x074ed0 | Size: 112 bytes [_ZN4lynx6canvas24CanvasResourceProvider3D9PutPixelsEPviiiiiiiiii]
// Khung tháo gỡ #0478 | Địa chỉ PC: 0x0dd25c | Địa chỉ FDE: 0x074ed0 | Kích thước: 112 bytes
//   0x0dd25c: AA1E03E8  mov      x8, x30
//   0x0dd260: 94026ABB  bl       #0x177d4c
//   0x0dd264: AA0803FE  mov      x30, x8
//   0x0dd268: A90A7BFD  stp      x29, x30, [sp, #0xa0]
static inline uint64_t fde_func_0478_0x0dd25c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd25cULL ^ (static_cast<uint64_t>(0xaa1e03e8ULL) << 13);
    acc = (acc + a1 + 0x94026abbULL) ^ 0x074ed0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0479 | PC: 0x0dd2cc | FDE: 0x074f00 | Size: 200 bytes [_ZN4lynx6canvas24CanvasResourceProvider3D22WillAccessRenderBufferEv]
// Khung tháo gỡ #0479 | Địa chỉ PC: 0x0dd2cc | Địa chỉ FDE: 0x074f00 | Kích thước: 200 bytes
//   0x0dd2cc: D10183FF  sub      sp, sp, #0x60
//   0x0dd2d0: F9001BF6  str      x22, [sp, #0x30]
//   0x0dd2d4: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x0dd2d8: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0479_0x0dd2cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd2ccULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf6ULL) ^ 0x074f00ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0480 | PC: 0x0dd394 | FDE: 0x074f20 | Size: 100 bytes [_ZN4lynx6canvas24CanvasResourceProvider3D8DoRasterEbbll]
// Khung tháo gỡ #0480 | Địa chỉ PC: 0x0dd394 | Địa chỉ FDE: 0x074f20 | Kích thước: 100 bytes
//   0x0dd394: D10143FF  sub      sp, sp, #0x50
//   0x0dd398: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0dd39c: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x0dd3a0: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0480_0x0dd394(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd394ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x074f20ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0481 | PC: 0x0dd3f8 | FDE: 0x074f40 | Size: 256 bytes [_ZN4lynx6canvas24CanvasResourceProvider3D12CreateRasterEPNS0_22CanvasResourceProviderEPNS0_22CountDownWaitableEventERKNS_3fml6RefPtrINS6_10TaskRunnerEEERKNS2_6OptionE]
// Khung tháo gỡ #0481 | Địa chỉ PC: 0x0dd3f8 | Địa chỉ FDE: 0x074f40 | Kích thước: 256 bytes
//   0x0dd3f8: AA1E03E1  mov      x1, x30
//   0x0dd3fc: 9402676B  bl       #0x1771a8
//   0x0dd400: AA0103FE  mov      x30, x1
//   0x0dd404: A90B7BFD  stp      x29, x30, [sp, #0xb0]
static inline uint64_t fde_func_0481_0x0dd3f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd3f8ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x9402676bULL) ^ 0x074f40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0482 | PC: 0x0dd588 | FDE: 0x074f70 | Size: 252 bytes [_ZN4lynx6canvas24CanvasResourceProvider3D32AdjustCanvasSizeInResizeIfNeededERiS2_]
// Khung tháo gỡ #0482 | Địa chỉ PC: 0x0dd588 | Địa chỉ FDE: 0x074f70 | Kích thước: 252 bytes
//   0x0dd588: A9BD5BFC  stp      x28, x22, [sp, #-0x30]!
//   0x0dd58c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0dd590: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0dd594: D10883FF  sub      sp, sp, #0x220
static inline uint64_t fde_func_0482_0x0dd588(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd588ULL ^ (static_cast<uint64_t>(0xa9bd5bfcULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x074f70ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0483 | PC: 0x0dd684 | FDE: 0x074fe0 | Size: 256 bytes
// Khung tháo gỡ #0483 | Địa chỉ PC: 0x0dd684 | Địa chỉ FDE: 0x074fe0 | Kích thước: 256 bytes
//   0x0dd684: F9400408  ldr      x8, [x0, #8]
//   0x0dd688: F9400900  ldr      x0, [x8, #0x10]
//   0x0dd68c: 17FFFFEC  b        #0xdd63c
//   0x0dd690: D100C3FF  sub      sp, sp, #0x30
static inline uint64_t fde_func_0483_0x0dd684(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd684ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf9400900ULL) ^ 0x074fe0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0484 | PC: 0x0dd89c | FDE: 0x075040 | Size: 8 bytes [_ZN4lynx6canvas24CanvasResourceProvider3D25GetDrawingBufferSizeWidthEv]
// Khung tháo gỡ #0484 | Địa chỉ PC: 0x0dd89c | Địa chỉ FDE: 0x075040 | Kích thước: 8 bytes
//   0x0dd89c: B9423800  ldr      w0, [x0, #0x238]
//   0x0dd8a0: D65F03C0  ret      
static inline uint64_t fde_func_0484_0x0dd89c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd89cULL ^ (static_cast<uint64_t>(0xb9423800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x075040ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0485 | PC: 0x0dd8a4 | FDE: 0x075058 | Size: 8 bytes [_ZN4lynx6canvas24CanvasResourceProvider3D26GetDrawingBufferSizeHeightEv]
// Khung tháo gỡ #0485 | Địa chỉ PC: 0x0dd8a4 | Địa chỉ FDE: 0x075058 | Kích thước: 8 bytes
//   0x0dd8a4: B9423C00  ldr      w0, [x0, #0x23c]
//   0x0dd8a8: D65F03C0  ret      
static inline uint64_t fde_func_0485_0x0dd8a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd8a4ULL ^ (static_cast<uint64_t>(0xb9423c00ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x075058ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0486 | PC: 0x0dd8ac | FDE: 0x075070 | Size: 256 bytes [_ZN4lynx6canvas24CanvasResourceProvider3D14UploadEGLImageEPviiiiiiiiii]
// Khung tháo gỡ #0486 | Địa chỉ PC: 0x0dd8ac | Địa chỉ FDE: 0x075070 | Kích thước: 256 bytes
//   0x0dd8ac: AA1E03E8  mov      x8, x30
//   0x0dd8b0: 940267C7  bl       #0x1777cc
//   0x0dd8b4: AA0803FE  mov      x30, x8
//   0x0dd8b8: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_0486_0x0dd8ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd8acULL ^ (static_cast<uint64_t>(0xaa1e03e8ULL) << 13);
    acc = (acc + a1 + 0x940267c7ULL) ^ 0x075070ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0487 | PC: 0x0dd9b4 | FDE: 0x0750a0 | Size: 256 bytes [_ZN4lynx6canvas8GLRasterC2ERKNS_3fml6RefPtrINS2_10TaskRunnerEEENS0_19DrawingBufferOptionEPNS0_22CountDownWaitableEventEiiPNS0_9GLContextE]
// Khung tháo gỡ #0487 | Địa chỉ PC: 0x0dd9b4 | Địa chỉ FDE: 0x0750a0 | Kích thước: 256 bytes
//   0x0dd9b4: AA1E03E7  mov      x7, x30
//   0x0dd9b8: 94027C1B  bl       #0x17ca24
//   0x0dd9bc: AA0703FE  mov      x30, x7
//   0x0dd9c0: A9187BF3  stp      x19, x30, [sp, #0x180]
static inline uint64_t fde_func_0487_0x0dd9b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd9b4ULL ^ (static_cast<uint64_t>(0xaa1e03e7ULL) << 13);
    acc = (acc + a1 + 0x94027c1bULL) ^ 0x0750a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0488 | PC: 0x0ddb48 | FDE: 0x0750c8 | Size: 104 bytes [_ZN4lynx6canvas8GLRasterD1Ev]
// Khung tháo gỡ #0488 | Địa chỉ PC: 0x0ddb48 | Địa chỉ FDE: 0x0750c8 | Kích thước: 104 bytes
//   0x0ddb48: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0ddb4c: 900005C9  adrp     x9, #0x195000
//   0x0ddb50: 39412008  ldrb     w8, [x0, #0x48]
//   0x0ddb54: F9411129  ldr      x9, [x9, #0x220]
static inline uint64_t fde_func_0488_0x0ddb48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddb48ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x900005c9ULL) ^ 0x0750c8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0489 | PC: 0x0ddbb0 | FDE: 0x0750e0 | Size: 256 bytes [_ZN4lynx6canvas8GLRaster4InitEv]
// Khung tháo gỡ #0489 | Địa chỉ PC: 0x0ddbb0 | Địa chỉ FDE: 0x0750e0 | Kích thước: 256 bytes
//   0x0ddbb0: D10583FF  sub      sp, sp, #0x160
//   0x0ddbb4: A9135BFC  stp      x28, x22, [sp, #0x130]
//   0x0ddbb8: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0ddbbc: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0489_0x0ddbb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddbb0ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa9135bfcULL) ^ 0x0750e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0490 | PC: 0x0ddcc8 | FDE: 0x075108 | Size: 112 bytes [_ZNK4lynx6canvas8GLRaster9DidRasterENSt6__ndk110unique_ptrINS0_16DoRasterCallbackENS2_14default_deleteIS4_EEEE]
// Khung tháo gỡ #0490 | Địa chỉ PC: 0x0ddcc8 | Địa chỉ FDE: 0x075108 | Kích thước: 112 bytes
//   0x0ddcc8: D100C3FF  sub      sp, sp, #0x30
//   0x0ddccc: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0ddcd0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0ddcd4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0490_0x0ddcc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddcc8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x075108ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0491 | PC: 0x0ddd38 | FDE: 0x075128 | Size: 256 bytes [_ZN4lynx6canvas8GLRaster24DoBlitToSurfacesIfNeededEblliPNS0_16DoRasterCallbackE]
// Khung tháo gỡ #0491 | Địa chỉ PC: 0x0ddd38 | Địa chỉ FDE: 0x075128 | Kích thước: 256 bytes
//   0x0ddd38: D107C3FF  sub      sp, sp, #0x1f0
//   0x0ddd3c: 6D1823E9  stp      d9, d8, [sp, #0x180]
//   0x0ddd40: AA1E03E6  mov      x6, x30
//   0x0ddd44: 94028EF7  bl       #0x181920
static inline uint64_t fde_func_0491_0x0ddd38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddd38ULL ^ (static_cast<uint64_t>(0xd107c3ffULL) << 13);
    acc = (acc + a1 + 0x6d1823e9ULL) ^ 0x075128ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0492 | PC: 0x0de010 | FDE: 0x075160 | Size: 256 bytes [_ZN4lynx6canvas8GLRaster26DrawDrawingBufferToSurfaceEPNS0_17CanvasSurfaceInfoEPNS0_16DoRasterCallbackE]
// Khung tháo gỡ #0492 | Địa chỉ PC: 0x0de010 | Địa chỉ FDE: 0x075160 | Kích thước: 256 bytes
//   0x0de010: D102C3FF  sub      sp, sp, #0xb0
//   0x0de014: F9003BF8  str      x24, [sp, #0x70]
//   0x0de018: A9085BF7  stp      x23, x22, [sp, #0x80]
//   0x0de01c: A90953F5  stp      x21, x20, [sp, #0x90]
static inline uint64_t fde_func_0492_0x0de010(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de010ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf8ULL) ^ 0x075160ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0493 | PC: 0x0de210 | FDE: 0x075188 | Size: 256 bytes [_ZNK4lynx6canvas8GLRaster13GLMakeCurrentEPNS0_24GLSurfaceGraphicsContextE]
// Khung tháo gỡ #0493 | Địa chỉ PC: 0x0de210 | Địa chỉ FDE: 0x075188 | Kích thước: 256 bytes
//   0x0de210: D10583FF  sub      sp, sp, #0x160
//   0x0de214: F9009BFC  str      x28, [sp, #0x130]
//   0x0de218: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0de21c: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0493_0x0de210(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de210ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x075188ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0494 | PC: 0x0de314 | FDE: 0x0751a8 | Size: 212 bytes [_ZNK4lynx6canvas8GLRaster12GetGLContextEv]
// Khung tháo gỡ #0494 | Địa chỉ PC: 0x0de314 | Địa chỉ FDE: 0x0751a8 | Kích thước: 212 bytes
//   0x0de314: D10083FF  sub      sp, sp, #0x20
//   0x0de318: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0de31c: AA0003F3  mov      x19, x0
//   0x0de320: F9402C00  ldr      x0, [x0, #0x58]
static inline uint64_t fde_func_0494_0x0de314(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de314ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0751a8ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0495 | PC: 0x0de3e8 | FDE: 0x0751f8 | Size: 36 bytes
// Khung tháo gỡ #0495 | Địa chỉ PC: 0x0de3e8 | Địa chỉ FDE: 0x0751f8 | Kích thước: 36 bytes
//   0x0de3e8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0de3ec: B0000588  adrp     x8, #0x18f000
//   0x0de3f0: 91000108  add      x8, x8, #0
//   0x0de3f4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0495_0x0de3e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de3e8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb0000588ULL) ^ 0x0751f8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0496 | PC: 0x0de40c | FDE: 0x075210 | Size: 24 bytes [_ZN4lynx6canvas8GLRaster14GLClearCurrentEv]
// Khung tháo gỡ #0496 | Địa chỉ PC: 0x0de40c | Địa chỉ FDE: 0x075210 | Kích thước: 24 bytes
//   0x0de40c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0de410: 9402A90C  bl       #0x188840
//   0x0de414: F9400008  ldr      x8, [x0]
//   0x0de418: F9401501  ldr      x1, [x8, #0x28]
static inline uint64_t fde_func_0496_0x0de40c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de40cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x9402a90cULL) ^ 0x075210ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0497 | PC: 0x0de424 | FDE: 0x075228 | Size: 256 bytes [_ZN4lynx6canvas8GLRaster34CreateOrRecreateCanvasRenderbufferEv]
// Khung tháo gỡ #0497 | Địa chỉ PC: 0x0de424 | Địa chỉ FDE: 0x075228 | Kích thước: 256 bytes
//   0x0de424: D10703FF  sub      sp, sp, #0x1c0
//   0x0de428: F900BBFC  str      x28, [sp, #0x170]
//   0x0de42c: A91863F9  stp      x25, x24, [sp, #0x180]
//   0x0de430: A9195BF7  stp      x23, x22, [sp, #0x190]
static inline uint64_t fde_func_0497_0x0de424(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de424ULL ^ (static_cast<uint64_t>(0xd10703ffULL) << 13);
    acc = (acc + a1 + 0xf900bbfcULL) ^ 0x075228ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0498 | PC: 0x0de6a8 | FDE: 0x075250 | Size: 152 bytes [_ZN4lynx6canvas8GLRaster45TryCreateOrRecreateCanvasOnScreenRenderbufferEv]
// Khung tháo gỡ #0498 | Địa chỉ PC: 0x0de6a8 | Địa chỉ FDE: 0x075250 | Kích thước: 152 bytes
//   0x0de6a8: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0de6ac: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0de6b0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0de6b4: F9402008  ldr      x8, [x0, #0x40]
static inline uint64_t fde_func_0498_0x0de6a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de6a8ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x075250ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0499 | PC: 0x0de740 | FDE: 0x075270 | Size: 256 bytes [_ZN4lynx6canvas6Raster4InitEv]
// Khung tháo gỡ #0499 | Địa chỉ PC: 0x0de740 | Địa chỉ FDE: 0x075270 | Kích thước: 256 bytes
//   0x0de740: D10103FF  sub      sp, sp, #0x40
//   0x0de744: F90013F4  str      x20, [sp, #0x20]
//   0x0de748: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x0de74c: 94025E93  bl       #0x176198
static inline uint64_t fde_func_0499_0x0de740(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de740ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f4ULL) ^ 0x075270ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0500 | PC: 0x0deb84 | FDE: 0x075300 | Size: 196 bytes [_ZN4lynx6canvas8Raster3DC2ERKNS_3fml6RefPtrINS2_10TaskRunnerEEENS0_19DrawingBufferOptionEPNS0_22CountDownWaitableEventEii]
// Khung tháo gỡ #0500 | Địa chỉ PC: 0x0deb84 | Địa chỉ FDE: 0x075300 | Kích thước: 196 bytes
//   0x0deb84: D105C3FF  sub      sp, sp, #0x170
//   0x0deb88: A9145BFC  stp      x28, x22, [sp, #0x140]
//   0x0deb8c: A91553F5  stp      x21, x20, [sp, #0x150]
//   0x0deb90: A9167BF3  stp      x19, x30, [sp, #0x160]
static inline uint64_t fde_func_0500_0x0deb84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0deb84ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xa9145bfcULL) ^ 0x075300ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0501 | PC: 0x0dec48 | FDE: 0x075328 | Size: 120 bytes [_ZN4lynx6canvas8Raster3DD2Ev]
// Khung tháo gỡ #0501 | Địa chỉ PC: 0x0dec48 | Địa chỉ FDE: 0x075328 | Kích thước: 120 bytes
//   0x0dec48: D10583FF  sub      sp, sp, #0x160
//   0x0dec4c: F9009BFC  str      x28, [sp, #0x130]
//   0x0dec50: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0dec54: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0501_0x0dec48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dec48ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x075328ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0502 | PC: 0x0decc0 | FDE: 0x075348 | Size: 24 bytes [_ZN4lynx6canvas8Raster3DD0Ev]
// Khung tháo gỡ #0502 | Địa chỉ PC: 0x0decc0 | Địa chỉ FDE: 0x075348 | Kích thước: 24 bytes
//   0x0decc0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0decc4: AA0003F3  mov      x19, x0
//   0x0decc8: 9402A6EE  bl       #0x188880
//   0x0deccc: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0502_0x0decc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0decc0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x075348ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0503 | PC: 0x0decd8 | FDE: 0x075360 | Size: 128 bytes [_ZN4lynx6canvas8Raster3D17WillAccessContentEb]
// Khung tháo gỡ #0503 | Địa chỉ PC: 0x0decd8 | Địa chỉ FDE: 0x075360 | Kích thước: 128 bytes
//   0x0decd8: D10543FF  sub      sp, sp, #0x150
//   0x0decdc: A91353FC  stp      x28, x20, [sp, #0x130]
//   0x0dece0: A9147BF3  stp      x19, x30, [sp, #0x140]
//   0x0dece4: 94026273  bl       #0x1776b0
static inline uint64_t fde_func_0503_0x0decd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0decd8ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa91353fcULL) ^ 0x075360ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0504 | PC: 0x0ded58 | FDE: 0x075380 | Size: 232 bytes [_ZN4lynx6canvas8Raster3D8DoRasterERKNSt6__ndk110shared_ptrINS0_14command_buffer14RunnableBufferEEEbllNS2_10unique_ptrINS0_16DoRasterCallbackENS2_14default_deleteISA_EEEE]
// Khung tháo gỡ #0504 | Địa chỉ PC: 0x0ded58 | Địa chỉ FDE: 0x075380 | Kích thước: 232 bytes
//   0x0ded58: D102C3FF  sub      sp, sp, #0xb0
//   0x0ded5c: F90033FA  str      x26, [sp, #0x60]
//   0x0ded60: A90763F9  stp      x25, x24, [sp, #0x70]
//   0x0ded64: A9085BF7  stp      x23, x22, [sp, #0x80]
static inline uint64_t fde_func_0504_0x0ded58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ded58ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90033faULL) ^ 0x075380ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0505 | PC: 0x0dee40 | FDE: 0x0753a8 | Size: 244 bytes [_ZN4lynx6canvas8Raster3D14DoCustomRasterERKNSt6__ndk18functionIFbvEEEblliNS2_10unique_ptrINS0_16DoRasterCallbackENS2_14default_deleteIS9_EEEE]
// Khung tháo gỡ #0505 | Địa chỉ PC: 0x0dee40 | Địa chỉ FDE: 0x0753a8 | Kích thước: 244 bytes
//   0x0dee40: AA1E03E7  mov      x7, x30
//   0x0dee44: 9402603F  bl       #0x176f40
//   0x0dee48: AA0703FE  mov      x30, x7
//   0x0dee4c: A9177BF3  stp      x19, x30, [sp, #0x170]
static inline uint64_t fde_func_0505_0x0dee40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dee40ULL ^ (static_cast<uint64_t>(0xaa1e03e7ULL) << 13);
    acc = (acc + a1 + 0x9402603fULL) ^ 0x0753a8ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #0506 | PC: 0x0def34 | FDE: 0x0753d8 | Size: 256 bytes [_ZN4lynx6canvas8Raster3D28MakeSureRenderbufferPreparedEv]
// Khung tháo gỡ #0506 | Địa chỉ PC: 0x0def34 | Địa chỉ FDE: 0x0753d8 | Kích thước: 256 bytes
//   0x0def34: D10603FF  sub      sp, sp, #0x180
//   0x0def38: A91463FC  stp      x28, x24, [sp, #0x140]
//   0x0def3c: A9155BF7  stp      x23, x22, [sp, #0x150]
//   0x0def40: A91653F5  stp      x21, x20, [sp, #0x160]
static inline uint64_t fde_func_0506_0x0def34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0def34ULL ^ (static_cast<uint64_t>(0xd10603ffULL) << 13);
    acc = (acc + a1 + 0xa91463fcULL) ^ 0x0753d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0507 | PC: 0x0df110 | FDE: 0x075418 | Size: 256 bytes
// Khung tháo gỡ #0507 | Địa chỉ PC: 0x0df110 | Địa chỉ FDE: 0x075418 | Kích thước: 256 bytes
//   0x0df110: 90000588  adrp     x8, #0x18f000
//   0x0df114: 91024108  add      x8, x8, #0x90
//   0x0df118: 140262F1  b        #0x177cdc
//   0x0df11c: F81F0FFE  str      x30, [sp, #-0x10]!
static inline uint64_t fde_func_0507_0x0df110(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df110ULL ^ (static_cast<uint64_t>(0x90000588ULL) << 13);
    acc = (acc + a1 + 0x91024108ULL) ^ 0x075418ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0508 | PC: 0x0df310 | FDE: 0x075488 | Size: 92 bytes
// Khung tháo gỡ #0508 | Địa chỉ PC: 0x0df310 | Địa chỉ FDE: 0x075488 | Kích thước: 92 bytes
//   0x0df310: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0df314: AA0003F3  mov      x19, x0
//   0x0df318: 97FFFFC4  bl       #0xdf228
//   0x0df31c: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0508_0x0df310(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df310ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x075488ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0509 | PC: 0x0df36c | FDE: 0x0754e8 | Size: 256 bytes
// Khung tháo gỡ #0509 | Địa chỉ PC: 0x0df36c | Địa chỉ FDE: 0x0754e8 | Kích thước: 256 bytes
//   0x0df36c: B940B800  ldr      w0, [x0, #0xb8]
//   0x0df370: D65F03C0  ret      
//   0x0df374: B940C000  ldr      w0, [x0, #0xc0]
//   0x0df378: D65F03C0  ret      
static inline uint64_t fde_func_0509_0x0df36c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df36cULL ^ (static_cast<uint64_t>(0xb940b800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0754e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0510 | PC: 0x0df46c | FDE: 0x075550 | Size: 128 bytes
// Khung tháo gỡ #0510 | Địa chỉ PC: 0x0df46c | Địa chỉ FDE: 0x075550 | Kích thước: 128 bytes
//   0x0df46c: D10083FF  sub      sp, sp, #0x20
//   0x0df470: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0df474: AA0003F3  mov      x19, x0
//   0x0df478: F9402800  ldr      x0, [x0, #0x50]
static inline uint64_t fde_func_0510_0x0df46c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df46cULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x075550ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0511 | PC: 0x0df4ec | FDE: 0x0755b0 | Size: 256 bytes
// Khung tháo gỡ #0511 | Địa chỉ PC: 0x0df4ec | Địa chỉ FDE: 0x0755b0 | Kích thước: 256 bytes
//   0x0df4ec: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0df4f0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0df4f4: AA0103F4  mov      x20, x1
//   0x0df4f8: B0FFFAA1  adrp     x1, #0x34000
static inline uint64_t fde_func_0511_0x0df4ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df4ecULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0755b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0512 | PC: 0x0e067c | FDE: 0x075630 | Size: 256 bytes
// Khung tháo gỡ #0512 | Địa chỉ PC: 0x0e067c | Địa chỉ FDE: 0x075630 | Kích thước: 256 bytes
//   0x0e067c: D10203FF  sub      sp, sp, #0x80
//   0x0e0680: AA1E03E3  mov      x3, x30
//   0x0e0684: 94026FCD  bl       #0x17c5b8
//   0x0e0688: AA0303FE  mov      x30, x3
static inline uint64_t fde_func_0512_0x0e067c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e067cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xaa1e03e3ULL) ^ 0x075630ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0513 | PC: 0x0e08ec | FDE: 0x0756c8 | Size: 112 bytes
// Khung tháo gỡ #0513 | Địa chỉ PC: 0x0e08ec | Địa chỉ FDE: 0x0756c8 | Kích thước: 112 bytes
//   0x0e08ec: F9400400  ldr      x0, [x0, #8]
//   0x0e08f0: 14000001  b        #0xe08f4
//   0x0e08f4: B4000160  cbz      x0, #0xe0920
//   0x0e08f8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
static inline uint64_t fde_func_0513_0x0e08ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e08ecULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x0756c8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0514 | PC: 0x0e095c | FDE: 0x075728 | Size: 96 bytes
// Khung tháo gỡ #0514 | Địa chỉ PC: 0x0e095c | Địa chỉ FDE: 0x075728 | Kích thước: 96 bytes
//   0x0e095c: F8420C08  ldr      x8, [x0, #0x20]!
//   0x0e0960: 14026CFF  b        #0x17bd5c
//   0x0e0964: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e0968: F0000568  adrp     x8, #0x18f000
static inline uint64_t fde_func_0514_0x0e095c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e095cULL ^ (static_cast<uint64_t>(0xf8420c08ULL) << 13);
    acc = (acc + a1 + 0x14026cffULL) ^ 0x075728ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0515 | PC: 0x0e09bc | FDE: 0x075788 | Size: 204 bytes
// Khung tháo gỡ #0515 | Địa chỉ PC: 0x0e09bc | Địa chỉ FDE: 0x075788 | Kích thước: 204 bytes
//   0x0e09bc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e09c0: AA0003F3  mov      x19, x0
//   0x0e09c4: 97FFFFF6  bl       #0xe099c
//   0x0e09c8: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0515_0x0e09bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e09bcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x075788ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #0516 | PC: 0x0e0a88 | FDE: 0x0757f0 | Size: 256 bytes
// Khung tháo gỡ #0516 | Địa chỉ PC: 0x0e0a88 | Địa chỉ FDE: 0x0757f0 | Kích thước: 256 bytes
//   0x0e0a88: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e0a8c: 9402659F  bl       #0x17a108
//   0x0e0a90: 91006260  add      x0, x19, #0x18
//   0x0e0a94: A8C17BF3  ldp      x19, x30, [sp], #0x10
static inline uint64_t fde_func_0516_0x0e0a88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e0a88ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9402659fULL) ^ 0x0757f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0517 | PC: 0x0e0d64 | FDE: 0x075878 | Size: 256 bytes
// Khung tháo gỡ #0517 | Địa chỉ PC: 0x0e0d64 | Địa chỉ FDE: 0x075878 | Kích thước: 256 bytes
//   0x0e0d64: AA1E03E7  mov      x7, x30
//   0x0e0d68: 94025F29  bl       #0x178a0c
//   0x0e0d6c: AA0703FE  mov      x30, x7
//   0x0e0d70: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_0517_0x0e0d64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e0d64ULL ^ (static_cast<uint64_t>(0xaa1e03e7ULL) << 13);
    acc = (acc + a1 + 0x94025f29ULL) ^ 0x075878ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0518 | PC: 0x0e0f48 | FDE: 0x075900 | Size: 256 bytes
// Khung tháo gỡ #0518 | Địa chỉ PC: 0x0e0f48 | Địa chỉ FDE: 0x075900 | Kích thước: 256 bytes
//   0x0e0f48: F9400808  ldr      x8, [x0, #0x10]
//   0x0e0f4c: F0000569  adrp     x9, #0x18f000
//   0x0e0f50: 91096129  add      x9, x9, #0x258
//   0x0e0f54: 14026C03  b        #0x17bf60
static inline uint64_t fde_func_0518_0x0e0f48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e0f48ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xf0000569ULL) ^ 0x075900ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0519 | PC: 0x0e106c | FDE: 0x075970 | Size: 256 bytes
// Khung tháo gỡ #0519 | Địa chỉ PC: 0x0e106c | Địa chỉ FDE: 0x075970 | Kích thước: 256 bytes
//   0x0e106c: D10583FF  sub      sp, sp, #0x160
//   0x0e1070: F9009BFC  str      x28, [sp, #0x130]
//   0x0e1074: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0e1078: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0519_0x0e106c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e106cULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x075970ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0520 | PC: 0x0e1234 | FDE: 0x075a00 | Size: 256 bytes
// Khung tháo gỡ #0520 | Địa chỉ PC: 0x0e1234 | Địa chỉ FDE: 0x075a00 | Kích thước: 256 bytes
//   0x0e1234: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e1238: F9400408  ldr      x8, [x0, #8]
//   0x0e123c: AA0003F3  mov      x19, x0
//   0x0e1240: 94027059  bl       #0x17d3a4
static inline uint64_t fde_func_0520_0x0e1234(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1234ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400408ULL) ^ 0x075a00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0521 | PC: 0x0e1360 | FDE: 0x075a78 | Size: 256 bytes
// Khung tháo gỡ #0521 | Địa chỉ PC: 0x0e1360 | Địa chỉ FDE: 0x075a78 | Kích thước: 256 bytes
//   0x0e1360: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0e1364: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e1368: F9400408  ldr      x8, [x0, #8]
//   0x0e136c: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0521_0x0e1360(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1360ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x075a78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0522 | PC: 0x0e16ec | FDE: 0x075af8 | Size: 256 bytes
// Khung tháo gỡ #0522 | Địa chỉ PC: 0x0e16ec | Địa chỉ FDE: 0x075af8 | Kích thước: 256 bytes
//   0x0e16ec: D10583FF  sub      sp, sp, #0x160
//   0x0e16f0: A9135BFC  stp      x28, x22, [sp, #0x130]
//   0x0e16f4: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0e16f8: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0522_0x0e16ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e16ecULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa9135bfcULL) ^ 0x075af8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0523 | PC: 0x0e1918 | FDE: 0x075b98 | Size: 204 bytes
// Khung tháo gỡ #0523 | Địa chỉ PC: 0x0e1918 | Địa chỉ FDE: 0x075b98 | Kích thước: 204 bytes
//   0x0e1918: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e191c: AA0003F3  mov      x19, x0
//   0x0e1920: 97FFFFFA  bl       #0xe1908
//   0x0e1924: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0523_0x0e1918(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1918ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x075b98ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #0524 | PC: 0x0e19e4 | FDE: 0x075bf8 | Size: 256 bytes
// Khung tháo gỡ #0524 | Địa chỉ PC: 0x0e19e4 | Địa chỉ FDE: 0x075bf8 | Kích thước: 256 bytes
//   0x0e19e4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e19e8: AA0003F3  mov      x19, x0
//   0x0e19ec: 97FFFFF6  bl       #0xe19c4
//   0x0e19f0: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0524_0x0e19e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e19e4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x075bf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0525 | PC: 0x0e20d8 | FDE: 0x075c70 | Size: 224 bytes
// Khung tháo gỡ #0525 | Địa chỉ PC: 0x0e20d8 | Địa chỉ FDE: 0x075c70 | Kích thước: 224 bytes
//   0x0e20d8: 3940C008  ldrb     w8, [x0, #0x30]
//   0x0e20dc: 34000048  cbz      w8, #0xe20e4
//   0x0e20e0: 17FF26EE  b        #0xabc98
//   0x0e20e4: D65F03C0  ret      
static inline uint64_t fde_func_0525_0x0e20d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e20d8ULL ^ (static_cast<uint64_t>(0x3940c008ULL) << 13);
    acc = (acc + a1 + 0x34000048ULL) ^ 0x075c70ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #0526 | PC: 0x0e21b8 | FDE: 0x075cd8 | Size: 136 bytes
// Khung tháo gỡ #0526 | Địa chỉ PC: 0x0e21b8 | Địa chỉ FDE: 0x075cd8 | Kích thước: 136 bytes
//   0x0e21b8: F9400808  ldr      x8, [x0, #0x10]
//   0x0e21bc: B0000569  adrp     x9, #0x18f000
//   0x0e21c0: 910BE129  add      x9, x9, #0x2f8
//   0x0e21c4: 14026291  b        #0x17ac08
static inline uint64_t fde_func_0526_0x0e21b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e21b8ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xb0000569ULL) ^ 0x075cd8ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0527 | PC: 0x0e2240 | FDE: 0x075d38 | Size: 100 bytes
// Khung tháo gỡ #0527 | Địa chỉ PC: 0x0e2240 | Địa chỉ FDE: 0x075d38 | Kích thước: 100 bytes
//   0x0e2240: 1400E15F  b        #0x11a7bc
//   0x0e2244: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e2248: 94026591  bl       #0x17b88c
//   0x0e224c: A8C17BF3  ldp      x19, x30, [sp], #0x10
static inline uint64_t fde_func_0527_0x0e2240(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2240ULL ^ (static_cast<uint64_t>(0x1400e15fULL) << 13);
    acc = (acc + a1 + 0xa9bf7bf3ULL) ^ 0x075d38ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0528 | PC: 0x0e22a4 | FDE: 0x075d98 | Size: 136 bytes
// Khung tháo gỡ #0528 | Địa chỉ PC: 0x0e22a4 | Địa chỉ FDE: 0x075d98 | Kích thước: 136 bytes
//   0x0e22a4: F9400808  ldr      x8, [x0, #0x10]
//   0x0e22a8: B0000569  adrp     x9, #0x18f000
//   0x0e22ac: 910E2129  add      x9, x9, #0x388
//   0x0e22b0: 14026256  b        #0x17ac08
static inline uint64_t fde_func_0528_0x0e22a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e22a4ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xb0000569ULL) ^ 0x075d98ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0529 | PC: 0x0e232c | FDE: 0x075df8 | Size: 256 bytes
// Khung tháo gỡ #0529 | Địa chỉ PC: 0x0e232c | Địa chỉ FDE: 0x075df8 | Kích thước: 256 bytes
//   0x0e232c: FC190FE8  str      d8, [sp, #-0x70]!
//   0x0e2330: AA1E03E2  mov      x2, x30
//   0x0e2334: 940251CB  bl       #0x176a60
//   0x0e2338: AA0203FE  mov      x30, x2
static inline uint64_t fde_func_0529_0x0e232c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e232cULL ^ (static_cast<uint64_t>(0xfc190fe8ULL) << 13);
    acc = (acc + a1 + 0xaa1e03e2ULL) ^ 0x075df8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0530 | PC: 0x0e2d38 | FDE: 0x075e80 | Size: 220 bytes
// Khung tháo gỡ #0530 | Địa chỉ PC: 0x0e2d38 | Địa chỉ FDE: 0x075e80 | Kích thước: 220 bytes
//   0x0e2d38: D37AFC08  lsr      x8, x0, #0x3a
//   0x0e2d3c: B5000068  cbnz     x8, #0xe2d48
//   0x0e2d40: D37AE400  lsl      x0, x0, #6
//   0x0e2d44: 14029177  b        #0x187320
static inline uint64_t fde_func_0530_0x0e2d38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2d38ULL ^ (static_cast<uint64_t>(0xd37afc08ULL) << 13);
    acc = (acc + a1 + 0xb5000068ULL) ^ 0x075e80ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0531 | PC: 0x0e2e14 | FDE: 0x075ef0 | Size: 128 bytes
// Khung tháo gỡ #0531 | Địa chỉ PC: 0x0e2e14 | Địa chỉ FDE: 0x075ef0 | Kích thước: 128 bytes
//   0x0e2e14: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0e2e18: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e2e1c: AA0103F3  mov      x19, x1
//   0x0e2e20: B0FFFA61  adrp     x1, #0x2f000
static inline uint64_t fde_func_0531_0x0e2e14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2e14ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x075ef0ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0532 | PC: 0x0e2e94 | FDE: 0x075f60 | Size: 256 bytes
// Khung tháo gỡ #0532 | Địa chỉ PC: 0x0e2e94 | Địa chỉ FDE: 0x075f60 | Kích thước: 256 bytes
//   0x0e2e94: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e2e98: AA0003F3  mov      x19, x0
//   0x0e2e9c: 94025369  bl       #0x177c40
//   0x0e2ea0: B0000568  adrp     x8, #0x18f000
static inline uint64_t fde_func_0532_0x0e2e94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2e94ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x075f60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0533 | PC: 0x0e30ac | FDE: 0x075fd8 | Size: 156 bytes
// Khung tháo gỡ #0533 | Địa chỉ PC: 0x0e30ac | Địa chỉ FDE: 0x075fd8 | Kích thước: 156 bytes
//   0x0e30ac: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e30b0: 90000568  adrp     x8, #0x18f000
//   0x0e30b4: 91102108  add      x8, x8, #0x408
//   0x0e30b8: 940271A3  bl       #0x17f744
static inline uint64_t fde_func_0533_0x0e30ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e30acULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x90000568ULL) ^ 0x075fd8ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0534 | PC: 0x0e3148 | FDE: 0x076038 | Size: 240 bytes
// Khung tháo gỡ #0534 | Địa chỉ PC: 0x0e3148 | Địa chỉ FDE: 0x076038 | Kích thước: 240 bytes
//   0x0e3148: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0e314c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e3150: 3946A008  ldrb     w8, [x0, #0x1a8]
//   0x0e3154: 94024F49  bl       #0x176e78
static inline uint64_t fde_func_0534_0x0e3148(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3148ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x076038ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0535 | PC: 0x0e3238 | FDE: 0x0760a0 | Size: 256 bytes
// Khung tháo gỡ #0535 | Địa chỉ PC: 0x0e3238 | Địa chỉ FDE: 0x0760a0 | Kích thước: 256 bytes
//   0x0e3238: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e323c: AA0003F3  mov      x19, x0
//   0x0e3240: 97FFFFF3  bl       #0xe320c
//   0x0e3244: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0535_0x0e3238(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3238ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0760a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0536 | PC: 0x0e3438 | FDE: 0x076110 | Size: 164 bytes
// Khung tháo gỡ #0536 | Địa chỉ PC: 0x0e3438 | Địa chỉ FDE: 0x076110 | Kích thước: 164 bytes
//   0x0e3438: F9400C08  ldr      x8, [x0, #0x18]
//   0x0e343c: B40000C8  cbz      x8, #0xe3454
//   0x0e3440: F9400908  ldr      x8, [x8, #0x10]
//   0x0e3444: B4000088  cbz      x8, #0xe3454
static inline uint64_t fde_func_0536_0x0e3438(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3438ULL ^ (static_cast<uint64_t>(0xf9400c08ULL) << 13);
    acc = (acc + a1 + 0xb40000c8ULL) ^ 0x076110ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0537 | PC: 0x0e34dc | FDE: 0x076178 | Size: 256 bytes
// Khung tháo gỡ #0537 | Địa chỉ PC: 0x0e34dc | Địa chỉ FDE: 0x076178 | Kích thước: 256 bytes
//   0x0e34dc: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0e34e0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0e34e4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0e34e8: 94025409  bl       #0x17850c
static inline uint64_t fde_func_0537_0x0e34dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e34dcULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x076178ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0538 | PC: 0x0e35f0 | FDE: 0x0761f0 | Size: 216 bytes
// Khung tháo gỡ #0538 | Địa chỉ PC: 0x0e35f0 | Địa chỉ FDE: 0x0761f0 | Kích thước: 216 bytes
//   0x0e35f0: D100C3FF  sub      sp, sp, #0x30
//   0x0e35f4: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0e35f8: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0e35fc: 9100C014  add      x20, x0, #0x30
static inline uint64_t fde_func_0538_0x0e35f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e35f0ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0761f0ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #0539 | PC: 0x0e36c8 | FDE: 0x076260 | Size: 120 bytes
// Khung tháo gỡ #0539 | Địa chỉ PC: 0x0e36c8 | Địa chỉ FDE: 0x076260 | Kích thước: 120 bytes
//   0x0e36c8: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0e36cc: 940278B6  bl       #0x1819a4
//   0x0e36d0: 52800200  mov      w0, #0x10
//   0x0e36d4: F84107FE  ldr      x30, [sp], #0x10
static inline uint64_t fde_func_0539_0x0e36c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e36c8ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x940278b6ULL) ^ 0x076260ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0540 | PC: 0x0e3740 | FDE: 0x0762c8 | Size: 200 bytes
// Khung tháo gỡ #0540 | Địa chỉ PC: 0x0e3740 | Địa chỉ FDE: 0x0762c8 | Kích thước: 200 bytes
//   0x0e3740: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0e3744: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e3748: 9100C013  add      x19, x0, #0x30
//   0x0e374c: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0540_0x0e3740(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3740ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0762c8ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0541 | PC: 0x0e3808 | FDE: 0x076338 | Size: 208 bytes
// Khung tháo gỡ #0541 | Địa chỉ PC: 0x0e3808 | Địa chỉ FDE: 0x076338 | Kích thước: 208 bytes
//   0x0e3808: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x0e380c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0e3810: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0e3814: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0541_0x0e3808(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3808ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x076338ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0542 | PC: 0x0e38d8 | FDE: 0x0763b0 | Size: 220 bytes
// Khung tháo gỡ #0542 | Địa chỉ PC: 0x0e38d8 | Địa chỉ FDE: 0x0763b0 | Kích thước: 220 bytes
//   0x0e38d8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e38dc: AA0003F3  mov      x19, x0
//   0x0e38e0: 94029434  bl       #0x1889b0
//   0x0e38e4: F9400269  ldr      x9, [x19]
static inline uint64_t fde_func_0542_0x0e38d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e38d8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0763b0ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #0543 | PC: 0x0e39b4 | FDE: 0x076418 | Size: 116 bytes
// Khung tháo gỡ #0543 | Địa chỉ PC: 0x0e39b4 | Địa chỉ FDE: 0x076418 | Kích thước: 116 bytes
//   0x0e39b4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e39b8: AA0003F3  mov      x19, x0
//   0x0e39bc: B9400800  ldr      w0, [x0, #8]
//   0x0e39c0: F9400261  ldr      x1, [x19]
static inline uint64_t fde_func_0543_0x0e39b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e39b4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x076418ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0544 | PC: 0x0e3a28 | FDE: 0x076480 | Size: 248 bytes
// Khung tháo gỡ #0544 | Địa chỉ PC: 0x0e3a28 | Địa chỉ FDE: 0x076480 | Kích thước: 248 bytes
//   0x0e3a28: D100C3FF  sub      sp, sp, #0x30
//   0x0e3a2c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0e3a30: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0e3a34: 9100C014  add      x20, x0, #0x30
static inline uint64_t fde_func_0544_0x0e3a28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3a28ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x076480ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0545 | PC: 0x0e3b20 | FDE: 0x0764f0 | Size: 192 bytes
// Khung tháo gỡ #0545 | Địa chỉ PC: 0x0e3b20 | Địa chỉ FDE: 0x0764f0 | Kích thước: 192 bytes
//   0x0e3b20: D100C3FF  sub      sp, sp, #0x30
//   0x0e3b24: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0e3b28: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0e3b2c: 9100C014  add      x20, x0, #0x30
static inline uint64_t fde_func_0545_0x0e3b20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3b20ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0764f0ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #0546 | PC: 0x0e3be0 | FDE: 0x076560 | Size: 256 bytes
// Khung tháo gỡ #0546 | Địa chỉ PC: 0x0e3be0 | Địa chỉ FDE: 0x076560 | Kích thước: 256 bytes
//   0x0e3be0: D10103FF  sub      sp, sp, #0x40
//   0x0e3be4: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0e3be8: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0e3bec: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0546_0x0e3be0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3be0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x076560ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0547 | PC: 0x0e3d08 | FDE: 0x0765d0 | Size: 140 bytes
// Khung tháo gỡ #0547 | Địa chỉ PC: 0x0e3d08 | Địa chỉ FDE: 0x0765d0 | Kích thước: 140 bytes
//   0x0e3d08: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0e3d0c: B9400000  ldr      w0, [x0]
//   0x0e3d10: 94028F7C  bl       #0x187b00
//   0x0e3d14: 52800080  mov      w0, #4
static inline uint64_t fde_func_0547_0x0e3d08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3d08ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb9400000ULL) ^ 0x0765d0ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0548 | PC: 0x0e3d94 | FDE: 0x076638 | Size: 96 bytes
// Khung tháo gỡ #0548 | Địa chỉ PC: 0x0e3d94 | Địa chỉ FDE: 0x076638 | Kích thước: 96 bytes
//   0x0e3d94: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0e3d98: B9400000  ldr      w0, [x0]
//   0x0e3d9c: 94029331  bl       #0x188a60
//   0x0e3da0: 52800080  mov      w0, #4
static inline uint64_t fde_func_0548_0x0e3d94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3d94ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb9400000ULL) ^ 0x076638ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0549 | PC: 0x0e3df4 | FDE: 0x076698 | Size: 200 bytes
// Khung tháo gỡ #0549 | Địa chỉ PC: 0x0e3df4 | Địa chỉ FDE: 0x076698 | Kích thước: 200 bytes
//   0x0e3df4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0e3df8: 29400408  ldp      w8, w1, [x0]
//   0x0e3dfc: A9408C02  ldp      x2, x3, [x0, #8]
//   0x0e3e00: 2A0803E0  mov      w0, w8
static inline uint64_t fde_func_0549_0x0e3df4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3df4ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x29400408ULL) ^ 0x076698ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0550 | PC: 0x0e3ebc | FDE: 0x076700 | Size: 256 bytes
// Khung tháo gỡ #0550 | Địa chỉ PC: 0x0e3ebc | Địa chỉ FDE: 0x076700 | Kích thước: 256 bytes
//   0x0e3ebc: AA1E03E3  mov      x3, x30
//   0x0e3ec0: 94024FC4  bl       #0x177dd0
//   0x0e3ec4: AA0303FE  mov      x30, x3
//   0x0e3ec8: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0550_0x0e3ebc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3ebcULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94024fc4ULL) ^ 0x076700ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0551 | PC: 0x0e3ff4 | FDE: 0x076780 | Size: 256 bytes
// Khung tháo gỡ #0551 | Địa chỉ PC: 0x0e3ff4 | Địa chỉ FDE: 0x076780 | Kích thước: 256 bytes
//   0x0e3ff4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0e3ff8: 94028119  bl       #0x18445c
//   0x0e3ffc: 52800100  mov      w0, #8
//   0x0e4000: F84107FE  ldr      x30, [sp], #0x10
static inline uint64_t fde_func_0551_0x0e3ff4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3ff4ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x94028119ULL) ^ 0x076780ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0552 | PC: 0x0e4300 | FDE: 0x076828 | Size: 256 bytes
// Khung tháo gỡ #0552 | Địa chỉ PC: 0x0e4300 | Địa chỉ FDE: 0x076828 | Kích thước: 256 bytes
//   0x0e4300: AA1E03E1  mov      x1, x30
//   0x0e4304: 94024A62  bl       #0x176c8c
//   0x0e4308: AA0103FE  mov      x30, x1
//   0x0e430c: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0552_0x0e4300(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4300ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x94024a62ULL) ^ 0x076828ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0553 | PC: 0x0e45ac | FDE: 0x0768b8 | Size: 196 bytes
// Khung tháo gỡ #0553 | Địa chỉ PC: 0x0e45ac | Địa chỉ FDE: 0x0768b8 | Kích thước: 196 bytes
//   0x0e45ac: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0e45b0: 94027501  bl       #0x1819b4
//   0x0e45b4: 52800180  mov      w0, #0xc
//   0x0e45b8: F84107FE  ldr      x30, [sp], #0x10
static inline uint64_t fde_func_0553_0x0e45ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e45acULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x94027501ULL) ^ 0x0768b8ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0554 | PC: 0x0e4670 | FDE: 0x076928 | Size: 252 bytes
// Khung tháo gỡ #0554 | Địa chỉ PC: 0x0e4670 | Địa chỉ FDE: 0x076928 | Kích thước: 252 bytes
//   0x0e4670: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0e4674: 940274D4  bl       #0x1819c4
//   0x0e4678: 52800180  mov      w0, #0xc
//   0x0e467c: F84107FE  ldr      x30, [sp], #0x10
static inline uint64_t fde_func_0554_0x0e4670(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4670ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x940274d4ULL) ^ 0x076928ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0555 | PC: 0x0e476c | FDE: 0x0769a0 | Size: 156 bytes
// Khung tháo gỡ #0555 | Địa chỉ PC: 0x0e476c | Địa chỉ FDE: 0x0769a0 | Kích thước: 156 bytes
//   0x0e476c: D10083FF  sub      sp, sp, #0x20
//   0x0e4770: F9000BFE  str      x30, [sp, #0x10]
//   0x0e4774: 94026723  bl       #0x17e400
//   0x0e4778: 94028F16  bl       #0x1883d0
static inline uint64_t fde_func_0555_0x0e476c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e476cULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfeULL) ^ 0x0769a0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0556 | PC: 0x0e4808 | FDE: 0x076a08 | Size: 148 bytes
// Khung tháo gỡ #0556 | Địa chỉ PC: 0x0e4808 | Địa chỉ FDE: 0x076a08 | Kích thước: 148 bytes
//   0x0e4808: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0e480c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e4810: D37EF455  lsl      x21, x2, #2
//   0x0e4814: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0556_0x0e4808(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4808ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x076a08ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0557 | PC: 0x0e489c | FDE: 0x076a78 | Size: 256 bytes
// Khung tháo gỡ #0557 | Địa chỉ PC: 0x0e489c | Địa chỉ FDE: 0x076a78 | Kích thước: 256 bytes
//   0x0e489c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e48a0: 94026BA4  bl       #0x17f730
//   0x0e48a4: 940290A3  bl       #0x188b30
//   0x0e48a8: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0557_0x0e489c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e489cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94026ba4ULL) ^ 0x076a78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0558 | PC: 0x0e4ac4 | FDE: 0x076af8 | Size: 192 bytes
// Khung tháo gỡ #0558 | Địa chỉ PC: 0x0e4ac4 | Địa chỉ FDE: 0x076af8 | Kích thước: 192 bytes
//   0x0e4ac4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0e4ac8: B9400000  ldr      w0, [x0]
//   0x0e4acc: 94029021  bl       #0x188b50
//   0x0e4ad0: 52800080  mov      w0, #4
static inline uint64_t fde_func_0558_0x0e4ac4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4ac4ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb9400000ULL) ^ 0x076af8ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #0559 | PC: 0x0e4b84 | FDE: 0x076b60 | Size: 256 bytes
// Khung tháo gỡ #0559 | Địa chỉ PC: 0x0e4b84 | Địa chỉ FDE: 0x076b60 | Kích thước: 256 bytes
//   0x0e4b84: D100C3FF  sub      sp, sp, #0x30
//   0x0e4b88: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0e4b8c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0e4b90: 94024504  bl       #0x175fa0
static inline uint64_t fde_func_0559_0x0e4b84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4b84ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x076b60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0560 | PC: 0x0e4cc4 | FDE: 0x076be0 | Size: 256 bytes
// Khung tháo gỡ #0560 | Địa chỉ PC: 0x0e4cc4 | Địa chỉ FDE: 0x076be0 | Kích thước: 256 bytes
//   0x0e4cc4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0e4cc8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e4ccc: AA0003F3  mov      x19, x0
//   0x0e4cd0: 94000077  bl       #0xe4eac
static inline uint64_t fde_func_0560_0x0e4cc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4cc4ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x076be0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0561 | PC: 0x0e4e2c | FDE: 0x076c58 | Size: 256 bytes
// Khung tháo gỡ #0561 | Địa chỉ PC: 0x0e4e2c | Địa chỉ FDE: 0x076c58 | Kích thước: 256 bytes
//   0x0e4e2c: D10103FF  sub      sp, sp, #0x40
//   0x0e4e30: F9000BF6  str      x22, [sp, #0x10]
//   0x0e4e34: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0e4e38: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0561_0x0e4e2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4e2cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x076c58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0562 | PC: 0x0e50ac | FDE: 0x076cd0 | Size: 256 bytes
// Khung tháo gỡ #0562 | Địa chỉ PC: 0x0e50ac | Địa chỉ FDE: 0x076cd0 | Kích thước: 256 bytes
//   0x0e50ac: AA1F03E1  mov      x1, xzr
//   0x0e50b0: 17FFFFF2  b        #0xe5078
//   0x0e50b4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e50b8: 94025414  bl       #0x17a108
static inline uint64_t fde_func_0562_0x0e50ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e50acULL ^ (static_cast<uint64_t>(0xaa1f03e1ULL) << 13);
    acc = (acc + a1 + 0x17fffff2ULL) ^ 0x076cd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0563 | PC: 0x0e51f4 | FDE: 0x076d48 | Size: 256 bytes
// Khung tháo gỡ #0563 | Địa chỉ PC: 0x0e51f4 | Địa chỉ FDE: 0x076d48 | Kích thước: 256 bytes
//   0x0e51f4: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0e51f8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0e51fc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0e5200: 2A0303F5  mov      w21, w3
static inline uint64_t fde_func_0563_0x0e51f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e51f4ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x076d48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0564 | PC: 0x0e5320 | FDE: 0x076dc8 | Size: 256 bytes
// Khung tháo gỡ #0564 | Địa chỉ PC: 0x0e5320 | Địa chỉ FDE: 0x076dc8 | Kích thước: 256 bytes
//   0x0e5320: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0e5324: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e5328: 2A0103F4  mov      w20, w1
//   0x0e532c: 940256BD  bl       #0x17ae20
static inline uint64_t fde_func_0564_0x0e5320(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5320ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x076dc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0565 | PC: 0x0e5478 | FDE: 0x076e40 | Size: 48 bytes
// Khung tháo gỡ #0565 | Địa chỉ PC: 0x0e5478 | Địa chỉ FDE: 0x076e40 | Kích thước: 48 bytes
//   0x0e5478: D10083FF  sub      sp, sp, #0x20
//   0x0e547c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e5480: 9402596F  bl       #0x17ba3c
//   0x0e5484: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0565_0x0e5478(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5478ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x076e40ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0566 | PC: 0x0e54a8 | FDE: 0x076e58 | Size: 156 bytes [_ZN4lynx6canvas9GLContext13CreateVirtualEv]
// Khung tháo gỡ #0566 | Địa chỉ PC: 0x0e54a8 | Địa chỉ FDE: 0x076e58 | Kích thước: 156 bytes
//   0x0e54a8: D10583FF  sub      sp, sp, #0x160
//   0x0e54ac: A9135BFC  stp      x28, x22, [sp, #0x130]
//   0x0e54b0: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0e54b4: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0566_0x0e54a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e54a8ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa9135bfcULL) ^ 0x076e58ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0567 | PC: 0x0e5544 | FDE: 0x076e80 | Size: 20 bytes [_ZN4lynx6canvas9GLContext10GetCurrentEv]
// Khung tháo gỡ #0567 | Địa chỉ PC: 0x0e5544 | Địa chỉ FDE: 0x076e80 | Kích thước: 20 bytes
//   0x0e5544: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0e5548: 94024FF9  bl       #0x17952c
//   0x0e554c: F9400000  ldr      x0, [x0]
//   0x0e5550: F84107FE  ldr      x30, [sp], #0x10
static inline uint64_t fde_func_0567_0x0e5544(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5544ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x94024ff9ULL) ^ 0x076e80ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0568 | PC: 0x0e5558 | FDE: 0x076e98 | Size: 128 bytes [_ZN4lynx6canvas9GLContext10CreateRealEv]
// Khung tháo gỡ #0568 | Địa chỉ PC: 0x0e5558 | Địa chỉ FDE: 0x076e98 | Kích thước: 128 bytes
//   0x0e5558: D10583FF  sub      sp, sp, #0x160
//   0x0e555c: A9135BFC  stp      x28, x22, [sp, #0x130]
//   0x0e5560: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0e5564: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0568_0x0e5558(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5558ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa9135bfcULL) ^ 0x076e98ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0569 | PC: 0x0e55d8 | FDE: 0x076ec0 | Size: 256 bytes
// Khung tháo gỡ #0569 | Địa chỉ PC: 0x0e55d8 | Địa chỉ FDE: 0x076ec0 | Kích thước: 256 bytes
//   0x0e55d8: D10583FF  sub      sp, sp, #0x160
//   0x0e55dc: F9009BFC  str      x28, [sp, #0x130]
//   0x0e55e0: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0e55e4: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0569_0x0e55d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e55d8ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x076ec0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0570 | PC: 0x0e595c | FDE: 0x076f40 | Size: 208 bytes
// Khung tháo gỡ #0570 | Địa chỉ PC: 0x0e595c | Địa chỉ FDE: 0x076f40 | Kích thước: 208 bytes
//   0x0e595c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0e5960: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e5964: F9400C14  ldr      x20, [x0, #0x18]
//   0x0e5968: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0570_0x0e595c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e595cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x076f40ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0571 | PC: 0x0e5a2c | FDE: 0x076f98 | Size: 20 bytes [_ZN4lynx6canvas24GLSurfaceGraphicsContext10GetCurrentEv]
// Khung tháo gỡ #0571 | Địa chỉ PC: 0x0e5a2c | Địa chỉ FDE: 0x076f98 | Kích thước: 20 bytes
//   0x0e5a2c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0e5a30: 940257FB  bl       #0x17ba1c
//   0x0e5a34: F9400000  ldr      x0, [x0]
//   0x0e5a38: F84107FE  ldr      x30, [sp], #0x10
static inline uint64_t fde_func_0571_0x0e5a2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5a2cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x940257fbULL) ^ 0x076f98ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0572 | PC: 0x0e5a40 | FDE: 0x076fb0 | Size: 256 bytes
// Khung tháo gỡ #0572 | Địa chỉ PC: 0x0e5a40 | Địa chỉ FDE: 0x076fb0 | Kích thước: 256 bytes
//   0x0e5a40: D10603FF  sub      sp, sp, #0x180
//   0x0e5a44: A91463FC  stp      x28, x24, [sp, #0x140]
//   0x0e5a48: A9155BF7  stp      x23, x22, [sp, #0x150]
//   0x0e5a4c: A91653F5  stp      x21, x20, [sp, #0x160]
static inline uint64_t fde_func_0572_0x0e5a40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5a40ULL ^ (static_cast<uint64_t>(0xd10603ffULL) << 13);
    acc = (acc + a1 + 0xa91463fcULL) ^ 0x076fb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0573 | PC: 0x0e5e18 | FDE: 0x077038 | Size: 112 bytes
// Khung tháo gỡ #0573 | Địa chỉ PC: 0x0e5e18 | Địa chỉ FDE: 0x077038 | Kích thước: 112 bytes
//   0x0e5e18: 17FFFF77  b        #0xe5bf4
//   0x0e5e1c: D10583FF  sub      sp, sp, #0x160
//   0x0e5e20: F9009BFC  str      x28, [sp, #0x130]
//   0x0e5e24: A91453F5  stp      x21, x20, [sp, #0x140]
static inline uint64_t fde_func_0573_0x0e5e18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5e18ULL ^ (static_cast<uint64_t>(0x17ffff77ULL) << 13);
    acc = (acc + a1 + 0xd10583ffULL) ^ 0x077038ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0574 | PC: 0x0e5e88 | FDE: 0x077070 | Size: 128 bytes [_ZN4lynx6canvas24GLSurfaceWithFrameBufferC2ENS_4base15MoveOnlyClosureINSt6__ndk110unique_ptrINS1_11WriteBufferENS4_14default_deleteIS6_EEEEJEEEiib]
// Khung tháo gỡ #0574 | Địa chỉ PC: 0x0e5e88 | Địa chỉ FDE: 0x077070 | Kích thước: 128 bytes
//   0x0e5e88: D10583FF  sub      sp, sp, #0x160
//   0x0e5e8c: F9009BFC  str      x28, [sp, #0x130]
//   0x0e5e90: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0e5e94: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0574_0x0e5e88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5e88ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x077070ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0575 | PC: 0x0e5f08 | FDE: 0x077090 | Size: 100 bytes [_ZN4lynx6canvas24GLSurfaceWithFrameBufferD2Ev]
// Khung tháo gỡ #0575 | Địa chỉ PC: 0x0e5f08 | Địa chỉ FDE: 0x077090 | Kích thước: 100 bytes
//   0x0e5f08: D10583FF  sub      sp, sp, #0x160
//   0x0e5f0c: F9009BFC  str      x28, [sp, #0x130]
//   0x0e5f10: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0e5f14: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0575_0x0e5f08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5f08ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x077090ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0576 | PC: 0x0e5f6c | FDE: 0x0770b0 | Size: 256 bytes [_ZN4lynx6canvas24GLSurfaceWithFrameBufferD0Ev]
// Khung tháo gỡ #0576 | Địa chỉ PC: 0x0e5f6c | Địa chỉ FDE: 0x0770b0 | Kích thước: 256 bytes
//   0x0e5f6c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e5f70: AA0003F3  mov      x19, x0
//   0x0e5f74: 94028B53  bl       #0x188cc0
//   0x0e5f78: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0576_0x0e5f6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5f6cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0770b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0577 | PC: 0x0e6140 | FDE: 0x077128 | Size: 256 bytes
// Khung tháo gỡ #0577 | Địa chỉ PC: 0x0e6140 | Địa chỉ FDE: 0x077128 | Kích thước: 256 bytes
//   0x0e6140: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e6144: AA0003F3  mov      x19, x0
//   0x0e6148: 97FFFFE0  bl       #0xe60c8
//   0x0e614c: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0577_0x0e6140(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6140ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x077128ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0578 | PC: 0x0e62c0 | FDE: 0x077198 | Size: 48 bytes
// Khung tháo gỡ #0578 | Địa chỉ PC: 0x0e62c0 | Địa chỉ FDE: 0x077198 | Kích thước: 48 bytes
//   0x0e62c0: F9402408  ldr      x8, [x0, #0x48]
//   0x0e62c4: B4000048  cbz      x8, #0xe62cc
//   0x0e62c8: 14027931  b        #0x18478c
//   0x0e62cc: 14023DEB  b        #0x175a78
static inline uint64_t fde_func_0578_0x0e62c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e62c0ULL ^ (static_cast<uint64_t>(0xf9402408ULL) << 13);
    acc = (acc + a1 + 0xb4000048ULL) ^ 0x077198ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0579 | PC: 0x0e62f0 | FDE: 0x0771c8 | Size: 124 bytes [_ZN4lynx6canvas27GLSurfaceGraphicsContextEGLC2Ev]
// Khung tháo gỡ #0579 | Địa chỉ PC: 0x0e62f0 | Địa chỉ FDE: 0x0771c8 | Kích thước: 124 bytes
//   0x0e62f0: D10583FF  sub      sp, sp, #0x160
//   0x0e62f4: F9009BFC  str      x28, [sp, #0x130]
//   0x0e62f8: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0e62fc: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0579_0x0e62f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e62f0ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x0771c8ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0580 | PC: 0x0e636c | FDE: 0x0771e8 | Size: 116 bytes [_ZN4lynx6canvas27GLSurfaceGraphicsContextEGLD2Ev]
// Khung tháo gỡ #0580 | Địa chỉ PC: 0x0e636c | Địa chỉ FDE: 0x0771e8 | Kích thước: 116 bytes
//   0x0e636c: D10583FF  sub      sp, sp, #0x160
//   0x0e6370: F9009BFC  str      x28, [sp, #0x130]
//   0x0e6374: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0e6378: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0580_0x0e636c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e636cULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x0771e8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0581 | PC: 0x0e63e0 | FDE: 0x077208 | Size: 8 bytes [_ZNK4lynx6canvas27GLSurfaceGraphicsContextEGL5ValidEv]
// Khung tháo gỡ #0581 | Địa chỉ PC: 0x0e63e0 | Địa chỉ FDE: 0x077208 | Kích thước: 8 bytes
//   0x0e63e0: 39404000  ldrb     w0, [x0, #0x10]
//   0x0e63e4: D65F03C0  ret      
static inline uint64_t fde_func_0581_0x0e63e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e63e0ULL ^ (static_cast<uint64_t>(0x39404000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x077208ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0582 | PC: 0x0e63e8 | FDE: 0x077220 | Size: 108 bytes [_ZNK4lynx6canvas27GLSurfaceGraphicsContextEGL5WidthEv]
// Khung tháo gỡ #0582 | Địa chỉ PC: 0x0e63e8 | Địa chỉ FDE: 0x077220 | Kích thước: 108 bytes
//   0x0e63e8: D10543FF  sub      sp, sp, #0x150
//   0x0e63ec: A91353FC  stp      x28, x20, [sp, #0x130]
//   0x0e63f0: A9147BF3  stp      x19, x30, [sp, #0x140]
//   0x0e63f4: 94024F79  bl       #0x17a1d8
static inline uint64_t fde_func_0582_0x0e63e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e63e8ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa91353fcULL) ^ 0x077220ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0583 | PC: 0x0e6454 | FDE: 0x077240 | Size: 108 bytes [_ZNK4lynx6canvas27GLSurfaceGraphicsContextEGL6HeightEv]
// Khung tháo gỡ #0583 | Địa chỉ PC: 0x0e6454 | Địa chỉ FDE: 0x077240 | Kích thước: 108 bytes
//   0x0e6454: D10543FF  sub      sp, sp, #0x150
//   0x0e6458: A91353FC  stp      x28, x20, [sp, #0x130]
//   0x0e645c: A9147BF3  stp      x19, x30, [sp, #0x140]
//   0x0e6460: 94024F5E  bl       #0x17a1d8
static inline uint64_t fde_func_0583_0x0e6454(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6454ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa91353fcULL) ^ 0x077240ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0584 | PC: 0x0e64c0 | FDE: 0x077260 | Size: 244 bytes [_ZN4lynx6canvas27GLSurfaceGraphicsContextEGL6ResizeEii]
// Khung tháo gỡ #0584 | Địa chỉ PC: 0x0e64c0 | Địa chỉ FDE: 0x077260 | Kích thước: 244 bytes
//   0x0e64c0: AA1E03E3  mov      x3, x30
//   0x0e64c4: 940248A7  bl       #0x178760
//   0x0e64c8: AA0303FE  mov      x30, x3
//   0x0e64cc: A9167BF3  stp      x19, x30, [sp, #0x160]
static inline uint64_t fde_func_0584_0x0e64c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e64c0ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x940248a7ULL) ^ 0x077260ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #0585 | PC: 0x0e65b4 | FDE: 0x077288 | Size: 104 bytes [_ZN4lynx6canvas27GLSurfaceGraphicsContextEGL9GLPresentEv]
// Khung tháo gỡ #0585 | Địa chỉ PC: 0x0e65b4 | Địa chỉ FDE: 0x077288 | Kích thước: 104 bytes
//   0x0e65b4: D10543FF  sub      sp, sp, #0x150
//   0x0e65b8: A91353FC  stp      x28, x20, [sp, #0x130]
//   0x0e65bc: A9147BF3  stp      x19, x30, [sp, #0x140]
//   0x0e65c0: 94024F06  bl       #0x17a1d8
static inline uint64_t fde_func_0585_0x0e65b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e65b4ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa91353fcULL) ^ 0x077288ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0586 | PC: 0x0e661c | FDE: 0x0772a8 | Size: 248 bytes [_ZN4lynx6canvas27GLSurfaceGraphicsContextEGL22ChooseEGLConfigurationEPvRKNS1_16EGLSurfaceConfigE]
// Khung tháo gỡ #0586 | Địa chỉ PC: 0x0e661c | Địa chỉ FDE: 0x0772a8 | Kích thước: 248 bytes
//   0x0e661c: D10203FF  sub      sp, sp, #0x80
//   0x0e6620: A9077BF3  stp      x19, x30, [sp, #0x70]
//   0x0e6624: D53BD053  mrs      x19, tpidr_el0
//   0x0e6628: B0FFFA28  adrp     x8, #0x2b000
static inline uint64_t fde_func_0586_0x0e661c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e661cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9077bf3ULL) ^ 0x0772a8ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0587 | PC: 0x0e6714 | FDE: 0x0772c8 | Size: 32 bytes [_ZN4lynx6canvas11FramebufferC1Ejj]
// Khung tháo gỡ #0587 | Địa chỉ PC: 0x0e6714 | Địa chỉ FDE: 0x0772c8 | Kích thước: 32 bytes
//   0x0e6714: B0FFFA28  adrp     x8, #0x2b000
//   0x0e6718: 3DC2E500  ldr      q0, [x8, #0xb90]
//   0x0e671c: 52828028  mov      w8, #0x1401
//   0x0e6720: 29000801  stp      w1, w2, [x0]
static inline uint64_t fde_func_0587_0x0e6714(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6714ULL ^ (static_cast<uint64_t>(0xb0fffa28ULL) << 13);
    acc = (acc + a1 + 0x3dc2e500ULL) ^ 0x0772c8ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0588 | PC: 0x0e6734 | FDE: 0x0772e0 | Size: 36 bytes [_ZN4lynx6canvas11FramebufferC2Ej]
// Khung tháo gỡ #0588 | Địa chỉ PC: 0x0e6734 | Địa chỉ FDE: 0x0772e0 | Kích thước: 36 bytes
//   0x0e6734: 52832108  mov      w8, #0x1908
//   0x0e6738: 52828029  mov      w9, #0x1401
//   0x0e673c: 0E040D00  dup      v0.2s, w8
//   0x0e6740: F900001F  str      xzr, [x0]
static inline uint64_t fde_func_0588_0x0e6734(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6734ULL ^ (static_cast<uint64_t>(0x52832108ULL) << 13);
    acc = (acc + a1 + 0x52828029ULL) ^ 0x0772e0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0589 | PC: 0x0e6758 | FDE: 0x0772f8 | Size: 60 bytes [_ZN4lynx6canvas11FramebufferD2Ev]
// Khung tháo gỡ #0589 | Địa chỉ PC: 0x0e6758 | Địa chỉ FDE: 0x0772f8 | Kích thước: 60 bytes
//   0x0e6758: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e675c: AA0003F3  mov      x19, x0
//   0x0e6760: B8408C08  ldr      w8, [x0, #8]!
//   0x0e6764: 34000048  cbz      w8, #0xe676c
static inline uint64_t fde_func_0589_0x0e6758(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6758ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0772f8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0590 | PC: 0x0e6794 | FDE: 0x077310 | Size: 256 bytes [_ZN4lynx6canvas11Framebuffer15InitOnGPUIfNeedEi]
// Khung tháo gỡ #0590 | Địa chỉ PC: 0x0e6794 | Địa chỉ FDE: 0x077310 | Kích thước: 256 bytes
//   0x0e6794: D107C3FF  sub      sp, sp, #0x1f0
//   0x0e6798: A91A6BFC  stp      x28, x26, [sp, #0x1a0]
//   0x0e679c: A91B63F9  stp      x25, x24, [sp, #0x1b0]
//   0x0e67a0: A91C5BF7  stp      x23, x22, [sp, #0x1c0]
static inline uint64_t fde_func_0590_0x0e6794(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6794ULL ^ (static_cast<uint64_t>(0xd107c3ffULL) << 13);
    acc = (acc + a1 + 0xa91a6bfcULL) ^ 0x077310ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0591 | PC: 0x0e69c8 | FDE: 0x077370 | Size: 88 bytes
// Khung tháo gỡ #0591 | Địa chỉ PC: 0x0e69c8 | Địa chỉ FDE: 0x077370 | Kích thước: 88 bytes
//   0x0e69c8: AA0003E1  mov      x1, x0
//   0x0e69cc: 52800020  mov      w0, #1
//   0x0e69d0: 140288D8  b        #0x188d30
//   0x0e69d4: AA0003E1  mov      x1, x0
static inline uint64_t fde_func_0591_0x0e69c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e69c8ULL ^ (static_cast<uint64_t>(0xaa0003e1ULL) << 13);
    acc = (acc + a1 + 0x52800020ULL) ^ 0x077370ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0592 | PC: 0x0e6a20 | FDE: 0x0773d0 | Size: 136 bytes
// Khung tháo gỡ #0592 | Địa chỉ PC: 0x0e6a20 | Địa chỉ FDE: 0x0773d0 | Kích thước: 136 bytes
//   0x0e6a20: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e6a24: 7100081F  cmp      w0, #2
//   0x0e6a28: 54000200  b.eq     #0xe6a68
//   0x0e6a2c: 350002A0  cbnz     w0, #0xe6a80
static inline uint64_t fde_func_0592_0x0e6a20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6a20ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x7100081fULL) ^ 0x0773d0ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0593 | PC: 0x0e6aa8 | FDE: 0x077430 | Size: 56 bytes
// Khung tháo gỡ #0593 | Địa chỉ PC: 0x0e6aa8 | Địa chỉ FDE: 0x077430 | Kích thước: 56 bytes
//   0x0e6aa8: AA0003E1  mov      x1, x0
//   0x0e6aac: 52800020  mov      w0, #1
//   0x0e6ab0: 140288BC  b        #0x188da0
//   0x0e6ab4: AA0003E1  mov      x1, x0
static inline uint64_t fde_func_0593_0x0e6aa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6aa8ULL ^ (static_cast<uint64_t>(0xaa0003e1ULL) << 13);
    acc = (acc + a1 + 0x52800020ULL) ^ 0x077430ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0594 | PC: 0x0e6ae0 | FDE: 0x077490 | Size: 164 bytes
// Khung tháo gỡ #0594 | Địa chỉ PC: 0x0e6ae0 | Địa chỉ FDE: 0x077490 | Kích thước: 164 bytes
//   0x0e6ae0: 92800002  mov      x2, #-1
//   0x0e6ae4: 2A1F03E1  mov      w1, wzr
//   0x0e6ae8: 140288BE  b        #0x188de0
//   0x0e6aec: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
static inline uint64_t fde_func_0594_0x0e6ae0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6ae0ULL ^ (static_cast<uint64_t>(0x92800002ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e1ULL) ^ 0x077490ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0595 | PC: 0x0e6b84 | FDE: 0x0774f0 | Size: 256 bytes
// Khung tháo gỡ #0595 | Địa chỉ PC: 0x0e6b84 | Địa chỉ FDE: 0x0774f0 | Kích thước: 256 bytes
//   0x0e6b84: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0e6b88: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e6b8c: 39400008  ldrb     w8, [x0]
//   0x0e6b90: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0595_0x0e6b84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6b84ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0774f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0596 | PC: 0x0e6e3c | FDE: 0x077580 | Size: 256 bytes
// Khung tháo gỡ #0596 | Địa chỉ PC: 0x0e6e3c | Địa chỉ FDE: 0x077580 | Kích thước: 256 bytes
//   0x0e6e3c: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0e6e40: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0e6e44: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0e6e48: 94027532  bl       #0x184310
static inline uint64_t fde_func_0596_0x0e6e3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6e3cULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x077580ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0597 | PC: 0x0e6f6c | FDE: 0x077600 | Size: 256 bytes
// Khung tháo gỡ #0597 | Địa chỉ PC: 0x0e6f6c | Địa chỉ FDE: 0x077600 | Kích thước: 256 bytes
//   0x0e6f6c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e6f70: 940242D6  bl       #0x177ac8
//   0x0e6f74: B40000F3  cbz      x19, #0xe6f90
//   0x0e6f78: 39404008  ldrb     w8, [x0, #0x10]
static inline uint64_t fde_func_0597_0x0e6f6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6f6cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x940242d6ULL) ^ 0x077600ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0598 | PC: 0x0e70e0 | FDE: 0x077680 | Size: 256 bytes
// Khung tháo gỡ #0598 | Địa chỉ PC: 0x0e70e0 | Địa chỉ FDE: 0x077680 | Kích thước: 256 bytes
//   0x0e70e0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e70e4: 94024279  bl       #0x177ac8
//   0x0e70e8: B4000113  cbz      x19, #0xe7108
//   0x0e70ec: 39404008  ldrb     w8, [x0, #0x10]
static inline uint64_t fde_func_0598_0x0e70e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e70e0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94024279ULL) ^ 0x077680ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0599 | PC: 0x0e721c | FDE: 0x0776c8 | Size: 172 bytes [_ZN4lynx6canvas24GLGlobalDeviceAttributesC1Ev]
// Khung tháo gỡ #0599 | Địa chỉ PC: 0x0e721c | Địa chỉ FDE: 0x0776c8 | Kích thước: 172 bytes
//   0x0e721c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e7220: 6F00E400  movi     v0.2d, #0000000000000000
//   0x0e7224: AD000000  stp      q0, q0, [x0]
//   0x0e7228: 4F07F600  fmov     v0.4s, #-1.00000000
static inline uint64_t fde_func_0599_0x0e721c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e721cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x6f00e400ULL) ^ 0x0776c8ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0600 | PC: 0x0e72c8 | FDE: 0x0776e0 | Size: 88 bytes [_ZN4lynx6canvas24GLGlobalDeviceAttributes8InstanceEv]
// Khung tháo gỡ #0600 | Địa chỉ PC: 0x0e72c8 | Địa chỉ FDE: 0x0776e0 | Kích thước: 88 bytes
//   0x0e72c8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0e72cc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e72d0: D0000588  adrp     x8, #0x199000
//   0x0e72d4: 911E2108  add      x8, x8, #0x788
static inline uint64_t fde_func_0600_0x0e72c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e72c8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0776e0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0601 | PC: 0x0e7320 | FDE: 0x077700 | Size: 256 bytes [_ZN4lynx6canvas24GLGlobalDeviceAttributes9InitOnGPUEv]
// Khung tháo gỡ #0601 | Địa chỉ PC: 0x0e7320 | Địa chỉ FDE: 0x077700 | Kích thước: 256 bytes
//   0x0e7320: D10703FF  sub      sp, sp, #0x1c0
//   0x0e7324: A9176BFC  stp      x28, x26, [sp, #0x170]
//   0x0e7328: A91863F9  stp      x25, x24, [sp, #0x180]
//   0x0e732c: A9195BF7  stp      x23, x22, [sp, #0x190]
static inline uint64_t fde_func_0601_0x0e7320(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7320ULL ^ (static_cast<uint64_t>(0xd10703ffULL) << 13);
    acc = (acc + a1 + 0xa9176bfcULL) ^ 0x077700ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0602 | PC: 0x0e7e7c | FDE: 0x077730 | Size: 32 bytes [_ZN4lynx6canvas24GLGlobalDeviceAttributes6InitedEv]
// Khung tháo gỡ #0602 | Địa chỉ PC: 0x0e7e7c | Địa chỉ FDE: 0x077730 | Kích thước: 32 bytes
//   0x0e7e7c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0e7e80: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e7e84: 94024BE7  bl       #0x17ae20
//   0x0e7e88: 39490274  ldrb     w20, [x19, #0x240]
static inline uint64_t fde_func_0602_0x0e7e7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7e7cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x077730ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0603 | PC: 0x0e7e9c | FDE: 0x077750 | Size: 32 bytes [_ZN4lynx6canvas24GLGlobalDeviceAttributes5ValidEv]
// Khung tháo gỡ #0603 | Địa chỉ PC: 0x0e7e9c | Địa chỉ FDE: 0x077750 | Kích thước: 32 bytes
//   0x0e7e9c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0e7ea0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e7ea4: 94024BDF  bl       #0x17ae20
//   0x0e7ea8: 39490674  ldrb     w20, [x19, #0x241]
static inline uint64_t fde_func_0603_0x0e7e9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7e9cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x077750ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0604 | PC: 0x0e7ebc | FDE: 0x077770 | Size: 56 bytes [_ZN4lynx6canvas24GLGlobalDeviceAttributes15InitedButFailedEv]
// Khung tháo gỡ #0604 | Địa chỉ PC: 0x0e7ebc | Địa chỉ FDE: 0x077770 | Kích thước: 56 bytes
//   0x0e7ebc: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0e7ec0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e7ec4: 94024BD7  bl       #0x17ae20
//   0x0e7ec8: 39490268  ldrb     w8, [x19, #0x240]
static inline uint64_t fde_func_0604_0x0e7ebc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7ebcULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x077770ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0605 | PC: 0x0e7ef4 | FDE: 0x077790 | Size: 256 bytes [_ZN4lynx6canvas24GLGlobalDeviceAttributes19GetDeviceAttributesEv]
// Khung tháo gỡ #0605 | Địa chỉ PC: 0x0e7ef4 | Địa chỉ FDE: 0x077790 | Kích thước: 256 bytes
//   0x0e7ef4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0e7ef8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e7efc: AA0003F3  mov      x19, x0
//   0x0e7f00: AA0803F4  mov      x20, x8
static inline uint64_t fde_func_0605_0x0e7ef4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7ef4ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x077790ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0606 | PC: 0x0e808c | FDE: 0x0777d8 | Size: 36 bytes [_ZN4lynx6canvas24GLGlobalDeviceAttributes22GetDeviceAttributesRefEv]
// Khung tháo gỡ #0606 | Địa chỉ PC: 0x0e808c | Địa chỉ FDE: 0x0777d8 | Kích thước: 36 bytes
//   0x0e808c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0e8090: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e8094: 94024B63  bl       #0x17ae20
//   0x0e8098: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0606_0x0e808c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e808cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0777d8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0607 | PC: 0x0e80b0 | FDE: 0x0777f8 | Size: 256 bytes
// Khung tháo gỡ #0607 | Địa chỉ PC: 0x0e80b0 | Địa chỉ FDE: 0x0777f8 | Kích thước: 256 bytes
//   0x0e80b0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e80b4: B0000588  adrp     x8, #0x199000
//   0x0e80b8: 911E6108  add      x8, x8, #0x798
//   0x0e80bc: 08DFFD08  ldarb    w8, [x8]
static inline uint64_t fde_func_0607_0x0e80b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e80b0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb0000588ULL) ^ 0x0777f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0608 | PC: 0x0e82e8 | FDE: 0x077870 | Size: 256 bytes
// Khung tháo gỡ #0608 | Địa chỉ PC: 0x0e82e8 | Địa chỉ FDE: 0x077870 | Kích thước: 256 bytes
//   0x0e82e8: 2A1F03E2  mov      w2, wzr
//   0x0e82ec: 17FFFF83  b        #0xe80f8
//   0x0e82f0: 14028218  b        #0x188b50
//   0x0e82f4: AA1E03E2  mov      x2, x30
static inline uint64_t fde_func_0608_0x0e82e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e82e8ULL ^ (static_cast<uint64_t>(0x2a1f03e2ULL) << 13);
    acc = (acc + a1 + 0x17ffff83ULL) ^ 0x077870ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0609 | PC: 0x0e85d0 | FDE: 0x0778e0 | Size: 236 bytes
// Khung tháo gỡ #0609 | Địa chỉ PC: 0x0e85d0 | Địa chỉ FDE: 0x0778e0 | Kích thước: 236 bytes
//   0x0e85d0: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0e85d4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e85d8: AA0003F3  mov      x19, x0
//   0x0e85dc: B4000261  cbz      x1, #0xe8628
static inline uint64_t fde_func_0609_0x0e85d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e85d0ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0778e0ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0610 | PC: 0x0e86bc | FDE: 0x077918 | Size: 164 bytes [_ZN4lynx6canvas9GLTextureC1Ejj]
// Khung tháo gỡ #0610 | Địa chỉ PC: 0x0e86bc | Địa chỉ FDE: 0x077918 | Kích thước: 164 bytes
//   0x0e86bc: D101C3FF  sub      sp, sp, #0x70
//   0x0e86c0: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x0e86c4: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x0e86c8: D53BD055  mrs      x21, tpidr_el0
static inline uint64_t fde_func_0610_0x0e86bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e86bcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90553f5ULL) ^ 0x077918ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0611 | PC: 0x0e8760 | FDE: 0x077938 | Size: 24 bytes [_ZN4lynx6canvas9GLTextureD2Ev]
// Khung tháo gỡ #0611 | Địa chỉ PC: 0x0e8760 | Địa chỉ FDE: 0x077938 | Kích thước: 24 bytes
//   0x0e8760: AA0003E1  mov      x1, x0
//   0x0e8764: B8408C28  ldr      w8, [x1, #8]!
//   0x0e8768: 34000068  cbz      w8, #0xe8774
//   0x0e876c: 52800020  mov      w0, #1
static inline uint64_t fde_func_0611_0x0e8760(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8760ULL ^ (static_cast<uint64_t>(0xaa0003e1ULL) << 13);
    acc = (acc + a1 + 0xb8408c28ULL) ^ 0x077938ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0612 | PC: 0x0e8778 | FDE: 0x077950 | Size: 256 bytes
// Khung tháo gỡ #0612 | Địa chỉ PC: 0x0e8778 | Địa chỉ FDE: 0x077950 | Kích thước: 256 bytes
//   0x0e8778: D10583FF  sub      sp, sp, #0x160
//   0x0e877c: F9009BFC  str      x28, [sp, #0x130]
//   0x0e8780: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0e8784: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0612_0x0e8778(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8778ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x077950ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0613 | PC: 0x0e8d90 | FDE: 0x0779d0 | Size: 256 bytes
// Khung tháo gỡ #0613 | Địa chỉ PC: 0x0e8d90 | Địa chỉ FDE: 0x0779d0 | Kích thước: 256 bytes
//   0x0e8d90: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0e8d94: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e8d98: 940261C7  bl       #0x1814b4
//   0x0e8d9c: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0613_0x0e8d90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8d90ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0779d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0614 | PC: 0x0e92a4 | FDE: 0x077a58 | Size: 256 bytes
// Khung tháo gỡ #0614 | Địa chỉ PC: 0x0e92a4 | Địa chỉ FDE: 0x077a58 | Kích thước: 256 bytes
//   0x0e92a4: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0e92a8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e92ac: 94026BD0  bl       #0x1841ec
//   0x0e92b0: 54000061  b.ne     #0xe92bc
static inline uint64_t fde_func_0614_0x0e92a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e92a4ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x077a58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0615 | PC: 0x0e951c | FDE: 0x077ad0 | Size: 116 bytes
// Khung tháo gỡ #0615 | Địa chỉ PC: 0x0e951c | Địa chỉ FDE: 0x077ad0 | Kích thước: 116 bytes
//   0x0e951c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e9520: B8408428  ldr      w8, [x1], #8
//   0x0e9524: AA0003F3  mov      x19, x0
//   0x0e9528: B8008408  str      w8, [x0], #8
static inline uint64_t fde_func_0615_0x0e951c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e951cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb8408428ULL) ^ 0x077ad0ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0616 | PC: 0x0e9590 | FDE: 0x077b30 | Size: 68 bytes
// Khung tháo gỡ #0616 | Địa chỉ PC: 0x0e9590 | Địa chỉ FDE: 0x077b30 | Kích thước: 68 bytes
//   0x0e9590: F9400008  ldr      x8, [x0]
//   0x0e9594: F85E8108  ldur     x8, [x8, #-0x18]
//   0x0e9598: 8B080008  add      x8, x0, x8
//   0x0e959c: 91004100  add      x0, x8, #0x10
static inline uint64_t fde_func_0616_0x0e9590(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9590ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf85e8108ULL) ^ 0x077b30ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0617 | PC: 0x0e95d4 | FDE: 0x077b90 | Size: 68 bytes
// Khung tháo gỡ #0617 | Địa chỉ PC: 0x0e95d4 | Địa chỉ FDE: 0x077b90 | Kích thước: 68 bytes
//   0x0e95d4: D1004000  sub      x0, x0, #0x10
//   0x0e95d8: 17FFFFF9  b        #0xe95bc
//   0x0e95dc: F9400008  ldr      x8, [x0]
//   0x0e95e0: F85E8108  ldur     x8, [x8, #-0x18]
static inline uint64_t fde_func_0617_0x0e95d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e95d4ULL ^ (static_cast<uint64_t>(0xd1004000ULL) << 13);
    acc = (acc + a1 + 0x17fffff9ULL) ^ 0x077b90ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0618 | PC: 0x0e9618 | FDE: 0x077bf0 | Size: 48 bytes
// Khung tháo gỡ #0618 | Địa chỉ PC: 0x0e9618 | Địa chỉ FDE: 0x077bf0 | Kích thước: 48 bytes
//   0x0e9618: D1004000  sub      x0, x0, #0x10
//   0x0e961c: 17FFFFC8  b        #0xe953c
//   0x0e9620: D1004000  sub      x0, x0, #0x10
//   0x0e9624: 17FFFFF7  b        #0xe9600
static inline uint64_t fde_func_0618_0x0e9618(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9618ULL ^ (static_cast<uint64_t>(0xd1004000ULL) << 13);
    acc = (acc + a1 + 0x17ffffc8ULL) ^ 0x077bf0ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0619 | PC: 0x0e9648 | FDE: 0x077c50 | Size: 256 bytes
// Khung tháo gỡ #0619 | Địa chỉ PC: 0x0e9648 | Địa chỉ FDE: 0x077c50 | Kích thước: 256 bytes
//   0x0e9648: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0e964c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0e9650: D0000528  adrp     x8, #0x18f000
//   0x0e9654: 9123A108  add      x8, x8, #0x8e8
static inline uint64_t fde_func_0619_0x0e9648(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9648ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x077c50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0620 | PC: 0x0e9c24 | FDE: 0x077cc8 | Size: 68 bytes
// Khung tháo gỡ #0620 | Địa chỉ PC: 0x0e9c24 | Địa chỉ FDE: 0x077cc8 | Kích thước: 68 bytes
//   0x0e9c24: D0000528  adrp     x8, #0x18f000
//   0x0e9c28: 913D8108  add      x8, x8, #0xf60
//   0x0e9c2c: 14023201  b        #0x176430
//   0x0e9c30: B9400801  ldr      w1, [x0, #8]
static inline uint64_t fde_func_0620_0x0e9c24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9c24ULL ^ (static_cast<uint64_t>(0xd0000528ULL) << 13);
    acc = (acc + a1 + 0x913d8108ULL) ^ 0x077cc8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0621 | PC: 0x0e9c68 | FDE: 0x077d28 | Size: 68 bytes
// Khung tháo gỡ #0621 | Địa chỉ PC: 0x0e9c68 | Địa chỉ FDE: 0x077d28 | Kích thước: 68 bytes
//   0x0e9c68: B9400801  ldr      w1, [x0, #8]
//   0x0e9c6c: 5281A040  mov      w0, #0xd02
//   0x0e9c70: 14027758  b        #0x1879d0
//   0x0e9c74: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
static inline uint64_t fde_func_0621_0x0e9c68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9c68ULL ^ (static_cast<uint64_t>(0xb9400801ULL) << 13);
    acc = (acc + a1 + 0x5281a040ULL) ^ 0x077d28ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0622 | PC: 0x0e9cac | FDE: 0x077d88 | Size: 88 bytes
// Khung tháo gỡ #0622 | Địa chỉ PC: 0x0e9cac | Địa chỉ FDE: 0x077d88 | Kích thước: 88 bytes
//   0x0e9cac: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e9cb0: AA0003F3  mov      x19, x0
//   0x0e9cb4: 94022F6D  bl       #0x175a68
//   0x0e9cb8: D0000528  adrp     x8, #0x18f000
static inline uint64_t fde_func_0622_0x0e9cac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9cacULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x077d88ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0623 | PC: 0x0e9d04 | FDE: 0x077de8 | Size: 72 bytes
// Khung tháo gỡ #0623 | Địa chỉ PC: 0x0e9d04 | Địa chỉ FDE: 0x077de8 | Kích thước: 72 bytes
//   0x0e9d04: D0000528  adrp     x8, #0x18f000
//   0x0e9d08: 91390108  add      x8, x8, #0xe40
//   0x0e9d0c: 14023FD4  b        #0x179c5c
//   0x0e9d10: 29410808  ldp      w8, w2, [x0, #8]
static inline uint64_t fde_func_0623_0x0e9d04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9d04ULL ^ (static_cast<uint64_t>(0xd0000528ULL) << 13);
    acc = (acc + a1 + 0x91390108ULL) ^ 0x077de8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0624 | PC: 0x0e9d4c | FDE: 0x077e48 | Size: 68 bytes
// Khung tháo gỡ #0624 | Địa chỉ PC: 0x0e9d4c | Địa chỉ FDE: 0x077e48 | Kích thước: 68 bytes
//   0x0e9d4c: 29412000  ldp      w0, w8, [x0, #8]
//   0x0e9d50: 34000048  cbz      w8, #0xe9d58
//   0x0e9d54: 1402776B  b        #0x187b00
//   0x0e9d58: 14027B32  b        #0x188a20
static inline uint64_t fde_func_0624_0x0e9d4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9d4cULL ^ (static_cast<uint64_t>(0x29412000ULL) << 13);
    acc = (acc + a1 + 0x34000048ULL) ^ 0x077e48ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0625 | PC: 0x0e9d90 | FDE: 0x077ea8 | Size: 104 bytes
// Khung tháo gỡ #0625 | Địa chỉ PC: 0x0e9d90 | Địa chỉ FDE: 0x077ea8 | Kích thước: 104 bytes
//   0x0e9d90: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e9d94: AA0003F3  mov      x19, x0
//   0x0e9d98: 94022F34  bl       #0x175a68
//   0x0e9d9c: D0000528  adrp     x8, #0x18f000
static inline uint64_t fde_func_0625_0x0e9d90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9d90ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x077ea8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0626 | PC: 0x0e9df8 | FDE: 0x077f08 | Size: 76 bytes
// Khung tháo gỡ #0626 | Địa chỉ PC: 0x0e9df8 | Địa chỉ FDE: 0x077f08 | Kích thước: 76 bytes
//   0x0e9df8: D0000528  adrp     x8, #0x18f000
//   0x0e9dfc: 91348108  add      x8, x8, #0xd20
//   0x0e9e00: F9000028  str      x8, [x1]
//   0x0e9e04: 39402008  ldrb     w8, [x0, #8]
static inline uint64_t fde_func_0626_0x0e9df8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9df8ULL ^ (static_cast<uint64_t>(0xd0000528ULL) << 13);
    acc = (acc + a1 + 0x91348108ULL) ^ 0x077f08ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0627 | PC: 0x0e9e44 | FDE: 0x077f68 | Size: 60 bytes
// Khung tháo gỡ #0627 | Địa chỉ PC: 0x0e9e44 | Địa chỉ FDE: 0x077f68 | Kích thước: 60 bytes
//   0x0e9e44: BD400800  ldr      s0, [x0, #8]
//   0x0e9e48: 140279DA  b        #0x1885b0
//   0x0e9e4c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e9e50: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0627_0x0e9e44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9e44ULL ^ (static_cast<uint64_t>(0xbd400800ULL) << 13);
    acc = (acc + a1 + 0x140279daULL) ^ 0x077f68ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0628 | PC: 0x0e9e80 | FDE: 0x077fc8 | Size: 88 bytes
// Khung tháo gỡ #0628 | Địa chỉ PC: 0x0e9e80 | Địa chỉ FDE: 0x077fc8 | Kích thước: 88 bytes
//   0x0e9e80: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e9e84: AA0003F3  mov      x19, x0
//   0x0e9e88: 9402376E  bl       #0x177c40
//   0x0e9e8c: D0000528  adrp     x8, #0x18f000
static inline uint64_t fde_func_0628_0x0e9e80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9e80ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x077fc8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0629 | PC: 0x0e9ed8 | FDE: 0x078028 | Size: 72 bytes
// Khung tháo gỡ #0629 | Địa chỉ PC: 0x0e9ed8 | Địa chỉ FDE: 0x078028 | Kích thước: 72 bytes
//   0x0e9ed8: D0000528  adrp     x8, #0x18f000
//   0x0e9edc: 91300108  add      x8, x8, #0xc00
//   0x0e9ee0: 14023F5F  b        #0x179c5c
//   0x0e9ee4: 29410408  ldp      w8, w1, [x0, #8]
static inline uint64_t fde_func_0629_0x0e9ed8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9ed8ULL ^ (static_cast<uint64_t>(0xd0000528ULL) << 13);
    acc = (acc + a1 + 0x91300108ULL) ^ 0x078028ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0630 | PC: 0x0e9f20 | FDE: 0x078088 | Size: 64 bytes
// Khung tháo gỡ #0630 | Địa chỉ PC: 0x0e9f20 | Địa chỉ FDE: 0x078088 | Kích thước: 64 bytes
//   0x0e9f20: B9400800  ldr      w0, [x0, #8]
//   0x0e9f24: 140279AB  b        #0x1885d0
//   0x0e9f28: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e9f2c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0630_0x0e9f20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9f20ULL ^ (static_cast<uint64_t>(0xb9400800ULL) << 13);
    acc = (acc + a1 + 0x140279abULL) ^ 0x078088ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0631 | PC: 0x0e9f60 | FDE: 0x0780e8 | Size: 88 bytes
// Khung tháo gỡ #0631 | Địa chỉ PC: 0x0e9f60 | Địa chỉ FDE: 0x0780e8 | Kích thước: 88 bytes
//   0x0e9f60: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0e9f64: AA0003F3  mov      x19, x0
//   0x0e9f68: 94022EC0  bl       #0x175a68
//   0x0e9f6c: D0000528  adrp     x8, #0x18f000
static inline uint64_t fde_func_0631_0x0e9f60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9f60ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0780e8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0632 | PC: 0x0e9fb8 | FDE: 0x078148 | Size: 64 bytes
// Khung tháo gỡ #0632 | Địa chỉ PC: 0x0e9fb8 | Địa chỉ FDE: 0x078148 | Kích thước: 64 bytes
//   0x0e9fb8: D0000528  adrp     x8, #0x18f000
//   0x0e9fbc: 912B8108  add      x8, x8, #0xae0
//   0x0e9fc0: 1402311C  b        #0x176430
//   0x0e9fc4: B9400800  ldr      w0, [x0, #8]
static inline uint64_t fde_func_0632_0x0e9fb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9fb8ULL ^ (static_cast<uint64_t>(0xd0000528ULL) << 13);
    acc = (acc + a1 + 0x912b8108ULL) ^ 0x078148ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0633 | PC: 0x0e9ff8 | FDE: 0x0781a8 | Size: 232 bytes
// Khung tháo gỡ #0633 | Địa chỉ PC: 0x0e9ff8 | Địa chỉ FDE: 0x0781a8 | Kích thước: 232 bytes
//   0x0e9ff8: D10543FF  sub      sp, sp, #0x150
//   0x0e9ffc: A91353FC  stp      x28, x20, [sp, #0x130]
//   0x0ea000: A9147BF3  stp      x19, x30, [sp, #0x140]
//   0x0ea004: 940235AB  bl       #0x1776b0
static inline uint64_t fde_func_0633_0x0e9ff8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9ff8ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa91353fcULL) ^ 0x0781a8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0634 | PC: 0x0ea0e0 | FDE: 0x078210 | Size: 88 bytes
// Khung tháo gỡ #0634 | Địa chỉ PC: 0x0ea0e0 | Địa chỉ FDE: 0x078210 | Kích thước: 88 bytes
//   0x0ea0e0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0ea0e4: AA0003F3  mov      x19, x0
//   0x0ea0e8: 94022E60  bl       #0x175a68
//   0x0ea0ec: B0000528  adrp     x8, #0x18f000
static inline uint64_t fde_func_0634_0x0ea0e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea0e0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x078210ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0635 | PC: 0x0ea138 | FDE: 0x078270 | Size: 68 bytes
// Khung tháo gỡ #0635 | Địa chỉ PC: 0x0ea138 | Địa chỉ FDE: 0x078270 | Kích thước: 68 bytes
//   0x0ea138: B0000528  adrp     x8, #0x18f000
//   0x0ea13c: 91270108  add      x8, x8, #0x9c0
//   0x0ea140: 140230BC  b        #0x176430
//   0x0ea144: B9400801  ldr      w1, [x0, #8]
static inline uint64_t fde_func_0635_0x0ea138(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea138ULL ^ (static_cast<uint64_t>(0xb0000528ULL) << 13);
    acc = (acc + a1 + 0x91270108ULL) ^ 0x078270ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0636 | PC: 0x0ea17c | FDE: 0x0782d0 | Size: 88 bytes
// Khung tháo gỡ #0636 | Địa chỉ PC: 0x0ea17c | Địa chỉ FDE: 0x0782d0 | Kích thước: 88 bytes
//   0x0ea17c: B9400801  ldr      w1, [x0, #8]
//   0x0ea180: 52919500  mov      w0, #0x8ca8
//   0x0ea184: 14027703  b        #0x187d90
//   0x0ea188: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
static inline uint64_t fde_func_0636_0x0ea17c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea17cULL ^ (static_cast<uint64_t>(0xb9400801ULL) << 13);
    acc = (acc + a1 + 0x52919500ULL) ^ 0x0782d0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0637 | PC: 0x0ea1d4 | FDE: 0x078330 | Size: 216 bytes
// Khung tháo gỡ #0637 | Địa chỉ PC: 0x0ea1d4 | Địa chỉ FDE: 0x078330 | Kích thước: 216 bytes
//   0x0ea1d4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0ea1d8: 94024F7E  bl       #0x17dfd0
//   0x0ea1dc: 97FFC682  bl       #0xdbbe4
//   0x0ea1e0: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0637_0x0ea1d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea1d4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94024f7eULL) ^ 0x078330ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #0638 | PC: 0x0ea2ac | FDE: 0x078398 | Size: 200 bytes
// Khung tháo gỡ #0638 | Địa chỉ PC: 0x0ea2ac | Địa chỉ FDE: 0x078398 | Kích thước: 200 bytes
//   0x0ea2ac: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0ea2b0: AA0003F3  mov      x19, x0
//   0x0ea2b4: 9101E000  add      x0, x0, #0x78
//   0x0ea2b8: 940001B4  bl       #0xea988
static inline uint64_t fde_func_0638_0x0ea2ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea2acULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x078398ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0639 | PC: 0x0ea374 | FDE: 0x078410 | Size: 208 bytes
// Khung tháo gỡ #0639 | Địa chỉ PC: 0x0ea374 | Địa chỉ FDE: 0x078410 | Kích thước: 208 bytes
//   0x0ea374: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0ea378: B202E7E8  mov      x8, #-0x3333333333333334
//   0x0ea37c: F2E19988  movk     x8, #0xccc, lsl #48
//   0x0ea380: EB08003F  cmp      x1, x8
static inline uint64_t fde_func_0639_0x0ea374(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea374ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb202e7e8ULL) ^ 0x078410ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0640 | PC: 0x0ea444 | FDE: 0x078480 | Size: 228 bytes
// Khung tháo gỡ #0640 | Địa chỉ PC: 0x0ea444 | Địa chỉ FDE: 0x078480 | Kích thước: 228 bytes
//   0x0ea444: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0ea448: D2849248  mov      x8, #0x2492
//   0x0ea44c: F2B24928  movk     x8, #0x9249, lsl #16
//   0x0ea450: F2C92488  movk     x8, #0x4924, lsl #32
static inline uint64_t fde_func_0640_0x0ea444(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea444ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xd2849248ULL) ^ 0x078480ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0641 | PC: 0x0ea528 | FDE: 0x0784e8 | Size: 136 bytes
// Khung tháo gỡ #0641 | Địa chỉ PC: 0x0ea528 | Địa chỉ FDE: 0x0784e8 | Kích thước: 136 bytes
//   0x0ea528: F9400808  ldr      x8, [x0, #0x10]
//   0x0ea52c: D0000529  adrp     x9, #0x190000
//   0x0ea530: 9103E129  add      x9, x9, #0xf8
//   0x0ea534: F9000009  str      x9, [x0]
static inline uint64_t fde_func_0641_0x0ea528(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea528ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xd0000529ULL) ^ 0x0784e8ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0642 | PC: 0x0ea5b0 | FDE: 0x078548 | Size: 256 bytes
// Khung tháo gỡ #0642 | Địa chỉ PC: 0x0ea5b0 | Địa chỉ FDE: 0x078548 | Kích thước: 256 bytes
//   0x0ea5b0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0ea5b4: AA0003F3  mov      x19, x0
//   0x0ea5b8: 97FFFFEC  bl       #0xea568
//   0x0ea5bc: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0642_0x0ea5b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea5b0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x078548ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0643 | PC: 0x0ea988 | FDE: 0x0785c8 | Size: 256 bytes
// Khung tháo gỡ #0643 | Địa chỉ PC: 0x0ea988 | Địa chỉ FDE: 0x0785c8 | Kích thước: 256 bytes
//   0x0ea988: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0ea98c: 39402008  ldrb     w8, [x0, #8]
//   0x0ea990: AA0003F3  mov      x19, x0
//   0x0ea994: 52817C40  mov      w0, #0xbe2
static inline uint64_t fde_func_0643_0x0ea988(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea988ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x39402008ULL) ^ 0x0785c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0644 | PC: 0x0eac94 | FDE: 0x078630 | Size: 256 bytes
// Khung tháo gỡ #0644 | Địa chỉ PC: 0x0eac94 | Địa chỉ FDE: 0x078630 | Kích thước: 256 bytes
//   0x0eac94: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0eac98: 94025938  bl       #0x181178
//   0x0eac9c: 5281A040  mov      w0, #0xd02
//   0x0eaca0: 94027348  bl       #0x1879c0
static inline uint64_t fde_func_0644_0x0eac94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eac94ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94025938ULL) ^ 0x078630ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0645 | PC: 0x0eae80 | FDE: 0x0786a0 | Size: 256 bytes
// Khung tháo gỡ #0645 | Địa chỉ PC: 0x0eae80 | Địa chỉ FDE: 0x0786a0 | Kích thước: 256 bytes
//   0x0eae80: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0eae84: 940258BD  bl       #0x181178
//   0x0eae88: 52817220  mov      w0, #0xb91
//   0x0eae8c: 940272CD  bl       #0x1879c0
static inline uint64_t fde_func_0645_0x0eae80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eae80ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x940258bdULL) ^ 0x0786a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0646 | PC: 0x0eb1fc | FDE: 0x078720 | Size: 256 bytes
// Khung tháo gỡ #0646 | Địa chỉ PC: 0x0eb1fc | Địa chỉ FDE: 0x078720 | Kích thước: 256 bytes
//   0x0eb1fc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0eb200: AA0003F3  mov      x19, x0
//   0x0eb204: 97FFFCD1  bl       #0xea548
//   0x0eb208: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0646_0x0eb1fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb1fcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x078720ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0647 | PC: 0x0eb4e4 | FDE: 0x078798 | Size: 256 bytes
// Khung tháo gỡ #0647 | Địa chỉ PC: 0x0eb4e4 | Địa chỉ FDE: 0x078798 | Kích thước: 256 bytes
//   0x0eb4e4: AA1E03E1  mov      x1, x30
//   0x0eb4e8: 9402323A  bl       #0x177dd0
//   0x0eb4ec: AA0103FE  mov      x30, x1
//   0x0eb4f0: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0647_0x0eb4e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb4e4ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x9402323aULL) ^ 0x078798ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0648 | PC: 0x0eb714 | FDE: 0x078810 | Size: 232 bytes
// Khung tháo gỡ #0648 | Địa chỉ PC: 0x0eb714 | Địa chỉ FDE: 0x078810 | Kích thước: 232 bytes
//   0x0eb714: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0eb718: AA0003F3  mov      x19, x0
//   0x0eb71c: 94000004  bl       #0xeb72c
//   0x0eb720: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0648_0x0eb714(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb714ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x078810ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0649 | PC: 0x0eb7fc | FDE: 0x078880 | Size: 160 bytes
// Khung tháo gỡ #0649 | Địa chỉ PC: 0x0eb7fc | Địa chỉ FDE: 0x078880 | Kích thước: 160 bytes
//   0x0eb7fc: B0FFFA00  adrp     x0, #0x2c000
//   0x0eb800: 91370C00  add      x0, x0, #0xdc3
//   0x0eb804: D65F03C0  ret      
//   0x0eb808: B0FFFA00  adrp     x0, #0x2c000
static inline uint64_t fde_func_0649_0x0eb7fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb7fcULL ^ (static_cast<uint64_t>(0xb0fffa00ULL) << 13);
    acc = (acc + a1 + 0x91370c00ULL) ^ 0x078880ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0650 | PC: 0x0eb89c | FDE: 0x0788f0 | Size: 256 bytes
// Khung tháo gỡ #0650 | Địa chỉ PC: 0x0eb89c | Địa chỉ FDE: 0x0788f0 | Kích thước: 256 bytes
//   0x0eb89c: A9BC63FC  stp      x28, x24, [sp, #-0x40]!
//   0x0eb8a0: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0eb8a4: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0eb8a8: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0650_0x0eb89c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb89cULL ^ (static_cast<uint64_t>(0xa9bc63fcULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0788f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0651 | PC: 0x0ebe30 | FDE: 0x078980 | Size: 156 bytes [_ZN4lynx6canvas13TextureSource9GetShaderEv]
// Khung tháo gỡ #0651 | Địa chỉ PC: 0x0ebe30 | Địa chỉ FDE: 0x078980 | Kích thước: 156 bytes
//   0x0ebe30: D10083FF  sub      sp, sp, #0x20
//   0x0ebe34: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0ebe38: 9402415F  bl       #0x17c3b4
//   0x0ebe3c: B50001C0  cbnz     x0, #0xebe74
static inline uint64_t fde_func_0651_0x0ebe30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ebe30ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x078980ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0652 | PC: 0x0ebecc | FDE: 0x0789e0 | Size: 28 bytes [_ZN4lynx6canvas29FirstFrameAwareSurfaceTextureC2EP7_JNIEnvP8_jobject]
// Khung tháo gỡ #0652 | Địa chỉ PC: 0x0ebecc | Địa chỉ FDE: 0x0789e0 | Kích thước: 28 bytes
//   0x0ebecc: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0ebed0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0ebed4: 940232E6  bl       #0x178a6c
//   0x0ebed8: 97FEFEA7  bl       #0xab974
static inline uint64_t fde_func_0652_0x0ebecc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ebeccULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0789e0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0653 | PC: 0x0ebee8 | FDE: 0x078a00 | Size: 256 bytes [_ZN4lynx6canvas29FirstFrameAwareSurfaceTextureD1Ev]
// Khung tháo gỡ #0653 | Địa chỉ PC: 0x0ebee8 | Địa chỉ FDE: 0x078a00 | Kích thước: 256 bytes
//   0x0ebee8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0ebeec: AA0003F3  mov      x19, x0
//   0x0ebef0: 94000004  bl       #0xebf00
//   0x0ebef4: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0653_0x0ebee8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ebee8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x078a00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0654 | PC: 0x0ec018 | FDE: 0x078a60 | Size: 192 bytes
// Khung tháo gỡ #0654 | Địa chỉ PC: 0x0ec018 | Địa chỉ FDE: 0x078a60 | Kích thước: 192 bytes
//   0x0ec018: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0ec01c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0ec020: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0ec024: 90000528  adrp     x8, #0x190000
static inline uint64_t fde_func_0654_0x0ec018(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ec018ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x078a60ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #0655 | PC: 0x0ec0d8 | FDE: 0x078ac8 | Size: 256 bytes
// Khung tháo gỡ #0655 | Địa chỉ PC: 0x0ec0d8 | Địa chỉ FDE: 0x078ac8 | Kích thước: 256 bytes
//   0x0ec0d8: A9BC63FC  stp      x28, x24, [sp, #-0x40]!
//   0x0ec0dc: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0ec0e0: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0ec0e4: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0655_0x0ec0d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ec0d8ULL ^ (static_cast<uint64_t>(0xa9bc63fcULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x078ac8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0656 | PC: 0x0ec620 | FDE: 0x078b58 | Size: 12 bytes
// Khung tháo gỡ #0656 | Địa chỉ PC: 0x0ec620 | Địa chỉ FDE: 0x078b58 | Kích thước: 12 bytes
//   0x0ec620: AA0103E2  mov      x2, x1
//   0x0ec624: AA1F03E1  mov      x1, xzr
//   0x0ec628: 14026BCA  b        #0x187550
static inline uint64_t fde_func_0656_0x0ec620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ec620ULL ^ (static_cast<uint64_t>(0xaa0103e2ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e1ULL) ^ 0x078b58ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0657 | PC: 0x0ec62c | FDE: 0x078b70 | Size: 200 bytes [_ZN4lynx6canvas21SurfaceTextureAndroid12GetTimestampEv]
// Khung tháo gỡ #0657 | Địa chỉ PC: 0x0ec62c | Địa chỉ FDE: 0x078b70 | Kích thước: 200 bytes
//   0x0ec62c: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x0ec630: F90007F4  str      x20, [sp, #8]
//   0x0ec634: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0ec638: F9401008  ldr      x8, [x0, #0x20]
static inline uint64_t fde_func_0657_0x0ec62c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ec62cULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xf90007f4ULL) ^ 0x078b70ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0658 | PC: 0x0ec6f4 | FDE: 0x078bc8 | Size: 256 bytes
// Khung tháo gỡ #0658 | Địa chỉ PC: 0x0ec6f4 | Địa chỉ FDE: 0x078bc8 | Kích thước: 256 bytes
//   0x0ec6f4: D10143FF  sub      sp, sp, #0x50
//   0x0ec6f8: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0ec6fc: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x0ec700: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0658_0x0ec6f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ec6f4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x078bc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0659 | PC: 0x0ec860 | FDE: 0x078c38 | Size: 256 bytes
// Khung tháo gỡ #0659 | Địa chỉ PC: 0x0ec860 | Địa chỉ FDE: 0x078c38 | Kích thước: 256 bytes
//   0x0ec860: D10583FF  sub      sp, sp, #0x160
//   0x0ec864: F9009BFC  str      x28, [sp, #0x130]
//   0x0ec868: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0ec86c: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0659_0x0ec860(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ec860ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x078c38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0660 | PC: 0x0ec98c | FDE: 0x078ca0 | Size: 212 bytes
// Khung tháo gỡ #0660 | Địa chỉ PC: 0x0ec98c | Địa chỉ FDE: 0x078ca0 | Kích thước: 212 bytes
//   0x0ec98c: D10583FF  sub      sp, sp, #0x160
//   0x0ec990: F9009BFC  str      x28, [sp, #0x130]
//   0x0ec994: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0ec998: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0660_0x0ec98c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ec98cULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x078ca0ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0661 | PC: 0x0eca60 | FDE: 0x078cd8 | Size: 256 bytes [_ZN4lynx6canvas13SurfaceClientD2Ev]
// Khung tháo gỡ #0661 | Địa chỉ PC: 0x0eca60 | Địa chỉ FDE: 0x078cd8 | Kích thước: 256 bytes
//   0x0eca60: AA1E03E1  mov      x1, x30
//   0x0eca64: 94022F3F  bl       #0x178760
//   0x0eca68: AA0103FE  mov      x30, x1
//   0x0eca6c: A9167BF3  stp      x19, x30, [sp, #0x160]
static inline uint64_t fde_func_0661_0x0eca60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eca60ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x94022f3fULL) ^ 0x078cd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0662 | PC: 0x0ecd8c | FDE: 0x078d30 | Size: 256 bytes
// Khung tháo gỡ #0662 | Địa chỉ PC: 0x0ecd8c | Địa chỉ FDE: 0x078d30 | Kích thước: 256 bytes
//   0x0ecd8c: D10103FF  sub      sp, sp, #0x40
//   0x0ecd90: F9000BF6  str      x22, [sp, #0x10]
//   0x0ecd94: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0ecd98: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0662_0x0ecd8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ecd8cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x078d30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0663 | PC: 0x0ed08c | FDE: 0x078db8 | Size: 256 bytes
// Khung tháo gỡ #0663 | Địa chỉ PC: 0x0ed08c | Địa chỉ FDE: 0x078db8 | Kích thước: 256 bytes
//   0x0ed08c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0ed090: 9100A000  add      x0, x0, #0x28
//   0x0ed094: 9400003F  bl       #0xed190
//   0x0ed098: A9402408  ldp      x8, x9, [x0]
static inline uint64_t fde_func_0663_0x0ed08c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ed08cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x9100a000ULL) ^ 0x078db8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0664 | PC: 0x0ed58c | FDE: 0x078e50 | Size: 196 bytes
// Khung tháo gỡ #0664 | Địa chỉ PC: 0x0ed58c | Địa chỉ FDE: 0x078e50 | Kích thước: 196 bytes
//   0x0ed58c: D10143FF  sub      sp, sp, #0x50
//   0x0ed590: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0ed594: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x0ed598: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0664_0x0ed58c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ed58cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x078e50ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0665 | PC: 0x0ed650 | FDE: 0x078e88 | Size: 32 bytes [_ZN4lynx6canvas30SurfaceWithAndroidNativeWindowC1EP13ANativeWindowii]
// Khung tháo gỡ #0665 | Địa chỉ PC: 0x0ed650 | Địa chỉ FDE: 0x078e88 | Kích thước: 32 bytes
//   0x0ed650: 29020C02  stp      w2, w3, [x0, #0x10]
//   0x0ed654: 90000548  adrp     x8, #0x195000
//   0x0ed658: F940ED08  ldr      x8, [x8, #0x1d8]
//   0x0ed65c: F9000C01  str      x1, [x0, #0x18]
static inline uint64_t fde_func_0665_0x0ed650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ed650ULL ^ (static_cast<uint64_t>(0x29020c02ULL) << 13);
    acc = (acc + a1 + 0x90000548ULL) ^ 0x078e88ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0666 | PC: 0x0ed670 | FDE: 0x078ea0 | Size: 60 bytes [_ZN4lynx6canvas30SurfaceWithAndroidNativeWindowD1Ev]
// Khung tháo gỡ #0666 | Địa chỉ PC: 0x0ed670 | Địa chỉ FDE: 0x078ea0 | Kích thước: 60 bytes
//   0x0ed670: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0ed674: 90000548  adrp     x8, #0x195000
//   0x0ed678: 94022AD6  bl       #0x1781d0
//   0x0ed67c: F940ED08  ldr      x8, [x8, #0x1d8]
static inline uint64_t fde_func_0666_0x0ed670(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ed670ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x90000548ULL) ^ 0x078ea0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0667 | PC: 0x0ed6ac | FDE: 0x078eb8 | Size: 24 bytes [_ZN4lynx6canvas30SurfaceWithAndroidNativeWindowD0Ev]
// Khung tháo gỡ #0667 | Địa chỉ PC: 0x0ed6ac | Địa chỉ FDE: 0x078eb8 | Kích thước: 24 bytes
//   0x0ed6ac: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0ed6b0: AA0003F3  mov      x19, x0
//   0x0ed6b4: 9402690F  bl       #0x187af0
//   0x0ed6b8: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0667_0x0ed6ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ed6acULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x078eb8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0668 | PC: 0x0ed6c4 | FDE: 0x078ed0 | Size: 140 bytes [_ZN4lynx6canvas30SurfaceWithAndroidNativeWindow21CreateGraphicsContextENS0_7Surface19GraphicsBackendTypeE]
// Khung tháo gỡ #0668 | Địa chỉ PC: 0x0ed6c4 | Địa chỉ FDE: 0x078ed0 | Kích thước: 140 bytes
//   0x0ed6c4: D10583FF  sub      sp, sp, #0x160
//   0x0ed6c8: F9009BFC  str      x28, [sp, #0x130]
//   0x0ed6cc: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0ed6d0: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0668_0x0ed6c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ed6c4ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x078ed0ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0669 | PC: 0x0ed750 | FDE: 0x078ef0 | Size: 32 bytes [_ZN4lynx6canvas32SurfaceAndroidWithSurfaceTextureC1EP13ANativeWindowNSt6__ndk110unique_ptrINS0_29FirstFrameAwareSurfaceTextureENS4_14default_deleteIS6_EEEE]
// Khung tháo gỡ #0669 | Địa chỉ PC: 0x0ed750 | Địa chỉ FDE: 0x078ef0 | Kích thước: 32 bytes
//   0x0ed750: F0000508  adrp     x8, #0x190000
//   0x0ed754: 91116108  add      x8, x8, #0x458
//   0x0ed758: A9007C08  stp      x8, xzr, [x0]
//   0x0ed75c: A901041F  stp      xzr, x1, [x0, #0x10]
static inline uint64_t fde_func_0669_0x0ed750(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ed750ULL ^ (static_cast<uint64_t>(0xf0000508ULL) << 13);
    acc = (acc + a1 + 0x91116108ULL) ^ 0x078ef0ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0670 | PC: 0x0ed770 | FDE: 0x078f08 | Size: 56 bytes [_ZN4lynx6canvas32SurfaceAndroidWithSurfaceTextureD1Ev]
// Khung tháo gỡ #0670 | Địa chỉ PC: 0x0ed770 | Địa chỉ FDE: 0x078f08 | Kích thước: 56 bytes
//   0x0ed770: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0ed774: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0ed778: F0000508  adrp     x8, #0x190000
//   0x0ed77c: 91116108  add      x8, x8, #0x458
static inline uint64_t fde_func_0670_0x0ed770(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ed770ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x078f08ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0671 | PC: 0x0ed7a8 | FDE: 0x078f28 | Size: 256 bytes [_ZN4lynx6canvas32SurfaceAndroidWithSurfaceTextureD0Ev]
// Khung tháo gỡ #0671 | Địa chỉ PC: 0x0ed7a8 | Địa chỉ FDE: 0x078f28 | Kích thước: 256 bytes
//   0x0ed7a8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0ed7ac: AA0003F3  mov      x19, x0
//   0x0ed7b0: 94026E4C  bl       #0x1890e0
//   0x0ed7b4: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0671_0x0ed7a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ed7a8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x078f28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0672 | PC: 0x0edbac | FDE: 0x078fb0 | Size: 252 bytes
// Khung tháo gỡ #0672 | Địa chỉ PC: 0x0edbac | Địa chỉ FDE: 0x078fb0 | Kích thước: 252 bytes
//   0x0edbac: D100C3FF  sub      sp, sp, #0x30
//   0x0edbb0: F9000BF4  str      x20, [sp, #0x10]
//   0x0edbb4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0edbb8: 94022F05  bl       #0x1797cc
static inline uint64_t fde_func_0672_0x0edbac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0edbacULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x078fb0ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0673 | PC: 0x0edca8 | FDE: 0x079020 | Size: 256 bytes
// Khung tháo gỡ #0673 | Địa chỉ PC: 0x0edca8 | Địa chỉ FDE: 0x079020 | Kích thước: 256 bytes
//   0x0edca8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0edcac: AA0003F3  mov      x19, x0
//   0x0edcb0: 97FFFFEF  bl       #0xedc6c
//   0x0edcb4: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0673_0x0edca8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0edca8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x079020ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0674 | PC: 0x0ee954 | FDE: 0x0790a8 | Size: 256 bytes
// Khung tháo gỡ #0674 | Địa chỉ PC: 0x0ee954 | Địa chỉ FDE: 0x0790a8 | Kích thước: 256 bytes
//   0x0ee954: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0ee958: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0ee95c: AA0003F3  mov      x19, x0
//   0x0ee960: 94003F2B  bl       #0xfe60c
static inline uint64_t fde_func_0674_0x0ee954(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee954ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0790a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0675 | PC: 0x0eec10 | FDE: 0x079128 | Size: 256 bytes
// Khung tháo gỡ #0675 | Địa chỉ PC: 0x0eec10 | Địa chỉ FDE: 0x079128 | Kích thước: 256 bytes
//   0x0eec10: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0eec14: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0eec18: 52911248  mov      w8, #0x8892
//   0x0eec1c: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_0675_0x0eec10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eec10ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x079128ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0676 | PC: 0x0eee10 | FDE: 0x079190 | Size: 256 bytes
// Khung tháo gỡ #0676 | Địa chỉ PC: 0x0eee10 | Địa chỉ FDE: 0x079190 | Kích thước: 256 bytes
//   0x0eee10: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0eee14: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0eee18: 2A0203F5  mov      w21, w2
//   0x0eee1c: 94021C61  bl       #0x175fa0
static inline uint64_t fde_func_0676_0x0eee10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eee10ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x079190ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0677 | PC: 0x0ef81c | FDE: 0x079210 | Size: 256 bytes
// Khung tháo gỡ #0677 | Địa chỉ PC: 0x0ef81c | Địa chỉ FDE: 0x079210 | Kích thước: 256 bytes
//   0x0ef81c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0ef820: 94024855  bl       #0x181974
//   0x0ef824: 52800200  mov      w0, #0x10
//   0x0ef828: F84107FE  ldr      x30, [sp], #0x10
static inline uint64_t fde_func_0677_0x0ef81c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef81cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x94024855ULL) ^ 0x079210ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0678 | PC: 0x0ef954 | FDE: 0x079278 | Size: 176 bytes
// Khung tháo gỡ #0678 | Địa chỉ PC: 0x0ef954 | Địa chỉ FDE: 0x079278 | Kích thước: 176 bytes
//   0x0ef954: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0ef958: 94022A03  bl       #0x17a164
//   0x0ef95c: F84107FE  ldr      x30, [sp], #0x10
//   0x0ef960: D65F03C0  ret      
static inline uint64_t fde_func_0678_0x0ef954(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef954ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x94022a03ULL) ^ 0x079278ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #0679 | PC: 0x0efa04 | FDE: 0x0792e0 | Size: 100 bytes
// Khung tháo gỡ #0679 | Địa chỉ PC: 0x0efa04 | Địa chỉ FDE: 0x0792e0 | Kích thước: 100 bytes
//   0x0efa04: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0efa08: F9400001  ldr      x1, [x0]
//   0x0efa0c: 52914680  mov      w0, #0x8a34
//   0x0efa10: 94025FEC  bl       #0x1879c0
static inline uint64_t fde_func_0679_0x0efa04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0efa04ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400001ULL) ^ 0x0792e0ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0680 | PC: 0x0efa68 | FDE: 0x079340 | Size: 256 bytes
// Khung tháo gỡ #0680 | Địa chỉ PC: 0x0efa68 | Địa chỉ FDE: 0x079340 | Kích thước: 256 bytes
//   0x0efa68: D100C3FF  sub      sp, sp, #0x30
//   0x0efa6c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0efa70: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0efa74: 2A0103F3  mov      w19, w1
static inline uint64_t fde_func_0680_0x0efa68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0efa68ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x079340ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0681 | PC: 0x0efdfc | FDE: 0x0793b8 | Size: 256 bytes
// Khung tháo gỡ #0681 | Địa chỉ PC: 0x0efdfc | Địa chỉ FDE: 0x0793b8 | Kích thước: 256 bytes
//   0x0efdfc: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0efe00: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0efe04: 94025898  bl       #0x186064
//   0x0efe08: 37000048  tbnz     w8, #0, #0xefe10
static inline uint64_t fde_func_0681_0x0efdfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0efdfcULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0793b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0682 | PC: 0x0f00a0 | FDE: 0x079438 | Size: 256 bytes
// Khung tháo gỡ #0682 | Địa chỉ PC: 0x0f00a0 | Địa chỉ FDE: 0x079438 | Kích thước: 256 bytes
//   0x0f00a0: AA1E03E6  mov      x6, x30
//   0x0f00a4: 94021F4B  bl       #0x177dd0
//   0x0f00a8: AA0603FE  mov      x30, x6
//   0x0f00ac: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0682_0x0f00a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f00a0ULL ^ (static_cast<uint64_t>(0xaa1e03e6ULL) << 13);
    acc = (acc + a1 + 0x94021f4bULL) ^ 0x079438ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0683 | PC: 0x0f0308 | FDE: 0x0794b0 | Size: 256 bytes
// Khung tháo gỡ #0683 | Địa chỉ PC: 0x0f0308 | Địa chỉ FDE: 0x0794b0 | Kích thước: 256 bytes
//   0x0f0308: D10143FF  sub      sp, sp, #0x50
//   0x0f030c: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0f0310: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x0f0314: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0683_0x0f0308(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f0308ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x0794b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0684 | PC: 0x0f0504 | FDE: 0x079520 | Size: 256 bytes
// Khung tháo gỡ #0684 | Địa chỉ PC: 0x0f0504 | Địa chỉ FDE: 0x079520 | Kích thước: 256 bytes
//   0x0f0504: AA1E03E8  mov      x8, x30
//   0x0f0508: 94021946  bl       #0x176a20
//   0x0f050c: AA0803FE  mov      x30, x8
//   0x0f0510: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_0684_0x0f0504(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f0504ULL ^ (static_cast<uint64_t>(0xaa1e03e8ULL) << 13);
    acc = (acc + a1 + 0x94021946ULL) ^ 0x079520ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0685 | PC: 0x0f0920 | FDE: 0x0795a8 | Size: 256 bytes
// Khung tháo gỡ #0685 | Địa chỉ PC: 0x0f0920 | Địa chỉ FDE: 0x0795a8 | Kích thước: 256 bytes
//   0x0f0920: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x0f0924: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0f0928: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0f092c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0685_0x0f0920(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f0920ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0795a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0686 | PC: 0x0f0b00 | FDE: 0x079630 | Size: 104 bytes
// Khung tháo gỡ #0686 | Địa chỉ PC: 0x0f0b00 | Địa chỉ FDE: 0x079630 | Kích thước: 104 bytes
//   0x0f0b00: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0f0b04: 9402178B  bl       #0x176930
//   0x0f0b08: 9402617E  bl       #0x189100
//   0x0f0b0c: 940222BE  bl       #0x179604
static inline uint64_t fde_func_0686_0x0f0b00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f0b00ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9402178bULL) ^ 0x079630ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0687 | PC: 0x0f0b68 | FDE: 0x079698 | Size: 252 bytes
// Khung tháo gỡ #0687 | Địa chỉ PC: 0x0f0b68 | Địa chỉ FDE: 0x079698 | Kích thước: 252 bytes
//   0x0f0b68: AA1E03E6  mov      x6, x30
//   0x0f0b6c: 940218F5  bl       #0x176f40
//   0x0f0b70: AA0603FE  mov      x30, x6
//   0x0f0b74: A9177BF3  stp      x19, x30, [sp, #0x170]
static inline uint64_t fde_func_0687_0x0f0b68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f0b68ULL ^ (static_cast<uint64_t>(0xaa1e03e6ULL) << 13);
    acc = (acc + a1 + 0x940218f5ULL) ^ 0x079698ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0688 | PC: 0x0f0c64 | FDE: 0x079718 | Size: 196 bytes
// Khung tháo gỡ #0688 | Địa chỉ PC: 0x0f0c64 | Địa chỉ FDE: 0x079718 | Kích thước: 196 bytes
//   0x0f0c64: 2A1F03E5  mov      w5, wzr
//   0x0f0c68: 14000001  b        #0xf0c6c
//   0x0f0c6c: AA1E03E6  mov      x6, x30
//   0x0f0c70: 940218B4  bl       #0x176f40
static inline uint64_t fde_func_0688_0x0f0c64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f0c64ULL ^ (static_cast<uint64_t>(0x2a1f03e5ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x079718ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0689 | PC: 0x0f0d28 | FDE: 0x079790 | Size: 256 bytes
// Khung tháo gỡ #0689 | Địa chỉ PC: 0x0f0d28 | Địa chỉ FDE: 0x079790 | Kích thước: 256 bytes
//   0x0f0d28: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x0f0d2c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0f0d30: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0f0d34: 94022574  bl       #0x17a304
static inline uint64_t fde_func_0689_0x0f0d28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f0d28ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x079790ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0690 | PC: 0x0f0ebc | FDE: 0x079810 | Size: 256 bytes
// Khung tháo gỡ #0690 | Địa chỉ PC: 0x0f0ebc | Địa chỉ FDE: 0x079810 | Kích thước: 256 bytes
//   0x0f0ebc: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x0f0ec0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0f0ec4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0f0ec8: 94022CCF  bl       #0x17c204
static inline uint64_t fde_func_0690_0x0f0ebc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f0ebcULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x079810ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0691 | PC: 0x0f10cc | FDE: 0x0798b8 | Size: 256 bytes
// Khung tháo gỡ #0691 | Địa chỉ PC: 0x0f10cc | Địa chỉ FDE: 0x0798b8 | Kích thước: 256 bytes
//   0x0f10cc: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x0f10d0: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0f10d4: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0f10d8: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0691_0x0f10cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f10ccULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0798b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0692 | PC: 0x0f13e4 | FDE: 0x079950 | Size: 256 bytes
// Khung tháo gỡ #0692 | Địa chỉ PC: 0x0f13e4 | Địa chỉ FDE: 0x079950 | Kích thước: 256 bytes
//   0x0f13e4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0f13e8: 9402556A  bl       #0x186990
//   0x0f13ec: 97FEECBD  bl       #0xac6e0
//   0x0f13f0: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0692_0x0f13e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f13e4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9402556aULL) ^ 0x079950ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0693 | PC: 0x0f1614 | FDE: 0x0799f0 | Size: 256 bytes
// Khung tháo gỡ #0693 | Địa chỉ PC: 0x0f1614 | Địa chỉ FDE: 0x0799f0 | Kích thước: 256 bytes
//   0x0f1614: AA1E03E8  mov      x8, x30
//   0x0f1618: 94021B3D  bl       #0x17830c
//   0x0f161c: AA0803FE  mov      x30, x8
//   0x0f1620: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_0693_0x0f1614(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f1614ULL ^ (static_cast<uint64_t>(0xaa1e03e8ULL) << 13);
    acc = (acc + a1 + 0x94021b3dULL) ^ 0x0799f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0694 | PC: 0x0f1830 | FDE: 0x079aa8 | Size: 256 bytes
// Khung tháo gỡ #0694 | Địa chỉ PC: 0x0f1830 | Địa chỉ FDE: 0x079aa8 | Kích thước: 256 bytes
//   0x0f1830: D101C3FF  sub      sp, sp, #0x70
//   0x0f1834: AA1E03E8  mov      x8, x30
//   0x0f1838: 9402148A  bl       #0x176a60
//   0x0f183c: AA0803FE  mov      x30, x8
static inline uint64_t fde_func_0694_0x0f1830(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f1830ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xaa1e03e8ULL) ^ 0x079aa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0695 | PC: 0x0f1b1c | FDE: 0x079b50 | Size: 256 bytes
// Khung tháo gỡ #0695 | Địa chỉ PC: 0x0f1b1c | Địa chỉ FDE: 0x079b50 | Kích thước: 256 bytes
//   0x0f1b1c: AA1E03E8  mov      x8, x30
//   0x0f1b20: 9402172B  bl       #0x1777cc
//   0x0f1b24: AA0803FE  mov      x30, x8
//   0x0f1b28: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_0695_0x0f1b1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f1b1cULL ^ (static_cast<uint64_t>(0xaa1e03e8ULL) << 13);
    acc = (acc + a1 + 0x9402172bULL) ^ 0x079b50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0696 | PC: 0x0f1e14 | FDE: 0x079bf0 | Size: 256 bytes
// Khung tháo gỡ #0696 | Địa chỉ PC: 0x0f1e14 | Địa chỉ FDE: 0x079bf0 | Kích thước: 256 bytes
//   0x0f1e14: D10083FF  sub      sp, sp, #0x20
//   0x0f1e18: F9000BFE  str      x30, [sp, #0x10]
//   0x0f1e1c: 94024988  bl       #0x18443c
//   0x0f1e20: B9402009  ldr      w9, [x0, #0x20]
static inline uint64_t fde_func_0696_0x0f1e14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f1e14ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfeULL) ^ 0x079bf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0697 | PC: 0x0f1f80 | FDE: 0x079c70 | Size: 148 bytes
// Khung tháo gỡ #0697 | Địa chỉ PC: 0x0f1f80 | Địa chỉ FDE: 0x079c70 | Kích thước: 148 bytes
//   0x0f1f80: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0f1f84: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0f1f88: AA0003F3  mov      x19, x0
//   0x0f1f8c: 94022A69  bl       #0x17c930
static inline uint64_t fde_func_0697_0x0f1f80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f1f80ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x079c70ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0698 | PC: 0x0f2014 | FDE: 0x079ce0 | Size: 256 bytes
// Khung tháo gỡ #0698 | Địa chỉ PC: 0x0f2014 | Địa chỉ FDE: 0x079ce0 | Kích thước: 256 bytes
//   0x0f2014: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0f2018: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0f201c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0f2020: F9400016  ldr      x22, [x0]
static inline uint64_t fde_func_0698_0x0f2014(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f2014ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x079ce0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0699 | PC: 0x0f2154 | FDE: 0x079d58 | Size: 256 bytes
// Khung tháo gỡ #0699 | Địa chỉ PC: 0x0f2154 | Địa chỉ FDE: 0x079d58 | Kích thước: 256 bytes
//   0x0f2154: B4000121  cbz      x1, #0xf2178
//   0x0f2158: 3941C428  ldrb     w8, [x1, #0x71]
//   0x0f215c: 340000E8  cbz      w8, #0xf2178
//   0x0f2160: F0FFF9E2  adrp     x2, #0x31000
static inline uint64_t fde_func_0699_0x0f2154(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f2154ULL ^ (static_cast<uint64_t>(0xb4000121ULL) << 13);
    acc = (acc + a1 + 0x3941c428ULL) ^ 0x079d58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0700 | PC: 0x0f24b0 | FDE: 0x079dd0 | Size: 256 bytes
// Khung tháo gỡ #0700 | Địa chỉ PC: 0x0f24b0 | Địa chỉ FDE: 0x079dd0 | Kích thước: 256 bytes
//   0x0f24b0: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0f24b4: AA0003E1  mov      x1, x0
//   0x0f24b8: B8404420  ldr      w0, [x1], #4
//   0x0f24bc: 94025A89  bl       #0x188ee0
static inline uint64_t fde_func_0700_0x0f24b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f24b0ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xaa0003e1ULL) ^ 0x079dd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0701 | PC: 0x0f25f8 | FDE: 0x079e48 | Size: 256 bytes
// Khung tháo gỡ #0701 | Địa chỉ PC: 0x0f25f8 | Địa chỉ FDE: 0x079e48 | Kích thước: 256 bytes
//   0x0f25f8: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0f25fc: 94022F89  bl       #0x17e420
//   0x0f2600: 52800400  mov      w0, #0x20
//   0x0f2604: F84107FE  ldr      x30, [sp], #0x10
static inline uint64_t fde_func_0701_0x0f25f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f25f8ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x94022f89ULL) ^ 0x079e48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0702 | PC: 0x0f27d4 | FDE: 0x079eb8 | Size: 256 bytes
// Khung tháo gỡ #0702 | Địa chỉ PC: 0x0f27d4 | Địa chỉ FDE: 0x079eb8 | Kích thước: 256 bytes
//   0x0f27d4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0f27d8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0f27dc: F941C008  ldr      x8, [x0, #0x380]
//   0x0f27e0: B5000048  cbnz     x8, #0xf27e8
static inline uint64_t fde_func_0702_0x0f27d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f27d4ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x079eb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0703 | PC: 0x0f2ae4 | FDE: 0x079f40 | Size: 256 bytes
// Khung tháo gỡ #0703 | Địa chỉ PC: 0x0f2ae4 | Địa chỉ FDE: 0x079f40 | Kích thước: 256 bytes
//   0x0f2ae4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0f2ae8: F9400409  ldr      x9, [x0, #8]
//   0x0f2aec: 29400408  ldp      w8, w1, [x0]
//   0x0f2af0: B4000069  cbz      x9, #0xf2afc
static inline uint64_t fde_func_0703_0x0f2ae4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f2ae4ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400409ULL) ^ 0x079f40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0704 | PC: 0x0f2dfc | FDE: 0x079fb8 | Size: 256 bytes
// Khung tháo gỡ #0704 | Địa chỉ PC: 0x0f2dfc | Địa chỉ FDE: 0x079fb8 | Kích thước: 256 bytes
//   0x0f2dfc: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0f2e00: F9400008  ldr      x8, [x0]
//   0x0f2e04: 29410801  ldp      w1, w2, [x0, #8]
//   0x0f2e08: F9400803  ldr      x3, [x0, #0x10]
static inline uint64_t fde_func_0704_0x0f2dfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f2dfcULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x079fb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0705 | PC: 0x0f3290 | FDE: 0x07a040 | Size: 256 bytes
// Khung tháo gỡ #0705 | Địa chỉ PC: 0x0f3290 | Địa chỉ FDE: 0x07a040 | Kích thước: 256 bytes
//   0x0f3290: AA1E03E3  mov      x3, x30
//   0x0f3294: 940212CF  bl       #0x177dd0
//   0x0f3298: AA0303FE  mov      x30, x3
//   0x0f329c: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0705_0x0f3290(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f3290ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x940212cfULL) ^ 0x07a040ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0706 | PC: 0x0f361c | FDE: 0x07a0c8 | Size: 256 bytes
// Khung tháo gỡ #0706 | Địa chỉ PC: 0x0f361c | Địa chỉ FDE: 0x07a0c8 | Kích thước: 256 bytes
//   0x0f361c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0f3620: 94021B70  bl       #0x17a3e0
//   0x0f3624: 940256F7  bl       #0x189200
//   0x0f3628: 52800200  mov      w0, #0x10
static inline uint64_t fde_func_0706_0x0f361c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f361cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x94021b70ULL) ^ 0x07a0c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0707 | PC: 0x0f3978 | FDE: 0x07a138 | Size: 256 bytes
// Khung tháo gỡ #0707 | Địa chỉ PC: 0x0f3978 | Địa chỉ FDE: 0x07a138 | Kích thước: 256 bytes
//   0x0f3978: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0f397c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0f3980: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0f3984: 94023B4E  bl       #0x1826bc
static inline uint64_t fde_func_0707_0x0f3978(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f3978ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x07a138ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0708 | PC: 0x0f3d0c | FDE: 0x07a1c0 | Size: 256 bytes
// Khung tháo gỡ #0708 | Địa chỉ PC: 0x0f3d0c | Địa chỉ FDE: 0x07a1c0 | Kích thước: 256 bytes
//   0x0f3d0c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0f3d10: 94021AB2  bl       #0x17a7d8
//   0x0f3d14: 94025543  bl       #0x189220
//   0x0f3d18: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_0708_0x0f3d0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f3d0cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x94021ab2ULL) ^ 0x07a1c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0709 | PC: 0x0f3e6c | FDE: 0x07a230 | Size: 256 bytes
// Khung tháo gỡ #0709 | Địa chỉ PC: 0x0f3e6c | Địa chỉ FDE: 0x07a230 | Kích thước: 256 bytes
//   0x0f3e6c: AA1E03E3  mov      x3, x30
//   0x0f3e70: 94020FD8  bl       #0x177dd0
//   0x0f3e74: AA0303FE  mov      x30, x3
//   0x0f3e78: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0709_0x0f3e6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f3e6cULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94020fd8ULL) ^ 0x07a230ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0710 | PC: 0x0f40ec | FDE: 0x07a2c8 | Size: 256 bytes
// Khung tháo gỡ #0710 | Địa chỉ PC: 0x0f40ec | Địa chỉ FDE: 0x07a2c8 | Kích thước: 256 bytes
//   0x0f40ec: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x0f40f0: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0f40f4: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0f40f8: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0710_0x0f40ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f40ecULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x07a2c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0711 | PC: 0x0f4438 | FDE: 0x07a350 | Size: 152 bytes
// Khung tháo gỡ #0711 | Địa chỉ PC: 0x0f4438 | Địa chỉ FDE: 0x07a350 | Kích thước: 152 bytes
//   0x0f4438: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0f443c: 29400408  ldp      w8, w1, [x0]
//   0x0f4440: AA0003F3  mov      x19, x0
//   0x0f4444: F8408E62  ldr      x2, [x19, #8]!
static inline uint64_t fde_func_0711_0x0f4438(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4438ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x29400408ULL) ^ 0x07a350ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0712 | PC: 0x0f44d0 | FDE: 0x07a3b0 | Size: 184 bytes
// Khung tháo gỡ #0712 | Địa chỉ PC: 0x0f44d0 | Địa chỉ FDE: 0x07a3b0 | Kích thước: 184 bytes
//   0x0f44d0: B40000E1  cbz      x1, #0xf44ec
//   0x0f44d4: F942DC08  ldr      x8, [x0, #0x5b8]
//   0x0f44d8: F9402029  ldr      x9, [x1, #0x40]
//   0x0f44dc: EB09011F  cmp      x8, x9
static inline uint64_t fde_func_0712_0x0f44d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f44d0ULL ^ (static_cast<uint64_t>(0xb40000e1ULL) << 13);
    acc = (acc + a1 + 0xf942dc08ULL) ^ 0x07a3b0ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0713 | PC: 0x0f4588 | FDE: 0x07a418 | Size: 256 bytes
// Khung tháo gỡ #0713 | Địa chỉ PC: 0x0f4588 | Địa chỉ FDE: 0x07a418 | Kích thước: 256 bytes
//   0x0f4588: D100C3FF  sub      sp, sp, #0x30
//   0x0f458c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0f4590: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0f4594: 94022BC2  bl       #0x17f49c
static inline uint64_t fde_func_0713_0x0f4588(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4588ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x07a418ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0714 | PC: 0x0f484c | FDE: 0x07a4a0 | Size: 256 bytes
// Khung tháo gỡ #0714 | Địa chỉ PC: 0x0f484c | Địa chỉ FDE: 0x07a4a0 | Kích thước: 256 bytes
//   0x0f484c: D10183FF  sub      sp, sp, #0x60
//   0x0f4850: AA1E03E8  mov      x8, x30
//   0x0f4854: 94020AD1  bl       #0x177398
//   0x0f4858: AA0803FE  mov      x30, x8
static inline uint64_t fde_func_0714_0x0f484c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f484cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xaa1e03e8ULL) ^ 0x07a4a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0715 | PC: 0x0f4a40 | FDE: 0x07a528 | Size: 256 bytes
// Khung tháo gỡ #0715 | Địa chỉ PC: 0x0f4a40 | Địa chỉ FDE: 0x07a528 | Kích thước: 256 bytes
//   0x0f4a40: 12850029  mov      w9, #-0x2802
//   0x0f4a44: 0B090049  add      w9, w2, w9
//   0x0f4a48: 7100093F  cmp      w9, #2
//   0x0f4a4c: 52900E49  mov      w9, #0x8072
static inline uint64_t fde_func_0715_0x0f4a40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4a40ULL ^ (static_cast<uint64_t>(0x12850029ULL) << 13);
    acc = (acc + a1 + 0x0b090049ULL) ^ 0x07a528ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0716 | PC: 0x0f4bfc | FDE: 0x07a5a0 | Size: 256 bytes
// Khung tháo gỡ #0716 | Địa chỉ PC: 0x0f4bfc | Địa chỉ FDE: 0x07a5a0 | Kích thước: 256 bytes
//   0x0f4bfc: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0f4c00: F9400008  ldr      x8, [x0]
//   0x0f4c04: B9400801  ldr      w1, [x0, #8]
//   0x0f4c08: BD400C00  ldr      s0, [x0, #0xc]
static inline uint64_t fde_func_0716_0x0f4bfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4bfcULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x07a5a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0717 | PC: 0x0f4f88 | FDE: 0x07a640 | Size: 256 bytes
// Khung tháo gỡ #0717 | Địa chỉ PC: 0x0f4f88 | Địa chỉ FDE: 0x07a640 | Kích thước: 256 bytes
//   0x0f4f88: AA1E03E8  mov      x8, x30
//   0x0f4f8c: 94020740  bl       #0x176c8c
//   0x0f4f90: AA0803FE  mov      x30, x8
//   0x0f4f94: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_0717_0x0f4f88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4f88ULL ^ (static_cast<uint64_t>(0xaa1e03e8ULL) << 13);
    acc = (acc + a1 + 0x94020740ULL) ^ 0x07a640ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0718 | PC: 0x0f5178 | FDE: 0x07a6e0 | Size: 256 bytes
// Khung tháo gỡ #0718 | Địa chỉ PC: 0x0f5178 | Địa chỉ FDE: 0x07a6e0 | Kích thước: 256 bytes
//   0x0f5178: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x0f517c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0f5180: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0f5184: AA0103F7  mov      x23, x1
static inline uint64_t fde_func_0718_0x0f5178(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5178ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x07a6e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0719 | PC: 0x0f559c | FDE: 0x07a788 | Size: 256 bytes
// Khung tháo gỡ #0719 | Địa chỉ PC: 0x0f559c | Địa chỉ FDE: 0x07a788 | Kích thước: 256 bytes
//   0x0f559c: AA1E03E8  mov      x8, x30
//   0x0f55a0: 940209EB  bl       #0x177d4c
//   0x0f55a4: AA0803FE  mov      x30, x8
//   0x0f55a8: A90A7BFD  stp      x29, x30, [sp, #0xa0]
static inline uint64_t fde_func_0719_0x0f559c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f559cULL ^ (static_cast<uint64_t>(0xaa1e03e8ULL) << 13);
    acc = (acc + a1 + 0x940209ebULL) ^ 0x07a788ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0720 | PC: 0x0f5b9c | FDE: 0x07a840 | Size: 256 bytes
// Khung tháo gỡ #0720 | Địa chỉ PC: 0x0f5b9c | Địa chỉ FDE: 0x07a840 | Kích thước: 256 bytes
//   0x0f5b9c: D103C3FF  sub      sp, sp, #0xf0
//   0x0f5ba0: AA1E03E7  mov      x7, x30
//   0x0f5ba4: 94021245  bl       #0x17a4b8
//   0x0f5ba8: AA0703FE  mov      x30, x7
static inline uint64_t fde_func_0720_0x0f5b9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5b9cULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xaa1e03e7ULL) ^ 0x07a840ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0721 | PC: 0x0f5ee0 | FDE: 0x07a900 | Size: 256 bytes
// Khung tháo gỡ #0721 | Địa chỉ PC: 0x0f5ee0 | Địa chỉ FDE: 0x07a900 | Kích thước: 256 bytes
//   0x0f5ee0: D103C3FF  sub      sp, sp, #0xf0
//   0x0f5ee4: AA1E03E8  mov      x8, x30
//   0x0f5ee8: 94021174  bl       #0x17a4b8
//   0x0f5eec: AA0803FE  mov      x30, x8
static inline uint64_t fde_func_0721_0x0f5ee0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5ee0ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xaa1e03e8ULL) ^ 0x07a900ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0722 | PC: 0x0f65e8 | FDE: 0x07a998 | Size: 256 bytes
// Khung tháo gỡ #0722 | Địa chỉ PC: 0x0f65e8 | Địa chỉ FDE: 0x07a998 | Kích thước: 256 bytes
//   0x0f65e8: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0f65ec: 94023C84  bl       #0x1857fc
//   0x0f65f0: 94024B40  bl       #0x1892f0
//   0x0f65f4: 52800280  mov      w0, #0x14
static inline uint64_t fde_func_0722_0x0f65e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f65e8ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x94023c84ULL) ^ 0x07a998ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0723 | PC: 0x0f6928 | FDE: 0x07aa28 | Size: 256 bytes
// Khung tháo gỡ #0723 | Địa chỉ PC: 0x0f6928 | Địa chỉ FDE: 0x07aa28 | Kích thước: 256 bytes
//   0x0f6928: AA1E03E8  mov      x8, x30
//   0x0f692c: 9402021F  bl       #0x1771a8
//   0x0f6930: AA0803FE  mov      x30, x8
//   0x0f6934: A90B7BFD  stp      x29, x30, [sp, #0xb0]
static inline uint64_t fde_func_0723_0x0f6928(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f6928ULL ^ (static_cast<uint64_t>(0xaa1e03e8ULL) << 13);
    acc = (acc + a1 + 0x9402021fULL) ^ 0x07aa28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0724 | PC: 0x0f6c34 | FDE: 0x07aad0 | Size: 256 bytes
// Khung tháo gỡ #0724 | Địa chỉ PC: 0x0f6c34 | Địa chỉ FDE: 0x07aad0 | Kích thước: 256 bytes
//   0x0f6c34: AA1E03E8  mov      x8, x30
//   0x0f6c38: 94021201  bl       #0x17b43c
//   0x0f6c3c: AA0803FE  mov      x30, x8
//   0x0f6c40: A90C7BFD  stp      x29, x30, [sp, #0xc0]
static inline uint64_t fde_func_0724_0x0f6c34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f6c34ULL ^ (static_cast<uint64_t>(0xaa1e03e8ULL) << 13);
    acc = (acc + a1 + 0x94021201ULL) ^ 0x07aad0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0725 | PC: 0x0f70e8 | FDE: 0x07ab90 | Size: 256 bytes
// Khung tháo gỡ #0725 | Địa chỉ PC: 0x0f70e8 | Địa chỉ FDE: 0x07ab90 | Kích thước: 256 bytes
//   0x0f70e8: AA1E03E8  mov      x8, x30
//   0x0f70ec: 940229CF  bl       #0x181828
//   0x0f70f0: AA0803FE  mov      x30, x8
//   0x0f70f4: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_0725_0x0f70e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f70e8ULL ^ (static_cast<uint64_t>(0xaa1e03e8ULL) << 13);
    acc = (acc + a1 + 0x940229cfULL) ^ 0x07ab90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0726 | PC: 0x0f73b4 | FDE: 0x07ac40 | Size: 256 bytes
// Khung tháo gỡ #0726 | Địa chỉ PC: 0x0f73b4 | Địa chỉ FDE: 0x07ac40 | Kích thước: 256 bytes
//   0x0f73b4: D10143FF  sub      sp, sp, #0x50
//   0x0f73b8: F90013F6  str      x22, [sp, #0x20]
//   0x0f73bc: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x0f73c0: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0726_0x0f73b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f73b4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x07ac40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0727 | PC: 0x0f7544 | FDE: 0x07acb8 | Size: 256 bytes
// Khung tháo gỡ #0727 | Địa chỉ PC: 0x0f7544 | Địa chỉ FDE: 0x07acb8 | Kích thước: 256 bytes
//   0x0f7544: D10143FF  sub      sp, sp, #0x50
//   0x0f7548: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0f754c: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x0f7550: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0727_0x0f7544(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f7544ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x07acb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0728 | PC: 0x0f76e8 | FDE: 0x07ad30 | Size: 256 bytes
// Khung tháo gỡ #0728 | Địa chỉ PC: 0x0f76e8 | Địa chỉ FDE: 0x07ad30 | Kích thước: 256 bytes
//   0x0f76e8: AA1E03E6  mov      x6, x30
//   0x0f76ec: 94021647  bl       #0x17d008
//   0x0f76f0: AA0603FE  mov      x30, x6
//   0x0f76f4: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0728_0x0f76e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f76e8ULL ^ (static_cast<uint64_t>(0xaa1e03e6ULL) << 13);
    acc = (acc + a1 + 0x94021647ULL) ^ 0x07ad30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0729 | PC: 0x0f78d4 | FDE: 0x07adb8 | Size: 256 bytes
// Khung tháo gỡ #0729 | Địa chỉ PC: 0x0f78d4 | Địa chỉ FDE: 0x07adb8 | Kích thước: 256 bytes
//   0x0f78d4: AA1E03E8  mov      x8, x30
//   0x0f78d8: 9401FE34  bl       #0x1771a8
//   0x0f78dc: AA0803FE  mov      x30, x8
//   0x0f78e0: A90B7BFD  stp      x29, x30, [sp, #0xb0]
static inline uint64_t fde_func_0729_0x0f78d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f78d4ULL ^ (static_cast<uint64_t>(0xaa1e03e8ULL) << 13);
    acc = (acc + a1 + 0x9401fe34ULL) ^ 0x07adb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0730 | PC: 0x0f7bc8 | FDE: 0x07ae58 | Size: 256 bytes
// Khung tháo gỡ #0730 | Địa chỉ PC: 0x0f7bc8 | Địa chỉ FDE: 0x07ae58 | Kích thước: 256 bytes
//   0x0f7bc8: D10103FF  sub      sp, sp, #0x40
//   0x0f7bcc: F9001BFE  str      x30, [sp, #0x30]
//   0x0f7bd0: 3DC013E0  ldr      q0, [sp, #0x40]
//   0x0f7bd4: A9452BE9  ldp      x9, x10, [sp, #0x50]
static inline uint64_t fde_func_0730_0x0f7bc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f7bc8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfeULL) ^ 0x07ae58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0731 | PC: 0x0f7ce8 | FDE: 0x07aed0 | Size: 256 bytes
// Khung tháo gỡ #0731 | Địa chỉ PC: 0x0f7ce8 | Địa chỉ FDE: 0x07aed0 | Kích thước: 256 bytes
//   0x0f7ce8: B4000201  cbz      x1, #0xf7d28
//   0x0f7cec: D10143FF  sub      sp, sp, #0x50
//   0x0f7cf0: F9001BF4  str      x20, [sp, #0x30]
//   0x0f7cf4: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0731_0x0f7ce8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f7ce8ULL ^ (static_cast<uint64_t>(0xb4000201ULL) << 13);
    acc = (acc + a1 + 0xd10143ffULL) ^ 0x07aed0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0732 | PC: 0x0f7e04 | FDE: 0x07af50 | Size: 256 bytes
// Khung tháo gỡ #0732 | Địa chỉ PC: 0x0f7e04 | Địa chỉ FDE: 0x07af50 | Kích thước: 256 bytes
//   0x0f7e04: AA1E03E8  mov      x8, x30
//   0x0f7e08: 9401FFD1  bl       #0x177d4c
//   0x0f7e0c: AA0803FE  mov      x30, x8
//   0x0f7e10: A90A7BFD  stp      x29, x30, [sp, #0xa0]
static inline uint64_t fde_func_0732_0x0f7e04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f7e04ULL ^ (static_cast<uint64_t>(0xaa1e03e8ULL) << 13);
    acc = (acc + a1 + 0x9401ffd1ULL) ^ 0x07af50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0733 | PC: 0x0f8088 | FDE: 0x07aff0 | Size: 256 bytes
// Khung tháo gỡ #0733 | Địa chỉ PC: 0x0f8088 | Địa chỉ FDE: 0x07aff0 | Kích thước: 256 bytes
//   0x0f8088: B4000241  cbz      x1, #0xf80d0
//   0x0f808c: D10143FF  sub      sp, sp, #0x50
//   0x0f8090: F9001BF4  str      x20, [sp, #0x30]
//   0x0f8094: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0733_0x0f8088(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8088ULL ^ (static_cast<uint64_t>(0xb4000241ULL) << 13);
    acc = (acc + a1 + 0xd10143ffULL) ^ 0x07aff0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0734 | PC: 0x0f81a8 | FDE: 0x07b070 | Size: 256 bytes
// Khung tháo gỡ #0734 | Địa chỉ PC: 0x0f81a8 | Địa chỉ FDE: 0x07b070 | Kích thước: 256 bytes
//   0x0f81a8: B4000221  cbz      x1, #0xf81ec
//   0x0f81ac: D10143FF  sub      sp, sp, #0x50
//   0x0f81b0: F9001BF4  str      x20, [sp, #0x30]
//   0x0f81b4: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0734_0x0f81a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f81a8ULL ^ (static_cast<uint64_t>(0xb4000221ULL) << 13);
    acc = (acc + a1 + 0xd10143ffULL) ^ 0x07b070ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0735 | PC: 0x0f834c | FDE: 0x07b100 | Size: 256 bytes
// Khung tháo gỡ #0735 | Địa chỉ PC: 0x0f834c | Địa chỉ FDE: 0x07b100 | Kích thước: 256 bytes
//   0x0f834c: AA1E03E8  mov      x8, x30
//   0x0f8350: 94020BD5  bl       #0x17b2a4
//   0x0f8354: AA0803FE  mov      x30, x8
//   0x0f8358: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0735_0x0f834c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f834cULL ^ (static_cast<uint64_t>(0xaa1e03e8ULL) << 13);
    acc = (acc + a1 + 0x94020bd5ULL) ^ 0x07b100ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0736 | PC: 0x0f8500 | FDE: 0x07b188 | Size: 256 bytes
// Khung tháo gỡ #0736 | Địa chỉ PC: 0x0f8500 | Địa chỉ FDE: 0x07b188 | Kích thước: 256 bytes
//   0x0f8500: B4000221  cbz      x1, #0xf8544
//   0x0f8504: D10103FF  sub      sp, sp, #0x40
//   0x0f8508: F90013F4  str      x20, [sp, #0x20]
//   0x0f850c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0736_0x0f8500(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8500ULL ^ (static_cast<uint64_t>(0xb4000221ULL) << 13);
    acc = (acc + a1 + 0xd10103ffULL) ^ 0x07b188ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0737 | PC: 0x0f8638 | FDE: 0x07b208 | Size: 256 bytes
// Khung tháo gỡ #0737 | Địa chỉ PC: 0x0f8638 | Địa chỉ FDE: 0x07b208 | Kích thước: 256 bytes
//   0x0f8638: D10103FF  sub      sp, sp, #0x40
//   0x0f863c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0f8640: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0f8644: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0737_0x0f8638(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8638ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x07b208ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0738 | PC: 0x0f8780 | FDE: 0x07b280 | Size: 256 bytes
// Khung tháo gỡ #0738 | Địa chỉ PC: 0x0f8780 | Địa chỉ FDE: 0x07b280 | Kích thước: 256 bytes
//   0x0f8780: D101C3FF  sub      sp, sp, #0x70
//   0x0f8784: F90023F6  str      x22, [sp, #0x40]
//   0x0f8788: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x0f878c: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_0738_0x0f8780(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8780ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f6ULL) ^ 0x07b280ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0739 | PC: 0x0f88e0 | FDE: 0x07b300 | Size: 256 bytes
// Khung tháo gỡ #0739 | Địa chỉ PC: 0x0f88e0 | Địa chỉ FDE: 0x07b300 | Kích thước: 256 bytes
//   0x0f88e0: D101C3FF  sub      sp, sp, #0x70
//   0x0f88e4: F90023F6  str      x22, [sp, #0x40]
//   0x0f88e8: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x0f88ec: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_0739_0x0f88e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f88e0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f6ULL) ^ 0x07b300ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0740 | PC: 0x0f8a48 | FDE: 0x07b380 | Size: 256 bytes
// Khung tháo gỡ #0740 | Địa chỉ PC: 0x0f8a48 | Địa chỉ FDE: 0x07b380 | Kích thước: 256 bytes
//   0x0f8a48: D101C3FF  sub      sp, sp, #0x70
//   0x0f8a4c: F90023F6  str      x22, [sp, #0x40]
//   0x0f8a50: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x0f8a54: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_0740_0x0f8a48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8a48ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f6ULL) ^ 0x07b380ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0741 | PC: 0x0f8ba8 | FDE: 0x07b400 | Size: 256 bytes
// Khung tháo gỡ #0741 | Địa chỉ PC: 0x0f8ba8 | Địa chỉ FDE: 0x07b400 | Kích thước: 256 bytes
//   0x0f8ba8: D101C3FF  sub      sp, sp, #0x70
//   0x0f8bac: F90023F6  str      x22, [sp, #0x40]
//   0x0f8bb0: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x0f8bb4: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_0741_0x0f8ba8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8ba8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f6ULL) ^ 0x07b400ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0742 | PC: 0x0f8d10 | FDE: 0x07b480 | Size: 256 bytes
// Khung tháo gỡ #0742 | Địa chỉ PC: 0x0f8d10 | Địa chỉ FDE: 0x07b480 | Kích thước: 256 bytes
//   0x0f8d10: D10103FF  sub      sp, sp, #0x40
//   0x0f8d14: F9000BF6  str      x22, [sp, #0x10]
//   0x0f8d18: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0f8d1c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0742_0x0f8d10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8d10ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x07b480ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0743 | PC: 0x0f8f68 | FDE: 0x07b508 | Size: 256 bytes
// Khung tháo gỡ #0743 | Địa chỉ PC: 0x0f8f68 | Địa chỉ FDE: 0x07b508 | Kích thước: 256 bytes
//   0x0f8f68: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0f8f6c: 94020ABF  bl       #0x17ba68
//   0x0f8f70: 94024108  bl       #0x189390
//   0x0f8f74: 52800280  mov      w0, #0x14
static inline uint64_t fde_func_0743_0x0f8f68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f8f68ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x94020abfULL) ^ 0x07b508ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0744 | PC: 0x0f9124 | FDE: 0x07b580 | Size: 256 bytes
// Khung tháo gỡ #0744 | Địa chỉ PC: 0x0f9124 | Địa chỉ FDE: 0x07b580 | Kích thước: 256 bytes
//   0x0f9124: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0f9128: 9402201C  bl       #0x181198
//   0x0f912c: 940229F8  bl       #0x18390c
//   0x0f9130: A8C17BF3  ldp      x19, x30, [sp], #0x10
static inline uint64_t fde_func_0744_0x0f9124(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9124ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9402201cULL) ^ 0x07b580ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0745 | PC: 0x0f92d8 | FDE: 0x07b5f0 | Size: 256 bytes
// Khung tháo gỡ #0745 | Địa chỉ PC: 0x0f92d8 | Địa chỉ FDE: 0x07b5f0 | Kích thước: 256 bytes
//   0x0f92d8: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0f92dc: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0f92e0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0f92e4: B943EC08  ldr      w8, [x0, #0x3ec]
static inline uint64_t fde_func_0745_0x0f92d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f92d8ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x07b5f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0746 | PC: 0x0f9638 | FDE: 0x07b670 | Size: 248 bytes
// Khung tháo gỡ #0746 | Địa chỉ PC: 0x0f9638 | Địa chỉ FDE: 0x07b670 | Kích thước: 248 bytes
//   0x0f9638: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0f963c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0f9640: 2A0203F5  mov      w21, w2
//   0x0f9644: AA0103E2  mov      x2, x1
static inline uint64_t fde_func_0746_0x0f9638(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9638ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x07b670ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0747 | PC: 0x0f9730 | FDE: 0x07b6e0 | Size: 256 bytes
// Khung tháo gỡ #0747 | Địa chỉ PC: 0x0f9730 | Địa chỉ FDE: 0x07b6e0 | Kích thước: 256 bytes
//   0x0f9730: 39412000  ldrb     w0, [x0, #0x48]
//   0x0f9734: D65F03C0  ret      
//   0x0f9738: D10103FF  sub      sp, sp, #0x40
//   0x0f973c: A9015BF7  stp      x23, x22, [sp, #0x10]
static inline uint64_t fde_func_0747_0x0f9730(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9730ULL ^ (static_cast<uint64_t>(0x39412000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x07b6e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0748 | PC: 0x0f9838 | FDE: 0x07b748 | Size: 256 bytes
// Khung tháo gỡ #0748 | Địa chỉ PC: 0x0f9838 | Địa chỉ FDE: 0x07b748 | Kích thước: 256 bytes
//   0x0f9838: F9401408  ldr      x8, [x0, #0x28]
//   0x0f983c: 52800069  mov      w9, #3
//   0x0f9840: B9006C09  str      w9, [x0, #0x6c]
//   0x0f9844: B9406801  ldr      w1, [x0, #0x68]
static inline uint64_t fde_func_0748_0x0f9838(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9838ULL ^ (static_cast<uint64_t>(0xf9401408ULL) << 13);
    acc = (acc + a1 + 0x52800069ULL) ^ 0x07b748ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0749 | PC: 0x0f9940 | FDE: 0x07b7c8 | Size: 132 bytes
// Khung tháo gỡ #0749 | Địa chỉ PC: 0x0f9940 | Địa chỉ FDE: 0x07b7c8 | Kích thước: 132 bytes
//   0x0f9940: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0f9944: AA0003F3  mov      x19, x0
//   0x0f9948: 97FFFFDE  bl       #0xf98c0
//   0x0f994c: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_0749_0x0f9940(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9940ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x07b7c8ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0750 | PC: 0x0f99c4 | FDE: 0x07b830 | Size: 148 bytes
// Khung tháo gỡ #0750 | Địa chỉ PC: 0x0f99c4 | Địa chỉ FDE: 0x07b830 | Kích thước: 148 bytes
//   0x0f99c4: D100C3FF  sub      sp, sp, #0x30
//   0x0f99c8: F9000BF4  str      x20, [sp, #0x10]
//   0x0f99cc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0f99d0: 940216BE  bl       #0x17f4c8
static inline uint64_t fde_func_0750_0x0f99c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f99c4ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x07b830ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0751 | PC: 0x0f9a58 | FDE: 0x07b898 | Size: 256 bytes
// Khung tháo gỡ #0751 | Địa chỉ PC: 0x0f9a58 | Địa chỉ FDE: 0x07b898 | Kích thước: 256 bytes
//   0x0f9a58: D100C3FF  sub      sp, sp, #0x30
//   0x0f9a5c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0f9a60: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0f9a64: 9100C034  add      x20, x1, #0x30
static inline uint64_t fde_func_0751_0x0f9a58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9a58ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x07b898ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0752 | PC: 0x0f9b68 | FDE: 0x07b908 | Size: 256 bytes
// Khung tháo gỡ #0752 | Địa chỉ PC: 0x0f9b68 | Địa chỉ FDE: 0x07b908 | Kích thước: 256 bytes
//   0x0f9b68: AA1E03E2  mov      x2, x30
//   0x0f9b6c: 9402078A  bl       #0x17b994
//   0x0f9b70: AA0203FE  mov      x30, x2
//   0x0f9b74: A9167BF3  stp      x19, x30, [sp, #0x160]
static inline uint64_t fde_func_0752_0x0f9b68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9b68ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9402078aULL) ^ 0x07b908ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0753 | PC: 0x0f9d34 | FDE: 0x07b990 | Size: 148 bytes
// Khung tháo gỡ #0753 | Địa chỉ PC: 0x0f9d34 | Địa chỉ FDE: 0x07b990 | Kích thước: 148 bytes
//   0x0f9d34: 3941C000  ldrb     w0, [x0, #0x70]
//   0x0f9d38: D65F03C0  ret      
//   0x0f9d3c: D100C3FF  sub      sp, sp, #0x30
//   0x0f9d40: A90153F5  stp      x21, x20, [sp, #0x10]
static inline uint64_t fde_func_0753_0x0f9d34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9d34ULL ^ (static_cast<uint64_t>(0x3941c000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x07b990ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0754 | PC: 0x0f9dc8 | FDE: 0x07b9f8 | Size: 256 bytes
// Khung tháo gỡ #0754 | Địa chỉ PC: 0x0f9dc8 | Địa chỉ FDE: 0x07b9f8 | Kích thước: 256 bytes
//   0x0f9dc8: B4000141  cbz      x1, #0xf9df0
//   0x0f9dcc: A945A408  ldp      x8, x9, [x0, #0x58]
//   0x0f9dd0: CB080129  sub      x9, x9, x8
//   0x0f9dd4: B40000E9  cbz      x9, #0xf9df0
static inline uint64_t fde_func_0754_0x0f9dc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9dc8ULL ^ (static_cast<uint64_t>(0xb4000141ULL) << 13);
    acc = (acc + a1 + 0xa945a408ULL) ^ 0x07b9f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0755 | PC: 0x0f9f14 | FDE: 0x07ba70 | Size: 256 bytes
// Khung tháo gỡ #0755 | Địa chỉ PC: 0x0f9f14 | Địa chỉ FDE: 0x07ba70 | Kích thước: 256 bytes
//   0x0f9f14: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0f9f18: F00004A8  adrp     x8, #0x190000
//   0x0f9f1c: 911E8108  add      x8, x8, #0x7a0
//   0x0f9f20: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0755_0x0f9f14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f9f14ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf00004a8ULL) ^ 0x07ba70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0756 | PC: 0x0fa0b0 | FDE: 0x07bae0 | Size: 236 bytes
// Khung tháo gỡ #0756 | Địa chỉ PC: 0x0fa0b0 | Địa chỉ FDE: 0x07bae0 | Kích thước: 236 bytes
//   0x0fa0b0: D100C3FF  sub      sp, sp, #0x30
//   0x0fa0b4: F9000BF4  str      x20, [sp, #0x10]
//   0x0fa0b8: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0fa0bc: 9401FA70  bl       #0x178a7c
static inline uint64_t fde_func_0756_0x0fa0b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fa0b0ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x07bae0ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0757 | PC: 0x0fa19c | FDE: 0x07bb50 | Size: 212 bytes
// Khung tháo gỡ #0757 | Địa chỉ PC: 0x0fa19c | Địa chỉ FDE: 0x07bb50 | Kích thước: 212 bytes
//   0x0fa19c: 14021AAE  b        #0x180c54
//   0x0fa1a0: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0fa1a4: F9400001  ldr      x1, [x0]
//   0x0fa1a8: 52800020  mov      w0, #1
static inline uint64_t fde_func_0757_0x0fa19c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fa19cULL ^ (static_cast<uint64_t>(0x14021aaeULL) << 13);
    acc = (acc + a1 + 0xf81f0ffeULL) ^ 0x07bb50ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0758 | PC: 0x0fa270 | FDE: 0x07bbc0 | Size: 88 bytes
// Khung tháo gỡ #0758 | Địa chỉ PC: 0x0fa270 | Địa chỉ FDE: 0x07bbc0 | Kích thước: 88 bytes
//   0x0fa270: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0fa274: D00004A8  adrp     x8, #0x190000
//   0x0fa278: 91210108  add      x8, x8, #0x840
//   0x0fa27c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0758_0x0fa270(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fa270ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xd00004a8ULL) ^ 0x07bbc0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0759 | PC: 0x0fa2c8 | FDE: 0x07bc20 | Size: 256 bytes
// Khung tháo gỡ #0759 | Địa chỉ PC: 0x0fa2c8 | Địa chỉ FDE: 0x07bc20 | Kích thước: 256 bytes
//   0x0fa2c8: B4000080  cbz      x0, #0xfa2d8
//   0x0fa2cc: F9400008  ldr      x8, [x0]
//   0x0fa2d0: F9401901  ldr      x1, [x8, #0x30]
//   0x0fa2d4: D61F0020  br       x1
static inline uint64_t fde_func_0759_0x0fa2c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fa2c8ULL ^ (static_cast<uint64_t>(0xb4000080ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x07bc20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0760 | PC: 0x0fa498 | FDE: 0x07bc98 | Size: 256 bytes
// Khung tháo gỡ #0760 | Địa chỉ PC: 0x0fa498 | Địa chỉ FDE: 0x07bc98 | Kích thước: 256 bytes
//   0x0fa498: D10583FF  sub      sp, sp, #0x160
//   0x0fa49c: F9009BFC  str      x28, [sp, #0x130]
//   0x0fa4a0: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0fa4a4: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0760_0x0fa498(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fa498ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x07bc98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0761 | PC: 0x0fa5c8 | FDE: 0x07bd08 | Size: 256 bytes
// Khung tháo gỡ #0761 | Địa chỉ PC: 0x0fa5c8 | Địa chỉ FDE: 0x07bd08 | Kích thước: 256 bytes
//   0x0fa5c8: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0fa5cc: F9400000  ldr      x0, [x0]
//   0x0fa5d0: 97FFB0F8  bl       #0xe69b0
//   0x0fa5d4: 52800100  mov      w0, #8
static inline uint64_t fde_func_0761_0x0fa5c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fa5c8ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400000ULL) ^ 0x07bd08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0762 | PC: 0x0fa780 | FDE: 0x07bd90 | Size: 256 bytes
// Khung tháo gỡ #0762 | Địa chỉ PC: 0x0fa780 | Địa chỉ FDE: 0x07bd90 | Kích thước: 256 bytes
//   0x0fa780: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0fa784: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0fa788: F9400008  ldr      x8, [x0]
//   0x0fa78c: 9401F091  bl       #0x1769d0
static inline uint64_t fde_func_0762_0x0fa780(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fa780ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x07bd90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0763 | PC: 0x0fa8fc | FDE: 0x07be10 | Size: 256 bytes
// Khung tháo gỡ #0763 | Địa chỉ PC: 0x0fa8fc | Địa chỉ FDE: 0x07be10 | Kích thước: 256 bytes
//   0x0fa8fc: D10143FF  sub      sp, sp, #0x50
//   0x0fa900: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x0fa904: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x0fa908: 94022B3A  bl       #0x1855f0
static inline uint64_t fde_func_0763_0x0fa8fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fa8fcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90353f5ULL) ^ 0x07be10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0764 | PC: 0x0fab60 | FDE: 0x07be88 | Size: 256 bytes
// Khung tháo gỡ #0764 | Địa chỉ PC: 0x0fab60 | Địa chỉ FDE: 0x07be88 | Kích thước: 256 bytes
//   0x0fab60: D10183FF  sub      sp, sp, #0x60
//   0x0fab64: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x0fab68: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x0fab6c: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0764_0x0fab60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fab60ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9035bf7ULL) ^ 0x07be88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0765 | PC: 0x0fb144 | FDE: 0x07bf10 | Size: 172 bytes
// Khung tháo gỡ #0765 | Địa chỉ PC: 0x0fb144 | Địa chỉ FDE: 0x07bf10 | Kích thước: 172 bytes
//   0x0fb144: B00004A8  adrp     x8, #0x190000
//   0x0fb148: 91244108  add      x8, x8, #0x910
//   0x0fb14c: F9000008  str      x8, [x0]
//   0x0fb150: 140155E5  b        #0x1508e4
static inline uint64_t fde_func_0765_0x0fb144(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb144ULL ^ (static_cast<uint64_t>(0xb00004a8ULL) << 13);
    acc = (acc + a1 + 0x91244108ULL) ^ 0x07bf10ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0766 | PC: 0x0fb1f0 | FDE: 0x07bf78 | Size: 256 bytes
// Khung tháo gỡ #0766 | Địa chỉ PC: 0x0fb1f0 | Địa chỉ FDE: 0x07bf78 | Kích thước: 256 bytes
//   0x0fb1f0: AA1E03E2  mov      x2, x30
//   0x0fb1f4: 9401F55B  bl       #0x178760
//   0x0fb1f8: AA0203FE  mov      x30, x2
//   0x0fb1fc: A9167BF3  stp      x19, x30, [sp, #0x160]
static inline uint64_t fde_func_0766_0x0fb1f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb1f0ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9401f55bULL) ^ 0x07bf78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0767 | PC: 0x0fb384 | FDE: 0x07bfe8 | Size: 188 bytes
// Khung tháo gỡ #0767 | Địa chỉ PC: 0x0fb384 | Địa chỉ FDE: 0x07bfe8 | Kích thước: 188 bytes
//   0x0fb384: 91006000  add      x0, x0, #0x18
//   0x0fb388: 14000001  b        #0xfb38c
//   0x0fb38c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0fb390: A9017BF3  stp      x19, x30, [sp, #0x10]
static inline uint64_t fde_func_0767_0x0fb384(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb384ULL ^ (static_cast<uint64_t>(0x91006000ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x07bfe8ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0768 | PC: 0x0fb440 | FDE: 0x07c058 | Size: 188 bytes
// Khung tháo gỡ #0768 | Địa chỉ PC: 0x0fb440 | Địa chỉ FDE: 0x07c058 | Kích thước: 188 bytes
//   0x0fb440: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0fb444: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0fb448: A9405414  ldp      x20, x21, [x0]
//   0x0fb44c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0768_0x0fb440(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb440ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x07c058ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0769 | PC: 0x0fb4fc | FDE: 0x07c0d0 | Size: 208 bytes
// Khung tháo gỡ #0769 | Địa chỉ PC: 0x0fb4fc | Địa chỉ FDE: 0x07c0d0 | Kích thước: 208 bytes
//   0x0fb4fc: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0fb500: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0fb504: F9400415  ldr      x21, [x0, #8]
//   0x0fb508: 9401E9BB  bl       #0x175bf4
static inline uint64_t fde_func_0769_0x0fb4fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb4fcULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x07c0d0ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0770 | PC: 0x0fb5cc | FDE: 0x07c140 | Size: 256 bytes
// Khung tháo gỡ #0770 | Địa chỉ PC: 0x0fb5cc | Địa chỉ FDE: 0x07c140 | Kích thước: 256 bytes
//   0x0fb5cc: D100C3FF  sub      sp, sp, #0x30
//   0x0fb5d0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0fb5d4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0fb5d8: F9404415  ldr      x21, [x0, #0x88]
static inline uint64_t fde_func_0770_0x0fb5cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb5ccULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x07c140ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0771 | PC: 0x0fb7c0 | FDE: 0x07c1b8 | Size: 256 bytes
// Khung tháo gỡ #0771 | Địa chỉ PC: 0x0fb7c0 | Địa chỉ FDE: 0x07c1b8 | Kích thước: 256 bytes
//   0x0fb7c0: D100C3FF  sub      sp, sp, #0x30
//   0x0fb7c4: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0fb7c8: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0fb7cc: 94020EDF  bl       #0x17f348
static inline uint64_t fde_func_0771_0x0fb7c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fb7c0ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x07c1b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0772 | PC: 0x0fc5b4 | FDE: 0x07c240 | Size: 256 bytes
// Khung tháo gỡ #0772 | Địa chỉ PC: 0x0fc5b4 | Địa chỉ FDE: 0x07c240 | Kích thước: 256 bytes
//   0x0fc5b4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0fc5b8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0fc5bc: AA0103F3  mov      x19, x1
//   0x0fc5c0: B8408428  ldr      w8, [x1], #8
static inline uint64_t fde_func_0772_0x0fc5b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fc5b4ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x07c240ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0773 | PC: 0x0fc728 | FDE: 0x07c2c0 | Size: 212 bytes
// Khung tháo gỡ #0773 | Địa chỉ PC: 0x0fc728 | Địa chỉ FDE: 0x07c2c0 | Kích thước: 212 bytes
//   0x0fc728: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0fc72c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0fc730: 9401FB2F  bl       #0x17b3ec
//   0x0fc734: B9403268  ldr      w8, [x19, #0x30]
static inline uint64_t fde_func_0773_0x0fc728(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fc728ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x07c2c0ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0774 | PC: 0x0fc7fc | FDE: 0x07c330 | Size: 256 bytes
// Khung tháo gỡ #0774 | Địa chỉ PC: 0x0fc7fc | Địa chỉ FDE: 0x07c330 | Kích thước: 256 bytes
//   0x0fc7fc: D10083FF  sub      sp, sp, #0x20
//   0x0fc800: F9000BFE  str      x30, [sp, #0x10]
//   0x0fc804: B4000241  cbz      x1, #0xfc84c
//   0x0fc808: 39414028  ldrb     w8, [x1, #0x50]
static inline uint64_t fde_func_0774_0x0fc7fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fc7fcULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfeULL) ^ 0x07c330ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0775 | PC: 0x0fca10 | FDE: 0x07c3b0 | Size: 248 bytes
// Khung tháo gỡ #0775 | Địa chỉ PC: 0x0fca10 | Địa chỉ FDE: 0x07c3b0 | Kích thước: 248 bytes
//   0x0fca10: D10583FF  sub      sp, sp, #0x160
//   0x0fca14: F9009BFC  str      x28, [sp, #0x130]
//   0x0fca18: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x0fca1c: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_0775_0x0fca10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fca10ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x07c3b0ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0776 | PC: 0x0fcb08 | FDE: 0x07c420 | Size: 256 bytes
// Khung tháo gỡ #0776 | Địa chỉ PC: 0x0fcb08 | Địa chỉ FDE: 0x07c420 | Kích thước: 256 bytes
//   0x0fcb08: 14020D97  b        #0x180164
//   0x0fcb0c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0fcb10: F9400000  ldr      x0, [x0]
//   0x0fcb14: 97FFA7AA  bl       #0xe69bc
static inline uint64_t fde_func_0776_0x0fcb08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fcb08ULL ^ (static_cast<uint64_t>(0x14020d97ULL) << 13);
    acc = (acc + a1 + 0xf81f0ffeULL) ^ 0x07c420ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0777 | PC: 0x0fccf0 | FDE: 0x07c490 | Size: 256 bytes
// Khung tháo gỡ #0777 | Địa chỉ PC: 0x0fccf0 | Địa chỉ FDE: 0x07c490 | Kích thước: 256 bytes
//   0x0fccf0: 140001D9  b        #0xfd454
//   0x0fccf4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0fccf8: AA0003F3  mov      x19, x0
//   0x0fccfc: 940001D6  bl       #0xfd454
static inline uint64_t fde_func_0777_0x0fccf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fccf0ULL ^ (static_cast<uint64_t>(0x140001d9ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bf3ULL) ^ 0x07c490ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0778 | PC: 0x0fce30 | FDE: 0x07c508 | Size: 256 bytes
// Khung tháo gỡ #0778 | Địa chỉ PC: 0x0fce30 | Địa chỉ FDE: 0x07c508 | Kích thước: 256 bytes
//   0x0fce30: AA1E03E6  mov      x6, x30
//   0x0fce34: 9401EC90  bl       #0x178074
//   0x0fce38: AA0603FE  mov      x30, x6
//   0x0fce3c: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0778_0x0fce30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fce30ULL ^ (static_cast<uint64_t>(0xaa1e03e6ULL) << 13);
    acc = (acc + a1 + 0x9401ec90ULL) ^ 0x07c508ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0779 | PC: 0x0fd010 | FDE: 0x07c590 | Size: 256 bytes
// Khung tháo gỡ #0779 | Địa chỉ PC: 0x0fd010 | Địa chỉ FDE: 0x07c590 | Kích thước: 256 bytes
//   0x0fd010: D100C3FF  sub      sp, sp, #0x30
//   0x0fd014: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0fd018: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0fd01c: F941C408  ldr      x8, [x0, #0x388]
static inline uint64_t fde_func_0779_0x0fd010(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fd010ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x07c590ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0780 | PC: 0x0fd450 | FDE: 0x07c620 | Size: 256 bytes
// Khung tháo gỡ #0780 | Địa chỉ PC: 0x0fd450 | Địa chỉ FDE: 0x07c620 | Kích thước: 256 bytes
//   0x0fd450: 1402252F  b        #0x18690c
//   0x0fd454: D10583FF  sub      sp, sp, #0x160
//   0x0fd458: F9009BFC  str      x28, [sp, #0x130]
//   0x0fd45c: A91453F5  stp      x21, x20, [sp, #0x140]
static inline uint64_t fde_func_0780_0x0fd450(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fd450ULL ^ (static_cast<uint64_t>(0x1402252fULL) << 13);
    acc = (acc + a1 + 0xd10583ffULL) ^ 0x07c620ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0781 | PC: 0x0fd934 | FDE: 0x07c6a0 | Size: 256 bytes
// Khung tháo gỡ #0781 | Địa chỉ PC: 0x0fd934 | Địa chỉ FDE: 0x07c6a0 | Kích thước: 256 bytes
//   0x0fd934: A9BC63FC  stp      x28, x24, [sp, #-0x40]!
//   0x0fd938: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0fd93c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0fd940: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0781_0x0fd934(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fd934ULL ^ (static_cast<uint64_t>(0xa9bc63fcULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x07c6a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0782 | PC: 0x0fe808 | FDE: 0x07c720 | Size: 256 bytes
// Khung tháo gỡ #0782 | Địa chỉ PC: 0x0fe808 | Địa chỉ FDE: 0x07c720 | Kích thước: 256 bytes
//   0x0fe808: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0fe80c: 52911268  mov      w8, #0x8893
//   0x0fe810: AA0103E9  mov      x9, x1
//   0x0fe814: 6B08005F  cmp      w2, w8
static inline uint64_t fde_func_0782_0x0fe808(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fe808ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x52911268ULL) ^ 0x07c720ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0783 | PC: 0x0fe914 | FDE: 0x07c780 | Size: 256 bytes
// Khung tháo gỡ #0783 | Địa chỉ PC: 0x0fe914 | Địa chỉ FDE: 0x07c780 | Kích thước: 256 bytes
//   0x0fe914: D101C3FF  sub      sp, sp, #0x70
//   0x0fe918: AA1E03E7  mov      x7, x30
//   0x0fe91c: 9401E051  bl       #0x176a60
//   0x0fe920: AA0703FE  mov      x30, x7
static inline uint64_t fde_func_0783_0x0fe914(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fe914ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xaa1e03e7ULL) ^ 0x07c780ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0784 | PC: 0x0fee0c | FDE: 0x07c818 | Size: 112 bytes
// Khung tháo gỡ #0784 | Địa chỉ PC: 0x0fee0c | Địa chỉ FDE: 0x07c818 | Kích thước: 112 bytes
//   0x0fee0c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0fee10: AA0003F3  mov      x19, x0
//   0x0fee14: 9401DF21  bl       #0x176a98
//   0x0fee18: D0000468  adrp     x8, #0x18c000
static inline uint64_t fde_func_0784_0x0fee0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fee0cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x07c818ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0785 | PC: 0x0fee7c | FDE: 0x07c878 | Size: 112 bytes
// Khung tháo gỡ #0785 | Địa chỉ PC: 0x0fee7c | Địa chỉ FDE: 0x07c878 | Kích thước: 112 bytes
//   0x0fee7c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0fee80: F9400001  ldr      x1, [x0]
//   0x0fee84: 5281AAC0  mov      w0, #0xd56
//   0x0fee88: 940222CE  bl       #0x1879c0
static inline uint64_t fde_func_0785_0x0fee7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fee7cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400001ULL) ^ 0x07c878ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0786 | PC: 0x0feeec | FDE: 0x07c8d8 | Size: 152 bytes
// Khung tháo gỡ #0786 | Địa chỉ PC: 0x0feeec | Địa chỉ FDE: 0x07c8d8 | Kích thước: 152 bytes
//   0x0feeec: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0feef0: F9400001  ldr      x1, [x0]
//   0x0feef4: 5281AA40  mov      w0, #0xd52
//   0x0feef8: 940222B2  bl       #0x1879c0
static inline uint64_t fde_func_0786_0x0feeec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0feeecULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400001ULL) ^ 0x07c8d8ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0787 | PC: 0x0fef84 | FDE: 0x07c938 | Size: 232 bytes
// Khung tháo gỡ #0787 | Địa chỉ PC: 0x0fef84 | Địa chỉ FDE: 0x07c938 | Kích thước: 232 bytes
//   0x0fef84: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0fef88: F9400001  ldr      x1, [x0]
//   0x0fef8c: 5281AAE0  mov      w0, #0xd57
//   0x0fef90: 9402228C  bl       #0x1879c0
static inline uint64_t fde_func_0787_0x0fef84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fef84ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400001ULL) ^ 0x07c938ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0788 | PC: 0x0ff06c | FDE: 0x07c9a0 | Size: 256 bytes
// Khung tháo gỡ #0788 | Địa chỉ PC: 0x0ff06c | Địa chỉ FDE: 0x07c9a0 | Kích thước: 256 bytes
//   0x0ff06c: D10103FF  sub      sp, sp, #0x40
//   0x0ff070: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0ff074: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0ff078: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0788_0x0ff06c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ff06cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x07c9a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0789 | PC: 0x0ff25c | FDE: 0x07ca18 | Size: 256 bytes
// Khung tháo gỡ #0789 | Địa chỉ PC: 0x0ff25c | Địa chỉ FDE: 0x07ca18 | Kích thước: 256 bytes
//   0x0ff25c: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0ff260: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0ff264: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0ff268: F941C408  ldr      x8, [x0, #0x388]
static inline uint64_t fde_func_0789_0x0ff25c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ff25cULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x07ca18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0790 | PC: 0x0ff4c8 | FDE: 0x07ca90 | Size: 256 bytes
// Khung tháo gỡ #0790 | Địa chỉ PC: 0x0ff4c8 | Địa chỉ FDE: 0x07ca90 | Kích thước: 256 bytes
//   0x0ff4c8: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0ff4cc: 940210F1  bl       #0x183890
//   0x0ff4d0: B4000068  cbz      x8, #0xff4dc
//   0x0ff4d4: B9400101  ldr      w1, [x8]
static inline uint64_t fde_func_0790_0x0ff4c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ff4c8ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x940210f1ULL) ^ 0x07ca90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0791 | PC: 0x0ff7ac | FDE: 0x07cb00 | Size: 256 bytes
// Khung tháo gỡ #0791 | Địa chỉ PC: 0x0ff7ac | Địa chỉ FDE: 0x07cb00 | Kích thước: 256 bytes
//   0x0ff7ac: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0ff7b0: 94021038  bl       #0x183890
//   0x0ff7b4: B4000068  cbz      x8, #0xff7c0
//   0x0ff7b8: B9400101  ldr      w1, [x8]
static inline uint64_t fde_func_0791_0x0ff7ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ff7acULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x94021038ULL) ^ 0x07cb00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0792 | PC: 0x0ff8cc | FDE: 0x07cb70 | Size: 256 bytes
// Khung tháo gỡ #0792 | Địa chỉ PC: 0x0ff8cc | Địa chỉ FDE: 0x07cb70 | Kích thước: 256 bytes
//   0x0ff8cc: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0ff8d0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0ff8d4: 129000A8  mov      w8, #-0x8006
//   0x0ff8d8: 0B080048  add      w8, w2, w8
static inline uint64_t fde_func_0792_0x0ff8cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ff8ccULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x07cb70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0793 | PC: 0x0ffa20 | FDE: 0x07cbe0 | Size: 256 bytes
// Khung tháo gỡ #0793 | Địa chỉ PC: 0x0ffa20 | Địa chỉ FDE: 0x07cbe0 | Kích thước: 256 bytes
//   0x0ffa20: D10103FF  sub      sp, sp, #0x40
//   0x0ffa24: F9000BF6  str      x22, [sp, #0x10]
//   0x0ffa28: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0ffa2c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0793_0x0ffa20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ffa20ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x07cbe0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0794 | PC: 0x0ffcd8 | FDE: 0x07cc58 | Size: 256 bytes
// Khung tháo gỡ #0794 | Địa chỉ PC: 0x0ffcd8 | Địa chỉ FDE: 0x07cc58 | Kích thước: 256 bytes
//   0x0ffcd8: AA1E03E4  mov      x4, x30
//   0x0ffcdc: 9401F4CB  bl       #0x17d008
//   0x0ffce0: AA0403FE  mov      x30, x4
//   0x0ffce4: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0794_0x0ffcd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ffcd8ULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x9401f4cbULL) ^ 0x07cc58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0795 | PC: 0x0fff38 | FDE: 0x07cce0 | Size: 256 bytes
// Khung tháo gỡ #0795 | Địa chỉ PC: 0x0fff38 | Địa chỉ FDE: 0x07cce0 | Kích thước: 256 bytes
//   0x0fff38: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x0fff3c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0fff40: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0fff44: B9401C48  ldr      w8, [x2, #0x1c]
static inline uint64_t fde_func_0795_0x0fff38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0fff38ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x07cce0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0796 | PC: 0x1001a4 | FDE: 0x07cd68 | Size: 256 bytes
// Khung tháo gỡ #0796 | Địa chỉ PC: 0x1001a4 | Địa chỉ FDE: 0x07cd68 | Kích thước: 256 bytes
//   0x1001a4: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x1001a8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1001ac: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1001b0: AA0003F6  mov      x22, x0
static inline uint64_t fde_func_0796_0x1001a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1001a4ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x07cd68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0797 | PC: 0x1003b8 | FDE: 0x07cdf0 | Size: 256 bytes
// Khung tháo gỡ #0797 | Địa chỉ PC: 0x1003b8 | Địa chỉ FDE: 0x07cdf0 | Kích thước: 256 bytes
//   0x1003b8: D10143FF  sub      sp, sp, #0x50
//   0x1003bc: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x1003c0: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x1003c4: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0797_0x1003b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1003b8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x07cdf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0798 | PC: 0x1006cc | FDE: 0x07ce70 | Size: 256 bytes
// Khung tháo gỡ #0798 | Địa chỉ PC: 0x1006cc | Địa chỉ FDE: 0x07ce70 | Kích thước: 256 bytes
//   0x1006cc: 36000041  tbz      w1, #0, #0x1006d4
//   0x1006d0: 14021D44  b        #0x187be0
//   0x1006d4: 17FEF438  b        #0xbd7b4
//   0x1006d8: D10183FF  sub      sp, sp, #0x60
static inline uint64_t fde_func_0798_0x1006cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1006ccULL ^ (static_cast<uint64_t>(0x36000041ULL) << 13);
    acc = (acc + a1 + 0x14021d44ULL) ^ 0x07ce70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0799 | PC: 0x100800 | FDE: 0x07cee8 | Size: 256 bytes
// Khung tháo gỡ #0799 | Địa chỉ PC: 0x100800 | Địa chỉ FDE: 0x07cee8 | Kích thước: 256 bytes
//   0x100800: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x100804: BD400000  ldr      s0, [x0]
//   0x100808: 94021F6A  bl       #0x1885b0
//   0x10080c: 52800080  mov      w0, #4
static inline uint64_t fde_func_0799_0x100800(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x100800ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xbd400000ULL) ^ 0x07cee8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Shard 2 Dispatcher / Bộ điều phối phân mảnh 2
uint64_t execute_fde_shard_2(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 400: return fde_func_0400_0x0d95b0(a0, a1);
        case 401: return fde_func_0401_0x0d9910(a0, a1);
        case 402: return fde_func_0402_0x0d9a44(a0, a1);
        case 403: return fde_func_0403_0x0d9b34(a0, a1);
        case 404: return fde_func_0404_0x0d9c30(a0, a1);
        case 405: return fde_func_0405_0x0d9d28(a0, a1);
        case 406: return fde_func_0406_0x0d9dfc(a0, a1);
        case 407: return fde_func_0407_0x0d9e18(a0, a1);
        case 408: return fde_func_0408_0x0d9f48(a0, a1);
        case 409: return fde_func_0409_0x0d9f98(a0, a1);
        case 410: return fde_func_0410_0x0da020(a0, a1);
        case 411: return fde_func_0411_0x0da09c(a0, a1);
        case 412: return fde_func_0412_0x0da0f4(a0, a1);
        case 413: return fde_func_0413_0x0da16c(a0, a1);
        case 414: return fde_func_0414_0x0da3f4(a0, a1);
        case 415: return fde_func_0415_0x0da424(a0, a1);
        case 416: return fde_func_0416_0x0da668(a0, a1);
        case 417: return fde_func_0417_0x0da6b0(a0, a1);
        case 418: return fde_func_0418_0x0da728(a0, a1);
        case 419: return fde_func_0419_0x0da7c4(a0, a1);
        case 420: return fde_func_0420_0x0da7d0(a0, a1);
        case 421: return fde_func_0421_0x0da890(a0, a1);
        case 422: return fde_func_0422_0x0da8b0(a0, a1);
        case 423: return fde_func_0423_0x0dab9c(a0, a1);
        case 424: return fde_func_0424_0x0dabac(a0, a1);
        case 425: return fde_func_0425_0x0dac60(a0, a1);
        case 426: return fde_func_0426_0x0dad58(a0, a1);
        case 427: return fde_func_0427_0x0dae74(a0, a1);
        case 428: return fde_func_0428_0x0dafec(a0, a1);
        case 429: return fde_func_0429_0x0db0a4(a0, a1);
        case 430: return fde_func_0430_0x0db198(a0, a1);
        case 431: return fde_func_0431_0x0db5d0(a0, a1);
        case 432: return fde_func_0432_0x0db680(a0, a1);
        case 433: return fde_func_0433_0x0db768(a0, a1);
        case 434: return fde_func_0434_0x0dbb50(a0, a1);
        case 435: return fde_func_0435_0x0dbc00(a0, a1);
        case 436: return fde_func_0436_0x0dbf1c(a0, a1);
        case 437: return fde_func_0437_0x0dc0a0(a0, a1);
        case 438: return fde_func_0438_0x0dc0c8(a0, a1);
        case 439: return fde_func_0439_0x0dc698(a0, a1);
        case 440: return fde_func_0440_0x0dc6e8(a0, a1);
        case 441: return fde_func_0441_0x0dc788(a0, a1);
        case 442: return fde_func_0442_0x0dc850(a0, a1);
        case 443: return fde_func_0443_0x0dc8bc(a0, a1);
        case 444: return fde_func_0444_0x0dc934(a0, a1);
        case 445: return fde_func_0445_0x0dc984(a0, a1);
        case 446: return fde_func_0446_0x0dc9a8(a0, a1);
        case 447: return fde_func_0447_0x0dc9b8(a0, a1);
        case 448: return fde_func_0448_0x0dc9c8(a0, a1);
        case 449: return fde_func_0449_0x0dc9d8(a0, a1);
        case 450: return fde_func_0450_0x0dc9e0(a0, a1);
        case 451: return fde_func_0451_0x0dca08(a0, a1);
        case 452: return fde_func_0452_0x0dca14(a0, a1);
        case 453: return fde_func_0453_0x0dca2c(a0, a1);
        case 454: return fde_func_0454_0x0dca68(a0, a1);
        case 455: return fde_func_0455_0x0dcb90(a0, a1);
        case 456: return fde_func_0456_0x0dcc08(a0, a1);
        case 457: return fde_func_0457_0x0dcc54(a0, a1);
        case 458: return fde_func_0458_0x0dccd4(a0, a1);
        case 459: return fde_func_0459_0x0dcd70(a0, a1);
        case 460: return fde_func_0460_0x0dcdc8(a0, a1);
        case 461: return fde_func_0461_0x0dcde4(a0, a1);
        case 462: return fde_func_0462_0x0dcdf0(a0, a1);
        case 463: return fde_func_0463_0x0dcdfc(a0, a1);
        case 464: return fde_func_0464_0x0dce48(a0, a1);
        case 465: return fde_func_0465_0x0dce7c(a0, a1);
        case 466: return fde_func_0466_0x0dce90(a0, a1);
        case 467: return fde_func_0467_0x0dcee0(a0, a1);
        case 468: return fde_func_0468_0x0dcf10(a0, a1);
        case 469: return fde_func_0469_0x0dcf4c(a0, a1);
        case 470: return fde_func_0470_0x0dcf54(a0, a1);
        case 471: return fde_func_0471_0x0dcfa8(a0, a1);
        case 472: return fde_func_0472_0x0dd05c(a0, a1);
        case 473: return fde_func_0473_0x0dd08c(a0, a1);
        case 474: return fde_func_0474_0x0dd0bc(a0, a1);
        case 475: return fde_func_0475_0x0dd12c(a0, a1);
        case 476: return fde_func_0476_0x0dd158(a0, a1);
        case 477: return fde_func_0477_0x0dd170(a0, a1);
        case 478: return fde_func_0478_0x0dd25c(a0, a1);
        case 479: return fde_func_0479_0x0dd2cc(a0, a1);
        case 480: return fde_func_0480_0x0dd394(a0, a1);
        case 481: return fde_func_0481_0x0dd3f8(a0, a1);
        case 482: return fde_func_0482_0x0dd588(a0, a1);
        case 483: return fde_func_0483_0x0dd684(a0, a1);
        case 484: return fde_func_0484_0x0dd89c(a0, a1);
        case 485: return fde_func_0485_0x0dd8a4(a0, a1);
        case 486: return fde_func_0486_0x0dd8ac(a0, a1);
        case 487: return fde_func_0487_0x0dd9b4(a0, a1);
        case 488: return fde_func_0488_0x0ddb48(a0, a1);
        case 489: return fde_func_0489_0x0ddbb0(a0, a1);
        case 490: return fde_func_0490_0x0ddcc8(a0, a1);
        case 491: return fde_func_0491_0x0ddd38(a0, a1);
        case 492: return fde_func_0492_0x0de010(a0, a1);
        case 493: return fde_func_0493_0x0de210(a0, a1);
        case 494: return fde_func_0494_0x0de314(a0, a1);
        case 495: return fde_func_0495_0x0de3e8(a0, a1);
        case 496: return fde_func_0496_0x0de40c(a0, a1);
        case 497: return fde_func_0497_0x0de424(a0, a1);
        case 498: return fde_func_0498_0x0de6a8(a0, a1);
        case 499: return fde_func_0499_0x0de740(a0, a1);
        case 500: return fde_func_0500_0x0deb84(a0, a1);
        case 501: return fde_func_0501_0x0dec48(a0, a1);
        case 502: return fde_func_0502_0x0decc0(a0, a1);
        case 503: return fde_func_0503_0x0decd8(a0, a1);
        case 504: return fde_func_0504_0x0ded58(a0, a1);
        case 505: return fde_func_0505_0x0dee40(a0, a1);
        case 506: return fde_func_0506_0x0def34(a0, a1);
        case 507: return fde_func_0507_0x0df110(a0, a1);
        case 508: return fde_func_0508_0x0df310(a0, a1);
        case 509: return fde_func_0509_0x0df36c(a0, a1);
        case 510: return fde_func_0510_0x0df46c(a0, a1);
        case 511: return fde_func_0511_0x0df4ec(a0, a1);
        case 512: return fde_func_0512_0x0e067c(a0, a1);
        case 513: return fde_func_0513_0x0e08ec(a0, a1);
        case 514: return fde_func_0514_0x0e095c(a0, a1);
        case 515: return fde_func_0515_0x0e09bc(a0, a1);
        case 516: return fde_func_0516_0x0e0a88(a0, a1);
        case 517: return fde_func_0517_0x0e0d64(a0, a1);
        case 518: return fde_func_0518_0x0e0f48(a0, a1);
        case 519: return fde_func_0519_0x0e106c(a0, a1);
        case 520: return fde_func_0520_0x0e1234(a0, a1);
        case 521: return fde_func_0521_0x0e1360(a0, a1);
        case 522: return fde_func_0522_0x0e16ec(a0, a1);
        case 523: return fde_func_0523_0x0e1918(a0, a1);
        case 524: return fde_func_0524_0x0e19e4(a0, a1);
        case 525: return fde_func_0525_0x0e20d8(a0, a1);
        case 526: return fde_func_0526_0x0e21b8(a0, a1);
        case 527: return fde_func_0527_0x0e2240(a0, a1);
        case 528: return fde_func_0528_0x0e22a4(a0, a1);
        case 529: return fde_func_0529_0x0e232c(a0, a1);
        case 530: return fde_func_0530_0x0e2d38(a0, a1);
        case 531: return fde_func_0531_0x0e2e14(a0, a1);
        case 532: return fde_func_0532_0x0e2e94(a0, a1);
        case 533: return fde_func_0533_0x0e30ac(a0, a1);
        case 534: return fde_func_0534_0x0e3148(a0, a1);
        case 535: return fde_func_0535_0x0e3238(a0, a1);
        case 536: return fde_func_0536_0x0e3438(a0, a1);
        case 537: return fde_func_0537_0x0e34dc(a0, a1);
        case 538: return fde_func_0538_0x0e35f0(a0, a1);
        case 539: return fde_func_0539_0x0e36c8(a0, a1);
        case 540: return fde_func_0540_0x0e3740(a0, a1);
        case 541: return fde_func_0541_0x0e3808(a0, a1);
        case 542: return fde_func_0542_0x0e38d8(a0, a1);
        case 543: return fde_func_0543_0x0e39b4(a0, a1);
        case 544: return fde_func_0544_0x0e3a28(a0, a1);
        case 545: return fde_func_0545_0x0e3b20(a0, a1);
        case 546: return fde_func_0546_0x0e3be0(a0, a1);
        case 547: return fde_func_0547_0x0e3d08(a0, a1);
        case 548: return fde_func_0548_0x0e3d94(a0, a1);
        case 549: return fde_func_0549_0x0e3df4(a0, a1);
        case 550: return fde_func_0550_0x0e3ebc(a0, a1);
        case 551: return fde_func_0551_0x0e3ff4(a0, a1);
        case 552: return fde_func_0552_0x0e4300(a0, a1);
        case 553: return fde_func_0553_0x0e45ac(a0, a1);
        case 554: return fde_func_0554_0x0e4670(a0, a1);
        case 555: return fde_func_0555_0x0e476c(a0, a1);
        case 556: return fde_func_0556_0x0e4808(a0, a1);
        case 557: return fde_func_0557_0x0e489c(a0, a1);
        case 558: return fde_func_0558_0x0e4ac4(a0, a1);
        case 559: return fde_func_0559_0x0e4b84(a0, a1);
        case 560: return fde_func_0560_0x0e4cc4(a0, a1);
        case 561: return fde_func_0561_0x0e4e2c(a0, a1);
        case 562: return fde_func_0562_0x0e50ac(a0, a1);
        case 563: return fde_func_0563_0x0e51f4(a0, a1);
        case 564: return fde_func_0564_0x0e5320(a0, a1);
        case 565: return fde_func_0565_0x0e5478(a0, a1);
        case 566: return fde_func_0566_0x0e54a8(a0, a1);
        case 567: return fde_func_0567_0x0e5544(a0, a1);
        case 568: return fde_func_0568_0x0e5558(a0, a1);
        case 569: return fde_func_0569_0x0e55d8(a0, a1);
        case 570: return fde_func_0570_0x0e595c(a0, a1);
        case 571: return fde_func_0571_0x0e5a2c(a0, a1);
        case 572: return fde_func_0572_0x0e5a40(a0, a1);
        case 573: return fde_func_0573_0x0e5e18(a0, a1);
        case 574: return fde_func_0574_0x0e5e88(a0, a1);
        case 575: return fde_func_0575_0x0e5f08(a0, a1);
        case 576: return fde_func_0576_0x0e5f6c(a0, a1);
        case 577: return fde_func_0577_0x0e6140(a0, a1);
        case 578: return fde_func_0578_0x0e62c0(a0, a1);
        case 579: return fde_func_0579_0x0e62f0(a0, a1);
        case 580: return fde_func_0580_0x0e636c(a0, a1);
        case 581: return fde_func_0581_0x0e63e0(a0, a1);
        case 582: return fde_func_0582_0x0e63e8(a0, a1);
        case 583: return fde_func_0583_0x0e6454(a0, a1);
        case 584: return fde_func_0584_0x0e64c0(a0, a1);
        case 585: return fde_func_0585_0x0e65b4(a0, a1);
        case 586: return fde_func_0586_0x0e661c(a0, a1);
        case 587: return fde_func_0587_0x0e6714(a0, a1);
        case 588: return fde_func_0588_0x0e6734(a0, a1);
        case 589: return fde_func_0589_0x0e6758(a0, a1);
        case 590: return fde_func_0590_0x0e6794(a0, a1);
        case 591: return fde_func_0591_0x0e69c8(a0, a1);
        case 592: return fde_func_0592_0x0e6a20(a0, a1);
        case 593: return fde_func_0593_0x0e6aa8(a0, a1);
        case 594: return fde_func_0594_0x0e6ae0(a0, a1);
        case 595: return fde_func_0595_0x0e6b84(a0, a1);
        case 596: return fde_func_0596_0x0e6e3c(a0, a1);
        case 597: return fde_func_0597_0x0e6f6c(a0, a1);
        case 598: return fde_func_0598_0x0e70e0(a0, a1);
        case 599: return fde_func_0599_0x0e721c(a0, a1);
        case 600: return fde_func_0600_0x0e72c8(a0, a1);
        case 601: return fde_func_0601_0x0e7320(a0, a1);
        case 602: return fde_func_0602_0x0e7e7c(a0, a1);
        case 603: return fde_func_0603_0x0e7e9c(a0, a1);
        case 604: return fde_func_0604_0x0e7ebc(a0, a1);
        case 605: return fde_func_0605_0x0e7ef4(a0, a1);
        case 606: return fde_func_0606_0x0e808c(a0, a1);
        case 607: return fde_func_0607_0x0e80b0(a0, a1);
        case 608: return fde_func_0608_0x0e82e8(a0, a1);
        case 609: return fde_func_0609_0x0e85d0(a0, a1);
        case 610: return fde_func_0610_0x0e86bc(a0, a1);
        case 611: return fde_func_0611_0x0e8760(a0, a1);
        case 612: return fde_func_0612_0x0e8778(a0, a1);
        case 613: return fde_func_0613_0x0e8d90(a0, a1);
        case 614: return fde_func_0614_0x0e92a4(a0, a1);
        case 615: return fde_func_0615_0x0e951c(a0, a1);
        case 616: return fde_func_0616_0x0e9590(a0, a1);
        case 617: return fde_func_0617_0x0e95d4(a0, a1);
        case 618: return fde_func_0618_0x0e9618(a0, a1);
        case 619: return fde_func_0619_0x0e9648(a0, a1);
        case 620: return fde_func_0620_0x0e9c24(a0, a1);
        case 621: return fde_func_0621_0x0e9c68(a0, a1);
        case 622: return fde_func_0622_0x0e9cac(a0, a1);
        case 623: return fde_func_0623_0x0e9d04(a0, a1);
        case 624: return fde_func_0624_0x0e9d4c(a0, a1);
        case 625: return fde_func_0625_0x0e9d90(a0, a1);
        case 626: return fde_func_0626_0x0e9df8(a0, a1);
        case 627: return fde_func_0627_0x0e9e44(a0, a1);
        case 628: return fde_func_0628_0x0e9e80(a0, a1);
        case 629: return fde_func_0629_0x0e9ed8(a0, a1);
        case 630: return fde_func_0630_0x0e9f20(a0, a1);
        case 631: return fde_func_0631_0x0e9f60(a0, a1);
        case 632: return fde_func_0632_0x0e9fb8(a0, a1);
        case 633: return fde_func_0633_0x0e9ff8(a0, a1);
        case 634: return fde_func_0634_0x0ea0e0(a0, a1);
        case 635: return fde_func_0635_0x0ea138(a0, a1);
        case 636: return fde_func_0636_0x0ea17c(a0, a1);
        case 637: return fde_func_0637_0x0ea1d4(a0, a1);
        case 638: return fde_func_0638_0x0ea2ac(a0, a1);
        case 639: return fde_func_0639_0x0ea374(a0, a1);
        case 640: return fde_func_0640_0x0ea444(a0, a1);
        case 641: return fde_func_0641_0x0ea528(a0, a1);
        case 642: return fde_func_0642_0x0ea5b0(a0, a1);
        case 643: return fde_func_0643_0x0ea988(a0, a1);
        case 644: return fde_func_0644_0x0eac94(a0, a1);
        case 645: return fde_func_0645_0x0eae80(a0, a1);
        case 646: return fde_func_0646_0x0eb1fc(a0, a1);
        case 647: return fde_func_0647_0x0eb4e4(a0, a1);
        case 648: return fde_func_0648_0x0eb714(a0, a1);
        case 649: return fde_func_0649_0x0eb7fc(a0, a1);
        case 650: return fde_func_0650_0x0eb89c(a0, a1);
        case 651: return fde_func_0651_0x0ebe30(a0, a1);
        case 652: return fde_func_0652_0x0ebecc(a0, a1);
        case 653: return fde_func_0653_0x0ebee8(a0, a1);
        case 654: return fde_func_0654_0x0ec018(a0, a1);
        case 655: return fde_func_0655_0x0ec0d8(a0, a1);
        case 656: return fde_func_0656_0x0ec620(a0, a1);
        case 657: return fde_func_0657_0x0ec62c(a0, a1);
        case 658: return fde_func_0658_0x0ec6f4(a0, a1);
        case 659: return fde_func_0659_0x0ec860(a0, a1);
        case 660: return fde_func_0660_0x0ec98c(a0, a1);
        case 661: return fde_func_0661_0x0eca60(a0, a1);
        case 662: return fde_func_0662_0x0ecd8c(a0, a1);
        case 663: return fde_func_0663_0x0ed08c(a0, a1);
        case 664: return fde_func_0664_0x0ed58c(a0, a1);
        case 665: return fde_func_0665_0x0ed650(a0, a1);
        case 666: return fde_func_0666_0x0ed670(a0, a1);
        case 667: return fde_func_0667_0x0ed6ac(a0, a1);
        case 668: return fde_func_0668_0x0ed6c4(a0, a1);
        case 669: return fde_func_0669_0x0ed750(a0, a1);
        case 670: return fde_func_0670_0x0ed770(a0, a1);
        case 671: return fde_func_0671_0x0ed7a8(a0, a1);
        case 672: return fde_func_0672_0x0edbac(a0, a1);
        case 673: return fde_func_0673_0x0edca8(a0, a1);
        case 674: return fde_func_0674_0x0ee954(a0, a1);
        case 675: return fde_func_0675_0x0eec10(a0, a1);
        case 676: return fde_func_0676_0x0eee10(a0, a1);
        case 677: return fde_func_0677_0x0ef81c(a0, a1);
        case 678: return fde_func_0678_0x0ef954(a0, a1);
        case 679: return fde_func_0679_0x0efa04(a0, a1);
        case 680: return fde_func_0680_0x0efa68(a0, a1);
        case 681: return fde_func_0681_0x0efdfc(a0, a1);
        case 682: return fde_func_0682_0x0f00a0(a0, a1);
        case 683: return fde_func_0683_0x0f0308(a0, a1);
        case 684: return fde_func_0684_0x0f0504(a0, a1);
        case 685: return fde_func_0685_0x0f0920(a0, a1);
        case 686: return fde_func_0686_0x0f0b00(a0, a1);
        case 687: return fde_func_0687_0x0f0b68(a0, a1);
        case 688: return fde_func_0688_0x0f0c64(a0, a1);
        case 689: return fde_func_0689_0x0f0d28(a0, a1);
        case 690: return fde_func_0690_0x0f0ebc(a0, a1);
        case 691: return fde_func_0691_0x0f10cc(a0, a1);
        case 692: return fde_func_0692_0x0f13e4(a0, a1);
        case 693: return fde_func_0693_0x0f1614(a0, a1);
        case 694: return fde_func_0694_0x0f1830(a0, a1);
        case 695: return fde_func_0695_0x0f1b1c(a0, a1);
        case 696: return fde_func_0696_0x0f1e14(a0, a1);
        case 697: return fde_func_0697_0x0f1f80(a0, a1);
        case 698: return fde_func_0698_0x0f2014(a0, a1);
        case 699: return fde_func_0699_0x0f2154(a0, a1);
        case 700: return fde_func_0700_0x0f24b0(a0, a1);
        case 701: return fde_func_0701_0x0f25f8(a0, a1);
        case 702: return fde_func_0702_0x0f27d4(a0, a1);
        case 703: return fde_func_0703_0x0f2ae4(a0, a1);
        case 704: return fde_func_0704_0x0f2dfc(a0, a1);
        case 705: return fde_func_0705_0x0f3290(a0, a1);
        case 706: return fde_func_0706_0x0f361c(a0, a1);
        case 707: return fde_func_0707_0x0f3978(a0, a1);
        case 708: return fde_func_0708_0x0f3d0c(a0, a1);
        case 709: return fde_func_0709_0x0f3e6c(a0, a1);
        case 710: return fde_func_0710_0x0f40ec(a0, a1);
        case 711: return fde_func_0711_0x0f4438(a0, a1);
        case 712: return fde_func_0712_0x0f44d0(a0, a1);
        case 713: return fde_func_0713_0x0f4588(a0, a1);
        case 714: return fde_func_0714_0x0f484c(a0, a1);
        case 715: return fde_func_0715_0x0f4a40(a0, a1);
        case 716: return fde_func_0716_0x0f4bfc(a0, a1);
        case 717: return fde_func_0717_0x0f4f88(a0, a1);
        case 718: return fde_func_0718_0x0f5178(a0, a1);
        case 719: return fde_func_0719_0x0f559c(a0, a1);
        case 720: return fde_func_0720_0x0f5b9c(a0, a1);
        case 721: return fde_func_0721_0x0f5ee0(a0, a1);
        case 722: return fde_func_0722_0x0f65e8(a0, a1);
        case 723: return fde_func_0723_0x0f6928(a0, a1);
        case 724: return fde_func_0724_0x0f6c34(a0, a1);
        case 725: return fde_func_0725_0x0f70e8(a0, a1);
        case 726: return fde_func_0726_0x0f73b4(a0, a1);
        case 727: return fde_func_0727_0x0f7544(a0, a1);
        case 728: return fde_func_0728_0x0f76e8(a0, a1);
        case 729: return fde_func_0729_0x0f78d4(a0, a1);
        case 730: return fde_func_0730_0x0f7bc8(a0, a1);
        case 731: return fde_func_0731_0x0f7ce8(a0, a1);
        case 732: return fde_func_0732_0x0f7e04(a0, a1);
        case 733: return fde_func_0733_0x0f8088(a0, a1);
        case 734: return fde_func_0734_0x0f81a8(a0, a1);
        case 735: return fde_func_0735_0x0f834c(a0, a1);
        case 736: return fde_func_0736_0x0f8500(a0, a1);
        case 737: return fde_func_0737_0x0f8638(a0, a1);
        case 738: return fde_func_0738_0x0f8780(a0, a1);
        case 739: return fde_func_0739_0x0f88e0(a0, a1);
        case 740: return fde_func_0740_0x0f8a48(a0, a1);
        case 741: return fde_func_0741_0x0f8ba8(a0, a1);
        case 742: return fde_func_0742_0x0f8d10(a0, a1);
        case 743: return fde_func_0743_0x0f8f68(a0, a1);
        case 744: return fde_func_0744_0x0f9124(a0, a1);
        case 745: return fde_func_0745_0x0f92d8(a0, a1);
        case 746: return fde_func_0746_0x0f9638(a0, a1);
        case 747: return fde_func_0747_0x0f9730(a0, a1);
        case 748: return fde_func_0748_0x0f9838(a0, a1);
        case 749: return fde_func_0749_0x0f9940(a0, a1);
        case 750: return fde_func_0750_0x0f99c4(a0, a1);
        case 751: return fde_func_0751_0x0f9a58(a0, a1);
        case 752: return fde_func_0752_0x0f9b68(a0, a1);
        case 753: return fde_func_0753_0x0f9d34(a0, a1);
        case 754: return fde_func_0754_0x0f9dc8(a0, a1);
        case 755: return fde_func_0755_0x0f9f14(a0, a1);
        case 756: return fde_func_0756_0x0fa0b0(a0, a1);
        case 757: return fde_func_0757_0x0fa19c(a0, a1);
        case 758: return fde_func_0758_0x0fa270(a0, a1);
        case 759: return fde_func_0759_0x0fa2c8(a0, a1);
        case 760: return fde_func_0760_0x0fa498(a0, a1);
        case 761: return fde_func_0761_0x0fa5c8(a0, a1);
        case 762: return fde_func_0762_0x0fa780(a0, a1);
        case 763: return fde_func_0763_0x0fa8fc(a0, a1);
        case 764: return fde_func_0764_0x0fab60(a0, a1);
        case 765: return fde_func_0765_0x0fb144(a0, a1);
        case 766: return fde_func_0766_0x0fb1f0(a0, a1);
        case 767: return fde_func_0767_0x0fb384(a0, a1);
        case 768: return fde_func_0768_0x0fb440(a0, a1);
        case 769: return fde_func_0769_0x0fb4fc(a0, a1);
        case 770: return fde_func_0770_0x0fb5cc(a0, a1);
        case 771: return fde_func_0771_0x0fb7c0(a0, a1);
        case 772: return fde_func_0772_0x0fc5b4(a0, a1);
        case 773: return fde_func_0773_0x0fc728(a0, a1);
        case 774: return fde_func_0774_0x0fc7fc(a0, a1);
        case 775: return fde_func_0775_0x0fca10(a0, a1);
        case 776: return fde_func_0776_0x0fcb08(a0, a1);
        case 777: return fde_func_0777_0x0fccf0(a0, a1);
        case 778: return fde_func_0778_0x0fce30(a0, a1);
        case 779: return fde_func_0779_0x0fd010(a0, a1);
        case 780: return fde_func_0780_0x0fd450(a0, a1);
        case 781: return fde_func_0781_0x0fd934(a0, a1);
        case 782: return fde_func_0782_0x0fe808(a0, a1);
        case 783: return fde_func_0783_0x0fe914(a0, a1);
        case 784: return fde_func_0784_0x0fee0c(a0, a1);
        case 785: return fde_func_0785_0x0fee7c(a0, a1);
        case 786: return fde_func_0786_0x0feeec(a0, a1);
        case 787: return fde_func_0787_0x0fef84(a0, a1);
        case 788: return fde_func_0788_0x0ff06c(a0, a1);
        case 789: return fde_func_0789_0x0ff25c(a0, a1);
        case 790: return fde_func_0790_0x0ff4c8(a0, a1);
        case 791: return fde_func_0791_0x0ff7ac(a0, a1);
        case 792: return fde_func_0792_0x0ff8cc(a0, a1);
        case 793: return fde_func_0793_0x0ffa20(a0, a1);
        case 794: return fde_func_0794_0x0ffcd8(a0, a1);
        case 795: return fde_func_0795_0x0fff38(a0, a1);
        case 796: return fde_func_0796_0x1001a4(a0, a1);
        case 797: return fde_func_0797_0x1003b8(a0, a1);
        case 798: return fde_func_0798_0x1006cc(a0, a1);
        case 799: return fde_func_0799_0x100800(a0, a1);
        default: return 0ULL;
    }
}

} // namespace canvas
} // namespace lynx